static inline void veno_enable(struct sock *sk)
{
struct veno *veno = inet_csk_ca(sk);
veno->doing_veno_now = 1;
veno->minrtt = 0x7fffffff;
}
static inline void veno_disable(struct sock *sk)
{
struct veno *veno = inet_csk_ca(sk);
veno->doing_veno_now = 0;
}
static void tcp_veno_init(struct sock *sk)
{
struct veno *veno = inet_csk_ca(sk);
veno->basertt = 0x7fffffff;
veno->inc = 1;
veno_enable(sk);
}
static void tcp_veno_pkts_acked(struct sock *sk, u32 cnt, s32 rtt_us)
{
struct veno *veno = inet_csk_ca(sk);
u32 vrtt;
if (rtt_us < 0)
return;
vrtt = rtt_us + 1;
if (vrtt < veno->basertt)
veno->basertt = vrtt;
veno->minrtt = min(veno->minrtt, vrtt);
veno->cntrtt++;
}
static void tcp_veno_state(struct sock *sk, u8 ca_state)
{
if (ca_state == TCP_CA_Open)
veno_enable(sk);
else
veno_disable(sk);
}
static void tcp_veno_cwnd_event(struct sock *sk, enum tcp_ca_event event)
{
if (event == CA_EVENT_CWND_RESTART || event == CA_EVENT_TX_START)
tcp_veno_init(sk);
}
static void tcp_veno_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct tcp_sock *tp = tcp_sk(sk);
struct veno *veno = inet_csk_ca(sk);
if (!veno->doing_veno_now) {
tcp_reno_cong_avoid(sk, ack, acked);
return;
}
if (!tcp_is_cwnd_limited(sk))
return;
if (veno->cntrtt <= 2) {
tcp_reno_cong_avoid(sk, ack, acked);
} else {
u64 target_cwnd;
u32 rtt;
rtt = veno->minrtt;
target_cwnd = (tp->snd_cwnd * veno->basertt);
target_cwnd <<= V_PARAM_SHIFT;
do_div(target_cwnd, rtt);
veno->diff = (tp->snd_cwnd << V_PARAM_SHIFT) - target_cwnd;
if (tp->snd_cwnd <= tp->snd_ssthresh) {
tcp_slow_start(tp, acked);
} else {
if (veno->diff < beta) {
tcp_cong_avoid_ai(tp, tp->snd_cwnd);
} else {
if (tp->snd_cwnd_cnt >= tp->snd_cwnd) {
if (veno->inc &&
tp->snd_cwnd < tp->snd_cwnd_clamp) {
tp->snd_cwnd++;
veno->inc = 0;
} else
veno->inc = 1;
tp->snd_cwnd_cnt = 0;
} else
tp->snd_cwnd_cnt++;
}
}
if (tp->snd_cwnd < 2)
tp->snd_cwnd = 2;
else if (tp->snd_cwnd > tp->snd_cwnd_clamp)
tp->snd_cwnd = tp->snd_cwnd_clamp;
}
veno->minrtt = 0x7fffffff;
}
static u32 tcp_veno_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct veno *veno = inet_csk_ca(sk);
if (veno->diff < beta)
return max(tp->snd_cwnd * 4 / 5, 2U);
else
return max(tp->snd_cwnd >> 1U, 2U);
}
static int __init tcp_veno_register(void)
{
BUILD_BUG_ON(sizeof(struct veno) > ICSK_CA_PRIV_SIZE);
tcp_register_congestion_control(&tcp_veno);
return 0;
}
static void __exit tcp_veno_unregister(void)
{
tcp_unregister_congestion_control(&tcp_veno);
}
