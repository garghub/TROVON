static void __init xcep_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(xcep_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_hwuart_info(NULL);
__raw_writel((__raw_readl(MSC1) & 0xffff) | 0xD5540000, MSC1);
__raw_writel((__raw_readl(MSC2) & 0xffff) | 0x72A00000, MSC2);
platform_add_devices(ARRAY_AND_SIZE(devices));
pxa_set_i2c_info(&xcep_i2c_platform_data);
}
