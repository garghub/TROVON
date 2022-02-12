static struct ov772x_priv *to_ov772x(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct ov772x_priv,
subdev);
}
static int ov772x_write_array(struct i2c_client *client,
const struct regval_list *vals)
{
while (vals->reg_num != 0xff) {
int ret = i2c_smbus_write_byte_data(client,
vals->reg_num,
vals->value);
if (ret < 0)
return ret;
vals++;
}
return 0;
}
static int ov772x_mask_set(struct i2c_client *client,
u8 command,
u8 mask,
u8 set)
{
s32 val = i2c_smbus_read_byte_data(client, command);
if (val < 0)
return val;
val &= ~mask;
val |= set & mask;
return i2c_smbus_write_byte_data(client, command, val);
}
static int ov772x_reset(struct i2c_client *client)
{
int ret = i2c_smbus_write_byte_data(client, COM7, SCCB_RESET);
msleep(1);
return ret;
}
static int ov772x_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov772x_priv *priv = container_of(sd, struct ov772x_priv, subdev);
if (!enable) {
ov772x_mask_set(client, COM2, SOFT_SLEEP_MODE, SOFT_SLEEP_MODE);
return 0;
}
if (!priv->win || !priv->cfmt) {
dev_err(&client->dev, "norm or win select error\n");
return -EPERM;
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
static int ov772x_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct ov772x_priv *priv = container_of(sd, struct ov772x_priv, subdev);
id->ident = priv->model;
id->revision = 0;
return 0;
}
static int ov772x_g_register(struct v4l2_subdev *sd,
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
reg->val = (__u64)ret;
return 0;
}
static int ov772x_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0xff ||
reg->val > 0xff)
return -EINVAL;
return i2c_smbus_write_byte_data(client, reg->reg, reg->val);
}
static const struct ov772x_win_size *ov772x_select_win(u32 width, u32 height)
{
__u32 diff;
const struct ov772x_win_size *win;
diff = abs(width - ov772x_win_qvga.width) +
abs(height - ov772x_win_qvga.height);
win = &ov772x_win_qvga;
if (diff >
abs(width - ov772x_win_vga.width) +
abs(height - ov772x_win_vga.height))
win = &ov772x_win_vga;
return win;
}
static int ov772x_set_params(struct i2c_client *client, u32 *width, u32 *height,
enum v4l2_mbus_pixelcode code)
{
struct ov772x_priv *priv = to_ov772x(client);
int ret = -EINVAL;
u8 val;
int i;
priv->cfmt = NULL;
for (i = 0; i < ARRAY_SIZE(ov772x_cfmts); i++) {
if (code == ov772x_cfmts[i].code) {
priv->cfmt = ov772x_cfmts + i;
break;
}
}
if (!priv->cfmt)
goto ov772x_set_fmt_error;
priv->win = ov772x_select_win(*width, *height);
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
ret = ov772x_write_array(client, priv->win->regs);
if (ret < 0)
goto ov772x_set_fmt_error;
val = priv->cfmt->dsp3;
if (val) {
ret = ov772x_mask_set(client,
DSP_CTRL3, UV_MASK, val);
if (ret < 0)
goto ov772x_set_fmt_error;
}
val = priv->cfmt->com3;
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
val = priv->win->com7_bit | priv->cfmt->com7;
ret = ov772x_mask_set(client,
COM7, SLCT_MASK | FMT_MASK | OFMT_MASK,
val);
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
*width = priv->win->width;
*height = priv->win->height;
return ret;
ov772x_set_fmt_error:
ov772x_reset(client);
priv->win = NULL;
priv->cfmt = NULL;
return ret;
}
static int ov772x_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
a->c.left = 0;
a->c.top = 0;
a->c.width = VGA_WIDTH;
a->c.height = VGA_HEIGHT;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int ov772x_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = VGA_WIDTH;
a->bounds.height = VGA_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ov772x_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov772x_priv *priv = container_of(sd, struct ov772x_priv, subdev);
if (!priv->win || !priv->cfmt) {
u32 width = VGA_WIDTH, height = VGA_HEIGHT;
int ret = ov772x_set_params(client, &width, &height,
V4L2_MBUS_FMT_YUYV8_2X8);
if (ret < 0)
return ret;
}
mf->width = priv->win->width;
mf->height = priv->win->height;
mf->code = priv->cfmt->code;
mf->colorspace = priv->cfmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov772x_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov772x_priv *priv = container_of(sd, struct ov772x_priv, subdev);
int ret = ov772x_set_params(client, &mf->width, &mf->height,
mf->code);
if (!ret)
mf->colorspace = priv->cfmt->colorspace;
return ret;
}
static int ov772x_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct ov772x_priv *priv = container_of(sd, struct ov772x_priv, subdev);
const struct ov772x_win_size *win;
int i;
win = ov772x_select_win(mf->width, mf->height);
mf->width = win->width;
mf->height = win->height;
mf->field = V4L2_FIELD_NONE;
for (i = 0; i < ARRAY_SIZE(ov772x_cfmts); i++)
if (mf->code == ov772x_cfmts[i].code)
break;
if (i == ARRAY_SIZE(ov772x_cfmts)) {
if (priv->cfmt) {
mf->colorspace = priv->cfmt->colorspace;
mf->code = priv->cfmt->code;
} else {
mf->colorspace = ov772x_cfmts[0].colorspace;
mf->code = ov772x_cfmts[0].code;
}
} else {
mf->colorspace = ov772x_cfmts[i].colorspace;
}
return 0;
}
static int ov772x_video_probe(struct i2c_client *client)
{
struct ov772x_priv *priv = to_ov772x(client);
u8 pid, ver;
const char *devname;
pid = i2c_smbus_read_byte_data(client, PID);
ver = i2c_smbus_read_byte_data(client, VER);
switch (VERSION(pid, ver)) {
case OV7720:
devname = "ov7720";
priv->model = V4L2_IDENT_OV7720;
break;
case OV7725:
devname = "ov7725";
priv->model = V4L2_IDENT_OV7725;
break;
default:
dev_err(&client->dev,
"Product ID error %x:%x\n", pid, ver);
return -ENODEV;
}
dev_info(&client->dev,
"%s Product ID %0x:%0x Manufacturer ID %x:%x\n",
devname,
pid,
ver,
i2c_smbus_read_byte_data(client, MIDH),
i2c_smbus_read_byte_data(client, MIDL));
return v4l2_ctrl_handler_setup(&priv->hdl);
}
static int ov772x_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(ov772x_cfmts))
return -EINVAL;
*code = ov772x_cfmts[index].code;
return 0;
}
static int ov772x_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_MASTER |
V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_HIGH |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(icl, cfg);
return 0;
}
static int ov772x_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov772x_priv *priv;
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int ret;
if (!icl || !icl->priv) {
dev_err(&client->dev, "OV772X: missing platform data!\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&adapter->dev,
"I2C-Adapter doesn't support "
"I2C_FUNC_SMBUS_BYTE_DATA\n");
return -EIO;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->info = icl->priv;
v4l2_i2c_subdev_init(&priv->subdev, client, &ov772x_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 3);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov772x_ctrl_ops,
V4L2_CID_BAND_STOP_FILTER, 0, 256, 1, 0);
priv->subdev.ctrl_handler = &priv->hdl;
if (priv->hdl.error) {
int err = priv->hdl.error;
kfree(priv);
return err;
}
ret = ov772x_video_probe(client);
if (ret) {
v4l2_ctrl_handler_free(&priv->hdl);
kfree(priv);
}
return ret;
}
static int ov772x_remove(struct i2c_client *client)
{
struct ov772x_priv *priv = to_ov772x(client);
v4l2_device_unregister_subdev(&priv->subdev);
v4l2_ctrl_handler_free(&priv->hdl);
kfree(priv);
return 0;
}
