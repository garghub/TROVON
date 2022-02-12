static bool alps_is_valid_first_byte(struct alps_data *priv,
unsigned char data)
{
return (data & priv->mask0) == priv->byte0;
}
static void alps_report_buttons(struct psmouse *psmouse,
struct input_dev *dev1, struct input_dev *dev2,
int left, int right, int middle)
{
struct input_dev *dev;
dev = test_bit(BTN_LEFT, dev2->key) ? dev2 : dev1;
input_report_key(dev, BTN_LEFT, left);
dev = test_bit(BTN_RIGHT, dev2->key) ? dev2 : dev1;
input_report_key(dev, BTN_RIGHT, right);
dev = test_bit(BTN_MIDDLE, dev2->key) ? dev2 : dev1;
input_report_key(dev, BTN_MIDDLE, middle);
input_sync(dev2);
}
static void alps_process_packet_v1_v2(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x, y, z, ges, fin, left, right, middle;
int back = 0, forward = 0;
if (priv->proto_version == ALPS_PROTO_V1) {
left = packet[2] & 0x10;
right = packet[2] & 0x08;
middle = 0;
x = packet[1] | ((packet[0] & 0x07) << 7);
y = packet[4] | ((packet[3] & 0x07) << 7);
z = packet[5];
} else {
left = packet[3] & 1;
right = packet[3] & 2;
middle = packet[3] & 4;
x = packet[1] | ((packet[2] & 0x78) << (7 - 3));
y = packet[4] | ((packet[3] & 0x70) << (7 - 4));
z = packet[5];
}
if (priv->flags & ALPS_FW_BK_1) {
back = packet[0] & 0x10;
forward = packet[2] & 4;
}
if (priv->flags & ALPS_FW_BK_2) {
back = packet[3] & 4;
forward = packet[2] & 4;
if ((middle = forward && back))
forward = back = 0;
}
ges = packet[2] & 1;
fin = packet[2] & 2;
if ((priv->flags & ALPS_DUALPOINT) && z == 127) {
input_report_rel(dev2, REL_X, (x > 383 ? (x - 768) : x));
input_report_rel(dev2, REL_Y, -(y > 255 ? (y - 512) : y));
alps_report_buttons(psmouse, dev2, dev, left, right, middle);
input_sync(dev2);
return;
}
alps_report_buttons(psmouse, dev, dev2, left, right, middle);
if (ges && !fin)
z = 40;
if (ges && fin && !priv->prev_fin) {
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
input_report_abs(dev, ABS_PRESSURE, 0);
input_report_key(dev, BTN_TOOL_FINGER, 0);
input_sync(dev);
}
priv->prev_fin = fin;
if (z > 30)
input_report_key(dev, BTN_TOUCH, 1);
if (z < 25)
input_report_key(dev, BTN_TOUCH, 0);
if (z > 0) {
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
}
input_report_abs(dev, ABS_PRESSURE, z);
input_report_key(dev, BTN_TOOL_FINGER, z > 0);
if (priv->flags & ALPS_WHEEL)
input_report_rel(dev, REL_WHEEL, ((packet[2] << 1) & 0x08) - ((packet[0] >> 4) & 0x07));
if (priv->flags & (ALPS_FW_BK_1 | ALPS_FW_BK_2)) {
input_report_key(dev, BTN_FORWARD, forward);
input_report_key(dev, BTN_BACK, back);
}
if (priv->flags & ALPS_FOUR_BUTTONS) {
input_report_key(dev, BTN_0, packet[2] & 4);
input_report_key(dev, BTN_1, packet[0] & 0x10);
input_report_key(dev, BTN_2, packet[3] & 4);
input_report_key(dev, BTN_3, packet[0] & 0x20);
}
input_sync(dev);
}
static int alps_process_bitmap(struct alps_data *priv,
unsigned int x_map, unsigned int y_map,
int *x1, int *y1, int *x2, int *y2)
{
struct alps_bitmap_point {
int start_bit;
int num_bits;
};
int fingers_x = 0, fingers_y = 0, fingers;
int i, bit, prev_bit;
struct alps_bitmap_point x_low = {0,}, x_high = {0,};
struct alps_bitmap_point y_low = {0,}, y_high = {0,};
struct alps_bitmap_point *point;
if (!x_map || !y_map)
return 0;
*x1 = *y1 = *x2 = *y2 = 0;
prev_bit = 0;
point = &x_low;
for (i = 0; x_map != 0; i++, x_map >>= 1) {
bit = x_map & 1;
if (bit) {
if (!prev_bit) {
point->start_bit = i;
fingers_x++;
}
point->num_bits++;
} else {
if (prev_bit)
point = &x_high;
else
point->num_bits = 0;
}
prev_bit = bit;
}
y_map = y_map << (sizeof(y_map) * BITS_PER_BYTE - priv->y_bits);
prev_bit = 0;
point = &y_low;
for (i = 0; y_map != 0; i++, y_map <<= 1) {
bit = y_map & (1 << (sizeof(y_map) * BITS_PER_BYTE - 1));
if (bit) {
if (!prev_bit) {
point->start_bit = i;
fingers_y++;
}
point->num_bits++;
} else {
if (prev_bit)
point = &y_high;
else
point->num_bits = 0;
}
prev_bit = bit;
}
fingers = max(fingers_x, fingers_y);
if (fingers > 1) {
if (fingers_x == 1) {
i = x_low.num_bits / 2;
x_low.num_bits = x_low.num_bits - i;
x_high.start_bit = x_low.start_bit + i;
x_high.num_bits = max(i, 1);
} else if (fingers_y == 1) {
i = y_low.num_bits / 2;
y_low.num_bits = y_low.num_bits - i;
y_high.start_bit = y_low.start_bit + i;
y_high.num_bits = max(i, 1);
}
}
*x1 = (priv->x_max * (2 * x_low.start_bit + x_low.num_bits - 1)) /
(2 * (priv->x_bits - 1));
*y1 = (priv->y_max * (2 * y_low.start_bit + y_low.num_bits - 1)) /
(2 * (priv->y_bits - 1));
if (fingers > 1) {
*x2 = (priv->x_max *
(2 * x_high.start_bit + x_high.num_bits - 1)) /
(2 * (priv->x_bits - 1));
*y2 = (priv->y_max *
(2 * y_high.start_bit + y_high.num_bits - 1)) /
(2 * (priv->y_bits - 1));
}
return fingers;
}
static void alps_set_slot(struct input_dev *dev, int slot, bool active,
int x, int y)
{
input_mt_slot(dev, slot);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, active);
if (active) {
input_report_abs(dev, ABS_MT_POSITION_X, x);
input_report_abs(dev, ABS_MT_POSITION_Y, y);
}
}
static void alps_report_semi_mt_data(struct input_dev *dev, int num_fingers,
int x1, int y1, int x2, int y2)
{
alps_set_slot(dev, 0, num_fingers != 0, x1, y1);
alps_set_slot(dev, 1, num_fingers == 2, x2, y2);
}
static void alps_process_trackstick_packet_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = priv->dev2;
int x, y, z, left, right, middle;
if (!(packet[0] & 0x40)) {
psmouse_dbg(psmouse, "Bad trackstick packet, discarding\n");
return;
}
if (packet[1] == 0x7f && packet[2] == 0x7f && packet[4] == 0x7f)
return;
x = (s8)(((packet[0] & 0x20) << 2) | (packet[1] & 0x7f));
y = (s8)(((packet[0] & 0x10) << 3) | (packet[2] & 0x7f));
z = (packet[4] & 0x7c) >> 2;
x /= 8;
y /= 8;
input_report_rel(dev, REL_X, x);
input_report_rel(dev, REL_Y, -y);
left = packet[3] & 0x01;
right = packet[3] & 0x02;
middle = packet[3] & 0x04;
if (!(priv->quirks & ALPS_QUIRK_TRACKSTICK_BUTTONS) &&
(left || right || middle))
priv->quirks |= ALPS_QUIRK_TRACKSTICK_BUTTONS;
if (priv->quirks & ALPS_QUIRK_TRACKSTICK_BUTTONS) {
input_report_key(dev, BTN_LEFT, left);
input_report_key(dev, BTN_RIGHT, right);
input_report_key(dev, BTN_MIDDLE, middle);
}
input_sync(dev);
return;
}
static void alps_decode_buttons_v3(struct alps_fields *f, unsigned char *p)
{
f->left = !!(p[3] & 0x01);
f->right = !!(p[3] & 0x02);
f->middle = !!(p[3] & 0x04);
f->ts_left = !!(p[3] & 0x10);
f->ts_right = !!(p[3] & 0x20);
f->ts_middle = !!(p[3] & 0x40);
}
static void alps_decode_pinnacle(struct alps_fields *f, unsigned char *p)
{
f->first_mp = !!(p[4] & 0x40);
f->is_mp = !!(p[0] & 0x40);
f->fingers = (p[5] & 0x3) + 1;
f->x_map = ((p[4] & 0x7e) << 8) |
((p[1] & 0x7f) << 2) |
((p[0] & 0x30) >> 4);
f->y_map = ((p[3] & 0x70) << 4) |
((p[2] & 0x7f) << 1) |
(p[4] & 0x01);
f->x = ((p[1] & 0x7f) << 4) | ((p[4] & 0x30) >> 2) |
((p[0] & 0x30) >> 4);
f->y = ((p[2] & 0x7f) << 4) | (p[4] & 0x0f);
f->z = p[5] & 0x7f;
alps_decode_buttons_v3(f, p);
}
static void alps_decode_rushmore(struct alps_fields *f, unsigned char *p)
{
alps_decode_pinnacle(f, p);
f->x_map |= (p[5] & 0x10) << 11;
f->y_map |= (p[5] & 0x20) << 6;
}
static void alps_decode_dolphin(struct alps_fields *f, unsigned char *p)
{
f->first_mp = !!(p[0] & 0x02);
f->is_mp = !!(p[0] & 0x20);
f->fingers = ((p[0] & 0x6) >> 1 |
(p[0] & 0x10) >> 2);
f->x_map = ((p[2] & 0x60) >> 5) |
((p[4] & 0x7f) << 2) |
((p[5] & 0x7f) << 9) |
((p[3] & 0x07) << 16) |
((p[3] & 0x70) << 15) |
((p[0] & 0x01) << 22);
f->y_map = (p[1] & 0x7f) |
((p[2] & 0x1f) << 7);
f->x = ((p[1] & 0x7f) | ((p[4] & 0x0f) << 7));
f->y = ((p[2] & 0x7f) | ((p[4] & 0xf0) << 3));
f->z = (p[0] & 4) ? 0 : p[5] & 0x7f;
alps_decode_buttons_v3(f, p);
}
static void alps_process_touchpad_packet_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
int fingers = 0, bmap_fingers;
struct alps_fields f;
priv->decode_fields(&f, packet);
if (priv->multi_packet) {
if (f.is_mp) {
fingers = f.fingers;
bmap_fingers = alps_process_bitmap(priv,
f.x_map, f.y_map,
&x1, &y1, &x2, &y2);
if (fingers > 1 && bmap_fingers < 2)
fingers = bmap_fingers;
priv->decode_fields(&f, priv->multi_data);
} else {
priv->multi_packet = 0;
}
}
if (f.is_mp)
return;
if (!priv->multi_packet && f.first_mp) {
priv->multi_packet = 1;
memcpy(priv->multi_data, packet, sizeof(priv->multi_data));
return;
}
priv->multi_packet = 0;
if (f.x && f.y && !f.z)
return;
if (!fingers) {
x1 = f.x;
y1 = f.y;
fingers = f.z > 0 ? 1 : 0;
}
if (f.z >= 64)
input_report_key(dev, BTN_TOUCH, 1);
else
input_report_key(dev, BTN_TOUCH, 0);
alps_report_semi_mt_data(dev, fingers, x1, y1, x2, y2);
input_mt_report_finger_count(dev, fingers);
input_report_key(dev, BTN_LEFT, f.left);
input_report_key(dev, BTN_RIGHT, f.right);
input_report_key(dev, BTN_MIDDLE, f.middle);
if (f.z > 0) {
input_report_abs(dev, ABS_X, f.x);
input_report_abs(dev, ABS_Y, f.y);
}
input_report_abs(dev, ABS_PRESSURE, f.z);
input_sync(dev);
if (!(priv->quirks & ALPS_QUIRK_TRACKSTICK_BUTTONS)) {
input_report_key(dev2, BTN_LEFT, f.ts_left);
input_report_key(dev2, BTN_RIGHT, f.ts_right);
input_report_key(dev2, BTN_MIDDLE, f.ts_middle);
input_sync(dev2);
}
}
static void alps_process_packet_v3(struct psmouse *psmouse)
{
unsigned char *packet = psmouse->packet;
if (packet[5] == 0x3f) {
alps_process_trackstick_packet_v3(psmouse);
return;
}
alps_process_touchpad_packet_v3(psmouse);
}
static void alps_process_packet_v4(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
int offset;
int x, y, z;
int left, right;
int x1, y1, x2, y2;
int fingers = 0;
unsigned int x_bitmap, y_bitmap;
if (packet[6] & 0x40) {
priv->multi_packet = 0;
}
if (WARN_ON_ONCE(priv->multi_packet > 2))
return;
offset = 2 * priv->multi_packet;
priv->multi_data[offset] = packet[6];
priv->multi_data[offset + 1] = packet[7];
if (++priv->multi_packet > 2) {
priv->multi_packet = 0;
x_bitmap = ((priv->multi_data[2] & 0x1f) << 10) |
((priv->multi_data[3] & 0x60) << 3) |
((priv->multi_data[0] & 0x3f) << 2) |
((priv->multi_data[1] & 0x60) >> 5);
y_bitmap = ((priv->multi_data[5] & 0x01) << 10) |
((priv->multi_data[3] & 0x1f) << 5) |
(priv->multi_data[1] & 0x1f);
fingers = alps_process_bitmap(priv, x_bitmap, y_bitmap,
&x1, &y1, &x2, &y2);
priv->fingers = fingers;
priv->x1 = x1;
priv->x2 = x2;
priv->y1 = y1;
priv->y2 = y2;
}
left = packet[4] & 0x01;
right = packet[4] & 0x02;
x = ((packet[1] & 0x7f) << 4) | ((packet[3] & 0x30) >> 2) |
((packet[0] & 0x30) >> 4);
y = ((packet[2] & 0x7f) << 4) | (packet[3] & 0x0f);
z = packet[5] & 0x7f;
if (priv->fingers < 2) {
x1 = x;
y1 = y;
fingers = z > 0 ? 1 : 0;
} else {
fingers = priv->fingers;
x1 = priv->x1;
x2 = priv->x2;
y1 = priv->y1;
y2 = priv->y2;
}
if (z >= 64)
input_report_key(dev, BTN_TOUCH, 1);
else
input_report_key(dev, BTN_TOUCH, 0);
alps_report_semi_mt_data(dev, fingers, x1, y1, x2, y2);
input_mt_report_finger_count(dev, fingers);
input_report_key(dev, BTN_LEFT, left);
input_report_key(dev, BTN_RIGHT, right);
if (z > 0) {
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
}
input_report_abs(dev, ABS_PRESSURE, z);
input_sync(dev);
}
static void alps_report_bare_ps2_packet(struct psmouse *psmouse,
unsigned char packet[],
bool report_buttons)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev2 = priv->dev2;
if (report_buttons)
alps_report_buttons(psmouse, dev2, psmouse->dev,
packet[0] & 1, packet[0] & 2, packet[0] & 4);
input_report_rel(dev2, REL_X,
packet[1] ? packet[1] - ((packet[0] << 4) & 0x100) : 0);
input_report_rel(dev2, REL_Y,
packet[2] ? ((packet[0] << 3) & 0x100) - packet[2] : 0);
input_sync(dev2);
}
static psmouse_ret_t alps_handle_interleaved_ps2(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
if (psmouse->pktcnt < 6)
return PSMOUSE_GOOD_DATA;
if (psmouse->pktcnt == 6) {
mod_timer(&priv->timer, jiffies + msecs_to_jiffies(20));
return PSMOUSE_GOOD_DATA;
}
del_timer(&priv->timer);
if (psmouse->packet[6] & 0x80) {
if (((psmouse->packet[3] |
psmouse->packet[4] |
psmouse->packet[5]) & 0x80) ||
(!alps_is_valid_first_byte(priv, psmouse->packet[6]))) {
psmouse_dbg(psmouse,
"refusing packet %4ph (suspected interleaved ps/2)\n",
psmouse->packet + 3);
return PSMOUSE_BAD_DATA;
}
priv->process_packet(psmouse);
psmouse->packet[0] = psmouse->packet[6];
psmouse->pktcnt = 1;
} else {
alps_report_bare_ps2_packet(psmouse, &psmouse->packet[3],
false);
psmouse->packet[3] = psmouse->packet[6] & 0xf7;
psmouse->pktcnt = 4;
}
return PSMOUSE_GOOD_DATA;
}
static void alps_flush_packet(unsigned long data)
{
struct psmouse *psmouse = (struct psmouse *)data;
struct alps_data *priv = psmouse->private;
serio_pause_rx(psmouse->ps2dev.serio);
if (psmouse->pktcnt == psmouse->pktsize) {
if ((psmouse->packet[3] |
psmouse->packet[4] |
psmouse->packet[5]) & 0x80) {
psmouse_dbg(psmouse,
"refusing packet %3ph (suspected interleaved ps/2)\n",
psmouse->packet + 3);
} else {
priv->process_packet(psmouse);
}
psmouse->pktcnt = 0;
}
serio_continue_rx(psmouse->ps2dev.serio);
}
static psmouse_ret_t alps_process_byte(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
if ((psmouse->packet[0] & 0xc8) == 0x08) {
if (psmouse->pktcnt == 3) {
alps_report_bare_ps2_packet(psmouse, psmouse->packet,
true);
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_GOOD_DATA;
}
if ((priv->flags & ALPS_PS2_INTERLEAVED) &&
psmouse->pktcnt >= 4 && (psmouse->packet[3] & 0x0f) == 0x0f) {
return alps_handle_interleaved_ps2(psmouse);
}
if (!alps_is_valid_first_byte(priv, psmouse->packet[0])) {
psmouse_dbg(psmouse,
"refusing packet[0] = %x (mask0 = %x, byte0 = %x)\n",
psmouse->packet[0], priv->mask0, priv->byte0);
return PSMOUSE_BAD_DATA;
}
if (priv->proto_version != ALPS_PROTO_V5 &&
psmouse->pktcnt >= 2 && psmouse->pktcnt <= psmouse->pktsize &&
(psmouse->packet[psmouse->pktcnt - 1] & 0x80)) {
psmouse_dbg(psmouse, "refusing packet[%i] = %x\n",
psmouse->pktcnt - 1,
psmouse->packet[psmouse->pktcnt - 1]);
return PSMOUSE_BAD_DATA;
}
if (psmouse->pktcnt == psmouse->pktsize) {
priv->process_packet(psmouse);
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_GOOD_DATA;
}
static int alps_command_mode_send_nibble(struct psmouse *psmouse, int nibble)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct alps_data *priv = psmouse->private;
int command;
unsigned char *param;
unsigned char dummy[4];
BUG_ON(nibble > 0xf);
command = priv->nibble_commands[nibble].command;
param = (command & 0x0f00) ?
dummy : (unsigned char *)&priv->nibble_commands[nibble].data;
if (ps2_command(ps2dev, param, command))
return -1;
return 0;
}
static int alps_command_mode_set_addr(struct psmouse *psmouse, int addr)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct alps_data *priv = psmouse->private;
int i, nibble;
if (ps2_command(ps2dev, NULL, priv->addr_command))
return -1;
for (i = 12; i >= 0; i -= 4) {
nibble = (addr >> i) & 0xf;
if (alps_command_mode_send_nibble(psmouse, nibble))
return -1;
}
return 0;
}
static int __alps_command_mode_read_reg(struct psmouse *psmouse, int addr)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4];
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return -1;
if (addr != ((param[0] << 8) | param[1]))
return -1;
return param[2];
}
static int alps_command_mode_read_reg(struct psmouse *psmouse, int addr)
{
if (alps_command_mode_set_addr(psmouse, addr))
return -1;
return __alps_command_mode_read_reg(psmouse, addr);
}
static int __alps_command_mode_write_reg(struct psmouse *psmouse, u8 value)
{
if (alps_command_mode_send_nibble(psmouse, (value >> 4) & 0xf))
return -1;
if (alps_command_mode_send_nibble(psmouse, value & 0xf))
return -1;
return 0;
}
static int alps_command_mode_write_reg(struct psmouse *psmouse, int addr,
u8 value)
{
if (alps_command_mode_set_addr(psmouse, addr))
return -1;
return __alps_command_mode_write_reg(psmouse, value);
}
static int alps_rpt_cmd(struct psmouse *psmouse, int init_command,
int repeated_command, unsigned char *param)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
param[0] = 0;
if (init_command && ps2_command(ps2dev, param, init_command))
return -EIO;
if (ps2_command(ps2dev, NULL, repeated_command) ||
ps2_command(ps2dev, NULL, repeated_command) ||
ps2_command(ps2dev, NULL, repeated_command))
return -EIO;
param[0] = param[1] = param[2] = 0xff;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return -EIO;
psmouse_dbg(psmouse, "%2.2X report: %3ph\n",
repeated_command, param);
return 0;
}
static int alps_enter_command_mode(struct psmouse *psmouse)
{
unsigned char param[4];
if (alps_rpt_cmd(psmouse, 0, PSMOUSE_CMD_RESET_WRAP, param)) {
psmouse_err(psmouse, "failed to enter command mode\n");
return -1;
}
if ((param[0] != 0x88 || (param[1] != 0x07 && param[1] != 0x08)) &&
param[0] != 0x73) {
psmouse_dbg(psmouse,
"unknown response while entering command mode\n");
return -1;
}
return 0;
}
static inline int alps_exit_command_mode(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM))
return -1;
return 0;
}
static int alps_passthrough_mode_v2(struct psmouse *psmouse, bool enable)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int cmd = enable ? PSMOUSE_CMD_SETSCALE21 : PSMOUSE_CMD_SETSCALE11;
if (ps2_command(ps2dev, NULL, cmd) ||
ps2_command(ps2dev, NULL, cmd) ||
ps2_command(ps2dev, NULL, cmd) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE))
return -1;
ps2_drain(ps2dev, 3, 100);
return 0;
}
static int alps_absolute_mode_v1_v2(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE))
return -1;
return ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETPOLL);
}
static int alps_get_status(struct psmouse *psmouse, char *param)
{
if (alps_rpt_cmd(psmouse, 0, PSMOUSE_CMD_DISABLE, param))
return -1;
return 0;
}
static int alps_tap_mode(struct psmouse *psmouse, int enable)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int cmd = enable ? PSMOUSE_CMD_SETRATE : PSMOUSE_CMD_SETRES;
unsigned char tap_arg = enable ? 0x0A : 0x00;
unsigned char param[4];
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, &tap_arg, cmd))
return -1;
if (alps_get_status(psmouse, param))
return -1;
return 0;
}
static int alps_poll(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char buf[sizeof(psmouse->packet)];
bool poll_failed;
if (priv->flags & ALPS_PASS)
alps_passthrough_mode_v2(psmouse, true);
poll_failed = ps2_command(&psmouse->ps2dev, buf,
PSMOUSE_CMD_POLL | (psmouse->pktsize << 8)) < 0;
if (priv->flags & ALPS_PASS)
alps_passthrough_mode_v2(psmouse, false);
if (poll_failed || (buf[0] & priv->mask0) != priv->byte0)
return -1;
if ((psmouse->badbyte & 0xc8) == 0x08) {
if (ps2_command(&psmouse->ps2dev, buf, PSMOUSE_CMD_POLL | (3 << 8)))
return -1;
}
memcpy(psmouse->packet, buf, sizeof(buf));
return 0;
}
static int alps_hw_init_v1_v2(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
if ((priv->flags & ALPS_PASS) &&
alps_passthrough_mode_v2(psmouse, true)) {
return -1;
}
if (alps_tap_mode(psmouse, true)) {
psmouse_warn(psmouse, "Failed to enable hardware tapping\n");
return -1;
}
if (alps_absolute_mode_v1_v2(psmouse)) {
psmouse_err(psmouse, "Failed to enable absolute mode\n");
return -1;
}
if ((priv->flags & ALPS_PASS) &&
alps_passthrough_mode_v2(psmouse, false)) {
return -1;
}
if (ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSTREAM)) {
psmouse_err(psmouse, "Failed to enable stream mode\n");
return -1;
}
return 0;
}
static int alps_passthrough_mode_v3(struct psmouse *psmouse,
int reg_base, bool enable)
{
int reg_val, ret = -1;
if (alps_enter_command_mode(psmouse))
return -1;
reg_val = alps_command_mode_read_reg(psmouse, reg_base + 0x0008);
if (reg_val == -1)
goto error;
if (enable)
reg_val |= 0x01;
else
reg_val &= ~0x01;
ret = __alps_command_mode_write_reg(psmouse, reg_val);
error:
if (alps_exit_command_mode(psmouse))
ret = -1;
return ret;
}
static int alps_absolute_mode_v3(struct psmouse *psmouse)
{
int reg_val;
reg_val = alps_command_mode_read_reg(psmouse, 0x0004);
if (reg_val == -1)
return -1;
reg_val |= 0x06;
if (__alps_command_mode_write_reg(psmouse, reg_val))
return -1;
return 0;
}
static int alps_probe_trackstick_v3(struct psmouse *psmouse, int reg_base)
{
int ret = -EIO, reg_val;
if (alps_enter_command_mode(psmouse))
goto error;
reg_val = alps_command_mode_read_reg(psmouse, reg_base + 0x08);
if (reg_val == -1)
goto error;
ret = reg_val & 0x80 ? 0 : -ENODEV;
error:
alps_exit_command_mode(psmouse);
return ret;
}
static int alps_setup_trackstick_v3(struct psmouse *psmouse, int reg_base)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int ret = 0;
unsigned char param[4];
if (alps_passthrough_mode_v3(psmouse, reg_base, true))
return -EIO;
if (alps_rpt_cmd(psmouse, 0, PSMOUSE_CMD_SETSCALE21, param)) {
psmouse_warn(psmouse, "trackstick E7 report failed\n");
ret = -ENODEV;
} else {
psmouse_dbg(psmouse, "trackstick E7 report: %3ph\n", param);
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
alps_command_mode_send_nibble(psmouse, 0x9) ||
alps_command_mode_send_nibble(psmouse, 0x4)) {
psmouse_err(psmouse,
"Error sending magic E6 sequence\n");
ret = -EIO;
goto error;
}
if (alps_enter_command_mode(psmouse) ||
alps_command_mode_write_reg(psmouse,
reg_base + 0x08, 0x82) ||
alps_exit_command_mode(psmouse))
ret = -EIO;
}
error:
if (alps_passthrough_mode_v3(psmouse, reg_base, false))
ret = -EIO;
return ret;
}
static int alps_hw_init_v3(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int reg_val;
unsigned char param[4];
reg_val = alps_probe_trackstick_v3(psmouse, ALPS_REG_BASE_PINNACLE);
if (reg_val == -EIO)
goto error;
if (reg_val == 0 &&
alps_setup_trackstick_v3(psmouse, ALPS_REG_BASE_PINNACLE) == -EIO)
goto error;
if (alps_enter_command_mode(psmouse) ||
alps_absolute_mode_v3(psmouse)) {
psmouse_err(psmouse, "Failed to enter absolute mode\n");
goto error;
}
reg_val = alps_command_mode_read_reg(psmouse, 0x0006);
if (reg_val == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, reg_val | 0x01))
goto error;
reg_val = alps_command_mode_read_reg(psmouse, 0x0007);
if (reg_val == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, reg_val | 0x01))
goto error;
if (alps_command_mode_read_reg(psmouse, 0x0144) == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, 0x04))
goto error;
if (alps_command_mode_read_reg(psmouse, 0x0159) == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, 0x03))
goto error;
if (alps_command_mode_read_reg(psmouse, 0x0163) == -1)
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0163, 0x03))
goto error;
if (alps_command_mode_read_reg(psmouse, 0x0162) == -1)
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0162, 0x04))
goto error;
alps_exit_command_mode(psmouse);
param[0] = 0x64;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE)) {
psmouse_err(psmouse, "Failed to enable data reporting\n");
return -1;
}
return 0;
error:
alps_exit_command_mode(psmouse);
return -1;
}
static int alps_hw_init_rushmore_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
struct ps2dev *ps2dev = &psmouse->ps2dev;
int reg_val, ret = -1;
if (priv->flags & ALPS_DUALPOINT) {
reg_val = alps_setup_trackstick_v3(psmouse,
ALPS_REG_BASE_RUSHMORE);
if (reg_val == -EIO)
goto error;
if (reg_val == -ENODEV)
priv->flags &= ~ALPS_DUALPOINT;
}
if (alps_enter_command_mode(psmouse) ||
alps_command_mode_read_reg(psmouse, 0xc2d9) == -1 ||
alps_command_mode_write_reg(psmouse, 0xc2cb, 0x00))
goto error;
reg_val = alps_command_mode_read_reg(psmouse, 0xc2c6);
if (reg_val == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, reg_val & 0xfd))
goto error;
if (alps_command_mode_write_reg(psmouse, 0xc2c9, 0x64))
goto error;
reg_val = alps_command_mode_read_reg(psmouse, 0xc2c4);
if (reg_val == -1)
goto error;
if (__alps_command_mode_write_reg(psmouse, reg_val | 0x02))
goto error;
alps_exit_command_mode(psmouse);
return ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE);
error:
alps_exit_command_mode(psmouse);
return ret;
}
static int alps_absolute_mode_v4(struct psmouse *psmouse)
{
int reg_val;
reg_val = alps_command_mode_read_reg(psmouse, 0x0004);
if (reg_val == -1)
return -1;
reg_val |= 0x02;
if (__alps_command_mode_write_reg(psmouse, reg_val))
return -1;
return 0;
}
static int alps_hw_init_v4(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4];
if (alps_enter_command_mode(psmouse))
goto error;
if (alps_absolute_mode_v4(psmouse)) {
psmouse_err(psmouse, "Failed to enter absolute mode\n");
goto error;
}
if (alps_command_mode_write_reg(psmouse, 0x0007, 0x8c))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0149, 0x03))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0160, 0x03))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x017f, 0x15))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0151, 0x01))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0168, 0x03))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x014a, 0x03))
goto error;
if (alps_command_mode_write_reg(psmouse, 0x0161, 0x03))
goto error;
alps_exit_command_mode(psmouse);
param[0] = 0xc8;
param[1] = 0x64;
param[2] = 0x50;
if (ps2_command(ps2dev, &param[0], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, &param[1], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, &param[2], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETID))
return -1;
param[0] = 0x64;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE)) {
psmouse_err(psmouse, "Failed to enable data reporting\n");
return -1;
}
return 0;
error:
alps_exit_command_mode(psmouse);
return -1;
}
static int alps_hw_init_dolphin_v1(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[2];
param[0] = 0x64;
param[1] = 0x28;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM) ||
ps2_command(ps2dev, &param[0], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, &param[1], PSMOUSE_CMD_SETRATE))
return -1;
return 0;
}
static void alps_set_defaults(struct alps_data *priv)
{
priv->byte0 = 0x8f;
priv->mask0 = 0x8f;
priv->flags = ALPS_DUALPOINT;
priv->x_max = 2000;
priv->y_max = 1400;
priv->x_bits = 15;
priv->y_bits = 11;
switch (priv->proto_version) {
case ALPS_PROTO_V1:
case ALPS_PROTO_V2:
priv->hw_init = alps_hw_init_v1_v2;
priv->process_packet = alps_process_packet_v1_v2;
priv->set_abs_params = alps_set_abs_params_st;
break;
case ALPS_PROTO_V3:
priv->hw_init = alps_hw_init_v3;
priv->process_packet = alps_process_packet_v3;
priv->set_abs_params = alps_set_abs_params_mt;
priv->decode_fields = alps_decode_pinnacle;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
break;
case ALPS_PROTO_V4:
priv->hw_init = alps_hw_init_v4;
priv->process_packet = alps_process_packet_v4;
priv->set_abs_params = alps_set_abs_params_mt;
priv->nibble_commands = alps_v4_nibble_commands;
priv->addr_command = PSMOUSE_CMD_DISABLE;
break;
case ALPS_PROTO_V5:
priv->hw_init = alps_hw_init_dolphin_v1;
priv->process_packet = alps_process_packet_v3;
priv->decode_fields = alps_decode_dolphin;
priv->set_abs_params = alps_set_abs_params_mt;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
priv->byte0 = 0xc8;
priv->mask0 = 0xc8;
priv->flags = 0;
priv->x_max = 1360;
priv->y_max = 660;
priv->x_bits = 23;
priv->y_bits = 12;
break;
}
}
static int alps_match_table(struct psmouse *psmouse, struct alps_data *priv,
unsigned char *e7, unsigned char *ec)
{
const struct alps_model_info *model;
int i;
for (i = 0; i < ARRAY_SIZE(alps_model_data); i++) {
model = &alps_model_data[i];
if (!memcmp(e7, model->signature, sizeof(model->signature)) &&
(!model->command_mode_resp ||
model->command_mode_resp == ec[2])) {
priv->proto_version = model->proto_version;
alps_set_defaults(priv);
priv->flags = model->flags;
priv->byte0 = model->byte0;
priv->mask0 = model->mask0;
return 0;
}
}
return -EINVAL;
}
static int alps_identify(struct psmouse *psmouse, struct alps_data *priv)
{
unsigned char e6[4], e7[4], ec[4];
if (alps_rpt_cmd(psmouse, PSMOUSE_CMD_SETRES,
PSMOUSE_CMD_SETSCALE11, e6))
return -EIO;
if ((e6[0] & 0xf8) != 0 || e6[1] != 0 || (e6[2] != 10 && e6[2] != 100))
return -EINVAL;
if (alps_rpt_cmd(psmouse, PSMOUSE_CMD_SETRES,
PSMOUSE_CMD_SETSCALE21, e7) ||
alps_rpt_cmd(psmouse, PSMOUSE_CMD_SETRES,
PSMOUSE_CMD_RESET_WRAP, ec) ||
alps_exit_command_mode(psmouse))
return -EIO;
if (alps_match_table(psmouse, priv, e7, ec) == 0) {
return 0;
} else if (e7[0] == 0x73 && e7[1] == 0x03 && e7[2] == 0x50 &&
ec[0] == 0x73 && ec[1] == 0x01) {
priv->proto_version = ALPS_PROTO_V5;
alps_set_defaults(priv);
return 0;
} else if (ec[0] == 0x88 && ec[1] == 0x08) {
priv->proto_version = ALPS_PROTO_V3;
alps_set_defaults(priv);
priv->hw_init = alps_hw_init_rushmore_v3;
priv->decode_fields = alps_decode_rushmore;
priv->x_bits = 16;
priv->y_bits = 12;
psmouse->private = priv;
if (alps_probe_trackstick_v3(psmouse, ALPS_REG_BASE_RUSHMORE))
priv->flags &= ~ALPS_DUALPOINT;
return 0;
} else if (ec[0] == 0x88 && ec[1] == 0x07 &&
ec[2] >= 0x90 && ec[2] <= 0x9d) {
priv->proto_version = ALPS_PROTO_V3;
alps_set_defaults(priv);
return 0;
}
psmouse_info(psmouse,
"Unknown ALPS touchpad: E7=%3ph, EC=%3ph\n", e7, ec);
return -EINVAL;
}
static int alps_reconnect(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
psmouse_reset(psmouse);
if (alps_identify(psmouse, priv) < 0)
return -1;
return priv->hw_init(psmouse);
}
static void alps_disconnect(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
psmouse_reset(psmouse);
del_timer_sync(&priv->timer);
input_unregister_device(priv->dev2);
kfree(priv);
}
static void alps_set_abs_params_st(struct alps_data *priv,
struct input_dev *dev1)
{
input_set_abs_params(dev1, ABS_X, 0, 1023, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, 767, 0, 0);
}
static void alps_set_abs_params_mt(struct alps_data *priv,
struct input_dev *dev1)
{
set_bit(INPUT_PROP_SEMI_MT, dev1->propbit);
input_mt_init_slots(dev1, 2, 0);
input_set_abs_params(dev1, ABS_MT_POSITION_X, 0, priv->x_max, 0, 0);
input_set_abs_params(dev1, ABS_MT_POSITION_Y, 0, priv->y_max, 0, 0);
set_bit(BTN_TOOL_DOUBLETAP, dev1->keybit);
set_bit(BTN_TOOL_TRIPLETAP, dev1->keybit);
set_bit(BTN_TOOL_QUADTAP, dev1->keybit);
input_set_abs_params(dev1, ABS_X, 0, priv->x_max, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, priv->y_max, 0, 0);
}
int alps_init(struct psmouse *psmouse)
{
struct alps_data *priv;
struct input_dev *dev1 = psmouse->dev, *dev2;
priv = kzalloc(sizeof(struct alps_data), GFP_KERNEL);
dev2 = input_allocate_device();
if (!priv || !dev2)
goto init_fail;
priv->dev2 = dev2;
setup_timer(&priv->timer, alps_flush_packet, (unsigned long)psmouse);
psmouse->private = priv;
psmouse_reset(psmouse);
if (alps_identify(psmouse, priv) < 0)
goto init_fail;
if (priv->hw_init(psmouse))
goto init_fail;
__clear_bit(EV_REL, dev1->evbit);
__clear_bit(REL_X, dev1->relbit);
__clear_bit(REL_Y, dev1->relbit);
dev1->evbit[BIT_WORD(EV_KEY)] |= BIT_MASK(EV_KEY);
dev1->keybit[BIT_WORD(BTN_TOUCH)] |= BIT_MASK(BTN_TOUCH);
dev1->keybit[BIT_WORD(BTN_TOOL_FINGER)] |= BIT_MASK(BTN_TOOL_FINGER);
dev1->keybit[BIT_WORD(BTN_LEFT)] |=
BIT_MASK(BTN_LEFT) | BIT_MASK(BTN_RIGHT);
dev1->evbit[BIT_WORD(EV_ABS)] |= BIT_MASK(EV_ABS);
priv->set_abs_params(priv, dev1);
input_set_abs_params(dev1, ABS_PRESSURE, 0, 127, 0, 0);
if (priv->flags & ALPS_WHEEL) {
dev1->evbit[BIT_WORD(EV_REL)] |= BIT_MASK(EV_REL);
dev1->relbit[BIT_WORD(REL_WHEEL)] |= BIT_MASK(REL_WHEEL);
}
if (priv->flags & (ALPS_FW_BK_1 | ALPS_FW_BK_2)) {
dev1->keybit[BIT_WORD(BTN_FORWARD)] |= BIT_MASK(BTN_FORWARD);
dev1->keybit[BIT_WORD(BTN_BACK)] |= BIT_MASK(BTN_BACK);
}
if (priv->flags & ALPS_FOUR_BUTTONS) {
dev1->keybit[BIT_WORD(BTN_0)] |= BIT_MASK(BTN_0);
dev1->keybit[BIT_WORD(BTN_1)] |= BIT_MASK(BTN_1);
dev1->keybit[BIT_WORD(BTN_2)] |= BIT_MASK(BTN_2);
dev1->keybit[BIT_WORD(BTN_3)] |= BIT_MASK(BTN_3);
} else {
dev1->keybit[BIT_WORD(BTN_MIDDLE)] |= BIT_MASK(BTN_MIDDLE);
}
snprintf(priv->phys, sizeof(priv->phys), "%s/input1", psmouse->ps2dev.serio->phys);
dev2->phys = priv->phys;
dev2->name = (priv->flags & ALPS_DUALPOINT) ?
"DualPoint Stick" : "PS/2 Mouse";
dev2->id.bustype = BUS_I8042;
dev2->id.vendor = 0x0002;
dev2->id.product = PSMOUSE_ALPS;
dev2->id.version = 0x0000;
dev2->dev.parent = &psmouse->ps2dev.serio->dev;
dev2->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
dev2->relbit[BIT_WORD(REL_X)] = BIT_MASK(REL_X) | BIT_MASK(REL_Y);
dev2->keybit[BIT_WORD(BTN_LEFT)] =
BIT_MASK(BTN_LEFT) | BIT_MASK(BTN_MIDDLE) | BIT_MASK(BTN_RIGHT);
if (input_register_device(priv->dev2))
goto init_fail;
psmouse->protocol_handler = alps_process_byte;
psmouse->poll = alps_poll;
psmouse->disconnect = alps_disconnect;
psmouse->reconnect = alps_reconnect;
psmouse->pktsize = priv->proto_version == ALPS_PROTO_V4 ? 8 : 6;
psmouse->resync_time = 0;
return 0;
init_fail:
psmouse_reset(psmouse);
input_free_device(dev2);
kfree(priv);
psmouse->private = NULL;
return -1;
}
int alps_detect(struct psmouse *psmouse, bool set_properties)
{
struct alps_data dummy;
if (alps_identify(psmouse, &dummy) < 0)
return -1;
if (set_properties) {
psmouse->vendor = "ALPS";
psmouse->name = dummy.flags & ALPS_DUALPOINT ?
"DualPoint TouchPad" : "GlidePoint";
psmouse->model = dummy.proto_version << 8;
}
return 0;
}
