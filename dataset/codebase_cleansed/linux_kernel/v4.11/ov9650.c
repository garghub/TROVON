static inline struct v4l2_subdev *ctrl_to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct ov965x, ctrls.handler)->sd;
}
static inline struct ov965x *to_ov965x(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov965x, sd);
}
static int ov965x_read(struct i2c_client *client, u8 addr, u8 *val)
{
u8 buf = addr;
struct i2c_msg msg = {
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &buf
};
int ret;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret == 1) {
msg.flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret == 1)
*val = buf;
}
v4l2_dbg(2, debug, client, "%s: 0x%02x @ 0x%02x. (%d)\n",
__func__, *val, addr, ret);
return ret == 1 ? 0 : ret;
}
static int ov965x_write(struct i2c_client *client, u8 addr, u8 val)
{
u8 buf[2] = { addr, val };
int ret = i2c_master_send(client, buf, 2);
v4l2_dbg(2, debug, client, "%s: 0x%02x @ 0x%02X (%d)\n",
__func__, val, addr, ret);
return ret == 2 ? 0 : ret;
}
static int ov965x_write_array(struct i2c_client *client,
const struct i2c_rv *regs)
{
int i, ret = 0;
for (i = 0; ret == 0 && regs[i].addr != REG_NULL; i++)
ret = ov965x_write(client, regs[i].addr, regs[i].value);
return ret;
}
static int ov965x_set_default_gamma_curve(struct ov965x *ov965x)
{
static const u8 gamma_curve[] = {
0x40, 0x30, 0x4b, 0x60, 0x70, 0x70, 0x70, 0x70,
0x60, 0x60, 0x50, 0x48, 0x3a, 0x2e, 0x28, 0x22,
0x04, 0x07, 0x10, 0x28, 0x36, 0x44, 0x52, 0x60,
0x6c, 0x78, 0x8c, 0x9e, 0xbb, 0xd2, 0xe6
};
u8 addr = REG_GSP;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gamma_curve); i++) {
int ret = ov965x_write(ov965x->client, addr, gamma_curve[i]);
if (ret < 0)
return ret;
addr++;
}
return 0;
}
static int ov965x_set_color_matrix(struct ov965x *ov965x)
{
static const u8 mtx[] = {
0x3a, 0x3d, 0x03, 0x12, 0x26, 0x38, 0x40, 0x40, 0x40, 0x0d
};
u8 addr = REG_MTX(1);
unsigned int i;
for (i = 0; i < ARRAY_SIZE(mtx); i++) {
int ret = ov965x_write(ov965x->client, addr, mtx[i]);
if (ret < 0)
return ret;
addr++;
}
return 0;
}
static void ov965x_gpio_set(int gpio, int val)
{
if (gpio_is_valid(gpio))
gpio_set_value(gpio, val);
}
static void __ov965x_set_power(struct ov965x *ov965x, int on)
{
if (on) {
ov965x_gpio_set(ov965x->gpios[GPIO_PWDN], 0);
ov965x_gpio_set(ov965x->gpios[GPIO_RST], 0);
msleep(25);
} else {
ov965x_gpio_set(ov965x->gpios[GPIO_RST], 1);
ov965x_gpio_set(ov965x->gpios[GPIO_PWDN], 1);
}
ov965x->streaming = 0;
}
static int ov965x_s_power(struct v4l2_subdev *sd, int on)
{
struct ov965x *ov965x = to_ov965x(sd);
struct i2c_client *client = ov965x->client;
int ret = 0;
v4l2_dbg(1, debug, client, "%s: on: %d\n", __func__, on);
mutex_lock(&ov965x->lock);
if (ov965x->power == !on) {
__ov965x_set_power(ov965x, on);
if (on) {
ret = ov965x_write_array(client,
ov965x_init_regs);
ov965x->apply_frame_fmt = 1;
ov965x->ctrls.update = 1;
}
}
if (!ret)
ov965x->power += on ? 1 : -1;
WARN_ON(ov965x->power < 0);
mutex_unlock(&ov965x->lock);
return ret;
}
static void ov965x_update_exposure_ctrl(struct ov965x *ov965x)
{
struct v4l2_ctrl *ctrl = ov965x->ctrls.exposure;
unsigned long fint, trow;
int min, max, def;
u8 clkrc;
mutex_lock(&ov965x->lock);
if (WARN_ON(!ctrl || !ov965x->frame_size)) {
mutex_unlock(&ov965x->lock);
return;
}
clkrc = DEF_CLKRC + ov965x->fiv->clkrc_div;
fint = ov965x->mclk_frequency * ((clkrc >> 7) + 1) /
((2 * ((clkrc & 0x3f) + 1)));
trow = (2 * 1520 * 1000000UL) / fint;
max = ov965x->frame_size->max_exp_lines * trow;
ov965x->exp_row_interval = trow;
mutex_unlock(&ov965x->lock);
v4l2_dbg(1, debug, &ov965x->sd, "clkrc: %#x, fi: %lu, tr: %lu, %d\n",
clkrc, fint, trow, max);
min = (trow + 100) / 100;
max = (max - 100) / 100;
def = min + (max - min) / 2;
if (v4l2_ctrl_modify_range(ctrl, min, max, 1, def))
v4l2_err(&ov965x->sd, "Exposure ctrl range update failed\n");
}
static int ov965x_set_banding_filter(struct ov965x *ov965x, int value)
{
unsigned long mbd, light_freq;
int ret;
u8 reg;
ret = ov965x_read(ov965x->client, REG_COM8, &reg);
if (!ret) {
if (value == V4L2_CID_POWER_LINE_FREQUENCY_DISABLED)
reg &= ~COM8_BFILT;
else
reg |= COM8_BFILT;
ret = ov965x_write(ov965x->client, REG_COM8, reg);
}
if (value == V4L2_CID_POWER_LINE_FREQUENCY_DISABLED)
return 0;
if (WARN_ON(ov965x->fiv == NULL))
return -EINVAL;
if (value == V4L2_CID_POWER_LINE_FREQUENCY_50HZ)
light_freq = 50;
else
light_freq = 60;
mbd = (1000UL * ov965x->fiv->interval.denominator *
ov965x->frame_size->max_exp_lines) /
ov965x->fiv->interval.numerator;
mbd = ((mbd / (light_freq * 2)) + 500) / 1000UL;
return ov965x_write(ov965x->client, REG_MBD, mbd);
}
static int ov965x_set_white_balance(struct ov965x *ov965x, int awb)
{
int ret;
u8 reg;
ret = ov965x_read(ov965x->client, REG_COM8, &reg);
if (!ret) {
reg = awb ? reg | REG_COM8 : reg & ~REG_COM8;
ret = ov965x_write(ov965x->client, REG_COM8, reg);
}
if (!ret && !awb) {
ret = ov965x_write(ov965x->client, REG_BLUE,
ov965x->ctrls.blue_balance->val);
if (ret < 0)
return ret;
ret = ov965x_write(ov965x->client, REG_RED,
ov965x->ctrls.red_balance->val);
}
return ret;
}
static int ov965x_set_brightness(struct ov965x *ov965x, int val)
{
static const u8 regs[NUM_BR_LEVELS + 1][NUM_BR_REGS] = {
{ REG_AEW, REG_AEB, REG_VPT },
{ 0x1c, 0x12, 0x50 },
{ 0x3d, 0x30, 0x71 },
{ 0x50, 0x44, 0x92 },
{ 0x70, 0x64, 0xc3 },
{ 0x90, 0x84, 0xd4 },
{ 0xc4, 0xbf, 0xf9 },
{ 0xd8, 0xd0, 0xfa },
};
int i, ret = 0;
val += (NUM_BR_LEVELS / 2 + 1);
if (val > NUM_BR_LEVELS)
return -EINVAL;
for (i = 0; i < NUM_BR_REGS && !ret; i++)
ret = ov965x_write(ov965x->client, regs[0][i],
regs[val][i]);
return ret;
}
static int ov965x_set_gain(struct ov965x *ov965x, int auto_gain)
{
struct i2c_client *client = ov965x->client;
struct ov965x_ctrls *ctrls = &ov965x->ctrls;
int ret = 0;
u8 reg;
if (ctrls->auto_gain->is_new) {
ret = ov965x_read(client, REG_COM8, &reg);
if (ret < 0)
return ret;
if (ctrls->auto_gain->val)
reg |= COM8_AGC;
else
reg &= ~COM8_AGC;
ret = ov965x_write(client, REG_COM8, reg);
if (ret < 0)
return ret;
}
if (ctrls->gain->is_new && !auto_gain) {
unsigned int gain = ctrls->gain->val;
unsigned int rgain;
int m;
for (m = 6; m >= 0; m--)
if (gain >= (1 << m) * 16)
break;
rgain = (gain - ((1 << m) * 16)) / (1 << m);
rgain |= (((1 << m) - 1) << 4);
ret = ov965x_write(client, REG_GAIN, rgain & 0xff);
if (ret < 0)
return ret;
ret = ov965x_read(client, REG_VREF, &reg);
if (ret < 0)
return ret;
reg &= ~VREF_GAIN_MASK;
reg |= (((rgain >> 8) & 0x3) << 6);
ret = ov965x_write(client, REG_VREF, reg);
if (ret < 0)
return ret;
ctrls->gain->val = (1 << m) * (16 + (rgain & 0xf));
}
return ret;
}
static int ov965x_set_sharpness(struct ov965x *ov965x, unsigned int value)
{
u8 com14, edge;
int ret;
ret = ov965x_read(ov965x->client, REG_COM14, &com14);
if (ret < 0)
return ret;
ret = ov965x_read(ov965x->client, REG_EDGE, &edge);
if (ret < 0)
return ret;
com14 = value ? com14 | COM14_EDGE_EN : com14 & ~COM14_EDGE_EN;
value--;
if (value > 0x0f) {
com14 |= COM14_EEF_X2;
value >>= 1;
} else {
com14 &= ~COM14_EEF_X2;
}
ret = ov965x_write(ov965x->client, REG_COM14, com14);
if (ret < 0)
return ret;
edge &= ~EDGE_FACTOR_MASK;
edge |= ((u8)value & 0x0f);
return ov965x_write(ov965x->client, REG_EDGE, edge);
}
static int ov965x_set_exposure(struct ov965x *ov965x, int exp)
{
struct i2c_client *client = ov965x->client;
struct ov965x_ctrls *ctrls = &ov965x->ctrls;
bool auto_exposure = (exp == V4L2_EXPOSURE_AUTO);
int ret;
u8 reg;
if (ctrls->auto_exp->is_new) {
ret = ov965x_read(client, REG_COM8, &reg);
if (ret < 0)
return ret;
if (auto_exposure)
reg |= (COM8_AEC | COM8_AGC);
else
reg &= ~(COM8_AEC | COM8_AGC);
ret = ov965x_write(client, REG_COM8, reg);
if (ret < 0)
return ret;
}
if (!auto_exposure && ctrls->exposure->is_new) {
unsigned int exposure = (ctrls->exposure->val * 100)
/ ov965x->exp_row_interval;
ret = ov965x_write(client, REG_COM1, exposure & 0x3);
if (!ret)
ret = ov965x_write(client, REG_AECH,
(exposure >> 2) & 0xff);
if (!ret)
ret = ov965x_write(client, REG_AECHM,
(exposure >> 10) & 0x3f);
ctrls->exposure->val = ((exposure * ov965x->exp_row_interval)
+ 50) / 100;
if (ret < 0)
return ret;
}
v4l2_ctrl_activate(ov965x->ctrls.brightness, !exp);
return 0;
}
static int ov965x_set_flip(struct ov965x *ov965x)
{
u8 mvfp = 0;
if (ov965x->ctrls.hflip->val)
mvfp |= MVFP_MIRROR;
if (ov965x->ctrls.vflip->val)
mvfp |= MVFP_FLIP;
return ov965x_write(ov965x->client, REG_MVFP, mvfp);
}
static int ov965x_set_saturation(struct ov965x *ov965x, int val)
{
static const u8 regs[NUM_SAT_LEVELS][NUM_SAT_REGS] = {
{ 0x1d, 0x1f, 0x02, 0x09, 0x13, 0x1c },
{ 0x2e, 0x31, 0x02, 0x0e, 0x1e, 0x2d },
{ 0x3a, 0x3d, 0x03, 0x12, 0x26, 0x38 },
{ 0x46, 0x49, 0x04, 0x16, 0x2e, 0x43 },
{ 0x57, 0x5c, 0x05, 0x1b, 0x39, 0x54 },
};
u8 addr = REG_MTX(1);
int i, ret = 0;
val += (NUM_SAT_LEVELS / 2);
if (val >= NUM_SAT_LEVELS)
return -EINVAL;
for (i = 0; i < NUM_SAT_REGS && !ret; i++)
ret = ov965x_write(ov965x->client, addr + i, regs[val][i]);
return ret;
}
static int ov965x_set_test_pattern(struct ov965x *ov965x, int value)
{
int ret;
u8 reg;
ret = ov965x_read(ov965x->client, REG_COM23, &reg);
if (ret < 0)
return ret;
reg = value ? reg | COM23_TEST_MODE : reg & ~COM23_TEST_MODE;
return ov965x_write(ov965x->client, REG_COM23, reg);
}
static int __g_volatile_ctrl(struct ov965x *ov965x, struct v4l2_ctrl *ctrl)
{
struct i2c_client *client = ov965x->client;
unsigned int exposure, gain, m;
u8 reg0, reg1, reg2;
int ret;
if (!ov965x->power)
return 0;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
if (!ctrl->val)
return 0;
ret = ov965x_read(client, REG_GAIN, &reg0);
if (ret < 0)
return ret;
ret = ov965x_read(client, REG_VREF, &reg1);
if (ret < 0)
return ret;
gain = ((reg1 >> 6) << 8) | reg0;
m = 0x01 << fls(gain >> 4);
ov965x->ctrls.gain->val = m * (16 + (gain & 0xf));
break;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->val == V4L2_EXPOSURE_MANUAL)
return 0;
ret = ov965x_read(client, REG_COM1, &reg0);
if (!ret)
ret = ov965x_read(client, REG_AECH, &reg1);
if (!ret)
ret = ov965x_read(client, REG_AECHM, &reg2);
if (ret < 0)
return ret;
exposure = ((reg2 & 0x3f) << 10) | (reg1 << 2) |
(reg0 & 0x3);
ov965x->ctrls.exposure->val = ((exposure *
ov965x->exp_row_interval) + 50) / 100;
break;
}
return 0;
}
static int ov965x_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = ctrl_to_sd(ctrl);
struct ov965x *ov965x = to_ov965x(sd);
int ret;
v4l2_dbg(1, debug, sd, "g_ctrl: %s\n", ctrl->name);
mutex_lock(&ov965x->lock);
ret = __g_volatile_ctrl(ov965x, ctrl);
mutex_unlock(&ov965x->lock);
return ret;
}
static int ov965x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = ctrl_to_sd(ctrl);
struct ov965x *ov965x = to_ov965x(sd);
int ret = -EINVAL;
v4l2_dbg(1, debug, sd, "s_ctrl: %s, value: %d. power: %d\n",
ctrl->name, ctrl->val, ov965x->power);
mutex_lock(&ov965x->lock);
if (ov965x->power == 0) {
mutex_unlock(&ov965x->lock);
return 0;
}
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = ov965x_set_white_balance(ov965x, ctrl->val);
break;
case V4L2_CID_BRIGHTNESS:
ret = ov965x_set_brightness(ov965x, ctrl->val);
break;
case V4L2_CID_EXPOSURE_AUTO:
ret = ov965x_set_exposure(ov965x, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
ret = ov965x_set_gain(ov965x, ctrl->val);
break;
case V4L2_CID_HFLIP:
ret = ov965x_set_flip(ov965x);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
ret = ov965x_set_banding_filter(ov965x, ctrl->val);
break;
case V4L2_CID_SATURATION:
ret = ov965x_set_saturation(ov965x, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
ret = ov965x_set_sharpness(ov965x, ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
ret = ov965x_set_test_pattern(ov965x, ctrl->val);
break;
}
mutex_unlock(&ov965x->lock);
return ret;
}
static int ov965x_initialize_controls(struct ov965x *ov965x)
{
const struct v4l2_ctrl_ops *ops = &ov965x_ctrl_ops;
struct ov965x_ctrls *ctrls = &ov965x->ctrls;
struct v4l2_ctrl_handler *hdl = &ctrls->handler;
int ret;
ret = v4l2_ctrl_handler_init(hdl, 16);
if (ret < 0)
return ret;
ctrls->auto_wb = v4l2_ctrl_new_std(hdl, ops,
V4L2_CID_AUTO_WHITE_BALANCE,
0, 1, 1, 1);
ctrls->blue_balance = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_BLUE_BALANCE,
0, 0xff, 1, 0x80);
ctrls->red_balance = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_RED_BALANCE,
0, 0xff, 1, 0x80);
ctrls->auto_exp = v4l2_ctrl_new_std_menu(hdl, ops,
V4L2_CID_EXPOSURE_AUTO,
V4L2_EXPOSURE_MANUAL, 0, V4L2_EXPOSURE_AUTO);
ctrls->exposure = v4l2_ctrl_new_std(hdl, ops,
V4L2_CID_EXPOSURE_ABSOLUTE,
2, 1500, 1, 500);
ctrls->auto_gain = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_AUTOGAIN,
0, 1, 1, 1);
ctrls->gain = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_GAIN,
16, 64 * (16 + 15), 1, 64 * 16);
ctrls->saturation = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_SATURATION,
-2, 2, 1, 0);
ctrls->brightness = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_BRIGHTNESS,
-3, 3, 1, 0);
ctrls->sharpness = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_SHARPNESS,
0, 32, 1, 6);
ctrls->hflip = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_HFLIP, 0, 1, 1, 0);
ctrls->vflip = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_VFLIP, 0, 1, 1, 0);
ctrls->light_freq = v4l2_ctrl_new_std_menu(hdl, ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, ~0x7,
V4L2_CID_POWER_LINE_FREQUENCY_50HZ);
v4l2_ctrl_new_std_menu_items(hdl, ops, V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(test_pattern_menu) - 1, 0, 0,
test_pattern_menu);
if (hdl->error) {
ret = hdl->error;
v4l2_ctrl_handler_free(hdl);
return ret;
}
ctrls->gain->flags |= V4L2_CTRL_FLAG_VOLATILE;
ctrls->exposure->flags |= V4L2_CTRL_FLAG_VOLATILE;
v4l2_ctrl_auto_cluster(3, &ctrls->auto_wb, 0, false);
v4l2_ctrl_auto_cluster(2, &ctrls->auto_gain, 0, true);
v4l2_ctrl_auto_cluster(2, &ctrls->auto_exp, 1, true);
v4l2_ctrl_cluster(2, &ctrls->hflip);
ov965x->sd.ctrl_handler = hdl;
return 0;
}
static void ov965x_get_default_format(struct v4l2_mbus_framefmt *mf)
{
mf->width = ov965x_framesizes[0].width;
mf->height = ov965x_framesizes[0].height;
mf->colorspace = ov965x_formats[0].colorspace;
mf->code = ov965x_formats[0].code;
mf->field = V4L2_FIELD_NONE;
}
static int ov965x_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= ARRAY_SIZE(ov965x_formats))
return -EINVAL;
code->code = ov965x_formats[code->index].code;
return 0;
}
static int ov965x_enum_frame_sizes(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
int i = ARRAY_SIZE(ov965x_formats);
if (fse->index >= ARRAY_SIZE(ov965x_framesizes))
return -EINVAL;
while (--i)
if (fse->code == ov965x_formats[i].code)
break;
fse->code = ov965x_formats[i].code;
fse->min_width = ov965x_framesizes[fse->index].width;
fse->max_width = fse->min_width;
fse->max_height = ov965x_framesizes[fse->index].height;
fse->min_height = fse->max_height;
return 0;
}
static int ov965x_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct ov965x *ov965x = to_ov965x(sd);
mutex_lock(&ov965x->lock);
fi->interval = ov965x->fiv->interval;
mutex_unlock(&ov965x->lock);
return 0;
}
static int __ov965x_set_frame_interval(struct ov965x *ov965x,
struct v4l2_subdev_frame_interval *fi)
{
struct v4l2_mbus_framefmt *mbus_fmt = &ov965x->format;
const struct ov965x_interval *fiv = &ov965x_intervals[0];
u64 req_int, err, min_err = ~0ULL;
unsigned int i;
if (fi->interval.denominator == 0)
return -EINVAL;
req_int = (u64)(fi->interval.numerator * 10000) /
fi->interval.denominator;
for (i = 0; i < ARRAY_SIZE(ov965x_intervals); i++) {
const struct ov965x_interval *iv = &ov965x_intervals[i];
if (mbus_fmt->width != iv->size.width ||
mbus_fmt->height != iv->size.height)
continue;
err = abs((u64)(iv->interval.numerator * 10000) /
iv->interval.denominator - req_int);
if (err < min_err) {
fiv = iv;
min_err = err;
}
}
ov965x->fiv = fiv;
v4l2_dbg(1, debug, &ov965x->sd, "Changed frame interval to %u us\n",
fiv->interval.numerator * 1000000 / fiv->interval.denominator);
return 0;
}
static int ov965x_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct ov965x *ov965x = to_ov965x(sd);
int ret;
v4l2_dbg(1, debug, sd, "Setting %d/%d frame interval\n",
fi->interval.numerator, fi->interval.denominator);
mutex_lock(&ov965x->lock);
ret = __ov965x_set_frame_interval(ov965x, fi);
ov965x->apply_frame_fmt = 1;
mutex_unlock(&ov965x->lock);
return ret;
}
static int ov965x_get_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ov965x *ov965x = to_ov965x(sd);
struct v4l2_mbus_framefmt *mf;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
fmt->format = *mf;
return 0;
}
mutex_lock(&ov965x->lock);
fmt->format = ov965x->format;
mutex_unlock(&ov965x->lock);
return 0;
}
static void __ov965x_try_frame_size(struct v4l2_mbus_framefmt *mf,
const struct ov965x_framesize **size)
{
const struct ov965x_framesize *fsize = &ov965x_framesizes[0],
*match = NULL;
int i = ARRAY_SIZE(ov965x_framesizes);
unsigned int min_err = UINT_MAX;
while (i--) {
int err = abs(fsize->width - mf->width)
+ abs(fsize->height - mf->height);
if (err < min_err) {
min_err = err;
match = fsize;
}
fsize++;
}
if (!match)
match = &ov965x_framesizes[0];
mf->width = match->width;
mf->height = match->height;
if (size)
*size = match;
}
static int ov965x_set_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
unsigned int index = ARRAY_SIZE(ov965x_formats);
struct v4l2_mbus_framefmt *mf = &fmt->format;
struct ov965x *ov965x = to_ov965x(sd);
const struct ov965x_framesize *size = NULL;
int ret = 0;
__ov965x_try_frame_size(mf, &size);
while (--index)
if (ov965x_formats[index].code == mf->code)
break;
mf->colorspace = V4L2_COLORSPACE_JPEG;
mf->code = ov965x_formats[index].code;
mf->field = V4L2_FIELD_NONE;
mutex_lock(&ov965x->lock);
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
if (cfg != NULL) {
mf = v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
*mf = fmt->format;
}
} else {
if (ov965x->streaming) {
ret = -EBUSY;
} else {
ov965x->frame_size = size;
ov965x->format = fmt->format;
ov965x->tslb_reg = ov965x_formats[index].tslb_reg;
ov965x->apply_frame_fmt = 1;
}
}
if (!ret && fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
struct v4l2_subdev_frame_interval fiv = {
.interval = { 0, 1 }
};
__ov965x_set_frame_interval(ov965x, &fiv);
}
mutex_unlock(&ov965x->lock);
if (!ret)
ov965x_update_exposure_ctrl(ov965x);
return ret;
}
static int ov965x_set_frame_size(struct ov965x *ov965x)
{
int i, ret = 0;
for (i = 0; ret == 0 && i < NUM_FMT_REGS; i++)
ret = ov965x_write(ov965x->client, frame_size_reg_addr[i],
ov965x->frame_size->regs[i]);
return ret;
}
static int __ov965x_set_params(struct ov965x *ov965x)
{
struct i2c_client *client = ov965x->client;
struct ov965x_ctrls *ctrls = &ov965x->ctrls;
int ret = 0;
u8 reg;
if (ov965x->apply_frame_fmt) {
reg = DEF_CLKRC + ov965x->fiv->clkrc_div;
ret = ov965x_write(client, REG_CLKRC, reg);
if (ret < 0)
return ret;
ret = ov965x_set_frame_size(ov965x);
if (ret < 0)
return ret;
ret = ov965x_read(client, REG_TSLB, &reg);
if (ret < 0)
return ret;
reg &= ~TSLB_YUYV_MASK;
reg |= ov965x->tslb_reg;
ret = ov965x_write(client, REG_TSLB, reg);
if (ret < 0)
return ret;
}
ret = ov965x_set_default_gamma_curve(ov965x);
if (ret < 0)
return ret;
ret = ov965x_set_color_matrix(ov965x);
if (ret < 0)
return ret;
ret = ov965x_read(client, REG_COM11, &reg);
if (!ret)
reg |= COM11_BANDING;
ret = ov965x_write(client, REG_COM11, reg);
if (ret < 0)
return ret;
return ov965x_set_banding_filter(ov965x, ctrls->light_freq->val);
}
static int ov965x_s_stream(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov965x *ov965x = to_ov965x(sd);
struct ov965x_ctrls *ctrls = &ov965x->ctrls;
int ret = 0;
v4l2_dbg(1, debug, client, "%s: on: %d\n", __func__, on);
mutex_lock(&ov965x->lock);
if (ov965x->streaming == !on) {
if (on)
ret = __ov965x_set_params(ov965x);
if (!ret && ctrls->update) {
mutex_unlock(&ov965x->lock);
ret = v4l2_ctrl_handler_setup(&ctrls->handler);
mutex_lock(&ov965x->lock);
if (!ret)
ctrls->update = 0;
}
if (!ret)
ret = ov965x_write(client, REG_COM2,
on ? 0x01 : 0x11);
}
if (!ret)
ov965x->streaming += on ? 1 : -1;
WARN_ON(ov965x->streaming < 0);
mutex_unlock(&ov965x->lock);
return ret;
}
static int ov965x_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *mf = v4l2_subdev_get_try_format(sd, fh->pad, 0);
ov965x_get_default_format(mf);
return 0;
}
static int ov965x_configure_gpios(struct ov965x *ov965x,
const struct ov9650_platform_data *pdata)
{
int ret, i;
ov965x->gpios[GPIO_PWDN] = pdata->gpio_pwdn;
ov965x->gpios[GPIO_RST] = pdata->gpio_reset;
for (i = 0; i < ARRAY_SIZE(ov965x->gpios); i++) {
int gpio = ov965x->gpios[i];
if (!gpio_is_valid(gpio))
continue;
ret = devm_gpio_request_one(&ov965x->client->dev, gpio,
GPIOF_OUT_INIT_HIGH, "OV965X");
if (ret < 0)
return ret;
v4l2_dbg(1, debug, &ov965x->sd, "set gpio %d to 1\n", gpio);
gpio_set_value(gpio, 1);
gpio_export(gpio, 0);
ov965x->gpios[i] = gpio;
}
return 0;
}
static int ov965x_detect_sensor(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov965x *ov965x = to_ov965x(sd);
u8 pid, ver;
int ret;
mutex_lock(&ov965x->lock);
__ov965x_set_power(ov965x, 1);
msleep(25);
ret = ov965x_read(client, REG_PID, &pid);
if (!ret)
ret = ov965x_read(client, REG_VER, &ver);
__ov965x_set_power(ov965x, 0);
if (!ret) {
ov965x->id = OV965X_ID(pid, ver);
if (ov965x->id == OV9650_ID || ov965x->id == OV9652_ID) {
v4l2_info(sd, "Found OV%04X sensor\n", ov965x->id);
} else {
v4l2_err(sd, "Sensor detection failed (%04X, %d)\n",
ov965x->id, ret);
ret = -ENODEV;
}
}
mutex_unlock(&ov965x->lock);
return ret;
}
static int ov965x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct ov9650_platform_data *pdata = client->dev.platform_data;
struct v4l2_subdev *sd;
struct ov965x *ov965x;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "platform data not specified\n");
return -EINVAL;
}
if (pdata->mclk_frequency == 0) {
dev_err(&client->dev, "MCLK frequency not specified\n");
return -EINVAL;
}
ov965x = devm_kzalloc(&client->dev, sizeof(*ov965x), GFP_KERNEL);
if (!ov965x)
return -ENOMEM;
mutex_init(&ov965x->lock);
ov965x->client = client;
ov965x->mclk_frequency = pdata->mclk_frequency;
sd = &ov965x->sd;
v4l2_i2c_subdev_init(sd, client, &ov965x_subdev_ops);
strlcpy(sd->name, DRIVER_NAME, sizeof(sd->name));
sd->internal_ops = &ov965x_sd_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE |
V4L2_SUBDEV_FL_HAS_EVENTS;
ret = ov965x_configure_gpios(ov965x, pdata);
if (ret < 0)
return ret;
ov965x->pad.flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_CAM_SENSOR;
ret = media_entity_pads_init(&sd->entity, 1, &ov965x->pad);
if (ret < 0)
return ret;
ret = ov965x_initialize_controls(ov965x);
if (ret < 0)
goto err_me;
ov965x_get_default_format(&ov965x->format);
ov965x->frame_size = &ov965x_framesizes[0];
ov965x->fiv = &ov965x_intervals[0];
ret = ov965x_detect_sensor(sd);
if (ret < 0)
goto err_ctrls;
ov965x_update_exposure_ctrl(ov965x);
ret = v4l2_async_register_subdev(sd);
if (ret < 0)
goto err_ctrls;
return 0;
err_ctrls:
v4l2_ctrl_handler_free(sd->ctrl_handler);
err_me:
media_entity_cleanup(&sd->entity);
return ret;
}
static int ov965x_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_async_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
media_entity_cleanup(&sd->entity);
return 0;
}
