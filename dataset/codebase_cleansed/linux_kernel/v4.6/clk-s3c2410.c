static int s3c2410_clk_suspend(void)
{
samsung_clk_save(reg_base, s3c2410_save,
ARRAY_SIZE(s3c2410_clk_regs));
return 0;
}
static void s3c2410_clk_resume(void)
{
samsung_clk_restore(reg_base, s3c2410_save,
ARRAY_SIZE(s3c2410_clk_regs));
}
static void s3c2410_clk_sleep_init(void)
{
s3c2410_save = samsung_clk_alloc_reg_dump(s3c2410_clk_regs,
ARRAY_SIZE(s3c2410_clk_regs));
if (!s3c2410_save) {
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
register_syscore_ops(&s3c2410_clk_syscore_ops);
return;
}
static void s3c2410_clk_sleep_init(void) {}
static void __init s3c2410_common_clk_register_fixed_ext(
struct samsung_clk_provider *ctx,
unsigned long xti_f)
{
struct samsung_clock_alias xti_alias = ALIAS(XTI, NULL, "xtal");
s3c2410_common_frate_clks[0].fixed_rate = xti_f;
samsung_clk_register_fixed_rate(ctx, s3c2410_common_frate_clks,
ARRAY_SIZE(s3c2410_common_frate_clks));
samsung_clk_register_alias(ctx, &xti_alias, 1);
}
void __init s3c2410_common_clk_init(struct device_node *np, unsigned long xti_f,
int current_soc,
void __iomem *base)
{
struct samsung_clk_provider *ctx;
reg_base = base;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
}
ctx = samsung_clk_init(np, reg_base, NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
if (!np)
s3c2410_common_clk_register_fixed_ext(ctx, xti_f);
if (current_soc == S3C2410) {
if (_get_rate("xti") == 12 * MHZ) {
s3c2410_plls[mpll].rate_table = pll_s3c2410_12mhz_tbl;
s3c2410_plls[upll].rate_table = pll_s3c2410_12mhz_tbl;
}
samsung_clk_register_pll(ctx, s3c2410_plls,
ARRAY_SIZE(s3c2410_plls), reg_base);
} else {
if (_get_rate("xti") == 12 * MHZ) {
s3c244x_common_plls[mpll].rate_table =
pll_s3c244x_12mhz_tbl;
s3c244x_common_plls[upll].rate_table =
pll_s3c2410_12mhz_tbl;
}
samsung_clk_register_pll(ctx, s3c244x_common_plls,
ARRAY_SIZE(s3c244x_common_plls), reg_base);
}
samsung_clk_register_mux(ctx, s3c2410_common_muxes,
ARRAY_SIZE(s3c2410_common_muxes));
samsung_clk_register_div(ctx, s3c2410_common_dividers,
ARRAY_SIZE(s3c2410_common_dividers));
samsung_clk_register_gate(ctx, s3c2410_common_gates,
ARRAY_SIZE(s3c2410_common_gates));
if (current_soc == S3C2440 || current_soc == S3C2442) {
samsung_clk_register_div(ctx, s3c244x_common_dividers,
ARRAY_SIZE(s3c244x_common_dividers));
samsung_clk_register_gate(ctx, s3c244x_common_gates,
ARRAY_SIZE(s3c244x_common_gates));
samsung_clk_register_mux(ctx, s3c244x_common_muxes,
ARRAY_SIZE(s3c244x_common_muxes));
samsung_clk_register_fixed_factor(ctx, s3c244x_common_ffactor,
ARRAY_SIZE(s3c244x_common_ffactor));
}
switch (current_soc) {
case S3C2410:
samsung_clk_register_div(ctx, s3c2410_dividers,
ARRAY_SIZE(s3c2410_dividers));
samsung_clk_register_fixed_factor(ctx, s3c2410_ffactor,
ARRAY_SIZE(s3c2410_ffactor));
samsung_clk_register_alias(ctx, s3c2410_aliases,
ARRAY_SIZE(s3c2410_aliases));
break;
case S3C2440:
samsung_clk_register_mux(ctx, s3c2440_muxes,
ARRAY_SIZE(s3c2440_muxes));
samsung_clk_register_gate(ctx, s3c2440_gates,
ARRAY_SIZE(s3c2440_gates));
break;
case S3C2442:
samsung_clk_register_mux(ctx, s3c2442_muxes,
ARRAY_SIZE(s3c2442_muxes));
samsung_clk_register_fixed_factor(ctx, s3c2442_ffactor,
ARRAY_SIZE(s3c2442_ffactor));
break;
}
samsung_clk_register_alias(ctx, s3c2410_common_aliases,
ARRAY_SIZE(s3c2410_common_aliases));
if (current_soc == S3C2440 || current_soc == S3C2442) {
samsung_clk_register_alias(ctx, s3c244x_common_aliases,
ARRAY_SIZE(s3c244x_common_aliases));
}
s3c2410_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
}
static void __init s3c2410_clk_init(struct device_node *np)
{
s3c2410_common_clk_init(np, 0, S3C2410, 0);
}
static void __init s3c2440_clk_init(struct device_node *np)
{
s3c2410_common_clk_init(np, 0, S3C2440, 0);
}
static void __init s3c2442_clk_init(struct device_node *np)
{
s3c2410_common_clk_init(np, 0, S3C2442, 0);
}
