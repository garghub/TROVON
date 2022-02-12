static u16
minstrel_get_valid_vht_rates(int bw, int nss, __le16 mcs_map)
{
u16 mask = 0;
if (bw == BW_20) {
if (nss != 3 && nss != 6)
mask = BIT(9);
} else if (bw == BW_80) {
if (nss == 3 || nss == 7)
mask = BIT(6);
else if (nss == 6)
mask = BIT(9);
} else {
WARN_ON(bw != BW_40);
}
switch ((le16_to_cpu(mcs_map) >> (2 * (nss - 1))) & 3) {
case IEEE80211_VHT_MCS_SUPPORT_0_7:
mask |= 0x300;
break;
case IEEE80211_VHT_MCS_SUPPORT_0_8:
mask |= 0x200;
break;
case IEEE80211_VHT_MCS_SUPPORT_0_9:
break;
default:
mask = 0x3ff;
}
return 0x3ff & ~mask;
}
static int
minstrel_ht_get_group_idx(struct ieee80211_tx_rate *rate)
{
return GROUP_IDX((rate->idx / 8) + 1,
!!(rate->flags & IEEE80211_TX_RC_SHORT_GI),
!!(rate->flags & IEEE80211_TX_RC_40_MHZ_WIDTH));
}
static int
minstrel_vht_get_group_idx(struct ieee80211_tx_rate *rate)
{
return VHT_GROUP_IDX(ieee80211_rate_get_vht_nss(rate),
!!(rate->flags & IEEE80211_TX_RC_SHORT_GI),
!!(rate->flags & IEEE80211_TX_RC_40_MHZ_WIDTH) +
2*!!(rate->flags & IEEE80211_TX_RC_80_MHZ_WIDTH));
}
static struct minstrel_rate_stats *
minstrel_ht_get_stats(struct minstrel_priv *mp, struct minstrel_ht_sta *mi,
struct ieee80211_tx_rate *rate)
{
int group, idx;
if (rate->flags & IEEE80211_TX_RC_MCS) {
group = minstrel_ht_get_group_idx(rate);
idx = rate->idx % 8;
} else if (rate->flags & IEEE80211_TX_RC_VHT_MCS) {
group = minstrel_vht_get_group_idx(rate);
idx = ieee80211_rate_get_vht_mcs(rate);
} else {
group = MINSTREL_CCK_GROUP;
for (idx = 0; idx < ARRAY_SIZE(mp->cck_rates); idx++)
if (rate->idx == mp->cck_rates[idx])
break;
if (!(mi->supported[group] & BIT(idx)))
idx += 4;
}
return &mi->groups[group].rates[idx];
}
static inline struct minstrel_rate_stats *
minstrel_get_ratestats(struct minstrel_ht_sta *mi, int index)
{
return &mi->groups[index / MCS_GROUP_RATES].rates[index % MCS_GROUP_RATES];
}
int
minstrel_ht_get_tp_avg(struct minstrel_ht_sta *mi, int group, int rate,
int prob_ewma)
{
unsigned int nsecs = 0;
if (prob_ewma < MINSTREL_FRAC(10, 100))
return 0;
if (group != MINSTREL_CCK_GROUP)
nsecs = 1000 * mi->overhead / MINSTREL_TRUNC(mi->avg_ampdu_len);
nsecs += minstrel_mcs_groups[group].duration[rate];
if (prob_ewma > MINSTREL_FRAC(90, 100))
return MINSTREL_TRUNC(100000 * ((MINSTREL_FRAC(90, 100) * 1000)
/ nsecs));
else
return MINSTREL_TRUNC(100000 * ((prob_ewma * 1000) / nsecs));
}
static void
minstrel_ht_sort_best_tp_rates(struct minstrel_ht_sta *mi, u16 index,
u16 *tp_list)
{
int cur_group, cur_idx, cur_tp_avg, cur_prob;
int tmp_group, tmp_idx, tmp_tp_avg, tmp_prob;
int j = MAX_THR_RATES;
cur_group = index / MCS_GROUP_RATES;
cur_idx = index % MCS_GROUP_RATES;
cur_prob = mi->groups[cur_group].rates[cur_idx].prob_ewma;
cur_tp_avg = minstrel_ht_get_tp_avg(mi, cur_group, cur_idx, cur_prob);
do {
tmp_group = tp_list[j - 1] / MCS_GROUP_RATES;
tmp_idx = tp_list[j - 1] % MCS_GROUP_RATES;
tmp_prob = mi->groups[tmp_group].rates[tmp_idx].prob_ewma;
tmp_tp_avg = minstrel_ht_get_tp_avg(mi, tmp_group, tmp_idx,
tmp_prob);
if (cur_tp_avg < tmp_tp_avg ||
(cur_tp_avg == tmp_tp_avg && cur_prob <= tmp_prob))
break;
j--;
} while (j > 0);
if (j < MAX_THR_RATES - 1) {
memmove(&tp_list[j + 1], &tp_list[j], (sizeof(*tp_list) *
(MAX_THR_RATES - (j + 1))));
}
if (j < MAX_THR_RATES)
tp_list[j] = index;
}
static void
minstrel_ht_set_best_prob_rate(struct minstrel_ht_sta *mi, u16 index)
{
struct minstrel_mcs_group_data *mg;
struct minstrel_rate_stats *mrs;
int tmp_group, tmp_idx, tmp_tp_avg, tmp_prob;
int max_tp_group, cur_tp_avg, cur_group, cur_idx;
int max_gpr_group, max_gpr_idx;
int max_gpr_tp_avg, max_gpr_prob;
cur_group = index / MCS_GROUP_RATES;
cur_idx = index % MCS_GROUP_RATES;
mg = &mi->groups[index / MCS_GROUP_RATES];
mrs = &mg->rates[index % MCS_GROUP_RATES];
tmp_group = mi->max_prob_rate / MCS_GROUP_RATES;
tmp_idx = mi->max_prob_rate % MCS_GROUP_RATES;
tmp_prob = mi->groups[tmp_group].rates[tmp_idx].prob_ewma;
tmp_tp_avg = minstrel_ht_get_tp_avg(mi, tmp_group, tmp_idx, tmp_prob);
max_tp_group = mi->max_tp_rate[0] / MCS_GROUP_RATES;
if((index / MCS_GROUP_RATES == MINSTREL_CCK_GROUP) &&
(max_tp_group != MINSTREL_CCK_GROUP))
return;
max_gpr_group = mg->max_group_prob_rate / MCS_GROUP_RATES;
max_gpr_idx = mg->max_group_prob_rate % MCS_GROUP_RATES;
max_gpr_prob = mi->groups[max_gpr_group].rates[max_gpr_idx].prob_ewma;
if (mrs->prob_ewma > MINSTREL_FRAC(75, 100)) {
cur_tp_avg = minstrel_ht_get_tp_avg(mi, cur_group, cur_idx,
mrs->prob_ewma);
if (cur_tp_avg > tmp_tp_avg)
mi->max_prob_rate = index;
max_gpr_tp_avg = minstrel_ht_get_tp_avg(mi, max_gpr_group,
max_gpr_idx,
max_gpr_prob);
if (cur_tp_avg > max_gpr_tp_avg)
mg->max_group_prob_rate = index;
} else {
if (mrs->prob_ewma > tmp_prob)
mi->max_prob_rate = index;
if (mrs->prob_ewma > max_gpr_prob)
mg->max_group_prob_rate = index;
}
}
static void
minstrel_ht_assign_best_tp_rates(struct minstrel_ht_sta *mi,
u16 tmp_mcs_tp_rate[MAX_THR_RATES],
u16 tmp_cck_tp_rate[MAX_THR_RATES])
{
unsigned int tmp_group, tmp_idx, tmp_cck_tp, tmp_mcs_tp, tmp_prob;
int i;
tmp_group = tmp_cck_tp_rate[0] / MCS_GROUP_RATES;
tmp_idx = tmp_cck_tp_rate[0] % MCS_GROUP_RATES;
tmp_prob = mi->groups[tmp_group].rates[tmp_idx].prob_ewma;
tmp_cck_tp = minstrel_ht_get_tp_avg(mi, tmp_group, tmp_idx, tmp_prob);
tmp_group = tmp_mcs_tp_rate[0] / MCS_GROUP_RATES;
tmp_idx = tmp_mcs_tp_rate[0] % MCS_GROUP_RATES;
tmp_prob = mi->groups[tmp_group].rates[tmp_idx].prob_ewma;
tmp_mcs_tp = minstrel_ht_get_tp_avg(mi, tmp_group, tmp_idx, tmp_prob);
if (tmp_cck_tp > tmp_mcs_tp) {
for(i = 0; i < MAX_THR_RATES; i++) {
minstrel_ht_sort_best_tp_rates(mi, tmp_cck_tp_rate[i],
tmp_mcs_tp_rate);
}
}
}
static inline void
minstrel_ht_prob_rate_reduce_streams(struct minstrel_ht_sta *mi)
{
struct minstrel_mcs_group_data *mg;
int tmp_max_streams, group, tmp_idx, tmp_prob;
int tmp_tp = 0;
tmp_max_streams = minstrel_mcs_groups[mi->max_tp_rate[0] /
MCS_GROUP_RATES].streams;
for (group = 0; group < ARRAY_SIZE(minstrel_mcs_groups); group++) {
mg = &mi->groups[group];
if (!mi->supported[group] || group == MINSTREL_CCK_GROUP)
continue;
tmp_idx = mg->max_group_prob_rate % MCS_GROUP_RATES;
tmp_prob = mi->groups[group].rates[tmp_idx].prob_ewma;
if (tmp_tp < minstrel_ht_get_tp_avg(mi, group, tmp_idx, tmp_prob) &&
(minstrel_mcs_groups[group].streams < tmp_max_streams)) {
mi->max_prob_rate = mg->max_group_prob_rate;
tmp_tp = minstrel_ht_get_tp_avg(mi, group,
tmp_idx,
tmp_prob);
}
}
}
static void
minstrel_ht_update_stats(struct minstrel_priv *mp, struct minstrel_ht_sta *mi)
{
struct minstrel_mcs_group_data *mg;
struct minstrel_rate_stats *mrs;
int group, i, j, cur_prob;
u16 tmp_mcs_tp_rate[MAX_THR_RATES], tmp_group_tp_rate[MAX_THR_RATES];
u16 tmp_cck_tp_rate[MAX_THR_RATES], index;
if (mi->ampdu_packets > 0) {
mi->avg_ampdu_len = minstrel_ewma(mi->avg_ampdu_len,
MINSTREL_FRAC(mi->ampdu_len, mi->ampdu_packets), EWMA_LEVEL);
mi->ampdu_len = 0;
mi->ampdu_packets = 0;
}
mi->sample_slow = 0;
mi->sample_count = 0;
for(j = 0; j < MAX_THR_RATES; j++){
tmp_mcs_tp_rate[j] = 0;
tmp_cck_tp_rate[j] = 0;
}
for (group = 0; group < ARRAY_SIZE(minstrel_mcs_groups); group++) {
mg = &mi->groups[group];
if (!mi->supported[group])
continue;
mi->sample_count++;
for(j = 0; j < MAX_THR_RATES; j++)
tmp_group_tp_rate[j] = group;
for (i = 0; i < MCS_GROUP_RATES; i++) {
if (!(mi->supported[group] & BIT(i)))
continue;
index = MCS_GROUP_RATES * group + i;
mrs = &mg->rates[i];
mrs->retry_updated = false;
minstrel_calc_rate_stats(mrs);
cur_prob = mrs->prob_ewma;
if (minstrel_ht_get_tp_avg(mi, group, i, cur_prob) == 0)
continue;
if (group != MINSTREL_CCK_GROUP) {
minstrel_ht_sort_best_tp_rates(mi, index,
tmp_mcs_tp_rate);
} else if (group == MINSTREL_CCK_GROUP) {
minstrel_ht_sort_best_tp_rates(mi, index,
tmp_cck_tp_rate);
}
minstrel_ht_sort_best_tp_rates(mi, index,
tmp_group_tp_rate);
minstrel_ht_set_best_prob_rate(mi, index);
}
memcpy(mg->max_group_tp_rate, tmp_group_tp_rate,
sizeof(mg->max_group_tp_rate));
}
minstrel_ht_assign_best_tp_rates(mi, tmp_mcs_tp_rate, tmp_cck_tp_rate);
memcpy(mi->max_tp_rate, tmp_mcs_tp_rate, sizeof(mi->max_tp_rate));
minstrel_ht_prob_rate_reduce_streams(mi);
mi->sample_count *= 8;
#ifdef CONFIG_MAC80211_DEBUGFS
if (mp->fixed_rate_idx != -1) {
for (i = 0; i < 4; i++)
mi->max_tp_rate[i] = mp->fixed_rate_idx;
mi->max_prob_rate = mp->fixed_rate_idx;
}
#endif
mi->last_stats_update = jiffies;
}
static bool
minstrel_ht_txstat_valid(struct minstrel_priv *mp, struct ieee80211_tx_rate *rate)
{
if (rate->idx < 0)
return false;
if (!rate->count)
return false;
if (rate->flags & IEEE80211_TX_RC_MCS ||
rate->flags & IEEE80211_TX_RC_VHT_MCS)
return true;
return rate->idx == mp->cck_rates[0] ||
rate->idx == mp->cck_rates[1] ||
rate->idx == mp->cck_rates[2] ||
rate->idx == mp->cck_rates[3];
}
static void
minstrel_set_next_sample_idx(struct minstrel_ht_sta *mi)
{
struct minstrel_mcs_group_data *mg;
for (;;) {
mi->sample_group++;
mi->sample_group %= ARRAY_SIZE(minstrel_mcs_groups);
mg = &mi->groups[mi->sample_group];
if (!mi->supported[mi->sample_group])
continue;
if (++mg->index >= MCS_GROUP_RATES) {
mg->index = 0;
if (++mg->column >= ARRAY_SIZE(sample_table))
mg->column = 0;
}
break;
}
}
static void
minstrel_downgrade_rate(struct minstrel_ht_sta *mi, u16 *idx, bool primary)
{
int group, orig_group;
orig_group = group = *idx / MCS_GROUP_RATES;
while (group > 0) {
group--;
if (!mi->supported[group])
continue;
if (minstrel_mcs_groups[group].streams >
minstrel_mcs_groups[orig_group].streams)
continue;
if (primary)
*idx = mi->groups[group].max_group_tp_rate[0];
else
*idx = mi->groups[group].max_group_tp_rate[1];
break;
}
}
static void
minstrel_aggr_check(struct ieee80211_sta *pubsta, struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
u16 tid;
if (skb_get_queue_mapping(skb) == IEEE80211_AC_VO)
return;
if (unlikely(!ieee80211_is_data_qos(hdr->frame_control)))
return;
if (unlikely(skb->protocol == cpu_to_be16(ETH_P_PAE)))
return;
tid = *ieee80211_get_qos_ctl(hdr) & IEEE80211_QOS_CTL_TID_MASK;
if (likely(sta->ampdu_mlme.tid_tx[tid]))
return;
ieee80211_start_tx_ba_session(pubsta, tid, 0);
}
static void
minstrel_ht_tx_status(void *priv, struct ieee80211_supported_band *sband,
void *priv_sta, struct ieee80211_tx_status *st)
{
struct ieee80211_tx_info *info = st->info;
struct minstrel_ht_sta_priv *msp = priv_sta;
struct minstrel_ht_sta *mi = &msp->ht;
struct ieee80211_tx_rate *ar = info->status.rates;
struct minstrel_rate_stats *rate, *rate2;
struct minstrel_priv *mp = priv;
bool last, update = false;
int i;
if (!msp->is_ht)
return mac80211_minstrel.tx_status_ext(priv, sband,
&msp->legacy, st);
if ((info->flags & IEEE80211_TX_CTL_AMPDU) &&
!(info->flags & IEEE80211_TX_STAT_AMPDU))
return;
if (!(info->flags & IEEE80211_TX_STAT_AMPDU)) {
info->status.ampdu_ack_len =
(info->flags & IEEE80211_TX_STAT_ACK ? 1 : 0);
info->status.ampdu_len = 1;
}
mi->ampdu_packets++;
mi->ampdu_len += info->status.ampdu_len;
if (!mi->sample_wait && !mi->sample_tries && mi->sample_count > 0) {
mi->sample_wait = 16 + 2 * MINSTREL_TRUNC(mi->avg_ampdu_len);
mi->sample_tries = 1;
mi->sample_count--;
}
if (info->flags & IEEE80211_TX_CTL_RATE_CTRL_PROBE)
mi->sample_packets += info->status.ampdu_len;
last = !minstrel_ht_txstat_valid(mp, &ar[0]);
for (i = 0; !last; i++) {
last = (i == IEEE80211_TX_MAX_RATES - 1) ||
!minstrel_ht_txstat_valid(mp, &ar[i + 1]);
rate = minstrel_ht_get_stats(mp, mi, &ar[i]);
if (last)
rate->success += info->status.ampdu_ack_len;
rate->attempts += ar[i].count * info->status.ampdu_len;
}
rate = minstrel_get_ratestats(mi, mi->max_tp_rate[0]);
if (rate->attempts > 30 &&
MINSTREL_FRAC(rate->success, rate->attempts) <
MINSTREL_FRAC(20, 100)) {
minstrel_downgrade_rate(mi, &mi->max_tp_rate[0], true);
update = true;
}
rate2 = minstrel_get_ratestats(mi, mi->max_tp_rate[1]);
if (rate2->attempts > 30 &&
MINSTREL_FRAC(rate2->success, rate2->attempts) <
MINSTREL_FRAC(20, 100)) {
minstrel_downgrade_rate(mi, &mi->max_tp_rate[1], false);
update = true;
}
if (time_after(jiffies, mi->last_stats_update +
(mp->update_interval / 2 * HZ) / 1000)) {
update = true;
minstrel_ht_update_stats(mp, mi);
}
if (update)
minstrel_ht_update_rates(mp, mi);
}
static void
minstrel_calc_retransmit(struct minstrel_priv *mp, struct minstrel_ht_sta *mi,
int index)
{
struct minstrel_rate_stats *mrs;
const struct mcs_group *group;
unsigned int tx_time, tx_time_rtscts, tx_time_data;
unsigned int cw = mp->cw_min;
unsigned int ctime = 0;
unsigned int t_slot = 9;
unsigned int ampdu_len = MINSTREL_TRUNC(mi->avg_ampdu_len);
unsigned int overhead = 0, overhead_rtscts = 0;
mrs = minstrel_get_ratestats(mi, index);
if (mrs->prob_ewma < MINSTREL_FRAC(1, 10)) {
mrs->retry_count = 1;
mrs->retry_count_rtscts = 1;
return;
}
mrs->retry_count = 2;
mrs->retry_count_rtscts = 2;
mrs->retry_updated = true;
group = &minstrel_mcs_groups[index / MCS_GROUP_RATES];
tx_time_data = group->duration[index % MCS_GROUP_RATES] * ampdu_len / 1000;
ctime = (t_slot * cw) >> 1;
cw = min((cw << 1) | 1, mp->cw_max);
ctime += (t_slot * cw) >> 1;
cw = min((cw << 1) | 1, mp->cw_max);
if (index / MCS_GROUP_RATES != MINSTREL_CCK_GROUP) {
overhead = mi->overhead;
overhead_rtscts = mi->overhead_rtscts;
}
tx_time = ctime + 2 * (overhead + tx_time_data);
tx_time_rtscts = ctime + 2 * (overhead_rtscts + tx_time_data);
do {
ctime = (t_slot * cw) >> 1;
cw = min((cw << 1) | 1, mp->cw_max);
tx_time += ctime + overhead + tx_time_data;
tx_time_rtscts += ctime + overhead_rtscts + tx_time_data;
if (tx_time_rtscts < mp->segment_size)
mrs->retry_count_rtscts++;
} while ((tx_time < mp->segment_size) &&
(++mrs->retry_count < mp->max_retry));
}
static void
minstrel_ht_set_rate(struct minstrel_priv *mp, struct minstrel_ht_sta *mi,
struct ieee80211_sta_rates *ratetbl, int offset, int index)
{
const struct mcs_group *group = &minstrel_mcs_groups[index / MCS_GROUP_RATES];
struct minstrel_rate_stats *mrs;
u8 idx;
u16 flags = group->flags;
mrs = minstrel_get_ratestats(mi, index);
if (!mrs->retry_updated)
minstrel_calc_retransmit(mp, mi, index);
if (mrs->prob_ewma < MINSTREL_FRAC(20, 100) || !mrs->retry_count) {
ratetbl->rate[offset].count = 2;
ratetbl->rate[offset].count_rts = 2;
ratetbl->rate[offset].count_cts = 2;
} else {
ratetbl->rate[offset].count = mrs->retry_count;
ratetbl->rate[offset].count_cts = mrs->retry_count;
ratetbl->rate[offset].count_rts = mrs->retry_count_rtscts;
}
if (index / MCS_GROUP_RATES == MINSTREL_CCK_GROUP)
idx = mp->cck_rates[index % ARRAY_SIZE(mp->cck_rates)];
else if (flags & IEEE80211_TX_RC_VHT_MCS)
idx = ((group->streams - 1) << 4) |
((index % MCS_GROUP_RATES) & 0xF);
else
idx = index % MCS_GROUP_RATES + (group->streams - 1) * 8;
if (offset > 0 ||
(mi->sta->smps_mode == IEEE80211_SMPS_DYNAMIC &&
group->streams > 1)) {
ratetbl->rate[offset].count = ratetbl->rate[offset].count_rts;
flags |= IEEE80211_TX_RC_USE_RTS_CTS;
}
ratetbl->rate[offset].idx = idx;
ratetbl->rate[offset].flags = flags;
}
static inline int
minstrel_ht_get_prob_ewma(struct minstrel_ht_sta *mi, int rate)
{
int group = rate / MCS_GROUP_RATES;
rate %= MCS_GROUP_RATES;
return mi->groups[group].rates[rate].prob_ewma;
}
static int
minstrel_ht_get_max_amsdu_len(struct minstrel_ht_sta *mi)
{
int group = mi->max_prob_rate / MCS_GROUP_RATES;
const struct mcs_group *g = &minstrel_mcs_groups[group];
int rate = mi->max_prob_rate % MCS_GROUP_RATES;
if (mi->groups[group].rates[rate].prob_ewma < MINSTREL_FRAC(50, 100))
return 1;
if (g->duration[rate] > MCS_DURATION(1, 0, 52))
return 500;
if (g->duration[rate] > MCS_DURATION(1, 0, 104))
return 1600;
if (g->duration[rate] > MCS_DURATION(1, 0, 260) ||
(minstrel_ht_get_prob_ewma(mi, mi->max_tp_rate[0]) <
MINSTREL_FRAC(75, 100)))
return 3200;
if (!mi->sta->vht_cap.vht_supported)
return IEEE80211_MAX_MPDU_LEN_HT_BA;
return 0;
}
static void
minstrel_ht_update_rates(struct minstrel_priv *mp, struct minstrel_ht_sta *mi)
{
struct ieee80211_sta_rates *rates;
int i = 0;
rates = kzalloc(sizeof(*rates), GFP_ATOMIC);
if (!rates)
return;
minstrel_ht_set_rate(mp, mi, rates, i++, mi->max_tp_rate[0]);
if (mp->hw->max_rates >= 3) {
minstrel_ht_set_rate(mp, mi, rates, i++, mi->max_tp_rate[1]);
}
if (mp->hw->max_rates >= 2) {
minstrel_ht_set_rate(mp, mi, rates, i++, mi->max_prob_rate);
}
mi->sta->max_rc_amsdu_len = minstrel_ht_get_max_amsdu_len(mi);
rates->rate[i].idx = -1;
rate_control_set_rates(mp->hw, mi->sta, rates);
}
static inline int
minstrel_get_duration(int index)
{
const struct mcs_group *group = &minstrel_mcs_groups[index / MCS_GROUP_RATES];
return group->duration[index % MCS_GROUP_RATES];
}
static int
minstrel_get_sample_rate(struct minstrel_priv *mp, struct minstrel_ht_sta *mi)
{
struct minstrel_rate_stats *mrs;
struct minstrel_mcs_group_data *mg;
unsigned int sample_dur, sample_group, cur_max_tp_streams;
int tp_rate1, tp_rate2;
int sample_idx = 0;
if (mi->sample_wait > 0) {
mi->sample_wait--;
return -1;
}
if (!mi->sample_tries)
return -1;
sample_group = mi->sample_group;
mg = &mi->groups[sample_group];
sample_idx = sample_table[mg->column][mg->index];
minstrel_set_next_sample_idx(mi);
if (!(mi->supported[sample_group] & BIT(sample_idx)))
return -1;
mrs = &mg->rates[sample_idx];
sample_idx += sample_group * MCS_GROUP_RATES;
if (minstrel_get_duration(mi->max_tp_rate[0]) >
minstrel_get_duration(mi->max_tp_rate[1])) {
tp_rate1 = mi->max_tp_rate[1];
tp_rate2 = mi->max_tp_rate[0];
} else {
tp_rate1 = mi->max_tp_rate[0];
tp_rate2 = mi->max_tp_rate[1];
}
if (sample_idx == mi->max_tp_rate[0] || sample_idx == mi->max_prob_rate)
return -1;
if (mrs->prob_ewma > MINSTREL_FRAC(95, 100))
return -1;
cur_max_tp_streams = minstrel_mcs_groups[tp_rate1 /
MCS_GROUP_RATES].streams;
sample_dur = minstrel_get_duration(sample_idx);
if (sample_dur >= minstrel_get_duration(tp_rate2) &&
(cur_max_tp_streams - 1 <
minstrel_mcs_groups[sample_group].streams ||
sample_dur >= minstrel_get_duration(mi->max_prob_rate))) {
if (mrs->sample_skipped < 20)
return -1;
if (mi->sample_slow++ > 2)
return -1;
}
mi->sample_tries--;
return sample_idx;
}
static void
minstrel_ht_get_rate(void *priv, struct ieee80211_sta *sta, void *priv_sta,
struct ieee80211_tx_rate_control *txrc)
{
const struct mcs_group *sample_group;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(txrc->skb);
struct ieee80211_tx_rate *rate = &info->status.rates[0];
struct minstrel_ht_sta_priv *msp = priv_sta;
struct minstrel_ht_sta *mi = &msp->ht;
struct minstrel_priv *mp = priv;
int sample_idx;
if (rate_control_send_low(sta, priv_sta, txrc))
return;
if (!msp->is_ht)
return mac80211_minstrel.get_rate(priv, sta, &msp->legacy, txrc);
if (!(info->flags & IEEE80211_TX_CTL_AMPDU) &&
mi->max_prob_rate / MCS_GROUP_RATES != MINSTREL_CCK_GROUP)
minstrel_aggr_check(sta, txrc->skb);
info->flags |= mi->tx_flags;
#ifdef CONFIG_MAC80211_DEBUGFS
if (mp->fixed_rate_idx != -1)
return;
#endif
if (mp->hw->max_rates == 1 &&
(info->control.flags & IEEE80211_TX_CTRL_PORT_CTRL_PROTO))
sample_idx = -1;
else
sample_idx = minstrel_get_sample_rate(mp, mi);
mi->total_packets++;
if (mi->total_packets == ~0) {
mi->total_packets = 0;
mi->sample_packets = 0;
}
if (sample_idx < 0)
return;
sample_group = &minstrel_mcs_groups[sample_idx / MCS_GROUP_RATES];
info->flags |= IEEE80211_TX_CTL_RATE_CTRL_PROBE;
rate->count = 1;
if (sample_idx / MCS_GROUP_RATES == MINSTREL_CCK_GROUP) {
int idx = sample_idx % ARRAY_SIZE(mp->cck_rates);
rate->idx = mp->cck_rates[idx];
} else if (sample_group->flags & IEEE80211_TX_RC_VHT_MCS) {
ieee80211_rate_set_vht(rate, sample_idx % MCS_GROUP_RATES,
sample_group->streams);
} else {
rate->idx = sample_idx % MCS_GROUP_RATES +
(sample_group->streams - 1) * 8;
}
rate->flags = sample_group->flags;
}
static void
minstrel_ht_update_cck(struct minstrel_priv *mp, struct minstrel_ht_sta *mi,
struct ieee80211_supported_band *sband,
struct ieee80211_sta *sta)
{
int i;
if (sband->band != NL80211_BAND_2GHZ)
return;
if (!ieee80211_hw_check(mp->hw, SUPPORTS_HT_CCK_RATES))
return;
mi->cck_supported = 0;
mi->cck_supported_short = 0;
for (i = 0; i < 4; i++) {
if (!rate_supported(sta, sband->band, mp->cck_rates[i]))
continue;
mi->cck_supported |= BIT(i);
if (sband->bitrates[i].flags & IEEE80211_RATE_SHORT_PREAMBLE)
mi->cck_supported_short |= BIT(i);
}
mi->supported[MINSTREL_CCK_GROUP] = mi->cck_supported;
}
static void
minstrel_ht_update_caps(void *priv, struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *priv_sta)
{
struct minstrel_priv *mp = priv;
struct minstrel_ht_sta_priv *msp = priv_sta;
struct minstrel_ht_sta *mi = &msp->ht;
struct ieee80211_mcs_info *mcs = &sta->ht_cap.mcs;
u16 sta_cap = sta->ht_cap.cap;
struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
struct sta_info *sinfo = container_of(sta, struct sta_info, sta);
int use_vht;
int n_supported = 0;
int ack_dur;
int stbc;
int i;
if (!sta->ht_cap.ht_supported)
goto use_legacy;
BUILD_BUG_ON(ARRAY_SIZE(minstrel_mcs_groups) != MINSTREL_GROUPS_NB);
#ifdef CONFIG_MAC80211_RC_MINSTREL_VHT
if (vht_cap->vht_supported)
use_vht = vht_cap->vht_mcs.tx_mcs_map != cpu_to_le16(~0);
else
#endif
use_vht = 0;
msp->is_ht = true;
memset(mi, 0, sizeof(*mi));
mi->sta = sta;
mi->last_stats_update = jiffies;
ack_dur = ieee80211_frame_duration(sband->band, 10, 60, 1, 1, 0);
mi->overhead = ieee80211_frame_duration(sband->band, 0, 60, 1, 1, 0);
mi->overhead += ack_dur;
mi->overhead_rtscts = mi->overhead + 2 * ack_dur;
mi->avg_ampdu_len = MINSTREL_FRAC(1, 1);
if (mp->has_mrr) {
mi->sample_count = 16;
mi->sample_wait = 0;
} else {
mi->sample_count = 8;
mi->sample_wait = 8;
}
mi->sample_tries = 4;
if (!use_vht) {
stbc = (sta_cap & IEEE80211_HT_CAP_RX_STBC) >>
IEEE80211_HT_CAP_RX_STBC_SHIFT;
mi->tx_flags |= stbc << IEEE80211_TX_CTL_STBC_SHIFT;
if (sta_cap & IEEE80211_HT_CAP_LDPC_CODING)
mi->tx_flags |= IEEE80211_TX_CTL_LDPC;
}
for (i = 0; i < ARRAY_SIZE(mi->groups); i++) {
u32 gflags = minstrel_mcs_groups[i].flags;
int bw, nss;
mi->supported[i] = 0;
if (i == MINSTREL_CCK_GROUP) {
minstrel_ht_update_cck(mp, mi, sband, sta);
continue;
}
if (gflags & IEEE80211_TX_RC_SHORT_GI) {
if (gflags & IEEE80211_TX_RC_40_MHZ_WIDTH) {
if (!(sta_cap & IEEE80211_HT_CAP_SGI_40))
continue;
} else {
if (!(sta_cap & IEEE80211_HT_CAP_SGI_20))
continue;
}
}
if (gflags & IEEE80211_TX_RC_40_MHZ_WIDTH &&
sta->bandwidth < IEEE80211_STA_RX_BW_40)
continue;
nss = minstrel_mcs_groups[i].streams;
if (sta->smps_mode == IEEE80211_SMPS_STATIC && nss > 1)
continue;
if (gflags & IEEE80211_TX_RC_MCS) {
#ifdef CONFIG_MAC80211_RC_MINSTREL_VHT
if (use_vht && minstrel_vht_only)
continue;
#endif
mi->supported[i] = mcs->rx_mask[nss - 1];
if (mi->supported[i])
n_supported++;
continue;
}
if (!vht_cap->vht_supported ||
WARN_ON(!(gflags & IEEE80211_TX_RC_VHT_MCS)) ||
WARN_ON(gflags & IEEE80211_TX_RC_160_MHZ_WIDTH))
continue;
if (gflags & IEEE80211_TX_RC_80_MHZ_WIDTH) {
if (sta->bandwidth < IEEE80211_STA_RX_BW_80 ||
((gflags & IEEE80211_TX_RC_SHORT_GI) &&
!(vht_cap->cap & IEEE80211_VHT_CAP_SHORT_GI_80))) {
continue;
}
}
if (gflags & IEEE80211_TX_RC_40_MHZ_WIDTH)
bw = BW_40;
else if (gflags & IEEE80211_TX_RC_80_MHZ_WIDTH)
bw = BW_80;
else
bw = BW_20;
mi->supported[i] = minstrel_get_valid_vht_rates(bw, nss,
vht_cap->vht_mcs.tx_mcs_map);
if (mi->supported[i])
n_supported++;
}
if (!n_supported)
goto use_legacy;
if (test_sta_flag(sinfo, WLAN_STA_SHORT_PREAMBLE))
mi->cck_supported_short |= mi->cck_supported_short << 4;
minstrel_ht_update_stats(mp, mi);
minstrel_ht_update_rates(mp, mi);
return;
use_legacy:
msp->is_ht = false;
memset(&msp->legacy, 0, sizeof(msp->legacy));
msp->legacy.r = msp->ratelist;
msp->legacy.sample_table = msp->sample_table;
return mac80211_minstrel.rate_init(priv, sband, chandef, sta,
&msp->legacy);
}
static void
minstrel_ht_rate_init(void *priv, struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *priv_sta)
{
minstrel_ht_update_caps(priv, sband, chandef, sta, priv_sta);
}
static void
minstrel_ht_rate_update(void *priv, struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *priv_sta,
u32 changed)
{
minstrel_ht_update_caps(priv, sband, chandef, sta, priv_sta);
}
static void *
minstrel_ht_alloc_sta(void *priv, struct ieee80211_sta *sta, gfp_t gfp)
{
struct ieee80211_supported_band *sband;
struct minstrel_ht_sta_priv *msp;
struct minstrel_priv *mp = priv;
struct ieee80211_hw *hw = mp->hw;
int max_rates = 0;
int i;
for (i = 0; i < NUM_NL80211_BANDS; i++) {
sband = hw->wiphy->bands[i];
if (sband && sband->n_bitrates > max_rates)
max_rates = sband->n_bitrates;
}
msp = kzalloc(sizeof(*msp), gfp);
if (!msp)
return NULL;
msp->ratelist = kzalloc(sizeof(struct minstrel_rate) * max_rates, gfp);
if (!msp->ratelist)
goto error;
msp->sample_table = kmalloc(SAMPLE_COLUMNS * max_rates, gfp);
if (!msp->sample_table)
goto error1;
return msp;
error1:
kfree(msp->ratelist);
error:
kfree(msp);
return NULL;
}
static void
minstrel_ht_free_sta(void *priv, struct ieee80211_sta *sta, void *priv_sta)
{
struct minstrel_ht_sta_priv *msp = priv_sta;
kfree(msp->sample_table);
kfree(msp->ratelist);
kfree(msp);
}
static void *
minstrel_ht_alloc(struct ieee80211_hw *hw, struct dentry *debugfsdir)
{
return mac80211_minstrel.alloc(hw, debugfsdir);
}
static void
minstrel_ht_free(void *priv)
{
mac80211_minstrel.free(priv);
}
static u32 minstrel_ht_get_expected_throughput(void *priv_sta)
{
struct minstrel_ht_sta_priv *msp = priv_sta;
struct minstrel_ht_sta *mi = &msp->ht;
int i, j, prob, tp_avg;
if (!msp->is_ht)
return mac80211_minstrel.get_expected_throughput(priv_sta);
i = mi->max_tp_rate[0] / MCS_GROUP_RATES;
j = mi->max_tp_rate[0] % MCS_GROUP_RATES;
prob = mi->groups[i].rates[j].prob_ewma;
tp_avg = minstrel_ht_get_tp_avg(mi, i, j, prob) * 10;
tp_avg = tp_avg * AVG_PKT_SIZE * 8 / 1024;
return tp_avg;
}
static void __init init_sample_table(void)
{
int col, i, new_idx;
u8 rnd[MCS_GROUP_RATES];
memset(sample_table, 0xff, sizeof(sample_table));
for (col = 0; col < SAMPLE_COLUMNS; col++) {
prandom_bytes(rnd, sizeof(rnd));
for (i = 0; i < MCS_GROUP_RATES; i++) {
new_idx = (i + rnd[i]) % MCS_GROUP_RATES;
while (sample_table[col][new_idx] != 0xff)
new_idx = (new_idx + 1) % MCS_GROUP_RATES;
sample_table[col][new_idx] = i;
}
}
}
int __init
rc80211_minstrel_ht_init(void)
{
init_sample_table();
return ieee80211_rate_control_register(&mac80211_minstrel_ht);
}
void
rc80211_minstrel_ht_exit(void)
{
ieee80211_rate_control_unregister(&mac80211_minstrel_ht);
}
