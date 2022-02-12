static __u8 *cp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
unsigned int i;
if (!(quirks & CP_RDESC_SWAPPED_MIN_MAX))
return rdesc;
for (i = 0; i < *rsize - 4; i++)
if (rdesc[i] == 0x29 && rdesc[i + 2] == 0x19) {
rdesc[i] = 0x19;
rdesc[i + 2] = 0x29;
swap(rdesc[i + 3], rdesc[i + 1]);
}
return rdesc;
}
static int cp_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if (!(quirks & CP_2WHEEL_MOUSE_HACK))
return 0;
if (usage->type == EV_REL && usage->code == REL_WHEEL)
set_bit(REL_HWHEEL, *bit);
if (usage->hid == 0x00090005)
return -1;
return 0;
}
static int cp_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
!usage->type || !(quirks & CP_2WHEEL_MOUSE_HACK))
return 0;
if (usage->hid == 0x00090005) {
if (value)
quirks |= CP_2WHEEL_MOUSE_HACK_ON;
else
quirks &= ~CP_2WHEEL_MOUSE_HACK_ON;
hid_set_drvdata(hdev, (void *)quirks);
return 1;
}
if (usage->code == REL_WHEEL && (quirks & CP_2WHEEL_MOUSE_HACK_ON)) {
struct input_dev *input = field->hidinput->input;
input_event(input, usage->type, REL_HWHEEL, value);
return 1;
}
return 0;
}
static int cp_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
unsigned long quirks = id->driver_data;
int ret;
hid_set_drvdata(hdev, (void *)quirks);
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
return ret;
}
