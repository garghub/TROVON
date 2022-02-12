int smu7_fan_ctrl_get_fan_speed_info(struct pp_hwmgr *hwmgr,
struct phm_fan_speed_info *fan_speed_info)
{
if (hwmgr->thermal_controller.fanInfo.bNoFan)
return -ENODEV;
fan_speed_info->supports_percent_read = true;
fan_speed_info->supports_percent_write = true;
fan_speed_info->min_percent = 0;
fan_speed_info->max_percent = 100;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_FanSpeedInTableIsRPM) &&
hwmgr->thermal_controller.fanInfo.ucTachometerPulsesPerRevolution) {
fan_speed_info->supports_rpm_read = true;
fan_speed_info->supports_rpm_write = true;
fan_speed_info->min_rpm = hwmgr->thermal_controller.fanInfo.ulMinRPM;
fan_speed_info->max_rpm = hwmgr->thermal_controller.fanInfo.ulMaxRPM;
} else {
fan_speed_info->min_rpm = 0;
fan_speed_info->max_rpm = 0;
}
return 0;
}
int smu7_fan_ctrl_get_fan_speed_percent(struct pp_hwmgr *hwmgr,
uint32_t *speed)
{
uint32_t duty100;
uint32_t duty;
uint64_t tmp64;
if (hwmgr->thermal_controller.fanInfo.bNoFan)
return -ENODEV;
duty100 = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL1, FMAX_DUTY100);
duty = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_STATUS, FDO_PWM_DUTY);
if (duty100 == 0)
return -EINVAL;
tmp64 = (uint64_t)duty * 100;
do_div(tmp64, duty100);
*speed = (uint32_t)tmp64;
if (*speed > 100)
*speed = 100;
return 0;
}
int smu7_fan_ctrl_get_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t *speed)
{
uint32_t tach_period;
uint32_t crystal_clock_freq;
if (hwmgr->thermal_controller.fanInfo.bNoFan ||
(hwmgr->thermal_controller.fanInfo.
ucTachometerPulsesPerRevolution == 0))
return -ENODEV;
tach_period = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_TACH_STATUS, TACH_PERIOD);
if (tach_period == 0)
return -EINVAL;
crystal_clock_freq = smu7_get_xclk(hwmgr);
*speed = 60 * crystal_clock_freq * 10000 / tach_period;
return 0;
}
int smu7_fan_ctrl_set_static_mode(struct pp_hwmgr *hwmgr, uint32_t mode)
{
if (hwmgr->fan_ctrl_is_in_default_mode) {
hwmgr->fan_ctrl_default_mode =
PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, FDO_PWM_MODE);
hwmgr->tmin =
PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, TMIN);
hwmgr->fan_ctrl_is_in_default_mode = false;
}
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, TMIN, 0);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, FDO_PWM_MODE, mode);
return 0;
}
int smu7_fan_ctrl_set_default_mode(struct pp_hwmgr *hwmgr)
{
if (!hwmgr->fan_ctrl_is_in_default_mode) {
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, FDO_PWM_MODE, hwmgr->fan_ctrl_default_mode);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, TMIN, hwmgr->tmin);
hwmgr->fan_ctrl_is_in_default_mode = true;
}
return 0;
}
static int smu7_fan_ctrl_start_smc_fan_control(struct pp_hwmgr *hwmgr)
{
int result;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_ODFuzzyFanControlSupport)) {
cgs_write_register(hwmgr->device, mmSMC_MSG_ARG_0, FAN_CONTROL_FUZZY);
result = smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_StartFanControl);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_FanSpeedInTableIsRPM))
hwmgr->hwmgr_func->set_max_fan_rpm_output(hwmgr,
hwmgr->thermal_controller.
advanceFanControlParameters.usMaxFanRPM);
else
hwmgr->hwmgr_func->set_max_fan_pwm_output(hwmgr,
hwmgr->thermal_controller.
advanceFanControlParameters.usMaxFanPWM);
} else {
cgs_write_register(hwmgr->device, mmSMC_MSG_ARG_0, FAN_CONTROL_TABLE);
result = smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_StartFanControl);
}
if (!result && hwmgr->thermal_controller.
advanceFanControlParameters.ucTargetTemperature)
result = smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_SetFanTemperatureTarget,
hwmgr->thermal_controller.
advanceFanControlParameters.ucTargetTemperature);
return result;
}
int smu7_fan_ctrl_stop_smc_fan_control(struct pp_hwmgr *hwmgr)
{
return smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_StopFanControl);
}
int smu7_fan_ctrl_set_fan_speed_percent(struct pp_hwmgr *hwmgr,
uint32_t speed)
{
uint32_t duty100;
uint32_t duty;
uint64_t tmp64;
if (hwmgr->thermal_controller.fanInfo.bNoFan)
return 0;
if (speed > 100)
speed = 100;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_MicrocodeFanControl))
smu7_fan_ctrl_stop_smc_fan_control(hwmgr);
duty100 = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL1, FMAX_DUTY100);
if (duty100 == 0)
return -EINVAL;
tmp64 = (uint64_t)speed * duty100;
do_div(tmp64, 100);
duty = (uint32_t)tmp64;
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL0, FDO_STATIC_DUTY, duty);
return smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
}
int smu7_fan_ctrl_reset_fan_speed_to_default(struct pp_hwmgr *hwmgr)
{
int result;
if (hwmgr->thermal_controller.fanInfo.bNoFan)
return 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_MicrocodeFanControl)) {
result = smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
if (!result)
result = smu7_fan_ctrl_start_smc_fan_control(hwmgr);
} else
result = smu7_fan_ctrl_set_default_mode(hwmgr);
return result;
}
int smu7_fan_ctrl_set_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t speed)
{
uint32_t tach_period;
uint32_t crystal_clock_freq;
if (hwmgr->thermal_controller.fanInfo.bNoFan ||
(hwmgr->thermal_controller.fanInfo.
ucTachometerPulsesPerRevolution == 0) ||
(speed < hwmgr->thermal_controller.fanInfo.ulMinRPM) ||
(speed > hwmgr->thermal_controller.fanInfo.ulMaxRPM))
return 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_MicrocodeFanControl))
smu7_fan_ctrl_stop_smc_fan_control(hwmgr);
crystal_clock_freq = smu7_get_xclk(hwmgr);
tach_period = 60 * crystal_clock_freq * 10000 / (8 * speed);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_TACH_STATUS, TACH_PERIOD, tach_period);
return smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
}
int smu7_thermal_get_temperature(struct pp_hwmgr *hwmgr)
{
int temp;
temp = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_MULT_THERMAL_STATUS, CTF_TEMP);
if (temp & 0x200)
temp = SMU7_THERMAL_MAXIMUM_TEMP_READING;
else
temp = temp & 0x1ff;
temp *= PP_TEMPERATURE_UNITS_PER_CENTIGRADES;
return temp;
}
static int smu7_thermal_set_temperature_range(struct pp_hwmgr *hwmgr,
uint32_t low_temp, uint32_t high_temp)
{
uint32_t low = SMU7_THERMAL_MINIMUM_ALERT_TEMP *
PP_TEMPERATURE_UNITS_PER_CENTIGRADES;
uint32_t high = SMU7_THERMAL_MAXIMUM_ALERT_TEMP *
PP_TEMPERATURE_UNITS_PER_CENTIGRADES;
if (low < low_temp)
low = low_temp;
if (high > high_temp)
high = high_temp;
if (low > high)
return -EINVAL;
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, DIG_THERM_INTH,
(high / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, DIG_THERM_INTL,
(low / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_CTRL, DIG_THERM_DPM,
(high / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));
return 0;
}
static int smu7_thermal_initialize(struct pp_hwmgr *hwmgr)
{
if (hwmgr->thermal_controller.fanInfo.ucTachometerPulsesPerRevolution)
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_TACH_CTRL, EDGE_PER_REV,
hwmgr->thermal_controller.fanInfo.
ucTachometerPulsesPerRevolution - 1);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_FDO_CTRL2, TACH_PWM_RESP_RATE, 0x28);
return 0;
}
int smu7_thermal_enable_alert(struct pp_hwmgr *hwmgr)
{
uint32_t alert;
alert = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, THERM_INT_MASK);
alert &= ~(SMU7_THERMAL_HIGH_ALERT_MASK | SMU7_THERMAL_LOW_ALERT_MASK);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, THERM_INT_MASK, alert);
return smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_Thermal_Cntl_Enable);
}
int smu7_thermal_disable_alert(struct pp_hwmgr *hwmgr)
{
uint32_t alert;
alert = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, THERM_INT_MASK);
alert |= (SMU7_THERMAL_HIGH_ALERT_MASK | SMU7_THERMAL_LOW_ALERT_MASK);
PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
CG_THERMAL_INT, THERM_INT_MASK, alert);
return smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_Thermal_Cntl_Disable);
}
int smu7_thermal_stop_thermal_controller(struct pp_hwmgr *hwmgr)
{
int result = smu7_thermal_disable_alert(hwmgr);
if (!hwmgr->thermal_controller.fanInfo.bNoFan)
smu7_fan_ctrl_set_default_mode(hwmgr);
return result;
}
static int tf_smu7_thermal_start_smc_fan_control(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_MicrocodeFanControl)) {
smu7_fan_ctrl_start_smc_fan_control(hwmgr);
smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
}
return 0;
}
static int tf_smu7_thermal_set_temperature_range(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
struct PP_TemperatureRange *range = (struct PP_TemperatureRange *)input;
if (range == NULL)
return -EINVAL;
return smu7_thermal_set_temperature_range(hwmgr, range->min, range->max);
}
static int tf_smu7_thermal_initialize(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
return smu7_thermal_initialize(hwmgr);
}
static int tf_smu7_thermal_enable_alert(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
return smu7_thermal_enable_alert(hwmgr);
}
static int tf_smu7_thermal_disable_alert(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
return smu7_thermal_disable_alert(hwmgr);
}
int smu7_thermal_ctrl_uninitialize_thermal_controller(struct pp_hwmgr *hwmgr)
{
if (!hwmgr->thermal_controller.fanInfo.bNoFan)
smu7_fan_ctrl_set_default_mode(hwmgr);
return 0;
}
int pp_smu7_thermal_initialize(struct pp_hwmgr *hwmgr)
{
int result;
result = phm_construct_table(hwmgr,
&phm_thermal_set_temperature_range_master,
&(hwmgr->set_temperature_range));
if (!result) {
result = phm_construct_table(hwmgr,
&phm_thermal_start_thermal_controller_master,
&(hwmgr->start_thermal_controller));
if (result)
phm_destroy_table(hwmgr, &(hwmgr->set_temperature_range));
}
if (!result)
hwmgr->fan_ctrl_is_in_default_mode = true;
return result;
}
