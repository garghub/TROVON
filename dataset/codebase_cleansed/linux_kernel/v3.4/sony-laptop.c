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
static int acpi_callgetfunc(acpi_handle handle, char *name, int *result)
{
struct acpi_buffer output;
union acpi_object out_obj;
acpi_status status;
output.length = sizeof(out_obj);
output.pointer = &out_obj;
status = acpi_evaluate_object(handle, name, NULL, &output);
if ((status == AE_OK) && (out_obj.type == ACPI_TYPE_INTEGER)) {
*result = out_obj.integer.value;
return 0;
}
pr_warn("acpi_callreadfunc failed\n");
return -1;
}
static int acpi_callsetfunc(acpi_handle handle, char *name, int value,
int *result)
{
struct acpi_object_list params;
union acpi_object in_obj;
struct acpi_buffer output;
union acpi_object out_obj;
acpi_status status;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = value;
output.length = sizeof(out_obj);
output.pointer = &out_obj;
status = acpi_evaluate_object(handle, name, &params, &output);
if (status == AE_OK) {
if (result != NULL) {
if (out_obj.type != ACPI_TYPE_INTEGER) {
pr_warn("acpi_evaluate_object bad return type\n");
return -1;
}
*result = out_obj.integer.value;
}
return 0;
}
pr_warn("acpi_evaluate_object failed\n");
return -1;
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
int i;
int result;
handles = kzalloc(sizeof(*handles), GFP_KERNEL);
if (!handles)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(handles->cap); i++) {
if (!acpi_callsetfunc(sony_nc_acpi_handle,
"SN00", i + 0x20, &result)) {
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
if (!handles)
return -1;
for (i = 0; i < 0x10; i++) {
if (handles->cap[i] == handle) {
dprintk("found handle 0x%.4x (offset: 0x%.2x)\n",
handle, i);
return i;
}
}
dprintk("handle 0x%.4x not found\n", handle);
return -1;
}
static int sony_call_snc_handle(int handle, int argument, int *result)
{
int ret = 0;
int offset = sony_find_snc_handle(handle);
if (offset < 0)
return -1;
ret = acpi_callsetfunc(sony_nc_acpi_handle, "SN07", offset | argument,
result);
dprintk("called SN07 with 0x%.4x (result: 0x%.4x)\n", offset | argument,
*result);
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
int value;
struct sony_nc_value *item =
container_of(attr, struct sony_nc_value, devattr);
if (!*item->acpiget)
return -EIO;
if (acpi_callgetfunc(sony_nc_acpi_handle, *item->acpiget, &value) < 0)
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
struct sony_nc_value *item =
container_of(attr, struct sony_nc_value, devattr);
if (!item->acpiset)
return -EIO;
if (count > 31)
return -EINVAL;
value = simple_strtoul(buffer, NULL, 10);
if (item->validate)
value = item->validate(SNC_VALIDATE_IN, value);
if (value < 0)
return value;
if (acpi_callsetfunc(sony_nc_acpi_handle, *item->acpiset, value, NULL) < 0)
return -EIO;
item->value = value;
item->valid = 1;
return count;
}
static int sony_backlight_update_status(struct backlight_device *bd)
{
return acpi_callsetfunc(sony_nc_acpi_handle, "SBRT",
bd->props.brightness + 1, NULL);
}
static int sony_backlight_get_brightness(struct backlight_device *bd)
{
int value;
if (acpi_callgetfunc(sony_nc_acpi_handle, "GBRT", &value))
return 0;
return value - 1;
}
static int sony_nc_get_brightness_ng(struct backlight_device *bd)
{
int result;
struct sony_backlight_props *sdev =
(struct sony_backlight_props *)bl_get_data(bd);
sony_call_snc_handle(sdev->handle, 0x0200, &result);
return (result & 0xff) - sdev->offset;
}
static int sony_nc_update_status_ng(struct backlight_device *bd)
{
int value, result;
struct sony_backlight_props *sdev =
(struct sony_backlight_props *)bl_get_data(bd);
value = bd->props.brightness + sdev->offset;
if (sony_call_snc_handle(sdev->handle, 0x0100 | (value << 16), &result))
return -EIO;
return value;
}
static void sony_nc_notify(struct acpi_device *device, u32 event)
{
u32 ev = event;
if (ev >= 0x90) {
int result;
int key_handle = 0;
ev -= 0x90;
if (sony_find_snc_handle(0x100) == ev)
key_handle = 0x100;
if (sony_find_snc_handle(0x127) == ev)
key_handle = 0x127;
if (key_handle) {
struct sony_nc_event *key_event;
if (sony_call_snc_handle(key_handle, 0x200, &result)) {
dprintk("sony_nc_notify, unable to decode"
" event 0x%.2x 0x%.2x\n", key_handle,
ev);
ev = event;
} else {
ev = result & 0xFF;
if (key_handle == 0x100)
key_event = sony_100_events;
else
key_event = sony_127_events;
for (; key_event->data; key_event++) {
if (key_event->data == ev) {
ev = key_event->event;
break;
}
}
if (!key_event->data)
pr_info("Unknown event: 0x%x 0x%x\n",
key_handle, ev);
else
sony_laptop_report_input_event(ev);
}
} else if (sony_find_snc_handle(sony_rfkill_handle) == ev) {
sony_nc_rfkill_update();
return;
}
} else
sony_laptop_report_input_event(ev);
dprintk("sony_nc_notify, event: 0x%.2x\n", ev);
acpi_bus_generate_proc_event(sony_nc_acpi_device, 1, ev);
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
static int sony_nc_function_setup(struct acpi_device *device)
{
int result;
acpi_callsetfunc(sony_nc_acpi_handle, "SN02", 0xffff, &result);
sony_call_snc_handle(0x0100, 0, &result);
sony_call_snc_handle(0x0101, 0, &result);
sony_call_snc_handle(0x0102, 0x100, &result);
sony_call_snc_handle(0x0127, 0, &result);
return 0;
}
static int sony_nc_resume(struct acpi_device *device)
{
struct sony_nc_value *item;
acpi_handle handle;
for (item = sony_nc_values; item->name; item++) {
int ret;
if (!item->valid)
continue;
ret = acpi_callsetfunc(sony_nc_acpi_handle, *item->acpiset,
item->value, NULL);
if (ret < 0) {
pr_err("%s: %d\n", __func__, ret);
break;
}
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "ECON",
&handle))) {
if (acpi_callsetfunc(sony_nc_acpi_handle, "ECON", 1, NULL))
dprintk("ECON Method failed\n");
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "SN00",
&handle))) {
dprintk("Doing SNC setup\n");
sony_nc_function_setup(device);
}
sony_nc_rfkill_update();
sony_nc_kbd_backlight_resume();
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
argument |= 0xff0000;
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
bool hwblock;
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
sony_call_snc_handle(sony_rfkill_handle, 0x200, &result);
hwblock = !(result & 0x1);
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
!(result & 0xf), false);
}
}
static void sony_nc_rfkill_setup(struct acpi_device *device)
{
int offset;
u8 dev_code, i;
acpi_status status;
struct acpi_object_list params;
union acpi_object in_obj;
union acpi_object *device_enum;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
offset = sony_find_snc_handle(0x124);
if (offset == -1) {
offset = sony_find_snc_handle(0x135);
if (offset == -1)
return;
else
sony_rfkill_handle = 0x135;
} else
sony_rfkill_handle = 0x124;
dprintk("Found rkfill handle: 0x%.4x\n", sony_rfkill_handle);
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = offset;
status = acpi_evaluate_object(sony_nc_acpi_handle, "SN06", &params,
&buffer);
if (ACPI_FAILURE(status)) {
dprintk("Radio device enumeration failed\n");
return;
}
device_enum = (union acpi_object *) buffer.pointer;
if (!device_enum) {
pr_err("No SN06 return object\n");
goto out_no_enum;
}
if (device_enum->type != ACPI_TYPE_BUFFER) {
pr_err("Invalid SN06 return object 0x%.2x\n",
device_enum->type);
goto out_no_enum;
}
for (i = 0; i < device_enum->buffer.length; i++) {
dev_code = *(device_enum->buffer.pointer + i);
if (dev_code == 0xff)
break;
dprintk("Radio devices, looking at 0x%.2x\n", dev_code);
if (dev_code == 0 && !sony_rfkill_devices[SONY_WIFI])
sony_nc_setup_rfkill(device, SONY_WIFI);
if (dev_code == 0x10 && !sony_rfkill_devices[SONY_BLUETOOTH])
sony_nc_setup_rfkill(device, SONY_BLUETOOTH);
if ((0xf0 & dev_code) == 0x20 &&
!sony_rfkill_devices[SONY_WWAN])
sony_nc_setup_rfkill(device, SONY_WWAN);
if (dev_code == 0x30 && !sony_rfkill_devices[SONY_WIMAX])
sony_nc_setup_rfkill(device, SONY_WIMAX);
}
out_no_enum:
kfree(buffer.pointer);
return;
}
static ssize_t __sony_nc_kbd_backlight_mode_set(u8 value)
{
int result;
if (value > 1)
return -EINVAL;
if (sony_call_snc_handle(KBDBL_HANDLER,
(value << 0x10) | SET_MODE, &result))
return -EIO;
sony_call_snc_handle(KBDBL_HANDLER, (value << 0x10) | SET_STATE,
&result);
kbdbl_handle->mode = value;
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
if (strict_strtoul(buffer, 10, &value))
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
count = snprintf(buffer, PAGE_SIZE, "%d\n", kbdbl_handle->mode);
return count;
}
static int __sony_nc_kbd_backlight_timeout_set(u8 value)
{
int result;
if (value > 3)
return -EINVAL;
if (sony_call_snc_handle(KBDBL_HANDLER,
(value << 0x10) | SET_TIMEOUT, &result))
return -EIO;
kbdbl_handle->timeout = value;
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
if (strict_strtoul(buffer, 10, &value))
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
count = snprintf(buffer, PAGE_SIZE, "%d\n", kbdbl_handle->timeout);
return count;
}
static int sony_nc_kbd_backlight_setup(struct platform_device *pd)
{
int result;
if (sony_call_snc_handle(KBDBL_HANDLER, KBDBL_PRESENT, &result))
return 0;
if (!(result & 0x02))
return 0;
kbdbl_handle = kzalloc(sizeof(*kbdbl_handle), GFP_KERNEL);
if (!kbdbl_handle)
return -ENOMEM;
sysfs_attr_init(&kbdbl_handle->mode_attr.attr);
kbdbl_handle->mode_attr.attr.name = "kbd_backlight";
kbdbl_handle->mode_attr.attr.mode = S_IRUGO | S_IWUSR;
kbdbl_handle->mode_attr.show = sony_nc_kbd_backlight_mode_show;
kbdbl_handle->mode_attr.store = sony_nc_kbd_backlight_mode_store;
sysfs_attr_init(&kbdbl_handle->timeout_attr.attr);
kbdbl_handle->timeout_attr.attr.name = "kbd_backlight_timeout";
kbdbl_handle->timeout_attr.attr.mode = S_IRUGO | S_IWUSR;
kbdbl_handle->timeout_attr.show = sony_nc_kbd_backlight_timeout_show;
kbdbl_handle->timeout_attr.store = sony_nc_kbd_backlight_timeout_store;
if (device_create_file(&pd->dev, &kbdbl_handle->mode_attr))
goto outkzalloc;
if (device_create_file(&pd->dev, &kbdbl_handle->timeout_attr))
goto outmode;
__sony_nc_kbd_backlight_mode_set(kbd_backlight);
__sony_nc_kbd_backlight_timeout_set(kbd_backlight_timeout);
return 0;
outmode:
device_remove_file(&pd->dev, &kbdbl_handle->mode_attr);
outkzalloc:
kfree(kbdbl_handle);
kbdbl_handle = NULL;
return -1;
}
static int sony_nc_kbd_backlight_cleanup(struct platform_device *pd)
{
if (kbdbl_handle) {
int result;
device_remove_file(&pd->dev, &kbdbl_handle->mode_attr);
device_remove_file(&pd->dev, &kbdbl_handle->timeout_attr);
sony_call_snc_handle(KBDBL_HANDLER, 0x1000 | SET_MODE, &result);
sony_call_snc_handle(KBDBL_HANDLER, SET_TIMEOUT, &result);
kfree(kbdbl_handle);
}
return 0;
}
static void sony_nc_kbd_backlight_resume(void)
{
int ignore = 0;
if (!kbdbl_handle)
return;
if (kbdbl_handle->mode == 0)
sony_call_snc_handle(KBDBL_HANDLER, SET_MODE, &ignore);
if (kbdbl_handle->timeout != 0)
sony_call_snc_handle(KBDBL_HANDLER,
(kbdbl_handle->timeout << 0x10) | SET_TIMEOUT,
&ignore);
}
static void sony_nc_backlight_ng_read_limits(int handle,
struct sony_backlight_props *props)
{
int offset;
acpi_status status;
u8 brlvl, i;
u8 min = 0xff, max = 0x00;
struct acpi_object_list params;
union acpi_object in_obj;
union acpi_object *lvl_enum;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
props->handle = handle;
props->offset = 0;
props->maxlvl = 0xff;
offset = sony_find_snc_handle(handle);
if (offset < 0)
return;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = offset;
status = acpi_evaluate_object(sony_nc_acpi_handle, "SN06", &params,
&buffer);
if (ACPI_FAILURE(status))
return;
lvl_enum = (union acpi_object *) buffer.pointer;
if (!lvl_enum) {
pr_err("No SN06 return object.");
return;
}
if (lvl_enum->type != ACPI_TYPE_BUFFER) {
pr_err("Invalid SN06 return object 0x%.2x\n",
lvl_enum->type);
goto out_invalid;
}
for (i = 0; i < 9 && i < lvl_enum->buffer.length; i++) {
brlvl = *(lvl_enum->buffer.pointer + i);
dprintk("Brightness level: %d\n", brlvl);
if (!brlvl)
break;
if (brlvl > max)
max = brlvl;
if (brlvl < min)
min = brlvl;
}
props->offset = min;
props->maxlvl = max;
dprintk("Brightness levels: min=%d max=%d\n", props->offset,
props->maxlvl);
out_invalid:
kfree(buffer.pointer);
return;
}
static void sony_nc_backlight_setup(void)
{
acpi_handle unused;
int max_brightness = 0;
const struct backlight_ops *ops = NULL;
struct backlight_properties props;
if (sony_find_snc_handle(0x12f) != -1) {
ops = &sony_backlight_ng_ops;
sony_nc_backlight_ng_read_limits(0x12f, &sony_bl_props);
max_brightness = sony_bl_props.maxlvl - sony_bl_props.offset;
} else if (sony_find_snc_handle(0x137) != -1) {
ops = &sony_backlight_ng_ops;
sony_nc_backlight_ng_read_limits(0x137, &sony_bl_props);
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
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "ECON",
&handle))) {
if (acpi_callsetfunc(sony_nc_acpi_handle, "ECON", 1, NULL))
dprintk("ECON Method failed\n");
}
if (ACPI_SUCCESS(acpi_get_handle(sony_nc_acpi_handle, "SN00",
&handle))) {
dprintk("Doing SNC setup\n");
result = sony_nc_handles_setup(sony_pf_device);
if (result)
goto outpresent;
result = sony_nc_kbd_backlight_setup(sony_pf_device);
if (result)
goto outsnc;
sony_nc_function_setup(device);
sony_nc_rfkill_setup(device);
}
result = sony_laptop_setup_input(device);
if (result) {
pr_err("Unable to create input devices\n");
goto outkbdbacklight;
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
sony_laptop_remove_input();
outkbdbacklight:
sony_nc_kbd_backlight_cleanup(sony_pf_device);
outsnc:
sony_nc_handles_cleanup(sony_pf_device);
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
sony_nc_kbd_backlight_cleanup(sony_pf_device);
sony_nc_handles_cleanup(sony_pf_device);
sony_pf_remove();
sony_laptop_remove_input();
sony_nc_rfkill_cleanup();
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
value = simple_strtoul(buffer, NULL, 10);
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
value = simple_strtoul(buffer, NULL, 10);
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
value = simple_strtoul(buffer, NULL, 10);
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
if (acpi_callgetfunc(sony_nc_acpi_handle, "GBRT", &value)) {
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
if (acpi_callsetfunc(sony_nc_acpi_handle, "SBRT",
(val8 >> 5) + 1, NULL)) {
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
