static int udp4_ufo_send_check(struct sk_buff *skb)
{
if (!pskb_may_pull(skb, sizeof(struct udphdr)))
return -EINVAL;
if (likely(!skb->encapsulation)) {
const struct iphdr *iph;
struct udphdr *uh;
iph = ip_hdr(skb);
uh = udp_hdr(skb);
uh->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr, skb->len,
IPPROTO_UDP, 0);
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct udphdr, check);
skb->ip_summed = CHECKSUM_PARTIAL;
}
return 0;
}
struct sk_buff *skb_udp_tunnel_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
u16 mac_offset = skb->mac_header;
int mac_len = skb->mac_len;
int tnl_hlen = skb_inner_mac_header(skb) - skb_transport_header(skb);
__be16 protocol = skb->protocol;
netdev_features_t enc_features;
int udp_offset, outer_hlen;
unsigned int oldlen;
bool need_csum;
oldlen = (u16)~skb->len;
if (unlikely(!pskb_may_pull(skb, tnl_hlen)))
goto out;
skb->encapsulation = 0;
__skb_pull(skb, tnl_hlen);
skb_reset_mac_header(skb);
skb_set_network_header(skb, skb_inner_network_offset(skb));
skb->mac_len = skb_inner_network_offset(skb);
skb->protocol = htons(ETH_P_TEB);
need_csum = !!(skb_shinfo(skb)->gso_type & SKB_GSO_UDP_TUNNEL_CSUM);
if (need_csum)
skb->encap_hdr_csum = 1;
enc_features = skb->dev->hw_enc_features & netif_skb_features(skb);
segs = skb_mac_gso_segment(skb, enc_features);
if (IS_ERR_OR_NULL(segs)) {
skb_gso_error_unwind(skb, protocol, tnl_hlen, mac_offset,
mac_len);
goto out;
}
outer_hlen = skb_tnl_header_len(skb);
udp_offset = outer_hlen - tnl_hlen;
skb = segs;
do {
struct udphdr *uh;
int len;
skb_reset_inner_headers(skb);
skb->encapsulation = 1;
skb->mac_len = mac_len;
skb_push(skb, outer_hlen);
skb_reset_mac_header(skb);
skb_set_network_header(skb, mac_len);
skb_set_transport_header(skb, udp_offset);
len = skb->len - udp_offset;
uh = udp_hdr(skb);
uh->len = htons(len);
if (need_csum) {
__be32 delta = htonl(oldlen + len);
uh->check = ~csum_fold((__force __wsum)
((__force u32)uh->check +
(__force u32)delta));
uh->check = gso_make_checksum(skb, ~uh->check);
if (uh->check == 0)
uh->check = CSUM_MANGLED_0;
}
skb->protocol = protocol;
} while ((skb = skb->next));
out:
return segs;
}
static struct sk_buff *udp4_ufo_fragment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
unsigned int mss;
int offset;
__wsum csum;
if (skb->encapsulation &&
(skb_shinfo(skb)->gso_type &
(SKB_GSO_UDP_TUNNEL|SKB_GSO_UDP_TUNNEL_CSUM))) {
segs = skb_udp_tunnel_segment(skb, features);
goto out;
}
mss = skb_shinfo(skb)->gso_size;
if (unlikely(skb->len <= mss))
goto out;
if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
int type = skb_shinfo(skb)->gso_type;
if (unlikely(type & ~(SKB_GSO_UDP | SKB_GSO_DODGY |
SKB_GSO_UDP_TUNNEL |
SKB_GSO_UDP_TUNNEL_CSUM |
SKB_GSO_IPIP |
SKB_GSO_GRE | SKB_GSO_GRE_CSUM |
SKB_GSO_MPLS) ||
!(type & (SKB_GSO_UDP))))
goto out;
skb_shinfo(skb)->gso_segs = DIV_ROUND_UP(skb->len, mss);
segs = NULL;
goto out;
}
offset = skb_checksum_start_offset(skb);
csum = skb_checksum(skb, offset, skb->len - offset, 0);
offset += skb->csum_offset;
*(__sum16 *)(skb->data + offset) = csum_fold(csum);
skb->ip_summed = CHECKSUM_NONE;
segs = skb_segment(skb, features);
out:
return segs;
}
int udp_add_offload(struct udp_offload *uo)
{
struct udp_offload_priv *new_offload = kzalloc(sizeof(*new_offload), GFP_ATOMIC);
if (!new_offload)
return -ENOMEM;
new_offload->offload = uo;
spin_lock(&udp_offload_lock);
new_offload->next = udp_offload_base;
rcu_assign_pointer(udp_offload_base, new_offload);
spin_unlock(&udp_offload_lock);
return 0;
}
static void udp_offload_free_routine(struct rcu_head *head)
{
struct udp_offload_priv *ou_priv = container_of(head, struct udp_offload_priv, rcu);
kfree(ou_priv);
}
void udp_del_offload(struct udp_offload *uo)
{
struct udp_offload_priv __rcu **head = &udp_offload_base;
struct udp_offload_priv *uo_priv;
spin_lock(&udp_offload_lock);
uo_priv = udp_deref_protected(*head);
for (; uo_priv != NULL;
uo_priv = udp_deref_protected(*head)) {
if (uo_priv->offload == uo) {
rcu_assign_pointer(*head,
udp_deref_protected(uo_priv->next));
goto unlock;
}
head = &uo_priv->next;
}
pr_warn("udp_del_offload: didn't find offload for port %d\n", ntohs(uo->port));
unlock:
spin_unlock(&udp_offload_lock);
if (uo_priv != NULL)
call_rcu(&uo_priv->rcu, udp_offload_free_routine);
}
static struct sk_buff **udp_gro_receive(struct sk_buff **head, struct sk_buff *skb)
{
struct udp_offload_priv *uo_priv;
struct sk_buff *p, **pp = NULL;
struct udphdr *uh, *uh2;
unsigned int hlen, off;
int flush = 1;
if (NAPI_GRO_CB(skb)->udp_mark ||
(!skb->encapsulation && skb->ip_summed != CHECKSUM_COMPLETE))
goto out;
NAPI_GRO_CB(skb)->udp_mark = 1;
off = skb_gro_offset(skb);
hlen = off + sizeof(*uh);
uh = skb_gro_header_fast(skb, off);
if (skb_gro_header_hard(skb, hlen)) {
uh = skb_gro_header_slow(skb, hlen, off);
if (unlikely(!uh))
goto out;
}
rcu_read_lock();
uo_priv = rcu_dereference(udp_offload_base);
for (; uo_priv != NULL; uo_priv = rcu_dereference(uo_priv->next)) {
if (uo_priv->offload->port == uh->dest &&
uo_priv->offload->callbacks.gro_receive)
goto unflush;
}
goto out_unlock;
unflush:
flush = 0;
for (p = *head; p; p = p->next) {
if (!NAPI_GRO_CB(p)->same_flow)
continue;
uh2 = (struct udphdr *)(p->data + off);
if ((*(u32 *)&uh->source != *(u32 *)&uh2->source)) {
NAPI_GRO_CB(p)->same_flow = 0;
continue;
}
}
skb_gro_pull(skb, sizeof(struct udphdr));
skb_gro_postpull_rcsum(skb, uh, sizeof(struct udphdr));
pp = uo_priv->offload->callbacks.gro_receive(head, skb);
out_unlock:
rcu_read_unlock();
out:
NAPI_GRO_CB(skb)->flush |= flush;
return pp;
}
static int udp_gro_complete(struct sk_buff *skb, int nhoff)
{
struct udp_offload_priv *uo_priv;
__be16 newlen = htons(skb->len - nhoff);
struct udphdr *uh = (struct udphdr *)(skb->data + nhoff);
int err = -ENOSYS;
uh->len = newlen;
rcu_read_lock();
uo_priv = rcu_dereference(udp_offload_base);
for (; uo_priv != NULL; uo_priv = rcu_dereference(uo_priv->next)) {
if (uo_priv->offload->port == uh->dest &&
uo_priv->offload->callbacks.gro_complete)
break;
}
if (uo_priv != NULL)
err = uo_priv->offload->callbacks.gro_complete(skb, nhoff + sizeof(struct udphdr));
rcu_read_unlock();
return err;
}
int __init udpv4_offload_init(void)
{
return inet_add_offload(&udpv4_offload, IPPROTO_UDP);
}
