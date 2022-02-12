static int hid_lg3ff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
int x, y;
memset(report->field[0]->value, 0, sizeof(__s32)*report->field[0]->maxusage);
switch (effect->type) {
case FF_CONSTANT:
x = effect->u.ramp.start_level;
y = effect->u.ramp.end_level;
report->field[0]->value[0] = 0x51;
report->field[0]->value[1] = (unsigned char)(-x);
report->field[0]->value[31] = (unsigned char)(-y);
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
break;
}
return 0;
}
static void hid_lg3ff_set_autocenter(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
report->field[0]->value[0] = 0x51;
report->field[0]->value[1] = 0x00;
report->field[0]->value[2] = 0x00;
report->field[0]->value[3] = 0x7F;
report->field[0]->value[4] = 0x7F;
report->field[0]->value[31] = 0x00;
report->field[0]->value[32] = 0x00;
report->field[0]->value[33] = 0x7F;
report->field[0]->value[34] = 0x7F;
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
}
int lg3ff_init(struct hid_device *hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
struct hid_report *report;
struct hid_field *field;
const signed short *ff_bits = ff3_joystick_ac;
int error;
int i;
if (list_empty(report_list)) {
hid_err(hid, "No output report found\n");
return -1;
}
report = list_entry(report_list->next, struct hid_report, list);
if (!report) {
hid_err(hid, "NULL output report\n");
return -1;
}
field = report->field[0];
if (!field) {
hid_err(hid, "NULL field\n");
return -1;
}
for (i = 0; ff_bits[i] >= 0; i++)
set_bit(ff_bits[i], dev->ffbit);
error = input_ff_create_memless(dev, NULL, hid_lg3ff_play);
if (error)
return error;
if (test_bit(FF_AUTOCENTER, dev->ffbit))
dev->ff->set_autocenter = hid_lg3ff_set_autocenter;
hid_info(hid, "Force feedback for Logitech Flight System G940 by Gary Stein <LordCnidarian@gmail.com>\n");
return 0;
}
