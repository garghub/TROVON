static int ts_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_LOGIVENDOR)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x046: ts_map_key_clear(KEY_YELLOW); break;
case 0x047: ts_map_key_clear(KEY_GREEN); break;
case 0x049: ts_map_key_clear(KEY_BLUE); break;
case 0x04a: ts_map_key_clear(KEY_RED); break;
case 0x00d: ts_map_key_clear(KEY_HOME); break;
case 0x025: ts_map_key_clear(KEY_TV); break;
case 0x048: ts_map_key_clear(KEY_VCR); break;
case 0x024: ts_map_key_clear(KEY_MENU); break;
default:
return 0;
}
return 1;
}
static int __init ts_init(void)
{
return hid_register_driver(&ts_driver);
}
static void __exit ts_exit(void)
{
hid_unregister_driver(&ts_driver);
}
