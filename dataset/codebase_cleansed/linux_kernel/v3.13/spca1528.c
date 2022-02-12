static void reg_r(struct gspca_dev *gspca_dev,
u8 req,
u16 index,
int len)
{
#if USB_BUF_SZ < 64
#error "USB buffer too small"
#endif
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x0000,
index,
gspca_dev->usb_buf, len,
500);
PDEBUG(D_USBI, "GET %02x 0000 %04x %02x", req, index,
gspca_dev->usb_buf[0]);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
u8 req,
u16 value,
u16 index)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "SET %02x %04x %04x", req, value, index);
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index,
NULL, 0, 500);
if (ret < 0) {
pr_err("reg_w err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_wb(struct gspca_dev *gspca_dev,
u8 req,
u16 value,
u16 index,
u8 byte)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "SET %02x %04x %04x %02x", req, value, index, byte);
gspca_dev->usb_buf[0] = byte;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index,
gspca_dev->usb_buf, 1, 500);
if (ret < 0) {
pr_err("reg_w err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void wait_status_0(struct gspca_dev *gspca_dev)
{
int i, w;
i = 16;
w = 0;
do {
reg_r(gspca_dev, 0x21, 0x0000, 1);
if (gspca_dev->usb_buf[0] == 0)
return;
w += 15;
msleep(w);
} while (--i > 0);
PERR("wait_status_0 timeout");
gspca_dev->usb_err = -ETIME;
}
static void wait_status_1(struct gspca_dev *gspca_dev)
{
int i;
i = 10;
do {
reg_r(gspca_dev, 0x21, 0x0001, 1);
msleep(10);
if (gspca_dev->usb_buf[0] == 1) {
reg_wb(gspca_dev, 0x21, 0x0000, 0x0001, 0x00);
reg_r(gspca_dev, 0x21, 0x0001, 1);
return;
}
} while (--i > 0);
PERR("wait_status_1 timeout");
gspca_dev->usb_err = -ETIME;
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
reg_wb(gspca_dev, 0xc0, 0x0000, 0x00c0, val);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
reg_wb(gspca_dev, 0xc1, 0x0000, 0x00c1, val);
}
static void sethue(struct gspca_dev *gspca_dev, s32 val)
{
reg_wb(gspca_dev, 0xc2, 0x0000, 0x0000, val);
}
static void setcolor(struct gspca_dev *gspca_dev, s32 val)
{
reg_wb(gspca_dev, 0xc3, 0x0000, 0x00c3, val);
}
static void setsharpness(struct gspca_dev *gspca_dev, s32 val)
{
reg_wb(gspca_dev, 0xc4, 0x0000, 0x00c4, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
gspca_dev->cam.cam_mode = vga_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(vga_mode);
gspca_dev->cam.npkt = 128;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0x00, 0x0001, 0x2067);
reg_w(gspca_dev, 0x00, 0x00d0, 0x206b);
reg_w(gspca_dev, 0x00, 0x0000, 0x206c);
reg_w(gspca_dev, 0x00, 0x0001, 0x2069);
msleep(8);
reg_w(gspca_dev, 0x00, 0x00c0, 0x206b);
reg_w(gspca_dev, 0x00, 0x0000, 0x206c);
reg_w(gspca_dev, 0x00, 0x0001, 0x2069);
reg_r(gspca_dev, 0x20, 0x0000, 1);
reg_r(gspca_dev, 0x20, 0x0000, 5);
reg_r(gspca_dev, 0x23, 0x0000, 64);
PDEBUG(D_PROBE, "%s%s", &gspca_dev->usb_buf[0x1c],
&gspca_dev->usb_buf[0x30]);
reg_r(gspca_dev, 0x23, 0x0001, 64);
return gspca_dev->usb_err;
}
static int sd_isoc_init(struct gspca_dev *gspca_dev)
{
u8 mode;
reg_r(gspca_dev, 0x00, 0x2520, 1);
wait_status_0(gspca_dev);
reg_w(gspca_dev, 0xc5, 0x0003, 0x0000);
wait_status_1(gspca_dev);
wait_status_0(gspca_dev);
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
reg_wb(gspca_dev, 0x25, 0x0000, 0x0004, mode);
reg_r(gspca_dev, 0x25, 0x0004, 1);
reg_wb(gspca_dev, 0x27, 0x0000, 0x0000, 0x06);
reg_r(gspca_dev, 0x27, 0x0000, 1);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
jpeg_define(sd->jpeg_hdr, gspca_dev->pixfmt.height,
gspca_dev->pixfmt.width,
0x22);
jpeg_set_qual(sd->jpeg_hdr, 85);
reg_r(gspca_dev, 0x00, 0x2520, 1);
msleep(8);
wait_status_0(gspca_dev);
reg_w(gspca_dev, 0x31, 0x0000, 0x0004);
wait_status_1(gspca_dev);
wait_status_0(gspca_dev);
msleep(200);
sd->pkt_seq = 0;
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
wait_status_0(gspca_dev);
reg_w(gspca_dev, 0x31, 0x0000, 0x0000);
wait_status_1(gspca_dev);
wait_status_0(gspca_dev);
}
static void add_packet(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int i;
i = 0;
do {
if (data[i] == 0xff) {
gspca_frame_add(gspca_dev, INTER_PACKET,
data, i + 1);
len -= i;
data += i;
*data = 0x00;
i = 0;
}
} while (++i < len);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
static const u8 ffd9[] = {0xff, 0xd9};
if (len < 3)
return;
if (*data == 0x02) {
if (data[1] & 0x02) {
sd->pkt_seq = !(data[1] & 1);
add_packet(gspca_dev, data + 2, len - 2);
gspca_frame_add(gspca_dev, LAST_PACKET,
ffd9, 2);
return;
}
if ((data[1] & 1) != sd->pkt_seq)
goto err;
if (gspca_dev->last_packet_type == LAST_PACKET)
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
add_packet(gspca_dev, data + 2, len - 2);
return;
}
err:
gspca_dev->last_packet_type = DISCARD_PACKET;
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
case V4L2_CID_HUE:
sethue(gspca_dev, ctrl->val);
break;
case V4L2_CID_SATURATION:
setcolor(gspca_dev, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
setsharpness(gspca_dev, ctrl->val);
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
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 8, 1, 1);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, 0, 255, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 8, 1, 1);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 255, 1, 0);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (intf->cur_altsetting->desc.bInterfaceNumber != 1)
return -ENODEV;
return gspca_dev_probe2(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
