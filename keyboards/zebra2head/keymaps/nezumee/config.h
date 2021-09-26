#pragma once

#include "nezumee_config.h"

// default but important
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_FORCE_HOLD_PER_KEY

#define LAYER_QWERTY 0
#define LAYER_COLEMAK 1
#define LAYER_CLOSE 3
#define LAYER_FAR 4
#define LAYER_INNER 5

#define LED_AMBER_CAPS_PIN LED_ZEBRA_PIN_1
#define LED_QWERTY_PIN LED_ZEBRA_PIN_2