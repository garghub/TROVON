void ieee80211_vht_cap_ie_to_sta_vht_cap(struct ieee80211_sub_if_data *sdata,
struct ieee80211_supported_band *sband,
struct ieee80211_vht_cap *vht_cap_ie,
struct ieee80211_sta_vht_cap *vht_cap)
{
if (WARN_ON_ONCE(!vht_cap))
return;
memset(vht_cap, 0, sizeof(*vht_cap));
if (!vht_cap_ie || !sband->vht_cap.vht_supported)
return;
vht_cap->vht_supported = true;
vht_cap->cap = le32_to_cpu(vht_cap_ie->vht_cap_info);
memcpy(&vht_cap->vht_mcs, &vht_cap_ie->supp_mcs,
sizeof(struct ieee80211_vht_mcs_info));
}
