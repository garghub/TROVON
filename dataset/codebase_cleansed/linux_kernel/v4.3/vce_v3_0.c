static uint32_t vce_v3_0_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
return RREG32(mmVCE_RB_RPTR);
else
return RREG32(mmVCE_RB_RPTR2);
}
static uint32_t vce_v3_0_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
return RREG32(mmVCE_RB_WPTR);
else
return RREG32(mmVCE_RB_WPTR2);
}
static void vce_v3_0_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vce.ring[0])
WREG32(mmVCE_RB_WPTR, ring->wptr);
else
WREG32(mmVCE_RB_WPTR2, ring->wptr);
}
static int vce_v3_0_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
int idx, i, j, r;
mutex_lock(&adev->grbm_idx_mutex);
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
if(idx == 0)
WREG32_P(mmGRBM_GFX_INDEX, 0,
~GRBM_GFX_INDEX__VCE_INSTANCE_MASK);
else
WREG32_P(mmGRBM_GFX_INDEX,
GRBM_GFX_INDEX__VCE_INSTANCE_MASK,
~GRBM_GFX_INDEX__VCE_INSTANCE_MASK);
vce_v3_0_mc_resume(adev, idx);
WREG32_P(mmVCE_STATUS, 1, ~1);
WREG32_P(mmVCE_VCPU_CNTL, VCE_VCPU_CNTL__CLK_EN_MASK,
~VCE_VCPU_CNTL__CLK_EN_MASK);
WREG32_P(mmVCE_SOFT_RESET,
VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(100);
WREG32_P(mmVCE_SOFT_RESET, 0,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
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
WREG32_P(mmVCE_SOFT_RESET,
VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(10);
WREG32_P(mmVCE_SOFT_RESET, 0,
~VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK);
mdelay(10);
r = -1;
}
WREG32_P(mmVCE_STATUS, 0, ~1);
if (r) {
DRM_ERROR("VCE not responding, giving up!!!\n");
mutex_unlock(&adev->grbm_idx_mutex);
return r;
}
}
WREG32_P(mmGRBM_GFX_INDEX, 0, ~GRBM_GFX_INDEX__VCE_INSTANCE_MASK);
mutex_unlock(&adev->grbm_idx_mutex);
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
return 0;
}
static unsigned vce_v3_0_get_harvest_config(struct amdgpu_device *adev)
{
u32 tmp;
unsigned ret;
if (adev->asic_type == CHIP_FIJI) {
ret = AMDGPU_VCE_HARVEST_VCE1;
return ret;
}
if (adev->flags & AMD_IS_APU)
tmp = (RREG32_SMC(ixVCE_HARVEST_FUSE_MACRO__ADDRESS) &
VCE_HARVEST_FUSE_MACRO__MASK) >>
VCE_HARVEST_FUSE_MACRO__SHIFT;
else
tmp = (RREG32_SMC(ixCC_HARVEST_FUSES) &
CC_HARVEST_FUSES__VCE_DISABLE_MASK) >>
CC_HARVEST_FUSES__VCE_DISABLE__SHIFT;
switch (tmp) {
case 1:
ret = AMDGPU_VCE_HARVEST_VCE0;
break;
case 2:
ret = AMDGPU_VCE_HARVEST_VCE1;
break;
case 3:
ret = AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1;
break;
default:
ret = 0;
}
return ret;
}
static int vce_v3_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->vce.harvest_config = vce_v3_0_get_harvest_config(adev);
if ((adev->vce.harvest_config &
(AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1)) ==
(AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1))
return -ENOENT;
vce_v3_0_set_ring_funcs(adev);
vce_v3_0_set_irq_funcs(adev);
return 0;
}
static int vce_v3_0_sw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring;
int r;
r = amdgpu_irq_add_id(adev, 167, &adev->vce.irq);
if (r)
return r;
r = amdgpu_vce_sw_init(adev, VCE_V3_0_FW_SIZE +
(VCE_V3_0_STACK_SIZE + VCE_V3_0_DATA_SIZE) * 2);
if (r)
return r;
r = amdgpu_vce_resume(adev);
if (r)
return r;
ring = &adev->vce.ring[0];
sprintf(ring->name, "vce0");
r = amdgpu_ring_init(adev, ring, 4096, VCE_CMD_NO_OP, 0xf,
&adev->vce.irq, 0, AMDGPU_RING_TYPE_VCE);
if (r)
return r;
ring = &adev->vce.ring[1];
sprintf(ring->name, "vce1");
r = amdgpu_ring_init(adev, ring, 4096, VCE_CMD_NO_OP, 0xf,
&adev->vce.irq, 0, AMDGPU_RING_TYPE_VCE);
if (r)
return r;
return r;
}
static int vce_v3_0_sw_fini(void *handle)
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
static int vce_v3_0_hw_init(void *handle)
{
struct amdgpu_ring *ring;
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v3_0_start(adev);
if (r)
return r;
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
static int vce_v3_0_hw_fini(void *handle)
{
return 0;
}
static int vce_v3_0_suspend(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v3_0_hw_fini(adev);
if (r)
return r;
r = amdgpu_vce_suspend(adev);
if (r)
return r;
return r;
}
static int vce_v3_0_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vce_resume(adev);
if (r)
return r;
r = vce_v3_0_hw_init(adev);
if (r)
return r;
return r;
}
static void vce_v3_0_mc_resume(struct amdgpu_device *adev, int idx)
{
uint32_t offset, size;
WREG32_P(mmVCE_CLOCK_GATING_A, 0, ~(1 << 16));
WREG32_P(mmVCE_UENC_CLOCK_GATING, 0x1FF000, ~0xFF9FF000);
WREG32_P(mmVCE_UENC_REG_CLOCK_GATING, 0x3F, ~0x3F);
WREG32(mmVCE_CLOCK_GATING_B, 0xf7);
WREG32(mmVCE_LMI_CTRL, 0x00398000);
WREG32_P(mmVCE_LMI_CACHE_CTRL, 0x0, ~0x1);
WREG32(mmVCE_LMI_SWAP_CNTL, 0);
WREG32(mmVCE_LMI_SWAP_CNTL1, 0);
WREG32(mmVCE_LMI_VM_CTRL, 0);
WREG32(mmVCE_LMI_VCPU_CACHE_40BIT_BAR, (adev->vce.gpu_addr >> 8));
offset = AMDGPU_VCE_FIRMWARE_OFFSET;
size = VCE_V3_0_FW_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET0, offset & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE0, size);
if (idx == 0) {
offset += size;
size = VCE_V3_0_STACK_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET1, offset & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE1, size);
offset += size;
size = VCE_V3_0_DATA_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET2, offset & 0x7fffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE2, size);
} else {
offset += size + VCE_V3_0_STACK_SIZE + VCE_V3_0_DATA_SIZE;
size = VCE_V3_0_STACK_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET1, offset & 0xfffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE1, size);
offset += size;
size = VCE_V3_0_DATA_SIZE;
WREG32(mmVCE_VCPU_CACHE_OFFSET2, offset & 0xfffffff);
WREG32(mmVCE_VCPU_CACHE_SIZE2, size);
}
WREG32_P(mmVCE_LMI_CTRL2, 0x0, ~0x100);
WREG32_P(mmVCE_SYS_INT_EN, VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK,
~VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK);
}
static bool vce_v3_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 mask = 0;
int idx;
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
if (idx == 0)
mask |= SRBM_STATUS2__VCE0_BUSY_MASK;
else
mask |= SRBM_STATUS2__VCE1_BUSY_MASK;
}
return !(RREG32(mmSRBM_STATUS2) & mask);
}
static int vce_v3_0_wait_for_idle(void *handle)
{
unsigned i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 mask = 0;
int idx;
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
if (idx == 0)
mask |= SRBM_STATUS2__VCE0_BUSY_MASK;
else
mask |= SRBM_STATUS2__VCE1_BUSY_MASK;
}
for (i = 0; i < adev->usec_timeout; i++) {
if (!(RREG32(mmSRBM_STATUS2) & mask))
return 0;
}
return -ETIMEDOUT;
}
static int vce_v3_0_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 mask = 0;
int idx;
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
if (idx == 0)
mask |= SRBM_SOFT_RESET__SOFT_RESET_VCE0_MASK;
else
mask |= SRBM_SOFT_RESET__SOFT_RESET_VCE1_MASK;
}
WREG32_P(mmSRBM_SOFT_RESET, mask,
~(SRBM_SOFT_RESET__SOFT_RESET_VCE0_MASK |
SRBM_SOFT_RESET__SOFT_RESET_VCE1_MASK));
mdelay(5);
return vce_v3_0_start(adev);
}
static void vce_v3_0_print_status(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
dev_info(adev->dev, "VCE 3.0 registers\n");
dev_info(adev->dev, " VCE_STATUS=0x%08X\n",
RREG32(mmVCE_STATUS));
dev_info(adev->dev, " VCE_VCPU_CNTL=0x%08X\n",
RREG32(mmVCE_VCPU_CNTL));
dev_info(adev->dev, " VCE_VCPU_CACHE_OFFSET0=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_OFFSET0));
dev_info(adev->dev, " VCE_VCPU_CACHE_SIZE0=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_SIZE0));
dev_info(adev->dev, " VCE_VCPU_CACHE_OFFSET1=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_OFFSET1));
dev_info(adev->dev, " VCE_VCPU_CACHE_SIZE1=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_SIZE1));
dev_info(adev->dev, " VCE_VCPU_CACHE_OFFSET2=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_OFFSET2));
dev_info(adev->dev, " VCE_VCPU_CACHE_SIZE2=0x%08X\n",
RREG32(mmVCE_VCPU_CACHE_SIZE2));
dev_info(adev->dev, " VCE_SOFT_RESET=0x%08X\n",
RREG32(mmVCE_SOFT_RESET));
dev_info(adev->dev, " VCE_RB_BASE_LO2=0x%08X\n",
RREG32(mmVCE_RB_BASE_LO2));
dev_info(adev->dev, " VCE_RB_BASE_HI2=0x%08X\n",
RREG32(mmVCE_RB_BASE_HI2));
dev_info(adev->dev, " VCE_RB_SIZE2=0x%08X\n",
RREG32(mmVCE_RB_SIZE2));
dev_info(adev->dev, " VCE_RB_RPTR2=0x%08X\n",
RREG32(mmVCE_RB_RPTR2));
dev_info(adev->dev, " VCE_RB_WPTR2=0x%08X\n",
RREG32(mmVCE_RB_WPTR2));
dev_info(adev->dev, " VCE_RB_BASE_LO=0x%08X\n",
RREG32(mmVCE_RB_BASE_LO));
dev_info(adev->dev, " VCE_RB_BASE_HI=0x%08X\n",
RREG32(mmVCE_RB_BASE_HI));
dev_info(adev->dev, " VCE_RB_SIZE=0x%08X\n",
RREG32(mmVCE_RB_SIZE));
dev_info(adev->dev, " VCE_RB_RPTR=0x%08X\n",
RREG32(mmVCE_RB_RPTR));
dev_info(adev->dev, " VCE_RB_WPTR=0x%08X\n",
RREG32(mmVCE_RB_WPTR));
dev_info(adev->dev, " VCE_CLOCK_GATING_A=0x%08X\n",
RREG32(mmVCE_CLOCK_GATING_A));
dev_info(adev->dev, " VCE_CLOCK_GATING_B=0x%08X\n",
RREG32(mmVCE_CLOCK_GATING_B));
dev_info(adev->dev, " VCE_UENC_CLOCK_GATING=0x%08X\n",
RREG32(mmVCE_UENC_CLOCK_GATING));
dev_info(adev->dev, " VCE_UENC_REG_CLOCK_GATING=0x%08X\n",
RREG32(mmVCE_UENC_REG_CLOCK_GATING));
dev_info(adev->dev, " VCE_SYS_INT_EN=0x%08X\n",
RREG32(mmVCE_SYS_INT_EN));
dev_info(adev->dev, " VCE_LMI_CTRL2=0x%08X\n",
RREG32(mmVCE_LMI_CTRL2));
dev_info(adev->dev, " VCE_LMI_CTRL=0x%08X\n",
RREG32(mmVCE_LMI_CTRL));
dev_info(adev->dev, " VCE_LMI_VM_CTRL=0x%08X\n",
RREG32(mmVCE_LMI_VM_CTRL));
dev_info(adev->dev, " VCE_LMI_SWAP_CNTL=0x%08X\n",
RREG32(mmVCE_LMI_SWAP_CNTL));
dev_info(adev->dev, " VCE_LMI_SWAP_CNTL1=0x%08X\n",
RREG32(mmVCE_LMI_SWAP_CNTL1));
dev_info(adev->dev, " VCE_LMI_CACHE_CTRL=0x%08X\n",
RREG32(mmVCE_LMI_CACHE_CTRL));
}
static int vce_v3_0_set_interrupt_state(struct amdgpu_device *adev,
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
static int vce_v3_0_process_interrupt(struct amdgpu_device *adev,
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
static int vce_v3_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int vce_v3_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (state == AMD_PG_STATE_GATE)
return 0;
else
return vce_v3_0_start(adev);
}
static void vce_v3_0_set_ring_funcs(struct amdgpu_device *adev)
{
adev->vce.ring[0].funcs = &vce_v3_0_ring_funcs;
adev->vce.ring[1].funcs = &vce_v3_0_ring_funcs;
}
static void vce_v3_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->vce.irq.num_types = 1;
adev->vce.irq.funcs = &vce_v3_0_irq_funcs;
}
