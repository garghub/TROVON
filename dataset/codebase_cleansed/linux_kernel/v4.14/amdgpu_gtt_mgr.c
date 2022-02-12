static int amdgpu_gtt_mgr_init(struct ttm_mem_type_manager *man,
unsigned long p_size)
{
struct amdgpu_device *adev = amdgpu_ttm_adev(man->bdev);
struct amdgpu_gtt_mgr *mgr;
uint64_t start, size;
mgr = kzalloc(sizeof(*mgr), GFP_KERNEL);
if (!mgr)
return -ENOMEM;
start = AMDGPU_GTT_MAX_TRANSFER_SIZE * AMDGPU_GTT_NUM_TRANSFER_WINDOWS;
size = (adev->mc.gart_size >> PAGE_SHIFT) - start;
drm_mm_init(&mgr->mm, start, size);
spin_lock_init(&mgr->lock);
atomic64_set(&mgr->available, p_size);
man->priv = mgr;
return 0;
}
static int amdgpu_gtt_mgr_fini(struct ttm_mem_type_manager *man)
{
struct amdgpu_gtt_mgr *mgr = man->priv;
spin_lock(&mgr->lock);
if (!drm_mm_clean(&mgr->mm)) {
spin_unlock(&mgr->lock);
return -EBUSY;
}
drm_mm_takedown(&mgr->mm);
spin_unlock(&mgr->lock);
kfree(mgr);
man->priv = NULL;
return 0;
}
bool amdgpu_gtt_mgr_is_allocated(struct ttm_mem_reg *mem)
{
struct drm_mm_node *node = mem->mm_node;
return (node->start != AMDGPU_BO_INVALID_OFFSET);
}
static int amdgpu_gtt_mgr_alloc(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *tbo,
const struct ttm_place *place,
struct ttm_mem_reg *mem)
{
struct amdgpu_device *adev = amdgpu_ttm_adev(man->bdev);
struct amdgpu_gtt_mgr *mgr = man->priv;
struct drm_mm_node *node = mem->mm_node;
enum drm_mm_insert_mode mode;
unsigned long fpfn, lpfn;
int r;
if (amdgpu_gtt_mgr_is_allocated(mem))
return 0;
if (place)
fpfn = place->fpfn;
else
fpfn = 0;
if (place && place->lpfn)
lpfn = place->lpfn;
else
lpfn = adev->gart.num_cpu_pages;
mode = DRM_MM_INSERT_BEST;
if (place && place->flags & TTM_PL_FLAG_TOPDOWN)
mode = DRM_MM_INSERT_HIGH;
spin_lock(&mgr->lock);
r = drm_mm_insert_node_in_range(&mgr->mm, node,
mem->num_pages, mem->page_alignment, 0,
fpfn, lpfn, mode);
spin_unlock(&mgr->lock);
if (!r)
mem->start = node->start;
return r;
}
static int amdgpu_gtt_mgr_new(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *tbo,
const struct ttm_place *place,
struct ttm_mem_reg *mem)
{
struct amdgpu_gtt_mgr *mgr = man->priv;
struct drm_mm_node *node;
int r;
spin_lock(&mgr->lock);
if (atomic64_read(&mgr->available) < mem->num_pages) {
spin_unlock(&mgr->lock);
return 0;
}
atomic64_sub(mem->num_pages, &mgr->available);
spin_unlock(&mgr->lock);
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node) {
r = -ENOMEM;
goto err_out;
}
node->start = AMDGPU_BO_INVALID_OFFSET;
node->size = mem->num_pages;
mem->mm_node = node;
if (place->fpfn || place->lpfn || place->flags & TTM_PL_FLAG_TOPDOWN) {
r = amdgpu_gtt_mgr_alloc(man, tbo, place, mem);
if (unlikely(r)) {
kfree(node);
mem->mm_node = NULL;
r = 0;
goto err_out;
}
} else {
mem->start = node->start;
}
return 0;
err_out:
atomic64_add(mem->num_pages, &mgr->available);
return r;
}
static void amdgpu_gtt_mgr_del(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
struct amdgpu_gtt_mgr *mgr = man->priv;
struct drm_mm_node *node = mem->mm_node;
if (!node)
return;
spin_lock(&mgr->lock);
if (node->start != AMDGPU_BO_INVALID_OFFSET)
drm_mm_remove_node(node);
spin_unlock(&mgr->lock);
atomic64_add(mem->num_pages, &mgr->available);
kfree(node);
mem->mm_node = NULL;
}
uint64_t amdgpu_gtt_mgr_usage(struct ttm_mem_type_manager *man)
{
struct amdgpu_gtt_mgr *mgr = man->priv;
return (u64)(man->size - atomic64_read(&mgr->available)) * PAGE_SIZE;
}
static void amdgpu_gtt_mgr_debug(struct ttm_mem_type_manager *man,
struct drm_printer *printer)
{
struct amdgpu_gtt_mgr *mgr = man->priv;
spin_lock(&mgr->lock);
drm_mm_print(&mgr->mm, printer);
spin_unlock(&mgr->lock);
drm_printf(printer, "man size:%llu pages, gtt available:%llu pages, usage:%lluMB\n",
man->size, (u64)atomic64_read(&mgr->available),
amdgpu_gtt_mgr_usage(man) >> 20);
}
