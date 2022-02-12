static int hid_betopff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct betopff_device *betopff = data;
__u16 left, right;
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
betopff->report->field[2]->value[0] = left / 256;
betopff->report->field[3]->value[0] = right / 256;
hid_hw_request(hid, betopff->report, HID_REQ_SET_REPORT);
return 0;
}
static int betopff_init(struct hid_device *hid)
{
struct betopff_device *betopff;
struct hid_report *report;
struct hid_input *hidinput =
list_first_entry(&hid->inputs, struct hid_input, list);
struct list_head *report_list =
&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
int field_count = 0;
int error;
int i, j;
if (list_empty(report_list)) {
hid_err(hid, "no output reports found\n");
return -ENODEV;
}
report = list_first_entry(report_list, struct hid_report, list);
for (i = 0; i < report->maxfield; i++) {
for (j = 0; j < report->field[i]->report_count; j++) {
report->field[i]->value[j] = 0x00;
field_count++;
}
}
if (field_count < 4) {
hid_err(hid, "not enough fields in the report: %d\n",
field_count);
return -ENODEV;
}
betopff = kzalloc(sizeof(*betopff), GFP_KERNEL);
if (!betopff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, betopff, hid_betopff_play);
if (error) {
kfree(betopff);
return error;
}
betopff->report = report;
hid_hw_request(hid, betopff->report, HID_REQ_SET_REPORT);
hid_info(hid, "Force feedback for betop devices by huangbo <huangbobupt@163.com>\n");
return 0;
}
static int betop_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
if (id->driver_data)
hdev->quirks |= HID_QUIRK_MULTI_INPUT;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT & ~HID_CONNECT_FF);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err;
}
betopff_init(hdev);
return 0;
err:
return ret;
}
