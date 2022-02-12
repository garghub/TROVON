static int sq905_command(struct gspca_dev *gspca_dev, u16 index)
{
int ret;
gspca_dev->usb_buf[0] = '\0';
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
SQ905_COMMAND, index, gspca_dev->usb_buf, 1,
SQ905_CMD_TIMEOUT);
if (ret < 0) {
pr_err("%s: usb_control_msg failed (%d)\n", __func__, ret);
return ret;
}
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
SQ905_PING, 0, gspca_dev->usb_buf, 1,
SQ905_CMD_TIMEOUT);
if (ret < 0) {
pr_err("%s: usb_control_msg failed 2 (%d)\n", __func__, ret);
return ret;
}
return 0;
}
static int sq905_ack_frame(struct gspca_dev *gspca_dev)
{
int ret;
gspca_dev->usb_buf[0] = '\0';
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
SQ905_READ_DONE, 0, gspca_dev->usb_buf, 1,
SQ905_CMD_TIMEOUT);
if (ret < 0) {
pr_err("%s: usb_control_msg failed (%d)\n", __func__, ret);
return ret;
}
return 0;
}
static int
sq905_read_data(struct gspca_dev *gspca_dev, u8 *data, int size, int need_lock)
{
int ret;
int act_len;
gspca_dev->usb_buf[0] = '\0';
if (need_lock)
mutex_lock(&gspca_dev->usb_lock);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
SQ905_BULK_READ, size, gspca_dev->usb_buf,
1, SQ905_CMD_TIMEOUT);
if (need_lock)
mutex_unlock(&gspca_dev->usb_lock);
if (ret < 0) {
pr_err("%s: usb_control_msg failed (%d)\n", __func__, ret);
return ret;
}
ret = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 0x81),
data, size, &act_len, SQ905_DATA_TIMEOUT);
if (ret < 0 || act_len != size) {
pr_err("bulk read fail (%d) len %d/%d\n", ret, act_len, size);
return -EIO;
}
return 0;
}
static void sq905_dostream(struct work_struct *work)
{
struct sd *dev = container_of(work, struct sd, work_struct);
struct gspca_dev *gspca_dev = &dev->gspca_dev;
int bytes_left;
int data_len;
int header_read;
int packet_type;
int frame_sz;
int ret;
u8 *data;
u8 *buffer;
buffer = kmalloc(SQ905_MAX_TRANSFER, GFP_KERNEL | GFP_DMA);
if (!buffer) {
pr_err("Couldn't allocate USB buffer\n");
goto quit_stream;
}
frame_sz = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].sizeimage
+ FRAME_HEADER_LEN;
while (gspca_dev->present && gspca_dev->streaming) {
#ifdef CONFIG_PM
if (gspca_dev->frozen)
break;
#endif
bytes_left = frame_sz;
header_read = 0;
while (bytes_left > 0 && gspca_dev->present) {
data_len = bytes_left > SQ905_MAX_TRANSFER ?
SQ905_MAX_TRANSFER : bytes_left;
ret = sq905_read_data(gspca_dev, buffer, data_len, 1);
if (ret < 0)
goto quit_stream;
PDEBUG(D_PACK,
"Got %d bytes out of %d for frame",
data_len, bytes_left);
bytes_left -= data_len;
data = buffer;
if (!header_read) {
packet_type = FIRST_PACKET;
data += FRAME_HEADER_LEN;
data_len -= FRAME_HEADER_LEN;
header_read = 1;
} else if (bytes_left == 0) {
packet_type = LAST_PACKET;
} else {
packet_type = INTER_PACKET;
}
gspca_frame_add(gspca_dev, packet_type,
data, data_len);
if (packet_type == FIRST_PACKET &&
bytes_left == 0)
gspca_frame_add(gspca_dev, LAST_PACKET,
NULL, 0);
}
if (gspca_dev->present) {
mutex_lock(&gspca_dev->usb_lock);
ret = sq905_ack_frame(gspca_dev);
mutex_unlock(&gspca_dev->usb_lock);
if (ret < 0)
goto quit_stream;
}
}
quit_stream:
if (gspca_dev->present) {
mutex_lock(&gspca_dev->usb_lock);
sq905_command(gspca_dev, SQ905_CLEAR);
mutex_unlock(&gspca_dev->usb_lock);
}
kfree(buffer);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam = &gspca_dev->cam;
struct sd *dev = (struct sd *) gspca_dev;
cam->bulk = 1;
cam->bulk_size = 64;
INIT_WORK(&dev->work_struct, sq905_dostream);
return 0;
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *dev = (struct sd *) gspca_dev;
mutex_unlock(&gspca_dev->usb_lock);
destroy_workqueue(dev->work_thread);
dev->work_thread = NULL;
mutex_lock(&gspca_dev->usb_lock);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
u32 ident;
int ret;
ret = sq905_command(gspca_dev, SQ905_CLEAR);
if (ret < 0)
return ret;
ret = sq905_command(gspca_dev, SQ905_ID);
if (ret < 0)
return ret;
ret = sq905_read_data(gspca_dev, gspca_dev->usb_buf, 4, 0);
if (ret < 0)
return ret;
ident = be32_to_cpup((__be32 *)gspca_dev->usb_buf);
ret = sq905_command(gspca_dev, SQ905_CLEAR);
if (ret < 0)
return ret;
PDEBUG(D_CONF, "SQ905 camera ID %08x detected", ident);
gspca_dev->cam.cam_mode = sq905_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(sq905_mode);
if (!(ident & SQ905_HIRES_MASK))
gspca_dev->cam.nmodes--;
if (ident & SQ905_ORIENTATION_MASK)
gspca_dev->cam.input_flags = V4L2_IN_ST_VFLIP;
else
gspca_dev->cam.input_flags = V4L2_IN_ST_VFLIP |
V4L2_IN_ST_HFLIP;
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *dev = (struct sd *) gspca_dev;
int ret;
switch (gspca_dev->curr_mode) {
default:
PDEBUG(D_STREAM, "Start streaming at high resolution");
ret = sq905_command(&dev->gspca_dev, SQ905_CAPTURE_HIGH);
break;
case 1:
PDEBUG(D_STREAM, "Start streaming at medium resolution");
ret = sq905_command(&dev->gspca_dev, SQ905_CAPTURE_MED);
break;
case 0:
PDEBUG(D_STREAM, "Start streaming at low resolution");
ret = sq905_command(&dev->gspca_dev, SQ905_CAPTURE_LOW);
}
if (ret < 0) {
PERR("Start streaming command failed");
return ret;
}
dev->work_thread = create_singlethread_workqueue(MODULE_NAME);
queue_work(dev->work_thread, &dev->work_struct);
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
&sd_desc,
sizeof(struct sd),
THIS_MODULE);
}
