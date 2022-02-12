static int reg_read(struct i2c_client *client, const u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int reg_write(struct i2c_client *client, const u8 reg,
const u8 data)
{
return i2c_smbus_write_byte_data(client, reg, data);
}
static int reg_set(struct i2c_client *client, const u8 reg,
const u8 data, u8 mask)
{
int ret = reg_read(client, reg);
if (ret < 0)
return ret;
return reg_write(client, reg, (ret & ~mask) | (data & mask));
}
static struct ak881x *to_ak881x(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct ak881x, subdev);
}
static int ak881x_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0x26)
return -EINVAL;
reg->size = 1;
reg->val = reg_read(client, reg->reg);
if (reg->val > 0xffff)
return -EIO;
return 0;
}
static int ak881x_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0x26)
return -EINVAL;
if (reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int ak881x_try_g_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ak881x *ak881x = to_ak881x(client);
v4l_bound_align_image(&mf->width, 0, 720, 2,
&mf->height, 0, ak881x->lines, 1, 0);
mf->field = V4L2_FIELD_INTERLACED;
mf->code = V4L2_MBUS_FMT_YUYV8_2X8;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int ak881x_s_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
if (mf->field != V4L2_FIELD_INTERLACED ||
mf->code != V4L2_MBUS_FMT_YUYV8_2X8)
return -EINVAL;
return ak881x_try_g_mbus_fmt(sd, mf);
}
static int ak881x_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index)
return -EINVAL;
*code = V4L2_MBUS_FMT_YUYV8_2X8;
return 0;
}
static int ak881x_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ak881x *ak881x = to_ak881x(client);
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = 720;
a->bounds.height = ak881x->lines;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ak881x_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ak881x *ak881x = to_ak881x(client);
u8 vp1;
if (std == V4L2_STD_NTSC_443) {
vp1 = 3;
ak881x->lines = 480;
} else if (std == V4L2_STD_PAL_M) {
vp1 = 5;
ak881x->lines = 480;
} else if (std == V4L2_STD_PAL_60) {
vp1 = 7;
ak881x->lines = 480;
} else if (std && !(std & ~V4L2_STD_PAL)) {
vp1 = 0xf;
ak881x->lines = 576;
} else if (std && !(std & ~V4L2_STD_NTSC)) {
vp1 = 0;
ak881x->lines = 480;
} else {
return -EINVAL;
}
reg_set(client, AK881X_VIDEO_PROCESS1, vp1, 0xf);
return 0;
}
static int ak881x_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ak881x *ak881x = to_ak881x(client);
if (enable) {
u8 dac;
if (ak881x->pdata->flags & AK881X_COMPONENT)
dac = 3;
else
dac = 4;
reg_write(client, AK881X_DAC_MODE, dac);
dev_dbg(&client->dev, "chip status 0x%x\n",
reg_read(client, AK881X_STATUS));
} else {
reg_write(client, AK881X_DAC_MODE, 0);
dev_dbg(&client->dev, "chip status 0x%x\n",
reg_read(client, AK881X_STATUS));
}
return 0;
}
static int ak881x_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct ak881x *ak881x;
u8 ifmode, data;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
ak881x = devm_kzalloc(&client->dev, sizeof(*ak881x), GFP_KERNEL);
if (!ak881x)
return -ENOMEM;
v4l2_i2c_subdev_init(&ak881x->subdev, client, &ak881x_subdev_ops);
data = reg_read(client, AK881X_DEVICE_ID);
switch (data) {
case 0x13:
case 0x14:
break;
default:
dev_err(&client->dev,
"No ak881x chip detected, register read %x\n", data);
return -ENODEV;
}
ak881x->revision = reg_read(client, AK881X_DEVICE_REVISION);
ak881x->pdata = client->dev.platform_data;
if (ak881x->pdata) {
if (ak881x->pdata->flags & AK881X_FIELD)
ifmode = 4;
else
ifmode = 0;
switch (ak881x->pdata->flags & AK881X_IF_MODE_MASK) {
case AK881X_IF_MODE_BT656:
ifmode |= 1;
break;
case AK881X_IF_MODE_MASTER:
ifmode |= 2;
break;
case AK881X_IF_MODE_SLAVE:
default:
break;
}
dev_dbg(&client->dev, "IF mode %x\n", ifmode);
reg_write(client, AK881X_INTERFACE_MODE, ifmode | (20 << 3));
}
ak881x->lines = 480;
dev_info(&client->dev, "Detected an ak881x chip ID %x, revision %x\n",
data, ak881x->revision);
return 0;
}
static int ak881x_remove(struct i2c_client *client)
{
struct ak881x *ak881x = to_ak881x(client);
v4l2_device_unregister_subdev(&ak881x->subdev);
return 0;
}
