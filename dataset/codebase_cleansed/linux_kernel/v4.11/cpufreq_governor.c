ssize_t store_sampling_rate(struct gov_attr_set *attr_set, const char *buf,
size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
struct policy_dbs_info *policy_dbs;
unsigned int rate;
int ret;
ret = sscanf(buf, "%u", &rate);
if (ret != 1)
return -EINVAL;
dbs_data->sampling_rate = max(rate, dbs_data->min_sampling_rate);
list_for_each_entry(policy_dbs, &attr_set->policy_list, list) {
mutex_lock(&policy_dbs->update_mutex);
gov_update_sample_delay(policy_dbs, 0);
mutex_unlock(&policy_dbs->update_mutex);
}
return count;
}
void gov_update_cpu_data(struct dbs_data *dbs_data)
{
struct policy_dbs_info *policy_dbs;
list_for_each_entry(policy_dbs, &dbs_data->attr_set.policy_list, list) {
unsigned int j;
for_each_cpu(j, policy_dbs->policy->cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->prev_cpu_idle = get_cpu_idle_time(j, &j_cdbs->prev_update_time,
dbs_data->io_is_busy);
if (dbs_data->ignore_nice_load)
j_cdbs->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
}
}
unsigned int dbs_update(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
unsigned int ignore_nice = dbs_data->ignore_nice_load;
unsigned int max_load = 0, idle_periods = UINT_MAX;
unsigned int sampling_rate, io_busy, j;
sampling_rate = dbs_data->sampling_rate * policy_dbs->rate_mult;
io_busy = dbs_data->io_is_busy;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
u64 update_time, cur_idle_time;
unsigned int idle_time, time_elapsed;
unsigned int load;
cur_idle_time = get_cpu_idle_time(j, &update_time, io_busy);
time_elapsed = update_time - j_cdbs->prev_update_time;
j_cdbs->prev_update_time = update_time;
idle_time = cur_idle_time - j_cdbs->prev_cpu_idle;
j_cdbs->prev_cpu_idle = cur_idle_time;
if (ignore_nice) {
u64 cur_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
idle_time += div_u64(cur_nice - j_cdbs->prev_cpu_nice, NSEC_PER_USEC);
j_cdbs->prev_cpu_nice = cur_nice;
}
if (unlikely(!time_elapsed)) {
load = j_cdbs->prev_load;
} else if (unlikely(time_elapsed > 2 * sampling_rate &&
j_cdbs->prev_load)) {
load = j_cdbs->prev_load;
j_cdbs->prev_load = 0;
} else {
if (time_elapsed >= idle_time) {
load = 100 * (time_elapsed - idle_time) / time_elapsed;
} else {
load = (int)idle_time < 0 ? 100 : 0;
}
j_cdbs->prev_load = load;
}
if (time_elapsed > 2 * sampling_rate) {
unsigned int periods = time_elapsed / sampling_rate;
if (periods < idle_periods)
idle_periods = periods;
}
if (load > max_load)
max_load = load;
}
policy_dbs->idle_periods = idle_periods;
return max_load;
}
static void dbs_work_handler(struct work_struct *work)
{
struct policy_dbs_info *policy_dbs;
struct cpufreq_policy *policy;
struct dbs_governor *gov;
policy_dbs = container_of(work, struct policy_dbs_info, work);
policy = policy_dbs->policy;
gov = dbs_governor_of(policy);
mutex_lock(&policy_dbs->update_mutex);
gov_update_sample_delay(policy_dbs, gov->gov_dbs_update(policy));
mutex_unlock(&policy_dbs->update_mutex);
atomic_set(&policy_dbs->work_count, 0);
smp_wmb();
policy_dbs->work_in_progress = false;
}
static void dbs_irq_work(struct irq_work *irq_work)
{
struct policy_dbs_info *policy_dbs;
policy_dbs = container_of(irq_work, struct policy_dbs_info, irq_work);
schedule_work_on(smp_processor_id(), &policy_dbs->work);
}
static void dbs_update_util_handler(struct update_util_data *data, u64 time,
unsigned int flags)
{
struct cpu_dbs_info *cdbs = container_of(data, struct cpu_dbs_info, update_util);
struct policy_dbs_info *policy_dbs = cdbs->policy_dbs;
u64 delta_ns, lst;
if (policy_dbs->work_in_progress)
return;
smp_rmb();
lst = READ_ONCE(policy_dbs->last_sample_time);
delta_ns = time - lst;
if ((s64)delta_ns < policy_dbs->sample_delay_ns)
return;
if (policy_dbs->is_shared) {
if (!atomic_add_unless(&policy_dbs->work_count, 1, 1))
return;
if (unlikely(lst != READ_ONCE(policy_dbs->last_sample_time))) {
atomic_set(&policy_dbs->work_count, 0);
return;
}
}
policy_dbs->last_sample_time = time;
policy_dbs->work_in_progress = true;
irq_work_queue(&policy_dbs->irq_work);
}
static void gov_set_update_util(struct policy_dbs_info *policy_dbs,
unsigned int delay_us)
{
struct cpufreq_policy *policy = policy_dbs->policy;
int cpu;
gov_update_sample_delay(policy_dbs, delay_us);
policy_dbs->last_sample_time = 0;
for_each_cpu(cpu, policy->cpus) {
struct cpu_dbs_info *cdbs = &per_cpu(cpu_dbs, cpu);
cpufreq_add_update_util_hook(cpu, &cdbs->update_util,
dbs_update_util_handler);
}
}
static inline void gov_clear_update_util(struct cpufreq_policy *policy)
{
int i;
for_each_cpu(i, policy->cpus)
cpufreq_remove_update_util_hook(i);
synchronize_sched();
}
static struct policy_dbs_info *alloc_policy_dbs_info(struct cpufreq_policy *policy,
struct dbs_governor *gov)
{
struct policy_dbs_info *policy_dbs;
int j;
policy_dbs = gov->alloc();
if (!policy_dbs)
return NULL;
policy_dbs->policy = policy;
mutex_init(&policy_dbs->update_mutex);
atomic_set(&policy_dbs->work_count, 0);
init_irq_work(&policy_dbs->irq_work, dbs_irq_work);
INIT_WORK(&policy_dbs->work, dbs_work_handler);
for_each_cpu(j, policy->related_cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->policy_dbs = policy_dbs;
}
return policy_dbs;
}
static void free_policy_dbs_info(struct policy_dbs_info *policy_dbs,
struct dbs_governor *gov)
{
int j;
mutex_destroy(&policy_dbs->update_mutex);
for_each_cpu(j, policy_dbs->policy->related_cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->policy_dbs = NULL;
j_cdbs->update_util.func = NULL;
}
gov->free(policy_dbs);
}
int cpufreq_dbs_governor_init(struct cpufreq_policy *policy)
{
struct dbs_governor *gov = dbs_governor_of(policy);
struct dbs_data *dbs_data;
struct policy_dbs_info *policy_dbs;
unsigned int latency;
int ret = 0;
if (policy->governor_data)
return -EBUSY;
policy_dbs = alloc_policy_dbs_info(policy, gov);
if (!policy_dbs)
return -ENOMEM;
mutex_lock(&gov_dbs_data_mutex);
dbs_data = gov->gdbs_data;
if (dbs_data) {
if (WARN_ON(have_governor_per_policy())) {
ret = -EINVAL;
goto free_policy_dbs_info;
}
policy_dbs->dbs_data = dbs_data;
policy->governor_data = policy_dbs;
gov_attr_set_get(&dbs_data->attr_set, &policy_dbs->list);
goto out;
}
dbs_data = kzalloc(sizeof(*dbs_data), GFP_KERNEL);
if (!dbs_data) {
ret = -ENOMEM;
goto free_policy_dbs_info;
}
gov_attr_set_init(&dbs_data->attr_set, &policy_dbs->list);
ret = gov->init(dbs_data);
if (ret)
goto free_policy_dbs_info;
latency = policy->cpuinfo.transition_latency / 1000;
if (latency == 0)
latency = 1;
dbs_data->min_sampling_rate = max(dbs_data->min_sampling_rate,
MIN_LATENCY_MULTIPLIER * latency);
dbs_data->sampling_rate = max(dbs_data->min_sampling_rate,
LATENCY_MULTIPLIER * latency);
if (!have_governor_per_policy())
gov->gdbs_data = dbs_data;
policy_dbs->dbs_data = dbs_data;
policy->governor_data = policy_dbs;
gov->kobj_type.sysfs_ops = &governor_sysfs_ops;
ret = kobject_init_and_add(&dbs_data->attr_set.kobj, &gov->kobj_type,
get_governor_parent_kobj(policy),
"%s", gov->gov.name);
if (!ret)
goto out;
pr_err("initialization failed (dbs_data kobject init error %d)\n", ret);
policy->governor_data = NULL;
if (!have_governor_per_policy())
gov->gdbs_data = NULL;
gov->exit(dbs_data);
kfree(dbs_data);
free_policy_dbs_info:
free_policy_dbs_info(policy_dbs, gov);
out:
mutex_unlock(&gov_dbs_data_mutex);
return ret;
}
void cpufreq_dbs_governor_exit(struct cpufreq_policy *policy)
{
struct dbs_governor *gov = dbs_governor_of(policy);
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
unsigned int count;
mutex_lock(&gov_dbs_data_mutex);
count = gov_attr_set_put(&dbs_data->attr_set, &policy_dbs->list);
policy->governor_data = NULL;
if (!count) {
if (!have_governor_per_policy())
gov->gdbs_data = NULL;
gov->exit(dbs_data);
kfree(dbs_data);
}
free_policy_dbs_info(policy_dbs, gov);
mutex_unlock(&gov_dbs_data_mutex);
}
int cpufreq_dbs_governor_start(struct cpufreq_policy *policy)
{
struct dbs_governor *gov = dbs_governor_of(policy);
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
unsigned int sampling_rate, ignore_nice, j;
unsigned int io_busy;
if (!policy->cur)
return -EINVAL;
policy_dbs->is_shared = policy_is_shared(policy);
policy_dbs->rate_mult = 1;
sampling_rate = dbs_data->sampling_rate;
ignore_nice = dbs_data->ignore_nice_load;
io_busy = dbs_data->io_is_busy;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->prev_cpu_idle = get_cpu_idle_time(j, &j_cdbs->prev_update_time, io_busy);
j_cdbs->prev_load = 0;
if (ignore_nice)
j_cdbs->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
gov->start(policy);
gov_set_update_util(policy_dbs, sampling_rate);
return 0;
}
void cpufreq_dbs_governor_stop(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
gov_clear_update_util(policy_dbs->policy);
irq_work_sync(&policy_dbs->irq_work);
cancel_work_sync(&policy_dbs->work);
atomic_set(&policy_dbs->work_count, 0);
policy_dbs->work_in_progress = false;
}
void cpufreq_dbs_governor_limits(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
mutex_lock(&policy_dbs->update_mutex);
cpufreq_policy_apply_limits(policy);
gov_update_sample_delay(policy_dbs, 0);
mutex_unlock(&policy_dbs->update_mutex);
}
