int drm_mem_info(char *buf, char **start, off_t offset,
int len, int *eof, void *data)
{
return 0;
}
static void *agp_remap(unsigned long offset, unsigned long size,
struct drm_device * dev)
{
unsigned long i, num_pages =
PAGE_ALIGN(size) / PAGE_SIZE;
struct drm_agp_mem *agpmem;
struct page **page_map;
struct page **phys_page_map;
void *addr;
size = PAGE_ALIGN(size);
#ifdef __alpha__
offset -= dev->hose->mem_space->start;
#endif
list_for_each_entry(agpmem, &dev->agp->memory, head)
if (agpmem->bound <= offset
&& (agpmem->bound + (agpmem->pages << PAGE_SHIFT)) >=
(offset + size))
break;
if (&agpmem->head == &dev->agp->memory)
return NULL;
page_map = vmalloc(num_pages * sizeof(struct page *));
if (!page_map)
return NULL;
phys_page_map = (agpmem->memory->pages + (offset - agpmem->bound) / PAGE_SIZE);
for (i = 0; i < num_pages; ++i)
page_map[i] = phys_page_map[i];
addr = vmap(page_map, num_pages, VM_IOREMAP, PAGE_AGP);
vfree(page_map);
return addr;
}
void drm_free_agp(DRM_AGP_MEM * handle, int pages)
{
agp_free_memory(handle);
}
int drm_bind_agp(DRM_AGP_MEM * handle, unsigned int start)
{
return agp_bind_memory(handle, start);
}
int drm_unbind_agp(DRM_AGP_MEM * handle)
{
return agp_unbind_memory(handle);
}
static inline void *agp_remap(unsigned long offset, unsigned long size,
struct drm_device * dev)
{
return NULL;
}
void drm_core_ioremap(struct drm_local_map *map, struct drm_device *dev)
{
if (drm_core_has_AGP(dev) &&
dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
map->handle = agp_remap(map->offset, map->size, dev);
else
map->handle = ioremap(map->offset, map->size);
}
void drm_core_ioremap_wc(struct drm_local_map *map, struct drm_device *dev)
{
if (drm_core_has_AGP(dev) &&
dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
map->handle = agp_remap(map->offset, map->size, dev);
else
map->handle = ioremap_wc(map->offset, map->size);
}
void drm_core_ioremapfree(struct drm_local_map *map, struct drm_device *dev)
{
if (!map->handle || !map->size)
return;
if (drm_core_has_AGP(dev) &&
dev->agp && dev->agp->cant_use_aperture && map->type == _DRM_AGP)
vunmap(map->handle);
else
iounmap(map->handle);
}
