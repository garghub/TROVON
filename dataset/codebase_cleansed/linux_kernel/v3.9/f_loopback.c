static inline struct f_loopback *func_to_loop(struct usb_function *f)
{
return container_of(f, struct f_loopback, function);
}
static int loopback_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_loopback *loop = func_to_loop(f);
int id;
int ret;
id = usb_interface_id(c, f);
if (id < 0)
return id;
loopback_intf.bInterfaceNumber = id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_loopback[0].id = id;
loopback_intf.iInterface = id;
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
hs_loop_source_desc.bEndpointAddress =
fs_loop_source_desc.bEndpointAddress;
hs_loop_sink_desc.bEndpointAddress = fs_loop_sink_desc.bEndpointAddress;
ss_loop_source_desc.bEndpointAddress =
fs_loop_source_desc.bEndpointAddress;
ss_loop_sink_desc.bEndpointAddress = fs_loop_sink_desc.bEndpointAddress;
ret = usb_assign_descriptors(f, fs_loopback_descs, hs_loopback_descs,
ss_loopback_descs);
if (ret)
return ret;
DBG(cdev, "%s speed %s: IN/%s, OUT/%s\n",
(gadget_is_superspeed(c->cdev->gadget) ? "super" :
(gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full")),
f->name, loop->in_ep->name, loop->out_ep->name);
return 0;
}
static void lb_free_func(struct usb_function *f)
{
usb_free_all_descriptors(f);
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
disable_endpoints(cdev, loop->in_ep, loop->out_ep, NULL, NULL);
VDBG(cdev, "%s disabled\n", loop->function.name);
}
static int
enable_loopback(struct usb_composite_dev *cdev, struct f_loopback *loop)
{
int result = 0;
struct usb_ep *ep;
struct usb_request *req;
unsigned i;
ep = loop->in_ep;
result = config_ep_by_speed(cdev->gadget, &(loop->function), ep);
if (result)
return result;
result = usb_ep_enable(ep);
if (result < 0)
return result;
ep->driver_data = loop;
ep = loop->out_ep;
result = config_ep_by_speed(cdev->gadget, &(loop->function), ep);
if (result)
goto fail0;
result = usb_ep_enable(ep);
if (result < 0) {
fail0:
ep = loop->in_ep;
usb_ep_disable(ep);
ep->driver_data = NULL;
return result;
}
ep->driver_data = loop;
for (i = 0; i < qlen && result == 0; i++) {
req = alloc_ep_req(ep, 0);
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
static struct usb_function *loopback_alloc(struct usb_function_instance *fi)
{
struct f_loopback *loop;
struct f_lb_opts *lb_opts;
loop = kzalloc(sizeof *loop, GFP_KERNEL);
if (!loop)
return ERR_PTR(-ENOMEM);
lb_opts = container_of(fi, struct f_lb_opts, func_inst);
buflen = lb_opts->bulk_buflen;
qlen = lb_opts->qlen;
if (!qlen)
qlen = 32;
loop->function.name = "loopback";
loop->function.bind = loopback_bind;
loop->function.set_alt = loopback_set_alt;
loop->function.disable = loopback_disable;
loop->function.strings = loopback_strings;
loop->function.free_func = lb_free_func;
return &loop->function;
}
static void lb_free_instance(struct usb_function_instance *fi)
{
struct f_lb_opts *lb_opts;
lb_opts = container_of(fi, struct f_lb_opts, func_inst);
kfree(lb_opts);
}
static struct usb_function_instance *loopback_alloc_instance(void)
{
struct f_lb_opts *lb_opts;
lb_opts = kzalloc(sizeof(*lb_opts), GFP_KERNEL);
if (!lb_opts)
return ERR_PTR(-ENOMEM);
lb_opts->func_inst.free_func_inst = lb_free_instance;
return &lb_opts->func_inst;
}
int __init lb_modinit(void)
{
int ret;
ret = usb_function_register(&Loopbackusb_func);
if (ret)
return ret;
return ret;
}
void __exit lb_modexit(void)
{
usb_function_unregister(&Loopbackusb_func);
}
