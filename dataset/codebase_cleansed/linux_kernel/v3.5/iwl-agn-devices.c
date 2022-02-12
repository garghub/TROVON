static void iwl1000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
priv->hw_params.ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl1000_nic_config(struct iwl_priv *priv)
{
iwl_set_bit(priv->trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
iwl_set_bits_mask_prph(priv->trans, APMG_DIGITAL_SVR_REG,
APMG_SVR_DIGITAL_VOLTAGE_1_32,
~APMG_SVR_VOLTAGE_CONFIG_BIT_MSK);
}
static inline u32 iwl_beacon_time_mask_low(struct iwl_priv *priv,
u16 tsf_bits)
{
return (1 << tsf_bits) - 1;
}
static inline u32 iwl_beacon_time_mask_high(struct iwl_priv *priv,
u16 tsf_bits)
{
return ((1 << (32 - tsf_bits)) - 1) << tsf_bits;
}
static u32 iwl_usecs_to_beacons(struct iwl_priv *priv, u32 usec,
u32 beacon_interval)
{
u32 quot;
u32 rem;
u32 interval = beacon_interval * TIME_UNIT;
if (!interval || !usec)
return 0;
quot = (usec / interval) &
(iwl_beacon_time_mask_high(priv, IWLAGN_EXT_BEACON_TIME_POS) >>
IWLAGN_EXT_BEACON_TIME_POS);
rem = (usec % interval) & iwl_beacon_time_mask_low(priv,
IWLAGN_EXT_BEACON_TIME_POS);
return (quot << IWLAGN_EXT_BEACON_TIME_POS) + rem;
}
static __le32 iwl_add_beacon_time(struct iwl_priv *priv, u32 base,
u32 addon, u32 beacon_interval)
{
u32 base_low = base & iwl_beacon_time_mask_low(priv,
IWLAGN_EXT_BEACON_TIME_POS);
u32 addon_low = addon & iwl_beacon_time_mask_low(priv,
IWLAGN_EXT_BEACON_TIME_POS);
u32 interval = beacon_interval * TIME_UNIT;
u32 res = (base & iwl_beacon_time_mask_high(priv,
IWLAGN_EXT_BEACON_TIME_POS)) +
(addon & iwl_beacon_time_mask_high(priv,
IWLAGN_EXT_BEACON_TIME_POS));
if (base_low > addon_low)
res += base_low - addon_low;
else if (base_low < addon_low) {
res += interval + base_low - addon_low;
res += (1 << IWLAGN_EXT_BEACON_TIME_POS);
} else
res += (1 << IWLAGN_EXT_BEACON_TIME_POS);
return cpu_to_le32(res);
}
static void iwl1000_hw_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ);
priv->hw_params.tx_chains_num =
num_of_ant(priv->hw_params.valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
priv->hw_params.rx_chains_num = 1;
else
priv->hw_params.rx_chains_num =
num_of_ant(priv->hw_params.valid_rx_ant);
iwl1000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl1000_sensitivity;
}
static void iwl2000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD;
priv->hw_params.ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl2000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
iwl_set_bit(priv->trans, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_IQ_INVER);
}
static void iwl2000_hw_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ);
priv->hw_params.tx_chains_num =
num_of_ant(priv->hw_params.valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
priv->hw_params.rx_chains_num = 1;
else
priv->hw_params.rx_chains_num =
num_of_ant(priv->hw_params.valid_rx_ant);
iwl2000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl2000_sensitivity;
}
static void iwl5000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
iwl_set_bits_mask_prph(priv->trans, APMG_PS_CTRL_REG,
APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS,
~APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS);
}
static s32 iwl_temp_calib_to_offset(struct iwl_priv *priv)
{
u16 temperature, voltage;
__le16 *temp_calib = (__le16 *)iwl_eeprom_query_addr(priv,
EEPROM_KELVIN_TEMPERATURE);
temperature = le16_to_cpu(temp_calib[0]);
voltage = le16_to_cpu(temp_calib[1]);
return (s32)(temperature -
voltage / IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF);
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
static void iwl5000_hw_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.tx_chains_num =
num_of_ant(priv->hw_params.valid_tx_ant);
priv->hw_params.rx_chains_num =
num_of_ant(priv->hw_params.valid_rx_ant);
iwl5000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl5000_sensitivity;
}
static void iwl5150_hw_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.tx_chains_num =
num_of_ant(priv->hw_params.valid_tx_ant);
priv->hw_params.rx_chains_num =
num_of_ant(priv->hw_params.valid_rx_ant);
iwl5150_set_ct_threshold(priv);
priv->hw_params.sens = &iwl5150_sensitivity;
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
return iwl_dvm_send_cmd(priv, &hcmd);
}
static void iwl6000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD;
priv->hw_params.ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl6000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
switch (priv->cfg->device_family) {
case IWL_DEVICE_FAMILY_6005:
case IWL_DEVICE_FAMILY_6030:
case IWL_DEVICE_FAMILY_6000:
break;
case IWL_DEVICE_FAMILY_6000i:
iwl_write32(priv->trans, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_SKU_2x2_IPA);
break;
case IWL_DEVICE_FAMILY_6050:
if (iwl_eeprom_calib_version(priv) >= 6)
iwl_set_bit(priv->trans, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
break;
case IWL_DEVICE_FAMILY_6150:
if (iwl_eeprom_calib_version(priv) >= 6)
iwl_set_bit(priv->trans, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6);
iwl_set_bit(priv->trans, CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_6050_1x2);
break;
default:
WARN_ON(1);
}
}
static void iwl6000_hw_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.tx_chains_num =
num_of_ant(priv->hw_params.valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
priv->hw_params.rx_chains_num = 1;
else
priv->hw_params.rx_chains_num =
num_of_ant(priv->hw_params.valid_rx_ant);
iwl6000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl6000_sensitivity;
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
return iwl_dvm_send_cmd(priv, &hcmd);
}
