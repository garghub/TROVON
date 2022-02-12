static void __init tcc8k_init(void)
{
#ifdef CONFIG_MTD_NAND_TCC
tcc_nand_device.dev.platform_data = &tcc8k_sdk_nand_data;
platform_device_register(&tcc_nand_device);
#endif
}
static void __init tcc8k_init_timer(void)
{
tcc_clocks_init(XI_FREQUENCY, XTI_FREQUENCY);
}
static void __init tcc8k_map_io(void)
{
tcc8k_map_common_io();
__raw_writel(0x00026003, CKC_BASE + PLL0CFG_OFFS);
__raw_writel(0x10000001, CKC_BASE + ACLKUART0_OFFS);
__raw_writel(0x00016003, CKC_BASE + PLL1CFG_OFFS);
__raw_writel(0x00036003, CKC_BASE + PLL2CFG_OFFS);
__raw_writel(0x00000001, SCFG_BASE + DTCMWAIT_OFFS);
udelay(300);
}
