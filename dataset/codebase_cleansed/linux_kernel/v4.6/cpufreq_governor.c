ssize_t store_sampling_rate(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct policy_dbs_info *policy_dbs;
unsigned int rate;
int ret;
ret = sscanf(buf, "%u", &rate);
if (ret != 1)
return -EINVAL;
dbs_data->sampling_rate = max(rate, dbs_data->min_sampling_rate);
list_for_each_entry(policy_dbs, &dbs_data->policy_dbs_list, list) {
mutex_lock(&policy_dbs->timer_mutex);
gov_update_sample_delay(policy_dbs, 0);
mutex_unlock(&policy_dbs->timer_mutex);
}
return count;
}
void gov_update_cpu_data(struct dbs_data *dbs_data)
{
struct policy_dbs_info *policy_dbs;
list_for_each_entry(policy_dbs, &dbs_data->policy_dbs_list, list) {
unsigned int j;
for_each_cpu(j, policy_dbs->policy->cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->prev_cpu_idle = get_cpu_idle_time(j, &j_cdbs->prev_cpu_wall,
dbs_data->io_is_busy);
if (dbs_data->ignore_nice_load)
j_cdbs->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
}
}
static inline struct dbs_data *to_dbs_data(struct kobject *kobj)
{
return container_of(kobj, struct dbs_data, kobj);
}
static inline struct governor_attr *to_gov_attr(struct attribute *attr)
{
return container_of(attr, struct governor_attr, attr);
}
static ssize_t governor_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct dbs_data *dbs_data = to_dbs_data(kobj);
struct governor_attr *gattr = to_gov_attr(attr);
return gattr->show(dbs_data, buf);
}
static ssize_t governor_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(kobj);
struct governor_attr *gattr = to_gov_attr(attr);
int ret = -EBUSY;
mutex_lock(&dbs_data->mutex);
if (dbs_data->usage_count)
ret = gattr->store(dbs_data, buf, count);
mutex_unlock(&dbs_data->mutex);
return ret;
}
unsigned int dbs_update(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
unsigned int ignore_nice = dbs_data->ignore_nice_load;
unsigned int max_load = 0;
unsigned int sampling_rate, io_busy, j;
sampling_rate = dbs_data->sampling_rate * policy_dbs->rate_mult;
io_busy = dbs_data->io_is_busy;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
u64 cur_wall_time, cur_idle_time;
unsigned int idle_time, wall_time;
unsigned int load;
cur_idle_time = get_cpu_idle_time(j, &cur_wall_time, io_busy);
wall_time = cur_wall_time - j_cdbs->prev_cpu_wall;
j_cdbs->prev_cpu_wall = cur_wall_time;
idle_time = cur_idle_time - j_cdbs->prev_cpu_idle;
j_cdbs->prev_cpu_idle = cur_idle_time;
if (ignore_nice) {
u64 cur_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
idle_time += cputime_to_usecs(cur_nice - j_cdbs->prev_cpu_nice);
j_cdbs->prev_cpu_nice = cur_nice;
}
if (unlikely(!wall_time || wall_time < idle_time))
continue;
if (unlikely(wall_time > (2 * sampling_rate) &&
j_cdbs->prev_load)) {
load = j_cdbs->prev_load;
j_cdbs->prev_load = 0;
} else {
load = 100 * (wall_time - idle_time) / wall_time;
j_cdbs->prev_load = load;
}
if (load > max_load)
max_load = load;
}
return max_load;
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
cpufreq_set_update_util_data(cpu, &cdbs->update_util);
}
}
static inline void gov_clear_update_util(struct cpufreq_policy *policy)
{
int i;
for_each_cpu(i, policy->cpus)
cpufreq_set_update_util_data(i, NULL);
synchronize_sched();
}
static void gov_cancel_work(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
gov_clear_update_util(policy_dbs->policy);
irq_work_sync(&policy_dbs->irq_work);
cancel_work_sync(&policy_dbs->work);
atomic_set(&policy_dbs->work_count, 0);
policy_dbs->work_in_progress = false;
}
static void dbs_work_handler(struct work_struct *work)
{
struct policy_dbs_info *policy_dbs;
struct cpufreq_policy *policy;
struct dbs_governor *gov;
policy_dbs = container_of(work, struct policy_dbs_info, work);
policy = policy_dbs->policy;
gov = dbs_governor_of(policy);
mutex_lock(&policy_dbs->timer_mutex);
gov_update_sample_delay(policy_dbs, gov->gov_dbs_timer(policy));
mutex_unlock(&policy_dbs->timer_mutex);
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
unsigned long util, unsigned long max)
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
static struct policy_dbs_info *alloc_policy_dbs_info(struct cpufreq_policy *policy,
struct dbs_governor *gov)
{
struct policy_dbs_info *policy_dbs;
int j;
policy_dbs = gov->alloc();
if (!policy_dbs)
return NULL;
policy_dbs->policy = policy;
mutex_init(&policy_dbs->timer_mutex);
atomic_set(&policy_dbs->work_count, 0);
init_irq_work(&policy_dbs->irq_work, dbs_irq_work);
INIT_WORK(&policy_dbs->work, dbs_work_handler);
for_each_cpu(j, policy->related_cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->policy_dbs = policy_dbs;
j_cdbs->update_util.func = dbs_update_util_handler;
}
return policy_dbs;
}
static void free_policy_dbs_info(struct policy_dbs_info *policy_dbs,
struct dbs_governor *gov)
{
int j;
mutex_destroy(&policy_dbs->timer_mutex);
for_each_cpu(j, policy_dbs->policy->related_cpus) {
struct cpu_dbs_info *j_cdbs = &per_cpu(cpu_dbs, j);
j_cdbs->policy_dbs = NULL;
j_cdbs->update_util.func = NULL;
}
gov->free(policy_dbs);
}
static int cpufreq_governor_init(struct cpufreq_policy *policy)
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
mutex_lock(&dbs_data->mutex);
dbs_data->usage_count++;
list_add(&policy_dbs->list, &dbs_data->policy_dbs_list);
mutex_unlock(&dbs_data->mutex);
goto out;
}
dbs_data = kzalloc(sizeof(*dbs_data), GFP_KERNEL);
if (!dbs_data) {
ret = -ENOMEM;
goto free_policy_dbs_info;
}
INIT_LIST_HEAD(&dbs_data->policy_dbs_list);
mutex_init(&dbs_data->mutex);
ret = gov->init(dbs_data, !policy->governor->initialized);
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
policy->governor_data = policy_dbs;
policy_dbs->dbs_data = dbs_data;
dbs_data->usage_count = 1;
list_add(&policy_dbs->list, &dbs_data->policy_dbs_list);
gov->kobj_type.sysfs_ops = &governor_sysfs_ops;
ret = kobject_init_and_add(&dbs_data->kobj, &gov->kobj_type,
get_governor_parent_kobj(policy),
"%s", gov->gov.name);
if (!ret)
goto out;
pr_err("cpufreq: Governor initialization failed (dbs_data kobject init error %d)\n", ret);
policy->governor_data = NULL;
if (!have_governor_per_policy())
gov->gdbs_data = NULL;
gov->exit(dbs_data, !policy->governor->initialized);
kfree(dbs_data);
free_policy_dbs_info:
free_policy_dbs_info(policy_dbs, gov);
out:
mutex_unlock(&gov_dbs_data_mutex);
return ret;
}
static int cpufreq_governor_exit(struct cpufreq_policy *policy)
{
struct dbs_governor *gov = dbs_governor_of(policy);
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
int count;
mutex_lock(&gov_dbs_data_mutex);
mutex_lock(&dbs_data->mutex);
list_del(&policy_dbs->list);
count = --dbs_data->usage_count;
mutex_unlock(&dbs_data->mutex);
if (!count) {
kobject_put(&dbs_data->kobj);
policy->governor_data = NULL;
if (!have_governor_per_policy())
gov->gdbs_data = NULL;
gov->exit(dbs_data, policy->governor->initialized == 1);
mutex_destroy(&dbs_data->mutex);
kfree(dbs_data);
} else {
policy->governor_data = NULL;
}
free_policy_dbs_info(policy_dbs, gov);
mutex_unlock(&gov_dbs_data_mutex);
return 0;
}
static int cpufreq_governor_start(struct cpufreq_policy *policy)
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
unsigned int prev_load;
j_cdbs->prev_cpu_idle = get_cpu_idle_time(j, &j_cdbs->prev_cpu_wall, io_busy);
prev_load = j_cdbs->prev_cpu_wall - j_cdbs->prev_cpu_idle;
j_cdbs->prev_load = 100 * prev_load / (unsigned int)j_cdbs->prev_cpu_wall;
if (ignore_nice)
j_cdbs->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
gov->start(policy);
gov_set_update_util(policy_dbs, sampling_rate);
return 0;
}
static int cpufreq_governor_stop(struct cpufreq_policy *policy)
{
gov_cancel_work(policy);
return 0;
}
static int cpufreq_governor_limits(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
mutex_lock(&policy_dbs->timer_mutex);
if (policy->max < policy->cur)
__cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
else if (policy->min > policy->cur)
__cpufreq_driver_target(policy, policy->min, CPUFREQ_RELATION_L);
gov_update_sample_delay(policy_dbs, 0);
mutex_unlock(&policy_dbs->timer_mutex);
return 0;
}
int cpufreq_governor_dbs(struct cpufreq_policy *policy, unsigned int event)
{
if (event == CPUFREQ_GOV_POLICY_INIT) {
return cpufreq_governor_init(policy);
} else if (policy->governor_data) {
switch (event) {
case CPUFREQ_GOV_POLICY_EXIT:
return cpufreq_governor_exit(policy);
case CPUFREQ_GOV_START:
return cpufreq_governor_start(policy);
case CPUFREQ_GOV_STOP:
return cpufreq_governor_stop(policy);
case CPUFREQ_GOV_LIMITS:
return cpufreq_governor_limits(policy);
}
}
return -EINVAL;
}
