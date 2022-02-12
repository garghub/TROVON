static void holtekff_send(struct holtekff_device *holtekff,
struct hid_device *hid,
const u8 data[HOLTEKFF_MSG_LENGTH])
{
int i;
for (i = 0; i < HOLTEKFF_MSG_LENGTH; i++) {
holtekff->field->value[i] = data[i];
}
dbg_hid("sending %*ph\n", 7, data);
usbhid_submit_report(hid, holtekff->field->report, USB_DIR_OUT);
}
static int holtekff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct holtekff_device *holtekff = data;
int left, right;
u8 buf[HOLTEKFF_MSG_LENGTH] =
{ 0x01, 0x01, 0xff, 0xff, 0x10, 0xe0, 0x00 };
left = effect->u.rumble.strong_magnitude;
right = effect->u.rumble.weak_magnitude;
dbg_hid("called with 0x%04x 0x%04x\n", left, right);
if (!left && !right) {
holtekff_send(holtekff, hid, stop_all6);
return 0;
}
if (left)
buf[1] |= 0x80;
if (right)
buf[1] |= 0x40;
buf[6] = min(0xf, (left >> 12) + (right >> 12));
holtekff_send(holtekff, hid, buf);
holtekff_send(holtekff, hid, start_effect_1);
return 0;
}
static int holtekff_init(struct hid_device *hid)
{
struct holtekff_device *holtekff;
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
if (report->maxfield < 1 || report->field[0]->report_count != 7) {
hid_err(hid, "unexpected output report layout\n");
return -ENODEV;
}
holtekff = kzalloc(sizeof(*holtekff), GFP_KERNEL);
if (!holtekff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
holtekff->field = report->field[0];
holtekff_send(holtekff, hid, stop_all4);
holtekff_send(holtekff, hid, stop_all6);
error = input_ff_create_memless(dev, holtekff, holtekff_play);
if (error) {
kfree(holtekff);
return error;
}
hid_info(hid, "Force feedback for Holtek On Line Grip based devices by Anssi Hannula <anssi.hannula@iki.fi>\n");
return 0;
}
static inline int holtekff_init(struct hid_device *hid)
{
return 0;
}
static int holtek_probe(struct hid_device *hdev, const struct hid_device_id *id)
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
holtekff_init(hdev);
return 0;
err:
return ret;
}
