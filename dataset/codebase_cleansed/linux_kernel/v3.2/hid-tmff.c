static inline int tmff_scale_u16(unsigned int in, int minimum, int maximum)
{
int ret;
ret = (in * (maximum - minimum) / 0xffff) + minimum;
if (ret < minimum)
return minimum;
if (ret > maximum)
return maximum;
return ret;
}
static inline int tmff_scale_s8(int in, int minimum, int maximum)
{
int ret;
ret = (((in + 0x80) * (maximum - minimum)) / 0xff) + minimum;
if (ret < minimum)
return minimum;
if (ret > maximum)
return maximum;
return ret;
}
static int tmff_play(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct tmff_device *tmff = data;
struct hid_field *ff_field = tmff->ff_field;
int x, y;
int left, right;
switch (effect->type) {
case FF_CONSTANT:
x = tmff_scale_s8(effect->u.ramp.start_level,
ff_field->logical_minimum,
ff_field->logical_maximum);
y = tmff_scale_s8(effect->u.ramp.end_level,
ff_field->logical_minimum,
ff_field->logical_maximum);
dbg_hid("(x, y)=(%04x, %04x)\n", x, y);
ff_field->value[0] = x;
ff_field->value[1] = y;
usbhid_submit_report(hid, tmff->report, USB_DIR_OUT);
break;
case FF_RUMBLE:
left = tmff_scale_u16(effect->u.rumble.weak_magnitude,
ff_field->logical_minimum,
ff_field->logical_maximum);
right = tmff_scale_u16(effect->u.rumble.strong_magnitude,
ff_field->logical_minimum,
ff_field->logical_maximum);
dbg_hid("(left,right)=(%08x, %08x)\n", left, right);
ff_field->value[0] = left;
ff_field->value[1] = right;
usbhid_submit_report(hid, tmff->report, USB_DIR_OUT);
break;
}
return 0;
}
static int tmff_init(struct hid_device *hid, const signed short *ff_bits)
{
struct tmff_device *tmff;
struct hid_report *report;
struct list_head *report_list;
struct hid_input *hidinput = list_entry(hid->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
int error;
int i;
tmff = kzalloc(sizeof(struct tmff_device), GFP_KERNEL);
if (!tmff)
return -ENOMEM;
report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
list_for_each_entry(report, report_list, list) {
int fieldnum;
for (fieldnum = 0; fieldnum < report->maxfield; ++fieldnum) {
struct hid_field *field = report->field[fieldnum];
if (field->maxusage <= 0)
continue;
switch (field->usage[0].hid) {
case THRUSTMASTER_USAGE_FF:
if (field->report_count < 2) {
hid_warn(hid, "ignoring FF field with report_count < 2\n");
continue;
}
if (field->logical_maximum ==
field->logical_minimum) {
hid_warn(hid, "ignoring FF field with logical_maximum == logical_minimum\n");
continue;
}
if (tmff->report && tmff->report != report) {
hid_warn(hid, "ignoring FF field in other report\n");
continue;
}
if (tmff->ff_field && tmff->ff_field != field) {
hid_warn(hid, "ignoring duplicate FF field\n");
continue;
}
tmff->report = report;
tmff->ff_field = field;
for (i = 0; ff_bits[i] >= 0; i++)
set_bit(ff_bits[i], input_dev->ffbit);
break;
default:
hid_warn(hid, "ignoring unknown output usage %08x\n",
field->usage[0].hid);
continue;
}
}
}
if (!tmff->report) {
hid_err(hid, "can't find FF field in output reports\n");
error = -ENODEV;
goto fail;
}
error = input_ff_create_memless(input_dev, tmff, tmff_play);
if (error)
goto fail;
hid_info(hid, "force feedback for ThrustMaster devices by Zinx Verituse <zinx@epicsol.org>\n");
return 0;
fail:
kfree(tmff);
return error;
}
static inline int tmff_init(struct hid_device *hid, const signed short *ff_bits)
{
return 0;
}
static int tm_probe(struct hid_device *hdev, const struct hid_device_id *id)
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
tmff_init(hdev, (void *)id->driver_data);
return 0;
err:
return ret;
}
static int __init tm_init(void)
{
return hid_register_driver(&tm_driver);
}
static void __exit tm_exit(void)
{
hid_unregister_driver(&tm_driver);
}
