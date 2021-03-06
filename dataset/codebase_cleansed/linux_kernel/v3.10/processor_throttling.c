static int acpi_processor_update_tsd_coord(void)
{
int count, count_target;
int retval = 0;
unsigned int i, j;
cpumask_var_t covered_cpus;
struct acpi_processor *pr, *match_pr;
struct acpi_tsd_package *pdomain, *match_pdomain;
struct acpi_processor_throttling *pthrottling, *match_pthrottling;
if (!zalloc_cpumask_var(&covered_cpus, GFP_KERNEL))
return -ENOMEM;
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr)
continue;
pthrottling = &(pr->throttling);
if (!pthrottling->tsd_valid_flag) {
retval = -EINVAL;
break;
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
pthrottling = &pr->throttling;
pdomain = &(pthrottling->domain_info);
cpumask_set_cpu(i, pthrottling->shared_cpu_map);
cpumask_set_cpu(i, covered_cpus);
if (pdomain->num_processors <= 1)
continue;
count_target = pdomain->num_processors;
count = 1;
for_each_possible_cpu(j) {
if (i == j)
continue;
match_pr = per_cpu(processors, j);
if (!match_pr)
continue;
match_pthrottling = &(match_pr->throttling);
match_pdomain = &(match_pthrottling->domain_info);
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
cpumask_set_cpu(j, pthrottling->shared_cpu_map);
count++;
}
for_each_possible_cpu(j) {
if (i == j)
continue;
match_pr = per_cpu(processors, j);
if (!match_pr)
continue;
match_pthrottling = &(match_pr->throttling);
match_pdomain = &(match_pthrottling->domain_info);
if (match_pdomain->domain != pdomain->domain)
continue;
cpumask_copy(match_pthrottling->shared_cpu_map,
pthrottling->shared_cpu_map);
}
}
err_ret:
free_cpumask_var(covered_cpus);
for_each_possible_cpu(i) {
pr = per_cpu(processors, i);
if (!pr)
continue;
if (retval) {
pthrottling = &(pr->throttling);
cpumask_clear(pthrottling->shared_cpu_map);
cpumask_set_cpu(i, pthrottling->shared_cpu_map);
pthrottling->shared_type = DOMAIN_COORD_TYPE_SW_ALL;
}
}
return retval;
}
void acpi_processor_throttling_init(void)
{
if (acpi_processor_update_tsd_coord()) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Assume no T-state coordination\n"));
}
return;
}
static int acpi_processor_throttling_notifier(unsigned long event, void *data)
{
struct throttling_tstate *p_tstate = data;
struct acpi_processor *pr;
unsigned int cpu ;
int target_state;
struct acpi_processor_limit *p_limit;
struct acpi_processor_throttling *p_throttling;
cpu = p_tstate->cpu;
pr = per_cpu(processors, cpu);
if (!pr) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Invalid pr pointer\n"));
return 0;
}
if (!pr->flags.throttling) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Throttling control is "
"unsupported on CPU %d\n", cpu));
return 0;
}
target_state = p_tstate->target_state;
p_throttling = &(pr->throttling);
switch (event) {
case THROTTLING_PRECHANGE:
p_limit = &pr->limit;
if (p_limit->thermal.tx > target_state)
target_state = p_limit->thermal.tx;
if (p_limit->user.tx > target_state)
target_state = p_limit->user.tx;
if (pr->throttling_platform_limit > target_state)
target_state = pr->throttling_platform_limit;
if (target_state >= p_throttling->state_count) {
printk(KERN_WARNING
"Exceed the limit of T-state \n");
target_state = p_throttling->state_count - 1;
}
p_tstate->target_state = target_state;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "PreChange Event:"
"target T-state of CPU %d is T%d\n",
cpu, target_state));
break;
case THROTTLING_POSTCHANGE:
p_throttling->state = target_state;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "PostChange Event:"
"CPU %d is switched to T%d\n",
cpu, target_state));
break;
default:
printk(KERN_WARNING
"Unsupported Throttling notifier event\n");
break;
}
return 0;
}
static int acpi_processor_get_platform_limit(struct acpi_processor *pr)
{
acpi_status status = 0;
unsigned long long tpc = 0;
if (!pr)
return -EINVAL;
if (ignore_tpc)
goto end;
status = acpi_evaluate_integer(pr->handle, "_TPC", NULL, &tpc);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _TPC"));
}
return -ENODEV;
}
end:
pr->throttling_platform_limit = (int)tpc;
return 0;
}
int acpi_processor_tstate_has_changed(struct acpi_processor *pr)
{
int result = 0;
int throttling_limit;
int current_state;
struct acpi_processor_limit *limit;
int target_state;
if (ignore_tpc)
return 0;
result = acpi_processor_get_platform_limit(pr);
if (result) {
return result;
}
throttling_limit = pr->throttling_platform_limit;
if (throttling_limit >= pr->throttling.state_count) {
return -EINVAL;
}
current_state = pr->throttling.state;
if (current_state > throttling_limit) {
limit = &pr->limit;
target_state = throttling_limit;
if (limit->thermal.tx > target_state)
target_state = limit->thermal.tx;
if (limit->user.tx > target_state)
target_state = limit->user.tx;
} else if (current_state == throttling_limit) {
return 0;
} else {
target_state = throttling_limit;
}
return acpi_processor_set_throttling(pr, target_state, false);
}
void acpi_processor_reevaluate_tstate(struct acpi_processor *pr,
unsigned long action)
{
int result = 0;
if (action == CPU_DEAD) {
pr->flags.throttling = 0;
return;
}
if (!pr->throttling.state_count) {
pr->flags.throttling = 0;
return;
}
pr->flags.throttling = 1;
result = acpi_processor_get_throttling(pr);
if (result)
goto end;
if (pr->throttling.state) {
result = acpi_processor_set_throttling(pr, 0, false);
if (result)
goto end;
}
end:
if (result)
pr->flags.throttling = 0;
}
static int acpi_processor_get_throttling_control(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = 0;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *ptc = NULL;
union acpi_object obj = { 0 };
struct acpi_processor_throttling *throttling;
status = acpi_evaluate_object(pr->handle, "_PTC", NULL, &buffer);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PTC"));
}
return -ENODEV;
}
ptc = (union acpi_object *)buffer.pointer;
if (!ptc || (ptc->type != ACPI_TYPE_PACKAGE)
|| (ptc->package.count != 2)) {
printk(KERN_ERR PREFIX "Invalid _PTC data\n");
result = -EFAULT;
goto end;
}
obj = ptc->package.elements[0];
if ((obj.type != ACPI_TYPE_BUFFER)
|| (obj.buffer.length < sizeof(struct acpi_ptc_register))
|| (obj.buffer.pointer == NULL)) {
printk(KERN_ERR PREFIX
"Invalid _PTC data (control_register)\n");
result = -EFAULT;
goto end;
}
memcpy(&pr->throttling.control_register, obj.buffer.pointer,
sizeof(struct acpi_ptc_register));
obj = ptc->package.elements[1];
if ((obj.type != ACPI_TYPE_BUFFER)
|| (obj.buffer.length < sizeof(struct acpi_ptc_register))
|| (obj.buffer.pointer == NULL)) {
printk(KERN_ERR PREFIX "Invalid _PTC data (status_register)\n");
result = -EFAULT;
goto end;
}
memcpy(&pr->throttling.status_register, obj.buffer.pointer,
sizeof(struct acpi_ptc_register));
throttling = &pr->throttling;
if ((throttling->control_register.bit_width +
throttling->control_register.bit_offset) > 32) {
printk(KERN_ERR PREFIX "Invalid _PTC control register\n");
result = -EFAULT;
goto end;
}
if ((throttling->status_register.bit_width +
throttling->status_register.bit_offset) > 32) {
printk(KERN_ERR PREFIX "Invalid _PTC status register\n");
result = -EFAULT;
goto end;
}
end:
kfree(buffer.pointer);
return result;
}
static int acpi_processor_get_throttling_states(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = AE_OK;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer format = { sizeof("NNNNN"), "NNNNN" };
struct acpi_buffer state = { 0, NULL };
union acpi_object *tss = NULL;
int i;
status = acpi_evaluate_object(pr->handle, "_TSS", NULL, &buffer);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _TSS"));
}
return -ENODEV;
}
tss = buffer.pointer;
if (!tss || (tss->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_ERR PREFIX "Invalid _TSS data\n");
result = -EFAULT;
goto end;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %d throttling states\n",
tss->package.count));
pr->throttling.state_count = tss->package.count;
pr->throttling.states_tss =
kmalloc(sizeof(struct acpi_processor_tx_tss) * tss->package.count,
GFP_KERNEL);
if (!pr->throttling.states_tss) {
result = -ENOMEM;
goto end;
}
for (i = 0; i < pr->throttling.state_count; i++) {
struct acpi_processor_tx_tss *tx =
(struct acpi_processor_tx_tss *)&(pr->throttling.
states_tss[i]);
state.length = sizeof(struct acpi_processor_tx_tss);
state.pointer = tx;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Extracting state %d\n", i));
status = acpi_extract_package(&(tss->package.elements[i]),
&format, &state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Invalid _TSS data"));
result = -EFAULT;
kfree(pr->throttling.states_tss);
goto end;
}
if (!tx->freqpercentage) {
printk(KERN_ERR PREFIX
"Invalid _TSS data: freq is zero\n");
result = -EFAULT;
kfree(pr->throttling.states_tss);
goto end;
}
}
end:
kfree(buffer.pointer);
return result;
}
static int acpi_processor_get_tsd(struct acpi_processor *pr)
{
int result = 0;
acpi_status status = AE_OK;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer format = { sizeof("NNNNN"), "NNNNN" };
struct acpi_buffer state = { 0, NULL };
union acpi_object *tsd = NULL;
struct acpi_tsd_package *pdomain;
struct acpi_processor_throttling *pthrottling;
pthrottling = &pr->throttling;
pthrottling->tsd_valid_flag = 0;
status = acpi_evaluate_object(pr->handle, "_TSD", NULL, &buffer);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _TSD"));
}
return -ENODEV;
}
tsd = buffer.pointer;
if (!tsd || (tsd->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_ERR PREFIX "Invalid _TSD data\n");
result = -EFAULT;
goto end;
}
if (tsd->package.count != 1) {
printk(KERN_ERR PREFIX "Invalid _TSD data\n");
result = -EFAULT;
goto end;
}
pdomain = &(pr->throttling.domain_info);
state.length = sizeof(struct acpi_tsd_package);
state.pointer = pdomain;
status = acpi_extract_package(&(tsd->package.elements[0]),
&format, &state);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR PREFIX "Invalid _TSD data\n");
result = -EFAULT;
goto end;
}
if (pdomain->num_entries != ACPI_TSD_REV0_ENTRIES) {
printk(KERN_ERR PREFIX "Unknown _TSD:num_entries\n");
result = -EFAULT;
goto end;
}
if (pdomain->revision != ACPI_TSD_REV0_REVISION) {
printk(KERN_ERR PREFIX "Unknown _TSD:revision\n");
result = -EFAULT;
goto end;
}
pthrottling = &pr->throttling;
pthrottling->tsd_valid_flag = 1;
pthrottling->shared_type = pdomain->coord_type;
cpumask_set_cpu(pr->id, pthrottling->shared_cpu_map);
if (pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ALL &&
pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ANY &&
pdomain->coord_type != DOMAIN_COORD_TYPE_HW_ALL) {
pthrottling->tsd_valid_flag = 0;
pthrottling->shared_type = DOMAIN_COORD_TYPE_SW_ALL;
}
end:
kfree(buffer.pointer);
return result;
}
static int acpi_processor_get_throttling_fadt(struct acpi_processor *pr)
{
int state = 0;
u32 value = 0;
u32 duty_mask = 0;
u32 duty_value = 0;
if (!pr)
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
pr->throttling.state = 0;
duty_mask = pr->throttling.state_count - 1;
duty_mask <<= pr->throttling.duty_offset;
local_irq_disable();
value = inl(pr->throttling.address);
if (value & 0x10) {
duty_value = value & duty_mask;
duty_value >>= pr->throttling.duty_offset;
if (duty_value)
state = pr->throttling.state_count - duty_value;
}
pr->throttling.state = state;
local_irq_enable();
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Throttling state is T%d (%d%% throttling applied)\n",
state, pr->throttling.states[state].performance));
return 0;
}
static int acpi_throttling_rdmsr(u64 *value)
{
u64 msr_high, msr_low;
u64 msr = 0;
int ret = -1;
if ((this_cpu_read(cpu_info.x86_vendor) != X86_VENDOR_INTEL) ||
!this_cpu_has(X86_FEATURE_ACPI)) {
printk(KERN_ERR PREFIX
"HARDWARE addr space,NOT supported yet\n");
} else {
msr_low = 0;
msr_high = 0;
rdmsr_safe(MSR_IA32_THERM_CONTROL,
(u32 *)&msr_low , (u32 *) &msr_high);
msr = (msr_high << 32) | msr_low;
*value = (u64) msr;
ret = 0;
}
return ret;
}
static int acpi_throttling_wrmsr(u64 value)
{
int ret = -1;
u64 msr;
if ((this_cpu_read(cpu_info.x86_vendor) != X86_VENDOR_INTEL) ||
!this_cpu_has(X86_FEATURE_ACPI)) {
printk(KERN_ERR PREFIX
"HARDWARE addr space,NOT supported yet\n");
} else {
msr = value;
wrmsr_safe(MSR_IA32_THERM_CONTROL,
msr & 0xffffffff, msr >> 32);
ret = 0;
}
return ret;
}
static int acpi_throttling_rdmsr(u64 *value)
{
printk(KERN_ERR PREFIX
"HARDWARE addr space,NOT supported yet\n");
return -1;
}
static int acpi_throttling_wrmsr(u64 value)
{
printk(KERN_ERR PREFIX
"HARDWARE addr space,NOT supported yet\n");
return -1;
}
static int acpi_read_throttling_status(struct acpi_processor *pr,
u64 *value)
{
u32 bit_width, bit_offset;
u32 ptc_value;
u64 ptc_mask;
struct acpi_processor_throttling *throttling;
int ret = -1;
throttling = &pr->throttling;
switch (throttling->status_register.space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
bit_width = throttling->status_register.bit_width;
bit_offset = throttling->status_register.bit_offset;
acpi_os_read_port((acpi_io_address) throttling->status_register.
address, &ptc_value,
(u32) (bit_width + bit_offset));
ptc_mask = (1 << bit_width) - 1;
*value = (u64) ((ptc_value >> bit_offset) & ptc_mask);
ret = 0;
break;
case ACPI_ADR_SPACE_FIXED_HARDWARE:
ret = acpi_throttling_rdmsr(value);
break;
default:
printk(KERN_ERR PREFIX "Unknown addr space %d\n",
(u32) (throttling->status_register.space_id));
}
return ret;
}
static int acpi_write_throttling_state(struct acpi_processor *pr,
u64 value)
{
u32 bit_width, bit_offset;
u64 ptc_value;
u64 ptc_mask;
struct acpi_processor_throttling *throttling;
int ret = -1;
throttling = &pr->throttling;
switch (throttling->control_register.space_id) {
case ACPI_ADR_SPACE_SYSTEM_IO:
bit_width = throttling->control_register.bit_width;
bit_offset = throttling->control_register.bit_offset;
ptc_mask = (1 << bit_width) - 1;
ptc_value = value & ptc_mask;
acpi_os_write_port((acpi_io_address) throttling->
control_register.address,
(u32) (ptc_value << bit_offset),
(u32) (bit_width + bit_offset));
ret = 0;
break;
case ACPI_ADR_SPACE_FIXED_HARDWARE:
ret = acpi_throttling_wrmsr(value);
break;
default:
printk(KERN_ERR PREFIX "Unknown addr space %d\n",
(u32) (throttling->control_register.space_id));
}
return ret;
}
static int acpi_get_throttling_state(struct acpi_processor *pr,
u64 value)
{
int i;
for (i = 0; i < pr->throttling.state_count; i++) {
struct acpi_processor_tx_tss *tx =
(struct acpi_processor_tx_tss *)&(pr->throttling.
states_tss[i]);
if (tx->control == value)
return i;
}
return -1;
}
static int acpi_get_throttling_value(struct acpi_processor *pr,
int state, u64 *value)
{
int ret = -1;
if (state >= 0 && state <= pr->throttling.state_count) {
struct acpi_processor_tx_tss *tx =
(struct acpi_processor_tx_tss *)&(pr->throttling.
states_tss[state]);
*value = tx->control;
ret = 0;
}
return ret;
}
static int acpi_processor_get_throttling_ptc(struct acpi_processor *pr)
{
int state = 0;
int ret;
u64 value;
if (!pr)
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
pr->throttling.state = 0;
value = 0;
ret = acpi_read_throttling_status(pr, &value);
if (ret >= 0) {
state = acpi_get_throttling_state(pr, value);
if (state == -1) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Invalid throttling state, reset\n"));
state = 0;
ret = acpi_processor_set_throttling(pr, state, true);
if (ret)
return ret;
}
pr->throttling.state = state;
}
return 0;
}
static int acpi_processor_get_throttling(struct acpi_processor *pr)
{
cpumask_var_t saved_mask;
int ret;
if (!pr)
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
if (!alloc_cpumask_var(&saved_mask, GFP_KERNEL))
return -ENOMEM;
cpumask_copy(saved_mask, &current->cpus_allowed);
if (set_cpus_allowed_ptr(current, cpumask_of(pr->id))) {
free_cpumask_var(saved_mask);
return -ENODEV;
}
ret = pr->throttling.acpi_processor_get_throttling(pr);
set_cpus_allowed_ptr(current, saved_mask);
free_cpumask_var(saved_mask);
return ret;
}
static int acpi_processor_get_fadt_info(struct acpi_processor *pr)
{
int i, step;
if (!pr->throttling.address) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No throttling register\n"));
return -EINVAL;
} else if (!pr->throttling.duty_width) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No throttling states\n"));
return -EINVAL;
}
else if ((pr->throttling.duty_offset + pr->throttling.duty_width) > 4) {
printk(KERN_WARNING PREFIX "duty_cycle spans bit 4\n");
return -EINVAL;
}
pr->throttling.state_count = 1 << acpi_gbl_FADT.duty_width;
step = (1000 / pr->throttling.state_count);
for (i = 0; i < pr->throttling.state_count; i++) {
pr->throttling.states[i].performance = 1000 - step * i;
pr->throttling.states[i].power = 1000 - step * i;
}
return 0;
}
static int acpi_processor_set_throttling_fadt(struct acpi_processor *pr,
int state, bool force)
{
u32 value = 0;
u32 duty_mask = 0;
u32 duty_value = 0;
if (!pr)
return -EINVAL;
if ((state < 0) || (state > (pr->throttling.state_count - 1)))
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
if (!force && (state == pr->throttling.state))
return 0;
if (state < pr->throttling_platform_limit)
return -EPERM;
if (state) {
duty_value = pr->throttling.state_count - state;
duty_value <<= pr->throttling.duty_offset;
duty_mask = pr->throttling.state_count - 1;
duty_mask <<= acpi_gbl_FADT.duty_offset;
duty_mask = ~duty_mask;
}
local_irq_disable();
value = inl(pr->throttling.address);
if (value & 0x10) {
value &= 0xFFFFFFEF;
outl(value, pr->throttling.address);
}
if (state) {
value &= duty_mask;
value |= duty_value;
outl(value, pr->throttling.address);
value |= 0x00000010;
outl(value, pr->throttling.address);
}
pr->throttling.state = state;
local_irq_enable();
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Throttling state set to T%d (%d%%)\n", state,
(pr->throttling.states[state].performance ? pr->
throttling.states[state].performance / 10 : 0)));
return 0;
}
static int acpi_processor_set_throttling_ptc(struct acpi_processor *pr,
int state, bool force)
{
int ret;
u64 value;
if (!pr)
return -EINVAL;
if ((state < 0) || (state > (pr->throttling.state_count - 1)))
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
if (!force && (state == pr->throttling.state))
return 0;
if (state < pr->throttling_platform_limit)
return -EPERM;
value = 0;
ret = acpi_get_throttling_value(pr, state, &value);
if (ret >= 0) {
acpi_write_throttling_state(pr, value);
pr->throttling.state = state;
}
return 0;
}
int acpi_processor_set_throttling(struct acpi_processor *pr,
int state, bool force)
{
cpumask_var_t saved_mask;
int ret = 0;
unsigned int i;
struct acpi_processor *match_pr;
struct acpi_processor_throttling *p_throttling;
struct throttling_tstate t_state;
cpumask_var_t online_throttling_cpus;
if (!pr)
return -EINVAL;
if (!pr->flags.throttling)
return -ENODEV;
if ((state < 0) || (state > (pr->throttling.state_count - 1)))
return -EINVAL;
if (!alloc_cpumask_var(&saved_mask, GFP_KERNEL))
return -ENOMEM;
if (!alloc_cpumask_var(&online_throttling_cpus, GFP_KERNEL)) {
free_cpumask_var(saved_mask);
return -ENOMEM;
}
if (cpu_is_offline(pr->id)) {
return -ENODEV;
}
cpumask_copy(saved_mask, &current->cpus_allowed);
t_state.target_state = state;
p_throttling = &(pr->throttling);
cpumask_and(online_throttling_cpus, cpu_online_mask,
p_throttling->shared_cpu_map);
for_each_cpu(i, online_throttling_cpus) {
t_state.cpu = i;
acpi_processor_throttling_notifier(THROTTLING_PRECHANGE,
&t_state);
}
if (p_throttling->shared_type == DOMAIN_COORD_TYPE_SW_ANY) {
if (set_cpus_allowed_ptr(current, cpumask_of(pr->id))) {
ret = -ENODEV;
goto exit;
}
ret = p_throttling->acpi_processor_set_throttling(pr,
t_state.target_state, force);
} else {
for_each_cpu(i, online_throttling_cpus) {
match_pr = per_cpu(processors, i);
if (!match_pr) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Invalid Pointer for CPU %d\n", i));
continue;
}
if (!match_pr->flags.throttling) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Throttling Control is unsupported "
"on CPU %d\n", i));
continue;
}
t_state.cpu = i;
if (set_cpus_allowed_ptr(current, cpumask_of(i)))
continue;
ret = match_pr->throttling.
acpi_processor_set_throttling(
match_pr, t_state.target_state, force);
}
}
for_each_cpu(i, online_throttling_cpus) {
t_state.cpu = i;
acpi_processor_throttling_notifier(THROTTLING_POSTCHANGE,
&t_state);
}
set_cpus_allowed_ptr(current, saved_mask);
exit:
free_cpumask_var(online_throttling_cpus);
free_cpumask_var(saved_mask);
return ret;
}
int acpi_processor_get_throttling_info(struct acpi_processor *pr)
{
int result = 0;
struct acpi_processor_throttling *pthrottling;
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"pblk_address[0x%08x] duty_offset[%d] duty_width[%d]\n",
pr->throttling.address,
pr->throttling.duty_offset,
pr->throttling.duty_width));
if (acpi_processor_get_throttling_control(pr) ||
acpi_processor_get_throttling_states(pr) ||
acpi_processor_get_platform_limit(pr))
{
pr->throttling.acpi_processor_get_throttling =
&acpi_processor_get_throttling_fadt;
pr->throttling.acpi_processor_set_throttling =
&acpi_processor_set_throttling_fadt;
if (acpi_processor_get_fadt_info(pr))
return 0;
} else {
pr->throttling.acpi_processor_get_throttling =
&acpi_processor_get_throttling_ptc;
pr->throttling.acpi_processor_set_throttling =
&acpi_processor_set_throttling_ptc;
}
if (acpi_processor_get_tsd(pr)) {
pthrottling = &pr->throttling;
pthrottling->tsd_valid_flag = 0;
cpumask_set_cpu(pr->id, pthrottling->shared_cpu_map);
pthrottling->shared_type = DOMAIN_COORD_TYPE_SW_ALL;
}
if (errata.piix4.throttle) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Throttling not supported on PIIX4 A- or B-step\n"));
return 0;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %d throttling states\n",
pr->throttling.state_count));
pr->flags.throttling = 1;
result = acpi_processor_get_throttling(pr);
if (result)
goto end;
if (pr->throttling.state) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Disabling throttling (was T%d)\n",
pr->throttling.state));
result = acpi_processor_set_throttling(pr, 0, false);
if (result)
goto end;
}
end:
if (result)
pr->flags.throttling = 0;
return result;
}
