static int powernow_k6_get_cpu_multiplier(void)
{
u64 invalue = 0;
u32 msrval;
msrval = POWERNOW_IOPORT + 0x1;
wrmsr(MSR_K6_EPMR, msrval, 0);
invalue = inl(POWERNOW_IOPORT + 0x8);
msrval = POWERNOW_IOPORT + 0x0;
wrmsr(MSR_K6_EPMR, msrval, 0);
return clock_ratio[(invalue >> 5)&7].index;
}
static void powernow_k6_set_state(struct cpufreq_policy *policy,
unsigned int best_i)
{
unsigned long outvalue = 0, invalue = 0;
unsigned long msrval;
struct cpufreq_freqs freqs;
if (clock_ratio[best_i].index > max_multiplier) {
printk(KERN_ERR PFX "invalid target frequency\n");
return;
}
freqs.old = busfreq * powernow_k6_get_cpu_multiplier();
freqs.new = busfreq * clock_ratio[best_i].index;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
outvalue = (1<<12) | (1<<10) | (1<<9) | (best_i<<5);
msrval = POWERNOW_IOPORT + 0x1;
wrmsr(MSR_K6_EPMR, msrval, 0);
invalue = inl(POWERNOW_IOPORT + 0x8);
invalue = invalue & 0xf;
outvalue = outvalue | invalue;
outl(outvalue , (POWERNOW_IOPORT + 0x8));
msrval = POWERNOW_IOPORT + 0x0;
wrmsr(MSR_K6_EPMR, msrval, 0);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return;
}
static int powernow_k6_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, &clock_ratio[0]);
}
static int powernow_k6_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int newstate = 0;
if (cpufreq_frequency_table_target(policy, &clock_ratio[0],
target_freq, relation, &newstate))
return -EINVAL;
powernow_k6_set_state(policy, newstate);
return 0;
}
static int powernow_k6_cpu_init(struct cpufreq_policy *policy)
{
unsigned int i, f;
int result;
if (policy->cpu != 0)
return -ENODEV;
max_multiplier = powernow_k6_get_cpu_multiplier();
busfreq = cpu_khz / max_multiplier;
for (i = 0; (clock_ratio[i].frequency != CPUFREQ_TABLE_END); i++) {
f = clock_ratio[i].index;
if (f > max_multiplier)
clock_ratio[i].frequency = CPUFREQ_ENTRY_INVALID;
else
clock_ratio[i].frequency = busfreq * f;
}
policy->cpuinfo.transition_latency = 200000;
policy->cur = busfreq * max_multiplier;
result = cpufreq_frequency_table_cpuinfo(policy, clock_ratio);
if (result)
return result;
cpufreq_frequency_table_get_attr(clock_ratio, policy->cpu);
return 0;
}
static int powernow_k6_cpu_exit(struct cpufreq_policy *policy)
{
unsigned int i;
for (i = 0; i < 8; i++) {
if (i == max_multiplier)
powernow_k6_set_state(policy, i);
}
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
}
static unsigned int powernow_k6_get(unsigned int cpu)
{
unsigned int ret;
ret = (busfreq * powernow_k6_get_cpu_multiplier());
return ret;
}
static int __init powernow_k6_init(void)
{
if (!x86_match_cpu(powernow_k6_ids))
return -ENODEV;
if (!request_region(POWERNOW_IOPORT, 16, "PowerNow!")) {
printk(KERN_INFO PFX "PowerNow IOPORT region already used.\n");
return -EIO;
}
if (cpufreq_register_driver(&powernow_k6_driver)) {
release_region(POWERNOW_IOPORT, 16);
return -EINVAL;
}
return 0;
}
static void __exit powernow_k6_exit(void)
{
cpufreq_unregister_driver(&powernow_k6_driver);
release_region(POWERNOW_IOPORT, 16);
}
