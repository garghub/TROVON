static void __init set_quirks(void)
{
if (!interface)
return;
if (quirks->mailled)
interface->capability |= ACER_CAP_MAILLED;
if (quirks->brightness)
interface->capability |= ACER_CAP_BRIGHTNESS;
}
static int __init dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static int __init
video_set_backlight_video_vendor(const struct dmi_system_id *d)
{
interface->capability &= ~ACER_CAP_BRIGHTNESS;
pr_info("Brightness must be controlled by generic video driver\n");
return 0;
}
static void __init find_quirks(void)
{
if (!force_series) {
dmi_check_system(acer_quirks);
dmi_check_system(non_acer_quirks);
} else if (force_series == 2490) {
quirks = &quirk_acer_travelmate_2490;
}
if (quirks == NULL)
quirks = &quirk_unknown;
set_quirks();
}
static bool has_cap(u32 cap)
{
if ((interface->capability & cap) != 0)
return 1;
return 0;
}
static acpi_status wmab_execute(struct wmab_args *regbuf,
struct acpi_buffer *result)
{
struct acpi_buffer input;
acpi_status status;
input.length = sizeof(struct wmab_args);
input.pointer = (u8 *)regbuf;
status = wmi_evaluate_method(AMW0_GUID1, 1, 1, &input, result);
return status;
}
static acpi_status AMW0_get_u32(u32 *value, u32 cap)
{
int err;
u8 result;
switch (cap) {
case ACER_CAP_MAILLED:
switch (quirks->mailled) {
default:
err = ec_read(0xA, &result);
if (err)
return AE_ERROR;
*value = (result >> 7) & 0x1;
return AE_OK;
}
break;
case ACER_CAP_WIRELESS:
switch (quirks->wireless) {
case 1:
err = ec_read(0x7B, &result);
if (err)
return AE_ERROR;
*value = result & 0x1;
return AE_OK;
case 2:
err = ec_read(0x71, &result);
if (err)
return AE_ERROR;
*value = result & 0x1;
return AE_OK;
case 3:
err = ec_read(0x78, &result);
if (err)
return AE_ERROR;
*value = result & 0x1;
return AE_OK;
default:
err = ec_read(0xA, &result);
if (err)
return AE_ERROR;
*value = (result >> 2) & 0x1;
return AE_OK;
}
break;
case ACER_CAP_BLUETOOTH:
switch (quirks->bluetooth) {
default:
err = ec_read(0xA, &result);
if (err)
return AE_ERROR;
*value = (result >> 4) & 0x1;
return AE_OK;
}
break;
case ACER_CAP_BRIGHTNESS:
switch (quirks->brightness) {
default:
err = ec_read(0x83, &result);
if (err)
return AE_ERROR;
*value = result;
return AE_OK;
}
break;
default:
return AE_ERROR;
}
return AE_OK;
}
static acpi_status AMW0_set_u32(u32 value, u32 cap)
{
struct wmab_args args;
args.eax = ACER_AMW0_WRITE;
args.ebx = value ? (1<<8) : 0;
args.ecx = args.edx = 0;
switch (cap) {
case ACER_CAP_MAILLED:
if (value > 1)
return AE_BAD_PARAMETER;
args.ebx |= ACER_AMW0_MAILLED_MASK;
break;
case ACER_CAP_WIRELESS:
if (value > 1)
return AE_BAD_PARAMETER;
args.ebx |= ACER_AMW0_WIRELESS_MASK;
break;
case ACER_CAP_BLUETOOTH:
if (value > 1)
return AE_BAD_PARAMETER;
args.ebx |= ACER_AMW0_BLUETOOTH_MASK;
break;
case ACER_CAP_BRIGHTNESS:
if (value > max_brightness)
return AE_BAD_PARAMETER;
switch (quirks->brightness) {
default:
return ec_write(0x83, value);
break;
}
default:
return AE_ERROR;
}
return wmab_execute(&args, NULL);
}
static acpi_status __init AMW0_find_mailled(void)
{
struct wmab_args args;
struct wmab_ret ret;
acpi_status status = AE_OK;
struct acpi_buffer out = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
args.eax = 0x86;
args.ebx = args.ecx = args.edx = 0;
status = wmab_execute(&args, &out);
if (ACPI_FAILURE(status))
return status;
obj = (union acpi_object *) out.pointer;
if (obj && obj->type == ACPI_TYPE_BUFFER &&
obj->buffer.length == sizeof(struct wmab_ret)) {
ret = *((struct wmab_ret *) obj->buffer.pointer);
} else {
kfree(out.pointer);
return AE_ERROR;
}
if (ret.eex & 0x1)
interface->capability |= ACER_CAP_MAILLED;
kfree(out.pointer);
return AE_OK;
}
static int __init AMW0_set_cap_acpi_check_device(void)
{
const struct acpi_device_id *id;
for (id = norfkill_ids; id->id[0]; id++)
if (acpi_dev_found(id->id))
return true;
return false;
}
static acpi_status __init AMW0_set_capabilities(void)
{
struct wmab_args args;
struct wmab_ret ret;
acpi_status status;
struct acpi_buffer out = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
if (wmi_has_guid(AMW0_GUID2)) {
if ((quirks != &quirk_unknown) ||
!AMW0_set_cap_acpi_check_device())
interface->capability |= ACER_CAP_WIRELESS;
return AE_OK;
}
args.eax = ACER_AMW0_WRITE;
args.ecx = args.edx = 0;
args.ebx = 0xa2 << 8;
args.ebx |= ACER_AMW0_WIRELESS_MASK;
status = wmab_execute(&args, &out);
if (ACPI_FAILURE(status))
return status;
obj = out.pointer;
if (obj && obj->type == ACPI_TYPE_BUFFER &&
obj->buffer.length == sizeof(struct wmab_ret)) {
ret = *((struct wmab_ret *) obj->buffer.pointer);
} else {
status = AE_ERROR;
goto out;
}
if (ret.eax & 0x1)
interface->capability |= ACER_CAP_WIRELESS;
args.ebx = 2 << 8;
args.ebx |= ACER_AMW0_BLUETOOTH_MASK;
status = wmab_execute(&args, &out);
if (ACPI_FAILURE(status))
goto out;
obj = (union acpi_object *) out.pointer;
if (obj && obj->type == ACPI_TYPE_BUFFER
&& obj->buffer.length == sizeof(struct wmab_ret)) {
ret = *((struct wmab_ret *) obj->buffer.pointer);
} else {
status = AE_ERROR;
goto out;
}
if (ret.eax & 0x1)
interface->capability |= ACER_CAP_BLUETOOTH;
if (quirks->brightness >= 0)
interface->capability |= ACER_CAP_BRIGHTNESS;
status = AE_OK;
out:
kfree(out.pointer);
return status;
}
static acpi_status
WMI_execute_u32(u32 method_id, u32 in, u32 *out)
{
struct acpi_buffer input = { (acpi_size) sizeof(u32), (void *)(&in) };
struct acpi_buffer result = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
u32 tmp = 0;
acpi_status status;
status = wmi_evaluate_method(WMID_GUID1, 1, method_id, &input, &result);
if (ACPI_FAILURE(status))
return status;
obj = (union acpi_object *) result.pointer;
if (obj) {
if (obj->type == ACPI_TYPE_BUFFER &&
(obj->buffer.length == sizeof(u32) ||
obj->buffer.length == sizeof(u64))) {
tmp = *((u32 *) obj->buffer.pointer);
} else if (obj->type == ACPI_TYPE_INTEGER) {
tmp = (u32) obj->integer.value;
}
}
if (out)
*out = tmp;
kfree(result.pointer);
return status;
}
static acpi_status WMID_get_u32(u32 *value, u32 cap)
{
acpi_status status;
u8 tmp;
u32 result, method_id = 0;
switch (cap) {
case ACER_CAP_WIRELESS:
method_id = ACER_WMID_GET_WIRELESS_METHODID;
break;
case ACER_CAP_BLUETOOTH:
method_id = ACER_WMID_GET_BLUETOOTH_METHODID;
break;
case ACER_CAP_BRIGHTNESS:
method_id = ACER_WMID_GET_BRIGHTNESS_METHODID;
break;
case ACER_CAP_THREEG:
method_id = ACER_WMID_GET_THREEG_METHODID;
break;
case ACER_CAP_MAILLED:
if (quirks->mailled == 1) {
ec_read(0x9f, &tmp);
*value = tmp & 0x1;
return 0;
}
default:
return AE_ERROR;
}
status = WMI_execute_u32(method_id, 0, &result);
if (ACPI_SUCCESS(status))
*value = (u8)result;
return status;
}
static acpi_status WMID_set_u32(u32 value, u32 cap)
{
u32 method_id = 0;
char param;
switch (cap) {
case ACER_CAP_BRIGHTNESS:
if (value > max_brightness)
return AE_BAD_PARAMETER;
method_id = ACER_WMID_SET_BRIGHTNESS_METHODID;
break;
case ACER_CAP_WIRELESS:
if (value > 1)
return AE_BAD_PARAMETER;
method_id = ACER_WMID_SET_WIRELESS_METHODID;
break;
case ACER_CAP_BLUETOOTH:
if (value > 1)
return AE_BAD_PARAMETER;
method_id = ACER_WMID_SET_BLUETOOTH_METHODID;
break;
case ACER_CAP_THREEG:
if (value > 1)
return AE_BAD_PARAMETER;
method_id = ACER_WMID_SET_THREEG_METHODID;
break;
case ACER_CAP_MAILLED:
if (value > 1)
return AE_BAD_PARAMETER;
if (quirks->mailled == 1) {
param = value ? 0x92 : 0x93;
i8042_lock_chip();
i8042_command(&param, 0x1059);
i8042_unlock_chip();
return 0;
}
break;
default:
return AE_ERROR;
}
return WMI_execute_u32(method_id, (u32)value, NULL);
}
static acpi_status wmid3_get_device_status(u32 *value, u16 device)
{
struct wmid3_gds_return_value return_value;
acpi_status status;
union acpi_object *obj;
struct wmid3_gds_get_input_param params = {
.function_num = 0x1,
.hotkey_number = commun_fn_key_number,
.devices = device,
};
struct acpi_buffer input = {
sizeof(struct wmid3_gds_get_input_param),
&params
};
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
status = wmi_evaluate_method(WMID_GUID3, 0, 0x2, &input, &output);
if (ACPI_FAILURE(status))
return status;
obj = output.pointer;
if (!obj)
return AE_ERROR;
else if (obj->type != ACPI_TYPE_BUFFER) {
kfree(obj);
return AE_ERROR;
}
if (obj->buffer.length != 8) {
pr_warn("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return AE_ERROR;
}
return_value = *((struct wmid3_gds_return_value *)obj->buffer.pointer);
kfree(obj);
if (return_value.error_code || return_value.ec_return_value)
pr_warn("Get 0x%x Device Status failed: 0x%x - 0x%x\n",
device,
return_value.error_code,
return_value.ec_return_value);
else
*value = !!(return_value.devices & device);
return status;
}
static acpi_status wmid_v2_get_u32(u32 *value, u32 cap)
{
u16 device;
switch (cap) {
case ACER_CAP_WIRELESS:
device = ACER_WMID3_GDS_WIRELESS;
break;
case ACER_CAP_BLUETOOTH:
device = ACER_WMID3_GDS_BLUETOOTH;
break;
case ACER_CAP_THREEG:
device = ACER_WMID3_GDS_THREEG;
break;
default:
return AE_ERROR;
}
return wmid3_get_device_status(value, device);
}
static acpi_status wmid3_set_device_status(u32 value, u16 device)
{
struct wmid3_gds_return_value return_value;
acpi_status status;
union acpi_object *obj;
u16 devices;
struct wmid3_gds_get_input_param get_params = {
.function_num = 0x1,
.hotkey_number = commun_fn_key_number,
.devices = commun_func_bitmap,
};
struct acpi_buffer get_input = {
sizeof(struct wmid3_gds_get_input_param),
&get_params
};
struct wmid3_gds_set_input_param set_params = {
.function_num = 0x2,
.hotkey_number = commun_fn_key_number,
.devices = commun_func_bitmap,
};
struct acpi_buffer set_input = {
sizeof(struct wmid3_gds_set_input_param),
&set_params
};
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer output2 = { ACPI_ALLOCATE_BUFFER, NULL };
status = wmi_evaluate_method(WMID_GUID3, 0, 0x2, &get_input, &output);
if (ACPI_FAILURE(status))
return status;
obj = output.pointer;
if (!obj)
return AE_ERROR;
else if (obj->type != ACPI_TYPE_BUFFER) {
kfree(obj);
return AE_ERROR;
}
if (obj->buffer.length != 8) {
pr_warn("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return AE_ERROR;
}
return_value = *((struct wmid3_gds_return_value *)obj->buffer.pointer);
kfree(obj);
if (return_value.error_code || return_value.ec_return_value) {
pr_warn("Get Current Device Status failed: 0x%x - 0x%x\n",
return_value.error_code,
return_value.ec_return_value);
return status;
}
devices = return_value.devices;
set_params.devices = (value) ? (devices | device) : (devices & ~device);
status = wmi_evaluate_method(WMID_GUID3, 0, 0x1, &set_input, &output2);
if (ACPI_FAILURE(status))
return status;
obj = output2.pointer;
if (!obj)
return AE_ERROR;
else if (obj->type != ACPI_TYPE_BUFFER) {
kfree(obj);
return AE_ERROR;
}
if (obj->buffer.length != 4) {
pr_warn("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return AE_ERROR;
}
return_value = *((struct wmid3_gds_return_value *)obj->buffer.pointer);
kfree(obj);
if (return_value.error_code || return_value.ec_return_value)
pr_warn("Set Device Status failed: 0x%x - 0x%x\n",
return_value.error_code,
return_value.ec_return_value);
return status;
}
static acpi_status wmid_v2_set_u32(u32 value, u32 cap)
{
u16 device;
switch (cap) {
case ACER_CAP_WIRELESS:
device = ACER_WMID3_GDS_WIRELESS;
break;
case ACER_CAP_BLUETOOTH:
device = ACER_WMID3_GDS_BLUETOOTH;
break;
case ACER_CAP_THREEG:
device = ACER_WMID3_GDS_THREEG;
break;
default:
return AE_ERROR;
}
return wmid3_set_device_status(value, device);
}
static void __init type_aa_dmi_decode(const struct dmi_header *header, void *d)
{
struct hotkey_function_type_aa *type_aa;
if (header->type != 0xAA)
return;
has_type_aa = true;
type_aa = (struct hotkey_function_type_aa *) header;
pr_info("Function bitmap for Communication Button: 0x%x\n",
type_aa->commun_func_bitmap);
commun_func_bitmap = type_aa->commun_func_bitmap;
if (type_aa->commun_func_bitmap & ACER_WMID3_GDS_WIRELESS)
interface->capability |= ACER_CAP_WIRELESS;
if (type_aa->commun_func_bitmap & ACER_WMID3_GDS_THREEG)
interface->capability |= ACER_CAP_THREEG;
if (type_aa->commun_func_bitmap & ACER_WMID3_GDS_BLUETOOTH)
interface->capability |= ACER_CAP_BLUETOOTH;
commun_fn_key_number = type_aa->commun_fn_key_number;
}
static acpi_status __init WMID_set_capabilities(void)
{
struct acpi_buffer out = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *obj;
acpi_status status;
u32 devices;
status = wmi_query_block(WMID_GUID2, 1, &out);
if (ACPI_FAILURE(status))
return status;
obj = (union acpi_object *) out.pointer;
if (obj) {
if (obj->type == ACPI_TYPE_BUFFER &&
(obj->buffer.length == sizeof(u32) ||
obj->buffer.length == sizeof(u64))) {
devices = *((u32 *) obj->buffer.pointer);
} else if (obj->type == ACPI_TYPE_INTEGER) {
devices = (u32) obj->integer.value;
} else {
kfree(out.pointer);
return AE_ERROR;
}
} else {
kfree(out.pointer);
return AE_ERROR;
}
pr_info("Function bitmap for Communication Device: 0x%x\n", devices);
if (devices & 0x07)
interface->capability |= ACER_CAP_WIRELESS;
if (devices & 0x40)
interface->capability |= ACER_CAP_THREEG;
if (devices & 0x10)
interface->capability |= ACER_CAP_BLUETOOTH;
if (!(devices & 0x20))
max_brightness = 0x9;
kfree(out.pointer);
return status;
}
static acpi_status get_u32(u32 *value, u32 cap)
{
acpi_status status = AE_ERROR;
switch (interface->type) {
case ACER_AMW0:
status = AMW0_get_u32(value, cap);
break;
case ACER_AMW0_V2:
if (cap == ACER_CAP_MAILLED) {
status = AMW0_get_u32(value, cap);
break;
}
case ACER_WMID:
status = WMID_get_u32(value, cap);
break;
case ACER_WMID_v2:
if (cap & (ACER_CAP_WIRELESS |
ACER_CAP_BLUETOOTH |
ACER_CAP_THREEG))
status = wmid_v2_get_u32(value, cap);
else if (wmi_has_guid(WMID_GUID2))
status = WMID_get_u32(value, cap);
break;
}
return status;
}
static acpi_status set_u32(u32 value, u32 cap)
{
acpi_status status;
if (interface->capability & cap) {
switch (interface->type) {
case ACER_AMW0:
return AMW0_set_u32(value, cap);
case ACER_AMW0_V2:
if (cap == ACER_CAP_MAILLED)
return AMW0_set_u32(value, cap);
if (cap == ACER_CAP_WIRELESS ||
cap == ACER_CAP_BLUETOOTH) {
status = WMID_set_u32(value, cap);
if (ACPI_FAILURE(status))
return status;
return AMW0_set_u32(value, cap);
}
case ACER_WMID:
return WMID_set_u32(value, cap);
case ACER_WMID_v2:
if (cap & (ACER_CAP_WIRELESS |
ACER_CAP_BLUETOOTH |
ACER_CAP_THREEG))
return wmid_v2_set_u32(value, cap);
else if (wmi_has_guid(WMID_GUID2))
return WMID_set_u32(value, cap);
default:
return AE_BAD_PARAMETER;
}
}
return AE_BAD_PARAMETER;
}
static void __init acer_commandline_init(void)
{
if (mailled >= 0)
set_u32(mailled, ACER_CAP_MAILLED);
if (!has_type_aa && threeg >= 0)
set_u32(threeg, ACER_CAP_THREEG);
if (brightness >= 0)
set_u32(brightness, ACER_CAP_BRIGHTNESS);
}
static void mail_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
set_u32(value, ACER_CAP_MAILLED);
}
static int acer_led_init(struct device *dev)
{
return led_classdev_register(dev, &mail_led);
}
static void acer_led_exit(void)
{
set_u32(LED_OFF, ACER_CAP_MAILLED);
led_classdev_unregister(&mail_led);
}
static int read_brightness(struct backlight_device *bd)
{
u32 value;
get_u32(&value, ACER_CAP_BRIGHTNESS);
return value;
}
static int update_bl_status(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
set_u32(intensity, ACER_CAP_BRIGHTNESS);
return 0;
}
static int acer_backlight_init(struct device *dev)
{
struct backlight_properties props;
struct backlight_device *bd;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = max_brightness;
bd = backlight_device_register("acer-wmi", dev, NULL, &acer_bl_ops,
&props);
if (IS_ERR(bd)) {
pr_err("Could not register Acer backlight device\n");
acer_backlight_device = NULL;
return PTR_ERR(bd);
}
acer_backlight_device = bd;
bd->props.power = FB_BLANK_UNBLANK;
bd->props.brightness = read_brightness(bd);
backlight_update_status(bd);
return 0;
}
static void acer_backlight_exit(void)
{
backlight_device_unregister(acer_backlight_device);
}
static int acer_gsensor_init(void)
{
acpi_status status;
struct acpi_buffer output;
union acpi_object out_obj;
output.length = sizeof(out_obj);
output.pointer = &out_obj;
status = acpi_evaluate_object(gsensor_handle, "_INI", NULL, &output);
if (ACPI_FAILURE(status))
return -1;
return 0;
}
static int acer_gsensor_open(struct input_dev *input)
{
return acer_gsensor_init();
}
static int acer_gsensor_event(void)
{
acpi_status status;
struct acpi_buffer output;
union acpi_object out_obj[5];
if (!has_cap(ACER_CAP_ACCEL))
return -1;
output.length = sizeof(out_obj);
output.pointer = out_obj;
status = acpi_evaluate_object(gsensor_handle, "RDVL", NULL, &output);
if (ACPI_FAILURE(status))
return -1;
if (out_obj->package.count != 4)
return -1;
input_report_abs(acer_wmi_accel_dev, ABS_X,
(s16)out_obj->package.elements[0].integer.value);
input_report_abs(acer_wmi_accel_dev, ABS_Y,
(s16)out_obj->package.elements[1].integer.value);
input_report_abs(acer_wmi_accel_dev, ABS_Z,
(s16)out_obj->package.elements[2].integer.value);
input_sync(acer_wmi_accel_dev);
return 0;
}
static void acer_rfkill_update(struct work_struct *ignored)
{
u32 state;
acpi_status status;
if (has_cap(ACER_CAP_WIRELESS)) {
status = get_u32(&state, ACER_CAP_WIRELESS);
if (ACPI_SUCCESS(status)) {
if (quirks->wireless == 3)
rfkill_set_hw_state(wireless_rfkill, !state);
else
rfkill_set_sw_state(wireless_rfkill, !state);
}
}
if (has_cap(ACER_CAP_BLUETOOTH)) {
status = get_u32(&state, ACER_CAP_BLUETOOTH);
if (ACPI_SUCCESS(status))
rfkill_set_sw_state(bluetooth_rfkill, !state);
}
if (has_cap(ACER_CAP_THREEG) && wmi_has_guid(WMID_GUID3)) {
status = get_u32(&state, ACER_WMID3_GDS_THREEG);
if (ACPI_SUCCESS(status))
rfkill_set_sw_state(threeg_rfkill, !state);
}
schedule_delayed_work(&acer_rfkill_work, round_jiffies_relative(HZ));
}
static int acer_rfkill_set(void *data, bool blocked)
{
acpi_status status;
u32 cap = (unsigned long)data;
if (rfkill_inited) {
status = set_u32(!blocked, cap);
if (ACPI_FAILURE(status))
return -ENODEV;
}
return 0;
}
static struct rfkill *acer_rfkill_register(struct device *dev,
enum rfkill_type type,
char *name, u32 cap)
{
int err;
struct rfkill *rfkill_dev;
u32 state;
acpi_status status;
rfkill_dev = rfkill_alloc(name, dev, type,
&acer_rfkill_ops,
(void *)(unsigned long)cap);
if (!rfkill_dev)
return ERR_PTR(-ENOMEM);
status = get_u32(&state, cap);
err = rfkill_register(rfkill_dev);
if (err) {
rfkill_destroy(rfkill_dev);
return ERR_PTR(err);
}
if (ACPI_SUCCESS(status))
rfkill_set_sw_state(rfkill_dev, !state);
return rfkill_dev;
}
static int acer_rfkill_init(struct device *dev)
{
int err;
if (has_cap(ACER_CAP_WIRELESS)) {
wireless_rfkill = acer_rfkill_register(dev, RFKILL_TYPE_WLAN,
"acer-wireless", ACER_CAP_WIRELESS);
if (IS_ERR(wireless_rfkill)) {
err = PTR_ERR(wireless_rfkill);
goto error_wireless;
}
}
if (has_cap(ACER_CAP_BLUETOOTH)) {
bluetooth_rfkill = acer_rfkill_register(dev,
RFKILL_TYPE_BLUETOOTH, "acer-bluetooth",
ACER_CAP_BLUETOOTH);
if (IS_ERR(bluetooth_rfkill)) {
err = PTR_ERR(bluetooth_rfkill);
goto error_bluetooth;
}
}
if (has_cap(ACER_CAP_THREEG)) {
threeg_rfkill = acer_rfkill_register(dev,
RFKILL_TYPE_WWAN, "acer-threeg",
ACER_CAP_THREEG);
if (IS_ERR(threeg_rfkill)) {
err = PTR_ERR(threeg_rfkill);
goto error_threeg;
}
}
rfkill_inited = true;
if ((ec_raw_mode || !wmi_has_guid(ACERWMID_EVENT_GUID)) &&
has_cap(ACER_CAP_WIRELESS | ACER_CAP_BLUETOOTH | ACER_CAP_THREEG))
schedule_delayed_work(&acer_rfkill_work,
round_jiffies_relative(HZ));
return 0;
error_threeg:
if (has_cap(ACER_CAP_BLUETOOTH)) {
rfkill_unregister(bluetooth_rfkill);
rfkill_destroy(bluetooth_rfkill);
}
error_bluetooth:
if (has_cap(ACER_CAP_WIRELESS)) {
rfkill_unregister(wireless_rfkill);
rfkill_destroy(wireless_rfkill);
}
error_wireless:
return err;
}
static void acer_rfkill_exit(void)
{
if ((ec_raw_mode || !wmi_has_guid(ACERWMID_EVENT_GUID)) &&
has_cap(ACER_CAP_WIRELESS | ACER_CAP_BLUETOOTH | ACER_CAP_THREEG))
cancel_delayed_work_sync(&acer_rfkill_work);
if (has_cap(ACER_CAP_WIRELESS)) {
rfkill_unregister(wireless_rfkill);
rfkill_destroy(wireless_rfkill);
}
if (has_cap(ACER_CAP_BLUETOOTH)) {
rfkill_unregister(bluetooth_rfkill);
rfkill_destroy(bluetooth_rfkill);
}
if (has_cap(ACER_CAP_THREEG)) {
rfkill_unregister(threeg_rfkill);
rfkill_destroy(threeg_rfkill);
}
return;
}
static void acer_wmi_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
struct event_return_value return_value;
acpi_status status;
u16 device_state;
const struct key_entry *key;
u32 scancode;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_warn("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (!obj)
return;
if (obj->type != ACPI_TYPE_BUFFER) {
pr_warn("Unknown response received %d\n", obj->type);
kfree(obj);
return;
}
if (obj->buffer.length != 8) {
pr_warn("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return;
}
return_value = *((struct event_return_value *)obj->buffer.pointer);
kfree(obj);
switch (return_value.function) {
case WMID_HOTKEY_EVENT:
device_state = return_value.device_state;
pr_debug("device state: 0x%x\n", device_state);
key = sparse_keymap_entry_from_scancode(acer_wmi_input_dev,
return_value.key_num);
if (!key) {
pr_warn("Unknown key number - 0x%x\n",
return_value.key_num);
} else {
scancode = return_value.key_num;
switch (key->keycode) {
case KEY_WLAN:
case KEY_BLUETOOTH:
if (has_cap(ACER_CAP_WIRELESS))
rfkill_set_sw_state(wireless_rfkill,
!(device_state & ACER_WMID3_GDS_WIRELESS));
if (has_cap(ACER_CAP_THREEG))
rfkill_set_sw_state(threeg_rfkill,
!(device_state & ACER_WMID3_GDS_THREEG));
if (has_cap(ACER_CAP_BLUETOOTH))
rfkill_set_sw_state(bluetooth_rfkill,
!(device_state & ACER_WMID3_GDS_BLUETOOTH));
break;
case KEY_TOUCHPAD_TOGGLE:
scancode = (device_state & ACER_WMID3_GDS_TOUCHPAD) ?
KEY_TOUCHPAD_ON : KEY_TOUCHPAD_OFF;
}
sparse_keymap_report_event(acer_wmi_input_dev, scancode, 1, true);
}
break;
case WMID_ACCEL_EVENT:
acer_gsensor_event();
break;
default:
pr_warn("Unknown function number - %d - %d\n",
return_value.function, return_value.key_num);
break;
}
}
static acpi_status __init
wmid3_set_lm_mode(struct lm_input_params *params,
struct lm_return_value *return_value)
{
acpi_status status;
union acpi_object *obj;
struct acpi_buffer input = { sizeof(struct lm_input_params), params };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
status = wmi_evaluate_method(WMID_GUID3, 0, 0x1, &input, &output);
if (ACPI_FAILURE(status))
return status;
obj = output.pointer;
if (!obj)
return AE_ERROR;
else if (obj->type != ACPI_TYPE_BUFFER) {
kfree(obj);
return AE_ERROR;
}
if (obj->buffer.length != 4) {
pr_warn("Unknown buffer length %d\n", obj->buffer.length);
kfree(obj);
return AE_ERROR;
}
*return_value = *((struct lm_return_value *)obj->buffer.pointer);
kfree(obj);
return status;
}
static int __init acer_wmi_enable_ec_raw(void)
{
struct lm_return_value return_value;
acpi_status status;
struct lm_input_params params = {
.function_num = 0x1,
.commun_devices = 0xFFFF,
.devices = 0xFFFF,
.lm_status = 0x00,
};
status = wmid3_set_lm_mode(&params, &return_value);
if (return_value.error_code || return_value.ec_return_value)
pr_warn("Enabling EC raw mode failed: 0x%x - 0x%x\n",
return_value.error_code,
return_value.ec_return_value);
else
pr_info("Enabled EC raw mode\n");
return status;
}
static int __init acer_wmi_enable_lm(void)
{
struct lm_return_value return_value;
acpi_status status;
struct lm_input_params params = {
.function_num = 0x1,
.commun_devices = 0xFFFF,
.devices = 0xFFFF,
.lm_status = 0x01,
};
status = wmid3_set_lm_mode(&params, &return_value);
if (return_value.error_code || return_value.ec_return_value)
pr_warn("Enabling Launch Manager failed: 0x%x - 0x%x\n",
return_value.error_code,
return_value.ec_return_value);
return status;
}
static acpi_status __init acer_wmi_get_handle_cb(acpi_handle ah, u32 level,
void *ctx, void **retval)
{
*(acpi_handle *)retval = ah;
return AE_OK;
}
static int __init acer_wmi_get_handle(const char *name, const char *prop,
acpi_handle *ah)
{
acpi_status status;
acpi_handle handle;
BUG_ON(!name || !ah);
handle = NULL;
status = acpi_get_devices(prop, acer_wmi_get_handle_cb,
(void *)name, &handle);
if (ACPI_SUCCESS(status)) {
*ah = handle;
return 0;
} else {
return -ENODEV;
}
}
static int __init acer_wmi_accel_setup(void)
{
int err;
err = acer_wmi_get_handle("SENR", "BST0001", &gsensor_handle);
if (err)
return err;
interface->capability |= ACER_CAP_ACCEL;
acer_wmi_accel_dev = input_allocate_device();
if (!acer_wmi_accel_dev)
return -ENOMEM;
acer_wmi_accel_dev->open = acer_gsensor_open;
acer_wmi_accel_dev->name = "Acer BMA150 accelerometer";
acer_wmi_accel_dev->phys = "wmi/input1";
acer_wmi_accel_dev->id.bustype = BUS_HOST;
acer_wmi_accel_dev->evbit[0] = BIT_MASK(EV_ABS);
input_set_abs_params(acer_wmi_accel_dev, ABS_X, -16384, 16384, 0, 0);
input_set_abs_params(acer_wmi_accel_dev, ABS_Y, -16384, 16384, 0, 0);
input_set_abs_params(acer_wmi_accel_dev, ABS_Z, -16384, 16384, 0, 0);
err = input_register_device(acer_wmi_accel_dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(acer_wmi_accel_dev);
return err;
}
static void acer_wmi_accel_destroy(void)
{
input_unregister_device(acer_wmi_accel_dev);
}
static int __init acer_wmi_input_setup(void)
{
acpi_status status;
int err;
acer_wmi_input_dev = input_allocate_device();
if (!acer_wmi_input_dev)
return -ENOMEM;
acer_wmi_input_dev->name = "Acer WMI hotkeys";
acer_wmi_input_dev->phys = "wmi/input0";
acer_wmi_input_dev->id.bustype = BUS_HOST;
err = sparse_keymap_setup(acer_wmi_input_dev, acer_wmi_keymap, NULL);
if (err)
goto err_free_dev;
status = wmi_install_notify_handler(ACERWMID_EVENT_GUID,
acer_wmi_notify, NULL);
if (ACPI_FAILURE(status)) {
err = -EIO;
goto err_free_keymap;
}
err = input_register_device(acer_wmi_input_dev);
if (err)
goto err_uninstall_notifier;
return 0;
err_uninstall_notifier:
wmi_remove_notify_handler(ACERWMID_EVENT_GUID);
err_free_keymap:
sparse_keymap_free(acer_wmi_input_dev);
err_free_dev:
input_free_device(acer_wmi_input_dev);
return err;
}
static void acer_wmi_input_destroy(void)
{
wmi_remove_notify_handler(ACERWMID_EVENT_GUID);
sparse_keymap_free(acer_wmi_input_dev);
input_unregister_device(acer_wmi_input_dev);
}
static u32 get_wmid_devices(void)
{
struct acpi_buffer out = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *obj;
acpi_status status;
u32 devices = 0;
status = wmi_query_block(WMID_GUID2, 1, &out);
if (ACPI_FAILURE(status))
return 0;
obj = (union acpi_object *) out.pointer;
if (obj) {
if (obj->type == ACPI_TYPE_BUFFER &&
(obj->buffer.length == sizeof(u32) ||
obj->buffer.length == sizeof(u64))) {
devices = *((u32 *) obj->buffer.pointer);
} else if (obj->type == ACPI_TYPE_INTEGER) {
devices = (u32) obj->integer.value;
}
}
kfree(out.pointer);
return devices;
}
static int acer_platform_probe(struct platform_device *device)
{
int err;
if (has_cap(ACER_CAP_MAILLED)) {
err = acer_led_init(&device->dev);
if (err)
goto error_mailled;
}
if (has_cap(ACER_CAP_BRIGHTNESS)) {
err = acer_backlight_init(&device->dev);
if (err)
goto error_brightness;
}
err = acer_rfkill_init(&device->dev);
if (err)
goto error_rfkill;
return err;
error_rfkill:
if (has_cap(ACER_CAP_BRIGHTNESS))
acer_backlight_exit();
error_brightness:
if (has_cap(ACER_CAP_MAILLED))
acer_led_exit();
error_mailled:
return err;
}
static int acer_platform_remove(struct platform_device *device)
{
if (has_cap(ACER_CAP_MAILLED))
acer_led_exit();
if (has_cap(ACER_CAP_BRIGHTNESS))
acer_backlight_exit();
acer_rfkill_exit();
return 0;
}
static int acer_suspend(struct device *dev)
{
u32 value;
struct acer_data *data = &interface->data;
if (!data)
return -ENOMEM;
if (has_cap(ACER_CAP_MAILLED)) {
get_u32(&value, ACER_CAP_MAILLED);
set_u32(LED_OFF, ACER_CAP_MAILLED);
data->mailled = value;
}
if (has_cap(ACER_CAP_BRIGHTNESS)) {
get_u32(&value, ACER_CAP_BRIGHTNESS);
data->brightness = value;
}
return 0;
}
static int acer_resume(struct device *dev)
{
struct acer_data *data = &interface->data;
if (!data)
return -ENOMEM;
if (has_cap(ACER_CAP_MAILLED))
set_u32(data->mailled, ACER_CAP_MAILLED);
if (has_cap(ACER_CAP_BRIGHTNESS))
set_u32(data->brightness, ACER_CAP_BRIGHTNESS);
if (has_cap(ACER_CAP_ACCEL))
acer_gsensor_init();
return 0;
}
static void acer_platform_shutdown(struct platform_device *device)
{
struct acer_data *data = &interface->data;
if (!data)
return;
if (has_cap(ACER_CAP_MAILLED))
set_u32(LED_OFF, ACER_CAP_MAILLED);
}
static void remove_debugfs(void)
{
debugfs_remove(interface->debug.devices);
debugfs_remove(interface->debug.root);
}
static int __init create_debugfs(void)
{
interface->debug.root = debugfs_create_dir("acer-wmi", NULL);
if (!interface->debug.root) {
pr_err("Failed to create debugfs directory");
return -ENOMEM;
}
interface->debug.devices = debugfs_create_u32("devices", S_IRUGO,
interface->debug.root,
&interface->debug.wmid_devices);
if (!interface->debug.devices)
goto error_debugfs;
return 0;
error_debugfs:
remove_debugfs();
return -ENOMEM;
}
static int __init acer_wmi_init(void)
{
int err;
pr_info("Acer Laptop ACPI-WMI Extras\n");
if (dmi_check_system(acer_blacklist)) {
pr_info("Blacklisted hardware detected - not loading\n");
return -ENODEV;
}
find_quirks();
if (wmi_has_guid(AMW0_GUID1) &&
!dmi_check_system(amw0_whitelist) &&
quirks == &quirk_unknown) {
pr_err("Unsupported machine has AMW0_GUID1, unable to load\n");
return -ENODEV;
}
if (wmi_has_guid(AMW0_GUID1) && wmi_has_guid(WMID_GUID1))
interface = &AMW0_V2_interface;
if (!wmi_has_guid(AMW0_GUID1) && wmi_has_guid(WMID_GUID1))
interface = &wmid_interface;
if (wmi_has_guid(WMID_GUID3))
interface = &wmid_v2_interface;
if (interface)
dmi_walk(type_aa_dmi_decode, NULL);
if (wmi_has_guid(WMID_GUID2) && interface) {
if (!has_type_aa && ACPI_FAILURE(WMID_set_capabilities())) {
pr_err("Unable to detect available WMID devices\n");
return -ENODEV;
}
interface->capability |= ACER_CAP_BRIGHTNESS;
} else if (!wmi_has_guid(WMID_GUID2) && interface && !has_type_aa) {
pr_err("No WMID device detection method found\n");
return -ENODEV;
}
if (wmi_has_guid(AMW0_GUID1) && !wmi_has_guid(WMID_GUID1)) {
interface = &AMW0_interface;
if (ACPI_FAILURE(AMW0_set_capabilities())) {
pr_err("Unable to detect available AMW0 devices\n");
return -ENODEV;
}
}
if (wmi_has_guid(AMW0_GUID1))
AMW0_find_mailled();
if (!interface) {
pr_err("No or unsupported WMI interface, unable to load\n");
return -ENODEV;
}
set_quirks();
if (dmi_check_system(video_vendor_dmi_table))
acpi_video_set_dmi_backlight_type(acpi_backlight_vendor);
if (acpi_video_get_backlight_type() != acpi_backlight_vendor)
interface->capability &= ~ACER_CAP_BRIGHTNESS;
if (wmi_has_guid(WMID_GUID3)) {
if (ec_raw_mode) {
if (ACPI_FAILURE(acer_wmi_enable_ec_raw())) {
pr_err("Cannot enable EC raw mode\n");
return -ENODEV;
}
} else if (ACPI_FAILURE(acer_wmi_enable_lm())) {
pr_err("Cannot enable Launch Manager mode\n");
return -ENODEV;
}
} else if (ec_raw_mode) {
pr_info("No WMID EC raw mode enable method\n");
}
if (wmi_has_guid(ACERWMID_EVENT_GUID)) {
err = acer_wmi_input_setup();
if (err)
return err;
}
acer_wmi_accel_setup();
err = platform_driver_register(&acer_platform_driver);
if (err) {
pr_err("Unable to register platform driver\n");
goto error_platform_register;
}
acer_platform_device = platform_device_alloc("acer-wmi", -1);
if (!acer_platform_device) {
err = -ENOMEM;
goto error_device_alloc;
}
err = platform_device_add(acer_platform_device);
if (err)
goto error_device_add;
if (wmi_has_guid(WMID_GUID2)) {
interface->debug.wmid_devices = get_wmid_devices();
err = create_debugfs();
if (err)
goto error_create_debugfs;
}
acer_commandline_init();
return 0;
error_create_debugfs:
platform_device_del(acer_platform_device);
error_device_add:
platform_device_put(acer_platform_device);
error_device_alloc:
platform_driver_unregister(&acer_platform_driver);
error_platform_register:
if (wmi_has_guid(ACERWMID_EVENT_GUID))
acer_wmi_input_destroy();
if (has_cap(ACER_CAP_ACCEL))
acer_wmi_accel_destroy();
return err;
}
static void __exit acer_wmi_exit(void)
{
if (wmi_has_guid(ACERWMID_EVENT_GUID))
acer_wmi_input_destroy();
if (has_cap(ACER_CAP_ACCEL))
acer_wmi_accel_destroy();
remove_debugfs();
platform_device_unregister(acer_platform_device);
platform_driver_unregister(&acer_platform_driver);
pr_info("Acer Laptop WMI Extras unloaded\n");
return;
}
