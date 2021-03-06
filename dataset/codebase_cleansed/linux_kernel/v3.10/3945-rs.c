static u8
il3945_get_rate_idx_by_rssi(s32 rssi, enum ieee80211_band band)
{
u32 idx = 0;
u32 table_size = 0;
struct il3945_tpt_entry *tpt_table = NULL;
if (rssi < IL_MIN_RSSI_VAL || rssi > IL_MAX_RSSI_VAL)
rssi = IL_MIN_RSSI_VAL;
switch (band) {
case IEEE80211_BAND_2GHZ:
tpt_table = il3945_tpt_table_g;
table_size = ARRAY_SIZE(il3945_tpt_table_g);
break;
case IEEE80211_BAND_5GHZ:
tpt_table = il3945_tpt_table_a;
table_size = ARRAY_SIZE(il3945_tpt_table_a);
break;
default:
BUG();
break;
}
while (idx < table_size && rssi < tpt_table[idx].min_rssi)
idx++;
idx = min(idx, table_size - 1);
return tpt_table[idx].idx;
}
static void
il3945_clear_win(struct il3945_rate_scale_data *win)
{
win->data = 0;
win->success_counter = 0;
win->success_ratio = -1;
win->counter = 0;
win->average_tpt = IL_INVALID_VALUE;
win->stamp = 0;
}
static int
il3945_rate_scale_flush_wins(struct il3945_rs_sta *rs_sta)
{
int unflushed = 0;
int i;
unsigned long flags;
struct il_priv *il __maybe_unused = rs_sta->il;
for (i = 0; i < RATE_COUNT_3945; i++) {
if (!rs_sta->win[i].counter)
continue;
spin_lock_irqsave(&rs_sta->lock, flags);
if (time_after(jiffies, rs_sta->win[i].stamp + RATE_WIN_FLUSH)) {
D_RATE("flushing %d samples of rate " "idx %d\n",
rs_sta->win[i].counter, i);
il3945_clear_win(&rs_sta->win[i]);
} else
unflushed++;
spin_unlock_irqrestore(&rs_sta->lock, flags);
}
return unflushed;
}
static void
il3945_bg_rate_scale_flush(unsigned long data)
{
struct il3945_rs_sta *rs_sta = (void *)data;
struct il_priv *il __maybe_unused = rs_sta->il;
int unflushed = 0;
unsigned long flags;
u32 packet_count, duration, pps;
D_RATE("enter\n");
unflushed = il3945_rate_scale_flush_wins(rs_sta);
spin_lock_irqsave(&rs_sta->lock, flags);
packet_count = (rs_sta->tx_packets - rs_sta->last_tx_packets) + 1;
rs_sta->last_tx_packets = rs_sta->tx_packets + 1;
if (unflushed) {
duration =
jiffies_to_msecs(jiffies - rs_sta->last_partial_flush);
D_RATE("Tx'd %d packets in %dms\n", packet_count, duration);
if (duration)
pps = (packet_count * 1000) / duration;
else
pps = 0;
if (pps) {
duration = (IL_AVERAGE_PACKETS * 1000) / pps;
if (duration < RATE_FLUSH_MIN)
duration = RATE_FLUSH_MIN;
else if (duration > RATE_FLUSH_MAX)
duration = RATE_FLUSH_MAX;
} else
duration = RATE_FLUSH_MAX;
rs_sta->flush_time = msecs_to_jiffies(duration);
D_RATE("new flush period: %d msec ave %d\n", duration,
packet_count);
mod_timer(&rs_sta->rate_scale_flush,
jiffies + rs_sta->flush_time);
rs_sta->last_partial_flush = jiffies;
} else {
rs_sta->flush_time = RATE_FLUSH;
rs_sta->flush_pending = 0;
}
rs_sta->last_flush = jiffies;
spin_unlock_irqrestore(&rs_sta->lock, flags);
D_RATE("leave\n");
}
static void
il3945_collect_tx_data(struct il3945_rs_sta *rs_sta,
struct il3945_rate_scale_data *win, int success,
int retries, int idx)
{
unsigned long flags;
s32 fail_count;
struct il_priv *il __maybe_unused = rs_sta->il;
if (!retries) {
D_RATE("leave: retries == 0 -- should be at least 1\n");
return;
}
spin_lock_irqsave(&rs_sta->lock, flags);
while (retries > 0) {
if (win->counter >= RATE_MAX_WINDOW) {
win->counter = RATE_MAX_WINDOW - 1;
if (win->data & (1ULL << (RATE_MAX_WINDOW - 1))) {
win->data &= ~(1ULL << (RATE_MAX_WINDOW - 1));
win->success_counter--;
}
}
win->counter++;
win->data <<= 1;
if (success > 0) {
win->success_counter++;
win->data |= 0x1;
success--;
}
retries--;
}
if (win->counter > 0)
win->success_ratio =
128 * (100 * win->success_counter) / win->counter;
else
win->success_ratio = IL_INVALID_VALUE;
fail_count = win->counter - win->success_counter;
if (fail_count >= RATE_MIN_FAILURE_TH ||
win->success_counter >= RATE_MIN_SUCCESS_TH)
win->average_tpt =
((win->success_ratio * rs_sta->expected_tpt[idx] +
64) / 128);
else
win->average_tpt = IL_INVALID_VALUE;
win->stamp = jiffies;
spin_unlock_irqrestore(&rs_sta->lock, flags);
}
void
il3945_rs_rate_init(struct il_priv *il, struct ieee80211_sta *sta, u8 sta_id)
{
struct ieee80211_hw *hw = il->hw;
struct ieee80211_conf *conf = &il->hw->conf;
struct il3945_sta_priv *psta;
struct il3945_rs_sta *rs_sta;
struct ieee80211_supported_band *sband;
int i;
D_INFO("enter\n");
if (sta_id == il->hw_params.bcast_id)
goto out;
psta = (struct il3945_sta_priv *)sta->drv_priv;
rs_sta = &psta->rs_sta;
sband = hw->wiphy->bands[conf->chandef.chan->band];
rs_sta->il = il;
rs_sta->start_rate = RATE_INVALID;
rs_sta->expected_tpt = il3945_expected_tpt_b;
rs_sta->last_partial_flush = jiffies;
rs_sta->last_flush = jiffies;
rs_sta->flush_time = RATE_FLUSH;
rs_sta->last_tx_packets = 0;
rs_sta->rate_scale_flush.data = (unsigned long)rs_sta;
rs_sta->rate_scale_flush.function = il3945_bg_rate_scale_flush;
for (i = 0; i < RATE_COUNT_3945; i++)
il3945_clear_win(&rs_sta->win[i]);
for (i = sband->n_bitrates - 1; i >= 0; i--) {
if (sta->supp_rates[sband->band] & (1 << i)) {
rs_sta->last_txrate_idx = i;
break;
}
}
il->_3945.sta_supp_rates = sta->supp_rates[sband->band];
if (sband->band == IEEE80211_BAND_5GHZ) {
rs_sta->last_txrate_idx += IL_FIRST_OFDM_RATE;
il->_3945.sta_supp_rates <<= IL_FIRST_OFDM_RATE;
}
out:
il->stations[sta_id].used &= ~IL_STA_UCODE_INPROGRESS;
D_INFO("leave\n");
}
static void *
il3945_rs_alloc(struct ieee80211_hw *hw, struct dentry *debugfsdir)
{
return hw->priv;
}
static void
il3945_rs_free(void *il)
{
}
static void *
il3945_rs_alloc_sta(void *il_priv, struct ieee80211_sta *sta, gfp_t gfp)
{
struct il3945_rs_sta *rs_sta;
struct il3945_sta_priv *psta = (void *)sta->drv_priv;
struct il_priv *il __maybe_unused = il_priv;
D_RATE("enter\n");
rs_sta = &psta->rs_sta;
spin_lock_init(&rs_sta->lock);
init_timer(&rs_sta->rate_scale_flush);
D_RATE("leave\n");
return rs_sta;
}
static void
il3945_rs_free_sta(void *il_priv, struct ieee80211_sta *sta, void *il_sta)
{
struct il3945_rs_sta *rs_sta = il_sta;
del_timer_sync(&rs_sta->rate_scale_flush);
}
static void
il3945_rs_tx_status(void *il_rate, struct ieee80211_supported_band *sband,
struct ieee80211_sta *sta, void *il_sta,
struct sk_buff *skb)
{
s8 retries = 0, current_count;
int scale_rate_idx, first_idx, last_idx;
unsigned long flags;
struct il_priv *il = (struct il_priv *)il_rate;
struct il3945_rs_sta *rs_sta = il_sta;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
D_RATE("enter\n");
retries = info->status.rates[0].count;
if (retries > RATE_RETRY_TH)
retries = RATE_RETRY_TH;
first_idx = sband->bitrates[info->status.rates[0].idx].hw_value;
if (first_idx < 0 || first_idx >= RATE_COUNT_3945) {
D_RATE("leave: Rate out of bounds: %d\n", first_idx);
return;
}
if (!il_sta) {
D_RATE("leave: No STA il data to update!\n");
return;
}
if (!rs_sta->il) {
D_RATE("leave: STA il data uninitialized!\n");
return;
}
rs_sta->tx_packets++;
scale_rate_idx = first_idx;
last_idx = first_idx;
while (retries > 1) {
if ((retries - 1) < il->retry_rate) {
current_count = (retries - 1);
last_idx = scale_rate_idx;
} else {
current_count = il->retry_rate;
last_idx = il3945_rs_next_rate(il, scale_rate_idx);
}
il3945_collect_tx_data(rs_sta, &rs_sta->win[scale_rate_idx], 0,
current_count, scale_rate_idx);
D_RATE("Update rate %d for %d retries.\n", scale_rate_idx,
current_count);
retries -= current_count;
scale_rate_idx = last_idx;
}
D_RATE("Update rate %d with %s.\n", last_idx,
(info->flags & IEEE80211_TX_STAT_ACK) ? "success" : "failure");
il3945_collect_tx_data(rs_sta, &rs_sta->win[last_idx],
info->flags & IEEE80211_TX_STAT_ACK, 1,
last_idx);
spin_lock_irqsave(&rs_sta->lock, flags);
if (!rs_sta->flush_pending &&
time_after(jiffies, rs_sta->last_flush + rs_sta->flush_time)) {
rs_sta->last_partial_flush = jiffies;
rs_sta->flush_pending = 1;
mod_timer(&rs_sta->rate_scale_flush,
jiffies + rs_sta->flush_time);
}
spin_unlock_irqrestore(&rs_sta->lock, flags);
D_RATE("leave\n");
}
static u16
il3945_get_adjacent_rate(struct il3945_rs_sta *rs_sta, u8 idx, u16 rate_mask,
enum ieee80211_band band)
{
u8 high = RATE_INVALID;
u8 low = RATE_INVALID;
struct il_priv *il __maybe_unused = rs_sta->il;
if (unlikely(band == IEEE80211_BAND_5GHZ)) {
int i;
u32 mask;
i = idx - 1;
for (mask = (1 << i); i >= 0; i--, mask >>= 1) {
if (rate_mask & mask) {
low = i;
break;
}
}
i = idx + 1;
for (mask = (1 << i); i < RATE_COUNT_3945; i++, mask <<= 1) {
if (rate_mask & mask) {
high = i;
break;
}
}
return (high << 8) | low;
}
low = idx;
while (low != RATE_INVALID) {
if (rs_sta->tgg)
low = il3945_rates[low].prev_rs_tgg;
else
low = il3945_rates[low].prev_rs;
if (low == RATE_INVALID)
break;
if (rate_mask & (1 << low))
break;
D_RATE("Skipping masked lower rate: %d\n", low);
}
high = idx;
while (high != RATE_INVALID) {
if (rs_sta->tgg)
high = il3945_rates[high].next_rs_tgg;
else
high = il3945_rates[high].next_rs;
if (high == RATE_INVALID)
break;
if (rate_mask & (1 << high))
break;
D_RATE("Skipping masked higher rate: %d\n", high);
}
return (high << 8) | low;
}
static void
il3945_rs_get_rate(void *il_r, struct ieee80211_sta *sta, void *il_sta,
struct ieee80211_tx_rate_control *txrc)
{
struct ieee80211_supported_band *sband = txrc->sband;
struct sk_buff *skb = txrc->skb;
u8 low = RATE_INVALID;
u8 high = RATE_INVALID;
u16 high_low;
int idx;
struct il3945_rs_sta *rs_sta = il_sta;
struct il3945_rate_scale_data *win = NULL;
int current_tpt = IL_INVALID_VALUE;
int low_tpt = IL_INVALID_VALUE;
int high_tpt = IL_INVALID_VALUE;
u32 fail_count;
s8 scale_action = 0;
unsigned long flags;
u16 rate_mask;
s8 max_rate_idx = -1;
struct il_priv *il __maybe_unused = (struct il_priv *)il_r;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
D_RATE("enter\n");
if (rs_sta && !rs_sta->il) {
D_RATE("Rate scaling information not initialized yet.\n");
il_sta = NULL;
}
if (rate_control_send_low(sta, il_sta, txrc))
return;
rate_mask = sta->supp_rates[sband->band];
max_rate_idx = txrc->max_rate_idx;
if (sband->band == IEEE80211_BAND_5GHZ && max_rate_idx != -1)
max_rate_idx += IL_FIRST_OFDM_RATE;
if (max_rate_idx < 0 || max_rate_idx >= RATE_COUNT)
max_rate_idx = -1;
idx = min(rs_sta->last_txrate_idx & 0xffff, RATE_COUNT_3945 - 1);
if (sband->band == IEEE80211_BAND_5GHZ)
rate_mask = rate_mask << IL_FIRST_OFDM_RATE;
spin_lock_irqsave(&rs_sta->lock, flags);
if (rs_sta->start_rate != RATE_INVALID) {
if (rs_sta->start_rate < idx &&
(rate_mask & (1 << rs_sta->start_rate)))
idx = rs_sta->start_rate;
rs_sta->start_rate = RATE_INVALID;
}
if (max_rate_idx != -1 && max_rate_idx < idx) {
if (rate_mask & (1 << max_rate_idx))
idx = max_rate_idx;
}
win = &(rs_sta->win[idx]);
fail_count = win->counter - win->success_counter;
if (fail_count < RATE_MIN_FAILURE_TH &&
win->success_counter < RATE_MIN_SUCCESS_TH) {
spin_unlock_irqrestore(&rs_sta->lock, flags);
D_RATE("Invalid average_tpt on rate %d: "
"counter: %d, success_counter: %d, "
"expected_tpt is %sNULL\n", idx, win->counter,
win->success_counter,
rs_sta->expected_tpt ? "not " : "");
win->average_tpt = IL_INVALID_VALUE;
goto out;
}
current_tpt = win->average_tpt;
high_low =
il3945_get_adjacent_rate(rs_sta, idx, rate_mask, sband->band);
low = high_low & 0xff;
high = (high_low >> 8) & 0xff;
if (max_rate_idx != -1 && max_rate_idx < high)
high = RATE_INVALID;
if (low != RATE_INVALID)
low_tpt = rs_sta->win[low].average_tpt;
if (high != RATE_INVALID)
high_tpt = rs_sta->win[high].average_tpt;
spin_unlock_irqrestore(&rs_sta->lock, flags);
scale_action = 0;
if (win->success_ratio < RATE_DECREASE_TH || !current_tpt) {
D_RATE("decrease rate because of low success_ratio\n");
scale_action = -1;
} else if (low_tpt == IL_INVALID_VALUE && high_tpt == IL_INVALID_VALUE) {
if (high != RATE_INVALID &&
win->success_ratio >= RATE_INCREASE_TH)
scale_action = 1;
else if (low != RATE_INVALID)
scale_action = 0;
} else if (low_tpt != IL_INVALID_VALUE && high_tpt != IL_INVALID_VALUE
&& low_tpt < current_tpt && high_tpt < current_tpt) {
D_RATE("No action -- low [%d] & high [%d] < "
"current_tpt [%d]\n", low_tpt, high_tpt, current_tpt);
scale_action = 0;
} else {
if (high_tpt != IL_INVALID_VALUE) {
if (high_tpt > current_tpt &&
win->success_ratio >= RATE_INCREASE_TH)
scale_action = 1;
else {
D_RATE("decrease rate because of high tpt\n");
scale_action = 0;
}
} else if (low_tpt != IL_INVALID_VALUE) {
if (low_tpt > current_tpt) {
D_RATE("decrease rate because of low tpt\n");
scale_action = -1;
} else if (win->success_ratio >= RATE_INCREASE_TH) {
scale_action = 1;
}
}
}
if (scale_action == -1 && low != RATE_INVALID &&
(win->success_ratio > RATE_HIGH_TH ||
current_tpt > 100 * rs_sta->expected_tpt[low]))
scale_action = 0;
switch (scale_action) {
case -1:
if (low != RATE_INVALID)
idx = low;
break;
case 1:
if (high != RATE_INVALID)
idx = high;
break;
case 0:
default:
break;
}
D_RATE("Selected %d (action %d) - low %d high %d\n", idx, scale_action,
low, high);
out:
if (sband->band == IEEE80211_BAND_5GHZ) {
if (WARN_ON_ONCE(idx < IL_FIRST_OFDM_RATE))
idx = IL_FIRST_OFDM_RATE;
rs_sta->last_txrate_idx = idx;
info->control.rates[0].idx = idx - IL_FIRST_OFDM_RATE;
} else {
rs_sta->last_txrate_idx = idx;
info->control.rates[0].idx = rs_sta->last_txrate_idx;
}
info->control.rates[0].count = 1;
D_RATE("leave: %d\n", idx);
}
static ssize_t
il3945_sta_dbgfs_stats_table_read(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
char *buff;
int desc = 0;
int j;
ssize_t ret;
struct il3945_rs_sta *lq_sta = file->private_data;
buff = kmalloc(1024, GFP_KERNEL);
if (!buff)
return -ENOMEM;
desc +=
sprintf(buff + desc,
"tx packets=%d last rate idx=%d\n"
"rate=0x%X flush time %d\n", lq_sta->tx_packets,
lq_sta->last_txrate_idx, lq_sta->start_rate,
jiffies_to_msecs(lq_sta->flush_time));
for (j = 0; j < RATE_COUNT_3945; j++) {
desc +=
sprintf(buff + desc, "counter=%d success=%d %%=%d\n",
lq_sta->win[j].counter,
lq_sta->win[j].success_counter,
lq_sta->win[j].success_ratio);
}
ret = simple_read_from_buffer(user_buf, count, ppos, buff, desc);
kfree(buff);
return ret;
}
static void
il3945_add_debugfs(void *il, void *il_sta, struct dentry *dir)
{
struct il3945_rs_sta *lq_sta = il_sta;
lq_sta->rs_sta_dbgfs_stats_table_file =
debugfs_create_file("rate_stats_table", 0600, dir, lq_sta,
&rs_sta_dbgfs_stats_table_ops);
}
static void
il3945_remove_debugfs(void *il, void *il_sta)
{
struct il3945_rs_sta *lq_sta = il_sta;
debugfs_remove(lq_sta->rs_sta_dbgfs_stats_table_file);
}
static void
il3945_rs_rate_init_stub(void *il_r, struct ieee80211_supported_band *sband,
struct ieee80211_sta *sta, void *il_sta)
{
}
void
il3945_rate_scale_init(struct ieee80211_hw *hw, s32 sta_id)
{
struct il_priv *il = hw->priv;
s32 rssi = 0;
unsigned long flags;
struct il3945_rs_sta *rs_sta;
struct ieee80211_sta *sta;
struct il3945_sta_priv *psta;
D_RATE("enter\n");
rcu_read_lock();
sta = ieee80211_find_sta(il->vif, il->stations[sta_id].sta.sta.addr);
if (!sta) {
D_RATE("Unable to find station to initialize rate scaling.\n");
rcu_read_unlock();
return;
}
psta = (void *)sta->drv_priv;
rs_sta = &psta->rs_sta;
spin_lock_irqsave(&rs_sta->lock, flags);
rs_sta->tgg = 0;
switch (il->band) {
case IEEE80211_BAND_2GHZ:
if (il->active.flags & RXON_FLG_TGG_PROTECT_MSK) {
rs_sta->tgg = 1;
rs_sta->expected_tpt = il3945_expected_tpt_g_prot;
} else
rs_sta->expected_tpt = il3945_expected_tpt_g;
break;
case IEEE80211_BAND_5GHZ:
rs_sta->expected_tpt = il3945_expected_tpt_a;
break;
default:
BUG();
break;
}
spin_unlock_irqrestore(&rs_sta->lock, flags);
rssi = il->_3945.last_rx_rssi;
if (rssi == 0)
rssi = IL_MIN_RSSI_VAL;
D_RATE("Network RSSI: %d\n", rssi);
rs_sta->start_rate = il3945_get_rate_idx_by_rssi(rssi, il->band);
D_RATE("leave: rssi %d assign rate idx: " "%d (plcp 0x%x)\n", rssi,
rs_sta->start_rate, il3945_rates[rs_sta->start_rate].plcp);
rcu_read_unlock();
}
int
il3945_rate_control_register(void)
{
return ieee80211_rate_control_register(&rs_ops);
}
void
il3945_rate_control_unregister(void)
{
ieee80211_rate_control_unregister(&rs_ops);
}
