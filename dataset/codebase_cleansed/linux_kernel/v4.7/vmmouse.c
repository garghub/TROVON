static void vmmouse_report_button(struct psmouse *psmouse,
struct input_dev *abs_dev,
struct input_dev *rel_dev,
struct input_dev *pref_dev,
unsigned int code, int value)
{
if (test_bit(code, abs_dev->key))
pref_dev = abs_dev;
else if (test_bit(code, rel_dev->key))
pref_dev = rel_dev;
input_report_key(pref_dev, code, value);
}
static psmouse_ret_t vmmouse_report_events(struct psmouse *psmouse)
{
struct input_dev *rel_dev = psmouse->dev;
struct vmmouse_data *priv = psmouse->private;
struct input_dev *abs_dev = priv->abs_dev;
struct input_dev *pref_dev;
u32 status, x, y, z;
u32 dummy1, dummy2, dummy3;
unsigned int queue_length;
unsigned int count = 255;
while (count--) {
VMMOUSE_CMD(ABSPOINTER_STATUS, 0,
status, dummy1, dummy2, dummy3);
if ((status & VMMOUSE_ERROR) == VMMOUSE_ERROR) {
psmouse_err(psmouse, "failed to fetch status data\n");
return PSMOUSE_BAD_DATA;
}
queue_length = status & 0xffff;
if (queue_length == 0)
break;
if (queue_length % 4) {
psmouse_err(psmouse, "invalid queue length\n");
return PSMOUSE_BAD_DATA;
}
VMMOUSE_CMD(ABSPOINTER_DATA, 4, status, x, y, z);
if (status & VMMOUSE_RELATIVE_PACKET) {
pref_dev = rel_dev;
input_report_rel(rel_dev, REL_X, (s32)x);
input_report_rel(rel_dev, REL_Y, -(s32)y);
} else {
pref_dev = abs_dev;
input_report_abs(abs_dev, ABS_X, x);
input_report_abs(abs_dev, ABS_Y, y);
}
input_report_rel(rel_dev, REL_WHEEL, -(s8)((u8) z));
vmmouse_report_button(psmouse, abs_dev, rel_dev,
pref_dev, BTN_LEFT,
status & VMMOUSE_LEFT_BUTTON);
vmmouse_report_button(psmouse, abs_dev, rel_dev,
pref_dev, BTN_RIGHT,
status & VMMOUSE_RIGHT_BUTTON);
vmmouse_report_button(psmouse, abs_dev, rel_dev,
pref_dev, BTN_MIDDLE,
status & VMMOUSE_MIDDLE_BUTTON);
input_sync(abs_dev);
input_sync(rel_dev);
}
return PSMOUSE_FULL_PACKET;
}
static psmouse_ret_t vmmouse_process_byte(struct psmouse *psmouse)
{
unsigned char *packet = psmouse->packet;
switch (psmouse->pktcnt) {
case 1:
return (packet[0] & 0x8) == 0x8 ?
PSMOUSE_GOOD_DATA : PSMOUSE_BAD_DATA;
case 2:
return PSMOUSE_GOOD_DATA;
default:
return vmmouse_report_events(psmouse);
}
}
static void vmmouse_disable(struct psmouse *psmouse)
{
u32 status;
u32 dummy1, dummy2, dummy3, dummy4;
VMMOUSE_CMD(ABSPOINTER_COMMAND, VMMOUSE_CMD_DISABLE,
dummy1, dummy2, dummy3, dummy4);
VMMOUSE_CMD(ABSPOINTER_STATUS, 0,
status, dummy1, dummy2, dummy3);
if ((status & VMMOUSE_ERROR) != VMMOUSE_ERROR)
psmouse_warn(psmouse, "failed to disable vmmouse device\n");
}
static int vmmouse_enable(struct psmouse *psmouse)
{
u32 status, version;
u32 dummy1, dummy2, dummy3, dummy4;
VMMOUSE_CMD(ABSPOINTER_COMMAND, VMMOUSE_CMD_ENABLE,
dummy1, dummy2, dummy3, dummy4);
VMMOUSE_CMD(ABSPOINTER_STATUS, 0, status, dummy1, dummy2, dummy3);
if ((status & 0x0000ffff) == 0) {
psmouse_dbg(psmouse, "empty flags - assuming no device\n");
return -ENXIO;
}
VMMOUSE_CMD(ABSPOINTER_DATA, 1 ,
version, dummy1, dummy2, dummy3);
if (version != VMMOUSE_VERSION_ID) {
psmouse_dbg(psmouse, "Unexpected version value: %u vs %u\n",
(unsigned) version, VMMOUSE_VERSION_ID);
vmmouse_disable(psmouse);
return -ENXIO;
}
VMMOUSE_CMD(ABSPOINTER_RESTRICT, VMMOUSE_RESTRICT_CPL0,
dummy1, dummy2, dummy3, dummy4);
VMMOUSE_CMD(ABSPOINTER_COMMAND, VMMOUSE_CMD_REQUEST_ABSOLUTE,
dummy1, dummy2, dummy3, dummy4);
return 0;
}
static bool vmmouse_check_hypervisor(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(vmmouse_supported_hypervisors); i++)
if (vmmouse_supported_hypervisors[i] == x86_hyper)
return true;
return false;
}
int vmmouse_detect(struct psmouse *psmouse, bool set_properties)
{
u32 response, version, dummy1, dummy2;
if (!vmmouse_check_hypervisor()) {
psmouse_dbg(psmouse,
"VMMouse not running on supported hypervisor.\n");
return -ENXIO;
}
response = ~VMMOUSE_PROTO_MAGIC;
VMMOUSE_CMD(GETVERSION, 0, version, response, dummy1, dummy2);
if (response != VMMOUSE_PROTO_MAGIC || version == 0xffffffffU)
return -ENXIO;
if (set_properties) {
psmouse->vendor = VMMOUSE_VENDOR;
psmouse->name = VMMOUSE_NAME;
psmouse->model = version;
}
return 0;
}
static void vmmouse_disconnect(struct psmouse *psmouse)
{
struct vmmouse_data *priv = psmouse->private;
vmmouse_disable(psmouse);
psmouse_reset(psmouse);
input_unregister_device(priv->abs_dev);
kfree(priv);
}
static int vmmouse_reconnect(struct psmouse *psmouse)
{
int error;
psmouse_reset(psmouse);
vmmouse_disable(psmouse);
error = vmmouse_enable(psmouse);
if (error) {
psmouse_err(psmouse,
"Unable to re-enable mouse when reconnecting, err: %d\n",
error);
return error;
}
return 0;
}
int vmmouse_init(struct psmouse *psmouse)
{
struct vmmouse_data *priv;
struct input_dev *rel_dev = psmouse->dev, *abs_dev;
int error;
psmouse_reset(psmouse);
error = vmmouse_enable(psmouse);
if (error)
return error;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
abs_dev = input_allocate_device();
if (!priv || !abs_dev) {
error = -ENOMEM;
goto init_fail;
}
priv->abs_dev = abs_dev;
psmouse->private = priv;
snprintf(priv->phys, sizeof(priv->phys), "%s/input1",
psmouse->ps2dev.serio->phys);
snprintf(priv->dev_name, sizeof(priv->dev_name), "%s %s %s",
VMMOUSE_PSNAME, VMMOUSE_VENDOR, VMMOUSE_NAME);
abs_dev->phys = priv->phys;
abs_dev->name = priv->dev_name;
abs_dev->id.bustype = BUS_I8042;
abs_dev->id.vendor = 0x0002;
abs_dev->id.product = PSMOUSE_VMMOUSE;
abs_dev->id.version = psmouse->model;
abs_dev->dev.parent = &psmouse->ps2dev.serio->dev;
input_set_capability(abs_dev, EV_KEY, BTN_LEFT);
input_set_capability(abs_dev, EV_KEY, BTN_RIGHT);
input_set_capability(abs_dev, EV_KEY, BTN_MIDDLE);
input_set_capability(abs_dev, EV_ABS, ABS_X);
input_set_capability(abs_dev, EV_ABS, ABS_Y);
input_set_abs_params(abs_dev, ABS_X, 0, VMMOUSE_MAX_X, 0, 0);
input_set_abs_params(abs_dev, ABS_Y, 0, VMMOUSE_MAX_Y, 0, 0);
error = input_register_device(priv->abs_dev);
if (error)
goto init_fail;
input_set_capability(rel_dev, EV_REL, REL_WHEEL);
psmouse->protocol_handler = vmmouse_process_byte;
psmouse->disconnect = vmmouse_disconnect;
psmouse->reconnect = vmmouse_reconnect;
return 0;
init_fail:
vmmouse_disable(psmouse);
psmouse_reset(psmouse);
input_free_device(abs_dev);
kfree(priv);
psmouse->private = NULL;
return error;
}
