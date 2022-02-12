static void tcp_event_new_data_sent(struct sock *sk, const struct sk_buff *skb)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
unsigned int prior_packets = tp->packets_out;
tcp_advance_send_head(sk, skb);
tp->snd_nxt = TCP_SKB_CB(skb)->end_seq;
tp->packets_out += tcp_skb_pcount(skb);
if (!prior_packets || icsk->icsk_pending == ICSK_TIME_EARLY_RETRANS ||
icsk->icsk_pending == ICSK_TIME_LOSS_PROBE) {
tcp_rearm_rto(sk);
}
NET_ADD_STATS(sock_net(sk), LINUX_MIB_TCPORIGDATASENT,
tcp_skb_pcount(skb));
}
static inline __u32 tcp_acceptable_seq(const struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
if (!before(tcp_wnd_end(tp), tp->snd_nxt))
return tp->snd_nxt;
else
return tcp_wnd_end(tp);
}
static __u16 tcp_advertise_mss(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
const struct dst_entry *dst = __sk_dst_get(sk);
int mss = tp->advmss;
if (dst) {
unsigned int metric = dst_metric_advmss(dst);
if (metric < mss) {
mss = metric;
tp->advmss = mss;
}
}
return (__u16)mss;
}
void tcp_cwnd_restart(struct sock *sk, s32 delta)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 restart_cwnd = tcp_init_cwnd(tp, __sk_dst_get(sk));
u32 cwnd = tp->snd_cwnd;
tcp_ca_event(sk, CA_EVENT_CWND_RESTART);
tp->snd_ssthresh = tcp_current_ssthresh(sk);
restart_cwnd = min(restart_cwnd, cwnd);
while ((delta -= inet_csk(sk)->icsk_rto) > 0 && cwnd > restart_cwnd)
cwnd >>= 1;
tp->snd_cwnd = max(cwnd, restart_cwnd);
tp->snd_cwnd_stamp = tcp_time_stamp;
tp->snd_cwnd_used = 0;
}
static void tcp_event_data_sent(struct tcp_sock *tp,
struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
const u32 now = tcp_time_stamp;
if (tcp_packets_in_flight(tp) == 0)
tcp_ca_event(sk, CA_EVENT_TX_START);
tp->lsndtime = now;
if ((u32)(now - icsk->icsk_ack.lrcvtime) < icsk->icsk_ack.ato)
icsk->icsk_ack.pingpong = 1;
}
static inline void tcp_event_ack_sent(struct sock *sk, unsigned int pkts)
{
tcp_dec_quickack_mode(sk, pkts);
inet_csk_clear_xmit_timer(sk, ICSK_TIME_DACK);
}
u32 tcp_default_init_rwnd(u32 mss)
{
u32 init_rwnd = TCP_INIT_CWND * 2;
if (mss > 1460)
init_rwnd = max((1460 * init_rwnd) / mss, 2U);
return init_rwnd;
}
void tcp_select_initial_window(int __space, __u32 mss,
__u32 *rcv_wnd, __u32 *window_clamp,
int wscale_ok, __u8 *rcv_wscale,
__u32 init_rcv_wnd)
{
unsigned int space = (__space < 0 ? 0 : __space);
if (*window_clamp == 0)
(*window_clamp) = (65535 << 14);
space = min(*window_clamp, space);
if (space > mss)
space = (space / mss) * mss;
if (sysctl_tcp_workaround_signed_windows)
(*rcv_wnd) = min(space, MAX_TCP_WINDOW);
else
(*rcv_wnd) = space;
(*rcv_wscale) = 0;
if (wscale_ok) {
space = max_t(u32, space, sysctl_tcp_rmem[2]);
space = max_t(u32, space, sysctl_rmem_max);
space = min_t(u32, space, *window_clamp);
while (space > 65535 && (*rcv_wscale) < 14) {
space >>= 1;
(*rcv_wscale)++;
}
}
if (mss > (1 << *rcv_wscale)) {
if (!init_rcv_wnd)
init_rcv_wnd = tcp_default_init_rwnd(mss);
*rcv_wnd = min(*rcv_wnd, init_rcv_wnd * mss);
}
(*window_clamp) = min(65535U << (*rcv_wscale), *window_clamp);
}
static u16 tcp_select_window(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 old_win = tp->rcv_wnd;
u32 cur_win = tcp_receive_window(tp);
u32 new_win = __tcp_select_window(sk);
if (new_win < cur_win) {
if (new_win == 0)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPWANTZEROWINDOWADV);
new_win = ALIGN(cur_win, 1 << tp->rx_opt.rcv_wscale);
}
tp->rcv_wnd = new_win;
tp->rcv_wup = tp->rcv_nxt;
if (!tp->rx_opt.rcv_wscale && sysctl_tcp_workaround_signed_windows)
new_win = min(new_win, MAX_TCP_WINDOW);
else
new_win = min(new_win, (65535U << tp->rx_opt.rcv_wscale));
new_win >>= tp->rx_opt.rcv_wscale;
if (new_win == 0) {
tp->pred_flags = 0;
if (old_win)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPTOZEROWINDOWADV);
} else if (old_win == 0) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPFROMZEROWINDOWADV);
}
return new_win;
}
static void tcp_ecn_send_synack(struct sock *sk, struct sk_buff *skb)
{
const struct tcp_sock *tp = tcp_sk(sk);
TCP_SKB_CB(skb)->tcp_flags &= ~TCPHDR_CWR;
if (!(tp->ecn_flags & TCP_ECN_OK))
TCP_SKB_CB(skb)->tcp_flags &= ~TCPHDR_ECE;
else if (tcp_ca_needs_ecn(sk))
INET_ECN_xmit(sk);
}
static void tcp_ecn_send_syn(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
bool use_ecn = sock_net(sk)->ipv4.sysctl_tcp_ecn == 1 ||
tcp_ca_needs_ecn(sk);
if (!use_ecn) {
const struct dst_entry *dst = __sk_dst_get(sk);
if (dst && dst_feature(dst, RTAX_FEATURE_ECN))
use_ecn = true;
}
tp->ecn_flags = 0;
if (use_ecn) {
TCP_SKB_CB(skb)->tcp_flags |= TCPHDR_ECE | TCPHDR_CWR;
tp->ecn_flags = TCP_ECN_OK;
if (tcp_ca_needs_ecn(sk))
INET_ECN_xmit(sk);
}
}
static void tcp_ecn_clear_syn(struct sock *sk, struct sk_buff *skb)
{
if (sock_net(sk)->ipv4.sysctl_tcp_ecn_fallback)
TCP_SKB_CB(skb)->tcp_flags &= ~(TCPHDR_ECE | TCPHDR_CWR);
}
static void
tcp_ecn_make_synack(const struct request_sock *req, struct tcphdr *th)
{
if (inet_rsk(req)->ecn_ok)
th->ece = 1;
}
static void tcp_ecn_send(struct sock *sk, struct sk_buff *skb,
struct tcphdr *th, int tcp_header_len)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->ecn_flags & TCP_ECN_OK) {
if (skb->len != tcp_header_len &&
!before(TCP_SKB_CB(skb)->seq, tp->snd_nxt)) {
INET_ECN_xmit(sk);
if (tp->ecn_flags & TCP_ECN_QUEUE_CWR) {
tp->ecn_flags &= ~TCP_ECN_QUEUE_CWR;
th->cwr = 1;
skb_shinfo(skb)->gso_type |= SKB_GSO_TCP_ECN;
}
} else if (!tcp_ca_needs_ecn(sk)) {
INET_ECN_dontxmit(sk);
}
if (tp->ecn_flags & TCP_ECN_DEMAND_CWR)
th->ece = 1;
}
}
static void tcp_init_nondata_skb(struct sk_buff *skb, u32 seq, u8 flags)
{
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum = 0;
TCP_SKB_CB(skb)->tcp_flags = flags;
TCP_SKB_CB(skb)->sacked = 0;
tcp_skb_pcount_set(skb, 1);
TCP_SKB_CB(skb)->seq = seq;
if (flags & (TCPHDR_SYN | TCPHDR_FIN))
seq++;
TCP_SKB_CB(skb)->end_seq = seq;
}
static inline bool tcp_urg_mode(const struct tcp_sock *tp)
{
return tp->snd_una != tp->snd_up;
}
static void tcp_options_write(__be32 *ptr, struct tcp_sock *tp,
struct tcp_out_options *opts)
{
u16 options = opts->options;
if (unlikely(OPTION_MD5 & options)) {
*ptr++ = htonl((TCPOPT_NOP << 24) | (TCPOPT_NOP << 16) |
(TCPOPT_MD5SIG << 8) | TCPOLEN_MD5SIG);
opts->hash_location = (__u8 *)ptr;
ptr += 4;
}
if (unlikely(opts->mss)) {
*ptr++ = htonl((TCPOPT_MSS << 24) |
(TCPOLEN_MSS << 16) |
opts->mss);
}
if (likely(OPTION_TS & options)) {
if (unlikely(OPTION_SACK_ADVERTISE & options)) {
*ptr++ = htonl((TCPOPT_SACK_PERM << 24) |
(TCPOLEN_SACK_PERM << 16) |
(TCPOPT_TIMESTAMP << 8) |
TCPOLEN_TIMESTAMP);
options &= ~OPTION_SACK_ADVERTISE;
} else {
*ptr++ = htonl((TCPOPT_NOP << 24) |
(TCPOPT_NOP << 16) |
(TCPOPT_TIMESTAMP << 8) |
TCPOLEN_TIMESTAMP);
}
*ptr++ = htonl(opts->tsval);
*ptr++ = htonl(opts->tsecr);
}
if (unlikely(OPTION_SACK_ADVERTISE & options)) {
*ptr++ = htonl((TCPOPT_NOP << 24) |
(TCPOPT_NOP << 16) |
(TCPOPT_SACK_PERM << 8) |
TCPOLEN_SACK_PERM);
}
if (unlikely(OPTION_WSCALE & options)) {
*ptr++ = htonl((TCPOPT_NOP << 24) |
(TCPOPT_WINDOW << 16) |
(TCPOLEN_WINDOW << 8) |
opts->ws);
}
if (unlikely(opts->num_sack_blocks)) {
struct tcp_sack_block *sp = tp->rx_opt.dsack ?
tp->duplicate_sack : tp->selective_acks;
int this_sack;
*ptr++ = htonl((TCPOPT_NOP << 24) |
(TCPOPT_NOP << 16) |
(TCPOPT_SACK << 8) |
(TCPOLEN_SACK_BASE + (opts->num_sack_blocks *
TCPOLEN_SACK_PERBLOCK)));
for (this_sack = 0; this_sack < opts->num_sack_blocks;
++this_sack) {
*ptr++ = htonl(sp[this_sack].start_seq);
*ptr++ = htonl(sp[this_sack].end_seq);
}
tp->rx_opt.dsack = 0;
}
if (unlikely(OPTION_FAST_OPEN_COOKIE & options)) {
struct tcp_fastopen_cookie *foc = opts->fastopen_cookie;
u8 *p = (u8 *)ptr;
u32 len;
if (foc->exp) {
len = TCPOLEN_EXP_FASTOPEN_BASE + foc->len;
*ptr = htonl((TCPOPT_EXP << 24) | (len << 16) |
TCPOPT_FASTOPEN_MAGIC);
p += TCPOLEN_EXP_FASTOPEN_BASE;
} else {
len = TCPOLEN_FASTOPEN_BASE + foc->len;
*p++ = TCPOPT_FASTOPEN;
*p++ = len;
}
memcpy(p, foc->val, foc->len);
if ((len & 3) == 2) {
p[foc->len] = TCPOPT_NOP;
p[foc->len + 1] = TCPOPT_NOP;
}
ptr += (len + 3) >> 2;
}
}
static unsigned int tcp_syn_options(struct sock *sk, struct sk_buff *skb,
struct tcp_out_options *opts,
struct tcp_md5sig_key **md5)
{
struct tcp_sock *tp = tcp_sk(sk);
unsigned int remaining = MAX_TCP_OPTION_SPACE;
struct tcp_fastopen_request *fastopen = tp->fastopen_req;
#ifdef CONFIG_TCP_MD5SIG
*md5 = tp->af_specific->md5_lookup(sk, sk);
if (*md5) {
opts->options |= OPTION_MD5;
remaining -= TCPOLEN_MD5SIG_ALIGNED;
}
#else
*md5 = NULL;
#endif
opts->mss = tcp_advertise_mss(sk);
remaining -= TCPOLEN_MSS_ALIGNED;
if (likely(sysctl_tcp_timestamps && !*md5)) {
opts->options |= OPTION_TS;
opts->tsval = tcp_skb_timestamp(skb) + tp->tsoffset;
opts->tsecr = tp->rx_opt.ts_recent;
remaining -= TCPOLEN_TSTAMP_ALIGNED;
}
if (likely(sysctl_tcp_window_scaling)) {
opts->ws = tp->rx_opt.rcv_wscale;
opts->options |= OPTION_WSCALE;
remaining -= TCPOLEN_WSCALE_ALIGNED;
}
if (likely(sysctl_tcp_sack)) {
opts->options |= OPTION_SACK_ADVERTISE;
if (unlikely(!(OPTION_TS & opts->options)))
remaining -= TCPOLEN_SACKPERM_ALIGNED;
}
if (fastopen && fastopen->cookie.len >= 0) {
u32 need = fastopen->cookie.len;
need += fastopen->cookie.exp ? TCPOLEN_EXP_FASTOPEN_BASE :
TCPOLEN_FASTOPEN_BASE;
need = (need + 3) & ~3U;
if (remaining >= need) {
opts->options |= OPTION_FAST_OPEN_COOKIE;
opts->fastopen_cookie = &fastopen->cookie;
remaining -= need;
tp->syn_fastopen = 1;
tp->syn_fastopen_exp = fastopen->cookie.exp ? 1 : 0;
}
}
return MAX_TCP_OPTION_SPACE - remaining;
}
static unsigned int tcp_synack_options(struct request_sock *req,
unsigned int mss, struct sk_buff *skb,
struct tcp_out_options *opts,
const struct tcp_md5sig_key *md5,
struct tcp_fastopen_cookie *foc)
{
struct inet_request_sock *ireq = inet_rsk(req);
unsigned int remaining = MAX_TCP_OPTION_SPACE;
#ifdef CONFIG_TCP_MD5SIG
if (md5) {
opts->options |= OPTION_MD5;
remaining -= TCPOLEN_MD5SIG_ALIGNED;
ireq->tstamp_ok &= !ireq->sack_ok;
}
#endif
opts->mss = mss;
remaining -= TCPOLEN_MSS_ALIGNED;
if (likely(ireq->wscale_ok)) {
opts->ws = ireq->rcv_wscale;
opts->options |= OPTION_WSCALE;
remaining -= TCPOLEN_WSCALE_ALIGNED;
}
if (likely(ireq->tstamp_ok)) {
opts->options |= OPTION_TS;
opts->tsval = tcp_skb_timestamp(skb) + tcp_rsk(req)->ts_off;
opts->tsecr = req->ts_recent;
remaining -= TCPOLEN_TSTAMP_ALIGNED;
}
if (likely(ireq->sack_ok)) {
opts->options |= OPTION_SACK_ADVERTISE;
if (unlikely(!ireq->tstamp_ok))
remaining -= TCPOLEN_SACKPERM_ALIGNED;
}
if (foc != NULL && foc->len >= 0) {
u32 need = foc->len;
need += foc->exp ? TCPOLEN_EXP_FASTOPEN_BASE :
TCPOLEN_FASTOPEN_BASE;
need = (need + 3) & ~3U;
if (remaining >= need) {
opts->options |= OPTION_FAST_OPEN_COOKIE;
opts->fastopen_cookie = foc;
remaining -= need;
}
}
return MAX_TCP_OPTION_SPACE - remaining;
}
static unsigned int tcp_established_options(struct sock *sk, struct sk_buff *skb,
struct tcp_out_options *opts,
struct tcp_md5sig_key **md5)
{
struct tcp_sock *tp = tcp_sk(sk);
unsigned int size = 0;
unsigned int eff_sacks;
opts->options = 0;
#ifdef CONFIG_TCP_MD5SIG
*md5 = tp->af_specific->md5_lookup(sk, sk);
if (unlikely(*md5)) {
opts->options |= OPTION_MD5;
size += TCPOLEN_MD5SIG_ALIGNED;
}
#else
*md5 = NULL;
#endif
if (likely(tp->rx_opt.tstamp_ok)) {
opts->options |= OPTION_TS;
opts->tsval = skb ? tcp_skb_timestamp(skb) + tp->tsoffset : 0;
opts->tsecr = tp->rx_opt.ts_recent;
size += TCPOLEN_TSTAMP_ALIGNED;
}
eff_sacks = tp->rx_opt.num_sacks + tp->rx_opt.dsack;
if (unlikely(eff_sacks)) {
const unsigned int remaining = MAX_TCP_OPTION_SPACE - size;
opts->num_sack_blocks =
min_t(unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK);
size += TCPOLEN_SACK_BASE_ALIGNED +
opts->num_sack_blocks * TCPOLEN_SACK_PERBLOCK;
}
return size;
}
static void tcp_tsq_handler(struct sock *sk)
{
if ((1 << sk->sk_state) &
(TCPF_ESTABLISHED | TCPF_FIN_WAIT1 | TCPF_CLOSING |
TCPF_CLOSE_WAIT | TCPF_LAST_ACK)) {
struct tcp_sock *tp = tcp_sk(sk);
if (tp->lost_out > tp->retrans_out &&
tp->snd_cwnd > tcp_packets_in_flight(tp))
tcp_xmit_retransmit_queue(sk);
tcp_write_xmit(sk, tcp_current_mss(sk), tp->nonagle,
0, GFP_ATOMIC);
}
}
static void tcp_tasklet_func(unsigned long data)
{
struct tsq_tasklet *tsq = (struct tsq_tasklet *)data;
LIST_HEAD(list);
unsigned long flags;
struct list_head *q, *n;
struct tcp_sock *tp;
struct sock *sk;
local_irq_save(flags);
list_splice_init(&tsq->head, &list);
local_irq_restore(flags);
list_for_each_safe(q, n, &list) {
tp = list_entry(q, struct tcp_sock, tsq_node);
list_del(&tp->tsq_node);
sk = (struct sock *)tp;
smp_mb__before_atomic();
clear_bit(TSQ_QUEUED, &sk->sk_tsq_flags);
if (!sk->sk_lock.owned &&
test_bit(TCP_TSQ_DEFERRED, &sk->sk_tsq_flags)) {
bh_lock_sock(sk);
if (!sock_owned_by_user(sk)) {
clear_bit(TCP_TSQ_DEFERRED, &sk->sk_tsq_flags);
tcp_tsq_handler(sk);
}
bh_unlock_sock(sk);
}
sk_free(sk);
}
}
void tcp_release_cb(struct sock *sk)
{
unsigned long flags, nflags;
do {
flags = sk->sk_tsq_flags;
if (!(flags & TCP_DEFERRED_ALL))
return;
nflags = flags & ~TCP_DEFERRED_ALL;
} while (cmpxchg(&sk->sk_tsq_flags, flags, nflags) != flags);
if (flags & TCPF_TSQ_DEFERRED)
tcp_tsq_handler(sk);
sock_release_ownership(sk);
if (flags & TCPF_WRITE_TIMER_DEFERRED) {
tcp_write_timer_handler(sk);
__sock_put(sk);
}
if (flags & TCPF_DELACK_TIMER_DEFERRED) {
tcp_delack_timer_handler(sk);
__sock_put(sk);
}
if (flags & TCPF_MTU_REDUCED_DEFERRED) {
inet_csk(sk)->icsk_af_ops->mtu_reduced(sk);
__sock_put(sk);
}
}
void __init tcp_tasklet_init(void)
{
int i;
for_each_possible_cpu(i) {
struct tsq_tasklet *tsq = &per_cpu(tsq_tasklet, i);
INIT_LIST_HEAD(&tsq->head);
tasklet_init(&tsq->tasklet,
tcp_tasklet_func,
(unsigned long)tsq);
}
}
void tcp_wfree(struct sk_buff *skb)
{
struct sock *sk = skb->sk;
struct tcp_sock *tp = tcp_sk(sk);
unsigned long flags, nval, oval;
int wmem;
wmem = atomic_sub_return(skb->truesize - 1, &sk->sk_wmem_alloc);
if (wmem >= SKB_TRUESIZE(1) && this_cpu_ksoftirqd() == current)
goto out;
for (oval = READ_ONCE(sk->sk_tsq_flags);; oval = nval) {
struct tsq_tasklet *tsq;
bool empty;
if (!(oval & TSQF_THROTTLED) || (oval & TSQF_QUEUED))
goto out;
nval = (oval & ~TSQF_THROTTLED) | TSQF_QUEUED | TCPF_TSQ_DEFERRED;
nval = cmpxchg(&sk->sk_tsq_flags, oval, nval);
if (nval != oval)
continue;
local_irq_save(flags);
tsq = this_cpu_ptr(&tsq_tasklet);
empty = list_empty(&tsq->head);
list_add(&tp->tsq_node, &tsq->head);
if (empty)
tasklet_schedule(&tsq->tasklet);
local_irq_restore(flags);
return;
}
out:
sk_free(sk);
}
static int tcp_transmit_skb(struct sock *sk, struct sk_buff *skb, int clone_it,
gfp_t gfp_mask)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct inet_sock *inet;
struct tcp_sock *tp;
struct tcp_skb_cb *tcb;
struct tcp_out_options opts;
unsigned int tcp_options_size, tcp_header_size;
struct tcp_md5sig_key *md5;
struct tcphdr *th;
int err;
BUG_ON(!skb || !tcp_skb_pcount(skb));
tp = tcp_sk(sk);
if (clone_it) {
skb_mstamp_get(&skb->skb_mstamp);
TCP_SKB_CB(skb)->tx.in_flight = TCP_SKB_CB(skb)->end_seq
- tp->snd_una;
tcp_rate_skb_sent(sk, skb);
if (unlikely(skb_cloned(skb)))
skb = pskb_copy(skb, gfp_mask);
else
skb = skb_clone(skb, gfp_mask);
if (unlikely(!skb))
return -ENOBUFS;
}
inet = inet_sk(sk);
tcb = TCP_SKB_CB(skb);
memset(&opts, 0, sizeof(opts));
if (unlikely(tcb->tcp_flags & TCPHDR_SYN))
tcp_options_size = tcp_syn_options(sk, skb, &opts, &md5);
else
tcp_options_size = tcp_established_options(sk, skb, &opts,
&md5);
tcp_header_size = tcp_options_size + sizeof(struct tcphdr);
skb->ooo_okay = sk_wmem_alloc_get(sk) < SKB_TRUESIZE(1);
skb_push(skb, tcp_header_size);
skb_reset_transport_header(skb);
skb_orphan(skb);
skb->sk = sk;
skb->destructor = skb_is_tcp_pure_ack(skb) ? __sock_wfree : tcp_wfree;
skb_set_hash_from_sk(skb, sk);
atomic_add(skb->truesize, &sk->sk_wmem_alloc);
th = (struct tcphdr *)skb->data;
th->source = inet->inet_sport;
th->dest = inet->inet_dport;
th->seq = htonl(tcb->seq);
th->ack_seq = htonl(tp->rcv_nxt);
*(((__be16 *)th) + 6) = htons(((tcp_header_size >> 2) << 12) |
tcb->tcp_flags);
th->check = 0;
th->urg_ptr = 0;
if (unlikely(tcp_urg_mode(tp) && before(tcb->seq, tp->snd_up))) {
if (before(tp->snd_up, tcb->seq + 0x10000)) {
th->urg_ptr = htons(tp->snd_up - tcb->seq);
th->urg = 1;
} else if (after(tcb->seq + 0xFFFF, tp->snd_nxt)) {
th->urg_ptr = htons(0xFFFF);
th->urg = 1;
}
}
tcp_options_write((__be32 *)(th + 1), tp, &opts);
skb_shinfo(skb)->gso_type = sk->sk_gso_type;
if (likely(!(tcb->tcp_flags & TCPHDR_SYN))) {
th->window = htons(tcp_select_window(sk));
tcp_ecn_send(sk, skb, th, tcp_header_size);
} else {
th->window = htons(min(tp->rcv_wnd, 65535U));
}
#ifdef CONFIG_TCP_MD5SIG
if (md5) {
sk_nocaps_add(sk, NETIF_F_GSO_MASK);
tp->af_specific->calc_md5_hash(opts.hash_location,
md5, sk, skb);
}
#endif
icsk->icsk_af_ops->send_check(sk, skb);
if (likely(tcb->tcp_flags & TCPHDR_ACK))
tcp_event_ack_sent(sk, tcp_skb_pcount(skb));
if (skb->len != tcp_header_size) {
tcp_event_data_sent(tp, sk);
tp->data_segs_out += tcp_skb_pcount(skb);
}
if (after(tcb->end_seq, tp->snd_nxt) || tcb->seq == tcb->end_seq)
TCP_ADD_STATS(sock_net(sk), TCP_MIB_OUTSEGS,
tcp_skb_pcount(skb));
tp->segs_out += tcp_skb_pcount(skb);
skb_shinfo(skb)->gso_segs = tcp_skb_pcount(skb);
skb_shinfo(skb)->gso_size = tcp_skb_mss(skb);
skb->tstamp = 0;
memset(skb->cb, 0, max(sizeof(struct inet_skb_parm),
sizeof(struct inet6_skb_parm)));
err = icsk->icsk_af_ops->queue_xmit(sk, skb, &inet->cork.fl);
if (likely(err <= 0))
return err;
tcp_enter_cwr(sk);
return net_xmit_eval(err);
}
static void tcp_queue_skb(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
tp->write_seq = TCP_SKB_CB(skb)->end_seq;
__skb_header_release(skb);
tcp_add_write_queue_tail(sk, skb);
sk->sk_wmem_queued += skb->truesize;
sk_mem_charge(sk, skb->truesize);
}
static void tcp_set_skb_tso_segs(struct sk_buff *skb, unsigned int mss_now)
{
if (skb->len <= mss_now || skb->ip_summed == CHECKSUM_NONE) {
tcp_skb_pcount_set(skb, 1);
TCP_SKB_CB(skb)->tcp_gso_size = 0;
} else {
tcp_skb_pcount_set(skb, DIV_ROUND_UP(skb->len, mss_now));
TCP_SKB_CB(skb)->tcp_gso_size = mss_now;
}
}
static void tcp_adjust_fackets_out(struct sock *sk, const struct sk_buff *skb,
int decr)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tp->sacked_out || tcp_is_reno(tp))
return;
if (after(tcp_highest_sack_seq(tp), TCP_SKB_CB(skb)->seq))
tp->fackets_out -= decr;
}
static void tcp_adjust_pcount(struct sock *sk, const struct sk_buff *skb, int decr)
{
struct tcp_sock *tp = tcp_sk(sk);
tp->packets_out -= decr;
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED)
tp->sacked_out -= decr;
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_RETRANS)
tp->retrans_out -= decr;
if (TCP_SKB_CB(skb)->sacked & TCPCB_LOST)
tp->lost_out -= decr;
if (tcp_is_reno(tp) && decr > 0)
tp->sacked_out -= min_t(u32, tp->sacked_out, decr);
tcp_adjust_fackets_out(sk, skb, decr);
if (tp->lost_skb_hint &&
before(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(tp->lost_skb_hint)->seq) &&
(tcp_is_fack(tp) || (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED)))
tp->lost_cnt_hint -= decr;
tcp_verify_left_out(tp);
}
static bool tcp_has_tx_tstamp(const struct sk_buff *skb)
{
return TCP_SKB_CB(skb)->txstamp_ack ||
(skb_shinfo(skb)->tx_flags & SKBTX_ANY_TSTAMP);
}
static void tcp_fragment_tstamp(struct sk_buff *skb, struct sk_buff *skb2)
{
struct skb_shared_info *shinfo = skb_shinfo(skb);
if (unlikely(tcp_has_tx_tstamp(skb)) &&
!before(shinfo->tskey, TCP_SKB_CB(skb2)->seq)) {
struct skb_shared_info *shinfo2 = skb_shinfo(skb2);
u8 tsflags = shinfo->tx_flags & SKBTX_ANY_TSTAMP;
shinfo->tx_flags &= ~tsflags;
shinfo2->tx_flags |= tsflags;
swap(shinfo->tskey, shinfo2->tskey);
TCP_SKB_CB(skb2)->txstamp_ack = TCP_SKB_CB(skb)->txstamp_ack;
TCP_SKB_CB(skb)->txstamp_ack = 0;
}
}
static void tcp_skb_fragment_eor(struct sk_buff *skb, struct sk_buff *skb2)
{
TCP_SKB_CB(skb2)->eor = TCP_SKB_CB(skb)->eor;
TCP_SKB_CB(skb)->eor = 0;
}
int tcp_fragment(struct sock *sk, struct sk_buff *skb, u32 len,
unsigned int mss_now, gfp_t gfp)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *buff;
int nsize, old_factor;
int nlen;
u8 flags;
if (WARN_ON(len > skb->len))
return -EINVAL;
nsize = skb_headlen(skb) - len;
if (nsize < 0)
nsize = 0;
if (skb_unclone(skb, gfp))
return -ENOMEM;
buff = sk_stream_alloc_skb(sk, nsize, gfp, true);
if (!buff)
return -ENOMEM;
sk->sk_wmem_queued += buff->truesize;
sk_mem_charge(sk, buff->truesize);
nlen = skb->len - len - nsize;
buff->truesize += nlen;
skb->truesize -= nlen;
TCP_SKB_CB(buff)->seq = TCP_SKB_CB(skb)->seq + len;
TCP_SKB_CB(buff)->end_seq = TCP_SKB_CB(skb)->end_seq;
TCP_SKB_CB(skb)->end_seq = TCP_SKB_CB(buff)->seq;
flags = TCP_SKB_CB(skb)->tcp_flags;
TCP_SKB_CB(skb)->tcp_flags = flags & ~(TCPHDR_FIN | TCPHDR_PSH);
TCP_SKB_CB(buff)->tcp_flags = flags;
TCP_SKB_CB(buff)->sacked = TCP_SKB_CB(skb)->sacked;
tcp_skb_fragment_eor(skb, buff);
if (!skb_shinfo(skb)->nr_frags && skb->ip_summed != CHECKSUM_PARTIAL) {
buff->csum = csum_partial_copy_nocheck(skb->data + len,
skb_put(buff, nsize),
nsize, 0);
skb_trim(skb, len);
skb->csum = csum_block_sub(skb->csum, buff->csum, len);
} else {
skb->ip_summed = CHECKSUM_PARTIAL;
skb_split(skb, buff, len);
}
buff->ip_summed = skb->ip_summed;
buff->tstamp = skb->tstamp;
tcp_fragment_tstamp(skb, buff);
old_factor = tcp_skb_pcount(skb);
tcp_set_skb_tso_segs(skb, mss_now);
tcp_set_skb_tso_segs(buff, mss_now);
TCP_SKB_CB(buff)->tx = TCP_SKB_CB(skb)->tx;
if (!before(tp->snd_nxt, TCP_SKB_CB(buff)->end_seq)) {
int diff = old_factor - tcp_skb_pcount(skb) -
tcp_skb_pcount(buff);
if (diff)
tcp_adjust_pcount(sk, skb, diff);
}
__skb_header_release(buff);
tcp_insert_write_queue_after(skb, buff, sk);
return 0;
}
static void __pskb_trim_head(struct sk_buff *skb, int len)
{
struct skb_shared_info *shinfo;
int i, k, eat;
eat = min_t(int, len, skb_headlen(skb));
if (eat) {
__skb_pull(skb, eat);
len -= eat;
if (!len)
return;
}
eat = len;
k = 0;
shinfo = skb_shinfo(skb);
for (i = 0; i < shinfo->nr_frags; i++) {
int size = skb_frag_size(&shinfo->frags[i]);
if (size <= eat) {
skb_frag_unref(skb, i);
eat -= size;
} else {
shinfo->frags[k] = shinfo->frags[i];
if (eat) {
shinfo->frags[k].page_offset += eat;
skb_frag_size_sub(&shinfo->frags[k], eat);
eat = 0;
}
k++;
}
}
shinfo->nr_frags = k;
skb_reset_tail_pointer(skb);
skb->data_len -= len;
skb->len = skb->data_len;
}
int tcp_trim_head(struct sock *sk, struct sk_buff *skb, u32 len)
{
if (skb_unclone(skb, GFP_ATOMIC))
return -ENOMEM;
__pskb_trim_head(skb, len);
TCP_SKB_CB(skb)->seq += len;
skb->ip_summed = CHECKSUM_PARTIAL;
skb->truesize -= len;
sk->sk_wmem_queued -= len;
sk_mem_uncharge(sk, len);
sock_set_flag(sk, SOCK_QUEUE_SHRUNK);
if (tcp_skb_pcount(skb) > 1)
tcp_set_skb_tso_segs(skb, tcp_skb_mss(skb));
return 0;
}
static inline int __tcp_mtu_to_mss(struct sock *sk, int pmtu)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct inet_connection_sock *icsk = inet_csk(sk);
int mss_now;
mss_now = pmtu - icsk->icsk_af_ops->net_header_len - sizeof(struct tcphdr);
if (icsk->icsk_af_ops->net_frag_header_len) {
const struct dst_entry *dst = __sk_dst_get(sk);
if (dst && dst_allfrag(dst))
mss_now -= icsk->icsk_af_ops->net_frag_header_len;
}
if (mss_now > tp->rx_opt.mss_clamp)
mss_now = tp->rx_opt.mss_clamp;
mss_now -= icsk->icsk_ext_hdr_len;
if (mss_now < 48)
mss_now = 48;
return mss_now;
}
int tcp_mtu_to_mss(struct sock *sk, int pmtu)
{
return __tcp_mtu_to_mss(sk, pmtu) -
(tcp_sk(sk)->tcp_header_len - sizeof(struct tcphdr));
}
int tcp_mss_to_mtu(struct sock *sk, int mss)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct inet_connection_sock *icsk = inet_csk(sk);
int mtu;
mtu = mss +
tp->tcp_header_len +
icsk->icsk_ext_hdr_len +
icsk->icsk_af_ops->net_header_len;
if (icsk->icsk_af_ops->net_frag_header_len) {
const struct dst_entry *dst = __sk_dst_get(sk);
if (dst && dst_allfrag(dst))
mtu += icsk->icsk_af_ops->net_frag_header_len;
}
return mtu;
}
void tcp_mtup_init(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
struct net *net = sock_net(sk);
icsk->icsk_mtup.enabled = net->ipv4.sysctl_tcp_mtu_probing > 1;
icsk->icsk_mtup.search_high = tp->rx_opt.mss_clamp + sizeof(struct tcphdr) +
icsk->icsk_af_ops->net_header_len;
icsk->icsk_mtup.search_low = tcp_mss_to_mtu(sk, net->ipv4.sysctl_tcp_base_mss);
icsk->icsk_mtup.probe_size = 0;
if (icsk->icsk_mtup.enabled)
icsk->icsk_mtup.probe_timestamp = tcp_time_stamp;
}
unsigned int tcp_sync_mss(struct sock *sk, u32 pmtu)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
int mss_now;
if (icsk->icsk_mtup.search_high > pmtu)
icsk->icsk_mtup.search_high = pmtu;
mss_now = tcp_mtu_to_mss(sk, pmtu);
mss_now = tcp_bound_to_half_wnd(tp, mss_now);
icsk->icsk_pmtu_cookie = pmtu;
if (icsk->icsk_mtup.enabled)
mss_now = min(mss_now, tcp_mtu_to_mss(sk, icsk->icsk_mtup.search_low));
tp->mss_cache = mss_now;
return mss_now;
}
unsigned int tcp_current_mss(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct dst_entry *dst = __sk_dst_get(sk);
u32 mss_now;
unsigned int header_len;
struct tcp_out_options opts;
struct tcp_md5sig_key *md5;
mss_now = tp->mss_cache;
if (dst) {
u32 mtu = dst_mtu(dst);
if (mtu != inet_csk(sk)->icsk_pmtu_cookie)
mss_now = tcp_sync_mss(sk, mtu);
}
header_len = tcp_established_options(sk, NULL, &opts, &md5) +
sizeof(struct tcphdr);
if (header_len != tp->tcp_header_len) {
int delta = (int) header_len - tp->tcp_header_len;
mss_now -= delta;
}
return mss_now;
}
static void tcp_cwnd_application_limited(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (inet_csk(sk)->icsk_ca_state == TCP_CA_Open &&
sk->sk_socket && !test_bit(SOCK_NOSPACE, &sk->sk_socket->flags)) {
u32 init_win = tcp_init_cwnd(tp, __sk_dst_get(sk));
u32 win_used = max(tp->snd_cwnd_used, init_win);
if (win_used < tp->snd_cwnd) {
tp->snd_ssthresh = tcp_current_ssthresh(sk);
tp->snd_cwnd = (tp->snd_cwnd + win_used) >> 1;
}
tp->snd_cwnd_used = 0;
}
tp->snd_cwnd_stamp = tcp_time_stamp;
}
static void tcp_cwnd_validate(struct sock *sk, bool is_cwnd_limited)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!before(tp->snd_una, tp->max_packets_seq) ||
tp->packets_out > tp->max_packets_out) {
tp->max_packets_out = tp->packets_out;
tp->max_packets_seq = tp->snd_nxt;
tp->is_cwnd_limited = is_cwnd_limited;
}
if (tcp_is_cwnd_limited(sk)) {
tp->snd_cwnd_used = 0;
tp->snd_cwnd_stamp = tcp_time_stamp;
} else {
if (tp->packets_out > tp->snd_cwnd_used)
tp->snd_cwnd_used = tp->packets_out;
if (sysctl_tcp_slow_start_after_idle &&
(s32)(tcp_time_stamp - tp->snd_cwnd_stamp) >= inet_csk(sk)->icsk_rto)
tcp_cwnd_application_limited(sk);
if (!tcp_send_head(sk) && sk->sk_socket &&
test_bit(SOCK_NOSPACE, &sk->sk_socket->flags) &&
(1 << sk->sk_state) & (TCPF_ESTABLISHED | TCPF_CLOSE_WAIT))
tcp_chrono_start(sk, TCP_CHRONO_SNDBUF_LIMITED);
}
}
static bool tcp_minshall_check(const struct tcp_sock *tp)
{
return after(tp->snd_sml, tp->snd_una) &&
!after(tp->snd_sml, tp->snd_nxt);
}
static void tcp_minshall_update(struct tcp_sock *tp, unsigned int mss_now,
const struct sk_buff *skb)
{
if (skb->len < tcp_skb_pcount(skb) * mss_now)
tp->snd_sml = TCP_SKB_CB(skb)->end_seq;
}
static bool tcp_nagle_check(bool partial, const struct tcp_sock *tp,
int nonagle)
{
return partial &&
((nonagle & TCP_NAGLE_CORK) ||
(!nonagle && tp->packets_out && tcp_minshall_check(tp)));
}
u32 tcp_tso_autosize(const struct sock *sk, unsigned int mss_now,
int min_tso_segs)
{
u32 bytes, segs;
bytes = min(sk->sk_pacing_rate >> 10,
sk->sk_gso_max_size - 1 - MAX_TCP_HEADER);
segs = max_t(u32, bytes / mss_now, min_tso_segs);
return min_t(u32, segs, sk->sk_gso_max_segs);
}
static u32 tcp_tso_segs(struct sock *sk, unsigned int mss_now)
{
const struct tcp_congestion_ops *ca_ops = inet_csk(sk)->icsk_ca_ops;
u32 tso_segs = ca_ops->tso_segs_goal ? ca_ops->tso_segs_goal(sk) : 0;
return tso_segs ? :
tcp_tso_autosize(sk, mss_now, sysctl_tcp_min_tso_segs);
}
static unsigned int tcp_mss_split_point(const struct sock *sk,
const struct sk_buff *skb,
unsigned int mss_now,
unsigned int max_segs,
int nonagle)
{
const struct tcp_sock *tp = tcp_sk(sk);
u32 partial, needed, window, max_len;
window = tcp_wnd_end(tp) - TCP_SKB_CB(skb)->seq;
max_len = mss_now * max_segs;
if (likely(max_len <= window && skb != tcp_write_queue_tail(sk)))
return max_len;
needed = min(skb->len, window);
if (max_len <= needed)
return max_len;
partial = needed % mss_now;
if (tcp_nagle_check(partial != 0, tp, nonagle))
return needed - partial;
return needed;
}
static inline unsigned int tcp_cwnd_test(const struct tcp_sock *tp,
const struct sk_buff *skb)
{
u32 in_flight, cwnd, halfcwnd;
if ((TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN) &&
tcp_skb_pcount(skb) == 1)
return 1;
in_flight = tcp_packets_in_flight(tp);
cwnd = tp->snd_cwnd;
if (in_flight >= cwnd)
return 0;
halfcwnd = max(cwnd >> 1, 1U);
return min(halfcwnd, cwnd - in_flight);
}
static int tcp_init_tso_segs(struct sk_buff *skb, unsigned int mss_now)
{
int tso_segs = tcp_skb_pcount(skb);
if (!tso_segs || (tso_segs > 1 && tcp_skb_mss(skb) != mss_now)) {
tcp_set_skb_tso_segs(skb, mss_now);
tso_segs = tcp_skb_pcount(skb);
}
return tso_segs;
}
static inline bool tcp_nagle_test(const struct tcp_sock *tp, const struct sk_buff *skb,
unsigned int cur_mss, int nonagle)
{
if (nonagle & TCP_NAGLE_PUSH)
return true;
if (tcp_urg_mode(tp) || (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN))
return true;
if (!tcp_nagle_check(skb->len < cur_mss, tp, nonagle))
return true;
return false;
}
static bool tcp_snd_wnd_test(const struct tcp_sock *tp,
const struct sk_buff *skb,
unsigned int cur_mss)
{
u32 end_seq = TCP_SKB_CB(skb)->end_seq;
if (skb->len > cur_mss)
end_seq = TCP_SKB_CB(skb)->seq + cur_mss;
return !after(end_seq, tcp_wnd_end(tp));
}
static unsigned int tcp_snd_test(const struct sock *sk, struct sk_buff *skb,
unsigned int cur_mss, int nonagle)
{
const struct tcp_sock *tp = tcp_sk(sk);
unsigned int cwnd_quota;
tcp_init_tso_segs(skb, cur_mss);
if (!tcp_nagle_test(tp, skb, cur_mss, nonagle))
return 0;
cwnd_quota = tcp_cwnd_test(tp, skb);
if (cwnd_quota && !tcp_snd_wnd_test(tp, skb, cur_mss))
cwnd_quota = 0;
return cwnd_quota;
}
bool tcp_may_send_now(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb = tcp_send_head(sk);
return skb &&
tcp_snd_test(sk, skb, tcp_current_mss(sk),
(tcp_skb_is_last(sk, skb) ?
tp->nonagle : TCP_NAGLE_PUSH));
}
static int tso_fragment(struct sock *sk, struct sk_buff *skb, unsigned int len,
unsigned int mss_now, gfp_t gfp)
{
struct sk_buff *buff;
int nlen = skb->len - len;
u8 flags;
if (skb->len != skb->data_len)
return tcp_fragment(sk, skb, len, mss_now, gfp);
buff = sk_stream_alloc_skb(sk, 0, gfp, true);
if (unlikely(!buff))
return -ENOMEM;
sk->sk_wmem_queued += buff->truesize;
sk_mem_charge(sk, buff->truesize);
buff->truesize += nlen;
skb->truesize -= nlen;
TCP_SKB_CB(buff)->seq = TCP_SKB_CB(skb)->seq + len;
TCP_SKB_CB(buff)->end_seq = TCP_SKB_CB(skb)->end_seq;
TCP_SKB_CB(skb)->end_seq = TCP_SKB_CB(buff)->seq;
flags = TCP_SKB_CB(skb)->tcp_flags;
TCP_SKB_CB(skb)->tcp_flags = flags & ~(TCPHDR_FIN | TCPHDR_PSH);
TCP_SKB_CB(buff)->tcp_flags = flags;
TCP_SKB_CB(buff)->sacked = 0;
tcp_skb_fragment_eor(skb, buff);
buff->ip_summed = skb->ip_summed = CHECKSUM_PARTIAL;
skb_split(skb, buff, len);
tcp_fragment_tstamp(skb, buff);
tcp_set_skb_tso_segs(skb, mss_now);
tcp_set_skb_tso_segs(buff, mss_now);
__skb_header_release(buff);
tcp_insert_write_queue_after(skb, buff, sk);
return 0;
}
static bool tcp_tso_should_defer(struct sock *sk, struct sk_buff *skb,
bool *is_cwnd_limited, u32 max_segs)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
u32 age, send_win, cong_win, limit, in_flight;
struct tcp_sock *tp = tcp_sk(sk);
struct skb_mstamp now;
struct sk_buff *head;
int win_divisor;
if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN)
goto send_now;
if (icsk->icsk_ca_state >= TCP_CA_Recovery)
goto send_now;
if ((s32)(tcp_time_stamp - tp->lsndtime) > 0)
goto send_now;
in_flight = tcp_packets_in_flight(tp);
BUG_ON(tcp_skb_pcount(skb) <= 1 || (tp->snd_cwnd <= in_flight));
send_win = tcp_wnd_end(tp) - TCP_SKB_CB(skb)->seq;
cong_win = (tp->snd_cwnd - in_flight) * tp->mss_cache;
limit = min(send_win, cong_win);
if (limit >= max_segs * tp->mss_cache)
goto send_now;
if ((skb != tcp_write_queue_tail(sk)) && (limit >= skb->len))
goto send_now;
win_divisor = ACCESS_ONCE(sysctl_tcp_tso_win_divisor);
if (win_divisor) {
u32 chunk = min(tp->snd_wnd, tp->snd_cwnd * tp->mss_cache);
chunk /= win_divisor;
if (limit >= chunk)
goto send_now;
} else {
if (limit > tcp_max_tso_deferred_mss(tp) * tp->mss_cache)
goto send_now;
}
head = tcp_write_queue_head(sk);
skb_mstamp_get(&now);
age = skb_mstamp_us_delta(&now, &head->skb_mstamp);
if (age < (tp->srtt_us >> 4))
goto send_now;
if (cong_win < send_win && cong_win <= skb->len)
*is_cwnd_limited = true;
return true;
send_now:
return false;
}
static inline void tcp_mtu_check_reprobe(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
u32 interval;
s32 delta;
interval = net->ipv4.sysctl_tcp_probe_interval;
delta = tcp_time_stamp - icsk->icsk_mtup.probe_timestamp;
if (unlikely(delta >= interval * HZ)) {
int mss = tcp_current_mss(sk);
icsk->icsk_mtup.probe_size = 0;
icsk->icsk_mtup.search_high = tp->rx_opt.mss_clamp +
sizeof(struct tcphdr) +
icsk->icsk_af_ops->net_header_len;
icsk->icsk_mtup.search_low = tcp_mss_to_mtu(sk, mss);
icsk->icsk_mtup.probe_timestamp = tcp_time_stamp;
}
}
static int tcp_mtu_probe(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb, *nskb, *next;
struct net *net = sock_net(sk);
int probe_size;
int size_needed;
int copy, len;
int mss_now;
int interval;
if (likely(!icsk->icsk_mtup.enabled ||
icsk->icsk_mtup.probe_size ||
inet_csk(sk)->icsk_ca_state != TCP_CA_Open ||
tp->snd_cwnd < 11 ||
tp->rx_opt.num_sacks || tp->rx_opt.dsack))
return -1;
mss_now = tcp_current_mss(sk);
probe_size = tcp_mtu_to_mss(sk, (icsk->icsk_mtup.search_high +
icsk->icsk_mtup.search_low) >> 1);
size_needed = probe_size + (tp->reordering + 1) * tp->mss_cache;
interval = icsk->icsk_mtup.search_high - icsk->icsk_mtup.search_low;
if (probe_size > tcp_mtu_to_mss(sk, icsk->icsk_mtup.search_high) ||
interval < net->ipv4.sysctl_tcp_probe_threshold) {
tcp_mtu_check_reprobe(sk);
return -1;
}
if (tp->write_seq - tp->snd_nxt < size_needed)
return -1;
if (tp->snd_wnd < size_needed)
return -1;
if (after(tp->snd_nxt + size_needed, tcp_wnd_end(tp)))
return 0;
if (tcp_packets_in_flight(tp) + 2 > tp->snd_cwnd) {
if (!tcp_packets_in_flight(tp))
return -1;
else
return 0;
}
nskb = sk_stream_alloc_skb(sk, probe_size, GFP_ATOMIC, false);
if (!nskb)
return -1;
sk->sk_wmem_queued += nskb->truesize;
sk_mem_charge(sk, nskb->truesize);
skb = tcp_send_head(sk);
TCP_SKB_CB(nskb)->seq = TCP_SKB_CB(skb)->seq;
TCP_SKB_CB(nskb)->end_seq = TCP_SKB_CB(skb)->seq + probe_size;
TCP_SKB_CB(nskb)->tcp_flags = TCPHDR_ACK;
TCP_SKB_CB(nskb)->sacked = 0;
nskb->csum = 0;
nskb->ip_summed = skb->ip_summed;
tcp_insert_write_queue_before(nskb, skb, sk);
len = 0;
tcp_for_write_queue_from_safe(skb, next, sk) {
copy = min_t(int, skb->len, probe_size - len);
if (nskb->ip_summed) {
skb_copy_bits(skb, 0, skb_put(nskb, copy), copy);
} else {
__wsum csum = skb_copy_and_csum_bits(skb, 0,
skb_put(nskb, copy),
copy, 0);
nskb->csum = csum_block_add(nskb->csum, csum, len);
}
if (skb->len <= copy) {
TCP_SKB_CB(nskb)->tcp_flags |= TCP_SKB_CB(skb)->tcp_flags;
tcp_unlink_write_queue(skb, sk);
sk_wmem_free_skb(sk, skb);
} else {
TCP_SKB_CB(nskb)->tcp_flags |= TCP_SKB_CB(skb)->tcp_flags &
~(TCPHDR_FIN|TCPHDR_PSH);
if (!skb_shinfo(skb)->nr_frags) {
skb_pull(skb, copy);
if (skb->ip_summed != CHECKSUM_PARTIAL)
skb->csum = csum_partial(skb->data,
skb->len, 0);
} else {
__pskb_trim_head(skb, copy);
tcp_set_skb_tso_segs(skb, mss_now);
}
TCP_SKB_CB(skb)->seq += copy;
}
len += copy;
if (len >= probe_size)
break;
}
tcp_init_tso_segs(nskb, nskb->len);
if (!tcp_transmit_skb(sk, nskb, 1, GFP_ATOMIC)) {
tp->snd_cwnd--;
tcp_event_new_data_sent(sk, nskb);
icsk->icsk_mtup.probe_size = tcp_mss_to_mtu(sk, nskb->len);
tp->mtu_probe.probe_seq_start = TCP_SKB_CB(nskb)->seq;
tp->mtu_probe.probe_seq_end = TCP_SKB_CB(nskb)->end_seq;
return 1;
}
return -1;
}
static bool tcp_small_queue_check(struct sock *sk, const struct sk_buff *skb,
unsigned int factor)
{
unsigned int limit;
limit = max(2 * skb->truesize, sk->sk_pacing_rate >> 10);
limit = min_t(u32, limit, sysctl_tcp_limit_output_bytes);
limit <<= factor;
if (atomic_read(&sk->sk_wmem_alloc) > limit) {
if (skb == sk->sk_write_queue.next ||
skb->prev == sk->sk_write_queue.next)
return false;
set_bit(TSQ_THROTTLED, &sk->sk_tsq_flags);
smp_mb__after_atomic();
if (atomic_read(&sk->sk_wmem_alloc) > limit)
return true;
}
return false;
}
static void tcp_chrono_set(struct tcp_sock *tp, const enum tcp_chrono new)
{
const u32 now = tcp_time_stamp;
if (tp->chrono_type > TCP_CHRONO_UNSPEC)
tp->chrono_stat[tp->chrono_type - 1] += now - tp->chrono_start;
tp->chrono_start = now;
tp->chrono_type = new;
}
void tcp_chrono_start(struct sock *sk, const enum tcp_chrono type)
{
struct tcp_sock *tp = tcp_sk(sk);
if (type > tp->chrono_type)
tcp_chrono_set(tp, type);
}
void tcp_chrono_stop(struct sock *sk, const enum tcp_chrono type)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_write_queue_empty(sk))
tcp_chrono_set(tp, TCP_CHRONO_UNSPEC);
else if (type == tp->chrono_type)
tcp_chrono_set(tp, TCP_CHRONO_BUSY);
}
static bool tcp_write_xmit(struct sock *sk, unsigned int mss_now, int nonagle,
int push_one, gfp_t gfp)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
unsigned int tso_segs, sent_pkts;
int cwnd_quota;
int result;
bool is_cwnd_limited = false, is_rwnd_limited = false;
u32 max_segs;
sent_pkts = 0;
if (!push_one) {
result = tcp_mtu_probe(sk);
if (!result) {
return false;
} else if (result > 0) {
sent_pkts = 1;
}
}
max_segs = tcp_tso_segs(sk, mss_now);
while ((skb = tcp_send_head(sk))) {
unsigned int limit;
tso_segs = tcp_init_tso_segs(skb, mss_now);
BUG_ON(!tso_segs);
if (unlikely(tp->repair) && tp->repair_queue == TCP_SEND_QUEUE) {
skb_mstamp_get(&skb->skb_mstamp);
goto repair;
}
cwnd_quota = tcp_cwnd_test(tp, skb);
if (!cwnd_quota) {
if (push_one == 2)
cwnd_quota = 1;
else
break;
}
if (unlikely(!tcp_snd_wnd_test(tp, skb, mss_now))) {
is_rwnd_limited = true;
break;
}
if (tso_segs == 1) {
if (unlikely(!tcp_nagle_test(tp, skb, mss_now,
(tcp_skb_is_last(sk, skb) ?
nonagle : TCP_NAGLE_PUSH))))
break;
} else {
if (!push_one &&
tcp_tso_should_defer(sk, skb, &is_cwnd_limited,
max_segs))
break;
}
limit = mss_now;
if (tso_segs > 1 && !tcp_urg_mode(tp))
limit = tcp_mss_split_point(sk, skb, mss_now,
min_t(unsigned int,
cwnd_quota,
max_segs),
nonagle);
if (skb->len > limit &&
unlikely(tso_fragment(sk, skb, limit, mss_now, gfp)))
break;
if (test_bit(TCP_TSQ_DEFERRED, &sk->sk_tsq_flags))
clear_bit(TCP_TSQ_DEFERRED, &sk->sk_tsq_flags);
if (tcp_small_queue_check(sk, skb, 0))
break;
if (unlikely(tcp_transmit_skb(sk, skb, 1, gfp)))
break;
repair:
tcp_event_new_data_sent(sk, skb);
tcp_minshall_update(tp, mss_now, skb);
sent_pkts += tcp_skb_pcount(skb);
if (push_one)
break;
}
if (is_rwnd_limited)
tcp_chrono_start(sk, TCP_CHRONO_RWND_LIMITED);
else
tcp_chrono_stop(sk, TCP_CHRONO_RWND_LIMITED);
if (likely(sent_pkts)) {
if (tcp_in_cwnd_reduction(sk))
tp->prr_out += sent_pkts;
if (push_one != 2)
tcp_schedule_loss_probe(sk);
is_cwnd_limited |= (tcp_packets_in_flight(tp) >= tp->snd_cwnd);
tcp_cwnd_validate(sk, is_cwnd_limited);
return false;
}
return !tp->packets_out && tcp_send_head(sk);
}
bool tcp_schedule_loss_probe(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
u32 timeout, tlp_time_stamp, rto_time_stamp;
u32 rtt = usecs_to_jiffies(tp->srtt_us >> 3);
if (WARN_ON(icsk->icsk_pending == ICSK_TIME_EARLY_RETRANS))
return false;
if (WARN_ON(icsk->icsk_pending == ICSK_TIME_LOSS_PROBE)) {
tcp_rearm_rto(sk);
return false;
}
if (tp->fastopen_rsk)
return false;
if (icsk->icsk_pending != ICSK_TIME_RETRANS)
return false;
if (sysctl_tcp_early_retrans < 3 || !tp->packets_out ||
!tcp_is_sack(tp) || inet_csk(sk)->icsk_ca_state != TCP_CA_Open)
return false;
if ((tp->snd_cwnd > tcp_packets_in_flight(tp)) &&
tcp_send_head(sk))
return false;
timeout = rtt << 1 ? : TCP_TIMEOUT_INIT;
if (tp->packets_out == 1)
timeout = max_t(u32, timeout,
(rtt + (rtt >> 1) + TCP_DELACK_MAX));
timeout = max_t(u32, timeout, msecs_to_jiffies(10));
tlp_time_stamp = tcp_time_stamp + timeout;
rto_time_stamp = (u32)inet_csk(sk)->icsk_timeout;
if ((s32)(tlp_time_stamp - rto_time_stamp) > 0) {
s32 delta = rto_time_stamp - tcp_time_stamp;
if (delta > 0)
timeout = delta;
}
inet_csk_reset_xmit_timer(sk, ICSK_TIME_LOSS_PROBE, timeout,
TCP_RTO_MAX);
return true;
}
static bool skb_still_in_host_queue(const struct sock *sk,
const struct sk_buff *skb)
{
if (unlikely(skb_fclone_busy(sk, skb))) {
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPSPURIOUS_RTX_HOSTQUEUES);
return true;
}
return false;
}
void tcp_send_loss_probe(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
int pcount;
int mss = tcp_current_mss(sk);
skb = tcp_send_head(sk);
if (skb) {
if (tcp_snd_wnd_test(tp, skb, mss)) {
pcount = tp->packets_out;
tcp_write_xmit(sk, mss, TCP_NAGLE_OFF, 2, GFP_ATOMIC);
if (tp->packets_out > pcount)
goto probe_sent;
goto rearm_timer;
}
skb = tcp_write_queue_prev(sk, skb);
} else {
skb = tcp_write_queue_tail(sk);
}
if (tp->tlp_high_seq)
goto rearm_timer;
if (WARN_ON(!skb))
goto rearm_timer;
if (skb_still_in_host_queue(sk, skb))
goto rearm_timer;
pcount = tcp_skb_pcount(skb);
if (WARN_ON(!pcount))
goto rearm_timer;
if ((pcount > 1) && (skb->len > (pcount - 1) * mss)) {
if (unlikely(tcp_fragment(sk, skb, (pcount - 1) * mss, mss,
GFP_ATOMIC)))
goto rearm_timer;
skb = tcp_write_queue_next(sk, skb);
}
if (WARN_ON(!skb || !tcp_skb_pcount(skb)))
goto rearm_timer;
if (__tcp_retransmit_skb(sk, skb, 1))
goto rearm_timer;
tp->tlp_high_seq = tp->snd_nxt;
probe_sent:
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPLOSSPROBES);
inet_csk(sk)->icsk_pending = 0;
rearm_timer:
tcp_rearm_rto(sk);
}
void __tcp_push_pending_frames(struct sock *sk, unsigned int cur_mss,
int nonagle)
{
if (unlikely(sk->sk_state == TCP_CLOSE))
return;
if (tcp_write_xmit(sk, cur_mss, nonagle, 0,
sk_gfp_mask(sk, GFP_ATOMIC)))
tcp_check_probe_timer(sk);
}
void tcp_push_one(struct sock *sk, unsigned int mss_now)
{
struct sk_buff *skb = tcp_send_head(sk);
BUG_ON(!skb || skb->len < mss_now);
tcp_write_xmit(sk, mss_now, TCP_NAGLE_PUSH, 1, sk->sk_allocation);
}
u32 __tcp_select_window(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
int mss = icsk->icsk_ack.rcv_mss;
int free_space = tcp_space(sk);
int allowed_space = tcp_full_space(sk);
int full_space = min_t(int, tp->window_clamp, allowed_space);
int window;
if (unlikely(mss > full_space)) {
mss = full_space;
if (mss <= 0)
return 0;
}
if (free_space < (full_space >> 1)) {
icsk->icsk_ack.quick = 0;
if (tcp_under_memory_pressure(sk))
tp->rcv_ssthresh = min(tp->rcv_ssthresh,
4U * tp->advmss);
free_space = round_down(free_space, 1 << tp->rx_opt.rcv_wscale);
if (free_space < (allowed_space >> 4) || free_space < mss)
return 0;
}
if (free_space > tp->rcv_ssthresh)
free_space = tp->rcv_ssthresh;
window = tp->rcv_wnd;
if (tp->rx_opt.rcv_wscale) {
window = free_space;
if (((window >> tp->rx_opt.rcv_wscale) << tp->rx_opt.rcv_wscale) != window)
window = (((window >> tp->rx_opt.rcv_wscale) + 1)
<< tp->rx_opt.rcv_wscale);
} else {
if (window <= free_space - mss || window > free_space)
window = (free_space / mss) * mss;
else if (mss == full_space &&
free_space > window + (full_space >> 1))
window = free_space;
}
return window;
}
void tcp_skb_collapse_tstamp(struct sk_buff *skb,
const struct sk_buff *next_skb)
{
if (unlikely(tcp_has_tx_tstamp(next_skb))) {
const struct skb_shared_info *next_shinfo =
skb_shinfo(next_skb);
struct skb_shared_info *shinfo = skb_shinfo(skb);
shinfo->tx_flags |= next_shinfo->tx_flags & SKBTX_ANY_TSTAMP;
shinfo->tskey = next_shinfo->tskey;
TCP_SKB_CB(skb)->txstamp_ack |=
TCP_SKB_CB(next_skb)->txstamp_ack;
}
}
static bool tcp_collapse_retrans(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *next_skb = tcp_write_queue_next(sk, skb);
int skb_size, next_skb_size;
skb_size = skb->len;
next_skb_size = next_skb->len;
BUG_ON(tcp_skb_pcount(skb) != 1 || tcp_skb_pcount(next_skb) != 1);
if (next_skb_size) {
if (next_skb_size <= skb_availroom(skb))
skb_copy_bits(next_skb, 0, skb_put(skb, next_skb_size),
next_skb_size);
else if (!skb_shift(skb, next_skb, next_skb_size))
return false;
}
tcp_highest_sack_combine(sk, next_skb, skb);
tcp_unlink_write_queue(next_skb, sk);
if (next_skb->ip_summed == CHECKSUM_PARTIAL)
skb->ip_summed = CHECKSUM_PARTIAL;
if (skb->ip_summed != CHECKSUM_PARTIAL)
skb->csum = csum_block_add(skb->csum, next_skb->csum, skb_size);
TCP_SKB_CB(skb)->end_seq = TCP_SKB_CB(next_skb)->end_seq;
TCP_SKB_CB(skb)->tcp_flags |= TCP_SKB_CB(next_skb)->tcp_flags;
TCP_SKB_CB(skb)->sacked |= TCP_SKB_CB(next_skb)->sacked & TCPCB_EVER_RETRANS;
TCP_SKB_CB(skb)->eor = TCP_SKB_CB(next_skb)->eor;
tcp_clear_retrans_hints_partial(tp);
if (next_skb == tp->retransmit_skb_hint)
tp->retransmit_skb_hint = skb;
tcp_adjust_pcount(sk, next_skb, tcp_skb_pcount(next_skb));
tcp_skb_collapse_tstamp(skb, next_skb);
sk_wmem_free_skb(sk, next_skb);
return true;
}
static bool tcp_can_collapse(const struct sock *sk, const struct sk_buff *skb)
{
if (tcp_skb_pcount(skb) > 1)
return false;
if (skb_cloned(skb))
return false;
if (skb == tcp_send_head(sk))
return false;
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED)
return false;
return true;
}
static void tcp_retrans_try_collapse(struct sock *sk, struct sk_buff *to,
int space)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb = to, *tmp;
bool first = true;
if (!sysctl_tcp_retrans_collapse)
return;
if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_SYN)
return;
tcp_for_write_queue_from_safe(skb, tmp, sk) {
if (!tcp_can_collapse(sk, skb))
break;
if (!tcp_skb_can_collapse_to(to))
break;
space -= skb->len;
if (first) {
first = false;
continue;
}
if (space < 0)
break;
if (after(TCP_SKB_CB(skb)->end_seq, tcp_wnd_end(tp)))
break;
if (!tcp_collapse_retrans(sk, to))
break;
}
}
int __tcp_retransmit_skb(struct sock *sk, struct sk_buff *skb, int segs)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
unsigned int cur_mss;
int diff, len, err;
if (icsk->icsk_mtup.probe_size)
icsk->icsk_mtup.probe_size = 0;
if (atomic_read(&sk->sk_wmem_alloc) >
min_t(u32, sk->sk_wmem_queued + (sk->sk_wmem_queued >> 2),
sk->sk_sndbuf))
return -EAGAIN;
if (skb_still_in_host_queue(sk, skb))
return -EBUSY;
if (before(TCP_SKB_CB(skb)->seq, tp->snd_una)) {
if (before(TCP_SKB_CB(skb)->end_seq, tp->snd_una))
BUG();
if (tcp_trim_head(sk, skb, tp->snd_una - TCP_SKB_CB(skb)->seq))
return -ENOMEM;
}
if (inet_csk(sk)->icsk_af_ops->rebuild_header(sk))
return -EHOSTUNREACH;
cur_mss = tcp_current_mss(sk);
if (!before(TCP_SKB_CB(skb)->seq, tcp_wnd_end(tp)) &&
TCP_SKB_CB(skb)->seq != tp->snd_una)
return -EAGAIN;
len = cur_mss * segs;
if (skb->len > len) {
if (tcp_fragment(sk, skb, len, cur_mss, GFP_ATOMIC))
return -ENOMEM;
} else {
if (skb_unclone(skb, GFP_ATOMIC))
return -ENOMEM;
diff = tcp_skb_pcount(skb);
tcp_set_skb_tso_segs(skb, cur_mss);
diff -= tcp_skb_pcount(skb);
if (diff)
tcp_adjust_pcount(sk, skb, diff);
if (skb->len < cur_mss)
tcp_retrans_try_collapse(sk, skb, cur_mss);
}
if ((TCP_SKB_CB(skb)->tcp_flags & TCPHDR_SYN_ECN) == TCPHDR_SYN_ECN)
tcp_ecn_clear_syn(sk, skb);
if (unlikely((NET_IP_ALIGN && ((unsigned long)skb->data & 3)) ||
skb_headroom(skb) >= 0xFFFF)) {
struct sk_buff *nskb;
skb_mstamp_get(&skb->skb_mstamp);
nskb = __pskb_copy(skb, MAX_TCP_HEADER, GFP_ATOMIC);
err = nskb ? tcp_transmit_skb(sk, nskb, 0, GFP_ATOMIC) :
-ENOBUFS;
} else {
err = tcp_transmit_skb(sk, skb, 1, GFP_ATOMIC);
}
if (likely(!err)) {
segs = tcp_skb_pcount(skb);
TCP_SKB_CB(skb)->sacked |= TCPCB_EVER_RETRANS;
TCP_ADD_STATS(sock_net(sk), TCP_MIB_RETRANSSEGS, segs);
if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_SYN)
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPSYNRETRANS);
tp->total_retrans += segs;
}
return err;
}
int tcp_retransmit_skb(struct sock *sk, struct sk_buff *skb, int segs)
{
struct tcp_sock *tp = tcp_sk(sk);
int err = __tcp_retransmit_skb(sk, skb, segs);
if (err == 0) {
#if FASTRETRANS_DEBUG > 0
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_RETRANS) {
net_dbg_ratelimited("retrans_out leaked\n");
}
#endif
TCP_SKB_CB(skb)->sacked |= TCPCB_RETRANS;
tp->retrans_out += tcp_skb_pcount(skb);
if (!tp->retrans_stamp)
tp->retrans_stamp = tcp_skb_timestamp(skb);
} else if (err != -EBUSY) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPRETRANSFAIL);
}
if (tp->undo_retrans < 0)
tp->undo_retrans = 0;
tp->undo_retrans += tcp_skb_pcount(skb);
return err;
}
static bool tcp_can_forward_retransmit(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
const struct tcp_sock *tp = tcp_sk(sk);
if (icsk->icsk_ca_state != TCP_CA_Recovery)
return false;
if (tcp_is_reno(tp))
return false;
if (tcp_may_send_now(sk))
return false;
return true;
}
void tcp_xmit_retransmit_queue(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
struct sk_buff *hole = NULL;
u32 max_segs, last_lost;
int mib_idx;
int fwd_rexmitting = 0;
if (!tp->packets_out)
return;
if (!tp->lost_out)
tp->retransmit_high = tp->snd_una;
if (tp->retransmit_skb_hint) {
skb = tp->retransmit_skb_hint;
last_lost = TCP_SKB_CB(skb)->end_seq;
if (after(last_lost, tp->retransmit_high))
last_lost = tp->retransmit_high;
} else {
skb = tcp_write_queue_head(sk);
last_lost = tp->snd_una;
}
max_segs = tcp_tso_segs(sk, tcp_current_mss(sk));
tcp_for_write_queue_from(skb, sk) {
__u8 sacked;
int segs;
if (skb == tcp_send_head(sk))
break;
if (!hole)
tp->retransmit_skb_hint = skb;
segs = tp->snd_cwnd - tcp_packets_in_flight(tp);
if (segs <= 0)
return;
sacked = TCP_SKB_CB(skb)->sacked;
segs = min_t(int, segs, max_segs);
if (fwd_rexmitting) {
begin_fwd:
if (!before(TCP_SKB_CB(skb)->seq, tcp_highest_sack_seq(tp)))
break;
mib_idx = LINUX_MIB_TCPFORWARDRETRANS;
} else if (!before(TCP_SKB_CB(skb)->seq, tp->retransmit_high)) {
tp->retransmit_high = last_lost;
if (!tcp_can_forward_retransmit(sk))
break;
if (hole) {
skb = hole;
hole = NULL;
}
fwd_rexmitting = 1;
goto begin_fwd;
} else if (!(sacked & TCPCB_LOST)) {
if (!hole && !(sacked & (TCPCB_SACKED_RETRANS|TCPCB_SACKED_ACKED)))
hole = skb;
continue;
} else {
last_lost = TCP_SKB_CB(skb)->end_seq;
if (icsk->icsk_ca_state != TCP_CA_Loss)
mib_idx = LINUX_MIB_TCPFASTRETRANS;
else
mib_idx = LINUX_MIB_TCPSLOWSTARTRETRANS;
}
if (sacked & (TCPCB_SACKED_ACKED|TCPCB_SACKED_RETRANS))
continue;
if (tcp_small_queue_check(sk, skb, 1))
return;
if (tcp_retransmit_skb(sk, skb, segs))
return;
NET_ADD_STATS(sock_net(sk), mib_idx, tcp_skb_pcount(skb));
if (tcp_in_cwnd_reduction(sk))
tp->prr_out += tcp_skb_pcount(skb);
if (skb == tcp_write_queue_head(sk))
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
inet_csk(sk)->icsk_rto,
TCP_RTO_MAX);
}
}
void sk_forced_mem_schedule(struct sock *sk, int size)
{
int amt;
if (size <= sk->sk_forward_alloc)
return;
amt = sk_mem_pages(size);
sk->sk_forward_alloc += amt * SK_MEM_QUANTUM;
sk_memory_allocated_add(sk, amt);
if (mem_cgroup_sockets_enabled && sk->sk_memcg)
mem_cgroup_charge_skmem(sk->sk_memcg, amt);
}
void tcp_send_fin(struct sock *sk)
{
struct sk_buff *skb, *tskb = tcp_write_queue_tail(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (tskb && (tcp_send_head(sk) || tcp_under_memory_pressure(sk))) {
coalesce:
TCP_SKB_CB(tskb)->tcp_flags |= TCPHDR_FIN;
TCP_SKB_CB(tskb)->end_seq++;
tp->write_seq++;
if (!tcp_send_head(sk)) {
tp->snd_nxt++;
return;
}
} else {
skb = alloc_skb_fclone(MAX_TCP_HEADER, sk->sk_allocation);
if (unlikely(!skb)) {
if (tskb)
goto coalesce;
return;
}
skb_reserve(skb, MAX_TCP_HEADER);
sk_forced_mem_schedule(sk, skb->truesize);
tcp_init_nondata_skb(skb, tp->write_seq,
TCPHDR_ACK | TCPHDR_FIN);
tcp_queue_skb(sk, skb);
}
__tcp_push_pending_frames(sk, tcp_current_mss(sk), TCP_NAGLE_OFF);
}
void tcp_send_active_reset(struct sock *sk, gfp_t priority)
{
struct sk_buff *skb;
skb = alloc_skb(MAX_TCP_HEADER, priority);
if (!skb) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTFAILED);
return;
}
skb_reserve(skb, MAX_TCP_HEADER);
tcp_init_nondata_skb(skb, tcp_acceptable_seq(sk),
TCPHDR_ACK | TCPHDR_RST);
skb_mstamp_get(&skb->skb_mstamp);
if (tcp_transmit_skb(sk, skb, 0, priority))
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTFAILED);
TCP_INC_STATS(sock_net(sk), TCP_MIB_OUTRSTS);
}
int tcp_send_synack(struct sock *sk)
{
struct sk_buff *skb;
skb = tcp_write_queue_head(sk);
if (!skb || !(TCP_SKB_CB(skb)->tcp_flags & TCPHDR_SYN)) {
pr_debug("%s: wrong queue state\n", __func__);
return -EFAULT;
}
if (!(TCP_SKB_CB(skb)->tcp_flags & TCPHDR_ACK)) {
if (skb_cloned(skb)) {
struct sk_buff *nskb = skb_copy(skb, GFP_ATOMIC);
if (!nskb)
return -ENOMEM;
tcp_unlink_write_queue(skb, sk);
__skb_header_release(nskb);
__tcp_add_write_queue_head(sk, nskb);
sk_wmem_free_skb(sk, skb);
sk->sk_wmem_queued += nskb->truesize;
sk_mem_charge(sk, nskb->truesize);
skb = nskb;
}
TCP_SKB_CB(skb)->tcp_flags |= TCPHDR_ACK;
tcp_ecn_send_synack(sk, skb);
}
return tcp_transmit_skb(sk, skb, 1, GFP_ATOMIC);
}
struct sk_buff *tcp_make_synack(const struct sock *sk, struct dst_entry *dst,
struct request_sock *req,
struct tcp_fastopen_cookie *foc,
enum tcp_synack_type synack_type)
{
struct inet_request_sock *ireq = inet_rsk(req);
const struct tcp_sock *tp = tcp_sk(sk);
struct tcp_md5sig_key *md5 = NULL;
struct tcp_out_options opts;
struct sk_buff *skb;
int tcp_header_size;
struct tcphdr *th;
u16 user_mss;
int mss;
skb = alloc_skb(MAX_TCP_HEADER, GFP_ATOMIC);
if (unlikely(!skb)) {
dst_release(dst);
return NULL;
}
skb_reserve(skb, MAX_TCP_HEADER);
switch (synack_type) {
case TCP_SYNACK_NORMAL:
skb_set_owner_w(skb, req_to_sk(req));
break;
case TCP_SYNACK_COOKIE:
break;
case TCP_SYNACK_FASTOPEN:
skb_set_owner_w(skb, (struct sock *)sk);
break;
}
skb_dst_set(skb, dst);
mss = dst_metric_advmss(dst);
user_mss = READ_ONCE(tp->rx_opt.user_mss);
if (user_mss && user_mss < mss)
mss = user_mss;
memset(&opts, 0, sizeof(opts));
#ifdef CONFIG_SYN_COOKIES
if (unlikely(req->cookie_ts))
skb->skb_mstamp.stamp_jiffies = cookie_init_timestamp(req);
else
#endif
skb_mstamp_get(&skb->skb_mstamp);
#ifdef CONFIG_TCP_MD5SIG
rcu_read_lock();
md5 = tcp_rsk(req)->af_specific->req_md5_lookup(sk, req_to_sk(req));
#endif
skb_set_hash(skb, tcp_rsk(req)->txhash, PKT_HASH_TYPE_L4);
tcp_header_size = tcp_synack_options(req, mss, skb, &opts, md5, foc) +
sizeof(*th);
skb_push(skb, tcp_header_size);
skb_reset_transport_header(skb);
th = (struct tcphdr *)skb->data;
memset(th, 0, sizeof(struct tcphdr));
th->syn = 1;
th->ack = 1;
tcp_ecn_make_synack(req, th);
th->source = htons(ireq->ir_num);
th->dest = ireq->ir_rmt_port;
tcp_init_nondata_skb(skb, tcp_rsk(req)->snt_isn,
TCPHDR_SYN | TCPHDR_ACK);
th->seq = htonl(TCP_SKB_CB(skb)->seq);
th->ack_seq = htonl(tcp_rsk(req)->rcv_nxt);
th->window = htons(min(req->rsk_rcv_wnd, 65535U));
tcp_options_write((__be32 *)(th + 1), NULL, &opts);
th->doff = (tcp_header_size >> 2);
__TCP_INC_STATS(sock_net(sk), TCP_MIB_OUTSEGS);
#ifdef CONFIG_TCP_MD5SIG
if (md5)
tcp_rsk(req)->af_specific->calc_md5_hash(opts.hash_location,
md5, req_to_sk(req), skb);
rcu_read_unlock();
#endif
skb->tstamp = 0;
return skb;
}
static void tcp_ca_dst_init(struct sock *sk, const struct dst_entry *dst)
{
struct inet_connection_sock *icsk = inet_csk(sk);
const struct tcp_congestion_ops *ca;
u32 ca_key = dst_metric(dst, RTAX_CC_ALGO);
if (ca_key == TCP_CA_UNSPEC)
return;
rcu_read_lock();
ca = tcp_ca_find_key(ca_key);
if (likely(ca && try_module_get(ca->owner))) {
module_put(icsk->icsk_ca_ops->owner);
icsk->icsk_ca_dst_locked = tcp_ca_dst_locked(dst);
icsk->icsk_ca_ops = ca;
}
rcu_read_unlock();
}
static void tcp_connect_init(struct sock *sk)
{
const struct dst_entry *dst = __sk_dst_get(sk);
struct tcp_sock *tp = tcp_sk(sk);
__u8 rcv_wscale;
tp->tcp_header_len = sizeof(struct tcphdr) +
(sysctl_tcp_timestamps ? TCPOLEN_TSTAMP_ALIGNED : 0);
#ifdef CONFIG_TCP_MD5SIG
if (tp->af_specific->md5_lookup(sk, sk))
tp->tcp_header_len += TCPOLEN_MD5SIG_ALIGNED;
#endif
if (tp->rx_opt.user_mss)
tp->rx_opt.mss_clamp = tp->rx_opt.user_mss;
tp->max_window = 0;
tcp_mtup_init(sk);
tcp_sync_mss(sk, dst_mtu(dst));
tcp_ca_dst_init(sk, dst);
if (!tp->window_clamp)
tp->window_clamp = dst_metric(dst, RTAX_WINDOW);
tp->advmss = dst_metric_advmss(dst);
if (tp->rx_opt.user_mss && tp->rx_opt.user_mss < tp->advmss)
tp->advmss = tp->rx_opt.user_mss;
tcp_initialize_rcv_mss(sk);
if (sk->sk_userlocks & SOCK_RCVBUF_LOCK &&
(tp->window_clamp > tcp_full_space(sk) || tp->window_clamp == 0))
tp->window_clamp = tcp_full_space(sk);
tcp_select_initial_window(tcp_full_space(sk),
tp->advmss - (tp->rx_opt.ts_recent_stamp ? tp->tcp_header_len - sizeof(struct tcphdr) : 0),
&tp->rcv_wnd,
&tp->window_clamp,
sysctl_tcp_window_scaling,
&rcv_wscale,
dst_metric(dst, RTAX_INITRWND));
tp->rx_opt.rcv_wscale = rcv_wscale;
tp->rcv_ssthresh = tp->rcv_wnd;
sk->sk_err = 0;
sock_reset_flag(sk, SOCK_DONE);
tp->snd_wnd = 0;
tcp_init_wl(tp, 0);
tp->snd_una = tp->write_seq;
tp->snd_sml = tp->write_seq;
tp->snd_up = tp->write_seq;
tp->snd_nxt = tp->write_seq;
if (likely(!tp->repair))
tp->rcv_nxt = 0;
else
tp->rcv_tstamp = tcp_time_stamp;
tp->rcv_wup = tp->rcv_nxt;
tp->copied_seq = tp->rcv_nxt;
inet_csk(sk)->icsk_rto = TCP_TIMEOUT_INIT;
inet_csk(sk)->icsk_retransmits = 0;
tcp_clear_retrans(tp);
}
static void tcp_connect_queue_skb(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_skb_cb *tcb = TCP_SKB_CB(skb);
tcb->end_seq += skb->len;
__skb_header_release(skb);
__tcp_add_write_queue_tail(sk, skb);
sk->sk_wmem_queued += skb->truesize;
sk_mem_charge(sk, skb->truesize);
tp->write_seq = tcb->end_seq;
tp->packets_out += tcp_skb_pcount(skb);
}
static int tcp_send_syn_data(struct sock *sk, struct sk_buff *syn)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_fastopen_request *fo = tp->fastopen_req;
int syn_loss = 0, space, err = 0;
unsigned long last_syn_loss = 0;
struct sk_buff *syn_data;
tp->rx_opt.mss_clamp = tp->advmss;
tcp_fastopen_cache_get(sk, &tp->rx_opt.mss_clamp, &fo->cookie,
&syn_loss, &last_syn_loss);
if (syn_loss > 1 &&
time_before(jiffies, last_syn_loss + (60*HZ << syn_loss))) {
fo->cookie.len = -1;
goto fallback;
}
if (sysctl_tcp_fastopen & TFO_CLIENT_NO_COOKIE)
fo->cookie.len = -1;
else if (fo->cookie.len <= 0)
goto fallback;
if (tp->rx_opt.user_mss && tp->rx_opt.user_mss < tp->rx_opt.mss_clamp)
tp->rx_opt.mss_clamp = tp->rx_opt.user_mss;
space = __tcp_mtu_to_mss(sk, inet_csk(sk)->icsk_pmtu_cookie) -
MAX_TCP_OPTION_SPACE;
space = min_t(size_t, space, fo->size);
space = min_t(size_t, space, SKB_MAX_HEAD(MAX_TCP_HEADER));
syn_data = sk_stream_alloc_skb(sk, space, sk->sk_allocation, false);
if (!syn_data)
goto fallback;
syn_data->ip_summed = CHECKSUM_PARTIAL;
memcpy(syn_data->cb, syn->cb, sizeof(syn->cb));
if (space) {
int copied = copy_from_iter(skb_put(syn_data, space), space,
&fo->data->msg_iter);
if (unlikely(!copied)) {
kfree_skb(syn_data);
goto fallback;
}
if (copied != space) {
skb_trim(syn_data, copied);
space = copied;
}
}
if (space == fo->size)
fo->data = NULL;
fo->copied = space;
tcp_connect_queue_skb(sk, syn_data);
if (syn_data->len)
tcp_chrono_start(sk, TCP_CHRONO_BUSY);
err = tcp_transmit_skb(sk, syn_data, 1, sk->sk_allocation);
syn->skb_mstamp = syn_data->skb_mstamp;
TCP_SKB_CB(syn_data)->seq++;
TCP_SKB_CB(syn_data)->tcp_flags = TCPHDR_ACK | TCPHDR_PSH;
if (!err) {
tp->syn_data = (fo->copied > 0);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPORIGDATASENT);
goto done;
}
fallback:
if (fo->cookie.len > 0)
fo->cookie.len = 0;
err = tcp_transmit_skb(sk, syn, 1, sk->sk_allocation);
if (err)
tp->syn_fastopen = 0;
done:
fo->cookie.len = -1;
return err;
}
int tcp_connect(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *buff;
int err;
tcp_connect_init(sk);
if (unlikely(tp->repair)) {
tcp_finish_connect(sk, NULL);
return 0;
}
buff = sk_stream_alloc_skb(sk, 0, sk->sk_allocation, true);
if (unlikely(!buff))
return -ENOBUFS;
tcp_init_nondata_skb(buff, tp->write_seq++, TCPHDR_SYN);
tp->retrans_stamp = tcp_time_stamp;
tcp_connect_queue_skb(sk, buff);
tcp_ecn_send_syn(sk, buff);
err = tp->fastopen_req ? tcp_send_syn_data(sk, buff) :
tcp_transmit_skb(sk, buff, 1, sk->sk_allocation);
if (err == -ECONNREFUSED)
return err;
tp->snd_nxt = tp->write_seq;
tp->pushed_seq = tp->write_seq;
TCP_INC_STATS(sock_net(sk), TCP_MIB_ACTIVEOPENS);
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
inet_csk(sk)->icsk_rto, TCP_RTO_MAX);
return 0;
}
void tcp_send_delayed_ack(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
int ato = icsk->icsk_ack.ato;
unsigned long timeout;
tcp_ca_event(sk, CA_EVENT_DELAYED_ACK);
if (ato > TCP_DELACK_MIN) {
const struct tcp_sock *tp = tcp_sk(sk);
int max_ato = HZ / 2;
if (icsk->icsk_ack.pingpong ||
(icsk->icsk_ack.pending & ICSK_ACK_PUSHED))
max_ato = TCP_DELACK_MAX;
if (tp->srtt_us) {
int rtt = max_t(int, usecs_to_jiffies(tp->srtt_us >> 3),
TCP_DELACK_MIN);
if (rtt < max_ato)
max_ato = rtt;
}
ato = min(ato, max_ato);
}
timeout = jiffies + ato;
if (icsk->icsk_ack.pending & ICSK_ACK_TIMER) {
if (icsk->icsk_ack.blocked ||
time_before_eq(icsk->icsk_ack.timeout, jiffies + (ato >> 2))) {
tcp_send_ack(sk);
return;
}
if (!time_before(timeout, icsk->icsk_ack.timeout))
timeout = icsk->icsk_ack.timeout;
}
icsk->icsk_ack.pending |= ICSK_ACK_SCHED | ICSK_ACK_TIMER;
icsk->icsk_ack.timeout = timeout;
sk_reset_timer(sk, &icsk->icsk_delack_timer, timeout);
}
void tcp_send_ack(struct sock *sk)
{
struct sk_buff *buff;
if (sk->sk_state == TCP_CLOSE)
return;
tcp_ca_event(sk, CA_EVENT_NON_DELAYED_ACK);
buff = alloc_skb(MAX_TCP_HEADER,
sk_gfp_mask(sk, GFP_ATOMIC | __GFP_NOWARN));
if (unlikely(!buff)) {
inet_csk_schedule_ack(sk);
inet_csk(sk)->icsk_ack.ato = TCP_ATO_MIN;
inet_csk_reset_xmit_timer(sk, ICSK_TIME_DACK,
TCP_DELACK_MAX, TCP_RTO_MAX);
return;
}
skb_reserve(buff, MAX_TCP_HEADER);
tcp_init_nondata_skb(buff, tcp_acceptable_seq(sk), TCPHDR_ACK);
skb_set_tcp_pure_ack(buff);
skb_mstamp_get(&buff->skb_mstamp);
tcp_transmit_skb(sk, buff, 0, (__force gfp_t)0);
}
static int tcp_xmit_probe_skb(struct sock *sk, int urgent, int mib)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
skb = alloc_skb(MAX_TCP_HEADER,
sk_gfp_mask(sk, GFP_ATOMIC | __GFP_NOWARN));
if (!skb)
return -1;
skb_reserve(skb, MAX_TCP_HEADER);
tcp_init_nondata_skb(skb, tp->snd_una - !urgent, TCPHDR_ACK);
skb_mstamp_get(&skb->skb_mstamp);
NET_INC_STATS(sock_net(sk), mib);
return tcp_transmit_skb(sk, skb, 0, (__force gfp_t)0);
}
void tcp_send_window_probe(struct sock *sk)
{
if (sk->sk_state == TCP_ESTABLISHED) {
tcp_sk(sk)->snd_wl1 = tcp_sk(sk)->rcv_nxt - 1;
tcp_xmit_probe_skb(sk, 0, LINUX_MIB_TCPWINPROBE);
}
}
int tcp_write_wakeup(struct sock *sk, int mib)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
if (sk->sk_state == TCP_CLOSE)
return -1;
skb = tcp_send_head(sk);
if (skb && before(TCP_SKB_CB(skb)->seq, tcp_wnd_end(tp))) {
int err;
unsigned int mss = tcp_current_mss(sk);
unsigned int seg_size = tcp_wnd_end(tp) - TCP_SKB_CB(skb)->seq;
if (before(tp->pushed_seq, TCP_SKB_CB(skb)->end_seq))
tp->pushed_seq = TCP_SKB_CB(skb)->end_seq;
if (seg_size < TCP_SKB_CB(skb)->end_seq - TCP_SKB_CB(skb)->seq ||
skb->len > mss) {
seg_size = min(seg_size, mss);
TCP_SKB_CB(skb)->tcp_flags |= TCPHDR_PSH;
if (tcp_fragment(sk, skb, seg_size, mss, GFP_ATOMIC))
return -1;
} else if (!tcp_skb_pcount(skb))
tcp_set_skb_tso_segs(skb, mss);
TCP_SKB_CB(skb)->tcp_flags |= TCPHDR_PSH;
err = tcp_transmit_skb(sk, skb, 1, GFP_ATOMIC);
if (!err)
tcp_event_new_data_sent(sk, skb);
return err;
} else {
if (between(tp->snd_up, tp->snd_una + 1, tp->snd_una + 0xFFFF))
tcp_xmit_probe_skb(sk, 1, mib);
return tcp_xmit_probe_skb(sk, 0, mib);
}
}
void tcp_send_probe0(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
unsigned long probe_max;
int err;
err = tcp_write_wakeup(sk, LINUX_MIB_TCPWINPROBE);
if (tp->packets_out || !tcp_send_head(sk)) {
icsk->icsk_probes_out = 0;
icsk->icsk_backoff = 0;
return;
}
if (err <= 0) {
if (icsk->icsk_backoff < net->ipv4.sysctl_tcp_retries2)
icsk->icsk_backoff++;
icsk->icsk_probes_out++;
probe_max = TCP_RTO_MAX;
} else {
if (!icsk->icsk_probes_out)
icsk->icsk_probes_out = 1;
probe_max = TCP_RESOURCE_PROBE_INTERVAL;
}
inet_csk_reset_xmit_timer(sk, ICSK_TIME_PROBE0,
tcp_probe0_when(sk, probe_max),
TCP_RTO_MAX);
}
int tcp_rtx_synack(const struct sock *sk, struct request_sock *req)
{
const struct tcp_request_sock_ops *af_ops = tcp_rsk(req)->af_specific;
struct flowi fl;
int res;
tcp_rsk(req)->txhash = net_tx_rndhash();
res = af_ops->send_synack(sk, NULL, &fl, req, NULL, TCP_SYNACK_NORMAL);
if (!res) {
__TCP_INC_STATS(sock_net(sk), TCP_MIB_RETRANSSEGS);
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPSYNRETRANS);
if (unlikely(tcp_passive_fastopen(sk)))
tcp_sk(sk)->total_retrans++;
}
return res;
}
