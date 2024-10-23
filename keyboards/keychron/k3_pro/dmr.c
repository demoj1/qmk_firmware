#include QMK_KEYBOARD_H
#include "quantum.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_LEFT:
    if (record->event.pressed && get_mods() == MOD_BIT(KC_LCMD)) {
      register_code(KC_HOME);
      return false;
    } else {
      unregister_code(KC_HOME);
      return true;
    }
    break;
  case KC_RIGHT:
    if (record->event.pressed && get_mods() == MOD_BIT(KC_LCMD)) {
      register_code(KC_END);
      return false;
    } else {
      unregister_code(KC_END);
      return true;
    }
    break;
  }

  return process_record_keymap(keycode, record);
}

