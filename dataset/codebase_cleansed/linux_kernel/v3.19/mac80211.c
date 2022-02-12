void iwl_mvm_ref(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref_type)
{
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
IWL_DEBUG_RPM(mvm, "Take mvm reference - type %d\n", ref_type);
spin_lock_bh(&mvm->refs_lock);
mvm->refs[ref_type]++;
spin_unlock_bh(&mvm->refs_lock);
iwl_trans_ref(mvm->trans);
}
void iwl_mvm_unref(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref_type)
{
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
IWL_DEBUG_RPM(mvm, "Leave mvm reference - type %d\n", ref_type);
spin_lock_bh(&mvm->refs_lock);
WARN_ON(!mvm->refs[ref_type]--);
spin_unlock_bh(&mvm->refs_lock);
iwl_trans_unref(mvm->trans);
}
static void iwl_mvm_unref_all_except(struct iwl_mvm *mvm,
enum iwl_mvm_ref_type except_ref)
{
int i, j;
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
spin_lock_bh(&mvm->refs_lock);
for (i = 0; i < IWL_MVM_REF_COUNT; i++) {
if (except_ref == i || !mvm->refs[i])
continue;
IWL_DEBUG_RPM(mvm, "Cleanup: remove mvm ref type %d (%d)\n",
i, mvm->refs[i]);
for (j = 0; j < mvm->refs[i]; j++)
iwl_trans_unref(mvm->trans);
mvm->refs[i] = 0;
}
spin_unlock_bh(&mvm->refs_lock);
}
bool iwl_mvm_ref_taken(struct iwl_mvm *mvm)
{
int i;
bool taken = false;
if (!iwl_mvm_is_d0i3_supported(mvm))
return true;
spin_lock_bh(&mvm->refs_lock);
for (i = 0; i < IWL_MVM_REF_COUNT; i++) {
if (mvm->refs[i]) {
taken = true;
break;
}
}
spin_unlock_bh(&mvm->refs_lock);
return taken;
}
int iwl_mvm_ref_sync(struct iwl_mvm *mvm, enum iwl_mvm_ref_type ref_type)
{
iwl_mvm_ref(mvm, ref_type);
if (!wait_event_timeout(mvm->d0i3_exit_waitq,
!test_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status),
HZ)) {
WARN_ON_ONCE(1);
iwl_mvm_unref(mvm, ref_type);
return -EIO;
}
return 0;
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
IEEE80211_HW_CHANCTX_STA_CSA |
IEEE80211_HW_SUPPORTS_CLONED_SKBS;
hw->queues = mvm->first_agg_queue;
hw->offchannel_tx_hw_queue = IWL_MVM_OFFCHANNEL_QUEUE;
hw->radiotap_mcs_details |= IEEE80211_RADIOTAP_MCS_HAVE_FEC |
IEEE80211_RADIOTAP_MCS_HAVE_STBC;
hw->radiotap_vht_details |= IEEE80211_RADIOTAP_VHT_KNOWN_STBC |
IEEE80211_RADIOTAP_VHT_KNOWN_BEAMFORMED;
hw->rate_control_algorithm = "iwl-mvm-rs";
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_MFP &&
!iwlwifi_mod_params.sw_crypto)
hw->flags |= IEEE80211_HW_MFP_CAPABLE;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_UAPSD_SUPPORT &&
!iwlwifi_mod_params.uapsd_disable) {
hw->flags |= IEEE80211_HW_SUPPORTS_UAPSD;
hw->uapsd_queues = IWL_MVM_UAPSD_QUEUES;
hw->uapsd_max_sp_len = IWL_UAPSD_MAX_SP;
}
if (mvm->fw->ucode_capa.api[0] & IWL_UCODE_TLV_API_LMAC_SCAN ||
mvm->fw->ucode_capa.capa[0] & IWL_UCODE_TLV_CAPA_UMAC_SCAN) {
hw->flags |= IEEE80211_SINGLE_HW_SCAN_ON_ALL_BANDS;
hw->wiphy->features |=
NL80211_FEATURE_SCHED_SCAN_RANDOM_MAC_ADDR |
NL80211_FEATURE_SCAN_RANDOM_MAC_ADDR;
}
hw->sta_data_size = sizeof(struct iwl_mvm_sta);
hw->vif_data_size = sizeof(struct iwl_mvm_vif);
hw->chanctx_data_size = sizeof(u16);
hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_P2P_GO) |
BIT(NL80211_IFTYPE_P2P_DEVICE) |
BIT(NL80211_IFTYPE_ADHOC);
hw->wiphy->flags |= WIPHY_FLAG_IBSS_RSN;
hw->wiphy->regulatory_flags |= REGULATORY_CUSTOM_REG |
REGULATORY_DISABLE_BEACON_HINTS;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_GO_UAPSD)
hw->wiphy->flags |= WIPHY_FLAG_AP_UAPSD;
hw->wiphy->flags |= WIPHY_FLAG_HAS_CHANNEL_SWITCH;
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
hw->wiphy->max_scan_ie_len = iwl_mvm_max_scan_ie_len(mvm, false);
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
if (IWL_UCODE_API(mvm->fw->ucode_ver) >= 10) {
hw->wiphy->flags |= WIPHY_FLAG_SUPPORTS_SCHED_SCAN;
hw->wiphy->max_sched_scan_ssids = PROBE_OPTION_MAX;
hw->wiphy->max_match_sets = IWL_SCAN_MAX_PROFILES;
hw->wiphy->max_sched_scan_ie_len =
SCAN_OFFLOAD_PROBE_REQ_SIZE - 24 - 2;
}
hw->wiphy->features |= NL80211_FEATURE_P2P_GO_CTWIN |
NL80211_FEATURE_LOW_PRIORITY_SCAN |
NL80211_FEATURE_P2P_GO_OPPPS |
NL80211_FEATURE_DYNAMIC_SMPS |
NL80211_FEATURE_STATIC_SMPS |
NL80211_FEATURE_SUPPORTS_WMM_ADMISSION;
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_TXPOWER_INSERTION_SUPPORT)
hw->wiphy->features |= NL80211_FEATURE_TX_POWER_INSERTION;
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_QUIET_PERIOD_SUPPORT)
hw->wiphy->features |= NL80211_FEATURE_QUIET;
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_DS_PARAM_SET_IE_SUPPORT)
hw->wiphy->features |=
NL80211_FEATURE_DS_PARAM_SET_IE_IN_PROBES;
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_WFA_TPC_REP_IE_SUPPORT)
hw->wiphy->features |= NL80211_FEATURE_WFA_TPC_IE_IN_PROBES;
mvm->rts_threshold = IEEE80211_MAX_RTS_THRESHOLD;
if (mvm->fw->cs[0].cipher) {
mvm->hw->n_cipher_schemes = 1;
mvm->hw->cipher_schemes = &mvm->fw->cs[0];
}
#ifdef CONFIG_PM_SLEEP
if (iwl_mvm_is_d0i3_supported(mvm) &&
device_can_wakeup(mvm->trans->dev)) {
mvm->wowlan.flags = WIPHY_WOWLAN_ANY;
hw->wiphy->wowlan = &mvm->wowlan;
} else if (mvm->fw->img[IWL_UCODE_WOWLAN].sec[0].len &&
mvm->trans->ops->d3_suspend &&
mvm->trans->ops->d3_resume &&
device_can_wakeup(mvm->trans->dev)) {
mvm->wowlan.flags = WIPHY_WOWLAN_MAGIC_PKT |
WIPHY_WOWLAN_DISCONNECT |
WIPHY_WOWLAN_EAP_IDENTITY_REQ |
WIPHY_WOWLAN_RFKILL_RELEASE |
WIPHY_WOWLAN_NET_DETECT;
if (!iwlwifi_mod_params.sw_crypto)
mvm->wowlan.flags |= WIPHY_WOWLAN_SUPPORTS_GTK_REKEY |
WIPHY_WOWLAN_GTK_REKEY_FAILURE |
WIPHY_WOWLAN_4WAY_HANDSHAKE;
mvm->wowlan.n_patterns = IWL_WOWLAN_MAX_PATTERNS;
mvm->wowlan.pattern_min_len = IWL_WOWLAN_MIN_PATTERN_LEN;
mvm->wowlan.pattern_max_len = IWL_WOWLAN_MAX_PATTERN_LEN;
mvm->wowlan.max_nd_match_sets = IWL_SCAN_MAX_PROFILES;
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
if (mvm->fw->ucode_capa.capa[0] & IWL_UCODE_TLV_CAPA_TDLS_SUPPORT) {
IWL_DEBUG_TDLS(mvm, "TDLS supported\n");
hw->wiphy->flags |= WIPHY_FLAG_SUPPORTS_TDLS;
}
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_TDLS_CHANNEL_SWITCH) {
IWL_DEBUG_TDLS(mvm, "TDLS channel switch supported\n");
hw->wiphy->features |= NL80211_FEATURE_TDLS_CHANNEL_SWITCH;
}
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
!test_bit(IWL_MVM_STATUS_ROC_RUNNING, &mvm->status) &&
!test_bit(IWL_MVM_STATUS_ROC_AUX_RUNNING, &mvm->status))
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
switch (action) {
case IEEE80211_AMPDU_TX_START:
case IEEE80211_AMPDU_TX_STOP_CONT:
case IEEE80211_AMPDU_TX_STOP_FLUSH:
case IEEE80211_AMPDU_TX_STOP_FLUSH_CONT:
case IEEE80211_AMPDU_TX_OPERATIONAL:
ret = iwl_mvm_ref_sync(mvm, IWL_MVM_REF_TX_AGG);
if (ret)
return ret;
tx_agg_ref = true;
break;
default:
break;
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
memset(&mvmvif->bf_data, 0, sizeof(mvmvif->bf_data));
}
static ssize_t iwl_mvm_read_coredump(char *buffer, loff_t offset, size_t count,
const void *data, size_t datalen)
{
const struct iwl_mvm_dump_ptrs *dump_ptrs = data;
ssize_t bytes_read;
ssize_t bytes_read_trans;
if (offset < dump_ptrs->op_mode_len) {
bytes_read = min_t(ssize_t, count,
dump_ptrs->op_mode_len - offset);
memcpy(buffer, (u8 *)dump_ptrs->op_mode_ptr + offset,
bytes_read);
offset += bytes_read;
count -= bytes_read;
if (count == 0)
return bytes_read;
} else {
bytes_read = 0;
}
if (!dump_ptrs->trans_ptr)
return bytes_read;
offset -= dump_ptrs->op_mode_len;
bytes_read_trans = min_t(ssize_t, count,
dump_ptrs->trans_ptr->len - offset);
memcpy(buffer + bytes_read,
(u8 *)dump_ptrs->trans_ptr->data + offset,
bytes_read_trans);
return bytes_read + bytes_read_trans;
}
static void iwl_mvm_free_coredump(const void *data)
{
const struct iwl_mvm_dump_ptrs *fw_error_dump = data;
vfree(fw_error_dump->op_mode_ptr);
vfree(fw_error_dump->trans_ptr);
kfree(fw_error_dump);
}
void iwl_mvm_fw_error_dump(struct iwl_mvm *mvm)
{
struct iwl_fw_error_dump_file *dump_file;
struct iwl_fw_error_dump_data *dump_data;
struct iwl_fw_error_dump_info *dump_info;
struct iwl_mvm_dump_ptrs *fw_error_dump;
const struct fw_img *img;
u32 sram_len, sram_ofs;
u32 file_len, rxf_len;
unsigned long flags;
int reg_val;
lockdep_assert_held(&mvm->mutex);
fw_error_dump = kzalloc(sizeof(*fw_error_dump), GFP_KERNEL);
if (!fw_error_dump)
return;
img = &mvm->fw->img[mvm->cur_ucode];
sram_ofs = img->sec[IWL_UCODE_SECTION_DATA].offset;
sram_len = img->sec[IWL_UCODE_SECTION_DATA].len;
reg_val = iwl_trans_read_prph(mvm->trans, RXF_SIZE_ADDR);
rxf_len = (reg_val & RXF_SIZE_BYTE_CNT_MSK) >> RXF_SIZE_BYTE_CND_POS;
rxf_len = rxf_len << 7;
file_len = sizeof(*dump_file) +
sizeof(*dump_data) * 3 +
sram_len +
rxf_len +
sizeof(*dump_info);
dump_file = vzalloc(file_len);
if (!dump_file) {
kfree(fw_error_dump);
return;
}
fw_error_dump->op_mode_ptr = dump_file;
dump_file->barker = cpu_to_le32(IWL_FW_ERROR_DUMP_BARKER);
dump_data = (void *)dump_file->data;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_DEV_FW_INFO);
dump_data->len = cpu_to_le32(sizeof(*dump_info));
dump_info = (void *) dump_data->data;
dump_info->device_family =
mvm->cfg->device_family == IWL_DEVICE_FAMILY_7000 ?
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_7) :
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_8);
memcpy(dump_info->fw_human_readable, mvm->fw->human_readable,
sizeof(dump_info->fw_human_readable));
strncpy(dump_info->dev_human_readable, mvm->cfg->name,
sizeof(dump_info->dev_human_readable));
strncpy(dump_info->bus_human_readable, mvm->dev->bus->name,
sizeof(dump_info->bus_human_readable));
dump_data = iwl_fw_error_next_data(dump_data);
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_RXF);
dump_data->len = cpu_to_le32(rxf_len);
if (iwl_trans_grab_nic_access(mvm->trans, false, &flags)) {
u32 *rxf = (void *)dump_data->data;
int i;
for (i = 0; i < (rxf_len / sizeof(u32)); i++) {
iwl_trans_write_prph(mvm->trans,
RXF_LD_FENCE_OFFSET_ADDR,
i * sizeof(u32));
rxf[i] = iwl_trans_read_prph(mvm->trans,
RXF_FIFO_RD_FENCE_ADDR);
}
iwl_trans_release_nic_access(mvm->trans, &flags);
}
dump_data = iwl_fw_error_next_data(dump_data);
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_SRAM);
dump_data->len = cpu_to_le32(sram_len);
iwl_trans_read_mem_bytes(mvm->trans, sram_ofs, dump_data->data,
sram_len);
fw_error_dump->trans_ptr = iwl_trans_dump_data(mvm->trans);
fw_error_dump->op_mode_len = file_len;
if (fw_error_dump->trans_ptr)
file_len += fw_error_dump->trans_ptr->len;
dump_file->file_len = cpu_to_le32(file_len);
dev_coredumpm(mvm->trans->dev, THIS_MODULE, fw_error_dump, 0,
GFP_KERNEL, iwl_mvm_read_coredump, iwl_mvm_free_coredump);
}
static void iwl_mvm_restart_cleanup(struct iwl_mvm *mvm)
{
if (!test_and_clear_bit(IWL_MVM_STATUS_D3_RECONFIG, &mvm->status))
iwl_mvm_fw_error_dump(mvm);
iwl_trans_stop_device(mvm->trans);
mvm->scan_status = IWL_MVM_SCAN_NONE;
mvm->ps_disabled = false;
mvm->calibrating = false;
ieee80211_remain_on_channel_expired(mvm->hw);
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_RESUME_ALL,
iwl_mvm_cleanup_iterator, mvm);
mvm->p2p_device_vif = NULL;
mvm->d0i3_ap_sta_id = IWL_MVM_STATION_COUNT;
iwl_mvm_reset_phy_ctxts(mvm);
memset(mvm->fw_key_table, 0, sizeof(mvm->fw_key_table));
memset(mvm->sta_drained, 0, sizeof(mvm->sta_drained));
memset(mvm->tfd_drained, 0, sizeof(mvm->tfd_drained));
memset(&mvm->last_bt_notif, 0, sizeof(mvm->last_bt_notif));
memset(&mvm->last_bt_notif_old, 0, sizeof(mvm->last_bt_notif_old));
memset(&mvm->last_bt_ci_cmd, 0, sizeof(mvm->last_bt_ci_cmd));
memset(&mvm->last_bt_ci_cmd_old, 0, sizeof(mvm->last_bt_ci_cmd_old));
memset(&mvm->bt_ack_kill_msk, 0, sizeof(mvm->bt_ack_kill_msk));
memset(&mvm->bt_cts_kill_msk, 0, sizeof(mvm->bt_cts_kill_msk));
ieee80211_wake_queues(mvm->hw);
iwl_mvm_unref_all_except(mvm, IWL_MVM_REF_UCODE_DOWN);
clear_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status);
mvm->vif_count = 0;
mvm->rx_ba_sessions = 0;
}
int __iwl_mvm_mac_start(struct iwl_mvm *mvm)
{
int ret;
lockdep_assert_held(&mvm->mutex);
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status))
iwl_mvm_restart_cleanup(mvm);
ret = iwl_mvm_up(mvm);
if (ret && test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status)) {
clear_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
iwl_mvm_d0i3_enable_tx(mvm, NULL);
}
return ret;
}
static int iwl_mvm_mac_start(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
ret = __iwl_mvm_mac_start(mvm);
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_restart_complete(struct iwl_mvm *mvm)
{
int ret;
mutex_lock(&mvm->mutex);
clear_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
iwl_mvm_d0i3_enable_tx(mvm, NULL);
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret)
IWL_ERR(mvm, "Failed to update quotas after restart (%d)\n",
ret);
iwl_mvm_unref(mvm, IWL_MVM_REF_UCODE_DOWN);
iwl_mvm_teardown_tdls_peers(mvm);
mutex_unlock(&mvm->mutex);
}
static void iwl_mvm_resume_complete(struct iwl_mvm *mvm)
{
bool exit_now;
if (!iwl_mvm_is_d0i3_supported(mvm))
return;
mutex_lock(&mvm->d0i3_suspend_mutex);
__clear_bit(D0I3_DEFER_WAKEUP, &mvm->d0i3_suspend_flags);
exit_now = __test_and_clear_bit(D0I3_PENDING_WAKEUP,
&mvm->d0i3_suspend_flags);
mutex_unlock(&mvm->d0i3_suspend_mutex);
if (exit_now) {
IWL_DEBUG_RPM(mvm, "Run deferred d0i3 exit\n");
_iwl_mvm_exit_d0i3(mvm);
}
}
static void
iwl_mvm_mac_reconfig_complete(struct ieee80211_hw *hw,
enum ieee80211_reconfig_type reconfig_type)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
switch (reconfig_type) {
case IEEE80211_RECONFIG_TYPE_RESTART:
iwl_mvm_restart_complete(mvm);
break;
case IEEE80211_RECONFIG_TYPE_SUSPEND:
iwl_mvm_resume_complete(mvm);
break;
}
}
void __iwl_mvm_mac_stop(struct iwl_mvm *mvm)
{
lockdep_assert_held(&mvm->mutex);
if (!test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status))
iwl_mvm_ref(mvm, IWL_MVM_REF_UCODE_DOWN);
cancel_work_sync(&mvm->roc_done_wk);
iwl_trans_stop_device(mvm->trans);
iwl_mvm_async_handlers_purge(mvm);
iwl_mvm_del_aux_sta(mvm);
clear_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
mvm->ucode_loaded = false;
}
static void iwl_mvm_mac_stop(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
flush_work(&mvm->d0i3_exit_work);
flush_work(&mvm->async_handlers_wk);
flush_work(&mvm->fw_error_dump_wk);
mutex_lock(&mvm->mutex);
__iwl_mvm_mac_stop(mvm);
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
return iwl_mvm_send_cmd_pdu(mvm, REDUCE_TX_POWER_CMD, 0,
sizeof(reduce_txpwr_cmd),
&reduce_txpwr_cmd);
}
static int iwl_mvm_mac_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
ret = iwl_mvm_ref_sync(mvm, IWL_MVM_REF_ADD_IF);
if (ret)
return ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_mac_ctxt_init(mvm, vif);
if (ret)
goto out_unlock;
if (vif->type != NL80211_IFTYPE_P2P_DEVICE)
mvm->vif_count++;
if (vif->type == NL80211_IFTYPE_AP ||
vif->type == NL80211_IFTYPE_ADHOC) {
ret = iwl_mvm_alloc_bcast_sta(mvm, vif);
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
ret = iwl_mvm_power_update_mac(mvm);
if (ret)
goto out_release;
ret = iwl_mvm_disable_beacon_filter(mvm, vif, 0);
if (ret)
goto out_remove_mac;
if (!mvm->bf_allowed_vif &&
vif->type == NL80211_IFTYPE_STATION && !vif->p2p) {
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
ret = iwl_mvm_add_bcast_sta(mvm, vif);
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
iwl_mvm_unref(mvm, IWL_MVM_REF_ADD_IF);
return ret;
}
static void iwl_mvm_prepare_mac_removal(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
u32 tfd_msk = iwl_mvm_mac_get_queues_mask(vif);
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
iwl_mvm_dealloc_bcast_sta(mvm, vif);
goto out_release;
}
if (vif->type == NL80211_IFTYPE_P2P_DEVICE) {
mvm->p2p_device_vif = NULL;
iwl_mvm_rm_bcast_sta(mvm, vif);
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_phy_ctxt_unref(mvm, mvmvif->phy_ctxt);
mvmvif->phy_ctxt = NULL;
}
if (mvm->vif_count && vif->type != NL80211_IFTYPE_P2P_DEVICE)
mvm->vif_count--;
iwl_mvm_power_update_mac(mvm);
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
int addr_count;
bool pass_all;
int len;
addr_count = netdev_hw_addr_list_count(mc_list);
pass_all = addr_count > MAX_MCAST_FILTERING_ADDRESSES ||
IWL_MVM_FW_MCAST_FILTER_PASS_ALL;
if (pass_all)
addr_count = 0;
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
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p ||
!vif->bss_conf.assoc)
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
if (IWL_MVM_FW_BCAST_FILTER_PASS_ALL)
return false;
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
return iwl_mvm_send_cmd_pdu(mvm, BCAST_FILTER_CMD, 0,
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
if (changes & BSS_CHANGED_BSSID && !mvmvif->associated)
memcpy(mvmvif->bssid, bss_conf->bssid, ETH_ALEN);
ret = iwl_mvm_mac_ctxt_changed(mvm, vif, false, mvmvif->bssid);
if (ret)
IWL_ERR(mvm, "failed to update MAC %pM\n", vif->addr);
memcpy(mvmvif->bssid, bss_conf->bssid, ETH_ALEN);
mvmvif->associated = bss_conf->assoc;
if (changes & BSS_CHANGED_ASSOC) {
if (bss_conf->assoc) {
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret) {
IWL_ERR(mvm, "failed to update quotas\n");
return;
}
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART,
&mvm->status)) {
u32 dur = (11 * vif->bss_conf.beacon_int) / 10;
iwl_mvm_protect_session(mvm, vif, dur, dur,
5 * dur, false);
}
iwl_mvm_sf_update(mvm, vif, false);
iwl_mvm_power_vif_assoc(mvm, vif);
if (vif->p2p) {
iwl_mvm_ref(mvm, IWL_MVM_REF_P2P_CLIENT);
iwl_mvm_update_smps(mvm, vif,
IWL_MVM_SMPS_REQ_PROT,
IEEE80211_SMPS_DYNAMIC);
}
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
ret = iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL);
if (ret)
IWL_ERR(mvm,
"failed to update MAC %pM (clear after unassoc)\n",
vif->addr);
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
}
if (changes & BSS_CHANGED_BEACON_INFO) {
iwl_mvm_sf_update(mvm, vif, false);
WARN_ON(iwl_mvm_enable_beacon_filter(mvm, vif, 0));
}
if (changes & (BSS_CHANGED_PS | BSS_CHANGED_P2P_PS | BSS_CHANGED_QOS)) {
ret = iwl_mvm_power_update_mac(mvm);
if (ret)
IWL_ERR(mvm, "failed to update power mode\n");
}
if (changes & BSS_CHANGED_TXPOWER) {
IWL_DEBUG_CALIB(mvm, "Changing TX Power to %d\n",
bss_conf->txpower);
iwl_mvm_set_tx_power(mvm, vif, bss_conf->txpower);
}
if (changes & BSS_CHANGED_CQM) {
IWL_DEBUG_MAC80211(mvm, "cqm info_changed\n");
mvmvif->bf_data.last_cqm_event = 0;
if (mvmvif->bf_data.bf_enabled) {
ret = iwl_mvm_enable_beacon_filter(mvm, vif, 0);
if (ret)
IWL_ERR(mvm,
"failed to update CQM thresholds\n");
}
}
if (changes & BSS_CHANGED_ARP_FILTER) {
IWL_DEBUG_MAC80211(mvm, "arp filter changed\n");
iwl_mvm_configure_bcast_filter(mvm, vif);
}
}
static int iwl_mvm_start_ap_ibss(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
ret = iwl_mvm_ref_sync(mvm, IWL_MVM_REF_START_AP);
if (ret)
return ret;
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
ret = iwl_mvm_send_add_bcast_sta(mvm, vif);
if (ret)
goto out_unbind;
mvmvif->ap_ibss_active = true;
iwl_mvm_power_update_mac(mvm);
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret)
goto out_quota_failed;
if (vif->p2p && mvm->p2p_device_vif)
iwl_mvm_mac_ctxt_changed(mvm, mvm->p2p_device_vif, false, NULL);
iwl_mvm_ref(mvm, IWL_MVM_REF_AP_IBSS);
iwl_mvm_bt_coex_vif_change(mvm);
if (iwl_mvm_phy_ctx_count(mvm) > 1)
iwl_mvm_teardown_tdls_peers(mvm);
mutex_unlock(&mvm->mutex);
return 0;
out_quota_failed:
iwl_mvm_power_update_mac(mvm);
mvmvif->ap_ibss_active = false;
iwl_mvm_send_rm_bcast_sta(mvm, vif);
out_unbind:
iwl_mvm_binding_remove_vif(mvm, vif);
out_remove:
iwl_mvm_mac_ctxt_remove(mvm, vif);
out_unlock:
mutex_unlock(&mvm->mutex);
iwl_mvm_unref(mvm, IWL_MVM_REF_START_AP);
return ret;
}
static void iwl_mvm_stop_ap_ibss(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
iwl_mvm_prepare_mac_removal(mvm, vif);
mutex_lock(&mvm->mutex);
if (rcu_access_pointer(mvm->csa_vif) == vif) {
iwl_mvm_remove_time_event(mvm, mvmvif,
&mvmvif->time_event_data);
RCU_INIT_POINTER(mvm->csa_vif, NULL);
}
if (rcu_access_pointer(mvm->csa_tx_blocked_vif) == vif) {
RCU_INIT_POINTER(mvm->csa_tx_blocked_vif, NULL);
mvm->csa_tx_block_bcn_timeout = 0;
}
mvmvif->ap_ibss_active = false;
mvm->ap_last_beacon_gp2 = 0;
iwl_mvm_bt_coex_vif_change(mvm);
iwl_mvm_unref(mvm, IWL_MVM_REF_AP_IBSS);
if (vif->p2p && mvm->p2p_device_vif)
iwl_mvm_mac_ctxt_changed(mvm, mvm->p2p_device_vif, false, NULL);
iwl_mvm_update_quotas(mvm, NULL);
iwl_mvm_send_rm_bcast_sta(mvm, vif);
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_power_update_mac(mvm);
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
BSS_CHANGED_BANDWIDTH | BSS_CHANGED_QOS) &&
iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL))
IWL_ERR(mvm, "failed to update MAC %pM\n", vif->addr);
if (changes & BSS_CHANGED_BEACON &&
iwl_mvm_mac_ctxt_beacon_changed(mvm, vif))
IWL_WARN(mvm, "Failed updating beacon data\n");
if (changes & BSS_CHANGED_TXPOWER) {
IWL_DEBUG_CALIB(mvm, "Changing TX Power to %d\n",
bss_conf->txpower);
iwl_mvm_set_tx_power(mvm, vif, bss_conf->txpower);
}
}
static void iwl_mvm_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *bss_conf,
u32 changes)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
if (iwl_mvm_ref_sync(mvm, IWL_MVM_REF_BSS_CHANGED))
return;
mutex_lock(&mvm->mutex);
if (changes & BSS_CHANGED_IDLE && !bss_conf->idle)
iwl_mvm_scan_offload_stop(mvm, true);
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
iwl_mvm_unref(mvm, IWL_MVM_REF_BSS_CHANGED);
}
static int iwl_mvm_cancel_scan_wait_notif(struct iwl_mvm *mvm,
enum iwl_scan_status scan_type)
{
int ret;
bool wait_for_handlers = false;
mutex_lock(&mvm->mutex);
if (mvm->scan_status != scan_type) {
ret = 0;
wait_for_handlers = true;
goto out;
}
switch (scan_type) {
case IWL_MVM_SCAN_SCHED:
ret = iwl_mvm_scan_offload_stop(mvm, true);
break;
case IWL_MVM_SCAN_OS:
ret = iwl_mvm_cancel_scan(mvm);
break;
case IWL_MVM_SCAN_NONE:
default:
WARN_ON_ONCE(1);
ret = -EINVAL;
break;
}
if (ret)
goto out;
wait_for_handlers = true;
out:
mutex_unlock(&mvm->mutex);
if (wait_for_handlers)
iwl_mvm_wait_for_async_handlers(mvm);
return ret;
}
static int iwl_mvm_mac_hw_scan(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_scan_request *hw_req)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct cfg80211_scan_request *req = &hw_req->req;
int ret;
if (req->n_channels == 0 ||
req->n_channels > mvm->fw->ucode_capa.n_scan_channels)
return -EINVAL;
if (!(mvm->fw->ucode_capa.capa[0] & IWL_UCODE_TLV_CAPA_UMAC_SCAN)) {
ret = iwl_mvm_cancel_scan_wait_notif(mvm, IWL_MVM_SCAN_SCHED);
if (ret)
return ret;
}
mutex_lock(&mvm->mutex);
if (mvm->scan_status != IWL_MVM_SCAN_NONE) {
ret = -EBUSY;
goto out;
}
iwl_mvm_ref(mvm, IWL_MVM_REF_SCAN);
if (mvm->fw->ucode_capa.capa[0] & IWL_UCODE_TLV_CAPA_UMAC_SCAN)
ret = iwl_mvm_scan_umac(mvm, vif, hw_req);
else if (mvm->fw->ucode_capa.api[0] & IWL_UCODE_TLV_API_LMAC_SCAN)
ret = iwl_mvm_unified_scan_lmac(mvm, vif, hw_req);
else
ret = iwl_mvm_scan_request(mvm, vif, req);
if (ret)
iwl_mvm_unref(mvm, IWL_MVM_REF_SCAN);
out:
mutex_unlock(&mvm->mutex);
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
if (sta->tdls &&
(vif->p2p ||
iwl_mvm_tdls_sta_count(mvm, NULL) ==
IWL_MVM_TDLS_STA_COUNT ||
iwl_mvm_phy_ctx_count(mvm) > 1)) {
IWL_DEBUG_MAC80211(mvm, "refusing TDLS sta\n");
ret = -EBUSY;
goto out_unlock;
}
ret = iwl_mvm_add_sta(mvm, vif, sta);
if (sta->tdls && ret == 0)
iwl_mvm_recalc_tdls_state(mvm, vif, true);
} else if (old_state == IEEE80211_STA_NONE &&
new_state == IEEE80211_STA_AUTH) {
mvm->last_ebs_successful = true;
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
if (iwl_mvm_phy_ctx_count(mvm) > 1)
iwl_mvm_teardown_tdls_peers(mvm);
WARN_ON(iwl_mvm_enable_beacon_filter(mvm, vif, 0));
ret = 0;
} else if (old_state == IEEE80211_STA_AUTHORIZED &&
new_state == IEEE80211_STA_ASSOC) {
WARN_ON(iwl_mvm_disable_beacon_filter(mvm, vif, 0));
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
if (sta->tdls)
iwl_mvm_recalc_tdls_state(mvm, vif, false);
} else {
ret = -EIO;
}
out_unlock:
mutex_unlock(&mvm->mutex);
if (sta->tdls && ret == 0) {
if (old_state == IEEE80211_STA_NOTEXIST &&
new_state == IEEE80211_STA_NONE)
ieee80211_reserve_tid(sta, IWL_MVM_TDLS_FW_TID);
else if (old_state == IEEE80211_STA_NONE &&
new_state == IEEE80211_STA_NOTEXIST)
ieee80211_unreserve_tid(sta, IWL_MVM_TDLS_FW_TID);
}
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
ret = iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL);
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
if (iwl_mvm_ref_sync(mvm, IWL_MVM_REF_PREPARE_TX))
return;
mutex_lock(&mvm->mutex);
iwl_mvm_protect_session(mvm, vif, duration, min_duration, 500, false);
mutex_unlock(&mvm->mutex);
iwl_mvm_unref(mvm, IWL_MVM_REF_PREPARE_TX);
}
static int iwl_mvm_mac_sched_scan_start(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_sched_scan_request *req,
struct ieee80211_scan_ies *ies)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
if (!(mvm->fw->ucode_capa.capa[0] & IWL_UCODE_TLV_CAPA_UMAC_SCAN)) {
ret = iwl_mvm_cancel_scan_wait_notif(mvm, IWL_MVM_SCAN_OS);
if (ret)
return ret;
}
mutex_lock(&mvm->mutex);
if (mvm->fw->ucode_capa.api[0] & IWL_UCODE_TLV_API_LMAC_SCAN) {
if (!vif->bss_conf.idle) {
ret = -EBUSY;
goto out;
}
} else if (!iwl_mvm_is_idle(mvm)) {
ret = -EBUSY;
goto out;
}
if (mvm->scan_status != IWL_MVM_SCAN_NONE) {
ret = -EBUSY;
goto out;
}
ret = iwl_mvm_scan_offload_start(mvm, vif, req, ies);
if (ret)
mvm->scan_status = IWL_MVM_SCAN_NONE;
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_mac_sched_scan_stop(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_scan_offload_stop(mvm, false);
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
if (vif->type != NL80211_IFTYPE_STATION)
return 0;
break;
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
static bool iwl_mvm_rx_aux_roc(struct iwl_notif_wait_data *notif_wait,
struct iwl_rx_packet *pkt, void *data)
{
struct iwl_mvm *mvm =
container_of(notif_wait, struct iwl_mvm, notif_wait);
struct iwl_hs20_roc_res *resp;
int resp_len = iwl_rx_packet_payload_len(pkt);
struct iwl_mvm_time_event_data *te_data = data;
if (WARN_ON(pkt->hdr.cmd != HOT_SPOT_CMD))
return true;
if (WARN_ON_ONCE(resp_len != sizeof(*resp))) {
IWL_ERR(mvm, "Invalid HOT_SPOT_CMD response\n");
return true;
}
resp = (void *)pkt->data;
IWL_DEBUG_TE(mvm,
"Aux ROC: Recieved response from ucode: status=%d uid=%d\n",
resp->status, resp->event_unique_id);
te_data->uid = le32_to_cpu(resp->event_unique_id);
IWL_DEBUG_TE(mvm, "TIME_EVENT_CMD response - UID = 0x%x\n",
te_data->uid);
spin_lock_bh(&mvm->time_event_lock);
list_add_tail(&te_data->list, &mvm->aux_roc_te_list);
spin_unlock_bh(&mvm->time_event_lock);
return true;
}
static int iwl_mvm_send_aux_roc_cmd(struct iwl_mvm *mvm,
struct ieee80211_channel *channel,
struct ieee80211_vif *vif,
int duration)
{
int res, time_reg = DEVICE_SYSTEM_TIME_REG;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_time_event_data *te_data = &mvmvif->hs_time_event_data;
static const u8 time_event_response[] = { HOT_SPOT_CMD };
struct iwl_notification_wait wait_time_event;
struct iwl_hs20_roc_req aux_roc_req = {
.action = cpu_to_le32(FW_CTXT_ACTION_ADD),
.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(MAC_INDEX_AUX, 0)),
.sta_id_and_color = cpu_to_le32(mvm->aux_sta.sta_id),
.channel_info.band = (channel->band == IEEE80211_BAND_2GHZ) ?
PHY_BAND_24 : PHY_BAND_5,
.channel_info.channel = channel->hw_value,
.channel_info.width = PHY_VHT_CHANNEL_MODE20,
.apply_time = cpu_to_le32(iwl_read_prph(mvm->trans, time_reg)),
.apply_time_max_delay =
cpu_to_le32(MSEC_TO_TU(AUX_ROC_MAX_DELAY_ON_CHANNEL)),
.duration = cpu_to_le32(MSEC_TO_TU(duration)),
};
memcpy(aux_roc_req.node_addr, vif->addr, ETH_ALEN);
lockdep_assert_held(&mvm->mutex);
spin_lock_bh(&mvm->time_event_lock);
if (WARN_ON(te_data->id == HOT_SPOT_CMD)) {
spin_unlock_bh(&mvm->time_event_lock);
return -EIO;
}
te_data->vif = vif;
te_data->duration = duration;
te_data->id = HOT_SPOT_CMD;
spin_unlock_bh(&mvm->time_event_lock);
iwl_init_notification_wait(&mvm->notif_wait, &wait_time_event,
time_event_response,
ARRAY_SIZE(time_event_response),
iwl_mvm_rx_aux_roc, te_data);
res = iwl_mvm_send_cmd_pdu(mvm, HOT_SPOT_CMD, 0, sizeof(aux_roc_req),
&aux_roc_req);
if (res) {
IWL_ERR(mvm, "Couldn't send HOT_SPOT_CMD: %d\n", res);
iwl_remove_notification(&mvm->notif_wait, &wait_time_event);
goto out_clear_te;
}
res = iwl_wait_notification(&mvm->notif_wait, &wait_time_event, 1);
WARN_ON_ONCE(res);
if (res) {
out_clear_te:
spin_lock_bh(&mvm->time_event_lock);
iwl_mvm_te_clear_data(mvm, te_data);
spin_unlock_bh(&mvm->time_event_lock);
}
return res;
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
mutex_lock(&mvm->mutex);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
if (mvm->fw->ucode_capa.capa[0] &
IWL_UCODE_TLV_CAPA_HOTSPOT_SUPPORT) {
ret = iwl_mvm_send_aux_roc_cmd(mvm, channel,
vif, duration);
goto out_unlock;
}
IWL_ERR(mvm, "hotspot not supported\n");
ret = -EINVAL;
goto out_unlock;
case NL80211_IFTYPE_P2P_DEVICE:
break;
default:
IWL_ERR(mvm, "vif isn't P2P_DEVICE: %d\n", vif->type);
ret = -EINVAL;
goto out_unlock;
}
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
iwl_mvm_stop_roc(mvm);
mutex_unlock(&mvm->mutex);
IWL_DEBUG_MAC80211(mvm, "leave\n");
return 0;
}
static int __iwl_mvm_add_chanctx(struct iwl_mvm *mvm,
struct ieee80211_chanctx_conf *ctx)
{
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt;
int ret;
lockdep_assert_held(&mvm->mutex);
IWL_DEBUG_MAC80211(mvm, "Add channel context\n");
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
return ret;
}
static int iwl_mvm_add_chanctx(struct ieee80211_hw *hw,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
ret = __iwl_mvm_add_chanctx(mvm, ctx);
mutex_unlock(&mvm->mutex);
return ret;
}
static void __iwl_mvm_remove_chanctx(struct iwl_mvm *mvm,
struct ieee80211_chanctx_conf *ctx)
{
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt = &mvm->phy_ctxts[*phy_ctxt_id];
lockdep_assert_held(&mvm->mutex);
iwl_mvm_phy_ctxt_unref(mvm, phy_ctxt);
}
static void iwl_mvm_remove_chanctx(struct ieee80211_hw *hw,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
mutex_lock(&mvm->mutex);
__iwl_mvm_remove_chanctx(mvm, ctx);
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
iwl_mvm_bt_coex_vif_change(mvm);
iwl_mvm_phy_ctxt_changed(mvm, phy_ctxt, &ctx->min_def,
ctx->rx_chains_static,
ctx->rx_chains_dynamic);
mutex_unlock(&mvm->mutex);
}
static int __iwl_mvm_assign_vif_chanctx(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx,
bool switching_chanctx)
{
u16 *phy_ctxt_id = (u16 *)ctx->drv_priv;
struct iwl_mvm_phy_ctxt *phy_ctxt = &mvm->phy_ctxts[*phy_ctxt_id];
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
lockdep_assert_held(&mvm->mutex);
mvmvif->phy_ctxt = phy_ctxt;
switch (vif->type) {
case NL80211_IFTYPE_AP:
if (switching_chanctx) {
mvmvif->ap_ibss_active = true;
break;
}
case NL80211_IFTYPE_ADHOC:
ret = 0;
goto out;
case NL80211_IFTYPE_STATION:
break;
case NL80211_IFTYPE_MONITOR:
mvmvif->ps_disabled = true;
break;
default:
ret = -EINVAL;
goto out;
}
ret = iwl_mvm_binding_add_vif(mvm, vif);
if (ret)
goto out;
iwl_mvm_power_update_mac(mvm);
if (vif->type == NL80211_IFTYPE_MONITOR) {
mvmvif->monitor_active = true;
ret = iwl_mvm_update_quotas(mvm, NULL);
if (ret)
goto out_remove_binding;
}
if (vif->type == NL80211_IFTYPE_AP) {
iwl_mvm_update_quotas(mvm, NULL);
iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL);
}
if (switching_chanctx && vif->type == NL80211_IFTYPE_STATION) {
u32 duration = 2 * vif->bss_conf.beacon_int;
ret = iwl_mvm_ref_sync(mvm, IWL_MVM_REF_PROTECT_CSA);
if (ret)
goto out_remove_binding;
iwl_mvm_protect_session(mvm, vif, duration, duration,
vif->bss_conf.beacon_int / 2,
true);
iwl_mvm_unref(mvm, IWL_MVM_REF_PROTECT_CSA);
iwl_mvm_update_quotas(mvm, NULL);
}
goto out;
out_remove_binding:
iwl_mvm_binding_remove_vif(mvm, vif);
iwl_mvm_power_update_mac(mvm);
out:
if (ret)
mvmvif->phy_ctxt = NULL;
return ret;
}
static int iwl_mvm_assign_vif_chanctx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
ret = __iwl_mvm_assign_vif_chanctx(mvm, vif, ctx, false);
mutex_unlock(&mvm->mutex);
return ret;
}
static void __iwl_mvm_unassign_vif_chanctx(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx,
bool switching_chanctx)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct ieee80211_vif *disabled_vif = NULL;
lockdep_assert_held(&mvm->mutex);
iwl_mvm_remove_time_event(mvm, mvmvif, &mvmvif->time_event_data);
switch (vif->type) {
case NL80211_IFTYPE_ADHOC:
goto out;
case NL80211_IFTYPE_MONITOR:
mvmvif->monitor_active = false;
mvmvif->ps_disabled = false;
break;
case NL80211_IFTYPE_AP:
if (!switching_chanctx || !mvmvif->ap_ibss_active)
goto out;
mvmvif->csa_countdown = false;
iwl_mvm_modify_all_sta_disable_tx(mvm, mvmvif, true);
rcu_assign_pointer(mvm->csa_tx_blocked_vif, vif);
mvmvif->ap_ibss_active = false;
break;
case NL80211_IFTYPE_STATION:
if (!switching_chanctx)
break;
disabled_vif = vif;
iwl_mvm_mac_ctxt_changed(mvm, vif, true, NULL);
break;
default:
break;
}
iwl_mvm_update_quotas(mvm, disabled_vif);
iwl_mvm_binding_remove_vif(mvm, vif);
out:
mvmvif->phy_ctxt = NULL;
iwl_mvm_power_update_mac(mvm);
}
static void iwl_mvm_unassign_vif_chanctx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_chanctx_conf *ctx)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
mutex_lock(&mvm->mutex);
__iwl_mvm_unassign_vif_chanctx(mvm, vif, ctx, false);
mutex_unlock(&mvm->mutex);
}
static int
iwl_mvm_switch_vif_chanctx_swap(struct iwl_mvm *mvm,
struct ieee80211_vif_chanctx_switch *vifs)
{
int ret;
mutex_lock(&mvm->mutex);
__iwl_mvm_unassign_vif_chanctx(mvm, vifs[0].vif, vifs[0].old_ctx, true);
__iwl_mvm_remove_chanctx(mvm, vifs[0].old_ctx);
ret = __iwl_mvm_add_chanctx(mvm, vifs[0].new_ctx);
if (ret) {
IWL_ERR(mvm, "failed to add new_ctx during channel switch\n");
goto out_reassign;
}
ret = __iwl_mvm_assign_vif_chanctx(mvm, vifs[0].vif, vifs[0].new_ctx,
true);
if (ret) {
IWL_ERR(mvm,
"failed to assign new_ctx during channel switch\n");
goto out_remove;
}
if (iwl_mvm_phy_ctx_count(mvm) > 1)
iwl_mvm_teardown_tdls_peers(mvm);
goto out;
out_remove:
__iwl_mvm_remove_chanctx(mvm, vifs[0].new_ctx);
out_reassign:
if (__iwl_mvm_add_chanctx(mvm, vifs[0].old_ctx)) {
IWL_ERR(mvm, "failed to add old_ctx back after failure.\n");
goto out_restart;
}
if (__iwl_mvm_assign_vif_chanctx(mvm, vifs[0].vif, vifs[0].old_ctx,
true)) {
IWL_ERR(mvm, "failed to reassign old_ctx after failure.\n");
goto out_restart;
}
goto out;
out_restart:
iwl_mvm_nic_restart(mvm, false);
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static int
iwl_mvm_switch_vif_chanctx_reassign(struct iwl_mvm *mvm,
struct ieee80211_vif_chanctx_switch *vifs)
{
int ret;
mutex_lock(&mvm->mutex);
__iwl_mvm_unassign_vif_chanctx(mvm, vifs[0].vif, vifs[0].old_ctx, true);
ret = __iwl_mvm_assign_vif_chanctx(mvm, vifs[0].vif, vifs[0].new_ctx,
true);
if (ret) {
IWL_ERR(mvm,
"failed to assign new_ctx during channel switch\n");
goto out_reassign;
}
goto out;
out_reassign:
if (__iwl_mvm_assign_vif_chanctx(mvm, vifs[0].vif, vifs[0].old_ctx,
true)) {
IWL_ERR(mvm, "failed to reassign old_ctx after failure.\n");
goto out_restart;
}
goto out;
out_restart:
iwl_mvm_nic_restart(mvm, false);
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_switch_vif_chanctx(struct ieee80211_hw *hw,
struct ieee80211_vif_chanctx_switch *vifs,
int n_vifs,
enum ieee80211_chanctx_switch_mode mode)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
if (n_vifs > 1)
return -EOPNOTSUPP;
switch (mode) {
case CHANCTX_SWMODE_SWAP_CONTEXTS:
ret = iwl_mvm_switch_vif_chanctx_swap(mvm, vifs);
break;
case CHANCTX_SWMODE_REASSIGN_VIF:
ret = iwl_mvm_switch_vif_chanctx_reassign(mvm, vifs);
break;
default:
ret = -EOPNOTSUPP;
break;
}
return ret;
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
return iwl_mvm_enable_beacon_filter(mvm, vif, 0);
return iwl_mvm_disable_beacon_filter(mvm, vif, 0);
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
static void iwl_mvm_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_channel_switch *chsw)
{
IWL_DEBUG_MAC80211(IWL_MAC80211_GET_MVM(hw),
"dummy channel switch op\n");
}
static int iwl_mvm_pre_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_channel_switch *chsw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct ieee80211_vif *csa_vif;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
u32 apply_time;
int ret;
mutex_lock(&mvm->mutex);
IWL_DEBUG_MAC80211(mvm, "pre CSA to freq %d\n",
chsw->chandef.center_freq1);
switch (vif->type) {
case NL80211_IFTYPE_AP:
csa_vif =
rcu_dereference_protected(mvm->csa_vif,
lockdep_is_held(&mvm->mutex));
if (WARN_ONCE(csa_vif && csa_vif->csa_active,
"Another CSA is already in progress")) {
ret = -EBUSY;
goto out_unlock;
}
rcu_assign_pointer(mvm->csa_vif, vif);
if (WARN_ONCE(mvmvif->csa_countdown,
"Previous CSA countdown didn't complete")) {
ret = -EBUSY;
goto out_unlock;
}
break;
case NL80211_IFTYPE_STATION:
apply_time = chsw->device_timestamp +
((vif->bss_conf.beacon_int * (chsw->count - 1) -
IWL_MVM_CHANNEL_SWITCH_TIME_CLIENT) * 1024);
if (chsw->block_tx)
iwl_mvm_csa_client_absent(mvm, vif);
iwl_mvm_schedule_csa_period(mvm, vif, vif->bss_conf.beacon_int,
apply_time);
if (mvmvif->bf_data.bf_enabled) {
ret = iwl_mvm_disable_beacon_filter(mvm, vif, 0);
if (ret)
goto out_unlock;
}
break;
default:
break;
}
mvmvif->ps_disabled = true;
ret = iwl_mvm_power_update_ps(mvm);
if (ret)
goto out_unlock;
iwl_mvm_teardown_tdls_peers(mvm);
out_unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_post_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
mutex_lock(&mvm->mutex);
if (vif->type == NL80211_IFTYPE_STATION) {
struct iwl_mvm_sta *mvmsta;
mvmsta = iwl_mvm_sta_from_staid_protected(mvm,
mvmvif->ap_sta_id);
if (WARN_ON(!mvmsta)) {
ret = -EIO;
goto out_unlock;
}
iwl_mvm_sta_modify_disable_tx(mvm, mvmsta, false);
iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL);
ret = iwl_mvm_enable_beacon_filter(mvm, vif, 0);
if (ret)
goto out_unlock;
iwl_mvm_stop_session_protection(mvm, vif);
}
mvmvif->ps_disabled = false;
ret = iwl_mvm_power_update_ps(mvm);
out_unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_mac_flush(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u32 queues, bool drop)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif;
struct iwl_mvm_sta *mvmsta;
struct ieee80211_sta *sta;
int i;
u32 msk = 0;
if (!vif || vif->type != NL80211_IFTYPE_STATION)
return;
mutex_lock(&mvm->mutex);
mvmvif = iwl_mvm_vif_from_mac80211(vif);
for (i = 0; i < IWL_MVM_STATION_COUNT; i++) {
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[i],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta))
continue;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (mvmsta->vif != vif)
continue;
WARN_ON(i != mvmvif->ap_sta_id && !sta->tdls);
msk |= mvmsta->tfd_queue_msk;
}
msk &= ~BIT(vif->hw_queue[IEEE80211_AC_VO]);
if (iwl_mvm_flush_tx_path(mvm, msk, true))
IWL_ERR(mvm, "flush request fail\n");
mutex_unlock(&mvm->mutex);
iwl_trans_wait_tx_queue_empty(mvm->trans, msk);
}
