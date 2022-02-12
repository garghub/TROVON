static unsigned int elanfreq_get_cpu_frequency(unsigned int cpu)
{
u8 clockspeed_reg;
local_irq_disable();
outb_p(0x80, REG_CSCIR);
clockspeed_reg = inb_p(REG_CSCDR);
local_irq_enable();
if ((clockspeed_reg & 0xE0) == 0xE0)
return 0;
if ((clockspeed_reg & 0xE0) == 0xC0) {
if ((clockspeed_reg & 0x01) == 0)
return 66000;
else
return 99000;
}
if ((clockspeed_reg & 0xE0) == 0xA0)
return 33000;
return (1<<((clockspeed_reg & 0xE0) >> 5)) * 1000;
}
static void elanfreq_set_cpu_state(unsigned int state)
{
struct cpufreq_freqs freqs;
freqs.old = elanfreq_get_cpu_frequency(0);
freqs.new = elan_multiplier[state].clock;
freqs.cpu = 0;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
printk(KERN_INFO "elanfreq: attempting to set frequency to %i kHz\n",
elan_multiplier[state].clock);
local_irq_disable();
outb_p(0x40, REG_CSCIR);
outb_p(0x00, REG_CSCDR);
local_irq_enable();
udelay(1000);
local_irq_disable();
outb_p(0x80, REG_CSCIR);
outb_p(elan_multiplier[state].val80h, REG_CSCDR);
outb_p(0x40, REG_CSCIR);
outb_p(elan_multiplier[state].val40h, REG_CSCDR);
udelay(10000);
local_irq_enable();
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
}
static int elanfreq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, &elanfreq_table[0]);
}
static int elanfreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int newstate = 0;
if (cpufreq_frequency_table_target(policy, &elanfreq_table[0],
target_freq, relation, &newstate))
return -EINVAL;
elanfreq_set_cpu_state(newstate);
return 0;
}
static int elanfreq_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *c = &cpu_data(0);
unsigned int i;
int result;
if ((c->x86_vendor != X86_VENDOR_AMD) ||
(c->x86 != 4) || (c->x86_model != 10))
return -ENODEV;
if (!max_freq)
max_freq = elanfreq_get_cpu_frequency(0);
for (i = 0; (elanfreq_table[i].frequency != CPUFREQ_TABLE_END); i++) {
if (elanfreq_table[i].frequency > max_freq)
elanfreq_table[i].frequency = CPUFREQ_ENTRY_INVALID;
}
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
policy->cur = elanfreq_get_cpu_frequency(0);
result = cpufreq_frequency_table_cpuinfo(policy, elanfreq_table);
if (result)
return result;
cpufreq_frequency_table_get_attr(elanfreq_table, policy->cpu);
return 0;
}
static int elanfreq_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
}
static int __init elanfreq_setup(char *str)
{
max_freq = simple_strtoul(str, &str, 0);
printk(KERN_WARNING "You're using the deprecated elanfreq command line option. Use elanfreq.max_freq instead, please!\n");
return 1;
}
static int __init elanfreq_init(void)
{
if (!x86_match_cpu(elan_id))
return -ENODEV;
return cpufreq_register_driver(&elanfreq_driver);
}
static void __exit elanfreq_exit(void)
{
cpufreq_unregister_driver(&elanfreq_driver);
}
