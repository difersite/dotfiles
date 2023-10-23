
// kb: crkbd
// km: neoncornemac

#include QMK_KEYBOARD_H

enum corne_layers { // las capas en este keymap
    _MACOS,
    _WIN10,
    _SYMB,
    _NUMP,
    _TUNE
};

enum custom_keycodes { // dando nombre de keycodes por definir
    SYMB = SAFE_RANGE,
    NUMP,
    HUI,
    HUD,
    OS,
    MAC_A,
    MAC_E,
    MAC_I,
    MAC_O,
    MAC_U,
    MAC_N
};

enum td_keycodes {
    ESCAPE,
//    COMMAND,
//    ALT
};

// definiendo el keycode TD_CAPLOCK
// un pulso: Left Shift
// dos pulsos: Caps Lock
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESCAPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DEL),
//    [ALT] = ACTION_TAP_DANCE_DOUBLE(KC_ALGR, KC_LALT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // Las keycodes en cada capa

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      | ESC DEL|   Q   |   W   |   E   |   R   |   T   |                         |   Y   |   U   |   I   |   O   |   P   | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _MACOS         |-------+-------+-------+-------+-------+---------|
      |SFT ( ) |   A   |   S   |   D   |   F   |   G   |                         |   H   |   J   |   K   |   L   | + * = | SFT � ? | 
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |CTRL TAB|   Z   |   X   |   C   |   V   |   B   |                         |   N   |   M   |  , ;  |  . :  | - _ / |  ' "    |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  CMD  CAPS  | SYMB    | SPACE  |       | SPACE | NUMP ENTER |  ALTGR ALT  |
                               '--------------------------------'       '----------------------------------'
*/

  [_MACOS] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
  TD(ESCAPE),   KC_Q,    KC_W,    MAC_E,    KC_R,    KC_T,                       KC_Y,    MAC_U,   MAC_I,  MAC_O,   KC_P,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _MACOS */    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_LPRN), MAC_A,  KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,  KC_L,  KC_PLUS, RSFT_T(ALGR(KC_SLASH)),
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_TAB), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        MAC_N,   KC_M, KC_COMM,  KC_DOT, KC_MINUS,  LALT_T(KC_QUOTE),
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                  MT(KC_LCMD,KC_CAPS), SYMB, KC_SPC,    KC_SPC, MT(NUMP,KC_ENT), KC_ALGR
                                      //'--------------------------'  '--------------------------------'
  ),

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      | ESC DEL|   Q   |   W   |   E   |   R   |   T   |                         |   Y   |   U   |   I   |   O   |   P   | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _WIN10         |-------+-------+-------+-------+-------+---------|
      |SFT ( ) |   A   |   S   |   D   |   F   |   G   |                         |   H   |   J   |   K   |   L   | - _ / | SFT � ? |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |CTRL TAB|   Z   |   X   |   C   |   V   |   B   |                         |   N   |   M   |  , ;  |  . :  | + * = |  ' "    |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  CMD  CAPS  | SYMB    | SPACE  |       | SPACE | NUMP ENTER |  ALTGR ALT  |
                               '--------------------------------'       '----------------------------------'
*/

  [_WIN10] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
  TD(ESCAPE),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _WIN10 */    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_LPRN), KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_PLUS, RSFT_T(ALGR(KC_SLASH)),
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_TAB), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_MINUS,  LALT_T(KC_QUOTE),
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                  MT(KC_LCMD,KC_CAPS), SYMB, KC_SPC,   KC_SPC, MT(NUMP,KC_ENT), KC_ALGR
                                      //'--------------------------'  '--------------------------------'
  ),

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |        |   !   |   �   |   #   |   $   |  %    |                         |   &   | HOME  |   UP   | END  |       | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _SYMB          |-------+-------+-------+-------+-------+---------|
      |    |   |   {   |   }   |   [   |   ]   |   \   |                         |       |  LEFT |  DOWN | RIGHT |       |         |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |        |       |       |       |       |PSCREEN|                         |       |    �  |   `   |   �   |   ~   |         |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                            |  CMD  CAPS  |          |   SPACE  |       | SPACE | NUMP ENTER | ALTGR ALT |
                            '-----------------------------------'       '--------------------------------'
*/

  [_SYMB] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
   XXXXXXX, KC_EXLM, ALGR(KC_1), KC_HASH, KC_DOLLAR, KC_PERC,                   KC_AMPR, KC_HOME, KC_UP,  KC_END,   XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|     /* _SYMB */    |--------+--------+--------+--------+--------+--------|
LSFT(KC_BSLS), KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS,                     XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCREEN,                   XXXXXXX, ALGR(KC_QUOTE), KC_GRV, ALGR(KC_BSLS), KC_TILDE, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                             MT(KC_LCMD,KC_CAPS), _______, KC_SPC,      KC_SPC, MT(NUMP,KC_ENT), KC_ALGR
                                    //'----------------------------'  '---------------------------------'
  ),

/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |   -    |   +   |   1   |   2   |   3   |   ,   |                         |   >   |  HOME |   UP  |  END  |       | BACKSPC |
      |--------+-------+-------+-------+-------+-------|          _NUMP          |-------+-------+-------+-------+-------+---------|
      |    /   |   *   |   4   |   5   |   6   |   .   |                         |   <   | LEFT  | DOWN  | RIGHT |       |         |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |    ^   |   =   |   7   |   8   |   9   |   0   |                         |       |   (   |   )   |       |       |         |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                               |  CMD  CAPS  | ENTER SYMB| SPACE|       | SPACE |             | ALTGR  ALT |
                               '--------------------------------'       '----------------------------------'
*/

  [_NUMP] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
     KC_MINUS, KC_PPLS,  KC_1,   KC_2,    KC_3,    KC_COMM,                     KC_RABK, KC_HOME,  KC_UP,  KC_END,  XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|    /* _NUMP */     |--------+--------+--------+--------+--------+--------|
     KC_SLASH, KC_ASTR,  KC_4,   KC_5,    KC_6,   KC_DOT,                       KC_LABK, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_CIRC, KC_EQUAL,  KC_7,   KC_8,    KC_9,   KC_0,                         XXXXXXX, LSFT(KC_9), LSFT(KC_0), XXXXXXX, XXXXXXX, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                        MT(KC_LCMD,KC_CAPS), MT(SYMB,KC_ENT), KC_SPC,    KC_SPC, _______, KC_ALGR
                               //'---------------------------------'  '--------------------------'
  ),
  
/*
      .------------------------------------------------.                         .-------------------------------------------------.
      |   F1   |    F2 |    F3 |    F4 |   F5  |  F6   |                         |   F7  |   F8  |   F9  |  F10  |  F11  |   F12   |
      |--------+-------+-------+-------+-------+-------|          _TUNE          |-------+-------+-------+-------+-------+---------|
      |  TOG   |  HUI  | PLAIN |BREATH | RMOOD | RSWIRL|                         |       | MUTE  | VOLD  | VOLU  |       |         |
      |--------+-------+-------+-------+-------+-------|                         |-------+-------+-------+-------+-------+---------|
      |        |  HUD  |       |       |       |       |                         |       |       |       |       |       |         |
      '---------------------------------------------------------|       |----------------------------------------------------------'
                             |  CAPS  CMD  |          |  SPACE  |       | SPACE |       |  ALTGR ALT |
                             '----------------------------------'       '----------------------------'
*/

  [_TUNE] = LAYOUT_split_3x6_3(
//  .-----------------------------------------------------.                    .-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,
//  |--------+--------+--------+--------+--------+--------|     /* _TUNE */    |--------+--------+--------+--------+--------+--------|
       RGB_TOG, HUI,    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,                     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, OS, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HUD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                MT(KC_LCMD,KC_CAPS), _______, KC_SPC,     KC_SPC, _______, KC_ALGR
                                      //'--------------------------'  '--------------------------'
  )
};

// ---------------------- variables -----------------------------

led_t led_usb_state;

uint8_t mod_state;
bool key_registered;

uint32_t master_sleep;
uint32_t slave_sleep;

uint8_t current_wpm = 0;
uint8_t hue_value;
uint8_t sat_value;
uint8_t val_value;
uint8_t mode_value;
uint8_t current_hue;
uint8_t current_val;

char hue_str[4];
char sat_str[4];
char val_str[4];
char mode_str[4];
// char wpm_str[4];

// --------------------------------------------------------------

void keyboard_post_init_user(void) {
    current_hue = rgblight_get_hue();
    current_val = RGBLIGHT_LIMIT_VAL;
}    
        
layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    
        case _TUNE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_WHITE);
            }
            break;    
            
        case _NUMP:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_TEAL);
            }    
            break;            
            
        case _SYMB:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(245, 255, current_val);
            }
            break;
                
        case _WIN10: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;    
            
        case _MACOS: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;      
    }
    
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(20, 255, current_val); // 
    } else { 
        rgblight_sethsv(current_hue, 255, current_val);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_LPRN):
        case LCTL_T(KC_TAB):
        case MT(KC_LCMD,KC_CAPS):   
        case RSFT_T(ALGR(KC_SLASH)):    
        case MT(SYMB,KC_ENT):
        case MT(NUMP,KC_ENT):
        case LALT_T(KC_QUOTE):
            return 125;
            
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_ENABLE // si OLED_ENABLE = yes en rules.mk
#include <stdio.h>

static void master_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0x18, 0x00, 
        0xc0, 0xf0, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xf8, 0xfc, 0xfe, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 
        0x3f, 0x3f, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7c, 0x78, 0x78, 0x38, 0x1c, 0x0f, 0x00, 0x00
    };
    
    oled_write_raw_P(crkbd_logo, 96);
    
    if (current_wpm != 0) { 
        master_sleep = timer_read32(); // se actualiza oled_sleep
    }        
}

static void render_layer(void) { // esta funcion muestra las capas en el OLED y resalta la capa presente
    if (IS_LAYER_ON(_WIN10)) { 
        oled_write_P(PSTR("WIN10"), layer_state_is(_WIN10) && !layer_state_is(_SYMB) && !layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    } else {
        oled_write_P(PSTR("MACOS"), layer_state_is(_MACOS));
    }    
    oled_write_P(PSTR("SYMB\n"), layer_state_is(_SYMB) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("NUMP\n"), layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("TUNE\n"), layer_state_is(_TUNE));
}

static void render_mode(void) {
    mode_str[3] = '\0';
    mode_str[2] = '0' + mode_value % 10;
    mode_str[1] = '0' + ( mode_value /= 10) % 10;
    mode_str[0] = '0' + mode_value / 10;
    oled_write("M ", false);
    oled_write(mode_str, false); // printear valor de WPM
}   

static void render_hsv(void) {
    oled_write("H ", false);
    hue_str[3] = '\0';
    hue_str[2] = '0' + hue_value % 10;
    hue_str[1] = '0' + ( hue_value /= 10) % 10;
    hue_str[0] = '0' + hue_value / 10;
    oled_write(hue_str, false);
    
    oled_write("S ", false);
    sat_str[3] = '\0';
    sat_str[2] = '0' + sat_value % 10;
    sat_str[1] = '0' + ( sat_value /= 10) % 10;
    sat_str[0] = '0' + sat_value / 10;
    oled_write(sat_str, false);
    
    oled_write("V ", false);
    val_str[3] = '\0';
    val_str[2] = '0' + val_value % 10;
    val_str[1] = '0' + ( val_value /= 10) % 10;
    val_str[0] = '0' + val_value / 10;
    oled_write(val_str, false);    
}    

static void slave_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0
    };

    oled_write_P(corne_logo, false);
    
    if (current_wpm != 0) { 
        slave_sleep = timer_read32(); // se actualiza oled_sleep
    }        
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
    return rotation;
    // rotacion de 270 en ambas pantallas OLED (master y slave)
    // de manera que el punto inicial este en un cierto extremo
    // y se siga cierta orientacion
}

// el OLED es de 128x32 pixeles
// cada page es de 8 pixeles a lo largo del lado con 128 px
// por lo que hay 16 pages a lo largo de los 128 px
bool oled_task_user(void) { // funcion en la cual se indica que poner en cada OLED

    current_wpm = get_current_wpm();
    mode_value = rgblight_get_mode();
    hue_value = rgblight_get_hue();
    sat_value = rgblight_get_sat();
    val_value = rgblight_get_val();
    
    /*
    if ( (timer_elapsed32(anim_ghost_sleep) > 120000) && (timer_elapsed32(anim_fishing_sleep) > 120000) && (current_wpm == 0) ) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return;
    }
    */    

    if (timer_elapsed32(master_sleep) > 60000 && timer_elapsed32(slave_sleep) > 60000 && current_wpm == 0) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return false;
    }
    
    if (current_wpm != 0 && !is_oled_on()) {
        oled_on();
    }
    
    led_usb_state = host_keyboard_led_state();      
    
    if (is_keyboard_master()) { // OLED del master
        oled_set_cursor(0,1);
        master_logo();
        oled_set_cursor(0,4);
        oled_write_P(PSTR("crkbd"), false);
        oled_set_cursor(0,6);
        render_layer(); // lo de las capas
        oled_set_cursor(0,11);
        render_mode();
        oled_set_cursor(0,12);
        render_hsv(); // lo del HSV
    } else {
        slave_logo();
        //oled_set_cursor(0,1);
        //slave_render_ghost();
        //oled_set_cursor(0,13);
        // render_wpm();
        //render_mode();
    }

    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    switch (keycode) {
       
        case HUI:
            if (record->event.pressed) {
                current_hue = current_hue + 5;
                if (current_hue > 255) {
                    current_hue = current_hue - 256;
                }    
            } else {
                ;
            }
            return false;    
            
        case HUD:
            if (record->event.pressed) {
                current_hue = current_hue - 5;
                if (current_hue < 0) {
                    current_hue = 256 + current_hue;
                }    
            } else {
                ;
            }
            return false;    
        
        case SYMB:
            if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case MT(SYMB,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;
            
        case MT(NUMP,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case MT(KC_LCMD,KC_CAPS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CAPS);
            } else if (record->event.pressed) { 
                register_code16(KC_LCMD);
            } else {
                unregister_code16(KC_LCMD);
            }
            return false;

        case LCTL_T(KC_TAB):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TAB);
                return false;
            }
            break;   

        case LSFT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_RPRN); // )
                } else {
                    tap_code16(KC_LPRN); // (
                }
            } else if (record->event.pressed) {
                register_code16(KC_LSFT);
            } else {
                unregister_code16(KC_LSFT);
            }
            return false; 

        case RSFT_T(ALGR(KC_SLASH)):
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_QUES); // ?
                } else {
                    tap_code16(ALGR(KC_SLASH)); // �
                }
            } else if (record->event.pressed) {
                register_code16(KC_RSFT);
            } else {
                unregister_code16(KC_RSFT);
            }
            return false;  

        case LALT_T(KC_QUOTE):
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_DQUO); // "
                    tap_code16(KC_SPC);
                } else {
                    tap_code16(KC_QUOTE); // '
                    tap_code16(KC_SPC);
                }
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
            } else {
                unregister_code16(KC_LALT);
            }
            return false;

        case KC_MINUS:
           if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT); // desactivar SHIFT
                    tap_code16(LSFT(KC_MINUS)); // ya que LSFT(KC_MINUS) entrega el simbolo _
                    key_registered = true; 
                    set_mods(mod_state); // volver a activar SHIFT
                    return false; 
                }

                if (mod_state & MOD_MASK_ALT) { // si ALT esta presionado
                    del_mods(MOD_MASK_ALT); // desactivar ALT
                    tap_code16(KC_SLASH); // ya que KC_SLASH entrega el simbolo /
                    key_registered = true; 
                    set_mods(mod_state); // volver a activar ALT
                    return false; 
                }
                
                else {
                    tap_code16(KC_MINUS);
                    key_registered = true;
                    return false;
                }    

            } else { // al liberar el keycode

                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }

        case KC_PLUS:
           if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT); // desactivar SHIFT
                    tap_code16(KC_ASTR); // ya que KC_ASTR entrega el simbolo *
                    key_registered = true; 
                    set_mods(mod_state); // volver a activar SHIFT
                    return false; 
                }

                if (mod_state & MOD_MASK_ALT) { // si ALT esta presionado
                    del_mods(MOD_MASK_ALT); // desactivar ALT
                    tap_code16(KC_EQUAL); // ya que KC_EQUAL entrega el simbolo =
                    key_registered = true; 
                    set_mods(mod_state); // volver a activar ALT
                    return false; 
                }
                
                else {
                    tap_code16(KC_PLUS);
                    key_registered = true;
                    return false;
                }    

            } else { // al liberar el keycode

                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            
        case KC_COMM:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_SCLN); // registrar ;
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode comma
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    unregister_code(KC_SCLN); // dejar de registrar KC_SCLN
                    key_registered = false;
                    return false;
                }
            }
            return true; // lo anterior es solo para cuando esta presionado SHIFT. Si no lo esta, simplemente hacer lo de KC_COMM
            
        case KC_DOT:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(LSFT(KC_SCLN)); // registrar :
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode dot
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    unregister_code16(LSFT(KC_SCLN)); // dejar de registrar LSFT(KC_SCLN)
                    key_registered = false;
                    return false;
                }
            }
            return true; // lo anterior es solo para cuando esta presionado SHIFT. Si no lo esta, simplemente hacer lo de KC_DOT               

        case KC_CIRC:
            if (record->event.pressed) {
                register_code16(KC_CIRC);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_CIRC);  
                unregister_code16(KC_SPC); 
            }
            return false;
            
        case KC_GRV:
            if (record->event.pressed) {
                register_code16(KC_GRV);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_GRV);  
                unregister_code16(KC_SPC); 
            }
            return false;  
            
        case KC_TILDE:
            if (record->event.pressed) {
                register_code16(KC_TILDE);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_TILDE);  
                unregister_code16(KC_SPC); 
            }
            return false;  
            
        case OS: 
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_WIN10)) {
                    layer_on(_WIN10);
                } else {
                    layer_off(_WIN10);
                }
            } else {
                ;
            }
            return false;    
            
        case MAC_A:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_A)); // registrar A
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_A); // registrar a
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_A));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_A);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;   
            
        case MAC_E:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_E)); // registrar E
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_E); // registrar e
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_E));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_E);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;     
            
        case MAC_I:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_I)); // registrar I
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_I); // registrar i
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_I));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_I);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;                       
            
        case MAC_O:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_O)); // registrar O
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_O); // registrar o
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_O));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_O);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;       
            
        case MAC_U:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_U)); // registrar U
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_U); // registrar u
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_U));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_U);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;                                 
        
        case MAC_N:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(LSFT(KC_N));
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(KC_N); // registrar n
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado o bloq mayus activado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_N)); 
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado ni bloq mayus activado
                        tap_code16(KC_N);
                        key_registered = true;
                        return false;
                    }    
                }            
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;                           

    }
    return true;
}
