static void reg_r(struct gspca_dev *gspca_dev,
__u16 value)
{
usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value,
0,
gspca_dev->usb_buf, 1,
500);
}
static void reg_w(struct gspca_dev *gspca_dev,
__u16 value,
const __u8 *buffer,
int len)
{
#ifdef GSPCA_DEBUG
if (len > USB_BUF_SZ) {
PDEBUG(D_ERR|D_PACK, "reg_w: buffer overflow");
return;
}
#endif
memcpy(gspca_dev->usb_buf, buffer, len);
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value,
0,
gspca_dev->usb_buf, len,
500);
}
static int i2c_w(struct gspca_dev *gspca_dev, const __u8 *buffer)
{
int retry = 60;
reg_w(gspca_dev, 0x08, buffer, 8);
while (retry--) {
msleep(10);
reg_r(gspca_dev, 0x08);
if (gspca_dev->usb_buf[0] & 0x04) {
if (gspca_dev->usb_buf[0] & 0x08)
return -1;
return 0;
}
}
return -1;
}
static void i2c_w_vector(struct gspca_dev *gspca_dev,
const __u8 buffer[][8], int len)
{
for (;;) {
reg_w(gspca_dev, 0x08, *buffer, 8);
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
i2cOV[3] = sd->ctrls[BRIGHTNESS].val;
if (i2c_w(gspca_dev, i2cOV) < 0)
goto err;
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
if (sd->ctrls[BRIGHTNESS].val < 127) {
i2cpbright[3] = 0x01;
i2cpbright[4] = 127 - sd->ctrls[BRIGHTNESS].val;
} else
i2cpbright[4] = sd->ctrls[BRIGHTNESS].val - 127;
if (i2c_w(gspca_dev, i2cpbright) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpdoit) < 0)
goto err;
break;
}
}
return;
err:
PDEBUG(D_ERR, "i2c error brightness");
}
static void setsensorgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gain = sd->ctrls[GAIN].val;
switch (sd->sensor) {
case SENSOR_HV7131D: {
__u8 i2c[] =
{0xc0, 0x11, 0x31, 0x00, 0x00, 0x00, 0x00, 0x17};
i2c[3] = 0x3f - (gain / 4);
i2c[4] = 0x3f - (gain / 4);
i2c[5] = 0x3f - (gain / 4);
if (i2c_w(gspca_dev, i2c) < 0)
goto err;
break;
}
case SENSOR_TAS5110C:
case SENSOR_TAS5130CXX: {
__u8 i2c[] =
{0x30, 0x11, 0x02, 0x20, 0x70, 0x00, 0x00, 0x10};
i2c[4] = 255 - gain;
if (i2c_w(gspca_dev, i2c) < 0)
goto err;
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
if (i2c_w(gspca_dev, i2c) < 0)
goto err;
break;
}
case SENSOR_OV6650:
gain >>= 1;
case SENSOR_OV7630: {
__u8 i2c[] = {0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10};
i2c[1] = sensor_data[sd->sensor].sensor_addr;
i2c[3] = gain >> 2;
if (i2c_w(gspca_dev, i2c) < 0)
goto err;
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
i2cpgain[3] = gain >> 3;
i2cpcolorgain[3] = gain >> 4;
i2cpcolorgain[4] = gain >> 4;
i2cpcolorgain[5] = gain >> 4;
i2cpcolorgain[6] = gain >> 4;
if (i2c_w(gspca_dev, i2cpgain) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpcolorgain) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpdoit) < 0)
goto err;
break;
}
}
return;
err:
PDEBUG(D_ERR, "i2c error gain");
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 gain;
__u8 buf[3] = { 0, 0, 0 };
if (sensor_data[sd->sensor].flags & F_GAIN) {
setsensorgain(gspca_dev);
return;
}
if (sd->bridge == BRIDGE_103) {
gain = sd->ctrls[GAIN].val >> 1;
buf[0] = gain;
buf[1] = gain;
buf[2] = gain;
reg_w(gspca_dev, 0x05, buf, 3);
} else {
gain = sd->ctrls[GAIN].val >> 4;
buf[0] = gain << 4 | gain;
buf[1] = gain;
reg_w(gspca_dev, 0x10, buf, 2);
}
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_HV7131D: {
__u8 i2c[] = {0xc0, 0x11, 0x25, 0x00, 0x00, 0x00, 0x00, 0x17};
u16 reg = sd->ctrls[EXPOSURE].val * 6;
i2c[3] = reg >> 8;
i2c[4] = reg & 0xff;
if (i2c_w(gspca_dev, i2c) != 0)
goto err;
break;
}
case SENSOR_TAS5110C:
case SENSOR_TAS5110D: {
u8 reg = sd->ctrls[EXPOSURE].val;
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
reg11 = (15 * sd->ctrls[EXPOSURE].val + 999) / 1000;
if (reg11 < 1)
reg11 = 1;
else if (reg11 > 16)
reg11 = 16;
if (gspca_dev->width == 640 && reg11 < 4)
reg11 = 4;
reg10 = (sd->ctrls[EXPOSURE].val * 15 * reg10_max)
/ (1000 * reg11);
if (sd->ctrls[AUTOGAIN].val && reg10 < 10)
reg10 = 10;
else if (reg10 > reg10_max)
reg10 = reg10_max;
i2c[1] = sensor_data[sd->sensor].sensor_addr;
i2c[3] = reg10;
i2c[4] |= reg11 - 1;
if (sd->reg11 == reg11)
i2c[0] = 0xa0;
if (i2c_w(gspca_dev, i2c) == 0)
sd->reg11 = reg11;
else
goto err;
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
if (sd->ctrls[EXPOSURE].val < 200) {
i2cpexpo[3] = 255 - (sd->ctrls[EXPOSURE].val * 255)
/ 200;
framerate_ctrl = 500;
} else {
framerate_ctrl = (sd->ctrls[EXPOSURE].val - 200)
* 1000 / 229 + 500;
}
i2cpframerate[3] = framerate_ctrl >> 6;
i2cpframerate[4] = framerate_ctrl & 0x3f;
if (i2c_w(gspca_dev, i2cpframerate) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpexpo) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpdoit) < 0)
goto err;
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
if (sd->ctrls[EXPOSURE].val < 150) {
i2cpexpo[3] = 150 - sd->ctrls[EXPOSURE].val;
framerate_ctrl = 300;
} else {
framerate_ctrl = (sd->ctrls[EXPOSURE].val - 150)
* 1000 / 230 + 300;
}
i2cpframerate[3] = framerate_ctrl >> 4;
i2cpframerate[4] = framerate_ctrl & 0x0f;
if (i2c_w(gspca_dev, i2cpframerate) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpexpo) < 0)
goto err;
if (i2c_w(gspca_dev, i2cpdoit) < 0)
goto err;
break;
}
}
return;
err:
PDEBUG(D_ERR, "i2c error exposure");
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_OV6650:
case SENSOR_OV7630: {
__u8 i2c[] = {0xa0, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x10};
switch (sd->ctrls[FREQ].val) {
default:
i2c[3] = 0;
break;
case 1:
i2c[3] = (sd->sensor == SENSOR_OV6650)
? 0x4f : 0x8a;
break;
}
i2c[1] = sensor_data[sd->sensor].sensor_addr;
if (i2c_w(gspca_dev, i2c) < 0)
PDEBUG(D_ERR, "i2c error setfreq");
break;
}
}
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
int deadzone, desired_avg_lum, result;
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum = atomic_read(&sd->avg_lum);
if ((gspca_dev->ctrl_dis & (1 << AUTOGAIN)) ||
avg_lum == -1 || !sd->ctrls[AUTOGAIN].val)
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
if (sensor_data[sd->sensor].flags & F_COARSE_EXPO)
result = coarse_grained_expo_autogain(gspca_dev, avg_lum,
sd->ctrls[BRIGHTNESS].val
* desired_avg_lum / 127,
deadzone);
else
result = auto_gain_n_exposure(gspca_dev, avg_lum,
sd->ctrls[BRIGHTNESS].val
* desired_avg_lum / 127,
deadzone, GAIN_KNEE, EXPOSURE_KNEE);
if (result) {
PDEBUG(D_FRAM, "autogain: gain changed: gain: %d expo: %d",
(int) sd->ctrls[GAIN].val,
(int) sd->ctrls[EXPOSURE].val);
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
gspca_dev->ctrl_dis = sensor_data[sd->sensor].ctrl_dis;
#if AUTOGAIN_DEF
if (!(gspca_dev->ctrl_dis & (1 << AUTOGAIN)))
gspca_dev->ctrl_inac = (1 << GAIN) | (1 << EXPOSURE);
#endif
cam = &gspca_dev->cam;
cam->ctrls = sd->ctrls;
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
struct sd *sd = (struct sd *) gspca_dev;
const __u8 stop = 0x09;
if (sensor_data[sd->sensor].flags & F_COARSE_EXPO) {
sd->ctrls[EXPOSURE].min = COARSE_EXPOSURE_MIN;
sd->ctrls[EXPOSURE].max = COARSE_EXPOSURE_MAX;
sd->ctrls[EXPOSURE].def = COARSE_EXPOSURE_DEF;
if (sd->ctrls[EXPOSURE].val > COARSE_EXPOSURE_MAX)
sd->ctrls[EXPOSURE].val = COARSE_EXPOSURE_DEF;
}
reg_w(gspca_dev, 0x01, &stop, 1);
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
sd->exp_too_high_cnt = 0;
sd->exp_too_low_cnt = 0;
atomic_set(&sd->avg_lum, -1);
return 0;
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
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->ctrls[AUTOGAIN].val = val;
sd->exp_too_high_cnt = 0;
sd->exp_too_low_cnt = 0;
if (sd->ctrls[AUTOGAIN].val
&& !(sensor_data[sd->sensor].flags & F_COARSE_EXPO)) {
sd->ctrls[EXPOSURE].val = sd->ctrls[EXPOSURE].def;
sd->ctrls[GAIN].val = sd->ctrls[GAIN].def;
if (gspca_dev->streaming) {
sd->autogain_ignore_frames = AUTOGAIN_IGNORE_FRAMES;
setexposure(gspca_dev);
setgain(gspca_dev);
}
}
if (sd->ctrls[AUTOGAIN].val)
gspca_dev->ctrl_inac = (1 << GAIN) | (1 << EXPOSURE);
else
gspca_dev->ctrl_inac = 0;
return 0;
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
