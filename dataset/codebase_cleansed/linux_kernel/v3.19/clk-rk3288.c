static int rk3288_clk_suspend(void)
{
int i, reg_id;
for (i = 0; i < ARRAY_SIZE(rk3288_saved_cru_reg_ids); i++) {
reg_id = rk3288_saved_cru_reg_ids[i];
rk3288_saved_cru_regs[i] =
readl_relaxed(rk3288_cru_base + reg_id);
}
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
static void rk3288_clk_sleep_init(void __iomem *reg_base)
{
rk3288_cru_base = reg_base;
register_syscore_ops(&rk3288_clk_syscore_ops);
}
static void rk3288_clk_sleep_init(void __iomem *reg_base) {}
static void __init rk3288_clk_init(struct device_node *np)
{
void __iomem *reg_base;
struct clk *clk;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
rockchip_clk_init(np, reg_base, CLK_NR_CLKS);
clk = clk_register_fixed_factor(NULL, "xin12m", "xin24m", 0, 1, 2);
if (IS_ERR(clk))
pr_warn("%s: could not register clock xin12m: %ld\n",
__func__, PTR_ERR(clk));
clk = clk_register_fixed_factor(NULL, "usb480m", "xin24m", 0, 20, 1);
if (IS_ERR(clk))
pr_warn("%s: could not register clock usb480m: %ld\n",
__func__, PTR_ERR(clk));
clk = clk_register_fixed_factor(NULL, "hclk_vcodec_pre",
"hclk_vcodec_pre_v", 0, 1, 4);
if (IS_ERR(clk))
pr_warn("%s: could not register clock hclk_vcodec_pre: %ld\n",
__func__, PTR_ERR(clk));
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
rockchip_register_softrst(np, 12, reg_base + RK3288_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(RK3288_GLB_SRST_FST);
rk3288_clk_sleep_init(reg_base);
}
