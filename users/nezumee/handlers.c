#include "quantum.h"
#include "amberutil.h"
#include "config.h"

typedef enum {
	EO_WHEEL,
	EO_HORIZONTAL_WHEEL,
	EO_VOLUME,
	EO_LEFTRIGHT,
	EO_TAB,
	EO_PGUP_DOWN,
	EO_UP_DOWN,
	EO_UNDO_REDO,
	EO_DYNAMIC_MACRO
} encoderOperation_t;

encoderOperation_t encoderOperation;
bool encoderSlowdown = false;
static uint16_t encoderSlowdownTimer = 0;

const int ENCODER_SLOWDOWN_DELAY = 300;

void set_encoder_operation(encoderOperation_t operation) {
	if (!is_playing_dynamic_macro()) {
		encoderOperation = operation;
		encoderSlowdown = false;
		encoderSlowdownTimer = 0;
	}
}

// Check if all the modifiers are released and clear the modtap operation.
void check_encoder_operation(void) {
	if (get_mods() == 0 &&
		!IS_LAYER_ON(LAYER_FAR) && !IS_LAYER_ON(LAYER_CLOSE) && !IS_LAYER_ON(LAYER_INNER)) {
		set_encoder_operation(EO_WHEEL);
	}
}

void encoder_update_user(uint8_t index, bool clockwise) {
	check_encoder_operation();

	if (encoderOperation == EO_WHEEL) {
		// Use layer if there's no operation captured otherwise
		if (IS_LAYER_ON(LAYER_FAR)) {
			set_encoder_operation(EO_VOLUME);
		} else if (IS_LAYER_ON(LAYER_CLOSE)) {
			set_encoder_operation(EO_HORIZONTAL_WHEEL);
		}
	}		
		
	if (!encoderSlowdown ||
		encoderSlowdownTimer == 0 ||
		timer_elapsed(encoderSlowdownTimer) > ENCODER_SLOWDOWN_DELAY) {
		if (encoderSlowdown) {
			encoderSlowdownTimer = timer_read();
		}

		switch (encoderOperation) {
			case EO_WHEEL:
				if (clockwise) {
				  tap_code(KC_WH_D);
				} else {
				  tap_code(KC_WH_U);
				}
				break;

			case EO_VOLUME:
				if (clockwise) {
				  tap_code(KC_VOLD);
				} else {
				  tap_code(KC_VOLU);
				}
				break;
				
			case EO_HORIZONTAL_WHEEL:
				if (clockwise) {
				  tap_code(KC_WH_R);
				} else {
				  tap_code(KC_WH_L);
				}
				break;
				
			case EO_LEFTRIGHT:
				if (clockwise) {
				  tap_code(KC_RIGHT);
				} else {
				  tap_code(KC_LEFT);
				}
				break;
				
			case EO_UP_DOWN:
				if (clockwise) {
				  tap_code(KC_DOWN);
				} else {
				  tap_code(KC_UP);
				}
				break;
						
			case EO_PGUP_DOWN:
				if (clockwise) {
				  tap_code(KC_PGDN);
				} else {
				  tap_code(KC_PGUP);
				}
				break;
				
			case EO_TAB:
				if (clockwise) {
					tap_code(KC_TAB);
				} else {
					SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
				}
				break;

			case EO_UNDO_REDO:
				if (clockwise) {
					SEND_STRING(SS_LCTL("y"));
				} else {
					SEND_STRING(SS_LCTL("z"));
				}
				break;
				
			case EO_DYNAMIC_MACRO:
				if (clockwise) {
					keyrecord_t record;
					record.event.pressed = false;
					process_dynamic_macro(DYN_MACRO_PLAY1, &record);
				} else {
					SEND_STRING(SS_LCTL("z"));
				}
		}
	}
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_N):
        case LSFT_T(KC_T):
			return TAPPING_TERM-20;

        //case LCTL_T(KC_E):
        //case LCTL_T(KC_S):
        case LALT_T(KC_I):
        case LALT_T(KC_R):
        case LGUI_T(KC_O):
        case LGUI_T(KC_A):
			return TAPPING_TERM+50;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_N):
        case LSFT_T(KC_T):
        case LCTL_T(KC_E):
        case LCTL_T(KC_S):
        case LALT_T(KC_I):
        case LALT_T(KC_R):
        case LGUI_T(KC_O):
        case LGUI_T(KC_A):
            return true;
			
        default:
            return false;
    }
}

int counter = 0;
const int ledCount = 2;
void matrix_scan_user() {

	// Use PWM to mix colors in RGB LED
	counter++;
	switch (counter % ledCount) {
		case 0:
		#ifdef LED_QWERTY_PIN
			writePin(LED_QWERTY_PIN, !IS_LAYER_ON(LAYER_COLEMAK));
		#endif
		#ifdef LED_AMBER_CAPS_PIN
			writePin(LED_AMBER_CAPS_PIN, 0);
		#endif
			break;
			
		case 1:
		#ifdef LED_QWERTY_PIN
			writePin(LED_QWERTY_PIN, 0);
		#endif
		#ifdef LED_AMBER_CAPS_PIN
			writePin(LED_AMBER_CAPS_PIN, host_keyboard_led_state().caps_lock);
		#endif
			break;
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	check_encoder_operation();

	switch (keycode) {
		case LALT_T(KC_R):	// Set left/right mode when pressing Alt for browser back/forward. Modtap Alt keys for COLEMAK
		case LALT_T(KC_I):
		case LALT_T(KC_S):	// Modtap Alt keys for QWERTY
		case LALT_T(KC_L):
		case KC_LALT:
			if (record->event.pressed) {
				set_encoder_operation(EO_LEFTRIGHT);
				encoderSlowdown = true;
			}
			break;

		case LCTL(KC_Z):	// Ctrl+Z/Y
		case LCTL(KC_Y):
			if (record->event.pressed) {
				set_encoder_operation(EO_UNDO_REDO);
			}
			break;

		default:
			switch (keycode & QK_BASIC_MAX) {
				case KC_F20:
					if (record->event.pressed) {
						SEND_STRING(SS_LALT(SS_LSFT("0")));
						layer_on(LAYER_COLEMAK);
					}
					break;
					
				case KC_F21:
					if (record->event.pressed) {
						SEND_STRING(SS_LALT(SS_LSFT("1")));	// Russian
						layer_off(LAYER_COLEMAK);
					}
					break;
					
				case KC_F22:
					if (record->event.pressed) {
						SEND_STRING(SS_LALT(SS_LSFT("2")));	// Japanese
						layer_on(LAYER_COLEMAK);
					}
					break;	

				case KC_TAB:
					if (record->event.pressed) {
						set_encoder_operation(EO_TAB);
					}
					break;
					
				case KC_LEFT:		
				case KC_RIGHT:
					if (record->event.pressed) {
						set_encoder_operation(EO_LEFTRIGHT);
					}
					break;

				case KC_UP:
				case KC_DOWN:
					if (record->event.pressed) {
						set_encoder_operation(EO_UP_DOWN);
					}
					break;
					
				case KC_PGUP:
				case KC_PGDN:
					if (record->event.pressed) {
						set_encoder_operation(EO_PGUP_DOWN);
					}
					break;
					
				case DYN_MACRO_PLAY1:
					if (record->event.pressed) {
						set_encoder_operation(EO_DYNAMIC_MACRO);
					}
					break;
			}
    }
		
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
	check_encoder_operation();
	return state;
}

void keyboard_post_init_user(void) {
	layer_on(LAYER_COLEMAK);
#ifdef LED_QWERTY_PIN
	setPinOutput(LED_QWERTY_PIN);
#endif
#ifdef LED_AMBER_CAPS_PIN
	setPinOutput(LED_AMBER_CAPS_PIN);
#endif
}