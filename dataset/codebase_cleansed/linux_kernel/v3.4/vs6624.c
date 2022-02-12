static inline struct vs6624 *to_vs6624(struct v4l2_subdev *sd)
{
return container_of(sd, struct vs6624, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct vs6624, hdl)->sd;
}
static int vs6624_read(struct v4l2_subdev *sd, u16 index)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[2];
buf[0] = index >> 8;
buf[1] = index;
i2c_master_send(client, buf, 2);
i2c_master_recv(client, buf, 1);
return buf[0];
}
static int vs6624_write(struct v4l2_subdev *sd, u16 index,
u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[3];
buf[0] = index >> 8;
buf[1] = index;
buf[2] = value;
return i2c_master_send(client, buf, 3);
}
static int vs6624_writeregs(struct v4l2_subdev *sd, const u16 *regs)
{
u16 reg;
u8 data;
while (*regs != 0x00) {
reg = *regs++;
data = *regs++;
vs6624_write(sd, reg, data);
}
return 0;
}
static int vs6624_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_CONTRAST:
vs6624_write(sd, VS6624_CONTRAST0, ctrl->val);
break;
case V4L2_CID_SATURATION:
vs6624_write(sd, VS6624_SATURATION0, ctrl->val);
break;
case V4L2_CID_HFLIP:
vs6624_write(sd, VS6624_HMIRROR0, ctrl->val);
break;
case V4L2_CID_VFLIP:
vs6624_write(sd, VS6624_VFLIP0, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int vs6624_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(vs6624_formats))
return -EINVAL;
*code = vs6624_formats[index].mbus_code;
return 0;
}
static int vs6624_try_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
int index;
for (index = 0; index < ARRAY_SIZE(vs6624_formats); index++)
if (vs6624_formats[index].mbus_code == fmt->code)
break;
if (index >= ARRAY_SIZE(vs6624_formats)) {
index = 0;
fmt->code = vs6624_formats[0].mbus_code;
}
if (fmt->width > VGA_WIDTH)
fmt->width = VGA_WIDTH;
if (fmt->height > VGA_HEIGHT)
fmt->height = VGA_HEIGHT;
fmt->width = fmt->width & (~3);
fmt->height = fmt->height & (~3);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = vs6624_formats[index].colorspace;
return 0;
}
static int vs6624_s_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct vs6624 *sensor = to_vs6624(sd);
int ret;
ret = vs6624_try_mbus_fmt(sd, fmt);
if (ret)
return ret;
switch (fmt->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
vs6624_write(sd, VS6624_IMG_FMT0, 0x0);
vs6624_write(sd, VS6624_YUV_SETUP, 0x1);
break;
case V4L2_MBUS_FMT_YUYV8_2X8:
vs6624_write(sd, VS6624_IMG_FMT0, 0x0);
vs6624_write(sd, VS6624_YUV_SETUP, 0x3);
break;
case V4L2_MBUS_FMT_RGB565_2X8_LE:
vs6624_write(sd, VS6624_IMG_FMT0, 0x4);
vs6624_write(sd, VS6624_RGB_SETUP, 0x0);
break;
default:
return -EINVAL;
}
if ((fmt->width == VGA_WIDTH) && (fmt->height == VGA_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x2);
else if ((fmt->width == QVGA_WIDTH) && (fmt->height == QVGA_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x4);
else if ((fmt->width == QQVGA_WIDTH) && (fmt->height == QQVGA_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x6);
else if ((fmt->width == CIF_WIDTH) && (fmt->height == CIF_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x3);
else if ((fmt->width == QCIF_WIDTH) && (fmt->height == QCIF_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x5);
else if ((fmt->width == QQCIF_WIDTH) && (fmt->height == QQCIF_HEIGHT))
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x7);
else {
vs6624_write(sd, VS6624_IMAGE_SIZE0, 0x8);
vs6624_write(sd, VS6624_MAN_HSIZE0_MSB, fmt->width >> 8);
vs6624_write(sd, VS6624_MAN_HSIZE0_LSB, fmt->width & 0xFF);
vs6624_write(sd, VS6624_MAN_VSIZE0_MSB, fmt->height >> 8);
vs6624_write(sd, VS6624_MAN_VSIZE0_LSB, fmt->height & 0xFF);
vs6624_write(sd, VS6624_CROP_CTRL0, 0x1);
}
sensor->fmt = *fmt;
return 0;
}
static int vs6624_g_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct vs6624 *sensor = to_vs6624(sd);
*fmt = sensor->fmt;
return 0;
}
static int vs6624_g_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct vs6624 *sensor = to_vs6624(sd);
struct v4l2_captureparm *cp = &parms->parm.capture;
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
memset(cp, 0, sizeof(*cp));
cp->capability = V4L2_CAP_TIMEPERFRAME;
cp->timeperframe.numerator = sensor->frame_rate.denominator;
cp->timeperframe.denominator = sensor->frame_rate.numerator;
return 0;
}
static int vs6624_s_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct vs6624 *sensor = to_vs6624(sd);
struct v4l2_captureparm *cp = &parms->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (cp->extendedmode != 0)
return -EINVAL;
if (tpf->numerator == 0 || tpf->denominator == 0
|| (tpf->denominator > tpf->numerator * MAX_FRAME_RATE)) {
tpf->numerator = 1;
tpf->denominator = MAX_FRAME_RATE;
}
sensor->frame_rate.numerator = tpf->denominator;
sensor->frame_rate.denominator = tpf->numerator;
vs6624_write(sd, VS6624_DISABLE_FR_DAMPER, 0x0);
vs6624_write(sd, VS6624_FR_NUM_MSB,
sensor->frame_rate.numerator >> 8);
vs6624_write(sd, VS6624_FR_NUM_LSB,
sensor->frame_rate.numerator & 0xFF);
vs6624_write(sd, VS6624_FR_DEN,
sensor->frame_rate.denominator & 0xFF);
return 0;
}
static int vs6624_s_stream(struct v4l2_subdev *sd, int enable)
{
if (enable)
vs6624_write(sd, VS6624_USER_CMD, 0x2);
else
vs6624_write(sd, VS6624_USER_CMD, 0x4);
udelay(100);
return 0;
}
static int vs6624_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
int rev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
rev = (vs6624_read(sd, VS6624_FW_VSN_MAJOR) << 8)
| vs6624_read(sd, VS6624_FW_VSN_MINOR);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_VS6624, rev);
}
static int vs6624_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = vs6624_read(sd, reg->reg & 0xffff);
reg->size = 1;
return 0;
}
static int vs6624_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
vs6624_write(sd, reg->reg & 0xffff, reg->val & 0xff);
return 0;
}
static int __devinit vs6624_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct vs6624 *sensor;
struct v4l2_subdev *sd;
struct v4l2_ctrl_handler *hdl;
const unsigned *ce;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -EIO;
ce = client->dev.platform_data;
if (ce == NULL)
return -EINVAL;
ret = gpio_request(*ce, "VS6624 Chip Enable");
if (ret) {
v4l_err(client, "failed to request GPIO %d\n", *ce);
return ret;
}
gpio_direction_output(*ce, 1);
mdelay(100);
sensor = kzalloc(sizeof(*sensor), GFP_KERNEL);
if (sensor == NULL) {
gpio_free(*ce);
return -ENOMEM;
}
sd = &sensor->sd;
v4l2_i2c_subdev_init(sd, client, &vs6624_ops);
vs6624_writeregs(sd, vs6624_p1);
vs6624_write(sd, VS6624_MICRO_EN, 0x2);
vs6624_write(sd, VS6624_DIO_EN, 0x1);
mdelay(10);
vs6624_writeregs(sd, vs6624_p2);
vs6624_writeregs(sd, vs6624_default);
vs6624_write(sd, VS6624_HSYNC_SETUP, 0xF);
vs6624_writeregs(sd, vs6624_run_setup);
sensor->frame_rate.numerator = MAX_FRAME_RATE;
sensor->frame_rate.denominator = 1;
vs6624_write(sd, VS6624_DISABLE_FR_DAMPER, 0x0);
vs6624_write(sd, VS6624_FR_NUM_MSB,
sensor->frame_rate.numerator >> 8);
vs6624_write(sd, VS6624_FR_NUM_LSB,
sensor->frame_rate.numerator & 0xFF);
vs6624_write(sd, VS6624_FR_DEN,
sensor->frame_rate.denominator & 0xFF);
sensor->fmt = vs6624_default_fmt;
sensor->ce_pin = *ce;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
hdl = &sensor->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &vs6624_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0xFF, 1, 0x87);
v4l2_ctrl_new_std(hdl, &vs6624_ctrl_ops,
V4L2_CID_SATURATION, 0, 0xFF, 1, 0x78);
v4l2_ctrl_new_std(hdl, &vs6624_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(hdl, &vs6624_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
kfree(sensor);
gpio_free(*ce);
return err;
}
ret = v4l2_ctrl_handler_setup(hdl);
if (ret) {
v4l2_ctrl_handler_free(hdl);
kfree(sensor);
gpio_free(*ce);
}
return ret;
}
static int __devexit vs6624_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct vs6624 *sensor = to_vs6624(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
gpio_free(sensor->ce_pin);
kfree(sensor);
return 0;
}
static __init int vs6624_init(void)
{
return i2c_add_driver(&vs6624_driver);
}
static __exit void vs6624_exit(void)
{
i2c_del_driver(&vs6624_driver);
}
