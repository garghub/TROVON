static void exynos4210_set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
tmp = exynos4210_clkdiv_table[div_index].clkdiv;
__raw_writel(tmp, EXYNOS4_CLKDIV_CPU);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STATCPU);
} while (tmp & 0x1111111);
tmp = __raw_readl(EXYNOS4_CLKDIV_CPU1);
tmp &= ~((0x7 << 4) | 0x7);
tmp |= ((clkdiv_cpu1[div_index][0] << 4) |
(clkdiv_cpu1[div_index][1] << 0));
__raw_writel(tmp, EXYNOS4_CLKDIV_CPU1);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STATCPU1);
} while (tmp & 0x11);
}
static void exynos4210_set_apll(unsigned int index)
{
unsigned int tmp;
clk_set_parent(moutcore, mout_mpll);
do {
tmp = (__raw_readl(EXYNOS4_CLKMUX_STATCPU)
>> EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT);
tmp &= 0x7;
} while (tmp != 0x2);
__raw_writel(EXYNOS4_APLL_LOCKTIME, EXYNOS4_APLL_LOCK);
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~((0x3ff << 16) | (0x3f << 8) | (0x7 << 0));
tmp |= exynos4210_apll_pms_table[index];
__raw_writel(tmp, EXYNOS4_APLL_CON0);
do {
tmp = __raw_readl(EXYNOS4_APLL_CON0);
} while (!(tmp & (0x1 << EXYNOS4_APLLCON0_LOCKED_SHIFT)));
clk_set_parent(moutcore, mout_apll);
do {
tmp = __raw_readl(EXYNOS4_CLKMUX_STATCPU);
tmp &= EXYNOS4_CLKMUX_STATCPU_MUXCORE_MASK;
} while (tmp != (0x1 << EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT));
}
bool exynos4210_pms_change(unsigned int old_index, unsigned int new_index)
{
unsigned int old_pm = (exynos4210_apll_pms_table[old_index] >> 8);
unsigned int new_pm = (exynos4210_apll_pms_table[new_index] >> 8);
return (old_pm == new_pm) ? 0 : 1;
}
static void exynos4210_set_frequency(unsigned int old_index,
unsigned int new_index)
{
unsigned int tmp;
if (old_index > new_index) {
if (!exynos4210_pms_change(old_index, new_index)) {
exynos4210_set_clkdiv(new_index);
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4210_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, EXYNOS4_APLL_CON0);
} else {
exynos4210_set_clkdiv(new_index);
exynos4210_set_apll(new_index);
}
} else if (old_index < new_index) {
if (!exynos4210_pms_change(old_index, new_index)) {
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4210_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, EXYNOS4_APLL_CON0);
exynos4210_set_clkdiv(new_index);
} else {
exynos4210_set_apll(new_index);
exynos4210_set_clkdiv(new_index);
}
}
}
int exynos4210_cpufreq_init(struct exynos_dvfs_info *info)
{
int i;
unsigned int tmp;
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
tmp = __raw_readl(EXYNOS4_CLKDIV_CPU);
for (i = L0; i < CPUFREQ_LEVEL_END; i++) {
tmp &= ~(EXYNOS4_CLKDIV_CPU0_CORE_MASK |
EXYNOS4_CLKDIV_CPU0_COREM0_MASK |
EXYNOS4_CLKDIV_CPU0_COREM1_MASK |
EXYNOS4_CLKDIV_CPU0_PERIPH_MASK |
EXYNOS4_CLKDIV_CPU0_ATB_MASK |
EXYNOS4_CLKDIV_CPU0_PCLKDBG_MASK |
EXYNOS4_CLKDIV_CPU0_APLL_MASK);
tmp |= ((clkdiv_cpu0[i][0] << EXYNOS4_CLKDIV_CPU0_CORE_SHIFT) |
(clkdiv_cpu0[i][1] << EXYNOS4_CLKDIV_CPU0_COREM0_SHIFT) |
(clkdiv_cpu0[i][2] << EXYNOS4_CLKDIV_CPU0_COREM1_SHIFT) |
(clkdiv_cpu0[i][3] << EXYNOS4_CLKDIV_CPU0_PERIPH_SHIFT) |
(clkdiv_cpu0[i][4] << EXYNOS4_CLKDIV_CPU0_ATB_SHIFT) |
(clkdiv_cpu0[i][5] << EXYNOS4_CLKDIV_CPU0_PCLKDBG_SHIFT) |
(clkdiv_cpu0[i][6] << EXYNOS4_CLKDIV_CPU0_APLL_SHIFT));
exynos4210_clkdiv_table[i].clkdiv = tmp;
}
info->mpll_freq_khz = rate;
info->pm_lock_idx = L2;
info->pll_safe_idx = L2;
info->max_support_idx = max_support_idx;
info->min_support_idx = min_support_idx;
info->cpu_clk = cpu_clk;
info->volt_table = exynos4210_volt_table;
info->freq_table = exynos4210_freq_table;
info->set_freq = exynos4210_set_frequency;
info->need_apll_change = exynos4210_pms_change;
return 0;
err_mout_apll:
if (!IS_ERR(mout_mpll))
clk_put(mout_mpll);
err_mout_mpll:
if (!IS_ERR(moutcore))
clk_put(moutcore);
err_moutcore:
if (!IS_ERR(cpu_clk))
clk_put(cpu_clk);
pr_debug("%s: failed initialization\n", __func__);
return -EINVAL;
}
