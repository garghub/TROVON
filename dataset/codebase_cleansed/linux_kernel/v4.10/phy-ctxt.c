u8 iwl_mvm_get_channel_width(struct cfg80211_chan_def *chandef)
{
switch (chandef->width) {
case NL80211_CHAN_WIDTH_20_NOHT:
case NL80211_CHAN_WIDTH_20:
return PHY_VHT_CHANNEL_MODE20;
case NL80211_CHAN_WIDTH_40:
return PHY_VHT_CHANNEL_MODE40;
case NL80211_CHAN_WIDTH_80:
return PHY_VHT_CHANNEL_MODE80;
case NL80211_CHAN_WIDTH_160:
return PHY_VHT_CHANNEL_MODE160;
default:
WARN(1, "Invalid channel width=%u", chandef->width);
return PHY_VHT_CHANNEL_MODE20;
}
}
u8 iwl_mvm_get_ctrl_pos(struct cfg80211_chan_def *chandef)
{
switch (chandef->chan->center_freq - chandef->center_freq1) {
case -70:
return PHY_VHT_CTRL_POS_4_BELOW;
case -50:
return PHY_VHT_CTRL_POS_3_BELOW;
case -30:
return PHY_VHT_CTRL_POS_2_BELOW;
case -10:
return PHY_VHT_CTRL_POS_1_BELOW;
case 10:
return PHY_VHT_CTRL_POS_1_ABOVE;
case 30:
return PHY_VHT_CTRL_POS_2_ABOVE;
case 50:
return PHY_VHT_CTRL_POS_3_ABOVE;
case 70:
return PHY_VHT_CTRL_POS_4_ABOVE;
default:
WARN(1, "Invalid channel definition");
case 0:
return PHY_VHT_CTRL_POS_1_BELOW;
}
}
static void iwl_mvm_phy_ctxt_cmd_hdr(struct iwl_mvm_phy_ctxt *ctxt,
struct iwl_phy_context_cmd *cmd,
u32 action, u32 apply_time)
{
memset(cmd, 0, sizeof(struct iwl_phy_context_cmd));
cmd->id_and_color = cpu_to_le32(FW_CMD_ID_AND_COLOR(ctxt->id,
ctxt->color));
cmd->action = cpu_to_le32(action);
cmd->apply_time = cpu_to_le32(apply_time);
}
static void iwl_mvm_phy_ctxt_cmd_data(struct iwl_mvm *mvm,
struct iwl_phy_context_cmd *cmd,
struct cfg80211_chan_def *chandef,
u8 chains_static, u8 chains_dynamic)
{
u8 active_cnt, idle_cnt;
cmd->ci.band = (chandef->chan->band == NL80211_BAND_2GHZ ?
PHY_BAND_24 : PHY_BAND_5);
cmd->ci.channel = chandef->chan->hw_value;
cmd->ci.width = iwl_mvm_get_channel_width(chandef);
cmd->ci.ctrl_pos = iwl_mvm_get_ctrl_pos(chandef);
idle_cnt = chains_static;
active_cnt = chains_dynamic;
if (active_cnt == 1 && iwl_mvm_rx_diversity_allowed(mvm)) {
idle_cnt = 2;
active_cnt = 2;
}
cmd->rxchain_info = cpu_to_le32(iwl_mvm_get_valid_rx_ant(mvm) <<
PHY_RX_CHAIN_VALID_POS);
cmd->rxchain_info |= cpu_to_le32(idle_cnt << PHY_RX_CHAIN_CNT_POS);
cmd->rxchain_info |= cpu_to_le32(active_cnt <<
PHY_RX_CHAIN_MIMO_CNT_POS);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (unlikely(mvm->dbgfs_rx_phyinfo))
cmd->rxchain_info = cpu_to_le32(mvm->dbgfs_rx_phyinfo);
#endif
cmd->txchain_info = cpu_to_le32(iwl_mvm_get_valid_tx_ant(mvm));
}
static int iwl_mvm_phy_ctxt_apply(struct iwl_mvm *mvm,
struct iwl_mvm_phy_ctxt *ctxt,
struct cfg80211_chan_def *chandef,
u8 chains_static, u8 chains_dynamic,
u32 action, u32 apply_time)
{
struct iwl_phy_context_cmd cmd;
int ret;
iwl_mvm_phy_ctxt_cmd_hdr(ctxt, &cmd, action, apply_time);
iwl_mvm_phy_ctxt_cmd_data(mvm, &cmd, chandef,
chains_static, chains_dynamic);
ret = iwl_mvm_send_cmd_pdu(mvm, PHY_CONTEXT_CMD, 0,
sizeof(struct iwl_phy_context_cmd),
&cmd);
if (ret)
IWL_ERR(mvm, "PHY ctxt cmd error. ret=%d\n", ret);
return ret;
}
int iwl_mvm_phy_ctxt_add(struct iwl_mvm *mvm, struct iwl_mvm_phy_ctxt *ctxt,
struct cfg80211_chan_def *chandef,
u8 chains_static, u8 chains_dynamic)
{
WARN_ON(!test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status) &&
ctxt->ref);
lockdep_assert_held(&mvm->mutex);
ctxt->channel = chandef->chan;
return iwl_mvm_phy_ctxt_apply(mvm, ctxt, chandef,
chains_static, chains_dynamic,
FW_CTXT_ACTION_ADD, 0);
}
void iwl_mvm_phy_ctxt_ref(struct iwl_mvm *mvm, struct iwl_mvm_phy_ctxt *ctxt)
{
lockdep_assert_held(&mvm->mutex);
ctxt->ref++;
}
int iwl_mvm_phy_ctxt_changed(struct iwl_mvm *mvm, struct iwl_mvm_phy_ctxt *ctxt,
struct cfg80211_chan_def *chandef,
u8 chains_static, u8 chains_dynamic)
{
lockdep_assert_held(&mvm->mutex);
ctxt->channel = chandef->chan;
return iwl_mvm_phy_ctxt_apply(mvm, ctxt, chandef,
chains_static, chains_dynamic,
FW_CTXT_ACTION_MODIFY, 0);
}
void iwl_mvm_phy_ctxt_unref(struct iwl_mvm *mvm, struct iwl_mvm_phy_ctxt *ctxt)
{
lockdep_assert_held(&mvm->mutex);
if (WARN_ON_ONCE(!ctxt))
return;
ctxt->ref--;
}
static void iwl_mvm_binding_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
unsigned long *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (!mvmvif->phy_ctxt)
return;
if (vif->type == NL80211_IFTYPE_STATION ||
vif->type == NL80211_IFTYPE_AP)
__set_bit(mvmvif->phy_ctxt->id, data);
}
int iwl_mvm_phy_ctx_count(struct iwl_mvm *mvm)
{
unsigned long phy_ctxt_counter = 0;
ieee80211_iterate_active_interfaces_atomic(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_binding_iterator,
&phy_ctxt_counter);
return hweight8(phy_ctxt_counter);
}
