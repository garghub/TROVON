static struct ov2640_priv *to_ov2640(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct ov2640_priv,
subdev);
}
static int ov2640_write_array(struct i2c_client *client,
const struct regval_list *vals)
{
int ret;
while ((vals->reg_num != 0xff) || (vals->value != 0xff)) {
ret = i2c_smbus_write_byte_data(client,
vals->reg_num, vals->value);
dev_vdbg(&client->dev, "array: 0x%02x, 0x%02x",
vals->reg_num, vals->value);
if (ret < 0)
return ret;
vals++;
}
return 0;
}
static int ov2640_mask_set(struct i2c_client *client,
u8 reg, u8 mask, u8 set)
{
s32 val = i2c_smbus_read_byte_data(client, reg);
if (val < 0)
return val;
val &= ~mask;
val |= set & mask;
dev_vdbg(&client->dev, "masks: 0x%02x, 0x%02x", reg, val);
return i2c_smbus_write_byte_data(client, reg, val);
}
static int ov2640_reset(struct i2c_client *client)
{
int ret;
const struct regval_list reset_seq[] = {
{BANK_SEL, BANK_SEL_SENS},
{COM7, COM7_SRST},
ENDMARKER,
};
ret = ov2640_write_array(client, reset_seq);
if (ret)
goto err;
msleep(5);
err:
dev_dbg(&client->dev, "%s: (ret %d)", __func__, ret);
return ret;
}
static int ov2640_s_stream(struct v4l2_subdev *sd, int enable)
{
return 0;
}
static int ov2640_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned long width_flag = flags & SOCAM_DATAWIDTH_MASK;
if (!is_power_of_2(width_flag))
return -EINVAL;
if (icl->set_bus_param)
return icl->set_bus_param(icl, width_flag);
if (width_flag & (SOCAM_DATAWIDTH_10 | SOCAM_DATAWIDTH_8))
return 0;
return 0;
}
static unsigned long ov2640_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned long flags = SOCAM_PCLK_SAMPLE_RISING | SOCAM_MASTER |
SOCAM_VSYNC_ACTIVE_HIGH | SOCAM_HSYNC_ACTIVE_HIGH |
SOCAM_DATA_ACTIVE_HIGH;
if (icl->query_bus_param)
flags |= icl->query_bus_param(icl) & SOCAM_DATAWIDTH_MASK;
else
flags |= SOCAM_DATAWIDTH_10;
return soc_camera_apply_sensor_flags(icl, flags);
}
static int ov2640_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2640_priv *priv = to_ov2640(client);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
ctrl->value = priv->flag_vflip;
break;
case V4L2_CID_HFLIP:
ctrl->value = priv->flag_hflip;
break;
}
return 0;
}
static int ov2640_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2640_priv *priv = to_ov2640(client);
int ret = 0;
u8 val;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
val = ctrl->value ? REG04_VFLIP_IMG : 0x00;
priv->flag_vflip = ctrl->value ? 1 : 0;
ret = ov2640_mask_set(client, REG04, REG04_VFLIP_IMG, val);
break;
case V4L2_CID_HFLIP:
val = ctrl->value ? REG04_HFLIP_IMG : 0x00;
priv->flag_hflip = ctrl->value ? 1 : 0;
ret = ov2640_mask_set(client, REG04, REG04_HFLIP_IMG, val);
break;
}
return ret;
}
static int ov2640_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2640_priv *priv = to_ov2640(client);
id->ident = priv->model;
id->revision = 0;
return 0;
}
static int ov2640_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
reg->size = 1;
if (reg->reg > 0xff)
return -EINVAL;
ret = i2c_smbus_read_byte_data(client, reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
return 0;
}
static int ov2640_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return i2c_smbus_write_byte_data(client, reg->reg, reg->val);
}
static const struct ov2640_win_size *ov2640_select_win(u32 *width, u32 *height)
{
int i, default_size = ARRAY_SIZE(ov2640_supported_win_sizes) - 1;
for (i = 0; i < ARRAY_SIZE(ov2640_supported_win_sizes); i++) {
if (ov2640_supported_win_sizes[i].width >= *width &&
ov2640_supported_win_sizes[i].height >= *height) {
*width = ov2640_supported_win_sizes[i].width;
*height = ov2640_supported_win_sizes[i].height;
return &ov2640_supported_win_sizes[i];
}
}
*width = ov2640_supported_win_sizes[default_size].width;
*height = ov2640_supported_win_sizes[default_size].height;
return &ov2640_supported_win_sizes[default_size];
}
static int ov2640_set_params(struct i2c_client *client, u32 *width, u32 *height,
enum v4l2_mbus_pixelcode code)
{
struct ov2640_priv *priv = to_ov2640(client);
const struct regval_list *selected_cfmt_regs;
int ret;
priv->win = ov2640_select_win(width, height);
priv->cfmt_code = 0;
switch (code) {
case V4L2_MBUS_FMT_RGB565_2X8_LE:
dev_dbg(&client->dev, "%s: Selected cfmt RGB565", __func__);
selected_cfmt_regs = ov2640_rgb565_regs;
break;
default:
case V4L2_MBUS_FMT_UYVY8_2X8:
dev_dbg(&client->dev, "%s: Selected cfmt YUV422", __func__);
selected_cfmt_regs = ov2640_yuv422_regs;
}
ov2640_reset(client);
dev_dbg(&client->dev, "%s: Init default", __func__);
ret = ov2640_write_array(client, ov2640_init_regs);
if (ret < 0)
goto err;
dev_dbg(&client->dev, "%s: Set size to %s", __func__, priv->win->name);
ret = ov2640_write_array(client, ov2640_size_change_preamble_regs);
if (ret < 0)
goto err;
ret = ov2640_write_array(client, priv->win->regs);
if (ret < 0)
goto err;
dev_dbg(&client->dev, "%s: Set cfmt", __func__);
ret = ov2640_write_array(client, ov2640_format_change_preamble_regs);
if (ret < 0)
goto err;
ret = ov2640_write_array(client, selected_cfmt_regs);
if (ret < 0)
goto err;
priv->cfmt_code = code;
*width = priv->win->width;
*height = priv->win->height;
return 0;
err:
dev_err(&client->dev, "%s: Error %d", __func__, ret);
ov2640_reset(client);
priv->win = NULL;
return ret;
}
static int ov2640_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2640_priv *priv = to_ov2640(client);
if (!priv->win) {
u32 width = W_SVGA, height = H_SVGA;
int ret = ov2640_set_params(client, &width, &height,
V4L2_MBUS_FMT_UYVY8_2X8);
if (ret < 0)
return ret;
}
mf->width = priv->win->width;
mf->height = priv->win->height;
mf->code = priv->cfmt_code;
switch (mf->code) {
case V4L2_MBUS_FMT_RGB565_2X8_LE:
mf->colorspace = V4L2_COLORSPACE_SRGB;
break;
default:
case V4L2_MBUS_FMT_UYVY8_2X8:
mf->colorspace = V4L2_COLORSPACE_JPEG;
}
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov2640_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
switch (mf->code) {
case V4L2_MBUS_FMT_RGB565_2X8_LE:
mf->colorspace = V4L2_COLORSPACE_SRGB;
break;
default:
mf->code = V4L2_MBUS_FMT_UYVY8_2X8;
case V4L2_MBUS_FMT_UYVY8_2X8:
mf->colorspace = V4L2_COLORSPACE_JPEG;
}
ret = ov2640_set_params(client, &mf->width, &mf->height, mf->code);
return ret;
}
static int ov2640_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
const struct ov2640_win_size *win;
win = ov2640_select_win(&mf->width, &mf->height);
mf->field = V4L2_FIELD_NONE;
switch (mf->code) {
case V4L2_MBUS_FMT_RGB565_2X8_LE:
mf->colorspace = V4L2_COLORSPACE_SRGB;
break;
default:
mf->code = V4L2_MBUS_FMT_UYVY8_2X8;
case V4L2_MBUS_FMT_UYVY8_2X8:
mf->colorspace = V4L2_COLORSPACE_JPEG;
}
return 0;
}
static int ov2640_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(ov2640_codes))
return -EINVAL;
*code = ov2640_codes[index];
return 0;
}
static int ov2640_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
a->c.left = 0;
a->c.top = 0;
a->c.width = W_UXGA;
a->c.height = H_UXGA;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int ov2640_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = W_UXGA;
a->bounds.height = H_UXGA;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ov2640_video_probe(struct soc_camera_device *icd,
struct i2c_client *client)
{
struct ov2640_priv *priv = to_ov2640(client);
u8 pid, ver, midh, midl;
const char *devname;
int ret;
BUG_ON(!icd->parent ||
to_soc_camera_host(icd->parent)->nr != icd->iface);
i2c_smbus_write_byte_data(client, BANK_SEL, BANK_SEL_SENS);
pid = i2c_smbus_read_byte_data(client, PID);
ver = i2c_smbus_read_byte_data(client, VER);
midh = i2c_smbus_read_byte_data(client, MIDH);
midl = i2c_smbus_read_byte_data(client, MIDL);
switch (VERSION(pid, ver)) {
case PID_OV2640:
devname = "ov2640";
priv->model = V4L2_IDENT_OV2640;
break;
default:
dev_err(&client->dev,
"Product ID error %x:%x\n", pid, ver);
ret = -ENODEV;
goto err;
}
dev_info(&client->dev,
"%s Product ID %0x:%0x Manufacturer ID %x:%x\n",
devname, pid, ver, midh, midl);
return 0;
err:
return ret;
}
static int ov2640_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov2640_priv *priv;
struct soc_camera_device *icd = client->dev.platform_data;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl;
int ret;
if (!icd) {
dev_err(&adapter->dev, "OV2640: missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&adapter->dev,
"OV2640: Missing platform_data for driver\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&adapter->dev,
"OV2640: I2C-Adapter doesn't support SMBUS\n");
return -EIO;
}
priv = kzalloc(sizeof(struct ov2640_priv), GFP_KERNEL);
if (!priv) {
dev_err(&adapter->dev,
"Failed to allocate memory for private data!\n");
return -ENOMEM;
}
priv->info = icl->priv;
v4l2_i2c_subdev_init(&priv->subdev, client, &ov2640_subdev_ops);
icd->ops = &ov2640_ops;
ret = ov2640_video_probe(icd, client);
if (ret) {
icd->ops = NULL;
kfree(priv);
} else {
dev_info(&adapter->dev, "OV2640 Probed\n");
}
return ret;
}
static int ov2640_remove(struct i2c_client *client)
{
struct ov2640_priv *priv = to_ov2640(client);
struct soc_camera_device *icd = client->dev.platform_data;
icd->ops = NULL;
kfree(priv);
return 0;
}
static int __init ov2640_module_init(void)
{
return i2c_add_driver(&ov2640_i2c_driver);
}
static void __exit ov2640_module_exit(void)
{
i2c_del_driver(&ov2640_i2c_driver);
}
