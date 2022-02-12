static void reg_w(struct gspca_dev *gspca_dev, u16 value, u16 index)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x02,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
NULL,
0,
1000);
if (ret < 0) {
pr_err("reg_w err writing %02x to %02x: %d\n",
value, index, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_r(struct gspca_dev *gspca_dev, u16 value, u16 index)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x03,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
gspca_dev->usb_buf,
2,
1000);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void konica_stream_on(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 1, 0x0b);
}
static void konica_stream_off(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0, 0x0b);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
gspca_dev->cam.cam_mode = vga_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(vga_mode);
gspca_dev->cam.no_urb_create = 1;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
int i;
msleep(6000);
for (i = 0; i < 20; i++) {
reg_r(gspca_dev, 0, 0x10);
if (gspca_dev->usb_buf[0] == 3)
break;
msleep(100);
}
reg_w(gspca_dev, 0, 0x0d);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct urb *urb;
int i, n, packet_size;
struct usb_host_interface *alt;
struct usb_interface *intf;
intf = usb_ifnum_to_if(sd->gspca_dev.dev, sd->gspca_dev.iface);
alt = usb_altnum_to_altsetting(intf, sd->gspca_dev.alt);
if (!alt) {
pr_err("Couldn't get altsetting\n");
return -EIO;
}
packet_size = le16_to_cpu(alt->endpoint[0].desc.wMaxPacketSize);
n = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
reg_w(gspca_dev, n, 0x08);
konica_stream_on(gspca_dev);
if (gspca_dev->usb_err)
return gspca_dev->usb_err;
#if MAX_NURBS < 4
#error "Not enough URBs in the gspca table"
#endif
#define SD_NPKT 32
for (n = 0; n < 4; n++) {
i = n & 1 ? 0 : 1;
packet_size =
le16_to_cpu(alt->endpoint[i].desc.wMaxPacketSize);
urb = usb_alloc_urb(SD_NPKT, GFP_KERNEL);
if (!urb) {
pr_err("usb_alloc_urb failed\n");
return -ENOMEM;
}
gspca_dev->urb[n] = urb;
urb->transfer_buffer = usb_alloc_coherent(gspca_dev->dev,
packet_size * SD_NPKT,
GFP_KERNEL,
&urb->transfer_dma);
if (urb->transfer_buffer == NULL) {
pr_err("usb_buffer_alloc failed\n");
return -ENOMEM;
}
urb->dev = gspca_dev->dev;
urb->context = gspca_dev;
urb->transfer_buffer_length = packet_size * SD_NPKT;
urb->pipe = usb_rcvisocpipe(gspca_dev->dev,
n & 1 ? 0x81 : 0x82);
urb->transfer_flags = URB_ISO_ASAP
| URB_NO_TRANSFER_DMA_MAP;
urb->interval = 1;
urb->complete = sd_isoc_irq;
urb->number_of_packets = SD_NPKT;
for (i = 0; i < SD_NPKT; i++) {
urb->iso_frame_desc[i].length = packet_size;
urb->iso_frame_desc[i].offset = packet_size * i;
}
}
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
konica_stream_off(gspca_dev);
#if IS_ENABLED(CONFIG_INPUT)
if (sd->snapshot_pressed) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
sd->snapshot_pressed = 0;
}
#endif
}
static void sd_isoc_irq(struct urb *urb)
{
struct gspca_dev *gspca_dev = (struct gspca_dev *) urb->context;
struct sd *sd = (struct sd *) gspca_dev;
struct urb *data_urb, *status_urb;
u8 *data;
int i, st;
PDEBUG(D_PACK, "sd isoc irq");
if (!gspca_dev->streaming)
return;
if (urb->status != 0) {
if (urb->status == -ESHUTDOWN)
return;
#ifdef CONFIG_PM
if (gspca_dev->frozen)
return;
#endif
PERR("urb status: %d", urb->status);
st = usb_submit_urb(urb, GFP_ATOMIC);
if (st < 0)
pr_err("resubmit urb error %d\n", st);
return;
}
if (urb->transfer_buffer_length > 32) {
sd->last_data_urb = urb;
return;
}
status_urb = urb;
data_urb = sd->last_data_urb;
sd->last_data_urb = NULL;
if (!data_urb || data_urb->start_frame != status_urb->start_frame) {
PERR("lost sync on frames");
goto resubmit;
}
if (data_urb->number_of_packets != status_urb->number_of_packets) {
PERR("no packets does not match, data: %d, status: %d",
data_urb->number_of_packets,
status_urb->number_of_packets);
goto resubmit;
}
for (i = 0; i < status_urb->number_of_packets; i++) {
if (data_urb->iso_frame_desc[i].status ||
status_urb->iso_frame_desc[i].status) {
PERR("pkt %d data-status %d, status-status %d", i,
data_urb->iso_frame_desc[i].status,
status_urb->iso_frame_desc[i].status);
gspca_dev->last_packet_type = DISCARD_PACKET;
continue;
}
if (status_urb->iso_frame_desc[i].actual_length != 1) {
PERR("bad status packet length %d",
status_urb->iso_frame_desc[i].actual_length);
gspca_dev->last_packet_type = DISCARD_PACKET;
continue;
}
st = *((u8 *)status_urb->transfer_buffer
+ status_urb->iso_frame_desc[i].offset);
data = (u8 *)data_urb->transfer_buffer
+ data_urb->iso_frame_desc[i].offset;
if (st & 0x80) {
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
} else {
#if IS_ENABLED(CONFIG_INPUT)
u8 button_state = st & 0x40 ? 1 : 0;
if (sd->snapshot_pressed != button_state) {
input_report_key(gspca_dev->input_dev,
KEY_CAMERA,
button_state);
input_sync(gspca_dev->input_dev);
sd->snapshot_pressed = button_state;
}
#endif
if (st & 0x01)
continue;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data,
data_urb->iso_frame_desc[i].actual_length);
}
resubmit:
if (data_urb) {
st = usb_submit_urb(data_urb, GFP_ATOMIC);
if (st < 0)
PERR("usb_submit_urb(data_urb) ret %d", st);
}
st = usb_submit_urb(status_urb, GFP_ATOMIC);
if (st < 0)
PERR("usb_submit_urb(status_urb) ret %d\n", st);
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
konica_stream_off(gspca_dev);
reg_w(gspca_dev, ctrl->val, BRIGHTNESS_REG);
konica_stream_on(gspca_dev);
break;
case V4L2_CID_CONTRAST:
konica_stream_off(gspca_dev);
reg_w(gspca_dev, ctrl->val, CONTRAST_REG);
konica_stream_on(gspca_dev);
break;
case V4L2_CID_SATURATION:
konica_stream_off(gspca_dev);
reg_w(gspca_dev, ctrl->val, SATURATION_REG);
konica_stream_on(gspca_dev);
break;
case V4L2_CID_WHITE_BALANCE_TEMPERATURE:
konica_stream_off(gspca_dev);
reg_w(gspca_dev, ctrl->val, WHITEBAL_REG);
konica_stream_on(gspca_dev);
break;
case V4L2_CID_SHARPNESS:
konica_stream_off(gspca_dev);
reg_w(gspca_dev, ctrl->val, SHARPNESS_REG);
konica_stream_on(gspca_dev);
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
V4L2_CID_BRIGHTNESS, 0, 9, 1, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 9, 1, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 9, 1, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_WHITE_BALANCE_TEMPERATURE,
0, 33, 1, 25);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 9, 1, 4);
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
