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
static int px_probe(struct hid_device *hid, const struct hid_device_id *id)
{
int ret;
ret = hid_parse(hid);
if (ret) {
hid_err(hid, "parse failed\n");
goto fail;
}
ret = hid_hw_start(hid, HID_CONNECT_DEFAULT);
if (ret)
hid_err(hid, "hw start failed\n");
fail:
return ret;
}
static void px_remove(struct hid_device *hid)
{
hid_hw_stop(hid);
}
static int __init px_init(void)
{
return hid_register_driver(&px_driver);
}
static void __exit px_exit(void)
{
hid_unregister_driver(&px_driver);
}
