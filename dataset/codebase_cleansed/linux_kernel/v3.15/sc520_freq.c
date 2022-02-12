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
static int sc520_freq_target(struct cpufreq_policy *policy, unsigned int state)
{
u8 clockspeed_reg;
local_irq_disable();
clockspeed_reg = *cpuctl & ~0x03;
*cpuctl = clockspeed_reg | sc520_freq_table[state].driver_data;
local_irq_enable();
return 0;
}
static int sc520_freq_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *c = &cpu_data(0);
if (c->x86_vendor != X86_VENDOR_AMD ||
c->x86 != 4 || c->x86_model != 9)
return -ENODEV;
policy->cpuinfo.transition_latency = 1000000;
return cpufreq_table_validate_and_show(policy, sc520_freq_table);
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
