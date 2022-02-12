static struct imx074 *to_imx074(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct imx074, subdev);
}
static const struct imx074_datafmt *imx074_find_datafmt(u32 code)
{
int i;
for (i = 0; i < ARRAY_SIZE(imx074_colour_fmts); i++)
if (imx074_colour_fmts[i].code == code)
return imx074_colour_fmts + i;
return NULL;
}
static int reg_write(struct i2c_client *client, const u16 addr, const u8 data)
{
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg;
unsigned char tx[3];
int ret;
msg.addr = client->addr;
msg.buf = tx;
msg.len = 3;
msg.flags = 0;
tx[0] = addr >> 8;
tx[1] = addr & 0xff;
tx[2] = data;
ret = i2c_transfer(adap, &msg, 1);
mdelay(2);
return ret == 1 ? 0 : -EIO;
}
static int reg_read(struct i2c_client *client, const u16 addr)
{
u8 buf[2] = {addr >> 8, addr & 0xff};
int ret;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 2,
.buf = buf,
}, {
.addr = client->addr,
.flags = I2C_M_RD,
.len = 2,
.buf = buf,
},
};
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0) {
dev_warn(&client->dev, "Reading register %x from %x failed\n",
addr, client->addr);
return ret;
}
return buf[0] & 0xff;
}
static int imx074_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
const struct imx074_datafmt *fmt = imx074_find_datafmt(mf->code);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct imx074 *priv = to_imx074(client);
if (format->pad)
return -EINVAL;
dev_dbg(sd->v4l2_dev->dev, "%s(%u)\n", __func__, mf->code);
if (!fmt) {
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
mf->code = imx074_colour_fmts[0].code;
mf->colorspace = imx074_colour_fmts[0].colorspace;
}
mf->width = IMX074_WIDTH;
mf->height = IMX074_HEIGHT;
mf->field = V4L2_FIELD_NONE;
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
priv->fmt = fmt;
else
cfg->try_fmt = *mf;
return 0;
}
static int imx074_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct imx074 *priv = to_imx074(client);
const struct imx074_datafmt *fmt = priv->fmt;
if (format->pad)
return -EINVAL;
mf->code = fmt->code;
mf->colorspace = fmt->colorspace;
mf->width = IMX074_WIDTH;
mf->height = IMX074_HEIGHT;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int imx074_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = IMX074_WIDTH;
sel->r.height = IMX074_HEIGHT;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_CROP:
return 0;
default:
return -EINVAL;
}
}
static int imx074_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad ||
(unsigned int)code->index >= ARRAY_SIZE(imx074_colour_fmts))
return -EINVAL;
code->code = imx074_colour_fmts[code->index].code;
return 0;
}
static int imx074_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return reg_write(client, MODE_SELECT, !!enable);
}
static int imx074_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct imx074 *priv = to_imx074(client);
return soc_camera_set_power(&client->dev, ssdd, priv->clk, on);
}
static int imx074_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->type = V4L2_MBUS_CSI2;
cfg->flags = V4L2_MBUS_CSI2_2_LANE |
V4L2_MBUS_CSI2_CHANNEL_0 |
V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
return 0;
}
static int imx074_video_probe(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
int ret;
u16 id;
ret = imx074_s_power(subdev, 1);
if (ret < 0)
return ret;
ret = reg_read(client, 0);
if (ret < 0)
goto done;
id = ret << 8;
ret = reg_read(client, 1);
if (ret < 0)
goto done;
id |= ret;
dev_info(&client->dev, "Chip ID 0x%04x detected\n", id);
if (id != 0x74) {
ret = -ENODEV;
goto done;
}
reg_write(client, PLL_MULTIPLIER, 0x2D);
reg_write(client, PRE_PLL_CLK_DIV, 0x02);
reg_write(client, PLSTATIM, 0x4B);
reg_write(client, 0x3024, 0x00);
reg_write(client, IMAGE_ORIENTATION, 0x00);
reg_write(client, 0x0112, 0x08);
reg_write(client, 0x0113, 0x08);
reg_write(client, VNDMY_ABLMGSHLMT, 0x80);
reg_write(client, Y_OPBADDR_START_DI, 0x08);
reg_write(client, 0x3015, 0x37);
reg_write(client, 0x301C, 0x01);
reg_write(client, 0x302C, 0x05);
reg_write(client, 0x3031, 0x26);
reg_write(client, 0x3041, 0x60);
reg_write(client, 0x3051, 0x24);
reg_write(client, 0x3053, 0x34);
reg_write(client, 0x3057, 0xC0);
reg_write(client, 0x305C, 0x09);
reg_write(client, 0x305D, 0x07);
reg_write(client, 0x3060, 0x30);
reg_write(client, 0x3065, 0x00);
reg_write(client, 0x30AA, 0x08);
reg_write(client, 0x30AB, 0x1C);
reg_write(client, 0x30B0, 0x32);
reg_write(client, 0x30B2, 0x83);
reg_write(client, 0x30D3, 0x04);
reg_write(client, 0x3106, 0x78);
reg_write(client, 0x310C, 0x82);
reg_write(client, 0x3304, 0x05);
reg_write(client, 0x3305, 0x04);
reg_write(client, 0x3306, 0x11);
reg_write(client, 0x3307, 0x02);
reg_write(client, 0x3308, 0x0C);
reg_write(client, 0x3309, 0x06);
reg_write(client, 0x330A, 0x08);
reg_write(client, 0x330B, 0x04);
reg_write(client, 0x330C, 0x08);
reg_write(client, 0x330D, 0x06);
reg_write(client, 0x330E, 0x01);
reg_write(client, 0x3381, 0x00);
reg_write(client, FRAME_LENGTH_LINES_HI, 0x06);
reg_write(client, FRAME_LENGTH_LINES_LO, 0x48);
reg_write(client, YADDR_START, 0x00);
reg_write(client, YADDR_END, 0x2F);
reg_write(client, X_OUTPUT_SIZE_MSB, 0x08);
reg_write(client, X_OUTPUT_SIZE_LSB, 0x38);
reg_write(client, Y_OUTPUT_SIZE_MSB, 0x06);
reg_write(client, Y_OUTPUT_SIZE_LSB, 0x18);
reg_write(client, X_EVEN_INC, 0x01);
reg_write(client, X_ODD_INC, 0x03);
reg_write(client, Y_EVEN_INC, 0x01);
reg_write(client, Y_ODD_INC, 0x03);
reg_write(client, HMODEADD, 0x00);
reg_write(client, VMODEADD, 0x16);
reg_write(client, VAPPLINE_START, 0x24);
reg_write(client, VAPPLINE_END, 0x53);
reg_write(client, SHUTTER, 0x00);
reg_write(client, HADDAVE, 0x80);
reg_write(client, LANESEL, 0x00);
reg_write(client, GROUPED_PARAMETER_HOLD, 0x00);
ret = 0;
done:
imx074_s_power(subdev, 0);
return ret;
}
static int imx074_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct imx074 *priv;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
int ret;
if (!ssdd) {
dev_err(&client->dev, "IMX074: missing platform data!\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_BYTE\n");
return -EIO;
}
priv = devm_kzalloc(&client->dev, sizeof(struct imx074), GFP_KERNEL);
if (!priv)
return -ENOMEM;
v4l2_i2c_subdev_init(&priv->subdev, client, &imx074_subdev_ops);
priv->fmt = &imx074_colour_fmts[0];
priv->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(priv->clk)) {
dev_info(&client->dev, "Error %ld getting clock\n", PTR_ERR(priv->clk));
return -EPROBE_DEFER;
}
ret = soc_camera_power_init(&client->dev, ssdd);
if (ret < 0)
goto epwrinit;
ret = imx074_video_probe(client);
if (ret < 0)
goto eprobe;
ret = v4l2_async_register_subdev(&priv->subdev);
if (!ret)
return 0;
epwrinit:
eprobe:
v4l2_clk_put(priv->clk);
return ret;
}
static int imx074_remove(struct i2c_client *client)
{
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct imx074 *priv = to_imx074(client);
v4l2_async_unregister_subdev(&priv->subdev);
v4l2_clk_put(priv->clk);
if (ssdd->free_bus)
ssdd->free_bus(ssdd);
return 0;
}
