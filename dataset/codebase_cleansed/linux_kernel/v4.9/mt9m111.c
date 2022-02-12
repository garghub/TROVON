static const struct mt9m111_datafmt *mt9m111_find_datafmt(struct mt9m111 *mt9m111,
u32 code)
{
int i;
for (i = 0; i < ARRAY_SIZE(mt9m111_colour_fmts); i++)
if (mt9m111_colour_fmts[i].code == code)
return mt9m111_colour_fmts + i;
return mt9m111->fmt;
}
static struct mt9m111 *to_mt9m111(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct mt9m111, subdev);
}
static int reg_page_map_set(struct i2c_client *client, const u16 reg)
{
int ret;
u16 page;
struct mt9m111 *mt9m111 = to_mt9m111(client);
page = (reg >> 8);
if (page == mt9m111->lastpage)
return 0;
if (page > 2)
return -EINVAL;
ret = i2c_smbus_write_word_swapped(client, MT9M111_PAGE_MAP, page);
if (!ret)
mt9m111->lastpage = page;
return ret;
}
static int mt9m111_reg_read(struct i2c_client *client, const u16 reg)
{
int ret;
ret = reg_page_map_set(client, reg);
if (!ret)
ret = i2c_smbus_read_word_swapped(client, reg & 0xff);
dev_dbg(&client->dev, "read reg.%03x -> %04x\n", reg, ret);
return ret;
}
static int mt9m111_reg_write(struct i2c_client *client, const u16 reg,
const u16 data)
{
int ret;
ret = reg_page_map_set(client, reg);
if (!ret)
ret = i2c_smbus_write_word_swapped(client, reg & 0xff, data);
dev_dbg(&client->dev, "write reg.%03x = %04x -> %d\n", reg, data, ret);
return ret;
}
static int mt9m111_reg_set(struct i2c_client *client, const u16 reg,
const u16 data)
{
int ret;
ret = mt9m111_reg_read(client, reg);
if (ret >= 0)
ret = mt9m111_reg_write(client, reg, ret | data);
return ret;
}
static int mt9m111_reg_clear(struct i2c_client *client, const u16 reg,
const u16 data)
{
int ret;
ret = mt9m111_reg_read(client, reg);
if (ret >= 0)
ret = mt9m111_reg_write(client, reg, ret & ~data);
return ret;
}
static int mt9m111_reg_mask(struct i2c_client *client, const u16 reg,
const u16 data, const u16 mask)
{
int ret;
ret = mt9m111_reg_read(client, reg);
if (ret >= 0)
ret = mt9m111_reg_write(client, reg, (ret & ~mask) | data);
return ret;
}
static int mt9m111_set_context(struct mt9m111 *mt9m111,
struct mt9m111_context *ctx)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
return reg_write(CONTEXT_CONTROL, ctx->control);
}
static int mt9m111_setup_rect_ctx(struct mt9m111 *mt9m111,
struct mt9m111_context *ctx, struct v4l2_rect *rect,
unsigned int width, unsigned int height)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret = mt9m111_reg_write(client, ctx->reducer_xzoom, rect->width);
if (!ret)
ret = mt9m111_reg_write(client, ctx->reducer_yzoom, rect->height);
if (!ret)
ret = mt9m111_reg_write(client, ctx->reducer_xsize, width);
if (!ret)
ret = mt9m111_reg_write(client, ctx->reducer_ysize, height);
return ret;
}
static int mt9m111_setup_geometry(struct mt9m111 *mt9m111, struct v4l2_rect *rect,
int width, int height, u32 code)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
ret = reg_write(COLUMN_START, rect->left);
if (!ret)
ret = reg_write(ROW_START, rect->top);
if (!ret)
ret = reg_write(WINDOW_WIDTH, rect->width);
if (!ret)
ret = reg_write(WINDOW_HEIGHT, rect->height);
if (code != MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE) {
if (!ret)
ret = mt9m111_setup_rect_ctx(mt9m111, &context_b,
rect, width, height);
if (!ret)
ret = mt9m111_setup_rect_ctx(mt9m111, &context_a,
rect, width, height);
}
dev_dbg(&client->dev, "%s(%x): %ux%u@%u:%u -> %ux%u = %d\n",
__func__, code, rect->width, rect->height, rect->left, rect->top,
width, height, ret);
return ret;
}
static int mt9m111_enable(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
return reg_write(RESET, MT9M111_RESET_CHIP_ENABLE);
}
static int mt9m111_reset(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
ret = reg_set(RESET, MT9M111_RESET_RESET_MODE);
if (!ret)
ret = reg_set(RESET, MT9M111_RESET_RESET_SOC);
if (!ret)
ret = reg_clear(RESET, MT9M111_RESET_RESET_MODE
| MT9M111_RESET_RESET_SOC);
return ret;
}
static int mt9m111_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m111 *mt9m111 = to_mt9m111(client);
struct v4l2_rect rect = sel->r;
int width, height;
int ret, align = 0;
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE ||
sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
if (mt9m111->fmt->code == MEDIA_BUS_FMT_SBGGR8_1X8 ||
mt9m111->fmt->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE) {
align = 1;
}
v4l_bound_align_image(&rect.width, 2, MT9M111_MAX_WIDTH, align,
&rect.height, 2, MT9M111_MAX_HEIGHT, align, 0);
rect.left = clamp(rect.left, MT9M111_MIN_DARK_COLS,
MT9M111_MIN_DARK_COLS + MT9M111_MAX_WIDTH -
(__s32)rect.width);
rect.top = clamp(rect.top, MT9M111_MIN_DARK_ROWS,
MT9M111_MIN_DARK_ROWS + MT9M111_MAX_HEIGHT -
(__s32)rect.height);
width = min(mt9m111->width, rect.width);
height = min(mt9m111->height, rect.height);
ret = mt9m111_setup_geometry(mt9m111, &rect, width, height, mt9m111->fmt->code);
if (!ret) {
mt9m111->rect = rect;
mt9m111->width = width;
mt9m111->height = height;
}
return ret;
}
static int mt9m111_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m111 *mt9m111 = to_mt9m111(client);
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
sel->r.left = MT9M111_MIN_DARK_COLS;
sel->r.top = MT9M111_MIN_DARK_ROWS;
sel->r.width = MT9M111_MAX_WIDTH;
sel->r.height = MT9M111_MAX_HEIGHT;
return 0;
case V4L2_SEL_TGT_CROP:
sel->r = mt9m111->rect;
return 0;
default:
return -EINVAL;
}
}
static int mt9m111_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
if (format->pad)
return -EINVAL;
mf->width = mt9m111->width;
mf->height = mt9m111->height;
mf->code = mt9m111->fmt->code;
mf->colorspace = mt9m111->fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int mt9m111_set_pixfmt(struct mt9m111 *mt9m111,
u32 code)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
u16 data_outfmt2, mask_outfmt2 = MT9M111_OUTFMT_PROCESSED_BAYER |
MT9M111_OUTFMT_BYPASS_IFP | MT9M111_OUTFMT_RGB |
MT9M111_OUTFMT_RGB565 | MT9M111_OUTFMT_RGB555 |
MT9M111_OUTFMT_RGB444x | MT9M111_OUTFMT_RGBx444 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
int ret;
switch (code) {
case MEDIA_BUS_FMT_SBGGR8_1X8:
data_outfmt2 = MT9M111_OUTFMT_PROCESSED_BAYER |
MT9M111_OUTFMT_RGB;
break;
case MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE:
data_outfmt2 = MT9M111_OUTFMT_BYPASS_IFP | MT9M111_OUTFMT_RGB;
break;
case MEDIA_BUS_FMT_RGB555_2X8_PADHI_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB555 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB555;
break;
case MEDIA_BUS_FMT_RGB565_2X8_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case MEDIA_BUS_FMT_RGB565_2X8_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565;
break;
case MEDIA_BUS_FMT_BGR565_2X8_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case MEDIA_BUS_FMT_BGR565_2X8_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case MEDIA_BUS_FMT_UYVY8_2X8:
data_outfmt2 = 0;
break;
case MEDIA_BUS_FMT_VYUY8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case MEDIA_BUS_FMT_YUYV8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case MEDIA_BUS_FMT_YVYU8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
default:
dev_err(&client->dev, "Pixel format not handled: %x\n", code);
return -EINVAL;
}
ret = mt9m111_reg_mask(client, context_a.output_fmt_ctrl2,
data_outfmt2, mask_outfmt2);
if (!ret)
ret = mt9m111_reg_mask(client, context_b.output_fmt_ctrl2,
data_outfmt2, mask_outfmt2);
return ret;
}
static int mt9m111_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
const struct mt9m111_datafmt *fmt;
struct v4l2_rect *rect = &mt9m111->rect;
bool bayer;
int ret;
if (format->pad)
return -EINVAL;
fmt = mt9m111_find_datafmt(mt9m111, mf->code);
bayer = fmt->code == MEDIA_BUS_FMT_SBGGR8_1X8 ||
fmt->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE;
if (bayer) {
rect->width = ALIGN(rect->width, 2);
rect->height = ALIGN(rect->height, 2);
}
if (fmt->code == MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE) {
mf->width = rect->width;
mf->height = rect->height;
} else {
if (mf->width > rect->width)
mf->width = rect->width;
if (mf->height > rect->height)
mf->height = rect->height;
}
dev_dbg(&client->dev, "%s(): %ux%u, code=%x\n", __func__,
mf->width, mf->height, fmt->code);
mf->code = fmt->code;
mf->colorspace = fmt->colorspace;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
cfg->try_fmt = *mf;
return 0;
}
ret = mt9m111_setup_geometry(mt9m111, rect, mf->width, mf->height, mf->code);
if (!ret)
ret = mt9m111_set_pixfmt(mt9m111, mf->code);
if (!ret) {
mt9m111->width = mf->width;
mt9m111->height = mf->height;
mt9m111->fmt = fmt;
}
return ret;
}
static int mt9m111_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int val;
if (reg->reg > 0x2ff)
return -EINVAL;
val = mt9m111_reg_read(client, reg->reg);
reg->size = 2;
reg->val = (u64)val;
if (reg->val > 0xffff)
return -EIO;
return 0;
}
static int mt9m111_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->reg > 0x2ff)
return -EINVAL;
if (mt9m111_reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int mt9m111_set_flip(struct mt9m111 *mt9m111, int flip, int mask)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
if (flip)
ret = mt9m111_reg_set(client, mt9m111->ctx->read_mode, mask);
else
ret = mt9m111_reg_clear(client, mt9m111->ctx->read_mode, mask);
return ret;
}
static int mt9m111_get_global_gain(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int data;
data = reg_read(GLOBAL_GAIN);
if (data >= 0)
return (data & 0x2f) * (1 << ((data >> 10) & 1)) *
(1 << ((data >> 9) & 1));
return data;
}
static int mt9m111_set_global_gain(struct mt9m111 *mt9m111, int gain)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
u16 val;
if (gain > 63 * 2 * 2)
return -EINVAL;
if ((gain >= 64 * 2) && (gain < 63 * 2 * 2))
val = (1 << 10) | (1 << 9) | (gain / 4);
else if ((gain >= 64) && (gain < 64 * 2))
val = (1 << 9) | (gain / 2);
else
val = gain;
return reg_write(GLOBAL_GAIN, val);
}
static int mt9m111_set_autoexposure(struct mt9m111 *mt9m111, int val)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
if (val == V4L2_EXPOSURE_AUTO)
return reg_set(OPER_MODE_CTRL, MT9M111_OPMODE_AUTOEXPO_EN);
return reg_clear(OPER_MODE_CTRL, MT9M111_OPMODE_AUTOEXPO_EN);
}
static int mt9m111_set_autowhitebalance(struct mt9m111 *mt9m111, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
if (on)
return reg_set(OPER_MODE_CTRL, MT9M111_OPMODE_AUTOWHITEBAL_EN);
return reg_clear(OPER_MODE_CTRL, MT9M111_OPMODE_AUTOWHITEBAL_EN);
}
static int mt9m111_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9m111 *mt9m111 = container_of(ctrl->handler,
struct mt9m111, hdl);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
return mt9m111_set_flip(mt9m111, ctrl->val,
MT9M111_RMB_MIRROR_ROWS);
case V4L2_CID_HFLIP:
return mt9m111_set_flip(mt9m111, ctrl->val,
MT9M111_RMB_MIRROR_COLS);
case V4L2_CID_GAIN:
return mt9m111_set_global_gain(mt9m111, ctrl->val);
case V4L2_CID_EXPOSURE_AUTO:
return mt9m111_set_autoexposure(mt9m111, ctrl->val);
case V4L2_CID_AUTO_WHITE_BALANCE:
return mt9m111_set_autowhitebalance(mt9m111, ctrl->val);
}
return -EINVAL;
}
static int mt9m111_suspend(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
v4l2_ctrl_s_ctrl(mt9m111->gain, mt9m111_get_global_gain(mt9m111));
ret = reg_set(RESET, MT9M111_RESET_RESET_MODE);
if (!ret)
ret = reg_set(RESET, MT9M111_RESET_RESET_SOC |
MT9M111_RESET_OUTPUT_DISABLE |
MT9M111_RESET_ANALOG_STANDBY);
if (!ret)
ret = reg_clear(RESET, MT9M111_RESET_CHIP_ENABLE);
return ret;
}
static void mt9m111_restore_state(struct mt9m111 *mt9m111)
{
mt9m111_set_context(mt9m111, mt9m111->ctx);
mt9m111_set_pixfmt(mt9m111, mt9m111->fmt->code);
mt9m111_setup_geometry(mt9m111, &mt9m111->rect,
mt9m111->width, mt9m111->height, mt9m111->fmt->code);
v4l2_ctrl_handler_setup(&mt9m111->hdl);
}
static int mt9m111_resume(struct mt9m111 *mt9m111)
{
int ret = mt9m111_enable(mt9m111);
if (!ret)
ret = mt9m111_reset(mt9m111);
if (!ret)
mt9m111_restore_state(mt9m111);
return ret;
}
static int mt9m111_init(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
ret = mt9m111_enable(mt9m111);
if (!ret)
ret = mt9m111_reset(mt9m111);
if (!ret)
ret = mt9m111_set_context(mt9m111, mt9m111->ctx);
if (ret)
dev_err(&client->dev, "mt9m111 init failed: %d\n", ret);
return ret;
}
static int mt9m111_power_on(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
ret = v4l2_clk_enable(mt9m111->clk);
if (ret < 0)
return ret;
ret = mt9m111_resume(mt9m111);
if (ret < 0) {
dev_err(&client->dev, "Failed to resume the sensor: %d\n", ret);
v4l2_clk_disable(mt9m111->clk);
}
return ret;
}
static void mt9m111_power_off(struct mt9m111 *mt9m111)
{
mt9m111_suspend(mt9m111);
v4l2_clk_disable(mt9m111->clk);
}
static int mt9m111_s_power(struct v4l2_subdev *sd, int on)
{
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
int ret = 0;
mutex_lock(&mt9m111->power_lock);
if (mt9m111->power_count == !on) {
if (on)
ret = mt9m111_power_on(mt9m111);
else
mt9m111_power_off(mt9m111);
}
if (!ret) {
mt9m111->power_count += on ? 1 : -1;
WARN_ON(mt9m111->power_count < 0);
}
mutex_unlock(&mt9m111->power_lock);
return ret;
}
static int mt9m111_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= ARRAY_SIZE(mt9m111_colour_fmts))
return -EINVAL;
code->code = mt9m111_colour_fmts[code->index].code;
return 0;
}
static int mt9m111_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
return 0;
}
static int mt9m111_video_probe(struct i2c_client *client)
{
struct mt9m111 *mt9m111 = to_mt9m111(client);
s32 data;
int ret;
ret = mt9m111_s_power(&mt9m111->subdev, 1);
if (ret < 0)
return ret;
data = reg_read(CHIP_VERSION);
switch (data) {
case 0x143a:
dev_info(&client->dev,
"Detected a MT9M111/MT9M131 chip ID %x\n", data);
break;
case 0x148c:
dev_info(&client->dev, "Detected a MT9M112 chip ID %x\n", data);
break;
default:
dev_err(&client->dev,
"No MT9M111/MT9M112/MT9M131 chip detected register read %x\n",
data);
ret = -ENODEV;
goto done;
}
ret = mt9m111_init(mt9m111);
if (ret)
goto done;
ret = v4l2_ctrl_handler_setup(&mt9m111->hdl);
done:
mt9m111_s_power(&mt9m111->subdev, 0);
return ret;
}
static int mt9m111_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9m111 *mt9m111;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9m111 = devm_kzalloc(&client->dev, sizeof(struct mt9m111), GFP_KERNEL);
if (!mt9m111)
return -ENOMEM;
mt9m111->clk = v4l2_clk_get(&client->dev, "mclk");
if (IS_ERR(mt9m111->clk))
return -EPROBE_DEFER;
mt9m111->ctx = &context_b;
v4l2_i2c_subdev_init(&mt9m111->subdev, client, &mt9m111_subdev_ops);
v4l2_ctrl_handler_init(&mt9m111->hdl, 5);
v4l2_ctrl_new_std(&mt9m111->hdl, &mt9m111_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&mt9m111->hdl, &mt9m111_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&mt9m111->hdl, &mt9m111_ctrl_ops,
V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1);
mt9m111->gain = v4l2_ctrl_new_std(&mt9m111->hdl, &mt9m111_ctrl_ops,
V4L2_CID_GAIN, 0, 63 * 2 * 2, 1, 32);
v4l2_ctrl_new_std_menu(&mt9m111->hdl,
&mt9m111_ctrl_ops, V4L2_CID_EXPOSURE_AUTO, 1, 0,
V4L2_EXPOSURE_AUTO);
mt9m111->subdev.ctrl_handler = &mt9m111->hdl;
if (mt9m111->hdl.error) {
ret = mt9m111->hdl.error;
goto out_clkput;
}
mt9m111->rect.left = MT9M111_MIN_DARK_COLS;
mt9m111->rect.top = MT9M111_MIN_DARK_ROWS;
mt9m111->rect.width = MT9M111_MAX_WIDTH;
mt9m111->rect.height = MT9M111_MAX_HEIGHT;
mt9m111->fmt = &mt9m111_colour_fmts[0];
mt9m111->lastpage = -1;
mutex_init(&mt9m111->power_lock);
ret = mt9m111_video_probe(client);
if (ret < 0)
goto out_hdlfree;
mt9m111->subdev.dev = &client->dev;
ret = v4l2_async_register_subdev(&mt9m111->subdev);
if (ret < 0)
goto out_hdlfree;
return 0;
out_hdlfree:
v4l2_ctrl_handler_free(&mt9m111->hdl);
out_clkput:
v4l2_clk_put(mt9m111->clk);
return ret;
}
static int mt9m111_remove(struct i2c_client *client)
{
struct mt9m111 *mt9m111 = to_mt9m111(client);
v4l2_async_unregister_subdev(&mt9m111->subdev);
v4l2_clk_put(mt9m111->clk);
v4l2_ctrl_handler_free(&mt9m111->hdl);
return 0;
}
