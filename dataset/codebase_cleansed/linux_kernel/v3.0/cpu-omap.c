static int omap_verify_speed(struct cpufreq_policy *policy)
{
if (freq_table)
return cpufreq_frequency_table_verify(policy, freq_table);
if (policy->cpu)
return -EINVAL;
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
policy->cpuinfo.max_freq);
policy->min = clk_round_rate(mpu_clk, policy->min * 1000) / 1000;
policy->max = clk_round_rate(mpu_clk, policy->max * 1000) / 1000;
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
policy->cpuinfo.max_freq);
return 0;
}
static unsigned int omap_getspeed(unsigned int cpu)
{
unsigned long rate;
if (cpu)
return 0;
rate = clk_get_rate(mpu_clk) / 1000;
return rate;
}
static int omap_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_freqs freqs;
int ret = 0;
if (target_freq < policy->min)
target_freq = policy->min;
if (target_freq > policy->max)
target_freq = policy->max;
freqs.old = omap_getspeed(0);
freqs.new = clk_round_rate(mpu_clk, target_freq * 1000) / 1000;
freqs.cpu = 0;
if (freqs.old == freqs.new)
return ret;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
#ifdef CONFIG_CPU_FREQ_DEBUG
printk(KERN_DEBUG "cpufreq-omap: transition: %u --> %u\n",
freqs.old, freqs.new);
#endif
ret = clk_set_rate(mpu_clk, freqs.new * 1000);
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
return ret;
}
static int __cpuinit omap_cpu_init(struct cpufreq_policy *policy)
{
int result = 0;
mpu_clk = clk_get(NULL, MPU_CLK);
if (IS_ERR(mpu_clk))
return PTR_ERR(mpu_clk);
if (policy->cpu != 0)
return -EINVAL;
policy->cur = policy->min = policy->max = omap_getspeed(0);
clk_init_cpufreq_table(&freq_table);
if (freq_table) {
result = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (!result)
cpufreq_frequency_table_get_attr(freq_table,
policy->cpu);
} else {
policy->cpuinfo.min_freq = clk_round_rate(mpu_clk, 0) / 1000;
policy->cpuinfo.max_freq = clk_round_rate(mpu_clk,
VERY_HI_RATE) / 1000;
}
policy->cpuinfo.transition_latency = 300 * 1000;
return 0;
}
static int omap_cpu_exit(struct cpufreq_policy *policy)
{
clk_exit_cpufreq_table(&freq_table);
clk_put(mpu_clk);
return 0;
}
static int __init omap_cpufreq_init(void)
{
return cpufreq_register_driver(&omap_driver);
}
