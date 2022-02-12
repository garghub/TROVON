void __init s3c24xx_fb_set_platdata(struct s3c2410fb_mach_info *pd)
{
struct s3c2410fb_mach_info *npd;
npd = kmemdup(pd, sizeof(*npd), GFP_KERNEL);
if (npd) {
s3c_device_lcd.dev.platform_data = npd;
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
memcpy(&s3c2410ts_info, hard_s3c2410ts_info, sizeof(struct s3c2410_ts_mach_info));
s3c_device_ts.dev.platform_data = &s3c2410ts_info;
}
void __init s3c24xx_udc_set_platdata(struct s3c2410_udc_mach_info *pd)
{
struct s3c2410_udc_mach_info *npd;
npd = kmalloc(sizeof(*npd), GFP_KERNEL);
if (npd) {
memcpy(npd, pd, sizeof(*npd));
s3c_device_usbgadget.dev.platform_data = npd;
} else {
printk(KERN_ERR "no memory for udc platform data\n");
}
}
void __init s3c24xx_hsudc_set_platdata(struct s3c24xx_hsudc_platdata *pd)
{
struct s3c24xx_hsudc_platdata *npd;
npd = kmalloc(sizeof(*npd), GFP_KERNEL);
if (npd) {
memcpy(npd, pd, sizeof(*npd));
s3c_device_usb_hsudc.dev.platform_data = npd;
} else {
printk(KERN_ERR "no memory for udc platform data\n");
}
}
void __init s3c24xx_mci_set_platdata(struct s3c24xx_mci_pdata *pdata)
{
struct s3c24xx_mci_pdata *npd;
npd = kmemdup(pdata, sizeof(struct s3c24xx_mci_pdata), GFP_KERNEL);
if (!npd)
printk(KERN_ERR "%s: no memory to copy pdata", __func__);
s3c_device_sdi.dev.platform_data = npd;
}
