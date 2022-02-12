static int __init sead3_i2c_init(void)
{
int err;
err = i2c_register_board_info(0, sead3_i2c_devices,
ARRAY_SIZE(sead3_i2c_devices));
if (err < 0)
pr_err("sead3-i2c-dev: cannot register board I2C devices\n");
return err;
}
