void evergreen_dma_fence_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_FENCE, 0, 0));
radeon_ring_write(ring, addr & 0xfffffffc);
radeon_ring_write(ring, (upper_32_bits(addr) & 0xff));
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_TRAP, 0, 0));
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (HDP_MEM_COHERENCY_FLUSH_CNTL >> 2));
radeon_ring_write(ring, 1);
}
void evergreen_dma_ring_ib_execute(struct radeon_device *rdev,
struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
if (rdev->wb.enabled) {
u32 next_rptr = ring->wptr + 4;
while ((next_rptr & 7) != 5)
next_rptr++;
next_rptr += 3;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_WRITE, 0, 1));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xff);
radeon_ring_write(ring, next_rptr);
}
while ((ring->wptr & 7) != 5)
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_NOP, 0, 0));
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_INDIRECT_BUFFER, 0, 0));
radeon_ring_write(ring, (ib->gpu_addr & 0xFFFFFFE0));
radeon_ring_write(ring, (ib->length_dw << 12) | (upper_32_bits(ib->gpu_addr) & 0xFF));
}
int evergreen_copy_dma(struct radeon_device *rdev,
uint64_t src_offset, uint64_t dst_offset,
unsigned num_gpu_pages,
struct radeon_fence **fence)
{
struct radeon_semaphore *sem = NULL;
int ring_index = rdev->asic->copy.dma_ring_index;
struct radeon_ring *ring = &rdev->ring[ring_index];
u32 size_in_dw, cur_size_in_dw;
int i, num_loops;
int r = 0;
r = radeon_semaphore_create(rdev, &sem);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
return r;
}
size_in_dw = (num_gpu_pages << RADEON_GPU_PAGE_SHIFT) / 4;
num_loops = DIV_ROUND_UP(size_in_dw, 0xfffff);
r = radeon_ring_lock(rdev, ring, num_loops * 5 + 11);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
radeon_semaphore_sync_to(sem, *fence);
radeon_semaphore_sync_rings(rdev, sem, ring->idx);
for (i = 0; i < num_loops; i++) {
cur_size_in_dw = size_in_dw;
if (cur_size_in_dw > 0xFFFFF)
cur_size_in_dw = 0xFFFFF;
size_in_dw -= cur_size_in_dw;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_COPY, 0, cur_size_in_dw));
radeon_ring_write(ring, dst_offset & 0xfffffffc);
radeon_ring_write(ring, src_offset & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(dst_offset) & 0xff);
radeon_ring_write(ring, upper_32_bits(src_offset) & 0xff);
src_offset += cur_size_in_dw * 4;
dst_offset += cur_size_in_dw * 4;
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
bool evergreen_dma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = evergreen_gpu_check_soft_reset(rdev);
if (!(reset_mask & RADEON_RESET_DMA)) {
radeon_ring_lockup_update(ring);
return false;
}
radeon_ring_force_activity(rdev, ring);
return radeon_ring_test_lockup(rdev, ring);
}
