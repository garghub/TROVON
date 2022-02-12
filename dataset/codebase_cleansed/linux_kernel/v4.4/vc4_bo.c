struct vc4_bo *vc4_bo_create(struct drm_device *dev, size_t size)
{
struct drm_gem_cma_object *cma_obj;
cma_obj = drm_gem_cma_create(dev, size);
if (IS_ERR(cma_obj))
return NULL;
else
return to_vc4_bo(&cma_obj->base);
}
int vc4_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
int min_pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
struct vc4_bo *bo = NULL;
int ret;
if (args->pitch < min_pitch)
args->pitch = min_pitch;
if (args->size < args->pitch * args->height)
args->size = args->pitch * args->height;
bo = vc4_bo_create(dev, roundup(args->size, PAGE_SIZE));
if (!bo)
return -ENOMEM;
ret = drm_gem_handle_create(file_priv, &bo->base.base, &args->handle);
drm_gem_object_unreference_unlocked(&bo->base.base);
return ret;
}
