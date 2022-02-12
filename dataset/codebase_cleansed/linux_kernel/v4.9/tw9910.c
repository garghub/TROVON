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
const unsigned hact = 720;
const unsigned hdelay = 15;
unsigned vact;
unsigned vdelay;
int ret;
if (!(norm & (V4L2_STD_NTSC | V4L2_STD_PAL)))
return -EINVAL;
priv->norm = norm;
if (norm & V4L2_STD_525_60) {
vact = 240;
vdelay = 18;
ret = tw9910_mask_set(client, VVBI, 0x10, 0x10);
} else {
vact = 288;
vdelay = 24;
ret = tw9910_mask_set(client, VVBI, 0x10, 0x00);
}
if (!ret)
ret = i2c_smbus_write_byte_data(client, CROP_HI,
((vdelay >> 2) & 0xc0) |
((vact >> 4) & 0x30) |
((hdelay >> 6) & 0x0c) |
((hact >> 8) & 0x03));
if (!ret)
ret = i2c_smbus_write_byte_data(client, VDELAY_LO,
vdelay & 0xff);
if (!ret)
ret = i2c_smbus_write_byte_data(client, VACTIVE_LO,
vact & 0xff);
return ret;
}
static int tw9910_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (reg->reg > 0xff)
return -EINVAL;
reg->size = 1;
ret = i2c_smbus_read_byte_data(client, reg->reg);
if (ret < 0)
return ret;
reg->val = (__u64)ret;
return 0;
}
static int tw9910_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return i2c_smbus_write_byte_data(client, reg->reg, reg->val);
}
static int tw9910_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct tw9910_priv *priv = to_tw9910(client);
return soc_camera_set_power(&client->dev, ssdd, priv->clk, on);
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
static int tw9910_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
if (sel->target > V4L2_SEL_TGT_CROP_BOUNDS)
return -EINVAL;
sel->r.left = 0;
sel->r.top = 0;
if (priv->norm & V4L2_STD_NTSC) {
sel->r.width = 640;
sel->r.height = 480;
} else {
sel->r.width = 768;
sel->r.height = 576;
}
return 0;
}
static int tw9910_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
if (format->pad)
return -EINVAL;
if (!priv->scale) {
priv->scale = tw9910_select_norm(priv->norm, 640, 480);
if (!priv->scale)
return -EINVAL;
}
mf->width = priv->scale->width;
mf->height = priv->scale->height;
mf->code = MEDIA_BUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
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
if (mf->code != MEDIA_BUS_FMT_UYVY8_2X8)
return -EINVAL;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
ret = tw9910_set_frame(sd, &width, &height);
if (!ret) {
mf->width = width;
mf->height = height;
}
return ret;
}
static int tw9910_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct tw9910_priv *priv = to_tw9910(client);
const struct tw9910_scale_ctrl *scale;
if (format->pad)
return -EINVAL;
if (V4L2_FIELD_ANY == mf->field) {
mf->field = V4L2_FIELD_INTERLACED_BT;
} else if (V4L2_FIELD_INTERLACED_BT != mf->field) {
dev_err(&client->dev, "Field type %d invalid.\n", mf->field);
return -EINVAL;
}
mf->code = MEDIA_BUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
scale = tw9910_select_norm(priv->norm, mf->width, mf->height);
if (!scale)
return -EINVAL;
mf->width = scale->width;
mf->height = scale->height;
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return tw9910_s_fmt(sd, mf);
cfg->try_fmt = *mf;
return 0;
}
static int tw9910_video_probe(struct i2c_client *client)
{
struct tw9910_priv *priv = to_tw9910(client);
s32 id;
int ret;
if (SOCAM_DATAWIDTH_16 != priv->info->buswidth &&
SOCAM_DATAWIDTH_8 != priv->info->buswidth) {
dev_err(&client->dev, "bus width error\n");
return -ENODEV;
}
ret = tw9910_s_power(&priv->subdev, 1);
if (ret < 0)
return ret;
id = i2c_smbus_read_byte_data(client, ID);
priv->revision = GET_REV(id);
id = GET_ID(id);
if (0x0B != id ||
0x01 < priv->revision) {
dev_err(&client->dev,
"Product ID error %x:%x\n",
id, priv->revision);
ret = -ENODEV;
goto done;
}
dev_info(&client->dev,
"tw9910 Product ID %0x:%0x\n", id, priv->revision);
priv->norm = V4L2_STD_NTSC;
priv->scale = &tw9910_ntsc_scales[0];
done:
tw9910_s_power(&priv->subdev, 0);
return ret;
}
static int tw9910_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index)
return -EINVAL;
code->code = MEDIA_BUS_FMT_UYVY8_2X8;
return 0;
}
static int tw9910_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_MASTER |
V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_LOW |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_LOW |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(ssdd, cfg);
return 0;
}
static int tw9910_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
u8 val = VSSL_VVALID | HSSL_DVALID;
unsigned long flags = soc_camera_apply_board_flags(ssdd, cfg);
if (flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
val |= HSP_HI;
if (flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
val |= VSP_HI;
return i2c_smbus_write_byte_data(client, OUTCTR1, val);
}
static int tw9910_g_tvnorms(struct v4l2_subdev *sd, v4l2_std_id *norm)
{
*norm = V4L2_STD_NTSC | V4L2_STD_PAL;
return 0;
}
static int tw9910_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct tw9910_priv *priv;
struct tw9910_video_info *info;
struct i2c_adapter *adapter =
to_i2c_adapter(client->dev.parent);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
int ret;
if (!ssdd || !ssdd->drv_priv) {
dev_err(&client->dev, "TW9910: missing platform data!\n");
return -EINVAL;
}
info = ssdd->drv_priv;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev,
"I2C-Adapter doesn't support "
"I2C_FUNC_SMBUS_BYTE_DATA\n");
return -EIO;
}
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->info = info;
v4l2_i2c_subdev_init(&priv->subdev, client, &tw9910_subdev_ops);
priv->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
ret = tw9910_video_probe(client);
if (ret < 0)
v4l2_clk_put(priv->clk);
return ret;
}
static int tw9910_remove(struct i2c_client *client)
{
struct tw9910_priv *priv = to_tw9910(client);
v4l2_clk_put(priv->clk);
return 0;
}
