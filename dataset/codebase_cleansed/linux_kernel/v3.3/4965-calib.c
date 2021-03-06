void
il4965_calib_free_results(struct il_priv *il)
{
int i;
for (i = 0; i < IL_CALIB_MAX; i++) {
kfree(il->calib_results[i].buf);
il->calib_results[i].buf = NULL;
il->calib_results[i].buf_len = 0;
}
}
static int
il4965_sens_energy_cck(struct il_priv *il, u32 norm_fa, u32 rx_enable_time,
struct stats_general_data *rx_info)
{
u32 max_nrg_cck = 0;
int i = 0;
u8 max_silence_rssi = 0;
u32 silence_ref = 0;
u8 silence_rssi_a = 0;
u8 silence_rssi_b = 0;
u8 silence_rssi_c = 0;
u32 val;
u32 false_alarms = norm_fa * 200 * 1024;
u32 max_false_alarms = MAX_FA_CCK * rx_enable_time;
u32 min_false_alarms = MIN_FA_CCK * rx_enable_time;
struct il_sensitivity_data *data = NULL;
const struct il_sensitivity_ranges *ranges = il->hw_params.sens;
data = &(il->sensitivity_data);
data->nrg_auto_corr_silence_diff = 0;
silence_rssi_a =
(u8) ((rx_info->beacon_silence_rssi_a & ALL_BAND_FILTER) >> 8);
silence_rssi_b =
(u8) ((rx_info->beacon_silence_rssi_b & ALL_BAND_FILTER) >> 8);
silence_rssi_c =
(u8) ((rx_info->beacon_silence_rssi_c & ALL_BAND_FILTER) >> 8);
val = max(silence_rssi_b, silence_rssi_c);
max_silence_rssi = max(silence_rssi_a, (u8) val);
data->nrg_silence_rssi[data->nrg_silence_idx] = max_silence_rssi;
data->nrg_silence_idx++;
if (data->nrg_silence_idx >= NRG_NUM_PREV_STAT_L)
data->nrg_silence_idx = 0;
for (i = 0; i < NRG_NUM_PREV_STAT_L; i++) {
val = data->nrg_silence_rssi[i];
silence_ref = max(silence_ref, val);
}
D_CALIB("silence a %u, b %u, c %u, 20-bcn max %u\n", silence_rssi_a,
silence_rssi_b, silence_rssi_c, silence_ref);
i = data->nrg_energy_idx;
val = min(rx_info->beacon_energy_b, rx_info->beacon_energy_c);
data->nrg_value[i] = min(rx_info->beacon_energy_a, val);
data->nrg_energy_idx++;
if (data->nrg_energy_idx >= 10)
data->nrg_energy_idx = 0;
max_nrg_cck = data->nrg_value[0];
for (i = 1; i < 10; i++)
max_nrg_cck = (u32) max(max_nrg_cck, (data->nrg_value[i]));
max_nrg_cck += 6;
D_CALIB("rx energy a %u, b %u, c %u, 10-bcn max/min %u\n",
rx_info->beacon_energy_a, rx_info->beacon_energy_b,
rx_info->beacon_energy_c, max_nrg_cck - 6);
if (false_alarms < min_false_alarms)
data->num_in_cck_no_fa++;
else
data->num_in_cck_no_fa = 0;
D_CALIB("consecutive bcns with few false alarms = %u\n",
data->num_in_cck_no_fa);
if (false_alarms > max_false_alarms &&
data->auto_corr_cck > AUTO_CORR_MAX_TH_CCK) {
D_CALIB("norm FA %u > max FA %u\n", false_alarms,
max_false_alarms);
D_CALIB("... reducing sensitivity\n");
data->nrg_curr_state = IL_FA_TOO_MANY;
data->nrg_silence_ref = silence_ref;
data->nrg_th_cck = data->nrg_th_cck - NRG_STEP_CCK;
} else if (false_alarms < min_false_alarms) {
data->nrg_curr_state = IL_FA_TOO_FEW;
data->nrg_auto_corr_silence_diff =
(s32) data->nrg_silence_ref - (s32) silence_ref;
D_CALIB("norm FA %u < min FA %u, silence diff %d\n",
false_alarms, min_false_alarms,
data->nrg_auto_corr_silence_diff);
if (data->nrg_prev_state != IL_FA_TOO_MANY &&
(data->nrg_auto_corr_silence_diff > NRG_DIFF ||
data->num_in_cck_no_fa > MAX_NUMBER_CCK_NO_FA)) {
D_CALIB("... increasing sensitivity\n");
val = data->nrg_th_cck + NRG_STEP_CCK;
data->nrg_th_cck = min((u32) ranges->min_nrg_cck, val);
} else {
D_CALIB("... but not changing sensitivity\n");
}
} else {
D_CALIB(" FA in safe zone\n");
data->nrg_curr_state = IL_FA_GOOD_RANGE;
data->nrg_silence_ref = silence_ref;
if (IL_FA_TOO_MANY == data->nrg_prev_state) {
D_CALIB("... increasing margin\n");
if (data->nrg_th_cck > (max_nrg_cck + NRG_MARGIN))
data->nrg_th_cck -= NRG_MARGIN;
else
data->nrg_th_cck = max_nrg_cck;
}
}
data->nrg_th_cck = max(max_nrg_cck, data->nrg_th_cck);
D_CALIB("new nrg_th_cck %u\n", data->nrg_th_cck);
data->nrg_prev_state = data->nrg_curr_state;
if (false_alarms > min_false_alarms) {
if (data->auto_corr_cck < AUTO_CORR_MAX_TH_CCK)
data->auto_corr_cck = AUTO_CORR_MAX_TH_CCK + 1;
else {
val = data->auto_corr_cck + AUTO_CORR_STEP_CCK;
data->auto_corr_cck =
min((u32) ranges->auto_corr_max_cck, val);
}
val = data->auto_corr_cck_mrc + AUTO_CORR_STEP_CCK;
data->auto_corr_cck_mrc =
min((u32) ranges->auto_corr_max_cck_mrc, val);
} else if (false_alarms < min_false_alarms &&
(data->nrg_auto_corr_silence_diff > NRG_DIFF ||
data->num_in_cck_no_fa > MAX_NUMBER_CCK_NO_FA)) {
val = data->auto_corr_cck - AUTO_CORR_STEP_CCK;
data->auto_corr_cck = max((u32) ranges->auto_corr_min_cck, val);
val = data->auto_corr_cck_mrc - AUTO_CORR_STEP_CCK;
data->auto_corr_cck_mrc =
max((u32) ranges->auto_corr_min_cck_mrc, val);
}
return 0;
}
static int
il4965_sens_auto_corr_ofdm(struct il_priv *il, u32 norm_fa, u32 rx_enable_time)
{
u32 val;
u32 false_alarms = norm_fa * 200 * 1024;
u32 max_false_alarms = MAX_FA_OFDM * rx_enable_time;
u32 min_false_alarms = MIN_FA_OFDM * rx_enable_time;
struct il_sensitivity_data *data = NULL;
const struct il_sensitivity_ranges *ranges = il->hw_params.sens;
data = &(il->sensitivity_data);
if (false_alarms > max_false_alarms) {
D_CALIB("norm FA %u > max FA %u)\n", false_alarms,
max_false_alarms);
val = data->auto_corr_ofdm + AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm =
min((u32) ranges->auto_corr_max_ofdm, val);
val = data->auto_corr_ofdm_mrc + AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_mrc =
min((u32) ranges->auto_corr_max_ofdm_mrc, val);
val = data->auto_corr_ofdm_x1 + AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_x1 =
min((u32) ranges->auto_corr_max_ofdm_x1, val);
val = data->auto_corr_ofdm_mrc_x1 + AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_mrc_x1 =
min((u32) ranges->auto_corr_max_ofdm_mrc_x1, val);
}
else if (false_alarms < min_false_alarms) {
D_CALIB("norm FA %u < min FA %u\n", false_alarms,
min_false_alarms);
val = data->auto_corr_ofdm - AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm =
max((u32) ranges->auto_corr_min_ofdm, val);
val = data->auto_corr_ofdm_mrc - AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_mrc =
max((u32) ranges->auto_corr_min_ofdm_mrc, val);
val = data->auto_corr_ofdm_x1 - AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_x1 =
max((u32) ranges->auto_corr_min_ofdm_x1, val);
val = data->auto_corr_ofdm_mrc_x1 - AUTO_CORR_STEP_OFDM;
data->auto_corr_ofdm_mrc_x1 =
max((u32) ranges->auto_corr_min_ofdm_mrc_x1, val);
} else {
D_CALIB("min FA %u < norm FA %u < max FA %u OK\n",
min_false_alarms, false_alarms, max_false_alarms);
}
return 0;
}
static void
il4965_prepare_legacy_sensitivity_tbl(struct il_priv *il,
struct il_sensitivity_data *data,
__le16 *tbl)
{
tbl[HD_AUTO_CORR32_X4_TH_ADD_MIN_IDX] =
cpu_to_le16((u16) data->auto_corr_ofdm);
tbl[HD_AUTO_CORR32_X4_TH_ADD_MIN_MRC_IDX] =
cpu_to_le16((u16) data->auto_corr_ofdm_mrc);
tbl[HD_AUTO_CORR32_X1_TH_ADD_MIN_IDX] =
cpu_to_le16((u16) data->auto_corr_ofdm_x1);
tbl[HD_AUTO_CORR32_X1_TH_ADD_MIN_MRC_IDX] =
cpu_to_le16((u16) data->auto_corr_ofdm_mrc_x1);
tbl[HD_AUTO_CORR40_X4_TH_ADD_MIN_IDX] =
cpu_to_le16((u16) data->auto_corr_cck);
tbl[HD_AUTO_CORR40_X4_TH_ADD_MIN_MRC_IDX] =
cpu_to_le16((u16) data->auto_corr_cck_mrc);
tbl[HD_MIN_ENERGY_CCK_DET_IDX] = cpu_to_le16((u16) data->nrg_th_cck);
tbl[HD_MIN_ENERGY_OFDM_DET_IDX] = cpu_to_le16((u16) data->nrg_th_ofdm);
tbl[HD_BARKER_CORR_TH_ADD_MIN_IDX] =
cpu_to_le16(data->barker_corr_th_min);
tbl[HD_BARKER_CORR_TH_ADD_MIN_MRC_IDX] =
cpu_to_le16(data->barker_corr_th_min_mrc);
tbl[HD_OFDM_ENERGY_TH_IN_IDX] = cpu_to_le16(data->nrg_th_cca);
D_CALIB("ofdm: ac %u mrc %u x1 %u mrc_x1 %u thresh %u\n",
data->auto_corr_ofdm, data->auto_corr_ofdm_mrc,
data->auto_corr_ofdm_x1, data->auto_corr_ofdm_mrc_x1,
data->nrg_th_ofdm);
D_CALIB("cck: ac %u mrc %u thresh %u\n", data->auto_corr_cck,
data->auto_corr_cck_mrc, data->nrg_th_cck);
}
static int
il4965_sensitivity_write(struct il_priv *il)
{
struct il_sensitivity_cmd cmd;
struct il_sensitivity_data *data = NULL;
struct il_host_cmd cmd_out = {
.id = C_SENSITIVITY,
.len = sizeof(struct il_sensitivity_cmd),
.flags = CMD_ASYNC,
.data = &cmd,
};
data = &(il->sensitivity_data);
memset(&cmd, 0, sizeof(cmd));
il4965_prepare_legacy_sensitivity_tbl(il, data, &cmd.table[0]);
cmd.control = C_SENSITIVITY_CONTROL_WORK_TBL;
if (!memcmp
(&cmd.table[0], &(il->sensitivity_tbl[0]),
sizeof(u16) * HD_TBL_SIZE)) {
D_CALIB("No change in C_SENSITIVITY\n");
return 0;
}
memcpy(&(il->sensitivity_tbl[0]), &(cmd.table[0]),
sizeof(u16) * HD_TBL_SIZE);
return il_send_cmd(il, &cmd_out);
}
void
il4965_init_sensitivity(struct il_priv *il)
{
int ret = 0;
int i;
struct il_sensitivity_data *data = NULL;
const struct il_sensitivity_ranges *ranges = il->hw_params.sens;
if (il->disable_sens_cal)
return;
D_CALIB("Start il4965_init_sensitivity\n");
data = &(il->sensitivity_data);
if (ranges == NULL)
return;
memset(data, 0, sizeof(struct il_sensitivity_data));
data->num_in_cck_no_fa = 0;
data->nrg_curr_state = IL_FA_TOO_MANY;
data->nrg_prev_state = IL_FA_TOO_MANY;
data->nrg_silence_ref = 0;
data->nrg_silence_idx = 0;
data->nrg_energy_idx = 0;
for (i = 0; i < 10; i++)
data->nrg_value[i] = 0;
for (i = 0; i < NRG_NUM_PREV_STAT_L; i++)
data->nrg_silence_rssi[i] = 0;
data->auto_corr_ofdm = ranges->auto_corr_min_ofdm;
data->auto_corr_ofdm_mrc = ranges->auto_corr_min_ofdm_mrc;
data->auto_corr_ofdm_x1 = ranges->auto_corr_min_ofdm_x1;
data->auto_corr_ofdm_mrc_x1 = ranges->auto_corr_min_ofdm_mrc_x1;
data->auto_corr_cck = AUTO_CORR_CCK_MIN_VAL_DEF;
data->auto_corr_cck_mrc = ranges->auto_corr_min_cck_mrc;
data->nrg_th_cck = ranges->nrg_th_cck;
data->nrg_th_ofdm = ranges->nrg_th_ofdm;
data->barker_corr_th_min = ranges->barker_corr_th_min;
data->barker_corr_th_min_mrc = ranges->barker_corr_th_min_mrc;
data->nrg_th_cca = ranges->nrg_th_cca;
data->last_bad_plcp_cnt_ofdm = 0;
data->last_fa_cnt_ofdm = 0;
data->last_bad_plcp_cnt_cck = 0;
data->last_fa_cnt_cck = 0;
ret |= il4965_sensitivity_write(il);
D_CALIB("<<return 0x%X\n", ret);
}
void
il4965_sensitivity_calibration(struct il_priv *il, void *resp)
{
u32 rx_enable_time;
u32 fa_cck;
u32 fa_ofdm;
u32 bad_plcp_cck;
u32 bad_plcp_ofdm;
u32 norm_fa_ofdm;
u32 norm_fa_cck;
struct il_sensitivity_data *data = NULL;
struct stats_rx_non_phy *rx_info;
struct stats_rx_phy *ofdm, *cck;
unsigned long flags;
struct stats_general_data statis;
if (il->disable_sens_cal)
return;
data = &(il->sensitivity_data);
if (!il_is_any_associated(il)) {
D_CALIB("<< - not associated\n");
return;
}
spin_lock_irqsave(&il->lock, flags);
rx_info = &(((struct il_notif_stats *)resp)->rx.general);
ofdm = &(((struct il_notif_stats *)resp)->rx.ofdm);
cck = &(((struct il_notif_stats *)resp)->rx.cck);
if (rx_info->interference_data_flag != INTERFERENCE_DATA_AVAILABLE) {
D_CALIB("<< invalid data.\n");
spin_unlock_irqrestore(&il->lock, flags);
return;
}
rx_enable_time = le32_to_cpu(rx_info->channel_load);
fa_cck = le32_to_cpu(cck->false_alarm_cnt);
fa_ofdm = le32_to_cpu(ofdm->false_alarm_cnt);
bad_plcp_cck = le32_to_cpu(cck->plcp_err);
bad_plcp_ofdm = le32_to_cpu(ofdm->plcp_err);
statis.beacon_silence_rssi_a =
le32_to_cpu(rx_info->beacon_silence_rssi_a);
statis.beacon_silence_rssi_b =
le32_to_cpu(rx_info->beacon_silence_rssi_b);
statis.beacon_silence_rssi_c =
le32_to_cpu(rx_info->beacon_silence_rssi_c);
statis.beacon_energy_a = le32_to_cpu(rx_info->beacon_energy_a);
statis.beacon_energy_b = le32_to_cpu(rx_info->beacon_energy_b);
statis.beacon_energy_c = le32_to_cpu(rx_info->beacon_energy_c);
spin_unlock_irqrestore(&il->lock, flags);
D_CALIB("rx_enable_time = %u usecs\n", rx_enable_time);
if (!rx_enable_time) {
D_CALIB("<< RX Enable Time == 0!\n");
return;
}
if (data->last_bad_plcp_cnt_cck > bad_plcp_cck)
data->last_bad_plcp_cnt_cck = bad_plcp_cck;
else {
bad_plcp_cck -= data->last_bad_plcp_cnt_cck;
data->last_bad_plcp_cnt_cck += bad_plcp_cck;
}
if (data->last_bad_plcp_cnt_ofdm > bad_plcp_ofdm)
data->last_bad_plcp_cnt_ofdm = bad_plcp_ofdm;
else {
bad_plcp_ofdm -= data->last_bad_plcp_cnt_ofdm;
data->last_bad_plcp_cnt_ofdm += bad_plcp_ofdm;
}
if (data->last_fa_cnt_ofdm > fa_ofdm)
data->last_fa_cnt_ofdm = fa_ofdm;
else {
fa_ofdm -= data->last_fa_cnt_ofdm;
data->last_fa_cnt_ofdm += fa_ofdm;
}
if (data->last_fa_cnt_cck > fa_cck)
data->last_fa_cnt_cck = fa_cck;
else {
fa_cck -= data->last_fa_cnt_cck;
data->last_fa_cnt_cck += fa_cck;
}
norm_fa_ofdm = fa_ofdm + bad_plcp_ofdm;
norm_fa_cck = fa_cck + bad_plcp_cck;
D_CALIB("cck: fa %u badp %u ofdm: fa %u badp %u\n", fa_cck,
bad_plcp_cck, fa_ofdm, bad_plcp_ofdm);
il4965_sens_auto_corr_ofdm(il, norm_fa_ofdm, rx_enable_time);
il4965_sens_energy_cck(il, norm_fa_cck, rx_enable_time, &statis);
il4965_sensitivity_write(il);
}
static inline u8
il4965_find_first_chain(u8 mask)
{
if (mask & ANT_A)
return CHAIN_A;
if (mask & ANT_B)
return CHAIN_B;
return CHAIN_C;
}
static void
il4965_find_disconn_antenna(struct il_priv *il, u32 * average_sig,
struct il_chain_noise_data *data)
{
u32 active_chains = 0;
u32 max_average_sig;
u16 max_average_sig_antenna_i;
u8 num_tx_chains;
u8 first_chain;
u16 i = 0;
average_sig[0] =
data->chain_signal_a /
il->cfg->base_params->chain_noise_num_beacons;
average_sig[1] =
data->chain_signal_b /
il->cfg->base_params->chain_noise_num_beacons;
average_sig[2] =
data->chain_signal_c /
il->cfg->base_params->chain_noise_num_beacons;
if (average_sig[0] >= average_sig[1]) {
max_average_sig = average_sig[0];
max_average_sig_antenna_i = 0;
active_chains = (1 << max_average_sig_antenna_i);
} else {
max_average_sig = average_sig[1];
max_average_sig_antenna_i = 1;
active_chains = (1 << max_average_sig_antenna_i);
}
if (average_sig[2] >= max_average_sig) {
max_average_sig = average_sig[2];
max_average_sig_antenna_i = 2;
active_chains = (1 << max_average_sig_antenna_i);
}
D_CALIB("average_sig: a %d b %d c %d\n", average_sig[0], average_sig[1],
average_sig[2]);
D_CALIB("max_average_sig = %d, antenna %d\n", max_average_sig,
max_average_sig_antenna_i);
for (i = 0; i < NUM_RX_CHAINS; i++) {
if (i != max_average_sig_antenna_i) {
s32 rssi_delta = (max_average_sig - average_sig[i]);
if (rssi_delta > MAXIMUM_ALLOWED_PATHLOSS)
data->disconn_array[i] = 1;
else
active_chains |= (1 << i);
D_CALIB("i = %d rssiDelta = %d "
"disconn_array[i] = %d\n", i, rssi_delta,
data->disconn_array[i]);
}
}
active_chains &= il->hw_params.valid_rx_ant;
num_tx_chains = 0;
for (i = 0; i < NUM_RX_CHAINS; i++) {
u8 ant_msk = (1 << i);
if (!(il->hw_params.valid_tx_ant & ant_msk))
continue;
num_tx_chains++;
if (data->disconn_array[i] == 0)
break;
if (num_tx_chains == il->hw_params.tx_chains_num &&
data->disconn_array[i]) {
first_chain =
il4965_find_first_chain(il->cfg->valid_tx_ant);
data->disconn_array[first_chain] = 0;
active_chains |= BIT(first_chain);
D_CALIB("All Tx chains are disconnected"
"- declare %d as connected\n", first_chain);
break;
}
}
if (active_chains != il->hw_params.valid_rx_ant &&
active_chains != il->chain_noise_data.active_chains)
D_CALIB("Detected that not all antennas are connected! "
"Connected: %#x, valid: %#x.\n", active_chains,
il->hw_params.valid_rx_ant);
data->active_chains = active_chains;
D_CALIB("active_chains (bitwise) = 0x%x\n", active_chains);
}
static void
il4965_gain_computation(struct il_priv *il, u32 * average_noise,
u16 min_average_noise_antenna_i, u32 min_average_noise,
u8 default_chain)
{
int i, ret;
struct il_chain_noise_data *data = &il->chain_noise_data;
data->delta_gain_code[min_average_noise_antenna_i] = 0;
for (i = default_chain; i < NUM_RX_CHAINS; i++) {
s32 delta_g = 0;
if (!data->disconn_array[i] &&
data->delta_gain_code[i] ==
CHAIN_NOISE_DELTA_GAIN_INIT_VAL) {
delta_g = average_noise[i] - min_average_noise;
data->delta_gain_code[i] = (u8) ((delta_g * 10) / 15);
data->delta_gain_code[i] =
min(data->delta_gain_code[i],
(u8) CHAIN_NOISE_MAX_DELTA_GAIN_CODE);
data->delta_gain_code[i] =
(data->delta_gain_code[i] | (1 << 2));
} else {
data->delta_gain_code[i] = 0;
}
}
D_CALIB("delta_gain_codes: a %d b %d c %d\n", data->delta_gain_code[0],
data->delta_gain_code[1], data->delta_gain_code[2]);
if (!data->radio_write) {
struct il_calib_diff_gain_cmd cmd;
data->radio_write = 1;
memset(&cmd, 0, sizeof(cmd));
cmd.hdr.op_code = IL_PHY_CALIBRATE_DIFF_GAIN_CMD;
cmd.diff_gain_a = data->delta_gain_code[0];
cmd.diff_gain_b = data->delta_gain_code[1];
cmd.diff_gain_c = data->delta_gain_code[2];
ret = il_send_cmd_pdu(il, C_PHY_CALIBRATION, sizeof(cmd), &cmd);
if (ret)
D_CALIB("fail sending cmd " "C_PHY_CALIBRATION\n");
data->state = IL_CHAIN_NOISE_CALIBRATED;
}
}
void
il4965_chain_noise_calibration(struct il_priv *il, void *stat_resp)
{
struct il_chain_noise_data *data = NULL;
u32 chain_noise_a;
u32 chain_noise_b;
u32 chain_noise_c;
u32 chain_sig_a;
u32 chain_sig_b;
u32 chain_sig_c;
u32 average_sig[NUM_RX_CHAINS] = { INITIALIZATION_VALUE };
u32 average_noise[NUM_RX_CHAINS] = { INITIALIZATION_VALUE };
u32 min_average_noise = MIN_AVERAGE_NOISE_MAX_VALUE;
u16 min_average_noise_antenna_i = INITIALIZATION_VALUE;
u16 i = 0;
u16 rxon_chnum = INITIALIZATION_VALUE;
u16 stat_chnum = INITIALIZATION_VALUE;
u8 rxon_band24;
u8 stat_band24;
unsigned long flags;
struct stats_rx_non_phy *rx_info;
struct il_rxon_context *ctx = &il->ctx;
if (il->disable_chain_noise_cal)
return;
data = &(il->chain_noise_data);
if (data->state != IL_CHAIN_NOISE_ACCUMULATE) {
if (data->state == IL_CHAIN_NOISE_ALIVE)
D_CALIB("Wait for noise calib reset\n");
return;
}
spin_lock_irqsave(&il->lock, flags);
rx_info = &(((struct il_notif_stats *)stat_resp)->rx.general);
if (rx_info->interference_data_flag != INTERFERENCE_DATA_AVAILABLE) {
D_CALIB(" << Interference data unavailable\n");
spin_unlock_irqrestore(&il->lock, flags);
return;
}
rxon_band24 = !!(ctx->staging.flags & RXON_FLG_BAND_24G_MSK);
rxon_chnum = le16_to_cpu(ctx->staging.channel);
stat_band24 =
!!(((struct il_notif_stats *)stat_resp)->
flag & STATS_REPLY_FLG_BAND_24G_MSK);
stat_chnum =
le32_to_cpu(((struct il_notif_stats *)stat_resp)->flag) >> 16;
if (rxon_chnum != stat_chnum || rxon_band24 != stat_band24) {
D_CALIB("Stats not from chan=%d, band24=%d\n", rxon_chnum,
rxon_band24);
spin_unlock_irqrestore(&il->lock, flags);
return;
}
chain_noise_a =
le32_to_cpu(rx_info->beacon_silence_rssi_a) & IN_BAND_FILTER;
chain_noise_b =
le32_to_cpu(rx_info->beacon_silence_rssi_b) & IN_BAND_FILTER;
chain_noise_c =
le32_to_cpu(rx_info->beacon_silence_rssi_c) & IN_BAND_FILTER;
chain_sig_a = le32_to_cpu(rx_info->beacon_rssi_a) & IN_BAND_FILTER;
chain_sig_b = le32_to_cpu(rx_info->beacon_rssi_b) & IN_BAND_FILTER;
chain_sig_c = le32_to_cpu(rx_info->beacon_rssi_c) & IN_BAND_FILTER;
spin_unlock_irqrestore(&il->lock, flags);
data->beacon_count++;
data->chain_noise_a = (chain_noise_a + data->chain_noise_a);
data->chain_noise_b = (chain_noise_b + data->chain_noise_b);
data->chain_noise_c = (chain_noise_c + data->chain_noise_c);
data->chain_signal_a = (chain_sig_a + data->chain_signal_a);
data->chain_signal_b = (chain_sig_b + data->chain_signal_b);
data->chain_signal_c = (chain_sig_c + data->chain_signal_c);
D_CALIB("chan=%d, band24=%d, beacon=%d\n", rxon_chnum, rxon_band24,
data->beacon_count);
D_CALIB("chain_sig: a %d b %d c %d\n", chain_sig_a, chain_sig_b,
chain_sig_c);
D_CALIB("chain_noise: a %d b %d c %d\n", chain_noise_a, chain_noise_b,
chain_noise_c);
if (data->beacon_count != il->cfg->base_params->chain_noise_num_beacons)
return;
il4965_find_disconn_antenna(il, average_sig, data);
average_noise[0] =
data->chain_noise_a / il->cfg->base_params->chain_noise_num_beacons;
average_noise[1] =
data->chain_noise_b / il->cfg->base_params->chain_noise_num_beacons;
average_noise[2] =
data->chain_noise_c / il->cfg->base_params->chain_noise_num_beacons;
for (i = 0; i < NUM_RX_CHAINS; i++) {
if (!data->disconn_array[i] &&
average_noise[i] <= min_average_noise) {
min_average_noise = average_noise[i];
min_average_noise_antenna_i = i;
}
}
D_CALIB("average_noise: a %d b %d c %d\n", average_noise[0],
average_noise[1], average_noise[2]);
D_CALIB("min_average_noise = %d, antenna %d\n", min_average_noise,
min_average_noise_antenna_i);
il4965_gain_computation(il, average_noise, min_average_noise_antenna_i,
min_average_noise,
il4965_find_first_chain(il->cfg->valid_rx_ant));
if (il->cfg->ops->lib->update_chain_flags)
il->cfg->ops->lib->update_chain_flags(il);
data->state = IL_CHAIN_NOISE_DONE;
il_power_update_mode(il, false);
}
void
il4965_reset_run_time_calib(struct il_priv *il)
{
int i;
memset(&(il->sensitivity_data), 0, sizeof(struct il_sensitivity_data));
memset(&(il->chain_noise_data), 0, sizeof(struct il_chain_noise_data));
for (i = 0; i < NUM_RX_CHAINS; i++)
il->chain_noise_data.delta_gain_code[i] =
CHAIN_NOISE_DELTA_GAIN_INIT_VAL;
il_send_stats_request(il, CMD_ASYNC, true);
}
