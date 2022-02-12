static inline const struct cpumask *cpu_core_mask(int cpu)
{
return cpumask_of(0);
}
static void freq_table_redup(struct cpufreq_frequency_table *freq_table,
int count)
{
int i, j;
for (i = 1; i < count; i++) {
for (j = 0; j < i; j++) {
if (freq_table[j].frequency == CPUFREQ_ENTRY_INVALID ||
freq_table[j].frequency !=
freq_table[i].frequency)
continue;
freq_table[i].frequency = CPUFREQ_ENTRY_INVALID;
break;
}
}
}
static void freq_table_sort(struct cpufreq_frequency_table *freq_table,
int count)
{
int i, j, ind;
unsigned int freq, max_freq;
struct cpufreq_frequency_table table;
for (i = 0; i < count - 1; i++) {
max_freq = freq_table[i].frequency;
ind = i;
for (j = i + 1; j < count; j++) {
freq = freq_table[j].frequency;
if (freq == CPUFREQ_ENTRY_INVALID ||
freq <= max_freq)
continue;
ind = j;
max_freq = freq;
}
if (ind != i) {
table.driver_data = freq_table[i].driver_data;
table.frequency = freq_table[i].frequency;
freq_table[i].driver_data = freq_table[ind].driver_data;
freq_table[i].frequency = freq_table[ind].frequency;
freq_table[ind].driver_data = table.driver_data;
freq_table[ind].frequency = table.frequency;
}
}
}
static int corenet_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
struct device_node *np;
int i, count, ret;
u32 freq, mask;
struct clk *clk;
struct cpufreq_frequency_table *table;
struct cpu_data *data;
unsigned int cpu = policy->cpu;
np = of_get_cpu_node(cpu, NULL);
if (!np)
return -ENODEV;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
pr_err("%s: no memory\n", __func__);
goto err_np;
}
policy->clk = of_clk_get(np, 0);
if (IS_ERR(policy->clk)) {
pr_err("%s: no clock information\n", __func__);
goto err_nomem2;
}
data->parent = of_parse_phandle(np, "clocks", 0);
if (!data->parent) {
pr_err("%s: could not get clock information\n", __func__);
goto err_nomem2;
}
count = of_property_count_strings(data->parent, "clock-names");
table = kcalloc(count + 1, sizeof(*table), GFP_KERNEL);
if (!table) {
pr_err("%s: no memory\n", __func__);
goto err_node;
}
if (fmask)
mask = fmask[get_hard_smp_processor_id(cpu)];
else
mask = 0x0;
for (i = 0; i < count; i++) {
clk = of_clk_get(data->parent, i);
freq = clk_get_rate(clk);
if (freq < min_cpufreq || (mask & (1 << i)))
table[i].frequency = CPUFREQ_ENTRY_INVALID;
else
table[i].frequency = freq / 1000;
table[i].driver_data = i;
}
freq_table_redup(table, count);
freq_table_sort(table, count);
table[i].frequency = CPUFREQ_TABLE_END;
ret = cpufreq_table_validate_and_show(policy, table);
if (ret) {
pr_err("invalid frequency table: %d\n", ret);
goto err_nomem1;
}
data->table = table;
per_cpu(cpu_data, cpu) = data;
cpumask_copy(policy->cpus, per_cpu(cpu_mask, cpu));
for_each_cpu(i, per_cpu(cpu_mask, cpu))
per_cpu(cpu_data, i) = data;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
of_node_put(np);
return 0;
err_nomem1:
kfree(table);
err_node:
of_node_put(data->parent);
err_nomem2:
per_cpu(cpu_data, cpu) = NULL;
kfree(data);
err_np:
of_node_put(np);
return -ENODEV;
}
static int __exit corenet_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
struct cpu_data *data = per_cpu(cpu_data, policy->cpu);
unsigned int cpu;
cpufreq_frequency_table_put_attr(policy->cpu);
of_node_put(data->parent);
kfree(data->table);
kfree(data);
for_each_cpu(cpu, per_cpu(cpu_mask, policy->cpu))
per_cpu(cpu_data, cpu) = NULL;
return 0;
}
static int corenet_cpufreq_target(struct cpufreq_policy *policy,
unsigned int index)
{
struct clk *parent;
struct cpu_data *data = per_cpu(cpu_data, policy->cpu);
parent = of_clk_get(data->parent, data->table[index].driver_data);
return clk_set_parent(policy->clk, parent);
}
static int __init ppc_corenet_cpufreq_init(void)
{
int ret;
struct device_node *np;
const struct of_device_id *match;
const struct soc_data *data;
unsigned int cpu;
np = of_find_matching_node(NULL, node_matches);
if (!np)
return -ENODEV;
for_each_possible_cpu(cpu) {
if (!alloc_cpumask_var(&per_cpu(cpu_mask, cpu), GFP_KERNEL))
goto err_mask;
cpumask_copy(per_cpu(cpu_mask, cpu), cpu_core_mask(cpu));
}
match = of_match_node(node_matches, np);
data = match->data;
if (data) {
if (data->flag)
fmask = data->freq_mask;
min_cpufreq = fsl_get_sys_freq();
} else {
min_cpufreq = fsl_get_sys_freq() / 2;
}
of_node_put(np);
ret = cpufreq_register_driver(&ppc_corenet_cpufreq_driver);
if (!ret)
pr_info("Freescale PowerPC corenet CPU frequency scaling driver\n");
return ret;
err_mask:
for_each_possible_cpu(cpu)
free_cpumask_var(per_cpu(cpu_mask, cpu));
return -ENOMEM;
}
static void __exit ppc_corenet_cpufreq_exit(void)
{
unsigned int cpu;
for_each_possible_cpu(cpu)
free_cpumask_var(per_cpu(cpu_mask, cpu));
cpufreq_unregister_driver(&ppc_corenet_cpufreq_driver);
}
