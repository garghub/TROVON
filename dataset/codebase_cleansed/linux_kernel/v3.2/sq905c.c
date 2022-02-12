static int sq905c_command(struct gspca_dev *gspca_dev, u16 command, u16 index)
{
int ret;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
command, index, NULL, 0,
SQ905C_CMD_TIMEOUT);
if (ret < 0) {
pr_err("%s: usb_control_msg failed (%d)\n", __func__, ret);
return ret;
}
return 0;
}
static int sq905c_read(struct gspca_dev *gspca_dev, u16 command, u16 index,
int size)
{
int ret;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
USB_REQ_SYNCH_FRAME,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
command, index, gspca_dev->usb_buf, size,
SQ905C_CMD_TIMEOUT);
if (ret < 0) {
pr_err("%s: usb_control_msg failed (%d)\n", __func__, ret);
return ret;
}
return 0;
}
static void sq905c_dostream(struct work_struct *work)
{
struct sd *dev = container_of(work, struct sd, work_struct);
struct gspca_dev *gspca_dev = &dev->gspca_dev;
int bytes_left;
int data_len;
int act_len;
int packet_type;
int ret;
u8 *buffer;
buffer = kmalloc(SQ905C_MAX_TRANSFER, GFP_KERNEL | GFP_DMA);
if (!buffer) {
pr_err("Couldn't allocate USB buffer\n");
goto quit_stream;
}
while (gspca_dev->present && gspca_dev->streaming) {
ret = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 0x81),
buffer, FRAME_HEADER_LEN, &act_len,
SQ905C_DATA_TIMEOUT);
PDEBUG(D_STREAM,
"Got %d bytes out of %d for header",
act_len, FRAME_HEADER_LEN);
if (ret < 0 || act_len < FRAME_HEADER_LEN)
goto quit_stream;
bytes_left = buffer[0x40]|(buffer[0x41]<<8)|(buffer[0x42]<<16)
|(buffer[0x43]<<24);
PDEBUG(D_STREAM, "bytes_left = 0x%x", bytes_left);
packet_type = FIRST_PACKET;
gspca_frame_add(gspca_dev, packet_type,
buffer, FRAME_HEADER_LEN);
while (bytes_left > 0 && gspca_dev->present) {
data_len = bytes_left > SQ905C_MAX_TRANSFER ?
SQ905C_MAX_TRANSFER : bytes_left;
ret = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 0x81),
buffer, data_len, &act_len,
SQ905C_DATA_TIMEOUT);
if (ret < 0 || act_len < data_len)
goto quit_stream;
PDEBUG(D_STREAM,
"Got %d bytes out of %d for frame",
data_len, bytes_left);
bytes_left -= data_len;
if (bytes_left == 0)
packet_type = LAST_PACKET;
else
packet_type = INTER_PACKET;
gspca_frame_add(gspca_dev, packet_type,
buffer, data_len);
}
}
quit_stream:
if (gspca_dev->present) {
mutex_lock(&gspca_dev->usb_lock);
sq905c_command(gspca_dev, SQ905C_CLEAR, 0);
mutex_unlock(&gspca_dev->usb_lock);
}
kfree(buffer);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam = &gspca_dev->cam;
struct sd *dev = (struct sd *) gspca_dev;
int ret;
PDEBUG(D_PROBE,
"SQ9050 camera detected"
" (vid/pid 0x%04X:0x%04X)", id->idVendor, id->idProduct);
ret = sq905c_command(gspca_dev, SQ905C_GET_ID, 0);
if (ret < 0) {
PDEBUG(D_ERR, "Get version command failed");
return ret;
}
ret = sq905c_read(gspca_dev, 0xf5, 0, 20);
if (ret < 0) {
PDEBUG(D_ERR, "Reading version command failed");
return ret;
}
PDEBUG(D_PROBE,
"SQ9050 ID string: %02x - %02x %02x %02x %02x %02x %02x",
gspca_dev->usb_buf[3],
gspca_dev->usb_buf[14], gspca_dev->usb_buf[15],
gspca_dev->usb_buf[16], gspca_dev->usb_buf[17],
gspca_dev->usb_buf[18], gspca_dev->usb_buf[19]);
cam->cam_mode = sq905c_mode;
cam->nmodes = 2;
if (gspca_dev->usb_buf[15] == 0)
cam->nmodes = 1;
cam->bulk_size = 32;
cam->bulk = 1;
INIT_WORK(&dev->work_struct, sq905c_dostream);
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
int ret;
ret = sq905c_command(gspca_dev, SQ905C_CLEAR, 0);
return ret;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *dev = (struct sd *) gspca_dev;
int ret;
dev->cap_mode = gspca_dev->cam.cam_mode;
switch (gspca_dev->width) {
case 640:
PDEBUG(D_STREAM, "Start streaming at high resolution");
dev->cap_mode++;
ret = sq905c_command(gspca_dev, SQ905C_CAPTURE_HI,
SQ905C_CAPTURE_INDEX);
break;
default:
PDEBUG(D_STREAM, "Start streaming at medium resolution");
ret = sq905c_command(gspca_dev, SQ905C_CAPTURE_MED,
SQ905C_CAPTURE_INDEX);
}
if (ret < 0) {
PDEBUG(D_ERR, "Start streaming command failed");
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
static int __init sd_mod_init(void)
{
return usb_register(&sd_driver);
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
