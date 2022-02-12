static void __init csb726_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(csb726_pin_config));
__raw_writel((__raw_readl(MSC2) & ~0xffff) | 0x7ff4, MSC2);
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
pxa27x_set_i2c_power_info(NULL);
pxa_set_mci_info(&csb726_mci);
pxa_set_ohci_info(&csb726_ohci_platform_data);
pxa_set_ac97_info(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
