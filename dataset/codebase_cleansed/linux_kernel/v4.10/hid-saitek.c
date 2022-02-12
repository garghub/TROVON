static int saitek_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
unsigned long quirks = id->driver_data;
struct saitek_sc *ssc;
int ret;
ssc = devm_kzalloc(&hdev->dev, sizeof(*ssc), GFP_KERNEL);
if (ssc == NULL) {
hid_err(hdev, "can't alloc saitek descriptor\n");
return -ENOMEM;
}
ssc->quirks = quirks;
ssc->mode = -1;
hid_set_drvdata(hdev, ssc);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
return 0;
}
static __u8 *saitek_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct saitek_sc *ssc = hid_get_drvdata(hdev);
if ((ssc->quirks & SAITEK_FIX_PS1000) && *rsize == 137 &&
rdesc[20] == 0x09 && rdesc[21] == 0x33 &&
rdesc[94] == 0x81 && rdesc[95] == 0x03 &&
rdesc[110] == 0x81 && rdesc[111] == 0x03) {
hid_info(hdev, "Fixing up Saitek PS1000 report descriptor\n");
rdesc[20] = 0x15;
rdesc[21] = 0x00;
rdesc[95] = 0x02;
rdesc[111] = 0x02;
}
return rdesc;
}
static int saitek_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *raw_data, int size)
{
struct saitek_sc *ssc = hid_get_drvdata(hdev);
if (ssc->quirks & SAITEK_RELEASE_MODE_RAT7 && size == 7) {
int mode = -1;
if (raw_data[1] & 0x01)
mode = 0;
else if (raw_data[1] & 0x02)
mode = 1;
else if (raw_data[1] & 0x04)
mode = 2;
raw_data[1] &= ~0x07;
if (mode != ssc->mode) {
hid_dbg(hdev, "entered mode %d\n", mode);
if (ssc->mode != -1) {
raw_data[1] |= 0x04;
}
ssc->mode = mode;
}
} else if (ssc->quirks & SAITEK_RELEASE_MODE_MMO7 && size == 8) {
int mode = -1;
if (raw_data[1] & 0x80)
mode = 0;
else if (raw_data[2] & 0x01)
mode = 1;
else if (raw_data[2] & 0x02)
mode = 2;
raw_data[1] &= ~0x80;
raw_data[2] &= ~0x03;
if (mode != ssc->mode) {
hid_dbg(hdev, "entered mode %d\n", mode);
if (ssc->mode != -1) {
raw_data[1] |= 0x80;
}
ssc->mode = mode;
}
}
return 0;
}
static int saitek_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct saitek_sc *ssc = hid_get_drvdata(hdev);
struct input_dev *input = field->hidinput->input;
if (usage->type == EV_KEY && value &&
(((ssc->quirks & SAITEK_RELEASE_MODE_RAT7) &&
usage->code - BTN_MOUSE == 10) ||
((ssc->quirks & SAITEK_RELEASE_MODE_MMO7) &&
usage->code - BTN_MOUSE == 15))) {
input_report_key(input, usage->code, 1);
input_report_key(input, usage->code, 0);
return 1;
}
return 0;
}
