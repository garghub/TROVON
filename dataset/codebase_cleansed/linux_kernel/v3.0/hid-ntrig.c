static int ntrig_version_string(unsigned char *raw, char *buf)
{
__u8 a = (raw[1] & 0x0e) >> 1;
__u8 b = (raw[0] & 0x3c) >> 2;
__u8 c = ((raw[0] & 0x03) << 3) | ((raw[3] & 0xe0) >> 5);
__u8 d = ((raw[3] & 0x07) << 3) | ((raw[2] & 0xe0) >> 5);
__u8 e = raw[2] & 0x07;
return sprintf(buf, "%u.%u.%u.%u.%u", a, b, c, d, e);
}
static inline int ntrig_get_mode(struct hid_device *hdev)
{
struct hid_report *report = hdev->report_enum[HID_FEATURE_REPORT].
report_id_hash[0x0d];
if (!report)
return -EINVAL;
usbhid_submit_report(hdev, report, USB_DIR_IN);
usbhid_wait_io(hdev);
return (int)report->field[0]->value[0];
}
static inline void ntrig_set_mode(struct hid_device *hdev, const int mode)
{
struct hid_report *report;
__u8 mode_commands[4] = { 0xe, 0xf, 0x1b, 0x10 };
if (mode < 0 || mode > 3)
return;
report = hdev->report_enum[HID_FEATURE_REPORT].
report_id_hash[mode_commands[mode]];
if (!report)
return;
usbhid_submit_report(hdev, report, USB_DIR_IN);
}
static void ntrig_report_version(struct hid_device *hdev)
{
int ret;
char buf[20];
struct usb_device *usb_dev = hid_to_usb_dev(hdev);
unsigned char *data = kmalloc(8, GFP_KERNEL);
if (!data)
goto err_free;
ret = usb_control_msg(usb_dev, usb_rcvctrlpipe(usb_dev, 0),
USB_REQ_CLEAR_FEATURE,
USB_TYPE_CLASS | USB_RECIP_INTERFACE |
USB_DIR_IN,
0x30c, 1, data, 8,
USB_CTRL_SET_TIMEOUT);
if (ret == 8) {
ret = ntrig_version_string(&data[2], buf);
hid_info(hdev, "Firmware version: %s (%02x%02x %02x%02x)\n",
buf, data[2], data[3], data[4], data[5]);
}
err_free:
kfree(data);
}
static ssize_t show_phys_width(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->sensor_physical_width);
}
static ssize_t show_phys_height(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->sensor_physical_height);
}
static ssize_t show_log_width(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->sensor_logical_width);
}
static ssize_t show_log_height(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->sensor_logical_height);
}
static ssize_t show_min_width(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->min_width *
nd->sensor_physical_width /
nd->sensor_logical_width);
}
static ssize_t set_min_width(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > nd->sensor_physical_width)
return -EINVAL;
nd->min_width = val * nd->sensor_logical_width /
nd->sensor_physical_width;
return count;
}
static ssize_t show_min_height(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->min_height *
nd->sensor_physical_height /
nd->sensor_logical_height);
}
static ssize_t set_min_height(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > nd->sensor_physical_height)
return -EINVAL;
nd->min_height = val * nd->sensor_logical_height /
nd->sensor_physical_height;
return count;
}
static ssize_t show_activate_slack(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->activate_slack);
}
static ssize_t set_activate_slack(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > 0x7f)
return -EINVAL;
nd->activate_slack = val;
return count;
}
static ssize_t show_activation_width(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->activation_width *
nd->sensor_physical_width /
nd->sensor_logical_width);
}
static ssize_t set_activation_width(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > nd->sensor_physical_width)
return -EINVAL;
nd->activation_width = val * nd->sensor_logical_width /
nd->sensor_physical_width;
return count;
}
static ssize_t show_activation_height(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", nd->activation_height *
nd->sensor_physical_height /
nd->sensor_logical_height);
}
static ssize_t set_activation_height(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > nd->sensor_physical_height)
return -EINVAL;
nd->activation_height = val * nd->sensor_logical_height /
nd->sensor_physical_height;
return count;
}
static ssize_t show_deactivate_slack(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
return sprintf(buf, "%d\n", -nd->deactivate_slack);
}
static ssize_t set_deactivate_slack(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct ntrig_data *nd = hid_get_drvdata(hdev);
unsigned long val;
if (strict_strtoul(buf, 0, &val))
return -EINVAL;
if (val > 7)
return -EINVAL;
nd->deactivate_slack = -val;
return count;
}
static int ntrig_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct ntrig_data *nd = hid_get_drvdata(hdev);
if (field->physical)
return 0;
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_GENDESK:
switch (usage->hid) {
case HID_GD_X:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_X);
input_set_abs_params(hi->input, ABS_X,
field->logical_minimum,
field->logical_maximum, 0, 0);
if (!nd->sensor_logical_width) {
nd->sensor_logical_width =
field->logical_maximum -
field->logical_minimum;
nd->sensor_physical_width =
field->physical_maximum -
field->physical_minimum;
nd->activation_width = activation_width *
nd->sensor_logical_width /
nd->sensor_physical_width;
nd->min_width = min_width *
nd->sensor_logical_width /
nd->sensor_physical_width;
}
return 1;
case HID_GD_Y:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_Y);
input_set_abs_params(hi->input, ABS_Y,
field->logical_minimum,
field->logical_maximum, 0, 0);
if (!nd->sensor_logical_height) {
nd->sensor_logical_height =
field->logical_maximum -
field->logical_minimum;
nd->sensor_physical_height =
field->physical_maximum -
field->physical_minimum;
nd->activation_height = activation_height *
nd->sensor_logical_height /
nd->sensor_physical_height;
nd->min_height = min_height *
nd->sensor_logical_height /
nd->sensor_physical_height;
}
return 1;
}
return 0;
case HID_UP_DIGITIZER:
switch (usage->hid) {
case HID_DG_CONTACTID:
case HID_DG_INPUTMODE:
case HID_DG_DEVICEINDEX:
case HID_DG_CONTACTMAX:
return -1;
case HID_DG_WIDTH:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MAJOR);
return 1;
case HID_DG_HEIGHT:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MINOR);
input_set_abs_params(hi->input, ABS_MT_ORIENTATION,
0, 1, 0, 0);
return 1;
}
return 0;
case 0xff000000:
return -1;
}
return 0;
}
static int ntrig_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (field->physical)
return 0;
if (usage->type == EV_KEY || usage->type == EV_REL
|| usage->type == EV_ABS)
clear_bit(usage->code, *bit);
return 0;
}
static int ntrig_event (struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct ntrig_data *nd = hid_get_drvdata(hid);
struct input_dev *input;
if (!(hid->claimed & HID_CLAIMED_INPUT))
goto not_claimed_input;
if(!(field->hidinput && field->hidinput->input))
return -EINVAL;
input = field->hidinput->input;
if (field->application == HID_DG_PEN)
return 0;
switch (usage->hid) {
case 0xff000001:
nd->reading_mt = 1;
nd->first_contact_touch = 0;
break;
case HID_DG_TIPSWITCH:
nd->tipswitch = value;
return 1;
case HID_DG_CONFIDENCE:
nd->confidence = value;
break;
case HID_GD_X:
nd->x = value;
nd->mt_foot_count = 0;
break;
case HID_GD_Y:
nd->y = value;
break;
case HID_DG_CONTACTID:
nd->id = value;
break;
case HID_DG_WIDTH:
nd->w = value;
break;
case HID_DG_HEIGHT:
nd->h = value;
if (!nd->reading_mt) {
input_report_key(input, BTN_TOUCH,
nd->tipswitch);
input_report_key(input, BTN_TOOL_DOUBLETAP,
nd->tipswitch);
input_event(input, EV_ABS, ABS_X, nd->x);
input_event(input, EV_ABS, ABS_Y, nd->y);
}
break;
case 0xff000002:
if (nd->mt_foot_count >= 4)
break;
nd->mt_footer[nd->mt_foot_count++] = value;
if (nd->mt_foot_count != 4)
break;
if (nd->mt_footer[2]) {
nd->act_state = deactivate_slack - 1;
nd->confidence = 0;
break;
}
if (nd->mt_footer[0]) {
if (nd->w < nd->min_width ||
nd->h < nd->min_height)
nd->confidence = 0;
} else
break;
if (nd->act_state > 0) {
if (nd->w >= nd->activation_width &&
nd->h >= nd->activation_height) {
if (nd->id)
nd->act_state = 0;
else {
nd->act_state = 1;
break;
}
} else
break;
}
if (!nd->confidence)
break;
if (nd->id == 0) {
nd->first_contact_touch = nd->confidence;
input_event(input, EV_ABS, ABS_X, nd->x);
input_event(input, EV_ABS, ABS_Y, nd->y);
}
input_event(input, EV_ABS, ABS_MT_POSITION_X, nd->x);
input_event(input, EV_ABS, ABS_MT_POSITION_Y, nd->y);
if (nd->w > nd->h) {
input_event(input, EV_ABS,
ABS_MT_ORIENTATION, 1);
input_event(input, EV_ABS,
ABS_MT_TOUCH_MAJOR, nd->w);
input_event(input, EV_ABS,
ABS_MT_TOUCH_MINOR, nd->h);
} else {
input_event(input, EV_ABS,
ABS_MT_ORIENTATION, 0);
input_event(input, EV_ABS,
ABS_MT_TOUCH_MAJOR, nd->h);
input_event(input, EV_ABS,
ABS_MT_TOUCH_MINOR, nd->w);
}
input_mt_sync(field->hidinput->input);
break;
case HID_DG_CONTACTCOUNT:
if (!nd->reading_mt)
break;
nd->reading_mt = 0;
if (nd->act_state > 0) {
if (value)
nd->act_state = (nd->act_state > value)
? nd->act_state - value
: 0;
else
nd->act_state = nd->activate_slack;
break;
} else {
if (value && nd->act_state >=
nd->deactivate_slack)
nd->act_state = 0;
else if (nd->act_state <= nd->deactivate_slack)
nd->act_state =
nd->activate_slack;
else {
nd->act_state--;
break;
}
}
if (nd->first_contact_touch && nd->act_state <= 0) {
input_report_key(input, BTN_TOOL_DOUBLETAP, 1);
input_report_key(input, BTN_TOUCH, 1);
} else {
input_report_key(input, BTN_TOOL_DOUBLETAP, 0);
input_report_key(input, BTN_TOUCH, 0);
}
break;
default:
return 0;
}
not_claimed_input:
if ((hid->claimed & HID_CLAIMED_HIDDEV) && hid->hiddev_hid_event)
hid->hiddev_hid_event(hid, field, usage, value);
return 1;
}
static int ntrig_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
struct ntrig_data *nd;
struct hid_input *hidinput;
struct input_dev *input;
struct hid_report *report;
if (id->driver_data)
hdev->quirks |= HID_QUIRK_MULTI_INPUT
| HID_QUIRK_NO_INIT_REPORTS;
nd = kmalloc(sizeof(struct ntrig_data), GFP_KERNEL);
if (!nd) {
hid_err(hdev, "cannot allocate N-Trig data\n");
return -ENOMEM;
}
nd->reading_mt = 0;
nd->min_width = 0;
nd->min_height = 0;
nd->activate_slack = activate_slack;
nd->act_state = activate_slack;
nd->deactivate_slack = -deactivate_slack;
nd->sensor_logical_width = 0;
nd->sensor_logical_height = 0;
nd->sensor_physical_width = 0;
nd->sensor_physical_height = 0;
hid_set_drvdata(hdev, nd);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT & ~HID_CONNECT_FF);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
list_for_each_entry(hidinput, &hdev->inputs, list) {
if (hidinput->report->maxfield < 1)
continue;
input = hidinput->input;
switch (hidinput->report->field[0]->application) {
case HID_DG_PEN:
input->name = "N-Trig Pen";
break;
case HID_DG_TOUCHSCREEN:
__clear_bit(BTN_TOOL_PEN, input->keybit);
__clear_bit(BTN_TOOL_FINGER, input->keybit);
__clear_bit(BTN_0, input->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, input->keybit);
input->name =
(hidinput->report->field[0]
->physical) ?
"N-Trig Touchscreen" :
"N-Trig MultiTouch";
break;
}
}
report = hdev->report_enum[HID_FEATURE_REPORT].report_id_hash[0x0a];
if (report) {
usbhid_wait_io(hdev);
usbhid_submit_report(hdev, report, USB_DIR_IN);
if (ntrig_get_mode(hdev) >= 4)
ntrig_set_mode(hdev, 3);
}
ntrig_report_version(hdev);
ret = sysfs_create_group(&hdev->dev.kobj,
&ntrig_attribute_group);
return 0;
err_free:
kfree(nd);
return ret;
}
static void ntrig_remove(struct hid_device *hdev)
{
sysfs_remove_group(&hdev->dev.kobj,
&ntrig_attribute_group);
hid_hw_stop(hdev);
kfree(hid_get_drvdata(hdev));
}
static int __init ntrig_init(void)
{
return hid_register_driver(&ntrig_driver);
}
static void __exit ntrig_exit(void)
{
hid_unregister_driver(&ntrig_driver);
}
