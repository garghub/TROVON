static u8 _rtl_rc_get_highest_rix(struct rtl_priv *rtlpriv,
struct ieee80211_sta *sta,
struct sk_buff *skb, bool not_data)
{
struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
struct rtl_phy *rtlphy = &(rtlpriv->phy);
struct rtl_sta_info *sta_entry = NULL;
u8 wireless_mode = 0;
if (sta) {
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
wireless_mode = sta_entry->wireless_mode;
}
if (rtl92e_is_special_data(rtlpriv->mac80211.hw, skb, true) ||
not_data) {
return 0;
} else {
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
if (wireless_mode == WIRELESS_MODE_B) {
return B_MODE_MAX_RIX;
} else if (wireless_mode == WIRELESS_MODE_G) {
return G_MODE_MAX_RIX;
} else if (wireless_mode == WIRELESS_MODE_N_24G) {
if (get_rf_type(rtlphy) != RF_2T2R)
return N_MODE_MCS7_RIX;
else
return N_MODE_MCS15_RIX;
} else if (wireless_mode == WIRELESS_MODE_AC_24G) {
return AC_MODE_MCS9_RIX;
} else {
return 0;
}
} else {
if (wireless_mode == WIRELESS_MODE_A) {
return A_MODE_MAX_RIX;
} else if (wireless_mode == WIRELESS_MODE_N_5G) {
if (get_rf_type(rtlphy) != RF_2T2R)
return N_MODE_MCS7_RIX;
else
return N_MODE_MCS15_RIX;
} else if (wireless_mode == WIRELESS_MODE_AC_5G) {
return AC_MODE_MCS9_RIX;
} else {
return 0;
}
}
}
}
static void _rtl_rc_rate_set_series(struct rtl_priv *rtlpriv,
struct ieee80211_sta *sta,
struct ieee80211_tx_rate *rate,
struct ieee80211_tx_rate_control *txrc,
u8 tries, char rix, int rtsctsenable,
bool not_data)
{
struct rtl_mac *mac = rtl_mac(rtlpriv);
u8 sgi_20 = 0, sgi_40 = 0, sgi_80 = 0;
if (sta) {
sgi_20 = sta->ht_cap.cap & IEEE80211_HT_CAP_SGI_20;
sgi_40 = sta->ht_cap.cap & IEEE80211_HT_CAP_SGI_40;
sgi_80 = sta->vht_cap.cap & IEEE80211_VHT_CAP_SHORT_GI_80;
}
rate->count = tries;
rate->idx = rix >= 0x00 ? rix : 0x00;
if (!not_data) {
if (txrc->short_preamble)
rate->flags |= IEEE80211_TX_RC_USE_SHORT_PREAMBLE;
if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC) {
if (sta && (sta->ht_cap.cap &
IEEE80211_HT_CAP_SUP_WIDTH_20_40))
rate->flags |= IEEE80211_TX_RC_40_MHZ_WIDTH;
if (sta && (sta->vht_cap.vht_supported))
rate->flags |= IEEE80211_TX_RC_80_MHZ_WIDTH;
} else {
if (mac->bw_40)
rate->flags |= IEEE80211_TX_RC_40_MHZ_WIDTH;
if (mac->bw_80)
rate->flags |= IEEE80211_TX_RC_80_MHZ_WIDTH;
}
if (sgi_20 || sgi_40 || sgi_80)
rate->flags |= IEEE80211_TX_RC_SHORT_GI;
if (sta && sta->ht_cap.ht_supported)
rate->flags |= IEEE80211_TX_RC_MCS;
if (sta && sta->vht_cap.vht_supported)
rate->flags |= IEEE80211_TX_RC_VHT_MCS;
}
}
static void rtl_get_rate(void *ppriv, struct ieee80211_sta *sta,
void *priv_sta,
struct ieee80211_tx_rate_control *txrc)
{
struct rtl_priv *rtlpriv = ppriv;
struct sk_buff *skb = txrc->skb;
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_tx_rate *rates = tx_info->control.rates;
__le16 fc = rtl_get_fc(skb);
u8 try_per_rate, i, rix;
bool not_data = !ieee80211_is_data(fc);
if (rate_control_send_low(sta, priv_sta, txrc))
return;
rix = _rtl_rc_get_highest_rix(rtlpriv, sta, skb, not_data);
try_per_rate = 1;
_rtl_rc_rate_set_series(rtlpriv, sta, &rates[0], txrc,
try_per_rate, rix, 1, not_data);
if (!not_data) {
for (i = 1; i < 4; i++)
_rtl_rc_rate_set_series(rtlpriv, sta, &rates[i],
txrc, i, (rix - i), 1,
not_data);
}
}
static bool _rtl_tx_aggr_check(struct rtl_priv *rtlpriv,
struct rtl_sta_info *sta_entry, u16 tid)
{
struct rtl_mac *mac = rtl_mac(rtlpriv);
if (mac->act_scanning)
return false;
if (mac->opmode == NL80211_IFTYPE_STATION &&
mac->cnt_after_linked < 3)
return false;
if (sta_entry->tids[tid].agg.agg_state == RTL_AGG_STOP)
return true;
return false;
}
static void rtl_tx_status(void *ppriv,
struct ieee80211_supported_band *sband,
struct ieee80211_sta *sta, void *priv_sta,
struct sk_buff *skb)
{
struct rtl_priv *rtlpriv = ppriv;
struct rtl_mac *mac = rtl_mac(rtlpriv);
struct ieee80211_hdr *hdr = rtl_get_hdr(skb);
__le16 fc = rtl_get_fc(skb);
struct rtl_sta_info *sta_entry;
if (!priv_sta || !ieee80211_is_data(fc))
return;
if (rtl92e_is_special_data(mac->hw, skb, true))
return;
if (is_multicast_ether_addr(ieee80211_get_DA(hdr)) ||
is_broadcast_ether_addr(ieee80211_get_DA(hdr)))
return;
if (sta) {
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
if ((sta->ht_cap.ht_supported) &&
!(skb->protocol == cpu_to_be16(ETH_P_PAE))) {
if (ieee80211_is_data_qos(fc)) {
u8 tid = rtl_get_tid(skb);
if (_rtl_tx_aggr_check(rtlpriv, sta_entry,
tid)) {
sta_entry->tids[tid].agg.agg_state =
RTL_AGG_PROGRESS;
ieee80211_start_tx_ba_session(sta, tid,
5000);
}
}
}
}
}
static void rtl_rate_init(void *ppriv,
struct ieee80211_supported_band *sband,
struct cfg80211_chan_def *chandef,
struct ieee80211_sta *sta, void *priv_sta)
{
}
static void *rtl_rate_alloc(struct ieee80211_hw *hw, struct dentry *debugfsdir)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
return rtlpriv;
}
static void rtl_rate_free(void *rtlpriv)
{
return;
}
static void *rtl_rate_alloc_sta(void *ppriv,
struct ieee80211_sta *sta, gfp_t gfp)
{
struct rtl_priv *rtlpriv = ppriv;
struct rtl_rate_priv *rate_priv;
rate_priv = kzalloc(sizeof(*rate_priv), gfp);
if (!rate_priv) {
RT_TRACE(COMP_ERR, DBG_EMERG,
("Unable to allocate private rc structure\n"));
return NULL;
}
rtlpriv->rate_priv = rate_priv;
return rate_priv;
}
static void rtl_rate_free_sta(void *rtlpriv,
struct ieee80211_sta *sta, void *priv_sta)
{
struct rtl_rate_priv *rate_priv = priv_sta;
kfree(rate_priv);
}
int rtl92e_rate_control_register(void)
{
return ieee80211_rate_control_register(&rtl_rate_ops);
}
void rtl92e_rate_control_unregister(void)
{
ieee80211_rate_control_unregister(&rtl_rate_ops);
}
