#include QMK_KEYBOARD_H
#include "keymap_german.h"



enum custom_keycodes {
    TRI_BRK_O = SAFE_RANGE, // Dein Custom Keycode
    // Füge hier weitere Custom Keycodes hinzu, wenn du sie brauchst
};

// Layer name definition
#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _MOVEMENT 3
//#define _NUMBERS 4
//#define _ACTIONS 5
//#define _AUTOMOUSE 6
//#define _I3MOVE 7


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
      ┌─────────────────────────────────────────────────┐
      │ q w e r t y                                     │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    ;    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │    Q    │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    P    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │  CTRL   │  LOWER  │  SPACE  ││  ENTER  │  RAISE  │  BSPC   │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘
	*/
									
									
	/*
      ┌─────────────────────────────────────────────────┐
      │ D v o r a k / Base Layer                        │                            ╭╮╭╮╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘                            │╰╯╰╯╰╯╰╯╰╯│
                    ┌─────────────┬─────────────┬─────────────┬─────────────┬────────╨────┐┌────╨────────┬─────────────┬─────────────┬─────────────┬─────────────┐
            ╌┄┈┈───═╡    ESC      │    ,        │    .        │        P    │        Y    ││      F      │        G    │        C    │        T    │        Z    │
                    ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
                    │    A        │    O        │        E    │        I    │        U    ││        H    │         D   │        R    │       N     │        S    │
      ┌─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┐
      │   MOUSE2    │  OSM(LCTL)  │    Q        │        J    │        K    │        X    ││       B     │        M    │       W     │        L    │        V    │    MOUSE1   │
      └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────┘
                                                │  OSM(LSFT)  │  SPACE      │ MO(SYMBOLS) ││ MO(NUMBERS) │    TT(NAV)  │  OSM(LALT)  │
                                                └─────────────┴─────────────┴─────────────┘└─────────────┴─────────────┴─────────────┘
	*/

    [_BASE] = LAYOUT(
                     KC_ESCAPE,     KC_COMMA,    KC_DOT,        KC_P,         KC_Z,  		 KC_F, 		  KC_G,         KC_C,         KC_T,         KC_Y,
                     KC_A,      KC_O,    KC_E,      KC_I,        KC_U, 	 KC_H, 		  KC_D,         KC_R,  KC_N,  KC_S, 
       KC_BTN2,        OSM(MOD_LCTL), KC_Q, KC_J,   KC_K,  KC_X, 	 KC_B,        KC_M,         KC_W,         KC_L,         KC_V,         KC_BTN1,
                                                 OSM(MOD_LSFT), KC_SPACE,     MO(1),     	 MO(2),       TT(3),        OSM(MOD_LALT)
    ),	
	[_SYMBOLS] = LAYOUT(
		              KC_ESCAPE,     KC_COMMA,    KC_DOT,        KC_P,         KC_Z,  		 KC_F, 		  KC_G,         KC_C,         KC_T,         KC_Y,
                     KC_A,      KC_O,    KC_E,      KC_I,        KC_U, 	 KC_H, 		  KC_D,         KC_R,  KC_N,  KC_S, 
       KC_C,        OSM(MOD_LCTL), KC_Q, KC_J,   KC_K,  KC_X, 	 KC_B,        KC_M,         KC_W,         KC_L,         KC_V,         KC_BTN1,
                                                 OSM(MOD_LSFT), KC_SPACE,     MO(1),     	 MO(2),       TT(3),        OSM(MOD_LALT)
    ),
	[_NUMBERS] = LAYOUT(
         KC_ESCAPE,     KC_COMMA,    KC_DOT,        KC_P,         KC_Z,  		 KC_F, 		  KC_G,         KC_C,         KC_T,         KC_Y,
                     KC_A,      KC_O,    KC_E,      KC_I,        KC_U, 	 KC_H, 		  KC_D,         KC_R,  KC_N,  KC_S, 
       KC_C,        OSM(MOD_LCTL), KC_Q, KC_J,   KC_K,  KC_X, 	 KC_B,        KC_M,         KC_W,         KC_L,         KC_V,         KC_BTN1,
                                                 OSM(MOD_LSFT), KC_SPACE,     MO(1),     	 MO(2),       TT(3),        OSM(MOD_LALT)
    ),
    [_MOVEMENT] = LAYOUT(
               KC_ESCAPE,     KC_COMMA,    KC_DOT,        KC_P,         KC_Z,  		 KC_F, 		  KC_G,         KC_C,         KC_T,         KC_Y,
                     KC_A,      KC_O,    KC_E,      KC_I,        KC_U, 	 KC_H, 		  KC_D,         KC_R,  KC_N,  KC_S, 
       KC_C,        OSM(MOD_LCTL), KC_Q, KC_J,   KC_K,  KC_X, 	 KC_B,        KC_M,         KC_W,         KC_L,         KC_V,         KC_BTN1,
                                                 OSM(MOD_LSFT), KC_SPACE,     MO(1),     	 MO(2),       TT(3),        OSM(MOD_LALT)
    )
	/*
	[_SYMBOLS] = LAYOUT(
		             RALT(KC_RBRC), RALT(KC_8), RALT(KC_7), LSFT(KC_8),   TD(9),   LSFT(KC_NONUS_BACKSLASH), LSFT(KC_9), RALT(KC_0), RALT(KC_9),   KC_GRAVE,
		             TD(0),         TD(1),       TD(27),        TD(4),        LSFT(KC_0), KC_NONUS_HASH, RALT(KC_Q), TD(6), LSFT(KC_RBRC), RALT(KC_NONUS_BACKSLASH),
		KC_TRNS, OSM(MOD_LCTL), TD(2), KC_RBRC, TD(3), LSFT(KC_GRAVE), TD(7), TD(8), LSFT(KC_5), LSFT(KC_6), OSM(MOD_LALT), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_NUMBERS] = LAYOUT(
        TD(22), TD(31), TD(30), TD(29), KC_9, KC_8, TD(26), TD(25), TD(24), KC_6,
        OSM(MOD_LALT), TD(28), KC_RBRC, TD(27), KC_F11, KC_F12, TD(23), LSFT(KC_7), LSFT(KC_0), OSM(MOD_LSFT), 
        KC_TRNS, KC_F7, KC_F5, KC_F3, KC_F1, KC_F9, KC_F8, KC_F10, KC_F2, KC_F4, KC_F6, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MOVEMENT] = LAYOUT(
              KC_ESC, KC_MS_L, KC_MS_U, KC_MS_R, LCTL(KC_X), KC_TAB, KC_ENTER, KC_UP, KC_PGUP, OSM(MOD_LALT),
              KC_LGUI, KC_BTN2, KC_MS_D, KC_BTN1, LCTL(KC_C), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, 
       KC_NO, OSM(MOD_LCTL), KC_WH_U, KC_BTN2, KC_WH_D, KC_TRNS, LCTL(KC_V), KC_BSPC, KC_DELETE, KC_PGDN, OSM(MOD_LCTL), KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), KC_TRNS
    )*/
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
             'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
             'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );

// I am using a Ploopy Nano as trackball, and this code is meant to automatically swap to nav layer once the Ploopy is moved
// "nano to keeb communcation"
/*
bool led_update_user(led_t state) {
    // if already in mouse layer, don't change any layers
    if (state.scroll_lock != layer_state_is(_AUTOMOUSE)) {
        layer_invert(_AUTOMOUSE);
    }
    return true;
}
*/
