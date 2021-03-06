static int fiji_set_smc_sram_address(struct amdgpu_device *adev, uint32_t smc_address, uint32_t limit)
{
uint32_t val;
if (smc_address & 3)
return -EINVAL;
if ((smc_address + 3) > limit)
return -EINVAL;
WREG32(mmSMC_IND_INDEX_0, smc_address);
val = RREG32(mmSMC_IND_ACCESS_CNTL);
val = REG_SET_FIELD(val, SMC_IND_ACCESS_CNTL, AUTO_INCREMENT_IND_0, 0);
WREG32(mmSMC_IND_ACCESS_CNTL, val);
return 0;
}
static int fiji_copy_bytes_to_smc(struct amdgpu_device *adev, uint32_t smc_start_address, const uint8_t *src, uint32_t byte_count, uint32_t limit)
{
uint32_t addr;
uint32_t data, orig_data;
int result = 0;
uint32_t extra_shift;
unsigned long flags;
if (smc_start_address & 3)
return -EINVAL;
if ((smc_start_address + byte_count) > limit)
return -EINVAL;
addr = smc_start_address;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
while (byte_count >= 4) {
data = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
result = fiji_set_smc_sram_address(adev, addr, limit);
if (result)
goto out;
WREG32(mmSMC_IND_DATA_0, data);
src += 4;
byte_count -= 4;
addr += 4;
}
if (0 != byte_count) {
data = 0;
result = fiji_set_smc_sram_address(adev, addr, limit);
if (result)
goto out;
orig_data = RREG32(mmSMC_IND_DATA_0);
extra_shift = 8 * (4 - byte_count);
while (byte_count > 0) {
data = (data << 8) + *src++;
byte_count--;
}
data <<= extra_shift;
data |= (orig_data & ~((~0UL) << extra_shift));
result = fiji_set_smc_sram_address(adev, addr, limit);
if (result)
goto out;
WREG32(mmSMC_IND_DATA_0, data);
}
out:
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return result;
}
static int fiji_program_jump_on_start(struct amdgpu_device *adev)
{
static unsigned char data[] = {0xE0, 0x00, 0x80, 0x40};
fiji_copy_bytes_to_smc(adev, 0x0, data, 4, sizeof(data)+1);
return 0;
}
static bool fiji_is_smc_ram_running(struct amdgpu_device *adev)
{
uint32_t val = RREG32_SMC(ixSMC_SYSCON_CLOCK_CNTL_0);
val = REG_GET_FIELD(val, SMC_SYSCON_CLOCK_CNTL_0, ck_disable);
return ((0 == val) && (0x20100 <= RREG32_SMC(ixSMC_PC_C)));
}
static int wait_smu_response(struct amdgpu_device *adev)
{
int i;
uint32_t val;
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32(mmSMC_RESP_0);
if (REG_GET_FIELD(val, SMC_RESP_0, SMC_RESP))
break;
udelay(1);
}
if (i == adev->usec_timeout)
return -EINVAL;
return 0;
}
static int fiji_send_msg_to_smc_offset(struct amdgpu_device *adev)
{
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send previous message\n");
return -EINVAL;
}
WREG32(mmSMC_MSG_ARG_0, 0x20000);
WREG32(mmSMC_MESSAGE_0, PPSMC_MSG_Test);
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send message\n");
return -EINVAL;
}
return 0;
}
static int fiji_send_msg_to_smc(struct amdgpu_device *adev, PPSMC_Msg msg)
{
if (!fiji_is_smc_ram_running(adev))
{
return -EINVAL;;
}
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send previous message\n");
return -EINVAL;
}
WREG32(mmSMC_MESSAGE_0, msg);
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send message\n");
return -EINVAL;
}
return 0;
}
static int fiji_send_msg_to_smc_without_waiting(struct amdgpu_device *adev,
PPSMC_Msg msg)
{
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send previous message\n");
return -EINVAL;
}
WREG32(mmSMC_MESSAGE_0, msg);
return 0;
}
static int fiji_send_msg_to_smc_with_parameter(struct amdgpu_device *adev,
PPSMC_Msg msg,
uint32_t parameter)
{
if (!fiji_is_smc_ram_running(adev))
return -EINVAL;
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send previous message\n");
return -EINVAL;
}
WREG32(mmSMC_MSG_ARG_0, parameter);
return fiji_send_msg_to_smc(adev, msg);
}
static int fiji_send_msg_to_smc_with_parameter_without_waiting(
struct amdgpu_device *adev,
PPSMC_Msg msg, uint32_t parameter)
{
if (wait_smu_response(adev)) {
DRM_ERROR("Failed to send previous message\n");
return -EINVAL;
}
WREG32(mmSMC_MSG_ARG_0, parameter);
return fiji_send_msg_to_smc_without_waiting(adev, msg);
}
static int fiji_smu_upload_firmware_image(struct amdgpu_device *adev)
{
const struct smc_firmware_header_v1_0 *hdr;
uint32_t ucode_size;
uint32_t ucode_start_address;
const uint8_t *src;
uint32_t val;
uint32_t byte_count;
uint32_t *data;
unsigned long flags;
if (!adev->pm.fw)
return -EINVAL;
if (adev->virtualization.supports_sr_iov)
return 0;
hdr = (const struct smc_firmware_header_v1_0 *)adev->pm.fw->data;
amdgpu_ucode_print_smc_hdr(&hdr->header);
adev->pm.fw_version = le32_to_cpu(hdr->header.ucode_version);
ucode_size = le32_to_cpu(hdr->header.ucode_size_bytes);
ucode_start_address = le32_to_cpu(hdr->ucode_start_addr);
src = (const uint8_t *)
(adev->pm.fw->data + le32_to_cpu(hdr->header.ucode_array_offset_bytes));
if (ucode_size & 3) {
DRM_ERROR("SMC ucode is not 4 bytes aligned\n");
return -EINVAL;
}
if (ucode_size > FIJI_SMC_SIZE) {
DRM_ERROR("SMC address is beyond the SMC RAM area\n");
return -EINVAL;
}
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmSMC_IND_INDEX_0, ucode_start_address);
val = RREG32(mmSMC_IND_ACCESS_CNTL);
val = REG_SET_FIELD(val, SMC_IND_ACCESS_CNTL, AUTO_INCREMENT_IND_0, 1);
WREG32(mmSMC_IND_ACCESS_CNTL, val);
byte_count = ucode_size;
data = (uint32_t *)src;
for (; byte_count >= 4; data++, byte_count -= 4)
WREG32(mmSMC_IND_DATA_0, data[0]);
val = RREG32(mmSMC_IND_ACCESS_CNTL);
val = REG_SET_FIELD(val, SMC_IND_ACCESS_CNTL, AUTO_INCREMENT_IND_0, 0);
WREG32(mmSMC_IND_ACCESS_CNTL, val);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return 0;
}
static enum AMDGPU_UCODE_ID fiji_convert_fw_type(uint32_t fw_type)
{
switch (fw_type) {
case UCODE_ID_SDMA0:
return AMDGPU_UCODE_ID_SDMA0;
case UCODE_ID_SDMA1:
return AMDGPU_UCODE_ID_SDMA1;
case UCODE_ID_CP_CE:
return AMDGPU_UCODE_ID_CP_CE;
case UCODE_ID_CP_PFP:
return AMDGPU_UCODE_ID_CP_PFP;
case UCODE_ID_CP_ME:
return AMDGPU_UCODE_ID_CP_ME;
case UCODE_ID_CP_MEC:
case UCODE_ID_CP_MEC_JT1:
case UCODE_ID_CP_MEC_JT2:
return AMDGPU_UCODE_ID_CP_MEC1;
case UCODE_ID_RLC_G:
return AMDGPU_UCODE_ID_RLC_G;
default:
DRM_ERROR("ucode type is out of range!\n");
return AMDGPU_UCODE_ID_MAXIMUM;
}
}
static int fiji_smu_populate_single_firmware_entry(struct amdgpu_device *adev,
uint32_t fw_type,
struct SMU_Entry *entry)
{
enum AMDGPU_UCODE_ID id = fiji_convert_fw_type(fw_type);
struct amdgpu_firmware_info *ucode = &adev->firmware.ucode[id];
const struct gfx_firmware_header_v1_0 *header = NULL;
uint64_t gpu_addr;
uint32_t data_size;
if (ucode->fw == NULL)
return -EINVAL;
gpu_addr = ucode->mc_addr;
header = (const struct gfx_firmware_header_v1_0 *)ucode->fw->data;
data_size = le32_to_cpu(header->header.ucode_size_bytes);
if ((fw_type == UCODE_ID_CP_MEC_JT1) ||
(fw_type == UCODE_ID_CP_MEC_JT2)) {
gpu_addr += le32_to_cpu(header->jt_offset) << 2;
data_size = le32_to_cpu(header->jt_size) << 2;
}
entry->version = (uint16_t)le32_to_cpu(header->header.ucode_version);
entry->id = (uint16_t)fw_type;
entry->image_addr_high = upper_32_bits(gpu_addr);
entry->image_addr_low = lower_32_bits(gpu_addr);
entry->meta_data_addr_high = 0;
entry->meta_data_addr_low = 0;
entry->data_size_byte = data_size;
entry->num_register_entries = 0;
if (fw_type == UCODE_ID_RLC_G)
entry->flags = 1;
else
entry->flags = 0;
return 0;
}
static int fiji_smu_request_load_fw(struct amdgpu_device *adev)
{
struct fiji_smu_private_data *private = (struct fiji_smu_private_data *)adev->smu.priv;
struct SMU_DRAMData_TOC *toc;
uint32_t fw_to_load;
WREG32_SMC(ixSOFT_REGISTERS_TABLE_28, 0);
fiji_send_msg_to_smc_with_parameter(adev, PPSMC_MSG_SMU_DRAM_ADDR_HI, private->smu_buffer_addr_high);
fiji_send_msg_to_smc_with_parameter(adev, PPSMC_MSG_SMU_DRAM_ADDR_LO, private->smu_buffer_addr_low);
toc = (struct SMU_DRAMData_TOC *)private->header;
toc->num_entries = 0;
toc->structure_version = 1;
if (!adev->firmware.smu_load)
return 0;
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_RLC_G,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for RLC\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_CE,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for CE\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_PFP,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for PFP\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_ME,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for ME\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_MEC,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for MEC\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_MEC_JT1,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for MEC_JT1\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_CP_MEC_JT2,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for MEC_JT2\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_SDMA0,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for SDMA0\n");
return -EINVAL;
}
if (fiji_smu_populate_single_firmware_entry(adev, UCODE_ID_SDMA1,
&toc->entry[toc->num_entries++])) {
DRM_ERROR("Failed to get firmware entry for SDMA1\n");
return -EINVAL;
}
fiji_send_msg_to_smc_with_parameter(adev, PPSMC_MSG_DRV_DRAM_ADDR_HI, private->header_addr_high);
fiji_send_msg_to_smc_with_parameter(adev, PPSMC_MSG_DRV_DRAM_ADDR_LO, private->header_addr_low);
fw_to_load = UCODE_ID_RLC_G_MASK |
UCODE_ID_SDMA0_MASK |
UCODE_ID_SDMA1_MASK |
UCODE_ID_CP_CE_MASK |
UCODE_ID_CP_ME_MASK |
UCODE_ID_CP_PFP_MASK |
UCODE_ID_CP_MEC_MASK;
if (fiji_send_msg_to_smc_with_parameter_without_waiting(adev, PPSMC_MSG_LoadUcodes, fw_to_load)) {
DRM_ERROR("Fail to request SMU load ucode\n");
return -EINVAL;
}
return 0;
}
static uint32_t fiji_smu_get_mask_for_fw_type(uint32_t fw_type)
{
switch (fw_type) {
case AMDGPU_UCODE_ID_SDMA0:
return UCODE_ID_SDMA0_MASK;
case AMDGPU_UCODE_ID_SDMA1:
return UCODE_ID_SDMA1_MASK;
case AMDGPU_UCODE_ID_CP_CE:
return UCODE_ID_CP_CE_MASK;
case AMDGPU_UCODE_ID_CP_PFP:
return UCODE_ID_CP_PFP_MASK;
case AMDGPU_UCODE_ID_CP_ME:
return UCODE_ID_CP_ME_MASK;
case AMDGPU_UCODE_ID_CP_MEC1:
return UCODE_ID_CP_MEC_MASK;
case AMDGPU_UCODE_ID_CP_MEC2:
return UCODE_ID_CP_MEC_MASK;
case AMDGPU_UCODE_ID_RLC_G:
return UCODE_ID_RLC_G_MASK;
default:
DRM_ERROR("ucode type is out of range!\n");
return 0;
}
}
static int fiji_smu_check_fw_load_finish(struct amdgpu_device *adev,
uint32_t fw_type)
{
uint32_t fw_mask = fiji_smu_get_mask_for_fw_type(fw_type);
int i;
for (i = 0; i < adev->usec_timeout; i++) {
if (fw_mask == (RREG32_SMC(ixSOFT_REGISTERS_TABLE_28) & fw_mask))
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("check firmware loading failed\n");
return -EINVAL;
}
return 0;
}
static int fiji_smu_start_in_protection_mode(struct amdgpu_device *adev)
{
int result;
uint32_t val;
int i;
val = RREG32_SMC(ixSMC_SYSCON_RESET_CNTL);
val = REG_SET_FIELD(val, SMC_SYSCON_RESET_CNTL, rst_reg, 1);
WREG32_SMC(ixSMC_SYSCON_RESET_CNTL, val);
result = fiji_smu_upload_firmware_image(adev);
if (result)
return result;
WREG32_SMC(ixSMU_STATUS, 0);
val = RREG32_SMC(ixSMC_SYSCON_CLOCK_CNTL_0);
val = REG_SET_FIELD(val, SMC_SYSCON_CLOCK_CNTL_0, ck_disable, 0);
WREG32_SMC(ixSMC_SYSCON_CLOCK_CNTL_0, val);
val = RREG32_SMC(ixSMC_SYSCON_RESET_CNTL);
val = REG_SET_FIELD(val, SMC_SYSCON_RESET_CNTL, rst_reg, 0);
WREG32_SMC(ixSMC_SYSCON_RESET_CNTL, val);
val = RREG32_SMC(ixSMU_INPUT_DATA);
val = REG_SET_FIELD(val, SMU_INPUT_DATA, AUTO_START, 1);
WREG32_SMC(ixSMU_INPUT_DATA, val);
WREG32_SMC(ixFIRMWARE_FLAGS, 0);
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32_SMC(ixRCU_UC_EVENTS);
if (REG_GET_FIELD(val, RCU_UC_EVENTS, INTERRUPTS_ENABLED))
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("Interrupt is not enabled by firmware\n");
return -EINVAL;
}
fiji_send_msg_to_smc_offset(adev);
DRM_INFO("[FM]try triger smu start\n");
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32_SMC(ixSMU_STATUS);
if (REG_GET_FIELD(val, SMU_STATUS, SMU_DONE))
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("Timeout for SMU start\n");
return -EINVAL;
}
val = RREG32_SMC(ixSMU_STATUS);
if (!REG_GET_FIELD(val, SMU_STATUS, SMU_PASS)) {
DRM_ERROR("SMU Firmware start failed\n");
return -EINVAL;
}
DRM_INFO("[FM]smu started\n");
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32_SMC(ixFIRMWARE_FLAGS);
if(REG_GET_FIELD(val, FIRMWARE_FLAGS, INTERRUPTS_ENABLED))
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("SMU firmware initialization failed\n");
return -EINVAL;
}
DRM_INFO("[FM]smu initialized\n");
return 0;
}
static int fiji_smu_start_in_non_protection_mode(struct amdgpu_device *adev)
{
int i, result;
uint32_t val;
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32_SMC(ixRCU_UC_EVENTS);
val = REG_GET_FIELD(val, RCU_UC_EVENTS, boot_seq_done);
if (val)
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("SMC boot sequence is not completed\n");
return -EINVAL;
}
WREG32_SMC(ixFIRMWARE_FLAGS, 0);
val = RREG32_SMC(ixSMC_SYSCON_RESET_CNTL);
val = REG_SET_FIELD(val, SMC_SYSCON_RESET_CNTL, rst_reg, 1);
WREG32_SMC(ixSMC_SYSCON_RESET_CNTL, val);
result = fiji_smu_upload_firmware_image(adev);
if (result)
return result;
fiji_program_jump_on_start(adev);
val = RREG32_SMC(ixSMC_SYSCON_CLOCK_CNTL_0);
val = REG_SET_FIELD(val, SMC_SYSCON_CLOCK_CNTL_0, ck_disable, 0);
WREG32_SMC(ixSMC_SYSCON_CLOCK_CNTL_0, val);
val = RREG32_SMC(ixSMC_SYSCON_RESET_CNTL);
val = REG_SET_FIELD(val, SMC_SYSCON_RESET_CNTL, rst_reg, 0);
WREG32_SMC(ixSMC_SYSCON_RESET_CNTL, val);
for (i = 0; i < adev->usec_timeout; i++) {
val = RREG32_SMC(ixFIRMWARE_FLAGS);
if (REG_GET_FIELD(val, FIRMWARE_FLAGS, INTERRUPTS_ENABLED))
break;
udelay(1);
}
if (i == adev->usec_timeout) {
DRM_ERROR("Timeout for SMC firmware initialization\n");
return -EINVAL;
}
return 0;
}
int fiji_smu_start(struct amdgpu_device *adev)
{
int result;
uint32_t val;
if (!fiji_is_smc_ram_running(adev)) {
val = RREG32_SMC(ixSMU_FIRMWARE);
if (!REG_GET_FIELD(val, SMU_FIRMWARE, SMU_MODE)) {
DRM_INFO("[FM]start smu in nonprotection mode\n");
result = fiji_smu_start_in_non_protection_mode(adev);
if (result)
return result;
} else {
DRM_INFO("[FM]start smu in protection mode\n");
result = fiji_smu_start_in_protection_mode(adev);
if (result)
return result;
}
}
return fiji_smu_request_load_fw(adev);
}
int fiji_smu_init(struct amdgpu_device *adev)
{
struct fiji_smu_private_data *private;
uint32_t image_size = ((sizeof(struct SMU_DRAMData_TOC) / 4096) + 1) * 4096;
uint32_t smu_internal_buffer_size = 200*4096;
struct amdgpu_bo **toc_buf = &adev->smu.toc_buf;
struct amdgpu_bo **smu_buf = &adev->smu.smu_buf;
uint64_t mc_addr;
void *toc_buf_ptr;
void *smu_buf_ptr;
int ret;
private = kzalloc(sizeof(struct fiji_smu_private_data), GFP_KERNEL);
if (NULL == private)
return -ENOMEM;
if (adev->firmware.smu_load)
amdgpu_ucode_init_bo(adev);
adev->smu.priv = private;
adev->smu.fw_flags = 0;
ret = amdgpu_bo_create(adev, image_size, PAGE_SIZE,
true, AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL, toc_buf);
if (ret) {
DRM_ERROR("Failed to allocate memory for TOC buffer\n");
return -ENOMEM;
}
ret = amdgpu_bo_create(adev, smu_internal_buffer_size, PAGE_SIZE,
true, AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL, smu_buf);
if (ret) {
DRM_ERROR("Failed to allocate memory for SMU internal buffer\n");
return -ENOMEM;
}
ret = amdgpu_bo_reserve(adev->smu.toc_buf, false);
if (ret) {
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to reserve the TOC buffer\n");
return -EINVAL;
}
ret = amdgpu_bo_pin(adev->smu.toc_buf, AMDGPU_GEM_DOMAIN_VRAM, &mc_addr);
if (ret) {
amdgpu_bo_unreserve(adev->smu.toc_buf);
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to pin the TOC buffer\n");
return -EINVAL;
}
ret = amdgpu_bo_kmap(*toc_buf, &toc_buf_ptr);
if (ret) {
amdgpu_bo_unreserve(adev->smu.toc_buf);
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to map the TOC buffer\n");
return -EINVAL;
}
amdgpu_bo_unreserve(adev->smu.toc_buf);
private->header_addr_low = lower_32_bits(mc_addr);
private->header_addr_high = upper_32_bits(mc_addr);
private->header = toc_buf_ptr;
ret = amdgpu_bo_reserve(adev->smu.smu_buf, false);
if (ret) {
amdgpu_bo_unref(&adev->smu.smu_buf);
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to reserve the SMU internal buffer\n");
return -EINVAL;
}
ret = amdgpu_bo_pin(adev->smu.smu_buf, AMDGPU_GEM_DOMAIN_VRAM, &mc_addr);
if (ret) {
amdgpu_bo_unreserve(adev->smu.smu_buf);
amdgpu_bo_unref(&adev->smu.smu_buf);
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to pin the SMU internal buffer\n");
return -EINVAL;
}
ret = amdgpu_bo_kmap(*smu_buf, &smu_buf_ptr);
if (ret) {
amdgpu_bo_unreserve(adev->smu.smu_buf);
amdgpu_bo_unref(&adev->smu.smu_buf);
amdgpu_bo_unref(&adev->smu.toc_buf);
DRM_ERROR("Failed to map the SMU internal buffer\n");
return -EINVAL;
}
amdgpu_bo_unreserve(adev->smu.smu_buf);
private->smu_buffer_addr_low = lower_32_bits(mc_addr);
private->smu_buffer_addr_high = upper_32_bits(mc_addr);
adev->smu.smumgr_funcs = &fiji_smumgr_funcs;
return 0;
}
int fiji_smu_fini(struct amdgpu_device *adev)
{
amdgpu_bo_unref(&adev->smu.toc_buf);
amdgpu_bo_unref(&adev->smu.smu_buf);
kfree(adev->smu.priv);
adev->smu.priv = NULL;
if (adev->firmware.fw_buf)
amdgpu_ucode_fini_bo(adev);
return 0;
}
