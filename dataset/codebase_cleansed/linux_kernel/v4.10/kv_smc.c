int amdgpu_kv_notify_message_to_smu(struct amdgpu_device *adev, u32 id)
{
u32 i;
u32 tmp = 0;
WREG32(mmSMC_MESSAGE_0, id & SMC_MESSAGE_0__SMC_MSG_MASK);
for (i = 0; i < adev->usec_timeout; i++) {
if ((RREG32(mmSMC_RESP_0) & SMC_RESP_0__SMC_RESP_MASK) != 0)
break;
udelay(1);
}
tmp = RREG32(mmSMC_RESP_0) & SMC_RESP_0__SMC_RESP_MASK;
if (tmp != 1) {
if (tmp == 0xFF)
return -EINVAL;
else if (tmp == 0xFE)
return -EINVAL;
}
return 0;
}
int amdgpu_kv_dpm_get_enable_mask(struct amdgpu_device *adev, u32 *enable_mask)
{
int ret;
ret = amdgpu_kv_notify_message_to_smu(adev, PPSMC_MSG_SCLKDPM_GetEnabledMask);
if (ret == 0)
*enable_mask = RREG32_SMC(ixSMC_SYSCON_MSG_ARG_0);
return ret;
}
int amdgpu_kv_send_msg_to_smc_with_parameter(struct amdgpu_device *adev,
PPSMC_Msg msg, u32 parameter)
{
WREG32(mmSMC_MSG_ARG_0, parameter);
return amdgpu_kv_notify_message_to_smu(adev, msg);
}
static int kv_set_smc_sram_address(struct amdgpu_device *adev,
u32 smc_address, u32 limit)
{
if (smc_address & 3)
return -EINVAL;
if ((smc_address + 3) > limit)
return -EINVAL;
WREG32(mmSMC_IND_INDEX_0, smc_address);
WREG32_P(mmSMC_IND_ACCESS_CNTL, 0,
~SMC_IND_ACCESS_CNTL__AUTO_INCREMENT_IND_0_MASK);
return 0;
}
int amdgpu_kv_read_smc_sram_dword(struct amdgpu_device *adev, u32 smc_address,
u32 *value, u32 limit)
{
int ret;
ret = kv_set_smc_sram_address(adev, smc_address, limit);
if (ret)
return ret;
*value = RREG32(mmSMC_IND_DATA_0);
return 0;
}
int amdgpu_kv_smc_dpm_enable(struct amdgpu_device *adev, bool enable)
{
if (enable)
return amdgpu_kv_notify_message_to_smu(adev, PPSMC_MSG_DPM_Enable);
else
return amdgpu_kv_notify_message_to_smu(adev, PPSMC_MSG_DPM_Disable);
}
int amdgpu_kv_smc_bapm_enable(struct amdgpu_device *adev, bool enable)
{
if (enable)
return amdgpu_kv_notify_message_to_smu(adev, PPSMC_MSG_EnableBAPM);
else
return amdgpu_kv_notify_message_to_smu(adev, PPSMC_MSG_DisableBAPM);
}
int amdgpu_kv_copy_bytes_to_smc(struct amdgpu_device *adev,
u32 smc_start_address,
const u8 *src, u32 byte_count, u32 limit)
{
int ret;
u32 data, original_data, addr, extra_shift, t_byte, count, mask;
if ((smc_start_address + byte_count) > limit)
return -EINVAL;
addr = smc_start_address;
t_byte = addr & 3;
if (t_byte != 0) {
addr -= t_byte;
ret = kv_set_smc_sram_address(adev, addr, limit);
if (ret)
return ret;
original_data = RREG32(mmSMC_IND_DATA_0);
data = 0;
mask = 0;
count = 4;
while (count > 0) {
if (t_byte > 0) {
mask = (mask << 8) | 0xff;
t_byte--;
} else if (byte_count > 0) {
data = (data << 8) + *src++;
byte_count--;
mask <<= 8;
} else {
data <<= 8;
mask = (mask << 8) | 0xff;
}
count--;
}
data |= original_data & mask;
ret = kv_set_smc_sram_address(adev, addr, limit);
if (ret)
return ret;
WREG32(mmSMC_IND_DATA_0, data);
addr += 4;
}
while (byte_count >= 4) {
data = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
ret = kv_set_smc_sram_address(adev, addr, limit);
if (ret)
return ret;
WREG32(mmSMC_IND_DATA_0, data);
src += 4;
byte_count -= 4;
addr += 4;
}
if (byte_count > 0) {
data = 0;
ret = kv_set_smc_sram_address(adev, addr, limit);
if (ret)
return ret;
original_data = RREG32(mmSMC_IND_DATA_0);
extra_shift = 8 * (4 - byte_count);
while (byte_count > 0) {
data = (data << 8) + *src++;
byte_count--;
}
data <<= extra_shift;
data |= (original_data & ~((~0UL) << extra_shift));
ret = kv_set_smc_sram_address(adev, addr, limit);
if (ret)
return ret;
WREG32(mmSMC_IND_DATA_0, data);
}
return 0;
}
