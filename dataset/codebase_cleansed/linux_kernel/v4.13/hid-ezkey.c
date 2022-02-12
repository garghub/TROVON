static int ez_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x230: ez_map_key(BTN_MOUSE); break;
case 0x231: ez_map_rel(REL_WHEEL); break;
case 0x232: ez_map_rel(REL_HWHEEL); break;
default:
return 0;
}
return 1;
}
static int ez_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
!usage->type)
return 0;
if (usage->type == EV_REL && usage->code == REL_HWHEEL) {
struct input_dev *input = field->hidinput->input;
input_event(input, usage->type, REL_WHEEL, -value);
return 1;
}
return 0;
}
