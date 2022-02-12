static void tcp_gro_dev_warn(struct sock *sk, const struct sk_buff *skb,
unsigned int len)
{
static bool __once __read_mostly;
if (!__once) {
struct net_device *dev;
__once = true;
rcu_read_lock();
dev = dev_get_by_index_rcu(sock_net(sk), skb->skb_iif);
if (!dev || len >= dev->mtu)
pr_warn("%s: Driver has suspect GRO implementation, TCP performance may be compromised.\n",
dev ? dev->name : "Unknown driver");
rcu_read_unlock();
}
}
static void tcp_measure_rcv_mss(struct sock *sk, const struct sk_buff *skb)
{
struct inet_connection_sock *icsk = inet_csk(sk);
const unsigned int lss = icsk->icsk_ack.last_seg_size;
unsigned int len;
icsk->icsk_ack.last_seg_size = 0;
len = skb_shinfo(skb)->gso_size ? : skb->len;
if (len >= icsk->icsk_ack.rcv_mss) {
icsk->icsk_ack.rcv_mss = min_t(unsigned int, len,
tcp_sk(sk)->advmss);
if (unlikely(len > icsk->icsk_ack.rcv_mss +
MAX_TCP_OPTION_SPACE))
tcp_gro_dev_warn(sk, skb, len);
} else {
len += skb->data - skb_transport_header(skb);
if (len >= TCP_MSS_DEFAULT + sizeof(struct tcphdr) ||
(len >= TCP_MIN_MSS + sizeof(struct tcphdr) &&
!(tcp_flag_word(tcp_hdr(skb)) & TCP_REMNANT))) {
len -= tcp_sk(sk)->tcp_header_len;
icsk->icsk_ack.last_seg_size = len;
if (len == lss) {
icsk->icsk_ack.rcv_mss = len;
return;
}
}
if (icsk->icsk_ack.pending & ICSK_ACK_PUSHED)
icsk->icsk_ack.pending |= ICSK_ACK_PUSHED2;
icsk->icsk_ack.pending |= ICSK_ACK_PUSHED;
}
}
static void tcp_incr_quickack(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
unsigned int quickacks = tcp_sk(sk)->rcv_wnd / (2 * icsk->icsk_ack.rcv_mss);
if (quickacks == 0)
quickacks = 2;
if (quickacks > icsk->icsk_ack.quick)
icsk->icsk_ack.quick = min(quickacks, TCP_MAX_QUICKACKS);
}
static void tcp_enter_quickack_mode(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
tcp_incr_quickack(sk);
icsk->icsk_ack.pingpong = 0;
icsk->icsk_ack.ato = TCP_ATO_MIN;
}
static bool tcp_in_quickack_mode(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
const struct dst_entry *dst = __sk_dst_get(sk);
return (dst && dst_metric(dst, RTAX_QUICKACK)) ||
(icsk->icsk_ack.quick && !icsk->icsk_ack.pingpong);
}
static void tcp_ecn_queue_cwr(struct tcp_sock *tp)
{
if (tp->ecn_flags & TCP_ECN_OK)
tp->ecn_flags |= TCP_ECN_QUEUE_CWR;
}
static void tcp_ecn_accept_cwr(struct tcp_sock *tp, const struct sk_buff *skb)
{
if (tcp_hdr(skb)->cwr)
tp->ecn_flags &= ~TCP_ECN_DEMAND_CWR;
}
static void tcp_ecn_withdraw_cwr(struct tcp_sock *tp)
{
tp->ecn_flags &= ~TCP_ECN_DEMAND_CWR;
}
static void __tcp_ecn_check_ce(struct tcp_sock *tp, const struct sk_buff *skb)
{
switch (TCP_SKB_CB(skb)->ip_dsfield & INET_ECN_MASK) {
case INET_ECN_NOT_ECT:
if (tp->ecn_flags & TCP_ECN_SEEN)
tcp_enter_quickack_mode((struct sock *)tp);
break;
case INET_ECN_CE:
if (tcp_ca_needs_ecn((struct sock *)tp))
tcp_ca_event((struct sock *)tp, CA_EVENT_ECN_IS_CE);
if (!(tp->ecn_flags & TCP_ECN_DEMAND_CWR)) {
tcp_enter_quickack_mode((struct sock *)tp);
tp->ecn_flags |= TCP_ECN_DEMAND_CWR;
}
tp->ecn_flags |= TCP_ECN_SEEN;
break;
default:
if (tcp_ca_needs_ecn((struct sock *)tp))
tcp_ca_event((struct sock *)tp, CA_EVENT_ECN_NO_CE);
tp->ecn_flags |= TCP_ECN_SEEN;
break;
}
}
static void tcp_ecn_check_ce(struct tcp_sock *tp, const struct sk_buff *skb)
{
if (tp->ecn_flags & TCP_ECN_OK)
__tcp_ecn_check_ce(tp, skb);
}
static void tcp_ecn_rcv_synack(struct tcp_sock *tp, const struct tcphdr *th)
{
if ((tp->ecn_flags & TCP_ECN_OK) && (!th->ece || th->cwr))
tp->ecn_flags &= ~TCP_ECN_OK;
}
static void tcp_ecn_rcv_syn(struct tcp_sock *tp, const struct tcphdr *th)
{
if ((tp->ecn_flags & TCP_ECN_OK) && (!th->ece || !th->cwr))
tp->ecn_flags &= ~TCP_ECN_OK;
}
static bool tcp_ecn_rcv_ecn_echo(const struct tcp_sock *tp, const struct tcphdr *th)
{
if (th->ece && !th->syn && (tp->ecn_flags & TCP_ECN_OK))
return true;
return false;
}
static void tcp_sndbuf_expand(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct tcp_congestion_ops *ca_ops = inet_csk(sk)->icsk_ca_ops;
int sndmem, per_mss;
u32 nr_segs;
per_mss = max_t(u32, tp->rx_opt.mss_clamp, tp->mss_cache) +
MAX_TCP_HEADER +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
per_mss = roundup_pow_of_two(per_mss) +
SKB_DATA_ALIGN(sizeof(struct sk_buff));
nr_segs = max_t(u32, TCP_INIT_CWND, tp->snd_cwnd);
nr_segs = max_t(u32, nr_segs, tp->reordering + 1);
sndmem = ca_ops->sndbuf_expand ? ca_ops->sndbuf_expand(sk) : 2;
sndmem *= nr_segs * per_mss;
if (sk->sk_sndbuf < sndmem)
sk->sk_sndbuf = min(sndmem, sysctl_tcp_wmem[2]);
}
static int __tcp_grow_window(const struct sock *sk, const struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
int truesize = tcp_win_from_space(skb->truesize) >> 1;
int window = tcp_win_from_space(sysctl_tcp_rmem[2]) >> 1;
while (tp->rcv_ssthresh <= window) {
if (truesize <= skb->len)
return 2 * inet_csk(sk)->icsk_ack.rcv_mss;
truesize >>= 1;
window >>= 1;
}
return 0;
}
static void tcp_grow_window(struct sock *sk, const struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->rcv_ssthresh < tp->window_clamp &&
(int)tp->rcv_ssthresh < tcp_space(sk) &&
!tcp_under_memory_pressure(sk)) {
int incr;
if (tcp_win_from_space(skb->truesize) <= skb->len)
incr = 2 * tp->advmss;
else
incr = __tcp_grow_window(sk, skb);
if (incr) {
incr = max_t(int, incr, 2 * skb->len);
tp->rcv_ssthresh = min(tp->rcv_ssthresh + incr,
tp->window_clamp);
inet_csk(sk)->icsk_ack.quick |= 1;
}
}
}
static void tcp_fixup_rcvbuf(struct sock *sk)
{
u32 mss = tcp_sk(sk)->advmss;
int rcvmem;
rcvmem = 2 * SKB_TRUESIZE(mss + MAX_TCP_HEADER) *
tcp_default_init_rwnd(mss);
if (sysctl_tcp_moderate_rcvbuf)
rcvmem <<= 2;
if (sk->sk_rcvbuf < rcvmem)
sk->sk_rcvbuf = min(rcvmem, sysctl_tcp_rmem[2]);
}
void tcp_init_buffer_space(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
int maxwin;
if (!(sk->sk_userlocks & SOCK_RCVBUF_LOCK))
tcp_fixup_rcvbuf(sk);
if (!(sk->sk_userlocks & SOCK_SNDBUF_LOCK))
tcp_sndbuf_expand(sk);
tp->rcvq_space.space = tp->rcv_wnd;
tp->rcvq_space.time = tcp_time_stamp;
tp->rcvq_space.seq = tp->copied_seq;
maxwin = tcp_full_space(sk);
if (tp->window_clamp >= maxwin) {
tp->window_clamp = maxwin;
if (sysctl_tcp_app_win && maxwin > 4 * tp->advmss)
tp->window_clamp = max(maxwin -
(maxwin >> sysctl_tcp_app_win),
4 * tp->advmss);
}
if (sysctl_tcp_app_win &&
tp->window_clamp > 2 * tp->advmss &&
tp->window_clamp + tp->advmss > maxwin)
tp->window_clamp = max(2 * tp->advmss, maxwin - tp->advmss);
tp->rcv_ssthresh = min(tp->rcv_ssthresh, tp->window_clamp);
tp->snd_cwnd_stamp = tcp_time_stamp;
}
static void tcp_clamp_window(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
icsk->icsk_ack.quick = 0;
if (sk->sk_rcvbuf < sysctl_tcp_rmem[2] &&
!(sk->sk_userlocks & SOCK_RCVBUF_LOCK) &&
!tcp_under_memory_pressure(sk) &&
sk_memory_allocated(sk) < sk_prot_mem_limits(sk, 0)) {
sk->sk_rcvbuf = min(atomic_read(&sk->sk_rmem_alloc),
sysctl_tcp_rmem[2]);
}
if (atomic_read(&sk->sk_rmem_alloc) > sk->sk_rcvbuf)
tp->rcv_ssthresh = min(tp->window_clamp, 2U * tp->advmss);
}
void tcp_initialize_rcv_mss(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
unsigned int hint = min_t(unsigned int, tp->advmss, tp->mss_cache);
hint = min(hint, tp->rcv_wnd / 2);
hint = min(hint, TCP_MSS_DEFAULT);
hint = max(hint, TCP_MIN_MSS);
inet_csk(sk)->icsk_ack.rcv_mss = hint;
}
static void tcp_rcv_rtt_update(struct tcp_sock *tp, u32 sample, int win_dep)
{
u32 new_sample = tp->rcv_rtt_est.rtt;
long m = sample;
if (m == 0)
m = 1;
if (new_sample != 0) {
if (!win_dep) {
m -= (new_sample >> 3);
new_sample += m;
} else {
m <<= 3;
if (m < new_sample)
new_sample = m;
}
} else {
new_sample = m << 3;
}
if (tp->rcv_rtt_est.rtt != new_sample)
tp->rcv_rtt_est.rtt = new_sample;
}
static inline void tcp_rcv_rtt_measure(struct tcp_sock *tp)
{
if (tp->rcv_rtt_est.time == 0)
goto new_measure;
if (before(tp->rcv_nxt, tp->rcv_rtt_est.seq))
return;
tcp_rcv_rtt_update(tp, tcp_time_stamp - tp->rcv_rtt_est.time, 1);
new_measure:
tp->rcv_rtt_est.seq = tp->rcv_nxt + tp->rcv_wnd;
tp->rcv_rtt_est.time = tcp_time_stamp;
}
static inline void tcp_rcv_rtt_measure_ts(struct sock *sk,
const struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->rx_opt.rcv_tsecr &&
(TCP_SKB_CB(skb)->end_seq -
TCP_SKB_CB(skb)->seq >= inet_csk(sk)->icsk_ack.rcv_mss))
tcp_rcv_rtt_update(tp, tcp_time_stamp - tp->rx_opt.rcv_tsecr, 0);
}
void tcp_rcv_space_adjust(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
int time;
int copied;
time = tcp_time_stamp - tp->rcvq_space.time;
if (time < (tp->rcv_rtt_est.rtt >> 3) || tp->rcv_rtt_est.rtt == 0)
return;
copied = tp->copied_seq - tp->rcvq_space.seq;
if (copied <= tp->rcvq_space.space)
goto new_measure;
if (sysctl_tcp_moderate_rcvbuf &&
!(sk->sk_userlocks & SOCK_RCVBUF_LOCK)) {
int rcvwin, rcvmem, rcvbuf;
rcvwin = (copied << 1) + 16 * tp->advmss;
if (copied >=
tp->rcvq_space.space + (tp->rcvq_space.space >> 2)) {
if (copied >=
tp->rcvq_space.space + (tp->rcvq_space.space >> 1))
rcvwin <<= 1;
else
rcvwin += (rcvwin >> 1);
}
rcvmem = SKB_TRUESIZE(tp->advmss + MAX_TCP_HEADER);
while (tcp_win_from_space(rcvmem) < tp->advmss)
rcvmem += 128;
rcvbuf = min(rcvwin / tp->advmss * rcvmem, sysctl_tcp_rmem[2]);
if (rcvbuf > sk->sk_rcvbuf) {
sk->sk_rcvbuf = rcvbuf;
tp->window_clamp = rcvwin;
}
}
tp->rcvq_space.space = copied;
new_measure:
tp->rcvq_space.seq = tp->copied_seq;
tp->rcvq_space.time = tcp_time_stamp;
}
static void tcp_event_data_recv(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
u32 now;
inet_csk_schedule_ack(sk);
tcp_measure_rcv_mss(sk, skb);
tcp_rcv_rtt_measure(tp);
now = tcp_time_stamp;
if (!icsk->icsk_ack.ato) {
tcp_incr_quickack(sk);
icsk->icsk_ack.ato = TCP_ATO_MIN;
} else {
int m = now - icsk->icsk_ack.lrcvtime;
if (m <= TCP_ATO_MIN / 2) {
icsk->icsk_ack.ato = (icsk->icsk_ack.ato >> 1) + TCP_ATO_MIN / 2;
} else if (m < icsk->icsk_ack.ato) {
icsk->icsk_ack.ato = (icsk->icsk_ack.ato >> 1) + m;
if (icsk->icsk_ack.ato > icsk->icsk_rto)
icsk->icsk_ack.ato = icsk->icsk_rto;
} else if (m > icsk->icsk_rto) {
tcp_incr_quickack(sk);
sk_mem_reclaim(sk);
}
}
icsk->icsk_ack.lrcvtime = now;
tcp_ecn_check_ce(tp, skb);
if (skb->len >= 128)
tcp_grow_window(sk, skb);
}
static void tcp_rtt_estimator(struct sock *sk, long mrtt_us)
{
struct tcp_sock *tp = tcp_sk(sk);
long m = mrtt_us;
u32 srtt = tp->srtt_us;
if (srtt != 0) {
m -= (srtt >> 3);
srtt += m;
if (m < 0) {
m = -m;
m -= (tp->mdev_us >> 2);
if (m > 0)
m >>= 3;
} else {
m -= (tp->mdev_us >> 2);
}
tp->mdev_us += m;
if (tp->mdev_us > tp->mdev_max_us) {
tp->mdev_max_us = tp->mdev_us;
if (tp->mdev_max_us > tp->rttvar_us)
tp->rttvar_us = tp->mdev_max_us;
}
if (after(tp->snd_una, tp->rtt_seq)) {
if (tp->mdev_max_us < tp->rttvar_us)
tp->rttvar_us -= (tp->rttvar_us - tp->mdev_max_us) >> 2;
tp->rtt_seq = tp->snd_nxt;
tp->mdev_max_us = tcp_rto_min_us(sk);
}
} else {
srtt = m << 3;
tp->mdev_us = m << 1;
tp->rttvar_us = max(tp->mdev_us, tcp_rto_min_us(sk));
tp->mdev_max_us = tp->rttvar_us;
tp->rtt_seq = tp->snd_nxt;
}
tp->srtt_us = max(1U, srtt);
}
static void tcp_update_pacing_rate(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
u64 rate;
rate = (u64)tp->mss_cache * ((USEC_PER_SEC / 100) << 3);
if (tp->snd_cwnd < tp->snd_ssthresh / 2)
rate *= sysctl_tcp_pacing_ss_ratio;
else
rate *= sysctl_tcp_pacing_ca_ratio;
rate *= max(tp->snd_cwnd, tp->packets_out);
if (likely(tp->srtt_us))
do_div(rate, tp->srtt_us);
ACCESS_ONCE(sk->sk_pacing_rate) = min_t(u64, rate,
sk->sk_max_pacing_rate);
}
static void tcp_set_rto(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
inet_csk(sk)->icsk_rto = __tcp_set_rto(tp);
tcp_bound_rto(sk);
}
__u32 tcp_init_cwnd(const struct tcp_sock *tp, const struct dst_entry *dst)
{
__u32 cwnd = (dst ? dst_metric(dst, RTAX_INITCWND) : 0);
if (!cwnd)
cwnd = TCP_INIT_CWND;
return min_t(__u32, cwnd, tp->snd_cwnd_clamp);
}
void tcp_disable_fack(struct tcp_sock *tp)
{
if (tcp_is_fack(tp))
tp->lost_skb_hint = NULL;
tp->rx_opt.sack_ok &= ~TCP_FACK_ENABLED;
}
static void tcp_dsack_seen(struct tcp_sock *tp)
{
tp->rx_opt.sack_ok |= TCP_DSACK_SEEN;
}
static void tcp_update_reordering(struct sock *sk, const int metric,
const int ts)
{
struct tcp_sock *tp = tcp_sk(sk);
int mib_idx;
if (metric > tp->reordering) {
tp->reordering = min(sysctl_tcp_max_reordering, metric);
#if FASTRETRANS_DEBUG > 1
pr_debug("Disorder%d %d %u f%u s%u rr%d\n",
tp->rx_opt.sack_ok, inet_csk(sk)->icsk_ca_state,
tp->reordering,
tp->fackets_out,
tp->sacked_out,
tp->undo_marker ? tp->undo_retrans : 0);
#endif
tcp_disable_fack(tp);
}
tp->rack.reord = 1;
if (ts)
mib_idx = LINUX_MIB_TCPTSREORDER;
else if (tcp_is_reno(tp))
mib_idx = LINUX_MIB_TCPRENOREORDER;
else if (tcp_is_fack(tp))
mib_idx = LINUX_MIB_TCPFACKREORDER;
else
mib_idx = LINUX_MIB_TCPSACKREORDER;
NET_INC_STATS(sock_net(sk), mib_idx);
}
static void tcp_verify_retransmit_hint(struct tcp_sock *tp, struct sk_buff *skb)
{
if (!tp->retransmit_skb_hint ||
before(TCP_SKB_CB(skb)->seq,
TCP_SKB_CB(tp->retransmit_skb_hint)->seq))
tp->retransmit_skb_hint = skb;
}
static void tcp_sum_lost(struct tcp_sock *tp, struct sk_buff *skb)
{
__u8 sacked = TCP_SKB_CB(skb)->sacked;
if (!(sacked & TCPCB_LOST) ||
((sacked & TCPCB_LOST) && (sacked & TCPCB_SACKED_RETRANS)))
tp->lost += tcp_skb_pcount(skb);
}
static void tcp_skb_mark_lost(struct tcp_sock *tp, struct sk_buff *skb)
{
if (!(TCP_SKB_CB(skb)->sacked & (TCPCB_LOST|TCPCB_SACKED_ACKED))) {
tcp_verify_retransmit_hint(tp, skb);
tp->lost_out += tcp_skb_pcount(skb);
tcp_sum_lost(tp, skb);
TCP_SKB_CB(skb)->sacked |= TCPCB_LOST;
}
}
void tcp_skb_mark_lost_uncond_verify(struct tcp_sock *tp, struct sk_buff *skb)
{
tcp_verify_retransmit_hint(tp, skb);
tcp_sum_lost(tp, skb);
if (!(TCP_SKB_CB(skb)->sacked & (TCPCB_LOST|TCPCB_SACKED_ACKED))) {
tp->lost_out += tcp_skb_pcount(skb);
TCP_SKB_CB(skb)->sacked |= TCPCB_LOST;
}
}
static bool tcp_is_sackblock_valid(struct tcp_sock *tp, bool is_dsack,
u32 start_seq, u32 end_seq)
{
if (after(end_seq, tp->snd_nxt) || !before(start_seq, end_seq))
return false;
if (!before(start_seq, tp->snd_nxt))
return false;
if (after(start_seq, tp->snd_una))
return true;
if (!is_dsack || !tp->undo_marker)
return false;
if (after(end_seq, tp->snd_una))
return false;
if (!before(start_seq, tp->undo_marker))
return true;
if (!after(end_seq, tp->undo_marker))
return false;
return !before(start_seq, end_seq - tp->max_window);
}
static bool tcp_check_dsack(struct sock *sk, const struct sk_buff *ack_skb,
struct tcp_sack_block_wire *sp, int num_sacks,
u32 prior_snd_una)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 start_seq_0 = get_unaligned_be32(&sp[0].start_seq);
u32 end_seq_0 = get_unaligned_be32(&sp[0].end_seq);
bool dup_sack = false;
if (before(start_seq_0, TCP_SKB_CB(ack_skb)->ack_seq)) {
dup_sack = true;
tcp_dsack_seen(tp);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPDSACKRECV);
} else if (num_sacks > 1) {
u32 end_seq_1 = get_unaligned_be32(&sp[1].end_seq);
u32 start_seq_1 = get_unaligned_be32(&sp[1].start_seq);
if (!after(end_seq_0, end_seq_1) &&
!before(start_seq_0, start_seq_1)) {
dup_sack = true;
tcp_dsack_seen(tp);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPDSACKOFORECV);
}
}
if (dup_sack && tp->undo_marker && tp->undo_retrans > 0 &&
!after(end_seq_0, prior_snd_una) &&
after(end_seq_0, tp->undo_marker))
tp->undo_retrans--;
return dup_sack;
}
static int tcp_match_skb_to_sack(struct sock *sk, struct sk_buff *skb,
u32 start_seq, u32 end_seq)
{
int err;
bool in_sack;
unsigned int pkt_len;
unsigned int mss;
in_sack = !after(start_seq, TCP_SKB_CB(skb)->seq) &&
!before(end_seq, TCP_SKB_CB(skb)->end_seq);
if (tcp_skb_pcount(skb) > 1 && !in_sack &&
after(TCP_SKB_CB(skb)->end_seq, start_seq)) {
mss = tcp_skb_mss(skb);
in_sack = !after(start_seq, TCP_SKB_CB(skb)->seq);
if (!in_sack) {
pkt_len = start_seq - TCP_SKB_CB(skb)->seq;
if (pkt_len < mss)
pkt_len = mss;
} else {
pkt_len = end_seq - TCP_SKB_CB(skb)->seq;
if (pkt_len < mss)
return -EINVAL;
}
if (pkt_len > mss) {
unsigned int new_len = (pkt_len / mss) * mss;
if (!in_sack && new_len < pkt_len) {
new_len += mss;
if (new_len >= skb->len)
return 0;
}
pkt_len = new_len;
}
err = tcp_fragment(sk, skb, pkt_len, mss, GFP_ATOMIC);
if (err < 0)
return err;
}
return in_sack;
}
static u8 tcp_sacktag_one(struct sock *sk,
struct tcp_sacktag_state *state, u8 sacked,
u32 start_seq, u32 end_seq,
int dup_sack, int pcount,
const struct skb_mstamp *xmit_time)
{
struct tcp_sock *tp = tcp_sk(sk);
int fack_count = state->fack_count;
if (dup_sack && (sacked & TCPCB_RETRANS)) {
if (tp->undo_marker && tp->undo_retrans > 0 &&
after(end_seq, tp->undo_marker))
tp->undo_retrans--;
if (sacked & TCPCB_SACKED_ACKED)
state->reord = min(fack_count, state->reord);
}
if (!after(end_seq, tp->snd_una))
return sacked;
if (!(sacked & TCPCB_SACKED_ACKED)) {
tcp_rack_advance(tp, sacked, end_seq,
xmit_time, &state->ack_time);
if (sacked & TCPCB_SACKED_RETRANS) {
if (sacked & TCPCB_LOST) {
sacked &= ~(TCPCB_LOST|TCPCB_SACKED_RETRANS);
tp->lost_out -= pcount;
tp->retrans_out -= pcount;
}
} else {
if (!(sacked & TCPCB_RETRANS)) {
if (before(start_seq,
tcp_highest_sack_seq(tp)))
state->reord = min(fack_count,
state->reord);
if (!after(end_seq, tp->high_seq))
state->flag |= FLAG_ORIG_SACK_ACKED;
if (state->first_sackt.v64 == 0)
state->first_sackt = *xmit_time;
state->last_sackt = *xmit_time;
}
if (sacked & TCPCB_LOST) {
sacked &= ~TCPCB_LOST;
tp->lost_out -= pcount;
}
}
sacked |= TCPCB_SACKED_ACKED;
state->flag |= FLAG_DATA_SACKED;
tp->sacked_out += pcount;
tp->delivered += pcount;
fack_count += pcount;
if (!tcp_is_fack(tp) && tp->lost_skb_hint &&
before(start_seq, TCP_SKB_CB(tp->lost_skb_hint)->seq))
tp->lost_cnt_hint += pcount;
if (fack_count > tp->fackets_out)
tp->fackets_out = fack_count;
}
if (dup_sack && (sacked & TCPCB_SACKED_RETRANS)) {
sacked &= ~TCPCB_SACKED_RETRANS;
tp->retrans_out -= pcount;
}
return sacked;
}
static bool tcp_shifted_skb(struct sock *sk, struct sk_buff *skb,
struct tcp_sacktag_state *state,
unsigned int pcount, int shifted, int mss,
bool dup_sack)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *prev = tcp_write_queue_prev(sk, skb);
u32 start_seq = TCP_SKB_CB(skb)->seq;
u32 end_seq = start_seq + shifted;
BUG_ON(!pcount);
tcp_sacktag_one(sk, state, TCP_SKB_CB(skb)->sacked,
start_seq, end_seq, dup_sack, pcount,
&skb->skb_mstamp);
tcp_rate_skb_delivered(sk, skb, state->rate);
if (skb == tp->lost_skb_hint)
tp->lost_cnt_hint += pcount;
TCP_SKB_CB(prev)->end_seq += shifted;
TCP_SKB_CB(skb)->seq += shifted;
tcp_skb_pcount_add(prev, pcount);
BUG_ON(tcp_skb_pcount(skb) < pcount);
tcp_skb_pcount_add(skb, -pcount);
if (!TCP_SKB_CB(prev)->tcp_gso_size)
TCP_SKB_CB(prev)->tcp_gso_size = mss;
if (tcp_skb_pcount(skb) <= 1)
TCP_SKB_CB(skb)->tcp_gso_size = 0;
TCP_SKB_CB(prev)->sacked |= (TCP_SKB_CB(skb)->sacked & TCPCB_EVER_RETRANS);
if (skb->len > 0) {
BUG_ON(!tcp_skb_pcount(skb));
NET_INC_STATS(sock_net(sk), LINUX_MIB_SACKSHIFTED);
return false;
}
if (skb == tp->retransmit_skb_hint)
tp->retransmit_skb_hint = prev;
if (skb == tp->lost_skb_hint) {
tp->lost_skb_hint = prev;
tp->lost_cnt_hint -= tcp_skb_pcount(prev);
}
TCP_SKB_CB(prev)->tcp_flags |= TCP_SKB_CB(skb)->tcp_flags;
TCP_SKB_CB(prev)->eor = TCP_SKB_CB(skb)->eor;
if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN)
TCP_SKB_CB(prev)->end_seq++;
if (skb == tcp_highest_sack(sk))
tcp_advance_highest_sack(sk, skb);
tcp_skb_collapse_tstamp(prev, skb);
if (unlikely(TCP_SKB_CB(prev)->tx.delivered_mstamp.v64))
TCP_SKB_CB(prev)->tx.delivered_mstamp.v64 = 0;
tcp_unlink_write_queue(skb, sk);
sk_wmem_free_skb(sk, skb);
NET_INC_STATS(sock_net(sk), LINUX_MIB_SACKMERGED);
return true;
}
static int tcp_skb_seglen(const struct sk_buff *skb)
{
return tcp_skb_pcount(skb) == 1 ? skb->len : tcp_skb_mss(skb);
}
static int skb_can_shift(const struct sk_buff *skb)
{
return !skb_headlen(skb) && skb_is_nonlinear(skb);
}
static struct sk_buff *tcp_shift_skb_data(struct sock *sk, struct sk_buff *skb,
struct tcp_sacktag_state *state,
u32 start_seq, u32 end_seq,
bool dup_sack)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *prev;
int mss;
int pcount = 0;
int len;
int in_sack;
if (!sk_can_gso(sk))
goto fallback;
if (!dup_sack &&
(TCP_SKB_CB(skb)->sacked & (TCPCB_LOST|TCPCB_SACKED_RETRANS)) == TCPCB_SACKED_RETRANS)
goto fallback;
if (!skb_can_shift(skb))
goto fallback;
if (!after(TCP_SKB_CB(skb)->end_seq, tp->snd_una))
goto fallback;
if (unlikely(skb == tcp_write_queue_head(sk)))
goto fallback;
prev = tcp_write_queue_prev(sk, skb);
if ((TCP_SKB_CB(prev)->sacked & TCPCB_TAGBITS) != TCPCB_SACKED_ACKED)
goto fallback;
if (!tcp_skb_can_collapse_to(prev))
goto fallback;
in_sack = !after(start_seq, TCP_SKB_CB(skb)->seq) &&
!before(end_seq, TCP_SKB_CB(skb)->end_seq);
if (in_sack) {
len = skb->len;
pcount = tcp_skb_pcount(skb);
mss = tcp_skb_seglen(skb);
if (mss != tcp_skb_seglen(prev))
goto fallback;
} else {
if (!after(TCP_SKB_CB(skb)->end_seq, start_seq))
goto noop;
if (tcp_skb_pcount(skb) <= 1)
goto noop;
in_sack = !after(start_seq, TCP_SKB_CB(skb)->seq);
if (!in_sack) {
goto fallback;
}
len = end_seq - TCP_SKB_CB(skb)->seq;
BUG_ON(len < 0);
BUG_ON(len > skb->len);
mss = tcp_skb_mss(skb);
if (mss != tcp_skb_seglen(prev))
goto fallback;
if (len == mss) {
pcount = 1;
} else if (len < mss) {
goto noop;
} else {
pcount = len / mss;
len = pcount * mss;
}
}
if (!after(TCP_SKB_CB(skb)->seq + len, tp->snd_una))
goto fallback;
if (!skb_shift(prev, skb, len))
goto fallback;
if (!tcp_shifted_skb(sk, skb, state, pcount, len, mss, dup_sack))
goto out;
if (prev == tcp_write_queue_tail(sk))
goto out;
skb = tcp_write_queue_next(sk, prev);
if (!skb_can_shift(skb) ||
(skb == tcp_send_head(sk)) ||
((TCP_SKB_CB(skb)->sacked & TCPCB_TAGBITS) != TCPCB_SACKED_ACKED) ||
(mss != tcp_skb_seglen(skb)))
goto out;
len = skb->len;
if (skb_shift(prev, skb, len)) {
pcount += tcp_skb_pcount(skb);
tcp_shifted_skb(sk, skb, state, tcp_skb_pcount(skb), len, mss, 0);
}
out:
state->fack_count += pcount;
return prev;
noop:
return skb;
fallback:
NET_INC_STATS(sock_net(sk), LINUX_MIB_SACKSHIFTFALLBACK);
return NULL;
}
static struct sk_buff *tcp_sacktag_walk(struct sk_buff *skb, struct sock *sk,
struct tcp_sack_block *next_dup,
struct tcp_sacktag_state *state,
u32 start_seq, u32 end_seq,
bool dup_sack_in)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *tmp;
tcp_for_write_queue_from(skb, sk) {
int in_sack = 0;
bool dup_sack = dup_sack_in;
if (skb == tcp_send_head(sk))
break;
if (!before(TCP_SKB_CB(skb)->seq, end_seq))
break;
if (next_dup &&
before(TCP_SKB_CB(skb)->seq, next_dup->end_seq)) {
in_sack = tcp_match_skb_to_sack(sk, skb,
next_dup->start_seq,
next_dup->end_seq);
if (in_sack > 0)
dup_sack = true;
}
if (in_sack <= 0) {
tmp = tcp_shift_skb_data(sk, skb, state,
start_seq, end_seq, dup_sack);
if (tmp) {
if (tmp != skb) {
skb = tmp;
continue;
}
in_sack = 0;
} else {
in_sack = tcp_match_skb_to_sack(sk, skb,
start_seq,
end_seq);
}
}
if (unlikely(in_sack < 0))
break;
if (in_sack) {
TCP_SKB_CB(skb)->sacked =
tcp_sacktag_one(sk,
state,
TCP_SKB_CB(skb)->sacked,
TCP_SKB_CB(skb)->seq,
TCP_SKB_CB(skb)->end_seq,
dup_sack,
tcp_skb_pcount(skb),
&skb->skb_mstamp);
tcp_rate_skb_delivered(sk, skb, state->rate);
if (!before(TCP_SKB_CB(skb)->seq,
tcp_highest_sack_seq(tp)))
tcp_advance_highest_sack(sk, skb);
}
state->fack_count += tcp_skb_pcount(skb);
}
return skb;
}
static struct sk_buff *tcp_sacktag_skip(struct sk_buff *skb, struct sock *sk,
struct tcp_sacktag_state *state,
u32 skip_to_seq)
{
tcp_for_write_queue_from(skb, sk) {
if (skb == tcp_send_head(sk))
break;
if (after(TCP_SKB_CB(skb)->end_seq, skip_to_seq))
break;
state->fack_count += tcp_skb_pcount(skb);
}
return skb;
}
static struct sk_buff *tcp_maybe_skipping_dsack(struct sk_buff *skb,
struct sock *sk,
struct tcp_sack_block *next_dup,
struct tcp_sacktag_state *state,
u32 skip_to_seq)
{
if (!next_dup)
return skb;
if (before(next_dup->start_seq, skip_to_seq)) {
skb = tcp_sacktag_skip(skb, sk, state, next_dup->start_seq);
skb = tcp_sacktag_walk(skb, sk, NULL, state,
next_dup->start_seq, next_dup->end_seq,
1);
}
return skb;
}
static int tcp_sack_cache_ok(const struct tcp_sock *tp, const struct tcp_sack_block *cache)
{
return cache < tp->recv_sack_cache + ARRAY_SIZE(tp->recv_sack_cache);
}
static int
tcp_sacktag_write_queue(struct sock *sk, const struct sk_buff *ack_skb,
u32 prior_snd_una, struct tcp_sacktag_state *state)
{
struct tcp_sock *tp = tcp_sk(sk);
const unsigned char *ptr = (skb_transport_header(ack_skb) +
TCP_SKB_CB(ack_skb)->sacked);
struct tcp_sack_block_wire *sp_wire = (struct tcp_sack_block_wire *)(ptr+2);
struct tcp_sack_block sp[TCP_NUM_SACKS];
struct tcp_sack_block *cache;
struct sk_buff *skb;
int num_sacks = min(TCP_NUM_SACKS, (ptr[1] - TCPOLEN_SACK_BASE) >> 3);
int used_sacks;
bool found_dup_sack = false;
int i, j;
int first_sack_index;
state->flag = 0;
state->reord = tp->packets_out;
if (!tp->sacked_out) {
if (WARN_ON(tp->fackets_out))
tp->fackets_out = 0;
tcp_highest_sack_reset(sk);
}
found_dup_sack = tcp_check_dsack(sk, ack_skb, sp_wire,
num_sacks, prior_snd_una);
if (found_dup_sack) {
state->flag |= FLAG_DSACKING_ACK;
tp->delivered++;
}
if (before(TCP_SKB_CB(ack_skb)->ack_seq, prior_snd_una - tp->max_window))
return 0;
if (!tp->packets_out)
goto out;
used_sacks = 0;
first_sack_index = 0;
for (i = 0; i < num_sacks; i++) {
bool dup_sack = !i && found_dup_sack;
sp[used_sacks].start_seq = get_unaligned_be32(&sp_wire[i].start_seq);
sp[used_sacks].end_seq = get_unaligned_be32(&sp_wire[i].end_seq);
if (!tcp_is_sackblock_valid(tp, dup_sack,
sp[used_sacks].start_seq,
sp[used_sacks].end_seq)) {
int mib_idx;
if (dup_sack) {
if (!tp->undo_marker)
mib_idx = LINUX_MIB_TCPDSACKIGNOREDNOUNDO;
else
mib_idx = LINUX_MIB_TCPDSACKIGNOREDOLD;
} else {
if ((TCP_SKB_CB(ack_skb)->ack_seq != tp->snd_una) &&
!after(sp[used_sacks].end_seq, tp->snd_una))
continue;
mib_idx = LINUX_MIB_TCPSACKDISCARD;
}
NET_INC_STATS(sock_net(sk), mib_idx);
if (i == 0)
first_sack_index = -1;
continue;
}
if (!after(sp[used_sacks].end_seq, prior_snd_una))
continue;
used_sacks++;
}
for (i = used_sacks - 1; i > 0; i--) {
for (j = 0; j < i; j++) {
if (after(sp[j].start_seq, sp[j + 1].start_seq)) {
swap(sp[j], sp[j + 1]);
if (j == first_sack_index)
first_sack_index = j + 1;
}
}
}
skb = tcp_write_queue_head(sk);
state->fack_count = 0;
i = 0;
if (!tp->sacked_out) {
cache = tp->recv_sack_cache + ARRAY_SIZE(tp->recv_sack_cache);
} else {
cache = tp->recv_sack_cache;
while (tcp_sack_cache_ok(tp, cache) && !cache->start_seq &&
!cache->end_seq)
cache++;
}
while (i < used_sacks) {
u32 start_seq = sp[i].start_seq;
u32 end_seq = sp[i].end_seq;
bool dup_sack = (found_dup_sack && (i == first_sack_index));
struct tcp_sack_block *next_dup = NULL;
if (found_dup_sack && ((i + 1) == first_sack_index))
next_dup = &sp[i + 1];
while (tcp_sack_cache_ok(tp, cache) &&
!before(start_seq, cache->end_seq))
cache++;
if (tcp_sack_cache_ok(tp, cache) && !dup_sack &&
after(end_seq, cache->start_seq)) {
if (before(start_seq, cache->start_seq)) {
skb = tcp_sacktag_skip(skb, sk, state,
start_seq);
skb = tcp_sacktag_walk(skb, sk, next_dup,
state,
start_seq,
cache->start_seq,
dup_sack);
}
if (!after(end_seq, cache->end_seq))
goto advance_sp;
skb = tcp_maybe_skipping_dsack(skb, sk, next_dup,
state,
cache->end_seq);
if (tcp_highest_sack_seq(tp) == cache->end_seq) {
skb = tcp_highest_sack(sk);
if (!skb)
break;
state->fack_count = tp->fackets_out;
cache++;
goto walk;
}
skb = tcp_sacktag_skip(skb, sk, state, cache->end_seq);
cache++;
continue;
}
if (!before(start_seq, tcp_highest_sack_seq(tp))) {
skb = tcp_highest_sack(sk);
if (!skb)
break;
state->fack_count = tp->fackets_out;
}
skb = tcp_sacktag_skip(skb, sk, state, start_seq);
walk:
skb = tcp_sacktag_walk(skb, sk, next_dup, state,
start_seq, end_seq, dup_sack);
advance_sp:
i++;
}
for (i = 0; i < ARRAY_SIZE(tp->recv_sack_cache) - used_sacks; i++) {
tp->recv_sack_cache[i].start_seq = 0;
tp->recv_sack_cache[i].end_seq = 0;
}
for (j = 0; j < used_sacks; j++)
tp->recv_sack_cache[i++] = sp[j];
if ((state->reord < tp->fackets_out) &&
((inet_csk(sk)->icsk_ca_state != TCP_CA_Loss) || tp->undo_marker))
tcp_update_reordering(sk, tp->fackets_out - state->reord, 0);
tcp_verify_left_out(tp);
out:
#if FASTRETRANS_DEBUG > 0
WARN_ON((int)tp->sacked_out < 0);
WARN_ON((int)tp->lost_out < 0);
WARN_ON((int)tp->retrans_out < 0);
WARN_ON((int)tcp_packets_in_flight(tp) < 0);
#endif
return state->flag;
}
static bool tcp_limit_reno_sacked(struct tcp_sock *tp)
{
u32 holes;
holes = max(tp->lost_out, 1U);
holes = min(holes, tp->packets_out);
if ((tp->sacked_out + holes) > tp->packets_out) {
tp->sacked_out = tp->packets_out - holes;
return true;
}
return false;
}
static void tcp_check_reno_reordering(struct sock *sk, const int addend)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_limit_reno_sacked(tp))
tcp_update_reordering(sk, tp->packets_out + addend, 0);
}
static void tcp_add_reno_sack(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 prior_sacked = tp->sacked_out;
tp->sacked_out++;
tcp_check_reno_reordering(sk, 0);
if (tp->sacked_out > prior_sacked)
tp->delivered++;
tcp_verify_left_out(tp);
}
static void tcp_remove_reno_sacks(struct sock *sk, int acked)
{
struct tcp_sock *tp = tcp_sk(sk);
if (acked > 0) {
tp->delivered += max_t(int, acked - tp->sacked_out, 1);
if (acked - 1 >= tp->sacked_out)
tp->sacked_out = 0;
else
tp->sacked_out -= acked - 1;
}
tcp_check_reno_reordering(sk, acked);
tcp_verify_left_out(tp);
}
static inline void tcp_reset_reno_sack(struct tcp_sock *tp)
{
tp->sacked_out = 0;
}
void tcp_clear_retrans(struct tcp_sock *tp)
{
tp->retrans_out = 0;
tp->lost_out = 0;
tp->undo_marker = 0;
tp->undo_retrans = -1;
tp->fackets_out = 0;
tp->sacked_out = 0;
}
static inline void tcp_init_undo(struct tcp_sock *tp)
{
tp->undo_marker = tp->snd_una;
tp->undo_retrans = tp->retrans_out ? : -1;
}
void tcp_enter_loss(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
struct sk_buff *skb;
bool new_recovery = icsk->icsk_ca_state < TCP_CA_Recovery;
bool is_reneg;
bool mark_lost;
if (icsk->icsk_ca_state <= TCP_CA_Disorder ||
!after(tp->high_seq, tp->snd_una) ||
(icsk->icsk_ca_state == TCP_CA_Loss && !icsk->icsk_retransmits)) {
tp->prior_ssthresh = tcp_current_ssthresh(sk);
tp->snd_ssthresh = icsk->icsk_ca_ops->ssthresh(sk);
tcp_ca_event(sk, CA_EVENT_LOSS);
tcp_init_undo(tp);
}
tp->snd_cwnd = 1;
tp->snd_cwnd_cnt = 0;
tp->snd_cwnd_stamp = tcp_time_stamp;
tp->retrans_out = 0;
tp->lost_out = 0;
if (tcp_is_reno(tp))
tcp_reset_reno_sack(tp);
skb = tcp_write_queue_head(sk);
is_reneg = skb && (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED);
if (is_reneg) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPSACKRENEGING);
tp->sacked_out = 0;
tp->fackets_out = 0;
}
tcp_clear_all_retrans_hints(tp);
tcp_for_write_queue(skb, sk) {
if (skb == tcp_send_head(sk))
break;
mark_lost = (!(TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED) ||
is_reneg);
if (mark_lost)
tcp_sum_lost(tp, skb);
TCP_SKB_CB(skb)->sacked &= (~TCPCB_TAGBITS)|TCPCB_SACKED_ACKED;
if (mark_lost) {
TCP_SKB_CB(skb)->sacked &= ~TCPCB_SACKED_ACKED;
TCP_SKB_CB(skb)->sacked |= TCPCB_LOST;
tp->lost_out += tcp_skb_pcount(skb);
}
}
tcp_verify_left_out(tp);
if (icsk->icsk_ca_state <= TCP_CA_Disorder &&
tp->sacked_out >= net->ipv4.sysctl_tcp_reordering)
tp->reordering = min_t(unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering);
tcp_set_ca_state(sk, TCP_CA_Loss);
tp->high_seq = tp->snd_nxt;
tcp_ecn_queue_cwr(tp);
tp->frto = sysctl_tcp_frto &&
(new_recovery || icsk->icsk_retransmits) &&
!inet_csk(sk)->icsk_mtup.probe_size;
}
static bool tcp_check_sack_reneging(struct sock *sk, int flag)
{
if (flag & FLAG_SACK_RENEGING) {
struct tcp_sock *tp = tcp_sk(sk);
unsigned long delay = max(usecs_to_jiffies(tp->srtt_us >> 4),
msecs_to_jiffies(10));
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
delay, TCP_RTO_MAX);
return true;
}
return false;
}
static inline int tcp_fackets_out(const struct tcp_sock *tp)
{
return tcp_is_reno(tp) ? tp->sacked_out + 1 : tp->fackets_out;
}
static inline int tcp_dupack_heuristics(const struct tcp_sock *tp)
{
return tcp_is_fack(tp) ? tp->fackets_out : tp->sacked_out + 1;
}
static bool tcp_time_to_recover(struct sock *sk, int flag)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->lost_out)
return true;
if (tcp_dupack_heuristics(tp) > tp->reordering)
return true;
return false;
}
static void tcp_mark_head_lost(struct sock *sk, int packets, int mark_head)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
int cnt, oldcnt, lost;
unsigned int mss;
const u32 loss_high = tcp_is_sack(tp) ? tp->snd_nxt : tp->high_seq;
WARN_ON(packets > tp->packets_out);
if (tp->lost_skb_hint) {
skb = tp->lost_skb_hint;
cnt = tp->lost_cnt_hint;
if (mark_head && skb != tcp_write_queue_head(sk))
return;
} else {
skb = tcp_write_queue_head(sk);
cnt = 0;
}
tcp_for_write_queue_from(skb, sk) {
if (skb == tcp_send_head(sk))
break;
tp->lost_skb_hint = skb;
tp->lost_cnt_hint = cnt;
if (after(TCP_SKB_CB(skb)->end_seq, loss_high))
break;
oldcnt = cnt;
if (tcp_is_fack(tp) || tcp_is_reno(tp) ||
(TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED))
cnt += tcp_skb_pcount(skb);
if (cnt > packets) {
if ((tcp_is_sack(tp) && !tcp_is_fack(tp)) ||
(TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED) ||
(oldcnt >= packets))
break;
mss = tcp_skb_mss(skb);
lost = (packets - oldcnt) * mss;
if (lost < skb->len &&
tcp_fragment(sk, skb, lost, mss, GFP_ATOMIC) < 0)
break;
cnt = packets;
}
tcp_skb_mark_lost(tp, skb);
if (mark_head)
break;
}
tcp_verify_left_out(tp);
}
static void tcp_update_scoreboard(struct sock *sk, int fast_rexmit)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_is_reno(tp)) {
tcp_mark_head_lost(sk, 1, 1);
} else if (tcp_is_fack(tp)) {
int lost = tp->fackets_out - tp->reordering;
if (lost <= 0)
lost = 1;
tcp_mark_head_lost(sk, lost, 0);
} else {
int sacked_upto = tp->sacked_out - tp->reordering;
if (sacked_upto >= 0)
tcp_mark_head_lost(sk, sacked_upto, 0);
else if (fast_rexmit)
tcp_mark_head_lost(sk, 1, 1);
}
}
static bool tcp_tsopt_ecr_before(const struct tcp_sock *tp, u32 when)
{
return tp->rx_opt.saw_tstamp && tp->rx_opt.rcv_tsecr &&
before(tp->rx_opt.rcv_tsecr, when);
}
static bool tcp_skb_spurious_retrans(const struct tcp_sock *tp,
const struct sk_buff *skb)
{
return (TCP_SKB_CB(skb)->sacked & TCPCB_RETRANS) &&
tcp_tsopt_ecr_before(tp, tcp_skb_timestamp(skb));
}
static inline bool tcp_packet_delayed(const struct tcp_sock *tp)
{
return !tp->retrans_stamp ||
tcp_tsopt_ecr_before(tp, tp->retrans_stamp);
}
static bool tcp_any_retrans_done(const struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
if (tp->retrans_out)
return true;
skb = tcp_write_queue_head(sk);
if (unlikely(skb && TCP_SKB_CB(skb)->sacked & TCPCB_EVER_RETRANS))
return true;
return false;
}
static void DBGUNDO(struct sock *sk, const char *msg)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_sock *inet = inet_sk(sk);
if (sk->sk_family == AF_INET) {
pr_debug("Undo %s %pI4/%u c%u l%u ss%u/%u p%u\n",
msg,
&inet->inet_daddr, ntohs(inet->inet_dport),
tp->snd_cwnd, tcp_left_out(tp),
tp->snd_ssthresh, tp->prior_ssthresh,
tp->packets_out);
}
#if IS_ENABLED(CONFIG_IPV6)
else if (sk->sk_family == AF_INET6) {
pr_debug("Undo %s %pI6/%u c%u l%u ss%u/%u p%u\n",
msg,
&sk->sk_v6_daddr, ntohs(inet->inet_dport),
tp->snd_cwnd, tcp_left_out(tp),
tp->snd_ssthresh, tp->prior_ssthresh,
tp->packets_out);
}
#endif
}
static void tcp_undo_cwnd_reduction(struct sock *sk, bool unmark_loss)
{
struct tcp_sock *tp = tcp_sk(sk);
if (unmark_loss) {
struct sk_buff *skb;
tcp_for_write_queue(skb, sk) {
if (skb == tcp_send_head(sk))
break;
TCP_SKB_CB(skb)->sacked &= ~TCPCB_LOST;
}
tp->lost_out = 0;
tcp_clear_all_retrans_hints(tp);
}
if (tp->prior_ssthresh) {
const struct inet_connection_sock *icsk = inet_csk(sk);
tp->snd_cwnd = icsk->icsk_ca_ops->undo_cwnd(sk);
if (tp->prior_ssthresh > tp->snd_ssthresh) {
tp->snd_ssthresh = tp->prior_ssthresh;
tcp_ecn_withdraw_cwr(tp);
}
}
tp->snd_cwnd_stamp = tcp_time_stamp;
tp->undo_marker = 0;
}
static inline bool tcp_may_undo(const struct tcp_sock *tp)
{
return tp->undo_marker && (!tp->undo_retrans || tcp_packet_delayed(tp));
}
static bool tcp_try_undo_recovery(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_may_undo(tp)) {
int mib_idx;
DBGUNDO(sk, inet_csk(sk)->icsk_ca_state == TCP_CA_Loss ? "loss" : "retrans");
tcp_undo_cwnd_reduction(sk, false);
if (inet_csk(sk)->icsk_ca_state == TCP_CA_Loss)
mib_idx = LINUX_MIB_TCPLOSSUNDO;
else
mib_idx = LINUX_MIB_TCPFULLUNDO;
NET_INC_STATS(sock_net(sk), mib_idx);
}
if (tp->snd_una == tp->high_seq && tcp_is_reno(tp)) {
if (!tcp_any_retrans_done(sk))
tp->retrans_stamp = 0;
return true;
}
tcp_set_ca_state(sk, TCP_CA_Open);
return false;
}
static bool tcp_try_undo_dsack(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->undo_marker && !tp->undo_retrans) {
DBGUNDO(sk, "D-SACK");
tcp_undo_cwnd_reduction(sk, false);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPDSACKUNDO);
return true;
}
return false;
}
static bool tcp_try_undo_loss(struct sock *sk, bool frto_undo)
{
struct tcp_sock *tp = tcp_sk(sk);
if (frto_undo || tcp_may_undo(tp)) {
tcp_undo_cwnd_reduction(sk, true);
DBGUNDO(sk, "partial loss");
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPLOSSUNDO);
if (frto_undo)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPSPURIOUSRTOS);
inet_csk(sk)->icsk_retransmits = 0;
if (frto_undo || tcp_is_sack(tp))
tcp_set_ca_state(sk, TCP_CA_Open);
return true;
}
return false;
}
static void tcp_init_cwnd_reduction(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
tp->high_seq = tp->snd_nxt;
tp->tlp_high_seq = 0;
tp->snd_cwnd_cnt = 0;
tp->prior_cwnd = tp->snd_cwnd;
tp->prr_delivered = 0;
tp->prr_out = 0;
tp->snd_ssthresh = inet_csk(sk)->icsk_ca_ops->ssthresh(sk);
tcp_ecn_queue_cwr(tp);
}
void tcp_cwnd_reduction(struct sock *sk, int newly_acked_sacked, int flag)
{
struct tcp_sock *tp = tcp_sk(sk);
int sndcnt = 0;
int delta = tp->snd_ssthresh - tcp_packets_in_flight(tp);
if (newly_acked_sacked <= 0 || WARN_ON_ONCE(!tp->prior_cwnd))
return;
tp->prr_delivered += newly_acked_sacked;
if (delta < 0) {
u64 dividend = (u64)tp->snd_ssthresh * tp->prr_delivered +
tp->prior_cwnd - 1;
sndcnt = div_u64(dividend, tp->prior_cwnd) - tp->prr_out;
} else if ((flag & FLAG_RETRANS_DATA_ACKED) &&
!(flag & FLAG_LOST_RETRANS)) {
sndcnt = min_t(int, delta,
max_t(int, tp->prr_delivered - tp->prr_out,
newly_acked_sacked) + 1);
} else {
sndcnt = min(delta, newly_acked_sacked);
}
sndcnt = max(sndcnt, (tp->prr_out ? 0 : 1));
tp->snd_cwnd = tcp_packets_in_flight(tp) + sndcnt;
}
static inline void tcp_end_cwnd_reduction(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (inet_csk(sk)->icsk_ca_ops->cong_control)
return;
if (inet_csk(sk)->icsk_ca_state == TCP_CA_CWR ||
(tp->undo_marker && tp->snd_ssthresh < TCP_INFINITE_SSTHRESH)) {
tp->snd_cwnd = tp->snd_ssthresh;
tp->snd_cwnd_stamp = tcp_time_stamp;
}
tcp_ca_event(sk, CA_EVENT_COMPLETE_CWR);
}
void tcp_enter_cwr(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
tp->prior_ssthresh = 0;
if (inet_csk(sk)->icsk_ca_state < TCP_CA_CWR) {
tp->undo_marker = 0;
tcp_init_cwnd_reduction(sk);
tcp_set_ca_state(sk, TCP_CA_CWR);
}
}
static void tcp_try_keep_open(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
int state = TCP_CA_Open;
if (tcp_left_out(tp) || tcp_any_retrans_done(sk))
state = TCP_CA_Disorder;
if (inet_csk(sk)->icsk_ca_state != state) {
tcp_set_ca_state(sk, state);
tp->high_seq = tp->snd_nxt;
}
}
static void tcp_try_to_open(struct sock *sk, int flag)
{
struct tcp_sock *tp = tcp_sk(sk);
tcp_verify_left_out(tp);
if (!tcp_any_retrans_done(sk))
tp->retrans_stamp = 0;
if (flag & FLAG_ECE)
tcp_enter_cwr(sk);
if (inet_csk(sk)->icsk_ca_state != TCP_CA_CWR) {
tcp_try_keep_open(sk);
}
}
static void tcp_mtup_probe_failed(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
icsk->icsk_mtup.search_high = icsk->icsk_mtup.probe_size - 1;
icsk->icsk_mtup.probe_size = 0;
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPMTUPFAIL);
}
static void tcp_mtup_probe_success(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
tp->prior_ssthresh = tcp_current_ssthresh(sk);
tp->snd_cwnd = tp->snd_cwnd *
tcp_mss_to_mtu(sk, tp->mss_cache) /
icsk->icsk_mtup.probe_size;
tp->snd_cwnd_cnt = 0;
tp->snd_cwnd_stamp = tcp_time_stamp;
tp->snd_ssthresh = tcp_current_ssthresh(sk);
icsk->icsk_mtup.search_low = icsk->icsk_mtup.probe_size;
icsk->icsk_mtup.probe_size = 0;
tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPMTUPSUCCESS);
}
void tcp_simple_retransmit(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
unsigned int mss = tcp_current_mss(sk);
u32 prior_lost = tp->lost_out;
tcp_for_write_queue(skb, sk) {
if (skb == tcp_send_head(sk))
break;
if (tcp_skb_seglen(skb) > mss &&
!(TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED)) {
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_RETRANS) {
TCP_SKB_CB(skb)->sacked &= ~TCPCB_SACKED_RETRANS;
tp->retrans_out -= tcp_skb_pcount(skb);
}
tcp_skb_mark_lost_uncond_verify(tp, skb);
}
}
tcp_clear_retrans_hints_partial(tp);
if (prior_lost == tp->lost_out)
return;
if (tcp_is_reno(tp))
tcp_limit_reno_sacked(tp);
tcp_verify_left_out(tp);
if (icsk->icsk_ca_state != TCP_CA_Loss) {
tp->high_seq = tp->snd_nxt;
tp->snd_ssthresh = tcp_current_ssthresh(sk);
tp->prior_ssthresh = 0;
tp->undo_marker = 0;
tcp_set_ca_state(sk, TCP_CA_Loss);
}
tcp_xmit_retransmit_queue(sk);
}
void tcp_enter_recovery(struct sock *sk, bool ece_ack)
{
struct tcp_sock *tp = tcp_sk(sk);
int mib_idx;
if (tcp_is_reno(tp))
mib_idx = LINUX_MIB_TCPRENORECOVERY;
else
mib_idx = LINUX_MIB_TCPSACKRECOVERY;
NET_INC_STATS(sock_net(sk), mib_idx);
tp->prior_ssthresh = 0;
tcp_init_undo(tp);
if (!tcp_in_cwnd_reduction(sk)) {
if (!ece_ack)
tp->prior_ssthresh = tcp_current_ssthresh(sk);
tcp_init_cwnd_reduction(sk);
}
tcp_set_ca_state(sk, TCP_CA_Recovery);
}
static void tcp_process_loss(struct sock *sk, int flag, bool is_dupack,
int *rexmit)
{
struct tcp_sock *tp = tcp_sk(sk);
bool recovered = !before(tp->snd_una, tp->high_seq);
if ((flag & FLAG_SND_UNA_ADVANCED) &&
tcp_try_undo_loss(sk, false))
return;
if ((flag & FLAG_ORIG_SACK_ACKED) &&
tcp_try_undo_loss(sk, tp->undo_marker))
return;
if (tp->frto) {
if (after(tp->snd_nxt, tp->high_seq)) {
if (flag & FLAG_DATA_SACKED || is_dupack)
tp->frto = 0;
} else if (flag & FLAG_SND_UNA_ADVANCED && !recovered) {
tp->high_seq = tp->snd_nxt;
if (tcp_send_head(sk) &&
after(tcp_wnd_end(tp), tp->snd_nxt)) {
*rexmit = REXMIT_NEW;
return;
}
tp->frto = 0;
}
}
if (recovered) {
tcp_try_undo_recovery(sk);
return;
}
if (tcp_is_reno(tp)) {
if (after(tp->snd_nxt, tp->high_seq) && is_dupack)
tcp_add_reno_sack(sk);
else if (flag & FLAG_SND_UNA_ADVANCED)
tcp_reset_reno_sack(tp);
}
*rexmit = REXMIT_LOST;
}
static bool tcp_try_undo_partial(struct sock *sk, const int acked)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tp->undo_marker && tcp_packet_delayed(tp)) {
tcp_update_reordering(sk, tcp_fackets_out(tp) + acked, 1);
if (tp->retrans_out)
return true;
if (!tcp_any_retrans_done(sk))
tp->retrans_stamp = 0;
DBGUNDO(sk, "partial recovery");
tcp_undo_cwnd_reduction(sk, true);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPPARTIALUNDO);
tcp_try_keep_open(sk);
return true;
}
return false;
}
static void tcp_rack_identify_loss(struct sock *sk, int *ack_flag,
const struct skb_mstamp *ack_time)
{
struct tcp_sock *tp = tcp_sk(sk);
if (sysctl_tcp_recovery & TCP_RACK_LOSS_DETECTION) {
u32 prior_retrans = tp->retrans_out;
tcp_rack_mark_lost(sk, ack_time);
if (prior_retrans > tp->retrans_out)
*ack_flag |= FLAG_LOST_RETRANS;
}
}
static void tcp_fastretrans_alert(struct sock *sk, const int acked,
bool is_dupack, int *ack_flag, int *rexmit,
const struct skb_mstamp *ack_time)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
int fast_rexmit = 0, flag = *ack_flag;
bool do_lost = is_dupack || ((flag & FLAG_DATA_SACKED) &&
(tcp_fackets_out(tp) > tp->reordering));
if (WARN_ON(!tp->packets_out && tp->sacked_out))
tp->sacked_out = 0;
if (WARN_ON(!tp->sacked_out && tp->fackets_out))
tp->fackets_out = 0;
if (flag & FLAG_ECE)
tp->prior_ssthresh = 0;
if (tcp_check_sack_reneging(sk, flag))
return;
tcp_verify_left_out(tp);
if (icsk->icsk_ca_state == TCP_CA_Open) {
WARN_ON(tp->retrans_out != 0);
tp->retrans_stamp = 0;
} else if (!before(tp->snd_una, tp->high_seq)) {
switch (icsk->icsk_ca_state) {
case TCP_CA_CWR:
if (tp->snd_una != tp->high_seq) {
tcp_end_cwnd_reduction(sk);
tcp_set_ca_state(sk, TCP_CA_Open);
}
break;
case TCP_CA_Recovery:
if (tcp_is_reno(tp))
tcp_reset_reno_sack(tp);
if (tcp_try_undo_recovery(sk))
return;
tcp_end_cwnd_reduction(sk);
break;
}
}
switch (icsk->icsk_ca_state) {
case TCP_CA_Recovery:
if (!(flag & FLAG_SND_UNA_ADVANCED)) {
if (tcp_is_reno(tp) && is_dupack)
tcp_add_reno_sack(sk);
} else {
if (tcp_try_undo_partial(sk, acked))
return;
do_lost = tcp_is_reno(tp) ||
tcp_fackets_out(tp) > tp->reordering;
}
if (tcp_try_undo_dsack(sk)) {
tcp_try_keep_open(sk);
return;
}
tcp_rack_identify_loss(sk, ack_flag, ack_time);
break;
case TCP_CA_Loss:
tcp_process_loss(sk, flag, is_dupack, rexmit);
tcp_rack_identify_loss(sk, ack_flag, ack_time);
if (!(icsk->icsk_ca_state == TCP_CA_Open ||
(*ack_flag & FLAG_LOST_RETRANS)))
return;
default:
if (tcp_is_reno(tp)) {
if (flag & FLAG_SND_UNA_ADVANCED)
tcp_reset_reno_sack(tp);
if (is_dupack)
tcp_add_reno_sack(sk);
}
if (icsk->icsk_ca_state <= TCP_CA_Disorder)
tcp_try_undo_dsack(sk);
tcp_rack_identify_loss(sk, ack_flag, ack_time);
if (!tcp_time_to_recover(sk, flag)) {
tcp_try_to_open(sk, flag);
return;
}
if (icsk->icsk_ca_state < TCP_CA_CWR &&
icsk->icsk_mtup.probe_size &&
tp->snd_una == tp->mtu_probe.probe_seq_start) {
tcp_mtup_probe_failed(sk);
tp->snd_cwnd++;
tcp_simple_retransmit(sk);
return;
}
tcp_enter_recovery(sk, (flag & FLAG_ECE));
fast_rexmit = 1;
}
if (do_lost)
tcp_update_scoreboard(sk, fast_rexmit);
*rexmit = REXMIT_LOST;
}
static void tcp_update_rtt_min(struct sock *sk, u32 rtt_us)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 wlen = sysctl_tcp_min_rtt_wlen * HZ;
minmax_running_min(&tp->rtt_min, wlen, tcp_time_stamp,
rtt_us ? : jiffies_to_usecs(1));
}
static inline bool tcp_ack_update_rtt(struct sock *sk, const int flag,
long seq_rtt_us, long sack_rtt_us,
long ca_rtt_us)
{
const struct tcp_sock *tp = tcp_sk(sk);
if (seq_rtt_us < 0)
seq_rtt_us = sack_rtt_us;
if (seq_rtt_us < 0 && tp->rx_opt.saw_tstamp && tp->rx_opt.rcv_tsecr &&
flag & FLAG_ACKED)
seq_rtt_us = ca_rtt_us = jiffies_to_usecs(tcp_time_stamp -
tp->rx_opt.rcv_tsecr);
if (seq_rtt_us < 0)
return false;
tcp_update_rtt_min(sk, ca_rtt_us);
tcp_rtt_estimator(sk, seq_rtt_us);
tcp_set_rto(sk);
inet_csk(sk)->icsk_backoff = 0;
return true;
}
void tcp_synack_rtt_meas(struct sock *sk, struct request_sock *req)
{
long rtt_us = -1L;
if (req && !req->num_retrans && tcp_rsk(req)->snt_synack.v64) {
struct skb_mstamp now;
skb_mstamp_get(&now);
rtt_us = skb_mstamp_us_delta(&now, &tcp_rsk(req)->snt_synack);
}
tcp_ack_update_rtt(sk, FLAG_SYN_ACKED, rtt_us, -1L, rtt_us);
}
static void tcp_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
icsk->icsk_ca_ops->cong_avoid(sk, ack, acked);
tcp_sk(sk)->snd_cwnd_stamp = tcp_time_stamp;
}
void tcp_rearm_rto(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (tp->fastopen_rsk)
return;
if (!tp->packets_out) {
inet_csk_clear_xmit_timer(sk, ICSK_TIME_RETRANS);
} else {
u32 rto = inet_csk(sk)->icsk_rto;
if (icsk->icsk_pending == ICSK_TIME_REO_TIMEOUT ||
icsk->icsk_pending == ICSK_TIME_LOSS_PROBE) {
struct sk_buff *skb = tcp_write_queue_head(sk);
const u32 rto_time_stamp =
tcp_skb_timestamp(skb) + rto;
s32 delta = (s32)(rto_time_stamp - tcp_time_stamp);
if (delta > 0)
rto = delta;
}
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS, rto,
TCP_RTO_MAX);
}
}
static u32 tcp_tso_acked(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 packets_acked;
BUG_ON(!after(TCP_SKB_CB(skb)->end_seq, tp->snd_una));
packets_acked = tcp_skb_pcount(skb);
if (tcp_trim_head(sk, skb, tp->snd_una - TCP_SKB_CB(skb)->seq))
return 0;
packets_acked -= tcp_skb_pcount(skb);
if (packets_acked) {
BUG_ON(tcp_skb_pcount(skb) == 0);
BUG_ON(!before(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb)->end_seq));
}
return packets_acked;
}
static void tcp_ack_tstamp(struct sock *sk, struct sk_buff *skb,
u32 prior_snd_una)
{
const struct skb_shared_info *shinfo;
if (likely(!TCP_SKB_CB(skb)->txstamp_ack))
return;
shinfo = skb_shinfo(skb);
if (!before(shinfo->tskey, prior_snd_una) &&
before(shinfo->tskey, tcp_sk(sk)->snd_una))
__skb_tstamp_tx(skb, NULL, sk, SCM_TSTAMP_ACK);
}
static int tcp_clean_rtx_queue(struct sock *sk, int prior_fackets,
u32 prior_snd_una, int *acked,
struct tcp_sacktag_state *sack)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct skb_mstamp first_ackt, last_ackt;
struct skb_mstamp *now = &sack->ack_time;
struct tcp_sock *tp = tcp_sk(sk);
u32 prior_sacked = tp->sacked_out;
u32 reord = tp->packets_out;
bool fully_acked = true;
long sack_rtt_us = -1L;
long seq_rtt_us = -1L;
long ca_rtt_us = -1L;
struct sk_buff *skb;
u32 pkts_acked = 0;
u32 last_in_flight = 0;
bool rtt_update;
int flag = 0;
first_ackt.v64 = 0;
while ((skb = tcp_write_queue_head(sk)) && skb != tcp_send_head(sk)) {
struct tcp_skb_cb *scb = TCP_SKB_CB(skb);
u8 sacked = scb->sacked;
u32 acked_pcount;
tcp_ack_tstamp(sk, skb, prior_snd_una);
if (after(scb->end_seq, tp->snd_una)) {
if (tcp_skb_pcount(skb) == 1 ||
!after(tp->snd_una, scb->seq))
break;
acked_pcount = tcp_tso_acked(sk, skb);
if (!acked_pcount)
break;
fully_acked = false;
} else {
prefetchw(skb->next);
acked_pcount = tcp_skb_pcount(skb);
}
if (unlikely(sacked & TCPCB_RETRANS)) {
if (sacked & TCPCB_SACKED_RETRANS)
tp->retrans_out -= acked_pcount;
flag |= FLAG_RETRANS_DATA_ACKED;
} else if (!(sacked & TCPCB_SACKED_ACKED)) {
last_ackt = skb->skb_mstamp;
WARN_ON_ONCE(last_ackt.v64 == 0);
if (!first_ackt.v64)
first_ackt = last_ackt;
last_in_flight = TCP_SKB_CB(skb)->tx.in_flight;
reord = min(pkts_acked, reord);
if (!after(scb->end_seq, tp->high_seq))
flag |= FLAG_ORIG_SACK_ACKED;
}
if (sacked & TCPCB_SACKED_ACKED) {
tp->sacked_out -= acked_pcount;
} else if (tcp_is_sack(tp)) {
tp->delivered += acked_pcount;
if (!tcp_skb_spurious_retrans(tp, skb))
tcp_rack_advance(tp, sacked, scb->end_seq,
&skb->skb_mstamp,
&sack->ack_time);
}
if (sacked & TCPCB_LOST)
tp->lost_out -= acked_pcount;
tp->packets_out -= acked_pcount;
pkts_acked += acked_pcount;
tcp_rate_skb_delivered(sk, skb, sack->rate);
if (likely(!(scb->tcp_flags & TCPHDR_SYN))) {
flag |= FLAG_DATA_ACKED;
} else {
flag |= FLAG_SYN_ACKED;
tp->retrans_stamp = 0;
}
if (!fully_acked)
break;
tcp_unlink_write_queue(skb, sk);
sk_wmem_free_skb(sk, skb);
if (unlikely(skb == tp->retransmit_skb_hint))
tp->retransmit_skb_hint = NULL;
if (unlikely(skb == tp->lost_skb_hint))
tp->lost_skb_hint = NULL;
}
if (!skb)
tcp_chrono_stop(sk, TCP_CHRONO_BUSY);
if (likely(between(tp->snd_up, prior_snd_una, tp->snd_una)))
tp->snd_up = tp->snd_una;
if (skb && (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_ACKED))
flag |= FLAG_SACK_RENEGING;
if (likely(first_ackt.v64) && !(flag & FLAG_RETRANS_DATA_ACKED)) {
seq_rtt_us = skb_mstamp_us_delta(now, &first_ackt);
ca_rtt_us = skb_mstamp_us_delta(now, &last_ackt);
}
if (sack->first_sackt.v64) {
sack_rtt_us = skb_mstamp_us_delta(now, &sack->first_sackt);
ca_rtt_us = skb_mstamp_us_delta(now, &sack->last_sackt);
}
sack->rate->rtt_us = ca_rtt_us;
rtt_update = tcp_ack_update_rtt(sk, flag, seq_rtt_us, sack_rtt_us,
ca_rtt_us);
if (flag & FLAG_ACKED) {
tcp_rearm_rto(sk);
if (unlikely(icsk->icsk_mtup.probe_size &&
!after(tp->mtu_probe.probe_seq_end, tp->snd_una))) {
tcp_mtup_probe_success(sk);
}
if (tcp_is_reno(tp)) {
tcp_remove_reno_sacks(sk, pkts_acked);
} else {
int delta;
if (reord < prior_fackets)
tcp_update_reordering(sk, tp->fackets_out - reord, 0);
delta = tcp_is_fack(tp) ? pkts_acked :
prior_sacked - tp->sacked_out;
tp->lost_cnt_hint -= min(tp->lost_cnt_hint, delta);
}
tp->fackets_out -= min(pkts_acked, tp->fackets_out);
} else if (skb && rtt_update && sack_rtt_us >= 0 &&
sack_rtt_us > skb_mstamp_us_delta(now, &skb->skb_mstamp)) {
tcp_rearm_rto(sk);
}
if (icsk->icsk_ca_ops->pkts_acked) {
struct ack_sample sample = { .pkts_acked = pkts_acked,
.rtt_us = ca_rtt_us,
.in_flight = last_in_flight };
icsk->icsk_ca_ops->pkts_acked(sk, &sample);
}
#if FASTRETRANS_DEBUG > 0
WARN_ON((int)tp->sacked_out < 0);
WARN_ON((int)tp->lost_out < 0);
WARN_ON((int)tp->retrans_out < 0);
if (!tp->packets_out && tcp_is_sack(tp)) {
icsk = inet_csk(sk);
if (tp->lost_out) {
pr_debug("Leak l=%u %d\n",
tp->lost_out, icsk->icsk_ca_state);
tp->lost_out = 0;
}
if (tp->sacked_out) {
pr_debug("Leak s=%u %d\n",
tp->sacked_out, icsk->icsk_ca_state);
tp->sacked_out = 0;
}
if (tp->retrans_out) {
pr_debug("Leak r=%u %d\n",
tp->retrans_out, icsk->icsk_ca_state);
tp->retrans_out = 0;
}
}
#endif
*acked = pkts_acked;
return flag;
}
static void tcp_ack_probe(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
if (!after(TCP_SKB_CB(tcp_send_head(sk))->end_seq, tcp_wnd_end(tp))) {
icsk->icsk_backoff = 0;
inet_csk_clear_xmit_timer(sk, ICSK_TIME_PROBE0);
} else {
unsigned long when = tcp_probe0_when(sk, TCP_RTO_MAX);
inet_csk_reset_xmit_timer(sk, ICSK_TIME_PROBE0,
when, TCP_RTO_MAX);
}
}
static inline bool tcp_ack_is_dubious(const struct sock *sk, const int flag)
{
return !(flag & FLAG_NOT_DUP) || (flag & FLAG_CA_ALERT) ||
inet_csk(sk)->icsk_ca_state != TCP_CA_Open;
}
static inline bool tcp_may_raise_cwnd(const struct sock *sk, const int flag)
{
if (tcp_sk(sk)->reordering > sock_net(sk)->ipv4.sysctl_tcp_reordering)
return flag & FLAG_FORWARD_PROGRESS;
return flag & FLAG_DATA_ACKED;
}
static void tcp_cong_control(struct sock *sk, u32 ack, u32 acked_sacked,
int flag, const struct rate_sample *rs)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_ca_ops->cong_control) {
icsk->icsk_ca_ops->cong_control(sk, rs);
return;
}
if (tcp_in_cwnd_reduction(sk)) {
tcp_cwnd_reduction(sk, acked_sacked, flag);
} else if (tcp_may_raise_cwnd(sk, flag)) {
tcp_cong_avoid(sk, ack, acked_sacked);
}
tcp_update_pacing_rate(sk);
}
static inline bool tcp_may_update_window(const struct tcp_sock *tp,
const u32 ack, const u32 ack_seq,
const u32 nwin)
{
return after(ack, tp->snd_una) ||
after(ack_seq, tp->snd_wl1) ||
(ack_seq == tp->snd_wl1 && nwin > tp->snd_wnd);
}
static void tcp_snd_una_update(struct tcp_sock *tp, u32 ack)
{
u32 delta = ack - tp->snd_una;
sock_owned_by_me((struct sock *)tp);
tp->bytes_acked += delta;
tp->snd_una = ack;
}
static void tcp_rcv_nxt_update(struct tcp_sock *tp, u32 seq)
{
u32 delta = seq - tp->rcv_nxt;
sock_owned_by_me((struct sock *)tp);
tp->bytes_received += delta;
tp->rcv_nxt = seq;
}
static int tcp_ack_update_window(struct sock *sk, const struct sk_buff *skb, u32 ack,
u32 ack_seq)
{
struct tcp_sock *tp = tcp_sk(sk);
int flag = 0;
u32 nwin = ntohs(tcp_hdr(skb)->window);
if (likely(!tcp_hdr(skb)->syn))
nwin <<= tp->rx_opt.snd_wscale;
if (tcp_may_update_window(tp, ack, ack_seq, nwin)) {
flag |= FLAG_WIN_UPDATE;
tcp_update_wl(tp, ack_seq);
if (tp->snd_wnd != nwin) {
tp->snd_wnd = nwin;
tp->pred_flags = 0;
tcp_fast_path_check(sk);
if (tcp_send_head(sk))
tcp_slow_start_after_idle_check(sk);
if (nwin > tp->max_window) {
tp->max_window = nwin;
tcp_sync_mss(sk, inet_csk(sk)->icsk_pmtu_cookie);
}
}
}
tcp_snd_una_update(tp, ack);
return flag;
}
static bool __tcp_oow_rate_limited(struct net *net, int mib_idx,
u32 *last_oow_ack_time)
{
if (*last_oow_ack_time) {
s32 elapsed = (s32)(tcp_time_stamp - *last_oow_ack_time);
if (0 <= elapsed && elapsed < sysctl_tcp_invalid_ratelimit) {
NET_INC_STATS(net, mib_idx);
return true;
}
}
*last_oow_ack_time = tcp_time_stamp;
return false;
}
bool tcp_oow_rate_limited(struct net *net, const struct sk_buff *skb,
int mib_idx, u32 *last_oow_ack_time)
{
if ((TCP_SKB_CB(skb)->seq != TCP_SKB_CB(skb)->end_seq) &&
!tcp_hdr(skb)->syn)
return false;
return __tcp_oow_rate_limited(net, mib_idx, last_oow_ack_time);
}
static void tcp_send_challenge_ack(struct sock *sk, const struct sk_buff *skb)
{
static u32 challenge_timestamp;
static unsigned int challenge_count;
struct tcp_sock *tp = tcp_sk(sk);
u32 count, now;
if (__tcp_oow_rate_limited(sock_net(sk),
LINUX_MIB_TCPACKSKIPPEDCHALLENGE,
&tp->last_oow_ack_time))
return;
now = jiffies / HZ;
if (now != challenge_timestamp) {
u32 half = (sysctl_tcp_challenge_ack_limit + 1) >> 1;
challenge_timestamp = now;
WRITE_ONCE(challenge_count, half +
prandom_u32_max(sysctl_tcp_challenge_ack_limit));
}
count = READ_ONCE(challenge_count);
if (count > 0) {
WRITE_ONCE(challenge_count, count - 1);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPCHALLENGEACK);
tcp_send_ack(sk);
}
}
static void tcp_store_ts_recent(struct tcp_sock *tp)
{
tp->rx_opt.ts_recent = tp->rx_opt.rcv_tsval;
tp->rx_opt.ts_recent_stamp = get_seconds();
}
static void tcp_replace_ts_recent(struct tcp_sock *tp, u32 seq)
{
if (tp->rx_opt.saw_tstamp && !after(seq, tp->rcv_wup)) {
if (tcp_paws_check(&tp->rx_opt, 0))
tcp_store_ts_recent(tp);
}
}
static void tcp_process_tlp_ack(struct sock *sk, u32 ack, int flag)
{
struct tcp_sock *tp = tcp_sk(sk);
if (before(ack, tp->tlp_high_seq))
return;
if (flag & FLAG_DSACKING_ACK) {
tp->tlp_high_seq = 0;
} else if (after(ack, tp->tlp_high_seq)) {
tcp_init_cwnd_reduction(sk);
tcp_set_ca_state(sk, TCP_CA_CWR);
tcp_end_cwnd_reduction(sk);
tcp_try_keep_open(sk);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPLOSSPROBERECOVERY);
} else if (!(flag & (FLAG_SND_UNA_ADVANCED |
FLAG_NOT_DUP | FLAG_DATA_SACKED))) {
tp->tlp_high_seq = 0;
}
}
static inline void tcp_in_ack_event(struct sock *sk, u32 flags)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_ca_ops->in_ack_event)
icsk->icsk_ca_ops->in_ack_event(sk, flags);
}
static void tcp_xmit_recovery(struct sock *sk, int rexmit)
{
struct tcp_sock *tp = tcp_sk(sk);
if (rexmit == REXMIT_NONE)
return;
if (unlikely(rexmit == 2)) {
__tcp_push_pending_frames(sk, tcp_current_mss(sk),
TCP_NAGLE_OFF);
if (after(tp->snd_nxt, tp->high_seq))
return;
tp->frto = 0;
}
tcp_xmit_retransmit_queue(sk);
}
static int tcp_ack(struct sock *sk, const struct sk_buff *skb, int flag)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_sacktag_state sack_state;
struct rate_sample rs = { .prior_delivered = 0 };
u32 prior_snd_una = tp->snd_una;
u32 ack_seq = TCP_SKB_CB(skb)->seq;
u32 ack = TCP_SKB_CB(skb)->ack_seq;
bool is_dupack = false;
u32 prior_fackets;
int prior_packets = tp->packets_out;
u32 delivered = tp->delivered;
u32 lost = tp->lost;
int acked = 0;
int rexmit = REXMIT_NONE;
sack_state.first_sackt.v64 = 0;
sack_state.rate = &rs;
prefetchw(sk->sk_write_queue.next);
if (before(ack, prior_snd_una)) {
if (before(ack, prior_snd_una - tp->max_window)) {
tcp_send_challenge_ack(sk, skb);
return -1;
}
goto old_ack;
}
if (after(ack, tp->snd_nxt))
goto invalid_ack;
skb_mstamp_get(&sack_state.ack_time);
if (icsk->icsk_pending == ICSK_TIME_LOSS_PROBE)
tcp_rearm_rto(sk);
if (after(ack, prior_snd_una)) {
flag |= FLAG_SND_UNA_ADVANCED;
icsk->icsk_retransmits = 0;
}
prior_fackets = tp->fackets_out;
rs.prior_in_flight = tcp_packets_in_flight(tp);
if (flag & FLAG_UPDATE_TS_RECENT)
tcp_replace_ts_recent(tp, TCP_SKB_CB(skb)->seq);
if (!(flag & FLAG_SLOWPATH) && after(ack, prior_snd_una)) {
tcp_update_wl(tp, ack_seq);
tcp_snd_una_update(tp, ack);
flag |= FLAG_WIN_UPDATE;
tcp_in_ack_event(sk, CA_ACK_WIN_UPDATE);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPHPACKS);
} else {
u32 ack_ev_flags = CA_ACK_SLOWPATH;
if (ack_seq != TCP_SKB_CB(skb)->end_seq)
flag |= FLAG_DATA;
else
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPPUREACKS);
flag |= tcp_ack_update_window(sk, skb, ack, ack_seq);
if (TCP_SKB_CB(skb)->sacked)
flag |= tcp_sacktag_write_queue(sk, skb, prior_snd_una,
&sack_state);
if (tcp_ecn_rcv_ecn_echo(tp, tcp_hdr(skb))) {
flag |= FLAG_ECE;
ack_ev_flags |= CA_ACK_ECE;
}
if (flag & FLAG_WIN_UPDATE)
ack_ev_flags |= CA_ACK_WIN_UPDATE;
tcp_in_ack_event(sk, ack_ev_flags);
}
sk->sk_err_soft = 0;
icsk->icsk_probes_out = 0;
tp->rcv_tstamp = tcp_time_stamp;
if (!prior_packets)
goto no_queue;
flag |= tcp_clean_rtx_queue(sk, prior_fackets, prior_snd_una, &acked,
&sack_state);
if (tcp_ack_is_dubious(sk, flag)) {
is_dupack = !(flag & (FLAG_SND_UNA_ADVANCED | FLAG_NOT_DUP));
tcp_fastretrans_alert(sk, acked, is_dupack, &flag, &rexmit,
&sack_state.ack_time);
}
if (tp->tlp_high_seq)
tcp_process_tlp_ack(sk, ack, flag);
if ((flag & FLAG_FORWARD_PROGRESS) || !(flag & FLAG_NOT_DUP))
sk_dst_confirm(sk);
if (icsk->icsk_pending == ICSK_TIME_RETRANS)
tcp_schedule_loss_probe(sk);
delivered = tp->delivered - delivered;
lost = tp->lost - lost;
tcp_rate_gen(sk, delivered, lost, &sack_state.ack_time,
sack_state.rate);
tcp_cong_control(sk, ack, delivered, flag, sack_state.rate);
tcp_xmit_recovery(sk, rexmit);
return 1;
no_queue:
if (flag & FLAG_DSACKING_ACK)
tcp_fastretrans_alert(sk, acked, is_dupack, &flag, &rexmit,
&sack_state.ack_time);
if (tcp_send_head(sk))
tcp_ack_probe(sk);
if (tp->tlp_high_seq)
tcp_process_tlp_ack(sk, ack, flag);
return 1;
invalid_ack:
SOCK_DEBUG(sk, "Ack %u after %u:%u\n", ack, tp->snd_una, tp->snd_nxt);
return -1;
old_ack:
if (TCP_SKB_CB(skb)->sacked) {
skb_mstamp_get(&sack_state.ack_time);
flag |= tcp_sacktag_write_queue(sk, skb, prior_snd_una,
&sack_state);
tcp_fastretrans_alert(sk, acked, is_dupack, &flag, &rexmit,
&sack_state.ack_time);
tcp_xmit_recovery(sk, rexmit);
}
SOCK_DEBUG(sk, "Ack %u before %u:%u\n", ack, tp->snd_una, tp->snd_nxt);
return 0;
}
static void tcp_parse_fastopen_option(int len, const unsigned char *cookie,
bool syn, struct tcp_fastopen_cookie *foc,
bool exp_opt)
{
if (!foc || !syn || len < 0 || (len & 1))
return;
if (len >= TCP_FASTOPEN_COOKIE_MIN &&
len <= TCP_FASTOPEN_COOKIE_MAX)
memcpy(foc->val, cookie, len);
else if (len != 0)
len = -1;
foc->len = len;
foc->exp = exp_opt;
}
void tcp_parse_options(const struct sk_buff *skb,
struct tcp_options_received *opt_rx, int estab,
struct tcp_fastopen_cookie *foc)
{
const unsigned char *ptr;
const struct tcphdr *th = tcp_hdr(skb);
int length = (th->doff * 4) - sizeof(struct tcphdr);
ptr = (const unsigned char *)(th + 1);
opt_rx->saw_tstamp = 0;
while (length > 0) {
int opcode = *ptr++;
int opsize;
switch (opcode) {
case TCPOPT_EOL:
return;
case TCPOPT_NOP:
length--;
continue;
default:
opsize = *ptr++;
if (opsize < 2)
return;
if (opsize > length)
return;
switch (opcode) {
case TCPOPT_MSS:
if (opsize == TCPOLEN_MSS && th->syn && !estab) {
u16 in_mss = get_unaligned_be16(ptr);
if (in_mss) {
if (opt_rx->user_mss &&
opt_rx->user_mss < in_mss)
in_mss = opt_rx->user_mss;
opt_rx->mss_clamp = in_mss;
}
}
break;
case TCPOPT_WINDOW:
if (opsize == TCPOLEN_WINDOW && th->syn &&
!estab && sysctl_tcp_window_scaling) {
__u8 snd_wscale = *(__u8 *)ptr;
opt_rx->wscale_ok = 1;
if (snd_wscale > 14) {
net_info_ratelimited("%s: Illegal window scaling value %d >14 received\n",
__func__,
snd_wscale);
snd_wscale = 14;
}
opt_rx->snd_wscale = snd_wscale;
}
break;
case TCPOPT_TIMESTAMP:
if ((opsize == TCPOLEN_TIMESTAMP) &&
((estab && opt_rx->tstamp_ok) ||
(!estab && sysctl_tcp_timestamps))) {
opt_rx->saw_tstamp = 1;
opt_rx->rcv_tsval = get_unaligned_be32(ptr);
opt_rx->rcv_tsecr = get_unaligned_be32(ptr + 4);
}
break;
case TCPOPT_SACK_PERM:
if (opsize == TCPOLEN_SACK_PERM && th->syn &&
!estab && sysctl_tcp_sack) {
opt_rx->sack_ok = TCP_SACK_SEEN;
tcp_sack_reset(opt_rx);
}
break;
case TCPOPT_SACK:
if ((opsize >= (TCPOLEN_SACK_BASE + TCPOLEN_SACK_PERBLOCK)) &&
!((opsize - TCPOLEN_SACK_BASE) % TCPOLEN_SACK_PERBLOCK) &&
opt_rx->sack_ok) {
TCP_SKB_CB(skb)->sacked = (ptr - 2) - (unsigned char *)th;
}
break;
#ifdef CONFIG_TCP_MD5SIG
case TCPOPT_MD5SIG:
break;
#endif
case TCPOPT_FASTOPEN:
tcp_parse_fastopen_option(
opsize - TCPOLEN_FASTOPEN_BASE,
ptr, th->syn, foc, false);
break;
case TCPOPT_EXP:
if (opsize >= TCPOLEN_EXP_FASTOPEN_BASE &&
get_unaligned_be16(ptr) ==
TCPOPT_FASTOPEN_MAGIC)
tcp_parse_fastopen_option(opsize -
TCPOLEN_EXP_FASTOPEN_BASE,
ptr + 2, th->syn, foc, true);
break;
}
ptr += opsize-2;
length -= opsize;
}
}
}
static bool tcp_parse_aligned_timestamp(struct tcp_sock *tp, const struct tcphdr *th)
{
const __be32 *ptr = (const __be32 *)(th + 1);
if (*ptr == htonl((TCPOPT_NOP << 24) | (TCPOPT_NOP << 16)
| (TCPOPT_TIMESTAMP << 8) | TCPOLEN_TIMESTAMP)) {
tp->rx_opt.saw_tstamp = 1;
++ptr;
tp->rx_opt.rcv_tsval = ntohl(*ptr);
++ptr;
if (*ptr)
tp->rx_opt.rcv_tsecr = ntohl(*ptr) - tp->tsoffset;
else
tp->rx_opt.rcv_tsecr = 0;
return true;
}
return false;
}
static bool tcp_fast_parse_options(const struct sk_buff *skb,
const struct tcphdr *th, struct tcp_sock *tp)
{
if (th->doff == (sizeof(*th) / 4)) {
tp->rx_opt.saw_tstamp = 0;
return false;
} else if (tp->rx_opt.tstamp_ok &&
th->doff == ((sizeof(*th) + TCPOLEN_TSTAMP_ALIGNED) / 4)) {
if (tcp_parse_aligned_timestamp(tp, th))
return true;
}
tcp_parse_options(skb, &tp->rx_opt, 1, NULL);
if (tp->rx_opt.saw_tstamp && tp->rx_opt.rcv_tsecr)
tp->rx_opt.rcv_tsecr -= tp->tsoffset;
return true;
}
const u8 *tcp_parse_md5sig_option(const struct tcphdr *th)
{
int length = (th->doff << 2) - sizeof(*th);
const u8 *ptr = (const u8 *)(th + 1);
if (length < TCPOLEN_MD5SIG)
return NULL;
while (length > 0) {
int opcode = *ptr++;
int opsize;
switch (opcode) {
case TCPOPT_EOL:
return NULL;
case TCPOPT_NOP:
length--;
continue;
default:
opsize = *ptr++;
if (opsize < 2 || opsize > length)
return NULL;
if (opcode == TCPOPT_MD5SIG)
return opsize == TCPOLEN_MD5SIG ? ptr : NULL;
}
ptr += opsize - 2;
length -= opsize;
}
return NULL;
}
static int tcp_disordered_ack(const struct sock *sk, const struct sk_buff *skb)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct tcphdr *th = tcp_hdr(skb);
u32 seq = TCP_SKB_CB(skb)->seq;
u32 ack = TCP_SKB_CB(skb)->ack_seq;
return (
(th->ack && seq == TCP_SKB_CB(skb)->end_seq && seq == tp->rcv_nxt) &&
ack == tp->snd_una &&
!tcp_may_update_window(tp, ack, seq, ntohs(th->window) << tp->rx_opt.snd_wscale) &&
(s32)(tp->rx_opt.ts_recent - tp->rx_opt.rcv_tsval) <= (inet_csk(sk)->icsk_rto * 1024) / HZ);
}
static inline bool tcp_paws_discard(const struct sock *sk,
const struct sk_buff *skb)
{
const struct tcp_sock *tp = tcp_sk(sk);
return !tcp_paws_check(&tp->rx_opt, TCP_PAWS_WINDOW) &&
!tcp_disordered_ack(sk, skb);
}
static inline bool tcp_sequence(const struct tcp_sock *tp, u32 seq, u32 end_seq)
{
return !before(end_seq, tp->rcv_wup) &&
!after(seq, tp->rcv_nxt + tcp_receive_window(tp));
}
void tcp_reset(struct sock *sk)
{
switch (sk->sk_state) {
case TCP_SYN_SENT:
sk->sk_err = ECONNREFUSED;
break;
case TCP_CLOSE_WAIT:
sk->sk_err = EPIPE;
break;
case TCP_CLOSE:
return;
default:
sk->sk_err = ECONNRESET;
}
smp_wmb();
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_error_report(sk);
tcp_done(sk);
}
void tcp_fin(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
inet_csk_schedule_ack(sk);
sk->sk_shutdown |= RCV_SHUTDOWN;
sock_set_flag(sk, SOCK_DONE);
switch (sk->sk_state) {
case TCP_SYN_RECV:
case TCP_ESTABLISHED:
tcp_set_state(sk, TCP_CLOSE_WAIT);
inet_csk(sk)->icsk_ack.pingpong = 1;
break;
case TCP_CLOSE_WAIT:
case TCP_CLOSING:
break;
case TCP_LAST_ACK:
break;
case TCP_FIN_WAIT1:
tcp_send_ack(sk);
tcp_set_state(sk, TCP_CLOSING);
break;
case TCP_FIN_WAIT2:
tcp_send_ack(sk);
tcp_time_wait(sk, TCP_TIME_WAIT, 0);
break;
default:
pr_err("%s: Impossible, sk->sk_state=%d\n",
__func__, sk->sk_state);
break;
}
skb_rbtree_purge(&tp->out_of_order_queue);
if (tcp_is_sack(tp))
tcp_sack_reset(&tp->rx_opt);
sk_mem_reclaim(sk);
if (!sock_flag(sk, SOCK_DEAD)) {
sk->sk_state_change(sk);
if (sk->sk_shutdown == SHUTDOWN_MASK ||
sk->sk_state == TCP_CLOSE)
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_HUP);
else
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_IN);
}
}
static inline bool tcp_sack_extend(struct tcp_sack_block *sp, u32 seq,
u32 end_seq)
{
if (!after(seq, sp->end_seq) && !after(sp->start_seq, end_seq)) {
if (before(seq, sp->start_seq))
sp->start_seq = seq;
if (after(end_seq, sp->end_seq))
sp->end_seq = end_seq;
return true;
}
return false;
}
static void tcp_dsack_set(struct sock *sk, u32 seq, u32 end_seq)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_is_sack(tp) && sysctl_tcp_dsack) {
int mib_idx;
if (before(seq, tp->rcv_nxt))
mib_idx = LINUX_MIB_TCPDSACKOLDSENT;
else
mib_idx = LINUX_MIB_TCPDSACKOFOSENT;
NET_INC_STATS(sock_net(sk), mib_idx);
tp->rx_opt.dsack = 1;
tp->duplicate_sack[0].start_seq = seq;
tp->duplicate_sack[0].end_seq = end_seq;
}
}
static void tcp_dsack_extend(struct sock *sk, u32 seq, u32 end_seq)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tp->rx_opt.dsack)
tcp_dsack_set(sk, seq, end_seq);
else
tcp_sack_extend(tp->duplicate_sack, seq, end_seq);
}
static void tcp_send_dupack(struct sock *sk, const struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
if (TCP_SKB_CB(skb)->end_seq != TCP_SKB_CB(skb)->seq &&
before(TCP_SKB_CB(skb)->seq, tp->rcv_nxt)) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_DELAYEDACKLOST);
tcp_enter_quickack_mode(sk);
if (tcp_is_sack(tp) && sysctl_tcp_dsack) {
u32 end_seq = TCP_SKB_CB(skb)->end_seq;
if (after(TCP_SKB_CB(skb)->end_seq, tp->rcv_nxt))
end_seq = tp->rcv_nxt;
tcp_dsack_set(sk, TCP_SKB_CB(skb)->seq, end_seq);
}
}
tcp_send_ack(sk);
}
static void tcp_sack_maybe_coalesce(struct tcp_sock *tp)
{
int this_sack;
struct tcp_sack_block *sp = &tp->selective_acks[0];
struct tcp_sack_block *swalk = sp + 1;
for (this_sack = 1; this_sack < tp->rx_opt.num_sacks;) {
if (tcp_sack_extend(sp, swalk->start_seq, swalk->end_seq)) {
int i;
tp->rx_opt.num_sacks--;
for (i = this_sack; i < tp->rx_opt.num_sacks; i++)
sp[i] = sp[i + 1];
continue;
}
this_sack++, swalk++;
}
}
static void tcp_sack_new_ofo_skb(struct sock *sk, u32 seq, u32 end_seq)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_sack_block *sp = &tp->selective_acks[0];
int cur_sacks = tp->rx_opt.num_sacks;
int this_sack;
if (!cur_sacks)
goto new_sack;
for (this_sack = 0; this_sack < cur_sacks; this_sack++, sp++) {
if (tcp_sack_extend(sp, seq, end_seq)) {
for (; this_sack > 0; this_sack--, sp--)
swap(*sp, *(sp - 1));
if (cur_sacks > 1)
tcp_sack_maybe_coalesce(tp);
return;
}
}
if (this_sack >= TCP_NUM_SACKS) {
this_sack--;
tp->rx_opt.num_sacks--;
sp--;
}
for (; this_sack > 0; this_sack--, sp--)
*sp = *(sp - 1);
new_sack:
sp->start_seq = seq;
sp->end_seq = end_seq;
tp->rx_opt.num_sacks++;
}
static void tcp_sack_remove(struct tcp_sock *tp)
{
struct tcp_sack_block *sp = &tp->selective_acks[0];
int num_sacks = tp->rx_opt.num_sacks;
int this_sack;
if (RB_EMPTY_ROOT(&tp->out_of_order_queue)) {
tp->rx_opt.num_sacks = 0;
return;
}
for (this_sack = 0; this_sack < num_sacks;) {
if (!before(tp->rcv_nxt, sp->start_seq)) {
int i;
WARN_ON(before(tp->rcv_nxt, sp->end_seq));
for (i = this_sack+1; i < num_sacks; i++)
tp->selective_acks[i-1] = tp->selective_acks[i];
num_sacks--;
continue;
}
this_sack++;
sp++;
}
tp->rx_opt.num_sacks = num_sacks;
}
static bool tcp_try_coalesce(struct sock *sk,
struct sk_buff *to,
struct sk_buff *from,
bool *fragstolen)
{
int delta;
*fragstolen = false;
if (TCP_SKB_CB(from)->seq != TCP_SKB_CB(to)->end_seq)
return false;
if (!skb_try_coalesce(to, from, fragstolen, &delta))
return false;
atomic_add(delta, &sk->sk_rmem_alloc);
sk_mem_charge(sk, delta);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPRCVCOALESCE);
TCP_SKB_CB(to)->end_seq = TCP_SKB_CB(from)->end_seq;
TCP_SKB_CB(to)->ack_seq = TCP_SKB_CB(from)->ack_seq;
TCP_SKB_CB(to)->tcp_flags |= TCP_SKB_CB(from)->tcp_flags;
return true;
}
static void tcp_drop(struct sock *sk, struct sk_buff *skb)
{
sk_drops_add(sk, skb);
__kfree_skb(skb);
}
static void tcp_ofo_queue(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
__u32 dsack_high = tp->rcv_nxt;
bool fin, fragstolen, eaten;
struct sk_buff *skb, *tail;
struct rb_node *p;
p = rb_first(&tp->out_of_order_queue);
while (p) {
skb = rb_entry(p, struct sk_buff, rbnode);
if (after(TCP_SKB_CB(skb)->seq, tp->rcv_nxt))
break;
if (before(TCP_SKB_CB(skb)->seq, dsack_high)) {
__u32 dsack = dsack_high;
if (before(TCP_SKB_CB(skb)->end_seq, dsack_high))
dsack_high = TCP_SKB_CB(skb)->end_seq;
tcp_dsack_extend(sk, TCP_SKB_CB(skb)->seq, dsack);
}
p = rb_next(p);
rb_erase(&skb->rbnode, &tp->out_of_order_queue);
if (unlikely(!after(TCP_SKB_CB(skb)->end_seq, tp->rcv_nxt))) {
SOCK_DEBUG(sk, "ofo packet was already received\n");
tcp_drop(sk, skb);
continue;
}
SOCK_DEBUG(sk, "ofo requeuing : rcv_next %X seq %X - %X\n",
tp->rcv_nxt, TCP_SKB_CB(skb)->seq,
TCP_SKB_CB(skb)->end_seq);
tail = skb_peek_tail(&sk->sk_receive_queue);
eaten = tail && tcp_try_coalesce(sk, tail, skb, &fragstolen);
tcp_rcv_nxt_update(tp, TCP_SKB_CB(skb)->end_seq);
fin = TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN;
if (!eaten)
__skb_queue_tail(&sk->sk_receive_queue, skb);
else
kfree_skb_partial(skb, fragstolen);
if (unlikely(fin)) {
tcp_fin(sk);
break;
}
}
}
static int tcp_try_rmem_schedule(struct sock *sk, struct sk_buff *skb,
unsigned int size)
{
if (atomic_read(&sk->sk_rmem_alloc) > sk->sk_rcvbuf ||
!sk_rmem_schedule(sk, skb, size)) {
if (tcp_prune_queue(sk) < 0)
return -1;
while (!sk_rmem_schedule(sk, skb, size)) {
if (!tcp_prune_ofo_queue(sk))
return -1;
}
}
return 0;
}
static void tcp_data_queue_ofo(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct rb_node **p, *q, *parent;
struct sk_buff *skb1;
u32 seq, end_seq;
bool fragstolen;
tcp_ecn_check_ce(tp, skb);
if (unlikely(tcp_try_rmem_schedule(sk, skb, skb->truesize))) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPOFODROP);
tcp_drop(sk, skb);
return;
}
tp->pred_flags = 0;
inet_csk_schedule_ack(sk);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPOFOQUEUE);
seq = TCP_SKB_CB(skb)->seq;
end_seq = TCP_SKB_CB(skb)->end_seq;
SOCK_DEBUG(sk, "out of order segment: rcv_next %X seq %X - %X\n",
tp->rcv_nxt, seq, end_seq);
p = &tp->out_of_order_queue.rb_node;
if (RB_EMPTY_ROOT(&tp->out_of_order_queue)) {
if (tcp_is_sack(tp)) {
tp->rx_opt.num_sacks = 1;
tp->selective_acks[0].start_seq = seq;
tp->selective_acks[0].end_seq = end_seq;
}
rb_link_node(&skb->rbnode, NULL, p);
rb_insert_color(&skb->rbnode, &tp->out_of_order_queue);
tp->ooo_last_skb = skb;
goto end;
}
if (tcp_try_coalesce(sk, tp->ooo_last_skb, skb, &fragstolen)) {
coalesce_done:
tcp_grow_window(sk, skb);
kfree_skb_partial(skb, fragstolen);
skb = NULL;
goto add_sack;
}
if (!before(seq, TCP_SKB_CB(tp->ooo_last_skb)->end_seq)) {
parent = &tp->ooo_last_skb->rbnode;
p = &parent->rb_right;
goto insert;
}
parent = NULL;
while (*p) {
parent = *p;
skb1 = rb_entry(parent, struct sk_buff, rbnode);
if (before(seq, TCP_SKB_CB(skb1)->seq)) {
p = &parent->rb_left;
continue;
}
if (before(seq, TCP_SKB_CB(skb1)->end_seq)) {
if (!after(end_seq, TCP_SKB_CB(skb1)->end_seq)) {
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPOFOMERGE);
__kfree_skb(skb);
skb = NULL;
tcp_dsack_set(sk, seq, end_seq);
goto add_sack;
}
if (after(seq, TCP_SKB_CB(skb1)->seq)) {
tcp_dsack_set(sk, seq, TCP_SKB_CB(skb1)->end_seq);
} else {
rb_replace_node(&skb1->rbnode, &skb->rbnode,
&tp->out_of_order_queue);
tcp_dsack_extend(sk,
TCP_SKB_CB(skb1)->seq,
TCP_SKB_CB(skb1)->end_seq);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPOFOMERGE);
__kfree_skb(skb1);
goto merge_right;
}
} else if (tcp_try_coalesce(sk, skb1, skb, &fragstolen)) {
goto coalesce_done;
}
p = &parent->rb_right;
}
insert:
rb_link_node(&skb->rbnode, parent, p);
rb_insert_color(&skb->rbnode, &tp->out_of_order_queue);
merge_right:
while ((q = rb_next(&skb->rbnode)) != NULL) {
skb1 = rb_entry(q, struct sk_buff, rbnode);
if (!after(end_seq, TCP_SKB_CB(skb1)->seq))
break;
if (before(end_seq, TCP_SKB_CB(skb1)->end_seq)) {
tcp_dsack_extend(sk, TCP_SKB_CB(skb1)->seq,
end_seq);
break;
}
rb_erase(&skb1->rbnode, &tp->out_of_order_queue);
tcp_dsack_extend(sk, TCP_SKB_CB(skb1)->seq,
TCP_SKB_CB(skb1)->end_seq);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPOFOMERGE);
tcp_drop(sk, skb1);
}
if (!q)
tp->ooo_last_skb = skb;
add_sack:
if (tcp_is_sack(tp))
tcp_sack_new_ofo_skb(sk, seq, end_seq);
end:
if (skb) {
tcp_grow_window(sk, skb);
skb_condense(skb);
skb_set_owner_r(skb, sk);
}
}
static int __must_check tcp_queue_rcv(struct sock *sk, struct sk_buff *skb, int hdrlen,
bool *fragstolen)
{
int eaten;
struct sk_buff *tail = skb_peek_tail(&sk->sk_receive_queue);
__skb_pull(skb, hdrlen);
eaten = (tail &&
tcp_try_coalesce(sk, tail, skb, fragstolen)) ? 1 : 0;
tcp_rcv_nxt_update(tcp_sk(sk), TCP_SKB_CB(skb)->end_seq);
if (!eaten) {
__skb_queue_tail(&sk->sk_receive_queue, skb);
skb_set_owner_r(skb, sk);
}
return eaten;
}
int tcp_send_rcvq(struct sock *sk, struct msghdr *msg, size_t size)
{
struct sk_buff *skb;
int err = -ENOMEM;
int data_len = 0;
bool fragstolen;
if (size == 0)
return 0;
if (size > PAGE_SIZE) {
int npages = min_t(size_t, size >> PAGE_SHIFT, MAX_SKB_FRAGS);
data_len = npages << PAGE_SHIFT;
size = data_len + (size & ~PAGE_MASK);
}
skb = alloc_skb_with_frags(size - data_len, data_len,
PAGE_ALLOC_COSTLY_ORDER,
&err, sk->sk_allocation);
if (!skb)
goto err;
skb_put(skb, size - data_len);
skb->data_len = data_len;
skb->len = size;
if (tcp_try_rmem_schedule(sk, skb, skb->truesize))
goto err_free;
err = skb_copy_datagram_from_iter(skb, 0, &msg->msg_iter, size);
if (err)
goto err_free;
TCP_SKB_CB(skb)->seq = tcp_sk(sk)->rcv_nxt;
TCP_SKB_CB(skb)->end_seq = TCP_SKB_CB(skb)->seq + size;
TCP_SKB_CB(skb)->ack_seq = tcp_sk(sk)->snd_una - 1;
if (tcp_queue_rcv(sk, skb, 0, &fragstolen)) {
WARN_ON_ONCE(fragstolen);
__kfree_skb(skb);
}
return size;
err_free:
kfree_skb(skb);
err:
return err;
}
static void tcp_data_queue(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
bool fragstolen = false;
int eaten = -1;
if (TCP_SKB_CB(skb)->seq == TCP_SKB_CB(skb)->end_seq) {
__kfree_skb(skb);
return;
}
skb_dst_drop(skb);
__skb_pull(skb, tcp_hdr(skb)->doff * 4);
tcp_ecn_accept_cwr(tp, skb);
tp->rx_opt.dsack = 0;
if (TCP_SKB_CB(skb)->seq == tp->rcv_nxt) {
if (tcp_receive_window(tp) == 0)
goto out_of_window;
if (tp->ucopy.task == current &&
tp->copied_seq == tp->rcv_nxt && tp->ucopy.len &&
sock_owned_by_user(sk) && !tp->urg_data) {
int chunk = min_t(unsigned int, skb->len,
tp->ucopy.len);
__set_current_state(TASK_RUNNING);
if (!skb_copy_datagram_msg(skb, 0, tp->ucopy.msg, chunk)) {
tp->ucopy.len -= chunk;
tp->copied_seq += chunk;
eaten = (chunk == skb->len);
tcp_rcv_space_adjust(sk);
}
}
if (eaten <= 0) {
queue_and_out:
if (eaten < 0) {
if (skb_queue_len(&sk->sk_receive_queue) == 0)
sk_forced_mem_schedule(sk, skb->truesize);
else if (tcp_try_rmem_schedule(sk, skb, skb->truesize))
goto drop;
}
eaten = tcp_queue_rcv(sk, skb, 0, &fragstolen);
}
tcp_rcv_nxt_update(tp, TCP_SKB_CB(skb)->end_seq);
if (skb->len)
tcp_event_data_recv(sk, skb);
if (TCP_SKB_CB(skb)->tcp_flags & TCPHDR_FIN)
tcp_fin(sk);
if (!RB_EMPTY_ROOT(&tp->out_of_order_queue)) {
tcp_ofo_queue(sk);
if (RB_EMPTY_ROOT(&tp->out_of_order_queue))
inet_csk(sk)->icsk_ack.pingpong = 0;
}
if (tp->rx_opt.num_sacks)
tcp_sack_remove(tp);
tcp_fast_path_check(sk);
if (eaten > 0)
kfree_skb_partial(skb, fragstolen);
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_data_ready(sk);
return;
}
if (!after(TCP_SKB_CB(skb)->end_seq, tp->rcv_nxt)) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_DELAYEDACKLOST);
tcp_dsack_set(sk, TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb)->end_seq);
out_of_window:
tcp_enter_quickack_mode(sk);
inet_csk_schedule_ack(sk);
drop:
tcp_drop(sk, skb);
return;
}
if (!before(TCP_SKB_CB(skb)->seq, tp->rcv_nxt + tcp_receive_window(tp)))
goto out_of_window;
tcp_enter_quickack_mode(sk);
if (before(TCP_SKB_CB(skb)->seq, tp->rcv_nxt)) {
SOCK_DEBUG(sk, "partial packet: rcv_next %X seq %X - %X\n",
tp->rcv_nxt, TCP_SKB_CB(skb)->seq,
TCP_SKB_CB(skb)->end_seq);
tcp_dsack_set(sk, TCP_SKB_CB(skb)->seq, tp->rcv_nxt);
if (!tcp_receive_window(tp))
goto out_of_window;
goto queue_and_out;
}
tcp_data_queue_ofo(sk, skb);
}
static struct sk_buff *tcp_skb_next(struct sk_buff *skb, struct sk_buff_head *list)
{
if (list)
return !skb_queue_is_last(list, skb) ? skb->next : NULL;
return rb_entry_safe(rb_next(&skb->rbnode), struct sk_buff, rbnode);
}
static struct sk_buff *tcp_collapse_one(struct sock *sk, struct sk_buff *skb,
struct sk_buff_head *list,
struct rb_root *root)
{
struct sk_buff *next = tcp_skb_next(skb, list);
if (list)
__skb_unlink(skb, list);
else
rb_erase(&skb->rbnode, root);
__kfree_skb(skb);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPRCVCOLLAPSED);
return next;
}
static void tcp_rbtree_insert(struct rb_root *root, struct sk_buff *skb)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct sk_buff *skb1;
while (*p) {
parent = *p;
skb1 = rb_entry(parent, struct sk_buff, rbnode);
if (before(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb1)->seq))
p = &parent->rb_left;
else
p = &parent->rb_right;
}
rb_link_node(&skb->rbnode, parent, p);
rb_insert_color(&skb->rbnode, root);
}
static void
tcp_collapse(struct sock *sk, struct sk_buff_head *list, struct rb_root *root,
struct sk_buff *head, struct sk_buff *tail, u32 start, u32 end)
{
struct sk_buff *skb = head, *n;
struct sk_buff_head tmp;
bool end_of_skbs;
restart:
for (end_of_skbs = true; skb != NULL && skb != tail; skb = n) {
n = tcp_skb_next(skb, list);
if (!before(start, TCP_SKB_CB(skb)->end_seq)) {
skb = tcp_collapse_one(sk, skb, list, root);
if (!skb)
break;
goto restart;
}
if (!(TCP_SKB_CB(skb)->tcp_flags & (TCPHDR_SYN | TCPHDR_FIN)) &&
(tcp_win_from_space(skb->truesize) > skb->len ||
before(TCP_SKB_CB(skb)->seq, start))) {
end_of_skbs = false;
break;
}
if (n && n != tail &&
TCP_SKB_CB(skb)->end_seq != TCP_SKB_CB(n)->seq) {
end_of_skbs = false;
break;
}
start = TCP_SKB_CB(skb)->end_seq;
}
if (end_of_skbs ||
(TCP_SKB_CB(skb)->tcp_flags & (TCPHDR_SYN | TCPHDR_FIN)))
return;
__skb_queue_head_init(&tmp);
while (before(start, end)) {
int copy = min_t(int, SKB_MAX_ORDER(0, 0), end - start);
struct sk_buff *nskb;
nskb = alloc_skb(copy, GFP_ATOMIC);
if (!nskb)
break;
memcpy(nskb->cb, skb->cb, sizeof(skb->cb));
TCP_SKB_CB(nskb)->seq = TCP_SKB_CB(nskb)->end_seq = start;
if (list)
__skb_queue_before(list, skb, nskb);
else
__skb_queue_tail(&tmp, nskb);
skb_set_owner_r(nskb, sk);
while (copy > 0) {
int offset = start - TCP_SKB_CB(skb)->seq;
int size = TCP_SKB_CB(skb)->end_seq - start;
BUG_ON(offset < 0);
if (size > 0) {
size = min(copy, size);
if (skb_copy_bits(skb, offset, skb_put(nskb, size), size))
BUG();
TCP_SKB_CB(nskb)->end_seq += size;
copy -= size;
start += size;
}
if (!before(start, TCP_SKB_CB(skb)->end_seq)) {
skb = tcp_collapse_one(sk, skb, list, root);
if (!skb ||
skb == tail ||
(TCP_SKB_CB(skb)->tcp_flags & (TCPHDR_SYN | TCPHDR_FIN)))
goto end;
}
}
}
end:
skb_queue_walk_safe(&tmp, skb, n)
tcp_rbtree_insert(root, skb);
}
static void tcp_collapse_ofo_queue(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb, *head;
struct rb_node *p;
u32 start, end;
p = rb_first(&tp->out_of_order_queue);
skb = rb_entry_safe(p, struct sk_buff, rbnode);
new_range:
if (!skb) {
p = rb_last(&tp->out_of_order_queue);
tp->ooo_last_skb = rb_entry(p, struct sk_buff, rbnode);
return;
}
start = TCP_SKB_CB(skb)->seq;
end = TCP_SKB_CB(skb)->end_seq;
for (head = skb;;) {
skb = tcp_skb_next(skb, NULL);
if (!skb ||
after(TCP_SKB_CB(skb)->seq, end) ||
before(TCP_SKB_CB(skb)->end_seq, start)) {
tcp_collapse(sk, NULL, &tp->out_of_order_queue,
head, skb, start, end);
goto new_range;
}
if (unlikely(before(TCP_SKB_CB(skb)->seq, start)))
start = TCP_SKB_CB(skb)->seq;
if (after(TCP_SKB_CB(skb)->end_seq, end))
end = TCP_SKB_CB(skb)->end_seq;
}
}
static bool tcp_prune_ofo_queue(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct rb_node *node, *prev;
if (RB_EMPTY_ROOT(&tp->out_of_order_queue))
return false;
NET_INC_STATS(sock_net(sk), LINUX_MIB_OFOPRUNED);
node = &tp->ooo_last_skb->rbnode;
do {
prev = rb_prev(node);
rb_erase(node, &tp->out_of_order_queue);
tcp_drop(sk, rb_entry(node, struct sk_buff, rbnode));
sk_mem_reclaim(sk);
if (atomic_read(&sk->sk_rmem_alloc) <= sk->sk_rcvbuf &&
!tcp_under_memory_pressure(sk))
break;
node = prev;
} while (node);
tp->ooo_last_skb = rb_entry(prev, struct sk_buff, rbnode);
if (tp->rx_opt.sack_ok)
tcp_sack_reset(&tp->rx_opt);
return true;
}
static int tcp_prune_queue(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
SOCK_DEBUG(sk, "prune_queue: c=%x\n", tp->copied_seq);
NET_INC_STATS(sock_net(sk), LINUX_MIB_PRUNECALLED);
if (atomic_read(&sk->sk_rmem_alloc) >= sk->sk_rcvbuf)
tcp_clamp_window(sk);
else if (tcp_under_memory_pressure(sk))
tp->rcv_ssthresh = min(tp->rcv_ssthresh, 4U * tp->advmss);
tcp_collapse_ofo_queue(sk);
if (!skb_queue_empty(&sk->sk_receive_queue))
tcp_collapse(sk, &sk->sk_receive_queue, NULL,
skb_peek(&sk->sk_receive_queue),
NULL,
tp->copied_seq, tp->rcv_nxt);
sk_mem_reclaim(sk);
if (atomic_read(&sk->sk_rmem_alloc) <= sk->sk_rcvbuf)
return 0;
tcp_prune_ofo_queue(sk);
if (atomic_read(&sk->sk_rmem_alloc) <= sk->sk_rcvbuf)
return 0;
NET_INC_STATS(sock_net(sk), LINUX_MIB_RCVPRUNED);
tp->pred_flags = 0;
return -1;
}
static bool tcp_should_expand_sndbuf(const struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
if (sk->sk_userlocks & SOCK_SNDBUF_LOCK)
return false;
if (tcp_under_memory_pressure(sk))
return false;
if (sk_memory_allocated(sk) >= sk_prot_mem_limits(sk, 0))
return false;
if (tcp_packets_in_flight(tp) >= tp->snd_cwnd)
return false;
return true;
}
static void tcp_new_space(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (tcp_should_expand_sndbuf(sk)) {
tcp_sndbuf_expand(sk);
tp->snd_cwnd_stamp = tcp_time_stamp;
}
sk->sk_write_space(sk);
}
static void tcp_check_space(struct sock *sk)
{
if (sock_flag(sk, SOCK_QUEUE_SHRUNK)) {
sock_reset_flag(sk, SOCK_QUEUE_SHRUNK);
smp_mb();
if (sk->sk_socket &&
test_bit(SOCK_NOSPACE, &sk->sk_socket->flags)) {
tcp_new_space(sk);
if (!test_bit(SOCK_NOSPACE, &sk->sk_socket->flags))
tcp_chrono_stop(sk, TCP_CHRONO_SNDBUF_LIMITED);
}
}
}
static inline void tcp_data_snd_check(struct sock *sk)
{
tcp_push_pending_frames(sk);
tcp_check_space(sk);
}
static void __tcp_ack_snd_check(struct sock *sk, int ofo_possible)
{
struct tcp_sock *tp = tcp_sk(sk);
if (((tp->rcv_nxt - tp->rcv_wup) > inet_csk(sk)->icsk_ack.rcv_mss &&
__tcp_select_window(sk) >= tp->rcv_wnd) ||
tcp_in_quickack_mode(sk) ||
(ofo_possible && !RB_EMPTY_ROOT(&tp->out_of_order_queue))) {
tcp_send_ack(sk);
} else {
tcp_send_delayed_ack(sk);
}
}
static inline void tcp_ack_snd_check(struct sock *sk)
{
if (!inet_csk_ack_scheduled(sk)) {
return;
}
__tcp_ack_snd_check(sk, 1);
}
static void tcp_check_urg(struct sock *sk, const struct tcphdr *th)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 ptr = ntohs(th->urg_ptr);
if (ptr && !sysctl_tcp_stdurg)
ptr--;
ptr += ntohl(th->seq);
if (after(tp->copied_seq, ptr))
return;
if (before(ptr, tp->rcv_nxt))
return;
if (tp->urg_data && !after(ptr, tp->urg_seq))
return;
sk_send_sigurg(sk);
if (tp->urg_seq == tp->copied_seq && tp->urg_data &&
!sock_flag(sk, SOCK_URGINLINE) && tp->copied_seq != tp->rcv_nxt) {
struct sk_buff *skb = skb_peek(&sk->sk_receive_queue);
tp->copied_seq++;
if (skb && !before(tp->copied_seq, TCP_SKB_CB(skb)->end_seq)) {
__skb_unlink(skb, &sk->sk_receive_queue);
__kfree_skb(skb);
}
}
tp->urg_data = TCP_URG_NOTYET;
tp->urg_seq = ptr;
tp->pred_flags = 0;
}
static void tcp_urg(struct sock *sk, struct sk_buff *skb, const struct tcphdr *th)
{
struct tcp_sock *tp = tcp_sk(sk);
if (th->urg)
tcp_check_urg(sk, th);
if (tp->urg_data == TCP_URG_NOTYET) {
u32 ptr = tp->urg_seq - ntohl(th->seq) + (th->doff * 4) -
th->syn;
if (ptr < skb->len) {
u8 tmp;
if (skb_copy_bits(skb, ptr, &tmp, 1))
BUG();
tp->urg_data = TCP_URG_VALID | tmp;
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_data_ready(sk);
}
}
}
static int tcp_copy_to_iovec(struct sock *sk, struct sk_buff *skb, int hlen)
{
struct tcp_sock *tp = tcp_sk(sk);
int chunk = skb->len - hlen;
int err;
if (skb_csum_unnecessary(skb))
err = skb_copy_datagram_msg(skb, hlen, tp->ucopy.msg, chunk);
else
err = skb_copy_and_csum_datagram_msg(skb, hlen, tp->ucopy.msg);
if (!err) {
tp->ucopy.len -= chunk;
tp->copied_seq += chunk;
tcp_rcv_space_adjust(sk);
}
return err;
}
static bool tcp_reset_check(const struct sock *sk, const struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
return unlikely(TCP_SKB_CB(skb)->seq == (tp->rcv_nxt - 1) &&
(1 << sk->sk_state) & (TCPF_CLOSE_WAIT | TCPF_LAST_ACK |
TCPF_CLOSING));
}
static bool tcp_validate_incoming(struct sock *sk, struct sk_buff *skb,
const struct tcphdr *th, int syn_inerr)
{
struct tcp_sock *tp = tcp_sk(sk);
bool rst_seq_match = false;
if (tcp_fast_parse_options(skb, th, tp) && tp->rx_opt.saw_tstamp &&
tcp_paws_discard(sk, skb)) {
if (!th->rst) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_PAWSESTABREJECTED);
if (!tcp_oow_rate_limited(sock_net(sk), skb,
LINUX_MIB_TCPACKSKIPPEDPAWS,
&tp->last_oow_ack_time))
tcp_send_dupack(sk, skb);
goto discard;
}
}
if (!tcp_sequence(tp, TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb)->end_seq)) {
if (!th->rst) {
if (th->syn)
goto syn_challenge;
if (!tcp_oow_rate_limited(sock_net(sk), skb,
LINUX_MIB_TCPACKSKIPPEDSEQ,
&tp->last_oow_ack_time))
tcp_send_dupack(sk, skb);
} else if (tcp_reset_check(sk, skb)) {
tcp_reset(sk);
}
goto discard;
}
if (th->rst) {
if (TCP_SKB_CB(skb)->seq == tp->rcv_nxt ||
tcp_reset_check(sk, skb)) {
rst_seq_match = true;
} else if (tcp_is_sack(tp) && tp->rx_opt.num_sacks > 0) {
struct tcp_sack_block *sp = &tp->selective_acks[0];
int max_sack = sp[0].end_seq;
int this_sack;
for (this_sack = 1; this_sack < tp->rx_opt.num_sacks;
++this_sack) {
max_sack = after(sp[this_sack].end_seq,
max_sack) ?
sp[this_sack].end_seq : max_sack;
}
if (TCP_SKB_CB(skb)->seq == max_sack)
rst_seq_match = true;
}
if (rst_seq_match)
tcp_reset(sk);
else
tcp_send_challenge_ack(sk, skb);
goto discard;
}
if (th->syn) {
syn_challenge:
if (syn_inerr)
TCP_INC_STATS(sock_net(sk), TCP_MIB_INERRS);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPSYNCHALLENGE);
tcp_send_challenge_ack(sk, skb);
goto discard;
}
return true;
discard:
tcp_drop(sk, skb);
return false;
}
void tcp_rcv_established(struct sock *sk, struct sk_buff *skb,
const struct tcphdr *th, unsigned int len)
{
struct tcp_sock *tp = tcp_sk(sk);
if (unlikely(!sk->sk_rx_dst))
inet_csk(sk)->icsk_af_ops->sk_rx_dst_set(sk, skb);
tp->rx_opt.saw_tstamp = 0;
if ((tcp_flag_word(th) & TCP_HP_BITS) == tp->pred_flags &&
TCP_SKB_CB(skb)->seq == tp->rcv_nxt &&
!after(TCP_SKB_CB(skb)->ack_seq, tp->snd_nxt)) {
int tcp_header_len = tp->tcp_header_len;
if (tcp_header_len == sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED) {
if (!tcp_parse_aligned_timestamp(tp, th))
goto slow_path;
if ((s32)(tp->rx_opt.rcv_tsval - tp->rx_opt.ts_recent) < 0)
goto slow_path;
}
if (len <= tcp_header_len) {
if (len == tcp_header_len) {
if (tcp_header_len ==
(sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED) &&
tp->rcv_nxt == tp->rcv_wup)
tcp_store_ts_recent(tp);
tcp_ack(sk, skb, 0);
__kfree_skb(skb);
tcp_data_snd_check(sk);
return;
} else {
TCP_INC_STATS(sock_net(sk), TCP_MIB_INERRS);
goto discard;
}
} else {
int eaten = 0;
bool fragstolen = false;
if (tp->ucopy.task == current &&
tp->copied_seq == tp->rcv_nxt &&
len - tcp_header_len <= tp->ucopy.len &&
sock_owned_by_user(sk)) {
__set_current_state(TASK_RUNNING);
if (!tcp_copy_to_iovec(sk, skb, tcp_header_len)) {
if (tcp_header_len ==
(sizeof(struct tcphdr) +
TCPOLEN_TSTAMP_ALIGNED) &&
tp->rcv_nxt == tp->rcv_wup)
tcp_store_ts_recent(tp);
tcp_rcv_rtt_measure_ts(sk, skb);
__skb_pull(skb, tcp_header_len);
tcp_rcv_nxt_update(tp, TCP_SKB_CB(skb)->end_seq);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPHPHITSTOUSER);
eaten = 1;
}
}
if (!eaten) {
if (tcp_checksum_complete(skb))
goto csum_error;
if ((int)skb->truesize > sk->sk_forward_alloc)
goto step5;
if (tcp_header_len ==
(sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED) &&
tp->rcv_nxt == tp->rcv_wup)
tcp_store_ts_recent(tp);
tcp_rcv_rtt_measure_ts(sk, skb);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPHPHITS);
eaten = tcp_queue_rcv(sk, skb, tcp_header_len,
&fragstolen);
}
tcp_event_data_recv(sk, skb);
if (TCP_SKB_CB(skb)->ack_seq != tp->snd_una) {
tcp_ack(sk, skb, FLAG_DATA);
tcp_data_snd_check(sk);
if (!inet_csk_ack_scheduled(sk))
goto no_ack;
}
__tcp_ack_snd_check(sk, 0);
no_ack:
if (eaten)
kfree_skb_partial(skb, fragstolen);
sk->sk_data_ready(sk);
return;
}
}
slow_path:
if (len < (th->doff << 2) || tcp_checksum_complete(skb))
goto csum_error;
if (!th->ack && !th->rst && !th->syn)
goto discard;
if (!tcp_validate_incoming(sk, skb, th, 1))
return;
step5:
if (tcp_ack(sk, skb, FLAG_SLOWPATH | FLAG_UPDATE_TS_RECENT) < 0)
goto discard;
tcp_rcv_rtt_measure_ts(sk, skb);
tcp_urg(sk, skb, th);
tcp_data_queue(sk, skb);
tcp_data_snd_check(sk);
tcp_ack_snd_check(sk);
return;
csum_error:
TCP_INC_STATS(sock_net(sk), TCP_MIB_CSUMERRORS);
TCP_INC_STATS(sock_net(sk), TCP_MIB_INERRS);
discard:
tcp_drop(sk, skb);
}
void tcp_finish_connect(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
tcp_set_state(sk, TCP_ESTABLISHED);
icsk->icsk_ack.lrcvtime = tcp_time_stamp;
if (skb) {
icsk->icsk_af_ops->sk_rx_dst_set(sk, skb);
security_inet_conn_established(sk, skb);
}
icsk->icsk_af_ops->rebuild_header(sk);
tcp_init_metrics(sk);
tcp_init_congestion_control(sk);
tp->lsndtime = tcp_time_stamp;
tcp_init_buffer_space(sk);
if (sock_flag(sk, SOCK_KEEPOPEN))
inet_csk_reset_keepalive_timer(sk, keepalive_time_when(tp));
if (!tp->rx_opt.snd_wscale)
__tcp_fast_path_on(tp, tp->snd_wnd);
else
tp->pred_flags = 0;
if (!sock_flag(sk, SOCK_DEAD)) {
sk->sk_state_change(sk);
sk_wake_async(sk, SOCK_WAKE_IO, POLL_OUT);
}
}
static bool tcp_rcv_fastopen_synack(struct sock *sk, struct sk_buff *synack,
struct tcp_fastopen_cookie *cookie)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *data = tp->syn_data ? tcp_write_queue_head(sk) : NULL;
u16 mss = tp->rx_opt.mss_clamp, try_exp = 0;
bool syn_drop = false;
if (mss == tp->rx_opt.user_mss) {
struct tcp_options_received opt;
tcp_clear_options(&opt);
opt.user_mss = opt.mss_clamp = 0;
tcp_parse_options(synack, &opt, 0, NULL);
mss = opt.mss_clamp;
}
if (!tp->syn_fastopen) {
cookie->len = -1;
} else if (tp->total_retrans) {
syn_drop = (cookie->len < 0 && data);
} else if (cookie->len < 0 && !tp->syn_data) {
try_exp = tp->syn_fastopen_exp ? 2 : 1;
}
tcp_fastopen_cache_set(sk, mss, cookie, syn_drop, try_exp);
if (data) {
tcp_for_write_queue_from(data, sk) {
if (data == tcp_send_head(sk) ||
__tcp_retransmit_skb(sk, data, 1))
break;
}
tcp_rearm_rto(sk);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPFASTOPENACTIVEFAIL);
return true;
}
tp->syn_data_acked = tp->syn_data;
if (tp->syn_data_acked)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPFASTOPENACTIVE);
tcp_fastopen_add_skb(sk, synack);
return false;
}
static int tcp_rcv_synsent_state_process(struct sock *sk, struct sk_buff *skb,
const struct tcphdr *th)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_fastopen_cookie foc = { .len = -1 };
int saved_clamp = tp->rx_opt.mss_clamp;
tcp_parse_options(skb, &tp->rx_opt, 0, &foc);
if (tp->rx_opt.saw_tstamp && tp->rx_opt.rcv_tsecr)
tp->rx_opt.rcv_tsecr -= tp->tsoffset;
if (th->ack) {
if (!after(TCP_SKB_CB(skb)->ack_seq, tp->snd_una) ||
after(TCP_SKB_CB(skb)->ack_seq, tp->snd_nxt))
goto reset_and_undo;
if (tp->rx_opt.saw_tstamp && tp->rx_opt.rcv_tsecr &&
!between(tp->rx_opt.rcv_tsecr, tp->retrans_stamp,
tcp_time_stamp)) {
NET_INC_STATS(sock_net(sk),
LINUX_MIB_PAWSACTIVEREJECTED);
goto reset_and_undo;
}
if (th->rst) {
tcp_reset(sk);
goto discard;
}
if (!th->syn)
goto discard_and_undo;
tcp_ecn_rcv_synack(tp, th);
tcp_init_wl(tp, TCP_SKB_CB(skb)->seq);
tcp_ack(sk, skb, FLAG_SLOWPATH);
tp->rcv_nxt = TCP_SKB_CB(skb)->seq + 1;
tp->rcv_wup = TCP_SKB_CB(skb)->seq + 1;
tp->snd_wnd = ntohs(th->window);
if (!tp->rx_opt.wscale_ok) {
tp->rx_opt.snd_wscale = tp->rx_opt.rcv_wscale = 0;
tp->window_clamp = min(tp->window_clamp, 65535U);
}
if (tp->rx_opt.saw_tstamp) {
tp->rx_opt.tstamp_ok = 1;
tp->tcp_header_len =
sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED;
tp->advmss -= TCPOLEN_TSTAMP_ALIGNED;
tcp_store_ts_recent(tp);
} else {
tp->tcp_header_len = sizeof(struct tcphdr);
}
if (tcp_is_sack(tp) && sysctl_tcp_fack)
tcp_enable_fack(tp);
tcp_mtup_init(sk);
tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
tcp_initialize_rcv_mss(sk);
tp->copied_seq = tp->rcv_nxt;
smp_mb();
tcp_finish_connect(sk, skb);
if ((tp->syn_fastopen || tp->syn_data) &&
tcp_rcv_fastopen_synack(sk, skb, &foc))
return -1;
if (sk->sk_write_pending ||
icsk->icsk_accept_queue.rskq_defer_accept ||
icsk->icsk_ack.pingpong) {
inet_csk_schedule_ack(sk);
tcp_enter_quickack_mode(sk);
inet_csk_reset_xmit_timer(sk, ICSK_TIME_DACK,
TCP_DELACK_MAX, TCP_RTO_MAX);
discard:
tcp_drop(sk, skb);
return 0;
} else {
tcp_send_ack(sk);
}
return -1;
}
if (th->rst) {
goto discard_and_undo;
}
if (tp->rx_opt.ts_recent_stamp && tp->rx_opt.saw_tstamp &&
tcp_paws_reject(&tp->rx_opt, 0))
goto discard_and_undo;
if (th->syn) {
tcp_set_state(sk, TCP_SYN_RECV);
if (tp->rx_opt.saw_tstamp) {
tp->rx_opt.tstamp_ok = 1;
tcp_store_ts_recent(tp);
tp->tcp_header_len =
sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED;
} else {
tp->tcp_header_len = sizeof(struct tcphdr);
}
tp->rcv_nxt = TCP_SKB_CB(skb)->seq + 1;
tp->copied_seq = tp->rcv_nxt;
tp->rcv_wup = TCP_SKB_CB(skb)->seq + 1;
tp->snd_wnd = ntohs(th->window);
tp->snd_wl1 = TCP_SKB_CB(skb)->seq;
tp->max_window = tp->snd_wnd;
tcp_ecn_rcv_syn(tp, th);
tcp_mtup_init(sk);
tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
tcp_initialize_rcv_mss(sk);
tcp_send_synack(sk);
#if 0
return -1;
#else
goto discard;
#endif
}
discard_and_undo:
tcp_clear_options(&tp->rx_opt);
tp->rx_opt.mss_clamp = saved_clamp;
goto discard;
reset_and_undo:
tcp_clear_options(&tp->rx_opt);
tp->rx_opt.mss_clamp = saved_clamp;
return 1;
}
int tcp_rcv_state_process(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
const struct tcphdr *th = tcp_hdr(skb);
struct request_sock *req;
int queued = 0;
bool acceptable;
switch (sk->sk_state) {
case TCP_CLOSE:
goto discard;
case TCP_LISTEN:
if (th->ack)
return 1;
if (th->rst)
goto discard;
if (th->syn) {
if (th->fin)
goto discard;
local_bh_disable();
acceptable = icsk->icsk_af_ops->conn_request(sk, skb) >= 0;
local_bh_enable();
if (!acceptable)
return 1;
consume_skb(skb);
return 0;
}
goto discard;
case TCP_SYN_SENT:
tp->rx_opt.saw_tstamp = 0;
queued = tcp_rcv_synsent_state_process(sk, skb, th);
if (queued >= 0)
return queued;
tcp_urg(sk, skb, th);
__kfree_skb(skb);
tcp_data_snd_check(sk);
return 0;
}
tp->rx_opt.saw_tstamp = 0;
req = tp->fastopen_rsk;
if (req) {
WARN_ON_ONCE(sk->sk_state != TCP_SYN_RECV &&
sk->sk_state != TCP_FIN_WAIT1);
if (!tcp_check_req(sk, skb, req, true))
goto discard;
}
if (!th->ack && !th->rst && !th->syn)
goto discard;
if (!tcp_validate_incoming(sk, skb, th, 0))
return 0;
acceptable = tcp_ack(sk, skb, FLAG_SLOWPATH |
FLAG_UPDATE_TS_RECENT) > 0;
switch (sk->sk_state) {
case TCP_SYN_RECV:
if (!acceptable)
return 1;
if (!tp->srtt_us)
tcp_synack_rtt_meas(sk, req);
if (req) {
inet_csk(sk)->icsk_retransmits = 0;
reqsk_fastopen_remove(sk, req, false);
} else {
icsk->icsk_af_ops->rebuild_header(sk);
tcp_init_congestion_control(sk);
tcp_mtup_init(sk);
tp->copied_seq = tp->rcv_nxt;
tcp_init_buffer_space(sk);
}
smp_mb();
tcp_set_state(sk, TCP_ESTABLISHED);
sk->sk_state_change(sk);
if (sk->sk_socket)
sk_wake_async(sk, SOCK_WAKE_IO, POLL_OUT);
tp->snd_una = TCP_SKB_CB(skb)->ack_seq;
tp->snd_wnd = ntohs(th->window) << tp->rx_opt.snd_wscale;
tcp_init_wl(tp, TCP_SKB_CB(skb)->seq);
if (tp->rx_opt.tstamp_ok)
tp->advmss -= TCPOLEN_TSTAMP_ALIGNED;
if (req) {
tcp_rearm_rto(sk);
} else
tcp_init_metrics(sk);
if (!inet_csk(sk)->icsk_ca_ops->cong_control)
tcp_update_pacing_rate(sk);
tp->lsndtime = tcp_time_stamp;
tcp_initialize_rcv_mss(sk);
tcp_fast_path_on(tp);
break;
case TCP_FIN_WAIT1: {
int tmo;
if (req) {
if (!acceptable)
return 1;
reqsk_fastopen_remove(sk, req, false);
tcp_rearm_rto(sk);
}
if (tp->snd_una != tp->write_seq)
break;
tcp_set_state(sk, TCP_FIN_WAIT2);
sk->sk_shutdown |= SEND_SHUTDOWN;
sk_dst_confirm(sk);
if (!sock_flag(sk, SOCK_DEAD)) {
sk->sk_state_change(sk);
break;
}
if (tp->linger2 < 0 ||
(TCP_SKB_CB(skb)->end_seq != TCP_SKB_CB(skb)->seq &&
after(TCP_SKB_CB(skb)->end_seq - th->fin, tp->rcv_nxt))) {
tcp_done(sk);
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTONDATA);
return 1;
}
tmo = tcp_fin_time(sk);
if (tmo > TCP_TIMEWAIT_LEN) {
inet_csk_reset_keepalive_timer(sk, tmo - TCP_TIMEWAIT_LEN);
} else if (th->fin || sock_owned_by_user(sk)) {
inet_csk_reset_keepalive_timer(sk, tmo);
} else {
tcp_time_wait(sk, TCP_FIN_WAIT2, tmo);
goto discard;
}
break;
}
case TCP_CLOSING:
if (tp->snd_una == tp->write_seq) {
tcp_time_wait(sk, TCP_TIME_WAIT, 0);
goto discard;
}
break;
case TCP_LAST_ACK:
if (tp->snd_una == tp->write_seq) {
tcp_update_metrics(sk);
tcp_done(sk);
goto discard;
}
break;
}
tcp_urg(sk, skb, th);
switch (sk->sk_state) {
case TCP_CLOSE_WAIT:
case TCP_CLOSING:
case TCP_LAST_ACK:
if (!before(TCP_SKB_CB(skb)->seq, tp->rcv_nxt))
break;
case TCP_FIN_WAIT1:
case TCP_FIN_WAIT2:
if (sk->sk_shutdown & RCV_SHUTDOWN) {
if (TCP_SKB_CB(skb)->end_seq != TCP_SKB_CB(skb)->seq &&
after(TCP_SKB_CB(skb)->end_seq - th->fin, tp->rcv_nxt)) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTONDATA);
tcp_reset(sk);
return 1;
}
}
case TCP_ESTABLISHED:
tcp_data_queue(sk, skb);
queued = 1;
break;
}
if (sk->sk_state != TCP_CLOSE) {
tcp_data_snd_check(sk);
tcp_ack_snd_check(sk);
}
if (!queued) {
discard:
tcp_drop(sk, skb);
}
return 0;
}
static inline void pr_drop_req(struct request_sock *req, __u16 port, int family)
{
struct inet_request_sock *ireq = inet_rsk(req);
if (family == AF_INET)
net_dbg_ratelimited("drop open request from %pI4/%u\n",
&ireq->ir_rmt_addr, port);
#if IS_ENABLED(CONFIG_IPV6)
else if (family == AF_INET6)
net_dbg_ratelimited("drop open request from %pI6/%u\n",
&ireq->ir_v6_rmt_addr, port);
#endif
}
static void tcp_ecn_create_request(struct request_sock *req,
const struct sk_buff *skb,
const struct sock *listen_sk,
const struct dst_entry *dst)
{
const struct tcphdr *th = tcp_hdr(skb);
const struct net *net = sock_net(listen_sk);
bool th_ecn = th->ece && th->cwr;
bool ect, ecn_ok;
u32 ecn_ok_dst;
if (!th_ecn)
return;
ect = !INET_ECN_is_not_ect(TCP_SKB_CB(skb)->ip_dsfield);
ecn_ok_dst = dst_feature(dst, DST_FEATURE_ECN_MASK);
ecn_ok = net->ipv4.sysctl_tcp_ecn || ecn_ok_dst;
if ((!ect && ecn_ok) || tcp_ca_needs_ecn(listen_sk) ||
(ecn_ok_dst & DST_FEATURE_ECN_CA))
inet_rsk(req)->ecn_ok = 1;
}
static void tcp_openreq_init(struct request_sock *req,
const struct tcp_options_received *rx_opt,
struct sk_buff *skb, const struct sock *sk)
{
struct inet_request_sock *ireq = inet_rsk(req);
req->rsk_rcv_wnd = 0;
req->cookie_ts = 0;
tcp_rsk(req)->rcv_isn = TCP_SKB_CB(skb)->seq;
tcp_rsk(req)->rcv_nxt = TCP_SKB_CB(skb)->seq + 1;
skb_mstamp_get(&tcp_rsk(req)->snt_synack);
tcp_rsk(req)->last_oow_ack_time = 0;
req->mss = rx_opt->mss_clamp;
req->ts_recent = rx_opt->saw_tstamp ? rx_opt->rcv_tsval : 0;
ireq->tstamp_ok = rx_opt->tstamp_ok;
ireq->sack_ok = rx_opt->sack_ok;
ireq->snd_wscale = rx_opt->snd_wscale;
ireq->wscale_ok = rx_opt->wscale_ok;
ireq->acked = 0;
ireq->ecn_ok = 0;
ireq->ir_rmt_port = tcp_hdr(skb)->source;
ireq->ir_num = ntohs(tcp_hdr(skb)->dest);
ireq->ir_mark = inet_request_mark(sk, skb);
}
struct request_sock *inet_reqsk_alloc(const struct request_sock_ops *ops,
struct sock *sk_listener,
bool attach_listener)
{
struct request_sock *req = reqsk_alloc(ops, sk_listener,
attach_listener);
if (req) {
struct inet_request_sock *ireq = inet_rsk(req);
kmemcheck_annotate_bitfield(ireq, flags);
ireq->opt = NULL;
#if IS_ENABLED(CONFIG_IPV6)
ireq->pktopts = NULL;
#endif
atomic64_set(&ireq->ir_cookie, 0);
ireq->ireq_state = TCP_NEW_SYN_RECV;
write_pnet(&ireq->ireq_net, sock_net(sk_listener));
ireq->ireq_family = sk_listener->sk_family;
}
return req;
}
static bool tcp_syn_flood_action(const struct sock *sk,
const struct sk_buff *skb,
const char *proto)
{
struct request_sock_queue *queue = &inet_csk(sk)->icsk_accept_queue;
const char *msg = "Dropping request";
bool want_cookie = false;
struct net *net = sock_net(sk);
#ifdef CONFIG_SYN_COOKIES
if (net->ipv4.sysctl_tcp_syncookies) {
msg = "Sending cookies";
want_cookie = true;
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPREQQFULLDOCOOKIES);
} else
#endif
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPREQQFULLDROP);
if (!queue->synflood_warned &&
net->ipv4.sysctl_tcp_syncookies != 2 &&
xchg(&queue->synflood_warned, 1) == 0)
pr_info("%s: Possible SYN flooding on port %d. %s. Check SNMP counters.\n",
proto, ntohs(tcp_hdr(skb)->dest), msg);
return want_cookie;
}
static void tcp_reqsk_record_syn(const struct sock *sk,
struct request_sock *req,
const struct sk_buff *skb)
{
if (tcp_sk(sk)->save_syn) {
u32 len = skb_network_header_len(skb) + tcp_hdrlen(skb);
u32 *copy;
copy = kmalloc(len + sizeof(u32), GFP_ATOMIC);
if (copy) {
copy[0] = len;
memcpy(&copy[1], skb_network_header(skb), len);
req->saved_syn = copy;
}
}
}
int tcp_conn_request(struct request_sock_ops *rsk_ops,
const struct tcp_request_sock_ops *af_ops,
struct sock *sk, struct sk_buff *skb)
{
struct tcp_fastopen_cookie foc = { .len = -1 };
__u32 isn = TCP_SKB_CB(skb)->tcp_tw_isn;
struct tcp_options_received tmp_opt;
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
struct sock *fastopen_sk = NULL;
struct dst_entry *dst = NULL;
struct request_sock *req;
bool want_cookie = false;
struct flowi fl;
if ((net->ipv4.sysctl_tcp_syncookies == 2 ||
inet_csk_reqsk_queue_is_full(sk)) && !isn) {
want_cookie = tcp_syn_flood_action(sk, skb, rsk_ops->slab_name);
if (!want_cookie)
goto drop;
}
if (sk_acceptq_is_full(sk)) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_LISTENOVERFLOWS);
goto drop;
}
req = inet_reqsk_alloc(rsk_ops, sk, !want_cookie);
if (!req)
goto drop;
tcp_rsk(req)->af_specific = af_ops;
tcp_rsk(req)->ts_off = 0;
tcp_clear_options(&tmp_opt);
tmp_opt.mss_clamp = af_ops->mss_clamp;
tmp_opt.user_mss = tp->rx_opt.user_mss;
tcp_parse_options(skb, &tmp_opt, 0, want_cookie ? NULL : &foc);
if (want_cookie && !tmp_opt.saw_tstamp)
tcp_clear_options(&tmp_opt);
tmp_opt.tstamp_ok = tmp_opt.saw_tstamp;
tcp_openreq_init(req, &tmp_opt, skb, sk);
inet_rsk(req)->no_srccheck = inet_sk(sk)->transparent;
inet_rsk(req)->ir_iif = inet_request_bound_dev_if(sk, skb);
af_ops->init_req(req, sk, skb);
if (security_inet_conn_request(sk, skb, req))
goto drop_and_free;
if (isn && tmp_opt.tstamp_ok)
af_ops->init_seq(skb, &tcp_rsk(req)->ts_off);
if (!want_cookie && !isn) {
if (net->ipv4.tcp_death_row.sysctl_tw_recycle) {
bool strict;
dst = af_ops->route_req(sk, &fl, req, &strict);
if (dst && strict &&
!tcp_peer_is_proven(req, dst, true,
tmp_opt.saw_tstamp)) {
NET_INC_STATS(sock_net(sk), LINUX_MIB_PAWSPASSIVEREJECTED);
goto drop_and_release;
}
}
else if (!net->ipv4.sysctl_tcp_syncookies &&
(net->ipv4.sysctl_max_syn_backlog - inet_csk_reqsk_queue_len(sk) <
(net->ipv4.sysctl_max_syn_backlog >> 2)) &&
!tcp_peer_is_proven(req, dst, false,
tmp_opt.saw_tstamp)) {
pr_drop_req(req, ntohs(tcp_hdr(skb)->source),
rsk_ops->family);
goto drop_and_release;
}
isn = af_ops->init_seq(skb, &tcp_rsk(req)->ts_off);
}
if (!dst) {
dst = af_ops->route_req(sk, &fl, req, NULL);
if (!dst)
goto drop_and_free;
}
tcp_ecn_create_request(req, skb, sk, dst);
if (want_cookie) {
isn = cookie_init_sequence(af_ops, sk, skb, &req->mss);
tcp_rsk(req)->ts_off = 0;
req->cookie_ts = tmp_opt.tstamp_ok;
if (!tmp_opt.tstamp_ok)
inet_rsk(req)->ecn_ok = 0;
}
tcp_rsk(req)->snt_isn = isn;
tcp_rsk(req)->txhash = net_tx_rndhash();
tcp_openreq_init_rwin(req, sk, dst);
if (!want_cookie) {
tcp_reqsk_record_syn(sk, req, skb);
fastopen_sk = tcp_try_fastopen(sk, skb, req, &foc, dst);
}
if (fastopen_sk) {
af_ops->send_synack(fastopen_sk, dst, &fl, req,
&foc, TCP_SYNACK_FASTOPEN);
inet_csk_reqsk_queue_add(sk, req, fastopen_sk);
sk->sk_data_ready(sk);
bh_unlock_sock(fastopen_sk);
sock_put(fastopen_sk);
} else {
tcp_rsk(req)->tfo_listener = false;
if (!want_cookie)
inet_csk_reqsk_queue_hash_add(sk, req, TCP_TIMEOUT_INIT);
af_ops->send_synack(sk, dst, &fl, req, &foc,
!want_cookie ? TCP_SYNACK_NORMAL :
TCP_SYNACK_COOKIE);
if (want_cookie) {
reqsk_free(req);
return 0;
}
}
reqsk_put(req);
return 0;
drop_and_release:
dst_release(dst);
drop_and_free:
reqsk_free(req);
drop:
tcp_listendrop(sk);
return 0;
}
