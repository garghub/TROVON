static void adv748x_hdmi_fill_format(struct adv748x_hdmi *hdmi,
struct v4l2_mbus_framefmt *fmt)
{
memset(fmt, 0, sizeof(*fmt));
fmt->code = MEDIA_BUS_FMT_RGB888_1X24;
fmt->field = hdmi->timings.bt.interlaced ?
V4L2_FIELD_ALTERNATE : V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
fmt->width = hdmi->timings.bt.width;
fmt->height = hdmi->timings.bt.height;
}
static void adv748x_fill_optional_dv_timings(struct v4l2_dv_timings *timings)
{
v4l2_find_dv_timings_cap(timings, &adv748x_hdmi_timings_cap,
250000, NULL, NULL);
}
static bool adv748x_hdmi_has_signal(struct adv748x_state *state)
{
int val;
val = hdmi_read(state, ADV748X_HDMI_LW1);
return (val & ADV748X_HDMI_LW1_VERT_FILTER) &&
(val & ADV748X_HDMI_LW1_DE_REGEN);
}
static int adv748x_hdmi_read_pixelclock(struct adv748x_state *state)
{
int a, b;
a = hdmi_read(state, ADV748X_HDMI_TMDS_1);
b = hdmi_read(state, ADV748X_HDMI_TMDS_2);
if (a < 0 || b < 0)
return -ENODATA;
return ((a << 1) | (b >> 7)) * 1000000 + (b & 0x7f) * 1000000 / 128;
}
static void adv748x_hdmi_set_de_timings(struct adv748x_state *state, int shift)
{
u8 high, low;
high = ADV748X_CP_DE_POS_HIGH_SET;
high |= (shift & 0x300) >> 8;
low = shift & 0xff;
cp_write(state, ADV748X_CP_DE_POS_HIGH, high);
cp_write(state, ADV748X_CP_DE_POS_END_LOW, low);
high |= (shift & 0x300) >> 6;
cp_write(state, ADV748X_CP_DE_POS_HIGH, high);
cp_write(state, ADV748X_CP_DE_POS_START_LOW, low);
}
static int adv748x_hdmi_set_video_timings(struct adv748x_state *state,
const struct v4l2_dv_timings *timings)
{
const struct adv748x_hdmi_video_standards *stds =
adv748x_hdmi_video_standards;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(adv748x_hdmi_video_standards); i++) {
if (!v4l2_match_dv_timings(timings, &stds[i].timings, 250000,
false))
continue;
}
if (i >= ARRAY_SIZE(adv748x_hdmi_video_standards))
return -EINVAL;
switch (stds[i].vid_std) {
case 0x53:
adv748x_hdmi_set_de_timings(state, -40);
break;
case 0x54:
case 0x5e:
adv748x_hdmi_set_de_timings(state, -44);
break;
default:
adv748x_hdmi_set_de_timings(state, 0);
break;
}
io_write(state, ADV748X_IO_VID_STD, stds[i].vid_std);
io_clrset(state, ADV748X_IO_DATAPATH, ADV748X_IO_DATAPATH_VFREQ_M,
stds[i].v_freq << ADV748X_IO_DATAPATH_VFREQ_SHIFT);
return 0;
}
static int adv748x_hdmi_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
int ret;
if (!timings)
return -EINVAL;
if (v4l2_match_dv_timings(&hdmi->timings, timings, 0, false))
return 0;
if (!v4l2_valid_dv_timings(timings, &adv748x_hdmi_timings_cap,
NULL, NULL))
return -ERANGE;
adv748x_fill_optional_dv_timings(timings);
mutex_lock(&state->mutex);
ret = adv748x_hdmi_set_video_timings(state, timings);
if (ret)
goto error;
hdmi->timings = *timings;
cp_clrset(state, ADV748X_CP_VID_ADJ_2, ADV748X_CP_VID_ADJ_2_INTERLACED,
timings->bt.interlaced ?
ADV748X_CP_VID_ADJ_2_INTERLACED : 0);
mutex_unlock(&state->mutex);
return 0;
error:
mutex_unlock(&state->mutex);
return ret;
}
static int adv748x_hdmi_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
mutex_lock(&state->mutex);
*timings = hdmi->timings;
mutex_unlock(&state->mutex);
return 0;
}
static int adv748x_hdmi_query_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
struct v4l2_bt_timings *bt = &timings->bt;
int pixelclock;
int polarity;
if (!timings)
return -EINVAL;
memset(timings, 0, sizeof(struct v4l2_dv_timings));
if (!adv748x_hdmi_has_signal(state))
return -ENOLINK;
pixelclock = adv748x_hdmi_read_pixelclock(state);
if (pixelclock < 0)
return -ENODATA;
timings->type = V4L2_DV_BT_656_1120;
bt->pixelclock = pixelclock;
bt->interlaced = hdmi_read(state, ADV748X_HDMI_F1H1) &
ADV748X_HDMI_F1H1_INTERLACED ?
V4L2_DV_INTERLACED : V4L2_DV_PROGRESSIVE;
bt->width = hdmi_read16(state, ADV748X_HDMI_LW1,
ADV748X_HDMI_LW1_WIDTH_MASK);
bt->height = hdmi_read16(state, ADV748X_HDMI_F0H1,
ADV748X_HDMI_F0H1_HEIGHT_MASK);
bt->hfrontporch = hdmi_read16(state, ADV748X_HDMI_HFRONT_PORCH,
ADV748X_HDMI_HFRONT_PORCH_MASK);
bt->hsync = hdmi_read16(state, ADV748X_HDMI_HSYNC_WIDTH,
ADV748X_HDMI_HSYNC_WIDTH_MASK);
bt->hbackporch = hdmi_read16(state, ADV748X_HDMI_HBACK_PORCH,
ADV748X_HDMI_HBACK_PORCH_MASK);
bt->vfrontporch = hdmi_read16(state, ADV748X_HDMI_VFRONT_PORCH,
ADV748X_HDMI_VFRONT_PORCH_MASK) / 2;
bt->vsync = hdmi_read16(state, ADV748X_HDMI_VSYNC_WIDTH,
ADV748X_HDMI_VSYNC_WIDTH_MASK) / 2;
bt->vbackporch = hdmi_read16(state, ADV748X_HDMI_VBACK_PORCH,
ADV748X_HDMI_VBACK_PORCH_MASK) / 2;
polarity = hdmi_read(state, 0x05);
bt->polarities = (polarity & BIT(4) ? V4L2_DV_VSYNC_POS_POL : 0) |
(polarity & BIT(5) ? V4L2_DV_HSYNC_POS_POL : 0);
if (bt->interlaced == V4L2_DV_INTERLACED) {
bt->height += hdmi_read16(state, 0x0b, 0x1fff);
bt->il_vfrontporch = hdmi_read16(state, 0x2c, 0x3fff) / 2;
bt->il_vsync = hdmi_read16(state, 0x30, 0x3fff) / 2;
bt->il_vbackporch = hdmi_read16(state, 0x34, 0x3fff) / 2;
}
adv748x_fill_optional_dv_timings(timings);
hdmi->timings = *timings;
return 0;
}
static int adv748x_hdmi_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
mutex_lock(&state->mutex);
*status = adv748x_hdmi_has_signal(state) ? 0 : V4L2_IN_ST_NO_SIGNAL;
mutex_unlock(&state->mutex);
return 0;
}
static int adv748x_hdmi_s_stream(struct v4l2_subdev *sd, int enable)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
int ret;
mutex_lock(&state->mutex);
ret = adv748x_txa_power(state, enable);
if (ret)
goto done;
if (adv748x_hdmi_has_signal(state))
adv_dbg(state, "Detected HDMI signal\n");
else
adv_dbg(state, "Couldn't detect HDMI video signal\n");
done:
mutex_unlock(&state->mutex);
return ret;
}
static int adv748x_hdmi_g_pixelaspect(struct v4l2_subdev *sd,
struct v4l2_fract *aspect)
{
aspect->numerator = 1;
aspect->denominator = 1;
return 0;
}
static int adv748x_hdmi_propagate_pixelrate(struct adv748x_hdmi *hdmi)
{
struct v4l2_subdev *tx;
struct v4l2_dv_timings timings;
struct v4l2_bt_timings *bt = &timings.bt;
unsigned int fps;
tx = adv748x_get_remote_sd(&hdmi->pads[ADV748X_HDMI_SOURCE]);
if (!tx)
return -ENOLINK;
adv748x_hdmi_query_dv_timings(&hdmi->sd, &timings);
fps = DIV_ROUND_CLOSEST_ULL(bt->pixelclock,
V4L2_DV_BT_FRAME_WIDTH(bt) *
V4L2_DV_BT_FRAME_HEIGHT(bt));
return adv748x_csi2_set_pixelrate(tx, bt->width * bt->height * fps);
}
static int adv748x_hdmi_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index != 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_RGB888_1X24;
return 0;
}
static int adv748x_hdmi_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct v4l2_mbus_framefmt *mbusformat;
if (sdformat->pad != ADV748X_HDMI_SOURCE)
return -EINVAL;
if (sdformat->which == V4L2_SUBDEV_FORMAT_TRY) {
mbusformat = v4l2_subdev_get_try_format(sd, cfg, sdformat->pad);
sdformat->format = *mbusformat;
} else {
adv748x_hdmi_fill_format(hdmi, &sdformat->format);
adv748x_hdmi_propagate_pixelrate(hdmi);
}
return 0;
}
static int adv748x_hdmi_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct v4l2_mbus_framefmt *mbusformat;
if (sdformat->pad != ADV748X_HDMI_SOURCE)
return -EINVAL;
if (sdformat->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return adv748x_hdmi_get_format(sd, cfg, sdformat);
mbusformat = v4l2_subdev_get_try_format(sd, cfg, sdformat->pad);
*mbusformat = sdformat->format;
return 0;
}
static int adv748x_hdmi_get_edid(struct v4l2_subdev *sd, struct v4l2_edid *edid)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
memset(edid->reserved, 0, sizeof(edid->reserved));
if (!hdmi->edid.present)
return -ENODATA;
if (edid->start_block == 0 && edid->blocks == 0) {
edid->blocks = hdmi->edid.blocks;
return 0;
}
if (edid->start_block >= hdmi->edid.blocks)
return -EINVAL;
if (edid->start_block + edid->blocks > hdmi->edid.blocks)
edid->blocks = hdmi->edid.blocks - edid->start_block;
memcpy(edid->edid, hdmi->edid.edid + edid->start_block * 128,
edid->blocks * 128);
return 0;
}
static inline int adv748x_hdmi_edid_write_block(struct adv748x_hdmi *hdmi,
unsigned int total_len, const u8 *val)
{
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
int err = 0;
int i = 0;
int len = 0;
adv_dbg(state, "%s: write EDID block (%d byte)\n",
__func__, total_len);
while (!err && i < total_len) {
len = (total_len - i) > I2C_SMBUS_BLOCK_MAX ?
I2C_SMBUS_BLOCK_MAX :
(total_len - i);
err = adv748x_write_block(state, ADV748X_PAGE_EDID,
i, val + i, len);
i += len;
}
return err;
}
static int adv748x_hdmi_set_edid(struct v4l2_subdev *sd, struct v4l2_edid *edid)
{
struct adv748x_hdmi *hdmi = adv748x_sd_to_hdmi(sd);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
int err;
memset(edid->reserved, 0, sizeof(edid->reserved));
if (edid->start_block != 0)
return -EINVAL;
if (edid->blocks == 0) {
hdmi->edid.blocks = 0;
hdmi->edid.present = 0;
hdmi->aspect_ratio.numerator = 16;
hdmi->aspect_ratio.denominator = 9;
repeater_write(state, ADV748X_REPEATER_EDID_SZ,
edid->blocks << ADV748X_REPEATER_EDID_SZ_SHIFT);
repeater_write(state, ADV748X_REPEATER_EDID_CTL, 0);
return 0;
}
if (edid->blocks > 4) {
edid->blocks = 4;
return -E2BIG;
}
memcpy(hdmi->edid.edid, edid->edid, 128 * edid->blocks);
hdmi->edid.blocks = edid->blocks;
hdmi->edid.present = true;
hdmi->aspect_ratio = v4l2_calc_aspect_ratio(edid->edid[0x15],
edid->edid[0x16]);
err = adv748x_hdmi_edid_write_block(hdmi, 128 * edid->blocks,
hdmi->edid.edid);
if (err < 0) {
v4l2_err(sd, "error %d writing edid pad %d\n", err, edid->pad);
return err;
}
repeater_write(state, ADV748X_REPEATER_EDID_SZ,
edid->blocks << ADV748X_REPEATER_EDID_SZ_SHIFT);
repeater_write(state, ADV748X_REPEATER_EDID_CTL,
ADV748X_REPEATER_EDID_CTL_EN);
return 0;
}
static bool adv748x_hdmi_check_dv_timings(const struct v4l2_dv_timings *timings,
void *hdl)
{
const struct adv748x_hdmi_video_standards *stds =
adv748x_hdmi_video_standards;
unsigned int i;
for (i = 0; stds[i].timings.bt.width; i++)
if (v4l2_match_dv_timings(timings, &stds[i].timings, 0, false))
return true;
return false;
}
static int adv748x_hdmi_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
return v4l2_enum_dv_timings_cap(timings, &adv748x_hdmi_timings_cap,
adv748x_hdmi_check_dv_timings, NULL);
}
static int adv748x_hdmi_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
*cap = adv748x_hdmi_timings_cap;
return 0;
}
static int adv748x_hdmi_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct adv748x_hdmi *hdmi = adv748x_ctrl_to_hdmi(ctrl);
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
int ret;
u8 pattern;
ret = cp_clrset(state, ADV748X_CP_VID_ADJ,
ADV748X_CP_VID_ADJ_ENABLE,
ADV748X_CP_VID_ADJ_ENABLE);
if (ret < 0)
return ret;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ret = cp_write(state, ADV748X_CP_BRI, ctrl->val);
break;
case V4L2_CID_HUE:
ret = cp_write(state, ADV748X_CP_HUE, ctrl->val);
break;
case V4L2_CID_CONTRAST:
ret = cp_write(state, ADV748X_CP_CON, ctrl->val);
break;
case V4L2_CID_SATURATION:
ret = cp_write(state, ADV748X_CP_SAT, ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
pattern = ctrl->val;
if (pattern) {
pattern--;
pattern |= ADV748X_CP_PAT_GEN_EN;
}
ret = cp_write(state, ADV748X_CP_PAT_GEN, pattern);
break;
default:
return -EINVAL;
}
return ret;
}
static int adv748x_hdmi_init_controls(struct adv748x_hdmi *hdmi)
{
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
v4l2_ctrl_handler_init(&hdmi->ctrl_hdl, 5);
hdmi->ctrl_hdl.lock = &state->mutex;
v4l2_ctrl_new_std(&hdmi->ctrl_hdl, &adv748x_hdmi_ctrl_ops,
V4L2_CID_BRIGHTNESS, ADV748X_CP_BRI_MIN,
ADV748X_CP_BRI_MAX, 1, ADV748X_CP_BRI_DEF);
v4l2_ctrl_new_std(&hdmi->ctrl_hdl, &adv748x_hdmi_ctrl_ops,
V4L2_CID_CONTRAST, ADV748X_CP_CON_MIN,
ADV748X_CP_CON_MAX, 1, ADV748X_CP_CON_DEF);
v4l2_ctrl_new_std(&hdmi->ctrl_hdl, &adv748x_hdmi_ctrl_ops,
V4L2_CID_SATURATION, ADV748X_CP_SAT_MIN,
ADV748X_CP_SAT_MAX, 1, ADV748X_CP_SAT_DEF);
v4l2_ctrl_new_std(&hdmi->ctrl_hdl, &adv748x_hdmi_ctrl_ops,
V4L2_CID_HUE, ADV748X_CP_HUE_MIN,
ADV748X_CP_HUE_MAX, 1, ADV748X_CP_HUE_DEF);
v4l2_ctrl_new_std_menu_items(&hdmi->ctrl_hdl, &adv748x_hdmi_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(hdmi_ctrl_patgen_menu) - 1,
0, 0, hdmi_ctrl_patgen_menu);
hdmi->sd.ctrl_handler = &hdmi->ctrl_hdl;
if (hdmi->ctrl_hdl.error) {
v4l2_ctrl_handler_free(&hdmi->ctrl_hdl);
return hdmi->ctrl_hdl.error;
}
return v4l2_ctrl_handler_setup(&hdmi->ctrl_hdl);
}
int adv748x_hdmi_init(struct adv748x_hdmi *hdmi)
{
struct adv748x_state *state = adv748x_hdmi_to_state(hdmi);
static const struct v4l2_dv_timings cea1280x720 =
V4L2_DV_BT_CEA_1280X720P30;
int ret;
hdmi->timings = cea1280x720;
hdmi->aspect_ratio.numerator = 16;
hdmi->aspect_ratio.denominator = 9;
adv748x_subdev_init(&hdmi->sd, state, &adv748x_ops_hdmi,
MEDIA_ENT_F_IO_DTV, "hdmi");
hdmi->pads[ADV748X_HDMI_SINK].flags = MEDIA_PAD_FL_SINK;
hdmi->pads[ADV748X_HDMI_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_pads_init(&hdmi->sd.entity,
ADV748X_HDMI_NR_PADS, hdmi->pads);
if (ret)
return ret;
ret = adv748x_hdmi_init_controls(hdmi);
if (ret)
goto err_free_media;
return 0;
err_free_media:
media_entity_cleanup(&hdmi->sd.entity);
return ret;
}
void adv748x_hdmi_cleanup(struct adv748x_hdmi *hdmi)
{
v4l2_device_unregister_subdev(&hdmi->sd);
media_entity_cleanup(&hdmi->sd.entity);
v4l2_ctrl_handler_free(&hdmi->ctrl_hdl);
}
