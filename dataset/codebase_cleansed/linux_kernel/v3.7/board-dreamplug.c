void __init dreamplug_init(void)
{
kirkwood_mpp_conf(dreamplug_mpp_config);
kirkwood_ehci_init();
kirkwood_ge00_init(&dreamplug_ge00_data);
kirkwood_ge01_init(&dreamplug_ge01_data);
kirkwood_sdio_init(&dreamplug_mvsdio_data);
}
