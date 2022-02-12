static void __init rk3188_common_clk_init(struct device_node *np)
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
rockchip_clk_register_branches(common_clk_branches,
ARRAY_SIZE(common_clk_branches));
rockchip_register_softrst(np, 9, reg_base + RK2928_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(RK2928_GLB_SRST_FST, NULL);
}
static void __init rk3066a_clk_init(struct device_node *np)
{
rk3188_common_clk_init(np);
rockchip_clk_register_plls(rk3066_pll_clks,
ARRAY_SIZE(rk3066_pll_clks),
RK3066_GRF_SOC_STATUS);
rockchip_clk_register_branches(rk3066a_clk_branches,
ARRAY_SIZE(rk3066a_clk_branches));
rockchip_clk_register_armclk(ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk3066_cpuclk_data, rk3066_cpuclk_rates,
ARRAY_SIZE(rk3066_cpuclk_rates));
rockchip_clk_protect_critical(rk3188_critical_clocks,
ARRAY_SIZE(rk3188_critical_clocks));
}
static void __init rk3188a_clk_init(struct device_node *np)
{
struct clk *clk1, *clk2;
unsigned long rate;
int ret;
rk3188_common_clk_init(np);
rockchip_clk_register_plls(rk3188_pll_clks,
ARRAY_SIZE(rk3188_pll_clks),
RK3188_GRF_SOC_STATUS);
rockchip_clk_register_branches(rk3188_clk_branches,
ARRAY_SIZE(rk3188_clk_branches));
rockchip_clk_register_armclk(ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk3188_cpuclk_data, rk3188_cpuclk_rates,
ARRAY_SIZE(rk3188_cpuclk_rates));
clk1 = __clk_lookup("aclk_cpu_pre");
clk2 = __clk_lookup("gpll");
if (clk1 && clk2) {
rate = clk_get_rate(clk1);
ret = clk_set_parent(clk1, clk2);
if (ret < 0)
pr_warn("%s: could not reparent aclk_cpu_pre to gpll\n",
__func__);
clk_set_rate(clk1, rate);
} else {
pr_warn("%s: missing clocks to reparent aclk_cpu_pre to gpll\n",
__func__);
}
rockchip_clk_protect_critical(rk3188_critical_clocks,
ARRAY_SIZE(rk3188_critical_clocks));
}
static void __init rk3188_clk_init(struct device_node *np)
{
int i;
for (i = 0; i < ARRAY_SIZE(rk3188_pll_clks); i++) {
struct rockchip_pll_clock *pll = &rk3188_pll_clks[i];
struct rockchip_pll_rate_table *rate;
if (!pll->rate_table)
continue;
rate = pll->rate_table;
while (rate->rate > 0) {
rate->nb = 1;
rate++;
}
}
rk3188a_clk_init(np);
}
