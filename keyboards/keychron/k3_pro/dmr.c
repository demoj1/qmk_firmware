#include QMK_KEYBOARD_H
#include "quantum.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  switch(keycode) {
  case KC_LEFT:
    if (mod_state & MOD_LGUI) {
      if (record->event.pressed) {
        del_mods(MOD_LGUI);
        tap_code(KC_HOME);
        add_mods(MOD_LGUI);
      } else {
        unregister_code(KC_LEFT);
      }

      return false;
    } else {
      return true;
    }
    break;
  case KC_RIGHT:
    if (mod_state & MOD_LGUI) {
      if (record->event.pressed) {
        del_mods(MOD_LGUI);
        tap_code(KC_END);
        add_mods(MOD_LGUI);
      } else {
        unregister_code(KC_RIGHT);
      }

      return false;
    } else {
      return true;
    }
    break;
  }

  return process_record_keymap(keycode, record);
}

