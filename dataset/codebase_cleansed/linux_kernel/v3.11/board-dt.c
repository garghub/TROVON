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
clkspec.args[0] = CGC_BIT_SDIO;
orion_clkdev_add(NULL, "mvsdio",
of_clk_get_from_provider(&clkspec));
clkspec.args[0] = CGC_BIT_GE0;
clk = of_clk_get_from_provider(&clkspec);
orion_clkdev_add(NULL, "mv643xx_eth_port.0", clk);
clk_prepare_enable(clk);
clkspec.args[0] = CGC_BIT_GE1;
clk = of_clk_get_from_provider(&clkspec);
orion_clkdev_add(NULL, "mv643xx_eth_port.1", clk);
clk_prepare_enable(clk);
}
static void __init kirkwood_of_clk_init(void)
{
of_clk_init(NULL);
kirkwood_legacy_clk_init();
}
static void __init kirkwood_dt_init(void)
{
pr_info("Kirkwood: %s, TCLK=%d.\n", kirkwood_id(), kirkwood_tclk);
writel(readl(CPU_CONFIG) & ~CPU_CONFIG_ERROR_PROP, CPU_CONFIG);
kirkwood_setup_wins();
kirkwood_l2_init();
kirkwood_cpufreq_init();
kirkwood_of_clk_init();
kirkwood_cpuidle_init();
#ifdef CONFIG_KEXEC
kexec_reinit = kirkwood_enable_pcie;
#endif
if (of_machine_is_compatible("globalscale,dreamplug"))
dreamplug_init();
if (of_machine_is_compatible("globalscale,guruplug"))
guruplug_dt_init();
if (of_machine_is_compatible("globalscale,sheevaplug"))
sheevaplug_dt_init();
if (of_machine_is_compatible("dlink,dns-kirkwood"))
dnskw_init();
if (of_machine_is_compatible("iom,iconnect"))
iconnect_init();
if (of_machine_is_compatible("raidsonic,ib-nas62x0"))
ib62x0_init();
if (of_machine_is_compatible("qnap,ts219"))
qnap_dt_ts219_init();
if (of_machine_is_compatible("seagate,dockstar"))
dockstar_dt_init();
if (of_machine_is_compatible("seagate,goflexnet"))
goflexnet_init();
if (of_machine_is_compatible("buffalo,lsxl"))
lsxl_init();
if (of_machine_is_compatible("iom,ix2-200"))
iomega_ix2_200_init();
if (of_machine_is_compatible("keymile,km_kirkwood"))
km_kirkwood_init();
if (of_machine_is_compatible("lacie,cloudbox") ||
of_machine_is_compatible("lacie,inetspace_v2") ||
of_machine_is_compatible("lacie,netspace_lite_v2") ||
of_machine_is_compatible("lacie,netspace_max_v2") ||
of_machine_is_compatible("lacie,netspace_mini_v2") ||
of_machine_is_compatible("lacie,netspace_v2"))
ns2_init();
if (of_machine_is_compatible("marvell,db-88f6281-bp") ||
of_machine_is_compatible("marvell,db-88f6282-bp"))
db88f628x_init();
if (of_machine_is_compatible("mpl,cec4"))
mplcec4_init();
if (of_machine_is_compatible("netgear,readynas-duo-v2"))
netgear_readynas_init();
if (of_machine_is_compatible("plathome,openblocks-a6"))
openblocks_a6_init();
if (of_machine_is_compatible("usi,topkick"))
usi_topkick_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
