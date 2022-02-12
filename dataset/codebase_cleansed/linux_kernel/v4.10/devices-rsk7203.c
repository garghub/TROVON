static int __init rsk7203_devices_setup(void)
{
gpio_request(GPIO_FN_TXD0, NULL);
gpio_request(GPIO_FN_RXD0, NULL);
__raw_writel(0x36db0400, 0xfffc0008);
gpio_request(GPIO_FN_IRQ0_PB, NULL);
return platform_add_devices(rsk7203_devices,
ARRAY_SIZE(rsk7203_devices));
}
