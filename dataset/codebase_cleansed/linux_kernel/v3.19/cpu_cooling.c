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
static unsigned long get_level(struct cpufreq_cooling_device *cpufreq_dev,
unsigned int freq)
{
unsigned long level;
for (level = 0; level <= cpufreq_dev->max_level; level++) {
if (freq == cpufreq_dev->freq_table[level])
return level;
if (freq > cpufreq_dev->freq_table[level])
break;
}
return THERMAL_CSTATE_INVALID;
}
unsigned long cpufreq_cooling_get_level(unsigned int cpu, unsigned int freq)
{
struct cpufreq_cooling_device *cpufreq_dev;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_dev, &cpufreq_dev_list, node) {
if (cpumask_test_cpu(cpu, &cpufreq_dev->allowed_cpus)) {
mutex_unlock(&cooling_cpufreq_lock);
return get_level(cpufreq_dev, freq);
}
}
mutex_unlock(&cooling_cpufreq_lock);
pr_err("%s: cpu:%d not part of any cooling device\n", __func__, cpu);
return THERMAL_CSTATE_INVALID;
}
static int cpufreq_thermal_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
unsigned long max_freq = 0;
struct cpufreq_cooling_device *cpufreq_dev;
if (event != CPUFREQ_ADJUST)
return 0;
mutex_lock(&cooling_cpufreq_lock);
list_for_each_entry(cpufreq_dev, &cpufreq_dev_list, node) {
if (!cpumask_test_cpu(policy->cpu,
&cpufreq_dev->allowed_cpus))
continue;
max_freq = cpufreq_dev->cpufreq_val;
if (policy->max != max_freq)
cpufreq_verify_within_limits(policy, 0, max_freq);
}
mutex_unlock(&cooling_cpufreq_lock);
return 0;
}
static int cpufreq_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
*state = cpufreq_device->max_level;
return 0;
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
unsigned int cpu = cpumask_any(&cpufreq_device->allowed_cpus);
unsigned int clip_freq;
if (WARN_ON(state > cpufreq_device->max_level))
return -EINVAL;
if (cpufreq_device->cpufreq_state == state)
return 0;
clip_freq = cpufreq_device->freq_table[state];
cpufreq_device->cpufreq_state = state;
cpufreq_device->cpufreq_val = clip_freq;
cpufreq_update_policy(cpu);
return 0;
}
static unsigned int find_next_max(struct cpufreq_frequency_table *table,
unsigned int prev_max)
{
struct cpufreq_frequency_table *pos;
unsigned int max = 0;
cpufreq_for_each_valid_entry(pos, table) {
if (pos->frequency > max && pos->frequency < prev_max)
max = pos->frequency;
}
return max;
}
static struct thermal_cooling_device *
__cpufreq_cooling_register(struct device_node *np,
const struct cpumask *clip_cpus)
{
struct thermal_cooling_device *cool_dev;
struct cpufreq_cooling_device *cpufreq_dev;
char dev_name[THERMAL_NAME_LENGTH];
struct cpufreq_frequency_table *pos, *table;
unsigned int freq, i;
int ret;
table = cpufreq_frequency_get_table(cpumask_first(clip_cpus));
if (!table) {
pr_debug("%s: CPUFreq table not found\n", __func__);
return ERR_PTR(-EPROBE_DEFER);
}
cpufreq_dev = kzalloc(sizeof(*cpufreq_dev), GFP_KERNEL);
if (!cpufreq_dev)
return ERR_PTR(-ENOMEM);
cpufreq_for_each_valid_entry(pos, table)
cpufreq_dev->max_level++;
cpufreq_dev->freq_table = kmalloc(sizeof(*cpufreq_dev->freq_table) *
cpufreq_dev->max_level, GFP_KERNEL);
if (!cpufreq_dev->freq_table) {
cool_dev = ERR_PTR(-ENOMEM);
goto free_cdev;
}
cpufreq_dev->max_level--;
cpumask_copy(&cpufreq_dev->allowed_cpus, clip_cpus);
ret = get_idr(&cpufreq_idr, &cpufreq_dev->id);
if (ret) {
cool_dev = ERR_PTR(ret);
goto free_table;
}
snprintf(dev_name, sizeof(dev_name), "thermal-cpufreq-%d",
cpufreq_dev->id);
cool_dev = thermal_of_cooling_device_register(np, dev_name, cpufreq_dev,
&cpufreq_cooling_ops);
if (IS_ERR(cool_dev))
goto remove_idr;
for (i = 0, freq = -1; i <= cpufreq_dev->max_level; i++) {
freq = find_next_max(table, freq);
cpufreq_dev->freq_table[i] = freq;
if (!freq)
pr_warn("%s: table has duplicate entries\n", __func__);
else
pr_debug("%s: freq:%u KHz\n", __func__, freq);
}
cpufreq_dev->cpufreq_val = cpufreq_dev->freq_table[0];
cpufreq_dev->cool_dev = cool_dev;
mutex_lock(&cooling_cpufreq_lock);
if (list_empty(&cpufreq_dev_list))
cpufreq_register_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
list_add(&cpufreq_dev->node, &cpufreq_dev_list);
mutex_unlock(&cooling_cpufreq_lock);
return cool_dev;
remove_idr:
release_idr(&cpufreq_idr, cpufreq_dev->id);
free_table:
kfree(cpufreq_dev->freq_table);
free_cdev:
kfree(cpufreq_dev);
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
list_del(&cpufreq_dev->node);
if (list_empty(&cpufreq_dev_list))
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
mutex_unlock(&cooling_cpufreq_lock);
thermal_cooling_device_unregister(cpufreq_dev->cool_dev);
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev->freq_table);
kfree(cpufreq_dev);
}
