static int command(struct gspca_dev *gspca_dev,
int order)
{
static u8 order_values[2][12] = {
{0xc6, 0, 0, 0, 0, 0, 0, 0, 0x20, 0, 0, 0},
{0xd3, 0, 0, 0, 0, 0, 0, 0x01, 0, 0, 0, 0},
};
memcpy(gspca_dev->usb_buf, order_values[order], 12);
return usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
USB_REQ_GET_STATUS,
USB_DIR_OUT | USB_TYPE_CLASS |
USB_RECIP_INTERFACE, 0, 0, gspca_dev->usb_buf,
12, FPIX_TIMEOUT);
}
static void dostream(struct work_struct *work)
{
struct usb_fpix *dev = container_of(work, struct usb_fpix, work_struct);
struct gspca_dev *gspca_dev = &dev->gspca_dev;
struct urb *urb = gspca_dev->urb[0];
u8 *data = urb->transfer_buffer;
int ret = 0;
int len;
mutex_lock(&gspca_dev->usb_lock);
mutex_unlock(&gspca_dev->usb_lock);
PDEBUG(D_STREAM, "dostream started");
again:
while (gspca_dev->present && gspca_dev->streaming) {
mutex_lock(&gspca_dev->usb_lock);
ret = command(gspca_dev, 1);
mutex_unlock(&gspca_dev->usb_lock);
if (ret < 0)
break;
if (!gspca_dev->present || !gspca_dev->streaming)
break;
for (;;) {
ret = usb_bulk_msg(gspca_dev->dev,
urb->pipe,
data,
FPIX_MAX_TRANSFER,
&len, FPIX_TIMEOUT);
if (ret < 0) {
goto again;
}
if (!gspca_dev->present || !gspca_dev->streaming)
goto out;
if (len < FPIX_MAX_TRANSFER ||
(data[len - 2] == 0xff &&
data[len - 1] == 0xd9)) {
gspca_frame_add(gspca_dev, LAST_PACKET,
data, len);
break;
}
gspca_frame_add(gspca_dev,
gspca_dev->last_packet_type
== LAST_PACKET
? FIRST_PACKET : INTER_PACKET,
data, len);
}
msleep(NEXT_FRAME_DELAY);
}
out:
PDEBUG(D_STREAM, "dostream stopped");
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct usb_fpix *dev = (struct usb_fpix *) gspca_dev;
struct cam *cam = &gspca_dev->cam;
cam->cam_mode = fpix_mode;
cam->nmodes = 1;
cam->bulk = 1;
cam->bulk_size = FPIX_MAX_TRANSFER;
INIT_WORK(&dev->work_struct, dostream);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct usb_fpix *dev = (struct usb_fpix *) gspca_dev;
int ret, len;
ret = command(gspca_dev, 0);
if (ret < 0) {
err("init failed %d", ret);
return ret;
}
ret = usb_bulk_msg(gspca_dev->dev,
gspca_dev->urb[0]->pipe,
gspca_dev->urb[0]->transfer_buffer,
FPIX_MAX_TRANSFER, &len,
FPIX_TIMEOUT);
if (ret < 0) {
err("usb_bulk_msg failed %d", ret);
return ret;
}
ret = command(gspca_dev, 1);
if (ret < 0) {
err("frame request failed %d", ret);
return ret;
}
usb_clear_halt(gspca_dev->dev, gspca_dev->urb[0]->pipe);
dev->work_thread = create_singlethread_workqueue(MODULE_NAME);
queue_work(dev->work_thread, &dev->work_struct);
return 0;
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct usb_fpix *dev = (struct usb_fpix *) gspca_dev;
mutex_unlock(&gspca_dev->usb_lock);
destroy_workqueue(dev->work_thread);
mutex_lock(&gspca_dev->usb_lock);
dev->work_thread = NULL;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
&sd_desc,
sizeof(struct usb_fpix),
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
