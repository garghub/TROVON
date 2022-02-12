const char *acpi_power_state_string(int state)
{
switch (state) {
case ACPI_STATE_D0:
return "D0";
case ACPI_STATE_D1:
return "D1";
case ACPI_STATE_D2:
return "D2";
case ACPI_STATE_D3_HOT:
return "D3hot";
case ACPI_STATE_D3_COLD:
return "D3cold";
default:
return "(unknown)";
}
}
int acpi_device_get_power(struct acpi_device *device, int *state)
{
int result = ACPI_STATE_UNKNOWN;
if (!device || !state)
return -EINVAL;
if (!device->flags.power_manageable) {
*state = device->parent ?
device->parent->power.state : ACPI_STATE_D0;
goto out;
}
if (device->power.flags.power_resources) {
int error = acpi_power_get_inferred_state(device, &result);
if (error)
return error;
}
if (device->power.flags.explicit_get) {
acpi_handle handle = device->handle;
unsigned long long psc;
acpi_status status;
status = acpi_evaluate_integer(handle, "_PSC", NULL, &psc);
if (ACPI_FAILURE(status))
return -ENODEV;
if (psc > result && psc < ACPI_STATE_D3_COLD)
result = psc;
else if (result == ACPI_STATE_UNKNOWN)
result = psc > ACPI_STATE_D2 ? ACPI_STATE_D3_HOT : psc;
}
if (!device->power.flags.ignore_parent && device->parent
&& device->parent->power.state == ACPI_STATE_UNKNOWN
&& result == ACPI_STATE_D0)
device->parent->power.state = ACPI_STATE_D0;
*state = result;
out:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Device [%s] power state is %s\n",
device->pnp.bus_id, acpi_power_state_string(*state)));
return 0;
}
static int acpi_dev_pm_explicit_set(struct acpi_device *adev, int state)
{
if (adev->power.states[state].flags.explicit_set) {
char method[5] = { '_', 'P', 'S', '0' + state, '\0' };
acpi_status status;
status = acpi_evaluate_object(adev->handle, method, NULL, NULL);
if (ACPI_FAILURE(status))
return -ENODEV;
}
return 0;
}
int acpi_device_set_power(struct acpi_device *device, int state)
{
int target_state = state;
int result = 0;
if (!device || !device->flags.power_manageable
|| (state < ACPI_STATE_D0) || (state > ACPI_STATE_D3_COLD))
return -EINVAL;
if (state == device->power.state) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Device [%s] already in %s\n",
device->pnp.bus_id,
acpi_power_state_string(state)));
return 0;
}
if (state == ACPI_STATE_D3_COLD) {
state = ACPI_STATE_D3_HOT;
if (!device->power.states[ACPI_STATE_D3_COLD].flags.valid)
target_state = state;
} else if (!device->power.states[state].flags.valid) {
dev_warn(&device->dev, "Power state %s not supported\n",
acpi_power_state_string(state));
return -ENODEV;
}
if (!device->power.flags.ignore_parent &&
device->parent && (state < device->parent->power.state)) {
dev_warn(&device->dev,
"Cannot transition to power state %s for parent in %s\n",
acpi_power_state_string(state),
acpi_power_state_string(device->parent->power.state));
return -ENODEV;
}
if (state > ACPI_STATE_D0) {
if (state < device->power.state) {
dev_warn(&device->dev, "Cannot transition from %s to %s\n",
acpi_power_state_string(device->power.state),
acpi_power_state_string(state));
return -ENODEV;
}
result = acpi_dev_pm_explicit_set(device, state);
if (result)
goto end;
if (device->power.flags.power_resources)
result = acpi_power_transition(device, target_state);
} else {
if (device->power.flags.power_resources) {
result = acpi_power_transition(device, ACPI_STATE_D0);
if (result)
goto end;
}
result = acpi_dev_pm_explicit_set(device, ACPI_STATE_D0);
}
end:
if (result) {
dev_warn(&device->dev, "Failed to change power state to %s\n",
acpi_power_state_string(state));
} else {
device->power.state = target_state;
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Device [%s] transitioned to %s\n",
device->pnp.bus_id,
acpi_power_state_string(state)));
}
return result;
}
int acpi_bus_set_power(acpi_handle handle, int state)
{
struct acpi_device *device;
int result;
result = acpi_bus_get_device(handle, &device);
if (result)
return result;
return acpi_device_set_power(device, state);
}
int acpi_bus_init_power(struct acpi_device *device)
{
int state;
int result;
if (!device)
return -EINVAL;
device->power.state = ACPI_STATE_UNKNOWN;
if (!acpi_device_is_present(device))
return -ENXIO;
result = acpi_device_get_power(device, &state);
if (result)
return result;
if (state < ACPI_STATE_D3_COLD && device->power.flags.power_resources) {
result = acpi_power_on_resources(device, state);
if (result)
return result;
if (state == ACPI_STATE_D0) {
result = acpi_dev_pm_explicit_set(device, state);
if (result)
return result;
}
} else if (state == ACPI_STATE_UNKNOWN) {
state = ACPI_STATE_D0;
}
device->power.state = state;
return 0;
}
int acpi_device_fix_up_power(struct acpi_device *device)
{
int ret = 0;
if (!device->power.flags.power_resources
&& !device->power.flags.explicit_get
&& device->power.state == ACPI_STATE_D0)
ret = acpi_dev_pm_explicit_set(device, ACPI_STATE_D0);
return ret;
}
int acpi_device_update_power(struct acpi_device *device, int *state_p)
{
int state;
int result;
if (device->power.state == ACPI_STATE_UNKNOWN) {
result = acpi_bus_init_power(device);
if (!result && state_p)
*state_p = device->power.state;
return result;
}
result = acpi_device_get_power(device, &state);
if (result)
return result;
if (state == ACPI_STATE_UNKNOWN) {
state = ACPI_STATE_D0;
result = acpi_device_set_power(device, state);
if (result)
return result;
} else {
if (device->power.flags.power_resources) {
result = acpi_power_transition(device, state);
if (result)
return result;
}
device->power.state = state;
}
if (state_p)
*state_p = state;
return 0;
}
int acpi_bus_update_power(acpi_handle handle, int *state_p)
{
struct acpi_device *device;
int result;
result = acpi_bus_get_device(handle, &device);
return result ? result : acpi_device_update_power(device, state_p);
}
bool acpi_bus_power_manageable(acpi_handle handle)
{
struct acpi_device *device;
int result;
result = acpi_bus_get_device(handle, &device);
return result ? false : device->flags.power_manageable;
}
static void acpi_pm_notify_handler(acpi_handle handle, u32 val, void *not_used)
{
struct acpi_device *adev;
if (val != ACPI_NOTIFY_DEVICE_WAKE)
return;
adev = acpi_bus_get_acpi_device(handle);
if (!adev)
return;
mutex_lock(&acpi_pm_notifier_lock);
if (adev->wakeup.flags.notifier_present) {
__pm_wakeup_event(adev->wakeup.ws, 0);
if (adev->wakeup.context.work.func)
queue_pm_work(&adev->wakeup.context.work);
}
mutex_unlock(&acpi_pm_notifier_lock);
acpi_bus_put_acpi_device(adev);
}
acpi_status acpi_add_pm_notifier(struct acpi_device *adev, struct device *dev,
void (*work_func)(struct work_struct *work))
{
acpi_status status = AE_ALREADY_EXISTS;
if (!dev && !work_func)
return AE_BAD_PARAMETER;
mutex_lock(&acpi_pm_notifier_lock);
if (adev->wakeup.flags.notifier_present)
goto out;
adev->wakeup.ws = wakeup_source_register(dev_name(&adev->dev));
adev->wakeup.context.dev = dev;
if (work_func)
INIT_WORK(&adev->wakeup.context.work, work_func);
status = acpi_install_notify_handler(adev->handle, ACPI_SYSTEM_NOTIFY,
acpi_pm_notify_handler, NULL);
if (ACPI_FAILURE(status))
goto out;
adev->wakeup.flags.notifier_present = true;
out:
mutex_unlock(&acpi_pm_notifier_lock);
return status;
}
acpi_status acpi_remove_pm_notifier(struct acpi_device *adev)
{
acpi_status status = AE_BAD_PARAMETER;
mutex_lock(&acpi_pm_notifier_lock);
if (!adev->wakeup.flags.notifier_present)
goto out;
status = acpi_remove_notify_handler(adev->handle,
ACPI_SYSTEM_NOTIFY,
acpi_pm_notify_handler);
if (ACPI_FAILURE(status))
goto out;
if (adev->wakeup.context.work.func) {
cancel_work_sync(&adev->wakeup.context.work);
adev->wakeup.context.work.func = NULL;
}
adev->wakeup.context.dev = NULL;
wakeup_source_unregister(adev->wakeup.ws);
adev->wakeup.flags.notifier_present = false;
out:
mutex_unlock(&acpi_pm_notifier_lock);
return status;
}
bool acpi_bus_can_wakeup(acpi_handle handle)
{
struct acpi_device *device;
int result;
result = acpi_bus_get_device(handle, &device);
return result ? false : device->wakeup.flags.valid;
}
static int acpi_dev_pm_get_state(struct device *dev, struct acpi_device *adev,
u32 target_state, int *d_min_p, int *d_max_p)
{
char method[] = { '_', 'S', '0' + target_state, 'D', '\0' };
acpi_handle handle = adev->handle;
unsigned long long ret;
int d_min, d_max;
bool wakeup = false;
acpi_status status;
d_min = ACPI_STATE_D0;
d_max = ACPI_STATE_D3_COLD;
if (target_state > ACPI_STATE_S0) {
ret = d_min;
status = acpi_evaluate_integer(handle, method, NULL, &ret);
if ((ACPI_FAILURE(status) && status != AE_NOT_FOUND)
|| ret > ACPI_STATE_D3_COLD)
return -ENODATA;
if (!adev->power.states[ret].flags.valid) {
if (ret == ACPI_STATE_D3_HOT)
ret = ACPI_STATE_D3_COLD;
else
return -ENODATA;
}
d_min = ret;
wakeup = device_may_wakeup(dev) && adev->wakeup.flags.valid
&& adev->wakeup.sleep_state >= target_state;
} else if (dev_pm_qos_flags(dev, PM_QOS_FLAG_REMOTE_WAKEUP) !=
PM_QOS_FLAGS_NONE) {
wakeup = adev->wakeup.flags.valid;
}
if (wakeup) {
method[3] = 'W';
status = acpi_evaluate_integer(handle, method, NULL, &ret);
if (status == AE_NOT_FOUND) {
if (target_state > ACPI_STATE_S0)
d_max = d_min;
} else if (ACPI_SUCCESS(status) && ret <= ACPI_STATE_D3_COLD) {
if (!adev->power.states[ret].flags.valid)
ret = ACPI_STATE_D3_COLD;
d_max = ret > d_min ? ret : d_min;
} else {
return -ENODATA;
}
}
if (d_min_p)
*d_min_p = d_min;
if (d_max_p)
*d_max_p = d_max;
return 0;
}
int acpi_pm_device_sleep_state(struct device *dev, int *d_min_p, int d_max_in)
{
struct acpi_device *adev;
int ret, d_min, d_max;
if (d_max_in < ACPI_STATE_D0 || d_max_in > ACPI_STATE_D3_COLD)
return -EINVAL;
if (d_max_in > ACPI_STATE_D2) {
enum pm_qos_flags_status stat;
stat = dev_pm_qos_flags(dev, PM_QOS_FLAG_NO_POWER_OFF);
if (stat == PM_QOS_FLAGS_ALL)
d_max_in = ACPI_STATE_D2;
}
adev = ACPI_COMPANION(dev);
if (!adev) {
dev_dbg(dev, "ACPI companion missing in %s!\n", __func__);
return -ENODEV;
}
ret = acpi_dev_pm_get_state(dev, adev, acpi_target_system_state(),
&d_min, &d_max);
if (ret)
return ret;
if (d_max_in < d_min)
return -EINVAL;
if (d_max > d_max_in) {
for (d_max = d_max_in; d_max > d_min; d_max--) {
if (adev->power.states[d_max].flags.valid)
break;
}
}
if (d_min_p)
*d_min_p = d_min;
return d_max;
}
static void acpi_pm_notify_work_func(struct work_struct *work)
{
struct device *dev;
dev = container_of(work, struct acpi_device_wakeup_context, work)->dev;
if (dev) {
pm_wakeup_event(dev, 0);
pm_runtime_resume(dev);
}
}
static int acpi_device_wakeup(struct acpi_device *adev, u32 target_state,
bool enable)
{
struct acpi_device_wakeup *wakeup = &adev->wakeup;
if (enable) {
acpi_status res;
int error;
error = acpi_enable_wakeup_device_power(adev, target_state);
if (error)
return error;
if (adev->wakeup.flags.enabled)
return 0;
res = acpi_enable_gpe(wakeup->gpe_device, wakeup->gpe_number);
if (ACPI_SUCCESS(res)) {
adev->wakeup.flags.enabled = 1;
} else {
acpi_disable_wakeup_device_power(adev);
return -EIO;
}
} else {
if (adev->wakeup.flags.enabled) {
acpi_disable_gpe(wakeup->gpe_device, wakeup->gpe_number);
adev->wakeup.flags.enabled = 0;
}
acpi_disable_wakeup_device_power(adev);
}
return 0;
}
int acpi_pm_device_run_wake(struct device *phys_dev, bool enable)
{
struct acpi_device *adev;
if (!device_run_wake(phys_dev))
return -EINVAL;
adev = ACPI_COMPANION(phys_dev);
if (!adev) {
dev_dbg(phys_dev, "ACPI companion missing in %s!\n", __func__);
return -ENODEV;
}
return acpi_device_wakeup(adev, ACPI_STATE_S0, enable);
}
int acpi_pm_device_sleep_wake(struct device *dev, bool enable)
{
struct acpi_device *adev;
int error;
if (!device_can_wakeup(dev))
return -EINVAL;
adev = ACPI_COMPANION(dev);
if (!adev) {
dev_dbg(dev, "ACPI companion missing in %s!\n", __func__);
return -ENODEV;
}
error = acpi_device_wakeup(adev, acpi_target_system_state(), enable);
if (!error)
dev_info(dev, "System wakeup %s by ACPI\n",
enable ? "enabled" : "disabled");
return error;
}
static int acpi_dev_pm_low_power(struct device *dev, struct acpi_device *adev,
u32 system_state)
{
int ret, state;
if (!acpi_device_power_manageable(adev))
return 0;
ret = acpi_dev_pm_get_state(dev, adev, system_state, NULL, &state);
return ret ? ret : acpi_device_set_power(adev, state);
}
static int acpi_dev_pm_full_power(struct acpi_device *adev)
{
return acpi_device_power_manageable(adev) ?
acpi_device_set_power(adev, ACPI_STATE_D0) : 0;
}
int acpi_dev_runtime_suspend(struct device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
bool remote_wakeup;
int error;
if (!adev)
return 0;
remote_wakeup = dev_pm_qos_flags(dev, PM_QOS_FLAG_REMOTE_WAKEUP) >
PM_QOS_FLAGS_NONE;
error = acpi_device_wakeup(adev, ACPI_STATE_S0, remote_wakeup);
if (remote_wakeup && error)
return -EAGAIN;
error = acpi_dev_pm_low_power(dev, adev, ACPI_STATE_S0);
if (error)
acpi_device_wakeup(adev, ACPI_STATE_S0, false);
return error;
}
int acpi_dev_runtime_resume(struct device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
int error;
if (!adev)
return 0;
error = acpi_dev_pm_full_power(adev);
acpi_device_wakeup(adev, ACPI_STATE_S0, false);
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
struct acpi_device *adev = ACPI_COMPANION(dev);
u32 target_state;
bool wakeup;
int error;
if (!adev)
return 0;
target_state = acpi_target_system_state();
wakeup = device_may_wakeup(dev) && acpi_device_can_wakeup(adev);
error = acpi_device_wakeup(adev, target_state, wakeup);
if (wakeup && error)
return error;
error = acpi_dev_pm_low_power(dev, adev, target_state);
if (error)
acpi_device_wakeup(adev, ACPI_STATE_UNKNOWN, false);
return error;
}
int acpi_dev_resume_early(struct device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
int error;
if (!adev)
return 0;
error = acpi_dev_pm_full_power(adev);
acpi_device_wakeup(adev, ACPI_STATE_UNKNOWN, false);
return error;
}
int acpi_subsys_prepare(struct device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
u32 sys_target;
int ret, state;
ret = pm_generic_prepare(dev);
if (ret < 0)
return ret;
if (!adev || !pm_runtime_suspended(dev)
|| device_may_wakeup(dev) != !!adev->wakeup.prepare_count)
return 0;
sys_target = acpi_target_system_state();
if (sys_target == ACPI_STATE_S0)
return 1;
if (adev->power.flags.dsw_present)
return 0;
ret = acpi_dev_pm_get_state(dev, adev, sys_target, NULL, &state);
return !ret && state == adev->power.state;
}
void acpi_subsys_complete(struct device *dev)
{
pm_generic_complete(dev);
if (dev->power.direct_complete)
pm_request_resume(dev);
}
int acpi_subsys_suspend(struct device *dev)
{
pm_runtime_resume(dev);
return pm_generic_suspend(dev);
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
int acpi_subsys_freeze(struct device *dev)
{
pm_runtime_resume(dev);
return pm_generic_freeze(dev);
}
static void acpi_dev_pm_detach(struct device *dev, bool power_off)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
if (adev && dev->pm_domain == &acpi_general_pm_domain) {
dev->pm_domain = NULL;
acpi_remove_pm_notifier(adev);
if (power_off) {
dev_pm_qos_hide_latency_limit(dev);
dev_pm_qos_hide_flags(dev);
acpi_device_wakeup(adev, ACPI_STATE_S0, false);
acpi_dev_pm_low_power(dev, adev, ACPI_STATE_S0);
}
}
}
int acpi_dev_pm_attach(struct device *dev, bool power_on)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
if (!adev)
return -ENODEV;
if (dev->pm_domain)
return -EEXIST;
if (!acpi_device_is_first_physical_node(adev, dev))
return -EBUSY;
acpi_add_pm_notifier(adev, dev, acpi_pm_notify_work_func);
dev->pm_domain = &acpi_general_pm_domain;
if (power_on) {
acpi_dev_pm_full_power(adev);
acpi_device_wakeup(adev, ACPI_STATE_S0, false);
}
dev->pm_domain->detach = acpi_dev_pm_detach;
return 0;
}
