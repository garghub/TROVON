static void __init rk3228_clk_init(struct device_node *np)
{
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
rockchip_clk_init(np, reg_base, CLK_NR_CLKS);
rockchip_clk_register_plls(rk3228_pll_clks,
ARRAY_SIZE(rk3228_pll_clks),
RK3228_GRF_SOC_STATUS0);
rockchip_clk_register_branches(rk3228_clk_branches,
ARRAY_SIZE(rk3228_clk_branches));
rockchip_clk_protect_critical(rk3228_critical_clocks,
ARRAY_SIZE(rk3228_critical_clocks));
rockchip_clk_register_armclk(ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk3228_cpuclk_data, rk3228_cpuclk_rates,
ARRAY_SIZE(rk3228_cpuclk_rates));
rockchip_register_softrst(np, 9, reg_base + RK2928_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(RK3228_GLB_SRST_FST, NULL);
}
