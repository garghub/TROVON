static __u8 *lg_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct lg_drv_data *drv_data = hid_get_drvdata(hdev);
struct usb_device_descriptor *udesc;
__u16 bcdDevice, rev_maj, rev_min;
if ((drv_data->quirks & LG_RDESC) && *rsize >= 90 && rdesc[83] == 0x26 &&
rdesc[84] == 0x8c && rdesc[85] == 0x02) {
hid_info(hdev,
"fixing up Logitech keyboard report descriptor\n");
rdesc[84] = rdesc[89] = 0x4d;
rdesc[85] = rdesc[90] = 0x10;
}
if ((drv_data->quirks & LG_RDESC_REL_ABS) && *rsize >= 50 &&
rdesc[32] == 0x81 && rdesc[33] == 0x06 &&
rdesc[49] == 0x81 && rdesc[50] == 0x06) {
hid_info(hdev,
"fixing up rel/abs in Logitech report descriptor\n");
rdesc[33] = rdesc[50] = 0x02;
}
switch (hdev->product) {
case USB_DEVICE_ID_LOGITECH_WHEEL:
udesc = &(hid_to_usb_dev(hdev)->descriptor);
if (!udesc) {
hid_err(hdev, "NULL USB device descriptor\n");
break;
}
bcdDevice = le16_to_cpu(udesc->bcdDevice);
rev_maj = bcdDevice >> 8;
rev_min = bcdDevice & 0xff;
if (rev_maj == 1 && rev_min == 2 &&
*rsize == DF_RDESC_ORIG_SIZE) {
hid_info(hdev,
"fixing up Logitech Driving Force report descriptor\n");
rdesc = df_rdesc_fixed;
*rsize = sizeof(df_rdesc_fixed);
}
break;
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL:
if (*rsize == MOMO_RDESC_ORIG_SIZE) {
hid_info(hdev,
"fixing up Logitech Momo Force (Red) report descriptor\n");
rdesc = momo_rdesc_fixed;
*rsize = sizeof(momo_rdesc_fixed);
}
break;
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
if (*rsize == DFP_RDESC_ORIG_SIZE) {
hid_info(hdev,
"fixing up Logitech Driving Force Pro report descriptor\n");
rdesc = dfp_rdesc_fixed;
*rsize = sizeof(dfp_rdesc_fixed);
}
break;
case USB_DEVICE_ID_LOGITECH_WII_WHEEL:
if (*rsize >= 101 && rdesc[41] == 0x95 && rdesc[42] == 0x0B &&
rdesc[47] == 0x05 && rdesc[48] == 0x09) {
hid_info(hdev, "fixing up Logitech Speed Force Wireless report descriptor\n");
rdesc[41] = 0x05;
rdesc[42] = 0x09;
rdesc[47] = 0x95;
rdesc[48] = 0x0B;
}
break;
}
return rdesc;
}
static int lg_ultrax_remote_mapping(struct hid_input *hi,
struct hid_usage *usage, unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_LOGIVENDOR)
return 0;
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0x004: lg_map_key_clear(KEY_AGAIN); break;
case 0x00d: lg_map_key_clear(KEY_HOME); break;
case 0x024: lg_map_key_clear(KEY_SHUFFLE); break;
case 0x025: lg_map_key_clear(KEY_TV); break;
case 0x026: lg_map_key_clear(KEY_MENU); break;
case 0x031: lg_map_key_clear(KEY_AUDIO); break;
case 0x032: lg_map_key_clear(KEY_TEXT); break;
case 0x033: lg_map_key_clear(KEY_LAST); break;
case 0x047: lg_map_key_clear(KEY_MP3); break;
case 0x048: lg_map_key_clear(KEY_DVD); break;
case 0x049: lg_map_key_clear(KEY_MEDIA); break;
case 0x04a: lg_map_key_clear(KEY_VIDEO); break;
case 0x04b: lg_map_key_clear(KEY_ANGLE); break;
case 0x04c: lg_map_key_clear(KEY_LANGUAGE); break;
case 0x04d: lg_map_key_clear(KEY_SUBTITLE); break;
case 0x051: lg_map_key_clear(KEY_RED); break;
case 0x052: lg_map_key_clear(KEY_CLOSE); break;
default:
return 0;
}
return 1;
}
static int lg_dinovo_mapping(struct hid_input *hi, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_LOGIVENDOR)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x00d: lg_map_key_clear(KEY_MEDIA); break;
default:
return 0;
}
return 1;
}
static int lg_wireless_mapping(struct hid_input *hi, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x1001: lg_map_key_clear(KEY_MESSENGER); break;
case 0x1003: lg_map_key_clear(KEY_SOUND); break;
case 0x1004: lg_map_key_clear(KEY_VIDEO); break;
case 0x1005: lg_map_key_clear(KEY_AUDIO); break;
case 0x100a: lg_map_key_clear(KEY_DOCUMENTS); break;
case 0x100f: lg_map_key_clear(KEY_FN_1); break;
case 0x1010: lg_map_key_clear(KEY_FN_2); break;
case 0x1011: lg_map_key_clear(KEY_PREVIOUSSONG); break;
case 0x1012: lg_map_key_clear(KEY_NEXTSONG); break;
case 0x1013: lg_map_key_clear(KEY_CAMERA); break;
case 0x1014: lg_map_key_clear(KEY_MESSENGER); break;
case 0x1015: lg_map_key_clear(KEY_RECORD); break;
case 0x1016: lg_map_key_clear(KEY_PLAYER); break;
case 0x1017: lg_map_key_clear(KEY_EJECTCD); break;
case 0x1018: lg_map_key_clear(KEY_MEDIA); break;
case 0x1019: lg_map_key_clear(KEY_PROG1); break;
case 0x101a: lg_map_key_clear(KEY_PROG2); break;
case 0x101b: lg_map_key_clear(KEY_PROG3); break;
case 0x101c: lg_map_key_clear(KEY_CYCLEWINDOWS); break;
case 0x101f: lg_map_key_clear(KEY_ZOOMIN); break;
case 0x1020: lg_map_key_clear(KEY_ZOOMOUT); break;
case 0x1021: lg_map_key_clear(KEY_ZOOMRESET); break;
case 0x1023: lg_map_key_clear(KEY_CLOSE); break;
case 0x1027: lg_map_key_clear(KEY_MENU); break;
case 0x1028: lg_map_key_clear(KEY_ANGLE); break;
case 0x1029: lg_map_key_clear(KEY_SHUFFLE); break;
case 0x102a: lg_map_key_clear(KEY_BACK); break;
case 0x102b: lg_map_key_clear(KEY_CYCLEWINDOWS); break;
case 0x102d: lg_map_key_clear(KEY_WWW); break;
case 0x1031: lg_map_key_clear(KEY_OK); break;
case 0x1032: lg_map_key_clear(KEY_CANCEL); break;
case 0x1041: lg_map_key_clear(KEY_BATTERY); break;
case 0x1042: lg_map_key_clear(KEY_WORDPROCESSOR); break;
case 0x1043: lg_map_key_clear(KEY_SPREADSHEET); break;
case 0x1044: lg_map_key_clear(KEY_PRESENTATION); break;
case 0x1045: lg_map_key_clear(KEY_UNDO); break;
case 0x1046: lg_map_key_clear(KEY_REDO); break;
case 0x1047: lg_map_key_clear(KEY_PRINT); break;
case 0x1048: lg_map_key_clear(KEY_SAVE); break;
case 0x1049: lg_map_key_clear(KEY_PROG1); break;
case 0x104a: lg_map_key_clear(KEY_PROG2); break;
case 0x104b: lg_map_key_clear(KEY_PROG3); break;
case 0x104c: lg_map_key_clear(KEY_PROG4); break;
default:
return 0;
}
return 1;
}
static int lg_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
static const u8 e_keymap[] = {
0,216, 0,213,175,156, 0, 0, 0, 0,
144, 0, 0, 0, 0, 0, 0, 0, 0,212,
174,167,152,161,112, 0, 0, 0,154, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0,183,184,185,186,187,
188,189,190,191,192,193,194, 0, 0, 0
};
struct lg_drv_data *drv_data = hid_get_drvdata(hdev);
unsigned int hid = usage->hid;
if (hdev->product == USB_DEVICE_ID_LOGITECH_RECEIVER &&
lg_ultrax_remote_mapping(hi, usage, bit, max))
return 1;
if (hdev->product == USB_DEVICE_ID_DINOVO_MINI &&
lg_dinovo_mapping(hi, usage, bit, max))
return 1;
if ((drv_data->quirks & LG_WIRELESS) && lg_wireless_mapping(hi, usage, bit, max))
return 1;
if ((hid & HID_USAGE_PAGE) != HID_UP_BUTTON)
return 0;
hid &= HID_USAGE;
if (field->application == HID_GD_MOUSE) {
if ((drv_data->quirks & LG_IGNORE_DOUBLED_WHEEL) &&
(hid == 7 || hid == 8))
return -1;
} else {
if ((drv_data->quirks & LG_EXPANDED_KEYMAP) &&
hid < ARRAY_SIZE(e_keymap) &&
e_keymap[hid] != 0) {
hid_map_usage(hi, usage, bit, max, EV_KEY,
e_keymap[hid]);
return 1;
}
}
return 0;
}
static int lg_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct lg_drv_data *drv_data = hid_get_drvdata(hdev);
if ((drv_data->quirks & LG_BAD_RELATIVE_KEYS) && usage->type == EV_KEY &&
(field->flags & HID_MAIN_ITEM_RELATIVE))
field->flags &= ~HID_MAIN_ITEM_RELATIVE;
if ((drv_data->quirks & LG_DUPLICATE_USAGES) && (usage->type == EV_KEY ||
usage->type == EV_REL || usage->type == EV_ABS))
clear_bit(usage->code, *bit);
if (usage->type == EV_ABS && (usage->code == ABS_X ||
usage->code == ABS_Y || usage->code == ABS_Z ||
usage->code == ABS_RZ)) {
switch (hdev->product) {
case USB_DEVICE_ID_LOGITECH_WHEEL:
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL:
case USB_DEVICE_ID_LOGITECH_DFP_WHEEL:
case USB_DEVICE_ID_LOGITECH_G25_WHEEL:
case USB_DEVICE_ID_LOGITECH_DFGT_WHEEL:
case USB_DEVICE_ID_LOGITECH_G27_WHEEL:
case USB_DEVICE_ID_LOGITECH_WII_WHEEL:
case USB_DEVICE_ID_LOGITECH_MOMO_WHEEL2:
field->application = HID_GD_MULTIAXIS;
break;
default:
break;
}
}
return 0;
}
static int lg_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct lg_drv_data *drv_data = hid_get_drvdata(hdev);
if ((drv_data->quirks & LG_INVERT_HWHEEL) && usage->code == REL_HWHEEL) {
input_event(field->hidinput->input, usage->type, usage->code,
-value);
return 1;
}
if (drv_data->quirks & LG_FF4) {
return lg4ff_adjust_input_event(hdev, field, usage, value, drv_data);
}
return 0;
}
static int lg_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
unsigned int connect_mask = HID_CONNECT_DEFAULT;
struct lg_drv_data *drv_data;
int ret;
drv_data = kzalloc(sizeof(struct lg_drv_data), GFP_KERNEL);
if (!drv_data) {
hid_err(hdev, "Insufficient memory, cannot allocate driver data\n");
return -ENOMEM;
}
drv_data->quirks = id->driver_data;
hid_set_drvdata(hdev, (void *)drv_data);
if (drv_data->quirks & LG_NOGET)
hdev->quirks |= HID_QUIRK_NOGET;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
if (drv_data->quirks & (LG_FF | LG_FF2 | LG_FF3 | LG_FF4))
connect_mask &= ~HID_CONNECT_FF;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
if (hdev->product == USB_DEVICE_ID_LOGITECH_WII_WHEEL) {
unsigned char buf[] = { 0x00, 0xAF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
ret = hdev->hid_output_raw_report(hdev, buf, sizeof(buf), HID_FEATURE_REPORT);
if (ret >= 0) {
wait_queue_head_t wait;
init_waitqueue_head (&wait);
wait_event_interruptible_timeout(wait, 0, 10);
buf[1] = 0xB2;
get_random_bytes(&buf[2], 2);
ret = hdev->hid_output_raw_report(hdev, buf, sizeof(buf), HID_FEATURE_REPORT);
}
}
if (drv_data->quirks & LG_FF)
lgff_init(hdev);
if (drv_data->quirks & LG_FF2)
lg2ff_init(hdev);
if (drv_data->quirks & LG_FF3)
lg3ff_init(hdev);
if (drv_data->quirks & LG_FF4)
lg4ff_init(hdev);
return 0;
err_free:
kfree(drv_data);
return ret;
}
static void lg_remove(struct hid_device *hdev)
{
struct lg_drv_data *drv_data = hid_get_drvdata(hdev);
if (drv_data->quirks & LG_FF4)
lg4ff_deinit(hdev);
hid_hw_stop(hdev);
kfree(drv_data);
}
