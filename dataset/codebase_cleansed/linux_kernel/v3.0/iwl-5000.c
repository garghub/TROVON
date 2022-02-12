static void iwl5000_nic_config(struct iwl_priv *priv)
{
unsigned long flags;
u16 radio_cfg;
spin_lock_irqsave(&priv->lock, flags);
radio_cfg = iwl_eeprom_query16(priv, EEPROM_RADIO_CONFIG);
if (EEPROM_RF_CFG_TYPE_MSK(radio_cfg) < EEPROM_RF_CONFIG_TYPE_MAX)
iwl_set_bit(priv, CSR_HW_IF_CONFIG_REG,
EEPROM_RF_CFG_TYPE_MSK(radio_cfg) |
EEPROM_RF_CFG_STEP_MSK(radio_cfg) |
EEPROM_RF_CFG_DASH_MSK(radio_cfg));
iwl_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
iwl_set_bits_mask_prph(priv, APMG_PS_CTRL_REG,
APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS,
~APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void iwl5150_set_ct_threshold(struct iwl_priv *priv)
{
const s32 volt2temp_coef = IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF;
s32 threshold = (s32)CELSIUS_TO_KELVIN(CT_KILL_THRESHOLD_LEGACY) -
iwl_temp_calib_to_offset(priv);
priv->hw_params.ct_kill_threshold = threshold * volt2temp_coef;
}
static void iwl5000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
}
static int iwl5000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
priv->hw_params.max_txq_num = priv->cfg->base_params->num_of_queues;
priv->hw_params.dma_chnl_num = FH50_TCSR_CHNL_NUM;
priv->hw_params.scd_bc_tbls_size =
priv->cfg->base_params->num_of_queues *
sizeof(struct iwlagn_scd_bc_tbl);
priv->hw_params.tfd_size = sizeof(struct iwl_tfd);
priv->hw_params.max_stations = IWLAGN_STATION_COUNT;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
priv->hw_params.max_data_size = IWLAGN_RTC_DATA_SIZE;
priv->hw_params.max_inst_size = IWLAGN_RTC_INST_SIZE;
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.rx_wrt_ptr_reg = FH_RSCSR_CHNL0_WPTR;
priv->hw_params.tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
priv->hw_params.rx_chains_num = num_of_ant(priv->cfg->valid_rx_ant);
priv->hw_params.valid_tx_ant = priv->cfg->valid_tx_ant;
priv->hw_params.valid_rx_ant = priv->cfg->valid_rx_ant;
iwl5000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl5000_sensitivity;
priv->hw_params.calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_TX_IQ_PERD) |
BIT(IWL_CALIB_BASE_BAND);
priv->hw_params.beacon_time_tsf_bits = IWLAGN_EXT_BEACON_TIME_POS;
return 0;
}
static int iwl5150_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
priv->hw_params.max_txq_num = priv->cfg->base_params->num_of_queues;
priv->hw_params.dma_chnl_num = FH50_TCSR_CHNL_NUM;
priv->hw_params.scd_bc_tbls_size =
priv->cfg->base_params->num_of_queues *
sizeof(struct iwlagn_scd_bc_tbl);
priv->hw_params.tfd_size = sizeof(struct iwl_tfd);
priv->hw_params.max_stations = IWLAGN_STATION_COUNT;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
priv->hw_params.max_data_size = IWLAGN_RTC_DATA_SIZE;
priv->hw_params.max_inst_size = IWLAGN_RTC_INST_SIZE;
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.rx_wrt_ptr_reg = FH_RSCSR_CHNL0_WPTR;
priv->hw_params.tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
priv->hw_params.rx_chains_num = num_of_ant(priv->cfg->valid_rx_ant);
priv->hw_params.valid_tx_ant = priv->cfg->valid_tx_ant;
priv->hw_params.valid_rx_ant = priv->cfg->valid_rx_ant;
iwl5150_set_ct_threshold(priv);
priv->hw_params.sens = &iwl5150_sensitivity;
priv->hw_params.calib_init_cfg =
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
priv->hw_params.calib_init_cfg |= BIT(IWL_CALIB_DC);
priv->hw_params.beacon_time_tsf_bits = IWLAGN_EXT_BEACON_TIME_POS;
return 0;
}
static void iwl5150_temperature(struct iwl_priv *priv)
{
u32 vt = 0;
s32 offset = iwl_temp_calib_to_offset(priv);
vt = le32_to_cpu(priv->statistics.common.temperature);
vt = vt / IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF + offset;
priv->temperature = KELVIN_TO_CELSIUS(vt);
iwl_tt_handler(priv);
}
static int iwl5000_hw_channel_switch(struct iwl_priv *priv,
struct ieee80211_channel_switch *ch_switch)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct iwl5000_channel_switch_cmd cmd;
const struct iwl_channel_info *ch_info;
u32 switch_time_in_usec, ucode_switch_time;
u16 ch;
u32 tsf_low;
u8 switch_count;
u16 beacon_interval = le16_to_cpu(ctx->timing.beacon_interval);
struct ieee80211_vif *vif = ctx->vif;
struct iwl_host_cmd hcmd = {
.id = REPLY_CHANNEL_SWITCH,
.len = { sizeof(cmd), },
.flags = CMD_SYNC,
.data = { &cmd, },
};
cmd.band = priv->band == IEEE80211_BAND_2GHZ;
ch = ch_switch->channel->hw_value;
IWL_DEBUG_11H(priv, "channel switch from %d to %d\n",
ctx->active.channel, ch);
cmd.channel = cpu_to_le16(ch);
cmd.rxon_flags = ctx->staging.flags;
cmd.rxon_filter_flags = ctx->staging.filter_flags;
switch_count = ch_switch->count;
tsf_low = ch_switch->timestamp & 0x0ffffffff;
if ((priv->ucode_beacon_time > tsf_low) && beacon_interval) {
if (switch_count > ((priv->ucode_beacon_time - tsf_low) /
beacon_interval)) {
switch_count -= (priv->ucode_beacon_time -
tsf_low) / beacon_interval;
} else
switch_count = 0;
}
if (switch_count <= 1)
cmd.switch_time = cpu_to_le32(priv->ucode_beacon_time);
else {
switch_time_in_usec =
vif->bss_conf.beacon_int * switch_count * TIME_UNIT;
ucode_switch_time = iwl_usecs_to_beacons(priv,
switch_time_in_usec,
beacon_interval);
cmd.switch_time = iwl_add_beacon_time(priv,
priv->ucode_beacon_time,
ucode_switch_time,
beacon_interval);
}
IWL_DEBUG_11H(priv, "uCode time for the switch is 0x%x\n",
cmd.switch_time);
ch_info = iwl_get_channel_info(priv, priv->band, ch);
if (ch_info)
cmd.expect_beacon = is_channel_radar(ch_info);
else {
IWL_ERR(priv, "invalid channel switch from %u to %u\n",
ctx->active.channel, ch);
return -EFAULT;
}
return iwl_send_cmd_sync(priv, &hcmd);
}
