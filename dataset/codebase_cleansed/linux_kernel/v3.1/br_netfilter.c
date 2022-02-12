static inline __be16 vlan_proto(const struct sk_buff *skb)
{
if (vlan_tx_tag_present(skb))
return skb->protocol;
else if (skb->protocol == htons(ETH_P_8021Q))
return vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
else
return 0;
}
static inline __be16 pppoe_proto(const struct sk_buff *skb)
{
return *((__be16 *)(skb_mac_header(skb) + ETH_HLEN +
sizeof(struct pppoe_hdr)));
}
static void fake_update_pmtu(struct dst_entry *dst, u32 mtu)
{
}
static u32 *fake_cow_metrics(struct dst_entry *dst, unsigned long old)
{
return NULL;
}
static struct neighbour *fake_neigh_lookup(const struct dst_entry *dst, const void *daddr)
{
return NULL;
}
void br_netfilter_rtable_init(struct net_bridge *br)
{
struct rtable *rt = &br->fake_rtable;
atomic_set(&rt->dst.__refcnt, 1);
rt->dst.dev = br->dev;
rt->dst.path = &rt->dst;
dst_init_metrics(&rt->dst, br_dst_default_metrics, true);
rt->dst.flags = DST_NOXFRM;
rt->dst.ops = &fake_dst_ops;
}
static inline struct rtable *bridge_parent_rtable(const struct net_device *dev)
{
struct net_bridge_port *port;
port = br_port_get_rcu(dev);
return port ? &port->br->fake_rtable : NULL;
}
static inline struct net_device *bridge_parent(const struct net_device *dev)
{
struct net_bridge_port *port;
port = br_port_get_rcu(dev);
return port ? port->br->dev : NULL;
}
static inline struct nf_bridge_info *nf_bridge_alloc(struct sk_buff *skb)
{
skb->nf_bridge = kzalloc(sizeof(struct nf_bridge_info), GFP_ATOMIC);
if (likely(skb->nf_bridge))
atomic_set(&(skb->nf_bridge->use), 1);
return skb->nf_bridge;
}
static inline struct nf_bridge_info *nf_bridge_unshare(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
if (atomic_read(&nf_bridge->use) > 1) {
struct nf_bridge_info *tmp = nf_bridge_alloc(skb);
if (tmp) {
memcpy(tmp, nf_bridge, sizeof(struct nf_bridge_info));
atomic_set(&tmp->use, 1);
}
nf_bridge_put(nf_bridge);
nf_bridge = tmp;
}
return nf_bridge;
}
static inline void nf_bridge_push_encap_header(struct sk_buff *skb)
{
unsigned int len = nf_bridge_encap_header_len(skb);
skb_push(skb, len);
skb->network_header -= len;
}
static inline void nf_bridge_pull_encap_header(struct sk_buff *skb)
{
unsigned int len = nf_bridge_encap_header_len(skb);
skb_pull(skb, len);
skb->network_header += len;
}
static inline void nf_bridge_pull_encap_header_rcsum(struct sk_buff *skb)
{
unsigned int len = nf_bridge_encap_header_len(skb);
skb_pull_rcsum(skb, len);
skb->network_header += len;
}
static inline void nf_bridge_save_header(struct sk_buff *skb)
{
int header_size = ETH_HLEN + nf_bridge_encap_header_len(skb);
skb_copy_from_linear_data_offset(skb, -header_size,
skb->nf_bridge->data, header_size);
}
static inline void nf_bridge_update_protocol(struct sk_buff *skb)
{
if (skb->nf_bridge->mask & BRNF_8021Q)
skb->protocol = htons(ETH_P_8021Q);
else if (skb->nf_bridge->mask & BRNF_PPPoE)
skb->protocol = htons(ETH_P_PPP_SES);
}
static int br_parse_ip_options(struct sk_buff *skb)
{
struct ip_options *opt;
const struct iphdr *iph;
struct net_device *dev = skb->dev;
u32 len;
iph = ip_hdr(skb);
opt = &(IPCB(skb)->opt);
if (iph->ihl < 5 || iph->version != 4)
goto inhdr_error;
if (!pskb_may_pull(skb, iph->ihl*4))
goto inhdr_error;
iph = ip_hdr(skb);
if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
goto inhdr_error;
len = ntohs(iph->tot_len);
if (skb->len < len) {
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INTRUNCATEDPKTS);
goto drop;
} else if (len < (iph->ihl*4))
goto inhdr_error;
if (pskb_trim_rcsum(skb, len)) {
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INDISCARDS);
goto drop;
}
memset(IPCB(skb), 0, sizeof(struct inet_skb_parm));
if (iph->ihl == 5)
return 0;
opt->optlen = iph->ihl*4 - sizeof(struct iphdr);
if (ip_options_compile(dev_net(dev), opt, skb))
goto inhdr_error;
if (unlikely(opt->srr)) {
struct in_device *in_dev = __in_dev_get_rcu(dev);
if (in_dev && !IN_DEV_SOURCE_ROUTE(in_dev))
goto drop;
if (ip_options_rcv_srr(skb))
goto drop;
}
return 0;
inhdr_error:
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INHDRERRORS);
drop:
return -1;
}
int nf_bridge_copy_header(struct sk_buff *skb)
{
int err;
unsigned int header_size;
nf_bridge_update_protocol(skb);
header_size = ETH_HLEN + nf_bridge_encap_header_len(skb);
err = skb_cow_head(skb, header_size);
if (err)
return err;
skb_copy_to_linear_data_offset(skb, -header_size,
skb->nf_bridge->data, header_size);
__skb_push(skb, nf_bridge_encap_header_len(skb));
return 0;
}
static int br_nf_pre_routing_finish_ipv6(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
struct rtable *rt;
if (nf_bridge->mask & BRNF_PKT_TYPE) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->mask ^= BRNF_PKT_TYPE;
}
nf_bridge->mask ^= BRNF_NF_BRIDGE_PREROUTING;
rt = bridge_parent_rtable(nf_bridge->physindev);
if (!rt) {
kfree_skb(skb);
return 0;
}
skb_dst_set_noref(skb, &rt->dst);
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_PRE_ROUTING, skb, skb->dev, NULL,
br_handle_frame_finish, 1);
return 0;
}
static int br_nf_pre_routing_finish_bridge(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
struct neighbour *neigh;
struct dst_entry *dst;
skb->dev = bridge_parent(skb->dev);
if (!skb->dev)
goto free_skb;
dst = skb_dst(skb);
neigh = dst_get_neighbour(dst);
if (neigh->hh.hh_len) {
neigh_hh_bridge(&neigh->hh, skb);
skb->dev = nf_bridge->physindev;
return br_handle_frame_finish(skb);
} else {
skb_copy_from_linear_data_offset(skb, -(ETH_HLEN-ETH_ALEN), skb->nf_bridge->data, ETH_HLEN-ETH_ALEN);
nf_bridge->mask |= BRNF_BRIDGED_DNAT;
return neigh->output(neigh, skb);
}
free_skb:
kfree_skb(skb);
return 0;
}
static int br_nf_pre_routing_finish(struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
struct iphdr *iph = ip_hdr(skb);
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
struct rtable *rt;
int err;
if (nf_bridge->mask & BRNF_PKT_TYPE) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->mask ^= BRNF_PKT_TYPE;
}
nf_bridge->mask ^= BRNF_NF_BRIDGE_PREROUTING;
if (dnat_took_place(skb)) {
if ((err = ip_route_input(skb, iph->daddr, iph->saddr, iph->tos, dev))) {
struct in_device *in_dev = __in_dev_get_rcu(dev);
if (err != -EHOSTUNREACH || !in_dev || IN_DEV_FORWARD(in_dev))
goto free_skb;
rt = ip_route_output(dev_net(dev), iph->daddr, 0,
RT_TOS(iph->tos), 0);
if (!IS_ERR(rt)) {
if (rt->dst.dev == dev) {
skb_dst_set(skb, &rt->dst);
goto bridged_dnat;
}
ip_rt_put(rt);
}
free_skb:
kfree_skb(skb);
return 0;
} else {
if (skb_dst(skb)->dev == dev) {
bridged_dnat:
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE,
NF_BR_PRE_ROUTING,
skb, skb->dev, NULL,
br_nf_pre_routing_finish_bridge,
1);
return 0;
}
memcpy(eth_hdr(skb)->h_dest, dev->dev_addr, ETH_ALEN);
skb->pkt_type = PACKET_HOST;
}
} else {
rt = bridge_parent_rtable(nf_bridge->physindev);
if (!rt) {
kfree_skb(skb);
return 0;
}
skb_dst_set_noref(skb, &rt->dst);
}
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_PRE_ROUTING, skb, skb->dev, NULL,
br_handle_frame_finish, 1);
return 0;
}
static struct net_device *setup_pre_routing(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->mask |= BRNF_PKT_TYPE;
}
nf_bridge->mask |= BRNF_NF_BRIDGE_PREROUTING;
nf_bridge->physindev = skb->dev;
skb->dev = bridge_parent(skb->dev);
if (skb->protocol == htons(ETH_P_8021Q))
nf_bridge->mask |= BRNF_8021Q;
else if (skb->protocol == htons(ETH_P_PPP_SES))
nf_bridge->mask |= BRNF_PPPoE;
return skb->dev;
}
static int check_hbh_len(struct sk_buff *skb)
{
unsigned char *raw = (u8 *)(ipv6_hdr(skb) + 1);
u32 pkt_len;
const unsigned char *nh = skb_network_header(skb);
int off = raw - nh;
int len = (raw[1] + 1) << 3;
if ((raw + len) - skb->data > skb_headlen(skb))
goto bad;
off += 2;
len -= 2;
while (len > 0) {
int optlen = nh[off + 1] + 2;
switch (nh[off]) {
case IPV6_TLV_PAD0:
optlen = 1;
break;
case IPV6_TLV_PADN:
break;
case IPV6_TLV_JUMBO:
if (nh[off + 1] != 4 || (off & 3) != 2)
goto bad;
pkt_len = ntohl(*(__be32 *) (nh + off + 2));
if (pkt_len <= IPV6_MAXPLEN ||
ipv6_hdr(skb)->payload_len)
goto bad;
if (pkt_len > skb->len - sizeof(struct ipv6hdr))
goto bad;
if (pskb_trim_rcsum(skb,
pkt_len + sizeof(struct ipv6hdr)))
goto bad;
nh = skb_network_header(skb);
break;
default:
if (optlen > len)
goto bad;
break;
}
off += optlen;
len -= optlen;
}
if (len == 0)
return 0;
bad:
return -1;
}
static unsigned int br_nf_pre_routing_ipv6(unsigned int hook,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
const struct ipv6hdr *hdr;
u32 pkt_len;
if (skb->len < sizeof(struct ipv6hdr))
return NF_DROP;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
return NF_DROP;
hdr = ipv6_hdr(skb);
if (hdr->version != 6)
return NF_DROP;
pkt_len = ntohs(hdr->payload_len);
if (pkt_len || hdr->nexthdr != NEXTHDR_HOP) {
if (pkt_len + sizeof(struct ipv6hdr) > skb->len)
return NF_DROP;
if (pskb_trim_rcsum(skb, pkt_len + sizeof(struct ipv6hdr)))
return NF_DROP;
}
if (hdr->nexthdr == NEXTHDR_HOP && check_hbh_len(skb))
return NF_DROP;
nf_bridge_put(skb->nf_bridge);
if (!nf_bridge_alloc(skb))
return NF_DROP;
if (!setup_pre_routing(skb))
return NF_DROP;
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(NFPROTO_IPV6, NF_INET_PRE_ROUTING, skb, skb->dev, NULL,
br_nf_pre_routing_finish_ipv6);
return NF_STOLEN;
}
static unsigned int br_nf_pre_routing(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct net_bridge_port *p;
struct net_bridge *br;
__u32 len = nf_bridge_encap_header_len(skb);
if (unlikely(!pskb_may_pull(skb, len)))
return NF_DROP;
p = br_port_get_rcu(in);
if (p == NULL)
return NF_DROP;
br = p->br;
if (skb->protocol == htons(ETH_P_IPV6) || IS_VLAN_IPV6(skb) ||
IS_PPPOE_IPV6(skb)) {
if (!brnf_call_ip6tables && !br->nf_call_ip6tables)
return NF_ACCEPT;
nf_bridge_pull_encap_header_rcsum(skb);
return br_nf_pre_routing_ipv6(hook, skb, in, out, okfn);
}
if (!brnf_call_iptables && !br->nf_call_iptables)
return NF_ACCEPT;
if (skb->protocol != htons(ETH_P_IP) && !IS_VLAN_IP(skb) &&
!IS_PPPOE_IP(skb))
return NF_ACCEPT;
nf_bridge_pull_encap_header_rcsum(skb);
if (br_parse_ip_options(skb))
return NF_DROP;
nf_bridge_put(skb->nf_bridge);
if (!nf_bridge_alloc(skb))
return NF_DROP;
if (!setup_pre_routing(skb))
return NF_DROP;
store_orig_dstaddr(skb);
skb->protocol = htons(ETH_P_IP);
NF_HOOK(NFPROTO_IPV4, NF_INET_PRE_ROUTING, skb, skb->dev, NULL,
br_nf_pre_routing_finish);
return NF_STOLEN;
}
static unsigned int br_nf_local_in(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct rtable *rt = skb_rtable(skb);
if (rt && rt == bridge_parent_rtable(in))
skb_dst_drop(skb);
return NF_ACCEPT;
}
static int br_nf_forward_finish(struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
struct net_device *in;
if (skb->protocol != htons(ETH_P_ARP) && !IS_VLAN_ARP(skb)) {
in = nf_bridge->physindev;
if (nf_bridge->mask & BRNF_PKT_TYPE) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->mask ^= BRNF_PKT_TYPE;
}
nf_bridge_update_protocol(skb);
} else {
in = *((struct net_device **)(skb->cb));
}
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_FORWARD, skb, in,
skb->dev, br_forward_finish, 1);
return 0;
}
static unsigned int br_nf_forward_ip(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_bridge_info *nf_bridge;
struct net_device *parent;
u_int8_t pf;
if (!skb->nf_bridge)
return NF_ACCEPT;
if (!nf_bridge_unshare(skb))
return NF_DROP;
parent = bridge_parent(out);
if (!parent)
return NF_DROP;
if (skb->protocol == htons(ETH_P_IP) || IS_VLAN_IP(skb) ||
IS_PPPOE_IP(skb))
pf = PF_INET;
else if (skb->protocol == htons(ETH_P_IPV6) || IS_VLAN_IPV6(skb) ||
IS_PPPOE_IPV6(skb))
pf = PF_INET6;
else
return NF_ACCEPT;
nf_bridge_pull_encap_header(skb);
nf_bridge = skb->nf_bridge;
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->mask |= BRNF_PKT_TYPE;
}
if (pf == PF_INET && br_parse_ip_options(skb))
return NF_DROP;
nf_bridge->mask |= BRNF_BRIDGED;
nf_bridge->physoutdev = skb->dev;
if (pf == PF_INET)
skb->protocol = htons(ETH_P_IP);
else
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(pf, NF_INET_FORWARD, skb, bridge_parent(in), parent,
br_nf_forward_finish);
return NF_STOLEN;
}
static unsigned int br_nf_forward_arp(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct net_bridge_port *p;
struct net_bridge *br;
struct net_device **d = (struct net_device **)(skb->cb);
p = br_port_get_rcu(out);
if (p == NULL)
return NF_ACCEPT;
br = p->br;
if (!brnf_call_arptables && !br->nf_call_arptables)
return NF_ACCEPT;
if (skb->protocol != htons(ETH_P_ARP)) {
if (!IS_VLAN_ARP(skb))
return NF_ACCEPT;
nf_bridge_pull_encap_header(skb);
}
if (arp_hdr(skb)->ar_pln != 4) {
if (IS_VLAN_ARP(skb))
nf_bridge_push_encap_header(skb);
return NF_ACCEPT;
}
*d = (struct net_device *)in;
NF_HOOK(NFPROTO_ARP, NF_ARP_FORWARD, skb, (struct net_device *)in,
(struct net_device *)out, br_nf_forward_finish);
return NF_STOLEN;
}
static int br_nf_dev_queue_xmit(struct sk_buff *skb)
{
int ret;
if (skb->nfct != NULL && skb->protocol == htons(ETH_P_IP) &&
skb->len + nf_bridge_mtu_reduction(skb) > skb->dev->mtu &&
!skb_is_gso(skb)) {
if (br_parse_ip_options(skb))
return NF_DROP;
ret = ip_fragment(skb, br_dev_queue_push_xmit);
} else
ret = br_dev_queue_push_xmit(skb);
return ret;
}
static int br_nf_dev_queue_xmit(struct sk_buff *skb)
{
return br_dev_queue_push_xmit(skb);
}
static unsigned int br_nf_post_routing(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_bridge_info *nf_bridge = skb->nf_bridge;
struct net_device *realoutdev = bridge_parent(skb->dev);
u_int8_t pf;
if (!nf_bridge || !(nf_bridge->mask & BRNF_BRIDGED))
return NF_ACCEPT;
if (!realoutdev)
return NF_DROP;
if (skb->protocol == htons(ETH_P_IP) || IS_VLAN_IP(skb) ||
IS_PPPOE_IP(skb))
pf = PF_INET;
else if (skb->protocol == htons(ETH_P_IPV6) || IS_VLAN_IPV6(skb) ||
IS_PPPOE_IPV6(skb))
pf = PF_INET6;
else
return NF_ACCEPT;
if (skb->pkt_type == PACKET_OTHERHOST) {
skb->pkt_type = PACKET_HOST;
nf_bridge->mask |= BRNF_PKT_TYPE;
}
nf_bridge_pull_encap_header(skb);
nf_bridge_save_header(skb);
if (pf == PF_INET)
skb->protocol = htons(ETH_P_IP);
else
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(pf, NF_INET_POST_ROUTING, skb, NULL, realoutdev,
br_nf_dev_queue_xmit);
return NF_STOLEN;
}
static unsigned int ip_sabotage_in(unsigned int hook, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
if (skb->nf_bridge &&
!(skb->nf_bridge->mask & BRNF_NF_BRIDGE_PREROUTING)) {
return NF_STOP;
}
return NF_ACCEPT;
}
static
int brnf_sysctl_call_tables(ctl_table * ctl, int write,
void __user * buffer, size_t * lenp, loff_t * ppos)
{
int ret;
ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
if (write && *(int *)(ctl->data))
*(int *)(ctl->data) = 1;
return ret;
}
int __init br_netfilter_init(void)
{
int ret;
ret = dst_entries_init(&fake_dst_ops);
if (ret < 0)
return ret;
ret = nf_register_hooks(br_nf_ops, ARRAY_SIZE(br_nf_ops));
if (ret < 0) {
dst_entries_destroy(&fake_dst_ops);
return ret;
}
#ifdef CONFIG_SYSCTL
brnf_sysctl_header = register_sysctl_paths(brnf_path, brnf_table);
if (brnf_sysctl_header == NULL) {
printk(KERN_WARNING
"br_netfilter: can't register to sysctl.\n");
nf_unregister_hooks(br_nf_ops, ARRAY_SIZE(br_nf_ops));
dst_entries_destroy(&fake_dst_ops);
return -ENOMEM;
}
#endif
printk(KERN_NOTICE "Bridge firewalling registered\n");
return 0;
}
void br_netfilter_fini(void)
{
nf_unregister_hooks(br_nf_ops, ARRAY_SIZE(br_nf_ops));
#ifdef CONFIG_SYSCTL
unregister_sysctl_table(brnf_sysctl_header);
#endif
dst_entries_destroy(&fake_dst_ops);
}
