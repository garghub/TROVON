int exynos4_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, exynos4_freq_table);
}
unsigned int exynos4_getspeed(unsigned int cpu)
{
return clk_get_rate(cpu_clk) / 1000;
}
void exynos4_set_clkdiv(unsigned int div_index)
{
unsigned int tmp;
tmp = __raw_readl(S5P_CLKDIV_CPU);
tmp &= ~(S5P_CLKDIV_CPU0_CORE_MASK | S5P_CLKDIV_CPU0_COREM0_MASK |
S5P_CLKDIV_CPU0_COREM1_MASK | S5P_CLKDIV_CPU0_PERIPH_MASK |
S5P_CLKDIV_CPU0_ATB_MASK | S5P_CLKDIV_CPU0_PCLKDBG_MASK |
S5P_CLKDIV_CPU0_APLL_MASK);
tmp |= ((clkdiv_cpu0[div_index][0] << S5P_CLKDIV_CPU0_CORE_SHIFT) |
(clkdiv_cpu0[div_index][1] << S5P_CLKDIV_CPU0_COREM0_SHIFT) |
(clkdiv_cpu0[div_index][2] << S5P_CLKDIV_CPU0_COREM1_SHIFT) |
(clkdiv_cpu0[div_index][3] << S5P_CLKDIV_CPU0_PERIPH_SHIFT) |
(clkdiv_cpu0[div_index][4] << S5P_CLKDIV_CPU0_ATB_SHIFT) |
(clkdiv_cpu0[div_index][5] << S5P_CLKDIV_CPU0_PCLKDBG_SHIFT) |
(clkdiv_cpu0[div_index][6] << S5P_CLKDIV_CPU0_APLL_SHIFT));
__raw_writel(tmp, S5P_CLKDIV_CPU);
do {
tmp = __raw_readl(S5P_CLKDIV_STATCPU);
} while (tmp & 0x1111111);
tmp = __raw_readl(S5P_CLKDIV_CPU1);
tmp &= ~((0x7 << 4) | 0x7);
tmp |= ((clkdiv_cpu1[div_index][0] << 4) |
(clkdiv_cpu1[div_index][1] << 0));
__raw_writel(tmp, S5P_CLKDIV_CPU1);
do {
tmp = __raw_readl(S5P_CLKDIV_STATCPU1);
} while (tmp & 0x11);
tmp = __raw_readl(S5P_CLKDIV_DMC0);
tmp &= ~(S5P_CLKDIV_DMC0_ACP_MASK | S5P_CLKDIV_DMC0_ACPPCLK_MASK |
S5P_CLKDIV_DMC0_DPHY_MASK | S5P_CLKDIV_DMC0_DMC_MASK |
S5P_CLKDIV_DMC0_DMCD_MASK | S5P_CLKDIV_DMC0_DMCP_MASK |
S5P_CLKDIV_DMC0_COPY2_MASK | S5P_CLKDIV_DMC0_CORETI_MASK);
tmp |= ((clkdiv_dmc0[div_index][0] << S5P_CLKDIV_DMC0_ACP_SHIFT) |
(clkdiv_dmc0[div_index][1] << S5P_CLKDIV_DMC0_ACPPCLK_SHIFT) |
(clkdiv_dmc0[div_index][2] << S5P_CLKDIV_DMC0_DPHY_SHIFT) |
(clkdiv_dmc0[div_index][3] << S5P_CLKDIV_DMC0_DMC_SHIFT) |
(clkdiv_dmc0[div_index][4] << S5P_CLKDIV_DMC0_DMCD_SHIFT) |
(clkdiv_dmc0[div_index][5] << S5P_CLKDIV_DMC0_DMCP_SHIFT) |
(clkdiv_dmc0[div_index][6] << S5P_CLKDIV_DMC0_COPY2_SHIFT) |
(clkdiv_dmc0[div_index][7] << S5P_CLKDIV_DMC0_CORETI_SHIFT));
__raw_writel(tmp, S5P_CLKDIV_DMC0);
do {
tmp = __raw_readl(S5P_CLKDIV_STAT_DMC0);
} while (tmp & 0x11111111);
tmp = __raw_readl(S5P_CLKDIV_TOP);
tmp &= ~(S5P_CLKDIV_TOP_ACLK200_MASK | S5P_CLKDIV_TOP_ACLK100_MASK |
S5P_CLKDIV_TOP_ACLK160_MASK | S5P_CLKDIV_TOP_ACLK133_MASK |
S5P_CLKDIV_TOP_ONENAND_MASK);
tmp |= ((clkdiv_top[div_index][0] << S5P_CLKDIV_TOP_ACLK200_SHIFT) |
(clkdiv_top[div_index][1] << S5P_CLKDIV_TOP_ACLK100_SHIFT) |
(clkdiv_top[div_index][2] << S5P_CLKDIV_TOP_ACLK160_SHIFT) |
(clkdiv_top[div_index][3] << S5P_CLKDIV_TOP_ACLK133_SHIFT) |
(clkdiv_top[div_index][4] << S5P_CLKDIV_TOP_ONENAND_SHIFT));
__raw_writel(tmp, S5P_CLKDIV_TOP);
do {
tmp = __raw_readl(S5P_CLKDIV_STAT_TOP);
} while (tmp & 0x11111);
tmp = __raw_readl(S5P_CLKDIV_LEFTBUS);
tmp &= ~(S5P_CLKDIV_BUS_GDLR_MASK | S5P_CLKDIV_BUS_GPLR_MASK);
tmp |= ((clkdiv_lr_bus[div_index][0] << S5P_CLKDIV_BUS_GDLR_SHIFT) |
(clkdiv_lr_bus[div_index][1] << S5P_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, S5P_CLKDIV_LEFTBUS);
do {
tmp = __raw_readl(S5P_CLKDIV_STAT_LEFTBUS);
} while (tmp & 0x11);
tmp = __raw_readl(S5P_CLKDIV_RIGHTBUS);
tmp &= ~(S5P_CLKDIV_BUS_GDLR_MASK | S5P_CLKDIV_BUS_GPLR_MASK);
tmp |= ((clkdiv_lr_bus[div_index][0] << S5P_CLKDIV_BUS_GDLR_SHIFT) |
(clkdiv_lr_bus[div_index][1] << S5P_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, S5P_CLKDIV_RIGHTBUS);
do {
tmp = __raw_readl(S5P_CLKDIV_STAT_RIGHTBUS);
} while (tmp & 0x11);
}
static void exynos4_set_apll(unsigned int index)
{
unsigned int tmp;
clk_set_parent(moutcore, mout_mpll);
do {
tmp = (__raw_readl(S5P_CLKMUX_STATCPU)
>> S5P_CLKSRC_CPU_MUXCORE_SHIFT);
tmp &= 0x7;
} while (tmp != 0x2);
__raw_writel(S5P_APLL_LOCKTIME, S5P_APLL_LOCK);
tmp = __raw_readl(S5P_APLL_CON0);
tmp &= ~((0x3ff << 16) | (0x3f << 8) | (0x7 << 0));
tmp |= exynos4_apll_pms_table[index];
__raw_writel(tmp, S5P_APLL_CON0);
do {
tmp = __raw_readl(S5P_APLL_CON0);
} while (!(tmp & (0x1 << S5P_APLLCON0_LOCKED_SHIFT)));
clk_set_parent(moutcore, mout_apll);
do {
tmp = __raw_readl(S5P_CLKMUX_STATCPU);
tmp &= S5P_CLKMUX_STATCPU_MUXCORE_MASK;
} while (tmp != (0x1 << S5P_CLKSRC_CPU_MUXCORE_SHIFT));
}
static void exynos4_set_frequency(unsigned int old_index, unsigned int new_index)
{
unsigned int tmp;
if (old_index > new_index) {
if (freqs.new == exynos4_freq_table[L0].frequency) {
exynos4_set_clkdiv(new_index);
exynos4_set_apll(new_index);
} else {
exynos4_set_clkdiv(new_index);
tmp = __raw_readl(S5P_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, S5P_APLL_CON0);
}
}
else if (old_index < new_index) {
if (freqs.old == exynos4_freq_table[L0].frequency) {
exynos4_set_apll(new_index);
exynos4_set_clkdiv(new_index);
} else {
tmp = __raw_readl(S5P_APLL_CON0);
tmp &= ~(0x7 << 0);
tmp |= (exynos4_apll_pms_table[new_index] & 0x7);
__raw_writel(tmp, S5P_APLL_CON0);
exynos4_set_clkdiv(new_index);
}
}
}
static int exynos4_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int index, old_index;
unsigned int arm_volt, int_volt;
freqs.old = exynos4_getspeed(policy->cpu);
if (cpufreq_frequency_table_target(policy, exynos4_freq_table,
freqs.old, relation, &old_index))
return -EINVAL;
if (cpufreq_frequency_table_target(policy, exynos4_freq_table,
target_freq, relation, &index))
return -EINVAL;
freqs.new = exynos4_freq_table[index].frequency;
freqs.cpu = policy->cpu;
if (freqs.new == freqs.old)
return 0;
arm_volt = exynos4_volt_table[index].arm_volt;
int_volt = exynos4_volt_table[index].int_volt;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
if (freqs.new > freqs.old) {
regulator_set_voltage(arm_regulator, arm_volt, arm_volt);
regulator_set_voltage(int_regulator, int_volt, int_volt);
}
exynos4_set_frequency(old_index, index);
if (freqs.new < freqs.old) {
regulator_set_voltage(arm_regulator, arm_volt, arm_volt);
regulator_set_voltage(int_regulator, int_volt, int_volt);
}
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
return 0;
}
static int exynos4_cpufreq_suspend(struct cpufreq_policy *policy)
{
return 0;
}
static int exynos4_cpufreq_resume(struct cpufreq_policy *policy)
{
return 0;
}
static int exynos4_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->cur = policy->min = policy->max = exynos4_getspeed(policy->cpu);
cpufreq_frequency_table_get_attr(exynos4_freq_table, policy->cpu);
policy->cpuinfo.transition_latency = 100000;
cpumask_setall(policy->cpus);
return cpufreq_frequency_table_cpuinfo(policy, exynos4_freq_table);
}
static int __init exynos4_cpufreq_init(void)
{
cpu_clk = clk_get(NULL, "armclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
moutcore = clk_get(NULL, "moutcore");
if (IS_ERR(moutcore))
goto out;
mout_mpll = clk_get(NULL, "mout_mpll");
if (IS_ERR(mout_mpll))
goto out;
mout_apll = clk_get(NULL, "mout_apll");
if (IS_ERR(mout_apll))
goto out;
arm_regulator = regulator_get(NULL, "vdd_arm");
if (IS_ERR(arm_regulator)) {
printk(KERN_ERR "failed to get resource %s\n", "vdd_arm");
goto out;
}
int_regulator = regulator_get(NULL, "vdd_int");
if (IS_ERR(int_regulator)) {
printk(KERN_ERR "failed to get resource %s\n", "vdd_int");
goto out;
}
memtype = __raw_readl(S5P_VA_DMC0 + S5P_DMC0_MEMCON_OFFSET);
memtype = (memtype >> S5P_DMC0_MEMTYPE_SHIFT);
memtype &= S5P_DMC0_MEMTYPE_MASK;
if ((memtype < DDR2) && (memtype > DDR3)) {
printk(KERN_ERR "%s: wrong memtype= 0x%x\n", __func__, memtype);
goto out;
} else {
printk(KERN_DEBUG "%s: memtype= 0x%x\n", __func__, memtype);
}
return cpufreq_register_driver(&exynos4_driver);
out:
if (!IS_ERR(cpu_clk))
clk_put(cpu_clk);
if (!IS_ERR(moutcore))
clk_put(moutcore);
if (!IS_ERR(mout_mpll))
clk_put(mout_mpll);
if (!IS_ERR(mout_apll))
clk_put(mout_apll);
if (!IS_ERR(arm_regulator))
regulator_put(arm_regulator);
if (!IS_ERR(int_regulator))
regulator_put(int_regulator);
printk(KERN_ERR "%s: failed initialization\n", __func__);
return -EINVAL;
}
