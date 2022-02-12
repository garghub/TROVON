static void iwl6000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD;
hw_params(priv).ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl6050_additional_nic_config(struct iwl_priv *priv)
{
if (iwl_eeprom_calib_version(priv->shrd) >= 6)
iwl_set_bit(bus(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
}
static void iwl6150_additional_nic_config(struct iwl_priv *priv)
{
if (iwl_eeprom_calib_version(priv->shrd) >= 6)
iwl_set_bit(bus(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
iwl_set_bit(bus(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_6050_1x2);
}
static void iwl6000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
if (cfg(priv)->pa_type == IWL_PA_INTERNAL) {
iwl_write32(bus(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_SKU_2x2_IPA);
}
if (cfg(priv)->additional_nic_config)
cfg(priv)->additional_nic_config(priv);
}
static int iwl6000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
cfg(priv)->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
hw_params(priv).max_txq_num = cfg(priv)->base_params->num_of_queues;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
hw_params(priv).max_data_size = IWL60_RTC_DATA_SIZE;
hw_params(priv).max_inst_size = IWL60_RTC_INST_SIZE;
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
hw_params(priv).tx_chains_num = num_of_ant(cfg(priv)->valid_tx_ant);
if (cfg(priv)->rx_with_siso_diversity)
hw_params(priv).rx_chains_num = 1;
else
hw_params(priv).rx_chains_num =
num_of_ant(cfg(priv)->valid_rx_ant);
hw_params(priv).valid_tx_ant = cfg(priv)->valid_tx_ant;
hw_params(priv).valid_rx_ant = cfg(priv)->valid_rx_ant;
iwl6000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl6000_sensitivity;
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
return iwl_trans_send_cmd(trans(priv), &hcmd);
}
