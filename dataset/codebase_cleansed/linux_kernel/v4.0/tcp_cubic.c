static inline void bictcp_reset(struct bictcp *ca)
{
ca->cnt = 0;
ca->last_max_cwnd = 0;
ca->last_cwnd = 0;
ca->last_time = 0;
ca->bic_origin_point = 0;
ca->bic_K = 0;
ca->delay_min = 0;
ca->epoch_start = 0;
ca->ack_cnt = 0;
ca->tcp_cwnd = 0;
ca->found = 0;
}
static inline u32 bictcp_clock(void)
{
#if HZ < 1000
return ktime_to_ms(ktime_get_real());
#else
return jiffies_to_msecs(jiffies);
#endif
}
static inline void bictcp_hystart_reset(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
ca->round_start = ca->last_ack = bictcp_clock();
ca->end_seq = tp->snd_nxt;
ca->curr_rtt = 0;
ca->sample_cnt = 0;
}
static void bictcp_init(struct sock *sk)
{
struct bictcp *ca = inet_csk_ca(sk);
bictcp_reset(ca);
ca->loss_cwnd = 0;
if (hystart)
bictcp_hystart_reset(sk);
if (!hystart && initial_ssthresh)
tcp_sk(sk)->snd_ssthresh = initial_ssthresh;
}
static u32 cubic_root(u64 a)
{
u32 x, b, shift;
static const u8 v[] = {
0, 54, 54, 54, 118, 118, 118, 118,
123, 129, 134, 138, 143, 147, 151, 156,
157, 161, 164, 168, 170, 173, 176, 179,
181, 185, 187, 190, 192, 194, 197, 199,
200, 202, 204, 206, 209, 211, 213, 215,
217, 219, 221, 222, 224, 225, 227, 229,
231, 232, 234, 236, 237, 239, 240, 242,
244, 245, 246, 248, 250, 251, 252, 254,
};
b = fls64(a);
if (b < 7) {
return ((u32)v[(u32)a] + 35) >> 6;
}
b = ((b * 84) >> 8) - 1;
shift = (a >> (b * 3));
x = ((u32)(((u32)v[shift] + 10) << b)) >> 6;
x = (2 * x + (u32)div64_u64(a, (u64)x * (u64)(x - 1)));
x = ((x * 341) >> 10);
return x;
}
static inline void bictcp_update(struct bictcp *ca, u32 cwnd, u32 acked)
{
u32 delta, bic_target, max_cnt;
u64 offs, t;
ca->ack_cnt += acked;
if (ca->last_cwnd == cwnd &&
(s32)(tcp_time_stamp - ca->last_time) <= HZ / 32)
return;
if (ca->epoch_start && tcp_time_stamp == ca->last_time)
goto tcp_friendliness;
ca->last_cwnd = cwnd;
ca->last_time = tcp_time_stamp;
if (ca->epoch_start == 0) {
ca->epoch_start = tcp_time_stamp;
ca->ack_cnt = acked;
ca->tcp_cwnd = cwnd;
if (ca->last_max_cwnd <= cwnd) {
ca->bic_K = 0;
ca->bic_origin_point = cwnd;
} else {
ca->bic_K = cubic_root(cube_factor
* (ca->last_max_cwnd - cwnd));
ca->bic_origin_point = ca->last_max_cwnd;
}
}
t = (s32)(tcp_time_stamp - ca->epoch_start);
t += msecs_to_jiffies(ca->delay_min >> 3);
t <<= BICTCP_HZ;
do_div(t, HZ);
if (t < ca->bic_K)
offs = ca->bic_K - t;
else
offs = t - ca->bic_K;
delta = (cube_rtt_scale * offs * offs * offs) >> (10+3*BICTCP_HZ);
if (t < ca->bic_K)
bic_target = ca->bic_origin_point - delta;
else
bic_target = ca->bic_origin_point + delta;
if (bic_target > cwnd) {
ca->cnt = cwnd / (bic_target - cwnd);
} else {
ca->cnt = 100 * cwnd;
}
if (ca->last_max_cwnd == 0 && ca->cnt > 20)
ca->cnt = 20;
tcp_friendliness:
if (tcp_friendliness) {
u32 scale = beta_scale;
delta = (cwnd * scale) >> 3;
while (ca->ack_cnt > delta) {
ca->ack_cnt -= delta;
ca->tcp_cwnd++;
}
if (ca->tcp_cwnd > cwnd) {
delta = ca->tcp_cwnd - cwnd;
max_cnt = cwnd / delta;
if (ca->cnt > max_cnt)
ca->cnt = max_cnt;
}
}
ca->cnt = max(ca->cnt, 2U);
}
static void bictcp_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
if (!tcp_is_cwnd_limited(sk))
return;
if (tp->snd_cwnd <= tp->snd_ssthresh) {
if (hystart && after(ack, ca->end_seq))
bictcp_hystart_reset(sk);
acked = tcp_slow_start(tp, acked);
if (!acked)
return;
}
bictcp_update(ca, tp->snd_cwnd, acked);
tcp_cong_avoid_ai(tp, ca->cnt, acked);
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
return max((tp->snd_cwnd * beta) / BICTCP_BETA_SCALE, 2U);
}
static u32 bictcp_undo_cwnd(struct sock *sk)
{
struct bictcp *ca = inet_csk_ca(sk);
return max(tcp_sk(sk)->snd_cwnd, ca->loss_cwnd);
}
static void bictcp_state(struct sock *sk, u8 new_state)
{
if (new_state == TCP_CA_Loss) {
bictcp_reset(inet_csk_ca(sk));
bictcp_hystart_reset(sk);
}
}
static void hystart_update(struct sock *sk, u32 delay)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
if (ca->found & hystart_detect)
return;
if (hystart_detect & HYSTART_ACK_TRAIN) {
u32 now = bictcp_clock();
if ((s32)(now - ca->last_ack) <= hystart_ack_delta) {
ca->last_ack = now;
if ((s32)(now - ca->round_start) > ca->delay_min >> 4) {
ca->found |= HYSTART_ACK_TRAIN;
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPHYSTARTTRAINDETECT);
NET_ADD_STATS_BH(sock_net(sk),
LINUX_MIB_TCPHYSTARTTRAINCWND,
tp->snd_cwnd);
tp->snd_ssthresh = tp->snd_cwnd;
}
}
}
if (hystart_detect & HYSTART_DELAY) {
if (ca->sample_cnt < HYSTART_MIN_SAMPLES) {
if (ca->curr_rtt == 0 || ca->curr_rtt > delay)
ca->curr_rtt = delay;
ca->sample_cnt++;
} else {
if (ca->curr_rtt > ca->delay_min +
HYSTART_DELAY_THRESH(ca->delay_min >> 3)) {
ca->found |= HYSTART_DELAY;
NET_INC_STATS_BH(sock_net(sk),
LINUX_MIB_TCPHYSTARTDELAYDETECT);
NET_ADD_STATS_BH(sock_net(sk),
LINUX_MIB_TCPHYSTARTDELAYCWND,
tp->snd_cwnd);
tp->snd_ssthresh = tp->snd_cwnd;
}
}
}
}
static void bictcp_acked(struct sock *sk, u32 cnt, s32 rtt_us)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct bictcp *ca = inet_csk_ca(sk);
u32 delay;
if (rtt_us < 0)
return;
if (ca->epoch_start && (s32)(tcp_time_stamp - ca->epoch_start) < HZ)
return;
delay = (rtt_us << 3) / USEC_PER_MSEC;
if (delay == 0)
delay = 1;
if (ca->delay_min == 0 || ca->delay_min > delay)
ca->delay_min = delay;
if (hystart && tp->snd_cwnd <= tp->snd_ssthresh &&
tp->snd_cwnd >= hystart_low_window)
hystart_update(sk, delay);
}
static int __init cubictcp_register(void)
{
BUILD_BUG_ON(sizeof(struct bictcp) > ICSK_CA_PRIV_SIZE);
beta_scale = 8*(BICTCP_BETA_SCALE+beta) / 3
/ (BICTCP_BETA_SCALE - beta);
cube_rtt_scale = (bic_scale * 10);
cube_factor = 1ull << (10+3*BICTCP_HZ);
do_div(cube_factor, bic_scale * 10);
return tcp_register_congestion_control(&cubictcp);
}
static void __exit cubictcp_unregister(void)
{
tcp_unregister_congestion_control(&cubictcp);
}
