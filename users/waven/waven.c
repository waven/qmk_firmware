#include "waven.h"

bool process_record_user_waven(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_COM:
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_K) SS_TAP(X_C) SS_UP(X_LCTRL));
        break;
      case M_UNCOM:
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_K) SS_TAP(X_U) SS_UP(X_LCTRL));
        break;
    }
  }
  return true;
};

void td_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count){
    case 1:
      if (state->pressed) {
        layer_on(_CL);
      }
      break;
    case 2:
      if (!state->pressed) {
        register_code (KC_CAPS);
      }
      break;
  }
}

void td_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
  uint8_t layer = biton32(layer_state);
  switch (state->count){
    case 1:
      layer_off(layer);
      break;
    case 2:
      unregister_code (KC_CAPS);
      break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_caps_finished, td_caps_reset),
  [TD_PUH]  = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
  [TD_PDE]  = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END)
};
