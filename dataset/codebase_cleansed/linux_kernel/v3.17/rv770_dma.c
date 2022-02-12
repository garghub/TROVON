int rv770_copy_dma(struct radeon_device *rdev,
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
num_loops = DIV_ROUND_UP(size_in_dw, 0xFFFF);
r = radeon_ring_lock(rdev, ring, num_loops * 5 + 8);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
radeon_semaphore_sync_to(sem, *fence);
radeon_semaphore_sync_rings(rdev, sem, ring->idx);
for (i = 0; i < num_loops; i++) {
cur_size_in_dw = size_in_dw;
if (cur_size_in_dw > 0xFFFF)
cur_size_in_dw = 0xFFFF;
size_in_dw -= cur_size_in_dw;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_COPY, 0, 0, cur_size_in_dw));
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
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
radeon_ring_unlock_commit(rdev, ring, false);
radeon_semaphore_free(rdev, &sem, *fence);
return r;
}
