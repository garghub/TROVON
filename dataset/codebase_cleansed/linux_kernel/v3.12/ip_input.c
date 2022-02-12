bool ip_call_ra_chain(struct sk_buff *skb)
{
struct ip_ra_chain *ra;
u8 protocol = ip_hdr(skb)->protocol;
struct sock *last = NULL;
struct net_device *dev = skb->dev;
for (ra = rcu_dereference(ip_ra_chain); ra; ra = rcu_dereference(ra->next)) {
struct sock *sk = ra->sk;
if (sk && inet_sk(sk)->inet_num == protocol &&
(!sk->sk_bound_dev_if ||
sk->sk_bound_dev_if == dev->ifindex) &&
net_eq(sock_net(sk), dev_net(dev))) {
if (ip_is_fragment(ip_hdr(skb))) {
if (ip_defrag(skb, IP_DEFRAG_CALL_RA_CHAIN))
return true;
}
if (last) {
struct sk_buff *skb2 = skb_clone(skb, GFP_ATOMIC);
if (skb2)
raw_rcv(last, skb2);
}
last = sk;
}
}
if (last) {
raw_rcv(last, skb);
return true;
}
return false;
}
static int ip_local_deliver_finish(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
__skb_pull(skb, skb_network_header_len(skb));
rcu_read_lock();
{
int protocol = ip_hdr(skb)->protocol;
const struct net_protocol *ipprot;
int raw;
resubmit:
raw = raw_local_deliver(skb, protocol);
ipprot = rcu_dereference(inet_protos[protocol]);
if (ipprot != NULL) {
int ret;
if (!ipprot->no_policy) {
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb)) {
kfree_skb(skb);
goto out;
}
nf_reset(skb);
}
ret = ipprot->handler(skb);
if (ret < 0) {
protocol = -ret;
goto resubmit;
}
IP_INC_STATS_BH(net, IPSTATS_MIB_INDELIVERS);
} else {
if (!raw) {
if (xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb)) {
IP_INC_STATS_BH(net, IPSTATS_MIB_INUNKNOWNPROTOS);
icmp_send(skb, ICMP_DEST_UNREACH,
ICMP_PROT_UNREACH, 0);
}
kfree_skb(skb);
} else {
IP_INC_STATS_BH(net, IPSTATS_MIB_INDELIVERS);
consume_skb(skb);
}
}
}
out:
rcu_read_unlock();
return 0;
}
int ip_local_deliver(struct sk_buff *skb)
{
if (ip_is_fragment(ip_hdr(skb))) {
if (ip_defrag(skb, IP_DEFRAG_LOCAL_DELIVER))
return 0;
}
return NF_HOOK(NFPROTO_IPV4, NF_INET_LOCAL_IN, skb, skb->dev, NULL,
ip_local_deliver_finish);
}
static inline bool ip_rcv_options(struct sk_buff *skb)
{
struct ip_options *opt;
const struct iphdr *iph;
struct net_device *dev = skb->dev;
if (skb_cow(skb, skb_headroom(skb))) {
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INDISCARDS);
goto drop;
}
iph = ip_hdr(skb);
opt = &(IPCB(skb)->opt);
opt->optlen = iph->ihl*4 - sizeof(struct iphdr);
if (ip_options_compile(dev_net(dev), opt, skb)) {
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INHDRERRORS);
goto drop;
}
if (unlikely(opt->srr)) {
struct in_device *in_dev = __in_dev_get_rcu(dev);
if (in_dev) {
if (!IN_DEV_SOURCE_ROUTE(in_dev)) {
if (IN_DEV_LOG_MARTIANS(in_dev))
net_info_ratelimited("source route option %pI4 -> %pI4\n",
&iph->saddr,
&iph->daddr);
goto drop;
}
}
if (ip_options_rcv_srr(skb))
goto drop;
}
return false;
drop:
return true;
}
static int ip_rcv_finish(struct sk_buff *skb)
{
const struct iphdr *iph = ip_hdr(skb);
struct rtable *rt;
if (sysctl_ip_early_demux && !skb_dst(skb)) {
const struct net_protocol *ipprot;
int protocol = iph->protocol;
ipprot = rcu_dereference(inet_protos[protocol]);
if (ipprot && ipprot->early_demux) {
ipprot->early_demux(skb);
iph = ip_hdr(skb);
}
}
if (!skb_dst(skb)) {
int err = ip_route_input_noref(skb, iph->daddr, iph->saddr,
iph->tos, skb->dev);
if (unlikely(err)) {
if (err == -EXDEV)
NET_INC_STATS_BH(dev_net(skb->dev),
LINUX_MIB_IPRPFILTER);
goto drop;
}
}
#ifdef CONFIG_IP_ROUTE_CLASSID
if (unlikely(skb_dst(skb)->tclassid)) {
struct ip_rt_acct *st = this_cpu_ptr(ip_rt_acct);
u32 idx = skb_dst(skb)->tclassid;
st[idx&0xFF].o_packets++;
st[idx&0xFF].o_bytes += skb->len;
st[(idx>>16)&0xFF].i_packets++;
st[(idx>>16)&0xFF].i_bytes += skb->len;
}
#endif
if (iph->ihl > 5 && ip_rcv_options(skb))
goto drop;
rt = skb_rtable(skb);
if (rt->rt_type == RTN_MULTICAST) {
IP_UPD_PO_STATS_BH(dev_net(rt->dst.dev), IPSTATS_MIB_INMCAST,
skb->len);
} else if (rt->rt_type == RTN_BROADCAST)
IP_UPD_PO_STATS_BH(dev_net(rt->dst.dev), IPSTATS_MIB_INBCAST,
skb->len);
return dst_input(skb);
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
int ip_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
{
const struct iphdr *iph;
u32 len;
if (skb->pkt_type == PACKET_OTHERHOST)
goto drop;
IP_UPD_PO_STATS_BH(dev_net(dev), IPSTATS_MIB_IN, skb->len);
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL) {
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INDISCARDS);
goto out;
}
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto inhdr_error;
iph = ip_hdr(skb);
if (iph->ihl < 5 || iph->version != 4)
goto inhdr_error;
BUILD_BUG_ON(IPSTATS_MIB_ECT1PKTS != IPSTATS_MIB_NOECTPKTS + INET_ECN_ECT_1);
BUILD_BUG_ON(IPSTATS_MIB_ECT0PKTS != IPSTATS_MIB_NOECTPKTS + INET_ECN_ECT_0);
BUILD_BUG_ON(IPSTATS_MIB_CEPKTS != IPSTATS_MIB_NOECTPKTS + INET_ECN_CE);
IP_ADD_STATS_BH(dev_net(dev),
IPSTATS_MIB_NOECTPKTS + (iph->tos & INET_ECN_MASK),
max_t(unsigned short, 1, skb_shinfo(skb)->gso_segs));
if (!pskb_may_pull(skb, iph->ihl*4))
goto inhdr_error;
iph = ip_hdr(skb);
if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
goto csum_error;
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
skb->transport_header = skb->network_header + iph->ihl*4;
memset(IPCB(skb), 0, sizeof(struct inet_skb_parm));
skb_orphan(skb);
return NF_HOOK(NFPROTO_IPV4, NF_INET_PRE_ROUTING, skb, dev, NULL,
ip_rcv_finish);
csum_error:
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_CSUMERRORS);
inhdr_error:
IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INHDRERRORS);
drop:
kfree_skb(skb);
out:
return NET_RX_DROP;
}
