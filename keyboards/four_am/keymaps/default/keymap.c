#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define UPPER 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------------------.         ,-------------------------------------------------------.
 * |  ESC |  F2  |   `  |   1  |   2  |   3  |   4  |   5  |   6  |         |   7  |   8  |   9  |   0  |   -  |   =  |Bspace|Delete|
 * |------+------+------+------+------+------+------+------+------'  ,------|------+------+------+------+------+------+------+------|
 * |  F3  |  F4  | Tab  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  | Home |
 * |------+------+------+------+------+------+------+------|         `------|------+------+------+------+------+------+------+------|
 * |  F5  |  F6  | Caps |   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  |   ;  |   '  | Enter| PgUp |
 * |------+------+------+------+------+------+------+------|                |------+------+------+------+------+------+------+------|
 * |  F7  |  F8  |LShift|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  |RShift|  Up  |PgDown|
 * |------+------+------+------+------+------+------+------|         |------+------+------+------+------+------+------+------+------|
 * |  F9  |  F10 | LCtrl| LGui | LAlt |       Space        |         |        Space       | RAlt | Upper| RCtrl| Left | Down | Right|
 * `-------------------------------------------------------'         `--------------------------------------------------------------'
 *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox( \
  KC_ESC,     KC_F2,     KC_GRAVE,     KC_1,       KC_2,          KC_3,          KC_4,         KC_5,
  KC_F3,      KC_F4,     KC_TAB,       KC_Q,       KC_W,          KC_E,          KC_R,         KC_T,
  KC_F5,      KC_F6,     KC_CAPSLOCK,  KC_A,       KC_S,          KC_D,          KC_F,         KC_G,
  KC_F7,      KC_F8,     KC_LSHIFT,    KC_Z,       KC_X,          KC_C,          KC_V,         KC_B,
  KC_F9,      KC_F10,    KC_LCTRL,     KC_LGUI,    KC_LALT,       KC_SPACE,      KC_NO,        KC_6,

  KC_7,      KC_8,       KC_9,         KC_0,       KC_MINUS,      KC_EQUAL,      KC_BSPACE,    KC_DELETE,
  KC_U,      KC_I,       KC_O,         KC_P,       KC_LBRACKET,   KC_RBRACKET,   KC_BSLASH,    KC_HOME,
  KC_H,      KC_J,       KC_K,         KC_L,       KC_SCOLON,     KC_QUOTE,      KC_ENTER,     KC_PGUP,
  KC_N,      KC_M,       KC_COMMA,     KC_DOT,     KC_SLASH,      KC_RSHIFT,     KC_UP,        KC_PGDOWN,
  KC_Y,      KC_SPACE,   KC_RALT,      MO(UPPER),  KC_RCTRL,      KC_LEFT,       KC_DOWN,      KC_RIGHT
),


/*
* Keymap 1: Upper
* ,--------------------------------------------------------------.         ,-------------------------------------------------------.
* | RESET|      |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------'  ,------|------+------+------+------+------+------+------+------|
* |  KP2 |  KP3 |      |      |      |      |      |      |         |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------|         `------|------+------+------+------+------+------+------+------|
* |  KP3 |  KP4 |      |      |      |      |      |      |                |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------|                |------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |                |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------|         |------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |                    |         |                    |      |      |      |      |      |      |
* `-------------------------------------------------------'         `--------------------------------------------------------------'
*
*/
[UPPER] = LAYOUT_ergodox( \
  RESET,    KC_F2,     KC_GRAVE,     KC_1,       KC_2,          KC_3,          KC_4,         KC_5,
  KC_KP_1,  KC_KP_2,   KC_TAB,       KC_Q,       KC_W,          KC_E,          KC_R,         KC_T,
  KC_KP_3,  KC_KP_4,   KC_CAPSLOCK,  KC_A,       KC_S,          KC_D,          KC_F,         KC_G,
  KC_F7,    KC_F8,     KC_LSHIFT,    KC_Z,       KC_X,          KC_C,          KC_V,         KC_B,
  KC_F9,    KC_F10,    KC_LCTRL,     KC_LALT,    KC_LGUI,       KC_SPACE,      KC_NO,        KC_6,

  KC_7,      KC_8,       KC_9,         KC_0,       KC_MINUS,      KC_EQUAL,      KC_BSPACE,    KC_DELETE,
  KC_U,      KC_I,       KC_O,         KC_P,       KC_LBRACKET,   KC_RBRACKET,   KC_BSLASH,    KC_HOME,
  KC_H,      KC_J,       KC_K,         KC_L,       KC_SCOLON,     KC_QUOTE,      KC_ENTER,     KC_PGUP,
  KC_N,      KC_M,       KC_COMMA,     KC_DOT,     KC_SLASH,      KC_RSHIFT,     KC_UP,        KC_PGDOWN,
  KC_Y,      KC_SPACE,   KC_RALT,      KC_F11,     KC_RCTRL,      KC_LEFT,       KC_DOWN,      KC_RIGHT
),
};

// const uint16_t PROGMEM fn_actions[] = {
//     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
// };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
