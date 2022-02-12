static void ov534_reg_write(struct gspca_dev *gspca_dev, u16 reg, u8 val)
{
struct usb_device *udev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "SET 01 0000 %04x %02x", reg, val);
gspca_dev->usb_buf[0] = val;
ret = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00, reg, gspca_dev->usb_buf, 1, CTRL_TIMEOUT);
if (ret < 0) {
err("write failed %d", ret);
gspca_dev->usb_err = ret;
}
}
static u8 ov534_reg_read(struct gspca_dev *gspca_dev, u16 reg)
{
struct usb_device *udev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return 0;
ret = usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
0x01,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00, reg, gspca_dev->usb_buf, 1, CTRL_TIMEOUT);
PDEBUG(D_USBI, "GET 01 0000 %04x %02x", reg, gspca_dev->usb_buf[0]);
if (ret < 0) {
err("read failed %d", ret);
gspca_dev->usb_err = ret;
}
return gspca_dev->usb_buf[0];
}
static void ov534_set_led(struct gspca_dev *gspca_dev, int status)
{
u8 data;
PDEBUG(D_CONF, "led status: %d", status);
data = ov534_reg_read(gspca_dev, 0x21);
data |= 0x80;
ov534_reg_write(gspca_dev, 0x21, data);
data = ov534_reg_read(gspca_dev, 0x23);
if (status)
data |= 0x80;
else
data &= ~0x80;
ov534_reg_write(gspca_dev, 0x23, data);
if (!status) {
data = ov534_reg_read(gspca_dev, 0x21);
data &= ~0x80;
ov534_reg_write(gspca_dev, 0x21, data);
}
}
static int sccb_check_status(struct gspca_dev *gspca_dev)
{
u8 data;
int i;
for (i = 0; i < 5; i++) {
data = ov534_reg_read(gspca_dev, OV534_REG_STATUS);
switch (data) {
case 0x00:
return 1;
case 0x04:
return 0;
case 0x03:
break;
default:
PDEBUG(D_ERR, "sccb status 0x%02x, attempt %d/5",
data, i + 1);
}
}
return 0;
}
static void sccb_reg_write(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
PDEBUG(D_USBO, "sccb write: %02x %02x", reg, val);
ov534_reg_write(gspca_dev, OV534_REG_SUBADDR, reg);
ov534_reg_write(gspca_dev, OV534_REG_WRITE, val);
ov534_reg_write(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_3);
if (!sccb_check_status(gspca_dev)) {
err("sccb_reg_write failed");
gspca_dev->usb_err = -EIO;
}
}
static u8 sccb_reg_read(struct gspca_dev *gspca_dev, u16 reg)
{
ov534_reg_write(gspca_dev, OV534_REG_SUBADDR, reg);
ov534_reg_write(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_2);
if (!sccb_check_status(gspca_dev))
err("sccb_reg_read failed 1");
ov534_reg_write(gspca_dev, OV534_REG_OPERATION, OV534_OP_READ_2);
if (!sccb_check_status(gspca_dev))
err("sccb_reg_read failed 2");
return ov534_reg_read(gspca_dev, OV534_REG_READ);
}
static void set_frame_rate(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
struct rate_s {
u8 fps;
u8 r11;
u8 r0d;
u8 re5;
};
const struct rate_s *r;
static const struct rate_s rate_0[] = {
{60, 0x01, 0xc1, 0x04},
{50, 0x01, 0x41, 0x02},
{40, 0x02, 0xc1, 0x04},
{30, 0x04, 0x81, 0x02},
{15, 0x03, 0x41, 0x04},
};
static const struct rate_s rate_1[] = {
{125, 0x02, 0x81, 0x02},
{100, 0x02, 0xc1, 0x04},
{75, 0x03, 0xc1, 0x04},
{60, 0x04, 0xc1, 0x04},
{50, 0x02, 0x41, 0x04},
{40, 0x03, 0x41, 0x04},
{30, 0x04, 0x41, 0x04},
};
if (sd->sensor != SENSOR_OV772x)
return;
if (gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv == 0) {
r = rate_0;
i = ARRAY_SIZE(rate_0);
} else {
r = rate_1;
i = ARRAY_SIZE(rate_1);
}
while (--i > 0) {
if (sd->frame_rate >= r->fps)
break;
r++;
}
sccb_reg_write(gspca_dev, 0x11, r->r11);
sccb_reg_write(gspca_dev, 0x0d, r->r0d);
ov534_reg_write(gspca_dev, 0xe5, r->re5);
PDEBUG(D_PROBE, "frame_rate: %d", r->fps);
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int val;
val = sd->ctrls[BRIGHTNESS].val;
if (sd->sensor == SENSOR_OV767x) {
if (val < 0)
val = 0x80 - val;
sccb_reg_write(gspca_dev, 0x55, val);
} else {
sccb_reg_write(gspca_dev, 0x9b, val);
}
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sd->ctrls[CONTRAST].val;
if (sd->sensor == SENSOR_OV767x)
sccb_reg_write(gspca_dev, 0x56, val);
else
sccb_reg_write(gspca_dev, 0x9c, val);
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
if (sd->ctrls[AGC].val)
return;
val = sd->ctrls[GAIN].val;
switch (val & 0x30) {
case 0x00:
val &= 0x0f;
break;
case 0x10:
val &= 0x0f;
val |= 0x30;
break;
case 0x20:
val &= 0x0f;
val |= 0x70;
break;
default:
val &= 0x0f;
val |= 0xf0;
break;
}
sccb_reg_write(gspca_dev, 0x00, val);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
if (sd->ctrls[AEC].val)
return;
val = sd->ctrls[EXPOSURE].val;
if (sd->sensor == SENSOR_OV767x) {
sccb_reg_write(gspca_dev, 0x10, val);
} else {
sccb_reg_write(gspca_dev, 0x08, val >> 7);
sccb_reg_write(gspca_dev, 0x10, val << 1);
}
}
static void setagc(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->ctrls[AGC].val) {
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) | 0x04);
sccb_reg_write(gspca_dev, 0x64,
sccb_reg_read(gspca_dev, 0x64) | 0x03);
} else {
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) & ~0x04);
sccb_reg_write(gspca_dev, 0x64,
sccb_reg_read(gspca_dev, 0x64) & ~0x03);
setgain(gspca_dev);
}
}
static void setawb(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->ctrls[AWB].val) {
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) | 0x02);
if (sd->sensor == SENSOR_OV772x)
sccb_reg_write(gspca_dev, 0x63,
sccb_reg_read(gspca_dev, 0x63) | 0xc0);
} else {
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) & ~0x02);
if (sd->sensor == SENSOR_OV772x)
sccb_reg_write(gspca_dev, 0x63,
sccb_reg_read(gspca_dev, 0x63) & ~0xc0);
}
}
static void setaec(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data;
data = sd->sensor == SENSOR_OV767x ?
0x05 :
0x01;
if (sd->ctrls[AEC].val)
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) | data);
else {
sccb_reg_write(gspca_dev, 0x13,
sccb_reg_read(gspca_dev, 0x13) & ~data);
if (sd->sensor == SENSOR_OV767x)
sd->ctrls[EXPOSURE].val =
sccb_reg_read(gspca_dev, 10);
else
setexposure(gspca_dev);
}
}
static void setsharpness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sd->ctrls[SHARPNESS].val;
sccb_reg_write(gspca_dev, 0x91, val);
sccb_reg_write(gspca_dev, 0x8e, val);
}
static void sethvflip(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
if (sd->sensor == SENSOR_OV767x) {
val = sccb_reg_read(gspca_dev, 0x1e);
val &= ~0x30;
if (sd->ctrls[HFLIP].val)
val |= 0x20;
if (sd->ctrls[VFLIP].val)
val |= 0x10;
sccb_reg_write(gspca_dev, 0x1e, val);
} else {
val = sccb_reg_read(gspca_dev, 0x0c);
val &= ~0xc0;
if (sd->ctrls[HFLIP].val == 0)
val |= 0x40;
if (sd->ctrls[VFLIP].val == 0)
val |= 0x80;
sccb_reg_write(gspca_dev, 0x0c, val);
}
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
int i;
static u8 color_tb[][6] = {
{0x42, 0x42, 0x00, 0x11, 0x30, 0x41},
{0x52, 0x52, 0x00, 0x16, 0x3c, 0x52},
{0x66, 0x66, 0x00, 0x1b, 0x4b, 0x66},
{0x80, 0x80, 0x00, 0x22, 0x5e, 0x80},
{0x9a, 0x9a, 0x00, 0x29, 0x71, 0x9a},
{0xb8, 0xb8, 0x00, 0x31, 0x87, 0xb8},
{0xdd, 0xdd, 0x00, 0x3b, 0xa2, 0xdd},
};
val = sd->ctrls[COLORS].val;
for (i = 0; i < ARRAY_SIZE(color_tb[0]); i++)
sccb_reg_write(gspca_dev, 0x4f + i, color_tb[val][i]);
}
static void setlightfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sd->ctrls[LIGHTFREQ].val ? 0x9e : 0x00;
if (sd->sensor == SENSOR_OV767x) {
sccb_reg_write(gspca_dev, 0x2a, 0x00);
if (val)
val = 0x9d;
}
sccb_reg_write(gspca_dev, 0x2b, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->ctrls = sd->ctrls;
if (sd_ctrls[AGC].qctrl.default_value == 0)
gspca_dev->ctrl_inac |= (1 << AWB);
cam->cam_mode = ov772x_mode;
cam->nmodes = ARRAY_SIZE(ov772x_mode);
sd->frame_rate = 30;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 sensor_id;
static const struct reg_array bridge_init[NSENSORS] = {
[SENSOR_OV767x] = {bridge_init_767x, ARRAY_SIZE(bridge_init_767x)},
[SENSOR_OV772x] = {bridge_init_772x, ARRAY_SIZE(bridge_init_772x)},
};
static const struct reg_array sensor_init[NSENSORS] = {
[SENSOR_OV767x] = {sensor_init_767x, ARRAY_SIZE(sensor_init_767x)},
[SENSOR_OV772x] = {sensor_init_772x, ARRAY_SIZE(sensor_init_772x)},
};
ov534_reg_write(gspca_dev, 0xe7, 0x3a);
ov534_reg_write(gspca_dev, 0xe0, 0x08);
msleep(100);
ov534_reg_write(gspca_dev, OV534_REG_ADDRESS, 0x42);
sccb_reg_write(gspca_dev, 0x12, 0x80);
msleep(10);
sccb_reg_read(gspca_dev, 0x0a);
sensor_id = sccb_reg_read(gspca_dev, 0x0a) << 8;
sccb_reg_read(gspca_dev, 0x0b);
sensor_id |= sccb_reg_read(gspca_dev, 0x0b);
PDEBUG(D_PROBE, "Sensor ID: %04x", sensor_id);
if ((sensor_id & 0xfff0) == 0x7670) {
sd->sensor = SENSOR_OV767x;
gspca_dev->ctrl_dis = (1 << GAIN) |
(1 << AGC) |
(1 << SHARPNESS);
sd->ctrls[BRIGHTNESS].min = -127;
sd->ctrls[BRIGHTNESS].max = 127;
sd->ctrls[BRIGHTNESS].def = 0;
sd->ctrls[CONTRAST].max = 0x80;
sd->ctrls[CONTRAST].def = 0x40;
sd->ctrls[EXPOSURE].min = 0x08;
sd->ctrls[EXPOSURE].max = 0x60;
sd->ctrls[EXPOSURE].def = 0x13;
sd->ctrls[SHARPNESS].max = 9;
sd->ctrls[SHARPNESS].def = 4;
sd->ctrls[HFLIP].def = 1;
gspca_dev->cam.cam_mode = ov767x_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(ov767x_mode);
} else {
sd->sensor = SENSOR_OV772x;
gspca_dev->ctrl_dis = (1 << COLORS);
gspca_dev->cam.bulk = 1;
gspca_dev->cam.bulk_size = 16384;
gspca_dev->cam.bulk_nurbs = 2;
gspca_dev->cam.mode_framerates = ov772x_framerates;
}
reg_w_array(gspca_dev, bridge_init[sd->sensor].val,
bridge_init[sd->sensor].len);
ov534_set_led(gspca_dev, 1);
sccb_w_array(gspca_dev, sensor_init[sd->sensor].val,
sensor_init[sd->sensor].len);
if (sd->sensor == SENSOR_OV767x)
sd_start(gspca_dev);
sd_stopN(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int mode;
static const struct reg_array bridge_start[NSENSORS][2] = {
[SENSOR_OV767x] = {{bridge_start_qvga_767x,
ARRAY_SIZE(bridge_start_qvga_767x)},
{bridge_start_vga_767x,
ARRAY_SIZE(bridge_start_vga_767x)}},
[SENSOR_OV772x] = {{bridge_start_qvga_772x,
ARRAY_SIZE(bridge_start_qvga_772x)},
{bridge_start_vga_772x,
ARRAY_SIZE(bridge_start_vga_772x)}},
};
static const struct reg_array sensor_start[NSENSORS][2] = {
[SENSOR_OV767x] = {{sensor_start_qvga_767x,
ARRAY_SIZE(sensor_start_qvga_767x)},
{sensor_start_vga_767x,
ARRAY_SIZE(sensor_start_vga_767x)}},
[SENSOR_OV772x] = {{sensor_start_qvga_772x,
ARRAY_SIZE(sensor_start_qvga_772x)},
{sensor_start_vga_772x,
ARRAY_SIZE(sensor_start_vga_772x)}},
};
if (sd->sensor == SENSOR_OV767x)
sccb_reg_write(gspca_dev, 0x1e, 0x04);
mode = gspca_dev->curr_mode;
reg_w_array(gspca_dev, bridge_start[sd->sensor][mode].val,
bridge_start[sd->sensor][mode].len);
sccb_w_array(gspca_dev, sensor_start[sd->sensor][mode].val,
sensor_start[sd->sensor][mode].len);
set_frame_rate(gspca_dev);
if (!(gspca_dev->ctrl_dis & (1 << AGC)))
setagc(gspca_dev);
setawb(gspca_dev);
setaec(gspca_dev);
if (!(gspca_dev->ctrl_dis & (1 << GAIN)))
setgain(gspca_dev);
setexposure(gspca_dev);
setbrightness(gspca_dev);
setcontrast(gspca_dev);
if (!(gspca_dev->ctrl_dis & (1 << SHARPNESS)))
setsharpness(gspca_dev);
sethvflip(gspca_dev);
if (!(gspca_dev->ctrl_dis & (1 << COLORS)))
setcolors(gspca_dev);
setlightfreq(gspca_dev);
ov534_set_led(gspca_dev, 1);
ov534_reg_write(gspca_dev, 0xe0, 0x00);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
ov534_reg_write(gspca_dev, 0xe0, 0x09);
ov534_set_led(gspca_dev, 0);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
__u32 this_pts;
u16 this_fid;
int remaining_len = len;
int payload_len;
payload_len = gspca_dev->cam.bulk ? 2048 : 2040;
do {
len = min(remaining_len, payload_len);
if (data[0] != 12 || len < 12) {
PDEBUG(D_PACK, "bad header");
goto discard;
}
if (data[1] & UVC_STREAM_ERR) {
PDEBUG(D_PACK, "payload error");
goto discard;
}
if (!(data[1] & UVC_STREAM_PTS)) {
PDEBUG(D_PACK, "PTS not present");
goto discard;
}
this_pts = (data[5] << 24) | (data[4] << 16)
| (data[3] << 8) | data[2];
this_fid = (data[1] & UVC_STREAM_FID) ? 1 : 0;
if (this_pts != sd->last_pts || this_fid != sd->last_fid) {
if (gspca_dev->last_packet_type == INTER_PACKET)
gspca_frame_add(gspca_dev, LAST_PACKET,
NULL, 0);
sd->last_pts = this_pts;
sd->last_fid = this_fid;
gspca_frame_add(gspca_dev, FIRST_PACKET,
data + 12, len - 12);
} else if (data[1] & UVC_STREAM_EOF) {
sd->last_pts = 0;
if (gspca_dev->pixfmt == V4L2_PIX_FMT_YUYV
&& gspca_dev->image_len + len - 12 !=
gspca_dev->width * gspca_dev->height * 2) {
PDEBUG(D_PACK, "wrong sized frame");
goto discard;
}
gspca_frame_add(gspca_dev, LAST_PACKET,
data + 12, len - 12);
} else {
gspca_frame_add(gspca_dev, INTER_PACKET,
data + 12, len - 12);
}
goto scan_next;
discard:
gspca_dev->last_packet_type = DISCARD_PACKET;
scan_next:
remaining_len -= len;
data += len;
} while (remaining_len > 0);
}
static int sd_setagc(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->ctrls[AGC].val = val;
if (val) {
gspca_dev->ctrl_inac &= ~(1 << AWB);
} else {
gspca_dev->ctrl_inac |= (1 << AWB);
if (sd->ctrls[AWB].val) {
sd->ctrls[AWB].val = 0;
if (gspca_dev->streaming)
setawb(gspca_dev);
}
}
if (gspca_dev->streaming)
setagc(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_querymenu(struct gspca_dev *gspca_dev,
struct v4l2_querymenu *menu)
{
switch (menu->id) {
case V4L2_CID_POWER_LINE_FREQUENCY:
switch (menu->index) {
case 0:
strcpy((char *) menu->name, "Disabled");
return 0;
case 1:
strcpy((char *) menu->name, "50 Hz");
return 0;
}
break;
}
return -EINVAL;
}
static void sd_get_streamparm(struct gspca_dev *gspca_dev,
struct v4l2_streamparm *parm)
{
struct v4l2_captureparm *cp = &parm->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
struct sd *sd = (struct sd *) gspca_dev;
cp->capability |= V4L2_CAP_TIMEPERFRAME;
tpf->numerator = 1;
tpf->denominator = sd->frame_rate;
}
static void sd_set_streamparm(struct gspca_dev *gspca_dev,
struct v4l2_streamparm *parm)
{
struct v4l2_captureparm *cp = &parm->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
struct sd *sd = (struct sd *) gspca_dev;
sd->frame_rate = tpf->denominator / tpf->numerator;
if (gspca_dev->streaming)
set_frame_rate(gspca_dev);
tpf->numerator = 1;
tpf->denominator = sd->frame_rate;
}
static int sd_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
static int __init sd_mod_init(void)
{
return usb_register(&sd_driver);
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
