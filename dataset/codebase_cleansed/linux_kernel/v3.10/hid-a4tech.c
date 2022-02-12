static int a4_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct a4tech_sc *a4 = hid_get_drvdata(hdev);
if (usage->type == EV_REL && usage->code == REL_WHEEL)
set_bit(REL_HWHEEL, *bit);
if ((a4->quirks & A4_2WHEEL_MOUSE_HACK_7) && usage->hid == 0x00090007)
return -1;
return 0;
}
static int a4_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct a4tech_sc *a4 = hid_get_drvdata(hdev);
struct input_dev *input;
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
!usage->type)
return 0;
input = field->hidinput->input;
if (a4->quirks & A4_2WHEEL_MOUSE_HACK_B8) {
if (usage->type == EV_REL && usage->code == REL_WHEEL) {
a4->delayed_value = value;
return 1;
}
if (usage->hid == 0x000100b8) {
input_event(input, EV_REL, value ? REL_HWHEEL :
REL_WHEEL, a4->delayed_value);
return 1;
}
}
if ((a4->quirks & A4_2WHEEL_MOUSE_HACK_7) && usage->hid == 0x00090007) {
a4->hw_wheel = !!value;
return 1;
}
if (usage->code == REL_WHEEL && a4->hw_wheel) {
input_event(input, usage->type, REL_HWHEEL, value);
return 1;
}
return 0;
}
static int a4_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct a4tech_sc *a4;
int ret;
a4 = kzalloc(sizeof(*a4), GFP_KERNEL);
if (a4 == NULL) {
hid_err(hdev, "can't alloc device descriptor\n");
ret = -ENOMEM;
goto err_free;
}
a4->quirks = id->driver_data;
hid_set_drvdata(hdev, a4);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
return 0;
err_free:
kfree(a4);
return ret;
}
static void a4_remove(struct hid_device *hdev)
{
struct a4tech_sc *a4 = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
kfree(a4);
}
