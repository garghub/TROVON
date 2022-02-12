static void __init rk3036_clk_init(struct device_node *np)
{
struct rockchip_clk_provider *ctx;
void __iomem *reg_base;
struct clk *clk;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: could not map cru region\n", __func__);
return;
}
writel_relaxed(HIWORD_UPDATE(0x2, 0x3, 10),
reg_base + RK2928_CLKSEL_CON(13));
ctx = rockchip_clk_init(np, reg_base, CLK_NR_CLKS);
if (IS_ERR(ctx)) {
pr_err("%s: rockchip clk init failed\n", __func__);
iounmap(reg_base);
return;
}
clk = clk_register_fixed_factor(NULL, "usb480m", "xin24m", 0, 20, 1);
if (IS_ERR(clk))
pr_warn("%s: could not register clock usb480m: %ld\n",
__func__, PTR_ERR(clk));
rockchip_clk_register_plls(ctx, rk3036_pll_clks,
ARRAY_SIZE(rk3036_pll_clks),
RK3036_GRF_SOC_STATUS0);
rockchip_clk_register_branches(ctx, rk3036_clk_branches,
ARRAY_SIZE(rk3036_clk_branches));
rockchip_clk_protect_critical(rk3036_critical_clocks,
ARRAY_SIZE(rk3036_critical_clocks));
rockchip_clk_register_armclk(ctx, ARMCLK, "armclk",
mux_armclk_p, ARRAY_SIZE(mux_armclk_p),
&rk3036_cpuclk_data, rk3036_cpuclk_rates,
ARRAY_SIZE(rk3036_cpuclk_rates));
rockchip_register_softrst(np, 9, reg_base + RK2928_SOFTRST_CON(0),
ROCKCHIP_SOFTRST_HIWORD_MASK);
rockchip_register_restart_notifier(ctx, RK2928_GLB_SRST_FST, NULL);
rockchip_clk_of_add_provider(np, ctx);
}
