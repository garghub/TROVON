static uint32_t uvd_v4_2_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
return RREG32(mmUVD_RBC_RB_RPTR);
}
static uint32_t uvd_v4_2_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
return RREG32(mmUVD_RBC_RB_WPTR);
}
static void uvd_v4_2_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
WREG32(mmUVD_RBC_RB_WPTR, ring->wptr);
}
static int uvd_v4_2_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
uvd_v4_2_set_ring_funcs(adev);
uvd_v4_2_set_irq_funcs(adev);
return 0;
}
static int uvd_v4_2_sw_init(void *handle)
{
struct amdgpu_ring *ring;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int r;
r = amdgpu_irq_add_id(adev, 124, &adev->uvd.irq);
if (r)
return r;
r = amdgpu_uvd_sw_init(adev);
if (r)
return r;
r = amdgpu_uvd_resume(adev);
if (r)
return r;
ring = &adev->uvd.ring;
sprintf(ring->name, "uvd");
r = amdgpu_ring_init(adev, ring, 4096, CP_PACKET2, 0xf,
&adev->uvd.irq, 0, AMDGPU_RING_TYPE_UVD);
return r;
}
static int uvd_v4_2_sw_fini(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_uvd_suspend(adev);
if (r)
return r;
r = amdgpu_uvd_sw_fini(adev);
if (r)
return r;
return r;
}
static int uvd_v4_2_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring = &adev->uvd.ring;
uint32_t tmp;
int r;
amdgpu_asic_set_uvd_clocks(adev, 53300, 40000);
r = uvd_v4_2_start(adev);
if (r)
goto done;
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
goto done;
}
r = amdgpu_ring_lock(ring, 10);
if (r) {
DRM_ERROR("amdgpu: ring failed to lock UVD ring (%d).\n", r);
goto done;
}
tmp = PACKET0(mmUVD_SEMA_WAIT_FAULT_TIMEOUT_CNTL, 0);
amdgpu_ring_write(ring, tmp);
amdgpu_ring_write(ring, 0xFFFFF);
tmp = PACKET0(mmUVD_SEMA_WAIT_INCOMPLETE_TIMEOUT_CNTL, 0);
amdgpu_ring_write(ring, tmp);
amdgpu_ring_write(ring, 0xFFFFF);
tmp = PACKET0(mmUVD_SEMA_SIGNAL_INCOMPLETE_TIMEOUT_CNTL, 0);
amdgpu_ring_write(ring, tmp);
amdgpu_ring_write(ring, 0xFFFFF);
amdgpu_ring_write(ring, PACKET0(mmUVD_SEMA_TIMEOUT_STATUS, 0));
amdgpu_ring_write(ring, 0x8);
amdgpu_ring_write(ring, PACKET0(mmUVD_SEMA_CNTL, 0));
amdgpu_ring_write(ring, 3);
amdgpu_ring_unlock_commit(ring);
done:
amdgpu_asic_set_uvd_clocks(adev, 0, 0);
if (!r)
DRM_INFO("UVD initialized successfully.\n");
return r;
}
static int uvd_v4_2_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring = &adev->uvd.ring;
uvd_v4_2_stop(adev);
ring->ready = false;
return 0;
}
static int uvd_v4_2_suspend(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_uvd_suspend(adev);
if (r)
return r;
r = uvd_v4_2_hw_fini(adev);
if (r)
return r;
return r;
}
static int uvd_v4_2_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_uvd_resume(adev);
if (r)
return r;
r = uvd_v4_2_hw_init(adev);
if (r)
return r;
return r;
}
static int uvd_v4_2_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->uvd.ring;
uint32_t rb_bufsz;
int i, j, r;
u32 lmi_swap_cntl = 0;
u32 mp_swap_cntl = 0;
uvd_v4_2_mc_resume(adev);
WREG32(mmUVD_CGC_GATE, 0);
WREG32_P(mmUVD_MASTINT_EN, 0, ~(1 << 1));
WREG32_P(mmUVD_LMI_CTRL2, 1 << 8, ~(1 << 8));
mdelay(1);
WREG32(mmUVD_SOFT_RESET, UVD_SOFT_RESET__LMI_SOFT_RESET_MASK |
UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK | UVD_SOFT_RESET__LBSI_SOFT_RESET_MASK |
UVD_SOFT_RESET__RBC_SOFT_RESET_MASK | UVD_SOFT_RESET__CSM_SOFT_RESET_MASK |
UVD_SOFT_RESET__CXW_SOFT_RESET_MASK | UVD_SOFT_RESET__TAP_SOFT_RESET_MASK |
UVD_SOFT_RESET__LMI_UMC_SOFT_RESET_MASK);
mdelay(5);
WREG32_P(mmSRBM_SOFT_RESET, 0, ~SRBM_SOFT_RESET__SOFT_RESET_UVD_MASK);
mdelay(5);
WREG32(mmUVD_LMI_CTRL, 0x40 | (1 << 8) | (1 << 13) |
(1 << 21) | (1 << 9) | (1 << 20));
#ifdef __BIG_ENDIAN
lmi_swap_cntl = 0xa;
mp_swap_cntl = 0;
#endif
WREG32(mmUVD_LMI_SWAP_CNTL, lmi_swap_cntl);
WREG32(mmUVD_MP_SWAP_CNTL, mp_swap_cntl);
WREG32(mmUVD_MPC_SET_MUXA0, 0x40c2040);
WREG32(mmUVD_MPC_SET_MUXA1, 0x0);
WREG32(mmUVD_MPC_SET_MUXB0, 0x40c2040);
WREG32(mmUVD_MPC_SET_MUXB1, 0x0);
WREG32(mmUVD_MPC_SET_ALU, 0);
WREG32(mmUVD_MPC_SET_MUX, 0x88);
WREG32(mmUVD_SOFT_RESET, UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(5);
WREG32(mmUVD_VCPU_CNTL, 1 << 9);
WREG32_P(mmUVD_LMI_CTRL2, 0, ~(1 << 8));
WREG32(mmUVD_SOFT_RESET, 0);
mdelay(10);
for (i = 0; i < 10; ++i) {
uint32_t status;
for (j = 0; j < 100; ++j) {
status = RREG32(mmUVD_STATUS);
if (status & 2)
break;
mdelay(10);
}
r = 0;
if (status & 2)
break;
DRM_ERROR("UVD not responding, trying to reset the VCPU!!!\n");
WREG32_P(mmUVD_SOFT_RESET, UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK,
~UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(10);
WREG32_P(mmUVD_SOFT_RESET, 0, ~UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(10);
r = -1;
}
if (r) {
DRM_ERROR("UVD not responding, giving up!!!\n");
return r;
}
WREG32_P(mmUVD_MASTINT_EN, 3<<1, ~(3 << 1));
WREG32(mmUVD_RBC_RB_CNTL, 0x11010101);
WREG32(mmUVD_RBC_RB_WPTR_CNTL, 0);
WREG32(mmUVD_LMI_EXT40_ADDR, upper_32_bits(ring->gpu_addr) |
(0x7 << 16) | (0x1 << 31));
WREG32(mmUVD_RBC_RB_RPTR, 0x0);
ring->wptr = RREG32(mmUVD_RBC_RB_RPTR);
WREG32(mmUVD_RBC_RB_WPTR, ring->wptr);
WREG32(mmUVD_RBC_RB_BASE, ring->gpu_addr);
rb_bufsz = order_base_2(ring->ring_size);
rb_bufsz = (0x1 << 8) | rb_bufsz;
WREG32_P(mmUVD_RBC_RB_CNTL, rb_bufsz, ~0x11f1f);
return 0;
}
static void uvd_v4_2_stop(struct amdgpu_device *adev)
{
WREG32(mmUVD_RBC_RB_CNTL, 0x11010101);
WREG32_P(mmUVD_LMI_CTRL2, 1 << 8, ~(1 << 8));
mdelay(1);
WREG32(mmUVD_SOFT_RESET, UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(5);
WREG32(mmUVD_VCPU_CNTL, 0x0);
WREG32_P(mmUVD_LMI_CTRL2, 0, ~(1 << 8));
}
static void uvd_v4_2_ring_emit_fence(struct amdgpu_ring *ring, u64 addr, u64 seq,
unsigned flags)
{
WARN_ON(flags & AMDGPU_FENCE_FLAG_64BIT);
amdgpu_ring_write(ring, PACKET0(mmUVD_CONTEXT_ID, 0));
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_DATA0, 0));
amdgpu_ring_write(ring, addr & 0xffffffff);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_DATA1, 0));
amdgpu_ring_write(ring, upper_32_bits(addr) & 0xff);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_CMD, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_DATA0, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_DATA1, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET0(mmUVD_GPCOM_VCPU_CMD, 0));
amdgpu_ring_write(ring, 2);
}
static bool uvd_v4_2_ring_emit_semaphore(struct amdgpu_ring *ring,
struct amdgpu_semaphore *semaphore,
bool emit_wait)
{
uint64_t addr = semaphore->gpu_addr;
amdgpu_ring_write(ring, PACKET0(mmUVD_SEMA_ADDR_LOW, 0));
amdgpu_ring_write(ring, (addr >> 3) & 0x000FFFFF);
amdgpu_ring_write(ring, PACKET0(mmUVD_SEMA_ADDR_HIGH, 0));
amdgpu_ring_write(ring, (addr >> 23) & 0x000FFFFF);
amdgpu_ring_write(ring, PACKET0(mmUVD_SEMA_CMD, 0));
amdgpu_ring_write(ring, 0x80 | (emit_wait ? 1 : 0));
return true;
}
static int uvd_v4_2_ring_test_ring(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
uint32_t tmp = 0;
unsigned i;
int r;
WREG32(mmUVD_CONTEXT_ID, 0xCAFEDEAD);
r = amdgpu_ring_lock(ring, 3);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring %d (%d).\n",
ring->idx, r);
return r;
}
amdgpu_ring_write(ring, PACKET0(mmUVD_CONTEXT_ID, 0));
amdgpu_ring_write(ring, 0xDEADBEEF);
amdgpu_ring_unlock_commit(ring);
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(mmUVD_CONTEXT_ID);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n",
ring->idx, i);
} else {
DRM_ERROR("amdgpu: ring %d test failed (0x%08X)\n",
ring->idx, tmp);
r = -EINVAL;
}
return r;
}
static void uvd_v4_2_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib)
{
amdgpu_ring_write(ring, PACKET0(mmUVD_RBC_IB_BASE, 0));
amdgpu_ring_write(ring, ib->gpu_addr);
amdgpu_ring_write(ring, PACKET0(mmUVD_RBC_IB_SIZE, 0));
amdgpu_ring_write(ring, ib->length_dw);
}
static int uvd_v4_2_ring_test_ib(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
struct fence *fence = NULL;
int r;
r = amdgpu_asic_set_uvd_clocks(adev, 53300, 40000);
if (r) {
DRM_ERROR("amdgpu: failed to raise UVD clocks (%d).\n", r);
return r;
}
r = amdgpu_uvd_get_create_msg(ring, 1, NULL);
if (r) {
DRM_ERROR("amdgpu: failed to get create msg (%d).\n", r);
goto error;
}
r = amdgpu_uvd_get_destroy_msg(ring, 1, &fence);
if (r) {
DRM_ERROR("amdgpu: failed to get destroy ib (%d).\n", r);
goto error;
}
r = fence_wait(fence, false);
if (r) {
DRM_ERROR("amdgpu: fence wait failed (%d).\n", r);
goto error;
}
DRM_INFO("ib test on ring %d succeeded\n", ring->idx);
error:
fence_put(fence);
amdgpu_asic_set_uvd_clocks(adev, 0, 0);
return r;
}
static void uvd_v4_2_mc_resume(struct amdgpu_device *adev)
{
uint64_t addr;
uint32_t size;
addr = (adev->uvd.gpu_addr + AMDGPU_UVD_FIRMWARE_OFFSET) >> 3;
size = AMDGPU_GPU_PAGE_ALIGN(adev->uvd.fw->size + 4) >> 3;
WREG32(mmUVD_VCPU_CACHE_OFFSET0, addr);
WREG32(mmUVD_VCPU_CACHE_SIZE0, size);
addr += size;
size = AMDGPU_UVD_STACK_SIZE >> 3;
WREG32(mmUVD_VCPU_CACHE_OFFSET1, addr);
WREG32(mmUVD_VCPU_CACHE_SIZE1, size);
addr += size;
size = AMDGPU_UVD_HEAP_SIZE >> 3;
WREG32(mmUVD_VCPU_CACHE_OFFSET2, addr);
WREG32(mmUVD_VCPU_CACHE_SIZE2, size);
addr = (adev->uvd.gpu_addr >> 28) & 0xF;
WREG32(mmUVD_LMI_ADDR_EXT, (addr << 12) | (addr << 0));
addr = (adev->uvd.gpu_addr >> 32) & 0xFF;
WREG32(mmUVD_LMI_EXT40_ADDR, addr | (0x9 << 16) | (0x1 << 31));
uvd_v4_2_init_cg(adev);
}
static void uvd_v4_2_enable_mgcg(struct amdgpu_device *adev,
bool enable)
{
u32 orig, data;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_UVD_MGCG)) {
data = RREG32_UVD_CTX(ixUVD_CGC_MEM_CTRL);
data = 0xfff;
WREG32_UVD_CTX(ixUVD_CGC_MEM_CTRL, data);
orig = data = RREG32(mmUVD_CGC_CTRL);
data |= UVD_CGC_CTRL__DYN_CLOCK_MODE_MASK;
if (orig != data)
WREG32(mmUVD_CGC_CTRL, data);
} else {
data = RREG32_UVD_CTX(ixUVD_CGC_MEM_CTRL);
data &= ~0xfff;
WREG32_UVD_CTX(ixUVD_CGC_MEM_CTRL, data);
orig = data = RREG32(mmUVD_CGC_CTRL);
data &= ~UVD_CGC_CTRL__DYN_CLOCK_MODE_MASK;
if (orig != data)
WREG32(mmUVD_CGC_CTRL, data);
}
}
static void uvd_v4_2_set_dcm(struct amdgpu_device *adev,
bool sw_mode)
{
u32 tmp, tmp2;
tmp = RREG32(mmUVD_CGC_CTRL);
tmp &= ~(UVD_CGC_CTRL__CLK_OFF_DELAY_MASK | UVD_CGC_CTRL__CLK_GATE_DLY_TIMER_MASK);
tmp |= UVD_CGC_CTRL__DYN_CLOCK_MODE_MASK |
(1 << UVD_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT) |
(4 << UVD_CGC_CTRL__CLK_OFF_DELAY__SHIFT);
if (sw_mode) {
tmp &= ~0x7ffff800;
tmp2 = UVD_CGC_CTRL2__DYN_OCLK_RAMP_EN_MASK |
UVD_CGC_CTRL2__DYN_RCLK_RAMP_EN_MASK |
(7 << UVD_CGC_CTRL2__GATER_DIV_ID__SHIFT);
} else {
tmp |= 0x7ffff800;
tmp2 = 0;
}
WREG32(mmUVD_CGC_CTRL, tmp);
WREG32_UVD_CTX(ixUVD_CGC_CTRL2, tmp2);
}
static void uvd_v4_2_init_cg(struct amdgpu_device *adev)
{
bool hw_mode = true;
if (hw_mode) {
uvd_v4_2_set_dcm(adev, false);
} else {
u32 tmp = RREG32(mmUVD_CGC_CTRL);
tmp &= ~UVD_CGC_CTRL__DYN_CLOCK_MODE_MASK;
WREG32(mmUVD_CGC_CTRL, tmp);
}
}
static bool uvd_v4_2_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return !(RREG32(mmSRBM_STATUS) & SRBM_STATUS__UVD_BUSY_MASK);
}
static int uvd_v4_2_wait_for_idle(void *handle)
{
unsigned i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
if (!(RREG32(mmSRBM_STATUS) & SRBM_STATUS__UVD_BUSY_MASK))
return 0;
}
return -ETIMEDOUT;
}
static int uvd_v4_2_soft_reset(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
uvd_v4_2_stop(adev);
WREG32_P(mmSRBM_SOFT_RESET, SRBM_SOFT_RESET__SOFT_RESET_UVD_MASK,
~SRBM_SOFT_RESET__SOFT_RESET_UVD_MASK);
mdelay(5);
return uvd_v4_2_start(adev);
}
static void uvd_v4_2_print_status(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
dev_info(adev->dev, "UVD 4.2 registers\n");
dev_info(adev->dev, " UVD_SEMA_ADDR_LOW=0x%08X\n",
RREG32(mmUVD_SEMA_ADDR_LOW));
dev_info(adev->dev, " UVD_SEMA_ADDR_HIGH=0x%08X\n",
RREG32(mmUVD_SEMA_ADDR_HIGH));
dev_info(adev->dev, " UVD_SEMA_CMD=0x%08X\n",
RREG32(mmUVD_SEMA_CMD));
dev_info(adev->dev, " UVD_GPCOM_VCPU_CMD=0x%08X\n",
RREG32(mmUVD_GPCOM_VCPU_CMD));
dev_info(adev->dev, " UVD_GPCOM_VCPU_DATA0=0x%08X\n",
RREG32(mmUVD_GPCOM_VCPU_DATA0));
dev_info(adev->dev, " UVD_GPCOM_VCPU_DATA1=0x%08X\n",
RREG32(mmUVD_GPCOM_VCPU_DATA1));
dev_info(adev->dev, " UVD_ENGINE_CNTL=0x%08X\n",
RREG32(mmUVD_ENGINE_CNTL));
dev_info(adev->dev, " UVD_UDEC_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_ADDR_CONFIG));
dev_info(adev->dev, " UVD_UDEC_DB_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_DB_ADDR_CONFIG));
dev_info(adev->dev, " UVD_UDEC_DBW_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_DBW_ADDR_CONFIG));
dev_info(adev->dev, " UVD_SEMA_CNTL=0x%08X\n",
RREG32(mmUVD_SEMA_CNTL));
dev_info(adev->dev, " UVD_LMI_EXT40_ADDR=0x%08X\n",
RREG32(mmUVD_LMI_EXT40_ADDR));
dev_info(adev->dev, " UVD_CTX_INDEX=0x%08X\n",
RREG32(mmUVD_CTX_INDEX));
dev_info(adev->dev, " UVD_CTX_DATA=0x%08X\n",
RREG32(mmUVD_CTX_DATA));
dev_info(adev->dev, " UVD_CGC_GATE=0x%08X\n",
RREG32(mmUVD_CGC_GATE));
dev_info(adev->dev, " UVD_CGC_CTRL=0x%08X\n",
RREG32(mmUVD_CGC_CTRL));
dev_info(adev->dev, " UVD_LMI_CTRL2=0x%08X\n",
RREG32(mmUVD_LMI_CTRL2));
dev_info(adev->dev, " UVD_MASTINT_EN=0x%08X\n",
RREG32(mmUVD_MASTINT_EN));
dev_info(adev->dev, " UVD_LMI_ADDR_EXT=0x%08X\n",
RREG32(mmUVD_LMI_ADDR_EXT));
dev_info(adev->dev, " UVD_LMI_CTRL=0x%08X\n",
RREG32(mmUVD_LMI_CTRL));
dev_info(adev->dev, " UVD_LMI_SWAP_CNTL=0x%08X\n",
RREG32(mmUVD_LMI_SWAP_CNTL));
dev_info(adev->dev, " UVD_MP_SWAP_CNTL=0x%08X\n",
RREG32(mmUVD_MP_SWAP_CNTL));
dev_info(adev->dev, " UVD_MPC_SET_MUXA0=0x%08X\n",
RREG32(mmUVD_MPC_SET_MUXA0));
dev_info(adev->dev, " UVD_MPC_SET_MUXA1=0x%08X\n",
RREG32(mmUVD_MPC_SET_MUXA1));
dev_info(adev->dev, " UVD_MPC_SET_MUXB0=0x%08X\n",
RREG32(mmUVD_MPC_SET_MUXB0));
dev_info(adev->dev, " UVD_MPC_SET_MUXB1=0x%08X\n",
RREG32(mmUVD_MPC_SET_MUXB1));
dev_info(adev->dev, " UVD_MPC_SET_MUX=0x%08X\n",
RREG32(mmUVD_MPC_SET_MUX));
dev_info(adev->dev, " UVD_MPC_SET_ALU=0x%08X\n",
RREG32(mmUVD_MPC_SET_ALU));
dev_info(adev->dev, " UVD_VCPU_CACHE_OFFSET0=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_OFFSET0));
dev_info(adev->dev, " UVD_VCPU_CACHE_SIZE0=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_SIZE0));
dev_info(adev->dev, " UVD_VCPU_CACHE_OFFSET1=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_OFFSET1));
dev_info(adev->dev, " UVD_VCPU_CACHE_SIZE1=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_SIZE1));
dev_info(adev->dev, " UVD_VCPU_CACHE_OFFSET2=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_OFFSET2));
dev_info(adev->dev, " UVD_VCPU_CACHE_SIZE2=0x%08X\n",
RREG32(mmUVD_VCPU_CACHE_SIZE2));
dev_info(adev->dev, " UVD_VCPU_CNTL=0x%08X\n",
RREG32(mmUVD_VCPU_CNTL));
dev_info(adev->dev, " UVD_SOFT_RESET=0x%08X\n",
RREG32(mmUVD_SOFT_RESET));
dev_info(adev->dev, " UVD_RBC_IB_BASE=0x%08X\n",
RREG32(mmUVD_RBC_IB_BASE));
dev_info(adev->dev, " UVD_RBC_IB_SIZE=0x%08X\n",
RREG32(mmUVD_RBC_IB_SIZE));
dev_info(adev->dev, " UVD_RBC_RB_BASE=0x%08X\n",
RREG32(mmUVD_RBC_RB_BASE));
dev_info(adev->dev, " UVD_RBC_RB_RPTR=0x%08X\n",
RREG32(mmUVD_RBC_RB_RPTR));
dev_info(adev->dev, " UVD_RBC_RB_WPTR=0x%08X\n",
RREG32(mmUVD_RBC_RB_WPTR));
dev_info(adev->dev, " UVD_RBC_RB_WPTR_CNTL=0x%08X\n",
RREG32(mmUVD_RBC_RB_WPTR_CNTL));
dev_info(adev->dev, " UVD_RBC_RB_CNTL=0x%08X\n",
RREG32(mmUVD_RBC_RB_CNTL));
dev_info(adev->dev, " UVD_STATUS=0x%08X\n",
RREG32(mmUVD_STATUS));
dev_info(adev->dev, " UVD_SEMA_TIMEOUT_STATUS=0x%08X\n",
RREG32(mmUVD_SEMA_TIMEOUT_STATUS));
dev_info(adev->dev, " UVD_SEMA_WAIT_INCOMPLETE_TIMEOUT_CNTL=0x%08X\n",
RREG32(mmUVD_SEMA_WAIT_INCOMPLETE_TIMEOUT_CNTL));
dev_info(adev->dev, " UVD_SEMA_WAIT_FAULT_TIMEOUT_CNTL=0x%08X\n",
RREG32(mmUVD_SEMA_WAIT_FAULT_TIMEOUT_CNTL));
dev_info(adev->dev, " UVD_SEMA_SIGNAL_INCOMPLETE_TIMEOUT_CNTL=0x%08X\n",
RREG32(mmUVD_SEMA_SIGNAL_INCOMPLETE_TIMEOUT_CNTL));
dev_info(adev->dev, " UVD_CONTEXT_ID=0x%08X\n",
RREG32(mmUVD_CONTEXT_ID));
}
static int uvd_v4_2_set_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
return 0;
}
static int uvd_v4_2_process_interrupt(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_DEBUG("IH: UVD TRAP\n");
amdgpu_fence_process(&adev->uvd.ring);
return 0;
}
static int uvd_v4_2_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
bool gate = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (!(adev->cg_flags & AMD_CG_SUPPORT_UVD_MGCG))
return 0;
if (state == AMD_CG_STATE_GATE)
gate = true;
uvd_v4_2_enable_mgcg(adev, gate);
return 0;
}
static int uvd_v4_2_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (!(adev->pg_flags & AMD_PG_SUPPORT_UVD))
return 0;
if (state == AMD_PG_STATE_GATE) {
uvd_v4_2_stop(adev);
return 0;
} else {
return uvd_v4_2_start(adev);
}
}
static void uvd_v4_2_set_ring_funcs(struct amdgpu_device *adev)
{
adev->uvd.ring.funcs = &uvd_v4_2_ring_funcs;
}
static void uvd_v4_2_set_irq_funcs(struct amdgpu_device *adev)
{
adev->uvd.irq.num_types = 1;
adev->uvd.irq.funcs = &uvd_v4_2_irq_funcs;
}
