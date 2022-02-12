static void fix_msc(void)
{
__raw_writel(0x129c24f2, MSC0);
__raw_writel(0x7ff424fa, MSC1);
__raw_writel(0x7ff47ff4, MSC2);
__raw_writel(__raw_readl(MDREFR) | 0x02080000, MDREFR);
}
static void __init h5000_init(void)
{
fix_msc();
pxa2xx_mfp_config(ARRAY_AND_SIZE(h5000_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_udc_info(&h5000_udc_mach_info);
platform_add_devices(ARRAY_AND_SIZE(devices));
}
