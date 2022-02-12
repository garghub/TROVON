struct page **_drm_gem_get_pages(struct drm_gem_object *obj, gfp_t gfpmask)
{
struct inode *inode;
struct address_space *mapping;
struct page *p, **pages;
int i, npages;
inode = file_inode(obj->filp);
mapping = inode->i_mapping;
npages = obj->size >> PAGE_SHIFT;
pages = drm_malloc_ab(npages, sizeof(struct page *));
if (pages == NULL)
return ERR_PTR(-ENOMEM);
gfpmask |= mapping_gfp_mask(mapping);
for (i = 0; i < npages; i++) {
p = shmem_read_mapping_page_gfp(mapping, i, gfpmask);
if (IS_ERR(p))
goto fail;
pages[i] = p;
BUG_ON((gfpmask & __GFP_DMA32) &&
(page_to_pfn(p) >= 0x00100000UL));
}
return pages;
fail:
while (i--)
page_cache_release(pages[i]);
drm_free_large(pages);
return ERR_CAST(p);
}
void _drm_gem_put_pages(struct drm_gem_object *obj, struct page **pages,
bool dirty, bool accessed)
{
int i, npages;
npages = obj->size >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
if (dirty)
set_page_dirty(pages[i]);
if (accessed)
mark_page_accessed(pages[i]);
page_cache_release(pages[i]);
}
drm_free_large(pages);
}
int
_drm_gem_create_mmap_offset_size(struct drm_gem_object *obj, size_t size)
{
struct drm_device *dev = obj->dev;
struct drm_gem_mm *mm = dev->mm_private;
struct drm_map_list *list;
struct drm_local_map *map;
int ret = 0;
list = &obj->map_list;
list->map = kzalloc(sizeof(struct drm_map_list), GFP_KERNEL);
if (!list->map)
return -ENOMEM;
map = list->map;
map->type = _DRM_GEM;
map->size = size;
map->handle = obj;
list->file_offset_node = drm_mm_search_free(&mm->offset_manager,
size / PAGE_SIZE, 0, 0);
if (!list->file_offset_node) {
DRM_ERROR("failed to allocate offset for bo %d\n", obj->name);
ret = -ENOSPC;
goto out_free_list;
}
list->file_offset_node = drm_mm_get_block(list->file_offset_node,
size / PAGE_SIZE, 0);
if (!list->file_offset_node) {
ret = -ENOMEM;
goto out_free_list;
}
list->hash.key = list->file_offset_node->start;
ret = drm_ht_insert_item(&mm->offset_hash, &list->hash);
if (ret) {
DRM_ERROR("failed to add to map hash\n");
goto out_free_mm;
}
return 0;
out_free_mm:
drm_mm_put_block(list->file_offset_node);
out_free_list:
kfree(list->map);
list->map = NULL;
return ret;
}
