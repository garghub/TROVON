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
return cpufreq_driver->have_governor_per_policy;
}
struct kobject *get_governor_parent_kobj(struct cpufreq_policy *policy)
{
if (have_governor_per_policy())
return &policy->kobj;
else
return cpufreq_global_kobject;
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
static struct cpufreq_policy *__cpufreq_cpu_get(unsigned int cpu, bool sysfs)
{
struct cpufreq_policy *data;
unsigned long flags;
if (cpu >= nr_cpu_ids)
goto err_out;
read_lock_irqsave(&cpufreq_driver_lock, flags);
if (!cpufreq_driver)
goto err_out_unlock;
if (!try_module_get(cpufreq_driver->owner))
goto err_out_unlock;
data = per_cpu(cpufreq_cpu_data, cpu);
if (!data)
goto err_out_put_module;
if (!sysfs && !kobject_get(&data->kobj))
goto err_out_put_module;
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
return data;
err_out_put_module:
module_put(cpufreq_driver->owner);
err_out_unlock:
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
err_out:
return NULL;
}
struct cpufreq_policy *cpufreq_cpu_get(unsigned int cpu)
{
if (cpufreq_disabled())
return NULL;
return __cpufreq_cpu_get(cpu, false);
}
static struct cpufreq_policy *cpufreq_cpu_get_sysfs(unsigned int cpu)
{
return __cpufreq_cpu_get(cpu, true);
}
static void __cpufreq_cpu_put(struct cpufreq_policy *data, bool sysfs)
{
if (!sysfs)
kobject_put(&data->kobj);
module_put(cpufreq_driver->owner);
}
void cpufreq_cpu_put(struct cpufreq_policy *data)
{
if (cpufreq_disabled())
return;
__cpufreq_cpu_put(data, false);
}
static void cpufreq_cpu_put_sysfs(struct cpufreq_policy *data)
{
__cpufreq_cpu_put(data, true);
}
static void adjust_jiffies(unsigned long val, struct cpufreq_freqs *ci)
{
if (ci->flags & CPUFREQ_CONST_LOOPS)
return;
if (!l_p_j_ref_freq) {
l_p_j_ref = loops_per_jiffy;
l_p_j_ref_freq = ci->old;
pr_debug("saving %lu as reference value for loops_per_jiffy; "
"freq is %u kHz\n", l_p_j_ref, l_p_j_ref_freq);
}
if ((val == CPUFREQ_POSTCHANGE && ci->old != ci->new) ||
(val == CPUFREQ_RESUMECHANGE || val == CPUFREQ_SUSPENDCHANGE)) {
loops_per_jiffy = cpufreq_scale(l_p_j_ref, l_p_j_ref_freq,
ci->new);
pr_debug("scaling loops_per_jiffy to %lu "
"for frequency %u kHz\n", loops_per_jiffy, ci->new);
}
}
static inline void adjust_jiffies(unsigned long val, struct cpufreq_freqs *ci)
{
return;
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
if (WARN(policy->transition_ongoing ==
cpumask_weight(policy->cpus),
"In middle of another frequency transition\n"))
return;
policy->transition_ongoing++;
if (!(cpufreq_driver->flags & CPUFREQ_CONST_LOOPS)) {
if ((policy) && (policy->cpu == freqs->cpu) &&
(policy->cur) && (policy->cur != freqs->old)) {
pr_debug("Warning: CPU frequency is"
" %u, cpufreq assumed %u kHz.\n",
freqs->old, policy->cur);
freqs->old = policy->cur;
}
}
srcu_notifier_call_chain(&cpufreq_transition_notifier_list,
CPUFREQ_PRECHANGE, freqs);
adjust_jiffies(CPUFREQ_PRECHANGE, freqs);
break;
case CPUFREQ_POSTCHANGE:
if (WARN(!policy->transition_ongoing,
"No frequency transition in progress\n"))
return;
policy->transition_ongoing--;
adjust_jiffies(CPUFREQ_POSTCHANGE, freqs);
pr_debug("FREQ: %lu - CPU: %lu", (unsigned long)freqs->new,
(unsigned long)freqs->cpu);
trace_cpu_frequency(freqs->new, freqs->cpu);
srcu_notifier_call_chain(&cpufreq_transition_notifier_list,
CPUFREQ_POSTCHANGE, freqs);
if (likely(policy) && likely(policy->cpu == freqs->cpu))
policy->cur = freqs->new;
break;
}
}
void cpufreq_notify_transition(struct cpufreq_policy *policy,
struct cpufreq_freqs *freqs, unsigned int state)
{
for_each_cpu(freqs->cpu, policy->cpus)
__cpufreq_notify_transition(policy, freqs, state);
}
static struct cpufreq_governor *__find_governor(const char *str_governor)
{
struct cpufreq_governor *t;
list_for_each_entry(t, &cpufreq_governor_list, governor_list)
if (!strnicmp(str_governor, t->name, CPUFREQ_NAME_LEN))
return t;
return NULL;
}
static int cpufreq_parse_governor(char *str_governor, unsigned int *policy,
struct cpufreq_governor **governor)
{
int err = -EINVAL;
if (!cpufreq_driver)
goto out;
if (cpufreq_driver->setpolicy) {
if (!strnicmp(str_governor, "performance", CPUFREQ_NAME_LEN)) {
*policy = CPUFREQ_POLICY_PERFORMANCE;
err = 0;
} else if (!strnicmp(str_governor, "powersave",
CPUFREQ_NAME_LEN)) {
*policy = CPUFREQ_POLICY_POWERSAVE;
err = 0;
}
} else if (cpufreq_driver->target) {
struct cpufreq_governor *t;
mutex_lock(&cpufreq_governor_mutex);
t = __find_governor(str_governor);
if (t == NULL) {
int ret;
mutex_unlock(&cpufreq_governor_mutex);
ret = request_module("cpufreq_%s", str_governor);
mutex_lock(&cpufreq_governor_mutex);
if (ret == 0)
t = __find_governor(str_governor);
}
if (t != NULL) {
*governor = t;
err = 0;
}
mutex_unlock(&cpufreq_governor_mutex);
}
out:
return err;
}
static ssize_t show_cpuinfo_cur_freq(struct cpufreq_policy *policy,
char *buf)
{
unsigned int cur_freq = __cpufreq_get(policy->cpu);
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
unsigned int ret;
char str_governor[16];
struct cpufreq_policy new_policy;
ret = cpufreq_get_policy(&new_policy, policy->cpu);
if (ret)
return ret;
ret = sscanf(buf, "%15s", str_governor);
if (ret != 1)
return -EINVAL;
if (cpufreq_parse_governor(str_governor, &new_policy.policy,
&new_policy.governor))
return -EINVAL;
ret = __cpufreq_set_policy(policy, &new_policy);
policy->user_policy.policy = policy->policy;
policy->user_policy.governor = policy->governor;
if (ret)
return ret;
else
return count;
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
if (!cpufreq_driver->target) {
i += sprintf(buf, "performance powersave");
goto out;
}
list_for_each_entry(t, &cpufreq_governor_list, governor_list) {
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
ssize_t ret = -EINVAL;
policy = cpufreq_cpu_get_sysfs(policy->cpu);
if (!policy)
goto no_policy;
if (lock_policy_rwsem_read(policy->cpu) < 0)
goto fail;
if (fattr->show)
ret = fattr->show(policy, buf);
else
ret = -EIO;
unlock_policy_rwsem_read(policy->cpu);
fail:
cpufreq_cpu_put_sysfs(policy);
no_policy:
return ret;
}
static ssize_t store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct cpufreq_policy *policy = to_policy(kobj);
struct freq_attr *fattr = to_attr(attr);
ssize_t ret = -EINVAL;
policy = cpufreq_cpu_get_sysfs(policy->cpu);
if (!policy)
goto no_policy;
if (lock_policy_rwsem_write(policy->cpu) < 0)
goto fail;
if (fattr->store)
ret = fattr->store(policy, buf, count);
else
ret = -EIO;
unlock_policy_rwsem_write(policy->cpu);
fail:
cpufreq_cpu_put_sysfs(policy);
no_policy:
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
static int cpufreq_add_dev_symlink(unsigned int cpu,
struct cpufreq_policy *policy)
{
unsigned int j;
int ret = 0;
for_each_cpu(j, policy->cpus) {
struct cpufreq_policy *managed_policy;
struct device *cpu_dev;
if (j == cpu)
continue;
pr_debug("CPU %u already managed, adding link\n", j);
managed_policy = cpufreq_cpu_get(cpu);
cpu_dev = get_cpu_device(j);
ret = sysfs_create_link(&cpu_dev->kobj, &policy->kobj,
"cpufreq");
if (ret) {
cpufreq_cpu_put(managed_policy);
return ret;
}
}
return ret;
}
static int cpufreq_add_dev_interface(unsigned int cpu,
struct cpufreq_policy *policy,
struct device *dev)
{
struct cpufreq_policy new_policy;
struct freq_attr **drv_attr;
unsigned long flags;
int ret = 0;
unsigned int j;
ret = kobject_init_and_add(&policy->kobj, &ktype_cpufreq,
&dev->kobj, "cpufreq");
if (ret)
return ret;
drv_attr = cpufreq_driver->attr;
while ((drv_attr) && (*drv_attr)) {
ret = sysfs_create_file(&policy->kobj, &((*drv_attr)->attr));
if (ret)
goto err_out_kobj_put;
drv_attr++;
}
if (cpufreq_driver->get) {
ret = sysfs_create_file(&policy->kobj, &cpuinfo_cur_freq.attr);
if (ret)
goto err_out_kobj_put;
}
if (cpufreq_driver->target) {
ret = sysfs_create_file(&policy->kobj, &scaling_cur_freq.attr);
if (ret)
goto err_out_kobj_put;
}
if (cpufreq_driver->bios_limit) {
ret = sysfs_create_file(&policy->kobj, &bios_limit.attr);
if (ret)
goto err_out_kobj_put;
}
write_lock_irqsave(&cpufreq_driver_lock, flags);
for_each_cpu(j, policy->cpus) {
per_cpu(cpufreq_cpu_data, j) = policy;
per_cpu(cpufreq_policy_cpu, j) = policy->cpu;
}
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
ret = cpufreq_add_dev_symlink(cpu, policy);
if (ret)
goto err_out_kobj_put;
memcpy(&new_policy, policy, sizeof(struct cpufreq_policy));
policy->governor = NULL;
ret = __cpufreq_set_policy(policy, &new_policy);
policy->user_policy.policy = policy->policy;
policy->user_policy.governor = policy->governor;
if (ret) {
pr_debug("setting policy failed\n");
if (cpufreq_driver->exit)
cpufreq_driver->exit(policy);
}
return ret;
err_out_kobj_put:
kobject_put(&policy->kobj);
wait_for_completion(&policy->kobj_unregister);
return ret;
}
static int cpufreq_add_policy_cpu(unsigned int cpu, unsigned int sibling,
struct device *dev)
{
struct cpufreq_policy *policy;
int ret = 0, has_target = !!cpufreq_driver->target;
unsigned long flags;
policy = cpufreq_cpu_get(sibling);
WARN_ON(!policy);
if (has_target)
__cpufreq_governor(policy, CPUFREQ_GOV_STOP);
lock_policy_rwsem_write(sibling);
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpumask_set_cpu(cpu, policy->cpus);
per_cpu(cpufreq_policy_cpu, cpu) = policy->cpu;
per_cpu(cpufreq_cpu_data, cpu) = policy;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
unlock_policy_rwsem_write(sibling);
if (has_target) {
__cpufreq_governor(policy, CPUFREQ_GOV_START);
__cpufreq_governor(policy, CPUFREQ_GOV_LIMITS);
}
ret = sysfs_create_link(&dev->kobj, &policy->kobj, "cpufreq");
if (ret) {
cpufreq_cpu_put(policy);
return ret;
}
return 0;
}
static int cpufreq_add_dev(struct device *dev, struct subsys_interface *sif)
{
unsigned int j, cpu = dev->id;
int ret = -ENOMEM;
struct cpufreq_policy *policy;
unsigned long flags;
#ifdef CONFIG_HOTPLUG_CPU
struct cpufreq_governor *gov;
int sibling;
#endif
if (cpu_is_offline(cpu))
return 0;
pr_debug("adding CPU %u\n", cpu);
#ifdef CONFIG_SMP
policy = cpufreq_cpu_get(cpu);
if (unlikely(policy)) {
cpufreq_cpu_put(policy);
return 0;
}
#ifdef CONFIG_HOTPLUG_CPU
read_lock_irqsave(&cpufreq_driver_lock, flags);
for_each_online_cpu(sibling) {
struct cpufreq_policy *cp = per_cpu(cpufreq_cpu_data, sibling);
if (cp && cpumask_test_cpu(cpu, cp->related_cpus)) {
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
return cpufreq_add_policy_cpu(cpu, sibling, dev);
}
}
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
#endif
#endif
if (!try_module_get(cpufreq_driver->owner)) {
ret = -EINVAL;
goto module_out;
}
policy = kzalloc(sizeof(struct cpufreq_policy), GFP_KERNEL);
if (!policy)
goto nomem_out;
if (!alloc_cpumask_var(&policy->cpus, GFP_KERNEL))
goto err_free_policy;
if (!zalloc_cpumask_var(&policy->related_cpus, GFP_KERNEL))
goto err_free_cpumask;
policy->cpu = cpu;
policy->governor = CPUFREQ_DEFAULT_GOVERNOR;
cpumask_copy(policy->cpus, cpumask_of(cpu));
per_cpu(cpufreq_policy_cpu, cpu) = cpu;
init_completion(&policy->kobj_unregister);
INIT_WORK(&policy->update, handle_update);
ret = cpufreq_driver->init(policy);
if (ret) {
pr_debug("initialization failed\n");
goto err_set_policy_cpu;
}
cpumask_or(policy->related_cpus, policy->related_cpus, policy->cpus);
cpumask_and(policy->cpus, policy->cpus, cpu_online_mask);
policy->user_policy.min = policy->min;
policy->user_policy.max = policy->max;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_START, policy);
#ifdef CONFIG_HOTPLUG_CPU
gov = __find_governor(per_cpu(cpufreq_cpu_governor, cpu));
if (gov) {
policy->governor = gov;
pr_debug("Restoring governor %s for cpu %d\n",
policy->governor->name, cpu);
}
#endif
ret = cpufreq_add_dev_interface(cpu, policy, dev);
if (ret)
goto err_out_unregister;
kobject_uevent(&policy->kobj, KOBJ_ADD);
module_put(cpufreq_driver->owner);
pr_debug("initialization complete\n");
return 0;
err_out_unregister:
write_lock_irqsave(&cpufreq_driver_lock, flags);
for_each_cpu(j, policy->cpus)
per_cpu(cpufreq_cpu_data, j) = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
kobject_put(&policy->kobj);
wait_for_completion(&policy->kobj_unregister);
err_set_policy_cpu:
per_cpu(cpufreq_policy_cpu, cpu) = -1;
free_cpumask_var(policy->related_cpus);
err_free_cpumask:
free_cpumask_var(policy->cpus);
err_free_policy:
kfree(policy);
nomem_out:
module_put(cpufreq_driver->owner);
module_out:
return ret;
}
static void update_policy_cpu(struct cpufreq_policy *policy, unsigned int cpu)
{
int j;
policy->last_cpu = policy->cpu;
policy->cpu = cpu;
for_each_cpu(j, policy->cpus)
per_cpu(cpufreq_policy_cpu, j) = cpu;
#ifdef CONFIG_CPU_FREQ_TABLE
cpufreq_frequency_table_update_policy_cpu(policy);
#endif
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_UPDATE_POLICY_CPU, policy);
}
static int __cpufreq_remove_dev(struct device *dev,
struct subsys_interface *sif)
{
unsigned int cpu = dev->id, ret, cpus;
unsigned long flags;
struct cpufreq_policy *data;
struct kobject *kobj;
struct completion *cmp;
struct device *cpu_dev;
pr_debug("%s: unregistering CPU %u\n", __func__, cpu);
write_lock_irqsave(&cpufreq_driver_lock, flags);
data = per_cpu(cpufreq_cpu_data, cpu);
per_cpu(cpufreq_cpu_data, cpu) = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
if (!data) {
pr_debug("%s: No cpu_data found\n", __func__);
return -EINVAL;
}
if (cpufreq_driver->target)
__cpufreq_governor(data, CPUFREQ_GOV_STOP);
#ifdef CONFIG_HOTPLUG_CPU
if (!cpufreq_driver->setpolicy)
strncpy(per_cpu(cpufreq_cpu_governor, cpu),
data->governor->name, CPUFREQ_NAME_LEN);
#endif
WARN_ON(lock_policy_rwsem_write(cpu));
cpus = cpumask_weight(data->cpus);
if (cpus > 1)
cpumask_clear_cpu(cpu, data->cpus);
unlock_policy_rwsem_write(cpu);
if (cpu != data->cpu) {
sysfs_remove_link(&dev->kobj, "cpufreq");
} else if (cpus > 1) {
cpu_dev = get_cpu_device(cpumask_first(data->cpus));
sysfs_remove_link(&cpu_dev->kobj, "cpufreq");
ret = kobject_move(&data->kobj, &cpu_dev->kobj);
if (ret) {
pr_err("%s: Failed to move kobj: %d", __func__, ret);
WARN_ON(lock_policy_rwsem_write(cpu));
cpumask_set_cpu(cpu, data->cpus);
write_lock_irqsave(&cpufreq_driver_lock, flags);
per_cpu(cpufreq_cpu_data, cpu) = data;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
unlock_policy_rwsem_write(cpu);
ret = sysfs_create_link(&cpu_dev->kobj, &data->kobj,
"cpufreq");
return -EINVAL;
}
WARN_ON(lock_policy_rwsem_write(cpu));
update_policy_cpu(data, cpu_dev->id);
unlock_policy_rwsem_write(cpu);
pr_debug("%s: policy Kobject moved to cpu: %d from: %d\n",
__func__, cpu_dev->id, cpu);
}
if (cpus == 1) {
if (cpufreq_driver->target)
__cpufreq_governor(data, CPUFREQ_GOV_POLICY_EXIT);
lock_policy_rwsem_read(cpu);
kobj = &data->kobj;
cmp = &data->kobj_unregister;
unlock_policy_rwsem_read(cpu);
kobject_put(kobj);
pr_debug("waiting for dropping of refcount\n");
wait_for_completion(cmp);
pr_debug("wait complete\n");
if (cpufreq_driver->exit)
cpufreq_driver->exit(data);
free_cpumask_var(data->related_cpus);
free_cpumask_var(data->cpus);
kfree(data);
} else {
pr_debug("%s: removing link, cpu: %d\n", __func__, cpu);
cpufreq_cpu_put(data);
if (cpufreq_driver->target) {
__cpufreq_governor(data, CPUFREQ_GOV_START);
__cpufreq_governor(data, CPUFREQ_GOV_LIMITS);
}
}
per_cpu(cpufreq_policy_cpu, cpu) = -1;
return 0;
}
static int cpufreq_remove_dev(struct device *dev, struct subsys_interface *sif)
{
unsigned int cpu = dev->id;
int retval;
if (cpu_is_offline(cpu))
return 0;
retval = __cpufreq_remove_dev(dev, sif);
return retval;
}
static void handle_update(struct work_struct *work)
{
struct cpufreq_policy *policy =
container_of(work, struct cpufreq_policy, update);
unsigned int cpu = policy->cpu;
pr_debug("handle_update for cpu %u called\n", cpu);
cpufreq_update_policy(cpu);
}
static void cpufreq_out_of_sync(unsigned int cpu, unsigned int old_freq,
unsigned int new_freq)
{
struct cpufreq_policy *policy;
struct cpufreq_freqs freqs;
unsigned long flags;
pr_debug("Warning: CPU frequency out of sync: cpufreq and timing "
"core thinks of %u, is %u kHz.\n", old_freq, new_freq);
freqs.old = old_freq;
freqs.new = new_freq;
read_lock_irqsave(&cpufreq_driver_lock, flags);
policy = per_cpu(cpufreq_cpu_data, cpu);
read_unlock_irqrestore(&cpufreq_driver_lock, flags);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
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
static unsigned int __cpufreq_get(unsigned int cpu)
{
struct cpufreq_policy *policy = per_cpu(cpufreq_cpu_data, cpu);
unsigned int ret_freq = 0;
if (!cpufreq_driver->get)
return ret_freq;
ret_freq = cpufreq_driver->get(cpu);
if (ret_freq && policy->cur &&
!(cpufreq_driver->flags & CPUFREQ_CONST_LOOPS)) {
if (unlikely(ret_freq != policy->cur)) {
cpufreq_out_of_sync(cpu, policy->cur, ret_freq);
schedule_work(&policy->update);
}
}
return ret_freq;
}
unsigned int cpufreq_get(unsigned int cpu)
{
unsigned int ret_freq = 0;
struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
if (!policy)
goto out;
if (unlikely(lock_policy_rwsem_read(cpu)))
goto out_policy;
ret_freq = __cpufreq_get(cpu);
unlock_policy_rwsem_read(cpu);
out_policy:
cpufreq_cpu_put(policy);
out:
return ret_freq;
}
static int cpufreq_bp_suspend(void)
{
int ret = 0;
int cpu = smp_processor_id();
struct cpufreq_policy *cpu_policy;
pr_debug("suspending cpu %u\n", cpu);
cpu_policy = cpufreq_cpu_get(cpu);
if (!cpu_policy)
return 0;
if (cpufreq_driver->suspend) {
ret = cpufreq_driver->suspend(cpu_policy);
if (ret)
printk(KERN_ERR "cpufreq: suspend failed in ->suspend "
"step on CPU %u\n", cpu_policy->cpu);
}
cpufreq_cpu_put(cpu_policy);
return ret;
}
static void cpufreq_bp_resume(void)
{
int ret = 0;
int cpu = smp_processor_id();
struct cpufreq_policy *cpu_policy;
pr_debug("resuming cpu %u\n", cpu);
cpu_policy = cpufreq_cpu_get(cpu);
if (!cpu_policy)
return;
if (cpufreq_driver->resume) {
ret = cpufreq_driver->resume(cpu_policy);
if (ret) {
printk(KERN_ERR "cpufreq: resume failed in ->resume "
"step on CPU %u\n", cpu_policy->cpu);
goto fail;
}
}
schedule_work(&cpu_policy->update);
fail:
cpufreq_cpu_put(cpu_policy);
}
const char *cpufreq_get_current_driver(void)
{
if (cpufreq_driver)
return cpufreq_driver->name;
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
int __cpufreq_driver_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
int retval = -EINVAL;
unsigned int old_target_freq = target_freq;
if (cpufreq_disabled())
return -ENODEV;
if (policy->transition_ongoing)
return -EBUSY;
if (target_freq > policy->max)
target_freq = policy->max;
if (target_freq < policy->min)
target_freq = policy->min;
pr_debug("target for CPU %u: %u kHz, relation %u, requested %u kHz\n",
policy->cpu, target_freq, relation, old_target_freq);
if (target_freq == policy->cur)
return 0;
if (cpufreq_driver->target)
retval = cpufreq_driver->target(policy, target_freq, relation);
return retval;
}
int cpufreq_driver_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
int ret = -EINVAL;
if (unlikely(lock_policy_rwsem_write(policy->cpu)))
goto fail;
ret = __cpufreq_driver_target(policy, target_freq, relation);
unlock_policy_rwsem_write(policy->cpu);
fail:
return ret;
}
int __cpufreq_driver_getavg(struct cpufreq_policy *policy, unsigned int cpu)
{
if (cpufreq_disabled())
return 0;
if (!cpufreq_driver->getavg)
return 0;
return cpufreq_driver->getavg(policy, cpu);
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
if (policy->governor->max_transition_latency &&
policy->cpuinfo.transition_latency >
policy->governor->max_transition_latency) {
if (!gov)
return -EINVAL;
else {
printk(KERN_WARNING "%s governor failed, too long"
" transition latency of HW, fallback"
" to %s governor\n",
policy->governor->name,
gov->name);
policy->governor = gov;
}
}
if (!try_module_get(policy->governor->owner))
return -EINVAL;
pr_debug("__cpufreq_governor for CPU %u, event %u\n",
policy->cpu, event);
mutex_lock(&cpufreq_governor_lock);
if ((!policy->governor_enabled && (event == CPUFREQ_GOV_STOP)) ||
(policy->governor_enabled && (event == CPUFREQ_GOV_START))) {
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
if ((event != CPUFREQ_GOV_START) || ret)
module_put(policy->governor->owner);
if ((event == CPUFREQ_GOV_STOP) && !ret)
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
if (__find_governor(governor->name) == NULL) {
err = 0;
list_add(&governor->governor_list, &cpufreq_governor_list);
}
mutex_unlock(&cpufreq_governor_mutex);
return err;
}
void cpufreq_unregister_governor(struct cpufreq_governor *governor)
{
#ifdef CONFIG_HOTPLUG_CPU
int cpu;
#endif
if (!governor)
return;
if (cpufreq_disabled())
return;
#ifdef CONFIG_HOTPLUG_CPU
for_each_present_cpu(cpu) {
if (cpu_online(cpu))
continue;
if (!strcmp(per_cpu(cpufreq_cpu_governor, cpu), governor->name))
strcpy(per_cpu(cpufreq_cpu_governor, cpu), "\0");
}
#endif
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
memcpy(policy, cpu_policy, sizeof(struct cpufreq_policy));
cpufreq_cpu_put(cpu_policy);
return 0;
}
static int __cpufreq_set_policy(struct cpufreq_policy *data,
struct cpufreq_policy *policy)
{
int ret = 0, failed = 1;
pr_debug("setting new policy for CPU %u: %u - %u kHz\n", policy->cpu,
policy->min, policy->max);
memcpy(&policy->cpuinfo, &data->cpuinfo,
sizeof(struct cpufreq_cpuinfo));
if (policy->min > data->max || policy->max < data->min) {
ret = -EINVAL;
goto error_out;
}
ret = cpufreq_driver->verify(policy);
if (ret)
goto error_out;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_ADJUST, policy);
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_INCOMPATIBLE, policy);
ret = cpufreq_driver->verify(policy);
if (ret)
goto error_out;
blocking_notifier_call_chain(&cpufreq_policy_notifier_list,
CPUFREQ_NOTIFY, policy);
data->min = policy->min;
data->max = policy->max;
pr_debug("new min and max freqs are %u - %u kHz\n",
data->min, data->max);
if (cpufreq_driver->setpolicy) {
data->policy = policy->policy;
pr_debug("setting range\n");
ret = cpufreq_driver->setpolicy(policy);
} else {
if (policy->governor != data->governor) {
struct cpufreq_governor *old_gov = data->governor;
pr_debug("governor switch\n");
if (data->governor) {
__cpufreq_governor(data, CPUFREQ_GOV_STOP);
unlock_policy_rwsem_write(policy->cpu);
__cpufreq_governor(data,
CPUFREQ_GOV_POLICY_EXIT);
lock_policy_rwsem_write(policy->cpu);
}
data->governor = policy->governor;
if (!__cpufreq_governor(data, CPUFREQ_GOV_POLICY_INIT)) {
if (!__cpufreq_governor(data, CPUFREQ_GOV_START)) {
failed = 0;
} else {
unlock_policy_rwsem_write(policy->cpu);
__cpufreq_governor(data,
CPUFREQ_GOV_POLICY_EXIT);
lock_policy_rwsem_write(policy->cpu);
}
}
if (failed) {
pr_debug("starting governor %s failed\n",
data->governor->name);
if (old_gov) {
data->governor = old_gov;
__cpufreq_governor(data,
CPUFREQ_GOV_POLICY_INIT);
__cpufreq_governor(data,
CPUFREQ_GOV_START);
}
ret = -EINVAL;
goto error_out;
}
}
pr_debug("governor: change or update limits\n");
__cpufreq_governor(data, CPUFREQ_GOV_LIMITS);
}
error_out:
return ret;
}
int cpufreq_update_policy(unsigned int cpu)
{
struct cpufreq_policy *data = cpufreq_cpu_get(cpu);
struct cpufreq_policy policy;
int ret;
if (!data) {
ret = -ENODEV;
goto no_policy;
}
if (unlikely(lock_policy_rwsem_write(cpu))) {
ret = -EINVAL;
goto fail;
}
pr_debug("updating policy for CPU %u\n", cpu);
memcpy(&policy, data, sizeof(struct cpufreq_policy));
policy.min = data->user_policy.min;
policy.max = data->user_policy.max;
policy.policy = data->user_policy.policy;
policy.governor = data->user_policy.governor;
if (cpufreq_driver->get) {
policy.cur = cpufreq_driver->get(cpu);
if (!data->cur) {
pr_debug("Driver did not initialize current freq");
data->cur = policy.cur;
} else {
if (data->cur != policy.cur && cpufreq_driver->target)
cpufreq_out_of_sync(cpu, data->cur,
policy.cur);
}
}
ret = __cpufreq_set_policy(data, &policy);
unlock_policy_rwsem_write(cpu);
fail:
cpufreq_cpu_put(data);
no_policy:
return ret;
}
static int cpufreq_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct device *dev;
dev = get_cpu_device(cpu);
if (dev) {
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
cpufreq_add_dev(dev, NULL);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
__cpufreq_remove_dev(dev, NULL);
break;
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
cpufreq_add_dev(dev, NULL);
break;
}
}
return NOTIFY_OK;
}
int cpufreq_register_driver(struct cpufreq_driver *driver_data)
{
unsigned long flags;
int ret;
if (cpufreq_disabled())
return -ENODEV;
if (!driver_data || !driver_data->verify || !driver_data->init ||
((!driver_data->setpolicy) && (!driver_data->target)))
return -EINVAL;
pr_debug("trying to register driver %s\n", driver_data->name);
if (driver_data->setpolicy)
driver_data->flags |= CPUFREQ_CONST_LOOPS;
write_lock_irqsave(&cpufreq_driver_lock, flags);
if (cpufreq_driver) {
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
return -EBUSY;
}
cpufreq_driver = driver_data;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
ret = subsys_interface_register(&cpufreq_interface);
if (ret)
goto err_null_driver;
if (!(cpufreq_driver->flags & CPUFREQ_STICKY)) {
int i;
ret = -ENODEV;
for (i = 0; i < nr_cpu_ids; i++)
if (cpu_possible(i) && per_cpu(cpufreq_cpu_data, i)) {
ret = 0;
break;
}
if (ret) {
pr_debug("no CPU initialized for driver %s\n",
driver_data->name);
goto err_if_unreg;
}
}
register_hotcpu_notifier(&cpufreq_cpu_notifier);
pr_debug("driver %s up and running\n", driver_data->name);
return 0;
err_if_unreg:
subsys_interface_unregister(&cpufreq_interface);
err_null_driver:
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
return ret;
}
int cpufreq_unregister_driver(struct cpufreq_driver *driver)
{
unsigned long flags;
if (!cpufreq_driver || (driver != cpufreq_driver))
return -EINVAL;
pr_debug("unregistering driver %s\n", driver->name);
subsys_interface_unregister(&cpufreq_interface);
unregister_hotcpu_notifier(&cpufreq_cpu_notifier);
write_lock_irqsave(&cpufreq_driver_lock, flags);
cpufreq_driver = NULL;
write_unlock_irqrestore(&cpufreq_driver_lock, flags);
return 0;
}
static int __init cpufreq_core_init(void)
{
int cpu;
if (cpufreq_disabled())
return -ENODEV;
for_each_possible_cpu(cpu) {
per_cpu(cpufreq_policy_cpu, cpu) = -1;
init_rwsem(&per_cpu(cpu_policy_rwsem, cpu));
}
cpufreq_global_kobject = kobject_create();
BUG_ON(!cpufreq_global_kobject);
register_syscore_ops(&cpufreq_syscore_ops);
return 0;
}
