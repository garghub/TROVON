static inline unsigned int serial_in(int offset, unsigned int base_addr)
{
return __raw_readl(PORT(base_addr, offset)) & 0xff;
}
static inline void serial_out(int offset, int value, unsigned int base_addr)
{
__raw_writel(value, PORT(base_addr, offset));
}
void __init fw_init_early_console(char port)
{
console_port = port;
}
int prom_putchar(char c)
{
unsigned int base_addr;
base_addr = console_port ? SEAD_UART1_REGS_BASE : SEAD_UART0_REGS_BASE;
while ((serial_in(UART_LSR, base_addr) & UART_LSR_THRE) == 0)
;
serial_out(UART_TX, c, base_addr);
return 1;
}
