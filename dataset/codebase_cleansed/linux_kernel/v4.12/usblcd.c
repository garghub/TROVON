static void lcd_delete(struct kref *kref)
{
struct usb_lcd *dev = to_lcd_dev(kref);
usb_put_dev(dev->udev);
kfree(dev->bulk_in_buffer);
kfree(dev);
}
static int lcd_open(struct inode *inode, struct file *file)
{
struct usb_lcd *dev;
struct usb_interface *interface;
int subminor, r;
mutex_lock(&lcd_mutex);
subminor = iminor(inode);
interface = usb_find_interface(&lcd_driver, subminor);
if (!interface) {
mutex_unlock(&lcd_mutex);
printk(KERN_ERR "USBLCD: %s - error, can't find device for minor %d\n",
__func__, subminor);
return -ENODEV;
}
mutex_lock(&open_disc_mutex);
dev = usb_get_intfdata(interface);
if (!dev) {
mutex_unlock(&open_disc_mutex);
mutex_unlock(&lcd_mutex);
return -ENODEV;
}
kref_get(&dev->kref);
mutex_unlock(&open_disc_mutex);
r = usb_autopm_get_interface(interface);
if (r < 0) {
kref_put(&dev->kref, lcd_delete);
mutex_unlock(&lcd_mutex);
return r;
}
file->private_data = dev;
mutex_unlock(&lcd_mutex);
return 0;
}
static int lcd_release(struct inode *inode, struct file *file)
{
struct usb_lcd *dev;
dev = file->private_data;
if (dev == NULL)
return -ENODEV;
usb_autopm_put_interface(dev->interface);
kref_put(&dev->kref, lcd_delete);
return 0;
}
static ssize_t lcd_read(struct file *file, char __user * buffer,
size_t count, loff_t *ppos)
{
struct usb_lcd *dev;
int retval = 0;
int bytes_read;
dev = file->private_data;
retval = usb_bulk_msg(dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->bulk_in_endpointAddr),
dev->bulk_in_buffer,
min(dev->bulk_in_size, count),
&bytes_read, 10000);
if (!retval) {
if (copy_to_user(buffer, dev->bulk_in_buffer, bytes_read))
retval = -EFAULT;
else
retval = bytes_read;
}
return retval;
}
static long lcd_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct usb_lcd *dev;
u16 bcdDevice;
char buf[30];
dev = file->private_data;
if (dev == NULL)
return -ENODEV;
switch (cmd) {
case IOCTL_GET_HARD_VERSION:
mutex_lock(&lcd_mutex);
bcdDevice = le16_to_cpu((dev->udev)->descriptor.bcdDevice);
sprintf(buf, "%1d%1d.%1d%1d",
(bcdDevice & 0xF000)>>12,
(bcdDevice & 0xF00)>>8,
(bcdDevice & 0xF0)>>4,
(bcdDevice & 0xF));
mutex_unlock(&lcd_mutex);
if (copy_to_user((void __user *)arg, buf, strlen(buf)) != 0)
return -EFAULT;
break;
case IOCTL_GET_DRV_VERSION:
sprintf(buf, DRIVER_VERSION);
if (copy_to_user((void __user *)arg, buf, strlen(buf)) != 0)
return -EFAULT;
break;
default:
return -ENOTTY;
break;
}
return 0;
}
static void lcd_write_bulk_callback(struct urb *urb)
{
struct usb_lcd *dev;
int status = urb->status;
dev = urb->context;
if (status &&
!(status == -ENOENT ||
status == -ECONNRESET ||
status == -ESHUTDOWN)) {
dev_dbg(&dev->interface->dev,
"nonzero write bulk status received: %d\n", status);
}
usb_free_coherent(urb->dev, urb->transfer_buffer_length,
urb->transfer_buffer, urb->transfer_dma);
up(&dev->limit_sem);
}
static ssize_t lcd_write(struct file *file, const char __user * user_buffer,
size_t count, loff_t *ppos)
{
struct usb_lcd *dev;
int retval = 0, r;
struct urb *urb = NULL;
char *buf = NULL;
dev = file->private_data;
if (count == 0)
goto exit;
r = down_interruptible(&dev->limit_sem);
if (r < 0)
return -EINTR;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
retval = -ENOMEM;
goto err_no_buf;
}
buf = usb_alloc_coherent(dev->udev, count, GFP_KERNEL,
&urb->transfer_dma);
if (!buf) {
retval = -ENOMEM;
goto error;
}
if (copy_from_user(buf, user_buffer, count)) {
retval = -EFAULT;
goto error;
}
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev,
dev->bulk_out_endpointAddr),
buf, count, lcd_write_bulk_callback, dev);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &dev->submitted);
retval = usb_submit_urb(urb, GFP_KERNEL);
if (retval) {
dev_err(&dev->udev->dev,
"%s - failed submitting write urb, error %d\n",
__func__, retval);
goto error_unanchor;
}
usb_free_urb(urb);
exit:
return count;
error_unanchor:
usb_unanchor_urb(urb);
error:
usb_free_coherent(dev->udev, count, buf, urb->transfer_dma);
usb_free_urb(urb);
err_no_buf:
up(&dev->limit_sem);
return retval;
}
static int lcd_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_lcd *dev = NULL;
struct usb_endpoint_descriptor *bulk_in, *bulk_out;
int i;
int retval;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
kref_init(&dev->kref);
sema_init(&dev->limit_sem, USB_LCD_CONCURRENT_WRITES);
init_usb_anchor(&dev->submitted);
dev->udev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
if (le16_to_cpu(dev->udev->descriptor.idProduct) != 0x0001) {
dev_warn(&interface->dev, "USBLCD model not supported.\n");
retval = -ENODEV;
goto error;
}
retval = usb_find_common_endpoints(interface->cur_altsetting,
&bulk_in, &bulk_out, NULL, NULL);
if (retval) {
dev_err(&interface->dev,
"Could not find both bulk-in and bulk-out endpoints\n");
goto error;
}
dev->bulk_in_size = usb_endpoint_maxp(bulk_in);
dev->bulk_in_endpointAddr = bulk_in->bEndpointAddress;
dev->bulk_in_buffer = kmalloc(dev->bulk_in_size, GFP_KERNEL);
if (!dev->bulk_in_buffer) {
retval = -ENOMEM;
goto error;
}
dev->bulk_out_endpointAddr = bulk_out->bEndpointAddress;
usb_set_intfdata(interface, dev);
retval = usb_register_dev(interface, &lcd_class);
if (retval) {
dev_err(&interface->dev,
"Not able to get a minor for this device.\n");
usb_set_intfdata(interface, NULL);
goto error;
}
i = le16_to_cpu(dev->udev->descriptor.bcdDevice);
dev_info(&interface->dev, "USBLCD Version %1d%1d.%1d%1d found "
"at address %d\n", (i & 0xF000)>>12, (i & 0xF00)>>8,
(i & 0xF0)>>4, (i & 0xF), dev->udev->devnum);
dev_info(&interface->dev, "USB LCD device now attached to USBLCD-%d\n",
interface->minor);
return 0;
error:
kref_put(&dev->kref, lcd_delete);
return retval;
}
static void lcd_draw_down(struct usb_lcd *dev)
{
int time;
time = usb_wait_anchor_empty_timeout(&dev->submitted, 1000);
if (!time)
usb_kill_anchored_urbs(&dev->submitted);
}
static int lcd_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usb_lcd *dev = usb_get_intfdata(intf);
if (!dev)
return 0;
lcd_draw_down(dev);
return 0;
}
static int lcd_resume(struct usb_interface *intf)
{
return 0;
}
static void lcd_disconnect(struct usb_interface *interface)
{
struct usb_lcd *dev;
int minor = interface->minor;
mutex_lock(&open_disc_mutex);
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
mutex_unlock(&open_disc_mutex);
usb_deregister_dev(interface, &lcd_class);
kref_put(&dev->kref, lcd_delete);
dev_info(&interface->dev, "USB LCD #%d now disconnected\n", minor);
}
