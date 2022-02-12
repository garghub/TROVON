static void __init nspire_map_io(void)
{
debug_ll_io_init();
}
static void __init nspire_init(void)
{
of_platform_default_populate(NULL, nspire_auxdata, NULL);
}
static void nspire_restart(enum reboot_mode mode, const char *cmd)
{
void __iomem *base = ioremap(NSPIRE_MISC_PHYS_BASE, SZ_4K);
if (!base)
return;
writel(2, base + NSPIRE_MISC_HWRESET);
}
