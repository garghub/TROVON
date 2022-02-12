static int ch_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_MSVENDOR)
return 0;
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0xff01: ch_map_key_clear(BTN_1); break;
case 0xff02: ch_map_key_clear(BTN_2); break;
case 0xff03: ch_map_key_clear(BTN_3); break;
case 0xff04: ch_map_key_clear(BTN_4); break;
case 0xff05: ch_map_key_clear(BTN_5); break;
case 0xff06: ch_map_key_clear(BTN_6); break;
case 0xff07: ch_map_key_clear(BTN_7); break;
case 0xff08: ch_map_key_clear(BTN_8); break;
case 0xff09: ch_map_key_clear(BTN_9); break;
case 0xff0a: ch_map_key_clear(BTN_A); break;
case 0xff0b: ch_map_key_clear(BTN_B); break;
default:
return 0;
}
return 1;
}
static int __init ch_init(void)
{
return hid_register_driver(&ch_driver);
}
static void __exit ch_exit(void)
{
hid_unregister_driver(&ch_driver);
}
