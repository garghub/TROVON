static void ieee80211_send_refuse_measurement_request(struct ieee80211_sub_if_data *sdata,
struct ieee80211_msrment_ie *request_ie,
const u8 *da, const u8 *bssid,
u8 dialog_token)
{
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct ieee80211_mgmt *msr_report;
skb = dev_alloc_skb(sizeof(*msr_report) + local->hw.extra_tx_headroom +
sizeof(struct ieee80211_msrment_ie));
if (!skb) {
printk(KERN_ERR "%s: failed to allocate buffer for "
"measurement report frame\n", sdata->name);
return;
}
skb_reserve(skb, local->hw.extra_tx_headroom);
msr_report = (struct ieee80211_mgmt *)skb_put(skb, 24);
memset(msr_report, 0, 24);
memcpy(msr_report->da, da, ETH_ALEN);
memcpy(msr_report->sa, sdata->vif.addr, ETH_ALEN);
memcpy(msr_report->bssid, bssid, ETH_ALEN);
msr_report->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
skb_put(skb, 1 + sizeof(msr_report->u.action.u.measurement));
msr_report->u.action.category = WLAN_CATEGORY_SPECTRUM_MGMT;
msr_report->u.action.u.measurement.action_code =
WLAN_ACTION_SPCT_MSR_RPRT;
msr_report->u.action.u.measurement.dialog_token = dialog_token;
msr_report->u.action.u.measurement.element_id = WLAN_EID_MEASURE_REPORT;
msr_report->u.action.u.measurement.length =
sizeof(struct ieee80211_msrment_ie);
memset(&msr_report->u.action.u.measurement.msr_elem, 0,
sizeof(struct ieee80211_msrment_ie));
msr_report->u.action.u.measurement.msr_elem.token = request_ie->token;
msr_report->u.action.u.measurement.msr_elem.mode |=
IEEE80211_SPCT_MSR_RPRT_MODE_REFUSED;
msr_report->u.action.u.measurement.msr_elem.type = request_ie->type;
ieee80211_tx_skb(sdata, skb);
}
void ieee80211_process_measurement_req(struct ieee80211_sub_if_data *sdata,
struct ieee80211_mgmt *mgmt,
size_t len)
{
ieee80211_send_refuse_measurement_request(sdata,
&mgmt->u.action.u.measurement.msr_elem,
mgmt->sa, mgmt->bssid,
mgmt->u.action.u.measurement.dialog_token);
}
