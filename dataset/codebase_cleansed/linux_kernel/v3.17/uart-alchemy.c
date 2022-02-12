void putc(char c)\r\n{\r\nalchemy_uart_putchar(AU1000_UART0_PHYS_ADDR, c);\r\n}
