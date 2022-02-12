static int acpi_video_get_brightness(struct backlight_device *bd)
{
unsigned long long cur_level;
int i;
struct acpi_video_device *vd = bl_get_data(bd);
if (acpi_video_device_lcd_get_level_current(vd, &cur_level, false))
return -EINVAL;
for (i = 2; i < vd->brightness->count; i++) {
if (vd->brightness->levels[i] == cur_level)
return i - 2;
}
return 0;
}
static int acpi_video_set_brightness(struct backlight_device *bd)
{
int request_level = bd->props.brightness + 2;
struct acpi_video_device *vd = bl_get_data(bd);
cancel_delayed_work(&vd->switch_brightness_work);
return acpi_video_device_lcd_set_level(vd,
vd->brightness->levels[request_level]);
}
static int video_get_max_state(struct thermal_cooling_device *cooling_dev, unsigned
long *state)
{
struct acpi_device *device = cooling_dev->devdata;
struct acpi_video_device *video = acpi_driver_data(device);
*state = video->brightness->count - 3;
return 0;
}
static int video_get_cur_state(struct thermal_cooling_device *cooling_dev, unsigned
long *state)
{
struct acpi_device *device = cooling_dev->devdata;
struct acpi_video_device *video = acpi_driver_data(device);
unsigned long long level;
int offset;
if (acpi_video_device_lcd_get_level_current(video, &level, false))
return -EINVAL;
for (offset = 2; offset < video->brightness->count; offset++)
if (level == video->brightness->levels[offset]) {
*state = video->brightness->count - offset - 1;
return 0;
}
return -EINVAL;
}
static int
video_set_cur_state(struct thermal_cooling_device *cooling_dev, unsigned long state)
{
struct acpi_device *device = cooling_dev->devdata;
struct acpi_video_device *video = acpi_driver_data(device);
int level;
if (state >= video->brightness->count - 2)
return -EINVAL;
state = video->brightness->count - state;
level = video->brightness->levels[state - 1];
return acpi_video_device_lcd_set_level(video, level);
}
static int
acpi_video_device_lcd_query_levels(acpi_handle handle,
union acpi_object **levels)
{
int status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
*levels = NULL;
status = acpi_evaluate_object(handle, "_BCL", NULL, &buffer);
if (!ACPI_SUCCESS(status))
return status;
obj = (union acpi_object *)buffer.pointer;
if (!obj || (obj->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_ERR PREFIX "Invalid _BCL data\n");
status = -EFAULT;
goto err;
}
*levels = obj;
return 0;
err:
kfree(buffer.pointer);
return status;
}
static int
acpi_video_device_lcd_set_level(struct acpi_video_device *device, int level)
{
int status;
int state;
status = acpi_execute_simple_method(device->dev->handle,
"_BCM", level);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO, "Evaluating _BCM failed"));
return -EIO;
}
device->brightness->curr = level;
for (state = 2; state < device->brightness->count; state++)
if (level == device->brightness->levels[state]) {
if (device->backlight)
device->backlight->props.brightness = state - 2;
return 0;
}
ACPI_ERROR((AE_INFO, "Current brightness invalid"));
return -EINVAL;
}
static int video_set_bqc_offset(const struct dmi_system_id *d)
{
bqc_offset_aml_bug_workaround = 9;
return 0;
}
static int video_disable_backlight_sysfs_if(
const struct dmi_system_id *d)
{
if (disable_backlight_sysfs_if == -1)
disable_backlight_sysfs_if = 1;
return 0;
}
static int video_set_device_id_scheme(const struct dmi_system_id *d)
{
device_id_scheme = true;
return 0;
}
static int video_enable_only_lcd(const struct dmi_system_id *d)
{
only_lcd = true;
return 0;
}
static int video_set_report_key_events(const struct dmi_system_id *id)
{
if (report_key_events == -1)
report_key_events = (uintptr_t)id->driver_data;
return 0;
}
static unsigned long long
acpi_video_bqc_value_to_level(struct acpi_video_device *device,
unsigned long long bqc_value)
{
unsigned long long level;
if (device->brightness->flags._BQC_use_index) {
if (device->brightness->flags._BCL_reversed)
bqc_value = device->brightness->count - 3 - bqc_value;
level = device->brightness->levels[bqc_value + 2];
} else {
level = bqc_value;
}
level += bqc_offset_aml_bug_workaround;
return level;
}
static int
acpi_video_device_lcd_get_level_current(struct acpi_video_device *device,
unsigned long long *level, bool raw)
{
acpi_status status = AE_OK;
int i;
if (device->cap._BQC || device->cap._BCQ) {
char *buf = device->cap._BQC ? "_BQC" : "_BCQ";
status = acpi_evaluate_integer(device->dev->handle, buf,
NULL, level);
if (ACPI_SUCCESS(status)) {
if (raw) {
return 0;
}
*level = acpi_video_bqc_value_to_level(device, *level);
for (i = 2; i < device->brightness->count; i++)
if (device->brightness->levels[i] == *level) {
device->brightness->curr = *level;
return 0;
}
ACPI_WARNING((AE_INFO,
"%s returned an invalid level",
buf));
device->cap._BQC = device->cap._BCQ = 0;
} else {
ACPI_WARNING((AE_INFO, "Evaluating %s failed", buf));
device->cap._BQC = device->cap._BCQ = 0;
}
}
*level = device->brightness->curr;
return 0;
}
static int
acpi_video_device_EDID(struct acpi_video_device *device,
union acpi_object **edid, ssize_t length)
{
int status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
union acpi_object arg0 = { ACPI_TYPE_INTEGER };
struct acpi_object_list args = { 1, &arg0 };
*edid = NULL;
if (!device)
return -ENODEV;
if (length == 128)
arg0.integer.value = 1;
else if (length == 256)
arg0.integer.value = 2;
else
return -EINVAL;
status = acpi_evaluate_object(device->dev->handle, "_DDC", &args, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
obj = buffer.pointer;
if (obj && obj->type == ACPI_TYPE_BUFFER)
*edid = obj;
else {
printk(KERN_ERR PREFIX "Invalid _DDC data\n");
status = -EFAULT;
kfree(obj);
}
return status;
}
static int
acpi_video_bus_DOS(struct acpi_video_bus *video, int bios_flag, int lcd_flag)
{
acpi_status status;
if (!video->cap._DOS)
return 0;
if (bios_flag < 0 || bios_flag > 3 || lcd_flag < 0 || lcd_flag > 1)
return -EINVAL;
video->dos_setting = (lcd_flag << 2) | bios_flag;
status = acpi_execute_simple_method(video->device->handle, "_DOS",
(lcd_flag << 2) | bios_flag);
if (ACPI_FAILURE(status))
return -EIO;
return 0;
}
static int
acpi_video_cmp_level(const void *a, const void *b)
{
return *(int *)a - *(int *)b;
}
static int acpi_video_bqc_quirk(struct acpi_video_device *device,
int max_level, int current_level)
{
struct acpi_video_device_brightness *br = device->brightness;
int result;
unsigned long long level;
int test_level;
if (bqc_offset_aml_bug_workaround)
return 0;
test_level = current_level == max_level ? br->levels[3] : max_level;
result = acpi_video_device_lcd_set_level(device, test_level);
if (result)
return result;
result = acpi_video_device_lcd_get_level_current(device, &level, true);
if (result)
return result;
if (level != test_level) {
if (level < br->count) {
if (br->flags._BCL_reversed)
level = br->count - 3 - level;
if (br->levels[level + 2] == test_level)
br->flags._BQC_use_index = 1;
}
if (!br->flags._BQC_use_index)
device->cap._BQC = device->cap._BCQ = 0;
}
return 0;
}
int acpi_video_get_levels(struct acpi_device *device,
struct acpi_video_device_brightness **dev_br,
int *pmax_level)
{
union acpi_object *obj = NULL;
int i, max_level = 0, count = 0, level_ac_battery = 0;
union acpi_object *o;
struct acpi_video_device_brightness *br = NULL;
int result = 0;
u32 value;
if (!ACPI_SUCCESS(acpi_video_device_lcd_query_levels(device->handle,
&obj))) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Could not query available "
"LCD brightness level\n"));
result = -ENODEV;
goto out;
}
if (obj->package.count < 2) {
result = -EINVAL;
goto out;
}
br = kzalloc(sizeof(*br), GFP_KERNEL);
if (!br) {
printk(KERN_ERR "can't allocate memory\n");
result = -ENOMEM;
goto out;
}
br->levels = kmalloc((obj->package.count + 2) * sizeof *(br->levels),
GFP_KERNEL);
if (!br->levels) {
result = -ENOMEM;
goto out_free;
}
for (i = 0; i < obj->package.count; i++) {
o = (union acpi_object *)&obj->package.elements[i];
if (o->type != ACPI_TYPE_INTEGER) {
printk(KERN_ERR PREFIX "Invalid data\n");
continue;
}
value = (u32) o->integer.value;
if (count > 2 && br->levels[count - 1] == value)
continue;
br->levels[count] = value;
if (br->levels[count] > max_level)
max_level = br->levels[count];
count++;
}
for (i = 2; i < count; i++) {
if (br->levels[i] == br->levels[0])
level_ac_battery++;
if (br->levels[i] == br->levels[1])
level_ac_battery++;
}
if (level_ac_battery < 2) {
level_ac_battery = 2 - level_ac_battery;
br->flags._BCL_no_ac_battery_levels = 1;
for (i = (count - 1 + level_ac_battery); i >= 2; i--)
br->levels[i] = br->levels[i - level_ac_battery];
count += level_ac_battery;
} else if (level_ac_battery > 2)
ACPI_ERROR((AE_INFO, "Too many duplicates in _BCL package"));
if (max_level == br->levels[2]) {
br->flags._BCL_reversed = 1;
sort(&br->levels[2], count - 2, sizeof(br->levels[2]),
acpi_video_cmp_level, NULL);
} else if (max_level != br->levels[count - 1])
ACPI_ERROR((AE_INFO,
"Found unordered _BCL package"));
br->count = count;
*dev_br = br;
if (pmax_level)
*pmax_level = max_level;
out:
kfree(obj);
return result;
out_free:
kfree(br);
goto out;
}
static int
acpi_video_init_brightness(struct acpi_video_device *device)
{
int i, max_level = 0;
unsigned long long level, level_old;
struct acpi_video_device_brightness *br = NULL;
int result = -EINVAL;
result = acpi_video_get_levels(device->dev, &br, &max_level);
if (result)
return result;
device->brightness = br;
br->curr = level = max_level;
if (!device->cap._BQC)
goto set_level;
result = acpi_video_device_lcd_get_level_current(device,
&level_old, true);
if (result)
goto out_free_levels;
result = acpi_video_bqc_quirk(device, max_level, level_old);
if (result)
goto out_free_levels;
if (!device->cap._BQC)
goto set_level;
level = acpi_video_bqc_value_to_level(device, level_old);
for (i = 2; i < br->count; i++)
if (level == br->levels[i])
break;
if (i == br->count || !level)
level = max_level;
set_level:
result = acpi_video_device_lcd_set_level(device, level);
if (result)
goto out_free_levels;
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"found %d brightness levels\n", br->count - 2));
return 0;
out_free_levels:
kfree(br->levels);
kfree(br);
device->brightness = NULL;
return result;
}
static void acpi_video_device_find_cap(struct acpi_video_device *device)
{
if (acpi_has_method(device->dev->handle, "_ADR"))
device->cap._ADR = 1;
if (acpi_has_method(device->dev->handle, "_BCL"))
device->cap._BCL = 1;
if (acpi_has_method(device->dev->handle, "_BCM"))
device->cap._BCM = 1;
if (acpi_has_method(device->dev->handle, "_BQC")) {
device->cap._BQC = 1;
} else if (acpi_has_method(device->dev->handle, "_BCQ")) {
printk(KERN_WARNING FW_BUG "_BCQ is used instead of _BQC\n");
device->cap._BCQ = 1;
}
if (acpi_has_method(device->dev->handle, "_DDC"))
device->cap._DDC = 1;
}
static void acpi_video_bus_find_cap(struct acpi_video_bus *video)
{
if (acpi_has_method(video->device->handle, "_DOS"))
video->cap._DOS = 1;
if (acpi_has_method(video->device->handle, "_DOD"))
video->cap._DOD = 1;
if (acpi_has_method(video->device->handle, "_ROM"))
video->cap._ROM = 1;
if (acpi_has_method(video->device->handle, "_GPD"))
video->cap._GPD = 1;
if (acpi_has_method(video->device->handle, "_SPD"))
video->cap._SPD = 1;
if (acpi_has_method(video->device->handle, "_VPO"))
video->cap._VPO = 1;
}
static int acpi_video_bus_check(struct acpi_video_bus *video)
{
acpi_status status = -ENOENT;
struct pci_dev *dev;
if (!video)
return -EINVAL;
dev = acpi_get_pci_dev(video->device->handle);
if (!dev)
return -ENODEV;
pci_dev_put(dev);
if (video->cap._DOS || video->cap._DOD) {
if (!video->cap._DOS) {
printk(KERN_WARNING FW_BUG
"ACPI(%s) defines _DOD but not _DOS\n",
acpi_device_bid(video->device));
}
video->flags.multihead = 1;
status = 0;
}
if (video->cap._ROM) {
video->flags.rom = 1;
status = 0;
}
if (video->cap._GPD && video->cap._SPD && video->cap._VPO) {
video->flags.post = 1;
status = 0;
}
return status;
}
static struct acpi_video_device_attrib *
acpi_video_get_device_attr(struct acpi_video_bus *video, unsigned long device_id)
{
struct acpi_video_enumerated_device *ids;
int i;
for (i = 0; i < video->attached_count; i++) {
ids = &video->attached_array[i];
if ((ids->value.int_val & 0xffff) == device_id)
return &ids->value.attrib;
}
return NULL;
}
static int
acpi_video_get_device_type(struct acpi_video_bus *video,
unsigned long device_id)
{
struct acpi_video_enumerated_device *ids;
int i;
for (i = 0; i < video->attached_count; i++) {
ids = &video->attached_array[i];
if ((ids->value.int_val & 0xffff) == device_id)
return ids->value.int_val;
}
return 0;
}
static int
acpi_video_bus_get_one_device(struct acpi_device *device,
struct acpi_video_bus *video)
{
unsigned long long device_id;
int status, device_type;
struct acpi_video_device *data;
struct acpi_video_device_attrib *attribute;
status =
acpi_evaluate_integer(device->handle, "_ADR", NULL, &device_id);
if (ACPI_FAILURE(status))
return 0;
data = kzalloc(sizeof(struct acpi_video_device), GFP_KERNEL);
if (!data)
return -ENOMEM;
strcpy(acpi_device_name(device), ACPI_VIDEO_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_VIDEO_CLASS);
device->driver_data = data;
data->device_id = device_id;
data->video = video;
data->dev = device;
INIT_DELAYED_WORK(&data->switch_brightness_work,
acpi_video_switch_brightness);
attribute = acpi_video_get_device_attr(video, device_id);
if (attribute && (attribute->device_id_scheme || device_id_scheme)) {
switch (attribute->display_type) {
case ACPI_VIDEO_DISPLAY_CRT:
data->flags.crt = 1;
break;
case ACPI_VIDEO_DISPLAY_TV:
data->flags.tvout = 1;
break;
case ACPI_VIDEO_DISPLAY_DVI:
data->flags.dvi = 1;
break;
case ACPI_VIDEO_DISPLAY_LCD:
data->flags.lcd = 1;
break;
default:
data->flags.unknown = 1;
break;
}
if (attribute->bios_can_detect)
data->flags.bios = 1;
} else {
device_type = acpi_video_get_device_type(video, device_id);
switch (device_type & 0xffe2ffff) {
case ACPI_VIDEO_DISPLAY_LEGACY_MONITOR:
data->flags.crt = 1;
break;
case ACPI_VIDEO_DISPLAY_LEGACY_PANEL:
data->flags.lcd = 1;
break;
case ACPI_VIDEO_DISPLAY_LEGACY_TV:
data->flags.tvout = 1;
break;
default:
data->flags.unknown = 1;
}
}
acpi_video_device_bind(video, data);
acpi_video_device_find_cap(data);
mutex_lock(&video->device_list_lock);
list_add_tail(&data->entry, &video->video_device_list);
mutex_unlock(&video->device_list_lock);
return status;
}
static void acpi_video_device_rebind(struct acpi_video_bus *video)
{
struct acpi_video_device *dev;
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry)
acpi_video_device_bind(video, dev);
mutex_unlock(&video->device_list_lock);
}
static void
acpi_video_device_bind(struct acpi_video_bus *video,
struct acpi_video_device *device)
{
struct acpi_video_enumerated_device *ids;
int i;
for (i = 0; i < video->attached_count; i++) {
ids = &video->attached_array[i];
if (device->device_id == (ids->value.int_val & 0xffff)) {
ids->bind_info = device;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "device_bind %d\n", i));
}
}
}
static bool acpi_video_device_in_dod(struct acpi_video_device *device)
{
struct acpi_video_bus *video = device->video;
int i;
if (!video->attached_count || video->child_count > 8)
return true;
for (i = 0; i < video->attached_count; i++) {
if ((video->attached_array[i].value.int_val & 0xfff) ==
(device->device_id & 0xfff))
return true;
}
return false;
}
static int acpi_video_device_enumerate(struct acpi_video_bus *video)
{
int status;
int count;
int i;
struct acpi_video_enumerated_device *active_list;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *dod = NULL;
union acpi_object *obj;
if (!video->cap._DOD)
return AE_NOT_EXIST;
status = acpi_evaluate_object(video->device->handle, "_DOD", NULL, &buffer);
if (!ACPI_SUCCESS(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _DOD"));
return status;
}
dod = buffer.pointer;
if (!dod || (dod->type != ACPI_TYPE_PACKAGE)) {
ACPI_EXCEPTION((AE_INFO, status, "Invalid _DOD data"));
status = -EFAULT;
goto out;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found %d video heads in _DOD\n",
dod->package.count));
active_list = kcalloc(1 + dod->package.count,
sizeof(struct acpi_video_enumerated_device),
GFP_KERNEL);
if (!active_list) {
status = -ENOMEM;
goto out;
}
count = 0;
for (i = 0; i < dod->package.count; i++) {
obj = &dod->package.elements[i];
if (obj->type != ACPI_TYPE_INTEGER) {
printk(KERN_ERR PREFIX
"Invalid _DOD data in element %d\n", i);
continue;
}
active_list[count].value.int_val = obj->integer.value;
active_list[count].bind_info = NULL;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "dod element[%d] = %d\n", i,
(int)obj->integer.value));
count++;
}
kfree(video->attached_array);
video->attached_array = active_list;
video->attached_count = count;
out:
kfree(buffer.pointer);
return status;
}
static int
acpi_video_get_next_level(struct acpi_video_device *device,
u32 level_current, u32 event)
{
int min, max, min_above, max_below, i, l, delta = 255;
max = max_below = 0;
min = min_above = 255;
for (i = 2; i < device->brightness->count; i++) {
l = device->brightness->levels[i];
if (abs(l - level_current) < abs(delta)) {
delta = l - level_current;
if (!delta)
break;
}
}
level_current += delta;
for (i = 2; i < device->brightness->count; i++) {
l = device->brightness->levels[i];
if (l < min)
min = l;
if (l > max)
max = l;
if (l < min_above && l > level_current)
min_above = l;
if (l > max_below && l < level_current)
max_below = l;
}
switch (event) {
case ACPI_VIDEO_NOTIFY_CYCLE_BRIGHTNESS:
return (level_current < max) ? min_above : min;
case ACPI_VIDEO_NOTIFY_INC_BRIGHTNESS:
return (level_current < max) ? min_above : max;
case ACPI_VIDEO_NOTIFY_DEC_BRIGHTNESS:
return (level_current > min) ? max_below : min;
case ACPI_VIDEO_NOTIFY_ZERO_BRIGHTNESS:
case ACPI_VIDEO_NOTIFY_DISPLAY_OFF:
return 0;
default:
return level_current;
}
}
static void
acpi_video_switch_brightness(struct work_struct *work)
{
struct acpi_video_device *device = container_of(to_delayed_work(work),
struct acpi_video_device, switch_brightness_work);
unsigned long long level_current, level_next;
int event = device->switch_brightness_event;
int result = -EINVAL;
if (!device->backlight)
return;
if (!device->brightness)
goto out;
result = acpi_video_device_lcd_get_level_current(device,
&level_current,
false);
if (result)
goto out;
level_next = acpi_video_get_next_level(device, level_current, event);
result = acpi_video_device_lcd_set_level(device, level_next);
if (!result)
backlight_force_update(device->backlight,
BACKLIGHT_UPDATE_HOTKEY);
out:
if (result)
printk(KERN_ERR PREFIX "Failed to switch the brightness\n");
}
int acpi_video_get_edid(struct acpi_device *device, int type, int device_id,
void **edid)
{
struct acpi_video_bus *video;
struct acpi_video_device *video_device;
union acpi_object *buffer = NULL;
acpi_status status;
int i, length;
if (!device || !acpi_driver_data(device))
return -EINVAL;
video = acpi_driver_data(device);
for (i = 0; i < video->attached_count; i++) {
video_device = video->attached_array[i].bind_info;
length = 256;
if (!video_device)
continue;
if (!video_device->cap._DDC)
continue;
if (type) {
switch (type) {
case ACPI_VIDEO_DISPLAY_CRT:
if (!video_device->flags.crt)
continue;
break;
case ACPI_VIDEO_DISPLAY_TV:
if (!video_device->flags.tvout)
continue;
break;
case ACPI_VIDEO_DISPLAY_DVI:
if (!video_device->flags.dvi)
continue;
break;
case ACPI_VIDEO_DISPLAY_LCD:
if (!video_device->flags.lcd)
continue;
break;
}
} else if (video_device->device_id != device_id) {
continue;
}
status = acpi_video_device_EDID(video_device, &buffer, length);
if (ACPI_FAILURE(status) || !buffer ||
buffer->type != ACPI_TYPE_BUFFER) {
length = 128;
status = acpi_video_device_EDID(video_device, &buffer,
length);
if (ACPI_FAILURE(status) || !buffer ||
buffer->type != ACPI_TYPE_BUFFER) {
continue;
}
}
*edid = buffer->buffer.pointer;
return length;
}
return -ENODEV;
}
static int
acpi_video_bus_get_devices(struct acpi_video_bus *video,
struct acpi_device *device)
{
int status = 0;
struct acpi_device *dev;
acpi_video_device_enumerate(video);
list_for_each_entry(dev, &device->children, node) {
status = acpi_video_bus_get_one_device(dev, video);
if (status) {
dev_err(&dev->dev, "Can't attach device\n");
break;
}
video->child_count++;
}
return status;
}
static int acpi_video_bus_start_devices(struct acpi_video_bus *video)
{
return acpi_video_bus_DOS(video, 0,
acpi_osi_is_win8() ? 1 : 0);
}
static int acpi_video_bus_stop_devices(struct acpi_video_bus *video)
{
return acpi_video_bus_DOS(video, 0,
acpi_osi_is_win8() ? 0 : 1);
}
static void acpi_video_bus_notify(struct acpi_device *device, u32 event)
{
struct acpi_video_bus *video = acpi_driver_data(device);
struct input_dev *input;
int keycode = 0;
if (!video || !video->input)
return;
input = video->input;
switch (event) {
case ACPI_VIDEO_NOTIFY_SWITCH:
keycode = KEY_SWITCHVIDEOMODE;
break;
case ACPI_VIDEO_NOTIFY_PROBE:
acpi_video_device_enumerate(video);
acpi_video_device_rebind(video);
keycode = KEY_SWITCHVIDEOMODE;
break;
case ACPI_VIDEO_NOTIFY_CYCLE:
keycode = KEY_SWITCHVIDEOMODE;
break;
case ACPI_VIDEO_NOTIFY_NEXT_OUTPUT:
keycode = KEY_VIDEO_NEXT;
break;
case ACPI_VIDEO_NOTIFY_PREV_OUTPUT:
keycode = KEY_VIDEO_PREV;
break;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
break;
}
if (acpi_notifier_call_chain(device, event, 0))
keycode = 0;
if (keycode && (report_key_events & REPORT_OUTPUT_KEY_EVENTS)) {
input_report_key(input, keycode, 1);
input_sync(input);
input_report_key(input, keycode, 0);
input_sync(input);
}
return;
}
static void brightness_switch_event(struct acpi_video_device *video_device,
u32 event)
{
if (!brightness_switch_enabled)
return;
video_device->switch_brightness_event = event;
schedule_delayed_work(&video_device->switch_brightness_work, HZ / 10);
}
static void acpi_video_device_notify(acpi_handle handle, u32 event, void *data)
{
struct acpi_video_device *video_device = data;
struct acpi_device *device = NULL;
struct acpi_video_bus *bus;
struct input_dev *input;
int keycode = 0;
if (!video_device)
return;
device = video_device->dev;
bus = video_device->video;
input = bus->input;
switch (event) {
case ACPI_VIDEO_NOTIFY_CYCLE_BRIGHTNESS:
brightness_switch_event(video_device, event);
keycode = KEY_BRIGHTNESS_CYCLE;
break;
case ACPI_VIDEO_NOTIFY_INC_BRIGHTNESS:
brightness_switch_event(video_device, event);
keycode = KEY_BRIGHTNESSUP;
break;
case ACPI_VIDEO_NOTIFY_DEC_BRIGHTNESS:
brightness_switch_event(video_device, event);
keycode = KEY_BRIGHTNESSDOWN;
break;
case ACPI_VIDEO_NOTIFY_ZERO_BRIGHTNESS:
brightness_switch_event(video_device, event);
keycode = KEY_BRIGHTNESS_ZERO;
break;
case ACPI_VIDEO_NOTIFY_DISPLAY_OFF:
brightness_switch_event(video_device, event);
keycode = KEY_DISPLAY_OFF;
break;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
break;
}
acpi_notifier_call_chain(device, event, 0);
if (keycode && (report_key_events & REPORT_BRIGHTNESS_KEY_EVENTS)) {
input_report_key(input, keycode, 1);
input_sync(input);
input_report_key(input, keycode, 0);
input_sync(input);
}
return;
}
static int acpi_video_resume(struct notifier_block *nb,
unsigned long val, void *ign)
{
struct acpi_video_bus *video;
struct acpi_video_device *video_device;
int i;
switch (val) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
case PM_RESTORE_PREPARE:
return NOTIFY_DONE;
}
video = container_of(nb, struct acpi_video_bus, pm_nb);
dev_info(&video->device->dev, "Restoring backlight state\n");
for (i = 0; i < video->attached_count; i++) {
video_device = video->attached_array[i].bind_info;
if (video_device && video_device->brightness)
acpi_video_device_lcd_set_level(video_device,
video_device->brightness->curr);
}
return NOTIFY_OK;
}
static acpi_status
acpi_video_bus_match(acpi_handle handle, u32 level, void *context,
void **return_value)
{
struct acpi_device *device = context;
struct acpi_device *sibling;
int result;
if (handle == device->handle)
return AE_CTRL_TERMINATE;
result = acpi_bus_get_device(handle, &sibling);
if (result)
return AE_OK;
if (!strcmp(acpi_device_name(sibling), ACPI_VIDEO_BUS_NAME))
return AE_ALREADY_EXISTS;
return AE_OK;
}
static void acpi_video_dev_register_backlight(struct acpi_video_device *device)
{
struct backlight_properties props;
struct pci_dev *pdev;
acpi_handle acpi_parent;
struct device *parent = NULL;
int result;
static int count;
char *name;
result = acpi_video_init_brightness(device);
if (result)
return;
if (disable_backlight_sysfs_if > 0)
return;
name = kasprintf(GFP_KERNEL, "acpi_video%d", count);
if (!name)
return;
count++;
acpi_get_parent(device->dev->handle, &acpi_parent);
pdev = acpi_get_pci_dev(acpi_parent);
if (pdev) {
parent = &pdev->dev;
pci_dev_put(pdev);
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_FIRMWARE;
props.max_brightness = device->brightness->count - 3;
device->backlight = backlight_device_register(name,
parent,
device,
&acpi_backlight_ops,
&props);
kfree(name);
if (IS_ERR(device->backlight)) {
device->backlight = NULL;
return;
}
device->backlight->props.brightness =
acpi_video_get_brightness(device->backlight);
device->cooling_dev = thermal_cooling_device_register("LCD",
device->dev, &video_cooling_ops);
if (IS_ERR(device->cooling_dev)) {
device->cooling_dev = NULL;
return;
}
dev_info(&device->dev->dev, "registered as cooling_device%d\n",
device->cooling_dev->id);
result = sysfs_create_link(&device->dev->dev.kobj,
&device->cooling_dev->device.kobj,
"thermal_cooling");
if (result)
printk(KERN_ERR PREFIX "Create sysfs link\n");
result = sysfs_create_link(&device->cooling_dev->device.kobj,
&device->dev->dev.kobj, "device");
if (result)
printk(KERN_ERR PREFIX "Create sysfs link\n");
}
static void acpi_video_run_bcl_for_osi(struct acpi_video_bus *video)
{
struct acpi_video_device *dev;
union acpi_object *levels;
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry) {
if (!acpi_video_device_lcd_query_levels(dev->dev->handle, &levels))
kfree(levels);
}
mutex_unlock(&video->device_list_lock);
}
static bool acpi_video_should_register_backlight(struct acpi_video_device *dev)
{
if (!acpi_video_device_in_dod(dev)) {
dev_dbg(&dev->dev->dev, "not in _DOD list, ignore\n");
return false;
}
if (only_lcd)
return dev->flags.lcd;
return true;
}
static int acpi_video_bus_register_backlight(struct acpi_video_bus *video)
{
struct acpi_video_device *dev;
if (video->backlight_registered)
return 0;
acpi_video_run_bcl_for_osi(video);
if (acpi_video_get_backlight_type() != acpi_backlight_video)
return 0;
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry) {
if (acpi_video_should_register_backlight(dev))
acpi_video_dev_register_backlight(dev);
}
mutex_unlock(&video->device_list_lock);
video->backlight_registered = true;
video->pm_nb.notifier_call = acpi_video_resume;
video->pm_nb.priority = 0;
return register_pm_notifier(&video->pm_nb);
}
static void acpi_video_dev_unregister_backlight(struct acpi_video_device *device)
{
if (device->backlight) {
backlight_device_unregister(device->backlight);
device->backlight = NULL;
}
if (device->brightness) {
kfree(device->brightness->levels);
kfree(device->brightness);
device->brightness = NULL;
}
if (device->cooling_dev) {
sysfs_remove_link(&device->dev->dev.kobj, "thermal_cooling");
sysfs_remove_link(&device->cooling_dev->device.kobj, "device");
thermal_cooling_device_unregister(device->cooling_dev);
device->cooling_dev = NULL;
}
}
static int acpi_video_bus_unregister_backlight(struct acpi_video_bus *video)
{
struct acpi_video_device *dev;
int error;
if (!video->backlight_registered)
return 0;
error = unregister_pm_notifier(&video->pm_nb);
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry)
acpi_video_dev_unregister_backlight(dev);
mutex_unlock(&video->device_list_lock);
video->backlight_registered = false;
return error;
}
static void acpi_video_dev_add_notify_handler(struct acpi_video_device *device)
{
acpi_status status;
struct acpi_device *adev = device->dev;
status = acpi_install_notify_handler(adev->handle, ACPI_DEVICE_NOTIFY,
acpi_video_device_notify, device);
if (ACPI_FAILURE(status))
dev_err(&adev->dev, "Error installing notify handler\n");
else
device->flags.notify = 1;
}
static int acpi_video_bus_add_notify_handler(struct acpi_video_bus *video)
{
struct input_dev *input;
struct acpi_video_device *dev;
int error;
video->input = input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto out;
}
error = acpi_video_bus_start_devices(video);
if (error)
goto err_free_input;
snprintf(video->phys, sizeof(video->phys),
"%s/video/input0", acpi_device_hid(video->device));
input->name = acpi_device_name(video->device);
input->phys = video->phys;
input->id.bustype = BUS_HOST;
input->id.product = 0x06;
input->dev.parent = &video->device->dev;
input->evbit[0] = BIT(EV_KEY);
set_bit(KEY_SWITCHVIDEOMODE, input->keybit);
set_bit(KEY_VIDEO_NEXT, input->keybit);
set_bit(KEY_VIDEO_PREV, input->keybit);
set_bit(KEY_BRIGHTNESS_CYCLE, input->keybit);
set_bit(KEY_BRIGHTNESSUP, input->keybit);
set_bit(KEY_BRIGHTNESSDOWN, input->keybit);
set_bit(KEY_BRIGHTNESS_ZERO, input->keybit);
set_bit(KEY_DISPLAY_OFF, input->keybit);
error = input_register_device(input);
if (error)
goto err_stop_dev;
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry)
acpi_video_dev_add_notify_handler(dev);
mutex_unlock(&video->device_list_lock);
return 0;
err_stop_dev:
acpi_video_bus_stop_devices(video);
err_free_input:
input_free_device(input);
video->input = NULL;
out:
return error;
}
static void acpi_video_dev_remove_notify_handler(struct acpi_video_device *dev)
{
if (dev->flags.notify) {
acpi_remove_notify_handler(dev->dev->handle, ACPI_DEVICE_NOTIFY,
acpi_video_device_notify);
dev->flags.notify = 0;
}
}
static void acpi_video_bus_remove_notify_handler(struct acpi_video_bus *video)
{
struct acpi_video_device *dev;
mutex_lock(&video->device_list_lock);
list_for_each_entry(dev, &video->video_device_list, entry)
acpi_video_dev_remove_notify_handler(dev);
mutex_unlock(&video->device_list_lock);
acpi_video_bus_stop_devices(video);
input_unregister_device(video->input);
video->input = NULL;
}
static int acpi_video_bus_put_devices(struct acpi_video_bus *video)
{
struct acpi_video_device *dev, *next;
mutex_lock(&video->device_list_lock);
list_for_each_entry_safe(dev, next, &video->video_device_list, entry) {
list_del(&dev->entry);
kfree(dev);
}
mutex_unlock(&video->device_list_lock);
return 0;
}
static int acpi_video_bus_add(struct acpi_device *device)
{
struct acpi_video_bus *video;
int error;
acpi_status status;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE,
device->parent->handle, 1,
acpi_video_bus_match, NULL,
device, NULL);
if (status == AE_ALREADY_EXISTS) {
printk(KERN_WARNING FW_BUG
"Duplicate ACPI video bus devices for the"
" same VGA controller, please try module "
"parameter \"video.allow_duplicates=1\""
"if the current driver doesn't work.\n");
if (!allow_duplicates)
return -ENODEV;
}
video = kzalloc(sizeof(struct acpi_video_bus), GFP_KERNEL);
if (!video)
return -ENOMEM;
if (!strcmp(device->pnp.bus_id, "VID")) {
if (instance)
device->pnp.bus_id[3] = '0' + instance;
instance++;
}
if (!strcmp(device->pnp.bus_id, "VGA")) {
if (instance)
device->pnp.bus_id[3] = '0' + instance;
instance++;
}
video->device = device;
strcpy(acpi_device_name(device), ACPI_VIDEO_BUS_NAME);
strcpy(acpi_device_class(device), ACPI_VIDEO_CLASS);
device->driver_data = video;
acpi_video_bus_find_cap(video);
error = acpi_video_bus_check(video);
if (error)
goto err_free_video;
mutex_init(&video->device_list_lock);
INIT_LIST_HEAD(&video->video_device_list);
error = acpi_video_bus_get_devices(video, device);
if (error)
goto err_put_video;
printk(KERN_INFO PREFIX "%s [%s] (multi-head: %s rom: %s post: %s)\n",
ACPI_VIDEO_DEVICE_NAME, acpi_device_bid(device),
video->flags.multihead ? "yes" : "no",
video->flags.rom ? "yes" : "no",
video->flags.post ? "yes" : "no");
mutex_lock(&video_list_lock);
list_add_tail(&video->entry, &video_bus_head);
mutex_unlock(&video_list_lock);
acpi_video_bus_register_backlight(video);
acpi_video_bus_add_notify_handler(video);
return 0;
err_put_video:
acpi_video_bus_put_devices(video);
kfree(video->attached_array);
err_free_video:
kfree(video);
device->driver_data = NULL;
return error;
}
static int acpi_video_bus_remove(struct acpi_device *device)
{
struct acpi_video_bus *video = NULL;
if (!device || !acpi_driver_data(device))
return -EINVAL;
video = acpi_driver_data(device);
acpi_video_bus_remove_notify_handler(video);
acpi_video_bus_unregister_backlight(video);
acpi_video_bus_put_devices(video);
mutex_lock(&video_list_lock);
list_del(&video->entry);
mutex_unlock(&video_list_lock);
kfree(video->attached_array);
kfree(video);
return 0;
}
static int __init is_i740(struct pci_dev *dev)
{
if (dev->device == 0x00D1)
return 1;
if (dev->device == 0x7000)
return 1;
return 0;
}
static int __init intel_opregion_present(void)
{
int opregion = 0;
struct pci_dev *dev = NULL;
u32 address;
for_each_pci_dev(dev) {
if ((dev->class >> 8) != PCI_CLASS_DISPLAY_VGA)
continue;
if (dev->vendor != PCI_VENDOR_ID_INTEL)
continue;
if (is_i740(dev))
continue;
pci_read_config_dword(dev, 0xfc, &address);
if (!address)
continue;
opregion = 1;
}
return opregion;
}
int acpi_video_register(void)
{
int ret = 0;
mutex_lock(&register_count_mutex);
if (register_count) {
goto leave;
}
dmi_check_system(video_dmi_table);
ret = acpi_bus_register_driver(&acpi_video_bus);
if (ret)
goto leave;
register_count = 1;
leave:
mutex_unlock(&register_count_mutex);
return ret;
}
void acpi_video_unregister(void)
{
mutex_lock(&register_count_mutex);
if (register_count) {
acpi_bus_unregister_driver(&acpi_video_bus);
register_count = 0;
}
mutex_unlock(&register_count_mutex);
}
void acpi_video_unregister_backlight(void)
{
struct acpi_video_bus *video;
mutex_lock(&register_count_mutex);
if (register_count) {
mutex_lock(&video_list_lock);
list_for_each_entry(video, &video_bus_head, entry)
acpi_video_bus_unregister_backlight(video);
mutex_unlock(&video_list_lock);
}
mutex_unlock(&register_count_mutex);
}
bool acpi_video_handles_brightness_key_presses(void)
{
bool have_video_busses;
mutex_lock(&video_list_lock);
have_video_busses = !list_empty(&video_bus_head);
mutex_unlock(&video_list_lock);
return have_video_busses &&
(report_key_events & REPORT_BRIGHTNESS_KEY_EVENTS);
}
static int __init acpi_video_init(void)
{
if (acpi_disabled)
return 0;
if (intel_opregion_present())
return 0;
return acpi_video_register();
}
static void __exit acpi_video_exit(void)
{
acpi_video_detect_exit();
acpi_video_unregister();
return;
}
