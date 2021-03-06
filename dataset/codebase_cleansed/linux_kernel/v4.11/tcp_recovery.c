static void tcp_rack_mark_skb_lost(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
tcp_skb_mark_lost_uncond_verify(tp, skb);
if (TCP_SKB_CB(skb)->sacked & TCPCB_SACKED_RETRANS) {
TCP_SKB_CB(skb)->sacked &= ~TCPCB_SACKED_RETRANS;
tp->retrans_out -= tcp_skb_pcount(skb);
NET_ADD_STATS(sock_net(sk), LINUX_MIB_TCPLOSTRETRANSMIT,
tcp_skb_pcount(skb));
}
}
static bool tcp_rack_sent_after(const struct skb_mstamp *t1,
const struct skb_mstamp *t2,
u32 seq1, u32 seq2)
{
return skb_mstamp_after(t1, t2) ||
(t1->v64 == t2->v64 && after(seq1, seq2));
}
static void tcp_rack_detect_loss(struct sock *sk, const struct skb_mstamp *now,
u32 *reo_timeout)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
u32 reo_wnd;
*reo_timeout = 0;
reo_wnd = 1000;
if ((tp->rack.reord || !tp->lost_out) && tcp_min_rtt(tp) != ~0U)
reo_wnd = max(tcp_min_rtt(tp) >> 2, reo_wnd);
tcp_for_write_queue(skb, sk) {
struct tcp_skb_cb *scb = TCP_SKB_CB(skb);
if (skb == tcp_send_head(sk))
break;
if (!after(scb->end_seq, tp->snd_una) ||
scb->sacked & TCPCB_SACKED_ACKED)
continue;
if (tcp_rack_sent_after(&tp->rack.mstamp, &skb->skb_mstamp,
tp->rack.end_seq, scb->end_seq)) {
u32 elapsed = skb_mstamp_us_delta(now,
&skb->skb_mstamp);
s32 remaining = tp->rack.rtt_us + reo_wnd - elapsed;
if (remaining < 0) {
tcp_rack_mark_skb_lost(sk, skb);
continue;
}
if ((scb->sacked & TCPCB_LOST) &&
!(scb->sacked & TCPCB_SACKED_RETRANS))
continue;
*reo_timeout = max_t(u32, *reo_timeout, 1 + remaining);
} else if (!(scb->sacked & TCPCB_RETRANS)) {
break;
}
}
}
void tcp_rack_mark_lost(struct sock *sk, const struct skb_mstamp *now)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 timeout;
if (!tp->rack.advanced)
return;
tp->rack.advanced = 0;
tcp_rack_detect_loss(sk, now, &timeout);
if (timeout) {
timeout = usecs_to_jiffies(timeout + TCP_REO_TIMEOUT_MIN);
inet_csk_reset_xmit_timer(sk, ICSK_TIME_REO_TIMEOUT,
timeout, inet_csk(sk)->icsk_rto);
}
}
void tcp_rack_advance(struct tcp_sock *tp, u8 sacked, u32 end_seq,
const struct skb_mstamp *xmit_time,
const struct skb_mstamp *ack_time)
{
u32 rtt_us;
if (tp->rack.mstamp.v64 &&
!tcp_rack_sent_after(xmit_time, &tp->rack.mstamp,
end_seq, tp->rack.end_seq))
return;
rtt_us = skb_mstamp_us_delta(ack_time, xmit_time);
if (sacked & TCPCB_RETRANS) {
if (rtt_us < tcp_min_rtt(tp))
return;
}
tp->rack.rtt_us = rtt_us;
tp->rack.mstamp = *xmit_time;
tp->rack.end_seq = end_seq;
tp->rack.advanced = 1;
}
void tcp_rack_reo_timeout(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct skb_mstamp now;
u32 timeout, prior_inflight;
skb_mstamp_get(&now);
prior_inflight = tcp_packets_in_flight(tp);
tcp_rack_detect_loss(sk, &now, &timeout);
if (prior_inflight != tcp_packets_in_flight(tp)) {
if (inet_csk(sk)->icsk_ca_state != TCP_CA_Recovery) {
tcp_enter_recovery(sk, false);
if (!inet_csk(sk)->icsk_ca_ops->cong_control)
tcp_cwnd_reduction(sk, 1, 0);
}
tcp_xmit_retransmit_queue(sk);
}
if (inet_csk(sk)->icsk_pending != ICSK_TIME_RETRANS)
tcp_rearm_rto(sk);
}
