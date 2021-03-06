static int maple_scom_switch_freq(int speed_mode)
{
unsigned long flags;
int to;
local_irq_save(flags);
scom970_write(SCOM_PCR, 0);
scom970_write(SCOM_PCR, PCR_HILO_SELECT | 0);
scom970_write(SCOM_PCR, PCR_HILO_SELECT |
maple_pmode_data[speed_mode]);
for (to = 0; to < 10; to++) {
unsigned long psr = scom970_read(SCOM_PSR);
if ((psr & PSR_CMD_RECEIVED) == 0 &&
(((psr >> PSR_CUR_SPEED_SHIFT) ^
(maple_pmode_data[speed_mode] >> PCR_SPEED_SHIFT)) & 0x3)
== 0)
break;
if (psr & PSR_CMD_COMPLETED)
break;
udelay(100);
}
local_irq_restore(flags);
maple_pmode_cur = speed_mode;
ppc_proc_freq = maple_cpu_freqs[speed_mode].frequency * 1000ul;
return 0;
}
static int maple_scom_query_freq(void)
{
unsigned long psr = scom970_read(SCOM_PSR);
int i;
for (i = 0; i <= maple_pmode_max; i++)
if ((((psr >> PSR_CUR_SPEED_SHIFT) ^
(maple_pmode_data[i] >> PCR_SPEED_SHIFT)) & 0x3) == 0)
break;
return i;
}
static int maple_cpufreq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, maple_cpu_freqs);
}
static int maple_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq, unsigned int relation)
{
unsigned int newstate = 0;
struct cpufreq_freqs freqs;
int rc;
if (cpufreq_frequency_table_target(policy, maple_cpu_freqs,
target_freq, relation, &newstate))
return -EINVAL;
if (maple_pmode_cur == newstate)
return 0;
mutex_lock(&maple_switch_mutex);
freqs.old = maple_cpu_freqs[maple_pmode_cur].frequency;
freqs.new = maple_cpu_freqs[newstate].frequency;
freqs.cpu = 0;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
rc = maple_scom_switch_freq(newstate);
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
mutex_unlock(&maple_switch_mutex);
return rc;
}
static unsigned int maple_cpufreq_get_speed(unsigned int cpu)
{
return maple_cpu_freqs[maple_pmode_cur].frequency;
}
static int maple_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->cpuinfo.transition_latency = 12000;
policy->cur = maple_cpu_freqs[maple_scom_query_freq()].frequency;
cpumask_copy(policy->cpus, cpu_online_mask);
cpufreq_frequency_table_get_attr(maple_cpu_freqs, policy->cpu);
return cpufreq_frequency_table_cpuinfo(policy,
maple_cpu_freqs);
}
static int __init maple_cpufreq_init(void)
{
struct device_node *cpus;
struct device_node *cpunode;
unsigned int psize;
unsigned long max_freq;
const u32 *valp;
u32 pvr_hi;
int rc = -ENODEV;
if (!of_machine_is_compatible("Momentum,Maple") &&
!of_machine_is_compatible("Momentum,Apache"))
return 0;
cpus = of_find_node_by_path("/cpus");
if (cpus == NULL) {
DBG("No /cpus node !\n");
return -ENODEV;
}
for (cpunode = NULL;
(cpunode = of_get_next_child(cpus, cpunode)) != NULL;) {
const u32 *reg = of_get_property(cpunode, "reg", NULL);
if (reg == NULL || (*reg) != 0)
continue;
if (!strcmp(cpunode->type, "cpu"))
break;
}
if (cpunode == NULL) {
printk(KERN_ERR "cpufreq: Can't find any CPU 0 node\n");
goto bail_cpus;
}
pvr_hi = PVR_VER(mfspr(SPRN_PVR));
if (pvr_hi != 0x3c && pvr_hi != 0x44) {
printk(KERN_ERR "cpufreq: Unsupported CPU version (%x)\n",
pvr_hi);
goto bail_noprops;
}
maple_pmode_data = of_get_property(cpunode, "power-mode-data", &psize);
if (!maple_pmode_data) {
DBG("No power-mode-data !\n");
goto bail_noprops;
}
maple_pmode_max = psize / sizeof(u32) - 1;
valp = of_get_property(cpunode, "clock-frequency", NULL);
if (!valp)
return -ENODEV;
max_freq = (*valp)/1000;
maple_cpu_freqs[0].frequency = max_freq;
maple_cpu_freqs[1].frequency = max_freq/2;
msleep(10);
maple_pmode_cur = -1;
maple_scom_switch_freq(maple_scom_query_freq());
printk(KERN_INFO "Registering Maple CPU frequency driver\n");
printk(KERN_INFO "Low: %d Mhz, High: %d Mhz, Cur: %d MHz\n",
maple_cpu_freqs[1].frequency/1000,
maple_cpu_freqs[0].frequency/1000,
maple_cpu_freqs[maple_pmode_cur].frequency/1000);
rc = cpufreq_register_driver(&maple_cpufreq_driver);
of_node_put(cpunode);
of_node_put(cpus);
return rc;
bail_noprops:
of_node_put(cpunode);
bail_cpus:
of_node_put(cpus);
return rc;
}
