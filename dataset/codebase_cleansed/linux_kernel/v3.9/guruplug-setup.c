static void __init guruplug_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(guruplug_mpp_config);
kirkwood_uart0_init();
kirkwood_nand_init(ARRAY_AND_SIZE(guruplug_nand_parts), 25);
kirkwood_ehci_init();
kirkwood_ge00_init(&guruplug_ge00_data);
kirkwood_ge01_init(&guruplug_ge01_data);
kirkwood_sata_init(&guruplug_sata_data);
kirkwood_sdio_init(&guruplug_mvsdio_data);
platform_device_register(&guruplug_leds);
}
