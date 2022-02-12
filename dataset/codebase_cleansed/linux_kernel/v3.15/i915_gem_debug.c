int
i915_verify_lists(struct drm_device *dev)
{
static int warned;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
int err = 0;
if (warned)
return 0;
list_for_each_entry(obj, &dev_priv->render_ring.active_list, list) {
if (obj->base.dev != dev ||
!atomic_read(&obj->base.refcount.refcount)) {
DRM_ERROR("freed render active %p\n", obj);
err++;
break;
} else if (!obj->active ||
(obj->base.read_domains & I915_GEM_GPU_DOMAINS) == 0) {
DRM_ERROR("invalid render active %p (a %d r %x)\n",
obj,
obj->active,
obj->base.read_domains);
err++;
} else if (obj->base.write_domain && list_empty(&obj->gpu_write_list)) {
DRM_ERROR("invalid render active %p (w %x, gwl %d)\n",
obj,
obj->base.write_domain,
!list_empty(&obj->gpu_write_list));
err++;
}
}
list_for_each_entry(obj, &dev_priv->mm.flushing_list, list) {
if (obj->base.dev != dev ||
!atomic_read(&obj->base.refcount.refcount)) {
DRM_ERROR("freed flushing %p\n", obj);
err++;
break;
} else if (!obj->active ||
(obj->base.write_domain & I915_GEM_GPU_DOMAINS) == 0 ||
list_empty(&obj->gpu_write_list)) {
DRM_ERROR("invalid flushing %p (a %d w %x gwl %d)\n",
obj,
obj->active,
obj->base.write_domain,
!list_empty(&obj->gpu_write_list));
err++;
}
}
list_for_each_entry(obj, &dev_priv->mm.gpu_write_list, gpu_write_list) {
if (obj->base.dev != dev ||
!atomic_read(&obj->base.refcount.refcount)) {
DRM_ERROR("freed gpu write %p\n", obj);
err++;
break;
} else if (!obj->active ||
(obj->base.write_domain & I915_GEM_GPU_DOMAINS) == 0) {
DRM_ERROR("invalid gpu write %p (a %d w %x)\n",
obj,
obj->active,
obj->base.write_domain);
err++;
}
}
list_for_each_entry(obj, &i915_gtt_vm->inactive_list, list) {
if (obj->base.dev != dev ||
!atomic_read(&obj->base.refcount.refcount)) {
DRM_ERROR("freed inactive %p\n", obj);
err++;
break;
} else if (obj->pin_count || obj->active ||
(obj->base.write_domain & I915_GEM_GPU_DOMAINS)) {
DRM_ERROR("invalid inactive %p (p %d a %d w %x)\n",
obj,
obj->pin_count, obj->active,
obj->base.write_domain);
err++;
}
}
return warned = err;
}
