void __init s3c24xx_ts_set_platdata(struct s3c2410_ts_mach_info *pd)
{
struct s3c2410_ts_mach_info *npd;
if (!pd) {
printk(KERN_ERR "%s: no platform data\n", __func__);
return;
}
npd = kmemdup(pd, sizeof(struct s3c2410_ts_mach_info), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
s3c_device_ts.dev.platform_data = npd;
}
