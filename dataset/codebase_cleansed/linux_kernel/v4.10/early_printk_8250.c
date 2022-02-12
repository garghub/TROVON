void setup_8250_early_printk_port(unsigned long base, unsigned int reg_shift,
unsigned int timeout)
{
serial8250_base = (void __iomem *)base;
serial8250_reg_shift = reg_shift;
serial8250_tx_timeout = timeout;
}
static inline u8 serial_in(int offset)
{
return readb(serial8250_base + (offset << serial8250_reg_shift));
}
static inline void serial_out(int offset, char value)
{
writeb(value, serial8250_base + (offset << serial8250_reg_shift));
}
void prom_putchar(char c)
{
unsigned int timeout;
int status, bits;
if (!serial8250_base)
return;
timeout = serial8250_tx_timeout;
bits = UART_LSR_TEMT | UART_LSR_THRE;
do {
status = serial_in(UART_LSR);
if (--timeout == 0)
break;
} while ((status & bits) != bits);
if (timeout)
serial_out(UART_TX, c);
}
