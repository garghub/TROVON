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
int i, result = -1;
uint32_t reg, data;
const PWR_Command_Table *virus = PwrVirusTable;
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
priv->avfs.AvfsBtcStatus = AVFS_LOAD_VIRUS;
for (i = 0; (i < PWR_VIRUS_TABLE_SIZE); i++) {
switch (virus->command) {
case PwrCmdWrite:
reg = virus->reg;
data = virus->data;
cgs_write_register(smumgr->device, reg, data);
break;
case PwrCmdEnd:
priv->avfs.AvfsBtcStatus = AVFS_BTC_VIRUS_LOADED;
result = 0;
break;
default:
printk(KERN_ERR "Table Exit with Invalid Command!");
priv->avfs.AvfsBtcStatus = AVFS_BTC_VIRUS_FAIL;
result = -1;
break;
}
virus++;
}
return result;
}
static int fiji_start_avfs_btc(struct pp_smumgr *smumgr)
{
int result = 0;
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
priv->avfs.AvfsBtcStatus = AVFS_BTC_STARTED;
if (priv->avfs.AvfsBtcParam) {
if (!smum_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PerformBtc, priv->avfs.AvfsBtcParam)) {
if (!smum_send_msg_to_smc(smumgr, PPSMC_MSG_EnableAvfs)) {
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_UNSAVED;
result = 0;
} else {
printk(KERN_ERR "[AVFS][fiji_start_avfs_btc] Attempt"
" to Enable AVFS Failed!");
smum_send_msg_to_smc(smumgr, PPSMC_MSG_DisableAvfs);
result = -1;
}
} else {
printk(KERN_ERR "[AVFS][fiji_start_avfs_btc] "
"PerformBTC SMU msg failed");
result = -1;
}
}
cgs_write_register(smumgr->device, mmCP_MEC_CNTL, 0x50000000);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0xffffffff);
cgs_write_register(smumgr->device, mmGRBM_SOFT_RESET, 0);
return result;
}
static int fiji_setup_pm_fuse_for_avfs(struct pp_smumgr *smumgr)
{
int result = 0;
uint32_t table_start;
uint32_t charz_freq_addr, inversion_voltage_addr, charz_freq;
uint16_t inversion_voltage;
charz_freq = 0x30750000;
inversion_voltage = 0x1A04;
PP_ASSERT_WITH_CODE(0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU73_Firmware_Header,
PmFuseTable), &table_start, 0x40000),
"[AVFS][Fiji_SetupGfxLvlStruct] SMU could not communicate "
"starting address of PmFuse structure",
return -1;);
charz_freq_addr = table_start +
offsetof(struct SMU73_Discrete_PmFuses, PsmCharzFreq);
inversion_voltage_addr = table_start +
offsetof(struct SMU73_Discrete_PmFuses, InversionVoltage);
result = smu7_copy_bytes_to_smc(smumgr, charz_freq_addr,
(uint8_t *)(&charz_freq), sizeof(charz_freq), 0x40000);
PP_ASSERT_WITH_CODE(0 == result,
"[AVFS][fiji_setup_pm_fuse_for_avfs] charz_freq could not "
"be populated.", return -1;);
result = smu7_copy_bytes_to_smc(smumgr, inversion_voltage_addr,
(uint8_t *)(&inversion_voltage), sizeof(inversion_voltage), 0x40000);
PP_ASSERT_WITH_CODE(0 == result, "[AVFS][fiji_setup_pm_fuse_for_avfs] "
"charz_freq could not be populated.", return -1;);
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
static int fiji_restore_vft_table(struct pp_smumgr *smumgr)
{
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
if (AVFS_BTC_COMPLETED_SAVED == priv->avfs.AvfsBtcStatus) {
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_RESTORED;
return 0;
} else
return -EINVAL;
}
static int fiji_save_vft_table(struct pp_smumgr *smumgr)
{
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
if (AVFS_BTC_COMPLETED_SAVED == priv->avfs.AvfsBtcStatus) {
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_RESTORED;
return 0;
} else
return -EINVAL;
}
static int fiji_avfs_event_mgr(struct pp_smumgr *smumgr, bool smu_started)
{
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
switch (priv->avfs.AvfsBtcStatus) {
case AVFS_BTC_COMPLETED_SAVED:
priv->avfs.AvfsBtcStatus = AVFS_BTC_RESTOREVFT_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_restore_vft_table(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not Copy Graphics "
"Level table over to SMU",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_RESTORED;
break;
case AVFS_BTC_COMPLETED_RESTORED:
priv->avfs.AvfsBtcStatus = AVFS_BTC_SMUMSG_ERROR;
PP_ASSERT_WITH_CODE(0 == smum_send_msg_to_smc(smumgr,
0x666),
"[AVFS][fiji_avfs_event_mgr] SMU did not respond "
"correctly to VftTableIsValid Msg",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_SMUMSG_ERROR;
PP_ASSERT_WITH_CODE(0 == smum_send_msg_to_smc(smumgr,
PPSMC_MSG_EnableAvfs),
"[AVFS][fiji_avfs_event_mgr] SMU did not respond "
"correctly to EnableAvfs Message Msg",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_SAVED;
break;
case AVFS_BTC_BOOT:
if (!smu_started)
break;
priv->avfs.AvfsBtcStatus = AVFS_BTC_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_setup_pm_fuse_for_avfs(smumgr),
"[AVFS][fiji_avfs_event_mgr] Failure at "
"fiji_setup_pm_fuse_for_avfs",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_DPMTABLESETUP_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_setup_graphics_level_structure(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not Copy Graphics Level"
" table over to SMU",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_VIRUS_FAIL;
PP_ASSERT_WITH_CODE(0 == fiji_setup_pwr_virus(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not setup "
"Pwr Virus for AVFS ",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_start_avfs_btc(smumgr),
"[AVFS][fiji_avfs_event_mgr] Failure at "
"fiji_start_avfs_btc. AVFS Disabled",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_SAVEVFT_FAILED;
PP_ASSERT_WITH_CODE(0 == fiji_save_vft_table(smumgr),
"[AVFS][fiji_avfs_event_mgr] Could not save VFT Table",
return -1;);
priv->avfs.AvfsBtcStatus = AVFS_BTC_COMPLETED_SAVED;
break;
case AVFS_BTC_DISABLED:
break;
case AVFS_BTC_NOTSUPPORTED:
break;
default:
printk(KERN_ERR "[AVFS] Something is broken. See log!");
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
struct fiji_smumgr *priv = (struct fiji_smumgr *)(smumgr->backend);
int i;
if (smu7_init(smumgr))
return -EINVAL;
priv->avfs.AvfsBtcStatus = AVFS_BTC_BOOT;
if (fiji_is_hw_avfs_present(smumgr))
priv->avfs.AvfsBtcParam = 0;
else
priv->avfs.AvfsBtcStatus = AVFS_BTC_NOTSUPPORTED;
for (i = 0; i < SMU73_MAX_LEVELS_GRAPHICS; i++)
priv->activity_target[i] = 30;
return 0;
}
int fiji_smum_init(struct pp_smumgr *smumgr)
{
struct fiji_smumgr *fiji_smu = NULL;
fiji_smu = kzalloc(sizeof(struct fiji_smumgr), GFP_KERNEL);
if (fiji_smu == NULL)
return -ENOMEM;
smumgr->backend = fiji_smu;
smumgr->smumgr_funcs = &fiji_smu_funcs;
return 0;
}
