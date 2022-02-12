void tcp_rate_skb_sent(struct sock *sk, struct sk_buff *skb)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tp->packets_out) {
tp->first_tx_mstamp = skb->skb_mstamp;
tp->delivered_mstamp = skb->skb_mstamp;
}
TCP_SKB_CB(skb)->tx.first_tx_mstamp = tp->first_tx_mstamp;
TCP_SKB_CB(skb)->tx.delivered_mstamp = tp->delivered_mstamp;
TCP_SKB_CB(skb)->tx.delivered = tp->delivered;
TCP_SKB_CB(skb)->tx.is_app_limited = tp->app_limited ? 1 : 0;
}
void tcp_rate_skb_delivered(struct sock *sk, struct sk_buff *skb,
struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_skb_cb *scb = TCP_SKB_CB(skb);
if (!scb->tx.delivered_mstamp.v64)
return;
if (!rs->prior_delivered ||
after(scb->tx.delivered, rs->prior_delivered)) {
rs->prior_delivered = scb->tx.delivered;
rs->prior_mstamp = scb->tx.delivered_mstamp;
rs->is_app_limited = scb->tx.is_app_limited;
rs->is_retrans = scb->sacked & TCPCB_RETRANS;
rs->interval_us = skb_mstamp_us_delta(
&skb->skb_mstamp,
&scb->tx.first_tx_mstamp);
tp->first_tx_mstamp = skb->skb_mstamp;
}
if (scb->sacked & TCPCB_SACKED_ACKED)
scb->tx.delivered_mstamp.v64 = 0;
}
void tcp_rate_gen(struct sock *sk, u32 delivered, u32 lost,
struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
u32 snd_us, ack_us;
if (tp->app_limited && after(tp->delivered, tp->app_limited))
tp->app_limited = 0;
if (delivered)
tp->delivered_mstamp = tp->tcp_mstamp;
rs->acked_sacked = delivered;
rs->losses = lost;
if (!rs->prior_mstamp.v64) {
rs->delivered = -1;
rs->interval_us = -1;
return;
}
rs->delivered = tp->delivered - rs->prior_delivered;
snd_us = rs->interval_us;
ack_us = skb_mstamp_us_delta(&tp->tcp_mstamp,
&rs->prior_mstamp);
rs->interval_us = max(snd_us, ack_us);
if (unlikely(rs->interval_us < tcp_min_rtt(tp))) {
if (!rs->is_retrans)
pr_debug("tcp rate: %ld %d %u %u %u\n",
rs->interval_us, rs->delivered,
inet_csk(sk)->icsk_ca_state,
tp->rx_opt.sack_ok, tcp_min_rtt(tp));
rs->interval_us = -1;
return;
}
if (!rs->is_app_limited ||
((u64)rs->delivered * tp->rate_interval_us >=
(u64)tp->rate_delivered * rs->interval_us)) {
tp->rate_delivered = rs->delivered;
tp->rate_interval_us = rs->interval_us;
tp->rate_app_limited = rs->is_app_limited;
}
}
void tcp_rate_check_app_limited(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
if (
tp->write_seq - tp->snd_nxt < tp->mss_cache &&
sk_wmem_alloc_get(sk) < SKB_TRUESIZE(1) &&
tcp_packets_in_flight(tp) < tp->snd_cwnd &&
tp->lost_out <= tp->retrans_out)
tp->app_limited =
(tp->delivered + tcp_packets_in_flight(tp)) ? : 1;
}
