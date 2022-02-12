static const struct rj54n1_datafmt *rj54n1_find_datafmt(
u32 code, const struct rj54n1_datafmt *fmt,
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
u32 *code)
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
static int rj54n1_s_crop(struct v4l2_subdev *sd, const struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct rj54n1 *rj54n1 = to_rj54n1(client);
const struct v4l2_rect *rect = &a->c;
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
int align = mf->code == MEDIA_BUS_FMT_SBGGR10_1X10 ||
mf->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE ||
mf->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE ||
mf->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE ||
mf->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE;
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
case MEDIA_BUS_FMT_YUYV8_2X8:
ret = reg_write(client, RJ54N1_OUT_SEL, 0);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
break;
case MEDIA_BUS_FMT_YVYU8_2X8:
ret = reg_write(client, RJ54N1_OUT_SEL, 0);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
break;
case MEDIA_BUS_FMT_RGB565_2X8_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 0x11);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
break;
case MEDIA_BUS_FMT_RGB565_2X8_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 0x11);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
break;
case MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 0);
break;
case MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 8, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 8);
break;
case MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 0);
break;
case MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE:
ret = reg_write(client, RJ54N1_OUT_SEL, 4);
if (!ret)
ret = reg_set(client, RJ54N1_BYTE_SWAP, 0, 8);
if (!ret)
ret = reg_write(client, RJ54N1_RA_SEL_UL, 8);
break;
case MEDIA_BUS_FMT_SBGGR10_1X10:
ret = reg_write(client, RJ54N1_OUT_SEL, 5);
break;
default:
ret = -EINVAL;
}
if (!ret)
ret = reg_set(client, RJ54N1_OCLK_SEL_EN,
(mf->code == MEDIA_BUS_FMT_SBGGR10_1X10) << 1, 2);
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
static int rj54n1_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg < 0x400 || reg->reg > 0x1fff)
return -EINVAL;
reg->size = 1;
reg->val = reg_read(client, reg->reg);
if (reg->val > 0xff)
return -EIO;
return 0;
}
static int rj54n1_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg < 0x400 || reg->reg > 0x1fff)
return -EINVAL;
if (reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int rj54n1_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct rj54n1 *rj54n1 = to_rj54n1(client);
return soc_camera_set_power(&client->dev, ssdd, rj54n1->clk, on);
}
static int rj54n1_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct rj54n1 *rj54n1 = container_of(ctrl->handler, struct rj54n1, hdl);
struct v4l2_subdev *sd = &rj54n1->subdev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->val)
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 0, 1);
else
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 1, 1);
if (data < 0)
return -EIO;
return 0;
case V4L2_CID_HFLIP:
if (ctrl->val)
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 0, 2);
else
data = reg_set(client, RJ54N1_MIRROR_STILL_MODE, 2, 2);
if (data < 0)
return -EIO;
return 0;
case V4L2_CID_GAIN:
if (reg_write(client, RJ54N1_Y_GAIN, ctrl->val * 2) < 0)
return -EIO;
return 0;
case V4L2_CID_AUTO_WHITE_BALANCE:
if (reg_set(client, RJ54N1_WB_SEL_WEIGHT_I, ctrl->val << 7,
0x80) < 0)
return -EIO;
rj54n1->auto_wb = ctrl->val;
return 0;
}
return -EINVAL;
}
static int rj54n1_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
cfg->flags =
V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_PCLK_SAMPLE_FALLING |
V4L2_MBUS_MASTER | V4L2_MBUS_DATA_ACTIVE_HIGH |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(ssdd, cfg);
return 0;
}
static int rj54n1_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
if (soc_camera_apply_board_flags(ssdd, cfg) &
V4L2_MBUS_PCLK_SAMPLE_RISING)
return reg_write(client, RJ54N1_OUT_SIGPO, 1 << 4);
else
return reg_write(client, RJ54N1_OUT_SIGPO, 0);
}
static int rj54n1_video_probe(struct i2c_client *client,
struct rj54n1_pdata *priv)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
int data1, data2;
int ret;
ret = rj54n1_s_power(&rj54n1->subdev, 1);
if (ret < 0)
return ret;
data1 = reg_read(client, RJ54N1_DEV_CODE);
data2 = reg_read(client, RJ54N1_DEV_CODE2);
if (data1 != 0x51 || data2 != 0x10) {
ret = -ENODEV;
dev_info(&client->dev, "No RJ54N1CB0C found, read 0x%x:0x%x\n",
data1, data2);
goto done;
}
ret = reg_write(client, RJ54N1_IOC, priv->ioctl_high << 7);
if (ret < 0)
goto done;
dev_info(&client->dev, "Detected a RJ54N1CB0C chip ID 0x%x:0x%x\n",
data1, data2);
ret = v4l2_ctrl_handler_setup(&rj54n1->hdl);
done:
rj54n1_s_power(&rj54n1->subdev, 0);
return ret;
}
static int rj54n1_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct rj54n1 *rj54n1;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct rj54n1_pdata *rj54n1_priv;
int ret;
if (!ssdd || !ssdd->drv_priv) {
dev_err(&client->dev, "RJ54N1CB0C: missing platform data!\n");
return -EINVAL;
}
rj54n1_priv = ssdd->drv_priv;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_BYTE\n");
return -EIO;
}
rj54n1 = devm_kzalloc(&client->dev, sizeof(struct rj54n1), GFP_KERNEL);
if (!rj54n1)
return -ENOMEM;
v4l2_i2c_subdev_init(&rj54n1->subdev, client, &rj54n1_subdev_ops);
v4l2_ctrl_handler_init(&rj54n1->hdl, 4);
v4l2_ctrl_new_std(&rj54n1->hdl, &rj54n1_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&rj54n1->hdl, &rj54n1_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&rj54n1->hdl, &rj54n1_ctrl_ops,
V4L2_CID_GAIN, 0, 127, 1, 66);
v4l2_ctrl_new_std(&rj54n1->hdl, &rj54n1_ctrl_ops,
V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1);
rj54n1->subdev.ctrl_handler = &rj54n1->hdl;
if (rj54n1->hdl.error)
return rj54n1->hdl.error;
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
rj54n1->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(rj54n1->clk)) {
ret = PTR_ERR(rj54n1->clk);
goto eclkget;
}
ret = rj54n1_video_probe(client, rj54n1_priv);
if (ret < 0) {
v4l2_clk_put(rj54n1->clk);
eclkget:
v4l2_ctrl_handler_free(&rj54n1->hdl);
}
return ret;
}
static int rj54n1_remove(struct i2c_client *client)
{
struct rj54n1 *rj54n1 = to_rj54n1(client);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
v4l2_clk_put(rj54n1->clk);
v4l2_device_unregister_subdev(&rj54n1->subdev);
if (ssdd->free_bus)
ssdd->free_bus(ssdd);
v4l2_ctrl_handler_free(&rj54n1->hdl);
return 0;
}
