void __init s3c_i2c0_set_platdata(struct s3c2410_platform_i2c *pd)
{
struct s3c2410_platform_i2c *npd;
if (!pd)
pd = &default_i2c_data0;
npd = kmemdup(pd, sizeof(struct s3c2410_platform_i2c), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
else if (!npd->cfg_gpio)
npd->cfg_gpio = s3c_i2c0_cfg_gpio;
s3c_device_i2c0.dev.platform_data = npd;
}
