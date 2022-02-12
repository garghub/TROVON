static int amdgpu_bo_list_create(struct amdgpu_fpriv *fpriv,
struct amdgpu_bo_list **result,
int *id)
{
int r;
*result = kzalloc(sizeof(struct amdgpu_bo_list), GFP_KERNEL);
if (!*result)
return -ENOMEM;
mutex_lock(&fpriv->bo_list_lock);
r = idr_alloc(&fpriv->bo_list_handles, *result,
1, 0, GFP_KERNEL);
if (r < 0) {
mutex_unlock(&fpriv->bo_list_lock);
kfree(*result);
return r;
}
*id = r;
mutex_init(&(*result)->lock);
(*result)->num_entries = 0;
(*result)->array = NULL;
mutex_lock(&(*result)->lock);
mutex_unlock(&fpriv->bo_list_lock);
return 0;
}
static void amdgpu_bo_list_destroy(struct amdgpu_fpriv *fpriv, int id)
{
struct amdgpu_bo_list *list;
mutex_lock(&fpriv->bo_list_lock);
list = idr_find(&fpriv->bo_list_handles, id);
if (list) {
mutex_lock(&list->lock);
idr_remove(&fpriv->bo_list_handles, id);
mutex_unlock(&list->lock);
amdgpu_bo_list_free(list);
}
mutex_unlock(&fpriv->bo_list_lock);
}
static int amdgpu_bo_list_set(struct amdgpu_device *adev,
struct drm_file *filp,
struct amdgpu_bo_list *list,
struct drm_amdgpu_bo_list_entry *info,
unsigned num_entries)
{
struct amdgpu_bo_list_entry *array;
struct amdgpu_bo *gds_obj = adev->gds.gds_gfx_bo;
struct amdgpu_bo *gws_obj = adev->gds.gws_gfx_bo;
struct amdgpu_bo *oa_obj = adev->gds.oa_gfx_bo;
unsigned last_entry = 0, first_userptr = num_entries;
unsigned i;
int r;
unsigned long total_size = 0;
array = drm_malloc_ab(num_entries, sizeof(struct amdgpu_bo_list_entry));
if (!array)
return -ENOMEM;
memset(array, 0, num_entries * sizeof(struct amdgpu_bo_list_entry));
for (i = 0; i < num_entries; ++i) {
struct amdgpu_bo_list_entry *entry;
struct drm_gem_object *gobj;
struct amdgpu_bo *bo;
struct mm_struct *usermm;
gobj = drm_gem_object_lookup(filp, info[i].bo_handle);
if (!gobj) {
r = -ENOENT;
goto error_free;
}
bo = amdgpu_bo_ref(gem_to_amdgpu_bo(gobj));
drm_gem_object_unreference_unlocked(gobj);
usermm = amdgpu_ttm_tt_get_usermm(bo->tbo.ttm);
if (usermm) {
if (usermm != current->mm) {
amdgpu_bo_unref(&bo);
r = -EPERM;
goto error_free;
}
entry = &array[--first_userptr];
} else {
entry = &array[last_entry++];
}
entry->robj = bo;
entry->priority = min(info[i].bo_priority,
AMDGPU_BO_LIST_MAX_PRIORITY);
entry->tv.bo = &entry->robj->tbo;
entry->tv.shared = true;
if (entry->robj->prefered_domains == AMDGPU_GEM_DOMAIN_GDS)
gds_obj = entry->robj;
if (entry->robj->prefered_domains == AMDGPU_GEM_DOMAIN_GWS)
gws_obj = entry->robj;
if (entry->robj->prefered_domains == AMDGPU_GEM_DOMAIN_OA)
oa_obj = entry->robj;
total_size += amdgpu_bo_size(entry->robj);
trace_amdgpu_bo_list_set(list, entry->robj);
}
for (i = 0; i < list->num_entries; ++i)
amdgpu_bo_unref(&list->array[i].robj);
drm_free_large(list->array);
list->gds_obj = gds_obj;
list->gws_obj = gws_obj;
list->oa_obj = oa_obj;
list->first_userptr = first_userptr;
list->array = array;
list->num_entries = num_entries;
trace_amdgpu_cs_bo_status(list->num_entries, total_size);
return 0;
error_free:
while (i--)
amdgpu_bo_unref(&array[i].robj);
drm_free_large(array);
return r;
}
struct amdgpu_bo_list *
amdgpu_bo_list_get(struct amdgpu_fpriv *fpriv, int id)
{
struct amdgpu_bo_list *result;
mutex_lock(&fpriv->bo_list_lock);
result = idr_find(&fpriv->bo_list_handles, id);
if (result)
mutex_lock(&result->lock);
mutex_unlock(&fpriv->bo_list_lock);
return result;
}
void amdgpu_bo_list_get_list(struct amdgpu_bo_list *list,
struct list_head *validated)
{
struct list_head bucket[AMDGPU_BO_LIST_NUM_BUCKETS];
unsigned i;
for (i = 0; i < AMDGPU_BO_LIST_NUM_BUCKETS; i++)
INIT_LIST_HEAD(&bucket[i]);
for (i = 0; i < list->num_entries; i++) {
unsigned priority = list->array[i].priority;
list_add_tail(&list->array[i].tv.head,
&bucket[priority]);
list->array[i].user_pages = NULL;
}
for (i = 0; i < AMDGPU_BO_LIST_NUM_BUCKETS; i++)
list_splice(&bucket[i], validated);
}
void amdgpu_bo_list_put(struct amdgpu_bo_list *list)
{
mutex_unlock(&list->lock);
}
void amdgpu_bo_list_free(struct amdgpu_bo_list *list)
{
unsigned i;
for (i = 0; i < list->num_entries; ++i)
amdgpu_bo_unref(&list->array[i].robj);
mutex_destroy(&list->lock);
drm_free_large(list->array);
kfree(list);
}
int amdgpu_bo_list_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
const uint32_t info_size = sizeof(struct drm_amdgpu_bo_list_entry);
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_fpriv *fpriv = filp->driver_priv;
union drm_amdgpu_bo_list *args = data;
uint32_t handle = args->in.list_handle;
const void __user *uptr = (const void*)(long)args->in.bo_info_ptr;
struct drm_amdgpu_bo_list_entry *info;
struct amdgpu_bo_list *list;
int r;
info = drm_malloc_ab(args->in.bo_number,
sizeof(struct drm_amdgpu_bo_list_entry));
if (!info)
return -ENOMEM;
r = -EFAULT;
if (likely(info_size == args->in.bo_info_size)) {
unsigned long bytes = args->in.bo_number *
args->in.bo_info_size;
if (copy_from_user(info, uptr, bytes))
goto error_free;
} else {
unsigned long bytes = min(args->in.bo_info_size, info_size);
unsigned i;
memset(info, 0, args->in.bo_number * info_size);
for (i = 0; i < args->in.bo_number; ++i) {
if (copy_from_user(&info[i], uptr, bytes))
goto error_free;
uptr += args->in.bo_info_size;
}
}
switch (args->in.operation) {
case AMDGPU_BO_LIST_OP_CREATE:
r = amdgpu_bo_list_create(fpriv, &list, &handle);
if (r)
goto error_free;
r = amdgpu_bo_list_set(adev, filp, list, info,
args->in.bo_number);
amdgpu_bo_list_put(list);
if (r)
goto error_free;
break;
case AMDGPU_BO_LIST_OP_DESTROY:
amdgpu_bo_list_destroy(fpriv, handle);
handle = 0;
break;
case AMDGPU_BO_LIST_OP_UPDATE:
r = -ENOENT;
list = amdgpu_bo_list_get(fpriv, handle);
if (!list)
goto error_free;
r = amdgpu_bo_list_set(adev, filp, list, info,
args->in.bo_number);
amdgpu_bo_list_put(list);
if (r)
goto error_free;
break;
default:
r = -EINVAL;
goto error_free;
}
memset(args, 0, sizeof(*args));
args->out.list_handle = handle;
drm_free_large(info);
return 0;
error_free:
drm_free_large(info);
return r;
}
