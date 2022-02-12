static inline void *drm_vmalloc_dma(unsigned long size)
{
#if defined(__powerpc__) && defined(CONFIG_NOT_COHERENT_CACHE)
return __vmalloc(size, GFP_KERNEL, PAGE_KERNEL | _PAGE_NO_CACHE);
#else
return vmalloc_32(size);
#endif
}
static void drm_sg_cleanup(struct drm_sg_mem * entry)
{
struct page *page;
int i;
for (i = 0; i < entry->pages; i++) {
page = entry->pagelist[i];
if (page)
ClearPageReserved(page);
}
vfree(entry->virtual);
kfree(entry->busaddr);
kfree(entry->pagelist);
kfree(entry);
}
void drm_legacy_sg_cleanup(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_SG) && dev->sg &&
!drm_core_check_feature(dev, DRIVER_MODESET)) {
drm_sg_cleanup(dev->sg);
dev->sg = NULL;
}
}
int drm_legacy_sg_alloc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_scatter_gather *request = data;
struct drm_sg_mem *entry;
unsigned long pages, i, j;
DRM_DEBUG("\n");
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (!drm_core_check_feature(dev, DRIVER_SG))
return -EINVAL;
if (dev->sg)
return -EINVAL;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
pages = (request->size + PAGE_SIZE - 1) / PAGE_SIZE;
DRM_DEBUG("size=%ld pages=%ld\n", request->size, pages);
entry->pages = pages;
entry->pagelist = kcalloc(pages, sizeof(*entry->pagelist), GFP_KERNEL);
if (!entry->pagelist) {
kfree(entry);
return -ENOMEM;
}
entry->busaddr = kcalloc(pages, sizeof(*entry->busaddr), GFP_KERNEL);
if (!entry->busaddr) {
kfree(entry->pagelist);
kfree(entry);
return -ENOMEM;
}
entry->virtual = drm_vmalloc_dma(pages << PAGE_SHIFT);
if (!entry->virtual) {
kfree(entry->busaddr);
kfree(entry->pagelist);
kfree(entry);
return -ENOMEM;
}
memset(entry->virtual, 0, pages << PAGE_SHIFT);
entry->handle = ScatterHandle((unsigned long)entry->virtual);
DRM_DEBUG("handle = %08lx\n", entry->handle);
DRM_DEBUG("virtual = %p\n", entry->virtual);
for (i = (unsigned long)entry->virtual, j = 0; j < pages;
i += PAGE_SIZE, j++) {
entry->pagelist[j] = vmalloc_to_page((void *)i);
if (!entry->pagelist[j])
goto failed;
SetPageReserved(entry->pagelist[j]);
}
request->handle = entry->handle;
dev->sg = entry;
#if DEBUG_SCATTER
{
int error = 0;
for (i = 0; i < pages; i++) {
unsigned long *tmp;
tmp = page_address(entry->pagelist[i]);
for (j = 0;
j < PAGE_SIZE / sizeof(unsigned long);
j++, tmp++) {
*tmp = 0xcafebabe;
}
tmp = (unsigned long *)((u8 *) entry->virtual +
(PAGE_SIZE * i));
for (j = 0;
j < PAGE_SIZE / sizeof(unsigned long);
j++, tmp++) {
if (*tmp != 0xcafebabe && error == 0) {
error = 1;
DRM_ERROR("Scatter allocation error, "
"pagelist does not match "
"virtual mapping\n");
}
}
tmp = page_address(entry->pagelist[i]);
for (j = 0;
j < PAGE_SIZE / sizeof(unsigned long);
j++, tmp++) {
*tmp = 0;
}
}
if (error == 0)
DRM_ERROR("Scatter allocation matches pagelist\n");
}
#endif
return 0;
failed:
drm_sg_cleanup(entry);
return -ENOMEM;
}
int drm_legacy_sg_free(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_scatter_gather *request = data;
struct drm_sg_mem *entry;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (!drm_core_check_feature(dev, DRIVER_SG))
return -EINVAL;
entry = dev->sg;
dev->sg = NULL;
if (!entry || entry->handle != request->handle)
return -EINVAL;
DRM_DEBUG("virtual = %p\n", entry->virtual);
drm_sg_cleanup(entry);
return 0;
}
