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
static void exynos4_clk_sleep_init(void)
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
static void exynos4_clk_sleep_init(void) {}
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
static void __init exynos4_clk_register_finpll(void)
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
fclk.flags = CLK_IS_ROOT;
fclk.fixed_rate = finpll_f;
samsung_clk_register_fixed_rate(&fclk, 1);
}
static void __init exynos4_clk_init(struct device_node *np,
enum exynos4_soc soc)
{
exynos4_soc = soc;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
samsung_clk_init(np, reg_base, CLK_NR_CLKS);
samsung_clk_of_register_fixed_ext(exynos4_fixed_rate_ext_clks,
ARRAY_SIZE(exynos4_fixed_rate_ext_clks),
ext_clk_match);
exynos4_clk_register_finpll();
if (exynos4_soc == EXYNOS4210) {
samsung_clk_register_mux(exynos4210_mux_early,
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
samsung_clk_register_pll(exynos4210_plls,
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
samsung_clk_register_pll(exynos4x12_plls,
ARRAY_SIZE(exynos4x12_plls), reg_base);
}
samsung_clk_register_fixed_rate(exynos4_fixed_rate_clks,
ARRAY_SIZE(exynos4_fixed_rate_clks));
samsung_clk_register_mux(exynos4_mux_clks,
ARRAY_SIZE(exynos4_mux_clks));
samsung_clk_register_div(exynos4_div_clks,
ARRAY_SIZE(exynos4_div_clks));
samsung_clk_register_gate(exynos4_gate_clks,
ARRAY_SIZE(exynos4_gate_clks));
if (exynos4_soc == EXYNOS4210) {
samsung_clk_register_fixed_rate(exynos4210_fixed_rate_clks,
ARRAY_SIZE(exynos4210_fixed_rate_clks));
samsung_clk_register_mux(exynos4210_mux_clks,
ARRAY_SIZE(exynos4210_mux_clks));
samsung_clk_register_div(exynos4210_div_clks,
ARRAY_SIZE(exynos4210_div_clks));
samsung_clk_register_gate(exynos4210_gate_clks,
ARRAY_SIZE(exynos4210_gate_clks));
samsung_clk_register_alias(exynos4210_aliases,
ARRAY_SIZE(exynos4210_aliases));
} else {
samsung_clk_register_mux(exynos4x12_mux_clks,
ARRAY_SIZE(exynos4x12_mux_clks));
samsung_clk_register_div(exynos4x12_div_clks,
ARRAY_SIZE(exynos4x12_div_clks));
samsung_clk_register_gate(exynos4x12_gate_clks,
ARRAY_SIZE(exynos4x12_gate_clks));
samsung_clk_register_alias(exynos4x12_aliases,
ARRAY_SIZE(exynos4x12_aliases));
}
samsung_clk_register_alias(exynos4_aliases,
ARRAY_SIZE(exynos4_aliases));
exynos4_clk_sleep_init();
pr_info("%s clocks: sclk_apll = %ld, sclk_mpll = %ld\n"
"\tsclk_epll = %ld, sclk_vpll = %ld, arm_clk = %ld\n",
exynos4_soc == EXYNOS4210 ? "Exynos4210" : "Exynos4x12",
_get_rate("sclk_apll"), _get_rate("sclk_mpll"),
_get_rate("sclk_epll"), _get_rate("sclk_vpll"),
_get_rate("arm_clk"));
}
static void __init exynos4210_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4210);
}
static void __init exynos4412_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4X12);
}
