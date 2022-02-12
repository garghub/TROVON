static void reg_rw(struct gspca_dev *gspca_dev,
u8 bRequestType, u8 bRequest,
u16 wValue, u16 wIndex, u16 wLength)
{
struct usb_device *udev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
bRequest,
bRequestType,
wValue, wIndex,
gspca_dev->usb_buf, wLength, 500);
if (ret < 0) {
gspca_dev->usb_err = ret;
pr_err("usb_control_msg error %d\n", ret);
}
return;
}
static int reg_reqs(struct gspca_dev *gspca_dev,
const struct dtcs033_usb_requests *preqs, int n_reqs)
{
int i = 0;
const struct dtcs033_usb_requests *preq;
while ((i < n_reqs) && (gspca_dev->usb_err >= 0)) {
preq = &preqs[i];
reg_rw(gspca_dev, preq->bRequestType, preq->bRequest,
preq->wValue, preq->wIndex, preq->wLength);
if (gspca_dev->usb_err < 0) {
PERR("usb error request no: %d / %d\n",
i, n_reqs);
} else if (preq->bRequestType & USB_DIR_IN) {
PDEBUG(D_STREAM,
"USB IN (%d) returned[%d] %02X %02X %02X %s",
i,
preq->wLength,
gspca_dev->usb_buf[0],
gspca_dev->usb_buf[1],
gspca_dev->usb_buf[2],
preq->wLength > 3 ? "...\n" : "\n");
}
i++;
}
return gspca_dev->usb_err;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
gspca_dev->cam.cam_mode = dtcs033_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(dtcs033_mode);
gspca_dev->cam.bulk = 1;
gspca_dev->cam.bulk_nurbs = 1;
gspca_dev->cam.bulk_size = DT_COLS*512;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static void dtcs033_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
if (len != DT_COLS*512) {
gspca_dev->last_packet_type = DISCARD_PACKET;
return;
}
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, INTER_PACKET,
data + 16*DT_COLS,
len - 32*DT_COLS);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
return;
}
static void dtcs033_setexposure(struct gspca_dev *gspca_dev,
s32 expo, s32 gain)
{
u16 sGain = (u16)gain;
u16 gainVal = 224+(sGain-14)*(768-224)/(33-14);
u16 wIndex = 0x0100|(0x00FF&gainVal);
u16 wValue = (0xFF00&gainVal)>>8;
u16 sXTime = (u16)expo;
u16 xtimeVal = (524*(150-(sXTime-1)))/150;
const u8 bRequestType =
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
const u8 bRequest = 0x18;
reg_rw(gspca_dev,
bRequestType, bRequest, wValue, wIndex, 0);
if (gspca_dev->usb_err < 0)
PERR("usb error in setexposure(gain) sequence.\n");
reg_rw(gspca_dev,
bRequestType, bRequest, (xtimeVal<<4), 0x6300, 0);
if (gspca_dev->usb_err < 0)
PERR("usb error in setexposure(time) sequence.\n");
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler,
struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
dtcs033_setexposure(gspca_dev,
ctrl->val, sd->gain->val);
break;
case V4L2_CID_GAIN:
dtcs033_setexposure(gspca_dev,
sd->exposure->val, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int dtcs033_init_controls(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 2);
sd->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE,
1, 150, 1, 75);
sd->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN,
14, 33, 1, 24);
if (hdl->error) {
PERR("Could not initialize controls: %d\n",
hdl->error);
return hdl->error;
}
v4l2_ctrl_cluster(2, &sd->exposure);
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
&sd_desc, sizeof(struct sd),
THIS_MODULE);
}
static int dtcs033_start(struct gspca_dev *gspca_dev)
{
return reg_reqs(gspca_dev, dtcs033_start_reqs,
ARRAY_SIZE(dtcs033_start_reqs));
}
static void dtcs033_stopN(struct gspca_dev *gspca_dev)
{
reg_reqs(gspca_dev, dtcs033_stop_reqs,
ARRAY_SIZE(dtcs033_stop_reqs));
return;
}
