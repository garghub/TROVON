static struct ov5642 *to_ov5642(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct ov5642, subdev);
}
static const struct ov5642_datafmt
*ov5642_find_datafmt(enum v4l2_mbus_pixelcode code)
{
int i;
for (i = 0; i < ARRAY_SIZE(ov5642_colour_fmts); i++)
if (ov5642_colour_fmts[i].code == code)
return ov5642_colour_fmts + i;
return NULL;
}
static int reg_read(struct i2c_client *client, u16 reg, u8 *val)
{
int ret;
unsigned char data[2] = { reg >> 8, reg & 0xff };
ret = i2c_master_send(client, data, 2);
if (ret < 2) {
dev_err(&client->dev, "%s: i2c read error, reg: %x\n",
__func__, reg);
return ret < 0 ? ret : -EIO;
}
ret = i2c_master_recv(client, val, 1);
if (ret < 1) {
dev_err(&client->dev, "%s: i2c read error, reg: %x\n",
__func__, reg);
return ret < 0 ? ret : -EIO;
}
return 0;
}
static int reg_write(struct i2c_client *client, u16 reg, u8 val)
{
int ret;
unsigned char data[3] = { reg >> 8, reg & 0xff, val };
ret = i2c_master_send(client, data, 3);
if (ret < 3) {
dev_err(&client->dev, "%s: i2c write error, reg: %x\n",
__func__, reg);
return ret < 0 ? ret : -EIO;
}
return 0;
}
static int reg_write16(struct i2c_client *client, u16 reg, u16 val16)
{
int ret;
ret = reg_write(client, reg, val16 >> 8);
if (ret)
return ret;
return reg_write(client, reg + 1, val16 & 0x00ff);
}
static int ov5642_get_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
u8 val;
if (reg->reg & ~0xffff)
return -EINVAL;
reg->size = 1;
ret = reg_read(client, reg->reg, &val);
if (!ret)
reg->val = (__u64)val;
return ret;
}
static int ov5642_set_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg & ~0xffff || reg->val & ~0xff)
return -EINVAL;
return reg_write(client, reg->reg, reg->val);
}
static int ov5642_write_array(struct i2c_client *client,
struct regval_list *vals)
{
while (vals->reg_num != 0xffff || vals->value != 0xff) {
int ret = reg_write(client, vals->reg_num, vals->value);
if (ret < 0)
return ret;
vals++;
}
dev_dbg(&client->dev, "Register list loaded\n");
return 0;
}
static int ov5642_set_resolution(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
int width = priv->crop_rect.width;
int height = priv->crop_rect.height;
int total_width = priv->total_width;
int total_height = priv->total_height;
int start_x = (OV5642_SENSOR_SIZE_X - width) / 2;
int start_y = (OV5642_SENSOR_SIZE_Y - height) / 2;
int ret;
ret = reg_write16(client, REG_WINDOW_START_X_HIGH, start_x);
if (!ret)
ret = reg_write16(client, REG_WINDOW_START_Y_HIGH, start_y);
if (!ret) {
priv->crop_rect.left = start_x;
priv->crop_rect.top = start_y;
}
if (!ret)
ret = reg_write16(client, REG_WINDOW_WIDTH_HIGH, width);
if (!ret)
ret = reg_write16(client, REG_WINDOW_HEIGHT_HIGH, height);
if (ret)
return ret;
priv->crop_rect.width = width;
priv->crop_rect.height = height;
ret = reg_write16(client, REG_OUT_WIDTH_HIGH, width);
if (!ret)
ret = reg_write16(client, REG_OUT_HEIGHT_HIGH, height);
if (!ret)
ret = reg_write16(client, REG_OUT_TOTAL_WIDTH_HIGH, total_width);
if (!ret)
ret = reg_write16(client, REG_OUT_TOTAL_HEIGHT_HIGH, total_height);
if (!ret)
ret = reg_write16(client, REG_AVG_WINDOW_END_X_HIGH, width);
if (!ret)
ret = reg_write16(client, REG_AVG_WINDOW_END_Y_HIGH, height);
return ret;
}
static int ov5642_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
const struct ov5642_datafmt *fmt = ov5642_find_datafmt(mf->code);
mf->width = priv->crop_rect.width;
mf->height = priv->crop_rect.height;
if (!fmt) {
mf->code = ov5642_colour_fmts[0].code;
mf->colorspace = ov5642_colour_fmts[0].colorspace;
}
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov5642_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
if (!ov5642_find_datafmt(mf->code))
return -EINVAL;
ov5642_try_fmt(sd, mf);
priv->fmt = ov5642_find_datafmt(mf->code);
return 0;
}
static int ov5642_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
const struct ov5642_datafmt *fmt = priv->fmt;
mf->code = fmt->code;
mf->colorspace = fmt->colorspace;
mf->width = priv->crop_rect.width;
mf->height = priv->crop_rect.height;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov5642_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(ov5642_colour_fmts))
return -EINVAL;
*code = ov5642_colour_fmts[index].code;
return 0;
}
static int ov5642_s_crop(struct v4l2_subdev *sd, const struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
struct v4l2_rect rect = a->c;
int ret;
v4l_bound_align_image(&rect.width, 48, OV5642_MAX_WIDTH, 1,
&rect.height, 32, OV5642_MAX_HEIGHT, 1, 0);
priv->crop_rect.width = rect.width;
priv->crop_rect.height = rect.height;
priv->total_width = rect.width + BLANKING_EXTRA_WIDTH;
priv->total_height = max_t(int, rect.height +
BLANKING_EXTRA_HEIGHT,
BLANKING_MIN_HEIGHT);
priv->crop_rect.width = rect.width;
priv->crop_rect.height = rect.height;
ret = ov5642_write_array(client, ov5642_default_regs_init);
if (!ret)
ret = ov5642_set_resolution(sd);
if (!ret)
ret = ov5642_write_array(client, ov5642_default_regs_finalise);
return ret;
}
static int ov5642_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
struct v4l2_rect *rect = &a->c;
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
*rect = priv->crop_rect;
return 0;
}
static int ov5642_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = OV5642_MAX_WIDTH;
a->bounds.height = OV5642_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int ov5642_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->type = V4L2_MBUS_CSI2;
cfg->flags = V4L2_MBUS_CSI2_2_LANE | V4L2_MBUS_CSI2_CHANNEL_0 |
V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
return 0;
}
static int ov5642_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct ov5642 *priv = to_ov5642(client);
int ret;
if (!on)
return soc_camera_power_off(&client->dev, ssdd, priv->clk);
ret = soc_camera_power_on(&client->dev, ssdd, priv->clk);
if (ret < 0)
return ret;
ret = ov5642_write_array(client, ov5642_default_regs_init);
if (!ret)
ret = ov5642_set_resolution(sd);
if (!ret)
ret = ov5642_write_array(client, ov5642_default_regs_finalise);
return ret;
}
static int ov5642_video_probe(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
int ret;
u8 id_high, id_low;
u16 id;
ret = ov5642_s_power(subdev, 1);
if (ret < 0)
return ret;
ret = reg_read(client, REG_CHIP_ID_HIGH, &id_high);
if (ret < 0)
goto done;
id = id_high << 8;
ret = reg_read(client, REG_CHIP_ID_LOW, &id_low);
if (ret < 0)
goto done;
id |= id_low;
dev_info(&client->dev, "Chip ID 0x%04x detected\n", id);
if (id != 0x5642) {
ret = -ENODEV;
goto done;
}
ret = 0;
done:
ov5642_s_power(subdev, 0);
return ret;
}
static int ov5642_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov5642 *priv;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
int ret;
if (!ssdd) {
dev_err(&client->dev, "OV5642: missing platform data!\n");
return -EINVAL;
}
priv = devm_kzalloc(&client->dev, sizeof(struct ov5642), GFP_KERNEL);
if (!priv)
return -ENOMEM;
v4l2_i2c_subdev_init(&priv->subdev, client, &ov5642_subdev_ops);
priv->fmt = &ov5642_colour_fmts[0];
priv->crop_rect.width = OV5642_DEFAULT_WIDTH;
priv->crop_rect.height = OV5642_DEFAULT_HEIGHT;
priv->crop_rect.left = (OV5642_MAX_WIDTH - OV5642_DEFAULT_WIDTH) / 2;
priv->crop_rect.top = (OV5642_MAX_HEIGHT - OV5642_DEFAULT_HEIGHT) / 2;
priv->total_width = OV5642_DEFAULT_WIDTH + BLANKING_EXTRA_WIDTH;
priv->total_height = BLANKING_MIN_HEIGHT;
priv->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
ret = ov5642_video_probe(client);
if (ret < 0)
v4l2_clk_put(priv->clk);
return ret;
}
static int ov5642_remove(struct i2c_client *client)
{
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct ov5642 *priv = to_ov5642(client);
v4l2_clk_put(priv->clk);
if (ssdd->free_bus)
ssdd->free_bus(ssdd);
return 0;
}
