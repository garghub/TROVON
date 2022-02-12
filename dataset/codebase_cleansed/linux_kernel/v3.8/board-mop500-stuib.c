void __init mop500_stuib_init(void)
{
if (machine_is_hrefv60())
tsc_plat_device.cs_pin = HREFV60_TOUCH_RST_GPIO;
else
tsc_plat_device.cs_pin = GPIO_BU21013_CS;
mop500_uib_i2c_add(0, mop500_i2c0_devices_stuib,
ARRAY_SIZE(mop500_i2c0_devices_stuib));
mop500_uib_i2c_add(3, u8500_i2c3_devices_stuib,
ARRAY_SIZE(u8500_i2c3_devices_stuib));
}
