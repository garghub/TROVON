bool si_dma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = si_gpu_check_soft_reset(rdev);
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
void si_dma_vm_set_page(struct radeon_device *rdev,
struct radeon_ib *ib,
uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
uint32_t r600_flags = cayman_vm_page_flags(rdev, flags);
uint64_t value;
unsigned ndw;
if (flags & RADEON_VM_PAGE_SYSTEM) {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
ib->ptr[ib->length_dw++] = DMA_PACKET(DMA_PACKET_WRITE, 0, 0, 0, ndw);
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
ib->ptr[ib->length_dw++] = DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0, 0);
}
void si_dma_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0, 0));
if (vm->id < 8) {
radeon_ring_write(ring, (0xf << 16) | ((VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2));
} else {
radeon_ring_write(ring, (0xf << 16) | ((VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((vm->id - 8) << 2)) >> 2));
}
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (HDP_MEM_COHERENCY_FLUSH_CNTL >> 2));
radeon_ring_write(ring, 1);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (VM_INVALIDATE_REQUEST >> 2));
radeon_ring_write(ring, 1 << vm->id);
}
int si_copy_dma(struct radeon_device *rdev,
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
num_loops = DIV_ROUND_UP(size_in_bytes, 0xfffff);
r = radeon_ring_lock(rdev, ring, num_loops * 5 + 11);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
if (radeon_fence_need_sync(*fence, ring->idx)) {
radeon_semaphore_sync_rings(rdev, sem, (*fence)->ring,
ring->idx);
radeon_fence_note_sync(*fence, ring->idx);
} else {
radeon_semaphore_free(rdev, &sem, NULL);
}
for (i = 0; i < num_loops; i++) {
cur_size_in_bytes = size_in_bytes;
if (cur_size_in_bytes > 0xFFFFF)
cur_size_in_bytes = 0xFFFFF;
size_in_bytes -= cur_size_in_bytes;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_COPY, 1, 0, 0, cur_size_in_bytes));
radeon_ring_write(ring, dst_offset & 0xffffffff);
radeon_ring_write(ring, src_offset & 0xffffffff);
radeon_ring_write(ring, upper_32_bits(dst_offset) & 0xff);
radeon_ring_write(ring, upper_32_bits(src_offset) & 0xff);
src_offset += cur_size_in_bytes;
dst_offset += cur_size_in_bytes;
}
r = radeon_fence_emit(rdev, fence, ring->idx);
if (r) {
radeon_ring_unlock_undo(rdev, ring);
return r;
}
radeon_ring_unlock_commit(rdev, ring);
radeon_semaphore_free(rdev, &sem, *fence);
return r;
}
