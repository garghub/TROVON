static int belkin_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER ||
!(quirks & BELKIN_WKBD))
return 0;
switch (usage->hid & HID_USAGE) {
case 0x03a: belkin_map_key_clear(KEY_SOUND); break;
case 0x03b: belkin_map_key_clear(KEY_CAMERA); break;
case 0x03c: belkin_map_key_clear(KEY_DOCUMENTS); break;
default:
return 0;
}
return 1;
}
static int belkin_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
unsigned long quirks = id->driver_data;
int ret;
hid_set_drvdata(hdev, (void *)quirks);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT |
((quirks & BELKIN_HIDDEV) ? HID_CONNECT_HIDDEV_FORCE : 0));
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
return 0;
err_free:
return ret;
}
static int __init belkin_init(void)
{
return hid_register_driver(&belkin_driver);
}
static void __exit belkin_exit(void)
{
hid_unregister_driver(&belkin_driver);
}
