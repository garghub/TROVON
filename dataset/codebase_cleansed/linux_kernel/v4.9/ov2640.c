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
static int ov2640_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd =
&container_of(ctrl->handler, struct ov2640_priv, hdl)->subdev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 val;
int ret;
ret = i2c_smbus_write_byte_data(client, BANK_SEL, BANK_SEL_SENS);
if (ret < 0)
return ret;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
val = ctrl->val ? REG04_VFLIP_IMG : 0x00;
return ov2640_mask_set(client, REG04, REG04_VFLIP_IMG, val);
case V4L2_CID_HFLIP:
val = ctrl->val ? REG04_HFLIP_IMG : 0x00;
return ov2640_mask_set(client, REG04, REG04_HFLIP_IMG, val);
}
return -EINVAL;
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
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return i2c_smbus_write_byte_data(client, reg->reg, reg->val);
}
static int ov2640_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct ov2640_priv *priv = to_ov2640(client);
return soc_camera_set_power(&client->dev, ssdd, priv->clk, on);
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
u32 code)
{
struct ov2640_priv *priv = to_ov2640(client);
const struct regval_list *selected_cfmt_regs;
int ret;
priv->win = ov2640_select_win(width, height);
priv->cfmt_code = 0;
switch (code) {
case MEDIA_BUS_FMT_RGB565_2X8_BE:
dev_dbg(&client->dev, "%s: Selected cfmt RGB565 BE", __func__);
selected_cfmt_regs = ov2640_rgb565_be_regs;
break;
case MEDIA_BUS_FMT_RGB565_2X8_LE:
dev_dbg(&client->dev, "%s: Selected cfmt RGB565 LE", __func__);
selected_cfmt_regs = ov2640_rgb565_le_regs;
break;
case MEDIA_BUS_FMT_YUYV8_2X8:
dev_dbg(&client->dev, "%s: Selected cfmt YUYV (YUV422)", __func__);
selected_cfmt_regs = ov2640_yuyv_regs;
break;
default:
case MEDIA_BUS_FMT_UYVY8_2X8:
dev_dbg(&client->dev, "%s: Selected cfmt UYVY", __func__);
selected_cfmt_regs = ov2640_uyvy_regs;
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
static int ov2640_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2640_priv *priv = to_ov2640(client);
if (format->pad)
return -EINVAL;
if (!priv->win) {
u32 width = SVGA_WIDTH, height = SVGA_HEIGHT;
priv->win = ov2640_select_win(&width, &height);
priv->cfmt_code = MEDIA_BUS_FMT_UYVY8_2X8;
}
mf->width = priv->win->width;
mf->height = priv->win->height;
mf->code = priv->cfmt_code;
switch (mf->code) {
case MEDIA_BUS_FMT_RGB565_2X8_BE:
case MEDIA_BUS_FMT_RGB565_2X8_LE:
mf->colorspace = V4L2_COLORSPACE_SRGB;
break;
default:
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_UYVY8_2X8:
mf->colorspace = V4L2_COLORSPACE_JPEG;
}
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov2640_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (format->pad)
return -EINVAL;
ov2640_select_win(&mf->width, &mf->height);
mf->field = V4L2_FIELD_NONE;
switch (mf->code) {
case MEDIA_BUS_FMT_RGB565_2X8_BE:
case MEDIA_BUS_FMT_RGB565_2X8_LE:
mf->colorspace = V4L2_COLORSPACE_SRGB;
break;
default:
mf->code = MEDIA_BUS_FMT_UYVY8_2X8;
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_UYVY8_2X8:
mf->colorspace = V4L2_COLORSPACE_JPEG;
}
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return ov2640_set_params(client, &mf->width,
&mf->height, mf->code);
cfg->try_fmt = *mf;
return 0;
}
static int ov2640_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= ARRAY_SIZE(ov2640_codes))
return -EINVAL;
code->code = ov2640_codes[code->index];
return 0;
}
static int ov2640_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_CROP:
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = UXGA_WIDTH;
sel->r.height = UXGA_HEIGHT;
return 0;
default:
return -EINVAL;
}
}
static int ov2640_video_probe(struct i2c_client *client)
{
struct ov2640_priv *priv = to_ov2640(client);
u8 pid, ver, midh, midl;
const char *devname;
int ret;
ret = ov2640_s_power(&priv->subdev, 1);
if (ret < 0)
return ret;
i2c_smbus_write_byte_data(client, BANK_SEL, BANK_SEL_SENS);
pid = i2c_smbus_read_byte_data(client, PID);
ver = i2c_smbus_read_byte_data(client, VER);
midh = i2c_smbus_read_byte_data(client, MIDH);
midl = i2c_smbus_read_byte_data(client, MIDL);
switch (VERSION(pid, ver)) {
case PID_OV2640:
devname = "ov2640";
break;
default:
dev_err(&client->dev,
"Product ID error %x:%x\n", pid, ver);
ret = -ENODEV;
goto done;
}
dev_info(&client->dev,
"%s Product ID %0x:%0x Manufacturer ID %x:%x\n",
devname, pid, ver, midh, midl);
ret = v4l2_ctrl_handler_setup(&priv->hdl);
done:
ov2640_s_power(&priv->subdev, 0);
return ret;
}
static int ov2640_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_MASTER |
V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_HIGH |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(ssdd, cfg);
return 0;
}
static int ov2640_hw_power(struct device *dev, int on)
{
struct i2c_client *client = to_i2c_client(dev);
struct ov2640_priv *priv = to_ov2640(client);
dev_dbg(&client->dev, "%s: %s the camera\n",
__func__, on ? "ENABLE" : "DISABLE");
if (priv->pwdn_gpio)
gpiod_direction_output(priv->pwdn_gpio, !on);
return 0;
}
static int ov2640_hw_reset(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ov2640_priv *priv = to_ov2640(client);
if (priv->resetb_gpio) {
gpiod_direction_output(priv->resetb_gpio, 1);
usleep_range(3000, 5000);
gpiod_direction_output(priv->resetb_gpio, 0);
}
return 0;
}
static int ov2640_probe_dt(struct i2c_client *client,
struct ov2640_priv *priv)
{
priv->resetb_gpio = devm_gpiod_get_optional(&client->dev, "resetb",
GPIOD_OUT_LOW);
if (!priv->resetb_gpio)
dev_dbg(&client->dev, "resetb gpio is not assigned!\n");
else if (IS_ERR(priv->resetb_gpio))
return PTR_ERR(priv->resetb_gpio);
priv->pwdn_gpio = devm_gpiod_get_optional(&client->dev, "pwdn",
GPIOD_OUT_HIGH);
if (!priv->pwdn_gpio)
dev_dbg(&client->dev, "pwdn gpio is not assigned!\n");
else if (IS_ERR(priv->pwdn_gpio))
return PTR_ERR(priv->pwdn_gpio);
priv->ssdd_dt.power = ov2640_hw_power;
priv->ssdd_dt.reset = ov2640_hw_reset;
client->dev.platform_data = &priv->ssdd_dt;
return 0;
}
static int ov2640_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov2640_priv *priv;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&adapter->dev,
"OV2640: I2C-Adapter doesn't support SMBUS\n");
return -EIO;
}
priv = devm_kzalloc(&client->dev, sizeof(struct ov2640_priv), GFP_KERNEL);
if (!priv) {
dev_err(&adapter->dev,
"Failed to allocate memory for private data!\n");
return -ENOMEM;
}
priv->clk = v4l2_clk_get(&client->dev, "xvclk");
if (IS_ERR(priv->clk))
return -EPROBE_DEFER;
if (!ssdd && !client->dev.of_node) {
dev_err(&client->dev, "Missing platform_data for driver\n");
ret = -EINVAL;
goto err_clk;
}
if (!ssdd) {
ret = ov2640_probe_dt(client, priv);
if (ret)
goto err_clk;
}
v4l2_i2c_subdev_init(&priv->subdev, client, &ov2640_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 2);
v4l2_ctrl_new_std(&priv->hdl, &ov2640_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov2640_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
priv->subdev.ctrl_handler = &priv->hdl;
if (priv->hdl.error) {
ret = priv->hdl.error;
goto err_clk;
}
ret = ov2640_video_probe(client);
if (ret < 0)
goto err_videoprobe;
ret = v4l2_async_register_subdev(&priv->subdev);
if (ret < 0)
goto err_videoprobe;
dev_info(&adapter->dev, "OV2640 Probed\n");
return 0;
err_videoprobe:
v4l2_ctrl_handler_free(&priv->hdl);
err_clk:
v4l2_clk_put(priv->clk);
return ret;
}
static int ov2640_remove(struct i2c_client *client)
{
struct ov2640_priv *priv = to_ov2640(client);
v4l2_async_unregister_subdev(&priv->subdev);
v4l2_clk_put(priv->clk);
v4l2_device_unregister_subdev(&priv->subdev);
v4l2_ctrl_handler_free(&priv->hdl);
return 0;
}
