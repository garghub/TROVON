void iwl_mvm_ref(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref_type)
{
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
IWL_DEBUG_RPM(mvm, "Take mvm reference - type %d\n", ref_type);
WARN_ON(test_and_set_bit(ref_type, mvm->ref_bitmap));
iwl_trans_ref(mvm->trans);
}
void iwl_mvm_unref(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref_type)
{
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
IWL_DEBUG_RPM(mvm, "Leave mvm reference - type %d\n", ref_type);
WARN_ON(!test_and_clear_bit(ref_type, mvm->ref_bitmap));
iwl_trans_unref(mvm->trans);
}
static void
iwl_mvm_unref_all_except(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref)
{
int i;
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
for_each_set_bit(i, mvm->ref_bitmap, IWL_MVM_REF_COUNT) {
if (ref == i)
continue;
IWL_DEBUG_RPM(mvm, "Cleanup: remove mvm ref type %d\n", i);
clear_bit(i, mvm->ref_bitmap);
iwl_trans_unref(mvm->trans);
}
}
static void iwl_mvm_reset_phy_ctxts(struct iwl_mvm *mvm)
{
int i;
memset(mvm->phy_ctxts, 0, sizeof(mvm->phy_ctxts));
for (i = 0; i < NUM_PHY_CTX; i++) {
mvm->phy_ctxts[i].id = i;
mvm->phy_ctxts[i].ref = 0;
}
}
static int iwl_mvm_max_scan_ie_len(struct iwl_mvm *mvm)
{
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NO_BASIC_SSID)
return mvm->fw->ucode_capa.max_probe_length - 24 - 2;
return mvm->fw->ucode_capa.max_probe_length - 24 - 34;
}
int iwl_mvm_mac_setup_register(struct iwl_mvm *mvm)
{
struct ieee80211_hw *hw = mvm->hw;
int num_mac, ret, i;
hw->flags = IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SPECTRUM_MGMT |
IEEE80211_HW_REPORTS_TX_ACK_STATUS |
IEEE80211_HW_QUEUE_CONTROL |
IEEE80211_HW_WANT_MONITOR_VIF |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_SUPPORTS_DYNAMIC_PS |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_TIMING_BEACON_ONLY |
IEEE80211_HW_CONNECTION_MONITOR |
IEEE80211_HW_SUPPORTS_DYNAMIC_SMPS |
IEEE80211_HW_SUPPORTS_STATIC_SMPS;
hw->queues = mvm->first_agg_queue;
hw->offchannel_tx_hw_queue = IWL_MVM_OFFCHANNEL_QUEUE;
hw->radiotap_mcs_details |= IEEE80211_RADIOTAP_MCS_HAVE_FEC |
IEEE80211_RADIOTAP_MCS_HAVE_STBC;
hw->radiotap_vht_details |= IEEE80211_RADIOTAP_VHT_KNOWN_STBC;
hw->rate_control_algorithm = "iwl-mvm-rs";
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_MFP &&
!iwlwifi_mod_params.sw_crypto)
hw->flags |= IEEE80211_HW_MFP_CAPABLE;
if (0 && mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_UAPSD_SUPPORT) {
hw->flags |= IEEE80211_HW_SUPPORTS_UAPSD;
hw->uapsd_queues = IWL_UAPSD_AC_INFO;
hw->uapsd_max_sp_len = IWL_UAPSD_MAX_SP;
}
hw->sta_data_size = sizeof(struct iwl_mvm_sta);
hw->vif_data_size = sizeof(struct iwl_mvm_vif);
hw->chanctx_data_size = sizeof(u16);
hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_P2P_GO) |
BIT(NL80211_IFTYPE_P2P_DEVICE);
if (IWL_UCODE_API(mvm->fw->ucode_ver) >= 8)
hw->wiphy->interface_modes |= BIT(NL80211_IFTYPE_ADHOC);
hw->wiphy->flags |= WIPHY_FLAG_IBSS_RSN;
hw->wiphy->regulatory_flags |= REGULATORY_CUSTOM_REG |
REGULATORY_DISABLE_BEACON_HINTS;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_GO_UAPSD)
hw->wiphy->flags |= WIPHY_FLAG_AP_UAPSD;
hw->wiphy->iface_combinations = iwl_mvm_iface_combinations;
hw->wiphy->n_iface_combinations =
ARRAY_SIZE(iwl_mvm_iface_combinations);
hw->wiphy->max_remain_on_channel_duration = 10000;
hw->max_listen_interval = IWL_CONN_MAX_LISTEN_INTERVAL;
memcpy(mvm->addresses[0].addr, mvm->nvm_data->hw_addr, ETH_ALEN);
hw->wiphy->addresses = mvm->addresses;
hw->wiphy->n_addresses = 1;
num_mac = (mvm->nvm_data->n_hw_addrs > 1) ?
min(IWL_MVM_MAX_ADDRESSES, mvm->nvm_data->n_hw_addrs) : 1;
for (i = 1; i < num_mac; i++) {
memcpy(mvm->addresses[i].addr, mvm->addresses[i-1].addr,
ETH_ALEN);
mvm->addresses[i].addr[5]++;
hw->wiphy->n_addresses++;
}
iwl_mvm_reset_phy_ctxts(mvm);
hw->wiphy->max_scan_ie_len = iwl_mvm_max_scan_ie_len(mvm);
hw->wiphy->max_scan_ssids = PROBE_OPTION_MAX;
if (mvm->nvm_data->bands[IEEE80211_BAND_2GHZ].n_channels)
hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&mvm->nvm_data->bands[IEEE80211_BAND_2GHZ];
if (mvm->nvm_data->bands[IEEE80211_BAND_5GHZ].n_channels)
hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&mvm->nvm_data->bands[IEEE80211_BAND_5GHZ];
hw->wiphy->hw_version = mvm->trans->hw_id;
if (iwlmvm_mod_params.power_scheme != IWL_POWER_SCHEME_CAM)
hw->wiphy->flags |= WIPHY_FLAG_PS_ON_BY_DEFAULT;
else
hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_SCHED_SCAN) {
hw->wiphy->flags |= WIPHY_FLAG_SUPPORTS_SCHED_SCAN;
hw->wiphy->max_sched_scan_ssids = PROBE_OPTION_MAX;
hw->wiphy->max_match_sets = IWL_SCAN_MAX_PROFILES;
hw->wiphy->max_sched_scan_ie_len =
SCAN_OFFLOAD_PROBE_REQ_SIZE - 24 - 2;
}
hw->wiphy->features |= NL80211_FEATURE_P2P_GO_CTWIN |
NL80211_FEATURE_P2P_GO_OPPPS;
mvm->rts_threshold = IEEE80211_MAX_RTS_THRESHOLD;
if (mvm->fw->cs[0].cipher) {
mvm->hw->n_cipher_schemes = 1;
mvm->hw->cipher_schemes = &mvm->fw->cs[0];
}
#ifdef CONFIG_PM_SLEEP
if (mvm->fw->img[IWL_UCODE_WOWLAN].sec[0].len &&
mvm->trans->ops->d3_suspend &&
mvm->trans->ops->d3_resume &&
device_can_wakeup(mvm->trans->dev)) {
mvm->wowlan.flags = WIPHY_WOWLAN_MAGIC_PKT |
WIPHY_WOWLAN_DISCONNECT |
WIPHY_WOWLAN_EAP_IDENTITY_REQ |
WIPHY_WOWLAN_RFKILL_RELEASE;
if (!iwlwifi_mod_params.sw_crypto)
mvm->wowlan.flags |= WIPHY_WOWLAN_SUPPORTS_GTK_REKEY |
WIPHY_WOWLAN_GTK_REKEY_FAILURE |
WIPHY_WOWLAN_4WAY_HANDSHAKE;
mvm->wowlan.n_patterns = IWL_WOWLAN_MAX_PATTERNS;
mvm->wowlan.pattern_min_len = IWL_WOWLAN_MIN_PATTERN_LEN;
mvm->wowlan.pattern_max_len = IWL_WOWLAN_MAX_PATTERN_LEN;
mvm->wowlan.tcp = &iwl_mvm_wowlan_tcp_support;
hw->wiphy->wowlan = &mvm->wowlan;
}
#endif
#ifdef CONFIG_IWLWIFI_BCAST_FILTERING
mvm->bcast_filters = iwl_mvm_default_bcast_filters;
#endif
ret = iwl_mvm_leds_init(mvm);
if (ret)
return ret;
ret = ieee80211_register_hw(mvm->hw);
if (ret)
iwl_mvm_leds_exit(mvm);
return ret;
}
static bool iwl_mvm_defer_tx(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct sk_buff *skb)
{
struct iwl_mvm_sta *mvmsta;
bool defer = false;
if (likely(!test_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status)))
return false;
spin_lock(&mvm->d0i3_tx_lock);
if (!test_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status))
goto out;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (mvmsta->sta_id == IWL_MVM_STATION_COUNT ||
mvmsta->sta_id != mvm->d0i3_ap_sta_id)
goto out;
__skb_queue_tail(&mvm->d0i3_tx, skb);
ieee80211_stop_queues(mvm->hw);
iwl_mvm_ref(mvm, IWL_MVM_REF_TX);
iwl_mvm_unref(mvm, IWL_MVM_REF_TX);
defer = true;
out:
spin_unlock(&mvm->d0i3_tx_lock);
return defer;
}
static void iwl_mvm_mac_tx(struct ieee80211_hw *hw,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct ieee80211_sta *sta = control->sta;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (void *)skb->data;
if (iwl_mvm_is_radio_killed(mvm)) {
IWL_DEBUG_DROP(mvm, "Dropping - RF/CT KILL\n");
goto drop;
}
if (IEEE80211_SKB_CB(skb)->hw_queue == IWL_MVM_OFFCHANNEL_QUEUE &&
!test_bit(IWL_MVM_STATUS_ROC_RUNNING, &mvm->status))
goto drop;
if (unlikely(info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER &&
ieee80211_is_mgmt(hdr->frame_control) &&
!ieee80211_is_deauth(hdr->frame_control) &&
!ieee80211_is_disassoc(hdr->frame_control) &&
!ieee80211_is_action(hdr->frame_control)))
sta = NULL;
if (sta) {
if (iwl_mvm_defer_tx(mvm, sta, skb))
return;
if (iwl_mvm_tx_skb(mvm, skb, sta))
goto drop;
return;
}
if (iwl_mvm_tx_skb_non_sta(mvm, skb))
goto drop;
return;
drop:
ieee80211_free_txskb(hw, skb);
}
static inline bool iwl_enable_rx_ampdu(const struct iwl_cfg *cfg)
{
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_RXAGG)
return false;
return true;
}
static inline bool iwl_enable_tx_ampdu(const struct iwl_cfg *cfg)
{
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_TXAGG)
return false;
if (iwlwifi_mod_params.disable_11n & IWL_ENABLE_HT_TXAGG)
return true;
return true;
}
static int iwl_mvm_mac_ampdu_action(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid,
u16 *ssn, u8 buf_size)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
bool tx_agg_ref = false;
IWL_DEBUG_HT(mvm, "A-MPDU action on addr %pM tid %d: action %d\n",
sta->addr, tid, action);
if (!(mvm->nvm_data->sku_cap_11n_enable))
return -EACCES;
if (action == IEEE80211_AMPDU_TX_START) {
iwl_mvm_ref(mvm, IWL_MVM_REF_TX_AGG);
tx_agg_ref = true;
if (!wait_event_timeout(mvm->d0i3_exit_waitq,
!test_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status), HZ)) {
WARN_ON_ONCE(1);
iwl_mvm_unref(mvm, IWL_MVM_REF_TX_AGG);
return -EIO;
}
}
mutex_lock(&mvm->mutex);
switch (action) {
case IEEE80211_AMPDU_RX_START:
if (!iwl_enable_rx_ampdu(mvm->cfg)) {
ret = -EINVAL;
break;
}
ret = iwl_mvm_sta_rx_agg(mvm, sta, tid, *ssn, true);
break;
case IEEE80211_AMPDU_RX_STOP:
ret = iwl_mvm_sta_rx_agg(mvm, sta, tid, 0, false);
break;
case IEEE80211_AMPDU_TX_START:
if (!iwl_enable_tx_ampdu(mvm->cfg)) {
ret = -EINVAL;
break;
}
ret = iwl_mvm_sta_tx_agg_start(mvm, vif, sta, tid, ssn);
break;
case IEEE80211_AMPDU_TX_STOP_CONT:
ret = iwl_mvm_sta_tx_agg_stop(mvm, vif, sta, tid);
break;
case IEEE80211_AMPDU_TX_STOP_FLUSH:
case IEEE80211_AMPDU_TX_STOP_FLUSH_CONT:
ret = iwl_mvm_sta_tx_agg_flush(mvm, vif, sta, tid);
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
ret = iwl_mvm_sta_tx_agg_oper(mvm, vif, sta, tid, buf_size);
break;
default:
WARN_ON_ONCE(1);
ret = -EINVAL;
break;
}
mutex_unlock(&mvm->mutex);
if (tx_agg_ref)
iwl_mvm_unref(mvm, IWL_MVM_REF_TX_AGG);
return ret;
}
static void iwl_mvm_cleanup_iterator(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
mvmvif->uploaded = false;
mvmvif->ap_sta_id = IWL_MVM_STATION_COUNT;
mvmvif->color++;
spin_lock_bh(&mvm->time_event_lock);
iwl_mvm_te_clear_data(mvm, &mvmvif->time_event_data);
spin_unlock_bh(&mvm->time_event_lock);
mvmvif->phy_ctxt = NULL;
}
static void iwl_mvm_restart_cleanup(struct iwl_mvm *mvm)
{
#ifdef CONFIG_IWLWIFI_DEBUGFS
static char *env[] = { "DRIVER=iwlwifi", "EVENT=error_dump", NULL };
iwl_mvm_fw_error_dump(mvm);
kobject_uevent_env(&mvm->hw->wiphy->dev.kobj, KOBJ_CHANGE, env);
#endif
iwl_trans_stop_device(mvm->trans);
mvm->scan_status = IWL_MVM_SCAN_NONE;
ieee80211_remain_on_channel_expired(mvm->hw);
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_cleanup_iterator, mvm);
mvm->p2p_device_vif = NULL;
mvm->d0i3_ap_sta_id = IWL_MVM_STATION_COUNT;
iwl_mvm_reset_phy_ctxts(mvm);
memset(mvm->fw_key_table, 0, sizeof(mvm->fw_key_table));
memset(mvm->sta_drained, 0, sizeof(mvm->sta_drained));
ieee80211_wake_queues(mvm->hw);
iwl_mvm_unref_all_except(mvm, IWL_MVM_REF_UCODE_DOWN);
mvm->vif_count = 0;
mvm->rx_ba_sessions = 0;
}
static int iwl_mvm_mac_start(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status))
iwl_mvm_restart_cleanup(mvm);
ret = iwl_mvm_up(mvm);
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_mac_restart_complete(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
clear_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
iwl_mvm_d0i3_enable_tx(mvm, NULL);
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret)
IWL_ERR(mvm, "Failed to update quotas after restart (%d)\n",
ret);
iwl_mvm_unref(mvm, IWL_MVM_REF_UCODE_DOWN);
mutex_unlock(&mvm->mutex);
}
static void iwl_mvm_mac_stop(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
flush_work(&mvm->d0i3_exit_work);
flush_work(&mvm->async_handlers_wk);
mutex_lock(&mvm->mutex);
iwl_mvm_ref(mvm, IWL_MVM_REF_UCODE_DOWN);
cancel_work_sync(&mvm->roc_done_wk);
iwl_trans_stop_device(mvm->trans);
iwl_mvm_async_handlers_purge(mvm);
iwl_mvm_dealloc_int_sta(mvm, &mvm->aux_sta);
mutex_unlock(&mvm->mutex);
cancel_work_sync(&mvm->async_handlers_wk);
}
static struct iwl_mvm_phy_ctxt *iwl_mvm_get_free_phy_ctxt(struct iwl_mvm *mvm)
{
u16 i;
lockdep_assert_held(&mvm->mutex);
for (i = 0; i < NUM_PHY_CTX; i++)
if (!mvm->phy_ctxts[i].ref)
return &mvm->phy_ctxts[i];
IWL_ERR(mvm, "No available PHY context\n");
return NULL;
}
static int iwl_mvm_set_tx_power(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
s8 tx_power)
{
struct iwl_reduce_tx_power_cmd reduce_txpwr_cmd = {
.mac_context_id = iwl_mvm_vif_from_mac80211(vif)->id,
.pwr_restriction = cpu_to_le16(tx_power),
};
return iwl_mvm_send_cmd_pdu(mvm, REDUCE_TX_POWER_CMD, CMD_SYNC,
sizeof(reduce_txpwr_cmd),
&reduce_txpwr_cmd);
}
static int iwl_mvm_mac_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_mac_ctxt_init(mvm, vif);
if (ret)
goto out_unlock;
if (vif->type != NL80211_IFTYPE_P2P_DEVICE)
mvm->vif_count++;
if (vif->type == NL80211_IFTYPE_AP ||
vif->type == NL80211_IFTYPE_ADHOC) {
u32 qmask = iwl_mvm_mac_get_queues_mask(mvm, vif);
ret = iwl_mvm_allocate_int_sta(mvm, &mvmvif->bcast_sta,
qmask,
ieee80211_vif_type_p2p(vif));
if (ret) {
IWL_ERR(mvm, "Failed to allocate bcast sta\n");
goto out_release;
}
iwl_mvm_vif_dbgfs_register(mvm, vif);
goto out_unlock;
}
ret = iwl_mvm_mac_ctxt_add(mvm, vif);
if (ret)
goto out_release;
ret = iwl_mvm_power_update_mac(mvm, vif);
if (ret)
goto out_release;
ret = iwl_mvm_disable_beacon_filter(mvm, vif, CMD_SYNC);
if (ret)
goto out_remove_mac;
if (!mvm->bf_allowed_vif && false &&
vif->type == NL80211_IFTYPE_STATION && !vif->p2p &&
mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_BF_UPDATED){
mvm->bf_allowed_vif = mvmvif;
vif->driver_flags |= IEEE80211_VIF_BEACON_FILTER |
IEEE80211_VIF_SUPPORTS_CQM_RSSI;
}
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
mvmvif->phy_ctxt = iwl_mvm_get_free_phy_ctxt(mvm);
if (!mvmvif->phy_ctxt) {
ret = -ENOSPC;
goto out_free_bf;
}
iwl_mvm_phy_ctxt_ref(mvm, mvmvif->phy_ctxt);
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (ret)
goto out_unref_phy;
ret = iwl_mvm_add_bcast_sta(mvm, vif, &mvmvif->bcast_sta);
if (ret)
goto out_unbind;
mvm->p2p_device_vif = vif;
}
iwl_mvm_vif_dbgfs_register(mvm, vif);
goto out_unlock;
out_unbind:
iwl_mvm_binding_remove_vif(mvm, vif);
out_unref_phy:
iwl_mvm_phy_ctxt_unref(mvm, mvmvif->phy_ctxt);
out_free_bf:
if (mvm->bf_allowed_vif == mvmvif) {
mvm->bf_allowed_vif = NULL;
vif->driver_flags &= ~(IEEE80211_VIF_BEACON_FILTER |
IEEE80211_VIF_SUPPORTS_CQM_RSSI);
}
out_remove_mac:
mvmvif->phy_ctxt = NULL;
iwl_mvm_mac_ctxt_remove(mvm, vif);
out_release:
if (vif->type != NL80211_IFTYPE_P2P_DEVICE)
mvm->vif_count--;
iwl_mvm_mac_ctxt_release(mvm, vif);
out_unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_prepare_mac_removal(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
u32 tfd_msk = 0, ac;
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
if (vif->hw_queue[ac] != IEEE80211_INVAL_HW_QUEUE)
tfd_msk |= BIT(vif->hw_queue[ac]);
if (vif->cab_queue != IEEE80211_INVAL_HW_QUEUE)
tfd_msk |= BIT(vif->cab_queue);
if (tfd_msk) {
mutex_lock(&mvm->mutex);
iwl_mvm_flush_tx_path(mvm, tfd_msk, true);
mutex_unlock(&mvm->mutex);
}
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
flush_work(&mvm->roc_done_wk);
} else {
flush_work(&mvm->sta_drained_wk);
}
}
static void iwl_mvm_mac_remove_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
iwl_mvm_prepare_mac_removal(mvm, vif);
mutex_lock(&mvm->mutex);
if (mvm->bf_allowed_vif == mvmvif) {
mvm->bf_allowed_vif = NULL;
vif->driver_flags &= ~(IEEE80211_VIF_BEACON_FILTER |
IEEE80211_VIF_SUPPORTS_CQM_RSSI);
}
iwl_mvm_vif_dbgfs_clean(mvm, vif);
if (vif->type == NL80211_IFTYPE_AP ||
vif->type == NL80211_IFTYPE_ADHOC) {
#ifdef CONFIG_NL80211_TESTMODE
if (vif == mvm->noa_vif) {
mvm->noa_vif = NULL;
mvm->noa_duration = 0;
}
#endif
iwl_mvm_dealloc_int_sta(mvm, &mvmvif->bcast_sta);
goto out_release;
}
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
mvm->p2p_device_vif = NULL;
iwl_mvm_rm_bcast_sta(mvm, &mvmvif->bcast_sta);
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_phy_ctxt_unref(mvm, mvmvif->phy_ctxt);
mvmvif->phy_ctxt = NULL;
}
if (mvm->vif_count && vif->type != NL80211_IFTYPE_P2P_DEVICE)
mvm->vif_count--;
iwl_mvm_power_update_mac(mvm, vif);
iwl_mvm_mac_ctxt_remove(mvm, vif);
out_release:
iwl_mvm_mac_ctxt_release(mvm, vif);
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_mac_config(struct ieee80211_hw *hw, u32 changed)
{
return 0;
}
static void iwl_mvm_mc_iface_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_mc_iter_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct iwl_mcast_filter_cmd *cmd = mvm->mcast_filter_cmd;
int ret, len;
if (WARN_ON_ONCE(data->port_id >= MAX_PORT_ID_NUM))
return;
if (vif->type != NL80211_IFTYPE_STATION ||
!vif->bss_conf.assoc)
return;
cmd->port_id = data->port_id++;
memcpy(cmd->bssid, vif->bss_conf.bssid, ETH_ALEN);
len = roundup(sizeof(*cmd) + cmd->count * ETH_ALEN, 4);
ret = iwl_mvm_send_cmd_pdu(mvm, MCAST_FILTER_CMD, CMD_ASYNC, len, cmd);
if (ret)
IWL_ERR(mvm, "mcast filter cmd error. ret=%d\n", ret);
}
static void iwl_mvm_recalc_multicast(struct iwl_mvm *mvm)
{
struct iwl_mvm_mc_iter_data iter_data = {
.mvm = mvm,
};
lockdep_assert_held(&mvm->mutex);
if (WARN_ON_ONCE(!mvm->mcast_filter_cmd))
return;
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_mc_iface_iterator, &iter_data);
}
static u64 iwl_mvm_prepare_multicast(struct ieee80211_hw *hw,
struct netdev_hw_addr_list *mc_list)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mcast_filter_cmd *cmd;
struct netdev_hw_addr *addr;
int addr_count = netdev_hw_addr_list_count(mc_list);
bool pass_all = false;
int len;
if (addr_count > MAX_MCAST_FILTERING_ADDRESSES) {
pass_all = true;
addr_count = 0;
}
len = roundup(sizeof(*cmd) + addr_count * ETH_ALEN, 4);
cmd = kzalloc(len, GFP_ATOMIC);
if (!cmd)
return 0;
if (pass_all) {
cmd->pass_all = 1;
return (u64)(unsigned long)cmd;
}
netdev_hw_addr_list_for_each(addr, mc_list) {
IWL_DEBUG_MAC80211(mvm, "mcast addr (%d): %pM\n",
cmd->count, addr->addr);
memcpy(&cmd->addr_list[cmd->count * ETH_ALEN],
addr->addr, ETH_ALEN);
cmd->count++;
}
return (u64)(unsigned long)cmd;
}
static void iwl_mvm_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags,
u64 multicast)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mcast_filter_cmd *cmd = (void *)(unsigned long)multicast;
mutex_lock(&mvm->mutex);
kfree(mvm->mcast_filter_cmd);
mvm->mcast_filter_cmd = cmd;
if (!cmd)
goto out;
iwl_mvm_recalc_multicast(mvm);
out:
mutex_unlock(&mvm->mutex);
*total_flags = 0;
}
static void
iwl_mvm_set_bcast_filter(struct ieee80211_vif *vif,
const struct iwl_fw_bcast_filter *in_filter,
struct iwl_fw_bcast_filter *out_filter)
{
struct iwl_fw_bcast_filter_attr *attr;
int i;
memcpy(out_filter, in_filter, sizeof(*out_filter));
for (i = 0; i < ARRAY_SIZE(out_filter->attrs); i++) {
attr = &out_filter->attrs[i];
if (!attr->mask)
break;
switch (attr->reserved1) {
case cpu_to_le16(BC_FILTER_MAGIC_IP):
if (vif->bss_conf.arp_addr_cnt != 1) {
attr->mask = 0;
continue;
}
attr->val = vif->bss_conf.arp_addr_list[0];
break;
case cpu_to_le16(BC_FILTER_MAGIC_MAC):
attr->val = *(__be32 *)&vif->addr[2];
break;
default:
break;
}
attr->reserved1 = 0;
out_filter->num_attrs++;
}
}
static void iwl_mvm_bcast_filter_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_bcast_iter_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct iwl_bcast_filter_cmd *cmd = data->cmd;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_fw_bcast_mac *bcast_mac;
int i;
if (WARN_ON(mvmvif->id >= ARRAY_SIZE(cmd->macs)))
return;
bcast_mac = &cmd->macs[mvmvif->id];
if (vif->type != NL80211_IFTYPE_STATION || !vif->bss_conf.assoc)
return;
bcast_mac->default_discard = 1;
for (i = 0; mvm->bcast_filters[i].attrs[0].mask; i++) {
if (WARN_ON_ONCE(data->current_filter >=
ARRAY_SIZE(cmd->filters))) {
bcast_mac->default_discard = 0;
bcast_mac->attached_filters = 0;
break;
}
iwl_mvm_set_bcast_filter(vif,
&mvm->bcast_filters[i],
&cmd->filters[data->current_filter]);
if (!cmd->filters[data->current_filter].num_attrs)
continue;
bcast_mac->attached_filters |=
cpu_to_le16(BIT(data->current_filter));
data->current_filter++;
}
}
bool iwl_mvm_bcast_filter_build_cmd(struct iwl_mvm *mvm,
struct iwl_bcast_filter_cmd *cmd)
{
struct iwl_bcast_iter_data iter_data = {
.mvm = mvm,
.cmd = cmd,
};
memset(cmd, 0, sizeof(*cmd));
cmd->max_bcast_filters = ARRAY_SIZE(cmd->filters);
cmd->max_macs = ARRAY_SIZE(cmd->macs);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvm->dbgfs_bcast_filtering.override) {
memcpy(cmd->filters, &mvm->dbgfs_bcast_filtering.cmd.filters,
sizeof(cmd->filters));
memcpy(cmd->macs, &mvm->dbgfs_bcast_filtering.cmd.macs,
sizeof(cmd->macs));
return true;
}
#endif
if (!mvm->bcast_filters)
return false;
ieee80211_iterate_active_interfaces(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_bcast_filter_iterator, &iter_data);
return true;
}
static int iwl_mvm_configure_bcast_filter(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_bcast_filter_cmd cmd;
if (!(mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_BCAST_FILTERING))
return 0;
if (!iwl_mvm_bcast_filter_build_cmd(mvm, &cmd))
return 0;
return iwl_mvm_send_cmd_pdu(mvm, BCAST_FILTER_CMD, CMD_SYNC,
sizeof(cmd), &cmd);
}
static inline int iwl_mvm_configure_bcast_filter(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
return 0;
}
static void iwl_mvm_bss_info_changed_station(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *bss_conf,
u32 changes)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
if (changes & BSS_CHANGED_ASSOC && bss_conf->assoc)
iwl_mvm_mac_ctxt_recalc_tsf_id(mvm, vif);
ret = iwl_mvm_mac_ctxt_changed(mvm, vif);
if (ret)
IWL_ERR(mvm, "failed to update MAC %pM\n", vif->addr);
if (changes & BSS_CHANGED_ASSOC) {
if (bss_conf->assoc) {
ret = iwl_mvm_update_quotas(mvm, vif);
if (ret) {
IWL_ERR(mvm, "failed to update quotas\n");
return;
}
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART,
&mvm->status)) {
u32 dur = (11 * vif->bss_conf.beacon_int) / 10;
iwl_mvm_protect_session(mvm, vif, dur, dur,
5 * dur);
}
iwl_mvm_sf_update(mvm, vif, false);
iwl_mvm_power_vif_assoc(mvm, vif);
if (vif->p2p)
iwl_mvm_ref(mvm, IWL_MVM_REF_P2P_CLIENT);
} else if (mvmvif->ap_sta_id != IWL_MVM_STATION_COUNT) {
WARN_ONCE(iwl_mvm_sf_update(mvm, vif, false),
"Failed to update SF upon disassociation\n");
ret = iwl_mvm_rm_sta_id(mvm, vif, mvmvif->ap_sta_id);
if (ret)
IWL_ERR(mvm, "failed to remove AP station\n");
if (mvm->d0i3_ap_sta_id == mvmvif->ap_sta_id)
mvm->d0i3_ap_sta_id = IWL_MVM_STATION_COUNT;
mvmvif->ap_sta_id = IWL_MVM_STATION_COUNT;
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret)
IWL_ERR(mvm, "failed to update quotas\n");
if (vif->p2p)
iwl_mvm_unref(mvm, IWL_MVM_REF_P2P_CLIENT);
}
iwl_mvm_recalc_multicast(mvm);
iwl_mvm_configure_bcast_filter(mvm, vif);
mvmvif->bf_data.ave_beacon_signal = 0;
iwl_mvm_bt_coex_vif_change(mvm);
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_TT,
IEEE80211_SMPS_AUTOMATIC);
} else if (changes & BSS_CHANGED_BEACON_INFO) {
iwl_mvm_remove_time_event(mvm, mvmvif,
&mvmvif->time_event_data);
iwl_mvm_sf_update(mvm, vif, false);
WARN_ON(iwl_mvm_enable_beacon_filter(mvm, vif, CMD_SYNC));
} else if (changes & (BSS_CHANGED_PS | BSS_CHANGED_P2P_PS |
BSS_CHANGED_QOS)) {
ret = iwl_mvm_power_update_mac(mvm, vif);
if (ret)
IWL_ERR(mvm, "failed to update power mode\n");
}
if (changes & BSS_CHANGED_TXPOWER) {
IWL_DEBUG_CALIB(mvm, "Changing TX Power to %d\n",
bss_conf->txpower);
iwl_mvm_set_tx_power(mvm, vif, bss_conf->txpower);
}
if (changes & BSS_CHANGED_CQM) {
IWL_DEBUG_MAC80211(mvm, "cqm info_changed");
mvmvif->bf_data.last_cqm_event = 0;
ret = iwl_mvm_update_beacon_filter(mvm, vif, false, CMD_SYNC);
if (ret)
IWL_ERR(mvm, "failed to update CQM thresholds\n");
}
if (changes & BSS_CHANGED_ARP_FILTER) {
IWL_DEBUG_MAC80211(mvm, "arp filter changed");
iwl_mvm_configure_bcast_filter(mvm, vif);
}
}
static int iwl_mvm_start_ap_ibss(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_mac_ctxt_beacon_changed(mvm, vif);
if (ret)
goto out_unlock;
if (vif->type == NL80211_IFTYPE_AP)
iwl_mvm_mac_ctxt_recalc_tsf_id(mvm, vif);
ret = iwl_mvm_mac_ctxt_add(mvm, vif);
if (ret)
goto out_unlock;
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (ret)
goto out_remove;
ret = iwl_mvm_send_bcast_sta(mvm, vif, &mvmvif->bcast_sta);
if (ret)
goto out_unbind;
mvmvif->ap_ibss_active = true;
iwl_mvm_power_update_mac(mvm, vif);
ret = iwl_mvm_update_quotas(mvm, vif);
if (ret)
goto out_quota_failed;
if (vif->p2p && mvm->p2p_device_vif)
iwl_mvm_mac_ctxt_changed(mvm, mvm->p2p_device_vif);
iwl_mvm_ref(mvm, IWL_MVM_REF_AP_IBSS);
iwl_mvm_bt_coex_vif_change(mvm);
mutex_unlock(&mvm->mutex);
return 0;
out_quota_failed:
iwl_mvm_power_update_mac(mvm, vif);
mvmvif->ap_ibss_active = false;
iwl_mvm_send_rm_bcast_sta(mvm, &mvmvif->bcast_sta);
out_unbind:
iwl_mvm_binding_remove_vif(mvm, vif);
out_remove:
iwl_mvm_mac_ctxt_remove(mvm, vif);
out_unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_stop_ap_ibss(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
iwl_mvm_prepare_mac_removal(mvm, vif);
mutex_lock(&mvm->mutex);
mvmvif->ap_ibss_active = false;
iwl_mvm_bt_coex_vif_change(mvm);
iwl_mvm_unref(mvm, IWL_MVM_REF_AP_IBSS);
if (vif->p2p && mvm->p2p_device_vif)
iwl_mvm_mac_ctxt_changed(mvm, mvm->p2p_device_vif);
iwl_mvm_update_quotas(mvm, NULL);
iwl_mvm_send_rm_bcast_sta(mvm, &mvmvif->bcast_sta);
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_power_update_mac(mvm, vif);
iwl_mvm_mac_ctxt_remove(mvm, vif);
mutex_unlock(&mvm->mutex);
}
static void
iwl_mvm_bss_info_changed_ap_ibss(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *bss_conf,
u32 changes)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (!mvmvif->ap_ibss_active)
return;
if (changes & (BSS_CHANGED_ERP_CTS_PROT | BSS_CHANGED_HT |
BSS_CHANGED_BANDWIDTH) &&
iwl_mvm_mac_ctxt_changed(mvm, vif))
IWL_ERR(mvm, "failed to update MAC %pM\n", vif->addr);
if (changes & BSS_CHANGED_BEACON &&
iwl_mvm_mac_ctxt_beacon_changed(mvm, vif))
IWL_WARN(mvm, "Failed updating beacon data\n");
}
static void iwl_mvm_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *bss_conf,
u32 changes)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
mutex_lock(&mvm->mutex);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
iwl_mvm_bss_info_changed_station(mvm, vif, bss_conf, changes);
break;
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_ADHOC:
iwl_mvm_bss_info_changed_ap_ibss(mvm, vif, bss_conf, changes);
break;
default:
WARN_ON_ONCE(1);
}
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_mac_hw_scan(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_scan_request *req)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
if (req->n_channels == 0 || req->n_channels > MAX_NUM_SCAN_CHANNELS)
return -EINVAL;
mutex_lock(&mvm->mutex);
switch (mvm->scan_status) {
case IWL_MVM_SCAN_SCHED:
ret = iwl_mvm_sched_scan_stop(mvm);
if (ret) {
ret = -EBUSY;
goto out;
}
break;
case IWL_MVM_SCAN_NONE:
break;
default:
ret = -EBUSY;
goto out;
}
iwl_mvm_ref(mvm, IWL_MVM_REF_SCAN);
ret = iwl_mvm_scan_request(mvm, vif, req);
if (ret)
iwl_mvm_unref(mvm, IWL_MVM_REF_SCAN);
out:
mutex_unlock(&mvm->mutex);
iwl_mvm_wait_for_async_handlers(mvm);
return ret;
}
static void iwl_mvm_mac_cancel_hw_scan(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
mutex_lock(&mvm->mutex);
iwl_mvm_cancel_scan(mvm);
mutex_unlock(&mvm->mutex);
}
static void
iwl_mvm_mac_allow_buffered_frames(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, u16 tids,
int num_frames,
enum ieee80211_frame_release_type reason,
bool more_data)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
iwl_mvm_sta_modify_sleep_tx_count(mvm, sta, reason, num_frames,
tids, more_data, false);
}
static void
iwl_mvm_mac_release_buffered_frames(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, u16 tids,
int num_frames,
enum ieee80211_frame_release_type reason,
bool more_data)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
iwl_mvm_sta_modify_sleep_tx_count(mvm, sta, reason, num_frames,
tids, more_data, true);
}
static void iwl_mvm_mac_sta_notify(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum sta_notify_cmd cmd,
struct ieee80211_sta *sta)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
int tid;
switch (cmd) {
case STA_NOTIFY_SLEEP:
if (atomic_read(&mvm->pending_frames[mvmsta->sta_id]) > 0)
ieee80211_sta_block_awake(hw, sta, true);
spin_lock_bh(&mvmsta->lock);
for (tid = 0; tid < IWL_MAX_TID_COUNT; tid++) {
struct iwl_mvm_tid_data *tid_data;
tid_data = &mvmsta->tid_data[tid];
if (tid_data->state != IWL_AGG_ON &&
tid_data->state != IWL_EMPTYING_HW_QUEUE_DELBA)
continue;
if (iwl_mvm_tid_queued(tid_data) == 0)
continue;
ieee80211_sta_set_buffered(sta, tid, true);
}
spin_unlock_bh(&mvmsta->lock);
break;
case STA_NOTIFY_AWAKE:
if (WARN_ON(mvmsta->sta_id == IWL_MVM_STATION_COUNT))
break;
iwl_mvm_sta_modify_ps_wake(mvm, sta);
break;
default:
break;
}
}
static void iwl_mvm_sta_pre_rcu_remove(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_sta *mvm_sta = (void *)sta->drv_priv;
mutex_lock(&mvm->mutex);
if (sta == rcu_access_pointer(mvm->fw_id_to_mac_id[mvm_sta->sta_id]))
rcu_assign_pointer(mvm->fw_id_to_mac_id[mvm_sta->sta_id],
ERR_PTR(-ENOENT));
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_mac_sta_state(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
enum ieee80211_sta_state old_state,
enum ieee80211_sta_state new_state)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
IWL_DEBUG_MAC80211(mvm, "station %pM state change %d->%d\n",
sta->addr, old_state, new_state);
if (WARN_ON_ONCE(!mvmvif->phy_ctxt))
return -EINVAL;
flush_work(&mvm->sta_drained_wk);
mutex_lock(&mvm->mutex);
if (old_state == IEEE80211_STA_NOTEXIST &&
new_state == IEEE80211_STA_NONE) {
if (vif->type == NL80211_IFTYPE_STATION &&
vif->bss_conf.beacon_int < 16) {
IWL_ERR(mvm,
"AP %pM beacon interval is %d, refusing due to firmware bug!\n",
sta->addr, vif->bss_conf.beacon_int);
ret = -EINVAL;
goto out_unlock;
}
ret = iwl_mvm_add_sta(mvm, vif, sta);
} else if (old_state == IEEE80211_STA_NONE &&
new_state == IEEE80211_STA_AUTH) {
ret = 0;
} else if (old_state == IEEE80211_STA_AUTH &&
new_state == IEEE80211_STA_ASSOC) {
ret = iwl_mvm_update_sta(mvm, vif, sta);
if (ret == 0)
iwl_mvm_rs_rate_init(mvm, sta,
mvmvif->phy_ctxt->channel->band,
true);
} else if (old_state == IEEE80211_STA_ASSOC &&
new_state == IEEE80211_STA_AUTHORIZED) {
if (vif->bss_conf.dtim_period)
WARN_ON(iwl_mvm_enable_beacon_filter(mvm, vif,
CMD_SYNC));
ret = 0;
} else if (old_state == IEEE80211_STA_AUTHORIZED &&
new_state == IEEE80211_STA_ASSOC) {
WARN_ON(iwl_mvm_disable_beacon_filter(mvm, vif, CMD_SYNC));
ret = 0;
} else if (old_state == IEEE80211_STA_ASSOC &&
new_state == IEEE80211_STA_AUTH) {
ret = 0;
} else if (old_state == IEEE80211_STA_AUTH &&
new_state == IEEE80211_STA_NONE) {
ret = 0;
} else if (old_state == IEEE80211_STA_NONE &&
new_state == IEEE80211_STA_NOTEXIST) {
ret = iwl_mvm_rm_sta(mvm, vif, sta);
} else {
ret = -EIO;
}
out_unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_mac_set_rts_threshold(struct ieee80211_hw *hw, u32 value)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
mvm->rts_threshold = value;
return 0;
}
static void iwl_mvm_sta_rc_update(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u32 changed)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
if (vif->type == NL80211_IFTYPE_STATION &&
changed & IEEE80211_RC_NSS_CHANGED)
iwl_mvm_sf_update(mvm, vif, false);
}
static int iwl_mvm_mac_conf_tx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u16 ac,
const struct ieee80211_tx_queue_params *params)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
mvmvif->queue_params[ac] = *params;
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
int ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_mac_ctxt_changed(mvm, vif);
mutex_unlock(&mvm->mutex);
return ret;
}
return 0;
}
static void iwl_mvm_mac_mgd_prepare_tx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u32 duration = min(IWL_MVM_TE_SESSION_PROTECTION_MAX_TIME_MS,
200 + vif->bss_conf.beacon_int);
u32 min_duration = min(IWL_MVM_TE_SESSION_PROTECTION_MIN_TIME_MS,
100 + vif->bss_conf.beacon_int);
if (WARN_ON_ONCE(vif->bss_conf.assoc))
return;
mutex_lock(&mvm->mutex);
iwl_mvm_protect_session(mvm, vif, duration, min_duration, 500);
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_mac_sched_scan_start(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_sched_scan_request *req,
struct ieee80211_sched_scan_ies *ies)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
if (!iwl_mvm_is_idle(mvm)) {
ret = -EBUSY;
goto out;
}
switch (mvm->scan_status) {
case IWL_MVM_SCAN_OS:
IWL_DEBUG_SCAN(mvm, "Stopping previous scan for sched_scan\n");
ret = iwl_mvm_cancel_scan(mvm);
if (ret) {
ret = -EBUSY;
goto out;
}
break;
case IWL_MVM_SCAN_NONE:
break;
default:
ret = -EBUSY;
goto out;
}
mvm->scan_status = IWL_MVM_SCAN_SCHED;
ret = iwl_mvm_config_sched_scan(mvm, vif, req, ies);
if (ret)
goto err;
ret = iwl_mvm_config_sched_scan_profiles(mvm, req);
if (ret)
goto err;
ret = iwl_mvm_sched_scan_start(mvm, req);
if (!ret)
goto out;
err:
mvm->scan_status = IWL_MVM_SCAN_NONE;
out:
mutex_unlock(&mvm->mutex);
iwl_mvm_wait_for_async_handlers(mvm);
return ret;
}
static int iwl_mvm_mac_sched_scan_stop(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_sched_scan_stop(mvm);
mutex_unlock(&mvm->mutex);
iwl_mvm_wait_for_async_handlers(mvm);
return ret;
}
static int iwl_mvm_mac_set_key(struct ieee80211_hw *hw,
enum set_key_cmd cmd,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
if (iwlwifi_mod_params.sw_crypto) {
IWL_DEBUG_MAC80211(mvm, "leave - hwcrypto disabled\n");
return -EOPNOTSUPP;
}
switch (key->cipher) {
case WLAN_CIPHER_SUITE_TKIP:
key->flags |= IEEE80211_KEY_FLAG_GENERATE_MMIC;
case WLAN_CIPHER_SUITE_CCMP:
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
WARN_ON_ONCE(!(hw->flags & IEEE80211_HW_MFP_CAPABLE));
break;
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
return 0;
default:
if (hw->n_cipher_schemes &&
hw->cipher_schemes->cipher == key->cipher)
key->flags |= IEEE80211_KEY_FLAG_PUT_IV_SPACE;
else
return -EOPNOTSUPP;
}
mutex_lock(&mvm->mutex);
switch (cmd) {
case SET_KEY:
if ((vif->type == NL80211_IFTYPE_ADHOC ||
vif->type == NL80211_IFTYPE_AP) && !sta) {
ret = 0;
key->hw_key_idx = STA_KEY_IDX_INVALID;
break;
}
IWL_DEBUG_MAC80211(mvm, "set hwcrypto key\n");
ret = iwl_mvm_set_sta_key(mvm, vif, sta, key, false);
if (ret) {
IWL_WARN(mvm, "set key failed\n");
key->hw_key_idx = STA_KEY_IDX_INVALID;
ret = 0;
}
break;
case DISABLE_KEY:
if (key->hw_key_idx == STA_KEY_IDX_INVALID) {
ret = 0;
break;
}
IWL_DEBUG_MAC80211(mvm, "disable hwcrypto key\n");
ret = iwl_mvm_remove_sta_key(mvm, vif, sta, key);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_mac_update_tkip_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_key_conf *keyconf,
struct ieee80211_sta *sta,
u32 iv32, u16 *phase1key)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
if (keyconf->hw_key_idx == STA_KEY_IDX_INVALID)
return;
iwl_mvm_update_tkip_key(mvm, vif, keyconf, sta, iv32, phase1key);
}
static int iwl_mvm_roc(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_channel *channel,
int duration,
enum ieee80211_roc_type type)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct cfg80211_chan_def chandef;
struct iwl_mvm_phy_ctxt *phy_ctxt;
int ret, i;
IWL_DEBUG_MAC80211(mvm, "enter (%d, %d, %d)\n", channel->hw_value,
duration, type);
if (vif->type != NL80211_IFTYPE_P2P_DEVICE) {
IWL_ERR(mvm, "vif isn't a P2P_DEVICE: %d\n", vif->type);
return -EINVAL;
}
mutex_lock(&mvm->mutex);
for (i = 0; i < NUM_PHY_CTX; i++) {
phy_ctxt = &mvm->phy_ctxts[i];
if (phy_ctxt->ref == 0 || mvmvif->phy_ctxt == phy_ctxt)
continue;
if (phy_ctxt->ref && channel == phy_ctxt->channel) {
ret = iwl_mvm_binding_remove_vif(mvm, vif);
if (WARN(ret, "Failed unbinding P2P_DEVICE\n"))
goto out_unlock;
iwl_mvm_phy_ctxt_unref(mvm, mvmvif->phy_ctxt);
mvmvif->phy_ctxt = phy_ctxt;
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (WARN(ret, "Failed binding P2P_DEVICE\n"))
goto out_unlock;
iwl_mvm_phy_ctxt_ref(mvm, mvmvif->phy_ctxt);
goto schedule_time_event;
}
}
if (channel == mvmvif->phy_ctxt->channel)
goto schedule_time_event;
cfg80211_chandef_create(&chandef, channel, NL80211_CHAN_NO_HT);
if (mvmvif->phy_ctxt->ref == 1) {
ret = iwl_mvm_phy_ctxt_changed(mvm, mvmvif->phy_ctxt,
&chandef, 1, 1);
if (ret)
goto out_unlock;
} else {
phy_ctxt = iwl_mvm_get_free_phy_ctxt(mvm);
if (!phy_ctxt) {
ret = -ENOSPC;
goto out_unlock;
}
ret = iwl_mvm_phy_ctxt_changed(mvm, phy_ctxt, &chandef,
1, 1);
if (ret) {
IWL_ERR(mvm, "Failed to change PHY context\n");
goto out_unlock;
}
ret = iwl_mvm_binding_remove_vif(mvm, vif);
if (WARN(ret, "Failed unbinding P2P_DEVICE\n"))
goto out_unlock;
iwl_mvm_phy_ctxt_unref(mvm, mvmvif->phy_ctxt);
mvmvif->phy_ctxt = phy_ctxt;
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (WARN(ret, "Failed binding P2P_DEVICE\n"))
goto out_unlock;
iwl_mvm_phy_ctxt_ref(mvm, mvmvif->phy_ctxt);
}
schedule_time_event:
ret = iwl_mvm_start_p2p_roc(mvm, vif, duration, type);
out_unlock:
mutex_unlock(&mvm->mutex);
IWL_DEBUG_MAC80211(mvm, "leave\n");
return ret;
}
static int iwl_mvm_cancel_roc(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
IWL_DEBUG_MAC80211(mvm, "enter\n");
mutex_lock(&mvm->mutex);
iwl_mvm_stop_p2p_roc(mvm);
mutex_unlock(&mvm->mutex);
IWL_DEBUG_MAC80211(mvm, "leave\n");
return 0;
}
static int iwl_mvm_add_chanctx(struct ieee80211_hw *hw,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt;
int ret;
IWL_DEBUG_MAC80211(mvm, "Add channel context\n");
mutex_lock(&mvm->mutex);
phy_ctxt = iwl_mvm_get_free_phy_ctxt(mvm);
if (!phy_ctxt) {
ret = -ENOSPC;
goto out;
}
ret = iwl_mvm_phy_ctxt_changed(mvm, phy_ctxt, &ctx->min_def,
ctx->rx_chains_static,
ctx->rx_chains_dynamic);
if (ret) {
IWL_ERR(mvm, "Failed to add PHY context\n");
goto out;
}
iwl_mvm_phy_ctxt_ref(mvm, phy_ctxt);
*phy_ctxt_id = phy_ctxt->id;
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_remove_chanctx(struct ieee80211_hw *hw,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt = &mvm->phy_ctxts[*phy_ctxt_id];
mutex_lock(&mvm->mutex);
iwl_mvm_phy_ctxt_unref(mvm, phy_ctxt);
mutex_unlock(&mvm->mutex);
}
static void iwl_mvm_change_chanctx(struct ieee80211_hw *hw,
struct ieee80211_chanctx_conf *ctx,
u32 changed)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt = &mvm->phy_ctxts[*phy_ctxt_id];
if (WARN_ONCE((phy_ctxt->ref > 1) &&
(changed & ~(IEEE80211_CHANCTX_CHANGE_WIDTH |
IEEE80211_CHANCTX_CHANGE_RX_CHAINS |
IEEE80211_CHANCTX_CHANGE_RADAR |
IEEE80211_CHANCTX_CHANGE_MIN_WIDTH)),
"Cannot change PHY. Ref=%d, changed=0x%X\n",
phy_ctxt->ref, changed))
return;
mutex_lock(&mvm->mutex);
iwl_mvm_phy_ctxt_changed(mvm, phy_ctxt, &ctx->min_def,
ctx->rx_chains_static,
ctx->rx_chains_dynamic);
iwl_mvm_bt_coex_vif_change(mvm);
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_assign_vif_chanctx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt = &mvm->phy_ctxts[*phy_ctxt_id];
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
mutex_lock(&mvm->mutex);
mvmvif->phy_ctxt = phy_ctxt;
switch (vif->type) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_ADHOC:
ret = 0;
goto out_unlock;
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_MONITOR:
break;
default:
ret = -EINVAL;
goto out_unlock;
}
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (ret)
goto out_unlock;
iwl_mvm_power_update_mac(mvm, vif);
if (vif->type == NL80211_IFTYPE_MONITOR) {
mvmvif->monitor_active = true;
ret = iwl_mvm_update_quotas(mvm, vif);
if (ret)
goto out_remove_binding;
}
goto out_unlock;
out_remove_binding:
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_power_update_mac(mvm, vif);
out_unlock:
mutex_unlock(&mvm->mutex);
if (ret)
mvmvif->phy_ctxt = NULL;
return ret;
}
static void iwl_mvm_unassign_vif_chanctx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
mutex_lock(&mvm->mutex);
iwl_mvm_remove_time_event(mvm, mvmvif, &mvmvif->time_event_data);
switch (vif->type) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_ADHOC:
goto out_unlock;
case NL80211_IFTYPE_MONITOR:
mvmvif->monitor_active = false;
iwl_mvm_update_quotas(mvm, NULL);
break;
default:
break;
}
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_power_update_mac(mvm, vif);
out_unlock:
mvmvif->phy_ctxt = NULL;
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_set_tim(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
bool set)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_sta *mvm_sta = (void *)sta->drv_priv;
if (!mvm_sta || !mvm_sta->vif) {
IWL_ERR(mvm, "Station is not associated to a vif\n");
return -EINVAL;
}
return iwl_mvm_mac_ctxt_beacon_changed(mvm, mvm_sta->vif);
}
static int __iwl_mvm_mac_testmode_cmd(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
void *data, int len)
{
struct nlattr *tb[IWL_MVM_TM_ATTR_MAX + 1];
int err;
u32 noa_duration;
err = nla_parse(tb, IWL_MVM_TM_ATTR_MAX, data, len, iwl_mvm_tm_policy);
if (err)
return err;
if (!tb[IWL_MVM_TM_ATTR_CMD])
return -EINVAL;
switch (nla_get_u32(tb[IWL_MVM_TM_ATTR_CMD])) {
case IWL_MVM_TM_CMD_SET_NOA:
if (!vif || vif->type != NL80211_IFTYPE_AP || !vif->p2p ||
!vif->bss_conf.enable_beacon ||
!tb[IWL_MVM_TM_ATTR_NOA_DURATION])
return -EINVAL;
noa_duration = nla_get_u32(tb[IWL_MVM_TM_ATTR_NOA_DURATION]);
if (noa_duration >= vif->bss_conf.beacon_int)
return -EINVAL;
mvm->noa_duration = noa_duration;
mvm->noa_vif = vif;
return iwl_mvm_update_quotas(mvm, NULL);
case IWL_MVM_TM_CMD_SET_BEACON_FILTER:
if (!vif || vif->type != NL80211_IFTYPE_STATION ||
!vif->bss_conf.assoc || !vif->bss_conf.dtim_period ||
!tb[IWL_MVM_TM_ATTR_BEACON_FILTER_STATE])
return -EINVAL;
if (nla_get_u32(tb[IWL_MVM_TM_ATTR_BEACON_FILTER_STATE]))
return iwl_mvm_enable_beacon_filter(mvm, vif,
CMD_SYNC);
return iwl_mvm_disable_beacon_filter(mvm, vif, CMD_SYNC);
}
return -EOPNOTSUPP;
}
static int iwl_mvm_mac_testmode_cmd(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
void *data, int len)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int err;
mutex_lock(&mvm->mutex);
err = __iwl_mvm_mac_testmode_cmd(mvm, vif, data, len);
mutex_unlock(&mvm->mutex);
return err;
}
