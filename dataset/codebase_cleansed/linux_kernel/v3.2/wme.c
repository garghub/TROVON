static int wme_downgrade_ac(struct sk_buff *skb)
{
switch (skb->priority) {
case 6:
case 7:
skb->priority = 5;
return 0;
case 4:
case 5:
skb->priority = 3;
return 0;
case 0:
case 3:
skb->priority = 2;
return 0;
default:
return -1;
}
}
u16 ieee80211_select_queue(struct ieee80211_sub_if_data *sdata,
struct sk_buff *skb)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta = NULL;
const u8 *ra = NULL;
bool qos = false;
if (local->hw.queues < 4 || skb->len < 6) {
skb->priority = 0;
return min_t(u16, local->hw.queues - 1, IEEE80211_AC_BE);
}
rcu_read_lock();
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP_VLAN:
sta = rcu_dereference(sdata->u.vlan.sta);
if (sta) {
qos = test_sta_flag(sta, WLAN_STA_WME);
break;
}
case NL80211_IFTYPE_AP:
ra = skb->data;
break;
case NL80211_IFTYPE_WDS:
ra = sdata->u.wds.remote_addr;
break;
#ifdef CONFIG_MAC80211_MESH
case NL80211_IFTYPE_MESH_POINT:
ra = skb->data;
break;
#endif
case NL80211_IFTYPE_STATION:
ra = sdata->u.mgd.bssid;
break;
case NL80211_IFTYPE_ADHOC:
ra = skb->data;
break;
default:
break;
}
if (!sta && ra && !is_multicast_ether_addr(ra)) {
sta = sta_info_get(sdata, ra);
if (sta)
qos = test_sta_flag(sta, WLAN_STA_WME);
}
rcu_read_unlock();
if (!qos) {
skb->priority = 0;
return IEEE80211_AC_BE;
}
skb->priority = cfg80211_classify8021d(skb);
return ieee80211_downgrade_queue(local, skb);
}
u16 ieee80211_downgrade_queue(struct ieee80211_local *local,
struct sk_buff *skb)
{
while (unlikely(local->wmm_acm & BIT(skb->priority))) {
if (wme_downgrade_ac(skb)) {
break;
}
}
return ieee802_1d_to_ac[skb->priority];
}
void ieee80211_set_qos_hdr(struct ieee80211_sub_if_data *sdata,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (void *)skb->data;
if (ieee80211_is_data_qos(hdr->frame_control)) {
u8 *p = ieee80211_get_qos_ctl(hdr);
u8 ack_policy = 0, tid;
tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
if (unlikely(sdata->local->wifi_wme_noack_test))
ack_policy |= IEEE80211_QOS_CTL_ACK_POLICY_NOACK;
*p++ = ack_policy | tid;
*p = ieee80211_vif_is_mesh(&sdata->vif) ?
(IEEE80211_QOS_CTL_MESH_CONTROL_PRESENT >> 8) : 0;
}
}
