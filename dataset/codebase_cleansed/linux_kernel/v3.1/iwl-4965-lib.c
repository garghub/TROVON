void iwl4965_check_abort_status(struct iwl_priv *priv,
u8 frame_count, u32 status)
{
if (frame_count == 1 && status == TX_STATUS_FAIL_RFKILL_FLUSH) {
IWL_ERR(priv, "Tx flush command to flush out all frames\n");
if (!test_bit(STATUS_EXIT_PENDING, &priv->status))
queue_work(priv->workqueue, &priv->tx_flush);
}
}
void iwl4965_rx_queue_reset(struct iwl_priv *priv, struct iwl_rx_queue *rxq)
{
unsigned long flags;
int i;
spin_lock_irqsave(&rxq->lock, flags);
INIT_LIST_HEAD(&rxq->rx_free);
INIT_LIST_HEAD(&rxq->rx_used);
for (i = 0; i < RX_FREE_BUFFERS + RX_QUEUE_SIZE; i++) {
if (rxq->pool[i].page != NULL) {
pci_unmap_page(priv->pci_dev, rxq->pool[i].page_dma,
PAGE_SIZE << priv->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
__iwl_legacy_free_pages(priv, rxq->pool[i].page);
rxq->pool[i].page = NULL;
}
list_add_tail(&rxq->pool[i].list, &rxq->rx_used);
}
for (i = 0; i < RX_QUEUE_SIZE; i++)
rxq->queue[i] = NULL;
rxq->read = rxq->write = 0;
rxq->write_actual = 0;
rxq->free_count = 0;
spin_unlock_irqrestore(&rxq->lock, flags);
}
int iwl4965_rx_init(struct iwl_priv *priv, struct iwl_rx_queue *rxq)
{
u32 rb_size;
const u32 rfdnlog = RX_QUEUE_SIZE_LOG;
u32 rb_timeout = 0;
if (priv->cfg->mod_params->amsdu_size_8K)
rb_size = FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_8K;
else
rb_size = FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_4K;
iwl_legacy_write_direct32(priv, FH_MEM_RCSR_CHNL0_CONFIG_REG, 0);
iwl_legacy_write_direct32(priv, FH_RSCSR_CHNL0_RBDCB_WPTR_REG, 0);
iwl_legacy_write_direct32(priv, FH_RSCSR_CHNL0_RBDCB_BASE_REG,
(u32)(rxq->bd_dma >> 8));
iwl_legacy_write_direct32(priv, FH_RSCSR_CHNL0_STTS_WPTR_REG,
rxq->rb_stts_dma >> 4);
iwl_legacy_write_direct32(priv, FH_MEM_RCSR_CHNL0_CONFIG_REG,
FH_RCSR_RX_CONFIG_CHNL_EN_ENABLE_VAL |
FH_RCSR_CHNL0_RX_CONFIG_IRQ_DEST_INT_HOST_VAL |
FH_RCSR_CHNL0_RX_CONFIG_SINGLE_FRAME_MSK |
rb_size|
(rb_timeout << FH_RCSR_RX_CONFIG_REG_IRQ_RBTH_POS)|
(rfdnlog << FH_RCSR_RX_CONFIG_RBDCB_SIZE_POS));
iwl_write8(priv, CSR_INT_COALESCING, IWL_HOST_INT_TIMEOUT_DEF);
return 0;
}
static void iwl4965_set_pwr_vmain(struct iwl_priv *priv)
{
iwl_legacy_set_bits_mask_prph(priv, APMG_PS_CTRL_REG,
APMG_PS_CTRL_VAL_PWR_SRC_VMAIN,
~APMG_PS_CTRL_MSK_PWR_SRC);
}
int iwl4965_hw_nic_init(struct iwl_priv *priv)
{
unsigned long flags;
struct iwl_rx_queue *rxq = &priv->rxq;
int ret;
spin_lock_irqsave(&priv->lock, flags);
priv->cfg->ops->lib->apm_ops.init(priv);
iwl_write8(priv, CSR_INT_COALESCING, IWL_HOST_INT_CALIB_TIMEOUT_DEF);
spin_unlock_irqrestore(&priv->lock, flags);
iwl4965_set_pwr_vmain(priv);
priv->cfg->ops->lib->apm_ops.config(priv);
if (!rxq->bd) {
ret = iwl_legacy_rx_queue_alloc(priv);
if (ret) {
IWL_ERR(priv, "Unable to initialize Rx queue\n");
return -ENOMEM;
}
} else
iwl4965_rx_queue_reset(priv, rxq);
iwl4965_rx_replenish(priv);
iwl4965_rx_init(priv, rxq);
spin_lock_irqsave(&priv->lock, flags);
rxq->need_update = 1;
iwl_legacy_rx_queue_update_write_ptr(priv, rxq);
spin_unlock_irqrestore(&priv->lock, flags);
if (!priv->txq) {
ret = iwl4965_txq_ctx_alloc(priv);
if (ret)
return ret;
} else
iwl4965_txq_ctx_reset(priv);
set_bit(STATUS_INIT, &priv->status);
return 0;
}
static inline __le32 iwl4965_dma_addr2rbd_ptr(struct iwl_priv *priv,
dma_addr_t dma_addr)
{
return cpu_to_le32((u32)(dma_addr >> 8));
}
void iwl4965_rx_queue_restock(struct iwl_priv *priv)
{
struct iwl_rx_queue *rxq = &priv->rxq;
struct list_head *element;
struct iwl_rx_mem_buffer *rxb;
unsigned long flags;
spin_lock_irqsave(&rxq->lock, flags);
while ((iwl_legacy_rx_queue_space(rxq) > 0) && (rxq->free_count)) {
rxb = rxq->queue[rxq->write];
BUG_ON(rxb && rxb->page);
element = rxq->rx_free.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
rxq->bd[rxq->write] = iwl4965_dma_addr2rbd_ptr(priv,
rxb->page_dma);
rxq->queue[rxq->write] = rxb;
rxq->write = (rxq->write + 1) & RX_QUEUE_MASK;
rxq->free_count--;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count <= RX_LOW_WATERMARK)
queue_work(priv->workqueue, &priv->rx_replenish);
if (rxq->write_actual != (rxq->write & ~0x7)) {
spin_lock_irqsave(&rxq->lock, flags);
rxq->need_update = 1;
spin_unlock_irqrestore(&rxq->lock, flags);
iwl_legacy_rx_queue_update_write_ptr(priv, rxq);
}
}
static void iwl4965_rx_allocate(struct iwl_priv *priv, gfp_t priority)
{
struct iwl_rx_queue *rxq = &priv->rxq;
struct list_head *element;
struct iwl_rx_mem_buffer *rxb;
struct page *page;
unsigned long flags;
gfp_t gfp_mask = priority;
while (1) {
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
return;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count > RX_LOW_WATERMARK)
gfp_mask |= __GFP_NOWARN;
if (priv->hw_params.rx_page_order > 0)
gfp_mask |= __GFP_COMP;
page = alloc_pages(gfp_mask, priv->hw_params.rx_page_order);
if (!page) {
if (net_ratelimit())
IWL_DEBUG_INFO(priv, "alloc_pages failed, "
"order: %d\n",
priv->hw_params.rx_page_order);
if ((rxq->free_count <= RX_LOW_WATERMARK) &&
net_ratelimit())
IWL_CRIT(priv,
"Failed to alloc_pages with %s. "
"Only %u free buffers remaining.\n",
priority == GFP_ATOMIC ?
"GFP_ATOMIC" : "GFP_KERNEL",
rxq->free_count);
return;
}
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
__free_pages(page, priv->hw_params.rx_page_order);
return;
}
element = rxq->rx_used.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
spin_unlock_irqrestore(&rxq->lock, flags);
BUG_ON(rxb->page);
rxb->page = page;
rxb->page_dma = pci_map_page(priv->pci_dev, page, 0,
PAGE_SIZE << priv->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
BUG_ON(rxb->page_dma & ~DMA_BIT_MASK(36));
BUG_ON(rxb->page_dma & DMA_BIT_MASK(8));
spin_lock_irqsave(&rxq->lock, flags);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
priv->alloc_rxb_page++;
spin_unlock_irqrestore(&rxq->lock, flags);
}
}
void iwl4965_rx_replenish(struct iwl_priv *priv)
{
unsigned long flags;
iwl4965_rx_allocate(priv, GFP_KERNEL);
spin_lock_irqsave(&priv->lock, flags);
iwl4965_rx_queue_restock(priv);
spin_unlock_irqrestore(&priv->lock, flags);
}
void iwl4965_rx_replenish_now(struct iwl_priv *priv)
{
iwl4965_rx_allocate(priv, GFP_ATOMIC);
iwl4965_rx_queue_restock(priv);
}
void iwl4965_rx_queue_free(struct iwl_priv *priv, struct iwl_rx_queue *rxq)
{
int i;
for (i = 0; i < RX_QUEUE_SIZE + RX_FREE_BUFFERS; i++) {
if (rxq->pool[i].page != NULL) {
pci_unmap_page(priv->pci_dev, rxq->pool[i].page_dma,
PAGE_SIZE << priv->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
__iwl_legacy_free_pages(priv, rxq->pool[i].page);
rxq->pool[i].page = NULL;
}
}
dma_free_coherent(&priv->pci_dev->dev, 4 * RX_QUEUE_SIZE, rxq->bd,
rxq->bd_dma);
dma_free_coherent(&priv->pci_dev->dev, sizeof(struct iwl_rb_status),
rxq->rb_stts, rxq->rb_stts_dma);
rxq->bd = NULL;
rxq->rb_stts = NULL;
}
int iwl4965_rxq_stop(struct iwl_priv *priv)
{
iwl_legacy_write_direct32(priv, FH_MEM_RCSR_CHNL0_CONFIG_REG, 0);
iwl_poll_direct_bit(priv, FH_MEM_RSSR_RX_STATUS_REG,
FH_RSSR_CHNL0_RX_STATUS_CHNL_IDLE, 1000);
return 0;
}
int iwl4965_hwrate_to_mac80211_idx(u32 rate_n_flags, enum ieee80211_band band)
{
int idx = 0;
int band_offset = 0;
if (rate_n_flags & RATE_MCS_HT_MSK) {
idx = (rate_n_flags & 0xff);
return idx;
} else {
if (band == IEEE80211_BAND_5GHZ)
band_offset = IWL_FIRST_OFDM_RATE;
for (idx = band_offset; idx < IWL_RATE_COUNT_LEGACY; idx++)
if (iwlegacy_rates[idx].plcp == (rate_n_flags & 0xFF))
return idx - band_offset;
}
return -1;
}
static int iwl4965_calc_rssi(struct iwl_priv *priv,
struct iwl_rx_phy_res *rx_resp)
{
struct iwl4965_rx_non_cfg_phy *ncphy =
(struct iwl4965_rx_non_cfg_phy *)rx_resp->non_cfg_phy_buf;
u32 agc = (le16_to_cpu(ncphy->agc_info) & IWL49_AGC_DB_MASK)
>> IWL49_AGC_DB_POS;
u32 valid_antennae =
(le16_to_cpu(rx_resp->phy_flags) & IWL49_RX_PHY_FLAGS_ANTENNAE_MASK)
>> IWL49_RX_PHY_FLAGS_ANTENNAE_OFFSET;
u8 max_rssi = 0;
u32 i;
for (i = 0; i < 3; i++)
if (valid_antennae & (1 << i))
max_rssi = max(ncphy->rssi_info[i << 1], max_rssi);
IWL_DEBUG_STATS(priv, "Rssi In A %d B %d C %d Max %d AGC dB %d\n",
ncphy->rssi_info[0], ncphy->rssi_info[2], ncphy->rssi_info[4],
max_rssi, agc);
return max_rssi - agc - IWL4965_RSSI_OFFSET;
}
static u32 iwl4965_translate_rx_status(struct iwl_priv *priv, u32 decrypt_in)
{
u32 decrypt_out = 0;
if ((decrypt_in & RX_RES_STATUS_STATION_FOUND) ==
RX_RES_STATUS_STATION_FOUND)
decrypt_out |= (RX_RES_STATUS_STATION_FOUND |
RX_RES_STATUS_NO_STATION_INFO_MISMATCH);
decrypt_out |= (decrypt_in & RX_RES_STATUS_SEC_TYPE_MSK);
if ((decrypt_in & RX_RES_STATUS_SEC_TYPE_MSK) ==
RX_RES_STATUS_SEC_TYPE_NONE)
return decrypt_out;
if ((decrypt_in & RX_RES_STATUS_SEC_TYPE_MSK) ==
RX_RES_STATUS_SEC_TYPE_ERR)
return decrypt_out;
if ((decrypt_in & RX_MPDU_RES_STATUS_DEC_DONE_MSK) !=
RX_MPDU_RES_STATUS_DEC_DONE_MSK)
return decrypt_out;
switch (decrypt_in & RX_RES_STATUS_SEC_TYPE_MSK) {
case RX_RES_STATUS_SEC_TYPE_CCMP:
if (!(decrypt_in & RX_MPDU_RES_STATUS_MIC_OK))
decrypt_out |= RX_RES_STATUS_BAD_ICV_MIC;
else
decrypt_out |= RX_RES_STATUS_DECRYPT_OK;
break;
case RX_RES_STATUS_SEC_TYPE_TKIP:
if (!(decrypt_in & RX_MPDU_RES_STATUS_TTAK_OK)) {
decrypt_out |= RX_RES_STATUS_BAD_KEY_TTAK;
break;
}
default:
if (!(decrypt_in & RX_MPDU_RES_STATUS_ICV_OK))
decrypt_out |= RX_RES_STATUS_BAD_ICV_MIC;
else
decrypt_out |= RX_RES_STATUS_DECRYPT_OK;
break;
}
IWL_DEBUG_RX(priv, "decrypt_in:0x%x decrypt_out = 0x%x\n",
decrypt_in, decrypt_out);
return decrypt_out;
}
static void iwl4965_pass_packet_to_mac80211(struct iwl_priv *priv,
struct ieee80211_hdr *hdr,
u16 len,
u32 ampdu_status,
struct iwl_rx_mem_buffer *rxb,
struct ieee80211_rx_status *stats)
{
struct sk_buff *skb;
__le16 fc = hdr->frame_control;
if (unlikely(!priv->is_open)) {
IWL_DEBUG_DROP_LIMIT(priv,
"Dropping packet while interface is not open.\n");
return;
}
if (!priv->cfg->mod_params->sw_crypto &&
iwl_legacy_set_decrypted_flag(priv, hdr, ampdu_status, stats))
return;
skb = dev_alloc_skb(128);
if (!skb) {
IWL_ERR(priv, "dev_alloc_skb failed\n");
return;
}
skb_add_rx_frag(skb, 0, rxb->page, (void *)hdr - rxb_addr(rxb), len);
iwl_legacy_update_stats(priv, false, fc, len);
memcpy(IEEE80211_SKB_RXCB(skb), stats, sizeof(*stats));
ieee80211_rx(priv->hw, skb);
priv->alloc_rxb_page--;
rxb->page = NULL;
}
void iwl4965_rx_reply_rx(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct ieee80211_hdr *header;
struct ieee80211_rx_status rx_status;
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_rx_phy_res *phy_res;
__le32 rx_pkt_status;
struct iwl_rx_mpdu_res_start *amsdu;
u32 len;
u32 ampdu_status;
u32 rate_n_flags;
if (pkt->hdr.cmd == REPLY_RX) {
phy_res = (struct iwl_rx_phy_res *)pkt->u.raw;
header = (struct ieee80211_hdr *)(pkt->u.raw + sizeof(*phy_res)
+ phy_res->cfg_phy_cnt);
len = le16_to_cpu(phy_res->byte_count);
rx_pkt_status = *(__le32 *)(pkt->u.raw + sizeof(*phy_res) +
phy_res->cfg_phy_cnt + len);
ampdu_status = le32_to_cpu(rx_pkt_status);
} else {
if (!priv->_4965.last_phy_res_valid) {
IWL_ERR(priv, "MPDU frame without cached PHY data\n");
return;
}
phy_res = &priv->_4965.last_phy_res;
amsdu = (struct iwl_rx_mpdu_res_start *)pkt->u.raw;
header = (struct ieee80211_hdr *)(pkt->u.raw + sizeof(*amsdu));
len = le16_to_cpu(amsdu->byte_count);
rx_pkt_status = *(__le32 *)(pkt->u.raw + sizeof(*amsdu) + len);
ampdu_status = iwl4965_translate_rx_status(priv,
le32_to_cpu(rx_pkt_status));
}
if ((unlikely(phy_res->cfg_phy_cnt > 20))) {
IWL_DEBUG_DROP(priv, "dsp size out of range [0,20]: %d/n",
phy_res->cfg_phy_cnt);
return;
}
if (!(rx_pkt_status & RX_RES_STATUS_NO_CRC32_ERROR) ||
!(rx_pkt_status & RX_RES_STATUS_NO_RXE_OVERFLOW)) {
IWL_DEBUG_RX(priv, "Bad CRC or FIFO: 0x%08X.\n",
le32_to_cpu(rx_pkt_status));
return;
}
rate_n_flags = le32_to_cpu(phy_res->rate_n_flags);
rx_status.mactime = le64_to_cpu(phy_res->timestamp);
rx_status.band = (phy_res->phy_flags & RX_RES_PHY_FLAGS_BAND_24_MSK) ?
IEEE80211_BAND_2GHZ : IEEE80211_BAND_5GHZ;
rx_status.freq =
ieee80211_channel_to_frequency(le16_to_cpu(phy_res->channel),
rx_status.band);
rx_status.rate_idx =
iwl4965_hwrate_to_mac80211_idx(rate_n_flags, rx_status.band);
rx_status.flag = 0;
priv->ucode_beacon_time = le32_to_cpu(phy_res->beacon_time_stamp);
rx_status.signal = iwl4965_calc_rssi(priv, phy_res);
iwl_legacy_dbg_log_rx_data_frame(priv, len, header);
IWL_DEBUG_STATS_LIMIT(priv, "Rssi %d, TSF %llu\n",
rx_status.signal, (unsigned long long)rx_status.mactime);
rx_status.antenna =
(le16_to_cpu(phy_res->phy_flags) & RX_RES_PHY_FLAGS_ANTENNA_MSK)
>> RX_RES_PHY_FLAGS_ANTENNA_POS;
if (phy_res->phy_flags & RX_RES_PHY_FLAGS_SHORT_PREAMBLE_MSK)
rx_status.flag |= RX_FLAG_SHORTPRE;
if (rate_n_flags & RATE_MCS_HT_MSK)
rx_status.flag |= RX_FLAG_HT;
if (rate_n_flags & RATE_MCS_HT40_MSK)
rx_status.flag |= RX_FLAG_40MHZ;
if (rate_n_flags & RATE_MCS_SGI_MSK)
rx_status.flag |= RX_FLAG_SHORT_GI;
iwl4965_pass_packet_to_mac80211(priv, header, len, ampdu_status,
rxb, &rx_status);
}
void iwl4965_rx_reply_rx_phy(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
priv->_4965.last_phy_res_valid = true;
memcpy(&priv->_4965.last_phy_res, pkt->u.raw,
sizeof(struct iwl_rx_phy_res));
}
static int iwl4965_get_channels_for_scan(struct iwl_priv *priv,
struct ieee80211_vif *vif,
enum ieee80211_band band,
u8 is_active, u8 n_probes,
struct iwl_scan_channel *scan_ch)
{
struct ieee80211_channel *chan;
const struct ieee80211_supported_band *sband;
const struct iwl_channel_info *ch_info;
u16 passive_dwell = 0;
u16 active_dwell = 0;
int added, i;
u16 channel;
sband = iwl_get_hw_mode(priv, band);
if (!sband)
return 0;
active_dwell = iwl_legacy_get_active_dwell_time(priv, band, n_probes);
passive_dwell = iwl_legacy_get_passive_dwell_time(priv, band, vif);
if (passive_dwell <= active_dwell)
passive_dwell = active_dwell + 1;
for (i = 0, added = 0; i < priv->scan_request->n_channels; i++) {
chan = priv->scan_request->channels[i];
if (chan->band != band)
continue;
channel = chan->hw_value;
scan_ch->channel = cpu_to_le16(channel);
ch_info = iwl_legacy_get_channel_info(priv, band, channel);
if (!iwl_legacy_is_channel_valid(ch_info)) {
IWL_DEBUG_SCAN(priv,
"Channel %d is INVALID for this band.\n",
channel);
continue;
}
if (!is_active || iwl_legacy_is_channel_passive(ch_info) ||
(chan->flags & IEEE80211_CHAN_PASSIVE_SCAN))
scan_ch->type = SCAN_CHANNEL_TYPE_PASSIVE;
else
scan_ch->type = SCAN_CHANNEL_TYPE_ACTIVE;
if (n_probes)
scan_ch->type |= IWL_SCAN_PROBE_MASK(n_probes);
scan_ch->active_dwell = cpu_to_le16(active_dwell);
scan_ch->passive_dwell = cpu_to_le16(passive_dwell);
scan_ch->dsp_atten = 110;
if (band == IEEE80211_BAND_5GHZ)
scan_ch->tx_gain = ((1 << 5) | (3 << 3)) | 3;
else
scan_ch->tx_gain = ((1 << 5) | (5 << 3));
IWL_DEBUG_SCAN(priv, "Scanning ch=%d prob=0x%X [%s %d]\n",
channel, le32_to_cpu(scan_ch->type),
(scan_ch->type & SCAN_CHANNEL_TYPE_ACTIVE) ?
"ACTIVE" : "PASSIVE",
(scan_ch->type & SCAN_CHANNEL_TYPE_ACTIVE) ?
active_dwell : passive_dwell);
scan_ch++;
added++;
}
IWL_DEBUG_SCAN(priv, "total channels to scan %d\n", added);
return added;
}
int iwl4965_request_scan(struct iwl_priv *priv, struct ieee80211_vif *vif)
{
struct iwl_host_cmd cmd = {
.id = REPLY_SCAN_CMD,
.len = sizeof(struct iwl_scan_cmd),
.flags = CMD_SIZE_HUGE,
};
struct iwl_scan_cmd *scan;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
u32 rate_flags = 0;
u16 cmd_len;
u16 rx_chain = 0;
enum ieee80211_band band;
u8 n_probes = 0;
u8 rx_ant = priv->hw_params.valid_rx_ant;
u8 rate;
bool is_active = false;
int chan_mod;
u8 active_chains;
u8 scan_tx_antennas = priv->hw_params.valid_tx_ant;
int ret;
lockdep_assert_held(&priv->mutex);
if (vif)
ctx = iwl_legacy_rxon_ctx_from_vif(vif);
if (!priv->scan_cmd) {
priv->scan_cmd = kmalloc(sizeof(struct iwl_scan_cmd) +
IWL_MAX_SCAN_SIZE, GFP_KERNEL);
if (!priv->scan_cmd) {
IWL_DEBUG_SCAN(priv,
"fail to allocate memory for scan\n");
return -ENOMEM;
}
}
scan = priv->scan_cmd;
memset(scan, 0, sizeof(struct iwl_scan_cmd) + IWL_MAX_SCAN_SIZE);
scan->quiet_plcp_th = IWL_PLCP_QUIET_THRESH;
scan->quiet_time = IWL_ACTIVE_QUIET_TIME;
if (iwl_legacy_is_any_associated(priv)) {
u16 interval;
u32 extra;
u32 suspend_time = 100;
u32 scan_suspend_time = 100;
IWL_DEBUG_INFO(priv, "Scanning while associated...\n");
interval = vif->bss_conf.beacon_int;
scan->suspend_time = 0;
scan->max_out_time = cpu_to_le32(200 * 1024);
if (!interval)
interval = suspend_time;
extra = (suspend_time / interval) << 22;
scan_suspend_time = (extra |
((suspend_time % interval) * 1024));
scan->suspend_time = cpu_to_le32(scan_suspend_time);
IWL_DEBUG_SCAN(priv, "suspend_time 0x%X beacon interval %d\n",
scan_suspend_time, interval);
}
if (priv->scan_request->n_ssids) {
int i, p = 0;
IWL_DEBUG_SCAN(priv, "Kicking off active scan\n");
for (i = 0; i < priv->scan_request->n_ssids; i++) {
if (!priv->scan_request->ssids[i].ssid_len)
continue;
scan->direct_scan[p].id = WLAN_EID_SSID;
scan->direct_scan[p].len =
priv->scan_request->ssids[i].ssid_len;
memcpy(scan->direct_scan[p].ssid,
priv->scan_request->ssids[i].ssid,
priv->scan_request->ssids[i].ssid_len);
n_probes++;
p++;
}
is_active = true;
} else
IWL_DEBUG_SCAN(priv, "Start passive scan.\n");
scan->tx_cmd.tx_flags = TX_CMD_FLG_SEQ_CTL_MSK;
scan->tx_cmd.sta_id = ctx->bcast_sta_id;
scan->tx_cmd.stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
switch (priv->scan_band) {
case IEEE80211_BAND_2GHZ:
scan->flags = RXON_FLG_BAND_24G_MSK | RXON_FLG_AUTO_DETECT_MSK;
chan_mod = le32_to_cpu(
priv->contexts[IWL_RXON_CTX_BSS].active.flags &
RXON_FLG_CHANNEL_MODE_MSK)
>> RXON_FLG_CHANNEL_MODE_POS;
if (chan_mod == CHANNEL_MODE_PURE_40) {
rate = IWL_RATE_6M_PLCP;
} else {
rate = IWL_RATE_1M_PLCP;
rate_flags = RATE_MCS_CCK_MSK;
}
break;
case IEEE80211_BAND_5GHZ:
rate = IWL_RATE_6M_PLCP;
break;
default:
IWL_WARN(priv, "Invalid scan band\n");
return -EIO;
}
scan->good_CRC_th = is_active ? IWL_GOOD_CRC_TH_DEFAULT :
IWL_GOOD_CRC_TH_NEVER;
band = priv->scan_band;
if (priv->cfg->scan_rx_antennas[band])
rx_ant = priv->cfg->scan_rx_antennas[band];
priv->scan_tx_ant[band] = iwl4965_toggle_tx_ant(priv,
priv->scan_tx_ant[band],
scan_tx_antennas);
rate_flags |= iwl4965_ant_idx_to_flags(priv->scan_tx_ant[band]);
scan->tx_cmd.rate_n_flags = iwl4965_hw_set_rate_n_flags(rate, rate_flags);
if (test_bit(STATUS_POWER_PMI, &priv->status)) {
active_chains = rx_ant &
((u8)(priv->chain_noise_data.active_chains));
if (!active_chains)
active_chains = rx_ant;
IWL_DEBUG_SCAN(priv, "chain_noise_data.active_chains: %u\n",
priv->chain_noise_data.active_chains);
rx_ant = iwl4965_first_antenna(active_chains);
}
rx_chain |= priv->hw_params.valid_rx_ant << RXON_RX_CHAIN_VALID_POS;
rx_chain |= rx_ant << RXON_RX_CHAIN_FORCE_MIMO_SEL_POS;
rx_chain |= rx_ant << RXON_RX_CHAIN_FORCE_SEL_POS;
rx_chain |= 0x1 << RXON_RX_CHAIN_DRIVER_FORCE_POS;
scan->rx_chain = cpu_to_le16(rx_chain);
cmd_len = iwl_legacy_fill_probe_req(priv,
(struct ieee80211_mgmt *)scan->data,
vif->addr,
priv->scan_request->ie,
priv->scan_request->ie_len,
IWL_MAX_SCAN_SIZE - sizeof(*scan));
scan->tx_cmd.len = cpu_to_le16(cmd_len);
scan->filter_flags |= (RXON_FILTER_ACCEPT_GRP_MSK |
RXON_FILTER_BCON_AWARE_MSK);
scan->channel_count = iwl4965_get_channels_for_scan(priv, vif, band,
is_active, n_probes,
(void *)&scan->data[cmd_len]);
if (scan->channel_count == 0) {
IWL_DEBUG_SCAN(priv, "channel count %d\n", scan->channel_count);
return -EIO;
}
cmd.len += le16_to_cpu(scan->tx_cmd.len) +
scan->channel_count * sizeof(struct iwl_scan_channel);
cmd.data = scan;
scan->len = cpu_to_le16(cmd.len);
set_bit(STATUS_SCAN_HW, &priv->status);
ret = iwl_legacy_send_cmd_sync(priv, &cmd);
if (ret)
clear_bit(STATUS_SCAN_HW, &priv->status);
return ret;
}
int iwl4965_manage_ibss_station(struct iwl_priv *priv,
struct ieee80211_vif *vif, bool add)
{
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
if (add)
return iwl4965_add_bssid_station(priv, vif_priv->ctx,
vif->bss_conf.bssid,
&vif_priv->ibss_bssid_sta_id);
return iwl_legacy_remove_station(priv, vif_priv->ibss_bssid_sta_id,
vif->bss_conf.bssid);
}
void iwl4965_free_tfds_in_queue(struct iwl_priv *priv,
int sta_id, int tid, int freed)
{
lockdep_assert_held(&priv->sta_lock);
if (priv->stations[sta_id].tid[tid].tfds_in_queue >= freed)
priv->stations[sta_id].tid[tid].tfds_in_queue -= freed;
else {
IWL_DEBUG_TX(priv, "free more than tfds_in_queue (%u:%d)\n",
priv->stations[sta_id].tid[tid].tfds_in_queue,
freed);
priv->stations[sta_id].tid[tid].tfds_in_queue = 0;
}
}
static bool iwl4965_is_single_rx_stream(struct iwl_priv *priv)
{
return priv->current_ht_config.smps == IEEE80211_SMPS_STATIC ||
priv->current_ht_config.single_chain_sufficient;
}
static int iwl4965_get_active_rx_chain_count(struct iwl_priv *priv)
{
if (iwl4965_is_single_rx_stream(priv))
return IWL_NUM_RX_CHAINS_SINGLE;
else
return IWL_NUM_RX_CHAINS_MULTIPLE;
}
static int
iwl4965_get_idle_rx_chain_count(struct iwl_priv *priv, int active_cnt)
{
switch (priv->current_ht_config.smps) {
case IEEE80211_SMPS_STATIC:
case IEEE80211_SMPS_DYNAMIC:
return IWL_NUM_IDLE_CHAINS_SINGLE;
case IEEE80211_SMPS_OFF:
return active_cnt;
default:
WARN(1, "invalid SMPS mode %d",
priv->current_ht_config.smps);
return active_cnt;
}
}
static u8 iwl4965_count_chain_bitmap(u32 chain_bitmap)
{
u8 res;
res = (chain_bitmap & BIT(0)) >> 0;
res += (chain_bitmap & BIT(1)) >> 1;
res += (chain_bitmap & BIT(2)) >> 2;
res += (chain_bitmap & BIT(3)) >> 3;
return res;
}
void iwl4965_set_rxon_chain(struct iwl_priv *priv, struct iwl_rxon_context *ctx)
{
bool is_single = iwl4965_is_single_rx_stream(priv);
bool is_cam = !test_bit(STATUS_POWER_PMI, &priv->status);
u8 idle_rx_cnt, active_rx_cnt, valid_rx_cnt;
u32 active_chains;
u16 rx_chain;
if (priv->chain_noise_data.active_chains)
active_chains = priv->chain_noise_data.active_chains;
else
active_chains = priv->hw_params.valid_rx_ant;
rx_chain = active_chains << RXON_RX_CHAIN_VALID_POS;
active_rx_cnt = iwl4965_get_active_rx_chain_count(priv);
idle_rx_cnt = iwl4965_get_idle_rx_chain_count(priv, active_rx_cnt);
valid_rx_cnt = iwl4965_count_chain_bitmap(active_chains);
if (valid_rx_cnt < active_rx_cnt)
active_rx_cnt = valid_rx_cnt;
if (valid_rx_cnt < idle_rx_cnt)
idle_rx_cnt = valid_rx_cnt;
rx_chain |= active_rx_cnt << RXON_RX_CHAIN_MIMO_CNT_POS;
rx_chain |= idle_rx_cnt << RXON_RX_CHAIN_CNT_POS;
ctx->staging.rx_chain = cpu_to_le16(rx_chain);
if (!is_single && (active_rx_cnt >= IWL_NUM_RX_CHAINS_SINGLE) && is_cam)
ctx->staging.rx_chain |= RXON_RX_CHAIN_MIMO_FORCE_MSK;
else
ctx->staging.rx_chain &= ~RXON_RX_CHAIN_MIMO_FORCE_MSK;
IWL_DEBUG_ASSOC(priv, "rx_chain=0x%X active=%d idle=%d\n",
ctx->staging.rx_chain,
active_rx_cnt, idle_rx_cnt);
WARN_ON(active_rx_cnt == 0 || idle_rx_cnt == 0 ||
active_rx_cnt < idle_rx_cnt);
}
u8 iwl4965_toggle_tx_ant(struct iwl_priv *priv, u8 ant, u8 valid)
{
int i;
u8 ind = ant;
for (i = 0; i < RATE_ANT_NUM - 1; i++) {
ind = (ind + 1) < RATE_ANT_NUM ? ind + 1 : 0;
if (valid & BIT(ind))
return ind;
}
return ant;
}
static const char *iwl4965_get_fh_string(int cmd)
{
switch (cmd) {
IWL_CMD(FH_RSCSR_CHNL0_STTS_WPTR_REG);
IWL_CMD(FH_RSCSR_CHNL0_RBDCB_BASE_REG);
IWL_CMD(FH_RSCSR_CHNL0_WPTR);
IWL_CMD(FH_MEM_RCSR_CHNL0_CONFIG_REG);
IWL_CMD(FH_MEM_RSSR_SHARED_CTRL_REG);
IWL_CMD(FH_MEM_RSSR_RX_STATUS_REG);
IWL_CMD(FH_MEM_RSSR_RX_ENABLE_ERR_IRQ2DRV);
IWL_CMD(FH_TSSR_TX_STATUS_REG);
IWL_CMD(FH_TSSR_TX_ERROR_REG);
default:
return "UNKNOWN";
}
}
int iwl4965_dump_fh(struct iwl_priv *priv, char **buf, bool display)
{
int i;
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
int pos = 0;
size_t bufsz = 0;
#endif
static const u32 fh_tbl[] = {
FH_RSCSR_CHNL0_STTS_WPTR_REG,
FH_RSCSR_CHNL0_RBDCB_BASE_REG,
FH_RSCSR_CHNL0_WPTR,
FH_MEM_RCSR_CHNL0_CONFIG_REG,
FH_MEM_RSSR_SHARED_CTRL_REG,
FH_MEM_RSSR_RX_STATUS_REG,
FH_MEM_RSSR_RX_ENABLE_ERR_IRQ2DRV,
FH_TSSR_TX_STATUS_REG,
FH_TSSR_TX_ERROR_REG
};
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (display) {
bufsz = ARRAY_SIZE(fh_tbl) * 48 + 40;
*buf = kmalloc(bufsz, GFP_KERNEL);
if (!*buf)
return -ENOMEM;
pos += scnprintf(*buf + pos, bufsz - pos,
"FH register values:\n");
for (i = 0; i < ARRAY_SIZE(fh_tbl); i++) {
pos += scnprintf(*buf + pos, bufsz - pos,
" %34s: 0X%08x\n",
iwl4965_get_fh_string(fh_tbl[i]),
iwl_legacy_read_direct32(priv, fh_tbl[i]));
}
return pos;
}
#endif
IWL_ERR(priv, "FH register values:\n");
for (i = 0; i < ARRAY_SIZE(fh_tbl); i++) {
IWL_ERR(priv, " %34s: 0X%08x\n",
iwl4965_get_fh_string(fh_tbl[i]),
iwl_legacy_read_direct32(priv, fh_tbl[i]));
}
return 0;
}
