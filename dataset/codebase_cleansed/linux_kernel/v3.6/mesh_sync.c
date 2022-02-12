static bool mesh_peer_tbtt_adjusting(struct ieee802_11_elems *ie)
{
return (ie->mesh_config->meshconf_cap &
MESHCONF_CAPAB_TBTT_ADJUSTING) != 0;
}
void mesh_sync_adjust_tbtt(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_if_mesh *ifmsh = &sdata->u.mesh;
u64 beacon_int_fraction = sdata->vif.bss_conf.beacon_int * 1024 / 2500;
u64 tsf;
u64 tsfdelta;
spin_lock_bh(&ifmsh->sync_offset_lock);
if (ifmsh->sync_offset_clockdrift_max < beacon_int_fraction) {
msync_dbg(sdata, "TBTT : max clockdrift=%lld; adjusting\n",
(long long) ifmsh->sync_offset_clockdrift_max);
tsfdelta = -ifmsh->sync_offset_clockdrift_max;
ifmsh->sync_offset_clockdrift_max = 0;
} else {
msync_dbg(sdata, "TBTT : max clockdrift=%lld; adjusting by %llu\n",
(long long) ifmsh->sync_offset_clockdrift_max,
(unsigned long long) beacon_int_fraction);
tsfdelta = -beacon_int_fraction;
ifmsh->sync_offset_clockdrift_max -= beacon_int_fraction;
}
tsf = drv_get_tsf(local, sdata);
if (tsf != -1ULL)
drv_set_tsf(local, sdata, tsf + tsfdelta);
spin_unlock_bh(&ifmsh->sync_offset_lock);
}
static void mesh_sync_offset_rx_bcn_presp(struct ieee80211_sub_if_data *sdata,
u16 stype,
struct ieee80211_mgmt *mgmt,
struct ieee802_11_elems *elems,
struct ieee80211_rx_status *rx_status)
{
struct ieee80211_if_mesh *ifmsh = &sdata->u.mesh;
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
u64 t_t, t_r;
WARN_ON(ifmsh->mesh_sp_id != IEEE80211_SYNC_METHOD_NEIGHBOR_OFFSET);
if (stype != IEEE80211_STYPE_BEACON)
return;
t_r = drv_get_tsf(local, sdata);
rcu_read_lock();
sta = sta_info_get(sdata, mgmt->sa);
if (!sta)
goto no_sync;
if (elems->mesh_config && mesh_peer_tbtt_adjusting(elems)) {
clear_sta_flag(sta, WLAN_STA_TOFFSET_KNOWN);
msync_dbg(sdata, "STA %pM : is adjusting TBTT\n", sta->sta.addr);
goto no_sync;
}
if (rx_status->flag & RX_FLAG_MACTIME_MPDU && rx_status->mactime) {
int rate;
if (rx_status->flag & RX_FLAG_HT) {
goto no_sync;
} else
rate = local->hw.wiphy->bands[rx_status->band]->
bitrates[rx_status->rate_idx].bitrate;
t_r = rx_status->mactime + (24 * 8 * 10 / rate);
}
t_t = le64_to_cpu(mgmt->u.beacon.timestamp);
sta->t_offset = t_t - t_r;
if (test_sta_flag(sta, WLAN_STA_TOFFSET_KNOWN)) {
s64 t_clockdrift = sta->t_offset_setpoint
- sta->t_offset;
msync_dbg(sdata,
"STA %pM : sta->t_offset=%lld, sta->t_offset_setpoint=%lld, t_clockdrift=%lld\n",
sta->sta.addr,
(long long) sta->t_offset,
(long long)
sta->t_offset_setpoint,
(long long) t_clockdrift);
if (t_clockdrift > TOFFSET_MAXIMUM_ADJUSTMENT ||
t_clockdrift < -TOFFSET_MAXIMUM_ADJUSTMENT) {
msync_dbg(sdata,
"STA %pM : t_clockdrift=%lld too large, setpoint reset\n",
sta->sta.addr,
(long long) t_clockdrift);
clear_sta_flag(sta, WLAN_STA_TOFFSET_KNOWN);
goto no_sync;
}
rcu_read_unlock();
spin_lock_bh(&ifmsh->sync_offset_lock);
if (t_clockdrift >
ifmsh->sync_offset_clockdrift_max)
ifmsh->sync_offset_clockdrift_max
= t_clockdrift;
spin_unlock_bh(&ifmsh->sync_offset_lock);
} else {
sta->t_offset_setpoint = sta->t_offset - TOFFSET_SET_MARGIN;
set_sta_flag(sta, WLAN_STA_TOFFSET_KNOWN);
msync_dbg(sdata,
"STA %pM : offset was invalid, sta->t_offset=%lld\n",
sta->sta.addr,
(long long) sta->t_offset);
rcu_read_unlock();
}
return;
no_sync:
rcu_read_unlock();
}
static void mesh_sync_offset_adjust_tbtt(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_if_mesh *ifmsh = &sdata->u.mesh;
WARN_ON(ifmsh->mesh_sp_id
!= IEEE80211_SYNC_METHOD_NEIGHBOR_OFFSET);
BUG_ON(!rcu_read_lock_held());
spin_lock_bh(&ifmsh->sync_offset_lock);
if (ifmsh->sync_offset_clockdrift_max >
TOFFSET_MINIMUM_ADJUSTMENT) {
msync_dbg(sdata,
"TBTT : kicking off TBTT adjustment with clockdrift_max=%lld\n",
ifmsh->sync_offset_clockdrift_max);
set_bit(MESH_WORK_DRIFT_ADJUST,
&ifmsh->wrkq_flags);
} else {
msync_dbg(sdata,
"TBTT : max clockdrift=%lld; too small to adjust\n",
(long long)ifmsh->sync_offset_clockdrift_max);
ifmsh->sync_offset_clockdrift_max = 0;
}
spin_unlock_bh(&ifmsh->sync_offset_lock);
}
static const u8 *mesh_get_vendor_oui(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_if_mesh *ifmsh = &sdata->u.mesh;
u8 offset;
if (!ifmsh->ie || !ifmsh->ie_len)
return NULL;
offset = ieee80211_ie_split_vendor(ifmsh->ie,
ifmsh->ie_len, 0);
if (!offset)
return NULL;
return ifmsh->ie + offset + 2;
}
static void mesh_sync_vendor_rx_bcn_presp(struct ieee80211_sub_if_data *sdata,
u16 stype,
struct ieee80211_mgmt *mgmt,
struct ieee802_11_elems *elems,
struct ieee80211_rx_status *rx_status)
{
const u8 *oui;
WARN_ON(sdata->u.mesh.mesh_sp_id != IEEE80211_SYNC_METHOD_VENDOR);
msync_dbg(sdata, "called mesh_sync_vendor_rx_bcn_presp\n");
oui = mesh_get_vendor_oui(sdata);
}
static void mesh_sync_vendor_adjust_tbtt(struct ieee80211_sub_if_data *sdata)
{
const u8 *oui;
WARN_ON(sdata->u.mesh.mesh_sp_id != IEEE80211_SYNC_METHOD_VENDOR);
msync_dbg(sdata, "called mesh_sync_vendor_adjust_tbtt\n");
oui = mesh_get_vendor_oui(sdata);
}
struct ieee80211_mesh_sync_ops *ieee80211_mesh_sync_ops_get(u8 method)
{
struct ieee80211_mesh_sync_ops *ops = NULL;
u8 i;
for (i = 0 ; i < ARRAY_SIZE(sync_methods); ++i) {
if (sync_methods[i].method == method) {
ops = &sync_methods[i].ops;
break;
}
}
return ops;
}
