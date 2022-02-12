static int is_rndis(struct usb_interface_descriptor *desc)
{
return (desc->bInterfaceClass == USB_CLASS_COMM &&
desc->bInterfaceSubClass == 2 &&
desc->bInterfaceProtocol == 0xff);
}
static int is_activesync(struct usb_interface_descriptor *desc)
{
return (desc->bInterfaceClass == USB_CLASS_MISC &&
desc->bInterfaceSubClass == 1 &&
desc->bInterfaceProtocol == 1);
}
static int is_wireless_rndis(struct usb_interface_descriptor *desc)
{
return (desc->bInterfaceClass == USB_CLASS_WIRELESS_CONTROLLER &&
desc->bInterfaceSubClass == 1 &&
desc->bInterfaceProtocol == 3);
}
static void usbnet_cdc_update_filter(struct usbnet *dev)
{
struct cdc_state *info = (void *) &dev->data;
struct usb_interface *intf = info->control;
struct net_device *net = dev->net;
u16 cdc_filter = USB_CDC_PACKET_TYPE_DIRECTED
| USB_CDC_PACKET_TYPE_BROADCAST;
if (net->flags & IFF_PROMISC)
cdc_filter |= USB_CDC_PACKET_TYPE_PROMISCUOUS;
if (!netdev_mc_empty(net) || (net->flags & IFF_ALLMULTI))
cdc_filter |= USB_CDC_PACKET_TYPE_ALL_MULTICAST;
usb_control_msg(dev->udev,
usb_sndctrlpipe(dev->udev, 0),
USB_CDC_SET_ETHERNET_PACKET_FILTER,
USB_TYPE_CLASS | USB_RECIP_INTERFACE,
cdc_filter,
intf->cur_altsetting->desc.bInterfaceNumber,
NULL,
0,
USB_CTRL_SET_TIMEOUT
);
}
int usbnet_generic_cdc_bind(struct usbnet *dev, struct usb_interface *intf)
{
u8 *buf = intf->cur_altsetting->extra;
int len = intf->cur_altsetting->extralen;
struct usb_interface_descriptor *d;
struct cdc_state *info = (void *) &dev->data;
int status;
int rndis;
bool android_rndis_quirk = false;
struct usb_driver *driver = driver_of(intf);
struct usb_cdc_parsed_header header;
if (sizeof(dev->data) < sizeof(*info))
return -EDOM;
if (len == 0 && dev->udev->actconfig->extralen) {
buf = dev->udev->actconfig->extra;
len = dev->udev->actconfig->extralen;
dev_dbg(&intf->dev, "CDC descriptors on config\n");
}
if (len == 0) {
struct usb_host_endpoint *hep;
hep = intf->cur_altsetting->endpoint;
if (hep) {
buf = hep->extra;
len = hep->extralen;
}
if (len)
dev_dbg(&intf->dev,
"CDC descriptors on endpoint\n");
}
rndis = (is_rndis(&intf->cur_altsetting->desc) ||
is_activesync(&intf->cur_altsetting->desc) ||
is_wireless_rndis(&intf->cur_altsetting->desc));
memset(info, 0, sizeof(*info));
info->control = intf;
cdc_parse_cdc_header(&header, intf, buf, len);
info->u = header.usb_cdc_union_desc;
info->header = header.usb_cdc_header_desc;
info->ether = header.usb_cdc_ether_desc;
if (!info->u) {
if (rndis)
goto skip;
else
goto bad_desc;
}
info->control = usb_ifnum_to_if(dev->udev,
info->u->bMasterInterface0);
info->data = usb_ifnum_to_if(dev->udev,
info->u->bSlaveInterface0);
if (!info->control || !info->data) {
dev_dbg(&intf->dev,
"master #%u/%p slave #%u/%p\n",
info->u->bMasterInterface0,
info->control,
info->u->bSlaveInterface0,
info->data);
if (rndis) {
android_rndis_quirk = true;
goto skip;
}
goto bad_desc;
}
if (info->control != intf) {
dev_dbg(&intf->dev, "bogus CDC Union\n");
if (info->data == intf) {
info->data = info->control;
info->control = intf;
} else
goto bad_desc;
}
if (info->control == info->data)
goto skip;
d = &info->data->cur_altsetting->desc;
if (d->bInterfaceClass != USB_CLASS_CDC_DATA) {
dev_dbg(&intf->dev, "slave class %u\n",
d->bInterfaceClass);
goto bad_desc;
}
skip:
if ( rndis &&
header.usb_cdc_acm_descriptor &&
header.usb_cdc_acm_descriptor->bmCapabilities) {
dev_dbg(&intf->dev,
"ACM capabilities %02x, not really RNDIS?\n",
header.usb_cdc_acm_descriptor->bmCapabilities);
goto bad_desc;
}
if (header.usb_cdc_ether_desc) {
dev->hard_mtu = le16_to_cpu(info->ether->wMaxSegmentSize);
}
if (header.usb_cdc_mdlm_desc &&
memcmp(header.usb_cdc_mdlm_desc->bGUID, mbm_guid, 16)) {
dev_dbg(&intf->dev, "GUID doesn't match\n");
goto bad_desc;
}
if (header.usb_cdc_mdlm_detail_desc &&
header.usb_cdc_mdlm_detail_desc->bLength <
(sizeof(struct usb_cdc_mdlm_detail_desc) + 1)) {
dev_dbg(&intf->dev, "Descriptor too short\n");
goto bad_desc;
}
if (rndis && (!info->u || android_rndis_quirk)) {
info->control = usb_ifnum_to_if(dev->udev, 0);
info->data = usb_ifnum_to_if(dev->udev, 1);
if (!info->control || !info->data || info->control != intf) {
dev_dbg(&intf->dev,
"rndis: master #0/%p slave #1/%p\n",
info->control,
info->data);
goto bad_desc;
}
} else if (!info->header || (!rndis && !info->ether)) {
dev_dbg(&intf->dev, "missing cdc %s%s%sdescriptor\n",
info->header ? "" : "header ",
info->u ? "" : "union ",
info->ether ? "" : "ether ");
goto bad_desc;
}
if (info->data != info->control) {
status = usb_driver_claim_interface(driver, info->data, dev);
if (status < 0)
return status;
}
status = usbnet_get_endpoints(dev, info->data);
if (status < 0) {
usb_set_intfdata(info->data, NULL);
if (info->data != info->control)
usb_driver_release_interface(driver, info->data);
return status;
}
if (info->data != info->control)
dev->status = NULL;
if (info->control->cur_altsetting->desc.bNumEndpoints == 1) {
struct usb_endpoint_descriptor *desc;
dev->status = &info->control->cur_altsetting->endpoint [0];
desc = &dev->status->desc;
if (!usb_endpoint_is_int_in(desc) ||
(le16_to_cpu(desc->wMaxPacketSize)
< sizeof(struct usb_cdc_notification)) ||
!desc->bInterval) {
dev_dbg(&intf->dev, "bad notification endpoint\n");
dev->status = NULL;
}
}
if (rndis && !dev->status) {
dev_dbg(&intf->dev, "missing RNDIS status endpoint\n");
usb_set_intfdata(info->data, NULL);
usb_driver_release_interface(driver, info->data);
return -ENODEV;
}
usbnet_cdc_update_filter(dev);
return 0;
bad_desc:
dev_info(&dev->udev->dev, "bad CDC descriptors\n");
return -ENODEV;
}
void usbnet_cdc_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct cdc_state *info = (void *) &dev->data;
struct usb_driver *driver = driver_of(intf);
if (info->data == info->control)
return;
if (intf == info->control && info->data) {
usb_set_intfdata(info->data, NULL);
usb_driver_release_interface(driver, info->data);
info->data = NULL;
}
else if (intf == info->data && info->control) {
usb_set_intfdata(info->control, NULL);
usb_driver_release_interface(driver, info->control);
info->control = NULL;
}
}
static void dumpspeed(struct usbnet *dev, __le32 *speeds)
{
netif_info(dev, timer, dev->net,
"link speeds: %u kbps up, %u kbps down\n",
__le32_to_cpu(speeds[0]) / 1000,
__le32_to_cpu(speeds[1]) / 1000);
}
void usbnet_cdc_status(struct usbnet *dev, struct urb *urb)
{
struct usb_cdc_notification *event;
if (urb->actual_length < sizeof(*event))
return;
if (test_and_clear_bit(EVENT_STS_SPLIT, &dev->flags)) {
dumpspeed(dev, (__le32 *) urb->transfer_buffer);
return;
}
event = urb->transfer_buffer;
switch (event->bNotificationType) {
case USB_CDC_NOTIFY_NETWORK_CONNECTION:
netif_dbg(dev, timer, dev->net, "CDC: carrier %s\n",
event->wValue ? "on" : "off");
if (event->wValue &&
!test_bit(__LINK_STATE_NOCARRIER, &dev->net->state))
usbnet_link_change(dev, 0, 0);
usbnet_link_change(dev, !!event->wValue, 0);
break;
case USB_CDC_NOTIFY_SPEED_CHANGE:
netif_dbg(dev, timer, dev->net, "CDC: speed change (len %d)\n",
urb->actual_length);
if (urb->actual_length != (sizeof(*event) + 8))
set_bit(EVENT_STS_SPLIT, &dev->flags);
else
dumpspeed(dev, (__le32 *) &event[1]);
break;
default:
netdev_err(dev->net, "CDC: unexpected notification %02x!\n",
event->bNotificationType);
break;
}
}
int usbnet_cdc_bind(struct usbnet *dev, struct usb_interface *intf)
{
int status;
struct cdc_state *info = (void *) &dev->data;
BUILD_BUG_ON((sizeof(((struct usbnet *)0)->data)
< sizeof(struct cdc_state)));
status = usbnet_generic_cdc_bind(dev, intf);
if (status < 0)
return status;
status = usbnet_get_ethernet_addr(dev, info->ether->iMACAddress);
if (status < 0) {
usb_set_intfdata(info->data, NULL);
usb_driver_release_interface(driver_of(intf), info->data);
return status;
}
return 0;
}
static int usbnet_cdc_zte_bind(struct usbnet *dev, struct usb_interface *intf)
{
int status = usbnet_cdc_bind(dev, intf);
if (!status && (dev->net->dev_addr[0] & 0x02))
eth_hw_addr_random(dev->net);
return status;
}
static int usbnet_cdc_zte_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
if (skb->len < ETH_HLEN || !(skb->data[0] & 0x02))
return 1;
skb_reset_mac_header(skb);
ether_addr_copy(eth_hdr(skb)->h_dest, dev->net->dev_addr);
return 1;
}
