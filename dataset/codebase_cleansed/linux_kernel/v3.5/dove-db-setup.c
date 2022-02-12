static int __init dove_db_pci_init(void)
{
if (machine_is_dove_db())
dove_pcie_init(1, 1);
return 0;
}
static void __init dove_db_init(void)
{
dove_init();
dove_ge00_init(&dove_db_ge00_data);
dove_ehci0_init();
dove_ehci1_init();
dove_sata_init(&dove_db_sata_data);
dove_sdio0_init();
dove_sdio1_init();
dove_spi0_init();
dove_spi1_init();
dove_uart0_init();
dove_uart1_init();
dove_i2c_init();
spi_register_board_info(dove_db_spi_flash_info,
ARRAY_SIZE(dove_db_spi_flash_info));
}
