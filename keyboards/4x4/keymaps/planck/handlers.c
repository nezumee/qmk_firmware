#include "quantum.h"
#include "4x4.h"
#include "config.h"
#include "keys.h"

/*
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
  {{6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
  {{6, 6}, {5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
  {{6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
  {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

// Use encoder for mouse scroll and volume depending on layer
bool encoder_update_user(uint8_t index, bool clockwise) {
	if (0 == index)
	{
		if (clockwise) {
		  tap_code(KC_WH_D);
		} else {
		  tap_code(KC_WH_U);
		}
	} else {
		if (clockwise) {
		  tap_code(KC_WH_R);
		} else {
		  tap_code(KC_WH_L);
		}
	}
	
	return true;
}
*/

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

enum held_state {
	HS_NONE = 0,
	HS_HELD = 1,
	HS_GOTKEY = 2
};
	
enum held_state held_ctrl = HS_NONE;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case HOLD_LCTL:
		case HOLD_LSFT:
		case HOLD_LALT:
		case HOLD_LALTTAB:
		case HOLD_LGUI:
			if (record->event.pressed) {
				switch (keycode) {
					case HOLD_LCTL:
						register_code(KC_LCTL);
						break;
					case HOLD_LSFT:
						register_code(KC_LSFT);
						break;
					case HOLD_LALT:
						register_code(KC_LALT);
						break;
					case HOLD_LALTTAB:
						register_code(KC_LALT);
						SEND_STRING(SS_DOWN(X_TAB) SS_DELAY(50) SS_UP(X_TAB));
						break;
					case HOLD_LGUI:
						register_code(KC_LGUI);
						break;
				}
				if (layer_state == 0) {
					held_ctrl = HS_HELD;
				} else {
					// Treat layer release as end of operation for Alt+Tab
					held_ctrl = HS_GOTKEY;
				}
			}
			return false; // Skip all further processing of this key

		default:
			if (record->event.pressed) {
				if (held_ctrl) {
					held_ctrl = HS_GOTKEY;
				}
			}
    }
		
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if ((layer_state & ~STATIC_LAYERSET) == 0) {
		if (held_ctrl == HS_GOTKEY) {
			unregister_code(KC_LCTL);
			unregister_code(KC_LSFT);
			unregister_code(KC_LALT);
			unregister_code(KC_LGUI);
			held_ctrl = HS_NONE;
		}
	}	
}  