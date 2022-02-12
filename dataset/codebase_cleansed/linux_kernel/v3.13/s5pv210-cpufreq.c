static void s5pv210_set_refresh(enum s5pv210_dmc_port ch, unsigned long freq)
{
unsigned long tmp, tmp1;
void __iomem *reg = NULL;
if (ch == DMC0) {
reg = (S5P_VA_DMC0 + 0x30);
} else if (ch == DMC1) {
reg = (S5P_VA_DMC1 + 0x30);
} else {
printk(KERN_ERR "Cannot find DMC port\n");
return;
}
tmp = s5pv210_dram_conf[ch].freq;
do_div(tmp, freq);
tmp1 = s5pv210_dram_conf[ch].refresh;
do_div(tmp1, tmp);
__raw_writel(tmp1, reg);
}
static unsigned int s5pv210_getspeed(unsigned int cpu)
{
if (cpu)
return 0;
return clk_get_rate(cpu_clk) / 1000;
}
static int s5pv210_target(struct cpufreq_policy *policy, unsigned int index)
{
unsigned long reg;
unsigned int priv_index;
unsigned int pll_changing = 0;
unsigned int bus_speed_changing = 0;
unsigned int old_freq, new_freq;
int arm_volt, int_volt;
int ret = 0;
mutex_lock(&set_freq_lock);
if (no_cpufreq_access) {
#ifdef CONFIG_PM_VERBOSE
pr_err("%s:%d denied access to %s as it is disabled"
"temporarily\n", __FILE__, __LINE__, __func__);
#endif
ret = -EINVAL;
goto exit;
}
old_freq = s5pv210_getspeed(0);
new_freq = s5pv210_freq_table[index].frequency;
if (cpufreq_frequency_table_target(policy, s5pv210_freq_table,
old_freq, CPUFREQ_RELATION_H,
&priv_index)) {
ret = -EINVAL;
goto exit;
}
arm_volt = dvs_conf[index].arm_volt;
int_volt = dvs_conf[index].int_volt;
if (new_freq > old_freq) {
ret = regulator_set_voltage(arm_regulator,
arm_volt, arm_volt_max);
if (ret)
goto exit;
ret = regulator_set_voltage(int_regulator,
int_volt, int_volt_max);
if (ret)
goto exit;
}
if ((index == L0) || (priv_index == L0))
pll_changing = 1;
if ((index == L4) || (priv_index == L4))
bus_speed_changing = 1;
if (bus_speed_changing) {
if (pll_changing)
s5pv210_set_refresh(DMC1, 83000);
else
s5pv210_set_refresh(DMC1, 100000);
s5pv210_set_refresh(DMC0, 83000);
}
if (pll_changing) {
reg = __raw_readl(S5P_CLK_DIV2);
reg &= ~(S5P_CLKDIV2_G3D_MASK | S5P_CLKDIV2_MFC_MASK);
reg |= (3 << S5P_CLKDIV2_G3D_SHIFT) |
(3 << S5P_CLKDIV2_MFC_SHIFT);
__raw_writel(reg, S5P_CLK_DIV2);
do {
reg = __raw_readl(S5P_CLKDIV_STAT0);
} while (reg & ((1 << 16) | (1 << 17)));
reg = __raw_readl(S5P_CLK_SRC2);
reg &= ~(S5P_CLKSRC2_G3D_MASK | S5P_CLKSRC2_MFC_MASK);
reg |= (1 << S5P_CLKSRC2_G3D_SHIFT) |
(1 << S5P_CLKSRC2_MFC_SHIFT);
__raw_writel(reg, S5P_CLK_SRC2);
do {
reg = __raw_readl(S5P_CLKMUX_STAT1);
} while (reg & ((1 << 7) | (1 << 3)));
if (!bus_speed_changing)
s5pv210_set_refresh(DMC1, 133000);
reg = __raw_readl(S5P_CLK_SRC0);
reg &= ~(S5P_CLKSRC0_MUX200_MASK);
reg |= (0x1 << S5P_CLKSRC0_MUX200_SHIFT);
__raw_writel(reg, S5P_CLK_SRC0);
do {
reg = __raw_readl(S5P_CLKMUX_STAT0);
} while (reg & (0x1 << 18));
}
reg = __raw_readl(S5P_CLK_DIV0);
reg &= ~(S5P_CLKDIV0_APLL_MASK | S5P_CLKDIV0_A2M_MASK |
S5P_CLKDIV0_HCLK200_MASK | S5P_CLKDIV0_PCLK100_MASK |
S5P_CLKDIV0_HCLK166_MASK | S5P_CLKDIV0_PCLK83_MASK |
S5P_CLKDIV0_HCLK133_MASK | S5P_CLKDIV0_PCLK66_MASK);
reg |= ((clkdiv_val[index][0] << S5P_CLKDIV0_APLL_SHIFT) |
(clkdiv_val[index][1] << S5P_CLKDIV0_A2M_SHIFT) |
(clkdiv_val[index][2] << S5P_CLKDIV0_HCLK200_SHIFT) |
(clkdiv_val[index][3] << S5P_CLKDIV0_PCLK100_SHIFT) |
(clkdiv_val[index][4] << S5P_CLKDIV0_HCLK166_SHIFT) |
(clkdiv_val[index][5] << S5P_CLKDIV0_PCLK83_SHIFT) |
(clkdiv_val[index][6] << S5P_CLKDIV0_HCLK133_SHIFT) |
(clkdiv_val[index][7] << S5P_CLKDIV0_PCLK66_SHIFT));
__raw_writel(reg, S5P_CLK_DIV0);
do {
reg = __raw_readl(S5P_CLKDIV_STAT0);
} while (reg & 0xff);
reg = __raw_readl(S5P_ARM_MCS_CON);
reg &= ~0x3;
if (index >= L3)
reg |= 0x3;
else
reg |= 0x1;
__raw_writel(reg, S5P_ARM_MCS_CON);
if (pll_changing) {
__raw_writel(0x2cf, S5P_APLL_LOCK);
if (index == L0)
__raw_writel(APLL_VAL_1000, S5P_APLL_CON);
else
__raw_writel(APLL_VAL_800, S5P_APLL_CON);
do {
reg = __raw_readl(S5P_APLL_CON);
} while (!(reg & (0x1 << 29)));
reg = __raw_readl(S5P_CLK_SRC2);
reg &= ~(S5P_CLKSRC2_G3D_MASK | S5P_CLKSRC2_MFC_MASK);
reg |= (0 << S5P_CLKSRC2_G3D_SHIFT) |
(0 << S5P_CLKSRC2_MFC_SHIFT);
__raw_writel(reg, S5P_CLK_SRC2);
do {
reg = __raw_readl(S5P_CLKMUX_STAT1);
} while (reg & ((1 << 7) | (1 << 3)));
reg = __raw_readl(S5P_CLK_DIV2);
reg &= ~(S5P_CLKDIV2_G3D_MASK | S5P_CLKDIV2_MFC_MASK);
reg |= (clkdiv_val[index][10] << S5P_CLKDIV2_G3D_SHIFT) |
(clkdiv_val[index][9] << S5P_CLKDIV2_MFC_SHIFT);
__raw_writel(reg, S5P_CLK_DIV2);
do {
reg = __raw_readl(S5P_CLKDIV_STAT0);
} while (reg & ((1 << 16) | (1 << 17)));
reg = __raw_readl(S5P_CLK_SRC0);
reg &= ~(S5P_CLKSRC0_MUX200_MASK);
reg |= (0x0 << S5P_CLKSRC0_MUX200_SHIFT);
__raw_writel(reg, S5P_CLK_SRC0);
do {
reg = __raw_readl(S5P_CLKMUX_STAT0);
} while (reg & (0x1 << 18));
if (!bus_speed_changing)
s5pv210_set_refresh(DMC1, 200000);
}
if (bus_speed_changing) {
reg = __raw_readl(S5P_CLK_DIV6);
reg &= ~S5P_CLKDIV6_ONEDRAM_MASK;
reg |= (clkdiv_val[index][8] << S5P_CLKDIV6_ONEDRAM_SHIFT);
__raw_writel(reg, S5P_CLK_DIV6);
do {
reg = __raw_readl(S5P_CLKDIV_STAT1);
} while (reg & (1 << 15));
if (index != L4) {
s5pv210_set_refresh(DMC0, 166000);
s5pv210_set_refresh(DMC1, 200000);
} else {
s5pv210_set_refresh(DMC0, 83000);
s5pv210_set_refresh(DMC1, 100000);
}
}
if (new_freq < old_freq) {
regulator_set_voltage(int_regulator,
int_volt, int_volt_max);
regulator_set_voltage(arm_regulator,
arm_volt, arm_volt_max);
}
printk(KERN_DEBUG "Perf changed[L%d]\n", index);
exit:
mutex_unlock(&set_freq_lock);
return ret;
}
static int s5pv210_cpufreq_suspend(struct cpufreq_policy *policy)
{
return 0;
}
static int s5pv210_cpufreq_resume(struct cpufreq_policy *policy)
{
return 0;
}
static int check_mem_type(void __iomem *dmc_reg)
{
unsigned long val;
val = __raw_readl(dmc_reg + 0x4);
val = (val & (0xf << 8));
return val >> 8;
}
static int __init s5pv210_cpu_init(struct cpufreq_policy *policy)
{
unsigned long mem_type;
int ret;
cpu_clk = clk_get(NULL, "armclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
dmc0_clk = clk_get(NULL, "sclk_dmc0");
if (IS_ERR(dmc0_clk)) {
ret = PTR_ERR(dmc0_clk);
goto out_dmc0;
}
dmc1_clk = clk_get(NULL, "hclk_msys");
if (IS_ERR(dmc1_clk)) {
ret = PTR_ERR(dmc1_clk);
goto out_dmc1;
}
if (policy->cpu != 0) {
ret = -EINVAL;
goto out_dmc1;
}
mem_type = check_mem_type(S5P_VA_DMC0);
if ((mem_type != LPDDR) && (mem_type != LPDDR2)) {
printk(KERN_ERR "CPUFreq doesn't support this memory type\n");
ret = -EINVAL;
goto out_dmc1;
}
s5pv210_dram_conf[0].refresh = (__raw_readl(S5P_VA_DMC0 + 0x30) * 1000);
s5pv210_dram_conf[0].freq = clk_get_rate(dmc0_clk);
s5pv210_dram_conf[1].refresh = (__raw_readl(S5P_VA_DMC1 + 0x30) * 1000);
s5pv210_dram_conf[1].freq = clk_get_rate(dmc1_clk);
return cpufreq_generic_init(policy, s5pv210_freq_table, 40000);
out_dmc1:
clk_put(dmc0_clk);
out_dmc0:
clk_put(cpu_clk);
return ret;
}
static int s5pv210_cpufreq_notifier_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
int ret;
switch (event) {
case PM_SUSPEND_PREPARE:
ret = cpufreq_driver_target(cpufreq_cpu_get(0), SLEEP_FREQ, 0);
if (ret < 0)
return NOTIFY_BAD;
no_cpufreq_access = true;
return NOTIFY_OK;
case PM_POST_RESTORE:
case PM_POST_SUSPEND:
no_cpufreq_access = false;
cpufreq_driver_target(cpufreq_cpu_get(0), SLEEP_FREQ, 0);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int s5pv210_cpufreq_reboot_notifier_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
int ret;
ret = cpufreq_driver_target(cpufreq_cpu_get(0), SLEEP_FREQ, 0);
if (ret < 0)
return NOTIFY_BAD;
no_cpufreq_access = true;
return NOTIFY_DONE;
}
static int __init s5pv210_cpufreq_init(void)
{
arm_regulator = regulator_get(NULL, "vddarm");
if (IS_ERR(arm_regulator)) {
pr_err("failed to get regulator vddarm");
return PTR_ERR(arm_regulator);
}
int_regulator = regulator_get(NULL, "vddint");
if (IS_ERR(int_regulator)) {
pr_err("failed to get regulator vddint");
regulator_put(arm_regulator);
return PTR_ERR(int_regulator);
}
register_pm_notifier(&s5pv210_cpufreq_notifier);
register_reboot_notifier(&s5pv210_cpufreq_reboot_notifier);
return cpufreq_register_driver(&s5pv210_driver);
}
