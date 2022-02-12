int cpufreq_frequency_table_cpuinfo(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *table)
{
struct cpufreq_frequency_table *pos;
unsigned int min_freq = ~0;
unsigned int max_freq = 0;
unsigned int freq;
cpufreq_for_each_valid_entry(pos, table) {
freq = pos->frequency;
if (!cpufreq_boost_enabled()
&& (pos->flags & CPUFREQ_BOOST_FREQ))
continue;
pr_debug("table entry %u: %u kHz\n", (int)(pos - table), freq);
if (freq < min_freq)
min_freq = freq;
if (freq > max_freq)
max_freq = freq;
}
policy->min = policy->cpuinfo.min_freq = min_freq;
policy->max = policy->cpuinfo.max_freq = max_freq;
if (policy->min == ~0)
return -EINVAL;
else
return 0;
}
int cpufreq_frequency_table_verify(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *table)
{
struct cpufreq_frequency_table *pos;
unsigned int freq, next_larger = ~0;
bool found = false;
pr_debug("request for verification of policy (%u - %u kHz) for cpu %u\n",
policy->min, policy->max, policy->cpu);
cpufreq_verify_within_cpu_limits(policy);
cpufreq_for_each_valid_entry(pos, table) {
freq = pos->frequency;
if ((freq >= policy->min) && (freq <= policy->max)) {
found = true;
break;
}
if ((next_larger > freq) && (freq > policy->max))
next_larger = freq;
}
if (!found) {
policy->max = next_larger;
cpufreq_verify_within_cpu_limits(policy);
}
pr_debug("verification lead to (%u - %u kHz) for cpu %u\n",
policy->min, policy->max, policy->cpu);
return 0;
}
int cpufreq_generic_frequency_table_verify(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *table =
cpufreq_frequency_get_table(policy->cpu);
if (!table)
return -ENODEV;
return cpufreq_frequency_table_verify(policy, table);
}
int cpufreq_frequency_table_target(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *table,
unsigned int target_freq,
unsigned int relation,
unsigned int *index)
{
struct cpufreq_frequency_table optimal = {
.driver_data = ~0,
.frequency = 0,
};
struct cpufreq_frequency_table suboptimal = {
.driver_data = ~0,
.frequency = 0,
};
struct cpufreq_frequency_table *pos;
unsigned int freq, i = 0;
pr_debug("request for target %u kHz (relation: %u) for cpu %u\n",
target_freq, relation, policy->cpu);
switch (relation) {
case CPUFREQ_RELATION_H:
suboptimal.frequency = ~0;
break;
case CPUFREQ_RELATION_L:
optimal.frequency = ~0;
break;
}
cpufreq_for_each_valid_entry(pos, table) {
freq = pos->frequency;
i = pos - table;
if ((freq < policy->min) || (freq > policy->max))
continue;
if (freq == target_freq) {
optimal.driver_data = i;
break;
}
switch (relation) {
case CPUFREQ_RELATION_H:
if (freq < target_freq) {
if (freq >= optimal.frequency) {
optimal.frequency = freq;
optimal.driver_data = i;
}
} else {
if (freq <= suboptimal.frequency) {
suboptimal.frequency = freq;
suboptimal.driver_data = i;
}
}
break;
case CPUFREQ_RELATION_L:
if (freq > target_freq) {
if (freq <= optimal.frequency) {
optimal.frequency = freq;
optimal.driver_data = i;
}
} else {
if (freq >= suboptimal.frequency) {
suboptimal.frequency = freq;
suboptimal.driver_data = i;
}
}
break;
}
}
if (optimal.driver_data > i) {
if (suboptimal.driver_data > i)
return -EINVAL;
*index = suboptimal.driver_data;
} else
*index = optimal.driver_data;
pr_debug("target index is %u, freq is:%u kHz\n", *index,
table[*index].frequency);
return 0;
}
int cpufreq_frequency_table_get_index(struct cpufreq_policy *policy,
unsigned int freq)
{
struct cpufreq_frequency_table *pos, *table;
table = cpufreq_frequency_get_table(policy->cpu);
if (unlikely(!table)) {
pr_debug("%s: Unable to find frequency table\n", __func__);
return -ENOENT;
}
cpufreq_for_each_valid_entry(pos, table)
if (pos->frequency == freq)
return pos - table;
return -EINVAL;
}
static ssize_t show_available_freqs(struct cpufreq_policy *policy, char *buf,
bool show_boost)
{
ssize_t count = 0;
struct cpufreq_frequency_table *pos, *table = policy->freq_table;
if (!table)
return -ENODEV;
cpufreq_for_each_valid_entry(pos, table) {
if (show_boost ^ (pos->flags & CPUFREQ_BOOST_FREQ))
continue;
count += sprintf(&buf[count], "%d ", pos->frequency);
}
count += sprintf(&buf[count], "\n");
return count;
}
static ssize_t scaling_available_frequencies_show(struct cpufreq_policy *policy,
char *buf)
{
return show_available_freqs(policy, buf, false);
}
static ssize_t scaling_boost_frequencies_show(struct cpufreq_policy *policy,
char *buf)
{
return show_available_freqs(policy, buf, true);
}
int cpufreq_table_validate_and_show(struct cpufreq_policy *policy,
struct cpufreq_frequency_table *table)
{
int ret = cpufreq_frequency_table_cpuinfo(policy, table);
if (!ret)
policy->freq_table = table;
return ret;
}
struct cpufreq_frequency_table *cpufreq_frequency_get_table(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get_raw(cpu);
return policy ? policy->freq_table : NULL;
}
