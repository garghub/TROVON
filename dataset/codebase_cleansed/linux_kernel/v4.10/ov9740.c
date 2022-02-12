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
bool scaling = false;
u32 scale_input_x;
u32 scale_input_y;
int ret;
if ((width != OV9740_MAX_WIDTH) || (height != OV9740_MAX_HEIGHT))
scaling = true;
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
u32 code = mf->code;
int ret;
ov9740_res_roundup(&mf->width, &mf->height);
switch (code) {
case MEDIA_BUS_FMT_YUYV8_2X8:
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
static int ov9740_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
if (format->pad)
return -EINVAL;
ov9740_res_roundup(&mf->width, &mf->height);
mf->field = V4L2_FIELD_NONE;
mf->code = MEDIA_BUS_FMT_YUYV8_2X8;
mf->colorspace = V4L2_COLORSPACE_SRGB;
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return ov9740_s_fmt(sd, mf);
cfg->try_fmt = *mf;
return 0;
}
static int ov9740_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= ARRAY_SIZE(ov9740_codes))
return -EINVAL;
code->code = ov9740_codes[code->index];
return 0;
}
static int ov9740_get_selection(struct v4l2_subdev *sd,
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
sel->r.width = OV9740_MAX_WIDTH;
sel->r.height = OV9740_MAX_HEIGHT;
return 0;
default:
return -EINVAL;
}
}
static int ov9740_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov9740_priv *priv =
container_of(ctrl->handler, struct ov9740_priv, hdl);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
priv->flag_vflip = ctrl->val;
break;
case V4L2_CID_HFLIP:
priv->flag_hflip = ctrl->val;
break;
default:
return -EINVAL;
}
return 0;
}
static int ov9740_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct ov9740_priv *priv = to_ov9740(sd);
int ret;
if (on) {
ret = soc_camera_power_on(&client->dev, ssdd, priv->clk);
if (ret < 0)
return ret;
if (priv->current_enable) {
ov9740_s_fmt(sd, &priv->current_mf);
ov9740_s_stream(sd, 1);
}
} else {
if (priv->current_enable) {
ov9740_s_stream(sd, 0);
priv->current_enable = true;
}
soc_camera_power_off(&client->dev, ssdd, priv->clk);
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
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg & ~0xffff || reg->val & ~0xff)
return -EINVAL;
return ov9740_reg_write(client, reg->reg, reg->val);
}
static int ov9740_video_probe(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov9740_priv *priv = to_ov9740(sd);
u8 modelhi, modello;
int ret;
ret = ov9740_s_power(&priv->subdev, 1);
if (ret < 0)
return ret;
ret = ov9740_reg_read(client, OV9740_MODEL_ID_HI, &modelhi);
if (ret < 0)
goto done;
ret = ov9740_reg_read(client, OV9740_MODEL_ID_LO, &modello);
if (ret < 0)
goto done;
priv->model = (modelhi << 8) | modello;
ret = ov9740_reg_read(client, OV9740_REVISION_NUMBER, &priv->revision);
if (ret < 0)
goto done;
ret = ov9740_reg_read(client, OV9740_MANUFACTURER_ID, &priv->manid);
if (ret < 0)
goto done;
ret = ov9740_reg_read(client, OV9740_SMIA_VERSION, &priv->smiaver);
if (ret < 0)
goto done;
if (priv->model != 0x9740) {
ret = -ENODEV;
goto done;
}
dev_info(&client->dev, "ov9740 Model ID 0x%04x, Revision 0x%02x, Manufacturer 0x%02x, SMIA Version 0x%02x\n",
priv->model, priv->revision, priv->manid, priv->smiaver);
ret = v4l2_ctrl_handler_setup(&priv->hdl);
done:
ov9740_s_power(&priv->subdev, 0);
return ret;
}
static int ov9740_g_mbus_config(struct v4l2_subdev *sd,
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
static int ov9740_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov9740_priv *priv;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
int ret;
if (!ssdd) {
dev_err(&client->dev, "Missing platform_data for driver\n");
return -EINVAL;
}
priv = devm_kzalloc(&client->dev, sizeof(struct ov9740_priv), GFP_KERNEL);
if (!priv) {
dev_err(&client->dev, "Failed to allocate private data!\n");
return -ENOMEM;
}
v4l2_i2c_subdev_init(&priv->subdev, client, &ov9740_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 13);
v4l2_ctrl_new_std(&priv->hdl, &ov9740_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ov9740_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
priv->subdev.ctrl_handler = &priv->hdl;
if (priv->hdl.error)
return priv->hdl.error;
priv->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
goto eclkget;
}
ret = ov9740_video_probe(client);
if (ret < 0) {
v4l2_clk_put(priv->clk);
eclkget:
v4l2_ctrl_handler_free(&priv->hdl);
}
return ret;
}
static int ov9740_remove(struct i2c_client *client)
{
struct ov9740_priv *priv = i2c_get_clientdata(client);
v4l2_clk_put(priv->clk);
v4l2_device_unregister_subdev(&priv->subdev);
v4l2_ctrl_handler_free(&priv->hdl);
return 0;
}
