static int speedlink_input_mapping(struct hid_device *hdev,
struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_LED:
return -1;
}
return 0;
}
static int speedlink_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
if (abs(value) >= 256)
return 1;
if (value == 0)
return 1;
return 0;
}
