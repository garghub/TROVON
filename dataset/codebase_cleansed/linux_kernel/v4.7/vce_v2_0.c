static uint32_t vce_v2_0_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
return RREG32(mmVCE_RB_RPTR);
else
return RREG32(mmVCE_RB_RPTR2);
}
static uint32_t vce_v2_0_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
return RREG32(mmVCE_RB_WPTR);
else
return RREG32(mmVCE_RB_WPTR2);
}
static void vce_v2_0_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
WREG32(mmVCE_RB_WPTR, ring->wptr);
else
WREG32(mmVCE_RB_WPTR2, ring->wptr);
}
static int vce_v2_0_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
int i, j, r;
vce_v2_0_mc_resume(adev);
WREG32_P(mmVCE_STATUS, 1, ~1);
ring = &adev->vce.ring[0];
WREG32(mmVCE_RB_RPTR, ring->wptr);
WREG32(mmVCE_RB_WPTR, ring->wptr);
WREG32(mmVCE_RB_BASE_LO, ring->gpu_addr);
WREG32(mmVCE_RB_BASE_HI, upper_32_bits(ring->gpu_addr));
WREG32(mmVCE_RB_SIZE, ring->ring_size / 4);
ring = &adev->vce.ring[1];
WREG32(mmVCE_RB_RPTR2, ring->wptr);
WREG32(mmVCE_RB_WPTR2, ring->wptr);
WREG32(mmVCE_RB_BASE_LO2, ring->gpu_addr);
WREG32(mmVCE_RB_BASE_HI2, upper_32_bits(ring->gpu_addr));
WREG32(mmVCE_RB_SIZE2, ring->ring_size / 4);
WREG32_P(mmVCE_VCPU_CNTL, VCE_VCPU_CNTL__CLK_EN_MASK, ~VCE_VCPU_CNTL__CLK_EN_MASK);
WREG32_P(mmVCE_SOFT_RESET,
VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(100);
WREG32_P(mmVCE_SOFT_RESET, 0, ~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
for (i = 0; i < 10; ++i) {
uint32_t status;
for (j = 0; j < 100; ++j) {
status = RREG32(mmVCE_STATUS);
if (status & 2)
break;
mdelay(10);
}
r = 0;
if (status & 2)
break;
DRM_ERROR("VCE not responding, trying to reset the ECPU!!!\n");
WREG32_P(mmVCE_SOFT_RESET, VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(10);
WREG32_P(mmVCE_SOFT_RESET, 0, ~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(10);
r = -1;
}
WREG32_P(mmVCE_STATUS, 0, ~1);
if (r) {
DRM_ERROR("VCE not responding, giving up!!!\n");
return r;
}
return 0;
}
static int vce_v2_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vce_v2_0_set_ring_funcs(adev);
vce_v2_0_set_irq_funcs(adev);
return 0;
}
static int vce_v2_0_sw_init(void *handle)
{
struct amdgpu_ring *ring;
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, 167, &adev->vce.irq);
if (r)
return r;
r = amdgpu_vce_sw_init(adev, VCE_V2_0_FW_SIZE +
VCE_V2_0_STACK_SIZE + VCE_V2_0_DATA_SIZE);
if (r)
return r;
r = amdgpu_vce_resume(adev);
if (r)
return r;
ring = &adev->vce.ring[0];
sprintf(ring->name, "vce0");
r = amdgpu_ring_init(adev, ring, 512, VCE_CMD_NO_OP, 0xf,
&adev->vce.irq, 0, AMDGPU_RING_TYPE_VCE);
if (r)
return r;
ring = &adev->vce.ring[1];
sprintf(ring->name, "vce1");
r = amdgpu_ring_init(adev, ring, 512, VCE_CMD_NO_OP, 0xf,
&adev->vce.irq, 0, AMDGPU_RING_TYPE_VCE);
if (r)
return r;
return r;
}
static int vce_v2_0_sw_fini(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vce_suspend(adev);
if (r)
return r;
r = amdgpu_vce_sw_fini(adev);
if (r)
return r;
return r;
}
static int vce_v2_0_hw_init(void *handle)
{
struct amdgpu_ring *ring;
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v2_0_start(adev);
if (r)
return 0;
ring = &adev->vce.ring[0];
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
ring = &adev->vce.ring[1];
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
DRM_INFO("VCE initialized successfully.\n");
return 0;
}
static int vce_v2_0_hw_fini(void *handle)
{
return 0;
}
static int vce_v2_0_suspend(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v2_0_hw_fini(adev);
if (r)
return r;
r = amdgpu_vce_suspend(adev);
if (r)
return r;
return r;
}
static int vce_v2_0_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vce_resume(adev);
if (r)
return r;
r = vce_v2_0_hw_init(adev);
if (r)
return r;
return r;
}
static void vce_v2_0_set_sw_cg(struct amdgpu_device *adev, bool gated)
{
u32 tmp;
if (gated) {
tmp = RREG32(mmVCE_CLOCK_GATING_B);
tmp |= 0xe70000;
WREG32(mmVCE_CLOCK_GATING_B, tmp);
tmp = RREG32(mmVCE_UENC_CLOCK_GATING);
tmp |= 0xff000000;
WREG32(mmVCE_UENC_CLOCK_GATING, tmp);
tmp = RREG32(mmVCE_UENC_REG_CLOCK_GATING);
tmp &= ~0x3fc;
WREG32(mmVCE_UENC_REG_CLOCK_GATING, tmp);
WREG32(mmVCE_CGTT_CLK_OVERRIDE, 0);
} else {
tmp = RREG32(mmVCE_CLOCK_GATING_B);
tmp |= 0xe7;
tmp &= ~0xe70000;
WREG32(mmVCE_CLOCK_GATING_B, tmp);
tmp = RREG32(mmVCE_UENC_CLOCK_GATING);
tmp |= 0x1fe000;
tmp &= ~0xff000000;
WREG32(mmVCE_UENC_CLOCK_GATING, tmp);
tmp = RREG32(mmVCE_UENC_REG_CLOCK_GATING);
tmp |= 0x3fc;
WREG32(mmVCE_UENC_REG_CLOCK_GATING, tmp);
}
}
static void vce_v2_0_set_dyn_cg(struct amdgpu_device *adev, bool gated)
{
u32 orig, tmp;
if (gated) {
if (vce_v2_0_wait_for_idle(adev)) {
DRM_INFO("VCE is busy, Can't set clock gateing");
return;
}
WREG32_P(mmVCE_VCPU_CNTL, 0, ~VCE_VCPU_CNTL__CLK_EN_MASK);
WREG32_P(mmVCE_SOFT_RESET, VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK, ~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(100);
WREG32(mmVCE_STATUS, 0);
} else {
WREG32_P(mmVCE_VCPU_CNTL, VCE_VCPU_CNTL__CLK_EN_MASK, ~VCE_VCPU_CNTL__CLK_EN_MASK);
WREG32_P(mmVCE_SOFT_RESET, VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK, ~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(100);
}
tmp = RREG32(mmVCE_CLOCK_GATING_B);
tmp &= ~0x00060006;
if (gated) {
tmp |= 0xe10000;
} else {
tmp |= 0xe1;
tmp &= ~0xe10000;
}
WREG32(mmVCE_CLOCK_GATING_B, tmp);
orig = tmp = RREG32(mmVCE_UENC_CLOCK_GATING);
tmp &= ~0x1fe000;
tmp &= ~0xff000000;
if (tmp != orig)
WREG32(mmVCE_UENC_CLOCK_GATING, tmp);
orig = tmp = RREG32(mmVCE_UENC_REG_CLOCK_GATING);
tmp &= ~0x3fc;
if (tmp != orig)
WREG32(mmVCE_UENC_REG_CLOCK_GATING, tmp);
if (gated)
WREG32(mmVCE_CGTT_CLK_OVERRIDE, 0);
WREG32_P(mmVCE_SOFT_RESET, 0, ~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
}
static void vce_v2_0_disable_cg(struct amdgpu_device *adev)
{
WREG32(mmVCE_CGTT_CLK_OVERRIDE, 7);
}
static void vce_v2_0_enable_mgcg(struct amdgpu_device *adev, bool enable)
{
bool sw_cg = false;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_VCE_MGCG)) {
if (sw_cg)
vce_v2_0_set_sw_cg(adev, true);
else
vce_v2_0_set_dyn_cg(adev, true);
} else {
vce_v2_0_disable_cg(adev);
if (sw_cg)
vce_v2_0_set_sw_cg(adev, false);
else
vce_v2_0_set_dyn_cg(adev, false);
}
}
static void vce_v2_0_init_cg(struct amdgpu_device *adev)
{
u32 tmp;
tmp = RREG32(mmVCE_CLOCK_GATING_A);
tmp &= ~0xfff;
tmp |= ((0 << 0) | (4 << 4));
tmp |= 0x40000;
WREG32(mmVCE_CLOCK_GATING_A, tmp);
tmp = RREG32(mmVCE_UENC_CLOCK_GATING);
tmp &= ~0xfff;
tmp |= ((0 << 0) | (4 << 4));
WREG32(mmVCE_UENC_CLOCK_GATING, tmp);
tmp = RREG32(mmVCE_CLOCK_GATING_B);
tmp |= 0x10;
tmp &= ~0x100000;
WREG32(mmVCE_CLOCK_GATING_B, tmp);
}
static void vce_v2_0_mc_resume(struct amdgpu_device *adev)
{
uint64_t addr = adev->vce.gpu_addr;
uint32_t size;
WREG32_P(mmVCE_CLOCK_GATING_A, 0, ~(1 << 16));
WREG32_P(mmVCE_UENC_CLOCK_GATING, 0x1FF000, ~0xFF9FF000);
WREG32_P(mmVCE_UENC_REG_CLOCK_GATING, 0x3F, ~0x3F);
WREG32(mmVCE_CLOCK_GATING_B, 0xf7);
WREG32(mmVCE_LMI_CTRL, 0x00398000);
WREG32_P(mmVCE_LMI_CACHE_CTRL, 0x0, ~0x1);
WREG32(mmVCE_LMI_SWAP_CNTL, 0);
WREG32(mmVCE_LMI_SWAP_CNTL1, 0);
WREG32(mmVCE_LMI_VM_CTRL, 0);
addr += AMDGPU_VCE_FIRMWARE_OFFSET;
size = VCE_V2_0_FW_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET0, addr & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE0, size);
addr += size;
size = VCE_V2_0_STACK_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET1, addr & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE1, size);
addr += size;
size = VCE_V2_0_DATA_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET2, addr & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE2, size);
WREG32_P(mmVCE_LMI_CTRL2, 0x0, ~0x100);
WREG32_P(mmVCE_SYS_INT_EN, VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK,
~VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK);
vce_v2_0_init_cg(adev);
}
static bool vce_v2_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return !(RREG32(mmSRBM_STATUS2) & SRBM_STATUS2__VCE_BUSY_MASK);
}
static int vce_v2_0_wait_for_idle(void *handle)
{
unsigned i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
if (!(RREG32(mmSRBM_STATUS2) & SRBM_STATUS2__VCE_BUSY_MASK))
return 0;
}
return -ETIMEDOUT;
}
static int vce_v2_0_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
WREG32_P(mmSRBM_SOFT_RESET, SRBM_SOFT_RESET__SOFT_RESET_VCE_MASK,
~SRBM_SOFT_RESET__SOFT_RESET_VCE_MASK);
mdelay(5);
return vce_v2_0_start(adev);
}
static int vce_v2_0_set_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
uint32_t val = 0;
if (state == AMDGPU_IRQ_STATE_ENABLE)
val |= VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK;
WREG32_P(mmVCE_SYS_INT_EN, val, ~VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK);
return 0;
}
static int vce_v2_0_process_interrupt(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_DEBUG("IH: VCE\n");
switch (entry->src_data) {
case 0:
amdgpu_fence_process(&adev->vce.ring[0]);
break;
case 1:
amdgpu_fence_process(&adev->vce.ring[1]);
break;
default:
DRM_ERROR("Unhandled interrupt: %d %d\n",
entry->src_id, entry->src_data);
break;
}
return 0;
}
static int vce_v2_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
bool gate = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (state == AMD_CG_STATE_GATE)
gate = true;
vce_v2_0_enable_mgcg(adev, gate);
return 0;
}
static int vce_v2_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (!(adev->pg_flags & AMD_PG_SUPPORT_VCE))
return 0;
if (state == AMD_PG_STATE_GATE)
return 0;
else
return vce_v2_0_start(adev);
}
static void vce_v2_0_set_ring_funcs(struct amdgpu_device *adev)
{
adev->vce.ring[0].funcs = &vce_v2_0_ring_funcs;
adev->vce.ring[1].funcs = &vce_v2_0_ring_funcs;
}
static void vce_v2_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->vce.irq.num_types = 1;
adev->vce.irq.funcs = &vce_v2_0_irq_funcs;
}
