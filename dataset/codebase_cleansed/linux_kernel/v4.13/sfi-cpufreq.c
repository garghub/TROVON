static int sfi_parse_freq(struct sfi_table_header *table)
{
struct sfi_table_simple *sb;
struct sfi_freq_table_entry *pentry;
int totallen;
sb = (struct sfi_table_simple *)table;
num_freq_table_entries = SFI_GET_NUM_ENTRIES(sb,
struct sfi_freq_table_entry);
if (num_freq_table_entries <= 1) {
pr_err("No p-states discovered\n");
return -ENODEV;
}
pentry = (struct sfi_freq_table_entry *)sb->pentry;
totallen = num_freq_table_entries * sizeof(*pentry);
sfi_cpufreq_array = kmemdup(pentry, totallen, GFP_KERNEL);
if (!sfi_cpufreq_array)
return -ENOMEM;
return 0;
}
static int sfi_cpufreq_target(struct cpufreq_policy *policy, unsigned int index)
{
unsigned int next_perf_state = 0;
u32 lo, hi;
next_perf_state = policy->freq_table[index].driver_data;
rdmsr_on_cpu(policy->cpu, MSR_IA32_PERF_CTL, &lo, &hi);
lo = (lo & ~INTEL_PERF_CTL_MASK) |
((u32) sfi_cpufreq_array[next_perf_state].ctrl_val &
INTEL_PERF_CTL_MASK);
wrmsr_on_cpu(policy->cpu, MSR_IA32_PERF_CTL, lo, hi);
return 0;
}
static int sfi_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->shared_type = CPUFREQ_SHARED_TYPE_HW;
policy->cpuinfo.transition_latency = 100000;
return cpufreq_table_validate_and_show(policy, freq_table);
}
static int __init sfi_cpufreq_init(void)
{
int ret, i;
ret = sfi_table_parse(SFI_SIG_FREQ, NULL, NULL, sfi_parse_freq);
if (ret)
return ret;
freq_table = kzalloc(sizeof(*freq_table) *
(num_freq_table_entries + 1), GFP_KERNEL);
if (!freq_table) {
ret = -ENOMEM;
goto err_free_array;
}
for (i = 0; i < num_freq_table_entries; i++) {
freq_table[i].driver_data = i;
freq_table[i].frequency = sfi_cpufreq_array[i].freq_mhz * 1000;
}
freq_table[i].frequency = CPUFREQ_TABLE_END;
ret = cpufreq_register_driver(&sfi_cpufreq_driver);
if (ret)
goto err_free_tbl;
return ret;
err_free_tbl:
kfree(freq_table);
err_free_array:
kfree(sfi_cpufreq_array);
return ret;
}
static void __exit sfi_cpufreq_exit(void)
{
cpufreq_unregister_driver(&sfi_cpufreq_driver);
kfree(freq_table);
kfree(sfi_cpufreq_array);
}
