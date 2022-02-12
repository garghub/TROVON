static struct mt9p031 *to_mt9p031(struct v4l2_subdev *sd)
{
return container_of(sd, struct mt9p031, subdev);
}
static int mt9p031_read(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_word_swapped(client, reg);
}
static int mt9p031_write(struct i2c_client *client, u8 reg, u16 data)
{
return i2c_smbus_write_word_swapped(client, reg, data);
}
static int mt9p031_set_output_control(struct mt9p031 *mt9p031, u16 clear,
u16 set)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
u16 value = (mt9p031->output_control & ~clear) | set;
int ret;
ret = mt9p031_write(client, MT9P031_OUTPUT_CONTROL, value);
if (ret < 0)
return ret;
mt9p031->output_control = value;
return 0;
}
static int mt9p031_set_mode2(struct mt9p031 *mt9p031, u16 clear, u16 set)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
u16 value = (mt9p031->mode2 & ~clear) | set;
int ret;
ret = mt9p031_write(client, MT9P031_READ_MODE_2, value);
if (ret < 0)
return ret;
mt9p031->mode2 = value;
return 0;
}
static int mt9p031_reset(struct mt9p031 *mt9p031)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
int ret;
ret = mt9p031_write(client, MT9P031_RST, MT9P031_RST_ENABLE);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_RST, MT9P031_RST_DISABLE);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_PIXEL_CLOCK_CONTROL,
MT9P031_PIXEL_CLOCK_DIVIDE(mt9p031->clk_div));
if (ret < 0)
return ret;
return mt9p031_set_output_control(mt9p031, MT9P031_OUTPUT_CONTROL_CEN,
0);
}
static int mt9p031_clk_setup(struct mt9p031 *mt9p031)
{
static const struct aptina_pll_limits limits = {
.ext_clock_min = 6000000,
.ext_clock_max = 27000000,
.int_clock_min = 2000000,
.int_clock_max = 13500000,
.out_clock_min = 180000000,
.out_clock_max = 360000000,
.pix_clock_max = 96000000,
.n_min = 1,
.n_max = 64,
.m_min = 16,
.m_max = 255,
.p1_min = 1,
.p1_max = 128,
};
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
struct mt9p031_platform_data *pdata = mt9p031->pdata;
int ret;
mt9p031->clk = devm_clk_get(&client->dev, NULL);
if (IS_ERR(mt9p031->clk))
return PTR_ERR(mt9p031->clk);
ret = clk_set_rate(mt9p031->clk, pdata->ext_freq);
if (ret < 0)
return ret;
if (pdata->ext_freq > limits.ext_clock_max) {
unsigned int div;
div = DIV_ROUND_UP(pdata->ext_freq, pdata->target_freq);
div = roundup_pow_of_two(div) / 2;
mt9p031->clk_div = max_t(unsigned int, div, 64);
mt9p031->use_pll = false;
return 0;
}
mt9p031->pll.ext_clock = pdata->ext_freq;
mt9p031->pll.pix_clock = pdata->target_freq;
mt9p031->use_pll = true;
return aptina_pll_calculate(&client->dev, &limits, &mt9p031->pll);
}
static int mt9p031_pll_enable(struct mt9p031 *mt9p031)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
int ret;
if (!mt9p031->use_pll)
return 0;
ret = mt9p031_write(client, MT9P031_PLL_CONTROL,
MT9P031_PLL_CONTROL_PWRON);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_PLL_CONFIG_1,
(mt9p031->pll.m << 8) | (mt9p031->pll.n - 1));
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_PLL_CONFIG_2, mt9p031->pll.p1 - 1);
if (ret < 0)
return ret;
usleep_range(1000, 2000);
ret = mt9p031_write(client, MT9P031_PLL_CONTROL,
MT9P031_PLL_CONTROL_PWRON |
MT9P031_PLL_CONTROL_USEPLL);
return ret;
}
static inline int mt9p031_pll_disable(struct mt9p031 *mt9p031)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
if (!mt9p031->use_pll)
return 0;
return mt9p031_write(client, MT9P031_PLL_CONTROL,
MT9P031_PLL_CONTROL_PWROFF);
}
static int mt9p031_power_on(struct mt9p031 *mt9p031)
{
int ret;
if (gpio_is_valid(mt9p031->reset)) {
gpio_set_value(mt9p031->reset, 0);
usleep_range(1000, 2000);
}
ret = regulator_bulk_enable(ARRAY_SIZE(mt9p031->regulators),
mt9p031->regulators);
if (ret < 0)
return ret;
if (mt9p031->clk) {
ret = clk_prepare_enable(mt9p031->clk);
if (ret) {
regulator_bulk_disable(ARRAY_SIZE(mt9p031->regulators),
mt9p031->regulators);
return ret;
}
}
if (gpio_is_valid(mt9p031->reset)) {
gpio_set_value(mt9p031->reset, 1);
usleep_range(1000, 2000);
}
return 0;
}
static void mt9p031_power_off(struct mt9p031 *mt9p031)
{
if (gpio_is_valid(mt9p031->reset)) {
gpio_set_value(mt9p031->reset, 0);
usleep_range(1000, 2000);
}
regulator_bulk_disable(ARRAY_SIZE(mt9p031->regulators),
mt9p031->regulators);
if (mt9p031->clk)
clk_disable_unprepare(mt9p031->clk);
}
static int __mt9p031_set_power(struct mt9p031 *mt9p031, bool on)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
int ret;
if (!on) {
mt9p031_power_off(mt9p031);
return 0;
}
ret = mt9p031_power_on(mt9p031);
if (ret < 0)
return ret;
ret = mt9p031_reset(mt9p031);
if (ret < 0) {
dev_err(&client->dev, "Failed to reset the camera\n");
return ret;
}
return v4l2_ctrl_handler_setup(&mt9p031->ctrls);
}
static int mt9p031_set_params(struct mt9p031 *mt9p031)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
struct v4l2_mbus_framefmt *format = &mt9p031->format;
const struct v4l2_rect *crop = &mt9p031->crop;
unsigned int hblank;
unsigned int vblank;
unsigned int xskip;
unsigned int yskip;
unsigned int xbin;
unsigned int ybin;
int ret;
ret = mt9p031_write(client, MT9P031_COLUMN_START, crop->left);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_ROW_START, crop->top);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_WINDOW_WIDTH, crop->width - 1);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_WINDOW_HEIGHT, crop->height - 1);
if (ret < 0)
return ret;
xskip = DIV_ROUND_CLOSEST(crop->width, format->width);
yskip = DIV_ROUND_CLOSEST(crop->height, format->height);
xbin = 1 << (ffs(xskip) - 1);
ybin = 1 << (ffs(yskip) - 1);
ret = mt9p031_write(client, MT9P031_COLUMN_ADDRESS_MODE,
((xbin - 1) << 4) | (xskip - 1));
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_ROW_ADDRESS_MODE,
((ybin - 1) << 4) | (yskip - 1));
if (ret < 0)
return ret;
hblank = 346 * ybin + 64 + (80 >> min_t(unsigned int, xbin, 3));
vblank = MT9P031_VERTICAL_BLANK_DEF;
ret = mt9p031_write(client, MT9P031_HORIZONTAL_BLANK, hblank - 1);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_VERTICAL_BLANK, vblank - 1);
if (ret < 0)
return ret;
return ret;
}
static int mt9p031_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
int ret;
if (!enable) {
ret = mt9p031_set_output_control(mt9p031,
MT9P031_OUTPUT_CONTROL_CEN, 0);
if (ret < 0)
return ret;
return mt9p031_pll_disable(mt9p031);
}
ret = mt9p031_set_params(mt9p031);
if (ret < 0)
return ret;
ret = mt9p031_set_output_control(mt9p031, 0,
MT9P031_OUTPUT_CONTROL_CEN);
if (ret < 0)
return ret;
return mt9p031_pll_enable(mt9p031);
}
static int mt9p031_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
if (code->pad || code->index)
return -EINVAL;
code->code = mt9p031->format.code;
return 0;
}
static int mt9p031_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
if (fse->index >= 8 || fse->code != mt9p031->format.code)
return -EINVAL;
fse->min_width = MT9P031_WINDOW_WIDTH_DEF
/ min_t(unsigned int, 7, fse->index + 1);
fse->max_width = fse->min_width;
fse->min_height = MT9P031_WINDOW_HEIGHT_DEF / (fse->index + 1);
fse->max_height = fse->min_height;
return 0;
}
static struct v4l2_mbus_framefmt *
__mt9p031_get_pad_format(struct mt9p031 *mt9p031, struct v4l2_subdev_fh *fh,
unsigned int pad, u32 which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9p031->format;
default:
return NULL;
}
}
static struct v4l2_rect *
__mt9p031_get_pad_crop(struct mt9p031 *mt9p031, struct v4l2_subdev_fh *fh,
unsigned int pad, u32 which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9p031->crop;
default:
return NULL;
}
}
static int mt9p031_get_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
fmt->format = *__mt9p031_get_pad_format(mt9p031, fh, fmt->pad,
fmt->which);
return 0;
}
static int mt9p031_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
unsigned int width;
unsigned int height;
unsigned int hratio;
unsigned int vratio;
__crop = __mt9p031_get_pad_crop(mt9p031, fh, format->pad,
format->which);
width = clamp_t(unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 7,
MT9P031_WINDOW_WIDTH_MIN),
__crop->width);
height = clamp_t(unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9P031_WINDOW_HEIGHT_MIN),
__crop->height);
hratio = DIV_ROUND_CLOSEST(__crop->width, width);
vratio = DIV_ROUND_CLOSEST(__crop->height, height);
__format = __mt9p031_get_pad_format(mt9p031, fh, format->pad,
format->which);
__format->width = __crop->width / hratio;
__format->height = __crop->height / vratio;
format->format = *__format;
return 0;
}
static int mt9p031_get_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
crop->rect = *__mt9p031_get_pad_crop(mt9p031, fh, crop->pad,
crop->which);
return 0;
}
static int mt9p031_set_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
struct v4l2_rect rect;
rect.left = clamp(ALIGN(crop->rect.left, 2), MT9P031_COLUMN_START_MIN,
MT9P031_COLUMN_START_MAX);
rect.top = clamp(ALIGN(crop->rect.top, 2), MT9P031_ROW_START_MIN,
MT9P031_ROW_START_MAX);
rect.width = clamp_t(unsigned int, ALIGN(crop->rect.width, 2),
MT9P031_WINDOW_WIDTH_MIN,
MT9P031_WINDOW_WIDTH_MAX);
rect.height = clamp_t(unsigned int, ALIGN(crop->rect.height, 2),
MT9P031_WINDOW_HEIGHT_MIN,
MT9P031_WINDOW_HEIGHT_MAX);
rect.width = min_t(unsigned int, rect.width,
MT9P031_PIXEL_ARRAY_WIDTH - rect.left);
rect.height = min_t(unsigned int, rect.height,
MT9P031_PIXEL_ARRAY_HEIGHT - rect.top);
__crop = __mt9p031_get_pad_crop(mt9p031, fh, crop->pad, crop->which);
if (rect.width != __crop->width || rect.height != __crop->height) {
__format = __mt9p031_get_pad_format(mt9p031, fh, crop->pad,
crop->which);
__format->width = rect.width;
__format->height = rect.height;
}
*__crop = rect;
crop->rect = rect;
return 0;
}
static int mt9p031_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9p031 *mt9p031 =
container_of(ctrl->handler, struct mt9p031, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&mt9p031->subdev);
u16 data;
int ret;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
ret = mt9p031_write(client, MT9P031_SHUTTER_WIDTH_UPPER,
(ctrl->val >> 16) & 0xffff);
if (ret < 0)
return ret;
return mt9p031_write(client, MT9P031_SHUTTER_WIDTH_LOWER,
ctrl->val & 0xffff);
case V4L2_CID_GAIN:
if (ctrl->val <= 32) {
data = ctrl->val;
} else if (ctrl->val <= 64) {
ctrl->val &= ~1;
data = (1 << 6) | (ctrl->val >> 1);
} else {
ctrl->val &= ~7;
data = ((ctrl->val - 64) << 5) | (1 << 6) | 32;
}
return mt9p031_write(client, MT9P031_GLOBAL_GAIN, data);
case V4L2_CID_HFLIP:
if (ctrl->val)
return mt9p031_set_mode2(mt9p031,
0, MT9P031_READ_MODE_2_COL_MIR);
else
return mt9p031_set_mode2(mt9p031,
MT9P031_READ_MODE_2_COL_MIR, 0);
case V4L2_CID_VFLIP:
if (ctrl->val)
return mt9p031_set_mode2(mt9p031,
0, MT9P031_READ_MODE_2_ROW_MIR);
else
return mt9p031_set_mode2(mt9p031,
MT9P031_READ_MODE_2_ROW_MIR, 0);
case V4L2_CID_TEST_PATTERN:
if (!ctrl->val) {
if (mt9p031->blc_auto->cur.val != 0) {
ret = mt9p031_s_ctrl(mt9p031->blc_auto);
if (ret < 0)
return ret;
}
if (mt9p031->blc_offset->cur.val != 0) {
ret = mt9p031_s_ctrl(mt9p031->blc_offset);
if (ret < 0)
return ret;
}
return mt9p031_write(client, MT9P031_TEST_PATTERN,
MT9P031_TEST_PATTERN_DISABLE);
}
ret = mt9p031_write(client, MT9P031_TEST_PATTERN_GREEN, 0x05a0);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_TEST_PATTERN_RED, 0x0a50);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_TEST_PATTERN_BLUE, 0x0aa0);
if (ret < 0)
return ret;
ret = mt9p031_set_mode2(mt9p031, MT9P031_READ_MODE_2_ROW_BLC,
0);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_ROW_BLACK_DEF_OFFSET, 0);
if (ret < 0)
return ret;
return mt9p031_write(client, MT9P031_TEST_PATTERN,
((ctrl->val - 1) << MT9P031_TEST_PATTERN_SHIFT)
| MT9P031_TEST_PATTERN_ENABLE);
case V4L2_CID_BLC_AUTO:
ret = mt9p031_set_mode2(mt9p031,
ctrl->val ? 0 : MT9P031_READ_MODE_2_ROW_BLC,
ctrl->val ? MT9P031_READ_MODE_2_ROW_BLC : 0);
if (ret < 0)
return ret;
return mt9p031_write(client, MT9P031_BLACK_LEVEL_CALIBRATION,
ctrl->val ? 0 : MT9P031_BLC_MANUAL_BLC);
case V4L2_CID_BLC_TARGET_LEVEL:
return mt9p031_write(client, MT9P031_ROW_BLACK_TARGET,
ctrl->val);
case V4L2_CID_BLC_ANALOG_OFFSET:
data = ctrl->val & ((1 << 9) - 1);
ret = mt9p031_write(client, MT9P031_GREEN1_OFFSET, data);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_GREEN2_OFFSET, data);
if (ret < 0)
return ret;
ret = mt9p031_write(client, MT9P031_RED_OFFSET, data);
if (ret < 0)
return ret;
return mt9p031_write(client, MT9P031_BLUE_OFFSET, data);
case V4L2_CID_BLC_DIGITAL_OFFSET:
return mt9p031_write(client, MT9P031_ROW_BLACK_DEF_OFFSET,
ctrl->val & ((1 << 12) - 1));
}
return 0;
}
static int mt9p031_set_power(struct v4l2_subdev *subdev, int on)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
int ret = 0;
mutex_lock(&mt9p031->power_lock);
if (mt9p031->power_count == !on) {
ret = __mt9p031_set_power(mt9p031, !!on);
if (ret < 0)
goto out;
}
mt9p031->power_count += on ? 1 : -1;
WARN_ON(mt9p031->power_count < 0);
out:
mutex_unlock(&mt9p031->power_lock);
return ret;
}
static int mt9p031_registered(struct v4l2_subdev *subdev)
{
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
s32 data;
int ret;
ret = mt9p031_power_on(mt9p031);
if (ret < 0) {
dev_err(&client->dev, "MT9P031 power up failed\n");
return ret;
}
data = mt9p031_read(client, MT9P031_CHIP_VERSION);
mt9p031_power_off(mt9p031);
if (data != MT9P031_CHIP_VERSION_VALUE) {
dev_err(&client->dev, "MT9P031 not detected, wrong version "
"0x%04x\n", data);
return -ENODEV;
}
dev_info(&client->dev, "MT9P031 detected at address 0x%02x\n",
client->addr);
return 0;
}
static int mt9p031_open(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
crop = v4l2_subdev_get_try_crop(fh, 0);
crop->left = MT9P031_COLUMN_START_DEF;
crop->top = MT9P031_ROW_START_DEF;
crop->width = MT9P031_WINDOW_WIDTH_DEF;
crop->height = MT9P031_WINDOW_HEIGHT_DEF;
format = v4l2_subdev_get_try_format(fh, 0);
if (mt9p031->model == MT9P031_MODEL_MONOCHROME)
format->code = V4L2_MBUS_FMT_Y12_1X12;
else
format->code = V4L2_MBUS_FMT_SGRBG12_1X12;
format->width = MT9P031_WINDOW_WIDTH_DEF;
format->height = MT9P031_WINDOW_HEIGHT_DEF;
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
return mt9p031_set_power(subdev, 1);
}
static int mt9p031_close(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
return mt9p031_set_power(subdev, 0);
}
static struct mt9p031_platform_data *
mt9p031_get_pdata(struct i2c_client *client)
{
struct mt9p031_platform_data *pdata;
struct device_node *np;
if (!IS_ENABLED(CONFIG_OF) || !client->dev.of_node)
return client->dev.platform_data;
np = of_graph_get_next_endpoint(client->dev.of_node, NULL);
if (!np)
return NULL;
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
goto done;
pdata->reset = of_get_named_gpio(client->dev.of_node, "reset-gpios", 0);
of_property_read_u32(np, "input-clock-frequency", &pdata->ext_freq);
of_property_read_u32(np, "pixel-clock-frequency", &pdata->target_freq);
done:
of_node_put(np);
return pdata;
}
static int mt9p031_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9p031_platform_data *pdata = mt9p031_get_pdata(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct mt9p031 *mt9p031;
unsigned int i;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&client->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9p031 = devm_kzalloc(&client->dev, sizeof(*mt9p031), GFP_KERNEL);
if (mt9p031 == NULL)
return -ENOMEM;
mt9p031->pdata = pdata;
mt9p031->output_control = MT9P031_OUTPUT_CONTROL_DEF;
mt9p031->mode2 = MT9P031_READ_MODE_2_ROW_BLC;
mt9p031->model = did->driver_data;
mt9p031->reset = -1;
mt9p031->regulators[0].supply = "vdd";
mt9p031->regulators[1].supply = "vdd_io";
mt9p031->regulators[2].supply = "vaa";
ret = devm_regulator_bulk_get(&client->dev, 3, mt9p031->regulators);
if (ret < 0) {
dev_err(&client->dev, "Unable to get regulators\n");
return ret;
}
v4l2_ctrl_handler_init(&mt9p031->ctrls, ARRAY_SIZE(mt9p031_ctrls) + 6);
v4l2_ctrl_new_std(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_EXPOSURE, MT9P031_SHUTTER_WIDTH_MIN,
MT9P031_SHUTTER_WIDTH_MAX, 1,
MT9P031_SHUTTER_WIDTH_DEF);
v4l2_ctrl_new_std(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_GAIN, MT9P031_GLOBAL_GAIN_MIN,
MT9P031_GLOBAL_GAIN_MAX, 1, MT9P031_GLOBAL_GAIN_DEF);
v4l2_ctrl_new_std(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_PIXEL_RATE, pdata->target_freq,
pdata->target_freq, 1, pdata->target_freq);
v4l2_ctrl_new_std_menu_items(&mt9p031->ctrls, &mt9p031_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(mt9p031_test_pattern_menu) - 1, 0,
0, mt9p031_test_pattern_menu);
for (i = 0; i < ARRAY_SIZE(mt9p031_ctrls); ++i)
v4l2_ctrl_new_custom(&mt9p031->ctrls, &mt9p031_ctrls[i], NULL);
mt9p031->subdev.ctrl_handler = &mt9p031->ctrls;
if (mt9p031->ctrls.error) {
printk(KERN_INFO "%s: control initialization error %d\n",
__func__, mt9p031->ctrls.error);
ret = mt9p031->ctrls.error;
goto done;
}
mt9p031->blc_auto = v4l2_ctrl_find(&mt9p031->ctrls, V4L2_CID_BLC_AUTO);
mt9p031->blc_offset = v4l2_ctrl_find(&mt9p031->ctrls,
V4L2_CID_BLC_DIGITAL_OFFSET);
mutex_init(&mt9p031->power_lock);
v4l2_i2c_subdev_init(&mt9p031->subdev, client, &mt9p031_subdev_ops);
mt9p031->subdev.internal_ops = &mt9p031_subdev_internal_ops;
mt9p031->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&mt9p031->subdev.entity, 1, &mt9p031->pad, 0);
if (ret < 0)
goto done;
mt9p031->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
mt9p031->crop.width = MT9P031_WINDOW_WIDTH_DEF;
mt9p031->crop.height = MT9P031_WINDOW_HEIGHT_DEF;
mt9p031->crop.left = MT9P031_COLUMN_START_DEF;
mt9p031->crop.top = MT9P031_ROW_START_DEF;
if (mt9p031->model == MT9P031_MODEL_MONOCHROME)
mt9p031->format.code = V4L2_MBUS_FMT_Y12_1X12;
else
mt9p031->format.code = V4L2_MBUS_FMT_SGRBG12_1X12;
mt9p031->format.width = MT9P031_WINDOW_WIDTH_DEF;
mt9p031->format.height = MT9P031_WINDOW_HEIGHT_DEF;
mt9p031->format.field = V4L2_FIELD_NONE;
mt9p031->format.colorspace = V4L2_COLORSPACE_SRGB;
if (gpio_is_valid(pdata->reset)) {
ret = devm_gpio_request_one(&client->dev, pdata->reset,
GPIOF_OUT_INIT_LOW, "mt9p031_rst");
if (ret < 0)
goto done;
mt9p031->reset = pdata->reset;
}
ret = mt9p031_clk_setup(mt9p031);
done:
if (ret < 0) {
v4l2_ctrl_handler_free(&mt9p031->ctrls);
media_entity_cleanup(&mt9p031->subdev.entity);
}
return ret;
}
static int mt9p031_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct mt9p031 *mt9p031 = to_mt9p031(subdev);
v4l2_ctrl_handler_free(&mt9p031->ctrls);
v4l2_device_unregister_subdev(subdev);
media_entity_cleanup(&subdev->entity);
return 0;
}
