static void __init nspire_map_io(void)
{
debug_ll_io_init();
}
static void __init nspire_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
nspire_auxdata, NULL);
}
static void __init nspire_init_time(void)
{
of_clk_init(NULL);
clocksource_of_init();
}
static void nspire_restart(char mode, const char *cmd)
{
void __iomem *base = ioremap(NSPIRE_MISC_PHYS_BASE, SZ_4K);
if (!base)
return;
writel(2, base + NSPIRE_MISC_HWRESET);
}
