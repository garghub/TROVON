static bool bbr_full_bw_reached(const struct sock *sk)
{
const struct bbr *bbr = inet_csk_ca(sk);
return bbr->full_bw_cnt >= bbr_full_bw_cnt;
}
static u32 bbr_max_bw(const struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
return minmax_get(&bbr->bw);
}
static u32 bbr_bw(const struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
return bbr->lt_use_bw ? bbr->lt_bw : bbr_max_bw(sk);
}
static u64 bbr_rate_bytes_per_sec(struct sock *sk, u64 rate, int gain)
{
rate *= tcp_mss_to_mtu(sk, tcp_sk(sk)->mss_cache);
rate *= gain;
rate >>= BBR_SCALE;
rate *= USEC_PER_SEC;
return rate >> BW_SCALE;
}
static u32 bbr_bw_to_pacing_rate(struct sock *sk, u32 bw, int gain)
{
u64 rate = bw;
rate = bbr_rate_bytes_per_sec(sk, rate, gain);
rate = min_t(u64, rate, sk->sk_max_pacing_rate);
return rate;
}
static void bbr_init_pacing_rate_from_rtt(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u64 bw;
u32 rtt_us;
if (tp->srtt_us) {
rtt_us = max(tp->srtt_us >> 3, 1U);
bbr->has_seen_rtt = 1;
} else {
rtt_us = USEC_PER_MSEC;
}
bw = (u64)tp->snd_cwnd * BW_UNIT;
do_div(bw, rtt_us);
sk->sk_pacing_rate = bbr_bw_to_pacing_rate(sk, bw, bbr_high_gain);
}
static void bbr_set_pacing_rate(struct sock *sk, u32 bw, int gain)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u32 rate = bbr_bw_to_pacing_rate(sk, bw, gain);
if (unlikely(!bbr->has_seen_rtt && tp->srtt_us))
bbr_init_pacing_rate_from_rtt(sk);
if (bbr_full_bw_reached(sk) || rate > sk->sk_pacing_rate)
sk->sk_pacing_rate = rate;
}
static u32 bbr_tso_segs_goal(struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
return bbr->tso_segs_goal;
}
static void bbr_set_tso_segs_goal(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u32 min_segs;
min_segs = sk->sk_pacing_rate < (bbr_min_tso_rate >> 3) ? 1 : 2;
bbr->tso_segs_goal = min(tcp_tso_autosize(sk, tp->mss_cache, min_segs),
0x7FU);
}
static void bbr_save_cwnd(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
if (bbr->prev_ca_state < TCP_CA_Recovery && bbr->mode != BBR_PROBE_RTT)
bbr->prior_cwnd = tp->snd_cwnd;
else
bbr->prior_cwnd = max(bbr->prior_cwnd, tp->snd_cwnd);
}
static void bbr_cwnd_event(struct sock *sk, enum tcp_ca_event event)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
if (event == CA_EVENT_TX_START && tp->app_limited) {
bbr->idle_restart = 1;
if (bbr->mode == BBR_PROBE_BW)
bbr_set_pacing_rate(sk, bbr_bw(sk), BBR_UNIT);
}
}
static u32 bbr_target_cwnd(struct sock *sk, u32 bw, int gain)
{
struct bbr *bbr = inet_csk_ca(sk);
u32 cwnd;
u64 w;
if (unlikely(bbr->min_rtt_us == ~0U))
return TCP_INIT_CWND;
w = (u64)bw * bbr->min_rtt_us;
cwnd = (((w * gain) >> BBR_SCALE) + BW_UNIT - 1) / BW_UNIT;
cwnd += 3 * bbr->tso_segs_goal;
cwnd = (cwnd + 1) & ~1U;
return cwnd;
}
static bool bbr_set_cwnd_to_recover_or_restore(
struct sock *sk, const struct rate_sample *rs, u32 acked, u32 *new_cwnd)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u8 prev_state = bbr->prev_ca_state, state = inet_csk(sk)->icsk_ca_state;
u32 cwnd = tp->snd_cwnd;
if (rs->losses > 0)
cwnd = max_t(s32, cwnd - rs->losses, 1);
if (state == TCP_CA_Recovery && prev_state != TCP_CA_Recovery) {
bbr->packet_conservation = 1;
bbr->next_rtt_delivered = tp->delivered;
cwnd = tcp_packets_in_flight(tp) + acked;
} else if (prev_state >= TCP_CA_Recovery && state < TCP_CA_Recovery) {
bbr->restore_cwnd = 1;
bbr->packet_conservation = 0;
}
bbr->prev_ca_state = state;
if (bbr->restore_cwnd) {
cwnd = max(cwnd, bbr->prior_cwnd);
bbr->restore_cwnd = 0;
}
if (bbr->packet_conservation) {
*new_cwnd = max(cwnd, tcp_packets_in_flight(tp) + acked);
return true;
}
*new_cwnd = cwnd;
return false;
}
static void bbr_set_cwnd(struct sock *sk, const struct rate_sample *rs,
u32 acked, u32 bw, int gain)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u32 cwnd = 0, target_cwnd = 0;
if (!acked)
return;
if (bbr_set_cwnd_to_recover_or_restore(sk, rs, acked, &cwnd))
goto done;
target_cwnd = bbr_target_cwnd(sk, bw, gain);
if (bbr_full_bw_reached(sk))
cwnd = min(cwnd + acked, target_cwnd);
else if (cwnd < target_cwnd || tp->delivered < TCP_INIT_CWND)
cwnd = cwnd + acked;
cwnd = max(cwnd, bbr_cwnd_min_target);
done:
tp->snd_cwnd = min(cwnd, tp->snd_cwnd_clamp);
if (bbr->mode == BBR_PROBE_RTT)
tp->snd_cwnd = min(tp->snd_cwnd, bbr_cwnd_min_target);
}
static bool bbr_is_next_cycle_phase(struct sock *sk,
const struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
bool is_full_length =
tcp_stamp_us_delta(tp->delivered_mstamp, bbr->cycle_mstamp) >
bbr->min_rtt_us;
u32 inflight, bw;
if (bbr->pacing_gain == BBR_UNIT)
return is_full_length;
inflight = rs->prior_in_flight;
bw = bbr_max_bw(sk);
if (bbr->pacing_gain > BBR_UNIT)
return is_full_length &&
(rs->losses ||
inflight >= bbr_target_cwnd(sk, bw, bbr->pacing_gain));
return is_full_length ||
inflight <= bbr_target_cwnd(sk, bw, BBR_UNIT);
}
static void bbr_advance_cycle_phase(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
bbr->cycle_idx = (bbr->cycle_idx + 1) & (CYCLE_LEN - 1);
bbr->cycle_mstamp = tp->delivered_mstamp;
bbr->pacing_gain = bbr_pacing_gain[bbr->cycle_idx];
}
static void bbr_update_cycle_phase(struct sock *sk,
const struct rate_sample *rs)
{
struct bbr *bbr = inet_csk_ca(sk);
if ((bbr->mode == BBR_PROBE_BW) && !bbr->lt_use_bw &&
bbr_is_next_cycle_phase(sk, rs))
bbr_advance_cycle_phase(sk);
}
static void bbr_reset_startup_mode(struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
bbr->mode = BBR_STARTUP;
bbr->pacing_gain = bbr_high_gain;
bbr->cwnd_gain = bbr_high_gain;
}
static void bbr_reset_probe_bw_mode(struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
bbr->mode = BBR_PROBE_BW;
bbr->pacing_gain = BBR_UNIT;
bbr->cwnd_gain = bbr_cwnd_gain;
bbr->cycle_idx = CYCLE_LEN - 1 - prandom_u32_max(bbr_cycle_rand);
bbr_advance_cycle_phase(sk);
}
static void bbr_reset_mode(struct sock *sk)
{
if (!bbr_full_bw_reached(sk))
bbr_reset_startup_mode(sk);
else
bbr_reset_probe_bw_mode(sk);
}
static void bbr_reset_lt_bw_sampling_interval(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
bbr->lt_last_stamp = div_u64(tp->delivered_mstamp, USEC_PER_MSEC);
bbr->lt_last_delivered = tp->delivered;
bbr->lt_last_lost = tp->lost;
bbr->lt_rtt_cnt = 0;
}
static void bbr_reset_lt_bw_sampling(struct sock *sk)
{
struct bbr *bbr = inet_csk_ca(sk);
bbr->lt_bw = 0;
bbr->lt_use_bw = 0;
bbr->lt_is_sampling = false;
bbr_reset_lt_bw_sampling_interval(sk);
}
static void bbr_lt_bw_interval_done(struct sock *sk, u32 bw)
{
struct bbr *bbr = inet_csk_ca(sk);
u32 diff;
if (bbr->lt_bw) {
diff = abs(bw - bbr->lt_bw);
if ((diff * BBR_UNIT <= bbr_lt_bw_ratio * bbr->lt_bw) ||
(bbr_rate_bytes_per_sec(sk, diff, BBR_UNIT) <=
bbr_lt_bw_diff)) {
bbr->lt_bw = (bw + bbr->lt_bw) >> 1;
bbr->lt_use_bw = 1;
bbr->pacing_gain = BBR_UNIT;
bbr->lt_rtt_cnt = 0;
return;
}
}
bbr->lt_bw = bw;
bbr_reset_lt_bw_sampling_interval(sk);
}
static void bbr_lt_bw_sampling(struct sock *sk, const struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u32 lost, delivered;
u64 bw;
u32 t;
if (bbr->lt_use_bw) {
if (bbr->mode == BBR_PROBE_BW && bbr->round_start &&
++bbr->lt_rtt_cnt >= bbr_lt_bw_max_rtts) {
bbr_reset_lt_bw_sampling(sk);
bbr_reset_probe_bw_mode(sk);
}
return;
}
if (!bbr->lt_is_sampling) {
if (!rs->losses)
return;
bbr_reset_lt_bw_sampling_interval(sk);
bbr->lt_is_sampling = true;
}
if (rs->is_app_limited) {
bbr_reset_lt_bw_sampling(sk);
return;
}
if (bbr->round_start)
bbr->lt_rtt_cnt++;
if (bbr->lt_rtt_cnt < bbr_lt_intvl_min_rtts)
return;
if (bbr->lt_rtt_cnt > 4 * bbr_lt_intvl_min_rtts) {
bbr_reset_lt_bw_sampling(sk);
return;
}
if (!rs->losses)
return;
lost = tp->lost - bbr->lt_last_lost;
delivered = tp->delivered - bbr->lt_last_delivered;
if (!delivered || (lost << BBR_SCALE) < bbr_lt_loss_thresh * delivered)
return;
t = div_u64(tp->delivered_mstamp, USEC_PER_MSEC) - bbr->lt_last_stamp;
if ((s32)t < 1)
return;
if (t >= ~0U / USEC_PER_MSEC) {
bbr_reset_lt_bw_sampling(sk);
return;
}
t *= USEC_PER_MSEC;
bw = (u64)delivered * BW_UNIT;
do_div(bw, t);
bbr_lt_bw_interval_done(sk, bw);
}
static void bbr_update_bw(struct sock *sk, const struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u64 bw;
bbr->round_start = 0;
if (rs->delivered < 0 || rs->interval_us <= 0)
return;
if (!before(rs->prior_delivered, bbr->next_rtt_delivered)) {
bbr->next_rtt_delivered = tp->delivered;
bbr->rtt_cnt++;
bbr->round_start = 1;
bbr->packet_conservation = 0;
}
bbr_lt_bw_sampling(sk, rs);
bw = (u64)rs->delivered * BW_UNIT;
do_div(bw, rs->interval_us);
if (!rs->is_app_limited || bw >= bbr_max_bw(sk)) {
minmax_running_max(&bbr->bw, bbr_bw_rtts, bbr->rtt_cnt, bw);
}
}
static void bbr_check_full_bw_reached(struct sock *sk,
const struct rate_sample *rs)
{
struct bbr *bbr = inet_csk_ca(sk);
u32 bw_thresh;
if (bbr_full_bw_reached(sk) || !bbr->round_start || rs->is_app_limited)
return;
bw_thresh = (u64)bbr->full_bw * bbr_full_bw_thresh >> BBR_SCALE;
if (bbr_max_bw(sk) >= bw_thresh) {
bbr->full_bw = bbr_max_bw(sk);
bbr->full_bw_cnt = 0;
return;
}
++bbr->full_bw_cnt;
}
static void bbr_check_drain(struct sock *sk, const struct rate_sample *rs)
{
struct bbr *bbr = inet_csk_ca(sk);
if (bbr->mode == BBR_STARTUP && bbr_full_bw_reached(sk)) {
bbr->mode = BBR_DRAIN;
bbr->pacing_gain = bbr_drain_gain;
bbr->cwnd_gain = bbr_high_gain;
}
if (bbr->mode == BBR_DRAIN &&
tcp_packets_in_flight(tcp_sk(sk)) <=
bbr_target_cwnd(sk, bbr_max_bw(sk), BBR_UNIT))
bbr_reset_probe_bw_mode(sk);
}
static void bbr_update_min_rtt(struct sock *sk, const struct rate_sample *rs)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
bool filter_expired;
filter_expired = after(tcp_jiffies32,
bbr->min_rtt_stamp + bbr_min_rtt_win_sec * HZ);
if (rs->rtt_us >= 0 &&
(rs->rtt_us <= bbr->min_rtt_us || filter_expired)) {
bbr->min_rtt_us = rs->rtt_us;
bbr->min_rtt_stamp = tcp_jiffies32;
}
if (bbr_probe_rtt_mode_ms > 0 && filter_expired &&
!bbr->idle_restart && bbr->mode != BBR_PROBE_RTT) {
bbr->mode = BBR_PROBE_RTT;
bbr->pacing_gain = BBR_UNIT;
bbr->cwnd_gain = BBR_UNIT;
bbr_save_cwnd(sk);
bbr->probe_rtt_done_stamp = 0;
}
if (bbr->mode == BBR_PROBE_RTT) {
tp->app_limited =
(tp->delivered + tcp_packets_in_flight(tp)) ? : 1;
if (!bbr->probe_rtt_done_stamp &&
tcp_packets_in_flight(tp) <= bbr_cwnd_min_target) {
bbr->probe_rtt_done_stamp = tcp_jiffies32 +
msecs_to_jiffies(bbr_probe_rtt_mode_ms);
bbr->probe_rtt_round_done = 0;
bbr->next_rtt_delivered = tp->delivered;
} else if (bbr->probe_rtt_done_stamp) {
if (bbr->round_start)
bbr->probe_rtt_round_done = 1;
if (bbr->probe_rtt_round_done &&
after(tcp_jiffies32, bbr->probe_rtt_done_stamp)) {
bbr->min_rtt_stamp = tcp_jiffies32;
bbr->restore_cwnd = 1;
bbr_reset_mode(sk);
}
}
}
bbr->idle_restart = 0;
}
static void bbr_update_model(struct sock *sk, const struct rate_sample *rs)
{
bbr_update_bw(sk, rs);
bbr_update_cycle_phase(sk, rs);
bbr_check_full_bw_reached(sk, rs);
bbr_check_drain(sk, rs);
bbr_update_min_rtt(sk, rs);
}
static void bbr_main(struct sock *sk, const struct rate_sample *rs)
{
struct bbr *bbr = inet_csk_ca(sk);
u32 bw;
bbr_update_model(sk, rs);
bw = bbr_bw(sk);
bbr_set_pacing_rate(sk, bw, bbr->pacing_gain);
bbr_set_tso_segs_goal(sk);
bbr_set_cwnd(sk, rs, rs->acked_sacked, bw, bbr->cwnd_gain);
}
static void bbr_init(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
bbr->prior_cwnd = 0;
bbr->tso_segs_goal = 0;
bbr->rtt_cnt = 0;
bbr->next_rtt_delivered = 0;
bbr->prev_ca_state = TCP_CA_Open;
bbr->packet_conservation = 0;
bbr->probe_rtt_done_stamp = 0;
bbr->probe_rtt_round_done = 0;
bbr->min_rtt_us = tcp_min_rtt(tp);
bbr->min_rtt_stamp = tcp_jiffies32;
minmax_reset(&bbr->bw, bbr->rtt_cnt, 0);
bbr->has_seen_rtt = 0;
bbr_init_pacing_rate_from_rtt(sk);
bbr->restore_cwnd = 0;
bbr->round_start = 0;
bbr->idle_restart = 0;
bbr->full_bw = 0;
bbr->full_bw_cnt = 0;
bbr->cycle_mstamp = 0;
bbr->cycle_idx = 0;
bbr_reset_lt_bw_sampling(sk);
bbr_reset_startup_mode(sk);
cmpxchg(&sk->sk_pacing_status, SK_PACING_NONE, SK_PACING_NEEDED);
}
static u32 bbr_sndbuf_expand(struct sock *sk)
{
return 3;
}
static u32 bbr_undo_cwnd(struct sock *sk)
{
return tcp_sk(sk)->snd_cwnd;
}
static u32 bbr_ssthresh(struct sock *sk)
{
bbr_save_cwnd(sk);
return TCP_INFINITE_SSTHRESH;
}
static size_t bbr_get_info(struct sock *sk, u32 ext, int *attr,
union tcp_cc_info *info)
{
if (ext & (1 << (INET_DIAG_BBRINFO - 1)) ||
ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
struct tcp_sock *tp = tcp_sk(sk);
struct bbr *bbr = inet_csk_ca(sk);
u64 bw = bbr_bw(sk);
bw = bw * tp->mss_cache * USEC_PER_SEC >> BW_SCALE;
memset(&info->bbr, 0, sizeof(info->bbr));
info->bbr.bbr_bw_lo = (u32)bw;
info->bbr.bbr_bw_hi = (u32)(bw >> 32);
info->bbr.bbr_min_rtt = bbr->min_rtt_us;
info->bbr.bbr_pacing_gain = bbr->pacing_gain;
info->bbr.bbr_cwnd_gain = bbr->cwnd_gain;
*attr = INET_DIAG_BBRINFO;
return sizeof(info->bbr);
}
return 0;
}
static void bbr_set_state(struct sock *sk, u8 new_state)
{
struct bbr *bbr = inet_csk_ca(sk);
if (new_state == TCP_CA_Loss) {
struct rate_sample rs = { .losses = 1 };
bbr->prev_ca_state = TCP_CA_Loss;
bbr->full_bw = 0;
bbr->round_start = 1;
bbr_lt_bw_sampling(sk, &rs);
}
}
static int __init bbr_register(void)
{
BUILD_BUG_ON(sizeof(struct bbr) > ICSK_CA_PRIV_SIZE);
return tcp_register_congestion_control(&tcp_bbr_cong_ops);
}
static void __exit bbr_unregister(void)
{
tcp_unregister_congestion_control(&tcp_bbr_cong_ops);
}
