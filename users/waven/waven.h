#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

#define _DL 0
#define _FL 1
#define _CL 2

// Helpful defines
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define SFT_TAB LSFT(KC_TAB)

//Macro declarations
enum custom_keycodes {
  M_COM = SAFE_RANGE,
  M_UNCOM,
  M_REGO,
  M_REGC,
  NEW_SAFE_RANGE     //use NEW_SAFE_RANGE for keymap specific codes
};

//Tap Dance Declarations
enum {
  TD_CAPS,
  TD_PUH,
  TD_PDE
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt);

bool process_record_user_waven(uint16_t keycode, keyrecord_t *record);

void td_caps_finished(qk_tap_dance_state_t *state, void *user_data);
void td_caps_reset(qk_tap_dance_state_t *state, void *user_data);
