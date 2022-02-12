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
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
ret = clk_set_rate(policy->mclk, target_freq * 1000);
cpufreq_notify_post_transition(policy, &freqs, ret);
return ret;
}
static int __init ucv2_cpu_init(struct cpufreq_policy *policy)
{
if (policy->cpu != 0)
return -EINVAL;
policy->min = policy->cpuinfo.min_freq = 250000;
policy->max = policy->cpuinfo.max_freq = 1000000;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
policy->clk = clk_get(NULL, "MAIN_CLK");
if (IS_ERR(policy->clk))
return PTR_ERR(policy->clk);
return 0;
}
static int __init ucv2_cpufreq_init(void)
{
return cpufreq_register_driver(&ucv2_driver);
}
