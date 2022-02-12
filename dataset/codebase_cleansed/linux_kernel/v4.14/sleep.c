static void acpi_sleep_tts_switch(u32 acpi_state)
{
acpi_status status;
status = acpi_execute_simple_method(NULL, "\\_TTS", acpi_state);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
printk(KERN_NOTICE "Failure in evaluating _TTS object\n");
}
}
static int tts_notify_reboot(struct notifier_block *this,
unsigned long code, void *x)
{
acpi_sleep_tts_switch(ACPI_STATE_S5);
return NOTIFY_DONE;
}
static int acpi_sleep_prepare(u32 acpi_state)
{
#ifdef CONFIG_ACPI_SLEEP
if (acpi_state == ACPI_STATE_S3) {
if (!acpi_wakeup_address)
return -EFAULT;
acpi_set_waking_vector(acpi_wakeup_address);
}
ACPI_FLUSH_CPU_CACHE();
#endif
printk(KERN_INFO PREFIX "Preparing to enter system sleep state S%d\n",
acpi_state);
acpi_enable_wakeup_devices(acpi_state);
acpi_enter_sleep_state_prep(acpi_state);
return 0;
}
static bool acpi_sleep_state_supported(u8 sleep_state)
{
acpi_status status;
u8 type_a, type_b;
status = acpi_get_sleep_type_data(sleep_state, &type_a, &type_b);
return ACPI_SUCCESS(status) && (!acpi_gbl_reduced_hardware
|| (acpi_gbl_FADT.sleep_control.address
&& acpi_gbl_FADT.sleep_status.address));
}
u32 acpi_target_system_state(void)
{
return acpi_target_sleep_state;
}
void __init acpi_nvs_nosave(void)
{
nvs_nosave = true;
}
void __init acpi_nvs_nosave_s3(void)
{
nvs_nosave_s3 = true;
}
static int __init init_nvs_save_s3(const struct dmi_system_id *d)
{
nvs_nosave_s3 = false;
return 0;
}
void __init acpi_old_suspend_ordering(void)
{
old_suspend_ordering = true;
}
static int __init init_old_suspend_ordering(const struct dmi_system_id *d)
{
acpi_old_suspend_ordering();
return 0;
}
static int __init init_nvs_nosave(const struct dmi_system_id *d)
{
acpi_nvs_nosave();
return 0;
}
static int __init init_no_lps0(const struct dmi_system_id *d)
{
acpi_sleep_no_lps0 = true;
return 0;
}
static void __init acpi_sleep_dmi_check(void)
{
int year;
if (dmi_get_date(DMI_BIOS_DATE, &year, NULL, NULL) && year >= 2012)
acpi_nvs_nosave_s3();
dmi_check_system(acpisleep_dmi_table);
}
static int acpi_pm_freeze(void)
{
acpi_disable_all_gpes();
acpi_os_wait_events_complete();
acpi_ec_block_transactions();
return 0;
}
static int acpi_pm_pre_suspend(void)
{
acpi_pm_freeze();
return suspend_nvs_save();
}
static int __acpi_pm_prepare(void)
{
int error = acpi_sleep_prepare(acpi_target_sleep_state);
if (error)
acpi_target_sleep_state = ACPI_STATE_S0;
return error;
}
static int acpi_pm_prepare(void)
{
int error = __acpi_pm_prepare();
if (!error)
error = acpi_pm_pre_suspend();
return error;
}
static int find_powerf_dev(struct device *dev, void *data)
{
struct acpi_device *device = to_acpi_device(dev);
const char *hid = acpi_device_hid(device);
return !strcmp(hid, ACPI_BUTTON_HID_POWERF);
}
static void acpi_pm_finish(void)
{
struct device *pwr_btn_dev;
u32 acpi_state = acpi_target_sleep_state;
acpi_ec_unblock_transactions();
suspend_nvs_free();
if (acpi_state == ACPI_STATE_S0)
return;
printk(KERN_INFO PREFIX "Waking up from system sleep state S%d\n",
acpi_state);
acpi_disable_wakeup_devices(acpi_state);
acpi_leave_sleep_state(acpi_state);
acpi_set_waking_vector(0);
acpi_target_sleep_state = ACPI_STATE_S0;
acpi_resume_power_resources();
if (!pwr_btn_event_pending)
return;
pwr_btn_event_pending = false;
pwr_btn_dev = bus_find_device(&acpi_bus_type, NULL, NULL,
find_powerf_dev);
if (pwr_btn_dev) {
pm_wakeup_event(pwr_btn_dev, 0);
put_device(pwr_btn_dev);
}
}
static void acpi_pm_start(u32 acpi_state)
{
acpi_target_sleep_state = acpi_state;
acpi_sleep_tts_switch(acpi_target_sleep_state);
acpi_scan_lock_acquire();
}
static void acpi_pm_end(void)
{
acpi_turn_off_unused_power_resources();
acpi_scan_lock_release();
acpi_target_sleep_state = ACPI_STATE_S0;
acpi_sleep_tts_switch(acpi_target_sleep_state);
}
static inline void acpi_sleep_dmi_check(void) {}
static int acpi_suspend_begin(suspend_state_t pm_state)
{
u32 acpi_state = acpi_suspend_states[pm_state];
int error;
error = (nvs_nosave || nvs_nosave_s3) ? 0 : suspend_nvs_alloc();
if (error)
return error;
if (!sleep_states[acpi_state]) {
pr_err("ACPI does not support sleep state S%u\n", acpi_state);
return -ENOSYS;
}
if (acpi_state > ACPI_STATE_S1)
pm_set_suspend_via_firmware();
acpi_pm_start(acpi_state);
return 0;
}
static int acpi_suspend_enter(suspend_state_t pm_state)
{
acpi_status status = AE_OK;
u32 acpi_state = acpi_target_sleep_state;
int error;
ACPI_FLUSH_CPU_CACHE();
trace_suspend_resume(TPS("acpi_suspend"), acpi_state, true);
switch (acpi_state) {
case ACPI_STATE_S1:
barrier();
status = acpi_enter_sleep_state(acpi_state);
break;
case ACPI_STATE_S3:
if (!acpi_suspend_lowlevel)
return -ENOSYS;
error = acpi_suspend_lowlevel();
if (error)
return error;
pr_info(PREFIX "Low-level resume complete\n");
pm_set_resume_via_firmware();
break;
}
trace_suspend_resume(TPS("acpi_suspend"), acpi_state, false);
acpi_write_bit_register(ACPI_BITREG_SCI_ENABLE, 1);
acpi_leave_sleep_state_prep(acpi_state);
if (ACPI_SUCCESS(status) && (acpi_state == ACPI_STATE_S3)) {
acpi_event_status pwr_btn_status = ACPI_EVENT_FLAG_DISABLED;
acpi_get_event_status(ACPI_EVENT_POWER_BUTTON, &pwr_btn_status);
if (pwr_btn_status & ACPI_EVENT_FLAG_STATUS_SET) {
acpi_clear_event(ACPI_EVENT_POWER_BUTTON);
pwr_btn_event_pending = true;
}
}
acpi_disable_all_gpes();
acpi_ec_unblock_transactions();
suspend_nvs_restore();
return ACPI_SUCCESS(status) ? 0 : -EFAULT;
}
static int acpi_suspend_state_valid(suspend_state_t pm_state)
{
u32 acpi_state;
switch (pm_state) {
case PM_SUSPEND_ON:
case PM_SUSPEND_STANDBY:
case PM_SUSPEND_MEM:
acpi_state = acpi_suspend_states[pm_state];
return sleep_states[acpi_state];
default:
return 0;
}
}
static int acpi_suspend_begin_old(suspend_state_t pm_state)
{
int error = acpi_suspend_begin(pm_state);
if (!error)
error = __acpi_pm_prepare();
return error;
}
static void lpi_device_get_constraints(void)
{
union acpi_object *out_obj;
int i;
out_obj = acpi_evaluate_dsm_typed(lps0_device_handle, &lps0_dsm_guid,
1, ACPI_LPS0_GET_DEVICE_CONSTRAINTS,
NULL, ACPI_TYPE_PACKAGE);
acpi_handle_debug(lps0_device_handle, "_DSM function 1 eval %s\n",
out_obj ? "successful" : "failed");
if (!out_obj)
return;
lpi_constraints_table = kcalloc(out_obj->package.count,
sizeof(*lpi_constraints_table),
GFP_KERNEL);
if (!lpi_constraints_table)
goto free_acpi_buffer;
acpi_handle_debug(lps0_device_handle, "LPI: constraints list begin:\n");
for (i = 0; i < out_obj->package.count; i++) {
struct lpi_constraints *constraint;
acpi_status status;
union acpi_object *package = &out_obj->package.elements[i];
struct lpi_device_info info = { };
int package_count = 0, j;
if (!package)
continue;
for (j = 0; j < package->package.count; ++j) {
union acpi_object *element =
&(package->package.elements[j]);
switch (element->type) {
case ACPI_TYPE_INTEGER:
info.enabled = element->integer.value;
break;
case ACPI_TYPE_STRING:
info.name = element->string.pointer;
break;
case ACPI_TYPE_PACKAGE:
package_count = element->package.count;
info.package = element->package.elements;
break;
}
}
if (!info.enabled || !info.package || !info.name)
continue;
constraint = &lpi_constraints_table[lpi_constraints_table_size];
status = acpi_get_handle(NULL, info.name, &constraint->handle);
if (ACPI_FAILURE(status))
continue;
acpi_handle_debug(lps0_device_handle,
"index:%d Name:%s\n", i, info.name);
constraint->min_dstate = -1;
for (j = 0; j < package_count; ++j) {
union acpi_object *info_obj = &info.package[j];
union acpi_object *cnstr_pkg;
union acpi_object *obj;
struct lpi_device_constraint dev_info;
switch (info_obj->type) {
case ACPI_TYPE_INTEGER:
break;
case ACPI_TYPE_PACKAGE:
if (info_obj->package.count < 2)
break;
cnstr_pkg = info_obj->package.elements;
obj = &cnstr_pkg[0];
dev_info.uid = obj->integer.value;
obj = &cnstr_pkg[1];
dev_info.min_dstate = obj->integer.value;
acpi_handle_debug(lps0_device_handle,
"uid:%d min_dstate:%s\n",
dev_info.uid,
acpi_power_state_string(dev_info.min_dstate));
constraint->min_dstate = dev_info.min_dstate;
break;
}
}
if (constraint->min_dstate < 0) {
acpi_handle_debug(lps0_device_handle,
"Incomplete constraint defined\n");
continue;
}
lpi_constraints_table_size++;
}
acpi_handle_debug(lps0_device_handle, "LPI: constraints list end\n");
free_acpi_buffer:
ACPI_FREE(out_obj);
}
static void lpi_check_constraints(void)
{
int i;
for (i = 0; i < lpi_constraints_table_size; ++i) {
struct acpi_device *adev;
if (acpi_bus_get_device(lpi_constraints_table[i].handle, &adev))
continue;
acpi_handle_debug(adev->handle,
"LPI: required min power state:%s current power state:%s\n",
acpi_power_state_string(lpi_constraints_table[i].min_dstate),
acpi_power_state_string(adev->power.state));
if (!adev->flags.power_manageable) {
acpi_handle_info(adev->handle, "LPI: Device not power manageble\n");
continue;
}
if (adev->power.state < lpi_constraints_table[i].min_dstate)
acpi_handle_info(adev->handle,
"LPI: Constraint not met; min power state:%s current power state:%s\n",
acpi_power_state_string(lpi_constraints_table[i].min_dstate),
acpi_power_state_string(adev->power.state));
}
}
static void acpi_sleep_run_lps0_dsm(unsigned int func)
{
union acpi_object *out_obj;
if (!(lps0_dsm_func_mask & (1 << func)))
return;
out_obj = acpi_evaluate_dsm(lps0_device_handle, &lps0_dsm_guid, 1, func, NULL);
ACPI_FREE(out_obj);
acpi_handle_debug(lps0_device_handle, "_DSM function %u evaluation %s\n",
func, out_obj ? "successful" : "failed");
}
static int lps0_device_attach(struct acpi_device *adev,
const struct acpi_device_id *not_used)
{
union acpi_object *out_obj;
if (lps0_device_handle)
return 0;
if (acpi_sleep_no_lps0) {
acpi_handle_info(adev->handle,
"Low Power S0 Idle interface disabled\n");
return 0;
}
if (!(acpi_gbl_FADT.flags & ACPI_FADT_LOW_POWER_S0))
return 0;
guid_parse(ACPI_LPS0_DSM_UUID, &lps0_dsm_guid);
out_obj = acpi_evaluate_dsm(adev->handle, &lps0_dsm_guid, 1, 0, NULL);
if (out_obj && out_obj->type == ACPI_TYPE_BUFFER) {
char bitmask = *(char *)out_obj->buffer.pointer;
if ((bitmask & ACPI_S2IDLE_FUNC_MASK) == ACPI_S2IDLE_FUNC_MASK) {
lps0_dsm_func_mask = bitmask;
lps0_device_handle = adev->handle;
if (mem_sleep_default > PM_SUSPEND_MEM)
mem_sleep_current = PM_SUSPEND_TO_IDLE;
}
acpi_handle_debug(adev->handle, "_DSM function mask: 0x%x\n",
bitmask);
} else {
acpi_handle_debug(adev->handle,
"_DSM function 0 evaluation failed\n");
}
ACPI_FREE(out_obj);
lpi_device_get_constraints();
return 0;
}
static int acpi_s2idle_begin(void)
{
acpi_scan_lock_acquire();
s2idle_in_progress = true;
return 0;
}
static int acpi_s2idle_prepare(void)
{
if (lps0_device_handle) {
acpi_sleep_run_lps0_dsm(ACPI_LPS0_SCREEN_OFF);
acpi_sleep_run_lps0_dsm(ACPI_LPS0_ENTRY);
} else {
acpi_enable_all_wakeup_gpes();
acpi_os_wait_events_complete();
}
if (acpi_sci_irq_valid())
enable_irq_wake(acpi_sci_irq);
return 0;
}
static void acpi_s2idle_wake(void)
{
if (pm_debug_messages_on)
lpi_check_constraints();
if (acpi_sci_irq_valid() &&
!irqd_is_wakeup_armed(irq_get_irq_data(acpi_sci_irq))) {
pm_system_cancel_wakeup();
s2idle_wakeup = true;
}
}
static void acpi_s2idle_sync(void)
{
acpi_ec_flush_work();
acpi_os_wait_events_complete();
s2idle_wakeup = false;
}
static void acpi_s2idle_restore(void)
{
if (acpi_sci_irq_valid())
disable_irq_wake(acpi_sci_irq);
if (lps0_device_handle) {
acpi_sleep_run_lps0_dsm(ACPI_LPS0_EXIT);
acpi_sleep_run_lps0_dsm(ACPI_LPS0_SCREEN_ON);
} else {
acpi_enable_all_runtime_gpes();
}
}
static void acpi_s2idle_end(void)
{
s2idle_in_progress = false;
acpi_scan_lock_release();
}
static void acpi_sleep_suspend_setup(void)
{
int i;
for (i = ACPI_STATE_S1; i < ACPI_STATE_S4; i++)
if (acpi_sleep_state_supported(i))
sleep_states[i] = 1;
suspend_set_ops(old_suspend_ordering ?
&acpi_suspend_ops_old : &acpi_suspend_ops);
acpi_scan_add_handler(&lps0_handler);
s2idle_set_ops(&acpi_s2idle_ops);
}
static inline void acpi_sleep_suspend_setup(void) {}
bool acpi_s2idle_wakeup(void)
{
return s2idle_wakeup;
}
bool acpi_sleep_no_ec_events(void)
{
return !s2idle_in_progress || !lps0_device_handle;
}
static int acpi_save_bm_rld(void)
{
acpi_read_bit_register(ACPI_BITREG_BUS_MASTER_RLD, &saved_bm_rld);
return 0;
}
static void acpi_restore_bm_rld(void)
{
u32 resumed_bm_rld = 0;
acpi_read_bit_register(ACPI_BITREG_BUS_MASTER_RLD, &resumed_bm_rld);
if (resumed_bm_rld == saved_bm_rld)
return;
acpi_write_bit_register(ACPI_BITREG_BUS_MASTER_RLD, saved_bm_rld);
}
static void acpi_sleep_syscore_init(void)
{
register_syscore_ops(&acpi_sleep_syscore_ops);
}
static inline void acpi_sleep_syscore_init(void) {}
void __init acpi_no_s4_hw_signature(void)
{
nosigcheck = true;
}
static int acpi_hibernation_begin(void)
{
int error;
error = nvs_nosave ? 0 : suspend_nvs_alloc();
if (!error)
acpi_pm_start(ACPI_STATE_S4);
return error;
}
static int acpi_hibernation_enter(void)
{
acpi_status status = AE_OK;
ACPI_FLUSH_CPU_CACHE();
status = acpi_enter_sleep_state(ACPI_STATE_S4);
acpi_leave_sleep_state_prep(ACPI_STATE_S4);
return ACPI_SUCCESS(status) ? 0 : -EFAULT;
}
static void acpi_hibernation_leave(void)
{
pm_set_resume_via_firmware();
acpi_enable();
acpi_leave_sleep_state_prep(ACPI_STATE_S4);
if (facs && s4_hardware_signature != facs->hardware_signature)
pr_crit("ACPI: Hardware changed while hibernated, success doubtful!\n");
suspend_nvs_restore();
acpi_ec_unblock_transactions();
}
static void acpi_pm_thaw(void)
{
acpi_ec_unblock_transactions();
acpi_enable_all_runtime_gpes();
}
static int acpi_hibernation_begin_old(void)
{
int error;
acpi_sleep_tts_switch(ACPI_STATE_S4);
error = acpi_sleep_prepare(ACPI_STATE_S4);
if (!error) {
if (!nvs_nosave)
error = suspend_nvs_alloc();
if (!error) {
acpi_target_sleep_state = ACPI_STATE_S4;
acpi_scan_lock_acquire();
}
}
return error;
}
static void acpi_sleep_hibernate_setup(void)
{
if (!acpi_sleep_state_supported(ACPI_STATE_S4))
return;
hibernation_set_ops(old_suspend_ordering ?
&acpi_hibernation_ops_old : &acpi_hibernation_ops);
sleep_states[ACPI_STATE_S4] = 1;
if (nosigcheck)
return;
acpi_get_table(ACPI_SIG_FACS, 1, (struct acpi_table_header **)&facs);
if (facs)
s4_hardware_signature = facs->hardware_signature;
}
static inline void acpi_sleep_hibernate_setup(void) {}
static void acpi_power_off_prepare(void)
{
acpi_sleep_prepare(ACPI_STATE_S5);
acpi_disable_all_gpes();
acpi_os_wait_events_complete();
}
static void acpi_power_off(void)
{
printk(KERN_DEBUG "%s called\n", __func__);
local_irq_disable();
acpi_enter_sleep_state(ACPI_STATE_S5);
}
int __init acpi_sleep_init(void)
{
char supported[ACPI_S_STATE_COUNT * 3 + 1];
char *pos = supported;
int i;
acpi_sleep_dmi_check();
sleep_states[ACPI_STATE_S0] = 1;
acpi_sleep_syscore_init();
acpi_sleep_suspend_setup();
acpi_sleep_hibernate_setup();
if (acpi_sleep_state_supported(ACPI_STATE_S5)) {
sleep_states[ACPI_STATE_S5] = 1;
pm_power_off_prepare = acpi_power_off_prepare;
pm_power_off = acpi_power_off;
} else {
acpi_no_s5 = true;
}
supported[0] = 0;
for (i = 0; i < ACPI_S_STATE_COUNT; i++) {
if (sleep_states[i])
pos += sprintf(pos, " S%d", i);
}
pr_info(PREFIX "(supports%s)\n", supported);
register_reboot_notifier(&tts_notifier);
return 0;
}
