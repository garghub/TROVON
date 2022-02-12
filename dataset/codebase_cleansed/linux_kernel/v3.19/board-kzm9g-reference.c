static void __init kzm_init(void)
{
sh73a0_add_standard_devices_dt();
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00400000, 0xc20f0fff);
#endif
}
static void kzm9g_restart(enum reboot_mode mode, const char *cmd)
{
writel((1 << 31), RESCNT2);
}
