static inline struct mga_device *
mgag200_bdev(struct ttm_bo_device *bd)
{
return container_of(bd, struct mga_device, ttm.bdev);
}
static int
mgag200_ttm_mem_global_init(struct drm_global_reference *ref)
{
return ttm_mem_global_init(ref->object);
}
static void
mgag200_ttm_mem_global_release(struct drm_global_reference *ref)
{
ttm_mem_global_release(ref->object);
}
static int mgag200_ttm_global_init(struct mga_device *ast)
{
struct drm_global_reference *global_ref;
int r;
global_ref = &ast->ttm.mem_global_ref;
global_ref->global_type = DRM_GLOBAL_TTM_MEM;
global_ref->size = sizeof(struct ttm_mem_global);
global_ref->init = &mgag200_ttm_mem_global_init;
global_ref->release = &mgag200_ttm_mem_global_release;
r = drm_global_item_ref(global_ref);
if (r != 0) {
DRM_ERROR("Failed setting up TTM memory accounting "
"subsystem.\n");
return r;
}
ast->ttm.bo_global_ref.mem_glob =
ast->ttm.mem_global_ref.object;
global_ref = &ast->ttm.bo_global_ref.ref;
global_ref->global_type = DRM_GLOBAL_TTM_BO;
global_ref->size = sizeof(struct ttm_bo_global);
global_ref->init = &ttm_bo_global_init;
global_ref->release = &ttm_bo_global_release;
r = drm_global_item_ref(global_ref);
if (r != 0) {
DRM_ERROR("Failed setting up TTM BO subsystem.\n");
drm_global_item_unref(&ast->ttm.mem_global_ref);
return r;
}
return 0;
}
void
mgag200_ttm_global_release(struct mga_device *ast)
{
if (ast->ttm.mem_global_ref.release == NULL)
return;
drm_global_item_unref(&ast->ttm.bo_global_ref.ref);
drm_global_item_unref(&ast->ttm.mem_global_ref);
ast->ttm.mem_global_ref.release = NULL;
}
static void mgag200_bo_ttm_destroy(struct ttm_buffer_object *tbo)
{
struct mgag200_bo *bo;
bo = container_of(tbo, struct mgag200_bo, bo);
drm_gem_object_release(&bo->gem);
kfree(bo);
}
bool mgag200_ttm_bo_is_mgag200_bo(struct ttm_buffer_object *bo)
{
if (bo->destroy == &mgag200_bo_ttm_destroy)
return true;
return false;
}
static int
mgag200_bo_init_mem_type(struct ttm_bo_device *bdev, uint32_t type,
struct ttm_mem_type_manager *man)
{
switch (type) {
case TTM_PL_SYSTEM:
man->flags = TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_MASK_CACHING;
man->default_caching = TTM_PL_FLAG_CACHED;
break;
case TTM_PL_VRAM:
man->func = &ttm_bo_manager_func;
man->flags = TTM_MEMTYPE_FLAG_FIXED |
TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_UNCACHED |
TTM_PL_FLAG_WC;
man->default_caching = TTM_PL_FLAG_WC;
break;
default:
DRM_ERROR("Unsupported memory type %u\n", (unsigned)type);
return -EINVAL;
}
return 0;
}
static void
mgag200_bo_evict_flags(struct ttm_buffer_object *bo, struct ttm_placement *pl)
{
struct mgag200_bo *mgabo = mgag200_bo(bo);
if (!mgag200_ttm_bo_is_mgag200_bo(bo))
return;
mgag200_ttm_placement(mgabo, TTM_PL_FLAG_SYSTEM);
*pl = mgabo->placement;
}
static int mgag200_bo_verify_access(struct ttm_buffer_object *bo, struct file *filp)
{
return 0;
}
static int mgag200_ttm_io_mem_reserve(struct ttm_bo_device *bdev,
struct ttm_mem_reg *mem)
{
struct ttm_mem_type_manager *man = &bdev->man[mem->mem_type];
struct mga_device *mdev = mgag200_bdev(bdev);
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
case TTM_PL_VRAM:
mem->bus.offset = mem->start << PAGE_SHIFT;
mem->bus.base = pci_resource_start(mdev->dev->pdev, 0);
mem->bus.is_iomem = true;
break;
default:
return -EINVAL;
break;
}
return 0;
}
static void mgag200_ttm_io_mem_free(struct ttm_bo_device *bdev, struct ttm_mem_reg *mem)
{
}
static int mgag200_bo_move(struct ttm_buffer_object *bo,
bool evict, bool interruptible,
bool no_wait_gpu,
struct ttm_mem_reg *new_mem)
{
int r;
r = ttm_bo_move_memcpy(bo, evict, no_wait_gpu, new_mem);
return r;
}
static void mgag200_ttm_backend_destroy(struct ttm_tt *tt)
{
ttm_tt_fini(tt);
kfree(tt);
}
struct ttm_tt *mgag200_ttm_tt_create(struct ttm_bo_device *bdev,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
struct ttm_tt *tt;
tt = kzalloc(sizeof(struct ttm_tt), GFP_KERNEL);
if (tt == NULL)
return NULL;
tt->func = &mgag200_tt_backend_func;
if (ttm_tt_init(tt, bdev, size, page_flags, dummy_read_page)) {
kfree(tt);
return NULL;
}
return tt;
}
static int mgag200_ttm_tt_populate(struct ttm_tt *ttm)
{
return ttm_pool_populate(ttm);
}
static void mgag200_ttm_tt_unpopulate(struct ttm_tt *ttm)
{
ttm_pool_unpopulate(ttm);
}
int mgag200_mm_init(struct mga_device *mdev)
{
int ret;
struct drm_device *dev = mdev->dev;
struct ttm_bo_device *bdev = &mdev->ttm.bdev;
ret = mgag200_ttm_global_init(mdev);
if (ret)
return ret;
ret = ttm_bo_device_init(&mdev->ttm.bdev,
mdev->ttm.bo_global_ref.ref.object,
&mgag200_bo_driver, DRM_FILE_PAGE_OFFSET,
true);
if (ret) {
DRM_ERROR("Error initialising bo driver; %d\n", ret);
return ret;
}
ret = ttm_bo_init_mm(bdev, TTM_PL_VRAM, mdev->mc.vram_size >> PAGE_SHIFT);
if (ret) {
DRM_ERROR("Failed ttm VRAM init: %d\n", ret);
return ret;
}
mdev->fb_mtrr = drm_mtrr_add(pci_resource_start(dev->pdev, 0),
pci_resource_len(dev->pdev, 0),
DRM_MTRR_WC);
return 0;
}
void mgag200_mm_fini(struct mga_device *mdev)
{
struct drm_device *dev = mdev->dev;
ttm_bo_device_release(&mdev->ttm.bdev);
mgag200_ttm_global_release(mdev);
if (mdev->fb_mtrr >= 0) {
drm_mtrr_del(mdev->fb_mtrr,
pci_resource_start(dev->pdev, 0),
pci_resource_len(dev->pdev, 0), DRM_MTRR_WC);
mdev->fb_mtrr = -1;
}
}
void mgag200_ttm_placement(struct mgag200_bo *bo, int domain)
{
u32 c = 0;
bo->placement.fpfn = 0;
bo->placement.lpfn = 0;
bo->placement.placement = bo->placements;
bo->placement.busy_placement = bo->placements;
if (domain & TTM_PL_FLAG_VRAM)
bo->placements[c++] = TTM_PL_FLAG_WC | TTM_PL_FLAG_UNCACHED | TTM_PL_FLAG_VRAM;
if (domain & TTM_PL_FLAG_SYSTEM)
bo->placements[c++] = TTM_PL_MASK_CACHING | TTM_PL_FLAG_SYSTEM;
if (!c)
bo->placements[c++] = TTM_PL_MASK_CACHING | TTM_PL_FLAG_SYSTEM;
bo->placement.num_placement = c;
bo->placement.num_busy_placement = c;
}
int mgag200_bo_reserve(struct mgag200_bo *bo, bool no_wait)
{
int ret;
ret = ttm_bo_reserve(&bo->bo, true, no_wait, false, 0);
if (ret) {
if (ret != -ERESTARTSYS)
DRM_ERROR("reserve failed %p\n", bo);
return ret;
}
return 0;
}
void mgag200_bo_unreserve(struct mgag200_bo *bo)
{
ttm_bo_unreserve(&bo->bo);
}
int mgag200_bo_create(struct drm_device *dev, int size, int align,
uint32_t flags, struct mgag200_bo **pmgabo)
{
struct mga_device *mdev = dev->dev_private;
struct mgag200_bo *mgabo;
size_t acc_size;
int ret;
mgabo = kzalloc(sizeof(struct mgag200_bo), GFP_KERNEL);
if (!mgabo)
return -ENOMEM;
ret = drm_gem_object_init(dev, &mgabo->gem, size);
if (ret) {
kfree(mgabo);
return ret;
}
mgabo->gem.driver_private = NULL;
mgabo->bo.bdev = &mdev->ttm.bdev;
mgag200_ttm_placement(mgabo, TTM_PL_FLAG_VRAM | TTM_PL_FLAG_SYSTEM);
acc_size = ttm_bo_dma_acc_size(&mdev->ttm.bdev, size,
sizeof(struct mgag200_bo));
ret = ttm_bo_init(&mdev->ttm.bdev, &mgabo->bo, size,
ttm_bo_type_device, &mgabo->placement,
align >> PAGE_SHIFT, false, NULL, acc_size,
NULL, mgag200_bo_ttm_destroy);
if (ret)
return ret;
*pmgabo = mgabo;
return 0;
}
static inline u64 mgag200_bo_gpu_offset(struct mgag200_bo *bo)
{
return bo->bo.offset;
}
int mgag200_bo_pin(struct mgag200_bo *bo, u32 pl_flag, u64 *gpu_addr)
{
int i, ret;
if (bo->pin_count) {
bo->pin_count++;
if (gpu_addr)
*gpu_addr = mgag200_bo_gpu_offset(bo);
}
mgag200_ttm_placement(bo, pl_flag);
for (i = 0; i < bo->placement.num_placement; i++)
bo->placements[i] |= TTM_PL_FLAG_NO_EVICT;
ret = ttm_bo_validate(&bo->bo, &bo->placement, false, false);
if (ret)
return ret;
bo->pin_count = 1;
if (gpu_addr)
*gpu_addr = mgag200_bo_gpu_offset(bo);
return 0;
}
int mgag200_bo_unpin(struct mgag200_bo *bo)
{
int i, ret;
if (!bo->pin_count) {
DRM_ERROR("unpin bad %p\n", bo);
return 0;
}
bo->pin_count--;
if (bo->pin_count)
return 0;
for (i = 0; i < bo->placement.num_placement ; i++)
bo->placements[i] &= ~TTM_PL_FLAG_NO_EVICT;
ret = ttm_bo_validate(&bo->bo, &bo->placement, false, false);
if (ret)
return ret;
return 0;
}
int mgag200_bo_push_sysram(struct mgag200_bo *bo)
{
int i, ret;
if (!bo->pin_count) {
DRM_ERROR("unpin bad %p\n", bo);
return 0;
}
bo->pin_count--;
if (bo->pin_count)
return 0;
if (bo->kmap.virtual)
ttm_bo_kunmap(&bo->kmap);
mgag200_ttm_placement(bo, TTM_PL_FLAG_SYSTEM);
for (i = 0; i < bo->placement.num_placement ; i++)
bo->placements[i] |= TTM_PL_FLAG_NO_EVICT;
ret = ttm_bo_validate(&bo->bo, &bo->placement, false, false);
if (ret) {
DRM_ERROR("pushing to VRAM failed\n");
return ret;
}
return 0;
}
int mgag200_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *file_priv;
struct mga_device *mdev;
if (unlikely(vma->vm_pgoff < DRM_FILE_PAGE_OFFSET))
return drm_mmap(filp, vma);
file_priv = filp->private_data;
mdev = file_priv->minor->dev->dev_private;
return ttm_bo_mmap(filp, vma, &mdev->ttm.bdev);
}
