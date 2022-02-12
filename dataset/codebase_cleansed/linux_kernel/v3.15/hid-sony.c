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
} else if ((sc->quirks & DUALSHOCK4_CONTROLLER_BT) && *rsize == 357) {
hid_info(hdev, "Using modified Dualshock 4 Bluetooth report descriptor\n");
rdesc = dualshock4_bt_rdesc;
*rsize = sizeof(dualshock4_bt_rdesc);
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
static void sixaxis_parse_report(struct sony_sc *sc, __u8 *rd, int size)
{
static const __u8 sixaxis_battery_capacity[] = { 0, 1, 25, 50, 75, 100 };
unsigned long flags;
__u8 cable_state, battery_capacity, battery_charging;
if (rd[30] >= 0xee) {
battery_capacity = 100;
battery_charging = !(rd[30] & 0x01);
} else {
__u8 index = rd[30] <= 5 ? rd[30] : 5;
battery_capacity = sixaxis_battery_capacity[index];
battery_charging = 0;
}
cable_state = !(rd[31] & 0x04);
spin_lock_irqsave(&sc->lock, flags);
sc->cable_state = cable_state;
sc->battery_capacity = battery_capacity;
sc->battery_charging = battery_charging;
spin_unlock_irqrestore(&sc->lock, flags);
}
static void dualshock4_parse_report(struct sony_sc *sc, __u8 *rd, int size)
{
struct hid_input *hidinput = list_entry(sc->hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
unsigned long flags;
int n, offset;
__u8 cable_state, battery_capacity, battery_charging;
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
__u16 x, y;
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
__u8 *rd, int size)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & SIXAXIS_CONTROLLER) && rd[0] == 0x01 && size == 49) {
swap(rd[41], rd[42]);
swap(rd[43], rd[44]);
swap(rd[45], rd[46]);
swap(rd[47], rd[48]);
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
static int sixaxis_set_operational_usb(struct hid_device *hdev)
{
int ret;
char *buf = kmalloc(18, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, 0xf2, buf, 17, HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret < 0)
hid_err(hdev, "can't set operational mode\n");
kfree(buf);
return ret;
}
static int sixaxis_set_operational_bt(struct hid_device *hdev)
{
unsigned char buf[] = { 0xf4, 0x42, 0x03, 0x00, 0x00 };
return hid_hw_raw_request(hdev, buf[0], buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
}
static int dualshock4_set_operational_bt(struct hid_device *hdev)
{
__u8 buf[37] = { 0 };
return hid_hw_raw_request(hdev, 0x02, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
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
} else {
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
} else if (drv_data->quirks & DUALSHOCK4_CONTROLLER) {
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
hid_hw_raw_request(sc->hdev, 0x01, buf, sizeof(buf), HID_OUTPUT_REPORT,
HID_REQ_SET_REPORT);
}
static void dualshock4_state_worker(struct work_struct *work)
{
struct sony_sc *sc = container_of(work, struct sony_sc, state_worker);
struct hid_device *hdev = sc->hdev;
int offset;
__u8 buf[78] = { 0 };
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
buf[0] = 0x05;
buf[1] = 0x03;
offset = 4;
} else {
buf[0] = 0x11;
buf[1] = 0xB0;
buf[3] = 0x0F;
offset = 6;
}
#ifdef CONFIG_SONY_FF
buf[offset++] = sc->right;
buf[offset++] = sc->left;
#else
offset += 2;
#endif
buf[offset++] = sc->led_state[0];
buf[offset++] = sc->led_state[1];
buf[offset++] = sc->led_state[2];
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB)
hid_hw_output_report(hdev, buf, 32);
else
hid_hw_raw_request(hdev, 0x11, buf, 78,
HID_OUTPUT_REPORT, HID_REQ_SET_REPORT);
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
static int sony_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct sony_sc *sc = container_of(psy, struct sony_sc, battery);
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
static atomic_t power_id_seq = ATOMIC_INIT(0);
unsigned long power_id;
struct hid_device *hdev = sc->hdev;
int ret;
sc->battery_capacity = 100;
power_id = (unsigned long)atomic_inc_return(&power_id_seq);
sc->battery.properties = sony_battery_props;
sc->battery.num_properties = ARRAY_SIZE(sony_battery_props);
sc->battery.get_property = sony_battery_get_property;
sc->battery.type = POWER_SUPPLY_TYPE_BATTERY;
sc->battery.use_for_apm = 0;
sc->battery.name = kasprintf(GFP_KERNEL, "sony_controller_battery_%lu",
power_id);
if (!sc->battery.name)
return -ENOMEM;
ret = power_supply_register(&hdev->dev, &sc->battery);
if (ret) {
hid_err(hdev, "Unable to register battery device\n");
goto err_free;
}
power_supply_powers(&sc->battery, &hdev->dev);
return 0;
err_free:
kfree(sc->battery.name);
sc->battery.name = NULL;
return ret;
}
static void sony_battery_remove(struct sony_sc *sc)
{
if (!sc->battery.name)
return;
power_supply_unregister(&sc->battery);
kfree(sc->battery.name);
sc->battery.name = NULL;
}
static int sony_register_touchpad(struct sony_sc *sc, int touch_count,
int w, int h)
{
struct hid_input *hidinput = list_entry(sc->hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
int ret;
ret = input_mt_init_slots(input_dev, touch_count, 0);
if (ret < 0) {
hid_err(sc->hdev, "Unable to initialize multi-touch slots\n");
return ret;
}
input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0, w, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0, h, 0, 0);
return 0;
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
int n, ret;
if ((sc->quirks & DUALSHOCK4_CONTROLLER_BT) ||
(sc->quirks & SIXAXIS_CONTROLLER_BT)) {
if (sony_get_bt_devaddr(sc) < 0) {
hid_warn(sc->hdev, "UNIQ does not contain a MAC address; duplicate check skipped\n");
return 0;
}
} else if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
__u8 buf[7];
ret = hid_hw_raw_request(sc->hdev, 0x81, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret != 7) {
hid_err(sc->hdev, "failed to retrieve feature report 0x81 with the DualShock 4 MAC address\n");
return ret < 0 ? ret : -EINVAL;
}
memcpy(sc->mac_address, &buf[1], sizeof(sc->mac_address));
} else if (sc->quirks & SIXAXIS_CONTROLLER_USB) {
__u8 buf[18];
ret = hid_hw_raw_request(sc->hdev, 0xf2, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret != 18) {
hid_err(sc->hdev, "failed to retrieve feature report 0xf2 with the Sixaxis MAC address\n");
return ret < 0 ? ret : -EINVAL;
}
for (n = 0; n < 6; n++)
sc->mac_address[5-n] = buf[4+n];
} else {
return 0;
}
return sony_check_add_dev_list(sc);
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
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
hdev->quirks |= HID_QUIRK_SKIP_OUTPUT_REPORT_ID;
ret = sixaxis_set_operational_usb(hdev);
sc->worker_initialized = 1;
INIT_WORK(&sc->state_worker, sixaxis_state_worker);
} else if (sc->quirks & SIXAXIS_CONTROLLER_BT) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = sixaxis_set_operational_bt(hdev);
sc->worker_initialized = 1;
INIT_WORK(&sc->state_worker, sixaxis_state_worker);
} else if (sc->quirks & DUALSHOCK4_CONTROLLER) {
if (sc->quirks & DUALSHOCK4_CONTROLLER_BT) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = dualshock4_set_operational_bt(hdev);
if (ret < 0) {
hid_err(hdev, "failed to set the Dualshock 4 operational mode\n");
goto err_stop;
}
}
ret = sony_register_touchpad(sc, 2, 1920, 940);
if (ret < 0)
goto err_stop;
sc->worker_initialized = 1;
INIT_WORK(&sc->state_worker, dualshock4_state_worker);
} else {
ret = 0;
}
if (ret < 0)
goto err_stop;
ret = sony_check_add(sc);
if (ret < 0)
goto err_stop;
if (sc->quirks & SONY_LED_SUPPORT) {
ret = sony_leds_init(hdev);
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
ret = sony_init_ff(hdev);
if (ret < 0)
goto err_close;
}
return 0;
err_close:
hid_hw_close(hdev);
err_stop:
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(hdev);
if (sc->quirks & SONY_BATTERY_SUPPORT)
sony_battery_remove(sc);
if (sc->worker_initialized)
cancel_work_sync(&sc->state_worker);
sony_remove_dev_list(sc);
hid_hw_stop(hdev);
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(hdev);
if (sc->quirks & SONY_BATTERY_SUPPORT) {
hid_hw_close(hdev);
sony_battery_remove(sc);
}
if (sc->worker_initialized)
cancel_work_sync(&sc->state_worker);
sony_remove_dev_list(sc);
hid_hw_stop(hdev);
}
