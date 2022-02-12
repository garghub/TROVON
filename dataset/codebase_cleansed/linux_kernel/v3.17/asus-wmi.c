static int asus_wmi_input_init(struct asus_wmi *asus)
{
int err;
asus->inputdev = input_allocate_device();
if (!asus->inputdev)
return -ENOMEM;
asus->inputdev->name = asus->driver->input_name;
asus->inputdev->phys = asus->driver->input_phys;
asus->inputdev->id.bustype = BUS_HOST;
asus->inputdev->dev.parent = &asus->platform_device->dev;
set_bit(EV_REP, asus->inputdev->evbit);
err = sparse_keymap_setup(asus->inputdev, asus->driver->keymap, NULL);
if (err)
goto err_free_dev;
err = input_register_device(asus->inputdev);
if (err)
goto err_free_keymap;
return 0;
err_free_keymap:
sparse_keymap_free(asus->inputdev);
err_free_dev:
input_free_device(asus->inputdev);
return err;
}
static void asus_wmi_input_exit(struct asus_wmi *asus)
{
if (asus->inputdev) {
sparse_keymap_free(asus->inputdev);
input_unregister_device(asus->inputdev);
}
asus->inputdev = NULL;
}
static int asus_wmi_evaluate_method(u32 method_id, u32 arg0, u32 arg1,
u32 *retval)
{
struct bios_args args = {
.arg0 = arg0,
.arg1 = arg1,
};
struct acpi_buffer input = { (acpi_size) sizeof(args), &args };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
union acpi_object *obj;
u32 tmp = 0;
status = wmi_evaluate_method(ASUS_WMI_MGMT_GUID, 1, method_id,
&input, &output);
if (ACPI_FAILURE(status))
goto exit;
obj = (union acpi_object *)output.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER)
tmp = (u32) obj->integer.value;
if (retval)
*retval = tmp;
kfree(obj);
exit:
if (ACPI_FAILURE(status))
return -EIO;
if (tmp == ASUS_WMI_UNSUPPORTED_METHOD)
return -ENODEV;
return 0;
}
static int asus_wmi_get_devstate(struct asus_wmi *asus, u32 dev_id, u32 *retval)
{
return asus_wmi_evaluate_method(asus->dsts_id, dev_id, 0, retval);
}
static int asus_wmi_set_devstate(u32 dev_id, u32 ctrl_param,
u32 *retval)
{
return asus_wmi_evaluate_method(ASUS_WMI_METHODID_DEVS, dev_id,
ctrl_param, retval);
}
static int asus_wmi_get_devstate_bits(struct asus_wmi *asus,
u32 dev_id, u32 mask)
{
u32 retval = 0;
int err;
err = asus_wmi_get_devstate(asus, dev_id, &retval);
if (err < 0)
return err;
if (!(retval & ASUS_WMI_DSTS_PRESENCE_BIT))
return -ENODEV;
if (mask == ASUS_WMI_DSTS_STATUS_BIT) {
if (retval & ASUS_WMI_DSTS_UNKNOWN_BIT)
return -ENODEV;
}
return retval & mask;
}
static int asus_wmi_get_devstate_simple(struct asus_wmi *asus, u32 dev_id)
{
return asus_wmi_get_devstate_bits(asus, dev_id,
ASUS_WMI_DSTS_STATUS_BIT);
}
static void tpd_led_update(struct work_struct *work)
{
int ctrl_param;
struct asus_wmi *asus;
asus = container_of(work, struct asus_wmi, tpd_led_work);
ctrl_param = asus->tpd_led_wk;
asus_wmi_set_devstate(ASUS_WMI_DEVID_TOUCHPAD_LED, ctrl_param, NULL);
}
static void tpd_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct asus_wmi *asus;
asus = container_of(led_cdev, struct asus_wmi, tpd_led);
asus->tpd_led_wk = !!value;
queue_work(asus->led_workqueue, &asus->tpd_led_work);
}
static int read_tpd_led_state(struct asus_wmi *asus)
{
return asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_TOUCHPAD_LED);
}
static enum led_brightness tpd_led_get(struct led_classdev *led_cdev)
{
struct asus_wmi *asus;
asus = container_of(led_cdev, struct asus_wmi, tpd_led);
return read_tpd_led_state(asus);
}
static void kbd_led_update(struct work_struct *work)
{
int ctrl_param = 0;
struct asus_wmi *asus;
asus = container_of(work, struct asus_wmi, kbd_led_work);
if (asus->kbd_led_wk > 0)
ctrl_param = 0x80 | (asus->kbd_led_wk & 0x7F);
asus_wmi_set_devstate(ASUS_WMI_DEVID_KBD_BACKLIGHT, ctrl_param, NULL);
}
static int kbd_led_read(struct asus_wmi *asus, int *level, int *env)
{
int retval;
retval = asus_wmi_get_devstate_bits(asus, ASUS_WMI_DEVID_KBD_BACKLIGHT,
0xFFFF);
if (retval == 0x8000)
retval = 0;
if (retval >= 0) {
if (level)
*level = retval & 0x7F;
if (env)
*env = (retval >> 8) & 0x7F;
retval = 0;
}
return retval;
}
static void kbd_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct asus_wmi *asus;
asus = container_of(led_cdev, struct asus_wmi, kbd_led);
if (value > asus->kbd_led.max_brightness)
value = asus->kbd_led.max_brightness;
else if (value < 0)
value = 0;
asus->kbd_led_wk = value;
queue_work(asus->led_workqueue, &asus->kbd_led_work);
}
static enum led_brightness kbd_led_get(struct led_classdev *led_cdev)
{
struct asus_wmi *asus;
int retval, value;
asus = container_of(led_cdev, struct asus_wmi, kbd_led);
retval = kbd_led_read(asus, &value, NULL);
if (retval < 0)
return retval;
return value;
}
static int wlan_led_unknown_state(struct asus_wmi *asus)
{
u32 result;
asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_WIRELESS_LED, &result);
return result & ASUS_WMI_DSTS_UNKNOWN_BIT;
}
static int wlan_led_presence(struct asus_wmi *asus)
{
u32 result;
asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_WIRELESS_LED, &result);
return result & ASUS_WMI_DSTS_PRESENCE_BIT;
}
static void wlan_led_update(struct work_struct *work)
{
int ctrl_param;
struct asus_wmi *asus;
asus = container_of(work, struct asus_wmi, wlan_led_work);
ctrl_param = asus->wlan_led_wk;
asus_wmi_set_devstate(ASUS_WMI_DEVID_WIRELESS_LED, ctrl_param, NULL);
}
static void wlan_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct asus_wmi *asus;
asus = container_of(led_cdev, struct asus_wmi, wlan_led);
asus->wlan_led_wk = !!value;
queue_work(asus->led_workqueue, &asus->wlan_led_work);
}
static enum led_brightness wlan_led_get(struct led_classdev *led_cdev)
{
struct asus_wmi *asus;
u32 result;
asus = container_of(led_cdev, struct asus_wmi, wlan_led);
asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_WIRELESS_LED, &result);
return result & ASUS_WMI_DSTS_BRIGHTNESS_MASK;
}
static void asus_wmi_led_exit(struct asus_wmi *asus)
{
if (!IS_ERR_OR_NULL(asus->kbd_led.dev))
led_classdev_unregister(&asus->kbd_led);
if (!IS_ERR_OR_NULL(asus->tpd_led.dev))
led_classdev_unregister(&asus->tpd_led);
if (!IS_ERR_OR_NULL(asus->wlan_led.dev))
led_classdev_unregister(&asus->wlan_led);
if (asus->led_workqueue)
destroy_workqueue(asus->led_workqueue);
}
static int asus_wmi_led_init(struct asus_wmi *asus)
{
int rv = 0;
asus->led_workqueue = create_singlethread_workqueue("led_workqueue");
if (!asus->led_workqueue)
return -ENOMEM;
if (read_tpd_led_state(asus) >= 0) {
INIT_WORK(&asus->tpd_led_work, tpd_led_update);
asus->tpd_led.name = "asus::touchpad";
asus->tpd_led.brightness_set = tpd_led_set;
asus->tpd_led.brightness_get = tpd_led_get;
asus->tpd_led.max_brightness = 1;
rv = led_classdev_register(&asus->platform_device->dev,
&asus->tpd_led);
if (rv)
goto error;
}
if (kbd_led_read(asus, NULL, NULL) >= 0) {
INIT_WORK(&asus->kbd_led_work, kbd_led_update);
asus->kbd_led.name = "asus::kbd_backlight";
asus->kbd_led.brightness_set = kbd_led_set;
asus->kbd_led.brightness_get = kbd_led_get;
asus->kbd_led.max_brightness = 3;
rv = led_classdev_register(&asus->platform_device->dev,
&asus->kbd_led);
if (rv)
goto error;
}
if (wlan_led_presence(asus) && (asus->driver->quirks->wapf > 0)) {
INIT_WORK(&asus->wlan_led_work, wlan_led_update);
asus->wlan_led.name = "asus::wlan";
asus->wlan_led.brightness_set = wlan_led_set;
if (!wlan_led_unknown_state(asus))
asus->wlan_led.brightness_get = wlan_led_get;
asus->wlan_led.flags = LED_CORE_SUSPENDRESUME;
asus->wlan_led.max_brightness = 1;
asus->wlan_led.default_trigger = "asus-wlan";
rv = led_classdev_register(&asus->platform_device->dev,
&asus->wlan_led);
}
error:
if (rv)
asus_wmi_led_exit(asus);
return rv;
}
static bool asus_wlan_rfkill_blocked(struct asus_wmi *asus)
{
int result = asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_WLAN);
if (result < 0)
return false;
return !result;
}
static void asus_rfkill_hotplug(struct asus_wmi *asus)
{
struct pci_dev *dev;
struct pci_bus *bus;
bool blocked;
bool absent;
u32 l;
mutex_lock(&asus->wmi_lock);
blocked = asus_wlan_rfkill_blocked(asus);
mutex_unlock(&asus->wmi_lock);
mutex_lock(&asus->hotplug_lock);
pci_lock_rescan_remove();
if (asus->wlan.rfkill)
rfkill_set_sw_state(asus->wlan.rfkill, blocked);
if (asus->hotplug_slot) {
bus = pci_find_bus(0, 1);
if (!bus) {
pr_warn("Unable to find PCI bus 1?\n");
goto out_unlock;
}
if (pci_bus_read_config_dword(bus, 0, PCI_VENDOR_ID, &l)) {
pr_err("Unable to read PCI config space?\n");
goto out_unlock;
}
absent = (l == 0xffffffff);
if (blocked != absent) {
pr_warn("BIOS says wireless lan is %s, "
"but the pci device is %s\n",
blocked ? "blocked" : "unblocked",
absent ? "absent" : "present");
pr_warn("skipped wireless hotplug as probably "
"inappropriate for this model\n");
goto out_unlock;
}
if (!blocked) {
dev = pci_get_slot(bus, 0);
if (dev) {
pci_dev_put(dev);
goto out_unlock;
}
dev = pci_scan_single_device(bus, 0);
if (dev) {
pci_bus_assign_resources(bus);
pci_bus_add_device(dev);
}
} else {
dev = pci_get_slot(bus, 0);
if (dev) {
pci_stop_and_remove_bus_device(dev);
pci_dev_put(dev);
}
}
}
out_unlock:
pci_unlock_rescan_remove();
mutex_unlock(&asus->hotplug_lock);
}
static void asus_rfkill_notify(acpi_handle handle, u32 event, void *data)
{
struct asus_wmi *asus = data;
if (event != ACPI_NOTIFY_BUS_CHECK)
return;
queue_work(asus->hotplug_workqueue, &asus->hotplug_work);
}
static int asus_register_rfkill_notifier(struct asus_wmi *asus, char *node)
{
acpi_status status;
acpi_handle handle;
status = acpi_get_handle(NULL, node, &handle);
if (ACPI_SUCCESS(status)) {
status = acpi_install_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
asus_rfkill_notify, asus);
if (ACPI_FAILURE(status))
pr_warn("Failed to register notify on %s\n", node);
} else
return -ENODEV;
return 0;
}
static void asus_unregister_rfkill_notifier(struct asus_wmi *asus, char *node)
{
acpi_status status = AE_OK;
acpi_handle handle;
status = acpi_get_handle(NULL, node, &handle);
if (ACPI_SUCCESS(status)) {
status = acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
asus_rfkill_notify);
if (ACPI_FAILURE(status))
pr_err("Error removing rfkill notify handler %s\n",
node);
}
}
static int asus_get_adapter_status(struct hotplug_slot *hotplug_slot,
u8 *value)
{
struct asus_wmi *asus = hotplug_slot->private;
int result = asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_WLAN);
if (result < 0)
return result;
*value = !!result;
return 0;
}
static void asus_cleanup_pci_hotplug(struct hotplug_slot *hotplug_slot)
{
kfree(hotplug_slot->info);
kfree(hotplug_slot);
}
static void asus_hotplug_work(struct work_struct *work)
{
struct asus_wmi *asus;
asus = container_of(work, struct asus_wmi, hotplug_work);
asus_rfkill_hotplug(asus);
}
static int asus_setup_pci_hotplug(struct asus_wmi *asus)
{
int ret = -ENOMEM;
struct pci_bus *bus = pci_find_bus(0, 1);
if (!bus) {
pr_err("Unable to find wifi PCI bus\n");
return -ENODEV;
}
asus->hotplug_workqueue =
create_singlethread_workqueue("hotplug_workqueue");
if (!asus->hotplug_workqueue)
goto error_workqueue;
INIT_WORK(&asus->hotplug_work, asus_hotplug_work);
asus->hotplug_slot = kzalloc(sizeof(struct hotplug_slot), GFP_KERNEL);
if (!asus->hotplug_slot)
goto error_slot;
asus->hotplug_slot->info = kzalloc(sizeof(struct hotplug_slot_info),
GFP_KERNEL);
if (!asus->hotplug_slot->info)
goto error_info;
asus->hotplug_slot->private = asus;
asus->hotplug_slot->release = &asus_cleanup_pci_hotplug;
asus->hotplug_slot->ops = &asus_hotplug_slot_ops;
asus_get_adapter_status(asus->hotplug_slot,
&asus->hotplug_slot->info->adapter_status);
ret = pci_hp_register(asus->hotplug_slot, bus, 0, "asus-wifi");
if (ret) {
pr_err("Unable to register hotplug slot - %d\n", ret);
goto error_register;
}
return 0;
error_register:
kfree(asus->hotplug_slot->info);
error_info:
kfree(asus->hotplug_slot);
asus->hotplug_slot = NULL;
error_slot:
destroy_workqueue(asus->hotplug_workqueue);
error_workqueue:
return ret;
}
static int asus_rfkill_set(void *data, bool blocked)
{
struct asus_rfkill *priv = data;
u32 ctrl_param = !blocked;
u32 dev_id = priv->dev_id;
if ((dev_id == ASUS_WMI_DEVID_WLAN) &&
priv->asus->driver->wlan_ctrl_by_user)
dev_id = ASUS_WMI_DEVID_WLAN_LED;
return asus_wmi_set_devstate(dev_id, ctrl_param, NULL);
}
static void asus_rfkill_query(struct rfkill *rfkill, void *data)
{
struct asus_rfkill *priv = data;
int result;
result = asus_wmi_get_devstate_simple(priv->asus, priv->dev_id);
if (result < 0)
return;
rfkill_set_sw_state(priv->rfkill, !result);
}
static int asus_rfkill_wlan_set(void *data, bool blocked)
{
struct asus_rfkill *priv = data;
struct asus_wmi *asus = priv->asus;
int ret;
mutex_lock(&asus->wmi_lock);
ret = asus_rfkill_set(data, blocked);
mutex_unlock(&asus->wmi_lock);
return ret;
}
static int asus_new_rfkill(struct asus_wmi *asus,
struct asus_rfkill *arfkill,
const char *name, enum rfkill_type type, int dev_id)
{
int result = asus_wmi_get_devstate_simple(asus, dev_id);
struct rfkill **rfkill = &arfkill->rfkill;
if (result < 0)
return result;
arfkill->dev_id = dev_id;
arfkill->asus = asus;
if (dev_id == ASUS_WMI_DEVID_WLAN &&
asus->driver->quirks->hotplug_wireless)
*rfkill = rfkill_alloc(name, &asus->platform_device->dev, type,
&asus_rfkill_wlan_ops, arfkill);
else
*rfkill = rfkill_alloc(name, &asus->platform_device->dev, type,
&asus_rfkill_ops, arfkill);
if (!*rfkill)
return -EINVAL;
if ((dev_id == ASUS_WMI_DEVID_WLAN) &&
(asus->driver->quirks->wapf > 0))
rfkill_set_led_trigger_name(*rfkill, "asus-wlan");
rfkill_init_sw_state(*rfkill, !result);
result = rfkill_register(*rfkill);
if (result) {
rfkill_destroy(*rfkill);
*rfkill = NULL;
return result;
}
return 0;
}
static void asus_wmi_rfkill_exit(struct asus_wmi *asus)
{
asus_unregister_rfkill_notifier(asus, "\\_SB.PCI0.P0P5");
asus_unregister_rfkill_notifier(asus, "\\_SB.PCI0.P0P6");
asus_unregister_rfkill_notifier(asus, "\\_SB.PCI0.P0P7");
if (asus->wlan.rfkill) {
rfkill_unregister(asus->wlan.rfkill);
rfkill_destroy(asus->wlan.rfkill);
asus->wlan.rfkill = NULL;
}
asus_rfkill_hotplug(asus);
if (asus->hotplug_slot)
pci_hp_deregister(asus->hotplug_slot);
if (asus->hotplug_workqueue)
destroy_workqueue(asus->hotplug_workqueue);
if (asus->bluetooth.rfkill) {
rfkill_unregister(asus->bluetooth.rfkill);
rfkill_destroy(asus->bluetooth.rfkill);
asus->bluetooth.rfkill = NULL;
}
if (asus->wimax.rfkill) {
rfkill_unregister(asus->wimax.rfkill);
rfkill_destroy(asus->wimax.rfkill);
asus->wimax.rfkill = NULL;
}
if (asus->wwan3g.rfkill) {
rfkill_unregister(asus->wwan3g.rfkill);
rfkill_destroy(asus->wwan3g.rfkill);
asus->wwan3g.rfkill = NULL;
}
if (asus->gps.rfkill) {
rfkill_unregister(asus->gps.rfkill);
rfkill_destroy(asus->gps.rfkill);
asus->gps.rfkill = NULL;
}
if (asus->uwb.rfkill) {
rfkill_unregister(asus->uwb.rfkill);
rfkill_destroy(asus->uwb.rfkill);
asus->uwb.rfkill = NULL;
}
}
static int asus_wmi_rfkill_init(struct asus_wmi *asus)
{
int result = 0;
mutex_init(&asus->hotplug_lock);
mutex_init(&asus->wmi_lock);
result = asus_new_rfkill(asus, &asus->wlan, "asus-wlan",
RFKILL_TYPE_WLAN, ASUS_WMI_DEVID_WLAN);
if (result && result != -ENODEV)
goto exit;
result = asus_new_rfkill(asus, &asus->bluetooth,
"asus-bluetooth", RFKILL_TYPE_BLUETOOTH,
ASUS_WMI_DEVID_BLUETOOTH);
if (result && result != -ENODEV)
goto exit;
result = asus_new_rfkill(asus, &asus->wimax, "asus-wimax",
RFKILL_TYPE_WIMAX, ASUS_WMI_DEVID_WIMAX);
if (result && result != -ENODEV)
goto exit;
result = asus_new_rfkill(asus, &asus->wwan3g, "asus-wwan3g",
RFKILL_TYPE_WWAN, ASUS_WMI_DEVID_WWAN3G);
if (result && result != -ENODEV)
goto exit;
result = asus_new_rfkill(asus, &asus->gps, "asus-gps",
RFKILL_TYPE_GPS, ASUS_WMI_DEVID_GPS);
if (result && result != -ENODEV)
goto exit;
result = asus_new_rfkill(asus, &asus->uwb, "asus-uwb",
RFKILL_TYPE_UWB, ASUS_WMI_DEVID_UWB);
if (result && result != -ENODEV)
goto exit;
if (!asus->driver->quirks->hotplug_wireless)
goto exit;
result = asus_setup_pci_hotplug(asus);
if (result == -EBUSY)
result = 0;
asus_register_rfkill_notifier(asus, "\\_SB.PCI0.P0P5");
asus_register_rfkill_notifier(asus, "\\_SB.PCI0.P0P6");
asus_register_rfkill_notifier(asus, "\\_SB.PCI0.P0P7");
asus_rfkill_hotplug(asus);
exit:
if (result && result != -ENODEV)
asus_wmi_rfkill_exit(asus);
if (result == -ENODEV)
result = 0;
return result;
}
static ssize_t asus_hwmon_pwm1(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct asus_wmi *asus = dev_get_drvdata(dev);
u32 value;
int err;
err = asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_FAN_CTRL, &value);
if (err < 0)
return err;
value &= 0xFF;
if (value == 1)
value = 85;
else if (value == 2)
value = 170;
else if (value == 3)
value = 255;
else if (value != 0) {
pr_err("Unknown fan speed %#x\n", value);
value = -1;
}
return sprintf(buf, "%d\n", value);
}
static ssize_t asus_hwmon_temp1(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct asus_wmi *asus = dev_get_drvdata(dev);
u32 value;
int err;
err = asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_THERMAL_CTRL, &value);
if (err < 0)
return err;
value = KELVIN_TO_CELSIUS((value & 0xFFFF)) * 1000;
return sprintf(buf, "%d\n", value);
}
static umode_t asus_hwmon_sysfs_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev->parent);
struct asus_wmi *asus = platform_get_drvdata(pdev);
bool ok = true;
int dev_id = -1;
u32 value = ASUS_WMI_UNSUPPORTED_METHOD;
if (attr == &dev_attr_pwm1.attr)
dev_id = ASUS_WMI_DEVID_FAN_CTRL;
else if (attr == &dev_attr_temp1_input.attr)
dev_id = ASUS_WMI_DEVID_THERMAL_CTRL;
if (dev_id != -1) {
int err = asus_wmi_get_devstate(asus, dev_id, &value);
if (err < 0)
return 0;
}
if (dev_id == ASUS_WMI_DEVID_FAN_CTRL) {
if (value == ASUS_WMI_UNSUPPORTED_METHOD || value & 0xFFF80000
|| (!asus->sfun && !(value & ASUS_WMI_DSTS_PRESENCE_BIT)))
ok = false;
} else if (dev_id == ASUS_WMI_DEVID_THERMAL_CTRL) {
if (value == 0)
ok = false;
}
return ok ? attr->mode : 0;
}
static int asus_wmi_hwmon_init(struct asus_wmi *asus)
{
struct device *hwmon;
hwmon = hwmon_device_register_with_groups(&asus->platform_device->dev,
"asus", asus,
hwmon_attribute_groups);
if (IS_ERR(hwmon)) {
pr_err("Could not register asus hwmon device\n");
return PTR_ERR(hwmon);
}
return 0;
}
static int read_backlight_power(struct asus_wmi *asus)
{
int ret;
if (asus->driver->quirks->store_backlight_power)
ret = !asus->driver->panel_power;
else
ret = asus_wmi_get_devstate_simple(asus,
ASUS_WMI_DEVID_BACKLIGHT);
if (ret < 0)
return ret;
return ret ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
}
static int read_brightness_max(struct asus_wmi *asus)
{
u32 retval;
int err;
err = asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_BRIGHTNESS, &retval);
if (err < 0)
return err;
retval = retval & ASUS_WMI_DSTS_MAX_BRIGTH_MASK;
retval >>= 8;
if (!retval)
return -ENODEV;
return retval;
}
static int read_brightness(struct backlight_device *bd)
{
struct asus_wmi *asus = bl_get_data(bd);
u32 retval;
int err;
err = asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_BRIGHTNESS, &retval);
if (err < 0)
return err;
return retval & ASUS_WMI_DSTS_BRIGHTNESS_MASK;
}
static u32 get_scalar_command(struct backlight_device *bd)
{
struct asus_wmi *asus = bl_get_data(bd);
u32 ctrl_param = 0;
if ((asus->driver->brightness < bd->props.brightness) ||
bd->props.brightness == bd->props.max_brightness)
ctrl_param = 0x00008001;
else if ((asus->driver->brightness > bd->props.brightness) ||
bd->props.brightness == 0)
ctrl_param = 0x00008000;
asus->driver->brightness = bd->props.brightness;
return ctrl_param;
}
static int update_bl_status(struct backlight_device *bd)
{
struct asus_wmi *asus = bl_get_data(bd);
u32 ctrl_param;
int power, err = 0;
power = read_backlight_power(asus);
if (power != -ENODEV && bd->props.power != power) {
ctrl_param = !!(bd->props.power == FB_BLANK_UNBLANK);
err = asus_wmi_set_devstate(ASUS_WMI_DEVID_BACKLIGHT,
ctrl_param, NULL);
if (asus->driver->quirks->store_backlight_power)
asus->driver->panel_power = bd->props.power;
if (asus->driver->quirks->scalar_panel_brightness)
return err;
}
if (asus->driver->quirks->scalar_panel_brightness)
ctrl_param = get_scalar_command(bd);
else
ctrl_param = bd->props.brightness;
err = asus_wmi_set_devstate(ASUS_WMI_DEVID_BRIGHTNESS,
ctrl_param, NULL);
return err;
}
static int asus_wmi_backlight_notify(struct asus_wmi *asus, int code)
{
struct backlight_device *bd = asus->backlight_device;
int old = bd->props.brightness;
int new = old;
if (code >= NOTIFY_BRNUP_MIN && code <= NOTIFY_BRNUP_MAX)
new = code - NOTIFY_BRNUP_MIN + 1;
else if (code >= NOTIFY_BRNDOWN_MIN && code <= NOTIFY_BRNDOWN_MAX)
new = code - NOTIFY_BRNDOWN_MIN;
bd->props.brightness = new;
backlight_update_status(bd);
backlight_force_update(bd, BACKLIGHT_UPDATE_HOTKEY);
return old;
}
static int asus_wmi_backlight_init(struct asus_wmi *asus)
{
struct backlight_device *bd;
struct backlight_properties props;
int max;
int power;
max = read_brightness_max(asus);
if (max < 0)
return max;
power = read_backlight_power(asus);
if (power == -ENODEV)
power = FB_BLANK_UNBLANK;
else if (power < 0)
return power;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = max;
bd = backlight_device_register(asus->driver->name,
&asus->platform_device->dev, asus,
&asus_wmi_bl_ops, &props);
if (IS_ERR(bd)) {
pr_err("Could not register backlight device\n");
return PTR_ERR(bd);
}
asus->backlight_device = bd;
if (asus->driver->quirks->store_backlight_power)
asus->driver->panel_power = power;
bd->props.brightness = read_brightness(bd);
bd->props.power = power;
backlight_update_status(bd);
asus->driver->brightness = bd->props.brightness;
return 0;
}
static void asus_wmi_backlight_exit(struct asus_wmi *asus)
{
if (asus->backlight_device)
backlight_device_unregister(asus->backlight_device);
asus->backlight_device = NULL;
}
static int is_display_toggle(int code)
{
if ((code >= 0x61 && code <= 0x67) ||
(code >= 0x8c && code <= 0x93) ||
(code >= 0xa0 && code <= 0xa7) ||
(code >= 0xd0 && code <= 0xd5))
return 1;
return 0;
}
static void asus_wmi_notify(u32 value, void *context)
{
struct asus_wmi *asus = context;
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
int code;
int orig_code;
unsigned int key_value = 1;
bool autorelease = 1;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_err("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (!obj || obj->type != ACPI_TYPE_INTEGER)
goto exit;
code = obj->integer.value;
orig_code = code;
if (asus->driver->key_filter) {
asus->driver->key_filter(asus->driver, &code, &key_value,
&autorelease);
if (code == ASUS_WMI_KEY_IGNORE)
goto exit;
}
if (code >= NOTIFY_BRNUP_MIN && code <= NOTIFY_BRNUP_MAX)
code = ASUS_WMI_BRN_UP;
else if (code >= NOTIFY_BRNDOWN_MIN &&
code <= NOTIFY_BRNDOWN_MAX)
code = ASUS_WMI_BRN_DOWN;
if (code == ASUS_WMI_BRN_DOWN || code == ASUS_WMI_BRN_UP) {
if (!acpi_video_backlight_support()) {
asus_wmi_backlight_notify(asus, orig_code);
goto exit;
}
}
if (is_display_toggle(code) &&
asus->driver->quirks->no_display_toggle)
goto exit;
if (!sparse_keymap_report_event(asus->inputdev, code,
key_value, autorelease))
pr_info("Unknown key %x pressed\n", code);
exit:
kfree(obj);
}
static int parse_arg(const char *buf, unsigned long count, int *val)
{
if (!count)
return 0;
if (sscanf(buf, "%i", val) != 1)
return -EINVAL;
return count;
}
static ssize_t store_sys_wmi(struct asus_wmi *asus, int devid,
const char *buf, size_t count)
{
u32 retval;
int rv, err, value;
value = asus_wmi_get_devstate_simple(asus, devid);
if (value == -ENODEV)
return value;
rv = parse_arg(buf, count, &value);
err = asus_wmi_set_devstate(devid, value, &retval);
if (err < 0)
return err;
return rv;
}
static ssize_t show_sys_wmi(struct asus_wmi *asus, int devid, char *buf)
{
int value = asus_wmi_get_devstate_simple(asus, devid);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t store_cpufv(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int value, rv;
if (!count || sscanf(buf, "%i", &value) != 1)
return -EINVAL;
if (value < 0 || value > 2)
return -EINVAL;
rv = asus_wmi_evaluate_method(ASUS_WMI_METHODID_CFVS, value, 0, NULL);
if (rv < 0)
return rv;
return count;
}
static umode_t asus_sysfs_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev);
struct asus_wmi *asus = platform_get_drvdata(pdev);
bool ok = true;
int devid = -1;
if (attr == &dev_attr_camera.attr)
devid = ASUS_WMI_DEVID_CAMERA;
else if (attr == &dev_attr_cardr.attr)
devid = ASUS_WMI_DEVID_CARDREADER;
else if (attr == &dev_attr_touchpad.attr)
devid = ASUS_WMI_DEVID_TOUCHPAD;
else if (attr == &dev_attr_lid_resume.attr)
devid = ASUS_WMI_DEVID_LID_RESUME;
if (devid != -1)
ok = !(asus_wmi_get_devstate_simple(asus, devid) < 0);
return ok ? attr->mode : 0;
}
static void asus_wmi_sysfs_exit(struct platform_device *device)
{
sysfs_remove_group(&device->dev.kobj, &platform_attribute_group);
}
static int asus_wmi_sysfs_init(struct platform_device *device)
{
return sysfs_create_group(&device->dev.kobj, &platform_attribute_group);
}
static int asus_wmi_platform_init(struct asus_wmi *asus)
{
int rv;
if (!asus_wmi_evaluate_method(ASUS_WMI_METHODID_INIT, 0, 0, &rv))
pr_info("Initialization: %#x\n", rv);
if (!asus_wmi_evaluate_method(ASUS_WMI_METHODID_SPEC, 0, 0x9, &rv)) {
pr_info("BIOS WMI version: %d.%d\n", rv >> 16, rv & 0xFF);
asus->spec = rv;
}
if (!asus_wmi_evaluate_method(ASUS_WMI_METHODID_SFUN, 0, 0, &rv)) {
pr_info("SFUN value: %#x\n", rv);
asus->sfun = rv;
}
if (!asus_wmi_evaluate_method(ASUS_WMI_METHODID_DSTS, 0, 0, NULL))
asus->dsts_id = ASUS_WMI_METHODID_DSTS;
else
asus->dsts_id = ASUS_WMI_METHODID_DSTS2;
if (asus->driver->quirks->wapf >= 0)
asus_wmi_set_devstate(ASUS_WMI_DEVID_CWAP,
asus->driver->quirks->wapf, NULL);
return asus_wmi_sysfs_init(asus->platform_device);
}
static void asus_wmi_platform_exit(struct asus_wmi *asus)
{
asus_wmi_sysfs_exit(asus->platform_device);
}
static int show_dsts(struct seq_file *m, void *data)
{
struct asus_wmi *asus = m->private;
int err;
u32 retval = -1;
err = asus_wmi_get_devstate(asus, asus->debug.dev_id, &retval);
if (err < 0)
return err;
seq_printf(m, "DSTS(%#x) = %#x\n", asus->debug.dev_id, retval);
return 0;
}
static int show_devs(struct seq_file *m, void *data)
{
struct asus_wmi *asus = m->private;
int err;
u32 retval = -1;
err = asus_wmi_set_devstate(asus->debug.dev_id, asus->debug.ctrl_param,
&retval);
if (err < 0)
return err;
seq_printf(m, "DEVS(%#x, %#x) = %#x\n", asus->debug.dev_id,
asus->debug.ctrl_param, retval);
return 0;
}
static int show_call(struct seq_file *m, void *data)
{
struct asus_wmi *asus = m->private;
struct bios_args args = {
.arg0 = asus->debug.dev_id,
.arg1 = asus->debug.ctrl_param,
};
struct acpi_buffer input = { (acpi_size) sizeof(args), &args };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
status = wmi_evaluate_method(ASUS_WMI_MGMT_GUID,
1, asus->debug.method_id,
&input, &output);
if (ACPI_FAILURE(status))
return -EIO;
obj = (union acpi_object *)output.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER)
seq_printf(m, "%#x(%#x, %#x) = %#x\n", asus->debug.method_id,
asus->debug.dev_id, asus->debug.ctrl_param,
(u32) obj->integer.value);
else
seq_printf(m, "%#x(%#x, %#x) = t:%d\n", asus->debug.method_id,
asus->debug.dev_id, asus->debug.ctrl_param,
obj ? obj->type : -1);
kfree(obj);
return 0;
}
static int asus_wmi_debugfs_open(struct inode *inode, struct file *file)
{
struct asus_wmi_debugfs_node *node = inode->i_private;
return single_open(file, node->show, node->asus);
}
static void asus_wmi_debugfs_exit(struct asus_wmi *asus)
{
debugfs_remove_recursive(asus->debug.root);
}
static int asus_wmi_debugfs_init(struct asus_wmi *asus)
{
struct dentry *dent;
int i;
asus->debug.root = debugfs_create_dir(asus->driver->name, NULL);
if (!asus->debug.root) {
pr_err("failed to create debugfs directory\n");
goto error_debugfs;
}
dent = debugfs_create_x32("method_id", S_IRUGO | S_IWUSR,
asus->debug.root, &asus->debug.method_id);
if (!dent)
goto error_debugfs;
dent = debugfs_create_x32("dev_id", S_IRUGO | S_IWUSR,
asus->debug.root, &asus->debug.dev_id);
if (!dent)
goto error_debugfs;
dent = debugfs_create_x32("ctrl_param", S_IRUGO | S_IWUSR,
asus->debug.root, &asus->debug.ctrl_param);
if (!dent)
goto error_debugfs;
for (i = 0; i < ARRAY_SIZE(asus_wmi_debug_files); i++) {
struct asus_wmi_debugfs_node *node = &asus_wmi_debug_files[i];
node->asus = asus;
dent = debugfs_create_file(node->name, S_IFREG | S_IRUGO,
asus->debug.root, node,
&asus_wmi_debugfs_io_ops);
if (!dent) {
pr_err("failed to create debug file: %s\n", node->name);
goto error_debugfs;
}
}
return 0;
error_debugfs:
asus_wmi_debugfs_exit(asus);
return -ENOMEM;
}
static int asus_wmi_add(struct platform_device *pdev)
{
struct platform_driver *pdrv = to_platform_driver(pdev->dev.driver);
struct asus_wmi_driver *wdrv = to_asus_wmi_driver(pdrv);
struct asus_wmi *asus;
const char *chassis_type;
acpi_status status;
int err;
u32 result;
asus = kzalloc(sizeof(struct asus_wmi), GFP_KERNEL);
if (!asus)
return -ENOMEM;
asus->driver = wdrv;
asus->platform_device = pdev;
wdrv->platform_device = pdev;
platform_set_drvdata(asus->platform_device, asus);
if (wdrv->detect_quirks)
wdrv->detect_quirks(asus->driver);
err = asus_wmi_platform_init(asus);
if (err)
goto fail_platform;
err = asus_wmi_input_init(asus);
if (err)
goto fail_input;
err = asus_wmi_hwmon_init(asus);
if (err)
goto fail_hwmon;
err = asus_wmi_led_init(asus);
if (err)
goto fail_leds;
err = asus_wmi_rfkill_init(asus);
if (err)
goto fail_rfkill;
chassis_type = dmi_get_system_info(DMI_CHASSIS_TYPE);
if (chassis_type && !strcmp(chassis_type, "3"))
acpi_video_dmi_promote_vendor();
if (asus->driver->quirks->wmi_backlight_power)
acpi_video_dmi_promote_vendor();
if (!acpi_video_backlight_support()) {
pr_info("Disabling ACPI video driver\n");
acpi_video_unregister();
err = asus_wmi_backlight_init(asus);
if (err && err != -ENODEV)
goto fail_backlight;
} else
pr_info("Backlight controlled by ACPI video driver\n");
status = wmi_install_notify_handler(asus->driver->event_guid,
asus_wmi_notify, asus);
if (ACPI_FAILURE(status)) {
pr_err("Unable to register notify handler - %d\n", status);
err = -ENODEV;
goto fail_wmi_handler;
}
err = asus_wmi_debugfs_init(asus);
if (err)
goto fail_debugfs;
asus_wmi_get_devstate(asus, ASUS_WMI_DEVID_WLAN, &result);
if (result & (ASUS_WMI_DSTS_PRESENCE_BIT | ASUS_WMI_DSTS_USER_BIT))
asus->driver->wlan_ctrl_by_user = 1;
return 0;
fail_debugfs:
wmi_remove_notify_handler(asus->driver->event_guid);
fail_wmi_handler:
asus_wmi_backlight_exit(asus);
fail_backlight:
asus_wmi_rfkill_exit(asus);
fail_rfkill:
asus_wmi_led_exit(asus);
fail_leds:
fail_hwmon:
asus_wmi_input_exit(asus);
fail_input:
asus_wmi_platform_exit(asus);
fail_platform:
kfree(asus);
return err;
}
static int asus_wmi_remove(struct platform_device *device)
{
struct asus_wmi *asus;
asus = platform_get_drvdata(device);
wmi_remove_notify_handler(asus->driver->event_guid);
asus_wmi_backlight_exit(asus);
asus_wmi_input_exit(asus);
asus_wmi_led_exit(asus);
asus_wmi_rfkill_exit(asus);
asus_wmi_debugfs_exit(asus);
asus_wmi_platform_exit(asus);
kfree(asus);
return 0;
}
static int asus_hotk_thaw(struct device *device)
{
struct asus_wmi *asus = dev_get_drvdata(device);
if (asus->wlan.rfkill) {
bool wlan;
wlan = asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_WLAN);
asus_wmi_set_devstate(ASUS_WMI_DEVID_WLAN, wlan, NULL);
}
return 0;
}
static int asus_hotk_restore(struct device *device)
{
struct asus_wmi *asus = dev_get_drvdata(device);
int bl;
if (asus->wlan.rfkill)
asus_rfkill_hotplug(asus);
if (asus->bluetooth.rfkill) {
bl = !asus_wmi_get_devstate_simple(asus,
ASUS_WMI_DEVID_BLUETOOTH);
rfkill_set_sw_state(asus->bluetooth.rfkill, bl);
}
if (asus->wimax.rfkill) {
bl = !asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_WIMAX);
rfkill_set_sw_state(asus->wimax.rfkill, bl);
}
if (asus->wwan3g.rfkill) {
bl = !asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_WWAN3G);
rfkill_set_sw_state(asus->wwan3g.rfkill, bl);
}
if (asus->gps.rfkill) {
bl = !asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_GPS);
rfkill_set_sw_state(asus->gps.rfkill, bl);
}
if (asus->uwb.rfkill) {
bl = !asus_wmi_get_devstate_simple(asus, ASUS_WMI_DEVID_UWB);
rfkill_set_sw_state(asus->uwb.rfkill, bl);
}
return 0;
}
static int asus_wmi_probe(struct platform_device *pdev)
{
struct platform_driver *pdrv = to_platform_driver(pdev->dev.driver);
struct asus_wmi_driver *wdrv = to_asus_wmi_driver(pdrv);
int ret;
if (!wmi_has_guid(ASUS_WMI_MGMT_GUID)) {
pr_warn("Management GUID not found\n");
return -ENODEV;
}
if (wdrv->event_guid && !wmi_has_guid(wdrv->event_guid)) {
pr_warn("Event GUID not found\n");
return -ENODEV;
}
if (wdrv->probe) {
ret = wdrv->probe(pdev);
if (ret)
return ret;
}
return asus_wmi_add(pdev);
}
int __init_or_module asus_wmi_register_driver(struct asus_wmi_driver *driver)
{
struct platform_driver *platform_driver;
struct platform_device *platform_device;
if (used)
return -EBUSY;
platform_driver = &driver->platform_driver;
platform_driver->remove = asus_wmi_remove;
platform_driver->driver.owner = driver->owner;
platform_driver->driver.name = driver->name;
platform_driver->driver.pm = &asus_pm_ops;
platform_device = platform_create_bundle(platform_driver,
asus_wmi_probe,
NULL, 0, NULL, 0);
if (IS_ERR(platform_device))
return PTR_ERR(platform_device);
used = true;
return 0;
}
void asus_wmi_unregister_driver(struct asus_wmi_driver *driver)
{
platform_device_unregister(driver->platform_device);
platform_driver_unregister(&driver->platform_driver);
used = false;
}
static int __init asus_wmi_init(void)
{
if (!wmi_has_guid(ASUS_WMI_MGMT_GUID)) {
pr_info("Asus Management GUID not found\n");
return -ENODEV;
}
pr_info("ASUS WMI generic driver loaded\n");
return 0;
}
static void __exit asus_wmi_exit(void)
{
pr_info("ASUS WMI generic driver unloaded\n");
}
