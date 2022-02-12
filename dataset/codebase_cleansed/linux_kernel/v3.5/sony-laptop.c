static void do_sony_laptop_release_key(unsigned long unused)
{
struct sony_laptop_keypress kp;
unsigned long flags;
spin_lock_irqsave(&sony_laptop_input.fifo_lock, flags);
if (kfifo_out(&sony_laptop_input.fifo,
(unsigned char *)&kp, sizeof(kp)) == sizeof(kp)) {
input_report_key(kp.dev, kp.key, 0);
input_sync(kp.dev);
}
if (kfifo_len(&sony_laptop_input.fifo) != 0)
mod_timer(&sony_laptop_input.release_key_timer,
jiffies + msecs_to_jiffies(10));
spin_unlock_irqrestore(&sony_laptop_input.fifo_lock, flags);
}
static void sony_laptop_report_input_event(u8 event)
{
struct input_dev *jog_dev = sony_laptop_input.jog_dev;
struct input_dev *key_dev = sony_laptop_input.key_dev;
struct sony_laptop_keypress kp = { NULL };
int scancode = -1;
if (event == SONYPI_EVENT_FNKEY_RELEASED ||
event == SONYPI_EVENT_ANYBUTTON_RELEASED) {
return;
}
switch (event) {
case SONYPI_EVENT_JOGDIAL_UP:
case SONYPI_EVENT_JOGDIAL_UP_PRESSED:
input_report_rel(jog_dev, REL_WHEEL, 1);
input_sync(jog_dev);
return;
case SONYPI_EVENT_JOGDIAL_DOWN:
case SONYPI_EVENT_JOGDIAL_DOWN_PRESSED:
input_report_rel(jog_dev, REL_WHEEL, -1);
input_sync(jog_dev);
return;
case SONYPI_EVENT_JOGDIAL_PRESSED:
kp.key = BTN_MIDDLE;
kp.dev = jog_dev;
break;
default:
if (event >= ARRAY_SIZE(sony_laptop_input_index)) {
dprintk("sony_laptop_report_input_event, event not known: %d\n", event);
break;
}
if ((scancode = sony_laptop_input_index[event]) != -1) {
kp.key = sony_laptop_input_keycode_map[scancode];
if (kp.key != KEY_UNKNOWN)
kp.dev = key_dev;
}
break;
}
if (kp.dev) {
if (scancode != -1)
input_event(kp.dev, EV_MSC, MSC_SCAN, scancode);
input_report_key(kp.dev, kp.key, 1);
input_sync(kp.dev);
kfifo_in_locked(&sony_laptop_input.fifo,
(unsigned char *)&kp, sizeof(kp),
&sony_laptop_input.fifo_lock);
mod_timer(&sony_laptop_input.release_key_timer,
jiffies + msecs_to_jiffies(10));
} else
dprintk("unknown input event %.2x\n", event);
}
static int sony_laptop_setup_input(struct acpi_device *acpi_device)
{
struct input_dev *jog_dev;
struct input_dev *key_dev;
int i;
int error;
if (atomic_add_return(1, &sony_laptop_input.users) > 1)
return 0;
spin_lock_init(&sony_laptop_input.fifo_lock);
error = kfifo_alloc(&sony_laptop_input.fifo,
SONY_LAPTOP_BUF_SIZE, GFP_KERNEL);
if (error) {
pr_err("kfifo_alloc failed\n");
goto err_dec_users;
}
setup_timer(&sony_laptop_input.release_key_timer,
do_sony_laptop_release_key, 0);
key_dev = input_allocate_device();
if (!key_dev) {
error = -ENOMEM;
goto err_free_kfifo;
}
key_dev->name = "Sony Vaio Keys";
key_dev->id.bustype = BUS_ISA;
key_dev->id.vendor = PCI_VENDOR_ID_SONY;
key_dev->dev.parent = &acpi_device->dev;
input_set_capability(key_dev, EV_MSC, MSC_SCAN);
__set_bit(EV_KEY, key_dev->evbit);
key_dev->keycodesize = sizeof(sony_laptop_input_keycode_map[0]);
key_dev->keycodemax = ARRAY_SIZE(sony_laptop_input_keycode_map);
key_dev->keycode = &sony_laptop_input_keycode_map;
for (i = 0; i < ARRAY_SIZE(sony_laptop_input_keycode_map); i++)
__set_bit(sony_laptop_input_keycode_map[i], key_dev->keybit);
__clear_bit(KEY_RESERVED, key_dev->keybit);
error = input_register_device(key_dev);
if (error)
goto err_free_keydev;
sony_laptop_input.key_dev = key_dev;
jog_dev = input_allocate_device();
if (!jog_dev) {
error = -ENOMEM;
goto err_unregister_keydev;
}
jog_dev->name = "Sony Vaio Jogdial";
jog_dev->id.bustype = BUS_ISA;
jog_dev->id.vendor = PCI_VENDOR_ID_SONY;
jog_dev->dev.parent = &acpi_device->dev;
input_set_capability(jog_dev, EV_KEY, BTN_MIDDLE);
input_set_capability(jog_dev, EV_REL, REL_WHEEL);
error = input_register_device(jog_dev);
if (error)
goto err_free_jogdev;
sony_laptop_input.jog_dev = jog_dev;
return 0;
err_free_jogdev:
input_free_device(jog_dev);
err_unregister_keydev:
input_unregister_device(key_dev);
key_dev = NULL;
err_free_keydev:
input_free_device(key_dev);
err_free_kfifo:
kfifo_free(&sony_laptop_input.fifo);
err_dec_users:
atomic_dec(&sony_laptop_input.users);
return error;
}
static void sony_laptop_remove_input(void)
{
struct sony_laptop_keypress kp = { NULL };
if (!atomic_dec_and_test(&sony_laptop_input.users))
return;
del_timer_sync(&sony_laptop_input.release_key_timer);
while (kfifo_out(&sony_laptop_input.fifo,
(unsigned char *)&kp, sizeof(kp)) == sizeof(kp)) {
input_report_key(kp.dev, kp.key, 0);
input_sync(kp.dev);
}
input_unregister_device(sony_laptop_input.key_dev);
sony_laptop_input.key_dev = NULL;
if (sony_laptop_input.jog_dev) {
input_unregister_device(sony_laptop_input.jog_dev);
sony_laptop_input.jog_dev = NULL;
}
kfifo_free(&sony_laptop_input.fifo);
}
static int sony_pf_add(void)
{
int ret = 0;
if (atomic_add_return(1, &sony_pf_users) > 1)
return 0;
ret = platform_driver_register(&sony_pf_driver);
if (ret)
goto out;
sony_pf_device = platform_device_alloc("sony-laptop", -1);
if (!sony_pf_device) {
ret = -ENOMEM;
goto out_platform_registered;
}
ret = platform_device_add(sony_pf_device);
if (ret)
goto out_platform_alloced;
return 0;
out_platform_alloced:
platform_device_put(sony_pf_device);
sony_pf_device = NULL;
out_platform_registered:
platform_driver_unregister(&sony_pf_driver);
out:
atomic_dec(&sony_pf_users);
return ret;
}
static void sony_pf_remove(void)
{
if (!atomic_dec_and_test(&sony_pf_users))
return;
platform_device_unregister(sony_pf_device);
platform_driver_unregister(&sony_pf_driver);
}
static union acpi_object *__call_snc_method(acpi_handle handle, char *method,
u64 *value)
{
union acpi_object *result = NULL;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
if (value) {
struct acpi_object_list params;
union acpi_object in;
in.type = ACPI_TYPE_INTEGER;
in.integer.value = *value;
params.count = 1;
params.pointer = &in;
status = acpi_evaluate_object(handle, method, &params, &output);
dprintk("__call_snc_method: [%s:0x%.8x%.8x]\n", method,
(unsigned int)(*value >> 32),
(unsigned int)*value & 0xffffffff);
} else {
status = acpi_evaluate_object(handle, method, NULL, &output);
dprintk("__call_snc_method: [%s]\n", method);
}
if (ACPI_FAILURE(status)) {
pr_err("Failed to evaluate [%s]\n", method);
return NULL;
}
result = (union acpi_object *) output.pointer;
if (!result)
dprintk("No return object [%s]\n", method);
return result;
}
static int sony_nc_int_call(acpi_handle handle, char *name, int *value,
int *result)
{
union acpi_object *object = NULL;
if (value) {
u64 v = *value;
object = __call_snc_method(handle, name, &v);
} else
object = __call_snc_method(handle, name, NULL);
if (!object)
return -EINVAL;
if (object->type != ACPI_TYPE_INTEGER) {
pr_warn("Invalid acpi_object: expected 0x%x got 0x%x\n",
ACPI_TYPE_INTEGER, object->type);
kfree(object);
return -EINVAL;
}
if (result)
*result = object->integer.value;
kfree(object);
return 0;
}
static int sony_nc_buffer_call(acpi_handle handle, char *name, u64 *value,
void *buffer, size_t buflen)
{
size_t len = len;
union acpi_object *object = __call_snc_method(handle, name, value);
if (!object)
return -EINVAL;
if (object->type == ACPI_TYPE_BUFFER)
len = MIN(buflen, object->buffer.length);
else if (object->type == ACPI_TYPE_INTEGER)
len = MIN(buflen, sizeof(object->integer.value));
else {
pr_warn("Invalid acpi_object: expected 0x%x got 0x%x\n",
ACPI_TYPE_BUFFER, object->type);
kfree(object);
return -EINVAL;
}
memcpy(buffer, object->buffer.pointer, len);
kfree(object);
return 0;
}
static ssize_t sony_nc_handles_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t len = 0;
int i;
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
len += snprintf(buffer + len, PAGE_SIZE - len, "0x%.4x ",
handles->cap[i]);
}
len += snprintf(buffer + len, PAGE_SIZE - len, "\n");
return len;
}
static int sony_nc_handles_setup(struct platform_device *pd)
{
int i, r, result, arg;
handles = kzalloc(sizeof(*handles), GFP_KERNEL);
if (!handles)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
arg = i + 0x20;
r = sony_nc_int_call(sony_nc_acpi_handle, "SN00", &arg,
&result);
if (!r) {
dprintk("caching handle 0x%.4x (offset: 0x%.2x)\n",
result, i);
handles->cap[i] = result;
}
}
if (debug) {
sysfs_attr_init(&handles->devattr.attr);
handles->devattr.attr.name = "handles";
handles->devattr.attr.mode = S_IRUGO;
handles->devattr.show = sony_nc_handles_show;
if (device_create_file(&pd->dev, &handles->devattr)) {
kfree(handles);
handles = NULL;
return -1;
}
}
return 0;
}
static int sony_nc_handles_cleanup(struct platform_device *pd)
{
if (handles) {
if (debug)
device_remove_file(&pd->dev, &handles->devattr);
kfree(handles);
handles = NULL;
}
return 0;
}
static int sony_find_snc_handle(int handle)
{
int i;
if (!handles || !handle)
return -EINVAL;
for (i = 0; i < 0x10; i++) {
if (handles->cap[i] == handle) {
dprintk("found handle 0x%.4x (offset: 0x%.2x)\n",
handle, i);
return i;
}
}
dprintk("handle 0x%.4x not found\n", handle);
return -EINVAL;
}
static int sony_call_snc_handle(int handle, int argument, int *result)
{
int arg, ret = 0;
int offset = sony_find_snc_handle(handle);
if (offset < 0)
return offset;
arg = offset | argument;
ret = sony_nc_int_call(sony_nc_acpi_handle, "SN07", &arg, result);
dprintk("called SN07 with 0x%.4x (result: 0x%.4x)\n", arg, *result);
return ret;
}
static int brightness_default_validate(const int direction, const int value)
{
switch (direction) {
case SNC_VALIDATE_OUT:
return value - 1;
case SNC_VALIDATE_IN:
if (value >= 0 && value < SONY_MAX_BRIGHTNESS)
return value + 1;
}
return -EINVAL;
}
static int boolean_validate(const int direction, const int value)
{
if (direction == SNC_VALIDATE_IN) {
if (value != 0 && value != 1)
return -EINVAL;
}
return value;
}
static ssize_t sony_nc_sysfs_show(struct device *dev, struct device_attribute *attr,
char *buffer)
{
int value, ret = 0;
struct sony_nc_value *item =
container_of(attr, struct sony_nc_value, devattr);
if (!*item->acpiget)
return -EIO;
ret = sony_nc_int_call(sony_nc_acpi_handle, *item->acpiget, NULL,
&value);
if (ret < 0)
return -EIO;
if (item->validate)
value = item->validate(SNC_VALIDATE_OUT, value);
return snprintf(buffer, PAGE_SIZE, "%d\n", value);
}
static ssize_t sony_nc_sysfs_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
int value;
int ret = 0;
struct sony_nc_value *item =
container_of(attr, struct sony_nc_value, devattr);
if (!item->acpiset)
return -EIO;
if (count > 31)
return -EINVAL;
if (kstrtoint(buffer, 10, &value))
return -EINVAL;
if (item->validate)
value = item->validate(SNC_VALIDATE_IN, value);
if (value < 0)
return value;
ret = sony_nc_int_call(sony_nc_acpi_handle, *item->acpiset,
&value, NULL);
if (ret < 0)
return -EIO;
item->value = value;
item->valid = 1;
return count;
}
static int sony_backlight_update_status(struct backlight_device *bd)
{
int arg = bd->props.brightness + 1;
return sony_nc_int_call(sony_nc_acpi_handle, "SBRT", &arg, NULL);
}
static int sony_backlight_get_brightness(struct backlight_device *bd)
{
int value;
if (sony_nc_int_call(sony_nc_acpi_handle, "GBRT", NULL, &value))
return 0;
return value - 1;
}
static int sony_nc_get_brightness_ng(struct backlight_device *bd)
{
int result;
struct sony_backlight_props *sdev =
(struct sony_backlight_props *)bl_get_data(bd);
sony_call_snc_handle(sdev->handle, sdev->cmd_base + 0x100, &result);
return (result & 0xff) - sdev->offset;
}
static int sony_nc_update_status_ng(struct backlight_device *bd)
{
int value, result;
struct sony_backlight_props *sdev =
(struct sony_backlight_props *)bl_get_data(bd);
value = bd->props.brightness + sdev->offset;
if (sony_call_snc_handle(sdev->handle, sdev->cmd_base | (value << 0x10),
&result))
return -EIO;
return value;
}
static int sony_nc_hotkeys_decode(u32 event, unsigned int handle)
{
int ret = -EINVAL;
unsigned int result = 0;
struct sony_nc_event *key_event;
if (sony_call_snc_handle(handle, 0x200, &result)) {
dprintk("Unable to decode event 0x%.2x 0x%.2x\n", handle,
event);
return -EINVAL;
}
result &= 0xFF;
if (handle == 0x0100)
key_event = sony_100_events;
else
key_event = sony_127_events;
for (; key_event->data; key_event++) {
if (key_event->data == result) {
ret = key_event->event;
break;
}
}
if (!key_event->data)
pr_info("Unknown hotkey 0x%.2x/0x%.2x (handle 0x%.2x)\n",
event, result, handle);
return ret;
}
static void sony_nc_notify(struct acpi_device *device, u32 event)
{
u32 real_ev = event;
u8 ev_type = 0;
dprintk("sony_nc_notify, event: 0x%.2x\n", event);
if (event >= 0x90) {
unsigned int result = 0;
unsigned int arg = 0;
unsigned int handle = 0;
unsigned int offset = event - 0x90;
if (offset >= ARRAY_SIZE(handles->cap)) {
pr_err("Event 0x%x outside of capabilities list\n",
event);
return;
}
handle = handles->cap[offset];
switch (handle) {
case 0x0100:
case 0x0127:
ev_type = HOTKEY;
real_ev = sony_nc_hotkeys_decode(event, handle);
if (real_ev > 0)
sony_laptop_report_input_event(real_ev);
else
real_ev = event;
break;
case 0x0124:
case 0x0135:
ev_type = KILLSWITCH;
sony_call_snc_handle(handle, 0x0100, &result);
real_ev = result & 0x03;
if (real_ev == 1)
sony_nc_rfkill_update();
break;
case 0x0128:
case 0x0146:
sony_call_snc_handle(handle, 0x0000, &result);
dprintk("GFX switch event received (reason: %s)\n",
(result & 0x01) ?
"switch change" : "unknown");
sony_call_snc_handle(handle, 0x0100, &result);
ev_type = GFX_SWITCH;
real_ev = result & 0xff;
break;
default:
dprintk("Unknown event 0x%x for handle 0x%x\n",
event, handle);
break;
}
arg = 1 << offset;
sony_nc_int_call(sony_nc_acpi_handle, "SN05", &arg, &result);
} else {
ev_type = HOTKEY;
sony_laptop_report_input_event(real_ev);
}
acpi_bus_generate_proc_event(sony_nc_acpi_device, ev_type, real_ev);
acpi_bus_generate_netlink_event(sony_nc_acpi_device->pnp.device_class,
dev_name(&sony_nc_acpi_device->dev), ev_type, real_ev);
}
static acpi_status sony_walk_callback(acpi_handle handle, u32 level,
void *context, void **return_value)
{
struct acpi_device_info *info;
if (ACPI_SUCCESS(acpi_get_object_info(handle, &info))) {
pr_warn("method: name: %4.4s, args %X\n",
(char *)&info->name, info->param_count);
kfree(info);
}
return AE_OK;
}
static void sony_nc_function_setup(struct acpi_device *device,
struct platform_device *pf_device)
{
unsigned int i, result, bitmask, arg;
if (!handles)
return;
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
unsigned int handle = handles->cap[i];
if (!handle)
continue;
dprintk("setting up handle 0x%.4x\n", handle);
switch (handle) {
case 0x0100:
case 0x0101:
case 0x0127:
sony_call_snc_handle(handle, 0, &result);
break;
case 0x0102:
sony_call_snc_handle(handle, 0x100, &result);
break;
case 0x0105:
case 0x0148:
result = sony_nc_touchpad_setup(pf_device, handle);
if (result)
pr_err("couldn't set up touchpad control function (%d)\n",
result);
break;
case 0x0115:
case 0x0136:
case 0x013f:
result = sony_nc_battery_care_setup(pf_device, handle);
if (result)
pr_err("couldn't set up battery care function (%d)\n",
result);
break;
case 0x0119:
result = sony_nc_lid_resume_setup(pf_device);
if (result)
pr_err("couldn't set up lid resume function (%d)\n",
result);
break;
case 0x0122:
result = sony_nc_thermal_setup(pf_device);
if (result)
pr_err("couldn't set up thermal profile function (%d)\n",
result);
break;
case 0x0131:
result = sony_nc_highspeed_charging_setup(pf_device);
if (result)
pr_err("couldn't set up high speed charging function (%d)\n",
result);
break;
case 0x0124:
case 0x0135:
result = sony_nc_rfkill_setup(device, handle);
if (result)
pr_err("couldn't set up rfkill support (%d)\n",
result);
break;
case 0x0137:
case 0x0143:
result = sony_nc_kbd_backlight_setup(pf_device, handle);
if (result)
pr_err("couldn't set up keyboard backlight function (%d)\n",
result);
break;
default:
continue;
}
}
arg = 0x10;
if (!sony_nc_int_call(sony_nc_acpi_handle, "SN00", &arg, &bitmask))
sony_nc_int_call(sony_nc_acpi_handle, "SN02", &bitmask,
&result);
}
static void sony_nc_function_cleanup(struct platform_device *pd)
{
unsigned int i, result, bitmask, handle;
sony_nc_int_call(sony_nc_acpi_handle, "SN01", NULL, &bitmask);
sony_nc_int_call(sony_nc_acpi_handle, "SN03", &bitmask, &result);
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
handle = handles->cap[i];
if (!handle)
continue;
switch (handle) {
case 0x0105:
case 0x0148:
sony_nc_touchpad_cleanup(pd);
break;
case 0x0115:
case 0x0136:
case 0x013f:
sony_nc_battery_care_cleanup(pd);
break;
case 0x0119:
sony_nc_lid_resume_cleanup(pd);
break;
case 0x0122:
sony_nc_thermal_cleanup(pd);
break;
case 0x0131:
sony_nc_highspeed_charging_cleanup(pd);
break;
case 0x0124:
case 0x0135:
sony_nc_rfkill_cleanup();
break;
case 0x0137:
case 0x0143:
sony_nc_kbd_backlight_cleanup(pd);
break;
default:
continue;
}
}
sony_nc_handles_cleanup(pd);
}
static void sony_nc_function_resume(void)
{
unsigned int i, result, bitmask, arg;
dprintk("Resuming SNC device\n");
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
unsigned int handle = handles->cap[i];
if (!handle)
continue;
switch (handle) {
case 0x0100:
case 0x0101:
case 0x0127:
sony_call_snc_handle(handle, 0, &result);
break;
case 0x0102:
sony_call_snc_handle(handle, 0x100, &result);
break;
case 0x0122:
sony_nc_thermal_resume();
break;
case 0x0124:
case 0x0135:
sony_nc_rfkill_update();
break;
case 0x0137:
case 0x0143:
sony_nc_kbd_backlight_resume();
break;
default:
continue;
}
}
arg = 0x10;
if (!sony_nc_int_call(sony_nc_acpi_handle, "SN00", &arg, &bitmask))
sony_nc_int_call(sony_nc_acpi_handle, "SN02", &bitmask,
&result);
}
static int sony_nc_resume(struct acpi_device *device)
{
struct sony_nc_value *item;
acpi_handle handle;
for (item = sony_nc_values; item->name; item++) {
int ret;
if (!item->valid)
continue;
ret = sony_nc_int_call(sony_nc_acpi_handle, *item->acpiset,
&item->value, NULL);
if (ret < 0) {
pr_err("%s: %d\n", __func__, ret);
break;
}
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "ECON",
&handle))) {
int arg = 1;
if (sony_nc_int_call(sony_nc_acpi_handle, "ECON", &arg, NULL))
dprintk("ECON Method failed\n");
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "SN00",
&handle)))
sony_nc_function_resume();
return 0;
}
static void sony_nc_rfkill_cleanup(void)
{
int i;
for (i = 0; i < N_SONY_RFKILL; i++) {
if (sony_rfkill_devices[i]) {
rfkill_unregister(sony_rfkill_devices[i]);
rfkill_destroy(sony_rfkill_devices[i]);
}
}
}
static int sony_nc_rfkill_set(void *data, bool blocked)
{
int result;
int argument = sony_rfkill_address[(long) data] + 0x100;
if (!blocked)
argument |= 0x030000;
return sony_call_snc_handle(sony_rfkill_handle, argument, &result);
}
static int sony_nc_setup_rfkill(struct acpi_device *device,
enum sony_nc_rfkill nc_type)
{
int err = 0;
struct rfkill *rfk;
enum rfkill_type type;
const char *name;
int result;
bool hwblock, swblock;
switch (nc_type) {
case SONY_WIFI:
type = RFKILL_TYPE_WLAN;
name = "sony-wifi";
break;
case SONY_BLUETOOTH:
type = RFKILL_TYPE_BLUETOOTH;
name = "sony-bluetooth";
break;
case SONY_WWAN:
type = RFKILL_TYPE_WWAN;
name = "sony-wwan";
break;
case SONY_WIMAX:
type = RFKILL_TYPE_WIMAX;
name = "sony-wimax";
break;
default:
return -EINVAL;
}
rfk = rfkill_alloc(name, &device->dev, type,
&sony_rfkill_ops, (void *)nc_type);
if (!rfk)
return -ENOMEM;
if (sony_call_snc_handle(sony_rfkill_handle, 0x200, &result) < 0) {
rfkill_destroy(rfk);
return -1;
}
hwblock = !(result & 0x1);
if (sony_call_snc_handle(sony_rfkill_handle,
sony_rfkill_address[nc_type],
&result) < 0) {
rfkill_destroy(rfk);
return -1;
}
swblock = !(result & 0x2);
rfkill_init_sw_state(rfk, swblock);
rfkill_set_hw_state(rfk, hwblock);
err = rfkill_register(rfk);
if (err) {
rfkill_destroy(rfk);
return err;
}
sony_rfkill_devices[nc_type] = rfk;
return err;
}
static void sony_nc_rfkill_update(void)
{
enum sony_nc_rfkill i;
int result;
bool hwblock;
sony_call_snc_handle(sony_rfkill_handle, 0x200, &result);
hwblock = !(result & 0x1);
for (i = 0; i < N_SONY_RFKILL; i++) {
int argument = sony_rfkill_address[i];
if (!sony_rfkill_devices[i])
continue;
if (hwblock) {
if (rfkill_set_hw_state(sony_rfkill_devices[i], true)) {
}
continue;
}
sony_call_snc_handle(sony_rfkill_handle, argument, &result);
rfkill_set_states(sony_rfkill_devices[i],
!(result & 0x2), false);
}
}
static int sony_nc_rfkill_setup(struct acpi_device *device,
unsigned int handle)
{
u64 offset;
int i;
unsigned char buffer[32] = { 0 };
offset = sony_find_snc_handle(handle);
sony_rfkill_handle = handle;
i = sony_nc_buffer_call(sony_nc_acpi_handle, "SN06", &offset, buffer,
32);
if (i < 0)
return i;
for (i = 0; i < ARRAY_SIZE(buffer); i++) {
if (buffer[i] == 0xff)
break;
dprintk("Radio devices, found 0x%.2x\n", buffer[i]);
if (buffer[i] == 0 && !sony_rfkill_devices[SONY_WIFI])
sony_nc_setup_rfkill(device, SONY_WIFI);
if (buffer[i] == 0x10 && !sony_rfkill_devices[SONY_BLUETOOTH])
sony_nc_setup_rfkill(device, SONY_BLUETOOTH);
if (((0xf0 & buffer[i]) == 0x20 ||
(0xf0 & buffer[i]) == 0x50) &&
!sony_rfkill_devices[SONY_WWAN])
sony_nc_setup_rfkill(device, SONY_WWAN);
if (buffer[i] == 0x30 && !sony_rfkill_devices[SONY_WIMAX])
sony_nc_setup_rfkill(device, SONY_WIMAX);
}
return 0;
}
static ssize_t __sony_nc_kbd_backlight_mode_set(u8 value)
{
int result;
if (value > 1)
return -EINVAL;
if (sony_call_snc_handle(kbdbl_ctl->handle,
(value << 0x10) | (kbdbl_ctl->base), &result))
return -EIO;
sony_call_snc_handle(kbdbl_ctl->handle,
(value << 0x10) | (kbdbl_ctl->base + 0x100), &result);
kbdbl_ctl->mode = value;
return 0;
}
static ssize_t sony_nc_kbd_backlight_mode_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
int ret = 0;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
ret = __sony_nc_kbd_backlight_mode_set(value);
if (ret < 0)
return ret;
return count;
}
static ssize_t sony_nc_kbd_backlight_mode_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count = 0;
count = snprintf(buffer, PAGE_SIZE, "%d\n", kbdbl_ctl->mode);
return count;
}
static int __sony_nc_kbd_backlight_timeout_set(u8 value)
{
int result;
if (value > 3)
return -EINVAL;
if (sony_call_snc_handle(kbdbl_ctl->handle, (value << 0x10) |
(kbdbl_ctl->base + 0x200), &result))
return -EIO;
kbdbl_ctl->timeout = value;
return 0;
}
static ssize_t sony_nc_kbd_backlight_timeout_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
int ret = 0;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
ret = __sony_nc_kbd_backlight_timeout_set(value);
if (ret < 0)
return ret;
return count;
}
static ssize_t sony_nc_kbd_backlight_timeout_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count = 0;
count = snprintf(buffer, PAGE_SIZE, "%d\n", kbdbl_ctl->timeout);
return count;
}
static int sony_nc_kbd_backlight_setup(struct platform_device *pd,
unsigned int handle)
{
int result;
int ret = 0;
ret = sony_call_snc_handle(handle, handle == 0x0137 ? 0x0B00 : 0x0100,
&result);
if (ret)
return ret;
if ((handle == 0x0137 && !(result & 0x02)) ||
!(result & 0x01)) {
dprintk("no backlight keyboard found\n");
return 0;
}
kbdbl_ctl = kzalloc(sizeof(*kbdbl_ctl), GFP_KERNEL);
if (!kbdbl_ctl)
return -ENOMEM;
kbdbl_ctl->handle = handle;
if (handle == 0x0137)
kbdbl_ctl->base = 0x0C00;
else
kbdbl_ctl->base = 0x4000;
sysfs_attr_init(&kbdbl_ctl->mode_attr.attr);
kbdbl_ctl->mode_attr.attr.name = "kbd_backlight";
kbdbl_ctl->mode_attr.attr.mode = S_IRUGO | S_IWUSR;
kbdbl_ctl->mode_attr.show = sony_nc_kbd_backlight_mode_show;
kbdbl_ctl->mode_attr.store = sony_nc_kbd_backlight_mode_store;
sysfs_attr_init(&kbdbl_ctl->timeout_attr.attr);
kbdbl_ctl->timeout_attr.attr.name = "kbd_backlight_timeout";
kbdbl_ctl->timeout_attr.attr.mode = S_IRUGO | S_IWUSR;
kbdbl_ctl->timeout_attr.show = sony_nc_kbd_backlight_timeout_show;
kbdbl_ctl->timeout_attr.store = sony_nc_kbd_backlight_timeout_store;
ret = device_create_file(&pd->dev, &kbdbl_ctl->mode_attr);
if (ret)
goto outkzalloc;
ret = device_create_file(&pd->dev, &kbdbl_ctl->timeout_attr);
if (ret)
goto outmode;
__sony_nc_kbd_backlight_mode_set(kbd_backlight);
__sony_nc_kbd_backlight_timeout_set(kbd_backlight_timeout);
return 0;
outmode:
device_remove_file(&pd->dev, &kbdbl_ctl->mode_attr);
outkzalloc:
kfree(kbdbl_ctl);
kbdbl_ctl = NULL;
return ret;
}
static void sony_nc_kbd_backlight_cleanup(struct platform_device *pd)
{
if (kbdbl_ctl) {
int result;
device_remove_file(&pd->dev, &kbdbl_ctl->mode_attr);
device_remove_file(&pd->dev, &kbdbl_ctl->timeout_attr);
sony_call_snc_handle(kbdbl_ctl->handle,
kbdbl_ctl->base | 0x10000, &result);
sony_call_snc_handle(kbdbl_ctl->handle,
kbdbl_ctl->base + 0x200, &result);
kfree(kbdbl_ctl);
kbdbl_ctl = NULL;
}
}
static void sony_nc_kbd_backlight_resume(void)
{
int ignore = 0;
if (!kbdbl_ctl)
return;
if (kbdbl_ctl->mode == 0)
sony_call_snc_handle(kbdbl_ctl->handle, kbdbl_ctl->base,
&ignore);
if (kbdbl_ctl->timeout != 0)
sony_call_snc_handle(kbdbl_ctl->handle,
(kbdbl_ctl->base + 0x200) |
(kbdbl_ctl->timeout << 0x10), &ignore);
}
static ssize_t sony_nc_battery_care_limit_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned int result, cmd;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
cmd = 0;
if (value > 0) {
if (value <= 50)
cmd = 0x20;
else if (value <= 80)
cmd = 0x10;
else if (value <= 100)
cmd = 0x30;
else
return -EINVAL;
if (bcare_ctl->handle != 0x013f)
cmd = cmd | (cmd << 2);
cmd = (cmd | 0x1) << 0x10;
}
if (sony_call_snc_handle(bcare_ctl->handle, cmd | 0x0100, &result))
return -EIO;
return count;
}
static ssize_t sony_nc_battery_care_limit_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
unsigned int result, status;
if (sony_call_snc_handle(bcare_ctl->handle, 0x0000, &result))
return -EIO;
status = (result & 0x01) ? ((result & 0x30) >> 0x04) : 0;
switch (status) {
case 1:
status = 80;
break;
case 2:
status = 50;
break;
case 3:
status = 100;
break;
default:
status = 0;
break;
}
return snprintf(buffer, PAGE_SIZE, "%d\n", status);
}
static ssize_t sony_nc_battery_care_health_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count = 0;
unsigned int health;
if (sony_call_snc_handle(bcare_ctl->handle, 0x0200, &health))
return -EIO;
count = snprintf(buffer, PAGE_SIZE, "%d\n", health & 0xff);
return count;
}
static int sony_nc_battery_care_setup(struct platform_device *pd,
unsigned int handle)
{
int ret = 0;
bcare_ctl = kzalloc(sizeof(struct battery_care_control), GFP_KERNEL);
if (!bcare_ctl)
return -ENOMEM;
bcare_ctl->handle = handle;
sysfs_attr_init(&bcare_ctl->attrs[0].attr);
bcare_ctl->attrs[0].attr.name = "battery_care_limiter";
bcare_ctl->attrs[0].attr.mode = S_IRUGO | S_IWUSR;
bcare_ctl->attrs[0].show = sony_nc_battery_care_limit_show;
bcare_ctl->attrs[0].store = sony_nc_battery_care_limit_store;
ret = device_create_file(&pd->dev, &bcare_ctl->attrs[0]);
if (ret)
goto outkzalloc;
if (handle == 0x0115)
return 0;
sysfs_attr_init(&bcare_ctl->attrs[1].attr);
bcare_ctl->attrs[1].attr.name = "battery_care_health";
bcare_ctl->attrs[1].attr.mode = S_IRUGO;
bcare_ctl->attrs[1].show = sony_nc_battery_care_health_show;
ret = device_create_file(&pd->dev, &bcare_ctl->attrs[1]);
if (ret)
goto outlimiter;
return 0;
outlimiter:
device_remove_file(&pd->dev, &bcare_ctl->attrs[0]);
outkzalloc:
kfree(bcare_ctl);
bcare_ctl = NULL;
return ret;
}
static void sony_nc_battery_care_cleanup(struct platform_device *pd)
{
if (bcare_ctl) {
device_remove_file(&pd->dev, &bcare_ctl->attrs[0]);
if (bcare_ctl->handle != 0x0115)
device_remove_file(&pd->dev, &bcare_ctl->attrs[1]);
kfree(bcare_ctl);
bcare_ctl = NULL;
}
}
static int sony_nc_thermal_mode_set(unsigned short mode)
{
unsigned int result;
if ((mode && !(th_handle->profiles & mode)) || mode >= THM_PROFILE_MAX)
return -EINVAL;
if (sony_call_snc_handle(0x0122, mode << 0x10 | 0x0200, &result))
return -EIO;
th_handle->mode = mode;
return 0;
}
static int sony_nc_thermal_mode_get(void)
{
unsigned int result;
if (sony_call_snc_handle(0x0122, 0x0100, &result))
return -EIO;
return result & 0xff;
}
static ssize_t sony_nc_thermal_profiles_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
short cnt;
size_t idx = 0;
for (cnt = 0; cnt < THM_PROFILE_MAX; cnt++) {
if (!cnt || (th_handle->profiles & cnt))
idx += snprintf(buffer + idx, PAGE_SIZE - idx, "%s ",
snc_thermal_profiles[cnt]);
}
idx += snprintf(buffer + idx, PAGE_SIZE - idx, "\n");
return idx;
}
static ssize_t sony_nc_thermal_mode_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned short cmd;
size_t len = count;
if (count == 0)
return -EINVAL;
if (buffer[len - 1] == '\n')
len--;
for (cmd = 0; cmd < THM_PROFILE_MAX; cmd++)
if (strncmp(buffer, snc_thermal_profiles[cmd], len) == 0)
break;
if (sony_nc_thermal_mode_set(cmd))
return -EIO;
return count;
}
static ssize_t sony_nc_thermal_mode_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count = 0;
int mode = sony_nc_thermal_mode_get();
if (mode < 0)
return mode;
count = snprintf(buffer, PAGE_SIZE, "%s\n", snc_thermal_profiles[mode]);
return count;
}
static int sony_nc_thermal_setup(struct platform_device *pd)
{
int ret = 0;
th_handle = kzalloc(sizeof(struct snc_thermal_ctrl), GFP_KERNEL);
if (!th_handle)
return -ENOMEM;
ret = sony_call_snc_handle(0x0122, 0x0000, &th_handle->profiles);
if (ret) {
pr_warn("couldn't to read the thermal profiles\n");
goto outkzalloc;
}
ret = sony_nc_thermal_mode_get();
if (ret < 0) {
pr_warn("couldn't to read the current thermal profile");
goto outkzalloc;
}
th_handle->mode = ret;
sysfs_attr_init(&th_handle->profiles_attr.attr);
th_handle->profiles_attr.attr.name = "thermal_profiles";
th_handle->profiles_attr.attr.mode = S_IRUGO;
th_handle->profiles_attr.show = sony_nc_thermal_profiles_show;
sysfs_attr_init(&th_handle->mode_attr.attr);
th_handle->mode_attr.attr.name = "thermal_control";
th_handle->mode_attr.attr.mode = S_IRUGO | S_IWUSR;
th_handle->mode_attr.show = sony_nc_thermal_mode_show;
th_handle->mode_attr.store = sony_nc_thermal_mode_store;
ret = device_create_file(&pd->dev, &th_handle->profiles_attr);
if (ret)
goto outkzalloc;
ret = device_create_file(&pd->dev, &th_handle->mode_attr);
if (ret)
goto outprofiles;
return 0;
outprofiles:
device_remove_file(&pd->dev, &th_handle->profiles_attr);
outkzalloc:
kfree(th_handle);
th_handle = NULL;
return ret;
}
static void sony_nc_thermal_cleanup(struct platform_device *pd)
{
if (th_handle) {
device_remove_file(&pd->dev, &th_handle->profiles_attr);
device_remove_file(&pd->dev, &th_handle->mode_attr);
kfree(th_handle);
th_handle = NULL;
}
}
static void sony_nc_thermal_resume(void)
{
unsigned int status = sony_nc_thermal_mode_get();
if (status != th_handle->mode)
sony_nc_thermal_mode_set(th_handle->mode);
}
static ssize_t sony_nc_lid_resume_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned int result, pos;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value) || value > 1)
return -EINVAL;
if (strcmp(attr->attr.name, "lid_resume_S3") == 0)
pos = 2;
else if (strcmp(attr->attr.name, "lid_resume_S4") == 0)
pos = 1;
else if (strcmp(attr->attr.name, "lid_resume_S5") == 0)
pos = 0;
else
return -EINVAL;
if (value)
value = lid_ctl->status | (1 << pos);
else
value = lid_ctl->status & ~(1 << pos);
if (sony_call_snc_handle(0x0119, value << 0x10 | 0x0100, &result))
return -EIO;
lid_ctl->status = value;
return count;
}
static ssize_t sony_nc_lid_resume_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
unsigned int pos;
if (strcmp(attr->attr.name, "lid_resume_S3") == 0)
pos = 2;
else if (strcmp(attr->attr.name, "lid_resume_S4") == 0)
pos = 1;
else if (strcmp(attr->attr.name, "lid_resume_S5") == 0)
pos = 0;
else
return -EINVAL;
return snprintf(buffer, PAGE_SIZE, "%d\n",
(lid_ctl->status >> pos) & 0x01);
}
static int sony_nc_lid_resume_setup(struct platform_device *pd)
{
unsigned int result;
int i;
if (sony_call_snc_handle(0x0119, 0x0000, &result))
return -EIO;
lid_ctl = kzalloc(sizeof(struct snc_lid_resume_control), GFP_KERNEL);
if (!lid_ctl)
return -ENOMEM;
lid_ctl->status = result & 0x7;
sysfs_attr_init(&lid_ctl->attrs[0].attr);
lid_ctl->attrs[0].attr.name = "lid_resume_S3";
lid_ctl->attrs[0].attr.mode = S_IRUGO | S_IWUSR;
lid_ctl->attrs[0].show = sony_nc_lid_resume_show;
lid_ctl->attrs[0].store = sony_nc_lid_resume_store;
sysfs_attr_init(&lid_ctl->attrs[1].attr);
lid_ctl->attrs[1].attr.name = "lid_resume_S4";
lid_ctl->attrs[1].attr.mode = S_IRUGO | S_IWUSR;
lid_ctl->attrs[1].show = sony_nc_lid_resume_show;
lid_ctl->attrs[1].store = sony_nc_lid_resume_store;
sysfs_attr_init(&lid_ctl->attrs[2].attr);
lid_ctl->attrs[2].attr.name = "lid_resume_S5";
lid_ctl->attrs[2].attr.mode = S_IRUGO | S_IWUSR;
lid_ctl->attrs[2].show = sony_nc_lid_resume_show;
lid_ctl->attrs[2].store = sony_nc_lid_resume_store;
for (i = 0; i < 3; i++) {
result = device_create_file(&pd->dev, &lid_ctl->attrs[i]);
if (result)
goto liderror;
}
return 0;
liderror:
for (; i > 0; i--)
device_remove_file(&pd->dev, &lid_ctl->attrs[i]);
kfree(lid_ctl);
lid_ctl = NULL;
return result;
}
static void sony_nc_lid_resume_cleanup(struct platform_device *pd)
{
int i;
if (lid_ctl) {
for (i = 0; i < 3; i++)
device_remove_file(&pd->dev, &lid_ctl->attrs[i]);
kfree(lid_ctl);
lid_ctl = NULL;
}
}
static ssize_t sony_nc_highspeed_charging_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned int result;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value) || value > 1)
return -EINVAL;
if (sony_call_snc_handle(0x0131, value << 0x10 | 0x0200, &result))
return -EIO;
return count;
}
static ssize_t sony_nc_highspeed_charging_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
unsigned int result;
if (sony_call_snc_handle(0x0131, 0x0100, &result))
return -EIO;
return snprintf(buffer, PAGE_SIZE, "%d\n", result & 0x01);
}
static int sony_nc_highspeed_charging_setup(struct platform_device *pd)
{
unsigned int result;
if (sony_call_snc_handle(0x0131, 0x0000, &result) || !(result & 0x01)) {
pr_info("No High Speed Charging capability found\n");
return 0;
}
hsc_handle = kzalloc(sizeof(struct device_attribute), GFP_KERNEL);
if (!hsc_handle)
return -ENOMEM;
sysfs_attr_init(&hsc_handle->attr);
hsc_handle->attr.name = "battery_highspeed_charging";
hsc_handle->attr.mode = S_IRUGO | S_IWUSR;
hsc_handle->show = sony_nc_highspeed_charging_show;
hsc_handle->store = sony_nc_highspeed_charging_store;
result = device_create_file(&pd->dev, hsc_handle);
if (result) {
kfree(hsc_handle);
hsc_handle = NULL;
return result;
}
return 0;
}
static void sony_nc_highspeed_charging_cleanup(struct platform_device *pd)
{
if (hsc_handle) {
device_remove_file(&pd->dev, hsc_handle);
kfree(hsc_handle);
hsc_handle = NULL;
}
}
static ssize_t sony_nc_touchpad_store(struct device *dev,
struct device_attribute *attr, const char *buffer, size_t count)
{
unsigned int result;
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value) || value > 1)
return -EINVAL;
if (sony_call_snc_handle(tp_ctl->handle,
(!value << 0x10) | 0x100, &result))
return -EIO;
return count;
}
static ssize_t sony_nc_touchpad_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
unsigned int result;
if (sony_call_snc_handle(tp_ctl->handle, 0x000, &result))
return -EINVAL;
return snprintf(buffer, PAGE_SIZE, "%d\n", !(result & 0x01));
}
static int sony_nc_touchpad_setup(struct platform_device *pd,
unsigned int handle)
{
int ret = 0;
tp_ctl = kzalloc(sizeof(struct touchpad_control), GFP_KERNEL);
if (!tp_ctl)
return -ENOMEM;
tp_ctl->handle = handle;
sysfs_attr_init(&tp_ctl->attr.attr);
tp_ctl->attr.attr.name = "touchpad";
tp_ctl->attr.attr.mode = S_IRUGO | S_IWUSR;
tp_ctl->attr.show = sony_nc_touchpad_show;
tp_ctl->attr.store = sony_nc_touchpad_store;
ret = device_create_file(&pd->dev, &tp_ctl->attr);
if (ret) {
kfree(tp_ctl);
tp_ctl = NULL;
}
return ret;
}
static void sony_nc_touchpad_cleanup(struct platform_device *pd)
{
if (tp_ctl) {
device_remove_file(&pd->dev, &tp_ctl->attr);
kfree(tp_ctl);
tp_ctl = NULL;
}
}
static void sony_nc_backlight_ng_read_limits(int handle,
struct sony_backlight_props *props)
{
u64 offset;
int i;
int lvl_table_len = 0;
u8 min = 0xff, max = 0x00;
unsigned char buffer[32] = { 0 };
props->handle = handle;
props->offset = 0;
props->maxlvl = 0xff;
offset = sony_find_snc_handle(handle);
i = sony_nc_buffer_call(sony_nc_acpi_handle, "SN06", &offset, buffer,
32);
if (i < 0)
return;
switch (handle) {
case 0x012f:
case 0x0137:
lvl_table_len = 9;
break;
case 0x143:
lvl_table_len = 16;
break;
}
for (i = 0; i < lvl_table_len && i < ARRAY_SIZE(buffer); i++) {
dprintk("Brightness level: %d\n", buffer[i]);
if (!buffer[i])
break;
if (buffer[i] > max)
max = buffer[i];
if (buffer[i] < min)
min = buffer[i];
}
props->offset = min;
props->maxlvl = max;
dprintk("Brightness levels: min=%d max=%d\n", props->offset,
props->maxlvl);
}
static void sony_nc_backlight_setup(void)
{
acpi_handle unused;
int max_brightness = 0;
const struct backlight_ops *ops = NULL;
struct backlight_properties props;
if (sony_find_snc_handle(0x12f) >= 0) {
ops = &sony_backlight_ng_ops;
sony_bl_props.cmd_base = 0x0100;
sony_nc_backlight_ng_read_limits(0x12f, &sony_bl_props);
max_brightness = sony_bl_props.maxlvl - sony_bl_props.offset;
} else if (sony_find_snc_handle(0x137) >= 0) {
ops = &sony_backlight_ng_ops;
sony_bl_props.cmd_base = 0x0100;
sony_nc_backlight_ng_read_limits(0x137, &sony_bl_props);
max_brightness = sony_bl_props.maxlvl - sony_bl_props.offset;
} else if (sony_find_snc_handle(0x143) >= 0) {
ops = &sony_backlight_ng_ops;
sony_bl_props.cmd_base = 0x3000;
sony_nc_backlight_ng_read_limits(0x143, &sony_bl_props);
max_brightness = sony_bl_props.maxlvl - sony_bl_props.offset;
} else if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "GBRT",
&unused))) {
ops = &sony_backlight_ops;
max_brightness = SONY_MAX_BRIGHTNESS - 1;
} else
return;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = max_brightness;
sony_bl_props.dev = backlight_device_register("sony", NULL,
&sony_bl_props,
ops, &props);
if (IS_ERR(sony_bl_props.dev)) {
pr_warn("unable to register backlight device\n");
sony_bl_props.dev = NULL;
} else
sony_bl_props.dev->props.brightness =
ops->get_brightness(sony_bl_props.dev);
}
static void sony_nc_backlight_cleanup(void)
{
if (sony_bl_props.dev)
backlight_device_unregister(sony_bl_props.dev);
}
static int sony_nc_add(struct acpi_device *device)
{
acpi_status status;
int result = 0;
acpi_handle handle;
struct sony_nc_value *item;
pr_info("%s v%s\n", SONY_NC_DRIVER_NAME, SONY_LAPTOP_DRIVER_VERSION);
sony_nc_acpi_device = device;
strcpy(acpi_device_class(device), "sony/hotkey");
sony_nc_acpi_handle = device->handle;
result = acpi_bus_get_status(device);
if (!result && !device->status.present) {
dprintk("Device not present\n");
result = -ENODEV;
goto outwalk;
}
result = sony_pf_add();
if (result)
goto outpresent;
if (debug) {
status = acpi_walk_namespace(ACPI_TYPE_METHOD,
sony_nc_acpi_handle, 1, sony_walk_callback,
NULL, NULL, NULL);
if (ACPI_FAILURE(status)) {
pr_warn("unable to walk acpi resources\n");
result = -ENODEV;
goto outpresent;
}
}
result = sony_laptop_setup_input(device);
if (result) {
pr_err("Unable to create input devices\n");
goto outplatform;
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "ECON",
&handle))) {
int arg = 1;
if (sony_nc_int_call(sony_nc_acpi_handle, "ECON", &arg, NULL))
dprintk("ECON Method failed\n");
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "SN00",
&handle))) {
dprintk("Doing SNC setup\n");
result = sony_nc_handles_setup(sony_pf_device);
if (!result)
sony_nc_function_setup(device, sony_pf_device);
}
if (acpi_video_backlight_support()) {
pr_info("brightness ignored, must be controlled by ACPI video driver\n");
} else {
sony_nc_backlight_setup();
}
for (item = sony_nc_values; item->name; ++item) {
if (!debug && item->debug)
continue;
for (; item->acpiget && *item->acpiget; ++item->acpiget) {
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle,
*item->acpiget,
&handle))) {
dprintk("Found %s getter: %s\n",
item->name, *item->acpiget);
item->devattr.attr.mode |= S_IRUGO;
break;
}
}
for (; item->acpiset && *item->acpiset; ++item->acpiset) {
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle,
*item->acpiset,
&handle))) {
dprintk("Found %s setter: %s\n",
item->name, *item->acpiset);
item->devattr.attr.mode |= S_IWUSR;
break;
}
}
if (item->devattr.attr.mode != 0) {
result =
device_create_file(&sony_pf_device->dev,
&item->devattr);
if (result)
goto out_sysfs;
}
}
return 0;
out_sysfs:
for (item = sony_nc_values; item->name; ++item) {
device_remove_file(&sony_pf_device->dev, &item->devattr);
}
sony_nc_backlight_cleanup();
sony_nc_function_cleanup(sony_pf_device);
sony_nc_handles_cleanup(sony_pf_device);
outplatform:
sony_laptop_remove_input();
outpresent:
sony_pf_remove();
outwalk:
sony_nc_rfkill_cleanup();
return result;
}
static int sony_nc_remove(struct acpi_device *device, int type)
{
struct sony_nc_value *item;
sony_nc_backlight_cleanup();
sony_nc_acpi_device = NULL;
for (item = sony_nc_values; item->name; ++item) {
device_remove_file(&sony_pf_device->dev, &item->devattr);
}
sony_nc_function_cleanup(sony_pf_device);
sony_nc_handles_cleanup(sony_pf_device);
sony_pf_remove();
sony_laptop_remove_input();
dprintk(SONY_NC_DRIVER_NAME " removed.\n");
return 0;
}
static u8 sony_pic_call1(u8 dev)
{
u8 v1, v2;
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2,
ITERATIONS_LONG);
outb(dev, spic_dev.cur_ioport->io1.minimum + 4);
v1 = inb_p(spic_dev.cur_ioport->io1.minimum + 4);
v2 = inb_p(spic_dev.cur_ioport->io1.minimum);
dprintk("sony_pic_call1(0x%.2x): 0x%.4x\n", dev, (v2 << 8) | v1);
return v2;
}
static u8 sony_pic_call2(u8 dev, u8 fn)
{
u8 v1;
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2,
ITERATIONS_LONG);
outb(dev, spic_dev.cur_ioport->io1.minimum + 4);
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2,
ITERATIONS_LONG);
outb(fn, spic_dev.cur_ioport->io1.minimum);
v1 = inb_p(spic_dev.cur_ioport->io1.minimum);
dprintk("sony_pic_call2(0x%.2x - 0x%.2x): 0x%.4x\n", dev, fn, v1);
return v1;
}
static u8 sony_pic_call3(u8 dev, u8 fn, u8 v)
{
u8 v1;
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2, ITERATIONS_LONG);
outb(dev, spic_dev.cur_ioport->io1.minimum + 4);
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2, ITERATIONS_LONG);
outb(fn, spic_dev.cur_ioport->io1.minimum);
wait_on_command(inb_p(spic_dev.cur_ioport->io1.minimum + 4) & 2, ITERATIONS_LONG);
outb(v, spic_dev.cur_ioport->io1.minimum);
v1 = inb_p(spic_dev.cur_ioport->io1.minimum);
dprintk("sony_pic_call3(0x%.2x - 0x%.2x - 0x%.2x): 0x%.4x\n",
dev, fn, v, v1);
return v1;
}
static int type3_handle_irq(const u8 data_mask, const u8 ev)
{
if (data_mask == 0x31) {
if (ev == 0x5c || ev == 0x5f)
sony_pic_call1(0xA0);
else if (ev == 0x61)
sony_pic_call1(0xB3);
return 0;
}
return 1;
}
static void sony_pic_detect_device_type(struct sony_pic_dev *dev)
{
struct pci_dev *pcidev;
pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, NULL);
if (pcidev) {
dev->model = SONYPI_DEVICE_TYPE1;
dev->evport_offset = SONYPI_TYPE1_OFFSET;
dev->event_types = type1_events;
goto out;
}
pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH6_1, NULL);
if (pcidev) {
dev->model = SONYPI_DEVICE_TYPE2;
dev->evport_offset = SONYPI_TYPE2_OFFSET;
dev->event_types = type2_events;
goto out;
}
pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH7_1, NULL);
if (pcidev) {
dev->model = SONYPI_DEVICE_TYPE3;
dev->handle_irq = type3_handle_irq;
dev->evport_offset = SONYPI_TYPE3_OFFSET;
dev->event_types = type3_events;
goto out;
}
pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH8_4, NULL);
if (pcidev) {
dev->model = SONYPI_DEVICE_TYPE3;
dev->handle_irq = type3_handle_irq;
dev->evport_offset = SONYPI_TYPE3_OFFSET;
dev->event_types = type3_events;
goto out;
}
pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH9_1, NULL);
if (pcidev) {
dev->model = SONYPI_DEVICE_TYPE3;
dev->handle_irq = type3_handle_irq;
dev->evport_offset = SONYPI_TYPE3_OFFSET;
dev->event_types = type3_events;
goto out;
}
dev->model = SONYPI_DEVICE_TYPE2;
dev->evport_offset = SONYPI_TYPE2_OFFSET;
dev->event_types = type2_events;
out:
if (pcidev)
pci_dev_put(pcidev);
pr_info("detected Type%d model\n",
dev->model == SONYPI_DEVICE_TYPE1 ? 1 :
dev->model == SONYPI_DEVICE_TYPE2 ? 2 : 3);
}
static int __sony_pic_camera_ready(void)
{
u8 v;
v = sony_pic_call2(0x8f, SONYPI_CAMERA_STATUS);
return (v != 0xff && (v & SONYPI_CAMERA_STATUS_READY));
}
static int __sony_pic_camera_off(void)
{
if (!camera) {
pr_warn("camera control not enabled\n");
return -ENODEV;
}
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_PICTURE,
SONYPI_CAMERA_MUTE_MASK),
ITERATIONS_SHORT);
if (spic_dev.camera_power) {
sony_pic_call2(0x91, 0);
spic_dev.camera_power = 0;
}
return 0;
}
static int __sony_pic_camera_on(void)
{
int i, j, x;
if (!camera) {
pr_warn("camera control not enabled\n");
return -ENODEV;
}
if (spic_dev.camera_power)
return 0;
for (j = 5; j > 0; j--) {
for (x = 0; x < 100 && sony_pic_call2(0x91, 0x1); x++)
msleep(10);
sony_pic_call1(0x93);
for (i = 400; i > 0; i--) {
if (__sony_pic_camera_ready())
break;
msleep(10);
}
if (i)
break;
}
if (j == 0) {
pr_warn("failed to power on camera\n");
return -ENODEV;
}
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_CONTROL,
0x5a),
ITERATIONS_SHORT);
spic_dev.camera_power = 1;
return 0;
}
int sony_pic_camera_command(int command, u8 value)
{
if (!camera)
return -EIO;
mutex_lock(&spic_dev.lock);
switch (command) {
case SONY_PIC_COMMAND_SETCAMERA:
if (value)
__sony_pic_camera_on();
else
__sony_pic_camera_off();
break;
case SONY_PIC_COMMAND_SETCAMERABRIGHTNESS:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_BRIGHTNESS, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERACONTRAST:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_CONTRAST, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERAHUE:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_HUE, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERACOLOR:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_COLOR, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERASHARPNESS:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_SHARPNESS, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERAPICTURE:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_PICTURE, value),
ITERATIONS_SHORT);
break;
case SONY_PIC_COMMAND_SETCAMERAAGC:
wait_on_command(sony_pic_call3(0x90, SONYPI_CAMERA_AGC, value),
ITERATIONS_SHORT);
break;
default:
pr_err("sony_pic_camera_command invalid: %d\n", command);
break;
}
mutex_unlock(&spic_dev.lock);
return 0;
}
static void __sony_pic_set_wwanpower(u8 state)
{
state = !!state;
if (spic_dev.wwan_power == state)
return;
sony_pic_call2(0xB0, state);
sony_pic_call1(0x82);
spic_dev.wwan_power = state;
}
static ssize_t sony_pic_wwanpower_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
mutex_lock(&spic_dev.lock);
__sony_pic_set_wwanpower(value);
mutex_unlock(&spic_dev.lock);
return count;
}
static ssize_t sony_pic_wwanpower_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count;
mutex_lock(&spic_dev.lock);
count = snprintf(buffer, PAGE_SIZE, "%d\n", spic_dev.wwan_power);
mutex_unlock(&spic_dev.lock);
return count;
}
static void __sony_pic_set_bluetoothpower(u8 state)
{
state = !!state;
if (spic_dev.bluetooth_power == state)
return;
sony_pic_call2(0x96, state);
sony_pic_call1(0x82);
spic_dev.bluetooth_power = state;
}
static ssize_t sony_pic_bluetoothpower_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
mutex_lock(&spic_dev.lock);
__sony_pic_set_bluetoothpower(value);
mutex_unlock(&spic_dev.lock);
return count;
}
static ssize_t sony_pic_bluetoothpower_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
ssize_t count = 0;
mutex_lock(&spic_dev.lock);
count = snprintf(buffer, PAGE_SIZE, "%d\n", spic_dev.bluetooth_power);
mutex_unlock(&spic_dev.lock);
return count;
}
static int sony_pic_set_fanspeed(unsigned long value)
{
return ec_write(SONY_PIC_FAN0_STATUS, value);
}
static int sony_pic_get_fanspeed(u8 *value)
{
return ec_read(SONY_PIC_FAN0_STATUS, value);
}
static ssize_t sony_pic_fanspeed_store(struct device *dev,
struct device_attribute *attr,
const char *buffer, size_t count)
{
unsigned long value;
if (count > 31)
return -EINVAL;
if (kstrtoul(buffer, 10, &value))
return -EINVAL;
if (sony_pic_set_fanspeed(value))
return -EIO;
return count;
}
static ssize_t sony_pic_fanspeed_show(struct device *dev,
struct device_attribute *attr, char *buffer)
{
u8 value = 0;
if (sony_pic_get_fanspeed(&value))
return -EIO;
return snprintf(buffer, PAGE_SIZE, "%d\n", value);
}
static int sonypi_misc_fasync(int fd, struct file *filp, int on)
{
return fasync_helper(fd, filp, on, &sonypi_compat.fifo_async);
}
static int sonypi_misc_release(struct inode *inode, struct file *file)
{
atomic_dec(&sonypi_compat.open_count);
return 0;
}
static int sonypi_misc_open(struct inode *inode, struct file *file)
{
unsigned long flags;
spin_lock_irqsave(&sonypi_compat.fifo_lock, flags);
if (atomic_inc_return(&sonypi_compat.open_count) == 1)
kfifo_reset(&sonypi_compat.fifo);
spin_unlock_irqrestore(&sonypi_compat.fifo_lock, flags);
return 0;
}
static ssize_t sonypi_misc_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
ssize_t ret;
unsigned char c;
if ((kfifo_len(&sonypi_compat.fifo) == 0) &&
(file->f_flags & O_NONBLOCK))
return -EAGAIN;
ret = wait_event_interruptible(sonypi_compat.fifo_proc_list,
kfifo_len(&sonypi_compat.fifo) != 0);
if (ret)
return ret;
while (ret < count &&
(kfifo_out_locked(&sonypi_compat.fifo, &c, sizeof(c),
&sonypi_compat.fifo_lock) == sizeof(c))) {
if (put_user(c, buf++))
return -EFAULT;
ret++;
}
if (ret > 0) {
struct inode *inode = file->f_path.dentry->d_inode;
inode->i_atime = current_fs_time(inode->i_sb);
}
return ret;
}
static unsigned int sonypi_misc_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &sonypi_compat.fifo_proc_list, wait);
if (kfifo_len(&sonypi_compat.fifo))
return POLLIN | POLLRDNORM;
return 0;
}
static int ec_read16(u8 addr, u16 *value)
{
u8 val_lb, val_hb;
if (ec_read(addr, &val_lb))
return -1;
if (ec_read(addr + 1, &val_hb))
return -1;
*value = val_lb | (val_hb << 8);
return 0;
}
static long sonypi_misc_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
int ret = 0;
void __user *argp = (void __user *)arg;
u8 val8;
u16 val16;
int value;
mutex_lock(&spic_dev.lock);
switch (cmd) {
case SONYPI_IOCGBRT:
if (sony_bl_props.dev == NULL) {
ret = -EIO;
break;
}
if (sony_nc_int_call(sony_nc_acpi_handle, "GBRT", NULL,
&value)) {
ret = -EIO;
break;
}
val8 = ((value & 0xff) - 1) << 5;
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSBRT:
if (sony_bl_props.dev == NULL) {
ret = -EIO;
break;
}
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
value = (val8 >> 5) + 1;
if (sony_nc_int_call(sony_nc_acpi_handle, "SBRT", &value,
NULL)) {
ret = -EIO;
break;
}
sony_bl_props.dev->props.brightness =
sony_backlight_get_brightness(sony_bl_props.dev);
break;
case SONYPI_IOCGBAT1CAP:
if (ec_read16(SONYPI_BAT1_FULL, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT1REM:
if (ec_read16(SONYPI_BAT1_LEFT, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT2CAP:
if (ec_read16(SONYPI_BAT2_FULL, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT2REM:
if (ec_read16(SONYPI_BAT2_LEFT, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBATFLAGS:
if (ec_read(SONYPI_BAT_FLAGS, &val8)) {
ret = -EIO;
break;
}
val8 &= 0x07;
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCGBLUE:
val8 = spic_dev.bluetooth_power;
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSBLUE:
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
__sony_pic_set_bluetoothpower(val8);
break;
case SONYPI_IOCGFAN:
if (sony_pic_get_fanspeed(&val8)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSFAN:
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
if (sony_pic_set_fanspeed(val8))
ret = -EIO;
break;
case SONYPI_IOCGTEMP:
if (ec_read(SONYPI_TEMP_STATUS, &val8)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&spic_dev.lock);
return ret;
}
static void sonypi_compat_report_event(u8 event)
{
kfifo_in_locked(&sonypi_compat.fifo, (unsigned char *)&event,
sizeof(event), &sonypi_compat.fifo_lock);
kill_fasync(&sonypi_compat.fifo_async, SIGIO, POLL_IN);
wake_up_interruptible(&sonypi_compat.fifo_proc_list);
}
static int sonypi_compat_init(void)
{
int error;
spin_lock_init(&sonypi_compat.fifo_lock);
error =
kfifo_alloc(&sonypi_compat.fifo, SONY_LAPTOP_BUF_SIZE, GFP_KERNEL);
if (error) {
pr_err("kfifo_alloc failed\n");
return error;
}
init_waitqueue_head(&sonypi_compat.fifo_proc_list);
if (minor != -1)
sonypi_misc_device.minor = minor;
error = misc_register(&sonypi_misc_device);
if (error) {
pr_err("misc_register failed\n");
goto err_free_kfifo;
}
if (minor == -1)
pr_info("device allocated minor is %d\n",
sonypi_misc_device.minor);
return 0;
err_free_kfifo:
kfifo_free(&sonypi_compat.fifo);
return error;
}
static void sonypi_compat_exit(void)
{
misc_deregister(&sonypi_misc_device);
kfifo_free(&sonypi_compat.fifo);
}
static int sonypi_compat_init(void) { return 0; }
static void sonypi_compat_exit(void) { }
static void sonypi_compat_report_event(u8 event) { }
static acpi_status
sony_pic_read_possible_resource(struct acpi_resource *resource, void *context)
{
u32 i;
struct sony_pic_dev *dev = (struct sony_pic_dev *)context;
switch (resource->type) {
case ACPI_RESOURCE_TYPE_START_DEPENDENT:
{
struct sony_pic_ioport *ioport = kzalloc(sizeof(*ioport), GFP_KERNEL);
if (!ioport)
return AE_ERROR;
list_add(&ioport->list, &dev->ioports);
return AE_OK;
}
case ACPI_RESOURCE_TYPE_END_DEPENDENT:
return AE_OK;
case ACPI_RESOURCE_TYPE_IRQ:
{
struct acpi_resource_irq *p = &resource->data.irq;
struct sony_pic_irq *interrupt = NULL;
if (!p || !p->interrupt_count) {
dprintk("Blank IRQ resource\n");
return AE_OK;
}
for (i = 0; i < p->interrupt_count; i++) {
if (!p->interrupts[i]) {
pr_warn("Invalid IRQ %d\n",
p->interrupts[i]);
continue;
}
interrupt = kzalloc(sizeof(*interrupt),
GFP_KERNEL);
if (!interrupt)
return AE_ERROR;
list_add(&interrupt->list, &dev->interrupts);
interrupt->irq.triggering = p->triggering;
interrupt->irq.polarity = p->polarity;
interrupt->irq.sharable = p->sharable;
interrupt->irq.interrupt_count = 1;
interrupt->irq.interrupts[0] = p->interrupts[i];
}
return AE_OK;
}
case ACPI_RESOURCE_TYPE_IO:
{
struct acpi_resource_io *io = &resource->data.io;
struct sony_pic_ioport *ioport =
list_first_entry(&dev->ioports, struct sony_pic_ioport, list);
if (!io) {
dprintk("Blank IO resource\n");
return AE_OK;
}
if (!ioport->io1.minimum) {
memcpy(&ioport->io1, io, sizeof(*io));
dprintk("IO1 at 0x%.4x (0x%.2x)\n", ioport->io1.minimum,
ioport->io1.address_length);
}
else if (!ioport->io2.minimum) {
memcpy(&ioport->io2, io, sizeof(*io));
dprintk("IO2 at 0x%.4x (0x%.2x)\n", ioport->io2.minimum,
ioport->io2.address_length);
}
else {
pr_err("Unknown SPIC Type, more than 2 IO Ports\n");
return AE_ERROR;
}
return AE_OK;
}
default:
dprintk("Resource %d isn't an IRQ nor an IO port\n",
resource->type);
case ACPI_RESOURCE_TYPE_END_TAG:
return AE_OK;
}
return AE_CTRL_TERMINATE;
}
static int sony_pic_possible_resources(struct acpi_device *device)
{
int result = 0;
acpi_status status = AE_OK;
if (!device)
return -EINVAL;
dprintk("Evaluating _STA\n");
result = acpi_bus_get_status(device);
if (result) {
pr_warn("Unable to read status\n");
goto end;
}
if (!device->status.enabled)
dprintk("Device disabled\n");
else
dprintk("Device enabled\n");
dprintk("Evaluating %s\n", METHOD_NAME__PRS);
status = acpi_walk_resources(device->handle, METHOD_NAME__PRS,
sony_pic_read_possible_resource, &spic_dev);
if (ACPI_FAILURE(status)) {
pr_warn("Failure evaluating %s\n", METHOD_NAME__PRS);
result = -ENODEV;
}
end:
return result;
}
static int sony_pic_disable(struct acpi_device *device)
{
acpi_status ret = acpi_evaluate_object(device->handle, "_DIS", NULL,
NULL);
if (ACPI_FAILURE(ret) && ret != AE_NOT_FOUND)
return -ENXIO;
dprintk("Device disabled\n");
return 0;
}
static int sony_pic_enable(struct acpi_device *device,
struct sony_pic_ioport *ioport, struct sony_pic_irq *irq)
{
acpi_status status;
int result = 0;
struct {
struct acpi_resource res1;
struct acpi_resource res2;
struct acpi_resource res3;
struct acpi_resource res4;
} *resource;
struct acpi_buffer buffer = { 0, NULL };
if (!ioport || !irq)
return -EINVAL;
resource = kzalloc(sizeof(*resource) + 1, GFP_KERNEL);
if (!resource)
return -ENOMEM;
buffer.length = sizeof(*resource) + 1;
buffer.pointer = resource;
if (spic_dev.model == SONYPI_DEVICE_TYPE1) {
resource->res1.type = ACPI_RESOURCE_TYPE_IO;
resource->res1.length = sizeof(struct acpi_resource);
memcpy(&resource->res1.data.io, &ioport->io1,
sizeof(struct acpi_resource_io));
resource->res2.type = ACPI_RESOURCE_TYPE_IO;
resource->res2.length = sizeof(struct acpi_resource);
memcpy(&resource->res2.data.io, &ioport->io2,
sizeof(struct acpi_resource_io));
resource->res3.type = ACPI_RESOURCE_TYPE_IRQ;
resource->res3.length = sizeof(struct acpi_resource);
memcpy(&resource->res3.data.irq, &irq->irq,
sizeof(struct acpi_resource_irq));
resource->res3.data.irq.sharable = ACPI_SHARED;
resource->res4.type = ACPI_RESOURCE_TYPE_END_TAG;
}
else {
resource->res1.type = ACPI_RESOURCE_TYPE_IO;
resource->res1.length = sizeof(struct acpi_resource);
memcpy(&resource->res1.data.io, &ioport->io1,
sizeof(struct acpi_resource_io));
resource->res2.type = ACPI_RESOURCE_TYPE_IRQ;
resource->res2.length = sizeof(struct acpi_resource);
memcpy(&resource->res2.data.irq, &irq->irq,
sizeof(struct acpi_resource_irq));
resource->res2.data.irq.sharable = ACPI_SHARED;
resource->res3.type = ACPI_RESOURCE_TYPE_END_TAG;
}
dprintk("Evaluating _SRS\n");
status = acpi_set_current_resources(device->handle, &buffer);
if (ACPI_FAILURE(status)) {
pr_err("Error evaluating _SRS\n");
result = -ENODEV;
goto end;
}
sony_pic_call1(0x82);
sony_pic_call2(0x81, 0xff);
sony_pic_call1(compat ? 0x92 : 0x82);
end:
kfree(resource);
return result;
}
static irqreturn_t sony_pic_irq(int irq, void *dev_id)
{
int i, j;
u8 ev = 0;
u8 data_mask = 0;
u8 device_event = 0;
struct sony_pic_dev *dev = (struct sony_pic_dev *) dev_id;
ev = inb_p(dev->cur_ioport->io1.minimum);
if (dev->cur_ioport->io2.minimum)
data_mask = inb_p(dev->cur_ioport->io2.minimum);
else
data_mask = inb_p(dev->cur_ioport->io1.minimum +
dev->evport_offset);
dprintk("event ([%.2x] [%.2x]) at port 0x%.4x(+0x%.2x)\n",
ev, data_mask, dev->cur_ioport->io1.minimum,
dev->evport_offset);
if (ev == 0x00 || ev == 0xff)
return IRQ_HANDLED;
for (i = 0; dev->event_types[i].mask; i++) {
if ((data_mask & dev->event_types[i].data) !=
dev->event_types[i].data)
continue;
if (!(mask & dev->event_types[i].mask))
continue;
for (j = 0; dev->event_types[i].events[j].event; j++) {
if (ev == dev->event_types[i].events[j].data) {
device_event =
dev->event_types[i].events[j].event;
if (!device_event)
return IRQ_HANDLED;
goto found;
}
}
}
if (dev->handle_irq && dev->handle_irq(data_mask, ev) == 0)
return IRQ_HANDLED;
dprintk("unknown event ([%.2x] [%.2x]) at port 0x%.4x(+0x%.2x)\n",
ev, data_mask, dev->cur_ioport->io1.minimum,
dev->evport_offset);
return IRQ_HANDLED;
found:
sony_laptop_report_input_event(device_event);
acpi_bus_generate_proc_event(dev->acpi_dev, 1, device_event);
sonypi_compat_report_event(device_event);
return IRQ_HANDLED;
}
static int sony_pic_remove(struct acpi_device *device, int type)
{
struct sony_pic_ioport *io, *tmp_io;
struct sony_pic_irq *irq, *tmp_irq;
if (sony_pic_disable(device)) {
pr_err("Couldn't disable device\n");
return -ENXIO;
}
free_irq(spic_dev.cur_irq->irq.interrupts[0], &spic_dev);
release_region(spic_dev.cur_ioport->io1.minimum,
spic_dev.cur_ioport->io1.address_length);
if (spic_dev.cur_ioport->io2.minimum)
release_region(spic_dev.cur_ioport->io2.minimum,
spic_dev.cur_ioport->io2.address_length);
sonypi_compat_exit();
sony_laptop_remove_input();
sysfs_remove_group(&sony_pf_device->dev.kobj, &spic_attribute_group);
sony_pf_remove();
list_for_each_entry_safe(io, tmp_io, &spic_dev.ioports, list) {
list_del(&io->list);
kfree(io);
}
list_for_each_entry_safe(irq, tmp_irq, &spic_dev.interrupts, list) {
list_del(&irq->list);
kfree(irq);
}
spic_dev.cur_ioport = NULL;
spic_dev.cur_irq = NULL;
dprintk(SONY_PIC_DRIVER_NAME " removed.\n");
return 0;
}
static int sony_pic_add(struct acpi_device *device)
{
int result;
struct sony_pic_ioport *io, *tmp_io;
struct sony_pic_irq *irq, *tmp_irq;
pr_info("%s v%s\n", SONY_PIC_DRIVER_NAME, SONY_LAPTOP_DRIVER_VERSION);
spic_dev.acpi_dev = device;
strcpy(acpi_device_class(device), "sony/hotkey");
sony_pic_detect_device_type(&spic_dev);
mutex_init(&spic_dev.lock);
result = sony_pic_possible_resources(device);
if (result) {
pr_err("Unable to read possible resources\n");
goto err_free_resources;
}
result = sony_laptop_setup_input(device);
if (result) {
pr_err("Unable to create input devices\n");
goto err_free_resources;
}
if (sonypi_compat_init())
goto err_remove_input;
list_for_each_entry_reverse(io, &spic_dev.ioports, list) {
if (request_region(io->io1.minimum, io->io1.address_length,
"Sony Programmable I/O Device")) {
dprintk("I/O port1: 0x%.4x (0x%.4x) + 0x%.2x\n",
io->io1.minimum, io->io1.maximum,
io->io1.address_length);
if (io->io2.minimum) {
if (request_region(io->io2.minimum,
io->io2.address_length,
"Sony Programmable I/O Device")) {
dprintk("I/O port2: 0x%.4x (0x%.4x) + 0x%.2x\n",
io->io2.minimum, io->io2.maximum,
io->io2.address_length);
spic_dev.cur_ioport = io;
break;
}
else {
dprintk("Unable to get I/O port2: "
"0x%.4x (0x%.4x) + 0x%.2x\n",
io->io2.minimum, io->io2.maximum,
io->io2.address_length);
release_region(io->io1.minimum,
io->io1.address_length);
}
}
else {
spic_dev.cur_ioport = io;
break;
}
}
}
if (!spic_dev.cur_ioport) {
pr_err("Failed to request_region\n");
result = -ENODEV;
goto err_remove_compat;
}
list_for_each_entry_reverse(irq, &spic_dev.interrupts, list) {
if (!request_irq(irq->irq.interrupts[0], sony_pic_irq,
0, "sony-laptop", &spic_dev)) {
dprintk("IRQ: %d - triggering: %d - "
"polarity: %d - shr: %d\n",
irq->irq.interrupts[0],
irq->irq.triggering,
irq->irq.polarity,
irq->irq.sharable);
spic_dev.cur_irq = irq;
break;
}
}
if (!spic_dev.cur_irq) {
pr_err("Failed to request_irq\n");
result = -ENODEV;
goto err_release_region;
}
result = sony_pic_enable(device, spic_dev.cur_ioport, spic_dev.cur_irq);
if (result) {
pr_err("Couldn't enable device\n");
goto err_free_irq;
}
spic_dev.bluetooth_power = -1;
result = sony_pf_add();
if (result)
goto err_disable_device;
result = sysfs_create_group(&sony_pf_device->dev.kobj, &spic_attribute_group);
if (result)
goto err_remove_pf;
return 0;
err_remove_pf:
sony_pf_remove();
err_disable_device:
sony_pic_disable(device);
err_free_irq:
free_irq(spic_dev.cur_irq->irq.interrupts[0], &spic_dev);
err_release_region:
release_region(spic_dev.cur_ioport->io1.minimum,
spic_dev.cur_ioport->io1.address_length);
if (spic_dev.cur_ioport->io2.minimum)
release_region(spic_dev.cur_ioport->io2.minimum,
spic_dev.cur_ioport->io2.address_length);
err_remove_compat:
sonypi_compat_exit();
err_remove_input:
sony_laptop_remove_input();
err_free_resources:
list_for_each_entry_safe(io, tmp_io, &spic_dev.ioports, list) {
list_del(&io->list);
kfree(io);
}
list_for_each_entry_safe(irq, tmp_irq, &spic_dev.interrupts, list) {
list_del(&irq->list);
kfree(irq);
}
spic_dev.cur_ioport = NULL;
spic_dev.cur_irq = NULL;
return result;
}
static int sony_pic_suspend(struct acpi_device *device, pm_message_t state)
{
if (sony_pic_disable(device))
return -ENXIO;
return 0;
}
static int sony_pic_resume(struct acpi_device *device)
{
sony_pic_enable(device, spic_dev.cur_ioport, spic_dev.cur_irq);
return 0;
}
static int __init sony_laptop_init(void)
{
int result;
if (!no_spic && dmi_check_system(sonypi_dmi_table)) {
result = acpi_bus_register_driver(&sony_pic_driver);
if (result) {
pr_err("Unable to register SPIC driver\n");
goto out;
}
spic_drv_registered = 1;
}
result = acpi_bus_register_driver(&sony_nc_driver);
if (result) {
pr_err("Unable to register SNC driver\n");
goto out_unregister_pic;
}
return 0;
out_unregister_pic:
if (spic_drv_registered)
acpi_bus_unregister_driver(&sony_pic_driver);
out:
return result;
}
static void __exit sony_laptop_exit(void)
{
acpi_bus_unregister_driver(&sony_nc_driver);
if (spic_drv_registered)
acpi_bus_unregister_driver(&sony_pic_driver);
}
