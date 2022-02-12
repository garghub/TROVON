static int iwl_init_channel_map(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 * const nvm_ch_flags)
{
int ch_idx;
int n_channels = 0;
struct ieee80211_channel *channel;
u16 ch_flags;
bool is_5ghz;
int num_of_ch;
const u8 *nvm_chan;
if (cfg->device_family != IWL_DEVICE_FAMILY_8000) {
num_of_ch = IWL_NUM_CHANNELS;
nvm_chan = &iwl_nvm_channels[0];
} else {
num_of_ch = IWL_NUM_CHANNELS_FAMILY_8000;
nvm_chan = &iwl_nvm_channels_family_8000[0];
}
for (ch_idx = 0; ch_idx < num_of_ch; ch_idx++) {
ch_flags = __le16_to_cpup(nvm_ch_flags + ch_idx);
if (ch_idx >= NUM_2GHZ_CHANNELS &&
!data->sku_cap_band_52GHz_enable)
ch_flags &= ~NVM_CHANNEL_VALID;
if (!(ch_flags & NVM_CHANNEL_VALID)) {
IWL_DEBUG_EEPROM(dev,
"Ch. %d Flags %x [%sGHz] - No traffic\n",
nvm_chan[ch_idx],
ch_flags,
(ch_idx >= NUM_2GHZ_CHANNELS) ?
"5.2" : "2.4");
continue;
}
channel = &data->channels[n_channels];
n_channels++;
channel->hw_value = nvm_chan[ch_idx];
channel->band = (ch_idx < NUM_2GHZ_CHANNELS) ?
IEEE80211_BAND_2GHZ : IEEE80211_BAND_5GHZ;
channel->center_freq =
ieee80211_channel_to_frequency(
channel->hw_value, channel->band);
channel->flags = IEEE80211_CHAN_NO_HT40;
if (ch_idx < NUM_2GHZ_CHANNELS &&
(ch_flags & NVM_CHANNEL_40MHZ)) {
if (nvm_chan[ch_idx] <= LAST_2GHZ_HT_PLUS)
channel->flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
if (nvm_chan[ch_idx] >= FIRST_2GHZ_HT_MINUS)
channel->flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
} else if (nvm_chan[ch_idx] <= LAST_5GHZ_HT &&
(ch_flags & NVM_CHANNEL_40MHZ)) {
if ((ch_idx - NUM_2GHZ_CHANNELS) % 2 == 0)
channel->flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
else
channel->flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
}
if (!(ch_flags & NVM_CHANNEL_80MHZ))
channel->flags |= IEEE80211_CHAN_NO_80MHZ;
if (!(ch_flags & NVM_CHANNEL_160MHZ))
channel->flags |= IEEE80211_CHAN_NO_160MHZ;
if (!(ch_flags & NVM_CHANNEL_IBSS))
channel->flags |= IEEE80211_CHAN_NO_IR;
if (!(ch_flags & NVM_CHANNEL_ACTIVE))
channel->flags |= IEEE80211_CHAN_NO_IR;
if (ch_flags & NVM_CHANNEL_RADAR)
channel->flags |= IEEE80211_CHAN_RADAR;
channel->max_power = DEFAULT_MAX_TX_POWER;
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
static void iwl_init_vht_hw_capab(const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
struct ieee80211_sta_vht_cap *vht_cap,
u8 tx_chains, u8 rx_chains)
{
int num_rx_ants = num_of_ant(rx_chains);
int num_tx_ants = num_of_ant(tx_chains);
vht_cap->vht_supported = true;
vht_cap->cap = IEEE80211_VHT_CAP_SHORT_GI_80 |
IEEE80211_VHT_CAP_RXSTBC_1 |
IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
3 << IEEE80211_VHT_CAP_BEAMFORMEE_STS_SHIFT |
7 << IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;
if (num_tx_ants > 1)
vht_cap->cap |= IEEE80211_VHT_CAP_TXSTBC;
else
vht_cap->cap |= IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN;
if (iwlwifi_mod_params.amsdu_size_8K)
vht_cap->cap |= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991;
vht_cap->vht_mcs.rx_mcs_map =
cpu_to_le16(IEEE80211_VHT_MCS_SUPPORT_0_9 << 0 |
IEEE80211_VHT_MCS_SUPPORT_0_9 << 2 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 4 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 6 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 8 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 10 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 12 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 14);
if (num_rx_ants == 1 || cfg->rx_with_siso_diversity) {
vht_cap->cap |= IEEE80211_VHT_CAP_RX_ANTENNA_PATTERN;
vht_cap->vht_mcs.rx_mcs_map |=
cpu_to_le16(IEEE80211_VHT_MCS_NOT_SUPPORTED << 2);
}
vht_cap->vht_mcs.tx_mcs_map = vht_cap->vht_mcs.rx_mcs_map;
}
static void iwl_init_sbands(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 *ch_section, bool enable_vht,
u8 tx_chains, u8 rx_chains)
{
int n_channels;
int n_used = 0;
struct ieee80211_supported_band *sband;
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
n_channels = iwl_init_channel_map(
dev, cfg, data,
&ch_section[NVM_CHANNELS]);
else
n_channels = iwl_init_channel_map(
dev, cfg, data,
&ch_section[NVM_CHANNELS_FAMILY_8000]);
sband = &data->bands[IEEE80211_BAND_2GHZ];
sband->band = IEEE80211_BAND_2GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_24_OFFS];
sband->n_bitrates = N_RATES_24;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_2GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_2GHZ,
tx_chains, rx_chains);
sband = &data->bands[IEEE80211_BAND_5GHZ];
sband->band = IEEE80211_BAND_5GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_52_OFFS];
sband->n_bitrates = N_RATES_52;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_5GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_5GHZ,
tx_chains, rx_chains);
if (enable_vht)
iwl_init_vht_hw_capab(cfg, data, &sband->vht_cap,
tx_chains, rx_chains);
if (n_channels != n_used)
IWL_ERR_DEV(dev, "NVM: used only %d of %d channels\n",
n_used, n_channels);
}
static int iwl_get_sku(const struct iwl_cfg *cfg,
const __le16 *nvm_sw)
{
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
return le16_to_cpup(nvm_sw + SKU);
else
return le32_to_cpup((__le32 *)(nvm_sw + SKU_FAMILY_8000));
}
static int iwl_get_nvm_version(const struct iwl_cfg *cfg,
const __le16 *nvm_sw)
{
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
return le16_to_cpup(nvm_sw + NVM_VERSION);
else
return le32_to_cpup((__le32 *)(nvm_sw +
NVM_VERSION_FAMILY_8000));
}
static int iwl_get_radio_cfg(const struct iwl_cfg *cfg,
const __le16 *nvm_sw)
{
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
return le16_to_cpup(nvm_sw + RADIO_CFG);
else
return le32_to_cpup((__le32 *)(nvm_sw + RADIO_CFG_FAMILY_8000));
}
static int iwl_get_n_hw_addrs(const struct iwl_cfg *cfg,
const __le16 *nvm_sw)
{
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
return le16_to_cpup(nvm_sw + N_HW_ADDRS);
else
return le32_to_cpup((__le32 *)(nvm_sw + N_HW_ADDRS_FAMILY_8000))
& N_HW_ADDRS_MASK_FAMILY_8000;
}
static void iwl_set_radio_cfg(const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
u32 radio_cfg)
{
if (cfg->device_family != IWL_DEVICE_FAMILY_8000) {
data->radio_cfg_type = NVM_RF_CFG_TYPE_MSK(radio_cfg);
data->radio_cfg_step = NVM_RF_CFG_STEP_MSK(radio_cfg);
data->radio_cfg_dash = NVM_RF_CFG_DASH_MSK(radio_cfg);
data->radio_cfg_pnum = NVM_RF_CFG_PNUM_MSK(radio_cfg);
return;
}
data->radio_cfg_type = NVM_RF_CFG_TYPE_MSK_FAMILY_8000(radio_cfg);
data->radio_cfg_step = NVM_RF_CFG_STEP_MSK_FAMILY_8000(radio_cfg);
data->radio_cfg_dash = NVM_RF_CFG_DASH_MSK_FAMILY_8000(radio_cfg);
data->radio_cfg_pnum = NVM_RF_CFG_FLAVOR_MSK_FAMILY_8000(radio_cfg);
}
static void iwl_set_hw_address(const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 *nvm_sec)
{
u8 hw_addr[ETH_ALEN];
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
memcpy(hw_addr, nvm_sec + HW_ADDR, ETH_ALEN);
else
memcpy(hw_addr, nvm_sec + MAC_ADDRESS_OVERRIDE_FAMILY_8000,
ETH_ALEN);
data->hw_addr[0] = hw_addr[1];
data->hw_addr[1] = hw_addr[0];
data->hw_addr[2] = hw_addr[3];
data->hw_addr[3] = hw_addr[2];
data->hw_addr[4] = hw_addr[5];
data->hw_addr[5] = hw_addr[4];
}
struct iwl_nvm_data *
iwl_parse_nvm_data(struct device *dev, const struct iwl_cfg *cfg,
const __le16 *nvm_hw, const __le16 *nvm_sw,
const __le16 *nvm_calib, const __le16 *regulatory,
const __le16 *mac_override, u8 tx_chains, u8 rx_chains)
{
struct iwl_nvm_data *data;
u32 sku;
u32 radio_cfg;
if (cfg->device_family != IWL_DEVICE_FAMILY_8000)
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) *
IWL_NUM_CHANNELS,
GFP_KERNEL);
else
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) *
IWL_NUM_CHANNELS_FAMILY_8000,
GFP_KERNEL);
if (!data)
return NULL;
data->nvm_version = iwl_get_nvm_version(cfg, nvm_sw);
radio_cfg = iwl_get_radio_cfg(cfg, nvm_sw);
iwl_set_radio_cfg(cfg, data, radio_cfg);
sku = iwl_get_sku(cfg, nvm_sw);
data->sku_cap_band_24GHz_enable = sku & NVM_SKU_CAP_BAND_24GHZ;
data->sku_cap_band_52GHz_enable = sku & NVM_SKU_CAP_BAND_52GHZ;
data->sku_cap_11n_enable = sku & NVM_SKU_CAP_11N_ENABLE;
data->sku_cap_11ac_enable = sku & NVM_SKU_CAP_11AC_ENABLE;
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
data->sku_cap_11n_enable = false;
data->n_hw_addrs = iwl_get_n_hw_addrs(cfg, nvm_sw);
if (cfg->device_family != IWL_DEVICE_FAMILY_8000) {
if (!nvm_calib) {
IWL_ERR_DEV(dev,
"Can't parse empty Calib NVM sections\n");
kfree(data);
return NULL;
}
data->xtal_calib[0] = *(nvm_calib + XTAL_CALIB);
data->xtal_calib[1] = *(nvm_calib + XTAL_CALIB + 1);
}
if (cfg->device_family != IWL_DEVICE_FAMILY_8000) {
iwl_set_hw_address(cfg, data, nvm_hw);
iwl_init_sbands(dev, cfg, data, nvm_sw,
sku & NVM_SKU_CAP_11AC_ENABLE, tx_chains,
rx_chains);
} else {
iwl_set_hw_address(cfg, data, mac_override);
iwl_init_sbands(dev, cfg, data, regulatory,
sku & NVM_SKU_CAP_11AC_ENABLE, tx_chains,
rx_chains);
}
data->calib_version = 255;
return data;
}
