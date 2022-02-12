static inline struct f_sourcesink *func_to_ss(struct usb_function *f)
{
return container_of(f, struct f_sourcesink, function);
}
static int __init
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
ss->in_ep->driver_data = cdev;
ss->out_ep = usb_ep_autoconfig(cdev->gadget, &fs_sink_desc);
if (!ss->out_ep)
goto autoconf_fail;
ss->out_ep->driver_data = cdev;
if (isoc_interval < 1)
isoc_interval = 1;
if (isoc_interval > 16)
isoc_interval = 16;
if (isoc_mult > 2)
isoc_mult = 2;
if (isoc_maxburst > 15)
isoc_maxburst = 15;
fs_iso_source_desc.wMaxPacketSize = isoc_maxpacket > 1023 ?
1023 : isoc_maxpacket;
fs_iso_source_desc.bInterval = isoc_interval;
fs_iso_sink_desc.wMaxPacketSize = isoc_maxpacket > 1023 ?
1023 : isoc_maxpacket;
fs_iso_sink_desc.bInterval = isoc_interval;
ss->iso_in_ep = usb_ep_autoconfig(cdev->gadget, &fs_iso_source_desc);
if (!ss->iso_in_ep)
goto no_iso;
ss->iso_in_ep->driver_data = cdev;
ss->iso_out_ep = usb_ep_autoconfig(cdev->gadget, &fs_iso_sink_desc);
if (ss->iso_out_ep) {
ss->iso_out_ep->driver_data = cdev;
} else {
ss->iso_in_ep->driver_data = NULL;
ss->iso_in_ep = NULL;
no_iso:
fs_source_sink_descs[FS_ALT_IFC_1_OFFSET] = NULL;
hs_source_sink_descs[HS_ALT_IFC_1_OFFSET] = NULL;
ss_source_sink_descs[SS_ALT_IFC_1_OFFSET] = NULL;
}
if (isoc_maxpacket > 1024)
isoc_maxpacket = 1024;
hs_source_desc.bEndpointAddress = fs_source_desc.bEndpointAddress;
hs_sink_desc.bEndpointAddress = fs_sink_desc.bEndpointAddress;
hs_iso_source_desc.wMaxPacketSize = isoc_maxpacket;
hs_iso_source_desc.wMaxPacketSize |= isoc_mult << 11;
hs_iso_source_desc.bInterval = isoc_interval;
hs_iso_source_desc.bEndpointAddress =
fs_iso_source_desc.bEndpointAddress;
hs_iso_sink_desc.wMaxPacketSize = isoc_maxpacket;
hs_iso_sink_desc.wMaxPacketSize |= isoc_mult << 11;
hs_iso_sink_desc.bInterval = isoc_interval;
hs_iso_sink_desc.bEndpointAddress = fs_iso_sink_desc.bEndpointAddress;
ss_source_desc.bEndpointAddress =
fs_source_desc.bEndpointAddress;
ss_sink_desc.bEndpointAddress =
fs_sink_desc.bEndpointAddress;
ss_iso_source_desc.wMaxPacketSize = isoc_maxpacket;
ss_iso_source_desc.bInterval = isoc_interval;
ss_iso_source_comp_desc.bmAttributes = isoc_mult;
ss_iso_source_comp_desc.bMaxBurst = isoc_maxburst;
ss_iso_source_comp_desc.wBytesPerInterval =
isoc_maxpacket * (isoc_mult + 1) * (isoc_maxburst + 1);
ss_iso_source_desc.bEndpointAddress =
fs_iso_source_desc.bEndpointAddress;
ss_iso_sink_desc.wMaxPacketSize = isoc_maxpacket;
ss_iso_sink_desc.bInterval = isoc_interval;
ss_iso_sink_comp_desc.bmAttributes = isoc_mult;
ss_iso_sink_comp_desc.bMaxBurst = isoc_maxburst;
ss_iso_sink_comp_desc.wBytesPerInterval =
isoc_maxpacket * (isoc_mult + 1) * (isoc_maxburst + 1);
ss_iso_sink_desc.bEndpointAddress = fs_iso_sink_desc.bEndpointAddress;
ret = usb_assign_descriptors(f, fs_source_sink_descs,
hs_source_sink_descs, ss_source_sink_descs);
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
sourcesink_unbind(struct usb_configuration *c, struct usb_function *f)
{
usb_free_all_descriptors(f);
kfree(func_to_ss(f));
}
static int check_read_data(struct f_sourcesink *ss, struct usb_request *req)
{
unsigned i;
u8 *buf = req->buf;
struct usb_composite_dev *cdev = ss->function.config->cdev;
if (pattern == 2)
return 0;
for (i = 0; i < req->actual; i++, buf++) {
switch (pattern) {
case 0:
if (*buf == 0)
continue;
break;
case 1:
if (*buf == (u8)(i % 63))
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
switch (pattern) {
case 0:
memset(req->buf, 0, req->length);
break;
case 1:
for (i = 0; i < req->length; i++)
*buf++ = (u8) (i % 63);
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
if (pattern != 2)
memset(req->buf, 0x55, req->length);
} else
reinit_write_data(ep, req);
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
int i, size, status;
for (i = 0; i < 8; i++) {
if (is_iso) {
switch (speed) {
case USB_SPEED_SUPER:
size = isoc_maxpacket * (isoc_mult + 1) *
(isoc_maxburst + 1);
break;
case USB_SPEED_HIGH:
size = isoc_maxpacket * (isoc_mult + 1);
break;
default:
size = isoc_maxpacket > 1023 ?
1023 : isoc_maxpacket;
break;
}
ep = is_in ? ss->iso_in_ep : ss->iso_out_ep;
req = alloc_ep_req(ep, size);
} else {
ep = is_in ? ss->in_ep : ss->out_ep;
req = alloc_ep_req(ep, 0);
}
if (!req)
return -ENOMEM;
req->complete = source_sink_complete;
if (is_in)
reinit_write_data(ep, req);
else if (pattern != 2)
memset(req->buf, 0x55, req->length);
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status) {
struct usb_composite_dev *cdev;
cdev = ss->function.config->cdev;
ERROR(cdev, "start %s%s %s --> %d\n",
is_iso ? "ISO-" : "", is_in ? "IN" : "OUT",
ep->name, status);
free_ep_req(ep, req);
}
if (!is_iso)
break;
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
ep->driver_data = NULL;
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
ep->driver_data = NULL;
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
if (ep) {
usb_ep_disable(ep);
ep->driver_data = NULL;
}
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
ep->driver_data = NULL;
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
if (ss->in_ep->driver_data)
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
static int __init sourcesink_bind_config(struct usb_configuration *c)
{
struct f_sourcesink *ss;
int status;
ss = kzalloc(sizeof *ss, GFP_KERNEL);
if (!ss)
return -ENOMEM;
ss->function.name = "source/sink";
ss->function.bind = sourcesink_bind;
ss->function.unbind = sourcesink_unbind;
ss->function.set_alt = sourcesink_set_alt;
ss->function.get_alt = sourcesink_get_alt;
ss->function.disable = sourcesink_disable;
status = usb_add_function(c, &ss->function);
if (status)
kfree(ss);
return status;
}
static int sourcesink_setup(struct usb_configuration *c,
const struct usb_ctrlrequest *ctrl)
{
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
int __init sourcesink_add(struct usb_composite_dev *cdev, bool autoresume)
{
int id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_sourcesink[0].id = id;
source_sink_intf_alt0.iInterface = id;
source_sink_intf_alt1.iInterface = id;
sourcesink_driver.iConfiguration = id;
if (autoresume)
sourcesink_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
if (gadget_is_otg(cdev->gadget)) {
sourcesink_driver.descriptors = otg_desc;
sourcesink_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
return usb_add_config(cdev, &sourcesink_driver, sourcesink_bind_config);
}
