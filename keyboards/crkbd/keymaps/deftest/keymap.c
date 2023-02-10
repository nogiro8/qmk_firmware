/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CTD,
};
enum combos { DF_LANG2,
  JK_LANG1,
  FJ_LEAD,
  JJ_ESC,

};

// combo
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [DF_LANG2] = COMBO(df_combo, KC_LNG2),
  [JK_LANG1] = COMBO(jk_combo, KC_LNG1),
  [FJ_LEAD] = COMBO(fj_combo, KC_LEAD),
};
// combo
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    CTD,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LEAD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| 
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                           LGUI_T(KC_LBRC),   LOWER,  KC_SPC,     KC_ENT,  LT(RAISE,KC_MINS),RALT_T(KC_RBRC)
                                      //`--------------------------'  `--------------------------'

  ),
                           //LGUI_T(KC_LBRC),   LT(1,KC_ESC),  KC_SPC,     KC_ENT,  LT(2,KC_MINS),RALT_T(KC_RBRC)

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_LEAD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LEAD, XXXXXXX, XXXXXXX, KC_LEAD, KC_LEAD, KC_LBRC,                     KC_RBRC,KC_PGDN,KC_PGUP,   KC_LEAD, KC_LEAD, KC_LEAD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     KC_ENT,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PLUS,KC_QUOTE, KC_DQT,XXXXXXX, KC_GRV,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_MINS, XXXXXXX, XXXXXXX, KC_TILD,                      KC_UNDS, KC_LBRC, KC_RBRC, KC_RCBR, KC_PIPE, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(3),  KC_LEAD,     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, CTD, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     XXXXXXX,KC_LCBR, KC_RCBR,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

// ctrl + h delete
static bool ctd_pressed = false;
static uint16_t ctd_pressed_time = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	      case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LNG2); // for macOS
          //register_code(KC_MHEN);
          //unregister_code(KC_MHEN);
          unregister_code(KC_LNG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LNG1); // for macOS
          //register_code(KC_HENK);
          //unregister_code(KC_HENK);
          unregister_code(KC_LNG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
  case CTD:
    if (record->event.pressed) {
      ctd_pressed = true;
      ctd_pressed_time = record->event.time;
      register_code(KC_LCTL);
    } else {
      unregister_code(KC_LCTL);
      ctd_pressed = false;
      if (TIMER_DIFF_16(record->event.time, ctd_pressed_time) < TAPPING_TERM) {
        register_code(KC_TAB); // for macOS
        unregister_code(KC_TAB);
      }
    }

    return false;

    case KC_ESC:
              if (record->event.pressed) {
                      register_code(KC_LNG2);
                      unregister_code(KC_LNG2);
                      register_code(KC_ESC);
              } else {
                      unregister_code(KC_ESC);
	      }
              return false;
    default:
	      if (ctd_pressed){
		      switch(keycode){
			      case KC_H:
				      if (record->event.pressed){
					      unregister_code(KC_LCTL);
					      register_code(KC_BSPC);
				      }else{
					      unregister_code(KC_BSPC);
					      if(ctd_pressed){
						      register_code(KC_LCTL);
					      }
				      }
				      return false;
              break;
            case KC_BSLS:
				      if (record->event.pressed){
					      //unregister_code(KC_LCTL);
                register_code(KC_RBRC);
				      }else{
                unregister_code(KC_RBRC);
					      if(ctd_pressed){ register_code(KC_LCTL);}
              }
				      return false;
				      break;

		      }

	      }

  }
  //if (record->event.pressed) {
  //  set_keylog(keycode, record);
  //}
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("()");
      SEND_STRING(SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_G) {
      SEND_STRING("[]");
      SEND_STRING(SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_B) {
      // Anything you can do in a macro.
      //SEND_STRING("QMK is awesome.");
      SEND_STRING("{}");
      SEND_STRING(SS_TAP(X_LEFT));
    }
  }
}

//const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_CTRL, KC_H, KC_BSPC);
////const key_override_t backspace_key_override = ko_make_with_layers_and_negmods(0, MOD_MASK_CTRL, KC_H, ~0, (uint8_t) MOD_MASK_CTRL);
//
//// This globally defines all key overrides to be used
//const key_override_t **key_overrides = (const key_override_t *[]){
//	&backspace_key_override,
//	NULL // Null terminate the array of overrides!
//};
//
