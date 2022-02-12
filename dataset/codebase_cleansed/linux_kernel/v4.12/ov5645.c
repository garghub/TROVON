static inline struct ov5645 *to_ov5645(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov5645, sd);
}
static int ov5645_regulators_enable(struct ov5645 *ov5645)
{
int ret;
ret = regulator_enable(ov5645->io_regulator);
if (ret < 0) {
dev_err(ov5645->dev, "set io voltage failed\n");
return ret;
}
ret = regulator_enable(ov5645->analog_regulator);
if (ret) {
dev_err(ov5645->dev, "set analog voltage failed\n");
goto err_disable_io;
}
ret = regulator_enable(ov5645->core_regulator);
if (ret) {
dev_err(ov5645->dev, "set core voltage failed\n");
goto err_disable_analog;
}
return 0;
err_disable_analog:
regulator_disable(ov5645->analog_regulator);
err_disable_io:
regulator_disable(ov5645->io_regulator);
return ret;
}
static void ov5645_regulators_disable(struct ov5645 *ov5645)
{
int ret;
ret = regulator_disable(ov5645->core_regulator);
if (ret < 0)
dev_err(ov5645->dev, "core regulator disable failed\n");
ret = regulator_disable(ov5645->analog_regulator);
if (ret < 0)
dev_err(ov5645->dev, "analog regulator disable failed\n");
ret = regulator_disable(ov5645->io_regulator);
if (ret < 0)
dev_err(ov5645->dev, "io regulator disable failed\n");
}
static int ov5645_write_reg(struct ov5645 *ov5645, u16 reg, u8 val)
{
u8 regbuf[3];
int ret;
regbuf[0] = reg >> 8;
regbuf[1] = reg & 0xff;
regbuf[2] = val;
ret = i2c_master_send(ov5645->i2c_client, regbuf, 3);
if (ret < 0)
dev_err(ov5645->dev, "%s: write reg error %d: reg=%x, val=%x\n",
__func__, ret, reg, val);
return ret;
}
static int ov5645_read_reg(struct ov5645 *ov5645, u16 reg, u8 *val)
{
u8 regbuf[2];
int ret;
regbuf[0] = reg >> 8;
regbuf[1] = reg & 0xff;
ret = i2c_master_send(ov5645->i2c_client, regbuf, 2);
if (ret < 0) {
dev_err(ov5645->dev, "%s: write reg error %d: reg=%x\n",
__func__, ret, reg);
return ret;
}
ret = i2c_master_recv(ov5645->i2c_client, val, 1);
if (ret < 0) {
dev_err(ov5645->dev, "%s: read reg error %d: reg=%x\n",
__func__, ret, reg);
return ret;
}
return 0;
}
static int ov5645_set_aec_mode(struct ov5645 *ov5645, u32 mode)
{
u8 val = ov5645->aec_pk_manual;
int ret;
if (mode == V4L2_EXPOSURE_AUTO)
val &= ~OV5645_AEC_MANUAL_ENABLE;
else
val |= OV5645_AEC_MANUAL_ENABLE;
ret = ov5645_write_reg(ov5645, OV5645_AEC_PK_MANUAL, val);
if (!ret)
ov5645->aec_pk_manual = val;
return ret;
}
static int ov5645_set_agc_mode(struct ov5645 *ov5645, u32 enable)
{
u8 val = ov5645->aec_pk_manual;
int ret;
if (enable)
val &= ~OV5645_AGC_MANUAL_ENABLE;
else
val |= OV5645_AGC_MANUAL_ENABLE;
ret = ov5645_write_reg(ov5645, OV5645_AEC_PK_MANUAL, val);
if (!ret)
ov5645->aec_pk_manual = val;
return ret;
}
static int ov5645_set_register_array(struct ov5645 *ov5645,
const struct reg_value *settings,
unsigned int num_settings)
{
unsigned int i;
int ret;
for (i = 0; i < num_settings; ++i, ++settings) {
ret = ov5645_write_reg(ov5645, settings->reg, settings->val);
if (ret < 0)
return ret;
}
return 0;
}
static int ov5645_set_power_on(struct ov5645 *ov5645)
{
int ret;
ret = ov5645_regulators_enable(ov5645);
if (ret < 0) {
return ret;
}
ret = clk_prepare_enable(ov5645->xclk);
if (ret < 0) {
dev_err(ov5645->dev, "clk prepare enable failed\n");
ov5645_regulators_disable(ov5645);
return ret;
}
usleep_range(5000, 15000);
gpiod_set_value_cansleep(ov5645->enable_gpio, 1);
usleep_range(1000, 2000);
gpiod_set_value_cansleep(ov5645->rst_gpio, 0);
msleep(20);
return 0;
}
static void ov5645_set_power_off(struct ov5645 *ov5645)
{
gpiod_set_value_cansleep(ov5645->rst_gpio, 1);
gpiod_set_value_cansleep(ov5645->enable_gpio, 0);
clk_disable_unprepare(ov5645->xclk);
ov5645_regulators_disable(ov5645);
}
static int ov5645_s_power(struct v4l2_subdev *sd, int on)
{
struct ov5645 *ov5645 = to_ov5645(sd);
int ret = 0;
mutex_lock(&ov5645->power_lock);
if (ov5645->power_count == !on) {
if (on) {
ret = ov5645_set_power_on(ov5645);
if (ret < 0)
goto exit;
ret = ov5645_set_register_array(ov5645,
ov5645_global_init_setting,
ARRAY_SIZE(ov5645_global_init_setting));
if (ret < 0) {
dev_err(ov5645->dev,
"could not set init registers\n");
ov5645_set_power_off(ov5645);
goto exit;
}
ret = ov5645_write_reg(ov5645, OV5645_SYSTEM_CTRL0,
OV5645_SYSTEM_CTRL0_STOP);
if (ret < 0) {
ov5645_set_power_off(ov5645);
goto exit;
}
} else {
ov5645_set_power_off(ov5645);
}
}
ov5645->power_count += on ? 1 : -1;
WARN_ON(ov5645->power_count < 0);
exit:
mutex_unlock(&ov5645->power_lock);
return ret;
}
static int ov5645_set_saturation(struct ov5645 *ov5645, s32 value)
{
u32 reg_value = (value * 0x10) + 0x40;
int ret;
ret = ov5645_write_reg(ov5645, OV5645_SDE_SAT_U, reg_value);
if (ret < 0)
return ret;
return ov5645_write_reg(ov5645, OV5645_SDE_SAT_V, reg_value);
}
static int ov5645_set_hflip(struct ov5645 *ov5645, s32 value)
{
u8 val = ov5645->timing_tc_reg21;
int ret;
if (value == 0)
val &= ~(OV5645_SENSOR_MIRROR);
else
val |= (OV5645_SENSOR_MIRROR);
ret = ov5645_write_reg(ov5645, OV5645_TIMING_TC_REG21, val);
if (!ret)
ov5645->timing_tc_reg21 = val;
return ret;
}
static int ov5645_set_vflip(struct ov5645 *ov5645, s32 value)
{
u8 val = ov5645->timing_tc_reg20;
int ret;
if (value == 0)
val |= (OV5645_SENSOR_VFLIP | OV5645_ISP_VFLIP);
else
val &= ~(OV5645_SENSOR_VFLIP | OV5645_ISP_VFLIP);
ret = ov5645_write_reg(ov5645, OV5645_TIMING_TC_REG20, val);
if (!ret)
ov5645->timing_tc_reg20 = val;
return ret;
}
static int ov5645_set_test_pattern(struct ov5645 *ov5645, s32 value)
{
u8 val = 0;
if (value) {
val = OV5645_SET_TEST_PATTERN(value - 1);
val |= OV5645_TEST_PATTERN_ENABLE;
}
return ov5645_write_reg(ov5645, OV5645_PRE_ISP_TEST_SETTING_1, val);
}
static int ov5645_set_awb(struct ov5645 *ov5645, s32 enable_auto)
{
u8 val = 0;
if (!enable_auto)
val = OV5645_AWB_MANUAL_ENABLE;
return ov5645_write_reg(ov5645, OV5645_AWB_MANUAL_CONTROL, val);
}
static int ov5645_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov5645 *ov5645 = container_of(ctrl->handler,
struct ov5645, ctrls);
int ret;
mutex_lock(&ov5645->power_lock);
if (!ov5645->power_count) {
mutex_unlock(&ov5645->power_lock);
return 0;
}
switch (ctrl->id) {
case V4L2_CID_SATURATION:
ret = ov5645_set_saturation(ov5645, ctrl->val);
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = ov5645_set_awb(ov5645, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
ret = ov5645_set_agc_mode(ov5645, ctrl->val);
break;
case V4L2_CID_EXPOSURE_AUTO:
ret = ov5645_set_aec_mode(ov5645, ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
ret = ov5645_set_test_pattern(ov5645, ctrl->val);
break;
case V4L2_CID_HFLIP:
ret = ov5645_set_hflip(ov5645, ctrl->val);
break;
case V4L2_CID_VFLIP:
ret = ov5645_set_vflip(ov5645, ctrl->val);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&ov5645->power_lock);
return ret;
}
static int ov5645_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_UYVY8_2X8;
return 0;
}
static int ov5645_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->code != MEDIA_BUS_FMT_UYVY8_2X8)
return -EINVAL;
if (fse->index >= ARRAY_SIZE(ov5645_mode_info_data))
return -EINVAL;
fse->min_width = ov5645_mode_info_data[fse->index].width;
fse->max_width = ov5645_mode_info_data[fse->index].width;
fse->min_height = ov5645_mode_info_data[fse->index].height;
fse->max_height = ov5645_mode_info_data[fse->index].height;
return 0;
}
static struct v4l2_mbus_framefmt *
__ov5645_get_pad_format(struct ov5645 *ov5645,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(&ov5645->sd, cfg, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &ov5645->fmt;
default:
return NULL;
}
}
static int ov5645_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct ov5645 *ov5645 = to_ov5645(sd);
format->format = *__ov5645_get_pad_format(ov5645, cfg, format->pad,
format->which);
return 0;
}
static struct v4l2_rect *
__ov5645_get_pad_crop(struct ov5645 *ov5645, struct v4l2_subdev_pad_config *cfg,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(&ov5645->sd, cfg, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &ov5645->crop;
default:
return NULL;
}
}
static const struct ov5645_mode_info *
ov5645_find_nearest_mode(unsigned int width, unsigned int height)
{
int i;
for (i = ARRAY_SIZE(ov5645_mode_info_data) - 1; i >= 0; i--) {
if (ov5645_mode_info_data[i].width <= width &&
ov5645_mode_info_data[i].height <= height)
break;
}
if (i < 0)
i = 0;
return &ov5645_mode_info_data[i];
}
static int ov5645_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct ov5645 *ov5645 = to_ov5645(sd);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
const struct ov5645_mode_info *new_mode;
__crop = __ov5645_get_pad_crop(ov5645, cfg, format->pad,
format->which);
new_mode = ov5645_find_nearest_mode(format->format.width,
format->format.height);
__crop->width = new_mode->width;
__crop->height = new_mode->height;
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
ov5645->current_mode = new_mode;
__format = __ov5645_get_pad_format(ov5645, cfg, format->pad,
format->which);
__format->width = __crop->width;
__format->height = __crop->height;
__format->code = MEDIA_BUS_FMT_UYVY8_2X8;
__format->field = V4L2_FIELD_NONE;
__format->colorspace = V4L2_COLORSPACE_SRGB;
format->format = *__format;
return 0;
}
static int ov5645_entity_init_cfg(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg)
{
struct v4l2_subdev_format fmt = { 0 };
fmt.which = cfg ? V4L2_SUBDEV_FORMAT_TRY : V4L2_SUBDEV_FORMAT_ACTIVE;
fmt.format.width = 1920;
fmt.format.height = 1080;
ov5645_set_format(subdev, cfg, &fmt);
return 0;
}
static int ov5645_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct ov5645 *ov5645 = to_ov5645(sd);
if (sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
sel->r = *__ov5645_get_pad_crop(ov5645, cfg, sel->pad,
sel->which);
return 0;
}
static int ov5645_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct ov5645 *ov5645 = to_ov5645(subdev);
int ret;
if (enable) {
ret = ov5645_set_register_array(ov5645,
ov5645->current_mode->data,
ov5645->current_mode->data_size);
if (ret < 0) {
dev_err(ov5645->dev, "could not set mode %dx%d\n",
ov5645->current_mode->width,
ov5645->current_mode->height);
return ret;
}
ret = v4l2_ctrl_handler_setup(&ov5645->ctrls);
if (ret < 0) {
dev_err(ov5645->dev, "could not sync v4l2 controls\n");
return ret;
}
ret = ov5645_write_reg(ov5645, OV5645_SYSTEM_CTRL0,
OV5645_SYSTEM_CTRL0_START);
if (ret < 0)
return ret;
} else {
ret = ov5645_write_reg(ov5645, OV5645_SYSTEM_CTRL0,
OV5645_SYSTEM_CTRL0_STOP);
if (ret < 0)
return ret;
}
return 0;
}
static int ov5645_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device_node *endpoint;
struct ov5645 *ov5645;
u8 chip_id_high, chip_id_low;
u32 xclk_freq;
int ret;
ov5645 = devm_kzalloc(dev, sizeof(struct ov5645), GFP_KERNEL);
if (!ov5645)
return -ENOMEM;
ov5645->i2c_client = client;
ov5645->dev = dev;
endpoint = of_graph_get_next_endpoint(dev->of_node, NULL);
if (!endpoint) {
dev_err(dev, "endpoint node not found\n");
return -EINVAL;
}
ret = v4l2_of_parse_endpoint(endpoint, &ov5645->ep);
if (ret < 0) {
dev_err(dev, "parsing endpoint node failed\n");
return ret;
}
of_node_put(endpoint);
if (ov5645->ep.bus_type != V4L2_MBUS_CSI2) {
dev_err(dev, "invalid bus type, must be CSI2\n");
return -EINVAL;
}
ov5645->xclk = devm_clk_get(dev, "xclk");
if (IS_ERR(ov5645->xclk)) {
dev_err(dev, "could not get xclk");
return PTR_ERR(ov5645->xclk);
}
ret = of_property_read_u32(dev->of_node, "clock-frequency", &xclk_freq);
if (ret) {
dev_err(dev, "could not get xclk frequency\n");
return ret;
}
if (xclk_freq != 23880000) {
dev_err(dev, "external clock frequency %u is not supported\n",
xclk_freq);
return -EINVAL;
}
ret = clk_set_rate(ov5645->xclk, xclk_freq);
if (ret) {
dev_err(dev, "could not set xclk frequency\n");
return ret;
}
ov5645->io_regulator = devm_regulator_get(dev, "vdddo");
if (IS_ERR(ov5645->io_regulator)) {
dev_err(dev, "cannot get io regulator\n");
return PTR_ERR(ov5645->io_regulator);
}
ret = regulator_set_voltage(ov5645->io_regulator,
OV5645_VOLTAGE_DIGITAL_IO,
OV5645_VOLTAGE_DIGITAL_IO);
if (ret < 0) {
dev_err(dev, "cannot set io voltage\n");
return ret;
}
ov5645->core_regulator = devm_regulator_get(dev, "vddd");
if (IS_ERR(ov5645->core_regulator)) {
dev_err(dev, "cannot get core regulator\n");
return PTR_ERR(ov5645->core_regulator);
}
ret = regulator_set_voltage(ov5645->core_regulator,
OV5645_VOLTAGE_DIGITAL_CORE,
OV5645_VOLTAGE_DIGITAL_CORE);
if (ret < 0) {
dev_err(dev, "cannot set core voltage\n");
return ret;
}
ov5645->analog_regulator = devm_regulator_get(dev, "vdda");
if (IS_ERR(ov5645->analog_regulator)) {
dev_err(dev, "cannot get analog regulator\n");
return PTR_ERR(ov5645->analog_regulator);
}
ret = regulator_set_voltage(ov5645->analog_regulator,
OV5645_VOLTAGE_ANALOG,
OV5645_VOLTAGE_ANALOG);
if (ret < 0) {
dev_err(dev, "cannot set analog voltage\n");
return ret;
}
ov5645->enable_gpio = devm_gpiod_get(dev, "enable", GPIOD_OUT_HIGH);
if (IS_ERR(ov5645->enable_gpio)) {
dev_err(dev, "cannot get enable gpio\n");
return PTR_ERR(ov5645->enable_gpio);
}
ov5645->rst_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(ov5645->rst_gpio)) {
dev_err(dev, "cannot get reset gpio\n");
return PTR_ERR(ov5645->rst_gpio);
}
mutex_init(&ov5645->power_lock);
v4l2_ctrl_handler_init(&ov5645->ctrls, 7);
v4l2_ctrl_new_std(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_SATURATION, -4, 4, 1, 0);
v4l2_ctrl_new_std(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
v4l2_ctrl_new_std(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1);
v4l2_ctrl_new_std_menu(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_EXPOSURE_AUTO, V4L2_EXPOSURE_MANUAL,
0, V4L2_EXPOSURE_AUTO);
v4l2_ctrl_new_std_menu_items(&ov5645->ctrls, &ov5645_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(ov5645_test_pattern_menu) - 1,
0, 0, ov5645_test_pattern_menu);
ov5645->sd.ctrl_handler = &ov5645->ctrls;
if (ov5645->ctrls.error) {
dev_err(dev, "%s: control initialization error %d\n",
__func__, ov5645->ctrls.error);
ret = ov5645->ctrls.error;
goto free_ctrl;
}
v4l2_i2c_subdev_init(&ov5645->sd, client, &ov5645_subdev_ops);
ov5645->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
ov5645->pad.flags = MEDIA_PAD_FL_SOURCE;
ov5645->sd.dev = &client->dev;
ret = media_entity_pads_init(&ov5645->sd.entity, 1, &ov5645->pad);
if (ret < 0) {
dev_err(dev, "could not register media entity\n");
goto free_ctrl;
}
ret = ov5645_s_power(&ov5645->sd, true);
if (ret < 0) {
dev_err(dev, "could not power up OV5645\n");
goto free_entity;
}
ret = ov5645_read_reg(ov5645, OV5645_CHIP_ID_HIGH, &chip_id_high);
if (ret < 0 || chip_id_high != OV5645_CHIP_ID_HIGH_BYTE) {
dev_err(dev, "could not read ID high\n");
ret = -ENODEV;
goto power_down;
}
ret = ov5645_read_reg(ov5645, OV5645_CHIP_ID_LOW, &chip_id_low);
if (ret < 0 || chip_id_low != OV5645_CHIP_ID_LOW_BYTE) {
dev_err(dev, "could not read ID low\n");
ret = -ENODEV;
goto power_down;
}
dev_info(dev, "OV5645 detected at address 0x%02x\n", client->addr);
ret = ov5645_read_reg(ov5645, OV5645_AEC_PK_MANUAL,
&ov5645->aec_pk_manual);
if (ret < 0) {
dev_err(dev, "could not read AEC/AGC mode\n");
ret = -ENODEV;
goto power_down;
}
ret = ov5645_read_reg(ov5645, OV5645_TIMING_TC_REG20,
&ov5645->timing_tc_reg20);
if (ret < 0) {
dev_err(dev, "could not read vflip value\n");
ret = -ENODEV;
goto power_down;
}
ret = ov5645_read_reg(ov5645, OV5645_TIMING_TC_REG21,
&ov5645->timing_tc_reg21);
if (ret < 0) {
dev_err(dev, "could not read hflip value\n");
ret = -ENODEV;
goto power_down;
}
ov5645_s_power(&ov5645->sd, false);
ret = v4l2_async_register_subdev(&ov5645->sd);
if (ret < 0) {
dev_err(dev, "could not register v4l2 device\n");
goto free_entity;
}
ov5645_entity_init_cfg(&ov5645->sd, NULL);
return 0;
power_down:
ov5645_s_power(&ov5645->sd, false);
free_entity:
media_entity_cleanup(&ov5645->sd.entity);
free_ctrl:
v4l2_ctrl_handler_free(&ov5645->ctrls);
mutex_destroy(&ov5645->power_lock);
return ret;
}
static int ov5645_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5645 *ov5645 = to_ov5645(sd);
v4l2_async_unregister_subdev(&ov5645->sd);
media_entity_cleanup(&ov5645->sd.entity);
v4l2_ctrl_handler_free(&ov5645->ctrls);
mutex_destroy(&ov5645->power_lock);
return 0;
}
