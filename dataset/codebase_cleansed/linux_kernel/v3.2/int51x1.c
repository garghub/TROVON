static int int51x1_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
int len;
if (!(pskb_may_pull(skb, INT51X1_HEADER_SIZE))) {
netdev_err(dev->net, "unexpected tiny rx frame\n");
return 0;
}
len = le16_to_cpu(*(__le16 *)&skb->data[skb->len - 2]);
skb_trim(skb, len);
return 1;
}
static struct sk_buff *int51x1_tx_fixup(struct usbnet *dev,
struct sk_buff *skb, gfp_t flags)
{
int pack_len = skb->len;
int pack_with_header_len = pack_len + INT51X1_HEADER_SIZE;
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
int need_tail = 0;
__le16 *len;
if ((pack_with_header_len) < dev->maxpacket)
need_tail = dev->maxpacket - pack_with_header_len + 1;
else if (!(pack_with_header_len % dev->maxpacket))
need_tail = 1;
if (!skb_cloned(skb) &&
(headroom + tailroom >= need_tail + INT51X1_HEADER_SIZE)) {
if (headroom < INT51X1_HEADER_SIZE || tailroom < need_tail) {
skb->data = memmove(skb->head + INT51X1_HEADER_SIZE,
skb->data, skb->len);
skb_set_tail_pointer(skb, skb->len);
}
} else {
struct sk_buff *skb2;
skb2 = skb_copy_expand(skb,
INT51X1_HEADER_SIZE,
need_tail,
flags);
dev_kfree_skb_any(skb);
if (!skb2)
return NULL;
skb = skb2;
}
pack_len += need_tail;
pack_len &= 0x07ff;
len = (__le16 *) __skb_push(skb, INT51X1_HEADER_SIZE);
*len = cpu_to_le16(pack_len);
if(need_tail)
memset(__skb_put(skb, need_tail), 0, need_tail);
return skb;
}
static void int51x1_async_cmd_callback(struct urb *urb)
{
struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
int status = urb->status;
if (status < 0)
dev_warn(&urb->dev->dev, "async callback failed with %d\n", status);
kfree(req);
usb_free_urb(urb);
}
static void int51x1_set_multicast(struct net_device *netdev)
{
struct usb_ctrlrequest *req;
int status;
struct urb *urb;
struct usbnet *dev = netdev_priv(netdev);
u16 filter = PACKET_TYPE_DIRECTED | PACKET_TYPE_BROADCAST;
if (netdev->flags & IFF_PROMISC) {
filter |= PACKET_TYPE_PROMISCUOUS;
netdev_info(dev->net, "promiscuous mode enabled\n");
} else if (!netdev_mc_empty(netdev) ||
(netdev->flags & IFF_ALLMULTI)) {
filter |= PACKET_TYPE_ALL_MULTICAST;
netdev_dbg(dev->net, "receive all multicast enabled\n");
} else {
netdev_dbg(dev->net, "receive own packets only\n");
}
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_warn(dev->net, "Error allocating URB\n");
return;
}
req = kmalloc(sizeof(*req), GFP_ATOMIC);
if (!req) {
netdev_warn(dev->net, "Error allocating control msg\n");
goto out;
}
req->bRequestType = USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE;
req->bRequest = SET_ETHERNET_PACKET_FILTER;
req->wValue = cpu_to_le16(filter);
req->wIndex = 0;
req->wLength = 0;
usb_fill_control_urb(urb, dev->udev, usb_sndctrlpipe(dev->udev, 0),
(void *)req, NULL, 0,
int51x1_async_cmd_callback,
(void *)req);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
netdev_warn(dev->net, "Error submitting control msg, sts=%d\n",
status);
goto out1;
}
return;
out1:
kfree(req);
out:
usb_free_urb(urb);
}
static int int51x1_bind(struct usbnet *dev, struct usb_interface *intf)
{
int status = usbnet_get_ethernet_addr(dev, 3);
if (status)
return status;
dev->net->hard_header_len += INT51X1_HEADER_SIZE;
dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
dev->net->netdev_ops = &int51x1_netdev_ops;
return usbnet_get_endpoints(dev, intf);
}
static int __init int51x1_init(void)
{
return usb_register(&int51x1_driver);
}
static void __exit int51x1_exit(void)
{
usb_deregister(&int51x1_driver);
}
