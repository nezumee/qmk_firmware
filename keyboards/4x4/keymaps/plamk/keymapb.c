#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, DF(2), KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, OSM(MOD_LCTL), RGB_MOD, OSM(MOD_LALT), OSM(MOD_LGUI), LT(3,KC_SPC), LT(4,KC_ENT), LT(4,KC_BSPC), LT(3,KC_DEL), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_ortho_4x12(KC_ESC, KC_W, KC_F, KC_P, KC_B, OSM(MOD_LSFT), OSM(MOD_LGUI), KC_J, KC_L, KC_U, KC_Y, KC_BSPC, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, OSM(MOD_LCTL), KC_NO, KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_Z, KC_X, KC_C, KC_D, KC_V, OSM(MOD_LALT), KC_NO, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), LT(3,KC_SPC), LT(4,KC_ENT), KC_TRNS, KC_TRNS, LT(4,KC_BSPC), LT(3,KC_DEL), KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT_ortho_4x12(OSL(7), MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_B_5, MI_G_5, DF(0), LSFT(KC_TAB), MI_E_1, MI_F_1, MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1, MI_As_5, MI_Fs_5, KC_TAB, MI_A_4, MI_Gs, MI_A, MI_As, MI_B, MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_A_5, LCTL(KC_U), LCTL(KC_D), KC_SPC, MI_C, MI_Cs, MI_D, MI_Ds, MI_E, MI_F, MI_Fs, MI_G, MI_Gs_5, MI_E_5, MI_C_5),
	[3] = LAYOUT_ortho_4x12(LCTL(KC_Y), LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_DEL, KC_BSLS, KC_7, KC_8, KC_9, KC_COLN, KC_BSPC, KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, HOLD_LALTTAB, KC_LBRC, KC_4, KC_5, KC_6, KC_RBRC, KC_PIPE, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_MINS, KC_1, KC_2, KC_3, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(6), MO(6), KC_0, KC_TRNS, KC_MSTP, KC_MNXT, KC_MPLY),
	[4] = LAYOUT_ortho_4x12(KC_GRV, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_PIPE, KC_AMPR, KC_ASTR, KC_TILD, KC_TRNS, KC_BSPC, KC_DEL, KC_CAPS, KC_F5, KC_F6, KC_F7, KC_F8, KC_LCBR, KC_DLR, KC_PERC, KC_CIRC, KC_RCBR, KC_BSLS, KC_TRNS, KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_UNDS, KC_EXLM, KC_AT, KC_HASH, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(6), KC_TRNS, KC_TRNS, MO(6), KC_TAB, KC_VOLD, KC_VOLU, KC_MPLY),
	[5] = LAYOUT_ortho_4x12(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, TO(0), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO, KC_NO, KC_NO),
	[6] = LAYOUT_ortho_4x12(KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, KC_TRNS, KC_TRNS, DF(0), DF(1), DF(2), TO(5), KC_TRNS, KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT_ortho_4x12(KC_NO, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2, MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, KC_TRNS, KC_TRNS, KC_TRNS)
};

