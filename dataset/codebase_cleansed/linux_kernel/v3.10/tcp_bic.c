static inline void bictcp_reset(struct bictcp *ca)
{
ca->cnt = 0;
ca->last_max_cwnd = 0;
ca->last_cwnd = 0;
ca->last_time = 0;
ca->epoch_start = 0;
ca->delayed_ack = 2 << ACK_RATIO_SHIFT;
}
static void bictcp_init(struct sock *sk)
{
struct bictcp *ca = inet_csk_ca(sk);
bictcp_reset(ca);
ca->loss_cwnd = 0;
if (initial_ssthresh)
tcp_sk(sk)->snd_ssthresh = initial_ssthresh;
}
static inline void bictcp_update(struct bictcp *ca, u32 cwnd)
{
if (ca->last_cwnd == cwnd &&
(s32)(tcp_time_stamp - ca->last_time) <= HZ / 32)
return;
ca->last_cwnd = cwnd;
ca->last_time = tcp_time_stamp;
if (ca->epoch_start == 0)
ca->epoch_start = tcp_time_stamp;
if (cwnd <= low_window) {
ca->cnt = cwnd;
return;
}
if (cwnd < ca->last_max_cwnd) {
__u32 dist = (ca->last_max_cwnd - cwnd)
/ BICTCP_B;
if (dist > max_increment)
ca->cnt = cwnd / max_increment;
else if (dist <= 1U)
ca->cnt = (cwnd * smooth_part) / BICTCP_B;
else
ca->cnt = cwnd / dist;
} else {
if (cwnd < ca->last_max_cwnd + BICTCP_B)
ca->cnt = (cwnd * smooth_part) / BICTCP_B;
else if (cwnd < ca->last_max_cwnd + max_increment*(BICTCP_B-1))
ca->cnt = (cwnd * (BICTCP_B-1))
/ (cwnd - ca->last_max_cwnd);
else
ca->cnt = cwnd / max_increment;
}
if (ca->last_max_cwnd == 0) {
if (ca->cnt > 20)
ca->cnt = 20;
}
ca->cnt = (ca->cnt << ACK_RATIO_SHIFT) / ca->delayed_ack;
if (ca->cnt == 0)
ca->cnt = 1;
}
static void bictcp_cong_avoid(struct sock *sk, u32 ack, u32 in_flight)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
if (!tcp_is_cwnd_limited(sk, in_flight))
return;
if (tp->snd_cwnd <= tp->snd_ssthresh)
tcp_slow_start(tp);
else {
bictcp_update(ca, tp->snd_cwnd);
tcp_cong_avoid_ai(tp, ca->cnt);
}
}
static u32 bictcp_recalc_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
ca->epoch_start = 0;
if (tp->snd_cwnd < ca->last_max_cwnd && fast_convergence)
ca->last_max_cwnd = (tp->snd_cwnd * (BICTCP_BETA_SCALE + beta))
/ (2 * BICTCP_BETA_SCALE);
else
ca->last_max_cwnd = tp->snd_cwnd;
ca->loss_cwnd = tp->snd_cwnd;
if (tp->snd_cwnd <= low_window)
return max(tp->snd_cwnd >> 1U, 2U);
else
return max((tp->snd_cwnd * beta) / BICTCP_BETA_SCALE, 2U);
}
static u32 bictcp_undo_cwnd(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct bictcp *ca = inet_csk_ca(sk);
return max(tp->snd_cwnd, ca->loss_cwnd);
}
static void bictcp_state(struct sock *sk, u8 new_state)
{
if (new_state == TCP_CA_Loss)
bictcp_reset(inet_csk_ca(sk));
}
static void bictcp_acked(struct sock *sk, u32 cnt, s32 rtt)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_ca_state == TCP_CA_Open) {
struct bictcp *ca = inet_csk_ca(sk);
cnt -= ca->delayed_ack >> ACK_RATIO_SHIFT;
ca->delayed_ack += cnt;
}
}
static int __init bictcp_register(void)
{
BUILD_BUG_ON(sizeof(struct bictcp) > ICSK_CA_PRIV_SIZE);
return tcp_register_congestion_control(&bictcp);
}
static void __exit bictcp_unregister(void)
{
tcp_unregister_congestion_control(&bictcp);
}
