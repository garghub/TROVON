static int exynos_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy,
exynos_info->freq_table);
}
static unsigned int exynos_getspeed(unsigned int cpu)
{
return clk_get_rate(exynos_info->cpu_clk) / 1000;
}
static int exynos_cpufreq_get_index(unsigned int freq)
{
struct cpufreq_frequency_table *freq_table = exynos_info->freq_table;
int index;
for (index = 0;
freq_table[index].frequency != CPUFREQ_TABLE_END; index++)
if (freq_table[index].frequency == freq)
break;
if (freq_table[index].frequency == CPUFREQ_TABLE_END)
return -EINVAL;
return index;
}
static int exynos_cpufreq_scale(unsigned int target_freq)
{
struct cpufreq_frequency_table *freq_table = exynos_info->freq_table;
unsigned int *volt_table = exynos_info->volt_table;
struct cpufreq_policy *policy = cpufreq_cpu_get(0);
unsigned int arm_volt, safe_arm_volt = 0;
unsigned int mpll_freq_khz = exynos_info->mpll_freq_khz;
int index, old_index;
int ret = 0;
freqs.old = policy->cur;
freqs.new = target_freq;
freqs.cpu = policy->cpu;
if (freqs.new == freqs.old)
goto out;
old_index = exynos_cpufreq_get_index(freqs.old);
if (old_index < 0) {
ret = old_index;
goto out;
}
index = exynos_cpufreq_get_index(target_freq);
if (index < 0) {
ret = index;
goto out;
}
if (exynos_info->need_apll_change != NULL) {
if (exynos_info->need_apll_change(old_index, index) &&
(freq_table[index].frequency < mpll_freq_khz) &&
(freq_table[old_index].frequency < mpll_freq_khz))
safe_arm_volt = volt_table[exynos_info->pll_safe_idx];
}
arm_volt = volt_table[index];
for_each_cpu(freqs.cpu, policy->cpus)
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
if ((freqs.new > freqs.old) && !safe_arm_volt) {
ret = regulator_set_voltage(arm_regulator, arm_volt, arm_volt);
if (ret) {
pr_err("%s: failed to set cpu voltage to %d\n",
__func__, arm_volt);
goto out;
}
}
if (safe_arm_volt) {
ret = regulator_set_voltage(arm_regulator, safe_arm_volt,
safe_arm_volt);
if (ret) {
pr_err("%s: failed to set cpu voltage to %d\n",
__func__, safe_arm_volt);
goto out;
}
}
exynos_info->set_freq(old_index, index);
for_each_cpu(freqs.cpu, policy->cpus)
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
if ((freqs.new < freqs.old) ||
((freqs.new > freqs.old) && safe_arm_volt)) {
regulator_set_voltage(arm_regulator, arm_volt,
arm_volt);
if (ret) {
pr_err("%s: failed to set cpu voltage to %d\n",
__func__, arm_volt);
goto out;
}
}
out:
cpufreq_cpu_put(policy);
return ret;
}
static int exynos_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_frequency_table *freq_table = exynos_info->freq_table;
unsigned int index;
unsigned int new_freq;
int ret = 0;
mutex_lock(&cpufreq_lock);
if (frequency_locked)
goto out;
if (cpufreq_frequency_table_target(policy, freq_table,
target_freq, relation, &index)) {
ret = -EINVAL;
goto out;
}
new_freq = freq_table[index].frequency;
ret = exynos_cpufreq_scale(new_freq);
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
int ret;
switch (pm_event) {
case PM_SUSPEND_PREPARE:
mutex_lock(&cpufreq_lock);
frequency_locked = true;
mutex_unlock(&cpufreq_lock);
ret = exynos_cpufreq_scale(locking_frequency);
if (ret < 0)
return NOTIFY_BAD;
break;
case PM_POST_SUSPEND:
mutex_lock(&cpufreq_lock);
frequency_locked = false;
mutex_unlock(&cpufreq_lock);
break;
}
return NOTIFY_OK;
}
static int exynos_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->cur = policy->min = policy->max = exynos_getspeed(policy->cpu);
cpufreq_frequency_table_get_attr(exynos_info->freq_table, policy->cpu);
policy->cpuinfo.transition_latency = 100000;
cpumask_setall(policy->cpus);
return cpufreq_frequency_table_cpuinfo(policy, exynos_info->freq_table);
}
static int exynos_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
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
locking_frequency = exynos_getspeed(0);
register_pm_notifier(&exynos_cpufreq_nb);
if (cpufreq_register_driver(&exynos_driver)) {
pr_err("%s: failed to register cpufreq driver\n", __func__);
goto err_cpufreq;
}
return 0;
err_cpufreq:
unregister_pm_notifier(&exynos_cpufreq_nb);
regulator_put(arm_regulator);
err_vdd_arm:
kfree(exynos_info);
pr_debug("%s: failed initialization\n", __func__);
return -EINVAL;
}
