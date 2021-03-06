static void eem_linkcmd_complete(struct urb *urb)
{
dev_kfree_skb(urb->context);
usb_free_urb(urb);
}
static void eem_linkcmd(struct usbnet *dev, struct sk_buff *skb)
{
struct urb *urb;
int status;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb)
goto fail;
usb_fill_bulk_urb(urb, dev->udev, dev->out,
skb->data, skb->len, eem_linkcmd_complete, skb);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
usb_free_urb(urb);
fail:
dev_kfree_skb(skb);
netdev_warn(dev->net, "link cmd failure\n");
return;
}
}
static int eem_bind(struct usbnet *dev, struct usb_interface *intf)
{
int status = 0;
status = usbnet_get_endpoints(dev, intf);
if (status < 0) {
usb_set_intfdata(intf, NULL);
usb_driver_release_interface(driver_of(intf), intf);
return status;
}
dev->net->hard_header_len += EEM_HEAD + ETH_FCS_LEN;
dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
return 0;
}
static struct sk_buff *eem_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
gfp_t flags)
{
struct sk_buff *skb2 = NULL;
u16 len = skb->len;
u32 crc = 0;
int padlen = 0;
if (!((len + EEM_HEAD + ETH_FCS_LEN) % dev->maxpacket))
padlen += 2;
if (!skb_cloned(skb)) {
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
if ((tailroom >= ETH_FCS_LEN + padlen) &&
(headroom >= EEM_HEAD))
goto done;
if ((headroom + tailroom)
> (EEM_HEAD + ETH_FCS_LEN + padlen)) {
skb->data = memmove(skb->head +
EEM_HEAD,
skb->data,
skb->len);
skb_set_tail_pointer(skb, len);
goto done;
}
}
skb2 = skb_copy_expand(skb, EEM_HEAD, ETH_FCS_LEN + padlen, flags);
if (!skb2)
return NULL;
dev_kfree_skb_any(skb);
skb = skb2;
done:
crc = crc32_le(~0, skb->data, skb->len);
crc = ~crc;
put_unaligned_le32(crc, skb_put(skb, 4));
len = skb->len;
put_unaligned_le16(BIT(14) | len, skb_push(skb, 2));
if (padlen)
put_unaligned_le16(0, skb_put(skb, 2));
return skb;
}
static int eem_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
do {
struct sk_buff *skb2 = NULL;
u16 header;
u16 len = 0;
if (skb->len < EEM_HEAD)
return 0;
header = get_unaligned_le16(skb->data);
skb_pull(skb, EEM_HEAD);
if (header & BIT(15)) {
u16 bmEEMCmd;
if (header & BIT(14)) {
netdev_dbg(dev->net, "reserved command %04x\n",
header);
continue;
}
bmEEMCmd = (header >> 11) & 0x7;
switch (bmEEMCmd) {
case 0:
len = header & 0x7FF;
if (skb->len < len)
return 0;
skb2 = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb2))
goto next;
skb_trim(skb2, len);
put_unaligned_le16(BIT(15) | (1 << 11) | len,
skb_push(skb2, 2));
eem_linkcmd(dev, skb2);
break;
case 2:
case 3:
case 4:
continue;
case 1:
case 5:
default:
netdev_warn(dev->net,
"unexpected link command %d\n",
bmEEMCmd);
continue;
}
} else {
u32 crc, crc2;
int is_last;
if (header == 0)
continue;
len = header & 0x3FFF;
if (skb->len < len)
return 0;
if (len < (ETH_HLEN + ETH_FCS_LEN))
goto next;
is_last = (len == skb->len);
if (is_last)
skb2 = skb;
else {
skb2 = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb2))
return 0;
}
if (header & BIT(14)) {
crc = get_unaligned_le32(skb2->data
+ len - ETH_FCS_LEN);
crc2 = ~crc32_le(~0, skb2->data, skb2->len
- ETH_FCS_LEN);
} else {
crc = get_unaligned_be32(skb2->data
+ len - ETH_FCS_LEN);
crc2 = 0xdeadbeef;
}
skb_trim(skb2, len - ETH_FCS_LEN);
if (is_last)
return crc == crc2;
if (unlikely(crc != crc2)) {
dev->net->stats.rx_errors++;
dev_kfree_skb_any(skb2);
} else
usbnet_skb_return(dev, skb2);
}
next:
skb_pull(skb, len);
} while (skb->len);
return 1;
}
