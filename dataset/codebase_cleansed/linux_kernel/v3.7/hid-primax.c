static int px_raw_event(struct hid_device *hid, struct hid_report *report,
u8 *data, int size)
{
int idx = size;
switch (report->id) {
case 0:
while (--idx > 1) {
if (data[idx] < 0xE0 || data[idx] > 0xE7)
continue;
data[0] |= (1 << (data[idx] - 0xE0));
data[idx] = 0;
}
hid_report_raw_event(hid, HID_INPUT_REPORT, data, size, 0);
return 1;
default:
hid_info(hid, "unknown report type %d\n", report->id);
break;
}
return 0;
}
static int __init px_init(void)
{
return hid_register_driver(&px_driver);
}
static void __exit px_exit(void)
{
hid_unregister_driver(&px_driver);
}
