static void __init rd88f6192_init(void)
{
kirkwood_init();
orion_gpio_set_valid(RD88F6192_GPIO_USB_VBUS, 1);
if (gpio_request(RD88F6192_GPIO_USB_VBUS, "USB VBUS") != 0 ||
gpio_direction_output(RD88F6192_GPIO_USB_VBUS, 1) != 0)
pr_err("RD-88F6192-NAS: failed to setup USB VBUS GPIO\n");
kirkwood_ehci_init();
kirkwood_ge00_init(&rd88f6192_ge00_data);
kirkwood_sata_init(&rd88f6192_sata_data);
spi_register_board_info(rd88F6192_spi_slave_info,
ARRAY_SIZE(rd88F6192_spi_slave_info));
kirkwood_spi_init();
kirkwood_uart0_init();
}
static int __init rd88f6192_pci_init(void)
{
if (machine_is_rd88f6192_nas())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
