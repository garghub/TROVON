static int smu7_enable_didt(struct pp_hwmgr *hwmgr, const bool enable)
{
uint32_t en = enable ? 1 : 0;
int32_t result = 0;
uint32_t data;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_SQRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_CTRL0);
data &= ~DIDT_SQ_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_SQ_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_SQ_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_CTRL0, data);
DIDTBlock_Info &= ~SQ_Enable_MASK;
DIDTBlock_Info |= en << SQ_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_CTRL0);
data &= ~DIDT_DB_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_DB_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_DB_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_CTRL0, data);
DIDTBlock_Info &= ~DB_Enable_MASK;
DIDTBlock_Info |= en << DB_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TDRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_CTRL0);
data &= ~DIDT_TD_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_TD_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_TD_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_CTRL0, data);
DIDTBlock_Info &= ~TD_Enable_MASK;
DIDTBlock_Info |= en << TD_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TCPRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_CTRL0);
data &= ~DIDT_TCP_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_TCP_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_TCP_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_CTRL0, data);
DIDTBlock_Info &= ~TCP_Enable_MASK;
DIDTBlock_Info |= en << TCP_Enable_SHIFT;
}
if (enable)
result = smum_send_msg_to_smc_with_parameter(hwmgr->smumgr, PPSMC_MSG_Didt_Block_Function, DIDTBlock_Info);
return result;
}
static int smu7_program_pt_config_registers(struct pp_hwmgr *hwmgr,
const struct gpu_pt_config_reg *cac_config_regs)
{
const struct gpu_pt_config_reg *config_regs = cac_config_regs;
uint32_t cache = 0;
uint32_t data = 0;
PP_ASSERT_WITH_CODE((config_regs != NULL), "Invalid config register table.", return -EINVAL);
while (config_regs->offset != 0xFFFFFFFF) {
if (config_regs->type == GPU_CONFIGREG_CACHE)
cache |= ((config_regs->value << config_regs->shift) & config_regs->mask);
else {
switch (config_regs->type) {
case GPU_CONFIGREG_SMC_IND:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__SMC, config_regs->offset);
break;
case GPU_CONFIGREG_DIDT_IND:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, config_regs->offset);
break;
case GPU_CONFIGREG_GC_CAC_IND:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG_GC_CAC, config_regs->offset);
break;
default:
data = cgs_read_register(hwmgr->device, config_regs->offset);
break;
}
data &= ~config_regs->mask;
data |= ((config_regs->value << config_regs->shift) & config_regs->mask);
data |= cache;
switch (config_regs->type) {
case GPU_CONFIGREG_SMC_IND:
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__SMC, config_regs->offset, data);
break;
case GPU_CONFIGREG_DIDT_IND:
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, config_regs->offset, data);
break;
case GPU_CONFIGREG_GC_CAC_IND:
cgs_write_ind_register(hwmgr->device, CGS_IND_REG_GC_CAC, config_regs->offset, data);
break;
default:
cgs_write_register(hwmgr->device, config_regs->offset, data);
break;
}
cache = 0;
}
config_regs++;
}
return 0;
}
int smu7_enable_didt_config(struct pp_hwmgr *hwmgr)
{
int result;
uint32_t num_se = 0;
uint32_t count, value, value2;
struct cgs_system_info sys_info = {0};
sys_info.size = sizeof(struct cgs_system_info);
sys_info.info_id = CGS_SYSTEM_INFO_GFX_SE_INFO;
result = cgs_query_system_info(hwmgr->device, &sys_info);
if (result == 0)
num_se = sys_info.value;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_SQRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TDRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TCPRamping)) {
value = 0;
value2 = cgs_read_register(hwmgr->device, mmGRBM_GFX_INDEX);
for (count = 0; count < num_se; count++) {
value = SYS_GRBM_GFX_INDEX_DATA__INSTANCE_BROADCAST_WRITES_MASK
| SYS_GRBM_GFX_INDEX_DATA__SH_BROADCAST_WRITES_MASK
| (count << SYS_GRBM_GFX_INDEX_DATA__SE_INDEX__SHIFT);
cgs_write_register(hwmgr->device, mmGRBM_GFX_INDEX, value);
if (hwmgr->chip_id == CHIP_POLARIS10) {
result = smu7_program_pt_config_registers(hwmgr, GCCACConfig_Polaris10);
PP_ASSERT_WITH_CODE((result == 0), "DIDT Config failed.", return result);
result = smu7_program_pt_config_registers(hwmgr, DIDTConfig_Polaris10);
PP_ASSERT_WITH_CODE((result == 0), "DIDT Config failed.", return result);
} else if ((hwmgr->chip_id == CHIP_POLARIS11) || (hwmgr->chip_id == CHIP_POLARIS12)) {
result = smu7_program_pt_config_registers(hwmgr, GCCACConfig_Polaris11);
PP_ASSERT_WITH_CODE((result == 0), "DIDT Config failed.", return result);
result = smu7_program_pt_config_registers(hwmgr, DIDTConfig_Polaris11);
PP_ASSERT_WITH_CODE((result == 0), "DIDT Config failed.", return result);
}
}
cgs_write_register(hwmgr->device, mmGRBM_GFX_INDEX, value2);
result = smu7_enable_didt(hwmgr, true);
PP_ASSERT_WITH_CODE((result == 0), "EnableDiDt failed.", return result);
}
return 0;
}
int smu7_disable_didt_config(struct pp_hwmgr *hwmgr)
{
int result;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_SQRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TDRamping) ||
phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TCPRamping)) {
result = smu7_enable_didt(hwmgr, false);
PP_ASSERT_WITH_CODE((result == 0), "Post DIDT enable clock gating failed.", return result);
}
return 0;
}
int smu7_enable_smc_cac(struct pp_hwmgr *hwmgr)
{
struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
int result = 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_CAC)) {
int smc_result;
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_EnableCac));
PP_ASSERT_WITH_CODE((0 == smc_result),
"Failed to enable CAC in SMC.", result = -1);
data->cac_enabled = (0 == smc_result) ? true : false;
}
return result;
}
int smu7_disable_smc_cac(struct pp_hwmgr *hwmgr)
{
struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
int result = 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_CAC) && data->cac_enabled) {
int smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_DisableCac));
PP_ASSERT_WITH_CODE((smc_result == 0),
"Failed to disable CAC in SMC.", result = -1);
data->cac_enabled = false;
}
return result;
}
int smu7_set_power_limit(struct pp_hwmgr *hwmgr, uint32_t n)
{
struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
if (data->power_containment_features &
POWERCONTAINMENT_FEATURE_PkgPwrLimit)
return smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_PkgPwrSetLimit, n);
return 0;
}
static int smu7_set_overdriver_target_tdp(struct pp_hwmgr *hwmgr,
uint32_t target_tdp)
{
return smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_OverDriveSetTargetTdp, target_tdp);
}
int smu7_enable_power_containment(struct pp_hwmgr *hwmgr)
{
struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
struct phm_ppt_v1_information *table_info =
(struct phm_ppt_v1_information *)(hwmgr->pptable);
int smc_result;
int result = 0;
struct phm_cac_tdp_table *cac_table;
data->power_containment_features = 0;
if (hwmgr->pp_table_version == PP_TABLE_V1)
cac_table = table_info->cac_dtp_table;
else
cac_table = hwmgr->dyn_state.cac_dtp_table;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment)) {
if (data->enable_tdc_limit_feature) {
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_TDCLimitEnable));
PP_ASSERT_WITH_CODE((0 == smc_result),
"Failed to enable TDCLimit in SMC.", result = -1;);
if (0 == smc_result)
data->power_containment_features |=
POWERCONTAINMENT_FEATURE_TDCLimit;
}
if (data->enable_pkg_pwr_tracking_feature) {
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_PkgPwrLimitEnable));
PP_ASSERT_WITH_CODE((0 == smc_result),
"Failed to enable PkgPwrTracking in SMC.", result = -1;);
if (0 == smc_result) {
uint32_t default_limit =
(uint32_t)(cac_table->usMaximumPowerDeliveryLimit * 256);
data->power_containment_features |=
POWERCONTAINMENT_FEATURE_PkgPwrLimit;
if (smu7_set_power_limit(hwmgr, default_limit))
printk(KERN_ERR "Failed to set Default Power Limit in SMC!");
}
}
}
return result;
}
int smu7_disable_power_containment(struct pp_hwmgr *hwmgr)
{
struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
int result = 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment) &&
data->power_containment_features) {
int smc_result;
if (data->power_containment_features &
POWERCONTAINMENT_FEATURE_TDCLimit) {
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_TDCLimitDisable));
PP_ASSERT_WITH_CODE((smc_result == 0),
"Failed to disable TDCLimit in SMC.",
result = smc_result);
}
if (data->power_containment_features &
POWERCONTAINMENT_FEATURE_DTE) {
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_DisableDTE));
PP_ASSERT_WITH_CODE((smc_result == 0),
"Failed to disable DTE in SMC.",
result = smc_result);
}
if (data->power_containment_features &
POWERCONTAINMENT_FEATURE_PkgPwrLimit) {
smc_result = smum_send_msg_to_smc(hwmgr->smumgr,
(uint16_t)(PPSMC_MSG_PkgPwrLimitDisable));
PP_ASSERT_WITH_CODE((smc_result == 0),
"Failed to disable PkgPwrTracking in SMC.",
result = smc_result);
}
data->power_containment_features = 0;
}
return result;
}
int smu7_power_control_set_level(struct pp_hwmgr *hwmgr)
{
struct phm_ppt_v1_information *table_info =
(struct phm_ppt_v1_information *)(hwmgr->pptable);
struct phm_cac_tdp_table *cac_table;
int adjust_percent, target_tdp;
int result = 0;
if (hwmgr->pp_table_version == PP_TABLE_V1)
cac_table = table_info->cac_dtp_table;
else
cac_table = hwmgr->dyn_state.cac_dtp_table;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment)) {
adjust_percent = hwmgr->platform_descriptor.TDPAdjustmentPolarity ?
hwmgr->platform_descriptor.TDPAdjustment :
(-1 * hwmgr->platform_descriptor.TDPAdjustment);
target_tdp = ((100 + adjust_percent) * (int)(cac_table->usTDP * 256)) / 100;
result = smu7_set_overdriver_target_tdp(hwmgr, (uint32_t)target_tdp);
}
return result;
}
