static __u8 *pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 62 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
rdesc[60] = 0xfa;
rdesc[40] = 0xfa;
}
return rdesc;
}
static int pl_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_LOGIVENDOR) {
switch (usage->hid & HID_USAGE) {
case 0x05a: pl_map_key_clear(KEY_TEXT); break;
case 0x05b: pl_map_key_clear(KEY_RED); break;
case 0x05c: pl_map_key_clear(KEY_GREEN); break;
case 0x05d: pl_map_key_clear(KEY_YELLOW); break;
case 0x05e: pl_map_key_clear(KEY_BLUE); break;
default:
return 0;
}
return 1;
}
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_CONSUMER) {
switch (usage->hid & HID_USAGE) {
case 0x0f6: pl_map_key_clear(KEY_NEXT); break;
case 0x0fa: pl_map_key_clear(KEY_BACK); break;
default:
return 0;
}
return 1;
}
return 0;
}
static int pl_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
hdev->quirks |= HID_QUIRK_NOGET;
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
