static int __init cm_a510_pci_init(void)
{
if (machine_is_cm_a510())
dove_pcie_init(1, 1);
return 0;
}
static void __init cm_a510_init(void)
{
dove_init();
dove_ge00_init(&cm_a510_ge00_data);
dove_ehci0_init();
dove_ehci1_init();
dove_sata_init(&cm_a510_sata_data);
dove_sdio0_init();
dove_sdio1_init();
dove_spi0_init();
dove_spi1_init();
dove_uart0_init();
dove_uart1_init();
dove_i2c_init();
spi_register_board_info(cm_a510_spi_flash_info,
ARRAY_SIZE(cm_a510_spi_flash_info));
}
