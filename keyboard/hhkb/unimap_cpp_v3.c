#include "unimap_trans.h"
#include "print.h"

enum macro_id {
    CPP_POINTER,
    CPP_COMMENT,
    L3_QUOTE,
    L3_MINUS,
    L3_LBRACKET,
    L3_RBRACKET,
    L3_BSLASH,
    L3_GRAVE,
};

enum function_id {
    KEY_FN3_LSHIFT,
    KEY_FN4_RSHIFT,
};


// L0, for remapped X keycodes
// 1st row
#define AC_L0_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define AC_L0_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
// 2nd row
#define AC_L0_RCBK       ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET)
#define AC_L0_LCBK       ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET)
// 3rd row
#define AC_L0_COLN       ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON)

#define AC_FN1           ACTION_LAYER_MOMENTARY(1)
#define AC_FN3L          ACTION_FUNCTION(KEY_FN3_LSHIFT)
#define AC_FN4R          ACTION_FUNCTION(KEY_FN4_RSHIFT)
#define AC_FN5           ACTION_LAYER_TAP_TOGGLE(5)

#define AC_TABF          ACTION_LAYER_TAP(2, KC_TAB) // FN2
#define AC_ENT_          ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER)

// L2, mainly for navigation
// #define AC_L2(KEY)       ACTION_MODS_KEY(MOD_LCTL, KC_##KEY)
// #define AC_L2_LNST       ACTION_MODS_KEY(MOD_LCTL, KC_A)
// #define AC_L2_LNED       ACTION_MODS_KEY(MOD_LCTL, KC_E)
#define AC_LNST          ACTION_MODS_KEY(MOD_LCTL, KC_A)
#define AC_LNED          ACTION_MODS_KEY(MOD_LCTL, KC_E)

// L3, for remapped L Shift+X keycodes
#define AC_L3(KEY)       ACTION_MODS_KEY(MOD_LSFT, KC_##KEY)

// 1st row
// #define AC_L3_GRAV       ACTION_KEY(KC_GRAVE)
#define AC_L3_DBQT       ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE)
#define AC_L3_SGQT       ACTION_MACRO(L3_QUOTE)
#define AC_L3_PIPE       ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH)
#define AC_L3_MINS       ACTION_MACRO(L3_MINUS)
#define AC_L3_PLUS       ACTION_MODS_KEY(MOD_LSFT, KC_EQUAL)
#define AC_L3_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define AC_L3_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
#define AC_L3_LBKT       ACTION_MACRO(L3_LBRACKET)
#define AC_L3_RBKT       ACTION_MACRO(L3_RBRACKET)
// #define AC_L3_AT         ACTION_MODS_KEY(MOD_LSFT, KC_2)
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
// #define AC_L4_GRAV       ACTION_KEY(KC_GRAVE)
#define AC_L4_DBQT       ACTION_MODS_KEY(MOD_RSFT, KC_QUOTE)
#define AC_L4_SGQT       ACTION_MACRO(L3_QUOTE)
#define AC_L4_PIPE       ACTION_MODS_KEY(MOD_RSFT, KC_BSLASH)
#define AC_L4_MINS       ACTION_MACRO(L3_MINUS)
#define AC_L4_PLUS       ACTION_MODS_KEY(MOD_RSFT, KC_EQUAL)
#define AC_L4_LPRN       ACTION_MODS_KEY(MOD_RSFT, KC_9)
#define AC_L4_RPRN       ACTION_MODS_KEY(MOD_RSFT, KC_0)
#define AC_L4_LBKT       ACTION_MACRO(L3_LBRACKET)
#define AC_L4_RBKT       ACTION_MACRO(L3_RBRACKET)
// #define AC_L4_AT         ACTION_MODS_KEY(MOD_RSFT, KC_2)
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
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL,L0_LPRN,L0_RPRN,
    TABF,Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   L0_LCBK,L0_RCBK,    BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,L0_COLN,            ENT,
    FN3L,Z,   X,   C,   V,   B,   N,   M,   COMM, DOT,SLSH,   FN4R,            FN1,
         LALT,LGUI,               SPC,                TRNS, FN5),

    // This is HHKB original Fn1 layer but removed navigation keys
    [1] = UNIMAP_HHKB(
    PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,     TRNS,
    TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,TRNS,TRNS,TRNS,TRNS,          PENT,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         TRNS,TRNS,               TRNS,                    TRNS,TRNS),

    // Tab navigation
    [2] = UNIMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LNST,  UP,LNED,HOME,PGUP,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT, END,PGDN,          TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         TRNS,TRNS,                  TRNS,                 TRNS,TRNS),

    // Remapped L Shift-X keys
    [3] = UNIMAP_HHKB(
    L3_TIDL,L3(1), L3(2), L3_GRV,L3_PIPE,  L3(5),  L3(6),  L3(7),  L3(8),L3_DBQT,L3_SGQT,  L3_PLUS,L3_USCR,L3_LBKT,L3_RBKT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  L3_LSBK,L3_RSBK,            DEL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,L3_HASH,  L3_DLLR,                L3_CCMT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   L3_QSTM,L3_CPTR,L3_BSLS,          TRNS,           TRNS,
             TRNS,  TRNS,                  L3_USCR,               TRNS,  TRNS),

    // Remapped R Shift-X keys
    [4] = UNIMAP_HHKB(
    L4_TIDL,L4(1), L4(2), L4_GRV,L4_PIPE,  L4(5),  L4(6),  L4(7),  L4(8),L4_DBQT,L4_SGQT,  L4_PLUS,L4_USCR,L4_LBKT,L4_RBKT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  L4_LSBK,L4_RSBK,            DEL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,L4_HASH,  L4_DLLR,                L4_CCMT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   L4_QSTM,L4_CPTR,L4_BSLS,          TRNS,           TRNS,
             TRNS,  TRNS,                  L4_USCR,               TRNS,  TRNS),

    // Swap left (GUI/WIN)<->(ALT/OPTION)
    [5] = UNIMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
         LGUI,LALT,                  TRNS,                 TRNS,TRNS),
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

        case L3_LBRACKET:
            return (record->event.pressed ? 
                    MACRO( I(0), SM(), CM(), T(LBRACKET), RM(), END ) : 
                    MACRO_NONE );

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
    }
}
