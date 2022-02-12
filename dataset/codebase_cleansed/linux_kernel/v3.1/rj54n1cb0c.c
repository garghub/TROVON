static const struct rj54n1_datafmt *rj54n1_find_datafmt(
enum v4l2_mbus_pixelcode code, const struct rj54n1_datafmt *fmt,
int n)
{
int i;
for (i = 0; i < n; i++)
if (fmt[i].code == code)
return fmt + i;
return NULL;
}
static struct rj54n1 *to_rj54n1(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct rj54n1, subdev);
}
static int reg_read(struct i2c_client *client, const u16 reg)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
int ret;
if (rj54n1->bank != reg >> 8) {
dev_dbg(&client->dev, "[0x%x] = 0x%x\n", 0xff, reg >> 8);
ret = i2c_smbus_write_byte_data(client, 0xff, reg >> 8);
if (ret < 0)
return ret;
rj54n1->bank = reg >> 8;
}
return i2c_smbus_read_byte_data(client, reg & 0xff);
}
static int reg_write(struct i2c_client *client, const u16 reg,
const u8 data)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
int ret;
if (rj54n1->bank != reg >> 8) {
dev_dbg(&client->dev, "[0x%x] = 0x%x\n", 0xff, reg >> 8);
ret = i2c_smbus_write_byte_data(client, 0xff, reg >> 8);
if (ret < 0)
return ret;
rj54n1->bank = reg >> 8;
}
dev_dbg(&client->dev, "[0x%x] = 0x%x\n", reg & 0xff, data);
return i2c_smbus_write_byte_data(client, reg & 0xff, data);
}
static int reg_set(struct i2c_client *client, const u16 reg,
const u8 data, const u8 mask)
{
int ret;
ret = reg_read(client, reg);
if (ret < 0)
return ret;
return reg_write(client, reg, (ret & ~mask) | (data & mask));
}
static int reg_write_multiple(struct i2c_client *client,
const struct rj54n1_reg_val *rv, const int n)
{
int i, ret;
for (i = 0; i < n; i++) {
ret = reg_write(client, rv->reg, rv->val);
if (ret < 0)
return ret;
rv++;
}
return 0;
}
static int rj54n1_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(rj54n1_colour_fmts))
return -EINVAL;
*code = rj54n1_colour_fmts[index].code;
return 0;
}
static int rj54n1_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return reg_set(client, RJ54N1_STILL_CONTROL, (!enable) << 7, 0x80);
}
static int rj54n1_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (flags & SOCAM_PCLK_SAMPLE_RISING)
return reg_write(client, RJ54N1_OUT_SIGPO, 1 << 4);
else
return reg_write(client, RJ54N1_OUT_SIGPO, 0);
}
static unsigned long rj54n1_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
const unsigned long flags =
SOCAM_PCLK_SAMPLE_RISING | SOCAM_PCLK_SAMPLE_FALLING |
SOCAM_MASTER | SOCAM_DATAWIDTH_8 |
SOCAM_HSYNC_ACTIVE_HIGH | SOCAM_VSYNC_ACTIVE_HIGH |
SOCAM_DATA_ACTIVE_HIGH;
return soc_camera_apply_sensor_flags(icl, flags);
}
static int rj54n1_set_rect(struct i2c_client *client,
u16 reg_x, u16 reg_y, u16 reg_xy,
u32 width, u32 height)
{
int ret;
ret = reg_write(client, reg_xy,
((width >> 4) & 0x70) |
((height >> 8) & 7));
if (!ret)
ret = reg_write(client, reg_x, width & 0xff);
if (!ret)
ret = reg_write(client, reg_y, height & 0xff);
return ret;
}
static int rj54n1_commit(struct i2c_client *client)
{
int ret = reg_write(client, RJ54N1_INIT_START, 1);
msleep(10);
if (!ret)
ret = reg_write(client, RJ54N1_INIT_START, 0);
return ret;
}
static int rj54n1_s_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
struct v4l2_rect *rect = &a->c;
int dummy = 0, output_w, output_h,
input_w = rect->width, input_h = rect->height;
int ret;
soc_camera_limit_side(&dummy, &input_w,
RJ54N1_COLUMN_SKIP, 8, RJ54N1_MAX_WIDTH);
soc_camera_limit_side(&dummy, &input_h,
RJ54N1_ROW_SKIP, 8, RJ54N1_MAX_HEIGHT);
output_w = (input_w * 1024 + rj54n1->resize / 2) / rj54n1->resize;
output_h = (input_h * 1024 + rj54n1->resize / 2) / rj54n1->resize;
dev_dbg(&client->dev, "Scaling for %dx%d : %u = %dx%d\n",
input_w, input_h, rj54n1->resize, output_w, output_h);
ret = rj54n1_sensor_scale(sd, &input_w, &input_h, &output_w, &output_h);
if (ret < 0)
return ret;
rj54n1->width = output_w;
rj54n1->height = output_h;
rj54n1->resize = ret;
rj54n1->rect.width = input_w;
rj54n1->rect.height = input_h;
return 0;
}
static int rj54n1_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
a->c = rj54n1->rect;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int rj54n1_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = RJ54N1_COLUMN_SKIP;
a->bounds.top = RJ54N1_ROW_SKIP;
a->bounds.width = RJ54N1_MAX_WIDTH;
a->bounds.height = RJ54N1_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int rj54n1_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
mf->code = rj54n1->fmt->code;
mf->colorspace = rj54n1->fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
mf->width = rj54n1->width;
mf->height = rj54n1->height;
return 0;
}
static int rj54n1_sensor_scale(struct v4l2_subdev *sd, s32 *in_w, s32 *in_h,
s32 *out_w, s32 *out_h)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
unsigned int skip, resize, input_w = *in_w, input_h = *in_h,
output_w = *out_w, output_h = *out_h;
u16 inc_sel, wb_bit8, wb_left, wb_right, wb_top, wb_bottom;
unsigned int peak, peak_50, peak_60;
int ret;
if (output_w > max(512U, input_w / 2)) {
if (2 * output_w > RJ54N1_MAX_WIDTH) {
input_w = RJ54N1_MAX_WIDTH;
output_w = RJ54N1_MAX_WIDTH / 2;
} else {
input_w = output_w * 2;
}
dev_dbg(&client->dev, "Adjusted output width: in %u, out %u\n",
input_w, output_w);
}
if (output_h > max(384U, input_h / 2)) {
if (2 * output_h > RJ54N1_MAX_HEIGHT) {
input_h = RJ54N1_MAX_HEIGHT;
output_h = RJ54N1_MAX_HEIGHT / 2;
} else {
input_h = output_h * 2;
}
dev_dbg(&client->dev, "Adjusted output height: in %u, out %u\n",
input_h, output_h);
}
ret = rj54n1_set_rect(client, RJ54N1_X_OUTPUT_SIZE_S_L,
RJ54N1_Y_OUTPUT_SIZE_S_L,
RJ54N1_XY_OUTPUT_SIZE_S_H, output_w, output_h);
if (!ret)
ret = rj54n1_set_rect(client, RJ54N1_X_OUTPUT_SIZE_P_L,
RJ54N1_Y_OUTPUT_SIZE_P_L,
RJ54N1_XY_OUTPUT_SIZE_P_H, output_w, output_h);
if (ret < 0)
return ret;
if (output_w > input_w && output_h > input_h) {
input_w = output_w;
input_h = output_h;
resize = 1024;
} else {
unsigned int resize_x, resize_y;
resize_x = (input_w * 1024 + output_w / 2) / output_w;
resize_y = (input_h * 1024 + output_h / 2) / output_h;
if (resize_x > resize_y &&
(output_h * resize_x + 512) / 1024 > RJ54N1_MAX_HEIGHT)
resize = (RJ54N1_MAX_HEIGHT * 1024 + output_h / 2) /
output_h;
else if (resize_y > resize_x &&
(output_w * resize_y + 512) / 1024 > RJ54N1_MAX_WIDTH)
resize = (RJ54N1_MAX_WIDTH * 1024 + output_w / 2) /
output_w;
else
resize = max(resize_x, resize_y);
switch (resize) {
case 2040 ... 2047:
resize = 2039;
break;
case 4080 ... 4095:
resize = 4079;
break;
case 8160 ... 8191:
resize = 8159;
break;
case 16320 ... 16384:
resize = 16319;
}
}
ret = reg_write(client, RJ54N1_RESIZE_HOLD_L, resize & 0xff);
if (!ret)
ret = reg_write(client, RJ54N1_RESIZE_HOLD_H, resize >> 8);
if (ret < 0)
return ret;
skip = min(resize / 1024, 15U);
inc_sel = 1 << skip;
if (inc_sel <= 2)
inc_sel = 0xc;
else if (resize & 1023 && skip < 15)
inc_sel |= 1 << (skip + 1);
ret = reg_write(client, RJ54N1_INC_USE_SEL_L, inc_sel & 0xfc);
if (!ret)
ret = reg_write(client, RJ54N1_INC_USE_SEL_H, inc_sel >> 8);
if (!rj54n1->auto_wb) {
wb_left = output_w / 16;
wb_right = (3 * output_w / 4 - 3) / 4;
wb_top = output_h / 16;
wb_bottom = (3 * output_h / 4 - 3) / 4;
wb_bit8 = ((wb_left >> 2) & 0x40) | ((wb_top >> 4) & 0x10) |
((wb_right >> 6) & 4) | ((wb_bottom >> 8) & 1);
if (!ret)
ret = reg_write(client, RJ54N1_BIT8_WB, wb_bit8);
if (!ret)
ret = reg_write(client, RJ54N1_HCAPS_WB, wb_left);
if (!ret)
ret = reg_write(client, RJ54N1_VCAPS_WB, wb_top);
if (!ret)
ret = reg_write(client, RJ54N1_HCAPE_WB, wb_right);
if (!ret)
ret = reg_write(client, RJ54N1_VCAPE_WB, wb_bottom);
}
peak = 12 * RJ54N1_MAX_WIDTH * (1 << 14) * resize / rj54n1->tgclk_mhz /
10000;
peak_50 = peak / 6;
peak_60 = peak / 5;
if (!ret)
ret = reg_write(client, RJ54N1_PEAK_H,
((peak_50 >> 4) & 0xf0) | (peak_60 >> 8));
if (!ret)
ret = reg_write(client, RJ54N1_PEAK_50, peak_50);
if (!ret)
ret = reg_write(client, RJ54N1_PEAK_60, peak_60);
if (!ret)
ret = reg_write(client, RJ54N1_PEAK_DIFF, peak / 150);
if (!ret)
ret = reg_write(client, RJ54N1_RESIZE_CONTROL,
RESIZE_HOLD_SEL | RESIZE_GO | 1);
if (ret < 0)
return ret;
msleep(230);
ret = reg_write(client, RJ54N1_RESIZE_CONTROL, RESIZE_HOLD_SEL | 1);
if (ret < 0)
return ret;
*in_w = (output_w * resize + 512) / 1024;
*in_h = (output_h * resize + 512) / 1024;
*out_w = output_w;
*out_h = output_h;
dev_dbg(&client->dev, "Scaled for %dx%d : %u = %ux%u, skip %u\n",
*in_w, *in_h, resize, output_w, output_h, skip);
return resize;
}
static int rj54n1_set_clock(struct i2c_client *client)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
int ret;
ret = reg_write(client, RJ54N1_RESET_STANDBY, E_EXCLK | SOFT_STDBY);
if (!ret)
ret = reg_write(client, RJ54N1_RESET_STANDBY, E_EXCLK);
if (!ret)
ret = reg_write(client, RJ54N1_PLL_L, PLL_L);
if (!ret)
ret = reg_write(client, RJ54N1_PLL_N, PLL_N);
if (!ret)
ret = reg_write(client, RJ54N1_RATIO_TG,
rj54n1->clk_div.ratio_tg);
if (!ret)
ret = reg_write(client, RJ54N1_RATIO_T,
rj54n1->clk_div.ratio_t);
if (!ret)
ret = reg_write(client, RJ54N1_RATIO_R,
rj54n1->clk_div.ratio_r);
if (!ret)
ret = reg_write(client, RJ54N1_RAMP_TGCLK_EN, 3);
if (!ret)
ret = reg_write(client, RJ54N1_OCLK_DSP, 0);
if (!ret)
ret = reg_write(client, RJ54N1_RATIO_OP,
rj54n1->clk_div.ratio_op);
if (!ret)
ret = reg_write(client, RJ54N1_RATIO_O,
rj54n1->clk_div.ratio_o);
if (!ret)
ret = reg_write(client, RJ54N1_OCLK_SEL_EN, 1);
if (!ret)
ret = reg_write(client, RJ54N1_TG_BYPASS, 2);
if (!ret)
ret = reg_write(client, RJ54N1_RESET_STANDBY,
E_EXCLK | SEN_RSTX);
if (!ret)
ret = reg_write(client, RJ54N1_PLL_EN, 1);
msleep(10);
if (!ret)
ret = reg_write(client, RJ54N1_CLK_RST, 1);
if (!ret)
ret = reg_read(client, RJ54N1_CLK_RST);
if (ret != 1) {
dev_err(&client->dev,
"Resetting RJ54N1CB0C clock failed: %d!\n", ret);
return -EIO;
}
ret = reg_set(client, RJ54N1_OCLK_DSP, 1, 1);
if (!ret)
ret = reg_write(client, RJ54N1_OCLK_SEL_EN, 1);
return ret;
}
static int rj54n1_reg_init(struct i2c_client *client)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
int ret = rj54n1_set_clock(client);
if (!ret)
ret = reg_write_multiple(client, bank_7, ARRAY_SIZE(bank_7));
if (!ret)
ret = reg_write_multiple(client, bank_10, ARRAY_SIZE(bank_10));
if (!ret)
ret = reg_write(client, RJ54N1_SCALE_1_2_LEV, 3 | (7 << 4));
if (!ret)
ret = reg_write(client, RJ54N1_SCALE_4_LEV, 0xf);
if (!ret)
ret = reg_write(client, RJ54N1_RESIZE_CONTROL,
RESIZE_HOLD_SEL | 1);
if (!ret)
ret = reg_write(client, RJ54N1_Y_GAIN, 0x84);
if (!ret)
ret = reg_write(client, RJ54N1_MIRROR_STILL_MODE, 0x27);
if (!ret)
ret = reg_write_multiple(client, bank_4, ARRAY_SIZE(bank_4));
if (!ret)
ret = reg_write(client, RJ54N1_EXPOSURE_CONTROL, 0x80);
if (!ret)
ret = reg_read(client, RJ54N1_WB_SEL_WEIGHT_I);
if (ret >= 0) {
rj54n1->auto_wb = ret & 0x80;
ret = reg_write_multiple(client, bank_5, ARRAY_SIZE(bank_5));
}
if (!ret)
ret = reg_write_multiple(client, bank_8, ARRAY_SIZE(bank_8));
if (!ret)
ret = reg_write(client, RJ54N1_RESET_STANDBY,
E_EXCLK | DSP_RSTX | SEN_RSTX);
if (!ret)
ret = rj54n1_commit(client);
if (!ret)
ret = reg_write(client, RJ54N1_RESET_STANDBY,
E_EXCLK | DSP_RSTX | TG_RSTX | SEN_RSTX);
if (!ret)
ret = reg_write(client, RJ54N1_FWFLG, 2);
msleep(700);
return ret;
}
static int rj54n1_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
const struct rj54n1_datafmt *fmt;
int align = mf->code == V4L2_MBUS_FMT_SBGGR10_1X10 ||
mf->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_BE ||
mf->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_BE ||
mf->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE ||
mf->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_LE;
dev_dbg(&client->dev, "%s: code = %d, width = %u, height = %u\n",
__func__, mf->code, mf->width, mf->height);
fmt = rj54n1_find_datafmt(mf->code, rj54n1_colour_fmts,
ARRAY_SIZE(rj54n1_colour_fmts));
if (!fmt) {
fmt = rj54n1->fmt;
mf->code = fmt->code;
}
mf->field = V4L2_FIELD_NONE;
mf->colorspace = fmt->colorspace;
v4l_bound_align_image(&mf->width, 112, RJ54N1_MAX_WIDTH, align,
&mf->height, 84, RJ54N1_MAX_HEIGHT, align, 0);
return 0;
}
static int rj54n1_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
const struct rj54n1_datafmt *fmt;
int output_w, output_h, max_w, max_h,
input_w = rj54n1->rect.width, input_h = rj54n1->rect.height;
int ret;
rj54n1_try_fmt(sd, mf);
ret = reg_read(client, RJ54N1_RESET_STANDBY);
if (ret < 0)
return ret;
if (!(ret & E_EXCLK)) {
ret = rj54n1_reg_init(client);
if (ret < 0)
return ret;
}
dev_dbg(&client->dev, "%s: code = %d, width = %u, height = %u\n",
__func__, mf->code, mf->width, mf->height);
switch (mf->code) {
case V4L2_MBUS_FMT_YUYV8_2X8:
ret = reg_write(client, RJ54N1_OUT_SEL, 0);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
break;
case V4L2_MBUS_FMT_YVYU8_2X8:
ret = reg_write(client, RJ54N1_OUT_SEL, 0);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
break;
case V4L2_MBUS_FMT_RGB565_2X8_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 0x11);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
break;
case V4L2_MBUS_FMT_RGB565_2X8_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 0x11);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
break;
case V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 0);
break;
case V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 8);
break;
case V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 0);
break;
case V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 8);
break;
case V4L2_MBUS_FMT_SBGGR10_1X10:
ret = reg_write(client, RJ54N1_OUT_SEL, 5);
break;
default:
ret = -EINVAL;
}
if (!ret)
ret = reg_set(client, RJ54N1_OCLK_SEL_EN,
(mf->code == V4L2_MBUS_FMT_SBGGR10_1X10) << 1, 2);
if (ret < 0)
return ret;
max_w = mf->width * (16 * 1024 - 1) / 1024;
if (input_w > max_w)
input_w = max_w;
max_h = mf->height * (16 * 1024 - 1) / 1024;
if (input_h > max_h)
input_h = max_h;
output_w = mf->width;
output_h = mf->height;
ret = rj54n1_sensor_scale(sd, &input_w, &input_h, &output_w, &output_h);
if (ret < 0)
return ret;
fmt = rj54n1_find_datafmt(mf->code, rj54n1_colour_fmts,
ARRAY_SIZE(rj54n1_colour_fmts));
rj54n1->fmt = fmt;
rj54n1->resize = ret;
rj54n1->rect.width = input_w;
rj54n1->rect.height = input_h;
rj54n1->width = output_w;
rj54n1->height = output_h;
mf->width = output_w;
mf->height = output_h;
mf->field = V4L2_FIELD_NONE;
mf->colorspace = fmt->colorspace;
return 0;
}
static int rj54n1_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = V4L2_IDENT_RJ54N1CB0C;
id->revision = 0;
return 0;
}
static int rj54n1_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR ||
reg->reg < 0x400 || reg->reg > 0x1fff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
reg->size = 1;
reg->val = reg_read(client, reg->reg);
if (reg->val > 0xff)
return -EIO;
return 0;
}
static int rj54n1_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR ||
reg->reg < 0x400 || reg->reg > 0x1fff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
if (reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int rj54n1_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
data = reg_read(client, RJ54N1_MIRROR_STILL_MODE);
if (data < 0)
return -EIO;
ctrl->value = !(data & 1);
break;
case V4L2_CID_HFLIP:
data = reg_read(client, RJ54N1_MIRROR_STILL_MODE);
if (data < 0)
return -EIO;
ctrl->value = !(data & 2);
break;
case V4L2_CID_GAIN:
data = reg_read(client, RJ54N1_Y_GAIN);
if (data < 0)
return -EIO;
ctrl->value = data / 2;
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
ctrl->value = rj54n1->auto_wb;
break;
}
return 0;
}
static int rj54n1_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
int data;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
const struct v4l2_queryctrl *qctrl;
qctrl = soc_camera_find_qctrl(&rj54n1_ops, ctrl->id);
if (!qctrl)
return -EINVAL;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->value)
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 0, 1);
else
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 1, 1);
if (data < 0)
return -EIO;
break;
case V4L2_CID_HFLIP:
if (ctrl->value)
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 0, 2);
else
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 2, 2);
if (data < 0)
return -EIO;
break;
case V4L2_CID_GAIN:
if (ctrl->value > qctrl->maximum ||
ctrl->value < qctrl->minimum)
return -EINVAL;
else if (reg_write(client, RJ54N1_Y_GAIN, ctrl->value * 2) < 0)
return -EIO;
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
if (reg_set(client, RJ54N1_WB_SEL_WEIGHT_I, ctrl->value << 7,
0x80) < 0)
return -EIO;
rj54n1->auto_wb = ctrl->value;
break;
}
return 0;
}
static int rj54n1_video_probe(struct soc_camera_device *icd,
struct i2c_client *client,
struct rj54n1_pdata *priv)
{
int data1, data2;
int ret;
BUG_ON(!icd->parent ||
to_soc_camera_host(icd->parent)->nr != icd->iface);
data1 = reg_read(client, RJ54N1_DEV_CODE);
data2 = reg_read(client, RJ54N1_DEV_CODE2);
if (data1 != 0x51 || data2 != 0x10) {
ret = -ENODEV;
dev_info(&client->dev, "No RJ54N1CB0C found, read 0x%x:0x%x\n",
data1, data2);
goto ei2c;
}
ret = reg_write(client, RJ54N1_IOC, priv->ioctl_high << 7);
if (ret < 0)
goto ei2c;
dev_info(&client->dev, "Detected a RJ54N1CB0C chip ID 0x%x:0x%x\n",
data1, data2);
ei2c:
return ret;
}
static int rj54n1_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct rj54n1 *rj54n1;
struct soc_camera_device *icd = client->dev.platform_data;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl;
struct rj54n1_pdata *rj54n1_priv;
int ret;
if (!icd) {
dev_err(&client->dev, "RJ54N1CB0C: missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl || !icl->priv) {
dev_err(&client->dev, "RJ54N1CB0C: missing platform data!\n");
return -EINVAL;
}
rj54n1_priv = icl->priv;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_BYTE\n");
return -EIO;
}
rj54n1 = kzalloc(sizeof(struct rj54n1), GFP_KERNEL);
if (!rj54n1)
return -ENOMEM;
v4l2_i2c_subdev_init(&rj54n1->subdev, client, &rj54n1_subdev_ops);
icd->ops = &rj54n1_ops;
rj54n1->clk_div = clk_div;
rj54n1->rect.left = RJ54N1_COLUMN_SKIP;
rj54n1->rect.top = RJ54N1_ROW_SKIP;
rj54n1->rect.width = RJ54N1_MAX_WIDTH;
rj54n1->rect.height = RJ54N1_MAX_HEIGHT;
rj54n1->width = RJ54N1_MAX_WIDTH;
rj54n1->height = RJ54N1_MAX_HEIGHT;
rj54n1->fmt = &rj54n1_colour_fmts[0];
rj54n1->resize = 1024;
rj54n1->tgclk_mhz = (rj54n1_priv->mclk_freq / PLL_L * PLL_N) /
(clk_div.ratio_tg + 1) / (clk_div.ratio_t + 1);
ret = rj54n1_video_probe(icd, client, rj54n1_priv);
if (ret < 0) {
icd->ops = NULL;
kfree(rj54n1);
return ret;
}
return ret;
}
static int rj54n1_remove(struct i2c_client *client)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
struct soc_camera_device *icd = client->dev.platform_data;
struct soc_camera_link *icl = to_soc_camera_link(icd);
icd->ops = NULL;
if (icl->free_bus)
icl->free_bus(icl);
kfree(rj54n1);
return 0;
}
static int __init rj54n1_mod_init(void)
{
return i2c_add_driver(&rj54n1_i2c_driver);
}
static void __exit rj54n1_mod_exit(void)
{
i2c_del_driver(&rj54n1_i2c_driver);
}
