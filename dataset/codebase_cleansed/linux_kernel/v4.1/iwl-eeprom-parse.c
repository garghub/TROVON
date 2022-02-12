static u16 iwl_eeprom_query16(const u8 *eeprom, size_t eeprom_size, int offset)
{
if (WARN_ON(offset + sizeof(u16) > eeprom_size))
return 0;
return le16_to_cpup((__le16 *)(eeprom + offset));
}
static u32 eeprom_indirect_address(const u8 *eeprom, size_t eeprom_size,
u32 address)
{
u16 offset = 0;
if ((address & INDIRECT_ADDRESS) == 0)
return address;
switch (address & INDIRECT_TYPE_MSK) {
case INDIRECT_HOST:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_HOST);
break;
case INDIRECT_GENERAL:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_GENERAL);
break;
case INDIRECT_REGULATORY:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_REGULATORY);
break;
case INDIRECT_TXP_LIMIT:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_TXP_LIMIT);
break;
case INDIRECT_TXP_LIMIT_SIZE:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_TXP_LIMIT_SIZE);
break;
case INDIRECT_CALIBRATION:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_CALIBRATION);
break;
case INDIRECT_PROCESS_ADJST:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_PROCESS_ADJST);
break;
case INDIRECT_OTHERS:
offset = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_LINK_OTHERS);
break;
default:
WARN_ON(1);
break;
}
return (address & ADDRESS_MSK) + (offset << 1);
}
static const u8 *iwl_eeprom_query_addr(const u8 *eeprom, size_t eeprom_size,
u32 offset)
{
u32 address = eeprom_indirect_address(eeprom, eeprom_size, offset);
if (WARN_ON(address >= eeprom_size))
return NULL;
return &eeprom[address];
}
static int iwl_eeprom_read_calib(const u8 *eeprom, size_t eeprom_size,
struct iwl_nvm_data *data)
{
struct iwl_eeprom_calib_hdr *hdr;
hdr = (void *)iwl_eeprom_query_addr(eeprom, eeprom_size,
EEPROM_CALIB_ALL);
if (!hdr)
return -ENODATA;
data->calib_version = hdr->version;
data->calib_voltage = hdr->voltage;
return 0;
}
static s8 iwl_get_max_txpwr_half_dbm(const struct iwl_nvm_data *data,
struct iwl_eeprom_enhanced_txpwr *txp)
{
s8 result = 0;
if (data->valid_tx_ant & ANT_A && txp->chain_a_max > result)
result = txp->chain_a_max;
if (data->valid_tx_ant & ANT_B && txp->chain_b_max > result)
result = txp->chain_b_max;
if (data->valid_tx_ant & ANT_C && txp->chain_c_max > result)
result = txp->chain_c_max;
if ((data->valid_tx_ant == ANT_AB ||
data->valid_tx_ant == ANT_BC ||
data->valid_tx_ant == ANT_AC) && txp->mimo2_max > result)
result = txp->mimo2_max;
if (data->valid_tx_ant == ANT_ABC && txp->mimo3_max > result)
result = txp->mimo3_max;
return result;
}
static void
iwl_eeprom_enh_txp_read_element(struct iwl_nvm_data *data,
struct iwl_eeprom_enhanced_txpwr *txp,
int n_channels, s8 max_txpower_avg)
{
int ch_idx;
enum ieee80211_band band;
band = txp->flags & IWL_EEPROM_ENH_TXP_FL_BAND_52G ?
IEEE80211_BAND_5GHZ : IEEE80211_BAND_2GHZ;
for (ch_idx = 0; ch_idx < n_channels; ch_idx++) {
struct ieee80211_channel *chan = &data->channels[ch_idx];
if (txp->channel != 0 && chan->hw_value != txp->channel)
continue;
if (band != chan->band)
continue;
if (chan->max_power < max_txpower_avg &&
!(txp->flags & IWL_EEPROM_ENH_TXP_FL_40MHZ))
chan->max_power = max_txpower_avg;
}
}
static void iwl_eeprom_enhanced_txpower(struct device *dev,
struct iwl_nvm_data *data,
const u8 *eeprom, size_t eeprom_size,
int n_channels)
{
struct iwl_eeprom_enhanced_txpwr *txp_array, *txp;
int idx, entries;
__le16 *txp_len;
s8 max_txp_avg_halfdbm;
BUILD_BUG_ON(sizeof(struct iwl_eeprom_enhanced_txpwr) != 8);
txp_len = (__le16 *)iwl_eeprom_query_addr(eeprom, eeprom_size,
EEPROM_TXP_SZ_OFFS);
entries = le16_to_cpup(txp_len) * 2 / EEPROM_TXP_ENTRY_LEN;
txp_array = (void *)iwl_eeprom_query_addr(eeprom, eeprom_size,
EEPROM_TXP_OFFS);
for (idx = 0; idx < entries; idx++) {
txp = &txp_array[idx];
if (!(txp->flags & IWL_EEPROM_ENH_TXP_FL_VALID))
continue;
IWL_DEBUG_EEPROM(dev, "%s %d:\t %s%s%s%s%s%s%s%s (0x%02x)\n",
(txp->channel && (txp->flags &
IWL_EEPROM_ENH_TXP_FL_COMMON_TYPE)) ?
"Common " : (txp->channel) ?
"Channel" : "Common",
(txp->channel),
TXP_CHECK_AND_PRINT(VALID),
TXP_CHECK_AND_PRINT(BAND_52G),
TXP_CHECK_AND_PRINT(OFDM),
TXP_CHECK_AND_PRINT(40MHZ),
TXP_CHECK_AND_PRINT(HT_AP),
TXP_CHECK_AND_PRINT(RES1),
TXP_CHECK_AND_PRINT(RES2),
TXP_CHECK_AND_PRINT(COMMON_TYPE),
txp->flags);
IWL_DEBUG_EEPROM(dev,
"\t\t chain_A: 0x%02x chain_B: 0X%02x chain_C: 0X%02x\n",
txp->chain_a_max, txp->chain_b_max,
txp->chain_c_max);
IWL_DEBUG_EEPROM(dev,
"\t\t MIMO2: 0x%02x MIMO3: 0x%02x High 20_on_40: 0x%02x Low 20_on_40: 0x%02x\n",
txp->mimo2_max, txp->mimo3_max,
((txp->delta_20_in_40 & 0xf0) >> 4),
(txp->delta_20_in_40 & 0x0f));
max_txp_avg_halfdbm = iwl_get_max_txpwr_half_dbm(data, txp);
iwl_eeprom_enh_txp_read_element(data, txp, n_channels,
DIV_ROUND_UP(max_txp_avg_halfdbm, 2));
if (max_txp_avg_halfdbm > data->max_tx_pwr_half_dbm)
data->max_tx_pwr_half_dbm = max_txp_avg_halfdbm;
}
}
static void iwl_init_band_reference(const struct iwl_cfg *cfg,
const u8 *eeprom, size_t eeprom_size,
int eeprom_band, int *eeprom_ch_count,
const struct iwl_eeprom_channel **ch_info,
const u8 **eeprom_ch_array)
{
u32 offset = cfg->eeprom_params->regulatory_bands[eeprom_band - 1];
offset |= INDIRECT_ADDRESS | INDIRECT_REGULATORY;
*ch_info = (void *)iwl_eeprom_query_addr(eeprom, eeprom_size, offset);
switch (eeprom_band) {
case 1:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_1);
*eeprom_ch_array = iwl_eeprom_band_1;
break;
case 2:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_2);
*eeprom_ch_array = iwl_eeprom_band_2;
break;
case 3:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_3);
*eeprom_ch_array = iwl_eeprom_band_3;
break;
case 4:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_4);
*eeprom_ch_array = iwl_eeprom_band_4;
break;
case 5:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_5);
*eeprom_ch_array = iwl_eeprom_band_5;
break;
case 6:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_6);
*eeprom_ch_array = iwl_eeprom_band_6;
break;
case 7:
*eeprom_ch_count = ARRAY_SIZE(iwl_eeprom_band_7);
*eeprom_ch_array = iwl_eeprom_band_7;
break;
default:
*eeprom_ch_count = 0;
*eeprom_ch_array = NULL;
WARN_ON(1);
}
}
static void iwl_mod_ht40_chan_info(struct device *dev,
struct iwl_nvm_data *data, int n_channels,
enum ieee80211_band band, u16 channel,
const struct iwl_eeprom_channel *eeprom_ch,
u8 clear_ht40_extension_channel)
{
struct ieee80211_channel *chan = NULL;
int i;
for (i = 0; i < n_channels; i++) {
if (data->channels[i].band != band)
continue;
if (data->channels[i].hw_value != channel)
continue;
chan = &data->channels[i];
break;
}
if (!chan)
return;
IWL_DEBUG_EEPROM(dev,
"HT40 Ch. %d [%sGHz] %s%s%s%s%s(0x%02x %ddBm): Ad-Hoc %ssupported\n",
channel,
band == IEEE80211_BAND_5GHZ ? "5.2" : "2.4",
CHECK_AND_PRINT(IBSS),
CHECK_AND_PRINT(ACTIVE),
CHECK_AND_PRINT(RADAR),
CHECK_AND_PRINT(WIDE),
CHECK_AND_PRINT(DFS),
eeprom_ch->flags,
eeprom_ch->max_power_avg,
((eeprom_ch->flags & EEPROM_CHANNEL_IBSS) &&
!(eeprom_ch->flags & EEPROM_CHANNEL_RADAR)) ? ""
: "not ");
if (eeprom_ch->flags & EEPROM_CHANNEL_VALID)
chan->flags &= ~clear_ht40_extension_channel;
}
static int iwl_init_channel_map(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const u8 *eeprom, size_t eeprom_size)
{
int band, ch_idx;
const struct iwl_eeprom_channel *eeprom_ch_info;
const u8 *eeprom_ch_array;
int eeprom_ch_count;
int n_channels = 0;
for (band = 1; band <= 5; band++) {
struct ieee80211_channel *channel;
iwl_init_band_reference(cfg, eeprom, eeprom_size, band,
&eeprom_ch_count, &eeprom_ch_info,
&eeprom_ch_array);
for (ch_idx = 0; ch_idx < eeprom_ch_count; ch_idx++) {
const struct iwl_eeprom_channel *eeprom_ch;
eeprom_ch = &eeprom_ch_info[ch_idx];
if (!(eeprom_ch->flags & EEPROM_CHANNEL_VALID)) {
IWL_DEBUG_EEPROM(dev,
"Ch. %d Flags %x [%sGHz] - No traffic\n",
eeprom_ch_array[ch_idx],
eeprom_ch_info[ch_idx].flags,
(band != 1) ? "5.2" : "2.4");
continue;
}
channel = &data->channels[n_channels];
n_channels++;
channel->hw_value = eeprom_ch_array[ch_idx];
channel->band = (band == 1) ? IEEE80211_BAND_2GHZ
: IEEE80211_BAND_5GHZ;
channel->center_freq =
ieee80211_channel_to_frequency(
channel->hw_value, channel->band);
channel->flags = IEEE80211_CHAN_NO_HT40;
if (!(eeprom_ch->flags & EEPROM_CHANNEL_IBSS))
channel->flags |= IEEE80211_CHAN_NO_IR;
if (!(eeprom_ch->flags & EEPROM_CHANNEL_ACTIVE))
channel->flags |= IEEE80211_CHAN_NO_IR;
if (eeprom_ch->flags & EEPROM_CHANNEL_RADAR)
channel->flags |= IEEE80211_CHAN_RADAR;
channel->max_power =
eeprom_ch_info[ch_idx].max_power_avg;
IWL_DEBUG_EEPROM(dev,
"Ch. %d [%sGHz] %s%s%s%s%s%s(0x%02x %ddBm): Ad-Hoc %ssupported\n",
channel->hw_value,
(band != 1) ? "5.2" : "2.4",
CHECK_AND_PRINT_I(VALID),
CHECK_AND_PRINT_I(IBSS),
CHECK_AND_PRINT_I(ACTIVE),
CHECK_AND_PRINT_I(RADAR),
CHECK_AND_PRINT_I(WIDE),
CHECK_AND_PRINT_I(DFS),
eeprom_ch_info[ch_idx].flags,
eeprom_ch_info[ch_idx].max_power_avg,
((eeprom_ch_info[ch_idx].flags &
EEPROM_CHANNEL_IBSS) &&
!(eeprom_ch_info[ch_idx].flags &
EEPROM_CHANNEL_RADAR))
? "" : "not ");
}
}
if (cfg->eeprom_params->enhanced_txpower) {
iwl_eeprom_enhanced_txpower(dev, data, eeprom, eeprom_size,
n_channels);
} else {
int i;
data->max_tx_pwr_half_dbm = -128;
for (i = 0; i < n_channels; i++)
data->max_tx_pwr_half_dbm =
max_t(s8, data->max_tx_pwr_half_dbm,
data->channels[i].max_power * 2);
}
if (cfg->eeprom_params->regulatory_bands[5] ==
EEPROM_REGULATORY_BAND_NO_HT40 &&
cfg->eeprom_params->regulatory_bands[6] ==
EEPROM_REGULATORY_BAND_NO_HT40)
return n_channels;
for (band = 6; band <= 7; band++) {
enum ieee80211_band ieeeband;
iwl_init_band_reference(cfg, eeprom, eeprom_size, band,
&eeprom_ch_count, &eeprom_ch_info,
&eeprom_ch_array);
ieeeband = (band == 6) ? IEEE80211_BAND_2GHZ
: IEEE80211_BAND_5GHZ;
for (ch_idx = 0; ch_idx < eeprom_ch_count; ch_idx++) {
iwl_mod_ht40_chan_info(dev, data, n_channels, ieeeband,
eeprom_ch_array[ch_idx],
&eeprom_ch_info[ch_idx],
IEEE80211_CHAN_NO_HT40PLUS);
iwl_mod_ht40_chan_info(dev, data, n_channels, ieeeband,
eeprom_ch_array[ch_idx] + 4,
&eeprom_ch_info[ch_idx],
IEEE80211_CHAN_NO_HT40MINUS);
}
}
return n_channels;
}
int iwl_init_sband_channels(struct iwl_nvm_data *data,
struct ieee80211_supported_band *sband,
int n_channels, enum ieee80211_band band)
{
struct ieee80211_channel *chan = &data->channels[0];
int n = 0, idx = 0;
while (chan->band != band && idx < n_channels)
chan = &data->channels[++idx];
sband->channels = &data->channels[idx];
while (chan->band == band && idx < n_channels) {
chan = &data->channels[++idx];
n++;
}
sband->n_channels = n;
return n;
}
void iwl_init_ht_hw_capab(const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
struct ieee80211_sta_ht_cap *ht_info,
enum ieee80211_band band,
u8 tx_chains, u8 rx_chains)
{
int max_bit_rate = 0;
tx_chains = hweight8(tx_chains);
if (cfg->rx_with_siso_diversity)
rx_chains = 1;
else
rx_chains = hweight8(rx_chains);
if (!(data->sku_cap_11n_enable) || !cfg->ht_params) {
ht_info->ht_supported = false;
return;
}
if (data->sku_cap_mimo_disabled)
rx_chains = 1;
ht_info->ht_supported = true;
ht_info->cap = IEEE80211_HT_CAP_DSSSCCK40;
if (cfg->ht_params->stbc) {
ht_info->cap |= (1 << IEEE80211_HT_CAP_RX_STBC_SHIFT);
if (tx_chains > 1)
ht_info->cap |= IEEE80211_HT_CAP_TX_STBC;
}
if (cfg->ht_params->ldpc)
ht_info->cap |= IEEE80211_HT_CAP_LDPC_CODING;
if (iwlwifi_mod_params.amsdu_size_8K)
ht_info->cap |= IEEE80211_HT_CAP_MAX_AMSDU;
ht_info->ampdu_factor = cfg->max_ht_ampdu_exponent;
ht_info->ampdu_density = IEEE80211_HT_MPDU_DENSITY_4;
ht_info->mcs.rx_mask[0] = 0xFF;
if (rx_chains >= 2)
ht_info->mcs.rx_mask[1] = 0xFF;
if (rx_chains >= 3)
ht_info->mcs.rx_mask[2] = 0xFF;
if (cfg->ht_params->ht_greenfield_support)
ht_info->cap |= IEEE80211_HT_CAP_GRN_FLD;
ht_info->cap |= IEEE80211_HT_CAP_SGI_20;
max_bit_rate = MAX_BIT_RATE_20_MHZ;
if (cfg->ht_params->ht40_bands & BIT(band)) {
ht_info->cap |= IEEE80211_HT_CAP_SUP_WIDTH_20_40;
ht_info->cap |= IEEE80211_HT_CAP_SGI_40;
max_bit_rate = MAX_BIT_RATE_40_MHZ;
}
max_bit_rate *= rx_chains;
WARN_ON(max_bit_rate & ~IEEE80211_HT_MCS_RX_HIGHEST_MASK);
ht_info->mcs.rx_highest = cpu_to_le16(max_bit_rate);
ht_info->mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
if (tx_chains != rx_chains) {
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
ht_info->mcs.tx_params |= ((tx_chains - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
}
}
static void iwl_init_sbands(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const u8 *eeprom, size_t eeprom_size)
{
int n_channels = iwl_init_channel_map(dev, cfg, data,
eeprom, eeprom_size);
int n_used = 0;
struct ieee80211_supported_band *sband;
sband = &data->bands[IEEE80211_BAND_2GHZ];
sband->band = IEEE80211_BAND_2GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_24_OFFS];
sband->n_bitrates = N_RATES_24;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_2GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_2GHZ,
data->valid_tx_ant, data->valid_rx_ant);
sband = &data->bands[IEEE80211_BAND_5GHZ];
sband->band = IEEE80211_BAND_5GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_52_OFFS];
sband->n_bitrates = N_RATES_52;
n_used += iwl_init_sband_channels(data, sband, n_channels,
IEEE80211_BAND_5GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, IEEE80211_BAND_5GHZ,
data->valid_tx_ant, data->valid_rx_ant);
if (n_channels != n_used)
IWL_ERR_DEV(dev, "EEPROM: used only %d of %d channels\n",
n_used, n_channels);
}
struct iwl_nvm_data *
iwl_parse_eeprom_data(struct device *dev, const struct iwl_cfg *cfg,
const u8 *eeprom, size_t eeprom_size)
{
struct iwl_nvm_data *data;
const void *tmp;
u16 radio_cfg, sku;
if (WARN_ON(!cfg || !cfg->eeprom_params))
return NULL;
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) * IWL_NUM_CHANNELS,
GFP_KERNEL);
if (!data)
return NULL;
tmp = iwl_eeprom_query_addr(eeprom, eeprom_size, EEPROM_MAC_ADDRESS);
if (!tmp)
goto err_free;
memcpy(data->hw_addr, tmp, ETH_ALEN);
data->n_hw_addrs = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_NUM_MAC_ADDRESS);
if (iwl_eeprom_read_calib(eeprom, eeprom_size, data))
goto err_free;
tmp = iwl_eeprom_query_addr(eeprom, eeprom_size, EEPROM_XTAL);
if (!tmp)
goto err_free;
memcpy(data->xtal_calib, tmp, sizeof(data->xtal_calib));
tmp = iwl_eeprom_query_addr(eeprom, eeprom_size,
EEPROM_RAW_TEMPERATURE);
if (!tmp)
goto err_free;
data->raw_temperature = *(__le16 *)tmp;
tmp = iwl_eeprom_query_addr(eeprom, eeprom_size,
EEPROM_KELVIN_TEMPERATURE);
if (!tmp)
goto err_free;
data->kelvin_temperature = *(__le16 *)tmp;
data->kelvin_voltage = *((__le16 *)tmp + 1);
radio_cfg = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_RADIO_CONFIG);
data->radio_cfg_dash = EEPROM_RF_CFG_DASH_MSK(radio_cfg);
data->radio_cfg_pnum = EEPROM_RF_CFG_PNUM_MSK(radio_cfg);
data->radio_cfg_step = EEPROM_RF_CFG_STEP_MSK(radio_cfg);
data->radio_cfg_type = EEPROM_RF_CFG_TYPE_MSK(radio_cfg);
data->valid_rx_ant = EEPROM_RF_CFG_RX_ANT_MSK(radio_cfg);
data->valid_tx_ant = EEPROM_RF_CFG_TX_ANT_MSK(radio_cfg);
sku = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_SKU_CAP);
data->sku_cap_11n_enable = sku & EEPROM_SKU_CAP_11N_ENABLE;
data->sku_cap_amt_enable = sku & EEPROM_SKU_CAP_AMT_ENABLE;
data->sku_cap_band_24GHz_enable = sku & EEPROM_SKU_CAP_BAND_24GHZ;
data->sku_cap_band_52GHz_enable = sku & EEPROM_SKU_CAP_BAND_52GHZ;
data->sku_cap_ipan_enable = sku & EEPROM_SKU_CAP_IPAN_ENABLE;
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
data->sku_cap_11n_enable = false;
data->nvm_version = iwl_eeprom_query16(eeprom, eeprom_size,
EEPROM_VERSION);
if (cfg->valid_tx_ant)
data->valid_tx_ant = cfg->valid_tx_ant;
if (cfg->valid_rx_ant)
data->valid_rx_ant = cfg->valid_rx_ant;
if (!data->valid_tx_ant || !data->valid_rx_ant) {
IWL_ERR_DEV(dev, "invalid antennas (0x%x, 0x%x)\n",
data->valid_tx_ant, data->valid_rx_ant);
goto err_free;
}
iwl_init_sbands(dev, cfg, data, eeprom, eeprom_size);
return data;
err_free:
kfree(data);
return NULL;
}
int iwl_nvm_check_version(struct iwl_nvm_data *data,
struct iwl_trans *trans)
{
if (data->nvm_version >= trans->cfg->nvm_ver ||
data->calib_version >= trans->cfg->nvm_calib_ver) {
IWL_DEBUG_INFO(trans, "device EEPROM VER=0x%x, CALIB=0x%x\n",
data->nvm_version, data->calib_version);
return 0;
}
IWL_ERR(trans,
"Unsupported (too old) EEPROM VER=0x%x < 0x%x CALIB=0x%x < 0x%x\n",
data->nvm_version, trans->cfg->nvm_ver,
data->calib_version, trans->cfg->nvm_calib_ver);
return -EINVAL;
}
