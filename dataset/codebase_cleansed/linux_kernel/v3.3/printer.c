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
error = usb_ep_queue(dev->out_ep, req, GFP_ATOMIC);
if (error) {
DBG(dev, "rx submit --> %d\n", error);
list_add(&req->list, &dev->rx_reqs);
break;
} else {
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
struct inode *inode = fd->f_path.dentry->d_inode;
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
static int
printer_set_config(struct printer_dev *dev, unsigned number)
{
int result = 0;
struct usb_gadget *gadget = dev->gadget;
switch (number) {
case DEV_CONFIG_VALUE:
result = 0;
break;
default:
result = -EINVAL;
case 0:
break;
}
if (result) {
usb_gadget_vbus_draw(dev->gadget,
dev->gadget->is_otg ? 8 : 100);
} else {
unsigned power;
power = 2 * config_desc.bMaxPower;
usb_gadget_vbus_draw(dev->gadget, power);
dev->config = number;
INFO(dev, "%s config #%d: %d mA, %s\n",
usb_speed_string(gadget->speed),
number, power, driver_desc);
}
return result;
}
static int
config_buf(enum usb_device_speed speed, u8 *buf, u8 type, unsigned index,
int is_otg)
{
int len;
const struct usb_descriptor_header **function;
#ifdef CONFIG_USB_GADGET_DUALSPEED
int hs = (speed == USB_SPEED_HIGH);
if (type == USB_DT_OTHER_SPEED_CONFIG)
hs = !hs;
if (hs) {
function = hs_printer_function;
} else {
function = fs_printer_function;
}
#else
function = fs_printer_function;
#endif
if (index >= device_desc.bNumConfigurations)
return -EINVAL;
if (!is_otg)
function++;
len = usb_gadget_config_buf(&config_desc, buf, USB_DESC_BUFSIZE,
function);
if (len < 0)
return len;
((struct usb_config_descriptor *) buf)->bDescriptorType = type;
return len;
}
static int
set_interface(struct printer_dev *dev, unsigned number)
{
int result = 0;
switch (dev->interface) {
case PRINTER_INTERFACE:
printer_reset_interface(dev);
break;
}
switch (number) {
case PRINTER_INTERFACE:
result = set_printer_interface(dev);
if (result) {
printer_reset_interface(dev);
} else {
dev->interface = PRINTER_INTERFACE;
}
break;
default:
result = -EINVAL;
}
if (!result)
INFO(dev, "Using interface %x\n", number);
return result;
}
static void printer_setup_complete(struct usb_ep *ep, struct usb_request *req)
{
if (req->status || req->actual != req->length)
DBG((struct printer_dev *) ep->driver_data,
"setup complete --> %d, %d/%d\n",
req->status, req->actual, req->length);
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
static int
printer_setup(struct usb_gadget *gadget, const struct usb_ctrlrequest *ctrl)
{
struct printer_dev *dev = get_gadget_data(gadget);
struct usb_request *req = dev->req;
int value = -EOPNOTSUPP;
u16 wIndex = le16_to_cpu(ctrl->wIndex);
u16 wValue = le16_to_cpu(ctrl->wValue);
u16 wLength = le16_to_cpu(ctrl->wLength);
DBG(dev, "ctrl req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest, wValue, wIndex, wLength);
req->complete = printer_setup_complete;
switch (ctrl->bRequestType&USB_TYPE_MASK) {
case USB_TYPE_STANDARD:
switch (ctrl->bRequest) {
case USB_REQ_GET_DESCRIPTOR:
if (ctrl->bRequestType != USB_DIR_IN)
break;
switch (wValue >> 8) {
case USB_DT_DEVICE:
device_desc.bMaxPacketSize0 =
gadget->ep0->maxpacket;
value = min(wLength, (u16) sizeof device_desc);
memcpy(req->buf, &device_desc, value);
break;
#ifdef CONFIG_USB_GADGET_DUALSPEED
case USB_DT_DEVICE_QUALIFIER:
if (!gadget_is_dualspeed(gadget))
break;
dev_qualifier.bMaxPacketSize0 =
gadget->ep0->maxpacket;
value = min(wLength,
(u16) sizeof dev_qualifier);
memcpy(req->buf, &dev_qualifier, value);
break;
case USB_DT_OTHER_SPEED_CONFIG:
if (!gadget_is_dualspeed(gadget))
break;
#endif
case USB_DT_CONFIG:
value = config_buf(gadget->speed, req->buf,
wValue >> 8,
wValue & 0xff,
gadget->is_otg);
if (value >= 0)
value = min(wLength, (u16) value);
break;
case USB_DT_STRING:
value = usb_gadget_get_string(&stringtab,
wValue & 0xff, req->buf);
if (value >= 0)
value = min(wLength, (u16) value);
break;
}
break;
case USB_REQ_SET_CONFIGURATION:
if (ctrl->bRequestType != 0)
break;
if (gadget->a_hnp_support)
DBG(dev, "HNP available\n");
else if (gadget->a_alt_hnp_support)
DBG(dev, "HNP needs a different root port\n");
value = printer_set_config(dev, wValue);
if (!value)
value = set_interface(dev, PRINTER_INTERFACE);
break;
case USB_REQ_GET_CONFIGURATION:
if (ctrl->bRequestType != USB_DIR_IN)
break;
*(u8 *)req->buf = dev->config;
value = min(wLength, (u16) 1);
break;
case USB_REQ_SET_INTERFACE:
if (ctrl->bRequestType != USB_RECIP_INTERFACE ||
!dev->config)
break;
value = set_interface(dev, PRINTER_INTERFACE);
break;
case USB_REQ_GET_INTERFACE:
if (ctrl->bRequestType !=
(USB_DIR_IN|USB_RECIP_INTERFACE)
|| !dev->config)
break;
*(u8 *)req->buf = dev->interface;
value = min(wLength, (u16) 1);
break;
default:
goto unknown;
}
break;
case USB_TYPE_CLASS:
switch (ctrl->bRequest) {
case 0:
if ((wIndex>>8) != PRINTER_INTERFACE)
break;
value = (pnp_string[0]<<8)|pnp_string[1];
memcpy(req->buf, pnp_string, value);
DBG(dev, "1284 PNP String: %x %s\n", value,
&pnp_string[2]);
break;
case 1:
if (wIndex != PRINTER_INTERFACE)
break;
*(u8 *)req->buf = dev->printer_status;
value = min(wLength, (u16) 1);
break;
case 2:
if (wIndex != PRINTER_INTERFACE)
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
if (value >= 0) {
req->length = value;
req->zero = value < wLength;
value = usb_ep_queue(gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
DBG(dev, "ep_queue --> %d\n", value);
req->status = 0;
printer_setup_complete(gadget->ep0, req);
}
}
return value;
}
static void
printer_disconnect(struct usb_gadget *gadget)
{
struct printer_dev *dev = get_gadget_data(gadget);
unsigned long flags;
DBG(dev, "%s\n", __func__);
spin_lock_irqsave(&dev->lock, flags);
printer_reset_interface(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
static void
printer_unbind(struct usb_gadget *gadget)
{
struct printer_dev *dev = get_gadget_data(gadget);
struct usb_request *req;
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
if (dev->req) {
printer_req_free(gadget->ep0, dev->req);
dev->req = NULL;
}
set_gadget_data(gadget, NULL);
}
static int __init
printer_bind(struct usb_gadget *gadget)
{
struct printer_dev *dev;
struct usb_ep *in_ep, *out_ep;
int status = -ENOMEM;
int gcnum;
size_t len;
u32 i;
struct usb_request *req;
dev = &usb_printer_gadget;
dev->pdev = device_create(usb_gadget_class, NULL, g_printer_devno,
NULL, "g_printer");
if (IS_ERR(dev->pdev)) {
ERROR(dev, "Failed to create device: g_printer\n");
goto fail;
}
cdev_init(&dev->printer_cdev, &printer_io_operations);
dev->printer_cdev.owner = THIS_MODULE;
status = cdev_add(&dev->printer_cdev, g_printer_devno, 1);
if (status) {
ERROR(dev, "Failed to open char device\n");
goto fail;
}
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0) {
device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
} else {
dev_warn(&gadget->dev, "controller '%s' not recognized\n",
gadget->name);
device_desc.bcdDevice =
cpu_to_le16(0xFFFF);
}
snprintf(manufacturer, sizeof(manufacturer), "%s %s with %s",
init_utsname()->sysname, init_utsname()->release,
gadget->name);
device_desc.idVendor =
cpu_to_le16(PRINTER_VENDOR_NUM);
device_desc.idProduct =
cpu_to_le16(PRINTER_PRODUCT_NUM);
if (idVendor) {
if (!idProduct) {
dev_err(&gadget->dev, "idVendor needs idProduct!\n");
return -ENODEV;
}
device_desc.idVendor = cpu_to_le16(idVendor);
device_desc.idProduct = cpu_to_le16(idProduct);
if (bcdDevice)
device_desc.bcdDevice = cpu_to_le16(bcdDevice);
}
if (iManufacturer)
strlcpy(manufacturer, iManufacturer, sizeof manufacturer);
if (iProduct)
strlcpy(product_desc, iProduct, sizeof product_desc);
if (iSerialNum)
strlcpy(serial_num, iSerialNum, sizeof serial_num);
if (iPNPstring)
strlcpy(&pnp_string[2], iPNPstring, (sizeof pnp_string)-2);
len = strlen(pnp_string);
pnp_string[0] = (len >> 8) & 0xFF;
pnp_string[1] = len & 0xFF;
usb_ep_autoconfig_reset(gadget);
in_ep = usb_ep_autoconfig(gadget, &fs_ep_in_desc);
if (!in_ep) {
autoconf_fail:
dev_err(&gadget->dev, "can't autoconfigure on %s\n",
gadget->name);
return -ENODEV;
}
in_ep->driver_data = in_ep;
out_ep = usb_ep_autoconfig(gadget, &fs_ep_out_desc);
if (!out_ep)
goto autoconf_fail;
out_ep->driver_data = out_ep;
#ifdef CONFIG_USB_GADGET_DUALSPEED
hs_ep_in_desc.bEndpointAddress = fs_ep_in_desc.bEndpointAddress;
hs_ep_out_desc.bEndpointAddress = fs_ep_out_desc.bEndpointAddress;
#endif
usb_gadget_set_selfpowered(gadget);
if (gadget->is_otg) {
otg_desc.bmAttributes |= USB_OTG_HNP,
config_desc.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
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
dev->config = 0;
dev->interface = -1;
dev->printer_cdev_open = 0;
dev->printer_status = PRINTER_NOT_ERROR;
dev->current_rx_req = NULL;
dev->current_rx_bytes = 0;
dev->current_rx_buf = NULL;
dev->in_ep = in_ep;
dev->out_ep = out_ep;
dev->req = printer_req_alloc(gadget->ep0, USB_DESC_BUFSIZE,
GFP_KERNEL);
if (!dev->req) {
status = -ENOMEM;
goto fail;
}
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
dev->req->complete = printer_setup_complete;
dev->gadget = gadget;
set_gadget_data(gadget, dev);
gadget->ep0->driver_data = dev;
INFO(dev, "%s, version: " DRIVER_VERSION "\n", driver_desc);
INFO(dev, "using %s, OUT %s IN %s\n", gadget->name, out_ep->name,
in_ep->name);
return 0;
fail:
printer_unbind(gadget);
return status;
}
static int __init
init(void)
{
int status;
usb_gadget_class = class_create(THIS_MODULE, "usb_printer_gadget");
if (IS_ERR(usb_gadget_class)) {
status = PTR_ERR(usb_gadget_class);
ERROR(dev, "unable to create usb_gadget class %d\n", status);
return status;
}
status = alloc_chrdev_region(&g_printer_devno, 0, 1,
"USB printer gadget");
if (status) {
ERROR(dev, "alloc_chrdev_region %d\n", status);
class_destroy(usb_gadget_class);
return status;
}
status = usb_gadget_probe_driver(&printer_driver, printer_bind);
if (status) {
class_destroy(usb_gadget_class);
unregister_chrdev_region(g_printer_devno, 1);
DBG(dev, "usb_gadget_probe_driver %x\n", status);
}
return status;
}
static void __exit
cleanup(void)
{
int status;
mutex_lock(&usb_printer_gadget.lock_printer_io);
status = usb_gadget_unregister_driver(&printer_driver);
if (status)
ERROR(dev, "usb_gadget_unregister_driver %x\n", status);
unregister_chrdev_region(g_printer_devno, 1);
class_destroy(usb_gadget_class);
mutex_unlock(&usb_printer_gadget.lock_printer_io);
}
