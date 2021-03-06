int pwc_init_controls(struct pwc_device *pdev)
{
struct v4l2_ctrl_handler *hdl;
struct v4l2_ctrl_config cfg;
int r, def;
hdl = &pdev->ctrl_handler;
r = v4l2_ctrl_handler_init(hdl, 20);
if (r)
return r;
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, BRIGHTNESS_FORMATTER, &def);
if (r || def > 127)
def = 63;
pdev->brightness = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 127, 1, def);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, CONTRAST_FORMATTER, &def);
if (r || def > 63)
def = 31;
pdev->contrast = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_CONTRAST, 0, 63, 1, def);
if (pdev->type >= 675) {
if (pdev->type < 730)
pdev->saturation_fmt = SATURATION_MODE_FORMATTER2;
else
pdev->saturation_fmt = SATURATION_MODE_FORMATTER1;
r = pwc_get_s8_ctrl(pdev, GET_CHROM_CTL, pdev->saturation_fmt,
&def);
if (r || def < -100 || def > 100)
def = 0;
pdev->saturation = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_SATURATION, -100, 100, 1, def);
}
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, GAMMA_FORMATTER, &def);
if (r || def > 31)
def = 15;
pdev->gamma = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_GAMMA, 0, 31, 1, def);
r = pwc_get_u8_ctrl(pdev, GET_CHROM_CTL, WB_MODE_FORMATTER, &def);
if (r || def > awb_auto)
def = awb_auto;
cfg = pwc_auto_white_balance_cfg;
cfg.name = v4l2_ctrl_get_name(cfg.id);
cfg.def = def;
pdev->auto_white_balance = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
if (!pdev->auto_white_balance)
return hdl->error;
r = pwc_get_u8_ctrl(pdev, GET_CHROM_CTL,
PRESET_MANUAL_RED_GAIN_FORMATTER, &def);
if (r)
def = 127;
pdev->red_balance = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 255, 1, def);
r = pwc_get_u8_ctrl(pdev, GET_CHROM_CTL,
PRESET_MANUAL_BLUE_GAIN_FORMATTER, &def);
if (r)
def = 127;
pdev->blue_balance = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 255, 1, def);
v4l2_ctrl_auto_cluster(3, &pdev->auto_white_balance, awb_manual, true);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, AGC_MODE_FORMATTER, &def);
if (r || (def != 0 && def != 0xff))
def = 0;
pdev->autogain = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, def == 0);
if (!pdev->autogain)
return hdl->error;
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, PRESET_AGC_FORMATTER, &def);
if (r || def > 63)
def = 31;
pdev->gain = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_GAIN, 0, 63, 1, def);
if (DEVICE_USE_CODEC2(pdev->type)) {
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, SHUTTER_MODE_FORMATTER,
&def);
if (r || (def != 0 && def != 0xff))
def = 0;
pdev->exposure_auto = v4l2_ctrl_new_std_menu(hdl,
&pwc_ctrl_ops,
V4L2_CID_EXPOSURE_AUTO,
1, 0, def != 0);
if (!pdev->exposure_auto)
return hdl->error;
r = pwc_get_u16_ctrl(pdev, GET_STATUS_CTL,
READ_SHUTTER_FORMATTER, &def);
if (r || def > 655)
def = 655;
pdev->exposure = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 655, 1, def);
v4l2_ctrl_auto_cluster(2, &pdev->autogain, 0, true);
v4l2_ctrl_auto_cluster(2, &pdev->exposure_auto,
V4L2_EXPOSURE_MANUAL, true);
} else if (DEVICE_USE_CODEC3(pdev->type)) {
r = pwc_get_u16_ctrl(pdev, GET_STATUS_CTL,
READ_SHUTTER_FORMATTER, &def);
if (r || def > 255)
def = 255;
pdev->exposure = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 255, 1, def);
pdev->autogain_expo_cluster[0] = pdev->autogain;
pdev->autogain_expo_cluster[1] = pdev->gain;
pdev->autogain_expo_cluster[2] = pdev->exposure;
v4l2_ctrl_auto_cluster(3, pdev->autogain_expo_cluster,
0, true);
}
r = pwc_get_u8_ctrl(pdev, GET_CHROM_CTL, COLOUR_MODE_FORMATTER,
&def);
if (r || (def != 0 && def != 0xff))
def = 0xff;
pdev->colorfx = v4l2_ctrl_new_std_menu(hdl, &pwc_ctrl_ops,
V4L2_CID_COLORFX, 1, 0, def == 0);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, AUTO_CONTOUR_FORMATTER, &def);
if (r || (def != 0 && def != 0xff))
def = 0;
cfg = pwc_autocontour_cfg;
cfg.def = def == 0;
pdev->autocontour = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
if (!pdev->autocontour)
return hdl->error;
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL, PRESET_CONTOUR_FORMATTER, &def);
if (r || def > 63)
def = 31;
cfg = pwc_contour_cfg;
cfg.def = def;
pdev->contour = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
v4l2_ctrl_auto_cluster(2, &pdev->autocontour, 0, false);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL,
BACK_LIGHT_COMPENSATION_FORMATTER, &def);
if (r || (def != 0 && def != 0xff))
def = 0;
cfg = pwc_backlight_cfg;
cfg.name = v4l2_ctrl_get_name(cfg.id);
cfg.def = def == 0;
pdev->backlight = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL,
FLICKERLESS_MODE_FORMATTER, &def);
if (r || (def != 0 && def != 0xff))
def = 0;
cfg = pwc_flicker_cfg;
cfg.name = v4l2_ctrl_get_name(cfg.id);
cfg.def = def == 0;
pdev->flicker = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
r = pwc_get_u8_ctrl(pdev, GET_LUM_CTL,
DYNAMIC_NOISE_CONTROL_FORMATTER, &def);
if (r || def > 3)
def = 2;
cfg = pwc_noise_reduction_cfg;
cfg.def = def;
pdev->noise_reduction = v4l2_ctrl_new_custom(hdl, &cfg, NULL);
pdev->save_user = v4l2_ctrl_new_custom(hdl, &pwc_save_user_cfg, NULL);
pdev->restore_user = v4l2_ctrl_new_custom(hdl, &pwc_restore_user_cfg,
NULL);
if (pdev->restore_user)
pdev->restore_user->flags |= V4L2_CTRL_FLAG_UPDATE;
pdev->restore_factory = v4l2_ctrl_new_custom(hdl,
&pwc_restore_factory_cfg,
NULL);
if (pdev->restore_factory)
pdev->restore_factory->flags |= V4L2_CTRL_FLAG_UPDATE;
if (!(pdev->features & FEATURE_MOTOR_PANTILT))
return hdl->error;
pdev->motor_pan = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_PAN_RELATIVE, -4480, 4480, 64, 0);
if (!pdev->motor_pan)
return hdl->error;
pdev->motor_tilt = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_TILT_RELATIVE, -1920, 1920, 64, 0);
pdev->motor_pan_reset = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_PAN_RESET, 0, 0, 0, 0);
pdev->motor_tilt_reset = v4l2_ctrl_new_std(hdl, &pwc_ctrl_ops,
V4L2_CID_TILT_RESET, 0, 0, 0, 0);
v4l2_ctrl_cluster(4, &pdev->motor_pan);
return hdl->error;
}
static void pwc_vidioc_fill_fmt(const struct pwc_device *pdev, struct v4l2_format *f)
{
memset(&f->fmt.pix, 0, sizeof(struct v4l2_pix_format));
f->fmt.pix.width = pdev->view.x;
f->fmt.pix.height = pdev->view.y;
f->fmt.pix.field = V4L2_FIELD_NONE;
if (pdev->pixfmt == V4L2_PIX_FMT_YUV420) {
f->fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
f->fmt.pix.bytesperline = (f->fmt.pix.width * 3)/2;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
} else {
f->fmt.pix.bytesperline = pdev->vbandlength/4;
f->fmt.pix.sizeimage = pdev->frame_size + sizeof(struct pwc_raw_frame);
if (DEVICE_USE_CODEC1(pdev->type))
f->fmt.pix.pixelformat = V4L2_PIX_FMT_PWC1;
else
f->fmt.pix.pixelformat = V4L2_PIX_FMT_PWC2;
}
PWC_DEBUG_IOCTL("pwc_vidioc_fill_fmt() "
"width=%d, height=%d, bytesperline=%d, sizeimage=%d, pixelformat=%c%c%c%c\n",
f->fmt.pix.width,
f->fmt.pix.height,
f->fmt.pix.bytesperline,
f->fmt.pix.sizeimage,
(f->fmt.pix.pixelformat)&255,
(f->fmt.pix.pixelformat>>8)&255,
(f->fmt.pix.pixelformat>>16)&255,
(f->fmt.pix.pixelformat>>24)&255);
}
static int pwc_vidioc_try_fmt(struct pwc_device *pdev, struct v4l2_format *f)
{
if (f->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
PWC_DEBUG_IOCTL("Bad video type must be V4L2_BUF_TYPE_VIDEO_CAPTURE\n");
return -EINVAL;
}
switch (f->fmt.pix.pixelformat) {
case V4L2_PIX_FMT_YUV420:
break;
case V4L2_PIX_FMT_PWC1:
if (DEVICE_USE_CODEC23(pdev->type)) {
PWC_DEBUG_IOCTL("codec1 is only supported for old pwc webcam\n");
return -EINVAL;
}
break;
case V4L2_PIX_FMT_PWC2:
if (DEVICE_USE_CODEC1(pdev->type)) {
PWC_DEBUG_IOCTL("codec23 is only supported for new pwc webcam\n");
return -EINVAL;
}
break;
default:
PWC_DEBUG_IOCTL("Unsupported pixel format\n");
return -EINVAL;
}
if (f->fmt.pix.width > pdev->view_max.x)
f->fmt.pix.width = pdev->view_max.x;
else if (f->fmt.pix.width < pdev->view_min.x)
f->fmt.pix.width = pdev->view_min.x;
if (f->fmt.pix.height > pdev->view_max.y)
f->fmt.pix.height = pdev->view_max.y;
else if (f->fmt.pix.height < pdev->view_min.y)
f->fmt.pix.height = pdev->view_min.y;
return 0;
}
static int pwc_s_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *f)
{
struct pwc_device *pdev = video_drvdata(file);
int ret, fps, snapshot, compression, pixelformat;
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != NULL &&
pdev->capt_file != file)
return -EBUSY;
pdev->capt_file = file;
ret = pwc_vidioc_try_fmt(pdev, f);
if (ret<0)
return ret;
pixelformat = f->fmt.pix.pixelformat;
compression = pdev->vcompression;
snapshot = 0;
fps = pdev->vframes;
if (f->fmt.pix.priv) {
compression = (f->fmt.pix.priv & PWC_QLT_MASK) >> PWC_QLT_SHIFT;
snapshot = !!(f->fmt.pix.priv & PWC_FPS_SNAPSHOT);
fps = (f->fmt.pix.priv & PWC_FPS_FRMASK) >> PWC_FPS_SHIFT;
if (fps == 0)
fps = pdev->vframes;
}
if (pixelformat != V4L2_PIX_FMT_YUV420 &&
pixelformat != V4L2_PIX_FMT_PWC1 &&
pixelformat != V4L2_PIX_FMT_PWC2)
return -EINVAL;
if (vb2_is_streaming(&pdev->vb_queue))
return -EBUSY;
PWC_DEBUG_IOCTL("Trying to set format to: width=%d height=%d fps=%d "
"compression=%d snapshot=%d format=%c%c%c%c\n",
f->fmt.pix.width, f->fmt.pix.height, fps,
compression, snapshot,
(pixelformat)&255,
(pixelformat>>8)&255,
(pixelformat>>16)&255,
(pixelformat>>24)&255);
ret = pwc_set_video_mode(pdev,
f->fmt.pix.width,
f->fmt.pix.height,
fps,
compression,
snapshot);
PWC_DEBUG_IOCTL("pwc_set_video_mode(), return=%d\n", ret);
if (ret)
return ret;
pdev->pixfmt = pixelformat;
pwc_vidioc_fill_fmt(pdev, f);
return 0;
}
static int pwc_querycap(struct file *file, void *fh, struct v4l2_capability *cap)
{
struct pwc_device *pdev = video_drvdata(file);
if (!pdev->udev)
return -ENODEV;
strcpy(cap->driver, PWC_NAME);
strlcpy(cap->card, pdev->vdev.name, sizeof(cap->card));
usb_make_path(pdev->udev, cap->bus_info, sizeof(cap->bus_info));
cap->capabilities =
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
return 0;
}
static int pwc_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
if (i->index)
return -EINVAL;
strcpy(i->name, "usb");
return 0;
}
static int pwc_g_input(struct file *file, void *fh, unsigned int *i)
{
*i = 0;
return 0;
}
static int pwc_s_input(struct file *file, void *fh, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int pwc_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct pwc_device *pdev =
container_of(ctrl->handler, struct pwc_device, ctrl_handler);
int ret = 0;
mutex_unlock(&pdev->modlock);
mutex_lock(&pdev->udevlock);
if (!pdev->udev) {
ret = -ENODEV;
goto leave;
}
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
if (pdev->color_bal_valid &&
(pdev->auto_white_balance->val != awb_auto ||
time_before(jiffies,
pdev->last_color_bal_update + HZ / 4))) {
pdev->red_balance->val = pdev->last_red_balance;
pdev->blue_balance->val = pdev->last_blue_balance;
break;
}
ret = pwc_get_u8_ctrl(pdev, GET_STATUS_CTL,
READ_RED_GAIN_FORMATTER,
&pdev->red_balance->val);
if (ret)
break;
ret = pwc_get_u8_ctrl(pdev, GET_STATUS_CTL,
READ_BLUE_GAIN_FORMATTER,
&pdev->blue_balance->val);
if (ret)
break;
pdev->last_red_balance = pdev->red_balance->val;
pdev->last_blue_balance = pdev->blue_balance->val;
pdev->last_color_bal_update = jiffies;
pdev->color_bal_valid = true;
break;
case V4L2_CID_AUTOGAIN:
if (pdev->gain_valid && time_before(jiffies,
pdev->last_gain_update + HZ / 4)) {
pdev->gain->val = pdev->last_gain;
break;
}
ret = pwc_get_u8_ctrl(pdev, GET_STATUS_CTL,
READ_AGC_FORMATTER, &pdev->gain->val);
if (ret)
break;
pdev->last_gain = pdev->gain->val;
pdev->last_gain_update = jiffies;
pdev->gain_valid = true;
if (!DEVICE_USE_CODEC3(pdev->type))
break;
case V4L2_CID_EXPOSURE_AUTO:
if (pdev->exposure_valid && time_before(jiffies,
pdev->last_exposure_update + HZ / 4)) {
pdev->exposure->val = pdev->last_exposure;
break;
}
ret = pwc_get_u16_ctrl(pdev, GET_STATUS_CTL,
READ_SHUTTER_FORMATTER,
&pdev->exposure->val);
if (ret)
break;
pdev->last_exposure = pdev->exposure->val;
pdev->last_exposure_update = jiffies;
pdev->exposure_valid = true;
break;
default:
ret = -EINVAL;
}
if (ret)
PWC_ERROR("g_ctrl %s error %d\n", ctrl->name, ret);
leave:
mutex_unlock(&pdev->udevlock);
mutex_lock(&pdev->modlock);
return ret;
}
static int pwc_set_awb(struct pwc_device *pdev)
{
int ret;
if (pdev->auto_white_balance->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_CHROM_CTL,
WB_MODE_FORMATTER,
pdev->auto_white_balance->val);
if (ret)
return ret;
if (pdev->auto_white_balance->val != awb_manual)
pdev->color_bal_valid = false;
}
if (pdev->auto_white_balance->val != awb_manual)
return 0;
if (pdev->red_balance->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_CHROM_CTL,
PRESET_MANUAL_RED_GAIN_FORMATTER,
pdev->red_balance->val);
if (ret)
return ret;
}
if (pdev->blue_balance->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_CHROM_CTL,
PRESET_MANUAL_BLUE_GAIN_FORMATTER,
pdev->blue_balance->val);
if (ret)
return ret;
}
return 0;
}
static int pwc_set_autogain(struct pwc_device *pdev)
{
int ret;
if (pdev->autogain->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
AGC_MODE_FORMATTER,
pdev->autogain->val ? 0 : 0xff);
if (ret)
return ret;
if (pdev->autogain->val)
pdev->gain_valid = false;
}
if (pdev->autogain->val)
return 0;
if (pdev->gain->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
PRESET_AGC_FORMATTER,
pdev->gain->val);
if (ret)
return ret;
}
return 0;
}
static int pwc_set_exposure_auto(struct pwc_device *pdev)
{
int ret;
int is_auto = pdev->exposure_auto->val == V4L2_EXPOSURE_AUTO;
if (pdev->exposure_auto->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
SHUTTER_MODE_FORMATTER,
is_auto ? 0 : 0xff);
if (ret)
return ret;
if (is_auto)
pdev->exposure_valid = false;
}
if (is_auto)
return 0;
if (pdev->exposure->is_new) {
ret = pwc_set_u16_ctrl(pdev, SET_LUM_CTL,
PRESET_SHUTTER_FORMATTER,
pdev->exposure->val);
if (ret)
return ret;
}
return 0;
}
static int pwc_set_autogain_expo(struct pwc_device *pdev)
{
int ret;
if (pdev->autogain->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
AGC_MODE_FORMATTER,
pdev->autogain->val ? 0 : 0xff);
if (ret)
return ret;
if (pdev->autogain->val) {
pdev->gain_valid = false;
pdev->exposure_valid = false;
}
}
if (pdev->autogain->val)
return 0;
if (pdev->gain->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
PRESET_AGC_FORMATTER,
pdev->gain->val);
if (ret)
return ret;
}
if (pdev->exposure->is_new) {
ret = pwc_set_u16_ctrl(pdev, SET_LUM_CTL,
PRESET_SHUTTER_FORMATTER,
pdev->exposure->val);
if (ret)
return ret;
}
return 0;
}
static int pwc_set_motor(struct pwc_device *pdev)
{
int ret;
u8 buf[4];
buf[0] = 0;
if (pdev->motor_pan_reset->is_new)
buf[0] |= 0x01;
if (pdev->motor_tilt_reset->is_new)
buf[0] |= 0x02;
if (pdev->motor_pan_reset->is_new || pdev->motor_tilt_reset->is_new) {
ret = send_control_msg(pdev, SET_MPT_CTL,
PT_RESET_CONTROL_FORMATTER, buf, 1);
if (ret < 0)
return ret;
}
memset(buf, 0, sizeof(buf));
if (pdev->motor_pan->is_new) {
buf[0] = pdev->motor_pan->val & 0xFF;
buf[1] = (pdev->motor_pan->val >> 8);
}
if (pdev->motor_tilt->is_new) {
buf[2] = pdev->motor_tilt->val & 0xFF;
buf[3] = (pdev->motor_tilt->val >> 8);
}
if (pdev->motor_pan->is_new || pdev->motor_tilt->is_new) {
ret = send_control_msg(pdev, SET_MPT_CTL,
PT_RELATIVE_CONTROL_FORMATTER,
buf, sizeof(buf));
if (ret < 0)
return ret;
}
return 0;
}
static int pwc_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct pwc_device *pdev =
container_of(ctrl->handler, struct pwc_device, ctrl_handler);
int ret = 0;
mutex_unlock(&pdev->modlock);
mutex_lock(&pdev->udevlock);
if (!pdev->udev) {
ret = -ENODEV;
goto leave;
}
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
BRIGHTNESS_FORMATTER, ctrl->val);
break;
case V4L2_CID_CONTRAST:
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
CONTRAST_FORMATTER, ctrl->val);
break;
case V4L2_CID_SATURATION:
ret = pwc_set_s8_ctrl(pdev, SET_CHROM_CTL,
pdev->saturation_fmt, ctrl->val);
break;
case V4L2_CID_GAMMA:
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
GAMMA_FORMATTER, ctrl->val);
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = pwc_set_awb(pdev);
break;
case V4L2_CID_AUTOGAIN:
if (DEVICE_USE_CODEC2(pdev->type))
ret = pwc_set_autogain(pdev);
else if (DEVICE_USE_CODEC3(pdev->type))
ret = pwc_set_autogain_expo(pdev);
else
ret = -EINVAL;
break;
case V4L2_CID_EXPOSURE_AUTO:
if (DEVICE_USE_CODEC2(pdev->type))
ret = pwc_set_exposure_auto(pdev);
else
ret = -EINVAL;
break;
case V4L2_CID_COLORFX:
ret = pwc_set_u8_ctrl(pdev, SET_CHROM_CTL,
COLOUR_MODE_FORMATTER,
ctrl->val ? 0 : 0xff);
break;
case PWC_CID_CUSTOM(autocontour):
if (pdev->autocontour->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
AUTO_CONTOUR_FORMATTER,
pdev->autocontour->val ? 0 : 0xff);
}
if (ret == 0 && pdev->contour->is_new) {
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
PRESET_CONTOUR_FORMATTER,
pdev->contour->val);
}
break;
case V4L2_CID_BACKLIGHT_COMPENSATION:
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
BACK_LIGHT_COMPENSATION_FORMATTER,
ctrl->val ? 0 : 0xff);
break;
case V4L2_CID_BAND_STOP_FILTER:
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
FLICKERLESS_MODE_FORMATTER,
ctrl->val ? 0 : 0xff);
break;
case PWC_CID_CUSTOM(noise_reduction):
ret = pwc_set_u8_ctrl(pdev, SET_LUM_CTL,
DYNAMIC_NOISE_CONTROL_FORMATTER,
ctrl->val);
break;
case PWC_CID_CUSTOM(save_user):
ret = pwc_button_ctrl(pdev, SAVE_USER_DEFAULTS_FORMATTER);
break;
case PWC_CID_CUSTOM(restore_user):
ret = pwc_button_ctrl(pdev, RESTORE_USER_DEFAULTS_FORMATTER);
break;
case PWC_CID_CUSTOM(restore_factory):
ret = pwc_button_ctrl(pdev,
RESTORE_FACTORY_DEFAULTS_FORMATTER);
break;
case V4L2_CID_PAN_RELATIVE:
ret = pwc_set_motor(pdev);
break;
default:
ret = -EINVAL;
}
if (ret)
PWC_ERROR("s_ctrl %s error %d\n", ctrl->name, ret);
leave:
mutex_unlock(&pdev->udevlock);
mutex_lock(&pdev->modlock);
return ret;
}
static int pwc_enum_fmt_vid_cap(struct file *file, void *fh, struct v4l2_fmtdesc *f)
{
struct pwc_device *pdev = video_drvdata(file);
switch (f->index) {
case 0:
f->pixelformat = pdev->type <= 646 ? V4L2_PIX_FMT_PWC1 : V4L2_PIX_FMT_PWC2;
f->flags = V4L2_FMT_FLAG_COMPRESSED;
strlcpy(f->description, "Raw Philips Webcam", sizeof(f->description));
break;
case 1:
f->pixelformat = V4L2_PIX_FMT_YUV420;
strlcpy(f->description, "4:2:0, planar, Y-Cb-Cr", sizeof(f->description));
break;
default:
return -EINVAL;
}
return 0;
}
static int pwc_g_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *f)
{
struct pwc_device *pdev = video_drvdata(file);
PWC_DEBUG_IOCTL("ioctl(VIDIOC_G_FMT) return size %dx%d\n",
pdev->image.x, pdev->image.y);
pwc_vidioc_fill_fmt(pdev, f);
return 0;
}
static int pwc_try_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *f)
{
struct pwc_device *pdev = video_drvdata(file);
return pwc_vidioc_try_fmt(pdev, f);
}
static int pwc_reqbufs(struct file *file, void *fh,
struct v4l2_requestbuffers *rb)
{
struct pwc_device *pdev = video_drvdata(file);
if (pdev->capt_file != NULL &&
pdev->capt_file != file)
return -EBUSY;
pdev->capt_file = file;
return vb2_reqbufs(&pdev->vb_queue, rb);
}
static int pwc_querybuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct pwc_device *pdev = video_drvdata(file);
return vb2_querybuf(&pdev->vb_queue, buf);
}
static int pwc_qbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct pwc_device *pdev = video_drvdata(file);
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != file)
return -EBUSY;
return vb2_qbuf(&pdev->vb_queue, buf);
}
static int pwc_dqbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct pwc_device *pdev = video_drvdata(file);
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != file)
return -EBUSY;
return vb2_dqbuf(&pdev->vb_queue, buf, file->f_flags & O_NONBLOCK);
}
static int pwc_streamon(struct file *file, void *fh, enum v4l2_buf_type i)
{
struct pwc_device *pdev = video_drvdata(file);
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != file)
return -EBUSY;
return vb2_streamon(&pdev->vb_queue, i);
}
static int pwc_streamoff(struct file *file, void *fh, enum v4l2_buf_type i)
{
struct pwc_device *pdev = video_drvdata(file);
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != file)
return -EBUSY;
return vb2_streamoff(&pdev->vb_queue, i);
}
static int pwc_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
struct pwc_device *pdev = video_drvdata(file);
unsigned int i = 0, index = fsize->index;
if (fsize->pixel_format == V4L2_PIX_FMT_YUV420) {
for (i = 0; i < PSZ_MAX; i++) {
if (pdev->image_mask & (1UL << i)) {
if (!index--) {
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = pwc_image_sizes[i].x;
fsize->discrete.height = pwc_image_sizes[i].y;
return 0;
}
}
}
} else if (fsize->index == 0 &&
((fsize->pixel_format == V4L2_PIX_FMT_PWC1 && DEVICE_USE_CODEC1(pdev->type)) ||
(fsize->pixel_format == V4L2_PIX_FMT_PWC2 && DEVICE_USE_CODEC23(pdev->type)))) {
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = pdev->abs_max.x;
fsize->discrete.height = pdev->abs_max.y;
return 0;
}
return -EINVAL;
}
static int pwc_enum_frameintervals(struct file *file, void *fh,
struct v4l2_frmivalenum *fival)
{
struct pwc_device *pdev = video_drvdata(file);
int size = -1;
unsigned int i;
for (i = 0; i < PSZ_MAX; i++) {
if (pwc_image_sizes[i].x == fival->width &&
pwc_image_sizes[i].y == fival->height) {
size = i;
break;
}
}
if (size < 0 || fival->pixel_format != V4L2_PIX_FMT_YUV420)
return -EINVAL;
i = pwc_get_fps(pdev, fival->index, size);
if (!i)
return -EINVAL;
fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
fival->discrete.numerator = 1;
fival->discrete.denominator = i;
return 0;
}
static int pwc_log_status(struct file *file, void *priv)
{
struct pwc_device *pdev = video_drvdata(file);
v4l2_ctrl_handler_log_status(&pdev->ctrl_handler, PWC_NAME);
return 0;
}
static long pwc_default(struct file *file, void *fh, bool valid_prio,
int cmd, void *arg)
{
struct pwc_device *pdev = video_drvdata(file);
return pwc_ioctl(pdev, cmd, arg);
}
