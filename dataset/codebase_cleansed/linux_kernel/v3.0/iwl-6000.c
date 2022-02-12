static void iwl6000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD;
priv->hw_params.ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl6050_additional_nic_config(struct iwl_priv *priv)
{
if (iwlagn_eeprom_calib_version(priv) >= 6)
iwl_set_bit(priv, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
}
static void iwl6150_additional_nic_config(struct iwl_priv *priv)
{
if (iwlagn_eeprom_calib_version(priv) >= 6)
iwl_set_bit(priv, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
iwl_set_bit(priv, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_6050_1x2);
}
static void iwl6000_nic_config(struct iwl_priv *priv)
{
u16 radio_cfg;
radio_cfg = iwl_eeprom_query16(priv, EEPROM_RADIO_CONFIG);
if (EEPROM_RF_CFG_TYPE_MSK(radio_cfg) <= EEPROM_RF_CONFIG_TYPE_MAX)
iwl_set_bit(priv, CSR_HW_IF_CONFIG_REG,
EEPROM_RF_CFG_TYPE_MSK(radio_cfg) |
EEPROM_RF_CFG_STEP_MSK(radio_cfg) |
EEPROM_RF_CFG_DASH_MSK(radio_cfg));
iwl_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
if (priv->cfg->pa_type == IWL_PA_INTERNAL) {
iwl_write32(priv, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_SKU_2x2_IPA);
}
if (priv->cfg->ops->nic &&
priv->cfg->ops->nic->additional_nic_config) {
priv->cfg->ops->nic->additional_nic_config(priv);
}
}
static int iwl6000_hw_set_hw_params(struct iwl_priv *priv)
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
priv->hw_params.max_data_size = IWL60_RTC_DATA_SIZE;
priv->hw_params.max_inst_size = IWL60_RTC_INST_SIZE;
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.rx_wrt_ptr_reg = FH_RSCSR_CHNL0_WPTR;
priv->hw_params.tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
priv->hw_params.rx_chains_num = 1;
else
priv->hw_params.rx_chains_num =
num_of_ant(priv->cfg->valid_rx_ant);
priv->hw_params.valid_tx_ant = priv->cfg->valid_tx_ant;
priv->hw_params.valid_rx_ant = priv->cfg->valid_rx_ant;
iwl6000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl6000_sensitivity;
priv->hw_params.calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
priv->hw_params.calib_rt_cfg |= BIT(IWL_CALIB_CFG_DC_IDX);
if (priv->cfg->need_temp_offset_calib)
priv->hw_params.calib_init_cfg |= BIT(IWL_CALIB_TEMP_OFFSET);
priv->hw_params.beacon_time_tsf_bits = IWLAGN_EXT_BEACON_TIME_POS;
return 0;
}
static int iwl6000_hw_channel_switch(struct iwl_priv *priv,
struct ieee80211_channel_switch *ch_switch)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct iwl6000_channel_switch_cmd cmd;
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
IWL_DEBUG_11H(priv, "channel switch from %u to %u\n",
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
