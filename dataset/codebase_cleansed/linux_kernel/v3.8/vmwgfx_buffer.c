static int vmw_ttm_bind(struct ttm_tt *ttm, struct ttm_mem_reg *bo_mem)
{
struct vmw_ttm_tt *vmw_be = container_of(ttm, struct vmw_ttm_tt, ttm);
vmw_be->gmr_id = bo_mem->start;
return vmw_gmr_bind(vmw_be->dev_priv, ttm->pages,
ttm->num_pages, vmw_be->gmr_id);
}
static int vmw_ttm_unbind(struct ttm_tt *ttm)
{
struct vmw_ttm_tt *vmw_be = container_of(ttm, struct vmw_ttm_tt, ttm);
vmw_gmr_unbind(vmw_be->dev_priv, vmw_be->gmr_id);
return 0;
}
static void vmw_ttm_destroy(struct ttm_tt *ttm)
{
struct vmw_ttm_tt *vmw_be = container_of(ttm, struct vmw_ttm_tt, ttm);
ttm_tt_fini(ttm);
kfree(vmw_be);
}
struct ttm_tt *vmw_ttm_tt_create(struct ttm_bo_device *bdev,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
struct vmw_ttm_tt *vmw_be;
vmw_be = kmalloc(sizeof(*vmw_be), GFP_KERNEL);
if (!vmw_be)
return NULL;
vmw_be->ttm.func = &vmw_ttm_func;
vmw_be->dev_priv = container_of(bdev, struct vmw_private, bdev);
if (ttm_tt_init(&vmw_be->ttm, bdev, size, page_flags, dummy_read_page)) {
kfree(vmw_be);
return NULL;
}
return &vmw_be->ttm;
}
int vmw_invalidate_caches(struct ttm_bo_device *bdev, uint32_t flags)
{
return 0;
}
int vmw_init_mem_type(struct ttm_bo_device *bdev, uint32_t type,
struct ttm_mem_type_manager *man)
{
switch (type) {
case TTM_PL_SYSTEM:
man->flags = TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_CACHED;
man->default_caching = TTM_PL_FLAG_CACHED;
break;
case TTM_PL_VRAM:
man->func = &ttm_bo_manager_func;
man->gpu_offset = 0;
man->flags = TTM_MEMTYPE_FLAG_FIXED | TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_CACHED;
man->default_caching = TTM_PL_FLAG_CACHED;
break;
case VMW_PL_GMR:
man->func = &vmw_gmrid_manager_func;
man->gpu_offset = 0;
man->flags = TTM_MEMTYPE_FLAG_CMA | TTM_MEMTYPE_FLAG_MAPPABLE;
man->available_caching = TTM_PL_FLAG_CACHED;
man->default_caching = TTM_PL_FLAG_CACHED;
break;
default:
DRM_ERROR("Unsupported memory type %u\n", (unsigned)type);
return -EINVAL;
}
return 0;
}
void vmw_evict_flags(struct ttm_buffer_object *bo,
struct ttm_placement *placement)
{
*placement = vmw_sys_placement;
}
static int vmw_verify_access(struct ttm_buffer_object *bo, struct file *filp)
{
struct ttm_object_file *tfile =
vmw_fpriv((struct drm_file *)filp->private_data)->tfile;
return vmw_user_dmabuf_verify_access(bo, tfile);
}
static int vmw_ttm_io_mem_reserve(struct ttm_bo_device *bdev, struct ttm_mem_reg *mem)
{
struct ttm_mem_type_manager *man = &bdev->man[mem->mem_type];
struct vmw_private *dev_priv = container_of(bdev, struct vmw_private, bdev);
mem->bus.addr = NULL;
mem->bus.is_iomem = false;
mem->bus.offset = 0;
mem->bus.size = mem->num_pages << PAGE_SHIFT;
mem->bus.base = 0;
if (!(man->flags & TTM_MEMTYPE_FLAG_MAPPABLE))
return -EINVAL;
switch (mem->mem_type) {
case TTM_PL_SYSTEM:
case VMW_PL_GMR:
return 0;
case TTM_PL_VRAM:
mem->bus.offset = mem->start << PAGE_SHIFT;
mem->bus.base = dev_priv->vram_start;
mem->bus.is_iomem = true;
break;
default:
return -EINVAL;
}
return 0;
}
static void vmw_ttm_io_mem_free(struct ttm_bo_device *bdev, struct ttm_mem_reg *mem)
{
}
static int vmw_ttm_fault_reserve_notify(struct ttm_buffer_object *bo)
{
return 0;
}
static void *vmw_sync_obj_ref(void *sync_obj)
{
return (void *)
vmw_fence_obj_reference((struct vmw_fence_obj *) sync_obj);
}
static void vmw_sync_obj_unref(void **sync_obj)
{
vmw_fence_obj_unreference((struct vmw_fence_obj **) sync_obj);
}
static int vmw_sync_obj_flush(void *sync_obj)
{
vmw_fence_obj_flush((struct vmw_fence_obj *) sync_obj);
return 0;
}
static bool vmw_sync_obj_signaled(void *sync_obj)
{
return vmw_fence_obj_signaled((struct vmw_fence_obj *) sync_obj,
DRM_VMW_FENCE_FLAG_EXEC);
}
static int vmw_sync_obj_wait(void *sync_obj, bool lazy, bool interruptible)
{
return vmw_fence_obj_wait((struct vmw_fence_obj *) sync_obj,
DRM_VMW_FENCE_FLAG_EXEC,
lazy, interruptible,
VMW_FENCE_WAIT_TIMEOUT);
}
