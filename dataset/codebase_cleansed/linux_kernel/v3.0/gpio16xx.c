static int __init omap16xx_gpio_init(void)
{
int i;
if (!cpu_is_omap16xx())
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(omap16xx_gpio_dev); i++)
platform_device_register(omap16xx_gpio_dev[i]);
gpio_bank_count = ARRAY_SIZE(omap16xx_gpio_dev);
return 0;
}
