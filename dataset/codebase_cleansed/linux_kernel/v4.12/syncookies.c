static u32 cookie_hash(__be32 saddr, __be32 daddr, __be16 sport, __be16 dport,
u32 count, int c)
{
net_get_random_once(syncookie_secret, sizeof(syncookie_secret));
return siphash_4u32((__force u32)saddr, (__force u32)daddr,
(__force u32)sport << 16 | (__force u32)dport,
count, &syncookie_secret[c]);
}
__u32 cookie_init_timestamp(struct request_sock *req)
{
struct inet_request_sock *ireq;
u32 ts, ts_now = tcp_time_stamp;
u32 options = 0;
ireq = inet_rsk(req);
options = ireq->wscale_ok ? ireq->snd_wscale : TS_OPT_WSCALE_MASK;
if (ireq->sack_ok)
options |= TS_OPT_SACK;
if (ireq->ecn_ok)
options |= TS_OPT_ECN;
ts = ts_now & ~TSMASK;
ts |= options;
if (ts > ts_now) {
ts >>= TSBITS;
ts--;
ts <<= TSBITS;
ts |= options;
}
return ts;
}
static __u32 secure_tcp_syn_cookie(__be32 saddr, __be32 daddr, __be16 sport,
__be16 dport, __u32 sseq, __u32 data)
{
u32 count = tcp_cookie_time();
return (cookie_hash(saddr, daddr, sport, dport, 0, 0) +
sseq + (count << COOKIEBITS) +
((cookie_hash(saddr, daddr, sport, dport, count, 1) + data)
& COOKIEMASK));
}
static __u32 check_tcp_syn_cookie(__u32 cookie, __be32 saddr, __be32 daddr,
__be16 sport, __be16 dport, __u32 sseq)
{
u32 diff, count = tcp_cookie_time();
cookie -= cookie_hash(saddr, daddr, sport, dport, 0, 0) + sseq;
diff = (count - (cookie >> COOKIEBITS)) & ((__u32) -1 >> COOKIEBITS);
if (diff >= MAX_SYNCOOKIE_AGE)
return (__u32)-1;
return (cookie -
cookie_hash(saddr, daddr, sport, dport, count - diff, 1))
& COOKIEMASK;
}
u32 __cookie_v4_init_sequence(const struct iphdr *iph, const struct tcphdr *th,
u16 *mssp)
{
int mssind;
const __u16 mss = *mssp;
for (mssind = ARRAY_SIZE(msstab) - 1; mssind ; mssind--)
if (mss >= msstab[mssind])
break;
*mssp = msstab[mssind];
return secure_tcp_syn_cookie(iph->saddr, iph->daddr,
th->source, th->dest, ntohl(th->seq),
mssind);
}
__u32 cookie_v4_init_sequence(const struct sk_buff *skb, __u16 *mssp)
{
const struct iphdr *iph = ip_hdr(skb);
const struct tcphdr *th = tcp_hdr(skb);
return __cookie_v4_init_sequence(iph, th, mssp);
}
int __cookie_v4_check(const struct iphdr *iph, const struct tcphdr *th,
u32 cookie)
{
__u32 seq = ntohl(th->seq) - 1;
__u32 mssind = check_tcp_syn_cookie(cookie, iph->saddr, iph->daddr,
th->source, th->dest, seq);
return mssind < ARRAY_SIZE(msstab) ? msstab[mssind] : 0;
}
struct sock *tcp_get_cookie_sock(struct sock *sk, struct sk_buff *skb,
struct request_sock *req,
struct dst_entry *dst, u32 tsoff)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct sock *child;
bool own_req;
child = icsk->icsk_af_ops->syn_recv_sock(sk, skb, req, dst,
NULL, &own_req);
if (child) {
atomic_set(&req->rsk_refcnt, 1);
tcp_sk(child)->tsoffset = tsoff;
sock_rps_save_rxhash(child, skb);
inet_csk_reqsk_queue_add(sk, req, child);
} else {
reqsk_free(req);
}
return child;
}
bool cookie_timestamp_decode(struct tcp_options_received *tcp_opt)
{
u32 options = tcp_opt->rcv_tsecr;
if (!tcp_opt->saw_tstamp) {
tcp_clear_options(tcp_opt);
return true;
}
if (!sysctl_tcp_timestamps)
return false;
tcp_opt->sack_ok = (options & TS_OPT_SACK) ? TCP_SACK_SEEN : 0;
if (tcp_opt->sack_ok && !sysctl_tcp_sack)
return false;
if ((options & TS_OPT_WSCALE_MASK) == TS_OPT_WSCALE_MASK)
return true;
tcp_opt->wscale_ok = 1;
tcp_opt->snd_wscale = options & TS_OPT_WSCALE_MASK;
return sysctl_tcp_window_scaling != 0;
}
bool cookie_ecn_ok(const struct tcp_options_received *tcp_opt,
const struct net *net, const struct dst_entry *dst)
{
bool ecn_ok = tcp_opt->rcv_tsecr & TS_OPT_ECN;
if (!ecn_ok)
return false;
if (net->ipv4.sysctl_tcp_ecn)
return true;
return dst_feature(dst, RTAX_FEATURE_ECN);
}
struct sock *cookie_v4_check(struct sock *sk, struct sk_buff *skb)
{
struct ip_options *opt = &TCP_SKB_CB(skb)->header.h4.opt;
struct tcp_options_received tcp_opt;
struct inet_request_sock *ireq;
struct tcp_request_sock *treq;
struct tcp_sock *tp = tcp_sk(sk);
const struct tcphdr *th = tcp_hdr(skb);
__u32 cookie = ntohl(th->ack_seq) - 1;
struct sock *ret = sk;
struct request_sock *req;
int mss;
struct rtable *rt;
__u8 rcv_wscale;
struct flowi4 fl4;
u32 tsoff = 0;
if (!sock_net(sk)->ipv4.sysctl_tcp_syncookies || !th->ack || th->rst)
goto out;
if (tcp_synq_no_recent_overflow(sk))
goto out;
mss = __cookie_v4_check(ip_hdr(skb), th, cookie);
if (mss == 0) {
__NET_INC_STATS(sock_net(sk), LINUX_MIB_SYNCOOKIESFAILED);
goto out;
}
__NET_INC_STATS(sock_net(sk), LINUX_MIB_SYNCOOKIESRECV);
memset(&tcp_opt, 0, sizeof(tcp_opt));
tcp_parse_options(skb, &tcp_opt, 0, NULL);
if (tcp_opt.saw_tstamp && tcp_opt.rcv_tsecr) {
tsoff = secure_tcp_ts_off(ip_hdr(skb)->daddr, ip_hdr(skb)->saddr);
tcp_opt.rcv_tsecr -= tsoff;
}
if (!cookie_timestamp_decode(&tcp_opt))
goto out;
ret = NULL;
req = inet_reqsk_alloc(&tcp_request_sock_ops, sk, false);
if (!req)
goto out;
ireq = inet_rsk(req);
treq = tcp_rsk(req);
treq->rcv_isn = ntohl(th->seq) - 1;
treq->snt_isn = cookie;
treq->ts_off = 0;
req->mss = mss;
ireq->ir_num = ntohs(th->dest);
ireq->ir_rmt_port = th->source;
sk_rcv_saddr_set(req_to_sk(req), ip_hdr(skb)->daddr);
sk_daddr_set(req_to_sk(req), ip_hdr(skb)->saddr);
ireq->ir_mark = inet_request_mark(sk, skb);
ireq->snd_wscale = tcp_opt.snd_wscale;
ireq->sack_ok = tcp_opt.sack_ok;
ireq->wscale_ok = tcp_opt.wscale_ok;
ireq->tstamp_ok = tcp_opt.saw_tstamp;
req->ts_recent = tcp_opt.saw_tstamp ? tcp_opt.rcv_tsval : 0;
treq->snt_synack.v64 = 0;
treq->tfo_listener = false;
ireq->ir_iif = inet_request_bound_dev_if(sk, skb);
ireq->opt = tcp_v4_save_options(skb);
if (security_inet_conn_request(sk, skb, req)) {
reqsk_free(req);
goto out;
}
req->num_retrans = 0;
flowi4_init_output(&fl4, ireq->ir_iif, ireq->ir_mark,
RT_CONN_FLAGS(sk), RT_SCOPE_UNIVERSE, IPPROTO_TCP,
inet_sk_flowi_flags(sk),
opt->srr ? opt->faddr : ireq->ir_rmt_addr,
ireq->ir_loc_addr, th->source, th->dest, sk->sk_uid);
security_req_classify_flow(req, flowi4_to_flowi(&fl4));
rt = ip_route_output_key(sock_net(sk), &fl4);
if (IS_ERR(rt)) {
reqsk_free(req);
goto out;
}
req->rsk_window_clamp = tp->window_clamp ? :dst_metric(&rt->dst, RTAX_WINDOW);
tcp_select_initial_window(tcp_full_space(sk), req->mss,
&req->rsk_rcv_wnd, &req->rsk_window_clamp,
ireq->wscale_ok, &rcv_wscale,
dst_metric(&rt->dst, RTAX_INITRWND));
ireq->rcv_wscale = rcv_wscale;
ireq->ecn_ok = cookie_ecn_ok(&tcp_opt, sock_net(sk), &rt->dst);
ret = tcp_get_cookie_sock(sk, skb, req, &rt->dst, tsoff);
if (ret)
inet_sk(ret)->cork.fl.u.ip4 = fl4;
out: return ret;
}
