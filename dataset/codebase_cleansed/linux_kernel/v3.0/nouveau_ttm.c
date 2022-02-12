int
nouveau_ttm_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *file_priv = filp->private_data;
struct drm_nouveau_private *dev_priv =
file_priv->minor->dev->dev_private;
if (unlikely(vma->vm_pgoff < DRM_FILE_PAGE_OFFSET))
return drm_mmap(filp, vma);
return ttm_bo_mmap(filp, vma, &dev_priv->ttm.bdev);
}
static int
nouveau_ttm_mem_global_init(struct drm_global_reference *ref)
{
return ttm_mem_global_init(ref->object);
}
static void
nouveau_ttm_mem_global_release(struct drm_global_reference *ref)
{
ttm_mem_global_release(ref->object);
}
int
nouveau_ttm_global_init(struct drm_nouveau_private *dev_priv)
{
struct drm_global_reference *global_ref;
int ret;
global_ref = &dev_priv->ttm.mem_global_ref;
global_ref->global_type = DRM_GLOBAL_TTM_MEM;
global_ref->size = sizeof(struct ttm_mem_global);
global_ref->init = &nouveau_ttm_mem_global_init;
global_ref->release = &nouveau_ttm_mem_global_release;
ret = drm_global_item_ref(global_ref);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed setting up TTM memory accounting\n");
dev_priv->ttm.mem_global_ref.release = NULL;
return ret;
}
dev_priv->ttm.bo_global_ref.mem_glob = global_ref->object;
global_ref = &dev_priv->ttm.bo_global_ref.ref;
global_ref->global_type = DRM_GLOBAL_TTM_BO;
global_ref->size = sizeof(struct ttm_bo_global);
global_ref->init = &ttm_bo_global_init;
global_ref->release = &ttm_bo_global_release;
ret = drm_global_item_ref(global_ref);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed setting up TTM BO subsystem\n");
drm_global_item_unref(&dev_priv->ttm.mem_global_ref);
dev_priv->ttm.mem_global_ref.release = NULL;
return ret;
}
return 0;
}
void
nouveau_ttm_global_release(struct drm_nouveau_private *dev_priv)
{
if (dev_priv->ttm.mem_global_ref.release == NULL)
return;
drm_global_item_unref(&dev_priv->ttm.bo_global_ref.ref);
drm_global_item_unref(&dev_priv->ttm.mem_global_ref);
dev_priv->ttm.mem_global_ref.release = NULL;
}
