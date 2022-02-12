static void exynos4x12_set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
unsigned int stat_cpu1;
tmp = apll_freq_4x12[div_index].clk_div_cpu0;
__raw_writel(tmp, EXYNOS4_CLKDIV_CPU);
while (__raw_readl(EXYNOS4_CLKDIV_STATCPU) & 0x11111111)
cpu_relax();
tmp = apll_freq_4x12[div_index].clk_div_cpu1;
__raw_writel(tmp, EXYNOS4_CLKDIV_CPU1);
if (soc_is_exynos4212())
stat_cpu1 = 0x11;
else
stat_cpu1 = 0x111;
while (__raw_readl(EXYNOS4_CLKDIV_STATCPU1) & stat_cpu1)
cpu_relax();
}
static void exynos4x12_set_apll(unsigned int index)
{
unsigned int tmp, freq = apll_freq_4x12[index].freq;
clk_set_parent(moutcore, mout_mpll);
do {
cpu_relax();
tmp = (__raw_readl(EXYNOS4_CLKMUX_STATCPU)
>> EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT);
tmp &= 0x7;
} while (tmp != 0x2);
clk_set_rate(mout_apll, freq * 1000);
clk_set_parent(moutcore, mout_apll);
do {
cpu_relax();
tmp = __raw_readl(EXYNOS4_CLKMUX_STATCPU);
tmp &= EXYNOS4_CLKMUX_STATCPU_MUXCORE_MASK;
} while (tmp != (0x1 << EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT));
}
static void exynos4x12_set_frequency(unsigned int old_index,
unsigned int new_index)
{
if (old_index > new_index) {
exynos4x12_set_clkdiv(new_index);
exynos4x12_set_apll(new_index);
} else if (old_index < new_index) {
exynos4x12_set_apll(new_index);
exynos4x12_set_clkdiv(new_index);
}
}
int exynos4x12_cpufreq_init(struct exynos_dvfs_info *info)
{
unsigned long rate;
cpu_clk = clk_get(NULL, "armclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
moutcore = clk_get(NULL, "moutcore");
if (IS_ERR(moutcore))
goto err_moutcore;
mout_mpll = clk_get(NULL, "mout_mpll");
if (IS_ERR(mout_mpll))
goto err_mout_mpll;
rate = clk_get_rate(mout_mpll) / 1000;
mout_apll = clk_get(NULL, "mout_apll");
if (IS_ERR(mout_apll))
goto err_mout_apll;
if (soc_is_exynos4212())
apll_freq_4x12 = apll_freq_4212;
else
apll_freq_4x12 = apll_freq_4412;
info->mpll_freq_khz = rate;
info->pll_safe_idx = L7;
info->cpu_clk = cpu_clk;
info->volt_table = exynos4x12_volt_table;
info->freq_table = exynos4x12_freq_table;
info->set_freq = exynos4x12_set_frequency;
return 0;
err_mout_apll:
clk_put(mout_mpll);
err_mout_mpll:
clk_put(moutcore);
err_moutcore:
clk_put(cpu_clk);
pr_debug("%s: failed initialization\n", __func__);
return -EINVAL;
}
