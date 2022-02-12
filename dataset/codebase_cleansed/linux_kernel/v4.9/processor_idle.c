static int disabled_by_idle_boot_param(void)
{
return boot_option_idle_override == IDLE_POLL ||
boot_option_idle_override == IDLE_HALT;
}
static int set_max_cstate(const struct dmi_system_id *id)
{
if (max_cstate > ACPI_PROCESSOR_MAX_POWER)
return 0;
pr_notice("%s detected - limiting to C%ld max_cstate."
" Override with \"processor.max_cstate=%d\"\n", id->ident,
(long)id->driver_data, ACPI_PROCESSOR_MAX_POWER + 1);
max_cstate = (long)id->driver_data;
return 0;
}
static void __cpuidle acpi_safe_halt(void)
{
if (!tif_need_resched()) {
safe_halt();
local_irq_disable();
}
}
static void lapic_timer_check_state(int state, struct acpi_processor *pr,
struct acpi_processor_cx *cx)
{
struct acpi_processor_power *pwr = &pr->power;
u8 type = local_apic_timer_c2_ok ? ACPI_STATE_C3 : ACPI_STATE_C2;
if (cpu_has(&cpu_data(pr->id), X86_FEATURE_ARAT))
return;
if (amd_e400_c1e_detected)
type = ACPI_STATE_C1;
if (pwr->timer_broadcast_on_state < state)
return;
if (cx->type >= type)
pr->power.timer_broadcast_on_state = state;
}
static void __lapic_timer_propagate_broadcast(void *arg)
{
struct acpi_processor *pr = (struct acpi_processor *) arg;
if (pr->power.timer_broadcast_on_state < INT_MAX)
tick_broadcast_enable();
else
tick_broadcast_disable();
}
static void lapic_timer_propagate_broadcast(struct acpi_processor *pr)
{
smp_call_function_single(pr->id, __lapic_timer_propagate_broadcast,
(void *)pr, 1);
}
static void lapic_timer_state_broadcast(struct acpi_processor *pr,
struct acpi_processor_cx *cx,
int broadcast)
{
int state = cx - pr->power.states;
if (state >= pr->power.timer_broadcast_on_state) {
if (broadcast)
tick_broadcast_enter();
else
tick_broadcast_exit();
}
}
static void lapic_timer_check_state(int state, struct acpi_processor *pr,
struct acpi_processor_cx *cstate) { }
static void lapic_timer_propagate_broadcast(struct acpi_processor *pr) { }
static void lapic_timer_state_broadcast(struct acpi_processor *pr,
struct acpi_processor_cx *cx,
int broadcast)
{
}
static void tsc_check_state(int state)
{
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_AMD:
case X86_VENDOR_INTEL:
if (boot_cpu_has(X86_FEATURE_NONSTOP_TSC))
return;
default:
if (state > ACPI_STATE_C1)
mark_tsc_unstable("TSC halts in idle");
}
}
static void tsc_check_state(int state) { return; }
static int acpi_processor_get_power_info_fadt(struct acpi_processor *pr)
{
if (!pr->pblk)
return -ENODEV;
pr->power.states[ACPI_STATE_C2].type = ACPI_STATE_C2;
pr->power.states[ACPI_STATE_C3].type = ACPI_STATE_C3;
#ifndef CONFIG_HOTPLUG_CPU
if ((num_online_cpus() > 1) &&
!(acpi_gbl_FADT.flags & ACPI_FADT_C2_MP_SUPPORTED))
return -ENODEV;
#endif
pr->power.states[ACPI_STATE_C2].address = pr->pblk + 4;
pr->power.states[ACPI_STATE_C3].address = pr->pblk + 5;
pr->power.states[ACPI_STATE_C2].latency = acpi_gbl_FADT.c2_latency;
pr->power.states[ACPI_STATE_C3].latency = acpi_gbl_FADT.c3_latency;
if (acpi_gbl_FADT.c2_latency > ACPI_PROCESSOR_MAX_C2_LATENCY) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"C2 latency too large [%d]\n", acpi_gbl_FADT.c2_latency));
pr->power.states[ACPI_STATE_C2].address = 0;
}
if (acpi_gbl_FADT.c3_latency > ACPI_PROCESSOR_MAX_C3_LATENCY) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"C3 latency too large [%d]\n", acpi_gbl_FADT.c3_latency));
pr->power.states[ACPI_STATE_C3].address = 0;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"lvl2[0x%08x] lvl3[0x%08x]\n",
pr->power.states[ACPI_STATE_C2].address,
pr->power.states[ACPI_STATE_C3].address));
return 0;
}
static int acpi_processor_get_power_info_default(struct acpi_processor *pr)
{
if (!pr->power.states[ACPI_STATE_C1].valid) {
pr->power.states[ACPI_STATE_C1].type = ACPI_STATE_C1;
pr->power.states[ACPI_STATE_C1].valid = 1;
pr->power.states[ACPI_STATE_C1].entry_method = ACPI_CSTATE_HALT;
}
pr->power.states[ACPI_STATE_C0].valid = 1;
return 0;
}
static int acpi_processor_get_power_info_cst(struct acpi_processor *pr)
{
acpi_status status;
u64 count;
int current_count;
int i, ret = 0;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *cst;
if (nocst)
return -ENODEV;
current_count = 0;
status = acpi_evaluate_object(pr->handle, "_CST", NULL, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No _CST, giving up\n"));
return -ENODEV;
}
cst = buffer.pointer;
if (!cst || (cst->type != ACPI_TYPE_PACKAGE) || cst->package.count < 2) {
pr_err("not enough elements in _CST\n");
ret = -EFAULT;
goto end;
}
count = cst->package.elements[0].integer.value;
if (count < 1 || count != cst->package.count - 1) {
pr_err("count given by _CST is not valid\n");
ret = -EFAULT;
goto end;
}
pr->flags.has_cst = 1;
for (i = 1; i <= count; i++) {
union acpi_object *element;
union acpi_object *obj;
struct acpi_power_register *reg;
struct acpi_processor_cx cx;
memset(&cx, 0, sizeof(cx));
element = &(cst->package.elements[i]);
if (element->type != ACPI_TYPE_PACKAGE)
continue;
if (element->package.count != 4)
continue;
obj = &(element->package.elements[0]);
if (obj->type != ACPI_TYPE_BUFFER)
continue;
reg = (struct acpi_power_register *)obj->buffer.pointer;
if (reg->space_id != ACPI_ADR_SPACE_SYSTEM_IO &&
(reg->space_id != ACPI_ADR_SPACE_FIXED_HARDWARE))
continue;
obj = &(element->package.elements[1]);
if (obj->type != ACPI_TYPE_INTEGER)
continue;
cx.type = obj->integer.value;
if (i == 1 && cx.type != ACPI_STATE_C1)
current_count++;
cx.address = reg->address;
cx.index = current_count + 1;
cx.entry_method = ACPI_CSTATE_SYSTEMIO;
if (reg->space_id == ACPI_ADR_SPACE_FIXED_HARDWARE) {
if (acpi_processor_ffh_cstate_probe
(pr->id, &cx, reg) == 0) {
cx.entry_method = ACPI_CSTATE_FFH;
} else if (cx.type == ACPI_STATE_C1) {
cx.entry_method = ACPI_CSTATE_HALT;
snprintf(cx.desc, ACPI_CX_DESC_LEN, "ACPI HLT");
} else {
continue;
}
if (cx.type == ACPI_STATE_C1 &&
(boot_option_idle_override == IDLE_NOMWAIT)) {
cx.entry_method = ACPI_CSTATE_HALT;
snprintf(cx.desc, ACPI_CX_DESC_LEN, "ACPI HLT");
}
} else {
snprintf(cx.desc, ACPI_CX_DESC_LEN, "ACPI IOPORT 0x%x",
cx.address);
}
if (cx.type == ACPI_STATE_C1) {
cx.valid = 1;
}
obj = &(element->package.elements[2]);
if (obj->type != ACPI_TYPE_INTEGER)
continue;
cx.latency = obj->integer.value;
obj = &(element->package.elements[3]);
if (obj->type != ACPI_TYPE_INTEGER)
continue;
current_count++;
memcpy(&(pr->power.states[current_count]), &cx, sizeof(cx));
if (current_count >= (ACPI_PROCESSOR_MAX_POWER - 1)) {
pr_warn("Limiting number of power states to max (%d)\n",
ACPI_PROCESSOR_MAX_POWER);
pr_warn("Please increase ACPI_PROCESSOR_MAX_POWER if needed.\n");
break;
}
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %d power states\n",
current_count));
if (current_count < 2)
ret = -EFAULT;
end:
kfree(buffer.pointer);
return ret;
}
static void acpi_processor_power_verify_c3(struct acpi_processor *pr,
struct acpi_processor_cx *cx)
{
static int bm_check_flag = -1;
static int bm_control_flag = -1;
if (!cx->address)
return;
else if (errata.piix4.fdma) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"C3 not supported on PIIX4 with Type-F DMA\n"));
return;
}
if (bm_check_flag == -1) {
acpi_processor_power_init_bm_check(&(pr->flags), pr->id);
bm_check_flag = pr->flags.bm_check;
bm_control_flag = pr->flags.bm_control;
} else {
pr->flags.bm_check = bm_check_flag;
pr->flags.bm_control = bm_control_flag;
}
if (pr->flags.bm_check) {
if (!pr->flags.bm_control) {
if (pr->flags.has_cst != 1) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"C3 support requires BM control\n"));
return;
} else {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"C3 support without BM control\n"));
}
}
} else {
if (!(acpi_gbl_FADT.flags & ACPI_FADT_WBINVD)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Cache invalidation should work properly"
" for C3 to be enabled on SMP systems\n"));
return;
}
}
cx->valid = 1;
acpi_write_bit_register(ACPI_BITREG_BUS_MASTER_RLD, 1);
return;
}
static int acpi_processor_power_verify(struct acpi_processor *pr)
{
unsigned int i;
unsigned int working = 0;
pr->power.timer_broadcast_on_state = INT_MAX;
for (i = 1; i < ACPI_PROCESSOR_MAX_POWER && i <= max_cstate; i++) {
struct acpi_processor_cx *cx = &pr->power.states[i];
switch (cx->type) {
case ACPI_STATE_C1:
cx->valid = 1;
break;
case ACPI_STATE_C2:
if (!cx->address)
break;
cx->valid = 1;
break;
case ACPI_STATE_C3:
acpi_processor_power_verify_c3(pr, cx);
break;
}
if (!cx->valid)
continue;
lapic_timer_check_state(i, pr, cx);
tsc_check_state(cx->type);
working++;
}
lapic_timer_propagate_broadcast(pr);
return (working);
}
static int acpi_processor_get_cstate_info(struct acpi_processor *pr)
{
unsigned int i;
int result;
memset(pr->power.states, 0, sizeof(pr->power.states));
result = acpi_processor_get_power_info_cst(pr);
if (result == -ENODEV)
result = acpi_processor_get_power_info_fadt(pr);
if (result)
return result;
acpi_processor_get_power_info_default(pr);
pr->power.count = acpi_processor_power_verify(pr);
for (i = 1; i < ACPI_PROCESSOR_MAX_POWER; i++) {
if (pr->power.states[i].valid) {
pr->power.count = i;
if (pr->power.states[i].type >= ACPI_STATE_C2)
pr->flags.power = 1;
}
}
return 0;
}
static int acpi_idle_bm_check(void)
{
u32 bm_status = 0;
if (bm_check_disable)
return 0;
acpi_read_bit_register(ACPI_BITREG_BUS_MASTER_STATUS, &bm_status);
if (bm_status)
acpi_write_bit_register(ACPI_BITREG_BUS_MASTER_STATUS, 1);
else if (errata.piix4.bmisx) {
if ((inb_p(errata.piix4.bmisx + 0x02) & 0x01)
|| (inb_p(errata.piix4.bmisx + 0x0A) & 0x01))
bm_status = 1;
}
return bm_status;
}
static void __cpuidle acpi_idle_do_entry(struct acpi_processor_cx *cx)
{
if (cx->entry_method == ACPI_CSTATE_FFH) {
acpi_processor_ffh_cstate_enter(cx);
} else if (cx->entry_method == ACPI_CSTATE_HALT) {
acpi_safe_halt();
} else {
inb(cx->address);
inl(acpi_gbl_FADT.xpm_timer_block.address);
}
}
static int acpi_idle_play_dead(struct cpuidle_device *dev, int index)
{
struct acpi_processor_cx *cx = per_cpu(acpi_cstate[index], dev->cpu);
ACPI_FLUSH_CPU_CACHE();
while (1) {
if (cx->entry_method == ACPI_CSTATE_HALT)
safe_halt();
else if (cx->entry_method == ACPI_CSTATE_SYSTEMIO) {
inb(cx->address);
inl(acpi_gbl_FADT.xpm_timer_block.address);
} else
return -ENODEV;
}
return 0;
}
static bool acpi_idle_fallback_to_c1(struct acpi_processor *pr)
{
return IS_ENABLED(CONFIG_HOTPLUG_CPU) && !pr->flags.has_cst &&
!(acpi_gbl_FADT.flags & ACPI_FADT_C2_MP_SUPPORTED);
}
static void acpi_idle_enter_bm(struct acpi_processor *pr,
struct acpi_processor_cx *cx, bool timer_bc)
{
acpi_unlazy_tlb(smp_processor_id());
if (timer_bc)
lapic_timer_state_broadcast(pr, cx, 1);
if (pr->flags.bm_control) {
raw_spin_lock(&c3_lock);
c3_cpu_count++;
if (c3_cpu_count == num_online_cpus())
acpi_write_bit_register(ACPI_BITREG_ARB_DISABLE, 1);
raw_spin_unlock(&c3_lock);
}
acpi_idle_do_entry(cx);
if (pr->flags.bm_control) {
raw_spin_lock(&c3_lock);
acpi_write_bit_register(ACPI_BITREG_ARB_DISABLE, 0);
c3_cpu_count--;
raw_spin_unlock(&c3_lock);
}
if (timer_bc)
lapic_timer_state_broadcast(pr, cx, 0);
}
static int acpi_idle_enter(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
struct acpi_processor_cx *cx = per_cpu(acpi_cstate[index], dev->cpu);
struct acpi_processor *pr;
pr = __this_cpu_read(processors);
if (unlikely(!pr))
return -EINVAL;
if (cx->type != ACPI_STATE_C1) {
if (acpi_idle_fallback_to_c1(pr) && num_online_cpus() > 1) {
index = CPUIDLE_DRIVER_STATE_START;
cx = per_cpu(acpi_cstate[index], dev->cpu);
} else if (cx->type == ACPI_STATE_C3 && pr->flags.bm_check) {
if (cx->bm_sts_skip || !acpi_idle_bm_check()) {
acpi_idle_enter_bm(pr, cx, true);
return index;
} else if (drv->safe_state_index >= 0) {
index = drv->safe_state_index;
cx = per_cpu(acpi_cstate[index], dev->cpu);
} else {
acpi_safe_halt();
return -EBUSY;
}
}
}
lapic_timer_state_broadcast(pr, cx, 1);
if (cx->type == ACPI_STATE_C3)
ACPI_FLUSH_CPU_CACHE();
acpi_idle_do_entry(cx);
lapic_timer_state_broadcast(pr, cx, 0);
return index;
}
static void acpi_idle_enter_freeze(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
struct acpi_processor_cx *cx = per_cpu(acpi_cstate[index], dev->cpu);
if (cx->type == ACPI_STATE_C3) {
struct acpi_processor *pr = __this_cpu_read(processors);
if (unlikely(!pr))
return;
if (pr->flags.bm_check) {
acpi_idle_enter_bm(pr, cx, false);
return;
} else {
ACPI_FLUSH_CPU_CACHE();
}
}
acpi_idle_do_entry(cx);
}
static int acpi_processor_setup_cpuidle_cx(struct acpi_processor *pr,
struct cpuidle_device *dev)
{
int i, count = CPUIDLE_DRIVER_STATE_START;
struct acpi_processor_cx *cx;
if (max_cstate == 0)
max_cstate = 1;
for (i = 1; i < ACPI_PROCESSOR_MAX_POWER && i <= max_cstate; i++) {
cx = &pr->power.states[i];
if (!cx->valid)
continue;
per_cpu(acpi_cstate[count], dev->cpu) = cx;
count++;
if (count == CPUIDLE_STATE_MAX)
break;
}
if (!count)
return -EINVAL;
return 0;
}
static int acpi_processor_setup_cstates(struct acpi_processor *pr)
{
int i, count = CPUIDLE_DRIVER_STATE_START;
struct acpi_processor_cx *cx;
struct cpuidle_state *state;
struct cpuidle_driver *drv = &acpi_idle_driver;
if (max_cstate == 0)
max_cstate = 1;
for (i = 1; i < ACPI_PROCESSOR_MAX_POWER && i <= max_cstate; i++) {
cx = &pr->power.states[i];
if (!cx->valid)
continue;
state = &drv->states[count];
snprintf(state->name, CPUIDLE_NAME_LEN, "C%d", i);
strlcpy(state->desc, cx->desc, CPUIDLE_DESC_LEN);
state->exit_latency = cx->latency;
state->target_residency = cx->latency * latency_factor;
state->enter = acpi_idle_enter;
state->flags = 0;
if (cx->type == ACPI_STATE_C1 || cx->type == ACPI_STATE_C2) {
state->enter_dead = acpi_idle_play_dead;
drv->safe_state_index = count;
}
if (cx->type != ACPI_STATE_C1 && !acpi_idle_fallback_to_c1(pr))
state->enter_freeze = acpi_idle_enter_freeze;
count++;
if (count == CPUIDLE_STATE_MAX)
break;
}
drv->state_count = count;
if (!count)
return -EINVAL;
return 0;
}
static inline void acpi_processor_cstate_first_run_checks(void)
{
acpi_status status;
static int first_run;
if (first_run)
return;
dmi_check_system(processor_power_dmi_table);
max_cstate = acpi_processor_cstate_check(max_cstate);
if (max_cstate < ACPI_C_STATES_MAX)
pr_notice("ACPI: processor limited to max C-state %d\n",
max_cstate);
first_run++;
if (acpi_gbl_FADT.cst_control && !nocst) {
status = acpi_os_write_port(acpi_gbl_FADT.smi_command,
acpi_gbl_FADT.cst_control, 8);
if (ACPI_FAILURE(status))
ACPI_EXCEPTION((AE_INFO, status,
"Notifying BIOS of _CST ability failed"));
}
}
static inline int disabled_by_idle_boot_param(void) { return 0; }
static inline void acpi_processor_cstate_first_run_checks(void) { }
static int acpi_processor_get_cstate_info(struct acpi_processor *pr)
{
return -ENODEV;
}
static int acpi_processor_setup_cpuidle_cx(struct acpi_processor *pr,
struct cpuidle_device *dev)
{
return -EINVAL;
}
static int acpi_processor_setup_cstates(struct acpi_processor *pr)
{
return -EINVAL;
}
static int obj_get_integer(union acpi_object *obj, u32 *value)
{
if (obj->type != ACPI_TYPE_INTEGER)
return -EINVAL;
*value = obj->integer.value;
return 0;
}
static int acpi_processor_evaluate_lpi(acpi_handle handle,
struct acpi_lpi_states_array *info)
{
acpi_status status;
int ret = 0;
int pkg_count, state_idx = 1, loop;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *lpi_data;
struct acpi_lpi_state *lpi_state;
status = acpi_evaluate_object(handle, "_LPI", NULL, &buffer);
if (ACPI_FAILURE(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No _LPI, giving up\n"));
return -ENODEV;
}
lpi_data = buffer.pointer;
if (!lpi_data || lpi_data->type != ACPI_TYPE_PACKAGE ||
lpi_data->package.count < 4) {
pr_debug("not enough elements in _LPI\n");
ret = -ENODATA;
goto end;
}
pkg_count = lpi_data->package.elements[2].integer.value;
if (pkg_count < 1 || pkg_count != lpi_data->package.count - 3) {
pr_debug("count given by _LPI is not valid\n");
ret = -ENODATA;
goto end;
}
lpi_state = kcalloc(pkg_count, sizeof(*lpi_state), GFP_KERNEL);
if (!lpi_state) {
ret = -ENOMEM;
goto end;
}
info->size = pkg_count;
info->entries = lpi_state;
for (loop = 3; state_idx <= pkg_count; loop++, state_idx++, lpi_state++) {
union acpi_object *element, *pkg_elem, *obj;
element = &lpi_data->package.elements[loop];
if (element->type != ACPI_TYPE_PACKAGE || element->package.count < 7)
continue;
pkg_elem = element->package.elements;
obj = pkg_elem + 6;
if (obj->type == ACPI_TYPE_BUFFER) {
struct acpi_power_register *reg;
reg = (struct acpi_power_register *)obj->buffer.pointer;
if (reg->space_id != ACPI_ADR_SPACE_SYSTEM_IO &&
reg->space_id != ACPI_ADR_SPACE_FIXED_HARDWARE)
continue;
lpi_state->address = reg->address;
lpi_state->entry_method =
reg->space_id == ACPI_ADR_SPACE_FIXED_HARDWARE ?
ACPI_CSTATE_FFH : ACPI_CSTATE_SYSTEMIO;
} else if (obj->type == ACPI_TYPE_INTEGER) {
lpi_state->entry_method = ACPI_CSTATE_INTEGER;
lpi_state->address = obj->integer.value;
} else {
continue;
}
obj = pkg_elem + 9;
if (obj->type == ACPI_TYPE_STRING)
strlcpy(lpi_state->desc, obj->string.pointer,
ACPI_CX_DESC_LEN);
lpi_state->index = state_idx;
if (obj_get_integer(pkg_elem + 0, &lpi_state->min_residency)) {
pr_debug("No min. residency found, assuming 10 us\n");
lpi_state->min_residency = 10;
}
if (obj_get_integer(pkg_elem + 1, &lpi_state->wake_latency)) {
pr_debug("No wakeup residency found, assuming 10 us\n");
lpi_state->wake_latency = 10;
}
if (obj_get_integer(pkg_elem + 2, &lpi_state->flags))
lpi_state->flags = 0;
if (obj_get_integer(pkg_elem + 3, &lpi_state->arch_flags))
lpi_state->arch_flags = 0;
if (obj_get_integer(pkg_elem + 4, &lpi_state->res_cnt_freq))
lpi_state->res_cnt_freq = 1;
if (obj_get_integer(pkg_elem + 5, &lpi_state->enable_parent_state))
lpi_state->enable_parent_state = 0;
}
acpi_handle_debug(handle, "Found %d power states\n", state_idx);
end:
kfree(buffer.pointer);
return ret;
}
static bool combine_lpi_states(struct acpi_lpi_state *local,
struct acpi_lpi_state *parent,
struct acpi_lpi_state *result)
{
if (parent->entry_method == ACPI_CSTATE_INTEGER) {
if (!parent->address)
return false;
result->address = local->address + parent->address;
} else {
result->address = parent->address;
}
result->min_residency = max(local->min_residency, parent->min_residency);
result->wake_latency = local->wake_latency + parent->wake_latency;
result->enable_parent_state = parent->enable_parent_state;
result->entry_method = local->entry_method;
result->flags = parent->flags;
result->arch_flags = parent->arch_flags;
result->index = parent->index;
strlcpy(result->desc, local->desc, ACPI_CX_DESC_LEN);
strlcat(result->desc, "+", ACPI_CX_DESC_LEN);
strlcat(result->desc, parent->desc, ACPI_CX_DESC_LEN);
return true;
}
static void stash_composite_state(struct acpi_lpi_states_array *curr_level,
struct acpi_lpi_state *t)
{
curr_level->composite_states[curr_level->composite_states_size++] = t;
}
static int flatten_lpi_states(struct acpi_processor *pr,
struct acpi_lpi_states_array *curr_level,
struct acpi_lpi_states_array *prev_level)
{
int i, j, state_count = curr_level->size;
struct acpi_lpi_state *p, *t = curr_level->entries;
curr_level->composite_states_size = 0;
for (j = 0; j < state_count; j++, t++) {
struct acpi_lpi_state *flpi;
if (!(t->flags & ACPI_LPI_STATE_FLAGS_ENABLED))
continue;
if (flat_state_cnt >= ACPI_PROCESSOR_MAX_POWER) {
pr_warn("Limiting number of LPI states to max (%d)\n",
ACPI_PROCESSOR_MAX_POWER);
pr_warn("Please increase ACPI_PROCESSOR_MAX_POWER if needed.\n");
break;
}
flpi = &pr->power.lpi_states[flat_state_cnt];
if (!prev_level) {
memcpy(flpi, t, sizeof(*t));
stash_composite_state(curr_level, flpi);
flat_state_cnt++;
continue;
}
for (i = 0; i < prev_level->composite_states_size; i++) {
p = prev_level->composite_states[i];
if (t->index <= p->enable_parent_state &&
combine_lpi_states(p, t, flpi)) {
stash_composite_state(curr_level, flpi);
flat_state_cnt++;
flpi++;
}
}
}
kfree(curr_level->entries);
return 0;
}
static int acpi_processor_get_lpi_info(struct acpi_processor *pr)
{
int ret, i;
acpi_status status;
acpi_handle handle = pr->handle, pr_ahandle;
struct acpi_device *d = NULL;
struct acpi_lpi_states_array info[2], *tmp, *prev, *curr;
if (!osc_pc_lpi_support_confirmed)
return -EOPNOTSUPP;
if (!acpi_has_method(handle, "_LPI"))
return -EINVAL;
flat_state_cnt = 0;
prev = &info[0];
curr = &info[1];
handle = pr->handle;
ret = acpi_processor_evaluate_lpi(handle, prev);
if (ret)
return ret;
flatten_lpi_states(pr, prev, NULL);
status = acpi_get_parent(handle, &pr_ahandle);
while (ACPI_SUCCESS(status)) {
acpi_bus_get_device(pr_ahandle, &d);
handle = pr_ahandle;
if (strcmp(acpi_device_hid(d), ACPI_PROCESSOR_CONTAINER_HID))
break;
if (!acpi_has_method(handle, "_LPI"))
break;
ret = acpi_processor_evaluate_lpi(handle, curr);
if (ret)
break;
flatten_lpi_states(pr, curr, prev);
tmp = prev, prev = curr, curr = tmp;
status = acpi_get_parent(handle, &pr_ahandle);
}
pr->power.count = flat_state_cnt;
for (i = 0; i < pr->power.count; i++)
pr->power.lpi_states[i].index = i;
pr->flags.has_lpi = 1;
pr->flags.power = 1;
return 0;
}
int __weak acpi_processor_ffh_lpi_probe(unsigned int cpu)
{
return -ENODEV;
}
int __weak acpi_processor_ffh_lpi_enter(struct acpi_lpi_state *lpi)
{
return -ENODEV;
}
static int acpi_idle_lpi_enter(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
struct acpi_processor *pr;
struct acpi_lpi_state *lpi;
pr = __this_cpu_read(processors);
if (unlikely(!pr))
return -EINVAL;
lpi = &pr->power.lpi_states[index];
if (lpi->entry_method == ACPI_CSTATE_FFH)
return acpi_processor_ffh_lpi_enter(lpi);
return -EINVAL;
}
static int acpi_processor_setup_lpi_states(struct acpi_processor *pr)
{
int i;
struct acpi_lpi_state *lpi;
struct cpuidle_state *state;
struct cpuidle_driver *drv = &acpi_idle_driver;
if (!pr->flags.has_lpi)
return -EOPNOTSUPP;
for (i = 0; i < pr->power.count && i < CPUIDLE_STATE_MAX; i++) {
lpi = &pr->power.lpi_states[i];
state = &drv->states[i];
snprintf(state->name, CPUIDLE_NAME_LEN, "LPI-%d", i);
strlcpy(state->desc, lpi->desc, CPUIDLE_DESC_LEN);
state->exit_latency = lpi->wake_latency;
state->target_residency = lpi->min_residency;
if (lpi->arch_flags)
state->flags |= CPUIDLE_FLAG_TIMER_STOP;
state->enter = acpi_idle_lpi_enter;
drv->safe_state_index = i;
}
drv->state_count = i;
return 0;
}
static int acpi_processor_setup_cpuidle_states(struct acpi_processor *pr)
{
int i;
struct cpuidle_driver *drv = &acpi_idle_driver;
if (!pr->flags.power_setup_done || !pr->flags.power)
return -EINVAL;
drv->safe_state_index = -1;
for (i = CPUIDLE_DRIVER_STATE_START; i < CPUIDLE_STATE_MAX; i++) {
drv->states[i].name[0] = '\0';
drv->states[i].desc[0] = '\0';
}
if (pr->flags.has_lpi)
return acpi_processor_setup_lpi_states(pr);
return acpi_processor_setup_cstates(pr);
}
static int acpi_processor_setup_cpuidle_dev(struct acpi_processor *pr,
struct cpuidle_device *dev)
{
if (!pr->flags.power_setup_done || !pr->flags.power || !dev)
return -EINVAL;
dev->cpu = pr->id;
if (pr->flags.has_lpi)
return acpi_processor_ffh_lpi_probe(pr->id);
return acpi_processor_setup_cpuidle_cx(pr, dev);
}
static int acpi_processor_get_power_info(struct acpi_processor *pr)
{
int ret;
ret = acpi_processor_get_lpi_info(pr);
if (ret)
ret = acpi_processor_get_cstate_info(pr);
return ret;
}
int acpi_processor_hotplug(struct acpi_processor *pr)
{
int ret = 0;
struct cpuidle_device *dev;
if (disabled_by_idle_boot_param())
return 0;
if (!pr->flags.power_setup_done)
return -ENODEV;
dev = per_cpu(acpi_cpuidle_device, pr->id);
cpuidle_pause_and_lock();
cpuidle_disable_device(dev);
ret = acpi_processor_get_power_info(pr);
if (!ret && pr->flags.power) {
acpi_processor_setup_cpuidle_dev(pr, dev);
ret = cpuidle_enable_device(dev);
}
cpuidle_resume_and_unlock();
return ret;
}
int acpi_processor_power_state_has_changed(struct acpi_processor *pr)
{
int cpu;
struct acpi_processor *_pr;
struct cpuidle_device *dev;
if (disabled_by_idle_boot_param())
return 0;
if (!pr->flags.power_setup_done)
return -ENODEV;
if (pr->id == 0 && cpuidle_get_driver() == &acpi_idle_driver) {
get_online_cpus();
cpuidle_pause_and_lock();
for_each_online_cpu(cpu) {
_pr = per_cpu(processors, cpu);
if (!_pr || !_pr->flags.power_setup_done)
continue;
dev = per_cpu(acpi_cpuidle_device, cpu);
cpuidle_disable_device(dev);
}
acpi_processor_get_power_info(pr);
acpi_processor_setup_cpuidle_states(pr);
for_each_online_cpu(cpu) {
_pr = per_cpu(processors, cpu);
if (!_pr || !_pr->flags.power_setup_done)
continue;
acpi_processor_get_power_info(_pr);
if (_pr->flags.power) {
dev = per_cpu(acpi_cpuidle_device, cpu);
acpi_processor_setup_cpuidle_dev(_pr, dev);
cpuidle_enable_device(dev);
}
}
cpuidle_resume_and_unlock();
put_online_cpus();
}
return 0;
}
int acpi_processor_power_init(struct acpi_processor *pr)
{
int retval;
struct cpuidle_device *dev;
if (disabled_by_idle_boot_param())
return 0;
acpi_processor_cstate_first_run_checks();
if (!acpi_processor_get_power_info(pr))
pr->flags.power_setup_done = 1;
if (pr->flags.power) {
if (!acpi_processor_registered) {
acpi_processor_setup_cpuidle_states(pr);
retval = cpuidle_register_driver(&acpi_idle_driver);
if (retval)
return retval;
pr_debug("%s registered with cpuidle\n",
acpi_idle_driver.name);
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
per_cpu(acpi_cpuidle_device, pr->id) = dev;
acpi_processor_setup_cpuidle_dev(pr, dev);
retval = cpuidle_register_device(dev);
if (retval) {
if (acpi_processor_registered == 0)
cpuidle_unregister_driver(&acpi_idle_driver);
return retval;
}
acpi_processor_registered++;
}
return 0;
}
int acpi_processor_power_exit(struct acpi_processor *pr)
{
struct cpuidle_device *dev = per_cpu(acpi_cpuidle_device, pr->id);
if (disabled_by_idle_boot_param())
return 0;
if (pr->flags.power) {
cpuidle_unregister_device(dev);
acpi_processor_registered--;
if (acpi_processor_registered == 0)
cpuidle_unregister_driver(&acpi_idle_driver);
}
pr->flags.power_setup_done = 0;
return 0;
}
