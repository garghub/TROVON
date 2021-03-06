static void
nouveau_bo_del_ttm(struct ttm_buffer_object *bo)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct drm_device *dev = dev_priv->dev;
struct nouveau_bo *nvbo = nouveau_bo(bo);
if (unlikely(nvbo->gem))
DRM_ERROR("bo %p still attached to GEM object\n", bo);
nv10_mem_put_tile_region(dev, nvbo->tile, NULL);
if (nvbo->vma.node) {
nouveau_vm_unmap(&nvbo->vma);
nouveau_vm_put(&nvbo->vma);
}
kfree(nvbo);
}
static void
nouveau_bo_fixup_align(struct nouveau_bo *nvbo, u32 flags,
int *align, int *size, int *page_shift)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(nvbo->bo.bdev);
if (dev_priv->card_type < NV_50) {
if (nvbo->tile_mode) {
if (dev_priv->chipset >= 0x40) {
*align = 65536;
*size = roundup(*size, 64 * nvbo->tile_mode);
} else if (dev_priv->chipset >= 0x30) {
*align = 32768;
*size = roundup(*size, 64 * nvbo->tile_mode);
} else if (dev_priv->chipset >= 0x20) {
*align = 16384;
*size = roundup(*size, 64 * nvbo->tile_mode);
} else if (dev_priv->chipset >= 0x10) {
*align = 16384;
*size = roundup(*size, 32 * nvbo->tile_mode);
}
}
} else {
if (likely(dev_priv->chan_vm)) {
if (!(flags & TTM_PL_FLAG_TT) && *size > 256 * 1024)
*page_shift = dev_priv->chan_vm->lpg_shift;
else
*page_shift = dev_priv->chan_vm->spg_shift;
} else {
*page_shift = 12;
}
*size = roundup(*size, (1 << *page_shift));
*align = max((1 << *page_shift), *align);
}
*size = roundup(*size, PAGE_SIZE);
}
int
nouveau_bo_new(struct drm_device *dev, struct nouveau_channel *chan,
int size, int align, uint32_t flags, uint32_t tile_mode,
uint32_t tile_flags, struct nouveau_bo **pnvbo)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_bo *nvbo;
int ret = 0, page_shift = 0;
nvbo = kzalloc(sizeof(struct nouveau_bo), GFP_KERNEL);
if (!nvbo)
return -ENOMEM;
INIT_LIST_HEAD(&nvbo->head);
INIT_LIST_HEAD(&nvbo->entry);
nvbo->tile_mode = tile_mode;
nvbo->tile_flags = tile_flags;
nvbo->bo.bdev = &dev_priv->ttm.bdev;
nouveau_bo_fixup_align(nvbo, flags, &align, &size, &page_shift);
align >>= PAGE_SHIFT;
if (dev_priv->chan_vm) {
ret = nouveau_vm_get(dev_priv->chan_vm, size, page_shift,
NV_MEM_ACCESS_RW, &nvbo->vma);
if (ret) {
kfree(nvbo);
return ret;
}
}
nvbo->bo.mem.num_pages = size >> PAGE_SHIFT;
nouveau_bo_placement_set(nvbo, flags, 0);
nvbo->channel = chan;
ret = ttm_bo_init(&dev_priv->ttm.bdev, &nvbo->bo, size,
ttm_bo_type_device, &nvbo->placement, align, 0,
false, NULL, size, nouveau_bo_del_ttm);
if (ret) {
return ret;
}
nvbo->channel = NULL;
if (nvbo->vma.node)
nvbo->bo.offset = nvbo->vma.offset;
*pnvbo = nvbo;
return 0;
}
static void
set_placement_list(uint32_t *pl, unsigned *n, uint32_t type, uint32_t flags)
{
*n = 0;
if (type & TTM_PL_FLAG_VRAM)
pl[(*n)++] = TTM_PL_FLAG_VRAM | flags;
if (type & TTM_PL_FLAG_TT)
pl[(*n)++] = TTM_PL_FLAG_TT | flags;
if (type & TTM_PL_FLAG_SYSTEM)
pl[(*n)++] = TTM_PL_FLAG_SYSTEM | flags;
}
static void
set_placement_range(struct nouveau_bo *nvbo, uint32_t type)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(nvbo->bo.bdev);
int vram_pages = dev_priv->vram_size >> PAGE_SHIFT;
if (dev_priv->card_type == NV_10 &&
nvbo->tile_mode && (type & TTM_PL_FLAG_VRAM) &&
nvbo->bo.mem.num_pages < vram_pages / 2) {
if (nvbo->tile_flags & NOUVEAU_GEM_TILE_ZETA) {
nvbo->placement.fpfn = vram_pages / 2;
nvbo->placement.lpfn = ~0;
} else {
nvbo->placement.fpfn = 0;
nvbo->placement.lpfn = vram_pages / 2;
}
}
}
void
nouveau_bo_placement_set(struct nouveau_bo *nvbo, uint32_t type, uint32_t busy)
{
struct ttm_placement *pl = &nvbo->placement;
uint32_t flags = TTM_PL_MASK_CACHING |
(nvbo->pin_refcnt ? TTM_PL_FLAG_NO_EVICT : 0);
pl->placement = nvbo->placements;
set_placement_list(nvbo->placements, &pl->num_placement,
type, flags);
pl->busy_placement = nvbo->busy_placements;
set_placement_list(nvbo->busy_placements, &pl->num_busy_placement,
type | busy, flags);
set_placement_range(nvbo, type);
}
int
nouveau_bo_pin(struct nouveau_bo *nvbo, uint32_t memtype)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(nvbo->bo.bdev);
struct ttm_buffer_object *bo = &nvbo->bo;
int ret;
if (nvbo->pin_refcnt && !(memtype & (1 << bo->mem.mem_type))) {
NV_ERROR(nouveau_bdev(bo->bdev)->dev,
"bo %p pinned elsewhere: 0x%08x vs 0x%08x\n", bo,
1 << bo->mem.mem_type, memtype);
return -EINVAL;
}
if (nvbo->pin_refcnt++)
return 0;
ret = ttm_bo_reserve(bo, false, false, false, 0);
if (ret)
goto out;
nouveau_bo_placement_set(nvbo, memtype, 0);
ret = nouveau_bo_validate(nvbo, false, false, false);
if (ret == 0) {
switch (bo->mem.mem_type) {
case TTM_PL_VRAM:
dev_priv->fb_aper_free -= bo->mem.size;
break;
case TTM_PL_TT:
dev_priv->gart_info.aper_free -= bo->mem.size;
break;
default:
break;
}
}
ttm_bo_unreserve(bo);
out:
if (unlikely(ret))
nvbo->pin_refcnt--;
return ret;
}
int
nouveau_bo_unpin(struct nouveau_bo *nvbo)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(nvbo->bo.bdev);
struct ttm_buffer_object *bo = &nvbo->bo;
int ret;
if (--nvbo->pin_refcnt)
return 0;
ret = ttm_bo_reserve(bo, false, false, false, 0);
if (ret)
return ret;
nouveau_bo_placement_set(nvbo, bo->mem.placement, 0);
ret = nouveau_bo_validate(nvbo, false, false, false);
if (ret == 0) {
switch (bo->mem.mem_type) {
case TTM_PL_VRAM:
dev_priv->fb_aper_free += bo->mem.size;
break;
case TTM_PL_TT:
dev_priv->gart_info.aper_free += bo->mem.size;
break;
default:
break;
}
}
ttm_bo_unreserve(bo);
return ret;
}
int
nouveau_bo_map(struct nouveau_bo *nvbo)
{
int ret;
ret = ttm_bo_reserve(&nvbo->bo, false, false, false, 0);
if (ret)
return ret;
ret = ttm_bo_kmap(&nvbo->bo, 0, nvbo->bo.mem.num_pages, &nvbo->kmap);
ttm_bo_unreserve(&nvbo->bo);
return ret;
}
void
nouveau_bo_unmap(struct nouveau_bo *nvbo)
{
if (nvbo)
ttm_bo_kunmap(&nvbo->kmap);
}
int
nouveau_bo_validate(struct nouveau_bo *nvbo, bool interruptible,
bool no_wait_reserve, bool no_wait_gpu)
{
int ret;
ret = ttm_bo_validate(&nvbo->bo, &nvbo->placement, interruptible,
no_wait_reserve, no_wait_gpu);
if (ret)
return ret;
if (nvbo->vma.node)
nvbo->bo.offset = nvbo->vma.offset;
return 0;
}
u16
nouveau_bo_rd16(struct nouveau_bo *nvbo, unsigned index)
{
bool is_iomem;
u16 *mem = ttm_kmap_obj_virtual(&nvbo->kmap, &is_iomem);
mem = &mem[index];
if (is_iomem)
return ioread16_native((void __force __iomem *)mem);
else
return *mem;
}
void
nouveau_bo_wr16(struct nouveau_bo *nvbo, unsigned index, u16 val)
{
bool is_iomem;
u16 *mem = ttm_kmap_obj_virtual(&nvbo->kmap, &is_iomem);
mem = &mem[index];
if (is_iomem)
iowrite16_native(val, (void __force __iomem *)mem);
else
*mem = val;
}
u32
nouveau_bo_rd32(struct nouveau_bo *nvbo, unsigned index)
{
bool is_iomem;
u32 *mem = ttm_kmap_obj_virtual(&nvbo->kmap, &is_iomem);
mem = &mem[index];
if (is_iomem)
return ioread32_native((void __force __iomem *)mem);
else
return *mem;
}
void
nouveau_bo_wr32(struct nouveau_bo *nvbo, unsigned index, u32 val)
{
bool is_iomem;
u32 *mem = ttm_kmap_obj_virtual(&nvbo->kmap, &is_iomem);
mem = &mem[index];
if (is_iomem)
iowrite32_native(val, (void __force __iomem *)mem);
else
*mem = val;
}
static struct ttm_backend *
nouveau_bo_create_ttm_backend_entry(struct ttm_bo_device *bdev)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bdev);
struct drm_device *dev = dev_priv->dev;
switch (dev_priv->gart_info.type) {
#if __OS_HAS_AGP
case NOUVEAU_GART_AGP:
return ttm_agp_backend_init(bdev, dev->agp->bridge);
#endif
case NOUVEAU_GART_PDMA:
case NOUVEAU_GART_HW:
return nouveau_sgdma_init_ttm(dev);
default:
NV_ERROR(dev, "Unknown GART type %d\n",
dev_priv->gart_info.type);
break;
}
return NULL;
}
static int
nouveau_bo_invalidate_caches(struct ttm_bo_device *bdev, uint32_t flags)
{
return 0;
}
static int
nouveau_bo_init_mem_type(struct ttm_bo_device *bdev, uint32_t type,
struct ttm_mem_type_manager *man)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bdev);
struct drm_device *dev = dev_priv->dev;
switch (type) {
case TTM_PL_SYSTEM:
man->flags = TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_MASK_CACHING;
man->default_caching = TTM_PL_FLAG_CACHED;
break;
case TTM_PL_VRAM:
if (dev_priv->card_type >= NV_50) {
man->func = &nouveau_vram_manager;
man->io_reserve_fastpath = false;
man->use_io_reserve_lru = true;
} else {
man->func = &ttm_bo_manager_func;
}
man->flags = TTM_MEMTYPE_FLAG_FIXED |
TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_UNCACHED |
TTM_PL_FLAG_WC;
man->default_caching = TTM_PL_FLAG_WC;
break;
case TTM_PL_TT:
if (dev_priv->card_type >= NV_50)
man->func = &nouveau_gart_manager;
else
man->func = &ttm_bo_manager_func;
switch (dev_priv->gart_info.type) {
case NOUVEAU_GART_AGP:
man->flags = TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_UNCACHED |
TTM_PL_FLAG_WC;
man->default_caching = TTM_PL_FLAG_WC;
break;
case NOUVEAU_GART_PDMA:
case NOUVEAU_GART_HW:
man->flags = TTM_MEMTYPE_FLAG_MAPPABLE |
TTM_MEMTYPE_FLAG_CMA;
man->available_caching = TTM_PL_MASK_CACHING;
man->default_caching = TTM_PL_FLAG_CACHED;
man->gpu_offset = dev_priv->gart_info.aper_base;
break;
default:
NV_ERROR(dev, "Unknown GART type: %d\n",
dev_priv->gart_info.type);
return -EINVAL;
}
break;
default:
NV_ERROR(dev, "Unsupported memory type %u\n", (unsigned)type);
return -EINVAL;
}
return 0;
}
static void
nouveau_bo_evict_flags(struct ttm_buffer_object *bo, struct ttm_placement *pl)
{
struct nouveau_bo *nvbo = nouveau_bo(bo);
switch (bo->mem.mem_type) {
case TTM_PL_VRAM:
nouveau_bo_placement_set(nvbo, TTM_PL_FLAG_TT,
TTM_PL_FLAG_SYSTEM);
break;
default:
nouveau_bo_placement_set(nvbo, TTM_PL_FLAG_SYSTEM, 0);
break;
}
*pl = nvbo->placement;
}
static int
nouveau_bo_move_accel_cleanup(struct nouveau_channel *chan,
struct nouveau_bo *nvbo, bool evict,
bool no_wait_reserve, bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
struct nouveau_fence *fence = NULL;
int ret;
ret = nouveau_fence_new(chan, &fence, true);
if (ret)
return ret;
ret = ttm_bo_move_accel_cleanup(&nvbo->bo, fence, NULL, evict,
no_wait_reserve, no_wait_gpu, new_mem);
nouveau_fence_unref(&fence);
return ret;
}
static int
nvc0_bo_move_m2mf(struct nouveau_channel *chan, struct ttm_buffer_object *bo,
struct ttm_mem_reg *old_mem, struct ttm_mem_reg *new_mem)
{
struct nouveau_mem *old_node = old_mem->mm_node;
struct nouveau_mem *new_node = new_mem->mm_node;
struct nouveau_bo *nvbo = nouveau_bo(bo);
u32 page_count = new_mem->num_pages;
u64 src_offset, dst_offset;
int ret;
src_offset = old_node->tmp_vma.offset;
if (new_node->tmp_vma.node)
dst_offset = new_node->tmp_vma.offset;
else
dst_offset = nvbo->vma.offset;
page_count = new_mem->num_pages;
while (page_count) {
int line_count = (page_count > 2047) ? 2047 : page_count;
ret = RING_SPACE(chan, 12);
if (ret)
return ret;
BEGIN_NVC0(chan, 2, NvSubM2MF, 0x0238, 2);
OUT_RING (chan, upper_32_bits(dst_offset));
OUT_RING (chan, lower_32_bits(dst_offset));
BEGIN_NVC0(chan, 2, NvSubM2MF, 0x030c, 6);
OUT_RING (chan, upper_32_bits(src_offset));
OUT_RING (chan, lower_32_bits(src_offset));
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, line_count);
BEGIN_NVC0(chan, 2, NvSubM2MF, 0x0300, 1);
OUT_RING (chan, 0x00100110);
page_count -= line_count;
src_offset += (PAGE_SIZE * line_count);
dst_offset += (PAGE_SIZE * line_count);
}
return 0;
}
static int
nv50_bo_move_m2mf(struct nouveau_channel *chan, struct ttm_buffer_object *bo,
struct ttm_mem_reg *old_mem, struct ttm_mem_reg *new_mem)
{
struct nouveau_mem *old_node = old_mem->mm_node;
struct nouveau_mem *new_node = new_mem->mm_node;
struct nouveau_bo *nvbo = nouveau_bo(bo);
u64 length = (new_mem->num_pages << PAGE_SHIFT);
u64 src_offset, dst_offset;
int ret;
src_offset = old_node->tmp_vma.offset;
if (new_node->tmp_vma.node)
dst_offset = new_node->tmp_vma.offset;
else
dst_offset = nvbo->vma.offset;
while (length) {
u32 amount, stride, height;
amount = min(length, (u64)(4 * 1024 * 1024));
stride = 16 * 4;
height = amount / stride;
if (new_mem->mem_type == TTM_PL_VRAM &&
nouveau_bo_tile_layout(nvbo)) {
ret = RING_SPACE(chan, 8);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, 0x0200, 7);
OUT_RING (chan, 0);
OUT_RING (chan, 0);
OUT_RING (chan, stride);
OUT_RING (chan, height);
OUT_RING (chan, 1);
OUT_RING (chan, 0);
OUT_RING (chan, 0);
} else {
ret = RING_SPACE(chan, 2);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, 0x0200, 1);
OUT_RING (chan, 1);
}
if (old_mem->mem_type == TTM_PL_VRAM &&
nouveau_bo_tile_layout(nvbo)) {
ret = RING_SPACE(chan, 8);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, 0x021c, 7);
OUT_RING (chan, 0);
OUT_RING (chan, 0);
OUT_RING (chan, stride);
OUT_RING (chan, height);
OUT_RING (chan, 1);
OUT_RING (chan, 0);
OUT_RING (chan, 0);
} else {
ret = RING_SPACE(chan, 2);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, 0x021c, 1);
OUT_RING (chan, 1);
}
ret = RING_SPACE(chan, 14);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, 0x0238, 2);
OUT_RING (chan, upper_32_bits(src_offset));
OUT_RING (chan, upper_32_bits(dst_offset));
BEGIN_RING(chan, NvSubM2MF, 0x030c, 8);
OUT_RING (chan, lower_32_bits(src_offset));
OUT_RING (chan, lower_32_bits(dst_offset));
OUT_RING (chan, stride);
OUT_RING (chan, stride);
OUT_RING (chan, stride);
OUT_RING (chan, height);
OUT_RING (chan, 0x00000101);
OUT_RING (chan, 0x00000000);
BEGIN_RING(chan, NvSubM2MF, NV_MEMORY_TO_MEMORY_FORMAT_NOP, 1);
OUT_RING (chan, 0);
length -= amount;
src_offset += amount;
dst_offset += amount;
}
return 0;
}
static inline uint32_t
nouveau_bo_mem_ctxdma(struct ttm_buffer_object *bo,
struct nouveau_channel *chan, struct ttm_mem_reg *mem)
{
if (mem->mem_type == TTM_PL_TT)
return chan->gart_handle;
return chan->vram_handle;
}
static int
nv04_bo_move_m2mf(struct nouveau_channel *chan, struct ttm_buffer_object *bo,
struct ttm_mem_reg *old_mem, struct ttm_mem_reg *new_mem)
{
u32 src_offset = old_mem->start << PAGE_SHIFT;
u32 dst_offset = new_mem->start << PAGE_SHIFT;
u32 page_count = new_mem->num_pages;
int ret;
ret = RING_SPACE(chan, 3);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF, NV_MEMORY_TO_MEMORY_FORMAT_DMA_SOURCE, 2);
OUT_RING (chan, nouveau_bo_mem_ctxdma(bo, chan, old_mem));
OUT_RING (chan, nouveau_bo_mem_ctxdma(bo, chan, new_mem));
page_count = new_mem->num_pages;
while (page_count) {
int line_count = (page_count > 2047) ? 2047 : page_count;
ret = RING_SPACE(chan, 11);
if (ret)
return ret;
BEGIN_RING(chan, NvSubM2MF,
NV_MEMORY_TO_MEMORY_FORMAT_OFFSET_IN, 8);
OUT_RING (chan, src_offset);
OUT_RING (chan, dst_offset);
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, PAGE_SIZE);
OUT_RING (chan, line_count);
OUT_RING (chan, 0x00000101);
OUT_RING (chan, 0x00000000);
BEGIN_RING(chan, NvSubM2MF, NV_MEMORY_TO_MEMORY_FORMAT_NOP, 1);
OUT_RING (chan, 0);
page_count -= line_count;
src_offset += (PAGE_SIZE * line_count);
dst_offset += (PAGE_SIZE * line_count);
}
return 0;
}
static int
nouveau_bo_move_m2mf(struct ttm_buffer_object *bo, int evict, bool intr,
bool no_wait_reserve, bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct nouveau_bo *nvbo = nouveau_bo(bo);
struct ttm_mem_reg *old_mem = &bo->mem;
struct nouveau_channel *chan;
int ret;
chan = nvbo->channel;
if (!chan) {
chan = dev_priv->channel;
mutex_lock_nested(&chan->mutex, NOUVEAU_KCHANNEL_MUTEX);
}
if (dev_priv->card_type >= NV_50) {
struct nouveau_mem *node = old_mem->mm_node;
if (!node->tmp_vma.node) {
u32 page_shift = nvbo->vma.node->type;
if (old_mem->mem_type == TTM_PL_TT)
page_shift = nvbo->vma.vm->spg_shift;
ret = nouveau_vm_get(chan->vm,
old_mem->num_pages << PAGE_SHIFT,
page_shift, NV_MEM_ACCESS_RO,
&node->tmp_vma);
if (ret)
goto out;
}
if (old_mem->mem_type == TTM_PL_VRAM)
nouveau_vm_map(&node->tmp_vma, node);
else {
nouveau_vm_map_sg(&node->tmp_vma, 0,
old_mem->num_pages << PAGE_SHIFT,
node, node->pages);
}
}
if (dev_priv->card_type < NV_50)
ret = nv04_bo_move_m2mf(chan, bo, &bo->mem, new_mem);
else
if (dev_priv->card_type < NV_C0)
ret = nv50_bo_move_m2mf(chan, bo, &bo->mem, new_mem);
else
ret = nvc0_bo_move_m2mf(chan, bo, &bo->mem, new_mem);
if (ret == 0) {
ret = nouveau_bo_move_accel_cleanup(chan, nvbo, evict,
no_wait_reserve,
no_wait_gpu, new_mem);
}
out:
if (chan == dev_priv->channel)
mutex_unlock(&chan->mutex);
return ret;
}
static int
nouveau_bo_move_flipd(struct ttm_buffer_object *bo, bool evict, bool intr,
bool no_wait_reserve, bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
u32 placement_memtype = TTM_PL_FLAG_TT | TTM_PL_MASK_CACHING;
struct ttm_placement placement;
struct ttm_mem_reg tmp_mem;
int ret;
placement.fpfn = placement.lpfn = 0;
placement.num_placement = placement.num_busy_placement = 1;
placement.placement = placement.busy_placement = &placement_memtype;
tmp_mem = *new_mem;
tmp_mem.mm_node = NULL;
ret = ttm_bo_mem_space(bo, &placement, &tmp_mem, intr, no_wait_reserve, no_wait_gpu);
if (ret)
return ret;
ret = ttm_tt_bind(bo->ttm, &tmp_mem);
if (ret)
goto out;
if (dev_priv->card_type >= NV_50) {
struct nouveau_bo *nvbo = nouveau_bo(bo);
struct nouveau_mem *node = tmp_mem.mm_node;
struct nouveau_vma *vma = &nvbo->vma;
if (vma->node->type != vma->vm->spg_shift)
vma = &node->tmp_vma;
nouveau_vm_map_sg(vma, 0, tmp_mem.num_pages << PAGE_SHIFT,
node, node->pages);
}
ret = nouveau_bo_move_m2mf(bo, true, intr, no_wait_reserve, no_wait_gpu, &tmp_mem);
if (dev_priv->card_type >= NV_50) {
struct nouveau_bo *nvbo = nouveau_bo(bo);
nouveau_vm_unmap(&nvbo->vma);
}
if (ret)
goto out;
ret = ttm_bo_move_ttm(bo, true, no_wait_reserve, no_wait_gpu, new_mem);
out:
ttm_bo_mem_put(bo, &tmp_mem);
return ret;
}
static int
nouveau_bo_move_flips(struct ttm_buffer_object *bo, bool evict, bool intr,
bool no_wait_reserve, bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
u32 placement_memtype = TTM_PL_FLAG_TT | TTM_PL_MASK_CACHING;
struct ttm_placement placement;
struct ttm_mem_reg tmp_mem;
int ret;
placement.fpfn = placement.lpfn = 0;
placement.num_placement = placement.num_busy_placement = 1;
placement.placement = placement.busy_placement = &placement_memtype;
tmp_mem = *new_mem;
tmp_mem.mm_node = NULL;
ret = ttm_bo_mem_space(bo, &placement, &tmp_mem, intr, no_wait_reserve, no_wait_gpu);
if (ret)
return ret;
ret = ttm_bo_move_ttm(bo, true, no_wait_reserve, no_wait_gpu, &tmp_mem);
if (ret)
goto out;
ret = nouveau_bo_move_m2mf(bo, true, intr, no_wait_reserve, no_wait_gpu, new_mem);
if (ret)
goto out;
out:
ttm_bo_mem_put(bo, &tmp_mem);
return ret;
}
static void
nouveau_bo_move_ntfy(struct ttm_buffer_object *bo, struct ttm_mem_reg *new_mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct nouveau_mem *node = new_mem->mm_node;
struct nouveau_bo *nvbo = nouveau_bo(bo);
struct nouveau_vma *vma = &nvbo->vma;
struct nouveau_vm *vm = vma->vm;
if (dev_priv->card_type < NV_50)
return;
switch (new_mem->mem_type) {
case TTM_PL_VRAM:
nouveau_vm_map(vma, node);
break;
case TTM_PL_TT:
if (vma->node->type != vm->spg_shift) {
nouveau_vm_unmap(vma);
vma = &node->tmp_vma;
}
nouveau_vm_map_sg(vma, 0, new_mem->num_pages << PAGE_SHIFT,
node, node->pages);
break;
default:
nouveau_vm_unmap(&nvbo->vma);
break;
}
}
static int
nouveau_bo_vm_bind(struct ttm_buffer_object *bo, struct ttm_mem_reg *new_mem,
struct nouveau_tile_reg **new_tile)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct drm_device *dev = dev_priv->dev;
struct nouveau_bo *nvbo = nouveau_bo(bo);
u64 offset = new_mem->start << PAGE_SHIFT;
*new_tile = NULL;
if (new_mem->mem_type != TTM_PL_VRAM)
return 0;
if (dev_priv->card_type >= NV_10) {
*new_tile = nv10_mem_set_tiling(dev, offset, new_mem->size,
nvbo->tile_mode,
nvbo->tile_flags);
}
return 0;
}
static void
nouveau_bo_vm_cleanup(struct ttm_buffer_object *bo,
struct nouveau_tile_reg *new_tile,
struct nouveau_tile_reg **old_tile)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct drm_device *dev = dev_priv->dev;
nv10_mem_put_tile_region(dev, *old_tile, bo->sync_obj);
*old_tile = new_tile;
}
static int
nouveau_bo_move(struct ttm_buffer_object *bo, bool evict, bool intr,
bool no_wait_reserve, bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct nouveau_bo *nvbo = nouveau_bo(bo);
struct ttm_mem_reg *old_mem = &bo->mem;
struct nouveau_tile_reg *new_tile = NULL;
int ret = 0;
if (dev_priv->card_type < NV_50) {
ret = nouveau_bo_vm_bind(bo, new_mem, &new_tile);
if (ret)
return ret;
}
if (old_mem->mem_type == TTM_PL_SYSTEM && !bo->ttm) {
BUG_ON(bo->mem.mm_node != NULL);
bo->mem = *new_mem;
new_mem->mm_node = NULL;
goto out;
}
if (!dev_priv->channel) {
ret = ttm_bo_move_memcpy(bo, evict, no_wait_reserve, no_wait_gpu, new_mem);
goto out;
}
if (new_mem->mem_type == TTM_PL_SYSTEM)
ret = nouveau_bo_move_flipd(bo, evict, intr, no_wait_reserve, no_wait_gpu, new_mem);
else if (old_mem->mem_type == TTM_PL_SYSTEM)
ret = nouveau_bo_move_flips(bo, evict, intr, no_wait_reserve, no_wait_gpu, new_mem);
else
ret = nouveau_bo_move_m2mf(bo, evict, intr, no_wait_reserve, no_wait_gpu, new_mem);
if (!ret)
goto out;
ret = ttm_bo_move_memcpy(bo, evict, no_wait_reserve, no_wait_gpu, new_mem);
out:
if (dev_priv->card_type < NV_50) {
if (ret)
nouveau_bo_vm_cleanup(bo, NULL, &new_tile);
else
nouveau_bo_vm_cleanup(bo, new_tile, &nvbo->tile);
}
return ret;
}
static int
nouveau_bo_verify_access(struct ttm_buffer_object *bo, struct file *filp)
{
return 0;
}
static int
nouveau_ttm_io_mem_reserve(struct ttm_bo_device *bdev, struct ttm_mem_reg *mem)
{
struct ttm_mem_type_manager *man = &bdev->man[mem->mem_type];
struct drm_nouveau_private *dev_priv = nouveau_bdev(bdev);
struct drm_device *dev = dev_priv->dev;
int ret;
mem->bus.addr = NULL;
mem->bus.offset = 0;
mem->bus.size = mem->num_pages << PAGE_SHIFT;
mem->bus.base = 0;
mem->bus.is_iomem = false;
if (!(man->flags & TTM_MEMTYPE_FLAG_MAPPABLE))
return -EINVAL;
switch (mem->mem_type) {
case TTM_PL_SYSTEM:
return 0;
case TTM_PL_TT:
#if __OS_HAS_AGP
if (dev_priv->gart_info.type == NOUVEAU_GART_AGP) {
mem->bus.offset = mem->start << PAGE_SHIFT;
mem->bus.base = dev_priv->gart_info.aper_base;
mem->bus.is_iomem = true;
}
#endif
break;
case TTM_PL_VRAM:
{
struct nouveau_mem *node = mem->mm_node;
u8 page_shift;
if (!dev_priv->bar1_vm) {
mem->bus.offset = mem->start << PAGE_SHIFT;
mem->bus.base = pci_resource_start(dev->pdev, 1);
mem->bus.is_iomem = true;
break;
}
if (dev_priv->card_type == NV_C0)
page_shift = node->page_shift;
else
page_shift = 12;
ret = nouveau_vm_get(dev_priv->bar1_vm, mem->bus.size,
page_shift, NV_MEM_ACCESS_RW,
&node->bar_vma);
if (ret)
return ret;
nouveau_vm_map(&node->bar_vma, node);
if (ret) {
nouveau_vm_put(&node->bar_vma);
return ret;
}
mem->bus.offset = node->bar_vma.offset;
if (dev_priv->card_type == NV_50)
mem->bus.offset -= 0x0020000000ULL;
mem->bus.base = pci_resource_start(dev->pdev, 1);
mem->bus.is_iomem = true;
}
break;
default:
return -EINVAL;
}
return 0;
}
static void
nouveau_ttm_io_mem_free(struct ttm_bo_device *bdev, struct ttm_mem_reg *mem)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bdev);
struct nouveau_mem *node = mem->mm_node;
if (!dev_priv->bar1_vm || mem->mem_type != TTM_PL_VRAM)
return;
if (!node->bar_vma.node)
return;
nouveau_vm_unmap(&node->bar_vma);
nouveau_vm_put(&node->bar_vma);
}
static int
nouveau_ttm_fault_reserve_notify(struct ttm_buffer_object *bo)
{
struct drm_nouveau_private *dev_priv = nouveau_bdev(bo->bdev);
struct nouveau_bo *nvbo = nouveau_bo(bo);
if (bo->mem.mem_type != TTM_PL_VRAM) {
if (dev_priv->card_type < NV_50 ||
!nouveau_bo_tile_layout(nvbo))
return 0;
}
if (bo->mem.start + bo->mem.num_pages < dev_priv->fb_mappable_pages)
return 0;
nvbo->placement.fpfn = 0;
nvbo->placement.lpfn = dev_priv->fb_mappable_pages;
nouveau_bo_placement_set(nvbo, TTM_PL_VRAM, 0);
return nouveau_bo_validate(nvbo, false, true, false);
}
void
nouveau_bo_fence(struct nouveau_bo *nvbo, struct nouveau_fence *fence)
{
struct nouveau_fence *old_fence;
if (likely(fence))
nouveau_fence_ref(fence);
spin_lock(&nvbo->bo.bdev->fence_lock);
old_fence = nvbo->bo.sync_obj;
nvbo->bo.sync_obj = fence;
spin_unlock(&nvbo->bo.bdev->fence_lock);
nouveau_fence_unref(&old_fence);
}
