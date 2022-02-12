static void __init hi3620_clk_init(struct device_node *np)
{
void __iomem *base;
if (np) {
base = of_iomap(np, 0);
if (!base) {
pr_err("failed to map Hi3620 clock registers\n");
return;
}
} else {
pr_err("failed to find Hi3620 clock node in DTS\n");
return;
}
hisi_clk_init(np, HI3620_NR_CLKS);
hisi_clk_register_fixed_rate(hi3620_fixed_rate_clks,
ARRAY_SIZE(hi3620_fixed_rate_clks),
base);
hisi_clk_register_fixed_factor(hi3620_fixed_factor_clks,
ARRAY_SIZE(hi3620_fixed_factor_clks),
base);
hisi_clk_register_mux(hi3620_mux_clks, ARRAY_SIZE(hi3620_mux_clks),
base);
hisi_clk_register_divider(hi3620_div_clks, ARRAY_SIZE(hi3620_div_clks),
base);
hisi_clk_register_gate_sep(hi3620_seperated_gate_clks,
ARRAY_SIZE(hi3620_seperated_gate_clks),
base);
}
