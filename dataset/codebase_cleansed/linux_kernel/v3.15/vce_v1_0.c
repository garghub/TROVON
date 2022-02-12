uint32_t vce_v1_0_get_rptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
if (ring->idx == TN_RING_TYPE_VCE1_INDEX)
return RREG32(VCE_RB_RPTR);
else
return RREG32(VCE_RB_RPTR2);
}
uint32_t vce_v1_0_get_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
if (ring->idx == TN_RING_TYPE_VCE1_INDEX)
return RREG32(VCE_RB_WPTR);
else
return RREG32(VCE_RB_WPTR2);
}
void vce_v1_0_set_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
if (ring->idx == TN_RING_TYPE_VCE1_INDEX)
WREG32(VCE_RB_WPTR, ring->wptr);
else
WREG32(VCE_RB_WPTR2, ring->wptr);
}
int vce_v1_0_start(struct radeon_device *rdev)
{
struct radeon_ring *ring;
int i, j, r;
WREG32_P(VCE_STATUS, 1, ~1);
ring = &rdev->ring[TN_RING_TYPE_VCE1_INDEX];
WREG32(VCE_RB_RPTR, ring->wptr);
WREG32(VCE_RB_WPTR, ring->wptr);
WREG32(VCE_RB_BASE_LO, ring->gpu_addr);
WREG32(VCE_RB_BASE_HI, upper_32_bits(ring->gpu_addr));
WREG32(VCE_RB_SIZE, ring->ring_size / 4);
ring = &rdev->ring[TN_RING_TYPE_VCE2_INDEX];
WREG32(VCE_RB_RPTR2, ring->wptr);
WREG32(VCE_RB_WPTR2, ring->wptr);
WREG32(VCE_RB_BASE_LO2, ring->gpu_addr);
WREG32(VCE_RB_BASE_HI2, upper_32_bits(ring->gpu_addr));
WREG32(VCE_RB_SIZE2, ring->ring_size / 4);
WREG32_P(VCE_VCPU_CNTL, VCE_CLK_EN, ~VCE_CLK_EN);
WREG32_P(VCE_SOFT_RESET,
VCE_ECPU_SOFT_RESET |
VCE_FME_SOFT_RESET, ~(
VCE_ECPU_SOFT_RESET |
VCE_FME_SOFT_RESET));
mdelay(100);
WREG32_P(VCE_SOFT_RESET, 0, ~(
VCE_ECPU_SOFT_RESET |
VCE_FME_SOFT_RESET));
for (i = 0; i < 10; ++i) {
uint32_t status;
for (j = 0; j < 100; ++j) {
status = RREG32(VCE_STATUS);
if (status & 2)
break;
mdelay(10);
}
r = 0;
if (status & 2)
break;
DRM_ERROR("VCE not responding, trying to reset the ECPU!!!\n");
WREG32_P(VCE_SOFT_RESET, VCE_ECPU_SOFT_RESET, ~VCE_ECPU_SOFT_RESET);
mdelay(10);
WREG32_P(VCE_SOFT_RESET, 0, ~VCE_ECPU_SOFT_RESET);
mdelay(10);
r = -1;
}
WREG32_P(VCE_STATUS, 0, ~1);
if (r) {
DRM_ERROR("VCE not responding, giving up!!!\n");
return r;
}
return 0;
}
int vce_v1_0_init(struct radeon_device *rdev)
{
struct radeon_ring *ring;
int r;
r = vce_v1_0_start(rdev);
if (r)
return r;
ring = &rdev->ring[TN_RING_TYPE_VCE1_INDEX];
ring->ready = true;
r = radeon_ring_test(rdev, TN_RING_TYPE_VCE1_INDEX, ring);
if (r) {
ring->ready = false;
return r;
}
ring = &rdev->ring[TN_RING_TYPE_VCE2_INDEX];
ring->ready = true;
r = radeon_ring_test(rdev, TN_RING_TYPE_VCE2_INDEX, ring);
if (r) {
ring->ready = false;
return r;
}
DRM_INFO("VCE initialized successfully.\n");
return 0;
}
