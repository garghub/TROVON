static __u8 *sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 107 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
rdesc[106] == 0x03) {
hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
rdesc[105] = rdesc[110] = 0x03;
rdesc[106] = rdesc[111] = 0x21;
}
return rdesc;
}
static int sp_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x2003: sp_map_key_clear(KEY_ZOOMIN); break;
case 0x2103: sp_map_key_clear(KEY_ZOOMOUT); break;
default:
return 0;
}
return 1;
}
static int __init sp_init(void)
{
return hid_register_driver(&sp_driver);
}
static void __exit sp_exit(void)
{
hid_unregister_driver(&sp_driver);
}
