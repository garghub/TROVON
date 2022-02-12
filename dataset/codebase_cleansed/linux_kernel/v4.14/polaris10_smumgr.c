static int polaris10_setup_pwr_virus(struct pp_smumgr *smumgr)
{
int i;
int result = -EINVAL;
uint32_t reg, data;
const PWR_Command_Table *pvirus = pwr_virus_table;
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
static int polaris10_perform_btc(struct pp_smumgr *smumgr)
{
int result = 0;
struct smu7_smumgr *smu_data = (struct smu7_smumgr *)(smumgr->backend);
if (0 != smu_data->avfs.avfs_btc_param) {
if (0 != smu7_send_msg_to_smc_with_parameter(smumgr, PPSMC_MSG_PerformBtc, smu_data->avfs.avfs_btc_param)) {
pr_info("[AVFS][SmuPolaris10_PerformBtc] PerformBTC SMU msg failed");
result = -1;
}
}
if (smu_data->avfs.avfs_btc_param > 1) {
cgs_write_register(smumgr->device, mmCP_MEC_CNTL, 0x50000000);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0xffffffff);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0);
}
return result;
}
static int polaris10_setup_graphics_level_structure(struct pp_smumgr *smumgr)
{
uint32_t vr_config;
uint32_t dpm_table_start;
uint16_t u16_boot_mvdd;
uint32_t graphics_level_address, vr_config_address, graphics_level_size;
graphics_level_size = sizeof(avfs_graphics_level_polaris10);
u16_boot_mvdd = PP_HOST_TO_SMC_US(1300 * VOLTAGE_SCALE);
PP_ASSERT_WITH_CODE(0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU74_Firmware_Header, DpmTable),
&dpm_table_start, 0x40000),
"[AVFS][Polaris10_SetupGfxLvlStruct] SMU could not communicate starting address of DPM table",
return -1);
vr_config = 0x01000500;
vr_config_address = dpm_table_start + offsetof(SMU74_Discrete_DpmTable, VRConfig);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, vr_config_address,
(uint8_t *)&vr_config, sizeof(uint32_t), 0x40000),
"[AVFS][Polaris10_SetupGfxLvlStruct] Problems copying VRConfig value over to SMC",
return -1);
graphics_level_address = dpm_table_start + offsetof(SMU74_Discrete_DpmTable, GraphicsLevel);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_graphics_level_polaris10),
graphics_level_size, 0x40000),
"[AVFS][Polaris10_SetupGfxLvlStruct] Copying of SCLK DPM table failed!",
return -1);
graphics_level_address = dpm_table_start + offsetof(SMU74_Discrete_DpmTable, MemoryLevel);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_memory_level_polaris10), sizeof(avfs_memory_level_polaris10), 0x40000),
"[AVFS][Polaris10_SetupGfxLvlStruct] Copying of MCLK DPM table failed!",
return -1);
graphics_level_address = dpm_table_start + offsetof(SMU74_Discrete_DpmTable, BootMVdd);
PP_ASSERT_WITH_CODE(0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&u16_boot_mvdd), sizeof(u16_boot_mvdd), 0x40000),
"[AVFS][Polaris10_SetupGfxLvlStruct] Copying of DPM table failed!",
return -1);
return 0;
}
static int
polaris10_avfs_event_mgr(struct pp_smumgr *smumgr, bool SMU_VFT_INTACT)
{
struct smu7_smumgr *smu_data = (struct smu7_smumgr *)(smumgr->backend);
switch (smu_data->avfs.avfs_btc_status) {
case AVFS_BTC_COMPLETED_PREVIOUSLY:
break;
case AVFS_BTC_BOOT:
smu_data->avfs.avfs_btc_status = AVFS_BTC_DPMTABLESETUP_FAILED;
PP_ASSERT_WITH_CODE(0 == polaris10_setup_graphics_level_structure(smumgr),
"[AVFS][Polaris10_AVFSEventMgr] Could not Copy Graphics Level table over to SMU",
return -EINVAL);
if (smu_data->avfs.avfs_btc_param > 1) {
pr_info("[AVFS][Polaris10_AVFSEventMgr] AC BTC has not been successfully verified on Fiji. There may be in this setting.");
smu_data->avfs.avfs_btc_status = AVFS_BTC_VIRUS_FAIL;
PP_ASSERT_WITH_CODE(0 == polaris10_setup_pwr_virus(smumgr),
"[AVFS][Polaris10_AVFSEventMgr] Could not setup Pwr Virus for AVFS ",
return -EINVAL);
}
smu_data->avfs.avfs_btc_status = AVFS_BTC_FAILED;
PP_ASSERT_WITH_CODE(0 == polaris10_perform_btc(smumgr),
"[AVFS][Polaris10_AVFSEventMgr] Failure at SmuPolaris10_PerformBTC. AVFS Disabled",
return -EINVAL);
smu_data->avfs.avfs_btc_status = AVFS_BTC_ENABLEAVFS;
break;
case AVFS_BTC_DISABLED:
case AVFS_BTC_ENABLEAVFS:
case AVFS_BTC_NOTSUPPORTED:
break;
default:
pr_err("AVFS failed status is %x!\n", smu_data->avfs.avfs_btc_status);
break;
}
return 0;
}
static int polaris10_start_smu_in_protection_mode(struct pp_smumgr *smumgr)
{
int result = 0;
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 1);
result = smu7_upload_smu_firmware_image(smumgr);
if (result != 0)
return result;
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC, ixSMU_STATUS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_CLOCK_CNTL_0, ck_disable, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 0);
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND, RCU_UC_EVENTS, INTERRUPTS_ENABLED, 1);
smu7_send_msg_to_smc_offset(smumgr);
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND, SMU_STATUS, SMU_DONE, 0);
if (1 != SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMU_STATUS, SMU_PASS))
PP_ASSERT_WITH_CODE(false, "SMU Firmware start failed!", return -1);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC, ixFIRMWARE_FLAGS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 1);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 0);
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND, FIRMWARE_FLAGS, INTERRUPTS_ENABLED, 1);
return result;
}
static int polaris10_start_smu_in_non_protection_mode(struct pp_smumgr *smumgr)
{
int result = 0;
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND, RCU_UC_EVENTS, boot_seq_done, 0);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixFIRMWARE_FLAGS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL,
rst_reg, 1);
result = smu7_upload_smu_firmware_image(smumgr);
if (result != 0)
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
static int polaris10_start_smu(struct pp_smumgr *smumgr)
{
int result = 0;
struct polaris10_smumgr *smu_data = (struct polaris10_smumgr *)(smumgr->backend);
bool SMU_VFT_INTACT;
if (!smu7_is_smc_ram_running(smumgr)) {
SMU_VFT_INTACT = false;
smu_data->protected_mode = (uint8_t) (SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC, SMU_FIRMWARE, SMU_MODE));
smu_data->smu7_data.security_hard_key = (uint8_t) (SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC, SMU_FIRMWARE, SMU_SEL));
if (smu_data->protected_mode == 0) {
result = polaris10_start_smu_in_non_protection_mode(smumgr);
} else {
result = polaris10_start_smu_in_protection_mode(smumgr);
if (result != 0) {
smu_data->smu7_data.security_hard_key ^= 1;
cgs_rel_firmware(smumgr->device, CGS_UCODE_ID_SMU);
result = polaris10_start_smu_in_protection_mode(smumgr);
}
}
if (result != 0)
PP_ASSERT_WITH_CODE(0, "Failed to load SMU ucode.", return result);
polaris10_avfs_event_mgr(smumgr, true);
} else
SMU_VFT_INTACT = true;
polaris10_avfs_event_mgr(smumgr, SMU_VFT_INTACT);
smu7_read_smc_sram_dword(smumgr, SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU74_Firmware_Header, SoftRegisters),
&(smu_data->smu7_data.soft_regs_start), 0x40000);
result = smu7_request_smu_load_fw(smumgr);
return result;
}
static bool polaris10_is_hw_avfs_present(struct pp_smumgr *smumgr)
{
uint32_t efuse;
efuse = cgs_read_ind_register(smumgr->device, CGS_IND_REG__SMC, ixSMU_EFUSE_0 + (49*4));
efuse &= 0x00000001;
if (efuse)
return true;
return false;
}
static int polaris10_smu_init(struct pp_smumgr *smumgr)
{
struct polaris10_smumgr *smu_data;
int i;
smu_data = kzalloc(sizeof(struct polaris10_smumgr), GFP_KERNEL);
if (smu_data == NULL)
return -ENOMEM;
smumgr->backend = smu_data;
if (smu7_init(smumgr))
return -EINVAL;
for (i = 0; i < SMU74_MAX_LEVELS_GRAPHICS; i++)
smu_data->activity_target[i] = PPPOLARIS10_TARGETACTIVITY_DFLT;
return 0;
}
