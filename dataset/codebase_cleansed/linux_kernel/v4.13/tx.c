static void iwlagn_tx_cmd_protection(struct iwl_priv *priv,
struct ieee80211_tx_info *info,
__le16 fc, __le32 *tx_flags)
{
if (info->control.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS ||
info->control.rates[0].flags & IEEE80211_TX_RC_USE_CTS_PROTECT ||
info->flags & IEEE80211_TX_CTL_AMPDU)
*tx_flags |= TX_CMD_FLG_PROT_REQUIRE_MSK;
}
static void iwlagn_tx_cmd_build_basic(struct iwl_priv *priv,
struct sk_buff *skb,
struct iwl_tx_cmd *tx_cmd,
struct ieee80211_tx_info *info,
struct ieee80211_hdr *hdr, u8 sta_id)
{
__le16 fc = hdr->frame_control;
__le32 tx_flags = tx_cmd->tx_flags;
tx_cmd->stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
if (!(info->flags & IEEE80211_TX_CTL_NO_ACK))
tx_flags |= TX_CMD_FLG_ACK_MSK;
else
tx_flags &= ~TX_CMD_FLG_ACK_MSK;
if (ieee80211_is_probe_resp(fc))
tx_flags |= TX_CMD_FLG_TSF_MSK;
else if (ieee80211_is_back_req(fc))
tx_flags |= TX_CMD_FLG_ACK_MSK | TX_CMD_FLG_IMM_BA_RSP_MASK;
else if (info->band == NL80211_BAND_2GHZ &&
priv->lib->bt_params &&
priv->lib->bt_params->advanced_bt_coexist &&
(ieee80211_is_auth(fc) || ieee80211_is_assoc_req(fc) ||
ieee80211_is_reassoc_req(fc) ||
info->control.flags & IEEE80211_TX_CTRL_PORT_CTRL_PROTO))
tx_flags |= TX_CMD_FLG_IGNORE_BT;
tx_cmd->sta_id = sta_id;
if (ieee80211_has_morefrags(fc))
tx_flags |= TX_CMD_FLG_MORE_FRAG_MSK;
if (ieee80211_is_data_qos(fc)) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
tx_cmd->tid_tspec = qc[0] & 0xf;
tx_flags &= ~TX_CMD_FLG_SEQ_CTL_MSK;
} else {
tx_cmd->tid_tspec = IWL_TID_NON_QOS;
if (info->flags & IEEE80211_TX_CTL_ASSIGN_SEQ)
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
else
tx_flags &= ~TX_CMD_FLG_SEQ_CTL_MSK;
}
iwlagn_tx_cmd_protection(priv, info, fc, &tx_flags);
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
static void iwlagn_tx_cmd_build_rate(struct iwl_priv *priv,
struct iwl_tx_cmd *tx_cmd,
struct ieee80211_tx_info *info,
struct ieee80211_sta *sta,
__le16 fc)
{
u32 rate_flags;
int rate_idx;
u8 rts_retry_limit;
u8 data_retry_limit;
u8 rate_plcp;
if (priv->wowlan) {
rts_retry_limit = IWLAGN_LOW_RETRY_LIMIT;
data_retry_limit = IWLAGN_LOW_RETRY_LIMIT;
} else {
rts_retry_limit = IWLAGN_RTS_DFAULT_RETRY_LIMIT;
if (ieee80211_is_probe_resp(fc)) {
data_retry_limit = IWLAGN_MGMT_DFAULT_RETRY_LIMIT;
rts_retry_limit =
min(data_retry_limit, rts_retry_limit);
} else if (ieee80211_is_back_req(fc))
data_retry_limit = IWLAGN_BAR_DFAULT_RETRY_LIMIT;
else
data_retry_limit = IWLAGN_DEFAULT_TX_RETRY;
}
tx_cmd->data_retry_limit = data_retry_limit;
tx_cmd->rts_retry_limit = rts_retry_limit;
if (ieee80211_is_data(fc)) {
tx_cmd->initial_rate_index = 0;
tx_cmd->tx_flags |= TX_CMD_FLG_STA_RATE_MSK;
return;
} else if (ieee80211_is_back_req(fc))
tx_cmd->tx_flags |= TX_CMD_FLG_STA_RATE_MSK;
rate_idx = info->control.rates[0].idx;
if (info->control.rates[0].flags & IEEE80211_TX_RC_MCS ||
(rate_idx < 0) || (rate_idx > IWL_RATE_COUNT_LEGACY))
rate_idx = rate_lowest_index(
&priv->nvm_data->bands[info->band], sta);
if (info->band == NL80211_BAND_5GHZ)
rate_idx += IWL_FIRST_OFDM_RATE;
rate_plcp = iwl_rates[rate_idx].plcp;
rate_flags = 0;
if ((rate_idx >= IWL_FIRST_CCK_RATE) && (rate_idx <= IWL_LAST_CCK_RATE))
rate_flags |= RATE_MCS_CCK_MSK;
if (priv->lib->bt_params &&
priv->lib->bt_params->advanced_bt_coexist &&
priv->bt_full_concurrent) {
priv->mgmt_tx_ant = iwl_toggle_tx_ant(priv, priv->mgmt_tx_ant,
first_antenna(priv->nvm_data->valid_tx_ant));
} else
priv->mgmt_tx_ant = iwl_toggle_tx_ant(
priv, priv->mgmt_tx_ant,
priv->nvm_data->valid_tx_ant);
rate_flags |= iwl_ant_idx_to_flags(priv->mgmt_tx_ant);
tx_cmd->rate_n_flags = iwl_hw_set_rate_n_flags(rate_plcp, rate_flags);
}
static void iwlagn_tx_cmd_build_hwcrypto(struct iwl_priv *priv,
struct ieee80211_tx_info *info,
struct iwl_tx_cmd *tx_cmd,
struct sk_buff *skb_frag)
{
struct ieee80211_key_conf *keyconf = info->control.hw_key;
switch (keyconf->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
tx_cmd->sec_ctl = TX_CMD_SEC_CCM;
memcpy(tx_cmd->key, keyconf->key, keyconf->keylen);
if (info->flags & IEEE80211_TX_CTL_AMPDU)
tx_cmd->tx_flags |= TX_CMD_FLG_AGG_CCMP_MSK;
break;
case WLAN_CIPHER_SUITE_TKIP:
tx_cmd->sec_ctl = TX_CMD_SEC_TKIP;
ieee80211_get_tkip_p2k(keyconf, skb_frag, tx_cmd->key);
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
static int iwl_sta_id_or_broadcast(struct iwl_rxon_context *context,
struct ieee80211_sta *sta)
{
int sta_id;
if (!sta)
return context->bcast_sta_id;
sta_id = iwl_sta_id(sta);
WARN_ON(sta_id == IWL_INVALID_STATION);
return sta_id;
}
int iwlagn_tx_skb(struct iwl_priv *priv,
struct ieee80211_sta *sta,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct iwl_station_priv *sta_priv = NULL;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct iwl_device_cmd *dev_cmd;
struct iwl_tx_cmd *tx_cmd;
__le16 fc;
u8 hdr_len;
u16 len, seq_number = 0;
u8 sta_id, tid = IWL_MAX_TID_COUNT;
bool is_agg = false, is_data_qos = false;
int txq_id;
if (info->control.vif)
ctx = iwl_rxon_ctx_from_vif(info->control.vif);
if (iwl_is_rfkill(priv)) {
IWL_DEBUG_DROP(priv, "Dropping - RF KILL\n");
goto drop_unlock_priv;
}
fc = hdr->frame_control;
#ifdef CONFIG_IWLWIFI_DEBUG
if (ieee80211_is_auth(fc))
IWL_DEBUG_TX(priv, "Sending AUTH frame\n");
else if (ieee80211_is_assoc_req(fc))
IWL_DEBUG_TX(priv, "Sending ASSOC frame\n");
else if (ieee80211_is_reassoc_req(fc))
IWL_DEBUG_TX(priv, "Sending REASSOC frame\n");
#endif
if (unlikely(ieee80211_is_probe_resp(fc))) {
struct iwl_wipan_noa_data *noa_data =
rcu_dereference(priv->noa_data);
if (noa_data &&
pskb_expand_head(skb, 0, noa_data->length,
GFP_ATOMIC) == 0) {
skb_put_data(skb, noa_data->data, noa_data->length);
hdr = (struct ieee80211_hdr *)skb->data;
}
}
hdr_len = ieee80211_hdrlen(fc);
if (!ieee80211_is_data(fc))
sta_id = ctx->bcast_sta_id;
else {
sta_id = iwl_sta_id_or_broadcast(ctx, sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_DEBUG_DROP(priv, "Dropping - INVALID STATION: %pM\n",
hdr->addr1);
goto drop_unlock_priv;
}
}
if (sta)
sta_priv = (void *)sta->drv_priv;
if (sta_priv && sta_priv->asleep &&
(info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER)) {
iwl_sta_modify_sleep_tx_count(priv, sta_id, 1);
}
dev_cmd = iwl_trans_alloc_tx_cmd(priv->trans);
if (unlikely(!dev_cmd))
goto drop_unlock_priv;
memset(dev_cmd, 0, sizeof(*dev_cmd));
dev_cmd->hdr.cmd = REPLY_TX;
tx_cmd = (struct iwl_tx_cmd *) dev_cmd->payload;
len = (u16)skb->len;
tx_cmd->len = cpu_to_le16(len);
if (info->control.hw_key)
iwlagn_tx_cmd_build_hwcrypto(priv, info, tx_cmd, skb);
iwlagn_tx_cmd_build_basic(priv, skb, tx_cmd, info, hdr, sta_id);
iwlagn_tx_cmd_build_rate(priv, tx_cmd, info, sta, fc);
memset(&info->status, 0, sizeof(info->status));
memset(info->driver_data, 0, sizeof(info->driver_data));
info->driver_data[0] = ctx;
info->driver_data[1] = dev_cmd;
spin_lock(&priv->sta_lock);
if (ieee80211_is_data_qos(fc) && !ieee80211_is_qos_nullfunc(fc)) {
u8 *qc = NULL;
struct iwl_tid_data *tid_data;
qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & IEEE80211_QOS_CTL_TID_MASK;
if (WARN_ON_ONCE(tid >= IWL_MAX_TID_COUNT))
goto drop_unlock_sta;
tid_data = &priv->tid_data[sta_id][tid];
if (info->flags & IEEE80211_TX_CTL_AMPDU &&
tid_data->agg.state != IWL_AGG_ON) {
IWL_ERR(priv,
"TX_CTL_AMPDU while not in AGG: Tx flags = 0x%08x, agg.state = %d\n",
info->flags, tid_data->agg.state);
IWL_ERR(priv, "sta_id = %d, tid = %d seq_num = %d\n",
sta_id, tid,
IEEE80211_SEQ_TO_SN(tid_data->seq_number));
goto drop_unlock_sta;
}
if (WARN_ONCE(tid_data->agg.state != IWL_AGG_ON &&
tid_data->agg.state != IWL_AGG_OFF,
"Tx while agg.state = %d\n", tid_data->agg.state))
goto drop_unlock_sta;
seq_number = tid_data->seq_number;
seq_number &= IEEE80211_SCTL_SEQ;
hdr->seq_ctrl &= cpu_to_le16(IEEE80211_SCTL_FRAG);
hdr->seq_ctrl |= cpu_to_le16(seq_number);
seq_number += 0x10;
if (info->flags & IEEE80211_TX_CTL_AMPDU)
is_agg = true;
is_data_qos = true;
}
memcpy(tx_cmd->hdr, hdr, hdr_len);
txq_id = info->hw_queue;
if (is_agg)
txq_id = priv->tid_data[sta_id][tid].agg.txq_id;
else if (info->flags & IEEE80211_TX_CTL_SEND_AFTER_DTIM) {
hdr->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
}
WARN_ON_ONCE(is_agg &&
priv->queue_to_mac80211[txq_id] != info->hw_queue);
IWL_DEBUG_TX(priv, "TX to [%d|%d] Q:%d - seq: 0x%x\n", sta_id, tid,
txq_id, seq_number);
if (iwl_trans_tx(priv->trans, skb, dev_cmd, txq_id))
goto drop_unlock_sta;
if (is_data_qos && !ieee80211_has_morefrags(fc))
priv->tid_data[sta_id][tid].seq_number = seq_number;
spin_unlock(&priv->sta_lock);
if (sta_priv && sta_priv->client && !is_agg)
atomic_inc(&sta_priv->pending_frames);
return 0;
drop_unlock_sta:
if (dev_cmd)
iwl_trans_free_tx_cmd(priv->trans, dev_cmd);
spin_unlock(&priv->sta_lock);
drop_unlock_priv:
return -1;
}
static int iwlagn_alloc_agg_txq(struct iwl_priv *priv, int mq)
{
int q;
for (q = IWLAGN_FIRST_AMPDU_QUEUE;
q < priv->cfg->base_params->num_of_queues; q++) {
if (!test_and_set_bit(q, priv->agg_q_alloc)) {
priv->queue_to_mac80211[q] = mq;
return q;
}
}
return -ENOSPC;
}
static void iwlagn_dealloc_agg_txq(struct iwl_priv *priv, int q)
{
clear_bit(q, priv->agg_q_alloc);
priv->queue_to_mac80211[q] = IWL_INVALID_MAC80211_QUEUE;
}
int iwlagn_tx_agg_stop(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid)
{
struct iwl_tid_data *tid_data;
int sta_id, txq_id;
enum iwl_agg_state agg_state;
sta_id = iwl_sta_id(sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_ERR(priv, "Invalid station for AGG tid %d\n", tid);
return -ENXIO;
}
spin_lock_bh(&priv->sta_lock);
tid_data = &priv->tid_data[sta_id][tid];
txq_id = tid_data->agg.txq_id;
switch (tid_data->agg.state) {
case IWL_EMPTYING_HW_QUEUE_ADDBA:
IWL_DEBUG_HT(priv, "AGG stop before setup done\n");
goto turn_off;
case IWL_AGG_STARTING:
IWL_DEBUG_HT(priv, "AGG stop before AGG became operational\n");
goto turn_off;
case IWL_AGG_ON:
break;
default:
IWL_WARN(priv,
"Stopping AGG while state not ON or starting for %d on %d (%d)\n",
sta_id, tid, tid_data->agg.state);
spin_unlock_bh(&priv->sta_lock);
return 0;
}
tid_data->agg.ssn = IEEE80211_SEQ_TO_SN(tid_data->seq_number);
if (!test_bit(txq_id, priv->agg_q_alloc)) {
IWL_DEBUG_TX_QUEUES(priv,
"stopping AGG on STA/TID %d/%d but hwq %d not used\n",
sta_id, tid, txq_id);
} else if (tid_data->agg.ssn != tid_data->next_reclaimed) {
IWL_DEBUG_TX_QUEUES(priv,
"Can't proceed: ssn %d, next_recl = %d\n",
tid_data->agg.ssn,
tid_data->next_reclaimed);
tid_data->agg.state = IWL_EMPTYING_HW_QUEUE_DELBA;
spin_unlock_bh(&priv->sta_lock);
return 0;
}
IWL_DEBUG_TX_QUEUES(priv, "Can proceed: ssn = next_recl = %d\n",
tid_data->agg.ssn);
turn_off:
agg_state = tid_data->agg.state;
tid_data->agg.state = IWL_AGG_OFF;
spin_unlock_bh(&priv->sta_lock);
if (test_bit(txq_id, priv->agg_q_alloc)) {
if (agg_state == IWL_AGG_ON)
iwl_trans_txq_disable(priv->trans, txq_id, true);
else
IWL_DEBUG_TX_QUEUES(priv, "Don't disable tx agg: %d\n",
agg_state);
iwlagn_dealloc_agg_txq(priv, txq_id);
}
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
return 0;
}
int iwlagn_tx_agg_start(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid, u16 *ssn)
{
struct iwl_rxon_context *ctx = iwl_rxon_ctx_from_vif(vif);
struct iwl_tid_data *tid_data;
int sta_id, txq_id, ret;
IWL_DEBUG_HT(priv, "TX AGG request on ra = %pM tid = %d\n",
sta->addr, tid);
sta_id = iwl_sta_id(sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_ERR(priv, "Start AGG on invalid station\n");
return -ENXIO;
}
if (unlikely(tid >= IWL_MAX_TID_COUNT))
return -EINVAL;
if (priv->tid_data[sta_id][tid].agg.state != IWL_AGG_OFF) {
IWL_ERR(priv, "Start AGG when state is not IWL_AGG_OFF !\n");
return -ENXIO;
}
txq_id = iwlagn_alloc_agg_txq(priv, ctx->ac_to_queue[tid_to_ac[tid]]);
if (txq_id < 0) {
IWL_DEBUG_TX_QUEUES(priv,
"No free aggregation queue for %pM/%d\n",
sta->addr, tid);
return txq_id;
}
ret = iwl_sta_tx_modify_enable_tid(priv, sta_id, tid);
if (ret)
return ret;
spin_lock_bh(&priv->sta_lock);
tid_data = &priv->tid_data[sta_id][tid];
tid_data->agg.ssn = IEEE80211_SEQ_TO_SN(tid_data->seq_number);
tid_data->agg.txq_id = txq_id;
*ssn = tid_data->agg.ssn;
if (*ssn == tid_data->next_reclaimed) {
IWL_DEBUG_TX_QUEUES(priv, "Can proceed: ssn = next_recl = %d\n",
tid_data->agg.ssn);
tid_data->agg.state = IWL_AGG_STARTING;
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
} else {
IWL_DEBUG_TX_QUEUES(priv, "Can't proceed: ssn %d, "
"next_reclaimed = %d\n",
tid_data->agg.ssn,
tid_data->next_reclaimed);
tid_data->agg.state = IWL_EMPTYING_HW_QUEUE_ADDBA;
}
spin_unlock_bh(&priv->sta_lock);
return ret;
}
int iwlagn_tx_agg_flush(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid)
{
struct iwl_tid_data *tid_data;
enum iwl_agg_state agg_state;
int sta_id, txq_id;
sta_id = iwl_sta_id(sta);
spin_lock_bh(&priv->sta_lock);
tid_data = &priv->tid_data[sta_id][tid];
txq_id = tid_data->agg.txq_id;
agg_state = tid_data->agg.state;
IWL_DEBUG_TX_QUEUES(priv, "Flush AGG: sta %d tid %d q %d state %d\n",
sta_id, tid, txq_id, tid_data->agg.state);
tid_data->agg.state = IWL_AGG_OFF;
spin_unlock_bh(&priv->sta_lock);
if (iwlagn_txfifo_flush(priv, BIT(txq_id)))
IWL_ERR(priv, "Couldn't flush the AGG queue\n");
if (test_bit(txq_id, priv->agg_q_alloc)) {
if (agg_state == IWL_AGG_ON)
iwl_trans_txq_disable(priv->trans, txq_id, true);
else
IWL_DEBUG_TX_QUEUES(priv, "Don't disable tx agg: %d\n",
agg_state);
iwlagn_dealloc_agg_txq(priv, txq_id);
}
return 0;
}
int iwlagn_tx_agg_oper(struct iwl_priv *priv, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid, u8 buf_size)
{
struct iwl_station_priv *sta_priv = (void *) sta->drv_priv;
struct iwl_rxon_context *ctx = iwl_rxon_ctx_from_vif(vif);
int q, fifo;
u16 ssn;
buf_size = min_t(int, buf_size, LINK_QUAL_AGG_FRAME_LIMIT_DEF);
spin_lock_bh(&priv->sta_lock);
ssn = priv->tid_data[sta_priv->sta_id][tid].agg.ssn;
q = priv->tid_data[sta_priv->sta_id][tid].agg.txq_id;
priv->tid_data[sta_priv->sta_id][tid].agg.state = IWL_AGG_ON;
spin_unlock_bh(&priv->sta_lock);
fifo = ctx->ac_to_fifo[tid_to_ac[tid]];
iwl_trans_txq_enable(priv->trans, q, fifo, sta_priv->sta_id, tid,
buf_size, ssn, 0);
if (sta_priv->max_agg_bufsize == 0)
sta_priv->max_agg_bufsize =
LINK_QUAL_AGG_FRAME_LIMIT_DEF;
sta_priv->max_agg_bufsize =
min(sta_priv->max_agg_bufsize, buf_size);
if (priv->hw_params.use_rts_for_aggregation) {
sta_priv->lq_sta.lq.general_params.flags |=
LINK_QUAL_FLAGS_SET_STA_TLC_RTS_MSK;
}
priv->agg_tids_count++;
IWL_DEBUG_HT(priv, "priv->agg_tids_count = %u\n",
priv->agg_tids_count);
sta_priv->lq_sta.lq.agg_params.agg_frame_cnt_limit =
sta_priv->max_agg_bufsize;
IWL_DEBUG_HT(priv, "Tx aggregation enabled on ra = %pM tid = %d\n",
sta->addr, tid);
return iwl_send_lq_cmd(priv, ctx,
&sta_priv->lq_sta.lq, CMD_ASYNC, false);
}
static void iwlagn_check_ratid_empty(struct iwl_priv *priv, int sta_id, u8 tid)
{
struct iwl_tid_data *tid_data = &priv->tid_data[sta_id][tid];
enum iwl_rxon_context_id ctx;
struct ieee80211_vif *vif;
u8 *addr;
lockdep_assert_held(&priv->sta_lock);
addr = priv->stations[sta_id].sta.sta.addr;
ctx = priv->stations[sta_id].ctxid;
vif = priv->contexts[ctx].vif;
switch (priv->tid_data[sta_id][tid].agg.state) {
case IWL_EMPTYING_HW_QUEUE_DELBA:
if (tid_data->agg.ssn == tid_data->next_reclaimed) {
IWL_DEBUG_TX_QUEUES(priv,
"Can continue DELBA flow ssn = next_recl = %d\n",
tid_data->next_reclaimed);
iwl_trans_txq_disable(priv->trans,
tid_data->agg.txq_id, true);
iwlagn_dealloc_agg_txq(priv, tid_data->agg.txq_id);
tid_data->agg.state = IWL_AGG_OFF;
ieee80211_stop_tx_ba_cb_irqsafe(vif, addr, tid);
}
break;
case IWL_EMPTYING_HW_QUEUE_ADDBA:
if (tid_data->agg.ssn == tid_data->next_reclaimed) {
IWL_DEBUG_TX_QUEUES(priv,
"Can continue ADDBA flow ssn = next_recl = %d\n",
tid_data->next_reclaimed);
tid_data->agg.state = IWL_AGG_STARTING;
ieee80211_start_tx_ba_cb_irqsafe(vif, addr, tid);
}
break;
default:
break;
}
}
static void iwlagn_non_agg_tx_status(struct iwl_priv *priv,
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
static void iwlagn_hwrate_to_tx_control(struct iwl_priv *priv, u32 rate_n_flags,
struct ieee80211_tx_info *info)
{
struct ieee80211_tx_rate *r = &info->status.rates[0];
info->status.antenna =
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
r->idx = iwlagn_hwrate_to_mac80211_idx(rate_n_flags, info->band);
}
const char *iwl_get_tx_fail_reason(u32 status)
{
#define TX_STATUS_FAIL(x) case TX_STATUS_FAIL_ ## x: return #x
#define TX_STATUS_POSTPONE(x) case TX_STATUS_POSTPONE_ ## x: return #x
switch (status & TX_STATUS_MSK) {
case TX_STATUS_SUCCESS:
return "SUCCESS";
TX_STATUS_POSTPONE(DELAY);
TX_STATUS_POSTPONE(FEW_BYTES);
TX_STATUS_POSTPONE(BT_PRIO);
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
static void iwlagn_count_agg_tx_err_status(struct iwl_priv *priv, u16 status)
{
status &= AGG_TX_STATUS_MSK;
switch (status) {
case AGG_TX_STATE_UNDERRUN_MSK:
priv->reply_agg_tx_stats.underrun++;
break;
case AGG_TX_STATE_BT_PRIO_MSK:
priv->reply_agg_tx_stats.bt_prio++;
break;
case AGG_TX_STATE_FEW_BYTES_MSK:
priv->reply_agg_tx_stats.few_bytes++;
break;
case AGG_TX_STATE_ABORT_MSK:
priv->reply_agg_tx_stats.abort++;
break;
case AGG_TX_STATE_LAST_SENT_TTL_MSK:
priv->reply_agg_tx_stats.last_sent_ttl++;
break;
case AGG_TX_STATE_LAST_SENT_TRY_CNT_MSK:
priv->reply_agg_tx_stats.last_sent_try++;
break;
case AGG_TX_STATE_LAST_SENT_BT_KILL_MSK:
priv->reply_agg_tx_stats.last_sent_bt_kill++;
break;
case AGG_TX_STATE_SCD_QUERY_MSK:
priv->reply_agg_tx_stats.scd_query++;
break;
case AGG_TX_STATE_TEST_BAD_CRC32_MSK:
priv->reply_agg_tx_stats.bad_crc32++;
break;
case AGG_TX_STATE_RESPONSE_MSK:
priv->reply_agg_tx_stats.response++;
break;
case AGG_TX_STATE_DUMP_TX_MSK:
priv->reply_agg_tx_stats.dump_tx++;
break;
case AGG_TX_STATE_DELAY_TX_MSK:
priv->reply_agg_tx_stats.delay_tx++;
break;
default:
priv->reply_agg_tx_stats.unknown++;
break;
}
}
static inline u32 iwlagn_get_scd_ssn(struct iwlagn_tx_resp *tx_resp)
{
return le32_to_cpup((__le32 *)&tx_resp->status +
tx_resp->frame_count) & IEEE80211_MAX_SN;
}
static void iwl_rx_reply_tx_agg(struct iwl_priv *priv,
struct iwlagn_tx_resp *tx_resp)
{
struct agg_tx_status *frame_status = &tx_resp->status;
int tid = (tx_resp->ra_tid & IWLAGN_TX_RES_TID_MSK) >>
IWLAGN_TX_RES_TID_POS;
int sta_id = (tx_resp->ra_tid & IWLAGN_TX_RES_RA_MSK) >>
IWLAGN_TX_RES_RA_POS;
struct iwl_ht_agg *agg = &priv->tid_data[sta_id][tid].agg;
u32 status = le16_to_cpu(tx_resp->status.status);
int i;
WARN_ON(tid == IWL_TID_NON_QOS);
if (agg->wait_for_ba)
IWL_DEBUG_TX_REPLY(priv,
"got tx response w/o block-ack\n");
agg->rate_n_flags = le32_to_cpu(tx_resp->rate_n_flags);
agg->wait_for_ba = (tx_resp->frame_count > 1);
if (tx_resp->bt_kill_count && tx_resp->frame_count == 1 &&
priv->lib->bt_params &&
priv->lib->bt_params->advanced_bt_coexist) {
IWL_DEBUG_COEX(priv, "receive reply tx w/ bt_kill\n");
}
if (tx_resp->frame_count == 1)
return;
IWL_DEBUG_TX_REPLY(priv, "TXQ %d initial_rate 0x%x ssn %d frm_cnt %d\n",
agg->txq_id,
le32_to_cpu(tx_resp->rate_n_flags),
iwlagn_get_scd_ssn(tx_resp), tx_resp->frame_count);
for (i = 0; i < tx_resp->frame_count; i++) {
u16 fstatus = le16_to_cpu(frame_status[i].status);
u8 retry_cnt = (fstatus & AGG_TX_TRY_MSK) >> AGG_TX_TRY_POS;
if (status & AGG_TX_STATUS_MSK)
iwlagn_count_agg_tx_err_status(priv, fstatus);
if (status & (AGG_TX_STATE_FEW_BYTES_MSK |
AGG_TX_STATE_ABORT_MSK))
continue;
if (status & AGG_TX_STATUS_MSK || retry_cnt > 1)
IWL_DEBUG_TX_REPLY(priv,
"%d: status %s (0x%04x), try-count (0x%01x)\n",
i,
iwl_get_agg_tx_fail_reason(fstatus),
fstatus & AGG_TX_STATUS_MSK,
retry_cnt);
}
}
const char *iwl_get_agg_tx_fail_reason(u16 status)
{
status &= AGG_TX_STATUS_MSK;
switch (status) {
case AGG_TX_STATE_TRANSMITTED:
return "SUCCESS";
AGG_TX_STATE_FAIL(UNDERRUN_MSK);
AGG_TX_STATE_FAIL(BT_PRIO_MSK);
AGG_TX_STATE_FAIL(FEW_BYTES_MSK);
AGG_TX_STATE_FAIL(ABORT_MSK);
AGG_TX_STATE_FAIL(LAST_SENT_TTL_MSK);
AGG_TX_STATE_FAIL(LAST_SENT_TRY_CNT_MSK);
AGG_TX_STATE_FAIL(LAST_SENT_BT_KILL_MSK);
AGG_TX_STATE_FAIL(SCD_QUERY_MSK);
AGG_TX_STATE_FAIL(TEST_BAD_CRC32_MSK);
AGG_TX_STATE_FAIL(RESPONSE_MSK);
AGG_TX_STATE_FAIL(DUMP_TX_MSK);
AGG_TX_STATE_FAIL(DELAY_TX_MSK);
}
return "UNKNOWN";
}
static void iwlagn_count_tx_err_status(struct iwl_priv *priv, u16 status)
{
status &= TX_STATUS_MSK;
switch (status) {
case TX_STATUS_POSTPONE_DELAY:
priv->reply_tx_stats.pp_delay++;
break;
case TX_STATUS_POSTPONE_FEW_BYTES:
priv->reply_tx_stats.pp_few_bytes++;
break;
case TX_STATUS_POSTPONE_BT_PRIO:
priv->reply_tx_stats.pp_bt_prio++;
break;
case TX_STATUS_POSTPONE_QUIET_PERIOD:
priv->reply_tx_stats.pp_quiet_period++;
break;
case TX_STATUS_POSTPONE_CALC_TTAK:
priv->reply_tx_stats.pp_calc_ttak++;
break;
case TX_STATUS_FAIL_INTERNAL_CROSSED_RETRY:
priv->reply_tx_stats.int_crossed_retry++;
break;
case TX_STATUS_FAIL_SHORT_LIMIT:
priv->reply_tx_stats.short_limit++;
break;
case TX_STATUS_FAIL_LONG_LIMIT:
priv->reply_tx_stats.long_limit++;
break;
case TX_STATUS_FAIL_FIFO_UNDERRUN:
priv->reply_tx_stats.fifo_underrun++;
break;
case TX_STATUS_FAIL_DRAIN_FLOW:
priv->reply_tx_stats.drain_flow++;
break;
case TX_STATUS_FAIL_RFKILL_FLUSH:
priv->reply_tx_stats.rfkill_flush++;
break;
case TX_STATUS_FAIL_LIFE_EXPIRE:
priv->reply_tx_stats.life_expire++;
break;
case TX_STATUS_FAIL_DEST_PS:
priv->reply_tx_stats.dest_ps++;
break;
case TX_STATUS_FAIL_HOST_ABORTED:
priv->reply_tx_stats.host_abort++;
break;
case TX_STATUS_FAIL_BT_RETRY:
priv->reply_tx_stats.bt_retry++;
break;
case TX_STATUS_FAIL_STA_INVALID:
priv->reply_tx_stats.sta_invalid++;
break;
case TX_STATUS_FAIL_FRAG_DROPPED:
priv->reply_tx_stats.frag_drop++;
break;
case TX_STATUS_FAIL_TID_DISABLE:
priv->reply_tx_stats.tid_disable++;
break;
case TX_STATUS_FAIL_FIFO_FLUSHED:
priv->reply_tx_stats.fifo_flush++;
break;
case TX_STATUS_FAIL_INSUFFICIENT_CF_POLL:
priv->reply_tx_stats.insuff_cf_poll++;
break;
case TX_STATUS_FAIL_PASSIVE_NO_RX:
priv->reply_tx_stats.fail_hw_drop++;
break;
case TX_STATUS_FAIL_NO_BEACON_ON_RADAR:
priv->reply_tx_stats.sta_color_mismatch++;
break;
default:
priv->reply_tx_stats.unknown++;
break;
}
}
static void iwlagn_set_tx_status(struct iwl_priv *priv,
struct ieee80211_tx_info *info,
struct iwlagn_tx_resp *tx_resp)
{
u16 status = le16_to_cpu(tx_resp->status.status);
info->flags &= ~IEEE80211_TX_CTL_AMPDU;
info->status.rates[0].count = tx_resp->failure_frame + 1;
info->flags |= iwl_tx_status_to_mac80211(status);
iwlagn_hwrate_to_tx_control(priv, le32_to_cpu(tx_resp->rate_n_flags),
info);
if (!iwl_is_tx_success(status))
iwlagn_count_tx_err_status(priv, status);
}
static void iwl_check_abort_status(struct iwl_priv *priv,
u8 frame_count, u32 status)
{
if (frame_count == 1 && status == TX_STATUS_FAIL_RFKILL_FLUSH) {
IWL_ERR(priv, "Tx flush command to flush out all frames\n");
if (!test_bit(STATUS_EXIT_PENDING, &priv->status))
queue_work(priv->workqueue, &priv->tx_flush);
}
}
void iwlagn_rx_reply_tx(struct iwl_priv *priv, struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 sequence = le16_to_cpu(pkt->hdr.sequence);
int txq_id = SEQ_TO_QUEUE(sequence);
int cmd_index __maybe_unused = SEQ_TO_INDEX(sequence);
struct iwlagn_tx_resp *tx_resp = (void *)pkt->data;
struct ieee80211_hdr *hdr;
u32 status = le16_to_cpu(tx_resp->status.status);
u16 ssn = iwlagn_get_scd_ssn(tx_resp);
int tid;
int sta_id;
int freed;
struct ieee80211_tx_info *info;
struct sk_buff_head skbs;
struct sk_buff *skb;
struct iwl_rxon_context *ctx;
bool is_agg = (txq_id >= IWLAGN_FIRST_AMPDU_QUEUE);
tid = (tx_resp->ra_tid & IWLAGN_TX_RES_TID_MSK) >>
IWLAGN_TX_RES_TID_POS;
sta_id = (tx_resp->ra_tid & IWLAGN_TX_RES_RA_MSK) >>
IWLAGN_TX_RES_RA_POS;
spin_lock_bh(&priv->sta_lock);
if (is_agg) {
WARN_ON_ONCE(sta_id >= IWLAGN_STATION_COUNT ||
tid >= IWL_MAX_TID_COUNT);
if (txq_id != priv->tid_data[sta_id][tid].agg.txq_id)
IWL_ERR(priv, "txq_id mismatch: %d %d\n", txq_id,
priv->tid_data[sta_id][tid].agg.txq_id);
iwl_rx_reply_tx_agg(priv, tx_resp);
}
__skb_queue_head_init(&skbs);
if (tx_resp->frame_count == 1) {
u16 next_reclaimed = le16_to_cpu(tx_resp->seq_ctl);
next_reclaimed = IEEE80211_SEQ_TO_SN(next_reclaimed + 0x10);
if (is_agg) {
next_reclaimed = ssn;
}
if (tid != IWL_TID_NON_QOS) {
priv->tid_data[sta_id][tid].next_reclaimed =
next_reclaimed;
IWL_DEBUG_TX_REPLY(priv, "Next reclaimed packet:%d\n",
next_reclaimed);
iwlagn_check_ratid_empty(priv, sta_id, tid);
}
iwl_trans_reclaim(priv->trans, txq_id, ssn, &skbs);
freed = 0;
skb_queue_walk(&skbs, skb) {
hdr = (struct ieee80211_hdr *)skb->data;
if (!ieee80211_is_data_qos(hdr->frame_control))
priv->last_seq_ctl = tx_resp->seq_ctl;
info = IEEE80211_SKB_CB(skb);
ctx = info->driver_data[0];
iwl_trans_free_tx_cmd(priv->trans,
info->driver_data[1]);
memset(&info->status, 0, sizeof(info->status));
if (status == TX_STATUS_FAIL_PASSIVE_NO_RX &&
ctx->vif &&
ctx->vif->type == NL80211_IFTYPE_STATION) {
priv->passive_no_rx = true;
IWL_DEBUG_TX_QUEUES(priv,
"stop all queues: passive channel\n");
ieee80211_stop_queues(priv->hw);
IWL_DEBUG_TX_REPLY(priv,
"TXQ %d status %s (0x%08x) "
"rate_n_flags 0x%x retries %d\n",
txq_id,
iwl_get_tx_fail_reason(status),
status,
le32_to_cpu(tx_resp->rate_n_flags),
tx_resp->failure_frame);
IWL_DEBUG_TX_REPLY(priv,
"FrameCnt = %d, idx=%d\n",
tx_resp->frame_count, cmd_index);
}
if (is_agg && !iwl_is_tx_success(status))
info->flags |= IEEE80211_TX_STAT_AMPDU_NO_BACK;
iwlagn_set_tx_status(priv, IEEE80211_SKB_CB(skb),
tx_resp);
if (!is_agg)
iwlagn_non_agg_tx_status(priv, ctx, hdr->addr1);
freed++;
}
if (tid != IWL_TID_NON_QOS) {
priv->tid_data[sta_id][tid].next_reclaimed =
next_reclaimed;
IWL_DEBUG_TX_REPLY(priv, "Next reclaimed packet:%d\n",
next_reclaimed);
}
if (!is_agg && freed != 1)
IWL_ERR(priv, "Q: %d, freed %d\n", txq_id, freed);
IWL_DEBUG_TX_REPLY(priv, "TXQ %d status %s (0x%08x)\n", txq_id,
iwl_get_tx_fail_reason(status), status);
IWL_DEBUG_TX_REPLY(priv,
"\t\t\t\tinitial_rate 0x%x retries %d, idx=%d ssn=%d seq_ctl=0x%x\n",
le32_to_cpu(tx_resp->rate_n_flags),
tx_resp->failure_frame,
SEQ_TO_INDEX(sequence), ssn,
le16_to_cpu(tx_resp->seq_ctl));
}
iwl_check_abort_status(priv, tx_resp->frame_count, status);
spin_unlock_bh(&priv->sta_lock);
while (!skb_queue_empty(&skbs)) {
skb = __skb_dequeue(&skbs);
ieee80211_tx_status(priv->hw, skb);
}
}
void iwlagn_rx_reply_compressed_ba(struct iwl_priv *priv,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_compressed_ba_resp *ba_resp = (void *)pkt->data;
struct iwl_ht_agg *agg;
struct sk_buff_head reclaimed_skbs;
struct sk_buff *skb;
int sta_id;
int tid;
int freed;
u16 scd_flow = le16_to_cpu(ba_resp->scd_flow);
u16 ba_resp_scd_ssn = le16_to_cpu(ba_resp->scd_ssn);
if (scd_flow >= priv->cfg->base_params->num_of_queues) {
IWL_ERR(priv,
"BUG_ON scd_flow is bigger than number of queues\n");
return;
}
sta_id = ba_resp->sta_id;
tid = ba_resp->tid;
agg = &priv->tid_data[sta_id][tid].agg;
spin_lock_bh(&priv->sta_lock);
if (unlikely(!agg->wait_for_ba)) {
if (unlikely(ba_resp->bitmap))
IWL_ERR(priv, "Received BA when not expected\n");
spin_unlock_bh(&priv->sta_lock);
return;
}
if (unlikely(scd_flow != agg->txq_id)) {
IWL_DEBUG_TX_QUEUES(priv,
"Bad queue mapping txq_id=%d, agg_txq[sta:%d,tid:%d]=%d\n",
scd_flow, sta_id, tid, agg->txq_id);
spin_unlock_bh(&priv->sta_lock);
return;
}
__skb_queue_head_init(&reclaimed_skbs);
iwl_trans_reclaim(priv->trans, scd_flow, ba_resp_scd_ssn,
&reclaimed_skbs);
IWL_DEBUG_TX_REPLY(priv, "REPLY_COMPRESSED_BA [%d] Received from %pM, "
"sta_id = %d\n",
agg->wait_for_ba,
(u8 *) &ba_resp->sta_addr_lo32,
ba_resp->sta_id);
IWL_DEBUG_TX_REPLY(priv, "TID = %d, SeqCtl = %d, bitmap = 0x%llx, "
"scd_flow = %d, scd_ssn = %d sent:%d, acked:%d\n",
ba_resp->tid, le16_to_cpu(ba_resp->seq_ctl),
(unsigned long long)le64_to_cpu(ba_resp->bitmap),
scd_flow, ba_resp_scd_ssn, ba_resp->txed,
ba_resp->txed_2_done);
agg->wait_for_ba = false;
if (ba_resp->txed_2_done > ba_resp->txed) {
IWL_DEBUG_TX_REPLY(priv,
"bogus sent(%d) and ack(%d) count\n",
ba_resp->txed, ba_resp->txed_2_done);
ba_resp->txed = ba_resp->txed_2_done;
}
priv->tid_data[sta_id][tid].next_reclaimed = ba_resp_scd_ssn;
iwlagn_check_ratid_empty(priv, sta_id, tid);
freed = 0;
skb_queue_walk(&reclaimed_skbs, skb) {
struct ieee80211_hdr *hdr = (void *)skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
if (ieee80211_is_data_qos(hdr->frame_control))
freed++;
else
WARN_ON_ONCE(1);
iwl_trans_free_tx_cmd(priv->trans, info->driver_data[1]);
memset(&info->status, 0, sizeof(info->status));
info->flags |= IEEE80211_TX_STAT_ACK;
if (freed == 1) {
info = IEEE80211_SKB_CB(skb);
memset(&info->status, 0, sizeof(info->status));
info->flags |= IEEE80211_TX_STAT_AMPDU;
info->status.ampdu_ack_len = ba_resp->txed_2_done;
info->status.ampdu_len = ba_resp->txed;
iwlagn_hwrate_to_tx_control(priv, agg->rate_n_flags,
info);
}
}
spin_unlock_bh(&priv->sta_lock);
while (!skb_queue_empty(&reclaimed_skbs)) {
skb = __skb_dequeue(&reclaimed_skbs);
ieee80211_tx_status(priv->hw, skb);
}
}
