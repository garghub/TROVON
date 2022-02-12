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
*wall = jiffies_to_usecs(cur_wall_time);
return jiffies_to_usecs(idle_time);
}
static inline cputime64_t get_cpu_idle_time(unsigned int cpu, cputime64_t *wall)
{
u64 idle_time = get_cpu_idle_time_us(cpu, NULL);
if (idle_time == -1ULL)
return get_cpu_idle_time_jiffy(cpu, wall);
else
idle_time += get_cpu_iowait_time_us(cpu, wall);
return idle_time;
}
static int
dbs_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
struct cpu_dbs_info_s *this_dbs_info = &per_cpu(cs_cpu_dbs_info,
freq->cpu);
struct cpufreq_policy *policy;
if (!this_dbs_info->enable)
return 0;
policy = this_dbs_info->cur_policy;
if (this_dbs_info->requested_freq > policy->max
|| this_dbs_info->requested_freq < policy->min)
this_dbs_info->requested_freq = freq->new;
return 0;
}
static ssize_t show_sampling_rate_min(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", min_sampling_rate);
}
static ssize_t store_sampling_down_factor(struct kobject *a,
struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
dbs_tuners_ins.sampling_down_factor = input;
return count;
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
static ssize_t store_up_threshold(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > 100 ||
input <= dbs_tuners_ins.down_threshold)
return -EINVAL;
dbs_tuners_ins.up_threshold = input;
return count;
}
static ssize_t store_down_threshold(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input < 11 || input > 100 ||
input >= dbs_tuners_ins.up_threshold)
return -EINVAL;
dbs_tuners_ins.down_threshold = input;
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
if (input == dbs_tuners_ins.ignore_nice)
return count;
dbs_tuners_ins.ignore_nice = input;
for_each_online_cpu(j) {
struct cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(cs_cpu_dbs_info, j);
dbs_info->prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->prev_cpu_wall);
if (dbs_tuners_ins.ignore_nice)
dbs_info->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
return count;
}
static ssize_t store_freq_step(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 100)
input = 100;
dbs_tuners_ins.freq_step = input;
return count;
}
static void dbs_check_cpu(struct cpu_dbs_info_s *this_dbs_info)
{
unsigned int load = 0;
unsigned int max_load = 0;
unsigned int freq_target;
struct cpufreq_policy *policy;
unsigned int j;
policy = this_dbs_info->cur_policy;
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info_s *j_dbs_info;
cputime64_t cur_wall_time, cur_idle_time;
unsigned int idle_time, wall_time;
j_dbs_info = &per_cpu(cs_cpu_dbs_info, j);
cur_idle_time = get_cpu_idle_time(j, &cur_wall_time);
wall_time = (unsigned int)
(cur_wall_time - j_dbs_info->prev_cpu_wall);
j_dbs_info->prev_cpu_wall = cur_wall_time;
idle_time = (unsigned int)
(cur_idle_time - j_dbs_info->prev_cpu_idle);
j_dbs_info->prev_cpu_idle = cur_idle_time;
if (dbs_tuners_ins.ignore_nice) {
u64 cur_nice;
unsigned long cur_nice_jiffies;
cur_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE] -
j_dbs_info->prev_cpu_nice;
cur_nice_jiffies = (unsigned long)
cputime64_to_jiffies64(cur_nice);
j_dbs_info->prev_cpu_nice = kcpustat_cpu(j).cpustat[CPUTIME_NICE];
idle_time += jiffies_to_usecs(cur_nice_jiffies);
}
if (unlikely(!wall_time || wall_time < idle_time))
continue;
load = 100 * (wall_time - idle_time) / wall_time;
if (load > max_load)
max_load = load;
}
if (dbs_tuners_ins.freq_step == 0)
return;
if (max_load > dbs_tuners_ins.up_threshold) {
this_dbs_info->down_skip = 0;
if (this_dbs_info->requested_freq == policy->max)
return;
freq_target = (dbs_tuners_ins.freq_step * policy->max) / 100;
if (unlikely(freq_target == 0))
freq_target = 5;
this_dbs_info->requested_freq += freq_target;
if (this_dbs_info->requested_freq > policy->max)
this_dbs_info->requested_freq = policy->max;
__cpufreq_driver_target(policy, this_dbs_info->requested_freq,
CPUFREQ_RELATION_H);
return;
}
if (max_load < (dbs_tuners_ins.down_threshold - 10)) {
freq_target = (dbs_tuners_ins.freq_step * policy->max) / 100;
this_dbs_info->requested_freq -= freq_target;
if (this_dbs_info->requested_freq < policy->min)
this_dbs_info->requested_freq = policy->min;
if (policy->cur == policy->min)
return;
__cpufreq_driver_target(policy, this_dbs_info->requested_freq,
CPUFREQ_RELATION_H);
return;
}
}
static void do_dbs_timer(struct work_struct *work)
{
struct cpu_dbs_info_s *dbs_info =
container_of(work, struct cpu_dbs_info_s, work.work);
unsigned int cpu = dbs_info->cpu;
int delay = usecs_to_jiffies(dbs_tuners_ins.sampling_rate);
delay -= jiffies % delay;
mutex_lock(&dbs_info->timer_mutex);
dbs_check_cpu(dbs_info);
schedule_delayed_work_on(cpu, &dbs_info->work, delay);
mutex_unlock(&dbs_info->timer_mutex);
}
static inline void dbs_timer_init(struct cpu_dbs_info_s *dbs_info)
{
int delay = usecs_to_jiffies(dbs_tuners_ins.sampling_rate);
delay -= jiffies % delay;
dbs_info->enable = 1;
INIT_DEFERRABLE_WORK(&dbs_info->work, do_dbs_timer);
schedule_delayed_work_on(dbs_info->cpu, &dbs_info->work, delay);
}
static inline void dbs_timer_exit(struct cpu_dbs_info_s *dbs_info)
{
dbs_info->enable = 0;
cancel_delayed_work_sync(&dbs_info->work);
}
static int cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
unsigned int cpu = policy->cpu;
struct cpu_dbs_info_s *this_dbs_info;
unsigned int j;
int rc;
this_dbs_info = &per_cpu(cs_cpu_dbs_info, cpu);
switch (event) {
case CPUFREQ_GOV_START:
if ((!cpu_online(cpu)) || (!policy->cur))
return -EINVAL;
mutex_lock(&dbs_mutex);
for_each_cpu(j, policy->cpus) {
struct cpu_dbs_info_s *j_dbs_info;
j_dbs_info = &per_cpu(cs_cpu_dbs_info, j);
j_dbs_info->cur_policy = policy;
j_dbs_info->prev_cpu_idle = get_cpu_idle_time(j,
&j_dbs_info->prev_cpu_wall);
if (dbs_tuners_ins.ignore_nice)
j_dbs_info->prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
this_dbs_info->cpu = cpu;
this_dbs_info->down_skip = 0;
this_dbs_info->requested_freq = policy->cur;
mutex_init(&this_dbs_info->timer_mutex);
dbs_enable++;
if (dbs_enable == 1) {
unsigned int latency;
latency = policy->cpuinfo.transition_latency / 1000;
if (latency == 0)
latency = 1;
rc = sysfs_create_group(cpufreq_global_kobject,
&dbs_attr_group);
if (rc) {
mutex_unlock(&dbs_mutex);
return rc;
}
min_sampling_rate =
MIN_SAMPLING_RATE_RATIO * jiffies_to_usecs(10);
min_sampling_rate = max(min_sampling_rate,
MIN_LATENCY_MULTIPLIER * latency);
dbs_tuners_ins.sampling_rate =
max(min_sampling_rate,
latency * LATENCY_MULTIPLIER);
cpufreq_register_notifier(
&dbs_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
mutex_unlock(&dbs_mutex);
dbs_timer_init(this_dbs_info);
break;
case CPUFREQ_GOV_STOP:
dbs_timer_exit(this_dbs_info);
mutex_lock(&dbs_mutex);
dbs_enable--;
mutex_destroy(&this_dbs_info->timer_mutex);
if (dbs_enable == 0)
cpufreq_unregister_notifier(
&dbs_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
mutex_unlock(&dbs_mutex);
if (!dbs_enable)
sysfs_remove_group(cpufreq_global_kobject,
&dbs_attr_group);
break;
case CPUFREQ_GOV_LIMITS:
mutex_lock(&this_dbs_info->timer_mutex);
if (policy->max < this_dbs_info->cur_policy->cur)
__cpufreq_driver_target(
this_dbs_info->cur_policy,
policy->max, CPUFREQ_RELATION_H);
else if (policy->min > this_dbs_info->cur_policy->cur)
__cpufreq_driver_target(
this_dbs_info->cur_policy,
policy->min, CPUFREQ_RELATION_L);
dbs_check_cpu(this_dbs_info);
mutex_unlock(&this_dbs_info->timer_mutex);
break;
}
return 0;
}
static int __init cpufreq_gov_dbs_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_conservative);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_conservative);
}
