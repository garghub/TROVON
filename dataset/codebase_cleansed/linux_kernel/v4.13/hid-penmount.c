static int penmount_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
if (((usage->hid - 1) & HID_USAGE) == 0) {
hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_TOUCH);
return 1;
} else {
return -1;
}
}
return 0;
}
