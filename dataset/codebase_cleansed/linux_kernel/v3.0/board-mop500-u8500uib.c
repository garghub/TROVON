void __init mop500_u8500uib_init(void)
{
mop500_uib_i2c_add(3, mop500_i2c3_devices_u8500,
ARRAY_SIZE(mop500_i2c3_devices_u8500));
mop500_uib_i2c_add(0, mop500_i2c0_devices_u8500,
ARRAY_SIZE(mop500_i2c0_devices_u8500));
}
