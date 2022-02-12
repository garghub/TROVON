static bool drm_property_type_valid(struct drm_property *property)
{
if (property->flags & DRM_MODE_PROP_EXTENDED_TYPE)
return !(property->flags & DRM_MODE_PROP_LEGACY_TYPE);
return !!(property->flags & DRM_MODE_PROP_LEGACY_TYPE);
}
struct drm_property *drm_property_create(struct drm_device *dev, int flags,
const char *name, int num_values)
{
struct drm_property *property = NULL;
int ret;
property = kzalloc(sizeof(struct drm_property), GFP_KERNEL);
if (!property)
return NULL;
property->dev = dev;
if (num_values) {
property->values = kcalloc(num_values, sizeof(uint64_t),
GFP_KERNEL);
if (!property->values)
goto fail;
}
ret = drm_mode_object_get(dev, &property->base, DRM_MODE_OBJECT_PROPERTY);
if (ret)
goto fail;
property->flags = flags;
property->num_values = num_values;
INIT_LIST_HEAD(&property->enum_list);
if (name) {
strncpy(property->name, name, DRM_PROP_NAME_LEN);
property->name[DRM_PROP_NAME_LEN-1] = '\0';
}
list_add_tail(&property->head, &dev->mode_config.property_list);
WARN_ON(!drm_property_type_valid(property));
return property;
fail:
kfree(property->values);
kfree(property);
return NULL;
}
struct drm_property *drm_property_create_enum(struct drm_device *dev, int flags,
const char *name,
const struct drm_prop_enum_list *props,
int num_values)
{
struct drm_property *property;
int i, ret;
flags |= DRM_MODE_PROP_ENUM;
property = drm_property_create(dev, flags, name, num_values);
if (!property)
return NULL;
for (i = 0; i < num_values; i++) {
ret = drm_property_add_enum(property, i,
props[i].type,
props[i].name);
if (ret) {
drm_property_destroy(dev, property);
return NULL;
}
}
return property;
}
struct drm_property *drm_property_create_bitmask(struct drm_device *dev,
int flags, const char *name,
const struct drm_prop_enum_list *props,
int num_props,
uint64_t supported_bits)
{
struct drm_property *property;
int i, ret, index = 0;
int num_values = hweight64(supported_bits);
flags |= DRM_MODE_PROP_BITMASK;
property = drm_property_create(dev, flags, name, num_values);
if (!property)
return NULL;
for (i = 0; i < num_props; i++) {
if (!(supported_bits & (1ULL << props[i].type)))
continue;
if (WARN_ON(index >= num_values)) {
drm_property_destroy(dev, property);
return NULL;
}
ret = drm_property_add_enum(property, index++,
props[i].type,
props[i].name);
if (ret) {
drm_property_destroy(dev, property);
return NULL;
}
}
return property;
}
static struct drm_property *property_create_range(struct drm_device *dev,
int flags, const char *name,
uint64_t min, uint64_t max)
{
struct drm_property *property;
property = drm_property_create(dev, flags, name, 2);
if (!property)
return NULL;
property->values[0] = min;
property->values[1] = max;
return property;
}
struct drm_property *drm_property_create_range(struct drm_device *dev, int flags,
const char *name,
uint64_t min, uint64_t max)
{
return property_create_range(dev, DRM_MODE_PROP_RANGE | flags,
name, min, max);
}
struct drm_property *drm_property_create_signed_range(struct drm_device *dev,
int flags, const char *name,
int64_t min, int64_t max)
{
return property_create_range(dev, DRM_MODE_PROP_SIGNED_RANGE | flags,
name, I642U64(min), I642U64(max));
}
struct drm_property *drm_property_create_object(struct drm_device *dev,
int flags, const char *name,
uint32_t type)
{
struct drm_property *property;
flags |= DRM_MODE_PROP_OBJECT;
if (WARN_ON(!(flags & DRM_MODE_PROP_ATOMIC)))
return NULL;
property = drm_property_create(dev, flags, name, 1);
if (!property)
return NULL;
property->values[0] = type;
return property;
}
struct drm_property *drm_property_create_bool(struct drm_device *dev, int flags,
const char *name)
{
return drm_property_create_range(dev, flags, name, 0, 1);
}
int drm_property_add_enum(struct drm_property *property, int index,
uint64_t value, const char *name)
{
struct drm_property_enum *prop_enum;
if (!(drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)))
return -EINVAL;
if (drm_property_type_is(property, DRM_MODE_PROP_BITMASK) &&
(value > 63))
return -EINVAL;
if (!list_empty(&property->enum_list)) {
list_for_each_entry(prop_enum, &property->enum_list, head) {
if (prop_enum->value == value) {
strncpy(prop_enum->name, name, DRM_PROP_NAME_LEN);
prop_enum->name[DRM_PROP_NAME_LEN-1] = '\0';
return 0;
}
}
}
prop_enum = kzalloc(sizeof(struct drm_property_enum), GFP_KERNEL);
if (!prop_enum)
return -ENOMEM;
strncpy(prop_enum->name, name, DRM_PROP_NAME_LEN);
prop_enum->name[DRM_PROP_NAME_LEN-1] = '\0';
prop_enum->value = value;
property->values[index] = value;
list_add_tail(&prop_enum->head, &property->enum_list);
return 0;
}
void drm_property_destroy(struct drm_device *dev, struct drm_property *property)
{
struct drm_property_enum *prop_enum, *pt;
list_for_each_entry_safe(prop_enum, pt, &property->enum_list, head) {
list_del(&prop_enum->head);
kfree(prop_enum);
}
if (property->num_values)
kfree(property->values);
drm_mode_object_unregister(dev, &property->base);
list_del(&property->head);
kfree(property);
}
int drm_mode_getproperty_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_get_property *out_resp = data;
struct drm_property *property;
int enum_count = 0;
int value_count = 0;
int ret = 0, i;
int copied;
struct drm_property_enum *prop_enum;
struct drm_mode_property_enum __user *enum_ptr;
uint64_t __user *values_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
property = drm_property_find(dev, out_resp->prop_id);
if (!property) {
ret = -ENOENT;
goto done;
}
if (drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
list_for_each_entry(prop_enum, &property->enum_list, head)
enum_count++;
}
value_count = property->num_values;
strncpy(out_resp->name, property->name, DRM_PROP_NAME_LEN);
out_resp->name[DRM_PROP_NAME_LEN-1] = 0;
out_resp->flags = property->flags;
if ((out_resp->count_values >= value_count) && value_count) {
values_ptr = (uint64_t __user *)(unsigned long)out_resp->values_ptr;
for (i = 0; i < value_count; i++) {
if (copy_to_user(values_ptr + i, &property->values[i], sizeof(uint64_t))) {
ret = -EFAULT;
goto done;
}
}
}
out_resp->count_values = value_count;
if (drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
if ((out_resp->count_enum_blobs >= enum_count) && enum_count) {
copied = 0;
enum_ptr = (struct drm_mode_property_enum __user *)(unsigned long)out_resp->enum_blob_ptr;
list_for_each_entry(prop_enum, &property->enum_list, head) {
if (copy_to_user(&enum_ptr[copied].value, &prop_enum->value, sizeof(uint64_t))) {
ret = -EFAULT;
goto done;
}
if (copy_to_user(&enum_ptr[copied].name,
&prop_enum->name, DRM_PROP_NAME_LEN)) {
ret = -EFAULT;
goto done;
}
copied++;
}
}
out_resp->count_enum_blobs = enum_count;
}
if (drm_property_type_is(property, DRM_MODE_PROP_BLOB))
out_resp->count_enum_blobs = 0;
done:
drm_modeset_unlock_all(dev);
return ret;
}
static void drm_property_free_blob(struct kref *kref)
{
struct drm_property_blob *blob =
container_of(kref, struct drm_property_blob, base.refcount);
mutex_lock(&blob->dev->mode_config.blob_lock);
list_del(&blob->head_global);
mutex_unlock(&blob->dev->mode_config.blob_lock);
drm_mode_object_unregister(blob->dev, &blob->base);
kfree(blob);
}
struct drm_property_blob *
drm_property_create_blob(struct drm_device *dev, size_t length,
const void *data)
{
struct drm_property_blob *blob;
int ret;
if (!length || length > ULONG_MAX - sizeof(struct drm_property_blob))
return ERR_PTR(-EINVAL);
blob = kzalloc(sizeof(struct drm_property_blob)+length, GFP_KERNEL);
if (!blob)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&blob->head_file);
blob->length = length;
blob->dev = dev;
if (data)
memcpy(blob->data, data, length);
ret = drm_mode_object_get_reg(dev, &blob->base, DRM_MODE_OBJECT_BLOB,
true, drm_property_free_blob);
if (ret) {
kfree(blob);
return ERR_PTR(-EINVAL);
}
mutex_lock(&dev->mode_config.blob_lock);
list_add_tail(&blob->head_global,
&dev->mode_config.property_blob_list);
mutex_unlock(&dev->mode_config.blob_lock);
return blob;
}
void drm_property_unreference_blob(struct drm_property_blob *blob)
{
if (!blob)
return;
drm_mode_object_unreference(&blob->base);
}
void drm_property_destroy_user_blobs(struct drm_device *dev,
struct drm_file *file_priv)
{
struct drm_property_blob *blob, *bt;
list_for_each_entry_safe(blob, bt, &file_priv->blobs, head_file) {
list_del_init(&blob->head_file);
drm_property_unreference_blob(blob);
}
}
struct drm_property_blob *drm_property_reference_blob(struct drm_property_blob *blob)
{
drm_mode_object_reference(&blob->base);
return blob;
}
struct drm_property_blob *drm_property_lookup_blob(struct drm_device *dev,
uint32_t id)
{
struct drm_mode_object *obj;
struct drm_property_blob *blob = NULL;
obj = __drm_mode_object_find(dev, id, DRM_MODE_OBJECT_BLOB);
if (obj)
blob = obj_to_blob(obj);
return blob;
}
int drm_property_replace_global_blob(struct drm_device *dev,
struct drm_property_blob **replace,
size_t length,
const void *data,
struct drm_mode_object *obj_holds_id,
struct drm_property *prop_holds_id)
{
struct drm_property_blob *new_blob = NULL;
struct drm_property_blob *old_blob = NULL;
int ret;
WARN_ON(replace == NULL);
old_blob = *replace;
if (length && data) {
new_blob = drm_property_create_blob(dev, length, data);
if (IS_ERR(new_blob))
return PTR_ERR(new_blob);
}
if (obj_holds_id) {
ret = drm_object_property_set_value(obj_holds_id,
prop_holds_id,
new_blob ?
new_blob->base.id : 0);
if (ret != 0)
goto err_created;
}
drm_property_unreference_blob(old_blob);
*replace = new_blob;
return 0;
err_created:
drm_property_unreference_blob(new_blob);
return ret;
}
int drm_mode_getblob_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_get_blob *out_resp = data;
struct drm_property_blob *blob;
int ret = 0;
void __user *blob_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
blob = drm_property_lookup_blob(dev, out_resp->blob_id);
if (!blob)
return -ENOENT;
if (out_resp->length == blob->length) {
blob_ptr = (void __user *)(unsigned long)out_resp->data;
if (copy_to_user(blob_ptr, blob->data, blob->length)) {
ret = -EFAULT;
goto unref;
}
}
out_resp->length = blob->length;
unref:
drm_property_unreference_blob(blob);
return ret;
}
int drm_mode_createblob_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_create_blob *out_resp = data;
struct drm_property_blob *blob;
void __user *blob_ptr;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
blob = drm_property_create_blob(dev, out_resp->length, NULL);
if (IS_ERR(blob))
return PTR_ERR(blob);
blob_ptr = (void __user *)(unsigned long)out_resp->data;
if (copy_from_user(blob->data, blob_ptr, out_resp->length)) {
ret = -EFAULT;
goto out_blob;
}
mutex_lock(&dev->mode_config.blob_lock);
out_resp->blob_id = blob->base.id;
list_add_tail(&blob->head_file, &file_priv->blobs);
mutex_unlock(&dev->mode_config.blob_lock);
return 0;
out_blob:
drm_property_unreference_blob(blob);
return ret;
}
int drm_mode_destroyblob_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_destroy_blob *out_resp = data;
struct drm_property_blob *blob = NULL, *bt;
bool found = false;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
blob = drm_property_lookup_blob(dev, out_resp->blob_id);
if (!blob)
return -ENOENT;
mutex_lock(&dev->mode_config.blob_lock);
list_for_each_entry(bt, &file_priv->blobs, head_file) {
if (bt == blob) {
found = true;
break;
}
}
if (!found) {
ret = -EPERM;
goto err;
}
list_del_init(&blob->head_file);
mutex_unlock(&dev->mode_config.blob_lock);
drm_property_unreference_blob(blob);
drm_property_unreference_blob(blob);
return 0;
err:
mutex_unlock(&dev->mode_config.blob_lock);
drm_property_unreference_blob(blob);
return ret;
}
bool drm_property_change_valid_get(struct drm_property *property,
uint64_t value, struct drm_mode_object **ref)
{
int i;
if (property->flags & DRM_MODE_PROP_IMMUTABLE)
return false;
*ref = NULL;
if (drm_property_type_is(property, DRM_MODE_PROP_RANGE)) {
if (value < property->values[0] || value > property->values[1])
return false;
return true;
} else if (drm_property_type_is(property, DRM_MODE_PROP_SIGNED_RANGE)) {
int64_t svalue = U642I64(value);
if (svalue < U642I64(property->values[0]) ||
svalue > U642I64(property->values[1]))
return false;
return true;
} else if (drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
uint64_t valid_mask = 0;
for (i = 0; i < property->num_values; i++)
valid_mask |= (1ULL << property->values[i]);
return !(value & ~valid_mask);
} else if (drm_property_type_is(property, DRM_MODE_PROP_BLOB)) {
struct drm_property_blob *blob;
if (value == 0)
return true;
blob = drm_property_lookup_blob(property->dev, value);
if (blob) {
*ref = &blob->base;
return true;
} else {
return false;
}
} else if (drm_property_type_is(property, DRM_MODE_PROP_OBJECT)) {
if (value == 0)
return true;
*ref = __drm_mode_object_find(property->dev, value,
property->values[0]);
return *ref != NULL;
}
for (i = 0; i < property->num_values; i++)
if (property->values[i] == value)
return true;
return false;
}
void drm_property_change_valid_put(struct drm_property *property,
struct drm_mode_object *ref)
{
if (!ref)
return;
if (drm_property_type_is(property, DRM_MODE_PROP_OBJECT)) {
drm_mode_object_unreference(ref);
} else if (drm_property_type_is(property, DRM_MODE_PROP_BLOB))
drm_property_unreference_blob(obj_to_blob(ref));
}
