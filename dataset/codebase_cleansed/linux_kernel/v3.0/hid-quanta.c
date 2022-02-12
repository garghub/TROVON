static int quanta_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_GENDESK:
switch (usage->hid) {
case HID_GD_X:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_X);
input_set_abs_params(hi->input, ABS_X,
field->logical_minimum,
field->logical_maximum, 0, 0);
return 1;
case HID_GD_Y:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_Y);
input_set_abs_params(hi->input, ABS_Y,
field->logical_minimum,
field->logical_maximum, 0, 0);
return 1;
}
return 0;
case HID_UP_DIGITIZER:
switch (usage->hid) {
case HID_DG_CONFIDENCE:
case HID_DG_TIPSWITCH:
case HID_DG_INPUTMODE:
case HID_DG_DEVICEINDEX:
case HID_DG_CONTACTCOUNT:
case HID_DG_CONTACTMAX:
case HID_DG_TIPPRESSURE:
case HID_DG_WIDTH:
case HID_DG_HEIGHT:
return -1;
case HID_DG_INRANGE:
hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_TOUCH);
return 1;
case HID_DG_CONTACTID:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TRACKING_ID);
return 1;
}
return 0;
case 0xff000000:
return -1;
}
return 0;
}
static int quanta_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (usage->type == EV_KEY || usage->type == EV_ABS)
clear_bit(usage->code, *bit);
return 0;
}
static void quanta_filter_event(struct quanta_data *td, struct input_dev *input)
{
td->first = !td->first;
if (!td->valid) {
if (!td->first && !td->activity_now && td->activity) {
input_event(input, EV_KEY, BTN_TOUCH, 0);
td->activity = false;
}
return;
}
input_event(input, EV_ABS, ABS_MT_TRACKING_ID, td->id);
input_event(input, EV_ABS, ABS_MT_POSITION_X, td->x);
input_event(input, EV_ABS, ABS_MT_POSITION_Y, td->y);
input_mt_sync(input);
td->valid = false;
if (!td->activity_now) {
if (!td->activity) {
input_event(input, EV_KEY, BTN_TOUCH, 1);
td->activity = true;
}
td->activity_now = true;
input_event(input, EV_ABS, ABS_X, td->x);
input_event(input, EV_ABS, ABS_Y, td->y);
}
}
static int quanta_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct quanta_data *td = hid_get_drvdata(hid);
if (hid->claimed & HID_CLAIMED_INPUT) {
struct input_dev *input = field->hidinput->input;
switch (usage->hid) {
case HID_DG_INRANGE:
td->valid = !!value;
break;
case HID_GD_X:
td->x = value;
break;
case HID_GD_Y:
td->y = value;
quanta_filter_event(td, input);
break;
case HID_DG_CONTACTID:
td->id = value;
break;
case HID_DG_CONTACTCOUNT:
td->first = false;
td->activity_now = false;
break;
case HID_DG_CONFIDENCE:
case HID_DG_TIPSWITCH:
break;
default:
return 0;
}
}
if (hid->claimed & HID_CLAIMED_HIDDEV && hid->hiddev_hid_event)
hid->hiddev_hid_event(hid, field, usage, value);
return 1;
}
static int quanta_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
struct quanta_data *td;
td = kmalloc(sizeof(struct quanta_data), GFP_KERNEL);
if (!td) {
hid_err(hdev, "cannot allocate Quanta Touch data\n");
return -ENOMEM;
}
td->valid = false;
td->activity = false;
td->activity_now = false;
td->first = false;
hid_set_drvdata(hdev, td);
ret = hid_parse(hdev);
if (!ret)
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret)
kfree(td);
return ret;
}
static void quanta_remove(struct hid_device *hdev)
{
hid_hw_stop(hdev);
kfree(hid_get_drvdata(hdev));
hid_set_drvdata(hdev, NULL);
}
static int __init quanta_init(void)
{
return hid_register_driver(&quanta_driver);
}
static void __exit quanta_exit(void)
{
hid_unregister_driver(&quanta_driver);
}
