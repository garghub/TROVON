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
pr_err("reg_w failed %d\n", ret);
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
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
}
return gspca_dev->usb_buf[0];
}
static int sccb_check_status(struct gspca_dev *gspca_dev)
{
u8 data;
int i;
for (i = 0; i < 5; i++) {
msleep(10);
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
pr_err("sccb_write failed\n");
}
static u8 sccb_read(struct gspca_dev *gspca_dev, u16 reg)
{
reg_w(gspca_dev, OV534_REG_SUBADDR, reg);
reg_w(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_2);
if (!sccb_check_status(gspca_dev))
pr_err("sccb_read failed 1\n");
reg_w(gspca_dev, OV534_REG_OPERATION, OV534_OP_READ_2);
if (!sccb_check_status(gspca_dev))
pr_err("sccb_read failed 2\n");
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
static void setbrightness(struct gspca_dev *gspca_dev, s32 brightness)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
s8 sval;
if (sd->sensor == SENSOR_OV562x) {
sval = brightness;
val = 0x76;
val += sval;
sccb_write(gspca_dev, 0x24, val);
val = 0x6a;
val += sval;
sccb_write(gspca_dev, 0x25, val);
if (sval < -40)
val = 0x71;
else if (sval < 20)
val = 0x94;
else
val = 0xe6;
sccb_write(gspca_dev, 0x26, val);
} else {
val = brightness;
if (val < 8)
val = 15 - val;
else
val = val - 8;
sccb_write(gspca_dev, 0x55,
0x0f | (val << 4));
}
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
sccb_write(gspca_dev, 0x56,
val << 4);
}
static void setautogain(struct gspca_dev *gspca_dev, s32 autogain)
{
u8 val;
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
if (autogain)
val |= 0x05;
else
val &= 0xfa;
sccb_write(gspca_dev, 0x13, val);
}
static void setexposure(struct gspca_dev *gspca_dev, s32 exposure)
{
static const u8 expo[4] = {0x00, 0x25, 0x38, 0x5e};
u8 val;
sccb_write(gspca_dev, 0x10, expo[exposure]);
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0x13, val);
val = sccb_read(gspca_dev, 0xa1);
sccb_write(gspca_dev, 0xff, 0x00);
sccb_write(gspca_dev, 0xa1, val & 0xe0);
}
static void setsharpness(struct gspca_dev *gspca_dev, s32 val)
{
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
static void setsatur(struct gspca_dev *gspca_dev, s32 val)
{
u8 val1, val2, val3;
static const u8 matrix[5][2] = {
{0x14, 0x38},
{0x1e, 0x54},
{0x28, 0x70},
{0x32, 0x8c},
{0x48, 0x90}
};
val1 = matrix[val][0];
val2 = matrix[val][1];
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
static void setlightfreq(struct gspca_dev *gspca_dev, s32 freq)
{
u8 val;
val = sccb_read(gspca_dev, 0x13);
sccb_write(gspca_dev, 0xff, 0x00);
if (freq == 0) {
sccb_write(gspca_dev, 0x13, val & 0xdf);
return;
}
sccb_write(gspca_dev, 0x13, val | 0x20);
val = sccb_read(gspca_dev, 0x42);
sccb_write(gspca_dev, 0xff, 0x00);
if (freq == 1)
val |= 0x01;
else
val &= 0xfe;
sccb_write(gspca_dev, 0x42, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
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
if ((sensor_id & 0xfff0) == 0x9650) {
sd->sensor = SENSOR_OV965x;
gspca_dev->cam.cam_mode = ov965x_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(ov965x_mode);
reg_w_array(gspca_dev, bridge_init,
ARRAY_SIZE(bridge_init));
sccb_w_array(gspca_dev, ov965x_init,
ARRAY_SIZE(ov965x_init));
reg_w_array(gspca_dev, bridge_init_2,
ARRAY_SIZE(bridge_init_2));
sccb_w_array(gspca_dev, ov965x_init_2,
ARRAY_SIZE(ov965x_init_2));
reg_w(gspca_dev, 0xe0, 0x00);
reg_w(gspca_dev, 0xe0, 0x01);
set_led(gspca_dev, 0);
reg_w(gspca_dev, 0xe0, 0x00);
} else if ((sensor_id & 0xfff0) == 0x9710) {
const char *p;
int l;
sd->sensor = SENSOR_OV971x;
gspca_dev->cam.cam_mode = ov971x_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(ov971x_mode);
gspca_dev->cam.bulk = 1;
gspca_dev->cam.bulk_size = 16384;
gspca_dev->cam.bulk_nurbs = 2;
sccb_w_array(gspca_dev, ov971x_init,
ARRAY_SIZE(ov971x_init));
reg_w(gspca_dev, 0x1c, 0x00);
reg_w(gspca_dev, 0x1d, 0x00);
p = video_device_node_name(&gspca_dev->vdev);
l = strlen(p) - 1;
if (p[l] == '0')
reg_w(gspca_dev, 0x56, 0x1f);
else
reg_w(gspca_dev, 0x56, 0x17);
} else if ((sensor_id & 0xfff0) == 0x5620) {
sd->sensor = SENSOR_OV562x;
gspca_dev->cam.cam_mode = ov562x_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(ov562x_mode);
reg_w_array(gspca_dev, ov562x_init,
ARRAY_SIZE(ov562x_init));
sccb_w_array(gspca_dev, ov562x_init_2,
ARRAY_SIZE(ov562x_init_2));
reg_w(gspca_dev, 0xe0, 0x00);
} else {
pr_err("Unknown sensor %04x", sensor_id);
return -EINVAL;
}
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_OV971x)
return gspca_dev->usb_err;
if (sd->sensor == SENSOR_OV562x)
return gspca_dev->usb_err;
switch (gspca_dev->curr_mode) {
case QVGA_MODE:
sccb_w_array(gspca_dev, ov965x_start_1_vga,
ARRAY_SIZE(ov965x_start_1_vga));
reg_w_array(gspca_dev, bridge_start_qvga,
ARRAY_SIZE(bridge_start_qvga));
sccb_w_array(gspca_dev, ov965x_start_2_qvga,
ARRAY_SIZE(ov965x_start_2_qvga));
break;
case VGA_MODE:
sccb_w_array(gspca_dev, ov965x_start_1_vga,
ARRAY_SIZE(ov965x_start_1_vga));
reg_w_array(gspca_dev, bridge_start_vga,
ARRAY_SIZE(bridge_start_vga));
sccb_w_array(gspca_dev, ov965x_start_2_vga,
ARRAY_SIZE(ov965x_start_2_vga));
break;
case SVGA_MODE:
sccb_w_array(gspca_dev, ov965x_start_1_svga,
ARRAY_SIZE(ov965x_start_1_svga));
reg_w_array(gspca_dev, bridge_start_svga,
ARRAY_SIZE(bridge_start_svga));
sccb_w_array(gspca_dev, ov965x_start_2_svga,
ARRAY_SIZE(ov965x_start_2_svga));
break;
case XGA_MODE:
sccb_w_array(gspca_dev, ov965x_start_1_xga,
ARRAY_SIZE(ov965x_start_1_xga));
reg_w_array(gspca_dev, bridge_start_xga,
ARRAY_SIZE(bridge_start_xga));
sccb_w_array(gspca_dev, ov965x_start_2_svga,
ARRAY_SIZE(ov965x_start_2_svga));
break;
default:
sccb_w_array(gspca_dev, ov965x_start_1_sxga,
ARRAY_SIZE(ov965x_start_1_sxga));
reg_w_array(gspca_dev, bridge_start_sxga,
ARRAY_SIZE(bridge_start_sxga));
sccb_w_array(gspca_dev, ov965x_start_2_sxga,
ARRAY_SIZE(ov965x_start_2_sxga));
break;
}
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
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
setbrightness(gspca_dev, ctrl->val);
break;
case V4L2_CID_CONTRAST:
setcontrast(gspca_dev, ctrl->val);
break;
case V4L2_CID_SATURATION:
setsatur(gspca_dev, ctrl->val);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
setlightfreq(gspca_dev, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
setsharpness(gspca_dev, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
if (ctrl->is_new)
setautogain(gspca_dev, ctrl->val);
if (!ctrl->val && gspca_dev->exposure->is_new)
setexposure(gspca_dev, gspca_dev->exposure->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
if (sd->sensor == SENSOR_OV971x)
return 0;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 7);
if (sd->sensor == SENSOR_OV562x) {
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, -90, 90, 1, 0);
} else {
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 15, 1, 7);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 15, 1, 3);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 4, 1, 2);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, -1, 4, 1, -1);
gspca_dev->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 3, 1, 0);
v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 0, 0);
v4l2_ctrl_auto_cluster(3, &gspca_dev->autogain, 0, false);
}
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
