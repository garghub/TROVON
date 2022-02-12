static int __init omap7xx_gpio_init(void)
{
int i;
if (!cpu_is_omap7xx())
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(omap7xx_gpio_dev); i++)
platform_device_register(omap7xx_gpio_dev[i]);
return 0;
}
