static inline u32 DTS_DIODE_GET_VREFS_ID(u32 flags)
{
return (flags & DTS_DIODE_REG_FLAGS_VREFS_ID) >>
DTS_DIODE_REG_FLAGS_VREFS_ID_POS;
}
static s16 iwl_mvm_dts_get_volt_band_gap(struct iwl_mvm *mvm)
{
struct iwl_nvm_section calib_sec;
const __le16 *calib;
u16 vbg;
calib_sec = mvm->nvm_sections[NVM_SECTION_TYPE_CALIBRATION];
calib = (__le16 *)calib_sec.data;
vbg = le16_to_cpu(calib[OTP_WP_DTS_VBG]);
if (vbg < MEAS_VBG_MIN_VAL || vbg > MEAS_VBG_MAX_VAL)
vbg = MEAS_VBG_DEFAULT_VAL;
return vbg;
}
static u16 iwl_mvm_dts_get_ptat_deviation_offset(struct iwl_mvm *mvm)
{
const u8 *calib;
u8 ptat, pa1, pa2, median;
calib = mvm->nvm_sections[NVM_SECTION_TYPE_CALIBRATION].data;
ptat = calib[OTP_DTS_DIODE_DEVIATION];
pa1 = calib[OTP_DTS_DIODE_DEVIATION + 1];
pa2 = calib[OTP_DTS_DIODE_DEVIATION + 2];
if (ptat > pa1) {
if (ptat > pa2)
median = (pa1 > pa2) ? pa1 : pa2;
else
median = ptat;
} else {
if (pa1 > pa2)
median = (ptat > pa2) ? ptat : pa2;
else
median = pa1;
}
return ptat - median;
}
static u8 iwl_mvm_dts_calibrate_ptat_deviation(struct iwl_mvm *mvm, u8 value)
{
s16 new_val = value - iwl_mvm_dts_get_ptat_deviation_offset(mvm);
if (new_val > PTAT_DIGITAL_VALUE_MAX_VALUE)
new_val = PTAT_DIGITAL_VALUE_MAX_VALUE;
else if (new_val < PTAT_DIGITAL_VALUE_MIN_VALUE)
new_val = PTAT_DIGITAL_VALUE_MIN_VALUE;
return new_val;
}
static bool dts_get_adjacent_vrefs(struct iwl_mvm *mvm,
union dts_diode_results *avg_ptat)
{
u8 vrefs_results[DTS_VREFS_NUM];
u8 low_vref_index = 0, flags;
u32 reg;
reg = iwl_read_prph(mvm->trans, DTSC_VREF_AVG);
memcpy(vrefs_results, &reg, sizeof(reg));
reg = iwl_read_prph(mvm->trans, DTSC_VREF5_AVG);
vrefs_results[4] = reg & 0xff;
if (avg_ptat->bits.digital_value < vrefs_results[0] ||
avg_ptat->bits.digital_value > vrefs_results[4])
return false;
if (avg_ptat->bits.digital_value > vrefs_results[3])
low_vref_index = 3;
else if (avg_ptat->bits.digital_value > vrefs_results[2])
low_vref_index = 2;
else if (avg_ptat->bits.digital_value > vrefs_results[1])
low_vref_index = 1;
avg_ptat->bits.vref_low = vrefs_results[low_vref_index];
avg_ptat->bits.vref_high = vrefs_results[low_vref_index + 1];
flags = avg_ptat->bits.flags;
avg_ptat->bits.flags =
(flags & ~DTS_DIODE_REG_FLAGS_VREFS_ID) |
(low_vref_index & DTS_DIODE_REG_FLAGS_VREFS_ID);
return true;
}
static bool dts_read_ptat_avg_results(struct iwl_mvm *mvm,
union dts_diode_results *avg_ptat)
{
u32 reg;
u8 tmp;
reg = iwl_read_prph(mvm->trans, DTSC_PTAT_AVG);
reg &= DTS_DIODE_REG_DIG_VAL | DTS_DIODE_REG_PASS_ONCE;
avg_ptat->reg_value = reg;
tmp = avg_ptat->bits.digital_value;
tmp = iwl_mvm_dts_calibrate_ptat_deviation(mvm, tmp);
avg_ptat->bits.digital_value = tmp;
return dts_get_adjacent_vrefs(mvm, avg_ptat) &&
DTS_DIODE_VALID(avg_ptat->bits.flags);
}
static s32 calculate_nic_temperature(union dts_diode_results avg_ptat,
u16 volt_band_gap)
{
u32 tmp_result;
u8 vrefs_diff;
static const u16 calc_lut[CALC_LUT_SIZE] = {
2168, 2118, 2071, 2026, 1983, 1942, 1902, 1864, 1828,
};
vrefs_diff = avg_ptat.bits.vref_high - avg_ptat.bits.vref_low;
if (vrefs_diff < CALC_VREFS_MIN_DIFF ||
vrefs_diff > CALC_VREFS_MAX_DIFF)
return TEMPERATURE_ERROR;
tmp_result =
vrefs_diff * (DTS_DIODE_GET_VREFS_ID(avg_ptat.bits.flags) + 9);
tmp_result += avg_ptat.bits.digital_value;
tmp_result -= avg_ptat.bits.vref_high;
tmp_result *= calc_lut[vrefs_diff - CALC_LUT_INDEX_OFFSET];
tmp_result *= volt_band_gap;
tmp_result = tmp_result >> CALC_TEMPERATURE_RESULT_SHIFT_OFFSET;
return (s16)tmp_result - 240;
}
static s32 check_nic_temperature(struct iwl_mvm *mvm)
{
u16 volt_band_gap;
union dts_diode_results avg_ptat;
volt_band_gap = iwl_mvm_dts_get_volt_band_gap(mvm);
iwl_write_prph(mvm->trans, SHR_MISC_WFM_DTS_EN, 0);
iwl_write_prph(mvm->trans, SHR_MISC_WFM_DTS_EN, 1);
iwl_write_prph(mvm->trans, DTSC_CFG_MODE,
DTSC_CFG_MODE_PERIODIC);
msleep(100);
if (!dts_read_ptat_avg_results(mvm, &avg_ptat))
return TEMPERATURE_ERROR;
iwl_write_prph(mvm->trans, SHR_MISC_WFM_DTS_EN, 0);
return calculate_nic_temperature(avg_ptat, volt_band_gap);
}
static void iwl_mvm_enter_ctkill(struct iwl_mvm *mvm)
{
u32 duration = mvm->thermal_throttle.params->ct_kill_duration;
IWL_ERR(mvm, "Enter CT Kill\n");
iwl_mvm_set_hw_ctkill_state(mvm, true);
schedule_delayed_work(&mvm->thermal_throttle.ct_kill_exit,
round_jiffies_relative(duration * HZ));
}
static void iwl_mvm_exit_ctkill(struct iwl_mvm *mvm)
{
IWL_ERR(mvm, "Exit CT Kill\n");
iwl_mvm_set_hw_ctkill_state(mvm, false);
}
static void check_exit_ctkill(struct work_struct *work)
{
struct iwl_mvm_tt_mgmt *tt;
struct iwl_mvm *mvm;
u32 duration;
s32 temp;
tt = container_of(work, struct iwl_mvm_tt_mgmt, ct_kill_exit.work);
mvm = container_of(tt, struct iwl_mvm, thermal_throttle);
duration = tt->params->ct_kill_duration;
iwl_trans_start_hw(mvm->trans);
temp = check_nic_temperature(mvm);
iwl_trans_stop_device(mvm->trans);
if (temp < MIN_TEMPERATURE || temp > MAX_TEMPERATURE) {
IWL_DEBUG_TEMP(mvm, "Failed to measure NIC temperature\n");
goto reschedule;
}
IWL_DEBUG_TEMP(mvm, "NIC temperature: %d\n", temp);
if (temp <= tt->params->ct_kill_exit) {
iwl_mvm_exit_ctkill(mvm);
return;
}
reschedule:
schedule_delayed_work(&mvm->thermal_throttle.ct_kill_exit,
round_jiffies(duration * HZ));
}
static void iwl_mvm_tt_smps_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = _data;
enum ieee80211_smps_mode smps_mode;
lockdep_assert_held(&mvm->mutex);
if (mvm->thermal_throttle.dynamic_smps)
smps_mode = IEEE80211_SMPS_DYNAMIC;
else
smps_mode = IEEE80211_SMPS_AUTOMATIC;
if (vif->type != NL80211_IFTYPE_STATION)
return;
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_TT, smps_mode);
}
static void iwl_mvm_tt_tx_protection(struct iwl_mvm *mvm, bool enable)
{
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
int i, err;
for (i = 0; i < IWL_MVM_STATION_COUNT; i++) {
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[i],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta))
continue;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (enable == mvmsta->tt_tx_protection)
continue;
err = iwl_mvm_tx_protection(mvm, mvmsta, enable);
if (err) {
IWL_ERR(mvm, "Failed to %s Tx protection\n",
enable ? "enable" : "disable");
} else {
IWL_DEBUG_TEMP(mvm, "%s Tx protection\n",
enable ? "Enable" : "Disable");
mvmsta->tt_tx_protection = enable;
}
}
}
void iwl_mvm_tt_tx_backoff(struct iwl_mvm *mvm, u32 backoff)
{
struct iwl_host_cmd cmd = {
.id = REPLY_THERMAL_MNG_BACKOFF,
.len = { sizeof(u32), },
.data = { &backoff, },
};
backoff = max(backoff, mvm->thermal_throttle.min_backoff);
if (iwl_mvm_send_cmd(mvm, &cmd) == 0) {
IWL_DEBUG_TEMP(mvm, "Set Thermal Tx backoff to: %u\n",
backoff);
mvm->thermal_throttle.tx_backoff = backoff;
} else {
IWL_ERR(mvm, "Failed to change Thermal Tx backoff\n");
}
}
void iwl_mvm_tt_handler(struct iwl_mvm *mvm)
{
const struct iwl_tt_params *params = mvm->thermal_throttle.params;
struct iwl_mvm_tt_mgmt *tt = &mvm->thermal_throttle;
s32 temperature = mvm->temperature;
bool throttle_enable = false;
int i;
u32 tx_backoff;
IWL_DEBUG_TEMP(mvm, "NIC temperature: %d\n", mvm->temperature);
if (params->support_ct_kill && temperature >= params->ct_kill_entry) {
iwl_mvm_enter_ctkill(mvm);
return;
}
if (params->support_dynamic_smps) {
if (!tt->dynamic_smps &&
temperature >= params->dynamic_smps_entry) {
IWL_DEBUG_TEMP(mvm, "Enable dynamic SMPS\n");
tt->dynamic_smps = true;
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_tt_smps_iterator, mvm);
throttle_enable = true;
} else if (tt->dynamic_smps &&
temperature <= params->dynamic_smps_exit) {
IWL_DEBUG_TEMP(mvm, "Disable dynamic SMPS\n");
tt->dynamic_smps = false;
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_tt_smps_iterator, mvm);
}
}
if (params->support_tx_protection) {
if (temperature >= params->tx_protection_entry) {
iwl_mvm_tt_tx_protection(mvm, true);
throttle_enable = true;
} else if (temperature <= params->tx_protection_exit) {
iwl_mvm_tt_tx_protection(mvm, false);
}
}
if (params->support_tx_backoff) {
tx_backoff = tt->min_backoff;
for (i = 0; i < TT_TX_BACKOFF_SIZE; i++) {
if (temperature < params->tx_backoff[i].temperature)
break;
tx_backoff = max(tt->min_backoff,
params->tx_backoff[i].backoff);
}
if (tx_backoff != tt->min_backoff)
throttle_enable = true;
if (tt->tx_backoff != tx_backoff)
iwl_mvm_tt_tx_backoff(mvm, tx_backoff);
}
if (!tt->throttle && throttle_enable) {
IWL_WARN(mvm,
"Due to high temperature thermal throttling initiated\n");
tt->throttle = true;
} else if (tt->throttle && !tt->dynamic_smps &&
tt->tx_backoff == tt->min_backoff &&
temperature <= params->tx_protection_exit) {
IWL_WARN(mvm,
"Temperature is back to normal thermal throttling stopped\n");
tt->throttle = false;
}
}
void iwl_mvm_tt_initialize(struct iwl_mvm *mvm, u32 min_backoff)
{
struct iwl_mvm_tt_mgmt *tt = &mvm->thermal_throttle;
IWL_DEBUG_TEMP(mvm, "Initialize Thermal Throttling\n");
if (mvm->cfg->high_temp)
tt->params = &iwl7000_high_temp_tt_params;
else
tt->params = &iwl7000_tt_params;
tt->throttle = false;
tt->min_backoff = min_backoff;
INIT_DELAYED_WORK(&tt->ct_kill_exit, check_exit_ctkill);
}
void iwl_mvm_tt_exit(struct iwl_mvm *mvm)
{
cancel_delayed_work_sync(&mvm->thermal_throttle.ct_kill_exit);
IWL_DEBUG_TEMP(mvm, "Exit Thermal Throttling\n");
}
