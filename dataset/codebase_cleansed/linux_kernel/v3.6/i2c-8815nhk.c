static int __init nhk8815_i2c_init(void)
{
nmk_config_pins(cpu8815_pins_i2c, ARRAY_SIZE(cpu8815_pins_i2c));
platform_device_register(&nhk8815_i2c_dev0);
platform_device_register(&nhk8815_i2c_dev1);
platform_device_register(&nhk8815_i2c_dev2);
return 0;
}
static void __exit nhk8815_i2c_exit(void)
{
platform_device_unregister(&nhk8815_i2c_dev0);
platform_device_unregister(&nhk8815_i2c_dev1);
platform_device_unregister(&nhk8815_i2c_dev2);
return;
}
