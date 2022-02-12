static void sa1100_update_dram_timings(int current_speed, int new_speed)
{
struct sa1100_dram_regs *settings = sa1100_dram_settings;
while (settings->speed != 0) {
if (new_speed == settings->speed)
break;
settings++;
}
if (settings->speed == 0) {
panic("%s: couldn't find dram setting for speed %d\n",
__func__, new_speed);
}
if (new_speed > current_speed) {
MDCNFG |= MDCNFG_CDB2;
MDCAS2 = settings->mdcas2;
MDCAS1 = settings->mdcas1;
MDCAS0 = settings->mdcas0;
MDCNFG = settings->mdcnfg;
} else {
MDCNFG |= MDCNFG_CDB2;
MDCAS0 = settings->mdcas0;
MDCAS1 = settings->mdcas1;
MDCAS2 = settings->mdcas2;
MDCNFG = settings->mdcnfg;
}
}
static int sa1100_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int cur = sa11x0_getspeed(0);
unsigned int new_ppcr;
struct cpufreq_freqs freqs;
new_ppcr = sa11x0_freq_to_ppcr(target_freq);
switch (relation) {
case CPUFREQ_RELATION_L:
if (sa11x0_ppcr_to_freq(new_ppcr) > policy->max)
new_ppcr--;
break;
case CPUFREQ_RELATION_H:
if ((sa11x0_ppcr_to_freq(new_ppcr) > target_freq) &&
(sa11x0_ppcr_to_freq(new_ppcr - 1) >= policy->min))
new_ppcr--;
break;
}
freqs.old = cur;
freqs.new = sa11x0_ppcr_to_freq(new_ppcr);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
if (freqs.new > cur)
sa1100_update_dram_timings(cur, freqs.new);
PPCR = new_ppcr;
if (freqs.new < cur)
sa1100_update_dram_timings(cur, freqs.new);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return 0;
}
static int __init sa1100_cpu_init(struct cpufreq_policy *policy)
{
if (policy->cpu != 0)
return -EINVAL;
policy->cur = policy->min = policy->max = sa11x0_getspeed(0);
policy->cpuinfo.min_freq = 59000;
policy->cpuinfo.max_freq = 287000;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
return 0;
}
static int __init sa1100_dram_init(void)
{
if (cpu_is_sa1100())
return cpufreq_register_driver(&sa1100_driver);
else
return -ENODEV;
}
