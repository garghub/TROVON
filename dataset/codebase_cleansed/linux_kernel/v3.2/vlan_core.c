bool vlan_do_receive(struct sk_buff **skbp, bool last_handler)
{
struct sk_buff *skb = *skbp;
u16 vlan_id = skb->vlan_tci & VLAN_VID_MASK;
struct net_device *vlan_dev;
struct vlan_pcpu_stats *rx_stats;
vlan_dev = vlan_find_dev(skb->dev, vlan_id);
if (!vlan_dev) {
if (vlan_id && last_handler)
skb->pkt_type = PACKET_OTHERHOST;
return false;
}
skb = *skbp = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb))
return false;
skb->dev = vlan_dev;
if (skb->pkt_type == PACKET_OTHERHOST) {
if (!compare_ether_addr(eth_hdr(skb)->h_dest,
vlan_dev->dev_addr))
skb->pkt_type = PACKET_HOST;
}
if (!(vlan_dev_info(vlan_dev)->flags & VLAN_FLAG_REORDER_HDR)) {
unsigned int offset = skb->data - skb_mac_header(skb);
skb_push(skb, offset);
skb = *skbp = vlan_insert_tag(skb, skb->vlan_tci);
if (!skb)
return false;
skb_pull(skb, offset + VLAN_HLEN);
skb_reset_mac_len(skb);
}
skb->priority = vlan_get_ingress_priority(vlan_dev, skb->vlan_tci);
skb->vlan_tci = 0;
rx_stats = this_cpu_ptr(vlan_dev_info(vlan_dev)->vlan_pcpu_stats);
u64_stats_update_begin(&rx_stats->syncp);
rx_stats->rx_packets++;
rx_stats->rx_bytes += skb->len;
if (skb->pkt_type == PACKET_MULTICAST)
rx_stats->rx_multicast++;
u64_stats_update_end(&rx_stats->syncp);
return true;
}
struct net_device *__vlan_find_dev_deep(struct net_device *real_dev,
u16 vlan_id)
{
struct vlan_group *grp = rcu_dereference_rtnl(real_dev->vlgrp);
if (grp) {
return vlan_group_get_device(grp, vlan_id);
} else {
if (netif_is_bond_slave(real_dev))
return __vlan_find_dev_deep(real_dev->master, vlan_id);
}
return NULL;
}
struct net_device *vlan_dev_real_dev(const struct net_device *dev)
{
return vlan_dev_info(dev)->real_dev;
}
u16 vlan_dev_vlan_id(const struct net_device *dev)
{
return vlan_dev_info(dev)->vlan_id;
}
static struct sk_buff *vlan_reorder_header(struct sk_buff *skb)
{
if (skb_cow(skb, skb_headroom(skb)) < 0)
return NULL;
memmove(skb->data - ETH_HLEN, skb->data - VLAN_ETH_HLEN, 2 * ETH_ALEN);
skb->mac_header += VLAN_HLEN;
skb_reset_mac_len(skb);
return skb;
}
static void vlan_set_encap_proto(struct sk_buff *skb, struct vlan_hdr *vhdr)
{
__be16 proto;
unsigned char *rawp;
proto = vhdr->h_vlan_encapsulated_proto;
if (ntohs(proto) >= 1536) {
skb->protocol = proto;
return;
}
rawp = skb->data;
if (*(unsigned short *) rawp == 0xFFFF)
skb->protocol = htons(ETH_P_802_3);
else
skb->protocol = htons(ETH_P_802_2);
}
struct sk_buff *vlan_untag(struct sk_buff *skb)
{
struct vlan_hdr *vhdr;
u16 vlan_tci;
if (unlikely(vlan_tx_tag_present(skb))) {
return skb;
}
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb))
goto err_free;
if (unlikely(!pskb_may_pull(skb, VLAN_HLEN)))
goto err_free;
vhdr = (struct vlan_hdr *) skb->data;
vlan_tci = ntohs(vhdr->h_vlan_TCI);
__vlan_hwaccel_put_tag(skb, vlan_tci);
skb_pull_rcsum(skb, VLAN_HLEN);
vlan_set_encap_proto(skb, vhdr);
skb = vlan_reorder_header(skb);
if (unlikely(!skb))
goto err_free;
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
return skb;
err_free:
kfree_skb(skb);
return NULL;
}
