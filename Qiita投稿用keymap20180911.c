#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"



/*	日本語キーボード用のヘッダファイル */
#include "keymap_jp.h"
//		JP_ZHTGは,半角全角ボタンらしい.しかし,OS側で,キーボードの種類を英語版ではなく,日本語にしなければならないのかもしれない.(英語版では,うまく動いてくれないからな)


#define BASEPlate 0 // default layer
#define JAPBASEPlate 1 // default layer

#define TEMP1Plate 2 // TEMP
#define MOVESPlate 3 // Move Layer
#define HHKBPlate 4	// HHKB Layer
#define ENGPlate 5 // ENG keys
#define TEMP5Plate 6 // TEMP
#define JAPPlate 7		// JAP keys

#define TEMP7Plate 8 // TEMP

#define TEMP9Plate 9 // TEMP
#define MOUSEPlate 10	// MOUSE Layer

#define MACBASE 16	// Mac Layer


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  JAP,
  ENG,
  ZEROReturn
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: WindowsBasic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | LGUI   |   1  |   2  |   3  |   4  |   5  |  Del |           | Bkspc|   6  |   7  |   8  |   9  |   0  |   \|   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  JAP |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |   =+   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~L10   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;: |   '"   |
 * |--------+------+------+------+------+------|      |           | Del  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `~   |  '"  | LAlt |Space |LCtrl/Enter |                       | L1/Space | RGui |LClick|RClick|  ~L3/Enter |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tab  | Esc  |       | PrSc |  App |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | ZEROReturn | | ]}   |        |      |
 *                                 | ~L8  |LAlt  |------|       |------|  Enter | RAlt |
 *                                 | Esc  |      | Enter|       | Tab  |        |      |
 *                                 `--------------------'       `----------------------'
 */


[BASEPlate] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
		GUI_T( M(2) ),	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_DELETE,			/* 7桁	*/
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	JAP,						/* 7桁	*/
		LT(MOUSEPlate, KC_BSPACE),	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			/* 6桁	*/
		KC_LSHIFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_NO,					/* 7桁	*/
		KC_GRAVE,	KC_QUOTE,	KC_LALT,	KC_SPACE,	CTL_T(KC_ENTER),			/* 5桁	*/
																/* 親指部分	*/
																KC_TAB,	KC_ESCAPE,							/* 2桁	*/
																			ZEROReturn,						/* 1桁	*/
																LT(ENGPlate, KC_ESCAPE),	KC_LALT,		/* 2桁	*/
																			KC_ENTER,						/* 1桁	*/



        // right hand
		KC_BSPACE,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSLASH,										/* 7桁	*/
		KC_RBRACKET,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_EQUAL,									/* 7桁	*/
			KC_H,	KC_J,	KC_K,	KC_L,	KC_SCOLON,	KC_QUOTE,											/* 6桁	*/
		KC_DELETE,	KC_N,	KC_M,	KC_COMMA,	KC_DOT,	KC_SLASH,	KC_RSHIFT,								/* 7桁	*/
				LT(MOVESPlate, KC_SPACE),	QK_RGUI,	KC_MS_BTN1,	KC_MS_BTN2,	LT(HHKBPlate, KC_ENTER),	/* 5桁	*/
		/* 親指部分	*/
		KC_PSCREEN,	KC_APPLICATION,		/* 2桁	*/
		KC_RBRACKET,					/* 1桁	*/
		KC_TAB,							/* 1桁	*/
			KC_ENTER,	KC_RALT			/* 2桁	*/

),


/* Keymap 1: temp
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |ZEROReturn|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | GUI  |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | TO0  |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// temp
[TEMP1Plate] = LAYOUT_ergodox(

       // left hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	_______,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	GUI_T(KC_NO),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	
																KC_NO,	TO(BASEPlate),	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	

       // right hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	ZEROReturn,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
				KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		RESET,	KC_NO,	
		KC_NO,	
		KC_NO,	
			KC_NO,	KC_NO	



),


/* Keymap 2: Move Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 *|ZEROReturn|      |      |      |      |      |      |           |      | PgUp | Tab  | Home | End  | SysRq|  Bkspc |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  '"  |  {   |  -_  |  =+  |  `~  |------|           |------|  ←  |  ↓  |  ↑  |  →  |  -_  |  Del   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LShift |  "   |  }   |  _   |  +   |  ~   |      |           |      | PgDn |  |   |  [{  |  ]}  |  \|  | RShift |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Ins  |Pause | Caps |ScrLk |LCtrl |                                       | LT1  | RGui |      |      |  \|  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Esc | Reset|       | M(2) | TO(5)|		←M(2)は,日本語入力のオン／オフ(Alt+`)
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | LAlt | LT5  |------|       |------|Enter | Esc  |
 *                                 |      |      | TO(1)|       | TO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
// Moves
[MOVESPlate] = LAYOUT_ergodox(
       // left hand
		KC_ESCAPE,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,	
		ZEROReturn,	 KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
//		KC_NO,	KC_EXCLAIM,	 KC_AT,	KC_HASH,	KC_DOLLAR,	KC_PERCENT,	KC_NO,		// ←お試し2列目20180907
//		JP_ZHTG,	JP_YEN,	 JP_CIRC,	JP_AT,	JP_COLN,	JP_BSLS,	JP_AMPR,		// ←お試し2列目20180907
//		KC_NO,	 KC_LOCKING_CAPS,	KC_LOCKING_NUM,	KC_LOCKING_SCROLL,	KC_NO,	KC_NO,	KC_NO,		// ←お試し2列目
		KC_NO,	KC_QUOTE,	KC_LEFT_CURLY_BRACE,	KC_MINUS,	KC_EQUAL,	KC_GRAVE,	
//		KC_KP_7,	KC_CAPSLOCK,	KC_NUMLOCK,	KC_SCROLLLOCK,	KC_NO,	KC_NO,		// ←お試し3列目
		KC_LSHIFT,	KC_DOUBLE_QUOTE,	KC_RIGHT_CURLY_BRACE,	KC_UNDERSCORE,	KC_PLUS,	KC_TILDE,	KC_NO,	
		KC_INSERT,	KC_PAUSE,	KC_CAPSLOCK,	KC_SLCK,	CTL_T(KC_NO),	
																KC_ESCAPE,	RESET,	
																			KC_NO,	
																KC_LALT,	KC_NO,	
																			TO(TEMP1Plate),	


       // right hand
		KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_NO,	
		KC_NO,	KC_PGUP,	KC_TAB,	KC_HOME,	KC_END,	KC_PSCREEN,	KC_BSPACE,	
			KC_LEFT,	KC_DOWN,	KC_UP,	KC_RIGHT,	KC_MINUS,	KC_DELETE,	
		KC_NO,	KC_PGDOWN,	KC_PIPE,	KC_LBRACKET,	KC_RBRACKET,	KC_BSLASH,	KC_RSHIFT,	
				KC_NO,	QK_RGUI,	KC_NO,	KC_NO,	KC_BSLASH,	
		M(2),	TO(TEMP5Plate),	
		KC_NO,	
		TO(HHKBPlate),	
			KC_ENTER,	KC_ESCAPE	


),


/* Keymap 3: hhkb Move
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgUp |  ↑  | Home |ZEROReturn|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |  ←  |  ↓  |  →  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgDn |      | End  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  JAP |      |      |      |  NG  |                                       |      |      |      |      |予約済み|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | TO 1 |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | TO5  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// hhkb Move
[HHKBPlate] = LAYOUT_ergodox(

       // left hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		JAP,	KC_NO,	KC_NO,	KC_NO,	ENG,	
																KC_NO,	TO(BASEPlate),	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	


       // right hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_PGUP,	KC_UP,	KC_HOME,	ZEROReturn,	
			KC_NO,	KC_NO,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_PGDOWN,	KC_NO,	KC_END,	KC_NO,	
				KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		RESET,	KC_NO,	
		KC_NO,	
		KC_NO,	
			KC_NO,	KC_NO	


),


/* Keymap 4: ENG keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F13 |  F14 |  F15 |  F16 |  F17 | F18  |           | LGUI |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Enter |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |ZEROReturn|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shift |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  JAP |       | RESET| TO(1)|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | M(2) |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// ENGPlate
[ENGPlate] = LAYOUT_ergodox(
       // left hand
		_______,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,	KC_F18,	
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	_______,	
		KC_ENTER,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	
		SFT_T(_______),	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,	_______,	
		_______,	_______,	_______,	_______,	_______,	
														_______,	JAP,	
																		_______,	
														_______,	_______,	
																		_______,	



    // right hand
		QK_RGUI,	_______,	_______,	_______,	_______,	_______,	_______,	
		_______,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	
			KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	ZEROReturn,	
		_______,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	RSFT_T(_______),	
			_______,	_______,	_______,	_______,	_______,	
		RESET,	TO(TEMP1Plate),	
		_______,	
		_______,	
			_______,	M(2)	

),


/* Keymap 5: temp
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |RClick|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |ZEROReturn|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | TO0  |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// temp
[TEMP5Plate] = LAYOUT_ergodox(

       // left hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_A,	_______,	KC_NO,	KC_MS_BTN2,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	
																KC_NO,	TO(BASEPlate),	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	

       // right hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	ZEROReturn,	
				KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		RESET,	KC_NO,	
		KC_NO,	
		KC_NO,	
			KC_NO,	KC_NO	

),


/* Keymap 6: Jap keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 *|ZEROReturn|     |      |      |      |      | LGUI |           |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Enter |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |  TO(9) |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shift |  !   |  "   |  #   |  $   |  %   |      |           |      |  &   |  '   |  (   |  )   |      | RESET  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TO(1)|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Reset|       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | M(2) |
 *                                 |      |      |      |       | ENG  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Jap keys
[JAPPlate] = LAYOUT_ergodox(
       // left hand
		ZEROReturn,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	QK_LGUI,	
		XXXXXXX,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	XXXXXXX,	
		KC_ENTER,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	
		SFT_T(XXXXXXX),	JP_EXLM,	JP_DQT,	JP_HASH,	JP_DLR,	JP_PERC,	XXXXXXX,	
		TO(TEMP1Plate),	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	
														TO(BASEPlate),	RESET,	
																		XXXXXXX,	
														XXXXXXX,	XXXXXXX,	
																		XXXXXXX,	



    // right hand
		KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,	KC_F12,	
		XXXXXXX,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	
			KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	XXXXXXX,	
		XXXXXXX,	JP_AMPR,	JP_QUOT,	JP_LPRN,	JP_RPRN,	XXXXXXX,	RESET,	
			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	TO(TEMP9Plate),	
		RESET,	XXXXXXX,	
		ENG,	
		XXXXXXX,	
			XXXXXXX,	M(2)	


),


/* Keymap 7: temp
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      | LGUI |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |ZEROReturn|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | TO0  |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// temp
[TEMP7Plate] = LAYOUT_ergodox(

       // left hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	GUI_T(KC_NO),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
																KC_NO,	TO(BASEPlate),	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	

       // right hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_LGUI,	KC_NO,	KC_NO,	
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
				KC_NO,	KC_NO,	KC_NO,	KC_NO,	ZEROReturn,	
		RESET,	KC_NO,	
		KC_NO,	
		KC_NO,	
			KC_NO,	KC_NO	


),


/* Keymap 1: WindowsBasic JapLayer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | LGUI   |   1  |   2  |   3  |   4  |   5  | Bkspc|           |  Del |   6  |   7  |   8  |   9  |   0  |   \|   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ENG |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |   =+   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~L10   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;: |   '"   |
 * |--------+------+------+------+------+------|      |           | Del  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `~   |  '"  | Space| Enter| LCtrl|                             | L1/Space | RGui |LClick|RClick|  ~L3/Enter |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tab  | Esc  |       | LT(5) | RESET|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | ZEROReturn | | TO(9)|        |      |
 *                                 | ~L8  |LAlt  |------|       |------|  Enter | RAlt |
 *                                 | Esc  |      | Enter|       | Tab  |        |      |
 *                                 `--------------------'       `----------------------'
 */


[JAPBASEPlate] = LAYOUT_ergodox(  // layer 0 : default

        // left hand
		_______,	_______,	_______,	_______,	_______,	_______,	KC_BSPACE,	
		_______,	_______,	_______,	_______,	_______,	_______,	ENG,	
		_______,	_______,	_______,	_______,	_______,	_______,	
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	
		_______,	_______,	KC_SPACE,	KC_ENTER,	KC_LCTRL,	
																// 親指部分
																_______,	_______,	
																			ZEROReturn,	
																LT(JAPPlate, KC_ESCAPE),	_______,	
																			_______,	



        // right hand
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	
			_______,	_______,	_______,	_______,	_______,	_______,	
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	
				_______,	_______,	_______,	_______,	LT(HHKBPlate, M(2)),	
		// 親指部分
		LT(TEMP5Plate, KC_NO),	RESET,	
		TO(TEMP9Plate),	
		_______,	
			_______,	_______	


),


/* Keymap 9: temp
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |ZEROReturn|    |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | RGUI |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | TO0  |       | RESET|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// temp
[TEMP9Plate] = LAYOUT_ergodox(

       // left hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		ZEROReturn,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	GUI_T(KC_NO),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
																KC_NO,	TO(BASEPlate),	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	

       // right hand
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	KC_NO,	
			KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	_______,	KC_NO,	KC_NO,	
				KC_NO,	KC_NO,	KC_RGUI,	KC_NO,	KC_NO,	
		KC_NO,	RESET,	
		KC_NO,	
		KC_NO,	
			KC_NO,	KC_NO	


),


/* Keymap 10: MOUSE Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |  Fject |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  `~     | Home |      | End  | PgUp | Tab  |  +   |           |      | VolUp| Lclk |Middle| Rclk |      |  Play  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | 予約済み| Del  |      |      | PgDn |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |  Stop  |
 * |---------+------+------+------+------+------|ZERO  |           |      |------+------+------+------+------+--------|
 * |  LShift | TO 1 | TO 2 | TO 4 | TO 5 | TO 6 |Return|           |      | VolDn| Prev | Next |      | Mute | RShift |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      | LCtrl|                                       |      | RGUI |      | Wleft|WRight|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TO 0 | Reset|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      | WWW  | WWW  |
 *                               |      |予約済み|------|       |------| Fwd  | Back |
 *                                 |      |      |      |      |wwwHome|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUSEPlate] = LAYOUT_ergodox(
       // left hand
		KC_ESCAPE,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,	
		KC_GRAVE,	KC_HOME,	KC_NO,	KC_END,	KC_PGUP,	KC_TAB,	KC_PLUS,	
		KC_NO,	KC_DELETE,	KC_NO,	KC_NO,	KC_PGDOWN,	KC_NO,	
		KC_LSHIFT,	TO(MOVESPlate),	TO(ENGPlate),	TO(HHKBPlate),	TO(JAPBASEPlate),	TO(MOUSEPlate),	ZEROReturn,	
		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_LCTL,	
																TO(BASEPlate),	RESET,	
																		KC_NO,	
																KC_NO,	KC_NO,	
																		KC_NO,	


       // right hand
		KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_MEDIA_EJECT,	
		KC_NO,	KC_AUDIO_VOL_UP,	KC_MS_BTN1,	KC_MS_BTN3,	KC_MS_BTN2,	KC_NO,	KC_MEDIA_PLAY_PAUSE,	
			KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,	KC_NO,	KC_MEDIA_STOP,	
		KC_NO,	KC_AUDIO_VOL_DOWN,	KC_MEDIA_PREV_TRACK,	KC_MEDIA_NEXT_TRACK,	KC_NO,	KC_AUDIO_MUTE,	KC_RSHIFT,	
				KC_NO,	RGUI_T(KC_NO),	KC_NO,	KC_MS_WH_LEFT,	KC_MS_WH_RIGHT,	
		KC_NO,	KC_NO,	
		KC_NO,	
		KC_WWW_HOME,	
			KC_WWW_FORWARD,	KC_WWW_BACK


),





};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MOVESPlate)                // FN1 - Momentary Layer 1 (Symbols)
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;



	case 2:
		if (record->event.pressed) { // 日本語入力のオン／オフ（英語配列）
			return MACRO( D(LALT), T(GRAVE), U(LALT), END);
		}
		break;



  }
  return MACRO_NONE;
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;


	case JAP:
		if (record->event.pressed) {
			// キー押下時に動く
			default_layer_set(JAPBASEPlate);
			layer_move(JAPBASEPlate);
		}
		else {
			// キー押上時に動く
		}
		return false;
		break;


	case ENG:
		if (record->event.pressed) {
			// キー押下時に動く
	default_layer_set(BASEPlate);
	layer_move(BASEPlate);
		}
		else {
			// キー押上時に動く
		}
		return false;
		break;


	case ZEROReturn:
		if (record->event.pressed) {
			// キー押下時に動く
			layer_clear();
			default_layer_set(0);
		}
		else {
			// キー押上時に動く
		}
		return false;
		break;


  }



  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
#endif
        #ifdef RGBLIGHT_ENABLE
		rgblight_enable_noeeprom();	// 有効20180901
		#endif


	// レイヤーを0に戻す.
	//		https://github.com/qmk/qmk_firmware/blob/master/tmk_core/common/action_layer.c
//	layer_clear();
//			clear_keyboard();
//			clear_mods();
//	default_layer_set(0);
//	layer_move(BASEPlate);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();


  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
//        ergodox_right_led_1_on();	// 赤
		DDRB |=  (1<<5);
		PORTB |=  (1<<5);


        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
			//	ここはどのようにして処理を通すようにすればいい？
        #endif
#ifdef RGBLIGHT_ENABLE
			rgblight_sethsv_at (  0, 255, 50, 0);
			rgblight_sethsv_at (  0, 255, 110, 1);
			rgblight_sethsv_coral_at ( 2 );
			rgblight_sethsv_at (  0, 255, 140, 3);
			rgblight_sethsv_at (  0, 255, 200, 4);
			rgblight_sethsv_coral_at ( 5 );
			rgblight_sethsv_at (  0, 255, 200, 6);
			rgblight_sethsv_at (  0, 255, 100, 7);
			rgblight_sethsv_at (  0, 255, 255, 8);
			rgblight_sethsv_coral_at ( 9 );
			rgblight_sethsv_at (  0, 255, 200, 10);
			rgblight_sethsv_at (  0, 255, 140, 11);
			rgblight_sethsv_at (  0, 255, 130, 12);
			rgblight_sethsv_at (  0, 255, 50, 13);
			rgblight_sethsv_coral_at ( 14 );

#endif
        break;
      case 2:
        ergodox_right_led_2_on();	// 緑
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
#ifdef RGBLIGHT_ENABLE
			rgblight_sethsv_noeeprom_green();

#endif
        break;
      case 3:
        ergodox_right_led_3_on();	// 青
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
#ifdef RGBLIGHT_ENABLE
			rgblight_sethsv_blue_at( 0 );
			rgblight_sethsv_blue_at( 1 );
			rgblight_sethsv_blue_at( 2 );
			rgblight_sethsv_blue_at( 3 );
			rgblight_sethsv_blue_at( 4 );
			rgblight_sethsv_blue_at( 5 );
			rgblight_sethsv_blue_at( 6 );
			rgblight_sethsv_blue_at( 7 );
			rgblight_sethsv_blue_at( 8 );
			rgblight_sethsv_blue_at( 9 );
			rgblight_sethsv_blue_at( 10 );
			rgblight_sethsv_blue_at( 11 );
			rgblight_sethsv_blue_at( 12 );
			rgblight_sethsv_blue_at( 13 );
			rgblight_sethsv_blue_at( 14 );

#endif
        break;
      case 4:
        ergodox_right_led_1_on();	// 赤
        ergodox_right_led_2_on();	// 緑
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif

#ifdef RGBLIGHT_ENABLE
		rgblight_sethsv_red_at(   0 );
		rgblight_sethsv_green_at( 1 );
		rgblight_sethsv_red_at(   2 );
		rgblight_sethsv_green_at( 3 );
		rgblight_sethsv_red_at(   4 );
		rgblight_sethsv_green_at( 5 );
		rgblight_sethsv_red_at(   6 );
		rgblight_sethsv_green_at( 7 );
		rgblight_sethsv_red_at(   8 );
		rgblight_sethsv_green_at( 9 );
		rgblight_sethsv_red_at(   10 );
		rgblight_sethsv_green_at( 11 );
		rgblight_sethsv_red_at(   12 );
		rgblight_sethsv_green_at( 13 );
		rgblight_sethsv_red_at(   14 );
#endif

        break;
      case 5:
        ergodox_right_led_1_on();	// 赤
        ergodox_right_led_3_on();	// 青
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif

#ifdef RGBLIGHT_ENABLE
		rgblight_sethsv_red_at(   0 );
		rgblight_sethsv_blue_at(  1 );
		rgblight_sethsv_red_at(   2 );
		rgblight_sethsv_blue_at(  3 );
		rgblight_sethsv_red_at(   4 );
		rgblight_sethsv_blue_at(  5 );
		rgblight_sethsv_red_at(   6 );
		rgblight_sethsv_blue_at(  7 );
		rgblight_sethsv_red_at(   8 );
		rgblight_sethsv_blue_at(  9 );
		rgblight_sethsv_red_at(   10 );
		rgblight_sethsv_blue_at(  11 );
		rgblight_sethsv_red_at(   12 );
		rgblight_sethsv_blue_at(  13 );
		rgblight_sethsv_red_at(   14 );
#endif

        break;
      case 6:
        ergodox_right_led_2_on();	// 緑
        ergodox_right_led_3_on();	// 青
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif

#ifdef RGBLIGHT_ENABLE
		rgblight_sethsv_green_at( 0 );
		rgblight_sethsv_blue_at(  1 );
		rgblight_sethsv_green_at( 2 );
		rgblight_sethsv_blue_at(  3 );
		rgblight_sethsv_green_at( 4 );
		rgblight_sethsv_blue_at(  5 );
		rgblight_sethsv_green_at( 6 );
		rgblight_sethsv_blue_at(  7 );
		rgblight_sethsv_green_at( 8 );
		rgblight_sethsv_blue_at(  9 );
		rgblight_sethsv_green_at( 10 );
		rgblight_sethsv_blue_at(  11 );
		rgblight_sethsv_green_at( 12 );
		rgblight_sethsv_blue_at(  13 );
		rgblight_sethsv_green_at( 14 );
#endif

        break;
      case 7:
        ergodox_right_led_1_on();	// 赤
        ergodox_right_led_2_on();	// 緑
        ergodox_right_led_3_on();	// 青
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif

#ifdef RGBLIGHT_ENABLE
		rgblight_sethsv_red_at( 0 );
		rgblight_sethsv_green_at(  1 );
		rgblight_sethsv_blue_at( 2 );
		rgblight_sethsv_red_at(  3 );
		rgblight_sethsv_green_at( 4 );
		rgblight_sethsv_blue_at(  5 );
		rgblight_sethsv_red_at( 6 );
		rgblight_sethsv_green_at(  7 );
		rgblight_sethsv_blue_at( 8 );
		rgblight_sethsv_red_at(  9 );
		rgblight_sethsv_green_at( 10 );
		rgblight_sethsv_blue_at(  11 );
		rgblight_sethsv_red_at( 12 );
		rgblight_sethsv_green_at(  13 );
		rgblight_sethsv_blue_at( 14 );
#endif

        break;
      default:
        break;
    }


  return state;
};
