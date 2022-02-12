static struct tw9910_priv *to_tw9910(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct tw9910_priv,
subdev);
}
static int tw9910_mask_set(struct i2c_client *client, u8 command,
u8 mask, u8 set)
{
s32 val = i2c_smbus_read_byte_data(client, command);
if (val < 0)
return val;
val &= ~mask;
val |= set & mask;
return i2c_smbus_write_byte_data(client, command, val);
}
static int tw9910_set_scale(struct i2c_client *client,
const struct tw9910_scale_ctrl *scale)
{
int ret;
ret = i2c_smbus_write_byte_data(client, SCALE_HI,
(scale->vscale & 0x0F00) >> 4 |
(scale->hscale & 0x0F00) >> 8);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, HSCALE_LO,
scale->hscale & 0x00FF);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, VSCALE_LO,
scale->vscale & 0x00FF);
return ret;
}
static int tw9910_set_hsync(struct i2c_client *client)
{
struct tw9910_priv *priv = to_tw9910(client);
int ret;
ret = i2c_smbus_write_byte_data(client, HSBEGIN,
(HSYNC_START & 0x07F8) >> 3);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, HSEND,
(HSYNC_END & 0x07F8) >> 3);
if (ret < 0)
return ret;
if (1 == priv->revision)
ret = tw9910_mask_set(client, HSLOWCTL, 0x77,
(HSYNC_START & 0x0007) << 4 |
(HSYNC_END & 0x0007));
return ret;
}
static void tw9910_reset(struct i2c_client *client)
{
tw9910_mask_set(client, ACNTL1, SRESET, SRESET);
msleep(1);
}
static int tw9910_power(struct i2c_client *client, int enable)
{
int ret;
u8 acntl1;
u8 acntl2;
if (enable) {
acntl1 = 0;
acntl2 = 0;
} else {
acntl1 = CLK_PDN | Y_PDN | C_PDN;
acntl2 = PLL_PDN;
}
ret = tw9910_mask_set(client, ACNTL1, ACNTL1_PDN_MASK, acntl1);
if (ret < 0)
return ret;
return tw9910_mask_set(client, ACNTL2, ACNTL2_PDN_MASK, acntl2);
}
static const struct tw9910_scale_ctrl *tw9910_select_norm(v4l2_std_id norm,
u32 width, u32 height)
{
const struct tw9910_scale_ctrl *scale;
const struct tw9910_scale_ctrl *ret = NULL;
__u32 diff = 0xffffffff, tmp;
int size, i;
if (norm & V4L2_STD_NTSC) {
scale = tw9910_ntsc_scales;
size = ARRAY_SIZE(tw9910_ntsc_scales);
} else if (norm & V4L2_STD_PAL) {
scale = tw9910_pal_scales;
size = ARRAY_SIZE(tw9910_pal_scales);
} else {
return NULL;
}
for (i = 0; i < size; i++) {
tmp = abs(width - scale[i].width) +
abs(height - scale[i].height);
if (tmp < diff) {
diff = tmp;
ret = scale + i;
}
}
return ret;
}
static int tw9910_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
u8 val;
int ret;
if (!enable) {
switch (priv->revision) {
case 0:
val = OEN_TRI_SEL_ALL_OFF_r0;
break;
case 1:
val = OEN_TRI_SEL_ALL_OFF_r1;
break;
default:
dev_err(&client->dev, "un-supported revision\n");
return -EINVAL;
}
} else {
val = OEN_TRI_SEL_ALL_ON;
if (!priv->scale) {
dev_err(&client->dev, "norm select error\n");
return -EPERM;
}
dev_dbg(&client->dev, "%s %dx%d\n",
priv->scale->name,
priv->scale->width,
priv->scale->height);
}
ret = tw9910_mask_set(client, OPFORM, OEN_TRI_SEL_MASK, val);
if (ret < 0)
return ret;
return tw9910_power(client, enable);
}
static int tw9910_g_std(struct v4l2_subdev *sd, v4l2_std_id *norm)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
*norm = priv->norm;
return 0;
}
static int tw9910_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
if (!(norm & (V4L2_STD_NTSC | V4L2_STD_PAL)))
return -EINVAL;
priv->norm = norm;
return 0;
}
static int tw9910_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
id->ident = V4L2_IDENT_TW9910;
id->revision = priv->revision;
return 0;
}
static int tw9910_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (reg->reg > 0xff)
return -EINVAL;
ret = i2c_smbus_read_byte_data(client, reg->reg);
if (ret < 0)
return ret;
reg->val = (__u64)ret;
return 0;
}
static int tw9910_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return i2c_smbus_write_byte_data(client, reg->reg, reg->val);
}
static int tw9910_set_frame(struct v4l2_subdev *sd, u32 *width, u32 *height)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
int ret = -EINVAL;
u8 val;
priv->scale = tw9910_select_norm(priv->norm, *width, *height);
if (!priv->scale)
goto tw9910_set_fmt_error;
tw9910_reset(client);
val = 0x00;
if (SOCAM_DATAWIDTH_16 == priv->info->buswidth)
val = LEN;
ret = tw9910_mask_set(client, OPFORM, LEN, val);
if (ret < 0)
goto tw9910_set_fmt_error;
switch (priv->info->mpout) {
case TW9910_MPO_VLOSS:
val = RTSEL_VLOSS; break;
case TW9910_MPO_HLOCK:
val = RTSEL_HLOCK; break;
case TW9910_MPO_SLOCK:
val = RTSEL_SLOCK; break;
case TW9910_MPO_VLOCK:
val = RTSEL_VLOCK; break;
case TW9910_MPO_MONO:
val = RTSEL_MONO; break;
case TW9910_MPO_DET50:
val = RTSEL_DET50; break;
case TW9910_MPO_FIELD:
val = RTSEL_FIELD; break;
case TW9910_MPO_RTCO:
val = RTSEL_RTCO; break;
default:
val = 0;
}
ret = tw9910_mask_set(client, VBICNTL, RTSEL_MASK, val);
if (ret < 0)
goto tw9910_set_fmt_error;
ret = tw9910_set_scale(client, priv->scale);
if (ret < 0)
goto tw9910_set_fmt_error;
ret = tw9910_set_hsync(client);
if (ret < 0)
goto tw9910_set_fmt_error;
*width = priv->scale->width;
*height = priv->scale->height;
return ret;
tw9910_set_fmt_error:
tw9910_reset(client);
priv->scale = NULL;
return ret;
}
static int tw9910_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
a->c.left = 0;
a->c.top = 0;
if (priv->norm & V4L2_STD_NTSC) {
a->c.width = 640;
a->c.height = 480;
} else {
a->c.width = 768;
a->c.height = 576;
}
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int tw9910_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
a->bounds.left = 0;
a->bounds.top = 0;
if (priv->norm & V4L2_STD_NTSC) {
a->bounds.width = 640;
a->bounds.height = 480;
} else {
a->bounds.width = 768;
a->bounds.height = 576;
}
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int tw9910_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
if (!priv->scale) {
int ret;
u32 width = 640, height = 480;
ret = tw9910_set_frame(sd, &width, &height);
if (ret < 0)
return ret;
}
mf->width = priv->scale->width;
mf->height = priv->scale->height;
mf->code = V4L2_MBUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_JPEG;
mf->field = V4L2_FIELD_INTERLACED_BT;
return 0;
}
static int tw9910_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
u32 width = mf->width, height = mf->height;
int ret;
WARN_ON(mf->field != V4L2_FIELD_ANY &&
mf->field != V4L2_FIELD_INTERLACED_BT);
if (mf->code != V4L2_MBUS_FMT_UYVY8_2X8)
return -EINVAL;
mf->colorspace = V4L2_COLORSPACE_JPEG;
ret = tw9910_set_frame(sd, &width, &height);
if (!ret) {
mf->width = width;
mf->height = height;
}
return ret;
}
static int tw9910_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
const struct tw9910_scale_ctrl *scale;
if (V4L2_FIELD_ANY == mf->field) {
mf->field = V4L2_FIELD_INTERLACED_BT;
} else if (V4L2_FIELD_INTERLACED_BT != mf->field) {
dev_err(&client->dev, "Field type %d invalid.\n", mf->field);
return -EINVAL;
}
mf->code = V4L2_MBUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_JPEG;
scale = tw9910_select_norm(priv->norm, mf->width, mf->height);
if (!scale)
return -EINVAL;
mf->width = scale->width;
mf->height = scale->height;
return 0;
}
static int tw9910_video_probe(struct i2c_client *client)
{
struct tw9910_priv *priv = to_tw9910(client);
s32 id;
if (SOCAM_DATAWIDTH_16 != priv->info->buswidth &&
SOCAM_DATAWIDTH_8 != priv->info->buswidth) {
dev_err(&client->dev, "bus width error\n");
return -ENODEV;
}
id = i2c_smbus_read_byte_data(client, ID);
priv->revision = GET_REV(id);
id = GET_ID(id);
if (0x0B != id ||
0x01 < priv->revision) {
dev_err(&client->dev,
"Product ID error %x:%x\n",
id, priv->revision);
return -ENODEV;
}
dev_info(&client->dev,
"tw9910 Product ID %0x:%0x\n", id, priv->revision);
priv->norm = V4L2_STD_NTSC;
return 0;
}
static int tw9910_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index)
return -EINVAL;
*code = V4L2_MBUS_FMT_UYVY8_2X8;
return 0;
}
static int tw9910_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_MASTER |
V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_LOW |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_LOW |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(icl, cfg);
return 0;
}
static int tw9910_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
u8 val = VSSL_VVALID | HSSL_DVALID;
unsigned long flags = soc_camera_apply_board_flags(icl, cfg);
if (flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
val |= HSP_HI;
if (flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
val |= VSP_HI;
return i2c_smbus_write_byte_data(client, OUTCTR1, val);
}
static int tw9910_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct tw9910_priv *priv;
struct tw9910_video_info *info;
struct i2c_adapter *adapter =
to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
int ret;
if (!icl || !icl->priv) {
dev_err(&client->dev, "TW9910: missing platform data!\n");
return -EINVAL;
}
info = icl->priv;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev,
"I2C-Adapter doesn't support "
"I2C_FUNC_SMBUS_BYTE_DATA\n");
return -EIO;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->info = info;
v4l2_i2c_subdev_init(&priv->subdev, client, &tw9910_subdev_ops);
ret = tw9910_video_probe(client);
if (ret)
kfree(priv);
return ret;
}
static int tw9910_remove(struct i2c_client *client)
{
struct tw9910_priv *priv = to_tw9910(client);
kfree(priv);
return 0;
}
