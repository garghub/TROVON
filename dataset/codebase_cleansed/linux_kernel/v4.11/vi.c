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
WREG32(mmSMC_IND_INDEX_11, (reg));
r = RREG32(mmSMC_IND_DATA_11);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return r;
}
static void vi_smc_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmSMC_IND_INDEX_11, (reg));
WREG32(mmSMC_IND_DATA_11, (v));
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
static u32 vi_gc_cac_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->gc_cac_idx_lock, flags);
WREG32(mmGC_CAC_IND_INDEX, (reg));
r = RREG32(mmGC_CAC_IND_DATA);
spin_unlock_irqrestore(&adev->gc_cac_idx_lock, flags);
return r;
}
static void vi_gc_cac_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->gc_cac_idx_lock, flags);
WREG32(mmGC_CAC_IND_INDEX, (reg));
WREG32(mmGC_CAC_IND_DATA, (v));
spin_unlock_irqrestore(&adev->gc_cac_idx_lock, flags);
}
static void vi_init_golden_registers(struct amdgpu_device *adev)
{
mutex_lock(&adev->grbm_idx_mutex);
if (amdgpu_sriov_vf(adev)) {
xgpu_vi_init_golden_registers(adev);
mutex_unlock(&adev->grbm_idx_mutex);
return;
}
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
case CHIP_POLARIS11:
case CHIP_POLARIS10:
case CHIP_POLARIS12:
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
static bool vi_read_bios_from_rom(struct amdgpu_device *adev,
u8 *bios, u32 length_bytes)
{
u32 *dw_ptr;
unsigned long flags;
u32 i, length_dw;
if (bios == NULL)
return false;
if (length_bytes == 0)
return false;
if (adev->flags & AMD_IS_APU)
return false;
dw_ptr = (u32 *)bios;
length_dw = ALIGN(length_bytes, 4) / 4;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(mmSMC_IND_INDEX_11, ixROM_INDEX);
WREG32(mmSMC_IND_DATA_11, 0);
WREG32(mmSMC_IND_INDEX_11, ixROM_DATA);
for (i = 0; i < length_dw; i++)
dw_ptr[i] = RREG32(mmSMC_IND_DATA_11);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return true;
}
static void vi_detect_hw_virtualization(struct amdgpu_device *adev)
{
uint32_t reg = RREG32(mmBIF_IOV_FUNC_IDENTIFIER);
if (reg & 1)
adev->virt.caps |= AMDGPU_SRIOV_CAPS_IS_VF;
if (reg & 0x80000000)
adev->virt.caps |= AMDGPU_SRIOV_CAPS_ENABLE_IOV;
if (reg == 0) {
if (is_virtual_machine())
adev->virt.caps |= AMDGPU_PASSTHROUGH_MODE;
}
}
static uint32_t vi_get_register_value(struct amdgpu_device *adev,
bool indexed, u32 se_num,
u32 sh_num, u32 reg_offset)
{
if (indexed) {
uint32_t val;
unsigned se_idx = (se_num == 0xffffffff) ? 0 : se_num;
unsigned sh_idx = (sh_num == 0xffffffff) ? 0 : sh_num;
switch (reg_offset) {
case mmCC_RB_BACKEND_DISABLE:
return adev->gfx.config.rb_config[se_idx][sh_idx].rb_backend_disable;
case mmGC_USER_RB_BACKEND_DISABLE:
return adev->gfx.config.rb_config[se_idx][sh_idx].user_rb_backend_disable;
case mmPA_SC_RASTER_CONFIG:
return adev->gfx.config.rb_config[se_idx][sh_idx].raster_config;
case mmPA_SC_RASTER_CONFIG_1:
return adev->gfx.config.rb_config[se_idx][sh_idx].raster_config_1;
}
mutex_lock(&adev->grbm_idx_mutex);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
amdgpu_gfx_select_se_sh(adev, se_num, sh_num, 0xffffffff);
val = RREG32(reg_offset);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
amdgpu_gfx_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
return val;
} else {
unsigned idx;
switch (reg_offset) {
case mmGB_ADDR_CONFIG:
return adev->gfx.config.gb_addr_config;
case mmMC_ARB_RAMCFG:
return adev->gfx.config.mc_arb_ramcfg;
case mmGB_TILE_MODE0:
case mmGB_TILE_MODE1:
case mmGB_TILE_MODE2:
case mmGB_TILE_MODE3:
case mmGB_TILE_MODE4:
case mmGB_TILE_MODE5:
case mmGB_TILE_MODE6:
case mmGB_TILE_MODE7:
case mmGB_TILE_MODE8:
case mmGB_TILE_MODE9:
case mmGB_TILE_MODE10:
case mmGB_TILE_MODE11:
case mmGB_TILE_MODE12:
case mmGB_TILE_MODE13:
case mmGB_TILE_MODE14:
case mmGB_TILE_MODE15:
case mmGB_TILE_MODE16:
case mmGB_TILE_MODE17:
case mmGB_TILE_MODE18:
case mmGB_TILE_MODE19:
case mmGB_TILE_MODE20:
case mmGB_TILE_MODE21:
case mmGB_TILE_MODE22:
case mmGB_TILE_MODE23:
case mmGB_TILE_MODE24:
case mmGB_TILE_MODE25:
case mmGB_TILE_MODE26:
case mmGB_TILE_MODE27:
case mmGB_TILE_MODE28:
case mmGB_TILE_MODE29:
case mmGB_TILE_MODE30:
case mmGB_TILE_MODE31:
idx = (reg_offset - mmGB_TILE_MODE0);
return adev->gfx.config.tile_mode_array[idx];
case mmGB_MACROTILE_MODE0:
case mmGB_MACROTILE_MODE1:
case mmGB_MACROTILE_MODE2:
case mmGB_MACROTILE_MODE3:
case mmGB_MACROTILE_MODE4:
case mmGB_MACROTILE_MODE5:
case mmGB_MACROTILE_MODE6:
case mmGB_MACROTILE_MODE7:
case mmGB_MACROTILE_MODE8:
case mmGB_MACROTILE_MODE9:
case mmGB_MACROTILE_MODE10:
case mmGB_MACROTILE_MODE11:
case mmGB_MACROTILE_MODE12:
case mmGB_MACROTILE_MODE13:
case mmGB_MACROTILE_MODE14:
case mmGB_MACROTILE_MODE15:
idx = (reg_offset - mmGB_MACROTILE_MODE0);
return adev->gfx.config.macrotile_mode_array[idx];
default:
return RREG32(reg_offset);
}
}
}
static int vi_read_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset, u32 *value)
{
const struct amdgpu_allowed_register_entry *asic_register_table = NULL;
const struct amdgpu_allowed_register_entry *asic_register_entry;
uint32_t size, i;
*value = 0;
switch (adev->asic_type) {
case CHIP_TOPAZ:
asic_register_table = tonga_allowed_read_registers;
size = ARRAY_SIZE(tonga_allowed_read_registers);
break;
case CHIP_FIJI:
case CHIP_TONGA:
case CHIP_POLARIS11:
case CHIP_POLARIS10:
case CHIP_POLARIS12:
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
*value = vi_get_register_value(adev,
asic_register_entry->grbm_indexed,
se_num, sh_num, reg_offset);
return 0;
}
}
for (i = 0; i < ARRAY_SIZE(vi_allowed_read_registers); i++) {
if (reg_offset != vi_allowed_read_registers[i].reg_offset)
continue;
if (!vi_allowed_read_registers[i].untouched)
*value = vi_get_register_value(adev,
vi_allowed_read_registers[i].grbm_indexed,
se_num, sh_num, reg_offset);
return 0;
}
return -EINVAL;
}
static int vi_gpu_pci_config_reset(struct amdgpu_device *adev)
{
u32 i;
dev_info(adev->dev, "GPU pci config reset\n");
pci_clear_master(adev->pdev);
amdgpu_pci_config_reset(adev);
udelay(100);
for (i = 0; i < adev->usec_timeout; i++) {
if (RREG32(mmCONFIG_MEMSIZE) != 0xffffffff) {
pci_set_master(adev->pdev);
adev->has_hw_reset = true;
return 0;
}
udelay(1);
}
return -EINVAL;
}
static int vi_asic_reset(struct amdgpu_device *adev)
{
int r;
amdgpu_atombios_scratch_regs_engine_hung(adev, true);
r = vi_gpu_pci_config_reset(adev);
amdgpu_atombios_scratch_regs_engine_hung(adev, false);
return r;
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
int r, i;
struct atom_clock_dividers dividers;
u32 tmp;
r = amdgpu_atombios_get_clock_dividers(adev,
COMPUTE_GPUCLK_INPUT_FLAG_DEFAULT_GPUCLK,
ecclk, false, &dividers);
if (r)
return r;
for (i = 0; i < 100; i++) {
if (RREG32_SMC(ixCG_ECLK_STATUS) & CG_ECLK_STATUS__ECLK_STATUS_MASK)
break;
mdelay(10);
}
if (i == 100)
return -ETIMEDOUT;
tmp = RREG32_SMC(ixCG_ECLK_CNTL);
tmp &= ~(CG_ECLK_CNTL__ECLK_DIR_CNTL_EN_MASK |
CG_ECLK_CNTL__ECLK_DIVIDER_MASK);
tmp |= dividers.post_divider;
WREG32_SMC(ixCG_ECLK_CNTL, tmp);
for (i = 0; i < 100; i++) {
if (RREG32_SMC(ixCG_ECLK_STATUS) & CG_ECLK_STATUS__ECLK_STATUS_MASK)
break;
mdelay(10);
}
if (i == 100)
return -ETIMEDOUT;
return 0;
}
static void vi_pcie_gen3_enable(struct amdgpu_device *adev)
{
if (pci_is_root_bus(adev->pdev->bus))
return;
if (amdgpu_pcie_gen2 == 0)
return;
if (adev->flags & AMD_IS_APU)
return;
if (!(adev->pm.pcie_gen_mask & (CAIL_PCIE_LINK_SPEED_SUPPORT_GEN2 |
CAIL_PCIE_LINK_SPEED_SUPPORT_GEN3)))
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
static uint32_t vi_get_rev_id(struct amdgpu_device *adev)
{
if (adev->flags & AMD_IS_APU)
return (RREG32_SMC(ATI_REV_ID_FUSE_MACRO__ADDRESS) & ATI_REV_ID_FUSE_MACRO__MASK)
>> ATI_REV_ID_FUSE_MACRO__SHIFT;
else
return (RREG32(mmPCIE_EFUSE4) & PCIE_EFUSE4__STRAP_BIF_ATI_REV_ID_MASK)
>> PCIE_EFUSE4__STRAP_BIF_ATI_REV_ID__SHIFT;
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
adev->gc_cac_rreg = &vi_gc_cac_rreg;
adev->gc_cac_wreg = &vi_gc_cac_wreg;
adev->asic_funcs = &vi_asic_funcs;
if (amdgpu_get_ip_block(adev, AMD_IP_BLOCK_TYPE_SMC) &&
(amdgpu_ip_block_mask & (1 << AMD_IP_BLOCK_TYPE_SMC)))
smc_enabled = true;
if (amdgpu_sriov_vf(adev)) {
amdgpu_virt_init_setting(adev);
xgpu_vi_mailbox_set_irq_funcs(adev);
}
adev->rev_id = vi_get_rev_id(adev);
adev->external_rev_id = 0xFF;
switch (adev->asic_type) {
case CHIP_TOPAZ:
adev->cg_flags = 0;
adev->pg_flags = 0;
adev->external_rev_id = 0x1;
break;
case CHIP_FIJI:
adev->cg_flags = AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CGTS_LS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_ROM_MGCG |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_UVD_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x3c;
break;
case CHIP_TONGA:
adev->cg_flags = AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_ROM_MGCG |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_DRM_LS |
AMD_CG_SUPPORT_UVD_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x14;
break;
case CHIP_POLARIS11:
adev->cg_flags = AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_3D_CGCG |
AMD_CG_SUPPORT_GFX_3D_CGLS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_BIF_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_ROM_MGCG |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_DRM_LS |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_VCE_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x5A;
break;
case CHIP_POLARIS10:
adev->cg_flags = AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_3D_CGCG |
AMD_CG_SUPPORT_GFX_3D_CGLS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_BIF_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_ROM_MGCG |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_DRM_LS |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_VCE_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x50;
break;
case CHIP_POLARIS12:
adev->cg_flags = AMD_CG_SUPPORT_UVD_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 0x64;
break;
case CHIP_CARRIZO:
adev->cg_flags = AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGTS_LS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_VCE_MGCG;
adev->pg_flags = 0;
if (adev->rev_id != 0x00) {
adev->pg_flags |=
AMD_PG_SUPPORT_GFX_SMG |
AMD_PG_SUPPORT_GFX_PIPELINE |
AMD_PG_SUPPORT_CP |
AMD_PG_SUPPORT_UVD |
AMD_PG_SUPPORT_VCE;
}
adev->external_rev_id = adev->rev_id + 0x1;
break;
case CHIP_STONEY:
adev->cg_flags = AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGTS_LS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_VCE_MGCG;
adev->pg_flags = AMD_PG_SUPPORT_GFX_PG |
AMD_PG_SUPPORT_GFX_SMG |
AMD_PG_SUPPORT_GFX_PIPELINE |
AMD_PG_SUPPORT_CP |
AMD_PG_SUPPORT_UVD |
AMD_PG_SUPPORT_VCE;
adev->external_rev_id = adev->rev_id + 0x61;
break;
default:
return -EINVAL;
}
if (amdgpu_smc_load_fw && smc_enabled)
adev->firmware.smu_load = true;
amdgpu_get_pcie_info(adev);
return 0;
}
static int vi_common_late_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
xgpu_vi_mailbox_get_irq(adev);
return 0;
}
static int vi_common_sw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
xgpu_vi_mailbox_add_irq_id(adev);
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
if (amdgpu_sriov_vf(adev))
xgpu_vi_mailbox_put_irq(adev);
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
static int vi_common_soft_reset(void *handle)
{
return 0;
}
static void vi_update_bif_medium_grain_light_sleep(struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
temp = data = RREG32_PCIE(ixPCIE_CNTL2);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_BIF_LS))
data |= PCIE_CNTL2__SLV_MEM_LS_EN_MASK |
PCIE_CNTL2__MST_MEM_LS_EN_MASK |
PCIE_CNTL2__REPLAY_MEM_LS_EN_MASK;
else
data &= ~(PCIE_CNTL2__SLV_MEM_LS_EN_MASK |
PCIE_CNTL2__MST_MEM_LS_EN_MASK |
PCIE_CNTL2__REPLAY_MEM_LS_EN_MASK);
if (temp != data)
WREG32_PCIE(ixPCIE_CNTL2, data);
}
static void vi_update_hdp_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
temp = data = RREG32(mmHDP_HOST_PATH_CNTL);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_HDP_MGCG))
data &= ~HDP_HOST_PATH_CNTL__CLOCK_GATING_DIS_MASK;
else
data |= HDP_HOST_PATH_CNTL__CLOCK_GATING_DIS_MASK;
if (temp != data)
WREG32(mmHDP_HOST_PATH_CNTL, data);
}
static void vi_update_hdp_light_sleep(struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
temp = data = RREG32(mmHDP_MEM_POWER_LS);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_HDP_LS))
data |= HDP_MEM_POWER_LS__LS_ENABLE_MASK;
else
data &= ~HDP_MEM_POWER_LS__LS_ENABLE_MASK;
if (temp != data)
WREG32(mmHDP_MEM_POWER_LS, data);
}
static void vi_update_drm_light_sleep(struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
temp = data = RREG32(0x157a);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_DRM_LS))
data |= 1;
else
data &= ~1;
if (temp != data)
WREG32(0x157a, data);
}
static void vi_update_rom_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t temp, data;
temp = data = RREG32_SMC(ixCGTT_ROM_CLK_CTRL0);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_ROM_MGCG))
data &= ~(CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK |
CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE1_MASK);
else
data |= CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK |
CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE1_MASK;
if (temp != data)
WREG32_SMC(ixCGTT_ROM_CLK_CTRL0, data);
}
static int vi_common_set_clockgating_state_by_smu(void *handle,
enum amd_clockgating_state state)
{
uint32_t msg_id, pp_state = 0;
uint32_t pp_support_state = 0;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
void *pp_handle = adev->powerplay.pp_handle;
if (adev->cg_flags & (AMD_CG_SUPPORT_MC_LS | AMD_CG_SUPPORT_MC_MGCG)) {
if (adev->cg_flags & AMD_CG_SUPPORT_MC_LS) {
pp_support_state = AMD_CG_SUPPORT_MC_LS;
pp_state = PP_STATE_LS;
}
if (adev->cg_flags & AMD_CG_SUPPORT_MC_MGCG) {
pp_support_state |= AMD_CG_SUPPORT_MC_MGCG;
pp_state |= PP_STATE_CG;
}
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_MC,
pp_support_state,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & (AMD_CG_SUPPORT_SDMA_LS | AMD_CG_SUPPORT_SDMA_MGCG)) {
if (adev->cg_flags & AMD_CG_SUPPORT_SDMA_LS) {
pp_support_state = AMD_CG_SUPPORT_SDMA_LS;
pp_state = PP_STATE_LS;
}
if (adev->cg_flags & AMD_CG_SUPPORT_SDMA_MGCG) {
pp_support_state |= AMD_CG_SUPPORT_SDMA_MGCG;
pp_state |= PP_STATE_CG;
}
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_SDMA,
pp_support_state,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & (AMD_CG_SUPPORT_HDP_LS | AMD_CG_SUPPORT_HDP_MGCG)) {
if (adev->cg_flags & AMD_CG_SUPPORT_HDP_LS) {
pp_support_state = AMD_CG_SUPPORT_HDP_LS;
pp_state = PP_STATE_LS;
}
if (adev->cg_flags & AMD_CG_SUPPORT_HDP_MGCG) {
pp_support_state |= AMD_CG_SUPPORT_HDP_MGCG;
pp_state |= PP_STATE_CG;
}
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_HDP,
pp_support_state,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & AMD_CG_SUPPORT_BIF_LS) {
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
else
pp_state = PP_STATE_LS;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_BIF,
PP_STATE_SUPPORT_LS,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & AMD_CG_SUPPORT_BIF_MGCG) {
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
else
pp_state = PP_STATE_CG;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_BIF,
PP_STATE_SUPPORT_CG,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & AMD_CG_SUPPORT_DRM_LS) {
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
else
pp_state = PP_STATE_LS;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_DRM,
PP_STATE_SUPPORT_LS,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
if (adev->cg_flags & AMD_CG_SUPPORT_ROM_MGCG) {
if (state == AMD_CG_STATE_UNGATE)
pp_state = 0;
else
pp_state = PP_STATE_CG;
msg_id = PP_CG_MSG_ID(PP_GROUP_SYS,
PP_BLOCK_SYS_ROM,
PP_STATE_SUPPORT_CG,
pp_state);
amd_set_clockgating_by_smu(pp_handle, msg_id);
}
return 0;
}
static int vi_common_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
switch (adev->asic_type) {
case CHIP_FIJI:
vi_update_bif_medium_grain_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_hdp_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_hdp_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_rom_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
case CHIP_CARRIZO:
case CHIP_STONEY:
vi_update_bif_medium_grain_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_hdp_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_hdp_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
vi_update_drm_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
case CHIP_TONGA:
case CHIP_POLARIS10:
case CHIP_POLARIS11:
case CHIP_POLARIS12:
vi_common_set_clockgating_state_by_smu(adev, state);
default:
break;
}
return 0;
}
static int vi_common_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void vi_common_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int data;
data = RREG32_PCIE(ixPCIE_CNTL2);
if (data & PCIE_CNTL2__SLV_MEM_LS_EN_MASK)
*flags |= AMD_CG_SUPPORT_BIF_LS;
data = RREG32(mmHDP_MEM_POWER_LS);
if (data & HDP_MEM_POWER_LS__LS_ENABLE_MASK)
*flags |= AMD_CG_SUPPORT_HDP_LS;
data = RREG32(mmHDP_HOST_PATH_CNTL);
if (!(data & HDP_HOST_PATH_CNTL__CLOCK_GATING_DIS_MASK))
*flags |= AMD_CG_SUPPORT_HDP_MGCG;
data = RREG32_SMC(ixCGTT_ROM_CLK_CTRL0);
if (!(data & CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK))
*flags |= AMD_CG_SUPPORT_ROM_MGCG;
}
int vi_set_ip_blocks(struct amdgpu_device *adev)
{
vi_detect_hw_virtualization(adev);
if (amdgpu_sriov_vf(adev))
adev->virt.ops = &xgpu_vi_virt_ops;
switch (adev->asic_type) {
case CHIP_TOPAZ:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v7_4_ip_block);
amdgpu_ip_block_add(adev, &iceland_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v2_4_ip_block);
break;
case CHIP_FIJI:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v8_5_ip_block);
amdgpu_ip_block_add(adev, &tonga_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display || amdgpu_sriov_vf(adev))
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v10_1_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v3_0_ip_block);
if (!amdgpu_sriov_vf(adev)) {
amdgpu_ip_block_add(adev, &uvd_v6_0_ip_block);
amdgpu_ip_block_add(adev, &vce_v3_0_ip_block);
}
break;
case CHIP_TONGA:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v8_0_ip_block);
amdgpu_ip_block_add(adev, &tonga_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display || amdgpu_sriov_vf(adev))
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v10_0_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v3_0_ip_block);
if (!amdgpu_sriov_vf(adev)) {
amdgpu_ip_block_add(adev, &uvd_v5_0_ip_block);
amdgpu_ip_block_add(adev, &vce_v3_0_ip_block);
}
break;
case CHIP_POLARIS11:
case CHIP_POLARIS10:
case CHIP_POLARIS12:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v8_1_ip_block);
amdgpu_ip_block_add(adev, &tonga_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v11_2_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v3_1_ip_block);
amdgpu_ip_block_add(adev, &uvd_v6_3_ip_block);
amdgpu_ip_block_add(adev, &vce_v3_4_ip_block);
break;
case CHIP_CARRIZO:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v8_0_ip_block);
amdgpu_ip_block_add(adev, &cz_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v11_0_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v3_0_ip_block);
amdgpu_ip_block_add(adev, &uvd_v6_0_ip_block);
amdgpu_ip_block_add(adev, &vce_v3_1_ip_block);
#if defined(CONFIG_DRM_AMD_ACP)
amdgpu_ip_block_add(adev, &acp_ip_block);
#endif
break;
case CHIP_STONEY:
amdgpu_ip_block_add(adev, &vi_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v8_0_ip_block);
amdgpu_ip_block_add(adev, &cz_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v11_0_ip_block);
amdgpu_ip_block_add(adev, &gfx_v8_1_ip_block);
amdgpu_ip_block_add(adev, &sdma_v3_0_ip_block);
amdgpu_ip_block_add(adev, &uvd_v6_2_ip_block);
amdgpu_ip_block_add(adev, &vce_v3_4_ip_block);
#if defined(CONFIG_DRM_AMD_ACP)
amdgpu_ip_block_add(adev, &acp_ip_block);
#endif
break;
default:
return -EINVAL;
}
return 0;
}
