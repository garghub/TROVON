static int iceland_start_smc(struct pp_smumgr *smumgr)
{
SMUM_WRITE_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL, rst_reg, 0);
return 0;
}
static void iceland_reset_smc(struct pp_smumgr *smumgr)
{
SMUM_WRITE_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_RESET_CNTL,
rst_reg, 1);
}
static void iceland_stop_smc_clock(struct pp_smumgr *smumgr)
{
SMUM_WRITE_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_CLOCK_CNTL_0,
ck_disable, 1);
}
static void iceland_start_smc_clock(struct pp_smumgr *smumgr)
{
SMUM_WRITE_INDIRECT_FIELD(smumgr->device, CGS_IND_REG__SMC,
SMC_SYSCON_CLOCK_CNTL_0,
ck_disable, 0);
}
static int iceland_smu_start_smc(struct pp_smumgr *smumgr)
{
smu7_program_jump_on_start(smumgr);
iceland_start_smc_clock(smumgr);
iceland_start_smc(smumgr);
SMUM_WAIT_INDIRECT_FIELD(smumgr, SMC_IND, FIRMWARE_FLAGS,
INTERRUPTS_ENABLED, 1);
return 0;
}
static int iceland_upload_smc_firmware_data(struct pp_smumgr *smumgr,
uint32_t length, const uint8_t *src,
uint32_t limit, uint32_t start_addr)
{
uint32_t byte_count = length;
uint32_t data;
PP_ASSERT_WITH_CODE((limit >= byte_count), "SMC address is beyond the SMC RAM area.", return -EINVAL);
cgs_write_register(smumgr->device, mmSMC_IND_INDEX_0, start_addr);
SMUM_WRITE_FIELD(smumgr->device, SMC_IND_ACCESS_CNTL, AUTO_INCREMENT_IND_0, 1);
while (byte_count >= 4) {
data = src[0] * 0x1000000 + src[1] * 0x10000 + src[2] * 0x100 + src[3];
cgs_write_register(smumgr->device, mmSMC_IND_DATA_0, data);
src += 4;
byte_count -= 4;
}
SMUM_WRITE_FIELD(smumgr->device, SMC_IND_ACCESS_CNTL, AUTO_INCREMENT_IND_0, 0);
PP_ASSERT_WITH_CODE((0 == byte_count), "SMC size must be dividable by 4.", return -EINVAL);
return 0;
}
static int iceland_smu_upload_firmware_image(struct pp_smumgr *smumgr)
{
uint32_t val;
struct cgs_firmware_info info = {0};
if (smumgr == NULL || smumgr->device == NULL)
return -EINVAL;
cgs_get_firmware_info(smumgr->device,
smu7_convert_fw_type_to_cgs(UCODE_ID_SMU), &info);
if (info.image_size & 3) {
pr_err("[ powerplay ] SMC ucode is not 4 bytes aligned\n");
return -EINVAL;
}
if (info.image_size > ICELAND_SMC_SIZE) {
pr_err("[ powerplay ] SMC address is beyond the SMC RAM area\n");
return -EINVAL;
}
SMUM_WAIT_INDIRECT_FIELD_UNEQUAL(smumgr, SMC_IND,
RCU_UC_EVENTS, boot_seq_done, 0);
val = cgs_read_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixSMC_SYSCON_MISC_CNTL);
cgs_write_ind_register(smumgr->device, CGS_IND_REG__SMC,
ixSMC_SYSCON_MISC_CNTL, val | 1);
iceland_stop_smc_clock(smumgr);
iceland_reset_smc(smumgr);
iceland_upload_smc_firmware_data(smumgr, info.image_size,
(uint8_t *)info.kptr, ICELAND_SMC_SIZE,
info.ucode_start_address);
return 0;
}
static int iceland_request_smu_load_specific_fw(struct pp_smumgr *smumgr,
uint32_t firmwareType)
{
return 0;
}
static int iceland_start_smu(struct pp_smumgr *smumgr)
{
int result;
result = iceland_smu_upload_firmware_image(smumgr);
if (result)
return result;
result = iceland_smu_start_smc(smumgr);
if (result)
return result;
if (!smu7_is_smc_ram_running(smumgr)) {
pr_info("smu not running, upload firmware again \n");
result = iceland_smu_upload_firmware_image(smumgr);
if (result)
return result;
result = iceland_smu_start_smc(smumgr);
if (result)
return result;
}
result = smu7_request_smu_load_fw(smumgr);
return result;
}
static int iceland_smu_init(struct pp_smumgr *smumgr)
{
int i;
struct iceland_smumgr *iceland_priv = NULL;
iceland_priv = kzalloc(sizeof(struct iceland_smumgr), GFP_KERNEL);
if (iceland_priv == NULL)
return -ENOMEM;
smumgr->backend = iceland_priv;
if (smu7_init(smumgr))
return -EINVAL;
for (i = 0; i < SMU71_MAX_LEVELS_GRAPHICS; i++)
iceland_priv->activity_target[i] = 30;
return 0;
}
