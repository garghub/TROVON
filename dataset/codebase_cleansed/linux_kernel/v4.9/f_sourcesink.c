static inline struct f_sourcesink *func_to_ss(struct usb_function *f)
{
return container_of(f, struct f_sourcesink, function);
}
static inline struct usb_request *ss_alloc_ep_req(struct usb_ep *ep, int len)
{
return alloc_ep_req(ep, len);
}
static void disable_ep(struct usb_composite_dev *cdev, struct usb_ep *ep)
{
int value;
value = usb_ep_disable(ep);
if (value < 0)
DBG(cdev, "disable %s --> %d\n", ep->name, value);
}
void disable_endpoints(struct usb_composite_dev *cdev,
struct usb_ep *in, struct usb_ep *out,
struct usb_ep *iso_in, struct usb_ep *iso_out)
{
disable_ep(cdev, in);
disable_ep(cdev, out);
if (iso_in)
disable_ep(cdev, iso_in);
if (iso_out)
disable_ep(cdev, iso_out);
}
static int
sourcesink_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_sourcesink *ss = func_to_ss(f);
int id;
int ret;
id = usb_interface_id(c, f);
if (id < 0)
return id;
source_sink_intf_alt0.bInterfaceNumber = id;
source_sink_intf_alt1.bInterfaceNumber = id;
ss->in_ep = usb_ep_autoconfig(cdev->gadget, &fs_source_desc);
if (!ss->in_ep) {
autoconf_fail:
ERROR(cdev, "%s: can't autoconfigure on %s\n",
f->name, cdev->gadget->name);
return -ENODEV;
}
ss->out_ep = usb_ep_autoconfig(cdev->gadget, &fs_sink_desc);
if (!ss->out_ep)
goto autoconf_fail;
if (ss->isoc_interval < 1)
ss->isoc_interval = 1;
if (ss->isoc_interval > 16)
ss->isoc_interval = 16;
if (ss->isoc_mult > 2)
ss->isoc_mult = 2;
if (ss->isoc_maxburst > 15)
ss->isoc_maxburst = 15;
fs_iso_source_desc.wMaxPacketSize = ss->isoc_maxpacket > 1023 ?
1023 : ss->isoc_maxpacket;
fs_iso_source_desc.bInterval = ss->isoc_interval;
fs_iso_sink_desc.wMaxPacketSize = ss->isoc_maxpacket > 1023 ?
1023 : ss->isoc_maxpacket;
fs_iso_sink_desc.bInterval = ss->isoc_interval;
ss->iso_in_ep = usb_ep_autoconfig(cdev->gadget, &fs_iso_source_desc);
if (!ss->iso_in_ep)
goto no_iso;
ss->iso_out_ep = usb_ep_autoconfig(cdev->gadget, &fs_iso_sink_desc);
if (!ss->iso_out_ep) {
usb_ep_autoconfig_release(ss->iso_in_ep);
ss->iso_in_ep = NULL;
no_iso:
fs_source_sink_descs[FS_ALT_IFC_1_OFFSET] = NULL;
hs_source_sink_descs[HS_ALT_IFC_1_OFFSET] = NULL;
ss_source_sink_descs[SS_ALT_IFC_1_OFFSET] = NULL;
}
if (ss->isoc_maxpacket > 1024)
ss->isoc_maxpacket = 1024;
hs_source_desc.bEndpointAddress = fs_source_desc.bEndpointAddress;
hs_sink_desc.bEndpointAddress = fs_sink_desc.bEndpointAddress;
hs_iso_source_desc.wMaxPacketSize = ss->isoc_maxpacket;
hs_iso_source_desc.wMaxPacketSize |= ss->isoc_mult << 11;
hs_iso_source_desc.bInterval = ss->isoc_interval;
hs_iso_source_desc.bEndpointAddress =
fs_iso_source_desc.bEndpointAddress;
hs_iso_sink_desc.wMaxPacketSize = ss->isoc_maxpacket;
hs_iso_sink_desc.wMaxPacketSize |= ss->isoc_mult << 11;
hs_iso_sink_desc.bInterval = ss->isoc_interval;
hs_iso_sink_desc.bEndpointAddress = fs_iso_sink_desc.bEndpointAddress;
ss_source_desc.bEndpointAddress =
fs_source_desc.bEndpointAddress;
ss_sink_desc.bEndpointAddress =
fs_sink_desc.bEndpointAddress;
ss_iso_source_desc.wMaxPacketSize = ss->isoc_maxpacket;
ss_iso_source_desc.bInterval = ss->isoc_interval;
ss_iso_source_comp_desc.bmAttributes = ss->isoc_mult;
ss_iso_source_comp_desc.bMaxBurst = ss->isoc_maxburst;
ss_iso_source_comp_desc.wBytesPerInterval = ss->isoc_maxpacket *
(ss->isoc_mult + 1) * (ss->isoc_maxburst + 1);
ss_iso_source_desc.bEndpointAddress =
fs_iso_source_desc.bEndpointAddress;
ss_iso_sink_desc.wMaxPacketSize = ss->isoc_maxpacket;
ss_iso_sink_desc.bInterval = ss->isoc_interval;
ss_iso_sink_comp_desc.bmAttributes = ss->isoc_mult;
ss_iso_sink_comp_desc.bMaxBurst = ss->isoc_maxburst;
ss_iso_sink_comp_desc.wBytesPerInterval = ss->isoc_maxpacket *
(ss->isoc_mult + 1) * (ss->isoc_maxburst + 1);
ss_iso_sink_desc.bEndpointAddress = fs_iso_sink_desc.bEndpointAddress;
ret = usb_assign_descriptors(f, fs_source_sink_descs,
hs_source_sink_descs, ss_source_sink_descs, NULL);
if (ret)
return ret;
DBG(cdev, "%s speed %s: IN/%s, OUT/%s, ISO-IN/%s, ISO-OUT/%s\n",
(gadget_is_superspeed(c->cdev->gadget) ? "super" :
(gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full")),
f->name, ss->in_ep->name, ss->out_ep->name,
ss->iso_in_ep ? ss->iso_in_ep->name : "<none>",
ss->iso_out_ep ? ss->iso_out_ep->name : "<none>");
return 0;
}
static void
sourcesink_free_func(struct usb_function *f)
{
struct f_ss_opts *opts;
opts = container_of(f->fi, struct f_ss_opts, func_inst);
mutex_lock(&opts->lock);
opts->refcnt--;
mutex_unlock(&opts->lock);
usb_free_all_descriptors(f);
kfree(func_to_ss(f));
}
static int check_read_data(struct f_sourcesink *ss, struct usb_request *req)
{
unsigned i;
u8 *buf = req->buf;
struct usb_composite_dev *cdev = ss->function.config->cdev;
int max_packet_size = le16_to_cpu(ss->out_ep->desc->wMaxPacketSize);
if (ss->pattern == 2)
return 0;
for (i = 0; i < req->actual; i++, buf++) {
switch (ss->pattern) {
case 0:
if (*buf == 0)
continue;
break;
case 1:
if (*buf == (u8)((i % max_packet_size) % 63))
continue;
break;
}
ERROR(cdev, "bad OUT byte, buf[%d] = %d\n", i, *buf);
usb_ep_set_halt(ss->out_ep);
return -EINVAL;
}
return 0;
}
static void reinit_write_data(struct usb_ep *ep, struct usb_request *req)
{
unsigned i;
u8 *buf = req->buf;
int max_packet_size = le16_to_cpu(ep->desc->wMaxPacketSize);
struct f_sourcesink *ss = ep->driver_data;
switch (ss->pattern) {
case 0:
memset(req->buf, 0, req->length);
break;
case 1:
for (i = 0; i < req->length; i++)
*buf++ = (u8) ((i % max_packet_size) % 63);
break;
case 2:
break;
}
}
static void source_sink_complete(struct usb_ep *ep, struct usb_request *req)
{
struct usb_composite_dev *cdev;
struct f_sourcesink *ss = ep->driver_data;
int status = req->status;
if (!ss)
return;
cdev = ss->function.config->cdev;
switch (status) {
case 0:
if (ep == ss->out_ep) {
check_read_data(ss, req);
if (ss->pattern != 2)
memset(req->buf, 0x55, req->length);
}
break;
case -ECONNABORTED:
case -ECONNRESET:
case -ESHUTDOWN:
VDBG(cdev, "%s gone (%d), %d/%d\n", ep->name, status,
req->actual, req->length);
if (ep == ss->out_ep)
check_read_data(ss, req);
free_ep_req(ep, req);
return;
case -EOVERFLOW:
default:
#if 1
DBG(cdev, "%s complete --> %d, %d/%d\n", ep->name,
status, req->actual, req->length);
#endif
case -EREMOTEIO:
break;
}
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status) {
ERROR(cdev, "kill %s: resubmit %d bytes --> %d\n",
ep->name, req->length, status);
usb_ep_set_halt(ep);
}
}
static int source_sink_start_ep(struct f_sourcesink *ss, bool is_in,
bool is_iso, int speed)
{
struct usb_ep *ep;
struct usb_request *req;
int i, size, qlen, status = 0;
if (is_iso) {
switch (speed) {
case USB_SPEED_SUPER:
size = ss->isoc_maxpacket *
(ss->isoc_mult + 1) *
(ss->isoc_maxburst + 1);
break;
case USB_SPEED_HIGH:
size = ss->isoc_maxpacket * (ss->isoc_mult + 1);
break;
default:
size = ss->isoc_maxpacket > 1023 ?
1023 : ss->isoc_maxpacket;
break;
}
ep = is_in ? ss->iso_in_ep : ss->iso_out_ep;
qlen = ss->iso_qlen;
} else {
ep = is_in ? ss->in_ep : ss->out_ep;
qlen = ss->bulk_qlen;
size = ss->buflen;
}
for (i = 0; i < qlen; i++) {
req = ss_alloc_ep_req(ep, size);
if (!req)
return -ENOMEM;
req->complete = source_sink_complete;
if (is_in)
reinit_write_data(ep, req);
else if (ss->pattern != 2)
memset(req->buf, 0x55, req->length);
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status) {
struct usb_composite_dev *cdev;
cdev = ss->function.config->cdev;
ERROR(cdev, "start %s%s %s --> %d\n",
is_iso ? "ISO-" : "", is_in ? "IN" : "OUT",
ep->name, status);
free_ep_req(ep, req);
return status;
}
}
return status;
}
static void disable_source_sink(struct f_sourcesink *ss)
{
struct usb_composite_dev *cdev;
cdev = ss->function.config->cdev;
disable_endpoints(cdev, ss->in_ep, ss->out_ep, ss->iso_in_ep,
ss->iso_out_ep);
VDBG(cdev, "%s disabled\n", ss->function.name);
}
static int
enable_source_sink(struct usb_composite_dev *cdev, struct f_sourcesink *ss,
int alt)
{
int result = 0;
int speed = cdev->gadget->speed;
struct usb_ep *ep;
ep = ss->in_ep;
result = config_ep_by_speed(cdev->gadget, &(ss->function), ep);
if (result)
return result;
result = usb_ep_enable(ep);
if (result < 0)
return result;
ep->driver_data = ss;
result = source_sink_start_ep(ss, true, false, speed);
if (result < 0) {
fail:
ep = ss->in_ep;
usb_ep_disable(ep);
return result;
}
ep = ss->out_ep;
result = config_ep_by_speed(cdev->gadget, &(ss->function), ep);
if (result)
goto fail;
result = usb_ep_enable(ep);
if (result < 0)
goto fail;
ep->driver_data = ss;
result = source_sink_start_ep(ss, false, false, speed);
if (result < 0) {
fail2:
ep = ss->out_ep;
usb_ep_disable(ep);
goto fail;
}
if (alt == 0)
goto out;
ep = ss->iso_in_ep;
if (ep) {
result = config_ep_by_speed(cdev->gadget, &(ss->function), ep);
if (result)
goto fail2;
result = usb_ep_enable(ep);
if (result < 0)
goto fail2;
ep->driver_data = ss;
result = source_sink_start_ep(ss, true, true, speed);
if (result < 0) {
fail3:
ep = ss->iso_in_ep;
if (ep)
usb_ep_disable(ep);
goto fail2;
}
}
ep = ss->iso_out_ep;
if (ep) {
result = config_ep_by_speed(cdev->gadget, &(ss->function), ep);
if (result)
goto fail3;
result = usb_ep_enable(ep);
if (result < 0)
goto fail3;
ep->driver_data = ss;
result = source_sink_start_ep(ss, false, true, speed);
if (result < 0) {
usb_ep_disable(ep);
goto fail3;
}
}
out:
ss->cur_alt = alt;
DBG(cdev, "%s enabled, alt intf %d\n", ss->function.name, alt);
return result;
}
static int sourcesink_set_alt(struct usb_function *f,
unsigned intf, unsigned alt)
{
struct f_sourcesink *ss = func_to_ss(f);
struct usb_composite_dev *cdev = f->config->cdev;
disable_source_sink(ss);
return enable_source_sink(cdev, ss, alt);
}
static int sourcesink_get_alt(struct usb_function *f, unsigned intf)
{
struct f_sourcesink *ss = func_to_ss(f);
return ss->cur_alt;
}
static void sourcesink_disable(struct usb_function *f)
{
struct f_sourcesink *ss = func_to_ss(f);
disable_source_sink(ss);
}
static int sourcesink_setup(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct usb_configuration *c = f->config;
struct usb_request *req = c->cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
req->length = USB_COMP_EP0_BUFSIZ;
switch (ctrl->bRequest) {
case 0x5b:
if (ctrl->bRequestType != (USB_DIR_OUT|USB_TYPE_VENDOR))
goto unknown;
if (w_value || w_index)
break;
if (w_length > req->length)
break;
value = w_length;
break;
case 0x5c:
if (ctrl->bRequestType != (USB_DIR_IN|USB_TYPE_VENDOR))
goto unknown;
if (w_value || w_index)
break;
if (w_length > req->length)
break;
value = w_length;
break;
default:
unknown:
VDBG(c->cdev,
"unknown control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
VDBG(c->cdev, "source/sink req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
req->zero = 0;
req->length = value;
value = usb_ep_queue(c->cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0)
ERROR(c->cdev, "source/sink response, err %d\n",
value);
}
return value;
}
static struct usb_function *source_sink_alloc_func(
struct usb_function_instance *fi)
{
struct f_sourcesink *ss;
struct f_ss_opts *ss_opts;
ss = kzalloc(sizeof(*ss), GFP_KERNEL);
if (!ss)
return NULL;
ss_opts = container_of(fi, struct f_ss_opts, func_inst);
mutex_lock(&ss_opts->lock);
ss_opts->refcnt++;
mutex_unlock(&ss_opts->lock);
ss->pattern = ss_opts->pattern;
ss->isoc_interval = ss_opts->isoc_interval;
ss->isoc_maxpacket = ss_opts->isoc_maxpacket;
ss->isoc_mult = ss_opts->isoc_mult;
ss->isoc_maxburst = ss_opts->isoc_maxburst;
ss->buflen = ss_opts->bulk_buflen;
ss->bulk_qlen = ss_opts->bulk_qlen;
ss->iso_qlen = ss_opts->iso_qlen;
ss->function.name = "source/sink";
ss->function.bind = sourcesink_bind;
ss->function.set_alt = sourcesink_set_alt;
ss->function.get_alt = sourcesink_get_alt;
ss->function.disable = sourcesink_disable;
ss->function.setup = sourcesink_setup;
ss->function.strings = sourcesink_strings;
ss->function.free_func = sourcesink_free_func;
return &ss->function;
}
static inline struct f_ss_opts *to_f_ss_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_ss_opts,
func_inst.group);
}
static void ss_attr_release(struct config_item *item)
{
struct f_ss_opts *ss_opts = to_f_ss_opts(item);
usb_put_function_instance(&ss_opts->func_inst);
}
static ssize_t f_ss_opts_pattern_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->pattern);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_pattern_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int ret;
u8 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou8(page, 0, &num);
if (ret)
goto end;
if (num != 0 && num != 1 && num != 2) {
ret = -EINVAL;
goto end;
}
opts->pattern = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_isoc_interval_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->isoc_interval);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_isoc_interval_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int ret;
u8 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou8(page, 0, &num);
if (ret)
goto end;
if (num > 16) {
ret = -EINVAL;
goto end;
}
opts->isoc_interval = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_isoc_maxpacket_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->isoc_maxpacket);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_isoc_maxpacket_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int ret;
u16 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou16(page, 0, &num);
if (ret)
goto end;
if (num > 1024) {
ret = -EINVAL;
goto end;
}
opts->isoc_maxpacket = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_isoc_mult_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->isoc_mult);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_isoc_mult_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int ret;
u8 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou8(page, 0, &num);
if (ret)
goto end;
if (num > 2) {
ret = -EINVAL;
goto end;
}
opts->isoc_mult = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_isoc_maxburst_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->isoc_maxburst);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_isoc_maxburst_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int ret;
u8 num;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = kstrtou8(page, 0, &num);
if (ret)
goto end;
if (num > 15) {
ret = -EINVAL;
goto end;
}
opts->isoc_maxburst = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_bulk_buflen_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->bulk_buflen);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_bulk_buflen_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
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
static ssize_t f_ss_opts_bulk_qlen_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->bulk_qlen);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_bulk_qlen_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
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
opts->bulk_qlen = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static ssize_t f_ss_opts_iso_qlen_show(struct config_item *item, char *page)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
int result;
mutex_lock(&opts->lock);
result = sprintf(page, "%u\n", opts->iso_qlen);
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_ss_opts_iso_qlen_store(struct config_item *item,
const char *page, size_t len)
{
struct f_ss_opts *opts = to_f_ss_opts(item);
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
opts->iso_qlen = num;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static void source_sink_free_instance(struct usb_function_instance *fi)
{
struct f_ss_opts *ss_opts;
ss_opts = container_of(fi, struct f_ss_opts, func_inst);
kfree(ss_opts);
}
static struct usb_function_instance *source_sink_alloc_inst(void)
{
struct f_ss_opts *ss_opts;
ss_opts = kzalloc(sizeof(*ss_opts), GFP_KERNEL);
if (!ss_opts)
return ERR_PTR(-ENOMEM);
mutex_init(&ss_opts->lock);
ss_opts->func_inst.free_func_inst = source_sink_free_instance;
ss_opts->isoc_interval = GZERO_ISOC_INTERVAL;
ss_opts->isoc_maxpacket = GZERO_ISOC_MAXPACKET;
ss_opts->bulk_buflen = GZERO_BULK_BUFLEN;
ss_opts->bulk_qlen = GZERO_SS_BULK_QLEN;
ss_opts->iso_qlen = GZERO_SS_ISO_QLEN;
config_group_init_type_name(&ss_opts->func_inst.group, "",
&ss_func_type);
return &ss_opts->func_inst;
}
static int __init sslb_modinit(void)
{
int ret;
ret = usb_function_register(&SourceSinkusb_func);
if (ret)
return ret;
ret = lb_modinit();
if (ret)
usb_function_unregister(&SourceSinkusb_func);
return ret;
}
static void __exit sslb_modexit(void)
{
usb_function_unregister(&SourceSinkusb_func);
lb_modexit();
}
