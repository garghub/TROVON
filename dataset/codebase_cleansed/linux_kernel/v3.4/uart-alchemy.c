void putc(char c)\r\n{\r\n#ifdef CONFIG_MIPS_DB1300\r\nalchemy_uart_putchar(AU1300_UART2_PHYS_ADDR, c);\r\n#else\r\nalchemy_uart_putchar(AU1000_UART0_PHYS_ADDR, c);\r\n#endif\r\n}
