static inline struct sock *icmpv6_sk(struct net *net)
{
return net->ipv6.icmp_sk[smp_processor_id()];
}
static void icmpv6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct icmp6hdr *icmp6 = (struct icmp6hdr *) (skb->data + offset);
struct net *net = dev_net(skb->dev);
if (type == ICMPV6_PKT_TOOBIG)
ip6_update_pmtu(skb, net, info, 0, 0, sock_net_uid(net, NULL));
else if (type == NDISC_REDIRECT)
ip6_redirect(skb, net, skb->dev->ifindex, 0,
sock_net_uid(net, NULL));
if (!(type & ICMPV6_INFOMSG_MASK))
if (icmp6->icmp6_type == ICMPV6_ECHO_REQUEST)
ping_err(skb, offset, ntohl(info));
}
__inline__ void icmpv6_xmit_unlock(struct sock *sk)
{
spin_unlock(&sk->sk_lock.slock);
}
static bool is_ineligible(const struct sk_buff *skb)
{
int ptr = (u8 *)(ipv6_hdr(skb) + 1) - skb->data;
int len = skb->len - ptr;
__u8 nexthdr = ipv6_hdr(skb)->nexthdr;
__be16 frag_off;
if (len < 0)
return true;
ptr = ipv6_skip_exthdr(skb, ptr, &nexthdr, &frag_off);
if (ptr < 0)
return false;
if (nexthdr == IPPROTO_ICMPV6) {
u8 _type, *tp;
tp = skb_header_pointer(skb,
ptr+offsetof(struct icmp6hdr, icmp6_type),
sizeof(_type), &_type);
if (!tp || !(*tp & ICMPV6_INFOMSG_MASK))
return true;
}
return false;
}
static bool icmpv6_mask_allow(int type)
{
if (type & ICMPV6_INFOMSG_MASK)
return true;
if (type == ICMPV6_PKT_TOOBIG)
return true;
return false;
}
static bool icmpv6_global_allow(int type)
{
if (icmpv6_mask_allow(type))
return true;
if (icmp_global_allow())
return true;
return false;
}
static bool icmpv6_xrlim_allow(struct sock *sk, u8 type,
struct flowi6 *fl6)
{
struct net *net = sock_net(sk);
struct dst_entry *dst;
bool res = false;
if (icmpv6_mask_allow(type))
return true;
dst = ip6_route_output(net, sk, fl6);
if (dst->error) {
IP6_INC_STATS(net, ip6_dst_idev(dst),
IPSTATS_MIB_OUTNOROUTES);
} else if (dst->dev && (dst->dev->flags&IFF_LOOPBACK)) {
res = true;
} else {
struct rt6_info *rt = (struct rt6_info *)dst;
int tmo = net->ipv6.sysctl.icmpv6_time;
struct inet_peer *peer;
if (rt->rt6i_dst.plen < 128)
tmo >>= ((128 - rt->rt6i_dst.plen)>>5);
peer = inet_getpeer_v6(net->ipv6.peers, &fl6->daddr, 1);
res = inet_peer_xrlim_allow(peer, tmo);
if (peer)
inet_putpeer(peer);
}
dst_release(dst);
return res;
}
static bool opt_unrec(struct sk_buff *skb, __u32 offset)
{
u8 _optval, *op;
offset += skb_network_offset(skb);
op = skb_header_pointer(skb, offset, sizeof(_optval), &_optval);
if (!op)
return true;
return (*op & 0xC0) == 0x80;
}
int icmpv6_push_pending_frames(struct sock *sk, struct flowi6 *fl6,
struct icmp6hdr *thdr, int len)
{
struct sk_buff *skb;
struct icmp6hdr *icmp6h;
int err = 0;
skb = skb_peek(&sk->sk_write_queue);
if (!skb)
goto out;
icmp6h = icmp6_hdr(skb);
memcpy(icmp6h, thdr, sizeof(struct icmp6hdr));
icmp6h->icmp6_cksum = 0;
if (skb_queue_len(&sk->sk_write_queue) == 1) {
skb->csum = csum_partial(icmp6h,
sizeof(struct icmp6hdr), skb->csum);
icmp6h->icmp6_cksum = csum_ipv6_magic(&fl6->saddr,
&fl6->daddr,
len, fl6->flowi6_proto,
skb->csum);
} else {
__wsum tmp_csum = 0;
skb_queue_walk(&sk->sk_write_queue, skb) {
tmp_csum = csum_add(tmp_csum, skb->csum);
}
tmp_csum = csum_partial(icmp6h,
sizeof(struct icmp6hdr), tmp_csum);
icmp6h->icmp6_cksum = csum_ipv6_magic(&fl6->saddr,
&fl6->daddr,
len, fl6->flowi6_proto,
tmp_csum);
}
ip6_push_pending_frames(sk);
out:
return err;
}
static int icmpv6_getfrag(void *from, char *to, int offset, int len, int odd, struct sk_buff *skb)
{
struct icmpv6_msg *msg = (struct icmpv6_msg *) from;
struct sk_buff *org_skb = msg->skb;
__wsum csum = 0;
csum = skb_copy_and_csum_bits(org_skb, msg->offset + offset,
to, len, csum);
skb->csum = csum_block_add(skb->csum, csum, odd);
if (!(msg->type & ICMPV6_INFOMSG_MASK))
nf_ct_attach(skb, org_skb);
return 0;
}
static void mip6_addr_swap(struct sk_buff *skb)
{
struct ipv6hdr *iph = ipv6_hdr(skb);
struct inet6_skb_parm *opt = IP6CB(skb);
struct ipv6_destopt_hao *hao;
struct in6_addr tmp;
int off;
if (opt->dsthao) {
off = ipv6_find_tlv(skb, opt->dsthao, IPV6_TLV_HAO);
if (likely(off >= 0)) {
hao = (struct ipv6_destopt_hao *)
(skb_network_header(skb) + off);
tmp = iph->saddr;
iph->saddr = hao->addr;
hao->addr = tmp;
}
}
}
static inline void mip6_addr_swap(struct sk_buff *skb) {}
static struct dst_entry *icmpv6_route_lookup(struct net *net,
struct sk_buff *skb,
struct sock *sk,
struct flowi6 *fl6)
{
struct dst_entry *dst, *dst2;
struct flowi6 fl2;
int err;
err = ip6_dst_lookup(net, sk, &dst, fl6);
if (err)
return ERR_PTR(err);
if (ipv6_anycast_destination(dst, &fl6->daddr)) {
net_dbg_ratelimited("icmp6_send: acast source\n");
dst_release(dst);
return ERR_PTR(-EINVAL);
}
dst2 = dst;
dst = xfrm_lookup(net, dst, flowi6_to_flowi(fl6), sk, 0);
if (!IS_ERR(dst)) {
if (dst != dst2)
return dst;
} else {
if (PTR_ERR(dst) == -EPERM)
dst = NULL;
else
return dst;
}
err = xfrm_decode_session_reverse(skb, flowi6_to_flowi(&fl2), AF_INET6);
if (err)
goto relookup_failed;
err = ip6_dst_lookup(net, sk, &dst2, &fl2);
if (err)
goto relookup_failed;
dst2 = xfrm_lookup(net, dst2, flowi6_to_flowi(&fl2), sk, XFRM_LOOKUP_ICMP);
if (!IS_ERR(dst2)) {
dst_release(dst);
dst = dst2;
} else {
err = PTR_ERR(dst2);
if (err == -EPERM) {
dst_release(dst);
return dst2;
} else
goto relookup_failed;
}
relookup_failed:
if (dst)
return dst;
return ERR_PTR(err);
}
static int icmp6_iif(const struct sk_buff *skb)
{
int iif = skb->dev->ifindex;
if (unlikely(iif == LOOPBACK_IFINDEX)) {
const struct rt6_info *rt6 = skb_rt6_info(skb);
if (rt6)
iif = rt6->rt6i_idev->dev->ifindex;
}
return iif;
}
static void icmp6_send(struct sk_buff *skb, u8 type, u8 code, __u32 info,
const struct in6_addr *force_saddr)
{
struct net *net = dev_net(skb->dev);
struct inet6_dev *idev = NULL;
struct ipv6hdr *hdr = ipv6_hdr(skb);
struct sock *sk;
struct ipv6_pinfo *np;
const struct in6_addr *saddr = NULL;
struct dst_entry *dst;
struct icmp6hdr tmp_hdr;
struct flowi6 fl6;
struct icmpv6_msg msg;
struct sockcm_cookie sockc_unused = {0};
struct ipcm6_cookie ipc6;
int iif = 0;
int addr_type = 0;
int len;
int err = 0;
u32 mark = IP6_REPLY_MARK(net, skb->mark);
if ((u8 *)hdr < skb->head ||
(skb_network_header(skb) + sizeof(*hdr)) > skb_tail_pointer(skb))
return;
addr_type = ipv6_addr_type(&hdr->daddr);
if (ipv6_chk_addr(net, &hdr->daddr, skb->dev, 0) ||
ipv6_chk_acast_addr_src(net, skb->dev, &hdr->daddr))
saddr = &hdr->daddr;
if (addr_type & IPV6_ADDR_MULTICAST || skb->pkt_type != PACKET_HOST) {
if (type != ICMPV6_PKT_TOOBIG &&
!(type == ICMPV6_PARAMPROB &&
code == ICMPV6_UNK_OPTION &&
(opt_unrec(skb, info))))
return;
saddr = NULL;
}
addr_type = ipv6_addr_type(&hdr->saddr);
if (__ipv6_addr_needs_scope_id(addr_type)) {
iif = icmp6_iif(skb);
} else {
dst = skb_dst(skb);
iif = l3mdev_master_ifindex(dst ? dst->dev : skb->dev);
}
if ((addr_type == IPV6_ADDR_ANY) || (addr_type & IPV6_ADDR_MULTICAST)) {
net_dbg_ratelimited("icmp6_send: addr_any/mcast source [%pI6c > %pI6c]\n",
&hdr->saddr, &hdr->daddr);
return;
}
if (is_ineligible(skb)) {
net_dbg_ratelimited("icmp6_send: no reply to icmp error [%pI6c > %pI6c]\n",
&hdr->saddr, &hdr->daddr);
return;
}
local_bh_disable();
if (!(skb->dev->flags&IFF_LOOPBACK) && !icmpv6_global_allow(type))
goto out_bh_enable;
mip6_addr_swap(skb);
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_ICMPV6;
fl6.daddr = hdr->saddr;
if (force_saddr)
saddr = force_saddr;
if (saddr)
fl6.saddr = *saddr;
fl6.flowi6_mark = mark;
fl6.flowi6_oif = iif;
fl6.fl6_icmp_type = type;
fl6.fl6_icmp_code = code;
fl6.flowi6_uid = sock_net_uid(net, NULL);
fl6.mp_hash = rt6_multipath_hash(&fl6, skb);
security_skb_classify_flow(skb, flowi6_to_flowi(&fl6));
sk = icmpv6_xmit_lock(net);
if (!sk)
goto out_bh_enable;
sk->sk_mark = mark;
np = inet6_sk(sk);
if (!icmpv6_xrlim_allow(sk, type, &fl6))
goto out;
tmp_hdr.icmp6_type = type;
tmp_hdr.icmp6_code = code;
tmp_hdr.icmp6_cksum = 0;
tmp_hdr.icmp6_pointer = htonl(info);
if (!fl6.flowi6_oif && ipv6_addr_is_multicast(&fl6.daddr))
fl6.flowi6_oif = np->mcast_oif;
else if (!fl6.flowi6_oif)
fl6.flowi6_oif = np->ucast_oif;
ipc6.tclass = np->tclass;
fl6.flowlabel = ip6_make_flowinfo(ipc6.tclass, fl6.flowlabel);
dst = icmpv6_route_lookup(net, skb, sk, &fl6);
if (IS_ERR(dst))
goto out;
ipc6.hlimit = ip6_sk_dst_hoplimit(np, &fl6, dst);
ipc6.dontfrag = np->dontfrag;
ipc6.opt = NULL;
msg.skb = skb;
msg.offset = skb_network_offset(skb);
msg.type = type;
len = skb->len - msg.offset;
len = min_t(unsigned int, len, IPV6_MIN_MTU - sizeof(struct ipv6hdr) - sizeof(struct icmp6hdr));
if (len < 0) {
net_dbg_ratelimited("icmp: len problem [%pI6c > %pI6c]\n",
&hdr->saddr, &hdr->daddr);
goto out_dst_release;
}
rcu_read_lock();
idev = __in6_dev_get(skb->dev);
err = ip6_append_data(sk, icmpv6_getfrag, &msg,
len + sizeof(struct icmp6hdr),
sizeof(struct icmp6hdr),
&ipc6, &fl6, (struct rt6_info *)dst,
MSG_DONTWAIT, &sockc_unused);
if (err) {
ICMP6_INC_STATS(net, idev, ICMP6_MIB_OUTERRORS);
ip6_flush_pending_frames(sk);
} else {
err = icmpv6_push_pending_frames(sk, &fl6, &tmp_hdr,
len + sizeof(struct icmp6hdr));
}
rcu_read_unlock();
out_dst_release:
dst_release(dst);
out:
icmpv6_xmit_unlock(sk);
out_bh_enable:
local_bh_enable();
}
void icmpv6_param_prob(struct sk_buff *skb, u8 code, int pos)
{
icmp6_send(skb, ICMPV6_PARAMPROB, code, pos, NULL);
kfree_skb(skb);
}
int ip6_err_gen_icmpv6_unreach(struct sk_buff *skb, int nhs, int type,
unsigned int data_len)
{
struct in6_addr temp_saddr;
struct rt6_info *rt;
struct sk_buff *skb2;
u32 info = 0;
if (!pskb_may_pull(skb, nhs + sizeof(struct ipv6hdr) + 8))
return 1;
if (data_len < 128 || (data_len & 7) || skb->len < data_len)
data_len = 0;
skb2 = data_len ? skb_copy(skb, GFP_ATOMIC) : skb_clone(skb, GFP_ATOMIC);
if (!skb2)
return 1;
skb_dst_drop(skb2);
skb_pull(skb2, nhs);
skb_reset_network_header(skb2);
rt = rt6_lookup(dev_net(skb->dev), &ipv6_hdr(skb2)->saddr, NULL, 0, 0);
if (rt && rt->dst.dev)
skb2->dev = rt->dst.dev;
ipv6_addr_set_v4mapped(ip_hdr(skb)->saddr, &temp_saddr);
if (data_len) {
__skb_push(skb2, nhs);
skb_reset_network_header(skb2);
memmove(skb2->data, skb2->data + nhs, data_len - nhs);
memset(skb2->data + data_len - nhs, 0, nhs);
info = (data_len/8) << 24;
}
if (type == ICMP_TIME_EXCEEDED)
icmp6_send(skb2, ICMPV6_TIME_EXCEED, ICMPV6_EXC_HOPLIMIT,
info, &temp_saddr);
else
icmp6_send(skb2, ICMPV6_DEST_UNREACH, ICMPV6_ADDR_UNREACH,
info, &temp_saddr);
if (rt)
ip6_rt_put(rt);
kfree_skb(skb2);
return 0;
}
static void icmpv6_echo_reply(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
struct sock *sk;
struct inet6_dev *idev;
struct ipv6_pinfo *np;
const struct in6_addr *saddr = NULL;
struct icmp6hdr *icmph = icmp6_hdr(skb);
struct icmp6hdr tmp_hdr;
struct flowi6 fl6;
struct icmpv6_msg msg;
struct dst_entry *dst;
struct ipcm6_cookie ipc6;
int err = 0;
u32 mark = IP6_REPLY_MARK(net, skb->mark);
struct sockcm_cookie sockc_unused = {0};
saddr = &ipv6_hdr(skb)->daddr;
if (!ipv6_unicast_destination(skb) &&
!(net->ipv6.sysctl.anycast_src_echo_reply &&
ipv6_anycast_destination(skb_dst(skb), saddr)))
saddr = NULL;
memcpy(&tmp_hdr, icmph, sizeof(tmp_hdr));
tmp_hdr.icmp6_type = ICMPV6_ECHO_REPLY;
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_ICMPV6;
fl6.daddr = ipv6_hdr(skb)->saddr;
if (saddr)
fl6.saddr = *saddr;
fl6.flowi6_oif = icmp6_iif(skb);
fl6.fl6_icmp_type = ICMPV6_ECHO_REPLY;
fl6.flowi6_mark = mark;
fl6.flowi6_uid = sock_net_uid(net, NULL);
security_skb_classify_flow(skb, flowi6_to_flowi(&fl6));
local_bh_disable();
sk = icmpv6_xmit_lock(net);
if (!sk)
goto out_bh_enable;
sk->sk_mark = mark;
np = inet6_sk(sk);
if (!fl6.flowi6_oif && ipv6_addr_is_multicast(&fl6.daddr))
fl6.flowi6_oif = np->mcast_oif;
else if (!fl6.flowi6_oif)
fl6.flowi6_oif = np->ucast_oif;
err = ip6_dst_lookup(net, sk, &dst, &fl6);
if (err)
goto out;
dst = xfrm_lookup(net, dst, flowi6_to_flowi(&fl6), sk, 0);
if (IS_ERR(dst))
goto out;
idev = __in6_dev_get(skb->dev);
msg.skb = skb;
msg.offset = 0;
msg.type = ICMPV6_ECHO_REPLY;
ipc6.hlimit = ip6_sk_dst_hoplimit(np, &fl6, dst);
ipc6.tclass = ipv6_get_dsfield(ipv6_hdr(skb));
ipc6.dontfrag = np->dontfrag;
ipc6.opt = NULL;
err = ip6_append_data(sk, icmpv6_getfrag, &msg, skb->len + sizeof(struct icmp6hdr),
sizeof(struct icmp6hdr), &ipc6, &fl6,
(struct rt6_info *)dst, MSG_DONTWAIT,
&sockc_unused);
if (err) {
__ICMP6_INC_STATS(net, idev, ICMP6_MIB_OUTERRORS);
ip6_flush_pending_frames(sk);
} else {
err = icmpv6_push_pending_frames(sk, &fl6, &tmp_hdr,
skb->len + sizeof(struct icmp6hdr));
}
dst_release(dst);
out:
icmpv6_xmit_unlock(sk);
out_bh_enable:
local_bh_enable();
}
void icmpv6_notify(struct sk_buff *skb, u8 type, u8 code, __be32 info)
{
const struct inet6_protocol *ipprot;
int inner_offset;
__be16 frag_off;
u8 nexthdr;
struct net *net = dev_net(skb->dev);
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto out;
nexthdr = ((struct ipv6hdr *)skb->data)->nexthdr;
if (ipv6_ext_hdr(nexthdr)) {
inner_offset = ipv6_skip_exthdr(skb, sizeof(struct ipv6hdr),
&nexthdr, &frag_off);
if (inner_offset < 0)
goto out;
} else {
inner_offset = sizeof(struct ipv6hdr);
}
if (!pskb_may_pull(skb, inner_offset+8))
goto out;
ipprot = rcu_dereference(inet6_protos[nexthdr]);
if (ipprot && ipprot->err_handler)
ipprot->err_handler(skb, NULL, type, code, inner_offset, info);
raw6_icmp_error(skb, nexthdr, type, code, inner_offset, info);
return;
out:
__ICMP6_INC_STATS(net, __in6_dev_get(skb->dev), ICMP6_MIB_INERRORS);
}
static int icmpv6_rcv(struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
struct inet6_dev *idev = __in6_dev_get(dev);
const struct in6_addr *saddr, *daddr;
struct icmp6hdr *hdr;
u8 type;
bool success = false;
if (!xfrm6_policy_check(NULL, XFRM_POLICY_IN, skb)) {
struct sec_path *sp = skb_sec_path(skb);
int nh;
if (!(sp && sp->xvec[sp->len - 1]->props.flags &
XFRM_STATE_ICMP))
goto drop_no_count;
if (!pskb_may_pull(skb, sizeof(*hdr) + sizeof(struct ipv6hdr)))
goto drop_no_count;
nh = skb_network_offset(skb);
skb_set_network_header(skb, sizeof(*hdr));
if (!xfrm6_policy_check_reverse(NULL, XFRM_POLICY_IN, skb))
goto drop_no_count;
skb_set_network_header(skb, nh);
}
__ICMP6_INC_STATS(dev_net(dev), idev, ICMP6_MIB_INMSGS);
saddr = &ipv6_hdr(skb)->saddr;
daddr = &ipv6_hdr(skb)->daddr;
if (skb_checksum_validate(skb, IPPROTO_ICMPV6, ip6_compute_pseudo)) {
net_dbg_ratelimited("ICMPv6 checksum failed [%pI6c > %pI6c]\n",
saddr, daddr);
goto csum_error;
}
if (!pskb_pull(skb, sizeof(*hdr)))
goto discard_it;
hdr = icmp6_hdr(skb);
type = hdr->icmp6_type;
ICMP6MSGIN_INC_STATS(dev_net(dev), idev, type);
switch (type) {
case ICMPV6_ECHO_REQUEST:
icmpv6_echo_reply(skb);
break;
case ICMPV6_ECHO_REPLY:
success = ping_rcv(skb);
break;
case ICMPV6_PKT_TOOBIG:
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto discard_it;
hdr = icmp6_hdr(skb);
case ICMPV6_DEST_UNREACH:
case ICMPV6_TIME_EXCEED:
case ICMPV6_PARAMPROB:
icmpv6_notify(skb, type, hdr->icmp6_code, hdr->icmp6_mtu);
break;
case NDISC_ROUTER_SOLICITATION:
case NDISC_ROUTER_ADVERTISEMENT:
case NDISC_NEIGHBOUR_SOLICITATION:
case NDISC_NEIGHBOUR_ADVERTISEMENT:
case NDISC_REDIRECT:
ndisc_rcv(skb);
break;
case ICMPV6_MGM_QUERY:
igmp6_event_query(skb);
break;
case ICMPV6_MGM_REPORT:
igmp6_event_report(skb);
break;
case ICMPV6_MGM_REDUCTION:
case ICMPV6_NI_QUERY:
case ICMPV6_NI_REPLY:
case ICMPV6_MLD2_REPORT:
case ICMPV6_DHAAD_REQUEST:
case ICMPV6_DHAAD_REPLY:
case ICMPV6_MOBILE_PREFIX_SOL:
case ICMPV6_MOBILE_PREFIX_ADV:
break;
default:
if (type & ICMPV6_INFOMSG_MASK)
break;
net_dbg_ratelimited("icmpv6: msg of unknown type [%pI6c > %pI6c]\n",
saddr, daddr);
icmpv6_notify(skb, type, hdr->icmp6_code, hdr->icmp6_mtu);
}
if (success)
consume_skb(skb);
else
kfree_skb(skb);
return 0;
csum_error:
__ICMP6_INC_STATS(dev_net(dev), idev, ICMP6_MIB_CSUMERRORS);
discard_it:
__ICMP6_INC_STATS(dev_net(dev), idev, ICMP6_MIB_INERRORS);
drop_no_count:
kfree_skb(skb);
return 0;
}
void icmpv6_flow_init(struct sock *sk, struct flowi6 *fl6,
u8 type,
const struct in6_addr *saddr,
const struct in6_addr *daddr,
int oif)
{
memset(fl6, 0, sizeof(*fl6));
fl6->saddr = *saddr;
fl6->daddr = *daddr;
fl6->flowi6_proto = IPPROTO_ICMPV6;
fl6->fl6_icmp_type = type;
fl6->fl6_icmp_code = 0;
fl6->flowi6_oif = oif;
security_sk_classify_flow(sk, flowi6_to_flowi(fl6));
}
static int __net_init icmpv6_sk_init(struct net *net)
{
struct sock *sk;
int err, i, j;
net->ipv6.icmp_sk =
kzalloc(nr_cpu_ids * sizeof(struct sock *), GFP_KERNEL);
if (!net->ipv6.icmp_sk)
return -ENOMEM;
for_each_possible_cpu(i) {
err = inet_ctl_sock_create(&sk, PF_INET6,
SOCK_RAW, IPPROTO_ICMPV6, net);
if (err < 0) {
pr_err("Failed to initialize the ICMP6 control socket (err %d)\n",
err);
goto fail;
}
net->ipv6.icmp_sk[i] = sk;
sk->sk_sndbuf = 2 * SKB_TRUESIZE(64 * 1024);
}
return 0;
fail:
for (j = 0; j < i; j++)
inet_ctl_sock_destroy(net->ipv6.icmp_sk[j]);
kfree(net->ipv6.icmp_sk);
return err;
}
static void __net_exit icmpv6_sk_exit(struct net *net)
{
int i;
for_each_possible_cpu(i) {
inet_ctl_sock_destroy(net->ipv6.icmp_sk[i]);
}
kfree(net->ipv6.icmp_sk);
}
int __init icmpv6_init(void)
{
int err;
err = register_pernet_subsys(&icmpv6_sk_ops);
if (err < 0)
return err;
err = -EAGAIN;
if (inet6_add_protocol(&icmpv6_protocol, IPPROTO_ICMPV6) < 0)
goto fail;
err = inet6_register_icmp_sender(icmp6_send);
if (err)
goto sender_reg_err;
return 0;
sender_reg_err:
inet6_del_protocol(&icmpv6_protocol, IPPROTO_ICMPV6);
fail:
pr_err("Failed to register ICMP6 protocol\n");
unregister_pernet_subsys(&icmpv6_sk_ops);
return err;
}
void icmpv6_cleanup(void)
{
inet6_unregister_icmp_sender(icmp6_send);
unregister_pernet_subsys(&icmpv6_sk_ops);
inet6_del_protocol(&icmpv6_protocol, IPPROTO_ICMPV6);
}
int icmpv6_err_convert(u8 type, u8 code, int *err)
{
int fatal = 0;
*err = EPROTO;
switch (type) {
case ICMPV6_DEST_UNREACH:
fatal = 1;
if (code < ARRAY_SIZE(tab_unreach)) {
*err = tab_unreach[code].err;
fatal = tab_unreach[code].fatal;
}
break;
case ICMPV6_PKT_TOOBIG:
*err = EMSGSIZE;
break;
case ICMPV6_PARAMPROB:
*err = EPROTO;
fatal = 1;
break;
case ICMPV6_TIME_EXCEED:
*err = EHOSTUNREACH;
break;
}
return fatal;
}
struct ctl_table * __net_init ipv6_icmp_sysctl_init(struct net *net)
{
struct ctl_table *table;
table = kmemdup(ipv6_icmp_table_template,
sizeof(ipv6_icmp_table_template),
GFP_KERNEL);
if (table)
table[0].data = &net->ipv6.sysctl.icmpv6_time;
return table;
}
