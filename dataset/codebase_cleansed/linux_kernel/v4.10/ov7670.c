static inline struct ov7670_info *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov7670_info, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct ov7670_info, hdl)->sd;
}
static int ov7670_read_smbus(struct v4l2_subdev *sd, unsigned char reg,
unsigned char *value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret >= 0) {
*value = (unsigned char)ret;
ret = 0;
}
return ret;
}
static int ov7670_write_smbus(struct v4l2_subdev *sd, unsigned char reg,
unsigned char value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = i2c_smbus_write_byte_data(client, reg, value);
if (reg == REG_COM7 && (value & COM7_RESET))
msleep(5);
return ret;
}
static int ov7670_read_i2c(struct v4l2_subdev *sd, unsigned char reg,
unsigned char *value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 data = reg;
struct i2c_msg msg;
int ret;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 1;
msg.buf = &data;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
printk(KERN_ERR "Error %d on register write\n", ret);
return ret;
}
msg.flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret >= 0) {
*value = data;
ret = 0;
}
return ret;
}
static int ov7670_write_i2c(struct v4l2_subdev *sd, unsigned char reg,
unsigned char value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_msg msg;
unsigned char data[2] = { reg, value };
int ret;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
msg.buf = data;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret > 0)
ret = 0;
if (reg == REG_COM7 && (value & COM7_RESET))
msleep(5);
return ret;
}
static int ov7670_read(struct v4l2_subdev *sd, unsigned char reg,
unsigned char *value)
{
struct ov7670_info *info = to_state(sd);
if (info->use_smbus)
return ov7670_read_smbus(sd, reg, value);
else
return ov7670_read_i2c(sd, reg, value);
}
static int ov7670_write(struct v4l2_subdev *sd, unsigned char reg,
unsigned char value)
{
struct ov7670_info *info = to_state(sd);
if (info->use_smbus)
return ov7670_write_smbus(sd, reg, value);
else
return ov7670_write_i2c(sd, reg, value);
}
static int ov7670_write_array(struct v4l2_subdev *sd, struct regval_list *vals)
{
while (vals->reg_num != 0xff || vals->value != 0xff) {
int ret = ov7670_write(sd, vals->reg_num, vals->value);
if (ret < 0)
return ret;
vals++;
}
return 0;
}
static int ov7670_reset(struct v4l2_subdev *sd, u32 val)
{
ov7670_write(sd, REG_COM7, COM7_RESET);
msleep(1);
return 0;
}
static int ov7670_init(struct v4l2_subdev *sd, u32 val)
{
return ov7670_write_array(sd, ov7670_default_regs);
}
static int ov7670_detect(struct v4l2_subdev *sd)
{
unsigned char v;
int ret;
ret = ov7670_init(sd, 0);
if (ret < 0)
return ret;
ret = ov7670_read(sd, REG_MIDH, &v);
if (ret < 0)
return ret;
if (v != 0x7f)
return -ENODEV;
ret = ov7670_read(sd, REG_MIDL, &v);
if (ret < 0)
return ret;
if (v != 0xa2)
return -ENODEV;
ret = ov7670_read(sd, REG_PID, &v);
if (ret < 0)
return ret;
if (v != 0x76)
return -ENODEV;
ret = ov7670_read(sd, REG_VER, &v);
if (ret < 0)
return ret;
if (v != 0x73)
return -ENODEV;
return 0;
}
static void ov7675_get_framerate(struct v4l2_subdev *sd,
struct v4l2_fract *tpf)
{
struct ov7670_info *info = to_state(sd);
u32 clkrc = info->clkrc;
int pll_factor;
if (info->pll_bypass)
pll_factor = 1;
else
pll_factor = PLL_FACTOR;
clkrc++;
if (info->fmt->mbus_code == MEDIA_BUS_FMT_SBGGR8_1X8)
clkrc = (clkrc >> 1);
tpf->numerator = 1;
tpf->denominator = (5 * pll_factor * info->clock_speed) /
(4 * clkrc);
}
static int ov7675_set_framerate(struct v4l2_subdev *sd,
struct v4l2_fract *tpf)
{
struct ov7670_info *info = to_state(sd);
u32 clkrc;
int pll_factor;
int ret;
if (info->pll_bypass) {
pll_factor = 1;
ret = ov7670_write(sd, REG_DBLV, DBLV_BYPASS);
} else {
pll_factor = PLL_FACTOR;
ret = ov7670_write(sd, REG_DBLV, DBLV_X4);
}
if (ret < 0)
return ret;
if (tpf->numerator == 0 || tpf->denominator == 0) {
clkrc = 0;
} else {
clkrc = (5 * pll_factor * info->clock_speed * tpf->numerator) /
(4 * tpf->denominator);
if (info->fmt->mbus_code == MEDIA_BUS_FMT_SBGGR8_1X8)
clkrc = (clkrc << 1);
clkrc--;
}
if (clkrc <= 0)
clkrc = CLK_EXT;
else if (clkrc > CLK_SCALE)
clkrc = CLK_SCALE;
info->clkrc = clkrc;
ov7675_get_framerate(sd, tpf);
ret = ov7670_write(sd, REG_CLKRC, info->clkrc);
if (ret < 0)
return ret;
return ov7670_write(sd, REG_DBLV, DBLV_X4);
}
static void ov7670_get_framerate_legacy(struct v4l2_subdev *sd,
struct v4l2_fract *tpf)
{
struct ov7670_info *info = to_state(sd);
tpf->numerator = 1;
tpf->denominator = info->clock_speed;
if ((info->clkrc & CLK_EXT) == 0 && (info->clkrc & CLK_SCALE) > 1)
tpf->denominator /= (info->clkrc & CLK_SCALE);
}
static int ov7670_set_framerate_legacy(struct v4l2_subdev *sd,
struct v4l2_fract *tpf)
{
struct ov7670_info *info = to_state(sd);
int div;
if (tpf->numerator == 0 || tpf->denominator == 0)
div = 1;
else
div = (tpf->numerator * info->clock_speed) / tpf->denominator;
if (div == 0)
div = 1;
else if (div > CLK_SCALE)
div = CLK_SCALE;
info->clkrc = (info->clkrc & 0x80) | div;
tpf->numerator = 1;
tpf->denominator = info->clock_speed / div;
return ov7670_write(sd, REG_CLKRC, info->clkrc);
}
static int ov7670_set_hw(struct v4l2_subdev *sd, int hstart, int hstop,
int vstart, int vstop)
{
int ret;
unsigned char v;
ret = ov7670_write(sd, REG_HSTART, (hstart >> 3) & 0xff);
ret += ov7670_write(sd, REG_HSTOP, (hstop >> 3) & 0xff);
ret += ov7670_read(sd, REG_HREF, &v);
v = (v & 0xc0) | ((hstop & 0x7) << 3) | (hstart & 0x7);
msleep(10);
ret += ov7670_write(sd, REG_HREF, v);
ret += ov7670_write(sd, REG_VSTART, (vstart >> 2) & 0xff);
ret += ov7670_write(sd, REG_VSTOP, (vstop >> 2) & 0xff);
ret += ov7670_read(sd, REG_VREF, &v);
v = (v & 0xf0) | ((vstop & 0x3) << 2) | (vstart & 0x3);
msleep(10);
ret += ov7670_write(sd, REG_VREF, v);
return ret;
}
static int ov7670_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= N_OV7670_FMTS)
return -EINVAL;
code->code = ov7670_formats[code->index].mbus_code;
return 0;
}
static int ov7670_try_fmt_internal(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt,
struct ov7670_format_struct **ret_fmt,
struct ov7670_win_size **ret_wsize)
{
int index, i;
struct ov7670_win_size *wsize;
struct ov7670_info *info = to_state(sd);
unsigned int n_win_sizes = info->devtype->n_win_sizes;
unsigned int win_sizes_limit = n_win_sizes;
for (index = 0; index < N_OV7670_FMTS; index++)
if (ov7670_formats[index].mbus_code == fmt->code)
break;
if (index >= N_OV7670_FMTS) {
index = 0;
fmt->code = ov7670_formats[0].mbus_code;
}
if (ret_fmt != NULL)
*ret_fmt = ov7670_formats + index;
fmt->field = V4L2_FIELD_NONE;
if (info->min_width || info->min_height)
for (i = 0; i < n_win_sizes; i++) {
wsize = info->devtype->win_sizes + i;
if (wsize->width < info->min_width ||
wsize->height < info->min_height) {
win_sizes_limit = i;
break;
}
}
for (wsize = info->devtype->win_sizes;
wsize < info->devtype->win_sizes + win_sizes_limit; wsize++)
if (fmt->width >= wsize->width && fmt->height >= wsize->height)
break;
if (wsize >= info->devtype->win_sizes + win_sizes_limit)
wsize--;
if (ret_wsize != NULL)
*ret_wsize = wsize;
fmt->width = wsize->width;
fmt->height = wsize->height;
fmt->colorspace = ov7670_formats[index].colorspace;
return 0;
}
static int ov7670_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct ov7670_format_struct *ovfmt;
struct ov7670_win_size *wsize;
struct ov7670_info *info = to_state(sd);
unsigned char com7;
int ret;
if (format->pad)
return -EINVAL;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
ret = ov7670_try_fmt_internal(sd, &format->format, NULL, NULL);
if (ret)
return ret;
cfg->try_fmt = format->format;
return 0;
}
ret = ov7670_try_fmt_internal(sd, &format->format, &ovfmt, &wsize);
if (ret)
return ret;
com7 = ovfmt->regs[0].value;
com7 |= wsize->com7_bit;
ov7670_write(sd, REG_COM7, com7);
ov7670_write_array(sd, ovfmt->regs + 1);
ov7670_set_hw(sd, wsize->hstart, wsize->hstop, wsize->vstart,
wsize->vstop);
ret = 0;
if (wsize->regs)
ret = ov7670_write_array(sd, wsize->regs);
info->fmt = ovfmt;
if (ret == 0)
ret = ov7670_write(sd, REG_CLKRC, info->clkrc);
return 0;
}
static int ov7670_g_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct v4l2_captureparm *cp = &parms->parm.capture;
struct ov7670_info *info = to_state(sd);
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
memset(cp, 0, sizeof(struct v4l2_captureparm));
cp->capability = V4L2_CAP_TIMEPERFRAME;
info->devtype->get_framerate(sd, &cp->timeperframe);
return 0;
}
static int ov7670_s_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct v4l2_captureparm *cp = &parms->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
struct ov7670_info *info = to_state(sd);
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (cp->extendedmode != 0)
return -EINVAL;
return info->devtype->set_framerate(sd, tpf);
}
static int ov7670_enum_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_interval_enum *fie)
{
struct ov7670_info *info = to_state(sd);
unsigned int n_win_sizes = info->devtype->n_win_sizes;
int i;
if (fie->pad)
return -EINVAL;
if (fie->index >= ARRAY_SIZE(ov7670_frame_rates))
return -EINVAL;
for (i = 0; i < n_win_sizes; i++) {
struct ov7670_win_size *win = &info->devtype->win_sizes[i];
if (info->min_width && win->width < info->min_width)
continue;
if (info->min_height && win->height < info->min_height)
continue;
if (fie->width == win->width && fie->height == win->height)
break;
}
if (i == n_win_sizes)
return -EINVAL;
fie->interval.numerator = 1;
fie->interval.denominator = ov7670_frame_rates[fie->index];
return 0;
}
static int ov7670_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct ov7670_info *info = to_state(sd);
int i;
int num_valid = -1;
__u32 index = fse->index;
unsigned int n_win_sizes = info->devtype->n_win_sizes;
if (fse->pad)
return -EINVAL;
for (i = 0; i < n_win_sizes; i++) {
struct ov7670_win_size *win = &info->devtype->win_sizes[i];
if (info->min_width && win->width < info->min_width)
continue;
if (info->min_height && win->height < info->min_height)
continue;
if (index == ++num_valid) {
fse->min_width = fse->max_width = win->width;
fse->min_height = fse->max_height = win->height;
return 0;
}
}
return -EINVAL;
}
static int ov7670_store_cmatrix(struct v4l2_subdev *sd,
int matrix[CMATRIX_LEN])
{
int i, ret;
unsigned char signbits = 0;
ret = ov7670_read(sd, REG_CMATRIX_SIGN, &signbits);
signbits &= 0xc0;
for (i = 0; i < CMATRIX_LEN; i++) {
unsigned char raw;
if (matrix[i] < 0) {
signbits |= (1 << i);
if (matrix[i] < -255)
raw = 0xff;
else
raw = (-1 * matrix[i]) & 0xff;
}
else {
if (matrix[i] > 255)
raw = 0xff;
else
raw = matrix[i] & 0xff;
}
ret += ov7670_write(sd, REG_CMATRIX_BASE + i, raw);
}
ret += ov7670_write(sd, REG_CMATRIX_SIGN, signbits);
return ret;
}
static int ov7670_sine(int theta)
{
int chs = 1;
int sine;
if (theta < 0) {
theta = -theta;
chs = -1;
}
if (theta <= 90)
sine = ov7670_sin_table[theta/SIN_STEP];
else {
theta -= 90;
sine = 1000 - ov7670_sin_table[theta/SIN_STEP];
}
return sine*chs;
}
static int ov7670_cosine(int theta)
{
theta = 90 - theta;
if (theta > 180)
theta -= 360;
else if (theta < -180)
theta += 360;
return ov7670_sine(theta);
}
static void ov7670_calc_cmatrix(struct ov7670_info *info,
int matrix[CMATRIX_LEN], int sat, int hue)
{
int i;
for (i = 0; i < CMATRIX_LEN; i++)
matrix[i] = (info->fmt->cmatrix[i] * sat) >> 7;
if (hue != 0) {
int sinth, costh, tmpmatrix[CMATRIX_LEN];
memcpy(tmpmatrix, matrix, CMATRIX_LEN*sizeof(int));
sinth = ov7670_sine(hue);
costh = ov7670_cosine(hue);
matrix[0] = (matrix[3]*sinth + matrix[0]*costh)/1000;
matrix[1] = (matrix[4]*sinth + matrix[1]*costh)/1000;
matrix[2] = (matrix[5]*sinth + matrix[2]*costh)/1000;
matrix[3] = (matrix[3]*costh - matrix[0]*sinth)/1000;
matrix[4] = (matrix[4]*costh - matrix[1]*sinth)/1000;
matrix[5] = (matrix[5]*costh - matrix[2]*sinth)/1000;
}
}
static int ov7670_s_sat_hue(struct v4l2_subdev *sd, int sat, int hue)
{
struct ov7670_info *info = to_state(sd);
int matrix[CMATRIX_LEN];
int ret;
ov7670_calc_cmatrix(info, matrix, sat, hue);
ret = ov7670_store_cmatrix(sd, matrix);
return ret;
}
static unsigned char ov7670_abs_to_sm(unsigned char v)
{
if (v > 127)
return v & 0x7f;
return (128 - v) | 0x80;
}
static int ov7670_s_brightness(struct v4l2_subdev *sd, int value)
{
unsigned char com8 = 0, v;
int ret;
ov7670_read(sd, REG_COM8, &com8);
com8 &= ~COM8_AEC;
ov7670_write(sd, REG_COM8, com8);
v = ov7670_abs_to_sm(value);
ret = ov7670_write(sd, REG_BRIGHT, v);
return ret;
}
static int ov7670_s_contrast(struct v4l2_subdev *sd, int value)
{
return ov7670_write(sd, REG_CONTRAS, (unsigned char) value);
}
static int ov7670_s_hflip(struct v4l2_subdev *sd, int value)
{
unsigned char v = 0;
int ret;
ret = ov7670_read(sd, REG_MVFP, &v);
if (value)
v |= MVFP_MIRROR;
else
v &= ~MVFP_MIRROR;
msleep(10);
ret += ov7670_write(sd, REG_MVFP, v);
return ret;
}
static int ov7670_s_vflip(struct v4l2_subdev *sd, int value)
{
unsigned char v = 0;
int ret;
ret = ov7670_read(sd, REG_MVFP, &v);
if (value)
v |= MVFP_FLIP;
else
v &= ~MVFP_FLIP;
msleep(10);
ret += ov7670_write(sd, REG_MVFP, v);
return ret;
}
static int ov7670_g_gain(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char gain;
ret = ov7670_read(sd, REG_GAIN, &gain);
*value = gain;
return ret;
}
static int ov7670_s_gain(struct v4l2_subdev *sd, int value)
{
int ret;
unsigned char com8;
ret = ov7670_write(sd, REG_GAIN, value & 0xff);
if (ret == 0) {
ret = ov7670_read(sd, REG_COM8, &com8);
ret = ov7670_write(sd, REG_COM8, com8 & ~COM8_AGC);
}
return ret;
}
static int ov7670_s_autogain(struct v4l2_subdev *sd, int value)
{
int ret;
unsigned char com8;
ret = ov7670_read(sd, REG_COM8, &com8);
if (ret == 0) {
if (value)
com8 |= COM8_AGC;
else
com8 &= ~COM8_AGC;
ret = ov7670_write(sd, REG_COM8, com8);
}
return ret;
}
static int ov7670_s_exp(struct v4l2_subdev *sd, int value)
{
int ret;
unsigned char com1, com8, aech, aechh;
ret = ov7670_read(sd, REG_COM1, &com1) +
ov7670_read(sd, REG_COM8, &com8) +
ov7670_read(sd, REG_AECHH, &aechh);
if (ret)
return ret;
com1 = (com1 & 0xfc) | (value & 0x03);
aech = (value >> 2) & 0xff;
aechh = (aechh & 0xc0) | ((value >> 10) & 0x3f);
ret = ov7670_write(sd, REG_COM1, com1) +
ov7670_write(sd, REG_AECH, aech) +
ov7670_write(sd, REG_AECHH, aechh);
if (ret == 0)
ret = ov7670_write(sd, REG_COM8, com8 & ~COM8_AEC);
return ret;
}
static int ov7670_s_autoexp(struct v4l2_subdev *sd,
enum v4l2_exposure_auto_type value)
{
int ret;
unsigned char com8;
ret = ov7670_read(sd, REG_COM8, &com8);
if (ret == 0) {
if (value == V4L2_EXPOSURE_AUTO)
com8 |= COM8_AEC;
else
com8 &= ~COM8_AEC;
ret = ov7670_write(sd, REG_COM8, com8);
}
return ret;
}
static int ov7670_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct ov7670_info *info = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
return ov7670_g_gain(sd, &info->gain->val);
}
return -EINVAL;
}
static int ov7670_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct ov7670_info *info = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
return ov7670_s_brightness(sd, ctrl->val);
case V4L2_CID_CONTRAST:
return ov7670_s_contrast(sd, ctrl->val);
case V4L2_CID_SATURATION:
return ov7670_s_sat_hue(sd,
info->saturation->val, info->hue->val);
case V4L2_CID_VFLIP:
return ov7670_s_vflip(sd, ctrl->val);
case V4L2_CID_HFLIP:
return ov7670_s_hflip(sd, ctrl->val);
case V4L2_CID_AUTOGAIN:
if (!ctrl->val) {
return ov7670_s_gain(sd, info->gain->val);
}
return ov7670_s_autogain(sd, ctrl->val);
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->val == V4L2_EXPOSURE_MANUAL) {
return ov7670_s_exp(sd, info->exposure->val);
}
return ov7670_s_autoexp(sd, ctrl->val);
}
return -EINVAL;
}
static int ov7670_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
unsigned char val = 0;
int ret;
ret = ov7670_read(sd, reg->reg & 0xff, &val);
reg->val = val;
reg->size = 1;
return ret;
}
static int ov7670_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
ov7670_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int ov7670_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_fract tpf;
struct v4l2_subdev *sd;
struct ov7670_info *info;
int ret;
info = devm_kzalloc(&client->dev, sizeof(*info), GFP_KERNEL);
if (info == NULL)
return -ENOMEM;
sd = &info->sd;
v4l2_i2c_subdev_init(sd, client, &ov7670_ops);
info->clock_speed = 30;
if (client->dev.platform_data) {
struct ov7670_config *config = client->dev.platform_data;
info->min_width = config->min_width;
info->min_height = config->min_height;
info->use_smbus = config->use_smbus;
if (config->clock_speed)
info->clock_speed = config->clock_speed;
if (config->pll_bypass && id->driver_data != MODEL_OV7670)
info->pll_bypass = true;
if (config->pclk_hb_disable)
info->pclk_hb_disable = true;
}
ret = ov7670_detect(sd);
if (ret) {
v4l_dbg(1, debug, client,
"chip found @ 0x%x (%s) is not an ov7670 chip.\n",
client->addr << 1, client->adapter->name);
return ret;
}
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
info->devtype = &ov7670_devdata[id->driver_data];
info->fmt = &ov7670_formats[0];
info->clkrc = 0;
tpf.numerator = 1;
tpf.denominator = 30;
info->devtype->set_framerate(sd, &tpf);
if (info->pclk_hb_disable)
ov7670_write(sd, REG_COM10, COM10_PCLK_HB);
v4l2_ctrl_handler_init(&info->hdl, 10);
v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_CONTRAST, 0, 127, 1, 64);
v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
info->saturation = v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_SATURATION, 0, 256, 1, 128);
info->hue = v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_HUE, -180, 180, 5, 0);
info->gain = v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 128);
info->auto_gain = v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
info->exposure = v4l2_ctrl_new_std(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 65535, 1, 500);
info->auto_exposure = v4l2_ctrl_new_std_menu(&info->hdl, &ov7670_ctrl_ops,
V4L2_CID_EXPOSURE_AUTO, V4L2_EXPOSURE_MANUAL, 0,
V4L2_EXPOSURE_AUTO);
sd->ctrl_handler = &info->hdl;
if (info->hdl.error) {
int err = info->hdl.error;
v4l2_ctrl_handler_free(&info->hdl);
return err;
}
v4l2_ctrl_auto_cluster(2, &info->auto_gain, 0, true);
v4l2_ctrl_auto_cluster(2, &info->auto_exposure,
V4L2_EXPOSURE_MANUAL, false);
v4l2_ctrl_cluster(2, &info->saturation);
v4l2_ctrl_handler_setup(&info->hdl);
return 0;
}
static int ov7670_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov7670_info *info = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&info->hdl);
return 0;
}
