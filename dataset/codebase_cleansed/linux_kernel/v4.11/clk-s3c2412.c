static int s3c2412_clk_suspend(void)
{
samsung_clk_save(reg_base, s3c2412_save,
ARRAY_SIZE(s3c2412_clk_regs));
return 0;
}
static void s3c2412_clk_resume(void)
{
samsung_clk_restore(reg_base, s3c2412_save,
ARRAY_SIZE(s3c2412_clk_regs));
}
static void __init s3c2412_clk_sleep_init(void)
{
s3c2412_save = samsung_clk_alloc_reg_dump(s3c2412_clk_regs,
ARRAY_SIZE(s3c2412_clk_regs));
if (!s3c2412_save) {
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
register_syscore_ops(&s3c2412_clk_syscore_ops);
return;
}
static void __init s3c2412_clk_sleep_init(void) {}
static int s3c2412_restart(struct notifier_block *this,
unsigned long mode, void *cmd)
{
__raw_writel(0x00, reg_base + CLKSRC);
__raw_writel(0x533C2412, reg_base + SWRST);
return NOTIFY_DONE;
}
static void __init s3c2412_common_clk_register_fixed_ext(
struct samsung_clk_provider *ctx,
unsigned long xti_f, unsigned long ext_f)
{
struct samsung_clock_alias xti_alias = ALIAS(XTI, NULL, "xtal");
s3c2412_common_frate_clks[0].fixed_rate = xti_f;
s3c2412_common_frate_clks[1].fixed_rate = ext_f;
samsung_clk_register_fixed_rate(ctx, s3c2412_common_frate_clks,
ARRAY_SIZE(s3c2412_common_frate_clks));
samsung_clk_register_alias(ctx, &xti_alias, 1);
}
void __init s3c2412_common_clk_init(struct device_node *np, unsigned long xti_f,
unsigned long ext_f, void __iomem *base)
{
struct samsung_clk_provider *ctx;
int ret;
reg_base = base;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
}
ctx = samsung_clk_init(np, reg_base, NR_CLKS);
if (!np)
s3c2412_common_clk_register_fixed_ext(ctx, xti_f, ext_f);
samsung_clk_register_pll(ctx, s3c2412_plls, ARRAY_SIZE(s3c2412_plls),
reg_base);
samsung_clk_register_mux(ctx, s3c2412_muxes, ARRAY_SIZE(s3c2412_muxes));
samsung_clk_register_div(ctx, s3c2412_dividers,
ARRAY_SIZE(s3c2412_dividers));
samsung_clk_register_gate(ctx, s3c2412_gates,
ARRAY_SIZE(s3c2412_gates));
samsung_clk_register_fixed_factor(ctx, s3c2412_ffactor,
ARRAY_SIZE(s3c2412_ffactor));
samsung_clk_register_alias(ctx, s3c2412_aliases,
ARRAY_SIZE(s3c2412_aliases));
s3c2412_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
ret = register_restart_handler(&s3c2412_restart_handler);
if (ret)
pr_warn("cannot register restart handler, %d\n", ret);
}
static void __init s3c2412_clk_init(struct device_node *np)
{
s3c2412_common_clk_init(np, 0, 0, 0);
}
