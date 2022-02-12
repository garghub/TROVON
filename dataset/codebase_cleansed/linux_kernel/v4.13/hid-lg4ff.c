static s32 lg4ff_adjust_dfp_x_axis(s32 value, u16 range)
{
u16 max_range;
s32 new_value;
if (range == 900)
return value;
else if (range == 200)
return value;
else if (range < 200)
max_range = 200;
else
max_range = 900;
new_value = 8192 + mult_frac(value - 8192, max_range, range);
if (new_value < 0)
return 0;
else if (new_value > 16383)
return 16383;
else
return new_value;
}
int lg4ff_adjust_input_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, s32 value, struct lg_drv_data *drv_data)
{
struct lg4ff_device_entry *entry = drv_data->device_props;
s32 new_value = 0;
if (!entry) {
hid_err(hid, "Device properties not found");
return 0;
}
switch (entry->wdata.product_id) {
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
switch (usage->code) {
case ABS_X:
new_value = lg4ff_adjust_dfp_x_axis(value, entry->wdata.range);
input_event(field->hidinput->input, usage->type, usage->code, new_value);
return 1;
default:
return 0;
}
default:
return 0;
}
}
int lg4ff_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *rd, int size, struct lg_drv_data *drv_data)
{
int offset;
struct lg4ff_device_entry *entry = drv_data->device_props;
if (!entry)
return 0;
if (entry->wdata.combine) {
switch (entry->wdata.product_id) {
case USB_DEVICE_ID_LOGITECH_WHEEL:
rd[5] = rd[3];
rd[6] = 0x7F;
return 1;
case USB_DEVICE_ID_LOGITECH_WINGMAN_FFG:
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL:
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL2:
rd[4] = rd[3];
rd[5] = 0x7F;
return 1;
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
rd[5] = rd[4];
rd[6] = 0x7F;
return 1;
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
case USB_DEVICE_ID_LOGITECH_G27_WHEEL:
offset = 5;
break;
case USB_DEVICE_ID_LOGITECH_DFGT_WHEEL:
case USB_DEVICE_ID_LOGITECH_G29_WHEEL:
offset = 6;
break;
case USB_DEVICE_ID_LOGITECH_WII_WHEEL:
offset = 3;
break;
default:
return 0;
}
rd[offset] = (0xFF + rd[offset] - rd[offset+1]) >> 1;
rd[offset+1] = 0x7F;
return 1;
}
return 0;
}
static void lg4ff_init_wheel_data(struct lg4ff_wheel_data * const wdata, const struct lg4ff_wheel *wheel,
const struct lg4ff_multimode_wheel *mmode_wheel,
const u16 real_product_id)
{
u32 alternate_modes = 0;
const char *real_tag = NULL;
const char *real_name = NULL;
if (mmode_wheel) {
alternate_modes = mmode_wheel->alternate_modes;
real_tag = mmode_wheel->real_tag;
real_name = mmode_wheel->real_name;
}
{
struct lg4ff_wheel_data t_wdata = { .product_id = wheel->product_id,
.real_product_id = real_product_id,
.combine = 0,
.min_range = wheel->min_range,
.max_range = wheel->max_range,
.set_range = wheel->set_range,
.alternate_modes = alternate_modes,
.real_tag = real_tag,
.real_name = real_name };
memcpy(wdata, &t_wdata, sizeof(t_wdata));
}
}
static int lg4ff_play(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
s32 *value;
int x;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return -EINVAL;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return -EINVAL;
}
value = entry->report->field[0]->value;
#define CLAMP(x) do { if (x < 0) x = 0; else if (x > 0xff) x = 0xff; } while (0)
switch (effect->type) {
case FF_CONSTANT:
x = effect->u.ramp.start_level + 0x80;
CLAMP(x);
spin_lock_irqsave(&entry->report_lock, flags);
if (x == 0x80) {
value[0] = 0x13;
value[1] = 0x00;
value[2] = 0x00;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
return 0;
}
value[0] = 0x11;
value[1] = 0x08;
value[2] = x;
value[3] = 0x80;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
break;
}
return 0;
}
static void lg4ff_set_autocenter_default(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
s32 *value = report->field[0]->value;
u32 expand_a, expand_b;
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return;
}
value = entry->report->field[0]->value;
spin_lock_irqsave(&entry->report_lock, flags);
if (magnitude == 0) {
value[0] = 0xf5;
value[1] = 0x00;
value[2] = 0x00;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
return;
}
if (magnitude <= 0xaaaa) {
expand_a = 0x0c * magnitude;
expand_b = 0x80 * magnitude;
} else {
expand_a = (0x0c * 0xaaaa) + 0x06 * (magnitude - 0xaaaa);
expand_b = (0x80 * 0xaaaa) + 0xff * (magnitude - 0xaaaa);
}
switch (entry->wdata.product_id) {
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL:
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL2:
break;
default:
expand_a = expand_a >> 1;
break;
}
value[0] = 0xfe;
value[1] = 0x0d;
value[2] = expand_a / 0xaaaa;
value[3] = expand_a / 0xaaaa;
value[4] = expand_b / 0xaaaa;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
value[0] = 0x14;
value[1] = 0x00;
value[2] = 0x00;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
}
static void lg4ff_set_autocenter_ffex(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
s32 *value;
magnitude = magnitude * 90 / 65535;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return;
}
value = entry->report->field[0]->value;
spin_lock_irqsave(&entry->report_lock, flags);
value[0] = 0xfe;
value[1] = 0x03;
value[2] = magnitude >> 14;
value[3] = magnitude >> 14;
value[4] = magnitude;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
}
static void lg4ff_set_range_g25(struct hid_device *hid, u16 range)
{
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
s32 *value;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return;
}
value = entry->report->field[0]->value;
dbg_hid("G25/G27/DFGT: setting range to %u\n", range);
spin_lock_irqsave(&entry->report_lock, flags);
value[0] = 0xf8;
value[1] = 0x81;
value[2] = range & 0x00ff;
value[3] = (range & 0xff00) >> 8;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
}
static void lg4ff_set_range_dfp(struct hid_device *hid, u16 range)
{
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
int start_left, start_right, full_range;
s32 *value;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return;
}
value = entry->report->field[0]->value;
dbg_hid("Driving Force Pro: setting range to %u\n", range);
spin_lock_irqsave(&entry->report_lock, flags);
value[0] = 0xf8;
value[1] = 0x00;
value[2] = 0x00;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
if (range > 200) {
value[1] = 0x03;
full_range = 900;
} else {
value[1] = 0x02;
full_range = 200;
}
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
value[0] = 0x81;
value[1] = 0x0b;
value[2] = 0x00;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
if (range == 200 || range == 900) {
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
return;
}
start_left = (((full_range - range + 1) * 2047) / full_range);
start_right = 0xfff - start_left;
value[2] = start_left >> 4;
value[3] = start_right >> 4;
value[4] = 0xff;
value[5] = (start_right & 0xe) << 4 | (start_left & 0xe);
value[6] = 0xff;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
}
static const struct lg4ff_compat_mode_switch *lg4ff_get_mode_switch_command(const u16 real_product_id, const u16 target_product_id)
{
switch (real_product_id) {
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
switch (target_product_id) {
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
return &lg4ff_mode_switch_ext01_dfp;
default:
return NULL;
}
break;
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
switch (target_product_id) {
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
return &lg4ff_mode_switch_ext01_dfp;
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
return &lg4ff_mode_switch_ext16_g25;
default:
return NULL;
}
break;
case USB_DEVICE_ID_LOGITECH_G27_WHEEL:
switch (target_product_id) {
case USB_DEVICE_ID_LOGITECH_WHEEL:
return &lg4ff_mode_switch_ext09_dfex;
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
return &lg4ff_mode_switch_ext09_dfp;
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
return &lg4ff_mode_switch_ext09_g25;
case USB_DEVICE_ID_LOGITECH_G27_WHEEL:
return &lg4ff_mode_switch_ext09_g27;
default:
return NULL;
}
break;
case USB_DEVICE_ID_LOGITECH_G29_WHEEL:
switch (target_product_id) {
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
return &lg4ff_mode_switch_ext09_dfp;
case USB_DEVICE_ID_LOGITECH_DFGT_WHEEL:
return &lg4ff_mode_switch_ext09_dfgt;
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
return &lg4ff_mode_switch_ext09_g25;
case USB_DEVICE_ID_LOGITECH_G27_WHEEL:
return &lg4ff_mode_switch_ext09_g27;
case USB_DEVICE_ID_LOGITECH_G29_WHEEL:
return &lg4ff_mode_switch_ext09_g29;
default:
return NULL;
}
break;
case USB_DEVICE_ID_LOGITECH_DFGT_WHEEL:
switch (target_product_id) {
case USB_DEVICE_ID_LOGITECH_WHEEL:
return &lg4ff_mode_switch_ext09_dfex;
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
return &lg4ff_mode_switch_ext09_dfp;
case USB_DEVICE_ID_LOGITECH_DFGT_WHEEL:
return &lg4ff_mode_switch_ext09_dfgt;
default:
return NULL;
}
break;
default:
return NULL;
}
}
static int lg4ff_switch_compatibility_mode(struct hid_device *hid, const struct lg4ff_compat_mode_switch *s)
{
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
unsigned long flags;
s32 *value;
u8 i;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return -EINVAL;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return -EINVAL;
}
value = entry->report->field[0]->value;
spin_lock_irqsave(&entry->report_lock, flags);
for (i = 0; i < s->cmd_count; i++) {
u8 j;
for (j = 0; j < 7; j++)
value[j] = s->cmd[j + (7*i)];
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
}
spin_unlock_irqrestore(&entry->report_lock, flags);
hid_hw_wait(hid);
return 0;
}
static ssize_t lg4ff_alternate_modes_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
ssize_t count = 0;
int i;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
if (!entry->wdata.real_name) {
hid_err(hid, "NULL pointer to string\n");
return 0;
}
for (i = 0; i < LG4FF_MODE_MAX_IDX; i++) {
if (entry->wdata.alternate_modes & BIT(i)) {
count += scnprintf(buf + count, PAGE_SIZE - count, "%s: %s",
lg4ff_alternate_modes[i].tag,
!lg4ff_alternate_modes[i].product_id ? entry->wdata.real_name : lg4ff_alternate_modes[i].name);
if (count >= PAGE_SIZE - 1)
return count;
if (lg4ff_alternate_modes[i].product_id == entry->wdata.product_id ||
(lg4ff_alternate_modes[i].product_id == 0 && entry->wdata.product_id == entry->wdata.real_product_id))
count += scnprintf(buf + count, PAGE_SIZE - count, " *\n");
else
count += scnprintf(buf + count, PAGE_SIZE - count, "\n");
if (count >= PAGE_SIZE - 1)
return count;
}
}
return count;
}
static ssize_t lg4ff_alternate_modes_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
const struct lg4ff_compat_mode_switch *s;
u16 target_product_id = 0;
int i, ret;
char *lbuf;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return -EINVAL;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return -EINVAL;
}
lbuf = kasprintf(GFP_KERNEL, "%s", buf);
if (!lbuf)
return -ENOMEM;
i = strlen(lbuf);
if (lbuf[i-1] == '\n') {
if (i == 1) {
kfree(lbuf);
return -EINVAL;
}
lbuf[i-1] = '\0';
}
for (i = 0; i < LG4FF_MODE_MAX_IDX; i++) {
const u16 mode_product_id = lg4ff_alternate_modes[i].product_id;
const char *tag = lg4ff_alternate_modes[i].tag;
if (entry->wdata.alternate_modes & BIT(i)) {
if (!strcmp(tag, lbuf)) {
if (!mode_product_id)
target_product_id = entry->wdata.real_product_id;
else
target_product_id = mode_product_id;
break;
}
}
}
if (i == LG4FF_MODE_MAX_IDX) {
hid_info(hid, "Requested mode \"%s\" is not supported by the device\n", lbuf);
kfree(lbuf);
return -EINVAL;
}
kfree(lbuf);
if (target_product_id == entry->wdata.product_id)
return count;
if (target_product_id == USB_DEVICE_ID_LOGITECH_WHEEL && !lg4ff_no_autoswitch) {
hid_info(hid, "\"%s\" cannot be switched to \"DF-EX\" mode. Load the \"hid_logitech\" module with \"lg4ff_no_autoswitch=1\" parameter set and try again\n",
entry->wdata.real_name);
return -EINVAL;
}
if ((entry->wdata.real_product_id == USB_DEVICE_ID_LOGITECH_DFP_WHEEL || entry->wdata.real_product_id == USB_DEVICE_ID_LOGITECH_G25_WHEEL) &&
entry->wdata.product_id > target_product_id) {
hid_info(hid, "\"%s\" cannot be switched back into \"%s\" mode\n", entry->wdata.real_name, lg4ff_alternate_modes[i].name);
return -EINVAL;
}
s = lg4ff_get_mode_switch_command(entry->wdata.real_product_id, target_product_id);
if (!s) {
hid_err(hid, "Invalid target product ID %X\n", target_product_id);
return -EINVAL;
}
ret = lg4ff_switch_compatibility_mode(hid, s);
return (ret == 0 ? count : ret);
}
static ssize_t lg4ff_combine_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
size_t count;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
count = scnprintf(buf, PAGE_SIZE, "%u\n", entry->wdata.combine);
return count;
}
static ssize_t lg4ff_combine_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
u16 combine = simple_strtoul(buf, NULL, 10);
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return -EINVAL;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return -EINVAL;
}
if (combine > 1)
combine = 1;
entry->wdata.combine = combine;
return count;
}
static ssize_t lg4ff_range_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
size_t count;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
count = scnprintf(buf, PAGE_SIZE, "%u\n", entry->wdata.range);
return count;
}
static ssize_t lg4ff_range_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
u16 range = simple_strtoul(buf, NULL, 10);
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return -EINVAL;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return -EINVAL;
}
if (range == 0)
range = entry->wdata.max_range;
if (entry->wdata.set_range && range >= entry->wdata.min_range && range <= entry->wdata.max_range) {
entry->wdata.set_range(hid, range);
entry->wdata.range = range;
}
return count;
}
static ssize_t lg4ff_real_id_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
size_t count;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
if (!entry->wdata.real_tag || !entry->wdata.real_name) {
hid_err(hid, "NULL pointer to string\n");
return 0;
}
count = scnprintf(buf, PAGE_SIZE, "%s: %s\n", entry->wdata.real_tag, entry->wdata.real_name);
return count;
}
static ssize_t lg4ff_real_id_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
return -EPERM;
}
static void lg4ff_set_leds(struct hid_device *hid, u8 leds)
{
struct lg_drv_data *drv_data;
struct lg4ff_device_entry *entry;
unsigned long flags;
s32 *value;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return;
}
value = entry->report->field[0]->value;
spin_lock_irqsave(&entry->report_lock, flags);
value[0] = 0xf8;
value[1] = 0x12;
value[2] = leds;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hid, entry->report, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&entry->report_lock, flags);
}
static void lg4ff_led_set_brightness(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct lg_drv_data *drv_data = hid_get_drvdata(hid);
struct lg4ff_device_entry *entry;
int i, state = 0;
if (!drv_data) {
hid_err(hid, "Device data not found.");
return;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found.");
return;
}
for (i = 0; i < 5; i++) {
if (led_cdev != entry->wdata.led[i])
continue;
state = (entry->wdata.led_state >> i) & 1;
if (value == LED_OFF && state) {
entry->wdata.led_state &= ~(1 << i);
lg4ff_set_leds(hid, entry->wdata.led_state);
} else if (value != LED_OFF && !state) {
entry->wdata.led_state |= 1 << i;
lg4ff_set_leds(hid, entry->wdata.led_state);
}
break;
}
}
static enum led_brightness lg4ff_led_get_brightness(struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct lg_drv_data *drv_data = hid_get_drvdata(hid);
struct lg4ff_device_entry *entry;
int i, value = 0;
if (!drv_data) {
hid_err(hid, "Device data not found.");
return LED_OFF;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found.");
return LED_OFF;
}
for (i = 0; i < 5; i++)
if (led_cdev == entry->wdata.led[i]) {
value = (entry->wdata.led_state >> i) & 1;
break;
}
return value ? LED_FULL : LED_OFF;
}
static u16 lg4ff_identify_multimode_wheel(struct hid_device *hid, const u16 reported_product_id, const u16 bcdDevice)
{
u32 current_mode;
int i;
for (i = 1; i < ARRAY_SIZE(lg4ff_alternate_modes); i++) {
dbg_hid("Testing whether PID is %X\n", lg4ff_alternate_modes[i].product_id);
if (reported_product_id == lg4ff_alternate_modes[i].product_id)
break;
}
if (i == ARRAY_SIZE(lg4ff_alternate_modes))
return 0;
current_mode = BIT(i);
for (i = 0; i < ARRAY_SIZE(lg4ff_main_checklist); i++) {
const u16 mask = lg4ff_main_checklist[i]->mask;
const u16 result = lg4ff_main_checklist[i]->result;
const u16 real_product_id = lg4ff_main_checklist[i]->real_product_id;
if ((current_mode & lg4ff_main_checklist[i]->modes) && \
(bcdDevice & mask) == result) {
dbg_hid("Found wheel with real PID %X whose reported PID is %X\n", real_product_id, reported_product_id);
return real_product_id;
}
}
dbg_hid("Wheel with bcdDevice %X was not recognized as multimode wheel, leaving in its current mode\n", bcdDevice);
return 0;
}
static int lg4ff_handle_multimode_wheel(struct hid_device *hid, u16 *real_product_id, const u16 bcdDevice)
{
const u16 reported_product_id = hid->product;
int ret;
*real_product_id = lg4ff_identify_multimode_wheel(hid, reported_product_id, bcdDevice);
if (!*real_product_id) {
*real_product_id = reported_product_id;
dbg_hid("Wheel is not a multimode wheel\n");
return LG4FF_MMODE_NOT_MULTIMODE;
}
if (reported_product_id == USB_DEVICE_ID_LOGITECH_WHEEL &&
reported_product_id != *real_product_id &&
!lg4ff_no_autoswitch) {
const struct lg4ff_compat_mode_switch *s = lg4ff_get_mode_switch_command(*real_product_id, *real_product_id);
if (!s) {
hid_err(hid, "Invalid product id %X\n", *real_product_id);
return LG4FF_MMODE_NOT_MULTIMODE;
}
ret = lg4ff_switch_compatibility_mode(hid, s);
if (ret) {
hid_err(hid, "Unable to switch wheel mode, errno %d\n", ret);
return LG4FF_MMODE_IS_MULTIMODE;
}
return LG4FF_MMODE_SWITCHED;
}
return LG4FF_MMODE_IS_MULTIMODE;
}
int lg4ff_init(struct hid_device *hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct input_dev *dev = hidinput->input;
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
const struct usb_device_descriptor *udesc = &(hid_to_usb_dev(hid)->descriptor);
const u16 bcdDevice = le16_to_cpu(udesc->bcdDevice);
const struct lg4ff_multimode_wheel *mmode_wheel = NULL;
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
int error, i, j;
int mmode_ret, mmode_idx = -1;
u16 real_product_id;
if (!hid_validate_values(hid, HID_OUTPUT_REPORT, 0, 0, 7))
return -1;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Cannot add device, private driver data not allocated\n");
return -1;
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
spin_lock_init(&entry->report_lock);
entry->report = report;
drv_data->device_props = entry;
mmode_ret = lg4ff_handle_multimode_wheel(hid, &real_product_id, bcdDevice);
if (mmode_ret == LG4FF_MMODE_SWITCHED)
return 0;
else if (mmode_ret < 0) {
hid_err(hid, "Unable to switch device mode during initialization, errno %d\n", mmode_ret);
error = mmode_ret;
goto err_init;
}
for (i = 0; i < ARRAY_SIZE(lg4ff_devices); i++) {
if (hid->product == lg4ff_devices[i].product_id) {
dbg_hid("Found compatible device, product ID %04X\n", lg4ff_devices[i].product_id);
break;
}
}
if (i == ARRAY_SIZE(lg4ff_devices)) {
hid_err(hid, "This device is flagged to be handled by the lg4ff module but this module does not know how to handle it. "
"Please report this as a bug to LKML, Simon Wood <simon@mungewell.org> or "
"Michal Maly <madcatxster@devoid-pointer.net>\n");
error = -1;
goto err_init;
}
if (mmode_ret == LG4FF_MMODE_IS_MULTIMODE) {
for (mmode_idx = 0; mmode_idx < ARRAY_SIZE(lg4ff_multimode_wheels); mmode_idx++) {
if (real_product_id == lg4ff_multimode_wheels[mmode_idx].product_id)
break;
}
if (mmode_idx == ARRAY_SIZE(lg4ff_multimode_wheels)) {
hid_err(hid, "Device product ID %X is not listed as a multimode wheel", real_product_id);
error = -1;
goto err_init;
}
}
for (j = 0; lg4ff_devices[i].ff_effects[j] >= 0; j++)
set_bit(lg4ff_devices[i].ff_effects[j], dev->ffbit);
error = input_ff_create_memless(dev, NULL, lg4ff_play);
if (error)
goto err_init;
if (mmode_ret == LG4FF_MMODE_IS_MULTIMODE) {
BUG_ON(mmode_idx == -1);
mmode_wheel = &lg4ff_multimode_wheels[mmode_idx];
}
lg4ff_init_wheel_data(&entry->wdata, &lg4ff_devices[i], mmode_wheel, real_product_id);
if (test_bit(FF_AUTOCENTER, dev->ffbit)) {
if ((bcdDevice >> 8) == LG4FF_FFEX_REV_MAJ &&
(bcdDevice & 0xff) == LG4FF_FFEX_REV_MIN)
dev->ff->set_autocenter = lg4ff_set_autocenter_ffex;
else
dev->ff->set_autocenter = lg4ff_set_autocenter_default;
dev->ff->set_autocenter(dev, 0);
}
error = device_create_file(&hid->dev, &dev_attr_combine_pedals);
if (error)
hid_warn(hid, "Unable to create sysfs interface for \"combine\", errno %d\n", error);
error = device_create_file(&hid->dev, &dev_attr_range);
if (error)
hid_warn(hid, "Unable to create sysfs interface for \"range\", errno %d\n", error);
if (mmode_ret == LG4FF_MMODE_IS_MULTIMODE) {
error = device_create_file(&hid->dev, &dev_attr_real_id);
if (error)
hid_warn(hid, "Unable to create sysfs interface for \"real_id\", errno %d\n", error);
error = device_create_file(&hid->dev, &dev_attr_alternate_modes);
if (error)
hid_warn(hid, "Unable to create sysfs interface for \"alternate_modes\", errno %d\n", error);
}
dbg_hid("sysfs interface created\n");
entry->wdata.range = entry->wdata.max_range;
if (entry->wdata.set_range)
entry->wdata.set_range(hid, entry->wdata.range);
#ifdef CONFIG_LEDS_CLASS
entry->wdata.led_state = 0;
for (j = 0; j < 5; j++)
entry->wdata.led[j] = NULL;
if (lg4ff_devices[i].product_id == USB_DEVICE_ID_LOGITECH_G27_WHEEL ||
lg4ff_devices[i].product_id == USB_DEVICE_ID_LOGITECH_G29_WHEEL) {
struct led_classdev *led;
size_t name_sz;
char *name;
lg4ff_set_leds(hid, 0);
name_sz = strlen(dev_name(&hid->dev)) + 8;
for (j = 0; j < 5; j++) {
led = kzalloc(sizeof(struct led_classdev)+name_sz, GFP_KERNEL);
if (!led) {
hid_err(hid, "can't allocate memory for LED %d\n", j);
goto err_leds;
}
name = (void *)(&led[1]);
snprintf(name, name_sz, "%s::RPM%d", dev_name(&hid->dev), j+1);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = lg4ff_led_get_brightness;
led->brightness_set = lg4ff_led_set_brightness;
entry->wdata.led[j] = led;
error = led_classdev_register(&hid->dev, led);
if (error) {
hid_err(hid, "failed to register LED %d. Aborting.\n", j);
err_leds:
for (j = 0; j < 5; j++) {
led = entry->wdata.led[j];
entry->wdata.led[j] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
goto out;
}
}
}
out:
#endif
hid_info(hid, "Force feedback support for Logitech Gaming Wheels\n");
return 0;
err_init:
drv_data->device_props = NULL;
kfree(entry);
return error;
}
int lg4ff_deinit(struct hid_device *hid)
{
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Error while deinitializing device, no private driver data.\n");
return -1;
}
entry = drv_data->device_props;
if (!entry)
goto out;
if (entry->wdata.alternate_modes) {
device_remove_file(&hid->dev, &dev_attr_real_id);
device_remove_file(&hid->dev, &dev_attr_alternate_modes);
}
device_remove_file(&hid->dev, &dev_attr_combine_pedals);
device_remove_file(&hid->dev, &dev_attr_range);
#ifdef CONFIG_LEDS_CLASS
{
int j;
struct led_classdev *led;
for (j = 0; j < 5; j++) {
led = entry->wdata.led[j];
entry->wdata.led[j] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
}
#endif
hid_hw_stop(hid);
drv_data->device_props = NULL;
kfree(entry);
out:
dbg_hid("Device successfully unregistered\n");
return 0;
}
