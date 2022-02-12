int vmw_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *file_priv;
struct vmw_private *dev_priv;
if (unlikely(vma->vm_pgoff < VMWGFX_FILE_PAGE_OFFSET)) {
if (vmw_fifo_mmap(filp, vma) == 0)
return 0;
return drm_mmap(filp, vma);
}
file_priv = filp->private_data;
dev_priv = vmw_priv(file_priv->minor->dev);
return ttm_bo_mmap(filp, vma, &dev_priv->bdev);
}
static int vmw_ttm_mem_global_init(struct drm_global_reference *ref)
{
DRM_INFO("global init.\n");
return ttm_mem_global_init(ref->object);
}
static void vmw_ttm_mem_global_release(struct drm_global_reference *ref)
{
ttm_mem_global_release(ref->object);
}
int vmw_ttm_global_init(struct vmw_private *dev_priv)
{
struct drm_global_reference *global_ref;
int ret;
global_ref = &dev_priv->mem_global_ref;
global_ref->global_type = DRM_GLOBAL_TTM_MEM;
global_ref->size = sizeof(struct ttm_mem_global);
global_ref->init = &vmw_ttm_mem_global_init;
global_ref->release = &vmw_ttm_mem_global_release;
ret = drm_global_item_ref(global_ref);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed setting up TTM memory accounting.\n");
return ret;
}
dev_priv->bo_global_ref.mem_glob =
dev_priv->mem_global_ref.object;
global_ref = &dev_priv->bo_global_ref.ref;
global_ref->global_type = DRM_GLOBAL_TTM_BO;
global_ref->size = sizeof(struct ttm_bo_global);
global_ref->init = &ttm_bo_global_init;
global_ref->release = &ttm_bo_global_release;
ret = drm_global_item_ref(global_ref);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed setting up TTM buffer objects.\n");
goto out_no_bo;
}
return 0;
out_no_bo:
drm_global_item_unref(&dev_priv->mem_global_ref);
return ret;
}
void vmw_ttm_global_release(struct vmw_private *dev_priv)
{
drm_global_item_unref(&dev_priv->bo_global_ref.ref);
drm_global_item_unref(&dev_priv->mem_global_ref);
}
