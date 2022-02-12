static inline struct ov2659 *to_ov2659(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov2659, sd);
}
static int ov2659_write(struct i2c_client *client, u16 reg, u8 val)
{
struct i2c_msg msg;
u8 buf[3];
int ret;
buf[0] = reg >> 8;
buf[1] = reg & 0xFF;
buf[2] = val;
msg.addr = client->addr;
msg.flags = client->flags;
msg.buf = buf;
msg.len = sizeof(buf);
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret >= 0)
return 0;
dev_dbg(&client->dev,
"ov2659 write reg(0x%x val:0x%x) failed !\n", reg, val);
return ret;
}
static int ov2659_read(struct i2c_client *client, u16 reg, u8 *val)
{
struct i2c_msg msg[2];
u8 buf[2];
int ret;
buf[0] = reg >> 8;
buf[1] = reg & 0xFF;
msg[0].addr = client->addr;
msg[0].flags = client->flags;
msg[0].buf = buf;
msg[0].len = sizeof(buf);
msg[1].addr = client->addr;
msg[1].flags = client->flags | I2C_M_RD;
msg[1].buf = buf;
msg[1].len = 1;
ret = i2c_transfer(client->adapter, msg, 2);
if (ret >= 0) {
*val = buf[0];
return 0;
}
dev_dbg(&client->dev,
"ov2659 read reg(0x%x val:0x%x) failed !\n", reg, *val);
return ret;
}
static int ov2659_write_array(struct i2c_client *client,
const struct sensor_register *regs)
{
int i, ret = 0;
for (i = 0; ret == 0 && regs[i].addr; i++)
ret = ov2659_write(client, regs[i].addr, regs[i].value);
return ret;
}
static void ov2659_pll_calc_params(struct ov2659 *ov2659)
{
const struct ov2659_platform_data *pdata = ov2659->pdata;
u8 ctrl1_reg = 0, ctrl2_reg = 0, ctrl3_reg = 0;
struct i2c_client *client = ov2659->client;
unsigned int desired = pdata->link_frequency;
u32 s_prediv = 1, s_postdiv = 1, s_mult = 1;
u32 prediv, postdiv, mult;
u32 bestdelta = -1;
u32 delta, actual;
int i, j;
for (i = 0; ctrl1[i].div != 0; i++) {
postdiv = ctrl1[i].div;
for (j = 0; ctrl3[j].div != 0; j++) {
prediv = ctrl3[j].div;
for (mult = 1; mult <= 63; mult++) {
actual = ov2659->xvclk_frequency;
actual *= mult;
actual /= prediv;
actual /= postdiv;
delta = actual - desired;
delta = abs(delta);
if ((delta < bestdelta) || (bestdelta == -1)) {
bestdelta = delta;
s_mult = mult;
s_prediv = prediv;
s_postdiv = postdiv;
ctrl1_reg = ctrl1[i].reg;
ctrl2_reg = mult;
ctrl3_reg = ctrl3[j].reg;
}
}
}
}
ov2659->pll.ctrl1 = ctrl1_reg;
ov2659->pll.ctrl2 = ctrl2_reg;
ov2659->pll.ctrl3 = ctrl3_reg;
dev_dbg(&client->dev,
"Actual reg config: ctrl1_reg: %02x ctrl2_reg: %02x ctrl3_reg: %02x\n",
ctrl1_reg, ctrl2_reg, ctrl3_reg);
}
static int ov2659_set_pixel_clock(struct ov2659 *ov2659)
{
struct i2c_client *client = ov2659->client;
struct sensor_register pll_regs[] = {
{REG_SC_PLL_CTRL1, ov2659->pll.ctrl1},
{REG_SC_PLL_CTRL2, ov2659->pll.ctrl2},
{REG_SC_PLL_CTRL3, ov2659->pll.ctrl3},
{REG_NULL, 0x00},
};
dev_dbg(&client->dev, "%s\n", __func__);
return ov2659_write_array(client, pll_regs);
}
static void ov2659_get_default_format(struct v4l2_mbus_framefmt *format)
{
format->width = ov2659_framesizes[2].width;
format->height = ov2659_framesizes[2].height;
format->colorspace = V4L2_COLORSPACE_SRGB;
format->code = ov2659_formats[0].code;
format->field = V4L2_FIELD_NONE;
}
static void ov2659_set_streaming(struct ov2659 *ov2659, int on)
{
struct i2c_client *client = ov2659->client;
int ret;
on = !!on;
dev_dbg(&client->dev, "%s: on: %d\n", __func__, on);
ret = ov2659_write(client, REG_SOFTWARE_STANDBY, on);
if (ret)
dev_err(&client->dev, "ov2659 soft standby failed\n");
}
static int ov2659_init(struct v4l2_subdev *sd, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return ov2659_write_array(client, ov2659_init_regs);
}
static int ov2659_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
dev_dbg(&client->dev, "%s:\n", __func__);
if (code->index >= ARRAY_SIZE(ov2659_formats))
return -EINVAL;
code->code = ov2659_formats[code->index].code;
return 0;
}
static int ov2659_enum_frame_sizes(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i = ARRAY_SIZE(ov2659_formats);
dev_dbg(&client->dev, "%s:\n", __func__);
if (fse->index >= ARRAY_SIZE(ov2659_framesizes))
return -EINVAL;
while (--i)
if (fse->code == ov2659_formats[i].code)
break;
fse->code = ov2659_formats[i].code;
fse->min_width = ov2659_framesizes[fse->index].width;
fse->max_width = fse->min_width;
fse->max_height = ov2659_framesizes[fse->index].height;
fse->min_height = fse->max_height;
return 0;
}
static int ov2659_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2659 *ov2659 = to_ov2659(sd);
struct v4l2_mbus_framefmt *mf;
dev_dbg(&client->dev, "ov2659_get_fmt\n");
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
mutex_lock(&ov2659->lock);
fmt->format = *mf;
mutex_unlock(&ov2659->lock);
return 0;
}
mutex_lock(&ov2659->lock);
fmt->format = ov2659->format;
mutex_unlock(&ov2659->lock);
dev_dbg(&client->dev, "ov2659_get_fmt: %x %dx%d\n",
ov2659->format.code, ov2659->format.width,
ov2659->format.height);
return 0;
}
static void __ov2659_try_frame_size(struct v4l2_mbus_framefmt *mf,
const struct ov2659_framesize **size)
{
const struct ov2659_framesize *fsize = &ov2659_framesizes[0];
const struct ov2659_framesize *match = NULL;
int i = ARRAY_SIZE(ov2659_framesizes);
unsigned int min_err = UINT_MAX;
while (i--) {
int err = abs(fsize->width - mf->width)
+ abs(fsize->height - mf->height);
if ((err < min_err) && (fsize->regs[0].addr)) {
min_err = err;
match = fsize;
}
fsize++;
}
if (!match)
match = &ov2659_framesizes[2];
mf->width = match->width;
mf->height = match->height;
if (size)
*size = match;
}
static int ov2659_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int index = ARRAY_SIZE(ov2659_formats);
struct v4l2_mbus_framefmt *mf = &fmt->format;
const struct ov2659_framesize *size = NULL;
struct ov2659 *ov2659 = to_ov2659(sd);
int ret = 0;
dev_dbg(&client->dev, "ov2659_set_fmt\n");
__ov2659_try_frame_size(mf, &size);
while (--index >= 0)
if (ov2659_formats[index].code == mf->code)
break;
if (index < 0)
return -EINVAL;
mf->colorspace = V4L2_COLORSPACE_SRGB;
mf->code = ov2659_formats[index].code;
mf->field = V4L2_FIELD_NONE;
mutex_lock(&ov2659->lock);
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
*mf = fmt->format;
} else {
s64 val;
if (ov2659->streaming) {
mutex_unlock(&ov2659->lock);
return -EBUSY;
}
ov2659->frame_size = size;
ov2659->format = fmt->format;
ov2659->format_ctrl_regs =
ov2659_formats[index].format_ctrl_regs;
if (ov2659->format.code != MEDIA_BUS_FMT_SBGGR8_1X8)
val = ov2659->pdata->link_frequency / 2;
else
val = ov2659->pdata->link_frequency;
ret = v4l2_ctrl_s_ctrl_int64(ov2659->link_frequency, val);
if (ret < 0)
dev_warn(&client->dev,
"failed to set link_frequency rate (%d)\n",
ret);
}
mutex_unlock(&ov2659->lock);
return ret;
}
static int ov2659_set_frame_size(struct ov2659 *ov2659)
{
struct i2c_client *client = ov2659->client;
dev_dbg(&client->dev, "%s\n", __func__);
return ov2659_write_array(ov2659->client, ov2659->frame_size->regs);
}
static int ov2659_set_format(struct ov2659 *ov2659)
{
struct i2c_client *client = ov2659->client;
dev_dbg(&client->dev, "%s\n", __func__);
return ov2659_write_array(ov2659->client, ov2659->format_ctrl_regs);
}
static int ov2659_s_stream(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov2659 *ov2659 = to_ov2659(sd);
int ret = 0;
dev_dbg(&client->dev, "%s: on: %d\n", __func__, on);
mutex_lock(&ov2659->lock);
on = !!on;
if (ov2659->streaming == on)
goto unlock;
if (!on) {
ov2659_set_streaming(ov2659, 0);
ov2659->streaming = on;
goto unlock;
}
ov2659_set_pixel_clock(ov2659);
ov2659_set_frame_size(ov2659);
ov2659_set_format(ov2659);
ov2659_set_streaming(ov2659, 1);
ov2659->streaming = on;
unlock:
mutex_unlock(&ov2659->lock);
return ret;
}
static int ov2659_set_test_pattern(struct ov2659 *ov2659, int value)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov2659->sd);
int ret;
u8 val;
ret = ov2659_read(client, REG_PRE_ISP_CTRL00, &val);
if (ret < 0)
return ret;
switch (value) {
case 0:
val &= ~TEST_PATTERN_ENABLE;
break;
case 1:
val &= VERTICAL_COLOR_BAR_MASK;
val |= TEST_PATTERN_ENABLE;
break;
}
return ov2659_write(client, REG_PRE_ISP_CTRL00, val);
}
static int ov2659_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov2659 *ov2659 =
container_of(ctrl->handler, struct ov2659, ctrls);
switch (ctrl->id) {
case V4L2_CID_TEST_PATTERN:
return ov2659_set_test_pattern(ov2659, ctrl->val);
}
return 0;
}
static int ov2659_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format =
v4l2_subdev_get_try_format(sd, fh->pad, 0);
dev_dbg(&client->dev, "%s:\n", __func__);
ov2659_get_default_format(format);
return 0;
}
static int ov2659_detect(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 pid, ver;
int ret;
dev_dbg(&client->dev, "%s:\n", __func__);
ret = ov2659_write(client, REG_SOFTWARE_RESET, 0x01);
if (ret != 0) {
dev_err(&client->dev, "Sensor soft reset failed\n");
return -ENODEV;
}
usleep_range(1000, 2000);
ret = ov2659_init(sd, 0);
if (ret < 0)
return ret;
ret = ov2659_read(client, REG_SC_CHIP_ID_H, &pid);
if (!ret)
ret = ov2659_read(client, REG_SC_CHIP_ID_L, &ver);
if (!ret) {
unsigned short id;
id = OV265X_ID(pid, ver);
if (id != OV2659_ID)
dev_err(&client->dev,
"Sensor detection failed (%04X, %d)\n",
id, ret);
else
dev_info(&client->dev, "Found OV%04X sensor\n", id);
}
return ret;
}
static struct ov2659_platform_data *
ov2659_get_pdata(struct i2c_client *client)
{
struct ov2659_platform_data *pdata;
struct device_node *endpoint;
int ret;
if (!IS_ENABLED(CONFIG_OF) || !client->dev.of_node)
return client->dev.platform_data;
endpoint = of_graph_get_next_endpoint(client->dev.of_node, NULL);
if (!endpoint)
return NULL;
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
goto done;
ret = of_property_read_u64(endpoint, "link-frequencies",
&pdata->link_frequency);
if (ret) {
dev_err(&client->dev, "link-frequencies property not found\n");
pdata = NULL;
}
done:
of_node_put(endpoint);
return pdata;
}
static int ov2659_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct ov2659_platform_data *pdata = ov2659_get_pdata(client);
struct v4l2_subdev *sd;
struct ov2659 *ov2659;
struct clk *clk;
int ret;
if (!pdata) {
dev_err(&client->dev, "platform data not specified\n");
return -EINVAL;
}
ov2659 = devm_kzalloc(&client->dev, sizeof(*ov2659), GFP_KERNEL);
if (!ov2659)
return -ENOMEM;
ov2659->pdata = pdata;
ov2659->client = client;
clk = devm_clk_get(&client->dev, "xvclk");
if (IS_ERR(clk))
return PTR_ERR(clk);
ov2659->xvclk_frequency = clk_get_rate(clk);
if (ov2659->xvclk_frequency < 6000000 ||
ov2659->xvclk_frequency > 27000000)
return -EINVAL;
v4l2_ctrl_handler_init(&ov2659->ctrls, 2);
ov2659->link_frequency =
v4l2_ctrl_new_std(&ov2659->ctrls, &ov2659_ctrl_ops,
V4L2_CID_PIXEL_RATE,
pdata->link_frequency / 2,
pdata->link_frequency, 1,
pdata->link_frequency);
v4l2_ctrl_new_std_menu_items(&ov2659->ctrls, &ov2659_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(ov2659_test_pattern_menu) - 1,
0, 0, ov2659_test_pattern_menu);
ov2659->sd.ctrl_handler = &ov2659->ctrls;
if (ov2659->ctrls.error) {
dev_err(&client->dev, "%s: control initialization error %d\n",
__func__, ov2659->ctrls.error);
return ov2659->ctrls.error;
}
sd = &ov2659->sd;
client->flags |= I2C_CLIENT_SCCB;
v4l2_i2c_subdev_init(sd, client, &ov2659_subdev_ops);
sd->internal_ops = &ov2659_subdev_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE |
V4L2_SUBDEV_FL_HAS_EVENTS;
#if defined(CONFIG_MEDIA_CONTROLLER)
ov2659->pad.flags = MEDIA_PAD_FL_SOURCE;
sd->entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
ret = media_entity_init(&sd->entity, 1, &ov2659->pad, 0);
if (ret < 0) {
v4l2_ctrl_handler_free(&ov2659->ctrls);
return ret;
}
#endif
mutex_init(&ov2659->lock);
ov2659_get_default_format(&ov2659->format);
ov2659->frame_size = &ov2659_framesizes[2];
ov2659->format_ctrl_regs = ov2659_formats[0].format_ctrl_regs;
ret = ov2659_detect(sd);
if (ret < 0)
goto error;
ov2659_pll_calc_params(ov2659);
ret = v4l2_async_register_subdev(&ov2659->sd);
if (ret)
goto error;
dev_info(&client->dev, "%s sensor driver registered !!\n", sd->name);
return 0;
error:
v4l2_ctrl_handler_free(&ov2659->ctrls);
#if defined(CONFIG_MEDIA_CONTROLLER)
media_entity_cleanup(&sd->entity);
#endif
mutex_destroy(&ov2659->lock);
return ret;
}
static int ov2659_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov2659 *ov2659 = to_ov2659(sd);
v4l2_ctrl_handler_free(&ov2659->ctrls);
v4l2_async_unregister_subdev(sd);
#if defined(CONFIG_MEDIA_CONTROLLER)
media_entity_cleanup(&sd->entity);
#endif
mutex_destroy(&ov2659->lock);
return 0;
}
