static void acpi_sleep_tts_switch(u32 acpi_state)
{
union acpi_object in_arg = { ACPI_TYPE_INTEGER };
struct acpi_object_list arg_list = { 1, &in_arg };
acpi_status status = AE_OK;
in_arg.integer.value = acpi_state;
status = acpi_evaluate_object(NULL, "\\_TTS", &arg_list, NULL);
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
acpi_set_firmware_waking_vector(acpi_wakeup_address);
}
ACPI_FLUSH_CPU_CACHE();
#endif
printk(KERN_INFO PREFIX "Preparing to enter system sleep state S%d\n",
acpi_state);
acpi_enable_wakeup_devices(acpi_state);
acpi_enter_sleep_state_prep(acpi_state);
return 0;
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
static void acpi_sleep_dmi_check(void)
{
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
acpi_set_firmware_waking_vector((acpi_physical_address) 0);
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
static void acpi_pm_end(void)
{
acpi_target_sleep_state = ACPI_STATE_S0;
acpi_sleep_tts_switch(acpi_target_sleep_state);
}
static inline void acpi_sleep_dmi_check(void) {}
static int acpi_suspend_begin(suspend_state_t pm_state)
{
u32 acpi_state = acpi_suspend_states[pm_state];
int error = 0;
error = (nvs_nosave || nvs_nosave_s3) ? 0 : suspend_nvs_alloc();
if (error)
return error;
if (sleep_states[acpi_state]) {
acpi_target_sleep_state = acpi_state;
acpi_sleep_tts_switch(acpi_target_sleep_state);
} else {
printk(KERN_ERR "ACPI does not support this state: %d\n",
pm_state);
error = -ENOSYS;
}
return error;
}
static int acpi_suspend_enter(suspend_state_t pm_state)
{
acpi_status status = AE_OK;
u32 acpi_state = acpi_target_sleep_state;
int error;
ACPI_FLUSH_CPU_CACHE();
switch (acpi_state) {
case ACPI_STATE_S1:
barrier();
status = acpi_enter_sleep_state(acpi_state);
break;
case ACPI_STATE_S3:
error = acpi_suspend_lowlevel();
if (error)
return error;
pr_info(PREFIX "Low-level resume complete\n");
break;
}
acpi_write_bit_register(ACPI_BITREG_SCI_ENABLE, 1);
acpi_leave_sleep_state_prep(acpi_state);
if (ACPI_SUCCESS(status) && (acpi_state == ACPI_STATE_S3)) {
acpi_event_status pwr_btn_status;
acpi_get_event_status(ACPI_EVENT_POWER_BUTTON, &pwr_btn_status);
if (pwr_btn_status & ACPI_EVENT_FLAG_SET) {
acpi_clear_event(ACPI_EVENT_POWER_BUTTON);
pwr_btn_event_pending = true;
}
}
acpi_disable_all_gpes();
acpi_ec_unblock_transactions_early();
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
static void acpi_sleep_suspend_setup(void)
{
int i;
for (i = ACPI_STATE_S1; i < ACPI_STATE_S4; i++) {
acpi_status status;
u8 type_a, type_b;
status = acpi_get_sleep_type_data(i, &type_a, &type_b);
if (ACPI_SUCCESS(status)) {
sleep_states[i] = 1;
}
}
suspend_set_ops(old_suspend_ordering ?
&acpi_suspend_ops_old : &acpi_suspend_ops);
}
static inline void acpi_sleep_suspend_setup(void) {}
void __init acpi_no_s4_hw_signature(void)
{
nosigcheck = true;
}
static int acpi_hibernation_begin(void)
{
int error;
error = nvs_nosave ? 0 : suspend_nvs_alloc();
if (!error) {
acpi_target_sleep_state = ACPI_STATE_S4;
acpi_sleep_tts_switch(acpi_target_sleep_state);
}
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
acpi_enable();
acpi_leave_sleep_state_prep(ACPI_STATE_S4);
if (facs && s4_hardware_signature != facs->hardware_signature) {
printk(KERN_EMERG "ACPI: Hardware changed while hibernated, "
"cannot resume!\n");
panic("ACPI S4 hardware signature mismatch");
}
suspend_nvs_restore();
acpi_ec_unblock_transactions_early();
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
if (!error)
acpi_target_sleep_state = ACPI_STATE_S4;
}
return error;
}
static void acpi_sleep_hibernate_setup(void)
{
acpi_status status;
u8 type_a, type_b;
status = acpi_get_sleep_type_data(ACPI_STATE_S4, &type_a, &type_b);
if (ACPI_FAILURE(status))
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
int acpi_suspend(u32 acpi_state)
{
suspend_state_t states[] = {
[1] = PM_SUSPEND_STANDBY,
[3] = PM_SUSPEND_MEM,
[5] = PM_SUSPEND_MAX
};
if (acpi_state < 6 && states[acpi_state])
return pm_suspend(states[acpi_state]);
if (acpi_state == 4)
return hibernate();
return -EINVAL;
}
static void acpi_power_off_prepare(void)
{
acpi_sleep_prepare(ACPI_STATE_S5);
acpi_disable_all_gpes();
}
static void acpi_power_off(void)
{
printk(KERN_DEBUG "%s called\n", __func__);
local_irq_disable();
acpi_enter_sleep_state(ACPI_STATE_S5);
}
int __init acpi_sleep_init(void)
{
acpi_status status;
u8 type_a, type_b;
char supported[ACPI_S_STATE_COUNT * 3 + 1];
char *pos = supported;
int i;
if (acpi_disabled)
return 0;
acpi_sleep_dmi_check();
sleep_states[ACPI_STATE_S0] = 1;
acpi_sleep_suspend_setup();
acpi_sleep_hibernate_setup();
status = acpi_get_sleep_type_data(ACPI_STATE_S5, &type_a, &type_b);
if (ACPI_SUCCESS(status)) {
sleep_states[ACPI_STATE_S5] = 1;
pm_power_off_prepare = acpi_power_off_prepare;
pm_power_off = acpi_power_off;
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
