static void pac207_write_regs(struct gspca_dev *gspca_dev, u16 index,
const u8 *buffer, u16 length)
{
struct usb_device *udev = gspca_dev->dev;
int err;
if (gspca_dev->usb_err < 0)
return;
memcpy(gspca_dev->usb_buf, buffer, length);
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x00, index,
gspca_dev->usb_buf, length, PAC207_CTRL_TIMEOUT);
if (err < 0) {
pr_err("Failed to write registers to index 0x%04X, error %d\n",
index, err);
gspca_dev->usb_err = err;
}
}
static void pac207_write_reg(struct gspca_dev *gspca_dev, u16 index, u16 value)
{
struct usb_device *udev = gspca_dev->dev;
int err;
if (gspca_dev->usb_err < 0)
return;
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x00,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, index, NULL, 0, PAC207_CTRL_TIMEOUT);
if (err) {
pr_err("Failed to write a register (index 0x%04X, value 0x%02X, error %d)\n",
index, value, err);
gspca_dev->usb_err = err;
}
}
static int pac207_read_reg(struct gspca_dev *gspca_dev, u16 index)
{
struct usb_device *udev = gspca_dev->dev;
int res;
if (gspca_dev->usb_err < 0)
return 0;
res = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x00, index,
gspca_dev->usb_buf, 1, PAC207_CTRL_TIMEOUT);
if (res < 0) {
pr_err("Failed to read a register (index 0x%04X, error %d)\n",
index, res);
gspca_dev->usb_err = res;
return 0;
}
return gspca_dev->usb_buf[0];
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam;
u8 idreg[2];
idreg[0] = pac207_read_reg(gspca_dev, 0x0000);
idreg[1] = pac207_read_reg(gspca_dev, 0x0001);
idreg[0] = ((idreg[0] & 0x0f) << 4) | ((idreg[1] & 0xf0) >> 4);
idreg[1] = idreg[1] & 0x0f;
PDEBUG(D_PROBE, "Pixart Sensor ID 0x%02X Chips ID 0x%02X",
idreg[0], idreg[1]);
if (idreg[0] != 0x27) {
PDEBUG(D_PROBE, "Error invalid sensor ID!");
return -ENODEV;
}
PDEBUG(D_PROBE,
"Pixart PAC207BCA Image Processor and Control Chip detected (vid/pid 0x%04X:0x%04X)",
id->idVendor, id->idProduct);
cam = &gspca_dev->cam;
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
u8 mode;
if (led_invert)
mode = 0x02;
else
mode = 0x00;
pac207_write_reg(gspca_dev, 0x41, mode);
pac207_write_reg(gspca_dev, 0x0f, 0x00);
return gspca_dev->usb_err;
}
static void setcontrol(struct gspca_dev *gspca_dev, u16 reg, u16 val)
{
pac207_write_reg(gspca_dev, reg, val);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (ctrl->id == V4L2_CID_AUTOGAIN && ctrl->is_new && ctrl->val) {
gspca_dev->exposure->val = PAC207_EXPOSURE_DEFAULT;
gspca_dev->gain->val = PAC207_GAIN_DEFAULT;
sd->autogain_ignore_frames = PAC_AUTOGAIN_IGNORE_FRAMES;
}
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
setcontrol(gspca_dev, PAC207_BRIGHTNESS_REG, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
if (gspca_dev->exposure->is_new || (ctrl->is_new && ctrl->val))
setcontrol(gspca_dev, PAC207_EXPOSURE_REG,
gspca_dev->exposure->val);
if (gspca_dev->gain->is_new || (ctrl->is_new && ctrl->val))
setcontrol(gspca_dev, PAC207_GAIN_REG,
gspca_dev->gain->val);
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
v4l2_ctrl_handler_init(hdl, 4);
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS,
PAC207_BRIGHTNESS_MIN, PAC207_BRIGHTNESS_MAX,
1, PAC207_BRIGHTNESS_DEFAULT);
gspca_dev->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE,
PAC207_EXPOSURE_MIN, PAC207_EXPOSURE_MAX,
1, PAC207_EXPOSURE_DEFAULT);
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN,
PAC207_GAIN_MIN, PAC207_GAIN_MAX,
1, PAC207_GAIN_DEFAULT);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_auto_cluster(3, &gspca_dev->autogain, 0, false);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 mode;
pac207_write_reg(gspca_dev, 0x0f, 0x10);
pac207_write_regs(gspca_dev, 0x0002, pac207_sensor_init[0], 8);
pac207_write_regs(gspca_dev, 0x000a, pac207_sensor_init[1], 8);
pac207_write_regs(gspca_dev, 0x0012, pac207_sensor_init[2], 8);
pac207_write_regs(gspca_dev, 0x0042, pac207_sensor_init[3], 8);
if (gspca_dev->pixfmt.width == 176)
pac207_write_reg(gspca_dev, 0x4a, 0xff);
else
pac207_write_reg(gspca_dev, 0x4a, 0x30);
pac207_write_reg(gspca_dev, 0x4b, 0x00);
pac207_write_reg(gspca_dev, 0x08, v4l2_ctrl_g_ctrl(sd->brightness));
pac207_write_reg(gspca_dev, 0x0e,
v4l2_ctrl_g_ctrl(gspca_dev->gain));
pac207_write_reg(gspca_dev, 0x02,
v4l2_ctrl_g_ctrl(gspca_dev->exposure));
if (led_invert)
mode = 0x00;
else
mode = 0x02;
if (gspca_dev->pixfmt.width == 176) {
mode |= 0x01;
PDEBUG(D_STREAM, "pac207_start mode 176x144");
} else {
PDEBUG(D_STREAM, "pac207_start mode 352x288");
}
pac207_write_reg(gspca_dev, 0x41, mode);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
msleep(10);
pac207_write_reg(gspca_dev, 0x40, 0x01);
sd->sof_read = 0;
sd->autogain_ignore_frames = 0;
atomic_set(&sd->avg_lum, -1);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
u8 mode;
if (led_invert)
mode = 0x02;
else
mode = 0x00;
pac207_write_reg(gspca_dev, 0x40, 0x00);
pac207_write_reg(gspca_dev, 0x41, mode);
pac207_write_reg(gspca_dev, 0x0f, 0x00);
}
static void pac207_do_auto_gain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum = atomic_read(&sd->avg_lum);
if (avg_lum == -1)
return;
if (sd->autogain_ignore_frames > 0)
sd->autogain_ignore_frames--;
else if (gspca_coarse_grained_expo_autogain(gspca_dev, avg_lum,
90, PAC207_AUTOGAIN_DEADZONE))
sd->autogain_ignore_frames = PAC_AUTOGAIN_IGNORE_FRAMES;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned char *sof;
sof = pac_find_sof(gspca_dev, &sd->sof_read, data, len);
if (sof) {
int n;
n = sof - data;
if (n > sizeof pac_sof_marker)
n -= sizeof pac_sof_marker;
else
n = 0;
gspca_frame_add(gspca_dev, LAST_PACKET,
data, n);
sd->header_read = 0;
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
len -= sof - data;
data = sof;
}
if (sd->header_read < 11) {
int needed;
if (sd->header_read < 5) {
needed = 5 - sd->header_read;
if (len >= needed)
atomic_set(&sd->avg_lum, data[needed - 1]);
}
needed = 11 - sd->header_read;
if (len <= needed) {
sd->header_read += len;
return;
}
data += needed;
len -= needed;
sd->header_read = 11;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
if (len == 2 && data[0] == 0x5a && data[1] == 0x5a) {
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
