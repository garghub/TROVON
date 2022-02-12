static inline struct f_loopback *func_to_loop(struct usb_function *f)
{
return container_of(f, struct f_loopback, function);
}
static int __init
loopback_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_loopback *loop = func_to_loop(f);
int id;
id = usb_interface_id(c, f);
if (id < 0)
return id;
loopback_intf.bInterfaceNumber = id;
loop->in_ep = usb_ep_autoconfig(cdev->gadget, &fs_loop_source_desc);
if (!loop->in_ep) {
autoconf_fail:
ERROR(cdev, "%s: can't autoconfigure on %s\n",
f->name, cdev->gadget->name);
return -ENODEV;
}
loop->in_ep->driver_data = cdev;
loop->out_ep = usb_ep_autoconfig(cdev->gadget, &fs_loop_sink_desc);
if (!loop->out_ep)
goto autoconf_fail;
loop->out_ep->driver_data = cdev;
if (gadget_is_dualspeed(c->cdev->gadget)) {
hs_loop_source_desc.bEndpointAddress =
fs_loop_source_desc.bEndpointAddress;
hs_loop_sink_desc.bEndpointAddress =
fs_loop_sink_desc.bEndpointAddress;
f->hs_descriptors = hs_loopback_descs;
}
DBG(cdev, "%s speed %s: IN/%s, OUT/%s\n",
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
f->name, loop->in_ep->name, loop->out_ep->name);
return 0;
}
static void
loopback_unbind(struct usb_configuration *c, struct usb_function *f)
{
kfree(func_to_loop(f));
}
static void loopback_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_loopback *loop = ep->driver_data;
struct usb_composite_dev *cdev = loop->function.config->cdev;
int status = req->status;
switch (status) {
case 0:
if (ep == loop->out_ep) {
req->zero = (req->actual < req->length);
req->length = req->actual;
status = usb_ep_queue(loop->in_ep, req, GFP_ATOMIC);
if (status == 0)
return;
ERROR(cdev, "can't loop %s to %s: %d\n",
ep->name, loop->in_ep->name,
status);
}
req->length = buflen;
status = usb_ep_queue(loop->out_ep, req, GFP_ATOMIC);
if (status == 0)
return;
default:
ERROR(cdev, "%s loop complete --> %d, %d/%d\n", ep->name,
status, req->actual, req->length);
case -ECONNABORTED:
case -ECONNRESET:
case -ESHUTDOWN:
free_ep_req(ep, req);
return;
}
}
static void disable_loopback(struct f_loopback *loop)
{
struct usb_composite_dev *cdev;
cdev = loop->function.config->cdev;
disable_endpoints(cdev, loop->in_ep, loop->out_ep);
VDBG(cdev, "%s disabled\n", loop->function.name);
}
static int
enable_loopback(struct usb_composite_dev *cdev, struct f_loopback *loop)
{
int result = 0;
const struct usb_endpoint_descriptor *src, *sink;
struct usb_ep *ep;
struct usb_request *req;
unsigned i;
src = ep_choose(cdev->gadget,
&hs_loop_source_desc, &fs_loop_source_desc);
sink = ep_choose(cdev->gadget,
&hs_loop_sink_desc, &fs_loop_sink_desc);
ep = loop->in_ep;
result = usb_ep_enable(ep, src);
if (result < 0)
return result;
ep->driver_data = loop;
ep = loop->out_ep;
result = usb_ep_enable(ep, sink);
if (result < 0) {
fail0:
ep = loop->in_ep;
usb_ep_disable(ep);
ep->driver_data = NULL;
return result;
}
ep->driver_data = loop;
for (i = 0; i < qlen && result == 0; i++) {
req = alloc_ep_req(ep);
if (req) {
req->complete = loopback_complete;
result = usb_ep_queue(ep, req, GFP_ATOMIC);
if (result)
ERROR(cdev, "%s queue req --> %d\n",
ep->name, result);
} else {
usb_ep_disable(ep);
ep->driver_data = NULL;
result = -ENOMEM;
goto fail0;
}
}
DBG(cdev, "%s enabled\n", loop->function.name);
return result;
}
static int loopback_set_alt(struct usb_function *f,
unsigned intf, unsigned alt)
{
struct f_loopback *loop = func_to_loop(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (loop->in_ep->driver_data)
disable_loopback(loop);
return enable_loopback(cdev, loop);
}
static void loopback_disable(struct usb_function *f)
{
struct f_loopback *loop = func_to_loop(f);
disable_loopback(loop);
}
static int __init loopback_bind_config(struct usb_configuration *c)
{
struct f_loopback *loop;
int status;
loop = kzalloc(sizeof *loop, GFP_KERNEL);
if (!loop)
return -ENOMEM;
loop->function.name = "loopback";
loop->function.descriptors = fs_loopback_descs;
loop->function.bind = loopback_bind;
loop->function.unbind = loopback_unbind;
loop->function.set_alt = loopback_set_alt;
loop->function.disable = loopback_disable;
status = usb_add_function(c, &loop->function);
if (status)
kfree(loop);
return status;
}
int __init loopback_add(struct usb_composite_dev *cdev, bool autoresume)
{
int id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_loopback[0].id = id;
loopback_intf.iInterface = id;
loopback_driver.iConfiguration = id;
if (autoresume)
sourcesink_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
if (gadget_is_otg(cdev->gadget)) {
loopback_driver.descriptors = otg_desc;
loopback_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
return usb_add_config(cdev, &loopback_driver, loopback_bind_config);
}
