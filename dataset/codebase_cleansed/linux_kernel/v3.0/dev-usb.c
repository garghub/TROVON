void __init s3c_ohci_set_platdata(struct s3c2410_hcd_info *info)
{
struct s3c2410_hcd_info *npd;
npd = kmemdup(info, sizeof(struct s3c2410_hcd_info), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory for platform data\n", __func__);
s3c_device_ohci.dev.platform_data = npd;
}
