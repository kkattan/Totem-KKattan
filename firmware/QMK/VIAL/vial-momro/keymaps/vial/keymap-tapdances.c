#include QMK_KEYBOARD_H
#include "keymap_german.h" // <-- Füge diese Zeile hinzu!

// for reasons unknown to me, tap dance definition only works if this ifndef stuff is included, and there is an endif at the end
#ifndef KEYMAP_MOMRO_H // Oder einen anderen eindeutigen Namen
#define KEYMAP_MOMRO_H
#include "keymap_introspection.h"



enum custom_keycodes {
    TRI_BRK_O = SAFE_RANGE, // Dein Custom Keycode
    // Füge hier weitere Custom Keycodes hinzu, wenn du sie brauchst
};



// https://docs.qmk.fm/features/tap_dance
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

//#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        
#define ACT_TDTH(tap, hold)                                   { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


// Layer name definition
#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _MOVEMENT 3
//#define _NUMBERS 4
//#define _ACTIONS 5
//#define _AUTOMOUSE 6
//#define _I3MOVE 7


// Initialise Tap Dances
enum {
    TD_A, 
    TD_O,
	TD_U,
	TD_QCUT,
	TD_JCPY,
    TD_KPST,
    TD_XPRT,
    TD_RGUI,
    TD_NXLM,
	TD_SSRP,
    TD_EURO,
	TD_COLN,
	TD_DOT,
	TD_AMPR,
	TD_FSLH,
	TD_BSLH,
	TD_DASH,
	TD_DOLR,
	TD_QMRK,
	TD_ACNT,
	TD_HERT,
	TD_SEVN,
	TD_FIVE,
	TD_THRE,
	TD_ONE,
	TD_ZERO,
	TD_TWO,
	TD_FOUR,
	TD_STRS
};


// Define Tap Dances
// "__attribute__((weak))" is somewhat required? No idea, copilot told me to use that, and it works. won't complain
__attribute__((weak)) tap_dance_action_t tap_dance_actions[] = {
	//tap_dance_action_t tap_dance_actions[] = {
	// German Umlaute
    [TD_A]    = ACT_TDTH(KC_A, KC_B),       // TAP: a HOLD: ä -- current 10
	[TD_O]    = ACT_TDTH(KC_O, DE_ODIA),        // TAP: o HOLD: ö -- current 11
    [TD_U]    = ACT_TDTH(KC_U, DE_UDIA),    // TAP: u HOLD: ü -- current 14
	
	
	// other keybinds in normal layer
    [TD_QCUT] = ACT_TDTH(KC_Q,                LCTL(KC_X)),     // TAP: q HOLD: CTRL+X -- current 15
    [TD_JCPY] = ACT_TDTH(KC_J,                LCTL(KC_C)),     // TAP: j HOLD: CTRL+C -- current 16
    [TD_KPST] = ACT_TDTH(KC_K,                LCTL(KC_V)),     // TAP: k HOLD: CTRL+V -- current 17
    [TD_XPRT] = ACT_TDTH(KC_X,                KC_PSCR),        // TAP: x HOLD: PRINT -- current 18
    [TD_RGUI] = ACT_TDTH(KC_R,                KC_LGUI),        // TAP: r HOLD: GUI/Win -- current 19
    [TD_NXLM] = ACT_TDTH(KC_N,                LSFT(KC_1)),     // TAP: n HOLD: ! -- current 20
	[TD_SSRP] = ACT_TDTH(KC_S,                KC_MINUS),       // TAP: s HOLD: ß -- current 21
    //[TD_EURO] = ACT_TDTH(KC_E,                RALT(KC_E)),     // TAP: e HOLD: € -- current 12
	[TD_EURO] = ACT_TDTH(KC_COLN, KC_SCLN),

	// All Tap Dances are mapped to German keyboard, so my Dances might not be suitable for non-German users
	// I use these for easier access to all the special chars I need
	[TD_COLN] = ACT_TDTH(KC_COMMA,            LSFT(KC_COMMA)), // TAP: , HOLD: ; -- current 0
	[TD_DOT]  = ACT_TDTH(KC_DOT,              LSFT(KC_DOT)),   // TAP: . HOLD: : -- current 1
	[TD_AMPR] = ACT_TDTH(LSFT(KC_6),          KC_GRAVE),       // TAP: & HOLD: ^ -- current 2
	[TD_FSLH] = ACT_TDTH(LSFT(KC_7),          LSFT(KC_MINUS)), // TAP: / HOLD: ? -- current 3
	[TD_BSLH] = ACT_TDTH(RALT(KC_MINUS),      LSFT(KC_1)),     // TAP: \ HOLD: ! -- current 8
	[TD_DASH] = ACT_TDTH(KC_SLASH,            LSFT(KC_SLASH)), // TAP: - HOLD: _ -- current 27
	[TD_DOLR] = ACT_TDTH(LSFT(KC_4),          LSFT(KC_D)),     // TAP: $ HOLD: D -- current 4
	[TD_QMRK] = ACT_TDTH(LSFT(KC_NONUS_HASH), LSFT(KC_2)),     // TAP: ' HOLD: " -- current 6
	[TD_ACNT] = ACT_TDTH(KC_EQUAL,            LSFT(KC_EQUAL)), // TAP: ´ HOLD: ` -- current 7
	// easy access to the heart emoji - <3
	[TD_HERT] = ACT_TDTH(KC_NONUS_BACKSLASH,  KC_3),           // TAP: < HOLD: 3 -- current 9
	
	// number layer tap dances
	[TD_SEVN] = ACT_TDTH(KC_7,                KC_ESC),         // TAP: 7 HOLD: ESC -- current 22 
	[TD_FIVE] = ACT_TDTH(KC_5,                LSFT(KC_5)),     // TAP: 5 HOLD: % -- current 31
	[TD_THRE] = ACT_TDTH(KC_3,                RALT(KC_E)),     // TAP: 3 HOLD: € -- current 30
	[TD_ONE]  = ACT_TDTH(KC_1,                LSFT(KC_8)),     // TAP: 1 HOLD: ( -- current 29
	[TD_ZERO] = ACT_TDTH(KC_0,                LSFT(KC_9)),     // TAP: 0 HOLD: ) -- current 26
	[TD_TWO]  = ACT_TDTH(KC_2,                LSFT(KC_4)),     // TAP: 2 HOLD: $ -- current 25
	[TD_FOUR] = ACT_TDTH(KC_4,                LSFT(KC_6)),     // TAP: 4 HOLD: & -- current 24
	[TD_STRS] = ACT_TDTH(LSFT(KC_RBRC),   KC_COMMA),       // TAP: * HOLD: , -- current 23
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_A): // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}


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
                     TD(TD_A),      TD(TD_O),    TD(TD_EURO),      KC_I,         TD(TD_U), 	 KC_H, 		  KC_D,         TD(TD_RGUI),  TD(TD_NXLM),  TD(TD_SSRP), 
       KC_C,        OSM(MOD_LCTL), TD(TD_QCUT), TD(TD_JCPY),   TD(TD_KPST),  TD(TD_XPRT), 	 KC_B,        KC_M,         KC_W,         KC_L,         KC_V,         KC_BTN1,
                                                 OSM(MOD_LSFT), KC_SPACE,     MO(1),     	 MO(2),       TT(3),        OSM(MOD_LALT)
    ),
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
    )
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
bool led_update_user(led_t state) {
    // if already in mouse layer, don't change any layers
    if (state.scroll_lock != layer_state_is(_MOVEMENT)) {
        layer_invert(_MOVEMENT);
    }
    return true;
}

#endif // KEYMAP_MOMRO_H
