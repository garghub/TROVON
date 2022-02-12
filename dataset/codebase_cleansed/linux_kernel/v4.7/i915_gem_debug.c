int
i915_verify_lists(struct drm_device *dev)
{
static int warned;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj;
struct intel_engine_cs *engine;
int err = 0;
if (warned)
return 0;
for_each_engine(engine, dev_priv) {
list_for_each_entry(obj, &engine->active_list,
engine_list[engine->id]) {
if (obj->base.dev != dev ||
!atomic_read(&obj->base.refcount.refcount)) {
DRM_ERROR("%s: freed active obj %p\n",
engine->name, obj);
err++;
break;
} else if (!obj->active ||
obj->last_read_req[engine->id] == NULL) {
DRM_ERROR("%s: invalid active obj %p\n",
engine->name, obj);
err++;
} else if (obj->base.write_domain) {
DRM_ERROR("%s: invalid write obj %p (w %x)\n",
engine->name,
obj, obj->base.write_domain);
err++;
}
}
}
return warned = err;
}
