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
static int ov5642_set_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
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
static int ov5642_set_resolution(struct i2c_client *client)
{
int ret;
u8 start_x_high = ((OV5642_SENSOR_SIZE_X - OV5642_WIDTH) / 2) >> 8;
u8 start_x_low = ((OV5642_SENSOR_SIZE_X - OV5642_WIDTH) / 2) & 0xff;
u8 start_y_high = ((OV5642_SENSOR_SIZE_Y - OV5642_HEIGHT) / 2) >> 8;
u8 start_y_low = ((OV5642_SENSOR_SIZE_Y - OV5642_HEIGHT) / 2) & 0xff;
u8 width_high = OV5642_WIDTH >> 8;
u8 width_low = OV5642_WIDTH & 0xff;
u8 height_high = OV5642_HEIGHT >> 8;
u8 height_low = OV5642_HEIGHT & 0xff;
u8 total_width_high = OV5642_TOTAL_WIDTH >> 8;
u8 total_width_low = OV5642_TOTAL_WIDTH & 0xff;
u8 total_height_high = OV5642_TOTAL_HEIGHT >> 8;
u8 total_height_low = OV5642_TOTAL_HEIGHT & 0xff;
ret = reg_write(client, REG_WINDOW_START_X_HIGH, start_x_high);
if (!ret)
ret = reg_write(client, REG_WINDOW_START_X_LOW, start_x_low);
if (!ret)
ret = reg_write(client, REG_WINDOW_START_Y_HIGH, start_y_high);
if (!ret)
ret = reg_write(client, REG_WINDOW_START_Y_LOW, start_y_low);
if (!ret)
ret = reg_write(client, REG_WINDOW_WIDTH_HIGH, width_high);
if (!ret)
ret = reg_write(client, REG_WINDOW_WIDTH_LOW , width_low);
if (!ret)
ret = reg_write(client, REG_WINDOW_HEIGHT_HIGH, height_high);
if (!ret)
ret = reg_write(client, REG_WINDOW_HEIGHT_LOW, height_low);
if (!ret)
ret = reg_write(client, REG_OUT_WIDTH_HIGH, width_high);
if (!ret)
ret = reg_write(client, REG_OUT_WIDTH_LOW , width_low);
if (!ret)
ret = reg_write(client, REG_OUT_HEIGHT_HIGH, height_high);
if (!ret)
ret = reg_write(client, REG_OUT_HEIGHT_LOW, height_low);
if (!ret)
ret = reg_write(client, REG_OUT_TOTAL_WIDTH_HIGH, total_width_high);
if (!ret)
ret = reg_write(client, REG_OUT_TOTAL_WIDTH_LOW, total_width_low);
if (!ret)
ret = reg_write(client, REG_OUT_TOTAL_HEIGHT_HIGH, total_height_high);
if (!ret)
ret = reg_write(client, REG_OUT_TOTAL_HEIGHT_LOW, total_height_low);
return ret;
}
static int ov5642_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
const struct ov5642_datafmt *fmt = ov5642_find_datafmt(mf->code);
dev_dbg(sd->v4l2_dev->dev, "%s(%u) width: %u heigth: %u\n",
__func__, mf->code, mf->width, mf->height);
if (!fmt) {
mf->code = ov5642_colour_fmts[0].code;
mf->colorspace = ov5642_colour_fmts[0].colorspace;
}
mf->width = OV5642_WIDTH;
mf->height = OV5642_HEIGHT;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int ov5642_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov5642 *priv = to_ov5642(client);
dev_dbg(sd->v4l2_dev->dev, "%s(%u)\n", __func__, mf->code);
if (!ov5642_find_datafmt(mf->code))
return -EINVAL;
ov5642_try_fmt(sd, mf);
priv->fmt = ov5642_find_datafmt(mf->code);
ov5642_write_array(client, ov5642_default_regs_init);
ov5642_set_resolution(client);
ov5642_write_array(client, ov5642_default_regs_finalise);
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
mf->width = OV5642_WIDTH;
mf->height = OV5642_HEIGHT;
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
static int ov5642_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = V4L2_IDENT_OV5642;
id->revision = 0;
return 0;
}
static int ov5642_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct v4l2_rect *rect = &a->c;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
rect->top = 0;
rect->left = 0;
rect->width = OV5642_WIDTH;
rect->height = OV5642_HEIGHT;
return 0;
}
static int ov5642_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = OV5642_WIDTH;
a->bounds.height = OV5642_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static unsigned long soc_ov5642_query_bus_param(struct soc_camera_device *icd)
{
return 0;
}
static int soc_ov5642_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
return -EINVAL;
}
static int ov5642_video_probe(struct soc_camera_device *icd,
struct i2c_client *client)
{
int ret;
u8 id_high, id_low;
u16 id;
ret = reg_read(client, REG_CHIP_ID_HIGH, &id_high);
if (ret < 0)
return ret;
id = id_high << 8;
ret = reg_read(client, REG_CHIP_ID_LOW, &id_low);
if (ret < 0)
return ret;
id |= id_low;
dev_info(&client->dev, "Chip ID 0x%04x detected\n", id);
if (id != 0x5642)
return -ENODEV;
return 0;
}
static int ov5642_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ov5642 *priv;
struct soc_camera_device *icd = client->dev.platform_data;
struct soc_camera_link *icl;
int ret;
if (!icd) {
dev_err(&client->dev, "OV5642: missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&client->dev, "OV5642: missing platform data!\n");
return -EINVAL;
}
priv = kzalloc(sizeof(struct ov5642), GFP_KERNEL);
if (!priv)
return -ENOMEM;
v4l2_i2c_subdev_init(&priv->subdev, client, &ov5642_subdev_ops);
icd->ops = &soc_ov5642_ops;
priv->fmt = &ov5642_colour_fmts[0];
ret = ov5642_video_probe(icd, client);
if (ret < 0)
goto error;
return 0;
error:
icd->ops = NULL;
kfree(priv);
return ret;
}
static int ov5642_remove(struct i2c_client *client)
{
struct ov5642 *priv = to_ov5642(client);
struct soc_camera_device *icd = client->dev.platform_data;
struct soc_camera_link *icl = to_soc_camera_link(icd);
icd->ops = NULL;
if (icl->free_bus)
icl->free_bus(icl);
kfree(priv);
return 0;
}
static int __init ov5642_mod_init(void)
{
return i2c_add_driver(&ov5642_i2c_driver);
}
static void __exit ov5642_mod_exit(void)
{
i2c_del_driver(&ov5642_i2c_driver);
}
