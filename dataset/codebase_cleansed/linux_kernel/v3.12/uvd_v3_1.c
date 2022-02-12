void uvd_v3_1_semaphore_emit(struct radeon_device *rdev,
struct radeon_ring *ring,
struct radeon_semaphore *semaphore,
bool emit_wait)
{
uint64_t addr = semaphore->gpu_addr;
radeon_ring_write(ring, PACKET0(UVD_SEMA_ADDR_LOW, 0));
radeon_ring_write(ring, (addr >> 3) & 0x000FFFFF);
radeon_ring_write(ring, PACKET0(UVD_SEMA_ADDR_HIGH, 0));
radeon_ring_write(ring, (addr >> 23) & 0x000FFFFF);
radeon_ring_write(ring, PACKET0(UVD_SEMA_CMD, 0));
radeon_ring_write(ring, 0x80 | (emit_wait ? 1 : 0));
}
