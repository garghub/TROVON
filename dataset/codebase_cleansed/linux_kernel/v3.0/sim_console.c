static inline unsigned int serial_in(int offset)
{
return inb(0x3f8 + offset);
}
static inline void serial_out(int offset, int value)
{
outb(value, 0x3f8 + offset);
}
void __init prom_putchar(char c)
{
while ((serial_in(UART_LSR) & UART_LSR_THRE) == 0)
;
serial_out(UART_TX, c);
}
