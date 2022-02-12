static int get_idr(struct idr *idr, int *id)
{
int err;
again:
if (unlikely(idr_pre_get(idr, GFP_KERNEL) == 0))
return -ENOMEM;
mutex_lock(&cooling_cpufreq_lock);
err = idr_get_new(idr, NULL, id);
mutex_unlock(&cooling_cpufreq_lock);
if (unlikely(err == -EAGAIN))
goto again;
else if (unlikely(err))
return err;
*id = *id & MAX_IDR_MASK;
return 0;
}
static void release_idr(struct idr *idr, int id)
{
mutex_lock(&cooling_cpufreq_lock);
idr_remove(idr, id);
mutex_unlock(&cooling_cpufreq_lock);
}
static int is_cpufreq_valid(int cpu)
{
struct cpufreq_policy policy;
return !cpufreq_get_policy(&policy, cpu);
}
static unsigned int get_cpu_frequency(unsigned int cpu, unsigned long level)
{
int ret = 0, i = 0;
unsigned long level_index;
bool descend = false;
struct cpufreq_frequency_table *table =
cpufreq_frequency_get_table(cpu);
if (!table)
return ret;
while (table[i].frequency != CPUFREQ_TABLE_END) {
if (table[i].frequency == CPUFREQ_ENTRY_INVALID)
continue;
if ((table[i + 1].frequency != CPUFREQ_TABLE_END) &&
(table[i + 1].frequency < table[i].frequency)
&& !descend) {
descend = true;
}
if (descend && i == level)
return table[i].frequency;
i++;
}
i--;
if (level > i || descend)
return ret;
level_index = i - level;
while (i >= 0) {
if (table[i].frequency == CPUFREQ_ENTRY_INVALID)
continue;
if (i == level_index)
return table[i].frequency;
i--;
}
return ret;
}
static int cpufreq_apply_cooling(struct cpufreq_cooling_device *cpufreq_device,
unsigned long cooling_state)
{
unsigned int cpuid, clip_freq;
struct cpumask *maskPtr = &cpufreq_device->allowed_cpus;
unsigned int cpu = cpumask_any(maskPtr);
if (cpufreq_device->cpufreq_state == cooling_state)
return 0;
clip_freq = get_cpu_frequency(cpu, cooling_state);
if (!clip_freq)
return -EINVAL;
cpufreq_device->cpufreq_state = cooling_state;
cpufreq_device->cpufreq_val = clip_freq;
notify_device = cpufreq_device;
for_each_cpu(cpuid, maskPtr) {
if (is_cpufreq_valid(cpuid))
cpufreq_update_policy(cpuid);
}
notify_device = NOTIFY_INVALID;
return 0;
}
static int cpufreq_thermal_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
unsigned long max_freq = 0;
if (event != CPUFREQ_ADJUST || notify_device == NOTIFY_INVALID)
return 0;
if (cpumask_test_cpu(policy->cpu, &notify_device->allowed_cpus))
max_freq = notify_device->cpufreq_val;
if (max_freq > policy->user_policy.max)
max_freq = policy->user_policy.max;
if (policy->max != max_freq)
cpufreq_verify_within_limits(policy, 0, max_freq);
return 0;
}
static int cpufreq_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
int ret = -EINVAL, i = 0;
struct cpufreq_cooling_device *cpufreq_device;
struct cpumask *maskPtr;
unsigned int cpu;
struct cpufreq_frequency_table *table;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_device, &cooling_cpufreq_list, node) {
if (cpufreq_device && cpufreq_device->cool_dev == cdev)
break;
}
if (cpufreq_device == NULL)
goto return_get_max_state;
maskPtr = &cpufreq_device->allowed_cpus;
cpu = cpumask_any(maskPtr);
table = cpufreq_frequency_get_table(cpu);
if (!table) {
*state = 0;
ret = 0;
goto return_get_max_state;
}
while (table[i].frequency != CPUFREQ_TABLE_END) {
if (table[i].frequency == CPUFREQ_ENTRY_INVALID)
continue;
i++;
}
if (i > 0) {
*state = --i;
ret = 0;
}
return_get_max_state:
mutex_unlock(&cooling_cpufreq_lock);
return ret;
}
static int cpufreq_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
int ret = -EINVAL;
struct cpufreq_cooling_device *cpufreq_device;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_device, &cooling_cpufreq_list, node) {
if (cpufreq_device && cpufreq_device->cool_dev == cdev) {
*state = cpufreq_device->cpufreq_state;
ret = 0;
break;
}
}
mutex_unlock(&cooling_cpufreq_lock);
return ret;
}
static int cpufreq_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
int ret = -EINVAL;
struct cpufreq_cooling_device *cpufreq_device;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_device, &cooling_cpufreq_list, node) {
if (cpufreq_device && cpufreq_device->cool_dev == cdev) {
ret = 0;
break;
}
}
if (!ret)
ret = cpufreq_apply_cooling(cpufreq_device, state);
mutex_unlock(&cooling_cpufreq_lock);
return ret;
}
struct thermal_cooling_device *cpufreq_cooling_register(
struct cpumask *clip_cpus)
{
struct thermal_cooling_device *cool_dev;
struct cpufreq_cooling_device *cpufreq_dev = NULL;
unsigned int cpufreq_dev_count = 0, min = 0, max = 0;
char dev_name[THERMAL_NAME_LENGTH];
int ret = 0, i;
struct cpufreq_policy policy;
list_for_each_entry(cpufreq_dev, &cooling_cpufreq_list, node)
cpufreq_dev_count++;
for_each_cpu(i, clip_cpus) {
if (!cpufreq_get_policy(&policy, i))
continue;
if (min == 0 && max == 0) {
min = policy.cpuinfo.min_freq;
max = policy.cpuinfo.max_freq;
} else {
if (min != policy.cpuinfo.min_freq ||
max != policy.cpuinfo.max_freq)
return ERR_PTR(-EINVAL);
}
}
cpufreq_dev = kzalloc(sizeof(struct cpufreq_cooling_device),
GFP_KERNEL);
if (!cpufreq_dev)
return ERR_PTR(-ENOMEM);
cpumask_copy(&cpufreq_dev->allowed_cpus, clip_cpus);
if (cpufreq_dev_count == 0)
mutex_init(&cooling_cpufreq_lock);
ret = get_idr(&cpufreq_idr, &cpufreq_dev->id);
if (ret) {
kfree(cpufreq_dev);
return ERR_PTR(-EINVAL);
}
sprintf(dev_name, "thermal-cpufreq-%d", cpufreq_dev->id);
cool_dev = thermal_cooling_device_register(dev_name, cpufreq_dev,
&cpufreq_cooling_ops);
if (!cool_dev) {
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev);
return ERR_PTR(-EINVAL);
}
cpufreq_dev->cool_dev = cool_dev;
cpufreq_dev->cpufreq_state = 0;
mutex_lock(&cooling_cpufreq_lock);
list_add_tail(&cpufreq_dev->node, &cooling_cpufreq_list);
if (cpufreq_dev_count == 0)
cpufreq_register_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
mutex_unlock(&cooling_cpufreq_lock);
return cool_dev;
}
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct cpufreq_cooling_device *cpufreq_dev = NULL;
unsigned int cpufreq_dev_count = 0;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_dev, &cooling_cpufreq_list, node) {
if (cpufreq_dev && cpufreq_dev->cool_dev == cdev)
break;
cpufreq_dev_count++;
}
if (!cpufreq_dev || cpufreq_dev->cool_dev != cdev) {
mutex_unlock(&cooling_cpufreq_lock);
return;
}
list_del(&cpufreq_dev->node);
if (cpufreq_dev_count == 1) {
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
}
mutex_unlock(&cooling_cpufreq_lock);
thermal_cooling_device_unregister(cpufreq_dev->cool_dev);
release_idr(&cpufreq_idr, cpufreq_dev->id);
if (cpufreq_dev_count == 1)
mutex_destroy(&cooling_cpufreq_lock);
kfree(cpufreq_dev);
}
