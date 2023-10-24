#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _LOWER,
  _RAISE,
  _COMBO,
  _NVIM,
};

enum custom_keycodes {
  // Tmux macro triggers
  T_PANE = SAFE_RANGE,
  T_CLOSE,
  T_PREV,
  T_NEXT,
  T_UP,
  T_DOWN,
  T_LEFT,
  T_RIGHT,
  T_VSPLT,
  T_HSPLT,
  T_ZOOM,
  // Neovim macro triggers
  N_SAVE,
  N_CLOSE,
  N_UP,
  N_DOWN,
  N_LEFT,
  N_RIGHT,
  N_VSPLT,
  N_HSPLT,
  N_VOPEN,
  N_HOPEN,
  KC_SECT
};

// Layer movement
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define COMBO  MO(_COMBO)
#define NVIM   MO(_NVIM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,   KC_4  ,  KC_5   ,                         KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_EQL  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_F   ,   KC_P,    KC_B   ,                         KC_J   ,  KC_L   ,  KC_U   ,  KC_Y   , KC_SCLN , KC_QUOT ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_BSPC ,  KC_A   ,  KC_R   ,  KC_S   ,   KC_T,    KC_G   ,                         KC_M   ,  KC_N   ,  KC_E   ,  KC_I   ,  KC_O   , KC_ENT  ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,   KC_D,    KC_V   , XXXXXXX ,    XXXXXXX ,  KC_K   ,  KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   KC_LCTL , KC_LGUI ,  LOWER  , KC_SPC  ,    KC_SPC  ,  RAISE  , KC_RGUI , KC_RALT
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_NVIM] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , N_VOPEN , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , N_CLOSE , N_SAVE  , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HOPEN , XXXXXXX , N_VSPLT , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HSPLT , C(KC_N) , C(KC_E) , C(KC_I) , C(KC_O) , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_LOWER] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_GRV  , XXXXXXX , XXXXXXX , KC_NUHS , XXXXXXX , XXXXXXX ,                         KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  , KC_F12  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , KC_LEFT , KC_DOWN ,  KC_UP  , KC_RGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ ,KC_TILDE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , KC_CIRC , KC_AMPR , KC_ASTR , KC_PIPE , KC_NUBS , _______ ,
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
     KC_LCBR , KC_LPRN , KC_LBRC , KC_RBRC , KC_RPRN , KC_RCBR ,                        N_HSPLT , C(KC_N) , C(KC_E) , C(KC_I) , C(KC_O) , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ , KC_EXLM ,S(KC_QUOT),S(KC_3) , KC_DLR  , KC_PERC , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ ,  COMBO  , KC_MINS ,    _______ , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_COMBO] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , T_CLOSE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , T_VSPLT , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , T_PREV  , XXXXXXX , T_ZOOM  , T_NEXT  , T_PANE  ,                        T_HSPLT , T_LEFT  , T_DOWN  ,  T_UP   , T_RIGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    _______ , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _COMBO);
}

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
        SEND_STRING(SS_DELAY(100) "00A7" SS_TAP(X_ENTER));
      }
      break;
    case T_PANE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_C));
      }
      break;
    case T_CLOSE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_X));
      }
      break;
    case T_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_P));
      }
      break;
    case T_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_N));
      }
      break;
    case T_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_UP));
      }
      break;
    case T_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_DOWN));
      }
      break;
    case T_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_LEFT));
      }
      break;
    case T_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_RIGHT));
      }
      break;
    case T_VSPLT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_LSFT("5"));
      }
      break;
    case T_HSPLT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_LSFT("'"));
      }
      break;
    case T_ZOOM:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING(SS_TAP(X_Z));
      }
      break;
    case N_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w"));
        SEND_STRING(SS_TAP(X_UP));
      }
      break;
    case N_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w"));
        SEND_STRING(SS_TAP(X_DOWN));
      }
      break;
    case N_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w"));
        SEND_STRING(SS_TAP(X_LEFT));
      }
      break;
    case N_RIGHT:
     if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w"));
        SEND_STRING(SS_TAP(X_RIGHT));
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
        SEND_STRING(":vsp"SS_TAP(X_ENTER));
      }
      break;
    case N_HSPLT:
      if (record->event.pressed) {
        SEND_STRING(":sp"SS_TAP(X_ENTER));
      }
      break;
    case N_CLOSE:
      if (record->event.pressed) {
        SEND_STRING(":q"SS_TAP(X_ENTER));
      }
      break;
    case N_SAVE:
      if (record->event.pressed) {
        SEND_STRING(":w"SS_TAP(X_ENTER));
      }
      break;
  }

  return true;
}
