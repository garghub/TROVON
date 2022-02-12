static unsigned int amd_powersave_bias_target(struct cpufreq_policy *policy,
unsigned int freq_next,
unsigned int relation)
{
int sensitivity;
long d_actual, d_reference;
struct msr actual, reference;
struct cpu_data_t *data = &per_cpu(cpu_data, policy->cpu);
struct policy_dbs_info *policy_dbs = policy->governor_data;
struct dbs_data *od_data = policy_dbs->dbs_data;
struct od_dbs_tuners *od_tuners = od_data->tuners;
if (!policy->freq_table)
return freq_next;
rdmsr_on_cpu(policy->cpu, MSR_AMD64_FREQ_SENSITIVITY_ACTUAL,
&actual.l, &actual.h);
rdmsr_on_cpu(policy->cpu, MSR_AMD64_FREQ_SENSITIVITY_REFERENCE,
&reference.l, &reference.h);
actual.h &= 0x00ffffff;
reference.h &= 0x00ffffff;
if (actual.q < data->actual || reference.q < data->reference) {
freq_next = policy->cur;
goto out;
}
d_actual = actual.q - data->actual;
d_reference = reference.q - data->reference;
if (d_reference == 0) {
freq_next = policy->cur;
goto out;
}
sensitivity = POWERSAVE_BIAS_MAX -
(POWERSAVE_BIAS_MAX * (d_reference - d_actual) / d_reference);
clamp(sensitivity, 0, POWERSAVE_BIAS_MAX);
if (sensitivity < od_tuners->powersave_bias) {
if (data->freq_prev == policy->cur)
freq_next = policy->cur;
if (freq_next > policy->cur)
freq_next = policy->cur;
else if (freq_next < policy->cur)
freq_next = policy->min;
else {
unsigned int index;
index = cpufreq_table_find_index_h(policy,
policy->cur - 1);
freq_next = policy->freq_table[index].frequency;
}
data->freq_prev = freq_next;
} else
data->freq_prev = 0;
out:
data->actual = actual.q;
data->reference = reference.q;
return freq_next;
}
static int __init amd_freq_sensitivity_init(void)
{
u64 val;
if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD)
return -ENODEV;
if (!static_cpu_has(X86_FEATURE_PROC_FEEDBACK))
return -ENODEV;
if (rdmsrl_safe(MSR_AMD64_FREQ_SENSITIVITY_ACTUAL, &val))
return -ENODEV;
if (!(val >> CLASS_CODE_SHIFT))
return -ENODEV;
od_register_powersave_bias_handler(amd_powersave_bias_target,
POWERSAVE_BIAS_DEF);
return 0;
}
static void __exit amd_freq_sensitivity_exit(void)
{
od_unregister_powersave_bias_handler();
}
