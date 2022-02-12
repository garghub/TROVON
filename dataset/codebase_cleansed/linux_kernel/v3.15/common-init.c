int ath9k_cmn_init_channels_rates(struct ath_common *common)
{
struct ath_hw *ah = (struct ath_hw *)common->ah;
void *channels;
BUILD_BUG_ON(ARRAY_SIZE(ath9k_2ghz_chantable) +
ARRAY_SIZE(ath9k_5ghz_chantable) !=
ATH9K_NUM_CHANNELS);
if (ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ) {
channels = devm_kzalloc(ah->dev,
sizeof(ath9k_2ghz_chantable), GFP_KERNEL);
if (!channels)
return -ENOMEM;
memcpy(channels, ath9k_2ghz_chantable,
sizeof(ath9k_2ghz_chantable));
common->sbands[IEEE80211_BAND_2GHZ].channels = channels;
common->sbands[IEEE80211_BAND_2GHZ].band = IEEE80211_BAND_2GHZ;
common->sbands[IEEE80211_BAND_2GHZ].n_channels =
ARRAY_SIZE(ath9k_2ghz_chantable);
common->sbands[IEEE80211_BAND_2GHZ].bitrates = ath9k_legacy_rates;
common->sbands[IEEE80211_BAND_2GHZ].n_bitrates =
ARRAY_SIZE(ath9k_legacy_rates);
}
if (ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ) {
channels = devm_kzalloc(ah->dev,
sizeof(ath9k_5ghz_chantable), GFP_KERNEL);
if (!channels)
return -ENOMEM;
memcpy(channels, ath9k_5ghz_chantable,
sizeof(ath9k_5ghz_chantable));
common->sbands[IEEE80211_BAND_5GHZ].channels = channels;
common->sbands[IEEE80211_BAND_5GHZ].band = IEEE80211_BAND_5GHZ;
common->sbands[IEEE80211_BAND_5GHZ].n_channels =
ARRAY_SIZE(ath9k_5ghz_chantable);
common->sbands[IEEE80211_BAND_5GHZ].bitrates =
ath9k_legacy_rates + 4;
common->sbands[IEEE80211_BAND_5GHZ].n_bitrates =
ARRAY_SIZE(ath9k_legacy_rates) - 4;
}
return 0;
}
void ath9k_cmn_setup_ht_cap(struct ath_hw *ah,
struct ieee80211_sta_ht_cap *ht_info)
{
struct ath_common *common = ath9k_hw_common(ah);
u8 tx_streams, rx_streams;
int i, max_streams;
ht_info->ht_supported = true;
ht_info->cap = IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
IEEE80211_HT_CAP_SM_PS |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_DSSSCCK40;
if (ah->caps.hw_caps & ATH9K_HW_CAP_LDPC)
ht_info->cap |= IEEE80211_HT_CAP_LDPC_CODING;
if (ah->caps.hw_caps & ATH9K_HW_CAP_SGI_20)
ht_info->cap |= IEEE80211_HT_CAP_SGI_20;
ht_info->ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
ht_info->ampdu_density = IEEE80211_HT_MPDU_DENSITY_8;
if (AR_SREV_9271(ah) || AR_SREV_9330(ah) || AR_SREV_9485(ah) || AR_SREV_9565(ah))
max_streams = 1;
else if (AR_SREV_9462(ah))
max_streams = 2;
else if (AR_SREV_9300_20_OR_LATER(ah))
max_streams = 3;
else
max_streams = 2;
if (AR_SREV_9280_20_OR_LATER(ah)) {
if (max_streams >= 2)
ht_info->cap |= IEEE80211_HT_CAP_TX_STBC;
ht_info->cap |= (1 << IEEE80211_HT_CAP_RX_STBC_SHIFT);
}
memset(&ht_info->mcs, 0, sizeof(ht_info->mcs));
tx_streams = ath9k_cmn_count_streams(ah->txchainmask, max_streams);
rx_streams = ath9k_cmn_count_streams(ah->rxchainmask, max_streams);
ath_dbg(common, CONFIG, "TX streams %d, RX streams: %d\n",
tx_streams, rx_streams);
if (tx_streams != rx_streams) {
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
ht_info->mcs.tx_params |= ((tx_streams - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
}
for (i = 0; i < rx_streams; i++)
ht_info->mcs.rx_mask[i] = 0xff;
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_DEFINED;
}
void ath9k_cmn_reload_chainmask(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
if (!(ah->caps.hw_caps & ATH9K_HW_CAP_HT))
return;
if (ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ)
ath9k_cmn_setup_ht_cap(ah,
&common->sbands[IEEE80211_BAND_2GHZ].ht_cap);
if (ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ)
ath9k_cmn_setup_ht_cap(ah,
&common->sbands[IEEE80211_BAND_5GHZ].ht_cap);
}
