static int get_idr(struct idr *idr, int *id)
{
int ret;
mutex_lock(&cooling_cpufreq_lock);
ret = idr_alloc(idr, NULL, 0, 0, GFP_KERNEL);
mutex_unlock(&cooling_cpufreq_lock);
if (unlikely(ret < 0))
return ret;
*id = ret;
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
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
struct cpumask *maskPtr = &cpufreq_device->allowed_cpus;
unsigned int cpu;
struct cpufreq_frequency_table *table;
unsigned long count = 0;
int i = 0;
cpu = cpumask_any(maskPtr);
table = cpufreq_frequency_get_table(cpu);
if (!table) {
*state = 0;
return 0;
}
for (i = 0; (table[i].frequency != CPUFREQ_TABLE_END); i++) {
if (table[i].frequency == CPUFREQ_ENTRY_INVALID)
continue;
count++;
}
if (count > 0) {
*state = --count;
return 0;
}
return -EINVAL;
}
static int cpufreq_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
*state = cpufreq_device->cpufreq_state;
return 0;
}
static int cpufreq_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
return cpufreq_apply_cooling(cpufreq_device, state);
}
struct thermal_cooling_device *cpufreq_cooling_register(
const struct cpumask *clip_cpus)
{
struct thermal_cooling_device *cool_dev;
struct cpufreq_cooling_device *cpufreq_dev = NULL;
unsigned int min = 0, max = 0;
char dev_name[THERMAL_NAME_LENGTH];
int ret = 0, i;
struct cpufreq_policy policy;
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
if (cpufreq_dev_count == 0)
cpufreq_register_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
cpufreq_dev_count++;
mutex_unlock(&cooling_cpufreq_lock);
return cool_dev;
}
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct cpufreq_cooling_device *cpufreq_dev = cdev->devdata;
mutex_lock(&cooling_cpufreq_lock);
cpufreq_dev_count--;
if (cpufreq_dev_count == 0) {
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
}
mutex_unlock(&cooling_cpufreq_lock);
thermal_cooling_device_unregister(cpufreq_dev->cool_dev);
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev);
}
