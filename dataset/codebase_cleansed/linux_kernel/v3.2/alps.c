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
static void alps_process_packet(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
const struct alps_model_info *model = priv->i;
unsigned char *packet = psmouse->packet;
struct input_dev *dev = psmouse->dev;
struct input_dev *dev2 = priv->dev2;
int x, y, z, ges, fin, left, right, middle;
int back = 0, forward = 0;
if (model->flags & ALPS_OLDPROTO) {
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
"refusing packet %x %x %x %x (suspected interleaved ps/2)\n",
psmouse->packet[3], psmouse->packet[4],
psmouse->packet[5], psmouse->packet[6]);
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
if (psmouse->pktcnt == 6) {
if ((psmouse->packet[3] |
psmouse->packet[4] |
psmouse->packet[5]) & 0x80) {
psmouse_dbg(psmouse,
"refusing packet %x %x %x (suspected interleaved ps/2)\n",
psmouse->packet[3], psmouse->packet[4],
psmouse->packet[5]);
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
if (psmouse->pktcnt >= 2 && psmouse->pktcnt <= 6 &&
(psmouse->packet[psmouse->pktcnt - 1] & 0x80)) {
psmouse_dbg(psmouse, "refusing packet[%i] = %x\n",
psmouse->pktcnt - 1,
psmouse->packet[psmouse->pktcnt - 1]);
return PSMOUSE_BAD_DATA;
}
if (psmouse->pktcnt == 6) {
alps_process_packet(psmouse);
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_GOOD_DATA;
}
static const struct alps_model_info *alps_get_model(struct psmouse *psmouse, int *version)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
static const unsigned char rates[] = { 0, 10, 20, 40, 60, 80, 100, 200 };
unsigned char param[4];
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
if (param[0] != 0 || param[1] != 0 || (param[2] != 10 && param[2] != 100))
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
for (i = 0; i < ARRAY_SIZE(alps_model_data); i++)
if (!memcmp(param, alps_model_data[i].signature,
sizeof(alps_model_data[i].signature)))
return alps_model_data + i;
return NULL;
}
static int alps_passthrough_mode(struct psmouse *psmouse, bool enable)
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
static int alps_absolute_mode(struct psmouse *psmouse)
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
unsigned char buf[6];
bool poll_failed;
if (priv->i->flags & ALPS_PASS)
alps_passthrough_mode(psmouse, true);
poll_failed = ps2_command(&psmouse->ps2dev, buf,
PSMOUSE_CMD_POLL | (psmouse->pktsize << 8)) < 0;
if (priv->i->flags & ALPS_PASS)
alps_passthrough_mode(psmouse, false);
if (poll_failed || (buf[0] & priv->i->mask0) != priv->i->byte0)
return -1;
if ((psmouse->badbyte & 0xc8) == 0x08) {
if (ps2_command(&psmouse->ps2dev, buf, PSMOUSE_CMD_POLL | (3 << 8)))
return -1;
}
memcpy(psmouse->packet, buf, sizeof(buf));
return 0;
}
static int alps_hw_init(struct psmouse *psmouse)
{
struct alps_data *priv = psmouse->private;
const struct alps_model_info *model = priv->i;
if ((model->flags & ALPS_PASS) &&
alps_passthrough_mode(psmouse, true)) {
return -1;
}
if (alps_tap_mode(psmouse, true)) {
psmouse_warn(psmouse, "Failed to enable hardware tapping\n");
return -1;
}
if (alps_absolute_mode(psmouse)) {
psmouse_err(psmouse, "Failed to enable absolute mode\n");
return -1;
}
if ((model->flags & ALPS_PASS) &&
alps_passthrough_mode(psmouse, false)) {
return -1;
}
if (ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_SETSTREAM)) {
psmouse_err(psmouse, "Failed to enable stream mode\n");
return -1;
}
return 0;
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
input_set_abs_params(dev1, ABS_X, 0, 1023, 0, 0);
input_set_abs_params(dev1, ABS_Y, 0, 767, 0, 0);
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
psmouse->pktsize = 6;
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
