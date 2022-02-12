void __init s3c_fb_set_platdata(struct s3c_fb_platdata *pd)
{
struct s3c_fb_platdata *npd;
if (!pd) {
printk(KERN_ERR "%s: no platform data\n", __func__);
return;
}
npd = kmemdup(pd, sizeof(struct s3c_fb_platdata), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
s3c_device_fb.dev.platform_data = npd;
}
