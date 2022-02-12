static inline struct cs_policy_dbs_info *to_dbs_info(struct policy_dbs_info *policy_dbs)
{
return container_of(policy_dbs, struct cs_policy_dbs_info, policy_dbs);
}
static inline unsigned int get_freq_target(struct cs_dbs_tuners *cs_tuners,
struct cpufreq_policy *policy)
{
unsigned int freq_target = (cs_tuners->freq_step * policy->max) / 100;
if (unlikely(freq_target == 0))
freq_target = DEF_FREQUENCY_STEP;
return freq_target;
}
static unsigned int cs_dbs_timer(struct cpufreq_policy *policy)
{
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct cs_policy_dbs_info *dbs_info = to_dbs_info(policy_dbs);
struct dbs_data *dbs_data = policy_dbs->dbs_data;
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int load = dbs_update(policy);
if (cs_tuners->freq_step == 0)
goto out;
if (load > dbs_data->up_threshold) {
dbs_info->down_skip = 0;
if (dbs_info->requested_freq == policy->max)
goto out;
dbs_info->requested_freq += get_freq_target(cs_tuners, policy);
if (dbs_info->requested_freq > policy->max)
dbs_info->requested_freq = policy->max;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_H);
goto out;
}
if (++dbs_info->down_skip < dbs_data->sampling_down_factor)
goto out;
dbs_info->down_skip = 0;
if (load < cs_tuners->down_threshold) {
unsigned int freq_target;
if (policy->cur == policy->min)
goto out;
freq_target = get_freq_target(cs_tuners, policy);
if (dbs_info->requested_freq > freq_target)
dbs_info->requested_freq -= freq_target;
else
dbs_info->requested_freq = policy->min;
__cpufreq_driver_target(policy, dbs_info->requested_freq,
CPUFREQ_RELATION_L);
}
out:
return dbs_data->sampling_rate;
}
static ssize_t store_sampling_down_factor(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
dbs_data->sampling_down_factor = input;
return count;
}
static ssize_t store_up_threshold(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > 100 || input <= cs_tuners->down_threshold)
return -EINVAL;
dbs_data->up_threshold = input;
return count;
}
static ssize_t store_down_threshold(struct gov_attr_set *attr_set,
const char *buf, size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
struct cs_dbs_tuners *cs_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input < 11 || input > 100 ||
input >= dbs_data->up_threshold)
return -EINVAL;
cs_tuners->down_threshold = input;
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
if (input == dbs_data->ignore_nice_load)
return count;
dbs_data->ignore_nice_load = input;
gov_update_cpu_data(dbs_data);
return count;
}
static ssize_t store_freq_step(struct gov_attr_set *attr_set, const char *buf,
size_t count)
{
struct dbs_data *dbs_data = to_dbs_data(attr_set);
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
static struct policy_dbs_info *cs_alloc(void)
{
struct cs_policy_dbs_info *dbs_info;
dbs_info = kzalloc(sizeof(*dbs_info), GFP_KERNEL);
return dbs_info ? &dbs_info->policy_dbs : NULL;
}
static void cs_free(struct policy_dbs_info *policy_dbs)
{
kfree(to_dbs_info(policy_dbs));
}
static int cs_init(struct dbs_data *dbs_data, bool notify)
{
struct cs_dbs_tuners *tuners;
tuners = kzalloc(sizeof(*tuners), GFP_KERNEL);
if (!tuners) {
pr_err("%s: kzalloc failed\n", __func__);
return -ENOMEM;
}
tuners->down_threshold = DEF_FREQUENCY_DOWN_THRESHOLD;
tuners->freq_step = DEF_FREQUENCY_STEP;
dbs_data->up_threshold = DEF_FREQUENCY_UP_THRESHOLD;
dbs_data->sampling_down_factor = DEF_SAMPLING_DOWN_FACTOR;
dbs_data->ignore_nice_load = 0;
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
static void cs_start(struct cpufreq_policy *policy)
{
struct cs_policy_dbs_info *dbs_info = to_dbs_info(policy->governor_data);
dbs_info->down_skip = 0;
dbs_info->requested_freq = policy->cur;
}
static int dbs_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
struct cpufreq_policy *policy = cpufreq_cpu_get_raw(freq->cpu);
struct cs_policy_dbs_info *dbs_info;
if (!policy)
return 0;
if (policy->governor != CPU_FREQ_GOV_CONSERVATIVE)
return 0;
dbs_info = to_dbs_info(policy->governor_data);
if (dbs_info->requested_freq > policy->max
|| dbs_info->requested_freq < policy->min)
dbs_info->requested_freq = freq->new;
return 0;
}
static int __init cpufreq_gov_dbs_init(void)
{
return cpufreq_register_governor(CPU_FREQ_GOV_CONSERVATIVE);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(CPU_FREQ_GOV_CONSERVATIVE);
}
struct cpufreq_governor *cpufreq_default_governor(void)
{
return CPU_FREQ_GOV_CONSERVATIVE;
}
