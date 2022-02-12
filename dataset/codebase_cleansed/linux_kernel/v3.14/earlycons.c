void prom_putchar(char c)
{
uint64_t uartbase;
#if defined(CONFIG_CPU_XLP)
uartbase = nlm_get_uart_regbase(0, 0);
#elif defined(CONFIG_CPU_XLR)
uartbase = nlm_mmio_base(NETLOGIC_IO_UART_0_OFFSET);
#endif
while ((nlm_read_reg(uartbase, UART_LSR) & UART_LSR_THRE) == 0)
;
nlm_write_reg(uartbase, UART_TX, c);
}
