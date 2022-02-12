static inline
void mesh_plink_inc_estab_count(struct ieee80211_sub_if_data *sdata)
{
atomic_inc(&sdata->u.mesh.mshstats.estab_plinks);
mesh_accept_plinks_update(sdata);
}
static inline
void mesh_plink_dec_estab_count(struct ieee80211_sub_if_data *sdata)
{
atomic_dec(&sdata->u.mesh.mshstats.estab_plinks);
mesh_accept_plinks_update(sdata);
}
static inline void mesh_plink_fsm_restart(struct sta_info *sta)
{
sta->plink_state = NL80211_PLINK_LISTEN;
sta->llid = sta->plid = sta->reason = 0;
sta->plink_retries = 0;
}
static struct sta_info *mesh_plink_alloc(struct ieee80211_sub_if_data *sdata,
u8 *hw_addr, u32 rates)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
if (local->num_sta >= MESH_MAX_PLINKS)
return NULL;
sta = sta_info_alloc(sdata, hw_addr, GFP_KERNEL);
if (!sta)
return NULL;
sta->flags = WLAN_STA_AUTHORIZED | WLAN_STA_AUTH;
sta->sta.supp_rates[local->hw.conf.channel->band] = rates;
rate_control_rate_init(sta);
return sta;
}
static bool __mesh_plink_deactivate(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
bool deactivated = false;
if (sta->plink_state == NL80211_PLINK_ESTAB) {
mesh_plink_dec_estab_count(sdata);
deactivated = true;
}
sta->plink_state = NL80211_PLINK_BLOCKED;
mesh_path_flush_by_nexthop(sta);
return deactivated;
}
void mesh_plink_deactivate(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
bool deactivated;
spin_lock_bh(&sta->lock);
deactivated = __mesh_plink_deactivate(sta);
spin_unlock_bh(&sta->lock);
if (deactivated)
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_BEACON);
}
static int mesh_plink_frame_tx(struct ieee80211_sub_if_data *sdata,
enum plink_frame_type action, u8 *da, __le16 llid, __le16 plid,
__le16 reason) {
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb = dev_alloc_skb(local->hw.extra_tx_headroom + 400 +
sdata->u.mesh.ie_len);
struct ieee80211_mgmt *mgmt;
bool include_plid = false;
static const u8 meshpeeringproto[] = { 0x00, 0x0F, 0xAC, 0x2A };
u8 *pos;
int ie_len;
if (!skb)
return -1;
skb_reserve(skb, local->hw.extra_tx_headroom);
mgmt = (struct ieee80211_mgmt *)
skb_put(skb, 25 + sizeof(mgmt->u.action.u.plink_action));
memset(mgmt, 0, 25 + sizeof(mgmt->u.action.u.plink_action));
mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
memcpy(mgmt->da, da, ETH_ALEN);
memcpy(mgmt->sa, sdata->vif.addr, ETH_ALEN);
memcpy(mgmt->bssid, sdata->vif.addr, ETH_ALEN);
mgmt->u.action.category = WLAN_CATEGORY_MESH_ACTION;
mgmt->u.action.u.plink_action.action_code = action;
if (action == PLINK_CLOSE)
mgmt->u.action.u.plink_action.aux = reason;
else {
mgmt->u.action.u.plink_action.aux = cpu_to_le16(0x0);
if (action == PLINK_CONFIRM) {
pos = skb_put(skb, 4);
memset(pos, 0, 2);
memcpy(pos + 2, &plid, 2);
}
mesh_mgmt_ies_add(skb, sdata);
}
switch (action) {
case PLINK_OPEN:
ie_len = 6;
break;
case PLINK_CONFIRM:
ie_len = 8;
include_plid = true;
break;
case PLINK_CLOSE:
default:
if (!plid)
ie_len = 8;
else {
ie_len = 10;
include_plid = true;
}
break;
}
pos = skb_put(skb, 2 + ie_len);
*pos++ = WLAN_EID_PEER_LINK;
*pos++ = ie_len;
memcpy(pos, meshpeeringproto, sizeof(meshpeeringproto));
pos += 4;
memcpy(pos, &llid, 2);
if (include_plid) {
pos += 2;
memcpy(pos, &plid, 2);
}
if (action == PLINK_CLOSE) {
pos += 2;
memcpy(pos, &reason, 2);
}
ieee80211_tx_skb(sdata, skb);
return 0;
}
void mesh_neighbour_update(u8 *hw_addr, u32 rates,
struct ieee80211_sub_if_data *sdata,
struct ieee802_11_elems *elems)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
rcu_read_lock();
sta = sta_info_get(sdata, hw_addr);
if (!sta) {
rcu_read_unlock();
if (sdata->u.mesh.security & IEEE80211_MESH_SEC_AUTHED)
cfg80211_notify_new_peer_candidate(sdata->dev, hw_addr,
elems->ie_start, elems->total_len,
GFP_KERNEL);
else
sta = mesh_plink_alloc(sdata, hw_addr, rates);
if (!sta)
return;
if (sta_info_insert_rcu(sta)) {
rcu_read_unlock();
return;
}
}
sta->last_rx = jiffies;
sta->sta.supp_rates[local->hw.conf.channel->band] = rates;
if (mesh_peer_accepts_plinks(elems) &&
sta->plink_state == NL80211_PLINK_LISTEN &&
sdata->u.mesh.accepting_plinks &&
sdata->u.mesh.mshcfg.auto_open_plinks)
mesh_plink_open(sta);
rcu_read_unlock();
}
static void mesh_plink_timer(unsigned long data)
{
struct sta_info *sta;
__le16 llid, plid, reason;
struct ieee80211_sub_if_data *sdata;
sta = (struct sta_info *) data;
if (sta->sdata->local->quiescing) {
sta->plink_timer_was_running = true;
return;
}
spin_lock_bh(&sta->lock);
if (sta->ignore_plink_timer) {
sta->ignore_plink_timer = false;
spin_unlock_bh(&sta->lock);
return;
}
mpl_dbg("Mesh plink timer for %pM fired on state %d\n",
sta->sta.addr, sta->plink_state);
reason = 0;
llid = sta->llid;
plid = sta->plid;
sdata = sta->sdata;
switch (sta->plink_state) {
case NL80211_PLINK_OPN_RCVD:
case NL80211_PLINK_OPN_SNT:
if (sta->plink_retries < dot11MeshMaxRetries(sdata)) {
u32 rand;
mpl_dbg("Mesh plink for %pM (retry, timeout): %d %d\n",
sta->sta.addr, sta->plink_retries,
sta->plink_timeout);
get_random_bytes(&rand, sizeof(u32));
sta->plink_timeout = sta->plink_timeout +
rand % sta->plink_timeout;
++sta->plink_retries;
mod_plink_timer(sta, sta->plink_timeout);
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_OPEN, sta->sta.addr, llid,
0, 0);
break;
}
reason = cpu_to_le16(MESH_MAX_RETRIES);
case NL80211_PLINK_CNF_RCVD:
if (!reason)
reason = cpu_to_le16(MESH_CONFIRM_TIMEOUT);
sta->plink_state = NL80211_PLINK_HOLDING;
mod_plink_timer(sta, dot11MeshHoldingTimeout(sdata));
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr, llid, plid,
reason);
break;
case NL80211_PLINK_HOLDING:
del_timer(&sta->plink_timer);
mesh_plink_fsm_restart(sta);
spin_unlock_bh(&sta->lock);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
}
void mesh_plink_quiesce(struct sta_info *sta)
{
if (del_timer_sync(&sta->plink_timer))
sta->plink_timer_was_running = true;
}
void mesh_plink_restart(struct sta_info *sta)
{
if (sta->plink_timer_was_running) {
add_timer(&sta->plink_timer);
sta->plink_timer_was_running = false;
}
}
static inline void mesh_plink_timer_set(struct sta_info *sta, int timeout)
{
sta->plink_timer.expires = jiffies + (HZ * timeout / 1000);
sta->plink_timer.data = (unsigned long) sta;
sta->plink_timer.function = mesh_plink_timer;
sta->plink_timeout = timeout;
add_timer(&sta->plink_timer);
}
int mesh_plink_open(struct sta_info *sta)
{
__le16 llid;
struct ieee80211_sub_if_data *sdata = sta->sdata;
if (!test_sta_flags(sta, WLAN_STA_AUTH))
return -EPERM;
spin_lock_bh(&sta->lock);
get_random_bytes(&llid, 2);
sta->llid = llid;
if (sta->plink_state != NL80211_PLINK_LISTEN) {
spin_unlock_bh(&sta->lock);
return -EBUSY;
}
sta->plink_state = NL80211_PLINK_OPN_SNT;
mesh_plink_timer_set(sta, dot11MeshRetryTimeout(sdata));
spin_unlock_bh(&sta->lock);
mpl_dbg("Mesh plink: starting establishment with %pM\n",
sta->sta.addr);
return mesh_plink_frame_tx(sdata, PLINK_OPEN,
sta->sta.addr, llid, 0, 0);
}
void mesh_plink_block(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
bool deactivated;
spin_lock_bh(&sta->lock);
deactivated = __mesh_plink_deactivate(sta);
sta->plink_state = NL80211_PLINK_BLOCKED;
spin_unlock_bh(&sta->lock);
if (deactivated)
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_BEACON);
}
void mesh_rx_plink_frame(struct ieee80211_sub_if_data *sdata, struct ieee80211_mgmt *mgmt,
size_t len, struct ieee80211_rx_status *rx_status)
{
struct ieee80211_local *local = sdata->local;
struct ieee802_11_elems elems;
struct sta_info *sta;
enum plink_event event;
enum plink_frame_type ftype;
size_t baselen;
bool deactivated, matches_local = true;
u8 ie_len;
u8 *baseaddr;
__le16 plid, llid, reason;
#ifdef CONFIG_MAC80211_VERBOSE_MPL_DEBUG
static const char *mplstates[] = {
[NL80211_PLINK_LISTEN] = "LISTEN",
[NL80211_PLINK_OPN_SNT] = "OPN-SNT",
[NL80211_PLINK_OPN_RCVD] = "OPN-RCVD",
[NL80211_PLINK_CNF_RCVD] = "CNF_RCVD",
[NL80211_PLINK_ESTAB] = "ESTAB",
[NL80211_PLINK_HOLDING] = "HOLDING",
[NL80211_PLINK_BLOCKED] = "BLOCKED"
};
#endif
if (len < IEEE80211_MIN_ACTION_SIZE + 3)
return;
if (is_multicast_ether_addr(mgmt->da)) {
mpl_dbg("Mesh plink: ignore frame from multicast address");
return;
}
baseaddr = mgmt->u.action.u.plink_action.variable;
baselen = (u8 *) mgmt->u.action.u.plink_action.variable - (u8 *) mgmt;
if (mgmt->u.action.u.plink_action.action_code == PLINK_CONFIRM) {
baseaddr += 4;
baselen += 4;
}
ieee802_11_parse_elems(baseaddr, len - baselen, &elems);
if (!elems.peer_link) {
mpl_dbg("Mesh plink: missing necessary peer link ie\n");
return;
}
if (elems.rsn_len &&
sdata->u.mesh.security == IEEE80211_MESH_SEC_NONE) {
mpl_dbg("Mesh plink: can't establish link with secure peer\n");
return;
}
ftype = mgmt->u.action.u.plink_action.action_code;
ie_len = elems.peer_link_len;
if ((ftype == PLINK_OPEN && ie_len != 6) ||
(ftype == PLINK_CONFIRM && ie_len != 8) ||
(ftype == PLINK_CLOSE && ie_len != 8 && ie_len != 10)) {
mpl_dbg("Mesh plink: incorrect plink ie length %d %d\n",
ftype, ie_len);
return;
}
if (ftype != PLINK_CLOSE && (!elems.mesh_id || !elems.mesh_config)) {
mpl_dbg("Mesh plink: missing necessary ie\n");
return;
}
memcpy(&plid, PLINK_GET_LLID(elems.peer_link), 2);
if (ftype == PLINK_CONFIRM || (ftype == PLINK_CLOSE && ie_len == 10))
memcpy(&llid, PLINK_GET_PLID(elems.peer_link), 2);
rcu_read_lock();
sta = sta_info_get(sdata, mgmt->sa);
if (!sta && ftype != PLINK_OPEN) {
mpl_dbg("Mesh plink: cls or cnf from unknown peer\n");
rcu_read_unlock();
return;
}
if (sta && !test_sta_flags(sta, WLAN_STA_AUTH)) {
mpl_dbg("Mesh plink: Action frame from non-authed peer\n");
rcu_read_unlock();
return;
}
if (sta && sta->plink_state == NL80211_PLINK_BLOCKED) {
rcu_read_unlock();
return;
}
event = PLINK_UNDEFINED;
if (ftype != PLINK_CLOSE && (!mesh_matches_local(&elems, sdata))) {
matches_local = false;
switch (ftype) {
case PLINK_OPEN:
event = OPN_RJCT;
break;
case PLINK_CONFIRM:
event = CNF_RJCT;
break;
case PLINK_CLOSE:
break;
}
}
if (!sta && !matches_local) {
rcu_read_unlock();
reason = cpu_to_le16(MESH_CAPABILITY_POLICY_VIOLATION);
llid = 0;
mesh_plink_frame_tx(sdata, PLINK_CLOSE, mgmt->sa, llid,
plid, reason);
return;
} else if (!sta) {
u32 rates;
rcu_read_unlock();
if (!mesh_plink_free_count(sdata)) {
mpl_dbg("Mesh plink error: no more free plinks\n");
return;
}
rates = ieee80211_sta_get_rates(local, &elems, rx_status->band);
sta = mesh_plink_alloc(sdata, mgmt->sa, rates);
if (!sta) {
mpl_dbg("Mesh plink error: plink table full\n");
return;
}
if (sta_info_insert_rcu(sta)) {
rcu_read_unlock();
return;
}
event = OPN_ACPT;
spin_lock_bh(&sta->lock);
} else if (matches_local) {
spin_lock_bh(&sta->lock);
switch (ftype) {
case PLINK_OPEN:
if (!mesh_plink_free_count(sdata) ||
(sta->plid && sta->plid != plid))
event = OPN_IGNR;
else
event = OPN_ACPT;
break;
case PLINK_CONFIRM:
if (!mesh_plink_free_count(sdata) ||
(sta->llid != llid || sta->plid != plid))
event = CNF_IGNR;
else
event = CNF_ACPT;
break;
case PLINK_CLOSE:
if (sta->plink_state == NL80211_PLINK_ESTAB)
event = CLS_ACPT;
else if (sta->plid != plid)
event = CLS_IGNR;
else if (ie_len == 7 && sta->llid != llid)
event = CLS_IGNR;
else
event = CLS_ACPT;
break;
default:
mpl_dbg("Mesh plink: unknown frame subtype\n");
spin_unlock_bh(&sta->lock);
rcu_read_unlock();
return;
}
} else {
spin_lock_bh(&sta->lock);
}
mpl_dbg("Mesh plink (peer, state, llid, plid, event): %pM %s %d %d %d\n",
mgmt->sa, mplstates[sta->plink_state],
le16_to_cpu(sta->llid), le16_to_cpu(sta->plid),
event);
reason = 0;
switch (sta->plink_state) {
case NL80211_PLINK_LISTEN:
switch (event) {
case CLS_ACPT:
mesh_plink_fsm_restart(sta);
spin_unlock_bh(&sta->lock);
break;
case OPN_ACPT:
sta->plink_state = NL80211_PLINK_OPN_RCVD;
sta->plid = plid;
get_random_bytes(&llid, 2);
sta->llid = llid;
mesh_plink_timer_set(sta, dot11MeshRetryTimeout(sdata));
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_OPEN, sta->sta.addr, llid,
0, 0);
mesh_plink_frame_tx(sdata, PLINK_CONFIRM, sta->sta.addr,
llid, plid, 0);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
break;
case NL80211_PLINK_OPN_SNT:
switch (event) {
case OPN_RJCT:
case CNF_RJCT:
reason = cpu_to_le16(MESH_CAPABILITY_POLICY_VIOLATION);
case CLS_ACPT:
if (!reason)
reason = cpu_to_le16(MESH_CLOSE_RCVD);
sta->reason = reason;
sta->plink_state = NL80211_PLINK_HOLDING;
if (!mod_plink_timer(sta,
dot11MeshHoldingTimeout(sdata)))
sta->ignore_plink_timer = true;
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr, llid,
plid, reason);
break;
case OPN_ACPT:
sta->plink_state = NL80211_PLINK_OPN_RCVD;
sta->plid = plid;
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CONFIRM, sta->sta.addr, llid,
plid, 0);
break;
case CNF_ACPT:
sta->plink_state = NL80211_PLINK_CNF_RCVD;
if (!mod_plink_timer(sta,
dot11MeshConfirmTimeout(sdata)))
sta->ignore_plink_timer = true;
spin_unlock_bh(&sta->lock);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
break;
case NL80211_PLINK_OPN_RCVD:
switch (event) {
case OPN_RJCT:
case CNF_RJCT:
reason = cpu_to_le16(MESH_CAPABILITY_POLICY_VIOLATION);
case CLS_ACPT:
if (!reason)
reason = cpu_to_le16(MESH_CLOSE_RCVD);
sta->reason = reason;
sta->plink_state = NL80211_PLINK_HOLDING;
if (!mod_plink_timer(sta,
dot11MeshHoldingTimeout(sdata)))
sta->ignore_plink_timer = true;
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr, llid,
plid, reason);
break;
case OPN_ACPT:
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CONFIRM, sta->sta.addr, llid,
plid, 0);
break;
case CNF_ACPT:
del_timer(&sta->plink_timer);
sta->plink_state = NL80211_PLINK_ESTAB;
spin_unlock_bh(&sta->lock);
mesh_plink_inc_estab_count(sdata);
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_BEACON);
mpl_dbg("Mesh plink with %pM ESTABLISHED\n",
sta->sta.addr);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
break;
case NL80211_PLINK_CNF_RCVD:
switch (event) {
case OPN_RJCT:
case CNF_RJCT:
reason = cpu_to_le16(MESH_CAPABILITY_POLICY_VIOLATION);
case CLS_ACPT:
if (!reason)
reason = cpu_to_le16(MESH_CLOSE_RCVD);
sta->reason = reason;
sta->plink_state = NL80211_PLINK_HOLDING;
if (!mod_plink_timer(sta,
dot11MeshHoldingTimeout(sdata)))
sta->ignore_plink_timer = true;
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr, llid,
plid, reason);
break;
case OPN_ACPT:
del_timer(&sta->plink_timer);
sta->plink_state = NL80211_PLINK_ESTAB;
spin_unlock_bh(&sta->lock);
mesh_plink_inc_estab_count(sdata);
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_BEACON);
mpl_dbg("Mesh plink with %pM ESTABLISHED\n",
sta->sta.addr);
mesh_plink_frame_tx(sdata, PLINK_CONFIRM, sta->sta.addr, llid,
plid, 0);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
break;
case NL80211_PLINK_ESTAB:
switch (event) {
case CLS_ACPT:
reason = cpu_to_le16(MESH_CLOSE_RCVD);
sta->reason = reason;
deactivated = __mesh_plink_deactivate(sta);
sta->plink_state = NL80211_PLINK_HOLDING;
llid = sta->llid;
mod_plink_timer(sta, dot11MeshHoldingTimeout(sdata));
spin_unlock_bh(&sta->lock);
if (deactivated)
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_BEACON);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr, llid,
plid, reason);
break;
case OPN_ACPT:
llid = sta->llid;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CONFIRM, sta->sta.addr, llid,
plid, 0);
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
break;
case NL80211_PLINK_HOLDING:
switch (event) {
case CLS_ACPT:
if (del_timer(&sta->plink_timer))
sta->ignore_plink_timer = 1;
mesh_plink_fsm_restart(sta);
spin_unlock_bh(&sta->lock);
break;
case OPN_ACPT:
case CNF_ACPT:
case OPN_RJCT:
case CNF_RJCT:
llid = sta->llid;
reason = sta->reason;
spin_unlock_bh(&sta->lock);
mesh_plink_frame_tx(sdata, PLINK_CLOSE, sta->sta.addr,
llid, plid, reason);
break;
default:
spin_unlock_bh(&sta->lock);
}
break;
default:
spin_unlock_bh(&sta->lock);
break;
}
rcu_read_unlock();
}
