static int ctrl_set_rational(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
struct mmal_parameter_rational rational_value;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
rational_value.num = ctrl->val;
rational_value.den = 100;
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&rational_value,
sizeof(rational_value));
}
static int ctrl_set_value(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
u32_value = ctrl->val;
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_iso(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *control;
if (ctrl->val > mmal_ctrl->max || ctrl->val < mmal_ctrl->min)
return 1;
if (ctrl->id == V4L2_CID_ISO_SENSITIVITY)
dev->iso = iso_values[ctrl->val];
else if (ctrl->id == V4L2_CID_ISO_SENSITIVITY_AUTO)
dev->manual_iso_enabled =
(ctrl->val == V4L2_ISO_SENSITIVITY_MANUAL);
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
if (dev->manual_iso_enabled)
u32_value = dev->iso;
else
u32_value = 0;
return vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_ISO,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_value_ev(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
s32 s32_value;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
s32_value = (ctrl->val - 12) * 2;
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&s32_value, sizeof(s32_value));
}
static int ctrl_set_rotate(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret;
u32 u32_value;
struct vchiq_mmal_component *camera;
camera = dev->component[MMAL_COMPONENT_CAMERA];
u32_value = ((ctrl->val % 360) / 90) * 90;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[0],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
if (ret < 0)
return ret;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[1],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
if (ret < 0)
return ret;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[2],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
return ret;
}
static int ctrl_set_flip(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret;
u32 u32_value;
struct vchiq_mmal_component *camera;
if (ctrl->id == V4L2_CID_HFLIP)
dev->hflip = ctrl->val;
else
dev->vflip = ctrl->val;
camera = dev->component[MMAL_COMPONENT_CAMERA];
if (dev->hflip && dev->vflip)
u32_value = MMAL_PARAM_MIRROR_BOTH;
else if (dev->hflip)
u32_value = MMAL_PARAM_MIRROR_HORIZONTAL;
else if (dev->vflip)
u32_value = MMAL_PARAM_MIRROR_VERTICAL;
else
u32_value = MMAL_PARAM_MIRROR_NONE;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[0],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
if (ret < 0)
return ret;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[1],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
if (ret < 0)
return ret;
ret = vchiq_mmal_port_parameter_set(dev->instance, &camera->output[2],
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
return ret;
}
static int ctrl_set_exposure(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
enum mmal_parameter_exposuremode exp_mode = dev->exposure_mode_user;
u32 shutter_speed = 0;
struct vchiq_mmal_port *control;
int ret = 0;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
if (mmal_ctrl->mmal_id == MMAL_PARAMETER_SHUTTER_SPEED) {
dev->manual_shutter_speed = ctrl->val * 100;
} else if (mmal_ctrl->mmal_id == MMAL_PARAMETER_EXPOSURE_MODE) {
switch (ctrl->val) {
case V4L2_EXPOSURE_AUTO:
exp_mode = MMAL_PARAM_EXPOSUREMODE_AUTO;
break;
case V4L2_EXPOSURE_MANUAL:
exp_mode = MMAL_PARAM_EXPOSUREMODE_OFF;
break;
}
dev->exposure_mode_user = exp_mode;
dev->exposure_mode_v4l2_user = ctrl->val;
} else if (mmal_ctrl->id == V4L2_CID_EXPOSURE_AUTO_PRIORITY) {
dev->exp_auto_priority = ctrl->val;
}
if (dev->scene_mode == V4L2_SCENE_MODE_NONE) {
if (exp_mode == MMAL_PARAM_EXPOSUREMODE_OFF)
shutter_speed = dev->manual_shutter_speed;
ret = vchiq_mmal_port_parameter_set(dev->instance,
control,
MMAL_PARAMETER_SHUTTER_SPEED,
&shutter_speed,
sizeof(shutter_speed));
ret += vchiq_mmal_port_parameter_set(dev->instance,
control,
MMAL_PARAMETER_EXPOSURE_MODE,
&exp_mode,
sizeof(u32));
dev->exposure_mode_active = exp_mode;
}
ret += set_framerate_params(dev);
return ret;
}
static int ctrl_set_metering_mode(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
switch (ctrl->val) {
case V4L2_EXPOSURE_METERING_AVERAGE:
dev->metering_mode = MMAL_PARAM_EXPOSUREMETERINGMODE_AVERAGE;
break;
case V4L2_EXPOSURE_METERING_CENTER_WEIGHTED:
dev->metering_mode = MMAL_PARAM_EXPOSUREMETERINGMODE_BACKLIT;
break;
case V4L2_EXPOSURE_METERING_SPOT:
dev->metering_mode = MMAL_PARAM_EXPOSUREMETERINGMODE_SPOT;
break;
}
if (dev->scene_mode == V4L2_SCENE_MODE_NONE) {
struct vchiq_mmal_port *control;
u32 u32_value = dev->metering_mode;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
} else
return 0;
}
static int ctrl_set_flicker_avoidance(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
switch (ctrl->val) {
case V4L2_CID_POWER_LINE_FREQUENCY_DISABLED:
u32_value = MMAL_PARAM_FLICKERAVOID_OFF;
break;
case V4L2_CID_POWER_LINE_FREQUENCY_50HZ:
u32_value = MMAL_PARAM_FLICKERAVOID_50HZ;
break;
case V4L2_CID_POWER_LINE_FREQUENCY_60HZ:
u32_value = MMAL_PARAM_FLICKERAVOID_60HZ;
break;
case V4L2_CID_POWER_LINE_FREQUENCY_AUTO:
u32_value = MMAL_PARAM_FLICKERAVOID_AUTO;
break;
}
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_awb_mode(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
switch (ctrl->val) {
case V4L2_WHITE_BALANCE_MANUAL:
u32_value = MMAL_PARAM_AWBMODE_OFF;
break;
case V4L2_WHITE_BALANCE_AUTO:
u32_value = MMAL_PARAM_AWBMODE_AUTO;
break;
case V4L2_WHITE_BALANCE_INCANDESCENT:
u32_value = MMAL_PARAM_AWBMODE_INCANDESCENT;
break;
case V4L2_WHITE_BALANCE_FLUORESCENT:
u32_value = MMAL_PARAM_AWBMODE_FLUORESCENT;
break;
case V4L2_WHITE_BALANCE_FLUORESCENT_H:
u32_value = MMAL_PARAM_AWBMODE_TUNGSTEN;
break;
case V4L2_WHITE_BALANCE_HORIZON:
u32_value = MMAL_PARAM_AWBMODE_HORIZON;
break;
case V4L2_WHITE_BALANCE_DAYLIGHT:
u32_value = MMAL_PARAM_AWBMODE_SUNLIGHT;
break;
case V4L2_WHITE_BALANCE_FLASH:
u32_value = MMAL_PARAM_AWBMODE_FLASH;
break;
case V4L2_WHITE_BALANCE_CLOUDY:
u32_value = MMAL_PARAM_AWBMODE_CLOUDY;
break;
case V4L2_WHITE_BALANCE_SHADE:
u32_value = MMAL_PARAM_AWBMODE_SHADE;
break;
}
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_awb_gains(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
struct vchiq_mmal_port *control;
struct mmal_parameter_awbgains gains;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
if (ctrl->id == V4L2_CID_RED_BALANCE)
dev->red_gain = ctrl->val;
else if (ctrl->id == V4L2_CID_BLUE_BALANCE)
dev->blue_gain = ctrl->val;
gains.r_gain.num = dev->red_gain;
gains.b_gain.num = dev->blue_gain;
gains.r_gain.den = gains.b_gain.den = 1000;
return vchiq_mmal_port_parameter_set(dev->instance, control,
mmal_ctrl->mmal_id,
&gains, sizeof(gains));
}
static int ctrl_set_image_effect(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret = -EINVAL;
int i, j;
struct vchiq_mmal_port *control;
struct mmal_parameter_imagefx_parameters imagefx;
for (i = 0; i < ARRAY_SIZE(v4l2_to_mmal_effects_values); i++) {
if (ctrl->val == v4l2_to_mmal_effects_values[i].v4l2_effect) {
imagefx.effect =
v4l2_to_mmal_effects_values[i].mmal_effect;
imagefx.num_effect_params =
v4l2_to_mmal_effects_values[i].num_effect_params;
if (imagefx.num_effect_params > MMAL_MAX_IMAGEFX_PARAMETERS)
imagefx.num_effect_params = MMAL_MAX_IMAGEFX_PARAMETERS;
for (j = 0; j < imagefx.num_effect_params; j++)
imagefx.effect_parameter[j] =
v4l2_to_mmal_effects_values[i].effect_params[j];
dev->colourfx.enable =
v4l2_to_mmal_effects_values[i].col_fx_enable;
if (!v4l2_to_mmal_effects_values[i].col_fx_fixed_cbcr) {
dev->colourfx.u =
v4l2_to_mmal_effects_values[i].u;
dev->colourfx.v =
v4l2_to_mmal_effects_values[i].v;
}
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
ret = vchiq_mmal_port_parameter_set(
dev->instance, control,
MMAL_PARAMETER_IMAGE_EFFECT_PARAMETERS,
&imagefx, sizeof(imagefx));
if (ret)
goto exit;
ret = vchiq_mmal_port_parameter_set(
dev->instance, control,
MMAL_PARAMETER_COLOUR_EFFECT,
&dev->colourfx, sizeof(dev->colourfx));
}
}
exit:
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"mmal_ctrl:%p ctrl id:0x%x ctrl val:%d imagefx:0x%x color_effect:%s u:%d v:%d ret %d(%d)\n",
mmal_ctrl, ctrl->id, ctrl->val, imagefx.effect,
dev->colourfx.enable ? "true" : "false",
dev->colourfx.u, dev->colourfx.v,
ret, (ret == 0 ? 0 : -EINVAL));
return (ret == 0 ? 0 : EINVAL);
}
static int ctrl_set_colfx(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret = -EINVAL;
struct vchiq_mmal_port *control;
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
dev->colourfx.enable = (ctrl->val & 0xff00) >> 8;
dev->colourfx.enable = ctrl->val & 0xff;
ret = vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_COLOUR_EFFECT,
&dev->colourfx,
sizeof(dev->colourfx));
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: After: mmal_ctrl:%p ctrl id:0x%x ctrl val:%d ret %d(%d)\n",
__func__, mmal_ctrl, ctrl->id, ctrl->val, ret,
(ret == 0 ? 0 : -EINVAL));
return (ret == 0 ? 0 : EINVAL);
}
static int ctrl_set_bitrate(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret;
struct vchiq_mmal_port *encoder_out;
dev->capture.encode_bitrate = ctrl->val;
encoder_out = &dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0];
ret = vchiq_mmal_port_parameter_set(dev->instance, encoder_out,
mmal_ctrl->mmal_id,
&ctrl->val, sizeof(ctrl->val));
ret = 0;
return ret;
}
static int ctrl_set_bitrate_mode(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 bitrate_mode;
struct vchiq_mmal_port *encoder_out;
encoder_out = &dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0];
dev->capture.encode_bitrate_mode = ctrl->val;
switch (ctrl->val) {
default:
case V4L2_MPEG_VIDEO_BITRATE_MODE_VBR:
bitrate_mode = MMAL_VIDEO_RATECONTROL_VARIABLE;
break;
case V4L2_MPEG_VIDEO_BITRATE_MODE_CBR:
bitrate_mode = MMAL_VIDEO_RATECONTROL_CONSTANT;
break;
}
vchiq_mmal_port_parameter_set(dev->instance, encoder_out,
mmal_ctrl->mmal_id,
&bitrate_mode,
sizeof(bitrate_mode));
return 0;
}
static int ctrl_set_image_encode_output(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *jpeg_out;
jpeg_out = &dev->component[MMAL_COMPONENT_IMAGE_ENCODE]->output[0];
u32_value = ctrl->val;
return vchiq_mmal_port_parameter_set(dev->instance, jpeg_out,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_video_encode_param_output(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
u32 u32_value;
struct vchiq_mmal_port *vid_enc_ctl;
vid_enc_ctl = &dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0];
u32_value = ctrl->val;
return vchiq_mmal_port_parameter_set(dev->instance, vid_enc_ctl,
mmal_ctrl->mmal_id,
&u32_value, sizeof(u32_value));
}
static int ctrl_set_video_encode_profile_level(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
struct mmal_parameter_video_profile param;
int ret = 0;
if (ctrl->id == V4L2_CID_MPEG_VIDEO_H264_PROFILE) {
switch (ctrl->val) {
case V4L2_MPEG_VIDEO_H264_PROFILE_BASELINE:
case V4L2_MPEG_VIDEO_H264_PROFILE_CONSTRAINED_BASELINE:
case V4L2_MPEG_VIDEO_H264_PROFILE_MAIN:
case V4L2_MPEG_VIDEO_H264_PROFILE_HIGH:
dev->capture.enc_profile = ctrl->val;
break;
default:
ret = -EINVAL;
break;
}
} else if (ctrl->id == V4L2_CID_MPEG_VIDEO_H264_LEVEL) {
switch (ctrl->val) {
case V4L2_MPEG_VIDEO_H264_LEVEL_1_0:
case V4L2_MPEG_VIDEO_H264_LEVEL_1B:
case V4L2_MPEG_VIDEO_H264_LEVEL_1_1:
case V4L2_MPEG_VIDEO_H264_LEVEL_1_2:
case V4L2_MPEG_VIDEO_H264_LEVEL_1_3:
case V4L2_MPEG_VIDEO_H264_LEVEL_2_0:
case V4L2_MPEG_VIDEO_H264_LEVEL_2_1:
case V4L2_MPEG_VIDEO_H264_LEVEL_2_2:
case V4L2_MPEG_VIDEO_H264_LEVEL_3_0:
case V4L2_MPEG_VIDEO_H264_LEVEL_3_1:
case V4L2_MPEG_VIDEO_H264_LEVEL_3_2:
case V4L2_MPEG_VIDEO_H264_LEVEL_4_0:
dev->capture.enc_level = ctrl->val;
break;
default:
ret = -EINVAL;
break;
}
}
if (!ret) {
switch (dev->capture.enc_profile) {
case V4L2_MPEG_VIDEO_H264_PROFILE_BASELINE:
param.profile = MMAL_VIDEO_PROFILE_H264_BASELINE;
break;
case V4L2_MPEG_VIDEO_H264_PROFILE_CONSTRAINED_BASELINE:
param.profile =
MMAL_VIDEO_PROFILE_H264_CONSTRAINED_BASELINE;
break;
case V4L2_MPEG_VIDEO_H264_PROFILE_MAIN:
param.profile = MMAL_VIDEO_PROFILE_H264_MAIN;
break;
case V4L2_MPEG_VIDEO_H264_PROFILE_HIGH:
param.profile = MMAL_VIDEO_PROFILE_H264_HIGH;
break;
default:
break;
}
switch (dev->capture.enc_level) {
case V4L2_MPEG_VIDEO_H264_LEVEL_1_0:
param.level = MMAL_VIDEO_LEVEL_H264_1;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_1B:
param.level = MMAL_VIDEO_LEVEL_H264_1b;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_1:
param.level = MMAL_VIDEO_LEVEL_H264_11;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_2:
param.level = MMAL_VIDEO_LEVEL_H264_12;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_3:
param.level = MMAL_VIDEO_LEVEL_H264_13;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_0:
param.level = MMAL_VIDEO_LEVEL_H264_2;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_1:
param.level = MMAL_VIDEO_LEVEL_H264_21;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_2:
param.level = MMAL_VIDEO_LEVEL_H264_22;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_0:
param.level = MMAL_VIDEO_LEVEL_H264_3;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_1:
param.level = MMAL_VIDEO_LEVEL_H264_31;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_2:
param.level = MMAL_VIDEO_LEVEL_H264_32;
break;
case V4L2_MPEG_VIDEO_H264_LEVEL_4_0:
param.level = MMAL_VIDEO_LEVEL_H264_4;
break;
default:
break;
}
ret = vchiq_mmal_port_parameter_set(dev->instance,
&dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0],
mmal_ctrl->mmal_id,
&param, sizeof(param));
}
return ret;
}
static int ctrl_set_scene_mode(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl *ctrl,
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl)
{
int ret = 0;
int shutter_speed;
struct vchiq_mmal_port *control;
v4l2_dbg(0, bcm2835_v4l2_debug, &dev->v4l2_dev,
"scene mode selected %d, was %d\n", ctrl->val,
dev->scene_mode);
control = &dev->component[MMAL_COMPONENT_CAMERA]->control;
if (ctrl->val == dev->scene_mode)
return 0;
if (ctrl->val == V4L2_SCENE_MODE_NONE) {
dev->scene_mode = V4L2_SCENE_MODE_NONE;
if (dev->exposure_mode_user == MMAL_PARAM_EXPOSUREMODE_OFF)
shutter_speed = dev->manual_shutter_speed;
else
shutter_speed = 0;
v4l2_dbg(0, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: scene mode none: shut_speed %d, exp_mode %d, metering %d\n",
__func__, shutter_speed, dev->exposure_mode_user,
dev->metering_mode);
ret = vchiq_mmal_port_parameter_set(dev->instance,
control,
MMAL_PARAMETER_SHUTTER_SPEED,
&shutter_speed,
sizeof(shutter_speed));
ret += vchiq_mmal_port_parameter_set(dev->instance,
control,
MMAL_PARAMETER_EXPOSURE_MODE,
&dev->exposure_mode_user,
sizeof(u32));
dev->exposure_mode_active = dev->exposure_mode_user;
ret += vchiq_mmal_port_parameter_set(dev->instance,
control,
MMAL_PARAMETER_EXP_METERING_MODE,
&dev->metering_mode,
sizeof(u32));
ret += set_framerate_params(dev);
} else {
int i;
const struct v4l2_mmal_scene_config *scene = NULL;
int shutter_speed;
enum mmal_parameter_exposuremode exposure_mode;
enum mmal_parameter_exposuremeteringmode metering_mode;
for (i = 0; i < ARRAY_SIZE(scene_configs); i++) {
if (scene_configs[i].v4l2_scene ==
ctrl->val) {
scene = &scene_configs[i];
break;
}
}
if (!scene)
return -EINVAL;
if (i >= ARRAY_SIZE(scene_configs))
return -EINVAL;
dev->scene_mode = ctrl->val;
if (scene->exposure_mode == MMAL_PARAM_EXPOSUREMODE_OFF)
shutter_speed = dev->manual_shutter_speed;
else
shutter_speed = 0;
exposure_mode = scene->exposure_mode;
metering_mode = scene->metering_mode;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: scene mode none: shut_speed %d, exp_mode %d, metering %d\n",
__func__, shutter_speed, exposure_mode, metering_mode);
ret = vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_SHUTTER_SPEED,
&shutter_speed,
sizeof(shutter_speed));
ret += vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_EXPOSURE_MODE,
&exposure_mode,
sizeof(u32));
dev->exposure_mode_active = exposure_mode;
ret += vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_EXPOSURE_MODE,
&exposure_mode,
sizeof(u32));
ret += vchiq_mmal_port_parameter_set(dev->instance, control,
MMAL_PARAMETER_EXP_METERING_MODE,
&metering_mode,
sizeof(u32));
ret += set_framerate_params(dev);
}
if (ret) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: Setting scene to %d, ret=%d\n",
__func__, ctrl->val, ret);
ret = -EINVAL;
}
return 0;
}
static int bm2835_mmal_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct bm2835_mmal_dev *dev =
container_of(ctrl->handler, struct bm2835_mmal_dev,
ctrl_handler);
const struct bm2835_mmal_v4l2_ctrl *mmal_ctrl = ctrl->priv;
int ret;
if (!mmal_ctrl || mmal_ctrl->id != ctrl->id || !mmal_ctrl->setter) {
pr_warn("mmal_ctrl:%p ctrl id:%d\n", mmal_ctrl, ctrl->id);
return -EINVAL;
}
ret = mmal_ctrl->setter(dev, ctrl, mmal_ctrl);
if (ret)
pr_warn("ctrl id:%d/MMAL param %08X- returned ret %d\n",
ctrl->id, mmal_ctrl->mmal_id, ret);
if (mmal_ctrl->ignore_errors)
ret = 0;
return ret;
}
int bm2835_mmal_set_all_camera_controls(struct bm2835_mmal_dev *dev)
{
int c;
int ret = 0;
for (c = 0; c < V4L2_CTRL_COUNT; c++) {
if ((dev->ctrls[c]) && (v4l2_ctrls[c].setter)) {
ret = v4l2_ctrls[c].setter(dev, dev->ctrls[c],
&v4l2_ctrls[c]);
if (!v4l2_ctrls[c].ignore_errors && ret) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Failed when setting default values for ctrl %d\n",
c);
break;
}
}
}
return ret;
}
int set_framerate_params(struct bm2835_mmal_dev *dev)
{
struct mmal_parameter_fps_range fps_range;
int ret;
if ((dev->exposure_mode_active != MMAL_PARAM_EXPOSUREMODE_OFF) &&
(dev->exp_auto_priority)) {
fps_range.fps_low.num = 1;
fps_range.fps_low.den = 1;
fps_range.fps_high.num = dev->capture.timeperframe.denominator;
fps_range.fps_high.den = dev->capture.timeperframe.numerator;
} else {
fps_range.fps_low.num = fps_range.fps_high.num =
dev->capture.timeperframe.denominator;
fps_range.fps_low.den = fps_range.fps_high.den =
dev->capture.timeperframe.numerator;
}
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Set fps range to %d/%d to %d/%d\n",
fps_range.fps_low.num,
fps_range.fps_low.den,
fps_range.fps_high.num,
fps_range.fps_high.den);
ret = vchiq_mmal_port_parameter_set(dev->instance,
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_PREVIEW],
MMAL_PARAMETER_FPS_RANGE,
&fps_range, sizeof(fps_range));
ret += vchiq_mmal_port_parameter_set(dev->instance,
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_VIDEO],
MMAL_PARAMETER_FPS_RANGE,
&fps_range, sizeof(fps_range));
ret += vchiq_mmal_port_parameter_set(dev->instance,
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_CAPTURE],
MMAL_PARAMETER_FPS_RANGE,
&fps_range, sizeof(fps_range));
if (ret)
v4l2_dbg(0, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Failed to set fps ret %d\n", ret);
return ret;
}
int bm2835_mmal_init_controls(struct bm2835_mmal_dev *dev,
struct v4l2_ctrl_handler *hdl)
{
int c;
const struct bm2835_mmal_v4l2_ctrl *ctrl;
v4l2_ctrl_handler_init(hdl, V4L2_CTRL_COUNT);
for (c = 0; c < V4L2_CTRL_COUNT; c++) {
ctrl = &v4l2_ctrls[c];
switch (ctrl->type) {
case MMAL_CONTROL_TYPE_STD:
dev->ctrls[c] = v4l2_ctrl_new_std(hdl,
&bm2835_mmal_ctrl_ops, ctrl->id,
ctrl->min, ctrl->max, ctrl->step, ctrl->def);
break;
case MMAL_CONTROL_TYPE_STD_MENU:
{
int mask = ctrl->min;
if (ctrl->id == V4L2_CID_SCENE_MODE) {
int i;
mask = 1 << V4L2_SCENE_MODE_NONE;
for (i = 0;
i < ARRAY_SIZE(scene_configs);
i++) {
mask |= 1 << scene_configs[i].v4l2_scene;
}
mask = ~mask;
}
dev->ctrls[c] = v4l2_ctrl_new_std_menu(hdl,
&bm2835_mmal_ctrl_ops, ctrl->id,
ctrl->max, mask, ctrl->def);
break;
}
case MMAL_CONTROL_TYPE_INT_MENU:
dev->ctrls[c] = v4l2_ctrl_new_int_menu(hdl,
&bm2835_mmal_ctrl_ops, ctrl->id,
ctrl->max, ctrl->def, ctrl->imenu);
break;
case MMAL_CONTROL_TYPE_CLUSTER:
continue;
}
if (hdl->error)
break;
dev->ctrls[c]->priv = (void *)ctrl;
}
if (hdl->error) {
pr_err("error adding control %d/%d id 0x%x\n", c,
V4L2_CTRL_COUNT, ctrl->id);
return hdl->error;
}
for (c = 0; c < V4L2_CTRL_COUNT; c++) {
ctrl = &v4l2_ctrls[c];
switch (ctrl->type) {
case MMAL_CONTROL_TYPE_CLUSTER:
v4l2_ctrl_auto_cluster(ctrl->min,
&dev->ctrls[c + 1],
ctrl->max,
ctrl->def);
break;
case MMAL_CONTROL_TYPE_STD:
case MMAL_CONTROL_TYPE_STD_MENU:
case MMAL_CONTROL_TYPE_INT_MENU:
break;
}
}
return 0;
}
