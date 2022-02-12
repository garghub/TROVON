static void exynos4_clk_wait_for_pll(u32 reg)
{
u32 pll_con;
pll_con = readl(reg_base + reg);
if (!(pll_con & PLL_ENABLED))
return;
while (!(pll_con & PLL_LOCKED)) {
cpu_relax();
pll_con = readl(reg_base + reg);
}
}
static int exynos4_clk_suspend(void)
{
samsung_clk_save(reg_base, exynos4_save_common,
ARRAY_SIZE(exynos4_clk_regs));
samsung_clk_save(reg_base, exynos4_save_pll,
ARRAY_SIZE(exynos4_clk_pll_regs));
if (exynos4_soc == EXYNOS4210) {
samsung_clk_save(reg_base, exynos4_save_soc,
ARRAY_SIZE(exynos4210_clk_save));
samsung_clk_restore(reg_base, src_mask_suspend_e4210,
ARRAY_SIZE(src_mask_suspend_e4210));
} else {
samsung_clk_save(reg_base, exynos4_save_soc,
ARRAY_SIZE(exynos4x12_clk_save));
}
samsung_clk_restore(reg_base, src_mask_suspend,
ARRAY_SIZE(src_mask_suspend));
return 0;
}
static void exynos4_clk_resume(void)
{
samsung_clk_restore(reg_base, exynos4_save_pll,
ARRAY_SIZE(exynos4_clk_pll_regs));
exynos4_clk_wait_for_pll(EPLL_CON0);
exynos4_clk_wait_for_pll(VPLL_CON0);
samsung_clk_restore(reg_base, exynos4_save_common,
ARRAY_SIZE(exynos4_clk_regs));
if (exynos4_soc == EXYNOS4210)
samsung_clk_restore(reg_base, exynos4_save_soc,
ARRAY_SIZE(exynos4210_clk_save));
else
samsung_clk_restore(reg_base, exynos4_save_soc,
ARRAY_SIZE(exynos4x12_clk_save));
}
static void __init exynos4_clk_sleep_init(void)
{
exynos4_save_common = samsung_clk_alloc_reg_dump(exynos4_clk_regs,
ARRAY_SIZE(exynos4_clk_regs));
if (!exynos4_save_common)
goto err_warn;
if (exynos4_soc == EXYNOS4210)
exynos4_save_soc = samsung_clk_alloc_reg_dump(
exynos4210_clk_save,
ARRAY_SIZE(exynos4210_clk_save));
else
exynos4_save_soc = samsung_clk_alloc_reg_dump(
exynos4x12_clk_save,
ARRAY_SIZE(exynos4x12_clk_save));
if (!exynos4_save_soc)
goto err_common;
exynos4_save_pll = samsung_clk_alloc_reg_dump(exynos4_clk_pll_regs,
ARRAY_SIZE(exynos4_clk_pll_regs));
if (!exynos4_save_pll)
goto err_soc;
register_syscore_ops(&exynos4_clk_syscore_ops);
return;
err_soc:
kfree(exynos4_save_soc);
err_common:
kfree(exynos4_save_common);
err_warn:
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
}
static void __init exynos4_clk_sleep_init(void) {}
static unsigned long exynos4_get_xom(void)
{
unsigned long xom = 0;
void __iomem *chipid_base;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "samsung,exynos4210-chipid");
if (np) {
chipid_base = of_iomap(np, 0);
if (chipid_base)
xom = readl(chipid_base + 8);
iounmap(chipid_base);
}
return xom;
}
static void __init exynos4_clk_register_finpll(struct samsung_clk_provider *ctx)
{
struct samsung_fixed_rate_clock fclk;
struct clk *clk;
unsigned long finpll_f = 24000000;
char *parent_name;
unsigned int xom = exynos4_get_xom();
parent_name = xom & 1 ? "xusbxti" : "xxti";
clk = clk_get(NULL, parent_name);
if (IS_ERR(clk)) {
pr_err("%s: failed to lookup parent clock %s, assuming "
"fin_pll clock frequency is 24MHz\n", __func__,
parent_name);
} else {
finpll_f = clk_get_rate(clk);
}
fclk.id = CLK_FIN_PLL;
fclk.name = "fin_pll";
fclk.parent_name = NULL;
fclk.flags = 0;
fclk.fixed_rate = finpll_f;
samsung_clk_register_fixed_rate(ctx, &fclk, 1);
}
static void __init exynos4x12_core_down_clock(void)
{
unsigned int tmp;
tmp = (PWR_CTRL1_CORE2_DOWN_RATIO(7) | PWR_CTRL1_CORE1_DOWN_RATIO(7) |
PWR_CTRL1_DIV2_DOWN_EN | PWR_CTRL1_DIV1_DOWN_EN |
PWR_CTRL1_USE_CORE1_WFE | PWR_CTRL1_USE_CORE0_WFE |
PWR_CTRL1_USE_CORE1_WFI | PWR_CTRL1_USE_CORE0_WFI);
if (num_possible_cpus() == 4)
tmp |= PWR_CTRL1_USE_CORE3_WFE | PWR_CTRL1_USE_CORE2_WFE |
PWR_CTRL1_USE_CORE3_WFI | PWR_CTRL1_USE_CORE2_WFI;
__raw_writel(tmp, reg_base + PWR_CTRL1);
__raw_writel(0x0, reg_base + E4X12_PWR_CTRL2);
}
static void __init exynos4_clk_init(struct device_node *np,
enum exynos4_soc soc)
{
struct samsung_clk_provider *ctx;
exynos4_soc = soc;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
samsung_clk_of_register_fixed_ext(ctx, exynos4_fixed_rate_ext_clks,
ARRAY_SIZE(exynos4_fixed_rate_ext_clks),
ext_clk_match);
exynos4_clk_register_finpll(ctx);
if (exynos4_soc == EXYNOS4210) {
samsung_clk_register_mux(ctx, exynos4210_mux_early,
ARRAY_SIZE(exynos4210_mux_early));
if (_get_rate("fin_pll") == 24000000) {
exynos4210_plls[apll].rate_table =
exynos4210_apll_rates;
exynos4210_plls[epll].rate_table =
exynos4210_epll_rates;
}
if (_get_rate("mout_vpllsrc") == 24000000)
exynos4210_plls[vpll].rate_table =
exynos4210_vpll_rates;
samsung_clk_register_pll(ctx, exynos4210_plls,
ARRAY_SIZE(exynos4210_plls), reg_base);
} else {
if (_get_rate("fin_pll") == 24000000) {
exynos4x12_plls[apll].rate_table =
exynos4x12_apll_rates;
exynos4x12_plls[epll].rate_table =
exynos4x12_epll_rates;
exynos4x12_plls[vpll].rate_table =
exynos4x12_vpll_rates;
}
samsung_clk_register_pll(ctx, exynos4x12_plls,
ARRAY_SIZE(exynos4x12_plls), reg_base);
}
samsung_clk_register_fixed_rate(ctx, exynos4_fixed_rate_clks,
ARRAY_SIZE(exynos4_fixed_rate_clks));
samsung_clk_register_mux(ctx, exynos4_mux_clks,
ARRAY_SIZE(exynos4_mux_clks));
samsung_clk_register_div(ctx, exynos4_div_clks,
ARRAY_SIZE(exynos4_div_clks));
samsung_clk_register_gate(ctx, exynos4_gate_clks,
ARRAY_SIZE(exynos4_gate_clks));
samsung_clk_register_fixed_factor(ctx, exynos4_fixed_factor_clks,
ARRAY_SIZE(exynos4_fixed_factor_clks));
if (exynos4_soc == EXYNOS4210) {
samsung_clk_register_fixed_rate(ctx, exynos4210_fixed_rate_clks,
ARRAY_SIZE(exynos4210_fixed_rate_clks));
samsung_clk_register_mux(ctx, exynos4210_mux_clks,
ARRAY_SIZE(exynos4210_mux_clks));
samsung_clk_register_div(ctx, exynos4210_div_clks,
ARRAY_SIZE(exynos4210_div_clks));
samsung_clk_register_gate(ctx, exynos4210_gate_clks,
ARRAY_SIZE(exynos4210_gate_clks));
samsung_clk_register_alias(ctx, exynos4210_aliases,
ARRAY_SIZE(exynos4210_aliases));
samsung_clk_register_fixed_factor(ctx,
exynos4210_fixed_factor_clks,
ARRAY_SIZE(exynos4210_fixed_factor_clks));
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_core_p4210[0], mout_core_p4210[1], 0x14200,
e4210_armclk_d, ARRAY_SIZE(e4210_armclk_d),
CLK_CPU_NEEDS_DEBUG_ALT_DIV | CLK_CPU_HAS_DIV1);
} else {
samsung_clk_register_mux(ctx, exynos4x12_mux_clks,
ARRAY_SIZE(exynos4x12_mux_clks));
samsung_clk_register_div(ctx, exynos4x12_div_clks,
ARRAY_SIZE(exynos4x12_div_clks));
samsung_clk_register_gate(ctx, exynos4x12_gate_clks,
ARRAY_SIZE(exynos4x12_gate_clks));
samsung_clk_register_alias(ctx, exynos4x12_aliases,
ARRAY_SIZE(exynos4x12_aliases));
samsung_clk_register_fixed_factor(ctx,
exynos4x12_fixed_factor_clks,
ARRAY_SIZE(exynos4x12_fixed_factor_clks));
if (of_machine_is_compatible("samsung,exynos4412")) {
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_core_p4x12[0], mout_core_p4x12[1], 0x14200,
e4412_armclk_d, ARRAY_SIZE(e4412_armclk_d),
CLK_CPU_NEEDS_DEBUG_ALT_DIV | CLK_CPU_HAS_DIV1);
} else {
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_core_p4x12[0], mout_core_p4x12[1], 0x14200,
e4212_armclk_d, ARRAY_SIZE(e4212_armclk_d),
CLK_CPU_NEEDS_DEBUG_ALT_DIV | CLK_CPU_HAS_DIV1);
}
}
samsung_clk_register_alias(ctx, exynos4_aliases,
ARRAY_SIZE(exynos4_aliases));
if (soc == EXYNOS4X12)
exynos4x12_core_down_clock();
exynos4_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
pr_info("%s clocks: sclk_apll = %ld, sclk_mpll = %ld\n"
"\tsclk_epll = %ld, sclk_vpll = %ld, arm_clk = %ld\n",
exynos4_soc == EXYNOS4210 ? "Exynos4210" : "Exynos4x12",
_get_rate("sclk_apll"), _get_rate("sclk_mpll"),
_get_rate("sclk_epll"), _get_rate("sclk_vpll"),
_get_rate("div_core2"));
}
static void __init exynos4210_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4210);
}
static void __init exynos4412_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4X12);
}
