void iwl_mvm_teardown_tdls_peers(struct iwl_mvm *mvm)
{
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
int i;
lockdep_assert_held(&mvm->mutex);
for (i = 0; i < ARRAY_SIZE(mvm->fw_id_to_mac_id); i++) {
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[i],
lockdep_is_held(&mvm->mutex));
if (!sta || IS_ERR(sta) || !sta->tdls)
continue;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
ieee80211_tdls_oper_request(mvmsta->vif, sta->addr,
NL80211_TDLS_TEARDOWN,
WLAN_REASON_TDLS_TEARDOWN_UNSPECIFIED,
GFP_KERNEL);
}
}
int iwl_mvm_tdls_sta_count(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
int count = 0;
int i;
lockdep_assert_held(&mvm->mutex);
for (i = 0; i < ARRAY_SIZE(mvm->fw_id_to_mac_id); i++) {
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[i],
lockdep_is_held(&mvm->mutex));
if (!sta || IS_ERR(sta) || !sta->tdls)
continue;
if (vif) {
mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (mvmsta->vif != vif)
continue;
}
count++;
}
return count;
}
static void iwl_mvm_tdls_config(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_rx_packet *pkt;
struct iwl_tdls_config_res *resp;
struct iwl_tdls_config_cmd tdls_cfg_cmd = {};
struct iwl_host_cmd cmd = {
.id = TDLS_CONFIG_CMD,
.flags = CMD_WANT_SKB,
.data = { &tdls_cfg_cmd, },
.len = { sizeof(struct iwl_tdls_config_cmd), },
};
struct ieee80211_sta *sta;
int ret, i, cnt;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
lockdep_assert_held(&mvm->mutex);
tdls_cfg_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id, mvmvif->color));
tdls_cfg_cmd.tx_to_ap_tid = IWL_MVM_TDLS_FW_TID;
tdls_cfg_cmd.tx_to_ap_ssn = cpu_to_le16(0);
cnt = 0;
for (i = 0; i < ARRAY_SIZE(mvm->fw_id_to_mac_id); i++) {
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[i],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta) || !sta->tdls)
continue;
tdls_cfg_cmd.sta_info[cnt].sta_id = i;
tdls_cfg_cmd.sta_info[cnt].tx_to_peer_tid =
IWL_MVM_TDLS_FW_TID;
tdls_cfg_cmd.sta_info[cnt].tx_to_peer_ssn = cpu_to_le16(0);
tdls_cfg_cmd.sta_info[cnt].is_initiator =
cpu_to_le32(sta->tdls_initiator ? 1 : 0);
cnt++;
}
tdls_cfg_cmd.tdls_peer_count = cnt;
IWL_DEBUG_TDLS(mvm, "send TDLS config to FW for %d peers\n", cnt);
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (WARN_ON_ONCE(ret))
return;
pkt = cmd.resp_pkt;
WARN_ON_ONCE(iwl_rx_packet_payload_len(pkt) != sizeof(*resp));
iwl_free_resp(&cmd);
}
void iwl_mvm_recalc_tdls_state(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
bool sta_added)
{
int tdls_sta_cnt = iwl_mvm_tdls_sta_count(mvm, vif);
if (tdls_sta_cnt == 1 && sta_added)
iwl_mvm_power_update_mac(mvm);
iwl_mvm_tdls_config(mvm, vif);
if (tdls_sta_cnt == 0 && !sta_added)
iwl_mvm_power_update_mac(mvm);
}
void iwl_mvm_mac_mgd_protect_tdls_discover(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
u32 duration = 2 * vif->bss_conf.dtim_period * vif->bss_conf.beacon_int;
if (iwl_mvm_ref_sync(mvm, IWL_MVM_REF_PROTECT_TDLS))
return;
mutex_lock(&mvm->mutex);
iwl_mvm_protect_session(mvm, vif, duration, duration, 100, true);
mutex_unlock(&mvm->mutex);
iwl_mvm_unref(mvm, IWL_MVM_REF_PROTECT_TDLS);
}
static const char *
iwl_mvm_tdls_cs_state_str(enum iwl_mvm_tdls_cs_state state)
{
switch (state) {
case IWL_MVM_TDLS_SW_IDLE:
return "IDLE";
case IWL_MVM_TDLS_SW_REQ_SENT:
return "REQ SENT";
case IWL_MVM_TDLS_SW_RESP_RCVD:
return "RESP RECEIVED";
case IWL_MVM_TDLS_SW_REQ_RCVD:
return "REQ RECEIVED";
case IWL_MVM_TDLS_SW_ACTIVE:
return "ACTIVE";
}
return NULL;
}
static void iwl_mvm_tdls_update_cs_state(struct iwl_mvm *mvm,
enum iwl_mvm_tdls_cs_state state)
{
if (mvm->tdls_cs.state == state)
return;
IWL_DEBUG_TDLS(mvm, "TDLS channel switch state: %s -> %s\n",
iwl_mvm_tdls_cs_state_str(mvm->tdls_cs.state),
iwl_mvm_tdls_cs_state_str(state));
mvm->tdls_cs.state = state;
if (state == IWL_MVM_TDLS_SW_REQ_SENT)
mvm->tdls_cs.peer.sent_timestamp =
iwl_read_prph(mvm->trans, DEVICE_SYSTEM_TIME_REG);
if (state == IWL_MVM_TDLS_SW_IDLE)
mvm->tdls_cs.cur_sta_id = IWL_MVM_INVALID_STA;
}
void iwl_mvm_rx_tdls_notif(struct iwl_mvm *mvm, struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_tdls_channel_switch_notif *notif = (void *)pkt->data;
struct ieee80211_sta *sta;
unsigned int delay;
struct iwl_mvm_sta *mvmsta;
struct ieee80211_vif *vif;
u32 sta_id = le32_to_cpu(notif->sta_id);
lockdep_assert_held(&mvm->mutex);
if (!le32_to_cpu(notif->status)) {
iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_IDLE);
return;
}
if (WARN_ON(sta_id >= IWL_MVM_STATION_COUNT))
return;
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[sta_id],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta) || WARN_ON(!sta->tdls))
return;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
vif = mvmsta->vif;
delay = TU_TO_MS(vif->bss_conf.dtim_period * vif->bss_conf.beacon_int);
mod_delayed_work(system_wq, &mvm->tdls_cs.dwork,
msecs_to_jiffies(delay));
iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_ACTIVE);
}
static int
iwl_mvm_tdls_check_action(struct iwl_mvm *mvm,
enum iwl_tdls_channel_switch_type type,
const u8 *peer, bool peer_initiator, u32 timestamp)
{
bool same_peer = false;
int ret = 0;
if (mvm->tdls_cs.state != IWL_MVM_TDLS_SW_IDLE &&
mvm->tdls_cs.cur_sta_id != IWL_MVM_INVALID_STA) {
struct ieee80211_sta *sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvm->tdls_cs.cur_sta_id],
lockdep_is_held(&mvm->mutex));
if (!IS_ERR_OR_NULL(sta))
same_peer = ether_addr_equal(peer, sta->addr);
}
switch (mvm->tdls_cs.state) {
case IWL_MVM_TDLS_SW_IDLE:
if (type == TDLS_MOVE_CH)
ret = -EINVAL;
break;
case IWL_MVM_TDLS_SW_REQ_SENT:
if (!same_peer)
ret = -EBUSY;
else if (type == TDLS_SEND_CHAN_SW_RESP_AND_MOVE_CH &&
!peer_initiator)
ret = -EBUSY;
else if (type == TDLS_SEND_CHAN_SW_REQ)
ret = -EBUSY;
else if (timestamp <= mvm->tdls_cs.peer.sent_timestamp)
ret = -EINVAL;
break;
case IWL_MVM_TDLS_SW_RESP_RCVD:
ret = -EBUSY;
break;
case IWL_MVM_TDLS_SW_REQ_RCVD:
if (type == TDLS_SEND_CHAN_SW_REQ) {
if (!same_peer)
ret = -EBUSY;
else if (peer_initiator)
ret = -EBUSY;
} else if (type == TDLS_MOVE_CH) {
ret = -EINVAL;
}
break;
case IWL_MVM_TDLS_SW_ACTIVE:
if (type != TDLS_MOVE_CH || !same_peer)
ret = -EBUSY;
break;
}
if (ret)
IWL_DEBUG_TDLS(mvm,
"Invalid TDLS action %d state %d peer %pM same_peer %d initiator %d\n",
type, mvm->tdls_cs.state, peer, same_peer,
peer_initiator);
return ret;
}
static int
iwl_mvm_tdls_config_channel_switch(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
enum iwl_tdls_channel_switch_type type,
const u8 *peer, bool peer_initiator,
u8 oper_class,
struct cfg80211_chan_def *chandef,
u32 timestamp, u16 switch_time,
u16 switch_timeout, struct sk_buff *skb,
u32 ch_sw_tm_ie)
{
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
struct ieee80211_tx_info *info;
struct ieee80211_hdr *hdr;
struct iwl_tdls_channel_switch_cmd cmd = {0};
int ret;
lockdep_assert_held(&mvm->mutex);
ret = iwl_mvm_tdls_check_action(mvm, type, peer, peer_initiator,
timestamp);
if (ret)
return ret;
if (!skb || WARN_ON(skb->len > IWL_TDLS_CH_SW_FRAME_MAX_SIZE)) {
ret = -EINVAL;
goto out;
}
cmd.switch_type = type;
cmd.timing.frame_timestamp = cpu_to_le32(timestamp);
cmd.timing.switch_time = cpu_to_le32(switch_time);
cmd.timing.switch_timeout = cpu_to_le32(switch_timeout);
rcu_read_lock();
sta = ieee80211_find_sta(vif, peer);
if (!sta) {
rcu_read_unlock();
ret = -ENOENT;
goto out;
}
mvmsta = iwl_mvm_sta_from_mac80211(sta);
cmd.peer_sta_id = cpu_to_le32(mvmsta->sta_id);
if (!chandef) {
if (mvm->tdls_cs.state == IWL_MVM_TDLS_SW_REQ_SENT &&
mvm->tdls_cs.peer.chandef.chan) {
chandef = &mvm->tdls_cs.peer.chandef;
} else if (mvm->tdls_cs.state == IWL_MVM_TDLS_SW_ACTIVE &&
type == TDLS_MOVE_CH) {
struct ieee80211_chanctx_conf *chanctx =
rcu_dereference(vif->chanctx_conf);
if (WARN_ON_ONCE(!chanctx)) {
rcu_read_unlock();
goto out;
}
chandef = &chanctx->def;
}
}
if (chandef) {
cmd.ci.band = (chandef->chan->band == NL80211_BAND_2GHZ ?
PHY_BAND_24 : PHY_BAND_5);
cmd.ci.channel = chandef->chan->hw_value;
cmd.ci.width = iwl_mvm_get_channel_width(chandef);
cmd.ci.ctrl_pos = iwl_mvm_get_ctrl_pos(chandef);
}
cmd.timing.max_offchan_duration =
cpu_to_le32(TU_TO_US(vif->bss_conf.dtim_period *
vif->bss_conf.beacon_int) / 2);
cmd.frame.switch_time_offset = cpu_to_le32(ch_sw_tm_ie + 2);
info = IEEE80211_SKB_CB(skb);
hdr = (void *)skb->data;
if (info->control.hw_key) {
if (info->control.hw_key->cipher != WLAN_CIPHER_SUITE_CCMP) {
rcu_read_unlock();
ret = -EINVAL;
goto out;
}
iwl_mvm_set_tx_cmd_ccmp(info, &cmd.frame.tx_cmd);
}
iwl_mvm_set_tx_cmd(mvm, skb, &cmd.frame.tx_cmd, info,
mvmsta->sta_id);
iwl_mvm_set_tx_cmd_rate(mvm, &cmd.frame.tx_cmd, info, sta,
hdr->frame_control);
rcu_read_unlock();
memcpy(cmd.frame.data, skb->data, skb->len);
ret = iwl_mvm_send_cmd_pdu(mvm, TDLS_CHANNEL_SWITCH_CMD, 0,
sizeof(cmd), &cmd);
if (ret) {
IWL_ERR(mvm, "Failed to send TDLS_CHANNEL_SWITCH cmd: %d\n",
ret);
goto out;
}
if (type != TDLS_MOVE_CH) {
mvm->tdls_cs.cur_sta_id = mvmsta->sta_id;
iwl_mvm_tdls_update_cs_state(mvm,
type == TDLS_SEND_CHAN_SW_REQ ?
IWL_MVM_TDLS_SW_REQ_SENT :
IWL_MVM_TDLS_SW_REQ_RCVD);
} else {
iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_RESP_RCVD);
}
out:
if (ret)
iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_IDLE);
return ret;
}
void iwl_mvm_tdls_ch_switch_work(struct work_struct *work)
{
struct iwl_mvm *mvm;
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
struct ieee80211_vif *vif;
unsigned int delay;
int ret;
mvm = container_of(work, struct iwl_mvm, tdls_cs.dwork.work);
mutex_lock(&mvm->mutex);
iwl_mvm_tdls_update_cs_state(mvm, IWL_MVM_TDLS_SW_IDLE);
if (mvm->tdls_cs.peer.sta_id == IWL_MVM_INVALID_STA)
goto out;
sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvm->tdls_cs.peer.sta_id],
lockdep_is_held(&mvm->mutex));
if (!sta || IS_ERR(sta) || WARN_ON(!sta->tdls))
goto out;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
vif = mvmsta->vif;
ret = iwl_mvm_tdls_config_channel_switch(mvm, vif,
TDLS_SEND_CHAN_SW_REQ,
sta->addr,
mvm->tdls_cs.peer.initiator,
mvm->tdls_cs.peer.op_class,
&mvm->tdls_cs.peer.chandef,
0, 0, 0,
mvm->tdls_cs.peer.skb,
mvm->tdls_cs.peer.ch_sw_tm_ie);
if (ret)
IWL_ERR(mvm, "Not sending TDLS channel switch: %d\n", ret);
delay = TU_TO_MS(vif->bss_conf.dtim_period * vif->bss_conf.beacon_int);
queue_delayed_work(system_wq, &mvm->tdls_cs.dwork,
msecs_to_jiffies(delay));
out:
mutex_unlock(&mvm->mutex);
}
int
iwl_mvm_tdls_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u8 oper_class,
struct cfg80211_chan_def *chandef,
struct sk_buff *tmpl_skb, u32 ch_sw_tm_ie)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_sta *mvmsta;
unsigned int delay;
int ret;
mutex_lock(&mvm->mutex);
IWL_DEBUG_TDLS(mvm, "TDLS channel switch with %pM ch %d width %d\n",
sta->addr, chandef->chan->center_freq, chandef->width);
if (mvm->tdls_cs.peer.sta_id != IWL_MVM_INVALID_STA) {
IWL_DEBUG_TDLS(mvm,
"Existing peer. Can't start switch with %pM\n",
sta->addr);
ret = -EBUSY;
goto out;
}
ret = iwl_mvm_tdls_config_channel_switch(mvm, vif,
TDLS_SEND_CHAN_SW_REQ,
sta->addr, sta->tdls_initiator,
oper_class, chandef, 0, 0, 0,
tmpl_skb, ch_sw_tm_ie);
if (ret)
goto out;
mvm->tdls_cs.peer.skb = skb_copy(tmpl_skb, GFP_KERNEL);
if (!mvm->tdls_cs.peer.skb) {
ret = -ENOMEM;
goto out;
}
mvmsta = iwl_mvm_sta_from_mac80211(sta);
mvm->tdls_cs.peer.sta_id = mvmsta->sta_id;
mvm->tdls_cs.peer.chandef = *chandef;
mvm->tdls_cs.peer.initiator = sta->tdls_initiator;
mvm->tdls_cs.peer.op_class = oper_class;
mvm->tdls_cs.peer.ch_sw_tm_ie = ch_sw_tm_ie;
delay = 2 * TU_TO_MS(vif->bss_conf.dtim_period *
vif->bss_conf.beacon_int);
mod_delayed_work(system_wq, &mvm->tdls_cs.dwork,
msecs_to_jiffies(delay));
out:
mutex_unlock(&mvm->mutex);
return ret;
}
void iwl_mvm_tdls_cancel_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct ieee80211_sta *cur_sta;
bool wait_for_phy = false;
mutex_lock(&mvm->mutex);
IWL_DEBUG_TDLS(mvm, "TDLS cancel channel switch with %pM\n", sta->addr);
if (mvm->tdls_cs.peer.sta_id == IWL_MVM_INVALID_STA) {
IWL_DEBUG_TDLS(mvm, "No ch switch peer - %pM\n", sta->addr);
goto out;
}
cur_sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvm->tdls_cs.peer.sta_id],
lockdep_is_held(&mvm->mutex));
if (cur_sta != sta)
goto out;
if (mvm->tdls_cs.cur_sta_id == mvm->tdls_cs.peer.sta_id &&
mvm->tdls_cs.state != IWL_MVM_TDLS_SW_IDLE)
wait_for_phy = true;
mvm->tdls_cs.peer.sta_id = IWL_MVM_INVALID_STA;
dev_kfree_skb(mvm->tdls_cs.peer.skb);
mvm->tdls_cs.peer.skb = NULL;
out:
mutex_unlock(&mvm->mutex);
if (wait_for_phy)
msleep(TU_TO_MS(vif->bss_conf.dtim_period *
vif->bss_conf.beacon_int));
flush_delayed_work(&mvm->tdls_cs.dwork);
IWL_DEBUG_TDLS(mvm, "TDLS ending channel switch with %pM\n", sta->addr);
}
void
iwl_mvm_tdls_recv_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_tdls_ch_sw_params *params)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
enum iwl_tdls_channel_switch_type type;
unsigned int delay;
const char *action_str =
params->action_code == WLAN_TDLS_CHANNEL_SWITCH_REQUEST ?
"REQ" : "RESP";
mutex_lock(&mvm->mutex);
IWL_DEBUG_TDLS(mvm,
"Received TDLS ch switch action %s from %pM status %d\n",
action_str, params->sta->addr, params->status);
if (params->action_code == WLAN_TDLS_CHANNEL_SWITCH_RESPONSE &&
params->status != 0 &&
mvm->tdls_cs.state == IWL_MVM_TDLS_SW_REQ_SENT &&
mvm->tdls_cs.cur_sta_id != IWL_MVM_INVALID_STA) {
struct ieee80211_sta *cur_sta;
cur_sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvm->tdls_cs.cur_sta_id],
lockdep_is_held(&mvm->mutex));
if (cur_sta == params->sta) {
iwl_mvm_tdls_update_cs_state(mvm,
IWL_MVM_TDLS_SW_IDLE);
goto retry;
}
}
type = (params->action_code == WLAN_TDLS_CHANNEL_SWITCH_REQUEST) ?
TDLS_SEND_CHAN_SW_RESP_AND_MOVE_CH : TDLS_MOVE_CH;
iwl_mvm_tdls_config_channel_switch(mvm, vif, type, params->sta->addr,
params->sta->tdls_initiator, 0,
params->chandef, params->timestamp,
params->switch_time,
params->switch_timeout,
params->tmpl_skb,
params->ch_sw_tm_ie);
retry:
delay = vif->bss_conf.dtim_period * vif->bss_conf.beacon_int *
1024 / 1000;
mod_delayed_work(system_wq, &mvm->tdls_cs.dwork,
msecs_to_jiffies(delay));
mutex_unlock(&mvm->mutex);
}
