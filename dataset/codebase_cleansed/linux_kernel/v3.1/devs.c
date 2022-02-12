void __init s3c24xx_fb_set_platdata(struct s3c2410fb_mach_info *pd)
{
struct s3c2410fb_mach_info *npd;
npd = s3c_set_platdata(pd, sizeof(*npd), &s3c_device_lcd);
if (npd) {
npd->displays = kmemdup(pd->displays,
sizeof(struct s3c2410fb_display) * npd->num_displays,
GFP_KERNEL);
if (!npd->displays)
printk(KERN_ERR "no memory for LCD display data\n");
} else {
printk(KERN_ERR "no memory for LCD platform data\n");
}
}
void __init s3c24xx_ts_set_platdata(struct s3c2410_ts_mach_info *hard_s3c2410ts_info)
{
s3c_set_platdata(hard_s3c2410ts_info,
sizeof(struct s3c2410_ts_mach_info), &s3c_device_ts);
}
void __init s3c24xx_udc_set_platdata(struct s3c2410_udc_mach_info *pd)
{
s3c_set_platdata(pd, sizeof(*pd), &s3c_device_usbgadget);
}
void __init s3c24xx_hsudc_set_platdata(struct s3c24xx_hsudc_platdata *pd)
{
s3c_set_platdata(pd, sizeof(*pd), &s3c_device_usb_hsudc);
}
void __init s3c24xx_mci_set_platdata(struct s3c24xx_mci_pdata *pdata)
{
s3c_set_platdata(pdata, sizeof(struct s3c24xx_mci_pdata),
&s3c_device_sdi);
}
