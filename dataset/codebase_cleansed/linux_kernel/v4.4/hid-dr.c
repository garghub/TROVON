static int drff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct drff_device *drff = data;
int strong, weak;
strong = effect->u.rumble.strong_magnitude;
weak = effect->u.rumble.weak_magnitude;
dbg_hid("called with 0x%04x 0x%04x", strong, weak);
if (strong || weak) {
strong = strong * 0xff / 0xffff;
weak = weak * 0xff / 0xffff;
if (weak == 0x0a)
weak = 0x0b;
drff->report->field[0]->value[0] = 0x51;
drff->report->field[0]->value[1] = 0x00;
drff->report->field[0]->value[2] = weak;
drff->report->field[0]->value[4] = strong;
hid_hw_request(hid, drff->report, HID_REQ_SET_REPORT);
drff->report->field[0]->value[0] = 0xfa;
drff->report->field[0]->value[1] = 0xfe;
} else {
drff->report->field[0]->value[0] = 0xf3;
drff->report->field[0]->value[1] = 0x00;
}
drff->report->field[0]->value[2] = 0x00;
drff->report->field[0]->value[4] = 0x00;
dbg_hid("running with 0x%02x 0x%02x", strong, weak);
hid_hw_request(hid, drff->report, HID_REQ_SET_REPORT);
return 0;
}
static int drff_init(struct hid_device *hid)
{
struct drff_device *drff;
struct hid_report *report;
struct hid_input *hidinput = list_first_entry(&hid->inputs,
struct hid_input, list);
struct list_head *report_list =
&hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
int error;
if (list_empty(report_list)) {
hid_err(hid, "no output reports found\n");
return -ENODEV;
}
report = list_first_entry(report_list, struct hid_report, list);
if (report->maxfield < 1) {
hid_err(hid, "no fields in the report\n");
return -ENODEV;
}
if (report->field[0]->report_count < 7) {
hid_err(hid, "not enough values in the field\n");
return -ENODEV;
}
drff = kzalloc(sizeof(struct drff_device), GFP_KERNEL);
if (!drff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, drff, drff_play);
if (error) {
kfree(drff);
return error;
}
drff->report = report;
drff->report->field[0]->value[0] = 0xf3;
drff->report->field[0]->value[1] = 0x00;
drff->report->field[0]->value[2] = 0x00;
drff->report->field[0]->value[3] = 0x00;
drff->report->field[0]->value[4] = 0x00;
drff->report->field[0]->value[5] = 0x00;
drff->report->field[0]->value[6] = 0x00;
hid_hw_request(hid, drff->report, HID_REQ_SET_REPORT);
hid_info(hid, "Force Feedback for DragonRise Inc. "
"game controllers by Richard Walmsley <richwalm@gmail.com>\n");
return 0;
}
static inline int drff_init(struct hid_device *hid)
{
return 0;
}
static __u8 *dr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
switch (hdev->product) {
case 0x0011:
if (*rsize == PID0011_RDESC_ORIG_SIZE) {
rdesc = pid0011_rdesc_fixed;
*rsize = sizeof(pid0011_rdesc_fixed);
}
break;
case 0x0006:
if (*rsize == sizeof(pid0006_rdesc_fixed)) {
rdesc = pid0006_rdesc_fixed;
*rsize = sizeof(pid0006_rdesc_fixed);
}
break;
}
return rdesc;
}
static int dr_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
dev_dbg(&hdev->dev, "DragonRise Inc. HID hardware probe...");
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
switch (hdev->product) {
case 0x0006:
ret = drff_init(hdev);
if (ret) {
dev_err(&hdev->dev, "force feedback init failed\n");
hid_hw_stop(hdev);
goto err;
}
break;
}
return 0;
err:
return ret;
}
