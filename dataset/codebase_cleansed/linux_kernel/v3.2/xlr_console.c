void prom_putchar(char c)\r\n{\r\nnlm_reg_t *mmio;\r\nmmio = netlogic_io_mmio(NETLOGIC_IO_UART_0_OFFSET);\r\nwhile (netlogic_read_reg(mmio, 0x5) == 0)\r\n;\r\nnetlogic_write_reg(mmio, 0x0, c);\r\n}
