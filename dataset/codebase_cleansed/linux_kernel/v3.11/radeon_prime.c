struct sg_table *radeon_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
struct radeon_bo *bo = gem_to_radeon_bo(obj);
int npages = bo->tbo.num_pages;
return drm_prime_pages_to_sg(bo->tbo.ttm->pages, npages);
}
void *radeon_gem_prime_vmap(struct drm_gem_object *obj)
{
struct radeon_bo *bo = gem_to_radeon_bo(obj);
int ret;
ret = ttm_bo_kmap(&bo->tbo, 0, bo->tbo.num_pages,
&bo->dma_buf_vmap);
if (ret)
return ERR_PTR(ret);
return bo->dma_buf_vmap.virtual;
}
void radeon_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
struct radeon_bo *bo = gem_to_radeon_bo(obj);
ttm_bo_kunmap(&bo->dma_buf_vmap);
}
struct drm_gem_object *radeon_gem_prime_import_sg_table(struct drm_device *dev,
size_t size,
struct sg_table *sg)
{
struct radeon_device *rdev = dev->dev_private;
struct radeon_bo *bo;
int ret;
ret = radeon_bo_create(rdev, size, PAGE_SIZE, false,
RADEON_GEM_DOMAIN_GTT, sg, &bo);
if (ret)
return ERR_PTR(ret);
bo->gem_base.driver_private = bo;
mutex_lock(&rdev->gem.mutex);
list_add_tail(&bo->list, &rdev->gem.objects);
mutex_unlock(&rdev->gem.mutex);
return &bo->gem_base;
}
int radeon_gem_prime_pin(struct drm_gem_object *obj)
{
struct radeon_bo *bo = gem_to_radeon_bo(obj);
int ret = 0;
ret = radeon_bo_reserve(bo, false);
if (unlikely(ret != 0))
return ret;
ret = radeon_bo_pin(bo, RADEON_GEM_DOMAIN_GTT, NULL);
radeon_bo_unreserve(bo);
return ret;
}
void radeon_gem_prime_unpin(struct drm_gem_object *obj)
{
struct radeon_bo *bo = gem_to_radeon_bo(obj);
int ret = 0;
ret = radeon_bo_reserve(bo, false);
if (unlikely(ret != 0))
return;
radeon_bo_unpin(bo);
radeon_bo_unreserve(bo);
}
