void cayman_dma_ring_ib_execute(struct radeon_device *rdev,
struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
if (rdev->wb.enabled) {
u32 next_rptr = ring->wptr + 4;
while ((next_rptr & 7) != 5)
next_rptr++;
next_rptr += 3;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_WRITE, 0, 0, 1));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xff);
radeon_ring_write(ring, next_rptr);
}
while ((ring->wptr & 7) != 5)
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0));
radeon_ring_write(ring, DMA_IB_PACKET(DMA_PACKET_INDIRECT_BUFFER, ib->vm ? ib->vm->id : 0, 0));
radeon_ring_write(ring, (ib->gpu_addr & 0xFFFFFFE0));
radeon_ring_write(ring, (ib->length_dw << 12) | (upper_32_bits(ib->gpu_addr) & 0xFF));
}
void cayman_dma_stop(struct radeon_device *rdev)
{
u32 rb_cntl;
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
rb_cntl = RREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET);
rb_cntl &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET, rb_cntl);
rb_cntl = RREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET);
rb_cntl &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET, rb_cntl);
rdev->ring[R600_RING_TYPE_DMA_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX].ready = false;
}
int cayman_dma_resume(struct radeon_device *rdev)
{
struct radeon_ring *ring;
u32 rb_cntl, dma_cntl, ib_cntl;
u32 rb_bufsz;
u32 reg_offset, wb_offset;
int i, r;
WREG32(SRBM_SOFT_RESET, SOFT_RESET_DMA | SOFT_RESET_DMA1);
RREG32(SRBM_SOFT_RESET);
udelay(50);
WREG32(SRBM_SOFT_RESET, 0);
for (i = 0; i < 2; i++) {
if (i == 0) {
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
reg_offset = DMA0_REGISTER_OFFSET;
wb_offset = R600_WB_DMA_RPTR_OFFSET;
} else {
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
reg_offset = DMA1_REGISTER_OFFSET;
wb_offset = CAYMAN_WB_DMA1_RPTR_OFFSET;
}
WREG32(DMA_SEM_INCOMPLETE_TIMER_CNTL + reg_offset, 0);
WREG32(DMA_SEM_WAIT_FAIL_TIMER_CNTL + reg_offset, 0);
rb_bufsz = order_base_2(ring->ring_size / 4);
rb_cntl = rb_bufsz << 1;
#ifdef __BIG_ENDIAN
rb_cntl |= DMA_RB_SWAP_ENABLE | DMA_RPTR_WRITEBACK_SWAP_ENABLE;
#endif
WREG32(DMA_RB_CNTL + reg_offset, rb_cntl);
WREG32(DMA_RB_RPTR + reg_offset, 0);
WREG32(DMA_RB_WPTR + reg_offset, 0);
WREG32(DMA_RB_RPTR_ADDR_HI + reg_offset,
upper_32_bits(rdev->wb.gpu_addr + wb_offset) & 0xFF);
WREG32(DMA_RB_RPTR_ADDR_LO + reg_offset,
((rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC));
if (rdev->wb.enabled)
rb_cntl |= DMA_RPTR_WRITEBACK_ENABLE;
WREG32(DMA_RB_BASE + reg_offset, ring->gpu_addr >> 8);
ib_cntl = DMA_IB_ENABLE | CMD_VMID_FORCE;
#ifdef __BIG_ENDIAN
ib_cntl |= DMA_IB_SWAP_ENABLE;
#endif
WREG32(DMA_IB_CNTL + reg_offset, ib_cntl);
dma_cntl = RREG32(DMA_CNTL + reg_offset);
dma_cntl &= ~CTXEMPTY_INT_ENABLE;
WREG32(DMA_CNTL + reg_offset, dma_cntl);
ring->wptr = 0;
WREG32(DMA_RB_WPTR + reg_offset, ring->wptr << 2);
ring->rptr = RREG32(DMA_RB_RPTR + reg_offset) >> 2;
WREG32(DMA_RB_CNTL + reg_offset, rb_cntl | DMA_RB_ENABLE);
ring->ready = true;
r = radeon_ring_test(rdev, ring->idx, ring);
if (r) {
ring->ready = false;
return r;
}
}
radeon_ttm_set_active_vram_size(rdev, rdev->mc.real_vram_size);
return 0;
}
void cayman_dma_fini(struct radeon_device *rdev)
{
cayman_dma_stop(rdev);
radeon_ring_fini(rdev, &rdev->ring[R600_RING_TYPE_DMA_INDEX]);
radeon_ring_fini(rdev, &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX]);
}
bool cayman_dma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = cayman_gpu_check_soft_reset(rdev);
u32 mask;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
mask = RADEON_RESET_DMA;
else
mask = RADEON_RESET_DMA1;
if (!(reset_mask & mask)) {
radeon_ring_lockup_update(ring);
return false;
}
radeon_ring_force_activity(rdev, ring);
return radeon_ring_test_lockup(rdev, ring);
}
void cayman_dma_vm_set_page(struct radeon_device *rdev,
struct radeon_ib *ib,
uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
uint32_t r600_flags = cayman_vm_page_flags(rdev, flags);
uint64_t value;
unsigned ndw;
if ((flags & RADEON_VM_PAGE_SYSTEM) || (count == 1)) {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
ib->ptr[ib->length_dw++] = DMA_PACKET(DMA_PACKET_WRITE, 0, 0, ndw);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe) & 0xff;
for (; ndw > 0; ndw -= 2, --count, pe += 8) {
if (flags & RADEON_VM_PAGE_SYSTEM) {
value = radeon_vm_map_gart(rdev, addr);
value &= 0xFFFFFFFFFFFFF000ULL;
} else if (flags & RADEON_VM_PAGE_VALID) {
value = addr;
} else {
value = 0;
}
addr += incr;
value |= r600_flags;
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
}
}
} else {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
if (flags & RADEON_VM_PAGE_VALID)
value = addr;
else
value = 0;
ib->ptr[ib->length_dw++] = DMA_PTE_PDE_PACKET(ndw);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe) & 0xff;
ib->ptr[ib->length_dw++] = r600_flags;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
ib->ptr[ib->length_dw++] = incr;
ib->ptr[ib->length_dw++] = 0;
pe += ndw * 4;
addr += (ndw / 2) * incr;
count -= ndw / 2;
}
}
while (ib->length_dw & 0x7)
ib->ptr[ib->length_dw++] = DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0);
}
void cayman_dma_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | ((VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2));
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (HDP_MEM_COHERENCY_FLUSH_CNTL >> 2));
radeon_ring_write(ring, 1);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (VM_INVALIDATE_REQUEST >> 2));
radeon_ring_write(ring, 1 << vm->id);
}
