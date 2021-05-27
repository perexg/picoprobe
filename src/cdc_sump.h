/*
 * license header?
 */

#ifndef CDC_SUMP_H
#define CDC_SUMP_H

#define SUMP_META_NAME 1
#define SUMP_META_FPGA_VERSION 2
#define SUMP_META_CPU_VERSION 3
#define SUMP_META_SAMPLE_RATE 0x23
#define SUMP_META_SAMPLE_RAM 0x21/*?*/
#define SUMP_META_PROBES_B 0x40/*?*/
#define SUMP_META_PROTOCOL_B 0x24/*?*/
#define SUMP_META_END 0

#define SUMP_FLAG1_DDR 0/*TODO ???*/
#define SUMP_FLAG1_GR0_DISABLE (1<<2)
#define SUMP_FLAG1_GR1_DISABLE (1<<3)
#define SUMP_FLAG1_GR2_DISABLE (1<<4)
#define SUMP_FLAG1_GR3_DISABLE (1<<5)
#define SUMP_FLAG1_EXT_TEST (1<<10)/*?*/
#define SUMP_FLAG1_ENABLE_RLE (1<<8)/*?*/

#define SUMP_CMD_RESET 0
#define SUMP_CMD_ID 2
#define SUMP_CMD_ARM 1
#define SUMP_CMD_META 4
#define SUMP_CMD_FINISH 5
#define SUMP_CMD_QUERY_INPUT 6
#define SUMP_CMD_ADVANCED_ARM 0xF
#define SUMP_CMD_SET_SAMPLE_RATE 0x80/*?*/
#define SUMP_CMD_SET_COUNTS 0x81/*?*/
#define SUMP_CMD_SET_FLAGS 0x82
#define SUMP_CMD_SET_ADV_TRG_SELECT 0x9E
#define SUMP_CMD_SET_ADV_TRG_DATA 0x9F
#define SUMP_CMD_SET_BTRG0_MASK 0xC0
#define SUMP_CMD_SET_BTRG1_MASK 0xC4
#define SUMP_CMD_SET_BTRG2_MASK 0xC8
#define SUMP_CMD_SET_BTRG3_MASK 0xCC
#define SUMP_CMD_SET_BTRG0_VALUE 0xC1
#define SUMP_CMD_SET_BTRG1_VALUE 0xC5
#define SUMP_CMD_SET_BTRG2_VALUE 0xC9
#define SUMP_CMD_SET_BTRG3_VALUE 0xCD
#define SUMP_CMD_SET_BTRG0_CONFIG 0xC2
#define SUMP_CMD_SET_BTRG1_CONFIG 0xC6
#define SUMP_CMD_SET_BTRG2_CONFIG 0xCA
#define SUMP_CMD_SET_BTRG3_CONFIG 0xCE

#define SUMP_CMD_IS_SHORT(x) 0/*TODO: ???*/

void __isr sump_dma_irq_handler(void);
void sump_rx(uint8_t *buf, uint count);
void cdc_sump_init(void);
void cdc_sump_task(void);
void cdc_sump_line_coding(cdc_line_coding_t const *line_coding);

#endif
