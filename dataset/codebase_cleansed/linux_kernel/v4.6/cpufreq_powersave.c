static int cpufreq_governor_powersave(struct cpufreq_policy *policy,
unsigned int event)
{
switch (event) {
case CPUFREQ_GOV_START:
case CPUFREQ_GOV_LIMITS:
pr_debug("setting to %u kHz because of event %u\n",
policy->min, event);
__cpufreq_driver_target(policy, policy->min,
CPUFREQ_RELATION_L);
break;
default:
break;
}
return 0;
}
static int __init cpufreq_gov_powersave_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_powersave);
}
static void __exit cpufreq_gov_powersave_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_powersave);
}
struct cpufreq_governor *cpufreq_default_governor(void)
{
return &cpufreq_gov_powersave;
}
