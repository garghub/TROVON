static void vegas_enable(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct vegas *vegas = inet_csk_ca(sk);
vegas->doing_vegas_now = 1;
vegas->beg_snd_nxt = tp->snd_nxt;
vegas->cntRTT = 0;
vegas->minRTT = 0x7fffffff;
}
static inline void vegas_disable(struct sock *sk)
{
struct vegas *vegas = inet_csk_ca(sk);
vegas->doing_vegas_now = 0;
}
void tcp_vegas_init(struct sock *sk)
{
struct vegas *vegas = inet_csk_ca(sk);
vegas->baseRTT = 0x7fffffff;
vegas_enable(sk);
}
void tcp_vegas_pkts_acked(struct sock *sk, const struct ack_sample *sample)
{
struct vegas *vegas = inet_csk_ca(sk);
u32 vrtt;
if (sample->rtt_us < 0)
return;
vrtt = sample->rtt_us + 1;
if (vrtt < vegas->baseRTT)
vegas->baseRTT = vrtt;
vegas->minRTT = min(vegas->minRTT, vrtt);
vegas->cntRTT++;
}
void tcp_vegas_state(struct sock *sk, u8 ca_state)
{
if (ca_state == TCP_CA_Open)
vegas_enable(sk);
else
vegas_disable(sk);
}
void tcp_vegas_cwnd_event(struct sock *sk, enum tcp_ca_event event)
{
if (event == CA_EVENT_CWND_RESTART ||
event == CA_EVENT_TX_START)
tcp_vegas_init(sk);
}
static inline u32 tcp_vegas_ssthresh(struct tcp_sock *tp)
{
return min(tp->snd_ssthresh, tp->snd_cwnd-1);
}
static void tcp_vegas_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct tcp_sock *tp = tcp_sk(sk);
struct vegas *vegas = inet_csk_ca(sk);
if (!vegas->doing_vegas_now) {
tcp_reno_cong_avoid(sk, ack, acked);
return;
}
if (after(ack, vegas->beg_snd_nxt)) {
vegas->beg_snd_nxt = tp->snd_nxt;
if (vegas->cntRTT <= 2) {
tcp_reno_cong_avoid(sk, ack, acked);
} else {
u32 rtt, diff;
u64 target_cwnd;
rtt = vegas->minRTT;
target_cwnd = (u64)tp->snd_cwnd * vegas->baseRTT;
do_div(target_cwnd, rtt);
diff = tp->snd_cwnd * (rtt-vegas->baseRTT) / vegas->baseRTT;
if (diff > gamma && tcp_in_slow_start(tp)) {
tp->snd_cwnd = min(tp->snd_cwnd, (u32)target_cwnd+1);
tp->snd_ssthresh = tcp_vegas_ssthresh(tp);
} else if (tcp_in_slow_start(tp)) {
tcp_slow_start(tp, acked);
} else {
if (diff > beta) {
tp->snd_cwnd--;
tp->snd_ssthresh
= tcp_vegas_ssthresh(tp);
} else if (diff < alpha) {
tp->snd_cwnd++;
} else {
}
}
if (tp->snd_cwnd < 2)
tp->snd_cwnd = 2;
else if (tp->snd_cwnd > tp->snd_cwnd_clamp)
tp->snd_cwnd = tp->snd_cwnd_clamp;
tp->snd_ssthresh = tcp_current_ssthresh(sk);
}
vegas->cntRTT = 0;
vegas->minRTT = 0x7fffffff;
}
else if (tcp_in_slow_start(tp))
tcp_slow_start(tp, acked);
}
size_t tcp_vegas_get_info(struct sock *sk, u32 ext, int *attr,
union tcp_cc_info *info)
{
const struct vegas *ca = inet_csk_ca(sk);
if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
info->vegas.tcpv_enabled = ca->doing_vegas_now,
info->vegas.tcpv_rttcnt = ca->cntRTT,
info->vegas.tcpv_rtt = ca->baseRTT,
info->vegas.tcpv_minrtt = ca->minRTT,
*attr = INET_DIAG_VEGASINFO;
return sizeof(struct tcpvegas_info);
}
return 0;
}
static int __init tcp_vegas_register(void)
{
BUILD_BUG_ON(sizeof(struct vegas) > ICSK_CA_PRIV_SIZE);
tcp_register_congestion_control(&tcp_vegas);
return 0;
}
static void __exit tcp_vegas_unregister(void)
{
tcp_unregister_congestion_control(&tcp_vegas);
}
