static int hid_lgff_play(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
int x, y;
unsigned int left, right;
#define CLAMP(x) if (x < 0) x = 0; if (x > 0xff) x = 0xff
switch (effect->type) {
case FF_CONSTANT:
x = effect->u.ramp.start_level + 0x7f;
y = effect->u.ramp.end_level + 0x7f;
CLAMP(x);
CLAMP(y);
report->field[0]->value[0] = 0x51;
report->field[0]->value[1] = 0x08;
report->field[0]->value[2] = x;
report->field[0]->value[3] = y;
dbg_hid("(x, y)=(%04x, %04x)\n", x, y);
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
break;
case FF_RUMBLE:
right = effect->u.rumble.strong_magnitude;
left = effect->u.rumble.weak_magnitude;
right = right * 0xff / 0xffff;
left = left * 0xff / 0xffff;
CLAMP(left);
CLAMP(right);
report->field[0]->value[0] = 0x42;
report->field[0]->value[1] = 0x00;
report->field[0]->value[2] = left;
report->field[0]->value[3] = right;
dbg_hid("(left, right)=(%04x, %04x)\n", left, right);
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
break;
}
return 0;
}
static void hid_lgff_set_autocenter(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
__s32 *value = report->field[0]->value;
magnitude = (magnitude >> 12) & 0xf;
*value++ = 0xfe;
*value++ = 0x0d;
*value++ = magnitude;
*value++ = magnitude;
*value++ = 0x80;
*value++ = 0x00;
*value = 0x00;
hid_hw_request(hid, report, HID_REQ_SET_REPORT);
}
int lgff_init(struct hid_device* hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
struct hid_report *report;
struct hid_field *field;
const signed short *ff_bits = ff_joystick;
int error;
int i;
if (list_empty(report_list)) {
hid_err(hid, "No output report found\n");
return -1;
}
report = list_entry(report_list->next, struct hid_report, list);
field = report->field[0];
if (!field) {
hid_err(hid, "NULL field\n");
return -1;
}
for (i = 0; i < ARRAY_SIZE(devices); i++) {
if (dev->id.vendor == devices[i].idVendor &&
dev->id.product == devices[i].idProduct) {
ff_bits = devices[i].ff;
break;
}
}
for (i = 0; ff_bits[i] >= 0; i++)
set_bit(ff_bits[i], dev->ffbit);
error = input_ff_create_memless(dev, NULL, hid_lgff_play);
if (error)
return error;
if ( test_bit(FF_AUTOCENTER, dev->ffbit) )
dev->ff->set_autocenter = hid_lgff_set_autocenter;
pr_info("Force feedback for Logitech force feedback devices by Johann Deneux <johann.deneux@it.uu.se>\n");
return 0;
}
