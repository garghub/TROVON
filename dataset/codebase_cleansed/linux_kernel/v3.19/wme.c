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
static inline u8 ieee80211_fix_reserved_tid(u8 tid)
{
switch (tid) {
case 0:
return 3;
case 1:
return 2;
case 2:
return 1;
case 3:
return 0;
case 4:
return 5;
case 5:
return 4;
case 6:
return 7;
case 7:
return 6;
}
return 0;
}
static u16 ieee80211_downgrade_queue(struct ieee80211_sub_if_data *sdata,
struct sta_info *sta, struct sk_buff *skb)
{
struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
while (sdata->wmm_acm & BIT(skb->priority)) {
int ac = ieee802_1d_to_ac[skb->priority];
if (ifmgd->tx_tspec[ac].admitted_time &&
skb->priority == ifmgd->tx_tspec[ac].up)
return ac;
if (wme_downgrade_ac(skb)) {
break;
}
}
if (sta && sta->reserved_tid == skb->priority)
skb->priority = ieee80211_fix_reserved_tid(skb->priority);
return ieee802_1d_to_ac[skb->priority];
}
u16 ieee80211_select_queue_80211(struct ieee80211_sub_if_data *sdata,
struct sk_buff *skb,
struct ieee80211_hdr *hdr)
{
struct ieee80211_local *local = sdata->local;
u8 *p;
if (local->hw.queues < IEEE80211_NUM_ACS)
return 0;
if (!ieee80211_is_data(hdr->frame_control)) {
skb->priority = 7;
return ieee802_1d_to_ac[skb->priority];
}
if (!ieee80211_is_data_qos(hdr->frame_control)) {
skb->priority = 0;
return ieee802_1d_to_ac[skb->priority];
}
p = ieee80211_get_qos_ctl(hdr);
skb->priority = *p & IEEE80211_QOS_CTL_TAG1D_MASK;
return ieee80211_downgrade_queue(sdata, NULL, skb);
}
u16 ieee80211_select_queue(struct ieee80211_sub_if_data *sdata,
struct sk_buff *skb)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta = NULL;
const u8 *ra = NULL;
bool qos = false;
struct mac80211_qos_map *qos_map;
u16 ret;
if (local->hw.queues < IEEE80211_NUM_ACS || skb->len < 6) {
skb->priority = 0;
return 0;
}
rcu_read_lock();
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP_VLAN:
sta = rcu_dereference(sdata->u.vlan.sta);
if (sta) {
qos = sta->sta.wme;
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
qos = true;
break;
#endif
case NL80211_IFTYPE_STATION:
sta = sta_info_get(sdata, skb->data);
if (sta)
qos = sta->sta.wme;
ra = sdata->u.mgd.bssid;
break;
case NL80211_IFTYPE_ADHOC:
ra = skb->data;
break;
case NL80211_IFTYPE_OCB:
qos = true;
break;
default:
break;
}
if (!sta && ra && !is_multicast_ether_addr(ra)) {
sta = sta_info_get(sdata, ra);
if (sta)
qos = sta->sta.wme;
}
if (!qos) {
skb->priority = 0;
ret = IEEE80211_AC_BE;
goto out;
}
if (skb->protocol == sdata->control_port_protocol) {
skb->priority = 7;
goto downgrade;
}
qos_map = rcu_dereference(sdata->qos_map);
skb->priority = cfg80211_classify8021d(skb, qos_map ?
&qos_map->qos_map : NULL);
downgrade:
ret = ieee80211_downgrade_queue(sdata, sta, skb);
out:
rcu_read_unlock();
return ret;
}
void ieee80211_set_qos_hdr(struct ieee80211_sub_if_data *sdata,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (void *)skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
u8 *p;
u8 ack_policy, tid;
if (!ieee80211_is_data_qos(hdr->frame_control))
return;
p = ieee80211_get_qos_ctl(hdr);
tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
ack_policy = *p & IEEE80211_QOS_CTL_EOSP;
if (is_multicast_ether_addr(hdr->addr1) ||
sdata->noack_map & BIT(tid)) {
ack_policy |= IEEE80211_QOS_CTL_ACK_POLICY_NOACK;
info->flags |= IEEE80211_TX_CTL_NO_ACK;
}
*p++ = ack_policy | tid;
if (ieee80211_vif_is_mesh(&sdata->vif)) {
*p &= ((IEEE80211_QOS_CTL_RSPI |
IEEE80211_QOS_CTL_MESH_PS_LEVEL) >> 8);
if (!ieee80211_is_qos_nullfunc(hdr->frame_control))
*p |= (IEEE80211_QOS_CTL_MESH_CONTROL_PRESENT >> 8);
} else {
*p = 0;
}
}
