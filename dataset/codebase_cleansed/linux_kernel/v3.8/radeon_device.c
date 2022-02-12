void radeon_surface_init(struct radeon_device *rdev)
{
if (rdev->family < CHIP_R600) {
int i;
for (i = 0; i < RADEON_GEM_MAX_SURFACES; i++) {
if (rdev->surface_regs[i].bo)
radeon_bo_get_surface_reg(rdev->surface_regs[i].bo);
else
radeon_clear_surface_reg(rdev, i);
}
WREG32(RADEON_SURFACE_CNTL, 0);
}
}
void radeon_scratch_init(struct radeon_device *rdev)
{
int i;
if (rdev->family < CHIP_R300) {
rdev->scratch.num_reg = 5;
} else {
rdev->scratch.num_reg = 7;
}
rdev->scratch.reg_base = RADEON_SCRATCH_REG0;
for (i = 0; i < rdev->scratch.num_reg; i++) {
rdev->scratch.free[i] = true;
rdev->scratch.reg[i] = rdev->scratch.reg_base + (i * 4);
}
}
int radeon_scratch_get(struct radeon_device *rdev, uint32_t *reg)
{
int i;
for (i = 0; i < rdev->scratch.num_reg; i++) {
if (rdev->scratch.free[i]) {
rdev->scratch.free[i] = false;
*reg = rdev->scratch.reg[i];
return 0;
}
}
return -EINVAL;
}
void radeon_scratch_free(struct radeon_device *rdev, uint32_t reg)
{
int i;
for (i = 0; i < rdev->scratch.num_reg; i++) {
if (rdev->scratch.reg[i] == reg) {
rdev->scratch.free[i] = true;
return;
}
}
}
void radeon_wb_disable(struct radeon_device *rdev)
{
int r;
if (rdev->wb.wb_obj) {
r = radeon_bo_reserve(rdev->wb.wb_obj, false);
if (unlikely(r != 0))
return;
radeon_bo_kunmap(rdev->wb.wb_obj);
radeon_bo_unpin(rdev->wb.wb_obj);
radeon_bo_unreserve(rdev->wb.wb_obj);
}
rdev->wb.enabled = false;
}
void radeon_wb_fini(struct radeon_device *rdev)
{
radeon_wb_disable(rdev);
if (rdev->wb.wb_obj) {
radeon_bo_unref(&rdev->wb.wb_obj);
rdev->wb.wb = NULL;
rdev->wb.wb_obj = NULL;
}
}
int radeon_wb_init(struct radeon_device *rdev)
{
int r;
if (rdev->wb.wb_obj == NULL) {
r = radeon_bo_create(rdev, RADEON_GPU_PAGE_SIZE, PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT, NULL, &rdev->wb.wb_obj);
if (r) {
dev_warn(rdev->dev, "(%d) create WB bo failed\n", r);
return r;
}
}
r = radeon_bo_reserve(rdev->wb.wb_obj, false);
if (unlikely(r != 0)) {
radeon_wb_fini(rdev);
return r;
}
r = radeon_bo_pin(rdev->wb.wb_obj, RADEON_GEM_DOMAIN_GTT,
&rdev->wb.gpu_addr);
if (r) {
radeon_bo_unreserve(rdev->wb.wb_obj);
dev_warn(rdev->dev, "(%d) pin WB bo failed\n", r);
radeon_wb_fini(rdev);
return r;
}
r = radeon_bo_kmap(rdev->wb.wb_obj, (void **)&rdev->wb.wb);
radeon_bo_unreserve(rdev->wb.wb_obj);
if (r) {
dev_warn(rdev->dev, "(%d) map WB bo failed\n", r);
radeon_wb_fini(rdev);
return r;
}
memset((char *)rdev->wb.wb, 0, RADEON_GPU_PAGE_SIZE);
rdev->wb.use_event = false;
if (radeon_no_wb == 1) {
rdev->wb.enabled = false;
} else {
if (rdev->flags & RADEON_IS_AGP) {
rdev->wb.enabled = false;
} else if (rdev->family < CHIP_R300) {
rdev->wb.enabled = false;
} else {
rdev->wb.enabled = true;
if (rdev->family >= CHIP_R600) {
rdev->wb.use_event = true;
}
}
}
if (rdev->family >= CHIP_PALM) {
rdev->wb.enabled = true;
rdev->wb.use_event = true;
}
dev_info(rdev->dev, "WB %sabled\n", rdev->wb.enabled ? "en" : "dis");
return 0;
}
void radeon_vram_location(struct radeon_device *rdev, struct radeon_mc *mc, u64 base)
{
uint64_t limit = (uint64_t)radeon_vram_limit << 20;
mc->vram_start = base;
if (mc->mc_vram_size > (0xFFFFFFFF - base + 1)) {
dev_warn(rdev->dev, "limiting VRAM to PCI aperture size\n");
mc->real_vram_size = mc->aper_size;
mc->mc_vram_size = mc->aper_size;
}
mc->vram_end = mc->vram_start + mc->mc_vram_size - 1;
if (rdev->flags & RADEON_IS_AGP && mc->vram_end > mc->gtt_start && mc->vram_start <= mc->gtt_end) {
dev_warn(rdev->dev, "limiting VRAM to PCI aperture size\n");
mc->real_vram_size = mc->aper_size;
mc->mc_vram_size = mc->aper_size;
}
mc->vram_end = mc->vram_start + mc->mc_vram_size - 1;
if (limit && limit < mc->real_vram_size)
mc->real_vram_size = limit;
dev_info(rdev->dev, "VRAM: %lluM 0x%016llX - 0x%016llX (%lluM used)\n",
mc->mc_vram_size >> 20, mc->vram_start,
mc->vram_end, mc->real_vram_size >> 20);
}
void radeon_gtt_location(struct radeon_device *rdev, struct radeon_mc *mc)
{
u64 size_af, size_bf;
size_af = ((0xFFFFFFFF - mc->vram_end) + mc->gtt_base_align) & ~mc->gtt_base_align;
size_bf = mc->vram_start & ~mc->gtt_base_align;
if (size_bf > size_af) {
if (mc->gtt_size > size_bf) {
dev_warn(rdev->dev, "limiting GTT\n");
mc->gtt_size = size_bf;
}
mc->gtt_start = (mc->vram_start & ~mc->gtt_base_align) - mc->gtt_size;
} else {
if (mc->gtt_size > size_af) {
dev_warn(rdev->dev, "limiting GTT\n");
mc->gtt_size = size_af;
}
mc->gtt_start = (mc->vram_end + 1 + mc->gtt_base_align) & ~mc->gtt_base_align;
}
mc->gtt_end = mc->gtt_start + mc->gtt_size - 1;
dev_info(rdev->dev, "GTT: %lluM 0x%016llX - 0x%016llX\n",
mc->gtt_size >> 20, mc->gtt_start, mc->gtt_end);
}
bool radeon_card_posted(struct radeon_device *rdev)
{
uint32_t reg;
if (efi_enabled(EFI_BOOT) &&
rdev->pdev->subsystem_vendor == PCI_VENDOR_ID_APPLE)
return false;
if (ASIC_IS_DCE41(rdev)) {
reg = RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC0_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC1_REGISTER_OFFSET);
if (reg & EVERGREEN_CRTC_MASTER_EN)
return true;
} else if (ASIC_IS_DCE4(rdev)) {
reg = RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC0_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC1_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC2_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC3_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC4_REGISTER_OFFSET) |
RREG32(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC5_REGISTER_OFFSET);
if (reg & EVERGREEN_CRTC_MASTER_EN)
return true;
} else if (ASIC_IS_AVIVO(rdev)) {
reg = RREG32(AVIVO_D1CRTC_CONTROL) |
RREG32(AVIVO_D2CRTC_CONTROL);
if (reg & AVIVO_CRTC_EN) {
return true;
}
} else {
reg = RREG32(RADEON_CRTC_GEN_CNTL) |
RREG32(RADEON_CRTC2_GEN_CNTL);
if (reg & RADEON_CRTC_EN) {
return true;
}
}
if (rdev->family >= CHIP_R600)
reg = RREG32(R600_CONFIG_MEMSIZE);
else
reg = RREG32(RADEON_CONFIG_MEMSIZE);
if (reg)
return true;
return false;
}
void radeon_update_bandwidth_info(struct radeon_device *rdev)
{
fixed20_12 a;
u32 sclk = rdev->pm.current_sclk;
u32 mclk = rdev->pm.current_mclk;
a.full = dfixed_const(100);
rdev->pm.sclk.full = dfixed_const(sclk);
rdev->pm.sclk.full = dfixed_div(rdev->pm.sclk, a);
rdev->pm.mclk.full = dfixed_const(mclk);
rdev->pm.mclk.full = dfixed_div(rdev->pm.mclk, a);
if (rdev->flags & RADEON_IS_IGP) {
a.full = dfixed_const(16);
rdev->pm.core_bandwidth.full = dfixed_div(rdev->pm.sclk, a);
}
}
bool radeon_boot_test_post_card(struct radeon_device *rdev)
{
if (radeon_card_posted(rdev))
return true;
if (rdev->bios) {
DRM_INFO("GPU not posted. posting now...\n");
if (rdev->is_atom_bios)
atom_asic_init(rdev->mode_info.atom_context);
else
radeon_combios_asic_init(rdev->ddev);
return true;
} else {
dev_err(rdev->dev, "Card not posted and no BIOS - ignoring\n");
return false;
}
}
int radeon_dummy_page_init(struct radeon_device *rdev)
{
if (rdev->dummy_page.page)
return 0;
rdev->dummy_page.page = alloc_page(GFP_DMA32 | GFP_KERNEL | __GFP_ZERO);
if (rdev->dummy_page.page == NULL)
return -ENOMEM;
rdev->dummy_page.addr = pci_map_page(rdev->pdev, rdev->dummy_page.page,
0, PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(rdev->pdev, rdev->dummy_page.addr)) {
dev_err(&rdev->pdev->dev, "Failed to DMA MAP the dummy page\n");
__free_page(rdev->dummy_page.page);
rdev->dummy_page.page = NULL;
return -ENOMEM;
}
return 0;
}
void radeon_dummy_page_fini(struct radeon_device *rdev)
{
if (rdev->dummy_page.page == NULL)
return;
pci_unmap_page(rdev->pdev, rdev->dummy_page.addr,
PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
__free_page(rdev->dummy_page.page);
rdev->dummy_page.page = NULL;
}
static uint32_t cail_pll_read(struct card_info *info, uint32_t reg)
{
struct radeon_device *rdev = info->dev->dev_private;
uint32_t r;
r = rdev->pll_rreg(rdev, reg);
return r;
}
static void cail_pll_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct radeon_device *rdev = info->dev->dev_private;
rdev->pll_wreg(rdev, reg, val);
}
static uint32_t cail_mc_read(struct card_info *info, uint32_t reg)
{
struct radeon_device *rdev = info->dev->dev_private;
uint32_t r;
r = rdev->mc_rreg(rdev, reg);
return r;
}
static void cail_mc_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct radeon_device *rdev = info->dev->dev_private;
rdev->mc_wreg(rdev, reg, val);
}
static void cail_reg_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct radeon_device *rdev = info->dev->dev_private;
WREG32(reg*4, val);
}
static uint32_t cail_reg_read(struct card_info *info, uint32_t reg)
{
struct radeon_device *rdev = info->dev->dev_private;
uint32_t r;
r = RREG32(reg*4);
return r;
}
static void cail_ioreg_write(struct card_info *info, uint32_t reg, uint32_t val)
{
struct radeon_device *rdev = info->dev->dev_private;
WREG32_IO(reg*4, val);
}
static uint32_t cail_ioreg_read(struct card_info *info, uint32_t reg)
{
struct radeon_device *rdev = info->dev->dev_private;
uint32_t r;
r = RREG32_IO(reg*4);
return r;
}
int radeon_atombios_init(struct radeon_device *rdev)
{
struct card_info *atom_card_info =
kzalloc(sizeof(struct card_info), GFP_KERNEL);
if (!atom_card_info)
return -ENOMEM;
rdev->mode_info.atom_card_info = atom_card_info;
atom_card_info->dev = rdev->ddev;
atom_card_info->reg_read = cail_reg_read;
atom_card_info->reg_write = cail_reg_write;
if (rdev->rio_mem) {
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
rdev->mode_info.atom_context = atom_parse(atom_card_info, rdev->bios);
mutex_init(&rdev->mode_info.atom_context->mutex);
radeon_atom_initialize_bios_scratch_regs(rdev->ddev);
atom_allocate_fb_scratch(rdev->mode_info.atom_context);
return 0;
}
void radeon_atombios_fini(struct radeon_device *rdev)
{
if (rdev->mode_info.atom_context) {
kfree(rdev->mode_info.atom_context->scratch);
kfree(rdev->mode_info.atom_context);
}
kfree(rdev->mode_info.atom_card_info);
}
int radeon_combios_init(struct radeon_device *rdev)
{
radeon_combios_initialize_bios_scratch_regs(rdev->ddev);
return 0;
}
void radeon_combios_fini(struct radeon_device *rdev)
{
}
static unsigned int radeon_vga_set_decode(void *cookie, bool state)
{
struct radeon_device *rdev = cookie;
radeon_vga_set_state(rdev, state);
if (state)
return VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM |
VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
else
return VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
}
static bool radeon_check_pot_argument(int arg)
{
return (arg & (arg - 1)) == 0;
}
static void radeon_check_arguments(struct radeon_device *rdev)
{
if (!radeon_check_pot_argument(radeon_vram_limit)) {
dev_warn(rdev->dev, "vram limit (%d) must be a power of 2\n",
radeon_vram_limit);
radeon_vram_limit = 0;
}
if (radeon_gart_size < 32) {
dev_warn(rdev->dev, "gart size (%d) too small forcing to 512M\n",
radeon_gart_size);
radeon_gart_size = 512;
} else if (!radeon_check_pot_argument(radeon_gart_size)) {
dev_warn(rdev->dev, "gart size (%d) must be a power of 2\n",
radeon_gart_size);
radeon_gart_size = 512;
}
rdev->mc.gtt_size = (uint64_t)radeon_gart_size << 20;
switch (radeon_agpmode) {
case -1:
case 0:
case 1:
case 2:
case 4:
case 8:
break;
default:
dev_warn(rdev->dev, "invalid AGP mode %d (valid mode: "
"-1, 0, 1, 2, 4, 8)\n", radeon_agpmode);
radeon_agpmode = 0;
break;
}
}
static bool radeon_switcheroo_quirk_long_wakeup(struct pci_dev *pdev)
{
if (pdev->subsystem_vendor == PCI_VENDOR_ID_APPLE &&
pdev->subsystem_device == 0x00e2) {
printk(KERN_INFO "radeon: quirking longer d3 wakeup delay\n");
return true;
}
return false;
}
static void radeon_switcheroo_set_state(struct pci_dev *pdev, enum vga_switcheroo_state state)
{
struct drm_device *dev = pci_get_drvdata(pdev);
pm_message_t pmm = { .event = PM_EVENT_SUSPEND };
if (state == VGA_SWITCHEROO_ON) {
unsigned d3_delay = dev->pdev->d3_delay;
printk(KERN_INFO "radeon: switched on\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
if (d3_delay < 20 && radeon_switcheroo_quirk_long_wakeup(pdev))
dev->pdev->d3_delay = 20;
radeon_resume_kms(dev);
dev->pdev->d3_delay = d3_delay;
dev->switch_power_state = DRM_SWITCH_POWER_ON;
drm_kms_helper_poll_enable(dev);
} else {
printk(KERN_INFO "radeon: switched off\n");
drm_kms_helper_poll_disable(dev);
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
radeon_suspend_kms(dev, pmm);
dev->switch_power_state = DRM_SWITCH_POWER_OFF;
}
}
static bool radeon_switcheroo_can_switch(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
bool can_switch;
spin_lock(&dev->count_lock);
can_switch = (dev->open_count == 0);
spin_unlock(&dev->count_lock);
return can_switch;
}
int radeon_device_init(struct radeon_device *rdev,
struct drm_device *ddev,
struct pci_dev *pdev,
uint32_t flags)
{
int r, i;
int dma_bits;
rdev->shutdown = false;
rdev->dev = &pdev->dev;
rdev->ddev = ddev;
rdev->pdev = pdev;
rdev->flags = flags;
rdev->family = flags & RADEON_FAMILY_MASK;
rdev->is_atom_bios = false;
rdev->usec_timeout = RADEON_MAX_USEC_TIMEOUT;
rdev->mc.gtt_size = radeon_gart_size * 1024 * 1024;
rdev->accel_working = false;
for (i = 0; i < RADEON_NUM_RINGS; i++) {
rdev->ring[i].idx = i;
}
DRM_INFO("initializing kernel modesetting (%s 0x%04X:0x%04X 0x%04X:0x%04X).\n",
radeon_family_name[rdev->family], pdev->vendor, pdev->device,
pdev->subsystem_vendor, pdev->subsystem_device);
mutex_init(&rdev->ring_lock);
mutex_init(&rdev->dc_hw_i2c_mutex);
atomic_set(&rdev->ih.lock, 0);
mutex_init(&rdev->gem.mutex);
mutex_init(&rdev->pm.mutex);
mutex_init(&rdev->gpu_clock_mutex);
init_rwsem(&rdev->pm.mclk_lock);
init_rwsem(&rdev->exclusive_lock);
init_waitqueue_head(&rdev->irq.vblank_queue);
r = radeon_gem_init(rdev);
if (r)
return r;
mutex_init(&rdev->vm_manager.lock);
rdev->vm_manager.max_pfn = 1 << 20;
INIT_LIST_HEAD(&rdev->vm_manager.lru_vm);
r = radeon_asic_init(rdev);
if (r)
return r;
radeon_check_arguments(rdev);
if ((rdev->family >= CHIP_RS400) &&
(rdev->flags & RADEON_IS_IGP)) {
rdev->flags &= ~RADEON_IS_AGP;
}
if (rdev->flags & RADEON_IS_AGP && radeon_agpmode == -1) {
radeon_agp_disable(rdev);
}
rdev->need_dma32 = false;
if (rdev->flags & RADEON_IS_AGP)
rdev->need_dma32 = true;
if ((rdev->flags & RADEON_IS_PCI) &&
(rdev->family <= CHIP_RS740))
rdev->need_dma32 = true;
dma_bits = rdev->need_dma32 ? 32 : 40;
r = pci_set_dma_mask(rdev->pdev, DMA_BIT_MASK(dma_bits));
if (r) {
rdev->need_dma32 = true;
dma_bits = 32;
printk(KERN_WARNING "radeon: No suitable DMA available.\n");
}
r = pci_set_consistent_dma_mask(rdev->pdev, DMA_BIT_MASK(dma_bits));
if (r) {
pci_set_consistent_dma_mask(rdev->pdev, DMA_BIT_MASK(32));
printk(KERN_WARNING "radeon: No coherent DMA available.\n");
}
spin_lock_init(&rdev->mmio_idx_lock);
rdev->rmmio_base = pci_resource_start(rdev->pdev, 2);
rdev->rmmio_size = pci_resource_len(rdev->pdev, 2);
rdev->rmmio = ioremap(rdev->rmmio_base, rdev->rmmio_size);
if (rdev->rmmio == NULL) {
return -ENOMEM;
}
DRM_INFO("register mmio base: 0x%08X\n", (uint32_t)rdev->rmmio_base);
DRM_INFO("register mmio size: %u\n", (unsigned)rdev->rmmio_size);
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
if (pci_resource_flags(rdev->pdev, i) & IORESOURCE_IO) {
rdev->rio_mem_size = pci_resource_len(rdev->pdev, i);
rdev->rio_mem = pci_iomap(rdev->pdev, i, rdev->rio_mem_size);
break;
}
}
if (rdev->rio_mem == NULL)
DRM_ERROR("Unable to find PCI I/O BAR\n");
vga_client_register(rdev->pdev, rdev, NULL, radeon_vga_set_decode);
vga_switcheroo_register_client(rdev->pdev, &radeon_switcheroo_ops);
r = radeon_init(rdev);
if (r)
return r;
r = radeon_ib_ring_tests(rdev);
if (r)
DRM_ERROR("ib ring test failed (%d).\n", r);
if (rdev->flags & RADEON_IS_AGP && !rdev->accel_working) {
radeon_asic_reset(rdev);
radeon_fini(rdev);
radeon_agp_disable(rdev);
r = radeon_init(rdev);
if (r)
return r;
}
if ((radeon_testing & 1)) {
radeon_test_moves(rdev);
}
if ((radeon_testing & 2)) {
radeon_test_syncing(rdev);
}
if (radeon_benchmarking) {
radeon_benchmark(rdev, radeon_benchmarking);
}
return 0;
}
void radeon_device_fini(struct radeon_device *rdev)
{
DRM_INFO("radeon: finishing device.\n");
rdev->shutdown = true;
radeon_bo_evict_vram(rdev);
radeon_fini(rdev);
vga_switcheroo_unregister_client(rdev->pdev);
vga_client_register(rdev->pdev, NULL, NULL, NULL);
if (rdev->rio_mem)
pci_iounmap(rdev->pdev, rdev->rio_mem);
rdev->rio_mem = NULL;
iounmap(rdev->rmmio);
rdev->rmmio = NULL;
radeon_debugfs_remove_files(rdev);
}
int radeon_suspend_kms(struct drm_device *dev, pm_message_t state)
{
struct radeon_device *rdev;
struct drm_crtc *crtc;
struct drm_connector *connector;
int i, r;
bool force_completion = false;
if (dev == NULL || dev->dev_private == NULL) {
return -ENODEV;
}
if (state.event == PM_EVENT_PRETHAW) {
return 0;
}
rdev = dev->dev_private;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
drm_kms_helper_poll_disable(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct radeon_framebuffer *rfb = to_radeon_framebuffer(crtc->fb);
struct radeon_bo *robj;
if (rfb == NULL || rfb->obj == NULL) {
continue;
}
robj = gem_to_radeon_bo(rfb->obj);
if (!radeon_fbdev_robj_is_fb(rdev, robj)) {
r = radeon_bo_reserve(robj, false);
if (r == 0) {
radeon_bo_unpin(robj);
radeon_bo_unreserve(robj);
}
}
}
radeon_bo_evict_vram(rdev);
mutex_lock(&rdev->ring_lock);
for (i = 0; i < RADEON_NUM_RINGS; i++) {
r = radeon_fence_wait_empty_locked(rdev, i);
if (r) {
force_completion = true;
}
}
if (force_completion) {
radeon_fence_driver_force_completion(rdev);
}
mutex_unlock(&rdev->ring_lock);
radeon_save_bios_scratch_regs(rdev);
radeon_pm_suspend(rdev);
radeon_suspend(rdev);
radeon_hpd_fini(rdev);
radeon_bo_evict_vram(rdev);
radeon_agp_suspend(rdev);
pci_save_state(dev->pdev);
if (state.event == PM_EVENT_SUSPEND) {
pci_disable_device(dev->pdev);
pci_set_power_state(dev->pdev, PCI_D3hot);
}
console_lock();
radeon_fbdev_set_suspend(rdev, 1);
console_unlock();
return 0;
}
int radeon_resume_kms(struct drm_device *dev)
{
struct drm_connector *connector;
struct radeon_device *rdev = dev->dev_private;
int r;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
console_lock();
pci_set_power_state(dev->pdev, PCI_D0);
pci_restore_state(dev->pdev);
if (pci_enable_device(dev->pdev)) {
console_unlock();
return -1;
}
radeon_agp_resume(rdev);
radeon_resume(rdev);
r = radeon_ib_ring_tests(rdev);
if (r)
DRM_ERROR("ib ring test failed (%d).\n", r);
radeon_pm_resume(rdev);
radeon_restore_bios_scratch_regs(rdev);
radeon_fbdev_set_suspend(rdev, 0);
console_unlock();
if (rdev->is_atom_bios) {
radeon_atom_encoder_init(rdev);
radeon_atom_disp_eng_pll_init(rdev);
if (rdev->mode_info.bl_encoder) {
u8 bl_level = radeon_get_backlight_level(rdev,
rdev->mode_info.bl_encoder);
radeon_set_backlight_level(rdev, rdev->mode_info.bl_encoder,
bl_level);
}
}
radeon_hpd_init(rdev);
drm_helper_resume_force_mode(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_ON);
}
drm_kms_helper_poll_enable(dev);
return 0;
}
int radeon_gpu_reset(struct radeon_device *rdev)
{
unsigned ring_sizes[RADEON_NUM_RINGS];
uint32_t *ring_data[RADEON_NUM_RINGS];
bool saved = false;
int i, r;
int resched;
down_write(&rdev->exclusive_lock);
radeon_save_bios_scratch_regs(rdev);
resched = ttm_bo_lock_delayed_workqueue(&rdev->mman.bdev);
radeon_suspend(rdev);
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
ring_sizes[i] = radeon_ring_backup(rdev, &rdev->ring[i],
&ring_data[i]);
if (ring_sizes[i]) {
saved = true;
dev_info(rdev->dev, "Saved %d dwords of commands "
"on ring %d.\n", ring_sizes[i], i);
}
}
retry:
r = radeon_asic_reset(rdev);
if (!r) {
dev_info(rdev->dev, "GPU reset succeeded, trying to resume\n");
radeon_resume(rdev);
}
radeon_restore_bios_scratch_regs(rdev);
if (!r) {
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
radeon_ring_restore(rdev, &rdev->ring[i],
ring_sizes[i], ring_data[i]);
ring_sizes[i] = 0;
ring_data[i] = NULL;
}
r = radeon_ib_ring_tests(rdev);
if (r) {
dev_err(rdev->dev, "ib ring test failed (%d).\n", r);
if (saved) {
saved = false;
radeon_suspend(rdev);
goto retry;
}
}
} else {
radeon_fence_driver_force_completion(rdev);
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
kfree(ring_data[i]);
}
}
drm_helper_resume_force_mode(rdev->ddev);
ttm_bo_unlock_delayed_workqueue(&rdev->mman.bdev, resched);
if (r) {
dev_info(rdev->dev, "GPU reset failed\n");
}
up_write(&rdev->exclusive_lock);
return r;
}
int radeon_debugfs_add_files(struct radeon_device *rdev,
struct drm_info_list *files,
unsigned nfiles)
{
unsigned i;
for (i = 0; i < rdev->debugfs_count; i++) {
if (rdev->debugfs[i].files == files) {
return 0;
}
}
i = rdev->debugfs_count + 1;
if (i > RADEON_DEBUGFS_MAX_COMPONENTS) {
DRM_ERROR("Reached maximum number of debugfs components.\n");
DRM_ERROR("Report so we increase "
"RADEON_DEBUGFS_MAX_COMPONENTS.\n");
return -EINVAL;
}
rdev->debugfs[rdev->debugfs_count].files = files;
rdev->debugfs[rdev->debugfs_count].num_files = nfiles;
rdev->debugfs_count = i;
#if defined(CONFIG_DEBUG_FS)
drm_debugfs_create_files(files, nfiles,
rdev->ddev->control->debugfs_root,
rdev->ddev->control);
drm_debugfs_create_files(files, nfiles,
rdev->ddev->primary->debugfs_root,
rdev->ddev->primary);
#endif
return 0;
}
static void radeon_debugfs_remove_files(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
unsigned i;
for (i = 0; i < rdev->debugfs_count; i++) {
drm_debugfs_remove_files(rdev->debugfs[i].files,
rdev->debugfs[i].num_files,
rdev->ddev->control);
drm_debugfs_remove_files(rdev->debugfs[i].files,
rdev->debugfs[i].num_files,
rdev->ddev->primary);
}
#endif
}
int radeon_debugfs_init(struct drm_minor *minor)
{
return 0;
}
void radeon_debugfs_cleanup(struct drm_minor *minor)
{
}
