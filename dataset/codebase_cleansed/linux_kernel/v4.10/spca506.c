static void reg_r(struct gspca_dev *gspca_dev,
__u16 req,
__u16 index,
__u16 length)
{
usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, length,
500);
}
static void reg_w(struct usb_device *dev,
__u16 req,
__u16 value,
__u16 index)
{
usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index,
NULL, 0, 500);
}
static void spca506_Initi2c(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev->dev, 0x07, SAA7113_I2C_BASE_WRITE, 0x0004);
}
static void spca506_WriteI2c(struct gspca_dev *gspca_dev, __u16 valeur,
__u16 reg)
{
int retry = 60;
reg_w(gspca_dev->dev, 0x07, reg, 0x0001);
reg_w(gspca_dev->dev, 0x07, valeur, 0x0000);
while (retry--) {
reg_r(gspca_dev, 0x07, 0x0003, 2);
if ((gspca_dev->usb_buf[0] | gspca_dev->usb_buf[1]) == 0x00)
break;
}
}
static void spca506_SetNormeInput(struct gspca_dev *gspca_dev,
__u16 norme,
__u16 channel)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 setbit0 = 0x00;
__u8 setbit1 = 0x00;
__u8 videomask = 0x00;
PDEBUG(D_STREAM, "** Open Set Norme **");
spca506_Initi2c(gspca_dev);
if (norme & V4L2_STD_NTSC)
setbit0 = 0x01;
if (channel == 4 || channel == 5 || channel > 9)
channel = 0;
if (channel < 4)
setbit1 = 0x02;
videomask = (0x48 | setbit0 | setbit1);
reg_w(gspca_dev->dev, 0x08, videomask, 0x0000);
spca506_WriteI2c(gspca_dev, (0xc0 | (channel & 0x0F)), 0x02);
if (norme & V4L2_STD_NTSC)
spca506_WriteI2c(gspca_dev, 0x33, 0x0e);
else if (norme & V4L2_STD_SECAM)
spca506_WriteI2c(gspca_dev, 0x53, 0x0e);
else
spca506_WriteI2c(gspca_dev, 0x03, 0x0e);
sd->norme = norme;
sd->channel = channel;
PDEBUG(D_STREAM, "Set Video Byte to 0x%2x", videomask);
PDEBUG(D_STREAM, "Set Norme: %08x Channel %d", norme, channel);
}
static void spca506_GetNormeInput(struct gspca_dev *gspca_dev,
__u16 *norme, __u16 *channel)
{
struct sd *sd = (struct sd *) gspca_dev;
*norme = sd->norme;
*channel = sd->channel;
PDEBUG(D_STREAM, "Get Norme: %d Channel %d", *norme, *channel);
}
static void spca506_Setsize(struct gspca_dev *gspca_dev, __u16 code,
__u16 xmult, __u16 ymult)
{
struct usb_device *dev = gspca_dev->dev;
PDEBUG(D_STREAM, "** SetSize **");
reg_w(dev, 0x04, (0x18 | (code & 0x07)), 0x0000);
reg_w(dev, 0x04, 0x41, 0x0001);
reg_w(dev, 0x04, 0x00, 0x0002);
reg_w(dev, 0x04, 0x00, 0x0003);
reg_w(dev, 0x04, 0x00, 0x0004);
reg_w(dev, 0x04, 0x01, 0x0005);
reg_w(dev, 0x04, xmult, 0x0006);
reg_w(dev, 0x04, ymult, 0x0007);
reg_w(dev, 0x04, 0x00, 0x0008);
reg_w(dev, 0x04, 0x00, 0x0009);
reg_w(dev, 0x04, 0x21, 0x000a);
reg_w(dev, 0x04, 0x00, 0x000b);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0xFF, 0x0003);
reg_w(dev, 0x03, 0x00, 0x0000);
reg_w(dev, 0x03, 0x1c, 0x0001);
reg_w(dev, 0x03, 0x18, 0x0001);
spca506_SetNormeInput(gspca_dev, 0, 0);
reg_w(dev, 0x03, 0x1c, 0x0001);
reg_w(dev, 0x03, 0x18, 0x0001);
reg_w(dev, 0x05, 0x00, 0x0000);
reg_w(dev, 0x05, 0xef, 0x0001);
reg_w(dev, 0x05, 0x00, 0x00c1);
reg_w(dev, 0x05, 0x00, 0x00c2);
reg_w(dev, 0x06, 0x18, 0x0002);
reg_w(dev, 0x06, 0xf5, 0x0011);
reg_w(dev, 0x06, 0x02, 0x0012);
reg_w(dev, 0x06, 0xfb, 0x0013);
reg_w(dev, 0x06, 0x00, 0x0014);
reg_w(dev, 0x06, 0xa4, 0x0051);
reg_w(dev, 0x06, 0x40, 0x0052);
reg_w(dev, 0x06, 0x71, 0x0053);
reg_w(dev, 0x06, 0x40, 0x0054);
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0x00, 0x0003);
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0xFF, 0x0003);
reg_w(dev, 0x02, 0x00, 0x0000);
reg_w(dev, 0x03, 0x60, 0x0000);
reg_w(dev, 0x03, 0x18, 0x0001);
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, 0x08, 0x01);
spca506_WriteI2c(gspca_dev, 0xc0, 0x02);
spca506_WriteI2c(gspca_dev, 0x33, 0x03);
spca506_WriteI2c(gspca_dev, 0x00, 0x04);
spca506_WriteI2c(gspca_dev, 0x00, 0x05);
spca506_WriteI2c(gspca_dev, 0x0d, 0x06);
spca506_WriteI2c(gspca_dev, 0xf0, 0x07);
spca506_WriteI2c(gspca_dev, 0x98, 0x08);
spca506_WriteI2c(gspca_dev, 0x03, 0x09);
spca506_WriteI2c(gspca_dev, 0x80, 0x0a);
spca506_WriteI2c(gspca_dev, 0x47, 0x0b);
spca506_WriteI2c(gspca_dev, 0x48, 0x0c);
spca506_WriteI2c(gspca_dev, 0x00, 0x0d);
spca506_WriteI2c(gspca_dev, 0x03, 0x0e);
spca506_WriteI2c(gspca_dev, 0x2a, 0x0f);
spca506_WriteI2c(gspca_dev, 0x00, 0x10);
spca506_WriteI2c(gspca_dev, 0x0c, 0x11);
spca506_WriteI2c(gspca_dev, 0xb8, 0x12);
spca506_WriteI2c(gspca_dev, 0x01, 0x13);
spca506_WriteI2c(gspca_dev, 0x00, 0x14);
spca506_WriteI2c(gspca_dev, 0x00, 0x15);
spca506_WriteI2c(gspca_dev, 0x00, 0x16);
spca506_WriteI2c(gspca_dev, 0x00, 0x17);
spca506_WriteI2c(gspca_dev, 0x00, 0x18);
spca506_WriteI2c(gspca_dev, 0x00, 0x19);
spca506_WriteI2c(gspca_dev, 0x00, 0x1a);
spca506_WriteI2c(gspca_dev, 0x00, 0x1b);
spca506_WriteI2c(gspca_dev, 0x00, 0x1c);
spca506_WriteI2c(gspca_dev, 0x00, 0x1d);
spca506_WriteI2c(gspca_dev, 0x00, 0x1e);
spca506_WriteI2c(gspca_dev, 0xa1, 0x1f);
spca506_WriteI2c(gspca_dev, 0x02, 0x40);
spca506_WriteI2c(gspca_dev, 0xff, 0x41);
spca506_WriteI2c(gspca_dev, 0xff, 0x42);
spca506_WriteI2c(gspca_dev, 0xff, 0x43);
spca506_WriteI2c(gspca_dev, 0xff, 0x44);
spca506_WriteI2c(gspca_dev, 0xff, 0x45);
spca506_WriteI2c(gspca_dev, 0xff, 0x46);
spca506_WriteI2c(gspca_dev, 0xff, 0x47);
spca506_WriteI2c(gspca_dev, 0xff, 0x48);
spca506_WriteI2c(gspca_dev, 0xff, 0x49);
spca506_WriteI2c(gspca_dev, 0xff, 0x4a);
spca506_WriteI2c(gspca_dev, 0xff, 0x4b);
spca506_WriteI2c(gspca_dev, 0xff, 0x4c);
spca506_WriteI2c(gspca_dev, 0xff, 0x4d);
spca506_WriteI2c(gspca_dev, 0xff, 0x4e);
spca506_WriteI2c(gspca_dev, 0xff, 0x4f);
spca506_WriteI2c(gspca_dev, 0xff, 0x50);
spca506_WriteI2c(gspca_dev, 0xff, 0x51);
spca506_WriteI2c(gspca_dev, 0xff, 0x52);
spca506_WriteI2c(gspca_dev, 0xff, 0x53);
spca506_WriteI2c(gspca_dev, 0xff, 0x54);
spca506_WriteI2c(gspca_dev, 0xff, 0x55);
spca506_WriteI2c(gspca_dev, 0xff, 0x56);
spca506_WriteI2c(gspca_dev, 0xff, 0x57);
spca506_WriteI2c(gspca_dev, 0x00, 0x58);
spca506_WriteI2c(gspca_dev, 0x54, 0x59);
spca506_WriteI2c(gspca_dev, 0x07, 0x5a);
spca506_WriteI2c(gspca_dev, 0x83, 0x5b);
spca506_WriteI2c(gspca_dev, 0x00, 0x5c);
spca506_WriteI2c(gspca_dev, 0x00, 0x5d);
spca506_WriteI2c(gspca_dev, 0x00, 0x5e);
spca506_WriteI2c(gspca_dev, 0x00, 0x5f);
spca506_WriteI2c(gspca_dev, 0x00, 0x60);
spca506_WriteI2c(gspca_dev, 0x05, 0x61);
spca506_WriteI2c(gspca_dev, 0x9f, 0x62);
PDEBUG(D_STREAM, "** Close Init *");
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
__u16 norme;
__u16 channel;
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0x00, 0x0003);
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0xFF, 0x0003);
reg_w(dev, 0x02, 0x00, 0x0000);
reg_w(dev, 0x03, 0x60, 0x0000);
reg_w(dev, 0x03, 0x18, 0x0001);
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, 0x08, 0x01);
spca506_WriteI2c(gspca_dev, 0x33, 0x03);
spca506_WriteI2c(gspca_dev, 0x00, 0x04);
spca506_WriteI2c(gspca_dev, 0x00, 0x05);
spca506_WriteI2c(gspca_dev, 0x0d, 0x06);
spca506_WriteI2c(gspca_dev, 0xf0, 0x07);
spca506_WriteI2c(gspca_dev, 0x98, 0x08);
spca506_WriteI2c(gspca_dev, 0x03, 0x09);
spca506_WriteI2c(gspca_dev, 0x80, 0x0a);
spca506_WriteI2c(gspca_dev, 0x47, 0x0b);
spca506_WriteI2c(gspca_dev, 0x48, 0x0c);
spca506_WriteI2c(gspca_dev, 0x00, 0x0d);
spca506_WriteI2c(gspca_dev, 0x2a, 0x0f);
spca506_WriteI2c(gspca_dev, 0x00, 0x10);
spca506_WriteI2c(gspca_dev, 0x0c, 0x11);
spca506_WriteI2c(gspca_dev, 0xb8, 0x12);
spca506_WriteI2c(gspca_dev, 0x01, 0x13);
spca506_WriteI2c(gspca_dev, 0x00, 0x14);
spca506_WriteI2c(gspca_dev, 0x00, 0x15);
spca506_WriteI2c(gspca_dev, 0x00, 0x16);
spca506_WriteI2c(gspca_dev, 0x00, 0x17);
spca506_WriteI2c(gspca_dev, 0x00, 0x18);
spca506_WriteI2c(gspca_dev, 0x00, 0x19);
spca506_WriteI2c(gspca_dev, 0x00, 0x1a);
spca506_WriteI2c(gspca_dev, 0x00, 0x1b);
spca506_WriteI2c(gspca_dev, 0x00, 0x1c);
spca506_WriteI2c(gspca_dev, 0x00, 0x1d);
spca506_WriteI2c(gspca_dev, 0x00, 0x1e);
spca506_WriteI2c(gspca_dev, 0xa1, 0x1f);
spca506_WriteI2c(gspca_dev, 0x02, 0x40);
spca506_WriteI2c(gspca_dev, 0xff, 0x41);
spca506_WriteI2c(gspca_dev, 0xff, 0x42);
spca506_WriteI2c(gspca_dev, 0xff, 0x43);
spca506_WriteI2c(gspca_dev, 0xff, 0x44);
spca506_WriteI2c(gspca_dev, 0xff, 0x45);
spca506_WriteI2c(gspca_dev, 0xff, 0x46);
spca506_WriteI2c(gspca_dev, 0xff, 0x47);
spca506_WriteI2c(gspca_dev, 0xff, 0x48);
spca506_WriteI2c(gspca_dev, 0xff, 0x49);
spca506_WriteI2c(gspca_dev, 0xff, 0x4a);
spca506_WriteI2c(gspca_dev, 0xff, 0x4b);
spca506_WriteI2c(gspca_dev, 0xff, 0x4c);
spca506_WriteI2c(gspca_dev, 0xff, 0x4d);
spca506_WriteI2c(gspca_dev, 0xff, 0x4e);
spca506_WriteI2c(gspca_dev, 0xff, 0x4f);
spca506_WriteI2c(gspca_dev, 0xff, 0x50);
spca506_WriteI2c(gspca_dev, 0xff, 0x51);
spca506_WriteI2c(gspca_dev, 0xff, 0x52);
spca506_WriteI2c(gspca_dev, 0xff, 0x53);
spca506_WriteI2c(gspca_dev, 0xff, 0x54);
spca506_WriteI2c(gspca_dev, 0xff, 0x55);
spca506_WriteI2c(gspca_dev, 0xff, 0x56);
spca506_WriteI2c(gspca_dev, 0xff, 0x57);
spca506_WriteI2c(gspca_dev, 0x00, 0x58);
spca506_WriteI2c(gspca_dev, 0x54, 0x59);
spca506_WriteI2c(gspca_dev, 0x07, 0x5a);
spca506_WriteI2c(gspca_dev, 0x83, 0x5b);
spca506_WriteI2c(gspca_dev, 0x00, 0x5c);
spca506_WriteI2c(gspca_dev, 0x00, 0x5d);
spca506_WriteI2c(gspca_dev, 0x00, 0x5e);
spca506_WriteI2c(gspca_dev, 0x00, 0x5f);
spca506_WriteI2c(gspca_dev, 0x00, 0x60);
spca506_WriteI2c(gspca_dev, 0x05, 0x61);
spca506_WriteI2c(gspca_dev, 0x9f, 0x62);
reg_w(dev, 0x05, 0x00, 0x0003);
reg_w(dev, 0x05, 0x00, 0x0004);
reg_w(dev, 0x03, 0x10, 0x0001);
reg_w(dev, 0x03, 0x78, 0x0000);
switch (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
case 0:
spca506_Setsize(gspca_dev, 0, 0x10, 0x10);
break;
case 1:
spca506_Setsize(gspca_dev, 1, 0x1a, 0x1a);
break;
case 2:
spca506_Setsize(gspca_dev, 2, 0x1c, 0x1c);
break;
case 4:
spca506_Setsize(gspca_dev, 4, 0x34, 0x34);
break;
default:
spca506_Setsize(gspca_dev, 5, 0x40, 0x40);
break;
}
reg_w(dev, 0x02, 0x01, 0x0000);
reg_w(dev, 0x03, 0x12, 0x0000);
reg_r(gspca_dev, 0x04, 0x0001, 2);
PDEBUG(D_STREAM, "webcam started");
spca506_GetNormeInput(gspca_dev, &norme, &channel);
spca506_SetNormeInput(gspca_dev, norme, channel);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
reg_w(dev, 0x02, 0x00, 0x0000);
reg_w(dev, 0x03, 0x00, 0x0004);
reg_w(dev, 0x03, 0x00, 0x0003);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
switch (data[0]) {
case 0:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
data += SPCA50X_OFFSET_DATA;
len -= SPCA50X_OFFSET_DATA;
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
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, val, SAA7113_bright);
spca506_WriteI2c(gspca_dev, 0x01, 0x09);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, val, SAA7113_contrast);
spca506_WriteI2c(gspca_dev, 0x01, 0x09);
}
static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, val, SAA7113_saturation);
spca506_WriteI2c(gspca_dev, 0x01, 0x09);
}
static void sethue(struct gspca_dev *gspca_dev, s32 val)
{
spca506_Initi2c(gspca_dev);
spca506_WriteI2c(gspca_dev, val, SAA7113_hue);
spca506_WriteI2c(gspca_dev, 0x01, 0x09);
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
setcolors(gspca_dev, ctrl->val);
break;
case V4L2_CID_HUE:
sethue(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 0x47);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 0x40);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, 0, 255, 1, 0);
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
