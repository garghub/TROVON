static int vl600_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
struct vl600_state *s = kzalloc(sizeof(struct vl600_state), GFP_KERNEL);
if (!s)
return -ENOMEM;
ret = usbnet_cdc_bind(dev, intf);
if (ret) {
kfree(s);
return ret;
}
dev->driver_priv = s;
dev->net->flags |= IFF_NOARP;
dev->net->flags |= IFF_MULTICAST;
return ret;
}
static void vl600_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct vl600_state *s = dev->driver_priv;
if (s->current_rx_buf)
dev_kfree_skb(s->current_rx_buf);
kfree(s);
return usbnet_cdc_unbind(dev, intf);
}
static int vl600_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct vl600_frame_hdr *frame;
struct vl600_pkt_hdr *packet;
struct ethhdr *ethhdr;
int packet_len, count;
struct sk_buff *buf = skb;
struct sk_buff *clone;
struct vl600_state *s = dev->driver_priv;
if (s->current_rx_buf) {
frame = (struct vl600_frame_hdr *) s->current_rx_buf->data;
if (skb->len + s->current_rx_buf->len >
le32_to_cpup(&frame->len)) {
netif_err(dev, ifup, dev->net, "Fragment too long\n");
dev->net->stats.rx_length_errors++;
goto error;
}
buf = s->current_rx_buf;
memcpy(skb_put(buf, skb->len), skb->data, skb->len);
} else if (skb->len < 4) {
netif_err(dev, ifup, dev->net, "Frame too short\n");
dev->net->stats.rx_length_errors++;
goto error;
}
frame = (struct vl600_frame_hdr *) buf->data;
if (ntohl(frame->magic) != 0x53544448 &&
ntohl(frame->magic) != 0x44544d48)
goto error;
if (buf->len < sizeof(*frame) ||
buf->len != le32_to_cpup(&frame->len)) {
if (s->current_rx_buf)
return 0;
s->current_rx_buf = skb_copy_expand(skb, 0,
le32_to_cpup(&frame->len), GFP_ATOMIC);
if (!s->current_rx_buf) {
netif_err(dev, ifup, dev->net, "Reserving %i bytes "
"for packet assembly failed.\n",
le32_to_cpup(&frame->len));
dev->net->stats.rx_errors++;
}
return 0;
}
count = le32_to_cpup(&frame->pkt_cnt);
skb_pull(buf, sizeof(*frame));
while (count--) {
if (buf->len < sizeof(*packet)) {
netif_err(dev, ifup, dev->net, "Packet too short\n");
goto error;
}
packet = (struct vl600_pkt_hdr *) buf->data;
packet_len = sizeof(*packet) + le32_to_cpup(&packet->len);
if (packet_len > buf->len) {
netif_err(dev, ifup, dev->net,
"Bad packet length stored in header\n");
goto error;
}
ethhdr = (struct ethhdr *) skb->data;
if (be16_to_cpup(&ethhdr->h_proto) == ETH_P_ARP &&
buf->len > 0x26) {
memcpy(ethhdr->h_source,
&buf->data[sizeof(*ethhdr) + 0x8],
ETH_ALEN);
memcpy(ethhdr->h_dest,
&buf->data[sizeof(*ethhdr) + 0x12],
ETH_ALEN);
} else {
memset(ethhdr->h_source, 0, ETH_ALEN);
memcpy(ethhdr->h_dest, dev->net->dev_addr, ETH_ALEN);
if ((buf->data[sizeof(*ethhdr)] & 0xf0) == 0x60)
ethhdr->h_proto = htons(ETH_P_IPV6);
}
if (count) {
clone = skb_clone(buf, GFP_ATOMIC);
if (!clone)
goto error;
skb_trim(clone, packet_len);
usbnet_skb_return(dev, clone);
skb_pull(buf, (packet_len + 3) & ~3);
} else {
skb_trim(buf, packet_len);
if (s->current_rx_buf) {
usbnet_skb_return(dev, buf);
s->current_rx_buf = NULL;
return 0;
}
return 1;
}
}
error:
if (s->current_rx_buf) {
dev_kfree_skb_any(s->current_rx_buf);
s->current_rx_buf = NULL;
}
dev->net->stats.rx_errors++;
return 0;
}
static struct sk_buff *vl600_tx_fixup(struct usbnet *dev,
struct sk_buff *skb, gfp_t flags)
{
struct sk_buff *ret;
struct vl600_frame_hdr *frame;
struct vl600_pkt_hdr *packet;
static uint32_t serial = 1;
int orig_len = skb->len - sizeof(struct ethhdr);
int full_len = (skb->len + sizeof(struct vl600_frame_hdr) + 3) & ~3;
frame = (struct vl600_frame_hdr *) skb->data;
if (skb->len > sizeof(*frame) && skb->len == le32_to_cpup(&frame->len))
return skb;
if (skb->len < sizeof(struct ethhdr))
return NULL;
if (!skb_cloned(skb)) {
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
if (tailroom >= full_len - skb->len - sizeof(*frame) &&
headroom >= sizeof(*frame))
goto encapsulate;
if (headroom + tailroom + skb->len >= full_len) {
skb->data = memmove(skb->head + sizeof(*frame),
skb->data, skb->len);
skb_set_tail_pointer(skb, skb->len);
goto encapsulate;
}
}
ret = skb_copy_expand(skb, sizeof(struct vl600_frame_hdr), full_len -
skb->len - sizeof(struct vl600_frame_hdr), flags);
dev_kfree_skb_any(skb);
if (!ret)
return ret;
skb = ret;
encapsulate:
packet = (struct vl600_pkt_hdr *) skb->data;
packet->h_proto = htons(ETH_P_IP);
memset(&packet->dummy, 0, sizeof(packet->dummy));
packet->len = cpu_to_le32(orig_len);
frame = (struct vl600_frame_hdr *) skb_push(skb, sizeof(*frame));
memset(frame, 0, sizeof(*frame));
frame->len = cpu_to_le32(full_len);
frame->serial = cpu_to_le32(serial++);
frame->pkt_cnt = cpu_to_le32(1);
if (skb->len < full_len)
skb_put(skb, full_len - skb->len);
return skb;
}
