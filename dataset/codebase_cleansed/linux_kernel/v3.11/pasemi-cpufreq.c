static int get_astate_freq(int astate)
{
u32 ret;
ret = in_le32(sdcpwr_mapbase + SDCPWR_CFGA0_REG + (astate * 0x10));
return ret & 0x3f;
}
static int get_cur_astate(int cpu)
{
u32 ret;
ret = in_le32(sdcpwr_mapbase + SDCPWR_PWST0_REG);
ret = (ret >> (cpu * 4)) & 0x7;
return ret;
}
static int get_gizmo_latency(void)
{
u32 giztime, ret;
giztime = in_le32(sdcpwr_mapbase + SDCPWR_GIZTIME_REG);
if (giztime & SDCPWR_GIZTIME_GR)
ret = (giztime & SDCPWR_GIZTIME_LONGLOCK) * 128000;
else
ret = (giztime & SDCPWR_GIZTIME_LONGLOCK) * 1000;
return ret;
}
static void set_astate(int cpu, unsigned int astate)
{
unsigned long flags;
if (unlikely(!sdcasr_mapbase))
return;
local_irq_save(flags);
out_le32(sdcasr_mapbase + SDCASR_REG + SDCASR_REG_STRIDE*cpu, astate);
local_irq_restore(flags);
}
int check_astate(void)
{
return get_cur_astate(hard_smp_processor_id());
}
void restore_astate(int cpu)
{
set_astate(cpu, current_astate);
}
static int pas_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
const u32 *max_freqp;
u32 max_freq;
int i, cur_astate;
struct resource res;
struct device_node *cpu, *dn;
int err = -ENODEV;
cpu = of_get_cpu_node(policy->cpu, NULL);
if (!cpu)
goto out;
dn = of_find_compatible_node(NULL, NULL, "1682m-sdc");
if (!dn)
dn = of_find_compatible_node(NULL, NULL,
"pasemi,pwrficient-sdc");
if (!dn)
goto out;
err = of_address_to_resource(dn, 0, &res);
of_node_put(dn);
if (err)
goto out;
sdcasr_mapbase = ioremap(res.start + SDCASR_OFFSET, 0x2000);
if (!sdcasr_mapbase) {
err = -EINVAL;
goto out;
}
dn = of_find_compatible_node(NULL, NULL, "1682m-gizmo");
if (!dn)
dn = of_find_compatible_node(NULL, NULL,
"pasemi,pwrficient-gizmo");
if (!dn) {
err = -ENODEV;
goto out_unmap_sdcasr;
}
err = of_address_to_resource(dn, 0, &res);
of_node_put(dn);
if (err)
goto out_unmap_sdcasr;
sdcpwr_mapbase = ioremap(res.start, 0x1000);
if (!sdcpwr_mapbase) {
err = -EINVAL;
goto out_unmap_sdcasr;
}
pr_debug("init cpufreq on CPU %d\n", policy->cpu);
max_freqp = of_get_property(cpu, "clock-frequency", NULL);
if (!max_freqp) {
err = -EINVAL;
goto out_unmap_sdcpwr;
}
max_freq = *max_freqp / 1000;
pr_debug("max clock-frequency is at %u kHz\n", max_freq);
pr_debug("initializing frequency table\n");
for (i=0; pas_freqs[i].frequency!=CPUFREQ_TABLE_END; i++) {
pas_freqs[i].frequency =
get_astate_freq(pas_freqs[i].driver_data) * 100000;
pr_debug("%d: %d\n", i, pas_freqs[i].frequency);
}
policy->cpuinfo.transition_latency = get_gizmo_latency();
cur_astate = get_cur_astate(policy->cpu);
pr_debug("current astate is at %d\n",cur_astate);
policy->cur = pas_freqs[cur_astate].frequency;
cpumask_copy(policy->cpus, cpu_online_mask);
ppc_proc_freq = policy->cur * 1000ul;
cpufreq_frequency_table_get_attr(pas_freqs, policy->cpu);
return cpufreq_frequency_table_cpuinfo(policy, pas_freqs);
out_unmap_sdcpwr:
iounmap(sdcpwr_mapbase);
out_unmap_sdcasr:
iounmap(sdcasr_mapbase);
out:
return err;
}
static int pas_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
if (system_state != SYSTEM_BOOTING)
return 0;
if (sdcasr_mapbase)
iounmap(sdcasr_mapbase);
if (sdcpwr_mapbase)
iounmap(sdcpwr_mapbase);
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
}
static int pas_cpufreq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, pas_freqs);
}
static int pas_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_freqs freqs;
int pas_astate_new;
int i;
cpufreq_frequency_table_target(policy,
pas_freqs,
target_freq,
relation,
&pas_astate_new);
freqs.old = policy->cur;
freqs.new = pas_freqs[pas_astate_new].frequency;
mutex_lock(&pas_switch_mutex);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
pr_debug("setting frequency for cpu %d to %d kHz, 1/%d of max frequency\n",
policy->cpu,
pas_freqs[pas_astate_new].frequency,
pas_freqs[pas_astate_new].driver_data);
current_astate = pas_astate_new;
for_each_online_cpu(i)
set_astate(i, pas_astate_new);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
mutex_unlock(&pas_switch_mutex);
ppc_proc_freq = freqs.new * 1000ul;
return 0;
}
static int __init pas_cpufreq_init(void)
{
if (!of_machine_is_compatible("PA6T-1682M") &&
!of_machine_is_compatible("pasemi,pwrficient"))
return -ENODEV;
return cpufreq_register_driver(&pas_cpufreq_driver);
}
static void __exit pas_cpufreq_exit(void)
{
cpufreq_unregister_driver(&pas_cpufreq_driver);
}
