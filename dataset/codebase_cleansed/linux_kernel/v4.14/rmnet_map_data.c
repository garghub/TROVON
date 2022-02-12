struct rmnet_map_header *rmnet_map_add_map_header(struct sk_buff *skb,
int hdrlen, int pad)
{
struct rmnet_map_header *map_header;
u32 padding, map_datalen;
u8 *padbytes;
if (skb_headroom(skb) < sizeof(struct rmnet_map_header))
return NULL;
map_datalen = skb->len - hdrlen;
map_header = (struct rmnet_map_header *)
skb_push(skb, sizeof(struct rmnet_map_header));
memset(map_header, 0, sizeof(struct rmnet_map_header));
if (pad == RMNET_MAP_NO_PAD_BYTES) {
map_header->pkt_len = htons(map_datalen);
return map_header;
}
padding = ALIGN(map_datalen, 4) - map_datalen;
if (padding == 0)
goto done;
if (skb_tailroom(skb) < padding)
return NULL;
padbytes = (u8 *)skb_put(skb, padding);
memset(padbytes, 0, padding);
done:
map_header->pkt_len = htons(map_datalen + padding);
map_header->pad_len = padding & 0x3F;
return map_header;
}
struct sk_buff *rmnet_map_deaggregate(struct sk_buff *skb)
{
struct rmnet_map_header *maph;
struct sk_buff *skbn;
u32 packet_len;
if (skb->len == 0)
return NULL;
maph = (struct rmnet_map_header *)skb->data;
packet_len = ntohs(maph->pkt_len) + sizeof(struct rmnet_map_header);
if (((int)skb->len - (int)packet_len) < 0)
return NULL;
if (ntohs(maph->pkt_len) == 0)
return NULL;
skbn = alloc_skb(packet_len + RMNET_MAP_DEAGGR_SPACING, GFP_ATOMIC);
if (!skbn)
return NULL;
skbn->dev = skb->dev;
skb_reserve(skbn, RMNET_MAP_DEAGGR_HEADROOM);
skb_put(skbn, packet_len);
memcpy(skbn->data, skb->data, packet_len);
skb_pull(skb, packet_len);
return skbn;
}
