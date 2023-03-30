#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _COMBO,
  _NVIM,
  _TEST,
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
  N_HOPEN
};

// Layer movement
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define COMBO  MO(_COMBO)
#define QWERTY TG(_QWERTY)
#define NVIM   MO(_NVIM)
#define TEST   TG(_TEST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_ESC  ,  KC_1   ,  KC_2   ,  KC_3   ,   KC_4  ,  KC_5   ,                         KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_EQL  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_F   ,   KC_P,    KC_B   ,                         KC_J   ,  KC_L   ,  KC_U   ,  KC_Y   , KC_SCLN , KC_QUOT ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_BSPC ,  KC_A   ,  KC_R   ,  KC_S   ,   KC_T,    KC_G   ,                         KC_M   ,  KC_N   ,  KC_E   ,  KC_I   ,  KC_O   , KC_ENT  ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     KC_LSFT ,  KC_Z   ,  KC_X   ,  KC_C   ,   KC_D,    KC_V   ,  NVIM   ,     TEST   ,  KC_K   ,  KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   KC_LCTL , KC_LGUI ,  LOWER  , KC_SPC  ,    KC_SPC  ,  RAISE  , KC_RGUI , KC_RALT
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_TEST] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ , _______ ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ , _______ ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ , KC_TAB  ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    KC_ENT  , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_QWERTY] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ , _______ , _______ , _______ ,                        _______ , _______ , _______ , _______ , _______ , KC_BSPC ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     _______ , _______ , _______ ,  KC_E   ,  KC_R   ,  KC_T   ,                         KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , _______ ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_LSFT , _______ ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,                         KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     KC_LCTL , _______ , _______ , _______ ,  KC_V   ,  KC_B   , _______ ,    _______ ,  KC_N   ,  KC_M   , _______ , _______ , _______ , KC_LALT ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    _______,  _______ , _______ , KC_GRV
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_NVIM] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , N_VOPEN , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , N_CLOSE , N_SAVE  , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HOPEN , XXXXXXX , N_VSPLT , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HSPLT , N_LEFT  , N_DOWN  ,  N_UP   , N_RIGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_LOWER] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  , KC_F12  ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , KC_LEFT , KC_DOWN ,  KC_UP  , KC_RGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ ,KC_TILDE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , KC_CIRC , KC_AMPR , KC_ASTR , KC_PIPE , KC_BSLS , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ , _______ , _______ ,    KC_UNDS ,  COMBO  , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_RAISE] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
      KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,                        XXXXXXX , XXXXXXX , N_VOPEN , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , N_CLOSE , N_SAVE  , XXXXXXX , XXXXXXX , XXXXXXX ,                        N_HOPEN , XXXXXXX , N_VSPLT , XXXXXXX , XXXXXXX , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     KC_LCBR , KC_LPRN , KC_LBRC , KC_RBRC , KC_RPRN , KC_RCBR ,                        N_HSPLT , N_LEFT  , N_DOWN  ,  N_UP   , N_RIGHT , XXXXXXX ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
     _______ , KC_EXLM ,  KC_AT  , S(KC_3) , KC_DLR  , KC_PERC , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
// |---------|---------|---------|---------|---------|---------|---------|  |---------|---------|---------|---------|---------|---------|---------|
                                   _______ , _______ ,  COMBO  , KC_MINS ,    _______ , _______ , _______ , _______
//                               |---------|---------|---------|---------|  |---------|---------|---------|---------|
),
[_COMBO] = LAYOUT(
// |---------|---------|---------|---------|---------|---------|                      |---------|---------|---------|---------|---------|---------|
     XXXXXXX , QWERTY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
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

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
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
