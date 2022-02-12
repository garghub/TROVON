static int hid_plff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct plff_device *plff = data;
int left, right;
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
debug("called with 0x%04x 0x%04x", left, right);
left = left * 0x7f / 0xffff;
right = right * 0x7f / 0xffff;
*plff->strong = left;
*plff->weak = right;
debug("running with 0x%02x 0x%02x", left, right);
usbhid_submit_report(hid, plff->report, USB_DIR_OUT);
return 0;
}
static int plff_init(struct hid_device *hid)
{
struct plff_device *plff;
struct hid_report *report;
struct hid_input *hidinput;
struct list_head *report_list =
&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct list_head *report_ptr = report_list;
struct input_dev *dev;
int error;
s32 *strong;
s32 *weak;
if (list_empty(report_list)) {
hid_err(hid, "no output reports found\n");
return -ENODEV;
}
list_for_each_entry(hidinput, &hid->inputs, list) {
report_ptr = report_ptr->next;
if (report_ptr == report_list) {
hid_err(hid, "required output report is missing\n");
return -ENODEV;
}
report = list_entry(report_ptr, struct hid_report, list);
if (report->maxfield < 1) {
hid_err(hid, "no fields in the report\n");
return -ENODEV;
}
if (report->field[0]->report_count >= 4) {
report->field[0]->value[0] = 0x00;
report->field[0]->value[1] = 0x00;
strong = &report->field[0]->value[2];
weak = &report->field[0]->value[3];
debug("detected single-field device");
} else if (report->maxfield >= 4 && report->field[0]->maxusage == 1 &&
report->field[0]->usage[0].hid == (HID_UP_LED | 0x43)) {
report->field[0]->value[0] = 0x00;
report->field[1]->value[0] = 0x00;
strong = &report->field[2]->value[0];
weak = &report->field[3]->value[0];
debug("detected 4-field device");
} else {
hid_err(hid, "not enough fields or values\n");
return -ENODEV;
}
plff = kzalloc(sizeof(struct plff_device), GFP_KERNEL);
if (!plff)
return -ENOMEM;
dev = hidinput->input;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, plff, hid_plff_play);
if (error) {
kfree(plff);
return error;
}
plff->report = report;
plff->strong = strong;
plff->weak = weak;
*strong = 0x00;
*weak = 0x00;
usbhid_submit_report(hid, plff->report, USB_DIR_OUT);
}
hid_info(hid, "Force feedback for PantherLord/GreenAsia devices by Anssi Hannula <anssi.hannula@gmail.com>\n");
return 0;
}
static inline int plff_init(struct hid_device *hid)
{
return 0;
}
static int pl_probe(struct hid_device *hdev, const struct hid_device_id *id)
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
plff_init(hdev);
return 0;
err:
return ret;
}
static int __init pl_init(void)
{
return hid_register_driver(&pl_driver);
}
static void __exit pl_exit(void)
{
hid_unregister_driver(&pl_driver);
}
