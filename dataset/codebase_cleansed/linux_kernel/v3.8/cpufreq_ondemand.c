static void ondemand_powersave_bias_init_cpu(int cpu)
{
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
dbs_info->freq_table = cpufreq_frequency_get_table(cpu);
dbs_info->freq_lo = 0;
}
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
static unsigned int powersave_bias_target(struct cpufreq_policy *policy,
unsigned int freq_next, unsigned int relation)
{
unsigned int freq_req, freq_reduc, freq_avg;
unsigned int freq_hi, freq_lo;
unsigned int index = 0;
unsigned int jiffies_total, jiffies_hi, jiffies_lo;
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
policy->cpu);
if (!dbs_info->freq_table) {
dbs_info->freq_lo = 0;
dbs_info->freq_lo_jiffies = 0;
return freq_next;
}
cpufreq_frequency_table_target(policy, dbs_info->freq_table, freq_next,
relation, &index);
freq_req = dbs_info->freq_table[index].frequency;
freq_reduc = freq_req * od_tuners.powersave_bias / 1000;
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
dbs_info->freq_lo_jiffies = 0;
return freq_lo;
}
jiffies_total = usecs_to_jiffies(od_tuners.sampling_rate);
jiffies_hi = (freq_avg - freq_lo) * jiffies_total;
jiffies_hi += ((freq_hi - freq_lo) / 2);
jiffies_hi /= (freq_hi - freq_lo);
jiffies_lo = jiffies_total - jiffies_hi;
dbs_info->freq_lo = freq_lo;
dbs_info->freq_lo_jiffies = jiffies_lo;
dbs_info->freq_hi_jiffies = jiffies_hi;
return freq_hi;
}
static void ondemand_powersave_bias_init(void)
{
int i;
for_each_online_cpu(i) {
ondemand_powersave_bias_init_cpu(i);
}
}
static void dbs_freq_increase(struct cpufreq_policy *p, unsigned int freq)
{
if (od_tuners.powersave_bias)
freq = powersave_bias_target(p, freq, CPUFREQ_RELATION_H);
else if (p->cur == p->max)
return;
__cpufreq_driver_target(p, freq, od_tuners.powersave_bias ?
CPUFREQ_RELATION_L : CPUFREQ_RELATION_H);
}
static void od_check_cpu(int cpu, unsigned int load_freq)
{
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
struct cpufreq_policy *policy = dbs_info->cdbs.cur_policy;
dbs_info->freq_lo = 0;
if (load_freq > od_tuners.up_threshold * policy->cur) {
if (policy->cur < policy->max)
dbs_info->rate_mult =
od_tuners.sampling_down_factor;
dbs_freq_increase(policy, policy->max);
return;
}
if (policy->cur == policy->min)
return;
if (load_freq < (od_tuners.up_threshold - od_tuners.down_differential) *
policy->cur) {
unsigned int freq_next;
freq_next = load_freq / (od_tuners.up_threshold -
od_tuners.down_differential);
dbs_info->rate_mult = 1;
if (freq_next < policy->min)
freq_next = policy->min;
if (!od_tuners.powersave_bias) {
__cpufreq_driver_target(policy, freq_next,
CPUFREQ_RELATION_L);
} else {
int freq = powersave_bias_target(policy, freq_next,
CPUFREQ_RELATION_L);
__cpufreq_driver_target(policy, freq,
CPUFREQ_RELATION_L);
}
}
}
static void od_dbs_timer(struct work_struct *work)
{
struct od_cpu_dbs_info_s *dbs_info =
container_of(work, struct od_cpu_dbs_info_s, cdbs.work.work);
unsigned int cpu = dbs_info->cdbs.cpu;
int delay, sample_type = dbs_info->sample_type;
mutex_lock(&dbs_info->cdbs.timer_mutex);
dbs_info->sample_type = OD_NORMAL_SAMPLE;
if (sample_type == OD_SUB_SAMPLE) {
delay = dbs_info->freq_lo_jiffies;
__cpufreq_driver_target(dbs_info->cdbs.cur_policy,
dbs_info->freq_lo, CPUFREQ_RELATION_H);
} else {
dbs_check_cpu(&od_dbs_data, cpu);
if (dbs_info->freq_lo) {
dbs_info->sample_type = OD_SUB_SAMPLE;
delay = dbs_info->freq_hi_jiffies;
} else {
delay = delay_for_sampling_rate(od_tuners.sampling_rate
* dbs_info->rate_mult);
}
}
schedule_delayed_work_on(cpu, &dbs_info->cdbs.work, delay);
mutex_unlock(&dbs_info->cdbs.timer_mutex);
}
static ssize_t show_sampling_rate_min(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", od_dbs_data.min_sampling_rate);
}
static void update_sampling_rate(unsigned int new_rate)
{
int cpu;
od_tuners.sampling_rate = new_rate = max(new_rate,
od_dbs_data.min_sampling_rate);
for_each_online_cpu(cpu) {
struct cpufreq_policy *policy;
struct od_cpu_dbs_info_s *dbs_info;
unsigned long next_sampling, appointed_at;
policy = cpufreq_cpu_get(cpu);
if (!policy)
continue;
if (policy->governor != &cpufreq_gov_ondemand) {
cpufreq_cpu_put(policy);
continue;
}
dbs_info = &per_cpu(od_cpu_dbs_info, policy->cpu);
cpufreq_cpu_put(policy);
mutex_lock(&dbs_info->cdbs.timer_mutex);
if (!delayed_work_pending(&dbs_info->cdbs.work)) {
mutex_unlock(&dbs_info->cdbs.timer_mutex);
continue;
}
next_sampling = jiffies + usecs_to_jiffies(new_rate);
appointed_at = dbs_info->cdbs.work.timer.expires;
if (time_before(next_sampling, appointed_at)) {
mutex_unlock(&dbs_info->cdbs.timer_mutex);
cancel_delayed_work_sync(&dbs_info->cdbs.work);
mutex_lock(&dbs_info->cdbs.timer_mutex);
schedule_delayed_work_on(dbs_info->cdbs.cpu,
&dbs_info->cdbs.work,
usecs_to_jiffies(new_rate));
}
mutex_unlock(&dbs_info->cdbs.timer_mutex);
}
}
static ssize_t store_sampling_rate(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
update_sampling_rate(input);
return count;
}
static ssize_t store_io_is_busy(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
od_tuners.io_is_busy = !!input;
return count;
}
static ssize_t store_up_threshold(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_FREQUENCY_UP_THRESHOLD ||
input < MIN_FREQUENCY_UP_THRESHOLD) {
return -EINVAL;
}
od_tuners.up_threshold = input;
return count;
}
static ssize_t store_sampling_down_factor(struct kobject *a,
struct attribute *b, const char *buf, size_t count)
{
unsigned int input, j;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
od_tuners.sampling_down_factor = input;
for_each_online_cpu(j) {
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
j);
dbs_info->rate_mult = 1;
}
return count;
}
static ssize_t store_ignore_nice_load(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
unsigned int j;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1)
input = 1;
if (input == od_tuners.ignore_nice) {
return count;
}
od_tuners.ignore_nice = input;
for_each_online_cpu(j) {
struct od_cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(od_cpu_dbs_info, j);
dbs_info->cdbs.prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->cdbs.prev_cpu_wall);
if (od_tuners.ignore_nice)
dbs_info->cdbs.prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
return count;
}
static ssize_t store_powersave_bias(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1000)
input = 1000;
od_tuners.powersave_bias = input;
ondemand_powersave_bias_init();
return count;
}
static int od_cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
return cpufreq_governor_dbs(&od_dbs_data, policy, event);
}
static int __init cpufreq_gov_dbs_init(void)
{
u64 idle_time;
int cpu = get_cpu();
mutex_init(&od_dbs_data.mutex);
idle_time = get_cpu_idle_time_us(cpu, NULL);
put_cpu();
if (idle_time != -1ULL) {
od_tuners.up_threshold = MICRO_FREQUENCY_UP_THRESHOLD;
od_tuners.down_differential = MICRO_FREQUENCY_DOWN_DIFFERENTIAL;
od_dbs_data.min_sampling_rate = MICRO_FREQUENCY_MIN_SAMPLE_RATE;
} else {
od_dbs_data.min_sampling_rate = MIN_SAMPLING_RATE_RATIO *
jiffies_to_usecs(10);
}
return cpufreq_register_governor(&cpufreq_gov_ondemand);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_ondemand);
}
