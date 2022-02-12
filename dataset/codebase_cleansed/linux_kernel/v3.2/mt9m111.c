static const struct mt9m111_datafmt *mt9m111_find_datafmt(
enum v4l2_mbus_pixelcode code, const struct mt9m111_datafmt *fmt,
int n)
{
int i;
for (i = 0; i < n; i++)
if (fmt[i].code == code)
return fmt + i;
return NULL;
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
ret = i2c_smbus_write_word_data(client, MT9M111_PAGE_MAP, swab16(page));
if (!ret)
mt9m111->lastpage = page;
return ret;
}
static int mt9m111_reg_read(struct i2c_client *client, const u16 reg)
{
int ret;
ret = reg_page_map_set(client, reg);
if (!ret)
ret = swab16(i2c_smbus_read_word_data(client, reg & 0xff));
dev_dbg(&client->dev, "read reg.%03x -> %04x\n", reg, ret);
return ret;
}
static int mt9m111_reg_write(struct i2c_client *client, const u16 reg,
const u16 data)
{
int ret;
ret = reg_page_map_set(client, reg);
if (!ret)
ret = i2c_smbus_write_word_data(client, reg & 0xff,
swab16(data));
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
enum mt9m111_context ctxt)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int valB = MT9M111_CTXT_CTRL_RESTART | MT9M111_CTXT_CTRL_DEFECTCOR_B
| MT9M111_CTXT_CTRL_RESIZE_B | MT9M111_CTXT_CTRL_CTRL2_B
| MT9M111_CTXT_CTRL_GAMMA_B | MT9M111_CTXT_CTRL_READ_MODE_B
| MT9M111_CTXT_CTRL_VBLANK_SEL_B
| MT9M111_CTXT_CTRL_HBLANK_SEL_B;
int valA = MT9M111_CTXT_CTRL_RESTART;
if (ctxt == HIGHPOWER)
return reg_write(CONTEXT_CONTROL, valB);
else
return reg_write(CONTEXT_CONTROL, valA);
}
static int mt9m111_setup_rect(struct mt9m111 *mt9m111,
struct v4l2_rect *rect)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret, is_raw_format;
int width = rect->width;
int height = rect->height;
if (mt9m111->fmt->code == V4L2_MBUS_FMT_SBGGR8_1X8 ||
mt9m111->fmt->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE)
is_raw_format = 1;
else
is_raw_format = 0;
ret = reg_write(COLUMN_START, rect->left);
if (!ret)
ret = reg_write(ROW_START, rect->top);
if (is_raw_format) {
if (!ret)
ret = reg_write(WINDOW_WIDTH, width);
if (!ret)
ret = reg_write(WINDOW_HEIGHT, height);
} else {
if (!ret)
ret = reg_write(REDUCER_XZOOM_B, MT9M111_MAX_WIDTH);
if (!ret)
ret = reg_write(REDUCER_YZOOM_B, MT9M111_MAX_HEIGHT);
if (!ret)
ret = reg_write(REDUCER_XSIZE_B, width);
if (!ret)
ret = reg_write(REDUCER_YSIZE_B, height);
if (!ret)
ret = reg_write(REDUCER_XZOOM_A, MT9M111_MAX_WIDTH);
if (!ret)
ret = reg_write(REDUCER_YZOOM_A, MT9M111_MAX_HEIGHT);
if (!ret)
ret = reg_write(REDUCER_XSIZE_A, width);
if (!ret)
ret = reg_write(REDUCER_YSIZE_A, height);
}
return ret;
}
static int mt9m111_enable(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
ret = reg_set(RESET, MT9M111_RESET_CHIP_ENABLE);
if (!ret)
mt9m111->powered = 1;
return ret;
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
static int mt9m111_make_rect(struct mt9m111 *mt9m111,
struct v4l2_rect *rect)
{
if (mt9m111->fmt->code == V4L2_MBUS_FMT_SBGGR8_1X8 ||
mt9m111->fmt->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE) {
rect->width = ALIGN(rect->width, 2);
rect->height = ALIGN(rect->height, 2);
}
soc_camera_limit_side(&rect->left, &rect->width,
MT9M111_MIN_DARK_COLS, 2, MT9M111_MAX_WIDTH);
soc_camera_limit_side(&rect->top, &rect->height,
MT9M111_MIN_DARK_ROWS, 2, MT9M111_MAX_HEIGHT);
return mt9m111_setup_rect(mt9m111, rect);
}
static int mt9m111_s_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct v4l2_rect rect = a->c;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
int ret;
dev_dbg(&client->dev, "%s left=%d, top=%d, width=%d, height=%d\n",
__func__, rect.left, rect.top, rect.width, rect.height);
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
ret = mt9m111_make_rect(mt9m111, &rect);
if (!ret)
mt9m111->rect = rect;
return ret;
}
static int mt9m111_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
a->c = mt9m111->rect;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int mt9m111_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
a->bounds.left = MT9M111_MIN_DARK_COLS;
a->bounds.top = MT9M111_MIN_DARK_ROWS;
a->bounds.width = MT9M111_MAX_WIDTH;
a->bounds.height = MT9M111_MAX_HEIGHT;
a->defrect = a->bounds;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int mt9m111_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
mf->width = mt9m111->rect.width;
mf->height = mt9m111->rect.height;
mf->code = mt9m111->fmt->code;
mf->colorspace = mt9m111->fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int mt9m111_set_pixfmt(struct mt9m111 *mt9m111,
enum v4l2_mbus_pixelcode code)
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
case V4L2_MBUS_FMT_SBGGR8_1X8:
data_outfmt2 = MT9M111_OUTFMT_PROCESSED_BAYER |
MT9M111_OUTFMT_RGB;
break;
case V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE:
data_outfmt2 = MT9M111_OUTFMT_BYPASS_IFP | MT9M111_OUTFMT_RGB;
break;
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB555 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB555;
break;
case V4L2_MBUS_FMT_RGB565_2X8_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case V4L2_MBUS_FMT_RGB565_2X8_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565;
break;
case V4L2_MBUS_FMT_BGR565_2X8_BE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case V4L2_MBUS_FMT_BGR565_2X8_LE:
data_outfmt2 = MT9M111_OUTFMT_RGB | MT9M111_OUTFMT_RGB565 |
MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case V4L2_MBUS_FMT_UYVY8_2X8:
data_outfmt2 = 0;
break;
case V4L2_MBUS_FMT_VYUY8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
case V4L2_MBUS_FMT_YUYV8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN;
break;
case V4L2_MBUS_FMT_YVYU8_2X8:
data_outfmt2 = MT9M111_OUTFMT_SWAP_YCbCr_C_Y_RGB_EVEN |
MT9M111_OUTFMT_SWAP_YCbCr_Cb_Cr_RGB_R_B;
break;
default:
dev_err(&client->dev, "Pixel format not handled: %x\n", code);
return -EINVAL;
}
ret = reg_mask(OUTPUT_FORMAT_CTRL2_A, data_outfmt2,
mask_outfmt2);
if (!ret)
ret = reg_mask(OUTPUT_FORMAT_CTRL2_B, data_outfmt2,
mask_outfmt2);
return ret;
}
static int mt9m111_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct mt9m111_datafmt *fmt;
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
struct v4l2_rect rect = {
.left = mt9m111->rect.left,
.top = mt9m111->rect.top,
.width = mf->width,
.height = mf->height,
};
int ret;
fmt = mt9m111_find_datafmt(mf->code, mt9m111_colour_fmts,
ARRAY_SIZE(mt9m111_colour_fmts));
if (!fmt)
return -EINVAL;
dev_dbg(&client->dev,
"%s code=%x left=%d, top=%d, width=%d, height=%d\n", __func__,
mf->code, rect.left, rect.top, rect.width, rect.height);
ret = mt9m111_make_rect(mt9m111, &rect);
if (!ret)
ret = mt9m111_set_pixfmt(mt9m111, mf->code);
if (!ret) {
mt9m111->rect = rect;
mt9m111->fmt = fmt;
mf->colorspace = fmt->colorspace;
}
return ret;
}
static int mt9m111_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
const struct mt9m111_datafmt *fmt;
bool bayer = mf->code == V4L2_MBUS_FMT_SBGGR8_1X8 ||
mf->code == V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE;
fmt = mt9m111_find_datafmt(mf->code, mt9m111_colour_fmts,
ARRAY_SIZE(mt9m111_colour_fmts));
if (!fmt) {
fmt = mt9m111->fmt;
mf->code = fmt->code;
}
if (mf->height > MT9M111_MAX_HEIGHT)
mf->height = MT9M111_MAX_HEIGHT;
else if (mf->height < 2)
mf->height = 2;
else if (bayer)
mf->height = ALIGN(mf->height, 2);
if (mf->width > MT9M111_MAX_WIDTH)
mf->width = MT9M111_MAX_WIDTH;
else if (mf->width < 2)
mf->width = 2;
else if (bayer)
mf->width = ALIGN(mf->width, 2);
mf->colorspace = fmt->colorspace;
return 0;
}
static int mt9m111_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = mt9m111->model;
id->revision = 0;
return 0;
}
static int mt9m111_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int val;
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR || reg->reg > 0x2ff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
val = mt9m111_reg_read(client, reg->reg);
reg->size = 2;
reg->val = (u64)val;
if (reg->val > 0xffff)
return -EIO;
return 0;
}
static int mt9m111_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR || reg->reg > 0x2ff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
if (mt9m111_reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int mt9m111_set_flip(struct mt9m111 *mt9m111, int flip, int mask)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
if (mt9m111->context == HIGHPOWER) {
if (flip)
ret = reg_set(READ_MODE_B, mask);
else
ret = reg_clear(READ_MODE_B, mask);
} else {
if (flip)
ret = reg_set(READ_MODE_A, mask);
else
ret = reg_clear(READ_MODE_A, mask);
}
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
static int mt9m111_set_autoexposure(struct mt9m111 *mt9m111, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
if (on)
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
v4l2_ctrl_s_ctrl(mt9m111->gain, mt9m111_get_global_gain(mt9m111));
return 0;
}
static void mt9m111_restore_state(struct mt9m111 *mt9m111)
{
mt9m111_set_context(mt9m111, mt9m111->context);
mt9m111_set_pixfmt(mt9m111, mt9m111->fmt->code);
mt9m111_setup_rect(mt9m111, &mt9m111->rect);
v4l2_ctrl_handler_setup(&mt9m111->hdl);
}
static int mt9m111_resume(struct mt9m111 *mt9m111)
{
int ret = 0;
if (mt9m111->powered) {
ret = mt9m111_enable(mt9m111);
if (!ret)
ret = mt9m111_reset(mt9m111);
if (!ret)
mt9m111_restore_state(mt9m111);
}
return ret;
}
static int mt9m111_init(struct mt9m111 *mt9m111)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9m111->subdev);
int ret;
mt9m111->context = HIGHPOWER;
ret = mt9m111_enable(mt9m111);
if (!ret)
ret = mt9m111_reset(mt9m111);
if (!ret)
ret = mt9m111_set_context(mt9m111, mt9m111->context);
if (ret)
dev_err(&client->dev, "mt9m111 init failed: %d\n", ret);
return ret;
}
static int mt9m111_video_probe(struct i2c_client *client)
{
struct mt9m111 *mt9m111 = to_mt9m111(client);
s32 data;
int ret;
data = reg_read(CHIP_VERSION);
switch (data) {
case 0x143a:
mt9m111->model = V4L2_IDENT_MT9M111;
dev_info(&client->dev,
"Detected a MT9M111/MT9M131 chip ID %x\n", data);
break;
case 0x148c:
mt9m111->model = V4L2_IDENT_MT9M112;
dev_info(&client->dev, "Detected a MT9M112 chip ID %x\n", data);
break;
default:
dev_err(&client->dev,
"No MT9M111/MT9M112/MT9M131 chip detected register read %x\n",
data);
return -ENODEV;
}
ret = mt9m111_init(mt9m111);
if (ret)
return ret;
return v4l2_ctrl_handler_setup(&mt9m111->hdl);
}
static int mt9m111_s_power(struct v4l2_subdev *sd, int on)
{
struct mt9m111 *mt9m111 = container_of(sd, struct mt9m111, subdev);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
mutex_lock(&mt9m111->power_lock);
if (mt9m111->power_count == !on) {
if (on) {
ret = mt9m111_resume(mt9m111);
if (ret) {
dev_err(&client->dev,
"Failed to resume the sensor: %d\n", ret);
goto out;
}
} else {
mt9m111_suspend(mt9m111);
}
}
mt9m111->power_count += on ? 1 : -1;
WARN_ON(mt9m111->power_count < 0);
out:
mutex_unlock(&mt9m111->power_lock);
return ret;
}
static int mt9m111_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(mt9m111_colour_fmts))
return -EINVAL;
*code = mt9m111_colour_fmts[index].code;
return 0;
}
static int mt9m111_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(icl, cfg);
return 0;
}
static int mt9m111_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9m111 *mt9m111;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl = soc_camera_i2c_to_link(client);
int ret;
if (!icl) {
dev_err(&client->dev, "mt9m111: driver needs platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9m111 = kzalloc(sizeof(struct mt9m111), GFP_KERNEL);
if (!mt9m111)
return -ENOMEM;
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
int err = mt9m111->hdl.error;
kfree(mt9m111);
return err;
}
mt9m111->rect.left = MT9M111_MIN_DARK_COLS;
mt9m111->rect.top = MT9M111_MIN_DARK_ROWS;
mt9m111->rect.width = MT9M111_MAX_WIDTH;
mt9m111->rect.height = MT9M111_MAX_HEIGHT;
mt9m111->fmt = &mt9m111_colour_fmts[0];
mt9m111->lastpage = -1;
mutex_init(&mt9m111->power_lock);
ret = mt9m111_video_probe(client);
if (ret) {
v4l2_ctrl_handler_free(&mt9m111->hdl);
kfree(mt9m111);
}
return ret;
}
static int mt9m111_remove(struct i2c_client *client)
{
struct mt9m111 *mt9m111 = to_mt9m111(client);
v4l2_device_unregister_subdev(&mt9m111->subdev);
v4l2_ctrl_handler_free(&mt9m111->hdl);
kfree(mt9m111);
return 0;
}
static int __init mt9m111_mod_init(void)
{
return i2c_add_driver(&mt9m111_i2c_driver);
}
static void __exit mt9m111_mod_exit(void)
{
i2c_del_driver(&mt9m111_i2c_driver);
}
