static void
nv10_mem_update_tile_region(struct drm_device *dev,
struct nouveau_tile_reg *tile, uint32_t addr,
uint32_t size, uint32_t pitch, uint32_t flags)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
int i = tile - dev_priv->tile.reg, j;
unsigned long save;
nouveau_fence_unref(&tile->fence);
if (tile->pitch)
pfb->free_tile_region(dev, i);
if (pitch)
pfb->init_tile_region(dev, i, addr, size, pitch, flags);
spin_lock_irqsave(&dev_priv->context_switch_lock, save);
pfifo->reassign(dev, false);
pfifo->cache_pull(dev, false);
nouveau_wait_for_idle(dev);
pfb->set_tile_region(dev, i);
for (j = 0; j < NVOBJ_ENGINE_NR; j++) {
if (dev_priv->eng[j] && dev_priv->eng[j]->set_tile_region)
dev_priv->eng[j]->set_tile_region(dev, i);
}
pfifo->cache_pull(dev, true);
pfifo->reassign(dev, true);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, save);
}
static struct nouveau_tile_reg *
nv10_mem_get_tile_region(struct drm_device *dev, int i)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_tile_reg *tile = &dev_priv->tile.reg[i];
spin_lock(&dev_priv->tile.lock);
if (!tile->used &&
(!tile->fence || nouveau_fence_signalled(tile->fence)))
tile->used = true;
else
tile = NULL;
spin_unlock(&dev_priv->tile.lock);
return tile;
}
void
nv10_mem_put_tile_region(struct drm_device *dev, struct nouveau_tile_reg *tile,
struct nouveau_fence *fence)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (tile) {
spin_lock(&dev_priv->tile.lock);
if (fence) {
tile->fence = fence;
nouveau_fence_ref(fence);
}
tile->used = false;
spin_unlock(&dev_priv->tile.lock);
}
}
struct nouveau_tile_reg *
nv10_mem_set_tiling(struct drm_device *dev, uint32_t addr, uint32_t size,
uint32_t pitch, uint32_t flags)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
struct nouveau_tile_reg *tile, *found = NULL;
int i;
for (i = 0; i < pfb->num_tiles; i++) {
tile = nv10_mem_get_tile_region(dev, i);
if (pitch && !found) {
found = tile;
continue;
} else if (tile && tile->pitch) {
nv10_mem_update_tile_region(dev, tile, 0, 0, 0, 0);
}
nv10_mem_put_tile_region(dev, tile, NULL);
}
if (found)
nv10_mem_update_tile_region(dev, found, addr, size,
pitch, flags);
return found;
}
void
nouveau_mem_vram_fini(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
ttm_bo_device_release(&dev_priv->ttm.bdev);
nouveau_ttm_global_release(dev_priv);
if (dev_priv->fb_mtrr >= 0) {
drm_mtrr_del(dev_priv->fb_mtrr,
pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1), DRM_MTRR_WC);
dev_priv->fb_mtrr = -1;
}
}
void
nouveau_mem_gart_fini(struct drm_device *dev)
{
nouveau_sgdma_takedown(dev);
if (drm_core_has_AGP(dev) && dev->agp) {
struct drm_agp_mem *entry, *tempe;
list_for_each_entry_safe(entry, tempe, &dev->agp->memory, head) {
if (entry->bound)
drm_unbind_agp(entry->memory);
drm_free_agp(entry->memory, entry->pages);
kfree(entry);
}
INIT_LIST_HEAD(&dev->agp->memory);
if (dev->agp->acquired)
drm_agp_release(dev);
dev->agp->acquired = 0;
dev->agp->enabled = 0;
}
}
static uint32_t
nouveau_mem_detect_nv04(struct drm_device *dev)
{
uint32_t boot0 = nv_rd32(dev, NV04_PFB_BOOT_0);
if (boot0 & 0x00000100)
return (((boot0 >> 12) & 0xf) * 2 + 2) * 1024 * 1024;
switch (boot0 & NV04_PFB_BOOT_0_RAM_AMOUNT) {
case NV04_PFB_BOOT_0_RAM_AMOUNT_32MB:
return 32 * 1024 * 1024;
case NV04_PFB_BOOT_0_RAM_AMOUNT_16MB:
return 16 * 1024 * 1024;
case NV04_PFB_BOOT_0_RAM_AMOUNT_8MB:
return 8 * 1024 * 1024;
case NV04_PFB_BOOT_0_RAM_AMOUNT_4MB:
return 4 * 1024 * 1024;
}
return 0;
}
static uint32_t
nouveau_mem_detect_nforce(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct pci_dev *bridge;
uint32_t mem;
bridge = pci_get_bus_and_slot(0, PCI_DEVFN(0, 1));
if (!bridge) {
NV_ERROR(dev, "no bridge device\n");
return 0;
}
if (dev_priv->flags & NV_NFORCE) {
pci_read_config_dword(bridge, 0x7C, &mem);
return (uint64_t)(((mem >> 6) & 31) + 1)*1024*1024;
} else
if (dev_priv->flags & NV_NFORCE2) {
pci_read_config_dword(bridge, 0x84, &mem);
return (uint64_t)(((mem >> 4) & 127) + 1)*1024*1024;
}
NV_ERROR(dev, "impossible!\n");
return 0;
}
int
nouveau_mem_detect(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (dev_priv->card_type == NV_04) {
dev_priv->vram_size = nouveau_mem_detect_nv04(dev);
} else
if (dev_priv->flags & (NV_NFORCE | NV_NFORCE2)) {
dev_priv->vram_size = nouveau_mem_detect_nforce(dev);
} else
if (dev_priv->card_type < NV_50) {
dev_priv->vram_size = nv_rd32(dev, NV04_PFB_FIFO_DATA);
dev_priv->vram_size &= NV10_PFB_FIFO_DATA_RAM_AMOUNT_MB_MASK;
}
if (dev_priv->vram_size)
return 0;
return -ENOMEM;
}
bool
nouveau_mem_flags_valid(struct drm_device *dev, u32 tile_flags)
{
if (!(tile_flags & NOUVEAU_GEM_TILE_LAYOUT_MASK))
return true;
return false;
}
static unsigned long
get_agp_mode(struct drm_device *dev, unsigned long mode)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (dev_priv->chipset == 0x18)
mode &= ~PCI_AGP_COMMAND_FW;
if (nouveau_agpmode > 0) {
bool agpv3 = mode & 0x8;
int rate = agpv3 ? nouveau_agpmode / 4 : nouveau_agpmode;
mode = (mode & ~0x7) | (rate & 0x7);
}
return mode;
}
int
nouveau_mem_reset_agp(struct drm_device *dev)
{
#if __OS_HAS_AGP
uint32_t saved_pci_nv_1, pmc_enable;
int ret;
if ((nv_rd32(dev, NV04_PBUS_PCI_NV_19) |
dev->agp->mode) & PCI_AGP_COMMAND_FW) {
struct drm_agp_info info;
struct drm_agp_mode mode;
ret = drm_agp_info(dev, &info);
if (ret)
return ret;
mode.mode = get_agp_mode(dev, info.mode) & ~PCI_AGP_COMMAND_FW;
ret = drm_agp_enable(dev, mode);
if (ret)
return ret;
}
saved_pci_nv_1 = nv_rd32(dev, NV04_PBUS_PCI_NV_1);
nv_wr32(dev, NV04_PBUS_PCI_NV_1, saved_pci_nv_1 & ~0x4);
nv_wr32(dev, NV04_PBUS_PCI_NV_19, 0);
pmc_enable = nv_rd32(dev, NV03_PMC_ENABLE);
if (pmc_enable & NV_PMC_ENABLE_PGRAPH) {
nv_wr32(dev, NV03_PMC_ENABLE,
pmc_enable & ~NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) |
NV_PMC_ENABLE_PGRAPH);
}
nv_wr32(dev, NV04_PBUS_PCI_NV_1, saved_pci_nv_1);
#endif
return 0;
}
int
nouveau_mem_init_agp(struct drm_device *dev)
{
#if __OS_HAS_AGP
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_agp_info info;
struct drm_agp_mode mode;
int ret;
if (!dev->agp->acquired) {
ret = drm_agp_acquire(dev);
if (ret) {
NV_ERROR(dev, "Unable to acquire AGP: %d\n", ret);
return ret;
}
}
nouveau_mem_reset_agp(dev);
ret = drm_agp_info(dev, &info);
if (ret) {
NV_ERROR(dev, "Unable to get AGP info: %d\n", ret);
return ret;
}
mode.mode = get_agp_mode(dev, info.mode);
ret = drm_agp_enable(dev, mode);
if (ret) {
NV_ERROR(dev, "Unable to enable AGP: %d\n", ret);
return ret;
}
dev_priv->gart_info.type = NOUVEAU_GART_AGP;
dev_priv->gart_info.aper_base = info.aperture_base;
dev_priv->gart_info.aper_size = info.aperture_size;
#endif
return 0;
}
int
nouveau_mem_vram_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct ttm_bo_device *bdev = &dev_priv->ttm.bdev;
int ret, dma_bits;
dma_bits = 32;
if (dev_priv->card_type >= NV_50) {
if (pci_dma_supported(dev->pdev, DMA_BIT_MASK(40)))
dma_bits = 40;
} else
if (0 && pci_is_pcie(dev->pdev) &&
dev_priv->chipset > 0x40 &&
dev_priv->chipset != 0x45) {
if (pci_dma_supported(dev->pdev, DMA_BIT_MASK(39)))
dma_bits = 39;
}
ret = pci_set_dma_mask(dev->pdev, DMA_BIT_MASK(dma_bits));
if (ret)
return ret;
dev_priv->fb_phys = pci_resource_start(dev->pdev, 1);
ret = nouveau_ttm_global_init(dev_priv);
if (ret)
return ret;
ret = ttm_bo_device_init(&dev_priv->ttm.bdev,
dev_priv->ttm.bo_global_ref.ref.object,
&nouveau_bo_driver, DRM_FILE_PAGE_OFFSET,
dma_bits <= 32 ? true : false);
if (ret) {
NV_ERROR(dev, "Error initialising bo driver: %d\n", ret);
return ret;
}
NV_INFO(dev, "Detected %dMiB VRAM\n", (int)(dev_priv->vram_size >> 20));
if (dev_priv->vram_sys_base) {
NV_INFO(dev, "Stolen system memory at: 0x%010llx\n",
dev_priv->vram_sys_base);
}
dev_priv->fb_available_size = dev_priv->vram_size;
dev_priv->fb_mappable_pages = dev_priv->fb_available_size;
if (dev_priv->fb_mappable_pages > pci_resource_len(dev->pdev, 1))
dev_priv->fb_mappable_pages = pci_resource_len(dev->pdev, 1);
dev_priv->fb_mappable_pages >>= PAGE_SHIFT;
dev_priv->fb_available_size -= dev_priv->ramin_rsvd_vram;
dev_priv->fb_aper_free = dev_priv->fb_available_size;
ret = ttm_bo_init_mm(bdev, TTM_PL_VRAM,
dev_priv->fb_available_size >> PAGE_SHIFT);
if (ret) {
NV_ERROR(dev, "Failed VRAM mm init: %d\n", ret);
return ret;
}
if (dev_priv->card_type < NV_50) {
ret = nouveau_bo_new(dev, 256*1024, 0, TTM_PL_FLAG_VRAM,
0, 0, &dev_priv->vga_ram);
if (ret == 0)
ret = nouveau_bo_pin(dev_priv->vga_ram,
TTM_PL_FLAG_VRAM);
if (ret) {
NV_WARN(dev, "failed to reserve VGA memory\n");
nouveau_bo_ref(NULL, &dev_priv->vga_ram);
}
}
dev_priv->fb_mtrr = drm_mtrr_add(pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1),
DRM_MTRR_WC);
return 0;
}
int
nouveau_mem_gart_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct ttm_bo_device *bdev = &dev_priv->ttm.bdev;
int ret;
dev_priv->gart_info.type = NOUVEAU_GART_NONE;
#if !defined(__powerpc__) && !defined(__ia64__)
if (drm_pci_device_is_agp(dev) && dev->agp && nouveau_agpmode) {
ret = nouveau_mem_init_agp(dev);
if (ret)
NV_ERROR(dev, "Error initialising AGP: %d\n", ret);
}
#endif
if (dev_priv->gart_info.type == NOUVEAU_GART_NONE) {
ret = nouveau_sgdma_init(dev);
if (ret) {
NV_ERROR(dev, "Error initialising PCI(E): %d\n", ret);
return ret;
}
}
NV_INFO(dev, "%d MiB GART (aperture)\n",
(int)(dev_priv->gart_info.aper_size >> 20));
dev_priv->gart_info.aper_free = dev_priv->gart_info.aper_size;
ret = ttm_bo_init_mm(bdev, TTM_PL_TT,
dev_priv->gart_info.aper_size >> PAGE_SHIFT);
if (ret) {
NV_ERROR(dev, "Failed TT mm init: %d\n", ret);
return ret;
}
return 0;
}
void
nouveau_mem_timing_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_engine *pm = &dev_priv->engine.pm;
struct nouveau_pm_memtimings *memtimings = &pm->memtimings;
struct nvbios *bios = &dev_priv->vbios;
struct bit_entry P;
u8 tUNK_0, tUNK_1, tUNK_2;
u8 tRP;
u8 tRAS;
u8 tRFC;
u8 tRC;
u8 tUNK_10, tUNK_11, tUNK_12, tUNK_13, tUNK_14;
u8 tUNK_18, tUNK_19, tUNK_20, tUNK_21;
u8 magic_number = 0;
u8 *mem = NULL, *entry;
int i, recordlen, entries;
if (bios->type == NVBIOS_BIT) {
if (bit_table(dev, 'P', &P))
return;
if (P.version == 1)
mem = ROMPTR(bios, P.data[4]);
else
if (P.version == 2)
mem = ROMPTR(bios, P.data[8]);
else {
NV_WARN(dev, "unknown mem for BIT P %d\n", P.version);
}
} else {
NV_DEBUG(dev, "BMP version too old for memory\n");
return;
}
if (!mem) {
NV_DEBUG(dev, "memory timing table pointer invalid\n");
return;
}
if (mem[0] != 0x10) {
NV_WARN(dev, "memory timing table 0x%02x unknown\n", mem[0]);
return;
}
entries = mem[2];
recordlen = mem[3];
if (recordlen < 15) {
NV_ERROR(dev, "mem timing table length unknown: %d\n", mem[3]);
return;
}
memtimings->timing =
kcalloc(entries, sizeof(*memtimings->timing), GFP_KERNEL);
if (!memtimings->timing)
return;
if (dev_priv->card_type >= NV_40 && dev_priv->chipset < 0x98) {
magic_number = (nv_rd32(dev, 0x100228) & 0x0f000000) >> 24;
}
entry = mem + mem[1];
for (i = 0; i < entries; i++, entry += recordlen) {
struct nouveau_pm_memtiming *timing = &pm->memtimings.timing[i];
if (entry[0] == 0)
continue;
tUNK_18 = 1;
tUNK_19 = 1;
tUNK_20 = 0;
tUNK_21 = 0;
switch (min(recordlen, 22)) {
case 22:
tUNK_21 = entry[21];
case 21:
tUNK_20 = entry[20];
case 20:
tUNK_19 = entry[19];
case 19:
tUNK_18 = entry[18];
default:
tUNK_0 = entry[0];
tUNK_1 = entry[1];
tUNK_2 = entry[2];
tRP = entry[3];
tRAS = entry[5];
tRFC = entry[7];
tRC = entry[9];
tUNK_10 = entry[10];
tUNK_11 = entry[11];
tUNK_12 = entry[12];
tUNK_13 = entry[13];
tUNK_14 = entry[14];
break;
}
timing->reg_100220 = (tRC << 24 | tRFC << 16 | tRAS << 8 | tRP);
timing->reg_100224 = (tUNK_0 + tUNK_19 + 1 + magic_number) << 24 |
max(tUNK_18, (u8) 1) << 16 |
(tUNK_1 + tUNK_19 + 1 + magic_number) << 8;
if (dev_priv->chipset == 0xa8) {
timing->reg_100224 |= (tUNK_2 - 1);
} else {
timing->reg_100224 |= (tUNK_2 + 2 - magic_number);
}
timing->reg_100228 = (tUNK_12 << 16 | tUNK_11 << 8 | tUNK_10);
if (dev_priv->chipset >= 0xa3 && dev_priv->chipset < 0xaa)
timing->reg_100228 |= (tUNK_19 - 1) << 24;
else
timing->reg_100228 |= magic_number << 24;
if (dev_priv->card_type == NV_40) {
timing->reg_100228 |= 0x20200000;
} else if (dev_priv->card_type >= NV_50) {
if (dev_priv->chipset < 0x98 ||
(dev_priv->chipset == 0x98 &&
dev_priv->stepping <= 0xa1)) {
timing->reg_10022c = (0x14 + tUNK_2) << 24 |
0x16 << 16 |
(tUNK_2 - 1) << 8 |
(tUNK_2 - 1);
} else {
timing->reg_10022c = tUNK_2 - 1;
}
timing->reg_100230 = (tUNK_20 << 24 | tUNK_21 << 16 |
tUNK_13 << 8 | tUNK_13);
timing->reg_100234 = (tRAS << 24 | tRC);
timing->reg_100234 += max(tUNK_10, tUNK_11) << 16;
if (dev_priv->chipset < 0x98 ||
(dev_priv->chipset == 0x98 &&
dev_priv->stepping <= 0xa1)) {
timing->reg_100234 |= (tUNK_2 + 2) << 8;
} else {
timing->reg_100234 |= (tUNK_19 + 6) << 8;
}
timing->reg_10023c = 0x202;
if (dev_priv->chipset < 0x98 ||
(dev_priv->chipset == 0x98 &&
dev_priv->stepping <= 0xa1)) {
timing->reg_10023c |= 0x4000000 | (tUNK_2 - 1) << 16;
} else {
}
}
timing->id = i;
NV_DEBUG(dev, "Entry %d: 220: %08x %08x %08x %08x\n", i,
timing->reg_100220, timing->reg_100224,
timing->reg_100228, timing->reg_10022c);
NV_DEBUG(dev, " 230: %08x %08x %08x %08x\n",
timing->reg_100230, timing->reg_100234,
timing->reg_100238, timing->reg_10023c);
NV_DEBUG(dev, " 240: %08x\n", timing->reg_100240);
}
memtimings->nr_timing = entries;
memtimings->supported = (dev_priv->chipset <= 0x98);
}
void
nouveau_mem_timing_fini(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_memtimings *mem = &dev_priv->engine.pm.memtimings;
kfree(mem->timing);
}
static int
nouveau_vram_manager_init(struct ttm_mem_type_manager *man, unsigned long psize)
{
return 0;
}
static int
nouveau_vram_manager_fini(struct ttm_mem_type_manager *man)
{
return 0;
}
static inline void
nouveau_mem_node_cleanup(struct nouveau_mem *node)
{
if (node->vma[0].node) {
nouveau_vm_unmap(&node->vma[0]);
nouveau_vm_put(&node->vma[0]);
}
if (node->vma[1].node) {
nouveau_vm_unmap(&node->vma[1]);
nouveau_vm_put(&node->vma[1]);
}
}
static void
nouveau_vram_manager_del(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(man->bdev);
struct nouveau_vram_engine *vram = &dev_priv->engine.vram;
struct drm_device *dev = dev_priv->dev;
nouveau_mem_node_cleanup(mem->mm_node);
vram->put(dev, (struct nouveau_mem **)&mem->mm_node);
}
static int
nouveau_vram_manager_new(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *bo,
struct ttm_placement *placement,
struct ttm_mem_reg *mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(man->bdev);
struct nouveau_vram_engine *vram = &dev_priv->engine.vram;
struct drm_device *dev = dev_priv->dev;
struct nouveau_bo *nvbo = nouveau_bo(bo);
struct nouveau_mem *node;
u32 size_nc = 0;
int ret;
if (nvbo->tile_flags & NOUVEAU_GEM_TILE_NONCONTIG)
size_nc = 1 << nvbo->page_shift;
ret = vram->get(dev, mem->num_pages << PAGE_SHIFT,
mem->page_alignment << PAGE_SHIFT, size_nc,
(nvbo->tile_flags >> 8) & 0x3ff, &node);
if (ret) {
mem->mm_node = NULL;
return (ret == -ENOSPC) ? 0 : ret;
}
node->page_shift = nvbo->page_shift;
mem->mm_node = node;
mem->start = node->offset >> PAGE_SHIFT;
return 0;
}
void
nouveau_vram_manager_debug(struct ttm_mem_type_manager *man, const char *prefix)
{
struct nouveau_mm *mm = man->priv;
struct nouveau_mm_node *r;
u32 total = 0, free = 0;
mutex_lock(&mm->mutex);
list_for_each_entry(r, &mm->nodes, nl_entry) {
printk(KERN_DEBUG "%s %d: 0x%010llx 0x%010llx\n",
prefix, r->type, ((u64)r->offset << 12),
(((u64)r->offset + r->length) << 12));
total += r->length;
if (!r->type)
free += r->length;
}
mutex_unlock(&mm->mutex);
printk(KERN_DEBUG "%s total: 0x%010llx free: 0x%010llx\n",
prefix, (u64)total << 12, (u64)free << 12);
printk(KERN_DEBUG "%s block: 0x%08x\n",
prefix, mm->block_size << 12);
}
static int
nouveau_gart_manager_init(struct ttm_mem_type_manager *man, unsigned long psize)
{
return 0;
}
static int
nouveau_gart_manager_fini(struct ttm_mem_type_manager *man)
{
return 0;
}
static void
nouveau_gart_manager_del(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
nouveau_mem_node_cleanup(mem->mm_node);
kfree(mem->mm_node);
mem->mm_node = NULL;
}
static int
nouveau_gart_manager_new(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *bo,
struct ttm_placement *placement,
struct ttm_mem_reg *mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct nouveau_mem *node;
if (unlikely((mem->num_pages << PAGE_SHIFT) >=
dev_priv->gart_info.aper_size))
return -ENOMEM;
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node)
return -ENOMEM;
node->page_shift = 12;
mem->mm_node = node;
mem->start = 0;
return 0;
}
void
nouveau_gart_manager_debug(struct ttm_mem_type_manager *man, const char *prefix)
{
}
