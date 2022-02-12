static int speedstep_find_register(void)
{
if (!speedstep_chipset_dev)
return -ENODEV;
pci_read_config_dword(speedstep_chipset_dev, 0x40, &pmbase);
if (!(pmbase & 0x01)) {
printk(KERN_ERR "speedstep-ich: could not find speedstep register\n");
return -ENODEV;
}
pmbase &= 0xFFFFFFFE;
if (!pmbase) {
printk(KERN_ERR "speedstep-ich: could not find speedstep register\n");
return -ENODEV;
}
pr_debug("pmbase is 0x%x\n", pmbase);
return 0;
}
static void speedstep_set_state(unsigned int state)
{
u8 pm2_blk;
u8 value;
unsigned long flags;
if (state > 0x1)
return;
local_irq_save(flags);
value = inb(pmbase + 0x50);
pr_debug("read at pmbase 0x%x + 0x50 returned 0x%x\n", pmbase, value);
value &= 0xFE;
value |= state;
pr_debug("writing 0x%x to pmbase 0x%x + 0x50\n", value, pmbase);
pm2_blk = inb(pmbase + 0x20);
pm2_blk |= 0x01;
outb(pm2_blk, (pmbase + 0x20));
outb(value, (pmbase + 0x50));
pm2_blk &= 0xfe;
outb(pm2_blk, (pmbase + 0x20));
value = inb(pmbase + 0x50);
local_irq_restore(flags);
pr_debug("read at pmbase 0x%x + 0x50 returned 0x%x\n", pmbase, value);
if (state == (value & 0x1))
pr_debug("change to %u MHz succeeded\n",
speedstep_get_frequency(speedstep_processor) / 1000);
else
printk(KERN_ERR "cpufreq: change failed - I/O error\n");
return;
}
static void _speedstep_set_state(void *_state)
{
speedstep_set_state(*(unsigned int *)_state);
}
static int speedstep_activate(void)
{
u16 value = 0;
if (!speedstep_chipset_dev)
return -EINVAL;
pci_read_config_word(speedstep_chipset_dev, 0x00A0, &value);
if (!(value & 0x08)) {
value |= 0x08;
pr_debug("activating SpeedStep (TM) registers\n");
pci_write_config_word(speedstep_chipset_dev, 0x00A0, value);
}
return 0;
}
static unsigned int speedstep_detect_chipset(void)
{
speedstep_chipset_dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82801DB_12,
PCI_ANY_ID, PCI_ANY_ID,
NULL);
if (speedstep_chipset_dev)
return 4;
speedstep_chipset_dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82801CA_12,
PCI_ANY_ID, PCI_ANY_ID,
NULL);
if (speedstep_chipset_dev)
return 3;
speedstep_chipset_dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82801BA_10,
PCI_ANY_ID, PCI_ANY_ID,
NULL);
if (speedstep_chipset_dev) {
static struct pci_dev *hostbridge;
hostbridge = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82815_MC,
PCI_ANY_ID, PCI_ANY_ID,
NULL);
if (!hostbridge)
return 2;
if (hostbridge->revision < 5) {
pr_debug("hostbridge does not support speedstep\n");
speedstep_chipset_dev = NULL;
pci_dev_put(hostbridge);
return 0;
}
pci_dev_put(hostbridge);
return 2;
}
return 0;
}
static void get_freq_data(void *_speed)
{
unsigned int *speed = _speed;
*speed = speedstep_get_frequency(speedstep_processor);
}
static unsigned int speedstep_get(unsigned int cpu)
{
unsigned int speed;
if (smp_call_function_single(cpu, get_freq_data, &speed, 1) != 0)
BUG();
pr_debug("detected %u kHz as current frequency\n", speed);
return speed;
}
static int speedstep_target(struct cpufreq_policy *policy, unsigned int index)
{
unsigned int policy_cpu;
policy_cpu = cpumask_any_and(policy->cpus, cpu_online_mask);
smp_call_function_single(policy_cpu, _speedstep_set_state, &index,
true);
return 0;
}
static void get_freqs_on_cpu(void *_get_freqs)
{
struct get_freqs *get_freqs = _get_freqs;
get_freqs->ret =
speedstep_get_freqs(speedstep_processor,
&speedstep_freqs[SPEEDSTEP_LOW].frequency,
&speedstep_freqs[SPEEDSTEP_HIGH].frequency,
&get_freqs->policy->cpuinfo.transition_latency,
&speedstep_set_state);
}
static int speedstep_cpu_init(struct cpufreq_policy *policy)
{
unsigned int policy_cpu;
struct get_freqs gf;
#ifdef CONFIG_SMP
cpumask_copy(policy->cpus, topology_sibling_cpumask(policy->cpu));
#endif
policy_cpu = cpumask_any_and(policy->cpus, cpu_online_mask);
gf.policy = policy;
smp_call_function_single(policy_cpu, get_freqs_on_cpu, &gf, 1);
if (gf.ret)
return gf.ret;
return cpufreq_table_validate_and_show(policy, speedstep_freqs);
}
static int __init speedstep_init(void)
{
if (!x86_match_cpu(ss_smi_ids))
return -ENODEV;
speedstep_processor = speedstep_detect_processor();
if (!speedstep_processor) {
pr_debug("Intel(R) SpeedStep(TM) capable processor "
"not found\n");
return -ENODEV;
}
if (!speedstep_detect_chipset()) {
pr_debug("Intel(R) SpeedStep(TM) for this chipset not "
"(yet) available.\n");
return -ENODEV;
}
if (speedstep_activate()) {
pci_dev_put(speedstep_chipset_dev);
return -EINVAL;
}
if (speedstep_find_register())
return -ENODEV;
return cpufreq_register_driver(&speedstep_driver);
}
static void __exit speedstep_exit(void)
{
pci_dev_put(speedstep_chipset_dev);
cpufreq_unregister_driver(&speedstep_driver);
}
