bool amdgpu_device_is_px(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
if (adev->flags & AMD_IS_PX)
return true;
return false;
}
uint32_t amdgpu_mm_rreg(struct amdgpu_device *adev, uint32_t reg,
bool always_indirect)
{
if ((reg * 4) < adev->rmmio_size && !always_indirect)
return readl(((void __iomem *)adev->rmmio) + (reg * 4));
else {
unsigned long flags;
uint32_t ret;
spin_lock_irqsave(&adev->mmio_idx_lock, flags);
writel((reg * 4), ((void __iomem *)adev->rmmio) + (mmMM_INDEX * 4));
ret = readl(((void __iomem *)adev->rmmio) + (mmMM_DATA * 4));
spin_unlock_irqrestore(&adev->mmio_idx_lock, flags);
return ret;
}
}
void amdgpu_mm_wreg(struct amdgpu_device *adev, uint32_t reg, uint32_t v,
bool always_indirect)
{
if ((reg * 4) < adev->rmmio_size && !always_indirect)
writel(v, ((void __iomem *)adev->rmmio) + (reg * 4));
else {
unsigned long flags;
spin_lock_irqsave(&adev->mmio_idx_lock, flags);
writel((reg * 4), ((void __iomem *)adev->rmmio) + (mmMM_INDEX * 4));
writel(v, ((void __iomem *)adev->rmmio) + (mmMM_DATA * 4));
spin_unlock_irqrestore(&adev->mmio_idx_lock, flags);
}
}
u32 amdgpu_io_rreg(struct amdgpu_device *adev, u32 reg)
{
if ((reg * 4) < adev->rio_mem_size)
return ioread32(adev->rio_mem + (reg * 4));
else {
iowrite32((reg * 4), adev->rio_mem + (mmMM_INDEX * 4));
return ioread32(adev->rio_mem + (mmMM_DATA * 4));
}
}
void amdgpu_io_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
if ((reg * 4) < adev->rio_mem_size)
iowrite32(v, adev->rio_mem + (reg * 4));
else {
iowrite32((reg * 4), adev->rio_mem + (mmMM_INDEX * 4));
iowrite32(v, adev->rio_mem + (mmMM_DATA * 4));
}
}
u32 amdgpu_mm_rdoorbell(struct amdgpu_device *adev, u32 index)
{
if (index < adev->doorbell.num_doorbells) {
return readl(adev->doorbell.ptr + index);
} else {
DRM_ERROR("reading beyond doorbell aperture: 0x%08x!\n", index);
return 0;
}
}
void amdgpu_mm_wdoorbell(struct amdgpu_device *adev, u32 index, u32 v)
{
if (index < adev->doorbell.num_doorbells) {
writel(v, adev->doorbell.ptr + index);
} else {
DRM_ERROR("writing beyond doorbell aperture: 0x%08x!\n", index);
}
}
static uint32_t amdgpu_invalid_rreg(struct amdgpu_device *adev, uint32_t reg)
{
DRM_ERROR("Invalid callback to read register 0x%04X\n", reg);
BUG();
return 0;
}
static void amdgpu_invalid_wreg(struct amdgpu_device *adev, uint32_t reg, uint32_t v)
{
DRM_ERROR("Invalid callback to write register 0x%04X with 0x%08X\n",
reg, v);
BUG();
}
static uint32_t amdgpu_block_invalid_rreg(struct amdgpu_device *adev,
uint32_t block, uint32_t reg)
{
DRM_ERROR("Invalid callback to read register 0x%04X in block 0x%04X\n",
reg, block);
BUG();
return 0;
}
static void amdgpu_block_invalid_wreg(struct amdgpu_device *adev,
uint32_t block,
uint32_t reg, uint32_t v)
{
DRM_ERROR("Invalid block callback to write register 0x%04X in block 0x%04X with 0x%08X\n",
reg, block, v);
BUG();
}
static int amdgpu_vram_scratch_init(struct amdgpu_device *adev)
{
int r;
if (adev->vram_scratch.robj == NULL) {
r = amdgpu_bo_create(adev, AMDGPU_GPU_PAGE_SIZE,
PAGE_SIZE, true, AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL, &adev->vram_scratch.robj);
if (r) {
return r;
}
}
r = amdgpu_bo_reserve(adev->vram_scratch.robj, false);
if (unlikely(r != 0))
return r;
r = amdgpu_bo_pin(adev->vram_scratch.robj,
AMDGPU_GEM_DOMAIN_VRAM, &adev->vram_scratch.gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->vram_scratch.robj);
return r;
}
r = amdgpu_bo_kmap(adev->vram_scratch.robj,
(void **)&adev->vram_scratch.ptr);
if (r)
amdgpu_bo_unpin(adev->vram_scratch.robj);
amdgpu_bo_unreserve(adev->vram_scratch.robj);
return r;
}
static void amdgpu_vram_scratch_fini(struct amdgpu_device *adev)
{
int r;
if (adev->vram_scratch.robj == NULL) {
return;
}
r = amdgpu_bo_reserve(adev->vram_scratch.robj, false);
if (likely(r == 0)) {
amdgpu_bo_kunmap(adev->vram_scratch.robj);
amdgpu_bo_unpin(adev->vram_scratch.robj);
amdgpu_bo_unreserve(adev->vram_scratch.robj);
}
amdgpu_bo_unref(&adev->vram_scratch.robj);
}
void amdgpu_program_register_sequence(struct amdgpu_device *adev,
const u32 *registers,
const u32 array_size)
{
u32 tmp, reg, and_mask, or_mask;
int i;
if (array_size % 3)
return;
for (i = 0; i < array_size; i +=3) {
reg = registers[i + 0];
and_mask = registers[i + 1];
or_mask = registers[i + 2];
if (and_mask == 0xffffffff) {
tmp = or_mask;
} else {
tmp = RREG32(reg);
tmp &= ~and_mask;
tmp |= or_mask;
}
WREG32(reg, tmp);
}
}
void amdgpu_pci_config_reset(struct amdgpu_device *adev)
{
pci_write_config_dword(adev->pdev, 0x7c, AMDGPU_ASIC_RESET_DATA);
}
static int amdgpu_doorbell_init(struct amdgpu_device *adev)
{
adev->doorbell.base = pci_resource_start(adev->pdev, 2);
adev->doorbell.size = pci_resource_len(adev->pdev, 2);
adev->doorbell.num_doorbells = min_t(u32, adev->doorbell.size / sizeof(u32),
AMDGPU_DOORBELL_MAX_ASSIGNMENT+1);
if (adev->doorbell.num_doorbells == 0)
return -EINVAL;
adev->doorbell.ptr = ioremap(adev->doorbell.base, adev->doorbell.num_doorbells * sizeof(u32));
if (adev->doorbell.ptr == NULL) {
return -ENOMEM;
}
DRM_INFO("doorbell mmio base: 0x%08X\n", (uint32_t)adev->doorbell.base);
DRM_INFO("doorbell mmio size: %u\n", (unsigned)adev->doorbell.size);
return 0;
}
static void amdgpu_doorbell_fini(struct amdgpu_device *adev)
{
iounmap(adev->doorbell.ptr);
adev->doorbell.ptr = NULL;
}
void amdgpu_doorbell_get_kfd_info(struct amdgpu_device *adev,
phys_addr_t *aperture_base,
size_t *aperture_size,
size_t *start_offset)
{
if (adev->doorbell.size > adev->doorbell.num_doorbells * sizeof(u32)) {
*aperture_base = adev->doorbell.base;
*aperture_size = adev->doorbell.size;
*start_offset = adev->doorbell.num_doorbells * sizeof(u32);
} else {
*aperture_base = 0;
*aperture_size = 0;
*start_offset = 0;
}
}
static void amdgpu_wb_fini(struct amdgpu_device *adev)
{
if (adev->wb.wb_obj) {
if (!amdgpu_bo_reserve(adev->wb.wb_obj, false)) {
amdgpu_bo_kunmap(adev->wb.wb_obj);
amdgpu_bo_unpin(adev->wb.wb_obj);
amdgpu_bo_unreserve(adev->wb.wb_obj);
}
amdgpu_bo_unref(&adev->wb.wb_obj);
adev->wb.wb = NULL;
adev->wb.wb_obj = NULL;
}
}
static int amdgpu_wb_init(struct amdgpu_device *adev)
{
int r;
if (adev->wb.wb_obj == NULL) {
r = amdgpu_bo_create(adev, AMDGPU_MAX_WB * 4, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL, NULL,
&adev->wb.wb_obj);
if (r) {
dev_warn(adev->dev, "(%d) create WB bo failed\n", r);
return r;
}
r = amdgpu_bo_reserve(adev->wb.wb_obj, false);
if (unlikely(r != 0)) {
amdgpu_wb_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->wb.wb_obj, AMDGPU_GEM_DOMAIN_GTT,
&adev->wb.gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->wb.wb_obj);
dev_warn(adev->dev, "(%d) pin WB bo failed\n", r);
amdgpu_wb_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->wb.wb_obj, (void **)&adev->wb.wb);
amdgpu_bo_unreserve(adev->wb.wb_obj);
if (r) {
dev_warn(adev->dev, "(%d) map WB bo failed\n", r);
amdgpu_wb_fini(adev);
return r;
}
adev->wb.num_wb = AMDGPU_MAX_WB;
memset(&adev->wb.used, 0, sizeof(adev->wb.used));
memset((char *)adev->wb.wb, 0, AMDGPU_GPU_PAGE_SIZE);
}
return 0;
}
int amdgpu_wb_get(struct amdgpu_device *adev, u32 *wb)
{
unsigned long offset = find_first_zero_bit(adev->wb.used, adev->wb.num_wb);
if (offset < adev->wb.num_wb) {
__set_bit(offset, adev->wb.used);
*wb = offset;
return 0;
} else {
return -EINVAL;
}
}
void amdgpu_wb_free(struct amdgpu_device *adev, u32 wb)
{
if (wb < adev->wb.num_wb)
__clear_bit(wb, adev->wb.used);
}
void amdgpu_vram_location(struct amdgpu_device *adev, struct amdgpu_mc *mc, u64 base)
{
uint64_t limit = (uint64_t)amdgpu_vram_limit << 20;
mc->vram_start = base;
if (mc->mc_vram_size > (adev->mc.mc_mask - base + 1)) {
dev_warn(adev->dev, "limiting VRAM to PCI aperture size\n");
mc->real_vram_size = mc->aper_size;
mc->mc_vram_size = mc->aper_size;
}
mc->vram_end = mc->vram_start + mc->mc_vram_size - 1;
if (limit && limit < mc->real_vram_size)
mc->real_vram_size = limit;
dev_info(adev->dev, "VRAM: %lluM 0x%016llX - 0x%016llX (%lluM used)\n",
mc->mc_vram_size >> 20, mc->vram_start,
mc->vram_end, mc->real_vram_size >> 20);
}
void amdgpu_gtt_location(struct amdgpu_device *adev, struct amdgpu_mc *mc)
{
u64 size_af, size_bf;
size_af = ((adev->mc.mc_mask - mc->vram_end) + mc->gtt_base_align) & ~mc->gtt_base_align;
size_bf = mc->vram_start & ~mc->gtt_base_align;
if (size_bf > size_af) {
if (mc->gtt_size > size_bf) {
dev_warn(adev->dev, "limiting GTT\n");
mc->gtt_size = size_bf;
}
mc->gtt_start = (mc->vram_start & ~mc->gtt_base_align) - mc->gtt_size;
} else {
if (mc->gtt_size > size_af) {
dev_warn(adev->dev, "limiting GTT\n");
mc->gtt_size = size_af;
}
mc->gtt_start = (mc->vram_end + 1 + mc->gtt_base_align) & ~mc->gtt_base_align;
}
mc->gtt_end = mc->gtt_start + mc->gtt_size - 1;
dev_info(adev->dev, "GTT: %lluM 0x%016llX - 0x%016llX\n",
mc->gtt_size >> 20, mc->gtt_start, mc->gtt_end);
}
bool amdgpu_card_posted(struct amdgpu_device *adev)
{
uint32_t reg;
reg = RREG32(mmCONFIG_MEMSIZE);
if (reg)
return true;
return false;
}
bool amdgpu_boot_test_post_card(struct amdgpu_device *adev)
{
if (amdgpu_card_posted(adev))
return true;
if (adev->bios) {
DRM_INFO("GPU not posted. posting now...\n");
if (adev->is_atom_bios)
amdgpu_atom_asic_init(adev->mode_info.atom_context);
return true;
} else {
dev_err(adev->dev, "Card not posted and no BIOS - ignoring\n");
return false;
}
}
int amdgpu_dummy_page_init(struct amdgpu_device *adev)
{
if (adev->dummy_page.page)
return 0;
adev->dummy_page.page = alloc_page(GFP_DMA32 | GFP_KERNEL | __GFP_ZERO);
if (adev->dummy_page.page == NULL)
return -ENOMEM;
adev->dummy_page.addr = pci_map_page(adev->pdev, adev->dummy_page.page,
0, PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(adev->pdev, adev->dummy_page.addr)) {
dev_err(&adev->pdev->dev, "Failed to DMA MAP the dummy page\n");
__free_page(adev->dummy_page.page);
adev->dummy_page.page = NULL;
return -ENOMEM;
}
return 0;
}
void amdgpu_dummy_page_fini(struct amdgpu_device *adev)
{
if (adev->dummy_page.page == NULL)
return;
pci_unmap_page(adev->pdev, adev->dummy_page.addr,
PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
__free_page(adev->dummy_page.page);
adev->dummy_page.page = NULL;
}
static uint32_t cail_pll_read(struct card_info *info, uint32_t reg)
{
return 0;
}
static void cail_pll_write(struct card_info *info, uint32_t reg, uint32_t val)
{
}
static uint32_t cail_mc_read(struct card_info *info, uint32_t reg)
{
return 0;
}
static void cail_mc_write(struct card_info *info, uint32_t reg, uint32_t val)
{
}
static void cail_reg_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct amdgpu_device *adev = info->dev->dev_private;
WREG32(reg, val);
}
static uint32_t cail_reg_read(struct card_info *info, uint32_t reg)
{
struct amdgpu_device *adev = info->dev->dev_private;
uint32_t r;
r = RREG32(reg);
return r;
}
static void cail_ioreg_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct amdgpu_device *adev = info->dev->dev_private;
WREG32_IO(reg, val);
}
static uint32_t cail_ioreg_read(struct card_info *info, uint32_t reg)
{
struct amdgpu_device *adev = info->dev->dev_private;
uint32_t r;
r = RREG32_IO(reg);
return r;
}
static void amdgpu_atombios_fini(struct amdgpu_device *adev)
{
if (adev->mode_info.atom_context)
kfree(adev->mode_info.atom_context->scratch);
kfree(adev->mode_info.atom_context);
adev->mode_info.atom_context = NULL;
kfree(adev->mode_info.atom_card_info);
adev->mode_info.atom_card_info = NULL;
}
static int amdgpu_atombios_init(struct amdgpu_device *adev)
{
struct card_info *atom_card_info =
kzalloc(sizeof(struct card_info), GFP_KERNEL);
if (!atom_card_info)
return -ENOMEM;
adev->mode_info.atom_card_info = atom_card_info;
atom_card_info->dev = adev->ddev;
atom_card_info->reg_read = cail_reg_read;
atom_card_info->reg_write = cail_reg_write;
if (adev->rio_mem) {
atom_card_info->ioreg_read = cail_ioreg_read;
atom_card_info->ioreg_write = cail_ioreg_write;
} else {
DRM_ERROR("Unable to find PCI I/O BAR; using MMIO for ATOM IIO\n");
atom_card_info->ioreg_read = cail_reg_read;
atom_card_info->ioreg_write = cail_reg_write;
}
atom_card_info->mc_read = cail_mc_read;
atom_card_info->mc_write = cail_mc_write;
atom_card_info->pll_read = cail_pll_read;
atom_card_info->pll_write = cail_pll_write;
adev->mode_info.atom_context = amdgpu_atom_parse(atom_card_info, adev->bios);
if (!adev->mode_info.atom_context) {
amdgpu_atombios_fini(adev);
return -ENOMEM;
}
mutex_init(&adev->mode_info.atom_context->mutex);
amdgpu_atombios_scratch_regs_init(adev);
amdgpu_atom_allocate_fb_scratch(adev->mode_info.atom_context);
return 0;
}
static unsigned int amdgpu_vga_set_decode(void *cookie, bool state)
{
struct amdgpu_device *adev = cookie;
amdgpu_asic_set_vga_state(adev, state);
if (state)
return VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM |
VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
else
return VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
}
static bool amdgpu_check_pot_argument(int arg)
{
return (arg & (arg - 1)) == 0;
}
static void amdgpu_check_arguments(struct amdgpu_device *adev)
{
if (!amdgpu_check_pot_argument(amdgpu_vram_limit)) {
dev_warn(adev->dev, "vram limit (%d) must be a power of 2\n",
amdgpu_vram_limit);
amdgpu_vram_limit = 0;
}
if (amdgpu_gart_size != -1) {
if (amdgpu_gart_size < 32) {
dev_warn(adev->dev, "gart size (%d) too small\n",
amdgpu_gart_size);
amdgpu_gart_size = -1;
} else if (!amdgpu_check_pot_argument(amdgpu_gart_size)) {
dev_warn(adev->dev, "gart size (%d) must be a power of 2\n",
amdgpu_gart_size);
amdgpu_gart_size = -1;
}
}
if (!amdgpu_check_pot_argument(amdgpu_vm_size)) {
dev_warn(adev->dev, "VM size (%d) must be a power of 2\n",
amdgpu_vm_size);
amdgpu_vm_size = 8;
}
if (amdgpu_vm_size < 1) {
dev_warn(adev->dev, "VM size (%d) too small, min is 1GB\n",
amdgpu_vm_size);
amdgpu_vm_size = 8;
}
if (amdgpu_vm_size > 1024) {
dev_warn(adev->dev, "VM size (%d) too large, max is 1TB\n",
amdgpu_vm_size);
amdgpu_vm_size = 8;
}
if (amdgpu_vm_block_size == -1) {
unsigned bits = ilog2(amdgpu_vm_size) + 18;
if (amdgpu_vm_size <= 8)
amdgpu_vm_block_size = bits - 9;
else
amdgpu_vm_block_size = (bits + 3) / 2;
} else if (amdgpu_vm_block_size < 9) {
dev_warn(adev->dev, "VM page table size (%d) too small\n",
amdgpu_vm_block_size);
amdgpu_vm_block_size = 9;
}
if (amdgpu_vm_block_size > 24 ||
(amdgpu_vm_size * 1024) < (1ull << amdgpu_vm_block_size)) {
dev_warn(adev->dev, "VM page table size (%d) too large\n",
amdgpu_vm_block_size);
amdgpu_vm_block_size = 9;
}
}
static void amdgpu_switcheroo_set_state(struct pci_dev *pdev, enum vga_switcheroo_state state)
{
struct drm_device *dev = pci_get_drvdata(pdev);
if (amdgpu_device_is_px(dev) && state == VGA_SWITCHEROO_OFF)
return;
if (state == VGA_SWITCHEROO_ON) {
unsigned d3_delay = dev->pdev->d3_delay;
printk(KERN_INFO "amdgpu: switched on\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
amdgpu_resume_kms(dev, true, true);
dev->pdev->d3_delay = d3_delay;
dev->switch_power_state = DRM_SWITCH_POWER_ON;
drm_kms_helper_poll_enable(dev);
} else {
printk(KERN_INFO "amdgpu: switched off\n");
drm_kms_helper_poll_disable(dev);
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
amdgpu_suspend_kms(dev, true, true);
dev->switch_power_state = DRM_SWITCH_POWER_OFF;
}
}
static bool amdgpu_switcheroo_can_switch(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
return dev->open_count == 0;
}
int amdgpu_set_clockgating_state(struct amdgpu_device *adev,
enum amd_ip_block_type block_type,
enum amd_clockgating_state state)
{
int i, r = 0;
for (i = 0; i < adev->num_ip_blocks; i++) {
if (adev->ip_blocks[i].type == block_type) {
r = adev->ip_blocks[i].funcs->set_clockgating_state((void *)adev,
state);
if (r)
return r;
}
}
return r;
}
int amdgpu_set_powergating_state(struct amdgpu_device *adev,
enum amd_ip_block_type block_type,
enum amd_powergating_state state)
{
int i, r = 0;
for (i = 0; i < adev->num_ip_blocks; i++) {
if (adev->ip_blocks[i].type == block_type) {
r = adev->ip_blocks[i].funcs->set_powergating_state((void *)adev,
state);
if (r)
return r;
}
}
return r;
}
const struct amdgpu_ip_block_version * amdgpu_get_ip_block(
struct amdgpu_device *adev,
enum amd_ip_block_type type)
{
int i;
for (i = 0; i < adev->num_ip_blocks; i++)
if (adev->ip_blocks[i].type == type)
return &adev->ip_blocks[i];
return NULL;
}
int amdgpu_ip_block_version_cmp(struct amdgpu_device *adev,
enum amd_ip_block_type type,
u32 major, u32 minor)
{
const struct amdgpu_ip_block_version *ip_block;
ip_block = amdgpu_get_ip_block(adev, type);
if (ip_block && ((ip_block->major > major) ||
((ip_block->major == major) &&
(ip_block->minor >= minor))))
return 0;
return 1;
}
static int amdgpu_early_init(struct amdgpu_device *adev)
{
int i, r;
switch (adev->asic_type) {
case CHIP_TOPAZ:
case CHIP_TONGA:
case CHIP_FIJI:
case CHIP_CARRIZO:
if (adev->asic_type == CHIP_CARRIZO)
adev->family = AMDGPU_FAMILY_CZ;
else
adev->family = AMDGPU_FAMILY_VI;
r = vi_set_ip_blocks(adev);
if (r)
return r;
break;
#ifdef CONFIG_DRM_AMDGPU_CIK
case CHIP_BONAIRE:
case CHIP_HAWAII:
case CHIP_KAVERI:
case CHIP_KABINI:
case CHIP_MULLINS:
if ((adev->asic_type == CHIP_BONAIRE) || (adev->asic_type == CHIP_HAWAII))
adev->family = AMDGPU_FAMILY_CI;
else
adev->family = AMDGPU_FAMILY_KV;
r = cik_set_ip_blocks(adev);
if (r)
return r;
break;
#endif
default:
return -EINVAL;
}
adev->ip_block_status = kcalloc(adev->num_ip_blocks,
sizeof(struct amdgpu_ip_block_status), GFP_KERNEL);
if (adev->ip_block_status == NULL)
return -ENOMEM;
if (adev->ip_blocks == NULL) {
DRM_ERROR("No IP blocks found!\n");
return r;
}
for (i = 0; i < adev->num_ip_blocks; i++) {
if ((amdgpu_ip_block_mask & (1 << i)) == 0) {
DRM_ERROR("disabled ip block: %d\n", i);
adev->ip_block_status[i].valid = false;
} else {
if (adev->ip_blocks[i].funcs->early_init) {
r = adev->ip_blocks[i].funcs->early_init((void *)adev);
if (r == -ENOENT)
adev->ip_block_status[i].valid = false;
else if (r)
return r;
else
adev->ip_block_status[i].valid = true;
} else {
adev->ip_block_status[i].valid = true;
}
}
}
return 0;
}
static int amdgpu_init(struct amdgpu_device *adev)
{
int i, r;
for (i = 0; i < adev->num_ip_blocks; i++) {
if (!adev->ip_block_status[i].valid)
continue;
r = adev->ip_blocks[i].funcs->sw_init((void *)adev);
if (r)
return r;
adev->ip_block_status[i].sw = true;
if (adev->ip_blocks[i].type == AMD_IP_BLOCK_TYPE_GMC) {
r = amdgpu_vram_scratch_init(adev);
if (r)
return r;
r = adev->ip_blocks[i].funcs->hw_init((void *)adev);
if (r)
return r;
r = amdgpu_wb_init(adev);
if (r)
return r;
adev->ip_block_status[i].hw = true;
}
}
for (i = 0; i < adev->num_ip_blocks; i++) {
if (!adev->ip_block_status[i].sw)
continue;
if (adev->ip_blocks[i].type == AMD_IP_BLOCK_TYPE_GMC)
continue;
r = adev->ip_blocks[i].funcs->hw_init((void *)adev);
if (r)
return r;
adev->ip_block_status[i].hw = true;
}
return 0;
}
static int amdgpu_late_init(struct amdgpu_device *adev)
{
int i = 0, r;
for (i = 0; i < adev->num_ip_blocks; i++) {
if (!adev->ip_block_status[i].valid)
continue;
r = adev->ip_blocks[i].funcs->set_clockgating_state((void *)adev,
AMD_CG_STATE_GATE);
if (r)
return r;
if (adev->ip_blocks[i].funcs->late_init) {
r = adev->ip_blocks[i].funcs->late_init((void *)adev);
if (r)
return r;
}
}
return 0;
}
static int amdgpu_fini(struct amdgpu_device *adev)
{
int i, r;
for (i = adev->num_ip_blocks - 1; i >= 0; i--) {
if (!adev->ip_block_status[i].hw)
continue;
if (adev->ip_blocks[i].type == AMD_IP_BLOCK_TYPE_GMC) {
amdgpu_wb_fini(adev);
amdgpu_vram_scratch_fini(adev);
}
r = adev->ip_blocks[i].funcs->set_clockgating_state((void *)adev,
AMD_CG_STATE_UNGATE);
if (r)
return r;
r = adev->ip_blocks[i].funcs->hw_fini((void *)adev);
adev->ip_block_status[i].hw = false;
}
for (i = adev->num_ip_blocks - 1; i >= 0; i--) {
if (!adev->ip_block_status[i].sw)
continue;
r = adev->ip_blocks[i].funcs->sw_fini((void *)adev);
adev->ip_block_status[i].sw = false;
adev->ip_block_status[i].valid = false;
}
return 0;
}
static int amdgpu_suspend(struct amdgpu_device *adev)
{
int i, r;
for (i = adev->num_ip_blocks - 1; i >= 0; i--) {
if (!adev->ip_block_status[i].valid)
continue;
r = adev->ip_blocks[i].funcs->set_clockgating_state((void *)adev,
AMD_CG_STATE_UNGATE);
r = adev->ip_blocks[i].funcs->suspend(adev);
}
return 0;
}
static int amdgpu_resume(struct amdgpu_device *adev)
{
int i, r;
for (i = 0; i < adev->num_ip_blocks; i++) {
if (!adev->ip_block_status[i].valid)
continue;
r = adev->ip_blocks[i].funcs->resume(adev);
if (r)
return r;
}
return 0;
}
int amdgpu_device_init(struct amdgpu_device *adev,
struct drm_device *ddev,
struct pci_dev *pdev,
uint32_t flags)
{
int r, i;
bool runtime = false;
adev->shutdown = false;
adev->dev = &pdev->dev;
adev->ddev = ddev;
adev->pdev = pdev;
adev->flags = flags;
adev->asic_type = flags & AMD_ASIC_MASK;
adev->is_atom_bios = false;
adev->usec_timeout = AMDGPU_MAX_USEC_TIMEOUT;
adev->mc.gtt_size = 512 * 1024 * 1024;
adev->accel_working = false;
adev->num_rings = 0;
adev->mman.buffer_funcs = NULL;
adev->mman.buffer_funcs_ring = NULL;
adev->vm_manager.vm_pte_funcs = NULL;
adev->vm_manager.vm_pte_funcs_ring = NULL;
adev->gart.gart_funcs = NULL;
adev->fence_context = fence_context_alloc(AMDGPU_MAX_RINGS);
adev->smc_rreg = &amdgpu_invalid_rreg;
adev->smc_wreg = &amdgpu_invalid_wreg;
adev->pcie_rreg = &amdgpu_invalid_rreg;
adev->pcie_wreg = &amdgpu_invalid_wreg;
adev->uvd_ctx_rreg = &amdgpu_invalid_rreg;
adev->uvd_ctx_wreg = &amdgpu_invalid_wreg;
adev->didt_rreg = &amdgpu_invalid_rreg;
adev->didt_wreg = &amdgpu_invalid_wreg;
adev->audio_endpt_rreg = &amdgpu_block_invalid_rreg;
adev->audio_endpt_wreg = &amdgpu_block_invalid_wreg;
DRM_INFO("initializing kernel modesetting (%s 0x%04X:0x%04X 0x%04X:0x%04X 0x%02X).\n",
amdgpu_asic_name[adev->asic_type], pdev->vendor, pdev->device,
pdev->subsystem_vendor, pdev->subsystem_device, pdev->revision);
mutex_init(&adev->ring_lock);
atomic_set(&adev->irq.ih.lock, 0);
mutex_init(&adev->gem.mutex);
mutex_init(&adev->pm.mutex);
mutex_init(&adev->gfx.gpu_clock_mutex);
mutex_init(&adev->srbm_mutex);
mutex_init(&adev->grbm_idx_mutex);
init_rwsem(&adev->exclusive_lock);
mutex_init(&adev->mn_lock);
hash_init(adev->mn_hash);
amdgpu_check_arguments(adev);
spin_lock_init(&adev->mmio_idx_lock);
spin_lock_init(&adev->smc_idx_lock);
spin_lock_init(&adev->pcie_idx_lock);
spin_lock_init(&adev->uvd_ctx_idx_lock);
spin_lock_init(&adev->didt_idx_lock);
spin_lock_init(&adev->audio_endpt_idx_lock);
adev->rmmio_base = pci_resource_start(adev->pdev, 5);
adev->rmmio_size = pci_resource_len(adev->pdev, 5);
adev->rmmio = ioremap(adev->rmmio_base, adev->rmmio_size);
if (adev->rmmio == NULL) {
return -ENOMEM;
}
DRM_INFO("register mmio base: 0x%08X\n", (uint32_t)adev->rmmio_base);
DRM_INFO("register mmio size: %u\n", (unsigned)adev->rmmio_size);
amdgpu_doorbell_init(adev);
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
if (pci_resource_flags(adev->pdev, i) & IORESOURCE_IO) {
adev->rio_mem_size = pci_resource_len(adev->pdev, i);
adev->rio_mem = pci_iomap(adev->pdev, i, adev->rio_mem_size);
break;
}
}
if (adev->rio_mem == NULL)
DRM_ERROR("Unable to find PCI I/O BAR\n");
r = amdgpu_early_init(adev);
if (r)
return r;
vga_client_register(adev->pdev, adev, NULL, amdgpu_vga_set_decode);
if (amdgpu_runtime_pm == 1)
runtime = true;
if (amdgpu_device_is_px(ddev))
runtime = true;
vga_switcheroo_register_client(adev->pdev, &amdgpu_switcheroo_ops, runtime);
if (runtime)
vga_switcheroo_init_domain_pm_ops(adev->dev, &adev->vga_pm_domain);
if (!amdgpu_get_bios(adev))
return -EINVAL;
if (!adev->is_atom_bios) {
dev_err(adev->dev, "Expecting atombios for GPU\n");
return -EINVAL;
}
r = amdgpu_atombios_init(adev);
if (r)
return r;
if (!amdgpu_card_posted(adev)) {
if (!adev->bios) {
dev_err(adev->dev, "Card not posted and no BIOS - ignoring\n");
return -EINVAL;
}
DRM_INFO("GPU not posted. posting now...\n");
amdgpu_atom_asic_init(adev->mode_info.atom_context);
}
r = amdgpu_atombios_get_clock_info(adev);
if (r)
return r;
amdgpu_atombios_i2c_init(adev);
r = amdgpu_fence_driver_init(adev);
if (r)
return r;
drm_mode_config_init(adev->ddev);
r = amdgpu_init(adev);
if (r) {
amdgpu_fini(adev);
return r;
}
adev->accel_working = true;
amdgpu_fbdev_init(adev);
r = amdgpu_ib_pool_init(adev);
if (r) {
dev_err(adev->dev, "IB initialization failed (%d).\n", r);
return r;
}
r = amdgpu_ctx_init(adev, true, &adev->kernel_ctx);
if (r) {
dev_err(adev->dev, "failed to create kernel context (%d).\n", r);
return r;
}
r = amdgpu_ib_ring_tests(adev);
if (r)
DRM_ERROR("ib ring test failed (%d).\n", r);
r = amdgpu_gem_debugfs_init(adev);
if (r) {
DRM_ERROR("registering gem debugfs failed (%d).\n", r);
}
r = amdgpu_debugfs_regs_init(adev);
if (r) {
DRM_ERROR("registering register debugfs failed (%d).\n", r);
}
if ((amdgpu_testing & 1)) {
if (adev->accel_working)
amdgpu_test_moves(adev);
else
DRM_INFO("amdgpu: acceleration disabled, skipping move tests\n");
}
if ((amdgpu_testing & 2)) {
if (adev->accel_working)
amdgpu_test_syncing(adev);
else
DRM_INFO("amdgpu: acceleration disabled, skipping sync tests\n");
}
if (amdgpu_benchmarking) {
if (adev->accel_working)
amdgpu_benchmark(adev, amdgpu_benchmarking);
else
DRM_INFO("amdgpu: acceleration disabled, skipping benchmarks\n");
}
r = amdgpu_late_init(adev);
if (r)
return r;
return 0;
}
void amdgpu_device_fini(struct amdgpu_device *adev)
{
int r;
DRM_INFO("amdgpu: finishing device.\n");
adev->shutdown = true;
amdgpu_bo_evict_vram(adev);
amdgpu_ctx_fini(&adev->kernel_ctx);
amdgpu_ib_pool_fini(adev);
amdgpu_fence_driver_fini(adev);
amdgpu_fbdev_fini(adev);
r = amdgpu_fini(adev);
kfree(adev->ip_block_status);
adev->ip_block_status = NULL;
adev->accel_working = false;
amdgpu_i2c_fini(adev);
amdgpu_atombios_fini(adev);
kfree(adev->bios);
adev->bios = NULL;
vga_switcheroo_unregister_client(adev->pdev);
vga_client_register(adev->pdev, NULL, NULL, NULL);
if (adev->rio_mem)
pci_iounmap(adev->pdev, adev->rio_mem);
adev->rio_mem = NULL;
iounmap(adev->rmmio);
adev->rmmio = NULL;
amdgpu_doorbell_fini(adev);
amdgpu_debugfs_regs_cleanup(adev);
amdgpu_debugfs_remove_files(adev);
}
int amdgpu_suspend_kms(struct drm_device *dev, bool suspend, bool fbcon)
{
struct amdgpu_device *adev;
struct drm_crtc *crtc;
struct drm_connector *connector;
int r;
if (dev == NULL || dev->dev_private == NULL) {
return -ENODEV;
}
adev = dev->dev_private;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
drm_kms_helper_poll_disable(dev);
drm_modeset_lock_all(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
}
drm_modeset_unlock_all(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct amdgpu_framebuffer *rfb = to_amdgpu_framebuffer(crtc->primary->fb);
struct amdgpu_bo *robj;
if (rfb == NULL || rfb->obj == NULL) {
continue;
}
robj = gem_to_amdgpu_bo(rfb->obj);
if (!amdgpu_fbdev_robj_is_fb(adev, robj)) {
r = amdgpu_bo_reserve(robj, false);
if (r == 0) {
amdgpu_bo_unpin(robj);
amdgpu_bo_unreserve(robj);
}
}
}
amdgpu_bo_evict_vram(adev);
amdgpu_fence_driver_suspend(adev);
r = amdgpu_suspend(adev);
amdgpu_bo_evict_vram(adev);
pci_save_state(dev->pdev);
if (suspend) {
pci_disable_device(dev->pdev);
pci_set_power_state(dev->pdev, PCI_D3hot);
}
if (fbcon) {
console_lock();
amdgpu_fbdev_set_suspend(adev, 1);
console_unlock();
}
return 0;
}
int amdgpu_resume_kms(struct drm_device *dev, bool resume, bool fbcon)
{
struct drm_connector *connector;
struct amdgpu_device *adev = dev->dev_private;
int r;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
if (fbcon) {
console_lock();
}
if (resume) {
pci_set_power_state(dev->pdev, PCI_D0);
pci_restore_state(dev->pdev);
if (pci_enable_device(dev->pdev)) {
if (fbcon)
console_unlock();
return -1;
}
}
amdgpu_atom_asic_init(adev->mode_info.atom_context);
r = amdgpu_resume(adev);
amdgpu_fence_driver_resume(adev);
r = amdgpu_ib_ring_tests(adev);
if (r)
DRM_ERROR("ib ring test failed (%d).\n", r);
r = amdgpu_late_init(adev);
if (r)
return r;
if (fbcon) {
drm_helper_resume_force_mode(dev);
drm_modeset_lock_all(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_ON);
}
drm_modeset_unlock_all(dev);
}
drm_kms_helper_poll_enable(dev);
if (fbcon) {
amdgpu_fbdev_set_suspend(adev, 0);
console_unlock();
}
return 0;
}
int amdgpu_gpu_reset(struct amdgpu_device *adev)
{
unsigned ring_sizes[AMDGPU_MAX_RINGS];
uint32_t *ring_data[AMDGPU_MAX_RINGS];
bool saved = false;
int i, r;
int resched;
down_write(&adev->exclusive_lock);
if (!adev->needs_reset) {
up_write(&adev->exclusive_lock);
return 0;
}
adev->needs_reset = false;
atomic_inc(&adev->gpu_reset_counter);
resched = ttm_bo_lock_delayed_workqueue(&adev->mman.bdev);
r = amdgpu_suspend(adev);
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring)
continue;
ring_sizes[i] = amdgpu_ring_backup(ring, &ring_data[i]);
if (ring_sizes[i]) {
saved = true;
dev_info(adev->dev, "Saved %d dwords of commands "
"on ring %d.\n", ring_sizes[i], i);
}
}
retry:
r = amdgpu_asic_reset(adev);
if (!r) {
dev_info(adev->dev, "GPU reset succeeded, trying to resume\n");
r = amdgpu_resume(adev);
}
if (!r) {
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring)
continue;
amdgpu_ring_restore(ring, ring_sizes[i], ring_data[i]);
ring_sizes[i] = 0;
ring_data[i] = NULL;
}
r = amdgpu_ib_ring_tests(adev);
if (r) {
dev_err(adev->dev, "ib ring test failed (%d).\n", r);
if (saved) {
saved = false;
r = amdgpu_suspend(adev);
goto retry;
}
}
} else {
amdgpu_fence_driver_force_completion(adev);
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
if (adev->rings[i])
kfree(ring_data[i]);
}
}
drm_helper_resume_force_mode(adev->ddev);
ttm_bo_unlock_delayed_workqueue(&adev->mman.bdev, resched);
if (r) {
dev_info(adev->dev, "GPU reset failed\n");
}
up_write(&adev->exclusive_lock);
return r;
}
int amdgpu_debugfs_add_files(struct amdgpu_device *adev,
struct drm_info_list *files,
unsigned nfiles)
{
unsigned i;
for (i = 0; i < adev->debugfs_count; i++) {
if (adev->debugfs[i].files == files) {
return 0;
}
}
i = adev->debugfs_count + 1;
if (i > AMDGPU_DEBUGFS_MAX_COMPONENTS) {
DRM_ERROR("Reached maximum number of debugfs components.\n");
DRM_ERROR("Report so we increase "
"AMDGPU_DEBUGFS_MAX_COMPONENTS.\n");
return -EINVAL;
}
adev->debugfs[adev->debugfs_count].files = files;
adev->debugfs[adev->debugfs_count].num_files = nfiles;
adev->debugfs_count = i;
#if defined(CONFIG_DEBUG_FS)
drm_debugfs_create_files(files, nfiles,
adev->ddev->control->debugfs_root,
adev->ddev->control);
drm_debugfs_create_files(files, nfiles,
adev->ddev->primary->debugfs_root,
adev->ddev->primary);
#endif
return 0;
}
static void amdgpu_debugfs_remove_files(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
unsigned i;
for (i = 0; i < adev->debugfs_count; i++) {
drm_debugfs_remove_files(adev->debugfs[i].files,
adev->debugfs[i].num_files,
adev->ddev->control);
drm_debugfs_remove_files(adev->debugfs[i].files,
adev->debugfs[i].num_files,
adev->ddev->primary);
}
#endif
}
static ssize_t amdgpu_debugfs_regs_read(struct file *f, char __user *buf,
size_t size, loff_t *pos)
{
struct amdgpu_device *adev = f->f_inode->i_private;
ssize_t result = 0;
int r;
if (size & 0x3 || *pos & 0x3)
return -EINVAL;
while (size) {
uint32_t value;
if (*pos > adev->rmmio_size)
return result;
value = RREG32(*pos >> 2);
r = put_user(value, (uint32_t *)buf);
if (r)
return r;
result += 4;
buf += 4;
*pos += 4;
size -= 4;
}
return result;
}
static ssize_t amdgpu_debugfs_regs_write(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
struct amdgpu_device *adev = f->f_inode->i_private;
ssize_t result = 0;
int r;
if (size & 0x3 || *pos & 0x3)
return -EINVAL;
while (size) {
uint32_t value;
if (*pos > adev->rmmio_size)
return result;
r = get_user(value, (uint32_t *)buf);
if (r)
return r;
WREG32(*pos >> 2, value);
result += 4;
buf += 4;
*pos += 4;
size -= 4;
}
return result;
}
static int amdgpu_debugfs_regs_init(struct amdgpu_device *adev)
{
struct drm_minor *minor = adev->ddev->primary;
struct dentry *ent, *root = minor->debugfs_root;
ent = debugfs_create_file("amdgpu_regs", S_IFREG | S_IRUGO, root,
adev, &amdgpu_debugfs_regs_fops);
if (IS_ERR(ent))
return PTR_ERR(ent);
i_size_write(ent->d_inode, adev->rmmio_size);
adev->debugfs_regs = ent;
return 0;
}
static void amdgpu_debugfs_regs_cleanup(struct amdgpu_device *adev)
{
debugfs_remove(adev->debugfs_regs);
adev->debugfs_regs = NULL;
}
int amdgpu_debugfs_init(struct drm_minor *minor)
{
return 0;
}
void amdgpu_debugfs_cleanup(struct drm_minor *minor)
{
}
static int amdgpu_debugfs_regs_init(struct amdgpu_device *adev)
{
return 0;
}
static void amdgpu_debugfs_regs_cleanup(struct amdgpu_device *adev) { }
