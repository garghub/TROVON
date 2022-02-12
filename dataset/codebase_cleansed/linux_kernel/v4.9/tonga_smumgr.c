static int tonga_start_in_protection_mode(struct pp_smumgr *smumgr)
{
int result;
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
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND,
RCU_UC_EVENTS, INTERRUPTS_ENABLED, 1);
smu7_send_msg_to_smc_offset(smumgr);
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND,
SMU_STATUS, SMU_DONE, 0);
if (1 != SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device,
CGS_IND_REG__SMC, SMU_STATUS, SMU_PASS)) {
printk(KERN_ERR "[ powerplay ] SMU Firmware start failed\n");
return -EINVAL;
}
SMUM_WAIT_VFPF_INDIRECT_FIELD(smumgr, SMC_IND,
FIRMWARE_FLAGS, INTERRUPTS_ENABLED, 1);
return 0;
}
static int tonga_start_in_non_protection_mode(struct pp_smumgr *smumgr)
{
int result = 0;
SMUM_WAIT_VFPF_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND,
RCU_UC_EVENTS, boot_seq_done, 0);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixFIRMWARE_FLAGS, 0);
SMUM_WRITE_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 1);
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
static int tonga_start_smu(struct pp_smumgr *smumgr)
{
int result;
if (!smu7_is_smc_ram_running(smumgr)) {
if (0 == SMUM_READ_VFPF_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMU_FIRMWARE, SMU_MODE)) {
result = tonga_start_in_non_protection_mode(smumgr);
if (result)
return result;
} else {
result = tonga_start_in_protection_mode(smumgr);
if (result)
return result;
}
}
result = smu7_request_smu_load_fw(smumgr);
return result;
}
static int tonga_smu_init(struct pp_smumgr *smumgr)
{
struct tonga_smumgr *smu_data = (struct tonga_smumgr *)(smumgr->backend);
int i;
if (smu7_init(smumgr))
return -EINVAL;
for (i = 0; i < SMU72_MAX_LEVELS_GRAPHICS; i++)
smu_data->activity_target[i] = 30;
return 0;
}
int tonga_smum_init(struct pp_smumgr *smumgr)
{
struct tonga_smumgr *tonga_smu = NULL;
tonga_smu = kzalloc(sizeof(struct tonga_smumgr), GFP_KERNEL);
if (tonga_smu == NULL)
return -ENOMEM;
smumgr->backend = tonga_smu;
smumgr->smumgr_funcs = &tonga_smu_funcs;
return 0;
}
