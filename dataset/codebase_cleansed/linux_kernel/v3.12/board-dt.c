static void __init kirkwood_legacy_clk_init(void)
{
struct device_node *np = of_find_compatible_node(
NULL, NULL, "marvell,kirkwood-gating-clock");
struct of_phandle_args clkspec;
struct clk *clk;
clkspec.np = np;
clkspec.args_count = 1;
clkspec.args[0] = CGC_BIT_PEX0;
orion_clkdev_add("0", "pcie",
of_clk_get_from_provider(&clkspec));
clkspec.args[0] = CGC_BIT_PEX1;
orion_clkdev_add("1", "pcie",
of_clk_get_from_provider(&clkspec));
clkspec.args[0] = CGC_BIT_GE0;
clk = of_clk_get_from_provider(&clkspec);
clk_prepare_enable(clk);
clkspec.args[0] = CGC_BIT_GE1;
clk = of_clk_get_from_provider(&clkspec);
clk_prepare_enable(clk);
}
static void __init kirkwood_dt_time_init(void)
{
of_clk_init(NULL);
clocksource_of_init();
}
static void __init kirkwood_dt_init_early(void)
{
mvebu_mbus_init("marvell,kirkwood-mbus",
BRIDGE_WINS_BASE, BRIDGE_WINS_SZ,
DDR_WINDOW_CPU_BASE, DDR_WINDOW_CPU_SZ);
}
static void __init kirkwood_dt_init(void)
{
pr_info("Kirkwood: %s, TCLK=%d.\n", kirkwood_id(), kirkwood_tclk);
writel(readl(CPU_CONFIG) & ~CPU_CONFIG_ERROR_PROP, CPU_CONFIG);
BUG_ON(mvebu_mbus_dt_init());
kirkwood_setup_wins();
kirkwood_l2_init();
kirkwood_cpufreq_init();
kirkwood_legacy_clk_init();
kirkwood_cpuidle_init();
#ifdef CONFIG_KEXEC
kexec_reinit = kirkwood_enable_pcie;
#endif
if (of_machine_is_compatible("marvell,mv88f6281gtw-ge"))
mv88f6281gtw_ge_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
