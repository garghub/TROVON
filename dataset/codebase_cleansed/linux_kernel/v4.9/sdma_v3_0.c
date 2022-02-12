static void sdma_v3_0_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_FIJI:
amdgpu_program_register_sequence(adev,
fiji_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(fiji_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
golden_settings_fiji_a10,
(const u32)ARRAY_SIZE(golden_settings_fiji_a10));
break;
case CHIP_TONGA:
amdgpu_program_register_sequence(adev,
tonga_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(tonga_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
golden_settings_tonga_a11,
(const u32)ARRAY_SIZE(golden_settings_tonga_a11));
break;
case CHIP_POLARIS11:
amdgpu_program_register_sequence(adev,
golden_settings_polaris11_a11,
(const u32)ARRAY_SIZE(golden_settings_polaris11_a11));
break;
case CHIP_POLARIS10:
amdgpu_program_register_sequence(adev,
golden_settings_polaris10_a11,
(const u32)ARRAY_SIZE(golden_settings_polaris10_a11));
break;
case CHIP_CARRIZO:
amdgpu_program_register_sequence(adev,
cz_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(cz_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
cz_golden_settings_a11,
(const u32)ARRAY_SIZE(cz_golden_settings_a11));
break;
case CHIP_STONEY:
amdgpu_program_register_sequence(adev,
stoney_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(stoney_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
stoney_golden_settings_a11,
(const u32)ARRAY_SIZE(stoney_golden_settings_a11));
break;
default:
break;
}
}
static void sdma_v3_0_free_microcode(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->sdma.num_instances; i++) {
release_firmware(adev->sdma.instance[i].fw);
adev->sdma.instance[i].fw = NULL;
}
}
static int sdma_v3_0_init_microcode(struct amdgpu_device *adev)
{
const char *chip_name;
char fw_name[30];
int err = 0, i;
struct amdgpu_firmware_info *info = NULL;
const struct common_firmware_header *header = NULL;
const struct sdma_firmware_header_v1_0 *hdr;
DRM_DEBUG("\n");
switch (adev->asic_type) {
case CHIP_TONGA:
chip_name = "tonga";
break;
case CHIP_FIJI:
chip_name = "fiji";
break;
case CHIP_POLARIS11:
chip_name = "polaris11";
break;
case CHIP_POLARIS10:
chip_name = "polaris10";
break;
case CHIP_CARRIZO:
chip_name = "carrizo";
break;
case CHIP_STONEY:
chip_name = "stoney";
break;
default: BUG();
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
if (adev->firmware.smu_load) {
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
printk(KERN_ERR
"sdma_v3_0: Failed to load firmware \"%s\"\n",
fw_name);
for (i = 0; i < adev->sdma.num_instances; i++) {
release_firmware(adev->sdma.instance[i].fw);
adev->sdma.instance[i].fw = NULL;
}
}
return err;
}
static uint32_t sdma_v3_0_ring_get_rptr(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs] >> 2;
}
static uint32_t sdma_v3_0_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u32 wptr;
if (ring->use_doorbell) {
wptr = ring->adev->wb.wb[ring->wptr_offs] >> 2;
} else {
int me = (ring == &ring->adev->sdma.instance[0].ring) ? 0 : 1;
wptr = RREG32(mmSDMA0_GFX_RB_WPTR + sdma_offsets[me]) >> 2;
}
return wptr;
}
static void sdma_v3_0_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring->use_doorbell) {
adev->wb.wb[ring->wptr_offs] = ring->wptr << 2;
WDOORBELL32(ring->doorbell_index, ring->wptr << 2);
} else {
int me = (ring == &ring->adev->sdma.instance[0].ring) ? 0 : 1;
WREG32(mmSDMA0_GFX_RB_WPTR + sdma_offsets[me], ring->wptr << 2);
}
}
static void sdma_v3_0_ring_insert_nop(struct amdgpu_ring *ring, uint32_t count)
{
struct amdgpu_sdma_instance *sdma = amdgpu_get_sdma_instance(ring);
int i;
for (i = 0; i < count; i++)
if (sdma && sdma->burst_nop && (i == 0))
amdgpu_ring_write(ring, ring->nop |
SDMA_PKT_NOP_HEADER_COUNT(count - 1));
else
amdgpu_ring_write(ring, ring->nop);
}
static void sdma_v3_0_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 vmid = vm_id & 0xf;
sdma_v3_0_ring_insert_nop(ring, (10 - (ring->wptr & 7)) % 8);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_INDIRECT) |
SDMA_PKT_INDIRECT_HEADER_VMID(vmid));
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr) & 0xffffffe0);
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, ib->length_dw);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
}
static void sdma_v3_0_ring_emit_hdp_flush(struct amdgpu_ring *ring)
{
u32 ref_and_mask = 0;
if (ring == &ring->adev->sdma.instance[0].ring)
ref_and_mask = REG_SET_FIELD(ref_and_mask, GPU_HDP_FLUSH_DONE, SDMA0, 1);
else
ref_and_mask = REG_SET_FIELD(ref_and_mask, GPU_HDP_FLUSH_DONE, SDMA1, 1);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_POLL_REGMEM) |
SDMA_PKT_POLL_REGMEM_HEADER_HDP_FLUSH(1) |
SDMA_PKT_POLL_REGMEM_HEADER_FUNC(3));
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_DONE << 2);
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_REQ << 2);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, SDMA_PKT_POLL_REGMEM_DW5_RETRY_COUNT(0xfff) |
SDMA_PKT_POLL_REGMEM_DW5_INTERVAL(10));
}
static void sdma_v3_0_ring_emit_hdp_invalidate(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, mmHDP_DEBUG0);
amdgpu_ring_write(ring, 1);
}
static void sdma_v3_0_ring_emit_fence(struct amdgpu_ring *ring, u64 addr, u64 seq,
unsigned flags)
{
bool write64bit = flags & AMDGPU_FENCE_FLAG_64BIT;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_FENCE));
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, lower_32_bits(seq));
if (write64bit) {
addr += 4;
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_FENCE));
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(seq));
}
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_TRAP));
amdgpu_ring_write(ring, SDMA_PKT_TRAP_INT_CONTEXT_INT_CONTEXT(0));
}
static void sdma_v3_0_gfx_stop(struct amdgpu_device *adev)
{
struct amdgpu_ring *sdma0 = &adev->sdma.instance[0].ring;
struct amdgpu_ring *sdma1 = &adev->sdma.instance[1].ring;
u32 rb_cntl, ib_cntl;
int i;
if ((adev->mman.buffer_funcs_ring == sdma0) ||
(adev->mman.buffer_funcs_ring == sdma1))
amdgpu_ttm_set_active_vram_size(adev, adev->mc.visible_vram_size);
for (i = 0; i < adev->sdma.num_instances; i++) {
rb_cntl = RREG32(mmSDMA0_GFX_RB_CNTL + sdma_offsets[i]);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_ENABLE, 0);
WREG32(mmSDMA0_GFX_RB_CNTL + sdma_offsets[i], rb_cntl);
ib_cntl = RREG32(mmSDMA0_GFX_IB_CNTL + sdma_offsets[i]);
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_ENABLE, 0);
WREG32(mmSDMA0_GFX_IB_CNTL + sdma_offsets[i], ib_cntl);
}
sdma0->ready = false;
sdma1->ready = false;
}
static void sdma_v3_0_rlc_stop(struct amdgpu_device *adev)
{
}
static void sdma_v3_0_ctx_switch_enable(struct amdgpu_device *adev, bool enable)
{
u32 f32_cntl;
int i;
for (i = 0; i < adev->sdma.num_instances; i++) {
f32_cntl = RREG32(mmSDMA0_CNTL + sdma_offsets[i]);
if (enable)
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_CNTL,
AUTO_CTXSW_ENABLE, 1);
else
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_CNTL,
AUTO_CTXSW_ENABLE, 0);
WREG32(mmSDMA0_CNTL + sdma_offsets[i], f32_cntl);
}
}
static void sdma_v3_0_enable(struct amdgpu_device *adev, bool enable)
{
u32 f32_cntl;
int i;
if (!enable) {
sdma_v3_0_gfx_stop(adev);
sdma_v3_0_rlc_stop(adev);
}
for (i = 0; i < adev->sdma.num_instances; i++) {
f32_cntl = RREG32(mmSDMA0_F32_CNTL + sdma_offsets[i]);
if (enable)
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_F32_CNTL, HALT, 0);
else
f32_cntl = REG_SET_FIELD(f32_cntl, SDMA0_F32_CNTL, HALT, 1);
WREG32(mmSDMA0_F32_CNTL + sdma_offsets[i], f32_cntl);
}
}
static int sdma_v3_0_gfx_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
u32 rb_cntl, ib_cntl;
u32 rb_bufsz;
u32 wb_offset;
u32 doorbell;
int i, j, r;
for (i = 0; i < adev->sdma.num_instances; i++) {
ring = &adev->sdma.instance[i].ring;
wb_offset = (ring->rptr_offs * 4);
mutex_lock(&adev->srbm_mutex);
for (j = 0; j < 16; j++) {
vi_srbm_select(adev, 0, 0, 0, j);
WREG32(mmSDMA0_GFX_VIRTUAL_ADDR + sdma_offsets[i], 0);
WREG32(mmSDMA0_GFX_APE1_CNTL + sdma_offsets[i], 0);
}
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
WREG32(mmSDMA0_TILING_CONFIG + sdma_offsets[i],
adev->gfx.config.gb_addr_config & 0x70);
WREG32(mmSDMA0_SEM_WAIT_FAIL_TIMER_CNTL + sdma_offsets[i], 0);
rb_bufsz = order_base_2(ring->ring_size / 4);
rb_cntl = RREG32(mmSDMA0_GFX_RB_CNTL + sdma_offsets[i]);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_SIZE, rb_bufsz);
#ifdef __BIG_ENDIAN
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_SWAP_ENABLE, 1);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL,
RPTR_WRITEBACK_SWAP_ENABLE, 1);
#endif
WREG32(mmSDMA0_GFX_RB_CNTL + sdma_offsets[i], rb_cntl);
WREG32(mmSDMA0_GFX_RB_RPTR + sdma_offsets[i], 0);
WREG32(mmSDMA0_GFX_RB_WPTR + sdma_offsets[i], 0);
WREG32(mmSDMA0_GFX_IB_RPTR + sdma_offsets[i], 0);
WREG32(mmSDMA0_GFX_IB_OFFSET + sdma_offsets[i], 0);
WREG32(mmSDMA0_GFX_RB_RPTR_ADDR_HI + sdma_offsets[i],
upper_32_bits(adev->wb.gpu_addr + wb_offset) & 0xFFFFFFFF);
WREG32(mmSDMA0_GFX_RB_RPTR_ADDR_LO + sdma_offsets[i],
lower_32_bits(adev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RPTR_WRITEBACK_ENABLE, 1);
WREG32(mmSDMA0_GFX_RB_BASE + sdma_offsets[i], ring->gpu_addr >> 8);
WREG32(mmSDMA0_GFX_RB_BASE_HI + sdma_offsets[i], ring->gpu_addr >> 40);
ring->wptr = 0;
WREG32(mmSDMA0_GFX_RB_WPTR + sdma_offsets[i], ring->wptr << 2);
doorbell = RREG32(mmSDMA0_GFX_DOORBELL + sdma_offsets[i]);
if (ring->use_doorbell) {
doorbell = REG_SET_FIELD(doorbell, SDMA0_GFX_DOORBELL,
OFFSET, ring->doorbell_index);
doorbell = REG_SET_FIELD(doorbell, SDMA0_GFX_DOORBELL, ENABLE, 1);
} else {
doorbell = REG_SET_FIELD(doorbell, SDMA0_GFX_DOORBELL, ENABLE, 0);
}
WREG32(mmSDMA0_GFX_DOORBELL + sdma_offsets[i], doorbell);
rb_cntl = REG_SET_FIELD(rb_cntl, SDMA0_GFX_RB_CNTL, RB_ENABLE, 1);
WREG32(mmSDMA0_GFX_RB_CNTL + sdma_offsets[i], rb_cntl);
ib_cntl = RREG32(mmSDMA0_GFX_IB_CNTL + sdma_offsets[i]);
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_ENABLE, 1);
#ifdef __BIG_ENDIAN
ib_cntl = REG_SET_FIELD(ib_cntl, SDMA0_GFX_IB_CNTL, IB_SWAP_ENABLE, 1);
#endif
WREG32(mmSDMA0_GFX_IB_CNTL + sdma_offsets[i], ib_cntl);
ring->ready = true;
}
sdma_v3_0_enable(adev, true);
sdma_v3_0_ctx_switch_enable(adev, true);
for (i = 0; i < adev->sdma.num_instances; i++) {
ring = &adev->sdma.instance[i].ring;
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
static int sdma_v3_0_rlc_resume(struct amdgpu_device *adev)
{
return 0;
}
static int sdma_v3_0_load_microcode(struct amdgpu_device *adev)
{
const struct sdma_firmware_header_v1_0 *hdr;
const __le32 *fw_data;
u32 fw_size;
int i, j;
sdma_v3_0_enable(adev, false);
for (i = 0; i < adev->sdma.num_instances; i++) {
if (!adev->sdma.instance[i].fw)
return -EINVAL;
hdr = (const struct sdma_firmware_header_v1_0 *)adev->sdma.instance[i].fw->data;
amdgpu_ucode_print_sdma_hdr(&hdr->header);
fw_size = le32_to_cpu(hdr->header.ucode_size_bytes) / 4;
fw_data = (const __le32 *)
(adev->sdma.instance[i].fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
WREG32(mmSDMA0_UCODE_ADDR + sdma_offsets[i], 0);
for (j = 0; j < fw_size; j++)
WREG32(mmSDMA0_UCODE_DATA + sdma_offsets[i], le32_to_cpup(fw_data++));
WREG32(mmSDMA0_UCODE_ADDR + sdma_offsets[i], adev->sdma.instance[i].fw_version);
}
return 0;
}
static int sdma_v3_0_start(struct amdgpu_device *adev)
{
int r, i;
if (!adev->pp_enabled) {
if (!adev->firmware.smu_load) {
r = sdma_v3_0_load_microcode(adev);
if (r)
return r;
} else {
for (i = 0; i < adev->sdma.num_instances; i++) {
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
(i == 0) ?
AMDGPU_UCODE_ID_SDMA0 :
AMDGPU_UCODE_ID_SDMA1);
if (r)
return -EINVAL;
}
}
}
sdma_v3_0_ctx_switch_enable(adev, false);
sdma_v3_0_enable(adev, false);
r = sdma_v3_0_gfx_resume(adev);
if (r)
return r;
r = sdma_v3_0_rlc_resume(adev);
if (r)
return r;
return 0;
}
static int sdma_v3_0_ring_test_ring(struct amdgpu_ring *ring)
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
amdgpu_ring_write(ring, SDMA_PKT_WRITE_UNTILED_DW_3_COUNT(1));
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
static int sdma_v3_0_ring_test_ib(struct amdgpu_ring *ring, long timeout)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib ib;
struct fence *f = NULL;
unsigned index;
u32 tmp = 0;
u64 gpu_addr;
long r;
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
ib.ptr[3] = SDMA_PKT_WRITE_UNTILED_DW_3_COUNT(1);
ib.ptr[4] = 0xDEADBEEF;
ib.ptr[5] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.ptr[6] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.ptr[7] = SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP);
ib.length_dw = 8;
r = amdgpu_ib_schedule(ring, 1, &ib, NULL, NULL, &f);
if (r)
goto err1;
r = fence_wait_timeout(f, false, timeout);
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
fence_put(f);
err0:
amdgpu_wb_free(adev, index);
return r;
}
static void sdma_v3_0_vm_copy_pte(struct amdgpu_ib *ib,
uint64_t pe, uint64_t src,
unsigned count)
{
unsigned bytes = count * 8;
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_COPY) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_COPY_LINEAR);
ib->ptr[ib->length_dw++] = bytes;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(src);
ib->ptr[ib->length_dw++] = upper_32_bits(src);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
}
static void sdma_v3_0_vm_write_pte(struct amdgpu_ib *ib, uint64_t pe,
uint64_t value, unsigned count,
uint32_t incr)
{
unsigned ndw = count * 2;
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_WRITE) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_COPY_LINEAR);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = ndw;
for (; ndw > 0; ndw -= 2, --count, pe += 8) {
ib->ptr[ib->length_dw++] = lower_32_bits(value);
ib->ptr[ib->length_dw++] = upper_32_bits(value);
value += incr;
}
}
static void sdma_v3_0_vm_set_pte_pde(struct amdgpu_ib *ib, uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_GEN_PTEPDE);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = flags;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(addr);
ib->ptr[ib->length_dw++] = upper_32_bits(addr);
ib->ptr[ib->length_dw++] = incr;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = count;
}
static void sdma_v3_0_ring_pad_ib(struct amdgpu_ring *ring, struct amdgpu_ib *ib)
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
static void sdma_v3_0_ring_emit_pipeline_sync(struct amdgpu_ring *ring)
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
static void sdma_v3_0_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr)
{
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
if (vm_id < 8) {
amdgpu_ring_write(ring, (mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR + vm_id));
} else {
amdgpu_ring_write(ring, (mmVM_CONTEXT8_PAGE_TABLE_BASE_ADDR + vm_id - 8));
}
amdgpu_ring_write(ring, pd_addr >> 12);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_SRBM_WRITE) |
SDMA_PKT_SRBM_WRITE_HEADER_BYTE_EN(0xf));
amdgpu_ring_write(ring, mmVM_INVALIDATE_REQUEST);
amdgpu_ring_write(ring, 1 << vm_id);
amdgpu_ring_write(ring, SDMA_PKT_HEADER_OP(SDMA_OP_POLL_REGMEM) |
SDMA_PKT_POLL_REGMEM_HEADER_HDP_FLUSH(0) |
SDMA_PKT_POLL_REGMEM_HEADER_FUNC(0));
amdgpu_ring_write(ring, mmVM_INVALIDATE_REQUEST << 2);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, SDMA_PKT_POLL_REGMEM_DW5_RETRY_COUNT(0xfff) |
SDMA_PKT_POLL_REGMEM_DW5_INTERVAL(10));
}
static unsigned sdma_v3_0_ring_get_emit_ib_size(struct amdgpu_ring *ring)
{
return
7 + 6;
}
static unsigned sdma_v3_0_ring_get_dma_frame_size(struct amdgpu_ring *ring)
{
return
6 +
3 +
6 +
12 +
10 + 10 + 10;
}
static int sdma_v3_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
switch (adev->asic_type) {
case CHIP_STONEY:
adev->sdma.num_instances = 1;
break;
default:
adev->sdma.num_instances = SDMA_MAX_INSTANCE;
break;
}
sdma_v3_0_set_ring_funcs(adev);
sdma_v3_0_set_buffer_funcs(adev);
sdma_v3_0_set_vm_pte_funcs(adev);
sdma_v3_0_set_irq_funcs(adev);
return 0;
}
static int sdma_v3_0_sw_init(void *handle)
{
struct amdgpu_ring *ring;
int r, i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, 224, &adev->sdma.trap_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 241, &adev->sdma.illegal_inst_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 247, &adev->sdma.illegal_inst_irq);
if (r)
return r;
r = sdma_v3_0_init_microcode(adev);
if (r) {
DRM_ERROR("Failed to load sdma firmware!\n");
return r;
}
for (i = 0; i < adev->sdma.num_instances; i++) {
ring = &adev->sdma.instance[i].ring;
ring->ring_obj = NULL;
ring->use_doorbell = true;
ring->doorbell_index = (i == 0) ?
AMDGPU_DOORBELL_sDMA_ENGINE0 : AMDGPU_DOORBELL_sDMA_ENGINE1;
sprintf(ring->name, "sdma%d", i);
r = amdgpu_ring_init(adev, ring, 1024,
SDMA_PKT_NOP_HEADER_OP(SDMA_OP_NOP), 0xf,
&adev->sdma.trap_irq,
(i == 0) ?
AMDGPU_SDMA_IRQ_TRAP0 : AMDGPU_SDMA_IRQ_TRAP1,
AMDGPU_RING_TYPE_SDMA);
if (r)
return r;
}
return r;
}
static int sdma_v3_0_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int i;
for (i = 0; i < adev->sdma.num_instances; i++)
amdgpu_ring_fini(&adev->sdma.instance[i].ring);
sdma_v3_0_free_microcode(adev);
return 0;
}
static int sdma_v3_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
sdma_v3_0_init_golden_registers(adev);
r = sdma_v3_0_start(adev);
if (r)
return r;
return r;
}
static int sdma_v3_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
sdma_v3_0_ctx_switch_enable(adev, false);
sdma_v3_0_enable(adev, false);
return 0;
}
static int sdma_v3_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return sdma_v3_0_hw_fini(adev);
}
static int sdma_v3_0_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return sdma_v3_0_hw_init(adev);
}
static bool sdma_v3_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 tmp = RREG32(mmSRBM_STATUS2);
if (tmp & (SRBM_STATUS2__SDMA_BUSY_MASK |
SRBM_STATUS2__SDMA1_BUSY_MASK))
return false;
return true;
}
static int sdma_v3_0_wait_for_idle(void *handle)
{
unsigned i;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(mmSRBM_STATUS2) & (SRBM_STATUS2__SDMA_BUSY_MASK |
SRBM_STATUS2__SDMA1_BUSY_MASK);
if (!tmp)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static bool sdma_v3_0_check_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset = 0;
u32 tmp = RREG32(mmSRBM_STATUS2);
if ((tmp & SRBM_STATUS2__SDMA_BUSY_MASK) ||
(tmp & SRBM_STATUS2__SDMA1_BUSY_MASK)) {
srbm_soft_reset |= SRBM_SOFT_RESET__SOFT_RESET_SDMA_MASK;
srbm_soft_reset |= SRBM_SOFT_RESET__SOFT_RESET_SDMA1_MASK;
}
if (srbm_soft_reset) {
adev->sdma.srbm_soft_reset = srbm_soft_reset;
return true;
} else {
adev->sdma.srbm_soft_reset = 0;
return false;
}
}
static int sdma_v3_0_pre_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset = 0;
if (!adev->sdma.srbm_soft_reset)
return 0;
srbm_soft_reset = adev->sdma.srbm_soft_reset;
if (REG_GET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA) ||
REG_GET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA1)) {
sdma_v3_0_ctx_switch_enable(adev, false);
sdma_v3_0_enable(adev, false);
}
return 0;
}
static int sdma_v3_0_post_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset = 0;
if (!adev->sdma.srbm_soft_reset)
return 0;
srbm_soft_reset = adev->sdma.srbm_soft_reset;
if (REG_GET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA) ||
REG_GET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA1)) {
sdma_v3_0_gfx_resume(adev);
sdma_v3_0_rlc_resume(adev);
}
return 0;
}
static int sdma_v3_0_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset = 0;
u32 tmp;
if (!adev->sdma.srbm_soft_reset)
return 0;
srbm_soft_reset = adev->sdma.srbm_soft_reset;
if (srbm_soft_reset) {
tmp = RREG32(mmSRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(adev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
}
return 0;
}
static int sdma_v3_0_set_trap_irq_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 sdma_cntl;
switch (type) {
case AMDGPU_SDMA_IRQ_TRAP0:
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
sdma_cntl = RREG32(mmSDMA0_CNTL + SDMA0_REGISTER_OFFSET);
sdma_cntl = REG_SET_FIELD(sdma_cntl, SDMA0_CNTL, TRAP_ENABLE, 0);
WREG32(mmSDMA0_CNTL + SDMA0_REGISTER_OFFSET, sdma_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
sdma_cntl = RREG32(mmSDMA0_CNTL + SDMA0_REGISTER_OFFSET);
sdma_cntl = REG_SET_FIELD(sdma_cntl, SDMA0_CNTL, TRAP_ENABLE, 1);
WREG32(mmSDMA0_CNTL + SDMA0_REGISTER_OFFSET, sdma_cntl);
break;
default:
break;
}
break;
case AMDGPU_SDMA_IRQ_TRAP1:
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
sdma_cntl = RREG32(mmSDMA0_CNTL + SDMA1_REGISTER_OFFSET);
sdma_cntl = REG_SET_FIELD(sdma_cntl, SDMA0_CNTL, TRAP_ENABLE, 0);
WREG32(mmSDMA0_CNTL + SDMA1_REGISTER_OFFSET, sdma_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
sdma_cntl = RREG32(mmSDMA0_CNTL + SDMA1_REGISTER_OFFSET);
sdma_cntl = REG_SET_FIELD(sdma_cntl, SDMA0_CNTL, TRAP_ENABLE, 1);
WREG32(mmSDMA0_CNTL + SDMA1_REGISTER_OFFSET, sdma_cntl);
break;
default:
break;
}
break;
default:
break;
}
return 0;
}
static int sdma_v3_0_process_trap_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
u8 instance_id, queue_id;
instance_id = (entry->ring_id & 0x3) >> 0;
queue_id = (entry->ring_id & 0xc) >> 2;
DRM_DEBUG("IH: SDMA trap\n");
switch (instance_id) {
case 0:
switch (queue_id) {
case 0:
amdgpu_fence_process(&adev->sdma.instance[0].ring);
break;
case 1:
break;
case 2:
break;
}
break;
case 1:
switch (queue_id) {
case 0:
amdgpu_fence_process(&adev->sdma.instance[1].ring);
break;
case 1:
break;
case 2:
break;
}
break;
}
return 0;
}
static int sdma_v3_0_process_illegal_inst_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal instruction in SDMA command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static void sdma_v3_0_update_sdma_medium_grain_clock_gating(
struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
int i;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_SDMA_MGCG)) {
for (i = 0; i < adev->sdma.num_instances; i++) {
temp = data = RREG32(mmSDMA0_CLK_CTRL + sdma_offsets[i]);
data &= ~(SDMA0_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE0_MASK);
if (data != temp)
WREG32(mmSDMA0_CLK_CTRL + sdma_offsets[i], data);
}
} else {
for (i = 0; i < adev->sdma.num_instances; i++) {
temp = data = RREG32(mmSDMA0_CLK_CTRL + sdma_offsets[i]);
data |= SDMA0_CLK_CTRL__SOFT_OVERRIDE7_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE6_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE5_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE4_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE3_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE2_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE1_MASK |
SDMA0_CLK_CTRL__SOFT_OVERRIDE0_MASK;
if (data != temp)
WREG32(mmSDMA0_CLK_CTRL + sdma_offsets[i], data);
}
}
}
static void sdma_v3_0_update_sdma_medium_grain_light_sleep(
struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
int i;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_SDMA_LS)) {
for (i = 0; i < adev->sdma.num_instances; i++) {
temp = data = RREG32(mmSDMA0_POWER_CNTL + sdma_offsets[i]);
data |= SDMA0_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (temp != data)
WREG32(mmSDMA0_POWER_CNTL + sdma_offsets[i], data);
}
} else {
for (i = 0; i < adev->sdma.num_instances; i++) {
temp = data = RREG32(mmSDMA0_POWER_CNTL + sdma_offsets[i]);
data &= ~SDMA0_POWER_CNTL__MEM_POWER_OVERRIDE_MASK;
if (temp != data)
WREG32(mmSDMA0_POWER_CNTL + sdma_offsets[i], data);
}
}
}
static int sdma_v3_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
switch (adev->asic_type) {
case CHIP_FIJI:
case CHIP_CARRIZO:
case CHIP_STONEY:
sdma_v3_0_update_sdma_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
sdma_v3_0_update_sdma_medium_grain_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
default:
break;
}
return 0;
}
static int sdma_v3_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void sdma_v3_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->sdma.num_instances; i++)
adev->sdma.instance[i].ring.funcs = &sdma_v3_0_ring_funcs;
}
static void sdma_v3_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->sdma.trap_irq.num_types = AMDGPU_SDMA_IRQ_LAST;
adev->sdma.trap_irq.funcs = &sdma_v3_0_trap_irq_funcs;
adev->sdma.illegal_inst_irq.funcs = &sdma_v3_0_illegal_inst_irq_funcs;
}
static void sdma_v3_0_emit_copy_buffer(struct amdgpu_ib *ib,
uint64_t src_offset,
uint64_t dst_offset,
uint32_t byte_count)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_COPY) |
SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_COPY_LINEAR);
ib->ptr[ib->length_dw++] = byte_count;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(src_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(src_offset);
ib->ptr[ib->length_dw++] = lower_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(dst_offset);
}
static void sdma_v3_0_emit_fill_buffer(struct amdgpu_ib *ib,
uint32_t src_data,
uint64_t dst_offset,
uint32_t byte_count)
{
ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_CONST_FILL);
ib->ptr[ib->length_dw++] = lower_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = upper_32_bits(dst_offset);
ib->ptr[ib->length_dw++] = src_data;
ib->ptr[ib->length_dw++] = byte_count;
}
static void sdma_v3_0_set_buffer_funcs(struct amdgpu_device *adev)
{
if (adev->mman.buffer_funcs == NULL) {
adev->mman.buffer_funcs = &sdma_v3_0_buffer_funcs;
adev->mman.buffer_funcs_ring = &adev->sdma.instance[0].ring;
}
}
static void sdma_v3_0_set_vm_pte_funcs(struct amdgpu_device *adev)
{
unsigned i;
if (adev->vm_manager.vm_pte_funcs == NULL) {
adev->vm_manager.vm_pte_funcs = &sdma_v3_0_vm_pte_funcs;
for (i = 0; i < adev->sdma.num_instances; i++)
adev->vm_manager.vm_pte_rings[i] =
&adev->sdma.instance[i].ring;
adev->vm_manager.vm_pte_num_rings = adev->sdma.num_instances;
}
}
