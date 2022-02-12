int __drm_mode_object_add(struct drm_device *dev, struct drm_mode_object *obj,
uint32_t obj_type, bool register_obj,
void (*obj_free_cb)(struct kref *kref))
{
int ret;
mutex_lock(&dev->mode_config.idr_mutex);
ret = idr_alloc(&dev->mode_config.crtc_idr, register_obj ? obj : NULL, 1, 0, GFP_KERNEL);
if (ret >= 0) {
obj->id = ret;
obj->type = obj_type;
if (obj_free_cb) {
obj->free_cb = obj_free_cb;
kref_init(&obj->refcount);
}
}
mutex_unlock(&dev->mode_config.idr_mutex);
return ret < 0 ? ret : 0;
}
int drm_mode_object_add(struct drm_device *dev,
struct drm_mode_object *obj, uint32_t obj_type)
{
return __drm_mode_object_add(dev, obj, obj_type, true, NULL);
}
void drm_mode_object_register(struct drm_device *dev,
struct drm_mode_object *obj)
{
mutex_lock(&dev->mode_config.idr_mutex);
idr_replace(&dev->mode_config.crtc_idr, obj, obj->id);
mutex_unlock(&dev->mode_config.idr_mutex);
}
void drm_mode_object_unregister(struct drm_device *dev,
struct drm_mode_object *object)
{
mutex_lock(&dev->mode_config.idr_mutex);
if (object->id) {
idr_remove(&dev->mode_config.crtc_idr, object->id);
object->id = 0;
}
mutex_unlock(&dev->mode_config.idr_mutex);
}
struct drm_mode_object *__drm_mode_object_find(struct drm_device *dev,
uint32_t id, uint32_t type)
{
struct drm_mode_object *obj = NULL;
mutex_lock(&dev->mode_config.idr_mutex);
obj = idr_find(&dev->mode_config.crtc_idr, id);
if (obj && type != DRM_MODE_OBJECT_ANY && obj->type != type)
obj = NULL;
if (obj && obj->id != id)
obj = NULL;
if (obj && obj->free_cb) {
if (!kref_get_unless_zero(&obj->refcount))
obj = NULL;
}
mutex_unlock(&dev->mode_config.idr_mutex);
return obj;
}
struct drm_mode_object *drm_mode_object_find(struct drm_device *dev,
uint32_t id, uint32_t type)
{
struct drm_mode_object *obj = NULL;
obj = __drm_mode_object_find(dev, id, type);
return obj;
}
void drm_mode_object_put(struct drm_mode_object *obj)
{
if (obj->free_cb) {
DRM_DEBUG("OBJ ID: %d (%d)\n", obj->id, kref_read(&obj->refcount));
kref_put(&obj->refcount, obj->free_cb);
}
}
void drm_mode_object_get(struct drm_mode_object *obj)
{
if (obj->free_cb) {
DRM_DEBUG("OBJ ID: %d (%d)\n", obj->id, kref_read(&obj->refcount));
kref_get(&obj->refcount);
}
}
void drm_object_attach_property(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t init_val)
{
int count = obj->properties->count;
if (count == DRM_OBJECT_MAX_PROPERTY) {
WARN(1, "Failed to attach object property (type: 0x%x). Please "
"increase DRM_OBJECT_MAX_PROPERTY by 1 for each time "
"you see this message on the same object type.\n",
obj->type);
return;
}
obj->properties->properties[count] = property;
obj->properties->values[count] = init_val;
obj->properties->count++;
}
int drm_object_property_set_value(struct drm_mode_object *obj,
struct drm_property *property, uint64_t val)
{
int i;
WARN_ON(drm_drv_uses_atomic_modeset(property->dev) &&
!(property->flags & DRM_MODE_PROP_IMMUTABLE));
for (i = 0; i < obj->properties->count; i++) {
if (obj->properties->properties[i] == property) {
obj->properties->values[i] = val;
return 0;
}
}
return -EINVAL;
}
int __drm_object_property_get_value(struct drm_mode_object *obj,
struct drm_property *property, uint64_t *val)
{
int i;
if (drm_drv_uses_atomic_modeset(property->dev) &&
!(property->flags & DRM_MODE_PROP_IMMUTABLE))
return drm_atomic_get_property(obj, property, val);
for (i = 0; i < obj->properties->count; i++) {
if (obj->properties->properties[i] == property) {
*val = obj->properties->values[i];
return 0;
}
}
return -EINVAL;
}
int drm_object_property_get_value(struct drm_mode_object *obj,
struct drm_property *property, uint64_t *val)
{
WARN_ON(drm_drv_uses_atomic_modeset(property->dev));
return __drm_object_property_get_value(obj, property, val);
}
int drm_mode_object_get_properties(struct drm_mode_object *obj, bool atomic,
uint32_t __user *prop_ptr,
uint64_t __user *prop_values,
uint32_t *arg_count_props)
{
int i, ret, count;
for (i = 0, count = 0; i < obj->properties->count; i++) {
struct drm_property *prop = obj->properties->properties[i];
uint64_t val;
if ((prop->flags & DRM_MODE_PROP_ATOMIC) && !atomic)
continue;
if (*arg_count_props > count) {
ret = __drm_object_property_get_value(obj, prop, &val);
if (ret)
return ret;
if (put_user(prop->base.id, prop_ptr + count))
return -EFAULT;
if (put_user(val, prop_values + count))
return -EFAULT;
}
count++;
}
*arg_count_props = count;
return 0;
}
int drm_mode_obj_get_properties_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_obj_get_properties *arg = data;
struct drm_mode_object *obj;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
obj = drm_mode_object_find(dev, arg->obj_id, arg->obj_type);
if (!obj) {
ret = -ENOENT;
goto out;
}
if (!obj->properties) {
ret = -EINVAL;
goto out_unref;
}
ret = drm_mode_object_get_properties(obj, file_priv->atomic,
(uint32_t __user *)(unsigned long)(arg->props_ptr),
(uint64_t __user *)(unsigned long)(arg->prop_values_ptr),
&arg->count_props);
out_unref:
drm_mode_object_put(obj);
out:
drm_modeset_unlock_all(dev);
return ret;
}
struct drm_property *drm_mode_obj_find_prop_id(struct drm_mode_object *obj,
uint32_t prop_id)
{
int i;
for (i = 0; i < obj->properties->count; i++)
if (obj->properties->properties[i]->base.id == prop_id)
return obj->properties->properties[i];
return NULL;
}
static int set_property_legacy(struct drm_mode_object *obj,
struct drm_property *prop,
uint64_t prop_value)
{
struct drm_device *dev = prop->dev;
struct drm_mode_object *ref;
int ret = -EINVAL;
if (!drm_property_change_valid_get(prop, prop_value, &ref))
return -EINVAL;
drm_modeset_lock_all(dev);
switch (obj->type) {
case DRM_MODE_OBJECT_CONNECTOR:
ret = drm_mode_connector_set_obj_prop(obj, prop,
prop_value);
break;
case DRM_MODE_OBJECT_CRTC:
ret = drm_mode_crtc_set_obj_prop(obj, prop, prop_value);
break;
case DRM_MODE_OBJECT_PLANE:
ret = drm_mode_plane_set_obj_prop(obj_to_plane(obj),
prop, prop_value);
break;
}
drm_property_change_valid_put(prop, ref);
drm_modeset_unlock_all(dev);
return ret;
}
static int set_property_atomic(struct drm_mode_object *obj,
struct drm_property *prop,
uint64_t prop_value)
{
struct drm_device *dev = prop->dev;
struct drm_atomic_state *state;
struct drm_modeset_acquire_ctx ctx;
int ret;
drm_modeset_acquire_init(&ctx, 0);
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = &ctx;
retry:
if (prop == state->dev->mode_config.dpms_property) {
if (obj->type != DRM_MODE_OBJECT_CONNECTOR) {
ret = -EINVAL;
goto out;
}
ret = drm_atomic_connector_commit_dpms(state,
obj_to_connector(obj),
prop_value);
} else {
ret = drm_atomic_set_property(state, obj, prop, prop_value);
if (ret)
goto out;
ret = drm_atomic_commit(state);
}
out:
if (ret == -EDEADLK) {
drm_atomic_state_clear(state);
drm_modeset_backoff(&ctx);
goto retry;
}
drm_atomic_state_put(state);
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return ret;
}
int drm_mode_obj_set_property_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_obj_set_property *arg = data;
struct drm_mode_object *arg_obj;
struct drm_property *property;
int ret = -EINVAL;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
arg_obj = drm_mode_object_find(dev, arg->obj_id, arg->obj_type);
if (!arg_obj)
return -ENOENT;
if (!arg_obj->properties)
goto out_unref;
property = drm_mode_obj_find_prop_id(arg_obj, arg->prop_id);
if (!property)
goto out_unref;
if (drm_drv_uses_atomic_modeset(property->dev))
ret = set_property_atomic(arg_obj, property, arg->value);
else
ret = set_property_legacy(arg_obj, property, arg->value);
out_unref:
drm_mode_object_put(arg_obj);
return ret;
}
