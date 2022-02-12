static int vcn_v1_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->vcn.num_enc_rings = 2;
vcn_v1_0_set_dec_ring_funcs(adev);
vcn_v1_0_set_enc_ring_funcs(adev);
vcn_v1_0_set_irq_funcs(adev);
return 0;
}
static int vcn_v1_0_sw_init(void *handle)
{
struct amdgpu_ring *ring;
int i, r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_VCN, 124, &adev->vcn.irq);
if (r)
return r;
for (i = 0; i < adev->vcn.num_enc_rings; ++i) {
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_VCN, i + 119,
&adev->vcn.irq);
if (r)
return r;
}
r = amdgpu_vcn_sw_init(adev);
if (r)
return r;
r = amdgpu_vcn_resume(adev);
if (r)
return r;
ring = &adev->vcn.ring_dec;
sprintf(ring->name, "vcn_dec");
r = amdgpu_ring_init(adev, ring, 512, &adev->vcn.irq, 0);
if (r)
return r;
for (i = 0; i < adev->vcn.num_enc_rings; ++i) {
ring = &adev->vcn.ring_enc[i];
sprintf(ring->name, "vcn_enc%d", i);
r = amdgpu_ring_init(adev, ring, 512, &adev->vcn.irq, 0);
if (r)
return r;
}
return r;
}
static int vcn_v1_0_sw_fini(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vcn_suspend(adev);
if (r)
return r;
r = amdgpu_vcn_sw_fini(adev);
return r;
}
static int vcn_v1_0_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring = &adev->vcn.ring_dec;
int i, r;
r = vcn_v1_0_start(adev);
if (r)
goto done;
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
goto done;
}
for (i = 0; i < adev->vcn.num_enc_rings; ++i) {
ring = &adev->vcn.ring_enc[i];
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
goto done;
}
}
done:
if (!r)
DRM_INFO("VCN decode and encode initialized successfully.\n");
return r;
}
static int vcn_v1_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
struct amdgpu_ring *ring = &adev->vcn.ring_dec;
int r;
r = vcn_v1_0_stop(adev);
if (r)
return r;
ring->ready = false;
return 0;
}
static int vcn_v1_0_suspend(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vcn_v1_0_hw_fini(adev);
if (r)
return r;
r = amdgpu_vcn_suspend(adev);
return r;
}
static int vcn_v1_0_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_vcn_resume(adev);
if (r)
return r;
r = vcn_v1_0_hw_init(adev);
return r;
}
static void vcn_v1_0_mc_resume(struct amdgpu_device *adev)
{
uint32_t size = AMDGPU_GPU_PAGE_ALIGN(adev->vcn.fw->size + 4);
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE_64BIT_BAR_LOW,
lower_32_bits(adev->vcn.gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE_64BIT_BAR_HIGH,
upper_32_bits(adev->vcn.gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_OFFSET0,
AMDGPU_UVD_FIRMWARE_OFFSET >> 3);
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_SIZE0, size);
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE1_64BIT_BAR_LOW,
lower_32_bits(adev->vcn.gpu_addr + size));
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE1_64BIT_BAR_HIGH,
upper_32_bits(adev->vcn.gpu_addr + size));
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_OFFSET1, 0);
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_SIZE1, AMDGPU_VCN_HEAP_SIZE);
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE2_64BIT_BAR_LOW,
lower_32_bits(adev->vcn.gpu_addr + size + AMDGPU_VCN_HEAP_SIZE));
WREG32_SOC15(UVD, 0, mmUVD_LMI_VCPU_CACHE2_64BIT_BAR_HIGH,
upper_32_bits(adev->vcn.gpu_addr + size + AMDGPU_VCN_HEAP_SIZE));
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_OFFSET2, 0);
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CACHE_SIZE2,
AMDGPU_VCN_STACK_SIZE + (AMDGPU_VCN_SESSION_SIZE * 40));
WREG32_SOC15(UVD, 0, mmUVD_UDEC_ADDR_CONFIG,
adev->gfx.config.gb_addr_config);
WREG32_SOC15(UVD, 0, mmUVD_UDEC_DB_ADDR_CONFIG,
adev->gfx.config.gb_addr_config);
WREG32_SOC15(UVD, 0, mmUVD_UDEC_DBW_ADDR_CONFIG,
adev->gfx.config.gb_addr_config);
}
static void vcn_v1_0_disable_clock_gating(struct amdgpu_device *adev, bool sw)
{
uint32_t data;
data = RREG32_SOC15(VCN, 0, mmJPEG_CGC_CTRL);
if (sw)
data |= 1 << JPEG_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
else
data &= ~JPEG_CGC_CTRL__DYN_CLOCK_MODE_MASK;
data |= 1 << JPEG_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT;
data |= 4 << JPEG_CGC_CTRL__CLK_OFF_DELAY__SHIFT;
WREG32_SOC15(VCN, 0, mmJPEG_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmJPEG_CGC_GATE);
data &= ~(JPEG_CGC_GATE__JPEG_MASK | JPEG_CGC_GATE__JPEG2_MASK);
WREG32_SOC15(VCN, 0, mmJPEG_CGC_GATE, data);
data = RREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL);
if (sw)
data |= 1 << UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
else
data &= ~ UVD_CGC_CTRL__DYN_CLOCK_MODE_MASK;
data |= 1 << UVD_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT;
data |= 4 << UVD_CGC_CTRL__CLK_OFF_DELAY__SHIFT;
WREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmUVD_CGC_GATE);
data &= ~(UVD_CGC_GATE__SYS_MASK
| UVD_CGC_GATE__UDEC_MASK
| UVD_CGC_GATE__MPEG2_MASK
| UVD_CGC_GATE__REGS_MASK
| UVD_CGC_GATE__RBC_MASK
| UVD_CGC_GATE__LMI_MC_MASK
| UVD_CGC_GATE__LMI_UMC_MASK
| UVD_CGC_GATE__IDCT_MASK
| UVD_CGC_GATE__MPRD_MASK
| UVD_CGC_GATE__MPC_MASK
| UVD_CGC_GATE__LBSI_MASK
| UVD_CGC_GATE__LRBBM_MASK
| UVD_CGC_GATE__UDEC_RE_MASK
| UVD_CGC_GATE__UDEC_CM_MASK
| UVD_CGC_GATE__UDEC_IT_MASK
| UVD_CGC_GATE__UDEC_DB_MASK
| UVD_CGC_GATE__UDEC_MP_MASK
| UVD_CGC_GATE__WCB_MASK
| UVD_CGC_GATE__VCPU_MASK
| UVD_CGC_GATE__SCPU_MASK);
WREG32_SOC15(VCN, 0, mmUVD_CGC_GATE, data);
data = RREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL);
data &= ~(UVD_CGC_CTRL__UDEC_RE_MODE_MASK
| UVD_CGC_CTRL__UDEC_CM_MODE_MASK
| UVD_CGC_CTRL__UDEC_IT_MODE_MASK
| UVD_CGC_CTRL__UDEC_DB_MODE_MASK
| UVD_CGC_CTRL__UDEC_MP_MODE_MASK
| UVD_CGC_CTRL__SYS_MODE_MASK
| UVD_CGC_CTRL__UDEC_MODE_MASK
| UVD_CGC_CTRL__MPEG2_MODE_MASK
| UVD_CGC_CTRL__REGS_MODE_MASK
| UVD_CGC_CTRL__RBC_MODE_MASK
| UVD_CGC_CTRL__LMI_MC_MODE_MASK
| UVD_CGC_CTRL__LMI_UMC_MODE_MASK
| UVD_CGC_CTRL__IDCT_MODE_MASK
| UVD_CGC_CTRL__MPRD_MODE_MASK
| UVD_CGC_CTRL__MPC_MODE_MASK
| UVD_CGC_CTRL__LBSI_MODE_MASK
| UVD_CGC_CTRL__LRBBM_MODE_MASK
| UVD_CGC_CTRL__WCB_MODE_MASK
| UVD_CGC_CTRL__VCPU_MODE_MASK
| UVD_CGC_CTRL__SCPU_MODE_MASK);
WREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_GATE);
data |= (UVD_SUVD_CGC_GATE__SRE_MASK
| UVD_SUVD_CGC_GATE__SIT_MASK
| UVD_SUVD_CGC_GATE__SMP_MASK
| UVD_SUVD_CGC_GATE__SCM_MASK
| UVD_SUVD_CGC_GATE__SDB_MASK
| UVD_SUVD_CGC_GATE__SRE_H264_MASK
| UVD_SUVD_CGC_GATE__SRE_HEVC_MASK
| UVD_SUVD_CGC_GATE__SIT_H264_MASK
| UVD_SUVD_CGC_GATE__SIT_HEVC_MASK
| UVD_SUVD_CGC_GATE__SCM_H264_MASK
| UVD_SUVD_CGC_GATE__SCM_HEVC_MASK
| UVD_SUVD_CGC_GATE__SDB_H264_MASK
| UVD_SUVD_CGC_GATE__SDB_HEVC_MASK
| UVD_SUVD_CGC_GATE__SCLR_MASK
| UVD_SUVD_CGC_GATE__UVD_SC_MASK
| UVD_SUVD_CGC_GATE__ENT_MASK
| UVD_SUVD_CGC_GATE__SIT_HEVC_DEC_MASK
| UVD_SUVD_CGC_GATE__SIT_HEVC_ENC_MASK
| UVD_SUVD_CGC_GATE__SITE_MASK
| UVD_SUVD_CGC_GATE__SRE_VP9_MASK
| UVD_SUVD_CGC_GATE__SCM_VP9_MASK
| UVD_SUVD_CGC_GATE__SIT_VP9_DEC_MASK
| UVD_SUVD_CGC_GATE__SDB_VP9_MASK
| UVD_SUVD_CGC_GATE__IME_HEVC_MASK);
WREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_GATE, data);
data = RREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_CTRL);
data &= ~(UVD_SUVD_CGC_CTRL__SRE_MODE_MASK
| UVD_SUVD_CGC_CTRL__SIT_MODE_MASK
| UVD_SUVD_CGC_CTRL__SMP_MODE_MASK
| UVD_SUVD_CGC_CTRL__SCM_MODE_MASK
| UVD_SUVD_CGC_CTRL__SDB_MODE_MASK
| UVD_SUVD_CGC_CTRL__SCLR_MODE_MASK
| UVD_SUVD_CGC_CTRL__UVD_SC_MODE_MASK
| UVD_SUVD_CGC_CTRL__ENT_MODE_MASK
| UVD_SUVD_CGC_CTRL__IME_MODE_MASK
| UVD_SUVD_CGC_CTRL__SITE_MODE_MASK);
WREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_CTRL, data);
}
static void vcn_v1_0_enable_clock_gating(struct amdgpu_device *adev, bool sw)
{
uint32_t data = 0;
data = RREG32_SOC15(VCN, 0, mmJPEG_CGC_CTRL);
if (sw)
data |= 1 << JPEG_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
else
data |= 0 << JPEG_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
data |= 1 << JPEG_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT;
data |= 4 << JPEG_CGC_CTRL__CLK_OFF_DELAY__SHIFT;
WREG32_SOC15(VCN, 0, mmJPEG_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmJPEG_CGC_GATE);
data |= (JPEG_CGC_GATE__JPEG_MASK | JPEG_CGC_GATE__JPEG2_MASK);
WREG32_SOC15(VCN, 0, mmJPEG_CGC_GATE, data);
data = RREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL);
if (sw)
data |= 1 << UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
else
data |= 0 << UVD_CGC_CTRL__DYN_CLOCK_MODE__SHIFT;
data |= 1 << UVD_CGC_CTRL__CLK_GATE_DLY_TIMER__SHIFT;
data |= 4 << UVD_CGC_CTRL__CLK_OFF_DELAY__SHIFT;
WREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL);
data |= (UVD_CGC_CTRL__UDEC_RE_MODE_MASK
| UVD_CGC_CTRL__UDEC_CM_MODE_MASK
| UVD_CGC_CTRL__UDEC_IT_MODE_MASK
| UVD_CGC_CTRL__UDEC_DB_MODE_MASK
| UVD_CGC_CTRL__UDEC_MP_MODE_MASK
| UVD_CGC_CTRL__SYS_MODE_MASK
| UVD_CGC_CTRL__UDEC_MODE_MASK
| UVD_CGC_CTRL__MPEG2_MODE_MASK
| UVD_CGC_CTRL__REGS_MODE_MASK
| UVD_CGC_CTRL__RBC_MODE_MASK
| UVD_CGC_CTRL__LMI_MC_MODE_MASK
| UVD_CGC_CTRL__LMI_UMC_MODE_MASK
| UVD_CGC_CTRL__IDCT_MODE_MASK
| UVD_CGC_CTRL__MPRD_MODE_MASK
| UVD_CGC_CTRL__MPC_MODE_MASK
| UVD_CGC_CTRL__LBSI_MODE_MASK
| UVD_CGC_CTRL__LRBBM_MODE_MASK
| UVD_CGC_CTRL__WCB_MODE_MASK
| UVD_CGC_CTRL__VCPU_MODE_MASK
| UVD_CGC_CTRL__SCPU_MODE_MASK);
WREG32_SOC15(VCN, 0, mmUVD_CGC_CTRL, data);
data = RREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_CTRL);
data |= (UVD_SUVD_CGC_CTRL__SRE_MODE_MASK
| UVD_SUVD_CGC_CTRL__SIT_MODE_MASK
| UVD_SUVD_CGC_CTRL__SMP_MODE_MASK
| UVD_SUVD_CGC_CTRL__SCM_MODE_MASK
| UVD_SUVD_CGC_CTRL__SDB_MODE_MASK
| UVD_SUVD_CGC_CTRL__SCLR_MODE_MASK
| UVD_SUVD_CGC_CTRL__UVD_SC_MODE_MASK
| UVD_SUVD_CGC_CTRL__ENT_MODE_MASK
| UVD_SUVD_CGC_CTRL__IME_MODE_MASK
| UVD_SUVD_CGC_CTRL__SITE_MODE_MASK);
WREG32_SOC15(VCN, 0, mmUVD_SUVD_CGC_CTRL, data);
}
static int vcn_v1_0_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->vcn.ring_dec;
uint32_t rb_bufsz, tmp;
uint32_t lmi_swap_cntl;
int i, j, r;
lmi_swap_cntl = 0;
vcn_v1_0_mc_resume(adev);
vcn_v1_0_disable_clock_gating(adev, true);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_MASTINT_EN), 0,
~UVD_MASTINT_EN__VCPU_EN_MASK);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_CTRL2),
UVD_LMI_CTRL2__STALL_ARB_UMC_MASK,
~UVD_LMI_CTRL2__STALL_ARB_UMC_MASK);
mdelay(1);
WREG32_SOC15(UVD, 0, mmUVD_SOFT_RESET,
UVD_SOFT_RESET__LMI_SOFT_RESET_MASK |
UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK |
UVD_SOFT_RESET__LBSI_SOFT_RESET_MASK |
UVD_SOFT_RESET__RBC_SOFT_RESET_MASK |
UVD_SOFT_RESET__CSM_SOFT_RESET_MASK |
UVD_SOFT_RESET__CXW_SOFT_RESET_MASK |
UVD_SOFT_RESET__TAP_SOFT_RESET_MASK |
UVD_SOFT_RESET__LMI_UMC_SOFT_RESET_MASK);
mdelay(5);
WREG32_SOC15(UVD, 0, mmUVD_LMI_CTRL,
(0x40 << UVD_LMI_CTRL__WRITE_CLEAN_TIMER__SHIFT) |
UVD_LMI_CTRL__WRITE_CLEAN_TIMER_EN_MASK |
UVD_LMI_CTRL__DATA_COHERENCY_EN_MASK |
UVD_LMI_CTRL__VCPU_DATA_COHERENCY_EN_MASK |
UVD_LMI_CTRL__REQ_MODE_MASK |
0x00100000L);
#ifdef __BIG_ENDIAN
lmi_swap_cntl = 0xa;
#endif
WREG32_SOC15(UVD, 0, mmUVD_LMI_SWAP_CNTL, lmi_swap_cntl);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_MUXA0, 0x40c2040);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_MUXA1, 0x0);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_MUXB0, 0x40c2040);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_MUXB1, 0x0);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_ALU, 0);
WREG32_SOC15(UVD, 0, mmUVD_MPC_SET_MUX, 0x88);
WREG32_SOC15(UVD, 0, mmUVD_SOFT_RESET,
UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(5);
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CNTL,
UVD_VCPU_CNTL__CLK_EN_MASK);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_CTRL2), 0,
~UVD_LMI_CTRL2__STALL_ARB_UMC_MASK);
WREG32_SOC15(UVD, 0, mmUVD_SOFT_RESET, 0);
mdelay(10);
for (i = 0; i < 10; ++i) {
uint32_t status;
for (j = 0; j < 100; ++j) {
status = RREG32_SOC15(UVD, 0, mmUVD_STATUS);
if (status & 2)
break;
mdelay(10);
}
r = 0;
if (status & 2)
break;
DRM_ERROR("VCN decode not responding, trying to reset the VCPU!!!\n");
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_SOFT_RESET),
UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK,
~UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(10);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_SOFT_RESET), 0,
~UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(10);
r = -1;
}
if (r) {
DRM_ERROR("VCN decode not responding, giving up!!!\n");
return r;
}
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_MASTINT_EN),
(UVD_MASTINT_EN__VCPU_EN_MASK|UVD_MASTINT_EN__SYS_EN_MASK),
~(UVD_MASTINT_EN__VCPU_EN_MASK|UVD_MASTINT_EN__SYS_EN_MASK));
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_STATUS), 0,
~(2 << UVD_STATUS__VCPU_REPORT__SHIFT));
rb_bufsz = order_base_2(ring->ring_size);
tmp = REG_SET_FIELD(0, UVD_RBC_RB_CNTL, RB_BUFSZ, rb_bufsz);
tmp = REG_SET_FIELD(tmp, UVD_RBC_RB_CNTL, RB_BLKSZ, 1);
tmp = REG_SET_FIELD(tmp, UVD_RBC_RB_CNTL, RB_NO_FETCH, 1);
tmp = REG_SET_FIELD(tmp, UVD_RBC_RB_CNTL, RB_WPTR_POLL_EN, 0);
tmp = REG_SET_FIELD(tmp, UVD_RBC_RB_CNTL, RB_NO_UPDATE, 1);
tmp = REG_SET_FIELD(tmp, UVD_RBC_RB_CNTL, RB_RPTR_WR_EN, 1);
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_CNTL, tmp);
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR_CNTL, 0);
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_RPTR_ADDR,
(upper_32_bits(ring->gpu_addr) >> 2));
WREG32_SOC15(UVD, 0, mmUVD_LMI_RBC_RB_64BIT_BAR_LOW,
lower_32_bits(ring->gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_LMI_RBC_RB_64BIT_BAR_HIGH,
upper_32_bits(ring->gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_RPTR, 0);
ring->wptr = RREG32_SOC15(UVD, 0, mmUVD_RBC_RB_RPTR);
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR,
lower_32_bits(ring->wptr));
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_RBC_RB_CNTL), 0,
~UVD_RBC_RB_CNTL__RB_NO_FETCH_MASK);
ring = &adev->vcn.ring_enc[0];
WREG32_SOC15(UVD, 0, mmUVD_RB_RPTR, lower_32_bits(ring->wptr));
WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR, lower_32_bits(ring->wptr));
WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_LO, ring->gpu_addr);
WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_HI, upper_32_bits(ring->gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_RB_SIZE, ring->ring_size / 4);
ring = &adev->vcn.ring_enc[1];
WREG32_SOC15(UVD, 0, mmUVD_RB_RPTR2, lower_32_bits(ring->wptr));
WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR2, lower_32_bits(ring->wptr));
WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_LO2, ring->gpu_addr);
WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_HI2, upper_32_bits(ring->gpu_addr));
WREG32_SOC15(UVD, 0, mmUVD_RB_SIZE2, ring->ring_size / 4);
return 0;
}
static int vcn_v1_0_stop(struct amdgpu_device *adev)
{
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_CNTL, 0x11010101);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_CTRL2),
UVD_LMI_CTRL2__STALL_ARB_UMC_MASK,
~UVD_LMI_CTRL2__STALL_ARB_UMC_MASK);
mdelay(1);
WREG32_SOC15(UVD, 0, mmUVD_SOFT_RESET,
UVD_SOFT_RESET__VCPU_SOFT_RESET_MASK);
mdelay(5);
WREG32_SOC15(UVD, 0, mmUVD_VCPU_CNTL, 0x0);
WREG32_P(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_CTRL2), 0,
~UVD_LMI_CTRL2__STALL_ARB_UMC_MASK);
vcn_v1_0_enable_clock_gating(adev, true);
return 0;
}
static int vcn_v1_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static uint64_t vcn_v1_0_dec_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
return RREG32_SOC15(UVD, 0, mmUVD_RBC_RB_RPTR);
}
static uint64_t vcn_v1_0_dec_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
return RREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR);
}
static void vcn_v1_0_dec_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR, lower_32_bits(ring->wptr));
}
static void vcn_v1_0_dec_ring_insert_start(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA0), 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_PACKET_START << 1);
}
static void vcn_v1_0_dec_ring_insert_end(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_PACKET_END << 1);
}
static void vcn_v1_0_dec_ring_emit_fence(struct amdgpu_ring *ring, u64 addr, u64 seq,
unsigned flags)
{
WARN_ON(flags & AMDGPU_FENCE_FLAG_64BIT);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_CONTEXT_ID), 0));
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA0), 0));
amdgpu_ring_write(ring, addr & 0xffffffff);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA1), 0));
amdgpu_ring_write(ring, upper_32_bits(addr) & 0xff);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_FENCE << 1);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA0), 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA1), 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_TRAP << 1);
}
static void vcn_v1_0_dec_ring_emit_hdp_invalidate(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, PACKET0(SOC15_REG_OFFSET(HDP, 0, mmHDP_DEBUG0), 0));
amdgpu_ring_write(ring, 1);
}
static void vcn_v1_0_dec_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_RBC_IB_VMID), 0));
amdgpu_ring_write(ring, vm_id);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_RBC_IB_64BIT_BAR_LOW), 0));
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_LMI_RBC_IB_64BIT_BAR_HIGH), 0));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_RBC_IB_SIZE), 0));
amdgpu_ring_write(ring, ib->length_dw);
}
static void vcn_v1_0_dec_vm_reg_write(struct amdgpu_ring *ring,
uint32_t data0, uint32_t data1)
{
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA0), 0));
amdgpu_ring_write(ring, data0);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA1), 0));
amdgpu_ring_write(ring, data1);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_WRITE_REG << 1);
}
static void vcn_v1_0_dec_vm_reg_wait(struct amdgpu_ring *ring,
uint32_t data0, uint32_t data1, uint32_t mask)
{
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA0), 0));
amdgpu_ring_write(ring, data0);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_DATA1), 0));
amdgpu_ring_write(ring, data1);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GP_SCRATCH8), 0));
amdgpu_ring_write(ring, mask);
amdgpu_ring_write(ring,
PACKET0(SOC15_REG_OFFSET(UVD, 0, mmUVD_GPCOM_VCPU_CMD), 0));
amdgpu_ring_write(ring, VCN_DEC_CMD_REG_READ_COND_WAIT << 1);
}
static void vcn_v1_0_dec_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr)
{
struct amdgpu_vmhub *hub = &ring->adev->vmhub[ring->funcs->vmhub];
uint32_t req = ring->adev->gart.gart_funcs->get_invalidate_req(vm_id);
uint32_t data0, data1, mask;
unsigned eng = ring->vm_inv_eng;
pd_addr = amdgpu_gart_get_vm_pde(ring->adev, pd_addr);
pd_addr |= AMDGPU_PTE_VALID;
data0 = (hub->ctx0_ptb_addr_hi32 + vm_id * 2) << 2;
data1 = upper_32_bits(pd_addr);
vcn_v1_0_dec_vm_reg_write(ring, data0, data1);
data0 = (hub->ctx0_ptb_addr_lo32 + vm_id * 2) << 2;
data1 = lower_32_bits(pd_addr);
vcn_v1_0_dec_vm_reg_write(ring, data0, data1);
data0 = (hub->ctx0_ptb_addr_lo32 + vm_id * 2) << 2;
data1 = lower_32_bits(pd_addr);
mask = 0xffffffff;
vcn_v1_0_dec_vm_reg_wait(ring, data0, data1, mask);
data0 = (hub->vm_inv_eng0_req + eng) << 2;
data1 = req;
vcn_v1_0_dec_vm_reg_write(ring, data0, data1);
data0 = (hub->vm_inv_eng0_ack + eng) << 2;
data1 = 1 << vm_id;
mask = 1 << vm_id;
vcn_v1_0_dec_vm_reg_wait(ring, data0, data1, mask);
}
static uint64_t vcn_v1_0_enc_ring_get_rptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vcn.ring_enc[0])
return RREG32_SOC15(UVD, 0, mmUVD_RB_RPTR);
else
return RREG32_SOC15(UVD, 0, mmUVD_RB_RPTR2);
}
static uint64_t vcn_v1_0_enc_ring_get_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vcn.ring_enc[0])
return RREG32_SOC15(UVD, 0, mmUVD_RB_WPTR);
else
return RREG32_SOC15(UVD, 0, mmUVD_RB_WPTR2);
}
static void vcn_v1_0_enc_ring_set_wptr(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring == &adev->vcn.ring_enc[0])
WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR,
lower_32_bits(ring->wptr));
else
WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR2,
lower_32_bits(ring->wptr));
}
static void vcn_v1_0_enc_ring_emit_fence(struct amdgpu_ring *ring, u64 addr,
u64 seq, unsigned flags)
{
WARN_ON(flags & AMDGPU_FENCE_FLAG_64BIT);
amdgpu_ring_write(ring, VCN_ENC_CMD_FENCE);
amdgpu_ring_write(ring, addr);
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring, VCN_ENC_CMD_TRAP);
}
static void vcn_v1_0_enc_ring_insert_end(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, VCN_ENC_CMD_END);
}
static void vcn_v1_0_enc_ring_emit_ib(struct amdgpu_ring *ring,
struct amdgpu_ib *ib, unsigned int vm_id, bool ctx_switch)
{
amdgpu_ring_write(ring, VCN_ENC_CMD_IB);
amdgpu_ring_write(ring, vm_id);
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, ib->length_dw);
}
static void vcn_v1_0_enc_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned int vm_id, uint64_t pd_addr)
{
struct amdgpu_vmhub *hub = &ring->adev->vmhub[ring->funcs->vmhub];
uint32_t req = ring->adev->gart.gart_funcs->get_invalidate_req(vm_id);
unsigned eng = ring->vm_inv_eng;
pd_addr = amdgpu_gart_get_vm_pde(ring->adev, pd_addr);
pd_addr |= AMDGPU_PTE_VALID;
amdgpu_ring_write(ring, VCN_ENC_CMD_REG_WRITE);
amdgpu_ring_write(ring,
(hub->ctx0_ptb_addr_hi32 + vm_id * 2) << 2);
amdgpu_ring_write(ring, upper_32_bits(pd_addr));
amdgpu_ring_write(ring, VCN_ENC_CMD_REG_WRITE);
amdgpu_ring_write(ring,
(hub->ctx0_ptb_addr_lo32 + vm_id * 2) << 2);
amdgpu_ring_write(ring, lower_32_bits(pd_addr));
amdgpu_ring_write(ring, VCN_ENC_CMD_REG_WAIT);
amdgpu_ring_write(ring,
(hub->ctx0_ptb_addr_lo32 + vm_id * 2) << 2);
amdgpu_ring_write(ring, 0xffffffff);
amdgpu_ring_write(ring, lower_32_bits(pd_addr));
amdgpu_ring_write(ring, VCN_ENC_CMD_REG_WRITE);
amdgpu_ring_write(ring, (hub->vm_inv_eng0_req + eng) << 2);
amdgpu_ring_write(ring, req);
amdgpu_ring_write(ring, VCN_ENC_CMD_REG_WAIT);
amdgpu_ring_write(ring, (hub->vm_inv_eng0_ack + eng) << 2);
amdgpu_ring_write(ring, 1 << vm_id);
amdgpu_ring_write(ring, 1 << vm_id);
}
static int vcn_v1_0_set_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
return 0;
}
static int vcn_v1_0_process_interrupt(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_DEBUG("IH: VCN TRAP\n");
switch (entry->src_id) {
case 124:
amdgpu_fence_process(&adev->vcn.ring_dec);
break;
case 119:
amdgpu_fence_process(&adev->vcn.ring_enc[0]);
break;
case 120:
amdgpu_fence_process(&adev->vcn.ring_enc[1]);
break;
default:
DRM_ERROR("Unhandled interrupt: %d %d\n",
entry->src_id, entry->src_data[0]);
break;
}
return 0;
}
static void vcn_v1_0_set_dec_ring_funcs(struct amdgpu_device *adev)
{
adev->vcn.ring_dec.funcs = &vcn_v1_0_dec_ring_vm_funcs;
DRM_INFO("VCN decode is enabled in VM mode\n");
}
static void vcn_v1_0_set_enc_ring_funcs(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->vcn.num_enc_rings; ++i)
adev->vcn.ring_enc[i].funcs = &vcn_v1_0_enc_ring_vm_funcs;
DRM_INFO("VCN encode is enabled in VM mode\n");
}
static void vcn_v1_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->uvd.irq.num_types = adev->vcn.num_enc_rings + 1;
adev->vcn.irq.funcs = &vcn_v1_0_irq_funcs;
}
