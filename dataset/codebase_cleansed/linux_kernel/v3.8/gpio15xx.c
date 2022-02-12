static int __init omap15xx_gpio_init(void)
{
if (!cpu_is_omap15xx())
return -EINVAL;
platform_device_register(&omap15xx_mpu_gpio);
platform_device_register(&omap15xx_gpio);
return 0;
}
