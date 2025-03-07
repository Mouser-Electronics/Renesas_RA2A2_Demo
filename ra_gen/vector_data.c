/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI3 RXI (Receive data full) */
            [3] = sci_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [5] = sci_i2c_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [6] = sci_i2c_tei_isr, /* SCI0 TEI (Transmit end) */
            [9] = sci_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [10] = sci_uart_tei_isr, /* SCI3 TEI (Transmit end) */
            [42] = r_icu_isr, /* ICU IRQ10 (External pin interrupt 10) */
            [51] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI3_RXI,GROUP0), /* SCI3 RXI (Receive data full) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI3_ERI,GROUP3), /* SCI3 ERI (Receive error) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TXI,GROUP5), /* SCI0 TXI (Transmit data empty) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TEI,GROUP6), /* SCI0 TEI (Transmit end) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TXI,GROUP1), /* SCI3 TXI (Transmit data empty) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TEI,GROUP2), /* SCI3 TEI (Transmit end) */
            [42] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ10,FIXED), /* ICU IRQ10 (External pin interrupt 10) */
            [51] = BSP_PRV_VECT_ENUM(EVENT_AGT0_INT,FIXED), /* AGT0 INT (AGT interrupt) */
        };
        #endif
        #endif
