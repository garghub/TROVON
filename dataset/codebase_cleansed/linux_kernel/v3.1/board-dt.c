static void __init tegra_dt_init(void)
{
struct device_node *node;
node = of_find_matching_node_by_address(NULL, tegra_dt_gic_match,
TEGRA_ARM_INT_DIST_BASE);
if (node)
irq_domain_add_simple(node, INT_GIC_BASE);
tegra_clk_init_from_table(tegra_dt_clk_init_table);
if (of_machine_is_compatible("nvidia,harmony"))
harmony_pinmux_init();
else if (of_machine_is_compatible("nvidia,seaboard"))
seaboard_pinmux_init();
of_platform_populate(NULL, tegra_dt_match_table, tegra20_auxdata_lookup, NULL);
}
