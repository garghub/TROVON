static int cpufreq_stats_update(struct cpufreq_stats *stats)
{
unsigned long long cur_time = get_jiffies_64();
spin_lock(&cpufreq_stats_lock);
stats->time_in_state[stats->last_index] += cur_time - stats->last_time;
stats->last_time = cur_time;
spin_unlock(&cpufreq_stats_lock);
return 0;
}
static ssize_t show_total_trans(struct cpufreq_policy *policy, char *buf)
{
return sprintf(buf, "%d\n", policy->stats->total_trans);
}
static ssize_t show_time_in_state(struct cpufreq_policy *policy, char *buf)
{
struct cpufreq_stats *stats = policy->stats;
ssize_t len = 0;
int i;
cpufreq_stats_update(stats);
for (i = 0; i < stats->state_num; i++) {
len += sprintf(buf + len, "%u %llu\n", stats->freq_table[i],
(unsigned long long)
jiffies_64_to_clock_t(stats->time_in_state[i]));
}
return len;
}
static ssize_t show_trans_table(struct cpufreq_policy *policy, char *buf)
{
struct cpufreq_stats *stats = policy->stats;
ssize_t len = 0;
int i, j;
len += snprintf(buf + len, PAGE_SIZE - len, " From : To\n");
len += snprintf(buf + len, PAGE_SIZE - len, " : ");
for (i = 0; i < stats->state_num; i++) {
if (len >= PAGE_SIZE)
break;
len += snprintf(buf + len, PAGE_SIZE - len, "%9u ",
stats->freq_table[i]);
}
if (len >= PAGE_SIZE)
return PAGE_SIZE;
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
for (i = 0; i < stats->state_num; i++) {
if (len >= PAGE_SIZE)
break;
len += snprintf(buf + len, PAGE_SIZE - len, "%9u: ",
stats->freq_table[i]);
for (j = 0; j < stats->state_num; j++) {
if (len >= PAGE_SIZE)
break;
len += snprintf(buf + len, PAGE_SIZE - len, "%9u ",
stats->trans_table[i*stats->max_state+j]);
}
if (len >= PAGE_SIZE)
break;
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
}
if (len >= PAGE_SIZE)
return PAGE_SIZE;
return len;
}
static int freq_table_get_index(struct cpufreq_stats *stats, unsigned int freq)
{
int index;
for (index = 0; index < stats->max_state; index++)
if (stats->freq_table[index] == freq)
return index;
return -1;
}
static void __cpufreq_stats_free_table(struct cpufreq_policy *policy)
{
struct cpufreq_stats *stats = policy->stats;
if (!stats)
return;
pr_debug("%s: Free stats table\n", __func__);
sysfs_remove_group(&policy->kobj, &stats_attr_group);
kfree(stats->time_in_state);
kfree(stats);
policy->stats = NULL;
}
static void cpufreq_stats_free_table(unsigned int cpu)
{
struct cpufreq_policy *policy;
policy = cpufreq_cpu_get(cpu);
if (!policy)
return;
__cpufreq_stats_free_table(policy);
cpufreq_cpu_put(policy);
}
static int __cpufreq_stats_create_table(struct cpufreq_policy *policy)
{
unsigned int i = 0, count = 0, ret = -ENOMEM;
struct cpufreq_stats *stats;
unsigned int alloc_size;
unsigned int cpu = policy->cpu;
struct cpufreq_frequency_table *pos, *table;
table = cpufreq_frequency_get_table(cpu);
if (unlikely(!table))
return 0;
if (policy->stats)
return -EEXIST;
stats = kzalloc(sizeof(*stats), GFP_KERNEL);
if (!stats)
return -ENOMEM;
cpufreq_for_each_valid_entry(pos, table)
count++;
alloc_size = count * sizeof(int) + count * sizeof(u64);
#ifdef CONFIG_CPU_FREQ_STAT_DETAILS
alloc_size += count * count * sizeof(int);
#endif
stats->time_in_state = kzalloc(alloc_size, GFP_KERNEL);
if (!stats->time_in_state)
goto free_stat;
stats->freq_table = (unsigned int *)(stats->time_in_state + count);
#ifdef CONFIG_CPU_FREQ_STAT_DETAILS
stats->trans_table = stats->freq_table + count;
#endif
stats->max_state = count;
cpufreq_for_each_valid_entry(pos, table)
if (freq_table_get_index(stats, pos->frequency) == -1)
stats->freq_table[i++] = pos->frequency;
stats->state_num = i;
stats->last_time = get_jiffies_64();
stats->last_index = freq_table_get_index(stats, policy->cur);
policy->stats = stats;
ret = sysfs_create_group(&policy->kobj, &stats_attr_group);
if (!ret)
return 0;
policy->stats = NULL;
kfree(stats->time_in_state);
free_stat:
kfree(stats);
return ret;
}
static void cpufreq_stats_create_table(unsigned int cpu)
{
struct cpufreq_policy *policy;
policy = cpufreq_cpu_get(cpu);
if (likely(!policy))
return;
__cpufreq_stats_create_table(policy);
cpufreq_cpu_put(policy);
}
static int cpufreq_stat_notifier_policy(struct notifier_block *nb,
unsigned long val, void *data)
{
int ret = 0;
struct cpufreq_policy *policy = data;
if (val == CPUFREQ_CREATE_POLICY)
ret = __cpufreq_stats_create_table(policy);
else if (val == CPUFREQ_REMOVE_POLICY)
__cpufreq_stats_free_table(policy);
return ret;
}
static int cpufreq_stat_notifier_trans(struct notifier_block *nb,
unsigned long val, void *data)
{
struct cpufreq_freqs *freq = data;
struct cpufreq_policy *policy = cpufreq_cpu_get(freq->cpu);
struct cpufreq_stats *stats;
int old_index, new_index;
if (!policy) {
pr_err("%s: No policy found\n", __func__);
return 0;
}
if (val != CPUFREQ_POSTCHANGE)
goto put_policy;
if (!policy->stats) {
pr_debug("%s: No stats found\n", __func__);
goto put_policy;
}
stats = policy->stats;
old_index = stats->last_index;
new_index = freq_table_get_index(stats, freq->new);
if (old_index == -1 || new_index == -1)
goto put_policy;
if (old_index == new_index)
goto put_policy;
cpufreq_stats_update(stats);
stats->last_index = new_index;
#ifdef CONFIG_CPU_FREQ_STAT_DETAILS
stats->trans_table[old_index * stats->max_state + new_index]++;
#endif
stats->total_trans++;
put_policy:
cpufreq_cpu_put(policy);
return 0;
}
static int __init cpufreq_stats_init(void)
{
int ret;
unsigned int cpu;
spin_lock_init(&cpufreq_stats_lock);
ret = cpufreq_register_notifier(&notifier_policy_block,
CPUFREQ_POLICY_NOTIFIER);
if (ret)
return ret;
for_each_online_cpu(cpu)
cpufreq_stats_create_table(cpu);
ret = cpufreq_register_notifier(&notifier_trans_block,
CPUFREQ_TRANSITION_NOTIFIER);
if (ret) {
cpufreq_unregister_notifier(&notifier_policy_block,
CPUFREQ_POLICY_NOTIFIER);
for_each_online_cpu(cpu)
cpufreq_stats_free_table(cpu);
return ret;
}
return 0;
}
static void __exit cpufreq_stats_exit(void)
{
unsigned int cpu;
cpufreq_unregister_notifier(&notifier_policy_block,
CPUFREQ_POLICY_NOTIFIER);
cpufreq_unregister_notifier(&notifier_trans_block,
CPUFREQ_TRANSITION_NOTIFIER);
for_each_online_cpu(cpu)
cpufreq_stats_free_table(cpu);
}
