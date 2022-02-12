static unsigned int sc520_freq_get_cpu_frequency(unsigned int cpu)
{
u8 clockspeed_reg = *cpuctl;
switch (clockspeed_reg & 0x03) {
default:
printk(KERN_ERR PFX "error: cpuctl register has unexpected "
"value %02x\n", clockspeed_reg);
case 0x01:
return 100000;
case 0x02:
return 133000;
}
}
static void sc520_freq_set_cpu_state(struct cpufreq_policy *policy,
unsigned int state)
{
struct cpufreq_freqs freqs;
u8 clockspeed_reg;
freqs.old = sc520_freq_get_cpu_frequency(0);
freqs.new = sc520_freq_table[state].frequency;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
pr_debug("attempting to set frequency to %i kHz\n",
sc520_freq_table[state].frequency);
local_irq_disable();
clockspeed_reg = *cpuctl & ~0x03;
*cpuctl = clockspeed_reg | sc520_freq_table[state].index;
local_irq_enable();
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
}
static int sc520_freq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, &sc520_freq_table[0]);
}
static int sc520_freq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int newstate = 0;
if (cpufreq_frequency_table_target(policy, sc520_freq_table,
target_freq, relation, &newstate))
return -EINVAL;
sc520_freq_set_cpu_state(policy, newstate);
return 0;
}
static int sc520_freq_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *c = &cpu_data(0);
int result;
if (c->x86_vendor != X86_VENDOR_AMD ||
c->x86 != 4 || c->x86_model != 9)
return -ENODEV;
policy->cpuinfo.transition_latency = 1000000;
policy->cur = sc520_freq_get_cpu_frequency(0);
result = cpufreq_frequency_table_cpuinfo(policy, sc520_freq_table);
if (result)
return result;
cpufreq_frequency_table_get_attr(sc520_freq_table, policy->cpu);
return 0;
}
static int sc520_freq_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
}
static int __init sc520_freq_init(void)
{
int err;
if (!x86_match_cpu(sc520_ids))
return -ENODEV;
cpuctl = ioremap((unsigned long)(MMCR_BASE + OFFS_CPUCTL), 1);
if (!cpuctl) {
printk(KERN_ERR "sc520_freq: error: failed to remap memory\n");
return -ENOMEM;
}
err = cpufreq_register_driver(&sc520_freq_driver);
if (err)
iounmap(cpuctl);
return err;
}
static void __exit sc520_freq_exit(void)
{
cpufreq_unregister_driver(&sc520_freq_driver);
iounmap(cpuctl);
}
