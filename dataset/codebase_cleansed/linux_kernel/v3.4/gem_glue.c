void drm_gem_object_release_wrap(struct drm_gem_object *obj)
{
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
int gem_create_mmap_offset(struct drm_gem_object *obj)
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
map->handle = obj;
list->file_offset_node = drm_mm_search_free(&mm->offset_manager,
obj->size / PAGE_SIZE, 0, 0);
if (!list->file_offset_node) {
dev_err(dev->dev, "failed to allocate offset for bo %d\n",
obj->name);
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
dev_err(dev->dev, "failed to add to map hash\n");
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
