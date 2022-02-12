static bool rs_ant_allow(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
struct rs_rate *rate,
const struct rs_tx_column *next_col)
{
return iwl_mvm_bt_coex_is_ant_avail(mvm, next_col->ant);
}
static bool rs_mimo_allow(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
struct rs_rate *rate,
const struct rs_tx_column *next_col)
{
struct iwl_mvm_sta *mvmsta;
struct iwl_mvm_vif *mvmvif;
if (!sta->ht_cap.ht_supported)
return false;
if (sta->smps_mode == IEEE80211_SMPS_STATIC)
return false;
if (num_of_ant(iwl_mvm_get_valid_tx_ant(mvm)) < 2)
return false;
if (!iwl_mvm_bt_coex_is_mimo_allowed(mvm, sta))
return false;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
mvmvif = iwl_mvm_vif_from_mac80211(mvmsta->vif);
if (IWL_MVM_RS_DISABLE_P2P_MIMO &&
iwl_mvm_vif_low_latency(mvmvif) && mvmsta->vif->p2p)
return false;
if (mvm->nvm_data->sku_cap_mimo_disabled)
return false;
return true;
}
static bool rs_siso_allow(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
struct rs_rate *rate,
const struct rs_tx_column *next_col)
{
if (!sta->ht_cap.ht_supported)
return false;
return true;
}
static bool rs_sgi_allow(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
struct rs_rate *rate,
const struct rs_tx_column *next_col)
{
struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
if (is_ht20(rate) && (ht_cap->cap &
IEEE80211_HT_CAP_SGI_20))
return true;
if (is_ht40(rate) && (ht_cap->cap &
IEEE80211_HT_CAP_SGI_40))
return true;
if (is_ht80(rate) && (vht_cap->cap &
IEEE80211_VHT_CAP_SHORT_GI_80))
return true;
return false;
}
static inline u8 rs_extract_rate(u32 rate_n_flags)
{
return (u8)(rate_n_flags & RATE_LEGACY_RATE_MSK);
}
static int iwl_hwrate_to_plcp_idx(u32 rate_n_flags)
{
int idx = 0;
if (rate_n_flags & RATE_MCS_HT_MSK) {
idx = rate_n_flags & RATE_HT_MCS_RATE_CODE_MSK;
idx += IWL_RATE_MCS_0_INDEX;
if (idx >= IWL_RATE_9M_INDEX)
idx += 1;
if ((idx >= IWL_FIRST_HT_RATE) && (idx <= IWL_LAST_HT_RATE))
return idx;
} else if (rate_n_flags & RATE_MCS_VHT_MSK) {
idx = rate_n_flags & RATE_VHT_MCS_RATE_CODE_MSK;
idx += IWL_RATE_MCS_0_INDEX;
if (idx >= IWL_RATE_9M_INDEX)
idx++;
if ((idx >= IWL_FIRST_VHT_RATE) && (idx <= IWL_LAST_VHT_RATE))
return idx;
} else {
u8 legacy_rate = rs_extract_rate(rate_n_flags);
for (idx = 0; idx < ARRAY_SIZE(iwl_rates); idx++)
if (iwl_rates[idx].plcp == legacy_rate)
return idx;
}
return IWL_RATE_INVALID;
}
static const char *rs_pretty_ant(u8 ant)
{
static const char * const ant_name[] = {
[ANT_NONE] = "None",
[ANT_A] = "A",
[ANT_B] = "B",
[ANT_AB] = "AB",
[ANT_C] = "C",
[ANT_AC] = "AC",
[ANT_BC] = "BC",
[ANT_ABC] = "ABC",
};
if (ant > ANT_ABC)
return "UNKNOWN";
return ant_name[ant];
}
static const char *rs_pretty_lq_type(enum iwl_table_type type)
{
static const char * const lq_types[] = {
[LQ_NONE] = "NONE",
[LQ_LEGACY_A] = "LEGACY_A",
[LQ_LEGACY_G] = "LEGACY_G",
[LQ_HT_SISO] = "HT SISO",
[LQ_HT_MIMO2] = "HT MIMO",
[LQ_VHT_SISO] = "VHT SISO",
[LQ_VHT_MIMO2] = "VHT MIMO",
};
if (type < LQ_NONE || type >= LQ_MAX)
return "UNKNOWN";
return lq_types[type];
}
static inline void rs_dump_rate(struct iwl_mvm *mvm, const struct rs_rate *rate,
const char *prefix)
{
IWL_DEBUG_RATE(mvm,
"%s: (%s: %d) ANT: %s BW: %d SGI: %d LDPC: %d STBC: %d\n",
prefix, rs_pretty_lq_type(rate->type),
rate->index, rs_pretty_ant(rate->ant),
rate->bw, rate->sgi, rate->ldpc, rate->stbc);
}
static void rs_rate_scale_clear_window(struct iwl_rate_scale_data *window)
{
window->data = 0;
window->success_counter = 0;
window->success_ratio = IWL_INVALID_VALUE;
window->counter = 0;
window->average_tpt = IWL_INVALID_VALUE;
}
static void rs_rate_scale_clear_tbl_windows(struct iwl_mvm *mvm,
struct iwl_scale_tbl_info *tbl)
{
int i;
IWL_DEBUG_RATE(mvm, "Clearing up window stats\n");
for (i = 0; i < IWL_RATE_COUNT; i++)
rs_rate_scale_clear_window(&tbl->win[i]);
for (i = 0; i < ARRAY_SIZE(tbl->tpc_win); i++)
rs_rate_scale_clear_window(&tbl->tpc_win[i]);
}
static inline u8 rs_is_valid_ant(u8 valid_antenna, u8 ant_type)
{
return (ant_type & valid_antenna) == ant_type;
}
static int rs_tl_turn_on_agg_for_tid(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_data, u8 tid,
struct ieee80211_sta *sta)
{
int ret = -EAGAIN;
IWL_DEBUG_HT(mvm, "Starting Tx agg: STA: %pM tid: %d\n",
sta->addr, tid);
ret = ieee80211_start_tx_ba_session(sta, tid, 5000);
if (ret == -EAGAIN) {
IWL_ERR(mvm, "Fail start Tx agg on tid: %d\n",
tid);
ieee80211_stop_tx_ba_session(sta, tid);
}
return ret;
}
static void rs_tl_turn_on_agg(struct iwl_mvm *mvm, u8 tid,
struct iwl_lq_sta *lq_data,
struct ieee80211_sta *sta)
{
if (tid < IWL_MAX_TID_COUNT)
rs_tl_turn_on_agg_for_tid(mvm, lq_data, tid, sta);
else
IWL_ERR(mvm, "tid exceeds max TID count: %d/%d\n",
tid, IWL_MAX_TID_COUNT);
}
static inline int get_num_of_ant_from_rate(u32 rate_n_flags)
{
return !!(rate_n_flags & RATE_MCS_ANT_A_MSK) +
!!(rate_n_flags & RATE_MCS_ANT_B_MSK) +
!!(rate_n_flags & RATE_MCS_ANT_C_MSK);
}
static s32 get_expected_tpt(struct iwl_scale_tbl_info *tbl, int rs_index)
{
if (tbl->expected_tpt)
return tbl->expected_tpt[rs_index];
return 0;
}
static int _rs_collect_tx_data(struct iwl_mvm *mvm,
struct iwl_scale_tbl_info *tbl,
int scale_index, int attempts, int successes,
struct iwl_rate_scale_data *window)
{
static const u64 mask = (((u64)1) << (IWL_RATE_MAX_WINDOW - 1));
s32 fail_count, tpt;
tpt = get_expected_tpt(tbl, scale_index);
while (attempts > 0) {
if (window->counter >= IWL_RATE_MAX_WINDOW) {
window->counter = IWL_RATE_MAX_WINDOW - 1;
if (window->data & mask) {
window->data &= ~mask;
window->success_counter--;
}
}
window->counter++;
window->data <<= 1;
if (successes > 0) {
window->success_counter++;
window->data |= 0x1;
successes--;
}
attempts--;
}
if (window->counter > 0)
window->success_ratio = 128 * (100 * window->success_counter)
/ window->counter;
else
window->success_ratio = IWL_INVALID_VALUE;
fail_count = window->counter - window->success_counter;
if ((fail_count >= IWL_MVM_RS_RATE_MIN_FAILURE_TH) ||
(window->success_counter >= IWL_MVM_RS_RATE_MIN_SUCCESS_TH))
window->average_tpt = (window->success_ratio * tpt + 64) / 128;
else
window->average_tpt = IWL_INVALID_VALUE;
return 0;
}
static int rs_collect_tx_data(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct iwl_scale_tbl_info *tbl,
int scale_index, int attempts, int successes,
u8 reduced_txp)
{
struct iwl_rate_scale_data *window = NULL;
int ret;
if (scale_index < 0 || scale_index >= IWL_RATE_COUNT)
return -EINVAL;
if (tbl->column != RS_COLUMN_INVALID) {
struct lq_sta_pers *pers = &lq_sta->pers;
pers->tx_stats[tbl->column][scale_index].total += attempts;
pers->tx_stats[tbl->column][scale_index].success += successes;
}
window = &(tbl->win[scale_index]);
ret = _rs_collect_tx_data(mvm, tbl, scale_index, attempts, successes,
window);
if (ret)
return ret;
if (WARN_ON_ONCE(reduced_txp > TPC_MAX_REDUCTION))
return -EINVAL;
window = &tbl->tpc_win[reduced_txp];
return _rs_collect_tx_data(mvm, tbl, scale_index, attempts, successes,
window);
}
static u32 ucode_rate_from_rs_rate(struct iwl_mvm *mvm,
struct rs_rate *rate)
{
u32 ucode_rate = 0;
int index = rate->index;
ucode_rate |= ((rate->ant << RATE_MCS_ANT_POS) &
RATE_MCS_ANT_ABC_MSK);
if (is_legacy(rate)) {
ucode_rate |= iwl_rates[index].plcp;
if (index >= IWL_FIRST_CCK_RATE && index <= IWL_LAST_CCK_RATE)
ucode_rate |= RATE_MCS_CCK_MSK;
return ucode_rate;
}
if (is_ht(rate)) {
if (index < IWL_FIRST_HT_RATE || index > IWL_LAST_HT_RATE) {
IWL_ERR(mvm, "Invalid HT rate index %d\n", index);
index = IWL_LAST_HT_RATE;
}
ucode_rate |= RATE_MCS_HT_MSK;
if (is_ht_siso(rate))
ucode_rate |= iwl_rates[index].plcp_ht_siso;
else if (is_ht_mimo2(rate))
ucode_rate |= iwl_rates[index].plcp_ht_mimo2;
else
WARN_ON_ONCE(1);
} else if (is_vht(rate)) {
if (index < IWL_FIRST_VHT_RATE || index > IWL_LAST_VHT_RATE) {
IWL_ERR(mvm, "Invalid VHT rate index %d\n", index);
index = IWL_LAST_VHT_RATE;
}
ucode_rate |= RATE_MCS_VHT_MSK;
if (is_vht_siso(rate))
ucode_rate |= iwl_rates[index].plcp_vht_siso;
else if (is_vht_mimo2(rate))
ucode_rate |= iwl_rates[index].plcp_vht_mimo2;
else
WARN_ON_ONCE(1);
} else {
IWL_ERR(mvm, "Invalid rate->type %d\n", rate->type);
}
if (is_siso(rate) && rate->stbc) {
ucode_rate |= RATE_MCS_ANT_AB_MSK;
ucode_rate |= RATE_MCS_VHT_STBC_MSK;
}
ucode_rate |= rate->bw;
if (rate->sgi)
ucode_rate |= RATE_MCS_SGI_MSK;
if (rate->ldpc)
ucode_rate |= RATE_MCS_LDPC_MSK;
return ucode_rate;
}
static int rs_rate_from_ucode_rate(const u32 ucode_rate,
enum ieee80211_band band,
struct rs_rate *rate)
{
u32 ant_msk = ucode_rate & RATE_MCS_ANT_ABC_MSK;
u8 num_of_ant = get_num_of_ant_from_rate(ucode_rate);
u8 nss;
memset(rate, 0, sizeof(*rate));
rate->index = iwl_hwrate_to_plcp_idx(ucode_rate);
if (rate->index == IWL_RATE_INVALID)
return -EINVAL;
rate->ant = (ant_msk >> RATE_MCS_ANT_POS);
if (!(ucode_rate & RATE_MCS_HT_MSK) &&
!(ucode_rate & RATE_MCS_VHT_MSK)) {
if (num_of_ant == 1) {
if (band == IEEE80211_BAND_5GHZ)
rate->type = LQ_LEGACY_A;
else
rate->type = LQ_LEGACY_G;
}
return 0;
}
if (ucode_rate & RATE_MCS_SGI_MSK)
rate->sgi = true;
if (ucode_rate & RATE_MCS_LDPC_MSK)
rate->ldpc = true;
if (ucode_rate & RATE_MCS_VHT_STBC_MSK)
rate->stbc = true;
if (ucode_rate & RATE_MCS_BF_MSK)
rate->bfer = true;
rate->bw = ucode_rate & RATE_MCS_CHAN_WIDTH_MSK;
if (ucode_rate & RATE_MCS_HT_MSK) {
nss = ((ucode_rate & RATE_HT_MCS_NSS_MSK) >>
RATE_HT_MCS_NSS_POS) + 1;
if (nss == 1) {
rate->type = LQ_HT_SISO;
WARN_ONCE(!rate->stbc && !rate->bfer && num_of_ant != 1,
"stbc %d bfer %d",
rate->stbc, rate->bfer);
} else if (nss == 2) {
rate->type = LQ_HT_MIMO2;
WARN_ON_ONCE(num_of_ant != 2);
} else {
WARN_ON_ONCE(1);
}
} else if (ucode_rate & RATE_MCS_VHT_MSK) {
nss = ((ucode_rate & RATE_VHT_MCS_NSS_MSK) >>
RATE_VHT_MCS_NSS_POS) + 1;
if (nss == 1) {
rate->type = LQ_VHT_SISO;
WARN_ONCE(!rate->stbc && !rate->bfer && num_of_ant != 1,
"stbc %d bfer %d",
rate->stbc, rate->bfer);
} else if (nss == 2) {
rate->type = LQ_VHT_MIMO2;
WARN_ON_ONCE(num_of_ant != 2);
} else {
WARN_ON_ONCE(1);
}
}
WARN_ON_ONCE(rate->bw == RATE_MCS_CHAN_WIDTH_160);
WARN_ON_ONCE(rate->bw == RATE_MCS_CHAN_WIDTH_80 &&
!is_vht(rate));
return 0;
}
static int rs_toggle_antenna(u32 valid_ant, struct rs_rate *rate)
{
u8 new_ant_type;
if (!rate->ant || rate->ant > ANT_ABC)
return 0;
if (!rs_is_valid_ant(valid_ant, rate->ant))
return 0;
new_ant_type = ant_toggle_lookup[rate->ant];
while ((new_ant_type != rate->ant) &&
!rs_is_valid_ant(valid_ant, new_ant_type))
new_ant_type = ant_toggle_lookup[new_ant_type];
if (new_ant_type == rate->ant)
return 0;
rate->ant = new_ant_type;
return 1;
}
static u16 rs_get_supported_rates(struct iwl_lq_sta *lq_sta,
struct rs_rate *rate)
{
if (is_legacy(rate))
return lq_sta->active_legacy_rate;
else if (is_siso(rate))
return lq_sta->active_siso_rate;
else if (is_mimo2(rate))
return lq_sta->active_mimo2_rate;
WARN_ON_ONCE(1);
return 0;
}
static u16 rs_get_adjacent_rate(struct iwl_mvm *mvm, u8 index, u16 rate_mask,
int rate_type)
{
u8 high = IWL_RATE_INVALID;
u8 low = IWL_RATE_INVALID;
if (is_type_a_band(rate_type) || !is_type_legacy(rate_type)) {
int i;
u32 mask;
i = index - 1;
for (mask = (1 << i); i >= 0; i--, mask >>= 1) {
if (rate_mask & mask) {
low = i;
break;
}
}
i = index + 1;
for (mask = (1 << i); i < IWL_RATE_COUNT; i++, mask <<= 1) {
if (rate_mask & mask) {
high = i;
break;
}
}
return (high << 8) | low;
}
low = index;
while (low != IWL_RATE_INVALID) {
low = iwl_rates[low].prev_rs;
if (low == IWL_RATE_INVALID)
break;
if (rate_mask & (1 << low))
break;
}
high = index;
while (high != IWL_RATE_INVALID) {
high = iwl_rates[high].next_rs;
if (high == IWL_RATE_INVALID)
break;
if (rate_mask & (1 << high))
break;
}
return (high << 8) | low;
}
static inline bool rs_rate_supported(struct iwl_lq_sta *lq_sta,
struct rs_rate *rate)
{
return BIT(rate->index) & rs_get_supported_rates(lq_sta, rate);
}
static bool rs_get_lower_rate_in_column(struct iwl_lq_sta *lq_sta,
struct rs_rate *rate)
{
u8 low;
u16 high_low;
u16 rate_mask;
struct iwl_mvm *mvm = lq_sta->pers.drv;
rate_mask = rs_get_supported_rates(lq_sta, rate);
high_low = rs_get_adjacent_rate(mvm, rate->index, rate_mask,
rate->type);
low = high_low & 0xff;
if (low == IWL_RATE_INVALID)
return true;
rate->index = low;
return false;
}
static void rs_get_lower_rate_down_column(struct iwl_lq_sta *lq_sta,
struct rs_rate *rate)
{
struct iwl_mvm *mvm = lq_sta->pers.drv;
if (is_legacy(rate)) {
return;
} else if (is_siso(rate)) {
if (lq_sta->band == IEEE80211_BAND_5GHZ)
rate->type = LQ_LEGACY_A;
else
rate->type = LQ_LEGACY_G;
rate->bw = RATE_MCS_CHAN_WIDTH_20;
WARN_ON_ONCE(rate->index < IWL_RATE_MCS_0_INDEX ||
rate->index > IWL_RATE_MCS_9_INDEX);
rate->index = rs_ht_to_legacy[rate->index];
rate->ldpc = false;
} else {
rate->type = is_vht_mimo2(rate) ?
LQ_VHT_SISO : LQ_HT_SISO;
}
if (num_of_ant(rate->ant) > 1)
rate->ant = first_antenna(iwl_mvm_get_valid_tx_ant(mvm));
rate->sgi = false;
if (!rs_rate_supported(lq_sta, rate))
rs_get_lower_rate_in_column(lq_sta, rate);
}
static inline bool rs_rate_equal(struct rs_rate *a,
struct rs_rate *b,
bool allow_ant_mismatch)
{
bool ant_match = (a->ant == b->ant) && (a->stbc == b->stbc) &&
(a->bfer == b->bfer);
if (allow_ant_mismatch) {
if (a->stbc || a->bfer) {
WARN_ONCE(a->ant != ANT_AB, "stbc %d bfer %d ant %d",
a->stbc, a->bfer, a->ant);
ant_match |= (b->ant == ANT_A || b->ant == ANT_B);
} else if (b->stbc || b->bfer) {
WARN_ONCE(b->ant != ANT_AB, "stbc %d bfer %d ant %d",
b->stbc, b->bfer, b->ant);
ant_match |= (a->ant == ANT_A || a->ant == ANT_B);
}
}
return (a->type == b->type) && (a->bw == b->bw) && (a->sgi == b->sgi) &&
(a->ldpc == b->ldpc) && (a->index == b->index) && ant_match;
}
static inline bool rs_rate_column_match(struct rs_rate *a,
struct rs_rate *b)
{
bool ant_match;
if (a->stbc || a->bfer)
ant_match = (b->ant == ANT_A || b->ant == ANT_B);
else
ant_match = (a->ant == b->ant);
return (a->type == b->type) && (a->bw == b->bw) && (a->sgi == b->sgi)
&& ant_match;
}
static inline enum rs_column rs_get_column_from_rate(struct rs_rate *rate)
{
if (is_legacy(rate)) {
if (rate->ant == ANT_A)
return RS_COLUMN_LEGACY_ANT_A;
if (rate->ant == ANT_B)
return RS_COLUMN_LEGACY_ANT_B;
goto err;
}
if (is_siso(rate)) {
if (rate->ant == ANT_A || rate->stbc || rate->bfer)
return rate->sgi ? RS_COLUMN_SISO_ANT_A_SGI :
RS_COLUMN_SISO_ANT_A;
if (rate->ant == ANT_B)
return rate->sgi ? RS_COLUMN_SISO_ANT_B_SGI :
RS_COLUMN_SISO_ANT_B;
goto err;
}
if (is_mimo(rate))
return rate->sgi ? RS_COLUMN_MIMO2_SGI : RS_COLUMN_MIMO2;
err:
return RS_COLUMN_INVALID;
}
static u8 rs_get_tid(struct ieee80211_hdr *hdr)
{
u8 tid = IWL_MAX_TID_COUNT;
if (ieee80211_is_data_qos(hdr->frame_control)) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & 0xf;
}
if (unlikely(tid > IWL_MAX_TID_COUNT))
tid = IWL_MAX_TID_COUNT;
return tid;
}
void iwl_mvm_rs_tx_status(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
int tid, struct ieee80211_tx_info *info)
{
int legacy_success;
int retries;
int i;
struct iwl_lq_cmd *table;
u32 lq_hwrate;
struct rs_rate lq_rate, tx_resp_rate;
struct iwl_scale_tbl_info *curr_tbl, *other_tbl, *tmp_tbl;
u8 reduced_txp = (uintptr_t)info->status.status_driver_data[0];
u32 tx_resp_hwrate = (uintptr_t)info->status.status_driver_data[1];
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct iwl_lq_sta *lq_sta = &mvmsta->lq_sta;
bool allow_ant_mismatch = fw_has_api(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_API_LQ_SS_PARAMS);
if (!lq_sta) {
IWL_DEBUG_RATE(mvm, "Station rate scaling not created yet.\n");
return;
} else if (!lq_sta->pers.drv) {
IWL_DEBUG_RATE(mvm, "Rate scaling not initialized yet.\n");
return;
}
if ((info->flags & IEEE80211_TX_CTL_AMPDU) &&
!(info->flags & IEEE80211_TX_STAT_AMPDU))
return;
rs_rate_from_ucode_rate(tx_resp_hwrate, info->band, &tx_resp_rate);
#ifdef CONFIG_MAC80211_DEBUGFS
if (lq_sta->pers.dbg_fixed_rate) {
int index = tx_resp_rate.index;
enum rs_column column;
int attempts, success;
column = rs_get_column_from_rate(&tx_resp_rate);
if (WARN_ONCE(column == RS_COLUMN_INVALID,
"Can't map rate 0x%x to column",
tx_resp_hwrate))
return;
if (info->flags & IEEE80211_TX_STAT_AMPDU) {
attempts = info->status.ampdu_len;
success = info->status.ampdu_ack_len;
} else {
attempts = info->status.rates[0].count;
success = !!(info->flags & IEEE80211_TX_STAT_ACK);
}
lq_sta->pers.tx_stats[column][index].total += attempts;
lq_sta->pers.tx_stats[column][index].success += success;
IWL_DEBUG_RATE(mvm, "Fixed rate 0x%x success %d attempts %d\n",
tx_resp_hwrate, success, attempts);
return;
}
#endif
if (time_after(jiffies,
(unsigned long)(lq_sta->last_tx +
(IWL_MVM_RS_IDLE_TIMEOUT * HZ)))) {
int t;
IWL_DEBUG_RATE(mvm, "Tx idle for too long. reinit rs\n");
for (t = 0; t < IWL_MAX_TID_COUNT; t++)
ieee80211_stop_tx_ba_session(sta, t);
iwl_mvm_rs_rate_init(mvm, sta, info->band, false);
return;
}
lq_sta->last_tx = jiffies;
table = &lq_sta->lq;
lq_hwrate = le32_to_cpu(table->rs_table[0]);
rs_rate_from_ucode_rate(lq_hwrate, info->band, &lq_rate);
if (!rs_rate_equal(&tx_resp_rate, &lq_rate, allow_ant_mismatch)) {
IWL_DEBUG_RATE(mvm,
"initial tx resp rate 0x%x does not match 0x%x\n",
tx_resp_hwrate, lq_hwrate);
lq_sta->missed_rate_counter++;
if (lq_sta->missed_rate_counter > IWL_MVM_RS_MISSED_RATE_MAX) {
lq_sta->missed_rate_counter = 0;
IWL_DEBUG_RATE(mvm,
"Too many rates mismatch. Send sync LQ. rs_state %d\n",
lq_sta->rs_state);
iwl_mvm_send_lq_cmd(mvm, &lq_sta->lq, false);
}
return;
} else
lq_sta->missed_rate_counter = 0;
if (!lq_sta->search_better_tbl) {
curr_tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
other_tbl = &(lq_sta->lq_info[1 - lq_sta->active_tbl]);
} else {
curr_tbl = &(lq_sta->lq_info[1 - lq_sta->active_tbl]);
other_tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
}
if (WARN_ON_ONCE(!rs_rate_column_match(&lq_rate, &curr_tbl->rate))) {
IWL_DEBUG_RATE(mvm,
"Neither active nor search matches tx rate\n");
tmp_tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
rs_dump_rate(mvm, &tmp_tbl->rate, "ACTIVE");
tmp_tbl = &(lq_sta->lq_info[1 - lq_sta->active_tbl]);
rs_dump_rate(mvm, &tmp_tbl->rate, "SEARCH");
rs_dump_rate(mvm, &lq_rate, "ACTUAL");
rs_stay_in_table(lq_sta, true);
goto done;
}
if (info->flags & IEEE80211_TX_STAT_AMPDU) {
if (info->status.ampdu_ack_len == 0)
info->status.ampdu_len = 1;
rs_collect_tx_data(mvm, lq_sta, curr_tbl, lq_rate.index,
info->status.ampdu_len,
info->status.ampdu_ack_len,
reduced_txp);
if (lq_sta->rs_state == RS_STATE_STAY_IN_COLUMN) {
lq_sta->total_success += info->status.ampdu_ack_len;
lq_sta->total_failed += (info->status.ampdu_len -
info->status.ampdu_ack_len);
}
} else {
retries = info->status.rates[0].count - 1;
retries = min(retries, 15);
legacy_success = !!(info->flags & IEEE80211_TX_STAT_ACK);
for (i = 0; i <= retries; ++i) {
lq_hwrate = le32_to_cpu(table->rs_table[i]);
rs_rate_from_ucode_rate(lq_hwrate, info->band,
&lq_rate);
if (rs_rate_column_match(&lq_rate, &curr_tbl->rate))
tmp_tbl = curr_tbl;
else if (rs_rate_column_match(&lq_rate,
&other_tbl->rate))
tmp_tbl = other_tbl;
else
continue;
rs_collect_tx_data(mvm, lq_sta, tmp_tbl, lq_rate.index,
1, i < retries ? 0 : legacy_success,
reduced_txp);
}
if (lq_sta->rs_state == RS_STATE_STAY_IN_COLUMN) {
lq_sta->total_success += legacy_success;
lq_sta->total_failed += retries + (1 - legacy_success);
}
}
lq_sta->last_rate_n_flags = lq_hwrate;
IWL_DEBUG_RATE(mvm, "reduced txpower: %d\n", reduced_txp);
done:
if (sta->supp_rates[info->band])
rs_rate_scale_perform(mvm, sta, lq_sta, tid);
}
static void rs_mac80211_tx_status(void *mvm_r,
struct ieee80211_supported_band *sband,
struct ieee80211_sta *sta, void *priv_sta,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct iwl_op_mode *op_mode = (struct iwl_op_mode *)mvm_r;
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
if (!iwl_mvm_sta_from_mac80211(sta)->vif)
return;
if (!ieee80211_is_data(hdr->frame_control) ||
info->flags & IEEE80211_TX_CTL_NO_ACK)
return;
iwl_mvm_rs_tx_status(mvm, sta, rs_get_tid(hdr), info);
}
static void rs_set_stay_in_table(struct iwl_mvm *mvm, u8 is_legacy,
struct iwl_lq_sta *lq_sta)
{
IWL_DEBUG_RATE(mvm, "Moving to RS_STATE_STAY_IN_COLUMN\n");
lq_sta->rs_state = RS_STATE_STAY_IN_COLUMN;
if (is_legacy) {
lq_sta->table_count_limit = IWL_MVM_RS_LEGACY_TABLE_COUNT;
lq_sta->max_failure_limit = IWL_MVM_RS_LEGACY_FAILURE_LIMIT;
lq_sta->max_success_limit = IWL_MVM_RS_LEGACY_SUCCESS_LIMIT;
} else {
lq_sta->table_count_limit = IWL_MVM_RS_NON_LEGACY_TABLE_COUNT;
lq_sta->max_failure_limit = IWL_MVM_RS_NON_LEGACY_FAILURE_LIMIT;
lq_sta->max_success_limit = IWL_MVM_RS_NON_LEGACY_SUCCESS_LIMIT;
}
lq_sta->table_count = 0;
lq_sta->total_failed = 0;
lq_sta->total_success = 0;
lq_sta->flush_timer = jiffies;
lq_sta->visited_columns = 0;
}
static inline int rs_get_max_rate_from_mask(unsigned long rate_mask)
{
if (rate_mask)
return find_last_bit(&rate_mask, BITS_PER_LONG);
return IWL_RATE_INVALID;
}
static int rs_get_max_allowed_rate(struct iwl_lq_sta *lq_sta,
const struct rs_tx_column *column)
{
switch (column->mode) {
case RS_LEGACY:
return lq_sta->max_legacy_rate_idx;
case RS_SISO:
return lq_sta->max_siso_rate_idx;
case RS_MIMO2:
return lq_sta->max_mimo2_rate_idx;
default:
WARN_ON_ONCE(1);
}
return lq_sta->max_legacy_rate_idx;
}
static const u16 *rs_get_expected_tpt_table(struct iwl_lq_sta *lq_sta,
const struct rs_tx_column *column,
u32 bw)
{
const u16 (*ht_tbl_pointer)[IWL_RATE_COUNT];
if (WARN_ON_ONCE(column->mode != RS_LEGACY &&
column->mode != RS_SISO &&
column->mode != RS_MIMO2))
return expected_tpt_legacy;
if (column->mode == RS_LEGACY)
return expected_tpt_legacy;
ht_tbl_pointer = expected_tpt_mimo2_20MHz;
if (column->mode == RS_SISO) {
switch (bw) {
case RATE_MCS_CHAN_WIDTH_20:
ht_tbl_pointer = expected_tpt_siso_20MHz;
break;
case RATE_MCS_CHAN_WIDTH_40:
ht_tbl_pointer = expected_tpt_siso_40MHz;
break;
case RATE_MCS_CHAN_WIDTH_80:
ht_tbl_pointer = expected_tpt_siso_80MHz;
break;
default:
WARN_ON_ONCE(1);
}
} else if (column->mode == RS_MIMO2) {
switch (bw) {
case RATE_MCS_CHAN_WIDTH_20:
ht_tbl_pointer = expected_tpt_mimo2_20MHz;
break;
case RATE_MCS_CHAN_WIDTH_40:
ht_tbl_pointer = expected_tpt_mimo2_40MHz;
break;
case RATE_MCS_CHAN_WIDTH_80:
ht_tbl_pointer = expected_tpt_mimo2_80MHz;
break;
default:
WARN_ON_ONCE(1);
}
} else {
WARN_ON_ONCE(1);
}
if (!column->sgi && !lq_sta->is_agg)
return ht_tbl_pointer[0];
else if (column->sgi && !lq_sta->is_agg)
return ht_tbl_pointer[1];
else if (!column->sgi && lq_sta->is_agg)
return ht_tbl_pointer[2];
else
return ht_tbl_pointer[3];
}
static void rs_set_expected_tpt_table(struct iwl_lq_sta *lq_sta,
struct iwl_scale_tbl_info *tbl)
{
struct rs_rate *rate = &tbl->rate;
const struct rs_tx_column *column = &rs_tx_columns[tbl->column];
tbl->expected_tpt = rs_get_expected_tpt_table(lq_sta, column, rate->bw);
}
static s32 rs_get_best_rate(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct iwl_scale_tbl_info *tbl,
unsigned long rate_mask, s8 index)
{
struct iwl_scale_tbl_info *active_tbl =
&(lq_sta->lq_info[lq_sta->active_tbl]);
s32 success_ratio = active_tbl->win[index].success_ratio;
u16 expected_current_tpt = active_tbl->expected_tpt[index];
const u16 *tpt_tbl = tbl->expected_tpt;
u16 high_low;
u32 target_tpt;
int rate_idx;
if (success_ratio > IWL_MVM_RS_SR_NO_DECREASE) {
target_tpt = 100 * expected_current_tpt;
IWL_DEBUG_RATE(mvm,
"SR %d high. Find rate exceeding EXPECTED_CURRENT %d\n",
success_ratio, target_tpt);
} else {
target_tpt = lq_sta->last_tpt;
IWL_DEBUG_RATE(mvm,
"SR %d not thag good. Find rate exceeding ACTUAL_TPT %d\n",
success_ratio, target_tpt);
}
rate_idx = find_first_bit(&rate_mask, BITS_PER_LONG);
while (rate_idx != IWL_RATE_INVALID) {
if (target_tpt < (100 * tpt_tbl[rate_idx]))
break;
high_low = rs_get_adjacent_rate(mvm, rate_idx, rate_mask,
tbl->rate.type);
rate_idx = (high_low >> 8) & 0xff;
}
IWL_DEBUG_RATE(mvm, "Best rate found %d target_tp %d expected_new %d\n",
rate_idx, target_tpt,
rate_idx != IWL_RATE_INVALID ?
100 * tpt_tbl[rate_idx] : IWL_INVALID_VALUE);
return rate_idx;
}
static u32 rs_bw_from_sta_bw(struct ieee80211_sta *sta)
{
if (sta->bandwidth >= IEEE80211_STA_RX_BW_80)
return RATE_MCS_CHAN_WIDTH_80;
else if (sta->bandwidth >= IEEE80211_STA_RX_BW_40)
return RATE_MCS_CHAN_WIDTH_40;
return RATE_MCS_CHAN_WIDTH_20;
}
static void rs_stay_in_table(struct iwl_lq_sta *lq_sta, bool force_search)
{
struct iwl_scale_tbl_info *tbl;
int active_tbl;
int flush_interval_passed = 0;
struct iwl_mvm *mvm;
mvm = lq_sta->pers.drv;
active_tbl = lq_sta->active_tbl;
tbl = &(lq_sta->lq_info[active_tbl]);
if (lq_sta->rs_state == RS_STATE_STAY_IN_COLUMN) {
if (lq_sta->flush_timer)
flush_interval_passed =
time_after(jiffies,
(unsigned long)(lq_sta->flush_timer +
(IWL_MVM_RS_STAY_IN_COLUMN_TIMEOUT * HZ)));
if (force_search ||
(lq_sta->total_failed > lq_sta->max_failure_limit) ||
(lq_sta->total_success > lq_sta->max_success_limit) ||
((!lq_sta->search_better_tbl) &&
(lq_sta->flush_timer) && (flush_interval_passed))) {
IWL_DEBUG_RATE(mvm,
"LQ: stay is expired %d %d %d\n",
lq_sta->total_failed,
lq_sta->total_success,
flush_interval_passed);
lq_sta->rs_state = RS_STATE_SEARCH_CYCLE_STARTED;
IWL_DEBUG_RATE(mvm,
"Moving to RS_STATE_SEARCH_CYCLE_STARTED\n");
lq_sta->total_failed = 0;
lq_sta->total_success = 0;
lq_sta->flush_timer = 0;
lq_sta->visited_columns = BIT(tbl->column);
} else {
lq_sta->table_count++;
if (lq_sta->table_count >=
lq_sta->table_count_limit) {
lq_sta->table_count = 0;
IWL_DEBUG_RATE(mvm,
"LQ: stay in table clear win\n");
rs_rate_scale_clear_tbl_windows(mvm, tbl);
}
}
if (lq_sta->rs_state == RS_STATE_SEARCH_CYCLE_STARTED) {
rs_rate_scale_clear_tbl_windows(mvm, tbl);
}
}
}
static void rs_update_rate_tbl(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
struct iwl_scale_tbl_info *tbl)
{
rs_fill_lq_cmd(mvm, sta, lq_sta, &tbl->rate);
iwl_mvm_send_lq_cmd(mvm, &lq_sta->lq, false);
}
static enum rs_column rs_get_next_column(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct ieee80211_sta *sta,
struct iwl_scale_tbl_info *tbl)
{
int i, j, max_rate;
enum rs_column next_col_id;
const struct rs_tx_column *curr_col = &rs_tx_columns[tbl->column];
const struct rs_tx_column *next_col;
allow_column_func_t allow_func;
u8 valid_ants = iwl_mvm_get_valid_tx_ant(mvm);
const u16 *expected_tpt_tbl;
u16 tpt, max_expected_tpt;
for (i = 0; i < MAX_NEXT_COLUMNS; i++) {
next_col_id = curr_col->next_columns[i];
if (next_col_id == RS_COLUMN_INVALID)
continue;
if (lq_sta->visited_columns & BIT(next_col_id)) {
IWL_DEBUG_RATE(mvm, "Skip already visited column %d\n",
next_col_id);
continue;
}
next_col = &rs_tx_columns[next_col_id];
if (!rs_is_valid_ant(valid_ants, next_col->ant)) {
IWL_DEBUG_RATE(mvm,
"Skip column %d as ANT config isn't supported by chip. valid_ants 0x%x column ant 0x%x\n",
next_col_id, valid_ants, next_col->ant);
continue;
}
for (j = 0; j < MAX_COLUMN_CHECKS; j++) {
allow_func = next_col->checks[j];
if (allow_func && !allow_func(mvm, sta, &tbl->rate,
next_col))
break;
}
if (j != MAX_COLUMN_CHECKS) {
IWL_DEBUG_RATE(mvm,
"Skip column %d: not allowed (check %d failed)\n",
next_col_id, j);
continue;
}
tpt = lq_sta->last_tpt / 100;
expected_tpt_tbl = rs_get_expected_tpt_table(lq_sta, next_col,
rs_bw_from_sta_bw(sta));
if (WARN_ON_ONCE(!expected_tpt_tbl))
continue;
max_rate = rs_get_max_allowed_rate(lq_sta, next_col);
if (max_rate == IWL_RATE_INVALID) {
IWL_DEBUG_RATE(mvm,
"Skip column %d: no rate is allowed in this column\n",
next_col_id);
continue;
}
max_expected_tpt = expected_tpt_tbl[max_rate];
if (tpt >= max_expected_tpt) {
IWL_DEBUG_RATE(mvm,
"Skip column %d: can't beat current TPT. Max expected %d current %d\n",
next_col_id, max_expected_tpt, tpt);
continue;
}
IWL_DEBUG_RATE(mvm,
"Found potential column %d. Max expected %d current %d\n",
next_col_id, max_expected_tpt, tpt);
break;
}
if (i == MAX_NEXT_COLUMNS)
return RS_COLUMN_INVALID;
return next_col_id;
}
static int rs_switch_to_column(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct ieee80211_sta *sta,
enum rs_column col_id)
{
struct iwl_scale_tbl_info *tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
struct iwl_scale_tbl_info *search_tbl =
&(lq_sta->lq_info[(1 - lq_sta->active_tbl)]);
struct rs_rate *rate = &search_tbl->rate;
const struct rs_tx_column *column = &rs_tx_columns[col_id];
const struct rs_tx_column *curr_column = &rs_tx_columns[tbl->column];
u32 sz = (sizeof(struct iwl_scale_tbl_info) -
(sizeof(struct iwl_rate_scale_data) * IWL_RATE_COUNT));
unsigned long rate_mask = 0;
u32 rate_idx = 0;
memcpy(search_tbl, tbl, sz);
rate->sgi = column->sgi;
rate->ant = column->ant;
if (column->mode == RS_LEGACY) {
if (lq_sta->band == IEEE80211_BAND_5GHZ)
rate->type = LQ_LEGACY_A;
else
rate->type = LQ_LEGACY_G;
rate->bw = RATE_MCS_CHAN_WIDTH_20;
rate->ldpc = false;
rate_mask = lq_sta->active_legacy_rate;
} else if (column->mode == RS_SISO) {
rate->type = lq_sta->is_vht ? LQ_VHT_SISO : LQ_HT_SISO;
rate_mask = lq_sta->active_siso_rate;
} else if (column->mode == RS_MIMO2) {
rate->type = lq_sta->is_vht ? LQ_VHT_MIMO2 : LQ_HT_MIMO2;
rate_mask = lq_sta->active_mimo2_rate;
} else {
WARN_ON_ONCE("Bad column mode");
}
if (column->mode != RS_LEGACY) {
rate->bw = rs_bw_from_sta_bw(sta);
rate->ldpc = lq_sta->ldpc;
}
search_tbl->column = col_id;
rs_set_expected_tpt_table(lq_sta, search_tbl);
lq_sta->visited_columns |= BIT(col_id);
if (curr_column->mode != column->mode) {
rate_idx = rs_get_best_rate(mvm, lq_sta, search_tbl,
rate_mask, rate->index);
if ((rate_idx == IWL_RATE_INVALID) ||
!(BIT(rate_idx) & rate_mask)) {
IWL_DEBUG_RATE(mvm,
"can not switch with index %d"
" rate mask %lx\n",
rate_idx, rate_mask);
goto err;
}
rate->index = rate_idx;
}
IWL_DEBUG_RATE(mvm, "Switched to column %d: Index %d\n",
col_id, rate->index);
return 0;
err:
rate->type = LQ_NONE;
return -1;
}
static enum rs_action rs_get_rate_action(struct iwl_mvm *mvm,
struct iwl_scale_tbl_info *tbl,
s32 sr, int low, int high,
int current_tpt,
int low_tpt, int high_tpt)
{
enum rs_action action = RS_ACTION_STAY;
if ((sr <= RS_PERCENT(IWL_MVM_RS_SR_FORCE_DECREASE)) ||
(current_tpt == 0)) {
IWL_DEBUG_RATE(mvm,
"Decrease rate because of low SR\n");
return RS_ACTION_DOWNSCALE;
}
if ((low_tpt == IWL_INVALID_VALUE) &&
(high_tpt == IWL_INVALID_VALUE) &&
(high != IWL_RATE_INVALID)) {
IWL_DEBUG_RATE(mvm,
"No data about high/low rates. Increase rate\n");
return RS_ACTION_UPSCALE;
}
if ((high_tpt == IWL_INVALID_VALUE) &&
(high != IWL_RATE_INVALID) &&
(low_tpt != IWL_INVALID_VALUE) &&
(low_tpt < current_tpt)) {
IWL_DEBUG_RATE(mvm,
"No data about high rate and low rate is worse. Increase rate\n");
return RS_ACTION_UPSCALE;
}
if ((high_tpt != IWL_INVALID_VALUE) &&
(high_tpt > current_tpt)) {
IWL_DEBUG_RATE(mvm,
"Higher rate is better. Increate rate\n");
return RS_ACTION_UPSCALE;
}
if ((low_tpt != IWL_INVALID_VALUE) &&
(high_tpt != IWL_INVALID_VALUE) &&
(low_tpt < current_tpt) &&
(high_tpt < current_tpt)) {
IWL_DEBUG_RATE(mvm,
"Both high and low are worse. Maintain rate\n");
return RS_ACTION_STAY;
}
if ((low_tpt != IWL_INVALID_VALUE) &&
(low_tpt > current_tpt)) {
IWL_DEBUG_RATE(mvm,
"Lower rate is better\n");
action = RS_ACTION_DOWNSCALE;
goto out;
}
if ((low_tpt == IWL_INVALID_VALUE) &&
(low != IWL_RATE_INVALID)) {
IWL_DEBUG_RATE(mvm,
"No data about lower rate\n");
action = RS_ACTION_DOWNSCALE;
goto out;
}
IWL_DEBUG_RATE(mvm, "Maintain rate\n");
out:
if ((action == RS_ACTION_DOWNSCALE) && (low != IWL_RATE_INVALID)) {
if (sr >= RS_PERCENT(IWL_MVM_RS_SR_NO_DECREASE)) {
IWL_DEBUG_RATE(mvm,
"SR is above NO DECREASE. Avoid downscale\n");
action = RS_ACTION_STAY;
} else if (current_tpt > (100 * tbl->expected_tpt[low])) {
IWL_DEBUG_RATE(mvm,
"Current TPT is higher than max expected in low rate. Avoid downscale\n");
action = RS_ACTION_STAY;
} else {
IWL_DEBUG_RATE(mvm, "Decrease rate\n");
}
}
return action;
}
static bool rs_stbc_allow(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta)
{
if (!lq_sta->stbc_capable)
return false;
if (!iwl_mvm_bt_coex_is_mimo_allowed(mvm, sta))
return false;
return true;
}
static void rs_get_adjacent_txp(struct iwl_mvm *mvm, int index,
int *weaker, int *stronger)
{
*weaker = index + IWL_MVM_RS_TPC_TX_POWER_STEP;
if (*weaker > TPC_MAX_REDUCTION)
*weaker = TPC_INVALID;
*stronger = index - IWL_MVM_RS_TPC_TX_POWER_STEP;
if (*stronger < 0)
*stronger = TPC_INVALID;
}
static bool rs_tpc_allowed(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
struct rs_rate *rate, enum ieee80211_band band)
{
int index = rate->index;
bool cam = (iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_CAM);
bool sta_ps_disabled = (vif->type == NL80211_IFTYPE_STATION &&
!vif->bss_conf.ps);
IWL_DEBUG_RATE(mvm, "cam: %d sta_ps_disabled %d\n",
cam, sta_ps_disabled);
if ((cam || sta_ps_disabled) &&
!iwl_mvm_bt_coex_is_tpc_allowed(mvm, band))
return false;
IWL_DEBUG_RATE(mvm, "check rate, table type: %d\n", rate->type);
if (is_legacy(rate))
return index == IWL_RATE_54M_INDEX;
if (is_ht(rate))
return index == IWL_RATE_MCS_7_INDEX;
if (is_vht(rate))
return index == IWL_RATE_MCS_7_INDEX ||
index == IWL_RATE_MCS_8_INDEX ||
index == IWL_RATE_MCS_9_INDEX;
WARN_ON_ONCE(1);
return false;
}
static enum tpc_action rs_get_tpc_action(struct iwl_mvm *mvm,
s32 sr, int weak, int strong,
int current_tpt,
int weak_tpt, int strong_tpt)
{
if (current_tpt == IWL_INVALID_VALUE) {
IWL_DEBUG_RATE(mvm, "no current tpt. stay.\n");
return TPC_ACTION_STAY;
}
if (sr <= RS_PERCENT(IWL_MVM_RS_TPC_SR_FORCE_INCREASE) ||
current_tpt == 0) {
IWL_DEBUG_RATE(mvm, "increase txp because of weak SR\n");
return TPC_ACTION_NO_RESTIRCTION;
}
if (weak != TPC_INVALID) {
if (weak_tpt == IWL_INVALID_VALUE &&
(strong_tpt == IWL_INVALID_VALUE ||
current_tpt >= strong_tpt)) {
IWL_DEBUG_RATE(mvm,
"no weak txp measurement. decrease txp\n");
return TPC_ACTION_DECREASE;
}
if (weak_tpt > current_tpt) {
IWL_DEBUG_RATE(mvm,
"lower txp has better tpt. decrease txp\n");
return TPC_ACTION_DECREASE;
}
}
if (sr < RS_PERCENT(IWL_MVM_RS_TPC_SR_NO_INCREASE) &&
strong != TPC_INVALID) {
if (weak_tpt == IWL_INVALID_VALUE &&
strong_tpt != IWL_INVALID_VALUE &&
current_tpt < strong_tpt) {
IWL_DEBUG_RATE(mvm,
"higher txp has better tpt. increase txp\n");
return TPC_ACTION_INCREASE;
}
if (weak_tpt < current_tpt &&
(strong_tpt == IWL_INVALID_VALUE ||
strong_tpt > current_tpt)) {
IWL_DEBUG_RATE(mvm,
"lower txp has worse tpt. increase txp\n");
return TPC_ACTION_INCREASE;
}
}
IWL_DEBUG_RATE(mvm, "no need to increase or decrease txp - stay\n");
return TPC_ACTION_STAY;
}
static bool rs_tpc_perform(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
struct iwl_scale_tbl_info *tbl)
{
struct iwl_mvm_sta *mvm_sta = iwl_mvm_sta_from_mac80211(sta);
struct ieee80211_vif *vif = mvm_sta->vif;
struct ieee80211_chanctx_conf *chanctx_conf;
enum ieee80211_band band;
struct iwl_rate_scale_data *window;
struct rs_rate *rate = &tbl->rate;
enum tpc_action action;
s32 sr;
u8 cur = lq_sta->lq.reduced_tpc;
int current_tpt;
int weak, strong;
int weak_tpt = IWL_INVALID_VALUE, strong_tpt = IWL_INVALID_VALUE;
#ifdef CONFIG_MAC80211_DEBUGFS
if (lq_sta->pers.dbg_fixed_txp_reduction <= TPC_MAX_REDUCTION) {
IWL_DEBUG_RATE(mvm, "fixed tpc: %d\n",
lq_sta->pers.dbg_fixed_txp_reduction);
lq_sta->lq.reduced_tpc = lq_sta->pers.dbg_fixed_txp_reduction;
return cur != lq_sta->pers.dbg_fixed_txp_reduction;
}
#endif
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (WARN_ON(!chanctx_conf))
band = IEEE80211_NUM_BANDS;
else
band = chanctx_conf->def.chan->band;
rcu_read_unlock();
if (!rs_tpc_allowed(mvm, vif, rate, band)) {
IWL_DEBUG_RATE(mvm,
"tpc is not allowed. remove txp restrictions\n");
lq_sta->lq.reduced_tpc = TPC_NO_REDUCTION;
return cur != TPC_NO_REDUCTION;
}
rs_get_adjacent_txp(mvm, cur, &weak, &strong);
window = tbl->tpc_win;
sr = window[cur].success_ratio;
current_tpt = window[cur].average_tpt;
if (weak != TPC_INVALID)
weak_tpt = window[weak].average_tpt;
if (strong != TPC_INVALID)
strong_tpt = window[strong].average_tpt;
IWL_DEBUG_RATE(mvm,
"(TPC: %d): cur_tpt %d SR %d weak %d strong %d weak_tpt %d strong_tpt %d\n",
cur, current_tpt, sr, weak, strong,
weak_tpt, strong_tpt);
action = rs_get_tpc_action(mvm, sr, weak, strong,
current_tpt, weak_tpt, strong_tpt);
if (weak == TPC_INVALID && action == TPC_ACTION_DECREASE) {
IWL_DEBUG_RATE(mvm, "already in lowest txp, stay\n");
action = TPC_ACTION_STAY;
} else if (strong == TPC_INVALID &&
(action == TPC_ACTION_INCREASE ||
action == TPC_ACTION_NO_RESTIRCTION)) {
IWL_DEBUG_RATE(mvm, "already in highest txp, stay\n");
action = TPC_ACTION_STAY;
}
switch (action) {
case TPC_ACTION_DECREASE:
lq_sta->lq.reduced_tpc = weak;
return true;
case TPC_ACTION_INCREASE:
lq_sta->lq.reduced_tpc = strong;
return true;
case TPC_ACTION_NO_RESTIRCTION:
lq_sta->lq.reduced_tpc = TPC_NO_REDUCTION;
return true;
case TPC_ACTION_STAY:
break;
}
return false;
}
static void rs_rate_scale_perform(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
int tid)
{
int low = IWL_RATE_INVALID;
int high = IWL_RATE_INVALID;
int index;
struct iwl_rate_scale_data *window = NULL;
int current_tpt = IWL_INVALID_VALUE;
int low_tpt = IWL_INVALID_VALUE;
int high_tpt = IWL_INVALID_VALUE;
u32 fail_count;
enum rs_action scale_action = RS_ACTION_STAY;
u16 rate_mask;
u8 update_lq = 0;
struct iwl_scale_tbl_info *tbl, *tbl1;
u8 active_tbl = 0;
u8 done_search = 0;
u16 high_low;
s32 sr;
u8 prev_agg = lq_sta->is_agg;
struct iwl_mvm_sta *sta_priv = iwl_mvm_sta_from_mac80211(sta);
struct iwl_mvm_tid_data *tid_data;
struct rs_rate *rate;
lq_sta->is_agg = !!sta_priv->agg_tids;
if (!lq_sta->search_better_tbl)
active_tbl = lq_sta->active_tbl;
else
active_tbl = 1 - lq_sta->active_tbl;
tbl = &(lq_sta->lq_info[active_tbl]);
rate = &tbl->rate;
if (prev_agg != lq_sta->is_agg) {
IWL_DEBUG_RATE(mvm,
"Aggregation changed: prev %d current %d. Update expected TPT table\n",
prev_agg, lq_sta->is_agg);
rs_set_expected_tpt_table(lq_sta, tbl);
rs_rate_scale_clear_tbl_windows(mvm, tbl);
}
index = rate->index;
rate_mask = rs_get_supported_rates(lq_sta, rate);
if (!(BIT(index) & rate_mask)) {
IWL_ERR(mvm, "Current Rate is not valid\n");
if (lq_sta->search_better_tbl) {
rate->type = LQ_NONE;
lq_sta->search_better_tbl = 0;
tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
rs_update_rate_tbl(mvm, sta, lq_sta, tbl);
}
return;
}
if (!tbl->expected_tpt) {
IWL_ERR(mvm, "tbl->expected_tpt is NULL\n");
return;
}
window = &(tbl->win[index]);
fail_count = window->counter - window->success_counter;
if ((fail_count < IWL_MVM_RS_RATE_MIN_FAILURE_TH) &&
(window->success_counter < IWL_MVM_RS_RATE_MIN_SUCCESS_TH)) {
IWL_DEBUG_RATE(mvm,
"(%s: %d): Test Window: succ %d total %d\n",
rs_pretty_lq_type(rate->type),
index, window->success_counter, window->counter);
window->average_tpt = IWL_INVALID_VALUE;
rs_stay_in_table(lq_sta, false);
return;
}
if (lq_sta->search_better_tbl) {
if (window->average_tpt > lq_sta->last_tpt) {
IWL_DEBUG_RATE(mvm,
"SWITCHING TO NEW TABLE SR: %d "
"cur-tpt %d old-tpt %d\n",
window->success_ratio,
window->average_tpt,
lq_sta->last_tpt);
lq_sta->active_tbl = active_tbl;
current_tpt = window->average_tpt;
} else {
IWL_DEBUG_RATE(mvm,
"GOING BACK TO THE OLD TABLE: SR %d "
"cur-tpt %d old-tpt %d\n",
window->success_ratio,
window->average_tpt,
lq_sta->last_tpt);
rate->type = LQ_NONE;
active_tbl = lq_sta->active_tbl;
tbl = &(lq_sta->lq_info[active_tbl]);
index = tbl->rate.index;
current_tpt = lq_sta->last_tpt;
update_lq = 1;
}
lq_sta->search_better_tbl = 0;
done_search = 1;
goto lq_update;
}
high_low = rs_get_adjacent_rate(mvm, index, rate_mask, rate->type);
low = high_low & 0xff;
high = (high_low >> 8) & 0xff;
sr = window->success_ratio;
current_tpt = window->average_tpt;
if (low != IWL_RATE_INVALID)
low_tpt = tbl->win[low].average_tpt;
if (high != IWL_RATE_INVALID)
high_tpt = tbl->win[high].average_tpt;
IWL_DEBUG_RATE(mvm,
"(%s: %d): cur_tpt %d SR %d low %d high %d low_tpt %d high_tpt %d\n",
rs_pretty_lq_type(rate->type), index, current_tpt, sr,
low, high, low_tpt, high_tpt);
scale_action = rs_get_rate_action(mvm, tbl, sr, low, high,
current_tpt, low_tpt, high_tpt);
if (is_mimo(rate) &&
!iwl_mvm_bt_coex_is_mimo_allowed(mvm, sta)) {
IWL_DEBUG_RATE(mvm,
"BT Coex forbids MIMO. Search for new config\n");
rs_stay_in_table(lq_sta, true);
goto lq_update;
}
switch (scale_action) {
case RS_ACTION_DOWNSCALE:
if (low != IWL_RATE_INVALID) {
update_lq = 1;
index = low;
} else {
IWL_DEBUG_RATE(mvm,
"At the bottom rate. Can't decrease\n");
}
break;
case RS_ACTION_UPSCALE:
if (high != IWL_RATE_INVALID) {
update_lq = 1;
index = high;
} else {
IWL_DEBUG_RATE(mvm,
"At the top rate. Can't increase\n");
}
break;
case RS_ACTION_STAY:
if (lq_sta->rs_state == RS_STATE_STAY_IN_COLUMN)
update_lq = rs_tpc_perform(mvm, sta, lq_sta, tbl);
break;
default:
break;
}
lq_update:
if (update_lq) {
tbl->rate.index = index;
rs_update_rate_tbl(mvm, sta, lq_sta, tbl);
}
rs_stay_in_table(lq_sta, false);
if (!update_lq && !done_search &&
lq_sta->rs_state == RS_STATE_SEARCH_CYCLE_STARTED
&& window->counter) {
enum rs_column next_column;
lq_sta->last_tpt = current_tpt;
IWL_DEBUG_RATE(mvm,
"Start Search: update_lq %d done_search %d rs_state %d win->counter %d\n",
update_lq, done_search, lq_sta->rs_state,
window->counter);
next_column = rs_get_next_column(mvm, lq_sta, sta, tbl);
if (next_column != RS_COLUMN_INVALID) {
int ret = rs_switch_to_column(mvm, lq_sta, sta,
next_column);
if (!ret)
lq_sta->search_better_tbl = 1;
} else {
IWL_DEBUG_RATE(mvm,
"No more columns to explore in search cycle. Go to RS_STATE_SEARCH_CYCLE_ENDED\n");
lq_sta->rs_state = RS_STATE_SEARCH_CYCLE_ENDED;
}
if (lq_sta->search_better_tbl) {
tbl = &(lq_sta->lq_info[(1 - lq_sta->active_tbl)]);
rs_rate_scale_clear_tbl_windows(mvm, tbl);
index = tbl->rate.index;
rs_dump_rate(mvm, &tbl->rate,
"Switch to SEARCH TABLE:");
rs_update_rate_tbl(mvm, sta, lq_sta, tbl);
} else {
done_search = 1;
}
}
if (done_search && lq_sta->rs_state == RS_STATE_SEARCH_CYCLE_ENDED) {
tbl1 = &(lq_sta->lq_info[lq_sta->active_tbl]);
if (is_legacy(&tbl1->rate)) {
IWL_DEBUG_RATE(mvm, "LQ: STAY in legacy table\n");
if (tid != IWL_MAX_TID_COUNT) {
tid_data = &sta_priv->tid_data[tid];
if (tid_data->state != IWL_AGG_OFF) {
IWL_DEBUG_RATE(mvm,
"Stop aggregation on tid %d\n",
tid);
ieee80211_stop_tx_ba_session(sta, tid);
}
}
rs_set_stay_in_table(mvm, 1, lq_sta);
} else {
if ((lq_sta->last_tpt > IWL_AGG_TPT_THREHOLD) &&
(lq_sta->tx_agg_tid_en & (1 << tid)) &&
(tid != IWL_MAX_TID_COUNT)) {
tid_data = &sta_priv->tid_data[tid];
if (tid_data->state == IWL_AGG_OFF) {
IWL_DEBUG_RATE(mvm,
"try to aggregate tid %d\n",
tid);
rs_tl_turn_on_agg(mvm, tid,
lq_sta, sta);
}
}
rs_set_stay_in_table(mvm, 0, lq_sta);
}
}
}
static void rs_init_optimal_rate(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta)
{
struct rs_rate *rate = &lq_sta->optimal_rate;
if (lq_sta->max_mimo2_rate_idx != IWL_RATE_INVALID)
rate->type = lq_sta->is_vht ? LQ_VHT_MIMO2 : LQ_HT_MIMO2;
else if (lq_sta->max_siso_rate_idx != IWL_RATE_INVALID)
rate->type = lq_sta->is_vht ? LQ_VHT_SISO : LQ_HT_SISO;
else if (lq_sta->band == IEEE80211_BAND_5GHZ)
rate->type = LQ_LEGACY_A;
else
rate->type = LQ_LEGACY_G;
rate->bw = rs_bw_from_sta_bw(sta);
rate->sgi = rs_sgi_allow(mvm, sta, rate, NULL);
if (is_mimo(rate)) {
lq_sta->optimal_rate_mask = lq_sta->active_mimo2_rate;
} else if (is_siso(rate)) {
lq_sta->optimal_rate_mask = lq_sta->active_siso_rate;
} else {
lq_sta->optimal_rate_mask = lq_sta->active_legacy_rate;
if (lq_sta->band == IEEE80211_BAND_5GHZ) {
lq_sta->optimal_rates = rs_optimal_rates_5ghz_legacy;
lq_sta->optimal_nentries =
ARRAY_SIZE(rs_optimal_rates_5ghz_legacy);
} else {
lq_sta->optimal_rates = rs_optimal_rates_24ghz_legacy;
lq_sta->optimal_nentries =
ARRAY_SIZE(rs_optimal_rates_24ghz_legacy);
}
}
if (is_vht(rate)) {
if (rate->bw == RATE_MCS_CHAN_WIDTH_20) {
lq_sta->optimal_rates = rs_optimal_rates_vht_20mhz;
lq_sta->optimal_nentries =
ARRAY_SIZE(rs_optimal_rates_vht_20mhz);
} else {
lq_sta->optimal_rates = rs_optimal_rates_vht_40_80mhz;
lq_sta->optimal_nentries =
ARRAY_SIZE(rs_optimal_rates_vht_40_80mhz);
}
} else if (is_ht(rate)) {
lq_sta->optimal_rates = rs_optimal_rates_ht;
lq_sta->optimal_nentries = ARRAY_SIZE(rs_optimal_rates_ht);
}
}
static struct rs_rate *rs_get_optimal_rate(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta)
{
struct rs_rate *rate = &lq_sta->optimal_rate;
int i;
rate->index = find_first_bit(&lq_sta->optimal_rate_mask,
BITS_PER_LONG);
for (i = 0; i < lq_sta->optimal_nentries; i++) {
int rate_idx = lq_sta->optimal_rates[i].rate_idx;
if ((lq_sta->pers.last_rssi >= lq_sta->optimal_rates[i].rssi) &&
(BIT(rate_idx) & lq_sta->optimal_rate_mask)) {
rate->index = rate_idx;
break;
}
}
rs_dump_rate(mvm, rate, "OPTIMAL RATE");
return rate;
}
static void rs_get_initial_rate(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
enum ieee80211_band band,
struct rs_rate *rate)
{
int i, nentries;
s8 best_rssi = S8_MIN;
u8 best_ant = ANT_NONE;
u8 valid_tx_ant = iwl_mvm_get_valid_tx_ant(mvm);
const struct rs_init_rate_info *initial_rates;
for (i = 0; i < ARRAY_SIZE(lq_sta->pers.chain_signal); i++) {
if (!(lq_sta->pers.chains & BIT(i)))
continue;
if (lq_sta->pers.chain_signal[i] > best_rssi) {
best_rssi = lq_sta->pers.chain_signal[i];
best_ant = BIT(i);
}
}
IWL_DEBUG_RATE(mvm, "Best ANT: %s Best RSSI: %d\n",
rs_pretty_ant(best_ant), best_rssi);
if (best_ant != ANT_A && best_ant != ANT_B)
rate->ant = first_antenna(valid_tx_ant);
else
rate->ant = best_ant;
rate->sgi = false;
rate->ldpc = false;
rate->bw = RATE_MCS_CHAN_WIDTH_20;
rate->index = find_first_bit(&lq_sta->active_legacy_rate,
BITS_PER_LONG);
if (band == IEEE80211_BAND_5GHZ) {
rate->type = LQ_LEGACY_A;
initial_rates = rs_optimal_rates_5ghz_legacy;
nentries = ARRAY_SIZE(rs_optimal_rates_5ghz_legacy);
} else {
rate->type = LQ_LEGACY_G;
initial_rates = rs_optimal_rates_24ghz_legacy;
nentries = ARRAY_SIZE(rs_optimal_rates_24ghz_legacy);
}
if (IWL_MVM_RS_RSSI_BASED_INIT_RATE) {
for (i = 0; i < nentries; i++) {
int rate_idx = initial_rates[i].rate_idx;
if ((best_rssi >= initial_rates[i].rssi) &&
(BIT(rate_idx) & lq_sta->active_legacy_rate)) {
rate->index = rate_idx;
break;
}
}
}
IWL_DEBUG_RATE(mvm, "rate_idx %d ANT %s\n", rate->index,
rs_pretty_ant(rate->ant));
}
void rs_update_last_rssi(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct ieee80211_rx_status *rx_status)
{
int i;
lq_sta->pers.chains = rx_status->chains;
lq_sta->pers.chain_signal[0] = rx_status->chain_signal[0];
lq_sta->pers.chain_signal[1] = rx_status->chain_signal[1];
lq_sta->pers.chain_signal[2] = rx_status->chain_signal[2];
lq_sta->pers.last_rssi = S8_MIN;
for (i = 0; i < ARRAY_SIZE(lq_sta->pers.chain_signal); i++) {
if (!(lq_sta->pers.chains & BIT(i)))
continue;
if (lq_sta->pers.chain_signal[i] > lq_sta->pers.last_rssi)
lq_sta->pers.last_rssi = lq_sta->pers.chain_signal[i];
}
}
static void rs_initialize_lq(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
enum ieee80211_band band,
bool init)
{
struct iwl_scale_tbl_info *tbl;
struct rs_rate *rate;
u8 active_tbl = 0;
if (!sta || !lq_sta)
return;
if (!lq_sta->search_better_tbl)
active_tbl = lq_sta->active_tbl;
else
active_tbl = 1 - lq_sta->active_tbl;
tbl = &(lq_sta->lq_info[active_tbl]);
rate = &tbl->rate;
rs_get_initial_rate(mvm, lq_sta, band, rate);
rs_init_optimal_rate(mvm, sta, lq_sta);
WARN_ON_ONCE(rate->ant != ANT_A && rate->ant != ANT_B);
if (rate->ant == ANT_A)
tbl->column = RS_COLUMN_LEGACY_ANT_A;
else
tbl->column = RS_COLUMN_LEGACY_ANT_B;
rs_set_expected_tpt_table(lq_sta, tbl);
rs_fill_lq_cmd(mvm, sta, lq_sta, rate);
iwl_mvm_send_lq_cmd(mvm, &lq_sta->lq, init);
}
static void rs_get_rate(void *mvm_r, struct ieee80211_sta *sta, void *mvm_sta,
struct ieee80211_tx_rate_control *txrc)
{
struct sk_buff *skb = txrc->skb;
struct iwl_op_mode *op_mode __maybe_unused =
(struct iwl_op_mode *)mvm_r;
struct iwl_mvm *mvm __maybe_unused = IWL_OP_MODE_GET_MVM(op_mode);
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct iwl_lq_sta *lq_sta = mvm_sta;
struct rs_rate *optimal_rate;
u32 last_ucode_rate;
if (sta && !iwl_mvm_sta_from_mac80211(sta)->vif) {
sta = NULL;
mvm_sta = NULL;
}
if (lq_sta && !lq_sta->pers.drv) {
IWL_DEBUG_RATE(mvm, "Rate scaling not initialized yet.\n");
mvm_sta = NULL;
}
if (rate_control_send_low(sta, mvm_sta, txrc))
return;
iwl_mvm_hwrate_to_tx_rate(lq_sta->last_rate_n_flags,
info->band, &info->control.rates[0]);
info->control.rates[0].count = 1;
if (lq_sta->rs_state != RS_STATE_STAY_IN_COLUMN) {
optimal_rate = rs_get_optimal_rate(mvm, lq_sta);
last_ucode_rate = ucode_rate_from_rs_rate(mvm,
optimal_rate);
iwl_mvm_hwrate_to_tx_rate(last_ucode_rate, info->band,
&txrc->reported_rate);
}
}
static void *rs_alloc_sta(void *mvm_rate, struct ieee80211_sta *sta,
gfp_t gfp)
{
struct iwl_mvm_sta *sta_priv = iwl_mvm_sta_from_mac80211(sta);
struct iwl_op_mode *op_mode = (struct iwl_op_mode *)mvm_rate;
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
struct iwl_lq_sta *lq_sta = &sta_priv->lq_sta;
IWL_DEBUG_RATE(mvm, "create station rate scale window\n");
lq_sta->pers.drv = mvm;
#ifdef CONFIG_MAC80211_DEBUGFS
lq_sta->pers.dbg_fixed_rate = 0;
lq_sta->pers.dbg_fixed_txp_reduction = TPC_INVALID;
lq_sta->pers.ss_force = RS_SS_FORCE_NONE;
#endif
lq_sta->pers.chains = 0;
memset(lq_sta->pers.chain_signal, 0, sizeof(lq_sta->pers.chain_signal));
lq_sta->pers.last_rssi = S8_MIN;
return &sta_priv->lq_sta;
}
static int rs_vht_highest_rx_mcs_index(struct ieee80211_sta_vht_cap *vht_cap,
int nss)
{
u16 rx_mcs = le16_to_cpu(vht_cap->vht_mcs.rx_mcs_map) &
(0x3 << (2 * (nss - 1)));
rx_mcs >>= (2 * (nss - 1));
if (rx_mcs == IEEE80211_VHT_MCS_SUPPORT_0_7)
return IWL_RATE_MCS_7_INDEX;
else if (rx_mcs == IEEE80211_VHT_MCS_SUPPORT_0_8)
return IWL_RATE_MCS_8_INDEX;
else if (rx_mcs == IEEE80211_VHT_MCS_SUPPORT_0_9)
return IWL_RATE_MCS_9_INDEX;
WARN_ON_ONCE(rx_mcs != IEEE80211_VHT_MCS_NOT_SUPPORTED);
return -1;
}
static void rs_vht_set_enabled_rates(struct ieee80211_sta *sta,
struct ieee80211_sta_vht_cap *vht_cap,
struct iwl_lq_sta *lq_sta)
{
int i;
int highest_mcs = rs_vht_highest_rx_mcs_index(vht_cap, 1);
if (highest_mcs >= IWL_RATE_MCS_0_INDEX) {
for (i = IWL_RATE_MCS_0_INDEX; i <= highest_mcs; i++) {
if (i == IWL_RATE_9M_INDEX)
continue;
if (i == IWL_RATE_MCS_9_INDEX &&
sta->bandwidth == IEEE80211_STA_RX_BW_20)
continue;
lq_sta->active_siso_rate |= BIT(i);
}
}
if (sta->rx_nss < 2)
return;
highest_mcs = rs_vht_highest_rx_mcs_index(vht_cap, 2);
if (highest_mcs >= IWL_RATE_MCS_0_INDEX) {
for (i = IWL_RATE_MCS_0_INDEX; i <= highest_mcs; i++) {
if (i == IWL_RATE_9M_INDEX)
continue;
if (i == IWL_RATE_MCS_9_INDEX &&
sta->bandwidth == IEEE80211_STA_RX_BW_20)
continue;
lq_sta->active_mimo2_rate |= BIT(i);
}
}
}
static void rs_ht_init(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
struct ieee80211_sta_ht_cap *ht_cap)
{
lq_sta->active_siso_rate = ht_cap->mcs.rx_mask[0] << 1;
lq_sta->active_siso_rate |= ht_cap->mcs.rx_mask[0] & 0x1;
lq_sta->active_siso_rate &= ~((u16)0x2);
lq_sta->active_siso_rate <<= IWL_FIRST_OFDM_RATE;
lq_sta->active_mimo2_rate = ht_cap->mcs.rx_mask[1] << 1;
lq_sta->active_mimo2_rate |= ht_cap->mcs.rx_mask[1] & 0x1;
lq_sta->active_mimo2_rate &= ~((u16)0x2);
lq_sta->active_mimo2_rate <<= IWL_FIRST_OFDM_RATE;
if (mvm->cfg->ht_params->ldpc &&
(ht_cap->cap & IEEE80211_HT_CAP_LDPC_CODING))
lq_sta->ldpc = true;
if (mvm->cfg->ht_params->stbc &&
(num_of_ant(iwl_mvm_get_valid_tx_ant(mvm)) > 1) &&
(ht_cap->cap & IEEE80211_HT_CAP_RX_STBC))
lq_sta->stbc_capable = true;
lq_sta->is_vht = false;
}
static void rs_vht_init(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
struct ieee80211_sta_vht_cap *vht_cap)
{
rs_vht_set_enabled_rates(sta, vht_cap, lq_sta);
if (mvm->cfg->ht_params->ldpc &&
(vht_cap->cap & IEEE80211_VHT_CAP_RXLDPC))
lq_sta->ldpc = true;
if (mvm->cfg->ht_params->stbc &&
(num_of_ant(iwl_mvm_get_valid_tx_ant(mvm)) > 1) &&
(vht_cap->cap & IEEE80211_VHT_CAP_RXSTBC_MASK))
lq_sta->stbc_capable = true;
if (fw_has_capa(&mvm->fw->ucode_capa, IWL_UCODE_TLV_CAPA_BEAMFORMER) &&
(num_of_ant(iwl_mvm_get_valid_tx_ant(mvm)) > 1) &&
(vht_cap->cap & IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE))
lq_sta->bfer_capable = true;
lq_sta->is_vht = true;
}
static void iwl_mvm_reset_frame_stats(struct iwl_mvm *mvm)
{
spin_lock_bh(&mvm->drv_stats_lock);
memset(&mvm->drv_rx_stats, 0, sizeof(mvm->drv_rx_stats));
spin_unlock_bh(&mvm->drv_stats_lock);
}
void iwl_mvm_update_frame_stats(struct iwl_mvm *mvm, u32 rate, bool agg)
{
u8 nss = 0, mcs = 0;
spin_lock(&mvm->drv_stats_lock);
if (agg)
mvm->drv_rx_stats.agg_frames++;
mvm->drv_rx_stats.success_frames++;
switch (rate & RATE_MCS_CHAN_WIDTH_MSK) {
case RATE_MCS_CHAN_WIDTH_20:
mvm->drv_rx_stats.bw_20_frames++;
break;
case RATE_MCS_CHAN_WIDTH_40:
mvm->drv_rx_stats.bw_40_frames++;
break;
case RATE_MCS_CHAN_WIDTH_80:
mvm->drv_rx_stats.bw_80_frames++;
break;
default:
WARN_ONCE(1, "bad BW. rate 0x%x", rate);
}
if (rate & RATE_MCS_HT_MSK) {
mvm->drv_rx_stats.ht_frames++;
mcs = rate & RATE_HT_MCS_RATE_CODE_MSK;
nss = ((rate & RATE_HT_MCS_NSS_MSK) >> RATE_HT_MCS_NSS_POS) + 1;
} else if (rate & RATE_MCS_VHT_MSK) {
mvm->drv_rx_stats.vht_frames++;
mcs = rate & RATE_VHT_MCS_RATE_CODE_MSK;
nss = ((rate & RATE_VHT_MCS_NSS_MSK) >>
RATE_VHT_MCS_NSS_POS) + 1;
} else {
mvm->drv_rx_stats.legacy_frames++;
}
if (nss == 1)
mvm->drv_rx_stats.siso_frames++;
else if (nss == 2)
mvm->drv_rx_stats.mimo2_frames++;
if (rate & RATE_MCS_SGI_MSK)
mvm->drv_rx_stats.sgi_frames++;
else
mvm->drv_rx_stats.ngi_frames++;
mvm->drv_rx_stats.last_rates[mvm->drv_rx_stats.last_frame_idx] = rate;
mvm->drv_rx_stats.last_frame_idx =
(mvm->drv_rx_stats.last_frame_idx + 1) %
ARRAY_SIZE(mvm->drv_rx_stats.last_rates);
spin_unlock(&mvm->drv_stats_lock);
}
void iwl_mvm_rs_rate_init(struct iwl_mvm *mvm, struct ieee80211_sta *sta,
enum ieee80211_band band, bool init)
{
int i, j;
struct ieee80211_hw *hw = mvm->hw;
struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
struct iwl_mvm_sta *sta_priv = iwl_mvm_sta_from_mac80211(sta);
struct iwl_lq_sta *lq_sta = &sta_priv->lq_sta;
struct ieee80211_supported_band *sband;
unsigned long supp;
memset(lq_sta, 0, offsetof(typeof(*lq_sta), pers));
sband = hw->wiphy->bands[band];
lq_sta->lq.sta_id = sta_priv->sta_id;
for (j = 0; j < LQ_SIZE; j++)
rs_rate_scale_clear_tbl_windows(mvm, &lq_sta->lq_info[j]);
lq_sta->flush_timer = 0;
lq_sta->last_tx = jiffies;
IWL_DEBUG_RATE(mvm,
"LQ: *** rate scale station global init for station %d ***\n",
sta_priv->sta_id);
lq_sta->missed_rate_counter = IWL_MVM_RS_MISSED_RATE_MAX;
lq_sta->band = sband->band;
supp = sta->supp_rates[sband->band];
lq_sta->active_legacy_rate = 0;
for_each_set_bit(i, &supp, BITS_PER_LONG)
lq_sta->active_legacy_rate |= BIT(sband->bitrates[i].hw_value);
if (!vht_cap || !vht_cap->vht_supported)
rs_ht_init(mvm, sta, lq_sta, ht_cap);
else
rs_vht_init(mvm, sta, lq_sta, vht_cap);
if (IWL_MVM_RS_DISABLE_P2P_MIMO && sta_priv->vif->p2p)
lq_sta->active_mimo2_rate = 0;
lq_sta->max_legacy_rate_idx =
rs_get_max_rate_from_mask(lq_sta->active_legacy_rate);
lq_sta->max_siso_rate_idx =
rs_get_max_rate_from_mask(lq_sta->active_siso_rate);
lq_sta->max_mimo2_rate_idx =
rs_get_max_rate_from_mask(lq_sta->active_mimo2_rate);
IWL_DEBUG_RATE(mvm,
"LEGACY=%lX SISO=%lX MIMO2=%lX VHT=%d LDPC=%d STBC=%d BFER=%d\n",
lq_sta->active_legacy_rate,
lq_sta->active_siso_rate,
lq_sta->active_mimo2_rate,
lq_sta->is_vht, lq_sta->ldpc, lq_sta->stbc_capable,
lq_sta->bfer_capable);
IWL_DEBUG_RATE(mvm, "MAX RATE: LEGACY=%d SISO=%d MIMO2=%d\n",
lq_sta->max_legacy_rate_idx,
lq_sta->max_siso_rate_idx,
lq_sta->max_mimo2_rate_idx);
lq_sta->lq.single_stream_ant_msk =
first_antenna(iwl_mvm_get_valid_tx_ant(mvm));
lq_sta->lq.dual_stream_ant_msk = ANT_AB;
lq_sta->tx_agg_tid_en = IWL_AGG_ALL_TID;
lq_sta->is_agg = 0;
#ifdef CONFIG_IWLWIFI_DEBUGFS
iwl_mvm_reset_frame_stats(mvm);
#endif
rs_initialize_lq(mvm, sta, lq_sta, band, init);
}
static void rs_rate_update(void *mvm_r,
struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *priv_sta,
u32 changed)
{
u8 tid;
struct iwl_op_mode *op_mode =
(struct iwl_op_mode *)mvm_r;
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
if (!iwl_mvm_sta_from_mac80211(sta)->vif)
return;
for (tid = 0; tid < IWL_MAX_TID_COUNT; tid++)
ieee80211_stop_tx_ba_session(sta, tid);
iwl_mvm_rs_rate_init(mvm, sta, sband->band, false);
}
static void rs_build_rates_table_from_fixed(struct iwl_mvm *mvm,
struct iwl_lq_cmd *lq_cmd,
enum ieee80211_band band,
u32 ucode_rate)
{
struct rs_rate rate;
int i;
int num_rates = ARRAY_SIZE(lq_cmd->rs_table);
__le32 ucode_rate_le32 = cpu_to_le32(ucode_rate);
u8 ant = (ucode_rate & RATE_MCS_ANT_ABC_MSK) >> RATE_MCS_ANT_POS;
for (i = 0; i < num_rates; i++)
lq_cmd->rs_table[i] = ucode_rate_le32;
rs_rate_from_ucode_rate(ucode_rate, band, &rate);
if (is_mimo(&rate))
lq_cmd->mimo_delim = num_rates - 1;
else
lq_cmd->mimo_delim = 0;
lq_cmd->reduced_tpc = 0;
if (num_of_ant(ant) == 1)
lq_cmd->single_stream_ant_msk = ant;
lq_cmd->agg_frame_cnt_limit = LINK_QUAL_AGG_FRAME_LIMIT_DEF;
}
static void rs_fill_rates_for_column(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta,
struct rs_rate *rate,
__le32 *rs_table, int *rs_table_index,
int num_rates, int num_retries,
u8 valid_tx_ant, bool toggle_ant)
{
int i, j;
__le32 ucode_rate;
bool bottom_reached = false;
int prev_rate_idx = rate->index;
int end = LINK_QUAL_MAX_RETRY_NUM;
int index = *rs_table_index;
for (i = 0; i < num_rates && index < end; i++) {
for (j = 0; j < num_retries && index < end; j++, index++) {
ucode_rate = cpu_to_le32(ucode_rate_from_rs_rate(mvm,
rate));
rs_table[index] = ucode_rate;
if (toggle_ant)
rs_toggle_antenna(valid_tx_ant, rate);
}
prev_rate_idx = rate->index;
bottom_reached = rs_get_lower_rate_in_column(lq_sta, rate);
if (bottom_reached && !is_legacy(rate))
break;
}
if (!bottom_reached && !is_legacy(rate))
rate->index = prev_rate_idx;
*rs_table_index = index;
}
static void rs_build_rates_table(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
const struct rs_rate *initial_rate)
{
struct rs_rate rate;
int num_rates, num_retries, index = 0;
u8 valid_tx_ant = 0;
struct iwl_lq_cmd *lq_cmd = &lq_sta->lq;
bool toggle_ant = false;
memcpy(&rate, initial_rate, sizeof(rate));
valid_tx_ant = iwl_mvm_get_valid_tx_ant(mvm);
if (!fw_has_api(&mvm->fw->ucode_capa, IWL_UCODE_TLV_API_LQ_SS_PARAMS) &&
rs_stbc_allow(mvm, sta, lq_sta))
rate.stbc = true;
if (is_siso(&rate)) {
num_rates = IWL_MVM_RS_INITIAL_SISO_NUM_RATES;
num_retries = IWL_MVM_RS_HT_VHT_RETRIES_PER_RATE;
} else if (is_mimo(&rate)) {
num_rates = IWL_MVM_RS_INITIAL_MIMO_NUM_RATES;
num_retries = IWL_MVM_RS_HT_VHT_RETRIES_PER_RATE;
} else {
num_rates = IWL_MVM_RS_INITIAL_LEGACY_NUM_RATES;
num_retries = IWL_MVM_RS_INITIAL_LEGACY_RETRIES;
toggle_ant = true;
}
rs_fill_rates_for_column(mvm, lq_sta, &rate, lq_cmd->rs_table, &index,
num_rates, num_retries, valid_tx_ant,
toggle_ant);
rs_get_lower_rate_down_column(lq_sta, &rate);
if (is_siso(&rate)) {
num_rates = IWL_MVM_RS_SECONDARY_SISO_NUM_RATES;
num_retries = IWL_MVM_RS_SECONDARY_SISO_RETRIES;
lq_cmd->mimo_delim = index;
} else if (is_legacy(&rate)) {
num_rates = IWL_MVM_RS_SECONDARY_LEGACY_NUM_RATES;
num_retries = IWL_MVM_RS_SECONDARY_LEGACY_RETRIES;
} else {
WARN_ON_ONCE(1);
}
toggle_ant = true;
rs_fill_rates_for_column(mvm, lq_sta, &rate, lq_cmd->rs_table, &index,
num_rates, num_retries, valid_tx_ant,
toggle_ant);
rs_get_lower_rate_down_column(lq_sta, &rate);
num_rates = IWL_MVM_RS_SECONDARY_LEGACY_NUM_RATES;
num_retries = IWL_MVM_RS_SECONDARY_LEGACY_RETRIES;
rs_fill_rates_for_column(mvm, lq_sta, &rate, lq_cmd->rs_table, &index,
num_rates, num_retries, valid_tx_ant,
toggle_ant);
}
static void rs_bfer_active_iter(void *_data,
struct ieee80211_sta *sta)
{
struct rs_bfer_active_iter_data *data = _data;
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct iwl_lq_cmd *lq_cmd = &mvmsta->lq_sta.lq;
u32 ss_params = le32_to_cpu(lq_cmd->ss_params);
if (sta == data->exclude_sta)
return;
if (ss_params & LQ_SS_BFER_ALLOWED) {
WARN_ON_ONCE(data->bfer_mvmsta != NULL);
data->bfer_mvmsta = mvmsta;
}
}
static int rs_bfer_priority(struct iwl_mvm_sta *sta)
{
int prio = -1;
enum nl80211_iftype viftype = ieee80211_vif_type_p2p(sta->vif);
switch (viftype) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_P2P_GO:
prio = 3;
break;
case NL80211_IFTYPE_P2P_CLIENT:
prio = 2;
break;
case NL80211_IFTYPE_STATION:
prio = 1;
break;
default:
WARN_ONCE(true, "viftype %d sta_id %d", viftype, sta->sta_id);
prio = -1;
}
return prio;
}
static int rs_bfer_priority_cmp(struct iwl_mvm_sta *sta1,
struct iwl_mvm_sta *sta2)
{
int prio1 = rs_bfer_priority(sta1);
int prio2 = rs_bfer_priority(sta2);
if (prio1 > prio2)
return 1;
if (prio1 < prio2)
return -1;
return 0;
}
static void rs_set_lq_ss_params(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
const struct rs_rate *initial_rate)
{
struct iwl_lq_cmd *lq_cmd = &lq_sta->lq;
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct rs_bfer_active_iter_data data = {
.exclude_sta = sta,
.bfer_mvmsta = NULL,
};
struct iwl_mvm_sta *bfer_mvmsta = NULL;
u32 ss_params = LQ_SS_PARAMS_VALID;
if (!iwl_mvm_bt_coex_is_mimo_allowed(mvm, sta))
goto out;
#ifdef CONFIG_MAC80211_DEBUGFS
if (lq_sta->pers.ss_force == RS_SS_FORCE_STBC)
ss_params |= (LQ_SS_STBC_1SS_ALLOWED | LQ_SS_FORCE);
else if (lq_sta->pers.ss_force == RS_SS_FORCE_BFER)
ss_params |= (LQ_SS_BFER_ALLOWED | LQ_SS_FORCE);
if (lq_sta->pers.ss_force != RS_SS_FORCE_NONE) {
IWL_DEBUG_RATE(mvm, "Forcing single stream Tx decision %d\n",
lq_sta->pers.ss_force);
goto out;
}
#endif
if (lq_sta->stbc_capable)
ss_params |= LQ_SS_STBC_1SS_ALLOWED;
if (!lq_sta->bfer_capable)
goto out;
ieee80211_iterate_stations_atomic(mvm->hw,
rs_bfer_active_iter,
&data);
bfer_mvmsta = data.bfer_mvmsta;
if (!bfer_mvmsta) {
IWL_DEBUG_RATE(mvm, "No sta with BFER allowed found. Allow\n");
ss_params |= LQ_SS_BFER_ALLOWED;
goto out;
}
IWL_DEBUG_RATE(mvm, "Found existing sta %d with BFER activated\n",
bfer_mvmsta->sta_id);
if (rs_bfer_priority_cmp(mvmsta, bfer_mvmsta) > 0) {
struct iwl_lq_cmd *bfersta_lq_cmd = &bfer_mvmsta->lq_sta.lq;
u32 bfersta_ss_params = le32_to_cpu(bfersta_lq_cmd->ss_params);
bfersta_ss_params &= ~LQ_SS_BFER_ALLOWED;
bfersta_lq_cmd->ss_params = cpu_to_le32(bfersta_ss_params);
iwl_mvm_send_lq_cmd(mvm, bfersta_lq_cmd, false);
ss_params |= LQ_SS_BFER_ALLOWED;
IWL_DEBUG_RATE(mvm,
"Lower priority BFER sta found (%d). Switch BFER\n",
bfer_mvmsta->sta_id);
}
out:
lq_cmd->ss_params = cpu_to_le32(ss_params);
}
static void rs_fill_lq_cmd(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct iwl_lq_sta *lq_sta,
const struct rs_rate *initial_rate)
{
struct iwl_lq_cmd *lq_cmd = &lq_sta->lq;
struct iwl_mvm_sta *mvmsta;
struct iwl_mvm_vif *mvmvif;
lq_cmd->agg_disable_start_th = IWL_MVM_RS_AGG_DISABLE_START;
lq_cmd->agg_time_limit =
cpu_to_le16(IWL_MVM_RS_AGG_TIME_LIMIT);
#ifdef CONFIG_MAC80211_DEBUGFS
if (lq_sta->pers.dbg_fixed_rate) {
rs_build_rates_table_from_fixed(mvm, lq_cmd,
lq_sta->band,
lq_sta->pers.dbg_fixed_rate);
return;
}
#endif
if (WARN_ON_ONCE(!sta || !initial_rate))
return;
rs_build_rates_table(mvm, sta, lq_sta, initial_rate);
if (fw_has_api(&mvm->fw->ucode_capa, IWL_UCODE_TLV_API_LQ_SS_PARAMS))
rs_set_lq_ss_params(mvm, sta, lq_sta, initial_rate);
mvmsta = iwl_mvm_sta_from_mac80211(sta);
mvmvif = iwl_mvm_vif_from_mac80211(mvmsta->vif);
if (num_of_ant(initial_rate->ant) == 1)
lq_cmd->single_stream_ant_msk = initial_rate->ant;
lq_cmd->agg_frame_cnt_limit = mvmsta->max_agg_bufsize;
if (iwl_mvm_vif_low_latency(mvmvif)) {
lq_cmd->agg_frame_cnt_limit--;
if (mvm->low_latency_agg_frame_limit)
lq_cmd->agg_frame_cnt_limit =
min(lq_cmd->agg_frame_cnt_limit,
mvm->low_latency_agg_frame_limit);
}
if (mvmsta->vif->p2p)
lq_cmd->flags |= LQ_FLAG_USE_RTS_MSK;
lq_cmd->agg_time_limit =
cpu_to_le16(iwl_mvm_coex_agg_time_limit(mvm, sta));
}
static void *rs_alloc(struct ieee80211_hw *hw, struct dentry *debugfsdir)
{
return hw->priv;
}
static void rs_free(void *mvm_rate)
{
return;
}
static void rs_free_sta(void *mvm_r, struct ieee80211_sta *sta,
void *mvm_sta)
{
struct iwl_op_mode *op_mode __maybe_unused = mvm_r;
struct iwl_mvm *mvm __maybe_unused = IWL_OP_MODE_GET_MVM(op_mode);
IWL_DEBUG_RATE(mvm, "enter\n");
IWL_DEBUG_RATE(mvm, "leave\n");
}
int rs_pretty_print_rate(char *buf, const u32 rate)
{
char *type, *bw;
u8 mcs = 0, nss = 0;
u8 ant = (rate & RATE_MCS_ANT_ABC_MSK) >> RATE_MCS_ANT_POS;
if (!(rate & RATE_MCS_HT_MSK) &&
!(rate & RATE_MCS_VHT_MSK)) {
int index = iwl_hwrate_to_plcp_idx(rate);
return sprintf(buf, "Legacy | ANT: %s Rate: %s Mbps\n",
rs_pretty_ant(ant),
index == IWL_RATE_INVALID ? "BAD" :
iwl_rate_mcs[index].mbps);
}
if (rate & RATE_MCS_VHT_MSK) {
type = "VHT";
mcs = rate & RATE_VHT_MCS_RATE_CODE_MSK;
nss = ((rate & RATE_VHT_MCS_NSS_MSK)
>> RATE_VHT_MCS_NSS_POS) + 1;
} else if (rate & RATE_MCS_HT_MSK) {
type = "HT";
mcs = rate & RATE_HT_MCS_INDEX_MSK;
} else {
type = "Unknown";
}
switch (rate & RATE_MCS_CHAN_WIDTH_MSK) {
case RATE_MCS_CHAN_WIDTH_20:
bw = "20Mhz";
break;
case RATE_MCS_CHAN_WIDTH_40:
bw = "40Mhz";
break;
case RATE_MCS_CHAN_WIDTH_80:
bw = "80Mhz";
break;
case RATE_MCS_CHAN_WIDTH_160:
bw = "160Mhz";
break;
default:
bw = "BAD BW";
}
return sprintf(buf, "%s | ANT: %s BW: %s MCS: %d NSS: %d %s%s%s%s%s\n",
type, rs_pretty_ant(ant), bw, mcs, nss,
(rate & RATE_MCS_SGI_MSK) ? "SGI " : "NGI ",
(rate & RATE_MCS_HT_STBC_MSK) ? "STBC " : "",
(rate & RATE_MCS_LDPC_MSK) ? "LDPC " : "",
(rate & RATE_MCS_BF_MSK) ? "BF " : "",
(rate & RATE_MCS_ZLF_MSK) ? "ZLF " : "");
}
static void rs_program_fix_rate(struct iwl_mvm *mvm,
struct iwl_lq_sta *lq_sta)
{
lq_sta->active_legacy_rate = 0x0FFF;
lq_sta->active_siso_rate = 0x1FD0;
lq_sta->active_mimo2_rate = 0x1FD0;
IWL_DEBUG_RATE(mvm, "sta_id %d rate 0x%X\n",
lq_sta->lq.sta_id, lq_sta->pers.dbg_fixed_rate);
if (lq_sta->pers.dbg_fixed_rate) {
rs_fill_lq_cmd(mvm, NULL, lq_sta, NULL);
iwl_mvm_send_lq_cmd(lq_sta->pers.drv, &lq_sta->lq, false);
}
}
static ssize_t rs_sta_dbgfs_scale_table_write(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
struct iwl_lq_sta *lq_sta = file->private_data;
struct iwl_mvm *mvm;
char buf[64];
size_t buf_size;
u32 parsed_rate;
mvm = lq_sta->pers.drv;
memset(buf, 0, sizeof(buf));
buf_size = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
if (sscanf(buf, "%x", &parsed_rate) == 1)
lq_sta->pers.dbg_fixed_rate = parsed_rate;
else
lq_sta->pers.dbg_fixed_rate = 0;
rs_program_fix_rate(mvm, lq_sta);
return count;
}
static ssize_t rs_sta_dbgfs_scale_table_read(struct file *file,
char __user *user_buf, size_t count, loff_t *ppos)
{
char *buff;
int desc = 0;
int i = 0;
ssize_t ret;
struct iwl_lq_sta *lq_sta = file->private_data;
struct iwl_mvm *mvm;
struct iwl_scale_tbl_info *tbl = &(lq_sta->lq_info[lq_sta->active_tbl]);
struct rs_rate *rate = &tbl->rate;
u32 ss_params;
mvm = lq_sta->pers.drv;
buff = kmalloc(2048, GFP_KERNEL);
if (!buff)
return -ENOMEM;
desc += sprintf(buff+desc, "sta_id %d\n", lq_sta->lq.sta_id);
desc += sprintf(buff+desc, "failed=%d success=%d rate=0%lX\n",
lq_sta->total_failed, lq_sta->total_success,
lq_sta->active_legacy_rate);
desc += sprintf(buff+desc, "fixed rate 0x%X\n",
lq_sta->pers.dbg_fixed_rate);
desc += sprintf(buff+desc, "valid_tx_ant %s%s%s\n",
(iwl_mvm_get_valid_tx_ant(mvm) & ANT_A) ? "ANT_A," : "",
(iwl_mvm_get_valid_tx_ant(mvm) & ANT_B) ? "ANT_B," : "",
(iwl_mvm_get_valid_tx_ant(mvm) & ANT_C) ? "ANT_C" : "");
desc += sprintf(buff+desc, "lq type %s\n",
(is_legacy(rate)) ? "legacy" :
is_vht(rate) ? "VHT" : "HT");
if (!is_legacy(rate)) {
desc += sprintf(buff + desc, " %s",
(is_siso(rate)) ? "SISO" : "MIMO2");
desc += sprintf(buff + desc, " %s",
(is_ht20(rate)) ? "20MHz" :
(is_ht40(rate)) ? "40MHz" :
(is_ht80(rate)) ? "80Mhz" : "BAD BW");
desc += sprintf(buff + desc, " %s %s %s\n",
(rate->sgi) ? "SGI" : "NGI",
(rate->ldpc) ? "LDPC" : "BCC",
(lq_sta->is_agg) ? "AGG on" : "");
}
desc += sprintf(buff+desc, "last tx rate=0x%X\n",
lq_sta->last_rate_n_flags);
desc += sprintf(buff+desc,
"general: flags=0x%X mimo-d=%d s-ant=0x%x d-ant=0x%x\n",
lq_sta->lq.flags,
lq_sta->lq.mimo_delim,
lq_sta->lq.single_stream_ant_msk,
lq_sta->lq.dual_stream_ant_msk);
desc += sprintf(buff+desc,
"agg: time_limit=%d dist_start_th=%d frame_cnt_limit=%d\n",
le16_to_cpu(lq_sta->lq.agg_time_limit),
lq_sta->lq.agg_disable_start_th,
lq_sta->lq.agg_frame_cnt_limit);
desc += sprintf(buff+desc, "reduced tpc=%d\n", lq_sta->lq.reduced_tpc);
ss_params = le32_to_cpu(lq_sta->lq.ss_params);
desc += sprintf(buff+desc, "single stream params: %s%s%s%s\n",
(ss_params & LQ_SS_PARAMS_VALID) ?
"VALID" : "INVALID",
(ss_params & LQ_SS_BFER_ALLOWED) ?
", BFER" : "",
(ss_params & LQ_SS_STBC_1SS_ALLOWED) ?
", STBC" : "",
(ss_params & LQ_SS_FORCE) ?
", FORCE" : "");
desc += sprintf(buff+desc,
"Start idx [0]=0x%x [1]=0x%x [2]=0x%x [3]=0x%x\n",
lq_sta->lq.initial_rate_index[0],
lq_sta->lq.initial_rate_index[1],
lq_sta->lq.initial_rate_index[2],
lq_sta->lq.initial_rate_index[3]);
for (i = 0; i < LINK_QUAL_MAX_RETRY_NUM; i++) {
u32 r = le32_to_cpu(lq_sta->lq.rs_table[i]);
desc += sprintf(buff+desc, " rate[%d] 0x%X ", i, r);
desc += rs_pretty_print_rate(buff+desc, r);
}
ret = simple_read_from_buffer(user_buf, count, ppos, buff, desc);
kfree(buff);
return ret;
}
static ssize_t rs_sta_dbgfs_stats_table_read(struct file *file,
char __user *user_buf, size_t count, loff_t *ppos)
{
char *buff;
int desc = 0;
int i, j;
ssize_t ret;
struct iwl_scale_tbl_info *tbl;
struct rs_rate *rate;
struct iwl_lq_sta *lq_sta = file->private_data;
buff = kmalloc(1024, GFP_KERNEL);
if (!buff)
return -ENOMEM;
for (i = 0; i < LQ_SIZE; i++) {
tbl = &(lq_sta->lq_info[i]);
rate = &tbl->rate;
desc += sprintf(buff+desc,
"%s type=%d SGI=%d BW=%s DUP=0\n"
"index=%d\n",
lq_sta->active_tbl == i ? "*" : "x",
rate->type,
rate->sgi,
is_ht20(rate) ? "20Mhz" :
is_ht40(rate) ? "40Mhz" :
is_ht80(rate) ? "80Mhz" : "ERR",
rate->index);
for (j = 0; j < IWL_RATE_COUNT; j++) {
desc += sprintf(buff+desc,
"counter=%d success=%d %%=%d\n",
tbl->win[j].counter,
tbl->win[j].success_counter,
tbl->win[j].success_ratio);
}
}
ret = simple_read_from_buffer(user_buf, count, ppos, buff, desc);
kfree(buff);
return ret;
}
static ssize_t rs_sta_dbgfs_drv_tx_stats_read(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
static const char * const column_name[] = {
[RS_COLUMN_LEGACY_ANT_A] = "LEGACY_ANT_A",
[RS_COLUMN_LEGACY_ANT_B] = "LEGACY_ANT_B",
[RS_COLUMN_SISO_ANT_A] = "SISO_ANT_A",
[RS_COLUMN_SISO_ANT_B] = "SISO_ANT_B",
[RS_COLUMN_SISO_ANT_A_SGI] = "SISO_ANT_A_SGI",
[RS_COLUMN_SISO_ANT_B_SGI] = "SISO_ANT_B_SGI",
[RS_COLUMN_MIMO2] = "MIMO2",
[RS_COLUMN_MIMO2_SGI] = "MIMO2_SGI",
};
static const char * const rate_name[] = {
[IWL_RATE_1M_INDEX] = "1M",
[IWL_RATE_2M_INDEX] = "2M",
[IWL_RATE_5M_INDEX] = "5.5M",
[IWL_RATE_11M_INDEX] = "11M",
[IWL_RATE_6M_INDEX] = "6M|MCS0",
[IWL_RATE_9M_INDEX] = "9M",
[IWL_RATE_12M_INDEX] = "12M|MCS1",
[IWL_RATE_18M_INDEX] = "18M|MCS2",
[IWL_RATE_24M_INDEX] = "24M|MCS3",
[IWL_RATE_36M_INDEX] = "36M|MCS4",
[IWL_RATE_48M_INDEX] = "48M|MCS5",
[IWL_RATE_54M_INDEX] = "54M|MCS6",
[IWL_RATE_MCS_7_INDEX] = "MCS7",
[IWL_RATE_MCS_8_INDEX] = "MCS8",
[IWL_RATE_MCS_9_INDEX] = "MCS9",
};
char *buff, *pos, *endpos;
int col, rate;
ssize_t ret;
struct iwl_lq_sta *lq_sta = file->private_data;
struct rs_rate_stats *stats;
static const size_t bufsz = 1024;
buff = kmalloc(bufsz, GFP_KERNEL);
if (!buff)
return -ENOMEM;
pos = buff;
endpos = pos + bufsz;
pos += scnprintf(pos, endpos - pos, "COLUMN,");
for (rate = 0; rate < IWL_RATE_COUNT; rate++)
pos += scnprintf(pos, endpos - pos, "%s,", rate_name[rate]);
pos += scnprintf(pos, endpos - pos, "\n");
for (col = 0; col < RS_COLUMN_COUNT; col++) {
pos += scnprintf(pos, endpos - pos,
"%s,", column_name[col]);
for (rate = 0; rate < IWL_RATE_COUNT; rate++) {
stats = &(lq_sta->pers.tx_stats[col][rate]);
pos += scnprintf(pos, endpos - pos,
"%llu/%llu,",
stats->success,
stats->total);
}
pos += scnprintf(pos, endpos - pos, "\n");
}
ret = simple_read_from_buffer(user_buf, count, ppos, buff, pos - buff);
kfree(buff);
return ret;
}
static ssize_t rs_sta_dbgfs_drv_tx_stats_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct iwl_lq_sta *lq_sta = file->private_data;
memset(lq_sta->pers.tx_stats, 0, sizeof(lq_sta->pers.tx_stats));
return count;
}
static ssize_t iwl_dbgfs_ss_force_read(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct iwl_lq_sta *lq_sta = file->private_data;
char buf[12];
int bufsz = sizeof(buf);
int pos = 0;
static const char * const ss_force_name[] = {
[RS_SS_FORCE_NONE] = "none",
[RS_SS_FORCE_STBC] = "stbc",
[RS_SS_FORCE_BFER] = "bfer",
[RS_SS_FORCE_SISO] = "siso",
};
pos += scnprintf(buf+pos, bufsz-pos, "%s\n",
ss_force_name[lq_sta->pers.ss_force]);
return simple_read_from_buffer(user_buf, count, ppos, buf, pos);
}
static ssize_t iwl_dbgfs_ss_force_write(struct iwl_lq_sta *lq_sta, char *buf,
size_t count, loff_t *ppos)
{
struct iwl_mvm *mvm = lq_sta->pers.drv;
int ret = 0;
if (!strncmp("none", buf, 4)) {
lq_sta->pers.ss_force = RS_SS_FORCE_NONE;
} else if (!strncmp("siso", buf, 4)) {
lq_sta->pers.ss_force = RS_SS_FORCE_SISO;
} else if (!strncmp("stbc", buf, 4)) {
if (lq_sta->stbc_capable) {
lq_sta->pers.ss_force = RS_SS_FORCE_STBC;
} else {
IWL_ERR(mvm,
"can't force STBC. peer doesn't support\n");
ret = -EINVAL;
}
} else if (!strncmp("bfer", buf, 4)) {
if (lq_sta->bfer_capable) {
lq_sta->pers.ss_force = RS_SS_FORCE_BFER;
} else {
IWL_ERR(mvm,
"can't force BFER. peer doesn't support\n");
ret = -EINVAL;
}
} else {
IWL_ERR(mvm, "valid values none|siso|stbc|bfer\n");
ret = -EINVAL;
}
return ret ?: count;
}
static void rs_add_debugfs(void *mvm, void *priv_sta, struct dentry *dir)
{
struct iwl_lq_sta *lq_sta = priv_sta;
struct iwl_mvm_sta *mvmsta;
mvmsta = container_of(lq_sta, struct iwl_mvm_sta, lq_sta);
if (!mvmsta->vif)
return;
debugfs_create_file("rate_scale_table", S_IRUSR | S_IWUSR, dir,
lq_sta, &rs_sta_dbgfs_scale_table_ops);
debugfs_create_file("rate_stats_table", S_IRUSR, dir,
lq_sta, &rs_sta_dbgfs_stats_table_ops);
debugfs_create_file("drv_tx_stats", S_IRUSR | S_IWUSR, dir,
lq_sta, &rs_sta_dbgfs_drv_tx_stats_ops);
debugfs_create_u8("tx_agg_tid_enable", S_IRUSR | S_IWUSR, dir,
&lq_sta->tx_agg_tid_en);
debugfs_create_u8("reduced_tpc", S_IRUSR | S_IWUSR, dir,
&lq_sta->pers.dbg_fixed_txp_reduction);
MVM_DEBUGFS_ADD_FILE_RS(ss_force, dir, S_IRUSR | S_IWUSR);
return;
err:
IWL_ERR((struct iwl_mvm *)mvm, "Can't create debugfs entity\n");
}
static void rs_remove_debugfs(void *mvm, void *mvm_sta)
{
}
static void rs_rate_init_stub(void *mvm_r,
struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *mvm_sta)
{
}
int iwl_mvm_rate_control_register(void)
{
return ieee80211_rate_control_register(&rs_mvm_ops);
}
void iwl_mvm_rate_control_unregister(void)
{
ieee80211_rate_control_unregister(&rs_mvm_ops);
}
int iwl_mvm_tx_protection(struct iwl_mvm *mvm, struct iwl_mvm_sta *mvmsta,
bool enable)
{
struct iwl_lq_cmd *lq = &mvmsta->lq_sta.lq;
lockdep_assert_held(&mvm->mutex);
if (enable) {
if (mvmsta->tx_protection == 0)
lq->flags |= LQ_FLAG_USE_RTS_MSK;
mvmsta->tx_protection++;
} else {
mvmsta->tx_protection--;
if (mvmsta->tx_protection == 0)
lq->flags &= ~LQ_FLAG_USE_RTS_MSK;
}
return iwl_mvm_send_lq_cmd(mvm, lq, false);
}
