static int synaptics_send_cmd(struct psmouse *psmouse, unsigned char c,
unsigned char *param)
{
if (psmouse_sliced_command(psmouse, c) ||
ps2_command(&psmouse->ps2dev, param, PSMOUSE_CMD_GETINFO)) {
psmouse_err(psmouse, "%s query 0x%02x failed.\n", __func__, c);
return -1;
}
return 0;
}
static int elantech_send_cmd(struct psmouse *psmouse, unsigned char c,
unsigned char *param)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, ETP_PS2_CUSTOM_COMMAND) ||
ps2_command(ps2dev, NULL, c) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO)) {
psmouse_err(psmouse, "%s query 0x%02x failed.\n", __func__, c);
return -1;
}
return 0;
}
static int elantech_ps2_command(struct psmouse *psmouse,
unsigned char *param, int command)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct elantech_data *etd = psmouse->private;
int rc;
int tries = ETP_PS2_COMMAND_TRIES;
do {
rc = ps2_command(ps2dev, param, command);
if (rc == 0)
break;
tries--;
elantech_debug("retrying ps2 command 0x%02x (%d).\n",
command, tries);
msleep(ETP_PS2_COMMAND_DELAY);
} while (tries > 0);
if (rc)
psmouse_err(psmouse, "ps2 command 0x%02x failed.\n", command);
return rc;
}
static int elantech_read_reg(struct psmouse *psmouse, unsigned char reg,
unsigned char *val)
{
struct elantech_data *etd = psmouse->private;
unsigned char param[3];
int rc = 0;
if (reg < 0x07 || reg > 0x26)
return -1;
if (reg > 0x11 && reg < 0x20)
return -1;
switch (etd->hw_version) {
case 1:
if (psmouse_sliced_command(psmouse, ETP_REGISTER_READ) ||
psmouse_sliced_command(psmouse, reg) ||
ps2_command(&psmouse->ps2dev, param, PSMOUSE_CMD_GETINFO)) {
rc = -1;
}
break;
case 2:
if (elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_READ) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, reg) ||
elantech_ps2_command(psmouse, param, PSMOUSE_CMD_GETINFO)) {
rc = -1;
}
break;
case 3 ... 4:
if (elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_READWRITE) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, reg) ||
elantech_ps2_command(psmouse, param, PSMOUSE_CMD_GETINFO)) {
rc = -1;
}
break;
}
if (rc)
psmouse_err(psmouse, "failed to read register 0x%02x.\n", reg);
else if (etd->hw_version != 4)
*val = param[0];
else
*val = param[1];
return rc;
}
static int elantech_write_reg(struct psmouse *psmouse, unsigned char reg,
unsigned char val)
{
struct elantech_data *etd = psmouse->private;
int rc = 0;
if (reg < 0x07 || reg > 0x26)
return -1;
if (reg > 0x11 && reg < 0x20)
return -1;
switch (etd->hw_version) {
case 1:
if (psmouse_sliced_command(psmouse, ETP_REGISTER_WRITE) ||
psmouse_sliced_command(psmouse, reg) ||
psmouse_sliced_command(psmouse, val) ||
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSCALE11)) {
rc = -1;
}
break;
case 2:
if (elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_WRITE) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, reg) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, val) ||
elantech_ps2_command(psmouse, NULL, PSMOUSE_CMD_SETSCALE11)) {
rc = -1;
}
break;
case 3:
if (elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_READWRITE) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, reg) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, val) ||
elantech_ps2_command(psmouse, NULL, PSMOUSE_CMD_SETSCALE11)) {
rc = -1;
}
break;
case 4:
if (elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_READWRITE) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, reg) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, ETP_REGISTER_READWRITE) ||
elantech_ps2_command(psmouse, NULL, ETP_PS2_CUSTOM_COMMAND) ||
elantech_ps2_command(psmouse, NULL, val) ||
elantech_ps2_command(psmouse, NULL, PSMOUSE_CMD_SETSCALE11)) {
rc = -1;
}
break;
}
if (rc)
psmouse_err(psmouse,
"failed to write register 0x%02x with value 0x%02x.\n",
reg, val);
return rc;
}
static void elantech_packet_dump(struct psmouse *psmouse)
{
int i;
psmouse_printk(KERN_DEBUG, psmouse, "PS/2 packet [");
for (i = 0; i < psmouse->pktsize; i++)
printk("%s0x%02x ", i ? ", " : " ", psmouse->packet[i]);
printk("]\n");
}
static void elantech_report_absolute_v1(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
int fingers;
if (etd->fw_version < 0x020000) {
fingers = ((packet[1] & 0x80) >> 7) +
((packet[1] & 0x30) >> 4);
} else {
fingers = (packet[0] & 0xc0) >> 6;
}
if (etd->jumpy_cursor) {
if (fingers != 1) {
etd->single_finger_reports = 0;
} else if (etd->single_finger_reports < 2) {
etd->single_finger_reports++;
elantech_debug("discarding packet\n");
return;
}
}
input_report_key(dev, BTN_TOUCH, fingers != 0);
if (fingers) {
input_report_abs(dev, ABS_X,
((packet[1] & 0x0c) << 6) | packet[2]);
input_report_abs(dev, ABS_Y,
etd->y_max - (((packet[1] & 0x03) << 8) | packet[3]));
}
input_report_key(dev, BTN_TOOL_FINGER, fingers == 1);
input_report_key(dev, BTN_TOOL_DOUBLETAP, fingers == 2);
input_report_key(dev, BTN_TOOL_TRIPLETAP, fingers == 3);
input_report_key(dev, BTN_LEFT, packet[0] & 0x01);
input_report_key(dev, BTN_RIGHT, packet[0] & 0x02);
if (etd->fw_version < 0x020000 &&
(etd->capabilities[0] & ETP_CAP_HAS_ROCKER)) {
input_report_key(dev, BTN_FORWARD, packet[0] & 0x40);
input_report_key(dev, BTN_BACK, packet[0] & 0x80);
}
input_sync(dev);
}
static void elantech_set_slot(struct input_dev *dev, int slot, bool active,
unsigned int x, unsigned int y)
{
input_mt_slot(dev, slot);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, active);
if (active) {
input_report_abs(dev, ABS_MT_POSITION_X, x);
input_report_abs(dev, ABS_MT_POSITION_Y, y);
}
}
static void elantech_report_semi_mt_data(struct input_dev *dev,
unsigned int num_fingers,
unsigned int x1, unsigned int y1,
unsigned int x2, unsigned int y2)
{
elantech_set_slot(dev, 0, num_fingers != 0, x1, y1);
elantech_set_slot(dev, 1, num_fingers >= 2, x2, y2);
}
static void elantech_report_absolute_v2(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
struct input_dev *dev = psmouse->dev;
unsigned char *packet = psmouse->packet;
unsigned int fingers, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
unsigned int width = 0, pres = 0;
fingers = (packet[0] & 0xc0) >> 6;
switch (fingers) {
case 3:
if (packet[3] & 0x80)
fingers = 4;
case 1:
x1 = ((packet[1] & 0x0f) << 8) | packet[2];
y1 = etd->y_max - (((packet[4] & 0x0f) << 8) | packet[5]);
pres = (packet[1] & 0xf0) | ((packet[4] & 0xf0) >> 4);
width = ((packet[0] & 0x30) >> 2) | ((packet[3] & 0x30) >> 4);
break;
case 2:
x1 = (((packet[0] & 0x10) << 4) | packet[1]) << 2;
y1 = etd->y_max -
((((packet[0] & 0x20) << 3) | packet[2]) << 2);
x2 = (((packet[3] & 0x10) << 4) | packet[4]) << 2;
y2 = etd->y_max -
((((packet[3] & 0x20) << 3) | packet[5]) << 2);
pres = 127;
width = 7;
break;
}
input_report_key(dev, BTN_TOUCH, fingers != 0);
if (fingers != 0) {
input_report_abs(dev, ABS_X, x1);
input_report_abs(dev, ABS_Y, y1);
}
elantech_report_semi_mt_data(dev, fingers, x1, y1, x2, y2);
input_report_key(dev, BTN_TOOL_FINGER, fingers == 1);
input_report_key(dev, BTN_TOOL_DOUBLETAP, fingers == 2);
input_report_key(dev, BTN_TOOL_TRIPLETAP, fingers == 3);
input_report_key(dev, BTN_TOOL_QUADTAP, fingers == 4);
input_report_key(dev, BTN_LEFT, packet[0] & 0x01);
input_report_key(dev, BTN_RIGHT, packet[0] & 0x02);
if (etd->reports_pressure) {
input_report_abs(dev, ABS_PRESSURE, pres);
input_report_abs(dev, ABS_TOOL_WIDTH, width);
}
input_sync(dev);
}
static void elantech_report_trackpoint(struct psmouse *psmouse,
int packet_type)
{
struct elantech_data *etd = psmouse->private;
struct input_dev *tp_dev = etd->tp_dev;
unsigned char *packet = psmouse->packet;
int x, y;
u32 t;
t = get_unaligned_le32(&packet[0]);
switch (t & ~7U) {
case 0x06000030U:
case 0x16008020U:
case 0x26800010U:
case 0x36808000U:
x = packet[4] - (int)((packet[1]^0x80) << 1);
y = (int)((packet[2]^0x80) << 1) - packet[5];
input_report_key(tp_dev, BTN_LEFT, packet[0] & 0x01);
input_report_key(tp_dev, BTN_RIGHT, packet[0] & 0x02);
input_report_key(tp_dev, BTN_MIDDLE, packet[0] & 0x04);
input_report_rel(tp_dev, REL_X, x);
input_report_rel(tp_dev, REL_Y, y);
input_sync(tp_dev);
break;
default:
if (etd->debug == 1)
elantech_packet_dump(psmouse);
break;
}
}
static void elantech_report_absolute_v3(struct psmouse *psmouse,
int packet_type)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
unsigned int fingers = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
unsigned int width = 0, pres = 0;
fingers = (packet[0] & 0xc0) >> 6;
switch (fingers) {
case 3:
case 1:
x1 = ((packet[1] & 0x0f) << 8) | packet[2];
y1 = etd->y_max - (((packet[4] & 0x0f) << 8) | packet[5]);
break;
case 2:
if (packet_type == PACKET_V3_HEAD) {
etd->mt[0].x = ((packet[1] & 0x0f) << 8) | packet[2];
etd->mt[0].y = etd->y_max -
(((packet[4] & 0x0f) << 8) | packet[5]);
return;
}
x1 = etd->mt[0].x;
y1 = etd->mt[0].y;
x2 = ((packet[1] & 0x0f) << 8) | packet[2];
y2 = etd->y_max - (((packet[4] & 0x0f) << 8) | packet[5]);
break;
}
pres = (packet[1] & 0xf0) | ((packet[4] & 0xf0) >> 4);
width = ((packet[0] & 0x30) >> 2) | ((packet[3] & 0x30) >> 4);
input_report_key(dev, BTN_TOUCH, fingers != 0);
if (fingers != 0) {
input_report_abs(dev, ABS_X, x1);
input_report_abs(dev, ABS_Y, y1);
}
elantech_report_semi_mt_data(dev, fingers, x1, y1, x2, y2);
input_report_key(dev, BTN_TOOL_FINGER, fingers == 1);
input_report_key(dev, BTN_TOOL_DOUBLETAP, fingers == 2);
input_report_key(dev, BTN_TOOL_TRIPLETAP, fingers == 3);
if (etd->fw_version & 0x001000) {
input_report_key(dev, BTN_LEFT, packet[0] & 0x03);
} else {
input_report_key(dev, BTN_LEFT, packet[0] & 0x01);
input_report_key(dev, BTN_RIGHT, packet[0] & 0x02);
}
input_report_abs(dev, ABS_PRESSURE, pres);
input_report_abs(dev, ABS_TOOL_WIDTH, width);
input_sync(dev);
}
static void elantech_input_sync_v4(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
if (etd->fw_version & 0x001000) {
input_report_key(dev, BTN_LEFT, packet[0] & 0x03);
} else {
input_report_key(dev, BTN_LEFT, packet[0] & 0x01);
input_report_key(dev, BTN_RIGHT, packet[0] & 0x02);
input_report_key(dev, BTN_MIDDLE, packet[0] & 0x04);
}
input_mt_report_pointer_emulation(dev, true);
input_sync(dev);
}
static void process_packet_status_v4(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
unsigned char *packet = psmouse->packet;
unsigned fingers;
int i;
fingers = packet[1] & 0x1f;
for (i = 0; i < ETP_MAX_FINGERS; i++) {
if ((fingers & (1 << i)) == 0) {
input_mt_slot(dev, i);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, false);
}
}
elantech_input_sync_v4(psmouse);
}
static void process_packet_head_v4(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
int id = ((packet[3] & 0xe0) >> 5) - 1;
int pres, traces;
if (id < 0)
return;
etd->mt[id].x = ((packet[1] & 0x0f) << 8) | packet[2];
etd->mt[id].y = etd->y_max - (((packet[4] & 0x0f) << 8) | packet[5]);
pres = (packet[1] & 0xf0) | ((packet[4] & 0xf0) >> 4);
traces = (packet[0] & 0xf0) >> 4;
input_mt_slot(dev, id);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, true);
input_report_abs(dev, ABS_MT_POSITION_X, etd->mt[id].x);
input_report_abs(dev, ABS_MT_POSITION_Y, etd->mt[id].y);
input_report_abs(dev, ABS_MT_PRESSURE, pres);
input_report_abs(dev, ABS_MT_TOUCH_MAJOR, traces * etd->width);
input_report_abs(dev, ABS_TOOL_WIDTH, traces);
elantech_input_sync_v4(psmouse);
}
static void process_packet_motion_v4(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
int weight, delta_x1 = 0, delta_y1 = 0, delta_x2 = 0, delta_y2 = 0;
int id, sid;
id = ((packet[0] & 0xe0) >> 5) - 1;
if (id < 0)
return;
sid = ((packet[3] & 0xe0) >> 5) - 1;
weight = (packet[0] & 0x10) ? ETP_WEIGHT_VALUE : 1;
delta_x1 = (signed char)packet[1];
delta_y1 = (signed char)packet[2];
delta_x2 = (signed char)packet[4];
delta_y2 = (signed char)packet[5];
etd->mt[id].x += delta_x1 * weight;
etd->mt[id].y -= delta_y1 * weight;
input_mt_slot(dev, id);
input_report_abs(dev, ABS_MT_POSITION_X, etd->mt[id].x);
input_report_abs(dev, ABS_MT_POSITION_Y, etd->mt[id].y);
if (sid >= 0) {
etd->mt[sid].x += delta_x2 * weight;
etd->mt[sid].y -= delta_y2 * weight;
input_mt_slot(dev, sid);
input_report_abs(dev, ABS_MT_POSITION_X, etd->mt[sid].x);
input_report_abs(dev, ABS_MT_POSITION_Y, etd->mt[sid].y);
}
elantech_input_sync_v4(psmouse);
}
static void elantech_report_absolute_v4(struct psmouse *psmouse,
int packet_type)
{
switch (packet_type) {
case PACKET_V4_STATUS:
process_packet_status_v4(psmouse);
break;
case PACKET_V4_HEAD:
process_packet_head_v4(psmouse);
break;
case PACKET_V4_MOTION:
process_packet_motion_v4(psmouse);
break;
case PACKET_UNKNOWN:
default:
break;
}
}
static int elantech_packet_check_v1(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
unsigned char p1, p2, p3;
if (etd->fw_version < 0x020000) {
p1 = (packet[0] & 0x20) >> 5;
p2 = (packet[0] & 0x10) >> 4;
} else {
p1 = (packet[0] & 0x10) >> 4;
p2 = (packet[0] & 0x20) >> 5;
}
p3 = (packet[0] & 0x04) >> 2;
return etd->parity[packet[1]] == p1 &&
etd->parity[packet[2]] == p2 &&
etd->parity[packet[3]] == p3;
}
static int elantech_debounce_check_v2(struct psmouse *psmouse)
{
const u8 debounce_packet[] = { 0x84, 0xff, 0xff, 0x02, 0xff, 0xff };
unsigned char *packet = psmouse->packet;
return !memcmp(packet, debounce_packet, sizeof(debounce_packet));
}
static int elantech_packet_check_v2(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
if (etd->reports_pressure)
return (packet[0] & 0x0c) == 0x04 &&
(packet[3] & 0x0f) == 0x02;
if ((packet[0] & 0xc0) == 0x80)
return (packet[0] & 0x0c) == 0x0c &&
(packet[3] & 0x0e) == 0x08;
return (packet[0] & 0x3c) == 0x3c &&
(packet[1] & 0xf0) == 0x00 &&
(packet[3] & 0x3e) == 0x38 &&
(packet[4] & 0xf0) == 0x00;
}
static int elantech_packet_check_v3(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
const u8 debounce_packet[] = { 0xc4, 0xff, 0xff, 0x02, 0xff, 0xff };
unsigned char *packet = psmouse->packet;
if (!memcmp(packet, debounce_packet, sizeof(debounce_packet)))
return PACKET_DEBOUNCE;
if (etd->crc_enabled) {
if ((packet[3] & 0x09) == 0x08)
return PACKET_V3_HEAD;
if ((packet[3] & 0x09) == 0x09)
return PACKET_V3_TAIL;
} else {
if ((packet[0] & 0x0c) == 0x04 && (packet[3] & 0xcf) == 0x02)
return PACKET_V3_HEAD;
if ((packet[0] & 0x0c) == 0x0c && (packet[3] & 0xce) == 0x0c)
return PACKET_V3_TAIL;
if ((packet[3] & 0x0f) == 0x06)
return PACKET_TRACKPOINT;
}
return PACKET_UNKNOWN;
}
static int elantech_packet_check_v4(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
unsigned char *packet = psmouse->packet;
unsigned char packet_type = packet[3] & 0x03;
unsigned int ic_version;
bool sanity_check;
if (etd->tp_dev && (packet[3] & 0x0f) == 0x06)
return PACKET_TRACKPOINT;
ic_version = (etd->fw_version & 0x0f0000) >> 16;
if (etd->crc_enabled)
sanity_check = ((packet[3] & 0x08) == 0x00);
else if (ic_version == 7 && etd->samples[1] == 0x2A)
sanity_check = ((packet[3] & 0x1c) == 0x10);
else
sanity_check = ((packet[0] & 0x0c) == 0x04 &&
(packet[3] & 0x1c) == 0x10);
if (!sanity_check)
return PACKET_UNKNOWN;
switch (packet_type) {
case 0:
return PACKET_V4_STATUS;
case 1:
return PACKET_V4_HEAD;
case 2:
return PACKET_V4_MOTION;
}
return PACKET_UNKNOWN;
}
static psmouse_ret_t elantech_process_byte(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
int packet_type;
if (psmouse->pktcnt < psmouse->pktsize)
return PSMOUSE_GOOD_DATA;
if (etd->debug > 1)
elantech_packet_dump(psmouse);
switch (etd->hw_version) {
case 1:
if (etd->paritycheck && !elantech_packet_check_v1(psmouse))
return PSMOUSE_BAD_DATA;
elantech_report_absolute_v1(psmouse);
break;
case 2:
if (elantech_debounce_check_v2(psmouse))
return PSMOUSE_FULL_PACKET;
if (etd->paritycheck && !elantech_packet_check_v2(psmouse))
return PSMOUSE_BAD_DATA;
elantech_report_absolute_v2(psmouse);
break;
case 3:
packet_type = elantech_packet_check_v3(psmouse);
switch (packet_type) {
case PACKET_UNKNOWN:
return PSMOUSE_BAD_DATA;
case PACKET_DEBOUNCE:
break;
case PACKET_TRACKPOINT:
elantech_report_trackpoint(psmouse, packet_type);
break;
default:
elantech_report_absolute_v3(psmouse, packet_type);
break;
}
break;
case 4:
packet_type = elantech_packet_check_v4(psmouse);
switch (packet_type) {
case PACKET_UNKNOWN:
return PSMOUSE_BAD_DATA;
case PACKET_TRACKPOINT:
elantech_report_trackpoint(psmouse, packet_type);
break;
default:
elantech_report_absolute_v4(psmouse, packet_type);
break;
}
break;
}
return PSMOUSE_FULL_PACKET;
}
static void elantech_set_rate_restore_reg_07(struct psmouse *psmouse,
unsigned int rate)
{
struct elantech_data *etd = psmouse->private;
etd->original_set_rate(psmouse, rate);
if (elantech_write_reg(psmouse, 0x07, etd->reg_07))
psmouse_err(psmouse, "restoring reg_07 failed\n");
}
static int elantech_set_absolute_mode(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
unsigned char val;
int tries = ETP_READ_BACK_TRIES;
int rc = 0;
switch (etd->hw_version) {
case 1:
etd->reg_10 = 0x16;
etd->reg_11 = 0x8f;
if (elantech_write_reg(psmouse, 0x10, etd->reg_10) ||
elantech_write_reg(psmouse, 0x11, etd->reg_11)) {
rc = -1;
}
break;
case 2:
etd->reg_10 = 0x54;
etd->reg_11 = 0x88;
etd->reg_21 = 0x60;
if (elantech_write_reg(psmouse, 0x10, etd->reg_10) ||
elantech_write_reg(psmouse, 0x11, etd->reg_11) ||
elantech_write_reg(psmouse, 0x21, etd->reg_21)) {
rc = -1;
}
break;
case 3:
if (etd->set_hw_resolution)
etd->reg_10 = 0x0b;
else
etd->reg_10 = 0x01;
if (elantech_write_reg(psmouse, 0x10, etd->reg_10))
rc = -1;
break;
case 4:
etd->reg_07 = 0x01;
if (elantech_write_reg(psmouse, 0x07, etd->reg_07))
rc = -1;
goto skip_readback_reg_10;
}
if (rc == 0) {
do {
rc = elantech_read_reg(psmouse, 0x10, &val);
if (rc == 0)
break;
tries--;
elantech_debug("retrying read (%d).\n", tries);
msleep(ETP_READ_BACK_DELAY);
} while (tries > 0);
if (rc) {
psmouse_err(psmouse,
"failed to read back register 0x10.\n");
} else if (etd->hw_version == 1 &&
!(val & ETP_R10_ABSOLUTE_MODE)) {
psmouse_err(psmouse,
"touchpad refuses to switch to absolute mode.\n");
rc = -1;
}
}
skip_readback_reg_10:
if (rc)
psmouse_err(psmouse, "failed to initialise registers.\n");
return rc;
}
static int elantech_set_range(struct psmouse *psmouse,
unsigned int *x_min, unsigned int *y_min,
unsigned int *x_max, unsigned int *y_max,
unsigned int *width)
{
struct elantech_data *etd = psmouse->private;
unsigned char param[3];
unsigned char traces;
switch (etd->hw_version) {
case 1:
*x_min = ETP_XMIN_V1;
*y_min = ETP_YMIN_V1;
*x_max = ETP_XMAX_V1;
*y_max = ETP_YMAX_V1;
break;
case 2:
if (etd->fw_version == 0x020800 ||
etd->fw_version == 0x020b00 ||
etd->fw_version == 0x020030) {
*x_min = ETP_XMIN_V2;
*y_min = ETP_YMIN_V2;
*x_max = ETP_XMAX_V2;
*y_max = ETP_YMAX_V2;
} else {
int i;
int fixed_dpi;
i = (etd->fw_version > 0x020800 &&
etd->fw_version < 0x020900) ? 1 : 2;
if (etd->send_cmd(psmouse, ETP_FW_ID_QUERY, param))
return -1;
fixed_dpi = param[1] & 0x10;
if (((etd->fw_version >> 16) == 0x14) && fixed_dpi) {
if (etd->send_cmd(psmouse, ETP_SAMPLE_QUERY, param))
return -1;
*x_max = (etd->capabilities[1] - i) * param[1] / 2;
*y_max = (etd->capabilities[2] - i) * param[2] / 2;
} else if (etd->fw_version == 0x040216) {
*x_max = 819;
*y_max = 405;
} else if (etd->fw_version == 0x040219 || etd->fw_version == 0x040215) {
*x_max = 900;
*y_max = 500;
} else {
*x_max = (etd->capabilities[1] - i) * 64;
*y_max = (etd->capabilities[2] - i) * 64;
}
}
break;
case 3:
if (etd->send_cmd(psmouse, ETP_FW_ID_QUERY, param))
return -1;
*x_max = (0x0f & param[0]) << 8 | param[1];
*y_max = (0xf0 & param[0]) << 4 | param[2];
break;
case 4:
if (etd->send_cmd(psmouse, ETP_FW_ID_QUERY, param))
return -1;
*x_max = (0x0f & param[0]) << 8 | param[1];
*y_max = (0xf0 & param[0]) << 4 | param[2];
traces = etd->capabilities[1];
if ((traces < 2) || (traces > *x_max))
return -1;
*width = *x_max / (traces - 1);
break;
}
return 0;
}
static unsigned int elantech_convert_res(unsigned int val)
{
return (val * 10 + 790) * 10 / 254;
}
static int elantech_get_resolution_v4(struct psmouse *psmouse,
unsigned int *x_res,
unsigned int *y_res)
{
unsigned char param[3];
if (elantech_send_cmd(psmouse, ETP_RESOLUTION_QUERY, param))
return -1;
*x_res = elantech_convert_res(param[1] & 0x0f);
*y_res = elantech_convert_res((param[1] & 0xf0) >> 4);
return 0;
}
static void elantech_set_buttonpad_prop(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
if (etd->fw_version & 0x001000) {
__set_bit(INPUT_PROP_BUTTONPAD, dev->propbit);
__clear_bit(BTN_RIGHT, dev->keybit);
}
}
static int elantech_set_input_params(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct elantech_data *etd = psmouse->private;
unsigned int x_min = 0, y_min = 0, x_max = 0, y_max = 0, width = 0;
unsigned int x_res = 31, y_res = 31;
if (elantech_set_range(psmouse, &x_min, &y_min, &x_max, &y_max, &width))
return -1;
__set_bit(INPUT_PROP_POINTER, dev->propbit);
__set_bit(EV_KEY, dev->evbit);
__set_bit(EV_ABS, dev->evbit);
__clear_bit(EV_REL, dev->evbit);
__set_bit(BTN_LEFT, dev->keybit);
if (dmi_check_system(elantech_dmi_has_middle_button))
__set_bit(BTN_MIDDLE, dev->keybit);
__set_bit(BTN_RIGHT, dev->keybit);
__set_bit(BTN_TOUCH, dev->keybit);
__set_bit(BTN_TOOL_FINGER, dev->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, dev->keybit);
__set_bit(BTN_TOOL_TRIPLETAP, dev->keybit);
switch (etd->hw_version) {
case 1:
if (etd->fw_version < 0x020000 &&
(etd->capabilities[0] & ETP_CAP_HAS_ROCKER)) {
__set_bit(BTN_FORWARD, dev->keybit);
__set_bit(BTN_BACK, dev->keybit);
}
input_set_abs_params(dev, ABS_X, x_min, x_max, 0, 0);
input_set_abs_params(dev, ABS_Y, y_min, y_max, 0, 0);
break;
case 2:
__set_bit(BTN_TOOL_QUADTAP, dev->keybit);
__set_bit(INPUT_PROP_SEMI_MT, dev->propbit);
case 3:
if (etd->hw_version == 3)
elantech_set_buttonpad_prop(psmouse);
input_set_abs_params(dev, ABS_X, x_min, x_max, 0, 0);
input_set_abs_params(dev, ABS_Y, y_min, y_max, 0, 0);
if (etd->reports_pressure) {
input_set_abs_params(dev, ABS_PRESSURE, ETP_PMIN_V2,
ETP_PMAX_V2, 0, 0);
input_set_abs_params(dev, ABS_TOOL_WIDTH, ETP_WMIN_V2,
ETP_WMAX_V2, 0, 0);
}
input_mt_init_slots(dev, 2, 0);
input_set_abs_params(dev, ABS_MT_POSITION_X, x_min, x_max, 0, 0);
input_set_abs_params(dev, ABS_MT_POSITION_Y, y_min, y_max, 0, 0);
break;
case 4:
if (elantech_get_resolution_v4(psmouse, &x_res, &y_res)) {
psmouse_warn(psmouse, "couldn't query resolution data.\n");
}
elantech_set_buttonpad_prop(psmouse);
__set_bit(BTN_TOOL_QUADTAP, dev->keybit);
input_set_abs_params(dev, ABS_X, x_min, x_max, 0, 0);
input_set_abs_params(dev, ABS_Y, y_min, y_max, 0, 0);
input_set_abs_params(dev, ABS_PRESSURE, ETP_PMIN_V2,
ETP_PMAX_V2, 0, 0);
input_set_abs_params(dev, ABS_TOOL_WIDTH, ETP_WMIN_V2,
ETP_WMAX_V2, 0, 0);
input_mt_init_slots(dev, ETP_MAX_FINGERS, 0);
input_set_abs_params(dev, ABS_MT_POSITION_X, x_min, x_max, 0, 0);
input_set_abs_params(dev, ABS_MT_POSITION_Y, y_min, y_max, 0, 0);
input_set_abs_params(dev, ABS_MT_PRESSURE, ETP_PMIN_V2,
ETP_PMAX_V2, 0, 0);
input_set_abs_params(dev, ABS_MT_TOUCH_MAJOR, 0,
ETP_WMAX_V2 * width, 0, 0);
break;
}
input_abs_set_res(dev, ABS_X, x_res);
input_abs_set_res(dev, ABS_Y, y_res);
if (etd->hw_version > 1) {
input_abs_set_res(dev, ABS_MT_POSITION_X, x_res);
input_abs_set_res(dev, ABS_MT_POSITION_Y, y_res);
}
etd->y_max = y_max;
etd->width = width;
return 0;
}
static ssize_t elantech_show_int_attr(struct psmouse *psmouse, void *data,
char *buf)
{
struct elantech_data *etd = psmouse->private;
struct elantech_attr_data *attr = data;
unsigned char *reg = (unsigned char *) etd + attr->field_offset;
int rc = 0;
if (attr->reg)
rc = elantech_read_reg(psmouse, attr->reg, reg);
return sprintf(buf, "0x%02x\n", (attr->reg && rc) ? -1 : *reg);
}
static ssize_t elantech_set_int_attr(struct psmouse *psmouse,
void *data, const char *buf, size_t count)
{
struct elantech_data *etd = psmouse->private;
struct elantech_attr_data *attr = data;
unsigned char *reg = (unsigned char *) etd + attr->field_offset;
unsigned char value;
int err;
err = kstrtou8(buf, 16, &value);
if (err)
return err;
if (etd->hw_version == 1) {
if (attr->reg == 0x10)
value |= ETP_R10_ABSOLUTE_MODE;
else if (attr->reg == 0x11)
value |= ETP_R11_4_BYTE_MODE;
}
if (!attr->reg || elantech_write_reg(psmouse, attr->reg, value) == 0)
*reg = value;
return count;
}
static bool elantech_is_signature_valid(const unsigned char *param)
{
static const unsigned char rates[] = { 200, 100, 80, 60, 40, 20, 10 };
int i;
if (param[0] == 0)
return false;
if (param[1] == 0)
return true;
if ((param[0] & 0x0f) >= 0x06 && (param[1] & 0xaf) == 0x0f &&
param[2] < 40)
return true;
for (i = 0; i < ARRAY_SIZE(rates); i++)
if (param[2] == rates[i])
return false;
return true;
}
int elantech_detect(struct psmouse *psmouse, bool set_properties)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[3];
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_RESET_DIS);
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO)) {
psmouse_dbg(psmouse, "sending Elantech magic knock failed.\n");
return -1;
}
if (param[0] != 0x3c || param[1] != 0x03 ||
(param[2] != 0xc8 && param[2] != 0x00)) {
psmouse_dbg(psmouse,
"unexpected magic knock result 0x%02x, 0x%02x, 0x%02x.\n",
param[0], param[1], param[2]);
return -1;
}
if (synaptics_send_cmd(psmouse, ETP_FW_VERSION_QUERY, param)) {
psmouse_dbg(psmouse, "failed to query firmware version.\n");
return -1;
}
psmouse_dbg(psmouse,
"Elantech version query result 0x%02x, 0x%02x, 0x%02x.\n",
param[0], param[1], param[2]);
if (!elantech_is_signature_valid(param)) {
psmouse_dbg(psmouse,
"Probably not a real Elantech touchpad. Aborting.\n");
return -1;
}
if (set_properties) {
psmouse->vendor = "Elantech";
psmouse->name = "Touchpad";
}
return 0;
}
static void elantech_disconnect(struct psmouse *psmouse)
{
struct elantech_data *etd = psmouse->private;
if (etd->tp_dev)
input_unregister_device(etd->tp_dev);
sysfs_remove_group(&psmouse->ps2dev.serio->dev.kobj,
&elantech_attr_group);
kfree(psmouse->private);
psmouse->private = NULL;
}
static int elantech_reconnect(struct psmouse *psmouse)
{
psmouse_reset(psmouse);
if (elantech_detect(psmouse, 0))
return -1;
if (elantech_set_absolute_mode(psmouse)) {
psmouse_err(psmouse,
"failed to put touchpad back into absolute mode.\n");
return -1;
}
return 0;
}
static int elantech_set_properties(struct elantech_data *etd)
{
int ver = (etd->fw_version & 0x0f0000) >> 16;
if (etd->fw_version < 0x020030 || etd->fw_version == 0x020600)
etd->hw_version = 1;
else {
switch (ver) {
case 2:
case 4:
etd->hw_version = 2;
break;
case 5:
etd->hw_version = 3;
break;
case 6:
case 7:
case 8:
case 9:
case 10:
case 13:
case 14:
etd->hw_version = 4;
break;
default:
return -1;
}
}
etd->send_cmd = etd->hw_version >= 3 ? elantech_send_cmd :
synaptics_send_cmd;
etd->paritycheck = 1;
etd->jumpy_cursor =
(etd->fw_version == 0x020022 || etd->fw_version == 0x020600);
if (etd->hw_version > 1) {
etd->debug = 1;
if (etd->fw_version >= 0x020800)
etd->reports_pressure = true;
}
etd->crc_enabled = (etd->fw_version & 0x4000) == 0x4000 ||
dmi_check_system(elantech_dmi_force_crc_enabled);
etd->set_hw_resolution = !dmi_check_system(no_hw_res_dmi_table);
return 0;
}
int elantech_init(struct psmouse *psmouse)
{
struct elantech_data *etd;
int i;
int error = -EINVAL;
unsigned char param[3];
struct input_dev *tp_dev;
psmouse->private = etd = kzalloc(sizeof(struct elantech_data), GFP_KERNEL);
if (!etd)
return -ENOMEM;
psmouse_reset(psmouse);
etd->parity[0] = 1;
for (i = 1; i < 256; i++)
etd->parity[i] = etd->parity[i & (i - 1)] ^ 1;
if (synaptics_send_cmd(psmouse, ETP_FW_VERSION_QUERY, param)) {
psmouse_err(psmouse, "failed to query firmware version.\n");
goto init_fail;
}
etd->fw_version = (param[0] << 16) | (param[1] << 8) | param[2];
if (elantech_set_properties(etd)) {
psmouse_err(psmouse, "unknown hardware version, aborting...\n");
goto init_fail;
}
psmouse_info(psmouse,
"assuming hardware version %d (with firmware version 0x%02x%02x%02x)\n",
etd->hw_version, param[0], param[1], param[2]);
if (etd->send_cmd(psmouse, ETP_CAPABILITIES_QUERY,
etd->capabilities)) {
psmouse_err(psmouse, "failed to query capabilities.\n");
goto init_fail;
}
psmouse_info(psmouse,
"Synaptics capabilities query result 0x%02x, 0x%02x, 0x%02x.\n",
etd->capabilities[0], etd->capabilities[1],
etd->capabilities[2]);
if (etd->hw_version != 1) {
if (etd->send_cmd(psmouse, ETP_SAMPLE_QUERY, etd->samples)) {
psmouse_err(psmouse, "failed to query sample data\n");
goto init_fail;
}
psmouse_info(psmouse,
"Elan sample query result %02x, %02x, %02x\n",
etd->samples[0], etd->samples[1], etd->samples[2]);
}
if (elantech_set_absolute_mode(psmouse)) {
psmouse_err(psmouse,
"failed to put touchpad into absolute mode.\n");
goto init_fail;
}
if (etd->fw_version == 0x381f17) {
etd->original_set_rate = psmouse->set_rate;
psmouse->set_rate = elantech_set_rate_restore_reg_07;
}
if (elantech_set_input_params(psmouse)) {
psmouse_err(psmouse, "failed to query touchpad range.\n");
goto init_fail;
}
error = sysfs_create_group(&psmouse->ps2dev.serio->dev.kobj,
&elantech_attr_group);
if (error) {
psmouse_err(psmouse,
"failed to create sysfs attributes, error: %d.\n",
error);
goto init_fail;
}
if ((etd->capabilities[0] & 0x80) == 0x80) {
tp_dev = input_allocate_device();
if (!tp_dev) {
error = -ENOMEM;
goto init_fail_tp_alloc;
}
etd->tp_dev = tp_dev;
snprintf(etd->tp_phys, sizeof(etd->tp_phys), "%s/input1",
psmouse->ps2dev.serio->phys);
tp_dev->phys = etd->tp_phys;
tp_dev->name = "Elantech PS/2 TrackPoint";
tp_dev->id.bustype = BUS_I8042;
tp_dev->id.vendor = 0x0002;
tp_dev->id.product = PSMOUSE_ELANTECH;
tp_dev->id.version = 0x0000;
tp_dev->dev.parent = &psmouse->ps2dev.serio->dev;
tp_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
tp_dev->relbit[BIT_WORD(REL_X)] =
BIT_MASK(REL_X) | BIT_MASK(REL_Y);
tp_dev->keybit[BIT_WORD(BTN_LEFT)] =
BIT_MASK(BTN_LEFT) | BIT_MASK(BTN_MIDDLE) |
BIT_MASK(BTN_RIGHT);
__set_bit(INPUT_PROP_POINTER, tp_dev->propbit);
__set_bit(INPUT_PROP_POINTING_STICK, tp_dev->propbit);
error = input_register_device(etd->tp_dev);
if (error < 0)
goto init_fail_tp_reg;
}
psmouse->protocol_handler = elantech_process_byte;
psmouse->disconnect = elantech_disconnect;
psmouse->reconnect = elantech_reconnect;
psmouse->pktsize = etd->hw_version > 1 ? 6 : 4;
return 0;
init_fail_tp_reg:
input_free_device(tp_dev);
init_fail_tp_alloc:
sysfs_remove_group(&psmouse->ps2dev.serio->dev.kobj,
&elantech_attr_group);
init_fail:
psmouse_reset(psmouse);
kfree(etd);
return error;
}
