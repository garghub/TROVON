static void __init mv88f6281gtw_ge_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(mv88f6281gtw_ge_mpp_config);
kirkwood_ehci_init();
kirkwood_ge00_init(&mv88f6281gtw_ge_ge00_data);
kirkwood_ge00_switch_init(&mv88f6281gtw_ge_switch_plat_data, NO_IRQ);
spi_register_board_info(mv88f6281gtw_ge_spi_slave_info,
ARRAY_SIZE(mv88f6281gtw_ge_spi_slave_info));
kirkwood_spi_init();
kirkwood_uart0_init();
platform_device_register(&mv88f6281gtw_ge_leds);
platform_device_register(&mv88f6281gtw_ge_buttons);
}
static int __init mv88f6281gtw_ge_pci_init(void)
{
if (machine_is_mv88f6281gtw_ge())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
