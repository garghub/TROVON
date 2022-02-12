static int init_powernv_pstates(void)
{
struct device_node *power_mgt;
int i, pstate_min, pstate_max, pstate_nominal, nr_pstates = 0;
const __be32 *pstate_ids, *pstate_freqs;
u32 len_ids, len_freqs;
power_mgt = of_find_node_by_path("/ibm,opal/power-mgt");
if (!power_mgt) {
pr_warn("power-mgt node not found\n");
return -ENODEV;
}
if (of_property_read_u32(power_mgt, "ibm,pstate-min", &pstate_min)) {
pr_warn("ibm,pstate-min node not found\n");
return -ENODEV;
}
if (of_property_read_u32(power_mgt, "ibm,pstate-max", &pstate_max)) {
pr_warn("ibm,pstate-max node not found\n");
return -ENODEV;
}
if (of_property_read_u32(power_mgt, "ibm,pstate-nominal",
&pstate_nominal)) {
pr_warn("ibm,pstate-nominal not found\n");
return -ENODEV;
}
pr_info("cpufreq pstate min %d nominal %d max %d\n", pstate_min,
pstate_nominal, pstate_max);
pstate_ids = of_get_property(power_mgt, "ibm,pstate-ids", &len_ids);
if (!pstate_ids) {
pr_warn("ibm,pstate-ids not found\n");
return -ENODEV;
}
pstate_freqs = of_get_property(power_mgt, "ibm,pstate-frequencies-mhz",
&len_freqs);
if (!pstate_freqs) {
pr_warn("ibm,pstate-frequencies-mhz not found\n");
return -ENODEV;
}
WARN_ON(len_ids != len_freqs);
nr_pstates = min(len_ids, len_freqs) / sizeof(u32);
if (!nr_pstates) {
pr_warn("No PStates found\n");
return -ENODEV;
}
pr_debug("NR PStates %d\n", nr_pstates);
for (i = 0; i < nr_pstates; i++) {
u32 id = be32_to_cpu(pstate_ids[i]);
u32 freq = be32_to_cpu(pstate_freqs[i]);
pr_debug("PState id %d freq %d MHz\n", id, freq);
powernv_freqs[i].frequency = freq * 1000;
powernv_freqs[i].driver_data = id;
}
powernv_freqs[i].frequency = CPUFREQ_TABLE_END;
powernv_pstate_info.min = pstate_min;
powernv_pstate_info.max = pstate_max;
powernv_pstate_info.nominal = pstate_nominal;
powernv_pstate_info.nr_pstates = nr_pstates;
return 0;
}
static unsigned int pstate_id_to_freq(int pstate_id)
{
int i;
i = powernv_pstate_info.max - pstate_id;
BUG_ON(i >= powernv_pstate_info.nr_pstates || i < 0);
return powernv_freqs[i].frequency;
}
static ssize_t cpuinfo_nominal_freq_show(struct cpufreq_policy *policy,
char *buf)
{
return sprintf(buf, "%u\n",
pstate_id_to_freq(powernv_pstate_info.nominal));
}
static inline unsigned long get_pmspr(unsigned long sprn)
{
switch (sprn) {
case SPRN_PMCR:
return mfspr(SPRN_PMCR);
case SPRN_PMICR:
return mfspr(SPRN_PMICR);
case SPRN_PMSR:
return mfspr(SPRN_PMSR);
}
BUG();
}
static inline void set_pmspr(unsigned long sprn, unsigned long val)
{
switch (sprn) {
case SPRN_PMCR:
mtspr(SPRN_PMCR, val);
return;
case SPRN_PMICR:
mtspr(SPRN_PMICR, val);
return;
}
BUG();
}
static void powernv_read_cpu_freq(void *arg)
{
unsigned long pmspr_val;
s8 local_pstate_id;
struct powernv_smp_call_data *freq_data = arg;
pmspr_val = get_pmspr(SPRN_PMSR);
local_pstate_id = (pmspr_val >> 48) & 0xFF;
freq_data->pstate_id = local_pstate_id;
freq_data->freq = pstate_id_to_freq(freq_data->pstate_id);
pr_debug("cpu %d pmsr %016lX pstate_id %d frequency %d kHz\n",
raw_smp_processor_id(), pmspr_val, freq_data->pstate_id,
freq_data->freq);
}
unsigned int powernv_cpufreq_get(unsigned int cpu)
{
struct powernv_smp_call_data freq_data;
smp_call_function_any(cpu_sibling_mask(cpu), powernv_read_cpu_freq,
&freq_data, 1);
return freq_data.freq;
}
static void set_pstate(void *freq_data)
{
unsigned long val;
unsigned long pstate_ul =
((struct powernv_smp_call_data *) freq_data)->pstate_id;
val = get_pmspr(SPRN_PMCR);
val = val & 0x0000FFFFFFFFFFFFULL;
pstate_ul = pstate_ul & 0xFF;
val = val | (pstate_ul << 56) | (pstate_ul << 48);
pr_debug("Setting cpu %d pmcr to %016lX\n",
raw_smp_processor_id(), val);
set_pmspr(SPRN_PMCR, val);
}
static int powernv_cpufreq_target_index(struct cpufreq_policy *policy,
unsigned int new_index)
{
struct powernv_smp_call_data freq_data;
freq_data.pstate_id = powernv_freqs[new_index].driver_data;
smp_call_function_any(policy->cpus, set_pstate, &freq_data, 1);
return 0;
}
static int powernv_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
int base, i;
base = cpu_first_thread_sibling(policy->cpu);
for (i = 0; i < threads_per_core; i++)
cpumask_set_cpu(base + i, policy->cpus);
return cpufreq_table_validate_and_show(policy, powernv_freqs);
}
static int __init powernv_cpufreq_init(void)
{
int rc = 0;
rc = init_powernv_pstates();
if (rc) {
pr_info("powernv-cpufreq disabled. System does not support PState control\n");
return rc;
}
return cpufreq_register_driver(&powernv_cpufreq_driver);
}
static void __exit powernv_cpufreq_exit(void)
{
cpufreq_unregister_driver(&powernv_cpufreq_driver);
}
