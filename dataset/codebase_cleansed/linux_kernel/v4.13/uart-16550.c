static inline unsigned int serial_in(int offset)
{
return *((volatile IOTYPE *)PORT(offset)) & 0xFF;
}
static inline void serial_out(int offset, int value)
{
*((volatile IOTYPE *)PORT(offset)) = value & 0xFF;
}
void putc(char c)
{
int timeout = 1000000;
while (((serial_in(UART_LSR) & UART_LSR_THRE) == 0) && (timeout-- > 0))
;
serial_out(UART_TX, c);
}
