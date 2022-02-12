static void __init sh73a0_map_io(void)
{
debug_ll_io_init();
iotable_init(sh73a0_io_desc, ARRAY_SIZE(sh73a0_io_desc));
}
static void __init sh73a0_generic_init(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00400000, 0xc20f0fff);
#endif
}
