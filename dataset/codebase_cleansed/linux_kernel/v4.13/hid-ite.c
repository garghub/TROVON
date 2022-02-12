static int ite_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct input_dev *input;
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput)
return 0;
input = field->hidinput->input;
if (usage->hid == HID_GD_RFKILL_BTN) {
input_event(input, EV_KEY, KEY_RFKILL, 1);
input_sync(input);
input_event(input, EV_KEY, KEY_RFKILL, 0);
input_sync(input);
return 1;
}
return 0;
}
