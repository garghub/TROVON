int iwl_eeprom_check_version(struct iwl_priv *priv)
{
u16 eeprom_ver;
u16 calib_ver;
eeprom_ver = iwl_eeprom_query16(priv, EEPROM_VERSION);
calib_ver = iwlagn_eeprom_calib_version(priv);
if (eeprom_ver < priv->cfg->eeprom_ver ||
calib_ver < priv->cfg->eeprom_calib_ver)
goto err;
IWL_INFO(priv, "device EEPROM VER=0x%x, CALIB=0x%x\n",
eeprom_ver, calib_ver);
return 0;
err:
IWL_ERR(priv, "Unsupported (too old) EEPROM VER=0x%x < 0x%x "
"CALIB=0x%x < 0x%x\n",
eeprom_ver, priv->cfg->eeprom_ver,
calib_ver, priv->cfg->eeprom_calib_ver);
return -EINVAL;
}
int iwl_eeprom_check_sku(struct iwl_priv *priv)
{
u16 eeprom_sku;
u16 radio_cfg;
eeprom_sku = iwl_eeprom_query16(priv, EEPROM_SKU_CAP);
if (!priv->cfg->sku) {
priv->cfg->sku =
((eeprom_sku & EEPROM_SKU_CAP_BAND_SELECTION) >>
EEPROM_SKU_CAP_BAND_POS);
if (eeprom_sku & EEPROM_SKU_CAP_11N_ENABLE)
priv->cfg->sku |= IWL_SKU_N;
}
if (!priv->cfg->sku) {
IWL_ERR(priv, "Invalid device sku\n");
return -EINVAL;
}
IWL_INFO(priv, "Device SKU: 0X%x\n", priv->cfg->sku);
if (!priv->cfg->valid_tx_ant && !priv->cfg->valid_rx_ant) {
radio_cfg = iwl_eeprom_query16(priv, EEPROM_RADIO_CONFIG);
priv->cfg->valid_tx_ant = EEPROM_RF_CFG_TX_ANT_MSK(radio_cfg);
priv->cfg->valid_rx_ant = EEPROM_RF_CFG_RX_ANT_MSK(radio_cfg);
if (!priv->cfg->valid_tx_ant || !priv->cfg->valid_rx_ant) {
IWL_ERR(priv, "Invalid chain (0X%x, 0X%x)\n",
priv->cfg->valid_tx_ant,
priv->cfg->valid_rx_ant);
return -EINVAL;
}
IWL_INFO(priv, "Valid Tx ant: 0X%x, Valid Rx ant: 0X%x\n",
priv->cfg->valid_tx_ant, priv->cfg->valid_rx_ant);
}
return 0;
}
void iwl_eeprom_get_mac(const struct iwl_priv *priv, u8 *mac)
{
const u8 *addr = priv->cfg->ops->lib->eeprom_ops.query_addr(priv,
EEPROM_MAC_ADDRESS);
memcpy(mac, addr, ETH_ALEN);
}
static s8 iwl_get_max_txpower_avg(struct iwl_priv *priv,
struct iwl_eeprom_enhanced_txpwr *enhanced_txpower,
int element, s8 *max_txpower_in_half_dbm)
{
s8 max_txpower_avg = 0;
if ((priv->cfg->valid_tx_ant & ANT_A) &&
(enhanced_txpower[element].chain_a_max > max_txpower_avg))
max_txpower_avg = enhanced_txpower[element].chain_a_max;
if ((priv->cfg->valid_tx_ant & ANT_B) &&
(enhanced_txpower[element].chain_b_max > max_txpower_avg))
max_txpower_avg = enhanced_txpower[element].chain_b_max;
if ((priv->cfg->valid_tx_ant & ANT_C) &&
(enhanced_txpower[element].chain_c_max > max_txpower_avg))
max_txpower_avg = enhanced_txpower[element].chain_c_max;
if (((priv->cfg->valid_tx_ant == ANT_AB) |
(priv->cfg->valid_tx_ant == ANT_BC) |
(priv->cfg->valid_tx_ant == ANT_AC)) &&
(enhanced_txpower[element].mimo2_max > max_txpower_avg))
max_txpower_avg = enhanced_txpower[element].mimo2_max;
if ((priv->cfg->valid_tx_ant == ANT_ABC) &&
(enhanced_txpower[element].mimo3_max > max_txpower_avg))
max_txpower_avg = enhanced_txpower[element].mimo3_max;
*max_txpower_in_half_dbm = max_txpower_avg;
return (max_txpower_avg & 0x01) + (max_txpower_avg >> 1);
}
static void
iwlcore_eeprom_enh_txp_read_element(struct iwl_priv *priv,
struct iwl_eeprom_enhanced_txpwr *txp,
s8 max_txpower_avg)
{
int ch_idx;
bool is_ht40 = txp->flags & IWL_EEPROM_ENH_TXP_FL_40MHZ;
enum ieee80211_band band;
band = txp->flags & IWL_EEPROM_ENH_TXP_FL_BAND_52G ?
IEEE80211_BAND_5GHZ : IEEE80211_BAND_2GHZ;
for (ch_idx = 0; ch_idx < priv->channel_count; ch_idx++) {
struct iwl_channel_info *ch_info = &priv->channel_info[ch_idx];
if (txp->channel != 0 && ch_info->channel != txp->channel)
continue;
if (band != ch_info->band)
continue;
if (ch_info->max_power_avg < max_txpower_avg && !is_ht40) {
ch_info->max_power_avg = max_txpower_avg;
ch_info->curr_txpow = max_txpower_avg;
ch_info->scan_power = max_txpower_avg;
}
if (is_ht40 && ch_info->ht40_max_power_avg < max_txpower_avg)
ch_info->ht40_max_power_avg = max_txpower_avg;
}
}
void iwlcore_eeprom_enhanced_txpower(struct iwl_priv *priv)
{
struct iwl_eeprom_enhanced_txpwr *txp_array, *txp;
int idx, entries;
__le16 *txp_len;
s8 max_txp_avg, max_txp_avg_halfdbm;
BUILD_BUG_ON(sizeof(struct iwl_eeprom_enhanced_txpwr) != 8);
txp_len = (__le16 *) iwlagn_eeprom_query_addr(priv, EEPROM_TXP_SZ_OFFS);
entries = le16_to_cpup(txp_len) * 2 / EEPROM_TXP_ENTRY_LEN;
txp_array = (void *) iwlagn_eeprom_query_addr(priv, EEPROM_TXP_OFFS);
for (idx = 0; idx < entries; idx++) {
txp = &txp_array[idx];
if (!(txp->flags & IWL_EEPROM_ENH_TXP_FL_VALID))
continue;
IWL_DEBUG_EEPROM(priv, "%s %d:\t %s%s%s%s%s%s%s%s (0x%02x)\n",
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
IWL_DEBUG_EEPROM(priv, "\t\t chain_A: 0x%02x "
"chain_B: 0X%02x chain_C: 0X%02x\n",
txp->chain_a_max, txp->chain_b_max,
txp->chain_c_max);
IWL_DEBUG_EEPROM(priv, "\t\t MIMO2: 0x%02x "
"MIMO3: 0x%02x High 20_on_40: 0x%02x "
"Low 20_on_40: 0x%02x\n",
txp->mimo2_max, txp->mimo3_max,
((txp->delta_20_in_40 & 0xf0) >> 4),
(txp->delta_20_in_40 & 0x0f));
max_txp_avg = iwl_get_max_txpower_avg(priv, txp_array, idx,
&max_txp_avg_halfdbm);
if (max_txp_avg > priv->tx_power_user_lmt)
priv->tx_power_user_lmt = max_txp_avg;
if (max_txp_avg_halfdbm > priv->tx_power_lmt_in_half_dbm)
priv->tx_power_lmt_in_half_dbm = max_txp_avg_halfdbm;
iwlcore_eeprom_enh_txp_read_element(priv, txp, max_txp_avg);
}
}
