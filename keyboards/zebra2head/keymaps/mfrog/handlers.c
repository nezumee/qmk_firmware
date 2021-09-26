#include "quantum.h" 

void keyboard_post_init_user(void) {
	setPinOutput(LED_NAV_PIN);
}

layer_state_t layer_state_set_user(layer_state_t state) {
	writePin(LED_NAV_PIN, IS_LAYER_ON_STATE(state, 4) ? 1 : 0);

	return state;
}