static u32 sdma_v4_0_get_reg_offset(u32 instance, u32 internal_offset)
{
u32 base = 0;
switch (instance) {
case 0:
base = SDMA0_BASE.instance[0].segment[0];
break;
case 1:
base = SDMA1_BASE.instance[0].segment[0];
break;
default:
BUG();
break;
}
return base + internal_offset;
}
static void sdma_v4_0_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_VEGA10:
amdgpu_program_register_sequence(adev,
golden_settings_sdma_4,
(const u32)ARRAY_SIZE(golden_settings_sdma_4));
amdgpu_program_register_sequence(adev,
golden_settings_sdma_vg10,
(const u32)ARRAY_SIZE(golden_settings_sdma_vg10));
break;
case CHIP_RAVEN:
amdgpu_program_register_sequence(adev,
golden_settings_sdma_4_1,
(const u32)ARRAY_SIZE(golden_settings_sdma_4_1));
amdgpu_program_register_sequence(adev,
golden_settings_sdma_rv1,
(const u32)ARRAY_SIZE(golden_settings_sdma_rv1));
break;
default:
break;
}
}
static int sdma_v4_0_init_microcode(struct amdgpu_device *adev)
{
const char *chip_name;
char fw_name[30];
int err = 0, i;
struct amdgpu_firmware_info *info = NULL;
const struct common_firmware_header *header = NULL;
const struct sdma_firmware_header_v1_0 *hdr;
DRM_DEBUG("\n");
switch (adev->asic_type) {
case CHIP_VEGA10:
chip_name = "vega10";
break;
case CHIP_RAVEN:
chip_name = "raven";
break;
default:
BUG();
}
for (i = 0; i < adev->sdma.num_instances; i++) {
if (i == 0)
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_sdma.bin", chip_name);
else
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_sdma1.bin", chip_name);
err = request_firmware(&adev->sdma.instance[i].fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->sdma.instance[i].fw);
if (err)
goto out;
hdr = (const struct sdma_firmware_header_v1_0 *)adev->sdma.instance[i].fw->data;
adev->sdma.instance[i].fw_version = le32_to_cpu(hdr->header.ucode_version);
adev->sdma.instance[i].feature_version = le32_to_cpu(hdr->ucode_feature_version);
if (adev->sdma.instance[i].feature_version >= 20)
adev->sdma.instance[i].burst_nop = true;
DRM_DEBUG("psp_load == '%s'\n",
adev->firmware.load_type == AMDGPU_FW_LOAD_PSP ? "true" : "false");
if (adev->firmware.load_type == AMDGPU_FW_LOAD_PSP) {
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_SDMA0 + i];
info->ucode_id = AMDGPU_UCODE_ID_SDMA0 + i;
info->fw = adev->sdma.instance[i].fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
}
}
out:
if (err) {
DRM_ERROR("sdma_v4_0: Failed to load firmware \"%s\"\n", fw_name);
for (i = 0; i < adev->sdma.num_instances; i++) {
release_firmware(adev->sdma.instance[i].fw);
adev->sdma.instance[i].fw = NULL;
}
}
return err;
}
static uint64_t sdma_v4_0_ring_get_rptr(struct amdgpu_ring *ring)
{
u64 *rptr;
rptr = ((u64 *)&ring->adev->wb.wb[ring->rptr_offs]);
DRM_DEBUG("rptr before shift == 0x%016llx\n", *rptr);
return ((*rptr) >> 2);
}
static uint64_t sdma_v4_0_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u64 *wptr = NULL;
uint64_t local_wptr = 0;
if (ring->use_doorbell) {
wptr = ((u64 *)&adev->wb.wb[ring->wptr_offs]);
DRM_DEBUG("wptr/doorbell before shift == 0x%016llx\n", *wptr);
*wptr = (*wptr) >> 2;
DRM_DEBUG("wptr/doorbell after shift == 0x%016llx\n", *wptr);
} else {
u32 lowbit, highbit;
int me = (ring == &adev->sdma.instance[0].ring) ? 0 : 1;
wptr = &local_wptr;
lowbit = RREG32(sdma_v4_0_get_reg_offset(me, mmSDMA0_GFX_RB_WPTR)) >> 2;
highbit = RREG32(sdma_v4_0_get_reg_offset(me, mmSDMA0_GFX_RB_WPTR_HI)) >> 2;
DRM_DEBUG("wptr [%i]high== 0x%08x low==0x%08x\n",
me, highbit, lowbit);
*wptr = highbit;
*wptr = (*wptr) << 32;
*wptr |= lowbit;
}
return *wptr;
}
static void sdma_v4_0_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
DRM_DEBUG("Setting write pointer\n");
if (ring->use_doorbell) {
DRM_DEBUG("Using doorbell -- "
"wptr_offs == 0x%08x "
"lower_32_bits(ring->wptr) << 2 == 0x%08x "
"upper_32_bits(ring->wptr) << 2 == 0x%08x\n",
ring->wptr_offs,
lower_32_bits(ring->wptr << 2),
upper_32_bits(ring->wptr << 2));
adev->wb.wb[ring->wptr_offs] = lower_32_bits(ring->wptr << 2);
adev->wb.wb[ring->wptr_offs + 1] = upper_32_bits(ring->wptr << 2);
DRM_DEBUG("calling WDOORBELL64(0x%08x, 0x%016llx)\n",
ring->doorbell_index, ring->wptr << 2);
WDOORBELL64(ring->doorbell_index, ring->wptr << 2);
} else {
int me = (ring == &ring->adev->sdma.instance[0].ring) ? 0 : 1;
DRM_DEBUG("Not using doorbell -- "
"mmSDMA%i_GFX_RB_WPTR == 0x%08x "
"mmSDMA%i_GFX_RB_WPTR_HI == 0x%08x\n",
me,
lower_32_bits(ring->wptr << 2),
me,
upper_32_bits(ring->wptr << 2));
WREG32(sdma_v4_0_get_reg_offset(me, mmSDMA0_GFX_RB_WPTR), lower_32_bits(ring->wptr << 2));
WREG32(sdma_v4_0_get_reg_offset(me, mmSDMA0_GFX_RB_WPTR_HI), upper_32_bits(ring->wptr << 2));
}
}
static void sdma_v4_0_ring_insert_nop(struct amdgpu_ring *ring, uint32_t count)
{
struct amdgpu_sdma_instance *sdma = amdgpu_get_sdma_instance(ring);
int i;
for (i = 0; i < count; i++)
if (sdma && sdma->burst_nop && (i == 0))
amdgpu_ring_write(ring, ring->funcs->nop |
SDMA_PKT_NOP_HEADER_COUNT(count - 1));
else
amdgpu_ring_write(ring, ring->funcs->nop);
}
static void sdma_v4_0_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 vmid = vm_id & 0xf;
sdma_v4_0_ring_insert_nop(ring, (10 - (lower_32_bits(ring->wptr) & 7)) % 8);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_INDIRECT) |
SDMA_PKT_INDIRECT_HEADER_VMID(vmid));
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr) & 0xffffffe0);
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, ib->length_dw);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
}
static void sdma_v4_0_ring_emit_hdp_flush(struct amdgpu_ring *ring)
{
u32 ref_and_mask = 0;
struct nbio_hdp_flush_reg *nbio_hf_reg;
if (ring->adev->flags & AMD_IS_APU)
nbio_hf_reg = &nbio_v7_0_hdp_flush_reg;
else
nbio_hf_reg = &nbio_v6_1_hdp_flush_reg;
if (ring == &ring->adev->sdma.instance[0].ring)
ref_and_mask = nbio_hf_reg->ref_and_mask_sdma0;
else
ref_and_mask = nbio_hf_reg->ref_and_mask_sdma1;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_POLL_REGMEM) |
SDMA_PKT_POLL_REGMEM_HEADER_HDP_FLUSH(1) |
SDMA_PKT_POLL_REGMEM_HEADER_FUNC(3));
amdgpu_ring_write(ring, nbio_hf_reg->hdp_flush_done_offset << 2);
amdgpu_ring_write(ring, nbio_hf_reg->hdp_flush_req_offset << 2);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, SDMA_PKT_POLL_REGMEM_DW5_RETRY_COUNT(0xfff) |
SDMA_PKT_POLL_REGMEM_DW5_INTERVAL(10));
}
static void sdma_v4_0_ring_emit_hdp_invalidate(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, SOC15_REG_OFFSET(HDP, 0, mmHDP_DEBUG0));
amdgpu_ring_write(ring, 1);
}
static void sdma_v4_0_ring_emit_fence(struct amdgpu_ring *ring, u64 addr, u64 seq,
unsigned flags)
{
bool write64bit = flags & AMDGPU_FENCE_FLAG_64BIT;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_FENCE));
BUG_ON(addr & 0x3);
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, lower_32_bits(seq));
if (write64bit) {
addr += 4;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_FENCE));
BUG_ON(addr & 0x3);
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(seq));
}
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_TRAP));
amdgpu_ring_write(ring, SDMA_PKT_TRAP_INT_CONTEXT_INT_CONTEXT(0));
}
static void sdma_v4_0_gfx_stop(struct amdgpu_device *adev)
{
struct amdgpu_ring *sdma0 = &adev->sdma.instance[0].ring;
struct amdgpu_ring *sdma1 = &adev->sdma.instance[1].ring;
u32 rb_cntl, ib_cntl;
int i;
if ((adev->mman.buffer_funcs_ring == sdma0) ||
(adev->mman.buffer_funcs_ring == sdma1))
amdgpu_ttm_set_active_vram_size(adev, adev->mc.visible_vram_size);
for (i = 0; i < adev->sdma.num_instances; i++) {
rb_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_CNTL));
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_ENABLE, 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_CNTL), rb_cntl);
ib_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_IB_CNTL));
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_ENABLE, 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_IB_CNTL), ib_cntl);
}
sdma0->ready = false;
sdma1->ready = false;
}
static void sdma_v4_0_rlc_stop(struct amdgpu_device *adev)
{
}
static void sdma_v4_0_ctx_switch_enable(struct amdgpu_device *adev, bool enable)
{
u32 f32_cntl;
int i;
for (i = 0; i < adev->sdma.num_instances; i++) {
f32_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_CNTL));
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_CNTL,
AUTO_CTXSW_ENABLE, enable ? 1 : 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_CNTL), f32_cntl);
}
}
static void sdma_v4_0_enable(struct amdgpu_device *adev, bool enable)
{
u32 f32_cntl;
int i;
if (enable == false) {
sdma_v4_0_gfx_stop(adev);
sdma_v4_0_rlc_stop(adev);
}
for (i = 0; i < adev->sdma.num_instances; i++) {
f32_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_F32_CNTL));
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_F32_CNTL, HALT, enable ? 0 : 1);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_F32_CNTL), f32_cntl);
}
}
static int sdma_v4_0_gfx_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
u32 rb_cntl, ib_cntl;
u32 rb_bufsz;
u32 wb_offset;
u32 doorbell;
u32 doorbell_offset;
u32 temp;
int i, r;
for (i = 0; i < adev->sdma.num_instances; i++) {
ring = &adev->sdma.instance[i].ring;
wb_offset = (ring->rptr_offs * 4);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_SEM_WAIT_FAIL_TIMER_CNTL), 0);
rb_bufsz = order_base_2(ring->ring_size / 4);
rb_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_CNTL));
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_SIZE, rb_bufsz);
#ifdef __BIG_ENDIAN
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_SWAP_ENABLE, 1);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL,
RPTR_WRITEBACK_SWAP_ENABLE, 1);
#endif
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_CNTL), rb_cntl);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_RPTR), 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_RPTR_HI), 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_WPTR), 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_WPTR_HI), 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_RPTR_ADDR_HI),
upper_32_bits(adev->wb.gpu_addr + wb_offset) & 0xFFFFFFFF);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_RPTR_ADDR_LO),
lower_32_bits(adev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RPTR_WRITEBACK_ENABLE, 1);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_BASE), ring->gpu_addr >> 8);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_BASE_HI), ring->gpu_addr >> 40);
ring->wptr = 0;
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_MINOR_PTR_UPDATE), 1);
if (!amdgpu_sriov_vf(adev)) {
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_WPTR), lower_32_bits(ring->wptr) << 2);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_WPTR_HI), upper_32_bits(ring->wptr) << 2);
}
doorbell = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_DOORBELL));
doorbell_offset = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_DOORBELL_OFFSET));
if (ring->use_doorbell) {
doorbell = REG_SET_FIELD(doorbell, SDMA0_GFX_DOORBELL, ENABLE, 1);
doorbell_offset = REG_SET_FIELD(doorbell_offset, SDMA0_GFX_DOORBELL_OFFSET,
OFFSET, ring->doorbell_index);
} else {
doorbell = REG_SET_FIELD(doorbell, SDMA0_GFX_DOORBELL, ENABLE, 0);
}
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_DOORBELL), doorbell);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_DOORBELL_OFFSET), doorbell_offset);
if (adev->flags & AMD_IS_APU)
nbio_v7_0_sdma_doorbell_range(adev, i, ring->use_doorbell, ring->doorbell_index);
else
nbio_v6_1_sdma_doorbell_range(adev, i, ring->use_doorbell, ring->doorbell_index);
if (amdgpu_sriov_vf(adev))
sdma_v4_0_ring_set_wptr(ring);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_MINOR_PTR_UPDATE), 0);
temp = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_CNTL));
temp = REG_SET_FIELD(temp, SDMA0_CNTL, UTC_L1_ENABLE, 1);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_CNTL), temp);
if (!amdgpu_sriov_vf(adev)) {
temp = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_F32_CNTL));
temp = REG_SET_FIELD(temp, SDMA0_F32_CNTL, HALT, 0);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_F32_CNTL), temp);
}
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_ENABLE, 1);
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_RB_CNTL), rb_cntl);
ib_cntl = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_IB_CNTL));
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_ENABLE, 1);
#ifdef __BIG_ENDIAN
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_SWAP_ENABLE, 1);
#endif
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_GFX_IB_CNTL), ib_cntl);
ring->ready = true;
if (amdgpu_sriov_vf(adev)) {
sdma_v4_0_ctx_switch_enable(adev, true);
sdma_v4_0_enable(adev, true);
}
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
if (adev->mman.buffer_funcs_ring == ring)
amdgpu_ttm_set_active_vram_size(adev, adev->mc.real_vram_size);
}
return 0;
}
static void
sdma_v4_1_update_power_gating(struct amdgpu_device *adev, bool enable)
{
uint32_t def, data;
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_SDMA)) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL));
data |= SDMA0_CNTL__CTXEMPTY_INT_ENABLE_MASK;
if (data != def)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL), data);
} else {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL));
data &= ~SDMA0_CNTL__CTXEMPTY_INT_ENABLE_MASK;
if (data != def)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL), data);
}
}
static void sdma_v4_1_init_power_gating(struct amdgpu_device *adev)
{
uint32_t def, data;
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL));
data |= SDMA0_POWER_CNTL__PG_CNTL_ENABLE_MASK;
if (data != def)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL), data);
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL));
data |= SDMA0_CNTL__CTXEMPTY_INT_ENABLE_MASK;
if (data != def)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CNTL), data);
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL));
data &= ~SDMA0_POWER_CNTL__ON_OFF_CONDITION_HOLD_TIME_MASK;
data |= (mmSDMA0_POWER_CNTL_DEFAULT & SDMA0_POWER_CNTL__ON_OFF_CONDITION_HOLD_TIME_MASK);
data &= ~SDMA0_POWER_CNTL__ON_OFF_STATUS_DURATION_TIME_MASK;
data |= (mmSDMA0_POWER_CNTL_DEFAULT & SDMA0_POWER_CNTL__ON_OFF_STATUS_DURATION_TIME_MASK);
if(data != def)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL), data);
}
static void sdma_v4_0_init_pg(struct amdgpu_device *adev)
{
if (!(adev->pg_flags & AMD_PG_SUPPORT_SDMA))
return;
switch (adev->asic_type) {
case CHIP_RAVEN:
sdma_v4_1_init_power_gating(adev);
sdma_v4_1_update_power_gating(adev, true);
break;
default:
break;
}
}
static int sdma_v4_0_rlc_resume(struct amdgpu_device *adev)
{
sdma_v4_0_init_pg(adev);
return 0;
}
static int sdma_v4_0_load_microcode(struct amdgpu_device *adev)
{
const struct sdma_firmware_header_v1_0 *hdr;
const __le32 *fw_data;
u32 fw_size;
u32 digest_size = 0;
int i, j;
sdma_v4_0_enable(adev, false);
for (i = 0; i < adev->sdma.num_instances; i++) {
uint16_t version_major;
uint16_t version_minor;
if (!adev->sdma.instance[i].fw)
return -EINVAL;
hdr = (const struct sdma_firmware_header_v1_0 *)adev->sdma.instance[i].fw->data;
amdgpu_ucode_print_sdma_hdr(&hdr->header);
fw_size = le32_to_cpu(hdr->header.ucode_size_bytes) / 4;
version_major = le16_to_cpu(hdr->header.header_version_major);
version_minor = le16_to_cpu(hdr->header.header_version_minor);
if (version_major == 1 && version_minor >= 1) {
const struct sdma_firmware_header_v1_1 *sdma_v1_1_hdr = (const struct sdma_firmware_header_v1_1 *) hdr;
digest_size = le32_to_cpu(sdma_v1_1_hdr->digest_size);
}
fw_size -= digest_size;
fw_data = (const __le32 *)
(adev->sdma.instance[i].fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_UCODE_ADDR), 0);
for (j = 0; j < fw_size; j++)
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_UCODE_DATA), le32_to_cpup(fw_data++));
WREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_UCODE_ADDR), adev->sdma.instance[i].fw_version);
}
return 0;
}
static int sdma_v4_0_start(struct amdgpu_device *adev)
{
int r = 0;
if (amdgpu_sriov_vf(adev)) {
sdma_v4_0_ctx_switch_enable(adev, false);
sdma_v4_0_enable(adev, false);
r = sdma_v4_0_gfx_resume(adev);
return r;
}
if (adev->firmware.load_type != AMDGPU_FW_LOAD_PSP) {
r = sdma_v4_0_load_microcode(adev);
if (r)
return r;
}
sdma_v4_0_enable(adev, true);
sdma_v4_0_ctx_switch_enable(adev, true);
r = sdma_v4_0_gfx_resume(adev);
if (r)
return r;
r = sdma_v4_0_rlc_resume(adev);
return r;
}
static int sdma_v4_0_ring_test_ring(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
unsigned i;
unsigned index;
int r;
u32 tmp;
u64 gpu_addr;
r = amdgpu_wb_get(adev, &index);
if (r) {
dev_err(adev->dev, "(%d) failed to allocate wb slot\n", r);
return r;
}
gpu_addr = adev->wb.gpu_addr + (index * 4);
tmp = 0xCAFEDEAD;
adev->wb.wb[index] = cpu_to_le32(tmp);
r = amdgpu_ring_alloc(ring, 5);
if (r) {
DRM_ERROR("amdgpu: dma failed to lock ring %d (%d).\n", ring->idx, r);
amdgpu_wb_free(adev, index);
return r;
}
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_WRITE) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_WRITE_LINEAR));
amdgpu_ring_write(ring, lower_32_bits(gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(gpu_addr));
amdgpu_ring_write(ring, SDMA_PKT_WRITE_UNTILED_DW_3_COUNT(0));
amdgpu_ring_write(ring, 0xDEADBEEF);
amdgpu_ring_commit(ring);
for (i = 0; i < adev->usec_timeout; i++) {
tmp = le32_to_cpu(adev->wb.wb[index]);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n", ring->idx, i);
} else {
DRM_ERROR("amdgpu: ring %d test failed (0x%08X)\n",
ring->idx, tmp);
r = -EINVAL;
}
amdgpu_wb_free(adev, index);
return r;
}
static int sdma_v4_0_ring_test_ib(struct amdgpu_ring *ring, long timeout)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib ib;
struct dma_fence *f = NULL;
unsigned index;
long r;
u32 tmp = 0;
u64 gpu_addr;
r = amdgpu_wb_get(adev, &index);
if (r) {
dev_err(adev->dev, "(%ld) failed to allocate wb slot\n", r);
return r;
}
gpu_addr = adev->wb.gpu_addr + (index * 4);
tmp = 0xCAFEDEAD;
adev->wb.wb[index] = cpu_to_le32(tmp);
memset(&ib, 0, sizeof(ib));
r = amdgpu_ib_get(adev, NULL, 256, &ib);
if (r) {
DRM_ERROR("amdgpu: failed to get ib (%ld).\n", r);
goto err0;
}
ib.ptr[0] = SDMA_PKT_HEADER_OP(SDMA_OP_WRITE) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_WRITE_LINEAR);
ib.ptr[1] = lower_32_bits(gpu_addr);
ib.ptr[2] = upper_32_bits(gpu_addr);
ib.ptr[3] = SDMA_PKT_WRITE_UNTILED_DW_3_COUNT(0);
ib.ptr[4] = 0xDEADBEEF;
ib.ptr[5] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.ptr[6] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.ptr[7] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.length_dw = 8;
r = amdgpu_ib_schedule(ring, 1, &ib, NULL, &f);
if (r)
goto err1;
r = dma_fence_wait_timeout(f, false, timeout);
if (r == 0) {
DRM_ERROR("amdgpu: IB test timed out\n");
r = -ETIMEDOUT;
goto err1;
} else if (r < 0) {
DRM_ERROR("amdgpu: fence wait failed (%ld).\n", r);
goto err1;
}
tmp = le32_to_cpu(adev->wb.wb[index]);
if (tmp == 0xDEADBEEF) {
DRM_INFO("ib test on ring %d succeeded\n", ring->idx);
r = 0;
} else {
DRM_ERROR("amdgpu: ib test failed (0x%08X)\n", tmp);
r = -EINVAL;
}
err1:
amdgpu_ib_free(adev, &ib, NULL);
dma_fence_put(f);
err0:
amdgpu_wb_free(adev, index);
return r;
}
static void sdma_v4_0_vm_copy_pte(struct amdgpu_ib *ib,
uint64_t pe, uint64_t src,
unsigned count)
{
unsigned bytes = count * 8;
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_COPY) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_COPY_LINEAR);
ib->ptr[ib->length_dw++] = bytes - 1;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(src);
ib->ptr[ib->length_dw++] = upper_32_bits(src);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
}
static void sdma_v4_0_vm_write_pte(struct amdgpu_ib *ib, uint64_t pe,
uint64_t value, unsigned count,
uint32_t incr)
{
unsigned ndw = count * 2;
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_WRITE) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_WRITE_LINEAR);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = ndw - 1;
for (; ndw > 0; ndw -= 2) {
ib->ptr[ib->length_dw++] = lower_32_bits(value);
ib->ptr[ib->length_dw++] = upper_32_bits(value);
value += incr;
}
}
static void sdma_v4_0_vm_set_pte_pde(struct amdgpu_ib *ib,
uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint64_t flags)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_PTEPDE);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = lower_32_bits(flags);
ib->ptr[ib->length_dw++] = upper_32_bits(flags);
ib->ptr[ib->length_dw++] = lower_32_bits(addr);
ib->ptr[ib->length_dw++] = upper_32_bits(addr);
ib->ptr[ib->length_dw++] = incr;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = count - 1;
}
static void sdma_v4_0_ring_pad_ib(struct amdgpu_ring *ring, struct amdgpu_ib *ib)
{
struct amdgpu_sdma_instance *sdma = amdgpu_get_sdma_instance(ring);
u32 pad_count;
int i;
pad_count = (8 - (ib->length_dw & 0x7)) % 8;
for (i = 0; i < pad_count; i++)
if (sdma && sdma->burst_nop && (i == 0))
ib->ptr[ib->length_dw++] =
SDMA_PKT_HEADER_OP(SDMA_OP_NOP) |
SDMA_PKT_NOP_HEADER_COUNT(pad_count - 1);
else
ib->ptr[ib->length_dw++] =
SDMA_PKT_HEADER_OP(SDMA_OP_NOP);
}
static void sdma_v4_0_ring_emit_pipeline_sync(struct amdgpu_ring *ring)
{
uint32_t seq = ring->fence_drv.sync_seq;
uint64_t addr = ring->fence_drv.gpu_addr;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_POLL_REGMEM) |
SDMA_PKT_POLL_REGMEM_HEADER_HDP_FLUSH(0) |
SDMA_PKT_POLL_REGMEM_HEADER_FUNC(3) |
SDMA_PKT_POLL_REGMEM_HEADER_MEM_POLL(1));
amdgpu_ring_write(ring, addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(addr) & 0xffffffff);
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring, 0xfffffff);
amdgpu_ring_write(ring, SDMA_PKT_POLL_REGMEM_DW5_RETRY_COUNT(0xfff) |
SDMA_PKT_POLL_REGMEM_DW5_INTERVAL(4));
}
static void sdma_v4_0_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr)
{
struct amdgpu_vmhub *hub = &ring->adev->vmhub[ring->funcs->vmhub];
uint32_t req = ring->adev->gart.gart_funcs->get_invalidate_req(vm_id);
unsigned eng = ring->vm_inv_eng;
pd_addr = amdgpu_gart_get_vm_pde(ring->adev, pd_addr);
pd_addr |= AMDGPU_PTE_VALID;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, hub->ctx0_ptb_addr_lo32 + vm_id * 2);
amdgpu_ring_write(ring, lower_32_bits(pd_addr));
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, hub->ctx0_ptb_addr_hi32 + vm_id * 2);
amdgpu_ring_write(ring, upper_32_bits(pd_addr));
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, hub->vm_inv_eng0_req + eng);
amdgpu_ring_write(ring, req);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_POLL_REGMEM) |
SDMA_PKT_POLL_REGMEM_HEADER_HDP_FLUSH(0) |
SDMA_PKT_POLL_REGMEM_HEADER_FUNC(3));
amdgpu_ring_write(ring, (hub->vm_inv_eng0_ack + eng) << 2);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 1 << vm_id);
amdgpu_ring_write(ring, 1 << vm_id);
amdgpu_ring_write(ring, SDMA_PKT_POLL_REGMEM_DW5_RETRY_COUNT(0xfff) |
SDMA_PKT_POLL_REGMEM_DW5_INTERVAL(10));
}
static int sdma_v4_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (adev->asic_type == CHIP_RAVEN)
adev->sdma.num_instances = 1;
else
adev->sdma.num_instances = 2;
sdma_v4_0_set_ring_funcs(adev);
sdma_v4_0_set_buffer_funcs(adev);
sdma_v4_0_set_vm_pte_funcs(adev);
sdma_v4_0_set_irq_funcs(adev);
return 0;
}
static int sdma_v4_0_sw_init(void *handle)
{
struct amdgpu_ring *ring;
int r, i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_SDMA0, 224,
&adev->sdma.trap_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_SDMA1, 224,
&adev->sdma.trap_irq);
if (r)
return r;
r = sdma_v4_0_init_microcode(adev);
if (r) {
DRM_ERROR("Failed to load sdma firmware!\n");
return r;
}
for (i = 0; i < adev->sdma.num_instances; i++) {
ring = &adev->sdma.instance[i].ring;
ring->ring_obj = NULL;
ring->use_doorbell = true;
DRM_INFO("use_doorbell being set to: [%s]\n",
ring->use_doorbell?"true":"false");
ring->doorbell_index = (i == 0) ?
(AMDGPU_DOORBELL64_sDMA_ENGINE0 << 1)
: (AMDGPU_DOORBELL64_sDMA_ENGINE1 << 1);
sprintf(ring->name, "sdma%d", i);
r = amdgpu_ring_init(adev, ring, 1024,
&adev->sdma.trap_irq,
(i == 0) ?
AMDGPU_SDMA_IRQ_TRAP0 :
AMDGPU_SDMA_IRQ_TRAP1);
if (r)
return r;
}
return r;
}
static int sdma_v4_0_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int i;
for (i = 0; i < adev->sdma.num_instances; i++)
amdgpu_ring_fini(&adev->sdma.instance[i].ring);
return 0;
}
static int sdma_v4_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
sdma_v4_0_init_golden_registers(adev);
r = sdma_v4_0_start(adev);
return r;
}
static int sdma_v4_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
return 0;
sdma_v4_0_ctx_switch_enable(adev, false);
sdma_v4_0_enable(adev, false);
return 0;
}
static int sdma_v4_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return sdma_v4_0_hw_fini(adev);
}
static int sdma_v4_0_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return sdma_v4_0_hw_init(adev);
}
static bool sdma_v4_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 i;
for (i = 0; i < adev->sdma.num_instances; i++) {
u32 tmp = RREG32(sdma_v4_0_get_reg_offset(i, mmSDMA0_STATUS_REG));
if (!(tmp & SDMA0_STATUS_REG__IDLE_MASK))
return false;
}
return true;
}
static int sdma_v4_0_wait_for_idle(void *handle)
{
unsigned i;
u32 sdma0, sdma1;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
sdma0 = RREG32(sdma_v4_0_get_reg_offset(0, mmSDMA0_STATUS_REG));
sdma1 = RREG32(sdma_v4_0_get_reg_offset(1, mmSDMA0_STATUS_REG));
if (sdma0 & sdma1 & SDMA0_STATUS_REG__IDLE_MASK)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int sdma_v4_0_soft_reset(void *handle)
{
return 0;
}
static int sdma_v4_0_set_trap_irq_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 sdma_cntl;
u32 reg_offset = (type == AMDGPU_SDMA_IRQ_TRAP0) ?
sdma_v4_0_get_reg_offset(0, mmSDMA0_CNTL) :
sdma_v4_0_get_reg_offset(1, mmSDMA0_CNTL);
sdma_cntl = RREG32(reg_offset);
sdma_cntl = REG_SET_FIELD(sdma_cntl, SDMA0_CNTL, TRAP_ENABLE,
state == AMDGPU_IRQ_STATE_ENABLE ? 1 : 0);
WREG32(reg_offset, sdma_cntl);
return 0;
}
static int sdma_v4_0_process_trap_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_DEBUG("IH: SDMA trap\n");
switch (entry->client_id) {
case AMDGPU_IH_CLIENTID_SDMA0:
switch (entry->ring_id) {
case 0:
amdgpu_fence_process(&adev->sdma.instance[0].ring);
break;
case 1:
break;
case 2:
break;
case 3:
break;
}
break;
case AMDGPU_IH_CLIENTID_SDMA1:
switch (entry->ring_id) {
case 0:
amdgpu_fence_process(&adev->sdma.instance[1].ring);
break;
case 1:
break;
case 2:
break;
case 3:
break;
}
break;
}
return 0;
}
static int sdma_v4_0_process_illegal_inst_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal instruction in SDMA command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static void sdma_v4_0_update_medium_grain_clock_gating(
struct amdgpu_device *adev,
bool enable)
{
uint32_t data, def;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_SDMA_MGCG)) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CLK_CTRL));
data &= ~(SDMA0_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE0_MASK);
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CLK_CTRL), data);
if (adev->asic_type == CHIP_VEGA10) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_CLK_CTRL));
data &= ~(SDMA1_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE0_MASK);
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_CLK_CTRL), data);
}
} else {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CLK_CTRL));
data |= (SDMA0_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE0_MASK);
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CLK_CTRL), data);
if (adev->asic_type == CHIP_VEGA10) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_CLK_CTRL));
data |= (SDMA1_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA1_CLK_CTRL__SOFT_OVERRIDE0_MASK);
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_CLK_CTRL), data);
}
}
}
static void sdma_v4_0_update_medium_grain_light_sleep(
struct amdgpu_device *adev,
bool enable)
{
uint32_t data, def;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_SDMA_LS)) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL));
data |= SDMA0_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL), data);
if (adev->asic_type == CHIP_VEGA10) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_POWER_CNTL));
data |= SDMA1_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_POWER_CNTL), data);
}
} else {
def = data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL));
data &= ~SDMA0_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL), data);
if (adev->asic_type == CHIP_VEGA10) {
def = data = RREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_POWER_CNTL));
data &= ~SDMA1_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(SDMA1, 0, mmSDMA1_POWER_CNTL), data);
}
}
}
static int sdma_v4_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
return 0;
switch (adev->asic_type) {
case CHIP_VEGA10:
case CHIP_RAVEN:
sdma_v4_0_update_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
sdma_v4_0_update_medium_grain_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
default:
break;
}
return 0;
}
static int sdma_v4_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
switch (adev->asic_type) {
case CHIP_RAVEN:
sdma_v4_1_update_power_gating(adev,
state == AMD_PG_STATE_GATE ? true : false);
break;
default:
break;
}
return 0;
}
static void sdma_v4_0_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int data;
if (amdgpu_sriov_vf(adev))
*flags = 0;
data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_CLK_CTRL));
if (!(data & SDMA0_CLK_CTRL__SOFT_OVERRIDE7_MASK))
*flags |= AMD_CG_SUPPORT_SDMA_MGCG;
data = RREG32(SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_POWER_CNTL));
if (data & SDMA0_POWER_CNTL__MEM_POWER_OVERRIDE_MASK)
*flags |= AMD_CG_SUPPORT_SDMA_LS;
}
static void sdma_v4_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->sdma.num_instances; i++)
adev->sdma.instance[i].ring.funcs = &sdma_v4_0_ring_funcs;
}
static void sdma_v4_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->sdma.trap_irq.num_types = AMDGPU_SDMA_IRQ_LAST;
adev->sdma.trap_irq.funcs = &sdma_v4_0_trap_irq_funcs;
adev->sdma.illegal_inst_irq.funcs = &sdma_v4_0_illegal_inst_irq_funcs;
}
static void sdma_v4_0_emit_copy_buffer(struct amdgpu_ib *ib,
uint64_t src_offset,
uint64_t dst_offset,
uint32_t byte_count)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_COPY) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_COPY_LINEAR);
ib->ptr[ib->length_dw++] = byte_count - 1;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(src_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(src_offset);
ib->ptr[ib->length_dw++] = lower_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(dst_offset);
}
static void sdma_v4_0_emit_fill_buffer(struct amdgpu_ib *ib,
uint32_t src_data,
uint64_t dst_offset,
uint32_t byte_count)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_CONST_FILL);
ib->ptr[ib->length_dw++] = lower_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = src_data;
ib->ptr[ib->length_dw++] = byte_count - 1;
}
static void sdma_v4_0_set_buffer_funcs(struct amdgpu_device *adev)
{
if (adev->mman.buffer_funcs == NULL) {
adev->mman.buffer_funcs = &sdma_v4_0_buffer_funcs;
adev->mman.buffer_funcs_ring = &adev->sdma.instance[0].ring;
}
}
static void sdma_v4_0_set_vm_pte_funcs(struct amdgpu_device *adev)
{
unsigned i;
if (adev->vm_manager.vm_pte_funcs == NULL) {
adev->vm_manager.vm_pte_funcs = &sdma_v4_0_vm_pte_funcs;
for (i = 0; i < adev->sdma.num_instances; i++)
adev->vm_manager.vm_pte_rings[i] =
&adev->sdma.instance[i].ring;
adev->vm_manager.vm_pte_num_rings = adev->sdma.num_instances;
}
}
