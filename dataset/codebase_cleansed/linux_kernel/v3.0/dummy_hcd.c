static inline struct dummy_ep *usb_ep_to_dummy_ep (struct usb_ep *_ep)
{
return container_of (_ep, struct dummy_ep, ep);
}
static inline struct dummy_request *usb_request_to_dummy_request
(struct usb_request *_req)
{
return container_of (_req, struct dummy_request, req);
}
static inline struct dummy *hcd_to_dummy (struct usb_hcd *hcd)
{
return (struct dummy *) (hcd->hcd_priv);
}
static inline struct usb_hcd *dummy_to_hcd (struct dummy *dum)
{
return container_of((void *) dum, struct usb_hcd, hcd_priv);
}
static inline struct device *dummy_dev (struct dummy *dum)
{
return dummy_to_hcd(dum)->self.controller;
}
static inline struct device *udc_dev (struct dummy *dum)
{
return dum->gadget.dev.parent;
}
static inline struct dummy *ep_to_dummy (struct dummy_ep *ep)
{
return container_of (ep->gadget, struct dummy, gadget);
}
static inline struct dummy *gadget_to_dummy (struct usb_gadget *gadget)
{
return container_of (gadget, struct dummy, gadget);
}
static inline struct dummy *gadget_dev_to_dummy (struct device *dev)
{
return container_of (dev, struct dummy, gadget.dev);
}
static void nuke (struct dummy *dum, struct dummy_ep *ep)
{
while (!list_empty (&ep->queue)) {
struct dummy_request *req;
req = list_entry (ep->queue.next, struct dummy_request, queue);
list_del_init (&req->queue);
req->req.status = -ESHUTDOWN;
spin_unlock (&dum->lock);
req->req.complete (&ep->ep, &req->req);
spin_lock (&dum->lock);
}
}
static void
stop_activity (struct dummy *dum)
{
struct dummy_ep *ep;
dum->address = 0;
list_for_each_entry (ep, &dum->gadget.ep_list, ep.ep_list)
nuke (dum, ep);
}
static void
set_link_state (struct dummy *dum)
{
dum->active = 0;
if ((dum->port_status & USB_PORT_STAT_POWER) == 0)
dum->port_status = 0;
else if (!dum->pullup || dum->udc_suspended) {
dum->port_status &= ~(USB_PORT_STAT_CONNECTION |
USB_PORT_STAT_ENABLE |
USB_PORT_STAT_LOW_SPEED |
USB_PORT_STAT_HIGH_SPEED |
USB_PORT_STAT_SUSPEND);
if ((dum->old_status & USB_PORT_STAT_CONNECTION) != 0)
dum->port_status |= (USB_PORT_STAT_C_CONNECTION << 16);
} else {
dum->port_status |= USB_PORT_STAT_CONNECTION;
if ((dum->old_status & USB_PORT_STAT_CONNECTION) == 0)
dum->port_status |= (USB_PORT_STAT_C_CONNECTION << 16);
if ((dum->port_status & USB_PORT_STAT_ENABLE) == 0)
dum->port_status &= ~USB_PORT_STAT_SUSPEND;
else if ((dum->port_status & USB_PORT_STAT_SUSPEND) == 0 &&
dum->rh_state != DUMMY_RH_SUSPENDED)
dum->active = 1;
}
if ((dum->port_status & USB_PORT_STAT_ENABLE) == 0 || dum->active)
dum->resuming = 0;
if ((dum->port_status & USB_PORT_STAT_CONNECTION) == 0 ||
(dum->port_status & USB_PORT_STAT_RESET) != 0) {
if ((dum->old_status & USB_PORT_STAT_CONNECTION) != 0 &&
(dum->old_status & USB_PORT_STAT_RESET) == 0 &&
dum->driver) {
stop_activity (dum);
spin_unlock (&dum->lock);
dum->driver->disconnect (&dum->gadget);
spin_lock (&dum->lock);
}
} else if (dum->active != dum->old_active) {
if (dum->old_active && dum->driver->suspend) {
spin_unlock (&dum->lock);
dum->driver->suspend (&dum->gadget);
spin_lock (&dum->lock);
} else if (!dum->old_active && dum->driver->resume) {
spin_unlock (&dum->lock);
dum->driver->resume (&dum->gadget);
spin_lock (&dum->lock);
}
}
dum->old_status = dum->port_status;
dum->old_active = dum->active;
}
static int
dummy_enable (struct usb_ep *_ep, const struct usb_endpoint_descriptor *desc)
{
struct dummy *dum;
struct dummy_ep *ep;
unsigned max;
int retval;
ep = usb_ep_to_dummy_ep (_ep);
if (!_ep || !desc || ep->desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT)
return -EINVAL;
dum = ep_to_dummy (ep);
if (!dum->driver || !is_enabled (dum))
return -ESHUTDOWN;
max = le16_to_cpu(desc->wMaxPacketSize) & 0x3ff;
retval = -EINVAL;
switch (desc->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_BULK:
if (strstr (ep->ep.name, "-iso")
|| strstr (ep->ep.name, "-int")) {
goto done;
}
switch (dum->gadget.speed) {
case USB_SPEED_HIGH:
if (max == 512)
break;
goto done;
case USB_SPEED_FULL:
if (max == 8 || max == 16 || max == 32 || max == 64)
break;
default:
goto done;
}
break;
case USB_ENDPOINT_XFER_INT:
if (strstr (ep->ep.name, "-iso"))
goto done;
switch (dum->gadget.speed) {
case USB_SPEED_HIGH:
if (max <= 1024)
break;
case USB_SPEED_FULL:
if (max <= 64)
break;
default:
if (max <= 8)
break;
goto done;
}
break;
case USB_ENDPOINT_XFER_ISOC:
if (strstr (ep->ep.name, "-bulk")
|| strstr (ep->ep.name, "-int"))
goto done;
switch (dum->gadget.speed) {
case USB_SPEED_HIGH:
if (max <= 1024)
break;
case USB_SPEED_FULL:
if (max <= 1023)
break;
default:
goto done;
}
break;
default:
goto done;
}
_ep->maxpacket = max;
ep->desc = desc;
dev_dbg (udc_dev(dum), "enabled %s (ep%d%s-%s) maxpacket %d\n",
_ep->name,
desc->bEndpointAddress & 0x0f,
(desc->bEndpointAddress & USB_DIR_IN) ? "in" : "out",
({ char *val;
switch (desc->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_BULK: val = "bulk"; break;
case USB_ENDPOINT_XFER_ISOC: val = "iso"; break;
case USB_ENDPOINT_XFER_INT: val = "intr"; break;
default: val = "ctrl"; break;
}; val; }),
max);
ep->halted = ep->wedged = 0;
retval = 0;
done:
return retval;
}
static int dummy_disable (struct usb_ep *_ep)
{
struct dummy_ep *ep;
struct dummy *dum;
unsigned long flags;
int retval;
ep = usb_ep_to_dummy_ep (_ep);
if (!_ep || !ep->desc || _ep->name == ep0name)
return -EINVAL;
dum = ep_to_dummy (ep);
spin_lock_irqsave (&dum->lock, flags);
ep->desc = NULL;
retval = 0;
nuke (dum, ep);
spin_unlock_irqrestore (&dum->lock, flags);
dev_dbg (udc_dev(dum), "disabled %s\n", _ep->name);
return retval;
}
static struct usb_request *
dummy_alloc_request (struct usb_ep *_ep, gfp_t mem_flags)
{
struct dummy_ep *ep;
struct dummy_request *req;
if (!_ep)
return NULL;
ep = usb_ep_to_dummy_ep (_ep);
req = kzalloc(sizeof(*req), mem_flags);
if (!req)
return NULL;
INIT_LIST_HEAD (&req->queue);
return &req->req;
}
static void
dummy_free_request (struct usb_ep *_ep, struct usb_request *_req)
{
struct dummy_ep *ep;
struct dummy_request *req;
ep = usb_ep_to_dummy_ep (_ep);
if (!ep || !_req || (!ep->desc && _ep->name != ep0name))
return;
req = usb_request_to_dummy_request (_req);
WARN_ON (!list_empty (&req->queue));
kfree (req);
}
static void
fifo_complete (struct usb_ep *ep, struct usb_request *req)
{
}
static int
dummy_queue (struct usb_ep *_ep, struct usb_request *_req,
gfp_t mem_flags)
{
struct dummy_ep *ep;
struct dummy_request *req;
struct dummy *dum;
unsigned long flags;
req = usb_request_to_dummy_request (_req);
if (!_req || !list_empty (&req->queue) || !_req->complete)
return -EINVAL;
ep = usb_ep_to_dummy_ep (_ep);
if (!_ep || (!ep->desc && _ep->name != ep0name))
return -EINVAL;
dum = ep_to_dummy (ep);
if (!dum->driver || !is_enabled (dum))
return -ESHUTDOWN;
#if 0
dev_dbg (udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
_req->status = -EINPROGRESS;
_req->actual = 0;
spin_lock_irqsave (&dum->lock, flags);
if (ep->desc && (ep->desc->bEndpointAddress & USB_DIR_IN) &&
list_empty (&dum->fifo_req.queue) &&
list_empty (&ep->queue) &&
_req->length <= FIFO_SIZE) {
req = &dum->fifo_req;
req->req = *_req;
req->req.buf = dum->fifo_buf;
memcpy (dum->fifo_buf, _req->buf, _req->length);
req->req.context = dum;
req->req.complete = fifo_complete;
list_add_tail(&req->queue, &ep->queue);
spin_unlock (&dum->lock);
_req->actual = _req->length;
_req->status = 0;
_req->complete (_ep, _req);
spin_lock (&dum->lock);
} else
list_add_tail(&req->queue, &ep->queue);
spin_unlock_irqrestore (&dum->lock, flags);
return 0;
}
static int dummy_dequeue (struct usb_ep *_ep, struct usb_request *_req)
{
struct dummy_ep *ep;
struct dummy *dum;
int retval = -EINVAL;
unsigned long flags;
struct dummy_request *req = NULL;
if (!_ep || !_req)
return retval;
ep = usb_ep_to_dummy_ep (_ep);
dum = ep_to_dummy (ep);
if (!dum->driver)
return -ESHUTDOWN;
local_irq_save (flags);
spin_lock (&dum->lock);
list_for_each_entry (req, &ep->queue, queue) {
if (&req->req == _req) {
list_del_init (&req->queue);
_req->status = -ECONNRESET;
retval = 0;
break;
}
}
spin_unlock (&dum->lock);
if (retval == 0) {
dev_dbg (udc_dev(dum),
"dequeued req %p from %s, len %d buf %p\n",
req, _ep->name, _req->length, _req->buf);
_req->complete (_ep, _req);
}
local_irq_restore (flags);
return retval;
}
static int
dummy_set_halt_and_wedge(struct usb_ep *_ep, int value, int wedged)
{
struct dummy_ep *ep;
struct dummy *dum;
if (!_ep)
return -EINVAL;
ep = usb_ep_to_dummy_ep (_ep);
dum = ep_to_dummy (ep);
if (!dum->driver)
return -ESHUTDOWN;
if (!value)
ep->halted = ep->wedged = 0;
else if (ep->desc && (ep->desc->bEndpointAddress & USB_DIR_IN) &&
!list_empty (&ep->queue))
return -EAGAIN;
else {
ep->halted = 1;
if (wedged)
ep->wedged = 1;
}
return 0;
}
static int
dummy_set_halt(struct usb_ep *_ep, int value)
{
return dummy_set_halt_and_wedge(_ep, value, 0);
}
static int dummy_set_wedge(struct usb_ep *_ep)
{
if (!_ep || _ep->name == ep0name)
return -EINVAL;
return dummy_set_halt_and_wedge(_ep, 1, 1);
}
static int dummy_g_get_frame (struct usb_gadget *_gadget)
{
struct timeval tv;
do_gettimeofday (&tv);
return tv.tv_usec / 1000;
}
static int dummy_wakeup (struct usb_gadget *_gadget)
{
struct dummy *dum;
dum = gadget_to_dummy (_gadget);
if (!(dum->devstatus & ( (1 << USB_DEVICE_B_HNP_ENABLE)
| (1 << USB_DEVICE_REMOTE_WAKEUP))))
return -EINVAL;
if ((dum->port_status & USB_PORT_STAT_CONNECTION) == 0)
return -ENOLINK;
if ((dum->port_status & USB_PORT_STAT_SUSPEND) == 0 &&
dum->rh_state != DUMMY_RH_SUSPENDED)
return -EIO;
dum->resuming = 1;
dum->re_timeout = jiffies + msecs_to_jiffies(20);
mod_timer (&dummy_to_hcd (dum)->rh_timer, dum->re_timeout);
return 0;
}
static int dummy_set_selfpowered (struct usb_gadget *_gadget, int value)
{
struct dummy *dum;
dum = gadget_to_dummy (_gadget);
if (value)
dum->devstatus |= (1 << USB_DEVICE_SELF_POWERED);
else
dum->devstatus &= ~(1 << USB_DEVICE_SELF_POWERED);
return 0;
}
static int dummy_pullup (struct usb_gadget *_gadget, int value)
{
struct dummy *dum;
unsigned long flags;
dum = gadget_to_dummy (_gadget);
spin_lock_irqsave (&dum->lock, flags);
dum->pullup = (value != 0);
set_link_state (dum);
spin_unlock_irqrestore (&dum->lock, flags);
usb_hcd_poll_rh_status (dummy_to_hcd (dum));
return 0;
}
static ssize_t
show_function (struct device *dev, struct device_attribute *attr, char *buf)
{
struct dummy *dum = gadget_dev_to_dummy (dev);
if (!dum->driver || !dum->driver->function)
return 0;
return scnprintf (buf, PAGE_SIZE, "%s\n", dum->driver->function);
}
int
usb_gadget_probe_driver(struct usb_gadget_driver *driver,
int (*bind)(struct usb_gadget *))
{
struct dummy *dum = the_controller;
int retval, i;
if (!dum)
return -EINVAL;
if (dum->driver)
return -EBUSY;
if (!bind || !driver->setup || driver->speed == USB_SPEED_UNKNOWN)
return -EINVAL;
dum->devstatus = 0;
INIT_LIST_HEAD (&dum->gadget.ep_list);
for (i = 0; i < DUMMY_ENDPOINTS; i++) {
struct dummy_ep *ep = &dum->ep [i];
if (!ep_name [i])
break;
ep->ep.name = ep_name [i];
ep->ep.ops = &dummy_ep_ops;
list_add_tail (&ep->ep.ep_list, &dum->gadget.ep_list);
ep->halted = ep->wedged = ep->already_seen =
ep->setup_stage = 0;
ep->ep.maxpacket = ~0;
ep->last_io = jiffies;
ep->gadget = &dum->gadget;
ep->desc = NULL;
INIT_LIST_HEAD (&ep->queue);
}
dum->gadget.ep0 = &dum->ep [0].ep;
dum->ep [0].ep.maxpacket = 64;
list_del_init (&dum->ep [0].ep.ep_list);
INIT_LIST_HEAD(&dum->fifo_req.queue);
driver->driver.bus = NULL;
dum->driver = driver;
dum->gadget.dev.driver = &driver->driver;
dev_dbg (udc_dev(dum), "binding gadget driver '%s'\n",
driver->driver.name);
retval = bind(&dum->gadget);
if (retval) {
dum->driver = NULL;
dum->gadget.dev.driver = NULL;
return retval;
}
spin_lock_irq (&dum->lock);
dum->pullup = 1;
set_link_state (dum);
spin_unlock_irq (&dum->lock);
usb_hcd_poll_rh_status (dummy_to_hcd (dum));
return 0;
}
int
usb_gadget_unregister_driver (struct usb_gadget_driver *driver)
{
struct dummy *dum = the_controller;
unsigned long flags;
if (!dum)
return -ENODEV;
if (!driver || driver != dum->driver || !driver->unbind)
return -EINVAL;
dev_dbg (udc_dev(dum), "unregister gadget driver '%s'\n",
driver->driver.name);
spin_lock_irqsave (&dum->lock, flags);
dum->pullup = 0;
set_link_state (dum);
spin_unlock_irqrestore (&dum->lock, flags);
driver->unbind (&dum->gadget);
dum->gadget.dev.driver = NULL;
dum->driver = NULL;
spin_lock_irqsave (&dum->lock, flags);
dum->pullup = 0;
set_link_state (dum);
spin_unlock_irqrestore (&dum->lock, flags);
usb_hcd_poll_rh_status (dummy_to_hcd (dum));
return 0;
}
int net2280_set_fifo_mode (struct usb_gadget *gadget, int mode)
{
return -ENOSYS;
}
static void
dummy_gadget_release (struct device *dev)
{
struct dummy *dum = gadget_dev_to_dummy (dev);
usb_put_hcd (dummy_to_hcd (dum));
}
static int dummy_udc_probe (struct platform_device *pdev)
{
struct dummy *dum = the_controller;
int rc;
usb_get_hcd(dummy_to_hcd(dum));
dum->gadget.name = gadget_name;
dum->gadget.ops = &dummy_ops;
dum->gadget.is_dualspeed = 1;
dum->gadget.is_otg = (dummy_to_hcd(dum)->self.otg_port != 0);
dev_set_name(&dum->gadget.dev, "gadget");
dum->gadget.dev.parent = &pdev->dev;
dum->gadget.dev.release = dummy_gadget_release;
rc = device_register (&dum->gadget.dev);
if (rc < 0) {
put_device(&dum->gadget.dev);
return rc;
}
rc = device_create_file (&dum->gadget.dev, &dev_attr_function);
if (rc < 0)
device_unregister (&dum->gadget.dev);
else
platform_set_drvdata(pdev, dum);
return rc;
}
static int dummy_udc_remove (struct platform_device *pdev)
{
struct dummy *dum = platform_get_drvdata (pdev);
platform_set_drvdata (pdev, NULL);
device_remove_file (&dum->gadget.dev, &dev_attr_function);
device_unregister (&dum->gadget.dev);
return 0;
}
static int dummy_udc_suspend (struct platform_device *pdev, pm_message_t state)
{
struct dummy *dum = platform_get_drvdata(pdev);
dev_dbg (&pdev->dev, "%s\n", __func__);
spin_lock_irq (&dum->lock);
dum->udc_suspended = 1;
set_link_state (dum);
spin_unlock_irq (&dum->lock);
usb_hcd_poll_rh_status (dummy_to_hcd (dum));
return 0;
}
static int dummy_udc_resume (struct platform_device *pdev)
{
struct dummy *dum = platform_get_drvdata(pdev);
dev_dbg (&pdev->dev, "%s\n", __func__);
spin_lock_irq (&dum->lock);
dum->udc_suspended = 0;
set_link_state (dum);
spin_unlock_irq (&dum->lock);
usb_hcd_poll_rh_status (dummy_to_hcd (dum));
return 0;
}
static int dummy_urb_enqueue (
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags
) {
struct dummy *dum;
struct urbp *urbp;
unsigned long flags;
int rc;
if (!urb->transfer_buffer && urb->transfer_buffer_length)
return -EINVAL;
urbp = kmalloc (sizeof *urbp, mem_flags);
if (!urbp)
return -ENOMEM;
urbp->urb = urb;
dum = hcd_to_dummy (hcd);
spin_lock_irqsave (&dum->lock, flags);
rc = usb_hcd_link_urb_to_ep(hcd, urb);
if (rc) {
kfree(urbp);
goto done;
}
if (!dum->udev) {
dum->udev = urb->dev;
usb_get_dev (dum->udev);
} else if (unlikely (dum->udev != urb->dev))
dev_err (dummy_dev(dum), "usb_device address has changed!\n");
list_add_tail (&urbp->urbp_list, &dum->urbp_list);
urb->hcpriv = urbp;
if (usb_pipetype (urb->pipe) == PIPE_CONTROL)
urb->error_count = 1;
if (!timer_pending (&dum->timer))
mod_timer (&dum->timer, jiffies + 1);
done:
spin_unlock_irqrestore(&dum->lock, flags);
return rc;
}
static int dummy_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct dummy *dum;
unsigned long flags;
int rc;
dum = hcd_to_dummy (hcd);
spin_lock_irqsave (&dum->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (!rc && dum->rh_state != DUMMY_RH_RUNNING &&
!list_empty(&dum->urbp_list))
mod_timer (&dum->timer, jiffies);
spin_unlock_irqrestore (&dum->lock, flags);
return rc;
}
static int
transfer(struct dummy *dum, struct urb *urb, struct dummy_ep *ep, int limit,
int *status)
{
struct dummy_request *req;
top:
list_for_each_entry (req, &ep->queue, queue) {
unsigned host_len, dev_len, len;
int is_short, to_host;
int rescan = 0;
host_len = urb->transfer_buffer_length - urb->actual_length;
dev_len = req->req.length - req->req.actual;
len = min (host_len, dev_len);
to_host = usb_pipein (urb->pipe);
if (unlikely (len == 0))
is_short = 1;
else {
char *ubuf, *rbuf;
if (limit < ep->ep.maxpacket && limit < len)
break;
len = min (len, (unsigned) limit);
if (len == 0)
break;
if (len > ep->ep.maxpacket) {
rescan = 1;
len -= (len % ep->ep.maxpacket);
}
is_short = (len % ep->ep.maxpacket) != 0;
ubuf = urb->transfer_buffer + urb->actual_length;
rbuf = req->req.buf + req->req.actual;
if (to_host)
memcpy (ubuf, rbuf, len);
else
memcpy (rbuf, ubuf, len);
ep->last_io = jiffies;
limit -= len;
urb->actual_length += len;
req->req.actual += len;
}
if (is_short) {
if (host_len == dev_len) {
req->req.status = 0;
*status = 0;
} else if (to_host) {
req->req.status = 0;
if (dev_len > host_len)
*status = -EOVERFLOW;
else
*status = 0;
} else if (!to_host) {
*status = 0;
if (host_len > dev_len)
req->req.status = -EOVERFLOW;
else
req->req.status = 0;
}
} else {
if (req->req.length == req->req.actual
&& !req->req.zero)
req->req.status = 0;
if (urb->transfer_buffer_length == urb->actual_length
&& !(urb->transfer_flags
& URB_ZERO_PACKET))
*status = 0;
}
if (req->req.status != -EINPROGRESS) {
list_del_init (&req->queue);
spin_unlock (&dum->lock);
req->req.complete (&ep->ep, &req->req);
spin_lock (&dum->lock);
rescan = 1;
}
if (*status != -EINPROGRESS)
break;
if (rescan)
goto top;
}
return limit;
}
static int periodic_bytes (struct dummy *dum, struct dummy_ep *ep)
{
int limit = ep->ep.maxpacket;
if (dum->gadget.speed == USB_SPEED_HIGH) {
int tmp;
tmp = le16_to_cpu(ep->desc->wMaxPacketSize);
tmp = (tmp >> 11) & 0x03;
tmp *= 8 ;
limit += limit * tmp;
}
return limit;
}
static struct dummy_ep *find_endpoint (struct dummy *dum, u8 address)
{
int i;
if (!is_active (dum))
return NULL;
if ((address & ~USB_DIR_IN) == 0)
return &dum->ep [0];
for (i = 1; i < DUMMY_ENDPOINTS; i++) {
struct dummy_ep *ep = &dum->ep [i];
if (!ep->desc)
continue;
if (ep->desc->bEndpointAddress == address)
return ep;
}
return NULL;
}
static int handle_control_request(struct dummy *dum, struct urb *urb,
struct usb_ctrlrequest *setup,
int *status)
{
struct dummy_ep *ep2;
int ret_val = 1;
unsigned w_index;
unsigned w_value;
w_index = le16_to_cpu(setup->wIndex);
w_value = le16_to_cpu(setup->wValue);
switch (setup->bRequest) {
case USB_REQ_SET_ADDRESS:
if (setup->bRequestType != Dev_Request)
break;
dum->address = w_value;
*status = 0;
dev_dbg(udc_dev(dum), "set_address = %d\n",
w_value);
ret_val = 0;
break;
case USB_REQ_SET_FEATURE:
if (setup->bRequestType == Dev_Request) {
ret_val = 0;
switch (w_value) {
case USB_DEVICE_REMOTE_WAKEUP:
break;
case USB_DEVICE_B_HNP_ENABLE:
dum->gadget.b_hnp_enable = 1;
break;
case USB_DEVICE_A_HNP_SUPPORT:
dum->gadget.a_hnp_support = 1;
break;
case USB_DEVICE_A_ALT_HNP_SUPPORT:
dum->gadget.a_alt_hnp_support = 1;
break;
default:
ret_val = -EOPNOTSUPP;
}
if (ret_val == 0) {
dum->devstatus |= (1 << w_value);
*status = 0;
}
} else if (setup->bRequestType == Ep_Request) {
ep2 = find_endpoint(dum, w_index);
if (!ep2 || ep2->ep.name == ep0name) {
ret_val = -EOPNOTSUPP;
break;
}
ep2->halted = 1;
ret_val = 0;
*status = 0;
}
break;
case USB_REQ_CLEAR_FEATURE:
if (setup->bRequestType == Dev_Request) {
ret_val = 0;
switch (w_value) {
case USB_DEVICE_REMOTE_WAKEUP:
w_value = USB_DEVICE_REMOTE_WAKEUP;
break;
default:
ret_val = -EOPNOTSUPP;
break;
}
if (ret_val == 0) {
dum->devstatus &= ~(1 << w_value);
*status = 0;
}
} else if (setup->bRequestType == Ep_Request) {
ep2 = find_endpoint(dum, w_index);
if (!ep2) {
ret_val = -EOPNOTSUPP;
break;
}
if (!ep2->wedged)
ep2->halted = 0;
ret_val = 0;
*status = 0;
}
break;
case USB_REQ_GET_STATUS:
if (setup->bRequestType == Dev_InRequest
|| setup->bRequestType == Intf_InRequest
|| setup->bRequestType == Ep_InRequest) {
char *buf;
buf = (char *)urb->transfer_buffer;
if (urb->transfer_buffer_length > 0) {
if (setup->bRequestType == Ep_InRequest) {
ep2 = find_endpoint(dum, w_index);
if (!ep2) {
ret_val = -EOPNOTSUPP;
break;
}
buf[0] = ep2->halted;
} else if (setup->bRequestType ==
Dev_InRequest) {
buf[0] = (u8)dum->devstatus;
} else
buf[0] = 0;
}
if (urb->transfer_buffer_length > 1)
buf[1] = 0;
urb->actual_length = min_t(u32, 2,
urb->transfer_buffer_length);
ret_val = 0;
*status = 0;
}
break;
}
return ret_val;
}
static void dummy_timer (unsigned long _dum)
{
struct dummy *dum = (struct dummy *) _dum;
struct urbp *urbp, *tmp;
unsigned long flags;
int limit, total;
int i;
switch (dum->gadget.speed) {
case USB_SPEED_LOW:
total = 8 * 12;
break;
case USB_SPEED_FULL:
total = 64 * 19;
break;
case USB_SPEED_HIGH:
total = 512 * 13 * 8;
break;
default:
dev_err (dummy_dev(dum), "bogus device speed\n");
return;
}
spin_lock_irqsave (&dum->lock, flags);
if (!dum->udev) {
dev_err (dummy_dev(dum),
"timer fired with no URBs pending?\n");
spin_unlock_irqrestore (&dum->lock, flags);
return;
}
for (i = 0; i < DUMMY_ENDPOINTS; i++) {
if (!ep_name [i])
break;
dum->ep [i].already_seen = 0;
}
restart:
list_for_each_entry_safe (urbp, tmp, &dum->urbp_list, urbp_list) {
struct urb *urb;
struct dummy_request *req;
u8 address;
struct dummy_ep *ep = NULL;
int type;
int status = -EINPROGRESS;
urb = urbp->urb;
if (urb->unlinked)
goto return_urb;
else if (dum->rh_state != DUMMY_RH_RUNNING)
continue;
type = usb_pipetype (urb->pipe);
if (total <= 0 && type == PIPE_BULK)
continue;
address = usb_pipeendpoint (urb->pipe);
if (usb_pipein (urb->pipe))
address |= USB_DIR_IN;
ep = find_endpoint(dum, address);
if (!ep) {
dev_dbg (dummy_dev(dum),
"no ep configured for urb %p\n",
urb);
status = -EPROTO;
goto return_urb;
}
if (ep->already_seen)
continue;
ep->already_seen = 1;
if (ep == &dum->ep [0] && urb->error_count) {
ep->setup_stage = 1;
urb->error_count = 0;
}
if (ep->halted && !ep->setup_stage) {
dev_dbg (dummy_dev(dum), "ep %s halted, urb %p\n",
ep->ep.name, urb);
status = -EPIPE;
goto return_urb;
}
if (ep == &dum->ep [0] && ep->setup_stage) {
struct usb_ctrlrequest setup;
int value = 1;
setup = *(struct usb_ctrlrequest*) urb->setup_packet;
list_for_each_entry (req, &ep->queue, queue) {
list_del_init (&req->queue);
req->req.status = -EOVERFLOW;
dev_dbg (udc_dev(dum), "stale req = %p\n",
req);
spin_unlock (&dum->lock);
req->req.complete (&ep->ep, &req->req);
spin_lock (&dum->lock);
ep->already_seen = 0;
goto restart;
}
ep->last_io = jiffies;
ep->setup_stage = 0;
ep->halted = 0;
value = handle_control_request(dum, urb, &setup,
&status);
if (value > 0) {
spin_unlock (&dum->lock);
value = dum->driver->setup (&dum->gadget,
&setup);
spin_lock (&dum->lock);
if (value >= 0) {
limit = 64*1024;
goto treat_control_like_bulk;
}
}
if (value < 0) {
if (value != -EOPNOTSUPP)
dev_dbg (udc_dev(dum),
"setup --> %d\n",
value);
status = -EPIPE;
urb->actual_length = 0;
}
goto return_urb;
}
limit = total;
switch (usb_pipetype (urb->pipe)) {
case PIPE_ISOCHRONOUS:
limit = max (limit, periodic_bytes (dum, ep));
status = -ENOSYS;
break;
case PIPE_INTERRUPT:
limit = max (limit, periodic_bytes (dum, ep));
default:
treat_control_like_bulk:
ep->last_io = jiffies;
total = transfer(dum, urb, ep, limit, &status);
break;
}
if (status == -EINPROGRESS)
continue;
return_urb:
list_del (&urbp->urbp_list);
kfree (urbp);
if (ep)
ep->already_seen = ep->setup_stage = 0;
usb_hcd_unlink_urb_from_ep(dummy_to_hcd(dum), urb);
spin_unlock (&dum->lock);
usb_hcd_giveback_urb(dummy_to_hcd(dum), urb, status);
spin_lock (&dum->lock);
goto restart;
}
if (list_empty (&dum->urbp_list)) {
usb_put_dev (dum->udev);
dum->udev = NULL;
} else if (dum->rh_state == DUMMY_RH_RUNNING) {
mod_timer (&dum->timer, jiffies + msecs_to_jiffies(1));
}
spin_unlock_irqrestore (&dum->lock, flags);
}
static int dummy_hub_status (struct usb_hcd *hcd, char *buf)
{
struct dummy *dum;
unsigned long flags;
int retval = 0;
dum = hcd_to_dummy (hcd);
spin_lock_irqsave (&dum->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd))
goto done;
if (dum->resuming && time_after_eq (jiffies, dum->re_timeout)) {
dum->port_status |= (USB_PORT_STAT_C_SUSPEND << 16);
dum->port_status &= ~USB_PORT_STAT_SUSPEND;
set_link_state (dum);
}
if ((dum->port_status & PORT_C_MASK) != 0) {
*buf = (1 << 1);
dev_dbg (dummy_dev(dum), "port status 0x%08x has changes\n",
dum->port_status);
retval = 1;
if (dum->rh_state == DUMMY_RH_SUSPENDED)
usb_hcd_resume_root_hub (hcd);
}
done:
spin_unlock_irqrestore (&dum->lock, flags);
return retval;
}
static inline void
hub_descriptor (struct usb_hub_descriptor *desc)
{
memset (desc, 0, sizeof *desc);
desc->bDescriptorType = 0x29;
desc->bDescLength = 9;
desc->wHubCharacteristics = cpu_to_le16(0x0001);
desc->bNbrPorts = 1;
desc->u.hs.DeviceRemovable[0] = 0xff;
desc->u.hs.DeviceRemovable[1] = 0xff;
}
static int dummy_hub_control (
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength
) {
struct dummy *dum;
int retval = 0;
unsigned long flags;
if (!HCD_HW_ACCESSIBLE(hcd))
return -ETIMEDOUT;
dum = hcd_to_dummy (hcd);
spin_lock_irqsave (&dum->lock, flags);
switch (typeReq) {
case ClearHubFeature:
break;
case ClearPortFeature:
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
if (dum->port_status & USB_PORT_STAT_SUSPEND) {
dum->resuming = 1;
dum->re_timeout = jiffies +
msecs_to_jiffies(20);
}
break;
case USB_PORT_FEAT_POWER:
if (dum->port_status & USB_PORT_STAT_POWER)
dev_dbg (dummy_dev(dum), "power-off\n");
default:
dum->port_status &= ~(1 << wValue);
set_link_state (dum);
}
break;
case GetHubDescriptor:
hub_descriptor ((struct usb_hub_descriptor *) buf);
break;
case GetHubStatus:
*(__le32 *) buf = cpu_to_le32 (0);
break;
case GetPortStatus:
if (wIndex != 1)
retval = -EPIPE;
if (dum->resuming &&
time_after_eq (jiffies, dum->re_timeout)) {
dum->port_status |= (USB_PORT_STAT_C_SUSPEND << 16);
dum->port_status &= ~USB_PORT_STAT_SUSPEND;
}
if ((dum->port_status & USB_PORT_STAT_RESET) != 0 &&
time_after_eq (jiffies, dum->re_timeout)) {
dum->port_status |= (USB_PORT_STAT_C_RESET << 16);
dum->port_status &= ~USB_PORT_STAT_RESET;
if (dum->pullup) {
dum->port_status |= USB_PORT_STAT_ENABLE;
dum->gadget.speed = dum->driver->speed;
dum->gadget.ep0->maxpacket = 64;
switch (dum->gadget.speed) {
case USB_SPEED_HIGH:
dum->port_status |=
USB_PORT_STAT_HIGH_SPEED;
break;
case USB_SPEED_LOW:
dum->gadget.ep0->maxpacket = 8;
dum->port_status |=
USB_PORT_STAT_LOW_SPEED;
break;
default:
dum->gadget.speed = USB_SPEED_FULL;
break;
}
}
}
set_link_state (dum);
((__le16 *) buf)[0] = cpu_to_le16 (dum->port_status);
((__le16 *) buf)[1] = cpu_to_le16 (dum->port_status >> 16);
break;
case SetHubFeature:
retval = -EPIPE;
break;
case SetPortFeature:
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
if (dum->active) {
dum->port_status |= USB_PORT_STAT_SUSPEND;
set_link_state (dum);
if (((1 << USB_DEVICE_B_HNP_ENABLE)
& dum->devstatus) != 0)
dev_dbg (dummy_dev(dum),
"no HNP yet!\n");
}
break;
case USB_PORT_FEAT_POWER:
dum->port_status |= USB_PORT_STAT_POWER;
set_link_state (dum);
break;
case USB_PORT_FEAT_RESET:
dum->port_status &= ~(USB_PORT_STAT_ENABLE
| USB_PORT_STAT_LOW_SPEED
| USB_PORT_STAT_HIGH_SPEED);
dum->devstatus = 0;
dum->re_timeout = jiffies + msecs_to_jiffies(50);
default:
if ((dum->port_status & USB_PORT_STAT_POWER) != 0) {
dum->port_status |= (1 << wValue);
set_link_state (dum);
}
}
break;
default:
dev_dbg (dummy_dev(dum),
"hub control req%04x v%04x i%04x l%d\n",
typeReq, wValue, wIndex, wLength);
retval = -EPIPE;
}
spin_unlock_irqrestore (&dum->lock, flags);
if ((dum->port_status & PORT_C_MASK) != 0)
usb_hcd_poll_rh_status (hcd);
return retval;
}
static int dummy_bus_suspend (struct usb_hcd *hcd)
{
struct dummy *dum = hcd_to_dummy (hcd);
dev_dbg (&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irq (&dum->lock);
dum->rh_state = DUMMY_RH_SUSPENDED;
set_link_state (dum);
hcd->state = HC_STATE_SUSPENDED;
spin_unlock_irq (&dum->lock);
return 0;
}
static int dummy_bus_resume (struct usb_hcd *hcd)
{
struct dummy *dum = hcd_to_dummy (hcd);
int rc = 0;
dev_dbg (&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irq (&dum->lock);
if (!HCD_HW_ACCESSIBLE(hcd)) {
rc = -ESHUTDOWN;
} else {
dum->rh_state = DUMMY_RH_RUNNING;
set_link_state (dum);
if (!list_empty(&dum->urbp_list))
mod_timer (&dum->timer, jiffies);
hcd->state = HC_STATE_RUNNING;
}
spin_unlock_irq (&dum->lock);
return rc;
}
static inline ssize_t
show_urb (char *buf, size_t size, struct urb *urb)
{
int ep = usb_pipeendpoint (urb->pipe);
return snprintf (buf, size,
"urb/%p %s ep%d%s%s len %d/%d\n",
urb,
({ char *s;
switch (urb->dev->speed) {
case USB_SPEED_LOW: s = "ls"; break;
case USB_SPEED_FULL: s = "fs"; break;
case USB_SPEED_HIGH: s = "hs"; break;
default: s = "?"; break;
}; s; }),
ep, ep ? (usb_pipein (urb->pipe) ? "in" : "out") : "",
({ char *s; \
switch (usb_pipetype (urb->pipe)) { \
case PIPE_CONTROL: s = ""; break; \
case PIPE_BULK: s = "-bulk"; break; \
case PIPE_INTERRUPT: s = "-int"; break; \
default: s = "-iso"; break; \
}; s;}),
urb->actual_length, urb->transfer_buffer_length);
}
static ssize_t
show_urbs (struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_hcd *hcd = dev_get_drvdata (dev);
struct dummy *dum = hcd_to_dummy (hcd);
struct urbp *urbp;
size_t size = 0;
unsigned long flags;
spin_lock_irqsave (&dum->lock, flags);
list_for_each_entry (urbp, &dum->urbp_list, urbp_list) {
size_t temp;
temp = show_urb (buf, PAGE_SIZE - size, urbp->urb);
buf += temp;
size += temp;
}
spin_unlock_irqrestore (&dum->lock, flags);
return size;
}
static int dummy_start (struct usb_hcd *hcd)
{
struct dummy *dum;
dum = hcd_to_dummy (hcd);
spin_lock_init (&dum->lock);
init_timer (&dum->timer);
dum->timer.function = dummy_timer;
dum->timer.data = (unsigned long) dum;
dum->rh_state = DUMMY_RH_RUNNING;
INIT_LIST_HEAD (&dum->urbp_list);
hcd->power_budget = POWER_BUDGET;
hcd->state = HC_STATE_RUNNING;
hcd->uses_new_polling = 1;
#ifdef CONFIG_USB_OTG
hcd->self.otg_port = 1;
#endif
return device_create_file (dummy_dev(dum), &dev_attr_urbs);
}
static void dummy_stop (struct usb_hcd *hcd)
{
struct dummy *dum;
dum = hcd_to_dummy (hcd);
device_remove_file (dummy_dev(dum), &dev_attr_urbs);
usb_gadget_unregister_driver (dum->driver);
dev_info (dummy_dev(dum), "stopped\n");
}
static int dummy_h_get_frame (struct usb_hcd *hcd)
{
return dummy_g_get_frame (NULL);
}
static int dummy_hcd_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
int retval;
dev_info(&pdev->dev, "%s, driver " DRIVER_VERSION "\n", driver_desc);
hcd = usb_create_hcd(&dummy_hcd, &pdev->dev, dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
the_controller = hcd_to_dummy (hcd);
hcd->has_tt = 1;
retval = usb_add_hcd(hcd, 0, 0);
if (retval != 0) {
usb_put_hcd (hcd);
the_controller = NULL;
}
return retval;
}
static int dummy_hcd_remove (struct platform_device *pdev)
{
struct usb_hcd *hcd;
hcd = platform_get_drvdata (pdev);
usb_remove_hcd (hcd);
usb_put_hcd (hcd);
the_controller = NULL;
return 0;
}
static int dummy_hcd_suspend (struct platform_device *pdev, pm_message_t state)
{
struct usb_hcd *hcd;
struct dummy *dum;
int rc = 0;
dev_dbg (&pdev->dev, "%s\n", __func__);
hcd = platform_get_drvdata (pdev);
dum = hcd_to_dummy (hcd);
if (dum->rh_state == DUMMY_RH_RUNNING) {
dev_warn(&pdev->dev, "Root hub isn't suspended!\n");
rc = -EBUSY;
} else
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
return rc;
}
static int dummy_hcd_resume (struct platform_device *pdev)
{
struct usb_hcd *hcd;
dev_dbg (&pdev->dev, "%s\n", __func__);
hcd = platform_get_drvdata (pdev);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
usb_hcd_poll_rh_status (hcd);
return 0;
}
static int __init init (void)
{
int retval = -ENOMEM;
if (usb_disabled ())
return -ENODEV;
the_hcd_pdev = platform_device_alloc(driver_name, -1);
if (!the_hcd_pdev)
return retval;
the_udc_pdev = platform_device_alloc(gadget_name, -1);
if (!the_udc_pdev)
goto err_alloc_udc;
retval = platform_driver_register(&dummy_hcd_driver);
if (retval < 0)
goto err_register_hcd_driver;
retval = platform_driver_register(&dummy_udc_driver);
if (retval < 0)
goto err_register_udc_driver;
retval = platform_device_add(the_hcd_pdev);
if (retval < 0)
goto err_add_hcd;
if (!the_controller) {
retval = -EINVAL;
goto err_add_udc;
}
retval = platform_device_add(the_udc_pdev);
if (retval < 0)
goto err_add_udc;
if (!platform_get_drvdata(the_udc_pdev)) {
retval = -EINVAL;
goto err_probe_udc;
}
return retval;
err_probe_udc:
platform_device_del(the_udc_pdev);
err_add_udc:
platform_device_del(the_hcd_pdev);
err_add_hcd:
platform_driver_unregister(&dummy_udc_driver);
err_register_udc_driver:
platform_driver_unregister(&dummy_hcd_driver);
err_register_hcd_driver:
platform_device_put(the_udc_pdev);
err_alloc_udc:
platform_device_put(the_hcd_pdev);
return retval;
}
static void __exit cleanup (void)
{
platform_device_unregister(the_udc_pdev);
platform_device_unregister(the_hcd_pdev);
platform_driver_unregister(&dummy_udc_driver);
platform_driver_unregister(&dummy_hcd_driver);
}
