static inline struct ov7670_info *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov7670_info, sd);
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
static int ov7670_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= N_OV7670_FMTS)
return -EINVAL;
*code = ov7670_formats[index].mbus_code;
return 0;
}
static int ov7670_try_fmt_internal(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt,
struct ov7670_format_struct **ret_fmt,
struct ov7670_win_size **ret_wsize)
{
int index;
struct ov7670_win_size *wsize;
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
for (wsize = ov7670_win_sizes; wsize < ov7670_win_sizes + N_WIN_SIZES;
wsize++)
if (fmt->width >= wsize->width && fmt->height >= wsize->height)
break;
if (wsize >= ov7670_win_sizes + N_WIN_SIZES)
wsize--;
if (ret_wsize != NULL)
*ret_wsize = wsize;
fmt->width = wsize->width;
fmt->height = wsize->height;
fmt->colorspace = ov7670_formats[index].colorspace;
return 0;
}
static int ov7670_try_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
return ov7670_try_fmt_internal(sd, fmt, NULL, NULL);
}
static int ov7670_s_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct ov7670_format_struct *ovfmt;
struct ov7670_win_size *wsize;
struct ov7670_info *info = to_state(sd);
unsigned char com7;
int ret;
ret = ov7670_try_fmt_internal(sd, fmt, &ovfmt, &wsize);
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
cp->timeperframe.numerator = 1;
cp->timeperframe.denominator = info->clock_speed;
if ((info->clkrc & CLK_EXT) == 0 && (info->clkrc & CLK_SCALE) > 1)
cp->timeperframe.denominator /= (info->clkrc & CLK_SCALE);
return 0;
}
static int ov7670_s_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct v4l2_captureparm *cp = &parms->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
struct ov7670_info *info = to_state(sd);
int div;
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (cp->extendedmode != 0)
return -EINVAL;
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
static int ov7670_enum_frameintervals(struct v4l2_subdev *sd,
struct v4l2_frmivalenum *interval)
{
if (interval->index >= ARRAY_SIZE(ov7670_frame_rates))
return -EINVAL;
interval->type = V4L2_FRMIVAL_TYPE_DISCRETE;
interval->discrete.numerator = 1;
interval->discrete.denominator = ov7670_frame_rates[interval->index];
return 0;
}
static int ov7670_enum_framesizes(struct v4l2_subdev *sd,
struct v4l2_frmsizeenum *fsize)
{
struct ov7670_info *info = to_state(sd);
int i;
int num_valid = -1;
__u32 index = fsize->index;
for (i = 0; i < N_WIN_SIZES; i++) {
struct ov7670_win_size *win = &ov7670_win_sizes[index];
if (info->min_width && win->width < info->min_width)
continue;
if (info->min_height && win->height < info->min_height)
continue;
if (index == ++num_valid) {
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = win->width;
fsize->discrete.height = win->height;
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
int matrix[CMATRIX_LEN])
{
int i;
for (i = 0; i < CMATRIX_LEN; i++)
matrix[i] = (info->fmt->cmatrix[i]*info->sat) >> 7;
if (info->hue != 0) {
int sinth, costh, tmpmatrix[CMATRIX_LEN];
memcpy(tmpmatrix, matrix, CMATRIX_LEN*sizeof(int));
sinth = ov7670_sine(info->hue);
costh = ov7670_cosine(info->hue);
matrix[0] = (matrix[3]*sinth + matrix[0]*costh)/1000;
matrix[1] = (matrix[4]*sinth + matrix[1]*costh)/1000;
matrix[2] = (matrix[5]*sinth + matrix[2]*costh)/1000;
matrix[3] = (matrix[3]*costh - matrix[0]*sinth)/1000;
matrix[4] = (matrix[4]*costh - matrix[1]*sinth)/1000;
matrix[5] = (matrix[5]*costh - matrix[2]*sinth)/1000;
}
}
static int ov7670_s_sat(struct v4l2_subdev *sd, int value)
{
struct ov7670_info *info = to_state(sd);
int matrix[CMATRIX_LEN];
int ret;
info->sat = value;
ov7670_calc_cmatrix(info, matrix);
ret = ov7670_store_cmatrix(sd, matrix);
return ret;
}
static int ov7670_g_sat(struct v4l2_subdev *sd, __s32 *value)
{
struct ov7670_info *info = to_state(sd);
*value = info->sat;
return 0;
}
static int ov7670_s_hue(struct v4l2_subdev *sd, int value)
{
struct ov7670_info *info = to_state(sd);
int matrix[CMATRIX_LEN];
int ret;
if (value < -180 || value > 180)
return -EINVAL;
info->hue = value;
ov7670_calc_cmatrix(info, matrix);
ret = ov7670_store_cmatrix(sd, matrix);
return ret;
}
static int ov7670_g_hue(struct v4l2_subdev *sd, __s32 *value)
{
struct ov7670_info *info = to_state(sd);
*value = info->hue;
return 0;
}
static unsigned char ov7670_sm_to_abs(unsigned char v)
{
if ((v & 0x80) == 0)
return v + 128;
return 128 - (v & 0x7f);
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
static int ov7670_g_brightness(struct v4l2_subdev *sd, __s32 *value)
{
unsigned char v = 0;
int ret = ov7670_read(sd, REG_BRIGHT, &v);
*value = ov7670_sm_to_abs(v);
return ret;
}
static int ov7670_s_contrast(struct v4l2_subdev *sd, int value)
{
return ov7670_write(sd, REG_CONTRAS, (unsigned char) value);
}
static int ov7670_g_contrast(struct v4l2_subdev *sd, __s32 *value)
{
unsigned char v = 0;
int ret = ov7670_read(sd, REG_CONTRAS, &v);
*value = v;
return ret;
}
static int ov7670_g_hflip(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char v = 0;
ret = ov7670_read(sd, REG_MVFP, &v);
*value = (v & MVFP_MIRROR) == MVFP_MIRROR;
return ret;
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
static int ov7670_g_vflip(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char v = 0;
ret = ov7670_read(sd, REG_MVFP, &v);
*value = (v & MVFP_FLIP) == MVFP_FLIP;
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
static int ov7670_g_autogain(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char com8;
ret = ov7670_read(sd, REG_COM8, &com8);
*value = (com8 & COM8_AGC) != 0;
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
static int ov7670_g_exp(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char com1, aech, aechh;
ret = ov7670_read(sd, REG_COM1, &com1) +
ov7670_read(sd, REG_AECH, &aech) +
ov7670_read(sd, REG_AECHH, &aechh);
*value = ((aechh & 0x3f) << 10) | (aech << 2) | (com1 & 0x03);
return ret;
}
static int ov7670_s_exp(struct v4l2_subdev *sd, int value)
{
int ret;
unsigned char com1, com8, aech, aechh;
ret = ov7670_read(sd, REG_COM1, &com1) +
ov7670_read(sd, REG_COM8, &com8);
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
static int ov7670_g_autoexp(struct v4l2_subdev *sd, __s32 *value)
{
int ret;
unsigned char com8;
enum v4l2_exposure_auto_type *atype = (enum v4l2_exposure_auto_type *) value;
ret = ov7670_read(sd, REG_COM8, &com8);
if (com8 & COM8_AEC)
*atype = V4L2_EXPOSURE_AUTO;
else
*atype = V4L2_EXPOSURE_MANUAL;
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
static int ov7670_queryctrl(struct v4l2_subdev *sd,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_BRIGHTNESS:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 128);
case V4L2_CID_CONTRAST:
return v4l2_ctrl_query_fill(qc, 0, 127, 1, 64);
case V4L2_CID_VFLIP:
case V4L2_CID_HFLIP:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
case V4L2_CID_SATURATION:
return v4l2_ctrl_query_fill(qc, 0, 256, 1, 128);
case V4L2_CID_HUE:
return v4l2_ctrl_query_fill(qc, -180, 180, 5, 0);
case V4L2_CID_GAIN:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 128);
case V4L2_CID_AUTOGAIN:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
case V4L2_CID_EXPOSURE:
return v4l2_ctrl_query_fill(qc, 0, 65535, 1, 500);
case V4L2_CID_EXPOSURE_AUTO:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
}
return -EINVAL;
}
static int ov7670_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
return ov7670_g_brightness(sd, &ctrl->value);
case V4L2_CID_CONTRAST:
return ov7670_g_contrast(sd, &ctrl->value);
case V4L2_CID_SATURATION:
return ov7670_g_sat(sd, &ctrl->value);
case V4L2_CID_HUE:
return ov7670_g_hue(sd, &ctrl->value);
case V4L2_CID_VFLIP:
return ov7670_g_vflip(sd, &ctrl->value);
case V4L2_CID_HFLIP:
return ov7670_g_hflip(sd, &ctrl->value);
case V4L2_CID_GAIN:
return ov7670_g_gain(sd, &ctrl->value);
case V4L2_CID_AUTOGAIN:
return ov7670_g_autogain(sd, &ctrl->value);
case V4L2_CID_EXPOSURE:
return ov7670_g_exp(sd, &ctrl->value);
case V4L2_CID_EXPOSURE_AUTO:
return ov7670_g_autoexp(sd, &ctrl->value);
}
return -EINVAL;
}
static int ov7670_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
return ov7670_s_brightness(sd, ctrl->value);
case V4L2_CID_CONTRAST:
return ov7670_s_contrast(sd, ctrl->value);
case V4L2_CID_SATURATION:
return ov7670_s_sat(sd, ctrl->value);
case V4L2_CID_HUE:
return ov7670_s_hue(sd, ctrl->value);
case V4L2_CID_VFLIP:
return ov7670_s_vflip(sd, ctrl->value);
case V4L2_CID_HFLIP:
return ov7670_s_hflip(sd, ctrl->value);
case V4L2_CID_GAIN:
return ov7670_s_gain(sd, ctrl->value);
case V4L2_CID_AUTOGAIN:
return ov7670_s_autogain(sd, ctrl->value);
case V4L2_CID_EXPOSURE:
return ov7670_s_exp(sd, ctrl->value);
case V4L2_CID_EXPOSURE_AUTO:
return ov7670_s_autoexp(sd,
(enum v4l2_exposure_auto_type) ctrl->value);
}
return -EINVAL;
}
static int ov7670_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_OV7670, 0);
}
static int ov7670_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned char val = 0;
int ret;
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
ret = ov7670_read(sd, reg->reg & 0xff, &val);
reg->val = val;
reg->size = 1;
return ret;
}
static int ov7670_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
ov7670_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int ov7670_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
struct ov7670_info *info;
int ret;
info = kzalloc(sizeof(struct ov7670_info), GFP_KERNEL);
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
}
ret = ov7670_detect(sd);
if (ret) {
v4l_dbg(1, debug, client,
"chip found @ 0x%x (%s) is not an ov7670 chip.\n",
client->addr << 1, client->adapter->name);
kfree(info);
return ret;
}
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
info->fmt = &ov7670_formats[0];
info->sat = 128;
info->clkrc = info->clock_speed / 30;
return 0;
}
static int ov7670_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
static __init int init_ov7670(void)
{
return i2c_add_driver(&ov7670_driver);
}
static __exit void exit_ov7670(void)
{
i2c_del_driver(&ov7670_driver);
}
