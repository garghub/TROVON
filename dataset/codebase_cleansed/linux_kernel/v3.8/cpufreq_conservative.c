static void cs_check_cpu(int cpu, unsigned int load)
{
struct cs_cpu_dbs_info_s *dbs_info = &per_cpu(cs_cpu_dbs_info, cpu);
struct cpufreq_policy *policy = dbs_info->cdbs.cur_policy;
unsigned int freq_target;
if (cs_tuners.freq_step == 0)
return;
if (load > cs_tuners.up_threshold) {
dbs_info->down_skip = 0;
if (dbs_info->requested_freq == policy->max)
return;
freq_target = (cs_tuners.freq_step * policy->max) / 100;
if (unlikely(freq_target == 0))
freq_target = 5;
dbs_info->requested_freq += freq_target;
if (dbs_info->requested_freq > policy->max)
dbs_info->requested_freq = policy->max;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_H);
return;
}
if (load < (cs_tuners.down_threshold - 10)) {
freq_target = (cs_tuners.freq_step * policy->max) / 100;
dbs_info->requested_freq -= freq_target;
if (dbs_info->requested_freq < policy->min)
dbs_info->requested_freq = policy->min;
if (policy->cur == policy->min)
return;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_H);
return;
}
}
static void cs_dbs_timer(struct work_struct *work)
{
struct cs_cpu_dbs_info_s *dbs_info = container_of(work,
struct cs_cpu_dbs_info_s, cdbs.work.work);
unsigned int cpu = dbs_info->cdbs.cpu;
int delay = delay_for_sampling_rate(cs_tuners.sampling_rate);
mutex_lock(&dbs_info->cdbs.timer_mutex);
dbs_check_cpu(&cs_dbs_data, cpu);
schedule_delayed_work_on(cpu, &dbs_info->cdbs.work, delay);
mutex_unlock(&dbs_info->cdbs.timer_mutex);
}
static int dbs_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
struct cs_cpu_dbs_info_s *dbs_info =
&per_cpu(cs_cpu_dbs_info, freq->cpu);
struct cpufreq_policy *policy;
if (!dbs_info->enable)
return 0;
policy = dbs_info->cdbs.cur_policy;
if (dbs_info->requested_freq > policy->max
|| dbs_info->requested_freq < policy->min)
dbs_info->requested_freq = freq->new;
return 0;
}
static ssize_t show_sampling_rate_min(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", cs_dbs_data.min_sampling_rate);
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
cs_tuners.sampling_down_factor = input;
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
cs_tuners.sampling_rate = max(input, cs_dbs_data.min_sampling_rate);
return count;
}
static ssize_t store_up_threshold(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > 100 || input <= cs_tuners.down_threshold)
return -EINVAL;
cs_tuners.up_threshold = input;
return count;
}
static ssize_t store_down_threshold(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input < 11 || input > 100 ||
input >= cs_tuners.up_threshold)
return -EINVAL;
cs_tuners.down_threshold = input;
return count;
}
static ssize_t store_ignore_nice_load(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input, j;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1)
input = 1;
if (input == cs_tuners.ignore_nice)
return count;
cs_tuners.ignore_nice = input;
for_each_online_cpu(j) {
struct cs_cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(cs_cpu_dbs_info, j);
dbs_info->cdbs.prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->cdbs.prev_cpu_wall);
if (cs_tuners.ignore_nice)
dbs_info->cdbs.prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
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
cs_tuners.freq_step = input;
return count;
}
static int cs_cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
return cpufreq_governor_dbs(&cs_dbs_data, policy, event);
}
static int __init cpufreq_gov_dbs_init(void)
{
mutex_init(&cs_dbs_data.mutex);
return cpufreq_register_governor(&cpufreq_gov_conservative);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_conservative);
}
