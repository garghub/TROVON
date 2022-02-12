int cz_phm_set_asic_block_gating(struct pp_hwmgr *hwmgr, enum PHM_AsicBlock block, enum PHM_ClockGateSetting gating)
{
int ret = 0;
switch (block) {
case PHM_AsicBlock_UVD_MVC:
case PHM_AsicBlock_UVD:
case PHM_AsicBlock_UVD_HD:
case PHM_AsicBlock_UVD_SD:
if (gating == PHM_ClockGateSetting_StaticOff)
ret = cz_dpm_powerdown_uvd(hwmgr);
else
ret = cz_dpm_powerup_uvd(hwmgr);
break;
case PHM_AsicBlock_GFX:
default:
break;
}
return ret;
}
bool cz_phm_is_safe_for_asic_block(struct pp_hwmgr *hwmgr, const struct pp_hw_power_state *state, enum PHM_AsicBlock block)
{
return true;
}
int cz_phm_enable_disable_gfx_power_gating(struct pp_hwmgr *hwmgr, bool enable)
{
return 0;
}
int cz_phm_smu_power_up_down_pcie(struct pp_hwmgr *hwmgr, uint32_t target, bool up, uint32_t args)
{
return 0;
}
int cz_phm_initialize_display_phy_access(struct pp_hwmgr *hwmgr, bool initialize, bool accesshw)
{
return 0;
}
int cz_phm_get_display_phy_access_info(struct pp_hwmgr *hwmgr)
{
return 0;
}
int cz_phm_gate_unused_display_phys(struct pp_hwmgr *hwmgr)
{
return 0;
}
int cz_phm_ungate_all_display_phys(struct pp_hwmgr *hwmgr)
{
return 0;
}
static int cz_tf_uvd_power_gating_initialize(struct pp_hwmgr *hwmgr, void *pInput, void *pOutput, void *pStorage, int Result)
{
return 0;
}
static int cz_tf_vce_power_gating_initialize(struct pp_hwmgr *hwmgr, void *pInput, void *pOutput, void *pStorage, int Result)
{
return 0;
}
int cz_enable_disable_uvd_dpm(struct pp_hwmgr *hwmgr, bool enable)
{
struct cz_hwmgr *cz_hwmgr = (struct cz_hwmgr *)(hwmgr->backend);
uint32_t dpm_features = 0;
if (enable &&
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_UVDDPM)) {
cz_hwmgr->dpm_flags |= DPMFlags_UVD_Enabled;
dpm_features |= UVD_DPM_MASK;
smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_EnableAllSmuFeatures, dpm_features);
} else {
dpm_features |= UVD_DPM_MASK;
cz_hwmgr->dpm_flags &= ~DPMFlags_UVD_Enabled;
smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_DisableAllSmuFeatures, dpm_features);
}
return 0;
}
int cz_enable_disable_vce_dpm(struct pp_hwmgr *hwmgr, bool enable)
{
struct cz_hwmgr *cz_hwmgr = (struct cz_hwmgr *)(hwmgr->backend);
uint32_t dpm_features = 0;
if (enable && phm_cap_enabled(
hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_VCEDPM)) {
cz_hwmgr->dpm_flags |= DPMFlags_VCE_Enabled;
dpm_features |= VCE_DPM_MASK;
smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_EnableAllSmuFeatures, dpm_features);
} else {
dpm_features |= VCE_DPM_MASK;
cz_hwmgr->dpm_flags &= ~DPMFlags_VCE_Enabled;
smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_DisableAllSmuFeatures, dpm_features);
}
return 0;
}
int cz_dpm_powergate_uvd(struct pp_hwmgr *hwmgr, bool bgate)
{
struct cz_hwmgr *cz_hwmgr = (struct cz_hwmgr *)(hwmgr->backend);
if (cz_hwmgr->uvd_power_gated == bgate)
return 0;
cz_hwmgr->uvd_power_gated = bgate;
if (bgate) {
cgs_set_clockgating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_CG_STATE_UNGATE);
cgs_set_powergating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_PG_STATE_GATE);
cz_dpm_update_uvd_dpm(hwmgr, true);
cz_dpm_powerdown_uvd(hwmgr);
} else {
cz_dpm_powerup_uvd(hwmgr);
cgs_set_clockgating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_PG_STATE_GATE);
cgs_set_powergating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_CG_STATE_UNGATE);
cz_dpm_update_uvd_dpm(hwmgr, false);
}
return 0;
}
int cz_dpm_powergate_vce(struct pp_hwmgr *hwmgr, bool bgate)
{
struct cz_hwmgr *cz_hwmgr = (struct cz_hwmgr *)(hwmgr->backend);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_VCEPowerGating)) {
if (cz_hwmgr->vce_power_gated != bgate) {
if (bgate) {
cgs_set_clockgating_state(
hwmgr->device,
AMD_IP_BLOCK_TYPE_VCE,
AMD_CG_STATE_UNGATE);
cgs_set_powergating_state(
hwmgr->device,
AMD_IP_BLOCK_TYPE_VCE,
AMD_PG_STATE_GATE);
cz_enable_disable_vce_dpm(hwmgr, false);
cz_hwmgr->vce_power_gated = true;
} else {
cz_dpm_powerup_vce(hwmgr);
cz_hwmgr->vce_power_gated = false;
cgs_set_clockgating_state(
hwmgr->device,
AMD_IP_BLOCK_TYPE_VCE,
AMD_PG_STATE_GATE);
cgs_set_powergating_state(
hwmgr->device,
AMD_IP_BLOCK_TYPE_VCE,
AMD_CG_STATE_UNGATE);
cz_dpm_update_vce_dpm(hwmgr);
cz_enable_disable_vce_dpm(hwmgr, true);
return 0;
}
}
} else {
cz_dpm_update_vce_dpm(hwmgr);
cz_enable_disable_vce_dpm(hwmgr, !bgate);
return 0;
}
if (!cz_hwmgr->vce_power_gated)
cz_dpm_update_vce_dpm(hwmgr);
return 0;
}
