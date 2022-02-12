static void __init rd88f6183ap_ge_init(void)
{
orion5x_init();
orion5x_ehci0_init();
orion5x_eth_init(&rd88f6183ap_ge_eth_data);
orion5x_eth_switch_init(&rd88f6183ap_ge_switch_plat_data,
gpio_to_irq(3));
spi_register_board_info(rd88f6183ap_ge_spi_slave_info,
ARRAY_SIZE(rd88f6183ap_ge_spi_slave_info));
orion5x_spi_init();
orion5x_uart0_init();
}
static int __init rd88f6183ap_ge_pci_init(void)
{
if (machine_is_rd88f6183ap_ge()) {
orion5x_pci_disable();
pci_common_init(&rd88f6183ap_ge_pci);
}
return 0;
}
