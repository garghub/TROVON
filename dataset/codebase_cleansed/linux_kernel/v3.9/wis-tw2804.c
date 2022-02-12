static int write_reg(struct i2c_client *client, u8 reg, u8 value, int channel)
{
return i2c_smbus_write_byte_data(client, reg | (channel << 6), value);
}
static int write_regs(struct i2c_client *client, u8 *regs, int channel)
{
int i;
for (i = 0; regs[i] != 0xff; i += 2)
if (i2c_smbus_write_byte_data(client,
regs[i] | (channel << 6), regs[i + 1]) < 0)
return -1;
return 0;
}
static int wis_tw2804_command(struct i2c_client *client,
unsigned int cmd, void *arg)
{
struct wis_tw2804 *dec = i2c_get_clientdata(client);
if (cmd == DECODER_SET_CHANNEL) {
int *input = arg;
if (*input < 0 || *input > 3) {
dev_err(&client->dev,
"channel %d is not between 0 and 3!\n", *input);
return 0;
}
dec->channel = *input;
dev_dbg(&client->dev, "initializing TW2804 channel %d\n",
dec->channel);
if (dec->channel == 0 &&
write_regs(client, global_registers, 0) < 0) {
dev_err(&client->dev,
"error initializing TW2804 global registers\n");
return 0;
}
if (write_regs(client, channel_registers, dec->channel) < 0) {
dev_err(&client->dev,
"error initializing TW2804 channel %d\n",
dec->channel);
return 0;
}
return 0;
}
if (dec->channel < 0) {
dev_dbg(&client->dev,
"ignoring command %08x until channel number is set\n",
cmd);
return 0;
}
switch (cmd) {
case VIDIOC_S_STD:
{
v4l2_std_id *input = arg;
u8 regs[] = {
0x01, *input & V4L2_STD_NTSC ? 0xc4 : 0x84,
0x09, *input & V4L2_STD_NTSC ? 0x07 : 0x04,
0x0a, *input & V4L2_STD_NTSC ? 0xf0 : 0x20,
0x0b, *input & V4L2_STD_NTSC ? 0x07 : 0x04,
0x0c, *input & V4L2_STD_NTSC ? 0xf0 : 0x20,
0x0d, *input & V4L2_STD_NTSC ? 0x40 : 0x4a,
0x16, *input & V4L2_STD_NTSC ? 0x00 : 0x40,
0x17, *input & V4L2_STD_NTSC ? 0x00 : 0x40,
0x20, *input & V4L2_STD_NTSC ? 0x07 : 0x0f,
0x21, *input & V4L2_STD_NTSC ? 0x07 : 0x0f,
0xff, 0xff,
};
write_regs(client, regs, dec->channel);
dec->norm = *input;
break;
}
case VIDIOC_QUERYCTRL:
{
struct v4l2_queryctrl *ctrl = arg;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Brightness", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 255;
ctrl->step = 1;
ctrl->default_value = 128;
ctrl->flags = 0;
break;
case V4L2_CID_CONTRAST:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Contrast", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 255;
ctrl->step = 1;
ctrl->default_value = 128;
ctrl->flags = 0;
break;
case V4L2_CID_SATURATION:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Saturation", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 255;
ctrl->step = 1;
ctrl->default_value = 128;
ctrl->flags = 0;
break;
case V4L2_CID_HUE:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Hue", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 255;
ctrl->step = 1;
ctrl->default_value = 128;
ctrl->flags = 0;
break;
}
break;
}
case VIDIOC_S_CTRL:
{
struct v4l2_control *ctrl = arg;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
if (ctrl->value > 255)
dec->brightness = 255;
else if (ctrl->value < 0)
dec->brightness = 0;
else
dec->brightness = ctrl->value;
write_reg(client, 0x12, dec->brightness, dec->channel);
break;
case V4L2_CID_CONTRAST:
if (ctrl->value > 255)
dec->contrast = 255;
else if (ctrl->value < 0)
dec->contrast = 0;
else
dec->contrast = ctrl->value;
write_reg(client, 0x11, dec->contrast, dec->channel);
break;
case V4L2_CID_SATURATION:
if (ctrl->value > 255)
dec->saturation = 255;
else if (ctrl->value < 0)
dec->saturation = 0;
else
dec->saturation = ctrl->value;
write_reg(client, 0x10, dec->saturation, dec->channel);
break;
case V4L2_CID_HUE:
if (ctrl->value > 255)
dec->hue = 255;
else if (ctrl->value < 0)
dec->hue = 0;
else
dec->hue = ctrl->value;
write_reg(client, 0x0f, dec->hue, dec->channel);
break;
}
break;
}
case VIDIOC_G_CTRL:
{
struct v4l2_control *ctrl = arg;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ctrl->value = dec->brightness;
break;
case V4L2_CID_CONTRAST:
ctrl->value = dec->contrast;
break;
case V4L2_CID_SATURATION:
ctrl->value = dec->saturation;
break;
case V4L2_CID_HUE:
ctrl->value = dec->hue;
break;
}
break;
}
default:
break;
}
return 0;
}
static int wis_tw2804_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct wis_tw2804 *dec;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
dec = kmalloc(sizeof(struct wis_tw2804), GFP_KERNEL);
if (dec == NULL)
return -ENOMEM;
dec->channel = -1;
dec->norm = V4L2_STD_NTSC;
dec->brightness = 128;
dec->contrast = 128;
dec->saturation = 128;
dec->hue = 128;
i2c_set_clientdata(client, dec);
dev_dbg(&client->dev, "creating TW2804 at address %d on %s\n",
client->addr, adapter->name);
return 0;
}
static int wis_tw2804_remove(struct i2c_client *client)
{
struct wis_tw2804 *dec = i2c_get_clientdata(client);
kfree(dec);
return 0;
}
