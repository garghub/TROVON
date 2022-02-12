static inline void sony_schedule_work(struct sony_sc *sc,
enum sony_worker which)
{
switch (which) {
case SONY_WORKER_STATE:
if (!sc->defer_initialization)
schedule_work(&sc->state_worker);
break;
case SONY_WORKER_HOTPLUG:
if (sc->hotplug_worker_initialized)
schedule_work(&sc->hotplug_worker);
break;
}
}
static ssize_t ds4_show_poll_interval(struct device *dev,
struct device_attribute
*attr, char *buf)
{
struct hid_device *hdev = to_hid_device(dev);
struct sony_sc *sc = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%i\n", sc->ds4_bt_poll_interval);
}
static ssize_t ds4_store_poll_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = to_hid_device(dev);
struct sony_sc *sc = hid_get_drvdata(hdev);
unsigned long flags;
u8 interval;
if (kstrtou8(buf, 0, &interval))
return -EINVAL;
if (interval > DS4_BT_MAX_POLL_INTERVAL_MS)
return -EINVAL;
spin_lock_irqsave(&sc->lock, flags);
sc->ds4_bt_poll_interval = interval;
spin_unlock_irqrestore(&sc->lock, flags);
sony_schedule_work(sc, SONY_WORKER_STATE);
return count;
}
static u8 *motion_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(motion_rdesc);
return motion_rdesc;
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
static int navigation_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
unsigned int key = usage->hid & HID_USAGE;
if (key >= ARRAY_SIZE(sixaxis_keymap))
return -1;
key = navigation_keymap[key];
if (!key)
return -1;
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
} else if (usage->hid == HID_GD_POINTER) {
switch (usage->usage_index) {
case 8:
usage->hid = HID_GD_Z;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_ABS, usage->hid & 0xf);
return 1;
} else if ((usage->hid & HID_USAGE_PAGE) == HID_UP_GENDESK) {
unsigned int abs = usage->hid & HID_USAGE;
if (abs >= ARRAY_SIZE(navigation_absmap))
return -1;
abs = navigation_absmap[abs];
hid_map_usage_clear(hi, usage, bit, max, EV_ABS, abs);
return 1;
}
return -1;
}
static int sixaxis_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
unsigned int key = usage->hid & HID_USAGE;
if (key >= ARRAY_SIZE(sixaxis_keymap))
return -1;
key = sixaxis_keymap[key];
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
} else if (usage->hid == HID_GD_POINTER) {
switch (usage->usage_index) {
case 8:
usage->hid = HID_GD_Z;
break;
case 9:
usage->hid = HID_GD_RZ;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_ABS, usage->hid & 0xf);
return 1;
} else if ((usage->hid & HID_USAGE_PAGE) == HID_UP_GENDESK) {
unsigned int abs = usage->hid & HID_USAGE;
if (abs >= ARRAY_SIZE(sixaxis_absmap))
return -1;
abs = sixaxis_absmap[abs];
hid_map_usage_clear(hi, usage, bit, max, EV_ABS, abs);
return 1;
}
return -1;
}
static int ds4_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
unsigned int key = usage->hid & HID_USAGE;
if (key >= ARRAY_SIZE(ds4_keymap))
return -1;
key = ds4_keymap[key];
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
} else if ((usage->hid & HID_USAGE_PAGE) == HID_UP_GENDESK) {
unsigned int abs = usage->hid & HID_USAGE;
if (usage->hid == HID_GD_HATSWITCH)
return 0;
if (abs >= ARRAY_SIZE(ds4_absmap))
return -1;
abs = ds4_absmap[abs];
hid_map_usage_clear(hi, usage, bit, max, EV_ABS, abs);
return 1;
}
return 0;
}
static u8 *sony_report_fixup(struct hid_device *hdev, u8 *rdesc,
unsigned int *rsize)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & (SINO_LITE_CONTROLLER | FUTUREMAX_DANCE_MAT))
return rdesc;
if ((sc->quirks & VAIO_RDESC_CONSTANT) && *rsize >= 56 &&
rdesc[2] == 0x09 && rdesc[3] == 0x02 &&
rdesc[54] == 0x81 && rdesc[55] == 0x07) {
hid_info(hdev, "Fixing up Sony RF Receiver report descriptor\n");
rdesc[55] = 0x06;
}
if (sc->quirks & MOTION_CONTROLLER)
return motion_fixup(hdev, rdesc, rsize);
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
if (sc->quirks & SIXAXIS_CONTROLLER) {
int val;
offset = SIXAXIS_INPUT_REPORT_ACC_X_OFFSET;
val = ((rd[offset+1] << 8) | rd[offset]) - 511;
input_report_abs(sc->sensor_dev, ABS_X, val);
val = 511 - ((rd[offset+5] << 8) | rd[offset+4]);
input_report_abs(sc->sensor_dev, ABS_Y, val);
val = 511 - ((rd[offset+3] << 8) | rd[offset+2]);
input_report_abs(sc->sensor_dev, ABS_Z, val);
input_sync(sc->sensor_dev);
}
}
static void dualshock4_parse_report(struct sony_sc *sc, u8 *rd, int size)
{
struct hid_input *hidinput = list_entry(sc->hdev->inputs.next,
struct hid_input, list);
struct input_dev *input_dev = hidinput->input;
unsigned long flags;
int n, m, offset, num_touch_data, max_touch_data;
u8 cable_state, battery_capacity, battery_charging;
u16 timestamp;
int data_offset = (sc->quirks & DUALSHOCK4_CONTROLLER_BT) ? 2 : 0;
offset = data_offset + DS4_INPUT_REPORT_BUTTON_OFFSET;
input_report_key(sc->touchpad, BTN_LEFT, rd[offset+2] & 0x2);
if (rd[0] == 17) {
int value;
offset = data_offset + DS4_INPUT_REPORT_AXIS_OFFSET;
input_report_abs(input_dev, ABS_X, rd[offset]);
input_report_abs(input_dev, ABS_Y, rd[offset+1]);
input_report_abs(input_dev, ABS_RX, rd[offset+2]);
input_report_abs(input_dev, ABS_RY, rd[offset+3]);
value = rd[offset+4] & 0xf;
if (value > 7)
value = 8;
input_report_abs(input_dev, ABS_HAT0X, ds4_hat_mapping[value].x);
input_report_abs(input_dev, ABS_HAT0Y, ds4_hat_mapping[value].y);
input_report_key(input_dev, BTN_WEST, rd[offset+4] & 0x10);
input_report_key(input_dev, BTN_SOUTH, rd[offset+4] & 0x20);
input_report_key(input_dev, BTN_EAST, rd[offset+4] & 0x40);
input_report_key(input_dev, BTN_NORTH, rd[offset+4] & 0x80);
input_report_key(input_dev, BTN_TL, rd[offset+5] & 0x1);
input_report_key(input_dev, BTN_TR, rd[offset+5] & 0x2);
input_report_key(input_dev, BTN_TL2, rd[offset+5] & 0x4);
input_report_key(input_dev, BTN_TR2, rd[offset+5] & 0x8);
input_report_key(input_dev, BTN_SELECT, rd[offset+5] & 0x10);
input_report_key(input_dev, BTN_START, rd[offset+5] & 0x20);
input_report_key(input_dev, BTN_THUMBL, rd[offset+5] & 0x40);
input_report_key(input_dev, BTN_THUMBR, rd[offset+5] & 0x80);
input_report_key(input_dev, BTN_MODE, rd[offset+6] & 0x1);
input_report_abs(input_dev, ABS_Z, rd[offset+7]);
input_report_abs(input_dev, ABS_RZ, rd[offset+8]);
input_sync(input_dev);
}
offset = data_offset + DS4_INPUT_REPORT_TIMESTAMP_OFFSET;
timestamp = get_unaligned_le16(&rd[offset]);
if (!sc->timestamp_initialized) {
sc->timestamp_us = ((unsigned int)timestamp * 16) / 3;
sc->timestamp_initialized = true;
} else {
u16 delta;
if (sc->prev_timestamp > timestamp)
delta = (U16_MAX - sc->prev_timestamp + timestamp + 1);
else
delta = timestamp - sc->prev_timestamp;
sc->timestamp_us += (delta * 16) / 3;
}
sc->prev_timestamp = timestamp;
input_event(sc->sensor_dev, EV_MSC, MSC_TIMESTAMP, sc->timestamp_us);
offset = data_offset + DS4_INPUT_REPORT_GYRO_X_OFFSET;
for (n = 0; n < 6; n++) {
int raw_data = (short)((rd[offset+1] << 8) | rd[offset]);
struct ds4_calibration_data *calib = &sc->ds4_calib_data[n];
int calib_data = mult_frac(calib->sens_numer,
raw_data - calib->bias,
calib->sens_denom);
input_report_abs(sc->sensor_dev, calib->abs_code, calib_data);
offset += 2;
}
input_sync(sc->sensor_dev);
offset = data_offset + DS4_INPUT_REPORT_BATTERY_OFFSET;
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
offset = data_offset + DS4_INPUT_REPORT_TOUCHPAD_OFFSET;
max_touch_data = (sc->quirks & DUALSHOCK4_CONTROLLER_BT) ? 4 : 3;
if (rd[offset] > 0 && rd[offset] <= max_touch_data)
num_touch_data = rd[offset];
else
num_touch_data = 1;
offset += 1;
for (m = 0; m < num_touch_data; m++) {
offset += 1;
for (n = 0; n < 2; n++) {
u16 x, y;
bool active;
x = rd[offset+1] | ((rd[offset+2] & 0xF) << 8);
y = ((rd[offset+2] & 0xF0) >> 4) | (rd[offset+3] << 4);
active = !(rd[offset] >> 7);
input_mt_slot(sc->touchpad, n);
input_mt_report_slot_state(sc->touchpad, MT_TOOL_FINGER, active);
if (active) {
input_report_abs(sc->touchpad, ABS_MT_POSITION_X, x);
input_report_abs(sc->touchpad, ABS_MT_POSITION_Y, y);
}
offset += 4;
}
input_mt_sync_frame(sc->touchpad);
input_sync(sc->touchpad);
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
} else if ((sc->quirks & DUALSHOCK4_CONTROLLER_USB) && rd[0] == 0x01 &&
size == 64) {
dualshock4_parse_report(sc, rd, size);
} else if (((sc->quirks & DUALSHOCK4_CONTROLLER_BT) && rd[0] == 0x11 &&
size == 78)) {
u8 bthdr = 0xA1;
u32 crc;
u32 report_crc;
crc = crc32_le(0xFFFFFFFF, &bthdr, 1);
crc = ~crc32_le(crc, rd, DS4_INPUT_REPORT_0x11_SIZE-4);
report_crc = get_unaligned_le32(&rd[DS4_INPUT_REPORT_0x11_SIZE-4]);
if (crc != report_crc) {
hid_dbg(sc->hdev, "DualShock 4 input report's CRC check failed, received crc 0x%0x != 0x%0x\n",
report_crc, crc);
return -EILSEQ;
}
dualshock4_parse_report(sc, rd, size);
} else if ((sc->quirks & DUALSHOCK4_DONGLE) && rd[0] == 0x01 &&
size == 64) {
unsigned long flags;
enum ds4_dongle_state dongle_state;
bool connected = (rd[31] & 0x04) ? false : true;
spin_lock_irqsave(&sc->lock, flags);
dongle_state = sc->ds4_dongle_state;
spin_unlock_irqrestore(&sc->lock, flags);
if (dongle_state == DONGLE_DISCONNECTED && connected) {
hid_info(sc->hdev, "DualShock 4 USB dongle: controller connected\n");
sony_set_leds(sc);
spin_lock_irqsave(&sc->lock, flags);
sc->ds4_dongle_state = DONGLE_CALIBRATING;
spin_unlock_irqrestore(&sc->lock, flags);
sony_schedule_work(sc, SONY_WORKER_HOTPLUG);
return 0;
} else if ((dongle_state == DONGLE_CONNECTED ||
dongle_state == DONGLE_DISABLED) && !connected) {
hid_info(sc->hdev, "DualShock 4 USB dongle: controller disconnected\n");
spin_lock_irqsave(&sc->lock, flags);
sc->ds4_dongle_state = DONGLE_DISCONNECTED;
spin_unlock_irqrestore(&sc->lock, flags);
return 0;
} else if (dongle_state == DONGLE_CALIBRATING ||
dongle_state == DONGLE_DISABLED ||
dongle_state == DONGLE_DISCONNECTED) {
return 0;
}
dualshock4_parse_report(sc, rd, size);
}
if (sc->defer_initialization) {
sc->defer_initialization = 0;
sony_schedule_work(sc, SONY_WORKER_STATE);
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
if (sc->quirks & NAVIGATION_CONTROLLER)
return navigation_mapping(hdev, hi, field, usage, bit, max);
if (sc->quirks & SIXAXIS_CONTROLLER)
return sixaxis_mapping(hdev, hi, field, usage, bit, max);
if (sc->quirks & DUALSHOCK4_CONTROLLER)
return ds4_mapping(hdev, hi, field, usage, bit, max);
return 0;
}
static int sony_register_touchpad(struct sony_sc *sc, int touch_count,
int w, int h)
{
size_t name_sz;
char *name;
int ret;
sc->touchpad = input_allocate_device();
if (!sc->touchpad)
return -ENOMEM;
input_set_drvdata(sc->touchpad, sc);
sc->touchpad->dev.parent = &sc->hdev->dev;
sc->touchpad->phys = sc->hdev->phys;
sc->touchpad->uniq = sc->hdev->uniq;
sc->touchpad->id.bustype = sc->hdev->bus;
sc->touchpad->id.vendor = sc->hdev->vendor;
sc->touchpad->id.product = sc->hdev->product;
sc->touchpad->id.version = sc->hdev->version;
name_sz = strlen(sc->hdev->name) + sizeof(DS4_TOUCHPAD_SUFFIX);
name = kzalloc(name_sz, GFP_KERNEL);
if (!name) {
ret = -ENOMEM;
goto err;
}
snprintf(name, name_sz, "%s" DS4_TOUCHPAD_SUFFIX, sc->hdev->name);
sc->touchpad->name = name;
ret = input_mt_init_slots(sc->touchpad, touch_count, INPUT_MT_POINTER);
if (ret < 0)
goto err;
__set_bit(EV_KEY, sc->touchpad->evbit);
__set_bit(BTN_LEFT, sc->touchpad->keybit);
__set_bit(INPUT_PROP_BUTTONPAD, sc->touchpad->propbit);
input_set_abs_params(sc->touchpad, ABS_MT_POSITION_X, 0, w, 0, 0);
input_set_abs_params(sc->touchpad, ABS_MT_POSITION_Y, 0, h, 0, 0);
ret = input_register_device(sc->touchpad);
if (ret < 0)
goto err;
return 0;
err:
kfree(sc->touchpad->name);
sc->touchpad->name = NULL;
input_free_device(sc->touchpad);
sc->touchpad = NULL;
return ret;
}
static void sony_unregister_touchpad(struct sony_sc *sc)
{
if (!sc->touchpad)
return;
kfree(sc->touchpad->name);
sc->touchpad->name = NULL;
input_unregister_device(sc->touchpad);
sc->touchpad = NULL;
}
static int sony_register_sensors(struct sony_sc *sc)
{
size_t name_sz;
char *name;
int ret;
int range;
sc->sensor_dev = input_allocate_device();
if (!sc->sensor_dev)
return -ENOMEM;
input_set_drvdata(sc->sensor_dev, sc);
sc->sensor_dev->dev.parent = &sc->hdev->dev;
sc->sensor_dev->phys = sc->hdev->phys;
sc->sensor_dev->uniq = sc->hdev->uniq;
sc->sensor_dev->id.bustype = sc->hdev->bus;
sc->sensor_dev->id.vendor = sc->hdev->vendor;
sc->sensor_dev->id.product = sc->hdev->product;
sc->sensor_dev->id.version = sc->hdev->version;
name_sz = strlen(sc->hdev->name) + sizeof(SENSOR_SUFFIX);
name = kzalloc(name_sz, GFP_KERNEL);
if (!name) {
ret = -ENOMEM;
goto err;
}
snprintf(name, name_sz, "%s" SENSOR_SUFFIX, sc->hdev->name);
sc->sensor_dev->name = name;
if (sc->quirks & SIXAXIS_CONTROLLER) {
input_set_abs_params(sc->sensor_dev, ABS_X, -512, 511, 4, 0);
input_set_abs_params(sc->sensor_dev, ABS_Y, -512, 511, 4, 0);
input_set_abs_params(sc->sensor_dev, ABS_Z, -512, 511, 4, 0);
input_abs_set_res(sc->sensor_dev, ABS_X, SIXAXIS_ACC_RES_PER_G);
input_abs_set_res(sc->sensor_dev, ABS_Y, SIXAXIS_ACC_RES_PER_G);
input_abs_set_res(sc->sensor_dev, ABS_Z, SIXAXIS_ACC_RES_PER_G);
} else if (sc->quirks & DUALSHOCK4_CONTROLLER) {
range = DS4_ACC_RES_PER_G*4;
input_set_abs_params(sc->sensor_dev, ABS_X, -range, range, 16, 0);
input_set_abs_params(sc->sensor_dev, ABS_Y, -range, range, 16, 0);
input_set_abs_params(sc->sensor_dev, ABS_Z, -range, range, 16, 0);
input_abs_set_res(sc->sensor_dev, ABS_X, DS4_ACC_RES_PER_G);
input_abs_set_res(sc->sensor_dev, ABS_Y, DS4_ACC_RES_PER_G);
input_abs_set_res(sc->sensor_dev, ABS_Z, DS4_ACC_RES_PER_G);
range = DS4_GYRO_RES_PER_DEG_S*2048;
input_set_abs_params(sc->sensor_dev, ABS_RX, -range, range, 16, 0);
input_set_abs_params(sc->sensor_dev, ABS_RY, -range, range, 16, 0);
input_set_abs_params(sc->sensor_dev, ABS_RZ, -range, range, 16, 0);
input_abs_set_res(sc->sensor_dev, ABS_RX, DS4_GYRO_RES_PER_DEG_S);
input_abs_set_res(sc->sensor_dev, ABS_RY, DS4_GYRO_RES_PER_DEG_S);
input_abs_set_res(sc->sensor_dev, ABS_RZ, DS4_GYRO_RES_PER_DEG_S);
__set_bit(EV_MSC, sc->sensor_dev->evbit);
__set_bit(MSC_TIMESTAMP, sc->sensor_dev->mscbit);
}
__set_bit(INPUT_PROP_ACCELEROMETER, sc->sensor_dev->propbit);
ret = input_register_device(sc->sensor_dev);
if (ret < 0)
goto err;
return 0;
err:
kfree(sc->sensor_dev->name);
sc->sensor_dev->name = NULL;
input_free_device(sc->sensor_dev);
sc->sensor_dev = NULL;
return ret;
}
static void sony_unregister_sensors(struct sony_sc *sc)
{
if (!sc->sensor_dev)
return;
kfree(sc->sensor_dev->name);
sc->sensor_dev->name = NULL;
input_unregister_device(sc->sensor_dev);
sc->sensor_dev = NULL;
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
static int dualshock4_get_calibration_data(struct sony_sc *sc)
{
u8 *buf;
int ret;
short gyro_pitch_bias, gyro_pitch_plus, gyro_pitch_minus;
short gyro_yaw_bias, gyro_yaw_plus, gyro_yaw_minus;
short gyro_roll_bias, gyro_roll_plus, gyro_roll_minus;
short gyro_speed_plus, gyro_speed_minus;
short acc_x_plus, acc_x_minus;
short acc_y_plus, acc_y_minus;
short acc_z_plus, acc_z_minus;
int speed_2x;
int range_2g;
if (sc->quirks & (DUALSHOCK4_CONTROLLER_USB | DUALSHOCK4_DONGLE)) {
buf = kmalloc(DS4_FEATURE_REPORT_0x02_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(sc->hdev, 0x02, buf,
DS4_FEATURE_REPORT_0x02_SIZE,
HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret < 0)
goto err_stop;
} else {
u8 bthdr = 0xA3;
u32 crc;
u32 report_crc;
int retries;
buf = kmalloc(DS4_FEATURE_REPORT_0x05_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
for (retries = 0; retries < 3; retries++) {
ret = hid_hw_raw_request(sc->hdev, 0x05, buf,
DS4_FEATURE_REPORT_0x05_SIZE,
HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret < 0)
goto err_stop;
crc = crc32_le(0xFFFFFFFF, &bthdr, 1);
crc = ~crc32_le(crc, buf, DS4_FEATURE_REPORT_0x05_SIZE-4);
report_crc = get_unaligned_le32(&buf[DS4_FEATURE_REPORT_0x05_SIZE-4]);
if (crc != report_crc) {
hid_warn(sc->hdev, "DualShock 4 calibration report's CRC check failed, received crc 0x%0x != 0x%0x\n",
report_crc, crc);
if (retries < 2) {
hid_warn(sc->hdev, "Retrying DualShock 4 get calibration report request\n");
continue;
} else {
ret = -EILSEQ;
goto err_stop;
}
} else {
break;
}
}
}
gyro_pitch_bias = get_unaligned_le16(&buf[1]);
gyro_yaw_bias = get_unaligned_le16(&buf[3]);
gyro_roll_bias = get_unaligned_le16(&buf[5]);
if (sc->quirks & DUALSHOCK4_CONTROLLER_USB) {
gyro_pitch_plus = get_unaligned_le16(&buf[7]);
gyro_pitch_minus = get_unaligned_le16(&buf[9]);
gyro_yaw_plus = get_unaligned_le16(&buf[11]);
gyro_yaw_minus = get_unaligned_le16(&buf[13]);
gyro_roll_plus = get_unaligned_le16(&buf[15]);
gyro_roll_minus = get_unaligned_le16(&buf[17]);
} else {
gyro_pitch_plus = get_unaligned_le16(&buf[7]);
gyro_yaw_plus = get_unaligned_le16(&buf[9]);
gyro_roll_plus = get_unaligned_le16(&buf[11]);
gyro_pitch_minus = get_unaligned_le16(&buf[13]);
gyro_yaw_minus = get_unaligned_le16(&buf[15]);
gyro_roll_minus = get_unaligned_le16(&buf[17]);
}
gyro_speed_plus = get_unaligned_le16(&buf[19]);
gyro_speed_minus = get_unaligned_le16(&buf[21]);
acc_x_plus = get_unaligned_le16(&buf[23]);
acc_x_minus = get_unaligned_le16(&buf[25]);
acc_y_plus = get_unaligned_le16(&buf[27]);
acc_y_minus = get_unaligned_le16(&buf[29]);
acc_z_plus = get_unaligned_le16(&buf[31]);
acc_z_minus = get_unaligned_le16(&buf[33]);
speed_2x = (gyro_speed_plus + gyro_speed_minus);
sc->ds4_calib_data[0].abs_code = ABS_RX;
sc->ds4_calib_data[0].bias = gyro_pitch_bias;
sc->ds4_calib_data[0].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
sc->ds4_calib_data[0].sens_denom = gyro_pitch_plus - gyro_pitch_minus;
sc->ds4_calib_data[1].abs_code = ABS_RY;
sc->ds4_calib_data[1].bias = gyro_yaw_bias;
sc->ds4_calib_data[1].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
sc->ds4_calib_data[1].sens_denom = gyro_yaw_plus - gyro_yaw_minus;
sc->ds4_calib_data[2].abs_code = ABS_RZ;
sc->ds4_calib_data[2].bias = gyro_roll_bias;
sc->ds4_calib_data[2].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
sc->ds4_calib_data[2].sens_denom = gyro_roll_plus - gyro_roll_minus;
range_2g = acc_x_plus - acc_x_minus;
sc->ds4_calib_data[3].abs_code = ABS_X;
sc->ds4_calib_data[3].bias = acc_x_plus - range_2g / 2;
sc->ds4_calib_data[3].sens_numer = 2*DS4_ACC_RES_PER_G;
sc->ds4_calib_data[3].sens_denom = range_2g;
range_2g = acc_y_plus - acc_y_minus;
sc->ds4_calib_data[4].abs_code = ABS_Y;
sc->ds4_calib_data[4].bias = acc_y_plus - range_2g / 2;
sc->ds4_calib_data[4].sens_numer = 2*DS4_ACC_RES_PER_G;
sc->ds4_calib_data[4].sens_denom = range_2g;
range_2g = acc_z_plus - acc_z_minus;
sc->ds4_calib_data[5].abs_code = ABS_Z;
sc->ds4_calib_data[5].bias = acc_z_plus - range_2g / 2;
sc->ds4_calib_data[5].sens_numer = 2*DS4_ACC_RES_PER_G;
sc->ds4_calib_data[5].sens_denom = range_2g;
err_stop:
kfree(buf);
return ret;
}
static void dualshock4_calibration_work(struct work_struct *work)
{
struct sony_sc *sc = container_of(work, struct sony_sc, hotplug_worker);
unsigned long flags;
enum ds4_dongle_state dongle_state;
int ret;
ret = dualshock4_get_calibration_data(sc);
if (ret < 0) {
hid_err(sc->hdev, "DualShock 4 USB dongle: calibration failed, disabling device\n");
dongle_state = DONGLE_DISABLED;
} else {
hid_info(sc->hdev, "DualShock 4 USB dongle: calibration completed\n");
dongle_state = DONGLE_CONNECTED;
}
spin_lock_irqsave(&sc->lock, flags);
sc->ds4_dongle_state = dongle_state;
spin_unlock_irqrestore(&sc->lock, flags);
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
{ 0x00, 0x00, 0x40 },
{ 0x40, 0x00, 0x00 },
{ 0x00, 0x40, 0x00 },
{ 0x20, 0x00, 0x20 },
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
sony_schedule_work(sc, SONY_WORKER_STATE);
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
sony_schedule_work(drv_data, SONY_WORKER_STATE);
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
led->flags = LED_CORE_SUSPENDRESUME;
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
if (sc->quirks & (DUALSHOCK4_CONTROLLER_USB | DUALSHOCK4_DONGLE)) {
memset(buf, 0, DS4_OUTPUT_REPORT_0x05_SIZE);
buf[0] = 0x05;
buf[1] = 0x07;
offset = 4;
} else {
memset(buf, 0, DS4_OUTPUT_REPORT_0x11_SIZE);
buf[0] = 0x11;
buf[1] = 0xC0 | sc->ds4_bt_poll_interval;
buf[3] = 0x07;
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
if (sc->quirks & (DUALSHOCK4_CONTROLLER_USB | DUALSHOCK4_DONGLE))
hid_hw_output_report(hdev, buf, DS4_OUTPUT_REPORT_0x05_SIZE);
else {
u8 bthdr = 0xA2;
u32 crc;
crc = crc32_le(0xFFFFFFFF, &bthdr, 1);
crc = ~crc32_le(crc, buf, DS4_OUTPUT_REPORT_0x11_SIZE-4);
put_unaligned_le32(crc, &buf[74]);
hid_hw_output_report(hdev, buf, DS4_OUTPUT_REPORT_0x11_SIZE);
}
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
sc->output_report_dmabuf = kmalloc(DS4_OUTPUT_REPORT_0x11_SIZE,
GFP_KERNEL);
else if (sc->quirks & (DUALSHOCK4_CONTROLLER_USB | DUALSHOCK4_DONGLE))
sc->output_report_dmabuf = kmalloc(DS4_OUTPUT_REPORT_0x05_SIZE,
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
sony_schedule_work(sc, SONY_WORKER_STATE);
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
static int sony_battery_probe(struct sony_sc *sc, int append_dev_id)
{
const char *battery_str_fmt = append_dev_id ?
"sony_controller_battery_%pMR_%i" :
"sony_controller_battery_%pMR";
struct power_supply_config psy_cfg = { .drv_data = sc, };
struct hid_device *hdev = sc->hdev;
int ret;
sc->battery_capacity = 100;
sc->battery_desc.properties = sony_battery_props;
sc->battery_desc.num_properties = ARRAY_SIZE(sony_battery_props);
sc->battery_desc.get_property = sony_battery_get_property;
sc->battery_desc.type = POWER_SUPPLY_TYPE_BATTERY;
sc->battery_desc.use_for_apm = 0;
sc->battery_desc.name = kasprintf(GFP_KERNEL, battery_str_fmt,
sc->mac_address, sc->device_id);
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
static inline int sony_compare_connection_type(struct sony_sc *sc0,
struct sony_sc *sc1)
{
const int sc0_not_bt = !(sc0->quirks & SONY_BT_DEVICE);
const int sc1_not_bt = !(sc1->quirks & SONY_BT_DEVICE);
return sc0_not_bt == sc1_not_bt;
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
if (sony_compare_connection_type(sc, entry)) {
ret = 1;
} else {
ret = -EEXIST;
hid_info(sc->hdev,
"controller with MAC address %pMR already connected\n",
sc->mac_address);
}
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
} else if (sc->quirks & (DUALSHOCK4_CONTROLLER_USB | DUALSHOCK4_DONGLE)) {
buf = kmalloc(DS4_FEATURE_REPORT_0x81_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(sc->hdev, 0x81, buf,
DS4_FEATURE_REPORT_0x81_SIZE, HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret != DS4_FEATURE_REPORT_0x81_SIZE) {
hid_err(sc->hdev, "failed to retrieve feature report 0x81 with the DualShock 4 MAC address\n");
ret = ret < 0 ? ret : -EINVAL;
goto out_free;
}
memcpy(sc->mac_address, &buf[1], sizeof(sc->mac_address));
snprintf(sc->hdev->uniq, sizeof(sc->hdev->uniq),
"%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
sc->mac_address[5], sc->mac_address[4],
sc->mac_address[3], sc->mac_address[2],
sc->mac_address[1], sc->mac_address[0]);
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
snprintf(sc->hdev->uniq, sizeof(sc->hdev->uniq),
"%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
sc->mac_address[5], sc->mac_address[4],
sc->mac_address[3], sc->mac_address[2],
sc->mac_address[1], sc->mac_address[0]);
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
if (!sc->state_worker_initialized)
INIT_WORK(&sc->state_worker, sony_state_worker);
sc->state_worker_initialized = 1;
}
static inline void sony_cancel_work_sync(struct sony_sc *sc)
{
if (sc->hotplug_worker_initialized)
cancel_work_sync(&sc->hotplug_worker);
if (sc->state_worker_initialized)
cancel_work_sync(&sc->state_worker);
}
static int sony_input_configured(struct hid_device *hdev,
struct hid_input *hidinput)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
int append_dev_id;
int ret;
ret = sony_set_device_id(sc);
if (ret < 0) {
hid_err(hdev, "failed to allocate the device id\n");
goto err_stop;
}
ret = append_dev_id = sony_check_add(sc);
if (ret < 0)
goto err_stop;
ret = sony_allocate_output_report(sc);
if (ret < 0) {
hid_err(hdev, "failed to allocate the output report buffer\n");
goto err_stop;
}
if (sc->quirks & NAVIGATION_CONTROLLER_USB) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
hdev->quirks |= HID_QUIRK_SKIP_OUTPUT_REPORT_ID;
sc->defer_initialization = 1;
ret = sixaxis_set_operational_usb(hdev);
if (ret < 0) {
hid_err(hdev, "Failed to set controller into operational mode\n");
goto err_stop;
}
sony_init_output_report(sc, sixaxis_send_output_report);
} else if (sc->quirks & NAVIGATION_CONTROLLER_BT) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = sixaxis_set_operational_bt(hdev);
if (ret < 0) {
hid_err(hdev, "Failed to set controller into operational mode\n");
goto err_stop;
}
sony_init_output_report(sc, sixaxis_send_output_report);
} else if (sc->quirks & SIXAXIS_CONTROLLER_USB) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
hdev->quirks |= HID_QUIRK_SKIP_OUTPUT_REPORT_ID;
sc->defer_initialization = 1;
ret = sixaxis_set_operational_usb(hdev);
if (ret < 0) {
hid_err(hdev, "Failed to set controller into operational mode\n");
goto err_stop;
}
ret = sony_register_sensors(sc);
if (ret) {
hid_err(sc->hdev,
"Unable to initialize motion sensors: %d\n", ret);
goto err_stop;
}
sony_init_output_report(sc, sixaxis_send_output_report);
} else if (sc->quirks & SIXAXIS_CONTROLLER_BT) {
hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
ret = sixaxis_set_operational_bt(hdev);
if (ret < 0) {
hid_err(hdev, "Failed to set controller into operational mode\n");
goto err_stop;
}
ret = sony_register_sensors(sc);
if (ret) {
hid_err(sc->hdev,
"Unable to initialize motion sensors: %d\n", ret);
goto err_stop;
}
sony_init_output_report(sc, sixaxis_send_output_report);
} else if (sc->quirks & DUALSHOCK4_CONTROLLER) {
ret = dualshock4_get_calibration_data(sc);
if (ret < 0) {
hid_err(hdev, "Failed to get calibration data from Dualshock 4\n");
goto err_stop;
}
ret = sony_register_touchpad(sc, 2, 1920, 942);
if (ret) {
hid_err(sc->hdev,
"Unable to initialize multi-touch slots: %d\n",
ret);
goto err_stop;
}
ret = sony_register_sensors(sc);
if (ret) {
hid_err(sc->hdev,
"Unable to initialize motion sensors: %d\n", ret);
goto err_stop;
}
if (sc->quirks & DUALSHOCK4_CONTROLLER_BT) {
sc->ds4_bt_poll_interval = DS4_BT_DEFAULT_POLL_INTERVAL_MS;
ret = device_create_file(&sc->hdev->dev, &dev_attr_bt_poll_interval);
if (ret)
hid_warn(sc->hdev,
"can't create sysfs bt_poll_interval attribute err: %d\n",
ret);
}
if (sc->quirks & DUALSHOCK4_DONGLE) {
INIT_WORK(&sc->hotplug_worker, dualshock4_calibration_work);
sc->hotplug_worker_initialized = 1;
sc->ds4_dongle_state = DONGLE_DISCONNECTED;
}
sony_init_output_report(sc, dualshock4_send_output_report);
} else if (sc->quirks & MOTION_CONTROLLER) {
sony_init_output_report(sc, motion_send_output_report);
} else {
ret = 0;
}
if (sc->quirks & SONY_LED_SUPPORT) {
ret = sony_leds_init(sc);
if (ret < 0)
goto err_stop;
}
if (sc->quirks & SONY_BATTERY_SUPPORT) {
ret = sony_battery_probe(sc, append_dev_id);
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
if (sc->ds4_bt_poll_interval)
device_remove_file(&sc->hdev->dev, &dev_attr_bt_poll_interval);
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(sc);
if (sc->quirks & SONY_BATTERY_SUPPORT)
sony_battery_remove(sc);
if (sc->touchpad)
sony_unregister_touchpad(sc);
if (sc->sensor_dev)
sony_unregister_sensors(sc);
sony_cancel_work_sync(sc);
kfree(sc->output_report_dmabuf);
sony_remove_dev_list(sc);
sony_release_device_id(sc);
hid_hw_stop(hdev);
return ret;
}
static int sony_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
unsigned long quirks = id->driver_data;
struct sony_sc *sc;
unsigned int connect_mask = HID_CONNECT_DEFAULT;
if (!strcmp(hdev->name, "FutureMax Dance Mat"))
quirks |= FUTUREMAX_DANCE_MAT;
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
if (sc->quirks & (SIXAXIS_CONTROLLER | DUALSHOCK4_CONTROLLER))
hdev->version |= 0x8000;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
if (!(hdev->claimed & HID_CLAIMED_INPUT)) {
hid_err(hdev, "failed to claim input\n");
return -ENODEV;
}
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
hid_hw_close(hdev);
if (sc->quirks & SONY_LED_SUPPORT)
sony_leds_remove(sc);
if (sc->quirks & SONY_BATTERY_SUPPORT)
sony_battery_remove(sc);
if (sc->touchpad)
sony_unregister_touchpad(sc);
if (sc->sensor_dev)
sony_unregister_sensors(sc);
if (sc->quirks & DUALSHOCK4_CONTROLLER_BT)
device_remove_file(&sc->hdev->dev, &dev_attr_bt_poll_interval);
sony_cancel_work_sync(sc);
kfree(sc->output_report_dmabuf);
sony_remove_dev_list(sc);
sony_release_device_id(sc);
hid_hw_stop(hdev);
}
static int sony_suspend(struct hid_device *hdev, pm_message_t message)
{
#ifdef CONFIG_SONY_FF
if (SONY_FF_SUPPORT) {
struct sony_sc *sc = hid_get_drvdata(hdev);
sc->left = sc->right = 0;
sony_send_output_report(sc);
}
#endif
return 0;
}
static int sony_resume(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & SIXAXIS_CONTROLLER_USB) ||
(sc->quirks & NAVIGATION_CONTROLLER_USB)) {
sixaxis_set_operational_usb(sc->hdev);
sc->defer_initialization = 1;
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
