static void iwl_mvm_mac_tsf_id_iter(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_mac_iface_iterator_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
u16 min_bi;
if (vif == data->vif)
return;
switch (data->vif->type) {
case NL80211_IFTYPE_STATION:
if (vif->type != NL80211_IFTYPE_AP ||
data->preferred_tsf != NUM_TSF_IDS ||
!test_bit(mvmvif->tsf_id, data->available_tsf_ids))
break;
min_bi = min(data->vif->bss_conf.beacon_int,
vif->bss_conf.beacon_int);
if (!min_bi)
break;
if ((data->vif->bss_conf.beacon_int -
vif->bss_conf.beacon_int) % min_bi == 0) {
data->preferred_tsf = mvmvif->tsf_id;
return;
}
break;
case NL80211_IFTYPE_AP:
if ((vif->type != NL80211_IFTYPE_AP &&
vif->type != NL80211_IFTYPE_STATION) ||
data->preferred_tsf != NUM_TSF_IDS ||
!test_bit(mvmvif->tsf_id, data->available_tsf_ids))
break;
min_bi = min(data->vif->bss_conf.beacon_int,
vif->bss_conf.beacon_int);
if (!min_bi)
break;
if ((data->vif->bss_conf.beacon_int -
vif->bss_conf.beacon_int) % min_bi == 0) {
data->preferred_tsf = mvmvif->tsf_id;
return;
}
break;
default:
break;
}
__clear_bit(mvmvif->tsf_id, data->available_tsf_ids);
if (data->preferred_tsf == mvmvif->tsf_id)
data->preferred_tsf = NUM_TSF_IDS;
}
u32 iwl_mvm_mac_get_queues_mask(struct ieee80211_vif *vif)
{
u32 qmask = 0, ac;
if (vif->type == NL80211_IFTYPE_P2P_DEVICE)
return BIT(IWL_MVM_OFFCHANNEL_QUEUE);
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
if (vif->hw_queue[ac] != IEEE80211_INVAL_HW_QUEUE)
qmask |= BIT(vif->hw_queue[ac]);
}
if (vif->type == NL80211_IFTYPE_AP)
qmask |= BIT(vif->cab_queue);
return qmask;
}
static void iwl_mvm_iface_hw_queues_iter(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_hw_queues_iface_iterator_data *data = _data;
if (vif == data->exclude_vif)
return;
data->used_hw_queues |= iwl_mvm_mac_get_queues_mask(vif);
}
static void iwl_mvm_mac_sta_hw_queues_iter(void *_data,
struct ieee80211_sta *sta)
{
struct iwl_mvm_hw_queues_iface_iterator_data *data = _data;
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
data->used_hw_queues |= mvmsta->tfd_queue_msk;
}
unsigned long iwl_mvm_get_used_hw_queues(struct iwl_mvm *mvm,
struct ieee80211_vif *exclude_vif)
{
u8 sta_id;
struct iwl_mvm_hw_queues_iface_iterator_data data = {
.exclude_vif = exclude_vif,
.used_hw_queues =
BIT(IWL_MVM_OFFCHANNEL_QUEUE) |
BIT(mvm->aux_queue) |
BIT(IWL_MVM_CMD_QUEUE),
};
lockdep_assert_held(&mvm->mutex);
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_iface_hw_queues_iter, &data);
ieee80211_iterate_stations_atomic(mvm->hw,
iwl_mvm_mac_sta_hw_queues_iter,
&data);
for_each_set_bit(sta_id, mvm->sta_drained, IWL_MVM_STATION_COUNT)
data.used_hw_queues |= mvm->tfd_drained[sta_id];
return data.used_hw_queues;
}
static void iwl_mvm_mac_iface_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_mac_iface_iterator_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (vif == data->vif) {
data->found_vif = true;
return;
}
__clear_bit(mvmvif->id, data->available_mac_ids);
iwl_mvm_mac_tsf_id_iter(_data, mac, vif);
}
void iwl_mvm_mac_ctxt_recalc_tsf_id(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_mac_iface_iterator_data data = {
.mvm = mvm,
.vif = vif,
.available_tsf_ids = { (1 << NUM_TSF_IDS) - 1 },
.preferred_tsf = NUM_TSF_IDS,
};
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_mac_tsf_id_iter, &data);
if (data.preferred_tsf != NUM_TSF_IDS)
mvmvif->tsf_id = data.preferred_tsf;
else if (!test_bit(mvmvif->tsf_id, data.available_tsf_ids))
mvmvif->tsf_id = find_first_bit(data.available_tsf_ids,
NUM_TSF_IDS);
}
static int iwl_mvm_mac_ctxt_allocate_resources(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_mac_iface_iterator_data data = {
.mvm = mvm,
.vif = vif,
.available_mac_ids = { (1 << NUM_MAC_INDEX_DRIVER) - 1 },
.available_tsf_ids = { (1 << NUM_TSF_IDS) - 1 },
.preferred_tsf = NUM_TSF_IDS,
.found_vif = false,
};
u32 ac;
int ret, i;
unsigned long used_hw_queues;
switch (vif->type) {
case NL80211_IFTYPE_ADHOC:
break;
case NL80211_IFTYPE_STATION:
if (!vif->p2p)
break;
default:
__clear_bit(0, data.available_mac_ids);
}
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_mac_iface_iterator, &data);
used_hw_queues = iwl_mvm_get_used_hw_queues(mvm, vif);
if (data.found_vif)
return 0;
if (WARN_ON_ONCE(test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status)))
return -EBUSY;
mvmvif->id = find_first_bit(data.available_mac_ids,
NUM_MAC_INDEX_DRIVER);
if (mvmvif->id == NUM_MAC_INDEX_DRIVER) {
IWL_ERR(mvm, "Failed to init MAC context - no free ID!\n");
ret = -EIO;
goto exit_fail;
}
if (data.preferred_tsf != NUM_TSF_IDS)
mvmvif->tsf_id = data.preferred_tsf;
else
mvmvif->tsf_id = find_first_bit(data.available_tsf_ids,
NUM_TSF_IDS);
if (mvmvif->tsf_id == NUM_TSF_IDS) {
IWL_ERR(mvm, "Failed to init MAC context - no free TSF!\n");
ret = -EIO;
goto exit_fail;
}
mvmvif->color = 0;
INIT_LIST_HEAD(&mvmvif->time_event_data.list);
mvmvif->time_event_data.id = TE_MAX;
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
vif->hw_queue[ac] = IEEE80211_INVAL_HW_QUEUE;
return 0;
}
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
u8 queue = find_first_zero_bit(&used_hw_queues,
mvm->first_agg_queue);
if (queue >= mvm->first_agg_queue) {
IWL_ERR(mvm, "Failed to allocate queue\n");
ret = -EIO;
goto exit_fail;
}
__set_bit(queue, &used_hw_queues);
vif->hw_queue[ac] = queue;
}
if (vif->type == NL80211_IFTYPE_AP) {
u8 queue = find_first_zero_bit(&used_hw_queues,
mvm->first_agg_queue);
if (queue >= mvm->first_agg_queue) {
IWL_ERR(mvm, "Failed to allocate cab queue\n");
ret = -EIO;
goto exit_fail;
}
vif->cab_queue = queue;
} else {
vif->cab_queue = IEEE80211_INVAL_HW_QUEUE;
}
mvmvif->bcast_sta.sta_id = IWL_MVM_STATION_COUNT;
mvmvif->ap_sta_id = IWL_MVM_STATION_COUNT;
for (i = 0; i < NUM_IWL_MVM_SMPS_REQ; i++)
mvmvif->smps_requests[i] = IEEE80211_SMPS_AUTOMATIC;
return 0;
exit_fail:
memset(mvmvif, 0, sizeof(struct iwl_mvm_vif));
memset(vif->hw_queue, IEEE80211_INVAL_HW_QUEUE, sizeof(vif->hw_queue));
vif->cab_queue = IEEE80211_INVAL_HW_QUEUE;
return ret;
}
int iwl_mvm_mac_ctxt_init(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
unsigned int wdg_timeout =
iwl_mvm_get_wd_timeout(mvm, vif, false, false);
u32 ac;
int ret;
lockdep_assert_held(&mvm->mutex);
ret = iwl_mvm_mac_ctxt_allocate_resources(mvm, vif);
if (ret)
return ret;
switch (vif->type) {
case NL80211_IFTYPE_P2P_DEVICE:
iwl_mvm_enable_ac_txq(mvm, IWL_MVM_OFFCHANNEL_QUEUE,
IWL_MVM_OFFCHANNEL_QUEUE,
IWL_MVM_TX_FIFO_VO, 0, wdg_timeout);
break;
case NL80211_IFTYPE_AP:
iwl_mvm_enable_ac_txq(mvm, vif->cab_queue, vif->cab_queue,
IWL_MVM_TX_FIFO_MCAST, 0, wdg_timeout);
default:
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
iwl_mvm_enable_ac_txq(mvm, vif->hw_queue[ac],
vif->hw_queue[ac],
iwl_mvm_ac_to_tx_fifo[ac], 0,
wdg_timeout);
break;
}
return 0;
}
void iwl_mvm_mac_ctxt_release(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
int ac;
lockdep_assert_held(&mvm->mutex);
switch (vif->type) {
case NL80211_IFTYPE_P2P_DEVICE:
iwl_mvm_disable_txq(mvm, IWL_MVM_OFFCHANNEL_QUEUE,
IWL_MVM_OFFCHANNEL_QUEUE, IWL_MAX_TID_COUNT,
0);
break;
case NL80211_IFTYPE_AP:
iwl_mvm_disable_txq(mvm, vif->cab_queue, vif->cab_queue,
IWL_MAX_TID_COUNT, 0);
default:
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
iwl_mvm_disable_txq(mvm, vif->hw_queue[ac],
vif->hw_queue[ac],
IWL_MAX_TID_COUNT, 0);
}
}
static void iwl_mvm_ack_rates(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
enum ieee80211_band band,
u8 *cck_rates, u8 *ofdm_rates)
{
struct ieee80211_supported_band *sband;
unsigned long basic = vif->bss_conf.basic_rates;
int lowest_present_ofdm = 100;
int lowest_present_cck = 100;
u8 cck = 0;
u8 ofdm = 0;
int i;
sband = mvm->hw->wiphy->bands[band];
for_each_set_bit(i, &basic, BITS_PER_LONG) {
int hw = sband->bitrates[i].hw_value;
if (hw >= IWL_FIRST_OFDM_RATE) {
ofdm |= BIT(hw - IWL_FIRST_OFDM_RATE);
if (lowest_present_ofdm > hw)
lowest_present_ofdm = hw;
} else {
BUILD_BUG_ON(IWL_FIRST_CCK_RATE != 0);
cck |= BIT(hw);
if (lowest_present_cck > hw)
lowest_present_cck = hw;
}
}
if (IWL_RATE_24M_INDEX < lowest_present_ofdm)
ofdm |= IWL_RATE_BIT_MSK(24) >> IWL_FIRST_OFDM_RATE;
if (IWL_RATE_12M_INDEX < lowest_present_ofdm)
ofdm |= IWL_RATE_BIT_MSK(12) >> IWL_FIRST_OFDM_RATE;
ofdm |= IWL_RATE_BIT_MSK(6) >> IWL_FIRST_OFDM_RATE;
if (IWL_RATE_11M_INDEX < lowest_present_cck)
cck |= IWL_RATE_BIT_MSK(11) >> IWL_FIRST_CCK_RATE;
if (IWL_RATE_5M_INDEX < lowest_present_cck)
cck |= IWL_RATE_BIT_MSK(5) >> IWL_FIRST_CCK_RATE;
if (IWL_RATE_2M_INDEX < lowest_present_cck)
cck |= IWL_RATE_BIT_MSK(2) >> IWL_FIRST_CCK_RATE;
cck |= IWL_RATE_BIT_MSK(1) >> IWL_FIRST_CCK_RATE;
*cck_rates = cck;
*ofdm_rates = ofdm;
}
static void iwl_mvm_mac_ctxt_set_ht_flags(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_mac_ctx_cmd *cmd)
{
u8 protection_mode = vif->bss_conf.ht_operation_mode &
IEEE80211_HT_OP_MODE_PROTECTION;
u32 ht_flag = MAC_PROT_FLG_HT_PROT | MAC_PROT_FLG_FAT_PROT;
IWL_DEBUG_RATE(mvm, "protection mode set to %d\n", protection_mode);
switch (protection_mode) {
case IEEE80211_HT_OP_MODE_PROTECTION_NONE:
break;
case IEEE80211_HT_OP_MODE_PROTECTION_NONMEMBER:
case IEEE80211_HT_OP_MODE_PROTECTION_NONHT_MIXED:
cmd->protection_flags |= cpu_to_le32(ht_flag);
break;
case IEEE80211_HT_OP_MODE_PROTECTION_20MHZ:
if (vif->bss_conf.chandef.width > NL80211_CHAN_WIDTH_20)
cmd->protection_flags |= cpu_to_le32(ht_flag);
break;
default:
IWL_ERR(mvm, "Illegal protection mode %d\n",
protection_mode);
break;
}
}
static void iwl_mvm_mac_ctxt_cmd_common(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_mac_ctx_cmd *cmd,
const u8 *bssid_override,
u32 action)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct ieee80211_chanctx_conf *chanctx;
bool ht_enabled = !!(vif->bss_conf.ht_operation_mode &
IEEE80211_HT_OP_MODE_PROTECTION);
u8 cck_ack_rates, ofdm_ack_rates;
const u8 *bssid = bssid_override ?: vif->bss_conf.bssid;
int i;
cmd->id_and_color = cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color));
cmd->action = cpu_to_le32(action);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
if (vif->p2p)
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_P2P_STA);
else
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_BSS_STA);
break;
case NL80211_IFTYPE_AP:
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_GO);
break;
case NL80211_IFTYPE_MONITOR:
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_LISTENER);
break;
case NL80211_IFTYPE_P2P_DEVICE:
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_P2P_DEVICE);
break;
case NL80211_IFTYPE_ADHOC:
cmd->mac_type = cpu_to_le32(FW_MAC_TYPE_IBSS);
break;
default:
WARN_ON_ONCE(1);
}
cmd->tsf_id = cpu_to_le32(mvmvif->tsf_id);
memcpy(cmd->node_addr, vif->addr, ETH_ALEN);
if (bssid)
memcpy(cmd->bssid_addr, bssid, ETH_ALEN);
else
eth_broadcast_addr(cmd->bssid_addr);
rcu_read_lock();
chanctx = rcu_dereference(vif->chanctx_conf);
iwl_mvm_ack_rates(mvm, vif, chanctx ? chanctx->def.chan->band
: IEEE80211_BAND_2GHZ,
&cck_ack_rates, &ofdm_ack_rates);
rcu_read_unlock();
cmd->cck_rates = cpu_to_le32((u32)cck_ack_rates);
cmd->ofdm_rates = cpu_to_le32((u32)ofdm_ack_rates);
cmd->cck_short_preamble =
cpu_to_le32(vif->bss_conf.use_short_preamble ?
MAC_FLG_SHORT_PREAMBLE : 0);
cmd->short_slot =
cpu_to_le32(vif->bss_conf.use_short_slot ?
MAC_FLG_SHORT_SLOT : 0);
cmd->filter_flags = cpu_to_le32(MAC_FILTER_ACCEPT_GRP);
for (i = 0; i < IEEE80211_NUM_ACS; i++) {
u8 txf = iwl_mvm_ac_to_tx_fifo[i];
cmd->ac[txf].cw_min =
cpu_to_le16(mvmvif->queue_params[i].cw_min);
cmd->ac[txf].cw_max =
cpu_to_le16(mvmvif->queue_params[i].cw_max);
cmd->ac[txf].edca_txop =
cpu_to_le16(mvmvif->queue_params[i].txop * 32);
cmd->ac[txf].aifsn = mvmvif->queue_params[i].aifs;
cmd->ac[txf].fifos_mask = BIT(txf);
}
if (vif->type == NL80211_IFTYPE_AP) {
cmd->ac[IWL_MVM_TX_FIFO_VO].fifos_mask |=
BIT(IWL_MVM_TX_FIFO_MCAST);
cmd->filter_flags |= cpu_to_le32(MAC_FILTER_IN_PROBE_REQUEST);
if (mvmvif->ap_assoc_sta_count) {
cmd->filter_flags |= cpu_to_le32(MAC_FILTER_IN_BEACON);
IWL_DEBUG_HC(mvm, "Asking FW to pass beacons\n");
} else {
IWL_DEBUG_HC(mvm, "No need to receive beacons\n");
}
}
if (vif->bss_conf.qos)
cmd->qos_flags |= cpu_to_le32(MAC_QOS_FLG_UPDATE_EDCA);
if (vif->bss_conf.use_cts_prot)
cmd->protection_flags |= cpu_to_le32(MAC_PROT_FLG_TGG_PROTECT);
IWL_DEBUG_RATE(mvm, "use_cts_prot %d, ht_operation_mode %d\n",
vif->bss_conf.use_cts_prot,
vif->bss_conf.ht_operation_mode);
if (vif->bss_conf.chandef.width != NL80211_CHAN_WIDTH_20_NOHT)
cmd->qos_flags |= cpu_to_le32(MAC_QOS_FLG_TGN);
if (ht_enabled)
iwl_mvm_mac_ctxt_set_ht_flags(mvm, vif, cmd);
}
static int iwl_mvm_mac_ctxt_send_cmd(struct iwl_mvm *mvm,
struct iwl_mac_ctx_cmd *cmd)
{
int ret = iwl_mvm_send_cmd_pdu(mvm, MAC_CONTEXT_CMD, 0,
sizeof(*cmd), cmd);
if (ret)
IWL_ERR(mvm, "Failed to send MAC context (action:%d): %d\n",
le32_to_cpu(cmd->action), ret);
return ret;
}
static int iwl_mvm_mac_ctxt_cmd_sta(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action, bool force_assoc_off,
const u8 *bssid_override)
{
struct iwl_mac_ctx_cmd cmd = {};
struct iwl_mac_data_sta *ctxt_sta;
WARN_ON(vif->type != NL80211_IFTYPE_STATION);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, bssid_override, action);
if (vif->p2p) {
struct ieee80211_p2p_noa_attr *noa =
&vif->bss_conf.p2p_noa_attr;
cmd.p2p_sta.ctwin = cpu_to_le32(noa->oppps_ctwindow &
IEEE80211_P2P_OPPPS_CTWINDOW_MASK);
ctxt_sta = &cmd.p2p_sta.sta;
} else {
ctxt_sta = &cmd.sta;
}
if (vif->bss_conf.assoc && vif->bss_conf.dtim_period &&
!force_assoc_off) {
u32 dtim_offs;
dtim_offs = vif->bss_conf.sync_dtim_count *
vif->bss_conf.beacon_int;
dtim_offs *= 1024;
ctxt_sta->dtim_tsf =
cpu_to_le64(vif->bss_conf.sync_tsf + dtim_offs);
ctxt_sta->dtim_time =
cpu_to_le32(vif->bss_conf.sync_device_ts + dtim_offs);
IWL_DEBUG_INFO(mvm, "DTIM TBTT is 0x%llx/0x%x, offset %d\n",
le64_to_cpu(ctxt_sta->dtim_tsf),
le32_to_cpu(ctxt_sta->dtim_time),
dtim_offs);
ctxt_sta->is_assoc = cpu_to_le32(1);
} else {
ctxt_sta->is_assoc = cpu_to_le32(0);
cmd.filter_flags |= cpu_to_le32(MAC_FILTER_IN_BEACON);
}
ctxt_sta->bi = cpu_to_le32(vif->bss_conf.beacon_int);
ctxt_sta->bi_reciprocal =
cpu_to_le32(iwl_mvm_reciprocal(vif->bss_conf.beacon_int));
ctxt_sta->dtim_interval = cpu_to_le32(vif->bss_conf.beacon_int *
vif->bss_conf.dtim_period);
ctxt_sta->dtim_reciprocal =
cpu_to_le32(iwl_mvm_reciprocal(vif->bss_conf.beacon_int *
vif->bss_conf.dtim_period));
ctxt_sta->listen_interval = cpu_to_le32(mvm->hw->conf.listen_interval);
ctxt_sta->assoc_id = cpu_to_le32(vif->bss_conf.aid);
if (vif->probe_req_reg && vif->bss_conf.assoc && vif->p2p)
cmd.filter_flags |= cpu_to_le32(MAC_FILTER_IN_PROBE_REQUEST);
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static int iwl_mvm_mac_ctxt_cmd_listener(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action)
{
struct iwl_mac_ctx_cmd cmd = {};
u32 tfd_queue_msk = 0;
int ret, i;
WARN_ON(vif->type != NL80211_IFTYPE_MONITOR);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, NULL, action);
for (i = 0; i < IEEE80211_NUM_ACS; i++)
if (vif->hw_queue[i] != IEEE80211_INVAL_HW_QUEUE)
tfd_queue_msk |= BIT(vif->hw_queue[i]);
cmd.filter_flags = cpu_to_le32(MAC_FILTER_IN_PROMISC |
MAC_FILTER_IN_CONTROL_AND_MGMT |
MAC_FILTER_IN_BEACON |
MAC_FILTER_IN_PROBE_REQUEST |
MAC_FILTER_IN_CRC32);
ieee80211_hw_set(mvm->hw, RX_INCLUDES_FCS);
ret = iwl_mvm_allocate_int_sta(mvm, &mvm->snif_sta, tfd_queue_msk,
vif->type);
if (ret)
return ret;
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static int iwl_mvm_mac_ctxt_cmd_ibss(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mac_ctx_cmd cmd = {};
WARN_ON(vif->type != NL80211_IFTYPE_ADHOC);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, NULL, action);
cmd.filter_flags = cpu_to_le32(MAC_FILTER_IN_BEACON |
MAC_FILTER_IN_PROBE_REQUEST);
cmd.ibss.bi = cpu_to_le32(vif->bss_conf.beacon_int);
cmd.ibss.bi_reciprocal =
cpu_to_le32(iwl_mvm_reciprocal(vif->bss_conf.beacon_int));
cmd.ibss.beacon_template = cpu_to_le32(mvmvif->id);
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static void iwl_mvm_go_iterator(void *_data, u8 *mac, struct ieee80211_vif *vif)
{
struct iwl_mvm_go_iterator_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (vif->type == NL80211_IFTYPE_AP && vif->p2p &&
mvmvif->ap_ibss_active)
data->go_active = true;
}
static int iwl_mvm_mac_ctxt_cmd_p2p_device(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action)
{
struct iwl_mac_ctx_cmd cmd = {};
struct iwl_mvm_go_iterator_data data = {};
WARN_ON(vif->type != NL80211_IFTYPE_P2P_DEVICE);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, NULL, action);
cmd.protection_flags |= cpu_to_le32(MAC_PROT_FLG_TGG_PROTECT);
cmd.filter_flags = cpu_to_le32(MAC_FILTER_IN_PROBE_REQUEST);
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_go_iterator, &data);
cmd.p2p_dev.is_disc_extended = cpu_to_le32(data.go_active ? 1 : 0);
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static void iwl_mvm_mac_ctxt_set_tim(struct iwl_mvm *mvm,
struct iwl_mac_beacon_cmd *beacon_cmd,
u8 *beacon, u32 frame_size)
{
u32 tim_idx;
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)beacon;
tim_idx = mgmt->u.beacon.variable - beacon;
while ((tim_idx < (frame_size - 2)) &&
(beacon[tim_idx] != WLAN_EID_TIM))
tim_idx += beacon[tim_idx+1] + 2;
if ((tim_idx < (frame_size - 1)) && (beacon[tim_idx] == WLAN_EID_TIM)) {
beacon_cmd->tim_idx = cpu_to_le32(tim_idx);
beacon_cmd->tim_size = cpu_to_le32((u32)beacon[tim_idx+1]);
} else {
IWL_WARN(mvm, "Unable to find TIM Element in beacon\n");
}
}
static int iwl_mvm_mac_ctxt_send_beacon(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct sk_buff *beacon)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_host_cmd cmd = {
.id = BEACON_TEMPLATE_CMD,
.flags = CMD_ASYNC,
};
struct iwl_mac_beacon_cmd beacon_cmd = {};
struct ieee80211_tx_info *info;
u32 beacon_skb_len;
u32 rate, tx_flags;
if (WARN_ON(!beacon))
return -EINVAL;
beacon_skb_len = beacon->len;
beacon_cmd.template_id = cpu_to_le32((u32)mvmvif->id);
info = IEEE80211_SKB_CB(beacon);
beacon_cmd.tx.len = cpu_to_le16((u16)beacon_skb_len);
beacon_cmd.tx.sta_id = mvmvif->bcast_sta.sta_id;
beacon_cmd.tx.life_time = cpu_to_le32(TX_CMD_LIFE_TIME_INFINITE);
tx_flags = TX_CMD_FLG_SEQ_CTL | TX_CMD_FLG_TSF;
tx_flags |=
iwl_mvm_bt_coex_tx_prio(mvm, (void *)beacon->data, info, 0) <<
TX_CMD_FLG_BT_PRIO_POS;
beacon_cmd.tx.tx_flags = cpu_to_le32(tx_flags);
if (!fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_BEACON_ANT_SELECTION)) {
mvm->mgmt_last_antenna_idx =
iwl_mvm_next_antenna(mvm, iwl_mvm_get_valid_tx_ant(mvm),
mvm->mgmt_last_antenna_idx);
}
beacon_cmd.tx.rate_n_flags =
cpu_to_le32(BIT(mvm->mgmt_last_antenna_idx) <<
RATE_MCS_ANT_POS);
if (info->band == IEEE80211_BAND_5GHZ || vif->p2p) {
rate = IWL_FIRST_OFDM_RATE;
} else {
rate = IWL_FIRST_CCK_RATE;
beacon_cmd.tx.rate_n_flags |= cpu_to_le32(RATE_MCS_CCK_MSK);
}
beacon_cmd.tx.rate_n_flags |=
cpu_to_le32(iwl_mvm_mac80211_idx_to_hwrate(rate));
if (vif->type == NL80211_IFTYPE_AP)
iwl_mvm_mac_ctxt_set_tim(mvm, &beacon_cmd,
beacon->data,
beacon_skb_len);
cmd.len[0] = sizeof(beacon_cmd);
cmd.data[0] = &beacon_cmd;
cmd.dataflags[0] = 0;
cmd.len[1] = beacon_skb_len;
cmd.data[1] = beacon->data;
cmd.dataflags[1] = IWL_HCMD_DFL_DUP;
return iwl_mvm_send_cmd(mvm, &cmd);
}
int iwl_mvm_mac_ctxt_beacon_changed(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct sk_buff *beacon;
int ret;
WARN_ON(vif->type != NL80211_IFTYPE_AP &&
vif->type != NL80211_IFTYPE_ADHOC);
beacon = ieee80211_beacon_get_template(mvm->hw, vif, NULL);
if (!beacon)
return -ENOMEM;
ret = iwl_mvm_mac_ctxt_send_beacon(mvm, vif, beacon);
dev_kfree_skb(beacon);
return ret;
}
static void iwl_mvm_mac_ap_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_mac_ap_iterator_data *data = _data;
if (vif->type != NL80211_IFTYPE_STATION || !vif->bss_conf.assoc)
return;
if (vif->p2p && data->beacon_device_ts)
return;
data->beacon_device_ts = vif->bss_conf.sync_device_ts;
data->beacon_int = vif->bss_conf.beacon_int;
}
static void iwl_mvm_mac_ctxt_cmd_fill_ap(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_mac_data_ap *ctxt_ap,
bool add)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_mac_ap_iterator_data data = {
.mvm = mvm,
.vif = vif,
.beacon_device_ts = 0
};
ctxt_ap->bi = cpu_to_le32(vif->bss_conf.beacon_int);
ctxt_ap->bi_reciprocal =
cpu_to_le32(iwl_mvm_reciprocal(vif->bss_conf.beacon_int));
ctxt_ap->dtim_interval = cpu_to_le32(vif->bss_conf.beacon_int *
vif->bss_conf.dtim_period);
ctxt_ap->dtim_reciprocal =
cpu_to_le32(iwl_mvm_reciprocal(vif->bss_conf.beacon_int *
vif->bss_conf.dtim_period));
ctxt_ap->mcast_qid = cpu_to_le32(vif->cab_queue);
if (add) {
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_mac_ap_iterator, &data);
if (data.beacon_device_ts) {
u32 rand = (prandom_u32() % (64 - 36)) + 36;
mvmvif->ap_beacon_time = data.beacon_device_ts +
ieee80211_tu_to_usec(data.beacon_int * rand /
100);
} else {
mvmvif->ap_beacon_time =
iwl_read_prph(mvm->trans,
DEVICE_SYSTEM_TIME_REG);
}
}
ctxt_ap->beacon_time = cpu_to_le32(mvmvif->ap_beacon_time);
ctxt_ap->beacon_tsf = 0;
ctxt_ap->beacon_template = cpu_to_le32(mvmvif->id);
}
static int iwl_mvm_mac_ctxt_cmd_ap(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action)
{
struct iwl_mac_ctx_cmd cmd = {};
WARN_ON(vif->type != NL80211_IFTYPE_AP || vif->p2p);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, NULL, action);
iwl_mvm_mac_ctxt_cmd_fill_ap(mvm, vif, &cmd.ap,
action == FW_CTXT_ACTION_ADD);
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static int iwl_mvm_mac_ctxt_cmd_go(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 action)
{
struct iwl_mac_ctx_cmd cmd = {};
struct ieee80211_p2p_noa_attr *noa = &vif->bss_conf.p2p_noa_attr;
WARN_ON(vif->type != NL80211_IFTYPE_AP || !vif->p2p);
iwl_mvm_mac_ctxt_cmd_common(mvm, vif, &cmd, NULL, action);
iwl_mvm_mac_ctxt_cmd_fill_ap(mvm, vif, &cmd.go.ap,
action == FW_CTXT_ACTION_ADD);
cmd.go.ctwin = cpu_to_le32(noa->oppps_ctwindow &
IEEE80211_P2P_OPPPS_CTWINDOW_MASK);
cmd.go.opp_ps_enabled =
cpu_to_le32(!!(noa->oppps_ctwindow &
IEEE80211_P2P_OPPPS_ENABLE_BIT));
return iwl_mvm_mac_ctxt_send_cmd(mvm, &cmd);
}
static int iwl_mvm_mac_ctx_send(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
u32 action, bool force_assoc_off,
const u8 *bssid_override)
{
switch (vif->type) {
case NL80211_IFTYPE_STATION:
return iwl_mvm_mac_ctxt_cmd_sta(mvm, vif, action,
force_assoc_off,
bssid_override);
break;
case NL80211_IFTYPE_AP:
if (!vif->p2p)
return iwl_mvm_mac_ctxt_cmd_ap(mvm, vif, action);
else
return iwl_mvm_mac_ctxt_cmd_go(mvm, vif, action);
break;
case NL80211_IFTYPE_MONITOR:
return iwl_mvm_mac_ctxt_cmd_listener(mvm, vif, action);
case NL80211_IFTYPE_P2P_DEVICE:
return iwl_mvm_mac_ctxt_cmd_p2p_device(mvm, vif, action);
case NL80211_IFTYPE_ADHOC:
return iwl_mvm_mac_ctxt_cmd_ibss(mvm, vif, action);
default:
break;
}
return -EOPNOTSUPP;
}
int iwl_mvm_mac_ctxt_add(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
if (WARN_ONCE(mvmvif->uploaded, "Adding active MAC %pM/%d\n",
vif->addr, ieee80211_vif_type_p2p(vif)))
return -EIO;
ret = iwl_mvm_mac_ctx_send(mvm, vif, FW_CTXT_ACTION_ADD,
true, NULL);
if (ret)
return ret;
iwl_mvm_set_last_nonqos_seq(mvm, vif);
mvmvif->uploaded = true;
return 0;
}
int iwl_mvm_mac_ctxt_changed(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
bool force_assoc_off, const u8 *bssid_override)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (WARN_ONCE(!mvmvif->uploaded, "Changing inactive MAC %pM/%d\n",
vif->addr, ieee80211_vif_type_p2p(vif)))
return -EIO;
return iwl_mvm_mac_ctx_send(mvm, vif, FW_CTXT_ACTION_MODIFY,
force_assoc_off, bssid_override);
}
int iwl_mvm_mac_ctxt_remove(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mac_ctx_cmd cmd;
int ret;
if (WARN_ONCE(!mvmvif->uploaded, "Removing inactive MAC %pM/%d\n",
vif->addr, ieee80211_vif_type_p2p(vif)))
return -EIO;
memset(&cmd, 0, sizeof(cmd));
cmd.id_and_color = cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color));
cmd.action = cpu_to_le32(FW_CTXT_ACTION_REMOVE);
ret = iwl_mvm_send_cmd_pdu(mvm, MAC_CONTEXT_CMD, 0,
sizeof(cmd), &cmd);
if (ret) {
IWL_ERR(mvm, "Failed to remove MAC context: %d\n", ret);
return ret;
}
mvmvif->uploaded = false;
if (vif->type == NL80211_IFTYPE_MONITOR) {
__clear_bit(IEEE80211_HW_RX_INCLUDES_FCS, mvm->hw->flags);
iwl_mvm_dealloc_snif_sta(mvm);
}
return 0;
}
static void iwl_mvm_csa_count_down(struct iwl_mvm *mvm,
struct ieee80211_vif *csa_vif, u32 gp2,
bool tx_success)
{
struct iwl_mvm_vif *mvmvif =
iwl_mvm_vif_from_mac80211(csa_vif);
if (!tx_success && !mvmvif->csa_countdown)
return;
mvmvif->csa_countdown = true;
if (!ieee80211_csa_is_complete(csa_vif)) {
int c = ieee80211_csa_update_counter(csa_vif);
iwl_mvm_mac_ctxt_beacon_changed(mvm, csa_vif);
if (csa_vif->p2p &&
!iwl_mvm_te_scheduled(&mvmvif->time_event_data) && gp2 &&
tx_success) {
u32 rel_time = (c + 1) *
csa_vif->bss_conf.beacon_int -
IWL_MVM_CHANNEL_SWITCH_TIME_GO;
u32 apply_time = gp2 + rel_time * 1024;
iwl_mvm_schedule_csa_period(mvm, csa_vif,
IWL_MVM_CHANNEL_SWITCH_TIME_GO -
IWL_MVM_CHANNEL_SWITCH_MARGIN,
apply_time);
}
} else if (!iwl_mvm_te_scheduled(&mvmvif->time_event_data)) {
ieee80211_csa_finish(csa_vif);
RCU_INIT_POINTER(mvm->csa_vif, NULL);
}
}
void iwl_mvm_rx_beacon_notif(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_extended_beacon_notif *beacon = (void *)pkt->data;
struct iwl_mvm_tx_resp *beacon_notify_hdr;
struct ieee80211_vif *csa_vif;
struct ieee80211_vif *tx_blocked_vif;
u16 status;
lockdep_assert_held(&mvm->mutex);
beacon_notify_hdr = &beacon->beacon_notify_hdr;
mvm->ap_last_beacon_gp2 = le32_to_cpu(beacon->gp2);
status = le16_to_cpu(beacon_notify_hdr->status.status) & TX_STATUS_MSK;
IWL_DEBUG_RX(mvm,
"beacon status %#x retries:%d tsf:0x%16llX gp2:0x%X rate:%d\n",
status, beacon_notify_hdr->failure_frame,
le64_to_cpu(beacon->tsf),
mvm->ap_last_beacon_gp2,
le32_to_cpu(beacon_notify_hdr->initial_rate));
csa_vif = rcu_dereference_protected(mvm->csa_vif,
lockdep_is_held(&mvm->mutex));
if (unlikely(csa_vif && csa_vif->csa_active))
iwl_mvm_csa_count_down(mvm, csa_vif, mvm->ap_last_beacon_gp2,
(status == TX_STATUS_SUCCESS));
tx_blocked_vif = rcu_dereference_protected(mvm->csa_tx_blocked_vif,
lockdep_is_held(&mvm->mutex));
if (unlikely(tx_blocked_vif)) {
struct iwl_mvm_vif *mvmvif =
iwl_mvm_vif_from_mac80211(tx_blocked_vif);
if (!mvm->csa_tx_block_bcn_timeout)
mvm->csa_tx_block_bcn_timeout =
IWL_MVM_CS_UNBLOCK_TX_TIMEOUT;
else
mvm->csa_tx_block_bcn_timeout--;
if (mvm->csa_tx_block_bcn_timeout == 0) {
iwl_mvm_modify_all_sta_disable_tx(mvm, mvmvif, false);
RCU_INIT_POINTER(mvm->csa_tx_blocked_vif, NULL);
}
}
}
static void iwl_mvm_beacon_loss_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_missed_beacons_notif *missed_beacons = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm *mvm = mvmvif->mvm;
struct iwl_fw_dbg_trigger_missed_bcon *bcon_trig;
struct iwl_fw_dbg_trigger_tlv *trigger;
u32 stop_trig_missed_bcon, stop_trig_missed_bcon_since_rx;
u32 rx_missed_bcon, rx_missed_bcon_since_rx;
if (mvmvif->id != (u16)le32_to_cpu(missed_beacons->mac_id))
return;
rx_missed_bcon = le32_to_cpu(missed_beacons->consec_missed_beacons);
rx_missed_bcon_since_rx =
le32_to_cpu(missed_beacons->consec_missed_beacons_since_last_rx);
if (le32_to_cpu(missed_beacons->consec_missed_beacons_since_last_rx) >
IWL_MVM_MISSED_BEACONS_THRESHOLD)
ieee80211_beacon_loss(vif);
if (!iwl_fw_dbg_trigger_enabled(mvm->fw,
FW_DBG_TRIGGER_MISSED_BEACONS))
return;
trigger = iwl_fw_dbg_get_trigger(mvm->fw,
FW_DBG_TRIGGER_MISSED_BEACONS);
bcon_trig = (void *)trigger->data;
stop_trig_missed_bcon = le32_to_cpu(bcon_trig->stop_consec_missed_bcon);
stop_trig_missed_bcon_since_rx =
le32_to_cpu(bcon_trig->stop_consec_missed_bcon_since_rx);
if (!iwl_fw_dbg_trigger_check_stop(mvm, vif, trigger))
return;
if (rx_missed_bcon_since_rx >= stop_trig_missed_bcon_since_rx ||
rx_missed_bcon >= stop_trig_missed_bcon)
iwl_mvm_fw_dbg_collect_trig(mvm, trigger, NULL);
}
void iwl_mvm_rx_missed_beacons_notif(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_missed_beacons_notif *mb = (void *)pkt->data;
IWL_DEBUG_INFO(mvm,
"missed bcn mac_id=%u, consecutive=%u (%u, %u, %u)\n",
le32_to_cpu(mb->mac_id),
le32_to_cpu(mb->consec_missed_beacons),
le32_to_cpu(mb->consec_missed_beacons_since_last_rx),
le32_to_cpu(mb->num_recvd_beacons),
le32_to_cpu(mb->num_expected_beacons));
ieee80211_iterate_active_interfaces_atomic(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_beacon_loss_iterator,
mb);
}
