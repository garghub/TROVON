static inline struct f_eem *func_to_eem(struct usb_function *f)
{
return container_of(f, struct f_eem, port.func);
}
static int eem_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct usb_composite_dev *cdev = f->config->cdev;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
DBG(cdev, "invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
return value;
}
static int eem_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_eem *eem = func_to_eem(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct net_device *net;
if (alt != 0)
goto fail;
if (intf == eem->ctrl_id) {
if (eem->port.in_ep->driver_data) {
DBG(cdev, "reset eem\n");
gether_disconnect(&eem->port);
}
if (!eem->port.in_ep->desc || !eem->port.out_ep->desc) {
DBG(cdev, "init eem\n");
if (config_ep_by_speed(cdev->gadget, f,
eem->port.in_ep) ||
config_ep_by_speed(cdev->gadget, f,
eem->port.out_ep)) {
eem->port.in_ep->desc = NULL;
eem->port.out_ep->desc = NULL;
goto fail;
}
}
eem->port.is_zlp_ok = 1;
eem->port.cdc_filter = DEFAULT_FILTER;
DBG(cdev, "activate eem\n");
net = gether_connect(&eem->port);
if (IS_ERR(net))
return PTR_ERR(net);
} else
goto fail;
return 0;
fail:
return -EINVAL;
}
static void eem_disable(struct usb_function *f)
{
struct f_eem *eem = func_to_eem(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "eem deactivated\n");
if (eem->port.in_ep->driver_data)
gether_disconnect(&eem->port);
}
static int __init
eem_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_eem *eem = func_to_eem(f);
int status;
struct usb_ep *ep;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
eem->ctrl_id = status;
eem_intf.bInterfaceNumber = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &eem_fs_in_desc);
if (!ep)
goto fail;
eem->port.in_ep = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &eem_fs_out_desc);
if (!ep)
goto fail;
eem->port.out_ep = ep;
ep->driver_data = cdev;
status = -ENOMEM;
f->descriptors = usb_copy_descriptors(eem_fs_function);
if (!f->descriptors)
goto fail;
if (gadget_is_dualspeed(c->cdev->gadget)) {
eem_hs_in_desc.bEndpointAddress =
eem_fs_in_desc.bEndpointAddress;
eem_hs_out_desc.bEndpointAddress =
eem_fs_out_desc.bEndpointAddress;
f->hs_descriptors = usb_copy_descriptors(eem_hs_function);
if (!f->hs_descriptors)
goto fail;
}
if (gadget_is_superspeed(c->cdev->gadget)) {
eem_ss_in_desc.bEndpointAddress =
eem_fs_in_desc.bEndpointAddress;
eem_ss_out_desc.bEndpointAddress =
eem_fs_out_desc.bEndpointAddress;
f->ss_descriptors = usb_copy_descriptors(eem_ss_function);
if (!f->ss_descriptors)
goto fail;
}
DBG(cdev, "CDC Ethernet (EEM): %s speed IN/%s OUT/%s\n",
gadget_is_superspeed(c->cdev->gadget) ? "super" :
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
eem->port.in_ep->name, eem->port.out_ep->name);
return 0;
fail:
if (f->descriptors)
usb_free_descriptors(f->descriptors);
if (f->hs_descriptors)
usb_free_descriptors(f->hs_descriptors);
if (eem->port.out_ep->desc)
eem->port.out_ep->driver_data = NULL;
if (eem->port.in_ep->desc)
eem->port.in_ep->driver_data = NULL;
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static void
eem_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_eem *eem = func_to_eem(f);
DBG(c->cdev, "eem unbind\n");
if (gadget_is_superspeed(c->cdev->gadget))
usb_free_descriptors(f->ss_descriptors);
if (gadget_is_dualspeed(c->cdev->gadget))
usb_free_descriptors(f->hs_descriptors);
usb_free_descriptors(f->descriptors);
kfree(eem);
}
static void eem_cmd_complete(struct usb_ep *ep, struct usb_request *req)
{
struct sk_buff *skb = (struct sk_buff *)req->context;
dev_kfree_skb_any(skb);
}
static struct sk_buff *eem_wrap(struct gether *port, struct sk_buff *skb)
{
struct sk_buff *skb2 = NULL;
struct usb_ep *in = port->in_ep;
int padlen = 0;
u16 len = skb->len;
if (!skb_cloned(skb)) {
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
if (((len + EEM_HLEN + ETH_FCS_LEN) % in->maxpacket) == 0)
padlen += 2;
if ((tailroom >= (ETH_FCS_LEN + padlen)) &&
(headroom >= EEM_HLEN))
goto done;
}
skb2 = skb_copy_expand(skb, EEM_HLEN, ETH_FCS_LEN + padlen, GFP_ATOMIC);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return skb;
done:
put_unaligned_be32(0xdeadbeef, skb_put(skb, 4));
len = skb->len;
put_unaligned_le16(len & 0x3FFF, skb_push(skb, 2));
if (padlen)
put_unaligned_le16(0, skb_put(skb, 2));
return skb;
}
static int eem_unwrap(struct gether *port,
struct sk_buff *skb,
struct sk_buff_head *list)
{
struct usb_composite_dev *cdev = port->func.config->cdev;
int status = 0;
do {
struct sk_buff *skb2;
u16 header;
u16 len = 0;
if (skb->len < EEM_HLEN) {
status = -EINVAL;
DBG(cdev, "invalid EEM header\n");
goto error;
}
header = get_unaligned_le16(skb->data);
skb_pull(skb, EEM_HLEN);
if (header & BIT(15)) {
struct usb_request *req = cdev->req;
u16 bmEEMCmd;
if (header & BIT(14))
continue;
bmEEMCmd = (header >> 11) & 0x7;
switch (bmEEMCmd) {
case 0:
len = header & 0x7FF;
if (skb->len < len) {
status = -EOVERFLOW;
goto error;
}
skb2 = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb2)) {
DBG(cdev, "EEM echo response error\n");
goto next;
}
skb_trim(skb2, len);
put_unaligned_le16(BIT(15) | BIT(11) | len,
skb_push(skb2, 2));
skb_copy_bits(skb2, 0, req->buf, skb2->len);
req->length = skb2->len;
req->complete = eem_cmd_complete;
req->zero = 1;
req->context = skb2;
if (usb_ep_queue(port->in_ep, req, GFP_ATOMIC))
DBG(cdev, "echo response queue fail\n");
break;
case 1:
case 2:
case 3:
case 4:
case 5:
default:
continue;
}
} else {
u32 crc, crc2;
struct sk_buff *skb3;
if (header == 0)
continue;
len = header & 0x3FFF;
if ((skb->len < len)
|| (len < (ETH_HLEN + ETH_FCS_LEN))) {
status = -EINVAL;
goto error;
}
if (header & BIT(14)) {
crc = get_unaligned_le32(skb->data + len
- ETH_FCS_LEN);
crc2 = ~crc32_le(~0,
skb->data, len - ETH_FCS_LEN);
} else {
crc = get_unaligned_be32(skb->data + len
- ETH_FCS_LEN);
crc2 = 0xdeadbeef;
}
if (crc != crc2) {
DBG(cdev, "invalid EEM CRC\n");
goto next;
}
skb2 = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb2)) {
DBG(cdev, "unable to unframe EEM packet\n");
continue;
}
skb_trim(skb2, len - ETH_FCS_LEN);
skb3 = skb_copy_expand(skb2,
NET_IP_ALIGN,
0,
GFP_ATOMIC);
if (unlikely(!skb3)) {
DBG(cdev, "unable to realign EEM packet\n");
dev_kfree_skb_any(skb2);
continue;
}
dev_kfree_skb_any(skb2);
skb_queue_tail(list, skb3);
}
next:
skb_pull(skb, len);
} while (skb->len);
error:
dev_kfree_skb_any(skb);
return status;
}
int __init eem_bind_config(struct usb_configuration *c)
{
struct f_eem *eem;
int status;
if (eem_string_defs[0].id == 0) {
status = usb_string_id(c->cdev);
if (status < 0)
return status;
eem_string_defs[0].id = status;
eem_intf.iInterface = status;
}
eem = kzalloc(sizeof *eem, GFP_KERNEL);
if (!eem)
return -ENOMEM;
eem->port.cdc_filter = DEFAULT_FILTER;
eem->port.func.name = "cdc_eem";
eem->port.func.strings = eem_strings;
eem->port.func.bind = eem_bind;
eem->port.func.unbind = eem_unbind;
eem->port.func.set_alt = eem_set_alt;
eem->port.func.setup = eem_setup;
eem->port.func.disable = eem_disable;
eem->port.wrap = eem_wrap;
eem->port.unwrap = eem_unwrap;
eem->port.header_len = EEM_HLEN;
status = usb_add_function(c, &eem->port.func);
if (status)
kfree(eem);
return status;
}
