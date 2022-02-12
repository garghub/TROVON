static int cpufreq_p4_setdc(unsigned int cpu, unsigned int newstate)
{
u32 l, h;
if ((newstate > DC_DISABLE) || (newstate == DC_RESV))
return -EINVAL;
rdmsr_on_cpu(cpu, MSR_IA32_THERM_STATUS, &l, &h);
if (l & 0x01)
pr_debug("CPU#%d currently thermal throttled\n", cpu);
if (has_N44_O17_errata[cpu] &&
(newstate == DC_25PT || newstate == DC_DFLT))
newstate = DC_38PT;
rdmsr_on_cpu(cpu, MSR_IA32_THERM_CONTROL, &l, &h);
if (newstate == DC_DISABLE) {
pr_debug("CPU#%d disabling modulation\n", cpu);
wrmsr_on_cpu(cpu, MSR_IA32_THERM_CONTROL, l & ~(1<<4), h);
} else {
pr_debug("CPU#%d setting duty cycle to %d%%\n",
cpu, ((125 * newstate) / 10));
l = (l & ~14);
l = l | (1<<4) | ((newstate & 0x7)<<1);
wrmsr_on_cpu(cpu, MSR_IA32_THERM_CONTROL, l, h);
}
return 0;
}
static int cpufreq_p4_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int newstate = DC_RESV;
struct cpufreq_freqs freqs;
int i;
if (cpufreq_frequency_table_target(policy, &p4clockmod_table[0],
target_freq, relation, &newstate))
return -EINVAL;
freqs.old = cpufreq_p4_get(policy->cpu);
freqs.new = stock_freq * p4clockmod_table[newstate].index / 8;
if (freqs.new == freqs.old)
return 0;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
for_each_cpu(i, policy->cpus)
cpufreq_p4_setdc(i, p4clockmod_table[newstate].index);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return 0;
}
static int cpufreq_p4_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, &p4clockmod_table[0]);
}
static unsigned int cpufreq_p4_get_frequency(struct cpuinfo_x86 *c)
{
if (c->x86 == 0x06) {
if (cpu_has(c, X86_FEATURE_EST))
printk_once(KERN_WARNING PFX "Warning: EST-capable "
"CPU detected. The acpi-cpufreq module offers "
"voltage scaling in addition to frequency "
"scaling. You should use that instead of "
"p4-clockmod, if possible.\n");
switch (c->x86_model) {
case 0x0E:
case 0x0F:
case 0x16:
case 0x1C:
p4clockmod_driver.flags |= CPUFREQ_CONST_LOOPS;
return speedstep_get_frequency(SPEEDSTEP_CPU_PCORE);
case 0x0D:
p4clockmod_driver.flags |= CPUFREQ_CONST_LOOPS;
case 0x09:
return speedstep_get_frequency(SPEEDSTEP_CPU_PM);
}
}
if (c->x86 != 0xF)
return 0;
p4clockmod_driver.flags |= CPUFREQ_CONST_LOOPS;
if (speedstep_detect_processor() == SPEEDSTEP_CPU_P4M) {
printk(KERN_WARNING PFX "Warning: Pentium 4-M detected. "
"The speedstep-ich or acpi cpufreq modules offer "
"voltage scaling in addition of frequency scaling. "
"You should use either one instead of p4-clockmod, "
"if possible.\n");
return speedstep_get_frequency(SPEEDSTEP_CPU_P4M);
}
return speedstep_get_frequency(SPEEDSTEP_CPU_P4D);
}
static int cpufreq_p4_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *c = &cpu_data(policy->cpu);
int cpuid = 0;
unsigned int i;
#ifdef CONFIG_SMP
cpumask_copy(policy->cpus, cpu_sibling_mask(policy->cpu));
#endif
cpuid = (c->x86 << 8) | (c->x86_model << 4) | c->x86_mask;
switch (cpuid) {
case 0x0f07:
case 0x0f0a:
case 0x0f11:
case 0x0f12:
has_N44_O17_errata[policy->cpu] = 1;
pr_debug("has errata -- disabling low frequencies\n");
}
if (speedstep_detect_processor() == SPEEDSTEP_CPU_P4D &&
c->x86_model < 2) {
cpufreq_p4_setdc(policy->cpu, DC_DISABLE);
recalibrate_cpu_khz();
}
stock_freq = cpufreq_p4_get_frequency(c);
if (!stock_freq)
return -EINVAL;
for (i = 1; (p4clockmod_table[i].frequency != CPUFREQ_TABLE_END); i++) {
if ((i < 2) && (has_N44_O17_errata[policy->cpu]))
p4clockmod_table[i].frequency = CPUFREQ_ENTRY_INVALID;
else
p4clockmod_table[i].frequency = (stock_freq * i)/8;
}
cpufreq_frequency_table_get_attr(p4clockmod_table, policy->cpu);
policy->cpuinfo.transition_latency = 10000001;
policy->cur = stock_freq;
return cpufreq_frequency_table_cpuinfo(policy, &p4clockmod_table[0]);
}
static int cpufreq_p4_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
}
static unsigned int cpufreq_p4_get(unsigned int cpu)
{
u32 l, h;
rdmsr_on_cpu(cpu, MSR_IA32_THERM_CONTROL, &l, &h);
if (l & 0x10) {
l = l >> 1;
l &= 0x7;
} else
l = DC_DISABLE;
if (l != DC_DISABLE)
return stock_freq * l / 8;
return stock_freq;
}
static int __init cpufreq_p4_init(void)
{
int ret;
if (!x86_match_cpu(cpufreq_p4_id) || !boot_cpu_has(X86_FEATURE_ACPI))
return -ENODEV;
ret = cpufreq_register_driver(&p4clockmod_driver);
if (!ret)
printk(KERN_INFO PFX "P4/Xeon(TM) CPU On-Demand Clock "
"Modulation available\n");
return ret;
}
static void __exit cpufreq_p4_exit(void)
{
cpufreq_unregister_driver(&p4clockmod_driver);
}
