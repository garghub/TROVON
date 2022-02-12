static void asus_report_contact_down(struct asus_drvdata *drvdat,
int toolType, u8 *data)
{
struct input_dev *input = drvdat->input;
int touch_major, pressure, x, y;
x = (data[0] & CONTACT_X_MSB_MASK) << 4 | data[1];
y = drvdat->tp->max_y - ((data[0] & CONTACT_Y_MSB_MASK) << 8 | data[2]);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
if (drvdat->tp->contact_size < 5)
return;
if (toolType == MT_TOOL_PALM) {
touch_major = MAX_TOUCH_MAJOR;
pressure = MAX_PRESSURE;
} else {
touch_major = (data[3] >> 4) & CONTACT_TOUCH_MAJOR_MASK;
pressure = data[4] & CONTACT_PRESSURE_MASK;
}
input_report_abs(input, ABS_MT_TOUCH_MAJOR, touch_major);
input_report_abs(input, ABS_MT_PRESSURE, pressure);
}
static void asus_report_tool_width(struct asus_drvdata *drvdat)
{
struct input_mt *mt = drvdat->input->mt;
struct input_mt_slot *oldest;
int oldid, count, i;
if (drvdat->tp->contact_size < 5)
return;
oldest = NULL;
oldid = mt->trkid;
count = 0;
for (i = 0; i < mt->num_slots; ++i) {
struct input_mt_slot *ps = &mt->slots[i];
int id = input_mt_get_value(ps, ABS_MT_TRACKING_ID);
if (id < 0)
continue;
if ((id - oldid) & TRKID_SGN) {
oldest = ps;
oldid = id;
}
count++;
}
if (oldest) {
input_report_abs(drvdat->input, ABS_TOOL_WIDTH,
input_mt_get_value(oldest, ABS_MT_TOUCH_MAJOR));
}
}
static int asus_report_input(struct asus_drvdata *drvdat, u8 *data, int size)
{
int i, toolType = MT_TOOL_FINGER;
u8 *contactData = data + 2;
if (size != 3 + drvdat->tp->contact_size * drvdat->tp->max_contacts)
return 0;
for (i = 0; i < drvdat->tp->max_contacts; i++) {
bool down = !!(data[1] & BIT(i+3));
if (drvdat->tp->contact_size >= 5)
toolType = contactData[3] & CONTACT_TOOL_TYPE_MASK ?
MT_TOOL_PALM : MT_TOOL_FINGER;
input_mt_slot(drvdat->input, i);
input_mt_report_slot_state(drvdat->input, toolType, down);
if (down) {
asus_report_contact_down(drvdat, toolType, contactData);
contactData += drvdat->tp->contact_size;
}
}
input_report_key(drvdat->input, BTN_LEFT, data[1] & BTN_LEFT_MASK);
asus_report_tool_width(drvdat);
input_mt_sync_frame(drvdat->input);
input_sync(drvdat->input);
return 1;
}
static int asus_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->tp && data[0] == INPUT_REPORT_ID)
return asus_report_input(drvdata, data, size);
return 0;
}
static int asus_kbd_set_report(struct hid_device *hdev, u8 *buf, size_t buf_size)
{
unsigned char *dmabuf;
int ret;
dmabuf = kmemdup(buf, buf_size, GFP_KERNEL);
if (!dmabuf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, FEATURE_KBD_REPORT_ID, dmabuf,
buf_size, HID_FEATURE_REPORT,
HID_REQ_SET_REPORT);
kfree(dmabuf);
return ret;
}
static int asus_kbd_init(struct hid_device *hdev)
{
u8 buf[] = { FEATURE_KBD_REPORT_ID, 0x41, 0x53, 0x55, 0x53, 0x20, 0x54,
0x65, 0x63, 0x68, 0x2e, 0x49, 0x6e, 0x63, 0x2e, 0x00 };
int ret;
ret = asus_kbd_set_report(hdev, buf, sizeof(buf));
if (ret < 0)
hid_err(hdev, "Asus failed to send init command: %d\n", ret);
return ret;
}
static int asus_kbd_get_functions(struct hid_device *hdev,
unsigned char *kbd_func)
{
u8 buf[] = { FEATURE_KBD_REPORT_ID, 0x05, 0x20, 0x31, 0x00, 0x08 };
u8 *readbuf;
int ret;
ret = asus_kbd_set_report(hdev, buf, sizeof(buf));
if (ret < 0) {
hid_err(hdev, "Asus failed to send configuration command: %d\n", ret);
return ret;
}
readbuf = kzalloc(FEATURE_KBD_REPORT_SIZE, GFP_KERNEL);
if (!readbuf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, FEATURE_KBD_REPORT_ID, readbuf,
FEATURE_KBD_REPORT_SIZE, HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret < 0) {
hid_err(hdev, "Asus failed to request functions: %d\n", ret);
kfree(readbuf);
return ret;
}
*kbd_func = readbuf[6];
kfree(readbuf);
return ret;
}
static void asus_kbd_backlight_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct asus_kbd_leds *led = container_of(led_cdev, struct asus_kbd_leds,
cdev);
if (led->brightness == brightness)
return;
led->brightness = brightness;
schedule_work(&led->work);
}
static enum led_brightness asus_kbd_backlight_get(struct led_classdev *led_cdev)
{
struct asus_kbd_leds *led = container_of(led_cdev, struct asus_kbd_leds,
cdev);
return led->brightness;
}
static void asus_kbd_backlight_work(struct work_struct *work)
{
struct asus_kbd_leds *led = container_of(work, struct asus_kbd_leds, work);
u8 buf[] = { FEATURE_KBD_REPORT_ID, 0xba, 0xc5, 0xc4, 0x00 };
int ret;
if (led->removed)
return;
buf[4] = led->brightness;
ret = asus_kbd_set_report(led->hdev, buf, sizeof(buf));
if (ret < 0)
hid_err(led->hdev, "Asus failed to set keyboard backlight: %d\n", ret);
}
static int asus_kbd_register_leds(struct hid_device *hdev)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
unsigned char kbd_func;
int ret;
ret = asus_kbd_init(hdev);
if (ret < 0)
return ret;
ret = asus_kbd_get_functions(hdev, &kbd_func);
if (ret < 0)
return ret;
if (!(kbd_func & SUPPORT_KBD_BACKLIGHT))
return -ENODEV;
drvdata->kbd_backlight = devm_kzalloc(&hdev->dev,
sizeof(struct asus_kbd_leds),
GFP_KERNEL);
if (!drvdata->kbd_backlight)
return -ENOMEM;
drvdata->kbd_backlight->removed = false;
drvdata->kbd_backlight->brightness = 0;
drvdata->kbd_backlight->hdev = hdev;
drvdata->kbd_backlight->cdev.name = "asus::kbd_backlight";
drvdata->kbd_backlight->cdev.max_brightness = 3;
drvdata->kbd_backlight->cdev.brightness_set = asus_kbd_backlight_set;
drvdata->kbd_backlight->cdev.brightness_get = asus_kbd_backlight_get;
INIT_WORK(&drvdata->kbd_backlight->work, asus_kbd_backlight_work);
ret = devm_led_classdev_register(&hdev->dev, &drvdata->kbd_backlight->cdev);
if (ret < 0) {
devm_kfree(&hdev->dev, drvdata->kbd_backlight);
}
return ret;
}
static int asus_input_configured(struct hid_device *hdev, struct hid_input *hi)
{
struct input_dev *input = hi->input;
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->quirks & QUIRK_T100CHI &&
hi->report->id != T100CHI_MOUSE_REPORT_ID)
return 0;
if (drvdata->tp) {
int ret;
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
drvdata->tp->max_x, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
drvdata->tp->max_y, 0, 0);
input_abs_set_res(input, ABS_MT_POSITION_X, drvdata->tp->res_x);
input_abs_set_res(input, ABS_MT_POSITION_Y, drvdata->tp->res_y);
if (drvdata->tp->contact_size >= 5) {
input_set_abs_params(input, ABS_TOOL_WIDTH, 0,
MAX_TOUCH_MAJOR, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR, 0,
MAX_TOUCH_MAJOR, 0, 0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0,
MAX_PRESSURE, 0, 0);
}
__set_bit(BTN_LEFT, input->keybit);
__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);
ret = input_mt_init_slots(input, drvdata->tp->max_contacts,
INPUT_MT_POINTER);
if (ret) {
hid_err(hdev, "Asus input mt init slots failed: %d\n", ret);
return ret;
}
}
drvdata->input = input;
if (drvdata->enable_backlight && asus_kbd_register_leds(hdev))
hid_warn(hdev, "Failed to initialize backlight.\n");
return 0;
}
static int asus_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit,
int *max)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->quirks & QUIRK_SKIP_INPUT_MAPPING) {
return -1;
}
if (drvdata->quirks & QUIRK_T100CHI) {
if (field->application == (HID_UP_GENDESK | 0x0080) ||
usage->hid == (HID_UP_GENDEVCTRLS | 0x0024) ||
usage->hid == (HID_UP_GENDEVCTRLS | 0x0025) ||
usage->hid == (HID_UP_GENDEVCTRLS | 0x0026))
return -1;
if (field->application == HID_GD_MOUSE &&
usage->hid != (HID_UP_BUTTON | 1))
return -1;
}
if ((usage->hid & HID_USAGE_PAGE) == 0xff310000) {
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0x10: asus_map_key_clear(KEY_BRIGHTNESSDOWN); break;
case 0x20: asus_map_key_clear(KEY_BRIGHTNESSUP); break;
case 0x35: asus_map_key_clear(KEY_DISPLAY_OFF); break;
case 0x6c: asus_map_key_clear(KEY_SLEEP); break;
case 0x82: asus_map_key_clear(KEY_CAMERA); break;
case 0x88: asus_map_key_clear(KEY_RFKILL); break;
case 0xb5: asus_map_key_clear(KEY_CALC); break;
case 0xc4: asus_map_key_clear(KEY_KBDILLUMUP); break;
case 0xc5: asus_map_key_clear(KEY_KBDILLUMDOWN); break;
case 0x6b: asus_map_key_clear(KEY_F21); break;
case 0x38: asus_map_key_clear(KEY_PROG1); break;
case 0xba: asus_map_key_clear(KEY_PROG2); break;
case 0x5c: asus_map_key_clear(KEY_PROG3); break;
default:
return -1;
}
if (drvdata->quirks & QUIRK_USE_KBD_BACKLIGHT)
drvdata->enable_backlight = true;
return 1;
}
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_MSVENDOR) {
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0xff01: asus_map_key_clear(BTN_1); break;
case 0xff02: asus_map_key_clear(BTN_2); break;
case 0xff03: asus_map_key_clear(BTN_3); break;
case 0xff04: asus_map_key_clear(BTN_4); break;
case 0xff05: asus_map_key_clear(BTN_5); break;
case 0xff06: asus_map_key_clear(BTN_6); break;
case 0xff07: asus_map_key_clear(BTN_7); break;
case 0xff08: asus_map_key_clear(BTN_8); break;
case 0xff09: asus_map_key_clear(BTN_9); break;
case 0xff0a: asus_map_key_clear(BTN_A); break;
case 0xff0b: asus_map_key_clear(BTN_B); break;
case 0x00f1: asus_map_key_clear(KEY_WLAN); break;
case 0x00f2: asus_map_key_clear(KEY_BRIGHTNESSDOWN); break;
case 0x00f3: asus_map_key_clear(KEY_BRIGHTNESSUP); break;
case 0x00f4: asus_map_key_clear(KEY_DISPLAY_OFF); break;
case 0x00f7: asus_map_key_clear(KEY_CAMERA); break;
case 0x00f8: asus_map_key_clear(KEY_PROG1); break;
default:
return 0;
}
return 1;
}
if (drvdata->quirks & QUIRK_NO_CONSUMER_USAGES &&
(usage->hid & HID_USAGE_PAGE) == HID_UP_CONSUMER) {
switch (usage->hid & HID_USAGE) {
case 0xe2:
case 0xe9:
case 0xea:
return 0;
default:
return -1;
}
}
return 0;
}
static int asus_start_multitouch(struct hid_device *hdev)
{
int ret;
const unsigned char buf[] = { FEATURE_REPORT_ID, 0x00, 0x03, 0x01, 0x00 };
unsigned char *dmabuf = kmemdup(buf, sizeof(buf), GFP_KERNEL);
if (!dmabuf) {
ret = -ENOMEM;
hid_err(hdev, "Asus failed to alloc dma buf: %d\n", ret);
return ret;
}
ret = hid_hw_raw_request(hdev, dmabuf[0], dmabuf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
kfree(dmabuf);
if (ret != sizeof(buf)) {
hid_err(hdev, "Asus failed to start multitouch: %d\n", ret);
return ret;
}
return 0;
}
static int __maybe_unused asus_reset_resume(struct hid_device *hdev)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->tp)
return asus_start_multitouch(hdev);
return 0;
}
static int asus_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
struct asus_drvdata *drvdata;
drvdata = devm_kzalloc(&hdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (drvdata == NULL) {
hid_err(hdev, "Can't alloc Asus descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, drvdata);
drvdata->quirks = id->driver_data;
if (drvdata->quirks & QUIRK_IS_MULTITOUCH)
drvdata->tp = &asus_i2c_tp;
if (drvdata->quirks & QUIRK_T100_KEYBOARD) {
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
if (intf->altsetting->desc.bInterfaceNumber == T100_TPAD_INTF) {
drvdata->quirks = QUIRK_SKIP_INPUT_MAPPING;
drvdata->tp = &asus_t100ta_tp;
}
}
if (drvdata->quirks & QUIRK_T100CHI) {
hdev->quirks |= HID_QUIRK_MULTI_INPUT |
HID_QUIRK_NO_EMPTY_INPUT;
drvdata->tp = &asus_t100chi_tp;
}
if (drvdata->quirks & QUIRK_NO_INIT_REPORTS)
hdev->quirks |= HID_QUIRK_NO_INIT_REPORTS;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "Asus hid parse failed: %d\n", ret);
return ret;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "Asus hw start failed: %d\n", ret);
return ret;
}
if (!drvdata->input) {
hid_err(hdev, "Asus input not registered\n");
ret = -ENOMEM;
goto err_stop_hw;
}
if (drvdata->tp) {
drvdata->input->name = "Asus TouchPad";
} else {
drvdata->input->name = "Asus Keyboard";
}
if (drvdata->tp) {
ret = asus_start_multitouch(hdev);
if (ret)
goto err_stop_hw;
}
return 0;
err_stop_hw:
hid_hw_stop(hdev);
return ret;
}
static void asus_remove(struct hid_device *hdev)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->kbd_backlight) {
drvdata->kbd_backlight->removed = true;
cancel_work_sync(&drvdata->kbd_backlight->work);
}
hid_hw_stop(hdev);
}
static __u8 *asus_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct asus_drvdata *drvdata = hid_get_drvdata(hdev);
if (drvdata->quirks & QUIRK_FIX_NOTEBOOK_REPORT &&
*rsize >= 56 && rdesc[54] == 0x25 && rdesc[55] == 0x65) {
hid_info(hdev, "Fixing up Asus notebook report descriptor\n");
rdesc[55] = 0xdd;
}
if (drvdata->quirks & QUIRK_T100_KEYBOARD &&
*rsize == 76 && rdesc[73] == 0x81 && rdesc[74] == 0x01) {
hid_info(hdev, "Fixing up Asus T100 keyb report descriptor\n");
rdesc[74] &= ~HID_MAIN_ITEM_CONSTANT;
}
if (drvdata->quirks & QUIRK_T100CHI &&
*rsize == 403 && rdesc[388] == 0x09 && rdesc[389] == 0x76) {
*rsize = 404;
rdesc = kmemdup(rdesc, *rsize, GFP_KERNEL);
if (!rdesc)
return NULL;
hid_info(hdev, "Fixing up T100CHI keyb report descriptor\n");
memmove(rdesc + 392, rdesc + 390, 12);
rdesc[388] = 0x19;
rdesc[389] = 0x00;
rdesc[390] = 0x29;
rdesc[391] = 0xff;
rdesc[402] = 0x00;
}
return rdesc;
}
