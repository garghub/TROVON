static int s3c2416_cpufreq_verify_speed(struct cpufreq_policy *policy)
{
struct s3c2416_data *s3c_freq = &s3c2416_cpufreq;
if (policy->cpu != 0)
return -EINVAL;
return cpufreq_frequency_table_verify(policy, s3c_freq->freq_table);
}
static unsigned int s3c2416_cpufreq_get_speed(unsigned int cpu)
{
struct s3c2416_data *s3c_freq = &s3c2416_cpufreq;
if (cpu != 0)
return 0;
if (s3c_freq->is_dvs)
return FREQ_DVS;
return clk_get_rate(s3c_freq->armclk) / 1000;
}
static int s3c2416_cpufreq_set_armdiv(struct s3c2416_data *s3c_freq,
unsigned int freq)
{
int ret;
if (clk_get_rate(s3c_freq->armdiv) / 1000 != freq) {
ret = clk_set_rate(s3c_freq->armdiv, freq * 1000);
if (ret < 0) {
pr_err("cpufreq: Failed to set armdiv rate %dkHz: %d\n",
freq, ret);
return ret;
}
}
return 0;
}
static int s3c2416_cpufreq_enter_dvs(struct s3c2416_data *s3c_freq, int idx)
{
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
struct s3c2416_dvfs *dvfs;
#endif
int ret;
if (s3c_freq->is_dvs) {
pr_debug("cpufreq: already in dvs mode, nothing to do\n");
return 0;
}
pr_debug("cpufreq: switching armclk to hclk (%lukHz)\n",
clk_get_rate(s3c_freq->hclk) / 1000);
ret = clk_set_parent(s3c_freq->armclk, s3c_freq->hclk);
if (ret < 0) {
pr_err("cpufreq: Failed to switch armclk to hclk: %d\n", ret);
return ret;
}
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
if (s3c_freq->vddarm) {
dvfs = &s3c2416_dvfs_table[idx];
pr_debug("cpufreq: setting regulator to %d-%d\n",
dvfs->vddarm_min, dvfs->vddarm_max);
ret = regulator_set_voltage(s3c_freq->vddarm,
dvfs->vddarm_min,
dvfs->vddarm_max);
if (ret != 0)
pr_err("cpufreq: Failed to set VDDARM: %d\n", ret);
}
#endif
s3c_freq->is_dvs = 1;
return 0;
}
static int s3c2416_cpufreq_leave_dvs(struct s3c2416_data *s3c_freq, int idx)
{
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
struct s3c2416_dvfs *dvfs;
#endif
int ret;
if (!s3c_freq->is_dvs) {
pr_debug("cpufreq: not in dvs mode, so can't leave\n");
return 0;
}
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
if (s3c_freq->vddarm) {
dvfs = &s3c2416_dvfs_table[idx];
pr_debug("cpufreq: setting regulator to %d-%d\n",
dvfs->vddarm_min, dvfs->vddarm_max);
ret = regulator_set_voltage(s3c_freq->vddarm,
dvfs->vddarm_min,
dvfs->vddarm_max);
if (ret != 0) {
pr_err("cpufreq: Failed to set VDDARM: %d\n", ret);
return ret;
}
}
#endif
if (clk_get_rate(s3c_freq->armdiv) > clk_get_rate(s3c_freq->hclk)) {
pr_debug("cpufreq: force armdiv to hclk frequency (%lukHz)\n",
clk_get_rate(s3c_freq->hclk) / 1000);
ret = s3c2416_cpufreq_set_armdiv(s3c_freq,
clk_get_rate(s3c_freq->hclk) / 1000);
if (ret < 0) {
pr_err("cpufreq: Failed to to set the armdiv to %lukHz: %d\n",
clk_get_rate(s3c_freq->hclk) / 1000, ret);
return ret;
}
}
pr_debug("cpufreq: switching armclk parent to armdiv (%lukHz)\n",
clk_get_rate(s3c_freq->armdiv) / 1000);
ret = clk_set_parent(s3c_freq->armclk, s3c_freq->armdiv);
if (ret < 0) {
pr_err("cpufreq: Failed to switch armclk clock parent to armdiv: %d\n",
ret);
return ret;
}
s3c_freq->is_dvs = 0;
return 0;
}
static int s3c2416_cpufreq_set_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct s3c2416_data *s3c_freq = &s3c2416_cpufreq;
struct cpufreq_freqs freqs;
int idx, ret, to_dvs = 0;
unsigned int i;
mutex_lock(&cpufreq_lock);
pr_debug("cpufreq: to %dKHz, relation %d\n", target_freq, relation);
ret = cpufreq_frequency_table_target(policy, s3c_freq->freq_table,
target_freq, relation, &i);
if (ret != 0)
goto out;
idx = s3c_freq->freq_table[i].index;
if (idx == SOURCE_HCLK)
to_dvs = 1;
if (to_dvs && s3c_freq->disable_dvs) {
pr_debug("cpufreq: entering dvs mode not allowed\n");
ret = -EINVAL;
goto out;
}
freqs.flags = 0;
freqs.old = s3c_freq->is_dvs ? FREQ_DVS
: clk_get_rate(s3c_freq->armclk) / 1000;
freqs.new = (s3c_freq->is_dvs && !to_dvs)
? clk_get_rate(s3c_freq->hclk) / 1000
: s3c_freq->freq_table[i].frequency;
pr_debug("cpufreq: Transition %d-%dkHz\n", freqs.old, freqs.new);
if (!to_dvs && freqs.old == freqs.new)
goto out;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
if (to_dvs) {
pr_debug("cpufreq: enter dvs\n");
ret = s3c2416_cpufreq_enter_dvs(s3c_freq, idx);
} else if (s3c_freq->is_dvs) {
pr_debug("cpufreq: leave dvs\n");
ret = s3c2416_cpufreq_leave_dvs(s3c_freq, idx);
} else {
pr_debug("cpufreq: change armdiv to %dkHz\n", freqs.new);
ret = s3c2416_cpufreq_set_armdiv(s3c_freq, freqs.new);
}
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
out:
mutex_unlock(&cpufreq_lock);
return ret;
}
static void __init s3c2416_cpufreq_cfg_regulator(struct s3c2416_data *s3c_freq)
{
int count, v, i, found;
struct cpufreq_frequency_table *freq;
struct s3c2416_dvfs *dvfs;
count = regulator_count_voltages(s3c_freq->vddarm);
if (count < 0) {
pr_err("cpufreq: Unable to check supported voltages\n");
return;
}
freq = s3c_freq->freq_table;
while (count > 0 && freq->frequency != CPUFREQ_TABLE_END) {
if (freq->frequency == CPUFREQ_ENTRY_INVALID)
continue;
dvfs = &s3c2416_dvfs_table[freq->index];
found = 0;
for (i = 0; i < count; i++) {
v = regulator_list_voltage(s3c_freq->vddarm, i);
if (v >= dvfs->vddarm_min)
found = 1;
}
if (!found) {
pr_debug("cpufreq: %dkHz unsupported by regulator\n",
freq->frequency);
freq->frequency = CPUFREQ_ENTRY_INVALID;
}
freq++;
}
s3c_freq->regulator_latency = 1 * 1000 * 1000;
}
static int s3c2416_cpufreq_reboot_notifier_evt(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct s3c2416_data *s3c_freq = &s3c2416_cpufreq;
int ret;
mutex_lock(&cpufreq_lock);
s3c_freq->disable_dvs = 1;
mutex_unlock(&cpufreq_lock);
if (s3c_freq->is_dvs) {
pr_debug("cpufreq: leave dvs on reboot\n");
ret = cpufreq_driver_target(cpufreq_cpu_get(0), FREQ_SLEEP, 0);
if (ret < 0)
return NOTIFY_BAD;
}
return NOTIFY_DONE;
}
static int __init s3c2416_cpufreq_driver_init(struct cpufreq_policy *policy)
{
struct s3c2416_data *s3c_freq = &s3c2416_cpufreq;
struct cpufreq_frequency_table *freq;
struct clk *msysclk;
unsigned long rate;
int ret;
if (policy->cpu != 0)
return -EINVAL;
msysclk = clk_get(NULL, "msysclk");
if (IS_ERR(msysclk)) {
ret = PTR_ERR(msysclk);
pr_err("cpufreq: Unable to obtain msysclk: %d\n", ret);
return ret;
}
rate = clk_get_rate(msysclk);
if (rate == 800 * 1000 * 1000) {
pr_info("cpufreq: msysclk running at %lukHz, using S3C2416 frequency table\n",
rate / 1000);
s3c_freq->freq_table = s3c2416_freq_table;
policy->cpuinfo.max_freq = 400000;
} else if (rate / 1000 == 534000) {
pr_info("cpufreq: msysclk running at %lukHz, using S3C2450 frequency table\n",
rate / 1000);
s3c_freq->freq_table = s3c2450_freq_table;
policy->cpuinfo.max_freq = 534000;
}
clk_put(msysclk);
if (s3c_freq->freq_table == NULL) {
pr_err("cpufreq: No frequency information for this CPU, msysclk at %lukHz\n",
rate / 1000);
return -ENODEV;
}
s3c_freq->is_dvs = 0;
s3c_freq->armdiv = clk_get(NULL, "armdiv");
if (IS_ERR(s3c_freq->armdiv)) {
ret = PTR_ERR(s3c_freq->armdiv);
pr_err("cpufreq: Unable to obtain ARMDIV: %d\n", ret);
return ret;
}
s3c_freq->hclk = clk_get(NULL, "hclk");
if (IS_ERR(s3c_freq->hclk)) {
ret = PTR_ERR(s3c_freq->hclk);
pr_err("cpufreq: Unable to obtain HCLK: %d\n", ret);
goto err_hclk;
}
rate = clk_get_rate(s3c_freq->hclk);
if (rate < 133 * 1000 * 1000) {
pr_err("cpufreq: HCLK not at 133MHz\n");
clk_put(s3c_freq->hclk);
ret = -EINVAL;
goto err_armclk;
}
s3c_freq->armclk = clk_get(NULL, "armclk");
if (IS_ERR(s3c_freq->armclk)) {
ret = PTR_ERR(s3c_freq->armclk);
pr_err("cpufreq: Unable to obtain ARMCLK: %d\n", ret);
goto err_armclk;
}
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
s3c_freq->vddarm = regulator_get(NULL, "vddarm");
if (IS_ERR(s3c_freq->vddarm)) {
ret = PTR_ERR(s3c_freq->vddarm);
pr_err("cpufreq: Failed to obtain VDDARM: %d\n", ret);
goto err_vddarm;
}
s3c2416_cpufreq_cfg_regulator(s3c_freq);
#else
s3c_freq->regulator_latency = 0;
#endif
freq = s3c_freq->freq_table;
while (freq->frequency != CPUFREQ_TABLE_END) {
if (freq->index == 0) {
if (!s3c_freq->hclk) {
pr_debug("cpufreq: %dkHz unsupported as it would need unavailable dvs mode\n",
freq->frequency);
freq->frequency = CPUFREQ_ENTRY_INVALID;
} else {
freq++;
continue;
}
}
rate = clk_round_rate(s3c_freq->armdiv,
freq->frequency * 1000);
rate /= 1000;
if (rate != freq->frequency) {
pr_debug("cpufreq: %dkHz unsupported by clock (clk_round_rate return %lu)\n",
freq->frequency, rate);
freq->frequency = CPUFREQ_ENTRY_INVALID;
}
freq++;
}
policy->cur = clk_get_rate(s3c_freq->armclk) / 1000;
policy->cpuinfo.transition_latency = (500 * 1000) +
s3c_freq->regulator_latency;
ret = cpufreq_frequency_table_cpuinfo(policy, s3c_freq->freq_table);
if (ret)
goto err_freq_table;
cpufreq_frequency_table_get_attr(s3c_freq->freq_table, 0);
register_reboot_notifier(&s3c2416_cpufreq_reboot_notifier);
return 0;
err_freq_table:
#ifdef CONFIG_ARM_S3C2416_CPUFREQ_VCORESCALE
regulator_put(s3c_freq->vddarm);
err_vddarm:
#endif
clk_put(s3c_freq->armclk);
err_armclk:
clk_put(s3c_freq->hclk);
err_hclk:
clk_put(s3c_freq->armdiv);
return ret;
}
static int __init s3c2416_cpufreq_init(void)
{
return cpufreq_register_driver(&s3c2416_cpufreq_driver);
}
