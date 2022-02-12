int drm_agp_info(struct drm_device *dev, struct drm_agp_info *info)
{
struct agp_kern_info *kern;
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
kern = &dev->agp->agp_info;
info->agp_version_major = kern->version.major;
info->agp_version_minor = kern->version.minor;
info->mode = kern->mode;
info->aperture_base = kern->aper_base;
info->aperture_size = kern->aper_size * 1024 * 1024;
info->memory_allowed = kern->max_memory << PAGE_SHIFT;
info->memory_used = kern->current_memory << PAGE_SHIFT;
info->id_vendor = kern->device->vendor;
info->id_device = kern->device->device;
return 0;
}
int drm_agp_info_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_info *info = data;
int err;
err = drm_agp_info(dev, info);
if (err)
return err;
return 0;
}
int drm_agp_acquire(struct drm_device * dev)
{
if (!dev->agp)
return -ENODEV;
if (dev->agp->acquired)
return -EBUSY;
if (!(dev->agp->bridge = agp_backend_acquire(dev->pdev)))
return -ENODEV;
dev->agp->acquired = 1;
return 0;
}
int drm_agp_acquire_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return drm_agp_acquire((struct drm_device *) file_priv->minor->dev);
}
int drm_agp_release(struct drm_device * dev)
{
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
agp_backend_release(dev->agp->bridge);
dev->agp->acquired = 0;
return 0;
}
int drm_agp_release_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return drm_agp_release(dev);
}
int drm_agp_enable(struct drm_device * dev, struct drm_agp_mode mode)
{
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
dev->agp->mode = mode.mode;
agp_enable(dev->agp->bridge, mode.mode);
dev->agp->enabled = 1;
return 0;
}
int drm_agp_enable_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_mode *mode = data;
return drm_agp_enable(dev, *mode);
}
int drm_agp_alloc(struct drm_device *dev, struct drm_agp_buffer *request)
{
struct drm_agp_mem *entry;
struct agp_memory *memory;
unsigned long pages;
u32 type;
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
if (!(entry = kzalloc(sizeof(*entry), GFP_KERNEL)))
return -ENOMEM;
pages = (request->size + PAGE_SIZE - 1) / PAGE_SIZE;
type = (u32) request->type;
if (!(memory = agp_allocate_memory(dev->agp->bridge, pages, type))) {
kfree(entry);
return -ENOMEM;
}
entry->handle = (unsigned long)memory->key + 1;
entry->memory = memory;
entry->bound = 0;
entry->pages = pages;
list_add(&entry->head, &dev->agp->memory);
request->handle = entry->handle;
request->physical = memory->physical;
return 0;
}
int drm_agp_alloc_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_buffer *request = data;
return drm_agp_alloc(dev, request);
}
static struct drm_agp_mem *drm_agp_lookup_entry(struct drm_device * dev,
unsigned long handle)
{
struct drm_agp_mem *entry;
list_for_each_entry(entry, &dev->agp->memory, head) {
if (entry->handle == handle)
return entry;
}
return NULL;
}
int drm_agp_unbind(struct drm_device *dev, struct drm_agp_binding *request)
{
struct drm_agp_mem *entry;
int ret;
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
if (!(entry = drm_agp_lookup_entry(dev, request->handle)))
return -EINVAL;
if (!entry->bound)
return -EINVAL;
ret = drm_unbind_agp(entry->memory);
if (ret == 0)
entry->bound = 0;
return ret;
}
int drm_agp_unbind_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_binding *request = data;
return drm_agp_unbind(dev, request);
}
int drm_agp_bind(struct drm_device *dev, struct drm_agp_binding *request)
{
struct drm_agp_mem *entry;
int retcode;
int page;
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
if (!(entry = drm_agp_lookup_entry(dev, request->handle)))
return -EINVAL;
if (entry->bound)
return -EINVAL;
page = (request->offset + PAGE_SIZE - 1) / PAGE_SIZE;
if ((retcode = drm_bind_agp(entry->memory, page)))
return retcode;
entry->bound = dev->agp->base + (page << PAGE_SHIFT);
DRM_DEBUG("base = 0x%lx entry->bound = 0x%lx\n",
dev->agp->base, entry->bound);
return 0;
}
int drm_agp_bind_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_binding *request = data;
return drm_agp_bind(dev, request);
}
int drm_agp_free(struct drm_device *dev, struct drm_agp_buffer *request)
{
struct drm_agp_mem *entry;
if (!dev->agp || !dev->agp->acquired)
return -EINVAL;
if (!(entry = drm_agp_lookup_entry(dev, request->handle)))
return -EINVAL;
if (entry->bound)
drm_unbind_agp(entry->memory);
list_del(&entry->head);
drm_free_agp(entry->memory, entry->pages);
kfree(entry);
return 0;
}
int drm_agp_free_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_agp_buffer *request = data;
return drm_agp_free(dev, request);
}
struct drm_agp_head *drm_agp_init(struct drm_device *dev)
{
struct drm_agp_head *head = NULL;
if (!(head = kzalloc(sizeof(*head), GFP_KERNEL)))
return NULL;
head->bridge = agp_find_bridge(dev->pdev);
if (!head->bridge) {
if (!(head->bridge = agp_backend_acquire(dev->pdev))) {
kfree(head);
return NULL;
}
agp_copy_info(head->bridge, &head->agp_info);
agp_backend_release(head->bridge);
} else {
agp_copy_info(head->bridge, &head->agp_info);
}
if (head->agp_info.chipset == NOT_SUPPORTED) {
kfree(head);
return NULL;
}
INIT_LIST_HEAD(&head->memory);
head->cant_use_aperture = head->agp_info.cant_use_aperture;
head->page_mask = head->agp_info.page_mask;
head->base = head->agp_info.aper_base;
return head;
}
void drm_legacy_agp_clear(struct drm_device *dev)
{
struct drm_agp_mem *entry, *tempe;
if (!dev->agp)
return;
if (!drm_core_check_feature(dev, DRIVER_LEGACY))
return;
list_for_each_entry_safe(entry, tempe, &dev->agp->memory, head) {
if (entry->bound)
drm_unbind_agp(entry->memory);
drm_free_agp(entry->memory, entry->pages);
kfree(entry);
}
INIT_LIST_HEAD(&dev->agp->memory);
if (dev->agp->acquired)
drm_agp_release(dev);
dev->agp->acquired = 0;
dev->agp->enabled = 0;
}
struct agp_memory *
drm_agp_bind_pages(struct drm_device *dev,
struct page **pages,
unsigned long num_pages,
uint32_t gtt_offset,
u32 type)
{
struct agp_memory *mem;
int ret, i;
DRM_DEBUG("\n");
mem = agp_allocate_memory(dev->agp->bridge, num_pages,
type);
if (mem == NULL) {
DRM_ERROR("Failed to allocate memory for %ld pages\n",
num_pages);
return NULL;
}
for (i = 0; i < num_pages; i++)
mem->pages[i] = pages[i];
mem->page_count = num_pages;
mem->is_flushed = true;
ret = agp_bind_memory(mem, gtt_offset / PAGE_SIZE);
if (ret != 0) {
DRM_ERROR("Failed to bind AGP memory: %d\n", ret);
agp_free_memory(mem);
return NULL;
}
return mem;
}
