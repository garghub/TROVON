static int hid_lg4ff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
int x;
#define CLAMP(x) if (x < 0) x = 0; if (x > 0xff) x = 0xff
switch (effect->type) {
case FF_CONSTANT:
x = effect->u.ramp.start_level + 0x80;
CLAMP(x);
report->field[0]->value[0] = 0x11;
report->field[0]->value[1] = 0x10;
report->field[0]->value[2] = x;
report->field[0]->value[3] = 0x00;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x08;
report->field[0]->value[6] = 0x00;
dbg_hid("Autocenter, x=0x%02X\n", x);
usbhid_submit_report(hid, report, USB_DIR_OUT);
break;
}
return 0;
}
static void hid_lg4ff_set_autocenter(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
__s32 *value = report->field[0]->value;
*value++ = 0xfe;
*value++ = 0x0d;
*value++ = 0x07;
*value++ = 0x07;
*value++ = (magnitude >> 8) & 0xff;
*value++ = 0x00;
*value = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
int lg4ff_init(struct hid_device *hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
struct hid_report *report;
struct hid_field *field;
const signed short *ff_bits = ff4_wheel_ac;
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
error = input_ff_create_memless(dev, NULL, hid_lg4ff_play);
if (error)
return error;
if (test_bit(FF_AUTOCENTER, dev->ffbit))
dev->ff->set_autocenter = hid_lg4ff_set_autocenter;
hid_info(hid, "Force feedback for Logitech Speed Force Wireless by Simon Wood <simon@mungewell.org>\n");
return 0;
}
