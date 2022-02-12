static int s3c2443_clk_suspend(void)
{
samsung_clk_save(reg_base, s3c2443_save,
ARRAY_SIZE(s3c2443_clk_regs));
return 0;
}
static void s3c2443_clk_resume(void)
{
samsung_clk_restore(reg_base, s3c2443_save,
ARRAY_SIZE(s3c2443_clk_regs));
}
static void s3c2443_clk_sleep_init(void)
{
s3c2443_save = samsung_clk_alloc_reg_dump(s3c2443_clk_regs,
ARRAY_SIZE(s3c2443_clk_regs));
if (!s3c2443_save) {
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
register_syscore_ops(&s3c2443_clk_syscore_ops);
return;
}
static void s3c2443_clk_sleep_init(void) {}
static int s3c2443_restart(struct notifier_block *this,
unsigned long mode, void *cmd)
{
__raw_writel(0x533c2443, reg_base + SWRST);
return NOTIFY_DONE;
}
static void __init s3c2443_common_clk_register_fixed_ext(
struct samsung_clk_provider *ctx, unsigned long xti_f)
{
s3c2443_common_frate_clks[0].fixed_rate = xti_f;
samsung_clk_register_fixed_rate(ctx, s3c2443_common_frate_clks,
ARRAY_SIZE(s3c2443_common_frate_clks));
}
void __init s3c2443_common_clk_init(struct device_node *np, unsigned long xti_f,
int current_soc,
void __iomem *base)
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
s3c2443_common_clk_register_fixed_ext(ctx, xti_f);
if (current_soc == S3C2416 || current_soc == S3C2450)
samsung_clk_register_pll(ctx, s3c2416_pll_clks,
ARRAY_SIZE(s3c2416_pll_clks), reg_base);
else
samsung_clk_register_pll(ctx, s3c2443_pll_clks,
ARRAY_SIZE(s3c2443_pll_clks), reg_base);
samsung_clk_register_mux(ctx, s3c2443_common_muxes,
ARRAY_SIZE(s3c2443_common_muxes));
samsung_clk_register_div(ctx, s3c2443_common_dividers,
ARRAY_SIZE(s3c2443_common_dividers));
samsung_clk_register_gate(ctx, s3c2443_common_gates,
ARRAY_SIZE(s3c2443_common_gates));
samsung_clk_register_alias(ctx, s3c2443_common_aliases,
ARRAY_SIZE(s3c2443_common_aliases));
switch (current_soc) {
case S3C2450:
samsung_clk_register_div(ctx, s3c2450_dividers,
ARRAY_SIZE(s3c2450_dividers));
samsung_clk_register_mux(ctx, s3c2450_muxes,
ARRAY_SIZE(s3c2450_muxes));
samsung_clk_register_gate(ctx, s3c2450_gates,
ARRAY_SIZE(s3c2450_gates));
samsung_clk_register_alias(ctx, s3c2450_aliases,
ARRAY_SIZE(s3c2450_aliases));
case S3C2416:
samsung_clk_register_div(ctx, s3c2416_dividers,
ARRAY_SIZE(s3c2416_dividers));
samsung_clk_register_mux(ctx, s3c2416_muxes,
ARRAY_SIZE(s3c2416_muxes));
samsung_clk_register_gate(ctx, s3c2416_gates,
ARRAY_SIZE(s3c2416_gates));
samsung_clk_register_alias(ctx, s3c2416_aliases,
ARRAY_SIZE(s3c2416_aliases));
break;
case S3C2443:
samsung_clk_register_div(ctx, s3c2443_dividers,
ARRAY_SIZE(s3c2443_dividers));
samsung_clk_register_gate(ctx, s3c2443_gates,
ARRAY_SIZE(s3c2443_gates));
samsung_clk_register_alias(ctx, s3c2443_aliases,
ARRAY_SIZE(s3c2443_aliases));
break;
}
s3c2443_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
ret = register_restart_handler(&s3c2443_restart_handler);
if (ret)
pr_warn("cannot register restart handler, %d\n", ret);
}
static void __init s3c2416_clk_init(struct device_node *np)
{
s3c2443_common_clk_init(np, 0, S3C2416, 0);
}
static void __init s3c2443_clk_init(struct device_node *np)
{
s3c2443_common_clk_init(np, 0, S3C2443, 0);
}
static void __init s3c2450_clk_init(struct device_node *np)
{
s3c2443_common_clk_init(np, 0, S3C2450, 0);
}
