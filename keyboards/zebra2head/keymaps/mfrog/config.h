// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#pragma once

// default but important
#define TAPPING_TERM 170
//#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
// #define QMK_KEYS_PER_SCAN 4

#define COMBO_COUNT 27

#define LED_NAV_PIN (LED_ZEBRA_HEAD_PIN)

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 5000