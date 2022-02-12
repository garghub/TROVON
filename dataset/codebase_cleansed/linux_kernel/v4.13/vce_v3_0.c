static uint64_t vce_v3_0_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u32 v;
mutex_lock(&adev->grbm_idx_mutex);
if (adev->vce.harvest_config == 0 ||
adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE1)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(0));
else if (adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE0)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(1));
if (ring == &adev->vce.ring[0])
v = RREG32(mmVCE_RB_RPTR);
else if (ring == &adev->vce.ring[1])
v = RREG32(mmVCE_RB_RPTR2);
else
v = RREG32(mmVCE_RB_RPTR3);
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
return v;
}
static uint64_t vce_v3_0_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u32 v;
mutex_lock(&adev->grbm_idx_mutex);
if (adev->vce.harvest_config == 0 ||
adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE1)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(0));
else if (adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE0)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(1));
if (ring == &adev->vce.ring[0])
v = RREG32(mmVCE_RB_WPTR);
else if (ring == &adev->vce.ring[1])
v = RREG32(mmVCE_RB_WPTR2);
else
v = RREG32(mmVCE_RB_WPTR3);
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
return v;
}
static void vce_v3_0_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
mutex_lock(&adev->grbm_idx_mutex);
if (adev->vce.harvest_config == 0 ||
adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE1)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(0));
else if (adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE0)
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(1));
if (ring == &adev->vce.ring[0])
WREG32(mmVCE_RB_WPTR, lower_32_bits(ring->wptr));
else if (ring == &adev->vce.ring[1])
WREG32(mmVCE_RB_WPTR2, lower_32_bits(ring->wptr));
else
WREG32(mmVCE_RB_WPTR3, lower_32_bits(ring->wptr));
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
}
static void vce_v3_0_override_vce_clock_gating(struct amdgpu_device *adev, bool override)
{
WREG32_FIELD(VCE_RB_ARB_CTRL, VCE_CGTT_OVERRIDE, override ? 1 : 0);
}
static void vce_v3_0_set_vce_sw_clock_gating(struct amdgpu_device *adev,
bool gated)
{
u32 data;
vce_v3_0_override_vce_clock_gating(adev, true);
if (!gated) {
data = RREG32(mmVCE_CLOCK_GATING_B);
data |= 0x1ff;
data &= ~0xef0000;
WREG32(mmVCE_CLOCK_GATING_B, data);
data = RREG32(mmVCE_UENC_CLOCK_GATING);
data |= 0x3ff000;
data &= ~0xffc00000;
WREG32(mmVCE_UENC_CLOCK_GATING, data);
data = RREG32(mmVCE_UENC_CLOCK_GATING_2);
data |= 0x2;
data &= ~0x00010000;
WREG32(mmVCE_UENC_CLOCK_GATING_2, data);
data = RREG32(mmVCE_UENC_REG_CLOCK_GATING);
data |= 0x37f;
WREG32(mmVCE_UENC_REG_CLOCK_GATING, data);
data = RREG32(mmVCE_UENC_DMA_DCLK_CTRL);
data |= VCE_UENC_DMA_DCLK_CTRL__WRDMCLK_FORCEON_MASK |
VCE_UENC_DMA_DCLK_CTRL__RDDMCLK_FORCEON_MASK |
VCE_UENC_DMA_DCLK_CTRL__REGCLK_FORCEON_MASK |
0x8;
WREG32(mmVCE_UENC_DMA_DCLK_CTRL, data);
} else {
data = RREG32(mmVCE_CLOCK_GATING_B);
data &= ~0x80010;
data |= 0xe70008;
WREG32(mmVCE_CLOCK_GATING_B, data);
data = RREG32(mmVCE_UENC_CLOCK_GATING);
data |= 0xffc00000;
WREG32(mmVCE_UENC_CLOCK_GATING, data);
data = RREG32(mmVCE_UENC_CLOCK_GATING_2);
data |= 0x10000;
WREG32(mmVCE_UENC_CLOCK_GATING_2, data);
data = RREG32(mmVCE_UENC_REG_CLOCK_GATING);
data &= ~0x3ff;
WREG32(mmVCE_UENC_REG_CLOCK_GATING, data);
data = RREG32(mmVCE_UENC_DMA_DCLK_CTRL);
data &= ~(VCE_UENC_DMA_DCLK_CTRL__WRDMCLK_FORCEON_MASK |
VCE_UENC_DMA_DCLK_CTRL__RDDMCLK_FORCEON_MASK |
VCE_UENC_DMA_DCLK_CTRL__REGCLK_FORCEON_MASK |
0x8);
WREG32(mmVCE_UENC_DMA_DCLK_CTRL, data);
}
vce_v3_0_override_vce_clock_gating(adev, false);
}
static int vce_v3_0_firmware_loaded(struct amdgpu_device *adev)
{
int i, j;
for (i = 0; i < 10; ++i) {
for (j = 0; j < 100; ++j) {
uint32_t status = RREG32(mmVCE_STATUS);
if (status & VCE_STATUS_VCPU_REPORT_FW_LOADED_MASK)
return 0;
mdelay(10);
}
DRM_ERROR("VCE not responding, trying to reset the ECPU!!!\n");
WREG32_FIELD(VCE_SOFT_RESET, ECPU_SOFT_RESET, 1);
mdelay(10);
WREG32_FIELD(VCE_SOFT_RESET, ECPU_SOFT_RESET, 0);
mdelay(10);
}
return -ETIMEDOUT;
}
static int vce_v3_0_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
int idx, r;
mutex_lock(&adev->grbm_idx_mutex);
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(idx));
if (idx != 1 || adev->vce.harvest_config == AMDGPU_VCE_HARVEST_VCE0) {
ring = &adev->vce.ring[0];
WREG32(mmVCE_RB_RPTR, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_WPTR, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_BASE_LO, ring->gpu_addr);
WREG32(mmVCE_RB_BASE_HI, upper_32_bits(ring->gpu_addr));
WREG32(mmVCE_RB_SIZE, ring->ring_size / 4);
ring = &adev->vce.ring[1];
WREG32(mmVCE_RB_RPTR2, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_WPTR2, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_BASE_LO2, ring->gpu_addr);
WREG32(mmVCE_RB_BASE_HI2, upper_32_bits(ring->gpu_addr));
WREG32(mmVCE_RB_SIZE2, ring->ring_size / 4);
ring = &adev->vce.ring[2];
WREG32(mmVCE_RB_RPTR3, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_WPTR3, lower_32_bits(ring->wptr));
WREG32(mmVCE_RB_BASE_LO3, ring->gpu_addr);
WREG32(mmVCE_RB_BASE_HI3, upper_32_bits(ring->gpu_addr));
WREG32(mmVCE_RB_SIZE3, ring->ring_size / 4);
}
vce_v3_0_mc_resume(adev, idx);
WREG32_FIELD(VCE_STATUS, JOB_BUSY, 1);
if (adev->asic_type >= CHIP_STONEY)
WREG32_P(mmVCE_VCPU_CNTL, 1, ~0x200001);
else
WREG32_FIELD(VCE_VCPU_CNTL, CLK_EN, 1);
WREG32_FIELD(VCE_SOFT_RESET, ECPU_SOFT_RESET, 0);
mdelay(100);
r = vce_v3_0_firmware_loaded(adev);
WREG32_FIELD(VCE_STATUS, JOB_BUSY, 0);
if (r) {
DRM_ERROR("VCE not responding, giving up!!!\n");
mutex_unlock(&adev->grbm_idx_mutex);
return r;
}
}
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
static int vce_v3_0_stop(struct amdgpu_device *adev)
{
int idx;
mutex_lock(&adev->grbm_idx_mutex);
for (idx = 0; idx < 2; ++idx) {
if (adev->vce.harvest_config & (1 << idx))
continue;
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(idx));
if (adev->asic_type >= CHIP_STONEY)
WREG32_P(mmVCE_VCPU_CNTL, 0, ~0x200001);
else
WREG32_FIELD(VCE_VCPU_CNTL, CLK_EN, 0);
WREG32_FIELD(VCE_SOFT_RESET, ECPU_SOFT_RESET, 1);
WREG32(mmVCE_STATUS, 0);
}
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
static unsigned vce_v3_0_get_harvest_config(struct amdgpu_device *adev)
{
u32 tmp;
if ((adev->asic_type == CHIP_FIJI) ||
(adev->asic_type == CHIP_STONEY) ||
(adev->asic_type == CHIP_POLARIS10) ||
(adev->asic_type == CHIP_POLARIS11) ||
(adev->asic_type == CHIP_POLARIS12))
return AMDGPU_VCE_HARVEST_VCE1;
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
return AMDGPU_VCE_HARVEST_VCE0;
case 2:
return AMDGPU_VCE_HARVEST_VCE1;
case 3:
return AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1;
default:
return 0;
}
}
static int vce_v3_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->vce.harvest_config = vce_v3_0_get_harvest_config(adev);
if ((adev->vce.harvest_config &
(AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1)) ==
(AMDGPU_VCE_HARVEST_VCE0 | AMDGPU_VCE_HARVEST_VCE1))
return -ENOENT;
adev->vce.num_rings = 3;
vce_v3_0_set_ring_funcs(adev);
vce_v3_0_set_irq_funcs(adev);
return 0;
}
static int vce_v3_0_sw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring;
int r, i;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_LEGACY, 167, &adev->vce.irq);
if (r)
return r;
r = amdgpu_vce_sw_init(adev, VCE_V3_0_FW_SIZE +
(VCE_V3_0_STACK_SIZE + VCE_V3_0_DATA_SIZE) * 2);
if (r)
return r;
if (adev->vce.fw_version < FW_52_8_3)
adev->vce.num_rings = 2;
r = amdgpu_vce_resume(adev);
if (r)
return r;
for (i = 0; i < adev->vce.num_rings; i++) {
ring = &adev->vce.ring[i];
sprintf(ring->name, "vce%d", i);
r = amdgpu_ring_init(adev, ring, 512, &adev->vce.irq, 0);
if (r)
return r;
}
return r;
}
static int vce_v3_0_sw_fini(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vce_suspend(adev);
if (r)
return r;
return amdgpu_vce_sw_fini(adev);
}
static int vce_v3_0_hw_init(void *handle)
{
int r, i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vce_v3_0_override_vce_clock_gating(adev, true);
if (!(adev->flags & AMD_IS_APU))
amdgpu_asic_set_vce_clocks(adev, 10000, 10000);
for (i = 0; i < adev->vce.num_rings; i++)
adev->vce.ring[i].ready = false;
for (i = 0; i < adev->vce.num_rings; i++) {
r = amdgpu_ring_test_ring(&adev->vce.ring[i]);
if (r)
return r;
else
adev->vce.ring[i].ready = true;
}
DRM_INFO("VCE initialized successfully.\n");
return 0;
}
static int vce_v3_0_hw_fini(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v3_0_wait_for_idle(handle);
if (r)
return r;
vce_v3_0_stop(adev);
return vce_v3_0_set_clockgating_state(adev, AMD_CG_STATE_GATE);
}
static int vce_v3_0_suspend(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vce_v3_0_hw_fini(adev);
if (r)
return r;
return amdgpu_vce_suspend(adev);
}
static int vce_v3_0_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vce_resume(adev);
if (r)
return r;
return vce_v3_0_hw_init(adev);
}
static void vce_v3_0_mc_resume(struct amdgpu_device *adev, int idx)
{
uint32_t offset, size;
WREG32_P(mmVCE_CLOCK_GATING_A, 0, ~(1 << 16));
WREG32_P(mmVCE_UENC_CLOCK_GATING, 0x1FF000, ~0xFF9FF000);
WREG32_P(mmVCE_UENC_REG_CLOCK_GATING, 0x3F, ~0x3F);
WREG32(mmVCE_CLOCK_GATING_B, 0x1FF);
WREG32(mmVCE_LMI_CTRL, 0x00398000);
WREG32_P(mmVCE_LMI_CACHE_CTRL, 0x0, ~0x1);
WREG32(mmVCE_LMI_SWAP_CNTL, 0);
WREG32(mmVCE_LMI_SWAP_CNTL1, 0);
WREG32(mmVCE_LMI_VM_CTRL, 0);
WREG32_OR(mmVCE_VCPU_CNTL, 0x00100000);
if (adev->asic_type >= CHIP_STONEY) {
WREG32(mmVCE_LMI_VCPU_CACHE_40BIT_BAR0, (adev->vce.gpu_addr >> 8));
WREG32(mmVCE_LMI_VCPU_CACHE_40BIT_BAR1, (adev->vce.gpu_addr >> 8));
WREG32(mmVCE_LMI_VCPU_CACHE_40BIT_BAR2, (adev->vce.gpu_addr >> 8));
} else
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
WREG32_FIELD(VCE_SYS_INT_EN, VCE_SYS_INT_TRAP_INTERRUPT_EN, 1);
}
static bool vce_v3_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 mask = 0;
mask |= (adev->vce.harvest_config & AMDGPU_VCE_HARVEST_VCE0) ? 0 : SRBM_STATUS2__VCE0_BUSY_MASK;
mask |= (adev->vce.harvest_config & AMDGPU_VCE_HARVEST_VCE1) ? 0 : SRBM_STATUS2__VCE1_BUSY_MASK;
return !(RREG32(mmSRBM_STATUS2) & mask);
}
static int vce_v3_0_wait_for_idle(void *handle)
{
unsigned i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++)
if (vce_v3_0_is_idle(handle))
return 0;
return -ETIMEDOUT;
}
static bool vce_v3_0_check_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset = 0;
mutex_lock(&adev->grbm_idx_mutex);
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(0));
if (RREG32(mmVCE_STATUS) & AMDGPU_VCE_STATUS_BUSY_MASK) {
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE0, 1);
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE1, 1);
}
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(1));
if (RREG32(mmVCE_STATUS) & AMDGPU_VCE_STATUS_BUSY_MASK) {
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE0, 1);
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE1, 1);
}
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(0));
mutex_unlock(&adev->grbm_idx_mutex);
if (srbm_soft_reset) {
adev->vce.srbm_soft_reset = srbm_soft_reset;
return true;
} else {
adev->vce.srbm_soft_reset = 0;
return false;
}
}
static int vce_v3_0_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 srbm_soft_reset;
if (!adev->vce.srbm_soft_reset)
return 0;
srbm_soft_reset = adev->vce.srbm_soft_reset;
if (srbm_soft_reset) {
u32 tmp;
tmp = RREG32(mmSRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(adev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
}
return 0;
}
static int vce_v3_0_pre_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (!adev->vce.srbm_soft_reset)
return 0;
mdelay(5);
return vce_v3_0_suspend(adev);
}
static int vce_v3_0_post_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (!adev->vce.srbm_soft_reset)
return 0;
mdelay(5);
return vce_v3_0_resume(adev);
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
WREG32_FIELD(VCE_SYS_INT_STATUS, VCE_SYS_INT_TRAP_INTERRUPT_INT, 1);
switch (entry->src_data[0]) {
case 0:
case 1:
case 2:
amdgpu_fence_process(&adev->vce.ring[entry->src_data[0]]);
break;
default:
DRM_ERROR("Unhandled interrupt: %d %d\n",
entry->src_id, entry->src_data[0]);
break;
}
return 0;
}
static int vce_v3_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
bool enable = (state == AMD_CG_STATE_GATE) ? true : false;
int i;
if (!(adev->cg_flags & AMD_CG_SUPPORT_VCE_MGCG))
return 0;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < 2; i++) {
if (adev->vce.harvest_config & (1 << i))
continue;
WREG32(mmGRBM_GFX_INDEX, GET_VCE_INSTANCE(i));
if (!enable) {
uint32_t data = RREG32(mmVCE_CLOCK_GATING_A);
data &= ~(0xf | 0xff0);
data |= ((0x0 << 0) | (0x04 << 4));
WREG32(mmVCE_CLOCK_GATING_A, data);
data = RREG32(mmVCE_UENC_CLOCK_GATING);
data &= ~(0xf | 0xff0);
data |= ((0x0 << 0) | (0x04 << 4));
WREG32(mmVCE_UENC_CLOCK_GATING, data);
}
vce_v3_0_set_vce_sw_clock_gating(adev, enable);
}
WREG32(mmGRBM_GFX_INDEX, mmGRBM_GFX_INDEX_DEFAULT);
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
static int vce_v3_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int ret = 0;
if (state == AMD_PG_STATE_GATE) {
ret = vce_v3_0_stop(adev);
if (ret)
goto out;
} else {
ret = vce_v3_0_start(adev);
if (ret)
goto out;
}
out:
return ret;
}
static void vce_v3_0_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int data;
mutex_lock(&adev->pm.mutex);
if (adev->flags & AMD_IS_APU)
data = RREG32_SMC(ixCURRENT_PG_STATUS_APU);
else
data = RREG32_SMC(ixCURRENT_PG_STATUS);
if (data & CURRENT_PG_STATUS__VCE_PG_STATUS_MASK) {
DRM_INFO("Cannot get clockgating state when VCE is powergated.\n");
goto out;
}
WREG32_FIELD(GRBM_GFX_INDEX, VCE_INSTANCE, 0);
data = RREG32(mmVCE_CLOCK_GATING_A);
if (data & (0x04 << 4))
*flags |= AMD_CG_SUPPORT_VCE_MGCG;
out:
mutex_unlock(&adev->pm.mutex);
}
static void vce_v3_0_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib, unsigned int vm_id, bool ctx_switch)
{
amdgpu_ring_write(ring, VCE_CMD_IB_VM);
amdgpu_ring_write(ring, vm_id);
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, ib->length_dw);
}
static void vce_v3_0_emit_vm_flush(struct amdgpu_ring *ring,
unsigned int vm_id, uint64_t pd_addr)
{
amdgpu_ring_write(ring, VCE_CMD_UPDATE_PTB);
amdgpu_ring_write(ring, vm_id);
amdgpu_ring_write(ring, pd_addr >> 12);
amdgpu_ring_write(ring, VCE_CMD_FLUSH_TLB);
amdgpu_ring_write(ring, vm_id);
amdgpu_ring_write(ring, VCE_CMD_END);
}
static void vce_v3_0_emit_pipeline_sync(struct amdgpu_ring *ring)
{
uint32_t seq = ring->fence_drv.sync_seq;
uint64_t addr = ring->fence_drv.gpu_addr;
amdgpu_ring_write(ring, VCE_CMD_WAIT_GE);
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, seq);
}
static void vce_v3_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
if (adev->asic_type >= CHIP_STONEY) {
for (i = 0; i < adev->vce.num_rings; i++)
adev->vce.ring[i].funcs = &vce_v3_0_ring_vm_funcs;
DRM_INFO("VCE enabled in VM mode\n");
} else {
for (i = 0; i < adev->vce.num_rings; i++)
adev->vce.ring[i].funcs = &vce_v3_0_ring_phys_funcs;
DRM_INFO("VCE enabled in physical mode\n");
}
}
static void vce_v3_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->vce.irq.num_types = 1;
adev->vce.irq.funcs = &vce_v3_0_irq_funcs;
}
