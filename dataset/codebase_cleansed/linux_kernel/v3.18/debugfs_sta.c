static ssize_t sta_flags_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[121];
struct sta_info *sta = file->private_data;
#define TEST(flg) \
test_sta_flag(sta, WLAN_STA_##flg) ? #flg "\n" : ""
int res = scnprintf(buf, sizeof(buf),
"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
TEST(AUTH), TEST(ASSOC), TEST(PS_STA),
TEST(PS_DRIVER), TEST(AUTHORIZED),
TEST(SHORT_PREAMBLE),
sta->sta.wme ? "WME\n" : "",
TEST(WDS), TEST(CLEAR_PS_FILT),
TEST(MFP), TEST(BLOCK_BA), TEST(PSPOLL),
TEST(UAPSD), TEST(SP), TEST(TDLS_PEER),
TEST(TDLS_PEER_AUTH), TEST(4ADDR_EVENT),
TEST(INSERTED), TEST(RATE_CONTROL),
TEST(TOFFSET_KNOWN), TEST(MPSP_OWNER),
TEST(MPSP_RECIPIENT));
#undef TEST
return simple_read_from_buffer(userbuf, count, ppos, buf, res);
}
static ssize_t sta_num_ps_buf_frames_read(struct file *file,
char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
char buf[17*IEEE80211_NUM_ACS], *p = buf;
int ac;
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
p += scnprintf(p, sizeof(buf)+buf-p, "AC%d: %d\n", ac,
skb_queue_len(&sta->ps_tx_buf[ac]) +
skb_queue_len(&sta->tx_filtered[ac]));
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t sta_inactive_ms_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
return mac80211_format_buffer(userbuf, count, ppos, "%d\n",
jiffies_to_msecs(jiffies - sta->last_rx));
}
static ssize_t sta_connected_time_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
struct timespec uptime;
struct tm result;
long connected_time_secs;
char buf[100];
int res;
ktime_get_ts(&uptime);
connected_time_secs = uptime.tv_sec - sta->last_connected;
time_to_tm(connected_time_secs, 0, &result);
result.tm_year -= 70;
result.tm_mday -= 1;
res = scnprintf(buf, sizeof(buf),
"years - %ld\nmonths - %d\ndays - %d\nclock - %d:%d:%d\n\n",
result.tm_year, result.tm_mon, result.tm_mday,
result.tm_hour, result.tm_min, result.tm_sec);
return simple_read_from_buffer(userbuf, count, ppos, buf, res);
}
static ssize_t sta_last_seq_ctrl_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[15*IEEE80211_NUM_TIDS], *p = buf;
int i;
struct sta_info *sta = file->private_data;
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
p += scnprintf(p, sizeof(buf)+buf-p, "%x ",
le16_to_cpu(sta->last_seq_ctrl[i]));
p += scnprintf(p, sizeof(buf)+buf-p, "\n");
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t sta_agg_status_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[71 + IEEE80211_NUM_TIDS * 40], *p = buf;
int i;
struct sta_info *sta = file->private_data;
struct tid_ampdu_rx *tid_rx;
struct tid_ampdu_tx *tid_tx;
rcu_read_lock();
p += scnprintf(p, sizeof(buf) + buf - p, "next dialog_token: %#02x\n",
sta->ampdu_mlme.dialog_token_allocator + 1);
p += scnprintf(p, sizeof(buf) + buf - p,
"TID\t\tRX\tDTKN\tSSN\t\tTX\tDTKN\tpending\n");
for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
tid_rx = rcu_dereference(sta->ampdu_mlme.tid_rx[i]);
tid_tx = rcu_dereference(sta->ampdu_mlme.tid_tx[i]);
p += scnprintf(p, sizeof(buf) + buf - p, "%02d", i);
p += scnprintf(p, sizeof(buf) + buf - p, "\t\t%x", !!tid_rx);
p += scnprintf(p, sizeof(buf) + buf - p, "\t%#.2x",
tid_rx ? tid_rx->dialog_token : 0);
p += scnprintf(p, sizeof(buf) + buf - p, "\t%#.3x",
tid_rx ? tid_rx->ssn : 0);
p += scnprintf(p, sizeof(buf) + buf - p, "\t\t%x", !!tid_tx);
p += scnprintf(p, sizeof(buf) + buf - p, "\t%#.2x",
tid_tx ? tid_tx->dialog_token : 0);
p += scnprintf(p, sizeof(buf) + buf - p, "\t%03d",
tid_tx ? skb_queue_len(&tid_tx->pending) : 0);
p += scnprintf(p, sizeof(buf) + buf - p, "\n");
}
rcu_read_unlock();
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t sta_agg_status_write(struct file *file, const char __user *userbuf,
size_t count, loff_t *ppos)
{
char _buf[12] = {}, *buf = _buf;
struct sta_info *sta = file->private_data;
bool start, tx;
unsigned long tid;
int ret;
if (count > sizeof(_buf))
return -EINVAL;
if (copy_from_user(buf, userbuf, count))
return -EFAULT;
buf[sizeof(_buf) - 1] = '\0';
if (strncmp(buf, "tx ", 3) == 0) {
buf += 3;
tx = true;
} else if (strncmp(buf, "rx ", 3) == 0) {
buf += 3;
tx = false;
} else
return -EINVAL;
if (strncmp(buf, "start ", 6) == 0) {
buf += 6;
start = true;
if (!tx)
return -EINVAL;
} else if (strncmp(buf, "stop ", 5) == 0) {
buf += 5;
start = false;
} else
return -EINVAL;
ret = kstrtoul(buf, 0, &tid);
if (ret)
return ret;
if (tid >= IEEE80211_NUM_TIDS)
return -EINVAL;
if (tx) {
if (start)
ret = ieee80211_start_tx_ba_session(&sta->sta, tid, 5000);
else
ret = ieee80211_stop_tx_ba_session(&sta->sta, tid);
} else {
__ieee80211_stop_rx_ba_session(sta, tid, WLAN_BACK_RECIPIENT,
3, true);
ret = 0;
}
return ret ?: count;
}
static ssize_t sta_ht_capa_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
#define PRINT_HT_CAP(_cond, _str) \
do { \
if (_cond) \
p += scnprintf(p, sizeof(buf)+buf-p, "\t" _str "\n"); \
} while (0)
char buf[512], *p = buf;
int i;
struct sta_info *sta = file->private_data;
struct ieee80211_sta_ht_cap *htc = &sta->sta.ht_cap;
p += scnprintf(p, sizeof(buf) + buf - p, "ht %ssupported\n",
htc->ht_supported ? "" : "not ");
if (htc->ht_supported) {
p += scnprintf(p, sizeof(buf)+buf-p, "cap: %#.4x\n", htc->cap);
PRINT_HT_CAP((htc->cap & BIT(0)), "RX LDPC");
PRINT_HT_CAP((htc->cap & BIT(1)), "HT20/HT40");
PRINT_HT_CAP(!(htc->cap & BIT(1)), "HT20");
PRINT_HT_CAP(((htc->cap >> 2) & 0x3) == 0, "Static SM Power Save");
PRINT_HT_CAP(((htc->cap >> 2) & 0x3) == 1, "Dynamic SM Power Save");
PRINT_HT_CAP(((htc->cap >> 2) & 0x3) == 3, "SM Power Save disabled");
PRINT_HT_CAP((htc->cap & BIT(4)), "RX Greenfield");
PRINT_HT_CAP((htc->cap & BIT(5)), "RX HT20 SGI");
PRINT_HT_CAP((htc->cap & BIT(6)), "RX HT40 SGI");
PRINT_HT_CAP((htc->cap & BIT(7)), "TX STBC");
PRINT_HT_CAP(((htc->cap >> 8) & 0x3) == 0, "No RX STBC");
PRINT_HT_CAP(((htc->cap >> 8) & 0x3) == 1, "RX STBC 1-stream");
PRINT_HT_CAP(((htc->cap >> 8) & 0x3) == 2, "RX STBC 2-streams");
PRINT_HT_CAP(((htc->cap >> 8) & 0x3) == 3, "RX STBC 3-streams");
PRINT_HT_CAP((htc->cap & BIT(10)), "HT Delayed Block Ack");
PRINT_HT_CAP(!(htc->cap & BIT(11)), "Max AMSDU length: "
"3839 bytes");
PRINT_HT_CAP((htc->cap & BIT(11)), "Max AMSDU length: "
"7935 bytes");
PRINT_HT_CAP((htc->cap & BIT(12)), "DSSS/CCK HT40");
PRINT_HT_CAP(!(htc->cap & BIT(12)), "No DSSS/CCK HT40");
PRINT_HT_CAP((htc->cap & BIT(14)), "40 MHz Intolerant");
PRINT_HT_CAP((htc->cap & BIT(15)), "L-SIG TXOP protection");
p += scnprintf(p, sizeof(buf)+buf-p, "ampdu factor/density: %d/%d\n",
htc->ampdu_factor, htc->ampdu_density);
p += scnprintf(p, sizeof(buf)+buf-p, "MCS mask:");
for (i = 0; i < IEEE80211_HT_MCS_MASK_LEN; i++)
p += scnprintf(p, sizeof(buf)+buf-p, " %.2x",
htc->mcs.rx_mask[i]);
p += scnprintf(p, sizeof(buf)+buf-p, "\n");
if (le16_to_cpu(htc->mcs.rx_highest)) {
p += scnprintf(p, sizeof(buf)+buf-p,
"MCS rx highest: %d Mbps\n",
le16_to_cpu(htc->mcs.rx_highest));
}
p += scnprintf(p, sizeof(buf)+buf-p, "MCS tx params: %x\n",
htc->mcs.tx_params);
}
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t sta_vht_capa_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[128], *p = buf;
struct sta_info *sta = file->private_data;
struct ieee80211_sta_vht_cap *vhtc = &sta->sta.vht_cap;
p += scnprintf(p, sizeof(buf) + buf - p, "VHT %ssupported\n",
vhtc->vht_supported ? "" : "not ");
if (vhtc->vht_supported) {
p += scnprintf(p, sizeof(buf)+buf-p, "cap: %#.8x\n", vhtc->cap);
p += scnprintf(p, sizeof(buf)+buf-p, "RX MCS: %.4x\n",
le16_to_cpu(vhtc->vht_mcs.rx_mcs_map));
if (vhtc->vht_mcs.rx_highest)
p += scnprintf(p, sizeof(buf)+buf-p,
"MCS RX highest: %d Mbps\n",
le16_to_cpu(vhtc->vht_mcs.rx_highest));
p += scnprintf(p, sizeof(buf)+buf-p, "TX MCS: %.4x\n",
le16_to_cpu(vhtc->vht_mcs.tx_mcs_map));
if (vhtc->vht_mcs.tx_highest)
p += scnprintf(p, sizeof(buf)+buf-p,
"MCS TX highest: %d Mbps\n",
le16_to_cpu(vhtc->vht_mcs.tx_highest));
}
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t sta_current_tx_rate_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
struct rate_info rinfo;
u16 rate;
sta_set_rate_info_tx(sta, &sta->last_tx_rate, &rinfo);
rate = cfg80211_calculate_bitrate(&rinfo);
return mac80211_format_buffer(userbuf, count, ppos,
"%d.%d MBit/s\n",
rate/10, rate%10);
}
static ssize_t sta_last_rx_rate_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
struct rate_info rinfo;
u16 rate;
sta_set_rate_info_rx(sta, &rinfo);
rate = cfg80211_calculate_bitrate(&rinfo);
return mac80211_format_buffer(userbuf, count, ppos,
"%d.%d MBit/s\n",
rate/10, rate%10);
}
static int
sta_tx_latency_stat_header(struct ieee80211_tx_latency_bin_ranges *tx_latency,
char *buf, int pos, int bufsz)
{
int i;
int range_count = tx_latency->n_ranges;
u32 *bin_ranges = tx_latency->ranges;
pos += scnprintf(buf + pos, bufsz - pos,
"Station\t\t\tTID\tMax\tAvg");
if (range_count) {
pos += scnprintf(buf + pos, bufsz - pos,
"\t<=%d", bin_ranges[0]);
for (i = 0; i < range_count - 1; i++)
pos += scnprintf(buf + pos, bufsz - pos, "\t%d-%d",
bin_ranges[i], bin_ranges[i+1]);
pos += scnprintf(buf + pos, bufsz - pos,
"\t%d<", bin_ranges[range_count - 1]);
}
pos += scnprintf(buf + pos, bufsz - pos, "\n");
return pos;
}
static int
sta_tx_latency_stat_table(struct ieee80211_tx_latency_bin_ranges *tx_lat_range,
struct ieee80211_tx_latency_stat *tx_lat,
char *buf, int pos, int bufsz, int tid)
{
u32 avg = 0;
int j;
int bin_count = tx_lat->bin_count;
pos += scnprintf(buf + pos, bufsz - pos, "\t\t\t%d", tid);
if (tx_lat->counter)
avg = tx_lat->sum / tx_lat->counter;
pos += scnprintf(buf + pos, bufsz - pos, "\t%d\t%d",
tx_lat->max, avg);
if (tx_lat_range->n_ranges && tx_lat->bins)
for (j = 0; j < bin_count; j++)
pos += scnprintf(buf + pos, bufsz - pos,
"\t%d", tx_lat->bins[j]);
pos += scnprintf(buf + pos, bufsz - pos, "\n");
return pos;
}
static ssize_t sta_tx_latency_stat_read(struct file *file,
char __user *userbuf,
size_t count, loff_t *ppos)
{
struct sta_info *sta = file->private_data;
struct ieee80211_local *local = sta->local;
struct ieee80211_tx_latency_bin_ranges *tx_latency;
char *buf;
int bufsz, ret, i;
int pos = 0;
bufsz = 20 * IEEE80211_NUM_TIDS *
sizeof(struct ieee80211_tx_latency_stat);
buf = kzalloc(bufsz, GFP_KERNEL);
if (!buf)
return -ENOMEM;
rcu_read_lock();
tx_latency = rcu_dereference(local->tx_latency);
if (!sta->tx_lat) {
pos += scnprintf(buf + pos, bufsz - pos,
"Tx latency statistics are not enabled\n");
goto unlock;
}
pos = sta_tx_latency_stat_header(tx_latency, buf, pos, bufsz);
pos += scnprintf(buf + pos, bufsz - pos, "%pM\n", sta->sta.addr);
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
pos = sta_tx_latency_stat_table(tx_latency, &sta->tx_lat[i],
buf, pos, bufsz, i);
unlock:
rcu_read_unlock();
ret = simple_read_from_buffer(userbuf, count, ppos, buf, pos);
kfree(buf);
return ret;
}
static ssize_t sta_tx_latency_stat_reset_write(struct file *file,
const char __user *userbuf,
size_t count, loff_t *ppos)
{
u32 *bins;
int bin_count;
struct sta_info *sta = file->private_data;
int i;
if (!sta->tx_lat)
return -EINVAL;
for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
bins = sta->tx_lat[i].bins;
bin_count = sta->tx_lat[i].bin_count;
sta->tx_lat[i].max = 0;
sta->tx_lat[i].sum = 0;
sta->tx_lat[i].counter = 0;
if (bin_count)
memset(bins, 0, bin_count * sizeof(u32));
}
return count;
}
void ieee80211_sta_debugfs_add(struct sta_info *sta)
{
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct dentry *stations_dir = sta->sdata->debugfs.subdir_stations;
u8 mac[3*ETH_ALEN];
sta->debugfs.add_has_run = true;
if (!stations_dir)
return;
snprintf(mac, sizeof(mac), "%pM", sta->sta.addr);
sta->debugfs.dir = debugfs_create_dir(mac, stations_dir);
if (!sta->debugfs.dir)
return;
DEBUGFS_ADD(flags);
DEBUGFS_ADD(num_ps_buf_frames);
DEBUGFS_ADD(inactive_ms);
DEBUGFS_ADD(connected_time);
DEBUGFS_ADD(last_seq_ctrl);
DEBUGFS_ADD(agg_status);
DEBUGFS_ADD(dev);
DEBUGFS_ADD(last_signal);
DEBUGFS_ADD(beacon_loss_count);
DEBUGFS_ADD(ht_capa);
DEBUGFS_ADD(vht_capa);
DEBUGFS_ADD(last_ack_signal);
DEBUGFS_ADD(current_tx_rate);
DEBUGFS_ADD(last_rx_rate);
DEBUGFS_ADD(tx_latency_stat);
DEBUGFS_ADD(tx_latency_stat_reset);
DEBUGFS_ADD_COUNTER(rx_packets, rx_packets);
DEBUGFS_ADD_COUNTER(tx_packets, tx_packets);
DEBUGFS_ADD_COUNTER(rx_bytes, rx_bytes);
DEBUGFS_ADD_COUNTER(tx_bytes, tx_bytes);
DEBUGFS_ADD_COUNTER(rx_duplicates, num_duplicates);
DEBUGFS_ADD_COUNTER(rx_fragments, rx_fragments);
DEBUGFS_ADD_COUNTER(rx_dropped, rx_dropped);
DEBUGFS_ADD_COUNTER(tx_fragments, tx_fragments);
DEBUGFS_ADD_COUNTER(tx_filtered, tx_filtered_count);
DEBUGFS_ADD_COUNTER(tx_retry_failed, tx_retry_failed);
DEBUGFS_ADD_COUNTER(tx_retry_count, tx_retry_count);
if (sizeof(sta->driver_buffered_tids) == sizeof(u32))
debugfs_create_x32("driver_buffered_tids", 0400,
sta->debugfs.dir,
(u32 *)&sta->driver_buffered_tids);
else
debugfs_create_x64("driver_buffered_tids", 0400,
sta->debugfs.dir,
(u64 *)&sta->driver_buffered_tids);
drv_sta_add_debugfs(local, sdata, &sta->sta, sta->debugfs.dir);
}
void ieee80211_sta_debugfs_remove(struct sta_info *sta)
{
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
drv_sta_remove_debugfs(local, sdata, &sta->sta, sta->debugfs.dir);
debugfs_remove_recursive(sta->debugfs.dir);
sta->debugfs.dir = NULL;
}
