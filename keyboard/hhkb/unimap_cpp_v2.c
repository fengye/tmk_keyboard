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
};

enum function_id {
    KEY_FN3_SHIFT,
    // L0 overlapped with navi magic
    KEY_I_UP,
    KEY_J_LEFT,
    KEY_K_DOWN,
    KEY_L_RIGHT,
    KEY_P_HOME,
    KEY_SCOLON_END,
    KEY_U_HEAD,
    KEY_O_TAIL,
    KEY_L0_LCBRKT,
    KEY_L0_COLON,

    // L3 overlapped with navi magic
    // L3 2nd row
    KEY_L3_LSBK,
    // L3 3rd row
    KEY_L3_HASH,
    KEY_L3_DLLR,
};


// L0, for remapped X keycodes
// 1st row
#define AC_L0_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define AC_L0_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
// 2nd row
#define AC_L0_LCBK       ACTION_FUNCTION(KEY_L0_LCBRKT)
#define AC_L0_RCBK       ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET)
// 3rd row
#define AC_L0_COLN       ACTION_FUNCTION(KEY_L0_COLON)

// Special arrow keys
#define AC_I_U           ACTION_FUNCTION(KEY_I_UP)
#define AC_J_L           ACTION_FUNCTION(KEY_J_LEFT)
#define AC_K_D           ACTION_FUNCTION(KEY_K_DOWN)
#define AC_L_R           ACTION_FUNCTION(KEY_L_RIGHT)
#define AC_U_H           ACTION_FUNCTION(KEY_U_HEAD)
#define AC_O_T           ACTION_FUNCTION(KEY_O_TAIL)
#define AC_P_HOME        ACTION_FUNCTION(KEY_P_HOME)
#define AC_SCLN_END      ACTION_FUNCTION(KEY_SCOLON_END)


#define AC_FN1           ACTION_LAYER_MOMENTARY(1)
#define AC_FN3           ACTION_FUNCTION(KEY_FN3_SHIFT)
#define AC_FN4           ACTION_LAYER_TAP_TOGGLE(4)

#define AC_TABF          ACTION_LAYER_TAP(2, KC_TAB) // FN2
#define AC_ENT_          ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER)

// L2, mainly for navigation
#define AC_L2_LNST       ACTION_MODS_KEY(MOD_LCTL, KC_A)
#define AC_L2_LNED       ACTION_MODS_KEY(MOD_LCTL, KC_E)
#define AC_LNST          ACTION_MODS_KEY(MOD_LCTL, KC_A)
#define AC_LNED          ACTION_MODS_KEY(MOD_LCTL, KC_E)

// L3, for remapped Shift+X keycodes
#define AC_L3(KEY)       ACTION_MODS_KEY(MOD_LSFT, KC_##KEY)

// 1st row
#define AC_L3_GRAV       ACTION_KEY(KC_GRAVE)
#define AC_L3_DBQT       ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE)
#define AC_L3_SGQT       ACTION_MACRO(L3_QUOTE)
#define AC_L3_PIPE       ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH)
#define AC_L3_MINS       ACTION_MACRO(L3_MINUS)
#define AC_L3_PLUS       ACTION_MODS_KEY(MOD_LSFT, KC_EQUAL)
#define AC_L3_LPRN       ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define AC_L3_RPRN       ACTION_MODS_KEY(MOD_LSFT, KC_0)
#define AC_L3_LBKT       ACTION_MACRO(L3_LBRACKET)
#define AC_L3_RBKT       ACTION_MACRO(L3_RBRACKET)
#define AC_L3_AT         ACTION_MODS_KEY(MOD_LSFT, KC_2)
// 2nd row
#define AC_L3_TIDL       ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE)
#define AC_L3_LSBK       ACTION_FUNCTION(KEY_L3_LSBK)
#define AC_L3_RSBK       ACTION_MODS_KEY(MOD_LSFT, KC_DOT)
// 3rd row
#define AC_L3_HASH       ACTION_FUNCTION(KEY_L3_HASH)
#define AC_L3_DLLR       ACTION_FUNCTION(KEY_L3_DLLR)
#define AC_L3_CCMT       ACTION_MACRO(CPP_COMMENT)
// 4th row
#define AC_L3_USCR       ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)
#define AC_L3_QSTM       ACTION_MODS_KEY(MOD_LSFT, KC_SLASH)
#define AC_L3_CPTR       ACTION_MACRO(CPP_POINTER)
#define AC_L3_BSLS       ACTION_MACRO(L3_BSLASH)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = UNIMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   EQL,   L0_LPRN,L0_RPRN,    GRV,
    TABF,Q,   W,   E,   R,   T,   Y,   U_H, I_U, O_T,   P_HOME,   L0_LCBK,L0_RCBK,    BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J_L, K_D, L_R,   SCLN_END, L0_COLN,            ENT_,
    FN3, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     FN3,          FN1,
         LALT,LGUI,               SPC,                    TRNS, FN4),

    // This is HHKB original Fn1 layer 
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

    // Mostly remapped Shift-X keys
    [3] = UNIMAP_HHKB(
    L3_GRAV,L3(1),  L3_DBQT,L3_SGQT,L3_PIPE,L3(5),  L3(6),  L3(7),  L3(8),  L3_MINS,L3_PLUS,L3_USCR,L3_LBKT,L3_RBKT,L3_TIDL,
    L3_AT,  TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   L3_LSBK,L3_RSBK,        DEL,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   L3_HASH,L3_DLLR,                L3_CCMT,
    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   L3_QSTM,L3_CPTR,L3_BSLS,        TRNS,           TRNS,
         TRNS,  TRNS,                  L3_USCR,               TRNS,  TRNS),

    // Swap left (GUI/WIN)<->(ALT/OPTION)
    [4] = UNIMAP_HHKB(
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
                    MACRO( I(0), SM(), CM(), T(SLSH), T(SLSH), T(SLSH), RM(), END ) :
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
    }
    return MACRO_NONE;
}


static uint8_t isNaviModPressed = 0;
#define NAVI_MOD        MOD_BIT(KC_LCTL)

static void alter_plain_key_for_magic(uint8_t original_keycode, uint8_t altered_keycode, bool is_pressed)
{
    const uint8_t saved_mods = get_mods();
    isNaviModPressed = saved_mods & NAVI_MOD;

    if (is_pressed) {
        if (isNaviModPressed) {
            unregister_mods(NAVI_MOD);
            add_key(altered_keycode);
            send_keyboard_report();
            set_mods(saved_mods);
        }
        else {
            add_key(original_keycode);
            send_keyboard_report();
        }
    }
    else {
        if (isNaviModPressed) {
            del_mods(NAVI_MOD);
            del_key(altered_keycode);
            del_key(original_keycode);
            send_keyboard_report();
            set_mods(saved_mods);
        }
        else {
            del_key(altered_keycode);
            del_key(original_keycode);
            send_keyboard_report();
        }
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id)
    {
        case KEY_FN3_SHIFT:
        {
            if (record->event.pressed) 
            {
                layer_on(3);
                send_keyboard_report();
                // also add shift mod
                add_mods(MOD_BIT(KC_LSHIFT));
                send_keyboard_report();
            }
            else
            {
                del_mods(MOD_BIT(KC_LSHIFT));
                send_keyboard_report();
                layer_off(3);
                send_keyboard_report();
                
            }
            break;
        }

        // simple navi magic
        case KEY_I_UP:
            alter_plain_key_for_magic(KC_I, KC_UP, record->event.pressed);
            break;

        case KEY_K_DOWN:
            alter_plain_key_for_magic(KC_K, KC_DOWN, record->event.pressed);
            break;

        case KEY_J_LEFT:
            alter_plain_key_for_magic(KC_J, KC_LEFT, record->event.pressed);
            break;

        case KEY_L_RIGHT:
            alter_plain_key_for_magic(KC_L, KC_RIGHT, record->event.pressed);
            break;

        // 'P' and 'HOME'
        case KEY_P_HOME:
            alter_plain_key_for_magic(KC_P, KC_HOME, record->event.pressed);
            break;

        // ';' and 'END'
        case KEY_SCOLON_END:
            alter_plain_key_for_magic(KC_SCOLON, KC_END, record->event.pressed);
            break;

        // navi magic 
        case KEY_U_HEAD:
        {
            uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    // ctrl+a
                    register_mods(MOD_BIT(KC_LCTL));
                    add_key(KC_A);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    add_key(KC_U);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    unregister_mods(MOD_BIT(KC_LCTL));
                    del_key(KC_A);
                    del_key(KC_U);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    del_key(KC_A);
                    del_key(KC_U);
                    send_keyboard_report();
                }
            }
        }
        break;

        // navi magic
        case KEY_O_TAIL:
        {
            uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    // ctrl+e
                    register_mods(MOD_BIT(KC_LCTL));
                    add_key(KC_E);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    add_key(KC_O);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    unregister_mods(MOD_BIT(KC_LCTL));
                    del_key(KC_E);
                    del_key(KC_O);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    del_key(KC_E);
                    del_key(KC_O);
                    send_keyboard_report();
                }
            }
        }
        break;

    
        ///////////////////////////////////////////
        // Layer 0
        // '{' and 'PAGE UP'
        // overlapped navi magic and layer 0
        case KEY_L0_LCBRKT:
        {
            const uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    add_key(KC_PGUP);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                    add_key(KC_LBRACKET);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    del_key(KC_PGUP);
                    del_key(KC_LBRACKET);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                    del_key(KC_PGUP);
                    del_key(KC_LBRACKET);
                    send_keyboard_report();
                }
            }
            
        }
        break;
        // ':' and 'PAGE DOWN'
        // overlapped navi magic and layer 3
        case KEY_L0_COLON:
        {
            const uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    add_key(KC_PGDOWN);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                    add_key(KC_SCOLON);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    del_key(KC_PGDOWN);
                    del_key(KC_SCOLON);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                    del_key(KC_PGDOWN);
                    del_key(KC_SCOLON);
                    send_keyboard_report();
                }
            }
            
        }
        break;
        ///////////////////////////////////////////////////////
        // L3 2nd row
        // '<' and 'PAGE UP'
        // overlapped navi magic and layer 3
        case KEY_L3_LSBK:
        {
            const uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    add_key(KC_PGUP);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    add_key(KC_COMMA);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    del_key(KC_PGUP);
                    del_key(KC_COMMA);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    del_key(KC_PGUP);
                    del_key(KC_COMMA);
                    send_keyboard_report();
                }
            }
        }
        break;

        ///////////////////////////////////////////////////////
        // L3 3rd row

        // '#' and 'END'
        // overlapped navi magic and layer 3
        case KEY_L3_HASH:
        {
            const uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    add_key(KC_END);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    add_key(KC_3);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    del_key(KC_END);
                    del_key(KC_3);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    del_key(KC_END);
                    del_key(KC_3);
                    send_keyboard_report();
                }
            }
            
        }
        break;
        // '$' and 'PAGE DOWN'
        // overlapped navi magic and layer 3
        case KEY_L3_DLLR:
        {
            const uint8_t saved_mods = get_mods();
            isNaviModPressed = saved_mods & NAVI_MOD;

            if (record->event.pressed) {
                if (isNaviModPressed) {
                    unregister_mods(NAVI_MOD);
                    add_key(KC_PGDOWN);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    add_key(KC_4);
                    send_keyboard_report();
                }
            }
            else {
                if (isNaviModPressed) {
                    del_mods(NAVI_MOD);
                    del_key(KC_PGDOWN);
                    del_key(KC_4);
                    send_keyboard_report();
                    set_mods(saved_mods);
                }
                else {
                    del_key(KC_PGDOWN);
                    del_key(KC_4);
                    send_keyboard_report();
                }
            }
        }
        break;
    }
}
#undef NAVI_MOD