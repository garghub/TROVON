static inline unsigned int serial_in(int offset)
{
return *((char *)PORT(offset));
}
static inline void serial_out(int offset, int value)
{
*((char *)PORT(offset)) = value;
}
void putc(char c)
{
int timeout = 1024;
while (((serial_in(UART_LSR) & UART_LSR_THRE) == 0) && (timeout-- > 0))
;
serial_out(UART_TX, c);
}
