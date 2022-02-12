static int exynos5440_clk_restart_notify(struct notifier_block *this,
unsigned long code, void *unused)
{
u32 val, status;
status = readl_relaxed(reg_base + 0xbc);
val = readl_relaxed(reg_base + 0xcc);
val = (val & 0xffff0000) | (status & 0xffff);
writel_relaxed(val, reg_base + 0xcc);
return NOTIFY_DONE;
}
static void __init exynos5440_clk_init(struct device_node *np)
{
struct samsung_clk_provider *ctx;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: failed to map clock controller registers,"
" aborting clock initialization\n", __func__);
return;
}
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
samsung_clk_of_register_fixed_ext(ctx, exynos5440_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5440_fixed_rate_ext_clks), ext_clk_match);
samsung_clk_register_pll2550x("cplla", "xtal", reg_base + 0x1c, 0x10);
samsung_clk_register_pll2550x("cpllb", "xtal", reg_base + 0x20, 0x10);
samsung_clk_register_fixed_rate(ctx, exynos5440_fixed_rate_clks,
ARRAY_SIZE(exynos5440_fixed_rate_clks));
samsung_clk_register_fixed_factor(ctx, exynos5440_fixed_factor_clks,
ARRAY_SIZE(exynos5440_fixed_factor_clks));
samsung_clk_register_mux(ctx, exynos5440_mux_clks,
ARRAY_SIZE(exynos5440_mux_clks));
samsung_clk_register_div(ctx, exynos5440_div_clks,
ARRAY_SIZE(exynos5440_div_clks));
samsung_clk_register_gate(ctx, exynos5440_gate_clks,
ARRAY_SIZE(exynos5440_gate_clks));
samsung_clk_of_add_provider(np, ctx);
if (register_restart_handler(&exynos5440_clk_restart_handler))
pr_warn("exynos5440 clock can't register restart handler\n");
pr_info("Exynos5440: arm_clk = %ldHz\n", _get_rate("arm_clk"));
pr_info("exynos5440 clock initialization complete\n");
}
