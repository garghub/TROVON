static void __init sheevaplug_init(void)
{
kirkwood_init();
if (machine_is_esata_sheevaplug())
kirkwood_mpp_conf(sheeva_esata_mpp_config);
else
kirkwood_mpp_conf(sheevaplug_mpp_config);
kirkwood_uart0_init();
kirkwood_nand_init(ARRAY_AND_SIZE(sheevaplug_nand_parts), 25);
if (gpio_request(29, "USB Power Enable") != 0 ||
gpio_direction_output(29, 1) != 0)
printk(KERN_ERR "can't set up GPIO 29 (USB Power Enable)\n");
kirkwood_ehci_init();
kirkwood_ge00_init(&sheevaplug_ge00_data);
if (machine_is_esata_sheevaplug())
kirkwood_sata_init(&sheeva_esata_sata_data);
if (machine_is_esata_sheevaplug())
kirkwood_sdio_init(&sheeva_esata_mvsdio_data);
else
kirkwood_sdio_init(&sheevaplug_mvsdio_data);
platform_device_register(&sheevaplug_leds);
}
