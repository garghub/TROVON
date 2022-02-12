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
static int wis_tw9903_command(struct i2c_client *client,
unsigned int cmd, void *arg)
{
struct wis_tw9903 *dec = i2c_get_clientdata(client);
switch (cmd) {
case VIDIOC_S_INPUT:
{
int *input = arg;
i2c_smbus_write_byte_data(client, 0x02, 0x40 | (*input << 1));
break;
}
#if 0
case DECODER_SET_RESOLUTION:
{
struct video_decoder_resolution *res = arg;
int hscale = 256 * 720 / (res->width - (res->width > 704 ? 0 : 8));
int vscale = 256 * (dec->norm & V4L2_STD_NTSC ? 240 : 288)
/ res->height;
u8 regs[] = {
0x0d, vscale & 0xff,
0x0f, hscale & 0xff,
0x0e, ((vscale & 0xf00) >> 4) | ((hscale & 0xf00) >> 8),
0x06, 0xc0,
0, 0,
};
printk(KERN_DEBUG "vscale is %04x, hscale is %04x\n",
vscale, hscale);
break;
}
#endif
case VIDIOC_S_STD:
{
v4l2_std_id *input = arg;
u8 regs[] = {
0x05, *input & V4L2_STD_NTSC ? 0x80 : 0x00,
0x07, *input & V4L2_STD_NTSC ? 0x02 : 0x12,
0x08, *input & V4L2_STD_NTSC ? 0x14 : 0x18,
0x09, *input & V4L2_STD_NTSC ? 0xf0 : 0x20,
0, 0,
};
write_regs(client, regs);
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
ctrl->minimum = -128;
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 0x00;
ctrl->flags = 0;
break;
case V4L2_CID_CONTRAST:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Contrast", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 255;
ctrl->step = 1;
ctrl->default_value = 0x60;
ctrl->flags = 0;
break;
#if 0
case V4L2_CID_SATURATION:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Saturation", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 64;
ctrl->flags = 0;
break;
#endif
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
if (ctrl->value > 127)
dec->brightness = 127;
else if (ctrl->value < -128)
dec->brightness = -128;
else
dec->brightness = ctrl->value;
write_reg(client, 0x10, dec->brightness);
break;
case V4L2_CID_CONTRAST:
if (ctrl->value > 255)
dec->contrast = 255;
else if (ctrl->value < 0)
dec->contrast = 0;
else
dec->contrast = ctrl->value;
write_reg(client, 0x11, dec->contrast);
break;
#if 0
case V4L2_CID_SATURATION:
if (ctrl->value > 127)
dec->saturation = 127;
else if (ctrl->value < 0)
dec->saturation = 0;
else
dec->saturation = ctrl->value;
break;
#endif
case V4L2_CID_HUE:
if (ctrl->value > 127)
dec->hue = 127;
else if (ctrl->value < -128)
dec->hue = -128;
else
dec->hue = ctrl->value;
write_reg(client, 0x15, dec->hue);
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
#if 0
case V4L2_CID_SATURATION:
ctrl->value = dec->saturation;
break;
#endif
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
static int wis_tw9903_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct wis_tw9903 *dec;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
dec = kmalloc(sizeof(struct wis_tw9903), GFP_KERNEL);
if (dec == NULL)
return -ENOMEM;
dec->norm = V4L2_STD_NTSC;
dec->brightness = 0;
dec->contrast = 0x60;
dec->hue = 0;
i2c_set_clientdata(client, dec);
printk(KERN_DEBUG
"wis-tw9903: initializing TW9903 at address %d on %s\n",
client->addr, adapter->name);
if (write_regs(client, initial_registers) < 0) {
printk(KERN_ERR "wis-tw9903: error initializing TW9903\n");
kfree(dec);
return -ENODEV;
}
return 0;
}
static int wis_tw9903_remove(struct i2c_client *client)
{
struct wis_tw9903 *dec = i2c_get_clientdata(client);
kfree(dec);
return 0;
}
static int __init wis_tw9903_init(void)
{
return i2c_add_driver(&wis_tw9903_driver);
}
static void __exit wis_tw9903_cleanup(void)
{
i2c_del_driver(&wis_tw9903_driver);
}
