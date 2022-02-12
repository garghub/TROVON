static void tcp_scalable_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tcp_is_cwnd_limited(sk))
return;
if (tp->snd_cwnd <= tp->snd_ssthresh)
tcp_slow_start(tp, acked);
else
tcp_cong_avoid_ai(tp, min(tp->snd_cwnd, TCP_SCALABLE_AI_CNT),
1);
}
static u32 tcp_scalable_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
return max(tp->snd_cwnd - (tp->snd_cwnd>>TCP_SCALABLE_MD_SCALE), 2U);
}
static int __init tcp_scalable_register(void)
{
return tcp_register_congestion_control(&tcp_scalable);
}
static void __exit tcp_scalable_unregister(void)
{
tcp_unregister_congestion_control(&tcp_scalable);
}
