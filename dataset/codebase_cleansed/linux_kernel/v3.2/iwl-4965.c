static int iwl4965_verify_bsm(struct iwl_priv *priv)
{
__le32 *image = priv->ucode_boot.v_addr;
u32 len = priv->ucode_boot.len;
u32 reg;
u32 val;
IWL_DEBUG_INFO(priv, "Begin verify bsm\n");
val = iwl_legacy_read_prph(priv, BSM_WR_DWCOUNT_REG);
for (reg = BSM_SRAM_LOWER_BOUND;
reg < BSM_SRAM_LOWER_BOUND + len;
reg += sizeof(u32), image++) {
val = iwl_legacy_read_prph(priv, reg);
if (val != le32_to_cpu(*image)) {
IWL_ERR(priv, "BSM uCode verification failed at "
"addr 0x%08X+%u (of %u), is 0x%x, s/b 0x%x\n",
BSM_SRAM_LOWER_BOUND,
reg - BSM_SRAM_LOWER_BOUND, len,
val, le32_to_cpu(*image));
return -EIO;
}
}
IWL_DEBUG_INFO(priv, "BSM bootstrap uCode image OK\n");
return 0;
}
static int iwl4965_load_bsm(struct iwl_priv *priv)
{
__le32 *image = priv->ucode_boot.v_addr;
u32 len = priv->ucode_boot.len;
dma_addr_t pinst;
dma_addr_t pdata;
u32 inst_len;
u32 data_len;
int i;
u32 done;
u32 reg_offset;
int ret;
IWL_DEBUG_INFO(priv, "Begin load bsm\n");
priv->ucode_type = UCODE_RT;
if (len > IWL49_MAX_BSM_SIZE)
return -EINVAL;
pinst = priv->ucode_init.p_addr >> 4;
pdata = priv->ucode_init_data.p_addr >> 4;
inst_len = priv->ucode_init.len;
data_len = priv->ucode_init_data.len;
iwl_legacy_write_prph(priv, BSM_DRAM_INST_PTR_REG, pinst);
iwl_legacy_write_prph(priv, BSM_DRAM_DATA_PTR_REG, pdata);
iwl_legacy_write_prph(priv, BSM_DRAM_INST_BYTECOUNT_REG, inst_len);
iwl_legacy_write_prph(priv, BSM_DRAM_DATA_BYTECOUNT_REG, data_len);
for (reg_offset = BSM_SRAM_LOWER_BOUND;
reg_offset < BSM_SRAM_LOWER_BOUND + len;
reg_offset += sizeof(u32), image++)
_iwl_legacy_write_prph(priv, reg_offset, le32_to_cpu(*image));
ret = iwl4965_verify_bsm(priv);
if (ret)
return ret;
iwl_legacy_write_prph(priv, BSM_WR_MEM_SRC_REG, 0x0);
iwl_legacy_write_prph(priv,
BSM_WR_MEM_DST_REG, IWL49_RTC_INST_LOWER_BOUND);
iwl_legacy_write_prph(priv, BSM_WR_DWCOUNT_REG, len / sizeof(u32));
iwl_legacy_write_prph(priv, BSM_WR_CTRL_REG, BSM_WR_CTRL_REG_BIT_START);
for (i = 0; i < 100; i++) {
done = iwl_legacy_read_prph(priv, BSM_WR_CTRL_REG);
if (!(done & BSM_WR_CTRL_REG_BIT_START))
break;
udelay(10);
}
if (i < 100)
IWL_DEBUG_INFO(priv, "BSM write complete, poll %d iterations\n", i);
else {
IWL_ERR(priv, "BSM write did not complete!\n");
return -EIO;
}
iwl_legacy_write_prph(priv,
BSM_WR_CTRL_REG, BSM_WR_CTRL_REG_BIT_START_EN);
return 0;
}
static int iwl4965_set_ucode_ptrs(struct iwl_priv *priv)
{
dma_addr_t pinst;
dma_addr_t pdata;
int ret = 0;
pinst = priv->ucode_code.p_addr >> 4;
pdata = priv->ucode_data_backup.p_addr >> 4;
iwl_legacy_write_prph(priv, BSM_DRAM_INST_PTR_REG, pinst);
iwl_legacy_write_prph(priv, BSM_DRAM_DATA_PTR_REG, pdata);
iwl_legacy_write_prph(priv, BSM_DRAM_DATA_BYTECOUNT_REG,
priv->ucode_data.len);
iwl_legacy_write_prph(priv, BSM_DRAM_INST_BYTECOUNT_REG,
priv->ucode_code.len | BSM_DRAM_INST_LOAD);
IWL_DEBUG_INFO(priv, "Runtime uCode pointers are set.\n");
return ret;
}
static void iwl4965_init_alive_start(struct iwl_priv *priv)
{
if (iwl4965_verify_ucode(priv)) {
IWL_DEBUG_INFO(priv, "Bad \"initialize\" uCode load.\n");
goto restart;
}
priv->temperature = iwl4965_hw_get_temperature(priv);
IWL_DEBUG_INFO(priv, "Initialization Alive received.\n");
if (iwl4965_set_ucode_ptrs(priv)) {
IWL_DEBUG_INFO(priv, "Couldn't set up uCode pointers.\n");
goto restart;
}
return;
restart:
queue_work(priv->workqueue, &priv->restart);
}
static bool iw4965_is_ht40_channel(__le32 rxon_flags)
{
int chan_mod = le32_to_cpu(rxon_flags & RXON_FLG_CHANNEL_MODE_MSK)
>> RXON_FLG_CHANNEL_MODE_POS;
return ((chan_mod == CHANNEL_MODE_PURE_40) ||
(chan_mod == CHANNEL_MODE_MIXED));
}
static void iwl4965_nic_config(struct iwl_priv *priv)
{
unsigned long flags;
u16 radio_cfg;
spin_lock_irqsave(&priv->lock, flags);
radio_cfg = iwl_legacy_eeprom_query16(priv, EEPROM_RADIO_CONFIG);
if (EEPROM_RF_CFG_TYPE_MSK(radio_cfg) == EEPROM_4965_RF_CFG_TYPE_MAX)
iwl_legacy_set_bit(priv, CSR_HW_IF_CONFIG_REG,
EEPROM_RF_CFG_TYPE_MSK(radio_cfg) |
EEPROM_RF_CFG_STEP_MSK(radio_cfg) |
EEPROM_RF_CFG_DASH_MSK(radio_cfg));
iwl_legacy_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
priv->calib_info = (struct iwl_eeprom_calib_info *)
iwl_legacy_eeprom_query_addr(priv,
EEPROM_4965_CALIB_TXPOWER_OFFSET);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void iwl4965_chain_noise_reset(struct iwl_priv *priv)
{
struct iwl_chain_noise_data *data = &(priv->chain_noise_data);
if ((data->state == IWL_CHAIN_NOISE_ALIVE) &&
iwl_legacy_is_any_associated(priv)) {
struct iwl_calib_diff_gain_cmd cmd;
data->chain_noise_a = 0;
data->chain_noise_b = 0;
data->chain_noise_c = 0;
data->chain_signal_a = 0;
data->chain_signal_b = 0;
data->chain_signal_c = 0;
data->beacon_count = 0;
memset(&cmd, 0, sizeof(cmd));
cmd.hdr.op_code = IWL_PHY_CALIBRATE_DIFF_GAIN_CMD;
cmd.diff_gain_a = 0;
cmd.diff_gain_b = 0;
cmd.diff_gain_c = 0;
if (iwl_legacy_send_cmd_pdu(priv, REPLY_PHY_CALIBRATION_CMD,
sizeof(cmd), &cmd))
IWL_ERR(priv,
"Could not send REPLY_PHY_CALIBRATION_CMD\n");
data->state = IWL_CHAIN_NOISE_ACCUMULATE;
IWL_DEBUG_CALIB(priv, "Run chain_noise_calibrate\n");
}
}
static void iwl4965_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold =
CELSIUS_TO_KELVIN(CT_KILL_THRESHOLD_LEGACY);
}
static int iwl4965_hw_set_hw_params(struct iwl_priv *priv)
{
if (priv->cfg->mod_params->num_of_queues >= IWL_MIN_NUM_QUEUES &&
priv->cfg->mod_params->num_of_queues <= IWL49_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
priv->cfg->mod_params->num_of_queues;
priv->hw_params.max_txq_num = priv->cfg->base_params->num_of_queues;
priv->hw_params.dma_chnl_num = FH49_TCSR_CHNL_NUM;
priv->hw_params.scd_bc_tbls_size =
priv->cfg->base_params->num_of_queues *
sizeof(struct iwl4965_scd_bc_tbl);
priv->hw_params.tfd_size = sizeof(struct iwl_tfd);
priv->hw_params.max_stations = IWL4965_STATION_COUNT;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWL4965_BROADCAST_ID;
priv->hw_params.max_data_size = IWL49_RTC_DATA_SIZE;
priv->hw_params.max_inst_size = IWL49_RTC_INST_SIZE;
priv->hw_params.max_bsm_size = BSM_SRAM_SIZE;
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.rx_wrt_ptr_reg = FH_RSCSR_CHNL0_WPTR;
priv->hw_params.tx_chains_num = iwl4965_num_of_ant(priv->cfg->valid_tx_ant);
priv->hw_params.rx_chains_num = iwl4965_num_of_ant(priv->cfg->valid_rx_ant);
priv->hw_params.valid_tx_ant = priv->cfg->valid_tx_ant;
priv->hw_params.valid_rx_ant = priv->cfg->valid_rx_ant;
iwl4965_set_ct_threshold(priv);
priv->hw_params.sens = &iwl4965_sensitivity;
priv->hw_params.beacon_time_tsf_bits = IWL4965_EXT_BEACON_TIME_POS;
return 0;
}
static s32 iwl4965_math_div_round(s32 num, s32 denom, s32 *res)
{
s32 sign = 1;
if (num < 0) {
sign = -sign;
num = -num;
}
if (denom < 0) {
sign = -sign;
denom = -denom;
}
*res = 1;
*res = ((num * 2 + denom) / (denom * 2)) * sign;
return 1;
}
static s32 iwl4965_get_voltage_compensation(s32 eeprom_voltage,
s32 current_voltage)
{
s32 comp = 0;
if ((TX_POWER_IWL_ILLEGAL_VOLTAGE == eeprom_voltage) ||
(TX_POWER_IWL_ILLEGAL_VOLTAGE == current_voltage))
return 0;
iwl4965_math_div_round(current_voltage - eeprom_voltage,
TX_POWER_IWL_VOLTAGE_CODES_PER_03V, &comp);
if (current_voltage > eeprom_voltage)
comp *= 2;
if ((comp < -2) || (comp > 2))
comp = 0;
return comp;
}
static s32 iwl4965_get_tx_atten_grp(u16 channel)
{
if (channel >= CALIB_IWL_TX_ATTEN_GR5_FCH &&
channel <= CALIB_IWL_TX_ATTEN_GR5_LCH)
return CALIB_CH_GROUP_5;
if (channel >= CALIB_IWL_TX_ATTEN_GR1_FCH &&
channel <= CALIB_IWL_TX_ATTEN_GR1_LCH)
return CALIB_CH_GROUP_1;
if (channel >= CALIB_IWL_TX_ATTEN_GR2_FCH &&
channel <= CALIB_IWL_TX_ATTEN_GR2_LCH)
return CALIB_CH_GROUP_2;
if (channel >= CALIB_IWL_TX_ATTEN_GR3_FCH &&
channel <= CALIB_IWL_TX_ATTEN_GR3_LCH)
return CALIB_CH_GROUP_3;
if (channel >= CALIB_IWL_TX_ATTEN_GR4_FCH &&
channel <= CALIB_IWL_TX_ATTEN_GR4_LCH)
return CALIB_CH_GROUP_4;
return -EINVAL;
}
static u32 iwl4965_get_sub_band(const struct iwl_priv *priv, u32 channel)
{
s32 b = -1;
for (b = 0; b < EEPROM_TX_POWER_BANDS; b++) {
if (priv->calib_info->band_info[b].ch_from == 0)
continue;
if ((channel >= priv->calib_info->band_info[b].ch_from)
&& (channel <= priv->calib_info->band_info[b].ch_to))
break;
}
return b;
}
static s32 iwl4965_interpolate_value(s32 x, s32 x1, s32 y1, s32 x2, s32 y2)
{
s32 val;
if (x2 == x1)
return y1;
else {
iwl4965_math_div_round((x2 - x) * (y1 - y2), (x2 - x1), &val);
return val + y2;
}
}
static int iwl4965_interpolate_chan(struct iwl_priv *priv, u32 channel,
struct iwl_eeprom_calib_ch_info *chan_info)
{
s32 s = -1;
u32 c;
u32 m;
const struct iwl_eeprom_calib_measure *m1;
const struct iwl_eeprom_calib_measure *m2;
struct iwl_eeprom_calib_measure *omeas;
u32 ch_i1;
u32 ch_i2;
s = iwl4965_get_sub_band(priv, channel);
if (s >= EEPROM_TX_POWER_BANDS) {
IWL_ERR(priv, "Tx Power can not find channel %d\n", channel);
return -1;
}
ch_i1 = priv->calib_info->band_info[s].ch1.ch_num;
ch_i2 = priv->calib_info->band_info[s].ch2.ch_num;
chan_info->ch_num = (u8) channel;
IWL_DEBUG_TXPOWER(priv, "channel %d subband %d factory cal ch %d & %d\n",
channel, s, ch_i1, ch_i2);
for (c = 0; c < EEPROM_TX_POWER_TX_CHAINS; c++) {
for (m = 0; m < EEPROM_TX_POWER_MEASUREMENTS; m++) {
m1 = &(priv->calib_info->band_info[s].ch1.
measurements[c][m]);
m2 = &(priv->calib_info->band_info[s].ch2.
measurements[c][m]);
omeas = &(chan_info->measurements[c][m]);
omeas->actual_pow =
(u8) iwl4965_interpolate_value(channel, ch_i1,
m1->actual_pow,
ch_i2,
m2->actual_pow);
omeas->gain_idx =
(u8) iwl4965_interpolate_value(channel, ch_i1,
m1->gain_idx, ch_i2,
m2->gain_idx);
omeas->temperature =
(u8) iwl4965_interpolate_value(channel, ch_i1,
m1->temperature,
ch_i2,
m2->temperature);
omeas->pa_det =
(s8) iwl4965_interpolate_value(channel, ch_i1,
m1->pa_det, ch_i2,
m2->pa_det);
IWL_DEBUG_TXPOWER(priv,
"chain %d meas %d AP1=%d AP2=%d AP=%d\n", c, m,
m1->actual_pow, m2->actual_pow, omeas->actual_pow);
IWL_DEBUG_TXPOWER(priv,
"chain %d meas %d NI1=%d NI2=%d NI=%d\n", c, m,
m1->gain_idx, m2->gain_idx, omeas->gain_idx);
IWL_DEBUG_TXPOWER(priv,
"chain %d meas %d PA1=%d PA2=%d PA=%d\n", c, m,
m1->pa_det, m2->pa_det, omeas->pa_det);
IWL_DEBUG_TXPOWER(priv,
"chain %d meas %d T1=%d T2=%d T=%d\n", c, m,
m1->temperature, m2->temperature,
omeas->temperature);
}
}
return 0;
}
static s32 get_min_power_index(s32 rate_power_index, u32 band)
{
if (!band) {
if ((rate_power_index & 7) <= 4)
return MIN_TX_GAIN_INDEX_52GHZ_EXT;
}
return MIN_TX_GAIN_INDEX;
}
static int iwl4965_fill_txpower_tbl(struct iwl_priv *priv, u8 band, u16 channel,
u8 is_ht40, u8 ctrl_chan_high,
struct iwl4965_tx_power_db *tx_power_tbl)
{
u8 saturation_power;
s32 target_power;
s32 user_target_power;
s32 power_limit;
s32 current_temp;
s32 reg_limit;
s32 current_regulatory;
s32 txatten_grp = CALIB_CH_GROUP_MAX;
int i;
int c;
const struct iwl_channel_info *ch_info = NULL;
struct iwl_eeprom_calib_ch_info ch_eeprom_info;
const struct iwl_eeprom_calib_measure *measurement;
s16 voltage;
s32 init_voltage;
s32 voltage_compensation;
s32 degrees_per_05db_num;
s32 degrees_per_05db_denom;
s32 factory_temp;
s32 temperature_comp[2];
s32 factory_gain_index[2];
s32 factory_actual_pwr[2];
s32 power_index;
user_target_power = 2 * priv->tx_power_user_lmt;
IWL_DEBUG_TXPOWER(priv, "chan %d band %d is_ht40 %d\n", channel, band,
is_ht40);
ch_info = iwl_legacy_get_channel_info(priv, priv->band, channel);
if (!iwl_legacy_is_channel_valid(ch_info))
return -EINVAL;
txatten_grp = iwl4965_get_tx_atten_grp(channel);
if (txatten_grp < 0) {
IWL_ERR(priv, "Can't find txatten group for channel %d.\n",
channel);
return txatten_grp;
}
IWL_DEBUG_TXPOWER(priv, "channel %d belongs to txatten group %d\n",
channel, txatten_grp);
if (is_ht40) {
if (ctrl_chan_high)
channel -= 2;
else
channel += 2;
}
if (band)
saturation_power = priv->calib_info->saturation_power24;
else
saturation_power = priv->calib_info->saturation_power52;
if (saturation_power < IWL_TX_POWER_SATURATION_MIN ||
saturation_power > IWL_TX_POWER_SATURATION_MAX) {
if (band)
saturation_power = IWL_TX_POWER_DEFAULT_SATURATION_24;
else
saturation_power = IWL_TX_POWER_DEFAULT_SATURATION_52;
}
if (is_ht40)
reg_limit = ch_info->ht40_max_power_avg * 2;
else
reg_limit = ch_info->max_power_avg * 2;
if ((reg_limit < IWL_TX_POWER_REGULATORY_MIN) ||
(reg_limit > IWL_TX_POWER_REGULATORY_MAX)) {
if (band)
reg_limit = IWL_TX_POWER_DEFAULT_REGULATORY_24;
else
reg_limit = IWL_TX_POWER_DEFAULT_REGULATORY_52;
}
iwl4965_interpolate_chan(priv, channel, &ch_eeprom_info);
voltage = le16_to_cpu(priv->calib_info->voltage);
init_voltage = (s32)le32_to_cpu(priv->card_alive_init.voltage);
voltage_compensation =
iwl4965_get_voltage_compensation(voltage, init_voltage);
IWL_DEBUG_TXPOWER(priv, "curr volt %d eeprom volt %d volt comp %d\n",
init_voltage,
voltage, voltage_compensation);
current_temp = max(priv->temperature, IWL_TX_POWER_TEMPERATURE_MIN);
current_temp = min(priv->temperature, IWL_TX_POWER_TEMPERATURE_MAX);
current_temp = KELVIN_TO_CELSIUS(current_temp);
degrees_per_05db_num =
tx_power_cmp_tble[txatten_grp].degrees_per_05db_a;
degrees_per_05db_denom =
tx_power_cmp_tble[txatten_grp].degrees_per_05db_a_denom;
for (c = 0; c < 2; c++) {
measurement = &ch_eeprom_info.measurements[c][1];
factory_temp = measurement->temperature;
iwl4965_math_div_round((current_temp - factory_temp) *
degrees_per_05db_denom,
degrees_per_05db_num,
&temperature_comp[c]);
factory_gain_index[c] = measurement->gain_idx;
factory_actual_pwr[c] = measurement->actual_pow;
IWL_DEBUG_TXPOWER(priv, "chain = %d\n", c);
IWL_DEBUG_TXPOWER(priv, "fctry tmp %d, "
"curr tmp %d, comp %d steps\n",
factory_temp, current_temp,
temperature_comp[c]);
IWL_DEBUG_TXPOWER(priv, "fctry idx %d, fctry pwr %d\n",
factory_gain_index[c],
factory_actual_pwr[c]);
}
for (i = 0; i < POWER_TABLE_NUM_ENTRIES; i++) {
u8 is_mimo_rate;
union iwl4965_tx_power_dual_stream tx_power;
if (i & 0x8) {
current_regulatory = reg_limit -
IWL_TX_POWER_MIMO_REGULATORY_COMPENSATION;
is_mimo_rate = 1;
} else {
current_regulatory = reg_limit;
is_mimo_rate = 0;
}
power_limit = saturation_power - back_off_table[i];
if (power_limit > current_regulatory)
power_limit = current_regulatory;
target_power = user_target_power;
if (target_power > power_limit)
target_power = power_limit;
IWL_DEBUG_TXPOWER(priv, "rate %d sat %d reg %d usr %d tgt %d\n",
i, saturation_power - back_off_table[i],
current_regulatory, user_target_power,
target_power);
for (c = 0; c < 2; c++) {
s32 atten_value;
if (is_mimo_rate)
atten_value =
(s32)le32_to_cpu(priv->card_alive_init.
tx_atten[txatten_grp][c]);
else
atten_value = 0;
power_index = (u8) (factory_gain_index[c] -
(target_power -
factory_actual_pwr[c]) -
temperature_comp[c] -
voltage_compensation +
atten_value);
if (power_index < get_min_power_index(i, band))
power_index = get_min_power_index(i, band);
if (!band)
power_index += 9;
if (i == POWER_TABLE_CCK_ENTRY)
power_index +=
IWL_TX_POWER_CCK_COMPENSATION_C_STEP;
if (power_index > 107) {
IWL_WARN(priv, "txpower index %d > 107\n",
power_index);
power_index = 107;
}
if (power_index < 0) {
IWL_WARN(priv, "txpower index %d < 0\n",
power_index);
power_index = 0;
}
tx_power.s.radio_tx_gain[c] =
gain_table[band][power_index].radio;
tx_power.s.dsp_predis_atten[c] =
gain_table[band][power_index].dsp;
IWL_DEBUG_TXPOWER(priv, "chain %d mimo %d index %d "
"gain 0x%02x dsp %d\n",
c, atten_value, power_index,
tx_power.s.radio_tx_gain[c],
tx_power.s.dsp_predis_atten[c]);
}
tx_power_tbl->power_tbl[i].dw = cpu_to_le32(tx_power.dw);
}
return 0;
}
static int iwl4965_send_tx_power(struct iwl_priv *priv)
{
struct iwl4965_txpowertable_cmd cmd = { 0 };
int ret;
u8 band = 0;
bool is_ht40 = false;
u8 ctrl_chan_high = 0;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
if (WARN_ONCE(test_bit(STATUS_SCAN_HW, &priv->status),
"TX Power requested while scanning!\n"))
return -EAGAIN;
band = priv->band == IEEE80211_BAND_2GHZ;
is_ht40 = iw4965_is_ht40_channel(ctx->active.flags);
if (is_ht40 && (ctx->active.flags & RXON_FLG_CTRL_CHANNEL_LOC_HI_MSK))
ctrl_chan_high = 1;
cmd.band = band;
cmd.channel = ctx->active.channel;
ret = iwl4965_fill_txpower_tbl(priv, band,
le16_to_cpu(ctx->active.channel),
is_ht40, ctrl_chan_high, &cmd.tx_power);
if (ret)
goto out;
ret = iwl_legacy_send_cmd_pdu(priv,
REPLY_TX_PWR_TABLE_CMD, sizeof(cmd), &cmd);
out:
return ret;
}
static int iwl4965_send_rxon_assoc(struct iwl_priv *priv,
struct iwl_rxon_context *ctx)
{
int ret = 0;
struct iwl4965_rxon_assoc_cmd rxon_assoc;
const struct iwl_legacy_rxon_cmd *rxon1 = &ctx->staging;
const struct iwl_legacy_rxon_cmd *rxon2 = &ctx->active;
if ((rxon1->flags == rxon2->flags) &&
(rxon1->filter_flags == rxon2->filter_flags) &&
(rxon1->cck_basic_rates == rxon2->cck_basic_rates) &&
(rxon1->ofdm_ht_single_stream_basic_rates ==
rxon2->ofdm_ht_single_stream_basic_rates) &&
(rxon1->ofdm_ht_dual_stream_basic_rates ==
rxon2->ofdm_ht_dual_stream_basic_rates) &&
(rxon1->rx_chain == rxon2->rx_chain) &&
(rxon1->ofdm_basic_rates == rxon2->ofdm_basic_rates)) {
IWL_DEBUG_INFO(priv, "Using current RXON_ASSOC. Not resending.\n");
return 0;
}
rxon_assoc.flags = ctx->staging.flags;
rxon_assoc.filter_flags = ctx->staging.filter_flags;
rxon_assoc.ofdm_basic_rates = ctx->staging.ofdm_basic_rates;
rxon_assoc.cck_basic_rates = ctx->staging.cck_basic_rates;
rxon_assoc.reserved = 0;
rxon_assoc.ofdm_ht_single_stream_basic_rates =
ctx->staging.ofdm_ht_single_stream_basic_rates;
rxon_assoc.ofdm_ht_dual_stream_basic_rates =
ctx->staging.ofdm_ht_dual_stream_basic_rates;
rxon_assoc.rx_chain_select_flags = ctx->staging.rx_chain;
ret = iwl_legacy_send_cmd_pdu_async(priv, REPLY_RXON_ASSOC,
sizeof(rxon_assoc), &rxon_assoc, NULL);
return ret;
}
static int iwl4965_commit_rxon(struct iwl_priv *priv, struct iwl_rxon_context *ctx)
{
struct iwl_legacy_rxon_cmd *active_rxon = (void *)&ctx->active;
int ret;
bool new_assoc =
!!(ctx->staging.filter_flags & RXON_FILTER_ASSOC_MSK);
if (!iwl_legacy_is_alive(priv))
return -EBUSY;
if (!ctx->is_active)
return 0;
ctx->staging.flags |= RXON_FLG_TSF2HOST_MSK;
ret = iwl_legacy_check_rxon_cmd(priv, ctx);
if (ret) {
IWL_ERR(priv, "Invalid RXON configuration. Not committing.\n");
return -EINVAL;
}
if (test_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->status) &&
(priv->switch_channel != ctx->staging.channel)) {
IWL_DEBUG_11H(priv, "abort channel switch on %d\n",
le16_to_cpu(priv->switch_channel));
iwl_legacy_chswitch_done(priv, false);
}
if (!iwl_legacy_full_rxon_required(priv, ctx)) {
ret = iwl_legacy_send_rxon_assoc(priv, ctx);
if (ret) {
IWL_ERR(priv, "Error setting RXON_ASSOC (%d)\n", ret);
return ret;
}
memcpy(active_rxon, &ctx->staging, sizeof(*active_rxon));
iwl_legacy_print_rx_config_cmd(priv, ctx);
iwl_legacy_set_tx_power(priv, priv->tx_power_next, false);
return 0;
}
if (iwl_legacy_is_associated_ctx(ctx) && new_assoc) {
IWL_DEBUG_INFO(priv, "Toggling associated bit on current RXON\n");
active_rxon->filter_flags &= ~RXON_FILTER_ASSOC_MSK;
ret = iwl_legacy_send_cmd_pdu(priv, ctx->rxon_cmd,
sizeof(struct iwl_legacy_rxon_cmd),
active_rxon);
if (ret) {
active_rxon->filter_flags |= RXON_FILTER_ASSOC_MSK;
IWL_ERR(priv, "Error clearing ASSOC_MSK (%d)\n", ret);
return ret;
}
iwl_legacy_clear_ucode_stations(priv, ctx);
iwl_legacy_restore_stations(priv, ctx);
ret = iwl4965_restore_default_wep_keys(priv, ctx);
if (ret) {
IWL_ERR(priv, "Failed to restore WEP keys (%d)\n", ret);
return ret;
}
}
IWL_DEBUG_INFO(priv, "Sending RXON\n"
"* with%s RXON_FILTER_ASSOC_MSK\n"
"* channel = %d\n"
"* bssid = %pM\n",
(new_assoc ? "" : "out"),
le16_to_cpu(ctx->staging.channel),
ctx->staging.bssid_addr);
iwl_legacy_set_rxon_hwcrypto(priv, ctx,
!priv->cfg->mod_params->sw_crypto);
if (!new_assoc) {
ret = iwl_legacy_send_cmd_pdu(priv, ctx->rxon_cmd,
sizeof(struct iwl_legacy_rxon_cmd), &ctx->staging);
if (ret) {
IWL_ERR(priv, "Error setting new RXON (%d)\n", ret);
return ret;
}
IWL_DEBUG_INFO(priv, "Return from !new_assoc RXON.\n");
memcpy(active_rxon, &ctx->staging, sizeof(*active_rxon));
iwl_legacy_clear_ucode_stations(priv, ctx);
iwl_legacy_restore_stations(priv, ctx);
ret = iwl4965_restore_default_wep_keys(priv, ctx);
if (ret) {
IWL_ERR(priv, "Failed to restore WEP keys (%d)\n", ret);
return ret;
}
}
if (new_assoc) {
priv->start_calib = 0;
ret = iwl_legacy_send_cmd_pdu(priv, ctx->rxon_cmd,
sizeof(struct iwl_legacy_rxon_cmd), &ctx->staging);
if (ret) {
IWL_ERR(priv, "Error setting new RXON (%d)\n", ret);
return ret;
}
memcpy(active_rxon, &ctx->staging, sizeof(*active_rxon));
}
iwl_legacy_print_rx_config_cmd(priv, ctx);
iwl4965_init_sensitivity(priv);
ret = iwl_legacy_set_tx_power(priv, priv->tx_power_next, true);
if (ret) {
IWL_ERR(priv, "Error sending TX power (%d)\n", ret);
return ret;
}
return 0;
}
static int iwl4965_hw_channel_switch(struct iwl_priv *priv,
struct ieee80211_channel_switch *ch_switch)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
int rc;
u8 band = 0;
bool is_ht40 = false;
u8 ctrl_chan_high = 0;
struct iwl4965_channel_switch_cmd cmd;
const struct iwl_channel_info *ch_info;
u32 switch_time_in_usec, ucode_switch_time;
u16 ch;
u32 tsf_low;
u8 switch_count;
u16 beacon_interval = le16_to_cpu(ctx->timing.beacon_interval);
struct ieee80211_vif *vif = ctx->vif;
band = priv->band == IEEE80211_BAND_2GHZ;
is_ht40 = iw4965_is_ht40_channel(ctx->staging.flags);
if (is_ht40 &&
(ctx->staging.flags & RXON_FLG_CTRL_CHANNEL_LOC_HI_MSK))
ctrl_chan_high = 1;
cmd.band = band;
cmd.expect_beacon = 0;
ch = ch_switch->channel->hw_value;
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
ucode_switch_time = iwl_legacy_usecs_to_beacons(priv,
switch_time_in_usec,
beacon_interval);
cmd.switch_time = iwl_legacy_add_beacon_time(priv,
priv->ucode_beacon_time,
ucode_switch_time,
beacon_interval);
}
IWL_DEBUG_11H(priv, "uCode time for the switch is 0x%x\n",
cmd.switch_time);
ch_info = iwl_legacy_get_channel_info(priv, priv->band, ch);
if (ch_info)
cmd.expect_beacon = iwl_legacy_is_channel_radar(ch_info);
else {
IWL_ERR(priv, "invalid channel switch from %u to %u\n",
ctx->active.channel, ch);
return -EFAULT;
}
rc = iwl4965_fill_txpower_tbl(priv, band, ch, is_ht40,
ctrl_chan_high, &cmd.tx_power);
if (rc) {
IWL_DEBUG_11H(priv, "error:%d fill txpower_tbl\n", rc);
return rc;
}
return iwl_legacy_send_cmd_pdu(priv,
REPLY_CHANNEL_SWITCH, sizeof(cmd), &cmd);
}
static void iwl4965_txq_update_byte_cnt_tbl(struct iwl_priv *priv,
struct iwl_tx_queue *txq,
u16 byte_cnt)
{
struct iwl4965_scd_bc_tbl *scd_bc_tbl = priv->scd_bc_tbls.addr;
int txq_id = txq->q.id;
int write_ptr = txq->q.write_ptr;
int len = byte_cnt + IWL_TX_CRC_SIZE + IWL_TX_DELIMITER_SIZE;
__le16 bc_ent;
WARN_ON(len > 0xFFF || write_ptr >= TFD_QUEUE_SIZE_MAX);
bc_ent = cpu_to_le16(len & 0xFFF);
scd_bc_tbl[txq_id].tfd_offset[write_ptr] = bc_ent;
if (write_ptr < TFD_QUEUE_SIZE_BC_DUP)
scd_bc_tbl[txq_id].
tfd_offset[TFD_QUEUE_SIZE_MAX + write_ptr] = bc_ent;
}
static int iwl4965_hw_get_temperature(struct iwl_priv *priv)
{
s32 temperature;
s32 vt;
s32 R1, R2, R3;
u32 R4;
if (test_bit(STATUS_TEMPERATURE, &priv->status) &&
(priv->_4965.statistics.flag &
STATISTICS_REPLY_FLG_HT40_MODE_MSK)) {
IWL_DEBUG_TEMP(priv, "Running HT40 temperature calibration\n");
R1 = (s32)le32_to_cpu(priv->card_alive_init.therm_r1[1]);
R2 = (s32)le32_to_cpu(priv->card_alive_init.therm_r2[1]);
R3 = (s32)le32_to_cpu(priv->card_alive_init.therm_r3[1]);
R4 = le32_to_cpu(priv->card_alive_init.therm_r4[1]);
} else {
IWL_DEBUG_TEMP(priv, "Running temperature calibration\n");
R1 = (s32)le32_to_cpu(priv->card_alive_init.therm_r1[0]);
R2 = (s32)le32_to_cpu(priv->card_alive_init.therm_r2[0]);
R3 = (s32)le32_to_cpu(priv->card_alive_init.therm_r3[0]);
R4 = le32_to_cpu(priv->card_alive_init.therm_r4[0]);
}
if (!test_bit(STATUS_TEMPERATURE, &priv->status))
vt = sign_extend32(R4, 23);
else
vt = sign_extend32(le32_to_cpu(priv->_4965.statistics.
general.common.temperature), 23);
IWL_DEBUG_TEMP(priv, "Calib values R[1-3]: %d %d %d R4: %d\n", R1, R2, R3, vt);
if (R3 == R1) {
IWL_ERR(priv, "Calibration conflict R1 == R3\n");
return -1;
}
temperature = TEMPERATURE_CALIB_A_VAL * (vt - R2);
temperature /= (R3 - R1);
temperature = (temperature * 97) / 100 + TEMPERATURE_CALIB_KELVIN_OFFSET;
IWL_DEBUG_TEMP(priv, "Calibrated temperature: %dK, %dC\n",
temperature, KELVIN_TO_CELSIUS(temperature));
return temperature;
}
static int iwl4965_is_temp_calib_needed(struct iwl_priv *priv)
{
int temp_diff;
if (!test_bit(STATUS_STATISTICS, &priv->status)) {
IWL_DEBUG_TEMP(priv, "Temperature not updated -- no statistics.\n");
return 0;
}
temp_diff = priv->temperature - priv->last_temperature;
if (temp_diff < 0) {
IWL_DEBUG_POWER(priv, "Getting cooler, delta %d\n", temp_diff);
temp_diff = -temp_diff;
} else if (temp_diff == 0)
IWL_DEBUG_POWER(priv, "Temperature unchanged\n");
else
IWL_DEBUG_POWER(priv, "Getting warmer, delta %d\n", temp_diff);
if (temp_diff < IWL_TEMPERATURE_THRESHOLD) {
IWL_DEBUG_POWER(priv, " => thermal txpower calib not needed\n");
return 0;
}
IWL_DEBUG_POWER(priv, " => thermal txpower calib needed\n");
return 1;
}
static void iwl4965_temperature_calib(struct iwl_priv *priv)
{
s32 temp;
temp = iwl4965_hw_get_temperature(priv);
if (IWL_TX_POWER_TEMPERATURE_OUT_OF_RANGE(temp))
return;
if (priv->temperature != temp) {
if (priv->temperature)
IWL_DEBUG_TEMP(priv, "Temperature changed "
"from %dC to %dC\n",
KELVIN_TO_CELSIUS(priv->temperature),
KELVIN_TO_CELSIUS(temp));
else
IWL_DEBUG_TEMP(priv, "Temperature "
"initialized to %dC\n",
KELVIN_TO_CELSIUS(temp));
}
priv->temperature = temp;
set_bit(STATUS_TEMPERATURE, &priv->status);
if (!priv->disable_tx_power_cal &&
unlikely(!test_bit(STATUS_SCANNING, &priv->status)) &&
iwl4965_is_temp_calib_needed(priv))
queue_work(priv->workqueue, &priv->txpower_work);
}
static u16 iwl4965_get_hcmd_size(u8 cmd_id, u16 len)
{
switch (cmd_id) {
case REPLY_RXON:
return (u16) sizeof(struct iwl4965_rxon_cmd);
default:
return len;
}
}
static u16 iwl4965_build_addsta_hcmd(const struct iwl_legacy_addsta_cmd *cmd,
u8 *data)
{
struct iwl4965_addsta_cmd *addsta = (struct iwl4965_addsta_cmd *)data;
addsta->mode = cmd->mode;
memcpy(&addsta->sta, &cmd->sta, sizeof(struct sta_id_modify));
memcpy(&addsta->key, &cmd->key, sizeof(struct iwl4965_keyinfo));
addsta->station_flags = cmd->station_flags;
addsta->station_flags_msk = cmd->station_flags_msk;
addsta->tid_disable_tx = cmd->tid_disable_tx;
addsta->add_immediate_ba_tid = cmd->add_immediate_ba_tid;
addsta->remove_immediate_ba_tid = cmd->remove_immediate_ba_tid;
addsta->add_immediate_ba_ssn = cmd->add_immediate_ba_ssn;
addsta->sleep_tx_count = cmd->sleep_tx_count;
addsta->reserved1 = cpu_to_le16(0);
addsta->reserved2 = cpu_to_le16(0);
return (u16)sizeof(struct iwl4965_addsta_cmd);
}
static inline u32 iwl4965_get_scd_ssn(struct iwl4965_tx_resp *tx_resp)
{
return le32_to_cpup(&tx_resp->u.status + tx_resp->frame_count) & MAX_SN;
}
static int iwl4965_tx_status_reply_tx(struct iwl_priv *priv,
struct iwl_ht_agg *agg,
struct iwl4965_tx_resp *tx_resp,
int txq_id, u16 start_idx)
{
u16 status;
struct agg_tx_status *frame_status = tx_resp->u.agg_status;
struct ieee80211_tx_info *info = NULL;
struct ieee80211_hdr *hdr = NULL;
u32 rate_n_flags = le32_to_cpu(tx_resp->rate_n_flags);
int i, sh, idx;
u16 seq;
if (agg->wait_for_ba)
IWL_DEBUG_TX_REPLY(priv, "got tx response w/o block-ack\n");
agg->frame_count = tx_resp->frame_count;
agg->start_idx = start_idx;
agg->rate_n_flags = rate_n_flags;
agg->bitmap = 0;
if (agg->frame_count == 1) {
status = le16_to_cpu(frame_status[0].status);
idx = start_idx;
IWL_DEBUG_TX_REPLY(priv, "FrameCnt = %d, StartIdx=%d idx=%d\n",
agg->frame_count, agg->start_idx, idx);
info = IEEE80211_SKB_CB(priv->txq[txq_id].txb[idx].skb);
info->status.rates[0].count = tx_resp->failure_frame + 1;
info->flags &= ~IEEE80211_TX_CTL_AMPDU;
info->flags |= iwl4965_tx_status_to_mac80211(status);
iwl4965_hwrate_to_tx_control(priv, rate_n_flags, info);
IWL_DEBUG_TX_REPLY(priv, "1 Frame 0x%x failure :%d\n",
status & 0xff, tx_resp->failure_frame);
IWL_DEBUG_TX_REPLY(priv, "Rate Info rate_n_flags=%x\n", rate_n_flags);
agg->wait_for_ba = 0;
} else {
u64 bitmap = 0;
int start = agg->start_idx;
for (i = 0; i < agg->frame_count; i++) {
u16 sc;
status = le16_to_cpu(frame_status[i].status);
seq = le16_to_cpu(frame_status[i].sequence);
idx = SEQ_TO_INDEX(seq);
txq_id = SEQ_TO_QUEUE(seq);
if (status & (AGG_TX_STATE_FEW_BYTES_MSK |
AGG_TX_STATE_ABORT_MSK))
continue;
IWL_DEBUG_TX_REPLY(priv, "FrameCnt = %d, txq_id=%d idx=%d\n",
agg->frame_count, txq_id, idx);
hdr = iwl_legacy_tx_queue_get_hdr(priv, txq_id, idx);
if (!hdr) {
IWL_ERR(priv,
"BUG_ON idx doesn't point to valid skb"
" idx=%d, txq_id=%d\n", idx, txq_id);
return -1;
}
sc = le16_to_cpu(hdr->seq_ctrl);
if (idx != (SEQ_TO_SN(sc) & 0xff)) {
IWL_ERR(priv,
"BUG_ON idx doesn't match seq control"
" idx=%d, seq_idx=%d, seq=%d\n",
idx, SEQ_TO_SN(sc), hdr->seq_ctrl);
return -1;
}
IWL_DEBUG_TX_REPLY(priv, "AGG Frame i=%d idx %d seq=%d\n",
i, idx, SEQ_TO_SN(sc));
sh = idx - start;
if (sh > 64) {
sh = (start - idx) + 0xff;
bitmap = bitmap << sh;
sh = 0;
start = idx;
} else if (sh < -64)
sh = 0xff - (start - idx);
else if (sh < 0) {
sh = start - idx;
start = idx;
bitmap = bitmap << sh;
sh = 0;
}
bitmap |= 1ULL << sh;
IWL_DEBUG_TX_REPLY(priv, "start=%d bitmap=0x%llx\n",
start, (unsigned long long)bitmap);
}
agg->bitmap = bitmap;
agg->start_idx = start;
IWL_DEBUG_TX_REPLY(priv, "Frames %d start_idx=%d bitmap=0x%llx\n",
agg->frame_count, agg->start_idx,
(unsigned long long)agg->bitmap);
if (bitmap)
agg->wait_for_ba = 1;
}
return 0;
}
static u8 iwl4965_find_station(struct iwl_priv *priv, const u8 *addr)
{
int i;
int start = 0;
int ret = IWL_INVALID_STATION;
unsigned long flags;
if ((priv->iw_mode == NL80211_IFTYPE_ADHOC))
start = IWL_STA_ID;
if (is_broadcast_ether_addr(addr))
return priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id;
spin_lock_irqsave(&priv->sta_lock, flags);
for (i = start; i < priv->hw_params.max_stations; i++)
if (priv->stations[i].used &&
(!compare_ether_addr(priv->stations[i].sta.sta.addr,
addr))) {
ret = i;
goto out;
}
IWL_DEBUG_ASSOC_LIMIT(priv, "can not find STA %pM total %d\n",
addr, priv->num_stations);
out:
if (ret != IWL_INVALID_STATION &&
(!(priv->stations[ret].used & IWL_STA_UCODE_ACTIVE) ||
((priv->stations[ret].used & IWL_STA_UCODE_ACTIVE) &&
(priv->stations[ret].used & IWL_STA_UCODE_INPROGRESS)))) {
IWL_ERR(priv, "Requested station info for sta %d before ready.\n",
ret);
ret = IWL_INVALID_STATION;
}
spin_unlock_irqrestore(&priv->sta_lock, flags);
return ret;
}
static int iwl4965_get_ra_sta_id(struct iwl_priv *priv, struct ieee80211_hdr *hdr)
{
if (priv->iw_mode == NL80211_IFTYPE_STATION) {
return IWL_AP_ID;
} else {
u8 *da = ieee80211_get_DA(hdr);
return iwl4965_find_station(priv, da);
}
}
static void iwl4965_rx_reply_tx(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 sequence = le16_to_cpu(pkt->hdr.sequence);
int txq_id = SEQ_TO_QUEUE(sequence);
int index = SEQ_TO_INDEX(sequence);
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct ieee80211_hdr *hdr;
struct ieee80211_tx_info *info;
struct iwl4965_tx_resp *tx_resp = (void *)&pkt->u.raw[0];
u32 status = le32_to_cpu(tx_resp->u.status);
int uninitialized_var(tid);
int sta_id;
int freed;
u8 *qc = NULL;
unsigned long flags;
if ((index >= txq->q.n_bd) || (iwl_legacy_queue_used(&txq->q, index) == 0)) {
IWL_ERR(priv, "Read index for DMA queue txq_id (%d) index %d "
"is out of range [0-%d] %d %d\n", txq_id,
index, txq->q.n_bd, txq->q.write_ptr,
txq->q.read_ptr);
return;
}
txq->time_stamp = jiffies;
info = IEEE80211_SKB_CB(txq->txb[txq->q.read_ptr].skb);
memset(&info->status, 0, sizeof(info->status));
hdr = iwl_legacy_tx_queue_get_hdr(priv, txq_id, index);
if (ieee80211_is_data_qos(hdr->frame_control)) {
qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & 0xf;
}
sta_id = iwl4965_get_ra_sta_id(priv, hdr);
if (txq->sched_retry && unlikely(sta_id == IWL_INVALID_STATION)) {
IWL_ERR(priv, "Station not known\n");
return;
}
spin_lock_irqsave(&priv->sta_lock, flags);
if (txq->sched_retry) {
const u32 scd_ssn = iwl4965_get_scd_ssn(tx_resp);
struct iwl_ht_agg *agg = NULL;
WARN_ON(!qc);
agg = &priv->stations[sta_id].tid[tid].agg;
iwl4965_tx_status_reply_tx(priv, agg, tx_resp, txq_id, index);
if ((tx_resp->frame_count == 1) && !iwl4965_is_tx_success(status))
info->flags |= IEEE80211_TX_STAT_AMPDU_NO_BACK;
if (txq->q.read_ptr != (scd_ssn & 0xff)) {
index = iwl_legacy_queue_dec_wrap(scd_ssn & 0xff,
txq->q.n_bd);
IWL_DEBUG_TX_REPLY(priv, "Retry scheduler reclaim scd_ssn "
"%d index %d\n", scd_ssn , index);
freed = iwl4965_tx_queue_reclaim(priv, txq_id, index);
if (qc)
iwl4965_free_tfds_in_queue(priv, sta_id,
tid, freed);
if (priv->mac80211_registered &&
(iwl_legacy_queue_space(&txq->q) > txq->q.low_mark)
&& (agg->state != IWL_EMPTYING_HW_QUEUE_DELBA))
iwl_legacy_wake_queue(priv, txq);
}
} else {
info->status.rates[0].count = tx_resp->failure_frame + 1;
info->flags |= iwl4965_tx_status_to_mac80211(status);
iwl4965_hwrate_to_tx_control(priv,
le32_to_cpu(tx_resp->rate_n_flags),
info);
IWL_DEBUG_TX_REPLY(priv, "TXQ %d status %s (0x%08x) "
"rate_n_flags 0x%x retries %d\n",
txq_id,
iwl4965_get_tx_fail_reason(status), status,
le32_to_cpu(tx_resp->rate_n_flags),
tx_resp->failure_frame);
freed = iwl4965_tx_queue_reclaim(priv, txq_id, index);
if (qc && likely(sta_id != IWL_INVALID_STATION))
iwl4965_free_tfds_in_queue(priv, sta_id, tid, freed);
else if (sta_id == IWL_INVALID_STATION)
IWL_DEBUG_TX_REPLY(priv, "Station not known\n");
if (priv->mac80211_registered &&
(iwl_legacy_queue_space(&txq->q) > txq->q.low_mark))
iwl_legacy_wake_queue(priv, txq);
}
if (qc && likely(sta_id != IWL_INVALID_STATION))
iwl4965_txq_check_empty(priv, sta_id, tid, txq_id);
iwl4965_check_abort_status(priv, tx_resp->frame_count, status);
spin_unlock_irqrestore(&priv->sta_lock, flags);
}
static void iwl4965_rx_beacon_notif(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl4965_beacon_notif *beacon = (void *)pkt->u.raw;
u8 rate __maybe_unused =
iwl4965_hw_get_rate(beacon->beacon_notify_hdr.rate_n_flags);
IWL_DEBUG_RX(priv, "beacon status %#x, retries:%d ibssmgr:%d "
"tsf:0x%.8x%.8x rate:%d\n",
le32_to_cpu(beacon->beacon_notify_hdr.u.status) & TX_STATUS_MSK,
beacon->beacon_notify_hdr.failure_frame,
le32_to_cpu(beacon->ibss_mgr_status),
le32_to_cpu(beacon->high_tsf),
le32_to_cpu(beacon->low_tsf), rate);
priv->ibss_manager = le32_to_cpu(beacon->ibss_mgr_status);
}
static void iwl4965_rx_handler_setup(struct iwl_priv *priv)
{
priv->rx_handlers[REPLY_RX] = iwl4965_rx_reply_rx;
priv->rx_handlers[REPLY_TX] = iwl4965_rx_reply_tx;
priv->rx_handlers[BEACON_NOTIFICATION] = iwl4965_rx_beacon_notif;
}
static void iwl4965_post_scan(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
if (memcmp(&ctx->staging, &ctx->active, sizeof(ctx->staging)))
iwl_legacy_commit_rxon(priv, ctx);
}
static void iwl4965_post_associate(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct ieee80211_vif *vif = ctx->vif;
struct ieee80211_conf *conf = NULL;
int ret = 0;
if (!vif || !priv->is_open)
return;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
iwl_legacy_scan_cancel_timeout(priv, 200);
conf = iwl_legacy_ieee80211_get_hw_conf(priv->hw);
ctx->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
iwl_legacy_commit_rxon(priv, ctx);
ret = iwl_legacy_send_rxon_timing(priv, ctx);
if (ret)
IWL_WARN(priv, "RXON timing - "
"Attempting to continue.\n");
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
iwl_legacy_set_rxon_ht(priv, &priv->current_ht_config);
if (priv->cfg->ops->hcmd->set_rxon_chain)
priv->cfg->ops->hcmd->set_rxon_chain(priv, ctx);
ctx->staging.assoc_id = cpu_to_le16(vif->bss_conf.aid);
IWL_DEBUG_ASSOC(priv, "assoc id %d beacon interval %d\n",
vif->bss_conf.aid, vif->bss_conf.beacon_int);
if (vif->bss_conf.use_short_preamble)
ctx->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
else
ctx->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
if (ctx->staging.flags & RXON_FLG_BAND_24G_MSK) {
if (vif->bss_conf.use_short_slot)
ctx->staging.flags |= RXON_FLG_SHORT_SLOT_MSK;
else
ctx->staging.flags &= ~RXON_FLG_SHORT_SLOT_MSK;
}
iwl_legacy_commit_rxon(priv, ctx);
IWL_DEBUG_ASSOC(priv, "Associated as %d to: %pM\n",
vif->bss_conf.aid, ctx->active.bssid_addr);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
break;
case NL80211_IFTYPE_ADHOC:
iwl4965_send_beacon_cmd(priv);
break;
default:
IWL_ERR(priv, "%s Should not be called in %d mode\n",
__func__, vif->type);
break;
}
if (priv->chain_noise_data.state == IWL_CHAIN_NOISE_DONE)
iwl_legacy_power_update_mode(priv, false);
iwl4965_chain_noise_reset(priv);
priv->start_calib = 1;
}
static void iwl4965_config_ap(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct ieee80211_vif *vif = ctx->vif;
int ret = 0;
lockdep_assert_held(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (!iwl_legacy_is_associated_ctx(ctx)) {
ctx->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
iwl_legacy_commit_rxon(priv, ctx);
ret = iwl_legacy_send_rxon_timing(priv, ctx);
if (ret)
IWL_WARN(priv, "RXON timing failed - "
"Attempting to continue.\n");
priv->chain_noise_data.active_chains =
priv->hw_params.valid_rx_ant;
iwl_legacy_set_rxon_ht(priv, &priv->current_ht_config);
if (priv->cfg->ops->hcmd->set_rxon_chain)
priv->cfg->ops->hcmd->set_rxon_chain(priv, ctx);
ctx->staging.assoc_id = 0;
if (vif->bss_conf.use_short_preamble)
ctx->staging.flags |=
RXON_FLG_SHORT_PREAMBLE_MSK;
else
ctx->staging.flags &=
~RXON_FLG_SHORT_PREAMBLE_MSK;
if (ctx->staging.flags & RXON_FLG_BAND_24G_MSK) {
if (vif->bss_conf.use_short_slot)
ctx->staging.flags |=
RXON_FLG_SHORT_SLOT_MSK;
else
ctx->staging.flags &=
~RXON_FLG_SHORT_SLOT_MSK;
}
iwl4965_send_beacon_cmd(priv);
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
iwl_legacy_commit_rxon(priv, ctx);
}
iwl4965_send_beacon_cmd(priv);
}
