static int stv_sndctrl(struct gspca_dev *gspca_dev, int set, u8 req, u16 val,
int size)
{
int ret = -1;
u8 req_type = 0;
unsigned int pipe = 0;
switch (set) {
case 0:
req_type = USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_ENDPOINT;
pipe = usb_rcvctrlpipe(gspca_dev->dev, 0);
break;
case 1:
req_type = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_ENDPOINT;
pipe = usb_sndctrlpipe(gspca_dev->dev, 0);
break;
case 2:
req_type = USB_DIR_IN | USB_RECIP_DEVICE;
pipe = usb_rcvctrlpipe(gspca_dev->dev, 0);
break;
case 3:
req_type = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
pipe = usb_sndctrlpipe(gspca_dev->dev, 0);
break;
}
ret = usb_control_msg(gspca_dev->dev, pipe,
req, req_type,
val, 0, gspca_dev->usb_buf, size, 500);
if ((ret < 0) && (req != 0x0a))
pr_err("usb_control_msg error %i, request = 0x%x, error = %i\n",
set, req, ret);
return ret;
}
static int stv0680_handle_error(struct gspca_dev *gspca_dev, int ret)
{
stv_sndctrl(gspca_dev, 0, 0x80, 0, 0x02);
PERR("last error: %i, command = 0x%x",
gspca_dev->usb_buf[0], gspca_dev->usb_buf[1]);
return ret;
}
static int stv0680_get_video_mode(struct gspca_dev *gspca_dev)
{
memset(gspca_dev->usb_buf, 0, 8);
gspca_dev->usb_buf[0] = 0x0f;
if (stv_sndctrl(gspca_dev, 0, 0x87, 0, 0x08) != 0x08) {
PERR("Get_Camera_Mode failed");
return stv0680_handle_error(gspca_dev, -EIO);
}
return gspca_dev->usb_buf[0];
}
static int stv0680_set_video_mode(struct gspca_dev *gspca_dev, u8 mode)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->current_mode == mode)
return 0;
memset(gspca_dev->usb_buf, 0, 8);
gspca_dev->usb_buf[0] = mode;
if (stv_sndctrl(gspca_dev, 3, 0x07, 0x0100, 0x08) != 0x08) {
PERR("Set_Camera_Mode failed");
return stv0680_handle_error(gspca_dev, -EIO);
}
if (stv0680_get_video_mode(gspca_dev) != mode) {
PERR("Error setting camera video mode!");
return -EIO;
}
sd->current_mode = mode;
return 0;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
int ret;
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam = &gspca_dev->cam;
msleep(1000);
if (stv_sndctrl(gspca_dev, 0, 0x88, 0x5678, 0x02) != 0x02 ||
gspca_dev->usb_buf[0] != 0x56 || gspca_dev->usb_buf[1] != 0x78) {
PERR("STV(e): camera ping failed!!");
return stv0680_handle_error(gspca_dev, -ENODEV);
}
if (stv_sndctrl(gspca_dev, 2, 0x06, 0x0200, 0x09) != 0x09)
return stv0680_handle_error(gspca_dev, -ENODEV);
if (stv_sndctrl(gspca_dev, 2, 0x06, 0x0200, 0x22) != 0x22 ||
gspca_dev->usb_buf[7] != 0xa0 || gspca_dev->usb_buf[8] != 0x23) {
PERR("Could not get descriptor 0200.");
return stv0680_handle_error(gspca_dev, -ENODEV);
}
if (stv_sndctrl(gspca_dev, 0, 0x8a, 0, 0x02) != 0x02)
return stv0680_handle_error(gspca_dev, -ENODEV);
if (stv_sndctrl(gspca_dev, 0, 0x8b, 0, 0x24) != 0x24)
return stv0680_handle_error(gspca_dev, -ENODEV);
if (stv_sndctrl(gspca_dev, 0, 0x85, 0, 0x10) != 0x10)
return stv0680_handle_error(gspca_dev, -ENODEV);
if (!(gspca_dev->usb_buf[7] & 0x09)) {
PERR("Camera supports neither CIF nor QVGA mode");
return -ENODEV;
}
if (gspca_dev->usb_buf[7] & 0x01)
PDEBUG(D_PROBE, "Camera supports CIF mode");
if (gspca_dev->usb_buf[7] & 0x02)
PDEBUG(D_PROBE, "Camera supports VGA mode");
if (gspca_dev->usb_buf[7] & 0x04)
PDEBUG(D_PROBE, "Camera supports QCIF mode");
if (gspca_dev->usb_buf[7] & 0x08)
PDEBUG(D_PROBE, "Camera supports QVGA mode");
if (gspca_dev->usb_buf[7] & 0x01)
sd->video_mode = 0x00;
else
sd->video_mode = 0x03;
PDEBUG(D_PROBE, "Firmware rev is %i.%i",
gspca_dev->usb_buf[0], gspca_dev->usb_buf[1]);
PDEBUG(D_PROBE, "ASIC rev is %i.%i",
gspca_dev->usb_buf[2], gspca_dev->usb_buf[3]);
PDEBUG(D_PROBE, "Sensor ID is %i",
(gspca_dev->usb_buf[4]*16) + (gspca_dev->usb_buf[5]>>4));
ret = stv0680_get_video_mode(gspca_dev);
if (ret < 0)
return ret;
sd->current_mode = sd->orig_mode = ret;
ret = stv0680_set_video_mode(gspca_dev, sd->video_mode);
if (ret < 0)
return ret;
if (stv_sndctrl(gspca_dev, 0, 0x8f, 0, 0x10) != 0x10)
return stv0680_handle_error(gspca_dev, -EIO);
cam->bulk = 1;
cam->bulk_nurbs = 1;
cam->bulk_size = (gspca_dev->usb_buf[0] << 24) |
(gspca_dev->usb_buf[1] << 16) |
(gspca_dev->usb_buf[2] << 8) |
(gspca_dev->usb_buf[3]);
sd->mode.width = (gspca_dev->usb_buf[4] << 8) |
(gspca_dev->usb_buf[5]);
sd->mode.height = (gspca_dev->usb_buf[6] << 8) |
(gspca_dev->usb_buf[7]);
sd->mode.pixelformat = V4L2_PIX_FMT_STV0680;
sd->mode.field = V4L2_FIELD_NONE;
sd->mode.bytesperline = sd->mode.width;
sd->mode.sizeimage = cam->bulk_size;
sd->mode.colorspace = V4L2_COLORSPACE_SRGB;
cam->cam_mode = &sd->mode;
cam->nmodes = 1;
ret = stv0680_set_video_mode(gspca_dev, sd->orig_mode);
if (ret < 0)
return ret;
if (stv_sndctrl(gspca_dev, 2, 0x06, 0x0100, 0x12) != 0x12 ||
gspca_dev->usb_buf[8] != 0x53 || gspca_dev->usb_buf[9] != 0x05) {
pr_err("Could not get descriptor 0100\n");
return stv0680_handle_error(gspca_dev, -EIO);
}
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
int ret;
struct sd *sd = (struct sd *) gspca_dev;
ret = stv0680_set_video_mode(gspca_dev, sd->video_mode);
if (ret < 0)
return ret;
if (stv_sndctrl(gspca_dev, 0, 0x85, 0, 0x10) != 0x10)
return stv0680_handle_error(gspca_dev, -EIO);
if (stv_sndctrl(gspca_dev, 1, 0x09, sd->video_mode << 8, 0x0) != 0x0)
return stv0680_handle_error(gspca_dev, -EIO);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
if (stv_sndctrl(gspca_dev, 1, 0x04, 0x0000, 0x0) != 0x0)
stv0680_handle_error(gspca_dev, -EIO);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!sd->gspca_dev.present)
return;
stv0680_set_video_mode(gspca_dev, sd->orig_mode);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (len != sd->mode.sizeimage) {
gspca_dev->last_packet_type = DISCARD_PACKET;
return;
}
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
