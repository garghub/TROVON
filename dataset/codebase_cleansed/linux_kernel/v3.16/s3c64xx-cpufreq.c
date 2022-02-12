static int s3c64xx_cpufreq_set_target(struct cpufreq_policy *policy,
unsigned int index)
{
struct s3c64xx_dvfs *dvfs;
unsigned int old_freq, new_freq;
int ret;
old_freq = clk_get_rate(policy->clk) / 1000;
new_freq = s3c64xx_freq_table[index].frequency;
dvfs = &s3c64xx_dvfs_table[s3c64xx_freq_table[index].driver_data];
#ifdef CONFIG_REGULATOR
if (vddarm && new_freq > old_freq) {
ret = regulator_set_voltage(vddarm,
dvfs->vddarm_min,
dvfs->vddarm_max);
if (ret != 0) {
pr_err("Failed to set VDDARM for %dkHz: %d\n",
new_freq, ret);
return ret;
}
}
#endif
ret = clk_set_rate(policy->clk, new_freq * 1000);
if (ret < 0) {
pr_err("Failed to set rate %dkHz: %d\n",
new_freq, ret);
return ret;
}
#ifdef CONFIG_REGULATOR
if (vddarm && new_freq < old_freq) {
ret = regulator_set_voltage(vddarm,
dvfs->vddarm_min,
dvfs->vddarm_max);
if (ret != 0) {
pr_err("Failed to set VDDARM for %dkHz: %d\n",
new_freq, ret);
if (clk_set_rate(policy->clk, old_freq * 1000) < 0)
pr_err("Failed to restore original clock rate\n");
return ret;
}
}
#endif
pr_debug("Set actual frequency %lukHz\n",
clk_get_rate(policy->clk) / 1000);
return 0;
}
static void __init s3c64xx_cpufreq_config_regulator(void)
{
int count, v, i, found;
struct cpufreq_frequency_table *freq;
struct s3c64xx_dvfs *dvfs;
count = regulator_count_voltages(vddarm);
if (count < 0) {
pr_err("Unable to check supported voltages\n");
}
if (!count)
goto out;
cpufreq_for_each_valid_entry(freq, s3c64xx_freq_table) {
dvfs = &s3c64xx_dvfs_table[freq->driver_data];
found = 0;
for (i = 0; i < count; i++) {
v = regulator_list_voltage(vddarm, i);
if (v >= dvfs->vddarm_min && v <= dvfs->vddarm_max)
found = 1;
}
if (!found) {
pr_debug("%dkHz unsupported by regulator\n",
freq->frequency);
freq->frequency = CPUFREQ_ENTRY_INVALID;
}
}
out:
regulator_latency = 1 * 1000 * 1000;
}
static int s3c64xx_cpufreq_driver_init(struct cpufreq_policy *policy)
{
int ret;
struct cpufreq_frequency_table *freq;
if (policy->cpu != 0)
return -EINVAL;
if (s3c64xx_freq_table == NULL) {
pr_err("No frequency information for this CPU\n");
return -ENODEV;
}
policy->clk = clk_get(NULL, "armclk");
if (IS_ERR(policy->clk)) {
pr_err("Unable to obtain ARMCLK: %ld\n",
PTR_ERR(policy->clk));
return PTR_ERR(policy->clk);
}
#ifdef CONFIG_REGULATOR
vddarm = regulator_get(NULL, "vddarm");
if (IS_ERR(vddarm)) {
ret = PTR_ERR(vddarm);
pr_err("Failed to obtain VDDARM: %d\n", ret);
pr_err("Only frequency scaling available\n");
vddarm = NULL;
} else {
s3c64xx_cpufreq_config_regulator();
}
#endif
cpufreq_for_each_entry(freq, s3c64xx_freq_table) {
unsigned long r;
r = clk_round_rate(policy->clk, freq->frequency * 1000);
r /= 1000;
if (r != freq->frequency) {
pr_debug("%dkHz unsupported by clock\n",
freq->frequency);
freq->frequency = CPUFREQ_ENTRY_INVALID;
}
if (!vddarm && freq->frequency > clk_get_rate(policy->clk) / 1000)
freq->frequency = CPUFREQ_ENTRY_INVALID;
}
ret = cpufreq_generic_init(policy, s3c64xx_freq_table,
(500 * 1000) + regulator_latency);
if (ret != 0) {
pr_err("Failed to configure frequency table: %d\n",
ret);
regulator_put(vddarm);
clk_put(policy->clk);
}
return ret;
}
static int __init s3c64xx_cpufreq_init(void)
{
return cpufreq_register_driver(&s3c64xx_cpufreq_driver);
}
