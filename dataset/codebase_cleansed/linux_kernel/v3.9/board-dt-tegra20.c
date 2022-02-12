static void __init tegra_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
tegra20_auxdata_lookup, NULL);
}
static void __init trimslice_init(void)
{
#ifdef CONFIG_TEGRA_PCI
int ret;
ret = tegra_pcie_init(true, true);
if (ret)
pr_err("tegra_pci_init() failed: %d\n", ret);
#endif
}
static void __init harmony_init(void)
{
#ifdef CONFIG_TEGRA_PCI
int ret;
ret = harmony_pcie_init();
if (ret)
pr_err("harmony_pcie_init() failed: %d\n", ret);
#endif
}
static void __init paz00_init(void)
{
tegra_paz00_wifikill_init();
}
static void __init tegra_dt_init_late(void)
{
int i;
tegra_init_late();
for (i = 0; i < ARRAY_SIZE(board_init_funcs); i++) {
if (of_machine_is_compatible(board_init_funcs[i].machine)) {
board_init_funcs[i].init();
break;
}
}
}
