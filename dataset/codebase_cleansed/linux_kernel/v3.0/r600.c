int rv6xx_get_temp(struct radeon_device *rdev)
{
u32 temp = (RREG32(CG_THERMAL_STATUS) & ASIC_T_MASK) >>
ASIC_T_SHIFT;
int actual_temp = temp & 0xff;
if (temp & 0x100)
actual_temp -= 256;
return actual_temp * 1000;
}
void r600_pm_get_dynpm_state(struct radeon_device *rdev)
{
int i;
rdev->pm.dynpm_can_upclock = true;
rdev->pm.dynpm_can_downclock = true;
if ((rdev->flags & RADEON_IS_IGP) || (rdev->family == CHIP_R600)) {
int min_power_state_index = 0;
if (rdev->pm.num_power_states > 2)
min_power_state_index = 1;
switch (rdev->pm.dynpm_planned_action) {
case DYNPM_ACTION_MINIMUM:
rdev->pm.requested_power_state_index = min_power_state_index;
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_downclock = false;
break;
case DYNPM_ACTION_DOWNCLOCK:
if (rdev->pm.current_power_state_index == min_power_state_index) {
rdev->pm.requested_power_state_index = rdev->pm.current_power_state_index;
rdev->pm.dynpm_can_downclock = false;
} else {
if (rdev->pm.active_crtc_count > 1) {
for (i = 0; i < rdev->pm.num_power_states; i++) {
if (rdev->pm.power_state[i].flags & RADEON_PM_STATE_SINGLE_DISPLAY_ONLY)
continue;
else if (i >= rdev->pm.current_power_state_index) {
rdev->pm.requested_power_state_index =
rdev->pm.current_power_state_index;
break;
} else {
rdev->pm.requested_power_state_index = i;
break;
}
}
} else {
if (rdev->pm.current_power_state_index == 0)
rdev->pm.requested_power_state_index =
rdev->pm.num_power_states - 1;
else
rdev->pm.requested_power_state_index =
rdev->pm.current_power_state_index - 1;
}
}
rdev->pm.requested_clock_mode_index = 0;
if ((rdev->pm.active_crtc_count > 0) &&
(rdev->pm.power_state[rdev->pm.requested_power_state_index].
clock_info[rdev->pm.requested_clock_mode_index].flags &
RADEON_PM_MODE_NO_DISPLAY)) {
rdev->pm.requested_power_state_index++;
}
break;
case DYNPM_ACTION_UPCLOCK:
if (rdev->pm.current_power_state_index == (rdev->pm.num_power_states - 1)) {
rdev->pm.requested_power_state_index = rdev->pm.current_power_state_index;
rdev->pm.dynpm_can_upclock = false;
} else {
if (rdev->pm.active_crtc_count > 1) {
for (i = (rdev->pm.num_power_states - 1); i >= 0; i--) {
if (rdev->pm.power_state[i].flags & RADEON_PM_STATE_SINGLE_DISPLAY_ONLY)
continue;
else if (i <= rdev->pm.current_power_state_index) {
rdev->pm.requested_power_state_index =
rdev->pm.current_power_state_index;
break;
} else {
rdev->pm.requested_power_state_index = i;
break;
}
}
} else
rdev->pm.requested_power_state_index =
rdev->pm.current_power_state_index + 1;
}
rdev->pm.requested_clock_mode_index = 0;
break;
case DYNPM_ACTION_DEFAULT:
rdev->pm.requested_power_state_index = rdev->pm.default_power_state_index;
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_upclock = false;
break;
case DYNPM_ACTION_NONE:
default:
DRM_ERROR("Requested mode for not defined action\n");
return;
}
} else {
if (rdev->pm.active_crtc_count > 1) {
rdev->pm.requested_power_state_index = -1;
for (i = 1; i < rdev->pm.num_power_states; i++) {
if (rdev->pm.power_state[i].flags & RADEON_PM_STATE_SINGLE_DISPLAY_ONLY)
continue;
else if ((rdev->pm.power_state[i].type == POWER_STATE_TYPE_PERFORMANCE) ||
(rdev->pm.power_state[i].type == POWER_STATE_TYPE_BATTERY)) {
rdev->pm.requested_power_state_index = i;
break;
}
}
if (rdev->pm.requested_power_state_index == -1)
rdev->pm.requested_power_state_index = 0;
} else
rdev->pm.requested_power_state_index = 1;
switch (rdev->pm.dynpm_planned_action) {
case DYNPM_ACTION_MINIMUM:
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_downclock = false;
break;
case DYNPM_ACTION_DOWNCLOCK:
if (rdev->pm.requested_power_state_index == rdev->pm.current_power_state_index) {
if (rdev->pm.current_clock_mode_index == 0) {
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_downclock = false;
} else
rdev->pm.requested_clock_mode_index =
rdev->pm.current_clock_mode_index - 1;
} else {
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_downclock = false;
}
if ((rdev->pm.active_crtc_count > 0) &&
(rdev->pm.power_state[rdev->pm.requested_power_state_index].
clock_info[rdev->pm.requested_clock_mode_index].flags &
RADEON_PM_MODE_NO_DISPLAY)) {
rdev->pm.requested_clock_mode_index++;
}
break;
case DYNPM_ACTION_UPCLOCK:
if (rdev->pm.requested_power_state_index == rdev->pm.current_power_state_index) {
if (rdev->pm.current_clock_mode_index ==
(rdev->pm.power_state[rdev->pm.requested_power_state_index].num_clock_modes - 1)) {
rdev->pm.requested_clock_mode_index = rdev->pm.current_clock_mode_index;
rdev->pm.dynpm_can_upclock = false;
} else
rdev->pm.requested_clock_mode_index =
rdev->pm.current_clock_mode_index + 1;
} else {
rdev->pm.requested_clock_mode_index =
rdev->pm.power_state[rdev->pm.requested_power_state_index].num_clock_modes - 1;
rdev->pm.dynpm_can_upclock = false;
}
break;
case DYNPM_ACTION_DEFAULT:
rdev->pm.requested_power_state_index = rdev->pm.default_power_state_index;
rdev->pm.requested_clock_mode_index = 0;
rdev->pm.dynpm_can_upclock = false;
break;
case DYNPM_ACTION_NONE:
default:
DRM_ERROR("Requested mode for not defined action\n");
return;
}
}
DRM_DEBUG_DRIVER("Requested: e: %d m: %d p: %d\n",
rdev->pm.power_state[rdev->pm.requested_power_state_index].
clock_info[rdev->pm.requested_clock_mode_index].sclk,
rdev->pm.power_state[rdev->pm.requested_power_state_index].
clock_info[rdev->pm.requested_clock_mode_index].mclk,
rdev->pm.power_state[rdev->pm.requested_power_state_index].
pcie_lanes);
}
static int r600_pm_get_type_index(struct radeon_device *rdev,
enum radeon_pm_state_type ps_type,
int instance)
{
int i;
int found_instance = -1;
for (i = 0; i < rdev->pm.num_power_states; i++) {
if (rdev->pm.power_state[i].type == ps_type) {
found_instance++;
if (found_instance == instance)
return i;
}
}
return rdev->pm.default_power_state_index;
}
void rs780_pm_init_profile(struct radeon_device *rdev)
{
if (rdev->pm.num_power_states == 2) {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 0;
} else if (rdev->pm.num_power_states == 3) {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 0;
} else {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx = 3;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx = 3;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 0;
}
}
void r600_pm_init_profile(struct radeon_device *rdev)
{
if (rdev->family == CHIP_R600) {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 0;
} else {
if (rdev->pm.num_power_states < 4) {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 1;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx = 2;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 2;
} else {
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_ps_idx = rdev->pm.default_power_state_index;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_DEFAULT_IDX].dpms_on_cm_idx = 2;
if (rdev->flags & RADEON_IS_MOBILITY) {
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 0);
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 0);
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
} else {
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_SH_IDX].dpms_on_cm_idx = 0;
}
if (rdev->flags & RADEON_IS_MOBILITY) {
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 0);
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 0);
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 1;
} else {
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_SH_IDX].dpms_on_cm_idx = 1;
}
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 0);
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_SH_IDX].dpms_on_cm_idx = 2;
if (rdev->flags & RADEON_IS_MOBILITY) {
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 1);
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 1);
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
} else {
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_LOW_MH_IDX].dpms_on_cm_idx = 0;
}
if (rdev->flags & RADEON_IS_MOBILITY) {
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 1);
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_BATTERY, 1);
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 1;
} else {
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_MID_MH_IDX].dpms_on_cm_idx = 1;
}
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_ps_idx =
r600_pm_get_type_index(rdev, POWER_STATE_TYPE_PERFORMANCE, 1);
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_off_cm_idx = 0;
rdev->pm.profiles[PM_PROFILE_HIGH_MH_IDX].dpms_on_cm_idx = 2;
}
}
}
void r600_pm_misc(struct radeon_device *rdev)
{
int req_ps_idx = rdev->pm.requested_power_state_index;
int req_cm_idx = rdev->pm.requested_clock_mode_index;
struct radeon_power_state *ps = &rdev->pm.power_state[req_ps_idx];
struct radeon_voltage *voltage = &ps->clock_info[req_cm_idx].voltage;
if ((voltage->type == VOLTAGE_SW) && voltage->voltage) {
if (voltage->voltage == 0xff01)
return;
if (voltage->voltage != rdev->pm.current_vddc) {
radeon_atom_set_voltage(rdev, voltage->voltage, SET_VOLTAGE_TYPE_ASIC_VDDC);
rdev->pm.current_vddc = voltage->voltage;
DRM_DEBUG_DRIVER("Setting: v: %d\n", voltage->voltage);
}
}
}
bool r600_gui_idle(struct radeon_device *rdev)
{
if (RREG32(GRBM_STATUS) & GUI_ACTIVE)
return false;
else
return true;
}
bool r600_hpd_sense(struct radeon_device *rdev, enum radeon_hpd_id hpd)
{
bool connected = false;
if (ASIC_IS_DCE3(rdev)) {
switch (hpd) {
case RADEON_HPD_1:
if (RREG32(DC_HPD1_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
case RADEON_HPD_2:
if (RREG32(DC_HPD2_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
case RADEON_HPD_3:
if (RREG32(DC_HPD3_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
case RADEON_HPD_4:
if (RREG32(DC_HPD4_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
case RADEON_HPD_5:
if (RREG32(DC_HPD5_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
case RADEON_HPD_6:
if (RREG32(DC_HPD6_INT_STATUS) & DC_HPDx_SENSE)
connected = true;
break;
default:
break;
}
} else {
switch (hpd) {
case RADEON_HPD_1:
if (RREG32(DC_HOT_PLUG_DETECT1_INT_STATUS) & DC_HOT_PLUG_DETECTx_SENSE)
connected = true;
break;
case RADEON_HPD_2:
if (RREG32(DC_HOT_PLUG_DETECT2_INT_STATUS) & DC_HOT_PLUG_DETECTx_SENSE)
connected = true;
break;
case RADEON_HPD_3:
if (RREG32(DC_HOT_PLUG_DETECT3_INT_STATUS) & DC_HOT_PLUG_DETECTx_SENSE)
connected = true;
break;
default:
break;
}
}
return connected;
}
void r600_hpd_set_polarity(struct radeon_device *rdev,
enum radeon_hpd_id hpd)
{
u32 tmp;
bool connected = r600_hpd_sense(rdev, hpd);
if (ASIC_IS_DCE3(rdev)) {
switch (hpd) {
case RADEON_HPD_1:
tmp = RREG32(DC_HPD1_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD1_INT_CONTROL, tmp);
break;
case RADEON_HPD_2:
tmp = RREG32(DC_HPD2_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD2_INT_CONTROL, tmp);
break;
case RADEON_HPD_3:
tmp = RREG32(DC_HPD3_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD3_INT_CONTROL, tmp);
break;
case RADEON_HPD_4:
tmp = RREG32(DC_HPD4_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD4_INT_CONTROL, tmp);
break;
case RADEON_HPD_5:
tmp = RREG32(DC_HPD5_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD5_INT_CONTROL, tmp);
break;
case RADEON_HPD_6:
tmp = RREG32(DC_HPD6_INT_CONTROL);
if (connected)
tmp &= ~DC_HPDx_INT_POLARITY;
else
tmp |= DC_HPDx_INT_POLARITY;
WREG32(DC_HPD6_INT_CONTROL, tmp);
break;
default:
break;
}
} else {
switch (hpd) {
case RADEON_HPD_1:
tmp = RREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL);
if (connected)
tmp &= ~DC_HOT_PLUG_DETECTx_INT_POLARITY;
else
tmp |= DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL, tmp);
break;
case RADEON_HPD_2:
tmp = RREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL);
if (connected)
tmp &= ~DC_HOT_PLUG_DETECTx_INT_POLARITY;
else
tmp |= DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL, tmp);
break;
case RADEON_HPD_3:
tmp = RREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL);
if (connected)
tmp &= ~DC_HOT_PLUG_DETECTx_INT_POLARITY;
else
tmp |= DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL, tmp);
break;
default:
break;
}
}
}
void r600_hpd_init(struct radeon_device *rdev)
{
struct drm_device *dev = rdev->ddev;
struct drm_connector *connector;
if (ASIC_IS_DCE3(rdev)) {
u32 tmp = DC_HPDx_CONNECTION_TIMER(0x9c4) | DC_HPDx_RX_INT_TIMER(0xfa);
if (ASIC_IS_DCE32(rdev))
tmp |= DC_HPDx_EN;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
switch (radeon_connector->hpd.hpd) {
case RADEON_HPD_1:
WREG32(DC_HPD1_CONTROL, tmp);
rdev->irq.hpd[0] = true;
break;
case RADEON_HPD_2:
WREG32(DC_HPD2_CONTROL, tmp);
rdev->irq.hpd[1] = true;
break;
case RADEON_HPD_3:
WREG32(DC_HPD3_CONTROL, tmp);
rdev->irq.hpd[2] = true;
break;
case RADEON_HPD_4:
WREG32(DC_HPD4_CONTROL, tmp);
rdev->irq.hpd[3] = true;
break;
case RADEON_HPD_5:
WREG32(DC_HPD5_CONTROL, tmp);
rdev->irq.hpd[4] = true;
break;
case RADEON_HPD_6:
WREG32(DC_HPD6_CONTROL, tmp);
rdev->irq.hpd[5] = true;
break;
default:
break;
}
}
} else {
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
switch (radeon_connector->hpd.hpd) {
case RADEON_HPD_1:
WREG32(DC_HOT_PLUG_DETECT1_CONTROL, DC_HOT_PLUG_DETECTx_EN);
rdev->irq.hpd[0] = true;
break;
case RADEON_HPD_2:
WREG32(DC_HOT_PLUG_DETECT2_CONTROL, DC_HOT_PLUG_DETECTx_EN);
rdev->irq.hpd[1] = true;
break;
case RADEON_HPD_3:
WREG32(DC_HOT_PLUG_DETECT3_CONTROL, DC_HOT_PLUG_DETECTx_EN);
rdev->irq.hpd[2] = true;
break;
default:
break;
}
}
}
if (rdev->irq.installed)
r600_irq_set(rdev);
}
void r600_hpd_fini(struct radeon_device *rdev)
{
struct drm_device *dev = rdev->ddev;
struct drm_connector *connector;
if (ASIC_IS_DCE3(rdev)) {
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
switch (radeon_connector->hpd.hpd) {
case RADEON_HPD_1:
WREG32(DC_HPD1_CONTROL, 0);
rdev->irq.hpd[0] = false;
break;
case RADEON_HPD_2:
WREG32(DC_HPD2_CONTROL, 0);
rdev->irq.hpd[1] = false;
break;
case RADEON_HPD_3:
WREG32(DC_HPD3_CONTROL, 0);
rdev->irq.hpd[2] = false;
break;
case RADEON_HPD_4:
WREG32(DC_HPD4_CONTROL, 0);
rdev->irq.hpd[3] = false;
break;
case RADEON_HPD_5:
WREG32(DC_HPD5_CONTROL, 0);
rdev->irq.hpd[4] = false;
break;
case RADEON_HPD_6:
WREG32(DC_HPD6_CONTROL, 0);
rdev->irq.hpd[5] = false;
break;
default:
break;
}
}
} else {
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
switch (radeon_connector->hpd.hpd) {
case RADEON_HPD_1:
WREG32(DC_HOT_PLUG_DETECT1_CONTROL, 0);
rdev->irq.hpd[0] = false;
break;
case RADEON_HPD_2:
WREG32(DC_HOT_PLUG_DETECT2_CONTROL, 0);
rdev->irq.hpd[1] = false;
break;
case RADEON_HPD_3:
WREG32(DC_HOT_PLUG_DETECT3_CONTROL, 0);
rdev->irq.hpd[2] = false;
break;
default:
break;
}
}
}
}
void r600_pcie_gart_tlb_flush(struct radeon_device *rdev)
{
unsigned i;
u32 tmp;
if ((rdev->family >= CHIP_RV770) && (rdev->family <= CHIP_RV740) &&
!(rdev->flags & RADEON_IS_AGP)) {
void __iomem *ptr = (void *)rdev->gart.table.vram.ptr;
u32 tmp;
WREG32(HDP_DEBUG1, 0);
tmp = readl((void __iomem *)ptr);
} else
WREG32(R_005480_HDP_MEM_COHERENCY_FLUSH_CNTL, 0x1);
WREG32(VM_CONTEXT0_INVALIDATION_LOW_ADDR, rdev->mc.gtt_start >> 12);
WREG32(VM_CONTEXT0_INVALIDATION_HIGH_ADDR, (rdev->mc.gtt_end - 1) >> 12);
WREG32(VM_CONTEXT0_REQUEST_RESPONSE, REQUEST_TYPE(1));
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(VM_CONTEXT0_REQUEST_RESPONSE);
tmp = (tmp & RESPONSE_TYPE_MASK) >> RESPONSE_TYPE_SHIFT;
if (tmp == 2) {
printk(KERN_WARNING "[drm] r600 flush TLB failed\n");
return;
}
if (tmp) {
return;
}
udelay(1);
}
}
int r600_pcie_gart_init(struct radeon_device *rdev)
{
int r;
if (rdev->gart.table.vram.robj) {
WARN(1, "R600 PCIE GART already initialized\n");
return 0;
}
r = radeon_gart_init(rdev);
if (r)
return r;
rdev->gart.table_size = rdev->gart.num_gpu_pages * 8;
return radeon_gart_table_vram_alloc(rdev);
}
int r600_pcie_gart_enable(struct radeon_device *rdev)
{
u32 tmp;
int r, i;
if (rdev->gart.table.vram.robj == NULL) {
dev_err(rdev->dev, "No VRAM object for PCIE GART.\n");
return -EINVAL;
}
r = radeon_gart_table_vram_pin(rdev);
if (r)
return r;
radeon_gart_restore(rdev);
WREG32(VM_L2_CNTL, ENABLE_L2_CACHE | ENABLE_L2_FRAGMENT_PROCESSING |
ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
EFFECTIVE_L2_QUEUE_SIZE(7));
WREG32(VM_L2_CNTL2, 0);
WREG32(VM_L2_CNTL3, BANK_SELECT_0(0) | BANK_SELECT_1(1));
tmp = ENABLE_L1_TLB | ENABLE_L1_FRAGMENT_PROCESSING |
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
EFFECTIVE_L1_TLB_SIZE(5) | EFFECTIVE_L1_QUEUE_SIZE(5) |
ENABLE_WAIT_L2_QUERY;
WREG32(MC_VM_L1_TLB_MCB_RD_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_HDP_CNTL, tmp | ENABLE_L1_STRICT_ORDERING);
WREG32(MC_VM_L1_TLB_MCB_WR_HDP_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_RD_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_RD_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_SEM_CNTL, tmp | ENABLE_SEMAPHORE_MODE);
WREG32(MC_VM_L1_TLB_MCB_WR_SEM_CNTL, tmp | ENABLE_SEMAPHORE_MODE);
WREG32(VM_CONTEXT0_PAGE_TABLE_START_ADDR, rdev->mc.gtt_start >> 12);
WREG32(VM_CONTEXT0_PAGE_TABLE_END_ADDR, rdev->mc.gtt_end >> 12);
WREG32(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR, rdev->gart.table_addr >> 12);
WREG32(VM_CONTEXT0_CNTL, ENABLE_CONTEXT | PAGE_TABLE_DEPTH(0) |
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT);
WREG32(VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR,
(u32)(rdev->dummy_page.addr >> 12));
for (i = 1; i < 7; i++)
WREG32(VM_CONTEXT0_CNTL + (i * 4), 0);
r600_pcie_gart_tlb_flush(rdev);
rdev->gart.ready = true;
return 0;
}
void r600_pcie_gart_disable(struct radeon_device *rdev)
{
u32 tmp;
int i, r;
for (i = 0; i < 7; i++)
WREG32(VM_CONTEXT0_CNTL + (i * 4), 0);
WREG32(VM_L2_CNTL, ENABLE_L2_FRAGMENT_PROCESSING |
EFFECTIVE_L2_QUEUE_SIZE(7));
WREG32(VM_L2_CNTL3, BANK_SELECT_0(0) | BANK_SELECT_1(1));
tmp = EFFECTIVE_L1_TLB_SIZE(5) | EFFECTIVE_L1_QUEUE_SIZE(5) |
ENABLE_WAIT_L2_QUERY;
WREG32(MC_VM_L1_TLB_MCD_RD_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_RD_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_SEM_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_SEM_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_HDP_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_HDP_CNTL, tmp);
if (rdev->gart.table.vram.robj) {
r = radeon_bo_reserve(rdev->gart.table.vram.robj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(rdev->gart.table.vram.robj);
radeon_bo_unpin(rdev->gart.table.vram.robj);
radeon_bo_unreserve(rdev->gart.table.vram.robj);
}
}
}
void r600_pcie_gart_fini(struct radeon_device *rdev)
{
radeon_gart_fini(rdev);
r600_pcie_gart_disable(rdev);
radeon_gart_table_vram_free(rdev);
}
void r600_agp_enable(struct radeon_device *rdev)
{
u32 tmp;
int i;
WREG32(VM_L2_CNTL, ENABLE_L2_CACHE | ENABLE_L2_FRAGMENT_PROCESSING |
ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
EFFECTIVE_L2_QUEUE_SIZE(7));
WREG32(VM_L2_CNTL2, 0);
WREG32(VM_L2_CNTL3, BANK_SELECT_0(0) | BANK_SELECT_1(1));
tmp = ENABLE_L1_TLB | ENABLE_L1_FRAGMENT_PROCESSING |
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
EFFECTIVE_L1_TLB_SIZE(5) | EFFECTIVE_L1_QUEUE_SIZE(5) |
ENABLE_WAIT_L2_QUERY;
WREG32(MC_VM_L1_TLB_MCB_RD_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_SYS_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_HDP_CNTL, tmp | ENABLE_L1_STRICT_ORDERING);
WREG32(MC_VM_L1_TLB_MCB_WR_HDP_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_RD_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_A_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_RD_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCD_WR_B_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_GFX_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_WR_PDMA_CNTL, tmp);
WREG32(MC_VM_L1_TLB_MCB_RD_SEM_CNTL, tmp | ENABLE_SEMAPHORE_MODE);
WREG32(MC_VM_L1_TLB_MCB_WR_SEM_CNTL, tmp | ENABLE_SEMAPHORE_MODE);
for (i = 0; i < 7; i++)
WREG32(VM_CONTEXT0_CNTL + (i * 4), 0);
}
int r600_mc_wait_for_idle(struct radeon_device *rdev)
{
unsigned i;
u32 tmp;
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(R_000E50_SRBM_STATUS) & 0x3F00;
if (!tmp)
return 0;
udelay(1);
}
return -1;
}
static void r600_mc_program(struct radeon_device *rdev)
{
struct rv515_mc_save save;
u32 tmp;
int i, j;
for (i = 0, j = 0; i < 32; i++, j += 0x18) {
WREG32((0x2c14 + j), 0x00000000);
WREG32((0x2c18 + j), 0x00000000);
WREG32((0x2c1c + j), 0x00000000);
WREG32((0x2c20 + j), 0x00000000);
WREG32((0x2c24 + j), 0x00000000);
}
WREG32(HDP_REG_COHERENCY_FLUSH_CNTL, 0);
rv515_mc_stop(rdev, &save);
if (r600_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
WREG32(VGA_HDP_CONTROL, VGA_MEMORY_DISABLE);
if (rdev->flags & RADEON_IS_AGP) {
if (rdev->mc.vram_start < rdev->mc.gtt_start) {
WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
rdev->mc.vram_start >> 12);
WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
rdev->mc.gtt_end >> 12);
} else {
WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
rdev->mc.gtt_start >> 12);
WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
rdev->mc.vram_end >> 12);
}
} else {
WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR, rdev->mc.vram_start >> 12);
WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR, rdev->mc.vram_end >> 12);
}
WREG32(MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR, 0);
tmp = ((rdev->mc.vram_end >> 24) & 0xFFFF) << 16;
tmp |= ((rdev->mc.vram_start >> 24) & 0xFFFF);
WREG32(MC_VM_FB_LOCATION, tmp);
WREG32(HDP_NONSURFACE_BASE, (rdev->mc.vram_start >> 8));
WREG32(HDP_NONSURFACE_INFO, (2 << 7));
WREG32(HDP_NONSURFACE_SIZE, 0x3FFFFFFF);
if (rdev->flags & RADEON_IS_AGP) {
WREG32(MC_VM_AGP_TOP, rdev->mc.gtt_end >> 22);
WREG32(MC_VM_AGP_BOT, rdev->mc.gtt_start >> 22);
WREG32(MC_VM_AGP_BASE, rdev->mc.agp_base >> 22);
} else {
WREG32(MC_VM_AGP_BASE, 0);
WREG32(MC_VM_AGP_TOP, 0x0FFFFFFF);
WREG32(MC_VM_AGP_BOT, 0x0FFFFFFF);
}
if (r600_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
rv515_mc_resume(rdev, &save);
rv515_vga_render_disable(rdev);
}
static void r600_vram_gtt_location(struct radeon_device *rdev, struct radeon_mc *mc)
{
u64 size_bf, size_af;
if (mc->mc_vram_size > 0xE0000000) {
dev_warn(rdev->dev, "limiting VRAM\n");
mc->real_vram_size = 0xE0000000;
mc->mc_vram_size = 0xE0000000;
}
if (rdev->flags & RADEON_IS_AGP) {
size_bf = mc->gtt_start;
size_af = 0xFFFFFFFF - mc->gtt_end + 1;
if (size_bf > size_af) {
if (mc->mc_vram_size > size_bf) {
dev_warn(rdev->dev, "limiting VRAM\n");
mc->real_vram_size = size_bf;
mc->mc_vram_size = size_bf;
}
mc->vram_start = mc->gtt_start - mc->mc_vram_size;
} else {
if (mc->mc_vram_size > size_af) {
dev_warn(rdev->dev, "limiting VRAM\n");
mc->real_vram_size = size_af;
mc->mc_vram_size = size_af;
}
mc->vram_start = mc->gtt_end;
}
mc->vram_end = mc->vram_start + mc->mc_vram_size - 1;
dev_info(rdev->dev, "VRAM: %lluM 0x%08llX - 0x%08llX (%lluM used)\n",
mc->mc_vram_size >> 20, mc->vram_start,
mc->vram_end, mc->real_vram_size >> 20);
} else {
u64 base = 0;
if (rdev->flags & RADEON_IS_IGP) {
base = RREG32(MC_VM_FB_LOCATION) & 0xFFFF;
base <<= 24;
}
radeon_vram_location(rdev, &rdev->mc, base);
rdev->mc.gtt_base_align = 0;
radeon_gtt_location(rdev, mc);
}
}
int r600_mc_init(struct radeon_device *rdev)
{
u32 tmp;
int chansize, numchan;
rdev->mc.vram_is_ddr = true;
tmp = RREG32(RAMCFG);
if (tmp & CHANSIZE_OVERRIDE) {
chansize = 16;
} else if (tmp & CHANSIZE_MASK) {
chansize = 64;
} else {
chansize = 32;
}
tmp = RREG32(CHMAP);
switch ((tmp & NOOFCHAN_MASK) >> NOOFCHAN_SHIFT) {
case 0:
default:
numchan = 1;
break;
case 1:
numchan = 2;
break;
case 2:
numchan = 4;
break;
case 3:
numchan = 8;
break;
}
rdev->mc.vram_width = numchan * chansize;
rdev->mc.aper_base = pci_resource_start(rdev->pdev, 0);
rdev->mc.aper_size = pci_resource_len(rdev->pdev, 0);
rdev->mc.mc_vram_size = RREG32(CONFIG_MEMSIZE);
rdev->mc.real_vram_size = RREG32(CONFIG_MEMSIZE);
rdev->mc.visible_vram_size = rdev->mc.aper_size;
r600_vram_gtt_location(rdev, &rdev->mc);
if (rdev->flags & RADEON_IS_IGP) {
rs690_pm_info(rdev);
rdev->mc.igp_sideport_enabled = radeon_atombios_sideport_present(rdev);
}
radeon_update_bandwidth_info(rdev);
return 0;
}
int r600_gpu_soft_reset(struct radeon_device *rdev)
{
struct rv515_mc_save save;
u32 grbm_busy_mask = S_008010_VC_BUSY(1) | S_008010_VGT_BUSY_NO_DMA(1) |
S_008010_VGT_BUSY(1) | S_008010_TA03_BUSY(1) |
S_008010_TC_BUSY(1) | S_008010_SX_BUSY(1) |
S_008010_SH_BUSY(1) | S_008010_SPI03_BUSY(1) |
S_008010_SMX_BUSY(1) | S_008010_SC_BUSY(1) |
S_008010_PA_BUSY(1) | S_008010_DB03_BUSY(1) |
S_008010_CR_BUSY(1) | S_008010_CB03_BUSY(1) |
S_008010_GUI_ACTIVE(1);
u32 grbm2_busy_mask = S_008014_SPI0_BUSY(1) | S_008014_SPI1_BUSY(1) |
S_008014_SPI2_BUSY(1) | S_008014_SPI3_BUSY(1) |
S_008014_TA0_BUSY(1) | S_008014_TA1_BUSY(1) |
S_008014_TA2_BUSY(1) | S_008014_TA3_BUSY(1) |
S_008014_DB0_BUSY(1) | S_008014_DB1_BUSY(1) |
S_008014_DB2_BUSY(1) | S_008014_DB3_BUSY(1) |
S_008014_CB0_BUSY(1) | S_008014_CB1_BUSY(1) |
S_008014_CB2_BUSY(1) | S_008014_CB3_BUSY(1);
u32 tmp;
if (!(RREG32(GRBM_STATUS) & GUI_ACTIVE))
return 0;
dev_info(rdev->dev, "GPU softreset \n");
dev_info(rdev->dev, " R_008010_GRBM_STATUS=0x%08X\n",
RREG32(R_008010_GRBM_STATUS));
dev_info(rdev->dev, " R_008014_GRBM_STATUS2=0x%08X\n",
RREG32(R_008014_GRBM_STATUS2));
dev_info(rdev->dev, " R_000E50_SRBM_STATUS=0x%08X\n",
RREG32(R_000E50_SRBM_STATUS));
rv515_mc_stop(rdev, &save);
if (r600_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
WREG32(R_0086D8_CP_ME_CNTL, S_0086D8_CP_ME_HALT(1));
if ((RREG32(R_008010_GRBM_STATUS) & grbm_busy_mask) ||
(RREG32(R_008014_GRBM_STATUS2) & grbm2_busy_mask)) {
tmp = S_008020_SOFT_RESET_CR(1) |
S_008020_SOFT_RESET_DB(1) |
S_008020_SOFT_RESET_CB(1) |
S_008020_SOFT_RESET_PA(1) |
S_008020_SOFT_RESET_SC(1) |
S_008020_SOFT_RESET_SMX(1) |
S_008020_SOFT_RESET_SPI(1) |
S_008020_SOFT_RESET_SX(1) |
S_008020_SOFT_RESET_SH(1) |
S_008020_SOFT_RESET_TC(1) |
S_008020_SOFT_RESET_TA(1) |
S_008020_SOFT_RESET_VC(1) |
S_008020_SOFT_RESET_VGT(1);
dev_info(rdev->dev, " R_008020_GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(R_008020_GRBM_SOFT_RESET, tmp);
RREG32(R_008020_GRBM_SOFT_RESET);
mdelay(15);
WREG32(R_008020_GRBM_SOFT_RESET, 0);
}
tmp = S_008020_SOFT_RESET_CP(1);
dev_info(rdev->dev, "R_008020_GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(R_008020_GRBM_SOFT_RESET, tmp);
RREG32(R_008020_GRBM_SOFT_RESET);
mdelay(15);
WREG32(R_008020_GRBM_SOFT_RESET, 0);
mdelay(1);
dev_info(rdev->dev, " R_008010_GRBM_STATUS=0x%08X\n",
RREG32(R_008010_GRBM_STATUS));
dev_info(rdev->dev, " R_008014_GRBM_STATUS2=0x%08X\n",
RREG32(R_008014_GRBM_STATUS2));
dev_info(rdev->dev, " R_000E50_SRBM_STATUS=0x%08X\n",
RREG32(R_000E50_SRBM_STATUS));
rv515_mc_resume(rdev, &save);
return 0;
}
bool r600_gpu_is_lockup(struct radeon_device *rdev)
{
u32 srbm_status;
u32 grbm_status;
u32 grbm_status2;
struct r100_gpu_lockup *lockup;
int r;
if (rdev->family >= CHIP_RV770)
lockup = &rdev->config.rv770.lockup;
else
lockup = &rdev->config.r600.lockup;
srbm_status = RREG32(R_000E50_SRBM_STATUS);
grbm_status = RREG32(R_008010_GRBM_STATUS);
grbm_status2 = RREG32(R_008014_GRBM_STATUS2);
if (!G_008010_GUI_ACTIVE(grbm_status)) {
r100_gpu_lockup_update(lockup, &rdev->cp);
return false;
}
r = radeon_ring_lock(rdev, 2);
if (!r) {
radeon_ring_write(rdev, 0x80000000);
radeon_ring_write(rdev, 0x80000000);
radeon_ring_unlock_commit(rdev);
}
rdev->cp.rptr = RREG32(R600_CP_RB_RPTR);
return r100_gpu_cp_is_lockup(rdev, lockup, &rdev->cp);
}
int r600_asic_reset(struct radeon_device *rdev)
{
return r600_gpu_soft_reset(rdev);
}
static u32 r600_get_tile_pipe_to_backend_map(u32 num_tile_pipes,
u32 num_backends,
u32 backend_disable_mask)
{
u32 backend_map = 0;
u32 enabled_backends_mask;
u32 enabled_backends_count;
u32 cur_pipe;
u32 swizzle_pipe[R6XX_MAX_PIPES];
u32 cur_backend;
u32 i;
if (num_tile_pipes > R6XX_MAX_PIPES)
num_tile_pipes = R6XX_MAX_PIPES;
if (num_tile_pipes < 1)
num_tile_pipes = 1;
if (num_backends > R6XX_MAX_BACKENDS)
num_backends = R6XX_MAX_BACKENDS;
if (num_backends < 1)
num_backends = 1;
enabled_backends_mask = 0;
enabled_backends_count = 0;
for (i = 0; i < R6XX_MAX_BACKENDS; ++i) {
if (((backend_disable_mask >> i) & 1) == 0) {
enabled_backends_mask |= (1 << i);
++enabled_backends_count;
}
if (enabled_backends_count == num_backends)
break;
}
if (enabled_backends_count == 0) {
enabled_backends_mask = 1;
enabled_backends_count = 1;
}
if (enabled_backends_count != num_backends)
num_backends = enabled_backends_count;
memset((uint8_t *)&swizzle_pipe[0], 0, sizeof(u32) * R6XX_MAX_PIPES);
switch (num_tile_pipes) {
case 1:
swizzle_pipe[0] = 0;
break;
case 2:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
break;
case 3:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
break;
case 4:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
swizzle_pipe[3] = 3;
break;
case 5:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
swizzle_pipe[3] = 3;
swizzle_pipe[4] = 4;
break;
case 6:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 4;
swizzle_pipe[3] = 5;
swizzle_pipe[4] = 1;
swizzle_pipe[5] = 3;
break;
case 7:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 4;
swizzle_pipe[3] = 6;
swizzle_pipe[4] = 1;
swizzle_pipe[5] = 3;
swizzle_pipe[6] = 5;
break;
case 8:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 4;
swizzle_pipe[3] = 6;
swizzle_pipe[4] = 1;
swizzle_pipe[5] = 3;
swizzle_pipe[6] = 5;
swizzle_pipe[7] = 7;
break;
}
cur_backend = 0;
for (cur_pipe = 0; cur_pipe < num_tile_pipes; ++cur_pipe) {
while (((1 << cur_backend) & enabled_backends_mask) == 0)
cur_backend = (cur_backend + 1) % R6XX_MAX_BACKENDS;
backend_map |= (u32)(((cur_backend & 3) << (swizzle_pipe[cur_pipe] * 2)));
cur_backend = (cur_backend + 1) % R6XX_MAX_BACKENDS;
}
return backend_map;
}
int r600_count_pipe_bits(uint32_t val)
{
int i, ret = 0;
for (i = 0; i < 32; i++) {
ret += val & 1;
val >>= 1;
}
return ret;
}
void r600_gpu_init(struct radeon_device *rdev)
{
u32 tiling_config;
u32 ramcfg;
u32 backend_map;
u32 cc_rb_backend_disable;
u32 cc_gc_shader_pipe_config;
u32 tmp;
int i, j;
u32 sq_config;
u32 sq_gpr_resource_mgmt_1 = 0;
u32 sq_gpr_resource_mgmt_2 = 0;
u32 sq_thread_resource_mgmt = 0;
u32 sq_stack_resource_mgmt_1 = 0;
u32 sq_stack_resource_mgmt_2 = 0;
switch (rdev->family) {
case CHIP_R600:
rdev->config.r600.max_pipes = 4;
rdev->config.r600.max_tile_pipes = 8;
rdev->config.r600.max_simds = 4;
rdev->config.r600.max_backends = 4;
rdev->config.r600.max_gprs = 256;
rdev->config.r600.max_threads = 192;
rdev->config.r600.max_stack_entries = 256;
rdev->config.r600.max_hw_contexts = 8;
rdev->config.r600.max_gs_threads = 16;
rdev->config.r600.sx_max_export_size = 128;
rdev->config.r600.sx_max_export_pos_size = 16;
rdev->config.r600.sx_max_export_smx_size = 128;
rdev->config.r600.sq_num_cf_insts = 2;
break;
case CHIP_RV630:
case CHIP_RV635:
rdev->config.r600.max_pipes = 2;
rdev->config.r600.max_tile_pipes = 2;
rdev->config.r600.max_simds = 3;
rdev->config.r600.max_backends = 1;
rdev->config.r600.max_gprs = 128;
rdev->config.r600.max_threads = 192;
rdev->config.r600.max_stack_entries = 128;
rdev->config.r600.max_hw_contexts = 8;
rdev->config.r600.max_gs_threads = 4;
rdev->config.r600.sx_max_export_size = 128;
rdev->config.r600.sx_max_export_pos_size = 16;
rdev->config.r600.sx_max_export_smx_size = 128;
rdev->config.r600.sq_num_cf_insts = 2;
break;
case CHIP_RV610:
case CHIP_RV620:
case CHIP_RS780:
case CHIP_RS880:
rdev->config.r600.max_pipes = 1;
rdev->config.r600.max_tile_pipes = 1;
rdev->config.r600.max_simds = 2;
rdev->config.r600.max_backends = 1;
rdev->config.r600.max_gprs = 128;
rdev->config.r600.max_threads = 192;
rdev->config.r600.max_stack_entries = 128;
rdev->config.r600.max_hw_contexts = 4;
rdev->config.r600.max_gs_threads = 4;
rdev->config.r600.sx_max_export_size = 128;
rdev->config.r600.sx_max_export_pos_size = 16;
rdev->config.r600.sx_max_export_smx_size = 128;
rdev->config.r600.sq_num_cf_insts = 1;
break;
case CHIP_RV670:
rdev->config.r600.max_pipes = 4;
rdev->config.r600.max_tile_pipes = 4;
rdev->config.r600.max_simds = 4;
rdev->config.r600.max_backends = 4;
rdev->config.r600.max_gprs = 192;
rdev->config.r600.max_threads = 192;
rdev->config.r600.max_stack_entries = 256;
rdev->config.r600.max_hw_contexts = 8;
rdev->config.r600.max_gs_threads = 16;
rdev->config.r600.sx_max_export_size = 128;
rdev->config.r600.sx_max_export_pos_size = 16;
rdev->config.r600.sx_max_export_smx_size = 128;
rdev->config.r600.sq_num_cf_insts = 2;
break;
default:
break;
}
for (i = 0, j = 0; i < 32; i++, j += 0x18) {
WREG32((0x2c14 + j), 0x00000000);
WREG32((0x2c18 + j), 0x00000000);
WREG32((0x2c1c + j), 0x00000000);
WREG32((0x2c20 + j), 0x00000000);
WREG32((0x2c24 + j), 0x00000000);
}
WREG32(GRBM_CNTL, GRBM_READ_TIMEOUT(0xff));
tiling_config = 0;
ramcfg = RREG32(RAMCFG);
switch (rdev->config.r600.max_tile_pipes) {
case 1:
tiling_config |= PIPE_TILING(0);
break;
case 2:
tiling_config |= PIPE_TILING(1);
break;
case 4:
tiling_config |= PIPE_TILING(2);
break;
case 8:
tiling_config |= PIPE_TILING(3);
break;
default:
break;
}
rdev->config.r600.tiling_npipes = rdev->config.r600.max_tile_pipes;
rdev->config.r600.tiling_nbanks = 4 << ((ramcfg & NOOFBANK_MASK) >> NOOFBANK_SHIFT);
tiling_config |= BANK_TILING((ramcfg & NOOFBANK_MASK) >> NOOFBANK_SHIFT);
tiling_config |= GROUP_SIZE((ramcfg & BURSTLENGTH_MASK) >> BURSTLENGTH_SHIFT);
if ((ramcfg & BURSTLENGTH_MASK) >> BURSTLENGTH_SHIFT)
rdev->config.r600.tiling_group_size = 512;
else
rdev->config.r600.tiling_group_size = 256;
tmp = (ramcfg & NOOFROWS_MASK) >> NOOFROWS_SHIFT;
if (tmp > 3) {
tiling_config |= ROW_TILING(3);
tiling_config |= SAMPLE_SPLIT(3);
} else {
tiling_config |= ROW_TILING(tmp);
tiling_config |= SAMPLE_SPLIT(tmp);
}
tiling_config |= BANK_SWAPS(1);
cc_rb_backend_disable = RREG32(CC_RB_BACKEND_DISABLE) & 0x00ff0000;
cc_rb_backend_disable |=
BACKEND_DISABLE((R6XX_MAX_BACKENDS_MASK << rdev->config.r600.max_backends) & R6XX_MAX_BACKENDS_MASK);
cc_gc_shader_pipe_config = RREG32(CC_GC_SHADER_PIPE_CONFIG) & 0xffffff00;
cc_gc_shader_pipe_config |=
INACTIVE_QD_PIPES((R6XX_MAX_PIPES_MASK << rdev->config.r600.max_pipes) & R6XX_MAX_PIPES_MASK);
cc_gc_shader_pipe_config |=
INACTIVE_SIMDS((R6XX_MAX_SIMDS_MASK << rdev->config.r600.max_simds) & R6XX_MAX_SIMDS_MASK);
backend_map = r600_get_tile_pipe_to_backend_map(rdev->config.r600.max_tile_pipes,
(R6XX_MAX_BACKENDS -
r600_count_pipe_bits((cc_rb_backend_disable &
R6XX_MAX_BACKENDS_MASK) >> 16)),
(cc_rb_backend_disable >> 16));
rdev->config.r600.tile_config = tiling_config;
tiling_config |= BACKEND_MAP(backend_map);
WREG32(GB_TILING_CONFIG, tiling_config);
WREG32(DCP_TILING_CONFIG, tiling_config & 0xffff);
WREG32(HDP_TILING_CONFIG, tiling_config & 0xffff);
WREG32(CC_RB_BACKEND_DISABLE, cc_rb_backend_disable);
WREG32(CC_GC_SHADER_PIPE_CONFIG, cc_gc_shader_pipe_config);
WREG32(GC_USER_SHADER_PIPE_CONFIG, cc_gc_shader_pipe_config);
tmp = R6XX_MAX_PIPES - r600_count_pipe_bits((cc_gc_shader_pipe_config & INACTIVE_QD_PIPES_MASK) >> 8);
WREG32(VGT_OUT_DEALLOC_CNTL, (tmp * 4) & DEALLOC_DIST_MASK);
WREG32(VGT_VERTEX_REUSE_BLOCK_CNTL, ((tmp * 4) - 2) & VTX_REUSE_DEPTH_MASK);
WREG32(CP_QUEUE_THRESHOLDS, (ROQ_IB1_START(0x16) | ROQ_IB2_START(0x2b)));
WREG32(CP_MEQ_THRESHOLDS, (MEQ_END(0x40) | ROQ_END(0x40)));
WREG32(TA_CNTL_AUX, (DISABLE_CUBE_ANISO | SYNC_GRADIENT |
SYNC_WALKER | SYNC_ALIGNER));
if (rdev->family == CHIP_RV670)
WREG32(ARB_GDEC_RD_CNTL, 0x00000021);
tmp = RREG32(SX_DEBUG_1);
tmp |= SMX_EVENT_RELEASE;
if ((rdev->family > CHIP_R600))
tmp |= ENABLE_NEW_SMX_ADDRESS;
WREG32(SX_DEBUG_1, tmp);
if (((rdev->family) == CHIP_R600) ||
((rdev->family) == CHIP_RV630) ||
((rdev->family) == CHIP_RV610) ||
((rdev->family) == CHIP_RV620) ||
((rdev->family) == CHIP_RS780) ||
((rdev->family) == CHIP_RS880)) {
WREG32(DB_DEBUG, PREZ_MUST_WAIT_FOR_POSTZ_DONE);
} else {
WREG32(DB_DEBUG, 0);
}
WREG32(DB_WATERMARKS, (DEPTH_FREE(4) | DEPTH_CACHELINE_FREE(16) |
DEPTH_FLUSH(16) | DEPTH_PENDING_FREE(4)));
WREG32(PA_SC_MULTI_CHIP_CNTL, 0);
WREG32(VGT_NUM_INSTANCES, 0);
WREG32(SPI_CONFIG_CNTL, GPR_WRITE_PRIORITY(0));
WREG32(SPI_CONFIG_CNTL_1, VTX_DONE_DELAY(0));
tmp = RREG32(SQ_MS_FIFO_SIZES);
if (((rdev->family) == CHIP_RV610) ||
((rdev->family) == CHIP_RV620) ||
((rdev->family) == CHIP_RS780) ||
((rdev->family) == CHIP_RS880)) {
tmp = (CACHE_FIFO_SIZE(0xa) |
FETCH_FIFO_HIWATER(0xa) |
DONE_FIFO_HIWATER(0xe0) |
ALU_UPDATE_FIFO_HIWATER(0x8));
} else if (((rdev->family) == CHIP_R600) ||
((rdev->family) == CHIP_RV630)) {
tmp &= ~DONE_FIFO_HIWATER(0xff);
tmp |= DONE_FIFO_HIWATER(0x4);
}
WREG32(SQ_MS_FIFO_SIZES, tmp);
sq_config = RREG32(SQ_CONFIG);
sq_config &= ~(PS_PRIO(3) |
VS_PRIO(3) |
GS_PRIO(3) |
ES_PRIO(3));
sq_config |= (DX9_CONSTS |
VC_ENABLE |
PS_PRIO(0) |
VS_PRIO(1) |
GS_PRIO(2) |
ES_PRIO(3));
if ((rdev->family) == CHIP_R600) {
sq_gpr_resource_mgmt_1 = (NUM_PS_GPRS(124) |
NUM_VS_GPRS(124) |
NUM_CLAUSE_TEMP_GPRS(4));
sq_gpr_resource_mgmt_2 = (NUM_GS_GPRS(0) |
NUM_ES_GPRS(0));
sq_thread_resource_mgmt = (NUM_PS_THREADS(136) |
NUM_VS_THREADS(48) |
NUM_GS_THREADS(4) |
NUM_ES_THREADS(4));
sq_stack_resource_mgmt_1 = (NUM_PS_STACK_ENTRIES(128) |
NUM_VS_STACK_ENTRIES(128));
sq_stack_resource_mgmt_2 = (NUM_GS_STACK_ENTRIES(0) |
NUM_ES_STACK_ENTRIES(0));
} else if (((rdev->family) == CHIP_RV610) ||
((rdev->family) == CHIP_RV620) ||
((rdev->family) == CHIP_RS780) ||
((rdev->family) == CHIP_RS880)) {
sq_config &= ~VC_ENABLE;
sq_gpr_resource_mgmt_1 = (NUM_PS_GPRS(44) |
NUM_VS_GPRS(44) |
NUM_CLAUSE_TEMP_GPRS(2));
sq_gpr_resource_mgmt_2 = (NUM_GS_GPRS(17) |
NUM_ES_GPRS(17));
sq_thread_resource_mgmt = (NUM_PS_THREADS(79) |
NUM_VS_THREADS(78) |
NUM_GS_THREADS(4) |
NUM_ES_THREADS(31));
sq_stack_resource_mgmt_1 = (NUM_PS_STACK_ENTRIES(40) |
NUM_VS_STACK_ENTRIES(40));
sq_stack_resource_mgmt_2 = (NUM_GS_STACK_ENTRIES(32) |
NUM_ES_STACK_ENTRIES(16));
} else if (((rdev->family) == CHIP_RV630) ||
((rdev->family) == CHIP_RV635)) {
sq_gpr_resource_mgmt_1 = (NUM_PS_GPRS(44) |
NUM_VS_GPRS(44) |
NUM_CLAUSE_TEMP_GPRS(2));
sq_gpr_resource_mgmt_2 = (NUM_GS_GPRS(18) |
NUM_ES_GPRS(18));
sq_thread_resource_mgmt = (NUM_PS_THREADS(79) |
NUM_VS_THREADS(78) |
NUM_GS_THREADS(4) |
NUM_ES_THREADS(31));
sq_stack_resource_mgmt_1 = (NUM_PS_STACK_ENTRIES(40) |
NUM_VS_STACK_ENTRIES(40));
sq_stack_resource_mgmt_2 = (NUM_GS_STACK_ENTRIES(32) |
NUM_ES_STACK_ENTRIES(16));
} else if ((rdev->family) == CHIP_RV670) {
sq_gpr_resource_mgmt_1 = (NUM_PS_GPRS(44) |
NUM_VS_GPRS(44) |
NUM_CLAUSE_TEMP_GPRS(2));
sq_gpr_resource_mgmt_2 = (NUM_GS_GPRS(17) |
NUM_ES_GPRS(17));
sq_thread_resource_mgmt = (NUM_PS_THREADS(79) |
NUM_VS_THREADS(78) |
NUM_GS_THREADS(4) |
NUM_ES_THREADS(31));
sq_stack_resource_mgmt_1 = (NUM_PS_STACK_ENTRIES(64) |
NUM_VS_STACK_ENTRIES(64));
sq_stack_resource_mgmt_2 = (NUM_GS_STACK_ENTRIES(64) |
NUM_ES_STACK_ENTRIES(64));
}
WREG32(SQ_CONFIG, sq_config);
WREG32(SQ_GPR_RESOURCE_MGMT_1, sq_gpr_resource_mgmt_1);
WREG32(SQ_GPR_RESOURCE_MGMT_2, sq_gpr_resource_mgmt_2);
WREG32(SQ_THREAD_RESOURCE_MGMT, sq_thread_resource_mgmt);
WREG32(SQ_STACK_RESOURCE_MGMT_1, sq_stack_resource_mgmt_1);
WREG32(SQ_STACK_RESOURCE_MGMT_2, sq_stack_resource_mgmt_2);
if (((rdev->family) == CHIP_RV610) ||
((rdev->family) == CHIP_RV620) ||
((rdev->family) == CHIP_RS780) ||
((rdev->family) == CHIP_RS880)) {
WREG32(VGT_CACHE_INVALIDATION, CACHE_INVALIDATION(TC_ONLY));
} else {
WREG32(VGT_CACHE_INVALIDATION, CACHE_INVALIDATION(VC_AND_TC));
}
WREG32(PA_SC_AA_SAMPLE_LOCS_2S, (S0_X(0xc) | S0_Y(0x4) |
S1_X(0x4) | S1_Y(0xc)));
WREG32(PA_SC_AA_SAMPLE_LOCS_4S, (S0_X(0xe) | S0_Y(0xe) |
S1_X(0x2) | S1_Y(0x2) |
S2_X(0xa) | S2_Y(0x6) |
S3_X(0x6) | S3_Y(0xa)));
WREG32(PA_SC_AA_SAMPLE_LOCS_8S_WD0, (S0_X(0xe) | S0_Y(0xb) |
S1_X(0x4) | S1_Y(0xc) |
S2_X(0x1) | S2_Y(0x6) |
S3_X(0xa) | S3_Y(0xe)));
WREG32(PA_SC_AA_SAMPLE_LOCS_8S_WD1, (S4_X(0x6) | S4_Y(0x1) |
S5_X(0x0) | S5_Y(0x0) |
S6_X(0xb) | S6_Y(0x4) |
S7_X(0x7) | S7_Y(0x8)));
WREG32(VGT_STRMOUT_EN, 0);
tmp = rdev->config.r600.max_pipes * 16;
switch (rdev->family) {
case CHIP_RV610:
case CHIP_RV620:
case CHIP_RS780:
case CHIP_RS880:
tmp += 32;
break;
case CHIP_RV670:
tmp += 128;
break;
default:
break;
}
if (tmp > 256) {
tmp = 256;
}
WREG32(VGT_ES_PER_GS, 128);
WREG32(VGT_GS_PER_ES, tmp);
WREG32(VGT_GS_PER_VS, 2);
WREG32(VGT_GS_VERTEX_REUSE, 16);
WREG32(PA_SC_LINE_STIPPLE_STATE, 0);
WREG32(VGT_STRMOUT_EN, 0);
WREG32(SX_MISC, 0);
WREG32(PA_SC_MODE_CNTL, 0);
WREG32(PA_SC_AA_CONFIG, 0);
WREG32(PA_SC_LINE_STIPPLE, 0);
WREG32(SPI_INPUT_Z, 0);
WREG32(SPI_PS_IN_CONTROL_0, NUM_INTERP(2));
WREG32(CB_COLOR7_FRAG, 0);
WREG32(CB_COLOR0_BASE, 0);
WREG32(CB_COLOR1_BASE, 0);
WREG32(CB_COLOR2_BASE, 0);
WREG32(CB_COLOR3_BASE, 0);
WREG32(CB_COLOR4_BASE, 0);
WREG32(CB_COLOR5_BASE, 0);
WREG32(CB_COLOR6_BASE, 0);
WREG32(CB_COLOR7_BASE, 0);
WREG32(CB_COLOR7_FRAG, 0);
switch (rdev->family) {
case CHIP_RV610:
case CHIP_RV620:
case CHIP_RS780:
case CHIP_RS880:
tmp = TC_L2_SIZE(8);
break;
case CHIP_RV630:
case CHIP_RV635:
tmp = TC_L2_SIZE(4);
break;
case CHIP_R600:
tmp = TC_L2_SIZE(0) | L2_DISABLE_LATE_HIT;
break;
default:
tmp = TC_L2_SIZE(0);
break;
}
WREG32(TC_CNTL, tmp);
tmp = RREG32(HDP_HOST_PATH_CNTL);
WREG32(HDP_HOST_PATH_CNTL, tmp);
tmp = RREG32(ARB_POP);
tmp |= ENABLE_TC128;
WREG32(ARB_POP, tmp);
WREG32(PA_SC_MULTI_CHIP_CNTL, 0);
WREG32(PA_CL_ENHANCE, (CLIP_VTX_REORDER_ENA |
NUM_CLIP_SEQ(3)));
WREG32(PA_SC_ENHANCE, FORCE_EOV_MAX_CLK_CNT(4095));
}
u32 r600_pciep_rreg(struct radeon_device *rdev, u32 reg)
{
u32 r;
WREG32(PCIE_PORT_INDEX, ((reg) & 0xff));
(void)RREG32(PCIE_PORT_INDEX);
r = RREG32(PCIE_PORT_DATA);
return r;
}
void r600_pciep_wreg(struct radeon_device *rdev, u32 reg, u32 v)
{
WREG32(PCIE_PORT_INDEX, ((reg) & 0xff));
(void)RREG32(PCIE_PORT_INDEX);
WREG32(PCIE_PORT_DATA, (v));
(void)RREG32(PCIE_PORT_DATA);
}
void r600_cp_stop(struct radeon_device *rdev)
{
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
WREG32(R_0086D8_CP_ME_CNTL, S_0086D8_CP_ME_HALT(1));
WREG32(SCRATCH_UMSK, 0);
}
int r600_init_microcode(struct radeon_device *rdev)
{
struct platform_device *pdev;
const char *chip_name;
const char *rlc_chip_name;
size_t pfp_req_size, me_req_size, rlc_req_size;
char fw_name[30];
int err;
DRM_DEBUG("\n");
pdev = platform_device_register_simple("radeon_cp", 0, NULL, 0);
err = IS_ERR(pdev);
if (err) {
printk(KERN_ERR "radeon_cp: Failed to register firmware\n");
return -EINVAL;
}
switch (rdev->family) {
case CHIP_R600:
chip_name = "R600";
rlc_chip_name = "R600";
break;
case CHIP_RV610:
chip_name = "RV610";
rlc_chip_name = "R600";
break;
case CHIP_RV630:
chip_name = "RV630";
rlc_chip_name = "R600";
break;
case CHIP_RV620:
chip_name = "RV620";
rlc_chip_name = "R600";
break;
case CHIP_RV635:
chip_name = "RV635";
rlc_chip_name = "R600";
break;
case CHIP_RV670:
chip_name = "RV670";
rlc_chip_name = "R600";
break;
case CHIP_RS780:
case CHIP_RS880:
chip_name = "RS780";
rlc_chip_name = "R600";
break;
case CHIP_RV770:
chip_name = "RV770";
rlc_chip_name = "R700";
break;
case CHIP_RV730:
case CHIP_RV740:
chip_name = "RV730";
rlc_chip_name = "R700";
break;
case CHIP_RV710:
chip_name = "RV710";
rlc_chip_name = "R700";
break;
case CHIP_CEDAR:
chip_name = "CEDAR";
rlc_chip_name = "CEDAR";
break;
case CHIP_REDWOOD:
chip_name = "REDWOOD";
rlc_chip_name = "REDWOOD";
break;
case CHIP_JUNIPER:
chip_name = "JUNIPER";
rlc_chip_name = "JUNIPER";
break;
case CHIP_CYPRESS:
case CHIP_HEMLOCK:
chip_name = "CYPRESS";
rlc_chip_name = "CYPRESS";
break;
case CHIP_PALM:
chip_name = "PALM";
rlc_chip_name = "SUMO";
break;
case CHIP_SUMO:
chip_name = "SUMO";
rlc_chip_name = "SUMO";
break;
case CHIP_SUMO2:
chip_name = "SUMO2";
rlc_chip_name = "SUMO";
break;
default: BUG();
}
if (rdev->family >= CHIP_CEDAR) {
pfp_req_size = EVERGREEN_PFP_UCODE_SIZE * 4;
me_req_size = EVERGREEN_PM4_UCODE_SIZE * 4;
rlc_req_size = EVERGREEN_RLC_UCODE_SIZE * 4;
} else if (rdev->family >= CHIP_RV770) {
pfp_req_size = R700_PFP_UCODE_SIZE * 4;
me_req_size = R700_PM4_UCODE_SIZE * 4;
rlc_req_size = R700_RLC_UCODE_SIZE * 4;
} else {
pfp_req_size = PFP_UCODE_SIZE * 4;
me_req_size = PM4_UCODE_SIZE * 12;
rlc_req_size = RLC_UCODE_SIZE * 4;
}
DRM_INFO("Loading %s Microcode\n", chip_name);
snprintf(fw_name, sizeof(fw_name), "radeon/%s_pfp.bin", chip_name);
err = request_firmware(&rdev->pfp_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->pfp_fw->size != pfp_req_size) {
printk(KERN_ERR
"r600_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->pfp_fw->size, fw_name);
err = -EINVAL;
goto out;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_me.bin", chip_name);
err = request_firmware(&rdev->me_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->me_fw->size != me_req_size) {
printk(KERN_ERR
"r600_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->me_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_rlc.bin", rlc_chip_name);
err = request_firmware(&rdev->rlc_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->rlc_fw->size != rlc_req_size) {
printk(KERN_ERR
"r600_rlc: Bogus length %zu in firmware \"%s\"\n",
rdev->rlc_fw->size, fw_name);
err = -EINVAL;
}
out:
platform_device_unregister(pdev);
if (err) {
if (err != -EINVAL)
printk(KERN_ERR
"r600_cp: Failed to load firmware \"%s\"\n",
fw_name);
release_firmware(rdev->pfp_fw);
rdev->pfp_fw = NULL;
release_firmware(rdev->me_fw);
rdev->me_fw = NULL;
release_firmware(rdev->rlc_fw);
rdev->rlc_fw = NULL;
}
return err;
}
static int r600_cp_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->me_fw || !rdev->pfp_fw)
return -EINVAL;
r600_cp_stop(rdev);
WREG32(CP_RB_CNTL,
#ifdef __BIG_ENDIAN
BUF_SWAP_32BIT |
#endif
RB_NO_UPDATE | RB_BLKSZ(15) | RB_BUFSZ(3));
WREG32(GRBM_SOFT_RESET, SOFT_RESET_CP);
RREG32(GRBM_SOFT_RESET);
mdelay(15);
WREG32(GRBM_SOFT_RESET, 0);
WREG32(CP_ME_RAM_WADDR, 0);
fw_data = (const __be32 *)rdev->me_fw->data;
WREG32(CP_ME_RAM_WADDR, 0);
for (i = 0; i < PM4_UCODE_SIZE * 3; i++)
WREG32(CP_ME_RAM_DATA,
be32_to_cpup(fw_data++));
fw_data = (const __be32 *)rdev->pfp_fw->data;
WREG32(CP_PFP_UCODE_ADDR, 0);
for (i = 0; i < PFP_UCODE_SIZE; i++)
WREG32(CP_PFP_UCODE_DATA,
be32_to_cpup(fw_data++));
WREG32(CP_PFP_UCODE_ADDR, 0);
WREG32(CP_ME_RAM_WADDR, 0);
WREG32(CP_ME_RAM_RADDR, 0);
return 0;
}
int r600_cp_start(struct radeon_device *rdev)
{
int r;
uint32_t cp_me;
r = radeon_ring_lock(rdev, 7);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(rdev, PACKET3(PACKET3_ME_INITIALIZE, 5));
radeon_ring_write(rdev, 0x1);
if (rdev->family >= CHIP_RV770) {
radeon_ring_write(rdev, 0x0);
radeon_ring_write(rdev, rdev->config.rv770.max_hw_contexts - 1);
} else {
radeon_ring_write(rdev, 0x3);
radeon_ring_write(rdev, rdev->config.r600.max_hw_contexts - 1);
}
radeon_ring_write(rdev, PACKET3_ME_INITIALIZE_DEVICE_ID(1));
radeon_ring_write(rdev, 0);
radeon_ring_write(rdev, 0);
radeon_ring_unlock_commit(rdev);
cp_me = 0xff;
WREG32(R_0086D8_CP_ME_CNTL, cp_me);
return 0;
}
int r600_cp_resume(struct radeon_device *rdev)
{
u32 tmp;
u32 rb_bufsz;
int r;
WREG32(GRBM_SOFT_RESET, SOFT_RESET_CP);
RREG32(GRBM_SOFT_RESET);
mdelay(15);
WREG32(GRBM_SOFT_RESET, 0);
rb_bufsz = drm_order(rdev->cp.ring_size / 8);
tmp = (drm_order(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= BUF_SWAP_32BIT;
#endif
WREG32(CP_RB_CNTL, tmp);
WREG32(CP_SEM_WAIT_TIMER, 0x4);
WREG32(CP_RB_WPTR_DELAY, 0);
WREG32(CP_RB_CNTL, tmp | RB_RPTR_WR_ENA);
WREG32(CP_RB_RPTR_WR, 0);
WREG32(CP_RB_WPTR, 0);
WREG32(CP_RB_RPTR_ADDR,
#ifdef __BIG_ENDIAN
RB_RPTR_SWAP(2) |
#endif
((rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFFFFFFFC));
WREG32(CP_RB_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFF);
WREG32(SCRATCH_ADDR, ((rdev->wb.gpu_addr + RADEON_WB_SCRATCH_OFFSET) >> 8) & 0xFFFFFFFF);
if (rdev->wb.enabled)
WREG32(SCRATCH_UMSK, 0xff);
else {
tmp |= RB_NO_UPDATE;
WREG32(SCRATCH_UMSK, 0);
}
mdelay(1);
WREG32(CP_RB_CNTL, tmp);
WREG32(CP_RB_BASE, rdev->cp.gpu_addr >> 8);
WREG32(CP_DEBUG, (1 << 27) | (1 << 28));
rdev->cp.rptr = RREG32(CP_RB_RPTR);
rdev->cp.wptr = RREG32(CP_RB_WPTR);
r600_cp_start(rdev);
rdev->cp.ready = true;
r = radeon_ring_test(rdev);
if (r) {
rdev->cp.ready = false;
return r;
}
return 0;
}
void r600_cp_commit(struct radeon_device *rdev)
{
WREG32(CP_RB_WPTR, rdev->cp.wptr);
(void)RREG32(CP_RB_WPTR);
}
void r600_ring_init(struct radeon_device *rdev, unsigned ring_size)
{
u32 rb_bufsz;
rb_bufsz = drm_order(ring_size / 8);
ring_size = (1 << (rb_bufsz + 1)) * 4;
rdev->cp.ring_size = ring_size;
rdev->cp.align_mask = 16 - 1;
}
void r600_cp_fini(struct radeon_device *rdev)
{
r600_cp_stop(rdev);
radeon_ring_fini(rdev);
}
void r600_scratch_init(struct radeon_device *rdev)
{
int i;
rdev->scratch.num_reg = 7;
rdev->scratch.reg_base = SCRATCH_REG0;
for (i = 0; i < rdev->scratch.num_reg; i++) {
rdev->scratch.free[i] = true;
rdev->scratch.reg[i] = rdev->scratch.reg_base + (i * 4);
}
}
int r600_ring_test(struct radeon_device *rdev)
{
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = radeon_scratch_get(rdev, &scratch);
if (r) {
DRM_ERROR("radeon: cp failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = radeon_ring_lock(rdev, 3);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
radeon_scratch_free(rdev, scratch);
return r;
}
radeon_ring_write(rdev, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(rdev, ((scratch - PACKET3_SET_CONFIG_REG_OFFSET) >> 2));
radeon_ring_write(rdev, 0xDEADBEEF);
radeon_ring_unlock_commit(rdev);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ring test succeeded in %d usecs\n", i);
} else {
DRM_ERROR("radeon: ring test failed (scratch(0x%04X)=0x%08X)\n",
scratch, tmp);
r = -EINVAL;
}
radeon_scratch_free(rdev, scratch);
return r;
}
void r600_fence_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
if (rdev->wb.use_event) {
u64 addr = rdev->wb.gpu_addr + R600_WB_EVENT_OFFSET +
(u64)(rdev->fence_drv.scratch_reg - rdev->scratch.reg_base);
radeon_ring_write(rdev, PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
radeon_ring_write(rdev, EVENT_TYPE(CACHE_FLUSH_AND_INV_EVENT_TS) | EVENT_INDEX(5));
radeon_ring_write(rdev, addr & 0xffffffff);
radeon_ring_write(rdev, (upper_32_bits(addr) & 0xff) | DATA_SEL(1) | INT_SEL(2));
radeon_ring_write(rdev, fence->seq);
radeon_ring_write(rdev, 0);
} else {
radeon_ring_write(rdev, PACKET3(PACKET3_EVENT_WRITE, 0));
radeon_ring_write(rdev, EVENT_TYPE(CACHE_FLUSH_AND_INV_EVENT) | EVENT_INDEX(0));
radeon_ring_write(rdev, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(rdev, (WAIT_UNTIL - PACKET3_SET_CONFIG_REG_OFFSET) >> 2);
radeon_ring_write(rdev, WAIT_3D_IDLE_bit | WAIT_3D_IDLECLEAN_bit);
radeon_ring_write(rdev, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(rdev, ((rdev->fence_drv.scratch_reg - PACKET3_SET_CONFIG_REG_OFFSET) >> 2));
radeon_ring_write(rdev, fence->seq);
radeon_ring_write(rdev, PACKET0(CP_INT_STATUS, 0));
radeon_ring_write(rdev, RB_INT_STAT);
}
}
int r600_copy_blit(struct radeon_device *rdev,
uint64_t src_offset, uint64_t dst_offset,
unsigned num_pages, struct radeon_fence *fence)
{
int r;
mutex_lock(&rdev->r600_blit.mutex);
rdev->r600_blit.vb_ib = NULL;
r = r600_blit_prepare_copy(rdev, num_pages * RADEON_GPU_PAGE_SIZE);
if (r) {
if (rdev->r600_blit.vb_ib)
radeon_ib_free(rdev, &rdev->r600_blit.vb_ib);
mutex_unlock(&rdev->r600_blit.mutex);
return r;
}
r600_kms_blit_copy(rdev, src_offset, dst_offset, num_pages * RADEON_GPU_PAGE_SIZE);
r600_blit_done_copy(rdev, fence);
mutex_unlock(&rdev->r600_blit.mutex);
return 0;
}
int r600_set_surface_reg(struct radeon_device *rdev, int reg,
uint32_t tiling_flags, uint32_t pitch,
uint32_t offset, uint32_t obj_size)
{
return 0;
}
void r600_clear_surface_reg(struct radeon_device *rdev, int reg)
{
}
int r600_startup(struct radeon_device *rdev)
{
int r;
r600_pcie_gen2_enable(rdev);
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->rlc_fw) {
r = r600_init_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load firmware!\n");
return r;
}
}
r600_mc_program(rdev);
if (rdev->flags & RADEON_IS_AGP) {
r600_agp_enable(rdev);
} else {
r = r600_pcie_gart_enable(rdev);
if (r)
return r;
}
r600_gpu_init(rdev);
r = r600_blit_init(rdev);
if (r) {
r600_blit_fini(rdev);
rdev->asic->copy = NULL;
dev_warn(rdev->dev, "failed blitter (%d) falling back to memcpy\n", r);
}
r = radeon_wb_init(rdev);
if (r)
return r;
r = r600_irq_init(rdev);
if (r) {
DRM_ERROR("radeon: IH init failed (%d).\n", r);
radeon_irq_kms_fini(rdev);
return r;
}
r600_irq_set(rdev);
r = radeon_ring_init(rdev, rdev->cp.ring_size);
if (r)
return r;
r = r600_cp_load_microcode(rdev);
if (r)
return r;
r = r600_cp_resume(rdev);
if (r)
return r;
return 0;
}
void r600_vga_set_state(struct radeon_device *rdev, bool state)
{
uint32_t temp;
temp = RREG32(CONFIG_CNTL);
if (state == false) {
temp &= ~(1<<0);
temp |= (1<<1);
} else {
temp &= ~(1<<1);
}
WREG32(CONFIG_CNTL, temp);
}
int r600_resume(struct radeon_device *rdev)
{
int r;
atom_asic_init(rdev->mode_info.atom_context);
r = r600_startup(rdev);
if (r) {
DRM_ERROR("r600 startup failed on resume\n");
return r;
}
r = r600_ib_test(rdev);
if (r) {
DRM_ERROR("radeon: failed testing IB (%d).\n", r);
return r;
}
r = r600_audio_init(rdev);
if (r) {
DRM_ERROR("radeon: audio resume failed\n");
return r;
}
return r;
}
int r600_suspend(struct radeon_device *rdev)
{
int r;
r600_audio_fini(rdev);
r600_cp_stop(rdev);
rdev->cp.ready = false;
r600_irq_suspend(rdev);
radeon_wb_disable(rdev);
r600_pcie_gart_disable(rdev);
if (rdev->r600_blit.shader_obj) {
r = radeon_bo_reserve(rdev->r600_blit.shader_obj, false);
if (!r) {
radeon_bo_unpin(rdev->r600_blit.shader_obj);
radeon_bo_unreserve(rdev->r600_blit.shader_obj);
}
}
return 0;
}
int r600_init(struct radeon_device *rdev)
{
int r;
if (r600_debugfs_mc_info_init(rdev)) {
DRM_ERROR("Failed to register debugfs file for mc !\n");
}
r = radeon_gem_init(rdev);
if (r)
return r;
if (!radeon_get_bios(rdev)) {
if (ASIC_IS_AVIVO(rdev))
return -EINVAL;
}
if (!rdev->is_atom_bios) {
dev_err(rdev->dev, "Expecting atombios for R600 GPU\n");
return -EINVAL;
}
r = radeon_atombios_init(rdev);
if (r)
return r;
if (!radeon_card_posted(rdev)) {
if (!rdev->bios) {
dev_err(rdev->dev, "Card not posted and no BIOS - ignoring\n");
return -EINVAL;
}
DRM_INFO("GPU not posted. posting now...\n");
atom_asic_init(rdev->mode_info.atom_context);
}
r600_scratch_init(rdev);
radeon_surface_init(rdev);
radeon_get_clock_info(rdev->ddev);
r = radeon_fence_driver_init(rdev);
if (r)
return r;
if (rdev->flags & RADEON_IS_AGP) {
r = radeon_agp_init(rdev);
if (r)
radeon_agp_disable(rdev);
}
r = r600_mc_init(rdev);
if (r)
return r;
r = radeon_bo_init(rdev);
if (r)
return r;
r = radeon_irq_kms_init(rdev);
if (r)
return r;
rdev->cp.ring_obj = NULL;
r600_ring_init(rdev, 1024 * 1024);
rdev->ih.ring_obj = NULL;
r600_ih_ring_init(rdev, 64 * 1024);
r = r600_pcie_gart_init(rdev);
if (r)
return r;
rdev->accel_working = true;
r = r600_startup(rdev);
if (r) {
dev_err(rdev->dev, "disabling GPU acceleration\n");
r600_cp_fini(rdev);
r600_irq_fini(rdev);
radeon_wb_fini(rdev);
radeon_irq_kms_fini(rdev);
r600_pcie_gart_fini(rdev);
rdev->accel_working = false;
}
if (rdev->accel_working) {
r = radeon_ib_pool_init(rdev);
if (r) {
dev_err(rdev->dev, "IB initialization failed (%d).\n", r);
rdev->accel_working = false;
} else {
r = r600_ib_test(rdev);
if (r) {
dev_err(rdev->dev, "IB test failed (%d).\n", r);
rdev->accel_working = false;
}
}
}
r = r600_audio_init(rdev);
if (r)
return r;
return 0;
}
void r600_fini(struct radeon_device *rdev)
{
r600_audio_fini(rdev);
r600_blit_fini(rdev);
r600_cp_fini(rdev);
r600_irq_fini(rdev);
radeon_wb_fini(rdev);
radeon_ib_pool_fini(rdev);
radeon_irq_kms_fini(rdev);
r600_pcie_gart_fini(rdev);
radeon_agp_fini(rdev);
radeon_gem_fini(rdev);
radeon_fence_driver_fini(rdev);
radeon_bo_fini(rdev);
radeon_atombios_fini(rdev);
kfree(rdev->bios);
rdev->bios = NULL;
}
void r600_ring_ib_execute(struct radeon_device *rdev, struct radeon_ib *ib)
{
radeon_ring_write(rdev, PACKET3(PACKET3_INDIRECT_BUFFER, 2));
radeon_ring_write(rdev,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
radeon_ring_write(rdev, upper_32_bits(ib->gpu_addr) & 0xFF);
radeon_ring_write(rdev, ib->length_dw);
}
int r600_ib_test(struct radeon_device *rdev)
{
struct radeon_ib *ib;
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = radeon_scratch_get(rdev, &scratch);
if (r) {
DRM_ERROR("radeon: failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = radeon_ib_get(rdev, &ib);
if (r) {
DRM_ERROR("radeon: failed to get ib (%d).\n", r);
return r;
}
ib->ptr[0] = PACKET3(PACKET3_SET_CONFIG_REG, 1);
ib->ptr[1] = ((scratch - PACKET3_SET_CONFIG_REG_OFFSET) >> 2);
ib->ptr[2] = 0xDEADBEEF;
ib->ptr[3] = PACKET2(0);
ib->ptr[4] = PACKET2(0);
ib->ptr[5] = PACKET2(0);
ib->ptr[6] = PACKET2(0);
ib->ptr[7] = PACKET2(0);
ib->ptr[8] = PACKET2(0);
ib->ptr[9] = PACKET2(0);
ib->ptr[10] = PACKET2(0);
ib->ptr[11] = PACKET2(0);
ib->ptr[12] = PACKET2(0);
ib->ptr[13] = PACKET2(0);
ib->ptr[14] = PACKET2(0);
ib->ptr[15] = PACKET2(0);
ib->length_dw = 16;
r = radeon_ib_schedule(rdev, ib);
if (r) {
radeon_scratch_free(rdev, scratch);
radeon_ib_free(rdev, &ib);
DRM_ERROR("radeon: failed to schedule ib (%d).\n", r);
return r;
}
r = radeon_fence_wait(ib->fence, false);
if (r) {
DRM_ERROR("radeon: fence wait failed (%d).\n", r);
return r;
}
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ib test succeeded in %u usecs\n", i);
} else {
DRM_ERROR("radeon: ib test failed (scratch(0x%04X)=0x%08X)\n",
scratch, tmp);
r = -EINVAL;
}
radeon_scratch_free(rdev, scratch);
radeon_ib_free(rdev, &ib);
return r;
}
void r600_ih_ring_init(struct radeon_device *rdev, unsigned ring_size)
{
u32 rb_bufsz;
rb_bufsz = drm_order(ring_size / 4);
ring_size = (1 << rb_bufsz) * 4;
rdev->ih.ring_size = ring_size;
rdev->ih.ptr_mask = rdev->ih.ring_size - 1;
rdev->ih.rptr = 0;
}
static int r600_ih_ring_alloc(struct radeon_device *rdev)
{
int r;
if (rdev->ih.ring_obj == NULL) {
r = radeon_bo_create(rdev, rdev->ih.ring_size,
PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT,
&rdev->ih.ring_obj);
if (r) {
DRM_ERROR("radeon: failed to create ih ring buffer (%d).\n", r);
return r;
}
r = radeon_bo_reserve(rdev->ih.ring_obj, false);
if (unlikely(r != 0))
return r;
r = radeon_bo_pin(rdev->ih.ring_obj,
RADEON_GEM_DOMAIN_GTT,
&rdev->ih.gpu_addr);
if (r) {
radeon_bo_unreserve(rdev->ih.ring_obj);
DRM_ERROR("radeon: failed to pin ih ring buffer (%d).\n", r);
return r;
}
r = radeon_bo_kmap(rdev->ih.ring_obj,
(void **)&rdev->ih.ring);
radeon_bo_unreserve(rdev->ih.ring_obj);
if (r) {
DRM_ERROR("radeon: failed to map ih ring buffer (%d).\n", r);
return r;
}
}
return 0;
}
static void r600_ih_ring_fini(struct radeon_device *rdev)
{
int r;
if (rdev->ih.ring_obj) {
r = radeon_bo_reserve(rdev->ih.ring_obj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(rdev->ih.ring_obj);
radeon_bo_unpin(rdev->ih.ring_obj);
radeon_bo_unreserve(rdev->ih.ring_obj);
}
radeon_bo_unref(&rdev->ih.ring_obj);
rdev->ih.ring = NULL;
rdev->ih.ring_obj = NULL;
}
}
void r600_rlc_stop(struct radeon_device *rdev)
{
if ((rdev->family >= CHIP_RV770) &&
(rdev->family <= CHIP_RV740)) {
WREG32(SRBM_SOFT_RESET, SOFT_RESET_RLC);
RREG32(SRBM_SOFT_RESET);
udelay(15000);
WREG32(SRBM_SOFT_RESET, 0);
RREG32(SRBM_SOFT_RESET);
}
WREG32(RLC_CNTL, 0);
}
static void r600_rlc_start(struct radeon_device *rdev)
{
WREG32(RLC_CNTL, RLC_ENABLE);
}
static int r600_rlc_init(struct radeon_device *rdev)
{
u32 i;
const __be32 *fw_data;
if (!rdev->rlc_fw)
return -EINVAL;
r600_rlc_stop(rdev);
WREG32(RLC_HB_BASE, 0);
WREG32(RLC_HB_CNTL, 0);
WREG32(RLC_HB_RPTR, 0);
WREG32(RLC_HB_WPTR, 0);
if (rdev->family <= CHIP_CAICOS) {
WREG32(RLC_HB_WPTR_LSB_ADDR, 0);
WREG32(RLC_HB_WPTR_MSB_ADDR, 0);
}
WREG32(RLC_MC_CNTL, 0);
WREG32(RLC_UCODE_CNTL, 0);
fw_data = (const __be32 *)rdev->rlc_fw->data;
if (rdev->family >= CHIP_CAYMAN) {
for (i = 0; i < CAYMAN_RLC_UCODE_SIZE; i++) {
WREG32(RLC_UCODE_ADDR, i);
WREG32(RLC_UCODE_DATA, be32_to_cpup(fw_data++));
}
} else if (rdev->family >= CHIP_CEDAR) {
for (i = 0; i < EVERGREEN_RLC_UCODE_SIZE; i++) {
WREG32(RLC_UCODE_ADDR, i);
WREG32(RLC_UCODE_DATA, be32_to_cpup(fw_data++));
}
} else if (rdev->family >= CHIP_RV770) {
for (i = 0; i < R700_RLC_UCODE_SIZE; i++) {
WREG32(RLC_UCODE_ADDR, i);
WREG32(RLC_UCODE_DATA, be32_to_cpup(fw_data++));
}
} else {
for (i = 0; i < RLC_UCODE_SIZE; i++) {
WREG32(RLC_UCODE_ADDR, i);
WREG32(RLC_UCODE_DATA, be32_to_cpup(fw_data++));
}
}
WREG32(RLC_UCODE_ADDR, 0);
r600_rlc_start(rdev);
return 0;
}
static void r600_enable_interrupts(struct radeon_device *rdev)
{
u32 ih_cntl = RREG32(IH_CNTL);
u32 ih_rb_cntl = RREG32(IH_RB_CNTL);
ih_cntl |= ENABLE_INTR;
ih_rb_cntl |= IH_RB_ENABLE;
WREG32(IH_CNTL, ih_cntl);
WREG32(IH_RB_CNTL, ih_rb_cntl);
rdev->ih.enabled = true;
}
void r600_disable_interrupts(struct radeon_device *rdev)
{
u32 ih_rb_cntl = RREG32(IH_RB_CNTL);
u32 ih_cntl = RREG32(IH_CNTL);
ih_rb_cntl &= ~IH_RB_ENABLE;
ih_cntl &= ~ENABLE_INTR;
WREG32(IH_RB_CNTL, ih_rb_cntl);
WREG32(IH_CNTL, ih_cntl);
WREG32(IH_RB_RPTR, 0);
WREG32(IH_RB_WPTR, 0);
rdev->ih.enabled = false;
rdev->ih.wptr = 0;
rdev->ih.rptr = 0;
}
static void r600_disable_interrupt_state(struct radeon_device *rdev)
{
u32 tmp;
WREG32(CP_INT_CNTL, CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE);
WREG32(GRBM_INT_CNTL, 0);
WREG32(DxMODE_INT_MASK, 0);
WREG32(D1GRPH_INTERRUPT_CONTROL, 0);
WREG32(D2GRPH_INTERRUPT_CONTROL, 0);
if (ASIC_IS_DCE3(rdev)) {
WREG32(DCE3_DACA_AUTODETECT_INT_CONTROL, 0);
WREG32(DCE3_DACB_AUTODETECT_INT_CONTROL, 0);
tmp = RREG32(DC_HPD1_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD1_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD2_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD2_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD3_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD3_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD4_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD4_INT_CONTROL, tmp);
if (ASIC_IS_DCE32(rdev)) {
tmp = RREG32(DC_HPD5_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD5_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD6_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD6_INT_CONTROL, tmp);
}
} else {
WREG32(DACA_AUTODETECT_INT_CONTROL, 0);
WREG32(DACB_AUTODETECT_INT_CONTROL, 0);
tmp = RREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL) & DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL, tmp);
tmp = RREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL) & DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL, tmp);
tmp = RREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL) & DC_HOT_PLUG_DETECTx_INT_POLARITY;
WREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL, tmp);
}
}
int r600_irq_init(struct radeon_device *rdev)
{
int ret = 0;
int rb_bufsz;
u32 interrupt_cntl, ih_cntl, ih_rb_cntl;
ret = r600_ih_ring_alloc(rdev);
if (ret)
return ret;
r600_disable_interrupts(rdev);
ret = r600_rlc_init(rdev);
if (ret) {
r600_ih_ring_fini(rdev);
return ret;
}
WREG32(INTERRUPT_CNTL2, rdev->ih.gpu_addr >> 8);
interrupt_cntl = RREG32(INTERRUPT_CNTL);
interrupt_cntl &= ~IH_DUMMY_RD_OVERRIDE;
interrupt_cntl &= ~IH_REQ_NONSNOOP_EN;
WREG32(INTERRUPT_CNTL, interrupt_cntl);
WREG32(IH_RB_BASE, rdev->ih.gpu_addr >> 8);
rb_bufsz = drm_order(rdev->ih.ring_size / 4);
ih_rb_cntl = (IH_WPTR_OVERFLOW_ENABLE |
IH_WPTR_OVERFLOW_CLEAR |
(rb_bufsz << 1));
if (rdev->wb.enabled)
ih_rb_cntl |= IH_WPTR_WRITEBACK_ENABLE;
WREG32(IH_RB_WPTR_ADDR_LO, (rdev->wb.gpu_addr + R600_WB_IH_WPTR_OFFSET) & 0xFFFFFFFC);
WREG32(IH_RB_WPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + R600_WB_IH_WPTR_OFFSET) & 0xFF);
WREG32(IH_RB_CNTL, ih_rb_cntl);
WREG32(IH_RB_RPTR, 0);
WREG32(IH_RB_WPTR, 0);
ih_cntl = MC_WRREQ_CREDIT(0x10) | MC_WR_CLEAN_CNT(0x10);
if (rdev->msi_enabled)
ih_cntl |= RPTR_REARM;
#ifdef __BIG_ENDIAN
ih_cntl |= IH_MC_SWAP(IH_MC_SWAP_32BIT);
#endif
WREG32(IH_CNTL, ih_cntl);
if (rdev->family >= CHIP_CEDAR)
evergreen_disable_interrupt_state(rdev);
else
r600_disable_interrupt_state(rdev);
r600_enable_interrupts(rdev);
return ret;
}
void r600_irq_suspend(struct radeon_device *rdev)
{
r600_irq_disable(rdev);
r600_rlc_stop(rdev);
}
void r600_irq_fini(struct radeon_device *rdev)
{
r600_irq_suspend(rdev);
r600_ih_ring_fini(rdev);
}
int r600_irq_set(struct radeon_device *rdev)
{
u32 cp_int_cntl = CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE;
u32 mode_int = 0;
u32 hpd1, hpd2, hpd3, hpd4 = 0, hpd5 = 0, hpd6 = 0;
u32 grbm_int_cntl = 0;
u32 hdmi1, hdmi2;
u32 d1grph = 0, d2grph = 0;
if (!rdev->irq.installed) {
WARN(1, "Can't enable IRQ/MSI because no handler is installed\n");
return -EINVAL;
}
if (!rdev->ih.enabled) {
r600_disable_interrupts(rdev);
r600_disable_interrupt_state(rdev);
return 0;
}
hdmi1 = RREG32(R600_HDMI_BLOCK1 + R600_HDMI_CNTL) & ~R600_HDMI_INT_EN;
if (ASIC_IS_DCE3(rdev)) {
hdmi2 = RREG32(R600_HDMI_BLOCK3 + R600_HDMI_CNTL) & ~R600_HDMI_INT_EN;
hpd1 = RREG32(DC_HPD1_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd2 = RREG32(DC_HPD2_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd3 = RREG32(DC_HPD3_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd4 = RREG32(DC_HPD4_INT_CONTROL) & ~DC_HPDx_INT_EN;
if (ASIC_IS_DCE32(rdev)) {
hpd5 = RREG32(DC_HPD5_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd6 = RREG32(DC_HPD6_INT_CONTROL) & ~DC_HPDx_INT_EN;
}
} else {
hdmi2 = RREG32(R600_HDMI_BLOCK2 + R600_HDMI_CNTL) & ~R600_HDMI_INT_EN;
hpd1 = RREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd2 = RREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd3 = RREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL) & ~DC_HPDx_INT_EN;
}
if (rdev->irq.sw_int) {
DRM_DEBUG("r600_irq_set: sw int\n");
cp_int_cntl |= RB_INT_ENABLE;
cp_int_cntl |= TIME_STAMP_INT_ENABLE;
}
if (rdev->irq.crtc_vblank_int[0] ||
rdev->irq.pflip[0]) {
DRM_DEBUG("r600_irq_set: vblank 0\n");
mode_int |= D1MODE_VBLANK_INT_MASK;
}
if (rdev->irq.crtc_vblank_int[1] ||
rdev->irq.pflip[1]) {
DRM_DEBUG("r600_irq_set: vblank 1\n");
mode_int |= D2MODE_VBLANK_INT_MASK;
}
if (rdev->irq.hpd[0]) {
DRM_DEBUG("r600_irq_set: hpd 1\n");
hpd1 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[1]) {
DRM_DEBUG("r600_irq_set: hpd 2\n");
hpd2 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[2]) {
DRM_DEBUG("r600_irq_set: hpd 3\n");
hpd3 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[3]) {
DRM_DEBUG("r600_irq_set: hpd 4\n");
hpd4 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[4]) {
DRM_DEBUG("r600_irq_set: hpd 5\n");
hpd5 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[5]) {
DRM_DEBUG("r600_irq_set: hpd 6\n");
hpd6 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hdmi[0]) {
DRM_DEBUG("r600_irq_set: hdmi 1\n");
hdmi1 |= R600_HDMI_INT_EN;
}
if (rdev->irq.hdmi[1]) {
DRM_DEBUG("r600_irq_set: hdmi 2\n");
hdmi2 |= R600_HDMI_INT_EN;
}
if (rdev->irq.gui_idle) {
DRM_DEBUG("gui idle\n");
grbm_int_cntl |= GUI_IDLE_INT_ENABLE;
}
WREG32(CP_INT_CNTL, cp_int_cntl);
WREG32(DxMODE_INT_MASK, mode_int);
WREG32(D1GRPH_INTERRUPT_CONTROL, d1grph);
WREG32(D2GRPH_INTERRUPT_CONTROL, d2grph);
WREG32(GRBM_INT_CNTL, grbm_int_cntl);
WREG32(R600_HDMI_BLOCK1 + R600_HDMI_CNTL, hdmi1);
if (ASIC_IS_DCE3(rdev)) {
WREG32(R600_HDMI_BLOCK3 + R600_HDMI_CNTL, hdmi2);
WREG32(DC_HPD1_INT_CONTROL, hpd1);
WREG32(DC_HPD2_INT_CONTROL, hpd2);
WREG32(DC_HPD3_INT_CONTROL, hpd3);
WREG32(DC_HPD4_INT_CONTROL, hpd4);
if (ASIC_IS_DCE32(rdev)) {
WREG32(DC_HPD5_INT_CONTROL, hpd5);
WREG32(DC_HPD6_INT_CONTROL, hpd6);
}
} else {
WREG32(R600_HDMI_BLOCK2 + R600_HDMI_CNTL, hdmi2);
WREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL, hpd1);
WREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL, hpd2);
WREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL, hpd3);
}
return 0;
}
static inline void r600_irq_ack(struct radeon_device *rdev)
{
u32 tmp;
if (ASIC_IS_DCE3(rdev)) {
rdev->irq.stat_regs.r600.disp_int = RREG32(DCE3_DISP_INTERRUPT_STATUS);
rdev->irq.stat_regs.r600.disp_int_cont = RREG32(DCE3_DISP_INTERRUPT_STATUS_CONTINUE);
rdev->irq.stat_regs.r600.disp_int_cont2 = RREG32(DCE3_DISP_INTERRUPT_STATUS_CONTINUE2);
} else {
rdev->irq.stat_regs.r600.disp_int = RREG32(DISP_INTERRUPT_STATUS);
rdev->irq.stat_regs.r600.disp_int_cont = RREG32(DISP_INTERRUPT_STATUS_CONTINUE);
rdev->irq.stat_regs.r600.disp_int_cont2 = 0;
}
rdev->irq.stat_regs.r600.d1grph_int = RREG32(D1GRPH_INTERRUPT_STATUS);
rdev->irq.stat_regs.r600.d2grph_int = RREG32(D2GRPH_INTERRUPT_STATUS);
if (rdev->irq.stat_regs.r600.d1grph_int & DxGRPH_PFLIP_INT_OCCURRED)
WREG32(D1GRPH_INTERRUPT_STATUS, DxGRPH_PFLIP_INT_CLEAR);
if (rdev->irq.stat_regs.r600.d2grph_int & DxGRPH_PFLIP_INT_OCCURRED)
WREG32(D2GRPH_INTERRUPT_STATUS, DxGRPH_PFLIP_INT_CLEAR);
if (rdev->irq.stat_regs.r600.disp_int & LB_D1_VBLANK_INTERRUPT)
WREG32(D1MODE_VBLANK_STATUS, DxMODE_VBLANK_ACK);
if (rdev->irq.stat_regs.r600.disp_int & LB_D1_VLINE_INTERRUPT)
WREG32(D1MODE_VLINE_STATUS, DxMODE_VLINE_ACK);
if (rdev->irq.stat_regs.r600.disp_int & LB_D2_VBLANK_INTERRUPT)
WREG32(D2MODE_VBLANK_STATUS, DxMODE_VBLANK_ACK);
if (rdev->irq.stat_regs.r600.disp_int & LB_D2_VLINE_INTERRUPT)
WREG32(D2MODE_VLINE_STATUS, DxMODE_VLINE_ACK);
if (rdev->irq.stat_regs.r600.disp_int & DC_HPD1_INTERRUPT) {
if (ASIC_IS_DCE3(rdev)) {
tmp = RREG32(DC_HPD1_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD1_INT_CONTROL, tmp);
} else {
tmp = RREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HOT_PLUG_DETECT1_INT_CONTROL, tmp);
}
}
if (rdev->irq.stat_regs.r600.disp_int & DC_HPD2_INTERRUPT) {
if (ASIC_IS_DCE3(rdev)) {
tmp = RREG32(DC_HPD2_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD2_INT_CONTROL, tmp);
} else {
tmp = RREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HOT_PLUG_DETECT2_INT_CONTROL, tmp);
}
}
if (rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD3_INTERRUPT) {
if (ASIC_IS_DCE3(rdev)) {
tmp = RREG32(DC_HPD3_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD3_INT_CONTROL, tmp);
} else {
tmp = RREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HOT_PLUG_DETECT3_INT_CONTROL, tmp);
}
}
if (rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD4_INTERRUPT) {
tmp = RREG32(DC_HPD4_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD4_INT_CONTROL, tmp);
}
if (ASIC_IS_DCE32(rdev)) {
if (rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD5_INTERRUPT) {
tmp = RREG32(DC_HPD5_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD5_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD6_INTERRUPT) {
tmp = RREG32(DC_HPD5_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD6_INT_CONTROL, tmp);
}
}
if (RREG32(R600_HDMI_BLOCK1 + R600_HDMI_STATUS) & R600_HDMI_INT_PENDING) {
WREG32_P(R600_HDMI_BLOCK1 + R600_HDMI_CNTL, R600_HDMI_INT_ACK, ~R600_HDMI_INT_ACK);
}
if (ASIC_IS_DCE3(rdev)) {
if (RREG32(R600_HDMI_BLOCK3 + R600_HDMI_STATUS) & R600_HDMI_INT_PENDING) {
WREG32_P(R600_HDMI_BLOCK3 + R600_HDMI_CNTL, R600_HDMI_INT_ACK, ~R600_HDMI_INT_ACK);
}
} else {
if (RREG32(R600_HDMI_BLOCK2 + R600_HDMI_STATUS) & R600_HDMI_INT_PENDING) {
WREG32_P(R600_HDMI_BLOCK2 + R600_HDMI_CNTL, R600_HDMI_INT_ACK, ~R600_HDMI_INT_ACK);
}
}
}
void r600_irq_disable(struct radeon_device *rdev)
{
r600_disable_interrupts(rdev);
mdelay(1);
r600_irq_ack(rdev);
r600_disable_interrupt_state(rdev);
}
static inline u32 r600_get_ih_wptr(struct radeon_device *rdev)
{
u32 wptr, tmp;
if (rdev->wb.enabled)
wptr = le32_to_cpu(rdev->wb.wb[R600_WB_IH_WPTR_OFFSET/4]);
else
wptr = RREG32(IH_RB_WPTR);
if (wptr & RB_OVERFLOW) {
dev_warn(rdev->dev, "IH ring buffer overflow (0x%08X, %d, %d)\n",
wptr, rdev->ih.rptr, (wptr + 16) + rdev->ih.ptr_mask);
rdev->ih.rptr = (wptr + 16) & rdev->ih.ptr_mask;
tmp = RREG32(IH_RB_CNTL);
tmp |= IH_WPTR_OVERFLOW_CLEAR;
WREG32(IH_RB_CNTL, tmp);
}
return (wptr & rdev->ih.ptr_mask);
}
int r600_irq_process(struct radeon_device *rdev)
{
u32 wptr;
u32 rptr;
u32 src_id, src_data;
u32 ring_index;
unsigned long flags;
bool queue_hotplug = false;
if (!rdev->ih.enabled || rdev->shutdown)
return IRQ_NONE;
wptr = r600_get_ih_wptr(rdev);
rptr = rdev->ih.rptr;
DRM_DEBUG("r600_irq_process start: rptr %d, wptr %d\n", rptr, wptr);
spin_lock_irqsave(&rdev->ih.lock, flags);
if (rptr == wptr) {
spin_unlock_irqrestore(&rdev->ih.lock, flags);
return IRQ_NONE;
}
restart_ih:
r600_irq_ack(rdev);
rdev->ih.wptr = wptr;
while (rptr != wptr) {
ring_index = rptr / 4;
src_id = le32_to_cpu(rdev->ih.ring[ring_index]) & 0xff;
src_data = le32_to_cpu(rdev->ih.ring[ring_index + 1]) & 0xfffffff;
switch (src_id) {
case 1:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.r600.disp_int & LB_D1_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[0]) {
drm_handle_vblank(rdev->ddev, 0);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (rdev->irq.pflip[0])
radeon_crtc_handle_flip(rdev, 0);
rdev->irq.stat_regs.r600.disp_int &= ~LB_D1_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D1 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.r600.disp_int & LB_D1_VLINE_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int &= ~LB_D1_VLINE_INTERRUPT;
DRM_DEBUG("IH: D1 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 5:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.r600.disp_int & LB_D2_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[1]) {
drm_handle_vblank(rdev->ddev, 1);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (rdev->irq.pflip[1])
radeon_crtc_handle_flip(rdev, 1);
rdev->irq.stat_regs.r600.disp_int &= ~LB_D2_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D2 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.r600.disp_int & LB_D2_VLINE_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int &= ~LB_D2_VLINE_INTERRUPT;
DRM_DEBUG("IH: D2 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 19:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.r600.disp_int & DC_HPD1_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int &= ~DC_HPD1_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD1\n");
}
break;
case 1:
if (rdev->irq.stat_regs.r600.disp_int & DC_HPD2_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int &= ~DC_HPD2_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD2\n");
}
break;
case 4:
if (rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD3_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int_cont &= ~DC_HPD3_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD3\n");
}
break;
case 5:
if (rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD4_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int_cont &= ~DC_HPD4_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD4\n");
}
break;
case 10:
if (rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD5_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int_cont2 &= ~DC_HPD5_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD5\n");
}
break;
case 12:
if (rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD6_INTERRUPT) {
rdev->irq.stat_regs.r600.disp_int_cont2 &= ~DC_HPD6_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD6\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 21:
DRM_DEBUG("IH: HDMI: 0x%x\n", src_data);
r600_audio_schedule_polling(rdev);
break;
case 176:
case 177:
case 178:
DRM_DEBUG("IH: CP int: 0x%08x\n", src_data);
radeon_fence_process(rdev);
break;
case 181:
DRM_DEBUG("IH: CP EOP\n");
radeon_fence_process(rdev);
break;
case 233:
DRM_DEBUG("IH: GUI idle\n");
rdev->pm.gui_idle = true;
wake_up(&rdev->irq.idle_queue);
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
rptr += 16;
rptr &= rdev->ih.ptr_mask;
}
wptr = r600_get_ih_wptr(rdev);
if (wptr != rdev->ih.wptr)
goto restart_ih;
if (queue_hotplug)
schedule_work(&rdev->hotplug_work);
rdev->ih.rptr = rptr;
WREG32(IH_RB_RPTR, rdev->ih.rptr);
spin_unlock_irqrestore(&rdev->ih.lock, flags);
return IRQ_HANDLED;
}
static int r600_debugfs_cp_ring_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
unsigned count, i, j;
radeon_ring_free_size(rdev);
count = (rdev->cp.ring_size / 4) - rdev->cp.ring_free_dw;
seq_printf(m, "CP_STAT 0x%08x\n", RREG32(CP_STAT));
seq_printf(m, "CP_RB_WPTR 0x%08x\n", RREG32(CP_RB_WPTR));
seq_printf(m, "CP_RB_RPTR 0x%08x\n", RREG32(CP_RB_RPTR));
seq_printf(m, "driver's copy of the CP_RB_WPTR 0x%08x\n", rdev->cp.wptr);
seq_printf(m, "driver's copy of the CP_RB_RPTR 0x%08x\n", rdev->cp.rptr);
seq_printf(m, "%u free dwords in ring\n", rdev->cp.ring_free_dw);
seq_printf(m, "%u dwords in ring\n", count);
i = rdev->cp.rptr;
for (j = 0; j <= count; j++) {
seq_printf(m, "r[%04d]=0x%08x\n", i, rdev->cp.ring[i]);
i = (i + 1) & rdev->cp.ptr_mask;
}
return 0;
}
static int r600_debugfs_mc_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
DREG32_SYS(m, rdev, R_000E50_SRBM_STATUS);
DREG32_SYS(m, rdev, VM_L2_STATUS);
return 0;
}
int r600_debugfs_mc_info_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, r600_mc_info_list, ARRAY_SIZE(r600_mc_info_list));
#else
return 0;
#endif
}
void r600_ioctl_wait_idle(struct radeon_device *rdev, struct radeon_bo *bo)
{
if ((rdev->family >= CHIP_RV770) && (rdev->family <= CHIP_RV740) &&
rdev->vram_scratch.ptr && !(rdev->flags & RADEON_IS_AGP)) {
void __iomem *ptr = (void *)rdev->vram_scratch.ptr;
u32 tmp;
WREG32(HDP_DEBUG1, 0);
tmp = readl((void __iomem *)ptr);
} else
WREG32(R_005480_HDP_MEM_COHERENCY_FLUSH_CNTL, 0x1);
}
void r600_set_pcie_lanes(struct radeon_device *rdev, int lanes)
{
u32 link_width_cntl, mask, target_reg;
if (rdev->flags & RADEON_IS_IGP)
return;
if (!(rdev->flags & RADEON_IS_PCIE))
return;
if (ASIC_IS_X2(rdev))
return;
switch (lanes) {
case 0:
mask = RADEON_PCIE_LC_LINK_WIDTH_X0;
break;
case 1:
mask = RADEON_PCIE_LC_LINK_WIDTH_X1;
break;
case 2:
mask = RADEON_PCIE_LC_LINK_WIDTH_X2;
break;
case 4:
mask = RADEON_PCIE_LC_LINK_WIDTH_X4;
break;
case 8:
mask = RADEON_PCIE_LC_LINK_WIDTH_X8;
break;
case 12:
mask = RADEON_PCIE_LC_LINK_WIDTH_X12;
break;
case 16:
default:
mask = RADEON_PCIE_LC_LINK_WIDTH_X16;
break;
}
link_width_cntl = RREG32_PCIE_P(RADEON_PCIE_LC_LINK_WIDTH_CNTL);
if ((link_width_cntl & RADEON_PCIE_LC_LINK_WIDTH_RD_MASK) ==
(mask << RADEON_PCIE_LC_LINK_WIDTH_RD_SHIFT))
return;
if (link_width_cntl & R600_PCIE_LC_UPCONFIGURE_DIS)
return;
link_width_cntl &= ~(RADEON_PCIE_LC_LINK_WIDTH_MASK |
RADEON_PCIE_LC_RECONFIG_NOW |
R600_PCIE_LC_RENEGOTIATE_EN |
R600_PCIE_LC_RECONFIG_ARC_MISSING_ESCAPE);
link_width_cntl |= mask;
WREG32_PCIE_P(RADEON_PCIE_LC_LINK_WIDTH_CNTL, link_width_cntl);
if (link_width_cntl & R600_PCIE_LC_RENEGOTIATION_SUPPORT)
link_width_cntl |= R600_PCIE_LC_RENEGOTIATE_EN | R600_PCIE_LC_UPCONFIGURE_SUPPORT;
else
link_width_cntl |= R600_PCIE_LC_RECONFIG_ARC_MISSING_ESCAPE;
WREG32_PCIE_P(RADEON_PCIE_LC_LINK_WIDTH_CNTL, (link_width_cntl |
RADEON_PCIE_LC_RECONFIG_NOW));
if (rdev->family >= CHIP_RV770)
target_reg = R700_TARGET_AND_CURRENT_PROFILE_INDEX;
else
target_reg = R600_TARGET_AND_CURRENT_PROFILE_INDEX;
link_width_cntl = RREG32(target_reg);
while (link_width_cntl == 0xffffffff)
link_width_cntl = RREG32(target_reg);
}
int r600_get_pcie_lanes(struct radeon_device *rdev)
{
u32 link_width_cntl;
if (rdev->flags & RADEON_IS_IGP)
return 0;
if (!(rdev->flags & RADEON_IS_PCIE))
return 0;
if (ASIC_IS_X2(rdev))
return 0;
link_width_cntl = RREG32_PCIE_P(RADEON_PCIE_LC_LINK_WIDTH_CNTL);
switch ((link_width_cntl & RADEON_PCIE_LC_LINK_WIDTH_RD_MASK) >> RADEON_PCIE_LC_LINK_WIDTH_RD_SHIFT) {
case RADEON_PCIE_LC_LINK_WIDTH_X0:
return 0;
case RADEON_PCIE_LC_LINK_WIDTH_X1:
return 1;
case RADEON_PCIE_LC_LINK_WIDTH_X2:
return 2;
case RADEON_PCIE_LC_LINK_WIDTH_X4:
return 4;
case RADEON_PCIE_LC_LINK_WIDTH_X8:
return 8;
case RADEON_PCIE_LC_LINK_WIDTH_X16:
default:
return 16;
}
}
static void r600_pcie_gen2_enable(struct radeon_device *rdev)
{
u32 link_width_cntl, lanes, speed_cntl, training_cntl, tmp;
u16 link_cntl2;
if (radeon_pcie_gen2 == 0)
return;
if (rdev->flags & RADEON_IS_IGP)
return;
if (!(rdev->flags & RADEON_IS_PCIE))
return;
if (ASIC_IS_X2(rdev))
return;
if (rdev->family <= CHIP_R600)
return;
if ((rdev->family == CHIP_RV670) ||
(rdev->family == CHIP_RV620) ||
(rdev->family == CHIP_RV635)) {
link_width_cntl = RREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL);
link_width_cntl &= ~LC_UPCONFIGURE_DIS;
WREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL, link_width_cntl);
link_width_cntl = RREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL);
if (link_width_cntl & LC_RENEGOTIATION_SUPPORT) {
lanes = (link_width_cntl & LC_LINK_WIDTH_RD_MASK) >> LC_LINK_WIDTH_RD_SHIFT;
link_width_cntl &= ~(LC_LINK_WIDTH_MASK |
LC_RECONFIG_ARC_MISSING_ESCAPE);
link_width_cntl |= lanes | LC_RECONFIG_NOW | LC_RENEGOTIATE_EN;
WREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL, link_width_cntl);
} else {
link_width_cntl |= LC_UPCONFIGURE_DIS;
WREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL, link_width_cntl);
}
}
speed_cntl = RREG32_PCIE_P(PCIE_LC_SPEED_CNTL);
if ((speed_cntl & LC_OTHER_SIDE_EVER_SENT_GEN2) &&
(speed_cntl & LC_OTHER_SIDE_SUPPORTS_GEN2)) {
if ((rdev->family == CHIP_RV670) ||
(rdev->family == CHIP_RV620) ||
(rdev->family == CHIP_RV635)) {
WREG32(MM_CFGREGS_CNTL, 0x8);
link_cntl2 = RREG32(0x4088);
WREG32(MM_CFGREGS_CNTL, 0);
if (link_cntl2 & SELECTABLE_DEEMPHASIS)
return;
}
speed_cntl &= ~LC_SPEED_CHANGE_ATTEMPTS_ALLOWED_MASK;
speed_cntl |= (0x3 << LC_SPEED_CHANGE_ATTEMPTS_ALLOWED_SHIFT);
speed_cntl &= ~LC_VOLTAGE_TIMER_SEL_MASK;
speed_cntl &= ~LC_FORCE_DIS_HW_SPEED_CHANGE;
speed_cntl |= LC_FORCE_EN_HW_SPEED_CHANGE;
WREG32_PCIE_P(PCIE_LC_SPEED_CNTL, speed_cntl);
tmp = RREG32(0x541c);
WREG32(0x541c, tmp | 0x8);
WREG32(MM_CFGREGS_CNTL, MM_WR_TO_CFG_EN);
link_cntl2 = RREG16(0x4088);
link_cntl2 &= ~TARGET_LINK_SPEED_MASK;
link_cntl2 |= 0x2;
WREG16(0x4088, link_cntl2);
WREG32(MM_CFGREGS_CNTL, 0);
if ((rdev->family == CHIP_RV670) ||
(rdev->family == CHIP_RV620) ||
(rdev->family == CHIP_RV635)) {
training_cntl = RREG32_PCIE_P(PCIE_LC_TRAINING_CNTL);
training_cntl &= ~LC_POINT_7_PLUS_EN;
WREG32_PCIE_P(PCIE_LC_TRAINING_CNTL, training_cntl);
} else {
speed_cntl = RREG32_PCIE_P(PCIE_LC_SPEED_CNTL);
speed_cntl &= ~LC_TARGET_LINK_SPEED_OVERRIDE_EN;
WREG32_PCIE_P(PCIE_LC_SPEED_CNTL, speed_cntl);
}
speed_cntl = RREG32_PCIE_P(PCIE_LC_SPEED_CNTL);
speed_cntl |= LC_GEN2_EN_STRAP;
WREG32_PCIE_P(PCIE_LC_SPEED_CNTL, speed_cntl);
} else {
link_width_cntl = RREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL);
if (1)
link_width_cntl |= LC_UPCONFIGURE_DIS;
else
link_width_cntl &= ~LC_UPCONFIGURE_DIS;
WREG32_PCIE_P(PCIE_LC_LINK_WIDTH_CNTL, link_width_cntl);
}
}
