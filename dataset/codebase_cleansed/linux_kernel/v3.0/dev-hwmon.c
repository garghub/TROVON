void __init s3c_hwmon_set_platdata(struct s3c_hwmon_pdata *pd)
{
struct s3c_hwmon_pdata *npd;
if (!pd) {
printk(KERN_ERR "%s: no platform data\n", __func__);
return;
}
npd = kmemdup(pd, sizeof(struct s3c_hwmon_pdata), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
s3c_device_hwmon.dev.platform_data = npd;
}
