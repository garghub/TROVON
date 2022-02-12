static int __init sead3_i2c_init(void)
{
return platform_device_register(&sead3_i2c_device);
}
