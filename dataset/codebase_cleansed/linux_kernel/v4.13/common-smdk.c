void __init smdk_machine_init(void)
{
int ret = gpio_request_array(smdk_led_gpios,
ARRAY_SIZE(smdk_led_gpios));
if (!WARN_ON(ret < 0))
gpio_free_array(smdk_led_gpios, ARRAY_SIZE(smdk_led_gpios));
if (machine_is_smdk2443())
smdk_nand_info.twrph0 = 50;
s3c_nand_set_platdata(&smdk_nand_info);
platform_add_devices(smdk_devs, ARRAY_SIZE(smdk_devs));
s3c_pm_init();
}
