int psb_gem_init_object(struct drm_gem_object *obj)
{
return -EINVAL;
}
void psb_gem_free_object(struct drm_gem_object *obj)
{
struct gtt_range *gtt = container_of(obj, struct gtt_range, gem);
psb_gtt_free_range(obj->dev, gtt);
if (obj->map_list.map) {
struct drm_gem_mm *mm = obj->dev->mm_private;
struct drm_map_list *list = &obj->map_list;
drm_ht_remove_item(&mm->offset_hash, &list->hash);
drm_mm_put_block(list->file_offset_node);
kfree(list->map);
list->map = NULL;
}
drm_gem_object_release(obj);
}
int psb_gem_get_aperture(struct drm_device *dev, void *data,
struct drm_file *file)
{
return -EINVAL;
}
static int psb_gem_create_mmap_offset(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct drm_gem_mm *mm = dev->mm_private;
struct drm_map_list *list;
struct drm_local_map *map;
int ret;
list = &obj->map_list;
list->map = kzalloc(sizeof(struct drm_map_list), GFP_KERNEL);
if (list->map == NULL)
return -ENOMEM;
map = list->map;
map->type = _DRM_GEM;
map->size = obj->size;
map->handle =obj;
list->file_offset_node = drm_mm_search_free(&mm->offset_manager,
obj->size / PAGE_SIZE, 0, 0);
if (!list->file_offset_node) {
DRM_ERROR("failed to allocate offset for bo %d\n", obj->name);
ret = -ENOSPC;
goto free_it;
}
list->file_offset_node = drm_mm_get_block(list->file_offset_node,
obj->size / PAGE_SIZE, 0);
if (!list->file_offset_node) {
ret = -ENOMEM;
goto free_it;
}
list->hash.key = list->file_offset_node->start;
ret = drm_ht_insert_item(&mm->offset_hash, &list->hash);
if (ret) {
DRM_ERROR("failed to add to map hash\n");
goto free_mm;
}
return 0;
free_mm:
drm_mm_put_block(list->file_offset_node);
free_it:
kfree(list->map);
list->map = NULL;
return ret;
}
int psb_gem_dumb_map_gtt(struct drm_file *file, struct drm_device *dev,
uint32_t handle, uint64_t *offset)
{
int ret = 0;
struct drm_gem_object *obj;
if (!(dev->driver->driver_features & DRIVER_GEM))
return -ENODEV;
mutex_lock(&dev->struct_mutex);
obj = drm_gem_object_lookup(dev, file, handle);
if (obj == NULL) {
ret = -ENOENT;
goto unlock;
}
if (!obj->map_list.map) {
ret = psb_gem_create_mmap_offset(obj);
if (ret)
goto out;
}
*offset = (u64)obj->map_list.hash.key << PAGE_SHIFT;
out:
drm_gem_object_unreference(obj);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int psb_gem_create(struct drm_file *file,
struct drm_device *dev, uint64_t size, uint32_t *handlep)
{
struct gtt_range *r;
int ret;
u32 handle;
size = roundup(size, PAGE_SIZE);
r = psb_gtt_alloc_range(dev, size, "gem", 0);
if (r == NULL)
return -ENOSPC;
if (drm_gem_object_init(dev, &r->gem, size) != 0) {
psb_gtt_free_range(dev, r);
return -ENOMEM;
}
ret = drm_gem_handle_create(file, &r->gem, &handle);
if (ret) {
drm_gem_object_release(&r->gem);
psb_gtt_free_range(dev, r);
return ret;
}
drm_gem_object_unreference(&r->gem);
*handlep = handle;
return 0;
}
int psb_gem_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
args->pitch = ALIGN(args->width * ((args->bpp + 7) / 8), 64);
args->size = args->pitch * args->height;
return psb_gem_create(file, dev, args->size, &args->handle);
}
int psb_gem_dumb_destroy(struct drm_file *file, struct drm_device *dev,
uint32_t handle)
{
return drm_gem_handle_delete(file, handle);
}
int psb_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_gem_object *obj;
struct gtt_range *r;
int ret;
unsigned long pfn;
pgoff_t page_offset;
struct drm_device *dev;
obj = vma->vm_private_data;
dev = obj->dev;
r = container_of(obj, struct gtt_range, gem);
mutex_lock(&dev->struct_mutex);
if (r->mmapping == 0) {
ret = psb_gtt_pin(r);
if (ret < 0) {
DRM_ERROR("gma500: pin failed: %d\n", ret);
goto fail;
}
r->mmapping = 1;
}
page_offset = ((unsigned long) vmf->virtual_address - vma->vm_start)
>> PAGE_SHIFT;
pfn = (r->resource.start >> PAGE_SHIFT) + page_offset;
pr_debug("Object GTT base at %p\n", (void *)(r->resource.start));
pr_debug("Inserting %p pfn %lx, pa %lx\n", vmf->virtual_address,
pfn, pfn << PAGE_SHIFT);
ret = vm_insert_pfn(vma, (unsigned long)vmf->virtual_address, pfn);
fail:
mutex_unlock(&dev->struct_mutex);
switch (ret) {
case 0:
case -ERESTARTSYS:
case -EINTR:
return VM_FAULT_NOPAGE;
case -ENOMEM:
return VM_FAULT_OOM;
default:
return VM_FAULT_SIGBUS;
}
}
