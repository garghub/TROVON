void __init dockstar_dt_init(void)
{
kirkwood_mpp_conf(dockstar_mpp_config);
if (gpio_request(29, "USB Power Enable") != 0 ||
gpio_direction_output(29, 1) != 0)
pr_err("can't setup GPIO 29 (USB Power Enable)\n");
kirkwood_ehci_init();
kirkwood_ge00_init(&dockstar_ge00_data);
}
