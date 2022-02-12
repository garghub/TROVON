static void __init rk3399_clk_init(struct device_node *np)
{
struct rockchip_clk_provider *ctx;
void __iomem *reg_base;
struct clk *clk;
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
clk = clk_register_fixed_factor(NULL, "pclk_wdt", "pclk_alive", 0, 1, 1);
if (IS_ERR(clk))
pr_warn("%s: could not register clock pclk_wdt: %ld\n",
__func__, PTR_ERR(clk));
else
rockchip_clk_add_lookup(ctx, clk, PCLK_WDT);
rockchip_clk_register_plls(ctx, rk3399_pll_clks,
ARRAY_SIZE(rk3399_pll_clks), -1);
rockchip_clk_register_branches(ctx, rk3399_clk_branches,
ARRAY_SIZE(rk3399_clk_branches));
rockchip_clk_protect_critical(rk3399_cru_critical_clocks,
ARRAY_SIZE(rk3399_cru_critical_clocks));
rockchip_clk_register_armclk(ctx, ARMCLKL, "armclkl",
mux_armclkl_p, ARRAY_SIZE(mux_armclkl_p),
&rk3399_cpuclkl_data, rk3399_cpuclkl_rates,
ARRAY_SIZE(rk3399_cpuclkl_rates));
rockchip_clk_register_armclk(ctx, ARMCLKB, "armclkb",
mux_armclkb_p, ARRAY_SIZE(mux_armclkb_p),
&rk3399_cpuclkb_data, rk3399_cpuclkb_rates,
ARRAY_SIZE(rk3399_cpuclkb_rates));
rockchip_register_softrst(np, 21, reg_base + RK3399_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(ctx, RK3399_GLB_SRST_FST, NULL);
rockchip_clk_of_add_provider(np, ctx);
}
static void __init rk3399_pmu_clk_init(struct device_node *np)
{
struct rockchip_clk_provider *ctx;
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru pmu region\n", __func__);
return;
}
ctx = rockchip_clk_init(np, reg_base, CLKPMU_NR_CLKS);
if (IS_ERR(ctx)) {
pr_err("%s: rockchip pmu clk init failed\n", __func__);
iounmap(reg_base);
return;
}
rockchip_clk_register_plls(ctx, rk3399_pmu_pll_clks,
ARRAY_SIZE(rk3399_pmu_pll_clks), -1);
rockchip_clk_register_branches(ctx, rk3399_clk_pmu_branches,
ARRAY_SIZE(rk3399_clk_pmu_branches));
rockchip_clk_protect_critical(rk3399_pmucru_critical_clocks,
ARRAY_SIZE(rk3399_pmucru_critical_clocks));
rockchip_register_softrst(np, 2, reg_base + RK3399_PMU_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_clk_of_add_provider(np, ctx);
}
