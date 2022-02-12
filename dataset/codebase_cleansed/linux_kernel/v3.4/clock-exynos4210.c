static int exynos4_clksrc_mask_lcd1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4210_CLKSRC_MASK_LCD1, clk, enable);
}
static int exynos4210_clock_suspend(void)
{
s3c_pm_do_save(exynos4210_clock_save, ARRAY_SIZE(exynos4210_clock_save));
return 0;
}
static void exynos4210_clock_resume(void)
{
s3c_pm_do_restore_core(exynos4210_clock_save, ARRAY_SIZE(exynos4210_clock_save));
}
void __init exynos4210_register_clocks(void)
{
int ptr;
exynos4_clk_mout_mpll.reg_src.reg = EXYNOS4_CLKSRC_CPU;
exynos4_clk_mout_mpll.reg_src.shift = 8;
exynos4_clk_mout_mpll.reg_src.size = 1;
for (ptr = 0; ptr < ARRAY_SIZE(sysclks); ptr++)
s3c_register_clksrc(sysclks[ptr], 1);
s3c_register_clksrc(clksrcs, ARRAY_SIZE(clksrcs));
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
register_syscore_ops(&exynos4210_clock_syscore_ops);
}
