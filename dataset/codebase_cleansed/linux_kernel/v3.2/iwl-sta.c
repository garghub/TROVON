static void iwl_legacy_sta_ucode_activate(struct iwl_priv *priv, u8 sta_id)
{
if (!(priv->stations[sta_id].used & IWL_STA_DRIVER_ACTIVE))
IWL_ERR(priv,
"ACTIVATE a non DRIVER active station id %u addr %pM\n",
sta_id, priv->stations[sta_id].sta.sta.addr);
if (priv->stations[sta_id].used & IWL_STA_UCODE_ACTIVE) {
IWL_DEBUG_ASSOC(priv,
"STA id %u addr %pM already present"
" in uCode (according to driver)\n",
sta_id, priv->stations[sta_id].sta.sta.addr);
} else {
priv->stations[sta_id].used |= IWL_STA_UCODE_ACTIVE;
IWL_DEBUG_ASSOC(priv, "Added STA id %u addr %pM to uCode\n",
sta_id, priv->stations[sta_id].sta.sta.addr);
}
}
static int iwl_legacy_process_add_sta_resp(struct iwl_priv *priv,
struct iwl_legacy_addsta_cmd *addsta,
struct iwl_rx_packet *pkt,
bool sync)
{
u8 sta_id = addsta->sta.sta_id;
unsigned long flags;
int ret = -EIO;
if (pkt->hdr.flags & IWL_CMD_FAILED_MSK) {
IWL_ERR(priv, "Bad return from REPLY_ADD_STA (0x%08X)\n",
pkt->hdr.flags);
return ret;
}
IWL_DEBUG_INFO(priv, "Processing response for adding station %u\n",
sta_id);
spin_lock_irqsave(&priv->sta_lock, flags);
switch (pkt->u.add_sta.status) {
case ADD_STA_SUCCESS_MSK:
IWL_DEBUG_INFO(priv, "REPLY_ADD_STA PASSED\n");
iwl_legacy_sta_ucode_activate(priv, sta_id);
ret = 0;
break;
case ADD_STA_NO_ROOM_IN_TABLE:
IWL_ERR(priv, "Adding station %d failed, no room in table.\n",
sta_id);
break;
case ADD_STA_NO_BLOCK_ACK_RESOURCE:
IWL_ERR(priv,
"Adding station %d failed, no block ack resource.\n",
sta_id);
break;
case ADD_STA_MODIFY_NON_EXIST_STA:
IWL_ERR(priv, "Attempting to modify non-existing station %d\n",
sta_id);
break;
default:
IWL_DEBUG_ASSOC(priv, "Received REPLY_ADD_STA:(0x%08X)\n",
pkt->u.add_sta.status);
break;
}
IWL_DEBUG_INFO(priv, "%s station id %u addr %pM\n",
priv->stations[sta_id].sta.mode ==
STA_CONTROL_MODIFY_MSK ? "Modified" : "Added",
sta_id, priv->stations[sta_id].sta.sta.addr);
IWL_DEBUG_INFO(priv, "%s station according to cmd buffer %pM\n",
priv->stations[sta_id].sta.mode ==
STA_CONTROL_MODIFY_MSK ? "Modified" : "Added",
addsta->sta.addr);
spin_unlock_irqrestore(&priv->sta_lock, flags);
return ret;
}
static void iwl_legacy_add_sta_callback(struct iwl_priv *priv,
struct iwl_device_cmd *cmd,
struct iwl_rx_packet *pkt)
{
struct iwl_legacy_addsta_cmd *addsta =
(struct iwl_legacy_addsta_cmd *)cmd->cmd.payload;
iwl_legacy_process_add_sta_resp(priv, addsta, pkt, false);
}
int iwl_legacy_send_add_sta(struct iwl_priv *priv,
struct iwl_legacy_addsta_cmd *sta, u8 flags)
{
struct iwl_rx_packet *pkt = NULL;
int ret = 0;
u8 data[sizeof(*sta)];
struct iwl_host_cmd cmd = {
.id = REPLY_ADD_STA,
.flags = flags,
.data = data,
};
u8 sta_id __maybe_unused = sta->sta.sta_id;
IWL_DEBUG_INFO(priv, "Adding sta %u (%pM) %ssynchronously\n",
sta_id, sta->sta.addr, flags & CMD_ASYNC ? "a" : "");
if (flags & CMD_ASYNC)
cmd.callback = iwl_legacy_add_sta_callback;
else {
cmd.flags |= CMD_WANT_SKB;
might_sleep();
}
cmd.len = priv->cfg->ops->utils->build_addsta_hcmd(sta, data);
ret = iwl_legacy_send_cmd(priv, &cmd);
if (ret || (flags & CMD_ASYNC))
return ret;
if (ret == 0) {
pkt = (struct iwl_rx_packet *)cmd.reply_page;
ret = iwl_legacy_process_add_sta_resp(priv, sta, pkt, true);
}
iwl_legacy_free_pages(priv, cmd.reply_page);
return ret;
}
static void iwl_legacy_set_ht_add_station(struct iwl_priv *priv, u8 index,
struct ieee80211_sta *sta,
struct iwl_rxon_context *ctx)
{
struct ieee80211_sta_ht_cap *sta_ht_inf = &sta->ht_cap;
__le32 sta_flags;
u8 mimo_ps_mode;
if (!sta || !sta_ht_inf->ht_supported)
goto done;
mimo_ps_mode = (sta_ht_inf->cap & IEEE80211_HT_CAP_SM_PS) >> 2;
IWL_DEBUG_ASSOC(priv, "spatial multiplexing power save mode: %s\n",
(mimo_ps_mode == WLAN_HT_CAP_SM_PS_STATIC) ?
"static" :
(mimo_ps_mode == WLAN_HT_CAP_SM_PS_DYNAMIC) ?
"dynamic" : "disabled");
sta_flags = priv->stations[index].sta.station_flags;
sta_flags &= ~(STA_FLG_RTS_MIMO_PROT_MSK | STA_FLG_MIMO_DIS_MSK);
switch (mimo_ps_mode) {
case WLAN_HT_CAP_SM_PS_STATIC:
sta_flags |= STA_FLG_MIMO_DIS_MSK;
break;
case WLAN_HT_CAP_SM_PS_DYNAMIC:
sta_flags |= STA_FLG_RTS_MIMO_PROT_MSK;
break;
case WLAN_HT_CAP_SM_PS_DISABLED:
break;
default:
IWL_WARN(priv, "Invalid MIMO PS mode %d\n", mimo_ps_mode);
break;
}
sta_flags |= cpu_to_le32(
(u32)sta_ht_inf->ampdu_factor << STA_FLG_MAX_AGG_SIZE_POS);
sta_flags |= cpu_to_le32(
(u32)sta_ht_inf->ampdu_density << STA_FLG_AGG_MPDU_DENSITY_POS);
if (iwl_legacy_is_ht40_tx_allowed(priv, ctx, &sta->ht_cap))
sta_flags |= STA_FLG_HT40_EN_MSK;
else
sta_flags &= ~STA_FLG_HT40_EN_MSK;
priv->stations[index].sta.station_flags = sta_flags;
done:
return;
}
u8 iwl_legacy_prep_station(struct iwl_priv *priv, struct iwl_rxon_context *ctx,
const u8 *addr, bool is_ap, struct ieee80211_sta *sta)
{
struct iwl_station_entry *station;
int i;
u8 sta_id = IWL_INVALID_STATION;
u16 rate;
if (is_ap)
sta_id = ctx->ap_sta_id;
else if (is_broadcast_ether_addr(addr))
sta_id = ctx->bcast_sta_id;
else
for (i = IWL_STA_ID; i < priv->hw_params.max_stations; i++) {
if (!compare_ether_addr(priv->stations[i].sta.sta.addr,
addr)) {
sta_id = i;
break;
}
if (!priv->stations[i].used &&
sta_id == IWL_INVALID_STATION)
sta_id = i;
}
if (unlikely(sta_id == IWL_INVALID_STATION))
return sta_id;
if (priv->stations[sta_id].used & IWL_STA_UCODE_INPROGRESS) {
IWL_DEBUG_INFO(priv,
"STA %d already in process of being added.\n",
sta_id);
return sta_id;
}
if ((priv->stations[sta_id].used & IWL_STA_DRIVER_ACTIVE) &&
(priv->stations[sta_id].used & IWL_STA_UCODE_ACTIVE) &&
!compare_ether_addr(priv->stations[sta_id].sta.sta.addr, addr)) {
IWL_DEBUG_ASSOC(priv,
"STA %d (%pM) already added, not adding again.\n",
sta_id, addr);
return sta_id;
}
station = &priv->stations[sta_id];
station->used = IWL_STA_DRIVER_ACTIVE;
IWL_DEBUG_ASSOC(priv, "Add STA to driver ID %d: %pM\n",
sta_id, addr);
priv->num_stations++;
memset(&station->sta, 0, sizeof(struct iwl_legacy_addsta_cmd));
memcpy(station->sta.sta.addr, addr, ETH_ALEN);
station->sta.mode = 0;
station->sta.sta.sta_id = sta_id;
station->sta.station_flags = ctx->station_flags;
station->ctxid = ctx->ctxid;
if (sta) {
struct iwl_station_priv_common *sta_priv;
sta_priv = (void *)sta->drv_priv;
sta_priv->ctx = ctx;
}
iwl_legacy_set_ht_add_station(priv, sta_id, sta, ctx);
rate = (priv->band == IEEE80211_BAND_5GHZ) ?
IWL_RATE_6M_PLCP : IWL_RATE_1M_PLCP;
station->sta.rate_n_flags = cpu_to_le16(rate | RATE_MCS_ANT_AB_MSK);
return sta_id;
}
int
iwl_legacy_add_station_common(struct iwl_priv *priv,
struct iwl_rxon_context *ctx,
const u8 *addr, bool is_ap,
struct ieee80211_sta *sta, u8 *sta_id_r)
{
unsigned long flags_spin;
int ret = 0;
u8 sta_id;
struct iwl_legacy_addsta_cmd sta_cmd;
*sta_id_r = 0;
spin_lock_irqsave(&priv->sta_lock, flags_spin);
sta_id = iwl_legacy_prep_station(priv, ctx, addr, is_ap, sta);
if (sta_id == IWL_INVALID_STATION) {
IWL_ERR(priv, "Unable to prepare station %pM for addition\n",
addr);
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
return -EINVAL;
}
if (priv->stations[sta_id].used & IWL_STA_UCODE_INPROGRESS) {
IWL_DEBUG_INFO(priv,
"STA %d already in process of being added.\n",
sta_id);
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
return -EEXIST;
}
if ((priv->stations[sta_id].used & IWL_STA_DRIVER_ACTIVE) &&
(priv->stations[sta_id].used & IWL_STA_UCODE_ACTIVE)) {
IWL_DEBUG_ASSOC(priv,
"STA %d (%pM) already added, not adding again.\n",
sta_id, addr);
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
return -EEXIST;
}
priv->stations[sta_id].used |= IWL_STA_UCODE_INPROGRESS;
memcpy(&sta_cmd, &priv->stations[sta_id].sta,
sizeof(struct iwl_legacy_addsta_cmd));
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
ret = iwl_legacy_send_add_sta(priv, &sta_cmd, CMD_SYNC);
if (ret) {
spin_lock_irqsave(&priv->sta_lock, flags_spin);
IWL_ERR(priv, "Adding station %pM failed.\n",
priv->stations[sta_id].sta.sta.addr);
priv->stations[sta_id].used &= ~IWL_STA_DRIVER_ACTIVE;
priv->stations[sta_id].used &= ~IWL_STA_UCODE_INPROGRESS;
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
}
*sta_id_r = sta_id;
return ret;
}
static void iwl_legacy_sta_ucode_deactivate(struct iwl_priv *priv, u8 sta_id)
{
if ((priv->stations[sta_id].used &
(IWL_STA_UCODE_ACTIVE | IWL_STA_DRIVER_ACTIVE)) !=
IWL_STA_UCODE_ACTIVE)
IWL_ERR(priv, "removed non active STA %u\n", sta_id);
priv->stations[sta_id].used &= ~IWL_STA_UCODE_ACTIVE;
memset(&priv->stations[sta_id], 0, sizeof(struct iwl_station_entry));
IWL_DEBUG_ASSOC(priv, "Removed STA %u\n", sta_id);
}
static int iwl_legacy_send_remove_station(struct iwl_priv *priv,
const u8 *addr, int sta_id,
bool temporary)
{
struct iwl_rx_packet *pkt;
int ret;
unsigned long flags_spin;
struct iwl_rem_sta_cmd rm_sta_cmd;
struct iwl_host_cmd cmd = {
.id = REPLY_REMOVE_STA,
.len = sizeof(struct iwl_rem_sta_cmd),
.flags = CMD_SYNC,
.data = &rm_sta_cmd,
};
memset(&rm_sta_cmd, 0, sizeof(rm_sta_cmd));
rm_sta_cmd.num_sta = 1;
memcpy(&rm_sta_cmd.addr, addr, ETH_ALEN);
cmd.flags |= CMD_WANT_SKB;
ret = iwl_legacy_send_cmd(priv, &cmd);
if (ret)
return ret;
pkt = (struct iwl_rx_packet *)cmd.reply_page;
if (pkt->hdr.flags & IWL_CMD_FAILED_MSK) {
IWL_ERR(priv, "Bad return from REPLY_REMOVE_STA (0x%08X)\n",
pkt->hdr.flags);
ret = -EIO;
}
if (!ret) {
switch (pkt->u.rem_sta.status) {
case REM_STA_SUCCESS_MSK:
if (!temporary) {
spin_lock_irqsave(&priv->sta_lock, flags_spin);
iwl_legacy_sta_ucode_deactivate(priv, sta_id);
spin_unlock_irqrestore(&priv->sta_lock,
flags_spin);
}
IWL_DEBUG_ASSOC(priv, "REPLY_REMOVE_STA PASSED\n");
break;
default:
ret = -EIO;
IWL_ERR(priv, "REPLY_REMOVE_STA failed\n");
break;
}
}
iwl_legacy_free_pages(priv, cmd.reply_page);
return ret;
}
int iwl_legacy_remove_station(struct iwl_priv *priv, const u8 sta_id,
const u8 *addr)
{
unsigned long flags;
if (!iwl_legacy_is_ready(priv)) {
IWL_DEBUG_INFO(priv,
"Unable to remove station %pM, device not ready.\n",
addr);
return 0;
}
IWL_DEBUG_ASSOC(priv, "Removing STA from driver:%d %pM\n",
sta_id, addr);
if (WARN_ON(sta_id == IWL_INVALID_STATION))
return -EINVAL;
spin_lock_irqsave(&priv->sta_lock, flags);
if (!(priv->stations[sta_id].used & IWL_STA_DRIVER_ACTIVE)) {
IWL_DEBUG_INFO(priv, "Removing %pM but non DRIVER active\n",
addr);
goto out_err;
}
if (!(priv->stations[sta_id].used & IWL_STA_UCODE_ACTIVE)) {
IWL_DEBUG_INFO(priv, "Removing %pM but non UCODE active\n",
addr);
goto out_err;
}
if (priv->stations[sta_id].used & IWL_STA_LOCAL) {
kfree(priv->stations[sta_id].lq);
priv->stations[sta_id].lq = NULL;
}
priv->stations[sta_id].used &= ~IWL_STA_DRIVER_ACTIVE;
priv->num_stations--;
BUG_ON(priv->num_stations < 0);
spin_unlock_irqrestore(&priv->sta_lock, flags);
return iwl_legacy_send_remove_station(priv, addr, sta_id, false);
out_err:
spin_unlock_irqrestore(&priv->sta_lock, flags);
return -EINVAL;
}
void iwl_legacy_clear_ucode_stations(struct iwl_priv *priv,
struct iwl_rxon_context *ctx)
{
int i;
unsigned long flags_spin;
bool cleared = false;
IWL_DEBUG_INFO(priv, "Clearing ucode stations in driver\n");
spin_lock_irqsave(&priv->sta_lock, flags_spin);
for (i = 0; i < priv->hw_params.max_stations; i++) {
if (ctx && ctx->ctxid != priv->stations[i].ctxid)
continue;
if (priv->stations[i].used & IWL_STA_UCODE_ACTIVE) {
IWL_DEBUG_INFO(priv,
"Clearing ucode active for station %d\n", i);
priv->stations[i].used &= ~IWL_STA_UCODE_ACTIVE;
cleared = true;
}
}
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
if (!cleared)
IWL_DEBUG_INFO(priv,
"No active stations found to be cleared\n");
}
void
iwl_legacy_restore_stations(struct iwl_priv *priv, struct iwl_rxon_context *ctx)
{
struct iwl_legacy_addsta_cmd sta_cmd;
struct iwl_link_quality_cmd lq;
unsigned long flags_spin;
int i;
bool found = false;
int ret;
bool send_lq;
if (!iwl_legacy_is_ready(priv)) {
IWL_DEBUG_INFO(priv,
"Not ready yet, not restoring any stations.\n");
return;
}
IWL_DEBUG_ASSOC(priv, "Restoring all known stations ... start.\n");
spin_lock_irqsave(&priv->sta_lock, flags_spin);
for (i = 0; i < priv->hw_params.max_stations; i++) {
if (ctx->ctxid != priv->stations[i].ctxid)
continue;
if ((priv->stations[i].used & IWL_STA_DRIVER_ACTIVE) &&
!(priv->stations[i].used & IWL_STA_UCODE_ACTIVE)) {
IWL_DEBUG_ASSOC(priv, "Restoring sta %pM\n",
priv->stations[i].sta.sta.addr);
priv->stations[i].sta.mode = 0;
priv->stations[i].used |= IWL_STA_UCODE_INPROGRESS;
found = true;
}
}
for (i = 0; i < priv->hw_params.max_stations; i++) {
if ((priv->stations[i].used & IWL_STA_UCODE_INPROGRESS)) {
memcpy(&sta_cmd, &priv->stations[i].sta,
sizeof(struct iwl_legacy_addsta_cmd));
send_lq = false;
if (priv->stations[i].lq) {
memcpy(&lq, priv->stations[i].lq,
sizeof(struct iwl_link_quality_cmd));
send_lq = true;
}
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
ret = iwl_legacy_send_add_sta(priv, &sta_cmd, CMD_SYNC);
if (ret) {
spin_lock_irqsave(&priv->sta_lock, flags_spin);
IWL_ERR(priv, "Adding station %pM failed.\n",
priv->stations[i].sta.sta.addr);
priv->stations[i].used &=
~IWL_STA_DRIVER_ACTIVE;
priv->stations[i].used &=
~IWL_STA_UCODE_INPROGRESS;
spin_unlock_irqrestore(&priv->sta_lock,
flags_spin);
}
if (send_lq)
iwl_legacy_send_lq_cmd(priv, ctx, &lq,
CMD_SYNC, true);
spin_lock_irqsave(&priv->sta_lock, flags_spin);
priv->stations[i].used &= ~IWL_STA_UCODE_INPROGRESS;
}
}
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
if (!found)
IWL_DEBUG_INFO(priv, "Restoring all known stations"
" .... no stations to be restored.\n");
else
IWL_DEBUG_INFO(priv, "Restoring all known stations"
" .... complete.\n");
}
int iwl_legacy_get_free_ucode_key_index(struct iwl_priv *priv)
{
int i;
for (i = 0; i < priv->sta_key_max_num; i++)
if (!test_and_set_bit(i, &priv->ucode_key_table))
return i;
return WEP_INVALID_OFFSET;
}
void iwl_legacy_dealloc_bcast_stations(struct iwl_priv *priv)
{
unsigned long flags;
int i;
spin_lock_irqsave(&priv->sta_lock, flags);
for (i = 0; i < priv->hw_params.max_stations; i++) {
if (!(priv->stations[i].used & IWL_STA_BCAST))
continue;
priv->stations[i].used &= ~IWL_STA_UCODE_ACTIVE;
priv->num_stations--;
BUG_ON(priv->num_stations < 0);
kfree(priv->stations[i].lq);
priv->stations[i].lq = NULL;
}
spin_unlock_irqrestore(&priv->sta_lock, flags);
}
static void iwl_legacy_dump_lq_cmd(struct iwl_priv *priv,
struct iwl_link_quality_cmd *lq)
{
int i;
IWL_DEBUG_RATE(priv, "lq station id 0x%x\n", lq->sta_id);
IWL_DEBUG_RATE(priv, "lq ant 0x%X 0x%X\n",
lq->general_params.single_stream_ant_msk,
lq->general_params.dual_stream_ant_msk);
for (i = 0; i < LINK_QUAL_MAX_RETRY_NUM; i++)
IWL_DEBUG_RATE(priv, "lq index %d 0x%X\n",
i, lq->rs_table[i].rate_n_flags);
}
static inline void iwl_legacy_dump_lq_cmd(struct iwl_priv *priv,
struct iwl_link_quality_cmd *lq)
{
}
static bool iwl_legacy_is_lq_table_valid(struct iwl_priv *priv,
struct iwl_rxon_context *ctx,
struct iwl_link_quality_cmd *lq)
{
int i;
if (ctx->ht.enabled)
return true;
IWL_DEBUG_INFO(priv, "Channel %u is not an HT channel\n",
ctx->active.channel);
for (i = 0; i < LINK_QUAL_MAX_RETRY_NUM; i++) {
if (le32_to_cpu(lq->rs_table[i].rate_n_flags) &
RATE_MCS_HT_MSK) {
IWL_DEBUG_INFO(priv,
"index %d of LQ expects HT channel\n",
i);
return false;
}
}
return true;
}
int iwl_legacy_send_lq_cmd(struct iwl_priv *priv, struct iwl_rxon_context *ctx,
struct iwl_link_quality_cmd *lq, u8 flags, bool init)
{
int ret = 0;
unsigned long flags_spin;
struct iwl_host_cmd cmd = {
.id = REPLY_TX_LINK_QUALITY_CMD,
.len = sizeof(struct iwl_link_quality_cmd),
.flags = flags,
.data = lq,
};
if (WARN_ON(lq->sta_id == IWL_INVALID_STATION))
return -EINVAL;
spin_lock_irqsave(&priv->sta_lock, flags_spin);
if (!(priv->stations[lq->sta_id].used & IWL_STA_DRIVER_ACTIVE)) {
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
return -EINVAL;
}
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
iwl_legacy_dump_lq_cmd(priv, lq);
BUG_ON(init && (cmd.flags & CMD_ASYNC));
if (iwl_legacy_is_lq_table_valid(priv, ctx, lq))
ret = iwl_legacy_send_cmd(priv, &cmd);
else
ret = -EINVAL;
if (cmd.flags & CMD_ASYNC)
return ret;
if (init) {
IWL_DEBUG_INFO(priv, "init LQ command complete,"
" clearing sta addition status for sta %d\n",
lq->sta_id);
spin_lock_irqsave(&priv->sta_lock, flags_spin);
priv->stations[lq->sta_id].used &= ~IWL_STA_UCODE_INPROGRESS;
spin_unlock_irqrestore(&priv->sta_lock, flags_spin);
}
return ret;
}
int iwl_legacy_mac_sta_remove(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct iwl_priv *priv = hw->priv;
struct iwl_station_priv_common *sta_common = (void *)sta->drv_priv;
int ret;
IWL_DEBUG_INFO(priv, "received request to remove station %pM\n",
sta->addr);
mutex_lock(&priv->mutex);
IWL_DEBUG_INFO(priv, "proceeding to remove station %pM\n",
sta->addr);
ret = iwl_legacy_remove_station(priv, sta_common->sta_id, sta->addr);
if (ret)
IWL_ERR(priv, "Error removing station %pM\n",
sta->addr);
mutex_unlock(&priv->mutex);
return ret;
}
