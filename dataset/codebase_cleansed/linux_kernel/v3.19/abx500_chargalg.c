static enum hrtimer_restart
abx500_chargalg_safety_timer_expired(struct hrtimer *timer)
{
struct abx500_chargalg *di = container_of(timer, struct abx500_chargalg,
safety_timer);
dev_err(di->dev, "Safety timer expired\n");
di->events.safety_timer_expired = true;
queue_work(di->chargalg_wq, &di->chargalg_work);
return HRTIMER_NORESTART;
}
static enum hrtimer_restart
abx500_chargalg_maintenance_timer_expired(struct hrtimer *timer)
{
struct abx500_chargalg *di = container_of(timer, struct abx500_chargalg,
maintenance_timer);
dev_dbg(di->dev, "Maintenance timer expired\n");
di->events.maintenance_timer_expired = true;
queue_work(di->chargalg_wq, &di->chargalg_work);
return HRTIMER_NORESTART;
}
static void abx500_chargalg_state_to(struct abx500_chargalg *di,
enum abx500_chargalg_states state)
{
dev_dbg(di->dev,
"State changed: %s (From state: [%d] %s =to=> [%d] %s )\n",
di->charge_state == state ? "NO" : "YES",
di->charge_state,
states[di->charge_state],
state,
states[state]);
di->charge_state = state;
}
static int abx500_chargalg_check_charger_enable(struct abx500_chargalg *di)
{
switch (di->charge_state) {
case STATE_NORMAL:
case STATE_MAINTENANCE_A:
case STATE_MAINTENANCE_B:
break;
default:
return 0;
}
if (di->chg_info.charger_type & USB_CHG) {
return di->usb_chg->ops.check_enable(di->usb_chg,
di->bm->bat_type[di->bm->batt_id].normal_vol_lvl,
di->bm->bat_type[di->bm->batt_id].normal_cur_lvl);
} else if ((di->chg_info.charger_type & AC_CHG) &&
!(di->ac_chg->external)) {
return di->ac_chg->ops.check_enable(di->ac_chg,
di->bm->bat_type[di->bm->batt_id].normal_vol_lvl,
di->bm->bat_type[di->bm->batt_id].normal_cur_lvl);
}
return 0;
}
static int abx500_chargalg_check_charger_connection(struct abx500_chargalg *di)
{
if (di->chg_info.conn_chg != di->chg_info.prev_conn_chg ||
di->susp_status.suspended_change) {
if ((di->chg_info.conn_chg & AC_CHG) &&
!di->susp_status.ac_suspended) {
dev_dbg(di->dev, "Charging source is AC\n");
if (di->chg_info.charger_type != AC_CHG) {
di->chg_info.charger_type = AC_CHG;
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
}
} else if ((di->chg_info.conn_chg & USB_CHG) &&
!di->susp_status.usb_suspended) {
dev_dbg(di->dev, "Charging source is USB\n");
di->chg_info.charger_type = USB_CHG;
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
} else if (di->chg_info.conn_chg &&
(di->susp_status.ac_suspended ||
di->susp_status.usb_suspended)) {
dev_dbg(di->dev, "Charging is suspended\n");
di->chg_info.charger_type = NO_CHG;
abx500_chargalg_state_to(di, STATE_SUSPENDED_INIT);
} else {
dev_dbg(di->dev, "Charging source is OFF\n");
di->chg_info.charger_type = NO_CHG;
abx500_chargalg_state_to(di, STATE_HANDHELD_INIT);
}
di->chg_info.prev_conn_chg = di->chg_info.conn_chg;
di->susp_status.suspended_change = false;
}
return di->chg_info.conn_chg;
}
static void abx500_chargalg_check_current_step_status
(struct abx500_chargalg *di)
{
if (di->curr_status.curr_step_change)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
di->curr_status.curr_step_change = false;
}
static void abx500_chargalg_start_safety_timer(struct abx500_chargalg *di)
{
int timer_expiration = 0;
switch (di->chg_info.charger_type) {
case AC_CHG:
timer_expiration = di->bm->main_safety_tmr_h;
break;
case USB_CHG:
timer_expiration = di->bm->usb_safety_tmr_h;
break;
default:
dev_err(di->dev, "Unknown charger to charge from\n");
break;
}
di->events.safety_timer_expired = false;
hrtimer_set_expires_range(&di->safety_timer,
ktime_set(timer_expiration * ONE_HOUR_IN_SECONDS, 0),
ktime_set(FIVE_MINUTES_IN_SECONDS, 0));
hrtimer_start_expires(&di->safety_timer, HRTIMER_MODE_REL);
}
static void abx500_chargalg_stop_safety_timer(struct abx500_chargalg *di)
{
if (hrtimer_try_to_cancel(&di->safety_timer) >= 0)
di->events.safety_timer_expired = false;
}
static void abx500_chargalg_start_maintenance_timer(struct abx500_chargalg *di,
int duration)
{
hrtimer_set_expires_range(&di->maintenance_timer,
ktime_set(duration * ONE_HOUR_IN_SECONDS, 0),
ktime_set(FIVE_MINUTES_IN_SECONDS, 0));
di->events.maintenance_timer_expired = false;
hrtimer_start_expires(&di->maintenance_timer, HRTIMER_MODE_REL);
}
static void abx500_chargalg_stop_maintenance_timer(struct abx500_chargalg *di)
{
if (hrtimer_try_to_cancel(&di->maintenance_timer) >= 0)
di->events.maintenance_timer_expired = false;
}
static int abx500_chargalg_kick_watchdog(struct abx500_chargalg *di)
{
if (di->ac_chg && di->ac_chg->ops.kick_wd &&
di->chg_info.online_chg & AC_CHG) {
if (di->ac_chg->external &&
di->usb_chg && di->usb_chg->ops.kick_wd)
di->usb_chg->ops.kick_wd(di->usb_chg);
return di->ac_chg->ops.kick_wd(di->ac_chg);
}
else if (di->usb_chg && di->usb_chg->ops.kick_wd &&
di->chg_info.online_chg & USB_CHG)
return di->usb_chg->ops.kick_wd(di->usb_chg);
return -ENXIO;
}
static int abx500_chargalg_ac_en(struct abx500_chargalg *di, int enable,
int vset, int iset)
{
static int abx500_chargalg_ex_ac_enable_toggle;
if (!di->ac_chg || !di->ac_chg->ops.enable)
return -ENXIO;
if (di->ac_chg->max_out_volt)
vset = min(vset, di->ac_chg->max_out_volt);
if (di->ac_chg->max_out_curr)
iset = min(iset, di->ac_chg->max_out_curr);
di->chg_info.ac_iset = iset;
di->chg_info.ac_vset = vset;
if (enable && di->ac_chg->external &&
!abx500_chargalg_ex_ac_enable_toggle) {
blocking_notifier_call_chain(&charger_notifier_list,
0, di->dev);
abx500_chargalg_ex_ac_enable_toggle++;
}
return di->ac_chg->ops.enable(di->ac_chg, enable, vset, iset);
}
static int abx500_chargalg_usb_en(struct abx500_chargalg *di, int enable,
int vset, int iset)
{
if (!di->usb_chg || !di->usb_chg->ops.enable)
return -ENXIO;
if (di->usb_chg->max_out_volt)
vset = min(vset, di->usb_chg->max_out_volt);
if (di->usb_chg->max_out_curr)
iset = min(iset, di->usb_chg->max_out_curr);
di->chg_info.usb_iset = iset;
di->chg_info.usb_vset = vset;
return di->usb_chg->ops.enable(di->usb_chg, enable, vset, iset);
}
static int ab8540_chargalg_usb_pp_en(struct abx500_chargalg *di, bool enable)
{
if (!di->usb_chg || !di->usb_chg->ops.pp_enable)
return -ENXIO;
return di->usb_chg->ops.pp_enable(di->usb_chg, enable);
}
static int ab8540_chargalg_usb_pre_chg_en(struct abx500_chargalg *di,
bool enable)
{
if (!di->usb_chg || !di->usb_chg->ops.pre_chg_enable)
return -ENXIO;
return di->usb_chg->ops.pre_chg_enable(di->usb_chg, enable);
}
static int abx500_chargalg_update_chg_curr(struct abx500_chargalg *di,
int iset)
{
if (di->ac_chg && di->ac_chg->ops.update_curr &&
di->chg_info.charger_type & AC_CHG) {
if (di->ac_chg->max_out_curr)
iset = min(iset, di->ac_chg->max_out_curr);
di->chg_info.ac_iset = iset;
return di->ac_chg->ops.update_curr(di->ac_chg, iset);
} else if (di->usb_chg && di->usb_chg->ops.update_curr &&
di->chg_info.charger_type & USB_CHG) {
if (di->usb_chg->max_out_curr)
iset = min(iset, di->usb_chg->max_out_curr);
di->chg_info.usb_iset = iset;
return di->usb_chg->ops.update_curr(di->usb_chg, iset);
}
return -ENXIO;
}
static void abx500_chargalg_stop_charging(struct abx500_chargalg *di)
{
abx500_chargalg_ac_en(di, false, 0, 0);
abx500_chargalg_usb_en(di, false, 0, 0);
abx500_chargalg_stop_safety_timer(di);
abx500_chargalg_stop_maintenance_timer(di);
di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
di->maintenance_chg = false;
cancel_delayed_work(&di->chargalg_wd_work);
power_supply_changed(&di->chargalg_psy);
}
static void abx500_chargalg_hold_charging(struct abx500_chargalg *di)
{
abx500_chargalg_ac_en(di, false, 0, 0);
abx500_chargalg_usb_en(di, false, 0, 0);
abx500_chargalg_stop_safety_timer(di);
abx500_chargalg_stop_maintenance_timer(di);
di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
di->maintenance_chg = false;
cancel_delayed_work(&di->chargalg_wd_work);
power_supply_changed(&di->chargalg_psy);
}
static void abx500_chargalg_start_charging(struct abx500_chargalg *di,
int vset, int iset)
{
switch (di->chg_info.charger_type) {
case AC_CHG:
dev_dbg(di->dev,
"AC parameters: Vset %d, Ich %d\n", vset, iset);
abx500_chargalg_usb_en(di, false, 0, 0);
abx500_chargalg_ac_en(di, true, vset, iset);
break;
case USB_CHG:
dev_dbg(di->dev,
"USB parameters: Vset %d, Ich %d\n", vset, iset);
abx500_chargalg_ac_en(di, false, 0, 0);
abx500_chargalg_usb_en(di, true, vset, iset);
break;
default:
dev_err(di->dev, "Unknown charger to charge from\n");
break;
}
}
static void abx500_chargalg_check_temp(struct abx500_chargalg *di)
{
if (di->batt_data.temp > (di->bm->temp_low + di->t_hyst_norm) &&
di->batt_data.temp < (di->bm->temp_high - di->t_hyst_norm)) {
di->events.btemp_underover = false;
di->events.btemp_lowhigh = false;
di->t_hyst_norm = 0;
di->t_hyst_lowhigh = 0;
} else {
if (((di->batt_data.temp >= di->bm->temp_high) &&
(di->batt_data.temp <
(di->bm->temp_over - di->t_hyst_lowhigh))) ||
((di->batt_data.temp >
(di->bm->temp_under + di->t_hyst_lowhigh)) &&
(di->batt_data.temp <= di->bm->temp_low))) {
di->events.btemp_underover = false;
di->events.btemp_lowhigh = true;
di->t_hyst_norm = di->bm->temp_hysteresis;
di->t_hyst_lowhigh = 0;
} else if (di->batt_data.temp <= di->bm->temp_under ||
di->batt_data.temp >= di->bm->temp_over) {
di->events.btemp_underover = true;
di->events.btemp_lowhigh = false;
di->t_hyst_norm = 0;
di->t_hyst_lowhigh = di->bm->temp_hysteresis;
} else {
dev_dbg(di->dev, "Within hysteresis limit temp: %d "
"hyst_lowhigh %d, hyst normal %d\n",
di->batt_data.temp, di->t_hyst_lowhigh,
di->t_hyst_norm);
}
}
}
static void abx500_chargalg_check_charger_voltage(struct abx500_chargalg *di)
{
if (di->chg_info.usb_volt > di->bm->chg_params->usb_volt_max)
di->chg_info.usb_chg_ok = false;
else
di->chg_info.usb_chg_ok = true;
if (di->chg_info.ac_volt > di->bm->chg_params->ac_volt_max)
di->chg_info.ac_chg_ok = false;
else
di->chg_info.ac_chg_ok = true;
}
static void abx500_chargalg_end_of_charge(struct abx500_chargalg *di)
{
if (di->charge_status == POWER_SUPPLY_STATUS_CHARGING &&
di->charge_state == STATE_NORMAL &&
!di->maintenance_chg && (di->batt_data.volt >=
di->bm->bat_type[di->bm->batt_id].termination_vol ||
di->events.usb_cv_active || di->events.ac_cv_active) &&
di->batt_data.avg_curr <
di->bm->bat_type[di->bm->batt_id].termination_curr &&
di->batt_data.avg_curr > 0) {
if (++di->eoc_cnt >= EOC_COND_CNT) {
di->eoc_cnt = 0;
if ((di->chg_info.charger_type & USB_CHG) &&
(di->usb_chg->power_path))
ab8540_chargalg_usb_pp_en(di, true);
di->charge_status = POWER_SUPPLY_STATUS_FULL;
di->maintenance_chg = true;
dev_dbg(di->dev, "EOC reached!\n");
power_supply_changed(&di->chargalg_psy);
} else {
dev_dbg(di->dev,
" EOC limit reached for the %d"
" time, out of %d before EOC\n",
di->eoc_cnt,
EOC_COND_CNT);
}
} else {
di->eoc_cnt = 0;
}
}
static void init_maxim_chg_curr(struct abx500_chargalg *di)
{
di->ccm.original_iset =
di->bm->bat_type[di->bm->batt_id].normal_cur_lvl;
di->ccm.current_iset =
di->bm->bat_type[di->bm->batt_id].normal_cur_lvl;
di->ccm.test_delta_i = di->bm->maxi->charger_curr_step;
di->ccm.max_current = di->bm->maxi->chg_curr;
di->ccm.condition_cnt = di->bm->maxi->wait_cycles;
di->ccm.level = 0;
}
static enum maxim_ret abx500_chargalg_chg_curr_maxim(struct abx500_chargalg *di)
{
int delta_i;
if (!di->bm->maxi->ena_maxi)
return MAXIM_RET_NOACTION;
delta_i = di->ccm.original_iset - di->batt_data.inst_curr;
if (di->events.vbus_collapsed) {
dev_dbg(di->dev, "Charger voltage has collapsed %d\n",
di->ccm.wait_cnt);
if (di->ccm.wait_cnt == 0) {
dev_dbg(di->dev, "lowering current\n");
di->ccm.wait_cnt++;
di->ccm.condition_cnt = di->bm->maxi->wait_cycles;
di->ccm.max_current =
di->ccm.current_iset - di->ccm.test_delta_i;
di->ccm.current_iset = di->ccm.max_current;
di->ccm.level--;
return MAXIM_RET_CHANGE;
} else {
dev_dbg(di->dev, "waiting\n");
di->ccm.wait_cnt = (di->ccm.wait_cnt + 1) % 3;
return MAXIM_RET_NOACTION;
}
}
di->ccm.wait_cnt = 0;
if ((di->batt_data.inst_curr > di->ccm.original_iset)) {
dev_dbg(di->dev, " Maximization Ibat (%dmA) too high"
" (limit %dmA) (current iset: %dmA)!\n",
di->batt_data.inst_curr, di->ccm.original_iset,
di->ccm.current_iset);
if (di->ccm.current_iset == di->ccm.original_iset)
return MAXIM_RET_NOACTION;
di->ccm.condition_cnt = di->bm->maxi->wait_cycles;
di->ccm.current_iset = di->ccm.original_iset;
di->ccm.level = 0;
return MAXIM_RET_IBAT_TOO_HIGH;
}
if (delta_i > di->ccm.test_delta_i &&
(di->ccm.current_iset + di->ccm.test_delta_i) <
di->ccm.max_current) {
if (di->ccm.condition_cnt-- == 0) {
di->ccm.condition_cnt = di->bm->maxi->wait_cycles;
di->ccm.current_iset += di->ccm.test_delta_i;
di->ccm.level++;
dev_dbg(di->dev, " Maximization needed, increase"
" with %d mA to %dmA (Optimal ibat: %d)"
" Level %d\n",
di->ccm.test_delta_i,
di->ccm.current_iset,
di->ccm.original_iset,
di->ccm.level);
return MAXIM_RET_CHANGE;
} else {
return MAXIM_RET_NOACTION;
}
} else {
di->ccm.condition_cnt = di->bm->maxi->wait_cycles;
return MAXIM_RET_NOACTION;
}
}
static void handle_maxim_chg_curr(struct abx500_chargalg *di)
{
enum maxim_ret ret;
int result;
ret = abx500_chargalg_chg_curr_maxim(di);
switch (ret) {
case MAXIM_RET_CHANGE:
result = abx500_chargalg_update_chg_curr(di,
di->ccm.current_iset);
if (result)
dev_err(di->dev, "failed to set chg curr\n");
break;
case MAXIM_RET_IBAT_TOO_HIGH:
result = abx500_chargalg_update_chg_curr(di,
di->bm->bat_type[di->bm->batt_id].normal_cur_lvl);
if (result)
dev_err(di->dev, "failed to set chg curr\n");
break;
case MAXIM_RET_NOACTION:
default:
break;
}
}
static int abx500_chargalg_get_ext_psy_data(struct device *dev, void *data)
{
struct power_supply *psy;
struct power_supply *ext;
struct abx500_chargalg *di;
union power_supply_propval ret;
int i, j;
bool psy_found = false;
bool capacity_updated = false;
psy = (struct power_supply *)data;
ext = dev_get_drvdata(dev);
di = to_abx500_chargalg_device_info(psy);
for (i = 0; i < ext->num_supplicants; i++) {
if (!strcmp(ext->supplied_to[i], psy->name))
psy_found = true;
}
if (!psy_found)
return 0;
if (!ext->get_property(ext, POWER_SUPPLY_PROP_CAPACITY, &ret)) {
di->batt_data.percent = ret.intval;
capacity_updated = true;
}
for (j = 0; j < ext->num_properties; j++) {
enum power_supply_property prop;
prop = ext->properties[j];
if (!di->ac_chg &&
ext->type == POWER_SUPPLY_TYPE_MAINS)
di->ac_chg = psy_to_ux500_charger(ext);
else if (!di->usb_chg &&
ext->type == POWER_SUPPLY_TYPE_USB)
di->usb_chg = psy_to_ux500_charger(ext);
if (ext->get_property(ext, prop, &ret))
continue;
switch (prop) {
case POWER_SUPPLY_PROP_PRESENT:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
if (ret.intval)
di->events.batt_rem = false;
else
di->events.batt_rem = true;
break;
case POWER_SUPPLY_TYPE_MAINS:
if (!ret.intval &&
(di->chg_info.conn_chg & AC_CHG)) {
di->chg_info.prev_conn_chg =
di->chg_info.conn_chg;
di->chg_info.conn_chg &= ~AC_CHG;
}
else if (ret.intval &&
!(di->chg_info.conn_chg & AC_CHG)) {
di->chg_info.prev_conn_chg =
di->chg_info.conn_chg;
di->chg_info.conn_chg |= AC_CHG;
}
break;
case POWER_SUPPLY_TYPE_USB:
if (!ret.intval &&
(di->chg_info.conn_chg & USB_CHG)) {
di->chg_info.prev_conn_chg =
di->chg_info.conn_chg;
di->chg_info.conn_chg &= ~USB_CHG;
}
else if (ret.intval &&
!(di->chg_info.conn_chg & USB_CHG)) {
di->chg_info.prev_conn_chg =
di->chg_info.conn_chg;
di->chg_info.conn_chg |= USB_CHG;
}
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_ONLINE:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
break;
case POWER_SUPPLY_TYPE_MAINS:
if (!ret.intval &&
(di->chg_info.online_chg & AC_CHG)) {
di->chg_info.prev_online_chg =
di->chg_info.online_chg;
di->chg_info.online_chg &= ~AC_CHG;
}
else if (ret.intval &&
!(di->chg_info.online_chg & AC_CHG)) {
di->chg_info.prev_online_chg =
di->chg_info.online_chg;
di->chg_info.online_chg |= AC_CHG;
queue_delayed_work(di->chargalg_wq,
&di->chargalg_wd_work, 0);
}
break;
case POWER_SUPPLY_TYPE_USB:
if (!ret.intval &&
(di->chg_info.online_chg & USB_CHG)) {
di->chg_info.prev_online_chg =
di->chg_info.online_chg;
di->chg_info.online_chg &= ~USB_CHG;
}
else if (ret.intval &&
!(di->chg_info.online_chg & USB_CHG)) {
di->chg_info.prev_online_chg =
di->chg_info.online_chg;
di->chg_info.online_chg |= USB_CHG;
queue_delayed_work(di->chargalg_wq,
&di->chargalg_wd_work, 0);
}
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_HEALTH:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
break;
case POWER_SUPPLY_TYPE_MAINS:
switch (ret.intval) {
case POWER_SUPPLY_HEALTH_UNSPEC_FAILURE:
di->events.mainextchnotok = true;
di->events.main_thermal_prot = false;
di->events.main_ovv = false;
di->events.ac_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_DEAD:
di->events.ac_wd_expired = true;
di->events.mainextchnotok = false;
di->events.main_ovv = false;
di->events.main_thermal_prot = false;
break;
case POWER_SUPPLY_HEALTH_COLD:
case POWER_SUPPLY_HEALTH_OVERHEAT:
di->events.main_thermal_prot = true;
di->events.mainextchnotok = false;
di->events.main_ovv = false;
di->events.ac_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_OVERVOLTAGE:
di->events.main_ovv = true;
di->events.mainextchnotok = false;
di->events.main_thermal_prot = false;
di->events.ac_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_GOOD:
di->events.main_thermal_prot = false;
di->events.mainextchnotok = false;
di->events.main_ovv = false;
di->events.ac_wd_expired = false;
break;
default:
break;
}
break;
case POWER_SUPPLY_TYPE_USB:
switch (ret.intval) {
case POWER_SUPPLY_HEALTH_UNSPEC_FAILURE:
di->events.usbchargernotok = true;
di->events.usb_thermal_prot = false;
di->events.vbus_ovv = false;
di->events.usb_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_DEAD:
di->events.usb_wd_expired = true;
di->events.usbchargernotok = false;
di->events.usb_thermal_prot = false;
di->events.vbus_ovv = false;
break;
case POWER_SUPPLY_HEALTH_COLD:
case POWER_SUPPLY_HEALTH_OVERHEAT:
di->events.usb_thermal_prot = true;
di->events.usbchargernotok = false;
di->events.vbus_ovv = false;
di->events.usb_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_OVERVOLTAGE:
di->events.vbus_ovv = true;
di->events.usbchargernotok = false;
di->events.usb_thermal_prot = false;
di->events.usb_wd_expired = false;
break;
case POWER_SUPPLY_HEALTH_GOOD:
di->events.usbchargernotok = false;
di->events.usb_thermal_prot = false;
di->events.vbus_ovv = false;
di->events.usb_wd_expired = false;
break;
default:
break;
}
default:
break;
}
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
di->batt_data.volt = ret.intval / 1000;
break;
case POWER_SUPPLY_TYPE_MAINS:
di->chg_info.ac_volt = ret.intval / 1000;
break;
case POWER_SUPPLY_TYPE_USB:
di->chg_info.usb_volt = ret.intval / 1000;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
switch (ext->type) {
case POWER_SUPPLY_TYPE_MAINS:
if (ret.intval)
di->events.ac_cv_active = true;
else
di->events.ac_cv_active = false;
break;
case POWER_SUPPLY_TYPE_USB:
if (ret.intval)
di->events.usb_cv_active = true;
else
di->events.usb_cv_active = false;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
if (ret.intval)
di->events.batt_unknown = false;
else
di->events.batt_unknown = true;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_TEMP:
di->batt_data.temp = ret.intval / 10;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
switch (ext->type) {
case POWER_SUPPLY_TYPE_MAINS:
di->chg_info.ac_curr =
ret.intval / 1000;
break;
case POWER_SUPPLY_TYPE_USB:
di->chg_info.usb_curr =
ret.intval / 1000;
break;
case POWER_SUPPLY_TYPE_BATTERY:
di->batt_data.inst_curr = ret.intval / 1000;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
switch (ext->type) {
case POWER_SUPPLY_TYPE_BATTERY:
di->batt_data.avg_curr = ret.intval / 1000;
break;
case POWER_SUPPLY_TYPE_USB:
if (ret.intval)
di->events.vbus_collapsed = true;
else
di->events.vbus_collapsed = false;
break;
default:
break;
}
break;
case POWER_SUPPLY_PROP_CAPACITY:
if (!capacity_updated)
di->batt_data.percent = ret.intval;
break;
default:
break;
}
}
return 0;
}
static void abx500_chargalg_external_power_changed(struct power_supply *psy)
{
struct abx500_chargalg *di = to_abx500_chargalg_device_info(psy);
queue_work(di->chargalg_wq, &di->chargalg_work);
}
static void abx500_chargalg_algorithm(struct abx500_chargalg *di)
{
int charger_status;
int ret;
int curr_step_lvl;
class_for_each_device(power_supply_class, NULL,
&di->chargalg_psy, abx500_chargalg_get_ext_psy_data);
abx500_chargalg_end_of_charge(di);
abx500_chargalg_check_temp(di);
abx500_chargalg_check_charger_voltage(di);
charger_status = abx500_chargalg_check_charger_connection(di);
abx500_chargalg_check_current_step_status(di);
if (is_ab8500(di->parent)) {
ret = abx500_chargalg_check_charger_enable(di);
if (ret < 0)
dev_err(di->dev, "Checking charger is enabled error"
": Returned Value %d\n", ret);
}
if (!charger_status ||
(di->events.batt_unknown && !di->bm->chg_unknown_bat)) {
if (di->charge_state != STATE_HANDHELD) {
di->events.safety_timer_expired = false;
abx500_chargalg_state_to(di, STATE_HANDHELD_INIT);
}
}
else if (di->charge_state == STATE_SUSPENDED_INIT ||
di->charge_state == STATE_SUSPENDED) {
}
else if (di->events.safety_timer_expired) {
if (di->charge_state != STATE_SAFETY_TIMER_EXPIRED)
abx500_chargalg_state_to(di,
STATE_SAFETY_TIMER_EXPIRED_INIT);
}
else if (di->events.batt_rem) {
if (di->charge_state != STATE_BATT_REMOVED)
abx500_chargalg_state_to(di, STATE_BATT_REMOVED_INIT);
}
else if (di->events.mainextchnotok || di->events.usbchargernotok) {
if (di->charge_state != STATE_CHG_NOT_OK &&
!di->events.vbus_collapsed)
abx500_chargalg_state_to(di, STATE_CHG_NOT_OK_INIT);
}
else if (di->events.vbus_ovv ||
di->events.main_ovv ||
di->events.batt_ovv ||
!di->chg_info.usb_chg_ok ||
!di->chg_info.ac_chg_ok) {
if (di->charge_state != STATE_OVV_PROTECT)
abx500_chargalg_state_to(di, STATE_OVV_PROTECT_INIT);
}
else if (di->events.main_thermal_prot ||
di->events.usb_thermal_prot) {
if (di->charge_state != STATE_HW_TEMP_PROTECT)
abx500_chargalg_state_to(di,
STATE_HW_TEMP_PROTECT_INIT);
}
else if (di->events.btemp_underover) {
if (di->charge_state != STATE_TEMP_UNDEROVER)
abx500_chargalg_state_to(di,
STATE_TEMP_UNDEROVER_INIT);
}
else if (di->events.ac_wd_expired ||
di->events.usb_wd_expired) {
if (di->charge_state != STATE_WD_EXPIRED)
abx500_chargalg_state_to(di, STATE_WD_EXPIRED_INIT);
}
else if (di->events.btemp_lowhigh) {
if (di->charge_state != STATE_TEMP_LOWHIGH)
abx500_chargalg_state_to(di, STATE_TEMP_LOWHIGH_INIT);
}
dev_dbg(di->dev,
"[CHARGALG] Vb %d Ib_avg %d Ib_inst %d Tb %d Cap %d Maint %d "
"State %s Active_chg %d Chg_status %d AC %d USB %d "
"AC_online %d USB_online %d AC_CV %d USB_CV %d AC_I %d "
"USB_I %d AC_Vset %d AC_Iset %d USB_Vset %d USB_Iset %d\n",
di->batt_data.volt,
di->batt_data.avg_curr,
di->batt_data.inst_curr,
di->batt_data.temp,
di->batt_data.percent,
di->maintenance_chg,
states[di->charge_state],
di->chg_info.charger_type,
di->charge_status,
di->chg_info.conn_chg & AC_CHG,
di->chg_info.conn_chg & USB_CHG,
di->chg_info.online_chg & AC_CHG,
di->chg_info.online_chg & USB_CHG,
di->events.ac_cv_active,
di->events.usb_cv_active,
di->chg_info.ac_curr,
di->chg_info.usb_curr,
di->chg_info.ac_vset,
di->chg_info.ac_iset,
di->chg_info.usb_vset,
di->chg_info.usb_iset);
switch (di->charge_state) {
case STATE_HANDHELD_INIT:
abx500_chargalg_stop_charging(di);
di->charge_status = POWER_SUPPLY_STATUS_DISCHARGING;
abx500_chargalg_state_to(di, STATE_HANDHELD);
case STATE_HANDHELD:
break;
case STATE_SUSPENDED_INIT:
if (di->susp_status.ac_suspended)
abx500_chargalg_ac_en(di, false, 0, 0);
if (di->susp_status.usb_suspended)
abx500_chargalg_usb_en(di, false, 0, 0);
abx500_chargalg_stop_safety_timer(di);
abx500_chargalg_stop_maintenance_timer(di);
di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
di->maintenance_chg = false;
abx500_chargalg_state_to(di, STATE_SUSPENDED);
power_supply_changed(&di->chargalg_psy);
case STATE_SUSPENDED:
break;
case STATE_BATT_REMOVED_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_BATT_REMOVED);
case STATE_BATT_REMOVED:
if (!di->events.batt_rem)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_HW_TEMP_PROTECT_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_HW_TEMP_PROTECT);
case STATE_HW_TEMP_PROTECT:
if (!di->events.main_thermal_prot &&
!di->events.usb_thermal_prot)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_OVV_PROTECT_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_OVV_PROTECT);
case STATE_OVV_PROTECT:
if (!di->events.vbus_ovv &&
!di->events.main_ovv &&
!di->events.batt_ovv &&
di->chg_info.usb_chg_ok &&
di->chg_info.ac_chg_ok)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_CHG_NOT_OK_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_CHG_NOT_OK);
case STATE_CHG_NOT_OK:
if (!di->events.mainextchnotok &&
!di->events.usbchargernotok)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_SAFETY_TIMER_EXPIRED_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_SAFETY_TIMER_EXPIRED);
case STATE_SAFETY_TIMER_EXPIRED:
break;
case STATE_NORMAL_INIT:
if ((di->chg_info.charger_type & USB_CHG) &&
di->usb_chg->power_path) {
if (di->batt_data.volt >
(di->bm->fg_params->lowbat_threshold +
BAT_PLUS_MARGIN)) {
ab8540_chargalg_usb_pre_chg_en(di, false);
ab8540_chargalg_usb_pp_en(di, false);
} else {
ab8540_chargalg_usb_pp_en(di, true);
ab8540_chargalg_usb_pre_chg_en(di, true);
abx500_chargalg_state_to(di,
STATE_USB_PP_PRE_CHARGE);
break;
}
}
if (di->curr_status.curr_step == CHARGALG_CURR_STEP_LOW)
abx500_chargalg_stop_charging(di);
else {
curr_step_lvl = di->bm->bat_type[
di->bm->batt_id].normal_cur_lvl
* di->curr_status.curr_step
/ CHARGALG_CURR_STEP_HIGH;
abx500_chargalg_start_charging(di,
di->bm->bat_type[di->bm->batt_id]
.normal_vol_lvl, curr_step_lvl);
}
abx500_chargalg_state_to(di, STATE_NORMAL);
abx500_chargalg_start_safety_timer(di);
abx500_chargalg_stop_maintenance_timer(di);
init_maxim_chg_curr(di);
di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
di->eoc_cnt = 0;
di->maintenance_chg = false;
power_supply_changed(&di->chargalg_psy);
break;
case STATE_USB_PP_PRE_CHARGE:
if (di->batt_data.volt >
(di->bm->fg_params->lowbat_threshold +
BAT_PLUS_MARGIN))
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_NORMAL:
handle_maxim_chg_curr(di);
if (di->charge_status == POWER_SUPPLY_STATUS_FULL &&
di->maintenance_chg) {
if (di->bm->no_maintenance)
abx500_chargalg_state_to(di,
STATE_WAIT_FOR_RECHARGE_INIT);
else
abx500_chargalg_state_to(di,
STATE_MAINTENANCE_A_INIT);
}
break;
case STATE_WAIT_FOR_RECHARGE_INIT:
abx500_chargalg_hold_charging(di);
abx500_chargalg_state_to(di, STATE_WAIT_FOR_RECHARGE);
case STATE_WAIT_FOR_RECHARGE:
if (di->batt_data.percent <=
di->bm->bat_type[di->bm->batt_id].
recharge_cap)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_MAINTENANCE_A_INIT:
abx500_chargalg_stop_safety_timer(di);
abx500_chargalg_start_maintenance_timer(di,
di->bm->bat_type[
di->bm->batt_id].maint_a_chg_timer_h);
abx500_chargalg_start_charging(di,
di->bm->bat_type[
di->bm->batt_id].maint_a_vol_lvl,
di->bm->bat_type[
di->bm->batt_id].maint_a_cur_lvl);
abx500_chargalg_state_to(di, STATE_MAINTENANCE_A);
power_supply_changed(&di->chargalg_psy);
case STATE_MAINTENANCE_A:
if (di->events.maintenance_timer_expired) {
abx500_chargalg_stop_maintenance_timer(di);
abx500_chargalg_state_to(di, STATE_MAINTENANCE_B_INIT);
}
break;
case STATE_MAINTENANCE_B_INIT:
abx500_chargalg_start_maintenance_timer(di,
di->bm->bat_type[
di->bm->batt_id].maint_b_chg_timer_h);
abx500_chargalg_start_charging(di,
di->bm->bat_type[
di->bm->batt_id].maint_b_vol_lvl,
di->bm->bat_type[
di->bm->batt_id].maint_b_cur_lvl);
abx500_chargalg_state_to(di, STATE_MAINTENANCE_B);
power_supply_changed(&di->chargalg_psy);
case STATE_MAINTENANCE_B:
if (di->events.maintenance_timer_expired) {
abx500_chargalg_stop_maintenance_timer(di);
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
}
break;
case STATE_TEMP_LOWHIGH_INIT:
abx500_chargalg_start_charging(di,
di->bm->bat_type[
di->bm->batt_id].low_high_vol_lvl,
di->bm->bat_type[
di->bm->batt_id].low_high_cur_lvl);
abx500_chargalg_stop_maintenance_timer(di);
di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
abx500_chargalg_state_to(di, STATE_TEMP_LOWHIGH);
power_supply_changed(&di->chargalg_psy);
case STATE_TEMP_LOWHIGH:
if (!di->events.btemp_lowhigh)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_WD_EXPIRED_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_WD_EXPIRED);
case STATE_WD_EXPIRED:
if (!di->events.ac_wd_expired &&
!di->events.usb_wd_expired)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
case STATE_TEMP_UNDEROVER_INIT:
abx500_chargalg_stop_charging(di);
abx500_chargalg_state_to(di, STATE_TEMP_UNDEROVER);
case STATE_TEMP_UNDEROVER:
if (!di->events.btemp_underover)
abx500_chargalg_state_to(di, STATE_NORMAL_INIT);
break;
}
if (di->charge_state == STATE_NORMAL_INIT ||
di->charge_state == STATE_MAINTENANCE_A_INIT ||
di->charge_state == STATE_MAINTENANCE_B_INIT)
queue_work(di->chargalg_wq, &di->chargalg_work);
}
static void abx500_chargalg_periodic_work(struct work_struct *work)
{
struct abx500_chargalg *di = container_of(work,
struct abx500_chargalg, chargalg_periodic_work.work);
abx500_chargalg_algorithm(di);
if (di->chg_info.conn_chg)
queue_delayed_work(di->chargalg_wq,
&di->chargalg_periodic_work,
di->bm->interval_charging * HZ);
else
queue_delayed_work(di->chargalg_wq,
&di->chargalg_periodic_work,
di->bm->interval_not_charging * HZ);
}
static void abx500_chargalg_wd_work(struct work_struct *work)
{
int ret;
struct abx500_chargalg *di = container_of(work,
struct abx500_chargalg, chargalg_wd_work.work);
dev_dbg(di->dev, "abx500_chargalg_wd_work\n");
ret = abx500_chargalg_kick_watchdog(di);
if (ret < 0)
dev_err(di->dev, "failed to kick watchdog\n");
queue_delayed_work(di->chargalg_wq,
&di->chargalg_wd_work, CHG_WD_INTERVAL);
}
static void abx500_chargalg_work(struct work_struct *work)
{
struct abx500_chargalg *di = container_of(work,
struct abx500_chargalg, chargalg_work);
abx500_chargalg_algorithm(di);
}
static int abx500_chargalg_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct abx500_chargalg *di;
di = to_abx500_chargalg_device_info(psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = di->charge_status;
break;
case POWER_SUPPLY_PROP_HEALTH:
if (di->events.batt_ovv) {
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
} else if (di->events.btemp_underover) {
if (di->batt_data.temp <= di->bm->temp_under)
val->intval = POWER_SUPPLY_HEALTH_COLD;
else
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
} else if (di->charge_state == STATE_SAFETY_TIMER_EXPIRED ||
di->charge_state == STATE_SAFETY_TIMER_EXPIRED_INIT) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
} else {
val->intval = POWER_SUPPLY_HEALTH_GOOD;
}
break;
default:
return -EINVAL;
}
return 0;
}
static ssize_t abx500_chargalg_curr_step_show(struct abx500_chargalg *di,
char *buf)
{
return sprintf(buf, "%d\n", di->curr_status.curr_step);
}
static ssize_t abx500_chargalg_curr_step_store(struct abx500_chargalg *di,
const char *buf, size_t length)
{
long int param;
int ret;
ret = kstrtol(buf, 10, &param);
if (ret < 0)
return ret;
di->curr_status.curr_step = param;
if (di->curr_status.curr_step >= CHARGALG_CURR_STEP_LOW &&
di->curr_status.curr_step <= CHARGALG_CURR_STEP_HIGH) {
di->curr_status.curr_step_change = true;
queue_work(di->chargalg_wq, &di->chargalg_work);
} else
dev_info(di->dev, "Wrong current step\n"
"Enter 0. Disable AC/USB Charging\n"
"1--100. Set AC/USB charging current step\n"
"100. Enable AC/USB Charging\n");
return strlen(buf);
}
static ssize_t abx500_chargalg_en_show(struct abx500_chargalg *di,
char *buf)
{
return sprintf(buf, "%d\n",
di->susp_status.ac_suspended &&
di->susp_status.usb_suspended);
}
static ssize_t abx500_chargalg_en_store(struct abx500_chargalg *di,
const char *buf, size_t length)
{
long int param;
int ac_usb;
int ret;
ret = kstrtol(buf, 10, &param);
if (ret < 0)
return ret;
ac_usb = param;
switch (ac_usb) {
case 0:
di->susp_status.ac_suspended = true;
di->susp_status.usb_suspended = true;
di->susp_status.suspended_change = true;
queue_work(di->chargalg_wq,
&di->chargalg_work);
break;
case 1:
di->susp_status.ac_suspended = false;
di->susp_status.suspended_change = true;
queue_work(di->chargalg_wq,
&di->chargalg_work);
break;
case 2:
di->susp_status.usb_suspended = false;
di->susp_status.suspended_change = true;
queue_work(di->chargalg_wq,
&di->chargalg_work);
break;
default:
dev_info(di->dev, "Wrong input\n"
"Enter 0. Disable AC/USB Charging\n"
"1. Enable AC charging\n"
"2. Enable USB Charging\n");
};
return strlen(buf);
}
static ssize_t abx500_chargalg_sysfs_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct abx500_chargalg_sysfs_entry *entry = container_of(attr,
struct abx500_chargalg_sysfs_entry, attr);
struct abx500_chargalg *di = container_of(kobj,
struct abx500_chargalg, chargalg_kobject);
if (!entry->show)
return -EIO;
return entry->show(di, buf);
}
static ssize_t abx500_chargalg_sysfs_charger(struct kobject *kobj,
struct attribute *attr, const char *buf, size_t length)
{
struct abx500_chargalg_sysfs_entry *entry = container_of(attr,
struct abx500_chargalg_sysfs_entry, attr);
struct abx500_chargalg *di = container_of(kobj,
struct abx500_chargalg, chargalg_kobject);
if (!entry->store)
return -EIO;
return entry->store(di, buf, length);
}
static void abx500_chargalg_sysfs_exit(struct abx500_chargalg *di)
{
kobject_del(&di->chargalg_kobject);
}
static int abx500_chargalg_sysfs_init(struct abx500_chargalg *di)
{
int ret = 0;
ret = kobject_init_and_add(&di->chargalg_kobject,
&abx500_chargalg_ktype,
NULL, "abx500_chargalg");
if (ret < 0)
dev_err(di->dev, "failed to create sysfs entry\n");
return ret;
}
static int abx500_chargalg_resume(struct platform_device *pdev)
{
struct abx500_chargalg *di = platform_get_drvdata(pdev);
if (di->chg_info.online_chg)
queue_delayed_work(di->chargalg_wq, &di->chargalg_wd_work, 0);
queue_delayed_work(di->chargalg_wq, &di->chargalg_periodic_work, 0);
return 0;
}
static int abx500_chargalg_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct abx500_chargalg *di = platform_get_drvdata(pdev);
if (di->chg_info.online_chg)
cancel_delayed_work_sync(&di->chargalg_wd_work);
cancel_delayed_work_sync(&di->chargalg_periodic_work);
return 0;
}
static int abx500_chargalg_remove(struct platform_device *pdev)
{
struct abx500_chargalg *di = platform_get_drvdata(pdev);
abx500_chargalg_sysfs_exit(di);
hrtimer_cancel(&di->safety_timer);
hrtimer_cancel(&di->maintenance_timer);
cancel_delayed_work_sync(&di->chargalg_periodic_work);
cancel_delayed_work_sync(&di->chargalg_wd_work);
cancel_work_sync(&di->chargalg_work);
destroy_workqueue(di->chargalg_wq);
power_supply_unregister(&di->chargalg_psy);
return 0;
}
static int abx500_chargalg_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct abx500_bm_data *plat = pdev->dev.platform_data;
struct abx500_chargalg *di;
int ret = 0;
di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
if (!di) {
dev_err(&pdev->dev, "%s no mem for ab8500_chargalg\n", __func__);
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
di->dev = &pdev->dev;
di->parent = dev_get_drvdata(pdev->dev.parent);
di->chargalg_psy.name = "abx500_chargalg";
di->chargalg_psy.type = POWER_SUPPLY_TYPE_BATTERY;
di->chargalg_psy.properties = abx500_chargalg_props;
di->chargalg_psy.num_properties = ARRAY_SIZE(abx500_chargalg_props);
di->chargalg_psy.get_property = abx500_chargalg_get_property;
di->chargalg_psy.supplied_to = supply_interface;
di->chargalg_psy.num_supplicants = ARRAY_SIZE(supply_interface),
di->chargalg_psy.external_power_changed =
abx500_chargalg_external_power_changed;
hrtimer_init(&di->safety_timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
di->safety_timer.function = abx500_chargalg_safety_timer_expired;
hrtimer_init(&di->maintenance_timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
di->maintenance_timer.function =
abx500_chargalg_maintenance_timer_expired;
di->chargalg_wq =
create_singlethread_workqueue("abx500_chargalg_wq");
if (di->chargalg_wq == NULL) {
dev_err(di->dev, "failed to create work queue\n");
return -ENOMEM;
}
INIT_DEFERRABLE_WORK(&di->chargalg_periodic_work,
abx500_chargalg_periodic_work);
INIT_DEFERRABLE_WORK(&di->chargalg_wd_work,
abx500_chargalg_wd_work);
INIT_WORK(&di->chargalg_work, abx500_chargalg_work);
di->chg_info.prev_conn_chg = -1;
ret = power_supply_register(di->dev, &di->chargalg_psy);
if (ret) {
dev_err(di->dev, "failed to register chargalg psy\n");
goto free_chargalg_wq;
}
platform_set_drvdata(pdev, di);
ret = abx500_chargalg_sysfs_init(di);
if (ret) {
dev_err(di->dev, "failed to create sysfs entry\n");
goto free_psy;
}
di->curr_status.curr_step = CHARGALG_CURR_STEP_HIGH;
queue_delayed_work(di->chargalg_wq, &di->chargalg_periodic_work, 0);
dev_info(di->dev, "probe success\n");
return ret;
free_psy:
power_supply_unregister(&di->chargalg_psy);
free_chargalg_wq:
destroy_workqueue(di->chargalg_wq);
return ret;
}
