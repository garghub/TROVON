void __init s3c_i2c1_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd) {
pd = &default_i2c_data;
pd->bus_num = 1;
}
npd = s3c_set_platdata(pd, sizeof(struct s3c2410_platform_i2c),
&s3c_device_i2c1);
if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c1_cfg_gpio;
}
