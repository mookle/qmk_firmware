#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _COMBO,
};

enum custom_keycodes {
  // Tmux macro triggers
  T_PANE = SAFE_RANGE,
  T_CLOSE,
  T_PREV,
  T_NEXT,
  T_VSPLT,
  T_HSPLT,
  T_ZOOM,
  // Neovim macro triggers
  N_SAVE,
  N_CLOSE,
  N_VSPLT,
  N_HSPLT,
  N_VOPEN,
  N_HOPEN,
  KC_SECT
};

// Layer movement
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define COMBO   MO(_COMBO)
#define COLEMAK DF(_COLEMAK)
#define QWERTY  DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,   KC_4  ,  KC_5   ,                         KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_EQL  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_F   ,   KC_P,    KC_B   ,                         KC_J   ,  KC_L   ,  KC_U   ,  KC_Y   , KC_SCLN , KC_QUOT ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_BSPC ,  KC_A   ,  KC_R   ,  KC_S   ,   KC_T,    KC_G   ,                         KC_M   ,  KC_N   ,  KC_E   ,  KC_I   ,  KC_O   , KC_ENT  ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,   KC_D,    KC_V   , KC_VOLD ,    KC_VOLU ,  KC_K   ,  KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   KC_LCTL , KC_LGUI ,  LOWER  , KC_SPC  ,    KC_SPC  ,  RAISE  , KC_RGUI , KC_RALT
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_QWERTY] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,   KC_4  ,  KC_5   ,                         KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_EQL  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,   KC_R,    KC_T   ,                         KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , KC_QUOT ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_BSPC ,  KC_A   ,  KC_S   ,  KC_D   ,   KC_F,    KC_G   ,                         KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , KC_ENT  ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,   KC_B,    KC_V   , _______ ,    _______ ,  KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   KC_LCTL , KC_LGUI ,  LOWER  , KC_SPC  ,    KC_SPC  ,  RAISE  , KC_RGUI , KC_RALT
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_LOWER] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_GRV  , XXXXXXX , XXXXXXX , KC_NUHS , XXXXXXX , XXXXXXX ,                         KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  , KC_F12  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , QWERTY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , KC_LEFT , KC_DOWN ,  KC_UP  , KC_RGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ ,KC_TILDE , XXXXXXX , COLEMAK , XXXXXXX , XXXXXXX , KC_MPRV ,    KC_MNXT , KC_CIRC , KC_AMPR , KC_ASTR , KC_PIPE , KC_NUBS , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    KC_UNDS ,  COMBO  , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_RAISE] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
      KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,                        XXXXXXX , XXXXXXX , N_VOPEN , XXXXXXX , XXXXXXX , KC_SECT ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , N_CLOSE , N_SAVE  , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HOPEN , XXXXXXX , N_VSPLT , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_LCBR , KC_LPRN , KC_LBRC , KC_RBRC , KC_RPRN , KC_RCBR ,                        N_HSPLT , C(KC_H) , C(KC_J) , C(KC_K) , C(KC_L) , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ , KC_EXLM ,S(KC_QUOT),S(KC_3) , KC_DLR  , KC_PERC , KC_MPLY ,    KC_MSTP , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ ,  COMBO  , KC_MINS ,    _______ , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_COMBO] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , T_CLOSE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , T_PREV  , T_VSPLT , T_NEXT  , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , T_PANE  ,                        T_HSPLT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     XXXXXXX , T_ZOOM  , XXXXXXX , XXXXXXX , XXXXXXX , KC_X , _______ ,    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    _______ , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
)
};

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
/*  return update_tri_layer_state(state, _LOWER, _RAISE, _COMBO);*/
/*}*/

const key_override_t at_dquote_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, S(KC_QUOT));
const key_override_t dquote_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, S(KC_2));

const key_override_t **key_overrides = (const key_override_t *[]){
    &at_dquote_override,
    &dquote_at_override,
    NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SECT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL));
        SEND_STRING(SS_TAP(X_U));
        SEND_STRING(SS_UP(X_LSFT) SS_UP(X_LCTL));
        SEND_STRING(SS_DELAY(150) "00A7" SS_TAP(X_ENTER));
        // If not for the SS_DELAY (because kitty unicode_input) then this
        // one-liner would do the job:
        //send_unicode_string("§");
      }
      break;
    case T_PANE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") "c");
      }
      break;
    case T_CLOSE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") "xy");
      }
      break;
    case T_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") "p");
      }
      break;
    case T_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") "n");
      }
      break;
    case T_VSPLT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") ":splitw -h" SS_TAP(X_ENTER));
      }
      break;
    case T_HSPLT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") ":splitw" SS_TAP(X_ENTER));
      }
      break;
    case T_ZOOM:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") "z");
      }
      break;
    case N_HOPEN:
     if (record->event.pressed) {
        SEND_STRING(SS_LCTL("x"));
      }
      break;
    case N_VOPEN:
     if (record->event.pressed) {
        SEND_STRING(SS_LCTL("v"));
      }
      break;
    case N_VSPLT:
      if (record->event.pressed) {
        SEND_STRING(":vsp" SS_TAP(X_ENTER));
      }
      break;
    case N_HSPLT:
      if (record->event.pressed) {
        SEND_STRING(":sp" SS_TAP(X_ENTER));
      }
      break;
    case N_CLOSE:
      if (record->event.pressed) {
        SEND_STRING(":q" SS_TAP(X_ENTER));
      }
      break;
    case N_SAVE:
      if (record->event.pressed) {
        SEND_STRING(":w" SS_TAP(X_ENTER));
      }
      break;
  }

  return true;
}
