/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega with RAMPS v1.4 for Anycubic
 */

#define BOARD_INFO_NAME "Anycubic RAMPS 1.4"

//
// Servos
//
#if MB(TRIGORILLA_14_11)
  #define SERVO0_PIN        5
  #define SERVO1_PIN        4
  #define SERVO2_PIN       11
  #define SERVO3_PIN        6
#endif

#define LARGE_FLASH        true

// Misc PINs
#define BUZZER 			   31
#define SDPOWER_PIN        -1
#define SDSS               53
#define LED_PIN            13
#define Z_MIN_PROBE_PIN     2
#define FIL_RUNOUT_PIN	   33

#ifdef OutageTest
	#define OUTAGETEST_PIN  79
	#define OUTAGECON_PIN   58
#endif

// Steppers
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Y2_STEP_PIN        36
#define Y2_DIR_PIN         34
#define Y2_ENABLE_PIN      30

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

// EndStops
#define X_MIN_PIN           3
#define Y_MIN_PIN          42
#define Z_MIN_PIN          18

#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          43

// Fans
#define FAN_PIN             9
#define FAN2_PIN           44
#define ORIG_E0_AUTO_FAN_PIN 44
#define CONTROLLER_FAN_PIN  7

// Heaters
#define HEATER_0_PIN       10
#define HEATER_1_PIN       45
#define HEATER_BED_PIN      8

// Temperatursensoren
#define TEMP_0_PIN         13
#define TEMP_1_PIN         15
#define TEMP_2_PIN         12
#define TEMP_BED_PIN       14

//
// Augmentation for auto-assigning RAMPS plugs
//
#if DISABLED(IS_RAMPS_EEB) && DISABLED(IS_RAMPS_EEF) && DISABLED(IS_RAMPS_EFB) && DISABLED(IS_RAMPS_EFF) && DISABLED(IS_RAMPS_SF) && !PIN_EXISTS(MOSFET_D)
  #if HOTENDS > 1
    #if TEMP_SENSOR_BED
      #define IS_RAMPS_EEB
    #else
      #define IS_RAMPS_EEF
    #endif
  #elif TEMP_SENSOR_BED
    #define IS_RAMPS_EFB
  #else
    #define IS_RAMPS_EFF
  #endif
#endif

//
// Heaters / Fans
//
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN     -1
#endif
#ifndef RAMPS_D8_PIN
  #define RAMPS_D8_PIN      8
#endif
#ifndef RAMPS_D9_PIN
  #define RAMPS_D9_PIN      9
#endif
#ifndef RAMPS_D10_PIN
  #define RAMPS_D10_PIN    10
#endif

#define HEATER_0_PIN       RAMPS_D10_PIN

#if ENABLED(IS_RAMPS_EFB)                      // Hotend, Fan, Bed
  #define HEATER_BED_PIN   45 // RAMPS_D8_PIN
#elif ENABLED(IS_RAMPS_EEF)                    // Hotend, Hotend, Fan
  #define HEATER_1_PIN     RAMPS_D9_PIN
#elif ENABLED(IS_RAMPS_EEB)                    // Hotend, Hotend, Bed
  #define HEATER_1_PIN     RAMPS_D9_PIN
  #define HEATER_BED_PIN   RAMPS_D8_PIN
#elif ENABLED(IS_RAMPS_EFF)                    // Hotend, Fan, Fan
  #define FAN1_PIN         RAMPS_D8_PIN
#elif DISABLED(IS_RAMPS_SF)                    // Not Spindle, Fan (i.e., "EFBF" or "EFBE")
  #define HEATER_BED_PIN   RAMPS_D8_PIN
  #if HOTENDS == 1
    #define FAN1_PIN       MOSFET_D_PIN
  #else
    #define HEATER_1_PIN   MOSFET_D_PIN
  #endif
#endif

// Servos
#if TRIGORILLA_VERSION == 0 // Default Trigorilla
  #ifdef NUM_SERVOS
  	#define SERVO0_PIN      11

  	#if NUM_SERVOS > 1
  		#define SERVO1_PIN    6
  	#endif

  	#if NUM_SERVOS > 2
  		#define SERVO2_PIN    5
  	#endif

  	#if NUM_SERVOS > 3
  		#define SERVO3_PIN    4
  	#endif
  #endif
#else // Trigorilla 1.1
  #ifdef NUM_SERVOS
    #define SERVO0_PIN 5

    #if NUM_SERVOS > 1
      #define SERVO1_PIN 4
    #endif

    #if NUM_SERVOS > 2
      #define SERVO2_PIN 11
    #endif

    #if NUM_SERVOS > 3
      #define SERVO3_PIN 6
    #endif
  #endif
#endif // #if TRIGORILLA_VERSION

#if defined(ANYCUBIC_TFT_MODEL)
  #define BEEPER_PIN       33
  #define SD_DETECT_PIN    49
#endif

// LCD
#if defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL) || defined(ANYCUBIC_TFT_MODEL)
	#define KILL_PIN        41
#else
	#define KILL_PIN        -1
#endif

#ifdef ULTRA_LCD
	#ifdef NEWPANEL
		#define LCD_PINS_RS 16
		#define LCD_PINS_ENABLE 17
		#define LCD_PINS_D4 23
		#define LCD_PINS_D5 25
		#define LCD_PINS_D6 27
		#define LCD_PINS_D7 29

		#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
			#define BEEPER_PIN 37

			#define BTN_EN1 31
			#define BTN_EN2 33
			#define BTN_ENC 35

			#define SD_DETECT_PIN 49
			#elif defined(LCD_I2C_PANELOLU2)
				#define BTN_EN1 47  //reverse if the encoder turns the wrong way.
				#define BTN_EN2 43
				#define BTN_ENC 32
				#define SDSS 53
				#define SD_DETECT_PIN -1
				#define KILL_PIN 41
			#elif defined(LCD_I2C_VIKI)
				#define BTN_EN1 22  //reverse if the encoder turns the wrong way.
				#define BTN_EN2 7
				#define BTN_ENC -1
				#define SDSS 53
				#define SD_DETECT_PIN 49
			#elif defined(FULL_GRAPHIC_SMALL_PANEL)
				#define BEEPER_PIN 37

				// Pins for DOGM SPI LCD Support
				#define DOGLCD_A0  23
				#define DOGLCD_CS  27
				#define LCD_PIN_BL	25	// backlight LED on PA3

				#define KILL_PIN 41
				// GLCD features
				//#define LCD_CONTRAST 190
				// Uncomment screen orientation
				// #define LCD_SCREEN_ROT_90
				// #define LCD_SCREEN_ROT_180
				// #define LCD_SCREEN_ROT_270
				//The encoder and click button
				#define BTN_EN1 33
				#define BTN_EN2 -1
				#define BTN_ENC 35  //the click switch
				//not connected to a pin
				#define SD_DETECT_PIN 49
			#elif defined(MULTIPANEL)
				//         #define BEEPER_PIN 37
				// Pins for DOGM SPI LCD Support
				#define DOGLCD_A0  17
				#define DOGLCD_CS  16
				#define LCD_PIN_BL	23	// backlight LED on A11/D65
				#define SDSS   53

				#define KILL_PIN 64
				// GLCD features
				//#define LCD_CONTRAST 190
				// Uncomment screen orientation
				// #define LCD_SCREEN_ROT_90
				// #define LCD_SCREEN_ROT_180
				// #define LCD_SCREEN_ROT_270
				//The encoder and click button
				#define BTN_EN1 -1
				#define BTN_EN2 33
				#define BTN_ENC 35  //the click switch
				//not connected to a pin
				#define SD_DETECT_PIN 49
			#else
				//arduino pin which triggers an piezzo beeper
				#define BEEPER_PIN 31  // Beeper on AUX-4

			//buttons are directly attached using AUX-2
			#ifdef REPRAPWORLD_KEYPAD
				#define BTN_EN1 64 // encoder
				#define BTN_EN2 59 // encoder
				#define BTN_ENC 63 // enter button
				#define SHIFT_OUT 40 // shift register
				#define SHIFT_CLK 44 // shift register
				#define SHIFT_LD 42 // shift register
				#else
				#define BTN_EN1 37
				#define BTN_EN2 35
				#define BTN_ENC -1  //the click
			#endif

			#ifdef G3D_PANEL
				#define SD_DETECT_PIN 49
				#else
				#define SD_DETECT_PIN -1  // Ramps does not use this port
			#endif

		#endif

		#define LCD_PINS_RS 16
		#define LCD_PINS_ENABLE 17
		#define LCD_PINS_D4 23
		#define LCD_PINS_D5 25
		#define LCD_PINS_D6 27
		#define LCD_PINS_D7 29

	#endif
#endif

#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
	
  #ifdef X_SERIAL_TX_PIN
	#undef X_SERIAL_TX_PIN
    #define X_SERIAL_TX_PIN  4
  #else
	#define X_SERIAL_TX_PIN  4
  #endif
  
  #ifndef X_SERIAL_RX_PIN
    #define X_SERIAL_RX_PIN  63
  #endif
  #ifndef X2_SERIAL_TX_PIN
    #define X2_SERIAL_TX_PIN -1
  #endif
  #ifndef X2_SERIAL_RX_PIN
    #define X2_SERIAL_RX_PIN -1
  #endif

  #ifdef Y_SERIAL_TX_PIN
	#undef Y_SERIAL_TX_PIN
    #define Y_SERIAL_TX_PIN  5
  #else
	#define Y_SERIAL_TX_PIN  5
  #endif
  #ifndef Y_SERIAL_RX_PIN
    #define Y_SERIAL_RX_PIN  64
  #endif
  #ifndef Y2_SERIAL_TX_PIN
    #define Y2_SERIAL_TX_PIN -1
  #endif
  #ifndef Y2_SERIAL_RX_PIN
    #define Y2_SERIAL_RX_PIN -1
  #endif

  #ifdef Z_SERIAL_TX_PIN
	#undef Z_SERIAL_TX_PIN
    #define Z_SERIAL_TX_PIN  6
  #else
	#define Z_SERIAL_TX_PIN  6
  #endif
  #ifndef Z_SERIAL_RX_PIN
    #define Z_SERIAL_RX_PIN  65
  #endif
  #ifndef Z2_SERIAL_TX_PIN
    #define Z2_SERIAL_TX_PIN -1
  #endif
  #ifndef Z2_SERIAL_RX_PIN
    #define Z2_SERIAL_RX_PIN -1
  #endif

  #ifdef E0_SERIAL_TX_PIN
	#undef EO_SERIAL_TX_PIN
    #define E0_SERIAL_TX_PIN 11
  #else 
	#define E0_SERIAL_TX_PIN 11
  #endif
  #ifndef E0_SERIAL_RX_PIN
    #define E0_SERIAL_RX_PIN 66
  #endif
  #ifndef E1_SERIAL_TX_PIN
    #define E1_SERIAL_TX_PIN -1
  #endif
  #ifndef E1_SERIAL_RX_PIN
    #define E1_SERIAL_RX_PIN -1
  #endif
  #ifndef E2_SERIAL_TX_PIN
    #define E2_SERIAL_TX_PIN -1
  #endif
  #ifndef E2_SERIAL_RX_PIN
    #define E2_SERIAL_RX_PIN -1
  #endif
  #ifndef E3_SERIAL_TX_PIN
    #define E3_SERIAL_TX_PIN -1
  #endif
  #ifndef E3_SERIAL_RX_PIN
    #define E3_SERIAL_RX_PIN -1
  #endif
  #ifndef E4_SERIAL_TX_PIN
    #define E4_SERIAL_TX_PIN -1
  #endif
  #ifndef E4_SERIAL_RX_PIN
    #define E4_SERIAL_RX_PIN -1
  #endif
#endif
