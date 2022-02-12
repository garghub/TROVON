static void __init pleb_init(void)
{
sa11x0_register_mtd(&pleb_flash_data, pleb_flash_resources,
ARRAY_SIZE(pleb_flash_resources));
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init pleb_map_io(void)
{
sa1100_map_io();
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
GAFR |= (GPIO_UART_TXD | GPIO_UART_RXD);
GPDR |= GPIO_UART_TXD;
GPDR &= ~GPIO_UART_RXD;
PPAR |= PPAR_UPR;
MECR = ((2<<10) | (2<<5) | (2<<0));
GPDR |= GPIO_ETH0_EN;
GPCR = GPIO_ETH0_EN;
GPDR &= ~GPIO_ETH0_IRQ;
irq_set_irq_type(GPIO_ETH0_IRQ, IRQ_TYPE_EDGE_FALLING);
}
