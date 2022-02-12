static int fiji_start_smu_in_protection_mode(struct pp_smumgr *smumgr)
{
int result = 0;
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 1);
result = smu7_upload_smu_firmware_image(smumgr);
if (result)
return result;
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixSMU_STATUS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_CLOCK_CNTL_0, ck_disable, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMU_INPUT_DATA, AUTO_START, 1);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixFIRMWARE_FLAGS, 0);
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND, RCU_UC_EVENTS,
INTERRUPTS_ENABLED, 1);
cgs_write_register(smumgr->device, mmSMC_MSG_ARG_0, 0x20000);
cgs_write_register(smumgr->device, mmSMC_MESSAGE_0, PPSMC_MSG_Test);
SMUM_WAIT_FIELD_UNEQUAL(smumgr, SMC_RESP_0, SMC_RESP, 0);
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND,
SMU_STATUS, SMU_DONE, 0);
if (SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMU_STATUS, SMU_PASS) != 1) {
PP_ASSERT_WITH_CODE(false,
"SMU Firmware start failed!", return -1);
}
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND,
FIRMWARE_FLAGS, INTERRUPTS_ENABLED, 1);
return result;
}
static int fiji_start_smu_in_non_protection_mode(struct pp_smumgr *smumgr)
{
int result = 0;
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND,
RCU_UC_EVENTS, boot_seq_done, 0);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixFIRMWARE_FLAGS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 1);
result = smu7_upload_smu_firmware_image(smumgr);
if (result)
return result;
smu7_program_jump_on_start(smumgr);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_CLOCK_CNTL_0, ck_disable, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 0);
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND,
FIRMWARE_FLAGS, INTERRUPTS_ENABLED, 1);
return result;
}
static int fiji_setup_pwr_virus(struct pp_smumgr *smumgr)
{
int i;
int result = -EINVAL;
uint32_t reg, data;
const PWR_Command_Table *pvirus = PwrVirusTable;
struct smu7_smumgr *smu_data = (struct smu7_smumgr *)(smumgr->backend);
for (i = 0; i < PWR_VIRUS_TABLE_SIZE; i++) {
switch (pvirus->command) {
case PwrCmdWrite:
reg = pvirus->reg;
data = pvirus->data;
cgs_write_register(smumgr->device, reg, data);
break;
case PwrCmdEnd:
result = 0;
break;
default:
pr_info("Table Exit with Invalid Command!");
smu_data->avfs.avfs_btc_status = AVFS_BTC_VIRUS_FAIL;
result = -EINVAL;
break;
}
pvirus++;
}
return result;
}
static int fiji_start_avfs_btc(struct pp_smumgr *smumgr)
{
int result = 0;
struct smu7_smumgr *smu_data = (struct smu7_smumgr *)(smumgr->backend);
if (0 != smu_data->avfs.avfs_btc_param) {
if (0 != smu7_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PerformBtc, smu_data->avfs.avfs_btc_param)) {
pr_info("[AVFS][Fiji_PerformBtc] PerformBTC SMU msg failed");
result = -EINVAL;
}
}
cgs_write_register(smumgr->device, mmCP_MEC_CNTL, 0x50000000);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0xffffffff);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0);
return result;
}
static int fiji_setup_graphics_level_structure(struct pp_smumgr *smumgr)
{
int32_t vr_config;
uint32_t table_start;
uint32_t level_addr, vr_config_addr;
uint32_t level_size = sizeof(avfs_graphics_level);
PP_ASSERT_WITH_CODE(0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION +
offsetof(SMU73_Firmware_Header, DpmTable),
&table_start, 0x40000),
"[AVFS][Fiji_SetupGfxLvlStruct] SMU could not "
"communicate starting address of DPM table",
return -1;);
vr_config = 0x01000500;
vr_config_addr = table_start +
offsetof(SMU73_Discrete_DpmTable, VRConfig);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, vr_config_addr,
(uint8_t *)&vr_config, sizeof(int32_t), 0x40000),
"[AVFS][Fiji_SetupGfxLvlStruct] Problems copying "
"vr_config value over to SMC",
return -1;);
level_addr = table_start + offsetof(SMU73_Discrete_DpmTable, GraphicsLevel);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, level_addr,
(uint8_t *)(&avfs_graphics_level), level_size, 0x40000),
"[AVFS][Fiji_SetupGfxLvlStruct] Copying of DPM table failed!",
return -1;);
return 0;
}
static int fiji_avfs_event_mgr(struct pp_smumgr *smumgr, bool smu_started)
{
struct smu7_smumgr *smu_data = (struct smu7_smumgr *)(smumgr->backend);
switch (smu_data->avfs.avfs_btc_status) {
case AVFS_BTC_COMPLETED_PREVIOUSLY:
break;
case AVFS_BTC_BOOT:
if (!smu_started)
break;
smu_data->avfs.avfs_btc_status = AVFS_BTC_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_setup_graphics_level_structure(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not Copy Graphics Level"
" table over to SMU",
return -EINVAL;);
smu_data->avfs.avfs_btc_status = AVFS_BTC_VIRUS_FAIL;
PP_ASSERT_WITH_CODE(0 == fiji_setup_pwr_virus(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not setup "
"Pwr Virus for AVFS ",
return -EINVAL;);
smu_data->avfs.avfs_btc_status = AVFS_BTC_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_start_avfs_btc(smumgr),
"[AVFS][fiji_avfs_event_mgr] Failure at "
"fiji_start_avfs_btc. AVFS Disabled",
return -EINVAL;);
smu_data->avfs.avfs_btc_status = AVFS_BTC_ENABLEAVFS;
break;
case AVFS_BTC_DISABLED:
case AVFS_BTC_NOTSUPPORTED:
case AVFS_BTC_ENABLEAVFS:
break;
default:
pr_err("AVFS failed status is %x !\n", smu_data->avfs.avfs_btc_status);
break;
}
return 0;
}
static int fiji_start_smu(struct pp_smumgr *smumgr)
{
int result = 0;
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
if (!(smu7_is_smc_ram_running(smumgr)
|| cgs_is_virtualization_enabled(smumgr->device))) {
fiji_avfs_event_mgr(smumgr, false);
if (0 == SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device,
CGS_IND_REG__SMC,
SMU_FIRMWARE, SMU_MODE)) {
result = fiji_start_smu_in_non_protection_mode(smumgr);
if (result)
return result;
} else {
result = fiji_start_smu_in_protection_mode(smumgr);
if (result)
return result;
}
fiji_avfs_event_mgr(smumgr, true);
}
cgs_set_clockgating_state(smumgr->device,
AMD_IP_BLOCK_TYPE_GFX, AMD_CG_STATE_GATE);
cgs_set_clockgating_state(smumgr->device,
AMD_IP_BLOCK_TYPE_GMC, AMD_CG_STATE_GATE);
cgs_set_clockgating_state(smumgr->device,
AMD_IP_BLOCK_TYPE_SDMA, AMD_CG_STATE_GATE);
cgs_set_clockgating_state(smumgr->device,
AMD_IP_BLOCK_TYPE_COMMON, AMD_CG_STATE_GATE);
smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION +
offsetof(SMU73_Firmware_Header, SoftRegisters),
&(priv->smu7_data.soft_regs_start), 0x40000);
result = smu7_request_smu_load_fw(smumgr);
return result;
}
static bool fiji_is_hw_avfs_present(struct pp_smumgr *smumgr)
{
uint32_t efuse = 0;
uint32_t mask = (1 << ((AVFS_EN_MSB - AVFS_EN_LSB) + 1)) - 1;
if (cgs_is_virtualization_enabled(smumgr->device))
return 0;
if (!atomctrl_read_efuse(smumgr->device, AVFS_EN_LSB, AVFS_EN_MSB,
mask, &efuse)) {
if (efuse)
return true;
}
return false;
}
static int fiji_smu_init(struct pp_smumgr *smumgr)
{
int i;
struct fiji_smumgr *fiji_priv = NULL;
fiji_priv = kzalloc(sizeof(struct fiji_smumgr), GFP_KERNEL);
if (fiji_priv == NULL)
return -ENOMEM;
smumgr->backend = fiji_priv;
if (smu7_init(smumgr))
return -EINVAL;
for (i = 0; i < SMU73_MAX_LEVELS_GRAPHICS; i++)
fiji_priv->activity_target[i] = 30;
return 0;
}
