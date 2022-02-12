static struct usb_request *
printer_req_alloc(struct usb_ep *ep, unsigned len, gfp_t gfp_flags)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, gfp_flags);
if (req != NULL) {
req->length = len;
req->buf = kmalloc(len, gfp_flags);
if (req->buf == NULL) {
usb_ep_free_request(ep, req);
return NULL;
}
}
return req;
}
static void
printer_req_free(struct usb_ep *ep, struct usb_request *req)
{
if (ep != NULL && req != NULL) {
kfree(req->buf);
usb_ep_free_request(ep, req);
}
}
static void rx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct printer_dev *dev = ep->driver_data;
int status = req->status;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
list_del_init(&req->list);
switch (status) {
case 0:
if (req->actual > 0) {
list_add_tail(&req->list, &dev->rx_buffers);
DBG(dev, "G_Printer : rx length %d\n", req->actual);
} else {
list_add(&req->list, &dev->rx_reqs);
}
break;
case -ECONNRESET:
case -ESHUTDOWN:
VDBG(dev, "rx shutdown, code %d\n", status);
list_add(&req->list, &dev->rx_reqs);
break;
case -ECONNABORTED:
DBG(dev, "rx %s reset\n", ep->name);
list_add(&req->list, &dev->rx_reqs);
break;
case -EOVERFLOW:
default:
DBG(dev, "rx status %d\n", status);
list_add(&req->list, &dev->rx_reqs);
break;
}
wake_up_interruptible(&dev->rx_wait);
spin_unlock_irqrestore(&dev->lock, flags);
}
static void tx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct printer_dev *dev = ep->driver_data;
switch (req->status) {
default:
VDBG(dev, "tx err %d\n", req->status);
case -ECONNRESET:
case -ESHUTDOWN:
break;
case 0:
break;
}
spin_lock(&dev->lock);
list_del_init(&req->list);
list_add(&req->list, &dev->tx_reqs);
wake_up_interruptible(&dev->tx_wait);
if (likely(list_empty(&dev->tx_reqs_active)))
wake_up_interruptible(&dev->tx_flush_wait);
spin_unlock(&dev->lock);
}
static int
printer_open(struct inode *inode, struct file *fd)
{
struct printer_dev *dev;
unsigned long flags;
int ret = -EBUSY;
mutex_lock(&printer_mutex);
dev = container_of(inode->i_cdev, struct printer_dev, printer_cdev);
spin_lock_irqsave(&dev->lock, flags);
if (!dev->printer_cdev_open) {
dev->printer_cdev_open = 1;
fd->private_data = dev;
ret = 0;
dev->printer_status |= PRINTER_SELECTED;
}
spin_unlock_irqrestore(&dev->lock, flags);
DBG(dev, "printer_open returned %x\n", ret);
mutex_unlock(&printer_mutex);
return ret;
}
static int
printer_close(struct inode *inode, struct file *fd)
{
struct printer_dev *dev = fd->private_data;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
dev->printer_cdev_open = 0;
fd->private_data = NULL;
dev->printer_status &= ~PRINTER_SELECTED;
spin_unlock_irqrestore(&dev->lock, flags);
DBG(dev, "printer_close\n");
return 0;
}
static void
setup_rx_reqs(struct printer_dev *dev)
{
struct usb_request *req;
while (likely(!list_empty(&dev->rx_reqs))) {
int error;
req = container_of(dev->rx_reqs.next,
struct usb_request, list);
list_del_init(&req->list);
req->length = USB_BUFSIZE;
req->complete = rx_complete;
spin_unlock(&dev->lock);
error = usb_ep_queue(dev->out_ep, req, GFP_ATOMIC);
spin_lock(&dev->lock);
if (error) {
DBG(dev, "rx submit --> %d\n", error);
list_add(&req->list, &dev->rx_reqs);
break;
}
else if (list_empty(&req->list)) {
list_add(&req->list, &dev->rx_reqs_active);
}
}
}
static ssize_t
printer_read(struct file *fd, char __user *buf, size_t len, loff_t *ptr)
{
struct printer_dev *dev = fd->private_data;
unsigned long flags;
size_t size;
size_t bytes_copied;
struct usb_request *req;
struct usb_request *current_rx_req;
size_t current_rx_bytes;
u8 *current_rx_buf;
if (len == 0)
return -EINVAL;
DBG(dev, "printer_read trying to read %d bytes\n", (int)len);
mutex_lock(&dev->lock_printer_io);
spin_lock_irqsave(&dev->lock, flags);
dev->reset_printer = 0;
setup_rx_reqs(dev);
bytes_copied = 0;
current_rx_req = dev->current_rx_req;
current_rx_bytes = dev->current_rx_bytes;
current_rx_buf = dev->current_rx_buf;
dev->current_rx_req = NULL;
dev->current_rx_bytes = 0;
dev->current_rx_buf = NULL;
if ((current_rx_bytes == 0) &&
(likely(list_empty(&dev->rx_buffers)))) {
spin_unlock_irqrestore(&dev->lock, flags);
if (fd->f_flags & (O_NONBLOCK|O_NDELAY)) {
mutex_unlock(&dev->lock_printer_io);
return -EAGAIN;
}
wait_event_interruptible(dev->rx_wait,
(likely(!list_empty(&dev->rx_buffers))));
spin_lock_irqsave(&dev->lock, flags);
}
while ((current_rx_bytes || likely(!list_empty(&dev->rx_buffers)))
&& len) {
if (current_rx_bytes == 0) {
req = container_of(dev->rx_buffers.next,
struct usb_request, list);
list_del_init(&req->list);
if (req->actual && req->buf) {
current_rx_req = req;
current_rx_bytes = req->actual;
current_rx_buf = req->buf;
} else {
list_add(&req->list, &dev->rx_reqs);
continue;
}
}
spin_unlock_irqrestore(&dev->lock, flags);
if (len > current_rx_bytes)
size = current_rx_bytes;
else
size = len;
size -= copy_to_user(buf, current_rx_buf, size);
bytes_copied += size;
len -= size;
buf += size;
spin_lock_irqsave(&dev->lock, flags);
if (dev->reset_printer) {
list_add(&current_rx_req->list, &dev->rx_reqs);
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
return -EAGAIN;
}
if (size < current_rx_bytes) {
current_rx_bytes -= size;
current_rx_buf += size;
} else {
list_add(&current_rx_req->list, &dev->rx_reqs);
current_rx_bytes = 0;
current_rx_buf = NULL;
current_rx_req = NULL;
}
}
dev->current_rx_req = current_rx_req;
dev->current_rx_bytes = current_rx_bytes;
dev->current_rx_buf = current_rx_buf;
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
DBG(dev, "printer_read returned %d bytes\n", (int)bytes_copied);
if (bytes_copied)
return bytes_copied;
else
return -EAGAIN;
}
static ssize_t
printer_write(struct file *fd, const char __user *buf, size_t len, loff_t *ptr)
{
struct printer_dev *dev = fd->private_data;
unsigned long flags;
size_t size;
size_t bytes_copied = 0;
struct usb_request *req;
DBG(dev, "printer_write trying to send %d bytes\n", (int)len);
if (len == 0)
return -EINVAL;
mutex_lock(&dev->lock_printer_io);
spin_lock_irqsave(&dev->lock, flags);
dev->reset_printer = 0;
if (likely(list_empty(&dev->tx_reqs))) {
spin_unlock_irqrestore(&dev->lock, flags);
if (fd->f_flags & (O_NONBLOCK|O_NDELAY)) {
mutex_unlock(&dev->lock_printer_io);
return -EAGAIN;
}
wait_event_interruptible(dev->tx_wait,
(likely(!list_empty(&dev->tx_reqs))));
spin_lock_irqsave(&dev->lock, flags);
}
while (likely(!list_empty(&dev->tx_reqs)) && len) {
if (len > USB_BUFSIZE)
size = USB_BUFSIZE;
else
size = len;
req = container_of(dev->tx_reqs.next, struct usb_request,
list);
list_del_init(&req->list);
req->complete = tx_complete;
req->length = size;
if (len > size)
req->zero = 0;
else
req->zero = ((len % dev->in_ep->maxpacket) == 0);
spin_unlock_irqrestore(&dev->lock, flags);
if (copy_from_user(req->buf, buf, size)) {
list_add(&req->list, &dev->tx_reqs);
mutex_unlock(&dev->lock_printer_io);
return bytes_copied;
}
bytes_copied += size;
len -= size;
buf += size;
spin_lock_irqsave(&dev->lock, flags);
if (dev->reset_printer) {
list_add(&req->list, &dev->tx_reqs);
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
return -EAGAIN;
}
if (usb_ep_queue(dev->in_ep, req, GFP_ATOMIC)) {
list_add(&req->list, &dev->tx_reqs);
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
return -EAGAIN;
}
list_add(&req->list, &dev->tx_reqs_active);
}
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
DBG(dev, "printer_write sent %d bytes\n", (int)bytes_copied);
if (bytes_copied) {
return bytes_copied;
} else {
return -EAGAIN;
}
}
static int
printer_fsync(struct file *fd, loff_t start, loff_t end, int datasync)
{
struct printer_dev *dev = fd->private_data;
struct inode *inode = file_inode(fd);
unsigned long flags;
int tx_list_empty;
mutex_lock(&inode->i_mutex);
spin_lock_irqsave(&dev->lock, flags);
tx_list_empty = (likely(list_empty(&dev->tx_reqs)));
spin_unlock_irqrestore(&dev->lock, flags);
if (!tx_list_empty) {
wait_event_interruptible(dev->tx_flush_wait,
(likely(list_empty(&dev->tx_reqs_active))));
}
mutex_unlock(&inode->i_mutex);
return 0;
}
static unsigned int
printer_poll(struct file *fd, poll_table *wait)
{
struct printer_dev *dev = fd->private_data;
unsigned long flags;
int status = 0;
mutex_lock(&dev->lock_printer_io);
spin_lock_irqsave(&dev->lock, flags);
setup_rx_reqs(dev);
spin_unlock_irqrestore(&dev->lock, flags);
mutex_unlock(&dev->lock_printer_io);
poll_wait(fd, &dev->rx_wait, wait);
poll_wait(fd, &dev->tx_wait, wait);
spin_lock_irqsave(&dev->lock, flags);
if (likely(!list_empty(&dev->tx_reqs)))
status |= POLLOUT | POLLWRNORM;
if (likely(dev->current_rx_bytes) ||
likely(!list_empty(&dev->rx_buffers)))
status |= POLLIN | POLLRDNORM;
spin_unlock_irqrestore(&dev->lock, flags);
return status;
}
static long
printer_ioctl(struct file *fd, unsigned int code, unsigned long arg)
{
struct printer_dev *dev = fd->private_data;
unsigned long flags;
int status = 0;
DBG(dev, "printer_ioctl: cmd=0x%4.4x, arg=%lu\n", code, arg);
spin_lock_irqsave(&dev->lock, flags);
switch (code) {
case GADGET_GET_PRINTER_STATUS:
status = (int)dev->printer_status;
break;
case GADGET_SET_PRINTER_STATUS:
dev->printer_status = (u8)arg;
break;
default:
DBG(dev, "printer_ioctl: ERROR cmd=0x%4.4xis not supported\n",
code);
status = -ENOTTY;
}
spin_unlock_irqrestore(&dev->lock, flags);
return status;
}
static int
set_printer_interface(struct printer_dev *dev)
{
int result = 0;
dev->in_ep->desc = ep_desc(dev->gadget, &hs_ep_in_desc, &fs_ep_in_desc);
dev->in_ep->driver_data = dev;
dev->out_ep->desc = ep_desc(dev->gadget, &hs_ep_out_desc,
&fs_ep_out_desc);
dev->out_ep->driver_data = dev;
result = usb_ep_enable(dev->in_ep);
if (result != 0) {
DBG(dev, "enable %s --> %d\n", dev->in_ep->name, result);
goto done;
}
result = usb_ep_enable(dev->out_ep);
if (result != 0) {
DBG(dev, "enable %s --> %d\n", dev->in_ep->name, result);
goto done;
}
done:
if (result != 0) {
(void) usb_ep_disable(dev->in_ep);
(void) usb_ep_disable(dev->out_ep);
dev->in_ep->desc = NULL;
dev->out_ep->desc = NULL;
}
return result;
}
static void printer_reset_interface(struct printer_dev *dev)
{
if (dev->interface < 0)
return;
DBG(dev, "%s\n", __func__);
if (dev->in_ep->desc)
usb_ep_disable(dev->in_ep);
if (dev->out_ep->desc)
usb_ep_disable(dev->out_ep);
dev->in_ep->desc = NULL;
dev->out_ep->desc = NULL;
dev->interface = -1;
}
static int set_interface(struct printer_dev *dev, unsigned number)
{
int result = 0;
printer_reset_interface(dev);
result = set_printer_interface(dev);
if (result)
printer_reset_interface(dev);
else
dev->interface = number;
if (!result)
INFO(dev, "Using interface %x\n", number);
return result;
}
static void printer_soft_reset(struct printer_dev *dev)
{
struct usb_request *req;
INFO(dev, "Received Printer Reset Request\n");
if (usb_ep_disable(dev->in_ep))
DBG(dev, "Failed to disable USB in_ep\n");
if (usb_ep_disable(dev->out_ep))
DBG(dev, "Failed to disable USB out_ep\n");
if (dev->current_rx_req != NULL) {
list_add(&dev->current_rx_req->list, &dev->rx_reqs);
dev->current_rx_req = NULL;
}
dev->current_rx_bytes = 0;
dev->current_rx_buf = NULL;
dev->reset_printer = 1;
while (likely(!(list_empty(&dev->rx_buffers)))) {
req = container_of(dev->rx_buffers.next, struct usb_request,
list);
list_del_init(&req->list);
list_add(&req->list, &dev->rx_reqs);
}
while (likely(!(list_empty(&dev->rx_reqs_active)))) {
req = container_of(dev->rx_buffers.next, struct usb_request,
list);
list_del_init(&req->list);
list_add(&req->list, &dev->rx_reqs);
}
while (likely(!(list_empty(&dev->tx_reqs_active)))) {
req = container_of(dev->tx_reqs_active.next,
struct usb_request, list);
list_del_init(&req->list);
list_add(&req->list, &dev->tx_reqs);
}
if (usb_ep_enable(dev->in_ep))
DBG(dev, "Failed to enable USB in_ep\n");
if (usb_ep_enable(dev->out_ep))
DBG(dev, "Failed to enable USB out_ep\n");
wake_up_interruptible(&dev->rx_wait);
wake_up_interruptible(&dev->tx_wait);
wake_up_interruptible(&dev->tx_flush_wait);
}
static int printer_func_setup(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct printer_dev *dev = container_of(f, struct printer_dev, function);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 wIndex = le16_to_cpu(ctrl->wIndex);
u16 wValue = le16_to_cpu(ctrl->wValue);
u16 wLength = le16_to_cpu(ctrl->wLength);
DBG(dev, "ctrl req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest, wValue, wIndex, wLength);
switch (ctrl->bRequestType&USB_TYPE_MASK) {
case USB_TYPE_CLASS:
switch (ctrl->bRequest) {
case 0:
if ((wIndex>>8) != dev->interface)
break;
value = (pnp_string[0]<<8)|pnp_string[1];
memcpy(req->buf, pnp_string, value);
DBG(dev, "1284 PNP String: %x %s\n", value,
&pnp_string[2]);
break;
case 1:
if (wIndex != dev->interface)
break;
*(u8 *)req->buf = dev->printer_status;
value = min(wLength, (u16) 1);
break;
case 2:
if (wIndex != dev->interface)
break;
printer_soft_reset(dev);
value = 0;
break;
default:
goto unknown;
}
break;
default:
unknown:
VDBG(dev,
"unknown ctrl req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
wValue, wIndex, wLength);
break;
}
return value;
}
static int __init printer_func_bind(struct usb_configuration *c,
struct usb_function *f)
{
struct printer_dev *dev = container_of(f, struct printer_dev, function);
struct usb_composite_dev *cdev = c->cdev;
struct usb_ep *in_ep;
struct usb_ep *out_ep = NULL;
int id;
int ret;
id = usb_interface_id(c, f);
if (id < 0)
return id;
intf_desc.bInterfaceNumber = id;
in_ep = usb_ep_autoconfig(cdev->gadget, &fs_ep_in_desc);
if (!in_ep) {
autoconf_fail:
dev_err(&cdev->gadget->dev, "can't autoconfigure on %s\n",
cdev->gadget->name);
return -ENODEV;
}
in_ep->driver_data = in_ep;
out_ep = usb_ep_autoconfig(cdev->gadget, &fs_ep_out_desc);
if (!out_ep)
goto autoconf_fail;
out_ep->driver_data = out_ep;
hs_ep_in_desc.bEndpointAddress = fs_ep_in_desc.bEndpointAddress;
hs_ep_out_desc.bEndpointAddress = fs_ep_out_desc.bEndpointAddress;
ret = usb_assign_descriptors(f, fs_printer_function,
hs_printer_function, NULL);
if (ret)
return ret;
dev->in_ep = in_ep;
dev->out_ep = out_ep;
return 0;
}
static void printer_func_unbind(struct usb_configuration *c,
struct usb_function *f)
{
usb_free_all_descriptors(f);
}
static int printer_func_set_alt(struct usb_function *f,
unsigned intf, unsigned alt)
{
struct printer_dev *dev = container_of(f, struct printer_dev, function);
int ret = -ENOTSUPP;
if (!alt)
ret = set_interface(dev, intf);
return ret;
}
static void printer_func_disable(struct usb_function *f)
{
struct printer_dev *dev = container_of(f, struct printer_dev, function);
unsigned long flags;
DBG(dev, "%s\n", __func__);
spin_lock_irqsave(&dev->lock, flags);
printer_reset_interface(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
static void printer_cfg_unbind(struct usb_configuration *c)
{
struct printer_dev *dev;
struct usb_request *req;
dev = &usb_printer_gadget;
DBG(dev, "%s\n", __func__);
device_destroy(usb_gadget_class, g_printer_devno);
cdev_del(&dev->printer_cdev);
WARN_ON(!list_empty(&dev->tx_reqs_active));
WARN_ON(!list_empty(&dev->rx_reqs_active));
while (!list_empty(&dev->tx_reqs)) {
req = container_of(dev->tx_reqs.next, struct usb_request,
list);
list_del(&req->list);
printer_req_free(dev->in_ep, req);
}
if (dev->current_rx_req != NULL)
printer_req_free(dev->out_ep, dev->current_rx_req);
while (!list_empty(&dev->rx_reqs)) {
req = container_of(dev->rx_reqs.next,
struct usb_request, list);
list_del(&req->list);
printer_req_free(dev->out_ep, req);
}
while (!list_empty(&dev->rx_buffers)) {
req = container_of(dev->rx_buffers.next,
struct usb_request, list);
list_del(&req->list);
printer_req_free(dev->out_ep, req);
}
}
static int __init printer_bind_config(struct usb_configuration *c)
{
struct usb_gadget *gadget = c->cdev->gadget;
struct printer_dev *dev;
int status = -ENOMEM;
size_t len;
u32 i;
struct usb_request *req;
usb_ep_autoconfig_reset(gadget);
dev = &usb_printer_gadget;
dev->function.name = shortname;
dev->function.bind = printer_func_bind;
dev->function.setup = printer_func_setup;
dev->function.unbind = printer_func_unbind;
dev->function.set_alt = printer_func_set_alt;
dev->function.disable = printer_func_disable;
status = usb_add_function(c, &dev->function);
if (status)
return status;
dev->pdev = device_create(usb_gadget_class, NULL, g_printer_devno,
NULL, "g_printer");
if (IS_ERR(dev->pdev)) {
ERROR(dev, "Failed to create device: g_printer\n");
status = PTR_ERR(dev->pdev);
goto fail;
}
cdev_init(&dev->printer_cdev, &printer_io_operations);
dev->printer_cdev.owner = THIS_MODULE;
status = cdev_add(&dev->printer_cdev, g_printer_devno, 1);
if (status) {
ERROR(dev, "Failed to open char device\n");
goto fail;
}
if (iPNPstring)
strlcpy(&pnp_string[2], iPNPstring, (sizeof pnp_string)-2);
len = strlen(pnp_string);
pnp_string[0] = (len >> 8) & 0xFF;
pnp_string[1] = len & 0xFF;
usb_gadget_set_selfpowered(gadget);
if (gadget_is_otg(gadget)) {
otg_descriptor.bmAttributes |= USB_OTG_HNP;
printer_cfg_driver.descriptors = otg_desc;
printer_cfg_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
spin_lock_init(&dev->lock);
mutex_init(&dev->lock_printer_io);
INIT_LIST_HEAD(&dev->tx_reqs);
INIT_LIST_HEAD(&dev->tx_reqs_active);
INIT_LIST_HEAD(&dev->rx_reqs);
INIT_LIST_HEAD(&dev->rx_reqs_active);
INIT_LIST_HEAD(&dev->rx_buffers);
init_waitqueue_head(&dev->rx_wait);
init_waitqueue_head(&dev->tx_wait);
init_waitqueue_head(&dev->tx_flush_wait);
dev->interface = -1;
dev->printer_cdev_open = 0;
dev->printer_status = PRINTER_NOT_ERROR;
dev->current_rx_req = NULL;
dev->current_rx_bytes = 0;
dev->current_rx_buf = NULL;
for (i = 0; i < QLEN; i++) {
req = printer_req_alloc(dev->in_ep, USB_BUFSIZE, GFP_KERNEL);
if (!req) {
while (!list_empty(&dev->tx_reqs)) {
req = container_of(dev->tx_reqs.next,
struct usb_request, list);
list_del(&req->list);
printer_req_free(dev->in_ep, req);
}
return -ENOMEM;
}
list_add(&req->list, &dev->tx_reqs);
}
for (i = 0; i < QLEN; i++) {
req = printer_req_alloc(dev->out_ep, USB_BUFSIZE, GFP_KERNEL);
if (!req) {
while (!list_empty(&dev->rx_reqs)) {
req = container_of(dev->rx_reqs.next,
struct usb_request, list);
list_del(&req->list);
printer_req_free(dev->out_ep, req);
}
return -ENOMEM;
}
list_add(&req->list, &dev->rx_reqs);
}
dev->gadget = gadget;
INFO(dev, "%s, version: " DRIVER_VERSION "\n", driver_desc);
return 0;
fail:
printer_cfg_unbind(c);
return status;
}
static int printer_unbind(struct usb_composite_dev *cdev)
{
return 0;
}
static int __init printer_bind(struct usb_composite_dev *cdev)
{
int ret;
ret = usb_string_ids_tab(cdev, strings);
if (ret < 0)
return ret;
device_desc.iManufacturer = strings[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings[USB_GADGET_PRODUCT_IDX].id;
device_desc.iSerialNumber = strings[USB_GADGET_SERIAL_IDX].id;
ret = usb_add_config(cdev, &printer_cfg_driver, printer_bind_config);
if (ret)
return ret;
usb_composite_overwrite_options(cdev, &coverwrite);
return ret;
}
static int __init
init(void)
{
int status;
usb_gadget_class = class_create(THIS_MODULE, "usb_printer_gadget");
if (IS_ERR(usb_gadget_class)) {
status = PTR_ERR(usb_gadget_class);
pr_err("unable to create usb_gadget class %d\n", status);
return status;
}
status = alloc_chrdev_region(&g_printer_devno, 0, 1,
"USB printer gadget");
if (status) {
pr_err("alloc_chrdev_region %d\n", status);
class_destroy(usb_gadget_class);
return status;
}
status = usb_composite_probe(&printer_driver);
if (status) {
class_destroy(usb_gadget_class);
unregister_chrdev_region(g_printer_devno, 1);
pr_err("usb_gadget_probe_driver %x\n", status);
}
return status;
}
static void __exit
cleanup(void)
{
mutex_lock(&usb_printer_gadget.lock_printer_io);
usb_composite_unregister(&printer_driver);
unregister_chrdev_region(g_printer_devno, 1);
class_destroy(usb_gadget_class);
mutex_unlock(&usb_printer_gadget.lock_printer_io);
}
