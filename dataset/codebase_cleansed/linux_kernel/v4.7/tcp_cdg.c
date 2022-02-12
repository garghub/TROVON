static u32 __pure nexp_u32(u32 ux)
{
static const u16 v[] = {
65535,
65518, 65501, 65468, 65401, 65267, 65001, 64470, 63422,
61378, 57484, 50423, 38795, 22965, 8047, 987, 14,
};
u32 msb = ux >> 8;
u32 res;
int i;
if (msb > U16_MAX)
return 0;
res = U32_MAX - (ux & 0xff) * (U32_MAX / 1000000);
for (i = 1; msb; i++, msb >>= 1) {
u32 y = v[i & -(msb & 1)] + U32_C(1);
res = ((u64)res * y) >> 16;
}
return res;
}
static void tcp_cdg_hystart_update(struct sock *sk)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
ca->delay_min = min_not_zero(ca->delay_min, ca->rtt.min);
if (ca->delay_min == 0)
return;
if (hystart_detect & HYSTART_ACK_TRAIN) {
u32 now_us = div_u64(local_clock(), NSEC_PER_USEC);
if (ca->last_ack == 0 || !tcp_is_cwnd_limited(sk)) {
ca->last_ack = now_us;
ca->round_start = now_us;
} else if (before(now_us, ca->last_ack + 3000)) {
u32 base_owd = max(ca->delay_min / 2U, 125U);
ca->last_ack = now_us;
if (after(now_us, ca->round_start + base_owd)) {
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPHYSTARTTRAINDETECT);
NET_ADD_STATS(sock_net(sk),
LINUX_MIB_TCPHYSTARTTRAINCWND,
tp->snd_cwnd);
tp->snd_ssthresh = tp->snd_cwnd;
return;
}
}
}
if (hystart_detect & HYSTART_DELAY) {
if (ca->sample_cnt < 8) {
ca->sample_cnt++;
} else {
s32 thresh = max(ca->delay_min + ca->delay_min / 8U,
125U);
if (ca->rtt.min > thresh) {
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPHYSTARTDELAYDETECT);
NET_ADD_STATS(sock_net(sk),
LINUX_MIB_TCPHYSTARTDELAYCWND,
tp->snd_cwnd);
tp->snd_ssthresh = tp->snd_cwnd;
}
}
}
}
static s32 tcp_cdg_grad(struct cdg *ca)
{
s32 gmin = ca->rtt.min - ca->rtt_prev.min;
s32 gmax = ca->rtt.max - ca->rtt_prev.max;
s32 grad;
if (ca->gradients) {
ca->gsum.min += gmin - ca->gradients[ca->tail].min;
ca->gsum.max += gmax - ca->gradients[ca->tail].max;
ca->gradients[ca->tail].min = gmin;
ca->gradients[ca->tail].max = gmax;
ca->tail = (ca->tail + 1) & (window - 1);
gmin = ca->gsum.min;
gmax = ca->gsum.max;
}
grad = gmin > 0 ? gmin : gmax;
if (!ca->gfilled) {
if (!ca->gradients && window > 1)
grad *= window;
else if (ca->tail == 0)
ca->gfilled = true;
else
grad = (grad * window) / (int)ca->tail;
}
if (gmin <= -32 || gmax <= -32)
ca->backoff_cnt = 0;
if (use_tolerance) {
gmin = DIV_ROUND_CLOSEST(gmin, 64);
gmax = DIV_ROUND_CLOSEST(gmax, 64);
if (gmin > 0 && gmax <= 0)
ca->state = CDG_FULL;
else if ((gmin > 0 && gmax > 0) || gmax < 0)
ca->state = CDG_NONFULL;
}
return grad;
}
static bool tcp_cdg_backoff(struct sock *sk, u32 grad)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (prandom_u32() <= nexp_u32(grad * backoff_factor))
return false;
if (use_ineff) {
ca->backoff_cnt++;
if (ca->backoff_cnt > use_ineff)
return false;
}
ca->shadow_wnd = max(ca->shadow_wnd, tp->snd_cwnd);
ca->state = CDG_BACKOFF;
tcp_enter_cwr(sk);
return true;
}
static void tcp_cdg_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
u32 prior_snd_cwnd;
u32 incr;
if (tcp_in_slow_start(tp) && hystart_detect)
tcp_cdg_hystart_update(sk);
if (after(ack, ca->rtt_seq) && ca->rtt.v64) {
s32 grad = 0;
if (ca->rtt_prev.v64)
grad = tcp_cdg_grad(ca);
ca->rtt_seq = tp->snd_nxt;
ca->rtt_prev = ca->rtt;
ca->rtt.v64 = 0;
ca->last_ack = 0;
ca->sample_cnt = 0;
if (grad > 0 && tcp_cdg_backoff(sk, grad))
return;
}
if (!tcp_is_cwnd_limited(sk)) {
ca->shadow_wnd = min(ca->shadow_wnd, tp->snd_cwnd);
return;
}
prior_snd_cwnd = tp->snd_cwnd;
tcp_reno_cong_avoid(sk, ack, acked);
incr = tp->snd_cwnd - prior_snd_cwnd;
ca->shadow_wnd = max(ca->shadow_wnd, ca->shadow_wnd + incr);
}
static void tcp_cdg_acked(struct sock *sk, const struct ack_sample *sample)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (sample->rtt_us <= 0)
return;
if (tp->sacked_out == 0) {
if (sample->pkts_acked == 1 && ca->delack) {
ca->rtt.min = min(ca->rtt.min, sample->rtt_us);
ca->delack--;
return;
} else if (sample->pkts_acked > 1 && ca->delack < 5) {
ca->delack++;
}
}
ca->rtt.min = min_not_zero(ca->rtt.min, sample->rtt_us);
ca->rtt.max = max(ca->rtt.max, sample->rtt_us);
}
static u32 tcp_cdg_ssthresh(struct sock *sk)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
ca->undo_cwnd = tp->snd_cwnd;
if (ca->state == CDG_BACKOFF)
return max(2U, (tp->snd_cwnd * min(1024U, backoff_beta)) >> 10);
if (ca->state == CDG_NONFULL && use_tolerance)
return tp->snd_cwnd;
ca->shadow_wnd = min(ca->shadow_wnd >> 1, tp->snd_cwnd);
if (use_shadow)
return max3(2U, ca->shadow_wnd, tp->snd_cwnd >> 1);
return max(2U, tp->snd_cwnd >> 1);
}
static u32 tcp_cdg_undo_cwnd(struct sock *sk)
{
struct cdg *ca = inet_csk_ca(sk);
return max(tcp_sk(sk)->snd_cwnd, ca->undo_cwnd);
}
static void tcp_cdg_cwnd_event(struct sock *sk, const enum tcp_ca_event ev)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct minmax *gradients;
switch (ev) {
case CA_EVENT_CWND_RESTART:
gradients = ca->gradients;
if (gradients)
memset(gradients, 0, window * sizeof(gradients[0]));
memset(ca, 0, sizeof(*ca));
ca->gradients = gradients;
ca->rtt_seq = tp->snd_nxt;
ca->shadow_wnd = tp->snd_cwnd;
break;
case CA_EVENT_COMPLETE_CWR:
ca->state = CDG_UNKNOWN;
ca->rtt_seq = tp->snd_nxt;
ca->rtt_prev = ca->rtt;
ca->rtt.v64 = 0;
break;
default:
break;
}
}
static void tcp_cdg_init(struct sock *sk)
{
struct cdg *ca = inet_csk_ca(sk);
struct tcp_sock *tp = tcp_sk(sk);
if (window > 1)
ca->gradients = kcalloc(window, sizeof(ca->gradients[0]),
GFP_NOWAIT | __GFP_NOWARN);
ca->rtt_seq = tp->snd_nxt;
ca->shadow_wnd = tp->snd_cwnd;
}
static void tcp_cdg_release(struct sock *sk)
{
struct cdg *ca = inet_csk_ca(sk);
kfree(ca->gradients);
}
static int __init tcp_cdg_register(void)
{
if (backoff_beta > 1024 || window < 1 || window > 256)
return -ERANGE;
if (!is_power_of_2(window))
return -EINVAL;
BUILD_BUG_ON(sizeof(struct cdg) > ICSK_CA_PRIV_SIZE);
tcp_register_congestion_control(&tcp_cdg);
return 0;
}
static void __exit tcp_cdg_unregister(void)
{
tcp_unregister_congestion_control(&tcp_cdg);
}
