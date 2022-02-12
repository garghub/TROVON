static int ov9740_reg_read(struct i2c_client *client, u16 reg, u8 *val)
{
int ret;
struct i2c_msg msg[] = {
{
.addr = client->addr,
.flags = 0,
.len = 2,
.buf = (u8 *)&reg,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 1,
.buf = val,
},
};
reg = swab16(reg);
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0) {
dev_err(&client->dev, "Failed reading register 0x%04x!\n", reg);
return ret;
}
return 0;
}
static int ov9740_reg_write(struct i2c_client *client, u16 reg, u8 val)
{
struct i2c_msg msg;
struct {
u16 reg;
u8 val;
} __packed buf;
int ret;
reg = swab16(reg);
buf.reg = reg;
buf.val = val;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 3;
msg.buf = (u8 *)&buf;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
dev_err(&client->dev, "Failed writing register 0x%04x!\n", reg);
return ret;
}
return 0;
}
static int ov9740_reg_rmw(struct i2c_client *client, u16 reg, u8 set, u8 unset)
{
u8 val;
int ret;
ret = ov9740_reg_read(client, reg, &val);
if (ret < 0) {
dev_err(&client->dev,
"[Read]-Modify-Write of register 0x%04x failed!\n",
reg);
return ret;
}
val |= set;
val &= ~unset;
ret = ov9740_reg_write(client, reg, val);
if (ret < 0) {
dev_err(&client->dev,
"Read-Modify-[Write] of register 0x%04x failed!\n",
reg);
return ret;
}
return 0;
}
static int ov9740_reg_write_array(struct i2c_client *client,
const struct ov9740_reg *regarray,
int regarraylen)
{
int i;
int ret;
for (i = 0; i < regarraylen; i++) {
ret = ov9740_reg_write(client,
regarray[i].reg, regarray[i].val);
if (ret < 0)
return ret;
}
return 0;
}
static int ov9740_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov9740_priv *priv = to_ov9740(sd);
int ret;
if (priv->flag_vflip)
ret = ov9740_reg_rmw(client, OV9740_IMAGE_ORT, 0x2, 0);
else
ret = ov9740_reg_rmw(client, OV9740_IMAGE_ORT, 0, 0x2);
if (ret < 0)
return ret;
if (priv->flag_hflip)
ret = ov9740_reg_rmw(client, OV9740_IMAGE_ORT, 0x1, 0);
else
ret = ov9740_reg_rmw(client, OV9740_IMAGE_ORT, 0, 0x1);
if (ret < 0)
return ret;
if (enable) {
dev_dbg(&client->dev, "Enabling Streaming\n");
ret = ov9740_reg_write(client, OV9740_MODE_SELECT, 0x01);
} else {
dev_dbg(&client->dev, "Disabling Streaming\n");
ret = ov9740_reg_write(client, OV9740_SOFTWARE_RESET, 0x01);
if (!ret)
ret = ov9740_reg_write(client, OV9740_MODE_SELECT,
0x00);
}
priv->current_enable = enable;
return ret;
}
static int ov9740_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
return 0;
}
static unsigned long ov9740_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned long flags = SOCAM_PCLK_SAMPLE_RISING | SOCAM_MASTER |
SOCAM_VSYNC_ACTIVE_HIGH | SOCAM_HSYNC_ACTIVE_HIGH |
SOCAM_DATA_ACTIVE_HIGH | SOCAM_DATAWIDTH_8;
return soc_camera_apply_sensor_flags(icl, flags);
}
static void ov9740_res_roundup(u32 *width, u32 *height)
{
*width = ALIGN(*width, 4);
if (*width > OV9740_MAX_WIDTH)
*width = OV9740_MAX_WIDTH;
if (*height > OV9740_MAX_HEIGHT)
*height = OV9740_MAX_HEIGHT;
}
static int ov9740_set_res(struct i2c_client *client, u32 width, u32 height)
{
u32 x_start;
u32 y_start;
u32 x_end;
u32 y_end;
bool scaling = 0;
u32 scale_input_x;
u32 scale_input_y;
int ret;
if ((width != OV9740_MAX_WIDTH) || (height != OV9740_MAX_HEIGHT))
scaling = 1;
if ((OV9740_MAX_WIDTH * height) > (OV9740_MAX_HEIGHT * width)) {
scale_input_x = (OV9740_MAX_HEIGHT * width) / height;
scale_input_y = OV9740_MAX_HEIGHT;
} else {
scale_input_x = OV9740_MAX_WIDTH;
scale_input_y = (OV9740_MAX_WIDTH * height) / width;
}
x_start = (OV9740_MAX_WIDTH - scale_input_x) / 2;
y_start = (OV9740_MAX_HEIGHT - scale_input_y) / 2;
x_end = x_start + scale_input_x - 1;
y_end = y_start + scale_input_y - 1;
ret = ov9740_reg_write(client, OV9740_X_ADDR_START_HI, x_start >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_X_ADDR_START_LO, x_start & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_ADDR_START_HI, y_start >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_ADDR_START_LO, y_start & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_X_ADDR_END_HI, x_end >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_X_ADDR_END_LO, x_end & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_ADDR_END_HI, y_end >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_ADDR_END_LO, y_end & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_X_OUTPUT_SIZE_HI, width >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_X_OUTPUT_SIZE_LO, width & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_OUTPUT_SIZE_HI, height >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_Y_OUTPUT_SIZE_LO, height & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL1E, scale_input_x >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL1F, scale_input_x & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL20, scale_input_y >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL21, scale_input_y & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_VFIFO_READ_START_HI,
(scale_input_x - width) >> 8);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_VFIFO_READ_START_LO,
(scale_input_x - width) & 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL00, 0xff);
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL01, 0xef |
(scaling << 4));
if (ret)
goto done;
ret = ov9740_reg_write(client, OV9740_ISP_CTRL03, 0xff);
done:
return ret;
}
static int ov9740_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov9740_priv *priv = to_ov9740(sd);
enum v4l2_colorspace cspace;
enum v4l2_mbus_pixelcode code = mf->code;
int ret;
ov9740_res_roundup(&mf->width, &mf->height);
switch (code) {
case V4L2_MBUS_FMT_YUYV8_2X8:
cspace = V4L2_COLORSPACE_SRGB;
break;
default:
return -EINVAL;
}
ret = ov9740_reg_write_array(client, ov9740_defaults,
ARRAY_SIZE(ov9740_defaults));
if (ret < 0)
return ret;
ret = ov9740_set_res(client, mf->width, mf->height);
if (ret < 0)
return ret;
mf->code = code;
mf->colorspace = cspace;
memcpy(&priv->current_mf, mf, sizeof(struct v4l2_mbus_framefmt));
return ret;
}
static int ov9740_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
ov9740_res_roundup(&mf->width, &mf->height);
mf->field = V4L2_FIELD_NONE;
mf->code = V4L2_MBUS_FMT_YUYV8_2X8;
mf->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int ov9740_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(ov9740_codes))
return -EINVAL;
*code = ov9740_codes[index];
return 0;
}
static int ov9740_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = OV9740_MAX_WIDTH;
a->bounds.height = OV9740_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ov9740_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
a->c.left = 0;
a->c.top = 0;
a->c.width = OV9740_MAX_WIDTH;
a->c.height = OV9740_MAX_HEIGHT;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int ov9740_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct ov9740_priv *priv = to_ov9740(sd);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
ctrl->value = priv->flag_vflip;
break;
case V4L2_CID_HFLIP:
ctrl->value = priv->flag_hflip;
break;
default:
return -EINVAL;
}
return 0;
}
static int ov9740_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct ov9740_priv *priv = to_ov9740(sd);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
priv->flag_vflip = ctrl->value;
break;
case V4L2_CID_HFLIP:
priv->flag_hflip = ctrl->value;
break;
default:
return -EINVAL;
}
return 0;
}
static int ov9740_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct ov9740_priv *priv = to_ov9740(sd);
id->ident = priv->ident;
id->revision = priv->revision;
return 0;
}
static int ov9740_s_power(struct v4l2_subdev *sd, int on)
{
struct ov9740_priv *priv = to_ov9740(sd);
if (!priv->current_enable)
return 0;
if (on) {
ov9740_s_fmt(sd, &priv->current_mf);
ov9740_s_stream(sd, priv->current_enable);
} else {
ov9740_s_stream(sd, 0);
priv->current_enable = true;
}
return 0;
}
static int ov9740_get_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
u8 val;
if (reg->reg & ~0xffff)
return -EINVAL;
reg->size = 2;
ret = ov9740_reg_read(client, reg->reg, &val);
if (ret)
return ret;
reg->val = (__u64)val;
return ret;
}
static int ov9740_set_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg & ~0xffff || reg->val & ~0xff)
return -EINVAL;
return ov9740_reg_write(client, reg->reg, reg->val);
}
static int ov9740_video_probe(struct soc_camera_device *icd,
struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov9740_priv *priv = to_ov9740(sd);
u8 modelhi, modello;
int ret;
BUG_ON(!icd->parent ||
to_soc_camera_host(icd->parent)->nr != icd->iface);
ret = ov9740_reg_read(client, OV9740_MODEL_ID_HI, &modelhi);
if (ret < 0)
goto err;
ret = ov9740_reg_read(client, OV9740_MODEL_ID_LO, &modello);
if (ret < 0)
goto err;
priv->model = (modelhi << 8) | modello;
ret = ov9740_reg_read(client, OV9740_REVISION_NUMBER, &priv->revision);
if (ret < 0)
goto err;
ret = ov9740_reg_read(client, OV9740_MANUFACTURER_ID, &priv->manid);
if (ret < 0)
goto err;
ret = ov9740_reg_read(client, OV9740_SMIA_VERSION, &priv->smiaver);
if (ret < 0)
goto err;
if (priv->model != 0x9740) {
ret = -ENODEV;
goto err;
}
priv->ident = V4L2_IDENT_OV9740;
dev_info(&client->dev, "ov9740 Model ID 0x%04x, Revision 0x%02x, "
"Manufacturer 0x%02x, SMIA Version 0x%02x\n",
priv->model, priv->revision, priv->manid, priv->smiaver);
err:
return ret;
}
static int ov9740_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov9740_priv *priv;
struct soc_camera_device *icd = client->dev.platform_data;
struct soc_camera_link *icl;
int ret;
if (!icd) {
dev_err(&client->dev, "Missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&client->dev, "Missing platform_data for driver\n");
return -EINVAL;
}
priv = kzalloc(sizeof(struct ov9740_priv), GFP_KERNEL);
if (!priv) {
dev_err(&client->dev, "Failed to allocate private data!\n");
return -ENOMEM;
}
v4l2_i2c_subdev_init(&priv->subdev, client, &ov9740_subdev_ops);
icd->ops = &ov9740_ops;
ret = ov9740_video_probe(icd, client);
if (ret < 0) {
icd->ops = NULL;
kfree(priv);
}
return ret;
}
static int ov9740_remove(struct i2c_client *client)
{
struct ov9740_priv *priv = i2c_get_clientdata(client);
kfree(priv);
return 0;
}
static int __init ov9740_module_init(void)
{
return i2c_add_driver(&ov9740_i2c_driver);
}
static void __exit ov9740_module_exit(void)
{
i2c_del_driver(&ov9740_i2c_driver);
}
