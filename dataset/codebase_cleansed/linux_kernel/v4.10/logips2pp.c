static psmouse_ret_t ps2pp_process_byte(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
unsigned char *packet = psmouse->packet;
if (psmouse->pktcnt < 3)
return PSMOUSE_GOOD_DATA;
if ((packet[0] & 0x48) == 0x48 && (packet[1] & 0x02) == 0x02) {
switch ((packet[1] >> 4) | (packet[0] & 0x30)) {
case 0x0d:
input_report_rel(dev, packet[2] & 0x80 ? REL_HWHEEL : REL_WHEEL,
(int) (packet[2] & 8) - (int) (packet[2] & 7));
input_report_key(dev, BTN_SIDE, (packet[2] >> 4) & 1);
input_report_key(dev, BTN_EXTRA, (packet[2] >> 5) & 1);
break;
case 0x0e:
input_report_key(dev, BTN_SIDE, (packet[2]) & 1);
input_report_key(dev, BTN_EXTRA, (packet[2] >> 1) & 1);
input_report_key(dev, BTN_BACK, (packet[2] >> 3) & 1);
input_report_key(dev, BTN_FORWARD, (packet[2] >> 4) & 1);
input_report_key(dev, BTN_TASK, (packet[2] >> 2) & 1);
break;
case 0x0f:
input_report_rel(dev, packet[2] & 0x08 ? REL_HWHEEL : REL_WHEEL,
(int) ((packet[2] >> 4) & 8) - (int) ((packet[2] >> 4) & 7));
packet[0] = packet[2] | 0x08;
break;
default:
psmouse_dbg(psmouse,
"Received PS2++ packet #%x, but don't know how to handle.\n",
(packet[1] >> 4) | (packet[0] & 0x30));
break;
}
} else {
input_report_rel(dev, REL_X, packet[1] ? (int) packet[1] - (int) ((packet[0] << 4) & 0x100) : 0);
input_report_rel(dev, REL_Y, packet[2] ? (int) ((packet[0] << 3) & 0x100) - (int) packet[2] : 0);
}
input_report_key(dev, BTN_LEFT, packet[0] & 1);
input_report_key(dev, BTN_MIDDLE, (packet[0] >> 2) & 1);
input_report_key(dev, BTN_RIGHT, (packet[0] >> 1) & 1);
input_sync(dev);
return PSMOUSE_FULL_PACKET;
}
static int ps2pp_cmd(struct psmouse *psmouse, unsigned char *param, unsigned char command)
{
if (psmouse_sliced_command(psmouse, command))
return -1;
if (ps2_command(&psmouse->ps2dev, param, PSMOUSE_CMD_POLL | 0x0300))
return -1;
return 0;
}
static void ps2pp_set_smartscroll(struct psmouse *psmouse, bool smartscroll)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4];
ps2pp_cmd(psmouse, param, 0x32);
param[0] = 0;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
param[0] = smartscroll;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
}
static ssize_t ps2pp_attr_show_smartscroll(struct psmouse *psmouse,
void *data, char *buf)
{
return sprintf(buf, "%d\n", psmouse->smartscroll);
}
static ssize_t ps2pp_attr_set_smartscroll(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
unsigned int value;
int err;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value > 1)
return -EINVAL;
ps2pp_set_smartscroll(psmouse, value);
psmouse->smartscroll = value;
return count;
}
static void ps2pp_set_resolution(struct psmouse *psmouse, unsigned int resolution)
{
if (resolution > 400) {
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param = 3;
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
ps2_command(ps2dev, &param, PSMOUSE_CMD_SETRES);
psmouse->resolution = 800;
} else
psmouse_set_resolution(psmouse, resolution);
}
static void ps2pp_disconnect(struct psmouse *psmouse)
{
device_remove_file(&psmouse->ps2dev.serio->dev, &psmouse_attr_smartscroll.dattr);
}
static const struct ps2pp_info *get_model_info(unsigned char model)
{
static const struct ps2pp_info ps2pp_list[] = {
{ 1, 0, 0 },
{ 12, 0, PS2PP_SIDE_BTN},
{ 13, 0, 0 },
{ 15, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN | PS2PP_TASK_BTN |
PS2PP_EXTRA_BTN | PS2PP_NAV_BTN | PS2PP_HWHEEL },
{ 40, 0, PS2PP_SIDE_BTN },
{ 41, 0, PS2PP_SIDE_BTN },
{ 42, 0, PS2PP_SIDE_BTN },
{ 43, 0, PS2PP_SIDE_BTN },
{ 50, 0, 0 },
{ 51, 0, 0 },
{ 52, PS2PP_KIND_WHEEL, PS2PP_SIDE_BTN | PS2PP_WHEEL },
{ 53, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 56, PS2PP_KIND_WHEEL, PS2PP_SIDE_BTN | PS2PP_WHEEL },
{ 61, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN | PS2PP_TASK_BTN |
PS2PP_EXTRA_BTN | PS2PP_NAV_BTN },
{ 66, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN | PS2PP_TASK_BTN |
PS2PP_EXTRA_BTN | PS2PP_NAV_BTN | PS2PP_HWHEEL },
{ 72, PS2PP_KIND_TRACKMAN, 0 },
{ 73, PS2PP_KIND_TRACKMAN, PS2PP_SIDE_BTN },
{ 75, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 76, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 79, PS2PP_KIND_TRACKMAN, PS2PP_WHEEL },
{ 80, PS2PP_KIND_WHEEL, PS2PP_SIDE_BTN | PS2PP_WHEEL },
{ 81, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 83, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 85, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 86, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 87, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 88, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 96, 0, 0 },
{ 97, PS2PP_KIND_TP3, PS2PP_WHEEL | PS2PP_HWHEEL },
{ 99, PS2PP_KIND_WHEEL, PS2PP_WHEEL },
{ 100, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN | PS2PP_TASK_BTN |
PS2PP_EXTRA_BTN | PS2PP_NAV_BTN },
{ 111, PS2PP_KIND_MX, PS2PP_WHEEL | PS2PP_SIDE_BTN },
{ 112, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN | PS2PP_TASK_BTN |
PS2PP_EXTRA_BTN | PS2PP_NAV_BTN },
{ 114, PS2PP_KIND_MX,
PS2PP_WHEEL | PS2PP_SIDE_BTN |
PS2PP_TASK_BTN | PS2PP_EXTRA_BTN }
};
int i;
for (i = 0; i < ARRAY_SIZE(ps2pp_list); i++)
if (model == ps2pp_list[i].model)
return &ps2pp_list[i];
return NULL;
}
static void ps2pp_set_model_properties(struct psmouse *psmouse,
const struct ps2pp_info *model_info,
bool using_ps2pp)
{
struct input_dev *input_dev = psmouse->dev;
if (model_info->features & PS2PP_SIDE_BTN)
__set_bit(BTN_SIDE, input_dev->keybit);
if (model_info->features & PS2PP_EXTRA_BTN)
__set_bit(BTN_EXTRA, input_dev->keybit);
if (model_info->features & PS2PP_TASK_BTN)
__set_bit(BTN_TASK, input_dev->keybit);
if (model_info->features & PS2PP_NAV_BTN) {
__set_bit(BTN_FORWARD, input_dev->keybit);
__set_bit(BTN_BACK, input_dev->keybit);
}
if (model_info->features & PS2PP_WHEEL)
__set_bit(REL_WHEEL, input_dev->relbit);
if (model_info->features & PS2PP_HWHEEL)
__set_bit(REL_HWHEEL, input_dev->relbit);
switch (model_info->kind) {
case PS2PP_KIND_WHEEL:
psmouse->name = "Wheel Mouse";
break;
case PS2PP_KIND_MX:
psmouse->name = "MX Mouse";
break;
case PS2PP_KIND_TP3:
psmouse->name = "TouchPad 3";
break;
case PS2PP_KIND_TRACKMAN:
psmouse->name = "TrackMan";
break;
default:
if (using_ps2pp)
psmouse->name = "Mouse";
break;
}
}
int ps2pp_detect(struct psmouse *psmouse, bool set_properties)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[4];
unsigned char model, buttons;
const struct ps2pp_info *model_info;
bool use_ps2pp = false;
int error;
param[0] = 0;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE11);
param[1] = 0;
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO);
model = ((param[0] >> 4) & 0x07) | ((param[0] << 3) & 0x78);
buttons = param[1];
if (!model || !buttons)
return -1;
model_info = get_model_info(model);
if (model_info) {
if (model_info->kind == PS2PP_KIND_TP3) {
param[0] = 0x11; param[1] = 0x04; param[2] = 0x68;
ps2_command(ps2dev, param, 0x30d1);
param[0] = 0x11; param[1] = 0x05; param[2] = 0x0b;
ps2_command(ps2dev, param, 0x30d1);
param[0] = 0x11; param[1] = 0x09; param[2] = 0xc3;
ps2_command(ps2dev, param, 0x30d1);
param[0] = 0;
if (!ps2_command(ps2dev, param, 0x13d1) &&
param[0] == 0x06 && param[1] == 0x00 && param[2] == 0x14) {
use_ps2pp = true;
}
} else {
param[0] = param[1] = param[2] = 0;
ps2pp_cmd(psmouse, param, 0x39);
ps2pp_cmd(psmouse, param, 0xDB);
if ((param[0] & 0x78) == 0x48 &&
(param[1] & 0xf3) == 0xc2 &&
(param[2] & 0x03) == ((param[1] >> 2) & 3)) {
ps2pp_set_smartscroll(psmouse, false);
use_ps2pp = true;
}
}
} else {
psmouse_warn(psmouse, "Detected unknown Logitech mouse model %d\n", model);
}
if (set_properties) {
psmouse->vendor = "Logitech";
psmouse->model = model;
if (use_ps2pp) {
psmouse->protocol_handler = ps2pp_process_byte;
psmouse->pktsize = 3;
if (model_info->kind != PS2PP_KIND_TP3) {
psmouse->set_resolution = ps2pp_set_resolution;
psmouse->disconnect = ps2pp_disconnect;
error = device_create_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_smartscroll.dattr);
if (error) {
psmouse_err(psmouse,
"failed to create smartscroll sysfs attribute, error: %d\n",
error);
return -1;
}
}
}
if (buttons >= 3)
__set_bit(BTN_MIDDLE, psmouse->dev->keybit);
if (model_info)
ps2pp_set_model_properties(psmouse, model_info, use_ps2pp);
}
return use_ps2pp ? 0 : -1;
}
