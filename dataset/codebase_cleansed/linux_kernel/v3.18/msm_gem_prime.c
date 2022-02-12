struct sg_table *msm_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
BUG_ON(!msm_obj->sgt);
return msm_obj->sgt;
}
void *msm_gem_prime_vmap(struct drm_gem_object *obj)
{
return msm_gem_vaddr(obj);
}
void msm_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
}
struct drm_gem_object *msm_gem_prime_import_sg_table(struct drm_device *dev,
struct dma_buf_attachment *attach, struct sg_table *sg)
{
return msm_gem_import(dev, attach->dmabuf->size, sg);
}
int msm_gem_prime_pin(struct drm_gem_object *obj)
{
if (!obj->import_attach)
msm_gem_get_pages(obj);
return 0;
}
void msm_gem_prime_unpin(struct drm_gem_object *obj)
{
if (!obj->import_attach)
msm_gem_put_pages(obj);
}
