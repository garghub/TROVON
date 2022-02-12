static void __init rk1108_clk_init(struct device_node *np)
{
struct rockchip_clk_provider *ctx;
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
ctx = rockchip_clk_init(np, reg_base, CLK_NR_CLKS);
if (IS_ERR(ctx)) {
pr_err("%s: rockchip clk init failed\n", __func__);
iounmap(reg_base);
return;
}
rockchip_clk_register_plls(ctx, rk1108_pll_clks,
ARRAY_SIZE(rk1108_pll_clks),
RK1108_GRF_SOC_STATUS0);
rockchip_clk_register_branches(ctx, rk1108_clk_branches,
ARRAY_SIZE(rk1108_clk_branches));
rockchip_clk_protect_critical(rk1108_critical_clocks,
ARRAY_SIZE(rk1108_critical_clocks));
rockchip_clk_register_armclk(ctx, ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk1108_cpuclk_data, rk1108_cpuclk_rates,
ARRAY_SIZE(rk1108_cpuclk_rates));
rockchip_register_softrst(np, 13, reg_base + RK1108_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(ctx, RK1108_GLB_SRST_FST, NULL);
rockchip_clk_of_add_provider(np, ctx);
}
