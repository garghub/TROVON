static int ts_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_LOGIVENDOR)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x00d: ts_map_key_clear(KEY_MEDIA); break;
case 0x024: ts_map_key_clear(KEY_MENU); break;
case 0x025: ts_map_key_clear(KEY_TV); break;
case 0x027: ts_map_key_clear(KEY_MODE); break;
case 0x031: ts_map_key_clear(KEY_AUDIO); break;
case 0x032: ts_map_key_clear(KEY_TEXT); break;
case 0x033: ts_map_key_clear(KEY_CHANNEL); break;
case 0x047: ts_map_key_clear(KEY_MP3); break;
case 0x048: ts_map_key_clear(KEY_TV2); break;
case 0x049: ts_map_key_clear(KEY_CAMERA); break;
case 0x04a: ts_map_key_clear(KEY_VIDEO); break;
case 0x04b: ts_map_key_clear(KEY_ANGLE); break;
case 0x04c: ts_map_key_clear(KEY_LANGUAGE); break;
case 0x04d: ts_map_key_clear(KEY_SUBTITLE); break;
case 0x050: ts_map_key_clear(KEY_RADIO); break;
case 0x05a: ts_map_key_clear(KEY_TEXT); break;
case 0x05b: ts_map_key_clear(KEY_RED); break;
case 0x05c: ts_map_key_clear(KEY_GREEN); break;
case 0x05d: ts_map_key_clear(KEY_YELLOW); break;
case 0x05e: ts_map_key_clear(KEY_BLUE); break;
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
