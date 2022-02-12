static struct ov772x_priv *to_ov772x(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov772x_priv, subdev);
}
static inline int ov772x_read(struct i2c_client *client, u8 addr)
{
return i2c_smbus_read_byte_data(client, addr);
}
static inline int ov772x_write(struct i2c_client *client, u8 addr, u8 value)
{
return i2c_smbus_write_byte_data(client, addr, value);
}
static int ov772x_mask_set(struct i2c_client *client, u8 command, u8 mask,
u8 set)
{
s32 val = ov772x_read(client, command);
if (val < 0)
return val;
val &= ~mask;
val |= set & mask;
return ov772x_write(client, command, val);
}
static int ov772x_reset(struct i2c_client *client)
{
int ret;
ret = ov772x_write(client, COM7, SCCB_RESET);
if (ret < 0)
return ret;
msleep(1);
return ov772x_mask_set(client, COM2, SOFT_SLEEP_MODE, SOFT_SLEEP_MODE);
}
static int ov772x_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov772x_priv *priv = to_ov772x(sd);
if (!enable) {
ov772x_mask_set(client, COM2, SOFT_SLEEP_MODE, SOFT_SLEEP_MODE);
return 0;
}
ov772x_mask_set(client, COM2, SOFT_SLEEP_MODE, 0);
dev_dbg(&client->dev, "format %d, win %s\n",
priv->cfmt->code, priv->win->name);
return 0;
}
static int ov772x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov772x_priv *priv = container_of(ctrl->handler,
struct ov772x_priv, hdl);
struct v4l2_subdev *sd = &priv->subdev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
u8 val;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
val = ctrl->val ? VFLIP_IMG : 0x00;
priv->flag_vflip = ctrl->val;
if (priv->info->flags & OV772X_FLAG_VFLIP)
val ^= VFLIP_IMG;
return ov772x_mask_set(client, COM3, VFLIP_IMG, val);
case V4L2_CID_HFLIP:
val = ctrl->val ? HFLIP_IMG : 0x00;
priv->flag_hflip = ctrl->val;
if (priv->info->flags & OV772X_FLAG_HFLIP)
val ^= HFLIP_IMG;
return ov772x_mask_set(client, COM3, HFLIP_IMG, val);
case V4L2_CID_BAND_STOP_FILTER:
if (!ctrl->val) {
ret = ov772x_mask_set(client, BDBASE, 0xff, 0xff);
if (!ret)
ret = ov772x_mask_set(client, COM8,
BNDF_ON_OFF, 0);
} else {
val = 256 - ctrl->val;
ret = ov772x_mask_set(client, COM8,
BNDF_ON_OFF, BNDF_ON_OFF);
if (!ret)
ret = ov772x_mask_set(client, BDBASE,
0xff, val);
}
if (!ret)
priv->band_filter = ctrl->val;
return ret;
}
return -EINVAL;
}
static int ov772x_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
reg->size = 1;
if (reg->reg > 0xff)
return -EINVAL;
ret = ov772x_read(client, reg->reg);
if (ret < 0)
return ret;
reg->val = (__u64)ret;
return 0;
}
static int ov772x_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return ov772x_write(client, reg->reg, reg->val);
}
static int ov772x_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct ov772x_priv *priv = to_ov772x(sd);
return soc_camera_set_power(&client->dev, ssdd, priv->clk, on);
}
static const struct ov772x_win_size *ov772x_select_win(u32 width, u32 height)
{
const struct ov772x_win_size *win = &ov772x_win_sizes[0];
u32 best_diff = UINT_MAX;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(ov772x_win_sizes); ++i) {
u32 diff = abs(width - ov772x_win_sizes[i].rect.width)
+ abs(height - ov772x_win_sizes[i].rect.height);
if (diff < best_diff) {
best_diff = diff;
win = &ov772x_win_sizes[i];
}
}
return win;
}
static void ov772x_select_params(const struct v4l2_mbus_framefmt *mf,
const struct ov772x_color_format **cfmt,
const struct ov772x_win_size **win)
{
unsigned int i;
*cfmt = &ov772x_cfmts[0];
for (i = 0; i < ARRAY_SIZE(ov772x_cfmts); i++) {
if (mf->code == ov772x_cfmts[i].code) {
*cfmt = &ov772x_cfmts[i];
break;
}
}
*win = ov772x_select_win(mf->width, mf->height);
}
static int ov772x_set_params(struct ov772x_priv *priv,
const struct ov772x_color_format *cfmt,
const struct ov772x_win_size *win)
{
struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
int ret;
u8 val;
ov772x_reset(client);
if (priv->info->edgectrl.strength & OV772X_MANUAL_EDGE_CTRL) {
ret = ov772x_mask_set(client, DSPAUTO, EDGE_ACTRL, 0x00);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_mask_set(client,
EDGE_TRSHLD, OV772X_EDGE_THRESHOLD_MASK,
priv->info->edgectrl.threshold);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_mask_set(client,
EDGE_STRNGT, OV772X_EDGE_STRENGTH_MASK,
priv->info->edgectrl.strength);
if (ret < 0)
goto ov772x_set_fmt_error;
} else if (priv->info->edgectrl.upper > priv->info->edgectrl.lower) {
ret = ov772x_mask_set(client,
EDGE_UPPER, OV772X_EDGE_UPPER_MASK,
priv->info->edgectrl.upper);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_mask_set(client,
EDGE_LOWER, OV772X_EDGE_LOWER_MASK,
priv->info->edgectrl.lower);
if (ret < 0)
goto ov772x_set_fmt_error;
}
ret = ov772x_write(client, HSTART, win->rect.left >> 2);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, HSIZE, win->rect.width >> 2);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, VSTART, win->rect.top >> 1);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, VSIZE, win->rect.height >> 1);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, HOUTSIZE, win->rect.width >> 2);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, VOUTSIZE, win->rect.height >> 1);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, HREF,
((win->rect.top & 1) << HREF_VSTART_SHIFT) |
((win->rect.left & 3) << HREF_HSTART_SHIFT) |
((win->rect.height & 1) << HREF_VSIZE_SHIFT) |
((win->rect.width & 3) << HREF_HSIZE_SHIFT));
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, EXHCH,
((win->rect.height & 1) << EXHCH_VSIZE_SHIFT) |
((win->rect.width & 3) << EXHCH_HSIZE_SHIFT));
if (ret < 0)
goto ov772x_set_fmt_error;
val = cfmt->dsp3;
if (val) {
ret = ov772x_mask_set(client,
DSP_CTRL3, UV_MASK, val);
if (ret < 0)
goto ov772x_set_fmt_error;
}
if (cfmt->dsp4) {
ret = ov772x_write(client, DSP_CTRL4, cfmt->dsp4);
if (ret < 0)
goto ov772x_set_fmt_error;
}
val = cfmt->com3;
if (priv->info->flags & OV772X_FLAG_VFLIP)
val |= VFLIP_IMG;
if (priv->info->flags & OV772X_FLAG_HFLIP)
val |= HFLIP_IMG;
if (priv->flag_vflip)
val ^= VFLIP_IMG;
if (priv->flag_hflip)
val ^= HFLIP_IMG;
ret = ov772x_mask_set(client,
COM3, SWAP_MASK | IMG_MASK, val);
if (ret < 0)
goto ov772x_set_fmt_error;
ret = ov772x_write(client, COM7, win->com7_bit | cfmt->com7);
if (ret < 0)
goto ov772x_set_fmt_error;
if (priv->band_filter) {
ret = ov772x_mask_set(client, COM8, BNDF_ON_OFF, 1);
if (!ret)
ret = ov772x_mask_set(client, BDBASE,
0xff, 256 - priv->band_filter);
if (ret < 0)
goto ov772x_set_fmt_error;
}
return ret;
ov772x_set_fmt_error:
ov772x_reset(client);
return ret;
}
static int ov772x_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
sel->r.left = 0;
sel->r.top = 0;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
sel->r.width = OV772X_MAX_WIDTH;
sel->r.height = OV772X_MAX_HEIGHT;
return 0;
case V4L2_SEL_TGT_CROP:
sel->r.width = VGA_WIDTH;
sel->r.height = VGA_HEIGHT;
return 0;
default:
return -EINVAL;
}
}
static int ov772x_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct ov772x_priv *priv = to_ov772x(sd);
if (format->pad)
return -EINVAL;
mf->width = priv->win->rect.width;
mf->height = priv->win->rect.height;
mf->code = priv->cfmt->code;
mf->colorspace = priv->cfmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov772x_s_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *mf)
{
struct ov772x_priv *priv = to_ov772x(sd);
const struct ov772x_color_format *cfmt;
const struct ov772x_win_size *win;
int ret;
ov772x_select_params(mf, &cfmt, &win);
ret = ov772x_set_params(priv, cfmt, win);
if (ret < 0)
return ret;
priv->win = win;
priv->cfmt = cfmt;
mf->code = cfmt->code;
mf->width = win->rect.width;
mf->height = win->rect.height;
mf->field = V4L2_FIELD_NONE;
mf->colorspace = cfmt->colorspace;
return 0;
}
static int ov772x_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
const struct ov772x_color_format *cfmt;
const struct ov772x_win_size *win;
if (format->pad)
return -EINVAL;
ov772x_select_params(mf, &cfmt, &win);
mf->code = cfmt->code;
mf->width = win->rect.width;
mf->height = win->rect.height;
mf->field = V4L2_FIELD_NONE;
mf->colorspace = cfmt->colorspace;
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return ov772x_s_fmt(sd, mf);
cfg->try_fmt = *mf;
return 0;
}
static int ov772x_video_probe(struct ov772x_priv *priv)
{
struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
u8 pid, ver;
const char *devname;
int ret;
ret = ov772x_s_power(&priv->subdev, 1);
if (ret < 0)
return ret;
pid = ov772x_read(client, PID);
ver = ov772x_read(client, VER);
switch (VERSION(pid, ver)) {
case OV7720:
devname = "ov7720";
break;
case OV7725:
devname = "ov7725";
break;
default:
dev_err(&client->dev,
"Product ID error %x:%x\n", pid, ver);
ret = -ENODEV;
goto done;
}
dev_info(&client->dev,
"%s Product ID %0x:%0x Manufacturer ID %x:%x\n",
devname,
pid,
ver,
ov772x_read(client, MIDH),
ov772x_read(client, MIDL));
ret = v4l2_ctrl_handler_setup(&priv->hdl);
done:
ov772x_s_power(&priv->subdev, 0);
return ret;
}
static int ov772x_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= ARRAY_SIZE(ov772x_cfmts))
return -EINVAL;
code->code = ov772x_cfmts[code->index].code;
return 0;
}
static int ov772x_g_mbus_config(struct v4l2_subdev *sd,
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
static int ov772x_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov772x_priv *priv;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int ret;
if (!ssdd || !ssdd->drv_priv) {
dev_err(&client->dev, "OV772X: missing platform data!\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_BYTE_DATA\n");
return -EIO;
}
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->info = ssdd->drv_priv;
v4l2_i2c_subdev_init(&priv->subdev, client, &ov772x_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 3);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_BAND_STOP_FILTER, 0, 256, 1, 0);
priv->subdev.ctrl_handler = &priv->hdl;
if (priv->hdl.error)
return priv->hdl.error;
priv->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
goto eclkget;
}
ret = ov772x_video_probe(priv);
if (ret < 0) {
v4l2_clk_put(priv->clk);
eclkget:
v4l2_ctrl_handler_free(&priv->hdl);
} else {
priv->cfmt = &ov772x_cfmts[0];
priv->win = &ov772x_win_sizes[0];
}
return ret;
}
static int ov772x_remove(struct i2c_client *client)
{
struct ov772x_priv *priv = to_ov772x(i2c_get_clientdata(client));
v4l2_clk_put(priv->clk);
v4l2_device_unregister_subdev(&priv->subdev);
v4l2_ctrl_handler_free(&priv->hdl);
return 0;
}
