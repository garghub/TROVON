u64 gfxhub_v1_0_get_mc_fb_offset(struct amdgpu_device *adev)
{
return (u64)RREG32_SOC15(GC, 0, mmMC_VM_FB_OFFSET) << 24;
}
static void gfxhub_v1_0_init_gart_pt_regs(struct amdgpu_device *adev)
{
uint64_t value;
BUG_ON(adev->gart.table_addr & (~0x0000FFFFFFFFF000ULL));
value = adev->gart.table_addr - adev->mc.vram_start
+ adev->vm_manager.vram_base_offset;
value &= 0x0000FFFFFFFFF000ULL;
value |= 0x1;
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LO32,
lower_32_bits(value));
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_HI32,
upper_32_bits(value));
}
static void gfxhub_v1_0_init_gart_aperture_regs(struct amdgpu_device *adev)
{
gfxhub_v1_0_init_gart_pt_regs(adev);
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_START_ADDR_LO32,
(u32)(adev->mc.gart_start >> 12));
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_START_ADDR_HI32,
(u32)(adev->mc.gart_start >> 44));
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_END_ADDR_LO32,
(u32)(adev->mc.gart_end >> 12));
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_PAGE_TABLE_END_ADDR_HI32,
(u32)(adev->mc.gart_end >> 44));
}
static void gfxhub_v1_0_init_system_aperture_regs(struct amdgpu_device *adev)
{
uint64_t value;
WREG32_SOC15(GC, 0, mmMC_VM_AGP_BASE, 0);
WREG32_SOC15(GC, 0, mmMC_VM_AGP_TOP, 0);
WREG32_SOC15(GC, 0, mmMC_VM_AGP_BOT, 0xFFFFFFFF);
WREG32_SOC15(GC, 0, mmMC_VM_SYSTEM_APERTURE_LOW_ADDR,
adev->mc.vram_start >> 18);
WREG32_SOC15(GC, 0, mmMC_VM_SYSTEM_APERTURE_HIGH_ADDR,
adev->mc.vram_end >> 18);
value = adev->vram_scratch.gpu_addr - adev->mc.vram_start
+ adev->vm_manager.vram_base_offset;
WREG32_SOC15(GC, 0, mmMC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB,
(u32)(value >> 12));
WREG32_SOC15(GC, 0, mmMC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB,
(u32)(value >> 44));
WREG32_SOC15(GC, 0, mmVM_L2_PROTECTION_FAULT_DEFAULT_ADDR_LO32,
(u32)(adev->dummy_page.addr >> 12));
WREG32_SOC15(GC, 0, mmVM_L2_PROTECTION_FAULT_DEFAULT_ADDR_HI32,
(u32)((u64)adev->dummy_page.addr >> 44));
WREG32_FIELD15(GC, 0, VM_L2_PROTECTION_FAULT_CNTL2,
ACTIVE_PAGE_MIGRATION_PTE_READ_RETRY, 1);
}
static void gfxhub_v1_0_init_tlb_regs(struct amdgpu_device *adev)
{
uint32_t tmp;
tmp = RREG32_SOC15(GC, 0, mmMC_VM_MX_L1_TLB_CNTL);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL, ENABLE_L1_TLB, 1);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL, SYSTEM_ACCESS_MODE, 3);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL,
ENABLE_ADVANCED_DRIVER_MODEL, 1);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL,
SYSTEM_APERTURE_UNMAPPED_ACCESS, 0);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL, ECO_BITS, 0);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL,
MTYPE, MTYPE_UC);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL, ATC_EN, 1);
WREG32_SOC15(GC, 0, mmMC_VM_MX_L1_TLB_CNTL, tmp);
}
static void gfxhub_v1_0_init_cache_regs(struct amdgpu_device *adev)
{
uint32_t tmp;
tmp = RREG32_SOC15(GC, 0, mmVM_L2_CNTL);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, ENABLE_L2_CACHE, 1);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, ENABLE_L2_FRAGMENT_PROCESSING, 1);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, L2_PDE0_CACHE_TAG_GENERATION_MODE,
0);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, PDE_FAULT_CLASSIFICATION, 1);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, CONTEXT1_IDENTITY_ACCESS_MODE, 1);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL, IDENTITY_MODE_FRAGMENT_SIZE, 0);
WREG32_SOC15(GC, 0, mmVM_L2_CNTL, tmp);
tmp = RREG32_SOC15(GC, 0, mmVM_L2_CNTL2);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL2, INVALIDATE_ALL_L1_TLBS, 1);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL2, INVALIDATE_L2_CACHE, 1);
WREG32_SOC15(GC, 0, mmVM_L2_CNTL2, tmp);
tmp = mmVM_L2_CNTL3_DEFAULT;
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL3, BANK_SELECT, 9);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL3, L2_CACHE_BIGK_FRAGMENT_SIZE, 6);
WREG32_SOC15(GC, 0, mmVM_L2_CNTL3, tmp);
tmp = mmVM_L2_CNTL4_DEFAULT;
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL4, VMC_TAP_PDE_REQUEST_PHYSICAL, 0);
tmp = REG_SET_FIELD(tmp, VM_L2_CNTL4, VMC_TAP_PTE_REQUEST_PHYSICAL, 0);
WREG32_SOC15(GC, 0, mmVM_L2_CNTL4, tmp);
}
static void gfxhub_v1_0_enable_system_domain(struct amdgpu_device *adev)
{
uint32_t tmp;
tmp = RREG32_SOC15(GC, 0, mmVM_CONTEXT0_CNTL);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT0_CNTL, ENABLE_CONTEXT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT0_CNTL, PAGE_TABLE_DEPTH, 0);
WREG32_SOC15(GC, 0, mmVM_CONTEXT0_CNTL, tmp);
}
static void gfxhub_v1_0_disable_identity_aperture(struct amdgpu_device *adev)
{
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT1_IDENTITY_APERTURE_LOW_ADDR_LO32,
0XFFFFFFFF);
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT1_IDENTITY_APERTURE_LOW_ADDR_HI32,
0x0000000F);
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT1_IDENTITY_APERTURE_HIGH_ADDR_LO32,
0);
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT1_IDENTITY_APERTURE_HIGH_ADDR_HI32,
0);
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT_IDENTITY_PHYSICAL_OFFSET_LO32, 0);
WREG32_SOC15(GC, 0, mmVM_L2_CONTEXT_IDENTITY_PHYSICAL_OFFSET_HI32, 0);
}
static void gfxhub_v1_0_setup_vmid_config(struct amdgpu_device *adev)
{
int i;
uint32_t tmp;
for (i = 0; i <= 14; i++) {
tmp = RREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_CNTL, i);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL, ENABLE_CONTEXT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL, PAGE_TABLE_DEPTH,
adev->vm_manager.num_level);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
PDE0_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
VALID_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
READ_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
WRITE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
EXECUTE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
PAGE_TABLE_BLOCK_SIZE,
adev->vm_manager.block_size - 9);
tmp = REG_SET_FIELD(tmp, VM_CONTEXT1_CNTL,
RETRY_PERMISSION_OR_INVALID_PAGE_FAULT, 0);
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_CNTL, i, tmp);
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_PAGE_TABLE_START_ADDR_LO32, i*2, 0);
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_PAGE_TABLE_START_ADDR_HI32, i*2, 0);
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_PAGE_TABLE_END_ADDR_LO32, i*2,
lower_32_bits(adev->vm_manager.max_pfn - 1));
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT1_PAGE_TABLE_END_ADDR_HI32, i*2,
upper_32_bits(adev->vm_manager.max_pfn - 1));
}
}
static void gfxhub_v1_0_program_invalidation(struct amdgpu_device *adev)
{
unsigned i;
for (i = 0 ; i < 18; ++i) {
WREG32_SOC15_OFFSET(GC, 0, mmVM_INVALIDATE_ENG0_ADDR_RANGE_LO32,
2 * i, 0xffffffff);
WREG32_SOC15_OFFSET(GC, 0, mmVM_INVALIDATE_ENG0_ADDR_RANGE_HI32,
2 * i, 0x1f);
}
}
int gfxhub_v1_0_gart_enable(struct amdgpu_device *adev)
{
if (amdgpu_sriov_vf(adev)) {
WREG32_SOC15(GC, 0, mmMC_VM_FB_LOCATION_BASE,
adev->mc.vram_start >> 24);
WREG32_SOC15(GC, 0, mmMC_VM_FB_LOCATION_TOP,
adev->mc.vram_end >> 24);
}
gfxhub_v1_0_init_gart_aperture_regs(adev);
gfxhub_v1_0_init_system_aperture_regs(adev);
gfxhub_v1_0_init_tlb_regs(adev);
gfxhub_v1_0_init_cache_regs(adev);
gfxhub_v1_0_enable_system_domain(adev);
gfxhub_v1_0_disable_identity_aperture(adev);
gfxhub_v1_0_setup_vmid_config(adev);
gfxhub_v1_0_program_invalidation(adev);
return 0;
}
void gfxhub_v1_0_gart_disable(struct amdgpu_device *adev)
{
u32 tmp;
u32 i;
for (i = 0; i < 16; i++)
WREG32_SOC15_OFFSET(GC, 0, mmVM_CONTEXT0_CNTL, i, 0);
tmp = RREG32_SOC15(GC, 0, mmMC_VM_MX_L1_TLB_CNTL);
tmp = REG_SET_FIELD(tmp, MC_VM_MX_L1_TLB_CNTL, ENABLE_L1_TLB, 0);
tmp = REG_SET_FIELD(tmp,
MC_VM_MX_L1_TLB_CNTL,
ENABLE_ADVANCED_DRIVER_MODEL,
0);
WREG32_SOC15(GC, 0, mmMC_VM_MX_L1_TLB_CNTL, tmp);
WREG32_FIELD15(GC, 0, VM_L2_CNTL, ENABLE_L2_CACHE, 0);
WREG32_SOC15(GC, 0, mmVM_L2_CNTL3, 0);
}
void gfxhub_v1_0_set_fault_enable_default(struct amdgpu_device *adev,
bool value)
{
u32 tmp;
tmp = RREG32_SOC15(GC, 0, mmVM_L2_PROTECTION_FAULT_CNTL);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
PDE0_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
PDE1_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
PDE2_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp,
VM_L2_PROTECTION_FAULT_CNTL,
TRANSLATE_FURTHER_PROTECTION_FAULT_ENABLE_DEFAULT,
value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
NACK_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
VALID_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
READ_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
WRITE_PROTECTION_FAULT_ENABLE_DEFAULT, value);
tmp = REG_SET_FIELD(tmp, VM_L2_PROTECTION_FAULT_CNTL,
EXECUTE_PROTECTION_FAULT_ENABLE_DEFAULT, value);
WREG32_SOC15(GC, 0, mmVM_L2_PROTECTION_FAULT_CNTL, tmp);
}
void gfxhub_v1_0_init(struct amdgpu_device *adev)
{
struct amdgpu_vmhub *hub = &adev->vmhub[AMDGPU_GFXHUB];
hub->ctx0_ptb_addr_lo32 =
SOC15_REG_OFFSET(GC, 0,
mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LO32);
hub->ctx0_ptb_addr_hi32 =
SOC15_REG_OFFSET(GC, 0,
mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_HI32);
hub->vm_inv_eng0_req =
SOC15_REG_OFFSET(GC, 0, mmVM_INVALIDATE_ENG0_REQ);
hub->vm_inv_eng0_ack =
SOC15_REG_OFFSET(GC, 0, mmVM_INVALIDATE_ENG0_ACK);
hub->vm_context0_cntl =
SOC15_REG_OFFSET(GC, 0, mmVM_CONTEXT0_CNTL);
hub->vm_l2_pro_fault_status =
SOC15_REG_OFFSET(GC, 0, mmVM_L2_PROTECTION_FAULT_STATUS);
hub->vm_l2_pro_fault_cntl =
SOC15_REG_OFFSET(GC, 0, mmVM_L2_PROTECTION_FAULT_CNTL);
}
