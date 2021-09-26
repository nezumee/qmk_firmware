#include "quantum.h" 

const uint16_t PROGMEM sy_combo[] = { KC_S, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM tp_combo[] = { KC_T, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM hl_combo[] = { KC_H, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM ed_combo[] = { KC_E, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM oq_combo[] = { KC_O, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM fj_combo[] = { KC_F, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM dk_combo[] = { KC_D, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM nm_combo[] = { KC_N, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM iq_combo[] = { KC_I, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM gm_combo[] = { KC_G, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM cx_combo[] = { KC_C, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM wb_combo[] = { KC_W, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM rv_combo[] = { KC_R, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM ac_combo[] = { KC_A, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM uz_combo[] = { KC_U, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM e_shift_combo[] = { KC_E, LT(2,KC_ENT), COMBO_END};
const uint16_t PROGMEM h_ctrl_combo[] = { KC_H, LT(2,KC_ENT), COMBO_END};
const uint16_t PROGMEM t_alt_combo[] = { KC_T, LT(2,KC_ENT), COMBO_END};
const uint16_t PROGMEM s_gui_combo[] = { KC_S, LT(2,KC_ENT), COMBO_END};
const uint16_t PROGMEM ten_combo[] = { KC_ESC, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM ni_dash_combo[] = { KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM wra_brackets_combo[] = { KC_W, KC_R, KC_A, COMBO_END};
const uint16_t PROGMEM wr_bracket_combo[] = { KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM ra_bracket_combo[] = { KC_R, KC_A, COMBO_END};
const uint16_t PROGMEM ctrl_alttab_combo[] = { OSM(MOD_LCTL), LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM dnsp_f_combo[] = { KC_D, KC_N, LT(1,KC_SPC), COMBO_END};
const uint16_t PROGMEM dn_f_combo[] = { KC_D, KC_N, COMBO_END};

enum combo_events {
  WRA_BRACKETS
};

combo_t key_combos[COMBO_COUNT] = {
	[WRA_BRACKETS] = COMBO_ACTION(wra_brackets_combo), 
	COMBO(sy_combo, KC_Y),
	COMBO(tp_combo, KC_P),
	COMBO(hl_combo, KC_L),
	COMBO(ed_combo, KC_DOT),
	COMBO(oq_combo, KC_Q),
	COMBO(fj_combo, KC_J),
	COMBO(dk_combo, KC_K),
	COMBO(nm_combo, KC_M),
	COMBO(iq_combo, KC_QUOT),
	COMBO(gm_combo, KC_MINS),
	COMBO(cx_combo, KC_X),
	COMBO(wb_combo, KC_B),
	COMBO(rv_combo, KC_V),
	COMBO(ac_combo, KC_COMM),
	COMBO(uz_combo, KC_Z),
	COMBO(ten_combo, KC_ENT),
	COMBO(e_shift_combo, OSM(MOD_LSFT)),
	COMBO(h_ctrl_combo, OSM(MOD_LCTL)),
	COMBO(t_alt_combo, OSM(MOD_LALT)),
	COMBO(s_gui_combo, OSM(MOD_LGUI)),
	COMBO(ni_dash_combo, KC_MINS),
	COMBO(wr_bracket_combo, KC_LPRN),
	COMBO(ra_bracket_combo, KC_RPRN),
	COMBO(ctrl_alttab_combo, LALT(KC_TAB)),
	COMBO(dn_f_combo, KC_F),
	COMBO(dnsp_f_combo, KC_J)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case WRA_BRACKETS:
      if (pressed) {
		SEND_STRING_DELAY("()" SS_DOWN(X_LEFT) SS_UP(X_LEFT), 20);
      }
      break;
  }
}