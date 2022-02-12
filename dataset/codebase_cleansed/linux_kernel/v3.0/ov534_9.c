static void reg_w_i(struct gspca_dev *gspca_dev, u16 reg, u8 val)
{
struct usb_device *udev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
gspca_dev->usb_buf[0] = val;
ret = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00, reg, gspca_dev->usb_buf, 1, CTRL_TIMEOUT);
if (ret < 0) {
err("reg_w failed %d", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev, u16 reg, u8 val)
{
PDEBUG(D_USBO, "reg_w [%04x] = %02x", reg, val);
reg_w_i(gspca_dev, reg, val);
}
static u8 reg_r(struct gspca_dev *gspca_dev, u16 reg)
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
PDEBUG(D_USBI, "reg_r [%04x] -> %02x", reg, gspca_dev->usb_buf[0]);
if (ret < 0) {
err("reg_r err %d", ret);
gspca_dev->usb_err = ret;
}
return gspca_dev->usb_buf[0];
}
static int sccb_check_status(struct gspca_dev *gspca_dev)
{
u8 data;
int i;
for (i = 0; i < 5; i++) {
data = reg_r(gspca_dev, OV534_REG_STATUS);
switch (data) {
case 0x00:
return 1;
case 0x04:
return 0;
case 0x03:
break;
default:
PDEBUG(D_USBI|D_USBO,
"sccb status 0x%02x, attempt %d/5",
data, i + 1);
}
}
return 0;
}
static void sccb_write(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
PDEBUG(D_USBO, "sccb_write [%02x] = %02x", reg, val);
reg_w_i(gspca_dev, OV534_REG_SUBADDR, reg);
reg_w_i(gspca_dev, OV534_REG_WRITE, val);
reg_w_i(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_3);
if (!sccb_check_status(gspca_dev))
err("sccb_write failed");
}
static u8 sccb_read(struct gspca_dev *gspca_dev, u16 reg)
{
reg_w(gspca_dev, OV534_REG_SUBADDR, reg);
reg_w(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_2);
if (!sccb_check_status(gspca_dev))
err("sccb_read failed 1");
reg_w(gspca_dev, OV534_REG_OPERATION, OV534_OP_READ_2);
if (!sccb_check_status(gspca_dev))
err("sccb_read failed 2");
return reg_r(gspca_dev, OV534_REG_READ);
}
static void set_led(struct gspca_dev *gspca_dev, int status)
{
u8 data;
PDEBUG(D_CONF, "led status: %d", status);
data = reg_r(gspca_dev, 0x21);
data |= 0x80;
reg_w(gspca_dev, 0x21, data);
data = reg_r(gspca_dev, 0x23);
if (status)
data |= 0x80;
else
data &= ~0x80;
reg_w(gspca_dev, 0x23, data);
if (!status) {
data = reg_r(gspca_dev, 0x21);
data &= ~0x80;
reg_w(gspca_dev, 0x21, data);
}
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sd->brightness;
if (val < 8)
val = 15 - val;
else
val = val - 8;
sccb_write(gspca_dev, 0x55,
0x0f | (val << 4));
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sccb_write(gspca_dev, 0x56,
sd->contrast << 4);
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
if (sd->autogain)
val |= 0x05;
else
val &= 0xfa;
sccb_write(gspca_dev, 0x13, val);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
static const u8 expo[4] = {0x00, 0x25, 0x38, 0x5e};
sccb_write(gspca_dev, 0x10,
expo[sd->exposure]);
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0x13, val);
val = sccb_read(gspca_dev, 0xa1);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0xa1, val & 0xe0);
}
static void setsharpness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
s8 val;
val = sd->sharpness;
if (val < 0) {
val = sccb_read(gspca_dev, 0x42);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0x42, val | 0x40);
return;
}
if (val != 0)
val = 1 << (val - 1);
sccb_write(gspca_dev, 0x3f,
val);
val = sccb_read(gspca_dev, 0x42);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0x42, val & 0xbf);
}
static void setsatur(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val1, val2, val3;
static const u8 matrix[5][2] = {
{0x14, 0x38},
{0x1e, 0x54},
{0x28, 0x70},
{0x32, 0x8c},
{0x48, 0x90}
};
val1 = matrix[sd->satur][0];
val2 = matrix[sd->satur][1];
val3 = val1 + val2;
sccb_write(gspca_dev, 0x4f, val3);
sccb_write(gspca_dev, 0x50, val3);
sccb_write(gspca_dev, 0x51, 0x00);
sccb_write(gspca_dev, 0x52, val1);
sccb_write(gspca_dev, 0x53, val2);
sccb_write(gspca_dev, 0x54, val3);
sccb_write(gspca_dev, 0x58, 0x1a);
val1 = sccb_read(gspca_dev, 0x41);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0x41, val1);
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
if (sd->freq == 0) {
sccb_write(gspca_dev, 0x13, val & 0xdf);
return;
}
sccb_write(gspca_dev, 0x13, val | 0x20);
val = sccb_read(gspca_dev, 0x42);
sccb_write(gspca_dev, 0xff, 0x00);
if (sd->freq == 1)
val |= 0x01;
else
val &= 0xfe;
sccb_write(gspca_dev, 0x42, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = ov965x_mode;
cam->nmodes = ARRAY_SIZE(ov965x_mode);
sd->brightness = BRIGHTNESS_DEF;
sd->contrast = CONTRAST_DEF;
#if AUTOGAIN_DEF != 0
sd->autogain = AUTOGAIN_DEF;
gspca_dev->ctrl_inac |= (1 << EXPO_IDX);
#endif
#if EXPO_DEF != 0
sd->exposure = EXPO_DEF;
#endif
#if SHARPNESS_DEF != 0
sd->sharpness = SHARPNESS_DEF;
#endif
sd->satur = SATUR_DEF;
sd->freq = FREQ_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
u16 sensor_id;
reg_w(gspca_dev, 0xe7, 0x3a);
reg_w(gspca_dev, 0xe0, 0x08);
msleep(100);
reg_w(gspca_dev, OV534_REG_ADDRESS, 0x60);
sccb_write(gspca_dev, 0x12, 0x80);
msleep(10);
sccb_read(gspca_dev, 0x0a);
sensor_id = sccb_read(gspca_dev, 0x0a) << 8;
sccb_read(gspca_dev, 0x0b);
sensor_id |= sccb_read(gspca_dev, 0x0b);
PDEBUG(D_PROBE, "Sensor ID: %04x", sensor_id);
reg_w_array(gspca_dev, bridge_init,
ARRAY_SIZE(bridge_init));
sccb_w_array(gspca_dev, sensor_init,
ARRAY_SIZE(sensor_init));
reg_w_array(gspca_dev, bridge_init_2,
ARRAY_SIZE(bridge_init_2));
sccb_w_array(gspca_dev, sensor_init_2,
ARRAY_SIZE(sensor_init_2));
reg_w(gspca_dev, 0xe0, 0x00);
reg_w(gspca_dev, 0xe0, 0x01);
set_led(gspca_dev, 0);
reg_w(gspca_dev, 0xe0, 0x00);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
switch (gspca_dev->curr_mode) {
case QVGA_MODE:
sccb_w_array(gspca_dev, sensor_start_1_vga,
ARRAY_SIZE(sensor_start_1_vga));
reg_w_array(gspca_dev, bridge_start_qvga,
ARRAY_SIZE(bridge_start_qvga));
sccb_w_array(gspca_dev, sensor_start_2_qvga,
ARRAY_SIZE(sensor_start_2_qvga));
break;
case VGA_MODE:
sccb_w_array(gspca_dev, sensor_start_1_vga,
ARRAY_SIZE(sensor_start_1_vga));
reg_w_array(gspca_dev, bridge_start_vga,
ARRAY_SIZE(bridge_start_vga));
sccb_w_array(gspca_dev, sensor_start_2_vga,
ARRAY_SIZE(sensor_start_2_vga));
break;
case SVGA_MODE:
sccb_w_array(gspca_dev, sensor_start_1_svga,
ARRAY_SIZE(sensor_start_1_svga));
reg_w_array(gspca_dev, bridge_start_svga,
ARRAY_SIZE(bridge_start_svga));
sccb_w_array(gspca_dev, sensor_start_2_svga,
ARRAY_SIZE(sensor_start_2_svga));
break;
case XGA_MODE:
sccb_w_array(gspca_dev, sensor_start_1_xga,
ARRAY_SIZE(sensor_start_1_xga));
reg_w_array(gspca_dev, bridge_start_xga,
ARRAY_SIZE(bridge_start_xga));
sccb_w_array(gspca_dev, sensor_start_2_svga,
ARRAY_SIZE(sensor_start_2_svga));
break;
default:
sccb_w_array(gspca_dev, sensor_start_1_sxga,
ARRAY_SIZE(sensor_start_1_sxga));
reg_w_array(gspca_dev, bridge_start_sxga,
ARRAY_SIZE(bridge_start_sxga));
sccb_w_array(gspca_dev, sensor_start_2_sxga,
ARRAY_SIZE(sensor_start_2_sxga));
break;
}
setfreq(gspca_dev);
setautogain(gspca_dev);
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setexposure(gspca_dev);
setsharpness(gspca_dev);
setsatur(gspca_dev);
reg_w(gspca_dev, 0xe0, 0x00);
reg_w(gspca_dev, 0xe0, 0x00);
set_led(gspca_dev, 1);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0xe0, 0x01);
set_led(gspca_dev, 0);
reg_w(gspca_dev, 0xe0, 0x00);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
__u32 this_pts;
u8 this_fid;
int remaining_len = len;
do {
len = min(remaining_len, 2040);
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
this_fid = data[1] & UVC_STREAM_FID;
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
static int sd_setbrightness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->brightness = val;
if (gspca_dev->streaming)
setbrightness(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getbrightness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->brightness;
return 0;
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
setcontrast(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return 0;
}
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->autogain = val;
if (gspca_dev->streaming) {
if (val)
gspca_dev->ctrl_inac |= (1 << EXPO_IDX);
else
gspca_dev->ctrl_inac &= ~(1 << EXPO_IDX);
setautogain(gspca_dev);
}
return gspca_dev->usb_err;
}
static int sd_getautogain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->autogain;
return 0;
}
static int sd_setexposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setsharpness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->sharpness = val;
if (gspca_dev->streaming)
setsharpness(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getsharpness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->sharpness;
return 0;
}
static int sd_setsatur(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->satur = val;
if (gspca_dev->streaming)
setsatur(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getsatur(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->satur;
return 0;
}
static int sd_setfreq(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->freq = val;
if (gspca_dev->streaming)
setfreq(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getfreq(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->freq;
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
