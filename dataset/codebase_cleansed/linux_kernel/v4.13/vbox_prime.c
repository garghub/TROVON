int vbox_gem_prime_pin(struct drm_gem_object *obj)
{
WARN_ONCE(1, "not implemented");
return -ENOSYS;
}
void vbox_gem_prime_unpin(struct drm_gem_object *obj)
{
WARN_ONCE(1, "not implemented");
}
struct sg_table *vbox_gem_prime_get_sg_table(struct drm_gem_object *obj)
{
WARN_ONCE(1, "not implemented");
return ERR_PTR(-ENOSYS);
}
struct drm_gem_object *vbox_gem_prime_import_sg_table(
struct drm_device *dev, struct dma_buf_attachment *attach,
struct sg_table *table)
{
WARN_ONCE(1, "not implemented");
return ERR_PTR(-ENOSYS);
}
void *vbox_gem_prime_vmap(struct drm_gem_object *obj)
{
WARN_ONCE(1, "not implemented");
return ERR_PTR(-ENOSYS);
}
void vbox_gem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
WARN_ONCE(1, "not implemented");
}
int vbox_gem_prime_mmap(struct drm_gem_object *obj, struct vm_area_struct *area)
{
WARN_ONCE(1, "not implemented");
return -ENOSYS;
}
