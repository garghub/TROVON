static __u8 *ms_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if ((quirks & MS_RDESC) && *rsize == 571 && rdesc[557] == 0x19 &&
rdesc[559] == 0x29) {
hid_info(hdev, "fixing up Microsoft Wireless Receiver Model 1028 report descriptor\n");
rdesc[557] = 0x35;
rdesc[559] = 0x45;
}
if ((quirks & MS_RDESC_3K) && *rsize == 106 && rdesc[94] == 0x19 &&
rdesc[95] == 0x00 && rdesc[96] == 0x29 &&
rdesc[97] == 0xff) {
rdesc[94] = 0x35;
rdesc[96] = 0x45;
}
return rdesc;
}
static int ms_ergonomy_kb_quirk(struct hid_input *hi, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct input_dev *input = hi->input;
switch (usage->hid & HID_USAGE) {
case 0xfd06: ms_map_key_clear(KEY_CHAT); break;
case 0xfd07: ms_map_key_clear(KEY_PHONE); break;
case 0xff05:
set_bit(EV_REP, input->evbit);
ms_map_key_clear(KEY_F13);
set_bit(KEY_F14, input->keybit);
set_bit(KEY_F15, input->keybit);
set_bit(KEY_F16, input->keybit);
set_bit(KEY_F17, input->keybit);
set_bit(KEY_F18, input->keybit);
default:
return 0;
}
return 1;
}
static int ms_presenter_8k_quirk(struct hid_input *hi, struct hid_usage *usage,
unsigned long **bit, int *max)
{
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0xfd08: ms_map_key_clear(KEY_FORWARD); break;
case 0xfd09: ms_map_key_clear(KEY_BACK); break;
case 0xfd0b: ms_map_key_clear(KEY_PLAYPAUSE); break;
case 0xfd0e: ms_map_key_clear(KEY_CLOSE); break;
case 0xfd0f: ms_map_key_clear(KEY_PLAY); break;
default:
return 0;
}
return 1;
}
static int ms_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_MSVENDOR)
return 0;
if (quirks & MS_ERGONOMY) {
int ret = ms_ergonomy_kb_quirk(hi, usage, bit, max);
if (ret)
return ret;
}
if ((quirks & MS_PRESENTER) &&
ms_presenter_8k_quirk(hi, usage, bit, max))
return 1;
return 0;
}
static int ms_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if (quirks & MS_DUPLICATE_USAGES)
clear_bit(usage->code, *bit);
return 0;
}
static int ms_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
!usage->type)
return 0;
if (quirks & MS_ERGONOMY && usage->hid == (HID_UP_MSVENDOR | 0xff05)) {
struct input_dev *input = field->hidinput->input;
static unsigned int last_key = 0;
unsigned int key = 0;
switch (value) {
case 0x01: key = KEY_F14; break;
case 0x02: key = KEY_F15; break;
case 0x04: key = KEY_F16; break;
case 0x08: key = KEY_F17; break;
case 0x10: key = KEY_F18; break;
}
if (key) {
input_event(input, usage->type, key, 1);
last_key = key;
} else
input_event(input, usage->type, last_key, 0);
return 1;
}
return 0;
}
static int ms_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
unsigned long quirks = id->driver_data;
int ret;
hid_set_drvdata(hdev, (void *)quirks);
if (quirks & MS_NOGET)
hdev->quirks |= HID_QUIRK_NOGET;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT | ((quirks & MS_HIDINPUT) ?
HID_CONNECT_HIDINPUT_FORCE : 0));
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
return 0;
err_free:
return ret;
}
static int __init ms_init(void)
{
return hid_register_driver(&ms_driver);
}
static void __exit ms_exit(void)
{
hid_unregister_driver(&ms_driver);
}
