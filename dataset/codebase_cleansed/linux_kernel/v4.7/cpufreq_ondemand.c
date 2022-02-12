static int should_io_be_busy(void)
{
#if defined(CONFIG_X86)
if (boot_cpu_data.x86_vendor == X86_VENDOR_INTEL &&
boot_cpu_data.x86 == 6 &&
boot_cpu_data.x86_model >= 15)
return 1;
#endif
return 0;
}
static unsigned int generic_powersave_bias_target(struct cpufreq_policy *policy,
unsigned int freq_next, unsigned int relation)
{
unsigned int freq_req, freq_reduc, freq_avg;
unsigned int freq_hi, freq_lo;
unsigned int index = 0;
unsigned int delay_hi_us;
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct od_policy_dbs_info *dbs_info = to_dbs_info(policy_dbs);
struct dbs_data *dbs_data = policy_dbs->dbs_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
if (!dbs_info->freq_table) {
dbs_info->freq_lo = 0;
dbs_info->freq_lo_delay_us = 0;
return freq_next;
}
cpufreq_frequency_table_target(policy, dbs_info->freq_table, freq_next,
relation, &index);
freq_req = dbs_info->freq_table[index].frequency;
freq_reduc = freq_req * od_tuners->powersave_bias / 1000;
freq_avg = freq_req - freq_reduc;
index = 0;
cpufreq_frequency_table_target(policy, dbs_info->freq_table, freq_avg,
CPUFREQ_RELATION_H, &index);
freq_lo = dbs_info->freq_table[index].frequency;
index = 0;
cpufreq_frequency_table_target(policy, dbs_info->freq_table, freq_avg,
CPUFREQ_RELATION_L, &index);
freq_hi = dbs_info->freq_table[index].frequency;
if (freq_hi == freq_lo) {
dbs_info->freq_lo = 0;
dbs_info->freq_lo_delay_us = 0;
return freq_lo;
}
delay_hi_us = (freq_avg - freq_lo) * dbs_data->sampling_rate;
delay_hi_us += (freq_hi - freq_lo) / 2;
delay_hi_us /= freq_hi - freq_lo;
dbs_info->freq_hi_delay_us = delay_hi_us;
dbs_info->freq_lo = freq_lo;
dbs_info->freq_lo_delay_us = dbs_data->sampling_rate - delay_hi_us;
return freq_hi;
}
static void ondemand_powersave_bias_init(struct cpufreq_policy *policy)
{
struct od_policy_dbs_info *dbs_info = to_dbs_info(policy->governor_data);
dbs_info->freq_table = cpufreq_frequency_get_table(policy->cpu);
dbs_info->freq_lo = 0;
}
static void dbs_freq_increase(struct cpufreq_policy *policy, unsigned int freq)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
if (od_tuners->powersave_bias)
freq = od_ops.powersave_bias_target(policy, freq,
CPUFREQ_RELATION_H);
else if (policy->cur == policy->max)
return;
__cpufreq_driver_target(policy, freq, od_tuners->powersave_bias ?
CPUFREQ_RELATION_L : CPUFREQ_RELATION_H);
}
static void od_update(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct od_policy_dbs_info *dbs_info = to_dbs_info(policy_dbs);
struct dbs_data *dbs_data = policy_dbs->dbs_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int load = dbs_update(policy);
dbs_info->freq_lo = 0;
if (load > dbs_data->up_threshold) {
if (policy->cur < policy->max)
policy_dbs->rate_mult = dbs_data->sampling_down_factor;
dbs_freq_increase(policy, policy->max);
} else {
unsigned int freq_next, min_f, max_f;
min_f = policy->cpuinfo.min_freq;
max_f = policy->cpuinfo.max_freq;
freq_next = min_f + load * (max_f - min_f) / 100;
policy_dbs->rate_mult = 1;
if (od_tuners->powersave_bias)
freq_next = od_ops.powersave_bias_target(policy,
freq_next,
CPUFREQ_RELATION_L);
__cpufreq_driver_target(policy, freq_next, CPUFREQ_RELATION_C);
}
}
static unsigned int od_dbs_timer(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *dbs_data = policy_dbs->dbs_data;
struct od_policy_dbs_info *dbs_info = to_dbs_info(policy_dbs);
int sample_type = dbs_info->sample_type;
dbs_info->sample_type = OD_NORMAL_SAMPLE;
if (sample_type == OD_SUB_SAMPLE && policy_dbs->sample_delay_ns > 0) {
__cpufreq_driver_target(policy, dbs_info->freq_lo,
CPUFREQ_RELATION_H);
return dbs_info->freq_lo_delay_us;
}
od_update(policy);
if (dbs_info->freq_lo) {
dbs_info->sample_type = OD_SUB_SAMPLE;
return dbs_info->freq_hi_delay_us;
}
return dbs_data->sampling_rate * policy_dbs->rate_mult;
}
static ssize_t store_io_is_busy(struct gov_attr_set *attr_set, const char *buf,
size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
dbs_data->io_is_busy = !!input;
gov_update_cpu_data(dbs_data);
return count;
}
static ssize_t store_up_threshold(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_FREQUENCY_UP_THRESHOLD ||
input < MIN_FREQUENCY_UP_THRESHOLD) {
return -EINVAL;
}
dbs_data->up_threshold = input;
return count;
}
static ssize_t store_sampling_down_factor(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
struct policy_dbs_info *policy_dbs;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
dbs_data->sampling_down_factor = input;
list_for_each_entry(policy_dbs, &attr_set->policy_list, list) {
mutex_lock(&policy_dbs->timer_mutex);
policy_dbs->rate_mult = 1;
mutex_unlock(&policy_dbs->timer_mutex);
}
return count;
}
static ssize_t store_ignore_nice_load(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1)
input = 1;
if (input == dbs_data->ignore_nice_load) {
return count;
}
dbs_data->ignore_nice_load = input;
gov_update_cpu_data(dbs_data);
return count;
}
static ssize_t store_powersave_bias(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
struct policy_dbs_info *policy_dbs;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1000)
input = 1000;
od_tuners->powersave_bias = input;
list_for_each_entry(policy_dbs, &attr_set->policy_list, list)
ondemand_powersave_bias_init(policy_dbs->policy);
return count;
}
static struct policy_dbs_info *od_alloc(void)
{
struct od_policy_dbs_info *dbs_info;
dbs_info = kzalloc(sizeof(*dbs_info), GFP_KERNEL);
return dbs_info ? &dbs_info->policy_dbs : NULL;
}
static void od_free(struct policy_dbs_info *policy_dbs)
{
kfree(to_dbs_info(policy_dbs));
}
static int od_init(struct dbs_data *dbs_data, bool notify)
{
struct od_dbs_tuners *tuners;
u64 idle_time;
int cpu;
tuners = kzalloc(sizeof(*tuners), GFP_KERNEL);
if (!tuners) {
pr_err("%s: kzalloc failed\n", __func__);
return -ENOMEM;
}
cpu = get_cpu();
idle_time = get_cpu_idle_time_us(cpu, NULL);
put_cpu();
if (idle_time != -1ULL) {
dbs_data->up_threshold = MICRO_FREQUENCY_UP_THRESHOLD;
dbs_data->min_sampling_rate = MICRO_FREQUENCY_MIN_SAMPLE_RATE;
} else {
dbs_data->up_threshold = DEF_FREQUENCY_UP_THRESHOLD;
dbs_data->min_sampling_rate = MIN_SAMPLING_RATE_RATIO *
jiffies_to_usecs(10);
}
dbs_data->sampling_down_factor = DEF_SAMPLING_DOWN_FACTOR;
dbs_data->ignore_nice_load = 0;
tuners->powersave_bias = default_powersave_bias;
dbs_data->io_is_busy = should_io_be_busy();
dbs_data->tuners = tuners;
return 0;
}
static void od_exit(struct dbs_data *dbs_data, bool notify)
{
kfree(dbs_data->tuners);
}
static void od_start(struct cpufreq_policy *policy)
{
struct od_policy_dbs_info *dbs_info = to_dbs_info(policy->governor_data);
dbs_info->sample_type = OD_NORMAL_SAMPLE;
ondemand_powersave_bias_init(policy);
}
static void od_set_powersave_bias(unsigned int powersave_bias)
{
unsigned int cpu;
cpumask_t done;
default_powersave_bias = powersave_bias;
cpumask_clear(&done);
get_online_cpus();
for_each_online_cpu(cpu) {
struct cpufreq_policy *policy;
struct policy_dbs_info *policy_dbs;
struct dbs_data *dbs_data;
struct od_dbs_tuners *od_tuners;
if (cpumask_test_cpu(cpu, &done))
continue;
policy = cpufreq_cpu_get_raw(cpu);
if (!policy || policy->governor != CPU_FREQ_GOV_ONDEMAND)
continue;
policy_dbs = policy->governor_data;
if (!policy_dbs)
continue;
cpumask_or(&done, &done, policy->cpus);
dbs_data = policy_dbs->dbs_data;
od_tuners = dbs_data->tuners;
od_tuners->powersave_bias = default_powersave_bias;
}
put_online_cpus();
}
void od_unregister_powersave_bias_handler(void)
{
od_ops.powersave_bias_target = generic_powersave_bias_target;
od_set_powersave_bias(0);
}
static int __init cpufreq_gov_dbs_init(void)
{
return cpufreq_register_governor(CPU_FREQ_GOV_ONDEMAND);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(CPU_FREQ_GOV_ONDEMAND);
}
struct cpufreq_governor *cpufreq_default_governor(void)
{
return CPU_FREQ_GOV_ONDEMAND;
}
