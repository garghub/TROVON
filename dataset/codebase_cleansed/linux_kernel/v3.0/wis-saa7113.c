static int write_reg(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static int write_regs(struct i2c_client *client, u8 *regs)
{
int i;
for (i = 0; regs[i] != 0x00; i += 2)
if (i2c_smbus_write_byte_data(client, regs[i], regs[i + 1]) < 0)
return -1;
return 0;
}
static int wis_saa7113_command(struct i2c_client *client,
unsigned int cmd, void *arg)
{
struct wis_saa7113 *dec = i2c_get_clientdata(client);
switch (cmd) {
case VIDIOC_S_INPUT:
{
int *input = arg;
i2c_smbus_write_byte_data(client, 0x02, 0xC0 | *input);
i2c_smbus_write_byte_data(client, 0x09,
*input < 6 ? 0x40 : 0x80);
break;
}
case VIDIOC_S_STD:
{
v4l2_std_id *input = arg;
dec->norm = *input;
if (dec->norm & V4L2_STD_NTSC) {
write_reg(client, 0x0e, 0x01);
write_reg(client, 0x10, 0x40);
} else if (dec->norm & V4L2_STD_PAL) {
write_reg(client, 0x0e, 0x01);
write_reg(client, 0x10, 0x48);
} else if (dec->norm * V4L2_STD_SECAM) {
write_reg(client, 0x0e, 0x50);
write_reg(client, 0x10, 0x48);
}
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
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 71;
ctrl->flags = 0;
break;
case V4L2_CID_SATURATION:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Saturation", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 64;
ctrl->flags = 0;
break;
case V4L2_CID_HUE:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Hue", sizeof(ctrl->name));
ctrl->minimum = -128;
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 0;
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
write_reg(client, 0x0a, dec->brightness);
break;
case V4L2_CID_CONTRAST:
if (ctrl->value > 127)
dec->contrast = 127;
else if (ctrl->value < 0)
dec->contrast = 0;
else
dec->contrast = ctrl->value;
write_reg(client, 0x0b, dec->contrast);
break;
case V4L2_CID_SATURATION:
if (ctrl->value > 127)
dec->saturation = 127;
else if (ctrl->value < 0)
dec->saturation = 0;
else
dec->saturation = ctrl->value;
write_reg(client, 0x0c, dec->saturation);
break;
case V4L2_CID_HUE:
if (ctrl->value > 127)
dec->hue = 127;
else if (ctrl->value < -128)
dec->hue = -128;
else
dec->hue = ctrl->value;
write_reg(client, 0x0d, dec->hue);
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
static int wis_saa7113_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct wis_saa7113 *dec;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
dec = kmalloc(sizeof(struct wis_saa7113), GFP_KERNEL);
if (dec == NULL)
return -ENOMEM;
dec->norm = V4L2_STD_NTSC;
dec->brightness = 128;
dec->contrast = 71;
dec->saturation = 64;
dec->hue = 0;
i2c_set_clientdata(client, dec);
printk(KERN_DEBUG
"wis-saa7113: initializing SAA7113 at address %d on %s\n",
client->addr, adapter->name);
if (write_regs(client, initial_registers) < 0) {
printk(KERN_ERR
"wis-saa7113: error initializing SAA7113\n");
kfree(dec);
return -ENODEV;
}
return 0;
}
static int wis_saa7113_remove(struct i2c_client *client)
{
struct wis_saa7113 *dec = i2c_get_clientdata(client);
kfree(dec);
return 0;
}
static int __init wis_saa7113_init(void)
{
return i2c_add_driver(&wis_saa7113_driver);
}
static void __exit wis_saa7113_cleanup(void)
{
i2c_del_driver(&wis_saa7113_driver);
}
