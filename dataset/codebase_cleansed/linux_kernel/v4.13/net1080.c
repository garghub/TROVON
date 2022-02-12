static int
nc_vendor_read(struct usbnet *dev, u8 req, u8 regnum, u16 *retval_ptr)
{
int status = usbnet_read_cmd(dev, req,
USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
0, regnum, retval_ptr,
sizeof *retval_ptr);
if (status > 0)
status = 0;
if (!status)
le16_to_cpus(retval_ptr);
return status;
}
static inline int
nc_register_read(struct usbnet *dev, u8 regnum, u16 *retval_ptr)
{
return nc_vendor_read(dev, REQUEST_REGISTER, regnum, retval_ptr);
}
static void
nc_vendor_write(struct usbnet *dev, u8 req, u8 regnum, u16 value)
{
usbnet_write_cmd(dev, req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, regnum, NULL, 0);
}
static inline void
nc_register_write(struct usbnet *dev, u8 regnum, u16 value)
{
nc_vendor_write(dev, REQUEST_REGISTER, regnum, value);
}
static inline void nc_dump_usbctl(struct usbnet *dev, u16 usbctl)
{
netif_dbg(dev, link, dev->net,
"net1080 %s-%s usbctl 0x%x:%s%s%s%s%s; this%s%s; other%s%s; r/o 0x%x\n",
dev->udev->bus->bus_name, dev->udev->devpath,
usbctl,
(usbctl & USBCTL_ENABLE_LANG) ? " lang" : "",
(usbctl & USBCTL_ENABLE_MFGR) ? " mfgr" : "",
(usbctl & USBCTL_ENABLE_PROD) ? " prod" : "",
(usbctl & USBCTL_ENABLE_SERIAL) ? " serial" : "",
(usbctl & USBCTL_ENABLE_DEFAULTS) ? " defaults" : "",
(usbctl & USBCTL_FLUSH_THIS) ? " FLUSH" : "",
(usbctl & USBCTL_DISCONN_THIS) ? " DIS" : "",
(usbctl & USBCTL_FLUSH_OTHER) ? " FLUSH" : "",
(usbctl & USBCTL_DISCONN_OTHER) ? " DIS" : "",
usbctl & ~USBCTL_WRITABLE_MASK);
}
static inline void nc_dump_status(struct usbnet *dev, u16 status)
{
netif_dbg(dev, link, dev->net,
"net1080 %s-%s status 0x%x: this (%c) PKT=%d%s%s%s; other PKT=%d%s%s%s; unspec 0x%x\n",
dev->udev->bus->bus_name, dev->udev->devpath,
status,
(status & STATUS_PORT_A) ? 'A' : 'B',
STATUS_PACKETS_THIS(status),
(status & STATUS_CONN_THIS) ? " CON" : "",
(status & STATUS_SUSPEND_THIS) ? " SUS" : "",
(status & STATUS_MAILBOX_THIS) ? " MBOX" : "",
STATUS_PACKETS_OTHER(status),
(status & STATUS_CONN_OTHER) ? " CON" : "",
(status & STATUS_SUSPEND_OTHER) ? " SUS" : "",
(status & STATUS_MAILBOX_OTHER) ? " MBOX" : "",
status & STATUS_UNSPEC_MASK);
}
static int net1080_reset(struct usbnet *dev)
{
u16 usbctl, status, ttl;
u16 vp;
int retval;
if ((retval = nc_register_read(dev, REG_STATUS, &vp)) < 0) {
netdev_dbg(dev->net, "can't read %s-%s status: %d\n",
dev->udev->bus->bus_name, dev->udev->devpath, retval);
goto done;
}
status = vp;
nc_dump_status(dev, status);
if ((retval = nc_register_read(dev, REG_USBCTL, &vp)) < 0) {
netdev_dbg(dev->net, "can't read USBCTL, %d\n", retval);
goto done;
}
usbctl = vp;
nc_dump_usbctl(dev, usbctl);
nc_register_write(dev, REG_USBCTL,
USBCTL_FLUSH_THIS | USBCTL_FLUSH_OTHER);
if ((retval = nc_register_read(dev, REG_TTL, &vp)) < 0) {
netdev_dbg(dev->net, "can't read TTL, %d\n", retval);
goto done;
}
ttl = vp;
nc_register_write(dev, REG_TTL,
MK_TTL(NC_READ_TTL_MS, TTL_OTHER(ttl)) );
netdev_dbg(dev->net, "assigned TTL, %d ms\n", NC_READ_TTL_MS);
netif_info(dev, link, dev->net, "port %c, peer %sconnected\n",
(status & STATUS_PORT_A) ? 'A' : 'B',
(status & STATUS_CONN_OTHER) ? "" : "dis");
retval = 0;
done:
return retval;
}
static int net1080_check_connect(struct usbnet *dev)
{
int retval;
u16 status;
u16 vp;
retval = nc_register_read(dev, REG_STATUS, &vp);
status = vp;
if (retval != 0) {
netdev_dbg(dev->net, "net1080_check_conn read - %d\n", retval);
return retval;
}
if ((status & STATUS_CONN_OTHER) != STATUS_CONN_OTHER)
return -ENOLINK;
return 0;
}
static void nc_ensure_sync(struct usbnet *dev)
{
if (++dev->frame_errors <= 5)
return;
if (usbnet_write_cmd_async(dev, REQUEST_REGISTER,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
USBCTL_FLUSH_THIS |
USBCTL_FLUSH_OTHER,
REG_USBCTL, NULL, 0))
return;
netif_dbg(dev, rx_err, dev->net,
"flush net1080; too many framing errors\n");
dev->frame_errors = 0;
}
static int net1080_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct nc_header *header;
struct nc_trailer *trailer;
u16 hdr_len, packet_len;
if (skb->len < dev->net->hard_header_len)
return 0;
if (!(skb->len & 0x01)) {
netdev_dbg(dev->net, "rx framesize %d range %d..%d mtu %d\n",
skb->len, dev->net->hard_header_len, dev->hard_mtu,
dev->net->mtu);
dev->net->stats.rx_frame_errors++;
nc_ensure_sync(dev);
return 0;
}
header = (struct nc_header *) skb->data;
hdr_len = le16_to_cpup(&header->hdr_len);
packet_len = le16_to_cpup(&header->packet_len);
if (FRAMED_SIZE(packet_len) > NC_MAX_PACKET) {
dev->net->stats.rx_frame_errors++;
netdev_dbg(dev->net, "packet too big, %d\n", packet_len);
nc_ensure_sync(dev);
return 0;
} else if (hdr_len < MIN_HEADER) {
dev->net->stats.rx_frame_errors++;
netdev_dbg(dev->net, "header too short, %d\n", hdr_len);
nc_ensure_sync(dev);
return 0;
} else if (hdr_len > MIN_HEADER) {
netdev_dbg(dev->net, "header OOB, %d bytes\n", hdr_len - MIN_HEADER);
nc_ensure_sync(dev);
}
skb_pull(skb, hdr_len);
trailer = (struct nc_trailer *)
(skb->data + skb->len - sizeof *trailer);
skb_trim(skb, skb->len - sizeof *trailer);
if ((packet_len & 0x01) == 0) {
if (skb->data [packet_len] != PAD_BYTE) {
dev->net->stats.rx_frame_errors++;
netdev_dbg(dev->net, "bad pad\n");
return 0;
}
skb_trim(skb, skb->len - 1);
}
if (skb->len != packet_len) {
dev->net->stats.rx_frame_errors++;
netdev_dbg(dev->net, "bad packet len %d (expected %d)\n",
skb->len, packet_len);
nc_ensure_sync(dev);
return 0;
}
if (header->packet_id != get_unaligned(&trailer->packet_id)) {
dev->net->stats.rx_fifo_errors++;
netdev_dbg(dev->net, "(2+ dropped) rx packet_id mismatch 0x%x 0x%x\n",
le16_to_cpu(header->packet_id),
le16_to_cpu(trailer->packet_id));
return 0;
}
#if 0
netdev_dbg(dev->net, "frame <rx h %d p %d id %d\n", header->hdr_len,
header->packet_len, header->packet_id);
#endif
dev->frame_errors = 0;
return 1;
}
static struct sk_buff *
net1080_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
struct sk_buff *skb2;
struct nc_header *header = NULL;
struct nc_trailer *trailer = NULL;
int padlen = sizeof (struct nc_trailer);
int len = skb->len;
if (!((len + padlen + sizeof (struct nc_header)) & 0x01))
padlen++;
if (!skb_cloned(skb)) {
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
if (padlen <= tailroom &&
sizeof(struct nc_header) <= headroom)
goto encapsulate;
if ((sizeof (struct nc_header) + padlen) <
(headroom + tailroom)) {
skb->data = memmove(skb->head
+ sizeof (struct nc_header),
skb->data, skb->len);
skb_set_tail_pointer(skb, len);
goto encapsulate;
}
}
skb2 = skb_copy_expand(skb,
sizeof (struct nc_header),
padlen,
flags);
dev_kfree_skb_any(skb);
if (!skb2)
return skb2;
skb = skb2;
encapsulate:
header = skb_push(skb, sizeof *header);
header->hdr_len = cpu_to_le16(sizeof (*header));
header->packet_len = cpu_to_le16(len);
header->packet_id = cpu_to_le16((u16)dev->xid++);
if (!((skb->len + sizeof *trailer) & 0x01))
skb_put_u8(skb, PAD_BYTE);
trailer = skb_put(skb, sizeof *trailer);
put_unaligned(header->packet_id, &trailer->packet_id);
#if 0
netdev_dbg(dev->net, "frame >tx h %d p %d id %d\n",
header->hdr_len, header->packet_len,
header->packet_id);
#endif
return skb;
}
static int net1080_bind(struct usbnet *dev, struct usb_interface *intf)
{
unsigned extra = sizeof (struct nc_header)
+ 1
+ sizeof (struct nc_trailer);
dev->net->hard_header_len += extra;
dev->rx_urb_size = dev->net->hard_header_len + dev->net->mtu;
dev->hard_mtu = NC_MAX_PACKET;
return usbnet_get_endpoints (dev, intf);
}
