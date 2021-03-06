static int check_est_cpu(unsigned int cpuid)
{
struct cpuinfo_x86 *cpu = &cpu_data(cpuid);
return cpu_has(cpu, X86_FEATURE_EST);
}
static unsigned extract_io(u32 value, struct acpi_cpufreq_data *data)
{
struct acpi_processor_performance *perf;
int i;
perf = data->acpi_data;
for (i = 0; i < perf->state_count; i++) {
if (value == perf->states[i].status)
return data->freq_table[i].frequency;
}
return 0;
}
static unsigned extract_msr(u32 msr, struct acpi_cpufreq_data *data)
{
int i;
struct acpi_processor_performance *perf;
msr &= INTEL_MSR_RANGE;
perf = data->acpi_data;
for (i = 0; data->freq_table[i].frequency != CPUFREQ_TABLE_END; i++) {
if (msr == perf->states[data->freq_table[i].index].status)
return data->freq_table[i].frequency;
}
return data->freq_table[0].frequency;
}
static unsigned extract_freq(u32 val, struct acpi_cpufreq_data *data)
{
switch (data->cpu_feature) {
case SYSTEM_INTEL_MSR_CAPABLE:
return extract_msr(val, data);
case SYSTEM_IO_CAPABLE:
return extract_io(val, data);
default:
return 0;
}
}
static void do_drv_read(void *_cmd)
{
struct drv_cmd *cmd = _cmd;
u32 h;
switch (cmd->type) {
case SYSTEM_INTEL_MSR_CAPABLE:
rdmsr(cmd->addr.msr.reg, cmd->val, h);
break;
case SYSTEM_IO_CAPABLE:
acpi_os_read_port((acpi_io_address)cmd->addr.io.port,
&cmd->val,
(u32)cmd->addr.io.bit_width);
break;
default:
break;
}
}
static void do_drv_write(void *_cmd)
{
struct drv_cmd *cmd = _cmd;
u32 lo, hi;
switch (cmd->type) {
case SYSTEM_INTEL_MSR_CAPABLE:
rdmsr(cmd->addr.msr.reg, lo, hi);
lo = (lo & ~INTEL_MSR_RANGE) | (cmd->val & INTEL_MSR_RANGE);
wrmsr(cmd->addr.msr.reg, lo, hi);
break;
case SYSTEM_IO_CAPABLE:
acpi_os_write_port((acpi_io_address)cmd->addr.io.port,
cmd->val,
(u32)cmd->addr.io.bit_width);
break;
default:
break;
}
}
static void drv_read(struct drv_cmd *cmd)
{
int err;
cmd->val = 0;
err = smp_call_function_any(cmd->mask, do_drv_read, cmd, 1);
WARN_ON_ONCE(err);
}
static void drv_write(struct drv_cmd *cmd)
{
int this_cpu;
this_cpu = get_cpu();
if (cpumask_test_cpu(this_cpu, cmd->mask))
do_drv_write(cmd);
smp_call_function_many(cmd->mask, do_drv_write, cmd, 1);
put_cpu();
}
static u32 get_cur_val(const struct cpumask *mask)
{
struct acpi_processor_performance *perf;
struct drv_cmd cmd;
if (unlikely(cpumask_empty(mask)))
return 0;
switch (per_cpu(acfreq_data, cpumask_first(mask))->cpu_feature) {
case SYSTEM_INTEL_MSR_CAPABLE:
cmd.type = SYSTEM_INTEL_MSR_CAPABLE;
cmd.addr.msr.reg = MSR_IA32_PERF_STATUS;
break;
case SYSTEM_IO_CAPABLE:
cmd.type = SYSTEM_IO_CAPABLE;
perf = per_cpu(acfreq_data, cpumask_first(mask))->acpi_data;
cmd.addr.io.port = perf->control_register.address;
cmd.addr.io.bit_width = perf->control_register.bit_width;
break;
default:
return 0;
}
cmd.mask = mask;
drv_read(&cmd);
pr_debug("get_cur_val = %u\n", cmd.val);
return cmd.val;
}
static unsigned int get_cur_freq_on_cpu(unsigned int cpu)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, cpu);
unsigned int freq;
unsigned int cached_freq;
pr_debug("get_cur_freq_on_cpu (%d)\n", cpu);
if (unlikely(data == NULL ||
data->acpi_data == NULL || data->freq_table == NULL)) {
return 0;
}
cached_freq = data->freq_table[data->acpi_data->state].frequency;
freq = extract_freq(get_cur_val(cpumask_of(cpu)), data);
if (freq != cached_freq) {
data->resume = 1;
}
pr_debug("cur freq = %u\n", freq);
return freq;
}
static unsigned int check_freqs(const struct cpumask *mask, unsigned int freq,
struct acpi_cpufreq_data *data)
{
unsigned int cur_freq;
unsigned int i;
for (i = 0; i < 100; i++) {
cur_freq = extract_freq(get_cur_val(mask), data);
if (cur_freq == freq)
return 1;
udelay(10);
}
return 0;
}
static int acpi_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq, unsigned int relation)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, policy->cpu);
struct acpi_processor_performance *perf;
struct cpufreq_freqs freqs;
struct drv_cmd cmd;
unsigned int next_state = 0;
unsigned int next_perf_state = 0;
unsigned int i;
int result = 0;
pr_debug("acpi_cpufreq_target %d (%d)\n", target_freq, policy->cpu);
if (unlikely(data == NULL ||
data->acpi_data == NULL || data->freq_table == NULL)) {
return -ENODEV;
}
perf = data->acpi_data;
result = cpufreq_frequency_table_target(policy,
data->freq_table,
target_freq,
relation, &next_state);
if (unlikely(result)) {
result = -ENODEV;
goto out;
}
next_perf_state = data->freq_table[next_state].index;
if (perf->state == next_perf_state) {
if (unlikely(data->resume)) {
pr_debug("Called after resume, resetting to P%d\n",
next_perf_state);
data->resume = 0;
} else {
pr_debug("Already at target state (P%d)\n",
next_perf_state);
goto out;
}
}
switch (data->cpu_feature) {
case SYSTEM_INTEL_MSR_CAPABLE:
cmd.type = SYSTEM_INTEL_MSR_CAPABLE;
cmd.addr.msr.reg = MSR_IA32_PERF_CTL;
cmd.val = (u32) perf->states[next_perf_state].control;
break;
case SYSTEM_IO_CAPABLE:
cmd.type = SYSTEM_IO_CAPABLE;
cmd.addr.io.port = perf->control_register.address;
cmd.addr.io.bit_width = perf->control_register.bit_width;
cmd.val = (u32) perf->states[next_perf_state].control;
break;
default:
result = -ENODEV;
goto out;
}
if (policy->shared_type != CPUFREQ_SHARED_TYPE_ANY)
cmd.mask = policy->cpus;
else
cmd.mask = cpumask_of(policy->cpu);
freqs.old = perf->states[perf->state].core_frequency * 1000;
freqs.new = data->freq_table[next_state].frequency;
for_each_cpu(i, policy->cpus) {
freqs.cpu = i;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
}
drv_write(&cmd);
if (acpi_pstate_strict) {
if (!check_freqs(cmd.mask, freqs.new, data)) {
pr_debug("acpi_cpufreq_target failed (%d)\n",
policy->cpu);
result = -EAGAIN;
goto out;
}
}
for_each_cpu(i, policy->cpus) {
freqs.cpu = i;
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
}
perf->state = next_perf_state;
out:
return result;
}
static int acpi_cpufreq_verify(struct cpufreq_policy *policy)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, policy->cpu);
pr_debug("acpi_cpufreq_verify\n");
return cpufreq_frequency_table_verify(policy, data->freq_table);
}
static unsigned long
acpi_cpufreq_guess_freq(struct acpi_cpufreq_data *data, unsigned int cpu)
{
struct acpi_processor_performance *perf = data->acpi_data;
if (cpu_khz) {
unsigned int i;
unsigned long freq;
unsigned long freqn = perf->states[0].core_frequency * 1000;
for (i = 0; i < (perf->state_count-1); i++) {
freq = freqn;
freqn = perf->states[i+1].core_frequency * 1000;
if ((2 * cpu_khz) > (freqn + freq)) {
perf->state = i;
return freq;
}
}
perf->state = perf->state_count-1;
return freqn;
} else {
perf->state = 0;
return perf->states[0].core_frequency * 1000;
}
}
static void free_acpi_perf_data(void)
{
unsigned int i;
for_each_possible_cpu(i)
free_cpumask_var(per_cpu_ptr(acpi_perf_data, i)
->shared_cpu_map);
free_percpu(acpi_perf_data);
}
static int __init acpi_cpufreq_early_init(void)
{
unsigned int i;
pr_debug("acpi_cpufreq_early_init\n");
acpi_perf_data = alloc_percpu(struct acpi_processor_performance);
if (!acpi_perf_data) {
pr_debug("Memory allocation error for acpi_perf_data.\n");
return -ENOMEM;
}
for_each_possible_cpu(i) {
if (!zalloc_cpumask_var_node(
&per_cpu_ptr(acpi_perf_data, i)->shared_cpu_map,
GFP_KERNEL, cpu_to_node(i))) {
free_acpi_perf_data();
return -ENOMEM;
}
}
acpi_processor_preregister_performance(acpi_perf_data);
return 0;
}
static int sw_any_bug_found(const struct dmi_system_id *d)
{
bios_with_sw_any_bug = 1;
return 0;
}
static int acpi_cpufreq_blacklist(struct cpuinfo_x86 *c)
{
if (c->x86_vendor == X86_VENDOR_INTEL) {
if ((c->x86 == 15) &&
(c->x86_model == 6) &&
(c->x86_mask == 8)) {
printk(KERN_INFO "acpi-cpufreq: Intel(R) "
"Xeon(R) 7100 Errata AL30, processors may "
"lock up on frequency changes: disabling "
"acpi-cpufreq.\n");
return -ENODEV;
}
}
return 0;
}
static int acpi_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
unsigned int i;
unsigned int valid_states = 0;
unsigned int cpu = policy->cpu;
struct acpi_cpufreq_data *data;
unsigned int result = 0;
struct cpuinfo_x86 *c = &cpu_data(policy->cpu);
struct acpi_processor_performance *perf;
#ifdef CONFIG_SMP
static int blacklisted;
#endif
pr_debug("acpi_cpufreq_cpu_init\n");
#ifdef CONFIG_SMP
if (blacklisted)
return blacklisted;
blacklisted = acpi_cpufreq_blacklist(c);
if (blacklisted)
return blacklisted;
#endif
data = kzalloc(sizeof(struct acpi_cpufreq_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->acpi_data = per_cpu_ptr(acpi_perf_data, cpu);
per_cpu(acfreq_data, cpu) = data;
if (cpu_has(c, X86_FEATURE_CONSTANT_TSC))
acpi_cpufreq_driver.flags |= CPUFREQ_CONST_LOOPS;
result = acpi_processor_register_performance(data->acpi_data, cpu);
if (result)
goto err_free;
perf = data->acpi_data;
policy->shared_type = perf->shared_type;
if (policy->shared_type == CPUFREQ_SHARED_TYPE_ALL ||
policy->shared_type == CPUFREQ_SHARED_TYPE_ANY) {
cpumask_copy(policy->cpus, perf->shared_cpu_map);
}
cpumask_copy(policy->related_cpus, perf->shared_cpu_map);
#ifdef CONFIG_SMP
dmi_check_system(sw_any_bug_dmi_table);
if (bios_with_sw_any_bug && cpumask_weight(policy->cpus) == 1) {
policy->shared_type = CPUFREQ_SHARED_TYPE_ALL;
cpumask_copy(policy->cpus, cpu_core_mask(cpu));
}
#endif
if (perf->state_count <= 1) {
pr_debug("No P-States\n");
result = -ENODEV;
goto err_unreg;
}
if (perf->control_register.space_id != perf->status_register.space_id) {
result = -ENODEV;
goto err_unreg;
}
switch (perf->control_register.space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
pr_debug("SYSTEM IO addr space\n");
data->cpu_feature = SYSTEM_IO_CAPABLE;
break;
case ACPI_ADR_SPACE_FIXED_HARDWARE:
pr_debug("HARDWARE addr space\n");
if (!check_est_cpu(cpu)) {
result = -ENODEV;
goto err_unreg;
}
data->cpu_feature = SYSTEM_INTEL_MSR_CAPABLE;
break;
default:
pr_debug("Unknown addr space %d\n",
(u32) (perf->control_register.space_id));
result = -ENODEV;
goto err_unreg;
}
data->freq_table = kmalloc(sizeof(struct cpufreq_frequency_table) *
(perf->state_count+1), GFP_KERNEL);
if (!data->freq_table) {
result = -ENOMEM;
goto err_unreg;
}
policy->cpuinfo.transition_latency = 0;
for (i = 0; i < perf->state_count; i++) {
if ((perf->states[i].transition_latency * 1000) >
policy->cpuinfo.transition_latency)
policy->cpuinfo.transition_latency =
perf->states[i].transition_latency * 1000;
}
if (perf->control_register.space_id == ACPI_ADR_SPACE_FIXED_HARDWARE &&
policy->cpuinfo.transition_latency > 20 * 1000) {
policy->cpuinfo.transition_latency = 20 * 1000;
printk_once(KERN_INFO
"P-state transition latency capped at 20 uS\n");
}
for (i = 0; i < perf->state_count; i++) {
if (i > 0 && perf->states[i].core_frequency >=
data->freq_table[valid_states-1].frequency / 1000)
continue;
data->freq_table[valid_states].index = i;
data->freq_table[valid_states].frequency =
perf->states[i].core_frequency * 1000;
valid_states++;
}
data->freq_table[valid_states].frequency = CPUFREQ_TABLE_END;
perf->state = 0;
result = cpufreq_frequency_table_cpuinfo(policy, data->freq_table);
if (result)
goto err_freqfree;
if (perf->states[0].core_frequency * 1000 != policy->cpuinfo.max_freq)
printk(KERN_WARNING FW_WARN "P-state 0 is not max freq\n");
switch (perf->control_register.space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
policy->cur = acpi_cpufreq_guess_freq(data, policy->cpu);
break;
case ACPI_ADR_SPACE_FIXED_HARDWARE:
acpi_cpufreq_driver.get = get_cur_freq_on_cpu;
policy->cur = get_cur_freq_on_cpu(cpu);
break;
default:
break;
}
acpi_processor_notify_smm(THIS_MODULE);
if (boot_cpu_has(X86_FEATURE_APERFMPERF))
acpi_cpufreq_driver.getavg = cpufreq_get_measured_perf;
pr_debug("CPU%u - ACPI performance management activated.\n", cpu);
for (i = 0; i < perf->state_count; i++)
pr_debug(" %cP%d: %d MHz, %d mW, %d uS\n",
(i == perf->state ? '*' : ' '), i,
(u32) perf->states[i].core_frequency,
(u32) perf->states[i].power,
(u32) perf->states[i].transition_latency);
cpufreq_frequency_table_get_attr(data->freq_table, policy->cpu);
data->resume = 1;
return result;
err_freqfree:
kfree(data->freq_table);
err_unreg:
acpi_processor_unregister_performance(perf, cpu);
err_free:
kfree(data);
per_cpu(acfreq_data, cpu) = NULL;
return result;
}
static int acpi_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, policy->cpu);
pr_debug("acpi_cpufreq_cpu_exit\n");
if (data) {
cpufreq_frequency_table_put_attr(policy->cpu);
per_cpu(acfreq_data, policy->cpu) = NULL;
acpi_processor_unregister_performance(data->acpi_data,
policy->cpu);
kfree(data->freq_table);
kfree(data);
}
return 0;
}
static int acpi_cpufreq_resume(struct cpufreq_policy *policy)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, policy->cpu);
pr_debug("acpi_cpufreq_resume\n");
data->resume = 1;
return 0;
}
static int __init acpi_cpufreq_init(void)
{
int ret;
if (acpi_disabled)
return 0;
pr_debug("acpi_cpufreq_init\n");
ret = acpi_cpufreq_early_init();
if (ret)
return ret;
ret = cpufreq_register_driver(&acpi_cpufreq_driver);
if (ret)
free_acpi_perf_data();
return ret;
}
static void __exit acpi_cpufreq_exit(void)
{
pr_debug("acpi_cpufreq_exit\n");
cpufreq_unregister_driver(&acpi_cpufreq_driver);
free_acpi_perf_data();
}
