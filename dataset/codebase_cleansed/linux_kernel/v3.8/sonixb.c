static void reg_r(struct gspca_dev *gspca_dev,
__u16 value)
{
int res;
if (gspca_dev->usb_err < 0)
return;
res = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value,
0,
gspca_dev->usb_buf, 1,
500);
if (res < 0) {
dev_err(gspca_dev->v4l2_dev.dev,
"Error reading register %02x: %d\n", value, res);
gspca_dev->usb_err = res;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
__u16 value,
const __u8 *buffer,
int len)
{
int res;
if (gspca_dev->usb_err < 0)
return;
memcpy(gspca_dev->usb_buf, buffer, len);
res = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value,
0,
gspca_dev->usb_buf, len,
500);
if (res < 0) {
dev_err(gspca_dev->v4l2_dev.dev,
"Error writing register %02x: %d\n", value, res);
gspca_dev->usb_err = res;
}
}
static void i2c_w(struct gspca_dev *gspca_dev, const u8 *buf)
{
int retry = 60;
if (gspca_dev->usb_err < 0)
return;
reg_w(gspca_dev, 0x08, buf, 8);
while (retry--) {
if (gspca_dev->usb_err < 0)
return;
msleep(1);
reg_r(gspca_dev, 0x08);
if (gspca_dev->usb_buf[0] & 0x04) {
if (gspca_dev->usb_buf[0] & 0x08) {
dev_err(gspca_dev->v4l2_dev.dev,
"i2c error writing %02x %02x %02x %02x"
" %02x %02x %02x %02x\n",
buf[0], buf[1], buf[2], buf[3],
buf[4], buf[5], buf[6], buf[7]);
gspca_dev->usb_err = -EIO;
}
return;
}
}
dev_err(gspca_dev->v4l2_dev.dev, "i2c write timeout\n");
gspca_dev->usb_err = -EIO;
}
static void i2c_w_vector(struct gspca_dev *gspca_dev,
const __u8 buffer[][8], int len)
{
for (;;) {
if (gspca_dev->usb_err < 0)
return;
i2c_w(gspca_dev, *buffer);
len -= 8;
if (len <= 0)
break;
buffer++;
}
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_OV6650:
case SENSOR_OV7630: {
__u8 i2cOV[] =
{0xa0, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x10};
i2cOV[1] = sensor_data[sd->sensor].sensor_addr;
i2cOV[3] = sd->brightness->val;
i2c_w(gspca_dev, i2cOV);
break;
}
case SENSOR_PAS106:
case SENSOR_PAS202: {
__u8 i2cpbright[] =
{0xb0, 0x40, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x16};
__u8 i2cpdoit[] =
{0xa0, 0x40, 0x11, 0x01, 0x00, 0x00, 0x00, 0x16};
if (sd->sensor == SENSOR_PAS106) {
i2cpbright[2] = 7;
i2cpdoit[2] = 0x13;
}
if (sd->brightness->val < 127) {
i2cpbright[3] = 0x01;
i2cpbright[4] = 127 - sd->brightness->val;
} else
i2cpbright[4] = sd->brightness->val - 127;
i2c_w(gspca_dev, i2cpbright);
i2c_w(gspca_dev, i2cpdoit);
break;
}
default:
break;
}
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gain = gspca_dev->gain->val;
switch (sd->sensor) {
case SENSOR_HV7131D: {
__u8 i2c[] =
{0xc0, 0x11, 0x31, 0x00, 0x00, 0x00, 0x00, 0x17};
i2c[3] = 0x3f - gain;
i2c[4] = 0x3f - gain;
i2c[5] = 0x3f - gain;
i2c_w(gspca_dev, i2c);
break;
}
case SENSOR_TAS5110C:
case SENSOR_TAS5130CXX: {
__u8 i2c[] =
{0x30, 0x11, 0x02, 0x20, 0x70, 0x00, 0x00, 0x10};
i2c[4] = 255 - gain;
i2c_w(gspca_dev, i2c);
break;
}
case SENSOR_TAS5110D: {
__u8 i2c[] = {
0xb0, 0x61, 0x02, 0x00, 0x10, 0x00, 0x00, 0x17 };
gain = 255 - gain;
i2c[3] |= (gain & 0x80) >> 7;
i2c[3] |= (gain & 0x40) >> 5;
i2c[3] |= (gain & 0x20) >> 3;
i2c[3] |= (gain & 0x10) >> 1;
i2c[3] |= (gain & 0x08) << 1;
i2c[3] |= (gain & 0x04) << 3;
i2c[3] |= (gain & 0x02) << 5;
i2c[3] |= (gain & 0x01) << 7;
i2c_w(gspca_dev, i2c);
break;
}
case SENSOR_OV6650:
case SENSOR_OV7630: {
__u8 i2c[] = {0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10};
if (sd->sensor == SENSOR_OV7630 && gain >= 32)
gain += 16;
i2c[1] = sensor_data[sd->sensor].sensor_addr;
i2c[3] = gain;
i2c_w(gspca_dev, i2c);
break;
}
case SENSOR_PAS106:
case SENSOR_PAS202: {
__u8 i2cpgain[] =
{0xa0, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x15};
__u8 i2cpcolorgain[] =
{0xc0, 0x40, 0x07, 0x00, 0x00, 0x00, 0x00, 0x15};
__u8 i2cpdoit[] =
{0xa0, 0x40, 0x11, 0x01, 0x00, 0x00, 0x00, 0x16};
if (sd->sensor == SENSOR_PAS106) {
i2cpgain[2] = 0x0e;
i2cpcolorgain[0] = 0xd0;
i2cpcolorgain[2] = 0x09;
i2cpdoit[2] = 0x13;
}
i2cpgain[3] = gain;
i2cpcolorgain[3] = gain >> 1;
i2cpcolorgain[4] = gain >> 1;
i2cpcolorgain[5] = gain >> 1;
i2cpcolorgain[6] = gain >> 1;
i2c_w(gspca_dev, i2cpgain);
i2c_w(gspca_dev, i2cpcolorgain);
i2c_w(gspca_dev, i2cpdoit);
break;
}
default:
if (sd->bridge == BRIDGE_103) {
u8 buf[3] = { gain, gain, gain };
reg_w(gspca_dev, 0x05, buf, 3);
} else {
u8 buf[2];
buf[0] = gain << 4 | gain;
buf[1] = gain;
reg_w(gspca_dev, 0x10, buf, 2);
}
}
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_HV7131D: {
__u8 i2c[] = {0xc0, 0x11, 0x25, 0x00, 0x00, 0x00, 0x00, 0x17};
u16 reg = gspca_dev->exposure->val;
i2c[3] = reg >> 8;
i2c[4] = reg & 0xff;
i2c_w(gspca_dev, i2c);
break;
}
case SENSOR_TAS5110C:
case SENSOR_TAS5110D: {
u8 reg = gspca_dev->exposure->val;
reg = (reg << 4) | 0x0b;
reg_w(gspca_dev, 0x19, &reg, 1);
break;
}
case SENSOR_OV6650:
case SENSOR_OV7630: {
__u8 i2c[] = {0xb0, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10};
int reg10, reg11, reg10_max;
if (sd->sensor == SENSOR_OV6650) {
reg10_max = 0x4d;
i2c[4] = 0xc0;
} else
reg10_max = 0x41;
reg11 = (15 * gspca_dev->exposure->val + 999) / 1000;
if (reg11 < 1)
reg11 = 1;
else if (reg11 > 16)
reg11 = 16;
if (gspca_dev->width == 640 && reg11 < 4)
reg11 = 4;
reg10 = (gspca_dev->exposure->val * 15 * reg10_max)
/ (1000 * reg11);
if (gspca_dev->autogain->val && reg10 < 10)
reg10 = 10;
else if (reg10 > reg10_max)
reg10 = reg10_max;
i2c[1] = sensor_data[sd->sensor].sensor_addr;
i2c[3] = reg10;
i2c[4] |= reg11 - 1;
if (sd->reg11 == reg11)
i2c[0] = 0xa0;
i2c_w(gspca_dev, i2c);
if (gspca_dev->usb_err == 0)
sd->reg11 = reg11;
break;
}
case SENSOR_PAS202: {
__u8 i2cpframerate[] =
{0xb0, 0x40, 0x04, 0x00, 0x00, 0x00, 0x00, 0x16};
__u8 i2cpexpo[] =
{0xa0, 0x40, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x16};
const __u8 i2cpdoit[] =
{0xa0, 0x40, 0x11, 0x01, 0x00, 0x00, 0x00, 0x16};
int framerate_ctrl;
if (gspca_dev->exposure->val < 200) {
i2cpexpo[3] = 255 - (gspca_dev->exposure->val * 255)
/ 200;
framerate_ctrl = 500;
} else {
framerate_ctrl = (gspca_dev->exposure->val - 200)
* 1000 / 229 + 500;
}
i2cpframerate[3] = framerate_ctrl >> 6;
i2cpframerate[4] = framerate_ctrl & 0x3f;
i2c_w(gspca_dev, i2cpframerate);
i2c_w(gspca_dev, i2cpexpo);
i2c_w(gspca_dev, i2cpdoit);
break;
}
case SENSOR_PAS106: {
__u8 i2cpframerate[] =
{0xb1, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00, 0x14};
__u8 i2cpexpo[] =
{0xa1, 0x40, 0x05, 0x00, 0x00, 0x00, 0x00, 0x14};
const __u8 i2cpdoit[] =
{0xa1, 0x40, 0x13, 0x01, 0x00, 0x00, 0x00, 0x14};
int framerate_ctrl;
if (gspca_dev->exposure->val < 150) {
i2cpexpo[3] = 150 - gspca_dev->exposure->val;
framerate_ctrl = 300;
} else {
framerate_ctrl = (gspca_dev->exposure->val - 150)
* 1000 / 230 + 300;
}
i2cpframerate[3] = framerate_ctrl >> 4;
i2cpframerate[4] = framerate_ctrl & 0x0f;
i2c_w(gspca_dev, i2cpframerate);
i2c_w(gspca_dev, i2cpexpo);
i2c_w(gspca_dev, i2cpdoit);
break;
}
default:
break;
}
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_OV6650 || sd->sensor == SENSOR_OV7630) {
__u8 i2c[] = {0xa0, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x10};
switch (sd->plfreq->val) {
default:
i2c[3] = 0;
break;
case 1:
i2c[3] = (sd->sensor == SENSOR_OV6650)
? 0x4f : 0x8a;
break;
}
i2c[1] = sensor_data[sd->sensor].sensor_addr;
i2c_w(gspca_dev, i2c);
}
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int deadzone, desired_avg_lum, avg_lum;
avg_lum = atomic_read(&sd->avg_lum);
if (avg_lum == -1)
return;
if (sd->autogain_ignore_frames > 0) {
sd->autogain_ignore_frames--;
return;
}
if (sensor_data[sd->sensor].flags & F_SIF) {
deadzone = 500;
desired_avg_lum = 5000;
} else {
deadzone = 1500;
desired_avg_lum = 13000;
}
if (sd->brightness)
desired_avg_lum = sd->brightness->val * desired_avg_lum / 127;
if (gspca_dev->exposure->maximum < 500) {
if (gspca_coarse_grained_expo_autogain(gspca_dev, avg_lum,
desired_avg_lum, deadzone))
sd->autogain_ignore_frames = AUTOGAIN_IGNORE_FRAMES;
} else {
int gain_knee = gspca_dev->gain->maximum * 9 / 10;
if (gspca_expo_autogain(gspca_dev, avg_lum, desired_avg_lum,
deadzone, gain_knee, sd->exposure_knee))
sd->autogain_ignore_frames = AUTOGAIN_IGNORE_FRAMES;
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
reg_r(gspca_dev, 0x00);
if (gspca_dev->usb_buf[0] != 0x10)
return -ENODEV;
sd->sensor = id->driver_info >> 8;
sd->bridge = id->driver_info & 0xff;
cam = &gspca_dev->cam;
if (!(sensor_data[sd->sensor].flags & F_SIF)) {
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
} else {
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
}
cam->npkt = 36;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
const __u8 stop = 0x09;
reg_w(gspca_dev, 0x01, &stop, 1);
return gspca_dev->usb_err;
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (ctrl->id == V4L2_CID_AUTOGAIN && ctrl->is_new && ctrl->val) {
gspca_dev->gain->val = gspca_dev->gain->default_value;
gspca_dev->exposure->val = gspca_dev->exposure->default_value;
sd->autogain_ignore_frames = AUTOGAIN_IGNORE_FRAMES;
}
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
setbrightness(gspca_dev);
break;
case V4L2_CID_AUTOGAIN:
if (gspca_dev->exposure->is_new || (ctrl->is_new && ctrl->val))
setexposure(gspca_dev);
if (gspca_dev->gain->is_new || (ctrl->is_new && ctrl->val))
setgain(gspca_dev);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
setfreq(gspca_dev);
break;
default:
return -EINVAL;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 5);
if (sd->sensor == SENSOR_OV6650 || sd->sensor == SENSOR_OV7630 ||
sd->sensor == SENSOR_PAS106 || sd->sensor == SENSOR_PAS202)
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 127);
switch (sd->sensor) {
case SENSOR_OV6650:
case SENSOR_PAS106:
case SENSOR_PAS202:
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 31, 1, 15);
break;
case SENSOR_OV7630:
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 47, 1, 31);
break;
case SENSOR_HV7131D:
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 63, 1, 31);
break;
case SENSOR_TAS5110C:
case SENSOR_TAS5110D:
case SENSOR_TAS5130CXX:
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 127);
break;
default:
if (sd->bridge == BRIDGE_103) {
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 127, 1, 63);
} else {
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 15, 1, 7);
}
}
switch (sd->sensor) {
case SENSOR_HV7131D:
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 8191, 1, 482);
sd->exposure_knee = 964;
break;
case SENSOR_OV6650:
case SENSOR_OV7630:
case SENSOR_PAS106:
case SENSOR_PAS202:
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 1023, 1, 66);
sd->exposure_knee = 200;
break;
case SENSOR_TAS5110C:
case SENSOR_TAS5110D:
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 2, 15, 1, 2);
break;
}
if (gspca_dev->exposure) {
gspca_dev->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
}
if (sd->sensor == SENSOR_OV6650 || sd->sensor == SENSOR_OV7630)
sd->plfreq = v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 0,
V4L2_CID_POWER_LINE_FREQUENCY_DISABLED);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
if (gspca_dev->autogain)
v4l2_ctrl_auto_cluster(3, &gspca_dev->autogain, 0, false);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam = &gspca_dev->cam;
int i, mode;
__u8 regs[0x31];
mode = cam->cam_mode[gspca_dev->curr_mode].priv & 0x07;
memcpy(&regs[0x01], sensor_data[sd->sensor].bridge_init, 0x19);
regs[0x18] |= mode << 4;
if (sd->bridge == BRIDGE_103) {
regs[0x05] = 0x20;
regs[0x06] = 0x20;
regs[0x07] = 0x20;
} else {
regs[0x10] = 0x00;
regs[0x11] = 0x00;
}
if (sensor_data[sd->sensor].flags & F_SIF) {
regs[0x1a] = 0x14;
regs[0x1b] = 0x0a;
regs[0x1c] = 0x02;
regs[0x1d] = 0x02;
regs[0x1e] = 0x09;
regs[0x1f] = 0x07;
} else {
regs[0x1a] = 0x1d;
regs[0x1b] = 0x10;
regs[0x1c] = 0x05;
regs[0x1d] = 0x03;
regs[0x1e] = 0x0f;
regs[0x1f] = 0x0c;
}
for (i = 0; i < 16; i++)
regs[0x20 + i] = i * 16;
regs[0x20 + i] = 255;
switch (sd->sensor) {
case SENSOR_TAS5130CXX:
regs[0x19] = mode ? 0x23 : 0x43;
break;
case SENSOR_OV7630:
if (sd->bridge == BRIDGE_103) {
regs[0x01] = 0x44;
regs[0x12] = 0x02;
}
}
if (cam->cam_mode[gspca_dev->curr_mode].priv & MODE_RAW)
regs[0x18] &= ~0x80;
if (cam->cam_mode[gspca_dev->curr_mode].priv & MODE_REDUCED_SIF) {
regs[0x12] += 16;
regs[0x13] += 24;
regs[0x15] = 320 / 16;
regs[0x16] = 240 / 16;
}
reg_w(gspca_dev, 0x01, &regs[0x01], 1);
reg_w(gspca_dev, 0x17, &regs[0x17], 1);
reg_w(gspca_dev, 0x01, &regs[0x01],
(sd->bridge == BRIDGE_103) ? 0x30 : 0x1f);
i2c_w_vector(gspca_dev, sensor_data[sd->sensor].sensor_init,
sensor_data[sd->sensor].sensor_init_size);
switch (sd->sensor) {
case SENSOR_PAS202: {
const __u8 i2cpclockdiv[] =
{0xa0, 0x40, 0x02, 0x03, 0x00, 0x00, 0x00, 0x10};
if (mode)
i2c_w(gspca_dev, i2cpclockdiv);
break;
}
case SENSOR_OV7630:
if (sd->bridge == BRIDGE_103) {
const __u8 i2c[] = { 0xa0, 0x21, 0x13,
0x80, 0x00, 0x00, 0x00, 0x10 };
i2c_w(gspca_dev, i2c);
}
break;
}
reg_w(gspca_dev, 0x15, &regs[0x15], 2);
reg_w(gspca_dev, 0x18, &regs[0x18], 1);
reg_w(gspca_dev, 0x12, &regs[0x12], 1);
reg_w(gspca_dev, 0x13, &regs[0x13], 1);
reg_w(gspca_dev, 0x17, &regs[0x17], 1);
reg_w(gspca_dev, 0x19, &regs[0x19], 1);
reg_w(gspca_dev, 0x1c, &regs[0x1c], 4);
reg_w(gspca_dev, 0x01, &regs[0x01], 1);
reg_w(gspca_dev, 0x18, &regs[0x18], 2);
msleep(20);
sd->reg11 = -1;
setgain(gspca_dev);
setbrightness(gspca_dev);
setexposure(gspca_dev);
setfreq(gspca_dev);
sd->frames_to_drop = 0;
sd->autogain_ignore_frames = 0;
gspca_dev->exp_too_high_cnt = 0;
gspca_dev->exp_too_low_cnt = 0;
atomic_set(&sd->avg_lum, -1);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
sd_init(gspca_dev);
}
static u8* find_sof(struct gspca_dev *gspca_dev, u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, header_size = (sd->bridge == BRIDGE_103) ? 18 : 12;
for (i = 0; i < len; i++) {
switch (sd->header_read) {
case 0:
if (data[i] == 0xff)
sd->header_read++;
break;
case 1:
if (data[i] == 0xff)
sd->header_read++;
else
sd->header_read = 0;
break;
case 2:
if (data[i] == 0x00)
sd->header_read++;
else if (data[i] != 0xff)
sd->header_read = 0;
break;
case 3:
if (data[i] == 0xc4)
sd->header_read++;
else if (data[i] == 0xff)
sd->header_read = 1;
else
sd->header_read = 0;
break;
case 4:
if (data[i] == 0xc4)
sd->header_read++;
else if (data[i] == 0xff)
sd->header_read = 1;
else
sd->header_read = 0;
break;
case 5:
if (data[i] == 0x96)
sd->header_read++;
else if (data[i] == 0xff)
sd->header_read = 1;
else
sd->header_read = 0;
break;
default:
sd->header[sd->header_read - 6] = data[i];
sd->header_read++;
if (sd->header_read == header_size) {
sd->header_read = 0;
return data + i + 1;
}
}
}
return NULL;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int fr_h_sz = 0, lum_offset = 0, len_after_sof = 0;
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam = &gspca_dev->cam;
u8 *sof;
sof = find_sof(gspca_dev, data, len);
if (sof) {
if (sd->bridge == BRIDGE_103) {
fr_h_sz = 18;
lum_offset = 3;
} else {
fr_h_sz = 12;
lum_offset = 2;
}
len_after_sof = len - (sof - data);
len = (sof - data) - fr_h_sz;
if (len < 0)
len = 0;
}
if (cam->cam_mode[gspca_dev->curr_mode].priv & MODE_RAW) {
int used;
int size = cam->cam_mode[gspca_dev->curr_mode].sizeimage;
used = gspca_dev->image_len;
if (used + len > size)
len = size - used;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
if (sof) {
int lum = sd->header[lum_offset] +
(sd->header[lum_offset + 1] << 8);
if (lum == 0 && sd->prev_avg_lum != 0) {
lum = -1;
sd->frames_to_drop = 2;
sd->prev_avg_lum = 0;
} else
sd->prev_avg_lum = lum;
atomic_set(&sd->avg_lum, lum);
if (sd->frames_to_drop)
sd->frames_to_drop--;
else
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, sof, len_after_sof);
}
}
static int sd_querymenu(struct gspca_dev *gspca_dev,
struct v4l2_querymenu *menu)
{
switch (menu->id) {
case V4L2_CID_POWER_LINE_FREQUENCY:
switch (menu->index) {
case 0:
strcpy((char *) menu->name, "NoFliker");
return 0;
case 1:
strcpy((char *) menu->name, "50 Hz");
return 0;
case 2:
strcpy((char *) menu->name, "60 Hz");
return 0;
}
break;
}
return -EINVAL;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
if (len == 1 && data[0] == 1) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
return ret;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
