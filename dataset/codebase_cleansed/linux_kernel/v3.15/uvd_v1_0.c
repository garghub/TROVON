uint32_t uvd_v1_0_get_rptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
return RREG32(UVD_RBC_RB_RPTR);
}
uint32_t uvd_v1_0_get_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
return RREG32(UVD_RBC_RB_WPTR);
}
void uvd_v1_0_set_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
WREG32(UVD_RBC_RB_WPTR, ring->wptr);
}
int uvd_v1_0_init(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[R600_RING_TYPE_UVD_INDEX];
uint32_t tmp;
int r;
if (rdev->family < CHIP_RV740)
radeon_set_uvd_clocks(rdev, 10000, 10000);
else
radeon_set_uvd_clocks(rdev, 53300, 40000);
r = uvd_v1_0_start(rdev);
if (r)
goto done;
ring->ready = true;
r = radeon_ring_test(rdev, R600_RING_TYPE_UVD_INDEX, ring);
if (r) {
ring->ready = false;
goto done;
}
r = radeon_ring_lock(rdev, ring, 10);
if (r) {
DRM_ERROR("radeon: ring failed to lock UVD ring (%d).\n", r);
goto done;
}
tmp = PACKET0(UVD_SEMA_WAIT_FAULT_TIMEOUT_CNTL, 0);
radeon_ring_write(ring, tmp);
radeon_ring_write(ring, 0xFFFFF);
tmp = PACKET0(UVD_SEMA_WAIT_INCOMPLETE_TIMEOUT_CNTL, 0);
radeon_ring_write(ring, tmp);
radeon_ring_write(ring, 0xFFFFF);
tmp = PACKET0(UVD_SEMA_SIGNAL_INCOMPLETE_TIMEOUT_CNTL, 0);
radeon_ring_write(ring, tmp);
radeon_ring_write(ring, 0xFFFFF);
radeon_ring_write(ring, PACKET0(UVD_SEMA_TIMEOUT_STATUS, 0));
radeon_ring_write(ring, 0x8);
radeon_ring_write(ring, PACKET0(UVD_SEMA_CNTL, 0));
radeon_ring_write(ring, 3);
radeon_ring_unlock_commit(rdev, ring);
done:
radeon_set_uvd_clocks(rdev, 0, 0);
if (!r)
DRM_INFO("UVD initialized successfully.\n");
return r;
}
void uvd_v1_0_fini(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[R600_RING_TYPE_UVD_INDEX];
uvd_v1_0_stop(rdev);
ring->ready = false;
}
int uvd_v1_0_start(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[R600_RING_TYPE_UVD_INDEX];
uint32_t rb_bufsz;
int i, j, r;
u32 lmi_swap_cntl = 0;
u32 mp_swap_cntl = 0;
WREG32(UVD_CGC_GATE, 0);
WREG32_P(UVD_MASTINT_EN, 0, ~(1 << 1));
WREG32_P(UVD_LMI_CTRL2, 1 << 8, ~(1 << 8));
WREG32_P(UVD_RB_ARB_CTRL, 1 << 3, ~(1 << 3));
mdelay(1);
WREG32(UVD_SOFT_RESET, LMI_SOFT_RESET | VCPU_SOFT_RESET |
LBSI_SOFT_RESET | RBC_SOFT_RESET | CSM_SOFT_RESET |
CXW_SOFT_RESET | TAP_SOFT_RESET | LMI_UMC_SOFT_RESET);
mdelay(5);
WREG32_P(SRBM_SOFT_RESET, 0, ~SOFT_RESET_UVD);
mdelay(5);
WREG32(UVD_LMI_CTRL, 0x40 | (1 << 8) | (1 << 13) |
(1 << 21) | (1 << 9) | (1 << 20));
#ifdef __BIG_ENDIAN
lmi_swap_cntl = 0xa;
mp_swap_cntl = 0;
#endif
WREG32(UVD_LMI_SWAP_CNTL, lmi_swap_cntl);
WREG32(UVD_MP_SWAP_CNTL, mp_swap_cntl);
WREG32(UVD_MPC_SET_MUXA0, 0x40c2040);
WREG32(UVD_MPC_SET_MUXA1, 0x0);
WREG32(UVD_MPC_SET_MUXB0, 0x40c2040);
WREG32(UVD_MPC_SET_MUXB1, 0x0);
WREG32(UVD_MPC_SET_ALU, 0);
WREG32(UVD_MPC_SET_MUX, 0x88);
WREG32(UVD_SOFT_RESET, VCPU_SOFT_RESET);
mdelay(5);
WREG32(UVD_VCPU_CNTL, 1 << 9);
WREG32_P(UVD_LMI_CTRL2, 0, ~(1 << 8));
WREG32(UVD_SOFT_RESET, 0);
mdelay(10);
WREG32_P(UVD_RB_ARB_CTRL, 0, ~(1 << 3));
for (i = 0; i < 10; ++i) {
uint32_t status;
for (j = 0; j < 100; ++j) {
status = RREG32(UVD_STATUS);
if (status & 2)
break;
mdelay(10);
}
r = 0;
if (status & 2)
break;
DRM_ERROR("UVD not responding, trying to reset the VCPU!!!\n");
WREG32_P(UVD_SOFT_RESET, VCPU_SOFT_RESET, ~VCPU_SOFT_RESET);
mdelay(10);
WREG32_P(UVD_SOFT_RESET, 0, ~VCPU_SOFT_RESET);
mdelay(10);
r = -1;
}
if (r) {
DRM_ERROR("UVD not responding, giving up!!!\n");
return r;
}
WREG32_P(UVD_MASTINT_EN, 3<<1, ~(3 << 1));
WREG32(UVD_RBC_RB_CNTL, 0x11010101);
WREG32(UVD_RBC_RB_WPTR_CNTL, 0);
WREG32(UVD_LMI_EXT40_ADDR, upper_32_bits(ring->gpu_addr) |
(0x7 << 16) | (0x1 << 31));
WREG32(UVD_RBC_RB_RPTR, 0x0);
ring->wptr = RREG32(UVD_RBC_RB_RPTR);
WREG32(UVD_RBC_RB_WPTR, ring->wptr);
WREG32(UVD_RBC_RB_BASE, ring->gpu_addr);
rb_bufsz = order_base_2(ring->ring_size);
rb_bufsz = (0x1 << 8) | rb_bufsz;
WREG32_P(UVD_RBC_RB_CNTL, rb_bufsz, ~0x11f1f);
return 0;
}
void uvd_v1_0_stop(struct radeon_device *rdev)
{
WREG32(UVD_RBC_RB_CNTL, 0x11010101);
WREG32_P(UVD_LMI_CTRL2, 1 << 8, ~(1 << 8));
WREG32_P(UVD_RB_ARB_CTRL, 1 << 3, ~(1 << 3));
mdelay(1);
WREG32(UVD_SOFT_RESET, VCPU_SOFT_RESET);
mdelay(5);
WREG32(UVD_VCPU_CNTL, 0x0);
WREG32_P(UVD_LMI_CTRL2, 0, ~(1 << 8));
WREG32_P(UVD_RB_ARB_CTRL, 0, ~(1 << 3));
}
int uvd_v1_0_ring_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
uint32_t tmp = 0;
unsigned i;
int r;
WREG32(UVD_CONTEXT_ID, 0xCAFEDEAD);
r = radeon_ring_lock(rdev, ring, 3);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring %d (%d).\n",
ring->idx, r);
return r;
}
radeon_ring_write(ring, PACKET0(UVD_CONTEXT_ID, 0));
radeon_ring_write(ring, 0xDEADBEEF);
radeon_ring_unlock_commit(rdev, ring);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(UVD_CONTEXT_ID);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n",
ring->idx, i);
} else {
DRM_ERROR("radeon: ring %d test failed (0x%08X)\n",
ring->idx, tmp);
r = -EINVAL;
}
return r;
}
bool uvd_v1_0_semaphore_emit(struct radeon_device *rdev,
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
radeon_ring_write(ring, emit_wait ? 1 : 0);
return true;
}
void uvd_v1_0_ib_execute(struct radeon_device *rdev, struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
radeon_ring_write(ring, PACKET0(UVD_RBC_IB_BASE, 0));
radeon_ring_write(ring, ib->gpu_addr);
radeon_ring_write(ring, PACKET0(UVD_RBC_IB_SIZE, 0));
radeon_ring_write(ring, ib->length_dw);
}
int uvd_v1_0_ib_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
struct radeon_fence *fence = NULL;
int r;
if (rdev->family < CHIP_RV740)
r = radeon_set_uvd_clocks(rdev, 10000, 10000);
else
r = radeon_set_uvd_clocks(rdev, 53300, 40000);
if (r) {
DRM_ERROR("radeon: failed to raise UVD clocks (%d).\n", r);
return r;
}
r = radeon_uvd_get_create_msg(rdev, ring->idx, 1, NULL);
if (r) {
DRM_ERROR("radeon: failed to get create msg (%d).\n", r);
goto error;
}
r = radeon_uvd_get_destroy_msg(rdev, ring->idx, 1, &fence);
if (r) {
DRM_ERROR("radeon: failed to get destroy ib (%d).\n", r);
goto error;
}
r = radeon_fence_wait(fence, false);
if (r) {
DRM_ERROR("radeon: fence wait failed (%d).\n", r);
goto error;
}
DRM_INFO("ib test on ring %d succeeded\n", ring->idx);
error:
radeon_fence_unref(&fence);
radeon_set_uvd_clocks(rdev, 0, 0);
return r;
}
