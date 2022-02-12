static void __init rk3368_clk_init(struct device_node *np)
{
void __iomem *reg_base;
struct clk *clk;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
rockchip_clk_init(np, reg_base, CLK_NR_CLKS);
clk = clk_register_fixed_factor(NULL, "pclk_wdt", "pclk_pd_alive", 0, 1, 1);
if (IS_ERR(clk))
pr_warn("%s: could not register clock pclk_wdt: %ld\n",
__func__, PTR_ERR(clk));
else
rockchip_clk_add_lookup(clk, PCLK_WDT);
rockchip_clk_register_plls(rk3368_pll_clks,
ARRAY_SIZE(rk3368_pll_clks),
RK3368_GRF_SOC_STATUS0);
rockchip_clk_register_branches(rk3368_clk_branches,
ARRAY_SIZE(rk3368_clk_branches));
rockchip_clk_protect_critical(rk3368_critical_clocks,
ARRAY_SIZE(rk3368_critical_clocks));
rockchip_clk_register_armclk(ARMCLKB, "armclkb",
mux_armclkb_p, ARRAY_SIZE(mux_armclkb_p),
&rk3368_cpuclkb_data, rk3368_cpuclkb_rates,
ARRAY_SIZE(rk3368_cpuclkb_rates));
rockchip_clk_register_armclk(ARMCLKL, "armclkl",
mux_armclkl_p, ARRAY_SIZE(mux_armclkl_p),
&rk3368_cpuclkl_data, rk3368_cpuclkl_rates,
ARRAY_SIZE(rk3368_cpuclkl_rates));
rockchip_register_softrst(np, 15, reg_base + RK3368_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(RK3368_GLB_SRST_FST, NULL);
}
