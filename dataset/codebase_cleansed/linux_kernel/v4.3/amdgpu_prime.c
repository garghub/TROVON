struct sg_table *amdgpu_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
int npages = bo->tbo.num_pages;
return drm_prime_pages_to_sg(bo->tbo.ttm->pages, npages);
}
void *amdgpu_gem_prime_vmap(struct drm_gem_object *obj)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
int ret;
ret = ttm_bo_kmap(&bo->tbo, 0, bo->tbo.num_pages,
&bo->dma_buf_vmap);
if (ret)
return ERR_PTR(ret);
return bo->dma_buf_vmap.virtual;
}
void amdgpu_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
ttm_bo_kunmap(&bo->dma_buf_vmap);
}
struct drm_gem_object *amdgpu_gem_prime_import_sg_table(struct drm_device *dev,
struct dma_buf_attachment *attach,
struct sg_table *sg)
{
struct reservation_object *resv = attach->dmabuf->resv;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_bo *bo;
int ret;
ww_mutex_lock(&resv->lock, NULL);
ret = amdgpu_bo_create(adev, attach->dmabuf->size, PAGE_SIZE, false,
AMDGPU_GEM_DOMAIN_GTT, 0, sg, resv, &bo);
ww_mutex_unlock(&resv->lock);
if (ret)
return ERR_PTR(ret);
mutex_lock(&adev->gem.mutex);
list_add_tail(&bo->list, &adev->gem.objects);
mutex_unlock(&adev->gem.mutex);
return &bo->gem_base;
}
int amdgpu_gem_prime_pin(struct drm_gem_object *obj)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
int ret = 0;
ret = amdgpu_bo_reserve(bo, false);
if (unlikely(ret != 0))
return ret;
ret = amdgpu_bo_pin(bo, AMDGPU_GEM_DOMAIN_GTT, NULL);
amdgpu_bo_unreserve(bo);
return ret;
}
void amdgpu_gem_prime_unpin(struct drm_gem_object *obj)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
int ret = 0;
ret = amdgpu_bo_reserve(bo, false);
if (unlikely(ret != 0))
return;
amdgpu_bo_unpin(bo);
amdgpu_bo_unreserve(bo);
}
struct reservation_object *amdgpu_gem_prime_res_obj(struct drm_gem_object *obj)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(obj);
return bo->tbo.resv;
}
struct dma_buf *amdgpu_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *gobj,
int flags)
{
struct amdgpu_bo *bo = gem_to_amdgpu_bo(gobj);
if (amdgpu_ttm_tt_has_userptr(bo->tbo.ttm))
return ERR_PTR(-EPERM);
return drm_gem_prime_export(dev, gobj, flags);
}
