static int tegra_cpu_clk_set_rate(unsigned long rate)
{
int ret;
clk_prepare_enable(pll_x_clk);
ret = clk_set_parent(cpu_clk, pll_p_clk);
if (ret) {
pr_err("Failed to switch cpu to clock pll_p\n");
goto out;
}
if (rate == clk_get_rate(pll_p_clk))
goto out;
ret = clk_set_rate(pll_x_clk, rate);
if (ret) {
pr_err("Failed to change pll_x to %lu\n", rate);
goto out;
}
ret = clk_set_parent(cpu_clk, pll_x_clk);
if (ret) {
pr_err("Failed to switch cpu to clock pll_x\n");
goto out;
}
out:
clk_disable_unprepare(pll_x_clk);
return ret;
}
static int tegra_update_cpu_speed(struct cpufreq_policy *policy,
unsigned long rate)
{
int ret = 0;
if (rate >= 816000)
clk_set_rate(emc_clk, 600000000);
else if (rate >= 456000)
clk_set_rate(emc_clk, 300000000);
else
clk_set_rate(emc_clk, 100000000);
ret = tegra_cpu_clk_set_rate(rate * 1000);
if (ret)
pr_err("cpu-tegra: Failed to set cpu frequency to %lu kHz\n",
rate);
return ret;
}
static int tegra_target(struct cpufreq_policy *policy, unsigned int index)
{
int ret = -EBUSY;
mutex_lock(&tegra_cpu_lock);
if (!is_suspended)
ret = tegra_update_cpu_speed(policy,
freq_table[index].frequency);
mutex_unlock(&tegra_cpu_lock);
return ret;
}
static int tegra_pm_notify(struct notifier_block *nb, unsigned long event,
void *dummy)
{
mutex_lock(&tegra_cpu_lock);
if (event == PM_SUSPEND_PREPARE) {
struct cpufreq_policy *policy = cpufreq_cpu_get(0);
is_suspended = true;
pr_info("Tegra cpufreq suspend: setting frequency to %d kHz\n",
freq_table[0].frequency);
if (clk_get_rate(cpu_clk) / 1000 != freq_table[0].frequency)
tegra_update_cpu_speed(policy, freq_table[0].frequency);
cpufreq_cpu_put(policy);
} else if (event == PM_POST_SUSPEND) {
is_suspended = false;
}
mutex_unlock(&tegra_cpu_lock);
return NOTIFY_OK;
}
static int tegra_cpu_init(struct cpufreq_policy *policy)
{
int ret;
if (policy->cpu >= NUM_CPUS)
return -EINVAL;
clk_prepare_enable(emc_clk);
clk_prepare_enable(cpu_clk);
ret = cpufreq_generic_init(policy, freq_table, 300 * 1000);
if (ret) {
clk_disable_unprepare(cpu_clk);
clk_disable_unprepare(emc_clk);
return ret;
}
if (policy->cpu == 0)
register_pm_notifier(&tegra_cpu_pm_notifier);
policy->clk = cpu_clk;
return 0;
}
static int tegra_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
clk_disable_unprepare(cpu_clk);
clk_disable_unprepare(emc_clk);
return 0;
}
static int __init tegra_cpufreq_init(void)
{
cpu_clk = clk_get_sys(NULL, "cclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
pll_x_clk = clk_get_sys(NULL, "pll_x");
if (IS_ERR(pll_x_clk))
return PTR_ERR(pll_x_clk);
pll_p_clk = clk_get_sys(NULL, "pll_p");
if (IS_ERR(pll_p_clk))
return PTR_ERR(pll_p_clk);
emc_clk = clk_get_sys("cpu", "emc");
if (IS_ERR(emc_clk)) {
clk_put(cpu_clk);
return PTR_ERR(emc_clk);
}
return cpufreq_register_driver(&tegra_cpufreq_driver);
}
static void __exit tegra_cpufreq_exit(void)
{
cpufreq_unregister_driver(&tegra_cpufreq_driver);
clk_put(emc_clk);
clk_put(cpu_clk);
}
