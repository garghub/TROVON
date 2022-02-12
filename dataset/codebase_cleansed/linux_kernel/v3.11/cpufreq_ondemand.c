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
static unsigned int generic_powersave_bias_target(struct cpufreq_policy *policy,
unsigned int freq_next, unsigned int relation)
{
unsigned int freq_req, freq_reduc, freq_avg;
unsigned int freq_hi, freq_lo;
unsigned int index = 0;
unsigned int jiffies_total, jiffies_hi, jiffies_lo;
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
policy->cpu);
struct dbs_data *dbs_data = policy->governor_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
if (!dbs_info->freq_table) {
dbs_info->freq_lo = 0;
dbs_info->freq_lo_jiffies = 0;
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
dbs_info->freq_lo_jiffies = 0;
return freq_lo;
}
jiffies_total = usecs_to_jiffies(od_tuners->sampling_rate);
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
struct dbs_data *dbs_data = p->governor_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
if (od_tuners->powersave_bias)
freq = od_ops.powersave_bias_target(p, freq,
CPUFREQ_RELATION_H);
else if (p->cur == p->max)
return;
__cpufreq_driver_target(p, freq, od_tuners->powersave_bias ?
CPUFREQ_RELATION_L : CPUFREQ_RELATION_H);
}
static void od_check_cpu(int cpu, unsigned int load_freq)
{
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
struct cpufreq_policy *policy = dbs_info->cdbs.cur_policy;
struct dbs_data *dbs_data = policy->governor_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
dbs_info->freq_lo = 0;
if (load_freq > od_tuners->up_threshold * policy->cur) {
if (policy->cur < policy->max)
dbs_info->rate_mult =
od_tuners->sampling_down_factor;
dbs_freq_increase(policy, policy->max);
return;
}
if (policy->cur == policy->min)
return;
if (load_freq < od_tuners->adj_up_threshold
* policy->cur) {
unsigned int freq_next;
freq_next = load_freq / od_tuners->adj_up_threshold;
dbs_info->rate_mult = 1;
if (freq_next < policy->min)
freq_next = policy->min;
if (!od_tuners->powersave_bias) {
__cpufreq_driver_target(policy, freq_next,
CPUFREQ_RELATION_L);
return;
}
freq_next = od_ops.powersave_bias_target(policy, freq_next,
CPUFREQ_RELATION_L);
__cpufreq_driver_target(policy, freq_next, CPUFREQ_RELATION_L);
}
}
static void od_dbs_timer(struct work_struct *work)
{
struct od_cpu_dbs_info_s *dbs_info =
container_of(work, struct od_cpu_dbs_info_s, cdbs.work.work);
unsigned int cpu = dbs_info->cdbs.cur_policy->cpu;
struct od_cpu_dbs_info_s *core_dbs_info = &per_cpu(od_cpu_dbs_info,
cpu);
struct dbs_data *dbs_data = dbs_info->cdbs.cur_policy->governor_data;
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
int delay = 0, sample_type = core_dbs_info->sample_type;
bool modify_all = true;
mutex_lock(&core_dbs_info->cdbs.timer_mutex);
if (!need_load_eval(&core_dbs_info->cdbs, od_tuners->sampling_rate)) {
modify_all = false;
goto max_delay;
}
core_dbs_info->sample_type = OD_NORMAL_SAMPLE;
if (sample_type == OD_SUB_SAMPLE) {
delay = core_dbs_info->freq_lo_jiffies;
__cpufreq_driver_target(core_dbs_info->cdbs.cur_policy,
core_dbs_info->freq_lo, CPUFREQ_RELATION_H);
} else {
dbs_check_cpu(dbs_data, cpu);
if (core_dbs_info->freq_lo) {
core_dbs_info->sample_type = OD_SUB_SAMPLE;
delay = core_dbs_info->freq_hi_jiffies;
}
}
max_delay:
if (!delay)
delay = delay_for_sampling_rate(od_tuners->sampling_rate
* core_dbs_info->rate_mult);
gov_queue_work(dbs_data, dbs_info->cdbs.cur_policy, delay, modify_all);
mutex_unlock(&core_dbs_info->cdbs.timer_mutex);
}
static void update_sampling_rate(struct dbs_data *dbs_data,
unsigned int new_rate)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
int cpu;
od_tuners->sampling_rate = new_rate = max(new_rate,
dbs_data->min_sampling_rate);
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
dbs_info = &per_cpu(od_cpu_dbs_info, cpu);
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
gov_queue_work(dbs_data, dbs_info->cdbs.cur_policy,
usecs_to_jiffies(new_rate), true);
}
mutex_unlock(&dbs_info->cdbs.timer_mutex);
}
}
static ssize_t store_sampling_rate(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
update_sampling_rate(dbs_data, input);
return count;
}
static ssize_t store_io_is_busy(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int input;
int ret;
unsigned int j;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
od_tuners->io_is_busy = !!input;
for_each_online_cpu(j) {
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
j);
dbs_info->cdbs.prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->cdbs.prev_cpu_wall, od_tuners->io_is_busy);
}
return count;
}
static ssize_t store_up_threshold(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_FREQUENCY_UP_THRESHOLD ||
input < MIN_FREQUENCY_UP_THRESHOLD) {
return -EINVAL;
}
od_tuners->adj_up_threshold += input;
od_tuners->adj_up_threshold -= od_tuners->up_threshold;
od_tuners->up_threshold = input;
return count;
}
static ssize_t store_sampling_down_factor(struct dbs_data *dbs_data,
const char *buf, size_t count)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int input, j;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
return -EINVAL;
od_tuners->sampling_down_factor = input;
for_each_online_cpu(j) {
struct od_cpu_dbs_info_s *dbs_info = &per_cpu(od_cpu_dbs_info,
j);
dbs_info->rate_mult = 1;
}
return count;
}
static ssize_t store_ignore_nice_load(struct dbs_data *dbs_data,
const char *buf, size_t count)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int input;
int ret;
unsigned int j;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1)
input = 1;
if (input == od_tuners->ignore_nice_load) {
return count;
}
od_tuners->ignore_nice_load = input;
for_each_online_cpu(j) {
struct od_cpu_dbs_info_s *dbs_info;
dbs_info = &per_cpu(od_cpu_dbs_info, j);
dbs_info->cdbs.prev_cpu_idle = get_cpu_idle_time(j,
&dbs_info->cdbs.prev_cpu_wall, od_tuners->io_is_busy);
if (od_tuners->ignore_nice_load)
dbs_info->cdbs.prev_cpu_nice =
kcpustat_cpu(j).cpustat[CPUTIME_NICE];
}
return count;
}
static ssize_t store_powersave_bias(struct dbs_data *dbs_data, const char *buf,
size_t count)
{
struct od_dbs_tuners *od_tuners = dbs_data->tuners;
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
if (input > 1000)
input = 1000;
od_tuners->powersave_bias = input;
ondemand_powersave_bias_init();
return count;
}
static int od_init(struct dbs_data *dbs_data)
{
struct od_dbs_tuners *tuners;
u64 idle_time;
int cpu;
tuners = kzalloc(sizeof(struct od_dbs_tuners), GFP_KERNEL);
if (!tuners) {
pr_err("%s: kzalloc failed\n", __func__);
return -ENOMEM;
}
cpu = get_cpu();
idle_time = get_cpu_idle_time_us(cpu, NULL);
put_cpu();
if (idle_time != -1ULL) {
tuners->up_threshold = MICRO_FREQUENCY_UP_THRESHOLD;
tuners->adj_up_threshold = MICRO_FREQUENCY_UP_THRESHOLD -
MICRO_FREQUENCY_DOWN_DIFFERENTIAL;
dbs_data->min_sampling_rate = MICRO_FREQUENCY_MIN_SAMPLE_RATE;
} else {
tuners->up_threshold = DEF_FREQUENCY_UP_THRESHOLD;
tuners->adj_up_threshold = DEF_FREQUENCY_UP_THRESHOLD -
DEF_FREQUENCY_DOWN_DIFFERENTIAL;
dbs_data->min_sampling_rate = MIN_SAMPLING_RATE_RATIO *
jiffies_to_usecs(10);
}
tuners->sampling_down_factor = DEF_SAMPLING_DOWN_FACTOR;
tuners->ignore_nice_load = 0;
tuners->powersave_bias = default_powersave_bias;
tuners->io_is_busy = should_io_be_busy();
dbs_data->tuners = tuners;
mutex_init(&dbs_data->mutex);
return 0;
}
static void od_exit(struct dbs_data *dbs_data)
{
kfree(dbs_data->tuners);
}
static void od_set_powersave_bias(unsigned int powersave_bias)
{
struct cpufreq_policy *policy;
struct dbs_data *dbs_data;
struct od_dbs_tuners *od_tuners;
unsigned int cpu;
cpumask_t done;
default_powersave_bias = powersave_bias;
cpumask_clear(&done);
get_online_cpus();
for_each_online_cpu(cpu) {
if (cpumask_test_cpu(cpu, &done))
continue;
policy = per_cpu(od_cpu_dbs_info, cpu).cdbs.cur_policy;
if (!policy)
continue;
cpumask_or(&done, &done, policy->cpus);
if (policy->governor != &cpufreq_gov_ondemand)
continue;
dbs_data = policy->governor_data;
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
static int od_cpufreq_governor_dbs(struct cpufreq_policy *policy,
unsigned int event)
{
return cpufreq_governor_dbs(policy, &od_dbs_cdata, event);
}
static int __init cpufreq_gov_dbs_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_ondemand);
}
static void __exit cpufreq_gov_dbs_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_ondemand);
}
