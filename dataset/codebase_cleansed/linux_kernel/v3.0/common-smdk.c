void __init smdk_machine_init(void)
{
s3c_gpio_cfgpin(S3C2410_GPF(4), S3C2410_GPIO_OUTPUT);
s3c_gpio_cfgpin(S3C2410_GPF(5), S3C2410_GPIO_OUTPUT);
s3c_gpio_cfgpin(S3C2410_GPF(6), S3C2410_GPIO_OUTPUT);
s3c_gpio_cfgpin(S3C2410_GPF(7), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPF(4), 1);
s3c2410_gpio_setpin(S3C2410_GPF(5), 1);
s3c2410_gpio_setpin(S3C2410_GPF(6), 1);
s3c2410_gpio_setpin(S3C2410_GPF(7), 1);
if (machine_is_smdk2443())
smdk_nand_info.twrph0 = 50;
s3c_nand_set_platdata(&smdk_nand_info);
platform_add_devices(smdk_devs, ARRAY_SIZE(smdk_devs));
s3c_pm_init();
}
