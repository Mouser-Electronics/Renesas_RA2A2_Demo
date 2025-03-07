/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (8)
#endif
/* ISR prototypes */
void sci_uart_rxi_isr(void);
void sci_uart_eri_isr(void);
void sci_i2c_txi_isr(void);
void sci_i2c_tei_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void r_icu_isr(void);
void agt_int_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI3_RXI ((IRQn_Type) 0) /* SCI3 RXI (Receive data full) */
#define SCI3_RXI_IRQn          ((IRQn_Type) 0) /* SCI3 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI3_ERI ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define SCI3_ERI_IRQn          ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 5) /* SCI0 TXI (Transmit data empty) */
#define SCI0_TXI_IRQn          ((IRQn_Type) 5) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 6) /* SCI0 TEI (Transmit end) */
#define SCI0_TEI_IRQn          ((IRQn_Type) 6) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI3_TXI ((IRQn_Type) 9) /* SCI3 TXI (Transmit data empty) */
#define SCI3_TXI_IRQn          ((IRQn_Type) 9) /* SCI3 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI3_TEI ((IRQn_Type) 10) /* SCI3 TEI (Transmit end) */
#define SCI3_TEI_IRQn          ((IRQn_Type) 10) /* SCI3 TEI (Transmit end) */
#define VECTOR_NUMBER_ICU_IRQ10 ((IRQn_Type) 42) /* ICU IRQ10 (External pin interrupt 10) */
#define ICU_IRQ10_IRQn          ((IRQn_Type) 42) /* ICU IRQ10 (External pin interrupt 10) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 51) /* AGT0 INT (AGT interrupt) */
#define AGT0_INT_IRQn          ((IRQn_Type) 51) /* AGT0 INT (AGT interrupt) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
