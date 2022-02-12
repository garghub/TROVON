static u32 vi_pcie_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(mmPCIE_INDEX, reg);
(void)RREG32(mmPCIE_INDEX);
r = RREG32(mmPCIE_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static void vi_pcie_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(mmPCIE_INDEX, reg);
(void)RREG32(mmPCIE_INDEX);
WREG32(mmPCIE_DATA, v);
(void)RREG32(mmPCIE_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static u32 vi_smc_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmSMC_IND_INDEX_0, (reg));
r = RREG32(mmSMC_IND_DATA_0);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return r;
}
static void vi_smc_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmSMC_IND_INDEX_0, (reg));
WREG32(mmSMC_IND_DATA_0, (v));
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
}
static u32 cz_smc_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmMP0PUB_IND_INDEX, (reg));
r = RREG32(mmMP0PUB_IND_DATA);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return r;
}
static void cz_smc_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmMP0PUB_IND_INDEX, (reg));
WREG32(mmMP0PUB_IND_DATA, (v));
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
}
static u32 vi_uvd_ctx_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->uvd_ctx_idx_lock, flags);
WREG32(mmUVD_CTX_INDEX, ((reg) & 0x1ff));
r = RREG32(mmUVD_CTX_DATA);
spin_unlock_irqrestore(&adev->uvd_ctx_idx_lock, flags);
return r;
}
static void vi_uvd_ctx_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->uvd_ctx_idx_lock, flags);
WREG32(mmUVD_CTX_INDEX, ((reg) & 0x1ff));
WREG32(mmUVD_CTX_DATA, (v));
spin_unlock_irqrestore(&adev->uvd_ctx_idx_lock, flags);
}
static u32 vi_didt_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->didt_idx_lock, flags);
WREG32(mmDIDT_IND_INDEX, (reg));
r = RREG32(mmDIDT_IND_DATA);
spin_unlock_irqrestore(&adev->didt_idx_lock, flags);
return r;
}
static void vi_didt_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->didt_idx_lock, flags);
WREG32(mmDIDT_IND_INDEX, (reg));
WREG32(mmDIDT_IND_DATA, (v));
spin_unlock_irqrestore(&adev->didt_idx_lock, flags);
}
static void vi_init_golden_registers(struct amdgpu_device *adev)
{
mutex_lock(&adev->grbm_idx_mutex);
switch (adev->asic_type) {
case CHIP_TOPAZ:
amdgpu_program_register_sequence(adev,
iceland_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(iceland_mgcg_cgcg_init));
break;
case CHIP_FIJI:
amdgpu_program_register_sequence(adev,
fiji_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(fiji_mgcg_cgcg_init));
break;
case CHIP_TONGA:
amdgpu_program_register_sequence(adev,
tonga_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(tonga_mgcg_cgcg_init));
break;
case CHIP_CARRIZO:
amdgpu_program_register_sequence(adev,
cz_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(cz_mgcg_cgcg_init));
break;
case CHIP_STONEY:
amdgpu_program_register_sequence(adev,
stoney_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(stoney_mgcg_cgcg_init));
break;
default:
break;
}
mutex_unlock(&adev->grbm_idx_mutex);
}
static u32 vi_get_xclk(struct amdgpu_device *adev)
{
u32 reference_clock = adev->clock.spll.reference_freq;
u32 tmp;
if (adev->flags & AMD_IS_APU)
return reference_clock;
tmp = RREG32_SMC(ixCG_CLKPIN_CNTL_2);
if (REG_GET_FIELD(tmp, CG_CLKPIN_CNTL_2, MUX_TCLK_TO_XCLK))
return 1000;
tmp = RREG32_SMC(ixCG_CLKPIN_CNTL);
if (REG_GET_FIELD(tmp, CG_CLKPIN_CNTL, XTALIN_DIVIDE))
return reference_clock / 4;
return reference_clock;
}
void vi_srbm_select(struct amdgpu_device *adev,
u32 me, u32 pipe, u32 queue, u32 vmid)
{
u32 srbm_gfx_cntl = 0;
srbm_gfx_cntl = REG_SET_FIELD(srbm_gfx_cntl, SRBM_GFX_CNTL, PIPEID, pipe);
srbm_gfx_cntl = REG_SET_FIELD(srbm_gfx_cntl, SRBM_GFX_CNTL, MEID, me);
srbm_gfx_cntl = REG_SET_FIELD(srbm_gfx_cntl, SRBM_GFX_CNTL, VMID, vmid);
srbm_gfx_cntl = REG_SET_FIELD(srbm_gfx_cntl, SRBM_GFX_CNTL, QUEUEID, queue);
WREG32(mmSRBM_GFX_CNTL, srbm_gfx_cntl);
}
static void vi_vga_set_state(struct amdgpu_device *adev, bool state)
{
}
static bool vi_read_disabled_bios(struct amdgpu_device *adev)
{
u32 bus_cntl;
u32 d1vga_control = 0;
u32 d2vga_control = 0;
u32 vga_render_control = 0;
u32 rom_cntl;
bool r;
bus_cntl = RREG32(mmBUS_CNTL);
if (adev->mode_info.num_crtc) {
d1vga_control = RREG32(mmD1VGA_CONTROL);
d2vga_control = RREG32(mmD2VGA_CONTROL);
vga_render_control = RREG32(mmVGA_RENDER_CONTROL);
}
rom_cntl = RREG32_SMC(ixROM_CNTL);
WREG32(mmBUS_CNTL, (bus_cntl & ~BUS_CNTL__BIOS_ROM_DIS_MASK));
if (adev->mode_info.num_crtc) {
WREG32(mmD1VGA_CONTROL,
(d1vga_control & ~(D1VGA_CONTROL__D1VGA_MODE_ENABLE_MASK |
D1VGA_CONTROL__D1VGA_TIMING_SELECT_MASK)));
WREG32(mmD2VGA_CONTROL,
(d2vga_control & ~(D2VGA_CONTROL__D2VGA_MODE_ENABLE_MASK |
D2VGA_CONTROL__D2VGA_TIMING_SELECT_MASK)));
WREG32(mmVGA_RENDER_CONTROL,
(vga_render_control & ~VGA_RENDER_CONTROL__VGA_VSTATUS_CNTL_MASK));
}
WREG32_SMC(ixROM_CNTL, rom_cntl | ROM_CNTL__SCK_OVERWRITE_MASK);
r = amdgpu_read_bios(adev);
WREG32(mmBUS_CNTL, bus_cntl);
if (adev->mode_info.num_crtc) {
WREG32(mmD1VGA_CONTROL, d1vga_control);
WREG32(mmD2VGA_CONTROL, d2vga_control);
WREG32(mmVGA_RENDER_CONTROL, vga_render_control);
}
WREG32_SMC(ixROM_CNTL, rom_cntl);
return r;
}
static uint32_t vi_read_indexed_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset)
{
uint32_t val;
mutex_lock(&adev->grbm_idx_mutex);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
gfx_v8_0_select_se_sh(adev, se_num, sh_num);
val = RREG32(reg_offset);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
return val;
}
static int vi_read_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset, u32 *value)
{
struct amdgpu_allowed_register_entry *asic_register_table = NULL;
struct amdgpu_allowed_register_entry *asic_register_entry;
uint32_t size, i;
*value = 0;
switch (adev->asic_type) {
case CHIP_TOPAZ:
asic_register_table = tonga_allowed_read_registers;
size = ARRAY_SIZE(tonga_allowed_read_registers);
break;
case CHIP_FIJI:
case CHIP_TONGA:
case CHIP_CARRIZO:
case CHIP_STONEY:
asic_register_table = cz_allowed_read_registers;
size = ARRAY_SIZE(cz_allowed_read_registers);
break;
default:
return -EINVAL;
}
if (asic_register_table) {
for (i = 0; i < size; i++) {
asic_register_entry = asic_register_table + i;
if (reg_offset != asic_register_entry->reg_offset)
continue;
if (!asic_register_entry->untouched)
*value = asic_register_entry->grbm_indexed ?
vi_read_indexed_register(adev, se_num,
sh_num, reg_offset) :
RREG32(reg_offset);
return 0;
}
}
for (i = 0; i < ARRAY_SIZE(vi_allowed_read_registers); i++) {
if (reg_offset != vi_allowed_read_registers[i].reg_offset)
continue;
if (!vi_allowed_read_registers[i].untouched)
*value = vi_allowed_read_registers[i].grbm_indexed ?
vi_read_indexed_register(adev, se_num,
sh_num, reg_offset) :
RREG32(reg_offset);
return 0;
}
return -EINVAL;
}
static void vi_print_gpu_status_regs(struct amdgpu_device *adev)
{
dev_info(adev->dev, " GRBM_STATUS=0x%08X\n",
RREG32(mmGRBM_STATUS));
dev_info(adev->dev, " GRBM_STATUS2=0x%08X\n",
RREG32(mmGRBM_STATUS2));
dev_info(adev->dev, " GRBM_STATUS_SE0=0x%08X\n",
RREG32(mmGRBM_STATUS_SE0));
dev_info(adev->dev, " GRBM_STATUS_SE1=0x%08X\n",
RREG32(mmGRBM_STATUS_SE1));
dev_info(adev->dev, " GRBM_STATUS_SE2=0x%08X\n",
RREG32(mmGRBM_STATUS_SE2));
dev_info(adev->dev, " GRBM_STATUS_SE3=0x%08X\n",
RREG32(mmGRBM_STATUS_SE3));
dev_info(adev->dev, " SRBM_STATUS=0x%08X\n",
RREG32(mmSRBM_STATUS));
dev_info(adev->dev, " SRBM_STATUS2=0x%08X\n",
RREG32(mmSRBM_STATUS2));
dev_info(adev->dev, " SDMA0_STATUS_REG = 0x%08X\n",
RREG32(mmSDMA0_STATUS_REG + SDMA0_REGISTER_OFFSET));
if (adev->sdma.num_instances > 1) {
dev_info(adev->dev, " SDMA1_STATUS_REG = 0x%08X\n",
RREG32(mmSDMA0_STATUS_REG + SDMA1_REGISTER_OFFSET));
}
dev_info(adev->dev, " CP_STAT = 0x%08x\n", RREG32(mmCP_STAT));
dev_info(adev->dev, " CP_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT1));
dev_info(adev->dev, " CP_STALLED_STAT2 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT2));
dev_info(adev->dev, " CP_STALLED_STAT3 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT3));
dev_info(adev->dev, " CP_CPF_BUSY_STAT = 0x%08x\n",
RREG32(mmCP_CPF_BUSY_STAT));
dev_info(adev->dev, " CP_CPF_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_CPF_STALLED_STAT1));
dev_info(adev->dev, " CP_CPF_STATUS = 0x%08x\n", RREG32(mmCP_CPF_STATUS));
dev_info(adev->dev, " CP_CPC_BUSY_STAT = 0x%08x\n", RREG32(mmCP_CPC_BUSY_STAT));
dev_info(adev->dev, " CP_CPC_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_CPC_STALLED_STAT1));
dev_info(adev->dev, " CP_CPC_STATUS = 0x%08x\n", RREG32(mmCP_CPC_STATUS));
}
u32 vi_gpu_check_soft_reset(struct amdgpu_device *adev)
{
u32 reset_mask = 0;
u32 tmp;
tmp = RREG32(mmGRBM_STATUS);
if (tmp & (GRBM_STATUS__PA_BUSY_MASK | GRBM_STATUS__SC_BUSY_MASK |
GRBM_STATUS__BCI_BUSY_MASK | GRBM_STATUS__SX_BUSY_MASK |
GRBM_STATUS__TA_BUSY_MASK | GRBM_STATUS__VGT_BUSY_MASK |
GRBM_STATUS__DB_BUSY_MASK | GRBM_STATUS__CB_BUSY_MASK |
GRBM_STATUS__GDS_BUSY_MASK | GRBM_STATUS__SPI_BUSY_MASK |
GRBM_STATUS__IA_BUSY_MASK | GRBM_STATUS__IA_BUSY_NO_DMA_MASK))
reset_mask |= AMDGPU_RESET_GFX;
if (tmp & (GRBM_STATUS__CP_BUSY_MASK | GRBM_STATUS__CP_COHERENCY_BUSY_MASK))
reset_mask |= AMDGPU_RESET_CP;
tmp = RREG32(mmGRBM_STATUS2);
if (tmp & GRBM_STATUS2__RLC_BUSY_MASK)
reset_mask |= AMDGPU_RESET_RLC;
if (tmp & (GRBM_STATUS2__CPF_BUSY_MASK |
GRBM_STATUS2__CPC_BUSY_MASK |
GRBM_STATUS2__CPG_BUSY_MASK))
reset_mask |= AMDGPU_RESET_CP;
tmp = RREG32(mmSRBM_STATUS2);
if (tmp & SRBM_STATUS2__SDMA_BUSY_MASK)
reset_mask |= AMDGPU_RESET_DMA;
if (tmp & SRBM_STATUS2__SDMA1_BUSY_MASK)
reset_mask |= AMDGPU_RESET_DMA1;
tmp = RREG32(mmSRBM_STATUS);
if (tmp & SRBM_STATUS__IH_BUSY_MASK)
reset_mask |= AMDGPU_RESET_IH;
if (tmp & SRBM_STATUS__SEM_BUSY_MASK)
reset_mask |= AMDGPU_RESET_SEM;
if (tmp & SRBM_STATUS__GRBM_RQ_PENDING_MASK)
reset_mask |= AMDGPU_RESET_GRBM;
if (adev->asic_type != CHIP_TOPAZ) {
if (tmp & (SRBM_STATUS__UVD_RQ_PENDING_MASK |
SRBM_STATUS__UVD_BUSY_MASK))
reset_mask |= AMDGPU_RESET_UVD;
}
if (tmp & SRBM_STATUS__VMC_BUSY_MASK)
reset_mask |= AMDGPU_RESET_VMC;
if (tmp & (SRBM_STATUS__MCB_BUSY_MASK | SRBM_STATUS__MCB_NON_DISPLAY_BUSY_MASK |
SRBM_STATUS__MCC_BUSY_MASK | SRBM_STATUS__MCD_BUSY_MASK))
reset_mask |= AMDGPU_RESET_MC;
tmp = RREG32(mmSDMA0_STATUS_REG + SDMA0_REGISTER_OFFSET);
if (!(tmp & SDMA0_STATUS_REG__IDLE_MASK))
reset_mask |= AMDGPU_RESET_DMA;
if (adev->sdma.num_instances > 1) {
tmp = RREG32(mmSDMA0_STATUS_REG + SDMA1_REGISTER_OFFSET);
if (!(tmp & SDMA0_STATUS_REG__IDLE_MASK))
reset_mask |= AMDGPU_RESET_DMA1;
}
#if 0
if (adev->asic_type != CHIP_TOPAZ) {
tmp = RREG32(mmVCE_STATUS);
if (tmp & VCE_STATUS__VCPU_REPORT_RB0_BUSY_MASK)
reset_mask |= AMDGPU_RESET_VCE;
if (tmp & VCE_STATUS__VCPU_REPORT_RB1_BUSY_MASK)
reset_mask |= AMDGPU_RESET_VCE1;
}
if (adev->asic_type != CHIP_TOPAZ) {
if (amdgpu_display_is_display_hung(adev))
reset_mask |= AMDGPU_RESET_DISPLAY;
}
#endif
if (reset_mask & AMDGPU_RESET_MC) {
DRM_DEBUG("MC busy: 0x%08X, clearing.\n", reset_mask);
reset_mask &= ~AMDGPU_RESET_MC;
}
return reset_mask;
}
static void vi_gpu_soft_reset(struct amdgpu_device *adev, u32 reset_mask)
{
struct amdgpu_mode_mc_save save;
u32 grbm_soft_reset = 0, srbm_soft_reset = 0;
u32 tmp;
if (reset_mask == 0)
return;
dev_info(adev->dev, "GPU softreset: 0x%08X\n", reset_mask);
vi_print_gpu_status_regs(adev);
dev_info(adev->dev, " VM_CONTEXT1_PROTECTION_FAULT_ADDR 0x%08X\n",
RREG32(mmVM_CONTEXT1_PROTECTION_FAULT_ADDR));
dev_info(adev->dev, " VM_CONTEXT1_PROTECTION_FAULT_STATUS 0x%08X\n",
RREG32(mmVM_CONTEXT1_PROTECTION_FAULT_STATUS));
tmp = RREG32(mmCP_ME_CNTL);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, ME_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, PFP_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, CE_HALT, 1);
WREG32(mmCP_ME_CNTL, tmp);
tmp = RREG32(mmCP_MEC_CNTL);
tmp = REG_SET_FIELD(tmp, CP_MEC_CNTL, MEC_ME1_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_MEC_CNTL, MEC_ME2_HALT, 1);
WREG32(mmCP_MEC_CNTL, tmp);
if (reset_mask & AMDGPU_RESET_DMA) {
tmp = RREG32(mmSDMA0_F32_CNTL + SDMA0_REGISTER_OFFSET);
tmp = REG_SET_FIELD(tmp, SDMA0_F32_CNTL, HALT, 1);
WREG32(mmSDMA0_F32_CNTL + SDMA0_REGISTER_OFFSET, tmp);
}
if (reset_mask & AMDGPU_RESET_DMA1) {
tmp = RREG32(mmSDMA0_F32_CNTL + SDMA1_REGISTER_OFFSET);
tmp = REG_SET_FIELD(tmp, SDMA0_F32_CNTL, HALT, 1);
WREG32(mmSDMA0_F32_CNTL + SDMA1_REGISTER_OFFSET, tmp);
}
gmc_v8_0_mc_stop(adev, &save);
if (amdgpu_asic_wait_for_mc_idle(adev)) {
dev_warn(adev->dev, "Wait for MC idle timedout !\n");
}
if (reset_mask & (AMDGPU_RESET_GFX | AMDGPU_RESET_COMPUTE | AMDGPU_RESET_CP)) {
grbm_soft_reset =
REG_SET_FIELD(grbm_soft_reset, GRBM_SOFT_RESET, SOFT_RESET_CP, 1);
grbm_soft_reset =
REG_SET_FIELD(grbm_soft_reset, GRBM_SOFT_RESET, SOFT_RESET_GFX, 1);
}
if (reset_mask & AMDGPU_RESET_CP) {
grbm_soft_reset =
REG_SET_FIELD(grbm_soft_reset, GRBM_SOFT_RESET, SOFT_RESET_CP, 1);
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_GRBM, 1);
}
if (reset_mask & AMDGPU_RESET_DMA)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA, 1);
if (reset_mask & AMDGPU_RESET_DMA1)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SDMA1, 1);
if (reset_mask & AMDGPU_RESET_DISPLAY)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_DC, 1);
if (reset_mask & AMDGPU_RESET_RLC)
grbm_soft_reset =
REG_SET_FIELD(grbm_soft_reset, GRBM_SOFT_RESET, SOFT_RESET_RLC, 1);
if (reset_mask & AMDGPU_RESET_SEM)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_SEM, 1);
if (reset_mask & AMDGPU_RESET_IH)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_IH, 1);
if (reset_mask & AMDGPU_RESET_GRBM)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_GRBM, 1);
if (reset_mask & AMDGPU_RESET_VMC)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VMC, 1);
if (reset_mask & AMDGPU_RESET_UVD)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_UVD, 1);
if (reset_mask & AMDGPU_RESET_VCE)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE0, 1);
if (reset_mask & AMDGPU_RESET_VCE)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_VCE1, 1);
if (!(adev->flags & AMD_IS_APU)) {
if (reset_mask & AMDGPU_RESET_MC)
srbm_soft_reset =
REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET, SOFT_RESET_MC, 1);
}
if (grbm_soft_reset) {
tmp = RREG32(mmGRBM_SOFT_RESET);
tmp |= grbm_soft_reset;
dev_info(adev->dev, "GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmGRBM_SOFT_RESET, tmp);
tmp = RREG32(mmGRBM_SOFT_RESET);
udelay(50);
tmp &= ~grbm_soft_reset;
WREG32(mmGRBM_SOFT_RESET, tmp);
tmp = RREG32(mmGRBM_SOFT_RESET);
}
if (srbm_soft_reset) {
tmp = RREG32(mmSRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(adev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
}
udelay(50);
gmc_v8_0_mc_resume(adev, &save);
udelay(50);
vi_print_gpu_status_regs(adev);
}
static void vi_gpu_pci_config_reset(struct amdgpu_device *adev)
{
struct amdgpu_mode_mc_save save;
u32 tmp, i;
dev_info(adev->dev, "GPU pci config reset\n");
tmp = RREG32(mmCP_ME_CNTL);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, ME_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, PFP_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, CE_HALT, 1);
WREG32(mmCP_ME_CNTL, tmp);
tmp = RREG32(mmCP_MEC_CNTL);
tmp = REG_SET_FIELD(tmp, CP_MEC_CNTL, MEC_ME1_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_MEC_CNTL, MEC_ME2_HALT, 1);
WREG32(mmCP_MEC_CNTL, tmp);
WREG32(mmCP_ME_CNTL, CP_ME_CNTL__ME_HALT_MASK |
CP_ME_CNTL__PFP_HALT_MASK | CP_ME_CNTL__CE_HALT_MASK);
WREG32(mmCP_MEC_CNTL,
CP_MEC_CNTL__MEC_ME1_HALT_MASK | CP_MEC_CNTL__MEC_ME2_HALT_MASK);
tmp = RREG32(mmSDMA0_F32_CNTL + SDMA0_REGISTER_OFFSET);
tmp = REG_SET_FIELD(tmp, SDMA0_F32_CNTL, HALT, 1);
WREG32(mmSDMA0_F32_CNTL + SDMA0_REGISTER_OFFSET, tmp);
tmp = RREG32(mmSDMA0_F32_CNTL + SDMA1_REGISTER_OFFSET);
tmp = REG_SET_FIELD(tmp, SDMA0_F32_CNTL, HALT, 1);
WREG32(mmSDMA0_F32_CNTL + SDMA1_REGISTER_OFFSET, tmp);
udelay(50);
gmc_v8_0_mc_stop(adev, &save);
if (amdgpu_asic_wait_for_mc_idle(adev)) {
dev_warn(adev->dev, "Wait for MC idle timed out !\n");
}
pci_clear_master(adev->pdev);
amdgpu_pci_config_reset(adev);
udelay(100);
for (i = 0; i < adev->usec_timeout; i++) {
if (RREG32(mmCONFIG_MEMSIZE) != 0xffffffff)
break;
udelay(1);
}
}
static void vi_set_bios_scratch_engine_hung(struct amdgpu_device *adev, bool hung)
{
u32 tmp = RREG32(mmBIOS_SCRATCH_3);
if (hung)
tmp |= ATOM_S3_ASIC_GUI_ENGINE_HUNG;
else
tmp &= ~ATOM_S3_ASIC_GUI_ENGINE_HUNG;
WREG32(mmBIOS_SCRATCH_3, tmp);
}
static int vi_asic_reset(struct amdgpu_device *adev)
{
u32 reset_mask;
reset_mask = vi_gpu_check_soft_reset(adev);
if (reset_mask)
vi_set_bios_scratch_engine_hung(adev, true);
vi_gpu_soft_reset(adev, reset_mask);
reset_mask = vi_gpu_check_soft_reset(adev);
if (reset_mask && amdgpu_hard_reset)
vi_gpu_pci_config_reset(adev);
reset_mask = vi_gpu_check_soft_reset(adev);
if (!reset_mask)
vi_set_bios_scratch_engine_hung(adev, false);
return 0;
}
static int vi_set_uvd_clock(struct amdgpu_device *adev, u32 clock,
u32 cntl_reg, u32 status_reg)
{
int r, i;
struct atom_clock_dividers dividers;
uint32_t tmp;
r = amdgpu_atombios_get_clock_dividers(adev,
COMPUTE_GPUCLK_INPUT_FLAG_DEFAULT_GPUCLK,
clock, false, &dividers);
if (r)
return r;
tmp = RREG32_SMC(cntl_reg);
tmp &= ~(CG_DCLK_CNTL__DCLK_DIR_CNTL_EN_MASK |
CG_DCLK_CNTL__DCLK_DIVIDER_MASK);
tmp |= dividers.post_divider;
WREG32_SMC(cntl_reg, tmp);
for (i = 0; i < 100; i++) {
if (RREG32_SMC(status_reg) & CG_DCLK_STATUS__DCLK_STATUS_MASK)
break;
mdelay(10);
}
if (i == 100)
return -ETIMEDOUT;
return 0;
}
static int vi_set_uvd_clocks(struct amdgpu_device *adev, u32 vclk, u32 dclk)
{
int r;
r = vi_set_uvd_clock(adev, vclk, ixCG_VCLK_CNTL, ixCG_VCLK_STATUS);
if (r)
return r;
r = vi_set_uvd_clock(adev, dclk, ixCG_DCLK_CNTL, ixCG_DCLK_STATUS);
return 0;
}
static int vi_set_vce_clocks(struct amdgpu_device *adev, u32 evclk, u32 ecclk)
{
return 0;
}
static void vi_pcie_gen3_enable(struct amdgpu_device *adev)
{
u32 mask;
int ret;
if (pci_is_root_bus(adev->pdev->bus))
return;
if (amdgpu_pcie_gen2 == 0)
return;
if (adev->flags & AMD_IS_APU)
return;
ret = drm_pcie_get_speed_cap_mask(adev->ddev, &mask);
if (ret != 0)
return;
if (!(mask & (DRM_PCIE_SPEED_50 | DRM_PCIE_SPEED_80)))
return;
}
static void vi_program_aspm(struct amdgpu_device *adev)
{
if (amdgpu_aspm == 0)
return;
}
static void vi_enable_doorbell_aperture(struct amdgpu_device *adev,
bool enable)
{
u32 tmp;
if (adev->flags & AMD_IS_APU)
return;
tmp = RREG32(mmBIF_DOORBELL_APER_EN);
if (enable)
tmp = REG_SET_FIELD(tmp, BIF_DOORBELL_APER_EN, BIF_DOORBELL_APER_EN, 1);
else
tmp = REG_SET_FIELD(tmp, BIF_DOORBELL_APER_EN, BIF_DOORBELL_APER_EN, 0);
WREG32(mmBIF_DOORBELL_APER_EN, tmp);
}
int vi_set_ip_blocks(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_TOPAZ:
adev->ip_blocks = topaz_ip_blocks;
adev->num_ip_blocks = ARRAY_SIZE(topaz_ip_blocks);
break;
case CHIP_FIJI:
adev->ip_blocks = fiji_ip_blocks;
adev->num_ip_blocks = ARRAY_SIZE(fiji_ip_blocks);
break;
case CHIP_TONGA:
adev->ip_blocks = tonga_ip_blocks;
adev->num_ip_blocks = ARRAY_SIZE(tonga_ip_blocks);
break;
case CHIP_CARRIZO:
case CHIP_STONEY:
adev->ip_blocks = cz_ip_blocks;
adev->num_ip_blocks = ARRAY_SIZE(cz_ip_blocks);
break;
default:
return -EINVAL;
}
return 0;
}
static uint32_t vi_get_rev_id(struct amdgpu_device *adev)
{
if (adev->asic_type == CHIP_TOPAZ)
return (RREG32(mmPCIE_EFUSE4) & PCIE_EFUSE4__STRAP_BIF_ATI_REV_ID_MASK)
>> PCIE_EFUSE4__STRAP_BIF_ATI_REV_ID__SHIFT;
else if (adev->flags & AMD_IS_APU)
return (RREG32_SMC(ATI_REV_ID_FUSE_MACRO__ADDRESS) & ATI_REV_ID_FUSE_MACRO__MASK)
>> ATI_REV_ID_FUSE_MACRO__SHIFT;
else
return (RREG32(mmCC_DRM_ID_STRAPS) & CC_DRM_ID_STRAPS__ATI_REV_ID_MASK)
>> CC_DRM_ID_STRAPS__ATI_REV_ID__SHIFT;
}
static int vi_common_early_init(void *handle)
{
bool smc_enabled = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (adev->flags & AMD_IS_APU) {
adev->smc_rreg = &cz_smc_rreg;
adev->smc_wreg = &cz_smc_wreg;
} else {
adev->smc_rreg = &vi_smc_rreg;
adev->smc_wreg = &vi_smc_wreg;
}
adev->pcie_rreg = &vi_pcie_rreg;
adev->pcie_wreg = &vi_pcie_wreg;
adev->uvd_ctx_rreg = &vi_uvd_ctx_rreg;
adev->uvd_ctx_wreg = &vi_uvd_ctx_wreg;
adev->didt_rreg = &vi_didt_rreg;
adev->didt_wreg = &vi_didt_wreg;
adev->asic_funcs = &vi_asic_funcs;
if (amdgpu_get_ip_block(adev, AMD_IP_BLOCK_TYPE_SMC) &&
(amdgpu_ip_block_mask & (1 << AMD_IP_BLOCK_TYPE_SMC)))
smc_enabled = true;
adev->rev_id = vi_get_rev_id(adev);
adev->external_rev_id = 0xFF;
switch (adev->asic_type) {
case CHIP_TOPAZ:
adev->has_uvd = false;
adev->cg_flags = 0;
adev->pg_flags = 0;
adev->external_rev_id = 0x1;
break;
case CHIP_FIJI:
adev->has_uvd = true;
adev->cg_flags = 0;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x3c;
break;
case CHIP_TONGA:
adev->has_uvd = true;
adev->cg_flags = 0;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x14;
break;
case CHIP_CARRIZO:
case CHIP_STONEY:
adev->has_uvd = true;
adev->cg_flags = 0;
adev->pg_flags = AMDGPU_PG_SUPPORT_VCE;
adev->external_rev_id = adev->rev_id + 0x1;
break;
default:
return -EINVAL;
}
if (amdgpu_smc_load_fw && smc_enabled)
adev->firmware.smu_load = true;
return 0;
}
static int vi_common_sw_init(void *handle)
{
return 0;
}
static int vi_common_sw_fini(void *handle)
{
return 0;
}
static int vi_common_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vi_init_golden_registers(adev);
vi_pcie_gen3_enable(adev);
vi_program_aspm(adev);
vi_enable_doorbell_aperture(adev, true);
return 0;
}
static int vi_common_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vi_enable_doorbell_aperture(adev, false);
return 0;
}
static int vi_common_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return vi_common_hw_fini(adev);
}
static int vi_common_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return vi_common_hw_init(adev);
}
static bool vi_common_is_idle(void *handle)
{
return true;
}
static int vi_common_wait_for_idle(void *handle)
{
return 0;
}
static void vi_common_print_status(void *handle)
{
return;
}
static int vi_common_soft_reset(void *handle)
{
return 0;
}
static int vi_common_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int vi_common_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
