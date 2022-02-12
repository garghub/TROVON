static struct sk_buff *
zaurus_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
int padlen;
struct sk_buff *skb2;
padlen = 2;
if (!skb_cloned(skb)) {
int tailroom = skb_tailroom(skb);
if ((padlen + 4) <= tailroom)
goto done;
}
skb2 = skb_copy_expand(skb, 0, 4 + padlen, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (skb) {
u32 fcs;
done:
fcs = crc32_le(~0, skb->data, skb->len);
fcs = ~fcs;
*skb_put (skb, 1) = fcs & 0xff;
*skb_put (skb, 1) = (fcs>> 8) & 0xff;
*skb_put (skb, 1) = (fcs>>16) & 0xff;
*skb_put (skb, 1) = (fcs>>24) & 0xff;
}
return skb;
}
static int zaurus_bind(struct usbnet *dev, struct usb_interface *intf)
{
dev->net->hard_header_len += 6;
dev->rx_urb_size = dev->net->hard_header_len + dev->net->mtu;
return usbnet_generic_cdc_bind(dev, intf);
}
static int always_connected (struct usbnet *dev)
{
return 0;
}
static int blan_mdlm_bind(struct usbnet *dev, struct usb_interface *intf)
{
u8 *buf = intf->cur_altsetting->extra;
int len = intf->cur_altsetting->extralen;
struct usb_cdc_mdlm_desc *desc = NULL;
struct usb_cdc_mdlm_detail_desc *detail = NULL;
while (len > 3) {
if (buf [1] != USB_DT_CS_INTERFACE)
goto next_desc;
switch (buf [2]) {
case USB_CDC_MDLM_TYPE:
if (desc) {
dev_dbg(&intf->dev, "extra MDLM\n");
goto bad_desc;
}
desc = (void *) buf;
if (desc->bLength != sizeof *desc) {
dev_dbg(&intf->dev, "MDLM len %u\n",
desc->bLength);
goto bad_desc;
}
if (memcmp(&desc->bGUID, blan_guid, 16) &&
memcmp(&desc->bGUID, safe_guid, 16)) {
dev_dbg(&intf->dev, "MDLM guid\n");
goto bad_desc;
}
break;
case USB_CDC_MDLM_DETAIL_TYPE:
if (detail) {
dev_dbg(&intf->dev, "extra MDLM detail\n");
goto bad_desc;
}
detail = (void *) buf;
switch (detail->bGuidDescriptorType) {
case 0:
if (detail->bLength != (sizeof *detail + 2))
goto bad_detail;
break;
case 1:
if (detail->bLength != (sizeof *detail + 3))
goto bad_detail;
break;
default:
goto bad_detail;
}
if ((detail->bDetailData[1] & ~0x02) != 0x01) {
bad_detail:
dev_dbg(&intf->dev,
"bad MDLM detail, %d %d %d\n",
detail->bLength,
detail->bDetailData[0],
detail->bDetailData[2]);
goto bad_desc;
}
dev->net->hard_header_len += 6;
dev->rx_urb_size = dev->net->hard_header_len
+ dev->net->mtu;
break;
}
next_desc:
len -= buf [0];
buf += buf [0];
}
if (!desc || !detail) {
dev_dbg(&intf->dev, "missing cdc mdlm %s%sdescriptor\n",
desc ? "" : "func ",
detail ? "" : "detail ");
goto bad_desc;
}
return usbnet_get_endpoints(dev, intf);
bad_desc:
dev_info(&dev->udev->dev, "unsupported MDLM descriptors\n");
return -ENODEV;
}
static int __init zaurus_init(void)
{
return usb_register(&zaurus_driver);
}
static void __exit zaurus_exit(void)
{
usb_deregister(&zaurus_driver);
}
