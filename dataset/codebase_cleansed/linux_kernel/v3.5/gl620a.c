static int genelink_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct gl_header *header;
struct gl_packet *packet;
struct sk_buff *gl_skb;
u32 size;
u32 count;
header = (struct gl_header *) skb->data;
count = le32_to_cpu(header->packet_count);
if (count > GL_MAX_TRANSMIT_PACKETS) {
dbg("genelink: invalid received packet count %u", count);
return 0;
}
packet = &header->packets;
skb_pull(skb, 4);
while (count > 1) {
size = le32_to_cpu(packet->packet_length);
if (size > GL_MAX_PACKET_LEN) {
dbg("genelink: invalid rx length %d", size);
return 0;
}
gl_skb = alloc_skb(size, GFP_ATOMIC);
if (gl_skb) {
memcpy(skb_put(gl_skb, size),
packet->packet_data, size);
usbnet_skb_return(dev, gl_skb);
}
packet = (struct gl_packet *)&packet->packet_data[size];
count--;
skb_pull(skb, size + 4);
}
skb_pull(skb, 4);
if (skb->len > GL_MAX_PACKET_LEN) {
dbg("genelink: invalid rx length %d", skb->len);
return 0;
}
return 1;
}
static struct sk_buff *
genelink_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
int padlen;
int length = skb->len;
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
__le32 *packet_count;
__le32 *packet_len;
padlen = ((skb->len + (4 + 4*1)) % 64) ? 0 : 1;
if ((!skb_cloned(skb))
&& ((headroom + tailroom) >= (padlen + (4 + 4*1)))) {
if ((headroom < (4 + 4*1)) || (tailroom < padlen)) {
skb->data = memmove(skb->head + (4 + 4*1),
skb->data, skb->len);
skb_set_tail_pointer(skb, skb->len);
}
} else {
struct sk_buff *skb2;
skb2 = skb_copy_expand(skb, (4 + 4*1) , padlen, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return NULL;
}
packet_count = (__le32 *) skb_push(skb, (4 + 4*1));
packet_len = packet_count + 1;
*packet_count = cpu_to_le32(1);
*packet_len = cpu_to_le32(length);
if ((skb->len % dev->maxpacket) == 0)
skb_put(skb, 1);
return skb;
}
static int genelink_bind(struct usbnet *dev, struct usb_interface *intf)
{
dev->hard_mtu = GL_RCV_BUF_SIZE;
dev->net->hard_header_len += 4;
dev->in = usb_rcvbulkpipe(dev->udev, dev->driver_info->in);
dev->out = usb_sndbulkpipe(dev->udev, dev->driver_info->out);
return 0;
}
