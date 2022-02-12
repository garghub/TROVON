static struct kobject *get_governor_parent_kobj(struct cpufreq_policy *policy)
{
if (have_governor_per_policy())
return &policy->kobj;
else
return cpufreq_global_kobject;
}
static struct attribute_group *get_sysfs_attr(struct dbs_data *dbs_data)
{
if (have_governor_per_policy())
return dbs_data->cdata->attr_group_gov_pol;
else
return dbs_data->cdata->attr_group_gov_sys;
}
static inline u64 get_cpu_idle_time_jiffy(unsigned int cpu, u64 *wall)
{
u64 idle_time;
u64 cur_wall_time;
u64 busy_time;
cur_wall_time = jiffies64_to_cputime64(get_jiffies_64());
busy_time = kcpustat_cpu(cpu).cpustat[CPUTIME_USER];
busy_time += kcpustat_cpu(cpu).cpustat[CPUTIME_SYSTEM];
busy_time += kcpustat_cpu(cpu).cpustat[CPUTIME_IRQ];
busy_time += kcpustat_cpu(cpu).cpustat[CPUTIME_SOFTIRQ];
busy_time += kcpustat_cpu(cpu).cpustat[CPUTIME_STEAL];
busy_time += kcpustat_cpu(cpu).cpustat[CPUTIME_NICE];
idle_time = cur_wall_time - busy_time;
if (wall)
*wall = cputime_to_usecs(cur_wall_time);
return cputime_to_usecs(idle_time);
}
u64 get_cpu_idle_time(unsigned int cpu, u64 *wall, int io_busy)
{
u64 idle_time = get_cpu_idle_time_us(cpu, io_busy ? wall : NULL);
if (idle_time == -1ULL)
return get_cpu_idle_time_jiffy(cpu, wall);
else if (!io_busy)
idle_time += get_cpu_iowait_time_us(cpu, wall);
return idle_time;
}
void dbs_check_cpu(struct dbs_data *dbs_data, int cpu)
{
struct cpu_dbs_common_info *cdbs = dbs_data->cdata->get_cpu_cdbs(cpu);
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
struct cpufreq_policy *policy;
unsigned int max_load = 0;
unsigned int ignore_nice;
unsigned int j;
if (dbs_data->cdata->governor == GOV_ONDEMAND)
ignore_nice = od_tuners->ignore_nice;
else
ignore_nice = cs_tuners->ignore_nice;
policy = cdbs->cur_policy;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_common_info *j_cdbs;
u64 cur_wall_time, cur_idle_time;
unsigned int idle_time, wall_time;
unsigned int load;
int io_busy = 0;
j_cdbs = dbs_data->cdata->get_cpu_cdbs(j);
if (dbs_data->cdata->governor == GOV_ONDEMAND)
io_busy = od_tuners->io_is_busy;
cur_idle_time = get_cpu_idle_time(j, &cur_wall_time, io_busy);
wall_time = (unsigned int)
(cur_wall_time - j_cdbs->prev_cpu_wall);
j_cdbs->prev_cpu_wall = cur_wall_time;
idle_time = (unsigned int)
(cur_idle_time - j_cdbs->prev_cpu_idle);
j_cdbs->prev_cpu_idle = cur_idle_time;
if (ignore_nice) {
u64 cur_nice;
unsigned long cur_nice_jiffies;
cur_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE] -
cdbs->prev_cpu_nice;
cur_nice_jiffies = (unsigned long)
cputime64_to_jiffies64(cur_nice);
cdbs->prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
idle_time += jiffies_to_usecs(cur_nice_jiffies);
}
if (unlikely(!wall_time || wall_time < idle_time))
continue;
load = 100 * (wall_time - idle_time) / wall_time;
if (dbs_data->cdata->governor == GOV_ONDEMAND) {
int freq_avg = __cpufreq_driver_getavg(policy, j);
if (freq_avg <= 0)
freq_avg = policy->cur;
load *= freq_avg;
}
if (load > max_load)
max_load = load;
}
dbs_data->cdata->gov_check_cpu(cpu, max_load);
}
static inline void __gov_queue_work(int cpu, struct dbs_data *dbs_data,
unsigned int delay)
{
struct cpu_dbs_common_info *cdbs = dbs_data->cdata->get_cpu_cdbs(cpu);
mod_delayed_work_on(cpu, system_wq, &cdbs->work, delay);
}
void gov_queue_work(struct dbs_data *dbs_data, struct cpufreq_policy *policy,
unsigned int delay, bool all_cpus)
{
int i;
if (!all_cpus) {
__gov_queue_work(smp_processor_id(), dbs_data, delay);
} else {
get_online_cpus();
for_each_cpu(i, policy->cpus)
__gov_queue_work(i, dbs_data, delay);
put_online_cpus();
}
}
static inline void gov_cancel_work(struct dbs_data *dbs_data,
struct cpufreq_policy *policy)
{
struct cpu_dbs_common_info *cdbs;
int i;
for_each_cpu(i, policy->cpus) {
cdbs = dbs_data->cdata->get_cpu_cdbs(i);
cancel_delayed_work_sync(&cdbs->work);
}
}
bool need_load_eval(struct cpu_dbs_common_info *cdbs,
unsigned int sampling_rate)
{
if (policy_is_shared(cdbs->cur_policy)) {
ktime_t time_now = ktime_get();
s64 delta_us = ktime_us_delta(time_now, cdbs->time_stamp);
if (delta_us < (s64)(sampling_rate / 2))
return false;
else
cdbs->time_stamp = time_now;
}
return true;
}
static void set_sampling_rate(struct dbs_data *dbs_data,
unsigned int sampling_rate)
{
if (dbs_data->cdata->governor == GOV_CONSERVATIVE) {
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
cs_tuners->sampling_rate = sampling_rate;
} else {
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
od_tuners->sampling_rate = sampling_rate;
}
}
int cpufreq_governor_dbs(struct cpufreq_policy *policy,
struct common_dbs_data *cdata, unsigned int event)
{
struct dbs_data *dbs_data;
struct od_cpu_dbs_info_s *od_dbs_info = NULL;
struct cs_cpu_dbs_info_s *cs_dbs_info = NULL;
struct od_ops *od_ops = NULL;
struct od_dbs_tuners *od_tuners = NULL;
struct cs_dbs_tuners *cs_tuners = NULL;
struct cpu_dbs_common_info *cpu_cdbs;
unsigned int sampling_rate, latency, ignore_nice, j, cpu = policy->cpu;
int io_busy = 0;
int rc;
if (have_governor_per_policy())
dbs_data = policy->governor_data;
else
dbs_data = cdata->gdbs_data;
WARN_ON(!dbs_data && (event != CPUFREQ_GOV_POLICY_INIT));
switch (event) {
case CPUFREQ_GOV_POLICY_INIT:
if (have_governor_per_policy()) {
WARN_ON(dbs_data);
} else if (dbs_data) {
dbs_data->usage_count++;
policy->governor_data = dbs_data;
return 0;
}
dbs_data = kzalloc(sizeof(*dbs_data), GFP_KERNEL);
if (!dbs_data) {
pr_err("%s: POLICY_INIT: kzalloc failed\n", __func__);
return -ENOMEM;
}
dbs_data->cdata = cdata;
dbs_data->usage_count = 1;
rc = cdata->init(dbs_data);
if (rc) {
pr_err("%s: POLICY_INIT: init() failed\n", __func__);
kfree(dbs_data);
return rc;
}
rc = sysfs_create_group(get_governor_parent_kobj(policy),
get_sysfs_attr(dbs_data));
if (rc) {
cdata->exit(dbs_data);
kfree(dbs_data);
return rc;
}
policy->governor_data = dbs_data;
latency = policy->cpuinfo.transition_latency / 1000;
if (latency == 0)
latency = 1;
dbs_data->min_sampling_rate = max(dbs_data->min_sampling_rate,
MIN_LATENCY_MULTIPLIER * latency);
set_sampling_rate(dbs_data, max(dbs_data->min_sampling_rate,
latency * LATENCY_MULTIPLIER));
if ((cdata->governor == GOV_CONSERVATIVE) &&
(!policy->governor->initialized)) {
struct cs_ops *cs_ops = dbs_data->cdata->gov_ops;
cpufreq_register_notifier(cs_ops->notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
if (!have_governor_per_policy())
cdata->gdbs_data = dbs_data;
return 0;
case CPUFREQ_GOV_POLICY_EXIT:
if (!--dbs_data->usage_count) {
sysfs_remove_group(get_governor_parent_kobj(policy),
get_sysfs_attr(dbs_data));
if ((dbs_data->cdata->governor == GOV_CONSERVATIVE) &&
(policy->governor->initialized == 1)) {
struct cs_ops *cs_ops = dbs_data->cdata->gov_ops;
cpufreq_unregister_notifier(cs_ops->notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
cdata->exit(dbs_data);
kfree(dbs_data);
cdata->gdbs_data = NULL;
}
policy->governor_data = NULL;
return 0;
}
cpu_cdbs = dbs_data->cdata->get_cpu_cdbs(cpu);
if (dbs_data->cdata->governor == GOV_CONSERVATIVE) {
cs_tuners = dbs_data->tuners;
cs_dbs_info = dbs_data->cdata->get_cpu_dbs_info_s(cpu);
sampling_rate = cs_tuners->sampling_rate;
ignore_nice = cs_tuners->ignore_nice;
} else {
od_tuners = dbs_data->tuners;
od_dbs_info = dbs_data->cdata->get_cpu_dbs_info_s(cpu);
sampling_rate = od_tuners->sampling_rate;
ignore_nice = od_tuners->ignore_nice;
od_ops = dbs_data->cdata->gov_ops;
io_busy = od_tuners->io_is_busy;
}
switch (event) {
case CPUFREQ_GOV_START:
if (!policy->cur)
return -EINVAL;
mutex_lock(&dbs_data->mutex);
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_common_info *j_cdbs =
dbs_data->cdata->get_cpu_cdbs(j);
j_cdbs->cpu = j;
j_cdbs->cur_policy = policy;
j_cdbs->prev_cpu_idle = get_cpu_idle_time(j,
&j_cdbs->prev_cpu_wall, io_busy);
if (ignore_nice)
j_cdbs->prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
mutex_init(&j_cdbs->timer_mutex);
INIT_DEFERRABLE_WORK(&j_cdbs->work,
dbs_data->cdata->gov_dbs_timer);
}
if (dbs_data->cdata->governor == GOV_CONSERVATIVE) {
cs_dbs_info->down_skip = 0;
cs_dbs_info->enable = 1;
cs_dbs_info->requested_freq = policy->cur;
} else {
od_dbs_info->rate_mult = 1;
od_dbs_info->sample_type = OD_NORMAL_SAMPLE;
od_ops->powersave_bias_init_cpu(cpu);
}
mutex_unlock(&dbs_data->mutex);
cpu_cdbs->time_stamp = ktime_get();
gov_queue_work(dbs_data, policy,
delay_for_sampling_rate(sampling_rate), true);
break;
case CPUFREQ_GOV_STOP:
if (dbs_data->cdata->governor == GOV_CONSERVATIVE)
cs_dbs_info->enable = 0;
gov_cancel_work(dbs_data, policy);
mutex_lock(&dbs_data->mutex);
mutex_destroy(&cpu_cdbs->timer_mutex);
mutex_unlock(&dbs_data->mutex);
break;
case CPUFREQ_GOV_LIMITS:
mutex_lock(&cpu_cdbs->timer_mutex);
if (policy->max < cpu_cdbs->cur_policy->cur)
__cpufreq_driver_target(cpu_cdbs->cur_policy,
policy->max, CPUFREQ_RELATION_H);
else if (policy->min > cpu_cdbs->cur_policy->cur)
__cpufreq_driver_target(cpu_cdbs->cur_policy,
policy->min, CPUFREQ_RELATION_L);
dbs_check_cpu(dbs_data, cpu);
mutex_unlock(&cpu_cdbs->timer_mutex);
break;
}
return 0;
}
