int iwlagn_send_tx_ant_config(struct iwl_priv *priv, u8 valid_tx_ant)
{
struct iwl_tx_ant_config_cmd tx_ant_cmd = {
.valid = cpu_to_le32(valid_tx_ant),
};
if (IWL_UCODE_API(priv->ucode_ver) > 1) {
IWL_DEBUG_HC(priv, "select valid tx ant: %u\n", valid_tx_ant);
return iwl_send_cmd_pdu(priv, TX_ANT_CONFIGURATION_CMD,
sizeof(struct iwl_tx_ant_config_cmd),
&tx_ant_cmd);
} else {
IWL_DEBUG_HC(priv, "TX_ANT_CONFIGURATION_CMD not supported\n");
return -EOPNOTSUPP;
}
}
static u16 iwlagn_build_addsta_hcmd(const struct iwl_addsta_cmd *cmd, u8 *data)
{
u16 size = (u16)sizeof(struct iwl_addsta_cmd);
struct iwl_addsta_cmd *addsta = (struct iwl_addsta_cmd *)data;
memcpy(addsta, cmd, size);
addsta->rate_n_flags = cpu_to_le16(0);
return size;
}
static void iwlagn_gain_computation(struct iwl_priv *priv,
u32 average_noise[NUM_RX_CHAINS],
u16 min_average_noise_antenna_i,
u32 min_average_noise,
u8 default_chain)
{
int i;
s32 delta_g;
struct iwl_chain_noise_data *data = &priv->chain_noise_data;
for (i = default_chain + 1; i < NUM_RX_CHAINS; i++) {
if ((data->disconn_array[i])) {
data->delta_gain_code[i] = 0;
continue;
}
delta_g = (priv->cfg->base_params->chain_noise_scale *
((s32)average_noise[default_chain] -
(s32)average_noise[i])) / 1500;
data->delta_gain_code[i] =
min(abs(delta_g), (long) CHAIN_NOISE_MAX_DELTA_GAIN_CODE);
if (delta_g < 0)
data->delta_gain_code[i] |= (1 << 2);
}
IWL_DEBUG_CALIB(priv, "Delta gains: ANT_B = %d ANT_C = %d\n",
data->delta_gain_code[1], data->delta_gain_code[2]);
if (!data->radio_write) {
struct iwl_calib_chain_noise_gain_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.hdr.op_code = priv->_agn.phy_calib_chain_noise_gain_cmd;
cmd.hdr.first_group = 0;
cmd.hdr.groups_num = 1;
cmd.hdr.data_valid = 1;
cmd.delta_gain_1 = data->delta_gain_code[1];
cmd.delta_gain_2 = data->delta_gain_code[2];
iwl_send_cmd_pdu_async(priv, REPLY_PHY_CALIBRATION_CMD,
sizeof(cmd), &cmd, NULL);
data->radio_write = 1;
data->state = IWL_CHAIN_NOISE_CALIBRATED;
}
}
static void iwlagn_chain_noise_reset(struct iwl_priv *priv)
{
struct iwl_chain_noise_data *data = &priv->chain_noise_data;
int ret;
if ((data->state == IWL_CHAIN_NOISE_ALIVE) &&
iwl_is_any_associated(priv)) {
struct iwl_calib_chain_noise_reset_cmd cmd;
data->chain_noise_a = 0;
data->chain_noise_b = 0;
data->chain_noise_c = 0;
data->chain_signal_a = 0;
data->chain_signal_b = 0;
data->chain_signal_c = 0;
data->beacon_count = 0;
memset(&cmd, 0, sizeof(cmd));
cmd.hdr.op_code = priv->_agn.phy_calib_chain_noise_reset_cmd;
cmd.hdr.first_group = 0;
cmd.hdr.groups_num = 1;
cmd.hdr.data_valid = 1;
ret = iwl_send_cmd_pdu(priv, REPLY_PHY_CALIBRATION_CMD,
sizeof(cmd), &cmd);
if (ret)
IWL_ERR(priv,
"Could not send REPLY_PHY_CALIBRATION_CMD\n");
data->state = IWL_CHAIN_NOISE_ACCUMULATE;
IWL_DEBUG_CALIB(priv, "Run chain_noise_calibrate\n");
}
}
static void iwlagn_tx_cmd_protection(struct iwl_priv *priv,
struct ieee80211_tx_info *info,
__le16 fc, __le32 *tx_flags)
{
if (info->control.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS ||
info->control.rates[0].flags & IEEE80211_TX_RC_USE_CTS_PROTECT ||
info->flags & IEEE80211_TX_CTL_AMPDU)
*tx_flags |= TX_CMD_FLG_PROT_REQUIRE_MSK;
}
static int iwlagn_calc_rssi(struct iwl_priv *priv,
struct iwl_rx_phy_res *rx_resp)
{
struct iwlagn_non_cfg_phy *ncphy =
(struct iwlagn_non_cfg_phy *)rx_resp->non_cfg_phy_buf;
u32 val, rssi_a, rssi_b, rssi_c, max_rssi;
u8 agc;
val = le32_to_cpu(ncphy->non_cfg_phy[IWLAGN_RX_RES_AGC_IDX]);
agc = (val & IWLAGN_OFDM_AGC_MSK) >> IWLAGN_OFDM_AGC_BIT_POS;
val = le32_to_cpu(ncphy->non_cfg_phy[IWLAGN_RX_RES_RSSI_AB_IDX]);
rssi_a = (val & IWLAGN_OFDM_RSSI_INBAND_A_BITMSK) >>
IWLAGN_OFDM_RSSI_A_BIT_POS;
rssi_b = (val & IWLAGN_OFDM_RSSI_INBAND_B_BITMSK) >>
IWLAGN_OFDM_RSSI_B_BIT_POS;
val = le32_to_cpu(ncphy->non_cfg_phy[IWLAGN_RX_RES_RSSI_C_IDX]);
rssi_c = (val & IWLAGN_OFDM_RSSI_INBAND_C_BITMSK) >>
IWLAGN_OFDM_RSSI_C_BIT_POS;
max_rssi = max_t(u32, rssi_a, rssi_b);
max_rssi = max_t(u32, max_rssi, rssi_c);
IWL_DEBUG_STATS(priv, "Rssi In A %d B %d C %d Max %d AGC dB %d\n",
rssi_a, rssi_b, rssi_c, max_rssi, agc);
return max_rssi - agc - IWLAGN_RSSI_OFFSET;
}
static int iwlagn_set_pan_params(struct iwl_priv *priv)
{
struct iwl_wipan_params_cmd cmd;
struct iwl_rxon_context *ctx_bss, *ctx_pan;
int slot0 = 300, slot1 = 0;
int ret;
if (priv->valid_contexts == BIT(IWL_RXON_CTX_BSS))
return 0;
BUILD_BUG_ON(NUM_IWL_RXON_CTX != 2);
lockdep_assert_held(&priv->mutex);
ctx_bss = &priv->contexts[IWL_RXON_CTX_BSS];
ctx_pan = &priv->contexts[IWL_RXON_CTX_PAN];
if (!ctx_pan->is_active)
return 0;
memset(&cmd, 0, sizeof(cmd));
cmd.num_slots = 2;
cmd.slots[0].type = 0;
cmd.slots[1].type = 1;
if (priv->_agn.hw_roc_channel) {
slot1 = priv->_agn.hw_roc_duration;
slot0 = IWL_MIN_SLOT_TIME;
} else if (ctx_bss->vif && ctx_pan->vif) {
int bcnint = ctx_pan->vif->bss_conf.beacon_int;
int dtim = ctx_pan->vif->bss_conf.dtim_period ?: 1;
cmd.flags |= cpu_to_le16(IWL_WIPAN_PARAMS_FLG_SLOTTED_MODE);
if (ctx_pan->vif->type == NL80211_IFTYPE_AP &&
bcnint &&
bcnint != ctx_bss->vif->bss_conf.beacon_int) {
IWL_ERR(priv,
"beacon intervals don't match (%d, %d)\n",
ctx_bss->vif->bss_conf.beacon_int,
ctx_pan->vif->bss_conf.beacon_int);
} else
bcnint = max_t(int, bcnint,
ctx_bss->vif->bss_conf.beacon_int);
if (!bcnint)
bcnint = DEFAULT_BEACON_INTERVAL;
slot0 = bcnint / 2;
slot1 = bcnint - slot0;
if (test_bit(STATUS_SCAN_HW, &priv->status) ||
(!ctx_bss->vif->bss_conf.idle &&
!ctx_bss->vif->bss_conf.assoc)) {
slot0 = dtim * bcnint * 3 - IWL_MIN_SLOT_TIME;
slot1 = IWL_MIN_SLOT_TIME;
} else if (!ctx_pan->vif->bss_conf.idle &&
!ctx_pan->vif->bss_conf.assoc) {
slot1 = bcnint * 3 - IWL_MIN_SLOT_TIME;
slot0 = IWL_MIN_SLOT_TIME;
}
} else if (ctx_pan->vif) {
slot0 = 0;
slot1 = max_t(int, 1, ctx_pan->vif->bss_conf.dtim_period) *
ctx_pan->vif->bss_conf.beacon_int;
slot1 = max_t(int, DEFAULT_BEACON_INTERVAL, slot1);
if (test_bit(STATUS_SCAN_HW, &priv->status)) {
slot0 = slot1 * 3 - IWL_MIN_SLOT_TIME;
slot1 = IWL_MIN_SLOT_TIME;
}
}
cmd.slots[0].width = cpu_to_le16(slot0);
cmd.slots[1].width = cpu_to_le16(slot1);
ret = iwl_send_cmd_pdu(priv, REPLY_WIPAN_PARAMS, sizeof(cmd), &cmd);
if (ret)
IWL_ERR(priv, "Error setting PAN parameters (%d)\n", ret);
return ret;
}
