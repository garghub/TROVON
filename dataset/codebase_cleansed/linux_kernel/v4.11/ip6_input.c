int ip6_rcv_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
skb = l3mdev_ip6_rcv(skb);
if (!skb)
return NET_RX_SUCCESS;
if (net->ipv4.sysctl_ip_early_demux && !skb_dst(skb) && skb->sk == NULL) {
const struct inet6_protocol *ipprot;
ipprot = rcu_dereference(inet6_protos[ipv6_hdr(skb)->nexthdr]);
if (ipprot && ipprot->early_demux)
ipprot->early_demux(skb);
}
if (!skb_valid_dst(skb))
ip6_route_input(skb);
return dst_input(skb);
}
int ipv6_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
{
const struct ipv6hdr *hdr;
u32 pkt_len;
struct inet6_dev *idev;
struct net *net = dev_net(skb->dev);
if (skb->pkt_type == PACKET_OTHERHOST) {
kfree_skb(skb);
return NET_RX_DROP;
}
rcu_read_lock();
idev = __in6_dev_get(skb->dev);
__IP6_UPD_PO_STATS(net, idev, IPSTATS_MIB_IN, skb->len);
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL ||
!idev || unlikely(idev->cnf.disable_ipv6)) {
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INDISCARDS);
goto drop;
}
memset(IP6CB(skb), 0, sizeof(struct inet6_skb_parm));
IP6CB(skb)->iif = skb_valid_dst(skb) ? ip6_dst_idev(skb_dst(skb))->dev->ifindex : dev->ifindex;
if (unlikely(!pskb_may_pull(skb, sizeof(*hdr))))
goto err;
hdr = ipv6_hdr(skb);
if (hdr->version != 6)
goto err;
__IP6_ADD_STATS(net, idev,
IPSTATS_MIB_NOECTPKTS +
(ipv6_get_dsfield(hdr) & INET_ECN_MASK),
max_t(unsigned short, 1, skb_shinfo(skb)->gso_segs));
if ((ipv6_addr_loopback(&hdr->saddr) ||
ipv6_addr_loopback(&hdr->daddr)) &&
!(dev->flags & IFF_LOOPBACK))
goto err;
if (!(skb->pkt_type == PACKET_LOOPBACK ||
dev->flags & IFF_LOOPBACK) &&
ipv6_addr_is_multicast(&hdr->daddr) &&
IPV6_ADDR_MC_SCOPE(&hdr->daddr) == 1)
goto err;
if (!ipv6_addr_is_multicast(&hdr->daddr) &&
(skb->pkt_type == PACKET_BROADCAST ||
skb->pkt_type == PACKET_MULTICAST) &&
idev->cnf.drop_unicast_in_l2_multicast)
goto err;
if (ipv6_addr_is_multicast(&hdr->daddr) &&
IPV6_ADDR_MC_SCOPE(&hdr->daddr) == 0)
goto err;
if (ipv6_addr_is_multicast(&hdr->saddr))
goto err;
skb->transport_header = skb->network_header + sizeof(*hdr);
IP6CB(skb)->nhoff = offsetof(struct ipv6hdr, nexthdr);
pkt_len = ntohs(hdr->payload_len);
if (pkt_len || hdr->nexthdr != NEXTHDR_HOP) {
if (pkt_len + sizeof(struct ipv6hdr) > skb->len) {
__IP6_INC_STATS(net,
idev, IPSTATS_MIB_INTRUNCATEDPKTS);
goto drop;
}
if (pskb_trim_rcsum(skb, pkt_len + sizeof(struct ipv6hdr))) {
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INHDRERRORS);
goto drop;
}
hdr = ipv6_hdr(skb);
}
if (hdr->nexthdr == NEXTHDR_HOP) {
if (ipv6_parse_hopopts(skb) < 0) {
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INHDRERRORS);
rcu_read_unlock();
return NET_RX_DROP;
}
}
rcu_read_unlock();
skb_orphan(skb);
return NF_HOOK(NFPROTO_IPV6, NF_INET_PRE_ROUTING,
net, NULL, skb, dev, NULL,
ip6_rcv_finish);
err:
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INHDRERRORS);
drop:
rcu_read_unlock();
kfree_skb(skb);
return NET_RX_DROP;
}
static int ip6_input_finish(struct net *net, struct sock *sk, struct sk_buff *skb)
{
const struct inet6_protocol *ipprot;
struct inet6_dev *idev;
unsigned int nhoff;
int nexthdr;
bool raw;
bool have_final = false;
rcu_read_lock();
resubmit:
idev = ip6_dst_idev(skb_dst(skb));
if (!pskb_pull(skb, skb_transport_offset(skb)))
goto discard;
nhoff = IP6CB(skb)->nhoff;
nexthdr = skb_network_header(skb)[nhoff];
resubmit_final:
raw = raw6_local_deliver(skb, nexthdr);
ipprot = rcu_dereference(inet6_protos[nexthdr]);
if (ipprot) {
int ret;
if (have_final) {
if (!(ipprot->flags & INET6_PROTO_FINAL)) {
goto discard;
}
} else if (ipprot->flags & INET6_PROTO_FINAL) {
const struct ipv6hdr *hdr;
have_final = true;
nf_reset(skb);
skb_postpull_rcsum(skb, skb_network_header(skb),
skb_network_header_len(skb));
hdr = ipv6_hdr(skb);
if (ipv6_addr_is_multicast(&hdr->daddr) &&
!ipv6_chk_mcast_addr(skb->dev, &hdr->daddr,
&hdr->saddr) &&
!ipv6_is_mld(skb, nexthdr, skb_network_header_len(skb)))
goto discard;
}
if (!(ipprot->flags & INET6_PROTO_NOPOLICY) &&
!xfrm6_policy_check(NULL, XFRM_POLICY_IN, skb))
goto discard;
ret = ipprot->handler(skb);
if (ret > 0) {
if (ipprot->flags & INET6_PROTO_FINAL) {
nexthdr = ret;
goto resubmit_final;
} else {
goto resubmit;
}
} else if (ret == 0) {
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INDELIVERS);
}
} else {
if (!raw) {
if (xfrm6_policy_check(NULL, XFRM_POLICY_IN, skb)) {
__IP6_INC_STATS(net, idev,
IPSTATS_MIB_INUNKNOWNPROTOS);
icmpv6_send(skb, ICMPV6_PARAMPROB,
ICMPV6_UNK_NEXTHDR, nhoff);
}
kfree_skb(skb);
} else {
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INDELIVERS);
consume_skb(skb);
}
}
rcu_read_unlock();
return 0;
discard:
__IP6_INC_STATS(net, idev, IPSTATS_MIB_INDISCARDS);
rcu_read_unlock();
kfree_skb(skb);
return 0;
}
int ip6_input(struct sk_buff *skb)
{
return NF_HOOK(NFPROTO_IPV6, NF_INET_LOCAL_IN,
dev_net(skb->dev), NULL, skb, skb->dev, NULL,
ip6_input_finish);
}
int ip6_mc_input(struct sk_buff *skb)
{
const struct ipv6hdr *hdr;
bool deliver;
__IP6_UPD_PO_STATS(dev_net(skb_dst(skb)->dev),
ip6_dst_idev(skb_dst(skb)), IPSTATS_MIB_INMCAST,
skb->len);
hdr = ipv6_hdr(skb);
deliver = ipv6_chk_mcast_addr(skb->dev, &hdr->daddr, NULL);
#ifdef CONFIG_IPV6_MROUTE
if (dev_net(skb->dev)->ipv6.devconf_all->mc_forwarding &&
!(ipv6_addr_type(&hdr->daddr) &
(IPV6_ADDR_LOOPBACK|IPV6_ADDR_LINKLOCAL)) &&
likely(!(IP6CB(skb)->flags & IP6SKB_FORWARDED))) {
struct sk_buff *skb2;
struct inet6_skb_parm *opt = IP6CB(skb);
if (unlikely(opt->flags & IP6SKB_ROUTERALERT)) {
u8 nexthdr = hdr->nexthdr;
__be16 frag_off;
int offset;
if (opt->ra == htons(IPV6_OPT_ROUTERALERT_MLD)) {
deliver = false;
if (!ipv6_ext_hdr(nexthdr)) {
goto out;
}
offset = ipv6_skip_exthdr(skb, sizeof(*hdr),
&nexthdr, &frag_off);
if (offset < 0)
goto out;
if (ipv6_is_mld(skb, nexthdr, offset))
deliver = true;
goto out;
}
}
if (deliver)
skb2 = skb_clone(skb, GFP_ATOMIC);
else {
skb2 = skb;
skb = NULL;
}
if (skb2) {
ip6_mr_input(skb2);
}
}
out:
#endif
if (likely(deliver))
ip6_input(skb);
else {
kfree_skb(skb);
}
return 0;
}
