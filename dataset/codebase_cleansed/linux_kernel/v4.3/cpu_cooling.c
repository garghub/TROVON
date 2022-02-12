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
mutex_lock(&cooling_list_lock);
list_for_each_entry(cpufreq_dev, &cpufreq_dev_list, node) {
if (cpumask_test_cpu(cpu, &cpufreq_dev->allowed_cpus)) {
mutex_unlock(&cooling_list_lock);
return get_level(cpufreq_dev, freq);
}
}
mutex_unlock(&cooling_list_lock);
pr_err("%s: cpu:%d not part of any cooling device\n", __func__, cpu);
return THERMAL_CSTATE_INVALID;
}
static int cpufreq_thermal_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
unsigned long clipped_freq;
struct cpufreq_cooling_device *cpufreq_dev;
if (event != CPUFREQ_ADJUST)
return NOTIFY_DONE;
mutex_lock(&cooling_list_lock);
list_for_each_entry(cpufreq_dev, &cpufreq_dev_list, node) {
if (!cpumask_test_cpu(policy->cpu, &cpufreq_dev->allowed_cpus))
continue;
clipped_freq = cpufreq_dev->clipped_freq;
if (policy->max > clipped_freq)
cpufreq_verify_within_limits(policy, 0, clipped_freq);
break;
}
mutex_unlock(&cooling_list_lock);
return NOTIFY_OK;
}
static int build_dyn_power_table(struct cpufreq_cooling_device *cpufreq_device,
u32 capacitance)
{
struct power_table *power_table;
struct dev_pm_opp *opp;
struct device *dev = NULL;
int num_opps = 0, cpu, i, ret = 0;
unsigned long freq;
for_each_cpu(cpu, &cpufreq_device->allowed_cpus) {
dev = get_cpu_device(cpu);
if (!dev) {
dev_warn(&cpufreq_device->cool_dev->device,
"No cpu device for cpu %d\n", cpu);
continue;
}
num_opps = dev_pm_opp_get_opp_count(dev);
if (num_opps > 0)
break;
else if (num_opps < 0)
return num_opps;
}
if (num_opps == 0)
return -EINVAL;
power_table = kcalloc(num_opps, sizeof(*power_table), GFP_KERNEL);
if (!power_table)
return -ENOMEM;
rcu_read_lock();
for (freq = 0, i = 0;
opp = dev_pm_opp_find_freq_ceil(dev, &freq), !IS_ERR(opp);
freq++, i++) {
u32 freq_mhz, voltage_mv;
u64 power;
if (i >= num_opps) {
rcu_read_unlock();
ret = -EAGAIN;
goto free_power_table;
}
freq_mhz = freq / 1000000;
voltage_mv = dev_pm_opp_get_voltage(opp) / 1000;
power = (u64)capacitance * freq_mhz * voltage_mv * voltage_mv;
do_div(power, 1000000000);
power_table[i].frequency = freq / 1000;
power_table[i].power = power;
}
rcu_read_unlock();
if (i != num_opps) {
ret = PTR_ERR(opp);
goto free_power_table;
}
cpufreq_device->cpu_dev = dev;
cpufreq_device->dyn_power_table = power_table;
cpufreq_device->dyn_power_table_entries = i;
return 0;
free_power_table:
kfree(power_table);
return ret;
}
static u32 cpu_freq_to_power(struct cpufreq_cooling_device *cpufreq_device,
u32 freq)
{
int i;
struct power_table *pt = cpufreq_device->dyn_power_table;
for (i = 1; i < cpufreq_device->dyn_power_table_entries; i++)
if (freq < pt[i].frequency)
break;
return pt[i - 1].power;
}
static u32 cpu_power_to_freq(struct cpufreq_cooling_device *cpufreq_device,
u32 power)
{
int i;
struct power_table *pt = cpufreq_device->dyn_power_table;
for (i = 1; i < cpufreq_device->dyn_power_table_entries; i++)
if (power < pt[i].power)
break;
return pt[i - 1].frequency;
}
static u32 get_load(struct cpufreq_cooling_device *cpufreq_device, int cpu)
{
u32 load;
u64 now, now_idle, delta_time, delta_idle;
now_idle = get_cpu_idle_time(cpu, &now, 0);
delta_idle = now_idle - cpufreq_device->time_in_idle[cpu];
delta_time = now - cpufreq_device->time_in_idle_timestamp[cpu];
if (delta_time <= delta_idle)
load = 0;
else
load = div64_u64(100 * (delta_time - delta_idle), delta_time);
cpufreq_device->time_in_idle[cpu] = now_idle;
cpufreq_device->time_in_idle_timestamp[cpu] = now;
return load;
}
static int get_static_power(struct cpufreq_cooling_device *cpufreq_device,
struct thermal_zone_device *tz, unsigned long freq,
u32 *power)
{
struct dev_pm_opp *opp;
unsigned long voltage;
struct cpumask *cpumask = &cpufreq_device->allowed_cpus;
unsigned long freq_hz = freq * 1000;
if (!cpufreq_device->plat_get_static_power ||
!cpufreq_device->cpu_dev) {
*power = 0;
return 0;
}
rcu_read_lock();
opp = dev_pm_opp_find_freq_exact(cpufreq_device->cpu_dev, freq_hz,
true);
voltage = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
if (voltage == 0) {
dev_warn_ratelimited(cpufreq_device->cpu_dev,
"Failed to get voltage for frequency %lu: %ld\n",
freq_hz, IS_ERR(opp) ? PTR_ERR(opp) : 0);
return -EINVAL;
}
return cpufreq_device->plat_get_static_power(cpumask, tz->passive_delay,
voltage, power);
}
static u32 get_dynamic_power(struct cpufreq_cooling_device *cpufreq_device,
unsigned long freq)
{
u32 raw_cpu_power;
raw_cpu_power = cpu_freq_to_power(cpufreq_device, freq);
return (raw_cpu_power * cpufreq_device->last_load) / 100;
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
cpufreq_device->clipped_freq = clip_freq;
cpufreq_update_policy(cpu);
return 0;
}
static int cpufreq_get_requested_power(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz,
u32 *power)
{
unsigned long freq;
int i = 0, cpu, ret;
u32 static_power, dynamic_power, total_load = 0;
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
u32 *load_cpu = NULL;
cpu = cpumask_any_and(&cpufreq_device->allowed_cpus, cpu_online_mask);
if (cpu >= nr_cpu_ids) {
*power = 0;
return 0;
}
freq = cpufreq_quick_get(cpu);
if (trace_thermal_power_cpu_get_power_enabled()) {
u32 ncpus = cpumask_weight(&cpufreq_device->allowed_cpus);
load_cpu = devm_kcalloc(&cdev->device, ncpus, sizeof(*load_cpu),
GFP_KERNEL);
}
for_each_cpu(cpu, &cpufreq_device->allowed_cpus) {
u32 load;
if (cpu_online(cpu))
load = get_load(cpufreq_device, cpu);
else
load = 0;
total_load += load;
if (trace_thermal_power_cpu_limit_enabled() && load_cpu)
load_cpu[i] = load;
i++;
}
cpufreq_device->last_load = total_load;
dynamic_power = get_dynamic_power(cpufreq_device, freq);
ret = get_static_power(cpufreq_device, tz, freq, &static_power);
if (ret) {
if (load_cpu)
devm_kfree(&cdev->device, load_cpu);
return ret;
}
if (load_cpu) {
trace_thermal_power_cpu_get_power(
&cpufreq_device->allowed_cpus,
freq, load_cpu, i, dynamic_power, static_power);
devm_kfree(&cdev->device, load_cpu);
}
*power = static_power + dynamic_power;
return 0;
}
static int cpufreq_state2power(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz,
unsigned long state, u32 *power)
{
unsigned int freq, num_cpus;
cpumask_t cpumask;
u32 static_power, dynamic_power;
int ret;
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
cpumask_and(&cpumask, &cpufreq_device->allowed_cpus, cpu_online_mask);
num_cpus = cpumask_weight(&cpumask);
if (num_cpus == 0) {
*power = 0;
return 0;
}
freq = cpufreq_device->freq_table[state];
if (!freq)
return -EINVAL;
dynamic_power = cpu_freq_to_power(cpufreq_device, freq) * num_cpus;
ret = get_static_power(cpufreq_device, tz, freq, &static_power);
if (ret)
return ret;
*power = static_power + dynamic_power;
return 0;
}
static int cpufreq_power2state(struct thermal_cooling_device *cdev,
struct thermal_zone_device *tz, u32 power,
unsigned long *state)
{
unsigned int cpu, cur_freq, target_freq;
int ret;
s32 dyn_power;
u32 last_load, normalised_power, static_power;
struct cpufreq_cooling_device *cpufreq_device = cdev->devdata;
cpu = cpumask_any_and(&cpufreq_device->allowed_cpus, cpu_online_mask);
if (cpu >= nr_cpu_ids)
return -ENODEV;
cur_freq = cpufreq_quick_get(cpu);
ret = get_static_power(cpufreq_device, tz, cur_freq, &static_power);
if (ret)
return ret;
dyn_power = power - static_power;
dyn_power = dyn_power > 0 ? dyn_power : 0;
last_load = cpufreq_device->last_load ?: 1;
normalised_power = (dyn_power * 100) / last_load;
target_freq = cpu_power_to_freq(cpufreq_device, normalised_power);
*state = cpufreq_cooling_get_level(cpu, target_freq);
if (*state == THERMAL_CSTATE_INVALID) {
dev_warn_ratelimited(&cdev->device,
"Failed to convert %dKHz for cpu %d into a cdev state\n",
target_freq, cpu);
return -EINVAL;
}
trace_thermal_power_cpu_limit(&cpufreq_device->allowed_cpus,
target_freq, *state, power);
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
const struct cpumask *clip_cpus, u32 capacitance,
get_static_t plat_static_func)
{
struct thermal_cooling_device *cool_dev;
struct cpufreq_cooling_device *cpufreq_dev;
char dev_name[THERMAL_NAME_LENGTH];
struct cpufreq_frequency_table *pos, *table;
unsigned int freq, i, num_cpus;
int ret;
table = cpufreq_frequency_get_table(cpumask_first(clip_cpus));
if (!table) {
pr_debug("%s: CPUFreq table not found\n", __func__);
return ERR_PTR(-EPROBE_DEFER);
}
cpufreq_dev = kzalloc(sizeof(*cpufreq_dev), GFP_KERNEL);
if (!cpufreq_dev)
return ERR_PTR(-ENOMEM);
num_cpus = cpumask_weight(clip_cpus);
cpufreq_dev->time_in_idle = kcalloc(num_cpus,
sizeof(*cpufreq_dev->time_in_idle),
GFP_KERNEL);
if (!cpufreq_dev->time_in_idle) {
cool_dev = ERR_PTR(-ENOMEM);
goto free_cdev;
}
cpufreq_dev->time_in_idle_timestamp =
kcalloc(num_cpus, sizeof(*cpufreq_dev->time_in_idle_timestamp),
GFP_KERNEL);
if (!cpufreq_dev->time_in_idle_timestamp) {
cool_dev = ERR_PTR(-ENOMEM);
goto free_time_in_idle;
}
cpufreq_for_each_valid_entry(pos, table)
cpufreq_dev->max_level++;
cpufreq_dev->freq_table = kmalloc(sizeof(*cpufreq_dev->freq_table) *
cpufreq_dev->max_level, GFP_KERNEL);
if (!cpufreq_dev->freq_table) {
cool_dev = ERR_PTR(-ENOMEM);
goto free_time_in_idle_timestamp;
}
cpufreq_dev->max_level--;
cpumask_copy(&cpufreq_dev->allowed_cpus, clip_cpus);
if (capacitance) {
cpufreq_cooling_ops.get_requested_power =
cpufreq_get_requested_power;
cpufreq_cooling_ops.state2power = cpufreq_state2power;
cpufreq_cooling_ops.power2state = cpufreq_power2state;
cpufreq_dev->plat_get_static_power = plat_static_func;
ret = build_dyn_power_table(cpufreq_dev, capacitance);
if (ret) {
cool_dev = ERR_PTR(ret);
goto free_table;
}
}
ret = get_idr(&cpufreq_idr, &cpufreq_dev->id);
if (ret) {
cool_dev = ERR_PTR(ret);
goto free_power_table;
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
cpufreq_dev->clipped_freq = cpufreq_dev->freq_table[0];
cpufreq_dev->cool_dev = cool_dev;
mutex_lock(&cooling_cpufreq_lock);
mutex_lock(&cooling_list_lock);
list_add(&cpufreq_dev->node, &cpufreq_dev_list);
mutex_unlock(&cooling_list_lock);
if (!cpufreq_dev_count++)
cpufreq_register_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
mutex_unlock(&cooling_cpufreq_lock);
return cool_dev;
remove_idr:
release_idr(&cpufreq_idr, cpufreq_dev->id);
free_power_table:
kfree(cpufreq_dev->dyn_power_table);
free_table:
kfree(cpufreq_dev->freq_table);
free_time_in_idle_timestamp:
kfree(cpufreq_dev->time_in_idle_timestamp);
free_time_in_idle:
kfree(cpufreq_dev->time_in_idle);
free_cdev:
kfree(cpufreq_dev);
return cool_dev;
}
struct thermal_cooling_device *
cpufreq_cooling_register(const struct cpumask *clip_cpus)
{
return __cpufreq_cooling_register(NULL, clip_cpus, 0, NULL);
}
struct thermal_cooling_device *
of_cpufreq_cooling_register(struct device_node *np,
const struct cpumask *clip_cpus)
{
if (!np)
return ERR_PTR(-EINVAL);
return __cpufreq_cooling_register(np, clip_cpus, 0, NULL);
}
struct thermal_cooling_device *
cpufreq_power_cooling_register(const struct cpumask *clip_cpus, u32 capacitance,
get_static_t plat_static_func)
{
return __cpufreq_cooling_register(NULL, clip_cpus, capacitance,
plat_static_func);
}
struct thermal_cooling_device *
of_cpufreq_power_cooling_register(struct device_node *np,
const struct cpumask *clip_cpus,
u32 capacitance,
get_static_t plat_static_func)
{
if (!np)
return ERR_PTR(-EINVAL);
return __cpufreq_cooling_register(np, clip_cpus, capacitance,
plat_static_func);
}
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
struct cpufreq_cooling_device *cpufreq_dev;
if (!cdev)
return;
cpufreq_dev = cdev->devdata;
mutex_lock(&cooling_cpufreq_lock);
if (!--cpufreq_dev_count)
cpufreq_unregister_notifier(&thermal_cpufreq_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
mutex_lock(&cooling_list_lock);
list_del(&cpufreq_dev->node);
mutex_unlock(&cooling_list_lock);
mutex_unlock(&cooling_cpufreq_lock);
thermal_cooling_device_unregister(cpufreq_dev->cool_dev);
release_idr(&cpufreq_idr, cpufreq_dev->id);
kfree(cpufreq_dev->dyn_power_table);
kfree(cpufreq_dev->time_in_idle_timestamp);
kfree(cpufreq_dev->time_in_idle);
kfree(cpufreq_dev->freq_table);
kfree(cpufreq_dev);
}
