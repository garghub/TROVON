static inline __u32 tcp_v4_init_sequence(const struct sk_buff *skb)
{
return secure_tcp_sequence_number(ip_hdr(skb)->daddr,
ip_hdr(skb)->saddr,
tcp_hdr(skb)->dest,
tcp_hdr(skb)->source);
}
int tcp_twsk_unique(struct sock *sk, struct sock *sktw, void *twp)
{
const struct tcp_timewait_sock *tcptw = tcp_twsk(sktw);
struct tcp_sock *tp = tcp_sk(sk);
if (tcptw->tw_ts_recent_stamp &&
(twp == NULL || (sysctl_tcp_tw_reuse &&
get_seconds() - tcptw->tw_ts_recent_stamp > 1))) {
tp->write_seq = tcptw->tw_snd_nxt + 65535 + 2;
if (tp->write_seq == 0)
tp->write_seq = 1;
tp->rx_opt.ts_recent = tcptw->tw_ts_recent;
tp->rx_opt.ts_recent_stamp = tcptw->tw_ts_recent_stamp;
sock_hold(sktw);
return 1;
}
return 0;
}
static int tcp_repair_connect(struct sock *sk)
{
tcp_connect_init(sk);
tcp_finish_connect(sk, NULL);
return 0;
}
int tcp_v4_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct sockaddr_in *usin = (struct sockaddr_in *)uaddr;
struct inet_sock *inet = inet_sk(sk);
struct tcp_sock *tp = tcp_sk(sk);
__be16 orig_sport, orig_dport;
__be32 daddr, nexthop;
struct flowi4 *fl4;
struct rtable *rt;
int err;
struct ip_options_rcu *inet_opt;
if (addr_len < sizeof(struct sockaddr_in))
return -EINVAL;
if (usin->sin_family != AF_INET)
return -EAFNOSUPPORT;
nexthop = daddr = usin->sin_addr.s_addr;
inet_opt = rcu_dereference_protected(inet->inet_opt,
sock_owned_by_user(sk));
if (inet_opt && inet_opt->opt.srr) {
if (!daddr)
return -EINVAL;
nexthop = inet_opt->opt.faddr;
}
orig_sport = inet->inet_sport;
orig_dport = usin->sin_port;
fl4 = &inet->cork.fl.u.ip4;
rt = ip_route_connect(fl4, nexthop, inet->inet_saddr,
RT_CONN_FLAGS(sk), sk->sk_bound_dev_if,
IPPROTO_TCP,
orig_sport, orig_dport, sk, true);
if (IS_ERR(rt)) {
err = PTR_ERR(rt);
if (err == -ENETUNREACH)
IP_INC_STATS_BH(sock_net(sk), IPSTATS_MIB_OUTNOROUTES);
return err;
}
if (rt->rt_flags & (RTCF_MULTICAST | RTCF_BROADCAST)) {
ip_rt_put(rt);
return -ENETUNREACH;
}
if (!inet_opt || !inet_opt->opt.srr)
daddr = fl4->daddr;
if (!inet->inet_saddr)
inet->inet_saddr = fl4->saddr;
inet->inet_rcv_saddr = inet->inet_saddr;
if (tp->rx_opt.ts_recent_stamp && inet->inet_daddr != daddr) {
tp->rx_opt.ts_recent = 0;
tp->rx_opt.ts_recent_stamp = 0;
if (likely(!tp->repair))
tp->write_seq = 0;
}
if (tcp_death_row.sysctl_tw_recycle &&
!tp->rx_opt.ts_recent_stamp && fl4->daddr == daddr)
tcp_fetch_timewait_stamp(sk, &rt->dst);
inet->inet_dport = usin->sin_port;
inet->inet_daddr = daddr;
inet_csk(sk)->icsk_ext_hdr_len = 0;
if (inet_opt)
inet_csk(sk)->icsk_ext_hdr_len = inet_opt->opt.optlen;
tp->rx_opt.mss_clamp = TCP_MSS_DEFAULT;
tcp_set_state(sk, TCP_SYN_SENT);
err = inet_hash_connect(&tcp_death_row, sk);
if (err)
goto failure;
rt = ip_route_newports(fl4, rt, orig_sport, orig_dport,
inet->inet_sport, inet->inet_dport, sk);
if (IS_ERR(rt)) {
err = PTR_ERR(rt);
rt = NULL;
goto failure;
}
sk->sk_gso_type = SKB_GSO_TCPV4;
sk_setup_caps(sk, &rt->dst);
if (!tp->write_seq && likely(!tp->repair))
tp->write_seq = secure_tcp_sequence_number(inet->inet_saddr,
inet->inet_daddr,
inet->inet_sport,
usin->sin_port);
inet->inet_id = tp->write_seq ^ jiffies;
if (likely(!tp->repair))
err = tcp_connect(sk);
else
err = tcp_repair_connect(sk);
rt = NULL;
if (err)
goto failure;
return 0;
failure:
tcp_set_state(sk, TCP_CLOSE);
ip_rt_put(rt);
sk->sk_route_caps = 0;
inet->inet_dport = 0;
return err;
}
static void tcp_v4_mtu_reduced(struct sock *sk)
{
struct dst_entry *dst;
struct inet_sock *inet = inet_sk(sk);
u32 mtu = tcp_sk(sk)->mtu_info;
if (sk->sk_state == TCP_LISTEN)
return;
dst = inet_csk_update_pmtu(sk, mtu);
if (!dst)
return;
if (mtu < dst_mtu(dst) && ip_dont_fragment(sk, dst))
sk->sk_err_soft = EMSGSIZE;
mtu = dst_mtu(dst);
if (inet->pmtudisc != IP_PMTUDISC_DONT &&
inet_csk(sk)->icsk_pmtu_cookie > mtu) {
tcp_sync_mss(sk, mtu);
tcp_simple_retransmit(sk);
}
}
static void do_redirect(struct sk_buff *skb, struct sock *sk)
{
struct dst_entry *dst = __sk_dst_check(sk, 0);
if (dst)
dst->ops->redirect(dst, sk, skb);
}
void tcp_v4_err(struct sk_buff *icmp_skb, u32 info)
{
const struct iphdr *iph = (const struct iphdr *)icmp_skb->data;
struct tcphdr *th = (struct tcphdr *)(icmp_skb->data + (iph->ihl << 2));
struct inet_connection_sock *icsk;
struct tcp_sock *tp;
struct inet_sock *inet;
const int type = icmp_hdr(icmp_skb)->type;
const int code = icmp_hdr(icmp_skb)->code;
struct sock *sk;
struct sk_buff *skb;
struct request_sock *req;
__u32 seq;
__u32 remaining;
int err;
struct net *net = dev_net(icmp_skb->dev);
if (icmp_skb->len < (iph->ihl << 2) + 8) {
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
return;
}
sk = inet_lookup(net, &tcp_hashinfo, iph->daddr, th->dest,
iph->saddr, th->source, inet_iif(icmp_skb));
if (!sk) {
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
return;
}
if (sk->sk_state == TCP_TIME_WAIT) {
inet_twsk_put(inet_twsk(sk));
return;
}
bh_lock_sock(sk);
if (sock_owned_by_user(sk) &&
type != ICMP_DEST_UNREACH &&
code != ICMP_FRAG_NEEDED)
NET_INC_STATS_BH(net, LINUX_MIB_LOCKDROPPEDICMPS);
if (sk->sk_state == TCP_CLOSE)
goto out;
if (unlikely(iph->ttl < inet_sk(sk)->min_ttl)) {
NET_INC_STATS_BH(net, LINUX_MIB_TCPMINTTLDROP);
goto out;
}
icsk = inet_csk(sk);
tp = tcp_sk(sk);
req = tp->fastopen_rsk;
seq = ntohl(th->seq);
if (sk->sk_state != TCP_LISTEN &&
!between(seq, tp->snd_una, tp->snd_nxt) &&
(req == NULL || seq != tcp_rsk(req)->snt_isn)) {
NET_INC_STATS_BH(net, LINUX_MIB_OUTOFWINDOWICMPS);
goto out;
}
switch (type) {
case ICMP_REDIRECT:
do_redirect(icmp_skb, sk);
goto out;
case ICMP_SOURCE_QUENCH:
goto out;
case ICMP_PARAMETERPROB:
err = EPROTO;
break;
case ICMP_DEST_UNREACH:
if (code > NR_ICMP_UNREACH)
goto out;
if (code == ICMP_FRAG_NEEDED) {
tp->mtu_info = info;
if (!sock_owned_by_user(sk)) {
tcp_v4_mtu_reduced(sk);
} else {
if (!test_and_set_bit(TCP_MTU_REDUCED_DEFERRED, &tp->tsq_flags))
sock_hold(sk);
}
goto out;
}
err = icmp_err_convert[code].errno;
if (code != ICMP_NET_UNREACH && code != ICMP_HOST_UNREACH)
break;
if (seq != tp->snd_una || !icsk->icsk_retransmits ||
!icsk->icsk_backoff)
break;
if (sock_owned_by_user(sk))
break;
icsk->icsk_backoff--;
inet_csk(sk)->icsk_rto = (tp->srtt ? __tcp_set_rto(tp) :
TCP_TIMEOUT_INIT) << icsk->icsk_backoff;
tcp_bound_rto(sk);
skb = tcp_write_queue_head(sk);
BUG_ON(!skb);
remaining = icsk->icsk_rto - min(icsk->icsk_rto,
tcp_time_stamp - TCP_SKB_CB(skb)->when);
if (remaining) {
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
remaining, TCP_RTO_MAX);
} else {
tcp_retransmit_timer(sk);
}
break;
case ICMP_TIME_EXCEEDED:
err = EHOSTUNREACH;
break;
default:
goto out;
}
if (req && req->sk == NULL)
goto out;
switch (sk->sk_state) {
struct request_sock *req, **prev;
case TCP_LISTEN:
if (sock_owned_by_user(sk))
goto out;
req = inet_csk_search_req(sk, &prev, th->dest,
iph->daddr, iph->saddr);
if (!req)
goto out;
WARN_ON(req->sk);
if (seq != tcp_rsk(req)->snt_isn) {
NET_INC_STATS_BH(net, LINUX_MIB_OUTOFWINDOWICMPS);
goto out;
}
inet_csk_reqsk_queue_drop(sk, req, prev);
goto out;
case TCP_SYN_SENT:
case TCP_SYN_RECV:
if (!sock_owned_by_user(sk)) {
sk->sk_err = err;
sk->sk_error_report(sk);
tcp_done(sk);
} else {
sk->sk_err_soft = err;
}
goto out;
}
inet = inet_sk(sk);
if (!sock_owned_by_user(sk) && inet->recverr) {
sk->sk_err = err;
sk->sk_error_report(sk);
} else {
sk->sk_err_soft = err;
}
out:
bh_unlock_sock(sk);
sock_put(sk);
}
static void __tcp_v4_send_check(struct sk_buff *skb,
__be32 saddr, __be32 daddr)
{
struct tcphdr *th = tcp_hdr(skb);
if (skb->ip_summed == CHECKSUM_PARTIAL) {
th->check = ~tcp_v4_check(skb->len, saddr, daddr, 0);
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct tcphdr, check);
} else {
th->check = tcp_v4_check(skb->len, saddr, daddr,
csum_partial(th,
th->doff << 2,
skb->csum));
}
}
void tcp_v4_send_check(struct sock *sk, struct sk_buff *skb)
{
const struct inet_sock *inet = inet_sk(sk);
__tcp_v4_send_check(skb, inet->inet_saddr, inet->inet_daddr);
}
int tcp_v4_gso_send_check(struct sk_buff *skb)
{
const struct iphdr *iph;
struct tcphdr *th;
if (!pskb_may_pull(skb, sizeof(*th)))
return -EINVAL;
iph = ip_hdr(skb);
th = tcp_hdr(skb);
th->check = 0;
skb->ip_summed = CHECKSUM_PARTIAL;
__tcp_v4_send_check(skb, iph->saddr, iph->daddr);
return 0;
}
static void tcp_v4_send_reset(struct sock *sk, struct sk_buff *skb)
{
const struct tcphdr *th = tcp_hdr(skb);
struct {
struct tcphdr th;
#ifdef CONFIG_TCP_MD5SIG
__be32 opt[(TCPOLEN_MD5SIG_ALIGNED >> 2)];
#endif
} rep;
struct ip_reply_arg arg;
#ifdef CONFIG_TCP_MD5SIG
struct tcp_md5sig_key *key;
const __u8 *hash_location = NULL;
unsigned char newhash[16];
int genhash;
struct sock *sk1 = NULL;
#endif
struct net *net;
if (th->rst)
return;
if (skb_rtable(skb)->rt_type != RTN_LOCAL)
return;
memset(&rep, 0, sizeof(rep));
rep.th.dest = th->source;
rep.th.source = th->dest;
rep.th.doff = sizeof(struct tcphdr) / 4;
rep.th.rst = 1;
if (th->ack) {
rep.th.seq = th->ack_seq;
} else {
rep.th.ack = 1;
rep.th.ack_seq = htonl(ntohl(th->seq) + th->syn + th->fin +
skb->len - (th->doff << 2));
}
memset(&arg, 0, sizeof(arg));
arg.iov[0].iov_base = (unsigned char *)&rep;
arg.iov[0].iov_len = sizeof(rep.th);
#ifdef CONFIG_TCP_MD5SIG
hash_location = tcp_parse_md5sig_option(th);
if (!sk && hash_location) {
sk1 = __inet_lookup_listener(dev_net(skb_dst(skb)->dev),
&tcp_hashinfo, ip_hdr(skb)->daddr,
ntohs(th->source), inet_iif(skb));
if (!sk1)
return;
rcu_read_lock();
key = tcp_md5_do_lookup(sk1, (union tcp_md5_addr *)
&ip_hdr(skb)->saddr, AF_INET);
if (!key)
goto release_sk1;
genhash = tcp_v4_md5_hash_skb(newhash, key, NULL, NULL, skb);
if (genhash || memcmp(hash_location, newhash, 16) != 0)
goto release_sk1;
} else {
key = sk ? tcp_md5_do_lookup(sk, (union tcp_md5_addr *)
&ip_hdr(skb)->saddr,
AF_INET) : NULL;
}
if (key) {
rep.opt[0] = htonl((TCPOPT_NOP << 24) |
(TCPOPT_NOP << 16) |
(TCPOPT_MD5SIG << 8) |
TCPOLEN_MD5SIG);
arg.iov[0].iov_len += TCPOLEN_MD5SIG_ALIGNED;
rep.th.doff = arg.iov[0].iov_len / 4;
tcp_v4_md5_hash_hdr((__u8 *) &rep.opt[1],
key, ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, &rep.th);
}
#endif
arg.csum = csum_tcpudp_nofold(ip_hdr(skb)->daddr,
ip_hdr(skb)->saddr,
arg.iov[0].iov_len, IPPROTO_TCP, 0);
arg.csumoffset = offsetof(struct tcphdr, check) / 2;
arg.flags = (sk && inet_sk(sk)->transparent) ? IP_REPLY_ARG_NOSRCCHECK : 0;
if (sk)
arg.bound_dev_if = sk->sk_bound_dev_if;
net = dev_net(skb_dst(skb)->dev);
arg.tos = ip_hdr(skb)->tos;
ip_send_unicast_reply(net, skb, ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, &arg, arg.iov[0].iov_len);
TCP_INC_STATS_BH(net, TCP_MIB_OUTSEGS);
TCP_INC_STATS_BH(net, TCP_MIB_OUTRSTS);
#ifdef CONFIG_TCP_MD5SIG
release_sk1:
if (sk1) {
rcu_read_unlock();
sock_put(sk1);
}
#endif
}
static void tcp_v4_send_ack(struct sk_buff *skb, u32 seq, u32 ack,
u32 win, u32 ts, int oif,
struct tcp_md5sig_key *key,
int reply_flags, u8 tos)
{
const struct tcphdr *th = tcp_hdr(skb);
struct {
struct tcphdr th;
__be32 opt[(TCPOLEN_TSTAMP_ALIGNED >> 2)
#ifdef CONFIG_TCP_MD5SIG
+ (TCPOLEN_MD5SIG_ALIGNED >> 2)
#endif
];
} rep;
struct ip_reply_arg arg;
struct net *net = dev_net(skb_dst(skb)->dev);
memset(&rep.th, 0, sizeof(struct tcphdr));
memset(&arg, 0, sizeof(arg));
arg.iov[0].iov_base = (unsigned char *)&rep;
arg.iov[0].iov_len = sizeof(rep.th);
if (ts) {
rep.opt[0] = htonl((TCPOPT_NOP << 24) | (TCPOPT_NOP << 16) |
(TCPOPT_TIMESTAMP << 8) |
TCPOLEN_TIMESTAMP);
rep.opt[1] = htonl(tcp_time_stamp);
rep.opt[2] = htonl(ts);
arg.iov[0].iov_len += TCPOLEN_TSTAMP_ALIGNED;
}
rep.th.dest = th->source;
rep.th.source = th->dest;
rep.th.doff = arg.iov[0].iov_len / 4;
rep.th.seq = htonl(seq);
rep.th.ack_seq = htonl(ack);
rep.th.ack = 1;
rep.th.window = htons(win);
#ifdef CONFIG_TCP_MD5SIG
if (key) {
int offset = (ts) ? 3 : 0;
rep.opt[offset++] = htonl((TCPOPT_NOP << 24) |
(TCPOPT_NOP << 16) |
(TCPOPT_MD5SIG << 8) |
TCPOLEN_MD5SIG);
arg.iov[0].iov_len += TCPOLEN_MD5SIG_ALIGNED;
rep.th.doff = arg.iov[0].iov_len/4;
tcp_v4_md5_hash_hdr((__u8 *) &rep.opt[offset],
key, ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, &rep.th);
}
#endif
arg.flags = reply_flags;
arg.csum = csum_tcpudp_nofold(ip_hdr(skb)->daddr,
ip_hdr(skb)->saddr,
arg.iov[0].iov_len, IPPROTO_TCP, 0);
arg.csumoffset = offsetof(struct tcphdr, check) / 2;
if (oif)
arg.bound_dev_if = oif;
arg.tos = tos;
ip_send_unicast_reply(net, skb, ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, &arg, arg.iov[0].iov_len);
TCP_INC_STATS_BH(net, TCP_MIB_OUTSEGS);
}
static void tcp_v4_timewait_ack(struct sock *sk, struct sk_buff *skb)
{
struct inet_timewait_sock *tw = inet_twsk(sk);
struct tcp_timewait_sock *tcptw = tcp_twsk(sk);
tcp_v4_send_ack(skb, tcptw->tw_snd_nxt, tcptw->tw_rcv_nxt,
tcptw->tw_rcv_wnd >> tw->tw_rcv_wscale,
tcptw->tw_ts_recent,
tw->tw_bound_dev_if,
tcp_twsk_md5_key(tcptw),
tw->tw_transparent ? IP_REPLY_ARG_NOSRCCHECK : 0,
tw->tw_tos
);
inet_twsk_put(tw);
}
static void tcp_v4_reqsk_send_ack(struct sock *sk, struct sk_buff *skb,
struct request_sock *req)
{
tcp_v4_send_ack(skb, (sk->sk_state == TCP_LISTEN) ?
tcp_rsk(req)->snt_isn + 1 : tcp_sk(sk)->snd_nxt,
tcp_rsk(req)->rcv_nxt, req->rcv_wnd,
req->ts_recent,
0,
tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&ip_hdr(skb)->daddr,
AF_INET),
inet_rsk(req)->no_srccheck ? IP_REPLY_ARG_NOSRCCHECK : 0,
ip_hdr(skb)->tos);
}
static int tcp_v4_send_synack(struct sock *sk, struct dst_entry *dst,
struct request_sock *req,
struct request_values *rvp,
u16 queue_mapping,
bool nocache)
{
const struct inet_request_sock *ireq = inet_rsk(req);
struct flowi4 fl4;
int err = -1;
struct sk_buff * skb;
if (!dst && (dst = inet_csk_route_req(sk, &fl4, req)) == NULL)
return -1;
skb = tcp_make_synack(sk, dst, req, rvp, NULL);
if (skb) {
__tcp_v4_send_check(skb, ireq->loc_addr, ireq->rmt_addr);
skb_set_queue_mapping(skb, queue_mapping);
err = ip_build_and_send_pkt(skb, sk, ireq->loc_addr,
ireq->rmt_addr,
ireq->opt);
err = net_xmit_eval(err);
if (!tcp_rsk(req)->snt_synack && !err)
tcp_rsk(req)->snt_synack = tcp_time_stamp;
}
return err;
}
static int tcp_v4_rtx_synack(struct sock *sk, struct request_sock *req,
struct request_values *rvp)
{
TCP_INC_STATS_BH(sock_net(sk), TCP_MIB_RETRANSSEGS);
return tcp_v4_send_synack(sk, NULL, req, rvp, 0, false);
}
static void tcp_v4_reqsk_destructor(struct request_sock *req)
{
kfree(inet_rsk(req)->opt);
}
bool tcp_syn_flood_action(struct sock *sk,
const struct sk_buff *skb,
const char *proto)
{
const char *msg = "Dropping request";
bool want_cookie = false;
struct listen_sock *lopt;
#ifdef CONFIG_SYN_COOKIES
if (sysctl_tcp_syncookies) {
msg = "Sending cookies";
want_cookie = true;
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPREQQFULLDOCOOKIES);
} else
#endif
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPREQQFULLDROP);
lopt = inet_csk(sk)->icsk_accept_queue.listen_opt;
if (!lopt->synflood_warned) {
lopt->synflood_warned = 1;
pr_info("%s: Possible SYN flooding on port %d. %s. Check SNMP counters.\n",
proto, ntohs(tcp_hdr(skb)->dest), msg);
}
return want_cookie;
}
static struct ip_options_rcu *tcp_v4_save_options(struct sk_buff *skb)
{
const struct ip_options *opt = &(IPCB(skb)->opt);
struct ip_options_rcu *dopt = NULL;
if (opt && opt->optlen) {
int opt_size = sizeof(*dopt) + opt->optlen;
dopt = kmalloc(opt_size, GFP_ATOMIC);
if (dopt) {
if (ip_options_echo(&dopt->opt, skb)) {
kfree(dopt);
dopt = NULL;
}
}
}
return dopt;
}
struct tcp_md5sig_key *tcp_md5_do_lookup(struct sock *sk,
const union tcp_md5_addr *addr,
int family)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_md5sig_key *key;
struct hlist_node *pos;
unsigned int size = sizeof(struct in_addr);
struct tcp_md5sig_info *md5sig;
md5sig = rcu_dereference_check(tp->md5sig_info,
sock_owned_by_user(sk) ||
lockdep_is_held(&sk->sk_lock.slock));
if (!md5sig)
return NULL;
#if IS_ENABLED(CONFIG_IPV6)
if (family == AF_INET6)
size = sizeof(struct in6_addr);
#endif
hlist_for_each_entry_rcu(key, pos, &md5sig->head, node) {
if (key->family != family)
continue;
if (!memcmp(&key->addr, addr, size))
return key;
}
return NULL;
}
struct tcp_md5sig_key *tcp_v4_md5_lookup(struct sock *sk,
struct sock *addr_sk)
{
union tcp_md5_addr *addr;
addr = (union tcp_md5_addr *)&inet_sk(addr_sk)->inet_daddr;
return tcp_md5_do_lookup(sk, addr, AF_INET);
}
static struct tcp_md5sig_key *tcp_v4_reqsk_md5_lookup(struct sock *sk,
struct request_sock *req)
{
union tcp_md5_addr *addr;
addr = (union tcp_md5_addr *)&inet_rsk(req)->rmt_addr;
return tcp_md5_do_lookup(sk, addr, AF_INET);
}
int tcp_md5_do_add(struct sock *sk, const union tcp_md5_addr *addr,
int family, const u8 *newkey, u8 newkeylen, gfp_t gfp)
{
struct tcp_md5sig_key *key;
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_md5sig_info *md5sig;
key = tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&addr, AF_INET);
if (key) {
memcpy(key->key, newkey, newkeylen);
key->keylen = newkeylen;
return 0;
}
md5sig = rcu_dereference_protected(tp->md5sig_info,
sock_owned_by_user(sk));
if (!md5sig) {
md5sig = kmalloc(sizeof(*md5sig), gfp);
if (!md5sig)
return -ENOMEM;
sk_nocaps_add(sk, NETIF_F_GSO_MASK);
INIT_HLIST_HEAD(&md5sig->head);
rcu_assign_pointer(tp->md5sig_info, md5sig);
}
key = sock_kmalloc(sk, sizeof(*key), gfp);
if (!key)
return -ENOMEM;
if (hlist_empty(&md5sig->head) && !tcp_alloc_md5sig_pool(sk)) {
sock_kfree_s(sk, key, sizeof(*key));
return -ENOMEM;
}
memcpy(key->key, newkey, newkeylen);
key->keylen = newkeylen;
key->family = family;
memcpy(&key->addr, addr,
(family == AF_INET6) ? sizeof(struct in6_addr) :
sizeof(struct in_addr));
hlist_add_head_rcu(&key->node, &md5sig->head);
return 0;
}
int tcp_md5_do_del(struct sock *sk, const union tcp_md5_addr *addr, int family)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_md5sig_key *key;
struct tcp_md5sig_info *md5sig;
key = tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&addr, AF_INET);
if (!key)
return -ENOENT;
hlist_del_rcu(&key->node);
atomic_sub(sizeof(*key), &sk->sk_omem_alloc);
kfree_rcu(key, rcu);
md5sig = rcu_dereference_protected(tp->md5sig_info,
sock_owned_by_user(sk));
if (hlist_empty(&md5sig->head))
tcp_free_md5sig_pool();
return 0;
}
void tcp_clear_md5_list(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_md5sig_key *key;
struct hlist_node *pos, *n;
struct tcp_md5sig_info *md5sig;
md5sig = rcu_dereference_protected(tp->md5sig_info, 1);
if (!hlist_empty(&md5sig->head))
tcp_free_md5sig_pool();
hlist_for_each_entry_safe(key, pos, n, &md5sig->head, node) {
hlist_del_rcu(&key->node);
atomic_sub(sizeof(*key), &sk->sk_omem_alloc);
kfree_rcu(key, rcu);
}
}
static int tcp_v4_parse_md5_keys(struct sock *sk, char __user *optval,
int optlen)
{
struct tcp_md5sig cmd;
struct sockaddr_in *sin = (struct sockaddr_in *)&cmd.tcpm_addr;
if (optlen < sizeof(cmd))
return -EINVAL;
if (copy_from_user(&cmd, optval, sizeof(cmd)))
return -EFAULT;
if (sin->sin_family != AF_INET)
return -EINVAL;
if (!cmd.tcpm_key || !cmd.tcpm_keylen)
return tcp_md5_do_del(sk, (union tcp_md5_addr *)&sin->sin_addr.s_addr,
AF_INET);
if (cmd.tcpm_keylen > TCP_MD5SIG_MAXKEYLEN)
return -EINVAL;
return tcp_md5_do_add(sk, (union tcp_md5_addr *)&sin->sin_addr.s_addr,
AF_INET, cmd.tcpm_key, cmd.tcpm_keylen,
GFP_KERNEL);
}
static int tcp_v4_md5_hash_pseudoheader(struct tcp_md5sig_pool *hp,
__be32 daddr, __be32 saddr, int nbytes)
{
struct tcp4_pseudohdr *bp;
struct scatterlist sg;
bp = &hp->md5_blk.ip4;
bp->saddr = saddr;
bp->daddr = daddr;
bp->pad = 0;
bp->protocol = IPPROTO_TCP;
bp->len = cpu_to_be16(nbytes);
sg_init_one(&sg, bp, sizeof(*bp));
return crypto_hash_update(&hp->md5_desc, &sg, sizeof(*bp));
}
static int tcp_v4_md5_hash_hdr(char *md5_hash, const struct tcp_md5sig_key *key,
__be32 daddr, __be32 saddr, const struct tcphdr *th)
{
struct tcp_md5sig_pool *hp;
struct hash_desc *desc;
hp = tcp_get_md5sig_pool();
if (!hp)
goto clear_hash_noput;
desc = &hp->md5_desc;
if (crypto_hash_init(desc))
goto clear_hash;
if (tcp_v4_md5_hash_pseudoheader(hp, daddr, saddr, th->doff << 2))
goto clear_hash;
if (tcp_md5_hash_header(hp, th))
goto clear_hash;
if (tcp_md5_hash_key(hp, key))
goto clear_hash;
if (crypto_hash_final(desc, md5_hash))
goto clear_hash;
tcp_put_md5sig_pool();
return 0;
clear_hash:
tcp_put_md5sig_pool();
clear_hash_noput:
memset(md5_hash, 0, 16);
return 1;
}
int tcp_v4_md5_hash_skb(char *md5_hash, struct tcp_md5sig_key *key,
const struct sock *sk, const struct request_sock *req,
const struct sk_buff *skb)
{
struct tcp_md5sig_pool *hp;
struct hash_desc *desc;
const struct tcphdr *th = tcp_hdr(skb);
__be32 saddr, daddr;
if (sk) {
saddr = inet_sk(sk)->inet_saddr;
daddr = inet_sk(sk)->inet_daddr;
} else if (req) {
saddr = inet_rsk(req)->loc_addr;
daddr = inet_rsk(req)->rmt_addr;
} else {
const struct iphdr *iph = ip_hdr(skb);
saddr = iph->saddr;
daddr = iph->daddr;
}
hp = tcp_get_md5sig_pool();
if (!hp)
goto clear_hash_noput;
desc = &hp->md5_desc;
if (crypto_hash_init(desc))
goto clear_hash;
if (tcp_v4_md5_hash_pseudoheader(hp, daddr, saddr, skb->len))
goto clear_hash;
if (tcp_md5_hash_header(hp, th))
goto clear_hash;
if (tcp_md5_hash_skb_data(hp, skb, th->doff << 2))
goto clear_hash;
if (tcp_md5_hash_key(hp, key))
goto clear_hash;
if (crypto_hash_final(desc, md5_hash))
goto clear_hash;
tcp_put_md5sig_pool();
return 0;
clear_hash:
tcp_put_md5sig_pool();
clear_hash_noput:
memset(md5_hash, 0, 16);
return 1;
}
static bool tcp_v4_inbound_md5_hash(struct sock *sk, const struct sk_buff *skb)
{
const __u8 *hash_location = NULL;
struct tcp_md5sig_key *hash_expected;
const struct iphdr *iph = ip_hdr(skb);
const struct tcphdr *th = tcp_hdr(skb);
int genhash;
unsigned char newhash[16];
hash_expected = tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&iph->saddr,
AF_INET);
hash_location = tcp_parse_md5sig_option(th);
if (!hash_expected && !hash_location)
return false;
if (hash_expected && !hash_location) {
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPMD5NOTFOUND);
return true;
}
if (!hash_expected && hash_location) {
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPMD5UNEXPECTED);
return true;
}
genhash = tcp_v4_md5_hash_skb(newhash,
hash_expected,
NULL, NULL, skb);
if (genhash || memcmp(hash_location, newhash, 16) != 0) {
net_info_ratelimited("MD5 Hash failed for (%pI4, %d)->(%pI4, %d)%s\n",
&iph->saddr, ntohs(th->source),
&iph->daddr, ntohs(th->dest),
genhash ? " tcp_v4_calc_md5_hash failed"
: "");
return true;
}
return false;
}
static bool tcp_fastopen_check(struct sock *sk, struct sk_buff *skb,
struct request_sock *req,
struct tcp_fastopen_cookie *foc,
struct tcp_fastopen_cookie *valid_foc)
{
bool skip_cookie = false;
struct fastopen_queue *fastopenq;
if (likely(!fastopen_cookie_present(foc))) {
if ((sysctl_tcp_fastopen & TFO_SERVER_ALWAYS) ||
((sysctl_tcp_fastopen & TFO_SERVER_COOKIE_NOT_REQD) &&
(TCP_SKB_CB(skb)->end_seq != TCP_SKB_CB(skb)->seq + 1)))
skip_cookie = true;
else
return false;
}
fastopenq = inet_csk(sk)->icsk_accept_queue.fastopenq;
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_TCPFASTOPENPASSIVE);
if ((sysctl_tcp_fastopen & TFO_SERVER_ENABLE) == 0 ||
fastopenq == NULL || fastopenq->max_qlen == 0)
return false;
if (fastopenq->qlen >= fastopenq->max_qlen) {
struct request_sock *req1;
spin_lock(&fastopenq->lock);
req1 = fastopenq->rskq_rst_head;
if ((req1 == NULL) || time_after(req1->expires, jiffies)) {
spin_unlock(&fastopenq->lock);
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPFASTOPENLISTENOVERFLOW);
foc->len = -1;
return false;
}
fastopenq->rskq_rst_head = req1->dl_next;
fastopenq->qlen--;
spin_unlock(&fastopenq->lock);
reqsk_free(req1);
}
if (skip_cookie) {
tcp_rsk(req)->rcv_nxt = TCP_SKB_CB(skb)->end_seq;
return true;
}
if (foc->len == TCP_FASTOPEN_COOKIE_SIZE) {
if ((sysctl_tcp_fastopen & TFO_SERVER_COOKIE_NOT_CHKED) == 0) {
tcp_fastopen_cookie_gen(ip_hdr(skb)->saddr, valid_foc);
if ((valid_foc->len != TCP_FASTOPEN_COOKIE_SIZE) ||
memcmp(&foc->val[0], &valid_foc->val[0],
TCP_FASTOPEN_COOKIE_SIZE) != 0)
return false;
valid_foc->len = -1;
}
tcp_rsk(req)->rcv_nxt = TCP_SKB_CB(skb)->end_seq;
return true;
} else if (foc->len == 0) {
tcp_fastopen_cookie_gen(ip_hdr(skb)->saddr, valid_foc);
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPFASTOPENCOOKIEREQD);
} else {
tcp_fastopen_cookie_gen(ip_hdr(skb)->saddr, valid_foc);
}
return false;
}
static int tcp_v4_conn_req_fastopen(struct sock *sk,
struct sk_buff *skb,
struct sk_buff *skb_synack,
struct request_sock *req,
struct request_values *rvp)
{
struct tcp_sock *tp = tcp_sk(sk);
struct request_sock_queue *queue = &inet_csk(sk)->icsk_accept_queue;
const struct inet_request_sock *ireq = inet_rsk(req);
struct sock *child;
int err;
req->retrans = 0;
req->sk = NULL;
child = inet_csk(sk)->icsk_af_ops->syn_recv_sock(sk, skb, req, NULL);
if (child == NULL) {
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPFASTOPENPASSIVEFAIL);
kfree_skb(skb_synack);
return -1;
}
err = ip_build_and_send_pkt(skb_synack, sk, ireq->loc_addr,
ireq->rmt_addr, ireq->opt);
err = net_xmit_eval(err);
if (!err)
tcp_rsk(req)->snt_synack = tcp_time_stamp;
spin_lock(&queue->fastopenq->lock);
queue->fastopenq->qlen++;
spin_unlock(&queue->fastopenq->lock);
tp = tcp_sk(child);
tp->fastopen_rsk = req;
sock_hold(sk);
tcp_rsk(req)->listener = sk;
tp->snd_wnd = ntohs(tcp_hdr(skb)->window);
inet_csk_reset_xmit_timer(child, ICSK_TIME_RETRANS,
TCP_TIMEOUT_INIT, TCP_RTO_MAX);
inet_csk_reqsk_queue_add(sk, req, child);
inet_csk(child)->icsk_af_ops->rebuild_header(child);
tcp_init_congestion_control(child);
tcp_mtup_init(child);
tcp_init_buffer_space(child);
tcp_init_metrics(child);
if (TCP_SKB_CB(skb)->end_seq == TCP_SKB_CB(skb)->seq + 1) {
tp->rcv_nxt = TCP_SKB_CB(skb)->end_seq;
} else {
skb = skb_get(skb);
skb_dst_drop(skb);
__skb_pull(skb, tcp_hdr(skb)->doff * 4);
skb_set_owner_r(skb, child);
__skb_queue_tail(&child->sk_receive_queue, skb);
tp->rcv_nxt = TCP_SKB_CB(skb)->end_seq;
tp->syn_data_acked = 1;
}
sk->sk_data_ready(sk, 0);
bh_unlock_sock(child);
sock_put(child);
WARN_ON(req->sk == NULL);
return 0;
}
int tcp_v4_conn_request(struct sock *sk, struct sk_buff *skb)
{
struct tcp_extend_values tmp_ext;
struct tcp_options_received tmp_opt;
const u8 *hash_location;
struct request_sock *req;
struct inet_request_sock *ireq;
struct tcp_sock *tp = tcp_sk(sk);
struct dst_entry *dst = NULL;
__be32 saddr = ip_hdr(skb)->saddr;
__be32 daddr = ip_hdr(skb)->daddr;
__u32 isn = TCP_SKB_CB(skb)->when;
bool want_cookie = false;
struct flowi4 fl4;
struct tcp_fastopen_cookie foc = { .len = -1 };
struct tcp_fastopen_cookie valid_foc = { .len = -1 };
struct sk_buff *skb_synack;
int do_fastopen;
if (skb_rtable(skb)->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST))
goto drop;
if (inet_csk_reqsk_queue_is_full(sk) && !isn) {
want_cookie = tcp_syn_flood_action(sk, skb, "TCP");
if (!want_cookie)
goto drop;
}
if (sk_acceptq_is_full(sk) && inet_csk_reqsk_queue_young(sk) > 1)
goto drop;
req = inet_reqsk_alloc(&tcp_request_sock_ops);
if (!req)
goto drop;
#ifdef CONFIG_TCP_MD5SIG
tcp_rsk(req)->af_specific = &tcp_request_sock_ipv4_ops;
#endif
tcp_clear_options(&tmp_opt);
tmp_opt.mss_clamp = TCP_MSS_DEFAULT;
tmp_opt.user_mss = tp->rx_opt.user_mss;
tcp_parse_options(skb, &tmp_opt, &hash_location, 0,
want_cookie ? NULL : &foc);
if (tmp_opt.cookie_plus > 0 &&
tmp_opt.saw_tstamp &&
!tp->rx_opt.cookie_out_never &&
(sysctl_tcp_cookie_size > 0 ||
(tp->cookie_values != NULL &&
tp->cookie_values->cookie_desired > 0))) {
u8 *c;
u32 *mess = &tmp_ext.cookie_bakery[COOKIE_DIGEST_WORDS];
int l = tmp_opt.cookie_plus - TCPOLEN_COOKIE_BASE;
if (tcp_cookie_generator(&tmp_ext.cookie_bakery[0]) != 0)
goto drop_and_release;
*mess++ ^= (__force u32)daddr;
*mess++ ^= (__force u32)saddr;
c = (u8 *)mess;
while (l-- > 0)
*c++ ^= *hash_location++;
want_cookie = false;
tmp_ext.cookie_out_never = 0;
tmp_ext.cookie_plus = tmp_opt.cookie_plus;
} else if (!tp->rx_opt.cookie_in_always) {
tmp_ext.cookie_out_never = 1;
tmp_ext.cookie_plus = 0;
} else {
goto drop_and_release;
}
tmp_ext.cookie_in_always = tp->rx_opt.cookie_in_always;
if (want_cookie && !tmp_opt.saw_tstamp)
tcp_clear_options(&tmp_opt);
tmp_opt.tstamp_ok = tmp_opt.saw_tstamp;
tcp_openreq_init(req, &tmp_opt, skb);
ireq = inet_rsk(req);
ireq->loc_addr = daddr;
ireq->rmt_addr = saddr;
ireq->no_srccheck = inet_sk(sk)->transparent;
ireq->opt = tcp_v4_save_options(skb);
if (security_inet_conn_request(sk, skb, req))
goto drop_and_free;
if (!want_cookie || tmp_opt.tstamp_ok)
TCP_ECN_create_request(req, skb);
if (want_cookie) {
isn = cookie_v4_init_sequence(sk, skb, &req->mss);
req->cookie_ts = tmp_opt.tstamp_ok;
} else if (!isn) {
if (tmp_opt.saw_tstamp &&
tcp_death_row.sysctl_tw_recycle &&
(dst = inet_csk_route_req(sk, &fl4, req)) != NULL &&
fl4.daddr == saddr) {
if (!tcp_peer_is_proven(req, dst, true)) {
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_PAWSPASSIVEREJECTED);
goto drop_and_release;
}
}
else if (!sysctl_tcp_syncookies &&
(sysctl_max_syn_backlog - inet_csk_reqsk_queue_len(sk) <
(sysctl_max_syn_backlog >> 2)) &&
!tcp_peer_is_proven(req, dst, false)) {
LIMIT_NETDEBUG(KERN_DEBUG pr_fmt("drop open request from %pI4/%u\n"),
&saddr, ntohs(tcp_hdr(skb)->source));
goto drop_and_release;
}
isn = tcp_v4_init_sequence(skb);
}
tcp_rsk(req)->snt_isn = isn;
if (dst == NULL) {
dst = inet_csk_route_req(sk, &fl4, req);
if (dst == NULL)
goto drop_and_free;
}
do_fastopen = tcp_fastopen_check(sk, skb, req, &foc, &valid_foc);
skb_synack = tcp_make_synack(sk, dst, req,
(struct request_values *)&tmp_ext,
fastopen_cookie_present(&valid_foc) ? &valid_foc : NULL);
if (skb_synack) {
__tcp_v4_send_check(skb_synack, ireq->loc_addr, ireq->rmt_addr);
skb_set_queue_mapping(skb_synack, skb_get_queue_mapping(skb));
} else
goto drop_and_free;
if (likely(!do_fastopen)) {
int err;
err = ip_build_and_send_pkt(skb_synack, sk, ireq->loc_addr,
ireq->rmt_addr, ireq->opt);
err = net_xmit_eval(err);
if (err || want_cookie)
goto drop_and_free;
tcp_rsk(req)->snt_synack = tcp_time_stamp;
tcp_rsk(req)->listener = NULL;
inet_csk_reqsk_queue_hash_add(sk, req, TCP_TIMEOUT_INIT);
if (fastopen_cookie_present(&foc) && foc.len != 0)
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPFASTOPENPASSIVEFAIL);
} else if (tcp_v4_conn_req_fastopen(sk, skb, skb_synack, req,
(struct request_values *)&tmp_ext))
goto drop_and_free;
return 0;
drop_and_release:
dst_release(dst);
drop_and_free:
reqsk_free(req);
drop:
return 0;
}
struct sock *tcp_v4_syn_recv_sock(struct sock *sk, struct sk_buff *skb,
struct request_sock *req,
struct dst_entry *dst)
{
struct inet_request_sock *ireq;
struct inet_sock *newinet;
struct tcp_sock *newtp;
struct sock *newsk;
#ifdef CONFIG_TCP_MD5SIG
struct tcp_md5sig_key *key;
#endif
struct ip_options_rcu *inet_opt;
if (sk_acceptq_is_full(sk))
goto exit_overflow;
newsk = tcp_create_openreq_child(sk, req, skb);
if (!newsk)
goto exit_nonewsk;
newsk->sk_gso_type = SKB_GSO_TCPV4;
inet_sk_rx_dst_set(newsk, skb);
newtp = tcp_sk(newsk);
newinet = inet_sk(newsk);
ireq = inet_rsk(req);
newinet->inet_daddr = ireq->rmt_addr;
newinet->inet_rcv_saddr = ireq->loc_addr;
newinet->inet_saddr = ireq->loc_addr;
inet_opt = ireq->opt;
rcu_assign_pointer(newinet->inet_opt, inet_opt);
ireq->opt = NULL;
newinet->mc_index = inet_iif(skb);
newinet->mc_ttl = ip_hdr(skb)->ttl;
newinet->rcv_tos = ip_hdr(skb)->tos;
inet_csk(newsk)->icsk_ext_hdr_len = 0;
if (inet_opt)
inet_csk(newsk)->icsk_ext_hdr_len = inet_opt->opt.optlen;
newinet->inet_id = newtp->write_seq ^ jiffies;
if (!dst) {
dst = inet_csk_route_child_sock(sk, newsk, req);
if (!dst)
goto put_and_exit;
} else {
}
sk_setup_caps(newsk, dst);
tcp_mtup_init(newsk);
tcp_sync_mss(newsk, dst_mtu(dst));
newtp->advmss = dst_metric_advmss(dst);
if (tcp_sk(sk)->rx_opt.user_mss &&
tcp_sk(sk)->rx_opt.user_mss < newtp->advmss)
newtp->advmss = tcp_sk(sk)->rx_opt.user_mss;
tcp_initialize_rcv_mss(newsk);
tcp_synack_rtt_meas(newsk, req);
newtp->total_retrans = req->retrans;
#ifdef CONFIG_TCP_MD5SIG
key = tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&newinet->inet_daddr,
AF_INET);
if (key != NULL) {
tcp_md5_do_add(newsk, (union tcp_md5_addr *)&newinet->inet_daddr,
AF_INET, key->key, key->keylen, GFP_ATOMIC);
sk_nocaps_add(newsk, NETIF_F_GSO_MASK);
}
#endif
if (__inet_inherit_port(sk, newsk) < 0)
goto put_and_exit;
__inet_hash_nolisten(newsk, NULL);
return newsk;
exit_overflow:
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_LISTENOVERFLOWS);
exit_nonewsk:
dst_release(dst);
exit:
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_LISTENDROPS);
return NULL;
put_and_exit:
tcp_clear_xmit_timers(newsk);
tcp_cleanup_congestion_control(newsk);
bh_unlock_sock(newsk);
sock_put(newsk);
goto exit;
}
static struct sock *tcp_v4_hnd_req(struct sock *sk, struct sk_buff *skb)
{
struct tcphdr *th = tcp_hdr(skb);
const struct iphdr *iph = ip_hdr(skb);
struct sock *nsk;
struct request_sock **prev;
struct request_sock *req = inet_csk_search_req(sk, &prev, th->source,
iph->saddr, iph->daddr);
if (req)
return tcp_check_req(sk, skb, req, prev, false);
nsk = inet_lookup_established(sock_net(sk), &tcp_hashinfo, iph->saddr,
th->source, iph->daddr, th->dest, inet_iif(skb));
if (nsk) {
if (nsk->sk_state != TCP_TIME_WAIT) {
bh_lock_sock(nsk);
return nsk;
}
inet_twsk_put(inet_twsk(nsk));
return NULL;
}
#ifdef CONFIG_SYN_COOKIES
if (!th->syn)
sk = cookie_v4_check(sk, skb, &(IPCB(skb)->opt));
#endif
return sk;
}
static __sum16 tcp_v4_checksum_init(struct sk_buff *skb)
{
const struct iphdr *iph = ip_hdr(skb);
if (skb->ip_summed == CHECKSUM_COMPLETE) {
if (!tcp_v4_check(skb->len, iph->saddr,
iph->daddr, skb->csum)) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
return 0;
}
}
skb->csum = csum_tcpudp_nofold(iph->saddr, iph->daddr,
skb->len, IPPROTO_TCP, 0);
if (skb->len <= 76) {
return __skb_checksum_complete(skb);
}
return 0;
}
int tcp_v4_do_rcv(struct sock *sk, struct sk_buff *skb)
{
struct sock *rsk;
#ifdef CONFIG_TCP_MD5SIG
if (tcp_v4_inbound_md5_hash(sk, skb))
goto discard;
#endif
if (sk->sk_state == TCP_ESTABLISHED) {
struct dst_entry *dst = sk->sk_rx_dst;
sock_rps_save_rxhash(sk, skb);
if (dst) {
if (inet_sk(sk)->rx_dst_ifindex != skb->skb_iif ||
dst->ops->check(dst, 0) == NULL) {
dst_release(dst);
sk->sk_rx_dst = NULL;
}
}
if (tcp_rcv_established(sk, skb, tcp_hdr(skb), skb->len)) {
rsk = sk;
goto reset;
}
return 0;
}
if (skb->len < tcp_hdrlen(skb) || tcp_checksum_complete(skb))
goto csum_err;
if (sk->sk_state == TCP_LISTEN) {
struct sock *nsk = tcp_v4_hnd_req(sk, skb);
if (!nsk)
goto discard;
if (nsk != sk) {
sock_rps_save_rxhash(nsk, skb);
if (tcp_child_process(sk, nsk, skb)) {
rsk = nsk;
goto reset;
}
return 0;
}
} else
sock_rps_save_rxhash(sk, skb);
if (tcp_rcv_state_process(sk, skb, tcp_hdr(skb), skb->len)) {
rsk = sk;
goto reset;
}
return 0;
reset:
tcp_v4_send_reset(rsk, skb);
discard:
kfree_skb(skb);
return 0;
csum_err:
TCP_INC_STATS_BH(sock_net(sk), TCP_MIB_INERRS);
goto discard;
}
void tcp_v4_early_demux(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
const struct iphdr *iph;
const struct tcphdr *th;
struct sock *sk;
if (skb->pkt_type != PACKET_HOST)
return;
if (!pskb_may_pull(skb, ip_hdrlen(skb) + sizeof(struct tcphdr)))
return;
iph = ip_hdr(skb);
th = (struct tcphdr *) ((char *)iph + ip_hdrlen(skb));
if (th->doff < sizeof(struct tcphdr) / 4)
return;
sk = __inet_lookup_established(net, &tcp_hashinfo,
iph->saddr, th->source,
iph->daddr, ntohs(th->dest),
skb->skb_iif);
if (sk) {
skb->sk = sk;
skb->destructor = sock_edemux;
if (sk->sk_state != TCP_TIME_WAIT) {
struct dst_entry *dst = sk->sk_rx_dst;
if (dst)
dst = dst_check(dst, 0);
if (dst &&
inet_sk(sk)->rx_dst_ifindex == skb->skb_iif)
skb_dst_set_noref(skb, dst);
}
}
}
int tcp_v4_rcv(struct sk_buff *skb)
{
const struct iphdr *iph;
const struct tcphdr *th;
struct sock *sk;
int ret;
struct net *net = dev_net(skb->dev);
if (skb->pkt_type != PACKET_HOST)
goto discard_it;
TCP_INC_STATS_BH(net, TCP_MIB_INSEGS);
if (!pskb_may_pull(skb, sizeof(struct tcphdr)))
goto discard_it;
th = tcp_hdr(skb);
if (th->doff < sizeof(struct tcphdr) / 4)
goto bad_packet;
if (!pskb_may_pull(skb, th->doff * 4))
goto discard_it;
if (!skb_csum_unnecessary(skb) && tcp_v4_checksum_init(skb))
goto bad_packet;
th = tcp_hdr(skb);
iph = ip_hdr(skb);
TCP_SKB_CB(skb)->seq = ntohl(th->seq);
TCP_SKB_CB(skb)->end_seq = (TCP_SKB_CB(skb)->seq + th->syn + th->fin +
skb->len - th->doff * 4);
TCP_SKB_CB(skb)->ack_seq = ntohl(th->ack_seq);
TCP_SKB_CB(skb)->when = 0;
TCP_SKB_CB(skb)->ip_dsfield = ipv4_get_dsfield(iph);
TCP_SKB_CB(skb)->sacked = 0;
sk = __inet_lookup_skb(&tcp_hashinfo, skb, th->source, th->dest);
if (!sk)
goto no_tcp_socket;
process:
if (sk->sk_state == TCP_TIME_WAIT)
goto do_time_wait;
if (unlikely(iph->ttl < inet_sk(sk)->min_ttl)) {
NET_INC_STATS_BH(net, LINUX_MIB_TCPMINTTLDROP);
goto discard_and_relse;
}
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto discard_and_relse;
nf_reset(skb);
if (sk_filter(sk, skb))
goto discard_and_relse;
skb->dev = NULL;
bh_lock_sock_nested(sk);
ret = 0;
if (!sock_owned_by_user(sk)) {
#ifdef CONFIG_NET_DMA
struct tcp_sock *tp = tcp_sk(sk);
if (!tp->ucopy.dma_chan && tp->ucopy.pinned_list)
tp->ucopy.dma_chan = net_dma_find_channel();
if (tp->ucopy.dma_chan)
ret = tcp_v4_do_rcv(sk, skb);
else
#endif
{
if (!tcp_prequeue(sk, skb))
ret = tcp_v4_do_rcv(sk, skb);
}
} else if (unlikely(sk_add_backlog(sk, skb,
sk->sk_rcvbuf + sk->sk_sndbuf))) {
bh_unlock_sock(sk);
NET_INC_STATS_BH(net, LINUX_MIB_TCPBACKLOGDROP);
goto discard_and_relse;
}
bh_unlock_sock(sk);
sock_put(sk);
return ret;
no_tcp_socket:
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto discard_it;
if (skb->len < (th->doff << 2) || tcp_checksum_complete(skb)) {
bad_packet:
TCP_INC_STATS_BH(net, TCP_MIB_INERRS);
} else {
tcp_v4_send_reset(NULL, skb);
}
discard_it:
kfree_skb(skb);
return 0;
discard_and_relse:
sock_put(sk);
goto discard_it;
do_time_wait:
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb)) {
inet_twsk_put(inet_twsk(sk));
goto discard_it;
}
if (skb->len < (th->doff << 2) || tcp_checksum_complete(skb)) {
TCP_INC_STATS_BH(net, TCP_MIB_INERRS);
inet_twsk_put(inet_twsk(sk));
goto discard_it;
}
switch (tcp_timewait_state_process(inet_twsk(sk), skb, th)) {
case TCP_TW_SYN: {
struct sock *sk2 = inet_lookup_listener(dev_net(skb->dev),
&tcp_hashinfo,
iph->daddr, th->dest,
inet_iif(skb));
if (sk2) {
inet_twsk_deschedule(inet_twsk(sk), &tcp_death_row);
inet_twsk_put(inet_twsk(sk));
sk = sk2;
goto process;
}
}
case TCP_TW_ACK:
tcp_v4_timewait_ack(sk, skb);
break;
case TCP_TW_RST:
goto no_tcp_socket;
case TCP_TW_SUCCESS:;
}
goto discard_it;
}
void inet_sk_rx_dst_set(struct sock *sk, const struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
dst_hold(dst);
sk->sk_rx_dst = dst;
inet_sk(sk)->rx_dst_ifindex = skb->skb_iif;
}
static int tcp_v4_init_sock(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
tcp_init_sock(sk);
icsk->icsk_af_ops = &ipv4_specific;
#ifdef CONFIG_TCP_MD5SIG
tcp_sk(sk)->af_specific = &tcp_sock_ipv4_specific;
#endif
return 0;
}
void tcp_v4_destroy_sock(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
tcp_clear_xmit_timers(sk);
tcp_cleanup_congestion_control(sk);
tcp_write_queue_purge(sk);
__skb_queue_purge(&tp->out_of_order_queue);
#ifdef CONFIG_TCP_MD5SIG
if (tp->md5sig_info) {
tcp_clear_md5_list(sk);
kfree_rcu(tp->md5sig_info, rcu);
tp->md5sig_info = NULL;
}
#endif
#ifdef CONFIG_NET_DMA
__skb_queue_purge(&sk->sk_async_wait_queue);
#endif
__skb_queue_purge(&tp->ucopy.prequeue);
if (inet_csk(sk)->icsk_bind_hash)
inet_put_port(sk);
if (tp->cookie_values != NULL) {
kref_put(&tp->cookie_values->kref,
tcp_cookie_values_release);
tp->cookie_values = NULL;
}
BUG_ON(tp->fastopen_rsk != NULL);
tcp_free_fastopen_req(tp);
sk_sockets_allocated_dec(sk);
sock_release_memcg(sk);
}
static inline struct inet_timewait_sock *tw_head(struct hlist_nulls_head *head)
{
return hlist_nulls_empty(head) ? NULL :
list_entry(head->first, struct inet_timewait_sock, tw_node);
}
static inline struct inet_timewait_sock *tw_next(struct inet_timewait_sock *tw)
{
return !is_a_nulls(tw->tw_node.next) ?
hlist_nulls_entry(tw->tw_node.next, typeof(*tw), tw_node) : NULL;
}
static void *listening_get_next(struct seq_file *seq, void *cur)
{
struct inet_connection_sock *icsk;
struct hlist_nulls_node *node;
struct sock *sk = cur;
struct inet_listen_hashbucket *ilb;
struct tcp_iter_state *st = seq->private;
struct net *net = seq_file_net(seq);
if (!sk) {
ilb = &tcp_hashinfo.listening_hash[st->bucket];
spin_lock_bh(&ilb->lock);
sk = sk_nulls_head(&ilb->head);
st->offset = 0;
goto get_sk;
}
ilb = &tcp_hashinfo.listening_hash[st->bucket];
++st->num;
++st->offset;
if (st->state == TCP_SEQ_STATE_OPENREQ) {
struct request_sock *req = cur;
icsk = inet_csk(st->syn_wait_sk);
req = req->dl_next;
while (1) {
while (req) {
if (req->rsk_ops->family == st->family) {
cur = req;
goto out;
}
req = req->dl_next;
}
if (++st->sbucket >= icsk->icsk_accept_queue.listen_opt->nr_table_entries)
break;
get_req:
req = icsk->icsk_accept_queue.listen_opt->syn_table[st->sbucket];
}
sk = sk_nulls_next(st->syn_wait_sk);
st->state = TCP_SEQ_STATE_LISTENING;
read_unlock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
} else {
icsk = inet_csk(sk);
read_lock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
if (reqsk_queue_len(&icsk->icsk_accept_queue))
goto start_req;
read_unlock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
sk = sk_nulls_next(sk);
}
get_sk:
sk_nulls_for_each_from(sk, node) {
if (!net_eq(sock_net(sk), net))
continue;
if (sk->sk_family == st->family) {
cur = sk;
goto out;
}
icsk = inet_csk(sk);
read_lock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
if (reqsk_queue_len(&icsk->icsk_accept_queue)) {
start_req:
st->uid = sock_i_uid(sk);
st->syn_wait_sk = sk;
st->state = TCP_SEQ_STATE_OPENREQ;
st->sbucket = 0;
goto get_req;
}
read_unlock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
}
spin_unlock_bh(&ilb->lock);
st->offset = 0;
if (++st->bucket < INET_LHTABLE_SIZE) {
ilb = &tcp_hashinfo.listening_hash[st->bucket];
spin_lock_bh(&ilb->lock);
sk = sk_nulls_head(&ilb->head);
goto get_sk;
}
cur = NULL;
out:
return cur;
}
static void *listening_get_idx(struct seq_file *seq, loff_t *pos)
{
struct tcp_iter_state *st = seq->private;
void *rc;
st->bucket = 0;
st->offset = 0;
rc = listening_get_next(seq, NULL);
while (rc && *pos) {
rc = listening_get_next(seq, rc);
--*pos;
}
return rc;
}
static inline bool empty_bucket(struct tcp_iter_state *st)
{
return hlist_nulls_empty(&tcp_hashinfo.ehash[st->bucket].chain) &&
hlist_nulls_empty(&tcp_hashinfo.ehash[st->bucket].twchain);
}
static void *established_get_first(struct seq_file *seq)
{
struct tcp_iter_state *st = seq->private;
struct net *net = seq_file_net(seq);
void *rc = NULL;
st->offset = 0;
for (; st->bucket <= tcp_hashinfo.ehash_mask; ++st->bucket) {
struct sock *sk;
struct hlist_nulls_node *node;
struct inet_timewait_sock *tw;
spinlock_t *lock = inet_ehash_lockp(&tcp_hashinfo, st->bucket);
if (empty_bucket(st))
continue;
spin_lock_bh(lock);
sk_nulls_for_each(sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if (sk->sk_family != st->family ||
!net_eq(sock_net(sk), net)) {
continue;
}
rc = sk;
goto out;
}
st->state = TCP_SEQ_STATE_TIME_WAIT;
inet_twsk_for_each(tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if (tw->tw_family != st->family ||
!net_eq(twsk_net(tw), net)) {
continue;
}
rc = tw;
goto out;
}
spin_unlock_bh(lock);
st->state = TCP_SEQ_STATE_ESTABLISHED;
}
out:
return rc;
}
static void *established_get_next(struct seq_file *seq, void *cur)
{
struct sock *sk = cur;
struct inet_timewait_sock *tw;
struct hlist_nulls_node *node;
struct tcp_iter_state *st = seq->private;
struct net *net = seq_file_net(seq);
++st->num;
++st->offset;
if (st->state == TCP_SEQ_STATE_TIME_WAIT) {
tw = cur;
tw = tw_next(tw);
get_tw:
while (tw && (tw->tw_family != st->family || !net_eq(twsk_net(tw), net))) {
tw = tw_next(tw);
}
if (tw) {
cur = tw;
goto out;
}
spin_unlock_bh(inet_ehash_lockp(&tcp_hashinfo, st->bucket));
st->state = TCP_SEQ_STATE_ESTABLISHED;
st->offset = 0;
while (++st->bucket <= tcp_hashinfo.ehash_mask &&
empty_bucket(st))
;
if (st->bucket > tcp_hashinfo.ehash_mask)
return NULL;
spin_lock_bh(inet_ehash_lockp(&tcp_hashinfo, st->bucket));
sk = sk_nulls_head(&tcp_hashinfo.ehash[st->bucket].chain);
} else
sk = sk_nulls_next(sk);
sk_nulls_for_each_from(sk, node) {
if (sk->sk_family == st->family && net_eq(sock_net(sk), net))
goto found;
}
st->state = TCP_SEQ_STATE_TIME_WAIT;
tw = tw_head(&tcp_hashinfo.ehash[st->bucket].twchain);
goto get_tw;
found:
cur = sk;
out:
return cur;
}
static void *established_get_idx(struct seq_file *seq, loff_t pos)
{
struct tcp_iter_state *st = seq->private;
void *rc;
st->bucket = 0;
rc = established_get_first(seq);
while (rc && pos) {
rc = established_get_next(seq, rc);
--pos;
}
return rc;
}
static void *tcp_get_idx(struct seq_file *seq, loff_t pos)
{
void *rc;
struct tcp_iter_state *st = seq->private;
st->state = TCP_SEQ_STATE_LISTENING;
rc = listening_get_idx(seq, &pos);
if (!rc) {
st->state = TCP_SEQ_STATE_ESTABLISHED;
rc = established_get_idx(seq, pos);
}
return rc;
}
static void *tcp_seek_last_pos(struct seq_file *seq)
{
struct tcp_iter_state *st = seq->private;
int offset = st->offset;
int orig_num = st->num;
void *rc = NULL;
switch (st->state) {
case TCP_SEQ_STATE_OPENREQ:
case TCP_SEQ_STATE_LISTENING:
if (st->bucket >= INET_LHTABLE_SIZE)
break;
st->state = TCP_SEQ_STATE_LISTENING;
rc = listening_get_next(seq, NULL);
while (offset-- && rc)
rc = listening_get_next(seq, rc);
if (rc)
break;
st->bucket = 0;
case TCP_SEQ_STATE_ESTABLISHED:
case TCP_SEQ_STATE_TIME_WAIT:
st->state = TCP_SEQ_STATE_ESTABLISHED;
if (st->bucket > tcp_hashinfo.ehash_mask)
break;
rc = established_get_first(seq);
while (offset-- && rc)
rc = established_get_next(seq, rc);
}
st->num = orig_num;
return rc;
}
static void *tcp_seq_start(struct seq_file *seq, loff_t *pos)
{
struct tcp_iter_state *st = seq->private;
void *rc;
if (*pos && *pos == st->last_pos) {
rc = tcp_seek_last_pos(seq);
if (rc)
goto out;
}
st->state = TCP_SEQ_STATE_LISTENING;
st->num = 0;
st->bucket = 0;
st->offset = 0;
rc = *pos ? tcp_get_idx(seq, *pos - 1) : SEQ_START_TOKEN;
out:
st->last_pos = *pos;
return rc;
}
static void *tcp_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct tcp_iter_state *st = seq->private;
void *rc = NULL;
if (v == SEQ_START_TOKEN) {
rc = tcp_get_idx(seq, 0);
goto out;
}
switch (st->state) {
case TCP_SEQ_STATE_OPENREQ:
case TCP_SEQ_STATE_LISTENING:
rc = listening_get_next(seq, v);
if (!rc) {
st->state = TCP_SEQ_STATE_ESTABLISHED;
st->bucket = 0;
st->offset = 0;
rc = established_get_first(seq);
}
break;
case TCP_SEQ_STATE_ESTABLISHED:
case TCP_SEQ_STATE_TIME_WAIT:
rc = established_get_next(seq, v);
break;
}
out:
++*pos;
st->last_pos = *pos;
return rc;
}
static void tcp_seq_stop(struct seq_file *seq, void *v)
{
struct tcp_iter_state *st = seq->private;
switch (st->state) {
case TCP_SEQ_STATE_OPENREQ:
if (v) {
struct inet_connection_sock *icsk = inet_csk(st->syn_wait_sk);
read_unlock_bh(&icsk->icsk_accept_queue.syn_wait_lock);
}
case TCP_SEQ_STATE_LISTENING:
if (v != SEQ_START_TOKEN)
spin_unlock_bh(&tcp_hashinfo.listening_hash[st->bucket].lock);
break;
case TCP_SEQ_STATE_TIME_WAIT:
case TCP_SEQ_STATE_ESTABLISHED:
if (v)
spin_unlock_bh(inet_ehash_lockp(&tcp_hashinfo, st->bucket));
break;
}
}
int tcp_seq_open(struct inode *inode, struct file *file)
{
struct tcp_seq_afinfo *afinfo = PDE(inode)->data;
struct tcp_iter_state *s;
int err;
err = seq_open_net(inode, file, &afinfo->seq_ops,
sizeof(struct tcp_iter_state));
if (err < 0)
return err;
s = ((struct seq_file *)file->private_data)->private;
s->family = afinfo->family;
s->last_pos = 0;
return 0;
}
int tcp_proc_register(struct net *net, struct tcp_seq_afinfo *afinfo)
{
int rc = 0;
struct proc_dir_entry *p;
afinfo->seq_ops.start = tcp_seq_start;
afinfo->seq_ops.next = tcp_seq_next;
afinfo->seq_ops.stop = tcp_seq_stop;
p = proc_create_data(afinfo->name, S_IRUGO, net->proc_net,
afinfo->seq_fops, afinfo);
if (!p)
rc = -ENOMEM;
return rc;
}
void tcp_proc_unregister(struct net *net, struct tcp_seq_afinfo *afinfo)
{
proc_net_remove(net, afinfo->name);
}
static void get_openreq4(const struct sock *sk, const struct request_sock *req,
struct seq_file *f, int i, kuid_t uid, int *len)
{
const struct inet_request_sock *ireq = inet_rsk(req);
long delta = req->expires - jiffies;
seq_printf(f, "%4d: %08X:%04X %08X:%04X"
" %02X %08X:%08X %02X:%08lX %08X %5d %8d %u %d %pK%n",
i,
ireq->loc_addr,
ntohs(inet_sk(sk)->inet_sport),
ireq->rmt_addr,
ntohs(ireq->rmt_port),
TCP_SYN_RECV,
0, 0,
1,
jiffies_delta_to_clock_t(delta),
req->retrans,
from_kuid_munged(seq_user_ns(f), uid),
0,
0,
atomic_read(&sk->sk_refcnt),
req,
len);
}
static void get_tcp4_sock(struct sock *sk, struct seq_file *f, int i, int *len)
{
int timer_active;
unsigned long timer_expires;
const struct tcp_sock *tp = tcp_sk(sk);
const struct inet_connection_sock *icsk = inet_csk(sk);
const struct inet_sock *inet = inet_sk(sk);
struct fastopen_queue *fastopenq = icsk->icsk_accept_queue.fastopenq;
__be32 dest = inet->inet_daddr;
__be32 src = inet->inet_rcv_saddr;
__u16 destp = ntohs(inet->inet_dport);
__u16 srcp = ntohs(inet->inet_sport);
int rx_queue;
if (icsk->icsk_pending == ICSK_TIME_RETRANS) {
timer_active = 1;
timer_expires = icsk->icsk_timeout;
} else if (icsk->icsk_pending == ICSK_TIME_PROBE0) {
timer_active = 4;
timer_expires = icsk->icsk_timeout;
} else if (timer_pending(&sk->sk_timer)) {
timer_active = 2;
timer_expires = sk->sk_timer.expires;
} else {
timer_active = 0;
timer_expires = jiffies;
}
if (sk->sk_state == TCP_LISTEN)
rx_queue = sk->sk_ack_backlog;
else
rx_queue = max_t(int, tp->rcv_nxt - tp->copied_seq, 0);
seq_printf(f, "%4d: %08X:%04X %08X:%04X %02X %08X:%08X %02X:%08lX "
"%08X %5d %8d %lu %d %pK %lu %lu %u %u %d%n",
i, src, srcp, dest, destp, sk->sk_state,
tp->write_seq - tp->snd_una,
rx_queue,
timer_active,
jiffies_delta_to_clock_t(timer_expires - jiffies),
icsk->icsk_retransmits,
from_kuid_munged(seq_user_ns(f), sock_i_uid(sk)),
icsk->icsk_probes_out,
sock_i_ino(sk),
atomic_read(&sk->sk_refcnt), sk,
jiffies_to_clock_t(icsk->icsk_rto),
jiffies_to_clock_t(icsk->icsk_ack.ato),
(icsk->icsk_ack.quick << 1) | icsk->icsk_ack.pingpong,
tp->snd_cwnd,
sk->sk_state == TCP_LISTEN ?
(fastopenq ? fastopenq->max_qlen : 0) :
(tcp_in_initial_slowstart(tp) ? -1 : tp->snd_ssthresh),
len);
}
static void get_timewait4_sock(const struct inet_timewait_sock *tw,
struct seq_file *f, int i, int *len)
{
__be32 dest, src;
__u16 destp, srcp;
long delta = tw->tw_ttd - jiffies;
dest = tw->tw_daddr;
src = tw->tw_rcv_saddr;
destp = ntohs(tw->tw_dport);
srcp = ntohs(tw->tw_sport);
seq_printf(f, "%4d: %08X:%04X %08X:%04X"
" %02X %08X:%08X %02X:%08lX %08X %5d %8d %d %d %pK%n",
i, src, srcp, dest, destp, tw->tw_substate, 0, 0,
3, jiffies_delta_to_clock_t(delta), 0, 0, 0, 0,
atomic_read(&tw->tw_refcnt), tw, len);
}
static int tcp4_seq_show(struct seq_file *seq, void *v)
{
struct tcp_iter_state *st;
int len;
if (v == SEQ_START_TOKEN) {
seq_printf(seq, "%-*s\n", TMPSZ - 1,
" sl local_address rem_address st tx_queue "
"rx_queue tr tm->when retrnsmt uid timeout "
"inode");
goto out;
}
st = seq->private;
switch (st->state) {
case TCP_SEQ_STATE_LISTENING:
case TCP_SEQ_STATE_ESTABLISHED:
get_tcp4_sock(v, seq, st->num, &len);
break;
case TCP_SEQ_STATE_OPENREQ:
get_openreq4(st->syn_wait_sk, v, seq, st->num, st->uid, &len);
break;
case TCP_SEQ_STATE_TIME_WAIT:
get_timewait4_sock(v, seq, st->num, &len);
break;
}
seq_printf(seq, "%*s\n", TMPSZ - 1 - len, "");
out:
return 0;
}
static int __net_init tcp4_proc_init_net(struct net *net)
{
return tcp_proc_register(net, &tcp4_seq_afinfo);
}
static void __net_exit tcp4_proc_exit_net(struct net *net)
{
tcp_proc_unregister(net, &tcp4_seq_afinfo);
}
int __init tcp4_proc_init(void)
{
return register_pernet_subsys(&tcp4_net_ops);
}
void tcp4_proc_exit(void)
{
unregister_pernet_subsys(&tcp4_net_ops);
}
struct sk_buff **tcp4_gro_receive(struct sk_buff **head, struct sk_buff *skb)
{
const struct iphdr *iph = skb_gro_network_header(skb);
__wsum wsum;
__sum16 sum;
switch (skb->ip_summed) {
case CHECKSUM_COMPLETE:
if (!tcp_v4_check(skb_gro_len(skb), iph->saddr, iph->daddr,
skb->csum)) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
break;
}
flush:
NAPI_GRO_CB(skb)->flush = 1;
return NULL;
case CHECKSUM_NONE:
wsum = csum_tcpudp_nofold(iph->saddr, iph->daddr,
skb_gro_len(skb), IPPROTO_TCP, 0);
sum = csum_fold(skb_checksum(skb,
skb_gro_offset(skb),
skb_gro_len(skb),
wsum));
if (sum)
goto flush;
skb->ip_summed = CHECKSUM_UNNECESSARY;
break;
}
return tcp_gro_receive(head, skb);
}
int tcp4_gro_complete(struct sk_buff *skb)
{
const struct iphdr *iph = ip_hdr(skb);
struct tcphdr *th = tcp_hdr(skb);
th->check = ~tcp_v4_check(skb->len - skb_transport_offset(skb),
iph->saddr, iph->daddr, 0);
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
return tcp_gro_complete(skb);
}
static int __net_init tcp_sk_init(struct net *net)
{
return 0;
}
static void __net_exit tcp_sk_exit(struct net *net)
{
}
static void __net_exit tcp_sk_exit_batch(struct list_head *net_exit_list)
{
inet_twsk_purge(&tcp_hashinfo, &tcp_death_row, AF_INET);
}
void __init tcp_v4_init(void)
{
inet_hashinfo_init(&tcp_hashinfo);
if (register_pernet_subsys(&tcp_sk_ops))
panic("Failed to create the TCP control socket.\n");
}
