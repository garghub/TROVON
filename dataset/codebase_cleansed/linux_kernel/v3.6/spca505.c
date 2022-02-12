static int reg_write(struct usb_device *dev,
u16 req, u16 index, u16 value)
{
int ret;
ret = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
req,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
PDEBUG(D_USBO, "reg write: 0x%02x,0x%02x:0x%02x, %d",
req, index, value, ret);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
return ret;
}
static int reg_read(struct gspca_dev *gspca_dev,
u16 req,
u16 index)
{
int ret;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index,
gspca_dev->usb_buf, 2,
500);
if (ret < 0)
return ret;
return (gspca_dev->usb_buf[1] << 8) + gspca_dev->usb_buf[0];
}
static int write_vector(struct gspca_dev *gspca_dev,
const u8 data[][3])
{
struct usb_device *dev = gspca_dev->dev;
int ret, i = 0;
while (data[i][0] != 0) {
ret = reg_write(dev, data[i][0], data[i][2], data[i][1]);
if (ret < 0)
return ret;
i++;
}
return 0;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
sd->subtype = id->driver_info;
if (sd->subtype != IntelPCCameraPro)
cam->nmodes = ARRAY_SIZE(vga_mode);
else
cam->nmodes = ARRAY_SIZE(vga_mode) - 1;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (write_vector(gspca_dev,
sd->subtype == Nxultra
? spca505b_init_data
: spca505_init_data))
return -EIO;
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 brightness)
{
reg_write(gspca_dev->dev, 0x05, 0x00, (255 - brightness) >> 6);
reg_write(gspca_dev->dev, 0x05, 0x01, (255 - brightness) << 2);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
int ret, mode;
static u8 mode_tb[][3] = {
{0x00, 0x10, 0x10},
{0x01, 0x1a, 0x1a},
{0x02, 0x1c, 0x1d},
{0x04, 0x34, 0x34},
{0x05, 0x40, 0x40}
};
if (sd->subtype == Nxultra)
write_vector(gspca_dev, spca505b_open_data_ccd);
else
write_vector(gspca_dev, spca505_open_data_ccd);
ret = reg_read(gspca_dev, 0x06, 0x16);
if (ret < 0) {
PDEBUG(D_ERR|D_CONF,
"register read failed err: %d",
ret);
return ret;
}
if (ret != 0x0101) {
pr_err("After vector read returns 0x%04x should be 0x0101\n",
ret);
}
ret = reg_write(gspca_dev->dev, 0x06, 0x16, 0x0a);
if (ret < 0)
return ret;
reg_write(gspca_dev->dev, 0x05, 0xc2, 0x12);
reg_write(dev, 0x02, 0x00, 0x00);
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
reg_write(dev, SPCA50X_REG_COMPRESS, 0x00, mode_tb[mode][0]);
reg_write(dev, SPCA50X_REG_COMPRESS, 0x06, mode_tb[mode][1]);
reg_write(dev, SPCA50X_REG_COMPRESS, 0x07, mode_tb[mode][2]);
return reg_write(dev, SPCA50X_REG_USB,
SPCA50X_USB_CTRL,
SPCA50X_CUSB_ENABLE);
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_write(gspca_dev->dev, 0x02, 0x00, 0x00);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
if (!gspca_dev->present)
return;
reg_write(gspca_dev->dev, 0x03, 0x03, 0x20);
reg_write(gspca_dev->dev, 0x03, 0x01, 0x00);
reg_write(gspca_dev->dev, 0x03, 0x00, 0x01);
reg_write(gspca_dev->dev, 0x05, 0x10, 0x01);
reg_write(gspca_dev->dev, 0x05, 0x11, 0x0f);
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
V4L2_CID_BRIGHTNESS, 0, 255, 1, 127);
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
