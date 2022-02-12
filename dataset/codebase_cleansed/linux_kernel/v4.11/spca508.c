static int reg_write(struct gspca_dev *gspca_dev, u16 index, u16 value)
{
int ret;
struct usb_device *dev = gspca_dev->dev;
ret = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
0,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
PDEBUG(D_USBO, "reg write i:0x%04x = 0x%02x",
index, value);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
return ret;
}
static int reg_read(struct gspca_dev *gspca_dev,
u16 index)
{
int ret;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index,
gspca_dev->usb_buf, 1,
500);
PDEBUG(D_USBI, "reg read i:%04x --> %02x",
index, gspca_dev->usb_buf[0]);
if (ret < 0) {
pr_err("reg_read err %d\n", ret);
return ret;
}
return gspca_dev->usb_buf[0];
}
static int ssi_w(struct gspca_dev *gspca_dev,
u16 reg, u16 val)
{
int ret, retry;
ret = reg_write(gspca_dev, 0x8802, reg >> 8);
if (ret < 0)
goto out;
ret = reg_write(gspca_dev, 0x8801, reg & 0x00ff);
if (ret < 0)
goto out;
if ((reg & 0xff00) == 0x1000) {
ret = reg_write(gspca_dev, 0x8805, val & 0x00ff);
if (ret < 0)
goto out;
val >>= 8;
}
ret = reg_write(gspca_dev, 0x8800, val);
if (ret < 0)
goto out;
retry = 10;
for (;;) {
ret = reg_read(gspca_dev, 0x8803);
if (ret < 0)
break;
if (gspca_dev->usb_buf[0] == 0)
break;
if (--retry <= 0) {
PERR("ssi_w busy %02x", gspca_dev->usb_buf[0]);
ret = -1;
break;
}
msleep(8);
}
out:
return ret;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
const u16 (*init_data)[2];
static const u16 (*(init_data_tb[]))[2] = {
spca508_vista_init_data,
spca508_sightcam_init_data,
spca508_sightcam2_init_data,
spca508cs110_init_data,
spca508cs110_init_data,
spca508_init_data,
};
int data1, data2;
data1 = reg_read(gspca_dev, 0x8104);
data2 = reg_read(gspca_dev, 0x8105);
PDEBUG(D_PROBE, "Webcam Vendor ID: 0x%02x%02x", data2, data1);
data1 = reg_read(gspca_dev, 0x8106);
data2 = reg_read(gspca_dev, 0x8107);
PDEBUG(D_PROBE, "Webcam Product ID: 0x%02x%02x", data2, data1);
data1 = reg_read(gspca_dev, 0x8621);
PDEBUG(D_PROBE, "Window 1 average luminance: %d", data1);
cam = &gspca_dev->cam;
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
sd->subtype = id->driver_info;
init_data = init_data_tb[sd->subtype];
return write_vector(gspca_dev, init_data);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
int mode;
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
reg_write(gspca_dev, 0x8500, mode);
switch (mode) {
case 0:
case 1:
reg_write(gspca_dev, 0x8700, 0x28);
break;
default:
reg_write(gspca_dev, 0x8700, 0x23);
break;
}
reg_write(gspca_dev, 0x8112, 0x10 | 0x20);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_write(gspca_dev, 0x8112, 0x20);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
switch (data[0]) {
case 0:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
data += SPCA508_OFFSET_DATA;
len -= SPCA508_OFFSET_DATA;
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
break;
case 0xff:
break;
default:
data += 1;
len -= 1;
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
break;
}
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 brightness)
{
reg_write(gspca_dev, 0x8651, brightness);
reg_write(gspca_dev, 0x8652, brightness);
reg_write(gspca_dev, 0x8653, brightness);
reg_write(gspca_dev, 0x8654, brightness);
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
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 5);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
