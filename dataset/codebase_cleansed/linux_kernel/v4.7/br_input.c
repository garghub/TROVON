static int
br_netif_receive_skb(struct net *net, struct sock *sk, struct sk_buff *skb)
{
return netif_receive_skb(skb);
}
static int br_pass_frame_up(struct sk_buff *skb)
{
struct net_device *indev, *brdev = BR_INPUT_SKB_CB(skb)->brdev;
struct net_bridge *br = netdev_priv(brdev);
struct net_bridge_vlan_group *vg;
struct pcpu_sw_netstats *brstats = this_cpu_ptr(br->stats);
u64_stats_update_begin(&brstats->syncp);
brstats->rx_packets++;
brstats->rx_bytes += skb->len;
u64_stats_update_end(&brstats->syncp);
vg = br_vlan_group_rcu(br);
if (!(brdev->flags & IFF_PROMISC) &&
!br_allowed_egress(vg, skb)) {
kfree_skb(skb);
return NET_RX_DROP;
}
indev = skb->dev;
skb->dev = brdev;
skb = br_handle_vlan(br, vg, skb);
if (!skb)
return NET_RX_DROP;
return NF_HOOK(NFPROTO_BRIDGE, NF_BR_LOCAL_IN,
dev_net(indev), NULL, skb, indev, NULL,
br_netif_receive_skb);
}
static void br_do_proxy_arp(struct sk_buff *skb, struct net_bridge *br,
u16 vid, struct net_bridge_port *p)
{
struct net_device *dev = br->dev;
struct neighbour *n;
struct arphdr *parp;
u8 *arpptr, *sha;
__be32 sip, tip;
BR_INPUT_SKB_CB(skb)->proxyarp_replied = false;
if (dev->flags & IFF_NOARP)
return;
if (!pskb_may_pull(skb, arp_hdr_len(dev))) {
dev->stats.tx_dropped++;
return;
}
parp = arp_hdr(skb);
if (parp->ar_pro != htons(ETH_P_IP) ||
parp->ar_op != htons(ARPOP_REQUEST) ||
parp->ar_hln != dev->addr_len ||
parp->ar_pln != 4)
return;
arpptr = (u8 *)parp + sizeof(struct arphdr);
sha = arpptr;
arpptr += dev->addr_len;
memcpy(&sip, arpptr, sizeof(sip));
arpptr += sizeof(sip);
arpptr += dev->addr_len;
memcpy(&tip, arpptr, sizeof(tip));
if (ipv4_is_loopback(tip) ||
ipv4_is_multicast(tip))
return;
n = neigh_lookup(&arp_tbl, &tip, dev);
if (n) {
struct net_bridge_fdb_entry *f;
if (!(n->nud_state & NUD_VALID)) {
neigh_release(n);
return;
}
f = __br_fdb_get(br, n->ha, vid);
if (f && ((p->flags & BR_PROXYARP) ||
(f->dst && (f->dst->flags & BR_PROXYARP_WIFI)))) {
arp_send(ARPOP_REPLY, ETH_P_ARP, sip, skb->dev, tip,
sha, n->ha, sha);
BR_INPUT_SKB_CB(skb)->proxyarp_replied = true;
}
neigh_release(n);
}
}
int br_handle_frame_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
const unsigned char *dest = eth_hdr(skb)->h_dest;
struct net_bridge_port *p = br_port_get_rcu(skb->dev);
struct net_bridge *br;
struct net_bridge_fdb_entry *dst;
struct net_bridge_mdb_entry *mdst;
struct sk_buff *skb2;
bool unicast = true;
u16 vid = 0;
if (!p || p->state == BR_STATE_DISABLED)
goto drop;
if (!br_allowed_ingress(p->br, nbp_vlan_group_rcu(p), skb, &vid))
goto out;
br = p->br;
if (p->flags & BR_LEARNING)
br_fdb_update(br, p, eth_hdr(skb)->h_source, vid, false);
if (!is_broadcast_ether_addr(dest) && is_multicast_ether_addr(dest) &&
br_multicast_rcv(br, p, skb, vid))
goto drop;
if (p->state == BR_STATE_LEARNING)
goto drop;
BR_INPUT_SKB_CB(skb)->brdev = br->dev;
skb2 = NULL;
if (br->dev->flags & IFF_PROMISC)
skb2 = skb;
dst = NULL;
if (IS_ENABLED(CONFIG_INET) && skb->protocol == htons(ETH_P_ARP))
br_do_proxy_arp(skb, br, vid, p);
if (is_broadcast_ether_addr(dest)) {
skb2 = skb;
unicast = false;
} else if (is_multicast_ether_addr(dest)) {
mdst = br_mdb_get(br, skb, vid);
if ((mdst || BR_INPUT_SKB_CB_MROUTERS_ONLY(skb)) &&
br_multicast_querier_exists(br, eth_hdr(skb))) {
if ((mdst && mdst->mglist) ||
br_multicast_is_router(br))
skb2 = skb;
br_multicast_forward(mdst, skb, skb2);
skb = NULL;
if (!skb2)
goto out;
} else
skb2 = skb;
unicast = false;
br->dev->stats.multicast++;
} else if ((dst = __br_fdb_get(br, dest, vid)) &&
dst->is_local) {
skb2 = skb;
skb = NULL;
}
if (skb) {
if (dst) {
dst->used = jiffies;
br_forward(dst->dst, skb, skb2);
} else
br_flood_forward(br, skb, skb2, unicast);
}
if (skb2)
return br_pass_frame_up(skb2);
out:
return 0;
drop:
kfree_skb(skb);
goto out;
}
static void __br_handle_local_finish(struct sk_buff *skb)
{
struct net_bridge_port *p = br_port_get_rcu(skb->dev);
u16 vid = 0;
if (p->flags & BR_LEARNING && br_should_learn(p, skb, &vid))
br_fdb_update(p->br, p, eth_hdr(skb)->h_source, vid, false);
}
static int br_handle_local_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct net_bridge_port *p = br_port_get_rcu(skb->dev);
__br_handle_local_finish(skb);
BR_INPUT_SKB_CB(skb)->brdev = p->br->dev;
br_pass_frame_up(skb);
return 0;
}
rx_handler_result_t br_handle_frame(struct sk_buff **pskb)
{
struct net_bridge_port *p;
struct sk_buff *skb = *pskb;
const unsigned char *dest = eth_hdr(skb)->h_dest;
br_should_route_hook_t *rhook;
if (unlikely(skb->pkt_type == PACKET_LOOPBACK))
return RX_HANDLER_PASS;
if (!is_valid_ether_addr(eth_hdr(skb)->h_source))
goto drop;
skb = skb_share_check(skb, GFP_ATOMIC);
if (!skb)
return RX_HANDLER_CONSUMED;
p = br_port_get_rcu(skb->dev);
if (unlikely(is_link_local_ether_addr(dest))) {
u16 fwd_mask = p->br->group_fwd_mask_required;
switch (dest[5]) {
case 0x00:
if (p->br->stp_enabled == BR_NO_STP ||
fwd_mask & (1u << dest[5]))
goto forward;
*pskb = skb;
__br_handle_local_finish(skb);
return RX_HANDLER_PASS;
case 0x01:
goto drop;
default:
fwd_mask |= p->br->group_fwd_mask;
if (fwd_mask & (1u << dest[5]))
goto forward;
}
NF_HOOK(NFPROTO_BRIDGE, NF_BR_LOCAL_IN, dev_net(skb->dev),
NULL, skb, skb->dev, NULL, br_handle_local_finish);
return RX_HANDLER_CONSUMED;
}
forward:
switch (p->state) {
case BR_STATE_FORWARDING:
rhook = rcu_dereference(br_should_route_hook);
if (rhook) {
if ((*rhook)(skb)) {
*pskb = skb;
return RX_HANDLER_PASS;
}
dest = eth_hdr(skb)->h_dest;
}
case BR_STATE_LEARNING:
if (ether_addr_equal(p->br->dev->dev_addr, dest))
skb->pkt_type = PACKET_HOST;
NF_HOOK(NFPROTO_BRIDGE, NF_BR_PRE_ROUTING,
dev_net(skb->dev), NULL, skb, skb->dev, NULL,
br_handle_frame_finish);
break;
default:
drop:
kfree_skb(skb);
}
return RX_HANDLER_CONSUMED;
}
