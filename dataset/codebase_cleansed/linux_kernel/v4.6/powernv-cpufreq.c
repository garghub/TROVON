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
if (len_ids != len_freqs) {
pr_warn("Entries in ibm,pstate-ids and "
"ibm,pstate-frequencies-mhz does not match\n");
}
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
if (i >= powernv_pstate_info.nr_pstates || i < 0) {
pr_warn("PState id %d outside of PState table, "
"reporting nominal id %d instead\n",
pstate_id, powernv_pstate_info.nominal);
i = powernv_pstate_info.max - powernv_pstate_info.nominal;
}
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
static unsigned int powernv_cpufreq_get(unsigned int cpu)
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
static inline unsigned int get_nominal_index(void)
{
return powernv_pstate_info.max - powernv_pstate_info.nominal;
}
static void powernv_cpufreq_throttle_check(void *data)
{
struct chip *chip;
unsigned int cpu = smp_processor_id();
unsigned long pmsr;
int pmsr_pmax;
pmsr = get_pmspr(SPRN_PMSR);
chip = this_cpu_read(chip_info);
pmsr_pmax = (s8)PMSR_MAX(pmsr);
if (pmsr_pmax != powernv_pstate_info.max) {
if (chip->throttled)
goto next;
chip->throttled = true;
if (pmsr_pmax < powernv_pstate_info.nominal) {
pr_warn_once("CPU %d on Chip %u has Pmax reduced below nominal frequency (%d < %d)\n",
cpu, chip->id, pmsr_pmax,
powernv_pstate_info.nominal);
chip->throttle_sub_turbo++;
} else {
chip->throttle_turbo++;
}
trace_powernv_throttle(chip->id,
throttle_reason[chip->throttle_reason],
pmsr_pmax);
} else if (chip->throttled) {
chip->throttled = false;
trace_powernv_throttle(chip->id,
throttle_reason[chip->throttle_reason],
pmsr_pmax);
}
next:
if (pmsr & PMSR_PSAFE_ENABLE) {
throttled = true;
pr_info("Pstate set to safe frequency\n");
}
if (pmsr & PMSR_SPR_EM_DISABLE) {
throttled = true;
pr_info("Frequency Control disabled from OS\n");
}
if (throttled) {
pr_info("PMSR = %16lx\n", pmsr);
pr_warn("CPU Frequency could be throttled\n");
}
}
static int powernv_cpufreq_target_index(struct cpufreq_policy *policy,
unsigned int new_index)
{
struct powernv_smp_call_data freq_data;
if (unlikely(rebooting) && new_index != get_nominal_index())
return 0;
if (!throttled)
powernv_cpufreq_throttle_check(NULL);
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
if (!policy->driver_data) {
int ret;
ret = sysfs_create_group(&policy->kobj, &throttle_attr_grp);
if (ret) {
pr_info("Failed to create throttle stats directory for cpu %d\n",
policy->cpu);
return ret;
}
policy->driver_data = policy;
}
return cpufreq_table_validate_and_show(policy, powernv_freqs);
}
static int powernv_cpufreq_reboot_notifier(struct notifier_block *nb,
unsigned long action, void *unused)
{
int cpu;
struct cpufreq_policy cpu_policy;
rebooting = true;
for_each_online_cpu(cpu) {
cpufreq_get_policy(&cpu_policy, cpu);
powernv_cpufreq_target_index(&cpu_policy, get_nominal_index());
}
return NOTIFY_DONE;
}
void powernv_cpufreq_work_fn(struct work_struct *work)
{
struct chip *chip = container_of(work, struct chip, throttle);
unsigned int cpu;
cpumask_t mask;
get_online_cpus();
cpumask_and(&mask, &chip->mask, cpu_online_mask);
smp_call_function_any(&mask,
powernv_cpufreq_throttle_check, NULL, 0);
if (!chip->restore)
goto out;
chip->restore = false;
for_each_cpu(cpu, &mask) {
int index;
struct cpufreq_policy policy;
cpufreq_get_policy(&policy, cpu);
cpufreq_frequency_table_target(&policy, policy.freq_table,
policy.cur,
CPUFREQ_RELATION_C, &index);
powernv_cpufreq_target_index(&policy, index);
cpumask_andnot(&mask, &mask, policy.cpus);
}
out:
put_online_cpus();
}
static int powernv_cpufreq_occ_msg(struct notifier_block *nb,
unsigned long msg_type, void *_msg)
{
struct opal_msg *msg = _msg;
struct opal_occ_msg omsg;
int i;
if (msg_type != OPAL_MSG_OCC)
return 0;
omsg.type = be64_to_cpu(msg->params[0]);
switch (omsg.type) {
case OCC_RESET:
occ_reset = true;
pr_info("OCC (On Chip Controller - enforces hard thermal/power limits) Resetting\n");
if (!throttled) {
throttled = true;
pr_warn("CPU frequency is throttled for duration\n");
}
break;
case OCC_LOAD:
pr_info("OCC Loading, CPU frequency is throttled until OCC is started\n");
break;
case OCC_THROTTLE:
omsg.chip = be64_to_cpu(msg->params[1]);
omsg.throttle_status = be64_to_cpu(msg->params[2]);
if (occ_reset) {
occ_reset = false;
throttled = false;
pr_info("OCC Active, CPU frequency is no longer throttled\n");
for (i = 0; i < nr_chips; i++) {
chips[i].restore = true;
schedule_work(&chips[i].throttle);
}
return 0;
}
for (i = 0; i < nr_chips; i++)
if (chips[i].id == omsg.chip)
break;
if (omsg.throttle_status >= 0 &&
omsg.throttle_status <= OCC_MAX_THROTTLE_STATUS) {
chips[i].throttle_reason = omsg.throttle_status;
chips[i].reason[omsg.throttle_status]++;
}
if (!omsg.throttle_status)
chips[i].restore = true;
schedule_work(&chips[i].throttle);
}
return 0;
}
static void powernv_cpufreq_stop_cpu(struct cpufreq_policy *policy)
{
struct powernv_smp_call_data freq_data;
freq_data.pstate_id = powernv_pstate_info.min;
smp_call_function_single(policy->cpu, set_pstate, &freq_data, 1);
}
static int init_chip_info(void)
{
unsigned int chip[256];
unsigned int cpu, i;
unsigned int prev_chip_id = UINT_MAX;
for_each_possible_cpu(cpu) {
unsigned int id = cpu_to_chip_id(cpu);
if (prev_chip_id != id) {
prev_chip_id = id;
chip[nr_chips++] = id;
}
}
chips = kcalloc(nr_chips, sizeof(struct chip), GFP_KERNEL);
if (!chips)
return -ENOMEM;
for (i = 0; i < nr_chips; i++) {
chips[i].id = chip[i];
cpumask_copy(&chips[i].mask, cpumask_of_node(chip[i]));
INIT_WORK(&chips[i].throttle, powernv_cpufreq_work_fn);
for_each_cpu(cpu, &chips[i].mask)
per_cpu(chip_info, cpu) = &chips[i];
}
return 0;
}
static inline void clean_chip_info(void)
{
kfree(chips);
}
static inline void unregister_all_notifiers(void)
{
opal_message_notifier_unregister(OPAL_MSG_OCC,
&powernv_cpufreq_opal_nb);
unregister_reboot_notifier(&powernv_cpufreq_reboot_nb);
}
static int __init powernv_cpufreq_init(void)
{
int rc = 0;
if (!firmware_has_feature(FW_FEATURE_OPAL))
return -ENODEV;
rc = init_powernv_pstates();
if (rc)
goto out;
rc = init_chip_info();
if (rc)
goto out;
register_reboot_notifier(&powernv_cpufreq_reboot_nb);
opal_message_notifier_register(OPAL_MSG_OCC, &powernv_cpufreq_opal_nb);
rc = cpufreq_register_driver(&powernv_cpufreq_driver);
if (!rc)
return 0;
pr_info("Failed to register the cpufreq driver (%d)\n", rc);
unregister_all_notifiers();
clean_chip_info();
out:
pr_info("Platform driver disabled. System does not support PState control\n");
return rc;
}
static void __exit powernv_cpufreq_exit(void)
{
cpufreq_unregister_driver(&powernv_cpufreq_driver);
unregister_all_notifiers();
clean_chip_info();
}
