static int hp_wmi_perform_query(int query, enum hp_wmi_command command,
void *buffer, int insize, int outsize)
{
struct bios_return *bios_return;
int actual_outsize;
union acpi_object *obj;
struct bios_args args = {
.signature = 0x55434553,
.command = command,
.commandtype = query,
.datasize = insize,
.data = 0,
};
struct acpi_buffer input = { sizeof(struct bios_args), &args };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
int ret = 0;
if (WARN_ON(insize > sizeof(args.data)))
return -EINVAL;
memcpy(&args.data, buffer, insize);
wmi_evaluate_method(HPWMI_BIOS_GUID, 0, 0x3, &input, &output);
obj = output.pointer;
if (!obj)
return -EINVAL;
if (obj->type != ACPI_TYPE_BUFFER) {
ret = -EINVAL;
goto out_free;
}
bios_return = (struct bios_return *)obj->buffer.pointer;
ret = bios_return->return_code;
if (ret) {
if (ret != HPWMI_RET_UNKNOWN_CMDTYPE)
pr_warn("query 0x%x returned error 0x%x\n", query, ret);
goto out_free;
}
if (!outsize)
goto out_free;
actual_outsize = min(outsize, (int)(obj->buffer.length - sizeof(*bios_return)));
memcpy(buffer, obj->buffer.pointer + sizeof(*bios_return), actual_outsize);
memset(buffer + actual_outsize, 0, outsize - actual_outsize);
out_free:
kfree(obj);
return ret;
}
static int hp_wmi_read_int(int query)
{
int val = 0, ret;
ret = hp_wmi_perform_query(query, HPWMI_READ, &val,
sizeof(val), sizeof(val));
if (ret)
return ret < 0 ? ret : -EINVAL;
return val;
}
static int hp_wmi_hw_state(int mask)
{
int state = hp_wmi_read_int(HPWMI_HARDWARE_QUERY);
if (state < 0)
return state;
return state & 0x1;
}
static int __init hp_wmi_bios_2008_later(void)
{
int state = 0;
int ret = hp_wmi_perform_query(HPWMI_FEATURE_QUERY, HPWMI_READ, &state,
sizeof(state), sizeof(state));
if (!ret)
return 1;
return (ret == HPWMI_RET_UNKNOWN_CMDTYPE) ? 0 : -ENXIO;
}
static int __init hp_wmi_bios_2009_later(void)
{
int state = 0;
int ret = hp_wmi_perform_query(HPWMI_FEATURE2_QUERY, HPWMI_READ, &state,
sizeof(state), sizeof(state));
if (!ret)
return 1;
return (ret == HPWMI_RET_UNKNOWN_CMDTYPE) ? 0 : -ENXIO;
}
static int __init hp_wmi_enable_hotkeys(void)
{
int value = 0x6e;
int ret = hp_wmi_perform_query(HPWMI_BIOS_QUERY, HPWMI_WRITE, &value,
sizeof(value), 0);
return ret <= 0 ? ret : -EINVAL;
}
static int hp_wmi_set_block(void *data, bool blocked)
{
enum hp_wmi_radio r = (enum hp_wmi_radio) data;
int query = BIT(r + 8) | ((!blocked) << r);
int ret;
ret = hp_wmi_perform_query(HPWMI_WIRELESS_QUERY, HPWMI_WRITE,
&query, sizeof(query), 0);
return ret <= 0 ? ret : -EINVAL;
}
static bool hp_wmi_get_sw_state(enum hp_wmi_radio r)
{
int mask = 0x200 << (r * 8);
int wireless = hp_wmi_read_int(HPWMI_WIRELESS_QUERY);
WARN_ONCE(wireless < 0, "error executing HPWMI_WIRELESS_QUERY");
return !(wireless & mask);
}
static bool hp_wmi_get_hw_state(enum hp_wmi_radio r)
{
int mask = 0x800 << (r * 8);
int wireless = hp_wmi_read_int(HPWMI_WIRELESS_QUERY);
WARN_ONCE(wireless < 0, "error executing HPWMI_WIRELESS_QUERY");
return !(wireless & mask);
}
static int hp_wmi_rfkill2_set_block(void *data, bool blocked)
{
int rfkill_id = (int)(long)data;
char buffer[4] = { 0x01, 0x00, rfkill_id, !blocked };
int ret;
ret = hp_wmi_perform_query(HPWMI_WIRELESS2_QUERY, HPWMI_WRITE,
buffer, sizeof(buffer), 0);
return ret <= 0 ? ret : -EINVAL;
}
static int hp_wmi_rfkill2_refresh(void)
{
struct bios_rfkill2_state state;
int err, i;
err = hp_wmi_perform_query(HPWMI_WIRELESS2_QUERY, HPWMI_READ, &state,
0, sizeof(state));
if (err)
return err;
for (i = 0; i < rfkill2_count; i++) {
int num = rfkill2[i].num;
struct bios_rfkill2_device_state *devstate;
devstate = &state.device[num];
if (num >= state.count ||
devstate->rfkill_id != rfkill2[i].id) {
pr_warn("power configuration of the wireless devices unexpectedly changed\n");
continue;
}
rfkill_set_states(rfkill2[i].rfkill,
IS_SWBLOCKED(devstate->power),
IS_HWBLOCKED(devstate->power));
}
return 0;
}
static ssize_t display_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_read_int(HPWMI_DISPLAY_QUERY);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t hddtemp_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_read_int(HPWMI_HDDTEMP_QUERY);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t als_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_read_int(HPWMI_ALS_QUERY);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t dock_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_hw_state(HPWMI_DOCK_MASK);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t tablet_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_hw_state(HPWMI_TABLET_MASK);
if (value < 0)
return value;
return sprintf(buf, "%d\n", value);
}
static ssize_t postcode_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int value = hp_wmi_read_int(HPWMI_POSTCODEERROR_QUERY);
if (value < 0)
return value;
return sprintf(buf, "0x%x\n", value);
}
static ssize_t als_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 tmp = simple_strtoul(buf, NULL, 10);
int ret = hp_wmi_perform_query(HPWMI_ALS_QUERY, HPWMI_WRITE, &tmp,
sizeof(tmp), sizeof(tmp));
if (ret)
return ret < 0 ? ret : -EINVAL;
return count;
}
static ssize_t postcode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
long unsigned int tmp2;
int ret;
u32 tmp;
ret = kstrtoul(buf, 10, &tmp2);
if (!ret && tmp2 != 1)
ret = -EINVAL;
if (ret)
goto out;
tmp = (u32) tmp2;
ret = hp_wmi_perform_query(HPWMI_POSTCODEERROR_QUERY, HPWMI_WRITE, &tmp,
sizeof(tmp), sizeof(tmp));
out:
if (ret)
return ret < 0 ? ret : -EINVAL;
return count;
}
static void hp_wmi_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
u32 event_id, event_data;
union acpi_object *obj;
acpi_status status;
u32 *location;
int key_code;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_info("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (!obj)
return;
if (obj->type != ACPI_TYPE_BUFFER) {
pr_info("Unknown response received %d\n", obj->type);
kfree(obj);
return;
}
location = (u32 *)obj->buffer.pointer;
if (obj->buffer.length == 8) {
event_id = *location;
event_data = *(location + 1);
} else if (obj->buffer.length == 16) {
event_id = *location;
event_data = *(location + 2);
} else {
pr_info("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return;
}
kfree(obj);
switch (event_id) {
case HPWMI_DOCK_EVENT:
if (test_bit(SW_DOCK, hp_wmi_input_dev->swbit))
input_report_switch(hp_wmi_input_dev, SW_DOCK,
hp_wmi_hw_state(HPWMI_DOCK_MASK));
if (test_bit(SW_TABLET_MODE, hp_wmi_input_dev->swbit))
input_report_switch(hp_wmi_input_dev, SW_TABLET_MODE,
hp_wmi_hw_state(HPWMI_TABLET_MASK));
input_sync(hp_wmi_input_dev);
break;
case HPWMI_PARK_HDD:
break;
case HPWMI_SMART_ADAPTER:
break;
case HPWMI_BEZEL_BUTTON:
key_code = hp_wmi_read_int(HPWMI_HOTKEY_QUERY);
if (key_code < 0)
break;
if (!sparse_keymap_report_event(hp_wmi_input_dev,
key_code, 1, true))
pr_info("Unknown key code - 0x%x\n", key_code);
break;
case HPWMI_WIRELESS:
if (rfkill2_count) {
hp_wmi_rfkill2_refresh();
break;
}
if (wifi_rfkill)
rfkill_set_states(wifi_rfkill,
hp_wmi_get_sw_state(HPWMI_WIFI),
hp_wmi_get_hw_state(HPWMI_WIFI));
if (bluetooth_rfkill)
rfkill_set_states(bluetooth_rfkill,
hp_wmi_get_sw_state(HPWMI_BLUETOOTH),
hp_wmi_get_hw_state(HPWMI_BLUETOOTH));
if (wwan_rfkill)
rfkill_set_states(wwan_rfkill,
hp_wmi_get_sw_state(HPWMI_WWAN),
hp_wmi_get_hw_state(HPWMI_WWAN));
break;
case HPWMI_CPU_BATTERY_THROTTLE:
pr_info("Unimplemented CPU throttle because of 3 Cell battery event detected\n");
break;
case HPWMI_LOCK_SWITCH:
break;
case HPWMI_LID_SWITCH:
break;
case HPWMI_SCREEN_ROTATION:
break;
case HPWMI_COOLSENSE_SYSTEM_MOBILE:
break;
case HPWMI_COOLSENSE_SYSTEM_HOT:
break;
case HPWMI_PROXIMITY_SENSOR:
break;
case HPWMI_BACKLIT_KB_BRIGHTNESS:
break;
case HPWMI_PEAKSHIFT_PERIOD:
break;
case HPWMI_BATTERY_CHARGE_PERIOD:
break;
default:
pr_info("Unknown event_id - %d - 0x%x\n", event_id, event_data);
break;
}
}
static int __init hp_wmi_input_setup(void)
{
acpi_status status;
int err, val;
hp_wmi_input_dev = input_allocate_device();
if (!hp_wmi_input_dev)
return -ENOMEM;
hp_wmi_input_dev->name = "HP WMI hotkeys";
hp_wmi_input_dev->phys = "wmi/input0";
hp_wmi_input_dev->id.bustype = BUS_HOST;
__set_bit(EV_SW, hp_wmi_input_dev->evbit);
val = hp_wmi_hw_state(HPWMI_DOCK_MASK);
if (!(val < 0)) {
__set_bit(SW_DOCK, hp_wmi_input_dev->swbit);
input_report_switch(hp_wmi_input_dev, SW_DOCK, val);
}
val = hp_wmi_hw_state(HPWMI_TABLET_MASK);
if (!(val < 0)) {
__set_bit(SW_TABLET_MODE, hp_wmi_input_dev->swbit);
input_report_switch(hp_wmi_input_dev, SW_TABLET_MODE, val);
}
err = sparse_keymap_setup(hp_wmi_input_dev, hp_wmi_keymap, NULL);
if (err)
goto err_free_dev;
input_sync(hp_wmi_input_dev);
if (!hp_wmi_bios_2009_later() && hp_wmi_bios_2008_later())
hp_wmi_enable_hotkeys();
status = wmi_install_notify_handler(HPWMI_EVENT_GUID, hp_wmi_notify, NULL);
if (ACPI_FAILURE(status)) {
err = -EIO;
goto err_free_dev;
}
err = input_register_device(hp_wmi_input_dev);
if (err)
goto err_uninstall_notifier;
return 0;
err_uninstall_notifier:
wmi_remove_notify_handler(HPWMI_EVENT_GUID);
err_free_dev:
input_free_device(hp_wmi_input_dev);
return err;
}
static void hp_wmi_input_destroy(void)
{
wmi_remove_notify_handler(HPWMI_EVENT_GUID);
input_unregister_device(hp_wmi_input_dev);
}
static void cleanup_sysfs(struct platform_device *device)
{
device_remove_file(&device->dev, &dev_attr_display);
device_remove_file(&device->dev, &dev_attr_hddtemp);
device_remove_file(&device->dev, &dev_attr_als);
device_remove_file(&device->dev, &dev_attr_dock);
device_remove_file(&device->dev, &dev_attr_tablet);
device_remove_file(&device->dev, &dev_attr_postcode);
}
static int __init hp_wmi_rfkill_setup(struct platform_device *device)
{
int err, wireless;
wireless = hp_wmi_read_int(HPWMI_WIRELESS_QUERY);
if (wireless < 0)
return wireless;
err = hp_wmi_perform_query(HPWMI_WIRELESS_QUERY, HPWMI_WRITE, &wireless,
sizeof(wireless), 0);
if (err)
return err;
if (wireless & 0x1) {
wifi_rfkill = rfkill_alloc("hp-wifi", &device->dev,
RFKILL_TYPE_WLAN,
&hp_wmi_rfkill_ops,
(void *) HPWMI_WIFI);
if (!wifi_rfkill)
return -ENOMEM;
rfkill_init_sw_state(wifi_rfkill,
hp_wmi_get_sw_state(HPWMI_WIFI));
rfkill_set_hw_state(wifi_rfkill,
hp_wmi_get_hw_state(HPWMI_WIFI));
err = rfkill_register(wifi_rfkill);
if (err)
goto register_wifi_error;
}
if (wireless & 0x2) {
bluetooth_rfkill = rfkill_alloc("hp-bluetooth", &device->dev,
RFKILL_TYPE_BLUETOOTH,
&hp_wmi_rfkill_ops,
(void *) HPWMI_BLUETOOTH);
if (!bluetooth_rfkill) {
err = -ENOMEM;
goto register_bluetooth_error;
}
rfkill_init_sw_state(bluetooth_rfkill,
hp_wmi_get_sw_state(HPWMI_BLUETOOTH));
rfkill_set_hw_state(bluetooth_rfkill,
hp_wmi_get_hw_state(HPWMI_BLUETOOTH));
err = rfkill_register(bluetooth_rfkill);
if (err)
goto register_bluetooth_error;
}
if (wireless & 0x4) {
wwan_rfkill = rfkill_alloc("hp-wwan", &device->dev,
RFKILL_TYPE_WWAN,
&hp_wmi_rfkill_ops,
(void *) HPWMI_WWAN);
if (!wwan_rfkill) {
err = -ENOMEM;
goto register_wwan_error;
}
rfkill_init_sw_state(wwan_rfkill,
hp_wmi_get_sw_state(HPWMI_WWAN));
rfkill_set_hw_state(wwan_rfkill,
hp_wmi_get_hw_state(HPWMI_WWAN));
err = rfkill_register(wwan_rfkill);
if (err)
goto register_wwan_error;
}
return 0;
register_wwan_error:
rfkill_destroy(wwan_rfkill);
wwan_rfkill = NULL;
if (bluetooth_rfkill)
rfkill_unregister(bluetooth_rfkill);
register_bluetooth_error:
rfkill_destroy(bluetooth_rfkill);
bluetooth_rfkill = NULL;
if (wifi_rfkill)
rfkill_unregister(wifi_rfkill);
register_wifi_error:
rfkill_destroy(wifi_rfkill);
wifi_rfkill = NULL;
return err;
}
static int __init hp_wmi_rfkill2_setup(struct platform_device *device)
{
struct bios_rfkill2_state state;
int err, i;
err = hp_wmi_perform_query(HPWMI_WIRELESS2_QUERY, HPWMI_READ, &state,
0, sizeof(state));
if (err)
return err < 0 ? err : -EINVAL;
if (state.count > HPWMI_MAX_RFKILL2_DEVICES) {
pr_warn("unable to parse 0x1b query output\n");
return -EINVAL;
}
for (i = 0; i < state.count; i++) {
struct rfkill *rfkill;
enum rfkill_type type;
char *name;
switch (state.device[i].radio_type) {
case HPWMI_WIFI:
type = RFKILL_TYPE_WLAN;
name = "hp-wifi";
break;
case HPWMI_BLUETOOTH:
type = RFKILL_TYPE_BLUETOOTH;
name = "hp-bluetooth";
break;
case HPWMI_WWAN:
type = RFKILL_TYPE_WWAN;
name = "hp-wwan";
break;
case HPWMI_GPS:
type = RFKILL_TYPE_GPS;
name = "hp-gps";
break;
default:
pr_warn("unknown device type 0x%x\n",
state.device[i].radio_type);
continue;
}
if (!state.device[i].vendor_id) {
pr_warn("zero device %d while %d reported\n",
i, state.count);
continue;
}
rfkill = rfkill_alloc(name, &device->dev, type,
&hp_wmi_rfkill2_ops, (void *)(long)i);
if (!rfkill) {
err = -ENOMEM;
goto fail;
}
rfkill2[rfkill2_count].id = state.device[i].rfkill_id;
rfkill2[rfkill2_count].num = i;
rfkill2[rfkill2_count].rfkill = rfkill;
rfkill_init_sw_state(rfkill,
IS_SWBLOCKED(state.device[i].power));
rfkill_set_hw_state(rfkill,
IS_HWBLOCKED(state.device[i].power));
if (!(state.device[i].power & HPWMI_POWER_BIOS))
pr_info("device %s blocked by BIOS\n", name);
err = rfkill_register(rfkill);
if (err) {
rfkill_destroy(rfkill);
goto fail;
}
rfkill2_count++;
}
return 0;
fail:
for (; rfkill2_count > 0; rfkill2_count--) {
rfkill_unregister(rfkill2[rfkill2_count - 1].rfkill);
rfkill_destroy(rfkill2[rfkill2_count - 1].rfkill);
}
return err;
}
static int __init hp_wmi_bios_setup(struct platform_device *device)
{
int err;
wifi_rfkill = NULL;
bluetooth_rfkill = NULL;
wwan_rfkill = NULL;
rfkill2_count = 0;
if (hp_wmi_rfkill_setup(device))
hp_wmi_rfkill2_setup(device);
err = device_create_file(&device->dev, &dev_attr_display);
if (err)
goto add_sysfs_error;
err = device_create_file(&device->dev, &dev_attr_hddtemp);
if (err)
goto add_sysfs_error;
err = device_create_file(&device->dev, &dev_attr_als);
if (err)
goto add_sysfs_error;
err = device_create_file(&device->dev, &dev_attr_dock);
if (err)
goto add_sysfs_error;
err = device_create_file(&device->dev, &dev_attr_tablet);
if (err)
goto add_sysfs_error;
err = device_create_file(&device->dev, &dev_attr_postcode);
if (err)
goto add_sysfs_error;
return 0;
add_sysfs_error:
cleanup_sysfs(device);
return err;
}
static int __exit hp_wmi_bios_remove(struct platform_device *device)
{
int i;
cleanup_sysfs(device);
for (i = 0; i < rfkill2_count; i++) {
rfkill_unregister(rfkill2[i].rfkill);
rfkill_destroy(rfkill2[i].rfkill);
}
if (wifi_rfkill) {
rfkill_unregister(wifi_rfkill);
rfkill_destroy(wifi_rfkill);
}
if (bluetooth_rfkill) {
rfkill_unregister(bluetooth_rfkill);
rfkill_destroy(bluetooth_rfkill);
}
if (wwan_rfkill) {
rfkill_unregister(wwan_rfkill);
rfkill_destroy(wwan_rfkill);
}
return 0;
}
static int hp_wmi_resume_handler(struct device *device)
{
if (hp_wmi_input_dev) {
if (test_bit(SW_DOCK, hp_wmi_input_dev->swbit))
input_report_switch(hp_wmi_input_dev, SW_DOCK,
hp_wmi_hw_state(HPWMI_DOCK_MASK));
if (test_bit(SW_TABLET_MODE, hp_wmi_input_dev->swbit))
input_report_switch(hp_wmi_input_dev, SW_TABLET_MODE,
hp_wmi_hw_state(HPWMI_TABLET_MASK));
input_sync(hp_wmi_input_dev);
}
if (rfkill2_count)
hp_wmi_rfkill2_refresh();
if (wifi_rfkill)
rfkill_set_states(wifi_rfkill,
hp_wmi_get_sw_state(HPWMI_WIFI),
hp_wmi_get_hw_state(HPWMI_WIFI));
if (bluetooth_rfkill)
rfkill_set_states(bluetooth_rfkill,
hp_wmi_get_sw_state(HPWMI_BLUETOOTH),
hp_wmi_get_hw_state(HPWMI_BLUETOOTH));
if (wwan_rfkill)
rfkill_set_states(wwan_rfkill,
hp_wmi_get_sw_state(HPWMI_WWAN),
hp_wmi_get_hw_state(HPWMI_WWAN));
return 0;
}
static int __init hp_wmi_init(void)
{
int event_capable = wmi_has_guid(HPWMI_EVENT_GUID);
int bios_capable = wmi_has_guid(HPWMI_BIOS_GUID);
int err;
if (!bios_capable && !event_capable)
return -ENODEV;
if (event_capable) {
err = hp_wmi_input_setup();
if (err)
return err;
}
if (bios_capable) {
hp_wmi_platform_dev =
platform_device_register_simple("hp-wmi", -1, NULL, 0);
if (IS_ERR(hp_wmi_platform_dev)) {
err = PTR_ERR(hp_wmi_platform_dev);
goto err_destroy_input;
}
err = platform_driver_probe(&hp_wmi_driver, hp_wmi_bios_setup);
if (err)
goto err_unregister_device;
}
return 0;
err_unregister_device:
platform_device_unregister(hp_wmi_platform_dev);
err_destroy_input:
if (event_capable)
hp_wmi_input_destroy();
return err;
}
static void __exit hp_wmi_exit(void)
{
if (wmi_has_guid(HPWMI_EVENT_GUID))
hp_wmi_input_destroy();
if (hp_wmi_platform_dev) {
platform_device_unregister(hp_wmi_platform_dev);
platform_driver_unregister(&hp_wmi_driver);
}
}
