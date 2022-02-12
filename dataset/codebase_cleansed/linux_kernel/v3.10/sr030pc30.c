static inline struct sr030pc30_info *to_sr030pc30(struct v4l2_subdev *sd)
{
return container_of(sd, struct sr030pc30_info, sd);
}
static inline int set_i2c_page(struct sr030pc30_info *info,
struct i2c_client *client, unsigned int reg)
{
int ret = 0;
u32 page = reg >> 8 & 0xFF;
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
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret = set_i2c_page(info, client, reg_addr);
if (!ret)
ret = i2c_smbus_read_byte_data(client, reg_addr & 0xFF);
return ret;
}
static int cam_i2c_write(struct v4l2_subdev *sd, u32 reg_addr, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret = set_i2c_page(info, client, reg_addr);
if (!ret)
ret = i2c_smbus_write_byte_data(
client, reg_addr & 0xFF, val);
return ret;
}
static inline int sr030pc30_bulk_write_reg(struct v4l2_subdev *sd,
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
static int sr030pc30_pwr_ctrl(struct v4l2_subdev *sd,
bool reset, bool sleep)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
u8 reg = sleep ? 0xF1 : 0xF0;
int ret = 0;
if (reset)
ret = cam_i2c_write(sd, POWER_CTRL_REG, reg | 0x02);
if (!ret) {
ret = cam_i2c_write(sd, POWER_CTRL_REG, reg);
if (!ret) {
info->sleep = sleep;
if (reset)
info->i2c_reg_page = -1;
}
}
return ret;
}
static inline int sr030pc30_enable_autoexposure(struct v4l2_subdev *sd, int on)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret = cam_i2c_write(sd, AE_CTL1_REG, on ? 0xDC : 0x0C);
if (!ret)
info->auto_exp = on;
return ret;
}
static int sr030pc30_set_exposure(struct v4l2_subdev *sd, int value)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
unsigned long expos = value * info->pdata->clk_rate / (8 * 1000);
int ret = cam_i2c_write(sd, EXP_TIMEH_REG, expos >> 16 & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_TIMEM_REG, expos >> 8 & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_TIMEL_REG, expos & 0xFF);
if (!ret) {
info->exposure = value;
ret = sr030pc30_enable_autoexposure(sd, 0);
}
return ret;
}
static int sr030pc30_enable_autowhitebalance(struct v4l2_subdev *sd, int on)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret = cam_i2c_write(sd, AWB_CTL2_REG, on ? 0x2E : 0x2F);
if (!ret)
ret = cam_i2c_write(sd, AWB_CTL1_REG, on ? 0xFB : 0x7B);
if (!ret)
info->auto_wb = on;
return ret;
}
static int sr030pc30_set_flip(struct v4l2_subdev *sd)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
s32 reg = cam_i2c_read(sd, VDO_CTL2_REG);
if (reg < 0)
return reg;
reg &= 0x7C;
if (info->hflip)
reg |= 0x01;
if (info->vflip)
reg |= 0x02;
return cam_i2c_write(sd, VDO_CTL2_REG, reg | 0x80);
}
static int sr030pc30_set_params(struct v4l2_subdev *sd)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret;
if (!info->curr_win)
return -EINVAL;
ret = cam_i2c_write(sd, VDO_CTL1_REG,
info->curr_win->vid_ctl1);
if (!ret && info->curr_fmt)
ret = cam_i2c_write(sd, ISP_CTL_REG(0),
info->curr_fmt->ispctl1_reg);
if (!ret)
ret = sr030pc30_set_flip(sd);
return ret;
}
static int sr030pc30_try_frame_size(struct v4l2_mbus_framefmt *mf)
{
unsigned int min_err = ~0;
int i = ARRAY_SIZE(sr030pc30_sizes);
const struct sr030pc30_frmsize *fsize = &sr030pc30_sizes[0],
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
return 0;
}
return -EINVAL;
}
static int sr030pc30_queryctrl(struct v4l2_subdev *sd,
struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(sr030pc30_ctrl); i++)
if (qc->id == sr030pc30_ctrl[i].id) {
*qc = sr030pc30_ctrl[i];
v4l2_dbg(1, debug, sd, "%s id: %d\n",
__func__, qc->id);
return 0;
}
return -EINVAL;
}
static inline int sr030pc30_set_bluebalance(struct v4l2_subdev *sd, int value)
{
int ret = cam_i2c_write(sd, MWB_BGAIN_REG, value);
if (!ret)
to_sr030pc30(sd)->blue_balance = value;
return ret;
}
static inline int sr030pc30_set_redbalance(struct v4l2_subdev *sd, int value)
{
int ret = cam_i2c_write(sd, MWB_RGAIN_REG, value);
if (!ret)
to_sr030pc30(sd)->red_balance = value;
return ret;
}
static int sr030pc30_s_ctrl(struct v4l2_subdev *sd,
struct v4l2_control *ctrl)
{
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(sr030pc30_ctrl); i++)
if (ctrl->id == sr030pc30_ctrl[i].id)
break;
if (i == ARRAY_SIZE(sr030pc30_ctrl))
return -EINVAL;
if (ctrl->value < sr030pc30_ctrl[i].minimum ||
ctrl->value > sr030pc30_ctrl[i].maximum)
return -ERANGE;
v4l2_dbg(1, debug, sd, "%s: ctrl_id: %d, value: %d\n",
__func__, ctrl->id, ctrl->value);
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
sr030pc30_enable_autowhitebalance(sd, ctrl->value);
break;
case V4L2_CID_BLUE_BALANCE:
ret = sr030pc30_set_bluebalance(sd, ctrl->value);
break;
case V4L2_CID_RED_BALANCE:
ret = sr030pc30_set_redbalance(sd, ctrl->value);
break;
case V4L2_CID_EXPOSURE_AUTO:
sr030pc30_enable_autoexposure(sd,
ctrl->value == V4L2_EXPOSURE_AUTO);
break;
case V4L2_CID_EXPOSURE:
ret = sr030pc30_set_exposure(sd, ctrl->value);
break;
default:
return -EINVAL;
}
return ret;
}
static int sr030pc30_g_ctrl(struct v4l2_subdev *sd,
struct v4l2_control *ctrl)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
v4l2_dbg(1, debug, sd, "%s: id: %d\n", __func__, ctrl->id);
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
ctrl->value = info->auto_wb;
break;
case V4L2_CID_BLUE_BALANCE:
ctrl->value = info->blue_balance;
break;
case V4L2_CID_RED_BALANCE:
ctrl->value = info->red_balance;
break;
case V4L2_CID_EXPOSURE_AUTO:
ctrl->value = info->auto_exp;
break;
case V4L2_CID_EXPOSURE:
ctrl->value = info->exposure;
break;
default:
return -EINVAL;
}
return 0;
}
static int sr030pc30_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (!code || index >= ARRAY_SIZE(sr030pc30_formats))
return -EINVAL;
*code = sr030pc30_formats[index].code;
return 0;
}
static int sr030pc30_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret;
if (!mf)
return -EINVAL;
if (!info->curr_win || !info->curr_fmt) {
ret = sr030pc30_set_params(sd);
if (ret)
return ret;
}
mf->width = info->curr_win->width;
mf->height = info->curr_win->height;
mf->code = info->curr_fmt->code;
mf->colorspace = info->curr_fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static const struct sr030pc30_format *try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
int i = ARRAY_SIZE(sr030pc30_formats);
sr030pc30_try_frame_size(mf);
while (i--)
if (mf->code == sr030pc30_formats[i].code)
break;
mf->code = sr030pc30_formats[i].code;
return &sr030pc30_formats[i];
}
static int sr030pc30_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
if (!sd || !mf)
return -EINVAL;
try_fmt(sd, mf);
return 0;
}
static int sr030pc30_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
if (!sd || !mf)
return -EINVAL;
info->curr_fmt = try_fmt(sd, mf);
return sr030pc30_set_params(sd);
}
static int sr030pc30_base_config(struct v4l2_subdev *sd)
{
struct sr030pc30_info *info = to_sr030pc30(sd);
int ret;
unsigned long expmin, expmax;
ret = sr030pc30_bulk_write_reg(sd, sr030pc30_base_regs);
if (!ret) {
info->curr_fmt = &sr030pc30_formats[0];
info->curr_win = &sr030pc30_sizes[0];
ret = sr030pc30_set_params(sd);
}
if (!ret)
ret = sr030pc30_pwr_ctrl(sd, false, false);
if (!ret && !info->pdata)
return ret;
expmin = EXPOS_MIN_MS * info->pdata->clk_rate / (8 * 1000);
expmax = EXPOS_MAX_MS * info->pdata->clk_rate / (8 * 1000);
v4l2_dbg(1, debug, sd, "%s: expmin= %lx, expmax= %lx", __func__,
expmin, expmax);
ret = cam_i2c_write(sd, EXP_MMINH_REG, expmin >> 8 & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_MMINL_REG, expmin & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_MMAXH_REG, expmax >> 16 & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_MMAXM_REG, expmax >> 8 & 0xFF);
if (!ret)
ret = cam_i2c_write(sd, EXP_MMAXL_REG, expmax & 0xFF);
return ret;
}
static int sr030pc30_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct sr030pc30_info *info = to_sr030pc30(sd);
const struct sr030pc30_platform_data *pdata = info->pdata;
int ret;
if (pdata == NULL) {
WARN(1, "No platform data!\n");
return -EINVAL;
}
if (!on)
sr030pc30_pwr_ctrl(sd, false, true);
if (pdata->set_power) {
ret = pdata->set_power(&client->dev, on);
if (ret)
return ret;
}
if (on) {
ret = sr030pc30_base_config(sd);
} else {
ret = 0;
info->curr_win = NULL;
info->curr_fmt = NULL;
}
return ret;
}
static int sr030pc30_detect(struct i2c_client *client)
{
const struct sr030pc30_platform_data *pdata
= client->dev.platform_data;
int ret;
if (pdata->set_power) {
ret = pdata->set_power(&client->dev, 1);
if (ret)
return ret;
}
ret = i2c_smbus_read_byte_data(client, DEVICE_ID_REG);
if (pdata->set_power)
pdata->set_power(&client->dev, 0);
if (ret < 0) {
dev_err(&client->dev, "%s: I2C read failed\n", __func__);
return ret;
}
return ret == SR030PC30_ID ? 0 : -ENODEV;
}
static int sr030pc30_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sr030pc30_info *info;
struct v4l2_subdev *sd;
const struct sr030pc30_platform_data *pdata
= client->dev.platform_data;
int ret;
if (!pdata) {
dev_err(&client->dev, "No platform data!");
return -EIO;
}
ret = sr030pc30_detect(client);
if (ret)
return ret;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
sd = &info->sd;
strcpy(sd->name, MODULE_NAME);
info->pdata = client->dev.platform_data;
v4l2_i2c_subdev_init(sd, client, &sr030pc30_ops);
info->i2c_reg_page = -1;
info->hflip = 1;
info->auto_exp = 1;
info->exposure = 30;
return 0;
}
static int sr030pc30_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct sr030pc30_info *info = to_sr030pc30(sd);
v4l2_device_unregister_subdev(sd);
kfree(info);
return 0;
}
