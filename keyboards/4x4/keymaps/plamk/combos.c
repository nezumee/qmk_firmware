#include "quantum.h" 
#include "amberutil.h"
#include "config.h"
#include "keys.h"

const uint16_t PROGMEM dotcom_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM comh_combo[] = {KC_COMM, KC_H, COMBO_END};
const uint16_t PROGMEM hcomdot_combo[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mcomdot_combo[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM starbracket_combo[] = {KC_ASTR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM num12_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM num23_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM bangat_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM athash_combo[] = {KC_AT, KC_HASH, COMBO_END};
const uint16_t PROGMEM mh_combo[] = {KC_M, KC_H, COMBO_END};	// original lower row for DHK
const uint16_t PROGMEM kh_combo[] = {KC_K, KC_H, COMBO_END};	// lower row variant for DH
const uint16_t PROGMEM ctrlcv_combo[] = {LCTL(KC_C), LCTL(KC_V), COMBO_END};
const uint16_t PROGMEM ctrlxc_combo[] = {LCTL(KC_X), LCTL(KC_C), COMBO_END};
const uint16_t PROGMEM tslash_combo[] = {KC_T, KC_SLSH, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, LT(6, KC_D), COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xcd_combo[] = {KC_X, KC_C, LT(6, KC_D), COMBO_END};
const uint16_t PROGMEM xcv_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};	// TODO: find some use?
const uint16_t PROGMEM num89_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM st_combo[] = {LCTL_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM rs_combo[] = {LALT_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM num45_combo[] = {LSFT_T(KC_4), LCTL_T(KC_5), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM df_combo[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM upright_combo[] = {KC_UP, KC_RGHT, COMBO_END};

enum combo_events {
  XCD_BRACKETS,
  XCV_BRACKETS,
  HCOMDOT_QUOTES,
  MCOMDOT_QUOTES,
};

combo_t key_combos[COMBO_COUNT] = {
	[XCD_BRACKETS] = COMBO_ACTION(xcd_combo),
	[XCV_BRACKETS] = COMBO_ACTION(xcv_combo),
	[HCOMDOT_QUOTES] = COMBO_ACTION(hcomdot_combo),
	[MCOMDOT_QUOTES] = COMBO_ACTION(mcomdot_combo),
	COMBO(dotcom_combo, KC_QUOT),
	COMBO(comh_combo, KC_DQUO),
	COMBO(starbracket_combo, KC_RPRN),
	COMBO(uy_combo, KC_SCLN),
	COMBO(wf_combo, KC_Q),
	COMBO(we_combo, KC_Q),
	COMBO(io_combo, KC_P),
	COMBO(num12_combo, KC_BSLS),
	COMBO(num23_combo, KC_GRV),
	COMBO(bangat_combo, KC_PIPE),
	COMBO(athash_combo, KC_TILD),
	COMBO(mh_combo, KC_MINS),
	COMBO(kh_combo, KC_MINS),
	COMBO(fp_combo, KC_MINS),
	COMBO(er_combo, KC_MINS),
	COMBO(ctrlcv_combo, LCTL(KC_Z)),
	COMBO(ctrlxc_combo, LCTL(KC_Y)),
	COMBO(tslash_combo, KC_QUES),
	COMBO(xc_combo, KC_LPRN),
	COMBO(cd_combo, KC_RPRN),
	COMBO(cv_combo, KC_RPRN),
	COMBO(num89_combo, KC_COLN),
	COMBO(st_combo, KC_TAB),
	COMBO(rs_combo, KC_BSPC),
	COMBO(num45_combo, KC_0),
	COMBO(df_combo, KC_TAB),
	COMBO(sd_combo, KC_BSPC),
	COMBO(upright_combo, HOLD_LALTTAB),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case XCD_BRACKETS:
    case XCV_BRACKETS:
      if (pressed) {
		SEND_STRING_DELAY("()" SS_DOWN(X_LEFT) SS_UP(X_LEFT), STRING_DELAY);
      }
      break;

    case HCOMDOT_QUOTES:
    case MCOMDOT_QUOTES:
      if (pressed) {
		SEND_STRING_DELAY("''", STRING_DELAY);
		uint8_t tmp_mods = get_mods();
		if (tmp_mods & MODS_SHIFT_MASK) {
			del_mods(MODS_SHIFT_MASK);
		}
		wait_ms(STRING_DELAY);
		SEND_STRING_DELAY(SS_DOWN(X_LEFT) SS_UP(X_LEFT), STRING_DELAY);
		set_mods(tmp_mods);
      }
      break;
  }
}