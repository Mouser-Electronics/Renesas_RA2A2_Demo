/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define ARDUINO_A1_GROVE2_A1 (BSP_IO_PORT_00_PIN_01)
#define ARDUINO_A2 (BSP_IO_PORT_00_PIN_02)
#define GROVE1_SCL_MIKROBUS_SCL_QWIIC_SCL (BSP_IO_PORT_00_PIN_12)
#define GROVE1_SDA_MIKROBUS_SDA_QWIIC_SDA (BSP_IO_PORT_00_PIN_13)
#define ARDUINO_A0_GROVE2_A0_MIKROBUS_AN (BSP_IO_PORT_00_PIN_14)
#define ARDUINO_A3 (BSP_IO_PORT_00_PIN_15)
#define ARDUINO_MOSI_MIKROBUS_TX (BSP_IO_PORT_01_PIN_00)
#define ARDUINO_MISO_MIKROBUS_RX (BSP_IO_PORT_01_PIN_01)
#define ARDUINO_SCK (BSP_IO_PORT_01_PIN_02)
#define ARDUINO_SS_PMOD1_CS3 (BSP_IO_PORT_01_PIN_03)
#define ARDUINO_D6 (BSP_IO_PORT_01_PIN_04)
#define ARDUINO_D9 (BSP_IO_PORT_01_PIN_05)
#define ARDUINO_TXD (BSP_IO_PORT_01_PIN_06) /* Arduino_D1 */
#define ARDUINO_RXD (BSP_IO_PORT_01_PIN_07) /* Arduino_D0 */
#define ARDUINO_D5 (BSP_IO_PORT_01_PIN_11)
#define PMOD1_CS2 (BSP_IO_PORT_01_PIN_12)
#define SW1 (BSP_IO_PORT_02_PIN_00)
#define PMOD2_GPIO2 (BSP_IO_PORT_02_PIN_03)
#define PMOD2_GPIO3 (BSP_IO_PORT_02_PIN_04)
#define PMOD2_GPIO4 (BSP_IO_PORT_02_PIN_05)
#define ARDUINO_D3 (BSP_IO_PORT_02_PIN_10)
#define ARDUINO_D7 (BSP_IO_PORT_03_PIN_01)
#define ARDUINO_D4 (BSP_IO_PORT_03_PIN_02)
#define ARDUINO_D8 (BSP_IO_PORT_03_PIN_03)
#define ARDUINO_D2_SW2 (BSP_IO_PORT_03_PIN_06)
#define LED1 (BSP_IO_PORT_03_PIN_07) /* BLUE */
#define LED2 (BSP_IO_PORT_03_PIN_08) /* GREEN */
#define LED3 (BSP_IO_PORT_03_PIN_09) /* RED */
#define PMOD2_GPIO1 (BSP_IO_PORT_03_PIN_10)
#define MIKROBUS_RST (BSP_IO_PORT_03_PIN_13)
#define PMOD1_INT (BSP_IO_PORT_04_PIN_00)
#define PMOD1_RESET (BSP_IO_PORT_04_PIN_01)
#define MIKROBUS_INT (BSP_IO_PORT_04_PIN_02)
#define MIKROBUS_MISO_PMOD1_MISO (BSP_IO_PORT_04_PIN_03)
#define MIKROBUS_MOSI_PMOD1_MOSI (BSP_IO_PORT_04_PIN_04)
#define MIKROBUS_SCK_PMOD1_SCK (BSP_IO_PORT_04_PIN_05)
#define MIKROBUS_CS_PMOD1_CS (BSP_IO_PORT_04_PIN_08)
#define MIKROBUS_PWM (BSP_IO_PORT_04_PIN_09)
#define ARDUINO_SDA_PMOD2_SDA (BSP_IO_PORT_04_PIN_10)
#define ARDUINO_SCL_PMOD2_SCL (BSP_IO_PORT_04_PIN_11)
#define PMOD2_RXD (BSP_IO_PORT_05_PIN_00) /* secondary option */
#define PMOD2_RESET (BSP_IO_PORT_05_PIN_01) /* Primary option */
#define PMOD2_SCK (BSP_IO_PORT_05_PIN_02) /* Tertiary option */
#define PMOD2_INT (BSP_IO_PORT_05_PIN_03) /* Primary option */

extern const ioport_cfg_t g_bsp_pin_cfg; /* RA6M4 EK */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
