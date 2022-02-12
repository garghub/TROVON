static int tegra_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, freq_table);
}
static unsigned int tegra_getspeed(unsigned int cpu)
{
unsigned long rate;
if (cpu >= NUM_CPUS)
return 0;
rate = clk_get_rate(cpu_clk) / 1000;
return rate;
}
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
struct cpufreq_freqs freqs;
freqs.old = tegra_getspeed(0);
freqs.new = rate;
if (freqs.old == freqs.new)
return ret;
if (rate >= 816000)
clk_set_rate(emc_clk, 600000000);
else if (rate >= 456000)
clk_set_rate(emc_clk, 300000000);
else
clk_set_rate(emc_clk, 100000000);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
#ifdef CONFIG_CPU_FREQ_DEBUG
printk(KERN_DEBUG "cpufreq-tegra: transition: %u --> %u\n",
freqs.old, freqs.new);
#endif
ret = tegra_cpu_clk_set_rate(freqs.new * 1000);
if (ret) {
pr_err("cpu-tegra: Failed to set cpu frequency to %d kHz\n",
freqs.new);
freqs.new = freqs.old;
}
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return ret;
}
static unsigned long tegra_cpu_highest_speed(void)
{
unsigned long rate = 0;
int i;
for_each_online_cpu(i)
rate = max(rate, target_cpu_speed[i]);
return rate;
}
static int tegra_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int idx;
unsigned int freq;
int ret = 0;
mutex_lock(&tegra_cpu_lock);
if (is_suspended) {
ret = -EBUSY;
goto out;
}
cpufreq_frequency_table_target(policy, freq_table, target_freq,
relation, &idx);
freq = freq_table[idx].frequency;
target_cpu_speed[policy->cpu] = freq;
ret = tegra_update_cpu_speed(policy, tegra_cpu_highest_speed());
out:
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
if (policy->cpu >= NUM_CPUS)
return -EINVAL;
clk_prepare_enable(emc_clk);
clk_prepare_enable(cpu_clk);
cpufreq_frequency_table_cpuinfo(policy, freq_table);
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
policy->cur = tegra_getspeed(policy->cpu);
target_cpu_speed[policy->cpu] = policy->cur;
policy->cpuinfo.transition_latency = 300 * 1000;
cpumask_copy(policy->cpus, cpu_possible_mask);
if (policy->cpu == 0)
register_pm_notifier(&tegra_cpu_pm_notifier);
return 0;
}
static int tegra_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_cpuinfo(policy, freq_table);
clk_disable_unprepare(emc_clk);
return 0;
}
static int __init tegra_cpufreq_init(void)
{
cpu_clk = clk_get_sys(NULL, "cpu");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
pll_x_clk = clk_get_sys(NULL, "pll_x");
if (IS_ERR(pll_x_clk))
return PTR_ERR(pll_x_clk);
pll_p_clk = clk_get_sys(NULL, "pll_p_cclk");
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
