static int ov9640_reg_read(struct i2c_client *client, u8 reg, u8 *val)
{
int ret;
u8 data = reg;
struct i2c_msg msg = {
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &data,
};
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0)
goto err;
msg.flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0)
goto err;
*val = data;
return 0;
err:
dev_err(&client->dev, "Failed reading register 0x%02x!\n", reg);
return ret;
}
static int ov9640_reg_write(struct i2c_client *client, u8 reg, u8 val)
{
int ret;
u8 _val;
unsigned char data[2] = { reg, val };
struct i2c_msg msg = {
.addr = client->addr,
.flags = 0,
.len = 2,
.buf = data,
};
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
dev_err(&client->dev, "Failed writing register 0x%02x!\n", reg);
return ret;
}
ret = ov9640_reg_read(client, reg, &_val);
if (ret)
dev_err(&client->dev,
"Failed reading back register 0x%02x!\n", reg);
return 0;
}
static int ov9640_reg_rmw(struct i2c_client *client, u8 reg, u8 set, u8 unset)
{
u8 val;
int ret;
ret = ov9640_reg_read(client, reg, &val);
if (ret) {
dev_err(&client->dev,
"[Read]-Modify-Write of register %02x failed!\n", reg);
return val;
}
val |= set;
val &= ~unset;
ret = ov9640_reg_write(client, reg, val);
if (ret)
dev_err(&client->dev,
"Read-Modify-[Write] of register %02x failed!\n", reg);
return ret;
}
static int ov9640_reset(struct i2c_client *client)
{
int ret;
ret = ov9640_reg_write(client, OV9640_COM7, OV9640_COM7_SCCB_RESET);
if (ret)
dev_err(&client->dev,
"An error occurred while entering soft reset!\n");
return ret;
}
static int ov9640_s_stream(struct v4l2_subdev *sd, int enable)
{
return 0;
}
static int ov9640_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov9640_priv *priv = container_of(ctrl->handler, struct ov9640_priv, hdl);
struct i2c_client *client = v4l2_get_subdevdata(&priv->subdev);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->val)
return ov9640_reg_rmw(client, OV9640_MVFP,
OV9640_MVFP_V, 0);
return ov9640_reg_rmw(client, OV9640_MVFP, 0, OV9640_MVFP_V);
case V4L2_CID_HFLIP:
if (ctrl->val)
return ov9640_reg_rmw(client, OV9640_MVFP,
OV9640_MVFP_H, 0);
return ov9640_reg_rmw(client, OV9640_MVFP, 0, OV9640_MVFP_H);
}
return -EINVAL;
}
static int ov9640_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct ov9640_priv *priv = to_ov9640_sensor(sd);
id->ident = priv->model;
id->revision = priv->revision;
return 0;
}
static int ov9640_get_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
u8 val;
if (reg->reg & ~0xff)
return -EINVAL;
reg->size = 1;
ret = ov9640_reg_read(client, reg->reg, &val);
if (ret)
return ret;
reg->val = (__u64)val;
return 0;
}
static int ov9640_set_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg & ~0xff || reg->val & ~0xff)
return -EINVAL;
return ov9640_reg_write(client, reg->reg, reg->val);
}
static void ov9640_res_roundup(u32 *width, u32 *height)
{
int i;
enum { QQCIF, QQVGA, QCIF, QVGA, CIF, VGA, SXGA };
int res_x[] = { 88, 160, 176, 320, 352, 640, 1280 };
int res_y[] = { 72, 120, 144, 240, 288, 480, 960 };
for (i = 0; i < ARRAY_SIZE(res_x); i++) {
if (res_x[i] >= *width && res_y[i] >= *height) {
*width = res_x[i];
*height = res_y[i];
return;
}
}
*width = res_x[SXGA];
*height = res_y[SXGA];
}
static void ov9640_alter_regs(enum v4l2_mbus_pixelcode code,
struct ov9640_reg_alt *alt)
{
switch (code) {
default:
case V4L2_MBUS_FMT_UYVY8_2X8:
alt->com12 = OV9640_COM12_YUV_AVG;
alt->com13 = OV9640_COM13_Y_DELAY_EN |
OV9640_COM13_YUV_DLY(0x01);
break;
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE:
alt->com7 = OV9640_COM7_RGB;
alt->com13 = OV9640_COM13_RGB_AVG;
alt->com15 = OV9640_COM15_RGB_555;
break;
case V4L2_MBUS_FMT_RGB565_2X8_LE:
alt->com7 = OV9640_COM7_RGB;
alt->com13 = OV9640_COM13_RGB_AVG;
alt->com15 = OV9640_COM15_RGB_565;
break;
};
}
static int ov9640_write_regs(struct i2c_client *client, u32 width,
enum v4l2_mbus_pixelcode code, struct ov9640_reg_alt *alts)
{
const struct ov9640_reg *ov9640_regs, *matrix_regs;
int ov9640_regs_len, matrix_regs_len;
int i, ret;
u8 val;
switch (width) {
case W_QQCIF:
ov9640_regs = ov9640_regs_qqcif;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_qqcif);
break;
case W_QQVGA:
ov9640_regs = ov9640_regs_qqvga;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_qqvga);
break;
case W_QCIF:
ov9640_regs = ov9640_regs_qcif;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_qcif);
break;
case W_QVGA:
ov9640_regs = ov9640_regs_qvga;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_qvga);
break;
case W_CIF:
ov9640_regs = ov9640_regs_cif;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_cif);
break;
case W_VGA:
ov9640_regs = ov9640_regs_vga;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_vga);
break;
case W_SXGA:
ov9640_regs = ov9640_regs_sxga;
ov9640_regs_len = ARRAY_SIZE(ov9640_regs_sxga);
break;
default:
dev_err(&client->dev, "Failed to select resolution!\n");
return -EINVAL;
}
if (code == V4L2_MBUS_FMT_UYVY8_2X8) {
matrix_regs = ov9640_regs_yuv;
matrix_regs_len = ARRAY_SIZE(ov9640_regs_yuv);
} else {
matrix_regs = ov9640_regs_rgb;
matrix_regs_len = ARRAY_SIZE(ov9640_regs_rgb);
}
for (i = 0; i < ov9640_regs_len; i++) {
val = ov9640_regs[i].val;
switch (ov9640_regs[i].reg) {
case OV9640_COM7:
val |= alts->com7;
break;
case OV9640_COM12:
val |= alts->com12;
break;
case OV9640_COM13:
val |= alts->com13;
break;
case OV9640_COM15:
val |= alts->com15;
break;
}
ret = ov9640_reg_write(client, ov9640_regs[i].reg, val);
if (ret)
return ret;
}
for (i = 0; i < matrix_regs_len; i++) {
ret = ov9640_reg_write(client, matrix_regs[i].reg,
matrix_regs[i].val);
if (ret)
return ret;
}
return 0;
}
static int ov9640_prog_dflt(struct i2c_client *client)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(ov9640_regs_dflt); i++) {
ret = ov9640_reg_write(client, ov9640_regs_dflt[i].reg,
ov9640_regs_dflt[i].val);
if (ret)
return ret;
}
mdelay(150);
return 0;
}
static int ov9640_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov9640_reg_alt alts = {0};
enum v4l2_colorspace cspace;
enum v4l2_mbus_pixelcode code = mf->code;
int ret;
ov9640_res_roundup(&mf->width, &mf->height);
ov9640_alter_regs(mf->code, &alts);
ov9640_reset(client);
ret = ov9640_prog_dflt(client);
if (ret)
return ret;
switch (code) {
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE:
case V4L2_MBUS_FMT_RGB565_2X8_LE:
cspace = V4L2_COLORSPACE_SRGB;
break;
default:
code = V4L2_MBUS_FMT_UYVY8_2X8;
case V4L2_MBUS_FMT_UYVY8_2X8:
cspace = V4L2_COLORSPACE_JPEG;
}
ret = ov9640_write_regs(client, mf->width, code, &alts);
if (!ret) {
mf->code = code;
mf->colorspace = cspace;
}
return ret;
}
static int ov9640_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
ov9640_res_roundup(&mf->width, &mf->height);
mf->field = V4L2_FIELD_NONE;
switch (mf->code) {
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE:
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
static int ov9640_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(ov9640_codes))
return -EINVAL;
*code = ov9640_codes[index];
return 0;
}
static int ov9640_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
a->c.left = 0;
a->c.top = 0;
a->c.width = W_SXGA;
a->c.height = H_SXGA;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int ov9640_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = W_SXGA;
a->bounds.height = H_SXGA;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ov9640_video_probe(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov9640_priv *priv = to_ov9640_sensor(sd);
u8 pid, ver, midh, midl;
const char *devname;
int ret = 0;
ret = ov9640_reg_read(client, OV9640_PID, &pid);
if (!ret)
ret = ov9640_reg_read(client, OV9640_VER, &ver);
if (!ret)
ret = ov9640_reg_read(client, OV9640_MIDH, &midh);
if (!ret)
ret = ov9640_reg_read(client, OV9640_MIDL, &midl);
if (ret)
return ret;
switch (VERSION(pid, ver)) {
case OV9640_V2:
devname = "ov9640";
priv->model = V4L2_IDENT_OV9640;
priv->revision = 2;
case OV9640_V3:
devname = "ov9640";
priv->model = V4L2_IDENT_OV9640;
priv->revision = 3;
break;
default:
dev_err(&client->dev, "Product ID error %x:%x\n", pid, ver);
return -ENODEV;
}
dev_info(&client->dev, "%s Product ID %0x:%0x Manufacturer ID %x:%x\n",
devname, pid, ver, midh, midl);
return v4l2_ctrl_handler_setup(&priv->hdl);
}
static int ov9640_g_mbus_config(struct v4l2_subdev *sd,
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
static int ov9640_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov9640_priv *priv;
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
int ret;
if (!icl) {
dev_err(&client->dev, "Missing platform_data for driver\n");
return -EINVAL;
}
priv = kzalloc(sizeof(struct ov9640_priv), GFP_KERNEL);
if (!priv) {
dev_err(&client->dev,
"Failed to allocate memory for private data!\n");
return -ENOMEM;
}
v4l2_i2c_subdev_init(&priv->subdev, client, &ov9640_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 2);
v4l2_ctrl_new_std(&priv->hdl, &ov9640_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov9640_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
priv->subdev.ctrl_handler = &priv->hdl;
if (priv->hdl.error) {
int err = priv->hdl.error;
kfree(priv);
return err;
}
ret = ov9640_video_probe(client);
if (ret) {
v4l2_ctrl_handler_free(&priv->hdl);
kfree(priv);
}
return ret;
}
static int ov9640_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov9640_priv *priv = to_ov9640_sensor(sd);
v4l2_device_unregister_subdev(&priv->subdev);
v4l2_ctrl_handler_free(&priv->hdl);
kfree(priv);
return 0;
}
