static u32 si_pcie_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(AMDGPU_PCIE_INDEX, reg);
(void)RREG32(AMDGPU_PCIE_INDEX);
r = RREG32(AMDGPU_PCIE_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static void si_pcie_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(AMDGPU_PCIE_INDEX, reg);
(void)RREG32(AMDGPU_PCIE_INDEX);
WREG32(AMDGPU_PCIE_DATA, v);
(void)RREG32(AMDGPU_PCIE_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static u32 si_pciep_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(PCIE_PORT_INDEX, ((reg) & 0xff));
(void)RREG32(PCIE_PORT_INDEX);
r = RREG32(PCIE_PORT_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static void si_pciep_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(PCIE_PORT_INDEX, ((reg) & 0xff));
(void)RREG32(PCIE_PORT_INDEX);
WREG32(PCIE_PORT_DATA, (v));
(void)RREG32(PCIE_PORT_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static u32 si_smc_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(SMC_IND_INDEX_0, (reg));
r = RREG32(SMC_IND_DATA_0);
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
return r;
}
static void si_smc_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->smc_idx_lock, flags);
WREG32(SMC_IND_INDEX_0, (reg));
WREG32(SMC_IND_DATA_0, (v));
spin_unlock_irqrestore(&adev->smc_idx_lock, flags);
}
static uint32_t si_get_register_value(struct amdgpu_device *adev,
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
default:
return RREG32(reg_offset);
}
}
}
static int si_read_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset, u32 *value)
{
uint32_t i;
*value = 0;
for (i = 0; i < ARRAY_SIZE(si_allowed_read_registers); i++) {
bool indexed = si_allowed_read_registers[i].grbm_indexed;
if (reg_offset != si_allowed_read_registers[i].reg_offset)
continue;
*value = si_get_register_value(adev, indexed, se_num, sh_num,
reg_offset);
return 0;
}
return -EINVAL;
}
static bool si_read_disabled_bios(struct amdgpu_device *adev)
{
u32 bus_cntl;
u32 d1vga_control = 0;
u32 d2vga_control = 0;
u32 vga_render_control = 0;
u32 rom_cntl;
bool r;
bus_cntl = RREG32(R600_BUS_CNTL);
if (adev->mode_info.num_crtc) {
d1vga_control = RREG32(AVIVO_D1VGA_CONTROL);
d2vga_control = RREG32(AVIVO_D2VGA_CONTROL);
vga_render_control = RREG32(VGA_RENDER_CONTROL);
}
rom_cntl = RREG32(R600_ROM_CNTL);
WREG32(R600_BUS_CNTL, (bus_cntl & ~R600_BIOS_ROM_DIS));
if (adev->mode_info.num_crtc) {
WREG32(AVIVO_D1VGA_CONTROL,
(d1vga_control & ~(AVIVO_DVGA_CONTROL_MODE_ENABLE |
AVIVO_DVGA_CONTROL_TIMING_SELECT)));
WREG32(AVIVO_D2VGA_CONTROL,
(d2vga_control & ~(AVIVO_DVGA_CONTROL_MODE_ENABLE |
AVIVO_DVGA_CONTROL_TIMING_SELECT)));
WREG32(VGA_RENDER_CONTROL,
(vga_render_control & C_000300_VGA_VSTATUS_CNTL));
}
WREG32(R600_ROM_CNTL, rom_cntl | R600_SCK_OVERWRITE);
r = amdgpu_read_bios(adev);
WREG32(R600_BUS_CNTL, bus_cntl);
if (adev->mode_info.num_crtc) {
WREG32(AVIVO_D1VGA_CONTROL, d1vga_control);
WREG32(AVIVO_D2VGA_CONTROL, d2vga_control);
WREG32(VGA_RENDER_CONTROL, vga_render_control);
}
WREG32(R600_ROM_CNTL, rom_cntl);
return r;
}
static int si_asic_reset(struct amdgpu_device *adev)
{
return 0;
}
static u32 si_get_config_memsize(struct amdgpu_device *adev)
{
return RREG32(mmCONFIG_MEMSIZE);
}
static void si_vga_set_state(struct amdgpu_device *adev, bool state)
{
uint32_t temp;
temp = RREG32(CONFIG_CNTL);
if (state == false) {
temp &= ~(1<<0);
temp |= (1<<1);
} else {
temp &= ~(1<<1);
}
WREG32(CONFIG_CNTL, temp);
}
static u32 si_get_xclk(struct amdgpu_device *adev)
{
u32 reference_clock = adev->clock.spll.reference_freq;
u32 tmp;
tmp = RREG32(CG_CLKPIN_CNTL_2);
if (tmp & MUX_TCLK_TO_XCLK)
return TCLK;
tmp = RREG32(CG_CLKPIN_CNTL);
if (tmp & XTALIN_DIVIDE)
return reference_clock / 4;
return reference_clock;
}
static int si_set_uvd_clocks(struct amdgpu_device *adev, u32 vclk, u32 dclk)
{
return 0;
}
static void si_detect_hw_virtualization(struct amdgpu_device *adev)
{
if (is_virtual_machine())
adev->virt.caps |= AMDGPU_PASSTHROUGH_MODE;
}
static uint32_t si_get_rev_id(struct amdgpu_device *adev)
{
return (RREG32(CC_DRM_ID_STRAPS) & CC_DRM_ID_STRAPS__ATI_REV_ID_MASK)
>> CC_DRM_ID_STRAPS__ATI_REV_ID__SHIFT;
}
static int si_common_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->smc_rreg = &si_smc_rreg;
adev->smc_wreg = &si_smc_wreg;
adev->pcie_rreg = &si_pcie_rreg;
adev->pcie_wreg = &si_pcie_wreg;
adev->pciep_rreg = &si_pciep_rreg;
adev->pciep_wreg = &si_pciep_wreg;
adev->uvd_ctx_rreg = NULL;
adev->uvd_ctx_wreg = NULL;
adev->didt_rreg = NULL;
adev->didt_wreg = NULL;
adev->asic_funcs = &si_asic_funcs;
adev->rev_id = si_get_rev_id(adev);
adev->external_rev_id = 0xFF;
switch (adev->asic_type) {
case CHIP_TAHITI:
adev->cg_flags =
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_VCE_MGCG |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_HDP_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = (adev->rev_id == 0) ? 1 :
(adev->rev_id == 1) ? 5 : 6;
break;
case CHIP_PITCAIRN:
adev->cg_flags =
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_VCE_MGCG |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_HDP_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 20;
break;
case CHIP_VERDE:
adev->cg_flags =
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CGTS_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_VCE_MGCG |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_HDP_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = adev->rev_id + 40;
break;
case CHIP_OLAND:
adev->cg_flags =
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_UVD_MGCG |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_HDP_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = 60;
break;
case CHIP_HAINAN:
adev->cg_flags =
AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_GFX_CGTS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_MC_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_HDP_MGCG;
adev->pg_flags = 0;
adev->external_rev_id = 70;
break;
default:
return -EINVAL;
}
return 0;
}
static int si_common_sw_init(void *handle)
{
return 0;
}
static int si_common_sw_fini(void *handle)
{
return 0;
}
static void si_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_TAHITI:
amdgpu_program_register_sequence(adev,
tahiti_golden_registers,
(const u32)ARRAY_SIZE(tahiti_golden_registers));
amdgpu_program_register_sequence(adev,
tahiti_golden_rlc_registers,
(const u32)ARRAY_SIZE(tahiti_golden_rlc_registers));
amdgpu_program_register_sequence(adev,
tahiti_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(tahiti_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
tahiti_golden_registers2,
(const u32)ARRAY_SIZE(tahiti_golden_registers2));
break;
case CHIP_PITCAIRN:
amdgpu_program_register_sequence(adev,
pitcairn_golden_registers,
(const u32)ARRAY_SIZE(pitcairn_golden_registers));
amdgpu_program_register_sequence(adev,
pitcairn_golden_rlc_registers,
(const u32)ARRAY_SIZE(pitcairn_golden_rlc_registers));
amdgpu_program_register_sequence(adev,
pitcairn_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(pitcairn_mgcg_cgcg_init));
break;
case CHIP_VERDE:
amdgpu_program_register_sequence(adev,
verde_golden_registers,
(const u32)ARRAY_SIZE(verde_golden_registers));
amdgpu_program_register_sequence(adev,
verde_golden_rlc_registers,
(const u32)ARRAY_SIZE(verde_golden_rlc_registers));
amdgpu_program_register_sequence(adev,
verde_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(verde_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
verde_pg_init,
(const u32)ARRAY_SIZE(verde_pg_init));
break;
case CHIP_OLAND:
amdgpu_program_register_sequence(adev,
oland_golden_registers,
(const u32)ARRAY_SIZE(oland_golden_registers));
amdgpu_program_register_sequence(adev,
oland_golden_rlc_registers,
(const u32)ARRAY_SIZE(oland_golden_rlc_registers));
amdgpu_program_register_sequence(adev,
oland_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(oland_mgcg_cgcg_init));
break;
case CHIP_HAINAN:
amdgpu_program_register_sequence(adev,
hainan_golden_registers,
(const u32)ARRAY_SIZE(hainan_golden_registers));
amdgpu_program_register_sequence(adev,
hainan_golden_registers2,
(const u32)ARRAY_SIZE(hainan_golden_registers2));
amdgpu_program_register_sequence(adev,
hainan_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(hainan_mgcg_cgcg_init));
break;
default:
BUG();
}
}
static void si_pcie_gen3_enable(struct amdgpu_device *adev)
{
struct pci_dev *root = adev->pdev->bus->self;
int bridge_pos, gpu_pos;
u32 speed_cntl, mask, current_data_rate;
int ret, i;
u16 tmp16;
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
speed_cntl = RREG32_PCIE_PORT(PCIE_LC_SPEED_CNTL);
current_data_rate = (speed_cntl & LC_CURRENT_DATA_RATE_MASK) >>
LC_CURRENT_DATA_RATE_SHIFT;
if (mask & DRM_PCIE_SPEED_80) {
if (current_data_rate == 2) {
DRM_INFO("PCIE gen 3 link speeds already enabled\n");
return;
}
DRM_INFO("enabling PCIE gen 3 link speeds, disable with amdgpu.pcie_gen2=0\n");
} else if (mask & DRM_PCIE_SPEED_50) {
if (current_data_rate == 1) {
DRM_INFO("PCIE gen 2 link speeds already enabled\n");
return;
}
DRM_INFO("enabling PCIE gen 2 link speeds, disable with amdgpu.pcie_gen2=0\n");
}
bridge_pos = pci_pcie_cap(root);
if (!bridge_pos)
return;
gpu_pos = pci_pcie_cap(adev->pdev);
if (!gpu_pos)
return;
if (mask & DRM_PCIE_SPEED_80) {
if (current_data_rate != 2) {
u16 bridge_cfg, gpu_cfg;
u16 bridge_cfg2, gpu_cfg2;
u32 max_lw, current_lw, tmp;
pci_read_config_word(root, bridge_pos + PCI_EXP_LNKCTL, &bridge_cfg);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL, &gpu_cfg);
tmp16 = bridge_cfg | PCI_EXP_LNKCTL_HAWD;
pci_write_config_word(root, bridge_pos + PCI_EXP_LNKCTL, tmp16);
tmp16 = gpu_cfg | PCI_EXP_LNKCTL_HAWD;
pci_write_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL, tmp16);
tmp = RREG32_PCIE(PCIE_LC_STATUS1);
max_lw = (tmp & LC_DETECTED_LINK_WIDTH_MASK) >> LC_DETECTED_LINK_WIDTH_SHIFT;
current_lw = (tmp & LC_OPERATING_LINK_WIDTH_MASK) >> LC_OPERATING_LINK_WIDTH_SHIFT;
if (current_lw < max_lw) {
tmp = RREG32_PCIE_PORT(PCIE_LC_LINK_WIDTH_CNTL);
if (tmp & LC_RENEGOTIATION_SUPPORT) {
tmp &= ~(LC_LINK_WIDTH_MASK | LC_UPCONFIGURE_DIS);
tmp |= (max_lw << LC_LINK_WIDTH_SHIFT);
tmp |= LC_UPCONFIGURE_SUPPORT | LC_RENEGOTIATE_EN | LC_RECONFIG_NOW;
WREG32_PCIE_PORT(PCIE_LC_LINK_WIDTH_CNTL, tmp);
}
}
for (i = 0; i < 10; i++) {
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_DEVSTA, &tmp16);
if (tmp16 & PCI_EXP_DEVSTA_TRPND)
break;
pci_read_config_word(root, bridge_pos + PCI_EXP_LNKCTL, &bridge_cfg);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL, &gpu_cfg);
pci_read_config_word(root, bridge_pos + PCI_EXP_LNKCTL2, &bridge_cfg2);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL2, &gpu_cfg2);
tmp = RREG32_PCIE_PORT(PCIE_LC_CNTL4);
tmp |= LC_SET_QUIESCE;
WREG32_PCIE_PORT(PCIE_LC_CNTL4, tmp);
tmp = RREG32_PCIE_PORT(PCIE_LC_CNTL4);
tmp |= LC_REDO_EQ;
WREG32_PCIE_PORT(PCIE_LC_CNTL4, tmp);
mdelay(100);
pci_read_config_word(root, bridge_pos + PCI_EXP_LNKCTL, &tmp16);
tmp16 &= ~PCI_EXP_LNKCTL_HAWD;
tmp16 |= (bridge_cfg & PCI_EXP_LNKCTL_HAWD);
pci_write_config_word(root, bridge_pos + PCI_EXP_LNKCTL, tmp16);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL, &tmp16);
tmp16 &= ~PCI_EXP_LNKCTL_HAWD;
tmp16 |= (gpu_cfg & PCI_EXP_LNKCTL_HAWD);
pci_write_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL, tmp16);
pci_read_config_word(root, bridge_pos + PCI_EXP_LNKCTL2, &tmp16);
tmp16 &= ~((1 << 4) | (7 << 9));
tmp16 |= (bridge_cfg2 & ((1 << 4) | (7 << 9)));
pci_write_config_word(root, bridge_pos + PCI_EXP_LNKCTL2, tmp16);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL2, &tmp16);
tmp16 &= ~((1 << 4) | (7 << 9));
tmp16 |= (gpu_cfg2 & ((1 << 4) | (7 << 9)));
pci_write_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL2, tmp16);
tmp = RREG32_PCIE_PORT(PCIE_LC_CNTL4);
tmp &= ~LC_SET_QUIESCE;
WREG32_PCIE_PORT(PCIE_LC_CNTL4, tmp);
}
}
}
speed_cntl |= LC_FORCE_EN_SW_SPEED_CHANGE | LC_FORCE_DIS_HW_SPEED_CHANGE;
speed_cntl &= ~LC_FORCE_DIS_SW_SPEED_CHANGE;
WREG32_PCIE_PORT(PCIE_LC_SPEED_CNTL, speed_cntl);
pci_read_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL2, &tmp16);
tmp16 &= ~0xf;
if (mask & DRM_PCIE_SPEED_80)
tmp16 |= 3;
else if (mask & DRM_PCIE_SPEED_50)
tmp16 |= 2;
else
tmp16 |= 1;
pci_write_config_word(adev->pdev, gpu_pos + PCI_EXP_LNKCTL2, tmp16);
speed_cntl = RREG32_PCIE_PORT(PCIE_LC_SPEED_CNTL);
speed_cntl |= LC_INITIATE_LINK_SPEED_CHANGE;
WREG32_PCIE_PORT(PCIE_LC_SPEED_CNTL, speed_cntl);
for (i = 0; i < adev->usec_timeout; i++) {
speed_cntl = RREG32_PCIE_PORT(PCIE_LC_SPEED_CNTL);
if ((speed_cntl & LC_INITIATE_LINK_SPEED_CHANGE) == 0)
break;
udelay(1);
}
}
static inline u32 si_pif_phy0_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(EVERGREEN_PIF_PHY0_INDEX, ((reg) & 0xffff));
r = RREG32(EVERGREEN_PIF_PHY0_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static inline void si_pif_phy0_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(EVERGREEN_PIF_PHY0_INDEX, ((reg) & 0xffff));
WREG32(EVERGREEN_PIF_PHY0_DATA, (v));
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static inline u32 si_pif_phy1_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags;
u32 r;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(EVERGREEN_PIF_PHY1_INDEX, ((reg) & 0xffff));
r = RREG32(EVERGREEN_PIF_PHY1_DATA);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static inline void si_pif_phy1_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(EVERGREEN_PIF_PHY1_INDEX, ((reg) & 0xffff));
WREG32(EVERGREEN_PIF_PHY1_DATA, (v));
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static void si_program_aspm(struct amdgpu_device *adev)
{
u32 data, orig;
bool disable_l0s = false, disable_l1 = false, disable_plloff_in_l1 = false;
bool disable_clkreq = false;
if (amdgpu_aspm == 0)
return;
if (adev->flags & AMD_IS_APU)
return;
orig = data = RREG32_PCIE_PORT(PCIE_LC_N_FTS_CNTL);
data &= ~LC_XMIT_N_FTS_MASK;
data |= LC_XMIT_N_FTS(0x24) | LC_XMIT_N_FTS_OVERRIDE_EN;
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_N_FTS_CNTL, data);
orig = data = RREG32_PCIE_PORT(PCIE_LC_CNTL3);
data |= LC_GO_TO_RECOVERY;
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_CNTL3, data);
orig = data = RREG32_PCIE(PCIE_P_CNTL);
data |= P_IGNORE_EDB_ERR;
if (orig != data)
WREG32_PCIE(PCIE_P_CNTL, data);
orig = data = RREG32_PCIE_PORT(PCIE_LC_CNTL);
data &= ~(LC_L0S_INACTIVITY_MASK | LC_L1_INACTIVITY_MASK);
data |= LC_PMI_TO_L1_DIS;
if (!disable_l0s)
data |= LC_L0S_INACTIVITY(7);
if (!disable_l1) {
data |= LC_L1_INACTIVITY(7);
data &= ~LC_PMI_TO_L1_DIS;
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_CNTL, data);
if (!disable_plloff_in_l1) {
bool clk_req_support;
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_0);
data &= ~(PLL_POWER_STATE_IN_OFF_0_MASK | PLL_POWER_STATE_IN_TXS2_0_MASK);
data |= PLL_POWER_STATE_IN_OFF_0(7) | PLL_POWER_STATE_IN_TXS2_0(7);
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_0, data);
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_1);
data &= ~(PLL_POWER_STATE_IN_OFF_1_MASK | PLL_POWER_STATE_IN_TXS2_1_MASK);
data |= PLL_POWER_STATE_IN_OFF_1(7) | PLL_POWER_STATE_IN_TXS2_1(7);
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_1, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_0);
data &= ~(PLL_POWER_STATE_IN_OFF_0_MASK | PLL_POWER_STATE_IN_TXS2_0_MASK);
data |= PLL_POWER_STATE_IN_OFF_0(7) | PLL_POWER_STATE_IN_TXS2_0(7);
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_0, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_1);
data &= ~(PLL_POWER_STATE_IN_OFF_1_MASK | PLL_POWER_STATE_IN_TXS2_1_MASK);
data |= PLL_POWER_STATE_IN_OFF_1(7) | PLL_POWER_STATE_IN_TXS2_1(7);
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_1, data);
if ((adev->family != CHIP_OLAND) && (adev->family != CHIP_HAINAN)) {
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_0);
data &= ~PLL_RAMP_UP_TIME_0_MASK;
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_0, data);
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_1);
data &= ~PLL_RAMP_UP_TIME_1_MASK;
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_1, data);
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_2);
data &= ~PLL_RAMP_UP_TIME_2_MASK;
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_2, data);
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_PWRDOWN_3);
data &= ~PLL_RAMP_UP_TIME_3_MASK;
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_PWRDOWN_3, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_0);
data &= ~PLL_RAMP_UP_TIME_0_MASK;
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_0, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_1);
data &= ~PLL_RAMP_UP_TIME_1_MASK;
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_1, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_2);
data &= ~PLL_RAMP_UP_TIME_2_MASK;
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_2, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_PWRDOWN_3);
data &= ~PLL_RAMP_UP_TIME_3_MASK;
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_PWRDOWN_3, data);
}
orig = data = RREG32_PCIE_PORT(PCIE_LC_LINK_WIDTH_CNTL);
data &= ~LC_DYN_LANES_PWR_STATE_MASK;
data |= LC_DYN_LANES_PWR_STATE(3);
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_LINK_WIDTH_CNTL, data);
orig = data = si_pif_phy0_rreg(adev,PB0_PIF_CNTL);
data &= ~LS2_EXIT_TIME_MASK;
if ((adev->family == CHIP_OLAND) || (adev->family == CHIP_HAINAN))
data |= LS2_EXIT_TIME(5);
if (orig != data)
si_pif_phy0_wreg(adev,PB0_PIF_CNTL, data);
orig = data = si_pif_phy1_rreg(adev,PB1_PIF_CNTL);
data &= ~LS2_EXIT_TIME_MASK;
if ((adev->family == CHIP_OLAND) || (adev->family == CHIP_HAINAN))
data |= LS2_EXIT_TIME(5);
if (orig != data)
si_pif_phy1_wreg(adev,PB1_PIF_CNTL, data);
if (!disable_clkreq &&
!pci_is_root_bus(adev->pdev->bus)) {
struct pci_dev *root = adev->pdev->bus->self;
u32 lnkcap;
clk_req_support = false;
pcie_capability_read_dword(root, PCI_EXP_LNKCAP, &lnkcap);
if (lnkcap & PCI_EXP_LNKCAP_CLKPM)
clk_req_support = true;
} else {
clk_req_support = false;
}
if (clk_req_support) {
orig = data = RREG32_PCIE_PORT(PCIE_LC_CNTL2);
data |= LC_ALLOW_PDWN_IN_L1 | LC_ALLOW_PDWN_IN_L23;
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_CNTL2, data);
orig = data = RREG32(THM_CLK_CNTL);
data &= ~(CMON_CLK_SEL_MASK | TMON_CLK_SEL_MASK);
data |= CMON_CLK_SEL(1) | TMON_CLK_SEL(1);
if (orig != data)
WREG32(THM_CLK_CNTL, data);
orig = data = RREG32(MISC_CLK_CNTL);
data &= ~(DEEP_SLEEP_CLK_SEL_MASK | ZCLK_SEL_MASK);
data |= DEEP_SLEEP_CLK_SEL(1) | ZCLK_SEL(1);
if (orig != data)
WREG32(MISC_CLK_CNTL, data);
orig = data = RREG32(CG_CLKPIN_CNTL);
data &= ~BCLK_AS_XCLK;
if (orig != data)
WREG32(CG_CLKPIN_CNTL, data);
orig = data = RREG32(CG_CLKPIN_CNTL_2);
data &= ~FORCE_BIF_REFCLK_EN;
if (orig != data)
WREG32(CG_CLKPIN_CNTL_2, data);
orig = data = RREG32(MPLL_BYPASSCLK_SEL);
data &= ~MPLL_CLKOUT_SEL_MASK;
data |= MPLL_CLKOUT_SEL(4);
if (orig != data)
WREG32(MPLL_BYPASSCLK_SEL, data);
orig = data = RREG32(SPLL_CNTL_MODE);
data &= ~SPLL_REFCLK_SEL_MASK;
if (orig != data)
WREG32(SPLL_CNTL_MODE, data);
}
}
} else {
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_CNTL, data);
}
orig = data = RREG32_PCIE(PCIE_CNTL2);
data |= SLV_MEM_LS_EN | MST_MEM_LS_EN | REPLAY_MEM_LS_EN;
if (orig != data)
WREG32_PCIE(PCIE_CNTL2, data);
if (!disable_l0s) {
data = RREG32_PCIE_PORT(PCIE_LC_N_FTS_CNTL);
if((data & LC_N_FTS_MASK) == LC_N_FTS_MASK) {
data = RREG32_PCIE(PCIE_LC_STATUS1);
if ((data & LC_REVERSE_XMIT) && (data & LC_REVERSE_RCVR)) {
orig = data = RREG32_PCIE_PORT(PCIE_LC_CNTL);
data &= ~LC_L0S_INACTIVITY_MASK;
if (orig != data)
WREG32_PCIE_PORT(PCIE_LC_CNTL, data);
}
}
}
}
static void si_fix_pci_max_read_req_size(struct amdgpu_device *adev)
{
int readrq;
u16 v;
readrq = pcie_get_readrq(adev->pdev);
v = ffs(readrq) - 8;
if ((v == 0) || (v == 6) || (v == 7))
pcie_set_readrq(adev->pdev, 512);
}
static int si_common_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
si_fix_pci_max_read_req_size(adev);
si_init_golden_registers(adev);
si_pcie_gen3_enable(adev);
si_program_aspm(adev);
return 0;
}
static int si_common_hw_fini(void *handle)
{
return 0;
}
static int si_common_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return si_common_hw_fini(adev);
}
static int si_common_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return si_common_hw_init(adev);
}
static bool si_common_is_idle(void *handle)
{
return true;
}
static int si_common_wait_for_idle(void *handle)
{
return 0;
}
static int si_common_soft_reset(void *handle)
{
return 0;
}
static int si_common_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int si_common_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
int si_set_ip_blocks(struct amdgpu_device *adev)
{
si_detect_hw_virtualization(adev);
switch (adev->asic_type) {
case CHIP_VERDE:
case CHIP_TAHITI:
case CHIP_PITCAIRN:
amdgpu_ip_block_add(adev, &si_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v6_0_ip_block);
amdgpu_ip_block_add(adev, &gfx_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_dma_ip_block);
break;
case CHIP_OLAND:
amdgpu_ip_block_add(adev, &si_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
else
amdgpu_ip_block_add(adev, &dce_v6_4_ip_block);
amdgpu_ip_block_add(adev, &gfx_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_dma_ip_block);
break;
case CHIP_HAINAN:
amdgpu_ip_block_add(adev, &si_common_ip_block);
amdgpu_ip_block_add(adev, &gmc_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_ih_ip_block);
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display)
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
amdgpu_ip_block_add(adev, &gfx_v6_0_ip_block);
amdgpu_ip_block_add(adev, &si_dma_ip_block);
break;
default:
BUG();
}
return 0;
}
