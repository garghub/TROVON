static int s5pv210_clk_suspend(void)
{
samsung_clk_save(reg_base, s5pv210_clk_dump,
ARRAY_SIZE(s5pv210_clk_regs));
return 0;
}
static void s5pv210_clk_resume(void)
{
samsung_clk_restore(reg_base, s5pv210_clk_dump,
ARRAY_SIZE(s5pv210_clk_regs));
}
static void s5pv210_clk_sleep_init(void)
{
s5pv210_clk_dump =
samsung_clk_alloc_reg_dump(s5pv210_clk_regs,
ARRAY_SIZE(s5pv210_clk_regs));
if (!s5pv210_clk_dump) {
pr_warn("%s: Failed to allocate sleep save data\n", __func__);
return;
}
register_syscore_ops(&s5pv210_clk_syscore_ops);
}
static inline void s5pv210_clk_sleep_init(void) { }
static void __init __s5pv210_clk_init(struct device_node *np,
unsigned long xxti_f,
unsigned long xusbxti_f,
bool is_s5p6442)
{
struct samsung_clk_provider *ctx;
ctx = samsung_clk_init(np, reg_base, NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
samsung_clk_register_mux(ctx, early_mux_clks,
ARRAY_SIZE(early_mux_clks));
if (is_s5p6442) {
samsung_clk_register_fixed_rate(ctx, s5p6442_frate_clks,
ARRAY_SIZE(s5p6442_frate_clks));
samsung_clk_register_pll(ctx, s5p6442_pll_clks,
ARRAY_SIZE(s5p6442_pll_clks), reg_base);
samsung_clk_register_mux(ctx, s5p6442_mux_clks,
ARRAY_SIZE(s5p6442_mux_clks));
samsung_clk_register_div(ctx, s5p6442_div_clks,
ARRAY_SIZE(s5p6442_div_clks));
samsung_clk_register_gate(ctx, s5p6442_gate_clks,
ARRAY_SIZE(s5p6442_gate_clks));
} else {
samsung_clk_register_fixed_rate(ctx, s5pv210_frate_clks,
ARRAY_SIZE(s5pv210_frate_clks));
samsung_clk_register_pll(ctx, s5pv210_pll_clks,
ARRAY_SIZE(s5pv210_pll_clks), reg_base);
samsung_clk_register_mux(ctx, s5pv210_mux_clks,
ARRAY_SIZE(s5pv210_mux_clks));
samsung_clk_register_div(ctx, s5pv210_div_clks,
ARRAY_SIZE(s5pv210_div_clks));
samsung_clk_register_gate(ctx, s5pv210_gate_clks,
ARRAY_SIZE(s5pv210_gate_clks));
}
samsung_clk_register_mux(ctx, mux_clks, ARRAY_SIZE(mux_clks));
samsung_clk_register_div(ctx, div_clks, ARRAY_SIZE(div_clks));
samsung_clk_register_gate(ctx, gate_clks, ARRAY_SIZE(gate_clks));
samsung_clk_register_fixed_factor(ctx, ffactor_clks,
ARRAY_SIZE(ffactor_clks));
samsung_clk_register_alias(ctx, s5pv210_aliases,
ARRAY_SIZE(s5pv210_aliases));
s5pv210_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
pr_info("%s clocks: mout_apll = %ld, mout_mpll = %ld\n"
"\tmout_epll = %ld, mout_vpll = %ld\n",
is_s5p6442 ? "S5P6442" : "S5PV210",
_get_rate("mout_apll"), _get_rate("mout_mpll"),
_get_rate("mout_epll"), _get_rate("mout_vpll"));
}
static void __init s5pv210_clk_dt_init(struct device_node *np)
{
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
__s5pv210_clk_init(np, 0, 0, false);
}
static void __init s5p6442_clk_dt_init(struct device_node *np)
{
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
__s5pv210_clk_init(np, 0, 0, true);
}
