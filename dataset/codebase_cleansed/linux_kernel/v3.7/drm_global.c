void drm_global_init(void)
{
int i;
for (i = 0; i < DRM_GLOBAL_NUM; ++i) {
struct drm_global_item *item = &glob[i];
mutex_init(&item->mutex);
item->object = NULL;
item->refcount = 0;
}
}
void drm_global_release(void)
{
int i;
for (i = 0; i < DRM_GLOBAL_NUM; ++i) {
struct drm_global_item *item = &glob[i];
BUG_ON(item->object != NULL);
BUG_ON(item->refcount != 0);
}
}
int drm_global_item_ref(struct drm_global_reference *ref)
{
int ret;
struct drm_global_item *item = &glob[ref->global_type];
void *object;
mutex_lock(&item->mutex);
if (item->refcount == 0) {
item->object = kzalloc(ref->size, GFP_KERNEL);
if (unlikely(item->object == NULL)) {
ret = -ENOMEM;
goto out_err;
}
ref->object = item->object;
ret = ref->init(ref);
if (unlikely(ret != 0))
goto out_err;
}
++item->refcount;
ref->object = item->object;
object = item->object;
mutex_unlock(&item->mutex);
return 0;
out_err:
mutex_unlock(&item->mutex);
item->object = NULL;
return ret;
}
void drm_global_item_unref(struct drm_global_reference *ref)
{
struct drm_global_item *item = &glob[ref->global_type];
mutex_lock(&item->mutex);
BUG_ON(item->refcount == 0);
BUG_ON(ref->object != item->object);
if (--item->refcount == 0) {
ref->release(ref);
item->object = NULL;
}
mutex_unlock(&item->mutex);
}
