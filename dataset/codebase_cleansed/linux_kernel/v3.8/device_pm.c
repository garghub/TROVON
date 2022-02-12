acpi_status acpi_add_pm_notifier(struct acpi_device *adev,
acpi_notify_handler handler, void *context)
{
acpi_status status = AE_ALREADY_EXISTS;
mutex_lock(&acpi_pm_notifier_lock);
if (adev->wakeup.flags.notifier_present)
goto out;
status = acpi_install_notify_handler(adev->handle,
ACPI_SYSTEM_NOTIFY,
handler, context);
if (ACPI_FAILURE(status))
goto out;
adev->wakeup.flags.notifier_present = true;
out:
mutex_unlock(&acpi_pm_notifier_lock);
return status;
}
acpi_status acpi_remove_pm_notifier(struct acpi_device *adev,
acpi_notify_handler handler)
{
acpi_status status = AE_BAD_PARAMETER;
mutex_lock(&acpi_pm_notifier_lock);
if (!adev->wakeup.flags.notifier_present)
goto out;
status = acpi_remove_notify_handler(adev->handle,
ACPI_SYSTEM_NOTIFY,
handler);
if (ACPI_FAILURE(status))
goto out;
adev->wakeup.flags.notifier_present = false;
out:
mutex_unlock(&acpi_pm_notifier_lock);
return status;
}
int acpi_device_power_state(struct device *dev, struct acpi_device *adev,
u32 target_state, int d_max_in, int *d_min_p)
{
char acpi_method[] = "_SxD";
unsigned long long d_min, d_max;
bool wakeup = false;
if (d_max_in < ACPI_STATE_D0 || d_max_in > ACPI_STATE_D3)
return -EINVAL;
if (d_max_in > ACPI_STATE_D3_HOT) {
enum pm_qos_flags_status stat;
stat = dev_pm_qos_flags(dev, PM_QOS_FLAG_NO_POWER_OFF);
if (stat == PM_QOS_FLAGS_ALL)
d_max_in = ACPI_STATE_D3_HOT;
}
acpi_method[2] = '0' + target_state;
d_min = ACPI_STATE_D0;
d_max = ACPI_STATE_D3;
if (target_state > ACPI_STATE_S0) {
acpi_evaluate_integer(adev->handle, acpi_method, NULL, &d_min);
wakeup = device_may_wakeup(dev) && adev->wakeup.flags.valid
&& adev->wakeup.sleep_state >= target_state;
} else if (dev_pm_qos_flags(dev, PM_QOS_FLAG_REMOTE_WAKEUP) !=
PM_QOS_FLAGS_NONE) {
wakeup = adev->wakeup.flags.valid;
}
if (wakeup) {
acpi_status status;
acpi_method[3] = 'W';
status = acpi_evaluate_integer(adev->handle, acpi_method, NULL,
&d_max);
if (ACPI_FAILURE(status)) {
if (target_state != ACPI_STATE_S0 ||
status != AE_NOT_FOUND)
d_max = d_min;
} else if (d_max < d_min) {
printk(KERN_WARNING "ACPI: Wrong value from %s\n",
acpi_method);
d_min = d_max;
}
}
if (d_max_in < d_min)
return -EINVAL;
if (d_min_p)
*d_min_p = d_min;
if (d_max > d_max_in) {
for (d_max = d_max_in; d_max > d_min; d_max--) {
if (adev->power.states[d_max].flags.valid)
break;
}
}
return d_max;
}
int acpi_pm_device_sleep_state(struct device *dev, int *d_min_p, int d_max_in)
{
acpi_handle handle = DEVICE_ACPI_HANDLE(dev);
struct acpi_device *adev;
if (!handle || ACPI_FAILURE(acpi_bus_get_device(handle, &adev))) {
dev_dbg(dev, "ACPI handle without context in %s!\n", __func__);
return -ENODEV;
}
return acpi_device_power_state(dev, adev, acpi_target_system_state(),
d_max_in, d_min_p);
}
static void acpi_wakeup_device(acpi_handle handle, u32 event, void *context)
{
struct device *dev = context;
if (event == ACPI_NOTIFY_DEVICE_WAKE && dev) {
pm_wakeup_event(dev, 0);
pm_runtime_resume(dev);
}
}
int __acpi_device_run_wake(struct acpi_device *adev, bool enable)
{
struct acpi_device_wakeup *wakeup = &adev->wakeup;
if (enable) {
acpi_status res;
int error;
error = acpi_enable_wakeup_device_power(adev, ACPI_STATE_S0);
if (error)
return error;
res = acpi_enable_gpe(wakeup->gpe_device, wakeup->gpe_number);
if (ACPI_FAILURE(res)) {
acpi_disable_wakeup_device_power(adev);
return -EIO;
}
} else {
acpi_disable_gpe(wakeup->gpe_device, wakeup->gpe_number);
acpi_disable_wakeup_device_power(adev);
}
return 0;
}
int acpi_pm_device_run_wake(struct device *phys_dev, bool enable)
{
struct acpi_device *adev;
acpi_handle handle;
if (!device_run_wake(phys_dev))
return -EINVAL;
handle = DEVICE_ACPI_HANDLE(phys_dev);
if (!handle || ACPI_FAILURE(acpi_bus_get_device(handle, &adev))) {
dev_dbg(phys_dev, "ACPI handle without context in %s!\n",
__func__);
return -ENODEV;
}
return __acpi_device_run_wake(adev, enable);
}
static inline void acpi_wakeup_device(acpi_handle handle, u32 event,
void *context) {}
int __acpi_device_sleep_wake(struct acpi_device *adev, u32 target_state,
bool enable)
{
return enable ?
acpi_enable_wakeup_device_power(adev, target_state) :
acpi_disable_wakeup_device_power(adev);
}
int acpi_pm_device_sleep_wake(struct device *dev, bool enable)
{
acpi_handle handle;
struct acpi_device *adev;
int error;
if (!device_can_wakeup(dev))
return -EINVAL;
handle = DEVICE_ACPI_HANDLE(dev);
if (!handle || ACPI_FAILURE(acpi_bus_get_device(handle, &adev))) {
dev_dbg(dev, "ACPI handle without context in %s!\n", __func__);
return -ENODEV;
}
error = __acpi_device_sleep_wake(adev, acpi_target_system_state(),
enable);
if (!error)
dev_info(dev, "System wakeup %s by ACPI\n",
enable ? "enabled" : "disabled");
return error;
}
static struct acpi_device *acpi_dev_pm_get_node(struct device *dev)
{
acpi_handle handle = DEVICE_ACPI_HANDLE(dev);
struct acpi_device *adev;
return handle && !acpi_bus_get_device(handle, &adev) ? adev : NULL;
}
static int acpi_dev_pm_low_power(struct device *dev, struct acpi_device *adev,
u32 system_state)
{
int power_state;
if (!acpi_device_power_manageable(adev))
return 0;
power_state = acpi_device_power_state(dev, adev, system_state,
ACPI_STATE_D3, NULL);
if (power_state < ACPI_STATE_D0 || power_state > ACPI_STATE_D3)
return -EIO;
return acpi_device_set_power(adev, power_state);
}
static int acpi_dev_pm_full_power(struct acpi_device *adev)
{
return acpi_device_power_manageable(adev) ?
acpi_device_set_power(adev, ACPI_STATE_D0) : 0;
}
int acpi_dev_runtime_suspend(struct device *dev)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
bool remote_wakeup;
int error;
if (!adev)
return 0;
remote_wakeup = dev_pm_qos_flags(dev, PM_QOS_FLAG_REMOTE_WAKEUP) >
PM_QOS_FLAGS_NONE;
error = __acpi_device_run_wake(adev, remote_wakeup);
if (remote_wakeup && error)
return -EAGAIN;
error = acpi_dev_pm_low_power(dev, adev, ACPI_STATE_S0);
if (error)
__acpi_device_run_wake(adev, false);
return error;
}
int acpi_dev_runtime_resume(struct device *dev)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
int error;
if (!adev)
return 0;
error = acpi_dev_pm_full_power(adev);
__acpi_device_run_wake(adev, false);
return error;
}
int acpi_subsys_runtime_suspend(struct device *dev)
{
int ret = pm_generic_runtime_suspend(dev);
return ret ? ret : acpi_dev_runtime_suspend(dev);
}
int acpi_subsys_runtime_resume(struct device *dev)
{
int ret = acpi_dev_runtime_resume(dev);
return ret ? ret : pm_generic_runtime_resume(dev);
}
int acpi_dev_suspend_late(struct device *dev)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
u32 target_state;
bool wakeup;
int error;
if (!adev)
return 0;
target_state = acpi_target_system_state();
wakeup = device_may_wakeup(dev);
error = __acpi_device_sleep_wake(adev, target_state, wakeup);
if (wakeup && error)
return error;
error = acpi_dev_pm_low_power(dev, adev, target_state);
if (error)
__acpi_device_sleep_wake(adev, ACPI_STATE_UNKNOWN, false);
return error;
}
int acpi_dev_resume_early(struct device *dev)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
int error;
if (!adev)
return 0;
error = acpi_dev_pm_full_power(adev);
__acpi_device_sleep_wake(adev, ACPI_STATE_UNKNOWN, false);
return error;
}
int acpi_subsys_prepare(struct device *dev)
{
pm_runtime_resume(dev);
return pm_generic_prepare(dev);
}
int acpi_subsys_suspend_late(struct device *dev)
{
int ret = pm_generic_suspend_late(dev);
return ret ? ret : acpi_dev_suspend_late(dev);
}
int acpi_subsys_resume_early(struct device *dev)
{
int ret = acpi_dev_resume_early(dev);
return ret ? ret : pm_generic_resume_early(dev);
}
int acpi_dev_pm_attach(struct device *dev, bool power_on)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
if (!adev)
return -ENODEV;
if (dev->pm_domain)
return -EEXIST;
acpi_add_pm_notifier(adev, acpi_wakeup_device, dev);
dev->pm_domain = &acpi_general_pm_domain;
if (power_on) {
acpi_dev_pm_full_power(adev);
__acpi_device_run_wake(adev, false);
}
return 0;
}
void acpi_dev_pm_detach(struct device *dev, bool power_off)
{
struct acpi_device *adev = acpi_dev_pm_get_node(dev);
if (adev && dev->pm_domain == &acpi_general_pm_domain) {
dev->pm_domain = NULL;
acpi_remove_pm_notifier(adev, acpi_wakeup_device);
if (power_off) {
dev_pm_qos_hide_latency_limit(dev);
dev_pm_qos_hide_flags(dev);
__acpi_device_run_wake(adev, false);
acpi_dev_pm_low_power(dev, adev, ACPI_STATE_S0);
}
}
}
