static int rk3288_clk_suspend(void)
{
int i, reg_id;
for (i = 0; i < ARRAY_SIZE(rk3288_saved_cru_reg_ids); i++) {
reg_id = rk3288_saved_cru_reg_ids[i];
rk3288_saved_cru_regs[i] =
readl_relaxed(rk3288_cru_base + reg_id);
}
writel_relaxed(0xf3030000, rk3288_cru_base + RK3288_MODE_CON);
return 0;
}
static void rk3288_clk_resume(void)
{
int i, reg_id;
for (i = ARRAY_SIZE(rk3288_saved_cru_reg_ids) - 1; i >= 0; i--) {
reg_id = rk3288_saved_cru_reg_ids[i];
writel_relaxed(rk3288_saved_cru_regs[i] | 0xffff0000,
rk3288_cru_base + reg_id);
}
}
static void rk3288_clk_shutdown(void)
{
writel_relaxed(0xf3030000, rk3288_cru_base + RK3288_MODE_CON);
}
static void __init rk3288_clk_init(struct device_node *np)
{
struct clk *clk;
rk3288_cru_base = of_iomap(np, 0);
if (!rk3288_cru_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
rockchip_clk_init(np, rk3288_cru_base, CLK_NR_CLKS);
clk = clk_register_fixed_factor(NULL, "pclk_wdt", "pclk_pd_alive", 0, 1, 1);
if (IS_ERR(clk))
pr_warn("%s: could not register clock pclk_wdt: %ld\n",
__func__, PTR_ERR(clk));
else
rockchip_clk_add_lookup(clk, PCLK_WDT);
rockchip_clk_register_plls(rk3288_pll_clks,
ARRAY_SIZE(rk3288_pll_clks),
RK3288_GRF_SOC_STATUS1);
rockchip_clk_register_branches(rk3288_clk_branches,
ARRAY_SIZE(rk3288_clk_branches));
rockchip_clk_protect_critical(rk3288_critical_clocks,
ARRAY_SIZE(rk3288_critical_clocks));
rockchip_clk_register_armclk(ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk3288_cpuclk_data, rk3288_cpuclk_rates,
ARRAY_SIZE(rk3288_cpuclk_rates));
rockchip_register_softrst(np, 12,
rk3288_cru_base + RK3288_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(RK3288_GLB_SRST_FST,
rk3288_clk_shutdown);
register_syscore_ops(&rk3288_clk_syscore_ops);
}
