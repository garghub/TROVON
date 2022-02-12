static inline struct f_rndis *func_to_rndis(struct usb_function *f)
{
return container_of(f, struct f_rndis, port.func);
}
static unsigned int bitrate(struct usb_gadget *g)
{
if (gadget_is_superspeed(g) && g->speed == USB_SPEED_SUPER)
return 13 * 1024 * 8 * 1000 * 8;
else if (gadget_is_dualspeed(g) && g->speed == USB_SPEED_HIGH)
return 13 * 512 * 8 * 1000 * 8;
else
return 19 * 64 * 1 * 1000 * 8;
}
static struct sk_buff *rndis_add_header(struct gether *port,
struct sk_buff *skb)
{
struct sk_buff *skb2;
skb2 = skb_realloc_headroom(skb, sizeof(struct rndis_packet_msg_type));
if (skb2)
rndis_add_hdr(skb2);
dev_kfree_skb_any(skb);
return skb2;
}
static void rndis_response_available(void *_rndis)
{
struct f_rndis *rndis = _rndis;
struct usb_request *req = rndis->notify_req;
struct usb_composite_dev *cdev = rndis->port.func.config->cdev;
__le32 *data = req->buf;
int status;
if (atomic_inc_return(&rndis->notify_count) != 1)
return;
data[0] = cpu_to_le32(1);
data[1] = cpu_to_le32(0);
status = usb_ep_queue(rndis->notify, req, GFP_ATOMIC);
if (status) {
atomic_dec(&rndis->notify_count);
DBG(cdev, "notify/0 --> %d\n", status);
}
}
static void rndis_response_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_rndis *rndis = req->context;
struct usb_composite_dev *cdev = rndis->port.func.config->cdev;
int status = req->status;
switch (status) {
case -ECONNRESET:
case -ESHUTDOWN:
atomic_set(&rndis->notify_count, 0);
break;
default:
DBG(cdev, "RNDIS %s response error %d, %d/%d\n",
ep->name, status,
req->actual, req->length);
case 0:
if (ep != rndis->notify)
break;
if (atomic_dec_and_test(&rndis->notify_count))
break;
status = usb_ep_queue(rndis->notify, req, GFP_ATOMIC);
if (status) {
atomic_dec(&rndis->notify_count);
DBG(cdev, "notify/1 --> %d\n", status);
}
break;
}
}
static void rndis_command_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_rndis *rndis = req->context;
int status;
status = rndis_msg_parser(rndis->config, (u8 *) req->buf);
if (status < 0)
pr_err("RNDIS command error %d, %d/%d\n",
status, req->actual, req->length);
}
static int
rndis_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct f_rndis *rndis = func_to_rndis(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
switch ((ctrl->bRequestType << 8) | ctrl->bRequest) {
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_SEND_ENCAPSULATED_COMMAND:
if (w_value || w_index != rndis->ctrl_id)
goto invalid;
value = w_length;
req->complete = rndis_command_complete;
req->context = rndis;
break;
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_GET_ENCAPSULATED_RESPONSE:
if (w_value || w_index != rndis->ctrl_id)
goto invalid;
else {
u8 *buf;
u32 n;
buf = rndis_get_next_response(rndis->config, &n);
if (buf) {
memcpy(req->buf, buf, n);
req->complete = rndis_response_complete;
req->context = rndis;
rndis_free_response(rndis->config, buf);
value = n;
}
}
break;
default:
invalid:
VDBG(cdev, "invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
DBG(cdev, "rndis req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
req->zero = (value < w_length);
req->length = value;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0)
ERROR(cdev, "rndis response on err %d\n", value);
}
return value;
}
static int rndis_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_rndis *rndis = func_to_rndis(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (intf == rndis->ctrl_id) {
if (rndis->notify->driver_data) {
VDBG(cdev, "reset rndis control %d\n", intf);
usb_ep_disable(rndis->notify);
}
if (!rndis->notify->desc) {
VDBG(cdev, "init rndis ctrl %d\n", intf);
if (config_ep_by_speed(cdev->gadget, f, rndis->notify))
goto fail;
}
usb_ep_enable(rndis->notify);
rndis->notify->driver_data = rndis;
} else if (intf == rndis->data_id) {
struct net_device *net;
if (rndis->port.in_ep->driver_data) {
DBG(cdev, "reset rndis\n");
gether_disconnect(&rndis->port);
}
if (!rndis->port.in_ep->desc || !rndis->port.out_ep->desc) {
DBG(cdev, "init rndis\n");
if (config_ep_by_speed(cdev->gadget, f,
rndis->port.in_ep) ||
config_ep_by_speed(cdev->gadget, f,
rndis->port.out_ep)) {
rndis->port.in_ep->desc = NULL;
rndis->port.out_ep->desc = NULL;
goto fail;
}
}
rndis->port.is_zlp_ok = false;
rndis->port.cdc_filter = 0;
DBG(cdev, "RNDIS RX/TX early activation ... \n");
net = gether_connect(&rndis->port);
if (IS_ERR(net))
return PTR_ERR(net);
rndis_set_param_dev(rndis->config, net,
&rndis->port.cdc_filter);
} else
goto fail;
return 0;
fail:
return -EINVAL;
}
static void rndis_disable(struct usb_function *f)
{
struct f_rndis *rndis = func_to_rndis(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (!rndis->notify->driver_data)
return;
DBG(cdev, "rndis deactivated\n");
rndis_uninit(rndis->config);
gether_disconnect(&rndis->port);
usb_ep_disable(rndis->notify);
rndis->notify->driver_data = NULL;
}
static void rndis_open(struct gether *geth)
{
struct f_rndis *rndis = func_to_rndis(&geth->func);
struct usb_composite_dev *cdev = geth->func.config->cdev;
DBG(cdev, "%s\n", __func__);
rndis_set_param_medium(rndis->config, RNDIS_MEDIUM_802_3,
bitrate(cdev->gadget) / 100);
rndis_signal_connect(rndis->config);
}
static void rndis_close(struct gether *geth)
{
struct f_rndis *rndis = func_to_rndis(&geth->func);
DBG(geth->func.config->cdev, "%s\n", __func__);
rndis_set_param_medium(rndis->config, RNDIS_MEDIUM_802_3, 0);
rndis_signal_disconnect(rndis->config);
}
static int
rndis_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_rndis *rndis = func_to_rndis(f);
int status;
struct usb_ep *ep;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
rndis->ctrl_id = status;
rndis_iad_descriptor.bFirstInterface = status;
rndis_control_intf.bInterfaceNumber = status;
rndis_union_desc.bMasterInterface0 = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
rndis->data_id = status;
rndis_data_intf.bInterfaceNumber = status;
rndis_union_desc.bSlaveInterface0 = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &fs_in_desc);
if (!ep)
goto fail;
rndis->port.in_ep = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &fs_out_desc);
if (!ep)
goto fail;
rndis->port.out_ep = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &fs_notify_desc);
if (!ep)
goto fail;
rndis->notify = ep;
ep->driver_data = cdev;
status = -ENOMEM;
rndis->notify_req = usb_ep_alloc_request(ep, GFP_KERNEL);
if (!rndis->notify_req)
goto fail;
rndis->notify_req->buf = kmalloc(STATUS_BYTECOUNT, GFP_KERNEL);
if (!rndis->notify_req->buf)
goto fail;
rndis->notify_req->length = STATUS_BYTECOUNT;
rndis->notify_req->context = rndis;
rndis->notify_req->complete = rndis_response_complete;
hs_in_desc.bEndpointAddress = fs_in_desc.bEndpointAddress;
hs_out_desc.bEndpointAddress = fs_out_desc.bEndpointAddress;
hs_notify_desc.bEndpointAddress = fs_notify_desc.bEndpointAddress;
ss_in_desc.bEndpointAddress = fs_in_desc.bEndpointAddress;
ss_out_desc.bEndpointAddress = fs_out_desc.bEndpointAddress;
ss_notify_desc.bEndpointAddress = fs_notify_desc.bEndpointAddress;
status = usb_assign_descriptors(f, eth_fs_function, eth_hs_function,
eth_ss_function);
if (status)
goto fail;
rndis->port.open = rndis_open;
rndis->port.close = rndis_close;
status = rndis_register(rndis_response_available, rndis);
if (status < 0)
goto fail;
rndis->config = status;
rndis_set_param_medium(rndis->config, RNDIS_MEDIUM_802_3, 0);
rndis_set_host_mac(rndis->config, rndis->ethaddr);
if (rndis->manufacturer && rndis->vendorID &&
rndis_set_param_vendor(rndis->config, rndis->vendorID,
rndis->manufacturer))
goto fail;
DBG(cdev, "RNDIS: %s speed IN/%s OUT/%s NOTIFY/%s\n",
gadget_is_superspeed(c->cdev->gadget) ? "super" :
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
rndis->port.in_ep->name, rndis->port.out_ep->name,
rndis->notify->name);
return 0;
fail:
usb_free_all_descriptors(f);
if (rndis->notify_req) {
kfree(rndis->notify_req->buf);
usb_ep_free_request(rndis->notify, rndis->notify_req);
}
if (rndis->notify)
rndis->notify->driver_data = NULL;
if (rndis->port.out_ep)
rndis->port.out_ep->driver_data = NULL;
if (rndis->port.in_ep)
rndis->port.in_ep->driver_data = NULL;
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static void
rndis_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_rndis *rndis = func_to_rndis(f);
rndis_deregister(rndis->config);
rndis_exit();
rndis_string_defs[0].id = 0;
usb_free_all_descriptors(f);
kfree(rndis->notify_req->buf);
usb_ep_free_request(rndis->notify, rndis->notify_req);
kfree(rndis);
}
static inline bool can_support_rndis(struct usb_configuration *c)
{
return true;
}
int
rndis_bind_config_vendor(struct usb_configuration *c, u8 ethaddr[ETH_ALEN],
u32 vendorID, const char *manufacturer, struct eth_dev *dev)
{
struct f_rndis *rndis;
int status;
if (!can_support_rndis(c) || !ethaddr)
return -EINVAL;
if (rndis_string_defs[0].id == 0) {
status = rndis_init();
if (status < 0)
return status;
status = usb_string_ids_tab(c->cdev, rndis_string_defs);
if (status)
return status;
rndis_control_intf.iInterface = rndis_string_defs[0].id;
rndis_data_intf.iInterface = rndis_string_defs[1].id;
rndis_iad_descriptor.iFunction = rndis_string_defs[2].id;
}
status = -ENOMEM;
rndis = kzalloc(sizeof *rndis, GFP_KERNEL);
if (!rndis)
goto fail;
memcpy(rndis->ethaddr, ethaddr, ETH_ALEN);
rndis->vendorID = vendorID;
rndis->manufacturer = manufacturer;
rndis->port.ioport = dev;
rndis->port.cdc_filter = 0;
rndis->port.header_len = sizeof(struct rndis_packet_msg_type);
rndis->port.wrap = rndis_add_header;
rndis->port.unwrap = rndis_rm_hdr;
rndis->port.func.name = "rndis";
rndis->port.func.strings = rndis_strings;
rndis->port.func.bind = rndis_bind;
rndis->port.func.unbind = rndis_unbind;
rndis->port.func.set_alt = rndis_set_alt;
rndis->port.func.setup = rndis_setup;
rndis->port.func.disable = rndis_disable;
status = usb_add_function(c, &rndis->port.func);
if (status) {
kfree(rndis);
fail:
rndis_exit();
}
return status;
}
