static int powernow_k6_get_cpu_multiplier(void)
{
unsigned long invalue = 0;
u32 msrval;
local_irq_disable();
msrval = POWERNOW_IOPORT + 0x1;
wrmsr(MSR_K6_EPMR, msrval, 0);
invalue = inl(POWERNOW_IOPORT + 0x8);
msrval = POWERNOW_IOPORT + 0x0;
wrmsr(MSR_K6_EPMR, msrval, 0);
local_irq_enable();
return clock_ratio[register_to_index[(invalue >> 5)&7]].driver_data;
}
static void powernow_k6_set_cpu_multiplier(unsigned int best_i)
{
unsigned long outvalue, invalue;
unsigned long msrval;
unsigned long cr0;
local_irq_disable();
cr0 = read_cr0();
write_cr0(cr0 | X86_CR0_CD);
wbinvd();
outvalue = (1<<12) | (1<<10) | (1<<9) | (index_to_register[best_i]<<5);
msrval = POWERNOW_IOPORT + 0x1;
wrmsr(MSR_K6_EPMR, msrval, 0);
invalue = inl(POWERNOW_IOPORT + 0x8);
invalue = invalue & 0x1f;
outvalue = outvalue | invalue;
outl(outvalue, (POWERNOW_IOPORT + 0x8));
msrval = POWERNOW_IOPORT + 0x0;
wrmsr(MSR_K6_EPMR, msrval, 0);
write_cr0(cr0);
local_irq_enable();
}
static int powernow_k6_target(struct cpufreq_policy *policy,
unsigned int best_i)
{
if (clock_ratio[best_i].driver_data > max_multiplier) {
pr_err("invalid target frequency\n");
return -EINVAL;
}
powernow_k6_set_cpu_multiplier(best_i);
return 0;
}
static int powernow_k6_cpu_init(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *pos;
unsigned int i, f;
unsigned khz;
if (policy->cpu != 0)
return -ENODEV;
max_multiplier = 0;
khz = cpu_khz;
for (i = 0; i < ARRAY_SIZE(usual_frequency_table); i++) {
if (khz >= usual_frequency_table[i].freq - FREQ_RANGE &&
khz <= usual_frequency_table[i].freq + FREQ_RANGE) {
khz = usual_frequency_table[i].freq;
max_multiplier = usual_frequency_table[i].mult;
break;
}
}
if (param_max_multiplier) {
cpufreq_for_each_entry(pos, clock_ratio)
if (pos->driver_data == param_max_multiplier) {
max_multiplier = param_max_multiplier;
goto have_max_multiplier;
}
pr_err("invalid max_multiplier parameter, valid parameters 20, 30, 35, 40, 45, 50, 55, 60\n");
return -EINVAL;
}
if (!max_multiplier) {
pr_warn("unknown frequency %u, cannot determine current multiplier\n",
khz);
pr_warn("use module parameters max_multiplier and bus_frequency\n");
return -EOPNOTSUPP;
}
have_max_multiplier:
param_max_multiplier = max_multiplier;
if (param_busfreq) {
if (param_busfreq >= 50000 && param_busfreq <= 150000) {
busfreq = param_busfreq / 10;
goto have_busfreq;
}
pr_err("invalid bus_frequency parameter, allowed range 50000 - 150000 kHz\n");
return -EINVAL;
}
busfreq = khz / max_multiplier;
have_busfreq:
param_busfreq = busfreq * 10;
cpufreq_for_each_entry(pos, clock_ratio) {
f = pos->driver_data;
if (f > max_multiplier)
pos->frequency = CPUFREQ_ENTRY_INVALID;
else
pos->frequency = busfreq * f;
}
policy->cpuinfo.transition_latency = 500000;
return cpufreq_table_validate_and_show(policy, clock_ratio);
}
static int powernow_k6_cpu_exit(struct cpufreq_policy *policy)
{
unsigned int i;
for (i = 0; (clock_ratio[i].frequency != CPUFREQ_TABLE_END); i++) {
if (clock_ratio[i].driver_data == max_multiplier) {
struct cpufreq_freqs freqs;
freqs.old = policy->cur;
freqs.new = clock_ratio[i].frequency;
freqs.flags = 0;
cpufreq_freq_transition_begin(policy, &freqs);
powernow_k6_target(policy, i);
cpufreq_freq_transition_end(policy, &freqs, 0);
break;
}
}
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
pr_info("PowerNow IOPORT region already used\n");
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
