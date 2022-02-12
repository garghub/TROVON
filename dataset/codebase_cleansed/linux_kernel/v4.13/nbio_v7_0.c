u32 nbio_v7_0_get_rev_id(struct amdgpu_device *adev)
{
u32 tmp = RREG32_SOC15(NBIO, 0, mmRCC_DEV0_EPF0_STRAP0);
tmp &= RCC_DEV0_EPF0_STRAP0__STRAP_ATI_REV_ID_DEV0_F0_MASK;
tmp >>= RCC_DEV0_EPF0_STRAP0__STRAP_ATI_REV_ID_DEV0_F0__SHIFT;
return tmp;
}
u32 nbio_v7_0_get_atombios_scratch_regs(struct amdgpu_device *adev,
uint32_t idx)
{
return RREG32_SOC15_OFFSET(NBIO, 0, mmBIOS_SCRATCH_0, idx);
}
void nbio_v7_0_set_atombios_scratch_regs(struct amdgpu_device *adev,
uint32_t idx, uint32_t val)
{
WREG32_SOC15_OFFSET(NBIO, 0, mmBIOS_SCRATCH_0, idx, val);
}
void nbio_v7_0_mc_access_enable(struct amdgpu_device *adev, bool enable)
{
if (enable)
WREG32_SOC15(NBIO, 0, mmBIF_FB_EN,
BIF_FB_EN__FB_READ_EN_MASK | BIF_FB_EN__FB_WRITE_EN_MASK);
else
WREG32_SOC15(NBIO, 0, mmBIF_FB_EN, 0);
}
void nbio_v7_0_hdp_flush(struct amdgpu_device *adev)
{
WREG32_SOC15(NBIO, 0, mmHDP_MEM_COHERENCY_FLUSH_CNTL, 0);
}
u32 nbio_v7_0_get_memsize(struct amdgpu_device *adev)
{
return RREG32_SOC15(NBIO, 0, mmRCC_CONFIG_MEMSIZE);
}
void nbio_v7_0_sdma_doorbell_range(struct amdgpu_device *adev, int instance,
bool use_doorbell, int doorbell_index)
{
u32 doorbell_range = RREG32(nbio_sdma_doorbell_range_reg[instance]);
if (use_doorbell) {
doorbell_range = REG_SET_FIELD(doorbell_range, BIF_SDMA0_DOORBELL_RANGE, OFFSET, doorbell_index);
doorbell_range = REG_SET_FIELD(doorbell_range, BIF_SDMA0_DOORBELL_RANGE, SIZE, 2);
} else
doorbell_range = REG_SET_FIELD(doorbell_range, BIF_SDMA0_DOORBELL_RANGE, SIZE, 0);
WREG32(nbio_sdma_doorbell_range_reg[instance], doorbell_range);
}
void nbio_v7_0_enable_doorbell_aperture(struct amdgpu_device *adev,
bool enable)
{
WREG32_FIELD15(NBIO, 0, RCC_DOORBELL_APER_EN, BIF_DOORBELL_APER_EN, enable ? 1 : 0);
}
void nbio_v7_0_ih_doorbell_range(struct amdgpu_device *adev,
bool use_doorbell, int doorbell_index)
{
u32 ih_doorbell_range = RREG32_SOC15(NBIO, 0 , mmBIF_IH_DOORBELL_RANGE);
if (use_doorbell) {
ih_doorbell_range = REG_SET_FIELD(ih_doorbell_range, BIF_IH_DOORBELL_RANGE, OFFSET, doorbell_index);
ih_doorbell_range = REG_SET_FIELD(ih_doorbell_range, BIF_IH_DOORBELL_RANGE, SIZE, 2);
} else
ih_doorbell_range = REG_SET_FIELD(ih_doorbell_range, BIF_IH_DOORBELL_RANGE, SIZE, 0);
WREG32_SOC15(NBIO, 0, mmBIF_IH_DOORBELL_RANGE, ih_doorbell_range);
}
static uint32_t nbio_7_0_read_syshub_ind_mmr(struct amdgpu_device *adev, uint32_t offset)
{
uint32_t data;
WREG32_SOC15(NBIO, 0, mmSYSHUB_INDEX, offset);
data = RREG32_SOC15(NBIO, 0, mmSYSHUB_DATA);
return data;
}
static void nbio_7_0_write_syshub_ind_mmr(struct amdgpu_device *adev, uint32_t offset,
uint32_t data)
{
WREG32_SOC15(NBIO, 0, mmSYSHUB_INDEX, offset);
WREG32_SOC15(NBIO, 0, mmSYSHUB_DATA, data);
}
void nbio_v7_0_update_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t def, data;
def = data = RREG32_PCIE(smnNBIF_MGCG_CTRL_LCLK);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_BIF_MGCG))
data |= NBIF_MGCG_CTRL_LCLK__NBIF_MGCG_EN_LCLK_MASK;
else
data &= ~NBIF_MGCG_CTRL_LCLK__NBIF_MGCG_EN_LCLK_MASK;
if (def != data)
WREG32_PCIE(smnNBIF_MGCG_CTRL_LCLK, data);
def = data = nbio_7_0_read_syshub_ind_mmr(adev, ixSYSHUB_MMREG_IND_SYSHUB_MGCG_CTRL_SOCCLK);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_BIF_MGCG))
data |= SYSHUB_MMREG_DIRECT_SYSHUB_MGCG_CTRL_SOCCLK__SYSHUB_MGCG_EN_SOCCLK_MASK;
else
data &= ~SYSHUB_MMREG_DIRECT_SYSHUB_MGCG_CTRL_SOCCLK__SYSHUB_MGCG_EN_SOCCLK_MASK;
if (def != data)
nbio_7_0_write_syshub_ind_mmr(adev, ixSYSHUB_MMREG_IND_SYSHUB_MGCG_CTRL_SOCCLK, data);
def = data = nbio_7_0_read_syshub_ind_mmr(adev, ixSYSHUB_MMREG_IND_SYSHUB_MGCG_CTRL_SHUBCLK);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_BIF_MGCG))
data |= SYSHUB_MMREG_DIRECT_SYSHUB_MGCG_CTRL_SHUBCLK__SYSHUB_MGCG_EN_SHUBCLK_MASK;
else
data &= ~SYSHUB_MMREG_DIRECT_SYSHUB_MGCG_CTRL_SHUBCLK__SYSHUB_MGCG_EN_SHUBCLK_MASK;
if (def != data)
nbio_7_0_write_syshub_ind_mmr(adev, ixSYSHUB_MMREG_IND_SYSHUB_MGCG_CTRL_SHUBCLK, data);
}
void nbio_v7_0_ih_control(struct amdgpu_device *adev)
{
u32 interrupt_cntl;
WREG32_SOC15(NBIO, 0, mmINTERRUPT_CNTL2, adev->dummy_page.addr >> 8);
interrupt_cntl = RREG32_SOC15(NBIO, 0, mmINTERRUPT_CNTL);
interrupt_cntl = REG_SET_FIELD(interrupt_cntl, INTERRUPT_CNTL, IH_DUMMY_RD_OVERRIDE, 0);
interrupt_cntl = REG_SET_FIELD(interrupt_cntl, INTERRUPT_CNTL, IH_REQ_NONSNOOP_EN, 0);
WREG32_SOC15(NBIO, 0, mmINTERRUPT_CNTL, interrupt_cntl);
}
int nbio_v7_0_init(struct amdgpu_device *adev)
{
nbio_v7_0_hdp_flush_reg.hdp_flush_req_offset = SOC15_REG_OFFSET(NBIO, 0, mmGPU_HDP_FLUSH_REQ);
nbio_v7_0_hdp_flush_reg.hdp_flush_done_offset = SOC15_REG_OFFSET(NBIO, 0, mmGPU_HDP_FLUSH_DONE);
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp0 = GPU_HDP_FLUSH_DONE__CP0_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp1 = GPU_HDP_FLUSH_DONE__CP1_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp2 = GPU_HDP_FLUSH_DONE__CP2_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp3 = GPU_HDP_FLUSH_DONE__CP3_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp4 = GPU_HDP_FLUSH_DONE__CP4_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp5 = GPU_HDP_FLUSH_DONE__CP5_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp6 = GPU_HDP_FLUSH_DONE__CP6_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp7 = GPU_HDP_FLUSH_DONE__CP7_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp8 = GPU_HDP_FLUSH_DONE__CP8_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_cp9 = GPU_HDP_FLUSH_DONE__CP9_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_sdma0 = GPU_HDP_FLUSH_DONE__SDMA0_MASK;
nbio_v7_0_hdp_flush_reg.ref_and_mask_sdma1 = GPU_HDP_FLUSH_DONE__SDMA1_MASK;
nbio_v7_0_pcie_index_data.index_offset = SOC15_REG_OFFSET(NBIO, 0, mmPCIE_INDEX2);
nbio_v7_0_pcie_index_data.data_offset = SOC15_REG_OFFSET(NBIO, 0, mmPCIE_DATA2);
return 0;
}
