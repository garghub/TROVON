static bool alps_is_valid_first_byte(const struct alps_model_info *model,
unsigned char data)
{
return (data & model->mask0) == model->byte0;
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
const struct alps_model_info *model = priv->i;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x, y, z, ges, fin, left, right, middle;
int back = 0, forward = 0;
if (model->proto_version == ALPS_PROTO_V1) {
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
if (model->flags & ALPS_FW_BK_1) {
back = packet[0] & 0x10;
forward = packet[2] & 4;
}
if (model->flags & ALPS_FW_BK_2) {
back = packet[3] & 4;
forward = packet[2] & 4;
if ((middle = forward && back))
forward = back = 0;
}
ges = packet[2] & 1;
fin = packet[2] & 2;
if ((model->flags & ALPS_DUALPOINT) && z == 127) {
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
if (model->flags & ALPS_WHEEL)
input_report_rel(dev, REL_WHEEL, ((packet[2] << 1) & 0x08) - ((packet[0] >> 4) & 0x07));
if (model->flags & (ALPS_FW_BK_1 | ALPS_FW_BK_2)) {
input_report_key(dev, BTN_FORWARD, forward);
input_report_key(dev, BTN_BACK, back);
}
if (model->flags & ALPS_FOUR_BUTTONS) {
input_report_key(dev, BTN_0, packet[2] & 4);
input_report_key(dev, BTN_1, packet[0] & 0x10);
input_report_key(dev, BTN_2, packet[3] & 4);
input_report_key(dev, BTN_3, packet[0] & 0x20);
}
input_sync(dev);
}
static int alps_process_bitmap(unsigned int x_map, unsigned int y_map,
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
y_map = y_map << (sizeof(y_map) * BITS_PER_BYTE - ALPS_BITMAP_Y_BITS);
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
*x1 = (ALPS_V3_X_MAX * (2 * x_low.start_bit + x_low.num_bits - 1)) /
(2 * (ALPS_BITMAP_X_BITS - 1));
*y1 = (ALPS_V3_Y_MAX * (2 * y_low.start_bit + y_low.num_bits - 1)) /
(2 * (ALPS_BITMAP_Y_BITS - 1));
if (fingers > 1) {
*x2 = (ALPS_V3_X_MAX * (2 * x_high.start_bit + x_high.num_bits - 1)) /
(2 * (ALPS_BITMAP_X_BITS - 1));
*y2 = (ALPS_V3_Y_MAX * (2 * y_high.start_bit + y_high.num_bits - 1)) /
(2 * (ALPS_BITMAP_Y_BITS - 1));
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
static void alps_process_touchpad_packet_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x, y, z;
int left, right, middle;
int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
int fingers = 0, bmap_fingers;
unsigned int x_bitmap, y_bitmap;
if (priv->multi_packet) {
if (packet[0] & 0x40) {
fingers = (packet[5] & 0x3) + 1;
x_bitmap = ((packet[4] & 0x7e) << 8) |
((packet[1] & 0x7f) << 2) |
((packet[0] & 0x30) >> 4);
y_bitmap = ((packet[3] & 0x70) << 4) |
((packet[2] & 0x7f) << 1) |
(packet[4] & 0x01);
bmap_fingers = alps_process_bitmap(x_bitmap, y_bitmap,
&x1, &y1, &x2, &y2);
if (fingers > 1 && bmap_fingers < 2)
fingers = bmap_fingers;
packet = priv->multi_data;
} else {
priv->multi_packet = 0;
}
}
if (packet[0] & 0x40)
return;
if (!priv->multi_packet && (packet[4] & 0x40)) {
priv->multi_packet = 1;
memcpy(priv->multi_data, packet, sizeof(priv->multi_data));
return;
}
priv->multi_packet = 0;
left = packet[3] & 0x01;
right = packet[3] & 0x02;
middle = packet[3] & 0x04;
x = ((packet[1] & 0x7f) << 4) | ((packet[4] & 0x30) >> 2) |
((packet[0] & 0x30) >> 4);
y = ((packet[2] & 0x7f) << 4) | (packet[4] & 0x0f);
z = packet[5] & 0x7f;
if (x && y && !z)
return;
if (!fingers) {
x1 = x;
y1 = y;
fingers = z > 0 ? 1 : 0;
}
if (z >= 64)
input_report_key(dev, BTN_TOUCH, 1);
else
input_report_key(dev, BTN_TOUCH, 0);
alps_report_semi_mt_data(dev, fingers, x1, y1, x2, y2);
input_mt_report_finger_count(dev, fingers);
input_report_key(dev, BTN_LEFT, left);
input_report_key(dev, BTN_RIGHT, right);
input_report_key(dev, BTN_MIDDLE, middle);
if (z > 0) {
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
}
input_report_abs(dev, ABS_PRESSURE, z);
input_sync(dev);
if (!(priv->quirks & ALPS_QUIRK_TRACKSTICK_BUTTONS)) {
left = packet[3] & 0x10;
right = packet[3] & 0x20;
middle = packet[3] & 0x40;
input_report_key(dev2, BTN_LEFT, left);
input_report_key(dev2, BTN_RIGHT, right);
input_report_key(dev2, BTN_MIDDLE, middle);
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
fingers = alps_process_bitmap(x_bitmap, y_bitmap,
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
static void alps_process_packet(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
const struct alps_model_info *model = priv->i;
switch (model->proto_version) {
case ALPS_PROTO_V1:
case ALPS_PROTO_V2:
alps_process_packet_v1_v2(psmouse);
break;
case ALPS_PROTO_V3:
alps_process_packet_v3(psmouse);
break;
case ALPS_PROTO_V4:
alps_process_packet_v4(psmouse);
break;
}
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
(!alps_is_valid_first_byte(priv->i, psmouse->packet[6]))) {
psmouse_dbg(psmouse,
"refusing packet %4ph (suspected interleaved ps/2)\n",
psmouse->packet + 3);
return PSMOUSE_BAD_DATA;
}
alps_process_packet(psmouse);
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
serio_pause_rx(psmouse->ps2dev.serio);
if (psmouse->pktcnt == psmouse->pktsize) {
if ((psmouse->packet[3] |
psmouse->packet[4] |
psmouse->packet[5]) & 0x80) {
psmouse_dbg(psmouse,
"refusing packet %3ph (suspected interleaved ps/2)\n",
psmouse->packet + 3);
} else {
alps_process_packet(psmouse);
}
psmouse->pktcnt = 0;
}
serio_continue_rx(psmouse->ps2dev.serio);
}
static psmouse_ret_t alps_process_byte(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
const struct alps_model_info *model = priv->i;
if ((psmouse->packet[0] & 0xc8) == 0x08) {
if (psmouse->pktcnt == 3) {
alps_report_bare_ps2_packet(psmouse, psmouse->packet,
true);
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_GOOD_DATA;
}
if ((model->flags & ALPS_PS2_INTERLEAVED) &&
psmouse->pktcnt >= 4 && (psmouse->packet[3] & 0x0f) == 0x0f) {
return alps_handle_interleaved_ps2(psmouse);
}
if (!alps_is_valid_first_byte(model, psmouse->packet[0])) {
psmouse_dbg(psmouse,
"refusing packet[0] = %x (mask0 = %x, byte0 = %x)\n",
psmouse->packet[0], model->mask0, model->byte0);
return PSMOUSE_BAD_DATA;
}
if (psmouse->pktcnt >= 2 && psmouse->pktcnt <= psmouse->pktsize &&
(psmouse->packet[psmouse->pktcnt - 1] & 0x80)) {
psmouse_dbg(psmouse, "refusing packet[%i] = %x\n",
psmouse->pktcnt - 1,
psmouse->packet[psmouse->pktcnt - 1]);
return PSMOUSE_BAD_DATA;
}
if (psmouse->pktcnt == psmouse->pktsize) {
alps_process_packet(psmouse);
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
static int alps_enter_command_mode(struct psmouse *psmouse,
unsigned char *resp)
{
unsigned char param[4];
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO)) {
psmouse_err(psmouse, "failed to enter command mode\n");
return -1;
}
if (param[0] != 0x88 && param[1] != 0x07) {
psmouse_dbg(psmouse,
"unknown response while entering command mode: %2.2x %2.2x %2.2x\n",
param[0], param[1], param[2]);
return -1;
}
if (resp)
*resp = param[2];
return 0;
}
static inline int alps_exit_command_mode(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM))
return -1;
return 0;
}
static const struct alps_model_info *alps_get_model(struct psmouse *psmouse, int *version)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
static const unsigned char rates[] = { 0, 10, 20, 40, 60, 80, 100, 200 };
unsigned char param[4];
const struct alps_model_info *model = NULL;
int i;
param[0] = 0;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11))
return NULL;
param[0] = param[1] = param[2] = 0xff;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return NULL;
psmouse_dbg(psmouse, "E6 report: %2.2x %2.2x %2.2x",
param[0], param[1], param[2]);
if ((param[0] & 0xf8) != 0 || param[1] != 0 ||
(param[2] != 10 && param[2] != 100))
return NULL;
param[0] = 0;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21))
return NULL;
param[0] = param[1] = param[2] = 0xff;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return NULL;
psmouse_dbg(psmouse, "E7 report: %2.2x %2.2x %2.2x",
param[0], param[1], param[2]);
if (version) {
for (i = 0; i < ARRAY_SIZE(rates) && param[2] != rates[i]; i++)
;
*version = (param[0] << 8) | (param[1] << 4) | i;
}
for (i = 0; i < ARRAY_SIZE(alps_model_data); i++) {
if (!memcmp(param, alps_model_data[i].signature,
sizeof(alps_model_data[i].signature))) {
model = alps_model_data + i;
break;
}
}
if (model && model->proto_version > ALPS_PROTO_V2) {
model = NULL;
if (alps_enter_command_mode(psmouse, param)) {
psmouse_warn(psmouse,
"touchpad failed to enter command mode\n");
} else {
for (i = 0; i < ARRAY_SIZE(alps_model_data); i++) {
if (alps_model_data[i].proto_version > ALPS_PROTO_V2 &&
alps_model_data[i].command_mode_resp == param[0]) {
model = alps_model_data + i;
break;
}
}
alps_exit_command_mode(psmouse);
if (!model)
psmouse_dbg(psmouse,
"Unknown command mode response %2.2x\n",
param[0]);
}
}
return model;
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
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return -1;
psmouse_dbg(psmouse, "Status: %2.2x %2.2x %2.2x",
param[0], param[1], param[2]);
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
if (priv->i->flags & ALPS_PASS)
alps_passthrough_mode_v2(psmouse, true);
poll_failed = ps2_command(&psmouse->ps2dev, buf,
PSMOUSE_CMD_POLL | (psmouse->pktsize << 8)) < 0;
if (priv->i->flags & ALPS_PASS)
alps_passthrough_mode_v2(psmouse, false);
if (poll_failed || (buf[0] & priv->i->mask0) != priv->i->byte0)
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
const struct alps_model_info *model = priv->i;
if ((model->flags & ALPS_PASS) &&
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
if ((model->flags & ALPS_PASS) &&
alps_passthrough_mode_v2(psmouse, false)) {
return -1;
}
if (ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSTREAM)) {
psmouse_err(psmouse, "Failed to enable stream mode\n");
return -1;
}
return 0;
}
static int alps_passthrough_mode_v3(struct psmouse *psmouse, bool enable)
{
int reg_val;
reg_val = alps_command_mode_read_reg(psmouse, 0x0008);
if (reg_val == -1)
return -1;
if (enable)
reg_val |= 0x01;
else
reg_val &= ~0x01;
if (__alps_command_mode_write_reg(psmouse, reg_val))
return -1;
return 0;
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
static int alps_hw_init_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
struct ps2dev *ps2dev = &psmouse->ps2dev;
int reg_val;
unsigned char param[4];
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
if (alps_enter_command_mode(psmouse, NULL))
goto error;
reg_val = alps_command_mode_read_reg(psmouse, 0x0008);
if (reg_val == -1)
goto error;
if (reg_val & 0x80) {
if (alps_passthrough_mode_v3(psmouse, true))
goto error;
if (alps_exit_command_mode(psmouse))
goto error;
param[0] = 0x64;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO)) {
psmouse_warn(psmouse, "trackstick E7 report failed\n");
} else {
psmouse_dbg(psmouse,
"trackstick E7 report: %2.2x %2.2x %2.2x\n",
param[0], param[1], param[2]);
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
alps_command_mode_send_nibble(psmouse, 0x9) ||
alps_command_mode_send_nibble(psmouse, 0x4)) {
psmouse_err(psmouse,
"Error sending magic E6 sequence\n");
goto error_passthrough;
}
}
if (alps_enter_command_mode(psmouse, NULL))
goto error_passthrough;
if (alps_passthrough_mode_v3(psmouse, false))
goto error;
}
if (alps_absolute_mode_v3(psmouse)) {
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
if (alps_command_mode_write_reg(psmouse, 0x0008, 0x82))
goto error;
alps_exit_command_mode(psmouse);
param[0] = 0x64;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE)) {
psmouse_err(psmouse, "Failed to enable data reporting\n");
return -1;
}
return 0;
error_passthrough:
if (!alps_enter_command_mode(psmouse, NULL))
alps_passthrough_mode_v3(psmouse, false);
error:
alps_exit_command_mode(psmouse);
return -1;
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
struct alps_data *priv = psmouse->private;
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4];
priv->nibble_commands = alps_v4_nibble_commands;
priv->addr_command = PSMOUSE_CMD_DISABLE;
if (alps_enter_command_mode(psmouse, NULL))
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
static int alps_hw_init(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
const struct alps_model_info *model = priv->i;
int ret = -1;
switch (model->proto_version) {
case ALPS_PROTO_V1:
case ALPS_PROTO_V2:
ret = alps_hw_init_v1_v2(psmouse);
break;
case ALPS_PROTO_V3:
ret = alps_hw_init_v3(psmouse);
break;
case ALPS_PROTO_V4:
ret = alps_hw_init_v4(psmouse);
break;
}
return ret;
}
static int alps_reconnect(struct psmouse *psmouse)
{
const struct alps_model_info *model;
psmouse_reset(psmouse);
model = alps_get_model(psmouse, NULL);
if (!model)
return -1;
return alps_hw_init(psmouse);
}
static void alps_disconnect(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
psmouse_reset(psmouse);
del_timer_sync(&priv->timer);
input_unregister_device(priv->dev2);
kfree(priv);
}
int alps_init(struct psmouse *psmouse)
{
struct alps_data *priv;
const struct alps_model_info *model;
struct input_dev *dev1 = psmouse->dev, *dev2;
int version;
priv = kzalloc(sizeof(struct alps_data), GFP_KERNEL);
dev2 = input_allocate_device();
if (!priv || !dev2)
goto init_fail;
priv->dev2 = dev2;
setup_timer(&priv->timer, alps_flush_packet, (unsigned long)psmouse);
psmouse->private = priv;
psmouse_reset(psmouse);
model = alps_get_model(psmouse, &version);
if (!model)
goto init_fail;
priv->i = model;
if (alps_hw_init(psmouse))
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
switch (model->proto_version) {
case ALPS_PROTO_V1:
case ALPS_PROTO_V2:
input_set_abs_params(dev1, ABS_X, 0, 1023, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, 767, 0, 0);
break;
case ALPS_PROTO_V3:
case ALPS_PROTO_V4:
set_bit(INPUT_PROP_SEMI_MT, dev1->propbit);
input_mt_init_slots(dev1, 2, 0);
input_set_abs_params(dev1, ABS_MT_POSITION_X, 0, ALPS_V3_X_MAX, 0, 0);
input_set_abs_params(dev1, ABS_MT_POSITION_Y, 0, ALPS_V3_Y_MAX, 0, 0);
set_bit(BTN_TOOL_DOUBLETAP, dev1->keybit);
set_bit(BTN_TOOL_TRIPLETAP, dev1->keybit);
set_bit(BTN_TOOL_QUADTAP, dev1->keybit);
input_set_abs_params(dev1, ABS_X, 0, ALPS_V3_X_MAX, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, ALPS_V3_Y_MAX, 0, 0);
break;
}
input_set_abs_params(dev1, ABS_PRESSURE, 0, 127, 0, 0);
if (model->flags & ALPS_WHEEL) {
dev1->evbit[BIT_WORD(EV_REL)] |= BIT_MASK(EV_REL);
dev1->relbit[BIT_WORD(REL_WHEEL)] |= BIT_MASK(REL_WHEEL);
}
if (model->flags & (ALPS_FW_BK_1 | ALPS_FW_BK_2)) {
dev1->keybit[BIT_WORD(BTN_FORWARD)] |= BIT_MASK(BTN_FORWARD);
dev1->keybit[BIT_WORD(BTN_BACK)] |= BIT_MASK(BTN_BACK);
}
if (model->flags & ALPS_FOUR_BUTTONS) {
dev1->keybit[BIT_WORD(BTN_0)] |= BIT_MASK(BTN_0);
dev1->keybit[BIT_WORD(BTN_1)] |= BIT_MASK(BTN_1);
dev1->keybit[BIT_WORD(BTN_2)] |= BIT_MASK(BTN_2);
dev1->keybit[BIT_WORD(BTN_3)] |= BIT_MASK(BTN_3);
} else {
dev1->keybit[BIT_WORD(BTN_MIDDLE)] |= BIT_MASK(BTN_MIDDLE);
}
snprintf(priv->phys, sizeof(priv->phys), "%s/input1", psmouse->ps2dev.serio->phys);
dev2->phys = priv->phys;
dev2->name = (model->flags & ALPS_DUALPOINT) ? "DualPoint Stick" : "PS/2 Mouse";
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
psmouse->pktsize = model->proto_version == ALPS_PROTO_V4 ? 8 : 6;
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
int version;
const struct alps_model_info *model;
model = alps_get_model(psmouse, &version);
if (!model)
return -1;
if (set_properties) {
psmouse->vendor = "ALPS";
psmouse->name = model->flags & ALPS_DUALPOINT ?
"DualPoint TouchPad" : "GlidePoint";
psmouse->model = version;
}
return 0;
}
