static int hid_gaff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct gaff_device *gaff = data;
int left, right;
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
dbg_hid("called with 0x%04x 0x%04x", left, right);
left = left * 0xfe / 0xffff;
right = right * 0xfe / 0xffff;
gaff->report->field[0]->value[0] = 0x51;
gaff->report->field[0]->value[1] = 0x0;
gaff->report->field[0]->value[2] = right;
gaff->report->field[0]->value[3] = 0;
gaff->report->field[0]->value[4] = left;
gaff->report->field[0]->value[5] = 0;
dbg_hid("running with 0x%02x 0x%02x", left, right);
usbhid_submit_report(hid, gaff->report, USB_DIR_OUT);
gaff->report->field[0]->value[0] = 0xfa;
gaff->report->field[0]->value[1] = 0xfe;
gaff->report->field[0]->value[2] = 0x0;
gaff->report->field[0]->value[4] = 0x0;
usbhid_submit_report(hid, gaff->report, USB_DIR_OUT);
return 0;
}
static int gaff_init(struct hid_device *hid)
{
struct gaff_device *gaff;
struct hid_report *report;
struct hid_input *hidinput = list_entry(hid->inputs.next,
struct hid_input, list);
struct list_head *report_list =
&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct list_head *report_ptr = report_list;
struct input_dev *dev = hidinput->input;
int error;
if (list_empty(report_list)) {
hid_err(hid, "no output reports found\n");
return -ENODEV;
}
report_ptr = report_ptr->next;
report = list_entry(report_ptr, struct hid_report, list);
if (report->maxfield < 1) {
hid_err(hid, "no fields in the report\n");
return -ENODEV;
}
if (report->field[0]->report_count < 6) {
hid_err(hid, "not enough values in the field\n");
return -ENODEV;
}
gaff = kzalloc(sizeof(struct gaff_device), GFP_KERNEL);
if (!gaff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, gaff, hid_gaff_play);
if (error) {
kfree(gaff);
return error;
}
gaff->report = report;
gaff->report->field[0]->value[0] = 0x51;
gaff->report->field[0]->value[1] = 0x00;
gaff->report->field[0]->value[2] = 0x00;
gaff->report->field[0]->value[3] = 0x00;
usbhid_submit_report(hid, gaff->report, USB_DIR_OUT);
gaff->report->field[0]->value[0] = 0xfa;
gaff->report->field[0]->value[1] = 0xfe;
usbhid_submit_report(hid, gaff->report, USB_DIR_OUT);
hid_info(hid, "Force Feedback for GreenAsia 0x12 devices by Lukasz Lubojanski <lukasz@lubojanski.info>\n");
return 0;
}
static inline int gaff_init(struct hid_device *hdev)
{
return 0;
}
static int ga_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
dev_dbg(&hdev->dev, "Greenasia HID hardware probe...");
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
gaff_init(hdev);
return 0;
err:
return ret;
}
