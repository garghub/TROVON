static void __init kzm_init(void)
{
sh73a0_add_standard_devices_dt();
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00400000, 0xc20f0fff);
#endif
}
