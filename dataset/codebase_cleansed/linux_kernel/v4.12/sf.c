static void iwl_mvm_bound_iface_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_active_iface_iterator_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (vif == data->ignore_vif || !mvmvif->phy_ctxt ||
vif->type == NL80211_IFTYPE_P2P_DEVICE)
return;
data->num_active_macs++;
if (vif->type == NL80211_IFTYPE_STATION) {
data->sta_vif_ap_sta_id = mvmvif->ap_sta_id;
if (vif->bss_conf.assoc)
data->sta_vif_state = SF_FULL_ON;
else
data->sta_vif_state = SF_INIT_OFF;
}
}
static void iwl_mvm_fill_sf_command(struct iwl_mvm *mvm,
struct iwl_sf_cfg_cmd *sf_cmd,
struct ieee80211_sta *sta)
{
int i, j, watermark;
sf_cmd->watermark[SF_LONG_DELAY_ON] = cpu_to_le32(SF_W_MARK_SCAN);
if (sta) {
if (sta->ht_cap.ht_supported || sta->vht_cap.vht_supported) {
switch (sta->rx_nss) {
case 1:
watermark = SF_W_MARK_SISO;
break;
case 2:
watermark = SF_W_MARK_MIMO2;
break;
default:
watermark = SF_W_MARK_MIMO3;
break;
}
} else {
watermark = SF_W_MARK_LEGACY;
}
} else {
watermark = SF_W_MARK_MIMO2;
}
sf_cmd->watermark[SF_FULL_ON] = cpu_to_le32(watermark);
for (i = 0; i < SF_NUM_SCENARIO; i++) {
for (j = 0; j < SF_NUM_TIMEOUT_TYPES; j++) {
sf_cmd->long_delay_timeouts[i][j] =
cpu_to_le32(SF_LONG_DELAY_AGING_TIMER);
}
}
if (sta) {
BUILD_BUG_ON(sizeof(sf_full_timeout) !=
sizeof(__le32) * SF_NUM_SCENARIO *
SF_NUM_TIMEOUT_TYPES);
memcpy(sf_cmd->full_on_timeouts, sf_full_timeout,
sizeof(sf_full_timeout));
} else {
BUILD_BUG_ON(sizeof(sf_full_timeout_def) !=
sizeof(__le32) * SF_NUM_SCENARIO *
SF_NUM_TIMEOUT_TYPES);
memcpy(sf_cmd->full_on_timeouts, sf_full_timeout_def,
sizeof(sf_full_timeout_def));
}
}
static int iwl_mvm_sf_config(struct iwl_mvm *mvm, u8 sta_id,
enum iwl_sf_state new_state)
{
struct iwl_sf_cfg_cmd sf_cmd = {
.state = cpu_to_le32(new_state),
};
struct ieee80211_sta *sta;
int ret = 0;
if (mvm->cfg->disable_dummy_notification)
sf_cmd.state |= cpu_to_le32(SF_CFG_DUMMY_NOTIF_OFF);
if (new_state != SF_FULL_ON && mvm->sf_state == new_state)
return 0;
switch (new_state) {
case SF_UNINIT:
iwl_mvm_fill_sf_command(mvm, &sf_cmd, NULL);
break;
case SF_FULL_ON:
if (sta_id == IWL_MVM_INVALID_STA) {
IWL_ERR(mvm,
"No station: Cannot switch SF to FULL_ON\n");
return -EINVAL;
}
rcu_read_lock();
sta = rcu_dereference(mvm->fw_id_to_mac_id[sta_id]);
if (IS_ERR_OR_NULL(sta)) {
IWL_ERR(mvm, "Invalid station id\n");
rcu_read_unlock();
return -EINVAL;
}
iwl_mvm_fill_sf_command(mvm, &sf_cmd, sta);
rcu_read_unlock();
break;
case SF_INIT_OFF:
iwl_mvm_fill_sf_command(mvm, &sf_cmd, NULL);
break;
default:
WARN_ONCE(1, "Invalid state: %d. not sending Smart Fifo cmd\n",
new_state);
return -EINVAL;
}
ret = iwl_mvm_send_cmd_pdu(mvm, REPLY_SF_CFG_CMD, CMD_ASYNC,
sizeof(sf_cmd), &sf_cmd);
if (!ret)
mvm->sf_state = new_state;
return ret;
}
int iwl_mvm_sf_update(struct iwl_mvm *mvm, struct ieee80211_vif *changed_vif,
bool remove_vif)
{
enum iwl_sf_state new_state;
u8 sta_id = IWL_MVM_INVALID_STA;
struct iwl_mvm_vif *mvmvif = NULL;
struct iwl_mvm_active_iface_iterator_data data = {
.ignore_vif = changed_vif,
.sta_vif_state = SF_UNINIT,
.sta_vif_ap_sta_id = IWL_MVM_INVALID_STA,
};
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status) ||
(changed_vif && changed_vif->type == NL80211_IFTYPE_P2P_DEVICE))
return 0;
ieee80211_iterate_active_interfaces_atomic(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_bound_iface_iterator,
&data);
if (changed_vif && !remove_vif)
data.num_active_macs++;
switch (data.num_active_macs) {
case 0:
new_state = SF_INIT_OFF;
break;
case 1:
if (remove_vif) {
new_state = data.sta_vif_state;
sta_id = data.sta_vif_ap_sta_id;
} else {
if (WARN_ON(!changed_vif))
return -EINVAL;
if (changed_vif->type != NL80211_IFTYPE_STATION) {
new_state = SF_UNINIT;
} else if (changed_vif->bss_conf.assoc &&
changed_vif->bss_conf.dtim_period) {
mvmvif = iwl_mvm_vif_from_mac80211(changed_vif);
sta_id = mvmvif->ap_sta_id;
new_state = SF_FULL_ON;
} else {
new_state = SF_INIT_OFF;
}
}
break;
default:
new_state = SF_UNINIT;
}
return iwl_mvm_sf_config(mvm, sta_id, new_state);
}
