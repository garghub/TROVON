int fiji_phm_disable_clock_power_gating(struct pp_hwmgr *hwmgr)
{
struct fiji_hwmgr *data = (struct fiji_hwmgr *)(hwmgr->backend);
data->uvd_power_gated = false;
data->vce_power_gated = false;
data->samu_power_gated = false;
data->acp_power_gated = false;
return 0;
}
int fiji_phm_powergate_uvd(struct pp_hwmgr *hwmgr, bool bgate)
{
struct fiji_hwmgr *data = (struct fiji_hwmgr *)(hwmgr->backend);
if (data->uvd_power_gated == bgate)
return 0;
data->uvd_power_gated = bgate;
if (bgate) {
cgs_set_clockgating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_CG_STATE_GATE);
fiji_update_uvd_dpm(hwmgr, true);
} else {
fiji_update_uvd_dpm(hwmgr, false);
cgs_set_clockgating_state(hwmgr->device,
AMD_IP_BLOCK_TYPE_UVD,
AMD_CG_STATE_UNGATE);
}
return 0;
}
int fiji_phm_powergate_vce(struct pp_hwmgr *hwmgr, bool bgate)
{
struct fiji_hwmgr *data = (struct fiji_hwmgr *)(hwmgr->backend);
struct phm_set_power_state_input states;
const struct pp_power_state *pcurrent;
struct pp_power_state *requested;
if (data->vce_power_gated == bgate)
return 0;
data->vce_power_gated = bgate;
pcurrent = hwmgr->current_ps;
requested = hwmgr->request_ps;
states.pcurrent_state = &(pcurrent->hardware);
states.pnew_state = &(requested->hardware);
fiji_update_vce_dpm(hwmgr, &states);
fiji_enable_disable_vce_dpm(hwmgr, !bgate);
return 0;
}
int fiji_phm_powergate_samu(struct pp_hwmgr *hwmgr, bool bgate)
{
struct fiji_hwmgr *data = (struct fiji_hwmgr *)(hwmgr->backend);
if (data->samu_power_gated == bgate)
return 0;
data->samu_power_gated = bgate;
if (bgate)
fiji_update_samu_dpm(hwmgr, true);
else
fiji_update_samu_dpm(hwmgr, false);
return 0;
}
int fiji_phm_powergate_acp(struct pp_hwmgr *hwmgr, bool bgate)
{
struct fiji_hwmgr *data = (struct fiji_hwmgr *)(hwmgr->backend);
if (data->acp_power_gated == bgate)
return 0;
data->acp_power_gated = bgate;
if (bgate)
fiji_update_acp_dpm(hwmgr, true);
else
fiji_update_acp_dpm(hwmgr, false);
return 0;
}
