#include "quantum.h"
#include "zebra2head.h"
#include "config.h"

// Use encoder for mouse scroll and volume depending on layer
void encoder_update_user(uint8_t index, bool clockwise) {
	if (IS_LAYER_ON(4)) {
		if (clockwise) {
		  tap_code(KC_VOLD);
		} else {
		  tap_code(KC_VOLU);
		}
	} else if (get_mods() & MODS_ALT_MASK) {
		if (clockwise) {
		  tap_code(KC_RIGHT);
		} else {
		  tap_code(KC_LEFT);
		}
	} else {
		if (clockwise) {
		  tap_code(KC_WH_D);
		} else {
		  tap_code(KC_WH_U);
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

bool led_update_user(led_t led_state) {
	bool colemak_enabled = IS_LAYER_ON(LAYER_COLEMAK);	
	writePin(LED_QWERTY_PIN, !colemak_enabled);
	
	writePin(LED_AMBER_CAPS_PIN, led_state.caps_lock);
	
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
    }
	
    return true;
};

void keyboard_post_init_user(void) {
	layer_on(LAYER_COLEMAK);
}