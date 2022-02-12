static void __init kzm_init(void)
{
sh73a0_add_standard_devices_dt();
pinctrl_register_mappings(kzm_pinctrl_map, ARRAY_SIZE(kzm_pinctrl_map));
sh73a0_pinmux_init();
gpio_request(GPIO_FN_SDHI0_VCCQ_MC0_ON, NULL);
gpio_request_one(15, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(14, GPIOF_OUT_INIT_HIGH, NULL);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40460000, 0x82000fff);
#endif
}
