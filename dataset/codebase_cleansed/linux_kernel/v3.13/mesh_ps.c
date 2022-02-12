static struct sk_buff *mps_qos_null_get(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
struct ieee80211_hdr *nullfunc;
struct sk_buff *skb;
int size = sizeof(*nullfunc);
__le16 fc;
skb = dev_alloc_skb(local->hw.extra_tx_headroom + size + 2);
if (!skb)
return NULL;
skb_reserve(skb, local->hw.extra_tx_headroom);
nullfunc = (struct ieee80211_hdr *) skb_put(skb, size);
fc = cpu_to_le16(IEEE80211_FTYPE_DATA | IEEE80211_STYPE_QOS_NULLFUNC);
ieee80211_fill_mesh_addresses(nullfunc, &fc, sta->sta.addr,
sdata->vif.addr);
nullfunc->frame_control = fc;
nullfunc->duration_id = 0;
memcpy(nullfunc->addr1, sta->sta.addr, ETH_ALEN);
memset(skb_put(skb, 2), 0, 2);
ieee80211_mps_set_frame_flags(sdata, sta, nullfunc);
return skb;
}
static void mps_qos_null_tx(struct sta_info *sta)
{
struct sk_buff *skb;
skb = mps_qos_null_get(sta);
if (!skb)
return;
mps_dbg(sta->sdata, "announcing peer-specific power mode to %pM\n",
sta->sta.addr);
if (!test_sta_flag(sta, WLAN_STA_PS_STA)) {
u8 *qc = ieee80211_get_qos_ctl((void *) skb->data);
qc[0] |= IEEE80211_QOS_CTL_EOSP;
}
ieee80211_tx_skb(sta->sdata, skb);
}
u32 ieee80211_mps_local_status_update(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_if_mesh *ifmsh = &sdata->u.mesh;
struct sta_info *sta;
bool peering = false;
int light_sleep_cnt = 0;
int deep_sleep_cnt = 0;
u32 changed = 0;
enum nl80211_mesh_power_mode nonpeer_pm;
rcu_read_lock();
list_for_each_entry_rcu(sta, &sdata->local->sta_list, list) {
if (sdata != sta->sdata)
continue;
switch (sta->plink_state) {
case NL80211_PLINK_OPN_SNT:
case NL80211_PLINK_OPN_RCVD:
case NL80211_PLINK_CNF_RCVD:
peering = true;
break;
case NL80211_PLINK_ESTAB:
if (sta->local_pm == NL80211_MESH_POWER_LIGHT_SLEEP)
light_sleep_cnt++;
else if (sta->local_pm == NL80211_MESH_POWER_DEEP_SLEEP)
deep_sleep_cnt++;
break;
default:
break;
}
}
rcu_read_unlock();
if (peering) {
mps_dbg(sdata, "setting non-peer PM to active for peering\n");
nonpeer_pm = NL80211_MESH_POWER_ACTIVE;
} else if (light_sleep_cnt || deep_sleep_cnt) {
mps_dbg(sdata, "setting non-peer PM to deep sleep\n");
nonpeer_pm = NL80211_MESH_POWER_DEEP_SLEEP;
} else {
mps_dbg(sdata, "setting non-peer PM to user value\n");
nonpeer_pm = ifmsh->mshcfg.power_mode;
}
if (ifmsh->nonpeer_pm != nonpeer_pm ||
!ifmsh->ps_peers_light_sleep != !light_sleep_cnt ||
!ifmsh->ps_peers_deep_sleep != !deep_sleep_cnt)
changed = BSS_CHANGED_BEACON;
ifmsh->nonpeer_pm = nonpeer_pm;
ifmsh->ps_peers_light_sleep = light_sleep_cnt;
ifmsh->ps_peers_deep_sleep = deep_sleep_cnt;
return changed;
}
u32 ieee80211_mps_set_sta_local_pm(struct sta_info *sta,
enum nl80211_mesh_power_mode pm)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
if (sta->local_pm == pm)
return 0;
mps_dbg(sdata, "local STA operates in mode %d with %pM\n",
pm, sta->sta.addr);
sta->local_pm = pm;
if (sta->plink_state == NL80211_PLINK_ESTAB)
mps_qos_null_tx(sta);
return ieee80211_mps_local_status_update(sdata);
}
void ieee80211_mps_set_frame_flags(struct ieee80211_sub_if_data *sdata,
struct sta_info *sta,
struct ieee80211_hdr *hdr)
{
enum nl80211_mesh_power_mode pm;
u8 *qc;
if (WARN_ON(is_unicast_ether_addr(hdr->addr1) &&
ieee80211_is_data_qos(hdr->frame_control) &&
!sta))
return;
if (is_unicast_ether_addr(hdr->addr1) &&
ieee80211_is_data_qos(hdr->frame_control) &&
sta->plink_state == NL80211_PLINK_ESTAB)
pm = sta->local_pm;
else
pm = sdata->u.mesh.nonpeer_pm;
if (pm == NL80211_MESH_POWER_ACTIVE)
hdr->frame_control &= cpu_to_le16(~IEEE80211_FCTL_PM);
else
hdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_PM);
if (!ieee80211_is_data_qos(hdr->frame_control))
return;
qc = ieee80211_get_qos_ctl(hdr);
if ((is_unicast_ether_addr(hdr->addr1) &&
pm == NL80211_MESH_POWER_DEEP_SLEEP) ||
(is_multicast_ether_addr(hdr->addr1) &&
sdata->u.mesh.ps_peers_deep_sleep > 0))
qc[1] |= (IEEE80211_QOS_CTL_MESH_PS_LEVEL >> 8);
else
qc[1] &= ~(IEEE80211_QOS_CTL_MESH_PS_LEVEL >> 8);
}
void ieee80211_mps_sta_status_update(struct sta_info *sta)
{
enum nl80211_mesh_power_mode pm;
bool do_buffer;
if (sta->sta_state < IEEE80211_STA_ASSOC)
return;
if (sta->plink_state == NL80211_PLINK_ESTAB &&
sta->peer_pm != NL80211_MESH_POWER_UNKNOWN)
pm = sta->peer_pm;
else
pm = sta->nonpeer_pm;
do_buffer = (pm != NL80211_MESH_POWER_ACTIVE);
if (sta->plink_state != NL80211_PLINK_ESTAB) {
clear_sta_flag(sta, WLAN_STA_MPSP_OWNER);
clear_sta_flag(sta, WLAN_STA_MPSP_RECIPIENT);
} else if (!do_buffer) {
clear_sta_flag(sta, WLAN_STA_MPSP_OWNER);
}
if (test_sta_flag(sta, WLAN_STA_PS_STA) == do_buffer)
return;
if (do_buffer) {
set_sta_flag(sta, WLAN_STA_PS_STA);
atomic_inc(&sta->sdata->u.mesh.ps.num_sta_ps);
mps_dbg(sta->sdata, "start PS buffering frames towards %pM\n",
sta->sta.addr);
} else {
ieee80211_sta_ps_deliver_wakeup(sta);
}
}
static void mps_set_sta_peer_pm(struct sta_info *sta,
struct ieee80211_hdr *hdr)
{
enum nl80211_mesh_power_mode pm;
u8 *qc = ieee80211_get_qos_ctl(hdr);
if (ieee80211_has_pm(hdr->frame_control)) {
if (qc[1] & (IEEE80211_QOS_CTL_MESH_PS_LEVEL >> 8))
pm = NL80211_MESH_POWER_DEEP_SLEEP;
else
pm = NL80211_MESH_POWER_LIGHT_SLEEP;
} else {
pm = NL80211_MESH_POWER_ACTIVE;
}
if (sta->peer_pm == pm)
return;
mps_dbg(sta->sdata, "STA %pM enters mode %d\n",
sta->sta.addr, pm);
sta->peer_pm = pm;
ieee80211_mps_sta_status_update(sta);
}
static void mps_set_sta_nonpeer_pm(struct sta_info *sta,
struct ieee80211_hdr *hdr)
{
enum nl80211_mesh_power_mode pm;
if (ieee80211_has_pm(hdr->frame_control))
pm = NL80211_MESH_POWER_DEEP_SLEEP;
else
pm = NL80211_MESH_POWER_ACTIVE;
if (sta->nonpeer_pm == pm)
return;
mps_dbg(sta->sdata, "STA %pM sets non-peer mode to %d\n",
sta->sta.addr, pm);
sta->nonpeer_pm = pm;
ieee80211_mps_sta_status_update(sta);
}
void ieee80211_mps_rx_h_sta_process(struct sta_info *sta,
struct ieee80211_hdr *hdr)
{
if (is_unicast_ether_addr(hdr->addr1) &&
ieee80211_is_data_qos(hdr->frame_control)) {
mps_set_sta_peer_pm(sta, hdr);
ieee80211_mpsp_trigger_process(ieee80211_get_qos_ctl(hdr),
sta, false, false);
} else {
mps_set_sta_nonpeer_pm(sta, hdr);
}
}
static void mpsp_trigger_send(struct sta_info *sta, bool rspi, bool eosp)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct sk_buff *skb;
struct ieee80211_hdr *nullfunc;
struct ieee80211_tx_info *info;
u8 *qc;
skb = mps_qos_null_get(sta);
if (!skb)
return;
nullfunc = (struct ieee80211_hdr *) skb->data;
if (!eosp)
nullfunc->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
qc = ieee80211_get_qos_ctl(nullfunc);
if (rspi)
qc[1] |= (IEEE80211_QOS_CTL_RSPI >> 8);
if (eosp)
qc[0] |= IEEE80211_QOS_CTL_EOSP;
info = IEEE80211_SKB_CB(skb);
info->flags |= IEEE80211_TX_CTL_NO_PS_BUFFER |
IEEE80211_TX_CTL_REQ_TX_STATUS;
mps_dbg(sdata, "sending MPSP trigger%s%s to %pM\n",
rspi ? " RSPI" : "", eosp ? " EOSP" : "", sta->sta.addr);
ieee80211_tx_skb(sdata, skb);
}
static void mpsp_qos_null_append(struct sta_info *sta,
struct sk_buff_head *frames)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct sk_buff *new_skb, *skb = skb_peek_tail(frames);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct ieee80211_tx_info *info;
if (ieee80211_is_data_qos(hdr->frame_control))
return;
new_skb = mps_qos_null_get(sta);
if (!new_skb)
return;
mps_dbg(sdata, "appending QoS Null in MPSP towards %pM\n",
sta->sta.addr);
new_skb->priority = 1;
skb_set_queue_mapping(new_skb, IEEE80211_AC_BK);
ieee80211_set_qos_hdr(sdata, new_skb);
info = IEEE80211_SKB_CB(new_skb);
info->control.vif = &sdata->vif;
info->flags |= IEEE80211_TX_INTFL_NEED_TXPROCESSING;
__skb_queue_tail(frames, new_skb);
}
static void mps_frame_deliver(struct sta_info *sta, int n_frames)
{
struct ieee80211_local *local = sta->sdata->local;
int ac;
struct sk_buff_head frames;
struct sk_buff *skb;
bool more_data = false;
skb_queue_head_init(&frames);
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
while (n_frames != 0) {
skb = skb_dequeue(&sta->tx_filtered[ac]);
if (!skb) {
skb = skb_dequeue(
&sta->ps_tx_buf[ac]);
if (skb)
local->total_ps_buffered--;
}
if (!skb)
break;
n_frames--;
__skb_queue_tail(&frames, skb);
}
if (!skb_queue_empty(&sta->tx_filtered[ac]) ||
!skb_queue_empty(&sta->ps_tx_buf[ac]))
more_data = true;
}
if (skb_queue_empty(&frames)) {
mpsp_trigger_send(sta, false, true);
return;
}
if (test_sta_flag(sta, WLAN_STA_MPSP_OWNER))
mpsp_qos_null_append(sta, &frames);
mps_dbg(sta->sdata, "sending %d frames to PS STA %pM\n",
skb_queue_len(&frames), sta->sta.addr);
skb_queue_walk(&frames, skb) {
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (void *) skb->data;
info->flags |= IEEE80211_TX_CTL_NO_PS_BUFFER;
if (more_data || !skb_queue_is_last(&frames, skb))
hdr->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
else
hdr->frame_control &=
cpu_to_le16(~IEEE80211_FCTL_MOREDATA);
if (skb_queue_is_last(&frames, skb) &&
ieee80211_is_data_qos(hdr->frame_control)) {
u8 *qoshdr = ieee80211_get_qos_ctl(hdr);
*qoshdr |= IEEE80211_QOS_CTL_EOSP;
info->flags |= IEEE80211_TX_CTL_REQ_TX_STATUS;
}
}
ieee80211_add_pending_skbs(local, &frames);
sta_info_recalc_tim(sta);
}
void ieee80211_mpsp_trigger_process(u8 *qc, struct sta_info *sta,
bool tx, bool acked)
{
u8 rspi = qc[1] & (IEEE80211_QOS_CTL_RSPI >> 8);
u8 eosp = qc[0] & IEEE80211_QOS_CTL_EOSP;
if (tx) {
if (rspi && acked)
set_sta_flag(sta, WLAN_STA_MPSP_RECIPIENT);
if (eosp)
clear_sta_flag(sta, WLAN_STA_MPSP_OWNER);
else if (acked &&
test_sta_flag(sta, WLAN_STA_PS_STA) &&
!test_and_set_sta_flag(sta, WLAN_STA_MPSP_OWNER))
mps_frame_deliver(sta, -1);
} else {
if (eosp)
clear_sta_flag(sta, WLAN_STA_MPSP_RECIPIENT);
else if (sta->local_pm != NL80211_MESH_POWER_ACTIVE)
set_sta_flag(sta, WLAN_STA_MPSP_RECIPIENT);
if (rspi && !test_and_set_sta_flag(sta, WLAN_STA_MPSP_OWNER))
mps_frame_deliver(sta, -1);
}
}
void ieee80211_mps_frame_release(struct sta_info *sta,
struct ieee802_11_elems *elems)
{
int ac, buffer_local = 0;
bool has_buffered = false;
if (sta->plink_state == NL80211_PLINK_ESTAB)
has_buffered = ieee80211_check_tim(elems->tim, elems->tim_len,
le16_to_cpu(sta->llid) % IEEE80211_MAX_AID);
if (has_buffered)
mps_dbg(sta->sdata, "%pM indicates buffered frames\n",
sta->sta.addr);
if (test_sta_flag(sta, WLAN_STA_PS_STA) &&
(!elems->awake_window || !le16_to_cpu(*elems->awake_window)))
return;
if (!test_sta_flag(sta, WLAN_STA_MPSP_OWNER))
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
buffer_local += skb_queue_len(&sta->ps_tx_buf[ac]) +
skb_queue_len(&sta->tx_filtered[ac]);
if (!has_buffered && !buffer_local)
return;
if (sta->plink_state == NL80211_PLINK_ESTAB)
mpsp_trigger_send(sta, has_buffered, !buffer_local);
else
mps_frame_deliver(sta, 1);
}
