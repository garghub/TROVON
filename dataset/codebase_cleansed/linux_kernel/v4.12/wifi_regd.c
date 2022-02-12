static int rtw_ieee80211_channel_to_frequency(int chan, int band)
{
if (chan == 14)
return 2484;
else if (chan < 14)
return 2407 + chan * 5;
else
return 0;
}
static void _rtw_reg_apply_flags(struct wiphy *wiphy)
{
struct adapter *padapter = wiphy_to_adapter(wiphy);
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
RT_CHANNEL_INFO *channel_set = pmlmeext->channel_set;
u8 max_chan_nums = pmlmeext->max_chan_nums;
struct ieee80211_supported_band *sband;
struct ieee80211_channel *ch;
unsigned int i, j;
u16 channel;
u32 freq;
for (i = 0; i < NUM_NL80211_BANDS; i++) {
sband = wiphy->bands[i];
if (sband) {
for (j = 0; j < sband->n_channels; j++) {
ch = &sband->channels[j];
if (ch)
ch->flags = IEEE80211_CHAN_DISABLED;
}
}
}
for (i = 0; i < max_chan_nums; i++) {
channel = channel_set[i].ChannelNum;
freq =
rtw_ieee80211_channel_to_frequency(channel,
NL80211_BAND_2GHZ);
ch = ieee80211_get_channel(wiphy, freq);
if (ch) {
if (channel_set[i].ScanType == SCAN_PASSIVE) {
ch->flags = IEEE80211_CHAN_NO_IR;
}
else {
ch->flags = 0;
}
}
}
}
static int _rtw_reg_notifier_apply(struct wiphy *wiphy,
struct regulatory_request *request,
struct rtw_regulatory *reg)
{
_rtw_reg_apply_flags(wiphy);
return 0;
}
static const struct ieee80211_regdomain *_rtw_regdomain_select(struct
rtw_regulatory
*reg)
{
return &rtw_regdom_rd;
}
static void _rtw_regd_init_wiphy(struct rtw_regulatory *reg,
struct wiphy *wiphy,
void (*reg_notifier) (struct wiphy * wiphy,
struct regulatory_request *
request))
{
const struct ieee80211_regdomain *regd;
wiphy->reg_notifier = reg_notifier;
wiphy->regulatory_flags |= REGULATORY_CUSTOM_REG;
wiphy->regulatory_flags &= ~REGULATORY_STRICT_REG;
wiphy->regulatory_flags &= ~REGULATORY_DISABLE_BEACON_HINTS;
regd = _rtw_regdomain_select(reg);
wiphy_apply_custom_regulatory(wiphy, regd);
_rtw_reg_apply_flags(wiphy);
}
int rtw_regd_init(struct adapter *padapter,
void (*reg_notifier) (struct wiphy * wiphy,
struct regulatory_request *request))
{
struct wiphy *wiphy = padapter->rtw_wdev->wiphy;
_rtw_regd_init_wiphy(NULL, wiphy, reg_notifier);
return 0;
}
void rtw_reg_notifier(struct wiphy *wiphy, struct regulatory_request *request)
{
struct rtw_regulatory *reg = NULL;
DBG_8192C("%s\n", __func__);
_rtw_reg_notifier_apply(wiphy, request, reg);
}
