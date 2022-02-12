void __init mxm_8x10_mmc_init(void)
{
pxa_set_mci_info(&mxm_8x10_mci_platform_data);
}
void __init mxm_8x10_usb_host_init(void)
{
pxa_set_ohci_info(&mxm_8x10_ohci_platform_data);
}
void __init mxm_8x10_ac97_init(void)
{
platform_device_register(&mxm_8x10_ac97_device);
}
static void __init mxm_8x10_nand_init(void)
{
pxa3xx_set_nand_info(&mxm_8x10_nand_info);
}
static inline void mxm_8x10_nand_init(void) {}
static void __init mxm_8x10_ethernet_init(void)
{
platform_device_register(&dm9k_device);
}
static void __init mxm_8x10_uarts_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
}
static void __init mxm_8x10_i2c_init(void)
{
i2c_register_board_info(0, mxm_8x10_i2c_devices,
ARRAY_SIZE(mxm_8x10_i2c_devices));
pxa_set_i2c_info(NULL);
}
void __init mxm_8x10_barebones_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(mfp_cfg));
mxm_8x10_uarts_init();
mxm_8x10_nand_init();
mxm_8x10_i2c_init();
mxm_8x10_ethernet_init();
}
