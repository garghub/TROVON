static int reg_write(struct usb_device *dev,
__u16 req, __u16 index, __u16 value)
{
int ret;
ret = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
req,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
PDEBUG(D_USBO, "reg write: 0x%02x 0x%02x 0x%02x",
req, index, value);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
return ret;
}
static int write_vector(struct gspca_dev *gspca_dev,
const __u16 data[][3])
{
struct usb_device *dev = gspca_dev->dev;
int ret, i = 0;
while (data[i][0] != 0 || data[i][1] != 0 || data[i][2] != 0) {
ret = reg_write(dev, data[i][0], data[i][2], data[i][1]);
if (ret < 0) {
PDEBUG(D_ERR,
"Reg write failed for 0x%02x,0x%02x,0x%02x",
data[i][0], data[i][1], data[i][2]);
return ret;
}
i++;
}
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x12, val);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
reg_write(gspca_dev->dev, 0x00, 0x00,
(val >> 8) & 0xff);
reg_write(gspca_dev->dev, 0x00, 0x01,
val & 0xff);
}
static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x0c, val);
}
static void setblue_balance(struct gspca_dev *gspca_dev, s32 val)
{
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x11, val);
}
static void setred_balance(struct gspca_dev *gspca_dev, s32 val)
{
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x13, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
sd->subtype = id->driver_info;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->subtype) {
case Arowana300KCMOSCamera:
case SmileIntlCamera:
if (write_vector(gspca_dev, spca501c_arowana_init_data))
goto error;
break;
case MystFromOriUnknownCamera:
if (write_vector(gspca_dev, spca501c_mysterious_open_data))
goto error;
break;
default:
if (write_vector(gspca_dev, spca501_init_data))
goto error;
break;
}
PDEBUG(D_STREAM, "Initializing SPCA501 finished");
return 0;
error:
return -EINVAL;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
int mode;
switch (sd->subtype) {
case ThreeComHomeConnectLite:
write_vector(gspca_dev, spca501_3com_open_data);
break;
case Arowana300KCMOSCamera:
case SmileIntlCamera:
write_vector(gspca_dev, spca501c_arowana_open_data);
break;
case MystFromOriUnknownCamera:
write_vector(gspca_dev, spca501c_mysterious_init_data);
break;
default:
write_vector(gspca_dev, spca501_open_data);
}
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
reg_write(dev, SPCA50X_REG_USB, 0x6, 0x94);
switch (mode) {
case 0:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x004a);
break;
case 1:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x104a);
break;
default:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x204a);
break;
}
reg_write(dev, SPCA501_REG_CTLRL, 0x01, 0x02);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_write(gspca_dev->dev, SPCA501_REG_CTLRL, 0x01, 0x00);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
if (!gspca_dev->present)
return;
reg_write(gspca_dev->dev, SPCA501_REG_CTLRL, 0x05, 0x00);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
switch (data[0]) {
case 0:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
data += SPCA501_OFFSET_DATA;
len -= SPCA501_OFFSET_DATA;
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
return;
case 0xff:
return;
}
data++;
len--;
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
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
case V4L2_CID_BLUE_BALANCE:
setblue_balance(gspca_dev, ctrl->val);
break;
case V4L2_CID_RED_BALANCE:
setred_balance(gspca_dev, ctrl->val);
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
V4L2_CID_BRIGHTNESS, 0, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 64725, 1, 64725);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 63, 1, 20);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 127, 1, 0);
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
