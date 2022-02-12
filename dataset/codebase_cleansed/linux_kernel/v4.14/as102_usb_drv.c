static int as102_usb_xfer_cmd(struct as10x_bus_adapter_t *bus_adap,
unsigned char *send_buf, int send_buf_len,
unsigned char *recv_buf, int recv_buf_len)
{
int ret = 0;
if (send_buf != NULL) {
ret = usb_control_msg(bus_adap->usb_dev,
usb_sndctrlpipe(bus_adap->usb_dev, 0),
AS102_USB_DEVICE_TX_CTRL_CMD,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
bus_adap->cmd_xid,
0,
send_buf, send_buf_len,
USB_CTRL_SET_TIMEOUT );
if (ret < 0) {
dev_dbg(&bus_adap->usb_dev->dev,
"usb_control_msg(send) failed, err %i\n", ret);
return ret;
}
if (ret != send_buf_len) {
dev_dbg(&bus_adap->usb_dev->dev,
"only wrote %d of %d bytes\n", ret, send_buf_len);
return -1;
}
}
if (recv_buf != NULL) {
#ifdef TRACE
dev_dbg(bus_adap->usb_dev->dev,
"want to read: %d bytes\n", recv_buf_len);
#endif
ret = usb_control_msg(bus_adap->usb_dev,
usb_rcvctrlpipe(bus_adap->usb_dev, 0),
AS102_USB_DEVICE_RX_CTRL_CMD,
USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
bus_adap->cmd_xid,
0,
recv_buf, recv_buf_len,
USB_CTRL_GET_TIMEOUT );
if (ret < 0) {
dev_dbg(&bus_adap->usb_dev->dev,
"usb_control_msg(recv) failed, err %i\n", ret);
return ret;
}
#ifdef TRACE
dev_dbg(bus_adap->usb_dev->dev,
"read %d bytes\n", recv_buf_len);
#endif
}
return ret;
}
static int as102_send_ep1(struct as10x_bus_adapter_t *bus_adap,
unsigned char *send_buf,
int send_buf_len,
int swap32)
{
int ret, actual_len;
ret = usb_bulk_msg(bus_adap->usb_dev,
usb_sndbulkpipe(bus_adap->usb_dev, 1),
send_buf, send_buf_len, &actual_len, 200);
if (ret) {
dev_dbg(&bus_adap->usb_dev->dev,
"usb_bulk_msg(send) failed, err %i\n", ret);
return ret;
}
if (actual_len != send_buf_len) {
dev_dbg(&bus_adap->usb_dev->dev, "only wrote %d of %d bytes\n",
actual_len, send_buf_len);
return -1;
}
return actual_len;
}
static int as102_read_ep2(struct as10x_bus_adapter_t *bus_adap,
unsigned char *recv_buf, int recv_buf_len)
{
int ret, actual_len;
if (recv_buf == NULL)
return -EINVAL;
ret = usb_bulk_msg(bus_adap->usb_dev,
usb_rcvbulkpipe(bus_adap->usb_dev, 2),
recv_buf, recv_buf_len, &actual_len, 200);
if (ret) {
dev_dbg(&bus_adap->usb_dev->dev,
"usb_bulk_msg(recv) failed, err %i\n", ret);
return ret;
}
if (actual_len != recv_buf_len) {
dev_dbg(&bus_adap->usb_dev->dev, "only read %d of %d bytes\n",
actual_len, recv_buf_len);
return -1;
}
return actual_len;
}
static int as102_submit_urb_stream(struct as102_dev_t *dev, struct urb *urb)
{
int err;
usb_fill_bulk_urb(urb,
dev->bus_adap.usb_dev,
usb_rcvbulkpipe(dev->bus_adap.usb_dev, 0x2),
urb->transfer_buffer,
AS102_USB_BUF_SIZE,
as102_urb_stream_irq,
dev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err)
dev_dbg(&urb->dev->dev,
"%s: usb_submit_urb failed\n", __func__);
return err;
}
void as102_urb_stream_irq(struct urb *urb)
{
struct as102_dev_t *as102_dev = urb->context;
if (urb->actual_length > 0) {
dvb_dmx_swfilter(&as102_dev->dvb_dmx,
urb->transfer_buffer,
urb->actual_length);
} else {
if (urb->actual_length == 0)
memset(urb->transfer_buffer, 0, AS102_USB_BUF_SIZE);
}
if (as102_dev->streaming)
as102_submit_urb_stream(as102_dev, urb);
}
static void as102_free_usb_stream_buffer(struct as102_dev_t *dev)
{
int i;
for (i = 0; i < MAX_STREAM_URB; i++)
usb_free_urb(dev->stream_urb[i]);
usb_free_coherent(dev->bus_adap.usb_dev,
MAX_STREAM_URB * AS102_USB_BUF_SIZE,
dev->stream,
dev->dma_addr);
}
static int as102_alloc_usb_stream_buffer(struct as102_dev_t *dev)
{
int i;
dev->stream = usb_alloc_coherent(dev->bus_adap.usb_dev,
MAX_STREAM_URB * AS102_USB_BUF_SIZE,
GFP_KERNEL,
&dev->dma_addr);
if (!dev->stream) {
dev_dbg(&dev->bus_adap.usb_dev->dev,
"%s: usb_buffer_alloc failed\n", __func__);
return -ENOMEM;
}
memset(dev->stream, 0, MAX_STREAM_URB * AS102_USB_BUF_SIZE);
for (i = 0; i < MAX_STREAM_URB; i++) {
struct urb *urb;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (urb == NULL) {
as102_free_usb_stream_buffer(dev);
return -ENOMEM;
}
urb->transfer_buffer = dev->stream + (i * AS102_USB_BUF_SIZE);
urb->transfer_dma = dev->dma_addr + (i * AS102_USB_BUF_SIZE);
urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer_length = AS102_USB_BUF_SIZE;
dev->stream_urb[i] = urb;
}
return 0;
}
static void as102_usb_stop_stream(struct as102_dev_t *dev)
{
int i;
for (i = 0; i < MAX_STREAM_URB; i++)
usb_kill_urb(dev->stream_urb[i]);
}
static int as102_usb_start_stream(struct as102_dev_t *dev)
{
int i, ret = 0;
for (i = 0; i < MAX_STREAM_URB; i++) {
ret = as102_submit_urb_stream(dev, dev->stream_urb[i]);
if (ret) {
as102_usb_stop_stream(dev);
return ret;
}
}
return 0;
}
static void as102_usb_release(struct kref *kref)
{
struct as102_dev_t *as102_dev;
as102_dev = container_of(kref, struct as102_dev_t, kref);
if (as102_dev != NULL) {
usb_put_dev(as102_dev->bus_adap.usb_dev);
kfree(as102_dev);
}
}
static void as102_usb_disconnect(struct usb_interface *intf)
{
struct as102_dev_t *as102_dev;
as102_dev = usb_get_intfdata(intf);
as102_dvb_unregister(as102_dev);
as102_free_usb_stream_buffer(as102_dev);
usb_set_intfdata(intf, NULL);
usb_deregister_dev(intf, &as102_usb_class_driver);
kref_put(&as102_dev->kref, as102_usb_release);
pr_info("%s: device has been disconnected\n", DRIVER_NAME);
}
static int as102_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret;
struct as102_dev_t *as102_dev;
int i;
if (ARRAY_SIZE(as102_usb_id_table) !=
(sizeof(as102_device_names) / sizeof(const char *))) {
pr_err("Device names table invalid size");
return -EINVAL;
}
as102_dev = kzalloc(sizeof(struct as102_dev_t), GFP_KERNEL);
if (as102_dev == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(as102_usb_id_table); i++) {
if (id == &as102_usb_id_table[i]) {
as102_dev->name = as102_device_names[i];
as102_dev->elna_cfg = as102_elna_cfg[i];
}
}
if (as102_dev->name == NULL)
as102_dev->name = "Unknown AS102 device";
as102_dev->bus_adap.ops = &as102_priv_ops;
as102_dev->bus_adap.cmd = &as102_dev->bus_adap.token.usb.c;
as102_dev->bus_adap.rsp = &as102_dev->bus_adap.token.usb.r;
kref_init(&as102_dev->kref);
usb_set_intfdata(intf, (void *) as102_dev);
as102_dev->bus_adap.usb_dev = usb_get_dev(interface_to_usbdev(intf));
ret = usb_register_dev(intf, &as102_usb_class_driver);
if (ret < 0) {
dev_err(&intf->dev,
"%s: usb_register_dev() failed (errno = %d)\n",
__func__, ret);
goto failed;
}
pr_info("%s: device has been detected\n", DRIVER_NAME);
ret = as102_alloc_usb_stream_buffer(as102_dev);
if (ret != 0)
goto failed_stream;
ret = as102_dvb_register(as102_dev);
if (ret != 0)
goto failed_dvb;
return ret;
failed_dvb:
as102_free_usb_stream_buffer(as102_dev);
failed_stream:
usb_deregister_dev(intf, &as102_usb_class_driver);
failed:
usb_put_dev(as102_dev->bus_adap.usb_dev);
usb_set_intfdata(intf, NULL);
kfree(as102_dev);
return ret;
}
static int as102_open(struct inode *inode, struct file *file)
{
int ret = 0, minor = 0;
struct usb_interface *intf = NULL;
struct as102_dev_t *dev = NULL;
minor = iminor(inode);
intf = usb_find_interface(&as102_usb_driver, minor);
if (intf == NULL) {
pr_err("%s: can't find device for minor %d\n",
__func__, minor);
ret = -ENODEV;
goto exit;
}
dev = usb_get_intfdata(intf);
if (dev == NULL) {
ret = -EFAULT;
goto exit;
}
file->private_data = dev;
kref_get(&dev->kref);
exit:
return ret;
}
static int as102_release(struct inode *inode, struct file *file)
{
struct as102_dev_t *dev = NULL;
dev = file->private_data;
if (dev != NULL) {
kref_put(&dev->kref, as102_usb_release);
}
return 0;
}
