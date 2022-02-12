static void wacom_notify_battery(struct wacom_wac *wacom_wac,
int bat_capacity, bool bat_charging, bool bat_connected,
bool ps_connected)
{
struct wacom *wacom = container_of(wacom_wac, struct wacom, wacom_wac);
bool changed = wacom_wac->battery_capacity != bat_capacity ||
wacom_wac->bat_charging != bat_charging ||
wacom_wac->bat_connected != bat_connected ||
wacom_wac->ps_connected != ps_connected;
if (changed) {
wacom_wac->battery_capacity = bat_capacity;
wacom_wac->bat_charging = bat_charging;
wacom_wac->bat_connected = bat_connected;
wacom_wac->ps_connected = ps_connected;
if (wacom->battery)
power_supply_changed(wacom->battery);
}
}
static int wacom_penpartner_irq(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
switch (data[0]) {
case 1:
if (data[5] & 0x80) {
wacom->tool[0] = (data[5] & 0x20) ? BTN_TOOL_RUBBER : BTN_TOOL_PEN;
wacom->id[0] = (data[5] & 0x20) ? ERASER_DEVICE_ID : STYLUS_DEVICE_ID;
input_report_key(input, wacom->tool[0], 1);
input_report_abs(input, ABS_MISC, wacom->id[0]);
input_report_abs(input, ABS_X, get_unaligned_le16(&data[1]));
input_report_abs(input, ABS_Y, get_unaligned_le16(&data[3]));
input_report_abs(input, ABS_PRESSURE, (signed char)data[6] + 127);
input_report_key(input, BTN_TOUCH, ((signed char)data[6] > -127));
input_report_key(input, BTN_STYLUS, (data[5] & 0x40));
} else {
input_report_key(input, wacom->tool[0], 0);
input_report_abs(input, ABS_MISC, 0);
input_report_abs(input, ABS_PRESSURE, -1);
input_report_key(input, BTN_TOUCH, 0);
}
break;
case 2:
input_report_key(input, BTN_TOOL_PEN, 1);
input_report_abs(input, ABS_MISC, STYLUS_DEVICE_ID);
input_report_abs(input, ABS_X, get_unaligned_le16(&data[1]));
input_report_abs(input, ABS_Y, get_unaligned_le16(&data[3]));
input_report_abs(input, ABS_PRESSURE, (signed char)data[6] + 127);
input_report_key(input, BTN_TOUCH, ((signed char)data[6] > -80) && !(data[5] & 0x20));
input_report_key(input, BTN_STYLUS, (data[5] & 0x40));
break;
default:
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__, data[0]);
return 0;
}
return 1;
}
static int wacom_pl_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
int prox, pressure;
if (data[0] != WACOM_REPORT_PENABLED) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__, data[0]);
return 0;
}
prox = data[1] & 0x40;
if (!wacom->id[0]) {
if ((data[0] & 0x10) || (data[4] & 0x20)) {
wacom->tool[0] = BTN_TOOL_RUBBER;
wacom->id[0] = ERASER_DEVICE_ID;
}
else {
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
}
}
if (wacom->tool[0] == BTN_TOOL_RUBBER && !(data[4] & 0x20)) {
input_report_key(input, BTN_TOOL_RUBBER, 0);
input_report_abs(input, ABS_MISC, 0);
input_sync(input);
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
}
pressure = (signed char)((data[7] << 1) | ((data[4] >> 2) & 1));
if (features->pressure_max > 255)
pressure = (pressure << 1) | ((data[4] >> 6) & 1);
pressure += (features->pressure_max + 1) / 2;
input_report_abs(input, ABS_X, data[3] | (data[2] << 7) | ((data[1] & 0x03) << 14));
input_report_abs(input, ABS_Y, data[6] | (data[5] << 7) | ((data[4] & 0x03) << 14));
input_report_abs(input, ABS_PRESSURE, pressure);
input_report_key(input, BTN_TOUCH, data[4] & 0x08);
input_report_key(input, BTN_STYLUS, data[4] & 0x10);
input_report_key(input, BTN_STYLUS2, (wacom->tool[0] == BTN_TOOL_PEN) && (data[4] & 0x20));
if (!prox)
wacom->id[0] = 0;
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
static int wacom_ptu_irq(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
if (data[0] != WACOM_REPORT_PENABLED) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__, data[0]);
return 0;
}
if (data[1] & 0x04) {
input_report_key(input, BTN_TOOL_RUBBER, data[1] & 0x20);
input_report_key(input, BTN_TOUCH, data[1] & 0x08);
wacom->id[0] = ERASER_DEVICE_ID;
} else {
input_report_key(input, BTN_TOOL_PEN, data[1] & 0x20);
input_report_key(input, BTN_TOUCH, data[1] & 0x01);
wacom->id[0] = STYLUS_DEVICE_ID;
}
input_report_abs(input, ABS_MISC, wacom->id[0]);
input_report_abs(input, ABS_X, le16_to_cpup((__le16 *)&data[2]));
input_report_abs(input, ABS_Y, le16_to_cpup((__le16 *)&data[4]));
input_report_abs(input, ABS_PRESSURE, le16_to_cpup((__le16 *)&data[6]));
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, data[1] & 0x10);
return 1;
}
static int wacom_dtu_irq(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
int prox = data[1] & 0x20;
dev_dbg(input->dev.parent,
"%s: received report #%d", __func__, data[0]);
if (prox) {
wacom->tool[0] = (data[1] & 0x0c) ? BTN_TOOL_RUBBER : BTN_TOOL_PEN;
if (wacom->tool[0] == BTN_TOOL_PEN)
wacom->id[0] = STYLUS_DEVICE_ID;
else
wacom->id[0] = ERASER_DEVICE_ID;
}
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, data[1] & 0x10);
input_report_abs(input, ABS_X, le16_to_cpup((__le16 *)&data[2]));
input_report_abs(input, ABS_Y, le16_to_cpup((__le16 *)&data[4]));
input_report_abs(input, ABS_PRESSURE, ((data[7] & 0x01) << 8) | data[6]);
input_report_key(input, BTN_TOUCH, data[1] & 0x05);
if (!prox)
wacom->id[0] = 0;
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
static int wacom_dtus_irq(struct wacom_wac *wacom)
{
char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
unsigned short prox, pressure = 0;
if (data[0] != WACOM_REPORT_DTUS && data[0] != WACOM_REPORT_DTUSPAD) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d", __func__, data[0]);
return 0;
} else if (data[0] == WACOM_REPORT_DTUSPAD) {
input = wacom->pad_input;
input_report_key(input, BTN_0, (data[1] & 0x01));
input_report_key(input, BTN_1, (data[1] & 0x02));
input_report_key(input, BTN_2, (data[1] & 0x04));
input_report_key(input, BTN_3, (data[1] & 0x08));
input_report_abs(input, ABS_MISC,
data[1] & 0x0f ? PAD_DEVICE_ID : 0);
return 1;
} else {
prox = data[1] & 0x80;
if (prox) {
switch ((data[1] >> 3) & 3) {
case 1:
wacom->tool[0] = BTN_TOOL_RUBBER;
wacom->id[0] = ERASER_DEVICE_ID;
break;
case 2:
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
break;
}
}
input_report_key(input, BTN_STYLUS, data[1] & 0x20);
input_report_key(input, BTN_STYLUS2, data[1] & 0x40);
input_report_abs(input, ABS_X, get_unaligned_be16(&data[3]));
input_report_abs(input, ABS_Y, get_unaligned_be16(&data[5]));
pressure = ((data[1] & 0x03) << 8) | (data[2] & 0xff);
input_report_abs(input, ABS_PRESSURE, pressure);
input_report_key(input, BTN_TOUCH, pressure > 10);
if (!prox)
wacom->id[0] = 0;
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
}
static int wacom_graphire_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
struct input_dev *pad_input = wacom->pad_input;
int battery_capacity, ps_connected;
int prox;
int rw = 0;
int retval = 0;
if (features->type == GRAPHIRE_BT) {
if (data[0] != WACOM_REPORT_PENABLED_BT) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__,
data[0]);
goto exit;
}
} else if (data[0] != WACOM_REPORT_PENABLED) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__, data[0]);
goto exit;
}
prox = data[1] & 0x80;
if (prox || wacom->id[0]) {
if (prox) {
switch ((data[1] >> 5) & 3) {
case 0:
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
break;
case 1:
wacom->tool[0] = BTN_TOOL_RUBBER;
wacom->id[0] = ERASER_DEVICE_ID;
break;
case 2:
input_report_key(input, BTN_MIDDLE, data[1] & 0x04);
case 3:
wacom->tool[0] = BTN_TOOL_MOUSE;
wacom->id[0] = CURSOR_DEVICE_ID;
break;
}
}
input_report_abs(input, ABS_X, le16_to_cpup((__le16 *)&data[2]));
input_report_abs(input, ABS_Y, le16_to_cpup((__le16 *)&data[4]));
if (wacom->tool[0] != BTN_TOOL_MOUSE) {
if (features->type == GRAPHIRE_BT)
input_report_abs(input, ABS_PRESSURE, data[6] |
(((__u16) (data[1] & 0x08)) << 5));
else
input_report_abs(input, ABS_PRESSURE, data[6] |
((data[7] & 0x03) << 8));
input_report_key(input, BTN_TOUCH, data[1] & 0x01);
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, data[1] & 0x04);
} else {
input_report_key(input, BTN_LEFT, data[1] & 0x01);
input_report_key(input, BTN_RIGHT, data[1] & 0x02);
if (features->type == WACOM_G4 ||
features->type == WACOM_MO) {
input_report_abs(input, ABS_DISTANCE, data[6] & 0x3f);
rw = (data[7] & 0x04) - (data[7] & 0x03);
} else if (features->type == GRAPHIRE_BT) {
rw = 44 - (data[6] >> 2);
rw = clamp_val(rw, 0, 31);
input_report_abs(input, ABS_DISTANCE, rw);
if (((data[1] >> 5) & 3) == 2) {
input_report_key(input, BTN_MIDDLE,
data[1] & 0x04);
rw = (data[6] & 0x01) ? -1 :
(data[6] & 0x02) ? 1 : 0;
} else {
rw = 0;
}
} else {
input_report_abs(input, ABS_DISTANCE, data[7] & 0x3f);
rw = -(signed char)data[6];
}
input_report_rel(input, REL_WHEEL, rw);
}
if (!prox)
wacom->id[0] = 0;
input_report_abs(input, ABS_MISC, wacom->id[0]);
input_report_key(input, wacom->tool[0], prox);
input_sync(input);
}
switch (features->type) {
case WACOM_G4:
prox = data[7] & 0xf8;
if (prox || wacom->id[1]) {
wacom->id[1] = PAD_DEVICE_ID;
input_report_key(pad_input, BTN_BACK, (data[7] & 0x40));
input_report_key(pad_input, BTN_FORWARD, (data[7] & 0x80));
rw = ((data[7] & 0x18) >> 3) - ((data[7] & 0x20) >> 3);
input_report_rel(pad_input, REL_WHEEL, rw);
if (!prox)
wacom->id[1] = 0;
input_report_abs(pad_input, ABS_MISC, wacom->id[1]);
retval = 1;
}
break;
case WACOM_MO:
prox = (data[7] & 0xf8) || data[8];
if (prox || wacom->id[1]) {
wacom->id[1] = PAD_DEVICE_ID;
input_report_key(pad_input, BTN_BACK, (data[7] & 0x08));
input_report_key(pad_input, BTN_LEFT, (data[7] & 0x20));
input_report_key(pad_input, BTN_FORWARD, (data[7] & 0x10));
input_report_key(pad_input, BTN_RIGHT, (data[7] & 0x40));
input_report_abs(pad_input, ABS_WHEEL, (data[8] & 0x7f));
if (!prox)
wacom->id[1] = 0;
input_report_abs(pad_input, ABS_MISC, wacom->id[1]);
retval = 1;
}
break;
case GRAPHIRE_BT:
prox = data[7] & 0x03;
if (prox || wacom->id[1]) {
wacom->id[1] = PAD_DEVICE_ID;
input_report_key(pad_input, BTN_0, (data[7] & 0x02));
input_report_key(pad_input, BTN_1, (data[7] & 0x01));
if (!prox)
wacom->id[1] = 0;
input_report_abs(pad_input, ABS_MISC, wacom->id[1]);
retval = 1;
}
break;
}
if (features->type == GRAPHIRE_BT) {
rw = (data[7] >> 2 & 0x07);
battery_capacity = batcap_gr[rw];
ps_connected = rw == 7;
wacom_notify_battery(wacom, battery_capacity, ps_connected,
1, ps_connected);
}
exit:
return retval;
}
static void wacom_intuos_schedule_prox_event(struct wacom_wac *wacom_wac)
{
struct wacom *wacom = container_of(wacom_wac, struct wacom, wacom_wac);
struct hid_report *r;
struct hid_report_enum *re;
re = &(wacom->hdev->report_enum[HID_FEATURE_REPORT]);
r = re->report_id_hash[WACOM_REPORT_INTUOSREAD];
if (r) {
hid_hw_request(wacom->hdev, r, HID_REQ_GET_REPORT);
}
}
static int wacom_intuos_inout(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
int idx = 0;
if (features->type == INTUOS)
idx = data[1] & 0x01;
if ((data[1] & 0xfc) == 0xc0) {
wacom->serial[idx] = ((data[3] & 0x0f) << 28) +
(data[4] << 20) + (data[5] << 12) +
(data[6] << 4) + (data[7] >> 4);
wacom->id[idx] = (data[2] << 4) | (data[3] >> 4) |
((data[7] & 0x0f) << 20) | ((data[8] & 0xf0) << 12);
switch (wacom->id[idx]) {
case 0x812:
case 0x801:
case 0x120802:
case 0x012:
wacom->tool[idx] = BTN_TOOL_PENCIL;
break;
case 0x822:
case 0x842:
case 0x852:
case 0x823:
case 0x813:
case 0x885:
case 0x802:
case 0x804:
case 0x022:
case 0x100804:
case 0x140802:
case 0x160802:
case 0x180802:
case 0x100802:
wacom->tool[idx] = BTN_TOOL_PEN;
break;
case 0x832:
case 0x032:
wacom->tool[idx] = BTN_TOOL_BRUSH;
break;
case 0x007:
case 0x09c:
case 0x094:
case 0x017:
case 0x806:
wacom->tool[idx] = BTN_TOOL_MOUSE;
break;
case 0x096:
case 0x097:
case 0x006:
wacom->tool[idx] = BTN_TOOL_LENS;
break;
case 0x82a:
case 0x85a:
case 0x91a:
case 0xd1a:
case 0x0fa:
case 0x82b:
case 0x81b:
case 0x91b:
case 0x80c:
case 0x80a:
case 0x90a:
case 0x14080a:
case 0x10090a:
case 0x10080c:
case 0x16080a:
case 0x18080a:
case 0x10080a:
wacom->tool[idx] = BTN_TOOL_RUBBER;
break;
case 0xd12:
case 0x912:
case 0x112:
case 0x913:
case 0x902:
case 0x100902:
wacom->tool[idx] = BTN_TOOL_AIRBRUSH;
break;
default:
wacom->tool[idx] = BTN_TOOL_PEN;
break;
}
return 1;
}
if ((!((wacom->id[idx] >> 20) & 0x01) &&
(features->type == WACOM_21UX2)) ||
(wacom->tool[idx] == BTN_TOOL_LENS &&
(features->type == INTUOS3 ||
features->type == INTUOS3S ||
features->type == INTUOS4 ||
features->type == INTUOS4S ||
features->type == INTUOS5 ||
features->type == INTUOS5S ||
features->type == INTUOSPM ||
features->type == INTUOSPS)) ||
(features->type == CINTIQ && !(data[1] & 0x40)))
return 1;
wacom->shared->stylus_in_proximity = true;
if (wacom->shared->touch_down)
return 1;
if (((data[1] & 0xfe) == 0x20) && wacom->reporting_data) {
input_report_key(input, BTN_TOUCH, 0);
input_report_abs(input, ABS_PRESSURE, 0);
input_report_abs(input, ABS_DISTANCE, wacom->features.distance_max);
return 2;
}
if ((data[1] & 0xfe) == 0x80) {
wacom->shared->stylus_in_proximity = false;
wacom->reporting_data = false;
if (!wacom->id[idx])
return 1;
input_report_abs(input, ABS_X, 0);
input_report_abs(input, ABS_Y, 0);
input_report_abs(input, ABS_DISTANCE, 0);
input_report_abs(input, ABS_TILT_X, 0);
input_report_abs(input, ABS_TILT_Y, 0);
if (wacom->tool[idx] >= BTN_TOOL_MOUSE) {
input_report_key(input, BTN_LEFT, 0);
input_report_key(input, BTN_MIDDLE, 0);
input_report_key(input, BTN_RIGHT, 0);
input_report_key(input, BTN_SIDE, 0);
input_report_key(input, BTN_EXTRA, 0);
input_report_abs(input, ABS_THROTTLE, 0);
input_report_abs(input, ABS_RZ, 0);
} else {
input_report_abs(input, ABS_PRESSURE, 0);
input_report_key(input, BTN_STYLUS, 0);
input_report_key(input, BTN_STYLUS2, 0);
input_report_key(input, BTN_TOUCH, 0);
input_report_abs(input, ABS_WHEEL, 0);
if (features->type >= INTUOS3S)
input_report_abs(input, ABS_Z, 0);
}
input_report_key(input, wacom->tool[idx], 0);
input_report_abs(input, ABS_MISC, 0);
input_event(input, EV_MSC, MSC_SERIAL, wacom->serial[idx]);
wacom->id[idx] = 0;
return 2;
}
if (!wacom->id[idx]) {
wacom_intuos_schedule_prox_event(wacom);
return 1;
}
return 0;
}
static int wacom_remote_irq(struct wacom_wac *wacom_wac, size_t len)
{
unsigned char *data = wacom_wac->data;
struct input_dev *input = wacom_wac->pad_input;
struct wacom *wacom = container_of(wacom_wac, struct wacom, wacom_wac);
struct wacom_features *features = &wacom_wac->features;
int bat_charging, bat_percent, touch_ring_mode;
__u32 serial;
int i;
if (data[0] != WACOM_REPORT_REMOTE) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d", __func__, data[0]);
return 0;
}
serial = data[3] + (data[4] << 8) + (data[5] << 16);
wacom_wac->id[0] = PAD_DEVICE_ID;
input_report_key(input, BTN_0, (data[9] & 0x01));
input_report_key(input, BTN_1, (data[9] & 0x02));
input_report_key(input, BTN_2, (data[9] & 0x04));
input_report_key(input, BTN_3, (data[9] & 0x08));
input_report_key(input, BTN_4, (data[9] & 0x10));
input_report_key(input, BTN_5, (data[9] & 0x20));
input_report_key(input, BTN_6, (data[9] & 0x40));
input_report_key(input, BTN_7, (data[9] & 0x80));
input_report_key(input, BTN_8, (data[10] & 0x01));
input_report_key(input, BTN_9, (data[10] & 0x02));
input_report_key(input, BTN_A, (data[10] & 0x04));
input_report_key(input, BTN_B, (data[10] & 0x08));
input_report_key(input, BTN_C, (data[10] & 0x10));
input_report_key(input, BTN_X, (data[10] & 0x20));
input_report_key(input, BTN_Y, (data[10] & 0x40));
input_report_key(input, BTN_Z, (data[10] & 0x80));
input_report_key(input, BTN_BASE, (data[11] & 0x01));
input_report_key(input, BTN_BASE2, (data[11] & 0x02));
if (data[12] & 0x80)
input_report_abs(input, ABS_WHEEL, (data[12] & 0x7f));
else
input_report_abs(input, ABS_WHEEL, 0);
bat_percent = data[7] & 0x7f;
bat_charging = !!(data[7] & 0x80);
if (data[9] | data[10] | (data[11] & 0x03) | data[12])
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
else
input_report_abs(input, ABS_MISC, 0);
input_event(input, EV_MSC, MSC_SERIAL, serial);
touch_ring_mode = (data[11] & 0xC0) >> 6;
for (i = 0; i < WACOM_MAX_REMOTES; i++) {
if (wacom_wac->serial[i] == serial)
wacom->led.select[i] = touch_ring_mode;
}
if (!wacom->battery &&
!(features->quirks & WACOM_QUIRK_BATTERY)) {
features->quirks |= WACOM_QUIRK_BATTERY;
INIT_WORK(&wacom->work, wacom_battery_work);
wacom_schedule_work(wacom_wac);
}
wacom_notify_battery(wacom_wac, bat_percent, bat_charging, 1,
bat_charging);
return 1;
}
static int wacom_remote_status_irq(struct wacom_wac *wacom_wac, size_t len)
{
struct wacom *wacom = container_of(wacom_wac, struct wacom, wacom_wac);
unsigned char *data = wacom_wac->data;
int i;
if (data[0] != WACOM_REPORT_DEVICE_LIST)
return 0;
for (i = 0; i < WACOM_MAX_REMOTES; i++) {
int j = i * 6;
int serial = (data[j+6] << 16) + (data[j+5] << 8) + data[j+4];
bool connected = data[j+2];
if (connected) {
int k;
if (wacom_wac->serial[i] == serial)
continue;
if (wacom_wac->serial[i]) {
wacom_remote_destroy_attr_group(wacom,
wacom_wac->serial[i]);
}
for (k = 0; k < WACOM_MAX_REMOTES; k++) {
if (wacom_wac->serial[k] == serial)
break;
}
if (k < WACOM_MAX_REMOTES) {
wacom_wac->serial[i] = serial;
continue;
}
wacom_remote_create_attr_group(wacom, serial, i);
} else if (wacom_wac->serial[i]) {
wacom_remote_destroy_attr_group(wacom,
wacom_wac->serial[i]);
}
}
return 0;
}
static void wacom_intuos_general(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
unsigned int t;
if ((data[1] & 0xb8) == 0xa0) {
t = (data[6] << 2) | ((data[7] >> 6) & 3);
if (features->type >= INTUOS4S && features->type <= CINTIQ_HYBRID) {
t = (t << 1) | (data[1] & 1);
}
input_report_abs(input, ABS_PRESSURE, t);
input_report_abs(input, ABS_TILT_X,
(((data[7] << 1) & 0x7e) | (data[8] >> 7)) - 64);
input_report_abs(input, ABS_TILT_Y, (data[8] & 0x7f) - 64);
input_report_key(input, BTN_STYLUS, data[1] & 2);
input_report_key(input, BTN_STYLUS2, data[1] & 4);
input_report_key(input, BTN_TOUCH, t > 10);
}
if ((data[1] & 0xbc) == 0xb4) {
input_report_abs(input, ABS_WHEEL,
(data[6] << 2) | ((data[7] >> 6) & 3));
input_report_abs(input, ABS_TILT_X,
(((data[7] << 1) & 0x7e) | (data[8] >> 7)) - 64);
input_report_abs(input, ABS_TILT_Y, (data[8] & 0x7f) - 64);
}
}
static int wacom_intuos_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
unsigned int t;
int idx = 0, result;
if (data[0] != WACOM_REPORT_PENABLED &&
data[0] != WACOM_REPORT_INTUOSREAD &&
data[0] != WACOM_REPORT_INTUOSWRITE &&
data[0] != WACOM_REPORT_INTUOSPAD &&
data[0] != WACOM_REPORT_CINTIQ &&
data[0] != WACOM_REPORT_CINTIQPAD &&
data[0] != WACOM_REPORT_INTUOS5PAD) {
dev_dbg(input->dev.parent,
"%s: received unknown report #%d\n", __func__, data[0]);
return 0;
}
if (features->type == INTUOS)
idx = data[1] & 0x01;
if (data[0] == WACOM_REPORT_INTUOSPAD || data[0] == WACOM_REPORT_INTUOS5PAD ||
data[0] == WACOM_REPORT_CINTIQPAD) {
input = wacom->pad_input;
if (features->type >= INTUOS4S && features->type <= INTUOS4L) {
input_report_key(input, BTN_0, (data[2] & 0x01));
input_report_key(input, BTN_1, (data[3] & 0x01));
input_report_key(input, BTN_2, (data[3] & 0x02));
input_report_key(input, BTN_3, (data[3] & 0x04));
input_report_key(input, BTN_4, (data[3] & 0x08));
input_report_key(input, BTN_5, (data[3] & 0x10));
input_report_key(input, BTN_6, (data[3] & 0x20));
if (data[1] & 0x80) {
input_report_abs(input, ABS_WHEEL, (data[1] & 0x7f));
} else {
input_report_abs(input, ABS_WHEEL, 0);
}
if (features->type != INTUOS4S) {
input_report_key(input, BTN_7, (data[3] & 0x40));
input_report_key(input, BTN_8, (data[3] & 0x80));
}
if (data[1] | (data[2] & 0x01) | data[3]) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type == DTK) {
input_report_key(input, BTN_0, (data[6] & 0x01));
input_report_key(input, BTN_1, (data[6] & 0x02));
input_report_key(input, BTN_2, (data[6] & 0x04));
input_report_key(input, BTN_3, (data[6] & 0x08));
input_report_key(input, BTN_4, (data[6] & 0x10));
input_report_key(input, BTN_5, (data[6] & 0x20));
if (data[6] & 0x3f) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type == WACOM_13HD) {
input_report_key(input, BTN_0, (data[3] & 0x01));
input_report_key(input, BTN_1, (data[4] & 0x01));
input_report_key(input, BTN_2, (data[4] & 0x02));
input_report_key(input, BTN_3, (data[4] & 0x04));
input_report_key(input, BTN_4, (data[4] & 0x08));
input_report_key(input, BTN_5, (data[4] & 0x10));
input_report_key(input, BTN_6, (data[4] & 0x20));
input_report_key(input, BTN_7, (data[4] & 0x40));
input_report_key(input, BTN_8, (data[4] & 0x80));
if ((data[3] & 0x01) | data[4]) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type == WACOM_24HD) {
input_report_key(input, BTN_0, (data[6] & 0x01));
input_report_key(input, BTN_1, (data[6] & 0x02));
input_report_key(input, BTN_2, (data[6] & 0x04));
input_report_key(input, BTN_3, (data[6] & 0x08));
input_report_key(input, BTN_4, (data[6] & 0x10));
input_report_key(input, BTN_5, (data[6] & 0x20));
input_report_key(input, BTN_6, (data[6] & 0x40));
input_report_key(input, BTN_7, (data[6] & 0x80));
input_report_key(input, BTN_8, (data[8] & 0x01));
input_report_key(input, BTN_9, (data[8] & 0x02));
input_report_key(input, BTN_A, (data[8] & 0x04));
input_report_key(input, BTN_B, (data[8] & 0x08));
input_report_key(input, BTN_C, (data[8] & 0x10));
input_report_key(input, BTN_X, (data[8] & 0x20));
input_report_key(input, BTN_Y, (data[8] & 0x40));
input_report_key(input, BTN_Z, (data[8] & 0x80));
input_report_key(input, KEY_PROG1, data[4] & 0x07);
input_report_key(input, KEY_PROG2, data[4] & 0xE0);
input_report_key(input, KEY_PROG3, data[3] & 0x1C);
if (data[1] & 0x80) {
input_report_abs(input, ABS_WHEEL, (data[1] & 0x7f));
} else {
input_report_abs(input, ABS_WHEEL, 0);
}
if (data[2] & 0x80) {
input_report_abs(input, ABS_THROTTLE, (data[2] & 0x7f));
} else {
input_report_abs(input, ABS_THROTTLE, 0);
}
if (data[1] | data[2] | (data[3] & 0x1f) | data[4] | data[6] | data[8]) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type == WACOM_27QHD) {
input_report_key(input, KEY_PROG1, data[2] & 0x01);
input_report_key(input, KEY_PROG2, data[2] & 0x02);
input_report_key(input, KEY_PROG3, data[2] & 0x04);
input_report_abs(input, ABS_X, be16_to_cpup((__be16 *)&data[4]));
input_report_abs(input, ABS_Y, be16_to_cpup((__be16 *)&data[6]));
input_report_abs(input, ABS_Z, be16_to_cpup((__be16 *)&data[8]));
if ((data[2] & 0x07) | data[4] | data[5] | data[6] | data[7] | data[8] | data[9]) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type == CINTIQ_HYBRID) {
input_report_key(input, BTN_1, (data[4] & 0x01));
input_report_key(input, BTN_2, (data[4] & 0x02));
input_report_key(input, BTN_3, (data[4] & 0x04));
input_report_key(input, BTN_4, (data[4] & 0x08));
input_report_key(input, BTN_5, (data[4] & 0x10));
input_report_key(input, BTN_6, (data[4] & 0x20));
input_report_key(input, BTN_7, (data[4] & 0x40));
input_report_key(input, BTN_8, (data[4] & 0x80));
input_report_key(input, BTN_0, (data[3] & 0x01));
if (data[4] | (data[3] & 0x01)) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else if (features->type >= INTUOS5S && features->type <= INTUOSPL) {
int i;
input_report_key(input, BTN_0, (data[3] & 0x01));
for (i = 0; i < 8; i++)
input_report_key(input, BTN_1 + i, data[4] & (1 << i));
if (data[2] & 0x80) {
input_report_abs(input, ABS_WHEEL, (data[2] & 0x7f));
} else {
input_report_abs(input, ABS_WHEEL, 0);
}
if (data[2] | (data[3] & 0x01) | data[4] | data[5]) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
} else {
if (features->type == WACOM_21UX2 || features->type == WACOM_22HD) {
input_report_key(input, BTN_0, (data[5] & 0x01));
input_report_key(input, BTN_1, (data[6] & 0x01));
input_report_key(input, BTN_2, (data[6] & 0x02));
input_report_key(input, BTN_3, (data[6] & 0x04));
input_report_key(input, BTN_4, (data[6] & 0x08));
input_report_key(input, BTN_5, (data[6] & 0x10));
input_report_key(input, BTN_6, (data[6] & 0x20));
input_report_key(input, BTN_7, (data[6] & 0x40));
input_report_key(input, BTN_8, (data[6] & 0x80));
input_report_key(input, BTN_9, (data[7] & 0x01));
input_report_key(input, BTN_A, (data[8] & 0x01));
input_report_key(input, BTN_B, (data[8] & 0x02));
input_report_key(input, BTN_C, (data[8] & 0x04));
input_report_key(input, BTN_X, (data[8] & 0x08));
input_report_key(input, BTN_Y, (data[8] & 0x10));
input_report_key(input, BTN_Z, (data[8] & 0x20));
input_report_key(input, BTN_BASE, (data[8] & 0x40));
input_report_key(input, BTN_BASE2, (data[8] & 0x80));
if (features->type == WACOM_22HD) {
input_report_key(input, KEY_PROG1, data[9] & 0x01);
input_report_key(input, KEY_PROG2, data[9] & 0x02);
input_report_key(input, KEY_PROG3, data[9] & 0x04);
}
} else {
input_report_key(input, BTN_0, (data[5] & 0x01));
input_report_key(input, BTN_1, (data[5] & 0x02));
input_report_key(input, BTN_2, (data[5] & 0x04));
input_report_key(input, BTN_3, (data[5] & 0x08));
input_report_key(input, BTN_4, (data[6] & 0x01));
input_report_key(input, BTN_5, (data[6] & 0x02));
input_report_key(input, BTN_6, (data[6] & 0x04));
input_report_key(input, BTN_7, (data[6] & 0x08));
input_report_key(input, BTN_8, (data[5] & 0x10));
input_report_key(input, BTN_9, (data[6] & 0x10));
}
input_report_abs(input, ABS_RX, ((data[1] & 0x1f) << 8) | data[2]);
input_report_abs(input, ABS_RY, ((data[3] & 0x1f) << 8) | data[4]);
if ((data[5] & 0x1f) | data[6] | (data[1] & 0x1f) |
data[2] | (data[3] & 0x1f) | data[4] | data[8] |
(data[7] & 0x01)) {
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_abs(input, ABS_MISC, 0);
}
}
return 1;
}
result = wacom_intuos_inout(wacom);
if (result)
return result - 1;
if (features->type >= INTUOS3S) {
input_report_abs(input, ABS_X, (data[2] << 9) | (data[3] << 1) | ((data[9] >> 1) & 1));
input_report_abs(input, ABS_Y, (data[4] << 9) | (data[5] << 1) | (data[9] & 1));
input_report_abs(input, ABS_DISTANCE, ((data[9] >> 2) & 0x3f));
} else {
input_report_abs(input, ABS_X, be16_to_cpup((__be16 *)&data[2]));
input_report_abs(input, ABS_Y, be16_to_cpup((__be16 *)&data[4]));
input_report_abs(input, ABS_DISTANCE, ((data[9] >> 3) & 0x1f));
}
wacom_intuos_general(wacom);
if ((data[1] & 0xbc) == 0xa8 || (data[1] & 0xbe) == 0xb0 || (data[1] & 0xbc) == 0xac) {
if (data[1] & 0x02) {
if (features->type >= INTUOS3S) {
t = (data[6] << 3) | ((data[7] >> 5) & 7);
t = (data[7] & 0x20) ? ((t > 900) ? ((t-1) / 2 - 1350) :
((t-1) / 2 + 450)) : (450 - t / 2) ;
input_report_abs(input, ABS_Z, t);
} else {
t = (data[6] << 3) | ((data[7] >> 5) & 7);
input_report_abs(input, ABS_RZ, (data[7] & 0x20) ?
((t - 1) / 2) : -t / 2);
}
} else if (!(data[1] & 0x10) && features->type < INTUOS3S) {
input_report_key(input, BTN_LEFT, data[8] & 0x01);
input_report_key(input, BTN_MIDDLE, data[8] & 0x02);
input_report_key(input, BTN_RIGHT, data[8] & 0x04);
input_report_key(input, BTN_SIDE, data[8] & 0x20);
input_report_key(input, BTN_EXTRA, data[8] & 0x10);
t = (data[6] << 2) | ((data[7] >> 6) & 3);
input_report_abs(input, ABS_THROTTLE, (data[8] & 0x08) ? -t : t);
} else if (wacom->tool[idx] == BTN_TOOL_MOUSE) {
if (features->type >= INTUOS4S && features->type <= INTUOSPL) {
input_report_key(input, BTN_LEFT, data[6] & 0x01);
input_report_key(input, BTN_MIDDLE, data[6] & 0x02);
input_report_key(input, BTN_RIGHT, data[6] & 0x04);
input_report_rel(input, REL_WHEEL, ((data[7] & 0x80) >> 7)
- ((data[7] & 0x40) >> 6));
input_report_key(input, BTN_SIDE, data[6] & 0x08);
input_report_key(input, BTN_EXTRA, data[6] & 0x10);
input_report_abs(input, ABS_TILT_X,
(((data[7] << 1) & 0x7e) | (data[8] >> 7)) - 64);
input_report_abs(input, ABS_TILT_Y, (data[8] & 0x7f) - 64);
} else {
input_report_key(input, BTN_LEFT, data[8] & 0x04);
input_report_key(input, BTN_MIDDLE, data[8] & 0x08);
input_report_key(input, BTN_RIGHT, data[8] & 0x10);
input_report_rel(input, REL_WHEEL, (data[8] & 0x01)
- ((data[8] & 0x02) >> 1));
if (features->type >= INTUOS3S && features->type <= INTUOS3L) {
input_report_key(input, BTN_SIDE, data[8] & 0x40);
input_report_key(input, BTN_EXTRA, data[8] & 0x20);
}
}
} else if ((features->type < INTUOS3S || features->type == INTUOS3L ||
features->type == INTUOS4L || features->type == INTUOS5L ||
features->type == INTUOSPL) &&
wacom->tool[idx] == BTN_TOOL_LENS) {
input_report_key(input, BTN_LEFT, data[8] & 0x01);
input_report_key(input, BTN_MIDDLE, data[8] & 0x02);
input_report_key(input, BTN_RIGHT, data[8] & 0x04);
input_report_key(input, BTN_SIDE, data[8] & 0x10);
input_report_key(input, BTN_EXTRA, data[8] & 0x08);
}
}
input_report_abs(input, ABS_MISC, wacom->id[idx]);
input_report_key(input, wacom->tool[idx], 1);
input_event(input, EV_MSC, MSC_SERIAL, wacom->serial[idx]);
wacom->reporting_data = true;
return 1;
}
static int int_dist(int x1, int y1, int x2, int y2)
{
int x = x2 - x1;
int y = y2 - y1;
return int_sqrt(x*x + y*y);
}
static void wacom_intuos_bt_process_data(struct wacom_wac *wacom,
unsigned char *data)
{
memcpy(wacom->data, data, 10);
wacom_intuos_irq(wacom);
input_sync(wacom->pen_input);
if (wacom->pad_input)
input_sync(wacom->pad_input);
}
static int wacom_intuos_bt_irq(struct wacom_wac *wacom, size_t len)
{
unsigned char data[WACOM_PKGLEN_MAX];
int i = 1;
unsigned power_raw, battery_capacity, bat_charging, ps_connected;
memcpy(data, wacom->data, len);
switch (data[0]) {
case 0x04:
wacom_intuos_bt_process_data(wacom, data + i);
i += 10;
case 0x03:
wacom_intuos_bt_process_data(wacom, data + i);
i += 10;
wacom_intuos_bt_process_data(wacom, data + i);
i += 10;
power_raw = data[i];
bat_charging = (power_raw & 0x08) ? 1 : 0;
ps_connected = (power_raw & 0x10) ? 1 : 0;
battery_capacity = batcap_i4[power_raw & 0x07];
wacom_notify_battery(wacom, battery_capacity, bat_charging,
battery_capacity || bat_charging,
ps_connected);
break;
default:
dev_dbg(wacom->pen_input->dev.parent,
"Unknown report: %d,%d size:%zu\n",
data[0], data[1], len);
return 0;
}
return 0;
}
static int wacom_wac_finger_count_touches(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->touch_input;
unsigned touch_max = wacom->features.touch_max;
int count = 0;
int i;
if (!touch_max)
return 0;
if (touch_max == 1)
return test_bit(BTN_TOUCH, input->key) &&
!wacom->shared->stylus_in_proximity;
for (i = 0; i < input->mt->num_slots; i++) {
struct input_mt_slot *ps = &input->mt->slots[i];
int id = input_mt_get_value(ps, ABS_MT_TRACKING_ID);
if (id >= 0)
count++;
}
return count;
}
static int wacom_24hdt_irq(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->touch_input;
unsigned char *data = wacom->data;
int i;
int current_num_contacts = data[61];
int contacts_to_send = 0;
int num_contacts_left = 4;
int byte_per_packet = WACOM_BYTES_PER_24HDT_PACKET;
int y_offset = 2;
if (wacom->features.type == WACOM_27QHDT) {
current_num_contacts = data[63];
num_contacts_left = 10;
byte_per_packet = WACOM_BYTES_PER_QHDTHID_PACKET;
y_offset = 0;
}
if (current_num_contacts)
wacom->num_contacts_left = current_num_contacts;
contacts_to_send = min(num_contacts_left, wacom->num_contacts_left);
for (i = 0; i < contacts_to_send; i++) {
int offset = (byte_per_packet * i) + 1;
bool touch = (data[offset] & 0x1) && !wacom->shared->stylus_in_proximity;
int slot = input_mt_get_slot_by_key(input, data[offset + 1]);
if (slot < 0)
continue;
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, touch);
if (touch) {
int t_x = get_unaligned_le16(&data[offset + 2]);
int t_y = get_unaligned_le16(&data[offset + 4 + y_offset]);
input_report_abs(input, ABS_MT_POSITION_X, t_x);
input_report_abs(input, ABS_MT_POSITION_Y, t_y);
if (wacom->features.type != WACOM_27QHDT) {
int c_x = get_unaligned_le16(&data[offset + 4]);
int c_y = get_unaligned_le16(&data[offset + 8]);
int w = get_unaligned_le16(&data[offset + 10]);
int h = get_unaligned_le16(&data[offset + 12]);
input_report_abs(input, ABS_MT_TOUCH_MAJOR, min(w,h));
input_report_abs(input, ABS_MT_WIDTH_MAJOR,
min(w, h) + int_dist(t_x, t_y, c_x, c_y));
input_report_abs(input, ABS_MT_WIDTH_MINOR, min(w, h));
input_report_abs(input, ABS_MT_ORIENTATION, w > h);
}
}
}
input_mt_sync_frame(input);
wacom->num_contacts_left -= contacts_to_send;
if (wacom->num_contacts_left <= 0) {
wacom->num_contacts_left = 0;
wacom->shared->touch_down = wacom_wac_finger_count_touches(wacom);
}
return 1;
}
static int wacom_mt_touch(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->touch_input;
unsigned char *data = wacom->data;
int i;
int current_num_contacts = data[2];
int contacts_to_send = 0;
int x_offset = 0;
if (wacom->features.type == MTTPC || wacom->features.type == MTTPC_B)
x_offset = -4;
if (current_num_contacts)
wacom->num_contacts_left = current_num_contacts;
contacts_to_send = min(5, wacom->num_contacts_left);
for (i = 0; i < contacts_to_send; i++) {
int offset = (WACOM_BYTES_PER_MT_PACKET + x_offset) * i + 3;
bool touch = (data[offset] & 0x1) && !wacom->shared->stylus_in_proximity;
int id = get_unaligned_le16(&data[offset + 1]);
int slot = input_mt_get_slot_by_key(input, id);
if (slot < 0)
continue;
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, touch);
if (touch) {
int x = get_unaligned_le16(&data[offset + x_offset + 7]);
int y = get_unaligned_le16(&data[offset + x_offset + 9]);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
}
input_mt_sync_frame(input);
wacom->num_contacts_left -= contacts_to_send;
if (wacom->num_contacts_left <= 0) {
wacom->num_contacts_left = 0;
wacom->shared->touch_down = wacom_wac_finger_count_touches(wacom);
}
return 1;
}
static int wacom_tpc_mt_touch(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->touch_input;
unsigned char *data = wacom->data;
int i;
for (i = 0; i < 2; i++) {
int p = data[1] & (1 << i);
bool touch = p && !wacom->shared->stylus_in_proximity;
input_mt_slot(input, i);
input_mt_report_slot_state(input, MT_TOOL_FINGER, touch);
if (touch) {
int x = le16_to_cpup((__le16 *)&data[i * 2 + 2]) & 0x7fff;
int y = le16_to_cpup((__le16 *)&data[i * 2 + 6]) & 0x7fff;
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
}
input_mt_sync_frame(input);
wacom->shared->touch_down = wacom_wac_finger_count_touches(wacom);
return 1;
}
static int wacom_tpc_single_touch(struct wacom_wac *wacom, size_t len)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->touch_input;
bool prox = !wacom->shared->stylus_in_proximity;
int x = 0, y = 0;
if (wacom->features.touch_max > 1 || len > WACOM_PKGLEN_TPC2FG)
return 0;
if (len == WACOM_PKGLEN_TPC1FG) {
prox = prox && (data[0] & 0x01);
x = get_unaligned_le16(&data[1]);
y = get_unaligned_le16(&data[3]);
} else if (len == WACOM_PKGLEN_TPC1FG_B) {
prox = prox && (data[2] & 0x01);
x = get_unaligned_le16(&data[3]);
y = get_unaligned_le16(&data[5]);
} else {
prox = prox && (data[1] & 0x01);
x = le16_to_cpup((__le16 *)&data[2]);
y = le16_to_cpup((__le16 *)&data[4]);
}
if (prox) {
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
}
input_report_key(input, BTN_TOUCH, prox);
wacom->shared->touch_down = prox;
return 1;
}
static int wacom_tpc_pen(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->pen_input;
bool prox = data[1] & 0x20;
if (!wacom->shared->stylus_in_proximity)
wacom->tool[0] = (data[1] & 0x0c) ? BTN_TOOL_RUBBER : BTN_TOOL_PEN;
wacom->shared->stylus_in_proximity = prox;
if (!wacom->shared->touch_down) {
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, data[1] & 0x10);
input_report_abs(input, ABS_X, le16_to_cpup((__le16 *)&data[2]));
input_report_abs(input, ABS_Y, le16_to_cpup((__le16 *)&data[4]));
input_report_abs(input, ABS_PRESSURE, ((data[7] & 0x07) << 8) | data[6]);
input_report_key(input, BTN_TOUCH, data[1] & 0x05);
input_report_key(input, wacom->tool[0], prox);
return 1;
}
return 0;
}
static int wacom_tpc_irq(struct wacom_wac *wacom, size_t len)
{
unsigned char *data = wacom->data;
if (wacom->pen_input)
dev_dbg(wacom->pen_input->dev.parent,
"%s: received report #%d\n", __func__, data[0]);
else if (wacom->touch_input)
dev_dbg(wacom->touch_input->dev.parent,
"%s: received report #%d\n", __func__, data[0]);
switch (len) {
case WACOM_PKGLEN_TPC1FG:
return wacom_tpc_single_touch(wacom, len);
case WACOM_PKGLEN_TPC2FG:
return wacom_tpc_mt_touch(wacom);
case WACOM_PKGLEN_PENABLED:
return wacom_tpc_pen(wacom);
default:
switch (data[0]) {
case WACOM_REPORT_TPC1FG:
case WACOM_REPORT_TPCHID:
case WACOM_REPORT_TPCST:
case WACOM_REPORT_TPC1FGE:
return wacom_tpc_single_touch(wacom, len);
case WACOM_REPORT_TPCMT:
case WACOM_REPORT_TPCMT2:
return wacom_mt_touch(wacom);
case WACOM_REPORT_PENABLED:
return wacom_tpc_pen(wacom);
}
}
return 0;
}
static void wacom_map_usage(struct input_dev *input, struct hid_usage *usage,
struct hid_field *field, __u8 type, __u16 code, int fuzz)
{
int fmin = field->logical_minimum;
int fmax = field->logical_maximum;
usage->type = type;
usage->code = code;
set_bit(type, input->evbit);
switch (type) {
case EV_ABS:
input_set_abs_params(input, code, fmin, fmax, fuzz, 0);
input_abs_set_res(input, code,
hidinput_calc_abs_res(field, code));
break;
case EV_KEY:
input_set_capability(input, EV_KEY, code);
break;
case EV_MSC:
input_set_capability(input, EV_MSC, code);
break;
}
}
static void wacom_wac_pen_usage_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct input_dev *input = wacom_wac->pen_input;
switch (usage->hid) {
case HID_GD_X:
wacom_map_usage(input, usage, field, EV_ABS, ABS_X, 4);
break;
case HID_GD_Y:
wacom_map_usage(input, usage, field, EV_ABS, ABS_Y, 4);
break;
case HID_DG_TIPPRESSURE:
wacom_map_usage(input, usage, field, EV_ABS, ABS_PRESSURE, 0);
break;
case HID_DG_INRANGE:
wacom_map_usage(input, usage, field, EV_KEY, BTN_TOOL_PEN, 0);
break;
case HID_DG_INVERT:
wacom_map_usage(input, usage, field, EV_KEY,
BTN_TOOL_RUBBER, 0);
break;
case HID_DG_ERASER:
case HID_DG_TIPSWITCH:
wacom_map_usage(input, usage, field, EV_KEY, BTN_TOUCH, 0);
break;
case HID_DG_BARRELSWITCH:
wacom_map_usage(input, usage, field, EV_KEY, BTN_STYLUS, 0);
break;
case HID_DG_BARRELSWITCH2:
wacom_map_usage(input, usage, field, EV_KEY, BTN_STYLUS2, 0);
break;
case HID_DG_TOOLSERIALNUMBER:
wacom_map_usage(input, usage, field, EV_MSC, MSC_SERIAL, 0);
break;
}
}
static int wacom_wac_pen_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct input_dev *input = wacom_wac->pen_input;
switch (usage->hid) {
case HID_DG_INRANGE:
wacom_wac->hid_data.inrange_state = value;
return 0;
case HID_DG_INVERT:
wacom_wac->hid_data.invert_state = value;
return 0;
case HID_DG_ERASER:
case HID_DG_TIPSWITCH:
wacom_wac->hid_data.tipswitch |= value;
return 0;
}
if (!usage->type || wacom_wac->shared->touch_down)
return 0;
input_event(input, usage->type, usage->code, value);
return 0;
}
static void wacom_wac_pen_pre_report(struct hid_device *hdev,
struct hid_report *report)
{
return;
}
static void wacom_wac_pen_report(struct hid_device *hdev,
struct hid_report *report)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct input_dev *input = wacom_wac->pen_input;
bool prox = wacom_wac->hid_data.inrange_state;
if (!wacom_wac->shared->stylus_in_proximity)
wacom_wac->tool[0] = wacom_wac->hid_data.invert_state ?
BTN_TOOL_RUBBER : BTN_TOOL_PEN;
wacom_wac->shared->stylus_in_proximity = prox;
if (!wacom_wac->shared->touch_down) {
input_report_key(input, BTN_TOUCH,
wacom_wac->hid_data.tipswitch);
input_report_key(input, wacom_wac->tool[0], prox);
wacom_wac->hid_data.tipswitch = false;
input_sync(input);
}
}
static void wacom_wac_finger_usage_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct wacom_features *features = &wacom_wac->features;
struct input_dev *input = wacom_wac->touch_input;
unsigned touch_max = wacom_wac->features.touch_max;
switch (usage->hid) {
case HID_GD_X:
features->last_slot_field = usage->hid;
if (touch_max == 1)
wacom_map_usage(input, usage, field, EV_ABS, ABS_X, 4);
else
wacom_map_usage(input, usage, field, EV_ABS,
ABS_MT_POSITION_X, 4);
break;
case HID_GD_Y:
features->last_slot_field = usage->hid;
if (touch_max == 1)
wacom_map_usage(input, usage, field, EV_ABS, ABS_Y, 4);
else
wacom_map_usage(input, usage, field, EV_ABS,
ABS_MT_POSITION_Y, 4);
break;
case HID_DG_WIDTH:
case HID_DG_HEIGHT:
features->last_slot_field = usage->hid;
wacom_map_usage(input, usage, field, EV_ABS, ABS_MT_TOUCH_MAJOR, 0);
wacom_map_usage(input, usage, field, EV_ABS, ABS_MT_TOUCH_MINOR, 0);
input_set_abs_params(input, ABS_MT_ORIENTATION, 0, 1, 0, 0);
break;
case HID_DG_CONTACTID:
features->last_slot_field = usage->hid;
break;
case HID_DG_INRANGE:
features->last_slot_field = usage->hid;
break;
case HID_DG_INVERT:
features->last_slot_field = usage->hid;
break;
case HID_DG_TIPSWITCH:
features->last_slot_field = usage->hid;
wacom_map_usage(input, usage, field, EV_KEY, BTN_TOUCH, 0);
break;
case HID_DG_CONTACTCOUNT:
wacom_wac->hid_data.cc_index = field->index;
wacom_wac->hid_data.cc_value_index = usage->usage_index;
break;
}
}
static void wacom_wac_finger_slot(struct wacom_wac *wacom_wac,
struct input_dev *input)
{
struct hid_data *hid_data = &wacom_wac->hid_data;
bool mt = wacom_wac->features.touch_max > 1;
bool prox = hid_data->tipswitch &&
!wacom_wac->shared->stylus_in_proximity;
wacom_wac->hid_data.num_received++;
if (wacom_wac->hid_data.num_received > wacom_wac->hid_data.num_expected)
return;
if (mt) {
int slot;
slot = input_mt_get_slot_by_key(input, hid_data->id);
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, prox);
}
else {
input_report_key(input, BTN_TOUCH, prox);
}
if (prox) {
input_report_abs(input, mt ? ABS_MT_POSITION_X : ABS_X,
hid_data->x);
input_report_abs(input, mt ? ABS_MT_POSITION_Y : ABS_Y,
hid_data->y);
if (test_bit(ABS_MT_TOUCH_MAJOR, input->absbit)) {
input_report_abs(input, ABS_MT_TOUCH_MAJOR, max(hid_data->width, hid_data->height));
input_report_abs(input, ABS_MT_TOUCH_MINOR, min(hid_data->width, hid_data->height));
if (hid_data->width != hid_data->height)
input_report_abs(input, ABS_MT_ORIENTATION, hid_data->width <= hid_data->height ? 0 : 1);
}
}
}
static int wacom_wac_finger_event(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage, __s32 value)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
switch (usage->hid) {
case HID_GD_X:
wacom_wac->hid_data.x = value;
break;
case HID_GD_Y:
wacom_wac->hid_data.y = value;
break;
case HID_DG_WIDTH:
wacom_wac->hid_data.width = value;
break;
case HID_DG_HEIGHT:
wacom_wac->hid_data.height = value;
break;
case HID_DG_CONTACTID:
wacom_wac->hid_data.id = value;
break;
case HID_DG_TIPSWITCH:
wacom_wac->hid_data.tipswitch = value;
break;
}
if (usage->usage_index + 1 == field->report_count) {
if (usage->hid == wacom_wac->features.last_slot_field)
wacom_wac_finger_slot(wacom_wac, wacom_wac->touch_input);
}
return 0;
}
static void wacom_wac_finger_pre_report(struct hid_device *hdev,
struct hid_report *report)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct hid_data* hid_data = &wacom_wac->hid_data;
if (hid_data->cc_index >= 0) {
struct hid_field *field = report->field[hid_data->cc_index];
int value = field->value[hid_data->cc_value_index];
if (value)
hid_data->num_expected = value;
}
else {
hid_data->num_expected = wacom_wac->features.touch_max;
}
}
static void wacom_wac_finger_report(struct hid_device *hdev,
struct hid_report *report)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct input_dev *input = wacom_wac->touch_input;
unsigned touch_max = wacom_wac->features.touch_max;
if (wacom_wac->hid_data.num_received < wacom_wac->hid_data.num_expected)
return;
if (touch_max > 1)
input_mt_sync_frame(input);
input_sync(input);
wacom_wac->hid_data.num_received = 0;
wacom_wac->shared->touch_down = wacom_wac_finger_count_touches(wacom_wac);
}
void wacom_wac_usage_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
__set_bit(INPUT_PROP_DIRECT, wacom_wac->pen_input->propbit);
__set_bit(INPUT_PROP_DIRECT, wacom_wac->touch_input->propbit);
if (WACOM_PEN_FIELD(field))
return wacom_wac_pen_usage_mapping(hdev, field, usage);
if (WACOM_FINGER_FIELD(field))
return wacom_wac_finger_usage_mapping(hdev, field, usage);
}
int wacom_wac_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct wacom *wacom = hid_get_drvdata(hdev);
if (wacom->wacom_wac.features.type != HID_GENERIC)
return 0;
if (WACOM_PEN_FIELD(field))
return wacom_wac_pen_event(hdev, field, usage, value);
if (WACOM_FINGER_FIELD(field))
return wacom_wac_finger_event(hdev, field, usage, value);
return 0;
}
static void wacom_report_events(struct hid_device *hdev, struct hid_report *report)
{
int r;
for (r = 0; r < report->maxfield; r++) {
struct hid_field *field;
unsigned count, n;
field = report->field[r];
count = field->report_count;
if (!(HID_MAIN_ITEM_VARIABLE & field->flags))
continue;
for (n = 0; n < count; n++)
wacom_wac_event(hdev, field, &field->usage[n], field->value[n]);
}
}
void wacom_wac_report(struct hid_device *hdev, struct hid_report *report)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct hid_field *field = report->field[0];
if (wacom_wac->features.type != HID_GENERIC)
return;
if (WACOM_PEN_FIELD(field))
wacom_wac_pen_pre_report(hdev, report);
if (WACOM_FINGER_FIELD(field))
wacom_wac_finger_pre_report(hdev, report);
wacom_report_events(hdev, report);
if (WACOM_PEN_FIELD(field))
return wacom_wac_pen_report(hdev, report);
if (WACOM_FINGER_FIELD(field))
return wacom_wac_finger_report(hdev, report);
}
static int wacom_bpt_touch(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
struct input_dev *input = wacom->touch_input;
struct input_dev *pad_input = wacom->pad_input;
unsigned char *data = wacom->data;
int i;
if (data[0] != 0x02)
return 0;
for (i = 0; i < 2; i++) {
int offset = (data[1] & 0x80) ? (8 * i) : (9 * i);
bool touch = data[offset + 3] & 0x80;
touch = touch && !wacom->shared->stylus_in_proximity;
input_mt_slot(input, i);
input_mt_report_slot_state(input, MT_TOOL_FINGER, touch);
if (touch) {
int x = get_unaligned_be16(&data[offset + 3]) & 0x7ff;
int y = get_unaligned_be16(&data[offset + 5]) & 0x7ff;
if (features->quirks & WACOM_QUIRK_BBTOUCH_LOWRES) {
x <<= 5;
y <<= 5;
}
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
}
input_mt_sync_frame(input);
input_report_key(pad_input, BTN_LEFT, (data[1] & 0x08) != 0);
input_report_key(pad_input, BTN_FORWARD, (data[1] & 0x04) != 0);
input_report_key(pad_input, BTN_BACK, (data[1] & 0x02) != 0);
input_report_key(pad_input, BTN_RIGHT, (data[1] & 0x01) != 0);
wacom->shared->touch_down = wacom_wac_finger_count_touches(wacom);
return 1;
}
static void wacom_bpt3_touch_msg(struct wacom_wac *wacom, unsigned char *data)
{
struct wacom_features *features = &wacom->features;
struct input_dev *input = wacom->touch_input;
bool touch = data[1] & 0x80;
int slot = input_mt_get_slot_by_key(input, data[0]);
if (slot < 0)
return;
touch = touch && !wacom->shared->stylus_in_proximity;
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, touch);
if (touch) {
int x = (data[2] << 4) | (data[4] >> 4);
int y = (data[3] << 4) | (data[4] & 0x0f);
int width, height;
if (features->type >= INTUOSPS && features->type <= INTUOSHT) {
width = data[5] * 100;
height = data[6] * 100;
} else {
int a = data[5];
int x_res = input_abs_get_res(input, ABS_MT_POSITION_X);
int y_res = input_abs_get_res(input, ABS_MT_POSITION_Y);
width = 2 * int_sqrt(a * WACOM_CONTACT_AREA_SCALE);
height = width * y_res / x_res;
}
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
input_report_abs(input, ABS_MT_TOUCH_MAJOR, width);
input_report_abs(input, ABS_MT_TOUCH_MINOR, height);
}
}
static void wacom_bpt3_button_msg(struct wacom_wac *wacom, unsigned char *data)
{
struct input_dev *input = wacom->pad_input;
struct wacom_features *features = &wacom->features;
if (features->type == INTUOSHT) {
input_report_key(input, BTN_LEFT, (data[1] & 0x02) != 0);
input_report_key(input, BTN_BACK, (data[1] & 0x08) != 0);
} else {
input_report_key(input, BTN_BACK, (data[1] & 0x02) != 0);
input_report_key(input, BTN_LEFT, (data[1] & 0x08) != 0);
}
input_report_key(input, BTN_FORWARD, (data[1] & 0x04) != 0);
input_report_key(input, BTN_RIGHT, (data[1] & 0x01) != 0);
}
static int wacom_bpt3_touch(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
int count = data[1] & 0x07;
int i;
if (data[0] != 0x02)
return 0;
for (i = 0; i < count; i++) {
int offset = (8 * i) + 2;
int msg_id = data[offset];
if (msg_id >= 2 && msg_id <= 17)
wacom_bpt3_touch_msg(wacom, data + offset);
else if (msg_id == 128)
wacom_bpt3_button_msg(wacom, data + offset);
}
if (wacom->touch_registered) {
input_mt_sync_frame(wacom->touch_input);
wacom->shared->touch_down = wacom_wac_finger_count_touches(wacom);
}
return 1;
}
static int wacom_bpt_pen(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
struct input_dev *input = wacom->pen_input;
unsigned char *data = wacom->data;
int prox = 0, x = 0, y = 0, p = 0, d = 0, pen = 0, btn1 = 0, btn2 = 0;
if (data[0] != WACOM_REPORT_PENABLED)
return 0;
prox = (data[1] & 0x20) == 0x20;
if (!wacom->shared->stylus_in_proximity) {
if (data[1] & 0x08) {
wacom->tool[0] = BTN_TOOL_RUBBER;
wacom->id[0] = ERASER_DEVICE_ID;
} else {
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
}
}
wacom->shared->stylus_in_proximity = prox;
if (wacom->shared->touch_down)
return 0;
if (prox) {
x = le16_to_cpup((__le16 *)&data[2]);
y = le16_to_cpup((__le16 *)&data[4]);
p = le16_to_cpup((__le16 *)&data[6]);
if (data[8] <= features->distance_max)
d = features->distance_max - data[8];
pen = data[1] & 0x01;
btn1 = data[1] & 0x02;
btn2 = data[1] & 0x04;
} else {
wacom->id[0] = 0;
}
input_report_key(input, BTN_TOUCH, pen);
input_report_key(input, BTN_STYLUS, btn1);
input_report_key(input, BTN_STYLUS2, btn2);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
input_report_abs(input, ABS_PRESSURE, p);
input_report_abs(input, ABS_DISTANCE, d);
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
static int wacom_bpt_irq(struct wacom_wac *wacom, size_t len)
{
if (len == WACOM_PKGLEN_BBTOUCH)
return wacom_bpt_touch(wacom);
else if (len == WACOM_PKGLEN_BBTOUCH3)
return wacom_bpt3_touch(wacom);
else if (len == WACOM_PKGLEN_BBFUN || len == WACOM_PKGLEN_BBPEN)
return wacom_bpt_pen(wacom);
return 0;
}
static void wacom_bamboo_pad_pen_event(struct wacom_wac *wacom,
unsigned char *data)
{
unsigned char prefix;
prefix = data[0];
data[0] = WACOM_REPORT_BPAD_PEN;
hid_input_report(wacom->shared->pen, HID_INPUT_REPORT, data,
WACOM_PKGLEN_PENABLED, 1);
data[0] = prefix;
}
static int wacom_bamboo_pad_touch_event(struct wacom_wac *wacom,
unsigned char *data)
{
struct input_dev *input = wacom->touch_input;
unsigned char *finger_data, prefix;
unsigned id;
int x, y;
bool valid;
prefix = data[0];
for (id = 0; id < wacom->features.touch_max; id++) {
valid = !!(prefix & BIT(id)) &&
!wacom->shared->stylus_in_proximity;
input_mt_slot(input, id);
input_mt_report_slot_state(input, MT_TOOL_FINGER, valid);
if (!valid)
continue;
finger_data = data + 1 + id * 3;
x = finger_data[0] | ((finger_data[1] & 0x0f) << 8);
y = (finger_data[2] << 4) | (finger_data[1] >> 4);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
input_mt_sync_frame(input);
input_report_key(input, BTN_LEFT, prefix & 0x40);
input_report_key(input, BTN_RIGHT, prefix & 0x80);
wacom->shared->touch_down = !!prefix &&
!wacom->shared->stylus_in_proximity;
return 1;
}
static int wacom_bamboo_pad_irq(struct wacom_wac *wacom, size_t len)
{
unsigned char *data = wacom->data;
if (!((len == WACOM_PKGLEN_BPAD_TOUCH) ||
(len == WACOM_PKGLEN_BPAD_TOUCH_USB)) ||
(data[0] != WACOM_REPORT_BPAD_TOUCH))
return 0;
if (data[1] & 0x01)
wacom_bamboo_pad_pen_event(wacom, &data[1]);
if (data[1] & 0x02)
return wacom_bamboo_pad_touch_event(wacom, &data[9]);
return 0;
}
static int wacom_wireless_irq(struct wacom_wac *wacom, size_t len)
{
unsigned char *data = wacom->data;
int connected;
if (len != WACOM_PKGLEN_WIRELESS || data[0] != WACOM_REPORT_WL)
return 0;
connected = data[1] & 0x01;
if (connected) {
int pid, battery, charging;
if ((wacom->shared->type == INTUOSHT) &&
wacom->shared->touch_input &&
wacom->shared->touch_max) {
input_report_switch(wacom->shared->touch_input,
SW_MUTE_DEVICE, data[5] & 0x40);
input_sync(wacom->shared->touch_input);
}
pid = get_unaligned_be16(&data[6]);
battery = (data[5] & 0x3f) * 100 / 31;
charging = !!(data[5] & 0x80);
if (wacom->pid != pid) {
wacom->pid = pid;
wacom_schedule_work(wacom);
}
if (wacom->shared->type)
wacom_notify_battery(wacom, battery, charging, 1, 0);
} else if (wacom->pid != 0) {
wacom->pid = 0;
wacom_schedule_work(wacom);
wacom_notify_battery(wacom, 0, 0, 0, 0);
}
return 0;
}
static int wacom_status_irq(struct wacom_wac *wacom_wac, size_t len)
{
struct wacom *wacom = container_of(wacom_wac, struct wacom, wacom_wac);
struct wacom_features *features = &wacom_wac->features;
unsigned char *data = wacom_wac->data;
if (data[0] != WACOM_REPORT_USB)
return 0;
if (features->type == INTUOSHT &&
wacom_wac->shared->touch_input &&
features->touch_max) {
input_report_switch(wacom_wac->shared->touch_input,
SW_MUTE_DEVICE, data[8] & 0x40);
input_sync(wacom_wac->shared->touch_input);
}
if (data[9] & 0x02) {
int battery = (data[8] & 0x3f) * 100 / 31;
bool charging = !!(data[8] & 0x80);
wacom_notify_battery(wacom_wac, battery, charging,
battery || charging, 1);
if (!wacom->battery &&
!(features->quirks & WACOM_QUIRK_BATTERY)) {
features->quirks |= WACOM_QUIRK_BATTERY;
INIT_WORK(&wacom->work, wacom_battery_work);
wacom_schedule_work(wacom_wac);
}
}
else if ((features->quirks & WACOM_QUIRK_BATTERY) &&
wacom->battery) {
features->quirks &= ~WACOM_QUIRK_BATTERY;
INIT_WORK(&wacom->work, wacom_battery_work);
wacom_schedule_work(wacom_wac);
wacom_notify_battery(wacom_wac, 0, 0, 0, 0);
}
return 0;
}
void wacom_wac_irq(struct wacom_wac *wacom_wac, size_t len)
{
bool sync;
switch (wacom_wac->features.type) {
case PENPARTNER:
sync = wacom_penpartner_irq(wacom_wac);
break;
case PL:
sync = wacom_pl_irq(wacom_wac);
break;
case WACOM_G4:
case GRAPHIRE:
case GRAPHIRE_BT:
case WACOM_MO:
sync = wacom_graphire_irq(wacom_wac);
break;
case PTU:
sync = wacom_ptu_irq(wacom_wac);
break;
case DTU:
sync = wacom_dtu_irq(wacom_wac);
break;
case DTUS:
case DTUSX:
sync = wacom_dtus_irq(wacom_wac);
break;
case INTUOS:
case INTUOS3S:
case INTUOS3:
case INTUOS3L:
case INTUOS4S:
case INTUOS4:
case INTUOS4L:
case CINTIQ:
case WACOM_BEE:
case WACOM_13HD:
case WACOM_21UX2:
case WACOM_22HD:
case WACOM_24HD:
case WACOM_27QHD:
case DTK:
case CINTIQ_HYBRID:
sync = wacom_intuos_irq(wacom_wac);
break;
case INTUOS4WL:
sync = wacom_intuos_bt_irq(wacom_wac, len);
break;
case WACOM_24HDT:
case WACOM_27QHDT:
sync = wacom_24hdt_irq(wacom_wac);
break;
case INTUOS5S:
case INTUOS5:
case INTUOS5L:
case INTUOSPS:
case INTUOSPM:
case INTUOSPL:
if (len == WACOM_PKGLEN_BBTOUCH3)
sync = wacom_bpt3_touch(wacom_wac);
else if (wacom_wac->data[0] == WACOM_REPORT_USB)
sync = wacom_status_irq(wacom_wac, len);
else
sync = wacom_intuos_irq(wacom_wac);
break;
case TABLETPC:
case TABLETPCE:
case TABLETPC2FG:
case MTSCREEN:
case MTTPC:
case MTTPC_B:
sync = wacom_tpc_irq(wacom_wac, len);
break;
case BAMBOO_PT:
case INTUOSHT:
if (wacom_wac->data[0] == WACOM_REPORT_USB)
sync = wacom_status_irq(wacom_wac, len);
else
sync = wacom_bpt_irq(wacom_wac, len);
break;
case BAMBOO_PAD:
sync = wacom_bamboo_pad_irq(wacom_wac, len);
break;
case WIRELESS:
sync = wacom_wireless_irq(wacom_wac, len);
break;
case REMOTE:
if (wacom_wac->data[0] == WACOM_REPORT_DEVICE_LIST)
sync = wacom_remote_status_irq(wacom_wac, len);
else
sync = wacom_remote_irq(wacom_wac, len);
break;
default:
sync = false;
break;
}
if (sync) {
if (wacom_wac->pen_input)
input_sync(wacom_wac->pen_input);
if (wacom_wac->touch_input)
input_sync(wacom_wac->touch_input);
if (wacom_wac->pad_input)
input_sync(wacom_wac->pad_input);
}
}
static void wacom_setup_cintiq(struct wacom_wac *wacom_wac)
{
struct input_dev *input_dev = wacom_wac->pen_input;
input_set_capability(input_dev, EV_MSC, MSC_SERIAL);
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_TOOL_BRUSH, input_dev->keybit);
__set_bit(BTN_TOOL_PENCIL, input_dev->keybit);
__set_bit(BTN_TOOL_AIRBRUSH, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(BTN_STYLUS2, input_dev->keybit);
input_set_abs_params(input_dev, ABS_DISTANCE,
0, wacom_wac->features.distance_max, 0, 0);
input_set_abs_params(input_dev, ABS_WHEEL, 0, 1023, 0, 0);
input_set_abs_params(input_dev, ABS_TILT_X, -64, 63, 0, 0);
input_abs_set_res(input_dev, ABS_TILT_X, 57);
input_set_abs_params(input_dev, ABS_TILT_Y, -64, 63, 0, 0);
input_abs_set_res(input_dev, ABS_TILT_Y, 57);
}
static void wacom_setup_intuos(struct wacom_wac *wacom_wac)
{
struct input_dev *input_dev = wacom_wac->pen_input;
input_set_capability(input_dev, EV_REL, REL_WHEEL);
wacom_setup_cintiq(wacom_wac);
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
__set_bit(BTN_MIDDLE, input_dev->keybit);
__set_bit(BTN_SIDE, input_dev->keybit);
__set_bit(BTN_EXTRA, input_dev->keybit);
__set_bit(BTN_TOOL_MOUSE, input_dev->keybit);
__set_bit(BTN_TOOL_LENS, input_dev->keybit);
input_set_abs_params(input_dev, ABS_RZ, -900, 899, 0, 0);
input_abs_set_res(input_dev, ABS_RZ, 287);
input_set_abs_params(input_dev, ABS_THROTTLE, -1023, 1023, 0, 0);
}
void wacom_setup_device_quirks(struct wacom *wacom)
{
struct wacom_features *features = &wacom->wacom_wac.features;
if (features->type == GRAPHIRE_BT || features->type == WACOM_G4 ||
features->type == DTUS || features->type == WACOM_MO ||
(features->type >= INTUOS3S && features->type <= WACOM_13HD &&
features->type != INTUOSHT)) {
if (features->device_type & WACOM_DEVICETYPE_PEN)
features->device_type |= WACOM_DEVICETYPE_PAD;
}
if (features->device_type & WACOM_DEVICETYPE_TOUCH && !features->x_max) {
features->x_max = 1023;
features->y_max = 1023;
}
if ((features->type >= INTUOS5S && features->type <= INTUOSHT) ||
(features->type == BAMBOO_PT)) {
if (features->pktlen == WACOM_PKGLEN_BBTOUCH3) {
if (features->touch_max)
features->device_type |= WACOM_DEVICETYPE_TOUCH;
if (features->type == BAMBOO_PT || features->type == INTUOSHT)
features->device_type |= WACOM_DEVICETYPE_PAD;
features->x_max = 4096;
features->y_max = 4096;
}
else if (features->pktlen == WACOM_PKGLEN_BBTOUCH) {
features->device_type |= WACOM_DEVICETYPE_PAD;
}
}
if (features->type == BAMBOO_PAD)
features->device_type = WACOM_DEVICETYPE_TOUCH;
if (features->type == REMOTE)
features->device_type = WACOM_DEVICETYPE_PAD;
if (wacom->hdev->bus == BUS_BLUETOOTH)
features->quirks |= WACOM_QUIRK_BATTERY;
if (features->type == BAMBOO_PT &&
features->pktlen == WACOM_PKGLEN_BBTOUCH) {
features->x_max <<= 5;
features->y_max <<= 5;
features->x_fuzz <<= 5;
features->y_fuzz <<= 5;
features->quirks |= WACOM_QUIRK_BBTOUCH_LOWRES;
}
if (features->type == WIRELESS) {
if (features->device_type == WACOM_DEVICETYPE_WL_MONITOR) {
features->quirks |= WACOM_QUIRK_BATTERY;
}
}
}
int wacom_setup_pen_input_capabilities(struct input_dev *input_dev,
struct wacom_wac *wacom_wac)
{
struct wacom_features *features = &wacom_wac->features;
input_dev->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
if (!(features->device_type & WACOM_DEVICETYPE_PEN))
return -ENODEV;
if (features->type == HID_GENERIC)
return 0;
__set_bit(BTN_TOUCH, input_dev->keybit);
__set_bit(ABS_MISC, input_dev->absbit);
input_set_abs_params(input_dev, ABS_X, features->x_min,
features->x_max, features->x_fuzz, 0);
input_set_abs_params(input_dev, ABS_Y, features->y_min,
features->y_max, features->y_fuzz, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0,
features->pressure_max, features->pressure_fuzz, 0);
input_abs_set_res(input_dev, ABS_X, features->x_resolution);
input_abs_set_res(input_dev, ABS_Y, features->y_resolution);
switch (features->type) {
case GRAPHIRE_BT:
__clear_bit(ABS_MISC, input_dev->absbit);
case WACOM_MO:
case WACOM_G4:
input_set_abs_params(input_dev, ABS_DISTANCE, 0,
features->distance_max,
0, 0);
case GRAPHIRE:
input_set_capability(input_dev, EV_REL, REL_WHEEL);
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
__set_bit(BTN_MIDDLE, input_dev->keybit);
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_TOOL_MOUSE, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(BTN_STYLUS2, input_dev->keybit);
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
break;
case WACOM_27QHD:
case WACOM_24HD:
case DTK:
case WACOM_22HD:
case WACOM_21UX2:
case WACOM_BEE:
case CINTIQ:
case WACOM_13HD:
case CINTIQ_HYBRID:
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
input_abs_set_res(input_dev, ABS_Z, 287);
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
wacom_setup_cintiq(wacom_wac);
break;
case INTUOS3:
case INTUOS3L:
case INTUOS3S:
case INTUOS4:
case INTUOS4WL:
case INTUOS4L:
case INTUOS4S:
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
input_abs_set_res(input_dev, ABS_Z, 287);
case INTUOS:
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
wacom_setup_intuos(wacom_wac);
break;
case INTUOS5:
case INTUOS5L:
case INTUOSPM:
case INTUOSPL:
case INTUOS5S:
case INTUOSPS:
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
input_set_abs_params(input_dev, ABS_DISTANCE, 0,
features->distance_max,
0, 0);
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
input_abs_set_res(input_dev, ABS_Z, 287);
wacom_setup_intuos(wacom_wac);
break;
case WACOM_24HDT:
case WACOM_27QHDT:
case MTSCREEN:
case MTTPC:
case MTTPC_B:
case TABLETPC2FG:
case TABLETPC:
case TABLETPCE:
__clear_bit(ABS_MISC, input_dev->absbit);
case DTUS:
case DTUSX:
case PL:
case DTU:
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(BTN_STYLUS2, input_dev->keybit);
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
break;
case PTU:
__set_bit(BTN_STYLUS2, input_dev->keybit);
case PENPARTNER:
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
break;
case INTUOSHT:
case BAMBOO_PT:
__clear_bit(ABS_MISC, input_dev->absbit);
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(BTN_STYLUS2, input_dev->keybit);
input_set_abs_params(input_dev, ABS_DISTANCE, 0,
features->distance_max,
0, 0);
break;
case BAMBOO_PAD:
__clear_bit(ABS_MISC, input_dev->absbit);
break;
}
return 0;
}
int wacom_setup_touch_input_capabilities(struct input_dev *input_dev,
struct wacom_wac *wacom_wac)
{
struct wacom_features *features = &wacom_wac->features;
input_dev->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
if (!(features->device_type & WACOM_DEVICETYPE_TOUCH))
return -ENODEV;
if (features->type == HID_GENERIC)
return 0;
__set_bit(BTN_TOUCH, input_dev->keybit);
if (features->touch_max == 1) {
input_set_abs_params(input_dev, ABS_X, 0,
features->x_max, features->x_fuzz, 0);
input_set_abs_params(input_dev, ABS_Y, 0,
features->y_max, features->y_fuzz, 0);
input_abs_set_res(input_dev, ABS_X,
features->x_resolution);
input_abs_set_res(input_dev, ABS_Y,
features->y_resolution);
}
else if (features->touch_max > 1) {
input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0,
features->x_max, features->x_fuzz, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0,
features->y_max, features->y_fuzz, 0);
input_abs_set_res(input_dev, ABS_MT_POSITION_X,
features->x_resolution);
input_abs_set_res(input_dev, ABS_MT_POSITION_Y,
features->y_resolution);
}
switch (features->type) {
case INTUOS5:
case INTUOS5L:
case INTUOSPM:
case INTUOSPL:
case INTUOS5S:
case INTUOSPS:
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR, 0, features->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR, 0, features->y_max, 0, 0);
input_mt_init_slots(input_dev, features->touch_max, INPUT_MT_POINTER);
break;
case WACOM_24HDT:
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR, 0, features->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_WIDTH_MAJOR, 0, features->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_WIDTH_MINOR, 0, features->y_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_ORIENTATION, 0, 1, 0, 0);
case WACOM_27QHDT:
case MTSCREEN:
case MTTPC:
case MTTPC_B:
case TABLETPC2FG:
input_mt_init_slots(input_dev, features->touch_max, INPUT_MT_DIRECT);
case TABLETPC:
case TABLETPCE:
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
break;
case INTUOSHT:
input_dev->evbit[0] |= BIT_MASK(EV_SW);
__set_bit(SW_MUTE_DEVICE, input_dev->swbit);
case BAMBOO_PT:
if (features->pktlen == WACOM_PKGLEN_BBTOUCH3) {
input_set_abs_params(input_dev,
ABS_MT_TOUCH_MAJOR,
0, features->x_max, 0, 0);
input_set_abs_params(input_dev,
ABS_MT_TOUCH_MINOR,
0, features->y_max, 0, 0);
}
input_mt_init_slots(input_dev, features->touch_max, INPUT_MT_POINTER);
break;
case BAMBOO_PAD:
input_mt_init_slots(input_dev, features->touch_max,
INPUT_MT_POINTER);
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
break;
}
return 0;
}
static void wacom_setup_numbered_buttons(struct input_dev *input_dev,
int button_count)
{
int i;
for (i = 0; i < button_count && i < 10; i++)
__set_bit(BTN_0 + i, input_dev->keybit);
for (i = 10; i < button_count && i < 16; i++)
__set_bit(BTN_A + (i-10), input_dev->keybit);
for (i = 16; i < button_count && i < 18; i++)
__set_bit(BTN_BASE + (i-16), input_dev->keybit);
}
int wacom_setup_pad_input_capabilities(struct input_dev *input_dev,
struct wacom_wac *wacom_wac)
{
struct wacom_features *features = &wacom_wac->features;
if (!(features->device_type & WACOM_DEVICETYPE_PAD))
return -ENODEV;
input_dev->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
__set_bit(ABS_MISC, input_dev->absbit);
input_set_abs_params(input_dev, ABS_X, 0, 1, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, 1, 0, 0);
__set_bit(BTN_STYLUS, input_dev->keybit);
wacom_setup_numbered_buttons(input_dev, features->numbered_buttons);
switch (features->type) {
case CINTIQ_HYBRID:
case DTK:
case DTUS:
case GRAPHIRE_BT:
break;
case WACOM_MO:
__set_bit(BTN_BACK, input_dev->keybit);
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_FORWARD, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
break;
case WACOM_G4:
__set_bit(BTN_BACK, input_dev->keybit);
__set_bit(BTN_FORWARD, input_dev->keybit);
input_set_capability(input_dev, EV_REL, REL_WHEEL);
break;
case WACOM_24HD:
__set_bit(KEY_PROG1, input_dev->keybit);
__set_bit(KEY_PROG2, input_dev->keybit);
__set_bit(KEY_PROG3, input_dev->keybit);
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
input_set_abs_params(input_dev, ABS_THROTTLE, 0, 71, 0, 0);
break;
case WACOM_27QHD:
__set_bit(KEY_PROG1, input_dev->keybit);
__set_bit(KEY_PROG2, input_dev->keybit);
__set_bit(KEY_PROG3, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, -2048, 2048, 0, 0);
input_abs_set_res(input_dev, ABS_X, 1024);
input_set_abs_params(input_dev, ABS_Y, -2048, 2048, 0, 0);
input_abs_set_res(input_dev, ABS_Y, 1024);
input_set_abs_params(input_dev, ABS_Z, -2048, 2048, 0, 0);
input_abs_set_res(input_dev, ABS_Z, 1024);
__set_bit(INPUT_PROP_ACCELEROMETER, input_dev->propbit);
break;
case WACOM_22HD:
__set_bit(KEY_PROG1, input_dev->keybit);
__set_bit(KEY_PROG2, input_dev->keybit);
__set_bit(KEY_PROG3, input_dev->keybit);
case WACOM_21UX2:
case WACOM_BEE:
case CINTIQ:
input_set_abs_params(input_dev, ABS_RX, 0, 4096, 0, 0);
input_set_abs_params(input_dev, ABS_RY, 0, 4096, 0, 0);
break;
case WACOM_13HD:
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
break;
case INTUOS3:
case INTUOS3L:
input_set_abs_params(input_dev, ABS_RY, 0, 4096, 0, 0);
case INTUOS3S:
input_set_abs_params(input_dev, ABS_RX, 0, 4096, 0, 0);
break;
case INTUOS5:
case INTUOS5L:
case INTUOSPM:
case INTUOSPL:
case INTUOS5S:
case INTUOSPS:
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
break;
case INTUOS4WL:
__set_bit(BTN_STYLUS, input_dev->keybit);
case INTUOS4:
case INTUOS4L:
case INTUOS4S:
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
break;
case INTUOSHT:
case BAMBOO_PT:
__clear_bit(ABS_MISC, input_dev->absbit);
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_FORWARD, input_dev->keybit);
__set_bit(BTN_BACK, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
break;
case REMOTE:
input_set_capability(input_dev, EV_MSC, MSC_SERIAL);
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
break;
default:
return -ENODEV;
}
return 0;
}
