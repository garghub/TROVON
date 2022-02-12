static int __init nhk8815_i2c_init(void)
{
nmk_gpio_set_mode(nhk8815_i2c_data0.scl_pin, NMK_GPIO_ALT_GPIO);
nmk_gpio_set_mode(nhk8815_i2c_data0.sda_pin, NMK_GPIO_ALT_GPIO);
platform_device_register(&nhk8815_i2c_dev0);
nmk_gpio_set_mode(nhk8815_i2c_data1.scl_pin, NMK_GPIO_ALT_GPIO);
nmk_gpio_set_mode(nhk8815_i2c_data1.sda_pin, NMK_GPIO_ALT_GPIO);
platform_device_register(&nhk8815_i2c_dev1);
return 0;
}
static void __exit nhk8815_i2c_exit(void)
{
platform_device_unregister(&nhk8815_i2c_dev0);
platform_device_unregister(&nhk8815_i2c_dev1);
return;
}
