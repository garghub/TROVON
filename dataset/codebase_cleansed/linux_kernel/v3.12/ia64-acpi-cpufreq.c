static int
processor_set_pstate (
u32 value)
{
s64 retval;
pr_debug("processor_set_pstate\n");
retval = ia64_pal_set_pstate((u64)value);
if (retval) {
pr_debug("Failed to set freq to 0x%x, with error 0x%lx\n",
value, retval);
return -ENODEV;
}
return (int)retval;
}
static int
processor_get_pstate (
u32 *value)
{
u64 pstate_index = 0;
s64 retval;
pr_debug("processor_get_pstate\n");
retval = ia64_pal_get_pstate(&pstate_index,
PAL_GET_PSTATE_TYPE_INSTANT);
*value = (u32) pstate_index;
if (retval)
pr_debug("Failed to get current freq with "
"error 0x%lx, idx 0x%x\n", retval, *value);
return (int)retval;
}
static unsigned
extract_clock (
struct cpufreq_acpi_io *data,
unsigned value,
unsigned int cpu)
{
unsigned long i;
pr_debug("extract_clock\n");
for (i = 0; i < data->acpi_data.state_count; i++) {
if (value == data->acpi_data.states[i].status)
return data->acpi_data.states[i].core_frequency;
}
return data->acpi_data.states[i-1].core_frequency;
}
static unsigned int
processor_get_freq (
struct cpufreq_acpi_io *data,
unsigned int cpu)
{
int ret = 0;
u32 value = 0;
cpumask_t saved_mask;
unsigned long clock_freq;
pr_debug("processor_get_freq\n");
saved_mask = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
if (smp_processor_id() != cpu)
goto migrate_end;
ret = processor_get_pstate(&value);
if (ret) {
set_cpus_allowed_ptr(current, &saved_mask);
printk(KERN_WARNING "get performance failed with error %d\n",
ret);
ret = 0;
goto migrate_end;
}
clock_freq = extract_clock(data, value, cpu);
ret = (clock_freq*1000);
migrate_end:
set_cpus_allowed_ptr(current, &saved_mask);
return ret;
}
static int
processor_set_freq (
struct cpufreq_acpi_io *data,
struct cpufreq_policy *policy,
int state)
{
int ret = 0;
u32 value = 0;
struct cpufreq_freqs cpufreq_freqs;
cpumask_t saved_mask;
int retval;
pr_debug("processor_set_freq\n");
saved_mask = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(policy->cpu));
if (smp_processor_id() != policy->cpu) {
retval = -EAGAIN;
goto migrate_end;
}
if (state == data->acpi_data.state) {
if (unlikely(data->resume)) {
pr_debug("Called after resume, resetting to P%d\n", state);
data->resume = 0;
} else {
pr_debug("Already at target state (P%d)\n", state);
retval = 0;
goto migrate_end;
}
}
pr_debug("Transitioning from P%d to P%d\n",
data->acpi_data.state, state);
cpufreq_freqs.old = data->freq_table[data->acpi_data.state].frequency;
cpufreq_freqs.new = data->freq_table[state].frequency;
cpufreq_notify_transition(policy, &cpufreq_freqs, CPUFREQ_PRECHANGE);
value = (u32) data->acpi_data.states[state].control;
pr_debug("Transitioning to state: 0x%08x\n", value);
ret = processor_set_pstate(value);
if (ret) {
unsigned int tmp = cpufreq_freqs.new;
cpufreq_notify_transition(policy, &cpufreq_freqs,
CPUFREQ_POSTCHANGE);
cpufreq_freqs.new = cpufreq_freqs.old;
cpufreq_freqs.old = tmp;
cpufreq_notify_transition(policy, &cpufreq_freqs,
CPUFREQ_PRECHANGE);
cpufreq_notify_transition(policy, &cpufreq_freqs,
CPUFREQ_POSTCHANGE);
printk(KERN_WARNING "Transition failed with error %d\n", ret);
retval = -ENODEV;
goto migrate_end;
}
cpufreq_notify_transition(policy, &cpufreq_freqs, CPUFREQ_POSTCHANGE);
data->acpi_data.state = state;
retval = 0;
migrate_end:
set_cpus_allowed_ptr(current, &saved_mask);
return (retval);
}
static unsigned int
acpi_cpufreq_get (
unsigned int cpu)
{
struct cpufreq_acpi_io *data = acpi_io_data[cpu];
pr_debug("acpi_cpufreq_get\n");
return processor_get_freq(data, cpu);
}
static int
acpi_cpufreq_target (
struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_acpi_io *data = acpi_io_data[policy->cpu];
unsigned int next_state = 0;
unsigned int result = 0;
pr_debug("acpi_cpufreq_setpolicy\n");
result = cpufreq_frequency_table_target(policy,
data->freq_table, target_freq, relation, &next_state);
if (result)
return (result);
result = processor_set_freq(data, policy, next_state);
return (result);
}
static int
acpi_cpufreq_verify (
struct cpufreq_policy *policy)
{
unsigned int result = 0;
struct cpufreq_acpi_io *data = acpi_io_data[policy->cpu];
pr_debug("acpi_cpufreq_verify\n");
result = cpufreq_frequency_table_verify(policy,
data->freq_table);
return (result);
}
static int
acpi_cpufreq_cpu_init (
struct cpufreq_policy *policy)
{
unsigned int i;
unsigned int cpu = policy->cpu;
struct cpufreq_acpi_io *data;
unsigned int result = 0;
pr_debug("acpi_cpufreq_cpu_init\n");
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return (-ENOMEM);
acpi_io_data[cpu] = data;
result = acpi_processor_register_performance(&data->acpi_data, cpu);
if (result)
goto err_free;
if (data->acpi_data.state_count <= 1) {
pr_debug("No P-States\n");
result = -ENODEV;
goto err_unreg;
}
if ((data->acpi_data.control_register.space_id !=
ACPI_ADR_SPACE_FIXED_HARDWARE) ||
(data->acpi_data.status_register.space_id !=
ACPI_ADR_SPACE_FIXED_HARDWARE)) {
pr_debug("Unsupported address space [%d, %d]\n",
(u32) (data->acpi_data.control_register.space_id),
(u32) (data->acpi_data.status_register.space_id));
result = -ENODEV;
goto err_unreg;
}
data->freq_table = kmalloc(sizeof(*data->freq_table) *
(data->acpi_data.state_count + 1),
GFP_KERNEL);
if (!data->freq_table) {
result = -ENOMEM;
goto err_unreg;
}
policy->cpuinfo.transition_latency = 0;
for (i=0; i<data->acpi_data.state_count; i++) {
if ((data->acpi_data.states[i].transition_latency * 1000) >
policy->cpuinfo.transition_latency) {
policy->cpuinfo.transition_latency =
data->acpi_data.states[i].transition_latency * 1000;
}
}
policy->cur = processor_get_freq(data, policy->cpu);
for (i = 0; i <= data->acpi_data.state_count; i++)
{
data->freq_table[i].driver_data = i;
if (i < data->acpi_data.state_count) {
data->freq_table[i].frequency =
data->acpi_data.states[i].core_frequency * 1000;
} else {
data->freq_table[i].frequency = CPUFREQ_TABLE_END;
}
}
result = cpufreq_frequency_table_cpuinfo(policy, data->freq_table);
if (result) {
goto err_freqfree;
}
acpi_processor_notify_smm(THIS_MODULE);
printk(KERN_INFO "acpi-cpufreq: CPU%u - ACPI performance management "
"activated.\n", cpu);
for (i = 0; i < data->acpi_data.state_count; i++)
pr_debug(" %cP%d: %d MHz, %d mW, %d uS, %d uS, 0x%x 0x%x\n",
(i == data->acpi_data.state?'*':' '), i,
(u32) data->acpi_data.states[i].core_frequency,
(u32) data->acpi_data.states[i].power,
(u32) data->acpi_data.states[i].transition_latency,
(u32) data->acpi_data.states[i].bus_master_latency,
(u32) data->acpi_data.states[i].status,
(u32) data->acpi_data.states[i].control);
cpufreq_frequency_table_get_attr(data->freq_table, policy->cpu);
data->resume = 1;
return (result);
err_freqfree:
kfree(data->freq_table);
err_unreg:
acpi_processor_unregister_performance(&data->acpi_data, cpu);
err_free:
kfree(data);
acpi_io_data[cpu] = NULL;
return (result);
}
static int
acpi_cpufreq_cpu_exit (
struct cpufreq_policy *policy)
{
struct cpufreq_acpi_io *data = acpi_io_data[policy->cpu];
pr_debug("acpi_cpufreq_cpu_exit\n");
if (data) {
cpufreq_frequency_table_put_attr(policy->cpu);
acpi_io_data[policy->cpu] = NULL;
acpi_processor_unregister_performance(&data->acpi_data,
policy->cpu);
kfree(data);
}
return (0);
}
static int __init
acpi_cpufreq_init (void)
{
pr_debug("acpi_cpufreq_init\n");
return cpufreq_register_driver(&acpi_cpufreq_driver);
}
static void __exit
acpi_cpufreq_exit (void)
{
pr_debug("acpi_cpufreq_exit\n");
cpufreq_unregister_driver(&acpi_cpufreq_driver);
return;
}
