static void __init kirkwood_legacy_clk_init(void)
{
struct device_node *np = of_find_compatible_node(
NULL, NULL, "marvell,kirkwood-gating-clock");
struct of_phandle_args clkspec;
struct clk *clk;
clkspec.np = np;
clkspec.args_count = 1;
clkspec.args[0] = CGC_BIT_GE0;
clk = of_clk_get_from_provider(&clkspec);
clk_prepare_enable(clk);
clkspec.args[0] = CGC_BIT_GE1;
clk = of_clk_get_from_provider(&clkspec);
clk_prepare_enable(clk);
}
static void __init kirkwood_dt_eth_fixup(void)
{
struct device_node *np;
for_each_compatible_node(np, NULL, "marvell,kirkwood-eth-port") {
struct device_node *pnp = of_get_parent(np);
struct clk *clk;
struct property *pmac;
void __iomem *io;
u8 *macaddr;
u32 reg;
if (!pnp)
continue;
if (!of_device_is_available(pnp) || of_get_mac_address(np))
goto eth_fixup_skip;
clk = of_clk_get(pnp, 0);
if (IS_ERR(clk))
goto eth_fixup_skip;
io = of_iomap(pnp, 0);
if (!io)
goto eth_fixup_no_map;
clk_prepare_enable(clk);
pr_err(FW_INFO "%s: local-mac-address is not set\n",
np->full_name);
pmac = kzalloc(sizeof(*pmac) + 6, GFP_KERNEL);
if (!pmac)
goto eth_fixup_no_mem;
pmac->value = pmac + 1;
pmac->length = 6;
pmac->name = kstrdup("local-mac-address", GFP_KERNEL);
if (!pmac->name) {
kfree(pmac);
goto eth_fixup_no_mem;
}
macaddr = pmac->value;
reg = readl(io + MV643XX_ETH_MAC_ADDR_HIGH);
macaddr[0] = (reg >> 24) & 0xff;
macaddr[1] = (reg >> 16) & 0xff;
macaddr[2] = (reg >> 8) & 0xff;
macaddr[3] = reg & 0xff;
reg = readl(io + MV643XX_ETH_MAC_ADDR_LOW);
macaddr[4] = (reg >> 8) & 0xff;
macaddr[5] = reg & 0xff;
of_update_property(np, pmac);
eth_fixup_no_mem:
iounmap(io);
clk_disable_unprepare(clk);
eth_fixup_no_map:
clk_put(clk);
eth_fixup_skip:
of_node_put(pnp);
}
}
static void __init kirkwood_dt_init(void)
{
pr_info("Kirkwood: %s, TCLK=%d.\n", kirkwood_id(), kirkwood_tclk);
writel(readl(CPU_CONFIG) & ~CPU_CONFIG_ERROR_PROP, CPU_CONFIG);
BUG_ON(mvebu_mbus_dt_init());
kirkwood_l2_init();
kirkwood_cpufreq_init();
kirkwood_cpuidle_init();
kirkwood_legacy_clk_init();
kirkwood_pm_init();
kirkwood_dt_eth_fixup();
#ifdef CONFIG_KEXEC
kexec_reinit = kirkwood_enable_pcie;
#endif
if (of_machine_is_compatible("marvell,mv88f6281gtw-ge"))
mv88f6281gtw_ge_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
