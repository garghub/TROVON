struct sg_table *nouveau_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
struct nouveau_bo *nvbo = nouveau_gem_object(obj);
int npages = nvbo->bo.num_pages;
return drm_prime_pages_to_sg(nvbo->bo.ttm->pages, npages);
}
void *nouveau_gem_prime_vmap(struct drm_gem_object *obj)
{
struct nouveau_bo *nvbo = nouveau_gem_object(obj);
int ret;
ret = ttm_bo_kmap(&nvbo->bo, 0, nvbo->bo.num_pages,
&nvbo->dma_buf_vmap);
if (ret)
return ERR_PTR(ret);
return nvbo->dma_buf_vmap.virtual;
}
void nouveau_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
struct nouveau_bo *nvbo = nouveau_gem_object(obj);
ttm_bo_kunmap(&nvbo->dma_buf_vmap);
}
struct drm_gem_object *nouveau_gem_prime_import_sg_table(struct drm_device *dev,
size_t size,
struct sg_table *sg)
{
struct nouveau_bo *nvbo;
u32 flags = 0;
int ret;
flags = TTM_PL_FLAG_TT;
ret = nouveau_bo_new(dev, size, 0, flags, 0, 0,
sg, &nvbo);
if (ret)
return ERR_PTR(ret);
nvbo->valid_domains = NOUVEAU_GEM_DOMAIN_GART;
nvbo->gem = drm_gem_object_alloc(dev, nvbo->bo.mem.size);
if (!nvbo->gem) {
nouveau_bo_ref(NULL, &nvbo);
return ERR_PTR(-ENOMEM);
}
nvbo->gem->driver_private = nvbo;
return nvbo->gem;
}
int nouveau_gem_prime_pin(struct drm_gem_object *obj)
{
struct nouveau_bo *nvbo = nouveau_gem_object(obj);
int ret = 0;
ret = nouveau_bo_pin(nvbo, TTM_PL_FLAG_TT);
if (ret)
return -EINVAL;
return 0;
}
