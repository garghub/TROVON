static void __init marzen_map_io(void)
{
iotable_init(marzen_io_desc, ARRAY_SIZE(marzen_io_desc));
}
static void __init marzen_init_early(void)
{
r8a7779_add_early_devices();
}
static void __init marzen_init(void)
{
r8a7779_pinmux_init();
gpio_request(GPIO_FN_TX2_C, NULL);
gpio_request(GPIO_FN_RX2_C, NULL);
gpio_request(GPIO_FN_TX4, NULL);
gpio_request(GPIO_FN_RX4, NULL);
gpio_request(GPIO_FN_EX_CS0, NULL);
gpio_request(GPIO_FN_IRQ1_B, NULL);
r8a7779_add_standard_devices();
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
static void __init marzen_timer_init(void)
{
r8a7779_clock_init();
shmobile_timer.init();
return;
}
