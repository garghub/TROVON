static struct sock *icmp_sk(struct net *net)
{
return net->ipv4.icmp_sk[smp_processor_id()];
}
static inline struct sock *icmp_xmit_lock(struct net *net)
{
struct sock *sk;
local_bh_disable();
sk = icmp_sk(net);
if (unlikely(!spin_trylock(&sk->sk_lock.slock))) {
local_bh_enable();
return NULL;
}
return sk;
}
static inline void icmp_xmit_unlock(struct sock *sk)
{
spin_unlock_bh(&sk->sk_lock.slock);
}
static inline bool icmpv4_xrlim_allow(struct net *net, struct rtable *rt,
struct flowi4 *fl4, int type, int code)
{
struct dst_entry *dst = &rt->dst;
bool rc = true;
if (type > NR_ICMP_TYPES)
goto out;
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED)
goto out;
if (dst->dev && (dst->dev->flags&IFF_LOOPBACK))
goto out;
if ((1 << type) & net->ipv4.sysctl_icmp_ratemask) {
if (!rt->peer)
rt_bind_peer(rt, fl4->daddr, 1);
rc = inet_peer_xrlim_allow(rt->peer,
net->ipv4.sysctl_icmp_ratelimit);
}
out:
return rc;
}
void icmp_out_count(struct net *net, unsigned char type)
{
ICMPMSGOUT_INC_STATS(net, type);
ICMP_INC_STATS(net, ICMP_MIB_OUTMSGS);
}
static int icmp_glue_bits(void *from, char *to, int offset, int len, int odd,
struct sk_buff *skb)
{
struct icmp_bxm *icmp_param = (struct icmp_bxm *)from;
__wsum csum;
csum = skb_copy_and_csum_bits(icmp_param->skb,
icmp_param->offset + offset,
to, len, 0);
skb->csum = csum_block_add(skb->csum, csum, odd);
if (icmp_pointers[icmp_param->data.icmph.type].error)
nf_ct_attach(skb, icmp_param->skb);
return 0;
}
static void icmp_push_reply(struct icmp_bxm *icmp_param,
struct flowi4 *fl4,
struct ipcm_cookie *ipc, struct rtable **rt)
{
struct sock *sk;
struct sk_buff *skb;
sk = icmp_sk(dev_net((*rt)->dst.dev));
if (ip_append_data(sk, fl4, icmp_glue_bits, icmp_param,
icmp_param->data_len+icmp_param->head_len,
icmp_param->head_len,
ipc, rt, MSG_DONTWAIT) < 0) {
ICMP_INC_STATS_BH(sock_net(sk), ICMP_MIB_OUTERRORS);
ip_flush_pending_frames(sk);
} else if ((skb = skb_peek(&sk->sk_write_queue)) != NULL) {
struct icmphdr *icmph = icmp_hdr(skb);
__wsum csum = 0;
struct sk_buff *skb1;
skb_queue_walk(&sk->sk_write_queue, skb1) {
csum = csum_add(csum, skb1->csum);
}
csum = csum_partial_copy_nocheck((void *)&icmp_param->data,
(char *)icmph,
icmp_param->head_len, csum);
icmph->checksum = csum_fold(csum);
skb->ip_summed = CHECKSUM_NONE;
ip_push_pending_frames(sk, fl4);
}
}
static void icmp_reply(struct icmp_bxm *icmp_param, struct sk_buff *skb)
{
struct ipcm_cookie ipc;
struct rtable *rt = skb_rtable(skb);
struct net *net = dev_net(rt->dst.dev);
struct flowi4 fl4;
struct sock *sk;
struct inet_sock *inet;
__be32 daddr;
if (ip_options_echo(&icmp_param->replyopts.opt.opt, skb))
return;
sk = icmp_xmit_lock(net);
if (sk == NULL)
return;
inet = inet_sk(sk);
icmp_param->data.icmph.checksum = 0;
inet->tos = ip_hdr(skb)->tos;
daddr = ipc.addr = ip_hdr(skb)->saddr;
ipc.opt = NULL;
ipc.tx_flags = 0;
if (icmp_param->replyopts.opt.opt.optlen) {
ipc.opt = &icmp_param->replyopts.opt;
if (ipc.opt->opt.srr)
daddr = icmp_param->replyopts.opt.opt.faddr;
}
memset(&fl4, 0, sizeof(fl4));
fl4.daddr = daddr;
fl4.saddr = rt->rt_spec_dst;
fl4.flowi4_tos = RT_TOS(ip_hdr(skb)->tos);
fl4.flowi4_proto = IPPROTO_ICMP;
security_skb_classify_flow(skb, flowi4_to_flowi(&fl4));
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt))
goto out_unlock;
if (icmpv4_xrlim_allow(net, rt, &fl4, icmp_param->data.icmph.type,
icmp_param->data.icmph.code))
icmp_push_reply(icmp_param, &fl4, &ipc, &rt);
ip_rt_put(rt);
out_unlock:
icmp_xmit_unlock(sk);
}
static struct rtable *icmp_route_lookup(struct net *net,
struct flowi4 *fl4,
struct sk_buff *skb_in,
const struct iphdr *iph,
__be32 saddr, u8 tos,
int type, int code,
struct icmp_bxm *param)
{
struct rtable *rt, *rt2;
int err;
memset(fl4, 0, sizeof(*fl4));
fl4->daddr = (param->replyopts.opt.opt.srr ?
param->replyopts.opt.opt.faddr : iph->saddr);
fl4->saddr = saddr;
fl4->flowi4_tos = RT_TOS(tos);
fl4->flowi4_proto = IPPROTO_ICMP;
fl4->fl4_icmp_type = type;
fl4->fl4_icmp_code = code;
security_skb_classify_flow(skb_in, flowi4_to_flowi(fl4));
rt = __ip_route_output_key(net, fl4);
if (IS_ERR(rt))
return rt;
rt2 = rt;
rt = (struct rtable *) xfrm_lookup(net, &rt->dst,
flowi4_to_flowi(fl4), NULL, 0);
if (!IS_ERR(rt)) {
if (rt != rt2)
return rt;
} else if (PTR_ERR(rt) == -EPERM) {
rt = NULL;
} else
return rt;
err = xfrm_decode_session_reverse(skb_in, flowi4_to_flowi(fl4), AF_INET);
if (err)
goto relookup_failed;
if (inet_addr_type(net, fl4->saddr) == RTN_LOCAL) {
rt2 = __ip_route_output_key(net, fl4);
if (IS_ERR(rt2))
err = PTR_ERR(rt2);
} else {
struct flowi4 fl4_2 = {};
unsigned long orefdst;
fl4_2.daddr = fl4->saddr;
rt2 = ip_route_output_key(net, &fl4_2);
if (IS_ERR(rt2)) {
err = PTR_ERR(rt2);
goto relookup_failed;
}
orefdst = skb_in->_skb_refdst;
err = ip_route_input(skb_in, fl4->daddr, fl4->saddr,
RT_TOS(tos), rt2->dst.dev);
dst_release(&rt2->dst);
rt2 = skb_rtable(skb_in);
skb_in->_skb_refdst = orefdst;
}
if (err)
goto relookup_failed;
rt2 = (struct rtable *) xfrm_lookup(net, &rt2->dst,
flowi4_to_flowi(fl4), NULL,
XFRM_LOOKUP_ICMP);
if (!IS_ERR(rt2)) {
dst_release(&rt->dst);
rt = rt2;
} else if (PTR_ERR(rt2) == -EPERM) {
if (rt)
dst_release(&rt->dst);
return rt2;
} else {
err = PTR_ERR(rt2);
goto relookup_failed;
}
return rt;
relookup_failed:
if (rt)
return rt;
return ERR_PTR(err);
}
void icmp_send(struct sk_buff *skb_in, int type, int code, __be32 info)
{
struct iphdr *iph;
int room;
struct icmp_bxm icmp_param;
struct rtable *rt = skb_rtable(skb_in);
struct ipcm_cookie ipc;
struct flowi4 fl4;
__be32 saddr;
u8 tos;
struct net *net;
struct sock *sk;
if (!rt)
goto out;
net = dev_net(rt->dst.dev);
iph = ip_hdr(skb_in);
if ((u8 *)iph < skb_in->head ||
(skb_in->network_header + sizeof(*iph)) > skb_in->tail)
goto out;
if (skb_in->pkt_type != PACKET_HOST)
goto out;
if (rt->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST))
goto out;
if (iph->frag_off & htons(IP_OFFSET))
goto out;
if (icmp_pointers[type].error) {
if (iph->protocol == IPPROTO_ICMP) {
u8 _inner_type, *itp;
itp = skb_header_pointer(skb_in,
skb_network_header(skb_in) +
(iph->ihl << 2) +
offsetof(struct icmphdr,
type) -
skb_in->data,
sizeof(_inner_type),
&_inner_type);
if (itp == NULL)
goto out;
if (*itp > NR_ICMP_TYPES ||
icmp_pointers[*itp].error)
goto out;
}
}
sk = icmp_xmit_lock(net);
if (sk == NULL)
return;
saddr = iph->daddr;
if (!(rt->rt_flags & RTCF_LOCAL)) {
struct net_device *dev = NULL;
rcu_read_lock();
if (rt_is_input_route(rt) &&
net->ipv4.sysctl_icmp_errors_use_inbound_ifaddr)
dev = dev_get_by_index_rcu(net, rt->rt_iif);
if (dev)
saddr = inet_select_addr(dev, 0, RT_SCOPE_LINK);
else
saddr = 0;
rcu_read_unlock();
}
tos = icmp_pointers[type].error ? ((iph->tos & IPTOS_TOS_MASK) |
IPTOS_PREC_INTERNETCONTROL) :
iph->tos;
if (ip_options_echo(&icmp_param.replyopts.opt.opt, skb_in))
goto out_unlock;
icmp_param.data.icmph.type = type;
icmp_param.data.icmph.code = code;
icmp_param.data.icmph.un.gateway = info;
icmp_param.data.icmph.checksum = 0;
icmp_param.skb = skb_in;
icmp_param.offset = skb_network_offset(skb_in);
inet_sk(sk)->tos = tos;
ipc.addr = iph->saddr;
ipc.opt = &icmp_param.replyopts.opt;
ipc.tx_flags = 0;
rt = icmp_route_lookup(net, &fl4, skb_in, iph, saddr, tos,
type, code, &icmp_param);
if (IS_ERR(rt))
goto out_unlock;
if (!icmpv4_xrlim_allow(net, rt, &fl4, type, code))
goto ende;
room = dst_mtu(&rt->dst);
if (room > 576)
room = 576;
room -= sizeof(struct iphdr) + icmp_param.replyopts.opt.opt.optlen;
room -= sizeof(struct icmphdr);
icmp_param.data_len = skb_in->len - icmp_param.offset;
if (icmp_param.data_len > room)
icmp_param.data_len = room;
icmp_param.head_len = sizeof(struct icmphdr);
icmp_push_reply(&icmp_param, &fl4, &ipc, &rt);
ende:
ip_rt_put(rt);
out_unlock:
icmp_xmit_unlock(sk);
out:;
}
static void icmp_unreach(struct sk_buff *skb)
{
const struct iphdr *iph;
struct icmphdr *icmph;
int hash, protocol;
const struct net_protocol *ipprot;
u32 info = 0;
struct net *net;
net = dev_net(skb_dst(skb)->dev);
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto out_err;
icmph = icmp_hdr(skb);
iph = (const struct iphdr *)skb->data;
if (iph->ihl < 5)
goto out_err;
if (icmph->type == ICMP_DEST_UNREACH) {
switch (icmph->code & 15) {
case ICMP_NET_UNREACH:
case ICMP_HOST_UNREACH:
case ICMP_PROT_UNREACH:
case ICMP_PORT_UNREACH:
break;
case ICMP_FRAG_NEEDED:
if (ipv4_config.no_pmtu_disc) {
LIMIT_NETDEBUG(KERN_INFO "ICMP: %pI4: fragmentation needed and DF set.\n",
&iph->daddr);
} else {
info = ip_rt_frag_needed(net, iph,
ntohs(icmph->un.frag.mtu),
skb->dev);
if (!info)
goto out;
}
break;
case ICMP_SR_FAILED:
LIMIT_NETDEBUG(KERN_INFO "ICMP: %pI4: Source Route Failed.\n",
&iph->daddr);
break;
default:
break;
}
if (icmph->code > NR_ICMP_UNREACH)
goto out;
} else if (icmph->type == ICMP_PARAMETERPROB)
info = ntohl(icmph->un.gateway) >> 24;
if (!net->ipv4.sysctl_icmp_ignore_bogus_error_responses &&
inet_addr_type(net, iph->daddr) == RTN_BROADCAST) {
if (net_ratelimit())
printk(KERN_WARNING "%pI4 sent an invalid ICMP "
"type %u, code %u "
"error to a broadcast: %pI4 on %s\n",
&ip_hdr(skb)->saddr,
icmph->type, icmph->code,
&iph->daddr,
skb->dev->name);
goto out;
}
if (!pskb_may_pull(skb, iph->ihl * 4 + 8))
goto out;
iph = (const struct iphdr *)skb->data;
protocol = iph->protocol;
raw_icmp_error(skb, protocol, info);
hash = protocol & (MAX_INET_PROTOS - 1);
rcu_read_lock();
ipprot = rcu_dereference(inet_protos[hash]);
if (ipprot && ipprot->err_handler)
ipprot->err_handler(skb, info);
rcu_read_unlock();
out:
return;
out_err:
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
goto out;
}
static void icmp_redirect(struct sk_buff *skb)
{
const struct iphdr *iph;
if (skb->len < sizeof(struct iphdr))
goto out_err;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto out;
iph = (const struct iphdr *)skb->data;
switch (icmp_hdr(skb)->code & 7) {
case ICMP_REDIR_NET:
case ICMP_REDIR_NETTOS:
case ICMP_REDIR_HOST:
case ICMP_REDIR_HOSTTOS:
ip_rt_redirect(ip_hdr(skb)->saddr, iph->daddr,
icmp_hdr(skb)->un.gateway,
iph->saddr, skb->dev);
break;
}
if (iph->protocol == IPPROTO_ICMP &&
iph->ihl >= 5 &&
pskb_may_pull(skb, (iph->ihl<<2)+8)) {
ping_err(skb, icmp_hdr(skb)->un.gateway);
}
out:
return;
out_err:
ICMP_INC_STATS_BH(dev_net(skb->dev), ICMP_MIB_INERRORS);
goto out;
}
static void icmp_echo(struct sk_buff *skb)
{
struct net *net;
net = dev_net(skb_dst(skb)->dev);
if (!net->ipv4.sysctl_icmp_echo_ignore_all) {
struct icmp_bxm icmp_param;
icmp_param.data.icmph = *icmp_hdr(skb);
icmp_param.data.icmph.type = ICMP_ECHOREPLY;
icmp_param.skb = skb;
icmp_param.offset = 0;
icmp_param.data_len = skb->len;
icmp_param.head_len = sizeof(struct icmphdr);
icmp_reply(&icmp_param, skb);
}
}
static void icmp_timestamp(struct sk_buff *skb)
{
struct timespec tv;
struct icmp_bxm icmp_param;
if (skb->len < 4)
goto out_err;
getnstimeofday(&tv);
icmp_param.data.times[1] = htonl((tv.tv_sec % 86400) * MSEC_PER_SEC +
tv.tv_nsec / NSEC_PER_MSEC);
icmp_param.data.times[2] = icmp_param.data.times[1];
if (skb_copy_bits(skb, 0, &icmp_param.data.times[0], 4))
BUG();
icmp_param.data.icmph = *icmp_hdr(skb);
icmp_param.data.icmph.type = ICMP_TIMESTAMPREPLY;
icmp_param.data.icmph.code = 0;
icmp_param.skb = skb;
icmp_param.offset = 0;
icmp_param.data_len = 0;
icmp_param.head_len = sizeof(struct icmphdr) + 12;
icmp_reply(&icmp_param, skb);
out:
return;
out_err:
ICMP_INC_STATS_BH(dev_net(skb_dst(skb)->dev), ICMP_MIB_INERRORS);
goto out;
}
static void icmp_address(struct sk_buff *skb)
{
#if 0
if (net_ratelimit())
printk(KERN_DEBUG "a guy asks for address mask. Who is it?\n");
#endif
}
static void icmp_address_reply(struct sk_buff *skb)
{
struct rtable *rt = skb_rtable(skb);
struct net_device *dev = skb->dev;
struct in_device *in_dev;
struct in_ifaddr *ifa;
if (skb->len < 4 || !(rt->rt_flags&RTCF_DIRECTSRC))
return;
in_dev = __in_dev_get_rcu(dev);
if (!in_dev)
return;
if (in_dev->ifa_list &&
IN_DEV_LOG_MARTIANS(in_dev) &&
IN_DEV_FORWARD(in_dev)) {
__be32 _mask, *mp;
mp = skb_header_pointer(skb, 0, sizeof(_mask), &_mask);
BUG_ON(mp == NULL);
for (ifa = in_dev->ifa_list; ifa; ifa = ifa->ifa_next) {
if (*mp == ifa->ifa_mask &&
inet_ifa_match(ip_hdr(skb)->saddr, ifa))
break;
}
if (!ifa && net_ratelimit()) {
printk(KERN_INFO "Wrong address mask %pI4 from %s/%pI4\n",
mp, dev->name, &ip_hdr(skb)->saddr);
}
}
}
static void icmp_discard(struct sk_buff *skb)
{
}
int icmp_rcv(struct sk_buff *skb)
{
struct icmphdr *icmph;
struct rtable *rt = skb_rtable(skb);
struct net *net = dev_net(rt->dst.dev);
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb)) {
struct sec_path *sp = skb_sec_path(skb);
int nh;
if (!(sp && sp->xvec[sp->len - 1]->props.flags &
XFRM_STATE_ICMP))
goto drop;
if (!pskb_may_pull(skb, sizeof(*icmph) + sizeof(struct iphdr)))
goto drop;
nh = skb_network_offset(skb);
skb_set_network_header(skb, sizeof(*icmph));
if (!xfrm4_policy_check_reverse(NULL, XFRM_POLICY_IN, skb))
goto drop;
skb_set_network_header(skb, nh);
}
ICMP_INC_STATS_BH(net, ICMP_MIB_INMSGS);
switch (skb->ip_summed) {
case CHECKSUM_COMPLETE:
if (!csum_fold(skb->csum))
break;
case CHECKSUM_NONE:
skb->csum = 0;
if (__skb_checksum_complete(skb))
goto error;
}
if (!pskb_pull(skb, sizeof(*icmph)))
goto error;
icmph = icmp_hdr(skb);
ICMPMSGIN_INC_STATS_BH(net, icmph->type);
if (icmph->type > NR_ICMP_TYPES)
goto error;
if (rt->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST)) {
if ((icmph->type == ICMP_ECHO ||
icmph->type == ICMP_TIMESTAMP) &&
net->ipv4.sysctl_icmp_echo_ignore_broadcasts) {
goto error;
}
if (icmph->type != ICMP_ECHO &&
icmph->type != ICMP_TIMESTAMP &&
icmph->type != ICMP_ADDRESS &&
icmph->type != ICMP_ADDRESSREPLY) {
goto error;
}
}
icmp_pointers[icmph->type].handler(skb);
drop:
kfree_skb(skb);
return 0;
error:
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
goto drop;
}
static void __net_exit icmp_sk_exit(struct net *net)
{
int i;
for_each_possible_cpu(i)
inet_ctl_sock_destroy(net->ipv4.icmp_sk[i]);
kfree(net->ipv4.icmp_sk);
net->ipv4.icmp_sk = NULL;
}
static int __net_init icmp_sk_init(struct net *net)
{
int i, err;
net->ipv4.icmp_sk =
kzalloc(nr_cpu_ids * sizeof(struct sock *), GFP_KERNEL);
if (net->ipv4.icmp_sk == NULL)
return -ENOMEM;
for_each_possible_cpu(i) {
struct sock *sk;
err = inet_ctl_sock_create(&sk, PF_INET,
SOCK_RAW, IPPROTO_ICMP, net);
if (err < 0)
goto fail;
net->ipv4.icmp_sk[i] = sk;
sk->sk_sndbuf =
(2 * ((64 * 1024) + sizeof(struct sk_buff)));
sock_set_flag(sk, SOCK_USE_WRITE_QUEUE);
inet_sk(sk)->pmtudisc = IP_PMTUDISC_DONT;
}
net->ipv4.sysctl_icmp_echo_ignore_all = 0;
net->ipv4.sysctl_icmp_echo_ignore_broadcasts = 1;
net->ipv4.sysctl_icmp_ignore_bogus_error_responses = 1;
net->ipv4.sysctl_icmp_ratelimit = 1 * HZ;
net->ipv4.sysctl_icmp_ratemask = 0x1818;
net->ipv4.sysctl_icmp_errors_use_inbound_ifaddr = 0;
return 0;
fail:
for_each_possible_cpu(i)
inet_ctl_sock_destroy(net->ipv4.icmp_sk[i]);
kfree(net->ipv4.icmp_sk);
return err;
}
int __init icmp_init(void)
{
return register_pernet_subsys(&icmp_sk_ops);
}
