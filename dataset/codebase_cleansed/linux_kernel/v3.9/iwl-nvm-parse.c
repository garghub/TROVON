static int iwl_init_channel_map(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 * const nvm_ch_flags)
{
int ch_idx;
int n_channels = 0;
struct ieee80211_channel *channel;
u16 ch_flags;
bool is_5ghz;
for (ch_idx = 0; ch_idx < IWL_NUM_CHANNELS; ch_idx++) {
ch_flags = __le16_to_cpup(nvm_ch_flags + ch_idx);
if (!(ch_flags & NVM_CHANNEL_VALID)) {
IWL_DEBUG_EEPROM(dev,
"Ch. %d Flags %x [%sGHz] - No traffic\n",
iwl_nvm_channels[ch_idx],
ch_flags,
(ch_idx >= NUM_2GHZ_CHANNELS) ?
"5.2" : "2.4");
continue;
}
channel = &data->channels[n_channels];
n_channels++;
channel->hw_value = iwl_nvm_channels[ch_idx];
channel->band = (ch_idx < NUM_2GHZ_CHANNELS) ?
IEEE80211_BAND_2GHZ : IEEE80211_BAND_5GHZ;
channel->center_freq =
ieee80211_channel_to_frequency(
channel->hw_value, channel->band);
channel->flags = IEEE80211_CHAN_NO_HT40;
if (ch_idx < NUM_2GHZ_CHANNELS &&
(ch_flags & NVM_CHANNEL_40MHZ)) {
if (iwl_nvm_channels[ch_idx] <= LAST_2GHZ_HT_PLUS)
channel->flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
if (iwl_nvm_channels[ch_idx] >= FIRST_2GHZ_HT_MINUS)
channel->flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
} else if (iwl_nvm_channels[ch_idx] <= LAST_5GHZ_HT &&
(ch_flags & NVM_CHANNEL_40MHZ)) {
if ((ch_idx - NUM_2GHZ_CHANNELS) % 2 == 0)
channel->flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
else
channel->flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
}
if (!(ch_flags & NVM_CHANNEL_IBSS))
channel->flags |= IEEE80211_CHAN_NO_IBSS;
if (!(ch_flags & NVM_CHANNEL_ACTIVE))
channel->flags |= IEEE80211_CHAN_PASSIVE_SCAN;
if (ch_flags & NVM_CHANNEL_RADAR)
channel->flags |= IEEE80211_CHAN_RADAR;
channel->max_power = 0;
is_5ghz = channel->band == IEEE80211_BAND_5GHZ;
IWL_DEBUG_EEPROM(dev,
"Ch. %d [%sGHz] %s%s%s%s%s%s(0x%02x %ddBm): Ad-Hoc %ssupported\n",
channel->hw_value,
is_5ghz ? "5.2" : "2.4",
CHECK_AND_PRINT_I(VALID),
CHECK_AND_PRINT_I(IBSS),
CHECK_AND_PRINT_I(ACTIVE),
CHECK_AND_PRINT_I(RADAR),
CHECK_AND_PRINT_I(WIDE),
CHECK_AND_PRINT_I(DFS),
ch_flags,
channel->max_power,
((ch_flags & NVM_CHANNEL_IBSS) &&
!(ch_flags & NVM_CHANNEL_RADAR))
? "" : "not ");
}
return n_channels;
}
static void iwl_init_sbands(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data, const __le16 *nvm_sw)
{
int n_channels = iwl_init_channel_map(dev, cfg, data,
&nvm_sw[NVM_CHANNELS]);
int n_used = 0;
struct ieee80211_supported_band *sband;
sband = &data->bands[IEEE80211_BAND_2GHZ];
sband->band = IEEE80211_BAND_2GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_24_OFFS];
sband->n_bitrates = N_RATES_24;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_2GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_2GHZ);
sband = &data->bands[IEEE80211_BAND_5GHZ];
sband->band = IEEE80211_BAND_5GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_52_OFFS];
sband->n_bitrates = N_RATES_52;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_5GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_5GHZ);
if (n_channels != n_used)
IWL_ERR_DEV(dev, "NVM: used only %d of %d channels\n",
n_used, n_channels);
}
struct iwl_nvm_data *
iwl_parse_nvm_data(struct device *dev, const struct iwl_cfg *cfg,
const __le16 *nvm_hw, const __le16 *nvm_sw,
const __le16 *nvm_calib)
{
struct iwl_nvm_data *data;
u8 hw_addr[ETH_ALEN];
u16 radio_cfg, sku;
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) * IWL_NUM_CHANNELS,
GFP_KERNEL);
if (!data)
return NULL;
data->nvm_version = le16_to_cpup(nvm_sw + NVM_VERSION);
radio_cfg = le16_to_cpup(nvm_sw + RADIO_CFG);
data->radio_cfg_type = NVM_RF_CFG_TYPE_MSK(radio_cfg);
data->radio_cfg_step = NVM_RF_CFG_STEP_MSK(radio_cfg);
data->radio_cfg_dash = NVM_RF_CFG_DASH_MSK(radio_cfg);
data->radio_cfg_pnum = NVM_RF_CFG_PNUM_MSK(radio_cfg);
data->valid_tx_ant = NVM_RF_CFG_TX_ANT_MSK(radio_cfg);
data->valid_rx_ant = NVM_RF_CFG_RX_ANT_MSK(radio_cfg);
sku = le16_to_cpup(nvm_sw + SKU);
data->sku_cap_band_24GHz_enable = sku & NVM_SKU_CAP_BAND_24GHZ;
data->sku_cap_band_52GHz_enable = sku & NVM_SKU_CAP_BAND_52GHZ;
data->sku_cap_11n_enable = sku & NVM_SKU_CAP_11N_ENABLE;
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
data->sku_cap_11n_enable = false;
if (cfg->valid_tx_ant)
data->valid_tx_ant = cfg->valid_tx_ant;
if (cfg->valid_rx_ant)
data->valid_rx_ant = cfg->valid_rx_ant;
if (!data->valid_tx_ant || !data->valid_rx_ant) {
IWL_ERR_DEV(dev, "invalid antennas (0x%x, 0x%x)\n",
data->valid_tx_ant, data->valid_rx_ant);
kfree(data);
return NULL;
}
data->n_hw_addrs = le16_to_cpup(nvm_sw + N_HW_ADDRS);
data->xtal_calib[0] = *(nvm_calib + XTAL_CALIB);
data->xtal_calib[1] = *(nvm_calib + XTAL_CALIB + 1);
memcpy(hw_addr, nvm_hw + HW_ADDR, ETH_ALEN);
data->hw_addr[0] = hw_addr[1];
data->hw_addr[1] = hw_addr[0];
data->hw_addr[2] = hw_addr[3];
data->hw_addr[3] = hw_addr[2];
data->hw_addr[4] = hw_addr[5];
data->hw_addr[5] = hw_addr[4];
iwl_init_sbands(dev, cfg, data, nvm_sw);
data->calib_version = 255;
return data;
}
