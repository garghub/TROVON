int rv770_set_smc_sram_address(struct radeon_device *rdev,
u16 smc_address, u16 limit)
{
u32 addr;
if (smc_address & 3)
return -EINVAL;
if ((smc_address + 3) > limit)
return -EINVAL;
addr = smc_address;
addr |= SMC_SRAM_AUTO_INC_DIS;
WREG32(SMC_SRAM_ADDR, addr);
return 0;
}
int rv770_copy_bytes_to_smc(struct radeon_device *rdev,
u16 smc_start_address, const u8 *src,
u16 byte_count, u16 limit)
{
u32 data, original_data, extra_shift;
u16 addr;
int ret;
if (smc_start_address & 3)
return -EINVAL;
if ((smc_start_address + byte_count) > limit)
return -EINVAL;
addr = smc_start_address;
while (byte_count >= 4) {
data = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3];
ret = rv770_set_smc_sram_address(rdev, addr, limit);
if (ret)
return ret;
WREG32(SMC_SRAM_DATA, data);
src += 4;
byte_count -= 4;
addr += 4;
}
if (byte_count > 0) {
data = 0;
ret = rv770_set_smc_sram_address(rdev, addr, limit);
if (ret)
return ret;
original_data = RREG32(SMC_SRAM_DATA);
extra_shift = 8 * (4 - byte_count);
while (byte_count > 0) {
data = (data << 8) + *src++;
byte_count--;
}
data <<= extra_shift;
data |= (original_data & ~((~0UL) << extra_shift));
ret = rv770_set_smc_sram_address(rdev, addr, limit);
if (ret)
return ret;
WREG32(SMC_SRAM_DATA, data);
}
return 0;
}
static int rv770_program_interrupt_vectors(struct radeon_device *rdev,
u32 smc_first_vector, const u8 *src,
u32 byte_count)
{
u32 tmp, i;
if (byte_count % 4)
return -EINVAL;
if (smc_first_vector < FIRST_SMC_INT_VECT_REG) {
tmp = FIRST_SMC_INT_VECT_REG - smc_first_vector;
if (tmp > byte_count)
return 0;
byte_count -= tmp;
src += tmp;
smc_first_vector = FIRST_SMC_INT_VECT_REG;
}
for (i = 0; i < byte_count; i += 4) {
tmp = (src[i] << 24) | (src[i + 1] << 16) | (src[i + 2] << 8) | src[i + 3];
WREG32(SMC_ISR_FFD8_FFDB + i, tmp);
}
return 0;
}
void rv770_start_smc(struct radeon_device *rdev)
{
WREG32_P(SMC_IO, SMC_RST_N, ~SMC_RST_N);
}
void rv770_reset_smc(struct radeon_device *rdev)
{
WREG32_P(SMC_IO, 0, ~SMC_RST_N);
}
void rv770_stop_smc_clock(struct radeon_device *rdev)
{
WREG32_P(SMC_IO, 0, ~SMC_CLK_EN);
}
void rv770_start_smc_clock(struct radeon_device *rdev)
{
WREG32_P(SMC_IO, SMC_CLK_EN, ~SMC_CLK_EN);
}
bool rv770_is_smc_running(struct radeon_device *rdev)
{
u32 tmp;
tmp = RREG32(SMC_IO);
if ((tmp & SMC_RST_N) && (tmp & SMC_CLK_EN))
return true;
else
return false;
}
PPSMC_Result rv770_send_msg_to_smc(struct radeon_device *rdev, PPSMC_Msg msg)
{
u32 tmp;
int i;
PPSMC_Result result;
if (!rv770_is_smc_running(rdev))
return PPSMC_Result_Failed;
WREG32_P(SMC_MSG, HOST_SMC_MSG(msg), ~HOST_SMC_MSG_MASK);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(SMC_MSG) & HOST_SMC_RESP_MASK;
tmp >>= HOST_SMC_RESP_SHIFT;
if (tmp != 0)
break;
udelay(1);
}
tmp = RREG32(SMC_MSG) & HOST_SMC_RESP_MASK;
tmp >>= HOST_SMC_RESP_SHIFT;
result = (PPSMC_Result)tmp;
return result;
}
PPSMC_Result rv770_wait_for_smc_inactive(struct radeon_device *rdev)
{
int i;
PPSMC_Result result = PPSMC_Result_OK;
if (!rv770_is_smc_running(rdev))
return result;
for (i = 0; i < rdev->usec_timeout; i++) {
if (RREG32(SMC_IO) & SMC_STOP_MODE)
break;
udelay(1);
}
return result;
}
static void rv770_clear_smc_sram(struct radeon_device *rdev, u16 limit)
{
u16 i;
for (i = 0; i < limit; i += 4) {
rv770_set_smc_sram_address(rdev, i, limit);
WREG32(SMC_SRAM_DATA, 0);
}
}
int rv770_load_smc_ucode(struct radeon_device *rdev,
u16 limit)
{
int ret;
const u8 *int_vect;
u16 int_vect_start_address;
u16 int_vect_size;
const u8 *ucode_data;
u16 ucode_start_address;
u16 ucode_size;
if (!rdev->smc_fw)
return -EINVAL;
rv770_clear_smc_sram(rdev, limit);
switch (rdev->family) {
case CHIP_RV770:
ucode_start_address = RV770_SMC_UCODE_START;
ucode_size = RV770_SMC_UCODE_SIZE;
int_vect = (const u8 *)&rv770_smc_int_vectors;
int_vect_start_address = RV770_SMC_INT_VECTOR_START;
int_vect_size = RV770_SMC_INT_VECTOR_SIZE;
break;
case CHIP_RV730:
ucode_start_address = RV730_SMC_UCODE_START;
ucode_size = RV730_SMC_UCODE_SIZE;
int_vect = (const u8 *)&rv730_smc_int_vectors;
int_vect_start_address = RV730_SMC_INT_VECTOR_START;
int_vect_size = RV730_SMC_INT_VECTOR_SIZE;
break;
case CHIP_RV710:
ucode_start_address = RV710_SMC_UCODE_START;
ucode_size = RV710_SMC_UCODE_SIZE;
int_vect = (const u8 *)&rv710_smc_int_vectors;
int_vect_start_address = RV710_SMC_INT_VECTOR_START;
int_vect_size = RV710_SMC_INT_VECTOR_SIZE;
break;
case CHIP_RV740:
ucode_start_address = RV740_SMC_UCODE_START;
ucode_size = RV740_SMC_UCODE_SIZE;
int_vect = (const u8 *)&rv740_smc_int_vectors;
int_vect_start_address = RV740_SMC_INT_VECTOR_START;
int_vect_size = RV740_SMC_INT_VECTOR_SIZE;
break;
case CHIP_CEDAR:
ucode_start_address = CEDAR_SMC_UCODE_START;
ucode_size = CEDAR_SMC_UCODE_SIZE;
int_vect = (const u8 *)&cedar_smc_int_vectors;
int_vect_start_address = CEDAR_SMC_INT_VECTOR_START;
int_vect_size = CEDAR_SMC_INT_VECTOR_SIZE;
break;
case CHIP_REDWOOD:
ucode_start_address = REDWOOD_SMC_UCODE_START;
ucode_size = REDWOOD_SMC_UCODE_SIZE;
int_vect = (const u8 *)&redwood_smc_int_vectors;
int_vect_start_address = REDWOOD_SMC_INT_VECTOR_START;
int_vect_size = REDWOOD_SMC_INT_VECTOR_SIZE;
break;
case CHIP_JUNIPER:
ucode_start_address = JUNIPER_SMC_UCODE_START;
ucode_size = JUNIPER_SMC_UCODE_SIZE;
int_vect = (const u8 *)&juniper_smc_int_vectors;
int_vect_start_address = JUNIPER_SMC_INT_VECTOR_START;
int_vect_size = JUNIPER_SMC_INT_VECTOR_SIZE;
break;
case CHIP_CYPRESS:
case CHIP_HEMLOCK:
ucode_start_address = CYPRESS_SMC_UCODE_START;
ucode_size = CYPRESS_SMC_UCODE_SIZE;
int_vect = (const u8 *)&cypress_smc_int_vectors;
int_vect_start_address = CYPRESS_SMC_INT_VECTOR_START;
int_vect_size = CYPRESS_SMC_INT_VECTOR_SIZE;
break;
case CHIP_BARTS:
ucode_start_address = BARTS_SMC_UCODE_START;
ucode_size = BARTS_SMC_UCODE_SIZE;
int_vect = (const u8 *)&barts_smc_int_vectors;
int_vect_start_address = BARTS_SMC_INT_VECTOR_START;
int_vect_size = BARTS_SMC_INT_VECTOR_SIZE;
break;
case CHIP_TURKS:
ucode_start_address = TURKS_SMC_UCODE_START;
ucode_size = TURKS_SMC_UCODE_SIZE;
int_vect = (const u8 *)&turks_smc_int_vectors;
int_vect_start_address = TURKS_SMC_INT_VECTOR_START;
int_vect_size = TURKS_SMC_INT_VECTOR_SIZE;
break;
case CHIP_CAICOS:
ucode_start_address = CAICOS_SMC_UCODE_START;
ucode_size = CAICOS_SMC_UCODE_SIZE;
int_vect = (const u8 *)&caicos_smc_int_vectors;
int_vect_start_address = CAICOS_SMC_INT_VECTOR_START;
int_vect_size = CAICOS_SMC_INT_VECTOR_SIZE;
break;
case CHIP_CAYMAN:
ucode_start_address = CAYMAN_SMC_UCODE_START;
ucode_size = CAYMAN_SMC_UCODE_SIZE;
int_vect = (const u8 *)&cayman_smc_int_vectors;
int_vect_start_address = CAYMAN_SMC_INT_VECTOR_START;
int_vect_size = CAYMAN_SMC_INT_VECTOR_SIZE;
break;
default:
DRM_ERROR("unknown asic in smc ucode loader\n");
BUG();
}
ucode_data = (const u8 *)rdev->smc_fw->data;
ret = rv770_copy_bytes_to_smc(rdev, ucode_start_address,
ucode_data, ucode_size, limit);
if (ret)
return ret;
ret = rv770_program_interrupt_vectors(rdev, int_vect_start_address,
int_vect, int_vect_size);
if (ret)
return ret;
return 0;
}
int rv770_read_smc_sram_dword(struct radeon_device *rdev,
u16 smc_address, u32 *value, u16 limit)
{
int ret;
ret = rv770_set_smc_sram_address(rdev, smc_address, limit);
if (ret)
return ret;
*value = RREG32(SMC_SRAM_DATA);
return 0;
}
int rv770_write_smc_sram_dword(struct radeon_device *rdev,
u16 smc_address, u32 value, u16 limit)
{
int ret;
ret = rv770_set_smc_sram_address(rdev, smc_address, limit);
if (ret)
return ret;
WREG32(SMC_SRAM_DATA, value);
return 0;
}
