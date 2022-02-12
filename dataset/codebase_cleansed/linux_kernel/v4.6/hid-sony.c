static u8 *sixaxis_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(sixaxis_rdesc);
return sixaxis_rdesc;
}
static u8 *motion_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(motion_rdesc);
return motion_rdesc;
}
static u8 *navigation_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(navigation_rdesc);
return navigation_rdesc;
}
static u8 *ps3remote_fixup(struct hid_device *hdev, u8 *rdesc,
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
static u8 *sony_report_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & SINO_LITE_CONTROLLER)
return rdesc;
if ((sc->quirks & VAIO_RDESC_CONSTANT) && *rsize >= 56 &&
rdesc[2] == 0x09 && rdesc[3] == 0x02 &&
rdesc[54] == 0x81 && rdesc[55] == 0x07) {
hid_info(hdev, "Fixing up Sony RF Receiver report descriptor\n");
rdesc[55] = 0x06;
}
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
hid_info(hdev, "Using modified Dualshock 4 report descriptor with gyroscope axes\n");
rdesc = dualshock4_usb_rdesc;
*rsize = sizeof(dualshock4_usb_rdesc);
} else if (sc->quirks & DUALSHOCK4_CONTROLLER_BT) {
hid_info(hdev, "Using modified Dualshock 4 Bluetooth report descriptor\n");
rdesc = dualshock4_bt_rdesc;
*rsize = sizeof(dualshock4_bt_rdesc);
}
if (sc->quirks & SIXAXIS_CONTROLLER)
return sixaxis_fixup(hdev, rdesc, rsize);
if (sc->quirks & MOTION_CONTROLLER)
return motion_fixup(hdev, rdesc, rsize);
if (sc->quirks & NAVIGATION_CONTROLLER)
return navigation_fixup(hdev, rdesc, rsize);
if (sc->quirks & PS3REMOTE)
return ps3remote_fixup(hdev, rdesc, rsize);
return rdesc;
}
static void sixaxis_parse_report(struct sony_sc *sc, u8 *rd, int size)
{
static const u8 sixaxis_battery_capacity[] = { 0, 1, 25, 50, 75, 100 };
unsigned long flags;
int offset;
u8 cable_state, battery_capacity, battery_charging;
offset = (sc->quirks & MOTION_CONTROLLER) ? 12 : 30;
if (rd[offset] >= 0xee) {
battery_capacity = 100;
battery_charging = !(rd[offset] & 0x01);
cable_state = 1;
} else {
u8 index = rd[offset] <= 5 ? rd[offset] : 5;
battery_capacity = sixaxis_battery_capacity[index];
battery_charging = 0;
cable_state = 0;
}
spin_lock_irqsave(&sc->lock, flags);
sc->cable_state = cable_state;
sc->battery_capacity = battery_capacity;
sc->battery_charging = battery_charging;
spin_unlock_irqrestore(&sc->lock, flags);
}
static void dualshock4_parse_report(struct sony_sc *sc, u8 *rd, int size)
{
struct hid_input *hidinput = list_entry(sc->hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
unsigned long flags;
int n, offset;
u8 cable_state, battery_capacity, battery_charging;
offset = (sc->quirks & DUALSHOCK4_CONTROLLER_USB) ? 30 : 32;
cable_state = (rd[offset] >> 4) & 0x01;
battery_capacity = rd[offset] & 0x0F;
if (!cable_state || battery_capacity > 10)
battery_charging = 0;
else
battery_charging = 1;
if (!cable_state)
battery_capacity++;
if (battery_capacity > 10)
battery_capacity = 10;
battery_capacity *= 10;
spin_lock_irqsave(&sc->lock, flags);
sc->cable_state = cable_state;
sc->battery_capacity = battery_capacity;
sc->battery_charging = battery_charging;
spin_unlock_irqrestore(&sc->lock, flags);
offset += 5;
for (n = 0; n < 2; n++) {
u16 x, y;
x = rd[offset+1] | ((rd[offset+2] & 0xF) << 8);
y = ((rd[offset+2] & 0xF0) >> 4) | (rd[offset+3] << 4);
input_mt_slot(input_dev, n);
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER,
!(rd[offset] >> 7));
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
offset += 4;
}
}
static int sony_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *rd, int size)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & SIXAXIS_CONTROLLER) && rd[0] == 0x01 && size == 49) {
if (rd[1] == 0xff)
return -EINVAL;
swap(rd[41], rd[42]);
swap(rd[43], rd[44]);
swap(rd[45], rd[46]);
swap(rd[47], rd[48]);
sixaxis_parse_report(sc, rd, size);
} else if ((sc->quirks & MOTION_CONTROLLER_BT) && rd[0] == 0x01 && size == 49) {
sixaxis_parse_report(sc, rd, size);
} else if ((sc->quirks & NAVIGATION_CONTROLLER) && rd[0] == 0x01 &&
size == 49) {
sixaxis_parse_report(sc, rd, size);
} else if (((sc->quirks & DUALSHOCK4_CONTROLLER_USB) && rd[0] == 0x01 &&
size == 64) || ((sc->quirks & DUALSHOCK4_CONTROLLER_BT)
&& rd[0] == 0x11 && size == 78)) {
dualshock4_parse_report(sc, rd, size);
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
static int sony_register_touchpad(struct hid_input *hi, int touch_count,
int w, int h)
{
struct input_dev *input_dev = hi->input;
int ret;
ret = input_mt_init_slots(input_dev, touch_count, 0);
if (ret < 0)
return ret;
input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0, w, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0, h, 0, 0);
return 0;
}
static int sony_input_configured(struct hid_device *hdev,
struct hid_input *hidinput)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
int ret;
if (sc->quirks & DUALSHOCK4_CONTROLLER) {
ret = sony_register_touchpad(hidinput, 2, 1920, 942);
if (ret) {
hid_err(sc->hdev,
"Unable to initialize multi-touch slots: %d\n",
ret);
return ret;
}
}
return 0;
}
static int sixaxis_set_operational_usb(struct hid_device *hdev)
{
const int buf_size =
max(SIXAXIS_REPORT_0xF2_SIZE, SIXAXIS_REPORT_0xF5_SIZE);
u8 *buf;
int ret;
buf = kmalloc(buf_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, 0xf2, buf, SIXAXIS_REPORT_0xF2_SIZE,
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret < 0) {
hid_err(hdev, "can't set operational mode: step 1\n");
goto out;
}
ret = hid_hw_raw_request(hdev, 0xf5, buf, SIXAXIS_REPORT_0xF5_SIZE,
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret < 0) {
hid_err(hdev, "can't set operational mode: step 2\n");
goto out;
}
ret = hid_hw_output_report(hdev, buf, 1);
if (ret < 0) {
hid_info(hdev, "can't set operational mode: step 3, ignoring\n");
ret = 0;
}
out:
kfree(buf);
return ret;
}
static int sixaxis_set_operational_bt(struct hid_device *hdev)
{
static const u8 report[] = { 0xf4, 0x42, 0x03, 0x00, 0x00 };
u8 *buf;
int ret;
buf = kmemdup(report, sizeof(report), GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, buf[0], buf, sizeof(report),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
kfree(buf);
return ret;
}
static int dualshock4_set_operational_bt(struct hid_device *hdev)
{
u8 *buf;
int ret;
buf = kmalloc(DS4_REPORT_0x02_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, 0x02, buf, DS4_REPORT_0x02_SIZE,
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
kfree(buf);
return ret;
}
static void sixaxis_set_leds_from_id(struct sony_sc *sc)
{
static const u8 sixaxis_leds[10][4] = {
{ 0x01, 0x00, 0x00, 0x00 },
{ 0x00, 0x01, 0x00, 0x00 },
{ 0x00, 0x00, 0x01, 0x00 },
{ 0x00, 0x00, 0x00, 0x01 },
{ 0x01, 0x00, 0x00, 0x01 },
{ 0x00, 0x01, 0x00, 0x01 },
{ 0x00, 0x00, 0x01, 0x01 },
{ 0x01, 0x00, 0x01, 0x01 },
{ 0x00, 0x01, 0x01, 0x01 },
{ 0x01, 0x01, 0x01, 0x01 }
};
int id = sc->device_id;
BUILD_BUG_ON(MAX_LEDS < ARRAY_SIZE(sixaxis_leds[0]));
if (id < 0)
return;
id %= 10;
memcpy(sc->led_state, sixaxis_leds[id], sizeof(sixaxis_leds[id]));
}
static void dualshock4_set_leds_from_id(struct sony_sc *sc)
{
static const u8 color_code[7][3] = {
{ 0x00, 0x00, 0x01 },
{ 0x01, 0x00, 0x00 },
{ 0x00, 0x01, 0x00 },
{ 0x02, 0x00, 0x01 },
{ 0x02, 0x01, 0x00 },
{ 0x00, 0x01, 0x01 },
{ 0x01, 0x01, 0x01 }
};
int id = sc->device_id;
BUILD_BUG_ON(MAX_LEDS < ARRAY_SIZE(color_code[0]));
if (id < 0)
return;
id %= 7;
memcpy(sc->led_state, color_code[id], sizeof(color_code[id]));
}
static void buzz_set_leds(struct sony_sc *sc)
{
struct hid_device *hdev = sc->hdev;
struct list_head *report_list =
&hdev->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next,
struct hid_report, list);
s32 *value = report->field[0]->value;
BUILD_BUG_ON(MAX_LEDS < 4);
value[0] = 0x00;
value[1] = sc->led_state[0] ? 0xff : 0x00;
value[2] = sc->led_state[1] ? 0xff : 0x00;
value[3] = sc->led_state[2] ? 0xff : 0x00;
value[4] = sc->led_state[3] ? 0xff : 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static void sony_set_leds(struct sony_sc *sc)
{
if (!(sc->quirks & BUZZ_CONTROLLER))
schedule_work(&sc->state_worker);
else
buzz_set_leds(sc);
}
static void sony_led_set_brightness(struct led_classdev *led,
enum led_brightness value)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = to_hid_device(dev);
struct sony_sc *drv_data;
int n;
int force_update;
drv_data = hid_get_drvdata(hdev);
if (!drv_data) {
hid_err(hdev, "No device data\n");
return;
}
force_update = !!(drv_data->quirks & SIXAXIS_CONTROLLER_USB);
for (n = 0; n < drv_data->led_count; n++) {
if (led == drv_data->leds[n] && (force_update ||
(value != drv_data->led_state[n] ||
drv_data->led_delay_on[n] ||
drv_data->led_delay_off[n]))) {
drv_data->led_state[n] = value;
drv_data->led_delay_on[n] = 0;
drv_data->led_delay_off[n] = 0;
sony_set_leds(drv_data);
break;
}
}
}
static enum led_brightness sony_led_get_brightness(struct led_classdev *led)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = to_hid_device(dev);
struct sony_sc *drv_data;
int n;
drv_data = hid_get_drvdata(hdev);
if (!drv_data) {
hid_err(hdev, "No device data\n");
return LED_OFF;
}
for (n = 0; n < drv_data->led_count; n++) {
if (led == drv_data->leds[n])
return drv_data->led_state[n];
}
return LED_OFF;
}
static int sony_led_blink_set(struct led_classdev *led, unsigned long *delay_on,
unsigned long *delay_off)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = to_hid_device(dev);
struct sony_sc *drv_data = hid_get_drvdata(hdev);
int n;
u8 new_on, new_off;
if (!drv_data) {
hid_err(hdev, "No device data\n");
return -EINVAL;
}
if (*delay_on > 2550)
*delay_on = 2550;
if (*delay_off > 2550)
*delay_off = 2550;
if (!*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
new_on = *delay_on / 10;
new_off = *delay_off / 10;
for (n = 0; n < drv_data->led_count; n++) {
if (led == drv_data->leds[n])
break;
}
if (n >= drv_data->led_count)
return -EINVAL;
if (new_on != drv_data->led_delay_on[n] ||
new_off != drv_data->led_delay_off[n]) {
drv_data->led_delay_on[n] = new_on;
drv_data->led_delay_off[n] = new_off;
schedule_work(&drv_data->state_worker);
}
return 0;
}
static void sony_leds_remove(struct sony_sc *sc)
{
struct led_classdev *led;
int n;
BUG_ON(!(sc->quirks & SONY_LED_SUPPORT));
for (n = 0; n < sc->led_count; n++) {
led = sc->leds[n];
sc->leds[n] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
sc->led_count = 0;
}
static int sony_leds_init(struct sony_sc *sc)
{
struct hid_device *hdev = sc->hdev;
int n, ret = 0;
int use_ds4_names;
struct led_classdev *led;
size_t name_sz;
char *name;
size_t name_len;
const char *name_fmt;
static const char * const ds4_name_str[] = { "red", "green", "blue",
"global" };
u8 max_brightness[MAX_LEDS] = { [0 ... (MAX_LEDS - 1)] = 1 };
u8 use_hw_blink[MAX_LEDS] = { 0 };
BUG_ON(!(sc->quirks & SONY_LED_SUPPORT));
if (sc->quirks & BUZZ_CONTROLLER) {
sc->led_count = 4;
use_ds4_names = 0;
name_len = strlen("::buzz#");
name_fmt = "%s::buzz%d";
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 0, 0, 7))
return -ENODEV;
} else if (sc->quirks & DUALSHOCK4_CONTROLLER) {
dualshock4_set_leds_from_id(sc);
sc->led_state[3] = 1;
sc->led_count = 4;
memset(max_brightness, 255, 3);
use_hw_blink[3] = 1;
use_ds4_names = 1;
name_len = 0;
name_fmt = "%s:%s";
} else if (sc->quirks & MOTION_CONTROLLER) {
sc->led_count = 3;
memset(max_brightness, 255, 3);
use_ds4_names = 1;
name_len = 0;
name_fmt = "%s:%s";
} else if (sc->quirks & NAVIGATION_CONTROLLER) {
static const u8 navigation_leds[4] = {0x01, 0x00, 0x00, 0x00};
memcpy(sc->led_state, navigation_leds, sizeof(navigation_leds));
sc->led_count = 1;
memset(use_hw_blink, 1, 4);
use_ds4_names = 0;
name_len = strlen("::sony#");
name_fmt = "%s::sony%d";
} else {
sixaxis_set_leds_from_id(sc);
sc->led_count = 4;
memset(use_hw_blink, 1, 4);
use_ds4_names = 0;
name_len = strlen("::sony#");
name_fmt = "%s::sony%d";
}
sony_set_leds(sc);
name_sz = strlen(dev_name(&hdev->dev)) + name_len + 1;
for (n = 0; n < sc->led_count; n++) {
if (use_ds4_names)
name_sz = strlen(dev_name(&hdev->dev)) + strlen(ds4_name_str[n]) + 2;
led = kzalloc(sizeof(struct led_classdev) + name_sz, GFP_KERNEL);
if (!led) {
hid_err(hdev, "Couldn't allocate memory for LED %d\n", n);
ret = -ENOMEM;
goto error_leds;
}
name = (void *)(&led[1]);
if (use_ds4_names)
snprintf(name, name_sz, name_fmt, dev_name(&hdev->dev),
ds4_name_str[n]);
else
snprintf(name, name_sz, name_fmt, dev_name(&hdev->dev), n + 1);
led->name = name;
led->brightness = sc->led_state[n];
led->max_brightness = max_brightness[n];
led->brightness_get = sony_led_get_brightness;
led->brightness_set = sony_led_set_brightness;
if (use_hw_blink[n])
led->blink_set = sony_led_blink_set;
sc->leds[n] = led;
ret = led_classdev_register(&hdev->dev, led);
if (ret) {
hid_err(hdev, "Failed to register LED %d\n", n);
sc->leds[n] = NULL;
kfree(led);
goto error_leds;
}
}
return ret;
error_leds:
sony_leds_remove(sc);
return ret;
}
static void sixaxis_send_output_report(struct sony_sc *sc)
{
static const union sixaxis_output_report_01 default_report = {
.buf = {
0x01,
0x01, 0xff, 0x00, 0xff, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0xff, 0x27, 0x10, 0x00, 0x32,
0x00, 0x00, 0x00, 0x00, 0x00
}
};
struct sixaxis_output_report *report =
(struct sixaxis_output_report *)sc->output_report_dmabuf;
int n;
memcpy(report, &default_report, sizeof(struct sixaxis_output_report));
#ifdef CONFIG_SONY_FF
report->rumble.right_motor_on = sc->right ? 1 : 0;
report->rumble.left_motor_force = sc->left;
#endif
report->leds_bitmap |= sc->led_state[0] << 1;
report->leds_bitmap |= sc->led_state[1] << 2;
report->leds_bitmap |= sc->led_state[2] << 3;
report->leds_bitmap |= sc->led_state[3] << 4;
if ((report->leds_bitmap & 0x1E) == 0)
report->leds_bitmap |= 0x20;
for (n = 0; n < 4; n++) {
if (sc->led_delay_on[n] || sc->led_delay_off[n]) {
report->led[3 - n].duty_off = sc->led_delay_off[n];
report->led[3 - n].duty_on = sc->led_delay_on[n];
}
}
hid_hw_raw_request(sc->hdev, report->report_id, (u8 *)report,
sizeof(struct sixaxis_output_report),
HID_OUTPUT_REPORT, HID_REQ_SET_REPORT);
}
static void dualshock4_send_output_report(struct sony_sc *sc)
{
struct hid_device *hdev = sc->hdev;
u8 *buf = sc->output_report_dmabuf;
int offset;
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
memset(buf, 0, DS4_REPORT_0x05_SIZE);
buf[0] = 0x05;
buf[1] = 0xFF;
offset = 4;
} else {
memset(buf, 0, DS4_REPORT_0x11_SIZE);
buf[0] = 0x11;
buf[1] = 0x80;
buf[3] = 0x0F;
offset = 6;
}
#ifdef CONFIG_SONY_FF
buf[offset++] = sc->right;
buf[offset++] = sc->left;
#else
offset += 2;
#endif
if (sc->led_state[3]) {
buf[offset++] = sc->led_state[0];
buf[offset++] = sc->led_state[1];
buf[offset++] = sc->led_state[2];
} else {
offset += 3;
}
buf[offset++] = sc->led_delay_on[3];
buf[offset++] = sc->led_delay_off[3];
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB)
hid_hw_output_report(hdev, buf, DS4_REPORT_0x05_SIZE);
else
hid_hw_raw_request(hdev, 0x11, buf, DS4_REPORT_0x11_SIZE,
HID_OUTPUT_REPORT, HID_REQ_SET_REPORT);
}
static void motion_send_output_report(struct sony_sc *sc)
{
struct hid_device *hdev = sc->hdev;
struct motion_output_report_02 *report =
(struct motion_output_report_02 *)sc->output_report_dmabuf;
memset(report, 0, MOTION_REPORT_0x02_SIZE);
report->type = 0x02;
report->r = sc->led_state[0];
report->g = sc->led_state[1];
report->b = sc->led_state[2];
#ifdef CONFIG_SONY_FF
report->rumble = max(sc->right, sc->left);
#endif
hid_hw_output_report(hdev, (u8 *)report, MOTION_REPORT_0x02_SIZE);
}
static inline void sony_send_output_report(struct sony_sc *sc)
{
if (sc->send_output_report)
sc->send_output_report(sc);
}
static void sony_state_worker(struct work_struct *work)
{
struct sony_sc *sc = container_of(work, struct sony_sc, state_worker);
sc->send_output_report(sc);
}
static int sony_allocate_output_report(struct sony_sc *sc)
{
if ((sc->quirks & SIXAXIS_CONTROLLER) ||
(sc->quirks & NAVIGATION_CONTROLLER))
sc->output_report_dmabuf =
kmalloc(sizeof(union sixaxis_output_report_01),
GFP_KERNEL);
else if (sc->quirks & DUALSHOCK4_CONTROLLER_BT)
sc->output_report_dmabuf = kmalloc(DS4_REPORT_0x11_SIZE,
GFP_KERNEL);
else if (sc->quirks & DUALSHOCK4_CONTROLLER_USB)
sc->output_report_dmabuf = kmalloc(DS4_REPORT_0x05_SIZE,
GFP_KERNEL);
else if (sc->quirks & MOTION_CONTROLLER)
sc->output_report_dmabuf = kmalloc(MOTION_REPORT_0x02_SIZE,
GFP_KERNEL);
else
return 0;
if (!sc->output_report_dmabuf)
return -ENOMEM;
return 0;
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
static int sony_init_ff(struct sony_sc *sc)
{
struct hid_input *hidinput = list_entry(sc->hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
input_set_capability(input_dev, EV_FF, FF_RUMBLE);
return input_ff_create_memless(input_dev, NULL, sony_play_effect);
}
static int sony_init_ff(struct sony_sc *sc)
{
return 0;
}
static int sony_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct sony_sc *sc = power_supply_get_drvdata(psy);
unsigned long flags;
int ret = 0;
u8 battery_charging, battery_capacity, cable_state;
spin_lock_irqsave(&sc->lock, flags);
battery_charging = sc->battery_charging;
battery_capacity = sc->battery_capacity;
cable_state = sc->cable_state;
spin_unlock_irqrestore(&sc->lock, flags);
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = 1;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_DEVICE;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = battery_capacity;
break;
case POWER_SUPPLY_PROP_STATUS:
if (battery_charging)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
if (battery_capacity == 100 && cable_state)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int sony_battery_probe(struct sony_sc *sc)
{
struct power_supply_config psy_cfg = { .drv_data = sc, };
struct hid_device *hdev = sc->hdev;
int ret;
sc->battery_capacity = 100;
sc->battery_desc.properties = sony_battery_props;
sc->battery_desc.num_properties = ARRAY_SIZE(sony_battery_props);
sc->battery_desc.get_property = sony_battery_get_property;
sc->battery_desc.type = POWER_SUPPLY_TYPE_BATTERY;
sc->battery_desc.use_for_apm = 0;
sc->battery_desc.name = kasprintf(GFP_KERNEL,
"sony_controller_battery_%pMR",
sc->mac_address);
if (!sc->battery_desc.name)
return -ENOMEM;
sc->battery = power_supply_register(&hdev->dev, &sc->battery_desc,
&psy_cfg);
if (IS_ERR(sc->battery)) {
ret = PTR_ERR(sc->battery);
hid_err(hdev, "Unable to register battery device\n");
goto err_free;
}
power_supply_powers(sc->battery, &hdev->dev);
return 0;
err_free:
kfree(sc->battery_desc.name);
sc->battery_desc.name = NULL;
return ret;
}
static void sony_battery_remove(struct sony_sc *sc)
{
if (!sc->battery_desc.name)
return;
power_supply_unregister(sc->battery);
kfree(sc->battery_desc.name);
sc->battery_desc.name = NULL;
}
static int sony_check_add_dev_list(struct sony_sc *sc)
{
struct sony_sc *entry;
unsigned long flags;
int ret;
spin_lock_irqsave(&sony_dev_list_lock, flags);
list_for_each_entry(entry, &sony_device_list, list_node) {
ret = memcmp(sc->mac_address, entry->mac_address,
sizeof(sc->mac_address));
if (!ret) {
ret = -EEXIST;
hid_info(sc->hdev, "controller with MAC address %pMR already connected\n",
sc->mac_address);
goto unlock;
}
}
ret = 0;
list_add(&(sc->list_node), &sony_device_list);
unlock:
spin_unlock_irqrestore(&sony_dev_list_lock, flags);
return ret;
}
static void sony_remove_dev_list(struct sony_sc *sc)
{
unsigned long flags;
if (sc->list_node.next) {
spin_lock_irqsave(&sony_dev_list_lock, flags);
list_del(&(sc->list_node));
spin_unlock_irqrestore(&sony_dev_list_lock, flags);
}
}
static int sony_get_bt_devaddr(struct sony_sc *sc)
{
int ret;
ret = strlen(sc->hdev->uniq);
if (ret != 17)
return -EINVAL;
ret = sscanf(sc->hdev->uniq,
"%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
&sc->mac_address[5], &sc->mac_address[4], &sc->mac_address[3],
&sc->mac_address[2], &sc->mac_address[1], &sc->mac_address[0]);
if (ret != 6)
return -EINVAL;
return 0;
}
static int sony_check_add(struct sony_sc *sc)
{
u8 *buf = NULL;
int n, ret;
if ((sc->quirks & DUALSHOCK4_CONTROLLER_BT) ||
(sc->quirks & MOTION_CONTROLLER_BT) ||
(sc->quirks & NAVIGATION_CONTROLLER_BT) ||
(sc->quirks & SIXAXIS_CONTROLLER_BT)) {
if (sony_get_bt_devaddr(sc) < 0) {
hid_warn(sc->hdev, "UNIQ does not contain a MAC address; duplicate check skipped\n");
return 0;
}
} else if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
buf = kmalloc(DS4_REPORT_0x81_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(sc->hdev, 0x81, buf,
DS4_REPORT_0x81_SIZE, HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret != DS4_REPORT_0x81_SIZE) {
hid_err(sc->hdev, "failed to retrieve feature report 0x81 with the DualShock 4 MAC address\n");
ret = ret < 0 ? ret : -EINVAL;
goto out_free;
}
memcpy(sc->mac_address, &buf[1], sizeof(sc->mac_address));
} else if ((sc->quirks & SIXAXIS_CONTROLLER_USB) ||
(sc->quirks & NAVIGATION_CONTROLLER_USB)) {
buf = kmalloc(SIXAXIS_REPORT_0xF2_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(sc->hdev, 0xf2, buf,
SIXAXIS_REPORT_0xF2_SIZE, HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret != SIXAXIS_REPORT_0xF2_SIZE) {
hid_err(sc->hdev, "failed to retrieve feature report 0xf2 with the Sixaxis MAC address\n");
ret = ret < 0 ? ret : -EINVAL;
goto out_free;
}
for (n = 0; n < 6; n++)
sc->mac_address[5-n] = buf[4+n];
} else {
return 0;
}
ret = sony_check_add_dev_list(sc);
out_free:
kfree(buf);
return ret;
}
static int sony_set_device_id(struct sony_sc *sc)
{
int ret;
if ((sc->quirks & SIXAXIS_CONTROLLER) ||
(sc->quirks & DUALSHOCK4_CONTROLLER)) {
ret = ida_simple_get(&sony_device_id_allocator, 0, 0,
GFP_KERNEL);
if (ret < 0) {
sc->device_id = -1;
return ret;
}
sc->device_id = ret;
} else {
sc->device_id = -1;
}
return 0;
}
static void sony_release_device_id(struct sony_sc *sc)
{
if (sc->device_id >= 0) {
ida_simple_remove(&sony_device_id_allocator, sc->device_id);
sc->device_id = -1;
}
}
static inline void sony_init_output_report(struct sony_sc *sc,
void (*send_output_report)(struct sony_sc *))
{
sc->send_output_report = send_output_report;
if (!sc->worker_initialized)
INIT_WORK(&sc->state_worker, sony_state_worker);
sc->worker_initialized = 1;
}
static inline void sony_cancel_work_sync(struct sony_sc *sc)
{
if (sc->worker_initialized)
cancel_work_sync(&sc->state_worker);
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
spin_lock_init(&sc->lock);
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
else if (sc->quirks & SIXAXIS_CONTROLLER)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
ret = sony_set_device_id(sc);
if (ret < 0) {
hid_err(hdev, "failed to allocate the device id\n");
goto err_stop;
}
ret = sony_allocate_output_report(sc);
if (ret < 0) {
hid_err(hdev, "failed to allocate the output report buffer\n");
goto err_stop;
}
if ((sc->quirks & SIXAXIS_CONTROLLER_USB) ||
(sc->quirks & NAVIGATION_CONTROLLER_USB)) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
hdev->quirks |= HID_QUIRK_SKIP_OUTPUT_REPORT_ID;
ret = sixaxis_set_operational_usb(hdev);
sony_init_output_report(sc, sixaxis_send_output_report);
} else if ((sc->quirks & SIXAXIS_CONTROLLER_BT) ||
(sc->quirks & NAVIGATION_CONTROLLER_BT)) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = sixaxis_set_operational_bt(hdev);
sony_init_output_report(sc, sixaxis_send_output_report);
} else if (sc->quirks & DUALSHOCK4_CONTROLLER) {
if (sc->quirks & DUALSHOCK4_CONTROLLER_BT) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = dualshock4_set_operational_bt(hdev);
if (ret < 0) {
hid_err(hdev, "failed to set the Dualshock 4 operational mode\n");
goto err_stop;
}
}
sony_init_output_report(sc, dualshock4_send_output_report);
} else if (sc->quirks & MOTION_CONTROLLER) {
sony_init_output_report(sc, motion_send_output_report);
} else {
ret = 0;
}
if (ret < 0)
goto err_stop;
ret = sony_check_add(sc);
if (ret < 0)
goto err_stop;
if (sc->quirks & SONY_LED_SUPPORT) {
ret = sony_leds_init(sc);
if (ret < 0)
goto err_stop;
}
if (sc->quirks & SONY_BATTERY_SUPPORT) {
ret = sony_battery_probe(sc);
if (ret < 0)
goto err_stop;
ret = hid_hw_open(hdev);
if (ret < 0) {
hid_err(hdev, "hw open failed\n");
goto err_stop;
}
}
if (sc->quirks & SONY_FF_SUPPORT) {
ret = sony_init_ff(sc);
if (ret < 0)
goto err_close;
}
return 0;
err_close:
hid_hw_close(hdev);
err_stop:
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(sc);
if (sc->quirks & SONY_BATTERY_SUPPORT)
sony_battery_remove(sc);
sony_cancel_work_sync(sc);
kfree(sc->output_report_dmabuf);
sony_remove_dev_list(sc);
sony_release_device_id(sc);
hid_hw_stop(hdev);
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(sc);
if (sc->quirks & SONY_BATTERY_SUPPORT) {
hid_hw_close(hdev);
sony_battery_remove(sc);
}
sony_cancel_work_sync(sc);
kfree(sc->output_report_dmabuf);
sony_remove_dev_list(sc);
sony_release_device_id(sc);
hid_hw_stop(hdev);
}
static int sony_suspend(struct hid_device *hdev, pm_message_t message)
{
if (SONY_LED_SUPPORT || SONY_FF_SUPPORT) {
struct sony_sc *sc = hid_get_drvdata(hdev);
#ifdef CONFIG_SONY_FF
sc->left = sc->right = 0;
#endif
memcpy(sc->resume_led_state, sc->led_state,
sizeof(sc->resume_led_state));
memset(sc->led_state, 0, sizeof(sc->led_state));
sony_send_output_report(sc);
}
return 0;
}
static int sony_resume(struct hid_device *hdev)
{
if (SONY_LED_SUPPORT) {
struct sony_sc *sc = hid_get_drvdata(hdev);
memcpy(sc->led_state, sc->resume_led_state,
sizeof(sc->led_state));
if ((sc->quirks & SIXAXIS_CONTROLLER_USB) ||
(sc->quirks & NAVIGATION_CONTROLLER_USB))
sixaxis_set_operational_usb(sc->hdev);
sony_set_leds(sc);
}
return 0;
}
static int __init sony_init(void)
{
dbg_hid("Sony:%s\n", __func__);
return hid_register_driver(&sony_driver);
}
static void __exit sony_exit(void)
{
dbg_hid("Sony:%s\n", __func__);
hid_unregister_driver(&sony_driver);
ida_destroy(&sony_device_id_allocator);
}
