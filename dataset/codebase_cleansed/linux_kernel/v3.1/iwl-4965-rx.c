void iwl4965_rx_missed_beacon_notif(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_missed_beacon_notif *missed_beacon;
missed_beacon = &pkt->u.missed_beacon;
if (le32_to_cpu(missed_beacon->consecutive_missed_beacons) >
priv->missed_beacon_threshold) {
IWL_DEBUG_CALIB(priv,
"missed bcn cnsq %d totl %d rcd %d expctd %d\n",
le32_to_cpu(missed_beacon->consecutive_missed_beacons),
le32_to_cpu(missed_beacon->total_missed_becons),
le32_to_cpu(missed_beacon->num_recvd_beacons),
le32_to_cpu(missed_beacon->num_expected_beacons));
if (!test_bit(STATUS_SCANNING, &priv->status))
iwl4965_init_sensitivity(priv);
}
}
static void iwl4965_rx_calc_noise(struct iwl_priv *priv)
{
struct statistics_rx_non_phy *rx_info;
int num_active_rx = 0;
int total_silence = 0;
int bcn_silence_a, bcn_silence_b, bcn_silence_c;
int last_rx_noise;
rx_info = &(priv->_4965.statistics.rx.general);
bcn_silence_a =
le32_to_cpu(rx_info->beacon_silence_rssi_a) & IN_BAND_FILTER;
bcn_silence_b =
le32_to_cpu(rx_info->beacon_silence_rssi_b) & IN_BAND_FILTER;
bcn_silence_c =
le32_to_cpu(rx_info->beacon_silence_rssi_c) & IN_BAND_FILTER;
if (bcn_silence_a) {
total_silence += bcn_silence_a;
num_active_rx++;
}
if (bcn_silence_b) {
total_silence += bcn_silence_b;
num_active_rx++;
}
if (bcn_silence_c) {
total_silence += bcn_silence_c;
num_active_rx++;
}
if (num_active_rx)
last_rx_noise = (total_silence / num_active_rx) - 107;
else
last_rx_noise = IWL_NOISE_MEAS_NOT_AVAILABLE;
IWL_DEBUG_CALIB(priv, "inband silence a %u, b %u, c %u, dBm %d\n",
bcn_silence_a, bcn_silence_b, bcn_silence_c,
last_rx_noise);
}
static void iwl4965_accumulative_statistics(struct iwl_priv *priv,
__le32 *stats)
{
int i, size;
__le32 *prev_stats;
u32 *accum_stats;
u32 *delta, *max_delta;
struct statistics_general_common *general, *accum_general;
struct statistics_tx *tx, *accum_tx;
prev_stats = (__le32 *)&priv->_4965.statistics;
accum_stats = (u32 *)&priv->_4965.accum_statistics;
size = sizeof(struct iwl_notif_statistics);
general = &priv->_4965.statistics.general.common;
accum_general = &priv->_4965.accum_statistics.general.common;
tx = &priv->_4965.statistics.tx;
accum_tx = &priv->_4965.accum_statistics.tx;
delta = (u32 *)&priv->_4965.delta_statistics;
max_delta = (u32 *)&priv->_4965.max_delta;
for (i = sizeof(__le32); i < size;
i += sizeof(__le32), stats++, prev_stats++, delta++,
max_delta++, accum_stats++) {
if (le32_to_cpu(*stats) > le32_to_cpu(*prev_stats)) {
*delta = (le32_to_cpu(*stats) -
le32_to_cpu(*prev_stats));
*accum_stats += *delta;
if (*delta > *max_delta)
*max_delta = *delta;
}
}
accum_general->temperature = general->temperature;
accum_general->ttl_timestamp = general->ttl_timestamp;
}
void iwl4965_rx_statistics(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
int change;
struct iwl_rx_packet *pkt = rxb_addr(rxb);
IWL_DEBUG_RX(priv,
"Statistics notification received (%d vs %d).\n",
(int)sizeof(struct iwl_notif_statistics),
le32_to_cpu(pkt->len_n_flags) &
FH_RSCSR_FRAME_SIZE_MSK);
change = ((priv->_4965.statistics.general.common.temperature !=
pkt->u.stats.general.common.temperature) ||
((priv->_4965.statistics.flag &
STATISTICS_REPLY_FLG_HT40_MODE_MSK) !=
(pkt->u.stats.flag &
STATISTICS_REPLY_FLG_HT40_MODE_MSK)));
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUGFS
iwl4965_accumulative_statistics(priv, (__le32 *)&pkt->u.stats);
#endif
memcpy(&priv->_4965.statistics, &pkt->u.stats,
sizeof(priv->_4965.statistics));
set_bit(STATUS_STATISTICS, &priv->status);
mod_timer(&priv->statistics_periodic, jiffies +
msecs_to_jiffies(REG_RECALIB_PERIOD * 1000));
if (unlikely(!test_bit(STATUS_SCANNING, &priv->status)) &&
(pkt->hdr.cmd == STATISTICS_NOTIFICATION)) {
iwl4965_rx_calc_noise(priv);
queue_work(priv->workqueue, &priv->run_time_calib_work);
}
if (priv->cfg->ops->lib->temp_ops.temperature && change)
priv->cfg->ops->lib->temp_ops.temperature(priv);
}
void iwl4965_reply_statistics(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
if (le32_to_cpu(pkt->u.stats.flag) & UCODE_STATISTICS_CLEAR_MSK) {
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUGFS
memset(&priv->_4965.accum_statistics, 0,
sizeof(struct iwl_notif_statistics));
memset(&priv->_4965.delta_statistics, 0,
sizeof(struct iwl_notif_statistics));
memset(&priv->_4965.max_delta, 0,
sizeof(struct iwl_notif_statistics));
#endif
IWL_DEBUG_RX(priv, "Statistics have been cleared\n");
}
iwl4965_rx_statistics(priv, rxb);
}
