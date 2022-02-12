static void hstcp_init(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct hstcp *ca = inet_csk_ca(sk);
ca->ai = 0;
tp->snd_cwnd_clamp = min_t(u32, tp->snd_cwnd_clamp, 0xffffffff/128);
}
static void hstcp_cong_avoid(struct sock *sk, u32 adk, u32 in_flight)
{
struct tcp_sock *tp = tcp_sk(sk);
struct hstcp *ca = inet_csk_ca(sk);
if (!tcp_is_cwnd_limited(sk, in_flight))
return;
if (tp->snd_cwnd <= tp->snd_ssthresh)
tcp_slow_start(tp);
else {
if (tp->snd_cwnd > hstcp_aimd_vals[ca->ai].cwnd) {
while (tp->snd_cwnd > hstcp_aimd_vals[ca->ai].cwnd &&
ca->ai < HSTCP_AIMD_MAX - 1)
ca->ai++;
} else if (ca->ai && tp->snd_cwnd <= hstcp_aimd_vals[ca->ai-1].cwnd) {
while (ca->ai && tp->snd_cwnd <= hstcp_aimd_vals[ca->ai-1].cwnd)
ca->ai--;
}
if (tp->snd_cwnd < tp->snd_cwnd_clamp) {
tp->snd_cwnd_cnt += ca->ai + 1;
if (tp->snd_cwnd_cnt >= tp->snd_cwnd) {
tp->snd_cwnd_cnt -= tp->snd_cwnd;
tp->snd_cwnd++;
}
}
}
}
static u32 hstcp_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct hstcp *ca = inet_csk_ca(sk);
return max(tp->snd_cwnd - ((tp->snd_cwnd * hstcp_aimd_vals[ca->ai].md) >> 8), 2U);
}
static int __init hstcp_register(void)
{
BUILD_BUG_ON(sizeof(struct hstcp) > ICSK_CA_PRIV_SIZE);
return tcp_register_congestion_control(&tcp_highspeed);
}
static void __exit hstcp_unregister(void)
{
tcp_unregister_congestion_control(&tcp_highspeed);
}
