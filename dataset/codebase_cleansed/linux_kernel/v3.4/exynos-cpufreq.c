int exynos_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy,
exynos_info->freq_table);
}
unsigned int exynos_getspeed(unsigned int cpu)
{
return clk_get_rate(exynos_info->cpu_clk) / 1000;
}
static int exynos_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int index, old_index;
unsigned int arm_volt, safe_arm_volt = 0;
int ret = 0;
struct cpufreq_frequency_table *freq_table = exynos_info->freq_table;
unsigned int *volt_table = exynos_info->volt_table;
unsigned int mpll_freq_khz = exynos_info->mpll_freq_khz;
mutex_lock(&cpufreq_lock);
freqs.old = policy->cur;
if (frequency_locked && target_freq != locking_frequency) {
ret = -EAGAIN;
goto out;
}
if (cpufreq_frequency_table_target(policy, freq_table,
freqs.old, relation, &old_index)) {
ret = -EINVAL;
goto out;
}
if (cpufreq_frequency_table_target(policy, freq_table,
target_freq, relation, &index)) {
ret = -EINVAL;
goto out;
}
freqs.new = freq_table[index].frequency;
freqs.cpu = policy->cpu;
if (exynos_info->need_apll_change != NULL) {
if (exynos_info->need_apll_change(old_index, index) &&
(freq_table[index].frequency < mpll_freq_khz) &&
(freq_table[old_index].frequency < mpll_freq_khz))
safe_arm_volt = volt_table[exynos_info->pll_safe_idx];
}
arm_volt = volt_table[index];
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
if ((freqs.new > freqs.old) && !safe_arm_volt) {
regulator_set_voltage(arm_regulator, arm_volt,
arm_volt);
}
if (safe_arm_volt)
regulator_set_voltage(arm_regulator, safe_arm_volt,
safe_arm_volt);
if (freqs.new != freqs.old)
exynos_info->set_freq(old_index, index);
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
if ((freqs.new < freqs.old) ||
((freqs.new > freqs.old) && safe_arm_volt)) {
regulator_set_voltage(arm_regulator, arm_volt,
arm_volt);
}
out:
mutex_unlock(&cpufreq_lock);
return ret;
}
static int exynos_cpufreq_suspend(struct cpufreq_policy *policy)
{
return 0;
}
static int exynos_cpufreq_resume(struct cpufreq_policy *policy)
{
return 0;
}
static int exynos_cpufreq_pm_notifier(struct notifier_block *notifier,
unsigned long pm_event, void *v)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(0);
static unsigned int saved_frequency;
unsigned int temp;
mutex_lock(&cpufreq_lock);
switch (pm_event) {
case PM_SUSPEND_PREPARE:
if (frequency_locked)
goto out;
frequency_locked = true;
if (locking_frequency) {
saved_frequency = exynos_getspeed(0);
mutex_unlock(&cpufreq_lock);
exynos_target(policy, locking_frequency,
CPUFREQ_RELATION_H);
mutex_lock(&cpufreq_lock);
}
break;
case PM_POST_SUSPEND:
if (saved_frequency) {
temp = locking_frequency;
locking_frequency = saved_frequency;
mutex_unlock(&cpufreq_lock);
exynos_target(policy, locking_frequency,
CPUFREQ_RELATION_H);
mutex_lock(&cpufreq_lock);
locking_frequency = temp;
}
frequency_locked = false;
break;
}
out:
mutex_unlock(&cpufreq_lock);
return NOTIFY_OK;
}
static int exynos_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->cur = policy->min = policy->max = exynos_getspeed(policy->cpu);
cpufreq_frequency_table_get_attr(exynos_info->freq_table, policy->cpu);
locking_frequency = exynos_getspeed(0);
policy->cpuinfo.transition_latency = 100000;
if (num_online_cpus() == 1) {
cpumask_copy(policy->related_cpus, cpu_possible_mask);
cpumask_copy(policy->cpus, cpu_online_mask);
} else {
cpumask_setall(policy->cpus);
}
return cpufreq_frequency_table_cpuinfo(policy, exynos_info->freq_table);
}
static int __init exynos_cpufreq_init(void)
{
int ret = -EINVAL;
exynos_info = kzalloc(sizeof(struct exynos_dvfs_info), GFP_KERNEL);
if (!exynos_info)
return -ENOMEM;
if (soc_is_exynos4210())
ret = exynos4210_cpufreq_init(exynos_info);
else if (soc_is_exynos4212() || soc_is_exynos4412())
ret = exynos4x12_cpufreq_init(exynos_info);
else if (soc_is_exynos5250())
ret = exynos5250_cpufreq_init(exynos_info);
else
pr_err("%s: CPU type not found\n", __func__);
if (ret)
goto err_vdd_arm;
if (exynos_info->set_freq == NULL) {
pr_err("%s: No set_freq function (ERR)\n", __func__);
goto err_vdd_arm;
}
arm_regulator = regulator_get(NULL, "vdd_arm");
if (IS_ERR(arm_regulator)) {
pr_err("%s: failed to get resource vdd_arm\n", __func__);
goto err_vdd_arm;
}
register_pm_notifier(&exynos_cpufreq_nb);
if (cpufreq_register_driver(&exynos_driver)) {
pr_err("%s: failed to register cpufreq driver\n", __func__);
goto err_cpufreq;
}
return 0;
err_cpufreq:
unregister_pm_notifier(&exynos_cpufreq_nb);
if (!IS_ERR(arm_regulator))
regulator_put(arm_regulator);
err_vdd_arm:
kfree(exynos_info);
pr_debug("%s: failed initialization\n", __func__);
return -EINVAL;
}
