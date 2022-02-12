static inline cputime64_t get_cpu_idle_time_jiffy(unsigned int cpu,
cputime64_t *wall)
{
cputime64_t idle_time;
cputime64_t cur_wall_time;
cputime64_t busy_time;
cur_wall_time = jiffies64_to_cputime64(get_jiffies_64());
busy_time = cputime64_add(kstat_cpu(cpu).cpustat.user,
kstat_cpu(cpu).cpustat.system);
busy_time = cputime64_add(busy_time, kstat_cpu(cpu).cpustat.irq);
busy_time = cputime64_add(busy_time, kstat_cpu(cpu).cpustat.softirq);
busy_time = cputime64_add(busy_time, kstat_cpu(cpu).cpustat.steal);
busy_time = cputime64_add(busy_time, kstat_cpu(cpu).cpustat.nice);
idle_time = cputime64_sub(cur_wall_time, busy_time);
if (wall)
*wall = (cputime64_t)jiffies_to_usecs(cur_wall_time);
return (cputime64_t)jiffies_to_usecs(idle_time);
}
static inline cputime64_t get_cpu_idle_time(unsigned int cpu, cputime64_t *wall)
{
u64 idle_time = get_cpu_idle_time_us(cpu, wall);
if (idle_time == -1ULL)
return get_cpu_idle_time_jiffy(cpu, wall);
return idle_time;
}
static inline cputime64_t get_cpu_iowait_time(unsigned int cpu, cputime64_t *wall)
{
u64 iowait_time = get_cpu_iowait_time_us(cpu, wall);
if (iowait_time == -1ULL)
return 0;
return iowait_time;
}
static unsigned int powersave_bias_target(struct cpufreq_policy *policy,
unsigned int freq_next,
unsigned int relation)
{
unsigned int freq_req, freq_reduc, freq_avg;
unsigned int freq_hi, freq_lo;
unsigned int index = 0;
unsigned int jiffies_total, jiffies_hi, jiffies_lo;
struct cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
policy->cpu);
if (!dbs_info->freq_table) {
dbs_info->freq_lo = 0;
dbs_info->freq_lo_jiffies = 0;
return freq_next;
}
cpufreq_frequency_table_target(policy, dbs_info->freq_table, freq_next,
relation, &index);
freq_req = dbs_info->freq_table[index].frequency;
freq_reduc = freq_req * dbs_tuners_ins.powersave_bias / 1000;
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
jiffies_total = usecs_to_jiffies(dbs_tuners_ins.sampling_rate);
jiffies_hi = (freq_avg - freq_lo) * jiffies_total;
jiffies_hi += ((freq_hi - freq_lo) / 2);
jiffies_hi /= (freq_hi - freq_lo);
jiffies_lo = jiffies_total - jiffies_hi;
dbs_info->freq_lo = freq_lo;
dbs_info->freq_lo_jiffies = jiffies_lo;
dbs_info->freq_hi_jiffies = jiffies_hi;
return freq_hi;
}
static void ondemand_powersave_bias_init_cpu(int cpu)
{
struct cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
dbs_info->freq_table = cpufreq_frequency_get_table(cpu);
dbs_info->freq_lo = 0;
}
static void ondemand_powersave_bias_init(void)
{
int i;
for_each_online_cpu(i) {
ondemand_powersave_bias_init_cpu(i);
}
}
static ssize_t show_sampling_rate_min(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", min_sampling_rate);
}
static ssize_t store_sampling_rate(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
dbs_tuners_ins.sampling_rate = max(input, min_sampling_rate);
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
dbs_tuners_ins.io_is_busy = !!input;
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
dbs_tuners_ins.up_threshold = input;
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
dbs_tuners_ins.sampling_down_factor = input;
for_each_online_cpu(j) {
struct cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(od_cpu_dbs_info, j);
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
if (input == dbs_tuners_ins.ignore_nice) {
return count;
}
dbs_tuners_ins.ignore_nice = input;
for_each_online_cpu(j) {
struct cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(od_cpu_dbs_info, j);
dbs_info->prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->prev_cpu_wall);
if (dbs_tuners_ins.ignore_nice)
dbs_info->prev_cpu_nice = kstat_cpu(j).cpustat.nice;
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
dbs_tuners_ins.powersave_bias = input;
ondemand_powersave_bias_init();
return count;
}
static void dbs_freq_increase(struct cpufreq_policy *p, unsigned int freq)
{
if (dbs_tuners_ins.powersave_bias)
freq = powersave_bias_target(p, freq, CPUFREQ_RELATION_H);
else if (p->cur == p->max)
return;
__cpufreq_driver_target(p, freq, dbs_tuners_ins.powersave_bias ?
CPUFREQ_RELATION_L : CPUFREQ_RELATION_H);
}
static void dbs_check_cpu(struct cpu_dbs_info_s *this_dbs_info)
{
unsigned int max_load_freq;
struct cpufreq_policy *policy;
unsigned int j;
this_dbs_info->freq_lo = 0;
policy = this_dbs_info->cur_policy;
max_load_freq = 0;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info_s *j_dbs_info;
cputime64_t cur_wall_time, cur_idle_time, cur_iowait_time;
unsigned int idle_time, wall_time, iowait_time;
unsigned int load, load_freq;
int freq_avg;
j_dbs_info = &per_cpu(od_cpu_dbs_info, j);
cur_idle_time = get_cpu_idle_time(j, &cur_wall_time);
cur_iowait_time = get_cpu_iowait_time(j, &cur_wall_time);
wall_time = (unsigned int) cputime64_sub(cur_wall_time,
j_dbs_info->prev_cpu_wall);
j_dbs_info->prev_cpu_wall = cur_wall_time;
idle_time = (unsigned int) cputime64_sub(cur_idle_time,
j_dbs_info->prev_cpu_idle);
j_dbs_info->prev_cpu_idle = cur_idle_time;
iowait_time = (unsigned int) cputime64_sub(cur_iowait_time,
j_dbs_info->prev_cpu_iowait);
j_dbs_info->prev_cpu_iowait = cur_iowait_time;
if (dbs_tuners_ins.ignore_nice) {
cputime64_t cur_nice;
unsigned long cur_nice_jiffies;
cur_nice = cputime64_sub(kstat_cpu(j).cpustat.nice,
j_dbs_info->prev_cpu_nice);
cur_nice_jiffies = (unsigned long)
cputime64_to_jiffies64(cur_nice);
j_dbs_info->prev_cpu_nice = kstat_cpu(j).cpustat.nice;
idle_time += jiffies_to_usecs(cur_nice_jiffies);
}
if (dbs_tuners_ins.io_is_busy && idle_time >= iowait_time)
idle_time -= iowait_time;
if (unlikely(!wall_time || wall_time < idle_time))
continue;
load = 100 * (wall_time - idle_time) / wall_time;
freq_avg = __cpufreq_driver_getavg(policy, j);
if (freq_avg <= 0)
freq_avg = policy->cur;
load_freq = load * freq_avg;
if (load_freq > max_load_freq)
max_load_freq = load_freq;
}
if (max_load_freq > dbs_tuners_ins.up_threshold * policy->cur) {
if (policy->cur < policy->max)
this_dbs_info->rate_mult =
dbs_tuners_ins.sampling_down_factor;
dbs_freq_increase(policy, policy->max);
return;
}
if (policy->cur == policy->min)
return;
if (max_load_freq <
(dbs_tuners_ins.up_threshold - dbs_tuners_ins.down_differential) *
policy->cur) {
unsigned int freq_next;
freq_next = max_load_freq /
(dbs_tuners_ins.up_threshold -
dbs_tuners_ins.down_differential);
this_dbs_info->rate_mult = 1;
if (freq_next < policy->min)
freq_next = policy->min;
if (!dbs_tuners_ins.powersave_bias) {
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
static void do_dbs_timer(struct work_struct *work)
{
struct cpu_dbs_info_s *dbs_info =
container_of(work, struct cpu_dbs_info_s, work.work);
unsigned int cpu = dbs_info->cpu;
int sample_type = dbs_info->sample_type;
int delay;
mutex_lock(&dbs_info->timer_mutex);
dbs_info->sample_type = DBS_NORMAL_SAMPLE;
if (!dbs_tuners_ins.powersave_bias ||
sample_type == DBS_NORMAL_SAMPLE) {
dbs_check_cpu(dbs_info);
if (dbs_info->freq_lo) {
dbs_info->sample_type = DBS_SUB_SAMPLE;
delay = dbs_info->freq_hi_jiffies;
} else {
delay = usecs_to_jiffies(dbs_tuners_ins.sampling_rate
* dbs_info->rate_mult);
if (num_online_cpus() > 1)
delay -= jiffies % delay;
}
} else {
__cpufreq_driver_target(dbs_info->cur_policy,
dbs_info->freq_lo, CPUFREQ_RELATION_H);
delay = dbs_info->freq_lo_jiffies;
}
schedule_delayed_work_on(cpu, &dbs_info->work, delay);
mutex_unlock(&dbs_info->timer_mutex);
}
static inline void dbs_timer_init(struct cpu_dbs_info_s *dbs_info)
{
int delay = usecs_to_jiffies(dbs_tuners_ins.sampling_rate);
if (num_online_cpus() > 1)
delay -= jiffies % delay;
dbs_info->sample_type = DBS_NORMAL_SAMPLE;
INIT_DELAYED_WORK_DEFERRABLE(&dbs_info->work, do_dbs_timer);
schedule_delayed_work_on(dbs_info->cpu, &dbs_info->work, delay);
}
static inline void dbs_timer_exit(struct cpu_dbs_info_s *dbs_info)
{
cancel_delayed_work_sync(&dbs_info->work);
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
static int cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
unsigned int cpu = policy->cpu;
struct cpu_dbs_info_s *this_dbs_info;
unsigned int j;
int rc;
this_dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
switch (event) {
case CPUFREQ_GOV_START:
if ((!cpu_online(cpu)) || (!policy->cur))
return -EINVAL;
mutex_lock(&dbs_mutex);
dbs_enable++;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info_s *j_dbs_info;
j_dbs_info = &per_cpu(od_cpu_dbs_info, j);
j_dbs_info->cur_policy = policy;
j_dbs_info->prev_cpu_idle = get_cpu_idle_time(j,
&j_dbs_info->prev_cpu_wall);
if (dbs_tuners_ins.ignore_nice) {
j_dbs_info->prev_cpu_nice =
kstat_cpu(j).cpustat.nice;
}
}
this_dbs_info->cpu = cpu;
this_dbs_info->rate_mult = 1;
ondemand_powersave_bias_init_cpu(cpu);
if (dbs_enable == 1) {
unsigned int latency;
rc = sysfs_create_group(cpufreq_global_kobject,
&dbs_attr_group);
if (rc) {
mutex_unlock(&dbs_mutex);
return rc;
}
latency = policy->cpuinfo.transition_latency / 1000;
if (latency == 0)
latency = 1;
min_sampling_rate = max(min_sampling_rate,
MIN_LATENCY_MULTIPLIER * latency);
dbs_tuners_ins.sampling_rate =
max(min_sampling_rate,
latency * LATENCY_MULTIPLIER);
dbs_tuners_ins.io_is_busy = should_io_be_busy();
}
mutex_unlock(&dbs_mutex);
mutex_init(&this_dbs_info->timer_mutex);
dbs_timer_init(this_dbs_info);
break;
case CPUFREQ_GOV_STOP:
dbs_timer_exit(this_dbs_info);
mutex_lock(&dbs_mutex);
mutex_destroy(&this_dbs_info->timer_mutex);
dbs_enable--;
mutex_unlock(&dbs_mutex);
if (!dbs_enable)
sysfs_remove_group(cpufreq_global_kobject,
&dbs_attr_group);
break;
case CPUFREQ_GOV_LIMITS:
mutex_lock(&this_dbs_info->timer_mutex);
if (policy->max < this_dbs_info->cur_policy->cur)
__cpufreq_driver_target(this_dbs_info->cur_policy,
policy->max, CPUFREQ_RELATION_H);
else if (policy->min > this_dbs_info->cur_policy->cur)
__cpufreq_driver_target(this_dbs_info->cur_policy,
policy->min, CPUFREQ_RELATION_L);
mutex_unlock(&this_dbs_info->timer_mutex);
break;
}
return 0;
}
static int __init cpufreq_gov_dbs_init(void)
{
cputime64_t wall;
u64 idle_time;
int cpu = get_cpu();
idle_time = get_cpu_idle_time_us(cpu, &wall);
put_cpu();
if (idle_time != -1ULL) {
dbs_tuners_ins.up_threshold = MICRO_FREQUENCY_UP_THRESHOLD;
dbs_tuners_ins.down_differential =
MICRO_FREQUENCY_DOWN_DIFFERENTIAL;
min_sampling_rate = MICRO_FREQUENCY_MIN_SAMPLE_RATE;
} else {
min_sampling_rate =
MIN_SAMPLING_RATE_RATIO * jiffies_to_usecs(10);
}
return cpufreq_register_governor(&cpufreq_gov_ondemand);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_ondemand);
}
