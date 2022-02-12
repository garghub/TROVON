static inline struct mlx5e_cq_moder mlx5e_am_get_profile(u8 cq_period_mode, int ix)
{
return profile[cq_period_mode][ix];
}
struct mlx5e_cq_moder mlx5e_am_get_def_profile(u8 rx_cq_period_mode)
{
int default_profile_ix;
if (rx_cq_period_mode == MLX5_CQ_PERIOD_MODE_START_FROM_CQE)
default_profile_ix = MLX5E_RX_AM_DEF_PROFILE_CQE;
else
default_profile_ix = MLX5E_RX_AM_DEF_PROFILE_EQE;
return profile[rx_cq_period_mode][default_profile_ix];
}
static bool mlx5e_am_on_top(struct mlx5e_rx_am *am)
{
switch (am->tune_state) {
case MLX5E_AM_PARKING_ON_TOP:
case MLX5E_AM_PARKING_TIRED:
return true;
case MLX5E_AM_GOING_RIGHT:
return (am->steps_left > 1) && (am->steps_right == 1);
default:
return (am->steps_right > 1) && (am->steps_left == 1);
}
}
static void mlx5e_am_turn(struct mlx5e_rx_am *am)
{
switch (am->tune_state) {
case MLX5E_AM_PARKING_ON_TOP:
case MLX5E_AM_PARKING_TIRED:
break;
case MLX5E_AM_GOING_RIGHT:
am->tune_state = MLX5E_AM_GOING_LEFT;
am->steps_left = 0;
break;
case MLX5E_AM_GOING_LEFT:
am->tune_state = MLX5E_AM_GOING_RIGHT;
am->steps_right = 0;
break;
}
}
static int mlx5e_am_step(struct mlx5e_rx_am *am)
{
if (am->tired == (MLX5E_PARAMS_AM_NUM_PROFILES * 2))
return MLX5E_AM_TOO_TIRED;
switch (am->tune_state) {
case MLX5E_AM_PARKING_ON_TOP:
case MLX5E_AM_PARKING_TIRED:
break;
case MLX5E_AM_GOING_RIGHT:
if (am->profile_ix == (MLX5E_PARAMS_AM_NUM_PROFILES - 1))
return MLX5E_AM_ON_EDGE;
am->profile_ix++;
am->steps_right++;
break;
case MLX5E_AM_GOING_LEFT:
if (am->profile_ix == 0)
return MLX5E_AM_ON_EDGE;
am->profile_ix--;
am->steps_left++;
break;
}
am->tired++;
return MLX5E_AM_STEPPED;
}
static void mlx5e_am_park_on_top(struct mlx5e_rx_am *am)
{
am->steps_right = 0;
am->steps_left = 0;
am->tired = 0;
am->tune_state = MLX5E_AM_PARKING_ON_TOP;
}
static void mlx5e_am_park_tired(struct mlx5e_rx_am *am)
{
am->steps_right = 0;
am->steps_left = 0;
am->tune_state = MLX5E_AM_PARKING_TIRED;
}
static void mlx5e_am_exit_parking(struct mlx5e_rx_am *am)
{
am->tune_state = am->profile_ix ? MLX5E_AM_GOING_LEFT :
MLX5E_AM_GOING_RIGHT;
mlx5e_am_step(am);
}
static int mlx5e_am_stats_compare(struct mlx5e_rx_am_stats *curr,
struct mlx5e_rx_am_stats *prev)
{
int diff;
if (!prev->ppms)
return curr->ppms ? MLX5E_AM_STATS_BETTER :
MLX5E_AM_STATS_SAME;
diff = curr->ppms - prev->ppms;
if (((100 * abs(diff)) / prev->ppms) > 10)
return (diff > 0) ? MLX5E_AM_STATS_BETTER :
MLX5E_AM_STATS_WORSE;
if (!prev->epms)
return curr->epms ? MLX5E_AM_STATS_WORSE :
MLX5E_AM_STATS_SAME;
diff = curr->epms - prev->epms;
if (((100 * abs(diff)) / prev->epms) > 10)
return (diff < 0) ? MLX5E_AM_STATS_BETTER :
MLX5E_AM_STATS_WORSE;
return MLX5E_AM_STATS_SAME;
}
static bool mlx5e_am_decision(struct mlx5e_rx_am_stats *curr_stats,
struct mlx5e_rx_am *am)
{
int prev_state = am->tune_state;
int prev_ix = am->profile_ix;
int stats_res;
int step_res;
switch (am->tune_state) {
case MLX5E_AM_PARKING_ON_TOP:
stats_res = mlx5e_am_stats_compare(curr_stats, &am->prev_stats);
if (stats_res != MLX5E_AM_STATS_SAME)
mlx5e_am_exit_parking(am);
break;
case MLX5E_AM_PARKING_TIRED:
am->tired--;
if (!am->tired)
mlx5e_am_exit_parking(am);
break;
case MLX5E_AM_GOING_RIGHT:
case MLX5E_AM_GOING_LEFT:
stats_res = mlx5e_am_stats_compare(curr_stats, &am->prev_stats);
if (stats_res != MLX5E_AM_STATS_BETTER)
mlx5e_am_turn(am);
if (mlx5e_am_on_top(am)) {
mlx5e_am_park_on_top(am);
break;
}
step_res = mlx5e_am_step(am);
switch (step_res) {
case MLX5E_AM_ON_EDGE:
mlx5e_am_park_on_top(am);
break;
case MLX5E_AM_TOO_TIRED:
mlx5e_am_park_tired(am);
break;
}
break;
}
if ((prev_state != MLX5E_AM_PARKING_ON_TOP) ||
(am->tune_state != MLX5E_AM_PARKING_ON_TOP))
am->prev_stats = *curr_stats;
return am->profile_ix != prev_ix;
}
static void mlx5e_am_sample(struct mlx5e_rq *rq,
struct mlx5e_rx_am_sample *s)
{
s->time = ktime_get();
s->pkt_ctr = rq->stats.packets;
s->event_ctr = rq->cq.event_ctr;
}
static void mlx5e_am_calc_stats(struct mlx5e_rx_am_sample *start,
struct mlx5e_rx_am_sample *end,
struct mlx5e_rx_am_stats *curr_stats)
{
u32 delta_us = ktime_us_delta(end->time, start->time);
unsigned int npkts = end->pkt_ctr - start->pkt_ctr;
if (!delta_us)
return;
curr_stats->ppms = (npkts * USEC_PER_MSEC) / delta_us;
curr_stats->epms = (MLX5E_AM_NEVENTS * USEC_PER_MSEC) / delta_us;
}
void mlx5e_rx_am_work(struct work_struct *work)
{
struct mlx5e_rx_am *am = container_of(work, struct mlx5e_rx_am,
work);
struct mlx5e_rq *rq = container_of(am, struct mlx5e_rq, am);
struct mlx5e_cq_moder cur_profile = profile[am->mode][am->profile_ix];
mlx5_core_modify_cq_moderation(rq->priv->mdev, &rq->cq.mcq,
cur_profile.usec, cur_profile.pkts);
am->state = MLX5E_AM_START_MEASURE;
}
void mlx5e_rx_am(struct mlx5e_rq *rq)
{
struct mlx5e_rx_am *am = &rq->am;
struct mlx5e_rx_am_sample end_sample;
struct mlx5e_rx_am_stats curr_stats;
u16 nevents;
switch (am->state) {
case MLX5E_AM_MEASURE_IN_PROGRESS:
nevents = rq->cq.event_ctr - am->start_sample.event_ctr;
if (nevents < MLX5E_AM_NEVENTS)
break;
mlx5e_am_sample(rq, &end_sample);
mlx5e_am_calc_stats(&am->start_sample, &end_sample,
&curr_stats);
if (mlx5e_am_decision(&curr_stats, am)) {
am->state = MLX5E_AM_APPLY_NEW_PROFILE;
schedule_work(&am->work);
break;
}
case MLX5E_AM_START_MEASURE:
mlx5e_am_sample(rq, &am->start_sample);
am->state = MLX5E_AM_MEASURE_IN_PROGRESS;
break;
case MLX5E_AM_APPLY_NEW_PROFILE:
break;
}
}
