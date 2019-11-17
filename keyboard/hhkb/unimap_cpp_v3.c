#include "unimap_trans.h"
#include "print.h"

enum macro_id {
    CPP_POINTER,
    CPP_COMMENT,
    L3_QUOTE,
    L3_MINUS,
    // L3_LBRACKET,
    L3_RBRACKET,
    L3_BSLASH,
    L3_GRAVE,
};

enum function_id {
    KEY_FN3_LSHIFT,
    KEY_FN4_RSHIFT,
    KEY_FN34_LNSTART,
    KEY_FN34_LNEND,
};

// L0, for remapped X keycodes
// 1st row
// #define AC_L0_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
// #define AC_L0_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
// 2nd row
#define AC_L0_RCBK       ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET)
#define AC_L0_LCBK       ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET)
// 3rd row
#define AC_L0_COLN       ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON)
// 4th row
#define AC_L0_DBQT       ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE)

#define AC_FN1           ACTION_LAYER_MOMENTARY(1)
#define AC_FN3L          ACTION_FUNCTION(KEY_FN3_LSHIFT)
#define AC_FN4R          ACTION_FUNCTION(KEY_FN4_RSHIFT)
#define AC_FN5_TG        ACTION_LAYER_TOGGLE(5)

//#define AC_TABF          ACTION_LAYER_TAP(2, KC_TAB) // FN
#define AC_ESCF          ACTION_LAYER_TAP(2, KC_ESC) // FN2
// #define AC_ENT_          ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER)

// L2, mainly for navigation, currently only line start/line end(which will be mapped to ctrl+a/ctrl+e on normal mode and home/end on windows mode)
#define AC_LNST          ACTION_FUNCTION(KEY_FN34_LNSTART)
#define AC_LNED          ACTION_FUNCTION(KEY_FN34_LNEND)

// L3, for remapped L Shift+X keycodes
#define AC_L3(KEY)       ACTION_MODS_KEY(MOD_LSFT, KC_##KEY)

// 1st row
#define AC_L3_DBQT       ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE)
#define AC_L3_SGQT       ACTION_MACRO(L3_QUOTE)
#define AC_L3_PIPE       ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH)
#define AC_L3_MINS       ACTION_MACRO(L3_MINUS)
#define AC_L3_PLUS       ACTION_MODS_KEY(MOD_LSFT, KC_EQUAL)
#define AC_L3_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define AC_L3_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
// #define AC_L3_LBRC       ACTION_MACRO(L3_LBRACKET)
#define AC_L3_RBRC       ACTION_MACRO(L3_RBRACKET)
#define AC_L3_TIDL       ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE)
#define AC_L3_GRV        ACTION_MACRO(L3_GRAVE)
// 2nd row
#define AC_L3_LSBK       ACTION_MODS_KEY(MOD_LSFT, KC_COMMA)
#define AC_L3_RSBK       ACTION_MODS_KEY(MOD_LSFT, KC_DOT)
// 3rd row
#define AC_L3_HASH       ACTION_MODS_KEY(MOD_LSFT, KC_3)
#define AC_L3_DLLR       ACTION_MODS_KEY(MOD_LSFT, KC_4)
#define AC_L3_CCMT       ACTION_MACRO(CPP_COMMENT)
// 4th row
#define AC_L3_USCR       ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)
#define AC_L3_QSTM       ACTION_MODS_KEY(MOD_LSFT, KC_SLASH)
#define AC_L3_CPTR       ACTION_MACRO(CPP_POINTER)
#define AC_L3_BSLS       ACTION_MACRO(L3_BSLASH)


// L4, for remapped R Shift+X keycodes
#define AC_L4(KEY)       ACTION_MODS_KEY(MOD_RSFT, KC_##KEY)
// 1st row
#define AC_L4_DBQT       ACTION_MODS_KEY(MOD_RSFT, KC_QUOTE)
#define AC_L4_SGQT       ACTION_MACRO(L3_QUOTE)
#define AC_L4_PIPE       ACTION_MODS_KEY(MOD_RSFT, KC_BSLASH)
#define AC_L4_MINS       ACTION_MACRO(L3_MINUS)
#define AC_L4_PLUS       ACTION_MODS_KEY(MOD_RSFT, KC_EQUAL)
#define AC_L4_LPRN       ACTION_MODS_KEY(MOD_RSFT, KC_9)
#define AC_L4_RPRN       ACTION_MODS_KEY(MOD_RSFT, KC_0)
// #define AC_L4_LBRC       ACTION_MACRO(L3_LBRACKET)
#define AC_L4_RBRC       ACTION_MACRO(L3_RBRACKET)
#define AC_L4_TIDL       ACTION_MODS_KEY(MOD_RSFT, KC_GRAVE)
#define AC_L4_GRV        ACTION_MACRO(L3_GRAVE)
// 2nd row
#define AC_L4_LSBK       ACTION_MODS_KEY(MOD_RSFT, KC_COMMA)
#define AC_L4_RSBK       ACTION_MODS_KEY(MOD_RSFT, KC_DOT)
// 3rd row
#define AC_L4_HASH       ACTION_MODS_KEY(MOD_RSFT, KC_3)
#define AC_L4_DLLR       ACTION_MODS_KEY(MOD_RSFT, KC_4)
#define AC_L4_CCMT       ACTION_MACRO(CPP_COMMENT)
// 4th row
#define AC_L4_USCR       ACTION_MODS_KEY(MOD_RSFT, KC_MINUS)
#define AC_L4_QSTM       ACTION_MODS_KEY(MOD_RSFT, KC_SLASH)
#define AC_L4_CPTR       ACTION_MACRO(CPP_POINTER)
#define AC_L4_BSLS       ACTION_MACRO(L3_BSLASH)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = UNIMAP_HHKB(
    ESCF,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS,    FN1,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC,        BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,               ENT,
    FN3L,Z,   X,   C,   V,   B,   N,   M,   COMM, DOT,SLSH,   FN4R,            DEL,
         LALT,LGUI,               SPC,                RGUI, RALT),

    // This is HHKB original Fn1 layer but removed navigation keys
    [1] = UNIMAP_HHKB(
    PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, TRNS,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,     TRNS,
    TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,TRNS,TRNS,TRNS,TRNS,          PENT,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         TRNS,TRNS,               FN5_TG,                  TRNS,TRNS),

    // Esc navigation
    [2] = UNIMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LNST,  UP,LNED,HOME,PGUP,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT, END,PGDN,          TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         TRNS,TRNS,                  TRNS,                 TRNS,TRNS),

    // Remapped L Shift-X keys
    [3] = UNIMAP_HHKB(
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,TRNS,TRNS,L3_TIDL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,TRNS,         DEL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,          L3_CCMT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,          L3_CPTR,
             TRNS,  TRNS,                  L3_USCR,               TRNS,  TRNS),

    // Remapped R Shift-X keys
    [4] = UNIMAP_HHKB(
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,TRNS,TRNS,L4_TIDL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,TRNS,         DEL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,          L4_CCMT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS,          L4_CPTR,
             TRNS,  TRNS,                  L4_USCR,               TRNS,  TRNS),

    // Swap left (GUI/WIN)<->(ALT/OPTION)
    [5] = UNIMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         LGUI,LALT,                 TRNS,                 RALT,RGUI),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case CPP_POINTER:
            return (record->event.pressed ?
                    MACRO( I(0), SM(), CM(), T(MINUS), ST(DOT), RM(), END ) :
                    MACRO_NONE );

        case CPP_COMMENT:
            return (record->event.pressed ?
                    MACRO( I(0), SM(), CM(), T(SLSH), T(SLSH), T(SPC), RM(), END ) :
                    MACRO_NONE );

        case L3_QUOTE:
            return (record->event.pressed ? 
                    MACRO( I(0), SM(), CM(), T(QUOTE), RM(), END ) : 
                    MACRO_NONE );

        case L3_MINUS:
            return (record->event.pressed ? 
                    MACRO( I(0), SM(), CM(), T(MINUS), RM(), END ) : 
                    MACRO_NONE );

        // case L3_LBRACKET:
        //     return (record->event.pressed ? 
        //             MACRO( I(0), SM(), CM(), T(LBRACKET), RM(), END ) : 
        //             MACRO_NONE );

        case L3_RBRACKET:
            return (record->event.pressed ? 
                    MACRO( I(0), SM(), CM(), T(RBRACKET), RM(), END ) : 
                    MACRO_NONE );

        case L3_BSLASH:
            return (record->event.pressed ?
                    MACRO( I(0), SM(), CM(), T(BSLASH), RM(), END ) : 
                    MACRO_NONE );
        case L3_GRAVE:
            return (record->event.pressed ?
                    MACRO( I(0), SM(), CM(), T(GRAVE), RM(), END ) : 
                    MACRO_NONE );
    }
    return MACRO_NONE;
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // The reason we have L/R shift mapped to different layer is 
    // the magic key L Shift + R Shift + [0-4](or other magic keys)
    switch(id)
    {
        case KEY_FN3_LSHIFT:
        {
            if (record->event.pressed) 
            {
                layer_on(3);
                register_code(KC_LSHIFT);
            }
            else
            {
                unregister_code(KC_LSHIFT);
                layer_off(3);
            }
        }
        break;
        case KEY_FN4_RSHIFT:
        {
            if (record->event.pressed) 
            {
                layer_on(4);
                register_code(KC_RSHIFT);
            }
            else
            {
                unregister_code(KC_RSHIFT);
                layer_off(4);
            }
        }
        break;
        case KEY_FN34_LNSTART:
        {
            uint32_t layer_win_on = layer_state_make(5);
            if (layer_test(layer_win_on))
            {
                // Windows use HOME/END instead of ctrl+a/ctrl+e
                if (record->event.pressed)
                {
                    register_code(KC_HOME);
                }
                else
                {
                    unregister_code(KC_HOME);
                }
            }
            else {
                if (record->event.pressed)
                {
                    // down mod
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    // down key
                    register_code(KC_A);
                }
                else
                {
                    // up key
                    unregister_code(KC_A);
                    // up mod
                    del_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();

                }
            }
        }
        break;
        case KEY_FN34_LNEND:
        {
            uint32_t layer_win_on = layer_state_make(5);
            if (layer_test(layer_win_on))
            {
                // Windows use HOME/END instead of ctrl+a/ctrl+e
                if (record->event.pressed)
                {
                    register_code(KC_END);
                }
                else
                {
                    unregister_code(KC_END);
                }
            }
            else 
            {
                if (record->event.pressed)
                {
                    // down mod
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    // down key
                    register_code(KC_E);
                }
                else
                {
                    // up key
                    unregister_code(KC_E);
                    // up mod
                    del_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();                    
                }
            }
        }
        break;

    }
}
