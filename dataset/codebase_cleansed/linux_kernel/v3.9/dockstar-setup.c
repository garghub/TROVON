static void __init dockstar_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(dockstar_mpp_config);
kirkwood_uart0_init();
kirkwood_nand_init(ARRAY_AND_SIZE(dockstar_nand_parts), 25);
if (gpio_request(29, "USB Power Enable") != 0 ||
gpio_direction_output(29, 1) != 0)
pr_err("can't set up GPIO 29 (USB Power Enable)\n");
kirkwood_ehci_init();
kirkwood_ge00_init(&dockstar_ge00_data);
platform_device_register(&dockstar_leds);
}
