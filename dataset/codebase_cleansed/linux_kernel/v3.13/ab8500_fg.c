struct ab8500_fg *ab8500_fg_get(void)
{
struct ab8500_fg *fg;
if (list_empty(&ab8500_fg_list))
return NULL;
fg = list_first_entry(&ab8500_fg_list, struct ab8500_fg, node);
return fg;
}
static u8 ab8500_volt_to_regval(int voltage)
{
int i;
if (voltage < ab8500_fg_lowbat_voltage_map[0])
return 0;
for (i = 0; i < ARRAY_SIZE(ab8500_fg_lowbat_voltage_map); i++) {
if (voltage < ab8500_fg_lowbat_voltage_map[i])
return (u8) i - 1;
}
return (u8) ARRAY_SIZE(ab8500_fg_lowbat_voltage_map) - 1;
}
static int ab8500_fg_is_low_curr(struct ab8500_fg *di, int curr)
{
if (curr > -di->bm->fg_params->high_curr_threshold)
return true;
else
return false;
}
static int ab8500_fg_add_cap_sample(struct ab8500_fg *di, int sample)
{
struct timespec ts;
struct ab8500_fg_avg_cap *avg = &di->avg_cap;
getnstimeofday(&ts);
do {
avg->sum += sample - avg->samples[avg->pos];
avg->samples[avg->pos] = sample;
avg->time_stamps[avg->pos] = ts.tv_sec;
avg->pos++;
if (avg->pos == NBR_AVG_SAMPLES)
avg->pos = 0;
if (avg->nbr_samples < NBR_AVG_SAMPLES)
avg->nbr_samples++;
} while (ts.tv_sec - VALID_CAPACITY_SEC > avg->time_stamps[avg->pos]);
avg->avg = avg->sum / avg->nbr_samples;
return avg->avg;
}
static void ab8500_fg_clear_cap_samples(struct ab8500_fg *di)
{
int i;
struct ab8500_fg_avg_cap *avg = &di->avg_cap;
avg->pos = 0;
avg->nbr_samples = 0;
avg->sum = 0;
avg->avg = 0;
for (i = 0; i < NBR_AVG_SAMPLES; i++) {
avg->samples[i] = 0;
avg->time_stamps[i] = 0;
}
}
static void ab8500_fg_fill_cap_sample(struct ab8500_fg *di, int sample)
{
int i;
struct timespec ts;
struct ab8500_fg_avg_cap *avg = &di->avg_cap;
getnstimeofday(&ts);
for (i = 0; i < NBR_AVG_SAMPLES; i++) {
avg->samples[i] = sample;
avg->time_stamps[i] = ts.tv_sec;
}
avg->pos = 0;
avg->nbr_samples = NBR_AVG_SAMPLES;
avg->sum = sample * NBR_AVG_SAMPLES;
avg->avg = sample;
}
static int ab8500_fg_coulomb_counter(struct ab8500_fg *di, bool enable)
{
int ret = 0;
mutex_lock(&di->cc_lock);
if (enable) {
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG, 0x00);
if (ret)
goto cc_err;
ret = abx500_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_NCOV_ACCU,
di->fg_samples);
if (ret)
goto cc_err;
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG,
(CC_DEEP_SLEEP_ENA | CC_PWR_UP_ENA));
if (ret)
goto cc_err;
di->flags.fg_enabled = true;
} else {
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG,
(RESET_ACCU | READ_REQ), 0);
if (ret)
goto cc_err;
ret = abx500_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_NCOV_ACCU_CTRL, 0);
if (ret)
goto cc_err;
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG, 0);
if (ret)
goto cc_err;
di->flags.fg_enabled = false;
}
dev_dbg(di->dev, " CC enabled: %d Samples: %d\n",
enable, di->fg_samples);
mutex_unlock(&di->cc_lock);
return ret;
cc_err:
dev_err(di->dev, "%s Enabling coulomb counter failed\n", __func__);
mutex_unlock(&di->cc_lock);
return ret;
}
int ab8500_fg_inst_curr_start(struct ab8500_fg *di)
{
u8 reg_val;
int ret;
mutex_lock(&di->cc_lock);
di->nbr_cceoc_irq_cnt = 0;
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG, &reg_val);
if (ret < 0)
goto fail;
if (!(reg_val & CC_PWR_UP_ENA)) {
dev_dbg(di->dev, "%s Enable FG\n", __func__);
di->turn_off_fg = true;
ret = abx500_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_NCOV_ACCU,
SEC_TO_SAMPLE(10));
if (ret)
goto fail;
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG,
(CC_DEEP_SLEEP_ENA | CC_PWR_UP_ENA));
if (ret)
goto fail;
} else {
di->turn_off_fg = false;
}
reinit_completion(&di->ab8500_fg_started);
reinit_completion(&di->ab8500_fg_complete);
enable_irq(di->irq);
return 0;
fail:
mutex_unlock(&di->cc_lock);
return ret;
}
int ab8500_fg_inst_curr_started(struct ab8500_fg *di)
{
return completion_done(&di->ab8500_fg_started);
}
int ab8500_fg_inst_curr_done(struct ab8500_fg *di)
{
return completion_done(&di->ab8500_fg_complete);
}
int ab8500_fg_inst_curr_finalize(struct ab8500_fg *di, int *res)
{
u8 low, high;
int val;
int ret;
int timeout;
if (!completion_done(&di->ab8500_fg_complete)) {
timeout = wait_for_completion_timeout(
&di->ab8500_fg_complete,
INS_CURR_TIMEOUT);
dev_dbg(di->dev, "Finalize time: %d ms\n",
((INS_CURR_TIMEOUT - timeout) * 1000) / HZ);
if (!timeout) {
ret = -ETIME;
disable_irq(di->irq);
di->nbr_cceoc_irq_cnt = 0;
dev_err(di->dev, "completion timed out [%d]\n",
__LINE__);
goto fail;
}
}
disable_irq(di->irq);
di->nbr_cceoc_irq_cnt = 0;
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG,
READ_REQ, READ_REQ);
usleep_range(100, 100);
ret = abx500_get_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_SMPL_CNVL_REG, &low);
if (ret < 0)
goto fail;
ret = abx500_get_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_SMPL_CNVH_REG, &high);
if (ret < 0)
goto fail;
if (high & 0x10)
val = (low | (high << 8) | 0xFFFFE000);
else
val = (low | (high << 8));
val = (val * QLSB_NANO_AMP_HOURS_X10 * 36 * 4) /
(1000 * di->bm->fg_res);
if (di->turn_off_fg) {
dev_dbg(di->dev, "%s Disable FG\n", __func__);
ret = abx500_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG, 0);
if (ret)
goto fail;
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8500_RTC_CC_CONF_REG, 0);
if (ret)
goto fail;
}
mutex_unlock(&di->cc_lock);
(*res) = val;
return 0;
fail:
mutex_unlock(&di->cc_lock);
return ret;
}
int ab8500_fg_inst_curr_blocking(struct ab8500_fg *di)
{
int ret;
int timeout;
int res = 0;
ret = ab8500_fg_inst_curr_start(di);
if (ret) {
dev_err(di->dev, "Failed to initialize fg_inst\n");
return 0;
}
if (!completion_done(&di->ab8500_fg_started)) {
timeout = wait_for_completion_timeout(
&di->ab8500_fg_started,
INS_CURR_TIMEOUT);
dev_dbg(di->dev, "Start time: %d ms\n",
((INS_CURR_TIMEOUT - timeout) * 1000) / HZ);
if (!timeout) {
ret = -ETIME;
dev_err(di->dev, "completion timed out [%d]\n",
__LINE__);
goto fail;
}
}
ret = ab8500_fg_inst_curr_finalize(di, &res);
if (ret) {
dev_err(di->dev, "Failed to finalize fg_inst\n");
return 0;
}
dev_dbg(di->dev, "%s instant current: %d", __func__, res);
return res;
fail:
disable_irq(di->irq);
mutex_unlock(&di->cc_lock);
return ret;
}
static void ab8500_fg_acc_cur_work(struct work_struct *work)
{
int val;
int ret;
u8 low, med, high;
struct ab8500_fg *di = container_of(work,
struct ab8500_fg, fg_acc_cur_work);
mutex_lock(&di->cc_lock);
ret = abx500_set_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_NCOV_ACCU_CTRL, RD_NCONV_ACCU_REQ);
if (ret)
goto exit;
ret = abx500_get_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_NCOV_ACCU_LOW, &low);
if (ret < 0)
goto exit;
ret = abx500_get_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_NCOV_ACCU_MED, &med);
if (ret < 0)
goto exit;
ret = abx500_get_register_interruptible(di->dev, AB8500_GAS_GAUGE,
AB8500_GASG_CC_NCOV_ACCU_HIGH, &high);
if (ret < 0)
goto exit;
if (high & 0x10)
val = (low | (med << 8) | (high << 16) | 0xFFE00000);
else
val = (low | (med << 8) | (high << 16));
di->accu_charge = (val * QLSB_NANO_AMP_HOURS_X10) /
(100 * di->bm->fg_res);
di->avg_curr = (val * QLSB_NANO_AMP_HOURS_X10 * 36) /
(1000 * di->bm->fg_res * (di->fg_samples / 4));
di->flags.conv_done = true;
mutex_unlock(&di->cc_lock);
queue_work(di->fg_wq, &di->fg_work);
dev_dbg(di->dev, "fg_res: %d, fg_samples: %d, gasg: %d, accu_charge: %d \n",
di->bm->fg_res, di->fg_samples, val, di->accu_charge);
return;
exit:
dev_err(di->dev,
"Failed to read or write gas gauge registers\n");
mutex_unlock(&di->cc_lock);
queue_work(di->fg_wq, &di->fg_work);
}
static int ab8500_fg_bat_voltage(struct ab8500_fg *di)
{
int vbat;
static int prev;
vbat = ab8500_gpadc_convert(di->gpadc, MAIN_BAT_V);
if (vbat < 0) {
dev_err(di->dev,
"%s gpadc conversion failed, using previous value\n",
__func__);
return prev;
}
prev = vbat;
return vbat;
}
static int ab8500_fg_volt_to_capacity(struct ab8500_fg *di, int voltage)
{
int i, tbl_size;
const struct abx500_v_to_cap *tbl;
int cap = 0;
tbl = di->bm->bat_type[di->bm->batt_id].v_to_cap_tbl,
tbl_size = di->bm->bat_type[di->bm->batt_id].n_v_cap_tbl_elements;
for (i = 0; i < tbl_size; ++i) {
if (voltage > tbl[i].voltage)
break;
}
if ((i > 0) && (i < tbl_size)) {
cap = interpolate(voltage,
tbl[i].voltage,
tbl[i].capacity * 10,
tbl[i-1].voltage,
tbl[i-1].capacity * 10);
} else if (i == 0) {
cap = 1000;
} else {
cap = 0;
}
dev_dbg(di->dev, "%s Vbat: %d, Cap: %d per mille",
__func__, voltage, cap);
return cap;
}
static int ab8500_fg_uncomp_volt_to_capacity(struct ab8500_fg *di)
{
di->vbat = ab8500_fg_bat_voltage(di);
return ab8500_fg_volt_to_capacity(di, di->vbat);
}
static int ab8500_fg_battery_resistance(struct ab8500_fg *di)
{
int i, tbl_size;
const struct batres_vs_temp *tbl;
int resist = 0;
tbl = di->bm->bat_type[di->bm->batt_id].batres_tbl;
tbl_size = di->bm->bat_type[di->bm->batt_id].n_batres_tbl_elements;
for (i = 0; i < tbl_size; ++i) {
if (di->bat_temp / 10 > tbl[i].temp)
break;
}
if ((i > 0) && (i < tbl_size)) {
resist = interpolate(di->bat_temp / 10,
tbl[i].temp,
tbl[i].resist,
tbl[i-1].temp,
tbl[i-1].resist);
} else if (i == 0) {
resist = tbl[0].resist;
} else {
resist = tbl[tbl_size - 1].resist;
}
dev_dbg(di->dev, "%s Temp: %d battery internal resistance: %d"
" fg resistance %d, total: %d (mOhm)\n",
__func__, di->bat_temp, resist, di->bm->fg_res / 10,
(di->bm->fg_res / 10) + resist);
resist += di->bm->fg_res / 10;
return resist;
}
static int ab8500_fg_load_comp_volt_to_capacity(struct ab8500_fg *di)
{
int vbat_comp, res;
int i = 0;
int vbat = 0;
ab8500_fg_inst_curr_start(di);
do {
vbat += ab8500_fg_bat_voltage(di);
i++;
usleep_range(5000, 6000);
} while (!ab8500_fg_inst_curr_done(di));
ab8500_fg_inst_curr_finalize(di, &di->inst_curr);
di->vbat = vbat / i;
res = ab8500_fg_battery_resistance(di);
vbat_comp = di->vbat - (di->inst_curr * res) / 1000;
dev_dbg(di->dev, "%s Measured Vbat: %dmV,Compensated Vbat %dmV, "
"R: %dmOhm, Current: %dmA Vbat Samples: %d\n",
__func__, di->vbat, vbat_comp, res, di->inst_curr, i);
return ab8500_fg_volt_to_capacity(di, vbat_comp);
}
static int ab8500_fg_convert_mah_to_permille(struct ab8500_fg *di, int cap_mah)
{
return (cap_mah * 1000) / di->bat_cap.max_mah_design;
}
static int ab8500_fg_convert_permille_to_mah(struct ab8500_fg *di, int cap_pm)
{
return cap_pm * di->bat_cap.max_mah_design / 1000;
}
static int ab8500_fg_convert_mah_to_uwh(struct ab8500_fg *di, int cap_mah)
{
u64 div_res;
u32 div_rem;
div_res = ((u64) cap_mah) * ((u64) di->vbat_nom);
div_rem = do_div(div_res, 1000);
if (div_rem >= 1000 / 2)
div_res++;
return (int) div_res;
}
static int ab8500_fg_calc_cap_charging(struct ab8500_fg *di)
{
dev_dbg(di->dev, "%s cap_mah %d accu_charge %d\n",
__func__,
di->bat_cap.mah,
di->accu_charge);
if (di->bat_cap.mah + di->accu_charge > 0)
di->bat_cap.mah += di->accu_charge;
else
di->bat_cap.mah = 0;
if (di->bat_cap.mah >= di->bat_cap.max_mah_design ||
di->flags.force_full) {
di->bat_cap.mah = di->bat_cap.max_mah_design;
}
ab8500_fg_fill_cap_sample(di, di->bat_cap.mah);
di->bat_cap.permille =
ab8500_fg_convert_mah_to_permille(di, di->bat_cap.mah);
di->vbat = ab8500_fg_bat_voltage(di);
di->inst_curr = ab8500_fg_inst_curr_blocking(di);
return di->bat_cap.mah;
}
static int ab8500_fg_calc_cap_discharge_voltage(struct ab8500_fg *di, bool comp)
{
int permille, mah;
if (comp)
permille = ab8500_fg_load_comp_volt_to_capacity(di);
else
permille = ab8500_fg_uncomp_volt_to_capacity(di);
mah = ab8500_fg_convert_permille_to_mah(di, permille);
di->bat_cap.mah = ab8500_fg_add_cap_sample(di, mah);
di->bat_cap.permille =
ab8500_fg_convert_mah_to_permille(di, di->bat_cap.mah);
return di->bat_cap.mah;
}
static int ab8500_fg_calc_cap_discharge_fg(struct ab8500_fg *di)
{
int permille_volt, permille;
dev_dbg(di->dev, "%s cap_mah %d accu_charge %d\n",
__func__,
di->bat_cap.mah,
di->accu_charge);
if (di->bat_cap.mah + di->accu_charge > 0)
di->bat_cap.mah += di->accu_charge;
else
di->bat_cap.mah = 0;
if (di->bat_cap.mah >= di->bat_cap.max_mah_design)
di->bat_cap.mah = di->bat_cap.max_mah_design;
permille = ab8500_fg_convert_mah_to_permille(di, di->bat_cap.mah);
permille_volt = ab8500_fg_uncomp_volt_to_capacity(di);
if (permille < permille_volt) {
di->bat_cap.permille = permille_volt;
di->bat_cap.mah = ab8500_fg_convert_permille_to_mah(di,
di->bat_cap.permille);
dev_dbg(di->dev, "%s voltage based: perm %d perm_volt %d\n",
__func__,
permille,
permille_volt);
ab8500_fg_fill_cap_sample(di, di->bat_cap.mah);
} else {
ab8500_fg_fill_cap_sample(di, di->bat_cap.mah);
di->bat_cap.permille =
ab8500_fg_convert_mah_to_permille(di, di->bat_cap.mah);
}
return di->bat_cap.mah;
}
static int ab8500_fg_capacity_level(struct ab8500_fg *di)
{
int ret, percent;
percent = DIV_ROUND_CLOSEST(di->bat_cap.permille, 10);
if (percent <= di->bm->cap_levels->critical ||
di->flags.low_bat)
ret = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
else if (percent <= di->bm->cap_levels->low)
ret = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
else if (percent <= di->bm->cap_levels->normal)
ret = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
else if (percent <= di->bm->cap_levels->high)
ret = POWER_SUPPLY_CAPACITY_LEVEL_HIGH;
else
ret = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
return ret;
}
static int ab8500_fg_calculate_scaled_capacity(struct ab8500_fg *di)
{
struct ab8500_fg_cap_scaling *cs = &di->bat_cap.cap_scale;
int capacity = di->bat_cap.prev_percent;
if (!cs->enable)
return capacity;
if (di->flags.fully_charged) {
cs->cap_to_scale[0] = 100;
cs->cap_to_scale[1] =
max(capacity, di->bm->fg_params->maint_thres);
dev_dbg(di->dev, "Scale cap with %d/%d\n",
cs->cap_to_scale[0], cs->cap_to_scale[1]);
}
if ((cs->cap_to_scale[0] != cs->cap_to_scale[1])
&& (cs->cap_to_scale[1] > 0))
capacity = min(100,
DIV_ROUND_CLOSEST(di->bat_cap.prev_percent *
cs->cap_to_scale[0],
cs->cap_to_scale[1]));
if (di->flags.charging) {
if (capacity < cs->disable_cap_level) {
cs->disable_cap_level = capacity;
dev_dbg(di->dev, "Cap to stop scale lowered %d%%\n",
cs->disable_cap_level);
} else if (!di->flags.fully_charged) {
if (di->bat_cap.prev_percent >=
cs->disable_cap_level) {
dev_dbg(di->dev, "Disabling scaled capacity\n");
cs->enable = false;
capacity = di->bat_cap.prev_percent;
} else {
dev_dbg(di->dev,
"Waiting in cap to level %d%%\n",
cs->disable_cap_level);
capacity = cs->disable_cap_level;
}
}
}
return capacity;
}
static void ab8500_fg_update_cap_scalers(struct ab8500_fg *di)
{
struct ab8500_fg_cap_scaling *cs = &di->bat_cap.cap_scale;
if (!cs->enable)
return;
if (di->flags.charging) {
di->bat_cap.cap_scale.disable_cap_level =
di->bat_cap.cap_scale.scaled_cap;
dev_dbg(di->dev, "Cap to stop scale at charge %d%%\n",
di->bat_cap.cap_scale.disable_cap_level);
} else {
if (cs->scaled_cap != 100) {
cs->cap_to_scale[0] = cs->scaled_cap;
cs->cap_to_scale[1] = di->bat_cap.prev_percent;
} else {
cs->cap_to_scale[0] = 100;
cs->cap_to_scale[1] =
max(di->bat_cap.prev_percent,
di->bm->fg_params->maint_thres);
}
dev_dbg(di->dev, "Cap to scale at discharge %d/%d\n",
cs->cap_to_scale[0], cs->cap_to_scale[1]);
}
}
static void ab8500_fg_check_capacity_limits(struct ab8500_fg *di, bool init)
{
bool changed = false;
int percent = DIV_ROUND_CLOSEST(di->bat_cap.permille, 10);
di->bat_cap.level = ab8500_fg_capacity_level(di);
if (di->bat_cap.level != di->bat_cap.prev_level) {
if (!(!di->flags.charging && di->bat_cap.level >
di->bat_cap.prev_level) || init) {
dev_dbg(di->dev, "level changed from %d to %d\n",
di->bat_cap.prev_level,
di->bat_cap.level);
di->bat_cap.prev_level = di->bat_cap.level;
changed = true;
} else {
dev_dbg(di->dev, "level not allowed to go up "
"since no charger is connected: %d to %d\n",
di->bat_cap.prev_level,
di->bat_cap.level);
}
}
if (di->flags.low_bat) {
dev_dbg(di->dev, "Battery low, set capacity to 0\n");
di->bat_cap.prev_percent = 0;
di->bat_cap.permille = 0;
percent = 0;
di->bat_cap.prev_mah = 0;
di->bat_cap.mah = 0;
changed = true;
} else if (di->flags.fully_charged) {
if (di->flags.force_full) {
di->bat_cap.prev_percent = percent;
di->bat_cap.prev_mah = di->bat_cap.mah;
changed = true;
if (!di->bat_cap.cap_scale.enable &&
di->bm->capacity_scaling) {
di->bat_cap.cap_scale.enable = true;
di->bat_cap.cap_scale.cap_to_scale[0] = 100;
di->bat_cap.cap_scale.cap_to_scale[1] =
di->bat_cap.prev_percent;
di->bat_cap.cap_scale.disable_cap_level = 100;
}
} else if (di->bat_cap.prev_percent != percent) {
dev_dbg(di->dev,
"battery reported full "
"but capacity dropping: %d\n",
percent);
di->bat_cap.prev_percent = percent;
di->bat_cap.prev_mah = di->bat_cap.mah;
changed = true;
}
} else if (di->bat_cap.prev_percent != percent) {
if (percent == 0) {
di->bat_cap.prev_percent = 1;
percent = 1;
changed = true;
} else if (!(!di->flags.charging &&
percent > di->bat_cap.prev_percent) || init) {
dev_dbg(di->dev,
"capacity changed from %d to %d (%d)\n",
di->bat_cap.prev_percent,
percent,
di->bat_cap.permille);
di->bat_cap.prev_percent = percent;
di->bat_cap.prev_mah = di->bat_cap.mah;
changed = true;
} else {
dev_dbg(di->dev, "capacity not allowed to go up since "
"no charger is connected: %d to %d (%d)\n",
di->bat_cap.prev_percent,
percent,
di->bat_cap.permille);
}
}
if (changed) {
if (di->bm->capacity_scaling) {
di->bat_cap.cap_scale.scaled_cap =
ab8500_fg_calculate_scaled_capacity(di);
dev_info(di->dev, "capacity=%d (%d)\n",
di->bat_cap.prev_percent,
di->bat_cap.cap_scale.scaled_cap);
}
power_supply_changed(&di->fg_psy);
if (di->flags.fully_charged && di->flags.force_full) {
dev_dbg(di->dev, "Battery full, notifying.\n");
di->flags.force_full = false;
sysfs_notify(&di->fg_kobject, NULL, "charge_full");
}
sysfs_notify(&di->fg_kobject, NULL, "charge_now");
}
}
static void ab8500_fg_charge_state_to(struct ab8500_fg *di,
enum ab8500_fg_charge_state new_state)
{
dev_dbg(di->dev, "Charge state from %d [%s] to %d [%s]\n",
di->charge_state,
charge_state[di->charge_state],
new_state,
charge_state[new_state]);
di->charge_state = new_state;
}
static void ab8500_fg_discharge_state_to(struct ab8500_fg *di,
enum ab8500_fg_discharge_state new_state)
{
dev_dbg(di->dev, "Disharge state from %d [%s] to %d [%s]\n",
di->discharge_state,
discharge_state[di->discharge_state],
new_state,
discharge_state[new_state]);
di->discharge_state = new_state;
}
static void ab8500_fg_algorithm_charging(struct ab8500_fg *di)
{
if (di->discharge_state != AB8500_FG_DISCHARGE_INIT_RECOVERY)
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_INIT_RECOVERY);
switch (di->charge_state) {
case AB8500_FG_CHARGE_INIT:
di->fg_samples = SEC_TO_SAMPLE(
di->bm->fg_params->accu_charging);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_charge_state_to(di, AB8500_FG_CHARGE_READOUT);
break;
case AB8500_FG_CHARGE_READOUT:
mutex_lock(&di->cc_lock);
if (!di->flags.conv_done && !di->flags.force_full) {
mutex_unlock(&di->cc_lock);
dev_dbg(di->dev, "%s CC conv not done\n",
__func__);
break;
}
di->flags.conv_done = false;
mutex_unlock(&di->cc_lock);
ab8500_fg_calc_cap_charging(di);
break;
default:
break;
}
ab8500_fg_check_capacity_limits(di, false);
}
static void force_capacity(struct ab8500_fg *di)
{
int cap;
ab8500_fg_clear_cap_samples(di);
cap = di->bat_cap.user_mah;
if (cap > di->bat_cap.max_mah_design) {
dev_dbg(di->dev, "Remaining cap %d can't be bigger than total"
" %d\n", cap, di->bat_cap.max_mah_design);
cap = di->bat_cap.max_mah_design;
}
ab8500_fg_fill_cap_sample(di, di->bat_cap.user_mah);
di->bat_cap.permille = ab8500_fg_convert_mah_to_permille(di, cap);
di->bat_cap.mah = cap;
ab8500_fg_check_capacity_limits(di, true);
}
static bool check_sysfs_capacity(struct ab8500_fg *di)
{
int cap, lower, upper;
int cap_permille;
cap = di->bat_cap.user_mah;
cap_permille = ab8500_fg_convert_mah_to_permille(di,
di->bat_cap.user_mah);
lower = di->bat_cap.permille - di->bm->fg_params->user_cap_limit * 10;
upper = di->bat_cap.permille + di->bm->fg_params->user_cap_limit * 10;
if (lower < 0)
lower = 0;
if (upper > 1000)
upper = 1000;
dev_dbg(di->dev, "Capacity limits:"
" (Lower: %d User: %d Upper: %d) [user: %d, was: %d]\n",
lower, cap_permille, upper, cap, di->bat_cap.mah);
if (cap_permille > lower && cap_permille < upper) {
dev_dbg(di->dev, "OK! Using users cap %d uAh now\n", cap);
force_capacity(di);
return true;
}
dev_dbg(di->dev, "Capacity from user out of limits, ignoring");
return false;
}
static void ab8500_fg_algorithm_discharging(struct ab8500_fg *di)
{
int sleep_time;
if (di->charge_state != AB8500_FG_CHARGE_INIT)
ab8500_fg_charge_state_to(di, AB8500_FG_CHARGE_INIT);
switch (di->discharge_state) {
case AB8500_FG_DISCHARGE_INIT:
di->init_cnt = 0;
di->fg_samples = SEC_TO_SAMPLE(di->bm->fg_params->init_timer);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_INITMEASURING);
case AB8500_FG_DISCHARGE_INITMEASURING:
sleep_time = di->bm->fg_params->init_timer;
if (di->init_cnt > di->bm->fg_params->init_discard_time) {
ab8500_fg_calc_cap_discharge_voltage(di, true);
ab8500_fg_check_capacity_limits(di, true);
}
di->init_cnt += sleep_time;
if (di->init_cnt > di->bm->fg_params->init_total_time)
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT_INIT);
break;
case AB8500_FG_DISCHARGE_INIT_RECOVERY:
di->recovery_cnt = 0;
di->recovery_needed = true;
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_RECOVERY);
case AB8500_FG_DISCHARGE_RECOVERY:
sleep_time = di->bm->fg_params->recovery_sleep_timer;
di->inst_curr = ab8500_fg_inst_curr_blocking(di);
if (ab8500_fg_is_low_curr(di, di->inst_curr)) {
if (di->recovery_cnt >
di->bm->fg_params->recovery_total_time) {
di->fg_samples = SEC_TO_SAMPLE(
di->bm->fg_params->accu_high_curr);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT);
di->recovery_needed = false;
} else {
queue_delayed_work(di->fg_wq,
&di->fg_periodic_work,
sleep_time * HZ);
}
di->recovery_cnt += sleep_time;
} else {
di->fg_samples = SEC_TO_SAMPLE(
di->bm->fg_params->accu_high_curr);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT);
}
break;
case AB8500_FG_DISCHARGE_READOUT_INIT:
di->fg_samples = SEC_TO_SAMPLE(
di->bm->fg_params->accu_high_curr);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT);
break;
case AB8500_FG_DISCHARGE_READOUT:
di->inst_curr = ab8500_fg_inst_curr_blocking(di);
if (ab8500_fg_is_low_curr(di, di->inst_curr)) {
if (di->high_curr_mode) {
di->high_curr_mode = false;
di->high_curr_cnt = 0;
}
if (di->recovery_needed) {
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_INIT_RECOVERY);
queue_delayed_work(di->fg_wq,
&di->fg_periodic_work, 0);
break;
}
ab8500_fg_calc_cap_discharge_voltage(di, true);
} else {
mutex_lock(&di->cc_lock);
if (!di->flags.conv_done) {
mutex_unlock(&di->cc_lock);
dev_dbg(di->dev, "%s CC conv not done\n",
__func__);
break;
}
di->flags.conv_done = false;
mutex_unlock(&di->cc_lock);
if (!di->high_curr_mode) {
di->high_curr_mode = true;
di->high_curr_cnt = 0;
}
di->high_curr_cnt +=
di->bm->fg_params->accu_high_curr;
if (di->high_curr_cnt >
di->bm->fg_params->high_curr_time)
di->recovery_needed = true;
ab8500_fg_calc_cap_discharge_fg(di);
}
ab8500_fg_check_capacity_limits(di, false);
break;
case AB8500_FG_DISCHARGE_WAKEUP:
ab8500_fg_calc_cap_discharge_voltage(di, true);
di->fg_samples = SEC_TO_SAMPLE(
di->bm->fg_params->accu_high_curr);
ab8500_fg_coulomb_counter(di, true);
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT);
ab8500_fg_check_capacity_limits(di, false);
break;
default:
break;
}
}
static void ab8500_fg_algorithm_calibrate(struct ab8500_fg *di)
{
int ret;
switch (di->calib_state) {
case AB8500_FG_CALIB_INIT:
dev_dbg(di->dev, "Calibration ongoing...\n");
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG,
CC_INT_CAL_N_AVG_MASK, CC_INT_CAL_SAMPLES_8);
if (ret < 0)
goto err;
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG,
CC_INTAVGOFFSET_ENA, CC_INTAVGOFFSET_ENA);
if (ret < 0)
goto err;
di->calib_state = AB8500_FG_CALIB_WAIT;
break;
case AB8500_FG_CALIB_END:
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_GAS_GAUGE, AB8500_GASG_CC_CTRL_REG,
CC_MUXOFFSET, CC_MUXOFFSET);
if (ret < 0)
goto err;
di->flags.calibrate = false;
dev_dbg(di->dev, "Calibration done...\n");
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
break;
case AB8500_FG_CALIB_WAIT:
dev_dbg(di->dev, "Calibration WFI\n");
default:
break;
}
return;
err:
dev_err(di->dev, "failed to calibrate the CC\n");
di->flags.calibrate = false;
di->calib_state = AB8500_FG_CALIB_INIT;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
}
static void ab8500_fg_algorithm(struct ab8500_fg *di)
{
if (di->flags.calibrate)
ab8500_fg_algorithm_calibrate(di);
else {
if (di->flags.charging)
ab8500_fg_algorithm_charging(di);
else
ab8500_fg_algorithm_discharging(di);
}
dev_dbg(di->dev, "[FG_DATA] %d %d %d %d %d %d %d %d %d %d "
"%d %d %d %d %d %d %d\n",
di->bat_cap.max_mah_design,
di->bat_cap.max_mah,
di->bat_cap.mah,
di->bat_cap.permille,
di->bat_cap.level,
di->bat_cap.prev_mah,
di->bat_cap.prev_percent,
di->bat_cap.prev_level,
di->vbat,
di->inst_curr,
di->avg_curr,
di->accu_charge,
di->flags.charging,
di->charge_state,
di->discharge_state,
di->high_curr_mode,
di->recovery_needed);
}
static void ab8500_fg_periodic_work(struct work_struct *work)
{
struct ab8500_fg *di = container_of(work, struct ab8500_fg,
fg_periodic_work.work);
if (di->init_capacity) {
ab8500_fg_calc_cap_discharge_voltage(di, true);
ab8500_fg_check_capacity_limits(di, true);
di->init_capacity = false;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
} else if (di->flags.user_cap) {
if (check_sysfs_capacity(di)) {
ab8500_fg_check_capacity_limits(di, true);
if (di->flags.charging)
ab8500_fg_charge_state_to(di,
AB8500_FG_CHARGE_INIT);
else
ab8500_fg_discharge_state_to(di,
AB8500_FG_DISCHARGE_READOUT_INIT);
}
di->flags.user_cap = false;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
} else
ab8500_fg_algorithm(di);
}
static void ab8500_fg_check_hw_failure_work(struct work_struct *work)
{
int ret;
u8 reg_value;
struct ab8500_fg *di = container_of(work, struct ab8500_fg,
fg_check_hw_failure_work.work);
ret = abx500_get_register_interruptible(di->dev,
AB8500_CHARGER, AB8500_CH_STAT_REG,
&reg_value);
if (ret < 0) {
dev_err(di->dev, "%s ab8500 read failed\n", __func__);
return;
}
if ((reg_value & BATT_OVV) == BATT_OVV) {
if (!di->flags.bat_ovv) {
dev_dbg(di->dev, "Battery OVV\n");
di->flags.bat_ovv = true;
power_supply_changed(&di->fg_psy);
}
queue_delayed_work(di->fg_wq, &di->fg_check_hw_failure_work,
HZ);
} else {
dev_dbg(di->dev, "Battery recovered from OVV\n");
di->flags.bat_ovv = false;
power_supply_changed(&di->fg_psy);
}
}
static void ab8500_fg_low_bat_work(struct work_struct *work)
{
int vbat;
struct ab8500_fg *di = container_of(work, struct ab8500_fg,
fg_low_bat_work.work);
vbat = ab8500_fg_bat_voltage(di);
if (vbat < di->bm->fg_params->lowbat_threshold) {
if (di->low_bat_cnt < 1) {
di->flags.low_bat = true;
dev_warn(di->dev, "Shut down pending...\n");
} else {
di->low_bat_cnt--;
dev_warn(di->dev, "Battery voltage still LOW\n");
queue_delayed_work(di->fg_wq, &di->fg_low_bat_work,
round_jiffies(LOW_BAT_CHECK_INTERVAL));
}
} else {
di->flags.low_bat_delay = false;
di->low_bat_cnt = 10;
dev_warn(di->dev, "Battery voltage OK again\n");
}
ab8500_fg_check_capacity_limits(di, false);
}
static int ab8500_fg_battok_calc(struct ab8500_fg *di, int target)
{
if (target > BATT_OK_MIN +
(BATT_OK_INCREMENT * BATT_OK_MAX_NR_INCREMENTS))
return BATT_OK_MAX_NR_INCREMENTS;
if (target < BATT_OK_MIN)
return 0;
return (target - BATT_OK_MIN) / BATT_OK_INCREMENT;
}
static int ab8500_fg_battok_init_hw_register(struct ab8500_fg *di)
{
int selected;
int sel0;
int sel1;
int cbp_sel0;
int cbp_sel1;
int ret;
int new_val;
sel0 = di->bm->fg_params->battok_falling_th_sel0;
sel1 = di->bm->fg_params->battok_raising_th_sel1;
cbp_sel0 = ab8500_fg_battok_calc(di, sel0);
cbp_sel1 = ab8500_fg_battok_calc(di, sel1);
selected = BATT_OK_MIN + cbp_sel0 * BATT_OK_INCREMENT;
if (selected != sel0)
dev_warn(di->dev, "Invalid voltage step:%d, using %d %d\n",
sel0, selected, cbp_sel0);
selected = BATT_OK_MIN + cbp_sel1 * BATT_OK_INCREMENT;
if (selected != sel1)
dev_warn(di->dev, "Invalid voltage step:%d, using %d %d\n",
sel1, selected, cbp_sel1);
new_val = cbp_sel0 | (cbp_sel1 << 4);
dev_dbg(di->dev, "using: %x %d %d\n", new_val, cbp_sel0, cbp_sel1);
ret = abx500_set_register_interruptible(di->dev, AB8500_SYS_CTRL2_BLOCK,
AB8500_BATT_OK_REG, new_val);
return ret;
}
static void ab8500_fg_instant_work(struct work_struct *work)
{
struct ab8500_fg *di = container_of(work, struct ab8500_fg, fg_work);
ab8500_fg_algorithm(di);
}
static irqreturn_t ab8500_fg_cc_data_end_handler(int irq, void *_di)
{
struct ab8500_fg *di = _di;
if (!di->nbr_cceoc_irq_cnt) {
di->nbr_cceoc_irq_cnt++;
complete(&di->ab8500_fg_started);
} else {
di->nbr_cceoc_irq_cnt = 0;
complete(&di->ab8500_fg_complete);
}
return IRQ_HANDLED;
}
static irqreturn_t ab8500_fg_cc_int_calib_handler(int irq, void *_di)
{
struct ab8500_fg *di = _di;
di->calib_state = AB8500_FG_CALIB_END;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
return IRQ_HANDLED;
}
static irqreturn_t ab8500_fg_cc_convend_handler(int irq, void *_di)
{
struct ab8500_fg *di = _di;
queue_work(di->fg_wq, &di->fg_acc_cur_work);
return IRQ_HANDLED;
}
static irqreturn_t ab8500_fg_batt_ovv_handler(int irq, void *_di)
{
struct ab8500_fg *di = _di;
dev_dbg(di->dev, "Battery OVV\n");
queue_delayed_work(di->fg_wq, &di->fg_check_hw_failure_work, 0);
return IRQ_HANDLED;
}
static irqreturn_t ab8500_fg_lowbatf_handler(int irq, void *_di)
{
struct ab8500_fg *di = _di;
if (!di->flags.low_bat_delay) {
dev_warn(di->dev, "Battery voltage is below LOW threshold\n");
di->flags.low_bat_delay = true;
queue_delayed_work(di->fg_wq, &di->fg_low_bat_work,
round_jiffies(LOW_BAT_CHECK_INTERVAL));
}
return IRQ_HANDLED;
}
static int ab8500_fg_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (di->flags.bat_ovv)
val->intval = BATT_OVV_VALUE * 1000;
else
val->intval = di->vbat * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
val->intval = di->inst_curr * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
val->intval = di->avg_curr * 1000;
break;
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
val->intval = ab8500_fg_convert_mah_to_uwh(di,
di->bat_cap.max_mah_design);
break;
case POWER_SUPPLY_PROP_ENERGY_FULL:
val->intval = ab8500_fg_convert_mah_to_uwh(di,
di->bat_cap.max_mah);
break;
case POWER_SUPPLY_PROP_ENERGY_NOW:
if (di->flags.batt_unknown && !di->bm->chg_unknown_bat &&
di->flags.batt_id_received)
val->intval = ab8500_fg_convert_mah_to_uwh(di,
di->bat_cap.max_mah);
else
val->intval = ab8500_fg_convert_mah_to_uwh(di,
di->bat_cap.prev_mah);
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = di->bat_cap.max_mah_design;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
val->intval = di->bat_cap.max_mah;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
if (di->flags.batt_unknown && !di->bm->chg_unknown_bat &&
di->flags.batt_id_received)
val->intval = di->bat_cap.max_mah;
else
val->intval = di->bat_cap.prev_mah;
break;
case POWER_SUPPLY_PROP_CAPACITY:
if (di->flags.batt_unknown && !di->bm->chg_unknown_bat &&
di->flags.batt_id_received)
val->intval = 100;
else
val->intval = di->bat_cap.prev_percent;
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
if (di->flags.batt_unknown && !di->bm->chg_unknown_bat &&
di->flags.batt_id_received)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
else
val->intval = di->bat_cap.prev_level;
break;
default:
return -EINVAL;
}
return 0;
}
static int ab8500_fg_get_ext_psy_data(struct device *dev, void *data)
{
struct power_supply *psy;
struct power_supply *ext;
struct ab8500_fg *di;
union power_supply_propval ret;
int i, j;
bool psy_found = false;
psy = (struct power_supply *)data;
ext = dev_get_drvdata(dev);
di = to_ab8500_fg_device_info(psy);
for (i = 0; i < ext->num_supplicants; i++) {
if (!strcmp(ext->supplied_to[i], psy->name))
psy_found = true;
}
if (!psy_found)
return 0;
for (j = 0; j < ext->num_properties; j++) {
enum power_supply_property prop;
prop = ext->properties[j];
if (ext->get_property(ext, prop, &ret))
continue;
switch (prop) {
case POWER_SUPPLY_PROP_STATUS:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
switch (ret.intval) {
case POWER_SUPPLY_STATUS_UNKNOWN:
case POWER_SUPPLY_STATUS_DISCHARGING:
case POWER_SUPPLY_STATUS_NOT_CHARGING:
if (!di->flags.charging)
break;
di->flags.charging = false;
di->flags.fully_charged = false;
if (di->bm->capacity_scaling)
ab8500_fg_update_cap_scalers(di);
queue_work(di->fg_wq, &di->fg_work);
break;
case POWER_SUPPLY_STATUS_FULL:
if (di->flags.fully_charged)
break;
di->flags.fully_charged = true;
di->flags.force_full = true;
di->bat_cap.max_mah = di->bat_cap.mah;
queue_work(di->fg_wq, &di->fg_work);
break;
case POWER_SUPPLY_STATUS_CHARGING:
if (di->flags.charging &&
!di->flags.fully_charged)
break;
di->flags.charging = true;
di->flags.fully_charged = false;
if (di->bm->capacity_scaling)
ab8500_fg_update_cap_scalers(di);
queue_work(di->fg_wq, &di->fg_work);
break;
};
default:
break;
};
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
if (!di->flags.batt_id_received &&
di->bm->batt_id != BATTERY_UNKNOWN) {
const struct abx500_battery_type *b;
b = &(di->bm->bat_type[di->bm->batt_id]);
di->flags.batt_id_received = true;
di->bat_cap.max_mah_design =
MILLI_TO_MICRO *
b->charge_full_design;
di->bat_cap.max_mah =
di->bat_cap.max_mah_design;
di->vbat_nom = b->nominal_voltage;
}
if (ret.intval)
di->flags.batt_unknown = false;
else
di->flags.batt_unknown = true;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_TEMP:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
if (di->flags.batt_id_received)
di->bat_temp = ret.intval;
break;
default:
break;
}
break;
default:
break;
}
}
return 0;
}
static int ab8500_fg_init_hw_registers(struct ab8500_fg *di)
{
int ret;
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_CHARGER,
AB8500_BATT_OVV,
BATT_OVV_TH_4P75,
BATT_OVV_TH_4P75);
if (ret) {
dev_err(di->dev, "failed to set BATT_OVV\n");
goto out;
}
ret = abx500_mask_and_set_register_interruptible(di->dev,
AB8500_CHARGER,
AB8500_BATT_OVV,
BATT_OVV_ENA,
BATT_OVV_ENA);
if (ret) {
dev_err(di->dev, "failed to enable BATT_OVV\n");
goto out;
}
ret = abx500_set_register_interruptible(di->dev,
AB8500_SYS_CTRL2_BLOCK,
AB8500_LOW_BAT_REG,
ab8500_volt_to_regval(
di->bm->fg_params->lowbat_threshold) << 1 |
LOW_BAT_ENABLE);
if (ret) {
dev_err(di->dev, "%s write failed\n", __func__);
goto out;
}
ret = ab8500_fg_battok_init_hw_register(di);
if (ret) {
dev_err(di->dev, "BattOk init write failed.\n");
goto out;
}
if (((is_ab8505(di->parent) || is_ab9540(di->parent)) &&
abx500_get_chip_id(di->dev) >= AB8500_CUT2P0)
|| is_ab8540(di->parent)) {
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_MAX_TIME_REG, di->bm->fg_params->pcut_max_time);
if (ret) {
dev_err(di->dev, "%s write failed AB8505_RTC_PCUT_MAX_TIME_REG\n", __func__);
goto out;
};
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_FLAG_TIME_REG, di->bm->fg_params->pcut_flag_time);
if (ret) {
dev_err(di->dev, "%s write failed AB8505_RTC_PCUT_FLAG_TIME_REG\n", __func__);
goto out;
};
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_RESTART_REG, di->bm->fg_params->pcut_max_restart);
if (ret) {
dev_err(di->dev, "%s write failed AB8505_RTC_PCUT_RESTART_REG\n", __func__);
goto out;
};
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_DEBOUNCE_REG, di->bm->fg_params->pcut_debounce_time);
if (ret) {
dev_err(di->dev, "%s write failed AB8505_RTC_PCUT_DEBOUNCE_REG\n", __func__);
goto out;
};
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_CTL_STATUS_REG, di->bm->fg_params->pcut_enable);
if (ret) {
dev_err(di->dev, "%s write failed AB8505_RTC_PCUT_CTL_STATUS_REG\n", __func__);
goto out;
};
}
out:
return ret;
}
static void ab8500_fg_external_power_changed(struct power_supply *psy)
{
struct ab8500_fg *di = to_ab8500_fg_device_info(psy);
class_for_each_device(power_supply_class, NULL,
&di->fg_psy, ab8500_fg_get_ext_psy_data);
}
static void ab8500_fg_reinit_work(struct work_struct *work)
{
struct ab8500_fg *di = container_of(work, struct ab8500_fg,
fg_reinit_work.work);
if (di->flags.calibrate == false) {
dev_dbg(di->dev, "Resetting FG state machine to init.\n");
ab8500_fg_clear_cap_samples(di);
ab8500_fg_calc_cap_discharge_voltage(di, true);
ab8500_fg_charge_state_to(di, AB8500_FG_CHARGE_INIT);
ab8500_fg_discharge_state_to(di, AB8500_FG_DISCHARGE_INIT);
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
} else {
dev_err(di->dev, "Residual offset calibration ongoing "
"retrying..\n");
queue_delayed_work(di->fg_wq, &di->fg_reinit_work,
round_jiffies(1));
}
}
void ab8500_fg_reinit(void)
{
struct ab8500_fg *di = ab8500_fg_get();
if (di != NULL)
queue_delayed_work(di->fg_wq, &di->fg_reinit_work, 0);
}
static ssize_t charge_full_show(struct ab8500_fg *di, char *buf)
{
return sprintf(buf, "%d\n", di->bat_cap.max_mah);
}
static ssize_t charge_full_store(struct ab8500_fg *di, const char *buf,
size_t count)
{
unsigned long charge_full;
ssize_t ret;
ret = kstrtoul(buf, 10, &charge_full);
dev_dbg(di->dev, "Ret %zd charge_full %lu", ret, charge_full);
if (!ret) {
di->bat_cap.max_mah = (int) charge_full;
ret = count;
}
return ret;
}
static ssize_t charge_now_show(struct ab8500_fg *di, char *buf)
{
return sprintf(buf, "%d\n", di->bat_cap.prev_mah);
}
static ssize_t charge_now_store(struct ab8500_fg *di, const char *buf,
size_t count)
{
unsigned long charge_now;
ssize_t ret;
ret = kstrtoul(buf, 10, &charge_now);
dev_dbg(di->dev, "Ret %zd charge_now %lu was %d",
ret, charge_now, di->bat_cap.prev_mah);
if (!ret) {
di->bat_cap.user_mah = (int) charge_now;
di->flags.user_cap = true;
ret = count;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
}
return ret;
}
static ssize_t
ab8500_fg_show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct ab8500_fg_sysfs_entry *entry;
struct ab8500_fg *di;
entry = container_of(attr, struct ab8500_fg_sysfs_entry, attr);
di = container_of(kobj, struct ab8500_fg, fg_kobject);
if (!entry->show)
return -EIO;
return entry->show(di, buf);
}
static ssize_t
ab8500_fg_store(struct kobject *kobj, struct attribute *attr, const char *buf,
size_t count)
{
struct ab8500_fg_sysfs_entry *entry;
struct ab8500_fg *di;
entry = container_of(attr, struct ab8500_fg_sysfs_entry, attr);
di = container_of(kobj, struct ab8500_fg, fg_kobject);
if (!entry->store)
return -EIO;
return entry->store(di, buf, count);
}
static void ab8500_fg_sysfs_exit(struct ab8500_fg *di)
{
kobject_del(&di->fg_kobject);
}
static int ab8500_fg_sysfs_init(struct ab8500_fg *di)
{
int ret = 0;
ret = kobject_init_and_add(&di->fg_kobject,
&ab8500_fg_ktype,
NULL, "battery");
if (ret < 0)
dev_err(di->dev, "failed to create sysfs entry\n");
return ret;
}
static ssize_t ab8505_powercut_flagtime_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_FLAG_TIME_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_FLAG_TIME_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0x7F));
fail:
return ret;
}
static ssize_t ab8505_powercut_flagtime_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
long unsigned reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
reg_value = simple_strtoul(buf, NULL, 10);
if (reg_value > 0x7F) {
dev_err(dev, "Incorrect parameter, echo 0 (1.98s) - 127 (15.625ms) for flagtime\n");
goto fail;
}
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_FLAG_TIME_REG, (u8)reg_value);
if (ret < 0)
dev_err(dev, "Failed to set AB8505_RTC_PCUT_FLAG_TIME_REG\n");
fail:
return count;
}
static ssize_t ab8505_powercut_maxtime_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_MAX_TIME_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_MAX_TIME_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0x7F));
fail:
return ret;
}
static ssize_t ab8505_powercut_maxtime_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
int reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
reg_value = simple_strtoul(buf, NULL, 10);
if (reg_value > 0x7F) {
dev_err(dev, "Incorrect parameter, echo 0 (0.0s) - 127 (1.98s) for maxtime\n");
goto fail;
}
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_MAX_TIME_REG, (u8)reg_value);
if (ret < 0)
dev_err(dev, "Failed to set AB8505_RTC_PCUT_MAX_TIME_REG\n");
fail:
return count;
}
static ssize_t ab8505_powercut_restart_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_RESTART_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_RESTART_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0xF));
fail:
return ret;
}
static ssize_t ab8505_powercut_restart_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
int reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
reg_value = simple_strtoul(buf, NULL, 10);
if (reg_value > 0xF) {
dev_err(dev, "Incorrect parameter, echo 0 - 15 for number of restart\n");
goto fail;
}
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_RESTART_REG, (u8)reg_value);
if (ret < 0)
dev_err(dev, "Failed to set AB8505_RTC_PCUT_RESTART_REG\n");
fail:
return count;
}
static ssize_t ab8505_powercut_timer_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_TIME_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_TIME_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0x7F));
fail:
return ret;
}
static ssize_t ab8505_powercut_restart_counter_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_RESTART_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_RESTART_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0xF0) >> 4);
fail:
return ret;
}
static ssize_t ab8505_powercut_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_CTL_STATUS_REG, &reg_value);
if (ret < 0)
goto fail;
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0x1));
fail:
return ret;
}
static ssize_t ab8505_powercut_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
int reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
reg_value = simple_strtoul(buf, NULL, 10);
if (reg_value > 0x1) {
dev_err(dev, "Incorrect parameter, echo 0/1 to disable/enable Pcut feature\n");
goto fail;
}
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_CTL_STATUS_REG, (u8)reg_value);
if (ret < 0)
dev_err(dev, "Failed to set AB8505_RTC_PCUT_CTL_STATUS_REG\n");
fail:
return count;
}
static ssize_t ab8505_powercut_flag_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_CTL_STATUS_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_CTL_STATUS_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", ((reg_value & 0x10) >> 4));
fail:
return ret;
}
static ssize_t ab8505_powercut_debounce_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_DEBOUNCE_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_DEBOUNCE_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", (reg_value & 0x7));
fail:
return ret;
}
static ssize_t ab8505_powercut_debounce_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
int reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
reg_value = simple_strtoul(buf, NULL, 10);
if (reg_value > 0x7) {
dev_err(dev, "Incorrect parameter, echo 0 to 7 for debounce setting\n");
goto fail;
}
ret = abx500_set_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_DEBOUNCE_REG, (u8)reg_value);
if (ret < 0)
dev_err(dev, "Failed to set AB8505_RTC_PCUT_DEBOUNCE_REG\n");
fail:
return count;
}
static ssize_t ab8505_powercut_enable_status_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 reg_value;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
ret = abx500_get_register_interruptible(di->dev, AB8500_RTC,
AB8505_RTC_PCUT_CTL_STATUS_REG, &reg_value);
if (ret < 0) {
dev_err(dev, "Failed to read AB8505_RTC_PCUT_CTL_STATUS_REG\n");
goto fail;
}
return scnprintf(buf, PAGE_SIZE, "%d\n", ((reg_value & 0x20) >> 5));
fail:
return ret;
}
static int ab8500_fg_sysfs_psy_create_attrs(struct device *dev)
{
unsigned int i, j;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
if (((is_ab8505(di->parent) || is_ab9540(di->parent)) &&
abx500_get_chip_id(dev->parent) >= AB8500_CUT2P0)
|| is_ab8540(di->parent)) {
for (j = 0; j < ARRAY_SIZE(ab8505_fg_sysfs_psy_attrs); j++)
if (device_create_file(dev, &ab8505_fg_sysfs_psy_attrs[j]))
goto sysfs_psy_create_attrs_failed_ab8505;
}
return 0;
sysfs_psy_create_attrs_failed_ab8505:
dev_err(dev, "Failed creating sysfs psy attrs for ab8505.\n");
while (j--)
device_remove_file(dev, &ab8505_fg_sysfs_psy_attrs[i]);
return -EIO;
}
static void ab8500_fg_sysfs_psy_remove_attrs(struct device *dev)
{
unsigned int i;
struct power_supply *psy = dev_get_drvdata(dev);
struct ab8500_fg *di;
di = to_ab8500_fg_device_info(psy);
if (((is_ab8505(di->parent) || is_ab9540(di->parent)) &&
abx500_get_chip_id(dev->parent) >= AB8500_CUT2P0)
|| is_ab8540(di->parent)) {
for (i = 0; i < ARRAY_SIZE(ab8505_fg_sysfs_psy_attrs); i++)
(void)device_remove_file(dev, &ab8505_fg_sysfs_psy_attrs[i]);
}
}
static int ab8500_fg_resume(struct platform_device *pdev)
{
struct ab8500_fg *di = platform_get_drvdata(pdev);
if (!di->flags.charging) {
ab8500_fg_discharge_state_to(di, AB8500_FG_DISCHARGE_WAKEUP);
queue_work(di->fg_wq, &di->fg_work);
}
return 0;
}
static int ab8500_fg_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct ab8500_fg *di = platform_get_drvdata(pdev);
flush_delayed_work(&di->fg_periodic_work);
flush_work(&di->fg_work);
flush_work(&di->fg_acc_cur_work);
flush_delayed_work(&di->fg_reinit_work);
flush_delayed_work(&di->fg_low_bat_work);
flush_delayed_work(&di->fg_check_hw_failure_work);
if (di->flags.fg_enabled && !di->flags.charging)
ab8500_fg_coulomb_counter(di, false);
return 0;
}
static int ab8500_fg_remove(struct platform_device *pdev)
{
int ret = 0;
struct ab8500_fg *di = platform_get_drvdata(pdev);
list_del(&di->node);
ret = ab8500_fg_coulomb_counter(di, false);
if (ret)
dev_err(di->dev, "failed to disable coulomb counter\n");
destroy_workqueue(di->fg_wq);
ab8500_fg_sysfs_exit(di);
flush_scheduled_work();
ab8500_fg_sysfs_psy_remove_attrs(di->fg_psy.dev);
power_supply_unregister(&di->fg_psy);
return ret;
}
static int ab8500_fg_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct abx500_bm_data *plat = pdev->dev.platform_data;
struct ab8500_fg *di;
int i, irq;
int ret = 0;
di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
if (!di) {
dev_err(&pdev->dev, "%s no mem for ab8500_fg\n", __func__);
return -ENOMEM;
}
if (!plat) {
dev_err(&pdev->dev, "no battery management data supplied\n");
return -EINVAL;
}
di->bm = plat;
if (np) {
ret = ab8500_bm_of_probe(&pdev->dev, np, di->bm);
if (ret) {
dev_err(&pdev->dev, "failed to get battery information\n");
return ret;
}
}
mutex_init(&di->cc_lock);
di->dev = &pdev->dev;
di->parent = dev_get_drvdata(pdev->dev.parent);
di->gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
di->fg_psy.name = "ab8500_fg";
di->fg_psy.type = POWER_SUPPLY_TYPE_BATTERY;
di->fg_psy.properties = ab8500_fg_props;
di->fg_psy.num_properties = ARRAY_SIZE(ab8500_fg_props);
di->fg_psy.get_property = ab8500_fg_get_property;
di->fg_psy.supplied_to = supply_interface;
di->fg_psy.num_supplicants = ARRAY_SIZE(supply_interface),
di->fg_psy.external_power_changed = ab8500_fg_external_power_changed;
di->bat_cap.max_mah_design = MILLI_TO_MICRO *
di->bm->bat_type[di->bm->batt_id].charge_full_design;
di->bat_cap.max_mah = di->bat_cap.max_mah_design;
di->vbat_nom = di->bm->bat_type[di->bm->batt_id].nominal_voltage;
di->init_capacity = true;
ab8500_fg_charge_state_to(di, AB8500_FG_CHARGE_INIT);
ab8500_fg_discharge_state_to(di, AB8500_FG_DISCHARGE_INIT);
di->fg_wq = create_singlethread_workqueue("ab8500_fg_wq");
if (di->fg_wq == NULL) {
dev_err(di->dev, "failed to create work queue\n");
return -ENOMEM;
}
INIT_WORK(&di->fg_work, ab8500_fg_instant_work);
INIT_WORK(&di->fg_acc_cur_work, ab8500_fg_acc_cur_work);
INIT_DEFERRABLE_WORK(&di->fg_reinit_work,
ab8500_fg_reinit_work);
INIT_DEFERRABLE_WORK(&di->fg_periodic_work,
ab8500_fg_periodic_work);
INIT_DEFERRABLE_WORK(&di->fg_low_bat_work,
ab8500_fg_low_bat_work);
INIT_DEFERRABLE_WORK(&di->fg_check_hw_failure_work,
ab8500_fg_check_hw_failure_work);
di->flags.low_bat = false;
di->low_bat_cnt = 10;
ret = ab8500_fg_init_hw_registers(di);
if (ret) {
dev_err(di->dev, "failed to initialize registers\n");
goto free_inst_curr_wq;
}
di->flags.batt_unknown = true;
di->flags.batt_id_received = false;
ret = power_supply_register(di->dev, &di->fg_psy);
if (ret) {
dev_err(di->dev, "failed to register FG psy\n");
goto free_inst_curr_wq;
}
di->fg_samples = SEC_TO_SAMPLE(di->bm->fg_params->init_timer);
ab8500_fg_coulomb_counter(di, true);
init_completion(&di->ab8500_fg_started);
init_completion(&di->ab8500_fg_complete);
for (i = 0; i < ARRAY_SIZE(ab8500_fg_irq); i++) {
irq = platform_get_irq_byname(pdev, ab8500_fg_irq[i].name);
ret = request_threaded_irq(irq, NULL, ab8500_fg_irq[i].isr,
IRQF_SHARED | IRQF_NO_SUSPEND,
ab8500_fg_irq[i].name, di);
if (ret != 0) {
dev_err(di->dev, "failed to request %s IRQ %d: %d\n"
, ab8500_fg_irq[i].name, irq, ret);
goto free_irq;
}
dev_dbg(di->dev, "Requested %s IRQ %d: %d\n",
ab8500_fg_irq[i].name, irq, ret);
}
di->irq = platform_get_irq_byname(pdev, "CCEOC");
disable_irq(di->irq);
di->nbr_cceoc_irq_cnt = 0;
platform_set_drvdata(pdev, di);
ret = ab8500_fg_sysfs_init(di);
if (ret) {
dev_err(di->dev, "failed to create sysfs entry\n");
goto free_irq;
}
ret = ab8500_fg_sysfs_psy_create_attrs(di->fg_psy.dev);
if (ret) {
dev_err(di->dev, "failed to create FG psy\n");
ab8500_fg_sysfs_exit(di);
goto free_irq;
}
di->flags.calibrate = true;
di->calib_state = AB8500_FG_CALIB_INIT;
di->bat_temp = 210;
queue_delayed_work(di->fg_wq, &di->fg_periodic_work, 0);
list_add_tail(&di->node, &ab8500_fg_list);
return ret;
free_irq:
power_supply_unregister(&di->fg_psy);
for (i = i - 1; i >= 0; i--) {
irq = platform_get_irq_byname(pdev, ab8500_fg_irq[i].name);
free_irq(irq, di);
}
free_inst_curr_wq:
destroy_workqueue(di->fg_wq);
return ret;
}
static int __init ab8500_fg_init(void)
{
return platform_driver_register(&ab8500_fg_driver);
}
static void __exit ab8500_fg_exit(void)
{
platform_driver_unregister(&ab8500_fg_driver);
}
