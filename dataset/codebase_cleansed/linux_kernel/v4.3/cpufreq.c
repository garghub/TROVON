static inline bool policy_is_inactive(struct cpufreq_policy *policy)
{
return cpumask_empty(policy->cpus);
}
static bool suitable_policy(struct cpufreq_policy *policy, bool active)
{
return active == !policy_is_inactive(policy);
}
static struct cpufreq_policy *next_policy(struct cpufreq_policy *policy,
bool active)
{
do {
policy = list_next_entry(policy, policy_list);
if (&policy->policy_list == &cpufreq_policy_list)
return NULL;
} while (!suitable_policy(policy, active));
return policy;
}
static struct cpufreq_policy *first_policy(bool active)
{
struct cpufreq_policy *policy;
if (list_empty(&cpufreq_policy_list))
return NULL;
policy = list_first_entry(&cpufreq_policy_list, typeof(*policy),
policy_list);
if (!suitable_policy(policy, active))
policy = next_policy(policy, active);
return policy;
}
static inline bool has_target(void)
{
return cpufreq_driver->target_index || cpufreq_driver->target;
}
static int __init init_cpufreq_transition_notifier_list(void)
{
srcu_init_notifier_head(&cpufreq_transition_notifier_list);
init_cpufreq_transition_notifier_list_called = true;
return 0;
}
static int cpufreq_disabled(void)
{
return off;
}
void disable_cpufreq(void)
{
off = 1;
}
bool have_governor_per_policy(void)
{
return !!(cpufreq_driver->flags & CPUFREQ_HAVE_GOVERNOR_PER_POLICY);
}
struct kobject *get_governor_parent_kobj(struct cpufreq_policy *policy)
{
if (have_governor_per_policy())
return &policy->kobj;
else
return cpufreq_global_kobject;
}
struct cpufreq_frequency_table *cpufreq_frequency_get_table(unsigned int cpu)
{
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
return policy && !policy_is_inactive(policy) ?
policy->freq_table : NULL;
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
int cpufreq_generic_init(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *table,
unsigned int transition_latency)
{
int ret;
ret = cpufreq_table_validate_and_show(policy, table);
if (ret) {
pr_err("%s: invalid frequency table: %d\n", __func__, ret);
return ret;
}
policy->cpuinfo.transition_latency = transition_latency;
cpumask_setall(policy->cpus);
return 0;
}
struct cpufreq_policy *cpufreq_cpu_get_raw(unsigned int cpu)
{
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
return policy && cpumask_test_cpu(cpu, policy->cpus) ? policy : NULL;
}
unsigned int cpufreq_generic_get(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get_raw(cpu);
if (!policy || IS_ERR(policy->clk)) {
pr_err("%s: No %s associated to cpu: %d\n",
__func__, policy ? "clk" : "policy", cpu);
return 0;
}
return clk_get_rate(policy->clk) / 1000;
}
struct cpufreq_policy *cpufreq_cpu_get(unsigned int cpu)
{
struct cpufreq_policy *policy = NULL;
unsigned long flags;
if (WARN_ON(cpu >= nr_cpu_ids))
return NULL;
read_lock_irqsave(&cpufreq_driver_lock, flags);
if (cpufreq_driver) {
policy = cpufreq_cpu_get_raw(cpu);
if (policy)
kobject_get(&policy->kobj);
}
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
return policy;
}
void cpufreq_cpu_put(struct cpufreq_policy *policy)
{
kobject_put(&policy->kobj);
}
static void adjust_jiffies(unsigned long val, struct cpufreq_freqs *ci)
{
#ifndef CONFIG_SMP
static unsigned long l_p_j_ref;
static unsigned int l_p_j_ref_freq;
if (ci->flags & CPUFREQ_CONST_LOOPS)
return;
if (!l_p_j_ref_freq) {
l_p_j_ref = loops_per_jiffy;
l_p_j_ref_freq = ci->old;
pr_debug("saving %lu as reference value for loops_per_jiffy; freq is %u kHz\n",
l_p_j_ref, l_p_j_ref_freq);
}
if (val == CPUFREQ_POSTCHANGE && ci->old != ci->new) {
loops_per_jiffy = cpufreq_scale(l_p_j_ref, l_p_j_ref_freq,
ci->new);
pr_debug("scaling loops_per_jiffy to %lu for frequency %u kHz\n",
loops_per_jiffy, ci->new);
}
#endif
}
static void __cpufreq_notify_transition(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, unsigned int state)
{
BUG_ON(irqs_disabled());
if (cpufreq_disabled())
return;
freqs->flags = cpufreq_driver->flags;
pr_debug("notification %u of frequency transition to %u kHz\n",
state, freqs->new);
switch (state) {
case CPUFREQ_PRECHANGE:
if (!(cpufreq_driver->flags & CPUFREQ_CONST_LOOPS)) {
if ((policy) && (policy->cpu == freqs->cpu) &&
(policy->cur) && (policy->cur != freqs->old)) {
pr_debug("Warning: CPU frequency is %u, cpufreq assumed %u kHz\n",
freqs->old, policy->cur);
freqs->old = policy->cur;
}
}
srcu_notifier_call_chain(&cpufreq_transition_notifier_list,
CPUFREQ_PRECHANGE, freqs);
adjust_jiffies(CPUFREQ_PRECHANGE, freqs);
break;
case CPUFREQ_POSTCHANGE:
adjust_jiffies(CPUFREQ_POSTCHANGE, freqs);
pr_debug("FREQ: %lu - CPU: %lu\n",
(unsigned long)freqs->new, (unsigned long)freqs->cpu);
trace_cpu_frequency(freqs->new, freqs->cpu);
srcu_notifier_call_chain(&cpufreq_transition_notifier_list,
CPUFREQ_POSTCHANGE, freqs);
if (likely(policy) && likely(policy->cpu == freqs->cpu))
policy->cur = freqs->new;
break;
}
}
static void cpufreq_notify_transition(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, unsigned int state)
{
for_each_cpu(freqs->cpu, policy->cpus)
__cpufreq_notify_transition(policy, freqs, state);
}
static void cpufreq_notify_post_transition(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, int transition_failed)
{
cpufreq_notify_transition(policy, freqs, CPUFREQ_POSTCHANGE);
if (!transition_failed)
return;
swap(freqs->old, freqs->new);
cpufreq_notify_transition(policy, freqs, CPUFREQ_PRECHANGE);
cpufreq_notify_transition(policy, freqs, CPUFREQ_POSTCHANGE);
}
void cpufreq_freq_transition_begin(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs)
{
WARN_ON(!(cpufreq_driver->flags & CPUFREQ_ASYNC_NOTIFICATION)
&& current == policy->transition_task);
wait:
wait_event(policy->transition_wait, !policy->transition_ongoing);
spin_lock(&policy->transition_lock);
if (unlikely(policy->transition_ongoing)) {
spin_unlock(&policy->transition_lock);
goto wait;
}
policy->transition_ongoing = true;
policy->transition_task = current;
spin_unlock(&policy->transition_lock);
cpufreq_notify_transition(policy, freqs, CPUFREQ_PRECHANGE);
}
void cpufreq_freq_transition_end(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, int transition_failed)
{
if (unlikely(WARN_ON(!policy->transition_ongoing)))
return;
cpufreq_notify_post_transition(policy, freqs, transition_failed);
policy->transition_ongoing = false;
policy->transition_task = NULL;
wake_up(&policy->transition_wait);
}
static ssize_t show_boost(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", cpufreq_driver->boost_enabled);
}
static ssize_t store_boost(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
int ret, enable;
ret = sscanf(buf, "%d", &enable);
if (ret != 1 || enable < 0 || enable > 1)
return -EINVAL;
if (cpufreq_boost_trigger_state(enable)) {
pr_err("%s: Cannot %s BOOST!\n",
__func__, enable ? "enable" : "disable");
return -EINVAL;
}
pr_debug("%s: cpufreq BOOST %s\n",
__func__, enable ? "enabled" : "disabled");
return count;
}
static struct cpufreq_governor *find_governor(const char *str_governor)
{
struct cpufreq_governor *t;
for_each_governor(t)
if (!strncasecmp(str_governor, t->name, CPUFREQ_NAME_LEN))
return t;
return NULL;
}
static int cpufreq_parse_governor(char *str_governor, unsigned int *policy,
struct cpufreq_governor **governor)
{
int err = -EINVAL;
if (cpufreq_driver->setpolicy) {
if (!strncasecmp(str_governor, "performance", CPUFREQ_NAME_LEN)) {
*policy = CPUFREQ_POLICY_PERFORMANCE;
err = 0;
} else if (!strncasecmp(str_governor, "powersave",
CPUFREQ_NAME_LEN)) {
*policy = CPUFREQ_POLICY_POWERSAVE;
err = 0;
}
} else {
struct cpufreq_governor *t;
mutex_lock(&cpufreq_governor_mutex);
t = find_governor(str_governor);
if (t == NULL) {
int ret;
mutex_unlock(&cpufreq_governor_mutex);
ret = request_module("cpufreq_%s", str_governor);
mutex_lock(&cpufreq_governor_mutex);
if (ret == 0)
t = find_governor(str_governor);
}
if (t != NULL) {
*governor = t;
err = 0;
}
mutex_unlock(&cpufreq_governor_mutex);
}
return err;
}
static ssize_t show_scaling_cur_freq(struct cpufreq_policy *policy, char *buf)
{
ssize_t ret;
if (cpufreq_driver && cpufreq_driver->setpolicy && cpufreq_driver->get)
ret = sprintf(buf, "%u\n", cpufreq_driver->get(policy->cpu));
else
ret = sprintf(buf, "%u\n", policy->cur);
return ret;
}
static ssize_t show_cpuinfo_cur_freq(struct cpufreq_policy *policy,
char *buf)
{
unsigned int cur_freq = __cpufreq_get(policy);
if (!cur_freq)
return sprintf(buf, "<unknown>");
return sprintf(buf, "%u\n", cur_freq);
}
static ssize_t show_scaling_governor(struct cpufreq_policy *policy, char *buf)
{
if (policy->policy == CPUFREQ_POLICY_POWERSAVE)
return sprintf(buf, "powersave\n");
else if (policy->policy == CPUFREQ_POLICY_PERFORMANCE)
return sprintf(buf, "performance\n");
else if (policy->governor)
return scnprintf(buf, CPUFREQ_NAME_PLEN, "%s\n",
policy->governor->name);
return -EINVAL;
}
static ssize_t store_scaling_governor(struct cpufreq_policy *policy,
const char *buf, size_t count)
{
int ret;
char str_governor[16];
struct cpufreq_policy new_policy;
memcpy(&new_policy, policy, sizeof(*policy));
ret = sscanf(buf, "%15s", str_governor);
if (ret != 1)
return -EINVAL;
if (cpufreq_parse_governor(str_governor, &new_policy.policy,
&new_policy.governor))
return -EINVAL;
ret = cpufreq_set_policy(policy, &new_policy);
return ret ? ret : count;
}
static ssize_t show_scaling_driver(struct cpufreq_policy *policy, char *buf)
{
return scnprintf(buf, CPUFREQ_NAME_PLEN, "%s\n", cpufreq_driver->name);
}
static ssize_t show_scaling_available_governors(struct cpufreq_policy *policy,
char *buf)
{
ssize_t i = 0;
struct cpufreq_governor *t;
if (!has_target()) {
i += sprintf(buf, "performance powersave");
goto out;
}
for_each_governor(t) {
if (i >= (ssize_t) ((PAGE_SIZE / sizeof(char))
- (CPUFREQ_NAME_LEN + 2)))
goto out;
i += scnprintf(&buf[i], CPUFREQ_NAME_PLEN, "%s ", t->name);
}
out:
i += sprintf(&buf[i], "\n");
return i;
}
ssize_t cpufreq_show_cpus(const struct cpumask *mask, char *buf)
{
ssize_t i = 0;
unsigned int cpu;
for_each_cpu(cpu, mask) {
if (i)
i += scnprintf(&buf[i], (PAGE_SIZE - i - 2), " ");
i += scnprintf(&buf[i], (PAGE_SIZE - i - 2), "%u", cpu);
if (i >= (PAGE_SIZE - 5))
break;
}
i += sprintf(&buf[i], "\n");
return i;
}
static ssize_t show_related_cpus(struct cpufreq_policy *policy, char *buf)
{
return cpufreq_show_cpus(policy->related_cpus, buf);
}
static ssize_t show_affected_cpus(struct cpufreq_policy *policy, char *buf)
{
return cpufreq_show_cpus(policy->cpus, buf);
}
static ssize_t store_scaling_setspeed(struct cpufreq_policy *policy,
const char *buf, size_t count)
{
unsigned int freq = 0;
unsigned int ret;
if (!policy->governor || !policy->governor->store_setspeed)
return -EINVAL;
ret = sscanf(buf, "%u", &freq);
if (ret != 1)
return -EINVAL;
policy->governor->store_setspeed(policy, freq);
return count;
}
static ssize_t show_scaling_setspeed(struct cpufreq_policy *policy, char *buf)
{
if (!policy->governor || !policy->governor->show_setspeed)
return sprintf(buf, "<unsupported>\n");
return policy->governor->show_setspeed(policy, buf);
}
static ssize_t show_bios_limit(struct cpufreq_policy *policy, char *buf)
{
unsigned int limit;
int ret;
if (cpufreq_driver->bios_limit) {
ret = cpufreq_driver->bios_limit(policy->cpu, &limit);
if (!ret)
return sprintf(buf, "%u\n", limit);
}
return sprintf(buf, "%u\n", policy->cpuinfo.max_freq);
}
static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct cpufreq_policy *policy = to_policy(kobj);
struct freq_attr *fattr = to_attr(attr);
ssize_t ret;
down_read(&policy->rwsem);
if (fattr->show)
ret = fattr->show(policy, buf);
else
ret = -EIO;
up_read(&policy->rwsem);
return ret;
}
static ssize_t store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct cpufreq_policy *policy = to_policy(kobj);
struct freq_attr *fattr = to_attr(attr);
ssize_t ret = -EINVAL;
get_online_cpus();
if (!cpu_online(policy->cpu))
goto unlock;
down_write(&policy->rwsem);
if (unlikely(policy_is_inactive(policy))) {
ret = -EBUSY;
goto unlock_policy_rwsem;
}
if (fattr->store)
ret = fattr->store(policy, buf, count);
else
ret = -EIO;
unlock_policy_rwsem:
up_write(&policy->rwsem);
unlock:
put_online_cpus();
return ret;
}
static void cpufreq_sysfs_release(struct kobject *kobj)
{
struct cpufreq_policy *policy = to_policy(kobj);
pr_debug("last reference is dropped\n");
complete(&policy->kobj_unregister);
}
int cpufreq_get_global_kobject(void)
{
if (!cpufreq_global_kobject_usage++)
return kobject_add(cpufreq_global_kobject,
&cpu_subsys.dev_root->kobj, "%s", "cpufreq");
return 0;
}
void cpufreq_put_global_kobject(void)
{
if (!--cpufreq_global_kobject_usage)
kobject_del(cpufreq_global_kobject);
}
int cpufreq_sysfs_create_file(const struct attribute *attr)
{
int ret = cpufreq_get_global_kobject();
if (!ret) {
ret = sysfs_create_file(cpufreq_global_kobject, attr);
if (ret)
cpufreq_put_global_kobject();
}
return ret;
}
void cpufreq_sysfs_remove_file(const struct attribute *attr)
{
sysfs_remove_file(cpufreq_global_kobject, attr);
cpufreq_put_global_kobject();
}
static int add_cpu_dev_symlink(struct cpufreq_policy *policy, int cpu)
{
struct device *cpu_dev;
pr_debug("%s: Adding symlink for CPU: %u\n", __func__, cpu);
if (!policy)
return 0;
cpu_dev = get_cpu_device(cpu);
if (WARN_ON(!cpu_dev))
return 0;
return sysfs_create_link(&cpu_dev->kobj, &policy->kobj, "cpufreq");
}
static void remove_cpu_dev_symlink(struct cpufreq_policy *policy, int cpu)
{
struct device *cpu_dev;
pr_debug("%s: Removing symlink for CPU: %u\n", __func__, cpu);
cpu_dev = get_cpu_device(cpu);
if (WARN_ON(!cpu_dev))
return;
sysfs_remove_link(&cpu_dev->kobj, "cpufreq");
}
static int cpufreq_add_dev_symlink(struct cpufreq_policy *policy)
{
unsigned int j;
int ret = 0;
for_each_cpu(j, policy->real_cpus) {
if (j == policy->kobj_cpu)
continue;
ret = add_cpu_dev_symlink(policy, j);
if (ret)
break;
}
return ret;
}
static void cpufreq_remove_dev_symlink(struct cpufreq_policy *policy)
{
unsigned int j;
for_each_cpu(j, policy->real_cpus) {
if (j == policy->kobj_cpu)
continue;
remove_cpu_dev_symlink(policy, j);
}
}
static int cpufreq_add_dev_interface(struct cpufreq_policy *policy)
{
struct freq_attr **drv_attr;
int ret = 0;
drv_attr = cpufreq_driver->attr;
while (drv_attr && *drv_attr) {
ret = sysfs_create_file(&policy->kobj, &((*drv_attr)->attr));
if (ret)
return ret;
drv_attr++;
}
if (cpufreq_driver->get) {
ret = sysfs_create_file(&policy->kobj, &cpuinfo_cur_freq.attr);
if (ret)
return ret;
}
ret = sysfs_create_file(&policy->kobj, &scaling_cur_freq.attr);
if (ret)
return ret;
if (cpufreq_driver->bios_limit) {
ret = sysfs_create_file(&policy->kobj, &bios_limit.attr);
if (ret)
return ret;
}
return cpufreq_add_dev_symlink(policy);
}
static int cpufreq_init_policy(struct cpufreq_policy *policy)
{
struct cpufreq_governor *gov = NULL;
struct cpufreq_policy new_policy;
memcpy(&new_policy, policy, sizeof(*policy));
gov = find_governor(policy->last_governor);
if (gov)
pr_debug("Restoring governor %s for cpu %d\n",
policy->governor->name, policy->cpu);
else
gov = CPUFREQ_DEFAULT_GOVERNOR;
new_policy.governor = gov;
if (cpufreq_driver->setpolicy)
cpufreq_parse_governor(gov->name, &new_policy.policy, NULL);
return cpufreq_set_policy(policy, &new_policy);
}
static int cpufreq_add_policy_cpu(struct cpufreq_policy *policy, unsigned int cpu)
{
int ret = 0;
if (cpumask_test_cpu(cpu, policy->cpus))
return 0;
if (has_target()) {
ret = __cpufreq_governor(policy, CPUFREQ_GOV_STOP);
if (ret) {
pr_err("%s: Failed to stop governor\n", __func__);
return ret;
}
}
down_write(&policy->rwsem);
cpumask_set_cpu(cpu, policy->cpus);
up_write(&policy->rwsem);
if (has_target()) {
ret = __cpufreq_governor(policy, CPUFREQ_GOV_START);
if (!ret)
ret = __cpufreq_governor(policy, CPUFREQ_GOV_LIMITS);
if (ret) {
pr_err("%s: Failed to start governor\n", __func__);
return ret;
}
}
return 0;
}
static struct cpufreq_policy *cpufreq_policy_alloc(unsigned int cpu)
{
struct device *dev = get_cpu_device(cpu);
struct cpufreq_policy *policy;
int ret;
if (WARN_ON(!dev))
return NULL;
policy = kzalloc(sizeof(*policy), GFP_KERNEL);
if (!policy)
return NULL;
if (!alloc_cpumask_var(&policy->cpus, GFP_KERNEL))
goto err_free_policy;
if (!zalloc_cpumask_var(&policy->related_cpus, GFP_KERNEL))
goto err_free_cpumask;
if (!zalloc_cpumask_var(&policy->real_cpus, GFP_KERNEL))
goto err_free_rcpumask;
ret = kobject_init_and_add(&policy->kobj, &ktype_cpufreq, &dev->kobj,
"cpufreq");
if (ret) {
pr_err("%s: failed to init policy->kobj: %d\n", __func__, ret);
goto err_free_real_cpus;
}
INIT_LIST_HEAD(&policy->policy_list);
init_rwsem(&policy->rwsem);
spin_lock_init(&policy->transition_lock);
init_waitqueue_head(&policy->transition_wait);
init_completion(&policy->kobj_unregister);
INIT_WORK(&policy->update, handle_update);
policy->cpu = cpu;
policy->kobj_cpu = cpu;
return policy;
err_free_real_cpus:
free_cpumask_var(policy->real_cpus);
err_free_rcpumask:
free_cpumask_var(policy->related_cpus);
err_free_cpumask:
free_cpumask_var(policy->cpus);
err_free_policy:
kfree(policy);
return NULL;
}
static void cpufreq_policy_put_kobj(struct cpufreq_policy *policy, bool notify)
{
struct kobject *kobj;
struct completion *cmp;
if (notify)
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_REMOVE_POLICY, policy);
down_write(&policy->rwsem);
cpufreq_remove_dev_symlink(policy);
kobj = &policy->kobj;
cmp = &policy->kobj_unregister;
up_write(&policy->rwsem);
kobject_put(kobj);
pr_debug("waiting for dropping of refcount\n");
wait_for_completion(cmp);
pr_debug("wait complete\n");
}
static void cpufreq_policy_free(struct cpufreq_policy *policy, bool notify)
{
unsigned long flags;
int cpu;
write_lock_irqsave(&cpufreq_driver_lock, flags);
list_del(&policy->policy_list);
for_each_cpu(cpu, policy->related_cpus)
per_cpu(cpufreq_cpu_data, cpu) = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
cpufreq_policy_put_kobj(policy, notify);
free_cpumask_var(policy->real_cpus);
free_cpumask_var(policy->related_cpus);
free_cpumask_var(policy->cpus);
kfree(policy);
}
static int cpufreq_online(unsigned int cpu)
{
struct cpufreq_policy *policy;
bool new_policy;
unsigned long flags;
unsigned int j;
int ret;
pr_debug("%s: bringing CPU%u online\n", __func__, cpu);
policy = per_cpu(cpufreq_cpu_data, cpu);
if (policy) {
WARN_ON(!cpumask_test_cpu(cpu, policy->related_cpus));
if (!policy_is_inactive(policy))
return cpufreq_add_policy_cpu(policy, cpu);
new_policy = false;
down_write(&policy->rwsem);
policy->cpu = cpu;
policy->governor = NULL;
up_write(&policy->rwsem);
} else {
new_policy = true;
policy = cpufreq_policy_alloc(cpu);
if (!policy)
return -ENOMEM;
}
cpumask_copy(policy->cpus, cpumask_of(cpu));
ret = cpufreq_driver->init(policy);
if (ret) {
pr_debug("initialization failed\n");
goto out_free_policy;
}
down_write(&policy->rwsem);
if (new_policy) {
cpumask_or(policy->related_cpus, policy->related_cpus, policy->cpus);
cpumask_and(policy->real_cpus, policy->cpus, cpu_present_mask);
}
cpumask_and(policy->cpus, policy->cpus, cpu_online_mask);
if (new_policy) {
policy->user_policy.min = policy->min;
policy->user_policy.max = policy->max;
write_lock_irqsave(&cpufreq_driver_lock, flags);
for_each_cpu(j, policy->related_cpus)
per_cpu(cpufreq_cpu_data, j) = policy;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
}
if (cpufreq_driver->get && !cpufreq_driver->setpolicy) {
policy->cur = cpufreq_driver->get(policy->cpu);
if (!policy->cur) {
pr_err("%s: ->get() failed\n", __func__);
goto out_exit_policy;
}
}
if ((cpufreq_driver->flags & CPUFREQ_NEED_INITIAL_FREQ_CHECK)
&& has_target()) {
ret = cpufreq_frequency_table_get_index(policy, policy->cur);
if (ret == -EINVAL) {
pr_warn("%s: CPU%d: Running at unlisted freq: %u KHz\n",
__func__, policy->cpu, policy->cur);
ret = __cpufreq_driver_target(policy, policy->cur - 1,
CPUFREQ_RELATION_L);
BUG_ON(ret);
pr_warn("%s: CPU%d: Unlisted initial frequency changed to: %u KHz\n",
__func__, policy->cpu, policy->cur);
}
}
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_START, policy);
if (new_policy) {
ret = cpufreq_add_dev_interface(policy);
if (ret)
goto out_exit_policy;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_CREATE_POLICY, policy);
write_lock_irqsave(&cpufreq_driver_lock, flags);
list_add(&policy->policy_list, &cpufreq_policy_list);
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
}
ret = cpufreq_init_policy(policy);
if (ret) {
pr_err("%s: Failed to initialize policy for cpu: %d (%d)\n",
__func__, cpu, ret);
new_policy = false;
goto out_exit_policy;
}
up_write(&policy->rwsem);
kobject_uevent(&policy->kobj, KOBJ_ADD);
if (cpufreq_driver->ready)
cpufreq_driver->ready(policy);
pr_debug("initialization complete\n");
return 0;
out_exit_policy:
up_write(&policy->rwsem);
if (cpufreq_driver->exit)
cpufreq_driver->exit(policy);
out_free_policy:
cpufreq_policy_free(policy, !new_policy);
return ret;
}
static int cpufreq_add_dev(struct device *dev, struct subsys_interface *sif)
{
unsigned cpu = dev->id;
int ret;
dev_dbg(dev, "%s: adding CPU%u\n", __func__, cpu);
if (cpu_online(cpu)) {
ret = cpufreq_online(cpu);
} else {
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
ret = policy && !cpumask_test_and_set_cpu(cpu, policy->real_cpus)
? add_cpu_dev_symlink(policy, cpu) : 0;
}
return ret;
}
static void cpufreq_offline_prepare(unsigned int cpu)
{
struct cpufreq_policy *policy;
pr_debug("%s: unregistering CPU %u\n", __func__, cpu);
policy = cpufreq_cpu_get_raw(cpu);
if (!policy) {
pr_debug("%s: No cpu_data found\n", __func__);
return;
}
if (has_target()) {
int ret = __cpufreq_governor(policy, CPUFREQ_GOV_STOP);
if (ret)
pr_err("%s: Failed to stop governor\n", __func__);
}
down_write(&policy->rwsem);
cpumask_clear_cpu(cpu, policy->cpus);
if (policy_is_inactive(policy)) {
if (has_target())
strncpy(policy->last_governor, policy->governor->name,
CPUFREQ_NAME_LEN);
} else if (cpu == policy->cpu) {
policy->cpu = cpumask_any(policy->cpus);
}
up_write(&policy->rwsem);
if (!policy_is_inactive(policy)) {
if (has_target()) {
int ret = __cpufreq_governor(policy, CPUFREQ_GOV_START);
if (!ret)
ret = __cpufreq_governor(policy, CPUFREQ_GOV_LIMITS);
if (ret)
pr_err("%s: Failed to start governor\n", __func__);
}
} else if (cpufreq_driver->stop_cpu) {
cpufreq_driver->stop_cpu(policy);
}
}
static void cpufreq_offline_finish(unsigned int cpu)
{
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
if (!policy) {
pr_debug("%s: No cpu_data found\n", __func__);
return;
}
if (!policy_is_inactive(policy))
return;
if (has_target()) {
int ret = __cpufreq_governor(policy, CPUFREQ_GOV_POLICY_EXIT);
if (ret)
pr_err("%s: Failed to exit governor\n", __func__);
}
if (cpufreq_driver->exit) {
cpufreq_driver->exit(policy);
policy->freq_table = NULL;
}
}
static void cpufreq_remove_dev(struct device *dev, struct subsys_interface *sif)
{
unsigned int cpu = dev->id;
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
if (!policy)
return;
if (cpu_online(cpu)) {
cpufreq_offline_prepare(cpu);
cpufreq_offline_finish(cpu);
}
cpumask_clear_cpu(cpu, policy->real_cpus);
if (cpumask_empty(policy->real_cpus)) {
cpufreq_policy_free(policy, true);
return;
}
if (cpu != policy->kobj_cpu) {
remove_cpu_dev_symlink(policy, cpu);
} else {
unsigned int new_cpu = cpumask_first(policy->real_cpus);
struct device *new_dev = get_cpu_device(new_cpu);
dev_dbg(dev, "%s: Moving policy object to CPU%u\n", __func__, new_cpu);
sysfs_remove_link(&new_dev->kobj, "cpufreq");
policy->kobj_cpu = new_cpu;
WARN_ON(kobject_move(&policy->kobj, &new_dev->kobj));
}
}
static void handle_update(struct work_struct *work)
{
struct cpufreq_policy *policy =
container_of(work, struct cpufreq_policy, update);
unsigned int cpu = policy->cpu;
pr_debug("handle_update for cpu %u called\n", cpu);
cpufreq_update_policy(cpu);
}
static void cpufreq_out_of_sync(struct cpufreq_policy *policy,
unsigned int new_freq)
{
struct cpufreq_freqs freqs;
pr_debug("Warning: CPU frequency out of sync: cpufreq and timing core thinks of %u, is %u kHz\n",
policy->cur, new_freq);
freqs.old = policy->cur;
freqs.new = new_freq;
cpufreq_freq_transition_begin(policy, &freqs);
cpufreq_freq_transition_end(policy, &freqs, 0);
}
unsigned int cpufreq_quick_get(unsigned int cpu)
{
struct cpufreq_policy *policy;
unsigned int ret_freq = 0;
if (cpufreq_driver && cpufreq_driver->setpolicy && cpufreq_driver->get)
return cpufreq_driver->get(cpu);
policy = cpufreq_cpu_get(cpu);
if (policy) {
ret_freq = policy->cur;
cpufreq_cpu_put(policy);
}
return ret_freq;
}
unsigned int cpufreq_quick_get_max(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
unsigned int ret_freq = 0;
if (policy) {
ret_freq = policy->max;
cpufreq_cpu_put(policy);
}
return ret_freq;
}
static unsigned int __cpufreq_get(struct cpufreq_policy *policy)
{
unsigned int ret_freq = 0;
if (!cpufreq_driver->get)
return ret_freq;
ret_freq = cpufreq_driver->get(policy->cpu);
if (unlikely(policy_is_inactive(policy)))
return ret_freq;
if (ret_freq && policy->cur &&
!(cpufreq_driver->flags & CPUFREQ_CONST_LOOPS)) {
if (unlikely(ret_freq != policy->cur)) {
cpufreq_out_of_sync(policy, ret_freq);
schedule_work(&policy->update);
}
}
return ret_freq;
}
unsigned int cpufreq_get(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
unsigned int ret_freq = 0;
if (policy) {
down_read(&policy->rwsem);
ret_freq = __cpufreq_get(policy);
up_read(&policy->rwsem);
cpufreq_cpu_put(policy);
}
return ret_freq;
}
int cpufreq_generic_suspend(struct cpufreq_policy *policy)
{
int ret;
if (!policy->suspend_freq) {
pr_debug("%s: suspend_freq not defined\n", __func__);
return 0;
}
pr_debug("%s: Setting suspend-freq: %u\n", __func__,
policy->suspend_freq);
ret = __cpufreq_driver_target(policy, policy->suspend_freq,
CPUFREQ_RELATION_H);
if (ret)
pr_err("%s: unable to set suspend-freq: %u. err: %d\n",
__func__, policy->suspend_freq, ret);
return ret;
}
void cpufreq_suspend(void)
{
struct cpufreq_policy *policy;
if (!cpufreq_driver)
return;
if (!has_target())
goto suspend;
pr_debug("%s: Suspending Governors\n", __func__);
for_each_active_policy(policy) {
if (__cpufreq_governor(policy, CPUFREQ_GOV_STOP))
pr_err("%s: Failed to stop governor for policy: %p\n",
__func__, policy);
else if (cpufreq_driver->suspend
&& cpufreq_driver->suspend(policy))
pr_err("%s: Failed to suspend driver: %p\n", __func__,
policy);
}
suspend:
cpufreq_suspended = true;
}
void cpufreq_resume(void)
{
struct cpufreq_policy *policy;
if (!cpufreq_driver)
return;
cpufreq_suspended = false;
if (!has_target())
return;
pr_debug("%s: Resuming Governors\n", __func__);
for_each_active_policy(policy) {
if (cpufreq_driver->resume && cpufreq_driver->resume(policy))
pr_err("%s: Failed to resume driver: %p\n", __func__,
policy);
else if (__cpufreq_governor(policy, CPUFREQ_GOV_START)
|| __cpufreq_governor(policy, CPUFREQ_GOV_LIMITS))
pr_err("%s: Failed to start governor for policy: %p\n",
__func__, policy);
}
policy = cpufreq_cpu_get_raw(cpumask_first(cpu_online_mask));
if (WARN_ON(!policy))
return;
schedule_work(&policy->update);
}
const char *cpufreq_get_current_driver(void)
{
if (cpufreq_driver)
return cpufreq_driver->name;
return NULL;
}
void *cpufreq_get_driver_data(void)
{
if (cpufreq_driver)
return cpufreq_driver->driver_data;
return NULL;
}
int cpufreq_register_notifier(struct notifier_block *nb, unsigned int list)
{
int ret;
if (cpufreq_disabled())
return -EINVAL;
WARN_ON(!init_cpufreq_transition_notifier_list_called);
switch (list) {
case CPUFREQ_TRANSITION_NOTIFIER:
ret = srcu_notifier_chain_register(
&cpufreq_transition_notifier_list, nb);
break;
case CPUFREQ_POLICY_NOTIFIER:
ret = blocking_notifier_chain_register(
&cpufreq_policy_notifier_list, nb);
break;
default:
ret = -EINVAL;
}
return ret;
}
int cpufreq_unregister_notifier(struct notifier_block *nb, unsigned int list)
{
int ret;
if (cpufreq_disabled())
return -EINVAL;
switch (list) {
case CPUFREQ_TRANSITION_NOTIFIER:
ret = srcu_notifier_chain_unregister(
&cpufreq_transition_notifier_list, nb);
break;
case CPUFREQ_POLICY_NOTIFIER:
ret = blocking_notifier_chain_unregister(
&cpufreq_policy_notifier_list, nb);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int __target_intermediate(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, int index)
{
int ret;
freqs->new = cpufreq_driver->get_intermediate(policy, index);
if (!freqs->new)
return 0;
pr_debug("%s: cpu: %d, switching to intermediate freq: oldfreq: %u, intermediate freq: %u\n",
__func__, policy->cpu, freqs->old, freqs->new);
cpufreq_freq_transition_begin(policy, freqs);
ret = cpufreq_driver->target_intermediate(policy, index);
cpufreq_freq_transition_end(policy, freqs, ret);
if (ret)
pr_err("%s: Failed to change to intermediate frequency: %d\n",
__func__, ret);
return ret;
}
static int __target_index(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *freq_table, int index)
{
struct cpufreq_freqs freqs = {.old = policy->cur, .flags = 0};
unsigned int intermediate_freq = 0;
int retval = -EINVAL;
bool notify;
notify = !(cpufreq_driver->flags & CPUFREQ_ASYNC_NOTIFICATION);
if (notify) {
if (cpufreq_driver->get_intermediate) {
retval = __target_intermediate(policy, &freqs, index);
if (retval)
return retval;
intermediate_freq = freqs.new;
if (intermediate_freq)
freqs.old = freqs.new;
}
freqs.new = freq_table[index].frequency;
pr_debug("%s: cpu: %d, oldfreq: %u, new freq: %u\n",
__func__, policy->cpu, freqs.old, freqs.new);
cpufreq_freq_transition_begin(policy, &freqs);
}
retval = cpufreq_driver->target_index(policy, index);
if (retval)
pr_err("%s: Failed to change cpu frequency: %d\n", __func__,
retval);
if (notify) {
cpufreq_freq_transition_end(policy, &freqs, retval);
if (unlikely(retval && intermediate_freq)) {
freqs.old = intermediate_freq;
freqs.new = policy->restore_freq;
cpufreq_freq_transition_begin(policy, &freqs);
cpufreq_freq_transition_end(policy, &freqs, 0);
}
}
return retval;
}
int __cpufreq_driver_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int old_target_freq = target_freq;
int retval = -EINVAL;
if (cpufreq_disabled())
return -ENODEV;
if (target_freq > policy->max)
target_freq = policy->max;
if (target_freq < policy->min)
target_freq = policy->min;
pr_debug("target for CPU %u: %u kHz, relation %u, requested %u kHz\n",
policy->cpu, target_freq, relation, old_target_freq);
if (target_freq == policy->cur)
return 0;
policy->restore_freq = policy->cur;
if (cpufreq_driver->target)
retval = cpufreq_driver->target(policy, target_freq, relation);
else if (cpufreq_driver->target_index) {
struct cpufreq_frequency_table *freq_table;
int index;
freq_table = cpufreq_frequency_get_table(policy->cpu);
if (unlikely(!freq_table)) {
pr_err("%s: Unable to find freq_table\n", __func__);
goto out;
}
retval = cpufreq_frequency_table_target(policy, freq_table,
target_freq, relation, &index);
if (unlikely(retval)) {
pr_err("%s: Unable to find matching freq\n", __func__);
goto out;
}
if (freq_table[index].frequency == policy->cur) {
retval = 0;
goto out;
}
retval = __target_index(policy, freq_table, index);
}
out:
return retval;
}
int cpufreq_driver_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
int ret = -EINVAL;
down_write(&policy->rwsem);
ret = __cpufreq_driver_target(policy, target_freq, relation);
up_write(&policy->rwsem);
return ret;
}
static int __cpufreq_governor(struct cpufreq_policy *policy,
unsigned int event)
{
int ret;
#ifdef CONFIG_CPU_FREQ_GOV_PERFORMANCE
struct cpufreq_governor *gov = &cpufreq_gov_performance;
#else
struct cpufreq_governor *gov = NULL;
#endif
if (cpufreq_suspended)
return 0;
if (!policy->governor)
return -EINVAL;
if (policy->governor->max_transition_latency &&
policy->cpuinfo.transition_latency >
policy->governor->max_transition_latency) {
if (!gov)
return -EINVAL;
else {
pr_warn("%s governor failed, too long transition latency of HW, fallback to %s governor\n",
policy->governor->name, gov->name);
policy->governor = gov;
}
}
if (event == CPUFREQ_GOV_POLICY_INIT)
if (!try_module_get(policy->governor->owner))
return -EINVAL;
pr_debug("%s: for CPU %u, event %u\n", __func__, policy->cpu, event);
mutex_lock(&cpufreq_governor_lock);
if ((policy->governor_enabled && event == CPUFREQ_GOV_START)
|| (!policy->governor_enabled
&& (event == CPUFREQ_GOV_LIMITS || event == CPUFREQ_GOV_STOP))) {
mutex_unlock(&cpufreq_governor_lock);
return -EBUSY;
}
if (event == CPUFREQ_GOV_STOP)
policy->governor_enabled = false;
else if (event == CPUFREQ_GOV_START)
policy->governor_enabled = true;
mutex_unlock(&cpufreq_governor_lock);
ret = policy->governor->governor(policy, event);
if (!ret) {
if (event == CPUFREQ_GOV_POLICY_INIT)
policy->governor->initialized++;
else if (event == CPUFREQ_GOV_POLICY_EXIT)
policy->governor->initialized--;
} else {
mutex_lock(&cpufreq_governor_lock);
if (event == CPUFREQ_GOV_STOP)
policy->governor_enabled = true;
else if (event == CPUFREQ_GOV_START)
policy->governor_enabled = false;
mutex_unlock(&cpufreq_governor_lock);
}
if (((event == CPUFREQ_GOV_POLICY_INIT) && ret) ||
((event == CPUFREQ_GOV_POLICY_EXIT) && !ret))
module_put(policy->governor->owner);
return ret;
}
int cpufreq_register_governor(struct cpufreq_governor *governor)
{
int err;
if (!governor)
return -EINVAL;
if (cpufreq_disabled())
return -ENODEV;
mutex_lock(&cpufreq_governor_mutex);
governor->initialized = 0;
err = -EBUSY;
if (!find_governor(governor->name)) {
err = 0;
list_add(&governor->governor_list, &cpufreq_governor_list);
}
mutex_unlock(&cpufreq_governor_mutex);
return err;
}
void cpufreq_unregister_governor(struct cpufreq_governor *governor)
{
struct cpufreq_policy *policy;
unsigned long flags;
if (!governor)
return;
if (cpufreq_disabled())
return;
read_lock_irqsave(&cpufreq_driver_lock, flags);
for_each_inactive_policy(policy) {
if (!strcmp(policy->last_governor, governor->name)) {
policy->governor = NULL;
strcpy(policy->last_governor, "\0");
}
}
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
mutex_lock(&cpufreq_governor_mutex);
list_del(&governor->governor_list);
mutex_unlock(&cpufreq_governor_mutex);
return;
}
int cpufreq_get_policy(struct cpufreq_policy *policy, unsigned int cpu)
{
struct cpufreq_policy *cpu_policy;
if (!policy)
return -EINVAL;
cpu_policy = cpufreq_cpu_get(cpu);
if (!cpu_policy)
return -EINVAL;
memcpy(policy, cpu_policy, sizeof(*policy));
cpufreq_cpu_put(cpu_policy);
return 0;
}
static int cpufreq_set_policy(struct cpufreq_policy *policy,
struct cpufreq_policy *new_policy)
{
struct cpufreq_governor *old_gov;
int ret;
pr_debug("setting new policy for CPU %u: %u - %u kHz\n",
new_policy->cpu, new_policy->min, new_policy->max);
memcpy(&new_policy->cpuinfo, &policy->cpuinfo, sizeof(policy->cpuinfo));
if (new_policy->min > new_policy->max)
return -EINVAL;
ret = cpufreq_driver->verify(new_policy);
if (ret)
return ret;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_ADJUST, new_policy);
ret = cpufreq_driver->verify(new_policy);
if (ret)
return ret;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_NOTIFY, new_policy);
policy->min = new_policy->min;
policy->max = new_policy->max;
pr_debug("new min and max freqs are %u - %u kHz\n",
policy->min, policy->max);
if (cpufreq_driver->setpolicy) {
policy->policy = new_policy->policy;
pr_debug("setting range\n");
return cpufreq_driver->setpolicy(new_policy);
}
if (new_policy->governor == policy->governor)
goto out;
pr_debug("governor switch\n");
old_gov = policy->governor;
if (old_gov) {
ret = __cpufreq_governor(policy, CPUFREQ_GOV_STOP);
if (ret) {
pr_debug("%s: Failed to Stop Governor: %s (%d)\n",
__func__, old_gov->name, ret);
return ret;
}
up_write(&policy->rwsem);
ret = __cpufreq_governor(policy, CPUFREQ_GOV_POLICY_EXIT);
down_write(&policy->rwsem);
if (ret) {
pr_err("%s: Failed to Exit Governor: %s (%d)\n",
__func__, old_gov->name, ret);
return ret;
}
}
policy->governor = new_policy->governor;
ret = __cpufreq_governor(policy, CPUFREQ_GOV_POLICY_INIT);
if (!ret) {
ret = __cpufreq_governor(policy, CPUFREQ_GOV_START);
if (!ret)
goto out;
up_write(&policy->rwsem);
__cpufreq_governor(policy, CPUFREQ_GOV_POLICY_EXIT);
down_write(&policy->rwsem);
}
pr_debug("starting governor %s failed\n", policy->governor->name);
if (old_gov) {
policy->governor = old_gov;
if (__cpufreq_governor(policy, CPUFREQ_GOV_POLICY_INIT))
policy->governor = NULL;
else
__cpufreq_governor(policy, CPUFREQ_GOV_START);
}
return ret;
out:
pr_debug("governor: change or update limits\n");
return __cpufreq_governor(policy, CPUFREQ_GOV_LIMITS);
}
int cpufreq_update_policy(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
struct cpufreq_policy new_policy;
int ret;
if (!policy)
return -ENODEV;
down_write(&policy->rwsem);
pr_debug("updating policy for CPU %u\n", cpu);
memcpy(&new_policy, policy, sizeof(*policy));
new_policy.min = policy->user_policy.min;
new_policy.max = policy->user_policy.max;
if (cpufreq_driver->get && !cpufreq_driver->setpolicy) {
new_policy.cur = cpufreq_driver->get(cpu);
if (WARN_ON(!new_policy.cur)) {
ret = -EIO;
goto unlock;
}
if (!policy->cur) {
pr_debug("Driver did not initialize current freq\n");
policy->cur = new_policy.cur;
} else {
if (policy->cur != new_policy.cur && has_target())
cpufreq_out_of_sync(policy, new_policy.cur);
}
}
ret = cpufreq_set_policy(policy, &new_policy);
unlock:
up_write(&policy->rwsem);
cpufreq_cpu_put(policy);
return ret;
}
static int cpufreq_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
cpufreq_online(cpu);
break;
case CPU_DOWN_PREPARE:
cpufreq_offline_prepare(cpu);
break;
case CPU_POST_DEAD:
cpufreq_offline_finish(cpu);
break;
case CPU_DOWN_FAILED:
cpufreq_online(cpu);
break;
}
return NOTIFY_OK;
}
static int cpufreq_boost_set_sw(int state)
{
struct cpufreq_frequency_table *freq_table;
struct cpufreq_policy *policy;
int ret = -EINVAL;
for_each_active_policy(policy) {
freq_table = cpufreq_frequency_get_table(policy->cpu);
if (freq_table) {
ret = cpufreq_frequency_table_cpuinfo(policy,
freq_table);
if (ret) {
pr_err("%s: Policy frequency update failed\n",
__func__);
break;
}
policy->user_policy.max = policy->max;
__cpufreq_governor(policy, CPUFREQ_GOV_LIMITS);
}
}
return ret;
}
int cpufreq_boost_trigger_state(int state)
{
unsigned long flags;
int ret = 0;
if (cpufreq_driver->boost_enabled == state)
return 0;
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver->boost_enabled = state;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
ret = cpufreq_driver->set_boost(state);
if (ret) {
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver->boost_enabled = !state;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
pr_err("%s: Cannot %s BOOST\n",
__func__, state ? "enable" : "disable");
}
return ret;
}
int cpufreq_boost_supported(void)
{
if (likely(cpufreq_driver))
return cpufreq_driver->boost_supported;
return 0;
}
static int create_boost_sysfs_file(void)
{
int ret;
if (!cpufreq_boost_supported())
return 0;
if (!cpufreq_driver->set_boost)
cpufreq_driver->set_boost = cpufreq_boost_set_sw;
ret = cpufreq_sysfs_create_file(&boost.attr);
if (ret)
pr_err("%s: cannot register global BOOST sysfs file\n",
__func__);
return ret;
}
static void remove_boost_sysfs_file(void)
{
if (cpufreq_boost_supported())
cpufreq_sysfs_remove_file(&boost.attr);
}
int cpufreq_enable_boost_support(void)
{
if (!cpufreq_driver)
return -EINVAL;
if (cpufreq_boost_supported())
return 0;
cpufreq_driver->boost_supported = true;
return create_boost_sysfs_file();
}
int cpufreq_boost_enabled(void)
{
return cpufreq_driver->boost_enabled;
}
int cpufreq_register_driver(struct cpufreq_driver *driver_data)
{
unsigned long flags;
int ret;
if (cpufreq_disabled())
return -ENODEV;
if (!driver_data || !driver_data->verify || !driver_data->init ||
!(driver_data->setpolicy || driver_data->target_index ||
driver_data->target) ||
(driver_data->setpolicy && (driver_data->target_index ||
driver_data->target)) ||
(!!driver_data->get_intermediate != !!driver_data->target_intermediate))
return -EINVAL;
pr_debug("trying to register driver %s\n", driver_data->name);
get_online_cpus();
write_lock_irqsave(&cpufreq_driver_lock, flags);
if (cpufreq_driver) {
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
ret = -EEXIST;
goto out;
}
cpufreq_driver = driver_data;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
if (driver_data->setpolicy)
driver_data->flags |= CPUFREQ_CONST_LOOPS;
ret = create_boost_sysfs_file();
if (ret)
goto err_null_driver;
ret = subsys_interface_register(&cpufreq_interface);
if (ret)
goto err_boost_unreg;
if (!(cpufreq_driver->flags & CPUFREQ_STICKY) &&
list_empty(&cpufreq_policy_list)) {
pr_debug("%s: No CPU initialized for driver %s\n", __func__,
driver_data->name);
goto err_if_unreg;
}
register_hotcpu_notifier(&cpufreq_cpu_notifier);
pr_debug("driver %s up and running\n", driver_data->name);
out:
put_online_cpus();
return ret;
err_if_unreg:
subsys_interface_unregister(&cpufreq_interface);
err_boost_unreg:
remove_boost_sysfs_file();
err_null_driver:
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
goto out;
}
int cpufreq_unregister_driver(struct cpufreq_driver *driver)
{
unsigned long flags;
if (!cpufreq_driver || (driver != cpufreq_driver))
return -EINVAL;
pr_debug("unregistering driver %s\n", driver->name);
get_online_cpus();
subsys_interface_unregister(&cpufreq_interface);
remove_boost_sysfs_file();
unregister_hotcpu_notifier(&cpufreq_cpu_notifier);
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
put_online_cpus();
return 0;
}
static int __init cpufreq_core_init(void)
{
if (cpufreq_disabled())
return -ENODEV;
cpufreq_global_kobject = kobject_create();
BUG_ON(!cpufreq_global_kobject);
register_syscore_ops(&cpufreq_syscore_ops);
return 0;
}
