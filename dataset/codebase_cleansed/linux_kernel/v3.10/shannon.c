static void __init shannon_init(void)
{
sa11x0_ppc_configure_mcp();
sa11x0_register_lcd(&shannon_lcd_info);
sa11x0_register_mtd(&shannon_flash_data, &shannon_flash_resource, 1);
sa11x0_register_mcp(&shannon_mcp_data);
}
static void __init shannon_map_io(void)
{
sa1100_map_io();
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
Ser1SDCR0 |= SDCR0_SUS;
GAFR |= (GPIO_UART_TXD | GPIO_UART_RXD);
GPDR |= GPIO_UART_TXD | SHANNON_GPIO_CODEC_RESET;
GPDR &= ~GPIO_UART_RXD;
PPAR |= PPAR_UPR;
GPCR = SHANNON_GPIO_CODEC_RESET;
GPSR = SHANNON_GPIO_CODEC_RESET;
}
