static inline unsigned int get_freq_target(struct cs_dbs_tuners *cs_tuners,
struct cpufreq_policy *policy)
{
unsigned int freq_target = (cs_tuners->freq_step * policy->max) / 100;
if (unlikely(freq_target == 0))
freq_target = DEF_FREQUENCY_STEP;
return freq_target;
}
static void cs_check_cpu(int cpu, unsigned int load)
{
struct cs_cpu_dbs_info_s *dbs_info = &per_cpu(cs_cpu_dbs_info, cpu);
struct cpufreq_policy *policy = dbs_info->cdbs.shared->policy;
struct dbs_data *dbs_data = policy->governor_data;
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
if (cs_tuners->freq_step == 0)
return;
if (load > cs_tuners->up_threshold) {
dbs_info->down_skip = 0;
if (dbs_info->requested_freq == policy->max)
return;
dbs_info->requested_freq += get_freq_target(cs_tuners, policy);
if (dbs_info->requested_freq > policy->max)
dbs_info->requested_freq = policy->max;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_H);
return;
}
if (++dbs_info->down_skip < cs_tuners->sampling_down_factor)
return;
dbs_info->down_skip = 0;
if (load < cs_tuners->down_threshold) {
unsigned int freq_target;
if (policy->cur == policy->min)
return;
freq_target = get_freq_target(cs_tuners, policy);
if (dbs_info->requested_freq > freq_target)
dbs_info->requested_freq -= freq_target;
else
dbs_info->requested_freq = policy->min;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_L);
return;
}
}
static unsigned int cs_dbs_timer(struct cpu_dbs_info *cdbs,
struct dbs_data *dbs_data, bool modify_all)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
if (modify_all)
dbs_check_cpu(dbs_data, cdbs->shared->policy->cpu);
return delay_for_sampling_rate(cs_tuners->sampling_rate);
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
policy = dbs_info->cdbs.shared->policy;
if (dbs_info->requested_freq > policy->max
|| dbs_info->requested_freq < policy->min)
dbs_info->requested_freq = freq->new;
return 0;
}
static ssize_t store_sampling_down_factor(struct dbs_data *dbs_data,
const char *buf, size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
cs_tuners->sampling_down_factor = input;
return count;
}
static ssize_t store_sampling_rate(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
cs_tuners->sampling_rate = max(input, dbs_data->min_sampling_rate);
return count;
}
static ssize_t store_up_threshold(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > 100 || input <= cs_tuners->down_threshold)
return -EINVAL;
cs_tuners->up_threshold = input;
return count;
}
static ssize_t store_down_threshold(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input < 11 || input > 100 ||
input >= cs_tuners->up_threshold)
return -EINVAL;
cs_tuners->down_threshold = input;
return count;
}
static ssize_t store_ignore_nice_load(struct dbs_data *dbs_data,
const char *buf, size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input, j;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1)
input = 1;
if (input == cs_tuners->ignore_nice_load)
return count;
cs_tuners->ignore_nice_load = input;
for_each_online_cpu(j) {
struct cs_cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(cs_cpu_dbs_info, j);
dbs_info->cdbs.prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->cdbs.prev_cpu_wall, 0);
if (cs_tuners->ignore_nice_load)
dbs_info->cdbs.prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
return count;
}
static ssize_t store_freq_step(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 100)
input = 100;
cs_tuners->freq_step = input;
return count;
}
static int cs_init(struct dbs_data *dbs_data, bool notify)
{
struct cs_dbs_tuners *tuners;
tuners = kzalloc(sizeof(*tuners), GFP_KERNEL);
if (!tuners) {
pr_err("%s: kzalloc failed\n", __func__);
return -ENOMEM;
}
tuners->up_threshold = DEF_FREQUENCY_UP_THRESHOLD;
tuners->down_threshold = DEF_FREQUENCY_DOWN_THRESHOLD;
tuners->sampling_down_factor = DEF_SAMPLING_DOWN_FACTOR;
tuners->ignore_nice_load = 0;
tuners->freq_step = DEF_FREQUENCY_STEP;
dbs_data->tuners = tuners;
dbs_data->min_sampling_rate = MIN_SAMPLING_RATE_RATIO *
jiffies_to_usecs(10);
if (notify)
cpufreq_register_notifier(&cs_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
return 0;
}
static void cs_exit(struct dbs_data *dbs_data, bool notify)
{
if (notify)
cpufreq_unregister_notifier(&cs_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
kfree(dbs_data->tuners);
}
static int cs_cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
return cpufreq_governor_dbs(policy, &cs_dbs_cdata, event);
}
static int __init cpufreq_gov_dbs_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_conservative);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_conservative);
}
