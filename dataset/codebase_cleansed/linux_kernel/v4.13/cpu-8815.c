static void __init cpu8815_map_io(void)
{
iotable_init(cpu8815_io_desc, ARRAY_SIZE(cpu8815_io_desc));
}
static void cpu8815_restart(enum reboot_mode mode, const char *cmd)
{
void __iomem *srcbase = ioremap(NOMADIK_SRC_BASE, SZ_4K);
writel(1, srcbase + 0x18);
}
