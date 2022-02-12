static void iwl5000_nic_config(struct iwl_priv *priv)
{
unsigned long flags;
iwl_rf_config(priv);
spin_lock_irqsave(&priv->shrd->lock, flags);
iwl_set_bits_mask_prph(bus(priv), APMG_PS_CTRL_REG,
APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS,
~APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS);
spin_unlock_irqrestore(&priv->shrd->lock, flags);
}
static s32 iwl_temp_calib_to_offset(struct iwl_priv *priv)
{
u16 temperature, voltage;
__le16 *temp_calib = (__le16 *)iwl_eeprom_query_addr(priv,
EEPROM_KELVIN_TEMPERATURE);
temperature = le16_to_cpu(temp_calib[0]);
voltage = le16_to_cpu(temp_calib[1]);
return (s32)(temperature - voltage / IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF);
}
static void iwl5150_set_ct_threshold(struct iwl_priv *priv)
{
const s32 volt2temp_coef = IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF;
s32 threshold = (s32)CELSIUS_TO_KELVIN(CT_KILL_THRESHOLD_LEGACY) -
iwl_temp_calib_to_offset(priv);
hw_params(priv).ct_kill_threshold = threshold * volt2temp_coef;
}
static void iwl5000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
}
static int iwl5000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
hw_params(priv).max_txq_num = priv->cfg->base_params->num_of_queues;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
hw_params(priv).max_data_size = IWLAGN_RTC_DATA_SIZE;
hw_params(priv).max_inst_size = IWLAGN_RTC_INST_SIZE;
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
hw_params(priv).tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
hw_params(priv).rx_chains_num = num_of_ant(priv->cfg->valid_rx_ant);
hw_params(priv).valid_tx_ant = priv->cfg->valid_tx_ant;
hw_params(priv).valid_rx_ant = priv->cfg->valid_rx_ant;
iwl5000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl5000_sensitivity;
hw_params(priv).calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_TX_IQ_PERD) |
BIT(IWL_CALIB_BASE_BAND);
return 0;
}
static int iwl5150_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
hw_params(priv).max_txq_num = priv->cfg->base_params->num_of_queues;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
hw_params(priv).max_data_size = IWLAGN_RTC_DATA_SIZE;
hw_params(priv).max_inst_size = IWLAGN_RTC_INST_SIZE;
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
hw_params(priv).tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
hw_params(priv).rx_chains_num = num_of_ant(priv->cfg->valid_rx_ant);
hw_params(priv).valid_tx_ant = priv->cfg->valid_tx_ant;
hw_params(priv).valid_rx_ant = priv->cfg->valid_rx_ant;
iwl5150_set_ct_threshold(priv);
hw_params(priv).sens = &iwl5150_sensitivity;
hw_params(priv).calib_init_cfg =
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
hw_params(priv).calib_init_cfg |= BIT(IWL_CALIB_DC);
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
return iwl_trans_send_cmd(trans(priv), &hcmd);
}
