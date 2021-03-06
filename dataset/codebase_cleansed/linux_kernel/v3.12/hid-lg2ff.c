static int play_effect(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct lg2ff_device *lg2ff = data;
int weak, strong;
strong = effect->u.rumble.strong_magnitude;
weak = effect->u.rumble.weak_magnitude;
if (weak || strong) {
weak = weak * 0xff / 0xffff;
strong = strong * 0xff / 0xffff;
lg2ff->report->field[0]->value[0] = 0x51;
lg2ff->report->field[0]->value[2] = weak;
lg2ff->report->field[0]->value[4] = strong;
} else {
lg2ff->report->field[0]->value[0] = 0xf3;
lg2ff->report->field[0]->value[2] = 0x00;
lg2ff->report->field[0]->value[4] = 0x00;
}
hid_hw_request(hid, lg2ff->report, HID_REQ_SET_REPORT);
return 0;
}
int lg2ff_init(struct hid_device *hid)
{
struct lg2ff_device *lg2ff;
struct hid_report *report;
struct hid_input *hidinput = list_entry(hid->inputs.next,
struct hid_input, list);
struct input_dev *dev = hidinput->input;
int error;
report = hid_validate_values(hid, HID_OUTPUT_REPORT, 0, 0, 7);
if (!report)
return -ENODEV;
lg2ff = kmalloc(sizeof(struct lg2ff_device), GFP_KERNEL);
if (!lg2ff)
return -ENOMEM;
set_bit(FF_RUMBLE, dev->ffbit);
error = input_ff_create_memless(dev, lg2ff, play_effect);
if (error) {
kfree(lg2ff);
return error;
}
lg2ff->report = report;
report->field[0]->value[0] = 0xf3;
report->field[0]->value[1] = 0x00;
report->field[0]->value[2] = 0x00;
report->field[0]->value[3] = 0x00;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
hid_info(hid, "Force feedback for Logitech RumblePad/Rumblepad 2 by Anssi Hannula <anssi.hannula@gmail.com>\n");
return 0;
}
