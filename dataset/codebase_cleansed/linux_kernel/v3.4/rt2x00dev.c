u32 rt2x00lib_get_bssidx(struct rt2x00_dev *rt2x00dev,
struct ieee80211_vif *vif)
{
if (rt2x00dev->intf_sta_count)
return 0;
return vif->addr[5] & (rt2x00dev->ops->max_ap_intf - 1);
}
int rt2x00lib_enable_radio(struct rt2x00_dev *rt2x00dev)
{
int status;
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return 0;
rt2x00queue_init_queues(rt2x00dev);
status =
rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_RADIO_ON);
if (status)
return status;
rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_RADIO_IRQ_ON);
rt2x00leds_led_radio(rt2x00dev, true);
rt2x00led_led_activity(rt2x00dev, true);
set_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags);
rt2x00queue_start_queues(rt2x00dev);
rt2x00link_start_tuner(rt2x00dev);
rt2x00link_start_agc(rt2x00dev);
if (test_bit(CAPABILITY_VCO_RECALIBRATION, &rt2x00dev->cap_flags))
rt2x00link_start_vcocal(rt2x00dev);
rt2x00link_start_watchdog(rt2x00dev);
return 0;
}
void rt2x00lib_disable_radio(struct rt2x00_dev *rt2x00dev)
{
if (!test_and_clear_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
rt2x00link_stop_watchdog(rt2x00dev);
rt2x00link_stop_agc(rt2x00dev);
if (test_bit(CAPABILITY_VCO_RECALIBRATION, &rt2x00dev->cap_flags))
rt2x00link_stop_vcocal(rt2x00dev);
rt2x00link_stop_tuner(rt2x00dev);
rt2x00queue_stop_queues(rt2x00dev);
rt2x00queue_flush_queues(rt2x00dev, true);
rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_RADIO_OFF);
rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_RADIO_IRQ_OFF);
rt2x00led_led_activity(rt2x00dev, false);
rt2x00leds_led_radio(rt2x00dev, false);
}
static void rt2x00lib_intf_scheduled_iter(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = data;
struct rt2x00_intf *intf = vif_to_intf(vif);
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
if (test_and_clear_bit(DELAYED_UPDATE_BEACON, &intf->delayed_flags))
rt2x00queue_update_beacon(rt2x00dev, vif);
}
static void rt2x00lib_intf_scheduled(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, intf_work);
ieee80211_iterate_active_interfaces(rt2x00dev->hw,
rt2x00lib_intf_scheduled_iter,
rt2x00dev);
}
static void rt2x00lib_autowakeup(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, autowakeup_work.work);
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return;
if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_AWAKE))
ERROR(rt2x00dev, "Device failed to wakeup.\n");
clear_bit(CONFIG_POWERSAVING, &rt2x00dev->flags);
}
static void rt2x00lib_bc_buffer_iter(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = data;
struct sk_buff *skb;
if (vif->type != NL80211_IFTYPE_AP)
return;
skb = ieee80211_get_buffered_bc(rt2x00dev->hw, vif);
while (skb) {
rt2x00mac_tx(rt2x00dev->hw, skb);
skb = ieee80211_get_buffered_bc(rt2x00dev->hw, vif);
}
}
static void rt2x00lib_beaconupdate_iter(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = data;
if (vif->type != NL80211_IFTYPE_AP &&
vif->type != NL80211_IFTYPE_ADHOC &&
vif->type != NL80211_IFTYPE_MESH_POINT &&
vif->type != NL80211_IFTYPE_WDS)
return;
WARN_ON(rt2x00_is_usb(rt2x00dev));
rt2x00queue_update_beacon_locked(rt2x00dev, vif);
}
void rt2x00lib_beacondone(struct rt2x00_dev *rt2x00dev)
{
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
ieee80211_iterate_active_interfaces_atomic(rt2x00dev->hw,
rt2x00lib_bc_buffer_iter,
rt2x00dev);
if (test_bit(CAPABILITY_PRE_TBTT_INTERRUPT, &rt2x00dev->cap_flags))
return;
ieee80211_iterate_active_interfaces_atomic(rt2x00dev->hw,
rt2x00lib_beaconupdate_iter,
rt2x00dev);
}
void rt2x00lib_pretbtt(struct rt2x00_dev *rt2x00dev)
{
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
ieee80211_iterate_active_interfaces_atomic(rt2x00dev->hw,
rt2x00lib_beaconupdate_iter,
rt2x00dev);
}
void rt2x00lib_dmastart(struct queue_entry *entry)
{
set_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags);
rt2x00queue_index_inc(entry, Q_INDEX);
}
void rt2x00lib_dmadone(struct queue_entry *entry)
{
set_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags);
clear_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags);
rt2x00queue_index_inc(entry, Q_INDEX_DMA_DONE);
}
void rt2x00lib_txdone(struct queue_entry *entry,
struct txdone_entry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(entry->skb);
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
unsigned int header_length, i;
u8 rate_idx, rate_flags, retry_rates;
u8 skbdesc_flags = skbdesc->flags;
bool success;
rt2x00queue_unmap_skb(entry);
skb_pull(entry->skb, rt2x00dev->ops->extra_tx_headroom);
skbdesc->flags &= ~SKBDESC_DESC_IN_SKB;
header_length = ieee80211_get_hdrlen_from_skb(entry->skb);
if (test_bit(REQUIRE_L2PAD, &rt2x00dev->cap_flags))
rt2x00queue_remove_l2pad(entry->skb, header_length);
if (test_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags))
rt2x00crypto_tx_insert_iv(entry->skb, header_length);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_TXDONE, entry->skb);
success =
test_bit(TXDONE_SUCCESS, &txdesc->flags) ||
test_bit(TXDONE_UNKNOWN, &txdesc->flags);
rt2x00dev->link.qual.tx_success += success;
rt2x00dev->link.qual.tx_failed += !success;
rate_idx = skbdesc->tx_rate_idx;
rate_flags = skbdesc->tx_rate_flags;
retry_rates = test_bit(TXDONE_FALLBACK, &txdesc->flags) ?
(txdesc->retry + 1) : 1;
memset(&tx_info->status, 0, sizeof(tx_info->status));
tx_info->status.ack_signal = 0;
for (i = 0; i < retry_rates && i < IEEE80211_TX_MAX_RATES; i++) {
tx_info->status.rates[i].idx = rate_idx - i;
tx_info->status.rates[i].flags = rate_flags;
if (rate_idx - i == 0) {
tx_info->status.rates[i].count = retry_rates - i;
i++;
break;
}
tx_info->status.rates[i].count = 1;
}
if (i < (IEEE80211_TX_MAX_RATES - 1))
tx_info->status.rates[i].idx = -1;
if (!(tx_info->flags & IEEE80211_TX_CTL_NO_ACK)) {
if (success)
tx_info->flags |= IEEE80211_TX_STAT_ACK;
else
rt2x00dev->low_level_stats.dot11ACKFailureCount++;
}
if (test_bit(TXDONE_AMPDU, &txdesc->flags) ||
tx_info->flags & IEEE80211_TX_CTL_AMPDU) {
tx_info->flags |= IEEE80211_TX_STAT_AMPDU;
tx_info->status.ampdu_len = 1;
tx_info->status.ampdu_ack_len = success ? 1 : 0;
if (!success)
tx_info->flags |= IEEE80211_TX_STAT_AMPDU_NO_BACK;
}
if (rate_flags & IEEE80211_TX_RC_USE_RTS_CTS) {
if (success)
rt2x00dev->low_level_stats.dot11RTSSuccessCount++;
else
rt2x00dev->low_level_stats.dot11RTSFailureCount++;
}
if (!(skbdesc_flags & SKBDESC_NOT_MAC80211)) {
if (test_bit(REQUIRE_TASKLET_CONTEXT, &rt2x00dev->cap_flags))
ieee80211_tx_status(rt2x00dev->hw, entry->skb);
else
ieee80211_tx_status_ni(rt2x00dev->hw, entry->skb);
} else
dev_kfree_skb_any(entry->skb);
entry->skb = NULL;
entry->flags = 0;
rt2x00dev->ops->lib->clear_entry(entry);
rt2x00queue_index_inc(entry, Q_INDEX_DONE);
spin_lock_bh(&entry->queue->tx_lock);
if (!rt2x00queue_threshold(entry->queue))
rt2x00queue_unpause_queue(entry->queue);
spin_unlock_bh(&entry->queue->tx_lock);
}
void rt2x00lib_txdone_noinfo(struct queue_entry *entry, u32 status)
{
struct txdone_entry_desc txdesc;
txdesc.flags = 0;
__set_bit(status, &txdesc.flags);
txdesc.retry = 0;
rt2x00lib_txdone(entry, &txdesc);
}
static u8 *rt2x00lib_find_ie(u8 *data, unsigned int len, u8 ie)
{
struct ieee80211_mgmt *mgmt = (void *)data;
u8 *pos, *end;
pos = (u8 *)mgmt->u.beacon.variable;
end = data + len;
while (pos < end) {
if (pos + 2 + pos[1] > end)
return NULL;
if (pos[0] == ie)
return pos;
pos += 2 + pos[1];
}
return NULL;
}
static void rt2x00lib_sleep(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, sleep_work);
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return;
if (!test_bit(CONFIG_POWERSAVING, &rt2x00dev->flags))
rt2x00lib_config(rt2x00dev, &rt2x00dev->hw->conf,
IEEE80211_CONF_CHANGE_PS);
}
static void rt2x00lib_rxdone_check_ps(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct rxdone_entry_desc *rxdesc)
{
struct ieee80211_hdr *hdr = (void *) skb->data;
struct ieee80211_tim_ie *tim_ie;
u8 *tim;
u8 tim_len;
bool cam;
if (likely(!ieee80211_is_beacon(hdr->frame_control) ||
!(rt2x00dev->hw->conf.flags & IEEE80211_CONF_PS)))
return;
if (skb->len <= 40 + FCS_LEN)
return;
if (!(rxdesc->dev_flags & RXDONE_MY_BSS) ||
!rt2x00dev->aid)
return;
rt2x00dev->last_beacon = jiffies;
tim = rt2x00lib_find_ie(skb->data, skb->len - FCS_LEN, WLAN_EID_TIM);
if (!tim)
return;
if (tim[1] < sizeof(*tim_ie))
return;
tim_len = tim[1];
tim_ie = (struct ieee80211_tim_ie *) &tim[2];
cam = ieee80211_check_tim(tim_ie, tim_len, rt2x00dev->aid);
cam |= (tim_ie->bitmap_ctrl & 0x01);
if (!cam && !test_bit(CONFIG_POWERSAVING, &rt2x00dev->flags))
queue_work(rt2x00dev->workqueue, &rt2x00dev->sleep_work);
}
static int rt2x00lib_rxdone_read_signal(struct rt2x00_dev *rt2x00dev,
struct rxdone_entry_desc *rxdesc)
{
struct ieee80211_supported_band *sband;
const struct rt2x00_rate *rate;
unsigned int i;
int signal = rxdesc->signal;
int type = (rxdesc->dev_flags & RXDONE_SIGNAL_MASK);
switch (rxdesc->rate_mode) {
case RATE_MODE_CCK:
case RATE_MODE_OFDM:
if (rxdesc->dev_flags & RXDONE_SIGNAL_MCS)
signal = RATE_MCS(rxdesc->rate_mode, signal);
sband = &rt2x00dev->bands[rt2x00dev->curr_band];
for (i = 0; i < sband->n_bitrates; i++) {
rate = rt2x00_get_rate(sband->bitrates[i].hw_value);
if (((type == RXDONE_SIGNAL_PLCP) &&
(rate->plcp == signal)) ||
((type == RXDONE_SIGNAL_BITRATE) &&
(rate->bitrate == signal)) ||
((type == RXDONE_SIGNAL_MCS) &&
(rate->mcs == signal))) {
return i;
}
}
break;
case RATE_MODE_HT_MIX:
case RATE_MODE_HT_GREENFIELD:
if (signal >= 0 && signal <= 76)
return signal;
break;
default:
break;
}
WARNING(rt2x00dev, "Frame received with unrecognized signal, "
"mode=0x%.4x, signal=0x%.4x, type=%d.\n",
rxdesc->rate_mode, signal, type);
return 0;
}
void rt2x00lib_rxdone(struct queue_entry *entry)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct rxdone_entry_desc rxdesc;
struct sk_buff *skb;
struct ieee80211_rx_status *rx_status;
unsigned int header_length;
int rate_idx;
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) ||
!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
goto submit_entry;
if (test_bit(ENTRY_DATA_IO_FAILED, &entry->flags))
goto submit_entry;
skb = rt2x00queue_alloc_rxskb(entry);
if (!skb)
goto submit_entry;
rt2x00queue_unmap_skb(entry);
memset(&rxdesc, 0, sizeof(rxdesc));
rt2x00dev->ops->lib->fill_rxdone(entry, &rxdesc);
if (unlikely(rxdesc.size == 0 ||
rxdesc.size > entry->queue->data_size)) {
WARNING(rt2x00dev, "Wrong frame size %d max %d.\n",
rxdesc.size, entry->queue->data_size);
dev_kfree_skb(entry->skb);
goto renew_skb;
}
header_length = ieee80211_get_hdrlen_from_skb(entry->skb);
if ((rxdesc.dev_flags & RXDONE_CRYPTO_IV) &&
(rxdesc.flags & RX_FLAG_IV_STRIPPED))
rt2x00crypto_rx_insert_iv(entry->skb, header_length,
&rxdesc);
else if (header_length &&
(rxdesc.size > header_length) &&
(rxdesc.dev_flags & RXDONE_L2PAD))
rt2x00queue_remove_l2pad(entry->skb, header_length);
skb_trim(entry->skb, rxdesc.size);
rate_idx = rt2x00lib_rxdone_read_signal(rt2x00dev, &rxdesc);
if (rxdesc.rate_mode == RATE_MODE_HT_MIX ||
rxdesc.rate_mode == RATE_MODE_HT_GREENFIELD)
rxdesc.flags |= RX_FLAG_HT;
rt2x00lib_rxdone_check_ps(rt2x00dev, entry->skb, &rxdesc);
rt2x00link_update_stats(rt2x00dev, entry->skb, &rxdesc);
rt2x00debug_update_crypto(rt2x00dev, &rxdesc);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_RXDONE, entry->skb);
rx_status = IEEE80211_SKB_RXCB(entry->skb);
rx_status->mactime = rxdesc.timestamp;
rx_status->band = rt2x00dev->curr_band;
rx_status->freq = rt2x00dev->curr_freq;
rx_status->rate_idx = rate_idx;
rx_status->signal = rxdesc.rssi;
rx_status->flag = rxdesc.flags;
rx_status->antenna = rt2x00dev->link.ant.active.rx;
ieee80211_rx_ni(rt2x00dev->hw, entry->skb);
renew_skb:
entry->skb = skb;
submit_entry:
entry->flags = 0;
rt2x00queue_index_inc(entry, Q_INDEX_DONE);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) &&
test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2x00dev->ops->lib->clear_entry(entry);
}
static void rt2x00lib_channel(struct ieee80211_channel *entry,
const int channel, const int tx_power,
const int value)
{
entry->band = channel <= 14 ? IEEE80211_BAND_2GHZ : IEEE80211_BAND_5GHZ;
entry->center_freq = ieee80211_channel_to_frequency(channel,
entry->band);
entry->hw_value = value;
entry->max_power = tx_power;
entry->max_antenna_gain = 0xff;
}
static void rt2x00lib_rate(struct ieee80211_rate *entry,
const u16 index, const struct rt2x00_rate *rate)
{
entry->flags = 0;
entry->bitrate = rate->bitrate;
entry->hw_value = index;
entry->hw_value_short = index;
if (rate->flags & DEV_RATE_SHORT_PREAMBLE)
entry->flags |= IEEE80211_RATE_SHORT_PREAMBLE;
}
static int rt2x00lib_probe_hw_modes(struct rt2x00_dev *rt2x00dev,
struct hw_mode_spec *spec)
{
struct ieee80211_hw *hw = rt2x00dev->hw;
struct ieee80211_channel *channels;
struct ieee80211_rate *rates;
unsigned int num_rates;
unsigned int i;
num_rates = 0;
if (spec->supported_rates & SUPPORT_RATE_CCK)
num_rates += 4;
if (spec->supported_rates & SUPPORT_RATE_OFDM)
num_rates += 8;
channels = kcalloc(spec->num_channels, sizeof(*channels), GFP_KERNEL);
if (!channels)
return -ENOMEM;
rates = kcalloc(num_rates, sizeof(*rates), GFP_KERNEL);
if (!rates)
goto exit_free_channels;
for (i = 0; i < num_rates; i++)
rt2x00lib_rate(&rates[i], i, rt2x00_get_rate(i));
for (i = 0; i < spec->num_channels; i++) {
rt2x00lib_channel(&channels[i],
spec->channels[i].channel,
spec->channels_info[i].max_power, i);
}
if (spec->supported_bands & SUPPORT_BAND_2GHZ) {
rt2x00dev->bands[IEEE80211_BAND_2GHZ].n_channels = 14;
rt2x00dev->bands[IEEE80211_BAND_2GHZ].n_bitrates = num_rates;
rt2x00dev->bands[IEEE80211_BAND_2GHZ].channels = channels;
rt2x00dev->bands[IEEE80211_BAND_2GHZ].bitrates = rates;
hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&rt2x00dev->bands[IEEE80211_BAND_2GHZ];
memcpy(&rt2x00dev->bands[IEEE80211_BAND_2GHZ].ht_cap,
&spec->ht, sizeof(spec->ht));
}
if (spec->supported_bands & SUPPORT_BAND_5GHZ) {
rt2x00dev->bands[IEEE80211_BAND_5GHZ].n_channels =
spec->num_channels - 14;
rt2x00dev->bands[IEEE80211_BAND_5GHZ].n_bitrates =
num_rates - 4;
rt2x00dev->bands[IEEE80211_BAND_5GHZ].channels = &channels[14];
rt2x00dev->bands[IEEE80211_BAND_5GHZ].bitrates = &rates[4];
hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&rt2x00dev->bands[IEEE80211_BAND_5GHZ];
memcpy(&rt2x00dev->bands[IEEE80211_BAND_5GHZ].ht_cap,
&spec->ht, sizeof(spec->ht));
}
return 0;
exit_free_channels:
kfree(channels);
ERROR(rt2x00dev, "Allocation ieee80211 modes failed.\n");
return -ENOMEM;
}
static void rt2x00lib_remove_hw(struct rt2x00_dev *rt2x00dev)
{
if (test_bit(DEVICE_STATE_REGISTERED_HW, &rt2x00dev->flags))
ieee80211_unregister_hw(rt2x00dev->hw);
if (likely(rt2x00dev->hw->wiphy->bands[IEEE80211_BAND_2GHZ])) {
kfree(rt2x00dev->hw->wiphy->bands[IEEE80211_BAND_2GHZ]->channels);
kfree(rt2x00dev->hw->wiphy->bands[IEEE80211_BAND_2GHZ]->bitrates);
rt2x00dev->hw->wiphy->bands[IEEE80211_BAND_2GHZ] = NULL;
rt2x00dev->hw->wiphy->bands[IEEE80211_BAND_5GHZ] = NULL;
}
kfree(rt2x00dev->spec.channels_info);
}
static int rt2x00lib_probe_hw(struct rt2x00_dev *rt2x00dev)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
int status;
if (test_bit(DEVICE_STATE_REGISTERED_HW, &rt2x00dev->flags))
return 0;
status = rt2x00lib_probe_hw_modes(rt2x00dev, spec);
if (status)
return status;
rt2x00dev->hw->queues = rt2x00dev->ops->tx_queues;
rt2x00dev->hw->extra_tx_headroom =
max_t(unsigned int, IEEE80211_TX_STATUS_HEADROOM,
rt2x00dev->ops->extra_tx_headroom);
if (test_bit(REQUIRE_L2PAD, &rt2x00dev->cap_flags))
rt2x00dev->hw->extra_tx_headroom += RT2X00_L2PAD_SIZE;
else if (test_bit(REQUIRE_DMA, &rt2x00dev->cap_flags))
rt2x00dev->hw->extra_tx_headroom += RT2X00_ALIGN_SIZE;
rt2x00dev->hw->sta_data_size = sizeof(struct rt2x00_sta);
if (test_bit(REQUIRE_TXSTATUS_FIFO, &rt2x00dev->cap_flags)) {
int kfifo_size =
roundup_pow_of_two(rt2x00dev->ops->tx_queues *
rt2x00dev->ops->tx->entry_num *
sizeof(u32));
status = kfifo_alloc(&rt2x00dev->txstatus_fifo, kfifo_size,
GFP_KERNEL);
if (status)
return status;
}
#define RT2X00_TASKLET_INIT(taskletname) \
if (rt2x00dev->ops->lib->taskletname) { \
tasklet_init(&rt2x00dev->taskletname, \
rt2x00dev->ops->lib->taskletname, \
(unsigned long)rt2x00dev); \
}
RT2X00_TASKLET_INIT(txstatus_tasklet);
RT2X00_TASKLET_INIT(pretbtt_tasklet);
RT2X00_TASKLET_INIT(tbtt_tasklet);
RT2X00_TASKLET_INIT(rxdone_tasklet);
RT2X00_TASKLET_INIT(autowake_tasklet);
#undef RT2X00_TASKLET_INIT
status = ieee80211_register_hw(rt2x00dev->hw);
if (status)
return status;
set_bit(DEVICE_STATE_REGISTERED_HW, &rt2x00dev->flags);
return 0;
}
static void rt2x00lib_uninitialize(struct rt2x00_dev *rt2x00dev)
{
if (!test_and_clear_bit(DEVICE_STATE_INITIALIZED, &rt2x00dev->flags))
return;
rt2x00rfkill_unregister(rt2x00dev);
rt2x00dev->ops->lib->uninitialize(rt2x00dev);
rt2x00queue_uninitialize(rt2x00dev);
}
static int rt2x00lib_initialize(struct rt2x00_dev *rt2x00dev)
{
int status;
if (test_bit(DEVICE_STATE_INITIALIZED, &rt2x00dev->flags))
return 0;
status = rt2x00queue_initialize(rt2x00dev);
if (status)
return status;
status = rt2x00dev->ops->lib->initialize(rt2x00dev);
if (status) {
rt2x00queue_uninitialize(rt2x00dev);
return status;
}
set_bit(DEVICE_STATE_INITIALIZED, &rt2x00dev->flags);
return 0;
}
int rt2x00lib_start(struct rt2x00_dev *rt2x00dev)
{
int retval;
if (test_bit(DEVICE_STATE_STARTED, &rt2x00dev->flags))
return 0;
retval = rt2x00lib_load_firmware(rt2x00dev);
if (retval)
return retval;
retval = rt2x00lib_initialize(rt2x00dev);
if (retval)
return retval;
rt2x00dev->intf_ap_count = 0;
rt2x00dev->intf_sta_count = 0;
rt2x00dev->intf_associated = 0;
retval = rt2x00lib_enable_radio(rt2x00dev);
if (retval)
return retval;
set_bit(DEVICE_STATE_STARTED, &rt2x00dev->flags);
return 0;
}
void rt2x00lib_stop(struct rt2x00_dev *rt2x00dev)
{
if (!test_and_clear_bit(DEVICE_STATE_STARTED, &rt2x00dev->flags))
return;
rt2x00lib_disable_radio(rt2x00dev);
rt2x00dev->intf_ap_count = 0;
rt2x00dev->intf_sta_count = 0;
rt2x00dev->intf_associated = 0;
}
int rt2x00lib_probe_dev(struct rt2x00_dev *rt2x00dev)
{
int retval = -ENOMEM;
if (rt2x00dev->ops->drv_data_size > 0) {
rt2x00dev->drv_data = kzalloc(rt2x00dev->ops->drv_data_size,
GFP_KERNEL);
if (!rt2x00dev->drv_data) {
retval = -ENOMEM;
goto exit;
}
}
spin_lock_init(&rt2x00dev->irqmask_lock);
mutex_init(&rt2x00dev->csr_mutex);
set_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
rt2x00dev->hw->vif_data_size = sizeof(struct rt2x00_intf);
rt2x00dev->hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION);
if (rt2x00dev->ops->bcn->entry_num > 0)
rt2x00dev->hw->wiphy->interface_modes |=
BIT(NL80211_IFTYPE_ADHOC) |
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_MESH_POINT) |
BIT(NL80211_IFTYPE_WDS);
rt2x00dev->workqueue =
alloc_ordered_workqueue(wiphy_name(rt2x00dev->hw->wiphy), 0);
if (!rt2x00dev->workqueue) {
retval = -ENOMEM;
goto exit;
}
INIT_WORK(&rt2x00dev->intf_work, rt2x00lib_intf_scheduled);
INIT_DELAYED_WORK(&rt2x00dev->autowakeup_work, rt2x00lib_autowakeup);
INIT_WORK(&rt2x00dev->sleep_work, rt2x00lib_sleep);
retval = rt2x00dev->ops->lib->probe_hw(rt2x00dev);
if (retval) {
ERROR(rt2x00dev, "Failed to allocate device.\n");
goto exit;
}
retval = rt2x00queue_allocate(rt2x00dev);
if (retval)
goto exit;
retval = rt2x00lib_probe_hw(rt2x00dev);
if (retval) {
ERROR(rt2x00dev, "Failed to initialize hw.\n");
goto exit;
}
rt2x00link_register(rt2x00dev);
rt2x00leds_register(rt2x00dev);
rt2x00debug_register(rt2x00dev);
rt2x00rfkill_register(rt2x00dev);
return 0;
exit:
rt2x00lib_remove_dev(rt2x00dev);
return retval;
}
void rt2x00lib_remove_dev(struct rt2x00_dev *rt2x00dev)
{
clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
rt2x00lib_disable_radio(rt2x00dev);
cancel_work_sync(&rt2x00dev->intf_work);
cancel_delayed_work_sync(&rt2x00dev->autowakeup_work);
cancel_work_sync(&rt2x00dev->sleep_work);
if (rt2x00_is_usb(rt2x00dev)) {
hrtimer_cancel(&rt2x00dev->txstatus_timer);
cancel_work_sync(&rt2x00dev->rxdone_work);
cancel_work_sync(&rt2x00dev->txdone_work);
}
if (rt2x00dev->workqueue)
destroy_workqueue(rt2x00dev->workqueue);
kfifo_free(&rt2x00dev->txstatus_fifo);
tasklet_kill(&rt2x00dev->txstatus_tasklet);
tasklet_kill(&rt2x00dev->pretbtt_tasklet);
tasklet_kill(&rt2x00dev->tbtt_tasklet);
tasklet_kill(&rt2x00dev->rxdone_tasklet);
tasklet_kill(&rt2x00dev->autowake_tasklet);
rt2x00lib_uninitialize(rt2x00dev);
rt2x00debug_deregister(rt2x00dev);
rt2x00leds_unregister(rt2x00dev);
rt2x00lib_remove_hw(rt2x00dev);
rt2x00lib_free_firmware(rt2x00dev);
rt2x00queue_free(rt2x00dev);
if (rt2x00dev->drv_data)
kfree(rt2x00dev->drv_data);
}
int rt2x00lib_suspend(struct rt2x00_dev *rt2x00dev, pm_message_t state)
{
NOTICE(rt2x00dev, "Going to sleep.\n");
if (!test_and_clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return 0;
rt2x00lib_uninitialize(rt2x00dev);
rt2x00leds_suspend(rt2x00dev);
rt2x00debug_deregister(rt2x00dev);
if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_SLEEP))
WARNING(rt2x00dev, "Device failed to enter sleep state, "
"continue suspending.\n");
return 0;
}
int rt2x00lib_resume(struct rt2x00_dev *rt2x00dev)
{
NOTICE(rt2x00dev, "Waking up.\n");
rt2x00debug_register(rt2x00dev);
rt2x00leds_resume(rt2x00dev);
set_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
return 0;
}
