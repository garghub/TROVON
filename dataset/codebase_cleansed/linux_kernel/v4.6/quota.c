static void iwl_mvm_quota_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_quota_iterator_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
u16 id;
if (vif == data->disabled_vif)
return;
if (!mvmvif->phy_ctxt)
return;
id = mvmvif->phy_ctxt->id;
BUILD_BUG_ON(NUM_PHY_CTX > MAX_BINDINGS);
if (WARN_ON_ONCE(id >= MAX_BINDINGS))
return;
switch (vif->type) {
case NL80211_IFTYPE_STATION:
if (vif->bss_conf.assoc)
break;
return;
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_ADHOC:
if (mvmvif->ap_ibss_active)
break;
return;
case NL80211_IFTYPE_MONITOR:
if (mvmvif->monitor_active)
break;
return;
case NL80211_IFTYPE_P2P_DEVICE:
return;
default:
WARN_ON_ONCE(1);
return;
}
if (data->colors[id] < 0)
data->colors[id] = mvmvif->phy_ctxt->color;
else
WARN_ON_ONCE(data->colors[id] != mvmvif->phy_ctxt->color);
data->n_interfaces[id]++;
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvmvif->dbgfs_quota_min)
data->dbgfs_min[id] = max(data->dbgfs_min[id],
mvmvif->dbgfs_quota_min);
#endif
if (iwl_mvm_vif_low_latency(mvmvif) && !data->low_latency[id]) {
data->n_low_latency_bindings++;
data->low_latency[id] = true;
}
}
static void iwl_mvm_adjust_quota_for_noa(struct iwl_mvm *mvm,
struct iwl_time_quota_cmd *cmd)
{
#ifdef CONFIG_NL80211_TESTMODE
struct iwl_mvm_vif *mvmvif;
int i, phy_id = -1, beacon_int = 0;
if (!mvm->noa_duration || !mvm->noa_vif)
return;
mvmvif = iwl_mvm_vif_from_mac80211(mvm->noa_vif);
if (!mvmvif->ap_ibss_active)
return;
phy_id = mvmvif->phy_ctxt->id;
beacon_int = mvm->noa_vif->bss_conf.beacon_int;
for (i = 0; i < MAX_BINDINGS; i++) {
u32 id_n_c = le32_to_cpu(cmd->quotas[i].id_and_color);
u32 id = (id_n_c & FW_CTXT_ID_MSK) >> FW_CTXT_ID_POS;
u32 quota = le32_to_cpu(cmd->quotas[i].quota);
if (id != phy_id)
continue;
quota *= (beacon_int - mvm->noa_duration);
quota /= beacon_int;
IWL_DEBUG_QUOTA(mvm, "quota: adjust for NoA from %d to %d\n",
le32_to_cpu(cmd->quotas[i].quota), quota);
cmd->quotas[i].quota = cpu_to_le32(quota);
}
#endif
}
int iwl_mvm_update_quotas(struct iwl_mvm *mvm,
bool force_update,
struct ieee80211_vif *disabled_vif)
{
struct iwl_time_quota_cmd cmd = {};
int i, idx, err, num_active_macs, quota, quota_rem, n_non_lowlat;
struct iwl_mvm_quota_iterator_data data = {
.n_interfaces = {},
.colors = { -1, -1, -1, -1 },
.disabled_vif = disabled_vif,
};
struct iwl_time_quota_cmd *last = &mvm->last_quota_cmd;
bool send = false;
lockdep_assert_held(&mvm->mutex);
if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status))
return 0;
BUILD_BUG_ON(MAX_BINDINGS != 4);
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_quota_iterator, &data);
num_active_macs = 0;
for (i = 0; i < MAX_BINDINGS; i++) {
cmd.quotas[i].id_and_color = cpu_to_le32(FW_CTXT_INVALID);
num_active_macs += data.n_interfaces[i];
}
n_non_lowlat = num_active_macs;
if (data.n_low_latency_bindings == 1) {
for (i = 0; i < MAX_BINDINGS; i++) {
if (data.low_latency[i]) {
n_non_lowlat -= data.n_interfaces[i];
break;
}
}
}
if (data.n_low_latency_bindings == 1 && n_non_lowlat) {
quota = (QUOTA_100 - QUOTA_LOWLAT_MIN) / n_non_lowlat;
quota_rem = QUOTA_100 - n_non_lowlat * quota -
QUOTA_LOWLAT_MIN;
IWL_DEBUG_QUOTA(mvm,
"quota: low-latency binding active, remaining quota per other binding: %d\n",
quota);
} else if (num_active_macs) {
quota = QUOTA_100 / num_active_macs;
quota_rem = QUOTA_100 % num_active_macs;
IWL_DEBUG_QUOTA(mvm,
"quota: splitting evenly per binding: %d\n",
quota);
} else {
quota = 0;
quota_rem = 0;
}
for (idx = 0, i = 0; i < MAX_BINDINGS; i++) {
if (data.colors[i] < 0)
continue;
cmd.quotas[idx].id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(i, data.colors[i]));
if (data.n_interfaces[i] <= 0)
cmd.quotas[idx].quota = cpu_to_le32(0);
#ifdef CONFIG_IWLWIFI_DEBUGFS
else if (data.dbgfs_min[i])
cmd.quotas[idx].quota =
cpu_to_le32(data.dbgfs_min[i] * QUOTA_100 / 100);
#endif
else if (data.n_low_latency_bindings == 1 && n_non_lowlat &&
data.low_latency[i])
cmd.quotas[idx].quota = cpu_to_le32(QUOTA_LOWLAT_MIN);
else
cmd.quotas[idx].quota =
cpu_to_le32(quota * data.n_interfaces[i]);
WARN_ONCE(le32_to_cpu(cmd.quotas[idx].quota) > QUOTA_100,
"Binding=%d, quota=%u > max=%u\n",
idx, le32_to_cpu(cmd.quotas[idx].quota), QUOTA_100);
cmd.quotas[idx].max_duration = cpu_to_le32(0);
idx++;
}
for (i = 0; i < MAX_BINDINGS; i++) {
if (le32_to_cpu(cmd.quotas[i].quota) != 0) {
le32_add_cpu(&cmd.quotas[i].quota, quota_rem);
IWL_DEBUG_QUOTA(mvm,
"quota: giving remainder of %d to binding %d\n",
quota_rem, i);
break;
}
}
iwl_mvm_adjust_quota_for_noa(mvm, &cmd);
for (i = 0; i < MAX_BINDINGS; i++) {
if (cmd.quotas[i].id_and_color != last->quotas[i].id_and_color)
send = true;
if (cmd.quotas[i].max_duration != last->quotas[i].max_duration)
send = true;
if (abs((int)le32_to_cpu(cmd.quotas[i].quota) -
(int)le32_to_cpu(last->quotas[i].quota))
> IWL_MVM_QUOTA_THRESHOLD)
send = true;
if (cmd.quotas[i].id_and_color == cpu_to_le32(FW_CTXT_INVALID))
continue;
WARN_ONCE(cmd.quotas[i].quota == 0,
"zero quota on binding %d\n", i);
}
if (!send && !force_update) {
return 0;
}
err = iwl_mvm_send_cmd_pdu(mvm, TIME_QUOTA_CMD, 0, sizeof(cmd), &cmd);
if (err)
IWL_ERR(mvm, "Failed to send quota: %d\n", err);
else
mvm->last_quota_cmd = cmd;
return err;
}
