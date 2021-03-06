static int write_acpi_int(acpi_handle handle, const char *method, int val)
{
struct acpi_object_list params;
union acpi_object in_obj;
acpi_status status;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = val;
status = acpi_evaluate_object(handle, (char *)method, &params, NULL);
return (status == AE_OK ? 0 : -1);
}
static int read_acpi_int(acpi_handle handle, const char *method, int *val)
{
acpi_status status;
unsigned long long result;
status = acpi_evaluate_integer(handle, (char *)method, NULL, &result);
if (ACPI_FAILURE(status)) {
*val = -1;
return -1;
} else {
*val = result;
return 0;
}
}
static int set_acpi(struct eeepc_laptop *eeepc, int cm, int value)
{
const char *method = cm_setv[cm];
if (method == NULL)
return -ENODEV;
if ((eeepc->cm_supported & (0x1 << cm)) == 0)
return -ENODEV;
if (write_acpi_int(eeepc->handle, method, value))
pr_warn("Error writing %s\n", method);
return 0;
}
static int get_acpi(struct eeepc_laptop *eeepc, int cm)
{
const char *method = cm_getv[cm];
int value;
if (method == NULL)
return -ENODEV;
if ((eeepc->cm_supported & (0x1 << cm)) == 0)
return -ENODEV;
if (read_acpi_int(eeepc->handle, method, &value))
pr_warn("Error reading %s\n", method);
return value;
}
static int acpi_setter_handle(struct eeepc_laptop *eeepc, int cm,
acpi_handle *handle)
{
const char *method = cm_setv[cm];
acpi_status status;
if (method == NULL)
return -ENODEV;
if ((eeepc->cm_supported & (0x1 << cm)) == 0)
return -ENODEV;
status = acpi_get_handle(eeepc->handle, (char *)method,
handle);
if (status != AE_OK) {
pr_warn("Error finding %s\n", method);
return -ENODEV;
}
return 0;
}
static int parse_arg(const char *buf, unsigned long count, int *val)
{
if (!count)
return 0;
if (sscanf(buf, "%i", val) != 1)
return -EINVAL;
return count;
}
static ssize_t store_sys_acpi(struct device *dev, int cm,
const char *buf, size_t count)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0)
value = set_acpi(eeepc, cm, value);
if (value < 0)
return -EIO;
return rv;
}
static ssize_t show_sys_acpi(struct device *dev, int cm, char *buf)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
int value = get_acpi(eeepc, cm);
if (value < 0)
return -EIO;
return sprintf(buf, "%d\n", value);
}
static int get_cpufv(struct eeepc_laptop *eeepc, struct eeepc_cpufv *c)
{
c->cur = get_acpi(eeepc, CM_ASL_CPUFV);
c->num = (c->cur >> 8) & 0xff;
c->cur &= 0xff;
if (c->cur < 0 || c->num <= 0 || c->num > 12)
return -ENODEV;
return 0;
}
static ssize_t show_available_cpufv(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
struct eeepc_cpufv c;
int i;
ssize_t len = 0;
if (get_cpufv(eeepc, &c))
return -ENODEV;
for (i = 0; i < c.num; i++)
len += sprintf(buf + len, "%d ", i);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t show_cpufv(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
struct eeepc_cpufv c;
if (get_cpufv(eeepc, &c))
return -ENODEV;
return sprintf(buf, "%#x\n", (c.num << 8) | c.cur);
}
static ssize_t store_cpufv(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
struct eeepc_cpufv c;
int rv, value;
if (eeepc->cpufv_disabled)
return -EPERM;
if (get_cpufv(eeepc, &c))
return -ENODEV;
rv = parse_arg(buf, count, &value);
if (rv < 0)
return rv;
if (!rv || value < 0 || value >= c.num)
return -EINVAL;
set_acpi(eeepc, CM_ASL_CPUFV, value);
return rv;
}
static ssize_t show_cpufv_disabled(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", eeepc->cpufv_disabled);
}
static ssize_t store_cpufv_disabled(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv < 0)
return rv;
switch (value) {
case 0:
if (eeepc->cpufv_disabled)
pr_warn("cpufv enabled (not officially supported "
"on this model)\n");
eeepc->cpufv_disabled = false;
return rv;
case 1:
return -EPERM;
default:
return -EINVAL;
}
}
static int eeepc_platform_init(struct eeepc_laptop *eeepc)
{
int result;
eeepc->platform_device = platform_device_alloc(EEEPC_LAPTOP_FILE, -1);
if (!eeepc->platform_device)
return -ENOMEM;
platform_set_drvdata(eeepc->platform_device, eeepc);
result = platform_device_add(eeepc->platform_device);
if (result)
goto fail_platform_device;
result = sysfs_create_group(&eeepc->platform_device->dev.kobj,
&platform_attribute_group);
if (result)
goto fail_sysfs;
return 0;
fail_sysfs:
platform_device_del(eeepc->platform_device);
fail_platform_device:
platform_device_put(eeepc->platform_device);
return result;
}
static void eeepc_platform_exit(struct eeepc_laptop *eeepc)
{
sysfs_remove_group(&eeepc->platform_device->dev.kobj,
&platform_attribute_group);
platform_device_unregister(eeepc->platform_device);
}
static void tpd_led_update(struct work_struct *work)
{
struct eeepc_laptop *eeepc;
eeepc = container_of(work, struct eeepc_laptop, tpd_led_work);
set_acpi(eeepc, CM_ASL_TPD, eeepc->tpd_led_wk);
}
static void tpd_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct eeepc_laptop *eeepc;
eeepc = container_of(led_cdev, struct eeepc_laptop, tpd_led);
eeepc->tpd_led_wk = (value > 0) ? 1 : 0;
queue_work(eeepc->led_workqueue, &eeepc->tpd_led_work);
}
static enum led_brightness tpd_led_get(struct led_classdev *led_cdev)
{
struct eeepc_laptop *eeepc;
eeepc = container_of(led_cdev, struct eeepc_laptop, tpd_led);
return get_acpi(eeepc, CM_ASL_TPD);
}
static int eeepc_led_init(struct eeepc_laptop *eeepc)
{
int rv;
if (get_acpi(eeepc, CM_ASL_TPD) == -ENODEV)
return 0;
eeepc->led_workqueue = create_singlethread_workqueue("led_workqueue");
if (!eeepc->led_workqueue)
return -ENOMEM;
INIT_WORK(&eeepc->tpd_led_work, tpd_led_update);
eeepc->tpd_led.name = "eeepc::touchpad";
eeepc->tpd_led.brightness_set = tpd_led_set;
if (get_acpi(eeepc, CM_ASL_TPD) >= 0)
eeepc->tpd_led.brightness_get = tpd_led_get;
eeepc->tpd_led.max_brightness = 1;
rv = led_classdev_register(&eeepc->platform_device->dev,
&eeepc->tpd_led);
if (rv) {
destroy_workqueue(eeepc->led_workqueue);
return rv;
}
return 0;
}
static void eeepc_led_exit(struct eeepc_laptop *eeepc)
{
if (!IS_ERR_OR_NULL(eeepc->tpd_led.dev))
led_classdev_unregister(&eeepc->tpd_led);
if (eeepc->led_workqueue)
destroy_workqueue(eeepc->led_workqueue);
}
static bool eeepc_wlan_rfkill_blocked(struct eeepc_laptop *eeepc)
{
if (get_acpi(eeepc, CM_ASL_WLAN) == 1)
return false;
return true;
}
static void eeepc_rfkill_hotplug(struct eeepc_laptop *eeepc, acpi_handle handle)
{
struct pci_dev *port;
struct pci_dev *dev;
struct pci_bus *bus;
bool blocked = eeepc_wlan_rfkill_blocked(eeepc);
bool absent;
u32 l;
if (eeepc->wlan_rfkill)
rfkill_set_sw_state(eeepc->wlan_rfkill, blocked);
mutex_lock(&eeepc->hotplug_lock);
if (eeepc->hotplug_slot) {
port = acpi_get_pci_dev(handle);
if (!port) {
pr_warning("Unable to find port\n");
goto out_unlock;
}
bus = port->subordinate;
if (!bus) {
pr_warn("Unable to find PCI bus 1?\n");
goto out_put_dev;
}
if (pci_bus_read_config_dword(bus, 0, PCI_VENDOR_ID, &l)) {
pr_err("Unable to read PCI config space?\n");
goto out_put_dev;
}
absent = (l == 0xffffffff);
if (blocked != absent) {
pr_warn("BIOS says wireless lan is %s, "
"but the pci device is %s\n",
blocked ? "blocked" : "unblocked",
absent ? "absent" : "present");
pr_warn("skipped wireless hotplug as probably "
"inappropriate for this model\n");
goto out_put_dev;
}
if (!blocked) {
dev = pci_get_slot(bus, 0);
if (dev) {
pci_dev_put(dev);
goto out_put_dev;
}
dev = pci_scan_single_device(bus, 0);
if (dev) {
pci_bus_assign_resources(bus);
if (pci_bus_add_device(dev))
pr_err("Unable to hotplug wifi\n");
}
} else {
dev = pci_get_slot(bus, 0);
if (dev) {
pci_stop_and_remove_bus_device(dev);
pci_dev_put(dev);
}
}
out_put_dev:
pci_dev_put(port);
}
out_unlock:
mutex_unlock(&eeepc->hotplug_lock);
}
static void eeepc_rfkill_hotplug_update(struct eeepc_laptop *eeepc, char *node)
{
acpi_status status = AE_OK;
acpi_handle handle;
status = acpi_get_handle(NULL, node, &handle);
if (ACPI_SUCCESS(status))
eeepc_rfkill_hotplug(eeepc, handle);
}
static void eeepc_rfkill_notify(acpi_handle handle, u32 event, void *data)
{
struct eeepc_laptop *eeepc = data;
if (event != ACPI_NOTIFY_BUS_CHECK)
return;
eeepc_rfkill_hotplug(eeepc, handle);
}
static int eeepc_register_rfkill_notifier(struct eeepc_laptop *eeepc,
char *node)
{
acpi_status status;
acpi_handle handle;
status = acpi_get_handle(NULL, node, &handle);
if (ACPI_SUCCESS(status)) {
status = acpi_install_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
eeepc_rfkill_notify,
eeepc);
if (ACPI_FAILURE(status))
pr_warn("Failed to register notify on %s\n", node);
eeepc_rfkill_hotplug(eeepc, handle);
} else
return -ENODEV;
return 0;
}
static void eeepc_unregister_rfkill_notifier(struct eeepc_laptop *eeepc,
char *node)
{
acpi_status status = AE_OK;
acpi_handle handle;
status = acpi_get_handle(NULL, node, &handle);
if (ACPI_SUCCESS(status)) {
status = acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
eeepc_rfkill_notify);
if (ACPI_FAILURE(status))
pr_err("Error removing rfkill notify handler %s\n",
node);
eeepc_rfkill_hotplug(eeepc, handle);
}
}
static int eeepc_get_adapter_status(struct hotplug_slot *hotplug_slot,
u8 *value)
{
struct eeepc_laptop *eeepc = hotplug_slot->private;
int val = get_acpi(eeepc, CM_ASL_WLAN);
if (val == 1 || val == 0)
*value = val;
else
return -EINVAL;
return 0;
}
static void eeepc_cleanup_pci_hotplug(struct hotplug_slot *hotplug_slot)
{
kfree(hotplug_slot->info);
kfree(hotplug_slot);
}
static int eeepc_setup_pci_hotplug(struct eeepc_laptop *eeepc)
{
int ret = -ENOMEM;
struct pci_bus *bus = pci_find_bus(0, 1);
if (!bus) {
pr_err("Unable to find wifi PCI bus\n");
return -ENODEV;
}
eeepc->hotplug_slot = kzalloc(sizeof(struct hotplug_slot), GFP_KERNEL);
if (!eeepc->hotplug_slot)
goto error_slot;
eeepc->hotplug_slot->info = kzalloc(sizeof(struct hotplug_slot_info),
GFP_KERNEL);
if (!eeepc->hotplug_slot->info)
goto error_info;
eeepc->hotplug_slot->private = eeepc;
eeepc->hotplug_slot->release = &eeepc_cleanup_pci_hotplug;
eeepc->hotplug_slot->ops = &eeepc_hotplug_slot_ops;
eeepc_get_adapter_status(eeepc->hotplug_slot,
&eeepc->hotplug_slot->info->adapter_status);
ret = pci_hp_register(eeepc->hotplug_slot, bus, 0, "eeepc-wifi");
if (ret) {
pr_err("Unable to register hotplug slot - %d\n", ret);
goto error_register;
}
return 0;
error_register:
kfree(eeepc->hotplug_slot->info);
error_info:
kfree(eeepc->hotplug_slot);
eeepc->hotplug_slot = NULL;
error_slot:
return ret;
}
static int eeepc_rfkill_set(void *data, bool blocked)
{
acpi_handle handle = data;
return write_acpi_int(handle, NULL, !blocked);
}
static int eeepc_new_rfkill(struct eeepc_laptop *eeepc,
struct rfkill **rfkill,
const char *name,
enum rfkill_type type, int cm)
{
acpi_handle handle;
int result;
result = acpi_setter_handle(eeepc, cm, &handle);
if (result < 0)
return result;
*rfkill = rfkill_alloc(name, &eeepc->platform_device->dev, type,
&eeepc_rfkill_ops, handle);
if (!*rfkill)
return -EINVAL;
rfkill_init_sw_state(*rfkill, get_acpi(eeepc, cm) != 1);
result = rfkill_register(*rfkill);
if (result) {
rfkill_destroy(*rfkill);
*rfkill = NULL;
return result;
}
return 0;
}
static void eeepc_rfkill_exit(struct eeepc_laptop *eeepc)
{
eeepc_unregister_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P5");
eeepc_unregister_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P6");
eeepc_unregister_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P7");
if (eeepc->wlan_rfkill) {
rfkill_unregister(eeepc->wlan_rfkill);
rfkill_destroy(eeepc->wlan_rfkill);
eeepc->wlan_rfkill = NULL;
}
if (eeepc->hotplug_slot)
pci_hp_deregister(eeepc->hotplug_slot);
if (eeepc->bluetooth_rfkill) {
rfkill_unregister(eeepc->bluetooth_rfkill);
rfkill_destroy(eeepc->bluetooth_rfkill);
eeepc->bluetooth_rfkill = NULL;
}
if (eeepc->wwan3g_rfkill) {
rfkill_unregister(eeepc->wwan3g_rfkill);
rfkill_destroy(eeepc->wwan3g_rfkill);
eeepc->wwan3g_rfkill = NULL;
}
if (eeepc->wimax_rfkill) {
rfkill_unregister(eeepc->wimax_rfkill);
rfkill_destroy(eeepc->wimax_rfkill);
eeepc->wimax_rfkill = NULL;
}
}
static int eeepc_rfkill_init(struct eeepc_laptop *eeepc)
{
int result = 0;
mutex_init(&eeepc->hotplug_lock);
result = eeepc_new_rfkill(eeepc, &eeepc->wlan_rfkill,
"eeepc-wlan", RFKILL_TYPE_WLAN,
CM_ASL_WLAN);
if (result && result != -ENODEV)
goto exit;
result = eeepc_new_rfkill(eeepc, &eeepc->bluetooth_rfkill,
"eeepc-bluetooth", RFKILL_TYPE_BLUETOOTH,
CM_ASL_BLUETOOTH);
if (result && result != -ENODEV)
goto exit;
result = eeepc_new_rfkill(eeepc, &eeepc->wwan3g_rfkill,
"eeepc-wwan3g", RFKILL_TYPE_WWAN,
CM_ASL_3G);
if (result && result != -ENODEV)
goto exit;
result = eeepc_new_rfkill(eeepc, &eeepc->wimax_rfkill,
"eeepc-wimax", RFKILL_TYPE_WIMAX,
CM_ASL_WIMAX);
if (result && result != -ENODEV)
goto exit;
if (eeepc->hotplug_disabled)
return 0;
result = eeepc_setup_pci_hotplug(eeepc);
if (result == -EBUSY)
result = 0;
eeepc_register_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P5");
eeepc_register_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P6");
eeepc_register_rfkill_notifier(eeepc, "\\_SB.PCI0.P0P7");
exit:
if (result && result != -ENODEV)
eeepc_rfkill_exit(eeepc);
return result;
}
static int eeepc_hotk_thaw(struct device *device)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(device);
if (eeepc->wlan_rfkill) {
bool wlan;
wlan = get_acpi(eeepc, CM_ASL_WLAN);
set_acpi(eeepc, CM_ASL_WLAN, wlan);
}
return 0;
}
static int eeepc_hotk_restore(struct device *device)
{
struct eeepc_laptop *eeepc = dev_get_drvdata(device);
if (eeepc->wlan_rfkill) {
eeepc_rfkill_hotplug_update(eeepc, "\\_SB.PCI0.P0P5");
eeepc_rfkill_hotplug_update(eeepc, "\\_SB.PCI0.P0P6");
eeepc_rfkill_hotplug_update(eeepc, "\\_SB.PCI0.P0P7");
}
if (eeepc->bluetooth_rfkill)
rfkill_set_sw_state(eeepc->bluetooth_rfkill,
get_acpi(eeepc, CM_ASL_BLUETOOTH) != 1);
if (eeepc->wwan3g_rfkill)
rfkill_set_sw_state(eeepc->wwan3g_rfkill,
get_acpi(eeepc, CM_ASL_3G) != 1);
if (eeepc->wimax_rfkill)
rfkill_set_sw_state(eeepc->wimax_rfkill,
get_acpi(eeepc, CM_ASL_WIMAX) != 1);
return 0;
}
static int eeepc_get_fan_pwm(void)
{
u8 value = 0;
ec_read(EEEPC_EC_FAN_PWM, &value);
return value * 255 / 100;
}
static void eeepc_set_fan_pwm(int value)
{
value = clamp_val(value, 0, 255);
value = value * 100 / 255;
ec_write(EEEPC_EC_FAN_PWM, value);
}
static int eeepc_get_fan_rpm(void)
{
u8 high = 0;
u8 low = 0;
ec_read(EEEPC_EC_FAN_HRPM, &high);
ec_read(EEEPC_EC_FAN_LRPM, &low);
return high << 8 | low;
}
static int eeepc_get_fan_ctrl(void)
{
u8 value = 0;
ec_read(EEEPC_EC_FAN_CTRL, &value);
if (value & 0x02)
return 1;
else
return 2;
}
static void eeepc_set_fan_ctrl(int manual)
{
u8 value = 0;
ec_read(EEEPC_EC_FAN_CTRL, &value);
if (manual == 1)
value |= 0x02;
else
value &= ~0x02;
ec_write(EEEPC_EC_FAN_CTRL, value);
}
static ssize_t store_sys_hwmon(void (*set)(int), const char *buf, size_t count)
{
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0)
set(value);
return rv;
}
static ssize_t show_sys_hwmon(int (*get)(void), char *buf)
{
return sprintf(buf, "%d\n", get());
}
static ssize_t
show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "eeepc\n");
}
static void eeepc_hwmon_exit(struct eeepc_laptop *eeepc)
{
struct device *hwmon;
hwmon = eeepc->hwmon_device;
if (!hwmon)
return;
sysfs_remove_group(&hwmon->kobj,
&hwmon_attribute_group);
hwmon_device_unregister(hwmon);
eeepc->hwmon_device = NULL;
}
static int eeepc_hwmon_init(struct eeepc_laptop *eeepc)
{
struct device *hwmon;
int result;
hwmon = hwmon_device_register(&eeepc->platform_device->dev);
if (IS_ERR(hwmon)) {
pr_err("Could not register eeepc hwmon device\n");
eeepc->hwmon_device = NULL;
return PTR_ERR(hwmon);
}
eeepc->hwmon_device = hwmon;
result = sysfs_create_group(&hwmon->kobj,
&hwmon_attribute_group);
if (result)
eeepc_hwmon_exit(eeepc);
return result;
}
static int read_brightness(struct backlight_device *bd)
{
struct eeepc_laptop *eeepc = bl_get_data(bd);
return get_acpi(eeepc, CM_ASL_PANELBRIGHT);
}
static int set_brightness(struct backlight_device *bd, int value)
{
struct eeepc_laptop *eeepc = bl_get_data(bd);
return set_acpi(eeepc, CM_ASL_PANELBRIGHT, value);
}
static int update_bl_status(struct backlight_device *bd)
{
return set_brightness(bd, bd->props.brightness);
}
static int eeepc_backlight_notify(struct eeepc_laptop *eeepc)
{
struct backlight_device *bd = eeepc->backlight_device;
int old = bd->props.brightness;
backlight_force_update(bd, BACKLIGHT_UPDATE_HOTKEY);
return old;
}
static int eeepc_backlight_init(struct eeepc_laptop *eeepc)
{
struct backlight_properties props;
struct backlight_device *bd;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = 15;
bd = backlight_device_register(EEEPC_LAPTOP_FILE,
&eeepc->platform_device->dev, eeepc,
&eeepcbl_ops, &props);
if (IS_ERR(bd)) {
pr_err("Could not register eeepc backlight device\n");
eeepc->backlight_device = NULL;
return PTR_ERR(bd);
}
eeepc->backlight_device = bd;
bd->props.brightness = read_brightness(bd);
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
return 0;
}
static void eeepc_backlight_exit(struct eeepc_laptop *eeepc)
{
if (eeepc->backlight_device)
backlight_device_unregister(eeepc->backlight_device);
eeepc->backlight_device = NULL;
}
static int eeepc_input_init(struct eeepc_laptop *eeepc)
{
struct input_dev *input;
int error;
input = input_allocate_device();
if (!input) {
pr_info("Unable to allocate input device\n");
return -ENOMEM;
}
input->name = "Asus EeePC extra buttons";
input->phys = EEEPC_LAPTOP_FILE "/input0";
input->id.bustype = BUS_HOST;
input->dev.parent = &eeepc->platform_device->dev;
error = sparse_keymap_setup(input, eeepc_keymap, NULL);
if (error) {
pr_err("Unable to setup input device keymap\n");
goto err_free_dev;
}
error = input_register_device(input);
if (error) {
pr_err("Unable to register input device\n");
goto err_free_keymap;
}
eeepc->inputdev = input;
return 0;
err_free_keymap:
sparse_keymap_free(input);
err_free_dev:
input_free_device(input);
return error;
}
static void eeepc_input_exit(struct eeepc_laptop *eeepc)
{
if (eeepc->inputdev) {
sparse_keymap_free(eeepc->inputdev);
input_unregister_device(eeepc->inputdev);
}
eeepc->inputdev = NULL;
}
static void eeepc_input_notify(struct eeepc_laptop *eeepc, int event)
{
if (!eeepc->inputdev)
return ;
if (!sparse_keymap_report_event(eeepc->inputdev, event, 1, true))
pr_info("Unknown key %x pressed\n", event);
}
static void eeepc_acpi_notify(struct acpi_device *device, u32 event)
{
struct eeepc_laptop *eeepc = acpi_driver_data(device);
u16 count;
if (event > ACPI_MAX_SYS_NOTIFY)
return;
count = eeepc->event_count[event % 128]++;
acpi_bus_generate_proc_event(device, event, count);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event,
count);
if (event >= NOTIFY_BRN_MIN && event <= NOTIFY_BRN_MAX) {
if (eeepc->backlight_device != NULL) {
int old_brightness, new_brightness;
old_brightness = eeepc_backlight_notify(eeepc);
new_brightness = event - NOTIFY_BRN_MIN;
if (new_brightness < old_brightness) {
event = NOTIFY_BRN_MIN;
} else if (new_brightness > old_brightness) {
event = NOTIFY_BRN_MAX;
} else {
}
eeepc_input_notify(eeepc, event);
}
} else {
eeepc_input_notify(eeepc, event);
}
}
static void eeepc_dmi_check(struct eeepc_laptop *eeepc)
{
const char *model;
model = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!model)
return;
if (strcmp(model, "701") == 0 || strcmp(model, "702") == 0) {
eeepc->cpufv_disabled = true;
pr_info("model %s does not officially support setting cpu "
"speed\n", model);
pr_info("cpufv disabled to avoid instability\n");
}
if (strcmp(model, "1005HA") == 0 || strcmp(model, "1201N") == 0 ||
strcmp(model, "1005PE") == 0) {
eeepc->hotplug_disabled = true;
pr_info("wlan hotplug disabled\n");
}
}
static void cmsg_quirk(struct eeepc_laptop *eeepc, int cm, const char *name)
{
int dummy;
if (!(eeepc->cm_supported & (1 << cm))
&& !read_acpi_int(eeepc->handle, cm_getv[cm], &dummy)) {
pr_info("%s (%x) not reported by BIOS,"
" enabling anyway\n", name, 1 << cm);
eeepc->cm_supported |= 1 << cm;
}
}
static void cmsg_quirks(struct eeepc_laptop *eeepc)
{
cmsg_quirk(eeepc, CM_ASL_LID, "LID");
cmsg_quirk(eeepc, CM_ASL_TYPE, "TYPE");
cmsg_quirk(eeepc, CM_ASL_PANELPOWER, "PANELPOWER");
cmsg_quirk(eeepc, CM_ASL_TPD, "TPD");
}
static int eeepc_acpi_init(struct eeepc_laptop *eeepc)
{
unsigned int init_flags;
int result;
result = acpi_bus_get_status(eeepc->device);
if (result)
return result;
if (!eeepc->device->status.present) {
pr_err("Hotkey device not present, aborting\n");
return -ENODEV;
}
init_flags = DISABLE_ASL_WLAN | DISABLE_ASL_DISPLAYSWITCH;
pr_notice("Hotkey init flags 0x%x\n", init_flags);
if (write_acpi_int(eeepc->handle, "INIT", init_flags)) {
pr_err("Hotkey initialization failed\n");
return -ENODEV;
}
if (read_acpi_int(eeepc->handle, "CMSG", &eeepc->cm_supported)) {
pr_err("Get control methods supported failed\n");
return -ENODEV;
}
cmsg_quirks(eeepc);
pr_info("Get control methods supported: 0x%x\n", eeepc->cm_supported);
return 0;
}
static void eeepc_enable_camera(struct eeepc_laptop *eeepc)
{
if (get_acpi(eeepc, CM_ASL_CAMERA) == 0)
set_acpi(eeepc, CM_ASL_CAMERA, 1);
}
static int eeepc_acpi_add(struct acpi_device *device)
{
struct eeepc_laptop *eeepc;
int result;
pr_notice(EEEPC_LAPTOP_NAME "\n");
eeepc = kzalloc(sizeof(struct eeepc_laptop), GFP_KERNEL);
if (!eeepc)
return -ENOMEM;
eeepc->handle = device->handle;
strcpy(acpi_device_name(device), EEEPC_ACPI_DEVICE_NAME);
strcpy(acpi_device_class(device), EEEPC_ACPI_CLASS);
device->driver_data = eeepc;
eeepc->device = device;
eeepc->hotplug_disabled = hotplug_disabled;
eeepc_dmi_check(eeepc);
result = eeepc_acpi_init(eeepc);
if (result)
goto fail_platform;
eeepc_enable_camera(eeepc);
result = eeepc_platform_init(eeepc);
if (result)
goto fail_platform;
if (!acpi_video_backlight_support()) {
result = eeepc_backlight_init(eeepc);
if (result)
goto fail_backlight;
} else
pr_info("Backlight controlled by ACPI video driver\n");
result = eeepc_input_init(eeepc);
if (result)
goto fail_input;
result = eeepc_hwmon_init(eeepc);
if (result)
goto fail_hwmon;
result = eeepc_led_init(eeepc);
if (result)
goto fail_led;
result = eeepc_rfkill_init(eeepc);
if (result)
goto fail_rfkill;
eeepc_device_present = true;
return 0;
fail_rfkill:
eeepc_led_exit(eeepc);
fail_led:
eeepc_hwmon_exit(eeepc);
fail_hwmon:
eeepc_input_exit(eeepc);
fail_input:
eeepc_backlight_exit(eeepc);
fail_backlight:
eeepc_platform_exit(eeepc);
fail_platform:
kfree(eeepc);
return result;
}
static int eeepc_acpi_remove(struct acpi_device *device)
{
struct eeepc_laptop *eeepc = acpi_driver_data(device);
eeepc_backlight_exit(eeepc);
eeepc_rfkill_exit(eeepc);
eeepc_input_exit(eeepc);
eeepc_hwmon_exit(eeepc);
eeepc_led_exit(eeepc);
eeepc_platform_exit(eeepc);
kfree(eeepc);
return 0;
}
static int __init eeepc_laptop_init(void)
{
int result;
result = platform_driver_register(&platform_driver);
if (result < 0)
return result;
result = acpi_bus_register_driver(&eeepc_acpi_driver);
if (result < 0)
goto fail_acpi_driver;
if (!eeepc_device_present) {
result = -ENODEV;
goto fail_no_device;
}
return 0;
fail_no_device:
acpi_bus_unregister_driver(&eeepc_acpi_driver);
fail_acpi_driver:
platform_driver_unregister(&platform_driver);
return result;
}
static void __exit eeepc_laptop_exit(void)
{
acpi_bus_unregister_driver(&eeepc_acpi_driver);
platform_driver_unregister(&platform_driver);
}
