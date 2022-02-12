static int zpff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct zpff_device *zpff = data;
int left, right;
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
dbg_hid("called with 0x%04x 0x%04x\n", left, right);
left = left * 0x7f / 0xffff;
right = right * 0x7f / 0xffff;
zpff->report->field[2]->value[0] = left;
zpff->report->field[3]->value[0] = right;
dbg_hid("running with 0x%02x 0x%02x\n", left, right);
hid_hw_request(hid, zpff->report, HID_REQ_SET_REPORT);
return 0;
}
static int zpff_init(struct hid_device *hid)
{
struct zpff_device *zpff;
struct hid_report *report;
struct hid_input *hidinput = list_entry(hid->inputs.next,
struct hid_input, list);
struct list_head *report_list =
&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
int error;
if (list_empty(report_list)) {
hid_err(hid, "no output report found\n");
return -ENODEV;
}
report = list_entry(report_list->next, struct hid_report, list);
if (report->maxfield < 4) {
hid_err(hid, "not enough fields in report\n");
return -ENODEV;
}
zpff = kzalloc(sizeof(struct zpff_device), GFP_KERNEL);
if (!zpff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, zpff, zpff_play);
if (error) {
kfree(zpff);
return error;
}
zpff->report = report;
zpff->report->field[0]->value[0] = 0x00;
zpff->report->field[1]->value[0] = 0x02;
zpff->report->field[2]->value[0] = 0x00;
zpff->report->field[3]->value[0] = 0x00;
hid_hw_request(hid, zpff->report, HID_REQ_SET_REPORT);
hid_info(hid, "force feedback for Zeroplus based devices by Anssi Hannula <anssi.hannula@gmail.com>\n");
return 0;
}
static inline int zpff_init(struct hid_device *hid)
{
return 0;
}
static int zp_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
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
zpff_init(hdev);
return 0;
err:
return ret;
}
