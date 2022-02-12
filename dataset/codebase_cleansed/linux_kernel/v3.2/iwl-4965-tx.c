static inline int iwl4965_get_ac_from_tid(u16 tid)
{
if (likely(tid < ARRAY_SIZE(tid_to_ac)))
return tid_to_ac[tid];
return -EINVAL;
}
static inline int
iwl4965_get_fifo_from_tid(struct iwl_rxon_context *ctx, u16 tid)
{
if (likely(tid < ARRAY_SIZE(tid_to_ac)))
return ctx->ac_to_fifo[tid_to_ac[tid]];
return -EINVAL;
}
static void iwl4965_tx_cmd_build_basic(struct iwl_priv *priv,
struct sk_buff *skb,
struct iwl_tx_cmd *tx_cmd,
struct ieee80211_tx_info *info,
struct ieee80211_hdr *hdr,
u8 std_id)
{
__le16 fc = hdr->frame_control;
__le32 tx_flags = tx_cmd->tx_flags;
tx_cmd->stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
if (!(info->flags & IEEE80211_TX_CTL_NO_ACK)) {
tx_flags |= TX_CMD_FLG_ACK_MSK;
if (ieee80211_is_mgmt(fc))
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
if (ieee80211_is_probe_resp(fc) &&
!(le16_to_cpu(hdr->seq_ctrl) & 0xf))
tx_flags |= TX_CMD_FLG_TSF_MSK;
} else {
tx_flags &= (~TX_CMD_FLG_ACK_MSK);
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
}
if (ieee80211_is_back_req(fc))
tx_flags |= TX_CMD_FLG_ACK_MSK | TX_CMD_FLG_IMM_BA_RSP_MASK;
tx_cmd->sta_id = std_id;
if (ieee80211_has_morefrags(fc))
tx_flags |= TX_CMD_FLG_MORE_FRAG_MSK;
if (ieee80211_is_data_qos(fc)) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
tx_cmd->tid_tspec = qc[0] & 0xf;
tx_flags &= ~TX_CMD_FLG_SEQ_CTL_MSK;
} else {
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
}
iwl_legacy_tx_cmd_protection(priv, info, fc, &tx_flags);
tx_flags &= ~(TX_CMD_FLG_ANT_SEL_MSK);
if (ieee80211_is_mgmt(fc)) {
if (ieee80211_is_assoc_req(fc) || ieee80211_is_reassoc_req(fc))
tx_cmd->timeout.pm_frame_timeout = cpu_to_le16(3);
else
tx_cmd->timeout.pm_frame_timeout = cpu_to_le16(2);
} else {
tx_cmd->timeout.pm_frame_timeout = 0;
}
tx_cmd->driver_txop = 0;
tx_cmd->tx_flags = tx_flags;
tx_cmd->next_frame_len = 0;
}
static void iwl4965_tx_cmd_build_rate(struct iwl_priv *priv,
struct iwl_tx_cmd *tx_cmd,
struct ieee80211_tx_info *info,
__le16 fc)
{
u32 rate_flags;
int rate_idx;
u8 rts_retry_limit;
u8 data_retry_limit;
u8 rate_plcp;
if (ieee80211_is_probe_resp(fc))
data_retry_limit = 3;
else
data_retry_limit = IWL4965_DEFAULT_TX_RETRY;
tx_cmd->data_retry_limit = data_retry_limit;
rts_retry_limit = RTS_DFAULT_RETRY_LIMIT;
if (data_retry_limit < rts_retry_limit)
rts_retry_limit = data_retry_limit;
tx_cmd->rts_retry_limit = rts_retry_limit;
if (ieee80211_is_data(fc)) {
tx_cmd->initial_rate_index = 0;
tx_cmd->tx_flags |= TX_CMD_FLG_STA_RATE_MSK;
return;
}
rate_idx = info->control.rates[0].idx;
if (info->control.rates[0].flags & IEEE80211_TX_RC_MCS ||
(rate_idx < 0) || (rate_idx > IWL_RATE_COUNT_LEGACY))
rate_idx = rate_lowest_index(&priv->bands[info->band],
info->control.sta);
if (info->band == IEEE80211_BAND_5GHZ)
rate_idx += IWL_FIRST_OFDM_RATE;
rate_plcp = iwlegacy_rates[rate_idx].plcp;
rate_flags = 0;
if ((rate_idx >= IWL_FIRST_CCK_RATE) && (rate_idx <= IWL_LAST_CCK_RATE))
rate_flags |= RATE_MCS_CCK_MSK;
priv->mgmt_tx_ant = iwl4965_toggle_tx_ant(priv, priv->mgmt_tx_ant,
priv->hw_params.valid_tx_ant);
rate_flags |= iwl4965_ant_idx_to_flags(priv->mgmt_tx_ant);
tx_cmd->rate_n_flags = iwl4965_hw_set_rate_n_flags(rate_plcp, rate_flags);
}
static void iwl4965_tx_cmd_build_hwcrypto(struct iwl_priv *priv,
struct ieee80211_tx_info *info,
struct iwl_tx_cmd *tx_cmd,
struct sk_buff *skb_frag,
int sta_id)
{
struct ieee80211_key_conf *keyconf = info->control.hw_key;
switch (keyconf->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
tx_cmd->sec_ctl = TX_CMD_SEC_CCM;
memcpy(tx_cmd->key, keyconf->key, keyconf->keylen);
if (info->flags & IEEE80211_TX_CTL_AMPDU)
tx_cmd->tx_flags |= TX_CMD_FLG_AGG_CCMP_MSK;
IWL_DEBUG_TX(priv, "tx_cmd with AES hwcrypto\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
tx_cmd->sec_ctl = TX_CMD_SEC_TKIP;
ieee80211_get_tkip_p2k(keyconf, skb_frag, tx_cmd->key);
IWL_DEBUG_TX(priv, "tx_cmd with tkip hwcrypto\n");
break;
case WLAN_CIPHER_SUITE_WEP104:
tx_cmd->sec_ctl |= TX_CMD_SEC_KEY128;
case WLAN_CIPHER_SUITE_WEP40:
tx_cmd->sec_ctl |= (TX_CMD_SEC_WEP |
(keyconf->keyidx & TX_CMD_SEC_MSK) << TX_CMD_SEC_SHIFT);
memcpy(&tx_cmd->key[3], keyconf->key, keyconf->keylen);
IWL_DEBUG_TX(priv, "Configuring packet for WEP encryption "
"with key %d\n", keyconf->keyidx);
break;
default:
IWL_ERR(priv, "Unknown encode cipher %x\n", keyconf->cipher);
break;
}
}
int iwl4965_tx_skb(struct iwl_priv *priv, struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_sta *sta = info->control.sta;
struct iwl_station_priv *sta_priv = NULL;
struct iwl_tx_queue *txq;
struct iwl_queue *q;
struct iwl_device_cmd *out_cmd;
struct iwl_cmd_meta *out_meta;
struct iwl_tx_cmd *tx_cmd;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
int txq_id;
dma_addr_t phys_addr;
dma_addr_t txcmd_phys;
dma_addr_t scratch_phys;
u16 len, firstlen, secondlen;
u16 seq_number = 0;
__le16 fc;
u8 hdr_len;
u8 sta_id;
u8 wait_write_ptr = 0;
u8 tid = 0;
u8 *qc = NULL;
unsigned long flags;
bool is_agg = false;
if (info->control.vif)
ctx = iwl_legacy_rxon_ctx_from_vif(info->control.vif);
spin_lock_irqsave(&priv->lock, flags);
if (iwl_legacy_is_rfkill(priv)) {
IWL_DEBUG_DROP(priv, "Dropping - RF KILL\n");
goto drop_unlock;
}
fc = hdr->frame_control;
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (ieee80211_is_auth(fc))
IWL_DEBUG_TX(priv, "Sending AUTH frame\n");
else if (ieee80211_is_assoc_req(fc))
IWL_DEBUG_TX(priv, "Sending ASSOC frame\n");
else if (ieee80211_is_reassoc_req(fc))
IWL_DEBUG_TX(priv, "Sending REASSOC frame\n");
#endif
hdr_len = ieee80211_hdrlen(fc);
if (!ieee80211_is_data(fc))
sta_id = ctx->bcast_sta_id;
else {
sta_id = iwl_legacy_sta_id_or_broadcast(priv, ctx, info->control.sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_DEBUG_DROP(priv, "Dropping - INVALID STATION: %pM\n",
hdr->addr1);
goto drop_unlock;
}
}
IWL_DEBUG_TX(priv, "station Id %d\n", sta_id);
if (sta)
sta_priv = (void *)sta->drv_priv;
if (sta_priv && sta_priv->asleep &&
(info->flags & IEEE80211_TX_CTL_POLL_RESPONSE)) {
iwl4965_sta_modify_sleep_tx_count(priv, sta_id, 1);
}
if (info->flags & IEEE80211_TX_CTL_SEND_AFTER_DTIM) {
txq_id = ctx->mcast_queue;
hdr->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
} else
txq_id = ctx->ac_to_queue[skb_get_queue_mapping(skb)];
spin_lock(&priv->sta_lock);
if (ieee80211_is_data_qos(fc)) {
qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & IEEE80211_QOS_CTL_TID_MASK;
if (WARN_ON_ONCE(tid >= MAX_TID_COUNT)) {
spin_unlock(&priv->sta_lock);
goto drop_unlock;
}
seq_number = priv->stations[sta_id].tid[tid].seq_number;
seq_number &= IEEE80211_SCTL_SEQ;
hdr->seq_ctrl = hdr->seq_ctrl &
cpu_to_le16(IEEE80211_SCTL_FRAG);
hdr->seq_ctrl |= cpu_to_le16(seq_number);
seq_number += 0x10;
if (info->flags & IEEE80211_TX_CTL_AMPDU &&
priv->stations[sta_id].tid[tid].agg.state == IWL_AGG_ON) {
txq_id = priv->stations[sta_id].tid[tid].agg.txq_id;
is_agg = true;
}
}
txq = &priv->txq[txq_id];
q = &txq->q;
if (unlikely(iwl_legacy_queue_space(q) < q->high_mark)) {
spin_unlock(&priv->sta_lock);
goto drop_unlock;
}
if (ieee80211_is_data_qos(fc)) {
priv->stations[sta_id].tid[tid].tfds_in_queue++;
if (!ieee80211_has_morefrags(fc))
priv->stations[sta_id].tid[tid].seq_number = seq_number;
}
spin_unlock(&priv->sta_lock);
memset(&(txq->txb[q->write_ptr]), 0, sizeof(struct iwl_tx_info));
txq->txb[q->write_ptr].skb = skb;
txq->txb[q->write_ptr].ctx = ctx;
out_cmd = txq->cmd[q->write_ptr];
out_meta = &txq->meta[q->write_ptr];
tx_cmd = &out_cmd->cmd.tx;
memset(&out_cmd->hdr, 0, sizeof(out_cmd->hdr));
memset(tx_cmd, 0, sizeof(struct iwl_tx_cmd));
out_cmd->hdr.cmd = REPLY_TX;
out_cmd->hdr.sequence = cpu_to_le16((u16)(QUEUE_TO_SEQ(txq_id) |
INDEX_TO_SEQ(q->write_ptr)));
memcpy(tx_cmd->hdr, hdr, hdr_len);
len = (u16)skb->len;
tx_cmd->len = cpu_to_le16(len);
if (info->control.hw_key)
iwl4965_tx_cmd_build_hwcrypto(priv, info, tx_cmd, skb, sta_id);
iwl4965_tx_cmd_build_basic(priv, skb, tx_cmd, info, hdr, sta_id);
iwl_legacy_dbg_log_tx_data_frame(priv, len, hdr);
iwl4965_tx_cmd_build_rate(priv, tx_cmd, info, fc);
iwl_legacy_update_stats(priv, true, fc, len);
len = sizeof(struct iwl_tx_cmd) +
sizeof(struct iwl_cmd_header) + hdr_len;
firstlen = (len + 3) & ~3;
if (firstlen != len)
tx_cmd->tx_flags |= TX_CMD_FLG_MH_PAD_MSK;
txcmd_phys = pci_map_single(priv->pci_dev,
&out_cmd->hdr, firstlen,
PCI_DMA_BIDIRECTIONAL);
dma_unmap_addr_set(out_meta, mapping, txcmd_phys);
dma_unmap_len_set(out_meta, len, firstlen);
priv->cfg->ops->lib->txq_attach_buf_to_tfd(priv, txq,
txcmd_phys, firstlen, 1, 0);
if (!ieee80211_has_morefrags(hdr->frame_control)) {
txq->need_update = 1;
} else {
wait_write_ptr = 1;
txq->need_update = 0;
}
secondlen = skb->len - hdr_len;
if (secondlen > 0) {
phys_addr = pci_map_single(priv->pci_dev, skb->data + hdr_len,
secondlen, PCI_DMA_TODEVICE);
priv->cfg->ops->lib->txq_attach_buf_to_tfd(priv, txq,
phys_addr, secondlen,
0, 0);
}
scratch_phys = txcmd_phys + sizeof(struct iwl_cmd_header) +
offsetof(struct iwl_tx_cmd, scratch);
pci_dma_sync_single_for_cpu(priv->pci_dev, txcmd_phys,
firstlen, PCI_DMA_BIDIRECTIONAL);
tx_cmd->dram_lsb_ptr = cpu_to_le32(scratch_phys);
tx_cmd->dram_msb_ptr = iwl_legacy_get_dma_hi_addr(scratch_phys);
IWL_DEBUG_TX(priv, "sequence nr = 0X%x\n",
le16_to_cpu(out_cmd->hdr.sequence));
IWL_DEBUG_TX(priv, "tx_flags = 0X%x\n", le32_to_cpu(tx_cmd->tx_flags));
iwl_print_hex_dump(priv, IWL_DL_TX, (u8 *)tx_cmd, sizeof(*tx_cmd));
iwl_print_hex_dump(priv, IWL_DL_TX, (u8 *)tx_cmd->hdr, hdr_len);
if (info->flags & IEEE80211_TX_CTL_AMPDU)
priv->cfg->ops->lib->txq_update_byte_cnt_tbl(priv, txq,
le16_to_cpu(tx_cmd->len));
pci_dma_sync_single_for_device(priv->pci_dev, txcmd_phys,
firstlen, PCI_DMA_BIDIRECTIONAL);
trace_iwlwifi_legacy_dev_tx(priv,
&((struct iwl_tfd *)txq->tfds)[txq->q.write_ptr],
sizeof(struct iwl_tfd),
&out_cmd->hdr, firstlen,
skb->data + hdr_len, secondlen);
q->write_ptr = iwl_legacy_queue_inc_wrap(q->write_ptr, q->n_bd);
iwl_legacy_txq_update_write_ptr(priv, txq);
spin_unlock_irqrestore(&priv->lock, flags);
if (sta_priv && sta_priv->client && !is_agg)
atomic_inc(&sta_priv->pending_frames);
if ((iwl_legacy_queue_space(q) < q->high_mark) &&
priv->mac80211_registered) {
if (wait_write_ptr) {
spin_lock_irqsave(&priv->lock, flags);
txq->need_update = 1;
iwl_legacy_txq_update_write_ptr(priv, txq);
spin_unlock_irqrestore(&priv->lock, flags);
} else {
iwl_legacy_stop_queue(priv, txq);
}
}
return 0;
drop_unlock:
spin_unlock_irqrestore(&priv->lock, flags);
return -1;
}
static inline int iwl4965_alloc_dma_ptr(struct iwl_priv *priv,
struct iwl_dma_ptr *ptr, size_t size)
{
ptr->addr = dma_alloc_coherent(&priv->pci_dev->dev, size, &ptr->dma,
GFP_KERNEL);
if (!ptr->addr)
return -ENOMEM;
ptr->size = size;
return 0;
}
static inline void iwl4965_free_dma_ptr(struct iwl_priv *priv,
struct iwl_dma_ptr *ptr)
{
if (unlikely(!ptr->addr))
return;
dma_free_coherent(&priv->pci_dev->dev, ptr->size, ptr->addr, ptr->dma);
memset(ptr, 0, sizeof(*ptr));
}
void iwl4965_hw_txq_ctx_free(struct iwl_priv *priv)
{
int txq_id;
if (priv->txq) {
for (txq_id = 0; txq_id < priv->hw_params.max_txq_num; txq_id++)
if (txq_id == priv->cmd_queue)
iwl_legacy_cmd_queue_free(priv);
else
iwl_legacy_tx_queue_free(priv, txq_id);
}
iwl4965_free_dma_ptr(priv, &priv->kw);
iwl4965_free_dma_ptr(priv, &priv->scd_bc_tbls);
iwl_legacy_txq_mem(priv);
}
int iwl4965_txq_ctx_alloc(struct iwl_priv *priv)
{
int ret;
int txq_id, slots_num;
unsigned long flags;
iwl4965_hw_txq_ctx_free(priv);
ret = iwl4965_alloc_dma_ptr(priv, &priv->scd_bc_tbls,
priv->hw_params.scd_bc_tbls_size);
if (ret) {
IWL_ERR(priv, "Scheduler BC Table allocation failed\n");
goto error_bc_tbls;
}
ret = iwl4965_alloc_dma_ptr(priv, &priv->kw, IWL_KW_SIZE);
if (ret) {
IWL_ERR(priv, "Keep Warm allocation failed\n");
goto error_kw;
}
ret = iwl_legacy_alloc_txq_mem(priv);
if (ret)
goto error;
spin_lock_irqsave(&priv->lock, flags);
iwl4965_txq_set_sched(priv, 0);
iwl_legacy_write_direct32(priv, FH_KW_MEM_ADDR_REG, priv->kw.dma >> 4);
spin_unlock_irqrestore(&priv->lock, flags);
for (txq_id = 0; txq_id < priv->hw_params.max_txq_num; txq_id++) {
slots_num = (txq_id == priv->cmd_queue) ?
TFD_CMD_SLOTS : TFD_TX_CMD_SLOTS;
ret = iwl_legacy_tx_queue_init(priv,
&priv->txq[txq_id], slots_num,
txq_id);
if (ret) {
IWL_ERR(priv, "Tx %d queue init failed\n", txq_id);
goto error;
}
}
return ret;
error:
iwl4965_hw_txq_ctx_free(priv);
iwl4965_free_dma_ptr(priv, &priv->kw);
error_kw:
iwl4965_free_dma_ptr(priv, &priv->scd_bc_tbls);
error_bc_tbls:
return ret;
}
void iwl4965_txq_ctx_reset(struct iwl_priv *priv)
{
int txq_id, slots_num;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
iwl4965_txq_set_sched(priv, 0);
iwl_legacy_write_direct32(priv, FH_KW_MEM_ADDR_REG, priv->kw.dma >> 4);
spin_unlock_irqrestore(&priv->lock, flags);
for (txq_id = 0; txq_id < priv->hw_params.max_txq_num; txq_id++) {
slots_num = txq_id == priv->cmd_queue ?
TFD_CMD_SLOTS : TFD_TX_CMD_SLOTS;
iwl_legacy_tx_queue_reset(priv, &priv->txq[txq_id],
slots_num, txq_id);
}
}
void iwl4965_txq_ctx_stop(struct iwl_priv *priv)
{
int ch, txq_id;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
iwl4965_txq_set_sched(priv, 0);
for (ch = 0; ch < priv->hw_params.dma_chnl_num; ch++) {
iwl_legacy_write_direct32(priv,
FH_TCSR_CHNL_TX_CONFIG_REG(ch), 0x0);
if (iwl_poll_direct_bit(priv, FH_TSSR_TX_STATUS_REG,
FH_TSSR_TX_STATUS_REG_MSK_CHNL_IDLE(ch),
1000))
IWL_ERR(priv, "Failing on timeout while stopping"
" DMA channel %d [0x%08x]", ch,
iwl_legacy_read_direct32(priv,
FH_TSSR_TX_STATUS_REG));
}
spin_unlock_irqrestore(&priv->lock, flags);
if (!priv->txq)
return;
for (txq_id = 0; txq_id < priv->hw_params.max_txq_num; txq_id++)
if (txq_id == priv->cmd_queue)
iwl_legacy_cmd_queue_unmap(priv);
else
iwl_legacy_tx_queue_unmap(priv, txq_id);
}
static int iwl4965_txq_ctx_activate_free(struct iwl_priv *priv)
{
int txq_id;
for (txq_id = 0; txq_id < priv->hw_params.max_txq_num; txq_id++)
if (!test_and_set_bit(txq_id, &priv->txq_ctx_active_msk))
return txq_id;
return -1;
}
static void iwl4965_tx_queue_stop_scheduler(struct iwl_priv *priv,
u16 txq_id)
{
iwl_legacy_write_prph(priv,
IWL49_SCD_QUEUE_STATUS_BITS(txq_id),
(0 << IWL49_SCD_QUEUE_STTS_REG_POS_ACTIVE)|
(1 << IWL49_SCD_QUEUE_STTS_REG_POS_SCD_ACT_EN));
}
static int iwl4965_tx_queue_set_q2ratid(struct iwl_priv *priv, u16 ra_tid,
u16 txq_id)
{
u32 tbl_dw_addr;
u32 tbl_dw;
u16 scd_q2ratid;
scd_q2ratid = ra_tid & IWL_SCD_QUEUE_RA_TID_MAP_RATID_MSK;
tbl_dw_addr = priv->scd_base_addr +
IWL49_SCD_TRANSLATE_TBL_OFFSET_QUEUE(txq_id);
tbl_dw = iwl_legacy_read_targ_mem(priv, tbl_dw_addr);
if (txq_id & 0x1)
tbl_dw = (scd_q2ratid << 16) | (tbl_dw & 0x0000FFFF);
else
tbl_dw = scd_q2ratid | (tbl_dw & 0xFFFF0000);
iwl_legacy_write_targ_mem(priv, tbl_dw_addr, tbl_dw);
return 0;
}
static int iwl4965_txq_agg_enable(struct iwl_priv *priv, int txq_id,
int tx_fifo, int sta_id, int tid, u16 ssn_idx)
{
unsigned long flags;
u16 ra_tid;
int ret;
if ((IWL49_FIRST_AMPDU_QUEUE > txq_id) ||
(IWL49_FIRST_AMPDU_QUEUE +
priv->cfg->base_params->num_of_ampdu_queues <= txq_id)) {
IWL_WARN(priv,
"queue number out of range: %d, must be %d to %d\n",
txq_id, IWL49_FIRST_AMPDU_QUEUE,
IWL49_FIRST_AMPDU_QUEUE +
priv->cfg->base_params->num_of_ampdu_queues - 1);
return -EINVAL;
}
ra_tid = BUILD_RAxTID(sta_id, tid);
ret = iwl4965_sta_tx_modify_enable_tid(priv, sta_id, tid);
if (ret)
return ret;
spin_lock_irqsave(&priv->lock, flags);
iwl4965_tx_queue_stop_scheduler(priv, txq_id);
iwl4965_tx_queue_set_q2ratid(priv, ra_tid, txq_id);
iwl_legacy_set_bits_prph(priv, IWL49_SCD_QUEUECHAIN_SEL, (1 << txq_id));
priv->txq[txq_id].q.read_ptr = (ssn_idx & 0xff);
priv->txq[txq_id].q.write_ptr = (ssn_idx & 0xff);
iwl4965_set_wr_ptrs(priv, txq_id, ssn_idx);
iwl_legacy_write_targ_mem(priv,
priv->scd_base_addr + IWL49_SCD_CONTEXT_QUEUE_OFFSET(txq_id),
(SCD_WIN_SIZE << IWL49_SCD_QUEUE_CTX_REG1_WIN_SIZE_POS) &
IWL49_SCD_QUEUE_CTX_REG1_WIN_SIZE_MSK);
iwl_legacy_write_targ_mem(priv, priv->scd_base_addr +
IWL49_SCD_CONTEXT_QUEUE_OFFSET(txq_id) + sizeof(u32),
(SCD_FRAME_LIMIT << IWL49_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_POS)
& IWL49_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_MSK);
iwl_legacy_set_bits_prph(priv, IWL49_SCD_INTERRUPT_MASK, (1 << txq_id));
iwl4965_tx_queue_set_status(priv, &priv->txq[txq_id], tx_fifo, 1);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
int iwl4965_tx_agg_start(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid, u16 *ssn)
{
int sta_id;
int tx_fifo;
int txq_id;
int ret;
unsigned long flags;
struct iwl_tid_data *tid_data;
tx_fifo = iwl4965_get_fifo_from_tid(iwl_legacy_rxon_ctx_from_vif(vif), tid);
if (unlikely(tx_fifo < 0))
return tx_fifo;
IWL_WARN(priv, "%s on ra = %pM tid = %d\n",
__func__, sta->addr, tid);
sta_id = iwl_legacy_sta_id(sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_ERR(priv, "Start AGG on invalid station\n");
return -ENXIO;
}
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
if (priv->stations[sta_id].tid[tid].agg.state != IWL_AGG_OFF) {
IWL_ERR(priv, "Start AGG when state is not IWL_AGG_OFF !\n");
return -ENXIO;
}
txq_id = iwl4965_txq_ctx_activate_free(priv);
if (txq_id == -1) {
IWL_ERR(priv, "No free aggregation queue available\n");
return -ENXIO;
}
spin_lock_irqsave(&priv->sta_lock, flags);
tid_data = &priv->stations[sta_id].tid[tid];
*ssn = SEQ_TO_SN(tid_data->seq_number);
tid_data->agg.txq_id = txq_id;
iwl_legacy_set_swq_id(&priv->txq[txq_id],
iwl4965_get_ac_from_tid(tid), txq_id);
spin_unlock_irqrestore(&priv->sta_lock, flags);
ret = iwl4965_txq_agg_enable(priv, txq_id, tx_fifo,
sta_id, tid, *ssn);
if (ret)
return ret;
spin_lock_irqsave(&priv->sta_lock, flags);
tid_data = &priv->stations[sta_id].tid[tid];
if (tid_data->tfds_in_queue == 0) {
IWL_DEBUG_HT(priv, "HW queue is empty\n");
tid_data->agg.state = IWL_AGG_ON;
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
} else {
IWL_DEBUG_HT(priv,
"HW queue is NOT empty: %d packets in HW queue\n",
tid_data->tfds_in_queue);
tid_data->agg.state = IWL_EMPTYING_HW_QUEUE_ADDBA;
}
spin_unlock_irqrestore(&priv->sta_lock, flags);
return ret;
}
static int iwl4965_txq_agg_disable(struct iwl_priv *priv, u16 txq_id,
u16 ssn_idx, u8 tx_fifo)
{
if ((IWL49_FIRST_AMPDU_QUEUE > txq_id) ||
(IWL49_FIRST_AMPDU_QUEUE +
priv->cfg->base_params->num_of_ampdu_queues <= txq_id)) {
IWL_WARN(priv,
"queue number out of range: %d, must be %d to %d\n",
txq_id, IWL49_FIRST_AMPDU_QUEUE,
IWL49_FIRST_AMPDU_QUEUE +
priv->cfg->base_params->num_of_ampdu_queues - 1);
return -EINVAL;
}
iwl4965_tx_queue_stop_scheduler(priv, txq_id);
iwl_legacy_clear_bits_prph(priv,
IWL49_SCD_QUEUECHAIN_SEL, (1 << txq_id));
priv->txq[txq_id].q.read_ptr = (ssn_idx & 0xff);
priv->txq[txq_id].q.write_ptr = (ssn_idx & 0xff);
iwl4965_set_wr_ptrs(priv, txq_id, ssn_idx);
iwl_legacy_clear_bits_prph(priv,
IWL49_SCD_INTERRUPT_MASK, (1 << txq_id));
iwl_txq_ctx_deactivate(priv, txq_id);
iwl4965_tx_queue_set_status(priv, &priv->txq[txq_id], tx_fifo, 0);
return 0;
}
int iwl4965_tx_agg_stop(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid)
{
int tx_fifo_id, txq_id, sta_id, ssn;
struct iwl_tid_data *tid_data;
int write_ptr, read_ptr;
unsigned long flags;
tx_fifo_id = iwl4965_get_fifo_from_tid(iwl_legacy_rxon_ctx_from_vif(vif), tid);
if (unlikely(tx_fifo_id < 0))
return tx_fifo_id;
sta_id = iwl_legacy_sta_id(sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_ERR(priv, "Invalid station for AGG tid %d\n", tid);
return -ENXIO;
}
spin_lock_irqsave(&priv->sta_lock, flags);
tid_data = &priv->stations[sta_id].tid[tid];
ssn = (tid_data->seq_number & IEEE80211_SCTL_SEQ) >> 4;
txq_id = tid_data->agg.txq_id;
switch (priv->stations[sta_id].tid[tid].agg.state) {
case IWL_EMPTYING_HW_QUEUE_ADDBA:
IWL_DEBUG_HT(priv, "AGG stop before setup done\n");
goto turn_off;
case IWL_AGG_ON:
break;
default:
IWL_WARN(priv, "Stopping AGG while state not ON or starting\n");
}
write_ptr = priv->txq[txq_id].q.write_ptr;
read_ptr = priv->txq[txq_id].q.read_ptr;
if (write_ptr != read_ptr) {
IWL_DEBUG_HT(priv, "Stopping a non empty AGG HW QUEUE\n");
priv->stations[sta_id].tid[tid].agg.state =
IWL_EMPTYING_HW_QUEUE_DELBA;
spin_unlock_irqrestore(&priv->sta_lock, flags);
return 0;
}
IWL_DEBUG_HT(priv, "HW queue is empty\n");
turn_off:
priv->stations[sta_id].tid[tid].agg.state = IWL_AGG_OFF;
spin_unlock(&priv->sta_lock);
spin_lock(&priv->lock);
iwl4965_txq_agg_disable(priv, txq_id, ssn, tx_fifo_id);
spin_unlock_irqrestore(&priv->lock, flags);
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
return 0;
}
int iwl4965_txq_check_empty(struct iwl_priv *priv,
int sta_id, u8 tid, int txq_id)
{
struct iwl_queue *q = &priv->txq[txq_id].q;
u8 *addr = priv->stations[sta_id].sta.sta.addr;
struct iwl_tid_data *tid_data = &priv->stations[sta_id].tid[tid];
struct iwl_rxon_context *ctx;
ctx = &priv->contexts[priv->stations[sta_id].ctxid];
lockdep_assert_held(&priv->sta_lock);
switch (priv->stations[sta_id].tid[tid].agg.state) {
case IWL_EMPTYING_HW_QUEUE_DELBA:
if ((txq_id == tid_data->agg.txq_id) &&
(q->read_ptr == q->write_ptr)) {
u16 ssn = SEQ_TO_SN(tid_data->seq_number);
int tx_fifo = iwl4965_get_fifo_from_tid(ctx, tid);
IWL_DEBUG_HT(priv,
"HW queue empty: continue DELBA flow\n");
iwl4965_txq_agg_disable(priv, txq_id, ssn, tx_fifo);
tid_data->agg.state = IWL_AGG_OFF;
ieee80211_stop_tx_ba_cb_irqsafe(ctx->vif, addr, tid);
}
break;
case IWL_EMPTYING_HW_QUEUE_ADDBA:
if (tid_data->tfds_in_queue == 0) {
IWL_DEBUG_HT(priv,
"HW queue empty: continue ADDBA flow\n");
tid_data->agg.state = IWL_AGG_ON;
ieee80211_start_tx_ba_cb_irqsafe(ctx->vif, addr, tid);
}
break;
}
return 0;
}
static void iwl4965_non_agg_tx_status(struct iwl_priv *priv,
struct iwl_rxon_context *ctx,
const u8 *addr1)
{
struct ieee80211_sta *sta;
struct iwl_station_priv *sta_priv;
rcu_read_lock();
sta = ieee80211_find_sta(ctx->vif, addr1);
if (sta) {
sta_priv = (void *)sta->drv_priv;
if (sta_priv->client &&
atomic_dec_return(&sta_priv->pending_frames) == 0)
ieee80211_sta_block_awake(priv->hw, sta, false);
}
rcu_read_unlock();
}
static void
iwl4965_tx_status(struct iwl_priv *priv, struct iwl_tx_info *tx_info,
bool is_agg)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) tx_info->skb->data;
if (!is_agg)
iwl4965_non_agg_tx_status(priv, tx_info->ctx, hdr->addr1);
ieee80211_tx_status_irqsafe(priv->hw, tx_info->skb);
}
int iwl4965_tx_queue_reclaim(struct iwl_priv *priv, int txq_id, int index)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct iwl_queue *q = &txq->q;
struct iwl_tx_info *tx_info;
int nfreed = 0;
struct ieee80211_hdr *hdr;
if ((index >= q->n_bd) || (iwl_legacy_queue_used(q, index) == 0)) {
IWL_ERR(priv, "Read index for DMA queue txq id (%d), index %d, "
"is out of range [0-%d] %d %d.\n", txq_id,
index, q->n_bd, q->write_ptr, q->read_ptr);
return 0;
}
for (index = iwl_legacy_queue_inc_wrap(index, q->n_bd);
q->read_ptr != index;
q->read_ptr = iwl_legacy_queue_inc_wrap(q->read_ptr, q->n_bd)) {
tx_info = &txq->txb[txq->q.read_ptr];
if (WARN_ON_ONCE(tx_info->skb == NULL))
continue;
hdr = (struct ieee80211_hdr *)tx_info->skb->data;
if (ieee80211_is_data_qos(hdr->frame_control))
nfreed++;
iwl4965_tx_status(priv, tx_info,
txq_id >= IWL4965_FIRST_AMPDU_QUEUE);
tx_info->skb = NULL;
priv->cfg->ops->lib->txq_free_tfd(priv, txq);
}
return nfreed;
}
static int iwl4965_tx_status_reply_compressed_ba(struct iwl_priv *priv,
struct iwl_ht_agg *agg,
struct iwl_compressed_ba_resp *ba_resp)
{
int i, sh, ack;
u16 seq_ctl = le16_to_cpu(ba_resp->seq_ctl);
u16 scd_flow = le16_to_cpu(ba_resp->scd_flow);
int successes = 0;
struct ieee80211_tx_info *info;
u64 bitmap, sent_bitmap;
if (unlikely(!agg->wait_for_ba)) {
if (unlikely(ba_resp->bitmap))
IWL_ERR(priv, "Received BA when not expected\n");
return -EINVAL;
}
agg->wait_for_ba = 0;
IWL_DEBUG_TX_REPLY(priv, "BA %d %d\n", agg->start_idx,
ba_resp->seq_ctl);
sh = agg->start_idx - SEQ_TO_INDEX(seq_ctl >> 4);
if (sh < 0)
sh += 0x100;
if (agg->frame_count > (64 - sh)) {
IWL_DEBUG_TX_REPLY(priv, "more frames than bitmap size");
return -1;
}
bitmap = le64_to_cpu(ba_resp->bitmap) >> sh;
sent_bitmap = bitmap & agg->bitmap;
i = 0;
while (sent_bitmap) {
ack = sent_bitmap & 1ULL;
successes += ack;
IWL_DEBUG_TX_REPLY(priv, "%s ON i=%d idx=%d raw=%d\n",
ack ? "ACK" : "NACK", i,
(agg->start_idx + i) & 0xff,
agg->start_idx + i);
sent_bitmap >>= 1;
++i;
}
IWL_DEBUG_TX_REPLY(priv, "Bitmap %llx\n",
(unsigned long long)bitmap);
info = IEEE80211_SKB_CB(priv->txq[scd_flow].txb[agg->start_idx].skb);
memset(&info->status, 0, sizeof(info->status));
info->flags |= IEEE80211_TX_STAT_ACK;
info->flags |= IEEE80211_TX_STAT_AMPDU;
info->status.ampdu_ack_len = successes;
info->status.ampdu_len = agg->frame_count;
iwl4965_hwrate_to_tx_control(priv, agg->rate_n_flags, info);
return 0;
}
void iwl4965_hwrate_to_tx_control(struct iwl_priv *priv, u32 rate_n_flags,
struct ieee80211_tx_info *info)
{
struct ieee80211_tx_rate *r = &info->control.rates[0];
info->antenna_sel_tx =
((rate_n_flags & RATE_MCS_ANT_ABC_MSK) >> RATE_MCS_ANT_POS);
if (rate_n_flags & RATE_MCS_HT_MSK)
r->flags |= IEEE80211_TX_RC_MCS;
if (rate_n_flags & RATE_MCS_GF_MSK)
r->flags |= IEEE80211_TX_RC_GREEN_FIELD;
if (rate_n_flags & RATE_MCS_HT40_MSK)
r->flags |= IEEE80211_TX_RC_40_MHZ_WIDTH;
if (rate_n_flags & RATE_MCS_DUP_MSK)
r->flags |= IEEE80211_TX_RC_DUP_DATA;
if (rate_n_flags & RATE_MCS_SGI_MSK)
r->flags |= IEEE80211_TX_RC_SHORT_GI;
r->idx = iwl4965_hwrate_to_mac80211_idx(rate_n_flags, info->band);
}
void iwl4965_rx_reply_compressed_ba(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_compressed_ba_resp *ba_resp = &pkt->u.compressed_ba;
struct iwl_tx_queue *txq = NULL;
struct iwl_ht_agg *agg;
int index;
int sta_id;
int tid;
unsigned long flags;
u16 scd_flow = le16_to_cpu(ba_resp->scd_flow);
u16 ba_resp_scd_ssn = le16_to_cpu(ba_resp->scd_ssn);
if (scd_flow >= priv->hw_params.max_txq_num) {
IWL_ERR(priv,
"BUG_ON scd_flow is bigger than number of queues\n");
return;
}
txq = &priv->txq[scd_flow];
sta_id = ba_resp->sta_id;
tid = ba_resp->tid;
agg = &priv->stations[sta_id].tid[tid].agg;
if (unlikely(agg->txq_id != scd_flow)) {
IWL_DEBUG_TX_REPLY(priv,
"BA scd_flow %d does not match txq_id %d\n",
scd_flow, agg->txq_id);
return;
}
index = iwl_legacy_queue_dec_wrap(ba_resp_scd_ssn & 0xff, txq->q.n_bd);
spin_lock_irqsave(&priv->sta_lock, flags);
IWL_DEBUG_TX_REPLY(priv, "REPLY_COMPRESSED_BA [%d] Received from %pM, "
"sta_id = %d\n",
agg->wait_for_ba,
(u8 *) &ba_resp->sta_addr_lo32,
ba_resp->sta_id);
IWL_DEBUG_TX_REPLY(priv, "TID = %d, SeqCtl = %d, bitmap = 0x%llx,"
"scd_flow = "
"%d, scd_ssn = %d\n",
ba_resp->tid,
ba_resp->seq_ctl,
(unsigned long long)le64_to_cpu(ba_resp->bitmap),
ba_resp->scd_flow,
ba_resp->scd_ssn);
IWL_DEBUG_TX_REPLY(priv, "DAT start_idx = %d, bitmap = 0x%llx\n",
agg->start_idx,
(unsigned long long)agg->bitmap);
iwl4965_tx_status_reply_compressed_ba(priv, agg, ba_resp);
if (txq->q.read_ptr != (ba_resp_scd_ssn & 0xff)) {
int freed = iwl4965_tx_queue_reclaim(priv, scd_flow, index);
iwl4965_free_tfds_in_queue(priv, sta_id, tid, freed);
if ((iwl_legacy_queue_space(&txq->q) > txq->q.low_mark) &&
priv->mac80211_registered &&
(agg->state != IWL_EMPTYING_HW_QUEUE_DELBA))
iwl_legacy_wake_queue(priv, txq);
iwl4965_txq_check_empty(priv, sta_id, tid, scd_flow);
}
spin_unlock_irqrestore(&priv->sta_lock, flags);
}
const char *iwl4965_get_tx_fail_reason(u32 status)
{
#define TX_STATUS_FAIL(x) case TX_STATUS_FAIL_ ## x: return #x
#define TX_STATUS_POSTPONE(x) case TX_STATUS_POSTPONE_ ## x: return #x
switch (status & TX_STATUS_MSK) {
case TX_STATUS_SUCCESS:
return "SUCCESS";
TX_STATUS_POSTPONE(DELAY);
TX_STATUS_POSTPONE(FEW_BYTES);
TX_STATUS_POSTPONE(QUIET_PERIOD);
TX_STATUS_POSTPONE(CALC_TTAK);
TX_STATUS_FAIL(INTERNAL_CROSSED_RETRY);
TX_STATUS_FAIL(SHORT_LIMIT);
TX_STATUS_FAIL(LONG_LIMIT);
TX_STATUS_FAIL(FIFO_UNDERRUN);
TX_STATUS_FAIL(DRAIN_FLOW);
TX_STATUS_FAIL(RFKILL_FLUSH);
TX_STATUS_FAIL(LIFE_EXPIRE);
TX_STATUS_FAIL(DEST_PS);
TX_STATUS_FAIL(HOST_ABORTED);
TX_STATUS_FAIL(BT_RETRY);
TX_STATUS_FAIL(STA_INVALID);
TX_STATUS_FAIL(FRAG_DROPPED);
TX_STATUS_FAIL(TID_DISABLE);
TX_STATUS_FAIL(FIFO_FLUSHED);
TX_STATUS_FAIL(INSUFFICIENT_CF_POLL);
TX_STATUS_FAIL(PASSIVE_NO_RX);
TX_STATUS_FAIL(NO_BEACON_ON_RADAR);
}
return "UNKNOWN";
#undef TX_STATUS_FAIL
#undef TX_STATUS_POSTPONE
}
