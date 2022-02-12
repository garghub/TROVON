int tcp_rack_mark_lost(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct sk_buff *skb;
u32 reo_wnd, prior_retrans = tp->retrans_out;
if (inet_csk(sk)->icsk_ca_state < TCP_CA_Recovery || !tp->rack.advanced)
return 0;
tp->rack.advanced = 0;
reo_wnd = 1000;
if (tp->rack.reord && tcp_min_rtt(tp) != ~0U)
reo_wnd = max(tcp_min_rtt(tp) >> 2, reo_wnd);
tcp_for_write_queue(skb, sk) {
struct tcp_skb_cb *scb = TCP_SKB_CB(skb);
if (skb == tcp_send_head(sk))
break;
if (!after(scb->end_seq, tp->snd_una) ||
scb->sacked & TCPCB_SACKED_ACKED)
continue;
if (skb_mstamp_after(&tp->rack.mstamp, &skb->skb_mstamp)) {
if (skb_mstamp_us_delta(&tp->rack.mstamp,
&skb->skb_mstamp) <= reo_wnd)
continue;
tcp_skb_mark_lost_uncond_verify(tp, skb);
if (scb->sacked & TCPCB_SACKED_RETRANS) {
scb->sacked &= ~TCPCB_SACKED_RETRANS;
tp->retrans_out -= tcp_skb_pcount(skb);
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPLOSTRETRANSMIT);
}
} else if (!(scb->sacked & TCPCB_RETRANS)) {
break;
}
}
return prior_retrans - tp->retrans_out;
}
void tcp_rack_advance(struct tcp_sock *tp,
const struct skb_mstamp *xmit_time, u8 sacked)
{
if (tp->rack.mstamp.v64 &&
!skb_mstamp_after(xmit_time, &tp->rack.mstamp))
return;
if (sacked & TCPCB_RETRANS) {
struct skb_mstamp now;
skb_mstamp_get(&now);
if (skb_mstamp_us_delta(&now, xmit_time) < tcp_min_rtt(tp))
return;
}
tp->rack.mstamp = *xmit_time;
tp->rack.advanced = 1;
}
