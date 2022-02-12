static int ks_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_MSVENDOR)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x01: ks_map_key(BTN_MIDDLE); break;
case 0x02: ks_map_key(BTN_SIDE); break;
default:
return 0;
}
return 1;
}
static int __init ks_init(void)
{
return hid_register_driver(&ks_driver);
}
static void __exit ks_exit(void)
{
hid_unregister_driver(&ks_driver);
}
