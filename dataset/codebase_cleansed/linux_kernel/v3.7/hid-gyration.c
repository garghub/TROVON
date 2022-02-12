static int gyration_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_LOGIVENDOR)
return 0;
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0x00d: gy_map_key_clear(KEY_HOME); break;
case 0x024: gy_map_key_clear(KEY_DVD); break;
case 0x025: gy_map_key_clear(KEY_PVR); break;
case 0x046: gy_map_key_clear(KEY_MEDIA); break;
case 0x047: gy_map_key_clear(KEY_MP3); break;
case 0x048: gy_map_key_clear(KEY_MEDIA); break;
case 0x049: gy_map_key_clear(KEY_CAMERA); break;
case 0x04a: gy_map_key_clear(KEY_VIDEO); break;
case 0x05a: gy_map_key_clear(KEY_TEXT); break;
case 0x05b: gy_map_key_clear(KEY_RED); break;
case 0x05c: gy_map_key_clear(KEY_GREEN); break;
case 0x05d: gy_map_key_clear(KEY_YELLOW); break;
case 0x05e: gy_map_key_clear(KEY_BLUE); break;
default:
return 0;
}
return 1;
}
static int gyration_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput)
return 0;
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_GENDESK &&
(usage->hid & 0xff) == 0x82) {
struct input_dev *input = field->hidinput->input;
input_event(input, usage->type, usage->code, 1);
input_sync(input);
input_event(input, usage->type, usage->code, 0);
input_sync(input);
return 1;
}
return 0;
}
static int __init gyration_init(void)
{
return hid_register_driver(&gyration_driver);
}
static void __exit gyration_exit(void)
{
hid_unregister_driver(&gyration_driver);
}
