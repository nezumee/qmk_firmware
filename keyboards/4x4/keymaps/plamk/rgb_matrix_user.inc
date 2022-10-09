// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(midi_feedback_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

const int CLIP_BLOCK_INITIAL_KEY = MI_C;
const int TRACK_ARM_INITIAL_KEY = MI_Gs_2;
const int TRACK_STOP_INITIAL_KEY = MI_E_3;
const int SCENE_INITIAL_KEY = MI_Gs_5;
extern char indicators[];
extern led_config_t g_led_config;

#ifdef CONSOLE_ENABLED
uint16_t debug_timer = 0;
uint16_t debug_counter = 0;
uint16_t debugColor = 0;
#endif

extern const uint8_t ableton_colors[];

// e.g: A simple effect, self-contained within a single method
static bool midi_feedback_effect(effect_params_t* params) 
{
	RGB_MATRIX_USE_LIMITS(led_min, led_max);  
	uint8_t layer = get_highest_layer(layer_state|default_layer_state);

	#ifdef CONSOLE_ENABLED
	if (0 == debug_counter && timer_elapsed(debug_timer) > 10000)
	{
		debug_counter = 100;
		dprintf("layer %u\n", layer);
		uint16_t t = debugColor*3;
		dprintf("CC %u %u %u %u %u\n", debugColor, t, ableton_colors[t], ableton_colors[t+1], ableton_colors[t+2]);
		debugColor++;
		if (debugColor > 100)
		{
			debugColor = 0;
		}
	}
	#endif

	for (uint8_t row = 0; row < MATRIX_ROWS; ++row)
	{
		for (uint8_t col = 0; col < MATRIX_COLS; ++col)
		{
			uint8_t index = g_led_config.matrix_co[row][col];

			if (index >= led_min && index <= led_max && index != NO_LED)
			{
				uint16_t light;
				uint16_t key = keymap_key_to_keycode(layer, (keypos_t){col,row});
				if (key >= CLIP_BLOCK_INITIAL_KEY && key < CLIP_BLOCK_INITIAL_KEY + CLIP_BLOCK_X * CLIP_BLOCK_Y)
				{
					light = indicators[key - CLIP_BLOCK_INITIAL_KEY];
				}
				else if (key >= TRACK_ARM_INITIAL_KEY && key < TRACK_ARM_INITIAL_KEY + CLIP_BLOCK_X)
				{
					// TODO use skinning from Ableton instead of hardcoding?
					// TODO constants for colors
					light = 6;	// arm - red
				}
				else if (key >= TRACK_STOP_INITIAL_KEY && key < TRACK_STOP_INITIAL_KEY + CLIP_BLOCK_X)
				{
					light = 118;	// stop - gray
				}
				else if (KC_SPACE == key)
				{
					light = 21;	// play - bright green
				}
				else if (KC_DEL == key)
				{
					light = 5;	// delete - bright red
				}
				else if (MI_A_4 == key)
				{
					light = 6;	// overdub - red
				}
				else if (key >= SCENE_INITIAL_KEY && key <= SCENE_INITIAL_KEY + CLIP_BLOCK_Y)
				{
					light = 22;	// scene play - green
				}
				else if ((key >= QK_DEF_LAYER && key <= QK_DEF_LAYER_MAX) ||
					(key >= QK_ONE_SHOT_LAYER && key <= QK_ONE_SHOT_LAYER_MAX))
				{
					light = 99;	// layer switches - yellow
				}
				else if ((key >= QK_LAYER_TAP && key <= QK_LAYER_TAP_MAX) ||
					(key >= QK_MOD_TAP && key <= QK_MOD_TAP_MAX))
				{
					light = 81;	// modtap layer and homerow switches - purple
				}
				else if (key > KC_TRNS)
				{
					light = 47;	// other keys - dark blue
				}
				else
				{
					light = 0;	// no key - black
				}

				uint8_t r = ableton_colors[light*3];
				uint8_t g = ableton_colors[light*3+1];
				uint8_t b = ableton_colors[light*3+2];
				
				// TODO dynamic brightness
				rgb_matrix_set_color(index, r/4, g/4, b/4);
				
				#ifdef CONSOLE_ENABLED
				if (debug_counter > 0)
				{
					dprintf("LED %u r%u c%u key%u l%u r%u g%u b%u\n", index, row, col, key, light, r, g, b);
				
					debug_counter--;
					if (0 == debug_counter)
					{
						debug_timer = timer_read();
					}
				}
				#endif
			}
		}
	}
	
	return rgb_matrix_check_finished_leds(led_max);
}

#endif