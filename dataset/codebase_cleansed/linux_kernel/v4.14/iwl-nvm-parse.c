static inline void iwl_nvm_print_channel_flags(struct device *dev, u32 level,
int chan, u16 flags)
{
#define CHECK_AND_PRINT_I(x) \
((flags & NVM_CHANNEL_##x) ? " " #x : "")
if (!(flags & NVM_CHANNEL_VALID)) {
IWL_DEBUG_DEV(dev, level, "Ch. %d: 0x%x: No traffic\n",
chan, flags);
return;
}
IWL_DEBUG_DEV(dev, level,
"Ch. %d: 0x%x:%s%s%s%s%s%s%s%s%s%s%s%s\n",
chan, flags,
CHECK_AND_PRINT_I(VALID),
CHECK_AND_PRINT_I(IBSS),
CHECK_AND_PRINT_I(ACTIVE),
CHECK_AND_PRINT_I(RADAR),
CHECK_AND_PRINT_I(INDOOR_ONLY),
CHECK_AND_PRINT_I(GO_CONCURRENT),
CHECK_AND_PRINT_I(UNIFORM),
CHECK_AND_PRINT_I(20MHZ),
CHECK_AND_PRINT_I(40MHZ),
CHECK_AND_PRINT_I(80MHZ),
CHECK_AND_PRINT_I(160MHZ),
CHECK_AND_PRINT_I(DC_HIGH));
#undef CHECK_AND_PRINT_I
}
static u32 iwl_get_channel_flags(u8 ch_num, int ch_idx, bool is_5ghz,
u16 nvm_flags, const struct iwl_cfg *cfg)
{
u32 flags = IEEE80211_CHAN_NO_HT40;
u32 last_5ghz_ht = LAST_5GHZ_HT;
if (cfg->nvm_type == IWL_NVM_EXT)
last_5ghz_ht = LAST_5GHZ_HT_FAMILY_8000;
if (!is_5ghz && (nvm_flags & NVM_CHANNEL_40MHZ)) {
if (ch_num <= LAST_2GHZ_HT_PLUS)
flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
if (ch_num >= FIRST_2GHZ_HT_MINUS)
flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
} else if (ch_num <= last_5ghz_ht && (nvm_flags & NVM_CHANNEL_40MHZ)) {
if ((ch_idx - NUM_2GHZ_CHANNELS) % 2 == 0)
flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
else
flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
}
if (!(nvm_flags & NVM_CHANNEL_80MHZ))
flags |= IEEE80211_CHAN_NO_80MHZ;
if (!(nvm_flags & NVM_CHANNEL_160MHZ))
flags |= IEEE80211_CHAN_NO_160MHZ;
if (!(nvm_flags & NVM_CHANNEL_IBSS))
flags |= IEEE80211_CHAN_NO_IR;
if (!(nvm_flags & NVM_CHANNEL_ACTIVE))
flags |= IEEE80211_CHAN_NO_IR;
if (nvm_flags & NVM_CHANNEL_RADAR)
flags |= IEEE80211_CHAN_RADAR;
if (nvm_flags & NVM_CHANNEL_INDOOR_ONLY)
flags |= IEEE80211_CHAN_INDOOR_ONLY;
if ((nvm_flags & NVM_CHANNEL_GO_CONCURRENT) &&
(flags & IEEE80211_CHAN_NO_IR))
flags |= IEEE80211_CHAN_IR_CONCURRENT;
return flags;
}
static int iwl_init_channel_map(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 * const nvm_ch_flags,
bool lar_supported, bool no_wide_in_5ghz)
{
int ch_idx;
int n_channels = 0;
struct ieee80211_channel *channel;
u16 ch_flags;
int num_of_ch, num_2ghz_channels;
const u8 *nvm_chan;
if (cfg->nvm_type != IWL_NVM_EXT) {
num_of_ch = IWL_NUM_CHANNELS;
nvm_chan = &iwl_nvm_channels[0];
num_2ghz_channels = NUM_2GHZ_CHANNELS;
} else {
num_of_ch = IWL_NUM_CHANNELS_EXT;
nvm_chan = &iwl_ext_nvm_channels[0];
num_2ghz_channels = NUM_2GHZ_CHANNELS_EXT;
}
for (ch_idx = 0; ch_idx < num_of_ch; ch_idx++) {
bool is_5ghz = (ch_idx >= num_2ghz_channels);
ch_flags = __le16_to_cpup(nvm_ch_flags + ch_idx);
if (is_5ghz && !data->sku_cap_band_52GHz_enable)
continue;
if (no_wide_in_5ghz && is_5ghz) {
ch_flags &= ~(NVM_CHANNEL_40MHZ |
NVM_CHANNEL_80MHZ |
NVM_CHANNEL_160MHZ);
}
if (ch_flags & NVM_CHANNEL_160MHZ)
data->vht160_supported = true;
if (!lar_supported && !(ch_flags & NVM_CHANNEL_VALID)) {
iwl_nvm_print_channel_flags(dev, IWL_DL_EEPROM,
nvm_chan[ch_idx], ch_flags);
continue;
}
channel = &data->channels[n_channels];
n_channels++;
channel->hw_value = nvm_chan[ch_idx];
channel->band = is_5ghz ?
NL80211_BAND_5GHZ : NL80211_BAND_2GHZ;
channel->center_freq =
ieee80211_channel_to_frequency(
channel->hw_value, channel->band);
channel->max_power = IWL_DEFAULT_MAX_TX_POWER;
if (!lar_supported)
channel->flags = iwl_get_channel_flags(nvm_chan[ch_idx],
ch_idx, is_5ghz,
ch_flags, cfg);
else
channel->flags = 0;
iwl_nvm_print_channel_flags(dev, IWL_DL_EEPROM,
channel->hw_value, ch_flags);
IWL_DEBUG_EEPROM(dev, "Ch. %d: %ddBm\n",
channel->hw_value, channel->max_power);
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
unsigned int max_ampdu_exponent = (cfg->max_vht_ampdu_exponent ?:
IEEE80211_VHT_MAX_AMPDU_1024K);
vht_cap->vht_supported = true;
vht_cap->cap = IEEE80211_VHT_CAP_SHORT_GI_80 |
IEEE80211_VHT_CAP_RXSTBC_1 |
IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
3 << IEEE80211_VHT_CAP_BEAMFORMEE_STS_SHIFT |
max_ampdu_exponent <<
IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;
if (data->vht160_supported)
vht_cap->cap |= IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ |
IEEE80211_VHT_CAP_SHORT_GI_160;
if (cfg->vht_mu_mimo_supported)
vht_cap->cap |= IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE;
if (cfg->ht_params->ldpc)
vht_cap->cap |= IEEE80211_VHT_CAP_RXLDPC;
if (data->sku_cap_mimo_disabled) {
num_rx_ants = 1;
num_tx_ants = 1;
}
if (num_tx_ants > 1)
vht_cap->cap |= IEEE80211_VHT_CAP_TXSTBC;
else
vht_cap->cap |= IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN;
switch (iwlwifi_mod_params.amsdu_size) {
case IWL_AMSDU_DEF:
if (cfg->mq_rx_supported)
vht_cap->cap |=
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454;
else
vht_cap->cap |= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895;
break;
case IWL_AMSDU_4K:
vht_cap->cap |= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895;
break;
case IWL_AMSDU_8K:
vht_cap->cap |= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991;
break;
case IWL_AMSDU_12K:
vht_cap->cap |= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454;
break;
default:
break;
}
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
void iwl_init_sbands(struct device *dev, const struct iwl_cfg *cfg,
struct iwl_nvm_data *data, const __le16 *nvm_ch_flags,
u8 tx_chains, u8 rx_chains, bool lar_supported,
bool no_wide_in_5ghz)
{
int n_channels;
int n_used = 0;
struct ieee80211_supported_band *sband;
n_channels = iwl_init_channel_map(dev, cfg, data, nvm_ch_flags,
lar_supported, no_wide_in_5ghz);
sband = &data->bands[NL80211_BAND_2GHZ];
sband->band = NL80211_BAND_2GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_24_OFFS];
sband->n_bitrates = N_RATES_24;
n_used += iwl_init_sband_channels(data, sband, n_channels,
NL80211_BAND_2GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, NL80211_BAND_2GHZ,
tx_chains, rx_chains);
sband = &data->bands[NL80211_BAND_5GHZ];
sband->band = NL80211_BAND_5GHZ;
sband->bitrates = &iwl_cfg80211_rates[RATES_52_OFFS];
sband->n_bitrates = N_RATES_52;
n_used += iwl_init_sband_channels(data, sband, n_channels,
NL80211_BAND_5GHZ);
iwl_init_ht_hw_capab(cfg, data, &sband->ht_cap, NL80211_BAND_5GHZ,
tx_chains, rx_chains);
if (data->sku_cap_11ac_enable && !iwlwifi_mod_params.disable_11ac)
iwl_init_vht_hw_capab(cfg, data, &sband->vht_cap,
tx_chains, rx_chains);
if (n_channels != n_used)
IWL_ERR_DEV(dev, "NVM: used only %d of %d channels\n",
n_used, n_channels);
}
static int iwl_get_sku(const struct iwl_cfg *cfg, const __le16 *nvm_sw,
const __le16 *phy_sku)
{
if (cfg->nvm_type != IWL_NVM_EXT)
return le16_to_cpup(nvm_sw + SKU);
return le32_to_cpup((__le32 *)(phy_sku + SKU_FAMILY_8000));
}
static int iwl_get_nvm_version(const struct iwl_cfg *cfg, const __le16 *nvm_sw)
{
if (cfg->nvm_type != IWL_NVM_EXT)
return le16_to_cpup(nvm_sw + NVM_VERSION);
else
return le32_to_cpup((__le32 *)(nvm_sw +
NVM_VERSION_EXT_NVM));
}
static int iwl_get_radio_cfg(const struct iwl_cfg *cfg, const __le16 *nvm_sw,
const __le16 *phy_sku)
{
if (cfg->nvm_type != IWL_NVM_EXT)
return le16_to_cpup(nvm_sw + RADIO_CFG);
return le32_to_cpup((__le32 *)(phy_sku + RADIO_CFG_FAMILY_EXT_NVM));
}
static int iwl_get_n_hw_addrs(const struct iwl_cfg *cfg, const __le16 *nvm_sw)
{
int n_hw_addr;
if (cfg->nvm_type != IWL_NVM_EXT)
return le16_to_cpup(nvm_sw + N_HW_ADDRS);
n_hw_addr = le32_to_cpup((__le32 *)(nvm_sw + N_HW_ADDRS_FAMILY_8000));
return n_hw_addr & N_HW_ADDR_MASK;
}
static void iwl_set_radio_cfg(const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
u32 radio_cfg)
{
if (cfg->nvm_type != IWL_NVM_EXT) {
data->radio_cfg_type = NVM_RF_CFG_TYPE_MSK(radio_cfg);
data->radio_cfg_step = NVM_RF_CFG_STEP_MSK(radio_cfg);
data->radio_cfg_dash = NVM_RF_CFG_DASH_MSK(radio_cfg);
data->radio_cfg_pnum = NVM_RF_CFG_PNUM_MSK(radio_cfg);
return;
}
data->radio_cfg_type = EXT_NVM_RF_CFG_TYPE_MSK(radio_cfg);
data->radio_cfg_step = EXT_NVM_RF_CFG_STEP_MSK(radio_cfg);
data->radio_cfg_dash = EXT_NVM_RF_CFG_DASH_MSK(radio_cfg);
data->radio_cfg_pnum = EXT_NVM_RF_CFG_FLAVOR_MSK(radio_cfg);
data->valid_tx_ant = EXT_NVM_RF_CFG_TX_ANT_MSK(radio_cfg);
data->valid_rx_ant = EXT_NVM_RF_CFG_RX_ANT_MSK(radio_cfg);
}
static void iwl_flip_hw_address(__le32 mac_addr0, __le32 mac_addr1, u8 *dest)
{
const u8 *hw_addr;
hw_addr = (const u8 *)&mac_addr0;
dest[0] = hw_addr[3];
dest[1] = hw_addr[2];
dest[2] = hw_addr[1];
dest[3] = hw_addr[0];
hw_addr = (const u8 *)&mac_addr1;
dest[4] = hw_addr[1];
dest[5] = hw_addr[0];
}
void iwl_set_hw_address_from_csr(struct iwl_trans *trans,
struct iwl_nvm_data *data)
{
__le32 mac_addr0 = cpu_to_le32(iwl_read32(trans, CSR_MAC_ADDR0_STRAP));
__le32 mac_addr1 = cpu_to_le32(iwl_read32(trans, CSR_MAC_ADDR1_STRAP));
iwl_flip_hw_address(mac_addr0, mac_addr1, data->hw_addr);
if (is_valid_ether_addr(data->hw_addr))
return;
mac_addr0 = cpu_to_le32(iwl_read32(trans, CSR_MAC_ADDR0_OTP));
mac_addr1 = cpu_to_le32(iwl_read32(trans, CSR_MAC_ADDR1_OTP));
iwl_flip_hw_address(mac_addr0, mac_addr1, data->hw_addr);
}
static void iwl_set_hw_address_family_8000(struct iwl_trans *trans,
const struct iwl_cfg *cfg,
struct iwl_nvm_data *data,
const __le16 *mac_override,
const __be16 *nvm_hw)
{
const u8 *hw_addr;
if (mac_override) {
static const u8 reserved_mac[] = {
0x02, 0xcc, 0xaa, 0xff, 0xee, 0x00
};
hw_addr = (const u8 *)(mac_override +
MAC_ADDRESS_OVERRIDE_EXT_NVM);
memcpy(data->hw_addr, hw_addr, ETH_ALEN);
if (is_valid_ether_addr(data->hw_addr) &&
memcmp(reserved_mac, hw_addr, ETH_ALEN) != 0)
return;
IWL_ERR(trans,
"mac address from nvm override section is not valid\n");
}
if (nvm_hw) {
__le32 mac_addr0 = cpu_to_le32(iwl_trans_read_prph(trans,
WFMP_MAC_ADDR_0));
__le32 mac_addr1 = cpu_to_le32(iwl_trans_read_prph(trans,
WFMP_MAC_ADDR_1));
iwl_flip_hw_address(mac_addr0, mac_addr1, data->hw_addr);
return;
}
IWL_ERR(trans, "mac address is not found\n");
}
static int iwl_set_hw_address(struct iwl_trans *trans,
const struct iwl_cfg *cfg,
struct iwl_nvm_data *data, const __be16 *nvm_hw,
const __le16 *mac_override)
{
if (cfg->mac_addr_from_csr) {
iwl_set_hw_address_from_csr(trans, data);
} else if (cfg->nvm_type != IWL_NVM_EXT) {
const u8 *hw_addr = (const u8 *)(nvm_hw + HW_ADDR);
data->hw_addr[0] = hw_addr[1];
data->hw_addr[1] = hw_addr[0];
data->hw_addr[2] = hw_addr[3];
data->hw_addr[3] = hw_addr[2];
data->hw_addr[4] = hw_addr[5];
data->hw_addr[5] = hw_addr[4];
} else {
iwl_set_hw_address_family_8000(trans, cfg, data,
mac_override, nvm_hw);
}
if (!is_valid_ether_addr(data->hw_addr)) {
IWL_ERR(trans, "no valid mac address was found\n");
return -EINVAL;
}
IWL_INFO(trans, "base HW address: %pM\n", data->hw_addr);
return 0;
}
static bool
iwl_nvm_no_wide_in_5ghz(struct device *dev, const struct iwl_cfg *cfg,
const __be16 *nvm_hw)
{
if (cfg->device_family == IWL_DEVICE_FAMILY_7000) {
u16 subsystem_id = be16_to_cpup(nvm_hw + SUBSYSTEM_ID);
u8 sku = (subsystem_id & 0x1e) >> 1;
if (sku == 5 || sku == 9) {
IWL_DEBUG_EEPROM(dev,
"disabling wide channels in 5GHz (0x%0x %d)\n",
subsystem_id, sku);
return true;
}
}
return false;
}
struct iwl_nvm_data *
iwl_parse_nvm_data(struct iwl_trans *trans, const struct iwl_cfg *cfg,
const __be16 *nvm_hw, const __le16 *nvm_sw,
const __le16 *nvm_calib, const __le16 *regulatory,
const __le16 *mac_override, const __le16 *phy_sku,
u8 tx_chains, u8 rx_chains, bool lar_fw_supported)
{
struct device *dev = trans->dev;
struct iwl_nvm_data *data;
bool lar_enabled;
bool no_wide_in_5ghz = iwl_nvm_no_wide_in_5ghz(dev, cfg, nvm_hw);
u32 sku, radio_cfg;
u16 lar_config;
const __le16 *ch_section;
if (cfg->nvm_type != IWL_NVM_EXT)
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) *
IWL_NUM_CHANNELS,
GFP_KERNEL);
else
data = kzalloc(sizeof(*data) +
sizeof(struct ieee80211_channel) *
IWL_NUM_CHANNELS_EXT,
GFP_KERNEL);
if (!data)
return NULL;
data->nvm_version = iwl_get_nvm_version(cfg, nvm_sw);
radio_cfg = iwl_get_radio_cfg(cfg, nvm_sw, phy_sku);
iwl_set_radio_cfg(cfg, data, radio_cfg);
if (data->valid_tx_ant)
tx_chains &= data->valid_tx_ant;
if (data->valid_rx_ant)
rx_chains &= data->valid_rx_ant;
sku = iwl_get_sku(cfg, nvm_sw, phy_sku);
data->sku_cap_band_24GHz_enable = sku & NVM_SKU_CAP_BAND_24GHZ;
data->sku_cap_band_52GHz_enable = sku & NVM_SKU_CAP_BAND_52GHZ;
data->sku_cap_11n_enable = sku & NVM_SKU_CAP_11N_ENABLE;
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
data->sku_cap_11n_enable = false;
data->sku_cap_11ac_enable = data->sku_cap_11n_enable &&
(sku & NVM_SKU_CAP_11AC_ENABLE);
data->sku_cap_mimo_disabled = sku & NVM_SKU_CAP_MIMO_DISABLE;
data->n_hw_addrs = iwl_get_n_hw_addrs(cfg, nvm_sw);
if (cfg->nvm_type != IWL_NVM_EXT) {
if (!nvm_calib) {
IWL_ERR(trans,
"Can't parse empty Calib NVM sections\n");
kfree(data);
return NULL;
}
ch_section = cfg->nvm_type == IWL_NVM_SDP ?
&regulatory[NVM_CHANNELS_SDP] :
&nvm_sw[NVM_CHANNELS];
data->xtal_calib[0] = *(nvm_calib + XTAL_CALIB);
data->xtal_calib[1] = *(nvm_calib + XTAL_CALIB + 1);
lar_enabled = true;
} else {
u16 lar_offset = data->nvm_version < 0xE39 ?
NVM_LAR_OFFSET_OLD :
NVM_LAR_OFFSET;
lar_config = le16_to_cpup(regulatory + lar_offset);
data->lar_enabled = !!(lar_config &
NVM_LAR_ENABLED);
lar_enabled = data->lar_enabled;
ch_section = &regulatory[NVM_CHANNELS_EXTENDED];
}
if (iwl_set_hw_address(trans, cfg, data, nvm_hw, mac_override)) {
kfree(data);
return NULL;
}
iwl_init_sbands(dev, cfg, data, ch_section, tx_chains, rx_chains,
lar_fw_supported && lar_enabled, no_wide_in_5ghz);
data->calib_version = 255;
return data;
}
static u32 iwl_nvm_get_regdom_bw_flags(const u8 *nvm_chan,
int ch_idx, u16 nvm_flags,
const struct iwl_cfg *cfg)
{
u32 flags = NL80211_RRF_NO_HT40;
u32 last_5ghz_ht = LAST_5GHZ_HT;
if (cfg->nvm_type == IWL_NVM_EXT)
last_5ghz_ht = LAST_5GHZ_HT_FAMILY_8000;
if (ch_idx < NUM_2GHZ_CHANNELS &&
(nvm_flags & NVM_CHANNEL_40MHZ)) {
if (nvm_chan[ch_idx] <= LAST_2GHZ_HT_PLUS)
flags &= ~NL80211_RRF_NO_HT40PLUS;
if (nvm_chan[ch_idx] >= FIRST_2GHZ_HT_MINUS)
flags &= ~NL80211_RRF_NO_HT40MINUS;
} else if (nvm_chan[ch_idx] <= last_5ghz_ht &&
(nvm_flags & NVM_CHANNEL_40MHZ)) {
if ((ch_idx - NUM_2GHZ_CHANNELS) % 2 == 0)
flags &= ~NL80211_RRF_NO_HT40PLUS;
else
flags &= ~NL80211_RRF_NO_HT40MINUS;
}
if (!(nvm_flags & NVM_CHANNEL_80MHZ))
flags |= NL80211_RRF_NO_80MHZ;
if (!(nvm_flags & NVM_CHANNEL_160MHZ))
flags |= NL80211_RRF_NO_160MHZ;
if (!(nvm_flags & NVM_CHANNEL_ACTIVE))
flags |= NL80211_RRF_NO_IR;
if (nvm_flags & NVM_CHANNEL_RADAR)
flags |= NL80211_RRF_DFS;
if (nvm_flags & NVM_CHANNEL_INDOOR_ONLY)
flags |= NL80211_RRF_NO_OUTDOOR;
if ((nvm_flags & NVM_CHANNEL_GO_CONCURRENT) &&
(flags & NL80211_RRF_NO_IR))
flags |= NL80211_RRF_GO_CONCURRENT;
return flags;
}
struct ieee80211_regdomain *
iwl_parse_nvm_mcc_info(struct device *dev, const struct iwl_cfg *cfg,
int num_of_ch, __le32 *channels, u16 fw_mcc)
{
int ch_idx;
u16 ch_flags;
u32 reg_rule_flags, prev_reg_rule_flags = 0;
const u8 *nvm_chan = cfg->nvm_type == IWL_NVM_EXT ?
iwl_ext_nvm_channels : iwl_nvm_channels;
struct ieee80211_regdomain *regd;
int size_of_regd;
struct ieee80211_reg_rule *rule;
enum nl80211_band band;
int center_freq, prev_center_freq = 0;
int valid_rules = 0;
bool new_rule;
int max_num_ch = cfg->nvm_type == IWL_NVM_EXT ?
IWL_NUM_CHANNELS_EXT : IWL_NUM_CHANNELS;
if (WARN_ON_ONCE(num_of_ch > NL80211_MAX_SUPP_REG_RULES))
return ERR_PTR(-EINVAL);
if (WARN_ON(num_of_ch > max_num_ch))
num_of_ch = max_num_ch;
IWL_DEBUG_DEV(dev, IWL_DL_LAR, "building regdom for %d channels\n",
num_of_ch);
size_of_regd =
sizeof(struct ieee80211_regdomain) +
num_of_ch * sizeof(struct ieee80211_reg_rule);
regd = kzalloc(size_of_regd, GFP_KERNEL);
if (!regd)
return ERR_PTR(-ENOMEM);
for (ch_idx = 0; ch_idx < num_of_ch; ch_idx++) {
ch_flags = (u16)__le32_to_cpup(channels + ch_idx);
band = (ch_idx < NUM_2GHZ_CHANNELS) ?
NL80211_BAND_2GHZ : NL80211_BAND_5GHZ;
center_freq = ieee80211_channel_to_frequency(nvm_chan[ch_idx],
band);
new_rule = false;
if (!(ch_flags & NVM_CHANNEL_VALID)) {
iwl_nvm_print_channel_flags(dev, IWL_DL_LAR,
nvm_chan[ch_idx], ch_flags);
continue;
}
reg_rule_flags = iwl_nvm_get_regdom_bw_flags(nvm_chan, ch_idx,
ch_flags, cfg);
if (ch_idx == 0 || prev_reg_rule_flags != reg_rule_flags ||
center_freq - prev_center_freq > 20) {
valid_rules++;
new_rule = true;
}
rule = &regd->reg_rules[valid_rules - 1];
if (new_rule)
rule->freq_range.start_freq_khz =
MHZ_TO_KHZ(center_freq - 10);
rule->freq_range.end_freq_khz = MHZ_TO_KHZ(center_freq + 10);
rule->power_rule.max_antenna_gain = DBI_TO_MBI(6);
rule->power_rule.max_eirp =
DBM_TO_MBM(IWL_DEFAULT_MAX_TX_POWER);
rule->flags = reg_rule_flags;
rule->flags |= NL80211_RRF_AUTO_BW;
rule->freq_range.max_bandwidth_khz = 0;
prev_center_freq = center_freq;
prev_reg_rule_flags = reg_rule_flags;
iwl_nvm_print_channel_flags(dev, IWL_DL_LAR,
nvm_chan[ch_idx], ch_flags);
}
regd->n_reg_rules = valid_rules;
regd->alpha2[0] = fw_mcc >> 8;
regd->alpha2[1] = fw_mcc & 0xff;
return regd;
}
static u32 iwl_wrdd_get_mcc(struct device *dev, union acpi_object *wrdd)
{
union acpi_object *mcc_pkg, *domain_type, *mcc_value;
u32 i;
if (wrdd->type != ACPI_TYPE_PACKAGE ||
wrdd->package.count < 2 ||
wrdd->package.elements[0].type != ACPI_TYPE_INTEGER ||
wrdd->package.elements[0].integer.value != 0) {
IWL_DEBUG_EEPROM(dev, "Unsupported wrdd structure\n");
return 0;
}
for (i = 1 ; i < wrdd->package.count ; ++i) {
mcc_pkg = &wrdd->package.elements[i];
if (mcc_pkg->type != ACPI_TYPE_PACKAGE ||
mcc_pkg->package.count < 2 ||
mcc_pkg->package.elements[0].type != ACPI_TYPE_INTEGER ||
mcc_pkg->package.elements[1].type != ACPI_TYPE_INTEGER) {
mcc_pkg = NULL;
continue;
}
domain_type = &mcc_pkg->package.elements[0];
if (domain_type->integer.value == WRDD_WIFI)
break;
mcc_pkg = NULL;
}
if (mcc_pkg) {
mcc_value = &mcc_pkg->package.elements[1];
return mcc_value->integer.value;
}
return 0;
}
int iwl_get_bios_mcc(struct device *dev, char *mcc)
{
acpi_handle root_handle;
acpi_handle handle;
struct acpi_buffer wrdd = {ACPI_ALLOCATE_BUFFER, NULL};
acpi_status status;
u32 mcc_val;
root_handle = ACPI_HANDLE(dev);
if (!root_handle) {
IWL_DEBUG_EEPROM(dev,
"Could not retrieve root port ACPI handle\n");
return -ENOENT;
}
status = acpi_get_handle(root_handle, (acpi_string)WRDD_METHOD,
&handle);
if (ACPI_FAILURE(status)) {
IWL_DEBUG_EEPROM(dev, "WRD method not found\n");
return -ENOENT;
}
status = acpi_evaluate_object(handle, NULL, NULL, &wrdd);
if (ACPI_FAILURE(status)) {
IWL_DEBUG_EEPROM(dev, "WRDC invocation failed (0x%x)\n",
status);
return -ENOENT;
}
mcc_val = iwl_wrdd_get_mcc(dev, wrdd.pointer);
kfree(wrdd.pointer);
if (!mcc_val)
return -ENOENT;
mcc[0] = (mcc_val >> 8) & 0xff;
mcc[1] = mcc_val & 0xff;
mcc[2] = '\0';
return 0;
}
