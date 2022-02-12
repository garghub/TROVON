static int __init bcm43xx_regulator_register(void)
{
int ret;
bcm43xx_vmmc.gpio = get_gpio_by_name(WLAN_SFI_GPIO_ENABLE_NAME);
ret = platform_device_register(&bcm43xx_vmmc_regulator);
if (ret) {
pr_err("%s: vmmc regulator register failed\n", __func__);
return ret;
}
return 0;
}
static void __init *bcm43xx_platform_data(void *info)
{
int ret;
ret = bcm43xx_regulator_register();
if (ret)
return NULL;
pr_info("Using generic wifi platform data\n");
return NULL;
}
