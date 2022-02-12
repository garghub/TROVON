static int vega10_program_didt_config_registers(struct pp_hwmgr *hwmgr, const struct vega10_didt_config_reg *config_regs, enum vega10_didt_config_reg_type reg_type)
{
uint32_t data;
PP_ASSERT_WITH_CODE((config_regs != NULL), "[vega10_program_didt_config_registers] Invalid config register table!", return -EINVAL);
while (config_regs->offset != 0xFFFFFFFF) {
switch (reg_type) {
case VEGA10_CONFIGREG_DIDT:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, config_regs->offset);
data &= ~config_regs->mask;
data |= ((config_regs->value << config_regs->shift) & config_regs->mask);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, config_regs->offset, data);
break;
case VEGA10_CONFIGREG_GCCAC:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG_GC_CAC, config_regs->offset);
data &= ~config_regs->mask;
data |= ((config_regs->value << config_regs->shift) & config_regs->mask);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG_GC_CAC, config_regs->offset, data);
break;
case VEGA10_CONFIGREG_SECAC:
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG_SE_CAC, config_regs->offset);
data &= ~config_regs->mask;
data |= ((config_regs->value << config_regs->shift) & config_regs->mask);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG_SE_CAC, config_regs->offset, data);
break;
default:
return -EINVAL;
}
config_regs++;
}
return 0;
}
static int vega10_program_gc_didt_config_registers(struct pp_hwmgr *hwmgr, const struct vega10_didt_config_reg *config_regs)
{
uint32_t data;
while (config_regs->offset != 0xFFFFFFFF) {
data = cgs_read_register(hwmgr->device, config_regs->offset);
data &= ~config_regs->mask;
data |= ((config_regs->value << config_regs->shift) & config_regs->mask);
cgs_write_register(hwmgr->device, config_regs->offset, data);
config_regs++;
}
return 0;
}
static void vega10_didt_set_mask(struct pp_hwmgr *hwmgr, const bool enable)
{
uint32_t data;
int result;
uint32_t en = (enable ? 1 : 0);
uint32_t didt_block_info = SQ_IR_MASK | TCP_IR_MASK | TD_PCC_MASK;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_SQRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_CTRL0);
data &= ~DIDT_SQ_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_SQ_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_SQ_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_CTRL0, data);
didt_block_info &= ~SQ_Enable_MASK;
didt_block_info |= en << SQ_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_CTRL0);
data &= ~DIDT_DB_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_DB_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_DB_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_CTRL0, data);
didt_block_info &= ~DB_Enable_MASK;
didt_block_info |= en << DB_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TDRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_CTRL0);
data &= ~DIDT_TD_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_TD_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_TD_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_CTRL0, data);
didt_block_info &= ~TD_Enable_MASK;
didt_block_info |= en << TD_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TCPRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_CTRL0);
data &= ~DIDT_TCP_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_TCP_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_TCP_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_CTRL0, data);
didt_block_info &= ~TCP_Enable_MASK;
didt_block_info |= en << TCP_Enable_SHIFT;
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DBR_CTRL0);
data &= ~DIDT_DBR_CTRL0__DIDT_CTRL_EN_MASK;
data |= ((en << DIDT_DBR_CTRL0__DIDT_CTRL_EN__SHIFT) & DIDT_DBR_CTRL0__DIDT_CTRL_EN_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DBR_CTRL0, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DiDtEDCEnable)) {
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_SQRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_EDC_CTRL);
data &= ~DIDT_SQ_EDC_CTRL__EDC_EN_MASK;
data |= ((en << DIDT_SQ_EDC_CTRL__EDC_EN__SHIFT) & DIDT_SQ_EDC_CTRL__EDC_EN_MASK);
data &= ~DIDT_SQ_EDC_CTRL__EDC_SW_RST_MASK;
data |= ((~en << DIDT_SQ_EDC_CTRL__EDC_SW_RST__SHIFT) & DIDT_SQ_EDC_CTRL__EDC_SW_RST_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_SQ_EDC_CTRL, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_EDC_CTRL);
data &= ~DIDT_DB_EDC_CTRL__EDC_EN_MASK;
data |= ((en << DIDT_DB_EDC_CTRL__EDC_EN__SHIFT) & DIDT_DB_EDC_CTRL__EDC_EN_MASK);
data &= ~DIDT_DB_EDC_CTRL__EDC_SW_RST_MASK;
data |= ((~en << DIDT_DB_EDC_CTRL__EDC_SW_RST__SHIFT) & DIDT_DB_EDC_CTRL__EDC_SW_RST_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DB_EDC_CTRL, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TDRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_EDC_CTRL);
data &= ~DIDT_TD_EDC_CTRL__EDC_EN_MASK;
data |= ((en << DIDT_TD_EDC_CTRL__EDC_EN__SHIFT) & DIDT_TD_EDC_CTRL__EDC_EN_MASK);
data &= ~DIDT_TD_EDC_CTRL__EDC_SW_RST_MASK;
data |= ((~en << DIDT_TD_EDC_CTRL__EDC_SW_RST__SHIFT) & DIDT_TD_EDC_CTRL__EDC_SW_RST_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TD_EDC_CTRL, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_TCPRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_EDC_CTRL);
data &= ~DIDT_TCP_EDC_CTRL__EDC_EN_MASK;
data |= ((en << DIDT_TCP_EDC_CTRL__EDC_EN__SHIFT) & DIDT_TCP_EDC_CTRL__EDC_EN_MASK);
data &= ~DIDT_TCP_EDC_CTRL__EDC_SW_RST_MASK;
data |= ((~en << DIDT_TCP_EDC_CTRL__EDC_SW_RST__SHIFT) & DIDT_TCP_EDC_CTRL__EDC_SW_RST_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_TCP_EDC_CTRL, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_DBRRamping)) {
data = cgs_read_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DBR_EDC_CTRL);
data &= ~DIDT_DBR_EDC_CTRL__EDC_EN_MASK;
data |= ((en << DIDT_DBR_EDC_CTRL__EDC_EN__SHIFT) & DIDT_DBR_EDC_CTRL__EDC_EN_MASK);
data &= ~DIDT_DBR_EDC_CTRL__EDC_SW_RST_MASK;
data |= ((~en << DIDT_DBR_EDC_CTRL__EDC_SW_RST__SHIFT) & DIDT_DBR_EDC_CTRL__EDC_SW_RST_MASK);
cgs_write_ind_register(hwmgr->device, CGS_IND_REG__DIDT, ixDIDT_DBR_EDC_CTRL, data);
}
}
if (enable) {
result = smum_send_msg_to_smc_with_parameter(hwmgr->smumgr, PPSMC_MSG_ConfigureGfxDidt, didt_block_info);
PP_ASSERT((0 == result), "[EnableDiDtConfig] SMC Configure Gfx Didt Failed!");
}
}
static int vega10_enable_cac_driving_se_didt_config(struct pp_hwmgr *hwmgr)
{
int result;
uint32_t num_se = 0, count, data;
struct cgs_system_info sys_info = {0};
uint32_t reg;
sys_info.size = sizeof(struct cgs_system_info);
sys_info.info_id = CGS_SYSTEM_INFO_GFX_SE_INFO;
if (cgs_query_system_info(hwmgr->device, &sys_info) == 0)
num_se = sys_info.value;
cgs_enter_safe_mode(hwmgr->device, true);
cgs_lock_grbm_idx(hwmgr->device, true);
reg = soc15_get_register_offset(GC_HWID, 0, mmGRBM_GFX_INDEX_BASE_IDX, mmGRBM_GFX_INDEX);
for (count = 0; count < num_se; count++) {
data = GRBM_GFX_INDEX__INSTANCE_BROADCAST_WRITES_MASK | GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK | ( count << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
cgs_write_register(hwmgr->device, reg, data);
result = vega10_program_didt_config_registers(hwmgr, SEDiDtStallCtrlConfig_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtStallPatternConfig_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtWeightConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl1Config_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl2Config_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl3Config_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtTuningCtrlConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SELCacConfig_Vega10, VEGA10_CONFIGREG_SECAC);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl0Config_Vega10, VEGA10_CONFIGREG_DIDT);
if (0 != result)
break;
}
cgs_write_register(hwmgr->device, reg, 0xE0000000);
cgs_lock_grbm_idx(hwmgr->device, false);
vega10_didt_set_mask(hwmgr, true);
cgs_enter_safe_mode(hwmgr->device, false);
return 0;
}
static int vega10_disable_cac_driving_se_didt_config(struct pp_hwmgr *hwmgr)
{
cgs_enter_safe_mode(hwmgr->device, true);
vega10_didt_set_mask(hwmgr, false);
cgs_enter_safe_mode(hwmgr->device, false);
return 0;
}
static int vega10_enable_psm_gc_didt_config(struct pp_hwmgr *hwmgr)
{
int result;
uint32_t num_se = 0, count, data;
struct cgs_system_info sys_info = {0};
uint32_t reg;
sys_info.size = sizeof(struct cgs_system_info);
sys_info.info_id = CGS_SYSTEM_INFO_GFX_SE_INFO;
if (cgs_query_system_info(hwmgr->device, &sys_info) == 0)
num_se = sys_info.value;
cgs_enter_safe_mode(hwmgr->device, true);
cgs_lock_grbm_idx(hwmgr->device, true);
reg = soc15_get_register_offset(GC_HWID, 0, mmGRBM_GFX_INDEX_BASE_IDX, mmGRBM_GFX_INDEX);
for (count = 0; count < num_se; count++) {
data = GRBM_GFX_INDEX__INSTANCE_BROADCAST_WRITES_MASK | GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK | ( count << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
cgs_write_register(hwmgr->device, reg, data);
result = vega10_program_didt_config_registers(hwmgr, SEDiDtStallCtrlConfig_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtStallPatternConfig_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl3Config_vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEDiDtCtrl0Config_Vega10, VEGA10_CONFIGREG_DIDT);
if (0 != result)
break;
}
cgs_write_register(hwmgr->device, reg, 0xE0000000);
cgs_lock_grbm_idx(hwmgr->device, false);
vega10_didt_set_mask(hwmgr, true);
cgs_enter_safe_mode(hwmgr->device, false);
vega10_program_gc_didt_config_registers(hwmgr, GCDiDtDroopCtrlConfig_vega10);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_GCEDC))
vega10_program_gc_didt_config_registers(hwmgr, GCDiDtCtrl0Config_vega10);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_PSM))
vega10_program_gc_didt_config_registers(hwmgr, AvfsPSMInitConfig_vega10);
return 0;
}
static int vega10_disable_psm_gc_didt_config(struct pp_hwmgr *hwmgr)
{
uint32_t data;
cgs_enter_safe_mode(hwmgr->device, true);
vega10_didt_set_mask(hwmgr, false);
cgs_enter_safe_mode(hwmgr->device, false);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_GCEDC)) {
data = 0x00000000;
cgs_write_register(hwmgr->device, mmGC_DIDT_CTRL0, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_PSM))
vega10_program_gc_didt_config_registers(hwmgr, AvfsPSMResetConfig_vega10);
return 0;
}
static int vega10_enable_se_edc_config(struct pp_hwmgr *hwmgr)
{
int result;
uint32_t num_se = 0, count, data;
struct cgs_system_info sys_info = {0};
uint32_t reg;
sys_info.size = sizeof(struct cgs_system_info);
sys_info.info_id = CGS_SYSTEM_INFO_GFX_SE_INFO;
if (cgs_query_system_info(hwmgr->device, &sys_info) == 0)
num_se = sys_info.value;
cgs_enter_safe_mode(hwmgr->device, true);
cgs_lock_grbm_idx(hwmgr->device, true);
reg = soc15_get_register_offset(GC_HWID, 0, mmGRBM_GFX_INDEX_BASE_IDX, mmGRBM_GFX_INDEX);
for (count = 0; count < num_se; count++) {
data = GRBM_GFX_INDEX__INSTANCE_BROADCAST_WRITES_MASK | GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK | ( count << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
cgs_write_register(hwmgr->device, reg, data);
result = vega10_program_didt_config_registers(hwmgr, SEDiDtWeightConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCStallPatternConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCStallDelayConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCThresholdConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCCtrlResetConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCCtrlConfig_Vega10, VEGA10_CONFIGREG_DIDT);
if (0 != result)
break;
}
cgs_write_register(hwmgr->device, reg, 0xE0000000);
cgs_lock_grbm_idx(hwmgr->device, false);
vega10_didt_set_mask(hwmgr, true);
cgs_enter_safe_mode(hwmgr->device, false);
return 0;
}
static int vega10_disable_se_edc_config(struct pp_hwmgr *hwmgr)
{
cgs_enter_safe_mode(hwmgr->device, true);
vega10_didt_set_mask(hwmgr, false);
cgs_enter_safe_mode(hwmgr->device, false);
return 0;
}
static int vega10_enable_psm_gc_edc_config(struct pp_hwmgr *hwmgr)
{
int result;
uint32_t num_se = 0;
uint32_t count, data;
struct cgs_system_info sys_info = {0};
uint32_t reg;
sys_info.size = sizeof(struct cgs_system_info);
sys_info.info_id = CGS_SYSTEM_INFO_GFX_SE_INFO;
if (cgs_query_system_info(hwmgr->device, &sys_info) == 0)
num_se = sys_info.value;
cgs_enter_safe_mode(hwmgr->device, true);
vega10_program_gc_didt_config_registers(hwmgr, AvfsPSMResetConfig_vega10);
cgs_lock_grbm_idx(hwmgr->device, true);
reg = soc15_get_register_offset(GC_HWID, 0, mmGRBM_GFX_INDEX_BASE_IDX, mmGRBM_GFX_INDEX);
for (count = 0; count < num_se; count++) {
data = GRBM_GFX_INDEX__INSTANCE_BROADCAST_WRITES_MASK | GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK | ( count << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
cgs_write_register(hwmgr->device, reg, data);
result |= vega10_program_didt_config_registers(hwmgr, PSMSEEDCStallPatternConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, PSMSEEDCStallDelayConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, PSMSEEDCCtrlResetConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, PSMSEEDCCtrlConfig_Vega10, VEGA10_CONFIGREG_DIDT);
if (0 != result)
break;
}
cgs_write_register(hwmgr->device, reg, 0xE0000000);
cgs_lock_grbm_idx(hwmgr->device, false);
vega10_didt_set_mask(hwmgr, true);
cgs_enter_safe_mode(hwmgr->device, false);
vega10_program_gc_didt_config_registers(hwmgr, PSMGCEDCDroopCtrlConfig_vega10);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_GCEDC)) {
vega10_program_gc_didt_config_registers(hwmgr, PSMGCEDCCtrlResetConfig_vega10);
vega10_program_gc_didt_config_registers(hwmgr, PSMGCEDCCtrlConfig_vega10);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_PSM))
vega10_program_gc_didt_config_registers(hwmgr, AvfsPSMInitConfig_vega10);
return 0;
}
static int vega10_disable_psm_gc_edc_config(struct pp_hwmgr *hwmgr)
{
uint32_t data;
cgs_enter_safe_mode(hwmgr->device, true);
vega10_didt_set_mask(hwmgr, false);
cgs_enter_safe_mode(hwmgr->device, false);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_GCEDC)) {
data = 0x00000000;
cgs_write_register(hwmgr->device, mmGC_EDC_CTRL, data);
}
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps, PHM_PlatformCaps_PSM))
vega10_program_gc_didt_config_registers(hwmgr, AvfsPSMResetConfig_vega10);
return 0;
}
static int vega10_enable_se_edc_force_stall_config(struct pp_hwmgr *hwmgr)
{
uint32_t reg;
int result;
cgs_enter_safe_mode(hwmgr->device, true);
cgs_lock_grbm_idx(hwmgr->device, true);
reg = soc15_get_register_offset(GC_HWID, 0, mmGRBM_GFX_INDEX_BASE_IDX, mmGRBM_GFX_INDEX);
cgs_write_register(hwmgr->device, reg, 0xE0000000);
cgs_lock_grbm_idx(hwmgr->device, false);
result = vega10_program_didt_config_registers(hwmgr, SEEDCForceStallPatternConfig_Vega10, VEGA10_CONFIGREG_DIDT);
result |= vega10_program_didt_config_registers(hwmgr, SEEDCCtrlForceStallConfig_Vega10, VEGA10_CONFIGREG_DIDT);
if (0 != result)
return result;
vega10_didt_set_mask(hwmgr, false);
cgs_enter_safe_mode(hwmgr->device, false);
return 0;
}
static int vega10_disable_se_edc_force_stall_config(struct pp_hwmgr *hwmgr)
{
int result;
result = vega10_disable_se_edc_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDtConfig] Pre DIDT disable clock gating failed!", return result);
return 0;
}
int vega10_enable_didt_config(struct pp_hwmgr *hwmgr)
{
int result = 0;
struct vega10_hwmgr *data = (struct vega10_hwmgr *)(hwmgr->backend);
if (data->smu_features[GNLD_DIDT].supported) {
if (data->smu_features[GNLD_DIDT].enabled)
PP_DBG_LOG("[EnableDiDtConfig] Feature DiDt Already enabled!\n");
switch (data->registry_data.didt_mode) {
case 0:
result = vega10_enable_cac_driving_se_didt_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[EnableDiDt] Attempt to enable DiDt Mode 0 Failed!", return result);
break;
case 2:
result = vega10_enable_psm_gc_didt_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[EnableDiDt] Attempt to enable DiDt Mode 2 Failed!", return result);
break;
case 3:
result = vega10_enable_se_edc_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[EnableDiDt] Attempt to enable DiDt Mode 3 Failed!", return result);
break;
case 1:
case 4:
case 5:
result = vega10_enable_psm_gc_edc_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[EnableDiDt] Attempt to enable DiDt Mode 5 Failed!", return result);
break;
case 6:
result = vega10_enable_se_edc_force_stall_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[EnableDiDt] Attempt to enable DiDt Mode 6 Failed!", return result);
break;
default:
result = -EINVAL;
break;
}
if (0 == result) {
PP_ASSERT_WITH_CODE((!vega10_enable_smc_features(hwmgr->smumgr, true, data->smu_features[GNLD_DIDT].smu_feature_bitmap)),
"[EnableDiDtConfig] Attempt to Enable DiDt feature Failed!", return result);
data->smu_features[GNLD_DIDT].enabled = true;
}
}
return result;
}
int vega10_disable_didt_config(struct pp_hwmgr *hwmgr)
{
int result = 0;
struct vega10_hwmgr *data = (struct vega10_hwmgr *)(hwmgr->backend);
if (data->smu_features[GNLD_DIDT].supported) {
if (!data->smu_features[GNLD_DIDT].enabled)
PP_DBG_LOG("[DisableDiDtConfig] Feature DiDt Already Disabled!\n");
switch (data->registry_data.didt_mode) {
case 0:
result = vega10_disable_cac_driving_se_didt_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDt] Attempt to disable DiDt Mode 0 Failed!", return result);
break;
case 2:
result = vega10_disable_psm_gc_didt_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDt] Attempt to disable DiDt Mode 2 Failed!", return result);
break;
case 3:
result = vega10_disable_se_edc_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDt] Attempt to disable DiDt Mode 3 Failed!", return result);
break;
case 1:
case 4:
case 5:
result = vega10_disable_psm_gc_edc_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDt] Attempt to disable DiDt Mode 5 Failed!", return result);
break;
case 6:
result = vega10_disable_se_edc_force_stall_config(hwmgr);
PP_ASSERT_WITH_CODE((0 == result), "[DisableDiDt] Attempt to disable DiDt Mode 6 Failed!", return result);
break;
default:
result = -EINVAL;
break;
}
if (0 == result) {
PP_ASSERT_WITH_CODE((0 != vega10_enable_smc_features(hwmgr->smumgr, false, data->smu_features[GNLD_DIDT].smu_feature_bitmap)),
"[DisableDiDtConfig] Attempt to Disable DiDt feature Failed!", return result);
data->smu_features[GNLD_DIDT].enabled = false;
}
}
return result;
}
void vega10_initialize_power_tune_defaults(struct pp_hwmgr *hwmgr)
{
struct vega10_hwmgr *data = (struct vega10_hwmgr *)(hwmgr->backend);
struct phm_ppt_v2_information *table_info =
(struct phm_ppt_v2_information *)(hwmgr->pptable);
struct phm_tdp_table *tdp_table = table_info->tdp_table;
PPTable_t *table = &(data->smc_state_table.pp_table);
table->SocketPowerLimit = cpu_to_le16(
tdp_table->usMaximumPowerDeliveryLimit);
table->TdcLimit = cpu_to_le16(tdp_table->usTDC);
table->EdcLimit = cpu_to_le16(tdp_table->usEDCLimit);
table->TedgeLimit = cpu_to_le16(tdp_table->usTemperatureLimitTedge);
table->ThotspotLimit = cpu_to_le16(tdp_table->usTemperatureLimitHotspot);
table->ThbmLimit = cpu_to_le16(tdp_table->usTemperatureLimitHBM);
table->Tvr_socLimit = cpu_to_le16(tdp_table->usTemperatureLimitVrVddc);
table->Tvr_memLimit = cpu_to_le16(tdp_table->usTemperatureLimitVrMvdd);
table->Tliquid1Limit = cpu_to_le16(tdp_table->usTemperatureLimitLiquid1);
table->Tliquid2Limit = cpu_to_le16(tdp_table->usTemperatureLimitLiquid2);
table->TplxLimit = cpu_to_le16(tdp_table->usTemperatureLimitPlx);
table->LoadLineResistance =
hwmgr->platform_descriptor.LoadLineSlope * 256;
table->FitLimit = 0;
table->Liquid1_I2C_address = tdp_table->ucLiquid1_I2C_address;
table->Liquid2_I2C_address = tdp_table->ucLiquid2_I2C_address;
table->Vr_I2C_address = tdp_table->ucVr_I2C_address;
table->Plx_I2C_address = tdp_table->ucPlx_I2C_address;
table->Liquid_I2C_LineSCL = tdp_table->ucLiquid_I2C_Line;
table->Liquid_I2C_LineSDA = tdp_table->ucLiquid_I2C_LineSDA;
table->Vr_I2C_LineSCL = tdp_table->ucVr_I2C_Line;
table->Vr_I2C_LineSDA = tdp_table->ucVr_I2C_LineSDA;
table->Plx_I2C_LineSCL = tdp_table->ucPlx_I2C_Line;
table->Plx_I2C_LineSDA = tdp_table->ucPlx_I2C_LineSDA;
}
int vega10_set_power_limit(struct pp_hwmgr *hwmgr, uint32_t n)
{
struct vega10_hwmgr *data =
(struct vega10_hwmgr *)(hwmgr->backend);
if (data->registry_data.enable_pkg_pwr_tracking_feature)
return smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_SetPptLimit, n);
return 0;
}
int vega10_enable_power_containment(struct pp_hwmgr *hwmgr)
{
struct vega10_hwmgr *data =
(struct vega10_hwmgr *)(hwmgr->backend);
struct phm_ppt_v2_information *table_info =
(struct phm_ppt_v2_information *)(hwmgr->pptable);
struct phm_tdp_table *tdp_table = table_info->tdp_table;
uint32_t default_pwr_limit =
(uint32_t)(tdp_table->usMaximumPowerDeliveryLimit);
int result = 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment)) {
if (data->smu_features[GNLD_PPT].supported)
PP_ASSERT_WITH_CODE(!vega10_enable_smc_features(hwmgr->smumgr,
true, data->smu_features[GNLD_PPT].smu_feature_bitmap),
"Attempt to enable PPT feature Failed!",
data->smu_features[GNLD_PPT].supported = false);
if (data->smu_features[GNLD_TDC].supported)
PP_ASSERT_WITH_CODE(!vega10_enable_smc_features(hwmgr->smumgr,
true, data->smu_features[GNLD_TDC].smu_feature_bitmap),
"Attempt to enable PPT feature Failed!",
data->smu_features[GNLD_TDC].supported = false);
result = vega10_set_power_limit(hwmgr, default_pwr_limit);
PP_ASSERT_WITH_CODE(!result,
"Failed to set Default Power Limit in SMC!",
return result);
}
return result;
}
int vega10_disable_power_containment(struct pp_hwmgr *hwmgr)
{
struct vega10_hwmgr *data =
(struct vega10_hwmgr *)(hwmgr->backend);
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment)) {
if (data->smu_features[GNLD_PPT].supported)
PP_ASSERT_WITH_CODE(!vega10_enable_smc_features(hwmgr->smumgr,
false, data->smu_features[GNLD_PPT].smu_feature_bitmap),
"Attempt to disable PPT feature Failed!",
data->smu_features[GNLD_PPT].supported = false);
if (data->smu_features[GNLD_TDC].supported)
PP_ASSERT_WITH_CODE(!vega10_enable_smc_features(hwmgr->smumgr,
false, data->smu_features[GNLD_TDC].smu_feature_bitmap),
"Attempt to disable PPT feature Failed!",
data->smu_features[GNLD_TDC].supported = false);
}
return 0;
}
static int vega10_set_overdrive_target_percentage(struct pp_hwmgr *hwmgr,
uint32_t adjust_percent)
{
return smum_send_msg_to_smc_with_parameter(hwmgr->smumgr,
PPSMC_MSG_OverDriveSetPercentage, adjust_percent);
}
int vega10_power_control_set_level(struct pp_hwmgr *hwmgr)
{
int adjust_percent, result = 0;
if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
PHM_PlatformCaps_PowerContainment)) {
adjust_percent =
hwmgr->platform_descriptor.TDPAdjustmentPolarity ?
hwmgr->platform_descriptor.TDPAdjustment :
(-1 * hwmgr->platform_descriptor.TDPAdjustment);
result = vega10_set_overdrive_target_percentage(hwmgr,
(uint32_t)adjust_percent);
}
return result;
}
