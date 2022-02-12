void putc(char c)
{
alchemy_uart_putchar(AU1000_UART0_PHYS_ADDR, c);
}
