void __init dreamplug_init(void)
{
kirkwood_mpp_conf(dreamplug_mpp_config);
spi_register_board_info(dreamplug_spi_slave_info,
ARRAY_SIZE(dreamplug_spi_slave_info));
kirkwood_spi_init();
kirkwood_ehci_init();
kirkwood_ge00_init(&dreamplug_ge00_data);
kirkwood_ge01_init(&dreamplug_ge01_data);
kirkwood_sata_init(&dreamplug_sata_data);
kirkwood_sdio_init(&dreamplug_mvsdio_data);
platform_device_register(&dreamplug_leds);
}
