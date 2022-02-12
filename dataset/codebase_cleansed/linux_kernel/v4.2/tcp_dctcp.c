static void dctcp_reset(const struct tcp_sock *tp, struct dctcp *ca)
{
ca->next_seq = tp->snd_nxt;
ca->acked_bytes_ecn = 0;
ca->acked_bytes_total = 0;
}
static void dctcp_init(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
if ((tp->ecn_flags & TCP_ECN_OK) ||
(sk->sk_state == TCP_LISTEN ||
sk->sk_state == TCP_CLOSE)) {
struct dctcp *ca = inet_csk_ca(sk);
ca->prior_snd_una = tp->snd_una;
ca->prior_rcv_nxt = tp->rcv_nxt;
ca->dctcp_alpha = min(dctcp_alpha_on_init, DCTCP_MAX_ALPHA);
ca->delayed_ack_reserved = 0;
ca->ce_state = 0;
dctcp_reset(tp, ca);
return;
}
inet_csk(sk)->icsk_ca_ops = &dctcp_reno;
INET_ECN_dontxmit(sk);
}
static u32 dctcp_ssthresh(struct sock *sk)
{
const struct dctcp *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
return max(tp->snd_cwnd - ((tp->snd_cwnd * ca->dctcp_alpha) >> 11U), 2U);
}
static void dctcp_ce_state_0_to_1(struct sock *sk)
{
struct dctcp *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (!ca->ce_state && ca->delayed_ack_reserved) {
u32 tmp_rcv_nxt;
tmp_rcv_nxt = tp->rcv_nxt;
tp->ecn_flags &= ~TCP_ECN_DEMAND_CWR;
tp->rcv_nxt = ca->prior_rcv_nxt;
tcp_send_ack(sk);
tp->rcv_nxt = tmp_rcv_nxt;
}
ca->prior_rcv_nxt = tp->rcv_nxt;
ca->ce_state = 1;
tp->ecn_flags |= TCP_ECN_DEMAND_CWR;
}
static void dctcp_ce_state_1_to_0(struct sock *sk)
{
struct dctcp *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (ca->ce_state && ca->delayed_ack_reserved) {
u32 tmp_rcv_nxt;
tmp_rcv_nxt = tp->rcv_nxt;
tp->ecn_flags |= TCP_ECN_DEMAND_CWR;
tp->rcv_nxt = ca->prior_rcv_nxt;
tcp_send_ack(sk);
tp->rcv_nxt = tmp_rcv_nxt;
}
ca->prior_rcv_nxt = tp->rcv_nxt;
ca->ce_state = 0;
tp->ecn_flags &= ~TCP_ECN_DEMAND_CWR;
}
static void dctcp_update_alpha(struct sock *sk, u32 flags)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct dctcp *ca = inet_csk_ca(sk);
u32 acked_bytes = tp->snd_una - ca->prior_snd_una;
if (acked_bytes == 0 && !(flags & CA_ACK_WIN_UPDATE))
acked_bytes = inet_csk(sk)->icsk_ack.rcv_mss;
if (acked_bytes) {
ca->acked_bytes_total += acked_bytes;
ca->prior_snd_una = tp->snd_una;
if (flags & CA_ACK_ECE)
ca->acked_bytes_ecn += acked_bytes;
}
if (!before(tp->snd_una, ca->next_seq)) {
u64 bytes_ecn = ca->acked_bytes_ecn;
u32 alpha = ca->dctcp_alpha;
alpha -= alpha >> dctcp_shift_g;
if (bytes_ecn) {
bytes_ecn <<= (10 - dctcp_shift_g);
do_div(bytes_ecn, max(1U, ca->acked_bytes_total));
alpha = min(alpha + (u32)bytes_ecn, DCTCP_MAX_ALPHA);
}
WRITE_ONCE(ca->dctcp_alpha, alpha);
dctcp_reset(tp, ca);
}
}
static void dctcp_state(struct sock *sk, u8 new_state)
{
if (dctcp_clamp_alpha_on_loss && new_state == TCP_CA_Loss) {
struct dctcp *ca = inet_csk_ca(sk);
ca->dctcp_alpha = DCTCP_MAX_ALPHA;
}
}
static void dctcp_update_ack_reserved(struct sock *sk, enum tcp_ca_event ev)
{
struct dctcp *ca = inet_csk_ca(sk);
switch (ev) {
case CA_EVENT_DELAYED_ACK:
if (!ca->delayed_ack_reserved)
ca->delayed_ack_reserved = 1;
break;
case CA_EVENT_NON_DELAYED_ACK:
if (ca->delayed_ack_reserved)
ca->delayed_ack_reserved = 0;
break;
default:
break;
}
}
static void dctcp_cwnd_event(struct sock *sk, enum tcp_ca_event ev)
{
switch (ev) {
case CA_EVENT_ECN_IS_CE:
dctcp_ce_state_0_to_1(sk);
break;
case CA_EVENT_ECN_NO_CE:
dctcp_ce_state_1_to_0(sk);
break;
case CA_EVENT_DELAYED_ACK:
case CA_EVENT_NON_DELAYED_ACK:
dctcp_update_ack_reserved(sk, ev);
break;
default:
break;
}
}
static size_t dctcp_get_info(struct sock *sk, u32 ext, int *attr,
union tcp_cc_info *info)
{
const struct dctcp *ca = inet_csk_ca(sk);
if (ext & (1 << (INET_DIAG_DCTCPINFO - 1)) ||
ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
memset(info, 0, sizeof(struct tcp_dctcp_info));
if (inet_csk(sk)->icsk_ca_ops != &dctcp_reno) {
info->dctcp.dctcp_enabled = 1;
info->dctcp.dctcp_ce_state = (u16) ca->ce_state;
info->dctcp.dctcp_alpha = ca->dctcp_alpha;
info->dctcp.dctcp_ab_ecn = ca->acked_bytes_ecn;
info->dctcp.dctcp_ab_tot = ca->acked_bytes_total;
}
*attr = INET_DIAG_DCTCPINFO;
return sizeof(*info);
}
return 0;
}
static int __init dctcp_register(void)
{
BUILD_BUG_ON(sizeof(struct dctcp) > ICSK_CA_PRIV_SIZE);
return tcp_register_congestion_control(&dctcp);
}
static void __exit dctcp_unregister(void)
{
tcp_unregister_congestion_control(&dctcp);
}
