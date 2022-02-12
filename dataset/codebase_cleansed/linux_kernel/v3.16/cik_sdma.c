uint32_t cik_sdma_get_rptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 rptr, reg;
if (rdev->wb.enabled) {
rptr = rdev->wb.wb[ring->rptr_offs/4];
} else {
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
reg = SDMA0_GFX_RB_RPTR + SDMA0_REGISTER_OFFSET;
else
reg = SDMA0_GFX_RB_RPTR + SDMA1_REGISTER_OFFSET;
rptr = RREG32(reg);
}
return (rptr & 0x3fffc) >> 2;
}
uint32_t cik_sdma_get_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 reg;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
reg = SDMA0_GFX_RB_WPTR + SDMA0_REGISTER_OFFSET;
else
reg = SDMA0_GFX_RB_WPTR + SDMA1_REGISTER_OFFSET;
return (RREG32(reg) & 0x3fffc) >> 2;
}
void cik_sdma_set_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 reg;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
reg = SDMA0_GFX_RB_WPTR + SDMA0_REGISTER_OFFSET;
else
reg = SDMA0_GFX_RB_WPTR + SDMA1_REGISTER_OFFSET;
WREG32(reg, (ring->wptr << 2) & 0x3fffc);
}
void cik_sdma_ring_ib_execute(struct radeon_device *rdev,
struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
u32 extra_bits = (ib->vm ? ib->vm->id : 0) & 0xf;
if (rdev->wb.enabled) {
u32 next_rptr = ring->wptr + 5;
while ((next_rptr & 7) != 4)
next_rptr++;
next_rptr += 4;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr));
radeon_ring_write(ring, 1);
radeon_ring_write(ring, next_rptr);
}
while ((ring->wptr & 7) != 4)
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_INDIRECT_BUFFER, 0, extra_bits));
radeon_ring_write(ring, ib->gpu_addr & 0xffffffe0);
radeon_ring_write(ring, upper_32_bits(ib->gpu_addr));
radeon_ring_write(ring, ib->length_dw);
}
static void cik_sdma_hdp_flush_ring_emit(struct radeon_device *rdev,
int ridx)
{
struct radeon_ring *ring = &rdev->ring[ridx];
u32 extra_bits = (SDMA_POLL_REG_MEM_EXTRA_OP(1) |
SDMA_POLL_REG_MEM_EXTRA_FUNC(3));
u32 ref_and_mask;
if (ridx == R600_RING_TYPE_DMA_INDEX)
ref_and_mask = SDMA0;
else
ref_and_mask = SDMA1;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_POLL_REG_MEM, 0, extra_bits));
radeon_ring_write(ring, GPU_HDP_FLUSH_DONE);
radeon_ring_write(ring, GPU_HDP_FLUSH_REQ);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, (0xfff << 16) | 10);
}
void cik_sdma_fence_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_FENCE, 0, 0));
radeon_ring_write(ring, lower_32_bits(addr));
radeon_ring_write(ring, upper_32_bits(addr));
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_TRAP, 0, 0));
cik_sdma_hdp_flush_ring_emit(rdev, fence->ring);
}
bool cik_sdma_semaphore_ring_emit(struct radeon_device *rdev,
struct radeon_ring *ring,
struct radeon_semaphore *semaphore,
bool emit_wait)
{
u64 addr = semaphore->gpu_addr;
u32 extra_bits = emit_wait ? 0 : SDMA_SEMAPHORE_EXTRA_S;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SEMAPHORE, 0, extra_bits));
radeon_ring_write(ring, addr & 0xfffffff8);
radeon_ring_write(ring, upper_32_bits(addr));
return true;
}
static void cik_sdma_gfx_stop(struct radeon_device *rdev)
{
u32 rb_cntl, reg_offset;
int i;
if ((rdev->asic->copy.copy_ring_index == R600_RING_TYPE_DMA_INDEX) ||
(rdev->asic->copy.copy_ring_index == CAYMAN_RING_TYPE_DMA1_INDEX))
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
for (i = 0; i < 2; i++) {
if (i == 0)
reg_offset = SDMA0_REGISTER_OFFSET;
else
reg_offset = SDMA1_REGISTER_OFFSET;
rb_cntl = RREG32(SDMA0_GFX_RB_CNTL + reg_offset);
rb_cntl &= ~SDMA_RB_ENABLE;
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl);
WREG32(SDMA0_GFX_IB_CNTL + reg_offset, 0);
}
rdev->ring[R600_RING_TYPE_DMA_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX].ready = false;
}
static void cik_sdma_rlc_stop(struct radeon_device *rdev)
{
}
void cik_sdma_enable(struct radeon_device *rdev, bool enable)
{
u32 me_cntl, reg_offset;
int i;
if (enable == false) {
cik_sdma_gfx_stop(rdev);
cik_sdma_rlc_stop(rdev);
}
for (i = 0; i < 2; i++) {
if (i == 0)
reg_offset = SDMA0_REGISTER_OFFSET;
else
reg_offset = SDMA1_REGISTER_OFFSET;
me_cntl = RREG32(SDMA0_ME_CNTL + reg_offset);
if (enable)
me_cntl &= ~SDMA_HALT;
else
me_cntl |= SDMA_HALT;
WREG32(SDMA0_ME_CNTL + reg_offset, me_cntl);
}
}
static int cik_sdma_gfx_resume(struct radeon_device *rdev)
{
struct radeon_ring *ring;
u32 rb_cntl, ib_cntl;
u32 rb_bufsz;
u32 reg_offset, wb_offset;
int i, r;
for (i = 0; i < 2; i++) {
if (i == 0) {
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
reg_offset = SDMA0_REGISTER_OFFSET;
wb_offset = R600_WB_DMA_RPTR_OFFSET;
} else {
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
reg_offset = SDMA1_REGISTER_OFFSET;
wb_offset = CAYMAN_WB_DMA1_RPTR_OFFSET;
}
WREG32(SDMA0_SEM_INCOMPLETE_TIMER_CNTL + reg_offset, 0);
WREG32(SDMA0_SEM_WAIT_FAIL_TIMER_CNTL + reg_offset, 0);
rb_bufsz = order_base_2(ring->ring_size / 4);
rb_cntl = rb_bufsz << 1;
#ifdef __BIG_ENDIAN
rb_cntl |= SDMA_RB_SWAP_ENABLE | SDMA_RPTR_WRITEBACK_SWAP_ENABLE;
#endif
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl);
WREG32(SDMA0_GFX_RB_RPTR + reg_offset, 0);
WREG32(SDMA0_GFX_RB_WPTR + reg_offset, 0);
WREG32(SDMA0_GFX_RB_RPTR_ADDR_HI + reg_offset,
upper_32_bits(rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFF);
WREG32(SDMA0_GFX_RB_RPTR_ADDR_LO + reg_offset,
((rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC));
if (rdev->wb.enabled)
rb_cntl |= SDMA_RPTR_WRITEBACK_ENABLE;
WREG32(SDMA0_GFX_RB_BASE + reg_offset, ring->gpu_addr >> 8);
WREG32(SDMA0_GFX_RB_BASE_HI + reg_offset, ring->gpu_addr >> 40);
ring->wptr = 0;
WREG32(SDMA0_GFX_RB_WPTR + reg_offset, ring->wptr << 2);
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl | SDMA_RB_ENABLE);
ib_cntl = SDMA_IB_ENABLE;
#ifdef __BIG_ENDIAN
ib_cntl |= SDMA_IB_SWAP_ENABLE;
#endif
WREG32(SDMA0_GFX_IB_CNTL + reg_offset, ib_cntl);
ring->ready = true;
r = radeon_ring_test(rdev, ring->idx, ring);
if (r) {
ring->ready = false;
return r;
}
}
if ((rdev->asic->copy.copy_ring_index == R600_RING_TYPE_DMA_INDEX) ||
(rdev->asic->copy.copy_ring_index == CAYMAN_RING_TYPE_DMA1_INDEX))
radeon_ttm_set_active_vram_size(rdev, rdev->mc.real_vram_size);
return 0;
}
static int cik_sdma_rlc_resume(struct radeon_device *rdev)
{
return 0;
}
static int cik_sdma_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->sdma_fw)
return -EINVAL;
cik_sdma_enable(rdev, false);
fw_data = (const __be32 *)rdev->sdma_fw->data;
WREG32(SDMA0_UCODE_ADDR + SDMA0_REGISTER_OFFSET, 0);
for (i = 0; i < CIK_SDMA_UCODE_SIZE; i++)
WREG32(SDMA0_UCODE_DATA + SDMA0_REGISTER_OFFSET, be32_to_cpup(fw_data++));
WREG32(SDMA0_UCODE_DATA + SDMA0_REGISTER_OFFSET, CIK_SDMA_UCODE_VERSION);
fw_data = (const __be32 *)rdev->sdma_fw->data;
WREG32(SDMA0_UCODE_ADDR + SDMA1_REGISTER_OFFSET, 0);
for (i = 0; i < CIK_SDMA_UCODE_SIZE; i++)
WREG32(SDMA0_UCODE_DATA + SDMA1_REGISTER_OFFSET, be32_to_cpup(fw_data++));
WREG32(SDMA0_UCODE_DATA + SDMA1_REGISTER_OFFSET, CIK_SDMA_UCODE_VERSION);
WREG32(SDMA0_UCODE_ADDR + SDMA0_REGISTER_OFFSET, 0);
WREG32(SDMA0_UCODE_ADDR + SDMA1_REGISTER_OFFSET, 0);
return 0;
}
int cik_sdma_resume(struct radeon_device *rdev)
{
int r;
WREG32(SRBM_SOFT_RESET, SOFT_RESET_SDMA | SOFT_RESET_SDMA1);
RREG32(SRBM_SOFT_RESET);
udelay(50);
WREG32(SRBM_SOFT_RESET, 0);
RREG32(SRBM_SOFT_RESET);
r = cik_sdma_load_microcode(rdev);
if (r)
return r;
cik_sdma_enable(rdev, true);
r = cik_sdma_gfx_resume(rdev);
if (r)
return r;
r = cik_sdma_rlc_resume(rdev);
if (r)
return r;
return 0;
}
void cik_sdma_fini(struct radeon_device *rdev)
{
cik_sdma_enable(rdev, false);
radeon_ring_fini(rdev, &rdev->ring[R600_RING_TYPE_DMA_INDEX]);
radeon_ring_fini(rdev, &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX]);
}
int cik_copy_dma(struct radeon_device *rdev,
uint64_t src_offset, uint64_t dst_offset,
unsigned num_gpu_pages,
struct radeon_fence **fence)
{
struct radeon_semaphore *sem = NULL;
int ring_index = rdev->asic->copy.dma_ring_index;
struct radeon_ring *ring = &rdev->ring[ring_index];
u32 size_in_bytes, cur_size_in_bytes;
int i, num_loops;
int r = 0;
r = radeon_semaphore_create(rdev, &sem);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
return r;
}
size_in_bytes = (num_gpu_pages << RADEON_GPU_PAGE_SHIFT);
num_loops = DIV_ROUND_UP(size_in_bytes, 0x1fffff);
r = radeon_ring_lock(rdev, ring, num_loops * 7 + 14);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
radeon_semaphore_sync_to(sem, *fence);
radeon_semaphore_sync_rings(rdev, sem, ring->idx);
for (i = 0; i < num_loops; i++) {
cur_size_in_bytes = size_in_bytes;
if (cur_size_in_bytes > 0x1fffff)
cur_size_in_bytes = 0x1fffff;
size_in_bytes -= cur_size_in_bytes;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_COPY, SDMA_COPY_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, cur_size_in_bytes);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, lower_32_bits(src_offset));
radeon_ring_write(ring, upper_32_bits(src_offset));
radeon_ring_write(ring, lower_32_bits(dst_offset));
radeon_ring_write(ring, upper_32_bits(dst_offset));
src_offset += cur_size_in_bytes;
dst_offset += cur_size_in_bytes;
}
r = radeon_fence_emit(rdev, fence, ring->idx);
if (r) {
radeon_ring_unlock_undo(rdev, ring);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
radeon_ring_unlock_commit(rdev, ring);
radeon_semaphore_free(rdev, &sem, *fence);
return r;
}
int cik_sdma_ring_test(struct radeon_device *rdev,
struct radeon_ring *ring)
{
unsigned i;
int r;
void __iomem *ptr = (void *)rdev->vram_scratch.ptr;
u32 tmp;
if (!ptr) {
DRM_ERROR("invalid vram scratch pointer\n");
return -EINVAL;
}
tmp = 0xCAFEDEAD;
writel(tmp, ptr);
r = radeon_ring_lock(rdev, ring, 5);
if (r) {
DRM_ERROR("radeon: dma failed to lock ring %d (%d).\n", ring->idx, r);
return r;
}
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, rdev->vram_scratch.gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(rdev->vram_scratch.gpu_addr));
radeon_ring_write(ring, 1);
radeon_ring_write(ring, 0xDEADBEEF);
radeon_ring_unlock_commit(rdev, ring);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = readl(ptr);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n", ring->idx, i);
} else {
DRM_ERROR("radeon: ring %d test failed (0x%08X)\n",
ring->idx, tmp);
r = -EINVAL;
}
return r;
}
int cik_sdma_ib_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
struct radeon_ib ib;
unsigned i;
int r;
void __iomem *ptr = (void *)rdev->vram_scratch.ptr;
u32 tmp = 0;
if (!ptr) {
DRM_ERROR("invalid vram scratch pointer\n");
return -EINVAL;
}
tmp = 0xCAFEDEAD;
writel(tmp, ptr);
r = radeon_ib_get(rdev, ring->idx, &ib, NULL, 256);
if (r) {
DRM_ERROR("radeon: failed to get ib (%d).\n", r);
return r;
}
ib.ptr[0] = SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0);
ib.ptr[1] = rdev->vram_scratch.gpu_addr & 0xfffffffc;
ib.ptr[2] = upper_32_bits(rdev->vram_scratch.gpu_addr);
ib.ptr[3] = 1;
ib.ptr[4] = 0xDEADBEEF;
ib.length_dw = 5;
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r) {
radeon_ib_free(rdev, &ib);
DRM_ERROR("radeon: failed to schedule ib (%d).\n", r);
return r;
}
r = radeon_fence_wait(ib.fence, false);
if (r) {
DRM_ERROR("radeon: fence wait failed (%d).\n", r);
return r;
}
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = readl(ptr);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ib test on ring %d succeeded in %u usecs\n", ib.fence->ring, i);
} else {
DRM_ERROR("radeon: ib test failed (0x%08X)\n", tmp);
r = -EINVAL;
}
radeon_ib_free(rdev, &ib);
return r;
}
bool cik_sdma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = cik_gpu_check_soft_reset(rdev);
u32 mask;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
mask = RADEON_RESET_DMA;
else
mask = RADEON_RESET_DMA1;
if (!(reset_mask & mask)) {
radeon_ring_lockup_update(rdev, ring);
return false;
}
return radeon_ring_test_lockup(rdev, ring);
}
void cik_sdma_vm_set_page(struct radeon_device *rdev,
struct radeon_ib *ib,
uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
uint64_t value;
unsigned ndw;
trace_radeon_vm_set_page(pe, addr, count, incr, flags);
if (flags == R600_PTE_GART) {
uint64_t src = rdev->gart.table_addr + (addr >> 12) * 8;
while (count) {
unsigned bytes = count * 8;
if (bytes > 0x1FFFF8)
bytes = 0x1FFFF8;
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_COPY, SDMA_WRITE_SUB_OPCODE_LINEAR, 0);
ib->ptr[ib->length_dw++] = bytes;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = lower_32_bits(src);
ib->ptr[ib->length_dw++] = upper_32_bits(src);
ib->ptr[ib->length_dw++] = lower_32_bits(pe);
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
pe += bytes;
src += bytes;
count -= bytes / 8;
}
} else if (flags & R600_PTE_SYSTEM) {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = ndw;
for (; ndw > 0; ndw -= 2, --count, pe += 8) {
value = radeon_vm_map_gart(rdev, addr);
value &= 0xFFFFFFFFFFFFF000ULL;
addr += incr;
value |= flags;
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
}
}
} else {
while (count) {
ndw = count;
if (ndw > 0x7FFFF)
ndw = 0x7FFFF;
if (flags & R600_PTE_VALID)
value = addr;
else
value = 0;
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_GENERATE_PTE_PDE, 0, 0);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = flags;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
ib->ptr[ib->length_dw++] = incr;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = ndw;
pe += ndw * 8;
addr += ndw * incr;
count -= ndw;
}
}
while (ib->length_dw & 0x7)
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0);
}
void cik_dma_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
if (vm->id < 8) {
radeon_ring_write(ring, (VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2);
} else {
radeon_ring_write(ring, (VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((vm->id - 8) << 2)) >> 2);
}
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, VMID(vm->id));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_BASES >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_CONFIG >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_APE1_BASE >> 2);
radeon_ring_write(ring, 1);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_APE1_LIMIT >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, VMID(0));
cik_sdma_hdp_flush_ring_emit(rdev, ridx);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, VM_INVALIDATE_REQUEST >> 2);
radeon_ring_write(ring, 1 << vm->id);
}
