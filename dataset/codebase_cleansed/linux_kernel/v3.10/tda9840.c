static void tda9840_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (i2c_smbus_write_byte_data(client, reg, val))
v4l2_dbg(1, debug, sd, "error writing %02x to %02x\n",
val, reg);
}
static int tda9840_status(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 byte;
if (1 != i2c_master_recv(client, &byte, 1)) {
v4l2_dbg(1, debug, sd,
"i2c_master_recv() failed\n");
return -EIO;
}
if (byte & 0x80) {
v4l2_dbg(1, debug, sd,
"TDA9840_DETECT: register contents invalid\n");
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "TDA9840_DETECT: byte: 0x%02x\n", byte);
return byte & 0x60;
}
static int tda9840_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *t)
{
int stat = tda9840_status(sd);
int byte;
if (t->index)
return -EINVAL;
stat = stat < 0 ? 0 : stat;
if (stat == 0 || stat == 0x60)
byte = TDA9840_SET_MONO;
else if (stat == 0x40)
byte = (t->audmode == V4L2_TUNER_MODE_MONO) ?
TDA9840_SET_MONO : TDA9840_SET_STEREO;
else {
switch (t->audmode) {
case V4L2_TUNER_MODE_LANG1_LANG2:
byte = TDA9840_SET_BOTH;
break;
case V4L2_TUNER_MODE_LANG2:
byte = TDA9840_SET_LANG2;
break;
default:
byte = TDA9840_SET_LANG1;
break;
}
}
v4l2_dbg(1, debug, sd, "TDA9840_SWITCH: 0x%02x\n", byte);
tda9840_write(sd, SWITCH, byte);
return 0;
}
static int tda9840_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *t)
{
int stat = tda9840_status(sd);
if (stat < 0)
return stat;
t->rxsubchans = V4L2_TUNER_SUB_MONO;
switch (stat & 0x60) {
case 0x00:
t->rxsubchans = V4L2_TUNER_SUB_MONO;
break;
case 0x20:
t->rxsubchans = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
break;
case 0x40:
t->rxsubchans = V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_MONO;
break;
default:
t->rxsubchans = V4L2_TUNER_MODE_MONO;
break;
}
return 0;
}
static int tda9840_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_TDA9840, 0);
}
static int tda9840_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &tda9840_ops);
tda9840_write(sd, LEVEL_ADJUST, 0);
tda9840_write(sd, STEREO_ADJUST, 0);
tda9840_write(sd, SWITCH, TDA9840_SET_STEREO);
return 0;
}
static int tda9840_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
