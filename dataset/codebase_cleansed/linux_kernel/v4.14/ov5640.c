static inline struct ov5640_dev *to_ov5640_dev(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov5640_dev, sd);
}
static inline struct v4l2_subdev *ctrl_to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct ov5640_dev,
ctrls.handler)->sd;
}
static int ov5640_init_slave_id(struct ov5640_dev *sensor)
{
struct i2c_client *client = sensor->i2c_client;
struct i2c_msg msg;
u8 buf[3];
int ret;
if (client->addr == OV5640_DEFAULT_SLAVE_ID)
return 0;
buf[0] = OV5640_REG_SLAVE_ID >> 8;
buf[1] = OV5640_REG_SLAVE_ID & 0xff;
buf[2] = client->addr << 1;
msg.addr = OV5640_DEFAULT_SLAVE_ID;
msg.flags = 0;
msg.buf = buf;
msg.len = sizeof(buf);
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
dev_err(&client->dev, "%s: failed with %d\n", __func__, ret);
return ret;
}
return 0;
}
static int ov5640_write_reg(struct ov5640_dev *sensor, u16 reg, u8 val)
{
struct i2c_client *client = sensor->i2c_client;
struct i2c_msg msg;
u8 buf[3];
int ret;
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
buf[2] = val;
msg.addr = client->addr;
msg.flags = client->flags;
msg.buf = buf;
msg.len = sizeof(buf);
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
v4l2_err(&sensor->sd, "%s: error: reg=%x, val=%x\n",
__func__, reg, val);
return ret;
}
return 0;
}
static int ov5640_read_reg(struct ov5640_dev *sensor, u16 reg, u8 *val)
{
struct i2c_client *client = sensor->i2c_client;
struct i2c_msg msg[2];
u8 buf[2];
int ret;
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
msg[0].addr = client->addr;
msg[0].flags = client->flags;
msg[0].buf = buf;
msg[0].len = sizeof(buf);
msg[1].addr = client->addr;
msg[1].flags = client->flags | I2C_M_RD;
msg[1].buf = buf;
msg[1].len = 1;
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0)
return ret;
*val = buf[0];
return 0;
}
static int ov5640_read_reg16(struct ov5640_dev *sensor, u16 reg, u16 *val)
{
u8 hi, lo;
int ret;
ret = ov5640_read_reg(sensor, reg, &hi);
if (ret)
return ret;
ret = ov5640_read_reg(sensor, reg+1, &lo);
if (ret)
return ret;
*val = ((u16)hi << 8) | (u16)lo;
return 0;
}
static int ov5640_write_reg16(struct ov5640_dev *sensor, u16 reg, u16 val)
{
int ret;
ret = ov5640_write_reg(sensor, reg, val >> 8);
if (ret)
return ret;
return ov5640_write_reg(sensor, reg + 1, val & 0xff);
}
static int ov5640_mod_reg(struct ov5640_dev *sensor, u16 reg,
u8 mask, u8 val)
{
u8 readval;
int ret;
ret = ov5640_read_reg(sensor, reg, &readval);
if (ret)
return ret;
readval &= ~mask;
val &= mask;
val |= readval;
return ov5640_write_reg(sensor, reg, val);
}
static int ov5640_load_regs(struct ov5640_dev *sensor,
const struct ov5640_mode_info *mode)
{
const struct reg_value *regs = mode->reg_data;
unsigned int i;
u32 delay_ms;
u16 reg_addr;
u8 mask, val;
int ret = 0;
for (i = 0; i < mode->reg_data_size; ++i, ++regs) {
delay_ms = regs->delay_ms;
reg_addr = regs->reg_addr;
val = regs->val;
mask = regs->mask;
if (mask)
ret = ov5640_mod_reg(sensor, reg_addr, mask, val);
else
ret = ov5640_write_reg(sensor, reg_addr, val);
if (ret)
break;
if (delay_ms)
usleep_range(1000*delay_ms, 1000*delay_ms+100);
}
return ret;
}
static int ov5640_get_exposure(struct ov5640_dev *sensor)
{
int exp, ret;
u8 temp;
ret = ov5640_read_reg(sensor, OV5640_REG_AEC_PK_EXPOSURE_HI, &temp);
if (ret)
return ret;
exp = ((int)temp & 0x0f) << 16;
ret = ov5640_read_reg(sensor, OV5640_REG_AEC_PK_EXPOSURE_MED, &temp);
if (ret)
return ret;
exp |= ((int)temp << 8);
ret = ov5640_read_reg(sensor, OV5640_REG_AEC_PK_EXPOSURE_LO, &temp);
if (ret)
return ret;
exp |= (int)temp;
return exp >> 4;
}
static int ov5640_set_exposure(struct ov5640_dev *sensor, u32 exposure)
{
int ret;
exposure <<= 4;
ret = ov5640_write_reg(sensor,
OV5640_REG_AEC_PK_EXPOSURE_LO,
exposure & 0xff);
if (ret)
return ret;
ret = ov5640_write_reg(sensor,
OV5640_REG_AEC_PK_EXPOSURE_MED,
(exposure >> 8) & 0xff);
if (ret)
return ret;
return ov5640_write_reg(sensor,
OV5640_REG_AEC_PK_EXPOSURE_HI,
(exposure >> 16) & 0x0f);
}
static int ov5640_get_gain(struct ov5640_dev *sensor)
{
u16 gain;
int ret;
ret = ov5640_read_reg16(sensor, OV5640_REG_AEC_PK_REAL_GAIN, &gain);
if (ret)
return ret;
return gain & 0x3ff;
}
static int ov5640_set_stream(struct ov5640_dev *sensor, bool on)
{
int ret;
ret = ov5640_mod_reg(sensor, OV5640_REG_MIPI_CTRL00, BIT(5),
on ? 0 : BIT(5));
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_PAD_OUTPUT00,
on ? 0x00 : 0x70);
if (ret)
return ret;
return ov5640_write_reg(sensor, OV5640_REG_FRAME_CTRL01,
on ? 0x00 : 0x0f);
}
static int ov5640_get_sysclk(struct ov5640_dev *sensor)
{
u32 xvclk = sensor->xclk_freq / 10000;
u32 multiplier, prediv, VCO, sysdiv, pll_rdiv;
u32 sclk_rdiv_map[] = {1, 2, 4, 8};
u32 bit_div2x = 1, sclk_rdiv, sysclk;
u8 temp1, temp2;
int ret;
ret = ov5640_read_reg(sensor, OV5640_REG_SC_PLL_CTRL0, &temp1);
if (ret)
return ret;
temp2 = temp1 & 0x0f;
if (temp2 == 8 || temp2 == 10)
bit_div2x = temp2 / 2;
ret = ov5640_read_reg(sensor, OV5640_REG_SC_PLL_CTRL1, &temp1);
if (ret)
return ret;
sysdiv = temp1 >> 4;
if (sysdiv == 0)
sysdiv = 16;
ret = ov5640_read_reg(sensor, OV5640_REG_SC_PLL_CTRL2, &temp1);
if (ret)
return ret;
multiplier = temp1;
ret = ov5640_read_reg(sensor, OV5640_REG_SC_PLL_CTRL3, &temp1);
if (ret)
return ret;
prediv = temp1 & 0x0f;
pll_rdiv = ((temp1 >> 4) & 0x01) + 1;
ret = ov5640_read_reg(sensor, OV5640_REG_SYS_ROOT_DIVIDER, &temp1);
if (ret)
return ret;
temp2 = temp1 & 0x03;
sclk_rdiv = sclk_rdiv_map[temp2];
if (!prediv || !sysdiv || !pll_rdiv || !bit_div2x)
return -EINVAL;
VCO = xvclk * multiplier / prediv;
sysclk = VCO / sysdiv / pll_rdiv * 2 / bit_div2x / sclk_rdiv;
return sysclk;
}
static int ov5640_set_night_mode(struct ov5640_dev *sensor)
{
u8 mode;
int ret;
ret = ov5640_read_reg(sensor, OV5640_REG_AEC_CTRL00, &mode);
if (ret)
return ret;
mode &= 0xfb;
return ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL00, mode);
}
static int ov5640_get_hts(struct ov5640_dev *sensor)
{
u16 hts;
int ret;
ret = ov5640_read_reg16(sensor, OV5640_REG_TIMING_HTS, &hts);
if (ret)
return ret;
return hts;
}
static int ov5640_get_vts(struct ov5640_dev *sensor)
{
u16 vts;
int ret;
ret = ov5640_read_reg16(sensor, OV5640_REG_TIMING_VTS, &vts);
if (ret)
return ret;
return vts;
}
static int ov5640_set_vts(struct ov5640_dev *sensor, int vts)
{
return ov5640_write_reg16(sensor, OV5640_REG_TIMING_VTS, vts);
}
static int ov5640_get_light_freq(struct ov5640_dev *sensor)
{
int ret, light_freq = 0;
u8 temp, temp1;
ret = ov5640_read_reg(sensor, OV5640_REG_HZ5060_CTRL01, &temp);
if (ret)
return ret;
if (temp & 0x80) {
ret = ov5640_read_reg(sensor, OV5640_REG_HZ5060_CTRL00,
&temp1);
if (ret)
return ret;
if (temp1 & 0x04) {
light_freq = 50;
} else {
light_freq = 60;
}
} else {
ret = ov5640_read_reg(sensor, OV5640_REG_SIGMADELTA_CTRL0C,
&temp1);
if (ret)
return ret;
if (temp1 & 0x01) {
light_freq = 50;
} else {
}
}
return light_freq;
}
static int ov5640_set_bandingfilter(struct ov5640_dev *sensor)
{
u32 band_step60, max_band60, band_step50, max_band50, prev_vts;
int ret;
ret = ov5640_get_sysclk(sensor);
if (ret < 0)
return ret;
if (ret == 0)
return -EINVAL;
sensor->prev_sysclk = ret;
ret = ov5640_get_hts(sensor);
if (ret < 0)
return ret;
if (ret == 0)
return -EINVAL;
sensor->prev_hts = ret;
ret = ov5640_get_vts(sensor);
if (ret < 0)
return ret;
prev_vts = ret;
band_step60 = sensor->prev_sysclk * 100 / sensor->prev_hts * 100 / 120;
ret = ov5640_write_reg16(sensor, OV5640_REG_AEC_B60_STEP, band_step60);
if (ret)
return ret;
if (!band_step60)
return -EINVAL;
max_band60 = (int)((prev_vts - 4) / band_step60);
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL0D, max_band60);
if (ret)
return ret;
band_step50 = sensor->prev_sysclk * 100 / sensor->prev_hts;
ret = ov5640_write_reg16(sensor, OV5640_REG_AEC_B50_STEP, band_step50);
if (ret)
return ret;
if (!band_step50)
return -EINVAL;
max_band50 = (int)((prev_vts - 4) / band_step50);
return ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL0E, max_band50);
}
static int ov5640_set_ae_target(struct ov5640_dev *sensor, int target)
{
u32 fast_high, fast_low;
int ret;
sensor->ae_low = target * 23 / 25;
sensor->ae_high = target * 27 / 25;
fast_high = sensor->ae_high << 1;
if (fast_high > 255)
fast_high = 255;
fast_low = sensor->ae_low >> 1;
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL0F, sensor->ae_high);
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL10, sensor->ae_low);
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL1B, sensor->ae_high);
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL1E, sensor->ae_low);
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL11, fast_high);
if (ret)
return ret;
return ov5640_write_reg(sensor, OV5640_REG_AEC_CTRL1F, fast_low);
}
static int ov5640_binning_on(struct ov5640_dev *sensor)
{
u8 temp;
int ret;
ret = ov5640_read_reg(sensor, OV5640_REG_TIMING_TC_REG21, &temp);
if (ret)
return ret;
temp &= 0xfe;
return temp ? 1 : 0;
}
static int ov5640_set_virtual_channel(struct ov5640_dev *sensor)
{
u8 temp, channel = virtual_channel;
int ret;
if (channel > 3)
return -EINVAL;
ret = ov5640_read_reg(sensor, OV5640_REG_DEBUG_MODE, &temp);
if (ret)
return ret;
temp &= ~(3 << 6);
temp |= (channel << 6);
return ov5640_write_reg(sensor, OV5640_REG_DEBUG_MODE, temp);
}
static const struct ov5640_mode_info *
ov5640_find_mode(struct ov5640_dev *sensor, enum ov5640_frame_rate fr,
int width, int height, bool nearest)
{
const struct ov5640_mode_info *mode = NULL;
int i;
for (i = OV5640_NUM_MODES - 1; i >= 0; i--) {
mode = &ov5640_mode_data[fr][i];
if (!mode->reg_data)
continue;
if ((nearest && mode->width <= width &&
mode->height <= height) ||
(!nearest && mode->width == width &&
mode->height == height))
break;
}
if (nearest && i < 0)
mode = &ov5640_mode_data[fr][0];
return mode;
}
static int ov5640_set_mode_exposure_calc(
struct ov5640_dev *sensor, const struct ov5640_mode_info *mode)
{
u32 prev_shutter, prev_gain16;
u32 cap_shutter, cap_gain16;
u32 cap_sysclk, cap_hts, cap_vts;
u32 light_freq, cap_bandfilt, cap_maxband;
u32 cap_gain16_shutter;
u8 average;
int ret;
if (mode->reg_data == NULL)
return -EINVAL;
ret = ov5640_get_exposure(sensor);
if (ret < 0)
return ret;
prev_shutter = ret;
ret = ov5640_binning_on(sensor);
if (ret < 0)
return ret;
if (ret && mode->id != OV5640_MODE_720P_1280_720 &&
mode->id != OV5640_MODE_1080P_1920_1080)
prev_shutter *= 2;
ret = ov5640_get_gain(sensor);
if (ret < 0)
return ret;
prev_gain16 = ret;
ret = ov5640_read_reg(sensor, OV5640_REG_AVG_READOUT, &average);
if (ret)
return ret;
ret = ov5640_set_night_mode(sensor);
if (ret < 0)
return ret;
ret = ov5640_load_regs(sensor, mode);
if (ret < 0)
return ret;
ret = ov5640_get_vts(sensor);
if (ret < 0)
return ret;
cap_vts = ret;
ret = ov5640_get_hts(sensor);
if (ret < 0)
return ret;
if (ret == 0)
return -EINVAL;
cap_hts = ret;
ret = ov5640_get_sysclk(sensor);
if (ret < 0)
return ret;
if (ret == 0)
return -EINVAL;
cap_sysclk = ret;
ret = ov5640_get_light_freq(sensor);
if (ret < 0)
return ret;
light_freq = ret;
if (light_freq == 60) {
cap_bandfilt = cap_sysclk * 100 / cap_hts * 100 / 120;
} else {
cap_bandfilt = cap_sysclk * 100 / cap_hts;
}
if (!sensor->prev_sysclk) {
ret = ov5640_get_sysclk(sensor);
if (ret < 0)
return ret;
if (ret == 0)
return -EINVAL;
sensor->prev_sysclk = ret;
}
if (!cap_bandfilt)
return -EINVAL;
cap_maxband = (int)((cap_vts - 4) / cap_bandfilt);
if (average > sensor->ae_low && average < sensor->ae_high) {
cap_gain16_shutter =
prev_gain16 * prev_shutter *
cap_sysclk / sensor->prev_sysclk *
sensor->prev_hts / cap_hts *
sensor->ae_target / average;
} else {
cap_gain16_shutter =
prev_gain16 * prev_shutter *
cap_sysclk / sensor->prev_sysclk *
sensor->prev_hts / cap_hts;
}
if (cap_gain16_shutter < (cap_bandfilt * 16)) {
cap_shutter = cap_gain16_shutter / 16;
if (cap_shutter < 1)
cap_shutter = 1;
cap_gain16 = cap_gain16_shutter / cap_shutter;
if (cap_gain16 < 16)
cap_gain16 = 16;
} else {
if (cap_gain16_shutter > (cap_bandfilt * cap_maxband * 16)) {
cap_shutter = cap_bandfilt * cap_maxband;
if (!cap_shutter)
return -EINVAL;
cap_gain16 = cap_gain16_shutter / cap_shutter;
} else {
cap_shutter =
((int)(cap_gain16_shutter / 16 / cap_bandfilt))
* cap_bandfilt;
if (!cap_shutter)
return -EINVAL;
cap_gain16 = cap_gain16_shutter / cap_shutter;
}
}
ret = __v4l2_ctrl_s_ctrl(sensor->ctrls.gain, cap_gain16);
if (ret)
return ret;
if (cap_shutter > (cap_vts - 4)) {
cap_vts = cap_shutter + 4;
ret = ov5640_set_vts(sensor, cap_vts);
if (ret < 0)
return ret;
}
return __v4l2_ctrl_s_ctrl(sensor->ctrls.exposure, cap_shutter);
}
static int ov5640_set_mode_direct(struct ov5640_dev *sensor,
const struct ov5640_mode_info *mode)
{
int ret;
if (mode->reg_data == NULL)
return -EINVAL;
ret = ov5640_load_regs(sensor, mode);
if (ret < 0)
return ret;
ret = __v4l2_ctrl_s_ctrl(sensor->ctrls.auto_gain, 1);
if (ret)
return ret;
return __v4l2_ctrl_s_ctrl(sensor->ctrls.auto_exp, V4L2_EXPOSURE_AUTO);
}
static int ov5640_set_mode(struct ov5640_dev *sensor,
const struct ov5640_mode_info *orig_mode)
{
const struct ov5640_mode_info *mode = sensor->current_mode;
enum ov5640_downsize_mode dn_mode, orig_dn_mode;
int ret;
dn_mode = mode->dn_mode;
orig_dn_mode = orig_mode->dn_mode;
ret = __v4l2_ctrl_s_ctrl(sensor->ctrls.auto_gain, 0);
if (ret)
return ret;
ret = __v4l2_ctrl_s_ctrl(sensor->ctrls.auto_exp, V4L2_EXPOSURE_MANUAL);
if (ret)
return ret;
if ((dn_mode == SUBSAMPLING && orig_dn_mode == SCALING) ||
(dn_mode == SCALING && orig_dn_mode == SUBSAMPLING)) {
ret = ov5640_set_mode_exposure_calc(sensor, mode);
} else {
ret = ov5640_set_mode_direct(sensor, mode);
}
if (ret < 0)
return ret;
ret = ov5640_set_ae_target(sensor, sensor->ae_target);
if (ret < 0)
return ret;
ret = ov5640_get_light_freq(sensor);
if (ret < 0)
return ret;
ret = ov5640_set_bandingfilter(sensor);
if (ret < 0)
return ret;
ret = ov5640_set_virtual_channel(sensor);
if (ret < 0)
return ret;
sensor->pending_mode_change = false;
return 0;
}
static int ov5640_restore_mode(struct ov5640_dev *sensor)
{
int ret;
ret = ov5640_load_regs(sensor, &ov5640_mode_init_data);
if (ret < 0)
return ret;
return ov5640_set_mode(sensor, &ov5640_mode_init_data);
}
static void ov5640_power(struct ov5640_dev *sensor, bool enable)
{
gpiod_set_value(sensor->pwdn_gpio, enable ? 0 : 1);
}
static void ov5640_reset(struct ov5640_dev *sensor)
{
if (!sensor->reset_gpio)
return;
gpiod_set_value(sensor->reset_gpio, 0);
ov5640_power(sensor, false);
usleep_range(5000, 10000);
ov5640_power(sensor, true);
usleep_range(5000, 10000);
gpiod_set_value(sensor->reset_gpio, 1);
usleep_range(1000, 2000);
gpiod_set_value(sensor->reset_gpio, 0);
usleep_range(5000, 10000);
}
static int ov5640_set_power(struct ov5640_dev *sensor, bool on)
{
int ret = 0;
if (on) {
clk_prepare_enable(sensor->xclk);
ret = regulator_bulk_enable(OV5640_NUM_SUPPLIES,
sensor->supplies);
if (ret)
goto xclk_off;
ov5640_reset(sensor);
ov5640_power(sensor, true);
ret = ov5640_init_slave_id(sensor);
if (ret)
goto power_off;
ret = ov5640_restore_mode(sensor);
if (ret)
goto power_off;
ret = ov5640_set_stream(sensor, true);
if (ret)
goto power_off;
usleep_range(1000, 2000);
ret = ov5640_set_stream(sensor, false);
if (ret)
goto power_off;
return 0;
}
power_off:
ov5640_power(sensor, false);
regulator_bulk_disable(OV5640_NUM_SUPPLIES, sensor->supplies);
xclk_off:
clk_disable_unprepare(sensor->xclk);
return ret;
}
static int ov5640_s_power(struct v4l2_subdev *sd, int on)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
int ret = 0;
mutex_lock(&sensor->lock);
if (sensor->power_count == !on) {
ret = ov5640_set_power(sensor, !!on);
if (ret)
goto out;
}
sensor->power_count += on ? 1 : -1;
WARN_ON(sensor->power_count < 0);
out:
mutex_unlock(&sensor->lock);
if (on && !ret && sensor->power_count == 1) {
ret = v4l2_ctrl_handler_setup(&sensor->ctrls.handler);
}
return ret;
}
static int ov5640_try_frame_interval(struct ov5640_dev *sensor,
struct v4l2_fract *fi,
u32 width, u32 height)
{
const struct ov5640_mode_info *mode;
u32 minfps, maxfps, fps;
int ret;
minfps = ov5640_framerates[OV5640_15_FPS];
maxfps = ov5640_framerates[OV5640_30_FPS];
if (fi->numerator == 0) {
fi->denominator = maxfps;
fi->numerator = 1;
return OV5640_30_FPS;
}
fps = DIV_ROUND_CLOSEST(fi->denominator, fi->numerator);
fi->numerator = 1;
if (fps > maxfps)
fi->denominator = maxfps;
else if (fps < minfps)
fi->denominator = minfps;
else if (2 * fps >= 2 * minfps + (maxfps - minfps))
fi->denominator = maxfps;
else
fi->denominator = minfps;
ret = (fi->denominator == minfps) ? OV5640_15_FPS : OV5640_30_FPS;
mode = ov5640_find_mode(sensor, ret, width, height, false);
return mode ? ret : -EINVAL;
}
static int ov5640_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
struct v4l2_mbus_framefmt *fmt;
if (format->pad != 0)
return -EINVAL;
mutex_lock(&sensor->lock);
if (format->which == V4L2_SUBDEV_FORMAT_TRY)
fmt = v4l2_subdev_get_try_format(&sensor->sd, cfg,
format->pad);
else
fmt = &sensor->fmt;
format->format = *fmt;
mutex_unlock(&sensor->lock);
return 0;
}
static int ov5640_try_fmt_internal(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt,
enum ov5640_frame_rate fr,
const struct ov5640_mode_info **new_mode)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
const struct ov5640_mode_info *mode;
mode = ov5640_find_mode(sensor, fr, fmt->width, fmt->height, true);
if (!mode)
return -EINVAL;
fmt->width = mode->width;
fmt->height = mode->height;
fmt->code = sensor->fmt.code;
if (new_mode)
*new_mode = mode;
return 0;
}
static int ov5640_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
const struct ov5640_mode_info *new_mode;
int ret;
if (format->pad != 0)
return -EINVAL;
mutex_lock(&sensor->lock);
if (sensor->streaming) {
ret = -EBUSY;
goto out;
}
ret = ov5640_try_fmt_internal(sd, &format->format,
sensor->current_fr, &new_mode);
if (ret)
goto out;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
struct v4l2_mbus_framefmt *fmt =
v4l2_subdev_get_try_format(sd, cfg, 0);
*fmt = format->format;
goto out;
}
sensor->current_mode = new_mode;
sensor->fmt = format->format;
sensor->pending_mode_change = true;
out:
mutex_unlock(&sensor->lock);
return ret;
}
static int ov5640_set_ctrl_hue(struct ov5640_dev *sensor, int value)
{
int ret;
if (value) {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0,
BIT(0), BIT(0));
if (ret)
return ret;
ret = ov5640_write_reg16(sensor, OV5640_REG_SDE_CTRL1, value);
} else {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0, BIT(0), 0);
}
return ret;
}
static int ov5640_set_ctrl_contrast(struct ov5640_dev *sensor, int value)
{
int ret;
if (value) {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0,
BIT(2), BIT(2));
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_SDE_CTRL5,
value & 0xff);
} else {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0, BIT(2), 0);
}
return ret;
}
static int ov5640_set_ctrl_saturation(struct ov5640_dev *sensor, int value)
{
int ret;
if (value) {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0,
BIT(1), BIT(1));
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_SDE_CTRL3,
value & 0xff);
if (ret)
return ret;
ret = ov5640_write_reg(sensor, OV5640_REG_SDE_CTRL4,
value & 0xff);
} else {
ret = ov5640_mod_reg(sensor, OV5640_REG_SDE_CTRL0, BIT(1), 0);
}
return ret;
}
static int ov5640_set_ctrl_white_balance(struct ov5640_dev *sensor, int awb)
{
int ret;
ret = ov5640_mod_reg(sensor, OV5640_REG_AWB_MANUAL_CTRL,
BIT(0), awb ? 0 : 1);
if (ret)
return ret;
if (!awb) {
u16 red = (u16)sensor->ctrls.red_balance->val;
u16 blue = (u16)sensor->ctrls.blue_balance->val;
ret = ov5640_write_reg16(sensor, OV5640_REG_AWB_R_GAIN, red);
if (ret)
return ret;
ret = ov5640_write_reg16(sensor, OV5640_REG_AWB_B_GAIN, blue);
}
return ret;
}
static int ov5640_set_ctrl_exposure(struct ov5640_dev *sensor, int exp)
{
struct ov5640_ctrls *ctrls = &sensor->ctrls;
bool auto_exposure = (exp == V4L2_EXPOSURE_AUTO);
int ret = 0;
if (ctrls->auto_exp->is_new) {
ret = ov5640_mod_reg(sensor, OV5640_REG_AEC_PK_MANUAL,
BIT(0), auto_exposure ? 0 : BIT(0));
if (ret)
return ret;
}
if (!auto_exposure && ctrls->exposure->is_new) {
u16 max_exp;
ret = ov5640_read_reg16(sensor, OV5640_REG_AEC_PK_VTS,
&max_exp);
if (ret)
return ret;
ret = ov5640_get_vts(sensor);
if (ret < 0)
return ret;
max_exp += ret;
if (ctrls->exposure->val < max_exp)
ret = ov5640_set_exposure(sensor, ctrls->exposure->val);
}
return ret;
}
static int ov5640_set_ctrl_gain(struct ov5640_dev *sensor, int auto_gain)
{
struct ov5640_ctrls *ctrls = &sensor->ctrls;
int ret = 0;
if (ctrls->auto_gain->is_new) {
ret = ov5640_mod_reg(sensor, OV5640_REG_AEC_PK_MANUAL,
BIT(1), ctrls->auto_gain->val ? 0 : BIT(1));
if (ret)
return ret;
}
if (!auto_gain && ctrls->gain->is_new) {
u16 gain = (u16)ctrls->gain->val;
ret = ov5640_write_reg16(sensor, OV5640_REG_AEC_PK_REAL_GAIN,
gain & 0x3ff);
}
return ret;
}
static int ov5640_set_ctrl_test_pattern(struct ov5640_dev *sensor, int value)
{
return ov5640_mod_reg(sensor, OV5640_REG_PRE_ISP_TEST_SET1,
0xa4, value ? 0xa4 : 0);
}
static int ov5640_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = ctrl_to_sd(ctrl);
struct ov5640_dev *sensor = to_ov5640_dev(sd);
int val;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
if (!ctrl->val)
return 0;
val = ov5640_get_gain(sensor);
if (val < 0)
return val;
sensor->ctrls.gain->val = val;
break;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->val == V4L2_EXPOSURE_MANUAL)
return 0;
val = ov5640_get_exposure(sensor);
if (val < 0)
return val;
sensor->ctrls.exposure->val = val;
break;
}
return 0;
}
static int ov5640_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = ctrl_to_sd(ctrl);
struct ov5640_dev *sensor = to_ov5640_dev(sd);
int ret;
if (sensor->power_count == 0)
return 0;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
ret = ov5640_set_ctrl_gain(sensor, ctrl->val);
break;
case V4L2_CID_EXPOSURE_AUTO:
ret = ov5640_set_ctrl_exposure(sensor, ctrl->val);
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = ov5640_set_ctrl_white_balance(sensor, ctrl->val);
break;
case V4L2_CID_HUE:
ret = ov5640_set_ctrl_hue(sensor, ctrl->val);
break;
case V4L2_CID_CONTRAST:
ret = ov5640_set_ctrl_contrast(sensor, ctrl->val);
break;
case V4L2_CID_SATURATION:
ret = ov5640_set_ctrl_saturation(sensor, ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
ret = ov5640_set_ctrl_test_pattern(sensor, ctrl->val);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int ov5640_init_controls(struct ov5640_dev *sensor)
{
const struct v4l2_ctrl_ops *ops = &ov5640_ctrl_ops;
struct ov5640_ctrls *ctrls = &sensor->ctrls;
struct v4l2_ctrl_handler *hdl = &ctrls->handler;
int ret;
v4l2_ctrl_handler_init(hdl, 32);
hdl->lock = &sensor->lock;
ctrls->auto_wb = v4l2_ctrl_new_std(hdl, ops,
V4L2_CID_AUTO_WHITE_BALANCE,
0, 1, 1, 1);
ctrls->blue_balance = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_BLUE_BALANCE,
0, 4095, 1, 0);
ctrls->red_balance = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_RED_BALANCE,
0, 4095, 1, 0);
ctrls->auto_exp = v4l2_ctrl_new_std_menu(hdl, ops,
V4L2_CID_EXPOSURE_AUTO,
V4L2_EXPOSURE_MANUAL, 0,
V4L2_EXPOSURE_AUTO);
ctrls->exposure = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_EXPOSURE,
0, 65535, 1, 0);
ctrls->auto_gain = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_AUTOGAIN,
0, 1, 1, 1);
ctrls->gain = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_GAIN,
0, 1023, 1, 0);
ctrls->saturation = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_SATURATION,
0, 255, 1, 64);
ctrls->hue = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_HUE,
0, 359, 1, 0);
ctrls->contrast = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_CONTRAST,
0, 255, 1, 0);
ctrls->test_pattern =
v4l2_ctrl_new_std_menu_items(hdl, ops, V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(test_pattern_menu) - 1,
0, 0, test_pattern_menu);
if (hdl->error) {
ret = hdl->error;
goto free_ctrls;
}
ctrls->gain->flags |= V4L2_CTRL_FLAG_VOLATILE;
ctrls->exposure->flags |= V4L2_CTRL_FLAG_VOLATILE;
v4l2_ctrl_auto_cluster(3, &ctrls->auto_wb, 0, false);
v4l2_ctrl_auto_cluster(2, &ctrls->auto_gain, 0, true);
v4l2_ctrl_auto_cluster(2, &ctrls->auto_exp, 1, true);
sensor->sd.ctrl_handler = hdl;
return 0;
free_ctrls:
v4l2_ctrl_handler_free(hdl);
return ret;
}
static int ov5640_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->pad != 0)
return -EINVAL;
if (fse->index >= OV5640_NUM_MODES)
return -EINVAL;
fse->min_width = fse->max_width =
ov5640_mode_data[0][fse->index].width;
fse->min_height = fse->max_height =
ov5640_mode_data[0][fse->index].height;
return 0;
}
static int ov5640_enum_frame_interval(
struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_interval_enum *fie)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
struct v4l2_fract tpf;
int ret;
if (fie->pad != 0)
return -EINVAL;
if (fie->index >= OV5640_NUM_FRAMERATES)
return -EINVAL;
tpf.numerator = 1;
tpf.denominator = ov5640_framerates[fie->index];
ret = ov5640_try_frame_interval(sensor, &tpf,
fie->width, fie->height);
if (ret < 0)
return -EINVAL;
fie->interval = tpf;
return 0;
}
static int ov5640_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
mutex_lock(&sensor->lock);
fi->interval = sensor->frame_interval;
mutex_unlock(&sensor->lock);
return 0;
}
static int ov5640_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
const struct ov5640_mode_info *mode;
int frame_rate, ret = 0;
if (fi->pad != 0)
return -EINVAL;
mutex_lock(&sensor->lock);
if (sensor->streaming) {
ret = -EBUSY;
goto out;
}
mode = sensor->current_mode;
frame_rate = ov5640_try_frame_interval(sensor, &fi->interval,
mode->width, mode->height);
if (frame_rate < 0)
frame_rate = OV5640_15_FPS;
sensor->current_fr = frame_rate;
sensor->frame_interval = fi->interval;
sensor->pending_mode_change = true;
out:
mutex_unlock(&sensor->lock);
return ret;
}
static int ov5640_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
if (code->pad != 0)
return -EINVAL;
if (code->index != 0)
return -EINVAL;
code->code = sensor->fmt.code;
return 0;
}
static int ov5640_s_stream(struct v4l2_subdev *sd, int enable)
{
struct ov5640_dev *sensor = to_ov5640_dev(sd);
int ret = 0;
mutex_lock(&sensor->lock);
if (sensor->streaming == !enable) {
if (enable && sensor->pending_mode_change) {
ret = ov5640_set_mode(sensor, sensor->current_mode);
if (ret)
goto out;
}
ret = ov5640_set_stream(sensor, enable);
if (!ret)
sensor->streaming = enable;
}
out:
mutex_unlock(&sensor->lock);
return ret;
}
static int ov5640_get_regulators(struct ov5640_dev *sensor)
{
int i;
for (i = 0; i < OV5640_NUM_SUPPLIES; i++)
sensor->supplies[i].supply = ov5640_supply_name[i];
return devm_regulator_bulk_get(&sensor->i2c_client->dev,
OV5640_NUM_SUPPLIES,
sensor->supplies);
}
static int ov5640_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct fwnode_handle *endpoint;
struct ov5640_dev *sensor;
int ret;
sensor = devm_kzalloc(dev, sizeof(*sensor), GFP_KERNEL);
if (!sensor)
return -ENOMEM;
sensor->i2c_client = client;
sensor->fmt.code = MEDIA_BUS_FMT_UYVY8_2X8;
sensor->fmt.width = 640;
sensor->fmt.height = 480;
sensor->fmt.field = V4L2_FIELD_NONE;
sensor->frame_interval.numerator = 1;
sensor->frame_interval.denominator = ov5640_framerates[OV5640_30_FPS];
sensor->current_fr = OV5640_30_FPS;
sensor->current_mode =
&ov5640_mode_data[OV5640_30_FPS][OV5640_MODE_VGA_640_480];
sensor->pending_mode_change = true;
sensor->ae_target = 52;
endpoint = fwnode_graph_get_next_endpoint(
of_fwnode_handle(client->dev.of_node), NULL);
if (!endpoint) {
dev_err(dev, "endpoint node not found\n");
return -EINVAL;
}
ret = v4l2_fwnode_endpoint_parse(endpoint, &sensor->ep);
fwnode_handle_put(endpoint);
if (ret) {
dev_err(dev, "Could not parse endpoint\n");
return ret;
}
if (sensor->ep.bus_type != V4L2_MBUS_CSI2) {
dev_err(dev, "invalid bus type, must be MIPI CSI2\n");
return -EINVAL;
}
sensor->xclk = devm_clk_get(dev, "xclk");
if (IS_ERR(sensor->xclk)) {
dev_err(dev, "failed to get xclk\n");
return PTR_ERR(sensor->xclk);
}
sensor->xclk_freq = clk_get_rate(sensor->xclk);
if (sensor->xclk_freq < OV5640_XCLK_MIN ||
sensor->xclk_freq > OV5640_XCLK_MAX) {
dev_err(dev, "xclk frequency out of range: %d Hz\n",
sensor->xclk_freq);
return -EINVAL;
}
sensor->pwdn_gpio = devm_gpiod_get_optional(dev, "powerdown",
GPIOD_OUT_HIGH);
sensor->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_HIGH);
v4l2_i2c_subdev_init(&sensor->sd, client, &ov5640_subdev_ops);
sensor->sd.flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
sensor->pad.flags = MEDIA_PAD_FL_SOURCE;
sensor->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
ret = media_entity_pads_init(&sensor->sd.entity, 1, &sensor->pad);
if (ret)
return ret;
ret = ov5640_get_regulators(sensor);
if (ret)
return ret;
mutex_init(&sensor->lock);
ret = ov5640_init_controls(sensor);
if (ret)
goto entity_cleanup;
ret = v4l2_async_register_subdev(&sensor->sd);
if (ret)
goto free_ctrls;
return 0;
free_ctrls:
v4l2_ctrl_handler_free(&sensor->ctrls.handler);
entity_cleanup:
mutex_destroy(&sensor->lock);
media_entity_cleanup(&sensor->sd.entity);
return ret;
}
static int ov5640_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5640_dev *sensor = to_ov5640_dev(sd);
v4l2_async_unregister_subdev(&sensor->sd);
mutex_destroy(&sensor->lock);
media_entity_cleanup(&sensor->sd.entity);
v4l2_ctrl_handler_free(&sensor->ctrls.handler);
return 0;
}
