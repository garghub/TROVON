static int powernow_k6_get_cpu_multiplier(void)
{
u64 invalue = 0;
u32 msrval;
msrval = POWERNOW_IOPORT + 0x1;
wrmsr(MSR_K6_EPMR, msrval, 0);
invalue = inl(POWERNOW_IOPORT + 0x8);
msrval = POWERNOW_IOPORT + 0x0;
wrmsr(MSR_K6_EPMR, msrval, 0);
return clock_ratio[(invalue >> 5)&7].driver_data;
}
static int powernow_k6_target(struct cpufreq_policy *policy,
unsigned int best_i)
{
unsigned long outvalue = 0, invalue = 0;
unsigned long msrval;
struct cpufreq_freqs freqs;
if (clock_ratio[best_i].driver_data > max_multiplier) {
printk(KERN_ERR PFX "invalid target frequency\n");
return -EINVAL;
}
freqs.old = busfreq * powernow_k6_get_cpu_multiplier();
freqs.new = busfreq * clock_ratio[best_i].driver_data;
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
return 0;
}
static int powernow_k6_cpu_init(struct cpufreq_policy *policy)
{
unsigned int i, f;
if (policy->cpu != 0)
return -ENODEV;
max_multiplier = powernow_k6_get_cpu_multiplier();
busfreq = cpu_khz / max_multiplier;
for (i = 0; (clock_ratio[i].frequency != CPUFREQ_TABLE_END); i++) {
f = clock_ratio[i].driver_data;
if (f > max_multiplier)
clock_ratio[i].frequency = CPUFREQ_ENTRY_INVALID;
else
clock_ratio[i].frequency = busfreq * f;
}
policy->cpuinfo.transition_latency = 200000;
return cpufreq_table_validate_and_show(policy, clock_ratio);
}
static int powernow_k6_cpu_exit(struct cpufreq_policy *policy)
{
unsigned int i;
for (i = 0; i < 8; i++) {
if (i == max_multiplier)
powernow_k6_target(policy, i);
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
