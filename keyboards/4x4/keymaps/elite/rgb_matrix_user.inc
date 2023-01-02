RGB_MATRIX_EFFECT(midi_elite_controls_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include "color.h"

extern led_config_t g_led_config;

typedef enum {
	BLACK = 0,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	PURPLE,
	WHITE,
	GOLD,
	GOLDENROD,
	ORANGE,
	PINK,
	SPRINGGREEN,
	TURQUOISE,
	BASE_COLOR_MASK = 0x7f,
	DARK = 0x80
} my_color;

const uint8_t my_color_rgb[] = {
	RGB_BLACK,
	RGB_RED,
	RGB_GREEN,
	RGB_BLUE,
	RGB_YELLOW,
	RGB_CYAN,
	RGB_PURPLE,
	RGB_WHITE,
	RGB_GOLD,
	RGB_GOLDENROD,
	RGB_ORANGE,
	RGB_PINK,
	RGB_SPRINGGREEN,
	RGB_TURQUOISE
/*	0,		0,		0,
	0xff,	0,		0,
	0,		0xff,	0,
	0,		0,		0xff,
	0xff,	0xff,	0,
	0,		0xff,	0xff,
	0xff,	0,		0xff,
	0xff,	0xff,	0xff*/
};

static my_color get_key_color(uint16_t key)
{
	switch (key & QK_BASIC_MAX)
	{
		// Direction
		case KC_Q:
		case KC_E:
		case KC_A:
		case KC_D:
			return DARK | GREEN;
			
		// Throttle
		case KC_TAB:
		case KC_W:
		case KC_S:
		case KC_X:
		case KC_R:
		case KC_F:
		case KC_F1:
		case KC_F2:
			return GREEN;
			
		// Target
		case KC_T:
		case KC_G:
			return PURPLE;
			
		// Weapons
		case KC_U:
		case KC_N:
		case KC_M:
			return RED;
			
		// Exploration
		case KC_QUOT:
		case KC_F5:
		case KC_F6:
		case KC_INS:
		case KC_F12:
			return DARK | GOLD;
			
		// FSD
		case KC_F4:
			return YELLOW;
			
		case KC_J:
			return ORANGE;
			
		// Panels
		case KC_1:
		case KC_2:
		case KC_3:
		case KC_4:
			return CYAN;
			
		// System
		case KC_ESC:
		case KC_ENT:
		case KC_BSPC:
		case KC_SPC:
		case KC_LEFT:
		case KC_RIGHT:
		case KC_UP:
		case KC_DOWN:
			return WHITE;
		
		case KC_TRNS:
			return DARK | BLUE;
			
		case KC_NO:
			return BLACK;
	}
	
	// Other
	return DARK | WHITE;
}

/* Use MIDI controller feedback notes sent to the keyboard to set the color of each button */
static bool midi_elite_controls_effect(effect_params_t* params) 
{
	RGB_MATRIX_USE_LIMITS(led_min, led_max);  
	
	uint8_t layer = get_highest_layer(layer_state | default_layer_state);

	for (uint8_t row = 0; row < MATRIX_ROWS; ++row)
	{
		for (uint8_t col = 0; col < MATRIX_COLS; ++col)
		{
			uint8_t index = g_led_config.matrix_co[row][col];

			if (index >= led_min && index <= led_max && index != NO_LED)
			{
				
				uint16_t key = keymap_key_to_keycode(layer, (keypos_t){col,row});
				my_color key_color = get_key_color(key);
				
				uint8_t color_index = key_color & BASE_COLOR_MASK;
				
				uint8_t r = my_color_rgb[color_index*3];
				uint8_t g = my_color_rgb[color_index*3 + 1];
				uint8_t b = my_color_rgb[color_index*3 + 2];
				
				if (key_color & DARK)
				{
					r /= 4;
					g /= 4;
					b /= 4;
				}
				
				// TODO dynamic brightness
				rgb_matrix_set_color(index, r/4, g/4, b/4);
			}
		}
	}
	
	return rgb_matrix_check_finished_leds(led_max);
}

#endif