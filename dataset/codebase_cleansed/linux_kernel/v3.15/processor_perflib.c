static int acpi_processor_ppc_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct cpufreq_policy *policy = data;
struct acpi_processor *pr;
unsigned int ppc = 0;
if (event == CPUFREQ_START && ignore_ppc <= 0) {
ignore_ppc = 0;
return 0;
}
if (ignore_ppc)
return 0;
if (event != CPUFREQ_INCOMPATIBLE)
return 0;
mutex_lock(&performance_mutex);
pr = per_cpu(processors, policy->cpu);
if (!pr || !pr->performance)
goto out;
ppc = (unsigned int)pr->performance_platform_limit;
if (ppc >= pr->performance->state_count)
goto out;
cpufreq_verify_within_limits(policy, 0,
pr->performance->states[ppc].
core_frequency * 1000);
out:
mutex_unlock(&performance_mutex);
return 0;
}
static int acpi_processor_get_platform_limit(struct acpi_processor *pr)
{
acpi_status status = 0;
unsigned long long ppc = 0;
if (!pr)
return -EINVAL;
status = acpi_evaluate_integer(pr->handle, "_PPC", NULL, &ppc);
if (status != AE_NOT_FOUND)
acpi_processor_ppc_status |= PPC_IN_USE;
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PPC"));
return -ENODEV;
}
pr_debug("CPU %d: _PPC is %d - frequency %s limited\n", pr->id,
(int)ppc, ppc ? "" : "not");
pr->performance_platform_limit = (int)ppc;
return 0;
}
static void acpi_processor_ppc_ost(acpi_handle handle, int status)
{
if (acpi_has_method(handle, "_OST"))
acpi_evaluate_ost(handle, ACPI_PROCESSOR_NOTIFY_PERFORMANCE,
status, NULL);
}
int acpi_processor_ppc_has_changed(struct acpi_processor *pr, int event_flag)
{
int ret;
if (ignore_ppc) {
if (event_flag)
acpi_processor_ppc_ost(pr->handle, 1);
return 0;
}
ret = acpi_processor_get_platform_limit(pr);
if (event_flag) {
if (ret < 0)
acpi_processor_ppc_ost(pr->handle, 1);
else
acpi_processor_ppc_ost(pr->handle, 0);
}
if (ret < 0)
return (ret);
else
return cpufreq_update_policy(pr->id);
}
int acpi_processor_get_bios_limit(int cpu, unsigned int *limit)
{
struct acpi_processor *pr;
pr = per_cpu(processors, cpu);
if (!pr || !pr->performance || !pr->performance->state_count)
return -ENODEV;
*limit = pr->performance->states[pr->performance_platform_limit].
core_frequency * 1000;
return 0;
}
void acpi_processor_ppc_init(void)
{
if (!cpufreq_register_notifier
(&acpi_ppc_notifier_block, CPUFREQ_POLICY_NOTIFIER))
acpi_processor_ppc_status |= PPC_REGISTERED;
else
printk(KERN_DEBUG
"Warning: Processor Platform Limit not supported.\n");
}
void acpi_processor_ppc_exit(void)
{
if (acpi_processor_ppc_status & PPC_REGISTERED)
cpufreq_unregister_notifier(&acpi_ppc_notifier_block,
CPUFREQ_POLICY_NOTIFIER);
acpi_processor_ppc_status &= ~PPC_REGISTERED;
}
static int acpi_processor_get_performance_control(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = 0;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *pct = NULL;
union acpi_object obj = { 0 };
status = acpi_evaluate_object(pr->handle, "_PCT", NULL, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PCT"));
return -ENODEV;
}
pct = (union acpi_object *)buffer.pointer;
if (!pct || (pct->type != ACPI_TYPE_PACKAGE)
|| (pct->package.count != 2)) {
printk(KERN_ERR PREFIX "Invalid _PCT data\n");
result = -EFAULT;
goto end;
}
obj = pct->package.elements[0];
if ((obj.type != ACPI_TYPE_BUFFER)
|| (obj.buffer.length < sizeof(struct acpi_pct_register))
|| (obj.buffer.pointer == NULL)) {
printk(KERN_ERR PREFIX "Invalid _PCT data (control_register)\n");
result = -EFAULT;
goto end;
}
memcpy(&pr->performance->control_register, obj.buffer.pointer,
sizeof(struct acpi_pct_register));
obj = pct->package.elements[1];
if ((obj.type != ACPI_TYPE_BUFFER)
|| (obj.buffer.length < sizeof(struct acpi_pct_register))
|| (obj.buffer.pointer == NULL)) {
printk(KERN_ERR PREFIX "Invalid _PCT data (status_register)\n");
result = -EFAULT;
goto end;
}
memcpy(&pr->performance->status_register, obj.buffer.pointer,
sizeof(struct acpi_pct_register));
end:
kfree(buffer.pointer);
return result;
}
static void amd_fixup_frequency(struct acpi_processor_px *px, int i)
{
u32 hi, lo, fid, did;
int index = px->control & 0x00000007;
if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD)
return;
if ((boot_cpu_data.x86 == 0x10 && boot_cpu_data.x86_model < 10)
|| boot_cpu_data.x86 == 0x11) {
rdmsr(MSR_AMD_PSTATE_DEF_BASE + index, lo, hi);
if (!(hi & BIT(31)))
return;
fid = lo & 0x3f;
did = (lo >> 6) & 7;
if (boot_cpu_data.x86 == 0x10)
px->core_frequency = (100 * (fid + 0x10)) >> did;
else
px->core_frequency = (100 * (fid + 8)) >> did;
}
}
static void amd_fixup_frequency(struct acpi_processor_px *px, int i) {}
static int acpi_processor_get_performance_states(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = AE_OK;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer format = { sizeof("NNNNNN"), "NNNNNN" };
struct acpi_buffer state = { 0, NULL };
union acpi_object *pss = NULL;
int i;
int last_invalid = -1;
status = acpi_evaluate_object(pr->handle, "_PSS", NULL, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PSS"));
return -ENODEV;
}
pss = buffer.pointer;
if (!pss || (pss->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_ERR PREFIX "Invalid _PSS data\n");
result = -EFAULT;
goto end;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %d performance states\n",
pss->package.count));
pr->performance->state_count = pss->package.count;
pr->performance->states =
kmalloc(sizeof(struct acpi_processor_px) * pss->package.count,
GFP_KERNEL);
if (!pr->performance->states) {
result = -ENOMEM;
goto end;
}
for (i = 0; i < pr->performance->state_count; i++) {
struct acpi_processor_px *px = &(pr->performance->states[i]);
state.length = sizeof(struct acpi_processor_px);
state.pointer = px;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Extracting state %d\n", i));
status = acpi_extract_package(&(pss->package.elements[i]),
&format, &state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Invalid _PSS data"));
result = -EFAULT;
kfree(pr->performance->states);
goto end;
}
amd_fixup_frequency(px, i);
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"State [%d]: core_frequency[%d] power[%d] transition_latency[%d] bus_master_latency[%d] control[0x%x] status[0x%x]\n",
i,
(u32) px->core_frequency,
(u32) px->power,
(u32) px->transition_latency,
(u32) px->bus_master_latency,
(u32) px->control, (u32) px->status));
if (!px->core_frequency ||
((u32)(px->core_frequency * 1000) !=
(px->core_frequency * 1000))) {
printk(KERN_ERR FW_BUG PREFIX
"Invalid BIOS _PSS frequency found for processor %d: 0x%llx MHz\n",
pr->id, px->core_frequency);
if (last_invalid == -1)
last_invalid = i;
} else {
if (last_invalid != -1) {
memcpy(&(pr->performance->states[last_invalid]),
px, sizeof(struct acpi_processor_px));
++last_invalid;
}
}
}
if (last_invalid == 0) {
printk(KERN_ERR FW_BUG PREFIX
"No valid BIOS _PSS frequency found for processor %d\n", pr->id);
result = -EFAULT;
kfree(pr->performance->states);
pr->performance->states = NULL;
}
if (last_invalid > 0)
pr->performance->state_count = last_invalid;
end:
kfree(buffer.pointer);
return result;
}
int acpi_processor_get_performance_info(struct acpi_processor *pr)
{
int result = 0;
if (!pr || !pr->performance || !pr->handle)
return -EINVAL;
if (!acpi_has_method(pr->handle, "_PCT")) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"ACPI-based processor performance control unavailable\n"));
return -ENODEV;
}
result = acpi_processor_get_performance_control(pr);
if (result)
goto update_bios;
result = acpi_processor_get_performance_states(pr);
if (result)
goto update_bios;
if (ignore_ppc != 1)
result = acpi_processor_get_platform_limit(pr);
return result;
update_bios:
#ifdef CONFIG_X86
if (acpi_has_method(pr->handle, "_PPC")) {
if(boot_cpu_has(X86_FEATURE_EST))
printk(KERN_WARNING FW_BUG "BIOS needs update for CPU "
"frequency support\n");
}
#endif
return result;
}
int acpi_processor_notify_smm(struct module *calling_module)
{
acpi_status status;
static int is_done = 0;
if (!(acpi_processor_ppc_status & PPC_REGISTERED))
return -EBUSY;
if (!try_module_get(calling_module))
return -EINVAL;
if (is_done > 0) {
module_put(calling_module);
return 0;
} else if (is_done < 0) {
module_put(calling_module);
return is_done;
}
is_done = -EIO;
if ((!acpi_gbl_FADT.smi_command) || (!acpi_gbl_FADT.pstate_control)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No SMI port or pstate_control\n"));
module_put(calling_module);
return 0;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Writing pstate_control [0x%x] to smi_command [0x%x]\n",
acpi_gbl_FADT.pstate_control, acpi_gbl_FADT.smi_command));
status = acpi_os_write_port(acpi_gbl_FADT.smi_command,
(u32) acpi_gbl_FADT.pstate_control, 8);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Failed to write pstate_control [0x%x] to "
"smi_command [0x%x]", acpi_gbl_FADT.pstate_control,
acpi_gbl_FADT.smi_command));
module_put(calling_module);
return status;
}
is_done = 1;
if (!(acpi_processor_ppc_status & PPC_IN_USE))
module_put(calling_module);
return 0;
}
static int acpi_processor_get_psd(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = AE_OK;
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
struct acpi_buffer format = {sizeof("NNNNN"), "NNNNN"};
struct acpi_buffer state = {0, NULL};
union acpi_object *psd = NULL;
struct acpi_psd_package *pdomain;
status = acpi_evaluate_object(pr->handle, "_PSD", NULL, &buffer);
if (ACPI_FAILURE(status)) {
return -ENODEV;
}
psd = buffer.pointer;
if (!psd || (psd->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_ERR PREFIX "Invalid _PSD data\n");
result = -EFAULT;
goto end;
}
if (psd->package.count != 1) {
printk(KERN_ERR PREFIX "Invalid _PSD data\n");
result = -EFAULT;
goto end;
}
pdomain = &(pr->performance->domain_info);
state.length = sizeof(struct acpi_psd_package);
state.pointer = pdomain;
status = acpi_extract_package(&(psd->package.elements[0]),
&format, &state);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR PREFIX "Invalid _PSD data\n");
result = -EFAULT;
goto end;
}
if (pdomain->num_entries != ACPI_PSD_REV0_ENTRIES) {
printk(KERN_ERR PREFIX "Unknown _PSD:num_entries\n");
result = -EFAULT;
goto end;
}
if (pdomain->revision != ACPI_PSD_REV0_REVISION) {
printk(KERN_ERR PREFIX "Unknown _PSD:revision\n");
result = -EFAULT;
goto end;
}
if (pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ALL &&
pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ANY &&
pdomain->coord_type != DOMAIN_COORD_TYPE_HW_ALL) {
printk(KERN_ERR PREFIX "Invalid _PSD:coord_type\n");
result = -EFAULT;
goto end;
}
end:
kfree(buffer.pointer);
return result;
}
int acpi_processor_preregister_performance(
struct acpi_processor_performance __percpu *performance)
{
int count_target;
int retval = 0;
unsigned int i, j;
cpumask_var_t covered_cpus;
struct acpi_processor *pr;
struct acpi_psd_package *pdomain;
struct acpi_processor *match_pr;
struct acpi_psd_package *match_pdomain;
if (!zalloc_cpumask_var(&covered_cpus, GFP_KERNEL))
return -ENOMEM;
mutex_lock(&performance_mutex);
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr) {
continue;
}
if (pr->performance) {
retval = -EBUSY;
goto err_out;
}
if (!performance || !per_cpu_ptr(performance, i)) {
retval = -EINVAL;
goto err_out;
}
}
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr)
continue;
pr->performance = per_cpu_ptr(performance, i);
cpumask_set_cpu(i, pr->performance->shared_cpu_map);
if (acpi_processor_get_psd(pr)) {
retval = -EINVAL;
continue;
}
}
if (retval)
goto err_ret;
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr)
continue;
if (cpumask_test_cpu(i, covered_cpus))
continue;
pdomain = &(pr->performance->domain_info);
cpumask_set_cpu(i, pr->performance->shared_cpu_map);
cpumask_set_cpu(i, covered_cpus);
if (pdomain->num_processors <= 1)
continue;
count_target = pdomain->num_processors;
if (pdomain->coord_type == DOMAIN_COORD_TYPE_SW_ALL)
pr->performance->shared_type = CPUFREQ_SHARED_TYPE_ALL;
else if (pdomain->coord_type == DOMAIN_COORD_TYPE_HW_ALL)
pr->performance->shared_type = CPUFREQ_SHARED_TYPE_HW;
else if (pdomain->coord_type == DOMAIN_COORD_TYPE_SW_ANY)
pr->performance->shared_type = CPUFREQ_SHARED_TYPE_ANY;
for_each_possible_cpu(j) {
if (i == j)
continue;
match_pr = per_cpu(processors, j);
if (!match_pr)
continue;
match_pdomain = &(match_pr->performance->domain_info);
if (match_pdomain->domain != pdomain->domain)
continue;
if (match_pdomain->num_processors != count_target) {
retval = -EINVAL;
goto err_ret;
}
if (pdomain->coord_type != match_pdomain->coord_type) {
retval = -EINVAL;
goto err_ret;
}
cpumask_set_cpu(j, covered_cpus);
cpumask_set_cpu(j, pr->performance->shared_cpu_map);
}
for_each_possible_cpu(j) {
if (i == j)
continue;
match_pr = per_cpu(processors, j);
if (!match_pr)
continue;
match_pdomain = &(match_pr->performance->domain_info);
if (match_pdomain->domain != pdomain->domain)
continue;
match_pr->performance->shared_type =
pr->performance->shared_type;
cpumask_copy(match_pr->performance->shared_cpu_map,
pr->performance->shared_cpu_map);
}
}
err_ret:
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr || !pr->performance)
continue;
if (retval) {
cpumask_clear(pr->performance->shared_cpu_map);
cpumask_set_cpu(i, pr->performance->shared_cpu_map);
pr->performance->shared_type = CPUFREQ_SHARED_TYPE_ALL;
}
pr->performance = NULL;
}
err_out:
mutex_unlock(&performance_mutex);
free_cpumask_var(covered_cpus);
return retval;
}
int
acpi_processor_register_performance(struct acpi_processor_performance
*performance, unsigned int cpu)
{
struct acpi_processor *pr;
if (!(acpi_processor_ppc_status & PPC_REGISTERED))
return -EINVAL;
mutex_lock(&performance_mutex);
pr = per_cpu(processors, cpu);
if (!pr) {
mutex_unlock(&performance_mutex);
return -ENODEV;
}
if (pr->performance) {
mutex_unlock(&performance_mutex);
return -EBUSY;
}
WARN_ON(!performance);
pr->performance = performance;
if (acpi_processor_get_performance_info(pr)) {
pr->performance = NULL;
mutex_unlock(&performance_mutex);
return -EIO;
}
mutex_unlock(&performance_mutex);
return 0;
}
void
acpi_processor_unregister_performance(struct acpi_processor_performance
*performance, unsigned int cpu)
{
struct acpi_processor *pr;
mutex_lock(&performance_mutex);
pr = per_cpu(processors, cpu);
if (!pr) {
mutex_unlock(&performance_mutex);
return;
}
if (pr->performance)
kfree(pr->performance->states);
pr->performance = NULL;
mutex_unlock(&performance_mutex);
return;
}
