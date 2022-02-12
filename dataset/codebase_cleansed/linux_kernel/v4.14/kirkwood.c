static void __init kirkwood_cpufreq_init(void)
{
platform_device_register(&kirkwood_cpufreq_device);
}
static void __init kirkwood_cpuidle_init(void)
{
platform_device_register(&kirkwood_cpuidle);
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
pr_err(FW_INFO "%pOF: local-mac-address is not set\n", np);
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
static void kirkwood_disable_mbus_error_propagation(void)
{
void __iomem *cpu_config;
cpu_config = ioremap(CPU_CONFIG_PHYS, 4);
writel(readl(cpu_config) & ~CPU_CONFIG_ERROR_PROP, cpu_config);
}
static void __init kirkwood_dt_init(void)
{
kirkwood_disable_mbus_error_propagation();
BUG_ON(mvebu_mbus_dt_init(false));
#ifdef CONFIG_CACHE_FEROCEON_L2
feroceon_of_init();
#endif
kirkwood_cpufreq_init();
kirkwood_cpuidle_init();
kirkwood_pm_init();
kirkwood_dt_eth_fixup();
of_platform_default_populate(NULL, auxdata, NULL);
}
