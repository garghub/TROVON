static void iwl_mvm_enter_ctkill(struct iwl_mvm *mvm)
{
struct iwl_mvm_tt_mgmt *tt = &mvm->thermal_throttle;
u32 duration = tt->params.ct_kill_duration;
if (test_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status))
return;
IWL_ERR(mvm, "Enter CT Kill\n");
iwl_mvm_set_hw_ctkill_state(mvm, true);
if (!iwl_mvm_is_tt_in_fw(mvm)) {
tt->throttle = false;
tt->dynamic_smps = false;
}
if (!mvm->temperature_test)
schedule_delayed_work(&tt->ct_kill_exit,
round_jiffies_relative(duration * HZ));
}
static void iwl_mvm_exit_ctkill(struct iwl_mvm *mvm)
{
if (!test_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status))
return;
IWL_ERR(mvm, "Exit CT Kill\n");
iwl_mvm_set_hw_ctkill_state(mvm, false);
}
void iwl_mvm_tt_temp_changed(struct iwl_mvm *mvm, u32 temp)
{
if (mvm->temperature_test)
return;
if (mvm->temperature == temp)
return;
mvm->temperature = temp;
iwl_mvm_tt_handler(mvm);
}
static int iwl_mvm_temp_notif_parse(struct iwl_mvm *mvm,
struct iwl_rx_packet *pkt)
{
struct iwl_dts_measurement_notif_v1 *notif_v1;
int len = iwl_rx_packet_payload_len(pkt);
int temp;
if (WARN_ON_ONCE(len < sizeof(*notif_v1))) {
IWL_ERR(mvm, "Invalid DTS_MEASUREMENT_NOTIFICATION\n");
return -EINVAL;
}
notif_v1 = (void *)pkt->data;
temp = le32_to_cpu(notif_v1->temp);
if (WARN_ON_ONCE(temp < 0))
temp = 0;
IWL_DEBUG_TEMP(mvm, "DTS_MEASUREMENT_NOTIFICATION - %d\n", temp);
return temp;
}
static bool iwl_mvm_temp_notif_wait(struct iwl_notif_wait_data *notif_wait,
struct iwl_rx_packet *pkt, void *data)
{
struct iwl_mvm *mvm =
container_of(notif_wait, struct iwl_mvm, notif_wait);
int *temp = data;
int ret;
ret = iwl_mvm_temp_notif_parse(mvm, pkt);
if (ret < 0)
return true;
*temp = ret;
return true;
}
void iwl_mvm_temp_notif(struct iwl_mvm *mvm, struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_dts_measurement_notif_v2 *notif_v2;
int len = iwl_rx_packet_payload_len(pkt);
int temp;
u32 ths_crossed;
if (test_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status))
return;
temp = iwl_mvm_temp_notif_parse(mvm, pkt);
if (!iwl_mvm_is_tt_in_fw(mvm)) {
if (temp >= 0)
iwl_mvm_tt_temp_changed(mvm, temp);
return;
}
if (WARN_ON_ONCE(len < sizeof(*notif_v2))) {
IWL_ERR(mvm, "Invalid DTS_MEASUREMENT_NOTIFICATION\n");
return;
}
notif_v2 = (void *)pkt->data;
ths_crossed = le32_to_cpu(notif_v2->threshold_idx);
if (ths_crossed == 0xFF)
return;
IWL_DEBUG_TEMP(mvm, "Temp = %d Threshold crossed = %d\n",
temp, ths_crossed);
#ifdef CONFIG_THERMAL
if (WARN_ON(ths_crossed >= IWL_MAX_DTS_TRIPS))
return;
if (mvm->tz_device.tzone) {
struct iwl_mvm_thermal_device *tz_dev = &mvm->tz_device;
thermal_notify_framework(tz_dev->tzone,
tz_dev->fw_trips_index[ths_crossed]);
}
#endif
}
void iwl_mvm_ct_kill_notif(struct iwl_mvm *mvm, struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct ct_kill_notif *notif;
int len = iwl_rx_packet_payload_len(pkt);
if (WARN_ON_ONCE(len != sizeof(*notif))) {
IWL_ERR(mvm, "Invalid CT_KILL_NOTIFICATION\n");
return;
}
notif = (struct ct_kill_notif *)pkt->data;
IWL_DEBUG_TEMP(mvm, "CT Kill notification temperature = %d\n",
notif->temperature);
iwl_mvm_enter_ctkill(mvm);
}
static int iwl_mvm_get_temp_cmd(struct iwl_mvm *mvm)
{
struct iwl_dts_measurement_cmd cmd = {
.flags = cpu_to_le32(DTS_TRIGGER_CMD_FLAGS_TEMP),
};
struct iwl_ext_dts_measurement_cmd extcmd = {
.control_mode = cpu_to_le32(DTS_AUTOMATIC),
};
u32 cmdid;
cmdid = iwl_cmd_id(CMD_DTS_MEASUREMENT_TRIGGER_WIDE,
PHY_OPS_GROUP, 0);
if (!fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_EXTENDED_DTS_MEASURE))
return iwl_mvm_send_cmd_pdu(mvm, cmdid, 0, sizeof(cmd), &cmd);
return iwl_mvm_send_cmd_pdu(mvm, cmdid, 0, sizeof(extcmd), &extcmd);
}
int iwl_mvm_get_temp(struct iwl_mvm *mvm, s32 *temp)
{
struct iwl_notification_wait wait_temp_notif;
static u16 temp_notif[] = { WIDE_ID(PHY_OPS_GROUP,
DTS_MEASUREMENT_NOTIF_WIDE) };
int ret;
lockdep_assert_held(&mvm->mutex);
iwl_init_notification_wait(&mvm->notif_wait, &wait_temp_notif,
temp_notif, ARRAY_SIZE(temp_notif),
iwl_mvm_temp_notif_wait, temp);
ret = iwl_mvm_get_temp_cmd(mvm);
if (ret) {
IWL_ERR(mvm, "Failed to get the temperature (err=%d)\n", ret);
iwl_remove_notification(&mvm->notif_wait, &wait_temp_notif);
return ret;
}
ret = iwl_wait_notification(&mvm->notif_wait, &wait_temp_notif,
IWL_MVM_TEMP_NOTIF_WAIT_TIMEOUT);
if (ret)
IWL_ERR(mvm, "Getting the temperature timed out\n");
return ret;
}
static void check_exit_ctkill(struct work_struct *work)
{
struct iwl_mvm_tt_mgmt *tt;
struct iwl_mvm *mvm;
u32 duration;
s32 temp;
int ret;
tt = container_of(work, struct iwl_mvm_tt_mgmt, ct_kill_exit.work);
mvm = container_of(tt, struct iwl_mvm, thermal_throttle);
if (iwl_mvm_is_tt_in_fw(mvm)) {
iwl_mvm_exit_ctkill(mvm);
return;
}
duration = tt->params.ct_kill_duration;
mutex_lock(&mvm->mutex);
if (__iwl_mvm_mac_start(mvm))
goto reschedule;
if (iwl_mvm_ref_sync(mvm, IWL_MVM_REF_CHECK_CTKILL)) {
__iwl_mvm_mac_stop(mvm);
goto reschedule;
}
ret = iwl_mvm_get_temp(mvm, &temp);
iwl_mvm_unref(mvm, IWL_MVM_REF_CHECK_CTKILL);
__iwl_mvm_mac_stop(mvm);
if (ret)
goto reschedule;
IWL_DEBUG_TEMP(mvm, "NIC temperature: %d\n", temp);
if (temp <= tt->params.ct_kill_exit) {
mutex_unlock(&mvm->mutex);
iwl_mvm_exit_ctkill(mvm);
return;
}
reschedule:
mutex_unlock(&mvm->mutex);
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
struct iwl_mvm_sta *mvmsta;
int i, err;
for (i = 0; i < ARRAY_SIZE(mvm->fw_id_to_mac_id); i++) {
mvmsta = iwl_mvm_sta_from_staid_protected(mvm, i);
if (!mvmsta)
continue;
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
struct iwl_tt_params *params = &mvm->thermal_throttle.params;
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
if (params->support_ct_kill &&
temperature <= params->ct_kill_exit) {
iwl_mvm_exit_ctkill(mvm);
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
int iwl_mvm_ctdp_command(struct iwl_mvm *mvm, u32 op, u32 state)
{
struct iwl_mvm_ctdp_cmd cmd = {
.operation = cpu_to_le32(op),
.budget = cpu_to_le32(iwl_mvm_cdev_budgets[state]),
.window_size = 0,
};
int ret;
u32 status;
lockdep_assert_held(&mvm->mutex);
ret = iwl_mvm_send_cmd_pdu_status(mvm, WIDE_ID(PHY_OPS_GROUP,
CTDP_CONFIG_CMD),
sizeof(cmd), &cmd, &status);
if (ret) {
IWL_ERR(mvm, "cTDP command failed (err=%d)\n", ret);
return ret;
}
switch (op) {
case CTDP_CMD_OPERATION_START:
#ifdef CONFIG_THERMAL
mvm->cooling_dev.cur_state = state;
#endif
break;
case CTDP_CMD_OPERATION_REPORT:
IWL_DEBUG_TEMP(mvm, "cTDP avg energy in mWatt = %d\n", status);
return status;
case CTDP_CMD_OPERATION_STOP:
IWL_DEBUG_TEMP(mvm, "cTDP stopped successfully\n");
break;
}
return 0;
}
static int compare_temps(const void *a, const void *b)
{
return ((s16)le16_to_cpu(*(__le16 *)a) -
(s16)le16_to_cpu(*(__le16 *)b));
}
int iwl_mvm_send_temp_report_ths_cmd(struct iwl_mvm *mvm)
{
struct temp_report_ths_cmd cmd = {0};
int ret, i, j, idx = 0;
lockdep_assert_held(&mvm->mutex);
if (!mvm->tz_device.tzone)
return -EINVAL;
for (i = 0; i < IWL_MAX_DTS_TRIPS; i++) {
if (mvm->tz_device.temp_trips[i] != S16_MIN) {
cmd.thresholds[idx++] =
cpu_to_le16(mvm->tz_device.temp_trips[i]);
}
}
cmd.num_temps = cpu_to_le32(idx);
if (!idx)
goto send;
sort(cmd.thresholds, idx, sizeof(s16), compare_temps, NULL);
for (i = 0; i < idx; i++) {
for (j = 0; j < IWL_MAX_DTS_TRIPS; j++) {
if (le16_to_cpu(cmd.thresholds[i]) ==
mvm->tz_device.temp_trips[j])
mvm->tz_device.fw_trips_index[i] = j;
}
}
send:
ret = iwl_mvm_send_cmd_pdu(mvm, WIDE_ID(PHY_OPS_GROUP,
TEMP_REPORTING_THRESHOLDS_CMD),
0, sizeof(cmd), &cmd);
if (ret)
IWL_ERR(mvm, "TEMP_REPORT_THS_CMD command failed (err=%d)\n",
ret);
return ret;
}
static int iwl_mvm_tzone_get_temp(struct thermal_zone_device *device,
int *temperature)
{
struct iwl_mvm *mvm = (struct iwl_mvm *)device->devdata;
int ret;
int temp;
mutex_lock(&mvm->mutex);
if (!iwl_mvm_firmware_running(mvm) ||
mvm->cur_ucode != IWL_UCODE_REGULAR) {
ret = -EIO;
goto out;
}
ret = iwl_mvm_get_temp(mvm, &temp);
if (ret)
goto out;
*temperature = temp * 1000;
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_tzone_get_trip_temp(struct thermal_zone_device *device,
int trip, int *temp)
{
struct iwl_mvm *mvm = (struct iwl_mvm *)device->devdata;
if (trip < 0 || trip >= IWL_MAX_DTS_TRIPS)
return -EINVAL;
*temp = mvm->tz_device.temp_trips[trip] * 1000;
return 0;
}
static int iwl_mvm_tzone_get_trip_type(struct thermal_zone_device *device,
int trip, enum thermal_trip_type *type)
{
if (trip < 0 || trip >= IWL_MAX_DTS_TRIPS)
return -EINVAL;
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
static int iwl_mvm_tzone_set_trip_temp(struct thermal_zone_device *device,
int trip, int temp)
{
struct iwl_mvm *mvm = (struct iwl_mvm *)device->devdata;
struct iwl_mvm_thermal_device *tzone;
int i, ret;
s16 temperature;
mutex_lock(&mvm->mutex);
if (!iwl_mvm_firmware_running(mvm) ||
mvm->cur_ucode != IWL_UCODE_REGULAR) {
ret = -EIO;
goto out;
}
if (trip < 0 || trip >= IWL_MAX_DTS_TRIPS) {
ret = -EINVAL;
goto out;
}
if ((temp / 1000) > S16_MAX) {
ret = -EINVAL;
goto out;
}
temperature = (s16)(temp / 1000);
tzone = &mvm->tz_device;
if (!tzone) {
ret = -EIO;
goto out;
}
if (tzone->temp_trips[trip] == temperature) {
ret = 0;
goto out;
}
for (i = 0; i < IWL_MAX_DTS_TRIPS; i++) {
if (tzone->temp_trips[i] == temperature) {
ret = -EINVAL;
goto out;
}
}
tzone->temp_trips[trip] = temperature;
ret = iwl_mvm_send_temp_report_ths_cmd(mvm);
out:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_thermal_zone_register(struct iwl_mvm *mvm)
{
int i;
char name[] = "iwlwifi";
if (!iwl_mvm_is_tt_in_fw(mvm)) {
mvm->tz_device.tzone = NULL;
return;
}
BUILD_BUG_ON(ARRAY_SIZE(name) >= THERMAL_NAME_LENGTH);
mvm->tz_device.tzone = thermal_zone_device_register(name,
IWL_MAX_DTS_TRIPS,
IWL_WRITABLE_TRIPS_MSK,
mvm, &tzone_ops,
NULL, 0, 0);
if (IS_ERR(mvm->tz_device.tzone)) {
IWL_DEBUG_TEMP(mvm,
"Failed to register to thermal zone (err = %ld)\n",
PTR_ERR(mvm->tz_device.tzone));
mvm->tz_device.tzone = NULL;
return;
}
for (i = 0 ; i < IWL_MAX_DTS_TRIPS; i++)
mvm->tz_device.temp_trips[i] = S16_MIN;
}
static int iwl_mvm_tcool_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
*state = ARRAY_SIZE(iwl_mvm_cdev_budgets) - 1;
return 0;
}
static int iwl_mvm_tcool_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct iwl_mvm *mvm = (struct iwl_mvm *)(cdev->devdata);
*state = mvm->cooling_dev.cur_state;
return 0;
}
static int iwl_mvm_tcool_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long new_state)
{
struct iwl_mvm *mvm = (struct iwl_mvm *)(cdev->devdata);
int ret;
mutex_lock(&mvm->mutex);
if (!iwl_mvm_firmware_running(mvm) ||
mvm->cur_ucode != IWL_UCODE_REGULAR) {
ret = -EIO;
goto unlock;
}
if (new_state >= ARRAY_SIZE(iwl_mvm_cdev_budgets)) {
ret = -EINVAL;
goto unlock;
}
ret = iwl_mvm_ctdp_command(mvm, CTDP_CMD_OPERATION_START,
new_state);
unlock:
mutex_unlock(&mvm->mutex);
return ret;
}
static void iwl_mvm_cooling_device_register(struct iwl_mvm *mvm)
{
char name[] = "iwlwifi";
if (!iwl_mvm_is_ctdp_supported(mvm))
return;
BUILD_BUG_ON(ARRAY_SIZE(name) >= THERMAL_NAME_LENGTH);
mvm->cooling_dev.cdev =
thermal_cooling_device_register(name,
mvm,
&tcooling_ops);
if (IS_ERR(mvm->cooling_dev.cdev)) {
IWL_DEBUG_TEMP(mvm,
"Failed to register to cooling device (err = %ld)\n",
PTR_ERR(mvm->cooling_dev.cdev));
mvm->cooling_dev.cdev = NULL;
return;
}
}
static void iwl_mvm_thermal_zone_unregister(struct iwl_mvm *mvm)
{
if (!iwl_mvm_is_tt_in_fw(mvm) || !mvm->tz_device.tzone)
return;
IWL_DEBUG_TEMP(mvm, "Thermal zone device unregister\n");
if (mvm->tz_device.tzone) {
thermal_zone_device_unregister(mvm->tz_device.tzone);
mvm->tz_device.tzone = NULL;
}
}
static void iwl_mvm_cooling_device_unregister(struct iwl_mvm *mvm)
{
if (!iwl_mvm_is_ctdp_supported(mvm) || !mvm->cooling_dev.cdev)
return;
IWL_DEBUG_TEMP(mvm, "Cooling device unregister\n");
if (mvm->cooling_dev.cdev) {
thermal_cooling_device_unregister(mvm->cooling_dev.cdev);
mvm->cooling_dev.cdev = NULL;
}
}
void iwl_mvm_thermal_initialize(struct iwl_mvm *mvm, u32 min_backoff)
{
struct iwl_mvm_tt_mgmt *tt = &mvm->thermal_throttle;
IWL_DEBUG_TEMP(mvm, "Initialize Thermal Throttling\n");
if (mvm->cfg->thermal_params)
tt->params = *mvm->cfg->thermal_params;
else
tt->params = iwl_mvm_default_tt_params;
tt->throttle = false;
tt->dynamic_smps = false;
tt->min_backoff = min_backoff;
INIT_DELAYED_WORK(&tt->ct_kill_exit, check_exit_ctkill);
#ifdef CONFIG_THERMAL
iwl_mvm_cooling_device_register(mvm);
iwl_mvm_thermal_zone_register(mvm);
#endif
mvm->init_status |= IWL_MVM_INIT_STATUS_THERMAL_INIT_COMPLETE;
}
void iwl_mvm_thermal_exit(struct iwl_mvm *mvm)
{
if (!(mvm->init_status & IWL_MVM_INIT_STATUS_THERMAL_INIT_COMPLETE))
return;
cancel_delayed_work_sync(&mvm->thermal_throttle.ct_kill_exit);
IWL_DEBUG_TEMP(mvm, "Exit Thermal Throttling\n");
#ifdef CONFIG_THERMAL
iwl_mvm_cooling_device_unregister(mvm);
iwl_mvm_thermal_zone_unregister(mvm);
#endif
mvm->init_status &= ~IWL_MVM_INIT_STATUS_THERMAL_INIT_COMPLETE;
}
