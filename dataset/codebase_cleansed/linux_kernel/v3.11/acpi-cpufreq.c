static bool boost_state(unsigned int cpu)
{
u32 lo, hi;
u64 msr;
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_INTEL:
rdmsr_on_cpu(cpu, MSR_IA32_MISC_ENABLE, &lo, &hi);
msr = lo | ((u64)hi << 32);
return !(msr & MSR_IA32_MISC_ENABLE_TURBO_DISABLE);
case X86_VENDOR_AMD:
rdmsr_on_cpu(cpu, MSR_K7_HWCR, &lo, &hi);
msr = lo | ((u64)hi << 32);
return !(msr & MSR_K7_HWCR_CPB_DIS);
}
return false;
}
static void boost_set_msrs(bool enable, const struct cpumask *cpumask)
{
u32 cpu;
u32 msr_addr;
u64 msr_mask;
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_INTEL:
msr_addr = MSR_IA32_MISC_ENABLE;
msr_mask = MSR_IA32_MISC_ENABLE_TURBO_DISABLE;
break;
case X86_VENDOR_AMD:
msr_addr = MSR_K7_HWCR;
msr_mask = MSR_K7_HWCR_CPB_DIS;
break;
default:
return;
}
rdmsr_on_cpus(cpumask, msr_addr, msrs);
for_each_cpu(cpu, cpumask) {
struct msr *reg = per_cpu_ptr(msrs, cpu);
if (enable)
reg->q &= ~msr_mask;
else
reg->q |= msr_mask;
}
wrmsr_on_cpus(cpumask, msr_addr, msrs);
}
static ssize_t _store_boost(const char *buf, size_t count)
{
int ret;
unsigned long val = 0;
if (!boost_supported)
return -EINVAL;
ret = kstrtoul(buf, 10, &val);
if (ret || (val > 1))
return -EINVAL;
if ((val && boost_enabled) || (!val && !boost_enabled))
return count;
get_online_cpus();
boost_set_msrs(val, cpu_online_mask);
put_online_cpus();
boost_enabled = val;
pr_debug("Core Boosting %sabled.\n", val ? "en" : "dis");
return count;
}
static ssize_t store_global_boost(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
return _store_boost(buf, count);
}
static ssize_t show_global_boost(struct kobject *kobj,
struct attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", boost_enabled);
}
static ssize_t show_freqdomain_cpus(struct cpufreq_policy *policy, char *buf)
{
struct acpi_cpufreq_data *data = per_cpu(acfreq_data, policy->cpu);
return cpufreq_show_cpus(data->freqdomain_cpus, buf);
}
static ssize_t store_cpb(struct cpufreq_policy *policy, const char *buf,
size_t count)
{
return _store_boost(buf, count);
}
static ssize_t show_cpb(struct cpufreq_policy *policy, char *buf)
{
return sprintf(buf, "%u\n", boost_enabled);
}
static int check_est_cpu(unsigned int cpuid)
{
struct cpuinfo_x86 *cpu = &cpu_data(cpuid);
return cpu_has(cpu, X86_FEATURE_EST);
}
static int check_amd_hwpstate_cpu(unsigned int cpuid)
{
struct cpuinfo_x86 *cpu = &cpu_data(cpuid);
return cpu_has(cpu, X86_FEATURE_HW_PSTATE);
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
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD)
msr &= AMD_MSR_RANGE;
else
msr &= INTEL_MSR_RANGE;
perf = data->acpi_data;
for (i = 0; data->freq_table[i].frequency != CPUFREQ_TABLE_END; i++) {
if (msr == perf->states[data->freq_table[i].driver_data].status)
return data->freq_table[i].frequency;
}
return data->freq_table[0].frequency;
}
static unsigned extract_freq(u32 val, struct acpi_cpufreq_data *data)
{
switch (data->cpu_feature) {
case SYSTEM_INTEL_MSR_CAPABLE:
case SYSTEM_AMD_MSR_CAPABLE:
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
case SYSTEM_AMD_MSR_CAPABLE:
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
case SYSTEM_AMD_MSR_CAPABLE:
wrmsr(cmd->addr.msr.reg, cmd->val, 0);
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
cmd.addr.msr.reg = MSR_IA32_PERF_CTL;
break;
case SYSTEM_AMD_MSR_CAPABLE:
cmd.type = SYSTEM_AMD_MSR_CAPABLE;
cmd.addr.msr.reg = MSR_AMD_PERF_CTL;
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
next_perf_state = data->freq_table[next_state].driver_data;
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
case SYSTEM_AMD_MSR_CAPABLE:
cmd.type = SYSTEM_AMD_MSR_CAPABLE;
cmd.addr.msr.reg = MSR_AMD_PERF_CTL;
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
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
drv_write(&cmd);
if (acpi_pstate_strict) {
if (!check_freqs(cmd.mask, freqs.new, data)) {
pr_debug("acpi_cpufreq_target failed (%d)\n",
policy->cpu);
result = -EAGAIN;
freqs.new = freqs.old;
}
}
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
if (!result)
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
static int boost_notify(struct notifier_block *nb, unsigned long action,
void *hcpu)
{
unsigned cpu = (long)hcpu;
const struct cpumask *cpumask;
cpumask = get_cpu_mask(cpu);
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
boost_set_msrs(boost_enabled, cpumask);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
boost_set_msrs(1, cpumask);
break;
default:
break;
}
return NOTIFY_OK;
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
if (!zalloc_cpumask_var(&data->freqdomain_cpus, GFP_KERNEL)) {
result = -ENOMEM;
goto err_free;
}
data->acpi_data = per_cpu_ptr(acpi_perf_data, cpu);
per_cpu(acfreq_data, cpu) = data;
if (cpu_has(c, X86_FEATURE_CONSTANT_TSC))
acpi_cpufreq_driver.flags |= CPUFREQ_CONST_LOOPS;
result = acpi_processor_register_performance(data->acpi_data, cpu);
if (result)
goto err_free_mask;
perf = data->acpi_data;
policy->shared_type = perf->shared_type;
if (policy->shared_type == CPUFREQ_SHARED_TYPE_ALL ||
policy->shared_type == CPUFREQ_SHARED_TYPE_ANY) {
cpumask_copy(policy->cpus, perf->shared_cpu_map);
}
cpumask_copy(data->freqdomain_cpus, perf->shared_cpu_map);
#ifdef CONFIG_SMP
dmi_check_system(sw_any_bug_dmi_table);
if (bios_with_sw_any_bug && !policy_is_shared(policy)) {
policy->shared_type = CPUFREQ_SHARED_TYPE_ALL;
cpumask_copy(policy->cpus, cpu_core_mask(cpu));
}
if (check_amd_hwpstate_cpu(cpu) && !acpi_pstate_strict) {
cpumask_clear(policy->cpus);
cpumask_set_cpu(cpu, policy->cpus);
cpumask_copy(data->freqdomain_cpus, cpu_sibling_mask(cpu));
policy->shared_type = CPUFREQ_SHARED_TYPE_HW;
pr_info_once(PFX "overriding BIOS provided _PSD data\n");
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
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD &&
boot_cpu_data.x86 == 0xf) {
pr_debug("AMD K8 systems must use native drivers.\n");
result = -ENODEV;
goto err_unreg;
}
pr_debug("SYSTEM IO addr space\n");
data->cpu_feature = SYSTEM_IO_CAPABLE;
break;
case ACPI_ADR_SPACE_FIXED_HARDWARE:
pr_debug("HARDWARE addr space\n");
if (check_est_cpu(cpu)) {
data->cpu_feature = SYSTEM_INTEL_MSR_CAPABLE;
break;
}
if (check_amd_hwpstate_cpu(cpu)) {
data->cpu_feature = SYSTEM_AMD_MSR_CAPABLE;
break;
}
result = -ENODEV;
goto err_unreg;
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
data->freq_table[valid_states].driver_data = i;
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
err_free_mask:
free_cpumask_var(data->freqdomain_cpus);
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
free_cpumask_var(data->freqdomain_cpus);
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
static void __init acpi_cpufreq_boost_init(void)
{
if (boot_cpu_has(X86_FEATURE_CPB) || boot_cpu_has(X86_FEATURE_IDA)) {
msrs = msrs_alloc();
if (!msrs)
return;
boost_supported = true;
boost_enabled = boost_state(0);
get_online_cpus();
boost_set_msrs(boost_enabled, cpu_online_mask);
register_cpu_notifier(&boost_nb);
put_online_cpus();
} else
global_boost.attr.mode = 0444;
if (cpufreq_sysfs_create_file(&(global_boost.attr)))
pr_warn(PFX "could not register global boost sysfs file\n");
else
pr_debug("registered global boost sysfs file\n");
}
static void __exit acpi_cpufreq_boost_exit(void)
{
cpufreq_sysfs_remove_file(&(global_boost.attr));
if (msrs) {
unregister_cpu_notifier(&boost_nb);
msrs_free(msrs);
msrs = NULL;
}
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
#ifdef CONFIG_X86_ACPI_CPUFREQ_CPB
if (check_amd_hwpstate_cpu(0)) {
struct freq_attr **iter;
pr_debug("adding sysfs entry for cpb\n");
for (iter = acpi_cpufreq_attr; *iter != NULL; iter++)
;
if (iter[1] == NULL)
*iter = &cpb;
}
#endif
ret = cpufreq_register_driver(&acpi_cpufreq_driver);
if (ret)
free_acpi_perf_data();
else
acpi_cpufreq_boost_init();
return ret;
}
static void __exit acpi_cpufreq_exit(void)
{
pr_debug("acpi_cpufreq_exit\n");
acpi_cpufreq_boost_exit();
cpufreq_unregister_driver(&acpi_cpufreq_driver);
free_acpi_perf_data();
}
