static int ucv2_verify_speed(struct cpufreq_policy *policy)
{
if (policy->cpu)
return -EINVAL;
cpufreq_verify_within_cpu_limits(policy);
return 0;
}
static int ucv2_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_freqs freqs;
int ret;
freqs.old = policy->cur;
freqs.new = target_freq;
cpufreq_freq_transition_begin(policy, &freqs);
ret = clk_set_rate(policy->clk, target_freq * 1000);
cpufreq_freq_transition_end(policy, &freqs, ret);
return ret;
}
static int __init ucv2_cpu_init(struct cpufreq_policy *policy)
{
if (policy->cpu != 0)
return -EINVAL;
policy->min = policy->cpuinfo.min_freq = 250000;
policy->max = policy->cpuinfo.max_freq = 1000000;
policy->clk = clk_get(NULL, "MAIN_CLK");
return PTR_ERR_OR_ZERO(policy->clk);
}
static int __init ucv2_cpufreq_init(void)
{
return cpufreq_register_driver(&ucv2_driver);
}
