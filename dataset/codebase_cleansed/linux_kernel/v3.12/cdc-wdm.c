static struct wdm_device *wdm_find_device(struct usb_interface *intf)
{
struct wdm_device *desc;
spin_lock(&wdm_device_list_lock);
list_for_each_entry(desc, &wdm_device_list, device_list)
if (desc->intf == intf)
goto found;
desc = NULL;
found:
spin_unlock(&wdm_device_list_lock);
return desc;
}
static struct wdm_device *wdm_find_device_by_minor(int minor)
{
struct wdm_device *desc;
spin_lock(&wdm_device_list_lock);
list_for_each_entry(desc, &wdm_device_list, device_list)
if (desc->intf->minor == minor)
goto found;
desc = NULL;
found:
spin_unlock(&wdm_device_list_lock);
return desc;
}
static void wdm_out_callback(struct urb *urb)
{
struct wdm_device *desc;
desc = urb->context;
spin_lock(&desc->iuspin);
desc->werr = urb->status;
spin_unlock(&desc->iuspin);
kfree(desc->outbuf);
desc->outbuf = NULL;
clear_bit(WDM_IN_USE, &desc->flags);
wake_up(&desc->wait);
}
static void wdm_in_callback(struct urb *urb)
{
struct wdm_device *desc = urb->context;
int status = urb->status;
int length = urb->actual_length;
spin_lock(&desc->iuspin);
clear_bit(WDM_RESPONDING, &desc->flags);
if (status) {
switch (status) {
case -ENOENT:
dev_dbg(&desc->intf->dev,
"nonzero urb status received: -ENOENT");
goto skip_error;
case -ECONNRESET:
dev_dbg(&desc->intf->dev,
"nonzero urb status received: -ECONNRESET");
goto skip_error;
case -ESHUTDOWN:
dev_dbg(&desc->intf->dev,
"nonzero urb status received: -ESHUTDOWN");
goto skip_error;
case -EPIPE:
dev_err(&desc->intf->dev,
"nonzero urb status received: -EPIPE\n");
break;
default:
dev_err(&desc->intf->dev,
"Unexpected error %d\n", status);
break;
}
}
desc->rerr = status;
if (length + desc->length > desc->wMaxCommand) {
set_bit(WDM_OVERFLOW, &desc->flags);
} else {
if (!test_bit(WDM_OVERFLOW, &desc->flags)) {
memmove(desc->ubuf + desc->length, desc->inbuf, length);
desc->length += length;
desc->reslength = length;
}
}
skip_error:
wake_up(&desc->wait);
set_bit(WDM_READ, &desc->flags);
spin_unlock(&desc->iuspin);
}
static void wdm_int_callback(struct urb *urb)
{
int rv = 0;
int responding;
int status = urb->status;
struct wdm_device *desc;
struct usb_cdc_notification *dr;
desc = urb->context;
dr = (struct usb_cdc_notification *)desc->sbuf;
if (status) {
switch (status) {
case -ESHUTDOWN:
case -ENOENT:
case -ECONNRESET:
return;
case -EPIPE:
set_bit(WDM_INT_STALL, &desc->flags);
dev_err(&desc->intf->dev, "Stall on int endpoint\n");
goto sw;
default:
dev_err(&desc->intf->dev,
"nonzero urb status received: %d\n", status);
break;
}
}
if (urb->actual_length < sizeof(struct usb_cdc_notification)) {
dev_err(&desc->intf->dev, "wdm_int_callback - %d bytes\n",
urb->actual_length);
goto exit;
}
switch (dr->bNotificationType) {
case USB_CDC_NOTIFY_RESPONSE_AVAILABLE:
dev_dbg(&desc->intf->dev,
"NOTIFY_RESPONSE_AVAILABLE received: index %d len %d",
dr->wIndex, dr->wLength);
break;
case USB_CDC_NOTIFY_NETWORK_CONNECTION:
dev_dbg(&desc->intf->dev,
"NOTIFY_NETWORK_CONNECTION %s network",
dr->wValue ? "connected to" : "disconnected from");
goto exit;
default:
clear_bit(WDM_POLL_RUNNING, &desc->flags);
dev_err(&desc->intf->dev,
"unknown notification %d received: index %d len %d\n",
dr->bNotificationType, dr->wIndex, dr->wLength);
goto exit;
}
spin_lock(&desc->iuspin);
clear_bit(WDM_READ, &desc->flags);
responding = test_and_set_bit(WDM_RESPONDING, &desc->flags);
if (!responding && !test_bit(WDM_DISCONNECTING, &desc->flags)
&& !test_bit(WDM_SUSPENDING, &desc->flags)) {
rv = usb_submit_urb(desc->response, GFP_ATOMIC);
dev_dbg(&desc->intf->dev, "%s: usb_submit_urb %d",
__func__, rv);
}
spin_unlock(&desc->iuspin);
if (rv < 0) {
clear_bit(WDM_RESPONDING, &desc->flags);
if (rv == -EPERM)
return;
if (rv == -ENOMEM) {
sw:
rv = schedule_work(&desc->rxwork);
if (rv)
dev_err(&desc->intf->dev,
"Cannot schedule work\n");
}
}
exit:
rv = usb_submit_urb(urb, GFP_ATOMIC);
if (rv)
dev_err(&desc->intf->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, rv);
}
static void kill_urbs(struct wdm_device *desc)
{
usb_kill_urb(desc->command);
usb_kill_urb(desc->validity);
usb_kill_urb(desc->response);
}
static void free_urbs(struct wdm_device *desc)
{
usb_free_urb(desc->validity);
usb_free_urb(desc->response);
usb_free_urb(desc->command);
}
static void cleanup(struct wdm_device *desc)
{
kfree(desc->sbuf);
kfree(desc->inbuf);
kfree(desc->orq);
kfree(desc->irq);
kfree(desc->ubuf);
free_urbs(desc);
kfree(desc);
}
static ssize_t wdm_write
(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
u8 *buf;
int rv = -EMSGSIZE, r, we;
struct wdm_device *desc = file->private_data;
struct usb_ctrlrequest *req;
if (count > desc->wMaxCommand)
count = desc->wMaxCommand;
spin_lock_irq(&desc->iuspin);
we = desc->werr;
desc->werr = 0;
spin_unlock_irq(&desc->iuspin);
if (we < 0)
return -EIO;
buf = kmalloc(count, GFP_KERNEL);
if (!buf) {
rv = -ENOMEM;
goto outnl;
}
r = copy_from_user(buf, buffer, count);
if (r > 0) {
kfree(buf);
rv = -EFAULT;
goto outnl;
}
r = mutex_lock_interruptible(&desc->wlock);
rv = -ERESTARTSYS;
if (r) {
kfree(buf);
goto outnl;
}
if (test_bit(WDM_DISCONNECTING, &desc->flags)) {
kfree(buf);
rv = -ENODEV;
goto outnp;
}
r = usb_autopm_get_interface(desc->intf);
if (r < 0) {
kfree(buf);
rv = usb_translate_errors(r);
goto outnp;
}
if (!(file->f_flags & O_NONBLOCK))
r = wait_event_interruptible(desc->wait, !test_bit(WDM_IN_USE,
&desc->flags));
else
if (test_bit(WDM_IN_USE, &desc->flags))
r = -EAGAIN;
if (test_bit(WDM_RESETTING, &desc->flags))
r = -EIO;
if (r < 0) {
kfree(buf);
rv = r;
goto out;
}
req = desc->orq;
usb_fill_control_urb(
desc->command,
interface_to_usbdev(desc->intf),
usb_sndctrlpipe(interface_to_usbdev(desc->intf), 0),
(unsigned char *)req,
buf,
count,
wdm_out_callback,
desc
);
req->bRequestType = (USB_DIR_OUT | USB_TYPE_CLASS |
USB_RECIP_INTERFACE);
req->bRequest = USB_CDC_SEND_ENCAPSULATED_COMMAND;
req->wValue = 0;
req->wIndex = desc->inum;
req->wLength = cpu_to_le16(count);
set_bit(WDM_IN_USE, &desc->flags);
desc->outbuf = buf;
rv = usb_submit_urb(desc->command, GFP_KERNEL);
if (rv < 0) {
kfree(buf);
desc->outbuf = NULL;
clear_bit(WDM_IN_USE, &desc->flags);
dev_err(&desc->intf->dev, "Tx URB error: %d\n", rv);
rv = usb_translate_errors(rv);
} else {
dev_dbg(&desc->intf->dev, "Tx URB has been submitted index=%d",
req->wIndex);
}
out:
usb_autopm_put_interface(desc->intf);
outnp:
mutex_unlock(&desc->wlock);
outnl:
return rv < 0 ? rv : count;
}
static ssize_t wdm_read
(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
int rv, cntr;
int i = 0;
struct wdm_device *desc = file->private_data;
rv = mutex_lock_interruptible(&desc->rlock);
if (rv < 0)
return -ERESTARTSYS;
cntr = ACCESS_ONCE(desc->length);
if (cntr == 0) {
desc->read = 0;
retry:
if (test_bit(WDM_DISCONNECTING, &desc->flags)) {
rv = -ENODEV;
goto err;
}
if (test_bit(WDM_OVERFLOW, &desc->flags)) {
clear_bit(WDM_OVERFLOW, &desc->flags);
rv = -ENOBUFS;
goto err;
}
i++;
if (file->f_flags & O_NONBLOCK) {
if (!test_bit(WDM_READ, &desc->flags)) {
rv = cntr ? cntr : -EAGAIN;
goto err;
}
rv = 0;
} else {
rv = wait_event_interruptible(desc->wait,
test_bit(WDM_READ, &desc->flags));
}
if (test_bit(WDM_DISCONNECTING, &desc->flags)) {
rv = -ENODEV;
goto err;
}
if (test_bit(WDM_RESETTING, &desc->flags)) {
rv = -EIO;
goto err;
}
usb_mark_last_busy(interface_to_usbdev(desc->intf));
if (rv < 0) {
rv = -ERESTARTSYS;
goto err;
}
spin_lock_irq(&desc->iuspin);
if (desc->rerr) {
desc->rerr = 0;
spin_unlock_irq(&desc->iuspin);
rv = -EIO;
goto err;
}
if (!test_bit(WDM_READ, &desc->flags)) {
spin_unlock_irq(&desc->iuspin);
goto retry;
}
if (!desc->reslength) {
dev_dbg(&desc->intf->dev, "%s: zero length - clearing WDM_READ\n", __func__);
clear_bit(WDM_READ, &desc->flags);
spin_unlock_irq(&desc->iuspin);
goto retry;
}
cntr = desc->length;
spin_unlock_irq(&desc->iuspin);
}
if (cntr > count)
cntr = count;
rv = copy_to_user(buffer, desc->ubuf, cntr);
if (rv > 0) {
rv = -EFAULT;
goto err;
}
spin_lock_irq(&desc->iuspin);
for (i = 0; i < desc->length - cntr; i++)
desc->ubuf[i] = desc->ubuf[i + cntr];
desc->length -= cntr;
if (!desc->length)
clear_bit(WDM_READ, &desc->flags);
spin_unlock_irq(&desc->iuspin);
rv = cntr;
err:
mutex_unlock(&desc->rlock);
return rv;
}
static int wdm_flush(struct file *file, fl_owner_t id)
{
struct wdm_device *desc = file->private_data;
wait_event(desc->wait, !test_bit(WDM_IN_USE, &desc->flags));
if (desc->werr < 0 && !test_bit(WDM_DISCONNECTING, &desc->flags))
dev_err(&desc->intf->dev, "Error in flush path: %d\n",
desc->werr);
return usb_translate_errors(desc->werr);
}
static unsigned int wdm_poll(struct file *file, struct poll_table_struct *wait)
{
struct wdm_device *desc = file->private_data;
unsigned long flags;
unsigned int mask = 0;
spin_lock_irqsave(&desc->iuspin, flags);
if (test_bit(WDM_DISCONNECTING, &desc->flags)) {
mask = POLLHUP | POLLERR;
spin_unlock_irqrestore(&desc->iuspin, flags);
goto desc_out;
}
if (test_bit(WDM_READ, &desc->flags))
mask = POLLIN | POLLRDNORM;
if (desc->rerr || desc->werr)
mask |= POLLERR;
if (!test_bit(WDM_IN_USE, &desc->flags))
mask |= POLLOUT | POLLWRNORM;
spin_unlock_irqrestore(&desc->iuspin, flags);
poll_wait(file, &desc->wait, wait);
desc_out:
return mask;
}
static int wdm_open(struct inode *inode, struct file *file)
{
int minor = iminor(inode);
int rv = -ENODEV;
struct usb_interface *intf;
struct wdm_device *desc;
mutex_lock(&wdm_mutex);
desc = wdm_find_device_by_minor(minor);
if (!desc)
goto out;
intf = desc->intf;
if (test_bit(WDM_DISCONNECTING, &desc->flags))
goto out;
file->private_data = desc;
rv = usb_autopm_get_interface(desc->intf);
if (rv < 0) {
dev_err(&desc->intf->dev, "Error autopm - %d\n", rv);
goto out;
}
mutex_lock(&desc->wlock);
if (!desc->count++) {
desc->werr = 0;
desc->rerr = 0;
rv = usb_submit_urb(desc->validity, GFP_KERNEL);
if (rv < 0) {
desc->count--;
dev_err(&desc->intf->dev,
"Error submitting int urb - %d\n", rv);
rv = usb_translate_errors(rv);
}
} else {
rv = 0;
}
mutex_unlock(&desc->wlock);
if (desc->count == 1)
desc->manage_power(intf, 1);
usb_autopm_put_interface(desc->intf);
out:
mutex_unlock(&wdm_mutex);
return rv;
}
static int wdm_release(struct inode *inode, struct file *file)
{
struct wdm_device *desc = file->private_data;
mutex_lock(&wdm_mutex);
mutex_lock(&desc->wlock);
desc->count--;
mutex_unlock(&desc->wlock);
if (!desc->count) {
if (!test_bit(WDM_DISCONNECTING, &desc->flags)) {
dev_dbg(&desc->intf->dev, "wdm_release: cleanup");
kill_urbs(desc);
desc->manage_power(desc->intf, 0);
} else {
pr_debug(KBUILD_MODNAME " %s: device gone - cleaning up\n", __func__);
cleanup(desc);
}
}
mutex_unlock(&wdm_mutex);
return 0;
}
static long wdm_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct wdm_device *desc = file->private_data;
int rv = 0;
switch (cmd) {
case IOCTL_WDM_MAX_COMMAND:
if (copy_to_user((void __user *)arg, &desc->wMaxCommand, sizeof(desc->wMaxCommand)))
rv = -EFAULT;
break;
default:
rv = -ENOTTY;
}
return rv;
}
static void wdm_rxwork(struct work_struct *work)
{
struct wdm_device *desc = container_of(work, struct wdm_device, rxwork);
unsigned long flags;
int rv = 0;
int responding;
spin_lock_irqsave(&desc->iuspin, flags);
if (test_bit(WDM_DISCONNECTING, &desc->flags)) {
spin_unlock_irqrestore(&desc->iuspin, flags);
} else {
responding = test_and_set_bit(WDM_RESPONDING, &desc->flags);
spin_unlock_irqrestore(&desc->iuspin, flags);
if (!responding)
rv = usb_submit_urb(desc->response, GFP_KERNEL);
if (rv < 0 && rv != -EPERM) {
spin_lock_irqsave(&desc->iuspin, flags);
clear_bit(WDM_RESPONDING, &desc->flags);
if (!test_bit(WDM_DISCONNECTING, &desc->flags))
schedule_work(&desc->rxwork);
spin_unlock_irqrestore(&desc->iuspin, flags);
}
}
}
static int wdm_create(struct usb_interface *intf, struct usb_endpoint_descriptor *ep,
u16 bufsize, int (*manage_power)(struct usb_interface *, int))
{
int rv = -ENOMEM;
struct wdm_device *desc;
desc = kzalloc(sizeof(struct wdm_device), GFP_KERNEL);
if (!desc)
goto out;
INIT_LIST_HEAD(&desc->device_list);
mutex_init(&desc->rlock);
mutex_init(&desc->wlock);
spin_lock_init(&desc->iuspin);
init_waitqueue_head(&desc->wait);
desc->wMaxCommand = bufsize;
desc->inum = cpu_to_le16((u16)intf->cur_altsetting->desc.bInterfaceNumber);
desc->intf = intf;
INIT_WORK(&desc->rxwork, wdm_rxwork);
rv = -EINVAL;
if (!usb_endpoint_is_int_in(ep))
goto err;
desc->wMaxPacketSize = usb_endpoint_maxp(ep);
desc->orq = kmalloc(sizeof(struct usb_ctrlrequest), GFP_KERNEL);
if (!desc->orq)
goto err;
desc->irq = kmalloc(sizeof(struct usb_ctrlrequest), GFP_KERNEL);
if (!desc->irq)
goto err;
desc->validity = usb_alloc_urb(0, GFP_KERNEL);
if (!desc->validity)
goto err;
desc->response = usb_alloc_urb(0, GFP_KERNEL);
if (!desc->response)
goto err;
desc->command = usb_alloc_urb(0, GFP_KERNEL);
if (!desc->command)
goto err;
desc->ubuf = kmalloc(desc->wMaxCommand, GFP_KERNEL);
if (!desc->ubuf)
goto err;
desc->sbuf = kmalloc(desc->wMaxPacketSize, GFP_KERNEL);
if (!desc->sbuf)
goto err;
desc->inbuf = kmalloc(desc->wMaxCommand, GFP_KERNEL);
if (!desc->inbuf)
goto err;
usb_fill_int_urb(
desc->validity,
interface_to_usbdev(intf),
usb_rcvintpipe(interface_to_usbdev(intf), ep->bEndpointAddress),
desc->sbuf,
desc->wMaxPacketSize,
wdm_int_callback,
desc,
ep->bInterval
);
desc->irq->bRequestType = (USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE);
desc->irq->bRequest = USB_CDC_GET_ENCAPSULATED_RESPONSE;
desc->irq->wValue = 0;
desc->irq->wIndex = desc->inum;
desc->irq->wLength = cpu_to_le16(desc->wMaxCommand);
usb_fill_control_urb(
desc->response,
interface_to_usbdev(intf),
usb_rcvctrlpipe(interface_to_usbdev(desc->intf), 0),
(unsigned char *)desc->irq,
desc->inbuf,
desc->wMaxCommand,
wdm_in_callback,
desc
);
desc->manage_power = manage_power;
spin_lock(&wdm_device_list_lock);
list_add(&desc->device_list, &wdm_device_list);
spin_unlock(&wdm_device_list_lock);
rv = usb_register_dev(intf, &wdm_class);
if (rv < 0)
goto err;
else
dev_info(&intf->dev, "%s: USB WDM device\n", dev_name(intf->usb_dev));
out:
return rv;
err:
spin_lock(&wdm_device_list_lock);
list_del(&desc->device_list);
spin_unlock(&wdm_device_list_lock);
cleanup(desc);
return rv;
}
static int wdm_manage_power(struct usb_interface *intf, int on)
{
int rv = usb_autopm_get_interface(intf);
if (rv < 0)
goto err;
intf->needs_remote_wakeup = on;
usb_autopm_put_interface(intf);
err:
return rv;
}
static int wdm_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
int rv = -EINVAL;
struct usb_host_interface *iface;
struct usb_endpoint_descriptor *ep;
struct usb_cdc_dmm_desc *dmhd;
u8 *buffer = intf->altsetting->extra;
int buflen = intf->altsetting->extralen;
u16 maxcom = WDM_DEFAULT_BUFSIZE;
if (!buffer)
goto err;
while (buflen > 2) {
if (buffer[1] != USB_DT_CS_INTERFACE) {
dev_err(&intf->dev, "skipping garbage\n");
goto next_desc;
}
switch (buffer[2]) {
case USB_CDC_HEADER_TYPE:
break;
case USB_CDC_DMM_TYPE:
dmhd = (struct usb_cdc_dmm_desc *)buffer;
maxcom = le16_to_cpu(dmhd->wMaxCommand);
dev_dbg(&intf->dev,
"Finding maximum buffer length: %d", maxcom);
break;
default:
dev_err(&intf->dev,
"Ignoring extra header, type %d, length %d\n",
buffer[2], buffer[0]);
break;
}
next_desc:
buflen -= buffer[0];
buffer += buffer[0];
}
iface = intf->cur_altsetting;
if (iface->desc.bNumEndpoints != 1)
goto err;
ep = &iface->endpoint[0].desc;
rv = wdm_create(intf, ep, maxcom, &wdm_manage_power);
err:
return rv;
}
struct usb_driver *usb_cdc_wdm_register(struct usb_interface *intf,
struct usb_endpoint_descriptor *ep,
int bufsize,
int (*manage_power)(struct usb_interface *, int))
{
int rv = -EINVAL;
rv = wdm_create(intf, ep, bufsize, manage_power);
if (rv < 0)
goto err;
return &wdm_driver;
err:
return ERR_PTR(rv);
}
static void wdm_disconnect(struct usb_interface *intf)
{
struct wdm_device *desc;
unsigned long flags;
usb_deregister_dev(intf, &wdm_class);
desc = wdm_find_device(intf);
mutex_lock(&wdm_mutex);
spin_lock_irqsave(&desc->iuspin, flags);
set_bit(WDM_DISCONNECTING, &desc->flags);
set_bit(WDM_READ, &desc->flags);
clear_bit(WDM_IN_USE, &desc->flags);
spin_unlock_irqrestore(&desc->iuspin, flags);
wake_up_all(&desc->wait);
mutex_lock(&desc->rlock);
mutex_lock(&desc->wlock);
kill_urbs(desc);
cancel_work_sync(&desc->rxwork);
mutex_unlock(&desc->wlock);
mutex_unlock(&desc->rlock);
spin_lock(&wdm_device_list_lock);
list_del(&desc->device_list);
spin_unlock(&wdm_device_list_lock);
if (!desc->count)
cleanup(desc);
else
dev_dbg(&intf->dev, "%s: %d open files - postponing cleanup\n", __func__, desc->count);
mutex_unlock(&wdm_mutex);
}
static int wdm_suspend(struct usb_interface *intf, pm_message_t message)
{
struct wdm_device *desc = wdm_find_device(intf);
int rv = 0;
dev_dbg(&desc->intf->dev, "wdm%d_suspend\n", intf->minor);
if (!PMSG_IS_AUTO(message)) {
mutex_lock(&desc->rlock);
mutex_lock(&desc->wlock);
}
spin_lock_irq(&desc->iuspin);
if (PMSG_IS_AUTO(message) &&
(test_bit(WDM_IN_USE, &desc->flags)
|| test_bit(WDM_RESPONDING, &desc->flags))) {
spin_unlock_irq(&desc->iuspin);
rv = -EBUSY;
} else {
set_bit(WDM_SUSPENDING, &desc->flags);
spin_unlock_irq(&desc->iuspin);
kill_urbs(desc);
cancel_work_sync(&desc->rxwork);
}
if (!PMSG_IS_AUTO(message)) {
mutex_unlock(&desc->wlock);
mutex_unlock(&desc->rlock);
}
return rv;
}
static int recover_from_urb_loss(struct wdm_device *desc)
{
int rv = 0;
if (desc->count) {
rv = usb_submit_urb(desc->validity, GFP_NOIO);
if (rv < 0)
dev_err(&desc->intf->dev,
"Error resume submitting int urb - %d\n", rv);
}
return rv;
}
static int wdm_resume(struct usb_interface *intf)
{
struct wdm_device *desc = wdm_find_device(intf);
int rv;
dev_dbg(&desc->intf->dev, "wdm%d_resume\n", intf->minor);
clear_bit(WDM_SUSPENDING, &desc->flags);
rv = recover_from_urb_loss(desc);
return rv;
}
static int wdm_pre_reset(struct usb_interface *intf)
{
struct wdm_device *desc = wdm_find_device(intf);
spin_lock_irq(&desc->iuspin);
set_bit(WDM_RESETTING, &desc->flags);
set_bit(WDM_READ, &desc->flags);
clear_bit(WDM_IN_USE, &desc->flags);
desc->rerr = -EINTR;
spin_unlock_irq(&desc->iuspin);
wake_up_all(&desc->wait);
mutex_lock(&desc->rlock);
mutex_lock(&desc->wlock);
kill_urbs(desc);
cancel_work_sync(&desc->rxwork);
return 0;
}
static int wdm_post_reset(struct usb_interface *intf)
{
struct wdm_device *desc = wdm_find_device(intf);
int rv;
clear_bit(WDM_OVERFLOW, &desc->flags);
clear_bit(WDM_RESETTING, &desc->flags);
rv = recover_from_urb_loss(desc);
mutex_unlock(&desc->wlock);
mutex_unlock(&desc->rlock);
return 0;
}
