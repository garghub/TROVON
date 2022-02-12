static int trinity_notify_message_to_smu(struct radeon_device *rdev, u32 id)
{
int i;
u32 v = 0;
WREG32(SMC_MESSAGE_0, id);
for (i = 0; i < rdev->usec_timeout; i++) {
if (RREG32(SMC_RESP_0) != 0)
break;
udelay(1);
}
v = RREG32(SMC_RESP_0);
if (v != 1) {
if (v == 0xFF) {
DRM_ERROR("SMC failed to handle the message!\n");
return -EINVAL;
} else if (v == 0xFE) {
DRM_ERROR("Unknown SMC message!\n");
return -EINVAL;
}
}
return 0;
}
int trinity_dpm_config(struct radeon_device *rdev, bool enable)
{
if (enable)
WREG32_SMC(SMU_SCRATCH0, 1);
else
WREG32_SMC(SMU_SCRATCH0, 0);
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_DPM_Config);
}
int trinity_dpm_force_state(struct radeon_device *rdev, u32 n)
{
WREG32_SMC(SMU_SCRATCH0, n);
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_DPM_ForceState);
}
int trinity_dpm_n_levels_disabled(struct radeon_device *rdev, u32 n)
{
WREG32_SMC(SMU_SCRATCH0, n);
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_DPM_N_LevelsDisabled);
}
int trinity_uvd_dpm_config(struct radeon_device *rdev)
{
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_UVD_DPM_Config);
}
int trinity_dpm_no_forced_level(struct radeon_device *rdev)
{
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_NoForcedLevel);
}
int trinity_dce_enable_voltage_adjustment(struct radeon_device *rdev,
bool enable)
{
if (enable)
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_DCE_AllowVoltageAdjustment);
else
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_DCE_RemoveVoltageAdjustment);
}
int trinity_gfx_dynamic_mgpg_config(struct radeon_device *rdev)
{
return trinity_notify_message_to_smu(rdev, PPSMC_MSG_PG_SIMD_Config);
}
void trinity_acquire_mutex(struct radeon_device *rdev)
{
int i;
WREG32(SMC_INT_REQ, 1);
for (i = 0; i < rdev->usec_timeout; i++) {
if ((RREG32(SMC_INT_REQ) & 0xffff) == 1)
break;
udelay(1);
}
}
void trinity_release_mutex(struct radeon_device *rdev)
{
WREG32(SMC_INT_REQ, 0);
}
