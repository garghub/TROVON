static int axff_play(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct axff_device *axff = data;
struct hid_report *report = axff->report;
int field_count = 0;
int left, right;
int i, j;
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
dbg_hid("called with 0x%04x 0x%04x", left, right);
left = left * 0xff / 0xffff;
right = right * 0xff / 0xffff;
for (i = 0; i < report->maxfield; i++) {
for (j = 0; j < report->field[i]->report_count; j++) {
report->field[i]->value[j] =
field_count % 2 ? right : left;
field_count++;
}
}
dbg_hid("running with 0x%02x 0x%02x", left, right);
usbhid_submit_report(hid, axff->report, USB_DIR_OUT);
return 0;
}
static int axff_init(struct hid_device *hid)
{
struct axff_device *axff;
struct hid_report *report;
struct hid_input *hidinput = list_first_entry(&hid->inputs, struct hid_input, list);
struct list_head *report_list =&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
int field_count = 0;
int i, j;
int error;
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
axff = kzalloc(sizeof(struct axff_device), GFP_KERNEL);
if (!axff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, axff, axff_play);
if (error)
goto err_free_mem;
axff->report = report;
usbhid_submit_report(hid, axff->report, USB_DIR_OUT);
hid_info(hid, "Force Feedback for ACRUX game controllers by Sergei Kolzun <x0r@dv-life.ru>\n");
return 0;
err_free_mem:
kfree(axff);
return error;
}
static inline int axff_init(struct hid_device *hid)
{
return 0;
}
static int ax_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int error;
dev_dbg(&hdev->dev, "ACRUX HID hardware probe...\n");
error = hid_parse(hdev);
if (error) {
hid_err(hdev, "parse failed\n");
return error;
}
error = hid_hw_start(hdev, HID_CONNECT_DEFAULT & ~HID_CONNECT_FF);
if (error) {
hid_err(hdev, "hw start failed\n");
return error;
}
error = axff_init(hdev);
if (error) {
hid_warn(hdev,
"Failed to enable force feedback support, error: %d\n",
error);
}
error = hid_hw_open(hdev);
if (error) {
dev_err(&hdev->dev, "hw open failed\n");
hid_hw_stop(hdev);
return error;
}
return 0;
}
static void ax_remove(struct hid_device *hdev)
{
hid_hw_close(hdev);
hid_hw_stop(hdev);
}
