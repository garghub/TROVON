u16 qlink_iface_type_mask_to_nl(u16 qlink_mask)
{
u16 result = 0;
if (qlink_mask & QLINK_IFTYPE_AP)
result |= BIT(NL80211_IFTYPE_AP);
if (qlink_mask & QLINK_IFTYPE_STATION)
result |= BIT(NL80211_IFTYPE_STATION);
if (qlink_mask & QLINK_IFTYPE_ADHOC)
result |= BIT(NL80211_IFTYPE_ADHOC);
if (qlink_mask & QLINK_IFTYPE_MONITOR)
result |= BIT(NL80211_IFTYPE_MONITOR);
if (qlink_mask & QLINK_IFTYPE_WDS)
result |= BIT(NL80211_IFTYPE_WDS);
return result;
}
u8 qlink_chan_width_mask_to_nl(u16 qlink_mask)
{
u8 result = 0;
if (qlink_mask & QLINK_CHAN_WIDTH_5)
result |= BIT(NL80211_CHAN_WIDTH_5);
if (qlink_mask & QLINK_CHAN_WIDTH_10)
result |= BIT(NL80211_CHAN_WIDTH_10);
if (qlink_mask & QLINK_CHAN_WIDTH_20_NOHT)
result |= BIT(NL80211_CHAN_WIDTH_20_NOHT);
if (qlink_mask & QLINK_CHAN_WIDTH_20)
result |= BIT(NL80211_CHAN_WIDTH_20);
if (qlink_mask & QLINK_CHAN_WIDTH_40)
result |= BIT(NL80211_CHAN_WIDTH_40);
if (qlink_mask & QLINK_CHAN_WIDTH_80)
result |= BIT(NL80211_CHAN_WIDTH_80);
if (qlink_mask & QLINK_CHAN_WIDTH_80P80)
result |= BIT(NL80211_CHAN_WIDTH_80P80);
if (qlink_mask & QLINK_CHAN_WIDTH_160)
result |= BIT(NL80211_CHAN_WIDTH_160);
return result;
}
