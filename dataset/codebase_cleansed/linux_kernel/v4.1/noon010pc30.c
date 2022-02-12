static inline struct noon010_info *to_noon010(struct v4l2_subdev *sd)
{
return container_of(sd, struct noon010_info, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct noon010_info, hdl)->sd;
}
static inline int set_i2c_page(struct noon010_info *info,
struct i2c_client *client, unsigned int reg)
{
u32 page = reg >> 8 & 0xFF;
int ret = 0;
if (info->i2c_reg_page != page && (reg & 0xFF) != 0x03) {
ret = i2c_smbus_write_byte_data(client, PAGEMODE_REG, page);
if (!ret)
info->i2c_reg_page = page;
}
return ret;
}
static int cam_i2c_read(struct v4l2_subdev *sd, u32 reg_addr)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct noon010_info *info = to_noon010(sd);
int ret = set_i2c_page(info, client, reg_addr);
if (ret)
return ret;
return i2c_smbus_read_byte_data(client, reg_addr & 0xFF);
}
static int cam_i2c_write(struct v4l2_subdev *sd, u32 reg_addr, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct noon010_info *info = to_noon010(sd);
int ret = set_i2c_page(info, client, reg_addr);
if (ret)
return ret;
return i2c_smbus_write_byte_data(client, reg_addr & 0xFF, val);
}
static inline int noon010_bulk_write_reg(struct v4l2_subdev *sd,
const struct i2c_regval *msg)
{
while (msg->addr != REG_TERM) {
int ret = cam_i2c_write(sd, msg->addr, msg->val);
if (ret)
return ret;
msg++;
}
return 0;
}
static int noon010_power_ctrl(struct v4l2_subdev *sd, bool reset, bool sleep)
{
struct noon010_info *info = to_noon010(sd);
u8 reg = sleep ? 0xF1 : 0xF0;
int ret = 0;
if (reset) {
ret = cam_i2c_write(sd, POWER_CTRL_REG, reg | 0x02);
udelay(20);
}
if (!ret) {
ret = cam_i2c_write(sd, POWER_CTRL_REG, reg);
if (reset && !ret)
info->i2c_reg_page = -1;
}
return ret;
}
static int noon010_enable_autowhitebalance(struct v4l2_subdev *sd, int on)
{
int ret;
ret = cam_i2c_write(sd, AWB_CTL_REG(1), on ? 0x2E : 0x2F);
if (!ret)
ret = cam_i2c_write(sd, AWB_CTL_REG(0), on ? 0xFB : 0x7B);
return ret;
}
static int noon010_set_flip(struct v4l2_subdev *sd, int hflip, int vflip)
{
struct noon010_info *info = to_noon010(sd);
int reg, ret;
reg = cam_i2c_read(sd, VDO_CTL_REG(1));
if (reg < 0)
return reg;
reg &= 0x7C;
if (hflip)
reg |= 0x01;
if (vflip)
reg |= 0x02;
ret = cam_i2c_write(sd, VDO_CTL_REG(1), reg | 0x80);
if (!ret) {
info->hflip = hflip;
info->vflip = vflip;
}
return ret;
}
static int noon010_set_params(struct v4l2_subdev *sd)
{
struct noon010_info *info = to_noon010(sd);
int ret = cam_i2c_write(sd, VDO_CTL_REG(0),
info->curr_win->vid_ctl1);
if (ret)
return ret;
return cam_i2c_write(sd, ISP_CTL_REG(0),
info->curr_fmt->ispctl1_reg);
}
static int noon010_try_frame_size(struct v4l2_mbus_framefmt *mf,
const struct noon010_frmsize **size)
{
unsigned int min_err = ~0;
int i = ARRAY_SIZE(noon010_sizes);
const struct noon010_frmsize *fsize = &noon010_sizes[0],
*match = NULL;
while (i--) {
int err = abs(fsize->width - mf->width)
+ abs(fsize->height - mf->height);
if (err < min_err) {
min_err = err;
match = fsize;
}
fsize++;
}
if (match) {
mf->width = match->width;
mf->height = match->height;
if (size)
*size = match;
return 0;
}
return -EINVAL;
}
static int power_enable(struct noon010_info *info)
{
int ret;
if (info->power) {
v4l2_info(&info->sd, "%s: sensor is already on\n", __func__);
return 0;
}
if (gpio_is_valid(info->gpio_nstby))
gpio_set_value(info->gpio_nstby, 0);
if (gpio_is_valid(info->gpio_nreset))
gpio_set_value(info->gpio_nreset, 0);
ret = regulator_bulk_enable(NOON010_NUM_SUPPLIES, info->supply);
if (ret)
return ret;
if (gpio_is_valid(info->gpio_nreset)) {
msleep(50);
gpio_set_value(info->gpio_nreset, 1);
}
if (gpio_is_valid(info->gpio_nstby)) {
udelay(1000);
gpio_set_value(info->gpio_nstby, 1);
}
if (gpio_is_valid(info->gpio_nreset)) {
udelay(1000);
gpio_set_value(info->gpio_nreset, 0);
msleep(100);
gpio_set_value(info->gpio_nreset, 1);
msleep(20);
}
info->power = 1;
v4l2_dbg(1, debug, &info->sd, "%s: sensor is on\n", __func__);
return 0;
}
static int power_disable(struct noon010_info *info)
{
int ret;
if (!info->power) {
v4l2_info(&info->sd, "%s: sensor is already off\n", __func__);
return 0;
}
ret = regulator_bulk_disable(NOON010_NUM_SUPPLIES, info->supply);
if (ret)
return ret;
if (gpio_is_valid(info->gpio_nstby))
gpio_set_value(info->gpio_nstby, 0);
if (gpio_is_valid(info->gpio_nreset))
gpio_set_value(info->gpio_nreset, 0);
info->power = 0;
v4l2_dbg(1, debug, &info->sd, "%s: sensor is off\n", __func__);
return 0;
}
static int noon010_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct noon010_info *info = to_noon010(sd);
int ret = 0;
v4l2_dbg(1, debug, sd, "%s: ctrl_id: %d, value: %d\n",
__func__, ctrl->id, ctrl->val);
mutex_lock(&info->lock);
if (!info->power)
goto unlock;
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = noon010_enable_autowhitebalance(sd, ctrl->val);
break;
case V4L2_CID_BLUE_BALANCE:
ret = cam_i2c_write(sd, MWB_BGAIN_REG, ctrl->val);
break;
case V4L2_CID_RED_BALANCE:
ret = cam_i2c_write(sd, MWB_RGAIN_REG, ctrl->val);
break;
default:
ret = -EINVAL;
}
unlock:
mutex_unlock(&info->lock);
return ret;
}
static int noon010_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= ARRAY_SIZE(noon010_formats))
return -EINVAL;
code->code = noon010_formats[code->index].code;
return 0;
}
static int noon010_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct noon010_info *info = to_noon010(sd);
struct v4l2_mbus_framefmt *mf;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
if (cfg) {
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
fmt->format = *mf;
}
return 0;
}
mf = &fmt->format;
mutex_lock(&info->lock);
mf->width = info->curr_win->width;
mf->height = info->curr_win->height;
mf->code = info->curr_fmt->code;
mf->colorspace = info->curr_fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
mutex_unlock(&info->lock);
return 0;
}
static const struct noon010_format *noon010_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
int i = ARRAY_SIZE(noon010_formats);
while (--i)
if (mf->code == noon010_formats[i].code)
break;
mf->code = noon010_formats[i].code;
return &noon010_formats[i];
}
static int noon010_set_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct noon010_info *info = to_noon010(sd);
const struct noon010_frmsize *size = NULL;
const struct noon010_format *nf;
struct v4l2_mbus_framefmt *mf;
int ret = 0;
nf = noon010_try_fmt(sd, &fmt->format);
noon010_try_frame_size(&fmt->format, &size);
fmt->format.colorspace = V4L2_COLORSPACE_JPEG;
fmt->format.field = V4L2_FIELD_NONE;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
if (cfg) {
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
*mf = fmt->format;
}
return 0;
}
mutex_lock(&info->lock);
if (!info->streaming) {
info->apply_new_cfg = 1;
info->curr_fmt = nf;
info->curr_win = size;
} else {
ret = -EBUSY;
}
mutex_unlock(&info->lock);
return ret;
}
static int noon010_base_config(struct v4l2_subdev *sd)
{
int ret = noon010_bulk_write_reg(sd, noon010_base_regs);
if (!ret)
ret = noon010_set_params(sd);
if (!ret)
ret = noon010_set_flip(sd, 1, 0);
return ret;
}
static int noon010_s_power(struct v4l2_subdev *sd, int on)
{
struct noon010_info *info = to_noon010(sd);
int ret;
mutex_lock(&info->lock);
if (on) {
ret = power_enable(info);
if (!ret)
ret = noon010_base_config(sd);
} else {
noon010_power_ctrl(sd, false, true);
ret = power_disable(info);
}
mutex_unlock(&info->lock);
if (!ret && on)
ret = v4l2_ctrl_handler_setup(&info->hdl);
return ret;
}
static int noon010_s_stream(struct v4l2_subdev *sd, int on)
{
struct noon010_info *info = to_noon010(sd);
int ret = 0;
mutex_lock(&info->lock);
if (!info->streaming != !on) {
ret = noon010_power_ctrl(sd, false, !on);
if (!ret)
info->streaming = on;
}
if (!ret && on && info->apply_new_cfg) {
ret = noon010_set_params(sd);
if (!ret)
info->apply_new_cfg = 0;
}
mutex_unlock(&info->lock);
return ret;
}
static int noon010_log_status(struct v4l2_subdev *sd)
{
struct noon010_info *info = to_noon010(sd);
v4l2_ctrl_handler_log_status(&info->hdl, sd->name);
return 0;
}
static int noon010_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *mf = v4l2_subdev_get_try_format(sd, fh->pad, 0);
mf->width = noon010_sizes[0].width;
mf->height = noon010_sizes[0].height;
mf->code = noon010_formats[0].code;
mf->colorspace = V4L2_COLORSPACE_JPEG;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int noon010_detect(struct i2c_client *client, struct noon010_info *info)
{
int ret;
ret = power_enable(info);
if (ret)
return ret;
ret = i2c_smbus_read_byte_data(client, DEVICE_ID_REG);
if (ret < 0)
dev_err(&client->dev, "I2C read failed: 0x%X\n", ret);
power_disable(info);
return ret == NOON010PC30_ID ? 0 : -ENODEV;
}
static int noon010_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct noon010_info *info;
struct v4l2_subdev *sd;
const struct noon010pc30_platform_data *pdata
= client->dev.platform_data;
int ret;
int i;
if (!pdata) {
dev_err(&client->dev, "No platform data!\n");
return -EIO;
}
info = devm_kzalloc(&client->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
mutex_init(&info->lock);
sd = &info->sd;
v4l2_i2c_subdev_init(sd, client, &noon010_ops);
strlcpy(sd->name, MODULE_NAME, sizeof(sd->name));
sd->internal_ops = &noon010_subdev_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
v4l2_ctrl_handler_init(&info->hdl, 3);
v4l2_ctrl_new_std(&info->hdl, &noon010_ctrl_ops,
V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1);
v4l2_ctrl_new_std(&info->hdl, &noon010_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 127, 1, 64);
v4l2_ctrl_new_std(&info->hdl, &noon010_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 127, 1, 64);
sd->ctrl_handler = &info->hdl;
ret = info->hdl.error;
if (ret)
goto np_err;
info->i2c_reg_page = -1;
info->gpio_nreset = -EINVAL;
info->gpio_nstby = -EINVAL;
info->curr_fmt = &noon010_formats[0];
info->curr_win = &noon010_sizes[0];
if (gpio_is_valid(pdata->gpio_nreset)) {
ret = devm_gpio_request_one(&client->dev, pdata->gpio_nreset,
GPIOF_OUT_INIT_LOW,
"NOON010PC30 NRST");
if (ret) {
dev_err(&client->dev, "GPIO request error: %d\n", ret);
goto np_err;
}
info->gpio_nreset = pdata->gpio_nreset;
gpio_export(info->gpio_nreset, 0);
}
if (gpio_is_valid(pdata->gpio_nstby)) {
ret = devm_gpio_request_one(&client->dev, pdata->gpio_nstby,
GPIOF_OUT_INIT_LOW,
"NOON010PC30 NSTBY");
if (ret) {
dev_err(&client->dev, "GPIO request error: %d\n", ret);
goto np_err;
}
info->gpio_nstby = pdata->gpio_nstby;
gpio_export(info->gpio_nstby, 0);
}
for (i = 0; i < NOON010_NUM_SUPPLIES; i++)
info->supply[i].supply = noon010_supply_name[i];
ret = devm_regulator_bulk_get(&client->dev, NOON010_NUM_SUPPLIES,
info->supply);
if (ret)
goto np_err;
info->pad.flags = MEDIA_PAD_FL_SOURCE;
sd->entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
ret = media_entity_init(&sd->entity, 1, &info->pad, 0);
if (ret < 0)
goto np_err;
ret = noon010_detect(client, info);
if (!ret)
return 0;
np_err:
v4l2_ctrl_handler_free(&info->hdl);
v4l2_device_unregister_subdev(sd);
return ret;
}
static int noon010_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct noon010_info *info = to_noon010(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&info->hdl);
media_entity_cleanup(&sd->entity);
return 0;
}
