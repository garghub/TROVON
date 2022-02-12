static u32 soc15_pcie_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags, address, data;
u32 r;
struct nbio_pcie_index_data *nbio_pcie_id;
if (adev->asic_type == CHIP_VEGA10)
nbio_pcie_id = &nbio_v6_1_pcie_index_data;
else
BUG();
address = nbio_pcie_id->index_offset;
data = nbio_pcie_id->data_offset;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(address, reg);
(void)RREG32(address);
r = RREG32(data);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
return r;
}
static void soc15_pcie_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags, address, data;
struct nbio_pcie_index_data *nbio_pcie_id;
if (adev->asic_type == CHIP_VEGA10)
nbio_pcie_id = &nbio_v6_1_pcie_index_data;
else
BUG();
address = nbio_pcie_id->index_offset;
data = nbio_pcie_id->data_offset;
spin_lock_irqsave(&adev->pcie_idx_lock, flags);
WREG32(address, reg);
(void)RREG32(address);
WREG32(data, v);
(void)RREG32(data);
spin_unlock_irqrestore(&adev->pcie_idx_lock, flags);
}
static u32 soc15_uvd_ctx_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags, address, data;
u32 r;
address = SOC15_REG_OFFSET(UVD, 0, mmUVD_CTX_INDEX);
data = SOC15_REG_OFFSET(UVD, 0, mmUVD_CTX_DATA);
spin_lock_irqsave(&adev->uvd_ctx_idx_lock, flags);
WREG32(address, ((reg) & 0x1ff));
r = RREG32(data);
spin_unlock_irqrestore(&adev->uvd_ctx_idx_lock, flags);
return r;
}
static void soc15_uvd_ctx_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags, address, data;
address = SOC15_REG_OFFSET(UVD, 0, mmUVD_CTX_INDEX);
data = SOC15_REG_OFFSET(UVD, 0, mmUVD_CTX_DATA);
spin_lock_irqsave(&adev->uvd_ctx_idx_lock, flags);
WREG32(address, ((reg) & 0x1ff));
WREG32(data, (v));
spin_unlock_irqrestore(&adev->uvd_ctx_idx_lock, flags);
}
static u32 soc15_didt_rreg(struct amdgpu_device *adev, u32 reg)
{
unsigned long flags, address, data;
u32 r;
address = SOC15_REG_OFFSET(GC, 0, mmDIDT_IND_INDEX);
data = SOC15_REG_OFFSET(GC, 0, mmDIDT_IND_DATA);
spin_lock_irqsave(&adev->didt_idx_lock, flags);
WREG32(address, (reg));
r = RREG32(data);
spin_unlock_irqrestore(&adev->didt_idx_lock, flags);
return r;
}
static void soc15_didt_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
unsigned long flags, address, data;
address = SOC15_REG_OFFSET(GC, 0, mmDIDT_IND_INDEX);
data = SOC15_REG_OFFSET(GC, 0, mmDIDT_IND_DATA);
spin_lock_irqsave(&adev->didt_idx_lock, flags);
WREG32(address, (reg));
WREG32(data, (v));
spin_unlock_irqrestore(&adev->didt_idx_lock, flags);
}
static u32 soc15_get_config_memsize(struct amdgpu_device *adev)
{
return nbio_v6_1_get_memsize(adev);
}
static void soc15_init_golden_registers(struct amdgpu_device *adev)
{
mutex_lock(&adev->grbm_idx_mutex);
switch (adev->asic_type) {
case CHIP_VEGA10:
amdgpu_program_register_sequence(adev,
vega10_golden_init,
(const u32)ARRAY_SIZE(vega10_golden_init));
break;
default:
break;
}
mutex_unlock(&adev->grbm_idx_mutex);
}
static u32 soc15_get_xclk(struct amdgpu_device *adev)
{
if (adev->asic_type == CHIP_VEGA10)
return adev->clock.spll.reference_freq/4;
else
return adev->clock.spll.reference_freq;
}
void soc15_grbm_select(struct amdgpu_device *adev,
u32 me, u32 pipe, u32 queue, u32 vmid)
{
u32 grbm_gfx_cntl = 0;
grbm_gfx_cntl = REG_SET_FIELD(grbm_gfx_cntl, GRBM_GFX_CNTL, PIPEID, pipe);
grbm_gfx_cntl = REG_SET_FIELD(grbm_gfx_cntl, GRBM_GFX_CNTL, MEID, me);
grbm_gfx_cntl = REG_SET_FIELD(grbm_gfx_cntl, GRBM_GFX_CNTL, VMID, vmid);
grbm_gfx_cntl = REG_SET_FIELD(grbm_gfx_cntl, GRBM_GFX_CNTL, QUEUEID, queue);
WREG32(SOC15_REG_OFFSET(GC, 0, mmGRBM_GFX_CNTL), grbm_gfx_cntl);
}
static void soc15_vga_set_state(struct amdgpu_device *adev, bool state)
{
}
static bool soc15_read_disabled_bios(struct amdgpu_device *adev)
{
return false;
}
static bool soc15_read_bios_from_rom(struct amdgpu_device *adev,
u8 *bios, u32 length_bytes)
{
u32 *dw_ptr;
u32 i, length_dw;
if (bios == NULL)
return false;
if (length_bytes == 0)
return false;
if (adev->flags & AMD_IS_APU)
return false;
dw_ptr = (u32 *)bios;
length_dw = ALIGN(length_bytes, 4) / 4;
WREG32(SOC15_REG_OFFSET(SMUIO, 0, mmROM_INDEX), 0);
for (i = 0; i < length_dw; i++)
dw_ptr[i] = RREG32(SOC15_REG_OFFSET(SMUIO, 0, mmROM_DATA));
return true;
}
static uint32_t soc15_read_indexed_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset)
{
uint32_t val;
mutex_lock(&adev->grbm_idx_mutex);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
amdgpu_gfx_select_se_sh(adev, se_num, sh_num, 0xffffffff);
val = RREG32(reg_offset);
if (se_num != 0xffffffff || sh_num != 0xffffffff)
amdgpu_gfx_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
return val;
}
static uint32_t soc15_get_register_value(struct amdgpu_device *adev,
bool indexed, u32 se_num,
u32 sh_num, u32 reg_offset)
{
if (indexed) {
return soc15_read_indexed_register(adev, se_num, sh_num, reg_offset);
} else {
switch (reg_offset) {
case SOC15_REG_OFFSET(GC, 0, mmGB_ADDR_CONFIG):
return adev->gfx.config.gb_addr_config;
default:
return RREG32(reg_offset);
}
}
}
static int soc15_read_register(struct amdgpu_device *adev, u32 se_num,
u32 sh_num, u32 reg_offset, u32 *value)
{
struct amdgpu_allowed_register_entry *asic_register_table = NULL;
struct amdgpu_allowed_register_entry *asic_register_entry;
uint32_t size, i;
*value = 0;
switch (adev->asic_type) {
case CHIP_VEGA10:
asic_register_table = vega10_allowed_read_registers;
size = ARRAY_SIZE(vega10_allowed_read_registers);
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
*value = soc15_get_register_value(adev,
asic_register_entry->grbm_indexed,
se_num, sh_num, reg_offset);
return 0;
}
}
for (i = 0; i < ARRAY_SIZE(soc15_allowed_read_registers); i++) {
if (reg_offset != soc15_allowed_read_registers[i].reg_offset)
continue;
if (!soc15_allowed_read_registers[i].untouched)
*value = soc15_get_register_value(adev,
soc15_allowed_read_registers[i].grbm_indexed,
se_num, sh_num, reg_offset);
return 0;
}
return -EINVAL;
}
static void soc15_gpu_pci_config_reset(struct amdgpu_device *adev)
{
u32 i;
dev_info(adev->dev, "GPU pci config reset\n");
pci_clear_master(adev->pdev);
amdgpu_pci_config_reset(adev);
udelay(100);
for (i = 0; i < adev->usec_timeout; i++) {
if (nbio_v6_1_get_memsize(adev) != 0xffffffff)
break;
udelay(1);
}
}
static int soc15_asic_reset(struct amdgpu_device *adev)
{
amdgpu_atomfirmware_scratch_regs_engine_hung(adev, true);
soc15_gpu_pci_config_reset(adev);
amdgpu_atomfirmware_scratch_regs_engine_hung(adev, false);
return 0;
}
static int soc15_set_uvd_clocks(struct amdgpu_device *adev, u32 vclk, u32 dclk)
{
return 0;
}
static int soc15_set_vce_clocks(struct amdgpu_device *adev, u32 evclk, u32 ecclk)
{
return 0;
}
static void soc15_pcie_gen3_enable(struct amdgpu_device *adev)
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
static void soc15_program_aspm(struct amdgpu_device *adev)
{
if (amdgpu_aspm == 0)
return;
}
static void soc15_enable_doorbell_aperture(struct amdgpu_device *adev,
bool enable)
{
nbio_v6_1_enable_doorbell_aperture(adev, enable);
nbio_v6_1_enable_doorbell_selfring_aperture(adev, enable);
}
int soc15_set_ip_blocks(struct amdgpu_device *adev)
{
nbio_v6_1_detect_hw_virt(adev);
if (amdgpu_sriov_vf(adev))
adev->virt.ops = &xgpu_ai_virt_ops;
switch (adev->asic_type) {
case CHIP_VEGA10:
amdgpu_ip_block_add(adev, &vega10_common_ip_block);
amdgpu_ip_block_add(adev, &gfxhub_v1_0_ip_block);
amdgpu_ip_block_add(adev, &mmhub_v1_0_ip_block);
amdgpu_ip_block_add(adev, &gmc_v9_0_ip_block);
amdgpu_ip_block_add(adev, &vega10_ih_ip_block);
if (amdgpu_fw_load_type == 2 || amdgpu_fw_load_type == -1)
amdgpu_ip_block_add(adev, &psp_v3_1_ip_block);
if (!amdgpu_sriov_vf(adev))
amdgpu_ip_block_add(adev, &amdgpu_pp_ip_block);
if (adev->enable_virtual_display || amdgpu_sriov_vf(adev))
amdgpu_ip_block_add(adev, &dce_virtual_ip_block);
amdgpu_ip_block_add(adev, &gfx_v9_0_ip_block);
amdgpu_ip_block_add(adev, &sdma_v4_0_ip_block);
amdgpu_ip_block_add(adev, &uvd_v7_0_ip_block);
amdgpu_ip_block_add(adev, &vce_v4_0_ip_block);
break;
default:
return -EINVAL;
}
return 0;
}
static uint32_t soc15_get_rev_id(struct amdgpu_device *adev)
{
return nbio_v6_1_get_rev_id(adev);
}
int gmc_v9_0_mc_wait_for_idle(struct amdgpu_device *adev)
{
return 0;
}
static int soc15_common_early_init(void *handle)
{
bool psp_enabled = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->smc_rreg = NULL;
adev->smc_wreg = NULL;
adev->pcie_rreg = &soc15_pcie_rreg;
adev->pcie_wreg = &soc15_pcie_wreg;
adev->uvd_ctx_rreg = &soc15_uvd_ctx_rreg;
adev->uvd_ctx_wreg = &soc15_uvd_ctx_wreg;
adev->didt_rreg = &soc15_didt_rreg;
adev->didt_wreg = &soc15_didt_wreg;
adev->asic_funcs = &soc15_asic_funcs;
if (amdgpu_get_ip_block(adev, AMD_IP_BLOCK_TYPE_PSP) &&
(amdgpu_ip_block_mask & (1 << AMD_IP_BLOCK_TYPE_PSP)))
psp_enabled = true;
if (amdgpu_sriov_vf(adev)) {
amdgpu_virt_init_setting(adev);
xgpu_ai_mailbox_set_irq_funcs(adev);
}
switch(adev->asic_type) {
case CHIP_VEGA10:
nbio_v6_1_init(adev);
break;
default:
return -EINVAL;
}
adev->rev_id = soc15_get_rev_id(adev);
adev->external_rev_id = 0xFF;
switch (adev->asic_type) {
case CHIP_VEGA10:
adev->cg_flags = AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_MGLS |
AMD_CG_SUPPORT_GFX_RLC_LS |
AMD_CG_SUPPORT_GFX_CP_LS |
AMD_CG_SUPPORT_GFX_3D_CGCG |
AMD_CG_SUPPORT_GFX_3D_CGLS |
AMD_CG_SUPPORT_GFX_CGCG |
AMD_CG_SUPPORT_GFX_CGLS |
AMD_CG_SUPPORT_BIF_MGCG |
AMD_CG_SUPPORT_BIF_LS |
AMD_CG_SUPPORT_HDP_LS |
AMD_CG_SUPPORT_DRM_MGCG |
AMD_CG_SUPPORT_DRM_LS |
AMD_CG_SUPPORT_ROM_MGCG |
AMD_CG_SUPPORT_DF_MGCG |
AMD_CG_SUPPORT_SDMA_MGCG |
AMD_CG_SUPPORT_SDMA_LS |
AMD_CG_SUPPORT_MC_MGCG |
AMD_CG_SUPPORT_MC_LS;
adev->pg_flags = 0;
adev->external_rev_id = 0x1;
break;
default:
return -EINVAL;
}
adev->firmware.load_type = amdgpu_ucode_get_load_type(adev, amdgpu_fw_load_type);
amdgpu_get_pcie_info(adev);
return 0;
}
static int soc15_common_late_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
xgpu_ai_mailbox_get_irq(adev);
return 0;
}
static int soc15_common_sw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
xgpu_ai_mailbox_add_irq_id(adev);
return 0;
}
static int soc15_common_sw_fini(void *handle)
{
return 0;
}
static int soc15_common_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
soc15_init_golden_registers(adev);
soc15_pcie_gen3_enable(adev);
soc15_program_aspm(adev);
soc15_enable_doorbell_aperture(adev, true);
return 0;
}
static int soc15_common_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
soc15_enable_doorbell_aperture(adev, false);
if (amdgpu_sriov_vf(adev))
xgpu_ai_mailbox_put_irq(adev);
return 0;
}
static int soc15_common_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return soc15_common_hw_fini(adev);
}
static int soc15_common_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return soc15_common_hw_init(adev);
}
static bool soc15_common_is_idle(void *handle)
{
return true;
}
static int soc15_common_wait_for_idle(void *handle)
{
return 0;
}
static int soc15_common_soft_reset(void *handle)
{
return 0;
}
static void soc15_update_hdp_light_sleep(struct amdgpu_device *adev, bool enable)
{
uint32_t def, data;
def = data = RREG32(SOC15_REG_OFFSET(HDP, 0, mmHDP_MEM_POWER_LS));
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_HDP_LS))
data |= HDP_MEM_POWER_LS__LS_ENABLE_MASK;
else
data &= ~HDP_MEM_POWER_LS__LS_ENABLE_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(HDP, 0, mmHDP_MEM_POWER_LS), data);
}
static void soc15_update_drm_clock_gating(struct amdgpu_device *adev, bool enable)
{
uint32_t def, data;
def = data = RREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_CGTT_CTRL0));
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_DRM_MGCG))
data &= ~(0x01000000 |
0x02000000 |
0x04000000 |
0x08000000 |
0x10000000 |
0x20000000 |
0x40000000 |
0x80000000);
else
data |= (0x01000000 |
0x02000000 |
0x04000000 |
0x08000000 |
0x10000000 |
0x20000000 |
0x40000000 |
0x80000000);
if (def != data)
WREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_CGTT_CTRL0), data);
}
static void soc15_update_drm_light_sleep(struct amdgpu_device *adev, bool enable)
{
uint32_t def, data;
def = data = RREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_LIGHT_SLEEP_CTRL));
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_DRM_LS))
data |= 1;
else
data &= ~1;
if (def != data)
WREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_LIGHT_SLEEP_CTRL), data);
}
static void soc15_update_rom_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t def, data;
def = data = RREG32(SOC15_REG_OFFSET(SMUIO, 0, mmCGTT_ROM_CLK_CTRL0));
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_ROM_MGCG))
data &= ~(CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK |
CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE1_MASK);
else
data |= CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK |
CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE1_MASK;
if (def != data)
WREG32(SOC15_REG_OFFSET(SMUIO, 0, mmCGTT_ROM_CLK_CTRL0), data);
}
static void soc15_update_df_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t data;
data = RREG32(SOC15_REG_OFFSET(DF, 0, mmFabricConfigAccessControl));
data &= ~FabricConfigAccessControl__CfgRegInstAccEn_MASK;
WREG32(SOC15_REG_OFFSET(DF, 0, mmFabricConfigAccessControl), data);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_DF_MGCG)) {
data = RREG32(SOC15_REG_OFFSET(DF, 0, mmDF_PIE_AON0_DfGlobalClkGater));
data &= ~DF_PIE_AON0_DfGlobalClkGater__MGCGMode_MASK;
data |= DF_MGCG_ENABLE_15_CYCLE_DELAY;
WREG32(SOC15_REG_OFFSET(DF, 0, mmDF_PIE_AON0_DfGlobalClkGater), data);
} else {
data = RREG32(SOC15_REG_OFFSET(DF, 0, mmDF_PIE_AON0_DfGlobalClkGater));
data &= ~DF_PIE_AON0_DfGlobalClkGater__MGCGMode_MASK;
data |= DF_MGCG_DISABLE;
WREG32(SOC15_REG_OFFSET(DF, 0, mmDF_PIE_AON0_DfGlobalClkGater), data);
}
WREG32(SOC15_REG_OFFSET(DF, 0, mmFabricConfigAccessControl),
mmFabricConfigAccessControl_DEFAULT);
}
static int soc15_common_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
return 0;
switch (adev->asic_type) {
case CHIP_VEGA10:
nbio_v6_1_update_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
nbio_v6_1_update_medium_grain_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
soc15_update_hdp_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
soc15_update_drm_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
soc15_update_drm_light_sleep(adev,
state == AMD_CG_STATE_GATE ? true : false);
soc15_update_rom_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
soc15_update_df_medium_grain_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
default:
break;
}
return 0;
}
static void soc15_common_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int data;
if (amdgpu_sriov_vf(adev))
*flags = 0;
nbio_v6_1_get_clockgating_state(adev, flags);
data = RREG32(SOC15_REG_OFFSET(HDP, 0, mmHDP_MEM_POWER_LS));
if (data & HDP_MEM_POWER_LS__LS_ENABLE_MASK)
*flags |= AMD_CG_SUPPORT_HDP_LS;
data = RREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_CGTT_CTRL0));
if (!(data & 0x01000000))
*flags |= AMD_CG_SUPPORT_DRM_MGCG;
data = RREG32(SOC15_REG_OFFSET(MP0, 0, mmMP0_MISC_LIGHT_SLEEP_CTRL));
if (data & 0x1)
*flags |= AMD_CG_SUPPORT_DRM_LS;
data = RREG32(SOC15_REG_OFFSET(SMUIO, 0, mmCGTT_ROM_CLK_CTRL0));
if (!(data & CGTT_ROM_CLK_CTRL0__SOFT_OVERRIDE0_MASK))
*flags |= AMD_CG_SUPPORT_ROM_MGCG;
data = RREG32(SOC15_REG_OFFSET(DF, 0, mmDF_PIE_AON0_DfGlobalClkGater));
if (data & DF_MGCG_ENABLE_15_CYCLE_DELAY)
*flags |= AMD_CG_SUPPORT_DF_MGCG;
}
static int soc15_common_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
