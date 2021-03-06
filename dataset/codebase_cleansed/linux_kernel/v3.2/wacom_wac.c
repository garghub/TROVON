static int wacom_penpartner_irq(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
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
printk(KERN_INFO "wacom_penpartner_irq: received unknown report #%d\n", data[0]);
return 0;
}
return 1;
}
static int wacom_pl_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
int prox, pressure;
if (data[0] != WACOM_REPORT_PENABLED) {
dbg("wacom_pl_irq: received unknown report #%d", data[0]);
return 0;
}
prox = data[1] & 0x40;
if (prox) {
wacom->id[0] = ERASER_DEVICE_ID;
pressure = (signed char)((data[7] << 1) | ((data[4] >> 2) & 1));
if (features->pressure_max > 255)
pressure = (pressure << 1) | ((data[4] >> 6) & 1);
pressure += (features->pressure_max + 1) / 2;
if (!wacom->tool[0]) {
if (data[1] & 0x10)
wacom->tool[1] = BTN_TOOL_RUBBER;
else
wacom->tool[1] = (data[4] & 0x20) ? BTN_TOOL_RUBBER : BTN_TOOL_PEN;
} else {
if (wacom->tool[1] == BTN_TOOL_RUBBER && !(data[4] & 0x20)) {
input_report_key(input, wacom->tool[1], 0);
input_sync(input);
wacom->tool[1] = BTN_TOOL_PEN;
return 0;
}
}
if (wacom->tool[1] != BTN_TOOL_RUBBER) {
wacom->tool[1] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
}
input_report_key(input, wacom->tool[1], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
input_report_abs(input, ABS_X, data[3] | (data[2] << 7) | ((data[1] & 0x03) << 14));
input_report_abs(input, ABS_Y, data[6] | (data[5] << 7) | ((data[4] & 0x03) << 14));
input_report_abs(input, ABS_PRESSURE, pressure);
input_report_key(input, BTN_TOUCH, data[4] & 0x08);
input_report_key(input, BTN_STYLUS, data[4] & 0x10);
input_report_key(input, BTN_STYLUS2, (wacom->tool[1] == BTN_TOOL_PEN) && (data[4] & 0x20));
} else {
if (wacom->tool[1] != BTN_TOOL_RUBBER) {
wacom->tool[1] = BTN_TOOL_PEN;
}
input_report_key(input, wacom->tool[1], prox);
}
wacom->tool[0] = prox;
return 1;
}
static int wacom_ptu_irq(struct wacom_wac *wacom)
{
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
if (data[0] != WACOM_REPORT_PENABLED) {
printk(KERN_INFO "wacom_ptu_irq: received unknown report #%d\n", data[0]);
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
struct wacom_features *features = &wacom->features;
char *data = wacom->data;
struct input_dev *input = wacom->input;
int prox = data[1] & 0x20, pressure;
dbg("wacom_dtu_irq: received report #%d", data[0]);
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
pressure = ((data[7] & 0x01) << 8) | data[6];
if (pressure < 0)
pressure = features->pressure_max + pressure + 1;
input_report_abs(input, ABS_PRESSURE, pressure);
input_report_key(input, BTN_TOUCH, data[1] & 0x05);
if (!prox)
wacom->id[0] = 0;
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
static int wacom_graphire_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
int prox;
int rw = 0;
int retval = 0;
if (data[0] != WACOM_REPORT_PENABLED) {
dbg("wacom_graphire_irq: received unknown report #%d", data[0]);
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
input_report_abs(input, ABS_PRESSURE, data[6] | ((data[7] & 0x01) << 8));
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
input_event(input, EV_MSC, MSC_SERIAL, 1);
input_sync(input);
}
switch (features->type) {
case WACOM_G4:
prox = data[7] & 0xf8;
if (prox || wacom->id[1]) {
wacom->id[1] = PAD_DEVICE_ID;
input_report_key(input, BTN_BACK, (data[7] & 0x40));
input_report_key(input, BTN_FORWARD, (data[7] & 0x80));
rw = ((data[7] & 0x18) >> 3) - ((data[7] & 0x20) >> 3);
input_report_rel(input, REL_WHEEL, rw);
if (!prox)
wacom->id[1] = 0;
input_report_abs(input, ABS_MISC, wacom->id[1]);
input_event(input, EV_MSC, MSC_SERIAL, 0xf0);
retval = 1;
}
break;
case WACOM_MO:
prox = (data[7] & 0xf8) || data[8];
if (prox || wacom->id[1]) {
wacom->id[1] = PAD_DEVICE_ID;
input_report_key(input, BTN_BACK, (data[7] & 0x08));
input_report_key(input, BTN_LEFT, (data[7] & 0x20));
input_report_key(input, BTN_FORWARD, (data[7] & 0x10));
input_report_key(input, BTN_RIGHT, (data[7] & 0x40));
input_report_abs(input, ABS_WHEEL, (data[8] & 0x7f));
if (!prox)
wacom->id[1] = 0;
input_report_abs(input, ABS_MISC, wacom->id[1]);
input_event(input, EV_MSC, MSC_SERIAL, 0xf0);
retval = 1;
}
break;
}
exit:
return retval;
}
static int wacom_intuos_inout(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
int idx = 0;
if (features->type == INTUOS)
idx = data[1] & 0x01;
if ((data[1] & 0xfc) == 0xc0) {
wacom->serial[idx] = ((data[3] & 0x0f) << 28) +
(data[4] << 20) + (data[5] << 12) +
(data[6] << 4) + (data[7] >> 4);
wacom->id[idx] = (data[2] << 4) | (data[3] >> 4) |
((data[7] & 0x0f) << 20) | ((data[8] & 0xf0) << 12);
switch (wacom->id[idx] & 0xfffff) {
case 0x812:
case 0x801:
case 0x20802:
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
case 0x40802:
case 0x022:
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
case 0x4080a:
case 0x90a:
wacom->tool[idx] = BTN_TOOL_RUBBER;
break;
case 0xd12:
case 0x912:
case 0x112:
case 0x913:
case 0x902:
wacom->tool[idx] = BTN_TOOL_AIRBRUSH;
break;
default:
wacom->tool[idx] = BTN_TOOL_PEN;
break;
}
return 1;
}
if (!((wacom->id[idx] >> 20) & 0x01) &&
(features->type == WACOM_21UX2))
return 1;
if ((data[1] & 0xfe) == 0x80) {
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
return 0;
}
static void wacom_intuos_general(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
unsigned int t;
if ((data[1] & 0xb8) == 0xa0) {
t = (data[6] << 2) | ((data[7] >> 6) & 3);
if ((features->type >= INTUOS4S && features->type <= INTUOS4L) ||
features->type == WACOM_21UX2) {
t = (t << 1) | (data[1] & 1);
}
input_report_abs(input, ABS_PRESSURE, t);
input_report_abs(input, ABS_TILT_X,
((data[7] << 1) & 0x7e) | (data[8] >> 7));
input_report_abs(input, ABS_TILT_Y, data[8] & 0x7f);
input_report_key(input, BTN_STYLUS, data[1] & 2);
input_report_key(input, BTN_STYLUS2, data[1] & 4);
input_report_key(input, BTN_TOUCH, t > 10);
}
if ((data[1] & 0xbc) == 0xb4) {
input_report_abs(input, ABS_WHEEL,
(data[6] << 2) | ((data[7] >> 6) & 3));
input_report_abs(input, ABS_TILT_X,
((data[7] << 1) & 0x7e) | (data[8] >> 7));
input_report_abs(input, ABS_TILT_Y, data[8] & 0x7f);
}
}
static int wacom_intuos_irq(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
unsigned char *data = wacom->data;
struct input_dev *input = wacom->input;
unsigned int t;
int idx = 0, result;
if (data[0] != WACOM_REPORT_PENABLED && data[0] != WACOM_REPORT_INTUOSREAD
&& data[0] != WACOM_REPORT_INTUOSWRITE && data[0] != WACOM_REPORT_INTUOSPAD) {
dbg("wacom_intuos_irq: received unknown report #%d", data[0]);
return 0;
}
if (features->type == INTUOS)
idx = data[1] & 0x01;
if (data[0] == WACOM_REPORT_INTUOSPAD) {
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
input_report_key(input, wacom->tool[1], 1);
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_key(input, wacom->tool[1], 0);
input_report_abs(input, ABS_MISC, 0);
}
} else {
if (features->type == WACOM_21UX2) {
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
input_report_key(input, wacom->tool[1], 1);
input_report_abs(input, ABS_MISC, PAD_DEVICE_ID);
} else {
input_report_key(input, wacom->tool[1], 0);
input_report_abs(input, ABS_MISC, 0);
}
}
input_event(input, EV_MSC, MSC_SERIAL, 0xffffffff);
return 1;
}
result = wacom_intuos_inout(wacom);
if (result)
return result - 1;
if (!wacom->id[idx])
return 0;
if (wacom->tool[idx] == BTN_TOOL_LENS &&
(features->type == INTUOS3 ||
features->type == INTUOS3S ||
features->type == INTUOS4 ||
features->type == INTUOS4S)) {
return 0;
}
if (features->type == CINTIQ && !(data[1] & 0x40))
return 0;
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
if (features->type >= INTUOS4S && features->type <= INTUOS4L) {
input_report_key(input, BTN_LEFT, data[6] & 0x01);
input_report_key(input, BTN_MIDDLE, data[6] & 0x02);
input_report_key(input, BTN_RIGHT, data[6] & 0x04);
input_report_rel(input, REL_WHEEL, ((data[7] & 0x80) >> 7)
- ((data[7] & 0x40) >> 6));
input_report_key(input, BTN_SIDE, data[6] & 0x08);
input_report_key(input, BTN_EXTRA, data[6] & 0x10);
input_report_abs(input, ABS_TILT_X,
((data[7] << 1) & 0x7e) | (data[8] >> 7));
input_report_abs(input, ABS_TILT_Y, data[8] & 0x7f);
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
features->type == INTUOS4L) &&
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
return 1;
}
static int wacom_tpc_mt_touch(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->input;
unsigned char *data = wacom->data;
int contact_with_no_pen_down_count = 0;
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
contact_with_no_pen_down_count++;
}
}
wacom->shared->touch_down = (contact_with_no_pen_down_count > 0);
input_mt_report_pointer_emulation(input, true);
return 1;
}
static int wacom_tpc_single_touch(struct wacom_wac *wacom, size_t len)
{
char *data = wacom->data;
struct input_dev *input = wacom->input;
bool prox;
int x = 0, y = 0;
if (!wacom->shared->stylus_in_proximity) {
if (len == WACOM_PKGLEN_TPC1FG) {
prox = data[0] & 0x01;
x = get_unaligned_le16(&data[1]);
y = get_unaligned_le16(&data[3]);
} else {
prox = data[1] & 0x01;
x = le16_to_cpup((__le16 *)&data[2]);
y = le16_to_cpup((__le16 *)&data[4]);
}
} else
prox = 0;
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
struct wacom_features *features = &wacom->features;
char *data = wacom->data;
struct input_dev *input = wacom->input;
int pressure;
bool prox = data[1] & 0x20;
if (!wacom->shared->stylus_in_proximity)
wacom->tool[0] = (data[1] & 0x0c) ? BTN_TOOL_RUBBER : BTN_TOOL_PEN;
wacom->shared->stylus_in_proximity = prox;
if (!wacom->shared->touch_down) {
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, data[1] & 0x10);
input_report_abs(input, ABS_X, le16_to_cpup((__le16 *)&data[2]));
input_report_abs(input, ABS_Y, le16_to_cpup((__le16 *)&data[4]));
pressure = ((data[7] & 0x01) << 8) | data[6];
if (pressure < 0)
pressure = features->pressure_max + pressure + 1;
input_report_abs(input, ABS_PRESSURE, pressure);
input_report_key(input, BTN_TOUCH, data[1] & 0x05);
input_report_key(input, wacom->tool[0], prox);
return 1;
}
return 0;
}
static int wacom_tpc_irq(struct wacom_wac *wacom, size_t len)
{
char *data = wacom->data;
dbg("wacom_tpc_irq: received report #%d", data[0]);
if (len == WACOM_PKGLEN_TPC1FG || data[0] == WACOM_REPORT_TPC1FG)
return wacom_tpc_single_touch(wacom, len);
else if (data[0] == WACOM_REPORT_TPC2FG)
return wacom_tpc_mt_touch(wacom);
else if (data[0] == WACOM_REPORT_PENABLED)
return wacom_tpc_pen(wacom);
return 0;
}
static int wacom_bpt_touch(struct wacom_wac *wacom)
{
struct wacom_features *features = &wacom->features;
struct input_dev *input = wacom->input;
unsigned char *data = wacom->data;
int i;
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
input_mt_report_pointer_emulation(input, true);
input_report_key(input, BTN_LEFT, (data[1] & 0x08) != 0);
input_report_key(input, BTN_FORWARD, (data[1] & 0x04) != 0);
input_report_key(input, BTN_BACK, (data[1] & 0x02) != 0);
input_report_key(input, BTN_RIGHT, (data[1] & 0x01) != 0);
input_sync(input);
return 0;
}
static int wacom_bpt_pen(struct wacom_wac *wacom)
{
struct input_dev *input = wacom->input;
unsigned char *data = wacom->data;
int prox = 0, x = 0, y = 0, p = 0, d = 0, pen = 0, btn1 = 0, btn2 = 0;
prox = (data[1] & 0x30) == 0x30;
if (prox) {
if (!wacom->shared->stylus_in_proximity) {
if (data[1] & 0x08) {
wacom->tool[0] = BTN_TOOL_RUBBER;
wacom->id[0] = ERASER_DEVICE_ID;
} else {
wacom->tool[0] = BTN_TOOL_PEN;
wacom->id[0] = STYLUS_DEVICE_ID;
}
wacom->shared->stylus_in_proximity = true;
}
x = le16_to_cpup((__le16 *)&data[2]);
y = le16_to_cpup((__le16 *)&data[4]);
p = le16_to_cpup((__le16 *)&data[6]);
if (data[8] <= wacom->features.distance_max)
d = wacom->features.distance_max - data[8];
pen = data[1] & 0x01;
btn1 = data[1] & 0x02;
btn2 = data[1] & 0x04;
}
input_report_key(input, BTN_TOUCH, pen);
input_report_key(input, BTN_STYLUS, btn1);
input_report_key(input, BTN_STYLUS2, btn2);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
input_report_abs(input, ABS_PRESSURE, p);
input_report_abs(input, ABS_DISTANCE, d);
if (!prox) {
wacom->id[0] = 0;
wacom->shared->stylus_in_proximity = false;
}
input_report_key(input, wacom->tool[0], prox);
input_report_abs(input, ABS_MISC, wacom->id[0]);
return 1;
}
static int wacom_bpt_irq(struct wacom_wac *wacom, size_t len)
{
if (len == WACOM_PKGLEN_BBTOUCH)
return wacom_bpt_touch(wacom);
else if (len == WACOM_PKGLEN_BBFUN)
return wacom_bpt_pen(wacom);
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
case WACOM_MO:
sync = wacom_graphire_irq(wacom_wac);
break;
case PTU:
sync = wacom_ptu_irq(wacom_wac);
break;
case DTU:
sync = wacom_dtu_irq(wacom_wac);
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
case WACOM_21UX2:
sync = wacom_intuos_irq(wacom_wac);
break;
case TABLETPC:
case TABLETPC2FG:
sync = wacom_tpc_irq(wacom_wac, len);
break;
case BAMBOO_PT:
sync = wacom_bpt_irq(wacom_wac, len);
break;
default:
sync = false;
break;
}
if (sync)
input_sync(wacom_wac->input);
}
static void wacom_setup_cintiq(struct wacom_wac *wacom_wac)
{
struct input_dev *input_dev = wacom_wac->input;
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
input_set_abs_params(input_dev, ABS_TILT_X, 0, 127, 0, 0);
input_set_abs_params(input_dev, ABS_TILT_Y, 0, 127, 0, 0);
}
static void wacom_setup_intuos(struct wacom_wac *wacom_wac)
{
struct input_dev *input_dev = wacom_wac->input;
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
input_set_abs_params(input_dev, ABS_THROTTLE, -1023, 1023, 0, 0);
}
void wacom_setup_device_quirks(struct wacom_features *features)
{
if (features->device_type == BTN_TOOL_FINGER && !features->x_max) {
features->x_max = 1023;
features->y_max = 1023;
}
if (features->type == TABLETPC || features->type == TABLETPC2FG ||
features->type == BAMBOO_PT)
features->quirks |= WACOM_QUIRK_MULTI_INPUT;
if (features->type == BAMBOO_PT &&
features->device_type == BTN_TOOL_DOUBLETAP) {
features->x_max <<= 5;
features->y_max <<= 5;
features->x_fuzz <<= 5;
features->y_fuzz <<= 5;
features->quirks |= WACOM_QUIRK_BBTOUCH_LOWRES;
}
}
static unsigned int wacom_calculate_touch_res(unsigned int logical_max,
unsigned int physical_max)
{
return (logical_max * 100) / physical_max;
}
void wacom_setup_input_capabilities(struct input_dev *input_dev,
struct wacom_wac *wacom_wac)
{
struct wacom_features *features = &wacom_wac->features;
int i;
input_dev->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, features->x_max,
features->x_fuzz, 0);
input_set_abs_params(input_dev, ABS_Y, 0, features->y_max,
features->y_fuzz, 0);
if (features->device_type == BTN_TOOL_PEN) {
input_set_abs_params(input_dev, ABS_PRESSURE, 0, features->pressure_max,
features->pressure_fuzz, 0);
input_abs_set_res(input_dev, ABS_X, features->x_resolution);
input_abs_set_res(input_dev, ABS_Y, features->y_resolution);
} else {
input_abs_set_res(input_dev, ABS_X,
wacom_calculate_touch_res(features->x_max,
features->x_phy));
input_abs_set_res(input_dev, ABS_Y,
wacom_calculate_touch_res(features->y_max,
features->y_phy));
}
__set_bit(ABS_MISC, input_dev->absbit);
switch (wacom_wac->features.type) {
case WACOM_MO:
input_set_abs_params(input_dev, ABS_WHEEL, 0, 71, 0, 0);
case WACOM_G4:
input_set_capability(input_dev, EV_MSC, MSC_SERIAL);
__set_bit(BTN_BACK, input_dev->keybit);
__set_bit(BTN_FORWARD, input_dev->keybit);
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
case WACOM_21UX2:
__set_bit(BTN_A, input_dev->keybit);
__set_bit(BTN_B, input_dev->keybit);
__set_bit(BTN_C, input_dev->keybit);
__set_bit(BTN_X, input_dev->keybit);
__set_bit(BTN_Y, input_dev->keybit);
__set_bit(BTN_Z, input_dev->keybit);
__set_bit(BTN_BASE, input_dev->keybit);
__set_bit(BTN_BASE2, input_dev->keybit);
case WACOM_BEE:
__set_bit(BTN_8, input_dev->keybit);
__set_bit(BTN_9, input_dev->keybit);
case CINTIQ:
for (i = 0; i < 8; i++)
__set_bit(BTN_0 + i, input_dev->keybit);
input_set_abs_params(input_dev, ABS_RX, 0, 4096, 0, 0);
input_set_abs_params(input_dev, ABS_RY, 0, 4096, 0, 0);
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
wacom_setup_cintiq(wacom_wac);
break;
case INTUOS3:
case INTUOS3L:
__set_bit(BTN_4, input_dev->keybit);
__set_bit(BTN_5, input_dev->keybit);
__set_bit(BTN_6, input_dev->keybit);
__set_bit(BTN_7, input_dev->keybit);
input_set_abs_params(input_dev, ABS_RY, 0, 4096, 0, 0);
case INTUOS3S:
__set_bit(BTN_0, input_dev->keybit);
__set_bit(BTN_1, input_dev->keybit);
__set_bit(BTN_2, input_dev->keybit);
__set_bit(BTN_3, input_dev->keybit);
input_set_abs_params(input_dev, ABS_RX, 0, 4096, 0, 0);
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
case INTUOS:
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
wacom_setup_intuos(wacom_wac);
break;
case INTUOS4:
case INTUOS4L:
__set_bit(BTN_7, input_dev->keybit);
__set_bit(BTN_8, input_dev->keybit);
case INTUOS4S:
for (i = 0; i < 7; i++)
__set_bit(BTN_0 + i, input_dev->keybit);
input_set_abs_params(input_dev, ABS_Z, -900, 899, 0, 0);
wacom_setup_intuos(wacom_wac);
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
break;
case TABLETPC2FG:
if (features->device_type == BTN_TOOL_DOUBLETAP) {
input_mt_init_slots(input_dev, 2);
input_set_abs_params(input_dev, ABS_MT_TOOL_TYPE,
0, MT_TOOL_MAX, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
0, features->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
0, features->y_max, 0, 0);
}
case TABLETPC:
__clear_bit(ABS_MISC, input_dev->absbit);
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
if (features->device_type != BTN_TOOL_PEN)
break;
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
case BAMBOO_PT:
__clear_bit(ABS_MISC, input_dev->absbit);
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
if (features->device_type == BTN_TOOL_DOUBLETAP) {
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_FORWARD, input_dev->keybit);
__set_bit(BTN_BACK, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
__set_bit(BTN_TOOL_FINGER, input_dev->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, input_dev->keybit);
input_mt_init_slots(input_dev, 2);
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
0, features->x_max,
features->x_fuzz, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
0, features->y_max,
features->y_fuzz, 0);
} else if (features->device_type == BTN_TOOL_PEN) {
__set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
__set_bit(BTN_TOOL_PEN, input_dev->keybit);
__set_bit(BTN_STYLUS, input_dev->keybit);
__set_bit(BTN_STYLUS2, input_dev->keybit);
input_set_abs_params(input_dev, ABS_DISTANCE, 0,
features->distance_max,
0, 0);
}
break;
}
}
