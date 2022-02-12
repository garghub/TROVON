static bool alps_is_valid_first_byte(struct alps_data *priv,
unsigned char data)
{
return (data & priv->mask0) == priv->byte0;
}
static void alps_report_buttons(struct input_dev *dev1, struct input_dev *dev2,
int left, int right, int middle)
{
struct input_dev *dev;
dev = (dev2 && test_bit(BTN_LEFT, dev2->key)) ? dev2 : dev1;
input_report_key(dev, BTN_LEFT, left);
dev = (dev2 && test_bit(BTN_RIGHT, dev2->key)) ? dev2 : dev1;
input_report_key(dev, BTN_RIGHT, right);
dev = (dev2 && test_bit(BTN_MIDDLE, dev2->key)) ? dev2 : dev1;
input_report_key(dev, BTN_MIDDLE, middle);
if (dev2)
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
alps_report_buttons(dev2, dev, left, right, middle);
input_sync(dev2);
return;
}
if (priv->flags & ALPS_STICK_BITS) {
left |= packet[0] & 1;
right |= packet[0] & 2;
middle |= packet[0] & 4;
}
alps_report_buttons(dev, dev2, left, right, middle);
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
static void alps_get_bitmap_points(unsigned int map,
struct alps_bitmap_point *low,
struct alps_bitmap_point *high,
int *fingers)
{
struct alps_bitmap_point *point;
int i, bit, prev_bit = 0;
point = low;
for (i = 0; map != 0; i++, map >>= 1) {
bit = map & 1;
if (bit) {
if (!prev_bit) {
point->start_bit = i;
point->num_bits = 0;
(*fingers)++;
}
point->num_bits++;
} else {
if (prev_bit)
point = high;
}
prev_bit = bit;
}
}
static int alps_process_bitmap(struct alps_data *priv,
struct alps_fields *fields)
{
int i, fingers_x = 0, fingers_y = 0, fingers, closest;
struct alps_bitmap_point x_low = {0,}, x_high = {0,};
struct alps_bitmap_point y_low = {0,}, y_high = {0,};
struct input_mt_pos corner[4];
if (!fields->x_map || !fields->y_map)
return 0;
alps_get_bitmap_points(fields->x_map, &x_low, &x_high, &fingers_x);
alps_get_bitmap_points(fields->y_map, &y_low, &y_high, &fingers_y);
fingers = max(fingers_x, fingers_y);
if (fingers_x == 1) {
i = (x_low.num_bits - 1) / 2;
x_low.num_bits = x_low.num_bits - i;
x_high.start_bit = x_low.start_bit + i;
x_high.num_bits = max(i, 1);
}
if (fingers_y == 1) {
i = (y_low.num_bits - 1) / 2;
y_low.num_bits = y_low.num_bits - i;
y_high.start_bit = y_low.start_bit + i;
y_high.num_bits = max(i, 1);
}
corner[0].x =
(priv->x_max * (2 * x_low.start_bit + x_low.num_bits - 1)) /
(2 * (priv->x_bits - 1));
corner[0].y =
(priv->y_max * (2 * y_low.start_bit + y_low.num_bits - 1)) /
(2 * (priv->y_bits - 1));
corner[1].x =
(priv->x_max * (2 * x_high.start_bit + x_high.num_bits - 1)) /
(2 * (priv->x_bits - 1));
corner[1].y =
(priv->y_max * (2 * y_low.start_bit + y_low.num_bits - 1)) /
(2 * (priv->y_bits - 1));
corner[2].x =
(priv->x_max * (2 * x_high.start_bit + x_high.num_bits - 1)) /
(2 * (priv->x_bits - 1));
corner[2].y =
(priv->y_max * (2 * y_high.start_bit + y_high.num_bits - 1)) /
(2 * (priv->y_bits - 1));
corner[3].x =
(priv->x_max * (2 * x_low.start_bit + x_low.num_bits - 1)) /
(2 * (priv->x_bits - 1));
corner[3].y =
(priv->y_max * (2 * y_high.start_bit + y_high.num_bits - 1)) /
(2 * (priv->y_bits - 1));
if (priv->proto_version == ALPS_PROTO_V5) {
for (i = 0; i < 4; i++)
corner[i].x = priv->x_max - corner[i].x;
}
if (priv->proto_version == ALPS_PROTO_V3 ||
priv->proto_version == ALPS_PROTO_V4) {
for (i = 0; i < 4; i++)
corner[i].y = priv->y_max - corner[i].y;
}
if (priv->second_touch == -1) {
closest = 0x7fffffff;
for (i = 0; i < 4; i++) {
int dx = fields->st.x - corner[i].x;
int dy = fields->st.y - corner[i].y;
int distance = dx * dx + dy * dy;
if (distance < closest) {
priv->second_touch = i;
closest = distance;
}
}
priv->second_touch = (priv->second_touch + 2) % 4;
}
fields->mt[0] = fields->st;
fields->mt[1] = corner[priv->second_touch];
return fingers;
}
static void alps_set_slot(struct input_dev *dev, int slot, int x, int y)
{
input_mt_slot(dev, slot);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, true);
input_report_abs(dev, ABS_MT_POSITION_X, x);
input_report_abs(dev, ABS_MT_POSITION_Y, y);
}
static void alps_report_mt_data(struct psmouse *psmouse, int n)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev = psmouse->dev;
struct alps_fields *f = &priv->f;
int i, slot[MAX_TOUCHES];
input_mt_assign_slots(dev, slot, f->mt, n, 0);
for (i = 0; i < n; i++)
alps_set_slot(dev, slot[i], f->mt[i].x, f->mt[i].y);
input_mt_sync_frame(dev);
}
static void alps_report_semi_mt_data(struct psmouse *psmouse, int fingers)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev = psmouse->dev;
struct alps_fields *f = &priv->f;
if (fingers < 2) {
f->mt[0].x = f->st.x;
f->mt[0].y = f->st.y;
fingers = f->pressure > 0 ? 1 : 0;
priv->second_touch = -1;
}
if (fingers >= 1)
alps_set_slot(dev, 0, f->mt[0].x, f->mt[0].y);
if (fingers >= 2)
alps_set_slot(dev, 1, f->mt[1].x, f->mt[1].y);
input_mt_sync_frame(dev);
input_mt_report_finger_count(dev, fingers);
input_report_key(dev, BTN_LEFT, f->left);
input_report_key(dev, BTN_RIGHT, f->right);
input_report_key(dev, BTN_MIDDLE, f->middle);
input_report_abs(dev, ABS_PRESSURE, f->pressure);
input_sync(dev);
}
static void alps_process_trackstick_packet_v3(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = priv->dev2;
int x, y, z, left, right, middle;
if (!(priv->flags & ALPS_DUALPOINT)) {
psmouse_warn(psmouse,
"Rejected trackstick packet from non DualPoint device");
return;
}
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
static int alps_decode_pinnacle(struct alps_fields *f, unsigned char *p,
struct psmouse *psmouse)
{
f->first_mp = !!(p[4] & 0x40);
f->is_mp = !!(p[0] & 0x40);
if (f->is_mp) {
f->fingers = (p[5] & 0x3) + 1;
f->x_map = ((p[4] & 0x7e) << 8) |
((p[1] & 0x7f) << 2) |
((p[0] & 0x30) >> 4);
f->y_map = ((p[3] & 0x70) << 4) |
((p[2] & 0x7f) << 1) |
(p[4] & 0x01);
} else {
f->st.x = ((p[1] & 0x7f) << 4) | ((p[4] & 0x30) >> 2) |
((p[0] & 0x30) >> 4);
f->st.y = ((p[2] & 0x7f) << 4) | (p[4] & 0x0f);
f->pressure = p[5] & 0x7f;
alps_decode_buttons_v3(f, p);
}
return 0;
}
static int alps_decode_rushmore(struct alps_fields *f, unsigned char *p,
struct psmouse *psmouse)
{
f->first_mp = !!(p[4] & 0x40);
f->is_mp = !!(p[5] & 0x40);
if (f->is_mp) {
f->fingers = max((p[5] & 0x3), ((p[5] >> 2) & 0x3)) + 1;
f->x_map = ((p[5] & 0x10) << 11) |
((p[4] & 0x7e) << 8) |
((p[1] & 0x7f) << 2) |
((p[0] & 0x30) >> 4);
f->y_map = ((p[5] & 0x20) << 6) |
((p[3] & 0x70) << 4) |
((p[2] & 0x7f) << 1) |
(p[4] & 0x01);
} else {
f->st.x = ((p[1] & 0x7f) << 4) | ((p[4] & 0x30) >> 2) |
((p[0] & 0x30) >> 4);
f->st.y = ((p[2] & 0x7f) << 4) | (p[4] & 0x0f);
f->pressure = p[5] & 0x7f;
alps_decode_buttons_v3(f, p);
}
return 0;
}
static int alps_decode_dolphin(struct alps_fields *f, unsigned char *p,
struct psmouse *psmouse)
{
u64 palm_data = 0;
struct alps_data *priv = psmouse->private;
f->first_mp = !!(p[0] & 0x02);
f->is_mp = !!(p[0] & 0x20);
if (!f->is_mp) {
f->st.x = ((p[1] & 0x7f) | ((p[4] & 0x0f) << 7));
f->st.y = ((p[2] & 0x7f) | ((p[4] & 0xf0) << 3));
f->pressure = (p[0] & 4) ? 0 : p[5] & 0x7f;
alps_decode_buttons_v3(f, p);
} else {
f->fingers = ((p[0] & 0x6) >> 1 |
(p[0] & 0x10) >> 2);
palm_data = (p[1] & 0x7f) |
((p[2] & 0x7f) << 7) |
((p[4] & 0x7f) << 14) |
((p[5] & 0x7f) << 21) |
((p[3] & 0x07) << 28) |
(((u64)p[3] & 0x70) << 27) |
(((u64)p[0] & 0x01) << 34);
f->y_map = palm_data & (BIT(priv->y_bits) - 1);
f->x_map = (palm_data >> priv->y_bits) &
(BIT(priv->x_bits) - 1);
}
return 0;
}
static void alps_process_touchpad_packet_v3_v5(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev2 = priv->dev2;
struct alps_fields *f = &priv->f;
int fingers = 0;
memset(f, 0, sizeof(*f));
priv->decode_fields(f, packet, psmouse);
if (priv->multi_packet) {
if (f->is_mp) {
fingers = f->fingers;
priv->decode_fields(f, priv->multi_data, psmouse);
if (alps_process_bitmap(priv, f) == 0)
fingers = 0;
} else {
priv->multi_packet = 0;
}
}
if (f->is_mp)
return;
if (!priv->multi_packet && f->first_mp) {
priv->multi_packet = 1;
memcpy(priv->multi_data, packet, sizeof(priv->multi_data));
return;
}
priv->multi_packet = 0;
if (f->st.x && f->st.y && !f->pressure)
return;
alps_report_semi_mt_data(psmouse, fingers);
if ((priv->flags & ALPS_DUALPOINT) &&
!(priv->quirks & ALPS_QUIRK_TRACKSTICK_BUTTONS)) {
input_report_key(dev2, BTN_LEFT, f->ts_left);
input_report_key(dev2, BTN_RIGHT, f->ts_right);
input_report_key(dev2, BTN_MIDDLE, f->ts_middle);
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
alps_process_touchpad_packet_v3_v5(psmouse);
}
static void alps_process_packet_v6(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x, y, z, left, right, middle;
if (packet[5] == 0x7F) {
if (!(priv->flags & ALPS_DUALPOINT)) {
psmouse_warn(psmouse,
"Rejected trackstick packet from non DualPoint device");
return;
}
x = packet[1] | ((packet[3] & 0x20) << 2);
y = packet[2] | ((packet[3] & 0x40) << 1);
z = packet[4];
left = packet[3] & 0x01;
right = packet[3] & 0x02;
middle = packet[3] & 0x04;
if (x == 0x7F && y == 0x7F && z == 0x7F)
x = y = z = 0;
input_report_rel(dev2, REL_X, (char)x / 4);
input_report_rel(dev2, REL_Y, -((char)y / 4));
input_report_key(dev2, BTN_LEFT, left);
input_report_key(dev2, BTN_RIGHT, right);
input_report_key(dev2, BTN_MIDDLE, middle);
input_sync(dev2);
return;
}
x = packet[1] | ((packet[3] & 0x78) << 4);
y = packet[2] | ((packet[4] & 0x78) << 4);
z = packet[5];
left = packet[3] & 0x01;
right = packet[3] & 0x02;
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
input_report_key(dev, BTN_LEFT, left);
input_report_key(dev, BTN_RIGHT, right);
input_sync(dev);
}
static void alps_process_packet_v4(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct alps_fields *f = &priv->f;
int offset;
if (packet[6] & 0x40) {
priv->multi_packet = 0;
}
if (WARN_ON_ONCE(priv->multi_packet > 2))
return;
offset = 2 * priv->multi_packet;
priv->multi_data[offset] = packet[6];
priv->multi_data[offset + 1] = packet[7];
f->left = !!(packet[4] & 0x01);
f->right = !!(packet[4] & 0x02);
f->st.x = ((packet[1] & 0x7f) << 4) | ((packet[3] & 0x30) >> 2) |
((packet[0] & 0x30) >> 4);
f->st.y = ((packet[2] & 0x7f) << 4) | (packet[3] & 0x0f);
f->pressure = packet[5] & 0x7f;
if (++priv->multi_packet > 2) {
priv->multi_packet = 0;
f->x_map = ((priv->multi_data[2] & 0x1f) << 10) |
((priv->multi_data[3] & 0x60) << 3) |
((priv->multi_data[0] & 0x3f) << 2) |
((priv->multi_data[1] & 0x60) >> 5);
f->y_map = ((priv->multi_data[5] & 0x01) << 10) |
((priv->multi_data[3] & 0x1f) << 5) |
(priv->multi_data[1] & 0x1f);
f->fingers = alps_process_bitmap(priv, f);
}
alps_report_semi_mt_data(psmouse, f->fingers);
}
static bool alps_is_valid_package_v7(struct psmouse *psmouse)
{
switch (psmouse->pktcnt) {
case 3:
return (psmouse->packet[2] & 0x40) == 0x40;
case 4:
return (psmouse->packet[3] & 0x48) == 0x48;
case 6:
return (psmouse->packet[5] & 0x40) == 0x00;
}
return true;
}
static unsigned char alps_get_packet_id_v7(char *byte)
{
unsigned char packet_id;
if (byte[4] & 0x40)
packet_id = V7_PACKET_ID_TWO;
else if (byte[4] & 0x01)
packet_id = V7_PACKET_ID_MULTI;
else if ((byte[0] & 0x10) && !(byte[4] & 0x43))
packet_id = V7_PACKET_ID_NEW;
else if (byte[1] == 0x00 && byte[4] == 0x00)
packet_id = V7_PACKET_ID_IDLE;
else
packet_id = V7_PACKET_ID_UNKNOWN;
return packet_id;
}
static void alps_get_finger_coordinate_v7(struct input_mt_pos *mt,
unsigned char *pkt,
unsigned char pkt_id)
{
mt[0].x = ((pkt[2] & 0x80) << 4);
mt[0].x |= ((pkt[2] & 0x3F) << 5);
mt[0].x |= ((pkt[3] & 0x30) >> 1);
mt[0].x |= (pkt[3] & 0x07);
mt[0].y = (pkt[1] << 3) | (pkt[0] & 0x07);
mt[1].x = ((pkt[3] & 0x80) << 4);
mt[1].x |= ((pkt[4] & 0x80) << 3);
mt[1].x |= ((pkt[4] & 0x3F) << 4);
mt[1].y = ((pkt[5] & 0x80) << 3);
mt[1].y |= ((pkt[5] & 0x3F) << 4);
switch (pkt_id) {
case V7_PACKET_ID_TWO:
mt[1].x &= ~0x000F;
mt[1].y |= 0x000F;
if (mt[1].y == 0x7ff && mt[1].x == 0xff0) {
mt[1].x = 0;
}
break;
case V7_PACKET_ID_MULTI:
mt[1].x &= ~0x003F;
mt[1].y &= ~0x0020;
mt[1].y |= ((pkt[4] & 0x02) << 4);
mt[1].y |= 0x001F;
break;
case V7_PACKET_ID_NEW:
mt[1].x &= ~0x003F;
mt[1].x |= (pkt[0] & 0x20);
mt[1].y |= 0x000F;
break;
}
mt[0].y = 0x7FF - mt[0].y;
mt[1].y = 0x7FF - mt[1].y;
}
static int alps_get_mt_count(struct input_mt_pos *mt)
{
int i, fingers = 0;
for (i = 0; i < MAX_TOUCHES; i++) {
if (mt[i].x != 0 || mt[i].y != 0)
fingers++;
}
return fingers;
}
static int alps_decode_packet_v7(struct alps_fields *f,
unsigned char *p,
struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char pkt_id;
pkt_id = alps_get_packet_id_v7(p);
if (pkt_id == V7_PACKET_ID_IDLE)
return 0;
if (pkt_id == V7_PACKET_ID_UNKNOWN)
return -1;
if (pkt_id == V7_PACKET_ID_NEW)
return 1;
alps_get_finger_coordinate_v7(f->mt, p, pkt_id);
if (pkt_id == V7_PACKET_ID_TWO)
f->fingers = alps_get_mt_count(f->mt);
else
f->fingers = 3 + (p[5] & 0x03);
f->left = (p[0] & 0x80) >> 7;
if (priv->flags & ALPS_BUTTONPAD) {
if (p[0] & 0x20)
f->fingers++;
if (p[0] & 0x10)
f->fingers++;
} else {
f->right = (p[0] & 0x20) >> 5;
f->middle = (p[0] & 0x10) >> 4;
}
if (f->fingers == 1 && f->mt[0].x == 0 && f->mt[0].y == 0) {
f->mt[0].x = f->mt[1].x;
f->mt[0].y = f->mt[1].y;
f->mt[1].x = 0;
f->mt[1].y = 0;
}
return 0;
}
static void alps_process_trackstick_packet_v7(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev2 = priv->dev2;
int x, y, z, left, right, middle;
if (!(priv->flags & ALPS_DUALPOINT)) {
psmouse_warn(psmouse,
"Rejected trackstick packet from non DualPoint device");
return;
}
x = ((packet[2] & 0xbf)) | ((packet[3] & 0x10) << 2);
y = (packet[3] & 0x07) | (packet[4] & 0xb8) |
((packet[3] & 0x20) << 1);
z = (packet[5] & 0x3f) | ((packet[3] & 0x80) >> 1);
left = (packet[1] & 0x01);
right = (packet[1] & 0x02) >> 1;
middle = (packet[1] & 0x04) >> 2;
input_report_rel(dev2, REL_X, (char)x);
input_report_rel(dev2, REL_Y, -((char)y));
input_report_key(dev2, BTN_LEFT, left);
input_report_key(dev2, BTN_RIGHT, right);
input_report_key(dev2, BTN_MIDDLE, middle);
input_sync(dev2);
}
static void alps_process_touchpad_packet_v7(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev = psmouse->dev;
struct alps_fields *f = &priv->f;
memset(f, 0, sizeof(*f));
if (priv->decode_fields(f, psmouse->packet, psmouse))
return;
alps_report_mt_data(psmouse, alps_get_mt_count(f->mt));
input_mt_report_finger_count(dev, f->fingers);
input_report_key(dev, BTN_LEFT, f->left);
input_report_key(dev, BTN_RIGHT, f->right);
input_report_key(dev, BTN_MIDDLE, f->middle);
input_sync(dev);
}
static void alps_process_packet_v7(struct psmouse *psmouse)
{
unsigned char *packet = psmouse->packet;
if (packet[0] == 0x48 && (packet[4] & 0x47) == 0x06)
alps_process_trackstick_packet_v7(psmouse);
else
alps_process_touchpad_packet_v7(psmouse);
}
static unsigned char alps_get_pkt_id_ss4_v2(unsigned char *byte)
{
unsigned char pkt_id = SS4_PACKET_ID_IDLE;
if (byte[0] == 0x18 && byte[1] == 0x10 && byte[2] == 0x00 &&
(byte[3] & 0x88) == 0x08 && byte[4] == 0x10 && byte[5] == 0x00) {
pkt_id = SS4_PACKET_ID_IDLE;
} else if (!(byte[3] & 0x10)) {
pkt_id = SS4_PACKET_ID_ONE;
} else if (!(byte[3] & 0x20)) {
pkt_id = SS4_PACKET_ID_TWO;
} else {
pkt_id = SS4_PACKET_ID_MULTI;
}
return pkt_id;
}
static int alps_decode_ss4_v2(struct alps_fields *f,
unsigned char *p, struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char pkt_id;
unsigned int no_data_x, no_data_y;
pkt_id = alps_get_pkt_id_ss4_v2(p);
switch (pkt_id) {
case SS4_PACKET_ID_ONE:
f->mt[0].x = SS4_1F_X_V2(p);
f->mt[0].y = SS4_1F_Y_V2(p);
f->pressure = ((SS4_1F_Z_V2(p)) * 2) & 0x7f;
f->fingers = 1;
f->first_mp = 0;
f->is_mp = 0;
break;
case SS4_PACKET_ID_TWO:
if (priv->flags & ALPS_BUTTONPAD) {
f->mt[0].x = SS4_BTL_MF_X_V2(p, 0);
f->mt[0].y = SS4_BTL_MF_Y_V2(p, 0);
f->mt[1].x = SS4_BTL_MF_X_V2(p, 1);
f->mt[1].y = SS4_BTL_MF_Y_V2(p, 1);
} else {
f->mt[0].x = SS4_STD_MF_X_V2(p, 0);
f->mt[0].y = SS4_STD_MF_Y_V2(p, 0);
f->mt[1].x = SS4_STD_MF_X_V2(p, 1);
f->mt[1].y = SS4_STD_MF_Y_V2(p, 1);
}
f->pressure = SS4_MF_Z_V2(p, 0) ? 0x30 : 0;
if (SS4_IS_MF_CONTINUE(p)) {
f->first_mp = 1;
} else {
f->fingers = 2;
f->first_mp = 0;
}
f->is_mp = 0;
break;
case SS4_PACKET_ID_MULTI:
if (priv->flags & ALPS_BUTTONPAD) {
f->mt[2].x = SS4_BTL_MF_X_V2(p, 0);
f->mt[2].y = SS4_BTL_MF_Y_V2(p, 0);
f->mt[3].x = SS4_BTL_MF_X_V2(p, 1);
f->mt[3].y = SS4_BTL_MF_Y_V2(p, 1);
no_data_x = SS4_MFPACKET_NO_AX_BL;
no_data_y = SS4_MFPACKET_NO_AY_BL;
} else {
f->mt[2].x = SS4_STD_MF_X_V2(p, 0);
f->mt[2].y = SS4_STD_MF_Y_V2(p, 0);
f->mt[3].x = SS4_STD_MF_X_V2(p, 1);
f->mt[3].y = SS4_STD_MF_Y_V2(p, 1);
no_data_x = SS4_MFPACKET_NO_AX;
no_data_y = SS4_MFPACKET_NO_AY;
}
f->first_mp = 0;
f->is_mp = 1;
if (SS4_IS_5F_DETECTED(p)) {
f->fingers = 5;
} else if (f->mt[3].x == no_data_x &&
f->mt[3].y == no_data_y) {
f->mt[3].x = 0;
f->mt[3].y = 0;
f->fingers = 3;
} else {
f->fingers = 4;
}
break;
case SS4_PACKET_ID_IDLE:
default:
memset(f, 0, sizeof(struct alps_fields));
break;
}
f->left = !!(SS4_BTN_V2(p) & 0x01);
if (!(priv->flags & ALPS_BUTTONPAD)) {
f->right = !!(SS4_BTN_V2(p) & 0x02);
f->middle = !!(SS4_BTN_V2(p) & 0x04);
}
return 0;
}
static void alps_process_packet_ss4_v2(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct alps_fields *f = &priv->f;
memset(f, 0, sizeof(struct alps_fields));
priv->decode_fields(f, packet, psmouse);
if (priv->multi_packet) {
if (f->is_mp) {
priv->decode_fields(f, priv->multi_data, psmouse);
} else {
priv->multi_packet = 0;
}
}
if (f->is_mp)
return;
if (!priv->multi_packet && f->first_mp) {
priv->multi_packet = 1;
memcpy(priv->multi_data, packet, sizeof(priv->multi_data));
return;
}
priv->multi_packet = 0;
alps_report_mt_data(psmouse, (f->fingers <= 4) ? f->fingers : 4);
input_mt_report_finger_count(dev, f->fingers);
input_report_key(dev, BTN_LEFT, f->left);
input_report_key(dev, BTN_RIGHT, f->right);
input_report_key(dev, BTN_MIDDLE, f->middle);
input_report_abs(dev, ABS_PRESSURE, f->pressure);
input_sync(dev);
}
static bool alps_is_valid_package_ss4_v2(struct psmouse *psmouse)
{
if (psmouse->pktcnt == 4 && ((psmouse->packet[3] & 0x08) != 0x08))
return false;
if (psmouse->pktcnt == 6 && ((psmouse->packet[5] & 0x10) != 0x0))
return false;
return true;
}
static void alps_register_bare_ps2_mouse(struct work_struct *work)
{
struct alps_data *priv =
container_of(work, struct alps_data, dev3_register_work.work);
struct psmouse *psmouse = priv->psmouse;
struct input_dev *dev3;
int error = 0;
mutex_lock(&alps_mutex);
if (priv->dev3)
goto out;
dev3 = input_allocate_device();
if (!dev3) {
psmouse_err(psmouse, "failed to allocate secondary device\n");
error = -ENOMEM;
goto out;
}
snprintf(priv->phys3, sizeof(priv->phys3), "%s/%s",
psmouse->ps2dev.serio->phys,
(priv->dev2 ? "input2" : "input1"));
dev3->phys = priv->phys3;
dev3->name = "PS/2 ALPS Mouse";
dev3->id.bustype = BUS_I8042;
dev3->id.vendor = 0x0002;
dev3->id.product = PSMOUSE_PS2;
dev3->id.version = 0x0000;
dev3->dev.parent = &psmouse->ps2dev.serio->dev;
input_set_capability(dev3, EV_REL, REL_X);
input_set_capability(dev3, EV_REL, REL_Y);
input_set_capability(dev3, EV_KEY, BTN_LEFT);
input_set_capability(dev3, EV_KEY, BTN_RIGHT);
input_set_capability(dev3, EV_KEY, BTN_MIDDLE);
__set_bit(INPUT_PROP_POINTER, dev3->propbit);
error = input_register_device(dev3);
if (error) {
psmouse_err(psmouse,
"failed to register secondary device: %d\n",
error);
input_free_device(dev3);
goto out;
}
priv->dev3 = dev3;
out:
if (error)
priv->dev3 = ERR_PTR(error);
mutex_unlock(&alps_mutex);
}
static void alps_report_bare_ps2_packet(struct psmouse *psmouse,
unsigned char packet[],
bool report_buttons)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev, *dev2 = NULL;
if (priv->proto_version == ALPS_PROTO_V2 &&
(priv->flags & ALPS_DUALPOINT)) {
dev = priv->dev2;
dev2 = psmouse->dev;
} else if (unlikely(IS_ERR_OR_NULL(priv->dev3))) {
if (!IS_ERR(priv->dev3))
psmouse_queue_work(psmouse, &priv->dev3_register_work,
0);
return;
} else {
dev = priv->dev3;
}
if (report_buttons)
alps_report_buttons(dev, dev2,
packet[0] & 1, packet[0] & 2, packet[0] & 4);
input_report_rel(dev, REL_X,
packet[1] ? packet[1] - ((packet[0] << 4) & 0x100) : 0);
input_report_rel(dev, REL_Y,
packet[2] ? ((packet[0] << 3) & 0x100) - packet[2] : 0);
input_sync(dev);
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
if (priv->proto_version != ALPS_PROTO_V8 &&
!psmouse->out_of_sync_cnt &&
(psmouse->packet[0] & 0xc8) == 0x08) {
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
if (priv->proto_version < ALPS_PROTO_V5 &&
psmouse->pktcnt >= 2 && psmouse->pktcnt <= psmouse->pktsize &&
(psmouse->packet[psmouse->pktcnt - 1] & 0x80)) {
psmouse_dbg(psmouse, "refusing packet[%i] = %x\n",
psmouse->pktcnt - 1,
psmouse->packet[psmouse->pktcnt - 1]);
if (priv->proto_version == ALPS_PROTO_V3_RUSHMORE &&
psmouse->pktcnt == psmouse->pktsize) {
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_BAD_DATA;
}
if ((priv->proto_version == ALPS_PROTO_V7 &&
!alps_is_valid_package_v7(psmouse)) ||
(priv->proto_version == ALPS_PROTO_V8 &&
!alps_is_valid_package_ss4_v2(psmouse))) {
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
static bool alps_check_valid_firmware_id(unsigned char id[])
{
if (id[0] == 0x73)
return true;
if (id[0] == 0x88 &&
(id[1] == 0x07 ||
id[1] == 0x08 ||
(id[1] & 0xf0) == 0xb0 ||
(id[1] & 0xf0) == 0xc0)) {
return true;
}
return false;
}
static int alps_enter_command_mode(struct psmouse *psmouse)
{
unsigned char param[4];
if (alps_rpt_cmd(psmouse, 0, PSMOUSE_CMD_RESET_WRAP, param)) {
psmouse_err(psmouse, "failed to enter command mode\n");
return -1;
}
if (!alps_check_valid_firmware_id(param)) {
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
static int alps_monitor_mode_send_word(struct psmouse *psmouse, u16 word)
{
int i, nibble;
for (i = 0; i <= 8; i += 4) {
nibble = (word >> i) & 0xf;
if (alps_command_mode_send_nibble(psmouse, nibble))
return -1;
}
return 0;
}
static int alps_monitor_mode_write_reg(struct psmouse *psmouse,
u16 addr, u16 value)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE) ||
alps_monitor_mode_send_word(psmouse, 0x0A0) ||
alps_monitor_mode_send_word(psmouse, addr) ||
alps_monitor_mode_send_word(psmouse, value) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE))
return -1;
return 0;
}
static int alps_monitor_mode(struct psmouse *psmouse, bool enable)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (enable) {
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_GETINFO) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_GETINFO))
return -1;
} else {
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP))
return -1;
}
return 0;
}
static int alps_absolute_mode_v6(struct psmouse *psmouse)
{
u16 reg_val = 0x181;
int ret = -1;
if (alps_monitor_mode(psmouse, true))
return -1;
ret = alps_monitor_mode_write_reg(psmouse, 0x000, reg_val);
if (alps_monitor_mode(psmouse, false))
ret = -1;
return ret;
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
static int alps_hw_init_v6(struct psmouse *psmouse)
{
unsigned char param[2] = {0xC8, 0x14};
if (alps_passthrough_mode_v2(psmouse, true))
return -1;
if (ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSCALE11) ||
ps2_command(&psmouse->ps2dev, &param[0], PSMOUSE_CMD_SETRATE) ||
ps2_command(&psmouse->ps2dev, &param[1], PSMOUSE_CMD_SETRATE))
return -1;
if (alps_passthrough_mode_v2(psmouse, false))
return -1;
if (alps_absolute_mode_v6(psmouse)) {
psmouse_err(psmouse, "Failed to enable absolute mode\n");
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
psmouse_warn(psmouse, "Failed to initialize trackstick (E7 report failed)\n");
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
static int alps_get_v3_v7_resolution(struct psmouse *psmouse, int reg_pitch)
{
int reg, x_pitch, y_pitch, x_electrode, y_electrode, x_phys, y_phys;
struct alps_data *priv = psmouse->private;
reg = alps_command_mode_read_reg(psmouse, reg_pitch);
if (reg < 0)
return reg;
x_pitch = (char)(reg << 4) >> 4;
x_pitch = 50 + 2 * x_pitch;
y_pitch = (char)reg >> 4;
y_pitch = 36 + 2 * y_pitch;
reg = alps_command_mode_read_reg(psmouse, reg_pitch + 1);
if (reg < 0)
return reg;
x_electrode = (char)(reg << 4) >> 4;
x_electrode = 17 + x_electrode;
y_electrode = (char)reg >> 4;
y_electrode = 13 + y_electrode;
x_phys = x_pitch * (x_electrode - 1);
y_phys = y_pitch * (y_electrode - 1);
priv->x_res = priv->x_max * 10 / x_phys;
priv->y_res = priv->y_max * 10 / y_phys;
psmouse_dbg(psmouse,
"pitch %dx%d num-electrodes %dx%d physical size %dx%d mm res %dx%d\n",
x_pitch, y_pitch, x_electrode, y_electrode,
x_phys / 10, y_phys / 10, priv->x_res, priv->y_res);
return 0;
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
}
if (alps_enter_command_mode(psmouse) ||
alps_command_mode_read_reg(psmouse, 0xc2d9) == -1 ||
alps_command_mode_write_reg(psmouse, 0xc2cb, 0x00))
goto error;
if (alps_get_v3_v7_resolution(psmouse, 0xc2da))
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
static int alps_get_otp_values_ss4_v2(struct psmouse *psmouse,
unsigned char index, unsigned char otp[])
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
switch (index) {
case 0:
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM) ||
ps2_command(ps2dev, otp, PSMOUSE_CMD_GETINFO))
return -1;
break;
case 1:
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETPOLL) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETPOLL) ||
ps2_command(ps2dev, otp, PSMOUSE_CMD_GETINFO))
return -1;
break;
}
return 0;
}
static int alps_update_device_area_ss4_v2(unsigned char otp[][4],
struct alps_data *priv)
{
int num_x_electrode;
int num_y_electrode;
int x_pitch, y_pitch, x_phys, y_phys;
num_x_electrode = SS4_NUMSENSOR_XOFFSET + (otp[1][0] & 0x0F);
num_y_electrode = SS4_NUMSENSOR_YOFFSET + ((otp[1][0] >> 4) & 0x0F);
priv->x_max = (num_x_electrode - 1) * SS4_COUNT_PER_ELECTRODE;
priv->y_max = (num_y_electrode - 1) * SS4_COUNT_PER_ELECTRODE;
x_pitch = ((otp[1][2] >> 2) & 0x07) + SS4_MIN_PITCH_MM;
y_pitch = ((otp[1][2] >> 5) & 0x07) + SS4_MIN_PITCH_MM;
x_phys = x_pitch * (num_x_electrode - 1);
y_phys = y_pitch * (num_y_electrode - 1);
priv->x_res = priv->x_max * 10 / x_phys;
priv->y_res = priv->y_max * 10 / y_phys;
return 0;
}
static int alps_update_btn_info_ss4_v2(unsigned char otp[][4],
struct alps_data *priv)
{
unsigned char is_btnless;
is_btnless = (otp[1][1] >> 3) & 0x01;
if (is_btnless)
priv->flags |= ALPS_BUTTONPAD;
return 0;
}
static int alps_set_defaults_ss4_v2(struct psmouse *psmouse,
struct alps_data *priv)
{
unsigned char otp[2][4];
memset(otp, 0, sizeof(otp));
if (alps_get_otp_values_ss4_v2(psmouse, 0, &otp[0][0]) ||
alps_get_otp_values_ss4_v2(psmouse, 1, &otp[1][0]))
return -1;
alps_update_device_area_ss4_v2(otp, priv);
alps_update_btn_info_ss4_v2(otp, priv);
return 0;
}
static int alps_dolphin_get_device_area(struct psmouse *psmouse,
struct alps_data *priv)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4] = {0};
int num_x_electrode, num_y_electrode;
if (alps_enter_command_mode(psmouse))
return -1;
param[0] = 0x0a;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_RESET_WRAP) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETPOLL) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETPOLL) ||
ps2_command(ps2dev, &param[0], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, &param[0], PSMOUSE_CMD_SETRATE))
return -1;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return -1;
num_x_electrode = DOLPHIN_PROFILE_XOFFSET + (param[2] & 0x0F);
num_y_electrode = DOLPHIN_PROFILE_YOFFSET + ((param[2] >> 4) & 0x0F);
priv->x_bits = num_x_electrode;
priv->y_bits = num_y_electrode;
priv->x_max = (num_x_electrode - 1) * DOLPHIN_COUNT_PER_ELECTRODE;
priv->y_max = (num_y_electrode - 1) * DOLPHIN_COUNT_PER_ELECTRODE;
if (alps_exit_command_mode(psmouse))
return -1;
return 0;
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
static int alps_hw_init_v7(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int reg_val, ret = -1;
if (alps_enter_command_mode(psmouse) ||
alps_command_mode_read_reg(psmouse, 0xc2d9) == -1)
goto error;
if (alps_get_v3_v7_resolution(psmouse, 0xc397))
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
static int alps_hw_init_ss4_v2(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
char param[2] = {0x64, 0x28};
int ret = -1;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSTREAM) ||
ps2_command(ps2dev, &param[0], PSMOUSE_CMD_SETRATE) ||
ps2_command(ps2dev, &param[1], PSMOUSE_CMD_SETRATE)) {
goto error;
}
if (alps_exit_command_mode(psmouse) ||
alps_enter_command_mode(psmouse) ||
alps_command_mode_write_reg(psmouse, 0x001D, 0x20)) {
goto error;
}
alps_exit_command_mode(psmouse);
return ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE);
error:
alps_exit_command_mode(psmouse);
return ret;
}
static int alps_set_protocol(struct psmouse *psmouse,
struct alps_data *priv,
const struct alps_protocol_info *protocol)
{
psmouse->private = priv;
setup_timer(&priv->timer, alps_flush_packet, (unsigned long)psmouse);
priv->proto_version = protocol->version;
priv->byte0 = protocol->byte0;
priv->mask0 = protocol->mask0;
priv->flags = protocol->flags;
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
priv->x_max = 1023;
priv->y_max = 767;
if (dmi_check_system(alps_dmi_has_separate_stick_buttons))
priv->flags |= ALPS_STICK_BITS;
break;
case ALPS_PROTO_V3:
priv->hw_init = alps_hw_init_v3;
priv->process_packet = alps_process_packet_v3;
priv->set_abs_params = alps_set_abs_params_semi_mt;
priv->decode_fields = alps_decode_pinnacle;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
break;
case ALPS_PROTO_V3_RUSHMORE:
priv->hw_init = alps_hw_init_rushmore_v3;
priv->process_packet = alps_process_packet_v3;
priv->set_abs_params = alps_set_abs_params_semi_mt;
priv->decode_fields = alps_decode_rushmore;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
priv->x_bits = 16;
priv->y_bits = 12;
if (alps_probe_trackstick_v3(psmouse,
ALPS_REG_BASE_RUSHMORE) < 0)
priv->flags &= ~ALPS_DUALPOINT;
break;
case ALPS_PROTO_V4:
priv->hw_init = alps_hw_init_v4;
priv->process_packet = alps_process_packet_v4;
priv->set_abs_params = alps_set_abs_params_semi_mt;
priv->nibble_commands = alps_v4_nibble_commands;
priv->addr_command = PSMOUSE_CMD_DISABLE;
break;
case ALPS_PROTO_V5:
priv->hw_init = alps_hw_init_dolphin_v1;
priv->process_packet = alps_process_touchpad_packet_v3_v5;
priv->decode_fields = alps_decode_dolphin;
priv->set_abs_params = alps_set_abs_params_semi_mt;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
priv->x_bits = 23;
priv->y_bits = 12;
if (alps_dolphin_get_device_area(psmouse, priv))
return -EIO;
break;
case ALPS_PROTO_V6:
priv->hw_init = alps_hw_init_v6;
priv->process_packet = alps_process_packet_v6;
priv->set_abs_params = alps_set_abs_params_st;
priv->nibble_commands = alps_v6_nibble_commands;
priv->x_max = 2047;
priv->y_max = 1535;
break;
case ALPS_PROTO_V7:
priv->hw_init = alps_hw_init_v7;
priv->process_packet = alps_process_packet_v7;
priv->decode_fields = alps_decode_packet_v7;
priv->set_abs_params = alps_set_abs_params_v7;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
priv->x_max = 0xfff;
priv->y_max = 0x7ff;
if (priv->fw_ver[1] != 0xba)
priv->flags |= ALPS_BUTTONPAD;
break;
case ALPS_PROTO_V8:
priv->hw_init = alps_hw_init_ss4_v2;
priv->process_packet = alps_process_packet_ss4_v2;
priv->decode_fields = alps_decode_ss4_v2;
priv->set_abs_params = alps_set_abs_params_ss4_v2;
priv->nibble_commands = alps_v3_nibble_commands;
priv->addr_command = PSMOUSE_CMD_RESET_WRAP;
if (alps_set_defaults_ss4_v2(psmouse, priv))
return -EIO;
break;
}
return 0;
}
static const struct alps_protocol_info *alps_match_table(unsigned char *e7,
unsigned char *ec)
{
const struct alps_model_info *model;
int i;
for (i = 0; i < ARRAY_SIZE(alps_model_data); i++) {
model = &alps_model_data[i];
if (!memcmp(e7, model->signature, sizeof(model->signature)) &&
(!model->command_mode_resp ||
model->command_mode_resp == ec[2])) {
return &model->protocol_info;
}
}
return NULL;
}
static int alps_identify(struct psmouse *psmouse, struct alps_data *priv)
{
const struct alps_protocol_info *protocol;
unsigned char e6[4], e7[4], ec[4];
int error;
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
protocol = alps_match_table(e7, ec);
if (!protocol) {
if (e7[0] == 0x73 && e7[1] == 0x03 && e7[2] == 0x50 &&
ec[0] == 0x73 && (ec[1] == 0x01 || ec[1] == 0x02)) {
protocol = &alps_v5_protocol_data;
} else if (ec[0] == 0x88 &&
((ec[1] & 0xf0) == 0xb0 || (ec[1] & 0xf0) == 0xc0)) {
protocol = &alps_v7_protocol_data;
} else if (ec[0] == 0x88 && ec[1] == 0x08) {
protocol = &alps_v3_rushmore_data;
} else if (ec[0] == 0x88 && ec[1] == 0x07 &&
ec[2] >= 0x90 && ec[2] <= 0x9d) {
protocol = &alps_v3_protocol_data;
} else if (e7[0] == 0x73 && e7[1] == 0x03 &&
e7[2] == 0x14 && ec[1] == 0x02) {
protocol = &alps_v8_protocol_data;
} else {
psmouse_dbg(psmouse,
"Likely not an ALPS touchpad: E7=%3ph, EC=%3ph\n", e7, ec);
return -EINVAL;
}
}
if (priv) {
memcpy(priv->fw_ver, ec, 3);
error = alps_set_protocol(psmouse, priv, protocol);
if (error)
return error;
}
return 0;
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
if (priv->dev2)
input_unregister_device(priv->dev2);
if (!IS_ERR_OR_NULL(priv->dev3))
input_unregister_device(priv->dev3);
kfree(priv);
}
static void alps_set_abs_params_st(struct alps_data *priv,
struct input_dev *dev1)
{
input_set_abs_params(dev1, ABS_X, 0, priv->x_max, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, priv->y_max, 0, 0);
input_set_abs_params(dev1, ABS_PRESSURE, 0, 127, 0, 0);
}
static void alps_set_abs_params_mt_common(struct alps_data *priv,
struct input_dev *dev1)
{
input_set_abs_params(dev1, ABS_MT_POSITION_X, 0, priv->x_max, 0, 0);
input_set_abs_params(dev1, ABS_MT_POSITION_Y, 0, priv->y_max, 0, 0);
input_abs_set_res(dev1, ABS_MT_POSITION_X, priv->x_res);
input_abs_set_res(dev1, ABS_MT_POSITION_Y, priv->y_res);
set_bit(BTN_TOOL_TRIPLETAP, dev1->keybit);
set_bit(BTN_TOOL_QUADTAP, dev1->keybit);
}
static void alps_set_abs_params_semi_mt(struct alps_data *priv,
struct input_dev *dev1)
{
alps_set_abs_params_mt_common(priv, dev1);
input_set_abs_params(dev1, ABS_PRESSURE, 0, 127, 0, 0);
input_mt_init_slots(dev1, MAX_TOUCHES,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED |
INPUT_MT_SEMI_MT);
}
static void alps_set_abs_params_v7(struct alps_data *priv,
struct input_dev *dev1)
{
alps_set_abs_params_mt_common(priv, dev1);
set_bit(BTN_TOOL_QUINTTAP, dev1->keybit);
input_mt_init_slots(dev1, MAX_TOUCHES,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED |
INPUT_MT_TRACK);
set_bit(BTN_TOOL_QUINTTAP, dev1->keybit);
}
static void alps_set_abs_params_ss4_v2(struct alps_data *priv,
struct input_dev *dev1)
{
alps_set_abs_params_mt_common(priv, dev1);
input_set_abs_params(dev1, ABS_PRESSURE, 0, 127, 0, 0);
set_bit(BTN_TOOL_QUINTTAP, dev1->keybit);
input_mt_init_slots(dev1, MAX_TOUCHES,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED |
INPUT_MT_TRACK);
}
int alps_init(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
struct input_dev *dev1 = psmouse->dev;
int error;
error = priv->hw_init(psmouse);
if (error)
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
} else if (priv->flags & ALPS_BUTTONPAD) {
set_bit(INPUT_PROP_BUTTONPAD, dev1->propbit);
clear_bit(BTN_RIGHT, dev1->keybit);
} else {
dev1->keybit[BIT_WORD(BTN_MIDDLE)] |= BIT_MASK(BTN_MIDDLE);
}
if (priv->flags & ALPS_DUALPOINT) {
struct input_dev *dev2;
dev2 = input_allocate_device();
if (!dev2) {
psmouse_err(psmouse,
"failed to allocate trackstick device\n");
error = -ENOMEM;
goto init_fail;
}
snprintf(priv->phys2, sizeof(priv->phys2), "%s/input1",
psmouse->ps2dev.serio->phys);
dev2->phys = priv->phys2;
dev2->name = "AlpsPS/2 ALPS DualPoint Stick";
dev2->id.bustype = BUS_I8042;
dev2->id.vendor = 0x0002;
dev2->id.product = PSMOUSE_ALPS;
dev2->id.version = priv->proto_version;
dev2->dev.parent = &psmouse->ps2dev.serio->dev;
input_set_capability(dev2, EV_REL, REL_X);
input_set_capability(dev2, EV_REL, REL_Y);
input_set_capability(dev2, EV_KEY, BTN_LEFT);
input_set_capability(dev2, EV_KEY, BTN_RIGHT);
input_set_capability(dev2, EV_KEY, BTN_MIDDLE);
__set_bit(INPUT_PROP_POINTER, dev2->propbit);
__set_bit(INPUT_PROP_POINTING_STICK, dev2->propbit);
error = input_register_device(dev2);
if (error) {
psmouse_err(psmouse,
"failed to register trackstick device: %d\n",
error);
input_free_device(dev2);
goto init_fail;
}
priv->dev2 = dev2;
}
priv->psmouse = psmouse;
INIT_DELAYED_WORK(&priv->dev3_register_work,
alps_register_bare_ps2_mouse);
psmouse->protocol_handler = alps_process_byte;
psmouse->poll = alps_poll;
psmouse->disconnect = alps_disconnect;
psmouse->reconnect = alps_reconnect;
psmouse->pktsize = priv->proto_version == ALPS_PROTO_V4 ? 8 : 6;
psmouse->resync_time = 0;
psmouse->resetafter = psmouse->pktsize * 2;
return 0;
init_fail:
psmouse_reset(psmouse);
kfree(psmouse->private);
psmouse->private = NULL;
return error;
}
int alps_detect(struct psmouse *psmouse, bool set_properties)
{
struct alps_data *priv;
int error;
error = alps_identify(psmouse, NULL);
if (error)
return error;
psmouse_reset(psmouse);
priv = kzalloc(sizeof(struct alps_data), GFP_KERNEL);
if (!priv)
return -ENOMEM;
error = alps_identify(psmouse, priv);
if (error) {
kfree(priv);
return error;
}
if (set_properties) {
psmouse->vendor = "ALPS";
psmouse->name = priv->flags & ALPS_DUALPOINT ?
"DualPoint TouchPad" : "GlidePoint";
psmouse->model = priv->proto_version;
} else {
kfree(priv);
psmouse->private = NULL;
}
return 0;
}
