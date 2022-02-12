static int gmc_v9_0_vm_fault_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
struct amdgpu_vmhub *hub;
u32 tmp, reg, bits, i;
bits = VM_CONTEXT1_CNTL__RANGE_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__DUMMY_PAGE_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__PDE0_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__VALID_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__READ_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__WRITE_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK |
VM_CONTEXT1_CNTL__EXECUTE_PROTECTION_FAULT_ENABLE_INTERRUPT_MASK;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
hub = &adev->vmhub[AMDGPU_MMHUB];
for (i = 0; i< 16; i++) {
reg = hub->vm_context0_cntl + i;
tmp = RREG32(reg);
tmp &= ~bits;
WREG32(reg, tmp);
}
hub = &adev->vmhub[AMDGPU_GFXHUB];
for (i = 0; i < 16; i++) {
reg = hub->vm_context0_cntl + i;
tmp = RREG32(reg);
tmp &= ~bits;
WREG32(reg, tmp);
}
break;
case AMDGPU_IRQ_STATE_ENABLE:
hub = &adev->vmhub[AMDGPU_MMHUB];
for (i = 0; i< 16; i++) {
reg = hub->vm_context0_cntl + i;
tmp = RREG32(reg);
tmp |= bits;
WREG32(reg, tmp);
}
hub = &adev->vmhub[AMDGPU_GFXHUB];
for (i = 0; i < 16; i++) {
reg = hub->vm_context0_cntl + i;
tmp = RREG32(reg);
tmp |= bits;
WREG32(reg, tmp);
}
break;
default:
break;
}
return 0;
}
static int gmc_v9_0_process_interrupt(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
struct amdgpu_vmhub *hub = &adev->vmhub[entry->vm_id_src];
uint32_t status = 0;
u64 addr;
addr = (u64)entry->src_data[0] << 12;
addr |= ((u64)entry->src_data[1] & 0xf) << 44;
if (!amdgpu_sriov_vf(adev)) {
status = RREG32(hub->vm_l2_pro_fault_status);
WREG32_P(hub->vm_l2_pro_fault_cntl, 1, ~1);
}
if (printk_ratelimit()) {
dev_err(adev->dev,
"[%s] VMC page fault (src_id:%u ring:%u vm_id:%u pas_id:%u)\n",
entry->vm_id_src ? "mmhub" : "gfxhub",
entry->src_id, entry->ring_id, entry->vm_id,
entry->pas_id);
dev_err(adev->dev, " at page 0x%016llx from %d\n",
addr, entry->client_id);
if (!amdgpu_sriov_vf(adev))
dev_err(adev->dev,
"VM_L2_PROTECTION_FAULT_STATUS:0x%08X\n",
status);
}
return 0;
}
static void gmc_v9_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->mc.vm_fault.num_types = 1;
adev->mc.vm_fault.funcs = &gmc_v9_0_irq_funcs;
}
static uint32_t gmc_v9_0_get_invalidate_req(unsigned int vm_id)
{
u32 req = 0;
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ,
PER_VMID_INVALIDATE_REQ, 1 << vm_id);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, FLUSH_TYPE, 0);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, INVALIDATE_L2_PTES, 1);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, INVALIDATE_L2_PDE0, 1);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, INVALIDATE_L2_PDE1, 1);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, INVALIDATE_L2_PDE2, 1);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ, INVALIDATE_L1_PTES, 1);
req = REG_SET_FIELD(req, VM_INVALIDATE_ENG0_REQ,
CLEAR_PROTECTION_FAULT_STATUS_ADDR, 0);
return req;
}
static void gmc_v9_0_gart_flush_gpu_tlb(struct amdgpu_device *adev,
uint32_t vmid)
{
const unsigned eng = 17;
unsigned i, j;
if (adev->flags & AMD_IS_APU)
nbio_v7_0_hdp_flush(adev);
else
nbio_v6_1_hdp_flush(adev);
spin_lock(&adev->mc.invalidate_lock);
for (i = 0; i < AMDGPU_MAX_VMHUBS; ++i) {
struct amdgpu_vmhub *hub = &adev->vmhub[i];
u32 tmp = gmc_v9_0_get_invalidate_req(vmid);
WREG32_NO_KIQ(hub->vm_inv_eng0_req + eng, tmp);
for (j = 0; j < 100; j++) {
tmp = RREG32_NO_KIQ(hub->vm_inv_eng0_ack + eng);
tmp &= 1 << vmid;
if (tmp)
break;
cpu_relax();
}
if (j < 100)
continue;
for (j = 0; j < adev->usec_timeout; j++) {
tmp = RREG32_NO_KIQ(hub->vm_inv_eng0_ack + eng);
tmp &= 1 << vmid;
if (tmp)
break;
udelay(1);
}
if (j < adev->usec_timeout)
continue;
DRM_ERROR("Timeout waiting for VM flush ACK!\n");
}
spin_unlock(&adev->mc.invalidate_lock);
}
static int gmc_v9_0_gart_set_pte_pde(struct amdgpu_device *adev,
void *cpu_pt_addr,
uint32_t gpu_page_idx,
uint64_t addr,
uint64_t flags)
{
void __iomem *ptr = (void *)cpu_pt_addr;
uint64_t value;
value = addr & 0x0000FFFFFFFFF000ULL;
value |= flags;
writeq(value, ptr + (gpu_page_idx * 8));
return 0;
}
static uint64_t gmc_v9_0_get_vm_pte_flags(struct amdgpu_device *adev,
uint32_t flags)
{
uint64_t pte_flag = 0;
if (flags & AMDGPU_VM_PAGE_EXECUTABLE)
pte_flag |= AMDGPU_PTE_EXECUTABLE;
if (flags & AMDGPU_VM_PAGE_READABLE)
pte_flag |= AMDGPU_PTE_READABLE;
if (flags & AMDGPU_VM_PAGE_WRITEABLE)
pte_flag |= AMDGPU_PTE_WRITEABLE;
switch (flags & AMDGPU_VM_MTYPE_MASK) {
case AMDGPU_VM_MTYPE_DEFAULT:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_NC);
break;
case AMDGPU_VM_MTYPE_NC:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_NC);
break;
case AMDGPU_VM_MTYPE_WC:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_WC);
break;
case AMDGPU_VM_MTYPE_CC:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_CC);
break;
case AMDGPU_VM_MTYPE_UC:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_UC);
break;
default:
pte_flag |= AMDGPU_PTE_MTYPE(MTYPE_NC);
break;
}
if (flags & AMDGPU_VM_PAGE_PRT)
pte_flag |= AMDGPU_PTE_PRT;
return pte_flag;
}
static u64 gmc_v9_0_get_vm_pde(struct amdgpu_device *adev, u64 addr)
{
addr = adev->vm_manager.vram_base_offset + addr - adev->mc.vram_start;
BUG_ON(addr & 0xFFFF00000000003FULL);
return addr;
}
static void gmc_v9_0_set_gart_funcs(struct amdgpu_device *adev)
{
if (adev->gart.gart_funcs == NULL)
adev->gart.gart_funcs = &gmc_v9_0_gart_funcs;
}
static int gmc_v9_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gmc_v9_0_set_gart_funcs(adev);
gmc_v9_0_set_irq_funcs(adev);
return 0;
}
static int gmc_v9_0_late_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
unsigned vm_inv_eng[AMDGPU_MAX_VMHUBS] = { 3, 3 };
unsigned i;
for(i = 0; i < adev->num_rings; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
unsigned vmhub = ring->funcs->vmhub;
ring->vm_inv_eng = vm_inv_eng[vmhub]++;
dev_info(adev->dev, "ring %u(%s) uses VM inv eng %u on hub %u\n",
ring->idx, ring->name, ring->vm_inv_eng,
ring->funcs->vmhub);
}
for(i = 0; i < AMDGPU_MAX_VMHUBS; ++i)
BUG_ON(vm_inv_eng[i] > 17);
return amdgpu_irq_get(adev, &adev->mc.vm_fault, 0);
}
static void gmc_v9_0_vram_gtt_location(struct amdgpu_device *adev,
struct amdgpu_mc *mc)
{
u64 base = 0;
if (!amdgpu_sriov_vf(adev))
base = mmhub_v1_0_get_fb_location(adev);
amdgpu_vram_location(adev, &adev->mc, base);
amdgpu_gart_location(adev, mc);
if (adev->flags & AMD_IS_APU)
adev->vm_manager.vram_base_offset = gfxhub_v1_0_get_mc_fb_offset(adev);
else
adev->vm_manager.vram_base_offset = 0;
}
static int gmc_v9_0_mc_init(struct amdgpu_device *adev)
{
u32 tmp;
int chansize, numchan;
adev->mc.vram_width = amdgpu_atomfirmware_get_vram_width(adev);
if (!adev->mc.vram_width) {
chansize = 128;
tmp = RREG32_SOC15(DF, 0, mmDF_CS_AON0_DramBaseAddress0);
tmp &= DF_CS_AON0_DramBaseAddress0__IntLvNumChan_MASK;
tmp >>= DF_CS_AON0_DramBaseAddress0__IntLvNumChan__SHIFT;
switch (tmp) {
case 0:
default:
numchan = 1;
break;
case 1:
numchan = 2;
break;
case 2:
numchan = 0;
break;
case 3:
numchan = 4;
break;
case 4:
numchan = 0;
break;
case 5:
numchan = 8;
break;
case 6:
numchan = 0;
break;
case 7:
numchan = 16;
break;
case 8:
numchan = 2;
break;
}
adev->mc.vram_width = numchan * chansize;
}
adev->mc.aper_base = pci_resource_start(adev->pdev, 0);
adev->mc.aper_size = pci_resource_len(adev->pdev, 0);
adev->mc.mc_vram_size =
((adev->flags & AMD_IS_APU) ? nbio_v7_0_get_memsize(adev) :
nbio_v6_1_get_memsize(adev)) * 1024ULL * 1024ULL;
adev->mc.real_vram_size = adev->mc.mc_vram_size;
adev->mc.visible_vram_size = adev->mc.aper_size;
if (adev->mc.visible_vram_size > adev->mc.real_vram_size)
adev->mc.visible_vram_size = adev->mc.real_vram_size;
if (amdgpu_gart_size == -1) {
switch (adev->asic_type) {
case CHIP_VEGA10:
default:
adev->mc.gart_size = 256ULL << 20;
break;
case CHIP_RAVEN:
adev->mc.gart_size = 1024ULL << 20;
break;
}
} else {
adev->mc.gart_size = (u64)amdgpu_gart_size << 20;
}
gmc_v9_0_vram_gtt_location(adev, &adev->mc);
return 0;
}
static int gmc_v9_0_gart_init(struct amdgpu_device *adev)
{
int r;
if (adev->gart.robj) {
WARN(1, "VEGA10 PCIE GART already initialized\n");
return 0;
}
r = amdgpu_gart_init(adev);
if (r)
return r;
adev->gart.table_size = adev->gart.num_gpu_pages * 8;
adev->gart.gart_pte_flags = AMDGPU_PTE_MTYPE(MTYPE_UC) |
AMDGPU_PTE_EXECUTABLE;
return amdgpu_gart_table_vram_alloc(adev);
}
static int gmc_v9_0_sw_init(void *handle)
{
int r;
int dma_bits;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gfxhub_v1_0_init(adev);
mmhub_v1_0_init(adev);
spin_lock_init(&adev->mc.invalidate_lock);
switch (adev->asic_type) {
case CHIP_RAVEN:
adev->mc.vram_type = AMDGPU_VRAM_TYPE_UNKNOWN;
if (adev->rev_id == 0x0 || adev->rev_id == 0x1) {
adev->vm_manager.vm_size = 1U << 18;
adev->vm_manager.block_size = 9;
adev->vm_manager.num_level = 3;
amdgpu_vm_set_fragment_size(adev, 9);
} else {
amdgpu_vm_adjust_size(adev, 64, 9);
adev->vm_manager.num_level = 1;
}
break;
case CHIP_VEGA10:
adev->mc.vram_type = AMDGPU_VRAM_TYPE_HBM;
adev->vm_manager.vm_size = 1U << 18;
adev->vm_manager.block_size = 9;
adev->vm_manager.num_level = 3;
amdgpu_vm_set_fragment_size(adev, 9);
break;
default:
break;
}
DRM_INFO("vm size is %llu GB, block size is %u-bit,fragment size is %u-bit\n",
adev->vm_manager.vm_size,
adev->vm_manager.block_size,
adev->vm_manager.fragment_size);
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_VMC, 0,
&adev->mc.vm_fault);
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_UTCL2, 0,
&adev->mc.vm_fault);
if (r)
return r;
adev->vm_manager.max_pfn = adev->vm_manager.vm_size << 18;
adev->mc.mc_mask = 0xffffffffffffULL;
adev->mc.stolen_size = 8 * 1024 * 1024;
adev->need_dma32 = false;
dma_bits = adev->need_dma32 ? 32 : 44;
r = pci_set_dma_mask(adev->pdev, DMA_BIT_MASK(dma_bits));
if (r) {
adev->need_dma32 = true;
dma_bits = 32;
printk(KERN_WARNING "amdgpu: No suitable DMA available.\n");
}
r = pci_set_consistent_dma_mask(adev->pdev, DMA_BIT_MASK(dma_bits));
if (r) {
pci_set_consistent_dma_mask(adev->pdev, DMA_BIT_MASK(32));
printk(KERN_WARNING "amdgpu: No coherent DMA available.\n");
}
r = gmc_v9_0_mc_init(adev);
if (r)
return r;
r = amdgpu_bo_init(adev);
if (r)
return r;
r = gmc_v9_0_gart_init(adev);
if (r)
return r;
adev->vm_manager.id_mgr[AMDGPU_GFXHUB].num_ids = AMDGPU_NUM_OF_VMIDS;
adev->vm_manager.id_mgr[AMDGPU_MMHUB].num_ids = AMDGPU_NUM_OF_VMIDS;
amdgpu_vm_manager_init(adev);
return 0;
}
static void gmc_v9_0_gart_fini(struct amdgpu_device *adev)
{
amdgpu_gart_table_vram_free(adev);
amdgpu_gart_fini(adev);
}
static int gmc_v9_0_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_vm_manager_fini(adev);
gmc_v9_0_gart_fini(adev);
amdgpu_gem_force_release(adev);
amdgpu_bo_fini(adev);
return 0;
}
static void gmc_v9_0_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_VEGA10:
break;
case CHIP_RAVEN:
break;
default:
break;
}
}
static int gmc_v9_0_gart_enable(struct amdgpu_device *adev)
{
int r;
bool value;
u32 tmp;
amdgpu_program_register_sequence(adev,
golden_settings_vega10_hdp,
(const u32)ARRAY_SIZE(golden_settings_vega10_hdp));
if (adev->gart.robj == NULL) {
dev_err(adev->dev, "No VRAM object for PCIE GART.\n");
return -EINVAL;
}
r = amdgpu_gart_table_vram_pin(adev);
if (r)
return r;
if (adev->flags & AMD_IS_APU)
nbio_v7_0_hdp_flush(adev);
else
nbio_v6_1_hdp_flush(adev);
switch (adev->asic_type) {
case CHIP_RAVEN:
mmhub_v1_0_initialize_power_gating(adev);
mmhub_v1_0_update_power_gating(adev, true);
break;
default:
break;
}
r = gfxhub_v1_0_gart_enable(adev);
if (r)
return r;
r = mmhub_v1_0_gart_enable(adev);
if (r)
return r;
tmp = RREG32_SOC15(HDP, 0, mmHDP_MISC_CNTL);
tmp |= HDP_MISC_CNTL__FLUSH_INVALIDATE_CACHE_MASK;
WREG32_SOC15(HDP, 0, mmHDP_MISC_CNTL, tmp);
tmp = RREG32_SOC15(HDP, 0, mmHDP_HOST_PATH_CNTL);
WREG32_SOC15(HDP, 0, mmHDP_HOST_PATH_CNTL, tmp);
if (amdgpu_vm_fault_stop == AMDGPU_VM_FAULT_STOP_ALWAYS)
value = false;
else
value = true;
gfxhub_v1_0_set_fault_enable_default(adev, value);
mmhub_v1_0_set_fault_enable_default(adev, value);
gmc_v9_0_gart_flush_gpu_tlb(adev, 0);
DRM_INFO("PCIE GART of %uM enabled (table at 0x%016llX).\n",
(unsigned)(adev->mc.gart_size >> 20),
(unsigned long long)adev->gart.table_addr);
adev->gart.ready = true;
return 0;
}
static int gmc_v9_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gmc_v9_0_init_golden_registers(adev);
if (adev->mode_info.num_crtc) {
u32 tmp;
tmp = RREG32_SOC15(DCE, 0, mmVGA_HDP_CONTROL);
tmp = REG_SET_FIELD(tmp, VGA_HDP_CONTROL, VGA_MEMORY_DISABLE, 1);
WREG32_SOC15(DCE, 0, mmVGA_HDP_CONTROL, tmp);
tmp = RREG32_SOC15(DCE, 0, mmVGA_RENDER_CONTROL);
tmp = REG_SET_FIELD(tmp, VGA_RENDER_CONTROL, VGA_VSTATUS_CNTL, 0);
WREG32_SOC15(DCE, 0, mmVGA_RENDER_CONTROL, tmp);
}
r = gmc_v9_0_gart_enable(adev);
return r;
}
static void gmc_v9_0_gart_disable(struct amdgpu_device *adev)
{
gfxhub_v1_0_gart_disable(adev);
mmhub_v1_0_gart_disable(adev);
amdgpu_gart_table_vram_unpin(adev);
}
static int gmc_v9_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev)) {
DRM_DEBUG("For SRIOV client, shouldn't do anything.\n");
return 0;
}
amdgpu_irq_put(adev, &adev->mc.vm_fault, 0);
gmc_v9_0_gart_disable(adev);
return 0;
}
static int gmc_v9_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gmc_v9_0_hw_fini(adev);
return 0;
}
static int gmc_v9_0_resume(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = gmc_v9_0_hw_init(adev);
if (r)
return r;
amdgpu_vm_reset_all_ids(adev);
return 0;
}
static bool gmc_v9_0_is_idle(void *handle)
{
return true;
}
static int gmc_v9_0_wait_for_idle(void *handle)
{
return 0;
}
static int gmc_v9_0_soft_reset(void *handle)
{
return 0;
}
static int gmc_v9_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return mmhub_v1_0_set_clockgating(adev, state);
}
static void gmc_v9_0_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
mmhub_v1_0_get_clockgating(adev, flags);
}
static int gmc_v9_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
