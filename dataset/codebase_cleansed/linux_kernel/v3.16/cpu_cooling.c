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
static int get_property(unsigned int cpu, unsigned long input,
unsigned int *output,
enum cpufreq_cooling_property property)
{
int i;
unsigned long max_level = 0, level = 0;
unsigned int freq = CPUFREQ_ENTRY_INVALID;
int descend = -1;
struct cpufreq_frequency_table *pos, *table =
cpufreq_frequency_get_table(cpu);
if (!output)
return -EINVAL;
if (!table)
return -EINVAL;
cpufreq_for_each_valid_entry(pos, table) {
if (freq == pos->frequency)
continue;
if (freq != CPUFREQ_ENTRY_INVALID && descend == -1)
descend = freq > pos->frequency;
freq = pos->frequency;
max_level++;
}
if (max_level == 0)
return -EINVAL;
max_level--;
if (property == GET_MAXL) {
*output = (unsigned int)max_level;
return 0;
}
if (property == GET_FREQ)
level = descend ? input : (max_level - input);
i = 0;
cpufreq_for_each_valid_entry(pos, table) {
if (freq == pos->frequency)
continue;
freq = pos->frequency;
if (property == GET_LEVEL && (unsigned int)input == freq) {
*output = descend ? i : (max_level - i);
return 0;
}
if (property == GET_FREQ && level == i) {
*output = freq;
return 0;
}
i++;
}
return -EINVAL;
}
unsigned long cpufreq_cooling_get_level(unsigned int cpu, unsigned int freq)
{
unsigned int val;
if (get_property(cpu, (unsigned long)freq, &val, GET_LEVEL))
return THERMAL_CSTATE_INVALID;
return (unsigned long)val;
}
static unsigned int get_cpu_frequency(unsigned int cpu, unsigned long level)
{
int ret = 0;
unsigned int freq;
ret = get_property(cpu, level, &freq, GET_FREQ);
if (ret)
return 0;
return freq;
}
static int cpufreq_apply_cooling(struct cpufreq_cooling_device *cpufreq_device,
unsigned long cooling_state)
{
unsigned int cpuid, clip_freq;
struct cpumask *mask = &cpufreq_device->allowed_cpus;
unsigned int cpu = cpumask_any(mask);
if (cpufreq_device->cpufreq_state == cooling_state)
return 0;
clip_freq = get_cpu_frequency(cpu, cooling_state);
if (!clip_freq)
return -EINVAL;
cpufreq_device->cpufreq_state = cooling_state;
cpufreq_device->cpufreq_val = clip_freq;
notify_device = cpufreq_device;
for_each_cpu(cpuid, mask) {
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
else
return 0;
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
struct cpumask *mask = &cpufreq_device->allowed_cpus;
unsigned int cpu;
unsigned int count = 0;
int ret;
cpu = cpumask_any(mask);
ret = get_property(cpu, 0, &count, GET_MAXL);
if (count > 0)
*state = count;
return ret;
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
static struct thermal_cooling_device *
__cpufreq_cooling_register(struct device_node *np,
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
snprintf(dev_name, sizeof(dev_name), "thermal-cpufreq-%d",
cpufreq_dev->id);
cool_dev = thermal_of_cooling_device_register(np, dev_name, cpufreq_dev,
&cpufreq_cooling_ops);
if (IS_ERR(cool_dev)) {
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev);
return cool_dev;
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
struct thermal_cooling_device *
cpufreq_cooling_register(const struct cpumask *clip_cpus)
{
return __cpufreq_cooling_register(NULL, clip_cpus);
}
struct thermal_cooling_device *
of_cpufreq_cooling_register(struct device_node *np,
const struct cpumask *clip_cpus)
{
if (!np)
return ERR_PTR(-EINVAL);
return __cpufreq_cooling_register(np, clip_cpus);
}
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct cpufreq_cooling_device *cpufreq_dev;
if (!cdev)
return;
cpufreq_dev = cdev->devdata;
mutex_lock(&cooling_cpufreq_lock);
cpufreq_dev_count--;
if (cpufreq_dev_count == 0)
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
mutex_unlock(&cooling_cpufreq_lock);
thermal_cooling_device_unregister(cpufreq_dev->cool_dev);
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev);
}
