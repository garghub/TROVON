static int tivo_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_TIVOVENDOR:
switch (usage->hid & HID_USAGE) {
case 0x3d: tivo_map_key_clear(KEY_MEDIA); break;
case 0x3e: tivo_map_key_clear(KEY_TV); break;
case 0x41: tivo_map_key_clear(KEY_KPMINUS); break;
case 0x42: tivo_map_key_clear(KEY_KPPLUS); break;
default:
return 0;
}
break;
case HID_UP_CONSUMER:
switch (usage->hid & HID_USAGE) {
case 0x083: tivo_map_key_clear(KEY_ENTER); break;
case 0x209: tivo_map_key_clear(KEY_INFO); break;
default:
return 0;
}
break;
default:
return 0;
}
return 1;
}
