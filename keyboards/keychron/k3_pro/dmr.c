#include QMK_KEYBOARD_H
#include "quantum.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  switch(keycode) {
  case KC_LEFT:
    if (mod_state & MOD_LGUI) {
      del_mods(MOD_LGUI);
      unregister_code(KC_LEFT);
      if (record->event.pressed) register_code(KC_HOME);
      else unregister_code(KC_HOME);
      add_mods(MOD_LGUI);

      return false;
    } else {
      return true;
    }
    break;
  case KC_RIGHT:
    if (mod_state & MOD_LGUI) {
      del_mods(MOD_LGUI);
      unregister_code(KC_RIGHT);
      if (record->event.pressed) register_code(KC_END);
      else unregister_code(KC_END);
      add_mods(MOD_LGUI);

      return false;
    } else {
      return true;
    }
    break;
  }

  return process_record_keymap(keycode, record);
}

