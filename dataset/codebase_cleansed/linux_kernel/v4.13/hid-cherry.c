static __u8 *ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 18 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
rdesc[11] = rdesc[16] = 0xff;
rdesc[12] = rdesc[17] = 0x03;
}
return rdesc;
}
static int ch_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x301: ch_map_key_clear(KEY_PROG1); break;
case 0x302: ch_map_key_clear(KEY_PROG2); break;
case 0x303: ch_map_key_clear(KEY_PROG3); break;
default:
return 0;
}
return 1;
}
