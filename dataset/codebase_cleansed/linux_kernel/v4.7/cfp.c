u8 *mwifiex_11d_code_2_region(u8 code)
{
u8 i;
u8 size = sizeof(region_code_mapping_t)/
sizeof(struct region_code_mapping);
for (i = 0; i < size; i++)
if (region_code_mapping_t[i].code == code)
return region_code_mapping_t[i].region;
return NULL;
}
u32 mwifiex_index_to_acs_data_rate(struct mwifiex_private *priv,
u8 index, u8 ht_info)
{
u32 rate = 0;
u8 mcs_index = 0;
u8 bw = 0;
u8 gi = 0;
if ((ht_info & 0x3) == MWIFIEX_RATE_FORMAT_VHT) {
mcs_index = min(index & 0xF, 9);
bw = (ht_info & 0xC) >> 2;
gi = (ht_info & 0x10) >> 4;
if ((index >> 4) == 1)
rate = ac_mcs_rate_nss2[2 * (3 - bw) + gi][mcs_index];
else
rate = ac_mcs_rate_nss1[2 * (3 - bw) + gi][mcs_index];
} else if ((ht_info & 0x3) == MWIFIEX_RATE_FORMAT_HT) {
bw = (ht_info & 0xC) >> 2;
gi = (ht_info & 0x10) >> 4;
if (index == MWIFIEX_RATE_BITMAP_MCS0) {
if (gi == 1)
rate = 0x0D;
else
rate = 0x0C;
} else if (index < 16) {
if ((bw == 1) || (bw == 0))
rate = mcs_rate[2 * (1 - bw) + gi][index];
else
rate = mwifiex_data_rates[0];
} else {
rate = mwifiex_data_rates[0];
}
} else {
if (index >= MWIFIEX_SUPPORTED_RATES_EXT)
index = 0;
rate = mwifiex_data_rates[index];
}
return rate;
}
u32 mwifiex_index_to_data_rate(struct mwifiex_private *priv,
u8 index, u8 ht_info)
{
u32 mcs_num_supp =
(priv->adapter->user_dev_mcs_support == HT_STREAM_2X2) ? 16 : 8;
u32 rate;
if (priv->adapter->is_hw_11ac_capable)
return mwifiex_index_to_acs_data_rate(priv, index, ht_info);
if (ht_info & BIT(0)) {
if (index == MWIFIEX_RATE_BITMAP_MCS0) {
if (ht_info & BIT(2))
rate = 0x0D;
else
rate = 0x0C;
} else if (index < mcs_num_supp) {
if (ht_info & BIT(1)) {
if (ht_info & BIT(2))
rate = mcs_rate[1][index];
else
rate = mcs_rate[0][index];
} else {
if (ht_info & BIT(2))
rate = mcs_rate[3][index];
else
rate = mcs_rate[2][index];
}
} else
rate = mwifiex_data_rates[0];
} else {
if (index >= MWIFIEX_SUPPORTED_RATES_EXT)
index = 0;
rate = mwifiex_data_rates[index];
}
return rate;
}
u32 mwifiex_get_active_data_rates(struct mwifiex_private *priv, u8 *rates)
{
if (!priv->media_connected)
return mwifiex_get_supported_rates(priv, rates);
else
return mwifiex_copy_rates(rates, 0,
priv->curr_bss_params.data_rates,
priv->curr_bss_params.num_of_rates);
}
struct mwifiex_chan_freq_power *
mwifiex_get_cfp(struct mwifiex_private *priv, u8 band, u16 channel, u32 freq)
{
struct mwifiex_chan_freq_power *cfp = NULL;
struct ieee80211_supported_band *sband;
struct ieee80211_channel *ch = NULL;
int i;
if (!channel && !freq)
return cfp;
if (mwifiex_band_to_radio_type(band) == HostCmd_SCAN_RADIO_TYPE_BG)
sband = priv->wdev.wiphy->bands[NL80211_BAND_2GHZ];
else
sband = priv->wdev.wiphy->bands[NL80211_BAND_5GHZ];
if (!sband) {
mwifiex_dbg(priv->adapter, ERROR,
"%s: cannot find cfp by band %d\n",
__func__, band);
return cfp;
}
for (i = 0; i < sband->n_channels; i++) {
ch = &sband->channels[i];
if (ch->flags & IEEE80211_CHAN_DISABLED)
continue;
if (freq) {
if (ch->center_freq == freq)
break;
} else {
if (ch->hw_value == channel ||
channel == FIRST_VALID_CHANNEL)
break;
}
}
if (i == sband->n_channels) {
mwifiex_dbg(priv->adapter, ERROR,
"%s: cannot find cfp by band %d\t"
"& channel=%d freq=%d\n",
__func__, band, channel, freq);
} else {
if (!ch)
return cfp;
priv->cfp.channel = ch->hw_value;
priv->cfp.freq = ch->center_freq;
priv->cfp.max_tx_power = ch->max_power;
cfp = &priv->cfp;
}
return cfp;
}
u8
mwifiex_is_rate_auto(struct mwifiex_private *priv)
{
u32 i;
int rate_num = 0;
for (i = 0; i < ARRAY_SIZE(priv->bitmap_rates); i++)
if (priv->bitmap_rates[i])
rate_num++;
if (rate_num > 1)
return true;
else
return false;
}
u32 mwifiex_get_rates_from_cfg80211(struct mwifiex_private *priv,
u8 *rates, u8 radio_type)
{
struct wiphy *wiphy = priv->adapter->wiphy;
struct cfg80211_scan_request *request = priv->scan_request;
u32 num_rates, rate_mask;
struct ieee80211_supported_band *sband;
int i;
if (radio_type) {
sband = wiphy->bands[NL80211_BAND_5GHZ];
if (WARN_ON_ONCE(!sband))
return 0;
rate_mask = request->rates[NL80211_BAND_5GHZ];
} else {
sband = wiphy->bands[NL80211_BAND_2GHZ];
if (WARN_ON_ONCE(!sband))
return 0;
rate_mask = request->rates[NL80211_BAND_2GHZ];
}
num_rates = 0;
for (i = 0; i < sband->n_bitrates; i++) {
if ((BIT(i) & rate_mask) == 0)
continue;
rates[num_rates++] = (u8)(sband->bitrates[i].bitrate / 5);
}
return num_rates;
}
u32 mwifiex_get_supported_rates(struct mwifiex_private *priv, u8 *rates)
{
u32 k = 0;
struct mwifiex_adapter *adapter = priv->adapter;
if (priv->bss_mode == NL80211_IFTYPE_STATION ||
priv->bss_mode == NL80211_IFTYPE_P2P_CLIENT) {
switch (adapter->config_bands) {
case BAND_B:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_b\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_b,
sizeof(supported_rates_b));
break;
case BAND_G:
case BAND_G | BAND_GN:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_g\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_g,
sizeof(supported_rates_g));
break;
case BAND_B | BAND_G:
case BAND_A | BAND_B | BAND_G:
case BAND_A | BAND_B:
case BAND_A | BAND_B | BAND_G | BAND_GN | BAND_AN:
case BAND_A | BAND_B | BAND_G | BAND_GN | BAND_AN | BAND_AAC:
case BAND_B | BAND_G | BAND_GN:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_bg\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_bg,
sizeof(supported_rates_bg));
break;
case BAND_A:
case BAND_A | BAND_G:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_a\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_a,
sizeof(supported_rates_a));
break;
case BAND_AN:
case BAND_A | BAND_AN:
case BAND_A | BAND_AN | BAND_AAC:
case BAND_A | BAND_G | BAND_AN | BAND_GN:
case BAND_A | BAND_G | BAND_AN | BAND_GN | BAND_AAC:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_a\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_a,
sizeof(supported_rates_a));
break;
case BAND_GN:
mwifiex_dbg(adapter, INFO, "info: infra band=%d\t"
"supported_rates_n\n",
adapter->config_bands);
k = mwifiex_copy_rates(rates, k, supported_rates_n,
sizeof(supported_rates_n));
break;
}
} else {
switch (adapter->adhoc_start_band) {
case BAND_B:
mwifiex_dbg(adapter, INFO, "info: adhoc B\n");
k = mwifiex_copy_rates(rates, k, adhoc_rates_b,
sizeof(adhoc_rates_b));
break;
case BAND_G:
case BAND_G | BAND_GN:
mwifiex_dbg(adapter, INFO, "info: adhoc G only\n");
k = mwifiex_copy_rates(rates, k, adhoc_rates_g,
sizeof(adhoc_rates_g));
break;
case BAND_B | BAND_G:
case BAND_B | BAND_G | BAND_GN:
mwifiex_dbg(adapter, INFO, "info: adhoc BG\n");
k = mwifiex_copy_rates(rates, k, adhoc_rates_bg,
sizeof(adhoc_rates_bg));
break;
case BAND_A:
case BAND_A | BAND_AN:
mwifiex_dbg(adapter, INFO, "info: adhoc A\n");
k = mwifiex_copy_rates(rates, k, adhoc_rates_a,
sizeof(adhoc_rates_a));
break;
}
}
return k;
}
u8 mwifiex_adjust_data_rate(struct mwifiex_private *priv,
u8 rx_rate, u8 rate_info)
{
u8 rate_index = 0;
if ((rate_info & BIT(0)) && (rate_info & BIT(1)))
rate_index = MWIFIEX_RATE_INDEX_MCS0 +
MWIFIEX_BW20_MCS_NUM + rx_rate;
else if (rate_info & BIT(0))
rate_index = MWIFIEX_RATE_INDEX_MCS0 + rx_rate;
else
rate_index = (rx_rate > MWIFIEX_RATE_INDEX_OFDM0) ?
rx_rate - 1 : rx_rate;
return rate_index;
}
