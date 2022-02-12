static void wacom_handle_model_response(struct wacom *wacom)
{
int major_v, minor_v, r = 0;
char *p;
p = strrchr(wacom->data, 'V');
if (p)
r = sscanf(p + 1, "%u.%u", &major_v, &minor_v);
if (r != 2)
major_v = minor_v = 0;
switch (wacom->data[2] << 8 | wacom->data[3]) {
case MODEL_CINTIQ:
case MODEL_CINTIQ2:
if ((wacom->data[2] << 8 | wacom->data[3]) == MODEL_CINTIQ) {
wacom->dev->name = "Wacom Cintiq";
wacom->dev->id.version = MODEL_CINTIQ;
} else {
wacom->dev->name = "Wacom Cintiq II";
wacom->dev->id.version = MODEL_CINTIQ2;
}
wacom->res_x = 508;
wacom->res_y = 508;
switch (wacom->data[5] << 8 | wacom->data[6]) {
case 0x3731:
wacom->res_x = 2540;
wacom->res_y = 2540;
case 0x3535:
case 0x3830:
wacom->extra_z_bits = 2;
}
wacom->flags = F_COVERS_SCREEN;
break;
case MODEL_PENPARTNER:
wacom->dev->name = "Wacom Penpartner";
wacom->dev->id.version = MODEL_PENPARTNER;
wacom->res_x = 1000;
wacom->res_y = 1000;
break;
case MODEL_GRAPHIRE:
wacom->dev->name = "Wacom Graphire";
wacom->dev->id.version = MODEL_GRAPHIRE;
wacom->res_x = 1016;
wacom->res_y = 1016;
wacom->max_x = 5103;
wacom->max_y = 3711;
wacom->extra_z_bits = 2;
wacom->eraser_mask = 0x08;
wacom->flags = F_HAS_STYLUS2 | F_HAS_SCROLLWHEEL;
break;
case MODEL_DIGITIZER_II:
wacom->dev->name = "Wacom Digitizer II";
wacom->dev->id.version = MODEL_DIGITIZER_II;
if (major_v == 1 && minor_v <= 2)
wacom->extra_z_bits = 0;
break;
default:
dev_err(&wacom->dev->dev, "Unsupported Wacom model %s\n",
wacom->data);
wacom->result = -ENODEV;
return;
}
dev_info(&wacom->dev->dev, "%s tablet, version %u.%u\n",
wacom->dev->name, major_v, minor_v);
}
static void wacom_handle_configuration_response(struct wacom *wacom)
{
int r, skip;
dev_dbg(&wacom->dev->dev, "Configuration string: %s\n", wacom->data);
r = sscanf(wacom->data, "~R%x,%u,%u,%u,%u", &skip, &skip, &skip,
&wacom->res_x, &wacom->res_y);
if (r != 5)
dev_warn(&wacom->dev->dev, "could not get resolution\n");
}
static void wacom_handle_coordinates_response(struct wacom *wacom)
{
int r;
dev_dbg(&wacom->dev->dev, "Coordinates string: %s\n", wacom->data);
r = sscanf(wacom->data, "~C%u,%u", &wacom->max_x, &wacom->max_y);
if (r != 2)
dev_warn(&wacom->dev->dev, "could not get max coordinates\n");
}
static void wacom_handle_response(struct wacom *wacom)
{
if (wacom->data[0] != '~' || wacom->data[1] != wacom->expect) {
dev_err(&wacom->dev->dev,
"Wacom got an unexpected response: %s\n", wacom->data);
wacom->result = -EIO;
} else {
wacom->result = 0;
switch (wacom->data[1]) {
case '#':
wacom_handle_model_response(wacom);
break;
case 'R':
wacom_handle_configuration_response(wacom);
break;
case 'C':
wacom_handle_coordinates_response(wacom);
break;
}
}
complete(&wacom->cmd_done);
}
static void wacom_handle_packet(struct wacom *wacom)
{
u8 in_proximity_p, stylus_p, button;
unsigned int tool;
int x, y, z;
in_proximity_p = wacom->data[0] & 0x40;
stylus_p = wacom->data[0] & 0x20;
button = (wacom->data[3] & 0x78) >> 3;
x = (wacom->data[0] & 3) << 14 | wacom->data[1]<<7 | wacom->data[2];
y = (wacom->data[3] & 3) << 14 | wacom->data[4]<<7 | wacom->data[5];
if (in_proximity_p && stylus_p) {
z = wacom->data[6] & 0x7f;
if (wacom->extra_z_bits >= 1)
z = z << 1 | (wacom->data[3] & 0x4) >> 2;
if (wacom->extra_z_bits > 1)
z = z << 1 | (wacom->data[0] & 0x4) >> 2;
z = z ^ (0x40 << wacom->extra_z_bits);
} else {
z = -1;
}
if (stylus_p)
tool = (button & wacom->eraser_mask) ? ERASER : STYLUS;
else
tool = CURSOR;
if (tool != wacom->tool && wacom->tool != 0) {
input_report_key(wacom->dev, tools[wacom->tool].input_id, 0);
input_sync(wacom->dev);
}
wacom->tool = tool;
input_report_key(wacom->dev, tools[tool].input_id, in_proximity_p);
input_report_abs(wacom->dev, ABS_MISC,
in_proximity_p ? tools[tool].device_id : 0);
input_report_abs(wacom->dev, ABS_X, x);
input_report_abs(wacom->dev, ABS_Y, y);
input_report_abs(wacom->dev, ABS_PRESSURE, z);
if (stylus_p) {
input_report_key(wacom->dev, BTN_TOUCH, button & 1);
input_report_key(wacom->dev, BTN_STYLUS, button & 2);
input_report_key(wacom->dev, BTN_STYLUS2, button & 4);
} else {
input_report_key(wacom->dev, BTN_LEFT, button & 1);
input_report_key(wacom->dev, BTN_RIGHT, button & 2);
input_report_key(wacom->dev, BTN_MIDDLE, button & 4);
z = (wacom->data[6] & 0x30) >> 4;
if (wacom->data[6] & 0x40)
z = -z;
input_report_rel(wacom->dev, REL_WHEEL, z);
}
input_sync(wacom->dev);
}
static void wacom_clear_data_buf(struct wacom *wacom)
{
memset(wacom->data, 0, DATA_SIZE);
wacom->idx = 0;
}
static irqreturn_t wacom_interrupt(struct serio *serio, unsigned char data,
unsigned int flags)
{
struct wacom *wacom = serio_get_drvdata(serio);
if (data & 0x80)
wacom->idx = 0;
if (data == '\r' && !(wacom->data[0] & 0x80)) {
wacom_handle_response(wacom);
wacom_clear_data_buf(wacom);
return IRQ_HANDLED;
}
if (wacom->idx > (DATA_SIZE - 2)) {
dev_dbg(&wacom->dev->dev,
"throwing away %d bytes of garbage\n", wacom->idx);
wacom_clear_data_buf(wacom);
}
wacom->data[wacom->idx++] = data;
if (wacom->idx == PACKET_LENGTH && (wacom->data[0] & 0x80)) {
wacom_handle_packet(wacom);
wacom_clear_data_buf(wacom);
}
return IRQ_HANDLED;
}
static void wacom_disconnect(struct serio *serio)
{
struct wacom *wacom = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(wacom->dev);
kfree(wacom);
}
static int wacom_send(struct serio *serio, const u8 *command)
{
int err = 0;
for (; !err && *command; command++)
err = serio_write(serio, *command);
return err;
}
static int wacom_send_setup_string(struct wacom *wacom, struct serio *serio)
{
const u8 *cmd;
switch (wacom->dev->id.version) {
case MODEL_CINTIQ:
cmd = COMMAND_ORIGIN_IN_UPPER_LEFT
COMMAND_TRANSMIT_AT_MAX_RATE
COMMAND_ENABLE_CONTINUOUS_MODE
COMMAND_START_SENDING_PACKETS;
break;
case MODEL_PENPARTNER:
cmd = COMMAND_ENABLE_PRESSURE_MODE
COMMAND_START_SENDING_PACKETS;
break;
default:
cmd = COMMAND_MULTI_MODE_INPUT
COMMAND_ORIGIN_IN_UPPER_LEFT
COMMAND_ENABLE_ALL_MACRO_BUTTONS
COMMAND_DISABLE_GROUP_1_MACRO_BUTTONS
COMMAND_TRANSMIT_AT_MAX_RATE
COMMAND_DISABLE_INCREMENTAL_MODE
COMMAND_ENABLE_CONTINUOUS_MODE
COMMAND_Z_FILTER
COMMAND_START_SENDING_PACKETS;
break;
}
return wacom_send(serio, cmd);
}
static int wacom_send_and_wait(struct wacom *wacom, struct serio *serio,
const u8 *cmd, const char *desc)
{
int err;
unsigned long u;
wacom->expect = cmd[1];
init_completion(&wacom->cmd_done);
err = wacom_send(serio, cmd);
if (err)
return err;
u = wait_for_completion_timeout(&wacom->cmd_done, HZ);
if (u == 0) {
wacom_handle_response(wacom);
}
wacom->expect = 0;
return wacom->result;
}
static int wacom_setup(struct wacom *wacom, struct serio *serio)
{
int err;
err = wacom_send_and_wait(wacom, serio, REQUEST_MODEL_AND_ROM_VERSION,
"model and version");
if (err)
return err;
if (!(wacom->res_x && wacom->res_y)) {
err = wacom_send_and_wait(wacom, serio,
REQUEST_CONFIGURATION_STRING,
"configuration string");
if (err)
return err;
}
if (!(wacom->max_x && wacom->max_y)) {
err = wacom_send_and_wait(wacom, serio,
REQUEST_MAX_COORDINATES,
"coordinates string");
if (err)
return err;
}
return wacom_send_setup_string(wacom, serio);
}
static int wacom_connect(struct serio *serio, struct serio_driver *drv)
{
struct wacom *wacom;
struct input_dev *input_dev;
int err = -ENOMEM;
wacom = kzalloc(sizeof(struct wacom), GFP_KERNEL);
input_dev = input_allocate_device();
if (!wacom || !input_dev)
goto free_device;
wacom->dev = input_dev;
wacom->extra_z_bits = 1;
wacom->eraser_mask = 0x04;
wacom->tool = wacom->idx = 0;
snprintf(wacom->phys, sizeof(wacom->phys), "%s/input0", serio->phys);
input_dev->phys = wacom->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_WACOM_IV;
input_dev->id.product = serio->id.extra;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] =
BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS) | BIT_MASK(EV_REL);
set_bit(ABS_MISC, input_dev->absbit);
set_bit(BTN_TOOL_PEN, input_dev->keybit);
set_bit(BTN_TOOL_RUBBER, input_dev->keybit);
set_bit(BTN_TOOL_MOUSE, input_dev->keybit);
set_bit(BTN_TOUCH, input_dev->keybit);
set_bit(BTN_STYLUS, input_dev->keybit);
set_bit(BTN_LEFT, input_dev->keybit);
set_bit(BTN_RIGHT, input_dev->keybit);
set_bit(BTN_MIDDLE, input_dev->keybit);
serio_set_drvdata(serio, wacom);
err = serio_open(serio, drv);
if (err)
goto free_device;
err = wacom_setup(wacom, serio);
if (err)
goto close_serio;
set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
if (!(wacom->flags & F_COVERS_SCREEN))
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
if (wacom->flags & F_HAS_STYLUS2)
__set_bit(BTN_STYLUS2, input_dev->keybit);
if (wacom->flags & F_HAS_SCROLLWHEEL)
__set_bit(REL_WHEEL, input_dev->relbit);
input_abs_set_res(wacom->dev, ABS_X, wacom->res_x);
input_abs_set_res(wacom->dev, ABS_Y, wacom->res_y);
input_set_abs_params(wacom->dev, ABS_X, 0, wacom->max_x, 0, 0);
input_set_abs_params(wacom->dev, ABS_Y, 0, wacom->max_y, 0, 0);
input_set_abs_params(wacom->dev, ABS_PRESSURE, -1,
(1 << (7 + wacom->extra_z_bits)) - 1, 0, 0);
err = input_register_device(wacom->dev);
if (err)
goto close_serio;
return 0;
close_serio:
serio_close(serio);
free_device:
serio_set_drvdata(serio, NULL);
input_free_device(input_dev);
kfree(wacom);
return err;
}
