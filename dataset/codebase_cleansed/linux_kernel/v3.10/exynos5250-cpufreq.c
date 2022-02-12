static void set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
tmp = apll_freq_5250[div_index].clk_div_cpu0;
__raw_writel(tmp, EXYNOS5_CLKDIV_CPU0);
while (__raw_readl(EXYNOS5_CLKDIV_STATCPU0) & 0x11111111)
cpu_relax();
tmp = apll_freq_5250[div_index].clk_div_cpu1;
__raw_writel(tmp, EXYNOS5_CLKDIV_CPU1);
while (__raw_readl(EXYNOS5_CLKDIV_STATCPU1) & 0x11)
cpu_relax();
}
static void set_apll(unsigned int new_index,
unsigned int old_index)
{
unsigned int tmp, pdiv;
clk_set_parent(moutcore, mout_mpll);
do {
cpu_relax();
tmp = (__raw_readl(EXYNOS5_CLKMUX_STATCPU) >> 16);
tmp &= 0x7;
} while (tmp != 0x2);
pdiv = ((apll_freq_5250[new_index].mps >> 8) & 0x3f);
__raw_writel((pdiv * 250), EXYNOS5_APLL_LOCK);
tmp = __raw_readl(EXYNOS5_APLL_CON0);
tmp &= ~((0x3ff << 16) | (0x3f << 8) | (0x7 << 0));
tmp |= apll_freq_5250[new_index].mps;
__raw_writel(tmp, EXYNOS5_APLL_CON0);
do {
cpu_relax();
tmp = __raw_readl(EXYNOS5_APLL_CON0);
} while (!(tmp & (0x1 << 29)));
clk_set_parent(moutcore, mout_apll);
do {
cpu_relax();
tmp = __raw_readl(EXYNOS5_CLKMUX_STATCPU);
tmp &= (0x7 << 16);
} while (tmp != (0x1 << 16));
}
static bool exynos5250_pms_change(unsigned int old_index, unsigned int new_index)
{
unsigned int old_pm = apll_freq_5250[old_index].mps >> 8;
unsigned int new_pm = apll_freq_5250[new_index].mps >> 8;
return (old_pm == new_pm) ? 0 : 1;
}
static void exynos5250_set_frequency(unsigned int old_index,
unsigned int new_index)
{
unsigned int tmp;
if (old_index > new_index) {
if (!exynos5250_pms_change(old_index, new_index)) {
set_clkdiv(new_index);
tmp = __raw_readl(EXYNOS5_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= apll_freq_5250[new_index].mps & 0x7;
__raw_writel(tmp, EXYNOS5_APLL_CON0);
} else {
set_clkdiv(new_index);
set_apll(new_index, old_index);
}
} else if (old_index < new_index) {
if (!exynos5250_pms_change(old_index, new_index)) {
tmp = __raw_readl(EXYNOS5_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= apll_freq_5250[new_index].mps & 0x7;
__raw_writel(tmp, EXYNOS5_APLL_CON0);
set_clkdiv(new_index);
} else {
set_apll(new_index, old_index);
set_clkdiv(new_index);
}
}
}
int exynos5250_cpufreq_init(struct exynos_dvfs_info *info)
{
unsigned long rate;
cpu_clk = clk_get(NULL, "armclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
moutcore = clk_get(NULL, "mout_cpu");
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
info->pll_safe_idx = L9;
info->cpu_clk = cpu_clk;
info->volt_table = exynos5250_volt_table;
info->freq_table = exynos5250_freq_table;
info->set_freq = exynos5250_set_frequency;
info->need_apll_change = exynos5250_pms_change;
return 0;
err_mout_apll:
clk_put(mout_mpll);
err_mout_mpll:
clk_put(moutcore);
err_moutcore:
clk_put(cpu_clk);
pr_err("%s: failed initialization\n", __func__);
return -EINVAL;
}
