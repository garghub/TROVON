static inline int idx_to_pstate(unsigned int i)
{
if (unlikely(i >= powernv_pstate_info.nr_pstates)) {
pr_warn_once("index %u is out of bound\n", i);
return powernv_freqs[powernv_pstate_info.nominal].driver_data;
}
return powernv_freqs[i].driver_data;
}
static inline unsigned int pstate_to_idx(int pstate)
{
int min = powernv_freqs[powernv_pstate_info.min].driver_data;
int max = powernv_freqs[powernv_pstate_info.max].driver_data;
if (min > 0) {
if (unlikely((pstate < max) || (pstate > min))) {
pr_warn_once("pstate %d is out of bound\n", pstate);
return powernv_pstate_info.nominal;
}
} else {
if (unlikely((pstate > max) || (pstate < min))) {
pr_warn_once("pstate %d is out of bound\n", pstate);
return powernv_pstate_info.nominal;
}
}
return abs(pstate - idx_to_pstate(powernv_pstate_info.max));
}
static inline void reset_gpstates(struct cpufreq_policy *policy)
{
struct global_pstate_info *gpstates = policy->driver_data;
gpstates->highest_lpstate_idx = 0;
gpstates->elapsed_time = 0;
gpstates->last_sampled_time = 0;
gpstates->last_lpstate_idx = 0;
gpstates->last_gpstate_idx = 0;
}
static int init_powernv_pstates(void)
{
struct device_node *power_mgt;
int i, nr_pstates = 0;
const __be32 *pstate_ids, *pstate_freqs;
u32 len_ids, len_freqs;
u32 pstate_min, pstate_max, pstate_nominal;
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
powernv_pstate_info.nr_pstates = nr_pstates;
pr_debug("NR PStates %d\n", nr_pstates);
for (i = 0; i < nr_pstates; i++) {
u32 id = be32_to_cpu(pstate_ids[i]);
u32 freq = be32_to_cpu(pstate_freqs[i]);
pr_debug("PState id %d freq %d MHz\n", id, freq);
powernv_freqs[i].frequency = freq * 1000;
powernv_freqs[i].driver_data = id;
if (id == pstate_max)
powernv_pstate_info.max = i;
else if (id == pstate_nominal)
powernv_pstate_info.nominal = i;
else if (id == pstate_min)
powernv_pstate_info.min = i;
}
powernv_freqs[i].frequency = CPUFREQ_TABLE_END;
return 0;
}
static unsigned int pstate_id_to_freq(int pstate_id)
{
int i;
i = pstate_to_idx(pstate_id);
if (i >= powernv_pstate_info.nr_pstates || i < 0) {
pr_warn("PState id %d outside of PState table, "
"reporting nominal id %d instead\n",
pstate_id, idx_to_pstate(powernv_pstate_info.nominal));
i = powernv_pstate_info.nominal;
}
return powernv_freqs[i].frequency;
}
static ssize_t cpuinfo_nominal_freq_show(struct cpufreq_policy *policy,
char *buf)
{
return sprintf(buf, "%u\n",
powernv_freqs[powernv_pstate_info.nominal].frequency);
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
static void set_pstate(void *data)
{
unsigned long val;
struct powernv_smp_call_data *freq_data = data;
unsigned long pstate_ul = freq_data->pstate_id;
unsigned long gpstate_ul = freq_data->gpstate_id;
val = get_pmspr(SPRN_PMCR);
val = val & 0x0000FFFFFFFFFFFFULL;
pstate_ul = pstate_ul & 0xFF;
gpstate_ul = gpstate_ul & 0xFF;
val = val | (gpstate_ul << 56) | (pstate_ul << 48);
pr_debug("Setting cpu %d pmcr to %016lX\n",
raw_smp_processor_id(), val);
set_pmspr(SPRN_PMCR, val);
}
static inline unsigned int get_nominal_index(void)
{
return powernv_pstate_info.nominal;
}
static void powernv_cpufreq_throttle_check(void *data)
{
struct chip *chip;
unsigned int cpu = smp_processor_id();
unsigned long pmsr;
int pmsr_pmax;
unsigned int pmsr_pmax_idx;
pmsr = get_pmspr(SPRN_PMSR);
chip = this_cpu_read(chip_info);
pmsr_pmax = (s8)PMSR_MAX(pmsr);
pmsr_pmax_idx = pstate_to_idx(pmsr_pmax);
if (pmsr_pmax_idx != powernv_pstate_info.max) {
if (chip->throttled)
goto next;
chip->throttled = true;
if (pmsr_pmax_idx > powernv_pstate_info.nominal) {
pr_warn_once("CPU %d on Chip %u has Pmax(%d) reduced below nominal frequency(%d)\n",
cpu, chip->id, pmsr_pmax,
idx_to_pstate(powernv_pstate_info.nominal));
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
static inline int calc_global_pstate(unsigned int elapsed_time,
int highest_lpstate_idx,
int local_pstate_idx)
{
int index_diff;
index_diff = ((int)ramp_down_percent(elapsed_time) *
(powernv_pstate_info.min - highest_lpstate_idx)) / 100;
if (highest_lpstate_idx + index_diff >= local_pstate_idx)
return local_pstate_idx;
else
return highest_lpstate_idx + index_diff;
}
static inline void queue_gpstate_timer(struct global_pstate_info *gpstates)
{
unsigned int timer_interval;
if ((gpstates->elapsed_time + GPSTATE_TIMER_INTERVAL)
> MAX_RAMP_DOWN_TIME)
timer_interval = MAX_RAMP_DOWN_TIME - gpstates->elapsed_time;
else
timer_interval = GPSTATE_TIMER_INTERVAL;
mod_timer(&gpstates->timer, jiffies + msecs_to_jiffies(timer_interval));
}
void gpstate_timer_handler(unsigned long data)
{
struct cpufreq_policy *policy = (struct cpufreq_policy *)data;
struct global_pstate_info *gpstates = policy->driver_data;
int gpstate_idx;
unsigned int time_diff = jiffies_to_msecs(jiffies)
- gpstates->last_sampled_time;
struct powernv_smp_call_data freq_data;
if (!spin_trylock(&gpstates->gpstate_lock))
return;
gpstates->last_sampled_time += time_diff;
gpstates->elapsed_time += time_diff;
freq_data.pstate_id = idx_to_pstate(gpstates->last_lpstate_idx);
if ((gpstates->last_gpstate_idx == gpstates->last_lpstate_idx) ||
(gpstates->elapsed_time > MAX_RAMP_DOWN_TIME)) {
gpstate_idx = pstate_to_idx(freq_data.pstate_id);
reset_gpstates(policy);
gpstates->highest_lpstate_idx = gpstate_idx;
} else {
gpstate_idx = calc_global_pstate(gpstates->elapsed_time,
gpstates->highest_lpstate_idx,
gpstates->last_lpstate_idx);
}
if (gpstate_idx != gpstates->last_lpstate_idx)
queue_gpstate_timer(gpstates);
freq_data.gpstate_id = idx_to_pstate(gpstate_idx);
gpstates->last_gpstate_idx = pstate_to_idx(freq_data.gpstate_id);
gpstates->last_lpstate_idx = pstate_to_idx(freq_data.pstate_id);
spin_unlock(&gpstates->gpstate_lock);
smp_call_function_any(policy->cpus, set_pstate, &freq_data, 1);
}
static int powernv_cpufreq_target_index(struct cpufreq_policy *policy,
unsigned int new_index)
{
struct powernv_smp_call_data freq_data;
unsigned int cur_msec, gpstate_idx;
struct global_pstate_info *gpstates = policy->driver_data;
if (unlikely(rebooting) && new_index != get_nominal_index())
return 0;
if (!throttled)
powernv_cpufreq_throttle_check(NULL);
cur_msec = jiffies_to_msecs(get_jiffies_64());
spin_lock(&gpstates->gpstate_lock);
freq_data.pstate_id = idx_to_pstate(new_index);
if (!gpstates->last_sampled_time) {
gpstate_idx = new_index;
gpstates->highest_lpstate_idx = new_index;
goto gpstates_done;
}
if (gpstates->last_gpstate_idx < new_index) {
gpstates->elapsed_time += cur_msec -
gpstates->last_sampled_time;
if (gpstates->elapsed_time > MAX_RAMP_DOWN_TIME) {
reset_gpstates(policy);
gpstates->highest_lpstate_idx = new_index;
gpstate_idx = new_index;
} else {
gpstate_idx = calc_global_pstate(gpstates->elapsed_time,
gpstates->highest_lpstate_idx,
new_index);
}
} else {
reset_gpstates(policy);
gpstates->highest_lpstate_idx = new_index;
gpstate_idx = new_index;
}
if (gpstate_idx != new_index)
queue_gpstate_timer(gpstates);
else
del_timer_sync(&gpstates->timer);
gpstates_done:
freq_data.gpstate_id = idx_to_pstate(gpstate_idx);
gpstates->last_sampled_time = cur_msec;
gpstates->last_gpstate_idx = gpstate_idx;
gpstates->last_lpstate_idx = new_index;
spin_unlock(&gpstates->gpstate_lock);
smp_call_function_any(policy->cpus, set_pstate, &freq_data, 1);
return 0;
}
static int powernv_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
int base, i, ret;
struct kernfs_node *kn;
struct global_pstate_info *gpstates;
base = cpu_first_thread_sibling(policy->cpu);
for (i = 0; i < threads_per_core; i++)
cpumask_set_cpu(base + i, policy->cpus);
kn = kernfs_find_and_get(policy->kobj.sd, throttle_attr_grp.name);
if (!kn) {
int ret;
ret = sysfs_create_group(&policy->kobj, &throttle_attr_grp);
if (ret) {
pr_info("Failed to create throttle stats directory for cpu %d\n",
policy->cpu);
return ret;
}
} else {
kernfs_put(kn);
}
gpstates = kzalloc(sizeof(*gpstates), GFP_KERNEL);
if (!gpstates)
return -ENOMEM;
policy->driver_data = gpstates;
init_timer_pinned_deferrable(&gpstates->timer);
gpstates->timer.data = (unsigned long)policy;
gpstates->timer.function = gpstate_timer_handler;
gpstates->timer.expires = jiffies +
msecs_to_jiffies(GPSTATE_TIMER_INTERVAL);
spin_lock_init(&gpstates->gpstate_lock);
ret = cpufreq_table_validate_and_show(policy, powernv_freqs);
if (ret < 0)
kfree(policy->driver_data);
return ret;
}
static int powernv_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
kfree(policy->driver_data);
return 0;
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
index = cpufreq_table_find_index_c(&policy, policy.cur);
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
struct global_pstate_info *gpstates = policy->driver_data;
freq_data.pstate_id = idx_to_pstate(powernv_pstate_info.min);
freq_data.gpstate_id = idx_to_pstate(powernv_pstate_info.min);
smp_call_function_single(policy->cpu, set_pstate, &freq_data, 1);
del_timer_sync(&gpstates->timer);
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
