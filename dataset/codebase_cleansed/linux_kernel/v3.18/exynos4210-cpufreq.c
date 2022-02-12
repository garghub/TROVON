static void exynos4210_set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
tmp = apll_freq_4210[div_index].clk_div_cpu0;
__raw_writel(tmp, cpufreq->cmu_regs + EXYNOS4_CLKDIV_CPU);
do {
tmp = __raw_readl(cpufreq->cmu_regs + EXYNOS4_CLKDIV_STATCPU);
} while (tmp & 0x1111111);
tmp = apll_freq_4210[div_index].clk_div_cpu1;
__raw_writel(tmp, cpufreq->cmu_regs + EXYNOS4_CLKDIV_CPU1);
do {
tmp = __raw_readl(cpufreq->cmu_regs + EXYNOS4_CLKDIV_STATCPU1);
} while (tmp & 0x11);
}
static void exynos4210_set_apll(unsigned int index)
{
unsigned int tmp, freq = apll_freq_4210[index].freq;
clk_set_parent(moutcore, mout_mpll);
do {
tmp = (__raw_readl(cpufreq->cmu_regs + EXYNOS4_CLKMUX_STATCPU)
>> EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT);
tmp &= 0x7;
} while (tmp != 0x2);
clk_set_rate(mout_apll, freq * 1000);
clk_set_parent(moutcore, mout_apll);
do {
tmp = __raw_readl(cpufreq->cmu_regs + EXYNOS4_CLKMUX_STATCPU);
tmp &= EXYNOS4_CLKMUX_STATCPU_MUXCORE_MASK;
} while (tmp != (0x1 << EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT));
}
static void exynos4210_set_frequency(unsigned int old_index,
unsigned int new_index)
{
if (old_index > new_index) {
exynos4210_set_clkdiv(new_index);
exynos4210_set_apll(new_index);
} else if (old_index < new_index) {
exynos4210_set_apll(new_index);
exynos4210_set_clkdiv(new_index);
}
}
int exynos4210_cpufreq_init(struct exynos_dvfs_info *info)
{
struct device_node *np;
unsigned long rate;
np = of_find_compatible_node(NULL, NULL, "samsung,exynos4210-clock");
if (!np) {
pr_err("%s: failed to find clock controller DT node\n",
__func__);
return -ENODEV;
}
info->cmu_regs = of_iomap(np, 0);
if (!info->cmu_regs) {
pr_err("%s: failed to map CMU registers\n", __func__);
return -EFAULT;
}
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
info->mpll_freq_khz = rate;
info->pll_safe_idx = L2;
info->cpu_clk = cpu_clk;
info->volt_table = exynos4210_volt_table;
info->freq_table = exynos4210_freq_table;
info->set_freq = exynos4210_set_frequency;
cpufreq = info;
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
