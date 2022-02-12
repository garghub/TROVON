static unsigned long get_level(struct cpufreq_cooling_device *cpufreq_cdev,
unsigned int freq)
{
struct freq_table *freq_table = cpufreq_cdev->freq_table;
unsigned long level;
for (level = 1; level <= cpufreq_cdev->max_level; level++)
if (freq > freq_table[level].frequency)
break;
return level - 1;
}
static int cpufreq_thermal_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
unsigned long clipped_freq;
struct cpufreq_cooling_device *cpufreq_cdev;
if (event != CPUFREQ_ADJUST)
return NOTIFY_DONE;
mutex_lock(&cooling_list_lock);
list_for_each_entry(cpufreq_cdev, &cpufreq_cdev_list, node) {
if (policy->cpu != cpufreq_cdev->policy->cpu)
continue;
clipped_freq = cpufreq_cdev->clipped_freq;
if (policy->max > clipped_freq)
cpufreq_verify_within_limits(policy, 0, clipped_freq);
break;
}
mutex_unlock(&cooling_list_lock);
return NOTIFY_OK;
}
static int update_freq_table(struct cpufreq_cooling_device *cpufreq_cdev,
u32 capacitance)
{
struct freq_table *freq_table = cpufreq_cdev->freq_table;
struct dev_pm_opp *opp;
struct device *dev = NULL;
int num_opps = 0, cpu = cpufreq_cdev->policy->cpu, i;
dev = get_cpu_device(cpu);
if (unlikely(!dev)) {
dev_warn(&cpufreq_cdev->cdev->device,
"No cpu device for cpu %d\n", cpu);
return -ENODEV;
}
num_opps = dev_pm_opp_get_opp_count(dev);
if (num_opps < 0)
return num_opps;
if (num_opps != cpufreq_cdev->max_level + 1) {
dev_warn(dev, "Number of OPPs not matching with max_levels\n");
return -EINVAL;
}
for (i = 0; i <= cpufreq_cdev->max_level; i++) {
unsigned long freq = freq_table[i].frequency * 1000;
u32 freq_mhz = freq_table[i].frequency / 1000;
u64 power;
u32 voltage_mv;
opp = dev_pm_opp_find_freq_ceil(dev, &freq);
if (IS_ERR(opp)) {
dev_err(dev, "failed to get opp for %lu frequency\n",
freq);
return -EINVAL;
}
voltage_mv = dev_pm_opp_get_voltage(opp) / 1000;
dev_pm_opp_put(opp);
power = (u64)capacitance * freq_mhz * voltage_mv * voltage_mv;
do_div(power, 1000000000);
freq_table[i].power = power;
}
return 0;
}
static u32 cpu_freq_to_power(struct cpufreq_cooling_device *cpufreq_cdev,
u32 freq)
{
int i;
struct freq_table *freq_table = cpufreq_cdev->freq_table;
for (i = 1; i <= cpufreq_cdev->max_level; i++)
if (freq > freq_table[i].frequency)
break;
return freq_table[i - 1].power;
}
static u32 cpu_power_to_freq(struct cpufreq_cooling_device *cpufreq_cdev,
u32 power)
{
int i;
struct freq_table *freq_table = cpufreq_cdev->freq_table;
for (i = 1; i <= cpufreq_cdev->max_level; i++)
if (power > freq_table[i].power)
break;
return freq_table[i - 1].frequency;
}
static u32 get_load(struct cpufreq_cooling_device *cpufreq_cdev, int cpu,
int cpu_idx)
{
u32 load;
u64 now, now_idle, delta_time, delta_idle;
struct time_in_idle *idle_time = &cpufreq_cdev->idle_time[cpu_idx];
now_idle = get_cpu_idle_time(cpu, &now, 0);
delta_idle = now_idle - idle_time->time;
delta_time = now - idle_time->timestamp;
if (delta_time <= delta_idle)
load = 0;
else
load = div64_u64(100 * (delta_time - delta_idle), delta_time);
idle_time->time = now_idle;
idle_time->timestamp = now;
return load;
}
static int get_static_power(struct cpufreq_cooling_device *cpufreq_cdev,
struct thermal_zone_device *tz, unsigned long freq,
u32 *power)
{
struct dev_pm_opp *opp;
unsigned long voltage;
struct cpufreq_policy *policy = cpufreq_cdev->policy;
struct cpumask *cpumask = policy->related_cpus;
unsigned long freq_hz = freq * 1000;
struct device *dev;
if (!cpufreq_cdev->plat_get_static_power) {
*power = 0;
return 0;
}
dev = get_cpu_device(policy->cpu);
WARN_ON(!dev);
opp = dev_pm_opp_find_freq_exact(dev, freq_hz, true);
if (IS_ERR(opp)) {
dev_warn_ratelimited(dev, "Failed to find OPP for frequency %lu: %ld\n",
freq_hz, PTR_ERR(opp));
return -EINVAL;
}
voltage = dev_pm_opp_get_voltage(opp);
dev_pm_opp_put(opp);
if (voltage == 0) {
dev_err_ratelimited(dev, "Failed to get voltage for frequency %lu\n",
freq_hz);
return -EINVAL;
}
return cpufreq_cdev->plat_get_static_power(cpumask, tz->passive_delay,
voltage, power);
}
static u32 get_dynamic_power(struct cpufreq_cooling_device *cpufreq_cdev,
unsigned long freq)
{
u32 raw_cpu_power;
raw_cpu_power = cpu_freq_to_power(cpufreq_cdev, freq);
return (raw_cpu_power * cpufreq_cdev->last_load) / 100;
}
static int cpufreq_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
*state = cpufreq_cdev->max_level;
return 0;
}
static int cpufreq_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
*state = cpufreq_cdev->cpufreq_state;
return 0;
}
static int cpufreq_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
unsigned int clip_freq;
if (WARN_ON(state > cpufreq_cdev->max_level))
return -EINVAL;
if (cpufreq_cdev->cpufreq_state == state)
return 0;
clip_freq = cpufreq_cdev->freq_table[state].frequency;
cpufreq_cdev->cpufreq_state = state;
cpufreq_cdev->clipped_freq = clip_freq;
cpufreq_update_policy(cpufreq_cdev->policy->cpu);
return 0;
}
static int cpufreq_get_requested_power(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz,
u32 *power)
{
unsigned long freq;
int i = 0, cpu, ret;
u32 static_power, dynamic_power, total_load = 0;
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
struct cpufreq_policy *policy = cpufreq_cdev->policy;
u32 *load_cpu = NULL;
freq = cpufreq_quick_get(policy->cpu);
if (trace_thermal_power_cpu_get_power_enabled()) {
u32 ncpus = cpumask_weight(policy->related_cpus);
load_cpu = kcalloc(ncpus, sizeof(*load_cpu), GFP_KERNEL);
}
for_each_cpu(cpu, policy->related_cpus) {
u32 load;
if (cpu_online(cpu))
load = get_load(cpufreq_cdev, cpu, i);
else
load = 0;
total_load += load;
if (trace_thermal_power_cpu_limit_enabled() && load_cpu)
load_cpu[i] = load;
i++;
}
cpufreq_cdev->last_load = total_load;
dynamic_power = get_dynamic_power(cpufreq_cdev, freq);
ret = get_static_power(cpufreq_cdev, tz, freq, &static_power);
if (ret) {
kfree(load_cpu);
return ret;
}
if (load_cpu) {
trace_thermal_power_cpu_get_power(policy->related_cpus, freq,
load_cpu, i, dynamic_power,
static_power);
kfree(load_cpu);
}
*power = static_power + dynamic_power;
return 0;
}
static int cpufreq_state2power(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz,
unsigned long state, u32 *power)
{
unsigned int freq, num_cpus;
u32 static_power, dynamic_power;
int ret;
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
if (WARN_ON(state > cpufreq_cdev->max_level))
return -EINVAL;
num_cpus = cpumask_weight(cpufreq_cdev->policy->cpus);
freq = cpufreq_cdev->freq_table[state].frequency;
dynamic_power = cpu_freq_to_power(cpufreq_cdev, freq) * num_cpus;
ret = get_static_power(cpufreq_cdev, tz, freq, &static_power);
if (ret)
return ret;
*power = static_power + dynamic_power;
return ret;
}
static int cpufreq_power2state(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz, u32 power,
unsigned long *state)
{
unsigned int cur_freq, target_freq;
int ret;
s32 dyn_power;
u32 last_load, normalised_power, static_power;
struct cpufreq_cooling_device *cpufreq_cdev = cdev->devdata;
struct cpufreq_policy *policy = cpufreq_cdev->policy;
cur_freq = cpufreq_quick_get(policy->cpu);
ret = get_static_power(cpufreq_cdev, tz, cur_freq, &static_power);
if (ret)
return ret;
dyn_power = power - static_power;
dyn_power = dyn_power > 0 ? dyn_power : 0;
last_load = cpufreq_cdev->last_load ?: 1;
normalised_power = (dyn_power * 100) / last_load;
target_freq = cpu_power_to_freq(cpufreq_cdev, normalised_power);
*state = get_level(cpufreq_cdev, target_freq);
trace_thermal_power_cpu_limit(policy->related_cpus, target_freq, *state,
power);
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
struct cpufreq_policy *policy, u32 capacitance,
get_static_t plat_static_func)
{
struct thermal_cooling_device *cdev;
struct cpufreq_cooling_device *cpufreq_cdev;
char dev_name[THERMAL_NAME_LENGTH];
unsigned int freq, i, num_cpus;
int ret;
struct thermal_cooling_device_ops *cooling_ops;
bool first;
if (IS_ERR_OR_NULL(policy)) {
pr_err("%s: cpufreq policy isn't valid: %p", __func__, policy);
return ERR_PTR(-EINVAL);
}
i = cpufreq_table_count_valid_entries(policy);
if (!i) {
pr_debug("%s: CPUFreq table not found or has no valid entries\n",
__func__);
return ERR_PTR(-ENODEV);
}
cpufreq_cdev = kzalloc(sizeof(*cpufreq_cdev), GFP_KERNEL);
if (!cpufreq_cdev)
return ERR_PTR(-ENOMEM);
cpufreq_cdev->policy = policy;
num_cpus = cpumask_weight(policy->related_cpus);
cpufreq_cdev->idle_time = kcalloc(num_cpus,
sizeof(*cpufreq_cdev->idle_time),
GFP_KERNEL);
if (!cpufreq_cdev->idle_time) {
cdev = ERR_PTR(-ENOMEM);
goto free_cdev;
}
cpufreq_cdev->max_level = i - 1;
cpufreq_cdev->freq_table = kmalloc_array(i,
sizeof(*cpufreq_cdev->freq_table),
GFP_KERNEL);
if (!cpufreq_cdev->freq_table) {
cdev = ERR_PTR(-ENOMEM);
goto free_idle_time;
}
ret = ida_simple_get(&cpufreq_ida, 0, 0, GFP_KERNEL);
if (ret < 0) {
cdev = ERR_PTR(ret);
goto free_table;
}
cpufreq_cdev->id = ret;
snprintf(dev_name, sizeof(dev_name), "thermal-cpufreq-%d",
cpufreq_cdev->id);
for (i = 0, freq = -1; i <= cpufreq_cdev->max_level; i++) {
freq = find_next_max(policy->freq_table, freq);
cpufreq_cdev->freq_table[i].frequency = freq;
if (!freq)
pr_warn("%s: table has duplicate entries\n", __func__);
else
pr_debug("%s: freq:%u KHz\n", __func__, freq);
}
if (capacitance) {
cpufreq_cdev->plat_get_static_power = plat_static_func;
ret = update_freq_table(cpufreq_cdev, capacitance);
if (ret) {
cdev = ERR_PTR(ret);
goto remove_ida;
}
cooling_ops = &cpufreq_power_cooling_ops;
} else {
cooling_ops = &cpufreq_cooling_ops;
}
cdev = thermal_of_cooling_device_register(np, dev_name, cpufreq_cdev,
cooling_ops);
if (IS_ERR(cdev))
goto remove_ida;
cpufreq_cdev->clipped_freq = cpufreq_cdev->freq_table[0].frequency;
cpufreq_cdev->cdev = cdev;
mutex_lock(&cooling_list_lock);
first = list_empty(&cpufreq_cdev_list);
list_add(&cpufreq_cdev->node, &cpufreq_cdev_list);
mutex_unlock(&cooling_list_lock);
if (first)
cpufreq_register_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
return cdev;
remove_ida:
ida_simple_remove(&cpufreq_ida, cpufreq_cdev->id);
free_table:
kfree(cpufreq_cdev->freq_table);
free_idle_time:
kfree(cpufreq_cdev->idle_time);
free_cdev:
kfree(cpufreq_cdev);
return cdev;
}
struct thermal_cooling_device *
cpufreq_cooling_register(struct cpufreq_policy *policy)
{
return __cpufreq_cooling_register(NULL, policy, 0, NULL);
}
struct thermal_cooling_device *
of_cpufreq_cooling_register(struct device_node *np,
struct cpufreq_policy *policy)
{
if (!np)
return ERR_PTR(-EINVAL);
return __cpufreq_cooling_register(np, policy, 0, NULL);
}
struct thermal_cooling_device *
cpufreq_power_cooling_register(struct cpufreq_policy *policy, u32 capacitance,
get_static_t plat_static_func)
{
return __cpufreq_cooling_register(NULL, policy, capacitance,
plat_static_func);
}
struct thermal_cooling_device *
of_cpufreq_power_cooling_register(struct device_node *np,
struct cpufreq_policy *policy,
u32 capacitance,
get_static_t plat_static_func)
{
if (!np)
return ERR_PTR(-EINVAL);
return __cpufreq_cooling_register(np, policy, capacitance,
plat_static_func);
}
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct cpufreq_cooling_device *cpufreq_cdev;
bool last;
if (!cdev)
return;
cpufreq_cdev = cdev->devdata;
mutex_lock(&cooling_list_lock);
list_del(&cpufreq_cdev->node);
last = list_empty(&cpufreq_cdev_list);
mutex_unlock(&cooling_list_lock);
if (last)
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
thermal_cooling_device_unregister(cpufreq_cdev->cdev);
ida_simple_remove(&cpufreq_ida, cpufreq_cdev->id);
kfree(cpufreq_cdev->idle_time);
kfree(cpufreq_cdev->freq_table);
kfree(cpufreq_cdev);
}
