static int plantronics_input_mapping(struct hid_device *hdev,
struct hid_input *hi,
struct hid_field *field,
struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (field->application == HID_CP_CONSUMERCONTROL
&& (usage->hid & HID_USAGE_PAGE) == HID_UP_CONSUMER) {
hid_dbg(hdev, "usage: %08x (appl: %08x) - defaulted\n",
usage->hid, field->application);
return 0;
}
hid_dbg(hdev, "usage: %08x (appl: %08x) - ignored\n",
usage->hid, field->application);
return -1;
}
