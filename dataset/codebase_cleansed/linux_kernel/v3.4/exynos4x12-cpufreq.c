static void exynos4x12_set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
unsigned int stat_cpu1;
tmp = exynos4x12_clkdiv_table[div_index].clkdiv;
__raw_writel(tmp, EXYNOS4_CLKDIV_CPU);
while (__raw_readl(EXYNOS4_CLKDIV_STATCPU) & 0x11111111)
cpu_relax();
tmp = exynos4x12_clkdiv_table[div_index].clkdiv1;
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
unsigned int tmp, pdiv;
clk_set_parent(moutcore, mout_mpll);
do {
cpu_relax();
tmp = (__raw_readl(EXYNOS4_CLKMUX_STATCPU)
>> EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT);
tmp &= 0x7;
} while (tmp != 0x2);
pdiv = ((exynos4x12_apll_pms_table[index] >> 8) & 0x3f);
__raw_writel((pdiv * 250), EXYNOS4_APLL_LOCK);
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~((0x3ff << 16) | (0x3f << 8) | (0x7 << 0));
tmp |= exynos4x12_apll_pms_table[index];
__raw_writel(tmp, EXYNOS4_APLL_CON0);
do {
cpu_relax();
tmp = __raw_readl(EXYNOS4_APLL_CON0);
} while (!(tmp & (0x1 << EXYNOS4_APLLCON0_LOCKED_SHIFT)));
clk_set_parent(moutcore, mout_apll);
do {
cpu_relax();
tmp = __raw_readl(EXYNOS4_CLKMUX_STATCPU);
tmp &= EXYNOS4_CLKMUX_STATCPU_MUXCORE_MASK;
} while (tmp != (0x1 << EXYNOS4_CLKSRC_CPU_MUXCORE_SHIFT));
}
bool exynos4x12_pms_change(unsigned int old_index, unsigned int new_index)
{
unsigned int old_pm = exynos4x12_apll_pms_table[old_index] >> 8;
unsigned int new_pm = exynos4x12_apll_pms_table[new_index] >> 8;
return (old_pm == new_pm) ? 0 : 1;
}
static void exynos4x12_set_frequency(unsigned int old_index,
unsigned int new_index)
{
unsigned int tmp;
if (old_index > new_index) {
if (!exynos4x12_pms_change(old_index, new_index)) {
exynos4x12_set_clkdiv(new_index);
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4x12_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, EXYNOS4_APLL_CON0);
} else {
exynos4x12_set_clkdiv(new_index);
exynos4x12_set_apll(new_index);
}
} else if (old_index < new_index) {
if (!exynos4x12_pms_change(old_index, new_index)) {
tmp = __raw_readl(EXYNOS4_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4x12_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, EXYNOS4_APLL_CON0);
exynos4x12_set_clkdiv(new_index);
} else {
exynos4x12_set_apll(new_index);
exynos4x12_set_clkdiv(new_index);
}
}
}
static void __init set_volt_table(void)
{
unsigned int i;
max_support_idx = L1;
exynos4x12_freq_table[L0].frequency = CPUFREQ_ENTRY_INVALID;
for (i = 0 ; i < CPUFREQ_LEVEL_END ; i++)
exynos4x12_volt_table[i] = asv_voltage_4x12[i];
}
int exynos4x12_cpufreq_init(struct exynos_dvfs_info *info)
{
int i;
unsigned int tmp;
unsigned long rate;
set_volt_table();
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
for (i = L0; i < CPUFREQ_LEVEL_END; i++) {
exynos4x12_clkdiv_table[i].index = i;
tmp = __raw_readl(EXYNOS4_CLKDIV_CPU);
tmp &= ~(EXYNOS4_CLKDIV_CPU0_CORE_MASK |
EXYNOS4_CLKDIV_CPU0_COREM0_MASK |
EXYNOS4_CLKDIV_CPU0_COREM1_MASK |
EXYNOS4_CLKDIV_CPU0_PERIPH_MASK |
EXYNOS4_CLKDIV_CPU0_ATB_MASK |
EXYNOS4_CLKDIV_CPU0_PCLKDBG_MASK |
EXYNOS4_CLKDIV_CPU0_APLL_MASK);
if (soc_is_exynos4212()) {
tmp |= ((clkdiv_cpu0_4212[i][0] << EXYNOS4_CLKDIV_CPU0_CORE_SHIFT) |
(clkdiv_cpu0_4212[i][1] << EXYNOS4_CLKDIV_CPU0_COREM0_SHIFT) |
(clkdiv_cpu0_4212[i][2] << EXYNOS4_CLKDIV_CPU0_COREM1_SHIFT) |
(clkdiv_cpu0_4212[i][3] << EXYNOS4_CLKDIV_CPU0_PERIPH_SHIFT) |
(clkdiv_cpu0_4212[i][4] << EXYNOS4_CLKDIV_CPU0_ATB_SHIFT) |
(clkdiv_cpu0_4212[i][5] << EXYNOS4_CLKDIV_CPU0_PCLKDBG_SHIFT) |
(clkdiv_cpu0_4212[i][6] << EXYNOS4_CLKDIV_CPU0_APLL_SHIFT));
} else {
tmp &= ~EXYNOS4_CLKDIV_CPU0_CORE2_MASK;
tmp |= ((clkdiv_cpu0_4412[i][0] << EXYNOS4_CLKDIV_CPU0_CORE_SHIFT) |
(clkdiv_cpu0_4412[i][1] << EXYNOS4_CLKDIV_CPU0_COREM0_SHIFT) |
(clkdiv_cpu0_4412[i][2] << EXYNOS4_CLKDIV_CPU0_COREM1_SHIFT) |
(clkdiv_cpu0_4412[i][3] << EXYNOS4_CLKDIV_CPU0_PERIPH_SHIFT) |
(clkdiv_cpu0_4412[i][4] << EXYNOS4_CLKDIV_CPU0_ATB_SHIFT) |
(clkdiv_cpu0_4412[i][5] << EXYNOS4_CLKDIV_CPU0_PCLKDBG_SHIFT) |
(clkdiv_cpu0_4412[i][6] << EXYNOS4_CLKDIV_CPU0_APLL_SHIFT) |
(clkdiv_cpu0_4412[i][7] << EXYNOS4_CLKDIV_CPU0_CORE2_SHIFT));
}
exynos4x12_clkdiv_table[i].clkdiv = tmp;
tmp = __raw_readl(EXYNOS4_CLKDIV_CPU1);
if (soc_is_exynos4212()) {
tmp &= ~(EXYNOS4_CLKDIV_CPU1_COPY_MASK |
EXYNOS4_CLKDIV_CPU1_HPM_MASK);
tmp |= ((clkdiv_cpu1_4212[i][0] << EXYNOS4_CLKDIV_CPU1_COPY_SHIFT) |
(clkdiv_cpu1_4212[i][1] << EXYNOS4_CLKDIV_CPU1_HPM_SHIFT));
} else {
tmp &= ~(EXYNOS4_CLKDIV_CPU1_COPY_MASK |
EXYNOS4_CLKDIV_CPU1_HPM_MASK |
EXYNOS4_CLKDIV_CPU1_CORES_MASK);
tmp |= ((clkdiv_cpu1_4412[i][0] << EXYNOS4_CLKDIV_CPU1_COPY_SHIFT) |
(clkdiv_cpu1_4412[i][1] << EXYNOS4_CLKDIV_CPU1_HPM_SHIFT) |
(clkdiv_cpu1_4412[i][2] << EXYNOS4_CLKDIV_CPU1_CORES_SHIFT));
}
exynos4x12_clkdiv_table[i].clkdiv1 = tmp;
}
info->mpll_freq_khz = rate;
info->pm_lock_idx = L5;
info->pll_safe_idx = L7;
info->max_support_idx = max_support_idx;
info->min_support_idx = min_support_idx;
info->cpu_clk = cpu_clk;
info->volt_table = exynos4x12_volt_table;
info->freq_table = exynos4x12_freq_table;
info->set_freq = exynos4x12_set_frequency;
info->need_apll_change = exynos4x12_pms_change;
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
