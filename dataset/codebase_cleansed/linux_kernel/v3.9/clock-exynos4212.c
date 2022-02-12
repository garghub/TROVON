static int exynos4212_clk_ip_isp0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_ISP0, clk, enable);
}
static int exynos4212_clk_ip_isp1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_ISP1, clk, enable);
}
static int exynos4212_clock_suspend(void)
{
s3c_pm_do_save(exynos4212_clock_save, ARRAY_SIZE(exynos4212_clock_save));
return 0;
}
static void exynos4212_clock_resume(void)
{
s3c_pm_do_restore_core(exynos4212_clock_save, ARRAY_SIZE(exynos4212_clock_save));
}
void __init exynos4212_register_clocks(void)
{
int ptr;
exynos4_clkset_group_list[4] = NULL;
exynos4_clkset_group_list[6] = &clk_mout_mpll_user.clk;
exynos4_clkset_aclk_top_list[0] = &clk_mout_mpll_user.clk;
exynos4_clk_mout_mpll.reg_src.reg = EXYNOS4_CLKSRC_DMC;
exynos4_clk_mout_mpll.reg_src.shift = 12;
exynos4_clk_mout_mpll.reg_src.size = 1;
for (ptr = 0; ptr < ARRAY_SIZE(sysclks); ptr++)
s3c_register_clksrc(sysclks[ptr], 1);
s3c_register_clksrc(clksrcs, ARRAY_SIZE(clksrcs));
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
register_syscore_ops(&exynos4212_clock_syscore_ops);
}
