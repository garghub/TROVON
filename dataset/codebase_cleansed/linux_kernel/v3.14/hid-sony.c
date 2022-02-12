static __u8 *ps3remote_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(ps3remote_rdesc);
return ps3remote_rdesc;
}
static int ps3remote_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned int key = usage->hid & HID_USAGE;
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_BUTTON)
return -1;
switch (usage->collection_index) {
case 1:
if (key >= ARRAY_SIZE(ps3remote_keymap_joypad_buttons))
return -1;
key = ps3remote_keymap_joypad_buttons[key];
if (!key)
return -1;
break;
case 2:
if (key >= ARRAY_SIZE(ps3remote_keymap_remote_buttons))
return -1;
key = ps3remote_keymap_remote_buttons[key];
if (!key)
return -1;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
}
static __u8 *sony_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & VAIO_RDESC_CONSTANT) && *rsize >= 56 &&
rdesc[2] == 0x09 && rdesc[3] == 0x02 &&
rdesc[54] == 0x81 && rdesc[55] == 0x07) {
hid_info(hdev, "Fixing up Sony RF Receiver report descriptor\n");
rdesc[55] = 0x06;
}
if ((sc->quirks & DUALSHOCK4_CONTROLLER_USB) && *rsize == 467) {
hid_info(hdev, "Using modified Dualshock 4 report descriptor with gyroscope axes\n");
rdesc = dualshock4_usb_rdesc;
*rsize = sizeof(dualshock4_usb_rdesc);
}
if ((((sc->quirks & SIXAXIS_CONTROLLER_USB) && *rsize == 148) ||
((sc->quirks & SIXAXIS_CONTROLLER_BT) && *rsize == 149)) &&
rdesc[83] == 0x75) {
hid_info(hdev, "Fixing up Sony Sixaxis report descriptor\n");
memcpy((void *)&rdesc[83], (void *)&sixaxis_rdesc_fixup,
sizeof(sixaxis_rdesc_fixup));
} else if (sc->quirks & SIXAXIS_CONTROLLER_USB &&
*rsize > sizeof(sixaxis_rdesc_fixup2)) {
hid_info(hdev, "Sony Sixaxis clone detected. Using original report descriptor (size: %d clone; %d new)\n",
*rsize, (int)sizeof(sixaxis_rdesc_fixup2));
*rsize = sizeof(sixaxis_rdesc_fixup2);
memcpy(rdesc, &sixaxis_rdesc_fixup2, *rsize);
}
if (sc->quirks & PS3REMOTE)
return ps3remote_fixup(hdev, rdesc, rsize);
return rdesc;
}
static int sony_raw_event(struct hid_device *hdev, struct hid_report *report,
__u8 *rd, int size)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & (SIXAXIS_CONTROLLER_USB | SIXAXIS_CONTROLLER_BT)) &&
rd[0] == 0x01 && size == 49) {
swap(rd[41], rd[42]);
swap(rd[43], rd[44]);
swap(rd[45], rd[46]);
swap(rd[47], rd[48]);
}
return 0;
}
static int sony_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & BUZZ_CONTROLLER) {
unsigned int key = usage->hid & HID_USAGE;
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_BUTTON)
return -1;
switch (usage->collection_index) {
case 1:
if (key >= ARRAY_SIZE(buzz_keymap))
return -1;
key = buzz_keymap[key];
if (!key)
return -1;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
}
if (sc->quirks & PS3REMOTE)
return ps3remote_mapping(hdev, hi, field, usage, bit, max);
return 0;
}
static int sixaxis_usb_output_raw_report(struct hid_device *hid, __u8 *buf,
size_t count, unsigned char report_type)
{
struct usb_interface *intf = to_usb_interface(hid->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_host_interface *interface = intf->cur_altsetting;
int report_id = buf[0];
int ret;
if (report_type == HID_OUTPUT_REPORT) {
buf++;
count--;
}
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
HID_REQ_SET_REPORT,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
((report_type + 1) << 8) | report_id,
interface->desc.bInterfaceNumber, buf, count,
USB_CTRL_SET_TIMEOUT);
if (ret > 0 && report_type == HID_OUTPUT_REPORT)
ret++;
return ret;
}
static int sixaxis_set_operational_usb(struct hid_device *hdev)
{
int ret;
char *buf = kmalloc(18, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hdev->hid_get_raw_report(hdev, 0xf2, buf, 17, HID_FEATURE_REPORT);
if (ret < 0)
hid_err(hdev, "can't set operational mode\n");
kfree(buf);
return ret;
}
static int sixaxis_set_operational_bt(struct hid_device *hdev)
{
unsigned char buf[] = { 0xf4, 0x42, 0x03, 0x00, 0x00 };
return hdev->hid_output_raw_report(hdev, buf, sizeof(buf), HID_FEATURE_REPORT);
}
static void buzz_set_leds(struct hid_device *hdev, const __u8 *leds)
{
struct list_head *report_list =
&hdev->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next,
struct hid_report, list);
__s32 *value = report->field[0]->value;
value[0] = 0x00;
value[1] = leds[0] ? 0xff : 0x00;
value[2] = leds[1] ? 0xff : 0x00;
value[3] = leds[2] ? 0xff : 0x00;
value[4] = leds[3] ? 0xff : 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static void sony_set_leds(struct hid_device *hdev, const __u8 *leds, int count)
{
struct sony_sc *drv_data = hid_get_drvdata(hdev);
int n;
BUG_ON(count > MAX_LEDS);
if (drv_data->quirks & BUZZ_CONTROLLER && count == 4) {
buzz_set_leds(hdev, leds);
} else if ((drv_data->quirks & SIXAXIS_CONTROLLER_USB) ||
(drv_data->quirks & DUALSHOCK4_CONTROLLER_USB)) {
for (n = 0; n < count; n++)
drv_data->led_state[n] = leds[n];
schedule_work(&drv_data->state_worker);
}
}
static void sony_led_set_brightness(struct led_classdev *led,
enum led_brightness value)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct sony_sc *drv_data;
int n;
drv_data = hid_get_drvdata(hdev);
if (!drv_data) {
hid_err(hdev, "No device data\n");
return;
}
for (n = 0; n < drv_data->led_count; n++) {
if (led == drv_data->leds[n]) {
if (value != drv_data->led_state[n]) {
drv_data->led_state[n] = value;
sony_set_leds(hdev, drv_data->led_state, drv_data->led_count);
}
break;
}
}
}
static enum led_brightness sony_led_get_brightness(struct led_classdev *led)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct sony_sc *drv_data;
int n;
int on = 0;
drv_data = hid_get_drvdata(hdev);
if (!drv_data) {
hid_err(hdev, "No device data\n");
return LED_OFF;
}
for (n = 0; n < drv_data->led_count; n++) {
if (led == drv_data->leds[n]) {
on = !!(drv_data->led_state[n]);
break;
}
}
return on ? LED_FULL : LED_OFF;
}
static void sony_leds_remove(struct hid_device *hdev)
{
struct sony_sc *drv_data;
struct led_classdev *led;
int n;
drv_data = hid_get_drvdata(hdev);
BUG_ON(!(drv_data->quirks & SONY_LED_SUPPORT));
for (n = 0; n < drv_data->led_count; n++) {
led = drv_data->leds[n];
drv_data->leds[n] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
drv_data->led_count = 0;
}
static int sony_leds_init(struct hid_device *hdev)
{
struct sony_sc *drv_data;
int n, ret = 0;
int max_brightness;
int use_colors;
struct led_classdev *led;
size_t name_sz;
char *name;
size_t name_len;
const char *name_fmt;
static const char * const color_str[] = { "red", "green", "blue" };
static const __u8 initial_values[MAX_LEDS] = { 0x00, 0x00, 0x00, 0x00 };
drv_data = hid_get_drvdata(hdev);
BUG_ON(!(drv_data->quirks & SONY_LED_SUPPORT));
if (drv_data->quirks & BUZZ_CONTROLLER) {
drv_data->led_count = 4;
max_brightness = 1;
use_colors = 0;
name_len = strlen("::buzz#");
name_fmt = "%s::buzz%d";
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 0, 0, 7))
return -ENODEV;
} else if (drv_data->quirks & DUALSHOCK4_CONTROLLER_USB) {
drv_data->led_count = 3;
max_brightness = 255;
use_colors = 1;
name_len = 0;
name_fmt = "%s:%s";
} else {
drv_data->led_count = 4;
max_brightness = 1;
use_colors = 0;
name_len = strlen("::sony#");
name_fmt = "%s::sony%d";
}
sony_set_leds(hdev, initial_values, drv_data->led_count);
name_sz = strlen(dev_name(&hdev->dev)) + name_len + 1;
for (n = 0; n < drv_data->led_count; n++) {
if (use_colors)
name_sz = strlen(dev_name(&hdev->dev)) + strlen(color_str[n]) + 2;
led = kzalloc(sizeof(struct led_classdev) + name_sz, GFP_KERNEL);
if (!led) {
hid_err(hdev, "Couldn't allocate memory for LED %d\n", n);
ret = -ENOMEM;
goto error_leds;
}
name = (void *)(&led[1]);
if (use_colors)
snprintf(name, name_sz, name_fmt, dev_name(&hdev->dev), color_str[n]);
else
snprintf(name, name_sz, name_fmt, dev_name(&hdev->dev), n + 1);
led->name = name;
led->brightness = 0;
led->max_brightness = max_brightness;
led->brightness_get = sony_led_get_brightness;
led->brightness_set = sony_led_set_brightness;
ret = led_classdev_register(&hdev->dev, led);
if (ret) {
hid_err(hdev, "Failed to register LED %d\n", n);
kfree(led);
goto error_leds;
}
drv_data->leds[n] = led;
}
return ret;
error_leds:
sony_leds_remove(hdev);
return ret;
}
static void sixaxis_state_worker(struct work_struct *work)
{
struct sony_sc *sc = container_of(work, struct sony_sc, state_worker);
unsigned char buf[] = {
0x01,
0x00, 0xff, 0x00, 0xff, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0x00, 0x00, 0x00, 0x00, 0x00
};
#ifdef CONFIG_SONY_FF
buf[3] = sc->right ? 1 : 0;
buf[5] = sc->left;
#endif
buf[10] |= sc->led_state[0] << 1;
buf[10] |= sc->led_state[1] << 2;
buf[10] |= sc->led_state[2] << 3;
buf[10] |= sc->led_state[3] << 4;
sc->hdev->hid_output_raw_report(sc->hdev, buf, sizeof(buf),
HID_OUTPUT_REPORT);
}
static void dualshock4_state_worker(struct work_struct *work)
{
struct sony_sc *sc = container_of(work, struct sony_sc, state_worker);
struct hid_device *hdev = sc->hdev;
struct hid_report *report = sc->output_report;
__s32 *value = report->field[0]->value;
value[0] = 0x03;
#ifdef CONFIG_SONY_FF
value[3] = sc->right;
value[4] = sc->left;
#endif
value[5] = sc->led_state[0];
value[6] = sc->led_state[1];
value[7] = sc->led_state[2];
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static int sony_play_effect(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct sony_sc *sc = hid_get_drvdata(hid);
if (effect->type != FF_RUMBLE)
return 0;
sc->left = effect->u.rumble.strong_magnitude / 256;
sc->right = effect->u.rumble.weak_magnitude / 256;
schedule_work(&sc->state_worker);
return 0;
}
static int sony_init_ff(struct hid_device *hdev)
{
struct hid_input *hidinput = list_entry(hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
input_set_capability(input_dev, EV_FF, FF_RUMBLE);
return input_ff_create_memless(input_dev, NULL, sony_play_effect);
}
static int sony_init_ff(struct hid_device *hdev)
{
return 0;
}
static int sony_set_output_report(struct sony_sc *sc, int req_id, int req_size)
{
struct list_head *head, *list;
struct hid_report *report;
struct hid_device *hdev = sc->hdev;
list = &hdev->report_enum[HID_OUTPUT_REPORT].report_list;
list_for_each(head, list) {
report = list_entry(head, struct hid_report, list);
if (report->id == req_id) {
if (report->size < req_size) {
hid_err(hdev, "Output report 0x%02x (%i bits) is smaller than requested size (%i bits)\n",
req_id, report->size, req_size);
return -EINVAL;
}
sc->output_report = report;
return 0;
}
}
hid_err(hdev, "Unable to locate output report 0x%02x\n", req_id);
return -EINVAL;
}
static int sony_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
unsigned long quirks = id->driver_data;
struct sony_sc *sc;
unsigned int connect_mask = HID_CONNECT_DEFAULT;
sc = devm_kzalloc(&hdev->dev, sizeof(*sc), GFP_KERNEL);
if (sc == NULL) {
hid_err(hdev, "can't alloc sony descriptor\n");
return -ENOMEM;
}
sc->quirks = quirks;
hid_set_drvdata(hdev, sc);
sc->hdev = hdev;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
if (sc->quirks & VAIO_RDESC_CONSTANT)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
else if (sc->quirks & SIXAXIS_CONTROLLER_USB)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
else if (sc->quirks & SIXAXIS_CONTROLLER_BT)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
if (sc->quirks & SIXAXIS_CONTROLLER_USB) {
hdev->hid_output_raw_report = sixaxis_usb_output_raw_report;
ret = sixaxis_set_operational_usb(hdev);
sc->worker_initialized = 1;
INIT_WORK(&sc->state_worker, sixaxis_state_worker);
}
else if (sc->quirks & SIXAXIS_CONTROLLER_BT)
ret = sixaxis_set_operational_bt(hdev);
else if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
ret = sony_set_output_report(sc, 0x05, 248);
if (ret < 0)
goto err_stop;
sc->worker_initialized = 1;
INIT_WORK(&sc->state_worker, dualshock4_state_worker);
} else {
ret = 0;
}
if (ret < 0)
goto err_stop;
if (sc->quirks & SONY_LED_SUPPORT) {
ret = sony_leds_init(hdev);
if (ret < 0)
goto err_stop;
}
if (sc->quirks & SONY_FF_SUPPORT) {
ret = sony_init_ff(hdev);
if (ret < 0)
goto err_stop;
}
return 0;
err_stop:
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(hdev);
hid_hw_stop(hdev);
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(hdev);
if (sc->worker_initialized)
cancel_work_sync(&sc->state_worker);
hid_hw_stop(hdev);
}
