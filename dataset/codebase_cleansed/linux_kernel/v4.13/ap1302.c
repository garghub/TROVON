static int ap1302_i2c_read_reg(struct v4l2_subdev *sd,
u16 reg, u16 len, void *val)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (len == AP1302_REG16)
ret = regmap_read(dev->regmap16, reg, val);
else if (len == AP1302_REG32)
ret = regmap_read(dev->regmap32, reg, val);
else
ret = -EINVAL;
if (ret) {
dev_dbg(&client->dev, "Read reg failed. reg=0x%04X\n", reg);
return ret;
}
if (len == AP1302_REG16)
dev_dbg(&client->dev, "read_reg[0x%04X] = 0x%04X\n",
reg, *(u16 *)val);
else
dev_dbg(&client->dev, "read_reg[0x%04X] = 0x%08X\n",
reg, *(u32 *)val);
return ret;
}
static int ap1302_i2c_write_reg(struct v4l2_subdev *sd,
u16 reg, u16 len, u32 val)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (len == AP1302_REG16)
ret = regmap_write(dev->regmap16, reg, val);
else if (len == AP1302_REG32)
ret = regmap_write(dev->regmap32, reg, val);
else
ret = -EINVAL;
if (ret) {
dev_dbg(&client->dev, "Write reg failed. reg=0x%04X\n", reg);
return ret;
}
if (len == AP1302_REG16)
dev_dbg(&client->dev, "write_reg[0x%04X] = 0x%04X\n",
reg, (u16)val);
else
dev_dbg(&client->dev, "write_reg[0x%04X] = 0x%08X\n",
reg, (u32)val);
return ret;
}
static u16
ap1302_calculate_context_reg_addr(enum ap1302_contexts context, u16 offset)
{
u16 reg_addr;
if (context == CONTEXT_SNAPSHOT) {
if (offset == CNTX_S1_SENSOR_MODE)
return 0;
if (offset > CNTX_S1_SENSOR_MODE)
offset -= 2;
}
if (context == CONTEXT_PREVIEW)
reg_addr = REG_PREVIEW_BASE + offset;
else if (context == CONTEXT_VIDEO)
reg_addr = REG_VIDEO_BASE + offset;
else
reg_addr = REG_SNAPSHOT_BASE + offset;
return reg_addr;
}
static int ap1302_read_context_reg(struct v4l2_subdev *sd,
enum ap1302_contexts context, u16 offset, u16 len)
{
struct ap1302_device *dev = to_ap1302_device(sd);
u16 reg_addr = ap1302_calculate_context_reg_addr(context, offset);
if (reg_addr == 0)
return -EINVAL;
return ap1302_i2c_read_reg(sd, reg_addr, len,
((u8 *)&dev->cntx_config[context]) + offset);
}
static int ap1302_write_context_reg(struct v4l2_subdev *sd,
enum ap1302_contexts context, u16 offset, u16 len)
{
struct ap1302_device *dev = to_ap1302_device(sd);
u16 reg_addr = ap1302_calculate_context_reg_addr(context, offset);
if (reg_addr == 0)
return -EINVAL;
return ap1302_i2c_write_reg(sd, reg_addr, len,
*(u32 *)(((u8 *)&dev->cntx_config[context]) + offset));
}
static int ap1302_dump_context_reg(struct v4l2_subdev *sd,
enum ap1302_contexts context)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ap1302_device *dev = to_ap1302_device(sd);
int i;
dev_dbg(&client->dev, "Dump registers for context[%d]:\n", context);
for (i = 0; i < ARRAY_SIZE(context_info); i++) {
struct ap1302_context_info *info = &context_info[i];
u8 *var = (u8 *)&dev->cntx_config[context] + info->offset;
if (context == CONTEXT_SNAPSHOT &&
info->offset == CNTX_S1_SENSOR_MODE)
continue;
ap1302_read_context_reg(sd, context, info->offset, info->len);
if (info->len == AP1302_REG16)
dev_dbg(&client->dev, "context.%s = 0x%04X (%d)\n",
info->name, *(u16 *)var, *(u16 *)var);
else
dev_dbg(&client->dev, "context.%s = 0x%08X (%d)\n",
info->name, *(u32 *)var, *(u32 *)var);
}
return 0;
}
static int ap1302_request_firmware(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ap1302_device *dev = to_ap1302_device(sd);
int ret;
ret = request_firmware(&dev->fw, "ap1302_fw.bin", &client->dev);
if (ret)
dev_err(&client->dev,
"ap1302_request_firmware failed. ret=%d\n", ret);
return ret;
}
static int ap1302_write_fw_window(struct v4l2_subdev *sd,
u16 *win_pos, const u8 *buf, u32 len)
{
struct ap1302_device *dev = to_ap1302_device(sd);
int ret;
u32 pos;
u32 sub_len;
for (pos = 0; pos < len; pos += sub_len) {
if (len - pos < AP1302_FW_WINDOW_SIZE - *win_pos)
sub_len = len - pos;
else
sub_len = AP1302_FW_WINDOW_SIZE - *win_pos;
ret = regmap_raw_write(dev->regmap16,
*win_pos + AP1302_FW_WINDOW_OFFSET,
buf + pos, sub_len);
if (ret)
return ret;
*win_pos += sub_len;
if (*win_pos >= AP1302_FW_WINDOW_SIZE)
*win_pos = 0;
}
return 0;
}
static int ap1302_load_firmware(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ap1302_device *dev = to_ap1302_device(sd);
const struct ap1302_firmware *fw;
const u8 *fw_data;
u16 reg_val = 0;
u16 win_pos = 0;
int ret;
dev_info(&client->dev, "Start to load firmware.\n");
if (!dev->fw) {
dev_err(&client->dev, "firmware not requested.\n");
return -EINVAL;
}
fw = (const struct ap1302_firmware *) dev->fw->data;
if (dev->fw->size != (sizeof(*fw) + fw->total_size)) {
dev_err(&client->dev, "firmware size does not match.\n");
return -EINVAL;
}
fw_data = (u8 *)&fw[1];
ret = ap1302_i2c_write_reg(sd, REG_SIP_CRC, AP1302_REG16, 0xFFFF);
if (ret)
return ret;
ret = ap1302_write_fw_window(sd, &win_pos, fw_data, fw->pll_init_size);
if (ret)
return ret;
ret = ap1302_i2c_write_reg(sd, REG_BOOTDATA_STAGE,
AP1302_REG16, 0x0002);
if (ret)
return ret;
msleep(20);
ret = ap1302_write_fw_window(sd, &win_pos, fw_data + fw->pll_init_size,
fw->total_size - fw->pll_init_size);
if (ret)
return ret;
ret = ap1302_i2c_read_reg(sd, REG_SIP_CRC, AP1302_REG16, &reg_val);
if (ret)
return ret;
if (reg_val != fw->crc) {
dev_err(&client->dev,
"crc does not match. T:0x%04X F:0x%04X\n",
fw->crc, reg_val);
return -EAGAIN;
}
ret = ap1302_i2c_write_reg(sd, REG_BOOTDATA_STAGE,
AP1302_REG16, 0xFFFF);
if (ret)
return ret;
dev_info(&client->dev, "Load firmware successfully.\n");
return 0;
}
static int __ap1302_s_power(struct v4l2_subdev *sd, int on, int load_fw)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret, i;
u16 ss_ptr;
dev_info(&client->dev, "ap1302_s_power is called.\n");
ret = dev->platform_data->power_ctrl(sd, on);
if (ret) {
dev_err(&client->dev,
"ap1302_s_power error. on=%d ret=%d\n", on, ret);
return ret;
}
dev->power_on = on;
if (!on || !load_fw)
return 0;
ret = ap1302_load_firmware(sd);
if (ret) {
dev_err(&client->dev,
"ap1302_load_firmware failed. ret=%d\n", ret);
return ret;
}
ret = ap1302_i2c_read_reg(sd, REG_SS_HEAD_PT0, AP1302_REG16, &ss_ptr);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(ap1302_ss_list); i++) {
ret = ap1302_i2c_write_reg(sd, ss_ptr + i * 2,
AP1302_REG16, ap1302_ss_list[i]);
if (ret)
return ret;
}
return ret;
}
static int ap1302_s_power(struct v4l2_subdev *sd, int on)
{
struct ap1302_device *dev = to_ap1302_device(sd);
int ret;
mutex_lock(&dev->input_lock);
ret = __ap1302_s_power(sd, on, 1);
dev->sys_activated = 0;
mutex_unlock(&dev->input_lock);
return ret;
}
static int ap1302_s_config(struct v4l2_subdev *sd, void *pdata)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct camera_mipi_info *mipi_info;
u16 reg_val = 0;
int ret;
dev_info(&client->dev, "ap1302_s_config is called.\n");
if (pdata == NULL)
return -ENODEV;
dev->platform_data = pdata;
mutex_lock(&dev->input_lock);
if (dev->platform_data->platform_init) {
ret = dev->platform_data->platform_init(client);
if (ret)
goto fail_power;
}
ret = __ap1302_s_power(sd, 1, 0);
if (ret)
goto fail_power;
ret = ap1302_i2c_read_reg(sd, REG_CHIP_VERSION, AP1302_REG16, &reg_val);
if (ret || (reg_val != AP1302_CHIP_ID)) {
dev_err(&client->dev,
"Chip version does no match. ret=%d ver=0x%04x\n",
ret, reg_val);
goto fail_config;
}
dev_info(&client->dev, "AP1302 Chip ID is 0x%X\n", reg_val);
ret = ap1302_i2c_read_reg(sd, REG_CHIP_REV, AP1302_REG16, &reg_val);
if (ret)
goto fail_config;
dev_info(&client->dev, "AP1302 Chip Rev is 0x%X\n", reg_val);
ret = dev->platform_data->csi_cfg(sd, 1);
if (ret)
goto fail_config;
mipi_info = v4l2_get_subdev_hostdata(sd);
if (!mipi_info)
goto fail_config;
dev->num_lanes = mipi_info->num_lanes;
ret = __ap1302_s_power(sd, 0, 0);
if (ret)
goto fail_power;
mutex_unlock(&dev->input_lock);
return ret;
fail_config:
__ap1302_s_power(sd, 0, 0);
fail_power:
mutex_unlock(&dev->input_lock);
dev_err(&client->dev, "ap1302_s_config failed\n");
return ret;
}
static enum ap1302_contexts ap1302_get_context(struct v4l2_subdev *sd)
{
struct ap1302_device *dev = to_ap1302_device(sd);
return dev->cur_context;
}
static int ap1302_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index)
return -EINVAL;
code->code = MEDIA_BUS_FMT_UYVY8_1X16;
return 0;
}
static int ap1302_match_resolution(struct ap1302_context_res *res,
struct v4l2_mbus_framefmt *fmt)
{
s32 w0, h0, mismatch, distance;
s32 w1 = fmt->width;
s32 h1 = fmt->height;
s32 min_distance = INT_MAX;
s32 i, idx = -1;
if (w1 == 0 || h1 == 0)
return -1;
for (i = 0; i < res->res_num; i++) {
w0 = res->res_table[i].width;
h0 = res->res_table[i].height;
if (w0 < w1 || h0 < h1)
continue;
mismatch = abs(w0 * h1 - w1 * h0) * 8192 / w1 / h0;
if (mismatch > 8192 * AP1302_MAX_RATIO_MISMATCH / 100)
continue;
distance = (w0 * h1 + w1 * h0) * 8192 / w1 / h1;
if (distance < min_distance) {
min_distance = distance;
idx = i;
}
}
return idx;
}
static s32 ap1302_try_mbus_fmt_locked(struct v4l2_subdev *sd,
enum ap1302_contexts context,
struct v4l2_mbus_framefmt *fmt)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct ap1302_res_struct *res_table;
s32 res_num, idx = -1;
res_table = dev->cntx_res[context].res_table;
res_num = dev->cntx_res[context].res_num;
if ((fmt->width <= res_table[res_num - 1].width) &&
(fmt->height <= res_table[res_num - 1].height))
idx = ap1302_match_resolution(&dev->cntx_res[context], fmt);
if (idx == -1)
idx = res_num - 1;
fmt->width = res_table[idx].width;
fmt->height = res_table[idx].height;
fmt->code = MEDIA_BUS_FMT_UYVY8_1X16;
return idx;
}
static int ap1302_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct ap1302_device *dev = to_ap1302_device(sd);
enum ap1302_contexts context;
struct ap1302_res_struct *res_table;
s32 cur_res;
if (format->pad)
return -EINVAL;
mutex_lock(&dev->input_lock);
context = ap1302_get_context(sd);
res_table = dev->cntx_res[context].res_table;
cur_res = dev->cntx_res[context].cur_res;
fmt->code = MEDIA_BUS_FMT_UYVY8_1X16;
fmt->width = res_table[cur_res].width;
fmt->height = res_table[cur_res].height;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ap1302_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct atomisp_input_stream_info *stream_info =
(struct atomisp_input_stream_info *)fmt->reserved;
enum ap1302_contexts context, main_context;
if (format->pad)
return -EINVAL;
if (!fmt)
return -EINVAL;
mutex_lock(&dev->input_lock);
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
context = ap1302_get_context(sd);
ap1302_try_mbus_fmt_locked(sd, context, fmt);
cfg->try_fmt = *fmt;
mutex_unlock(&dev->input_lock);
return 0;
}
context = stream_to_context[stream_info->stream];
dev_dbg(&client->dev, "ap1302_set_mbus_fmt. stream=%d context=%d\n",
stream_info->stream, context);
dev->cntx_res[context].cur_res =
ap1302_try_mbus_fmt_locked(sd, context, fmt);
dev->cntx_config[context].width = fmt->width;
dev->cntx_config[context].height = fmt->height;
ap1302_write_context_reg(sd, context, CNTX_WIDTH, AP1302_REG16);
ap1302_write_context_reg(sd, context, CNTX_HEIGHT, AP1302_REG16);
ap1302_read_context_reg(sd, context, CNTX_OUT_FMT, AP1302_REG16);
dev->cntx_config[context].out_fmt &= ~OUT_FMT_TYPE_MASK;
dev->cntx_config[context].out_fmt |= AP1302_FMT_UYVY422;
ap1302_write_context_reg(sd, context, CNTX_OUT_FMT, AP1302_REG16);
main_context = ap1302_get_context(sd);
if (context == main_context) {
ap1302_read_context_reg(sd, context,
CNTX_MIPI_CTRL, AP1302_REG16);
dev->cntx_config[context].mipi_ctrl &= ~MIPI_CTRL_IMGVC_MASK;
dev->cntx_config[context].mipi_ctrl |=
(context << MIPI_CTRL_IMGVC_OFFSET);
dev->cntx_config[context].mipi_ctrl &= ~MIPI_CTRL_SSVC_MASK;
dev->cntx_config[context].mipi_ctrl |=
(context << MIPI_CTRL_SSVC_OFFSET);
dev->cntx_config[context].mipi_ctrl &= ~MIPI_CTRL_SSTYPE_MASK;
dev->cntx_config[context].mipi_ctrl |=
(0x12 << MIPI_CTRL_SSTYPE_OFFSET);
ap1302_write_context_reg(sd, context,
CNTX_MIPI_CTRL, AP1302_REG16);
ap1302_read_context_reg(sd, context,
CNTX_SS, AP1302_REG16);
dev->cntx_config[context].ss = AP1302_SS_CTRL;
ap1302_write_context_reg(sd, context,
CNTX_SS, AP1302_REG16);
} else {
ap1302_read_context_reg(sd, context,
CNTX_MIPI_II_CTRL, AP1302_REG16);
dev->cntx_config[context].mipi_ii_ctrl &= ~MIPI_CTRL_IMGVC_MASK;
dev->cntx_config[context].mipi_ii_ctrl |=
(context << MIPI_CTRL_IMGVC_OFFSET);
ap1302_write_context_reg(sd, context,
CNTX_MIPI_II_CTRL, AP1302_REG16);
if (stream_info->enable) {
ap1302_read_context_reg(sd, main_context,
CNTX_OUT_FMT, AP1302_REG16);
dev->cntx_config[context].out_fmt |=
(aux_stream_config[main_context][context]
<< OUT_FMT_IIS_OFFSET);
ap1302_write_context_reg(sd, main_context,
CNTX_OUT_FMT, AP1302_REG16);
}
}
stream_info->ch_id = context;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ap1302_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *interval)
{
struct ap1302_device *dev = to_ap1302_device(sd);
enum ap1302_contexts context;
struct ap1302_res_struct *res_table;
u32 cur_res;
mutex_lock(&dev->input_lock);
context = ap1302_get_context(sd);
res_table = dev->cntx_res[context].res_table;
cur_res = dev->cntx_res[context].cur_res;
interval->interval.denominator = res_table[cur_res].fps;
interval->interval.numerator = 1;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ap1302_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct ap1302_device *dev = to_ap1302_device(sd);
enum ap1302_contexts context;
struct ap1302_res_struct *res_table;
int index = fse->index;
mutex_lock(&dev->input_lock);
context = ap1302_get_context(sd);
if (index >= dev->cntx_res[context].res_num) {
mutex_unlock(&dev->input_lock);
return -EINVAL;
}
res_table = dev->cntx_res[context].res_table;
fse->min_width = res_table[index].width;
fse->min_height = res_table[index].height;
fse->max_width = res_table[index].width;
fse->max_height = res_table[index].height;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ap1302_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
*frames = 0;
return 0;
}
static int ap1302_s_stream(struct v4l2_subdev *sd, int enable)
{
struct ap1302_device *dev = to_ap1302_device(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
enum ap1302_contexts context;
u32 reg_val;
int ret;
mutex_lock(&dev->input_lock);
context = ap1302_get_context(sd);
dev_dbg(&client->dev, "ap1302_s_stream. context=%d enable=%d\n",
context, enable);
ap1302_i2c_read_reg(sd, REG_CTRL,
AP1302_REG16, &reg_val);
reg_val &= ~CTRL_CNTX_MASK;
reg_val |= (context<<CTRL_CNTX_OFFSET);
ap1302_i2c_write_reg(sd, REG_CTRL,
AP1302_REG16, reg_val);
ap1302_i2c_read_reg(sd, REG_SENSOR_SELECT,
AP1302_REG16, &reg_val);
reg_val &= ~SENSOR_SELECT_MASK;
reg_val |= (AP1302_SENSOR_PRI<<SENSOR_SELECT_OFFSET);
ap1302_i2c_write_reg(sd, REG_SENSOR_SELECT,
AP1302_REG16, reg_val);
if (enable) {
dev_info(&client->dev, "Start stream. context=%d\n", context);
ap1302_dump_context_reg(sd, context);
if (!dev->sys_activated) {
reg_val = AP1302_SYS_ACTIVATE;
dev->sys_activated = 1;
} else {
reg_val = AP1302_SYS_SWITCH;
}
} else {
dev_info(&client->dev, "Stop stream. context=%d\n", context);
reg_val = AP1302_SYS_SWITCH;
}
ret = ap1302_i2c_write_reg(sd, REG_SYS_START, AP1302_REG16, reg_val);
if (ret)
dev_err(&client->dev,
"AP1302 set stream failed. enable=%d\n", enable);
mutex_unlock(&dev->input_lock);
return ret;
}
static int ap1302_set_exposure_off(struct v4l2_subdev *sd, s32 val)
{
val -= AP1302_MIN_EV;
return ap1302_i2c_write_reg(sd, REG_AE_BV_OFF, AP1302_REG16,
ap1302_ev_values[val]);
}
static int ap1302_set_wb_mode(struct v4l2_subdev *sd, s32 val)
{
int ret = 0;
u16 reg_val;
ret = ap1302_i2c_read_reg(sd, REG_AWB_CTRL, AP1302_REG16, &reg_val);
if (ret)
return ret;
reg_val &= ~AWB_CTRL_MODE_MASK;
reg_val |= ap1302_wb_values[val] << AWB_CTRL_MODE_OFFSET;
if (val == V4L2_WHITE_BALANCE_FLASH)
reg_val |= AWB_CTRL_FLASH_MASK;
else
reg_val &= ~AWB_CTRL_FLASH_MASK;
ret = ap1302_i2c_write_reg(sd, REG_AWB_CTRL, AP1302_REG16, reg_val);
return ret;
}
static int ap1302_set_zoom(struct v4l2_subdev *sd, s32 val)
{
ap1302_i2c_write_reg(sd, REG_DZ_TGT_FCT, AP1302_REG16,
val * 4 + 0x100);
return 0;
}
static int ap1302_set_special_effect(struct v4l2_subdev *sd, s32 val)
{
ap1302_i2c_write_reg(sd, REG_SFX_MODE, AP1302_REG16,
ap1302_sfx_values[val]);
return 0;
}
static int ap1302_set_scene_mode(struct v4l2_subdev *sd, s32 val)
{
ap1302_i2c_write_reg(sd, REG_SCENE_CTRL, AP1302_REG16,
ap1302_scene_mode_values[val]);
return 0;
}
static int ap1302_set_flicker_freq(struct v4l2_subdev *sd, s32 val)
{
ap1302_i2c_write_reg(sd, REG_FLICK_CTRL, AP1302_REG16,
ap1302_flicker_values[val]);
return 0;
}
static int ap1302_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ap1302_device *dev = container_of(
ctrl->handler, struct ap1302_device, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_RUN_MODE:
dev->cur_context = ap1302_cntx_mapping[ctrl->val];
break;
case V4L2_CID_EXPOSURE:
ap1302_set_exposure_off(&dev->sd, ctrl->val);
break;
case V4L2_CID_AUTO_N_PRESET_WHITE_BALANCE:
ap1302_set_wb_mode(&dev->sd, ctrl->val);
break;
case V4L2_CID_ZOOM_ABSOLUTE:
ap1302_set_zoom(&dev->sd, ctrl->val);
break;
case V4L2_CID_COLORFX:
ap1302_set_special_effect(&dev->sd, ctrl->val);
break;
case V4L2_CID_SCENE_MODE:
ap1302_set_scene_mode(&dev->sd, ctrl->val);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
ap1302_set_flicker_freq(&dev->sd, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int ap1302_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct ap1302_device *dev = to_ap1302_device(sd);
int ret;
u32 reg_val;
if (reg->size != AP1302_REG16 &&
reg->size != AP1302_REG32)
return -EINVAL;
mutex_lock(&dev->input_lock);
if (dev->power_on)
ret = ap1302_i2c_read_reg(sd, reg->reg, reg->size, &reg_val);
else
ret = -EIO;
mutex_unlock(&dev->input_lock);
if (ret)
return ret;
reg->val = reg_val;
return 0;
}
static int ap1302_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct ap1302_device *dev = to_ap1302_device(sd);
int ret;
if (reg->size != AP1302_REG16 &&
reg->size != AP1302_REG32)
return -EINVAL;
mutex_lock(&dev->input_lock);
if (dev->power_on)
ret = ap1302_i2c_write_reg(sd, reg->reg, reg->size, reg->val);
else
ret = -EIO;
mutex_unlock(&dev->input_lock);
return ret;
}
static long ap1302_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
long ret = 0;
switch (cmd) {
case VIDIOC_DBG_G_REGISTER:
ret = ap1302_g_register(sd, arg);
break;
case VIDIOC_DBG_S_REGISTER:
ret = ap1302_s_register(sd, arg);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int ap1302_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ap1302_device *dev = to_ap1302_device(sd);
if (dev->platform_data->platform_deinit)
dev->platform_data->platform_deinit();
release_firmware(dev->fw);
media_entity_cleanup(&dev->sd.entity);
dev->platform_data->csi_cfg(sd, 0);
v4l2_device_unregister_subdev(sd);
return 0;
}
static int ap1302_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ap1302_device *dev;
int ret;
unsigned int i;
dev_info(&client->dev, "ap1302 probe called.\n");
dev = devm_kzalloc(&client->dev, sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(&client->dev, "%s: out of memory\n", __func__);
return -ENOMEM;
}
mutex_init(&dev->input_lock);
v4l2_i2c_subdev_init(&(dev->sd), client, &ap1302_ops);
ret = ap1302_request_firmware(&(dev->sd));
if (ret) {
dev_err(&client->dev, "Cannot request ap1302 firmware.\n");
goto out_free;
}
dev->regmap16 = devm_regmap_init_i2c(client, &ap1302_reg16_config);
if (IS_ERR(dev->regmap16)) {
ret = PTR_ERR(dev->regmap16);
dev_err(&client->dev,
"Failed to allocate 16bit register map: %d\n", ret);
return ret;
}
dev->regmap32 = devm_regmap_init_i2c(client, &ap1302_reg32_config);
if (IS_ERR(dev->regmap32)) {
ret = PTR_ERR(dev->regmap32);
dev_err(&client->dev,
"Failed to allocate 32bit register map: %d\n", ret);
return ret;
}
if (client->dev.platform_data) {
ret = ap1302_s_config(&dev->sd, client->dev.platform_data);
if (ret)
goto out_free;
}
dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
dev->pad.flags = MEDIA_PAD_FL_SOURCE;
dev->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
dev->cntx_res[CONTEXT_PREVIEW].res_num = ARRAY_SIZE(ap1302_preview_res);
dev->cntx_res[CONTEXT_PREVIEW].res_table = ap1302_preview_res;
dev->cntx_res[CONTEXT_SNAPSHOT].res_num =
ARRAY_SIZE(ap1302_snapshot_res);
dev->cntx_res[CONTEXT_SNAPSHOT].res_table = ap1302_snapshot_res;
dev->cntx_res[CONTEXT_VIDEO].res_num = ARRAY_SIZE(ap1302_video_res);
dev->cntx_res[CONTEXT_VIDEO].res_table = ap1302_video_res;
ret = v4l2_ctrl_handler_init(&dev->ctrl_handler, ARRAY_SIZE(ctrls));
if (ret) {
ap1302_remove(client);
return ret;
}
for (i = 0; i < ARRAY_SIZE(ctrls); i++)
v4l2_ctrl_new_custom(&dev->ctrl_handler, &ctrls[i], NULL);
if (dev->ctrl_handler.error) {
ap1302_remove(client);
return dev->ctrl_handler.error;
}
dev->ctrl_handler.lock = &dev->input_lock;
dev->sd.ctrl_handler = &dev->ctrl_handler;
v4l2_ctrl_handler_setup(&dev->ctrl_handler);
dev->run_mode = v4l2_ctrl_find(&dev->ctrl_handler, V4L2_CID_RUN_MODE);
v4l2_ctrl_s_ctrl(dev->run_mode, ATOMISP_RUN_MODE_PREVIEW);
ret = media_entity_pads_init(&dev->sd.entity, 1, &dev->pad);
if (ret)
ap1302_remove(client);
return ret;
out_free:
v4l2_device_unregister_subdev(&dev->sd);
return ret;
}
