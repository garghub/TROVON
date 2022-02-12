static __u8 *mr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 30 && rdesc[29] == 0x05 && rdesc[30] == 0x09) {
hid_info(hdev, "fixing up button/consumer in HID report descriptor\n");
rdesc[30] = 0x0c;
}
return rdesc;
}
static int mr_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x156: mr_map_key_clear(KEY_WORDPROCESSOR); break;
case 0x157: mr_map_key_clear(KEY_SPREADSHEET); break;
case 0x158: mr_map_key_clear(KEY_PRESENTATION); break;
case 0x15c: mr_map_key_clear(KEY_STOP); break;
default:
return 0;
}
return 1;
}
static int __init mr_init(void)
{
return hid_register_driver(&mr_driver);
}
static void __exit mr_exit(void)
{
hid_unregister_driver(&mr_driver);
}
