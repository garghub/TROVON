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
loop->out_ep = usb_ep_autoconfig(cdev->gadget, &fs_loop_sink_desc);
if (!loop->out_ep)
goto autoconf_fail;
hs_loop_source_desc.bEndpointAddress =
fs_loop_source_desc.bEndpointAddress;
hs_loop_sink_desc.bEndpointAddress = fs_loop_sink_desc.bEndpointAddress;
ss_loop_source_desc.bEndpointAddress =
fs_loop_source_desc.bEndpointAddress;
ss_loop_sink_desc.bEndpointAddress = fs_loop_sink_desc.bEndpointAddress;
ret = usb_assign_descriptors(f, fs_loopback_descs, hs_loopback_descs,
ss_loopback_descs, NULL);
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
struct f_lb_opts *opts;
opts = container_of(f->fi, struct f_lb_opts, func_inst);
mutex_lock(&opts->lock);
opts->refcnt--;
mutex_unlock(&opts->lock);
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
struct usb_request *in_req = req->context;
in_req->zero = (req->actual < req->length);
in_req->length = req->actual;
ep = loop->in_ep;
req = in_req;
} else {
req = req->context;
ep = loop->out_ep;
}
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status == 0) {
return;
} else {
ERROR(cdev, "Unable to loop back buffer to %s: %d\n",
ep->name, status);
goto free_req;
}
default:
ERROR(cdev, "%s loop complete --> %d, %d/%d\n", ep->name,
status, req->actual, req->length);
case -ECONNABORTED:
case -ECONNRESET:
case -ESHUTDOWN:
free_req:
usb_ep_free_request(ep == loop->in_ep ?
loop->out_ep : loop->in_ep,
req->context);
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
static inline struct usb_request *lb_alloc_ep_req(struct usb_ep *ep, int len)
{
return alloc_ep_req(ep, len);
}
static int alloc_requests(struct usb_composite_dev *cdev,
struct f_loopback *loop)
{
struct usb_request *in_req, *out_req;
int i;
int result = 0;
for (i = 0; i < loop->qlen && result == 0; i++) {
result = -ENOMEM;
in_req = usb_ep_alloc_request(loop->in_ep, GFP_ATOMIC);
if (!in_req)
goto fail;
out_req = lb_alloc_ep_req(loop->out_ep, loop->buflen);
if (!out_req)
goto fail_in;
in_req->complete = loopback_complete;
out_req->complete = loopback_complete;
in_req->buf = out_req->buf;
in_req->context = out_req;
out_req->context = in_req;
result = usb_ep_queue(loop->out_ep, out_req, GFP_ATOMIC);
if (result) {
ERROR(cdev, "%s queue req --> %d\n",
loop->out_ep->name, result);
goto fail_out;
}
}
return 0;
fail_out:
free_ep_req(loop->out_ep, out_req);
fail_in:
usb_ep_free_request(loop->in_ep, in_req);
fail:
return result;
}
static int enable_endpoint(struct usb_composite_dev *cdev,
struct f_loopback *loop, struct usb_ep *ep)
{
int result;
result = config_ep_by_speed(cdev->gadget, &(loop->function), ep);
if (result)
goto out;
result = usb_ep_enable(ep);
if (result < 0)
goto out;
ep->driver_data = loop;
result = 0;
out:
return result;
}
static int
enable_loopback(struct usb_composite_dev *cdev, struct f_loopback *loop)
{
int result = 0;
result = enable_endpoint(cdev, loop, loop->in_ep);
if (result)
goto out;
result = enable_endpoint(cdev, loop, loop->out_ep);
if (result)
goto disable_in;
result = alloc_requests(cdev, loop);
if (result)
goto disable_out;
DBG(cdev, "%s enabled\n", loop->function.name);
return 0;
disable_out:
usb_ep_disable(loop->out_ep);
disable_in:
usb_ep_disable(loop->in_ep);
out:
return result;
}
static int loopback_set_alt(struct usb_function *f,
unsigned intf, unsigned alt)
{
struct f_loopback *loop = func_to_loop(f);
struct usb_composite_dev *cdev = f->config->cdev;
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
mutex_lock(&lb_opts->lock);
lb_opts->refcnt++;
mutex_unlock(&lb_opts->lock);
loop->buflen = lb_opts->bulk_buflen;
loop->qlen = lb_opts->qlen;
if (!loop->qlen)
loop->qlen = 32;
loop->function.name = "loopback";
loop->function.bind = loopback_bind;
loop->function.set_alt = loopback_set_alt;
loop->function.disable = loopback_disable;
loop->function.strings = loopback_strings;
loop->function.free_func = lb_free_func;
return &loop->function;
}
static inline struct f_lb_opts *to_f_lb_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_lb_opts,
func_inst.group);
}
static void lb_attr_release(struct config_item *item)
{
struct f_lb_opts *lb_opts = to_f_lb_opts(item);
usb_put_function_instance(&lb_opts->func_inst);
}
static ssize_t f_lb_opts_qlen_show(struct config_item *item, char *page)
{
struct f_lb_opts *opts = to_f_lb_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%d\n", opts->qlen);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_lb_opts_qlen_store(struct config_item *item,
const char *page, size_t len)
{
struct f_lb_opts *opts = to_f_lb_opts(item);
int ret;
u32 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou32(page, 0, &num);
if (ret)
goto end;
opts->qlen = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_lb_opts_bulk_buflen_show(struct config_item *item, char *page)
{
struct f_lb_opts *opts = to_f_lb_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%d\n", opts->bulk_buflen);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_lb_opts_bulk_buflen_store(struct config_item *item,
const char *page, size_t len)
{
struct f_lb_opts *opts = to_f_lb_opts(item);
int ret;
u32 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou32(page, 0, &num);
if (ret)
goto end;
opts->bulk_buflen = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
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
mutex_init(&lb_opts->lock);
lb_opts->func_inst.free_func_inst = lb_free_instance;
lb_opts->bulk_buflen = GZERO_BULK_BUFLEN;
lb_opts->qlen = GZERO_QLEN;
config_group_init_type_name(&lb_opts->func_inst.group, "",
&lb_func_type);
return &lb_opts->func_inst;
}
int __init lb_modinit(void)
{
return usb_function_register(&Loopbackusb_func);
}
void __exit lb_modexit(void)
{
usb_function_unregister(&Loopbackusb_func);
}
