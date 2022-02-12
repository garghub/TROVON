int focaltech_detect(struct psmouse *psmouse, bool set_properties)
{
if (!psmouse_matches_pnp_id(psmouse, focaltech_pnp_ids))
return -ENODEV;
if (set_properties) {
psmouse->vendor = "FocalTech";
psmouse->name = "FocalTech Touchpad";
}
return 0;
}
static void focaltech_reset(struct psmouse *psmouse)
{
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_RESET_DIS);
psmouse_reset(psmouse);
}
static void focaltech_report_state(struct psmouse *psmouse)
{
struct focaltech_data *priv = psmouse->private;
struct focaltech_hw_state *state = &priv->state;
struct input_dev *dev = psmouse->dev;
int i;
for (i = 0; i < FOC_MAX_FINGERS; i++) {
struct focaltech_finger_state *finger = &state->fingers[i];
bool active = finger->active && finger->valid;
input_mt_slot(dev, i);
input_mt_report_slot_state(dev, MT_TOOL_FINGER, active);
if (active) {
unsigned int clamped_x, clamped_y;
clamped_x = clamp(finger->x, 0U, priv->x_max);
clamped_y = clamp(finger->y, 0U, priv->y_max);
input_report_abs(dev, ABS_MT_POSITION_X, clamped_x);
input_report_abs(dev, ABS_MT_POSITION_Y,
priv->y_max - clamped_y);
input_report_abs(dev, ABS_TOOL_WIDTH, state->width);
}
}
input_mt_report_pointer_emulation(dev, true);
input_report_key(psmouse->dev, BTN_LEFT, state->pressed);
input_sync(psmouse->dev);
}
static void focaltech_process_touch_packet(struct psmouse *psmouse,
unsigned char *packet)
{
struct focaltech_data *priv = psmouse->private;
struct focaltech_hw_state *state = &priv->state;
unsigned char fingers = packet[1];
int i;
state->pressed = (packet[0] >> 4) & 1;
for (i = 0; i < FOC_MAX_FINGERS; i++) {
state->fingers[i].active = fingers & 0x1;
if (!state->fingers[i].active) {
state->fingers[i].valid = false;
}
fingers >>= 1;
}
}
static void focaltech_process_abs_packet(struct psmouse *psmouse,
unsigned char *packet)
{
struct focaltech_data *priv = psmouse->private;
struct focaltech_hw_state *state = &priv->state;
unsigned int finger;
finger = (packet[1] >> 4) - 1;
if (finger >= FOC_MAX_FINGERS) {
psmouse_err(psmouse, "Invalid finger in abs packet: %d\n",
finger);
return;
}
state->pressed = (packet[0] >> 4) & 1;
state->fingers[finger].x = ((packet[1] & 0xf) << 8) | packet[2];
state->fingers[finger].y = (packet[3] << 8) | packet[4];
state->width = packet[5] >> 4;
state->fingers[finger].valid = true;
}
static void focaltech_process_rel_packet(struct psmouse *psmouse,
unsigned char *packet)
{
struct focaltech_data *priv = psmouse->private;
struct focaltech_hw_state *state = &priv->state;
int finger1, finger2;
state->pressed = packet[0] >> 7;
finger1 = ((packet[0] >> 4) & 0x7) - 1;
if (finger1 < FOC_MAX_FINGERS) {
state->fingers[finger1].x += (char)packet[1];
state->fingers[finger1].y += (char)packet[2];
} else {
psmouse_err(psmouse, "First finger in rel packet invalid: %d\n",
finger1);
}
finger2 = ((packet[3] >> 4) & 0x7) - 1;
if (finger2 < FOC_MAX_FINGERS) {
state->fingers[finger2].x += (char)packet[4];
state->fingers[finger2].y += (char)packet[5];
}
}
static void focaltech_process_packet(struct psmouse *psmouse)
{
unsigned char *packet = psmouse->packet;
switch (packet[0] & 0xf) {
case FOC_TOUCH:
focaltech_process_touch_packet(psmouse, packet);
break;
case FOC_ABS:
focaltech_process_abs_packet(psmouse, packet);
break;
case FOC_REL:
focaltech_process_rel_packet(psmouse, packet);
break;
default:
psmouse_err(psmouse, "Unknown packet type: %02x\n", packet[0]);
break;
}
focaltech_report_state(psmouse);
}
static psmouse_ret_t focaltech_process_byte(struct psmouse *psmouse)
{
if (psmouse->pktcnt >= 6) {
focaltech_process_packet(psmouse);
return PSMOUSE_FULL_PACKET;
}
return PSMOUSE_GOOD_DATA;
}
static int focaltech_switch_protocol(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[3];
param[0] = 0;
if (ps2_command(ps2dev, param, 0x10f8))
return -EIO;
if (ps2_command(ps2dev, param, 0x10f8))
return -EIO;
if (ps2_command(ps2dev, param, 0x10f8))
return -EIO;
param[0] = 1;
if (ps2_command(ps2dev, param, 0x10f8))
return -EIO;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETSCALE11))
return -EIO;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_ENABLE))
return -EIO;
return 0;
}
static void focaltech_disconnect(struct psmouse *psmouse)
{
focaltech_reset(psmouse);
kfree(psmouse->private);
psmouse->private = NULL;
}
static int focaltech_reconnect(struct psmouse *psmouse)
{
int error;
focaltech_reset(psmouse);
error = focaltech_switch_protocol(psmouse);
if (error) {
psmouse_err(psmouse, "Unable to initialize the device\n");
return error;
}
return 0;
}
static void focaltech_set_input_params(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct focaltech_data *priv = psmouse->private;
__clear_bit(EV_REL, dev->evbit);
__clear_bit(REL_X, dev->relbit);
__clear_bit(REL_Y, dev->relbit);
__clear_bit(BTN_RIGHT, dev->keybit);
__clear_bit(BTN_MIDDLE, dev->keybit);
__set_bit(EV_ABS, dev->evbit);
input_set_abs_params(dev, ABS_MT_POSITION_X, 0, priv->x_max, 0, 0);
input_set_abs_params(dev, ABS_MT_POSITION_Y, 0, priv->y_max, 0, 0);
input_set_abs_params(dev, ABS_TOOL_WIDTH, 0, 15, 0, 0);
input_mt_init_slots(dev, 5, INPUT_MT_POINTER);
__set_bit(INPUT_PROP_BUTTONPAD, dev->propbit);
}
static int focaltech_read_register(struct ps2dev *ps2dev, int reg,
unsigned char *param)
{
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETSCALE11))
return -EIO;
param[0] = 0;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES))
return -EIO;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES))
return -EIO;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES))
return -EIO;
param[0] = reg;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES))
return -EIO;
if (ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
return -EIO;
return 0;
}
static int focaltech_read_size(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct focaltech_data *priv = psmouse->private;
char param[3];
if (focaltech_read_register(ps2dev, 2, param))
return -EIO;
priv->x_max = (unsigned char)param[1] * 128;
priv->y_max = (unsigned char)param[2] * 128;
return 0;
}
void focaltech_set_resolution(struct psmouse *psmouse, unsigned int resolution)
{
}
static void focaltech_set_rate(struct psmouse *psmouse, unsigned int rate)
{
}
static void focaltech_set_scale(struct psmouse *psmouse,
enum psmouse_scale scale)
{
}
int focaltech_init(struct psmouse *psmouse)
{
struct focaltech_data *priv;
int error;
psmouse->private = priv = kzalloc(sizeof(struct focaltech_data),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
focaltech_reset(psmouse);
error = focaltech_read_size(psmouse);
if (error) {
psmouse_err(psmouse,
"Unable to read the size of the touchpad\n");
goto fail;
}
error = focaltech_switch_protocol(psmouse);
if (error) {
psmouse_err(psmouse, "Unable to initialize the device\n");
goto fail;
}
focaltech_set_input_params(psmouse);
psmouse->protocol_handler = focaltech_process_byte;
psmouse->pktsize = 6;
psmouse->disconnect = focaltech_disconnect;
psmouse->reconnect = focaltech_reconnect;
psmouse->cleanup = focaltech_reset;
psmouse->resync_time = 0;
psmouse->set_resolution = focaltech_set_resolution;
psmouse->set_rate = focaltech_set_rate;
psmouse->set_scale = focaltech_set_scale;
return 0;
fail:
focaltech_reset(psmouse);
kfree(priv);
return error;
}
int focaltech_init(struct psmouse *psmouse)
{
focaltech_reset(psmouse);
return 0;
}
