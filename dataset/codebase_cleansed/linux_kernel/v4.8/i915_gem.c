static bool cpu_cache_is_coherent(struct drm_device *dev,
enum i915_cache_level level)
{
return HAS_LLC(dev) || level != I915_CACHE_NONE;
}
static bool cpu_write_needs_clflush(struct drm_i915_gem_object *obj)
{
if (obj->base.write_domain == I915_GEM_DOMAIN_CPU)
return false;
if (!cpu_cache_is_coherent(obj->base.dev, obj->cache_level))
return true;
return obj->pin_display;
}
static int
insert_mappable_node(struct drm_i915_private *i915,
struct drm_mm_node *node, u32 size)
{
memset(node, 0, sizeof(*node));
return drm_mm_insert_node_in_range_generic(&i915->ggtt.base.mm, node,
size, 0, 0, 0,
i915->ggtt.mappable_end,
DRM_MM_SEARCH_DEFAULT,
DRM_MM_CREATE_DEFAULT);
}
static void
remove_mappable_node(struct drm_mm_node *node)
{
drm_mm_remove_node(node);
}
static void i915_gem_info_add_obj(struct drm_i915_private *dev_priv,
size_t size)
{
spin_lock(&dev_priv->mm.object_stat_lock);
dev_priv->mm.object_count++;
dev_priv->mm.object_memory += size;
spin_unlock(&dev_priv->mm.object_stat_lock);
}
static void i915_gem_info_remove_obj(struct drm_i915_private *dev_priv,
size_t size)
{
spin_lock(&dev_priv->mm.object_stat_lock);
dev_priv->mm.object_count--;
dev_priv->mm.object_memory -= size;
spin_unlock(&dev_priv->mm.object_stat_lock);
}
static int
i915_gem_wait_for_error(struct i915_gpu_error *error)
{
int ret;
if (!i915_reset_in_progress(error))
return 0;
ret = wait_event_interruptible_timeout(error->reset_queue,
!i915_reset_in_progress(error),
10*HZ);
if (ret == 0) {
DRM_ERROR("Timed out waiting for the gpu reset to complete\n");
return -EIO;
} else if (ret < 0) {
return ret;
} else {
return 0;
}
}
int i915_mutex_lock_interruptible(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
ret = i915_gem_wait_for_error(&dev_priv->gpu_error);
if (ret)
return ret;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
WARN_ON(i915_verify_lists(dev));
return 0;
}
int
i915_gem_get_aperture_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
struct drm_i915_gem_get_aperture *args = data;
struct i915_vma *vma;
size_t pinned;
pinned = 0;
mutex_lock(&dev->struct_mutex);
list_for_each_entry(vma, &ggtt->base.active_list, vm_link)
if (vma->pin_count)
pinned += vma->node.size;
list_for_each_entry(vma, &ggtt->base.inactive_list, vm_link)
if (vma->pin_count)
pinned += vma->node.size;
mutex_unlock(&dev->struct_mutex);
args->aper_size = ggtt->base.total;
args->aper_available_size = args->aper_size - pinned;
return 0;
}
static int
i915_gem_object_get_pages_phys(struct drm_i915_gem_object *obj)
{
struct address_space *mapping = obj->base.filp->f_mapping;
char *vaddr = obj->phys_handle->vaddr;
struct sg_table *st;
struct scatterlist *sg;
int i;
if (WARN_ON(i915_gem_object_needs_bit17_swizzle(obj)))
return -EINVAL;
for (i = 0; i < obj->base.size / PAGE_SIZE; i++) {
struct page *page;
char *src;
page = shmem_read_mapping_page(mapping, i);
if (IS_ERR(page))
return PTR_ERR(page);
src = kmap_atomic(page);
memcpy(vaddr, src, PAGE_SIZE);
drm_clflush_virt_range(vaddr, PAGE_SIZE);
kunmap_atomic(src);
put_page(page);
vaddr += PAGE_SIZE;
}
i915_gem_chipset_flush(to_i915(obj->base.dev));
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL)
return -ENOMEM;
if (sg_alloc_table(st, 1, GFP_KERNEL)) {
kfree(st);
return -ENOMEM;
}
sg = st->sgl;
sg->offset = 0;
sg->length = obj->base.size;
sg_dma_address(sg) = obj->phys_handle->busaddr;
sg_dma_len(sg) = obj->base.size;
obj->pages = st;
return 0;
}
static void
i915_gem_object_put_pages_phys(struct drm_i915_gem_object *obj)
{
int ret;
BUG_ON(obj->madv == __I915_MADV_PURGED);
ret = i915_gem_object_set_to_cpu_domain(obj, true);
if (WARN_ON(ret)) {
obj->base.read_domains = obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
if (obj->madv == I915_MADV_DONTNEED)
obj->dirty = 0;
if (obj->dirty) {
struct address_space *mapping = obj->base.filp->f_mapping;
char *vaddr = obj->phys_handle->vaddr;
int i;
for (i = 0; i < obj->base.size / PAGE_SIZE; i++) {
struct page *page;
char *dst;
page = shmem_read_mapping_page(mapping, i);
if (IS_ERR(page))
continue;
dst = kmap_atomic(page);
drm_clflush_virt_range(vaddr, PAGE_SIZE);
memcpy(dst, vaddr, PAGE_SIZE);
kunmap_atomic(dst);
set_page_dirty(page);
if (obj->madv == I915_MADV_WILLNEED)
mark_page_accessed(page);
put_page(page);
vaddr += PAGE_SIZE;
}
obj->dirty = 0;
}
sg_free_table(obj->pages);
kfree(obj->pages);
}
static void
i915_gem_object_release_phys(struct drm_i915_gem_object *obj)
{
drm_pci_free(obj->base.dev, obj->phys_handle);
}
static int
drop_pages(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma, *next;
int ret;
drm_gem_object_reference(&obj->base);
list_for_each_entry_safe(vma, next, &obj->vma_list, obj_link)
if (i915_vma_unbind(vma))
break;
ret = i915_gem_object_put_pages(obj);
drm_gem_object_unreference(&obj->base);
return ret;
}
int
i915_gem_object_attach_phys(struct drm_i915_gem_object *obj,
int align)
{
drm_dma_handle_t *phys;
int ret;
if (obj->phys_handle) {
if ((unsigned long)obj->phys_handle->vaddr & (align -1))
return -EBUSY;
return 0;
}
if (obj->madv != I915_MADV_WILLNEED)
return -EFAULT;
if (obj->base.filp == NULL)
return -EINVAL;
ret = drop_pages(obj);
if (ret)
return ret;
phys = drm_pci_alloc(obj->base.dev, obj->base.size, align);
if (!phys)
return -ENOMEM;
obj->phys_handle = phys;
obj->ops = &i915_gem_phys_ops;
return i915_gem_object_get_pages(obj);
}
static int
i915_gem_phys_pwrite(struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file_priv)
{
struct drm_device *dev = obj->base.dev;
void *vaddr = obj->phys_handle->vaddr + args->offset;
char __user *user_data = u64_to_user_ptr(args->data_ptr);
int ret = 0;
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
intel_fb_obj_invalidate(obj, ORIGIN_CPU);
if (__copy_from_user_inatomic_nocache(vaddr, user_data, args->size)) {
unsigned long unwritten;
mutex_unlock(&dev->struct_mutex);
unwritten = copy_from_user(vaddr, user_data, args->size);
mutex_lock(&dev->struct_mutex);
if (unwritten) {
ret = -EFAULT;
goto out;
}
}
drm_clflush_virt_range(vaddr, args->size);
i915_gem_chipset_flush(to_i915(dev));
out:
intel_fb_obj_flush(obj, false, ORIGIN_CPU);
return ret;
}
void *i915_gem_object_alloc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
return kmem_cache_zalloc(dev_priv->objects, GFP_KERNEL);
}
void i915_gem_object_free(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
kmem_cache_free(dev_priv->objects, obj);
}
static int
i915_gem_create(struct drm_file *file,
struct drm_device *dev,
uint64_t size,
uint32_t *handle_p)
{
struct drm_i915_gem_object *obj;
int ret;
u32 handle;
size = roundup(size, PAGE_SIZE);
if (size == 0)
return -EINVAL;
obj = i915_gem_object_create(dev, size);
if (IS_ERR(obj))
return PTR_ERR(obj);
ret = drm_gem_handle_create(file, &obj->base, &handle);
drm_gem_object_unreference_unlocked(&obj->base);
if (ret)
return ret;
*handle_p = handle;
return 0;
}
int
i915_gem_dumb_create(struct drm_file *file,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
args->pitch = ALIGN(args->width * DIV_ROUND_UP(args->bpp, 8), 64);
args->size = args->pitch * args->height;
return i915_gem_create(file, dev,
args->size, &args->handle);
}
int
i915_gem_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_create *args = data;
return i915_gem_create(file, dev,
args->size, &args->handle);
}
static inline int
__copy_to_user_swizzled(char __user *cpu_vaddr,
const char *gpu_vaddr, int gpu_offset,
int length)
{
int ret, cpu_offset = 0;
while (length > 0) {
int cacheline_end = ALIGN(gpu_offset + 1, 64);
int this_length = min(cacheline_end - gpu_offset, length);
int swizzled_gpu_offset = gpu_offset ^ 64;
ret = __copy_to_user(cpu_vaddr + cpu_offset,
gpu_vaddr + swizzled_gpu_offset,
this_length);
if (ret)
return ret + length;
cpu_offset += this_length;
gpu_offset += this_length;
length -= this_length;
}
return 0;
}
static inline int
__copy_from_user_swizzled(char *gpu_vaddr, int gpu_offset,
const char __user *cpu_vaddr,
int length)
{
int ret, cpu_offset = 0;
while (length > 0) {
int cacheline_end = ALIGN(gpu_offset + 1, 64);
int this_length = min(cacheline_end - gpu_offset, length);
int swizzled_gpu_offset = gpu_offset ^ 64;
ret = __copy_from_user(gpu_vaddr + swizzled_gpu_offset,
cpu_vaddr + cpu_offset,
this_length);
if (ret)
return ret + length;
cpu_offset += this_length;
gpu_offset += this_length;
length -= this_length;
}
return 0;
}
int i915_gem_obj_prepare_shmem_read(struct drm_i915_gem_object *obj,
int *needs_clflush)
{
int ret;
*needs_clflush = 0;
if (WARN_ON(!i915_gem_object_has_struct_page(obj)))
return -EINVAL;
if (!(obj->base.read_domains & I915_GEM_DOMAIN_CPU)) {
*needs_clflush = !cpu_cache_is_coherent(obj->base.dev,
obj->cache_level);
ret = i915_gem_object_wait_rendering(obj, true);
if (ret)
return ret;
}
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
i915_gem_object_pin_pages(obj);
return ret;
}
static int
shmem_pread_fast(struct page *page, int shmem_page_offset, int page_length,
char __user *user_data,
bool page_do_bit17_swizzling, bool needs_clflush)
{
char *vaddr;
int ret;
if (unlikely(page_do_bit17_swizzling))
return -EINVAL;
vaddr = kmap_atomic(page);
if (needs_clflush)
drm_clflush_virt_range(vaddr + shmem_page_offset,
page_length);
ret = __copy_to_user_inatomic(user_data,
vaddr + shmem_page_offset,
page_length);
kunmap_atomic(vaddr);
return ret ? -EFAULT : 0;
}
static void
shmem_clflush_swizzled_range(char *addr, unsigned long length,
bool swizzled)
{
if (unlikely(swizzled)) {
unsigned long start = (unsigned long) addr;
unsigned long end = (unsigned long) addr + length;
start = round_down(start, 128);
end = round_up(end, 128);
drm_clflush_virt_range((void *)start, end - start);
} else {
drm_clflush_virt_range(addr, length);
}
}
static int
shmem_pread_slow(struct page *page, int shmem_page_offset, int page_length,
char __user *user_data,
bool page_do_bit17_swizzling, bool needs_clflush)
{
char *vaddr;
int ret;
vaddr = kmap(page);
if (needs_clflush)
shmem_clflush_swizzled_range(vaddr + shmem_page_offset,
page_length,
page_do_bit17_swizzling);
if (page_do_bit17_swizzling)
ret = __copy_to_user_swizzled(user_data,
vaddr, shmem_page_offset,
page_length);
else
ret = __copy_to_user(user_data,
vaddr + shmem_page_offset,
page_length);
kunmap(page);
return ret ? - EFAULT : 0;
}
static inline unsigned long
slow_user_access(struct io_mapping *mapping,
uint64_t page_base, int page_offset,
char __user *user_data,
unsigned long length, bool pwrite)
{
void __iomem *ioaddr;
void *vaddr;
uint64_t unwritten;
ioaddr = io_mapping_map_wc(mapping, page_base, PAGE_SIZE);
vaddr = (void __force *)ioaddr + page_offset;
if (pwrite)
unwritten = __copy_from_user(vaddr, user_data, length);
else
unwritten = __copy_to_user(user_data, vaddr, length);
io_mapping_unmap(ioaddr);
return unwritten;
}
static int
i915_gem_gtt_pread(struct drm_device *dev,
struct drm_i915_gem_object *obj, uint64_t size,
uint64_t data_offset, uint64_t data_ptr)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
struct drm_mm_node node;
char __user *user_data;
uint64_t remain;
uint64_t offset;
int ret;
ret = i915_gem_obj_ggtt_pin(obj, 0, PIN_MAPPABLE);
if (ret) {
ret = insert_mappable_node(dev_priv, &node, PAGE_SIZE);
if (ret)
goto out;
ret = i915_gem_object_get_pages(obj);
if (ret) {
remove_mappable_node(&node);
goto out;
}
i915_gem_object_pin_pages(obj);
} else {
node.start = i915_gem_obj_ggtt_offset(obj);
node.allocated = false;
ret = i915_gem_object_put_fence(obj);
if (ret)
goto out_unpin;
}
ret = i915_gem_object_set_to_gtt_domain(obj, false);
if (ret)
goto out_unpin;
user_data = u64_to_user_ptr(data_ptr);
remain = size;
offset = data_offset;
mutex_unlock(&dev->struct_mutex);
if (likely(!i915.prefault_disable)) {
ret = fault_in_multipages_writeable(user_data, remain);
if (ret) {
mutex_lock(&dev->struct_mutex);
goto out_unpin;
}
}
while (remain > 0) {
u32 page_base = node.start;
unsigned page_offset = offset_in_page(offset);
unsigned page_length = PAGE_SIZE - page_offset;
page_length = remain < page_length ? remain : page_length;
if (node.allocated) {
wmb();
ggtt->base.insert_page(&ggtt->base,
i915_gem_object_get_dma_address(obj, offset >> PAGE_SHIFT),
node.start,
I915_CACHE_NONE, 0);
wmb();
} else {
page_base += offset & PAGE_MASK;
}
if (slow_user_access(ggtt->mappable, page_base,
page_offset, user_data,
page_length, false)) {
ret = -EFAULT;
break;
}
remain -= page_length;
user_data += page_length;
offset += page_length;
}
mutex_lock(&dev->struct_mutex);
if (ret == 0 && (obj->base.read_domains & I915_GEM_DOMAIN_GTT) == 0) {
ret = i915_gem_object_set_to_gtt_domain(obj, false);
}
out_unpin:
if (node.allocated) {
wmb();
ggtt->base.clear_range(&ggtt->base,
node.start, node.size,
true);
i915_gem_object_unpin_pages(obj);
remove_mappable_node(&node);
} else {
i915_gem_object_ggtt_unpin(obj);
}
out:
return ret;
}
static int
i915_gem_shmem_pread(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pread *args,
struct drm_file *file)
{
char __user *user_data;
ssize_t remain;
loff_t offset;
int shmem_page_offset, page_length, ret = 0;
int obj_do_bit17_swizzling, page_do_bit17_swizzling;
int prefaulted = 0;
int needs_clflush = 0;
struct sg_page_iter sg_iter;
if (!i915_gem_object_has_struct_page(obj))
return -ENODEV;
user_data = u64_to_user_ptr(args->data_ptr);
remain = args->size;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
ret = i915_gem_obj_prepare_shmem_read(obj, &needs_clflush);
if (ret)
return ret;
offset = args->offset;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct page *page = sg_page_iter_page(&sg_iter);
if (remain <= 0)
break;
shmem_page_offset = offset_in_page(offset);
page_length = remain;
if ((shmem_page_offset + page_length) > PAGE_SIZE)
page_length = PAGE_SIZE - shmem_page_offset;
page_do_bit17_swizzling = obj_do_bit17_swizzling &&
(page_to_phys(page) & (1 << 17)) != 0;
ret = shmem_pread_fast(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
needs_clflush);
if (ret == 0)
goto next_page;
mutex_unlock(&dev->struct_mutex);
if (likely(!i915.prefault_disable) && !prefaulted) {
ret = fault_in_multipages_writeable(user_data, remain);
(void)ret;
prefaulted = 1;
}
ret = shmem_pread_slow(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
needs_clflush);
mutex_lock(&dev->struct_mutex);
if (ret)
goto out;
next_page:
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out:
i915_gem_object_unpin_pages(obj);
return ret;
}
int
i915_gem_pread_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_pread *args = data;
struct drm_i915_gem_object *obj;
int ret = 0;
if (args->size == 0)
return 0;
if (!access_ok(VERIFY_WRITE,
u64_to_user_ptr(args->data_ptr),
args->size))
return -EFAULT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto out;
}
trace_i915_gem_object_pread(obj, args->offset, args->size);
ret = i915_gem_shmem_pread(dev, obj, args, file);
if (ret == -EFAULT || ret == -ENODEV) {
intel_runtime_pm_get(to_i915(dev));
ret = i915_gem_gtt_pread(dev, obj, args->size,
args->offset, args->data_ptr);
intel_runtime_pm_put(to_i915(dev));
}
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static inline int
fast_user_write(struct io_mapping *mapping,
loff_t page_base, int page_offset,
char __user *user_data,
int length)
{
void __iomem *vaddr_atomic;
void *vaddr;
unsigned long unwritten;
vaddr_atomic = io_mapping_map_atomic_wc(mapping, page_base);
vaddr = (void __force*)vaddr_atomic + page_offset;
unwritten = __copy_from_user_inatomic_nocache(vaddr,
user_data, length);
io_mapping_unmap_atomic(vaddr_atomic);
return unwritten;
}
static int
i915_gem_gtt_pwrite_fast(struct drm_i915_private *i915,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file)
{
struct i915_ggtt *ggtt = &i915->ggtt;
struct drm_device *dev = obj->base.dev;
struct drm_mm_node node;
uint64_t remain, offset;
char __user *user_data;
int ret;
bool hit_slow_path = false;
if (obj->tiling_mode != I915_TILING_NONE)
return -EFAULT;
ret = i915_gem_obj_ggtt_pin(obj, 0, PIN_MAPPABLE | PIN_NONBLOCK);
if (ret) {
ret = insert_mappable_node(i915, &node, PAGE_SIZE);
if (ret)
goto out;
ret = i915_gem_object_get_pages(obj);
if (ret) {
remove_mappable_node(&node);
goto out;
}
i915_gem_object_pin_pages(obj);
} else {
node.start = i915_gem_obj_ggtt_offset(obj);
node.allocated = false;
ret = i915_gem_object_put_fence(obj);
if (ret)
goto out_unpin;
}
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
goto out_unpin;
intel_fb_obj_invalidate(obj, ORIGIN_GTT);
obj->dirty = true;
user_data = u64_to_user_ptr(args->data_ptr);
offset = args->offset;
remain = args->size;
while (remain) {
u32 page_base = node.start;
unsigned page_offset = offset_in_page(offset);
unsigned page_length = PAGE_SIZE - page_offset;
page_length = remain < page_length ? remain : page_length;
if (node.allocated) {
wmb();
ggtt->base.insert_page(&ggtt->base,
i915_gem_object_get_dma_address(obj, offset >> PAGE_SHIFT),
node.start, I915_CACHE_NONE, 0);
wmb();
} else {
page_base += offset & PAGE_MASK;
}
if (fast_user_write(ggtt->mappable, page_base,
page_offset, user_data, page_length)) {
hit_slow_path = true;
mutex_unlock(&dev->struct_mutex);
if (slow_user_access(ggtt->mappable,
page_base,
page_offset, user_data,
page_length, true)) {
ret = -EFAULT;
mutex_lock(&dev->struct_mutex);
goto out_flush;
}
mutex_lock(&dev->struct_mutex);
}
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out_flush:
if (hit_slow_path) {
if (ret == 0 &&
(obj->base.read_domains & I915_GEM_DOMAIN_GTT) == 0) {
ret = i915_gem_object_set_to_gtt_domain(obj, false);
}
}
intel_fb_obj_flush(obj, false, ORIGIN_GTT);
out_unpin:
if (node.allocated) {
wmb();
ggtt->base.clear_range(&ggtt->base,
node.start, node.size,
true);
i915_gem_object_unpin_pages(obj);
remove_mappable_node(&node);
} else {
i915_gem_object_ggtt_unpin(obj);
}
out:
return ret;
}
static int
shmem_pwrite_fast(struct page *page, int shmem_page_offset, int page_length,
char __user *user_data,
bool page_do_bit17_swizzling,
bool needs_clflush_before,
bool needs_clflush_after)
{
char *vaddr;
int ret;
if (unlikely(page_do_bit17_swizzling))
return -EINVAL;
vaddr = kmap_atomic(page);
if (needs_clflush_before)
drm_clflush_virt_range(vaddr + shmem_page_offset,
page_length);
ret = __copy_from_user_inatomic(vaddr + shmem_page_offset,
user_data, page_length);
if (needs_clflush_after)
drm_clflush_virt_range(vaddr + shmem_page_offset,
page_length);
kunmap_atomic(vaddr);
return ret ? -EFAULT : 0;
}
static int
shmem_pwrite_slow(struct page *page, int shmem_page_offset, int page_length,
char __user *user_data,
bool page_do_bit17_swizzling,
bool needs_clflush_before,
bool needs_clflush_after)
{
char *vaddr;
int ret;
vaddr = kmap(page);
if (unlikely(needs_clflush_before || page_do_bit17_swizzling))
shmem_clflush_swizzled_range(vaddr + shmem_page_offset,
page_length,
page_do_bit17_swizzling);
if (page_do_bit17_swizzling)
ret = __copy_from_user_swizzled(vaddr, shmem_page_offset,
user_data,
page_length);
else
ret = __copy_from_user(vaddr + shmem_page_offset,
user_data,
page_length);
if (needs_clflush_after)
shmem_clflush_swizzled_range(vaddr + shmem_page_offset,
page_length,
page_do_bit17_swizzling);
kunmap(page);
return ret ? -EFAULT : 0;
}
static int
i915_gem_shmem_pwrite(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file)
{
ssize_t remain;
loff_t offset;
char __user *user_data;
int shmem_page_offset, page_length, ret = 0;
int obj_do_bit17_swizzling, page_do_bit17_swizzling;
int hit_slowpath = 0;
int needs_clflush_after = 0;
int needs_clflush_before = 0;
struct sg_page_iter sg_iter;
user_data = u64_to_user_ptr(args->data_ptr);
remain = args->size;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
needs_clflush_after = cpu_write_needs_clflush(obj);
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
}
if ((obj->base.read_domains & I915_GEM_DOMAIN_CPU) == 0)
needs_clflush_before =
!cpu_cache_is_coherent(dev, obj->cache_level);
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
intel_fb_obj_invalidate(obj, ORIGIN_CPU);
i915_gem_object_pin_pages(obj);
offset = args->offset;
obj->dirty = 1;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents,
offset >> PAGE_SHIFT) {
struct page *page = sg_page_iter_page(&sg_iter);
int partial_cacheline_write;
if (remain <= 0)
break;
shmem_page_offset = offset_in_page(offset);
page_length = remain;
if ((shmem_page_offset + page_length) > PAGE_SIZE)
page_length = PAGE_SIZE - shmem_page_offset;
partial_cacheline_write = needs_clflush_before &&
((shmem_page_offset | page_length)
& (boot_cpu_data.x86_clflush_size - 1));
page_do_bit17_swizzling = obj_do_bit17_swizzling &&
(page_to_phys(page) & (1 << 17)) != 0;
ret = shmem_pwrite_fast(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush_after);
if (ret == 0)
goto next_page;
hit_slowpath = 1;
mutex_unlock(&dev->struct_mutex);
ret = shmem_pwrite_slow(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush_after);
mutex_lock(&dev->struct_mutex);
if (ret)
goto out;
next_page:
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out:
i915_gem_object_unpin_pages(obj);
if (hit_slowpath) {
if (!needs_clflush_after &&
obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
if (i915_gem_clflush_object(obj, obj->pin_display))
needs_clflush_after = true;
}
}
if (needs_clflush_after)
i915_gem_chipset_flush(to_i915(dev));
else
obj->cache_dirty = true;
intel_fb_obj_flush(obj, false, ORIGIN_CPU);
return ret;
}
int
i915_gem_pwrite_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_pwrite *args = data;
struct drm_i915_gem_object *obj;
int ret;
if (args->size == 0)
return 0;
if (!access_ok(VERIFY_READ,
u64_to_user_ptr(args->data_ptr),
args->size))
return -EFAULT;
if (likely(!i915.prefault_disable)) {
ret = fault_in_multipages_readable(u64_to_user_ptr(args->data_ptr),
args->size);
if (ret)
return -EFAULT;
}
intel_runtime_pm_get(dev_priv);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto put_rpm;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto out;
}
trace_i915_gem_object_pwrite(obj, args->offset, args->size);
ret = -EFAULT;
if (!i915_gem_object_has_struct_page(obj) ||
cpu_write_needs_clflush(obj)) {
ret = i915_gem_gtt_pwrite_fast(dev_priv, obj, args, file);
}
if (ret == -EFAULT || ret == -ENOSPC) {
if (obj->phys_handle)
ret = i915_gem_phys_pwrite(obj, args, file);
else if (i915_gem_object_has_struct_page(obj))
ret = i915_gem_shmem_pwrite(dev, obj, args, file);
else
ret = -ENODEV;
}
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
put_rpm:
intel_runtime_pm_put(dev_priv);
return ret;
}
static int
i915_gem_check_wedge(unsigned reset_counter, bool interruptible)
{
if (__i915_terminally_wedged(reset_counter))
return -EIO;
if (__i915_reset_in_progress(reset_counter)) {
if (!interruptible)
return -EIO;
return -EAGAIN;
}
return 0;
}
static unsigned long local_clock_us(unsigned *cpu)
{
unsigned long t;
*cpu = get_cpu();
t = local_clock() >> 10;
put_cpu();
return t;
}
static bool busywait_stop(unsigned long timeout, unsigned cpu)
{
unsigned this_cpu;
if (time_after(local_clock_us(&this_cpu), timeout))
return true;
return this_cpu != cpu;
}
bool __i915_spin_request(const struct drm_i915_gem_request *req,
int state, unsigned long timeout_us)
{
unsigned cpu;
timeout_us += local_clock_us(&cpu);
do {
if (i915_gem_request_completed(req))
return true;
if (signal_pending_state(state, current))
break;
if (busywait_stop(timeout_us, cpu))
break;
cpu_relax_lowlatency();
} while (!need_resched());
return false;
}
int __i915_wait_request(struct drm_i915_gem_request *req,
bool interruptible,
s64 *timeout,
struct intel_rps_client *rps)
{
int state = interruptible ? TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE;
DEFINE_WAIT(reset);
struct intel_wait wait;
unsigned long timeout_remain;
s64 before = 0;
int ret = 0;
might_sleep();
if (list_empty(&req->list))
return 0;
if (i915_gem_request_completed(req))
return 0;
timeout_remain = MAX_SCHEDULE_TIMEOUT;
if (timeout) {
if (WARN_ON(*timeout < 0))
return -EINVAL;
if (*timeout == 0)
return -ETIME;
timeout_remain = nsecs_to_jiffies_timeout(*timeout);
before = ktime_get_raw_ns();
}
trace_i915_gem_request_wait_begin(req);
if (INTEL_INFO(req->i915)->gen >= 6)
gen6_rps_boost(req->i915, rps, req->emitted_jiffies);
if (i915_spin_request(req, state, 5))
goto complete;
set_current_state(state);
add_wait_queue(&req->i915->gpu_error.wait_queue, &reset);
intel_wait_init(&wait, req->seqno);
if (intel_engine_add_wait(req->engine, &wait))
goto wakeup;
for (;;) {
if (signal_pending_state(state, current)) {
ret = -ERESTARTSYS;
break;
}
timeout_remain = io_schedule_timeout(timeout_remain);
if (timeout_remain == 0) {
ret = -ETIME;
break;
}
if (intel_wait_complete(&wait))
break;
set_current_state(state);
wakeup:
if (__i915_request_irq_complete(req))
break;
if (i915_spin_request(req, state, 2))
break;
}
remove_wait_queue(&req->i915->gpu_error.wait_queue, &reset);
intel_engine_remove_wait(req->engine, &wait);
__set_current_state(TASK_RUNNING);
complete:
trace_i915_gem_request_wait_end(req);
if (timeout) {
s64 tres = *timeout - (ktime_get_raw_ns() - before);
*timeout = tres < 0 ? 0 : tres;
if (ret == -ETIME && *timeout < jiffies_to_usecs(1)*1000)
*timeout = 0;
}
if (rps && req->seqno == req->engine->last_submitted_seqno) {
spin_lock(&req->i915->rps.client_lock);
list_del_init(&rps->link);
spin_unlock(&req->i915->rps.client_lock);
}
return ret;
}
int i915_gem_request_add_to_client(struct drm_i915_gem_request *req,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv;
WARN_ON(!req || !file || req->file_priv);
if (!req || !file)
return -EINVAL;
if (req->file_priv)
return -EINVAL;
file_priv = file->driver_priv;
spin_lock(&file_priv->mm.lock);
req->file_priv = file_priv;
list_add_tail(&req->client_list, &file_priv->mm.request_list);
spin_unlock(&file_priv->mm.lock);
req->pid = get_pid(task_pid(current));
return 0;
}
static inline void
i915_gem_request_remove_from_client(struct drm_i915_gem_request *request)
{
struct drm_i915_file_private *file_priv = request->file_priv;
if (!file_priv)
return;
spin_lock(&file_priv->mm.lock);
list_del(&request->client_list);
request->file_priv = NULL;
spin_unlock(&file_priv->mm.lock);
put_pid(request->pid);
request->pid = NULL;
}
static void i915_gem_request_retire(struct drm_i915_gem_request *request)
{
trace_i915_gem_request_retire(request);
request->ringbuf->last_retired_head = request->postfix;
list_del_init(&request->list);
i915_gem_request_remove_from_client(request);
if (request->previous_context) {
if (i915.enable_execlists)
intel_lr_context_unpin(request->previous_context,
request->engine);
}
i915_gem_context_unreference(request->ctx);
i915_gem_request_unreference(request);
}
static void
__i915_gem_request_retire__upto(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
struct drm_i915_gem_request *tmp;
lockdep_assert_held(&engine->i915->drm.struct_mutex);
if (list_empty(&req->list))
return;
do {
tmp = list_first_entry(&engine->request_list,
typeof(*tmp), list);
i915_gem_request_retire(tmp);
} while (tmp != req);
WARN_ON(i915_verify_lists(engine->dev));
}
int
i915_wait_request(struct drm_i915_gem_request *req)
{
struct drm_i915_private *dev_priv = req->i915;
bool interruptible;
int ret;
interruptible = dev_priv->mm.interruptible;
BUG_ON(!mutex_is_locked(&dev_priv->drm.struct_mutex));
ret = __i915_wait_request(req, interruptible, NULL, NULL);
if (ret)
return ret;
if (!i915_reset_in_progress(&dev_priv->gpu_error))
__i915_gem_request_retire__upto(req);
return 0;
}
int
i915_gem_object_wait_rendering(struct drm_i915_gem_object *obj,
bool readonly)
{
int ret, i;
if (!obj->active)
return 0;
if (readonly) {
if (obj->last_write_req != NULL) {
ret = i915_wait_request(obj->last_write_req);
if (ret)
return ret;
i = obj->last_write_req->engine->id;
if (obj->last_read_req[i] == obj->last_write_req)
i915_gem_object_retire__read(obj, i);
else
i915_gem_object_retire__write(obj);
}
} else {
for (i = 0; i < I915_NUM_ENGINES; i++) {
if (obj->last_read_req[i] == NULL)
continue;
ret = i915_wait_request(obj->last_read_req[i]);
if (ret)
return ret;
i915_gem_object_retire__read(obj, i);
}
GEM_BUG_ON(obj->active);
}
return 0;
}
static void
i915_gem_object_retire_request(struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req)
{
int ring = req->engine->id;
if (obj->last_read_req[ring] == req)
i915_gem_object_retire__read(obj, ring);
else if (obj->last_write_req == req)
i915_gem_object_retire__write(obj);
if (!i915_reset_in_progress(&req->i915->gpu_error))
__i915_gem_request_retire__upto(req);
}
static __must_check int
i915_gem_object_wait_rendering__nonblocking(struct drm_i915_gem_object *obj,
struct intel_rps_client *rps,
bool readonly)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_request *requests[I915_NUM_ENGINES];
int ret, i, n = 0;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
BUG_ON(!dev_priv->mm.interruptible);
if (!obj->active)
return 0;
if (readonly) {
struct drm_i915_gem_request *req;
req = obj->last_write_req;
if (req == NULL)
return 0;
requests[n++] = i915_gem_request_reference(req);
} else {
for (i = 0; i < I915_NUM_ENGINES; i++) {
struct drm_i915_gem_request *req;
req = obj->last_read_req[i];
if (req == NULL)
continue;
requests[n++] = i915_gem_request_reference(req);
}
}
mutex_unlock(&dev->struct_mutex);
ret = 0;
for (i = 0; ret == 0 && i < n; i++)
ret = __i915_wait_request(requests[i], true, NULL, rps);
mutex_lock(&dev->struct_mutex);
for (i = 0; i < n; i++) {
if (ret == 0)
i915_gem_object_retire_request(obj, requests[i]);
i915_gem_request_unreference(requests[i]);
}
return ret;
}
static struct intel_rps_client *to_rps_client(struct drm_file *file)
{
struct drm_i915_file_private *fpriv = file->driver_priv;
return &fpriv->rps;
}
static enum fb_op_origin
write_origin(struct drm_i915_gem_object *obj, unsigned domain)
{
return domain == I915_GEM_DOMAIN_GTT && !obj->has_wc_mmap ?
ORIGIN_GTT : ORIGIN_CPU;
}
int
i915_gem_set_domain_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_set_domain *args = data;
struct drm_i915_gem_object *obj;
uint32_t read_domains = args->read_domains;
uint32_t write_domain = args->write_domain;
int ret;
if (write_domain & I915_GEM_GPU_DOMAINS)
return -EINVAL;
if (read_domains & I915_GEM_GPU_DOMAINS)
return -EINVAL;
if (write_domain != 0 && read_domains != write_domain)
return -EINVAL;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
ret = i915_gem_object_wait_rendering__nonblocking(obj,
to_rps_client(file),
!write_domain);
if (ret)
goto unref;
if (read_domains & I915_GEM_DOMAIN_GTT)
ret = i915_gem_object_set_to_gtt_domain(obj, write_domain != 0);
else
ret = i915_gem_object_set_to_cpu_domain(obj, write_domain != 0);
if (write_domain != 0)
intel_fb_obj_invalidate(obj, write_origin(obj, write_domain));
unref:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_sw_finish_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_sw_finish *args = data;
struct drm_i915_gem_object *obj;
int ret = 0;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->pin_display)
i915_gem_object_flush_cpu_write_domain(obj);
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_mmap_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_mmap *args = data;
struct drm_gem_object *obj;
unsigned long addr;
if (args->flags & ~(I915_MMAP_WC))
return -EINVAL;
if (args->flags & I915_MMAP_WC && !boot_cpu_has(X86_FEATURE_PAT))
return -ENODEV;
obj = drm_gem_object_lookup(file, args->handle);
if (obj == NULL)
return -ENOENT;
if (!obj->filp) {
drm_gem_object_unreference_unlocked(obj);
return -EINVAL;
}
addr = vm_mmap(obj->filp, 0, args->size,
PROT_READ | PROT_WRITE, MAP_SHARED,
args->offset);
if (args->flags & I915_MMAP_WC) {
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
if (down_write_killable(&mm->mmap_sem)) {
drm_gem_object_unreference_unlocked(obj);
return -EINTR;
}
vma = find_vma(mm, addr);
if (vma)
vma->vm_page_prot =
pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
else
addr = -ENOMEM;
up_write(&mm->mmap_sem);
WRITE_ONCE(to_intel_bo(obj)->has_wc_mmap, true);
}
drm_gem_object_unreference_unlocked(obj);
if (IS_ERR((void *)addr))
return addr;
args->addr_ptr = (uint64_t) addr;
return 0;
}
int i915_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_i915_gem_object *obj = to_intel_bo(vma->vm_private_data);
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
struct i915_ggtt_view view = i915_ggtt_view_normal;
pgoff_t page_offset;
unsigned long pfn;
int ret = 0;
bool write = !!(vmf->flags & FAULT_FLAG_WRITE);
intel_runtime_pm_get(dev_priv);
page_offset = ((unsigned long)vmf->virtual_address - vma->vm_start) >>
PAGE_SHIFT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto out;
trace_i915_gem_object_fault(obj, page_offset, true, write);
ret = i915_gem_object_wait_rendering__nonblocking(obj, NULL, !write);
if (ret)
goto unlock;
if (obj->cache_level != I915_CACHE_NONE && !HAS_LLC(dev)) {
ret = -EFAULT;
goto unlock;
}
if (obj->base.size >= ggtt->mappable_end &&
obj->tiling_mode == I915_TILING_NONE) {
static const unsigned int chunk_size = 256;
memset(&view, 0, sizeof(view));
view.type = I915_GGTT_VIEW_PARTIAL;
view.params.partial.offset = rounddown(page_offset, chunk_size);
view.params.partial.size =
min_t(unsigned int,
chunk_size,
(vma->vm_end - vma->vm_start)/PAGE_SIZE -
view.params.partial.offset);
}
ret = i915_gem_object_ggtt_pin(obj, &view, 0, PIN_MAPPABLE);
if (ret)
goto unlock;
ret = i915_gem_object_set_to_gtt_domain(obj, write);
if (ret)
goto unpin;
ret = i915_gem_object_get_fence(obj);
if (ret)
goto unpin;
pfn = ggtt->mappable_base +
i915_gem_obj_ggtt_offset_view(obj, &view);
pfn >>= PAGE_SHIFT;
if (unlikely(view.type == I915_GGTT_VIEW_PARTIAL)) {
unsigned long base = vma->vm_start +
(view.params.partial.offset << PAGE_SHIFT);
unsigned int i;
for (i = 0; i < view.params.partial.size; i++) {
ret = vm_insert_pfn(vma, base + i * PAGE_SIZE, pfn + i);
if (ret)
break;
}
obj->fault_mappable = true;
} else {
if (!obj->fault_mappable) {
unsigned long size = min_t(unsigned long,
vma->vm_end - vma->vm_start,
obj->base.size);
int i;
for (i = 0; i < size >> PAGE_SHIFT; i++) {
ret = vm_insert_pfn(vma,
(unsigned long)vma->vm_start + i * PAGE_SIZE,
pfn + i);
if (ret)
break;
}
obj->fault_mappable = true;
} else
ret = vm_insert_pfn(vma,
(unsigned long)vmf->virtual_address,
pfn + page_offset);
}
unpin:
i915_gem_object_ggtt_unpin_view(obj, &view);
unlock:
mutex_unlock(&dev->struct_mutex);
out:
switch (ret) {
case -EIO:
if (!i915_terminally_wedged(&dev_priv->gpu_error)) {
ret = VM_FAULT_SIGBUS;
break;
}
case -EAGAIN:
case 0:
case -ERESTARTSYS:
case -EINTR:
case -EBUSY:
ret = VM_FAULT_NOPAGE;
break;
case -ENOMEM:
ret = VM_FAULT_OOM;
break;
case -ENOSPC:
case -EFAULT:
ret = VM_FAULT_SIGBUS;
break;
default:
WARN_ONCE(ret, "unhandled error in i915_gem_fault: %i\n", ret);
ret = VM_FAULT_SIGBUS;
break;
}
intel_runtime_pm_put(dev_priv);
return ret;
}
void
i915_gem_release_mmap(struct drm_i915_gem_object *obj)
{
lockdep_assert_held(&obj->base.dev->struct_mutex);
if (!obj->fault_mappable)
return;
drm_vma_node_unmap(&obj->base.vma_node,
obj->base.dev->anon_inode->i_mapping);
wmb();
obj->fault_mappable = false;
}
void
i915_gem_release_all_mmaps(struct drm_i915_private *dev_priv)
{
struct drm_i915_gem_object *obj;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list)
i915_gem_release_mmap(obj);
}
uint32_t
i915_gem_get_gtt_size(struct drm_device *dev, uint32_t size, int tiling_mode)
{
uint32_t gtt_size;
if (INTEL_INFO(dev)->gen >= 4 ||
tiling_mode == I915_TILING_NONE)
return size;
if (IS_GEN3(dev))
gtt_size = 1024*1024;
else
gtt_size = 512*1024;
while (gtt_size < size)
gtt_size <<= 1;
return gtt_size;
}
uint32_t
i915_gem_get_gtt_alignment(struct drm_device *dev, uint32_t size,
int tiling_mode, bool fenced)
{
if (INTEL_INFO(dev)->gen >= 4 || (!fenced && IS_G33(dev)) ||
tiling_mode == I915_TILING_NONE)
return 4096;
return i915_gem_get_gtt_size(dev, size, tiling_mode);
}
static int i915_gem_object_create_mmap_offset(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
int ret;
dev_priv->mm.shrinker_no_lock_stealing = true;
ret = drm_gem_create_mmap_offset(&obj->base);
if (ret != -ENOSPC)
goto out;
i915_gem_shrink(dev_priv,
obj->base.size >> PAGE_SHIFT,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_PURGEABLE);
ret = drm_gem_create_mmap_offset(&obj->base);
if (ret != -ENOSPC)
goto out;
i915_gem_shrink_all(dev_priv);
ret = drm_gem_create_mmap_offset(&obj->base);
out:
dev_priv->mm.shrinker_no_lock_stealing = false;
return ret;
}
static void i915_gem_object_free_mmap_offset(struct drm_i915_gem_object *obj)
{
drm_gem_free_mmap_offset(&obj->base);
}
int
i915_gem_mmap_gtt(struct drm_file *file,
struct drm_device *dev,
uint32_t handle,
uint64_t *offset)
{
struct drm_i915_gem_object *obj;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->madv != I915_MADV_WILLNEED) {
DRM_DEBUG("Attempting to mmap a purgeable buffer\n");
ret = -EFAULT;
goto out;
}
ret = i915_gem_object_create_mmap_offset(obj);
if (ret)
goto out;
*offset = drm_vma_node_offset_addr(&obj->base.vma_node);
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_mmap_gtt_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_mmap_gtt *args = data;
return i915_gem_mmap_gtt(file, dev, args->handle, &args->offset);
}
static void
i915_gem_object_truncate(struct drm_i915_gem_object *obj)
{
i915_gem_object_free_mmap_offset(obj);
if (obj->base.filp == NULL)
return;
shmem_truncate_range(file_inode(obj->base.filp), 0, (loff_t)-1);
obj->madv = __I915_MADV_PURGED;
}
static void
i915_gem_object_invalidate(struct drm_i915_gem_object *obj)
{
struct address_space *mapping;
switch (obj->madv) {
case I915_MADV_DONTNEED:
i915_gem_object_truncate(obj);
case __I915_MADV_PURGED:
return;
}
if (obj->base.filp == NULL)
return;
mapping = obj->base.filp->f_mapping,
invalidate_mapping_pages(mapping, 0, (loff_t)-1);
}
static void
i915_gem_object_put_pages_gtt(struct drm_i915_gem_object *obj)
{
struct sgt_iter sgt_iter;
struct page *page;
int ret;
BUG_ON(obj->madv == __I915_MADV_PURGED);
ret = i915_gem_object_set_to_cpu_domain(obj, true);
if (WARN_ON(ret)) {
i915_gem_clflush_object(obj, true);
obj->base.read_domains = obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
i915_gem_gtt_finish_object(obj);
if (i915_gem_object_needs_bit17_swizzle(obj))
i915_gem_object_save_bit_17_swizzle(obj);
if (obj->madv == I915_MADV_DONTNEED)
obj->dirty = 0;
for_each_sgt_page(page, sgt_iter, obj->pages) {
if (obj->dirty)
set_page_dirty(page);
if (obj->madv == I915_MADV_WILLNEED)
mark_page_accessed(page);
put_page(page);
}
obj->dirty = 0;
sg_free_table(obj->pages);
kfree(obj->pages);
}
int
i915_gem_object_put_pages(struct drm_i915_gem_object *obj)
{
const struct drm_i915_gem_object_ops *ops = obj->ops;
if (obj->pages == NULL)
return 0;
if (obj->pages_pin_count)
return -EBUSY;
BUG_ON(i915_gem_obj_bound_any(obj));
list_del(&obj->global_list);
if (obj->mapping) {
if (is_vmalloc_addr(obj->mapping))
vunmap(obj->mapping);
else
kunmap(kmap_to_page(obj->mapping));
obj->mapping = NULL;
}
ops->put_pages(obj);
obj->pages = NULL;
i915_gem_object_invalidate(obj);
return 0;
}
static int
i915_gem_object_get_pages_gtt(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
int page_count, i;
struct address_space *mapping;
struct sg_table *st;
struct scatterlist *sg;
struct sgt_iter sgt_iter;
struct page *page;
unsigned long last_pfn = 0;
int ret;
gfp_t gfp;
BUG_ON(obj->base.read_domains & I915_GEM_GPU_DOMAINS);
BUG_ON(obj->base.write_domain & I915_GEM_GPU_DOMAINS);
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL)
return -ENOMEM;
page_count = obj->base.size / PAGE_SIZE;
if (sg_alloc_table(st, page_count, GFP_KERNEL)) {
kfree(st);
return -ENOMEM;
}
mapping = obj->base.filp->f_mapping;
gfp = mapping_gfp_constraint(mapping, ~(__GFP_IO | __GFP_RECLAIM));
gfp |= __GFP_NORETRY | __GFP_NOWARN;
sg = st->sgl;
st->nents = 0;
for (i = 0; i < page_count; i++) {
page = shmem_read_mapping_page_gfp(mapping, i, gfp);
if (IS_ERR(page)) {
i915_gem_shrink(dev_priv,
page_count,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_PURGEABLE);
page = shmem_read_mapping_page_gfp(mapping, i, gfp);
}
if (IS_ERR(page)) {
i915_gem_shrink_all(dev_priv);
page = shmem_read_mapping_page(mapping, i);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
goto err_pages;
}
}
#ifdef CONFIG_SWIOTLB
if (swiotlb_nr_tbl()) {
st->nents++;
sg_set_page(sg, page, PAGE_SIZE, 0);
sg = sg_next(sg);
continue;
}
#endif
if (!i || page_to_pfn(page) != last_pfn + 1) {
if (i)
sg = sg_next(sg);
st->nents++;
sg_set_page(sg, page, PAGE_SIZE, 0);
} else {
sg->length += PAGE_SIZE;
}
last_pfn = page_to_pfn(page);
WARN_ON((gfp & __GFP_DMA32) && (last_pfn >= 0x00100000UL));
}
#ifdef CONFIG_SWIOTLB
if (!swiotlb_nr_tbl())
#endif
sg_mark_end(sg);
obj->pages = st;
ret = i915_gem_gtt_prepare_object(obj);
if (ret)
goto err_pages;
if (i915_gem_object_needs_bit17_swizzle(obj))
i915_gem_object_do_bit_17_swizzle(obj);
if (obj->tiling_mode != I915_TILING_NONE &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES)
i915_gem_object_pin_pages(obj);
return 0;
err_pages:
sg_mark_end(sg);
for_each_sgt_page(page, sgt_iter, st)
put_page(page);
sg_free_table(st);
kfree(st);
if (ret == -ENOSPC)
ret = -ENOMEM;
return ret;
}
int
i915_gem_object_get_pages(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
const struct drm_i915_gem_object_ops *ops = obj->ops;
int ret;
if (obj->pages)
return 0;
if (obj->madv != I915_MADV_WILLNEED) {
DRM_DEBUG("Attempting to obtain a purgeable object\n");
return -EFAULT;
}
BUG_ON(obj->pages_pin_count);
ret = ops->get_pages(obj);
if (ret)
return ret;
list_add_tail(&obj->global_list, &dev_priv->mm.unbound_list);
obj->get_page.sg = obj->pages->sgl;
obj->get_page.last = 0;
return 0;
}
static void *i915_gem_object_map(const struct drm_i915_gem_object *obj)
{
unsigned long n_pages = obj->base.size >> PAGE_SHIFT;
struct sg_table *sgt = obj->pages;
struct sgt_iter sgt_iter;
struct page *page;
struct page *stack_pages[32];
struct page **pages = stack_pages;
unsigned long i = 0;
void *addr;
if (n_pages == 1)
return kmap(sg_page(sgt->sgl));
if (n_pages > ARRAY_SIZE(stack_pages)) {
pages = drm_malloc_gfp(n_pages, sizeof(*pages), GFP_TEMPORARY);
if (!pages)
return NULL;
}
for_each_sgt_page(page, sgt_iter, sgt)
pages[i++] = page;
GEM_BUG_ON(i != n_pages);
addr = vmap(pages, n_pages, 0, PAGE_KERNEL);
if (pages != stack_pages)
drm_free_large(pages);
return addr;
}
void *i915_gem_object_pin_map(struct drm_i915_gem_object *obj)
{
int ret;
lockdep_assert_held(&obj->base.dev->struct_mutex);
ret = i915_gem_object_get_pages(obj);
if (ret)
return ERR_PTR(ret);
i915_gem_object_pin_pages(obj);
if (!obj->mapping) {
obj->mapping = i915_gem_object_map(obj);
if (!obj->mapping) {
i915_gem_object_unpin_pages(obj);
return ERR_PTR(-ENOMEM);
}
}
return obj->mapping;
}
void i915_vma_move_to_active(struct i915_vma *vma,
struct drm_i915_gem_request *req)
{
struct drm_i915_gem_object *obj = vma->obj;
struct intel_engine_cs *engine;
engine = i915_gem_request_get_engine(req);
if (obj->active == 0)
drm_gem_object_reference(&obj->base);
obj->active |= intel_engine_flag(engine);
list_move_tail(&obj->engine_list[engine->id], &engine->active_list);
i915_gem_request_assign(&obj->last_read_req[engine->id], req);
list_move_tail(&vma->vm_link, &vma->vm->active_list);
}
static void
i915_gem_object_retire__write(struct drm_i915_gem_object *obj)
{
GEM_BUG_ON(obj->last_write_req == NULL);
GEM_BUG_ON(!(obj->active & intel_engine_flag(obj->last_write_req->engine)));
i915_gem_request_assign(&obj->last_write_req, NULL);
intel_fb_obj_flush(obj, true, ORIGIN_CS);
}
static void
i915_gem_object_retire__read(struct drm_i915_gem_object *obj, int ring)
{
struct i915_vma *vma;
GEM_BUG_ON(obj->last_read_req[ring] == NULL);
GEM_BUG_ON(!(obj->active & (1 << ring)));
list_del_init(&obj->engine_list[ring]);
i915_gem_request_assign(&obj->last_read_req[ring], NULL);
if (obj->last_write_req && obj->last_write_req->engine->id == ring)
i915_gem_object_retire__write(obj);
obj->active &= ~(1 << ring);
if (obj->active)
return;
list_move_tail(&obj->global_list,
&to_i915(obj->base.dev)->mm.bound_list);
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!list_empty(&vma->vm_link))
list_move_tail(&vma->vm_link, &vma->vm->inactive_list);
}
i915_gem_request_assign(&obj->last_fenced_req, NULL);
drm_gem_object_unreference(&obj->base);
}
static int
i915_gem_init_seqno(struct drm_i915_private *dev_priv, u32 seqno)
{
struct intel_engine_cs *engine;
int ret;
for_each_engine(engine, dev_priv) {
ret = intel_engine_idle(engine);
if (ret)
return ret;
}
i915_gem_retire_requests(dev_priv);
if (!i915_seqno_passed(seqno, dev_priv->next_seqno)) {
while (intel_kick_waiters(dev_priv) ||
intel_kick_signalers(dev_priv))
yield();
}
for_each_engine(engine, dev_priv)
intel_ring_init_seqno(engine, seqno);
return 0;
}
int i915_gem_set_seqno(struct drm_device *dev, u32 seqno)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
if (seqno == 0)
return -EINVAL;
ret = i915_gem_init_seqno(dev_priv, seqno - 1);
if (ret)
return ret;
dev_priv->next_seqno = seqno;
dev_priv->last_seqno = seqno - 1;
if (dev_priv->last_seqno == 0)
dev_priv->last_seqno--;
return 0;
}
int
i915_gem_get_seqno(struct drm_i915_private *dev_priv, u32 *seqno)
{
if (dev_priv->next_seqno == 0) {
int ret = i915_gem_init_seqno(dev_priv, 0);
if (ret)
return ret;
dev_priv->next_seqno = 1;
}
*seqno = dev_priv->last_seqno = dev_priv->next_seqno++;
return 0;
}
static void i915_gem_mark_busy(const struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->gt.active_engines |= intel_engine_flag(engine);
if (dev_priv->gt.awake)
return;
intel_runtime_pm_get_noresume(dev_priv);
dev_priv->gt.awake = true;
i915_update_gfx_val(dev_priv);
if (INTEL_GEN(dev_priv) >= 6)
gen6_rps_busy(dev_priv);
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.retire_work,
round_jiffies_up_relative(HZ));
}
void __i915_add_request(struct drm_i915_gem_request *request,
struct drm_i915_gem_object *obj,
bool flush_caches)
{
struct intel_engine_cs *engine;
struct intel_ringbuffer *ringbuf;
u32 request_start;
u32 reserved_tail;
int ret;
if (WARN_ON(request == NULL))
return;
engine = request->engine;
ringbuf = request->ringbuf;
request_start = intel_ring_get_tail(ringbuf);
reserved_tail = request->reserved_space;
request->reserved_space = 0;
if (flush_caches) {
if (i915.enable_execlists)
ret = logical_ring_flush_all_caches(request);
else
ret = intel_ring_flush_all_caches(request);
WARN(ret, "*_ring_flush_all_caches failed: %d!\n", ret);
}
trace_i915_gem_request_add(request);
request->head = request_start;
request->batch_obj = obj;
request->emitted_jiffies = jiffies;
request->previous_seqno = engine->last_submitted_seqno;
smp_store_mb(engine->last_submitted_seqno, request->seqno);
list_add_tail(&request->list, &engine->request_list);
request->postfix = intel_ring_get_tail(ringbuf);
if (i915.enable_execlists)
ret = engine->emit_request(request);
else {
ret = engine->add_request(request);
request->tail = intel_ring_get_tail(ringbuf);
}
WARN(ret, "emit|add_request failed: %d!\n", ret);
ret = intel_ring_get_tail(ringbuf) - request_start;
if (ret < 0)
ret += ringbuf->size;
WARN_ONCE(ret > reserved_tail,
"Not enough space reserved (%d bytes) "
"for adding the request (%d bytes)\n",
reserved_tail, ret);
i915_gem_mark_busy(engine);
}
static bool i915_context_is_banned(const struct i915_gem_context *ctx)
{
unsigned long elapsed;
if (ctx->hang_stats.banned)
return true;
elapsed = get_seconds() - ctx->hang_stats.guilty_ts;
if (ctx->hang_stats.ban_period_seconds &&
elapsed <= ctx->hang_stats.ban_period_seconds) {
DRM_DEBUG("context hanging too fast, banning!\n");
return true;
}
return false;
}
static void i915_set_reset_status(struct i915_gem_context *ctx,
const bool guilty)
{
struct i915_ctx_hang_stats *hs = &ctx->hang_stats;
if (guilty) {
hs->banned = i915_context_is_banned(ctx);
hs->batch_active++;
hs->guilty_ts = get_seconds();
} else {
hs->batch_pending++;
}
}
void i915_gem_request_free(struct kref *req_ref)
{
struct drm_i915_gem_request *req = container_of(req_ref,
typeof(*req), ref);
kmem_cache_free(req->i915->requests, req);
}
static inline int
__i915_gem_request_alloc(struct intel_engine_cs *engine,
struct i915_gem_context *ctx,
struct drm_i915_gem_request **req_out)
{
struct drm_i915_private *dev_priv = engine->i915;
unsigned reset_counter = i915_reset_counter(&dev_priv->gpu_error);
struct drm_i915_gem_request *req;
int ret;
if (!req_out)
return -EINVAL;
*req_out = NULL;
ret = i915_gem_check_wedge(reset_counter, dev_priv->mm.interruptible);
if (ret)
return ret;
req = kmem_cache_zalloc(dev_priv->requests, GFP_KERNEL);
if (req == NULL)
return -ENOMEM;
ret = i915_gem_get_seqno(engine->i915, &req->seqno);
if (ret)
goto err;
kref_init(&req->ref);
req->i915 = dev_priv;
req->engine = engine;
req->ctx = ctx;
i915_gem_context_reference(req->ctx);
req->reserved_space = MIN_SPACE_FOR_ADD_REQUEST;
if (i915.enable_execlists)
ret = intel_logical_ring_alloc_request_extras(req);
else
ret = intel_ring_alloc_request_extras(req);
if (ret)
goto err_ctx;
*req_out = req;
return 0;
err_ctx:
i915_gem_context_unreference(ctx);
err:
kmem_cache_free(dev_priv->requests, req);
return ret;
}
struct drm_i915_gem_request *
i915_gem_request_alloc(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct drm_i915_gem_request *req;
int err;
if (ctx == NULL)
ctx = engine->i915->kernel_context;
err = __i915_gem_request_alloc(engine, ctx, &req);
return err ? ERR_PTR(err) : req;
}
struct drm_i915_gem_request *
i915_gem_find_active_request(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request;
list_for_each_entry(request, &engine->request_list, list) {
if (i915_gem_request_completed(request))
continue;
return request;
}
return NULL;
}
static void i915_gem_reset_engine_status(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request;
bool ring_hung;
request = i915_gem_find_active_request(engine);
if (request == NULL)
return;
ring_hung = engine->hangcheck.score >= HANGCHECK_SCORE_RING_HUNG;
i915_set_reset_status(request->ctx, ring_hung);
list_for_each_entry_continue(request, &engine->request_list, list)
i915_set_reset_status(request->ctx, false);
}
static void i915_gem_reset_engine_cleanup(struct intel_engine_cs *engine)
{
struct intel_ringbuffer *buffer;
while (!list_empty(&engine->active_list)) {
struct drm_i915_gem_object *obj;
obj = list_first_entry(&engine->active_list,
struct drm_i915_gem_object,
engine_list[engine->id]);
i915_gem_object_retire__read(obj, engine->id);
}
if (i915.enable_execlists) {
tasklet_kill(&engine->irq_tasklet);
intel_execlists_cancel_requests(engine);
}
while (!list_empty(&engine->request_list)) {
struct drm_i915_gem_request *request;
request = list_first_entry(&engine->request_list,
struct drm_i915_gem_request,
list);
i915_gem_request_retire(request);
}
list_for_each_entry(buffer, &engine->buffers, link) {
buffer->last_retired_head = buffer->tail;
intel_ring_update_space(buffer);
}
intel_ring_init_seqno(engine, engine->last_submitted_seqno);
engine->i915->gt.active_engines &= ~intel_engine_flag(engine);
}
void i915_gem_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine;
for_each_engine(engine, dev_priv)
i915_gem_reset_engine_status(engine);
for_each_engine(engine, dev_priv)
i915_gem_reset_engine_cleanup(engine);
mod_delayed_work(dev_priv->wq, &dev_priv->gt.idle_work, 0);
i915_gem_context_reset(dev);
i915_gem_restore_fences(dev);
WARN_ON(i915_verify_lists(dev));
}
void
i915_gem_retire_requests_ring(struct intel_engine_cs *engine)
{
WARN_ON(i915_verify_lists(engine->dev));
while (!list_empty(&engine->request_list)) {
struct drm_i915_gem_request *request;
request = list_first_entry(&engine->request_list,
struct drm_i915_gem_request,
list);
if (!i915_gem_request_completed(request))
break;
i915_gem_request_retire(request);
}
while (!list_empty(&engine->active_list)) {
struct drm_i915_gem_object *obj;
obj = list_first_entry(&engine->active_list,
struct drm_i915_gem_object,
engine_list[engine->id]);
if (!list_empty(&obj->last_read_req[engine->id]->list))
break;
i915_gem_object_retire__read(obj, engine->id);
}
WARN_ON(i915_verify_lists(engine->dev));
}
void i915_gem_retire_requests(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (dev_priv->gt.active_engines == 0)
return;
GEM_BUG_ON(!dev_priv->gt.awake);
for_each_engine(engine, dev_priv) {
i915_gem_retire_requests_ring(engine);
if (list_empty(&engine->request_list))
dev_priv->gt.active_engines &= ~intel_engine_flag(engine);
}
if (dev_priv->gt.active_engines == 0)
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.idle_work,
msecs_to_jiffies(100));
}
static void
i915_gem_retire_work_handler(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), gt.retire_work.work);
struct drm_device *dev = &dev_priv->drm;
if (mutex_trylock(&dev->struct_mutex)) {
i915_gem_retire_requests(dev_priv);
mutex_unlock(&dev->struct_mutex);
}
if (READ_ONCE(dev_priv->gt.awake))
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.retire_work,
round_jiffies_up_relative(HZ));
}
static void
i915_gem_idle_work_handler(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), gt.idle_work.work);
struct drm_device *dev = &dev_priv->drm;
struct intel_engine_cs *engine;
unsigned int stuck_engines;
bool rearm_hangcheck;
if (!READ_ONCE(dev_priv->gt.awake))
return;
if (READ_ONCE(dev_priv->gt.active_engines))
return;
rearm_hangcheck =
cancel_delayed_work_sync(&dev_priv->gpu_error.hangcheck_work);
if (!mutex_trylock(&dev->struct_mutex)) {
mod_delayed_work(dev_priv->wq,
&dev_priv->gt.idle_work,
msecs_to_jiffies(50));
goto out_rearm;
}
if (dev_priv->gt.active_engines)
goto out_unlock;
for_each_engine(engine, dev_priv)
i915_gem_batch_pool_fini(&engine->batch_pool);
GEM_BUG_ON(!dev_priv->gt.awake);
dev_priv->gt.awake = false;
rearm_hangcheck = false;
stuck_engines = intel_kick_waiters(dev_priv);
if (unlikely(stuck_engines)) {
DRM_DEBUG_DRIVER("kicked stuck waiters...missed irq\n");
dev_priv->gpu_error.missed_irq_rings |= stuck_engines;
}
if (INTEL_GEN(dev_priv) >= 6)
gen6_rps_idle(dev_priv);
intel_runtime_pm_put(dev_priv);
out_unlock:
mutex_unlock(&dev->struct_mutex);
out_rearm:
if (rearm_hangcheck) {
GEM_BUG_ON(!dev_priv->gt.awake);
i915_queue_hangcheck(dev_priv);
}
}
static int
i915_gem_object_flush_active(struct drm_i915_gem_object *obj)
{
int i;
if (!obj->active)
return 0;
for (i = 0; i < I915_NUM_ENGINES; i++) {
struct drm_i915_gem_request *req;
req = obj->last_read_req[i];
if (req == NULL)
continue;
if (i915_gem_request_completed(req))
i915_gem_object_retire__read(obj, i);
}
return 0;
}
int
i915_gem_wait_ioctl(struct drm_device *dev, void *data, struct drm_file *file)
{
struct drm_i915_gem_wait *args = data;
struct drm_i915_gem_object *obj;
struct drm_i915_gem_request *req[I915_NUM_ENGINES];
int i, n = 0;
int ret;
if (args->flags != 0)
return -EINVAL;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, args->bo_handle));
if (&obj->base == NULL) {
mutex_unlock(&dev->struct_mutex);
return -ENOENT;
}
ret = i915_gem_object_flush_active(obj);
if (ret)
goto out;
if (!obj->active)
goto out;
if (args->timeout_ns == 0) {
ret = -ETIME;
goto out;
}
drm_gem_object_unreference(&obj->base);
for (i = 0; i < I915_NUM_ENGINES; i++) {
if (obj->last_read_req[i] == NULL)
continue;
req[n++] = i915_gem_request_reference(obj->last_read_req[i]);
}
mutex_unlock(&dev->struct_mutex);
for (i = 0; i < n; i++) {
if (ret == 0)
ret = __i915_wait_request(req[i], true,
args->timeout_ns > 0 ? &args->timeout_ns : NULL,
to_rps_client(file));
i915_gem_request_unreference(req[i]);
}
return ret;
out:
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int
__i915_gem_object_sync(struct drm_i915_gem_object *obj,
struct intel_engine_cs *to,
struct drm_i915_gem_request *from_req,
struct drm_i915_gem_request **to_req)
{
struct intel_engine_cs *from;
int ret;
from = i915_gem_request_get_engine(from_req);
if (to == from)
return 0;
if (i915_gem_request_completed(from_req))
return 0;
if (!i915_semaphore_is_enabled(to_i915(obj->base.dev))) {
struct drm_i915_private *i915 = to_i915(obj->base.dev);
ret = __i915_wait_request(from_req,
i915->mm.interruptible,
NULL,
&i915->rps.semaphores);
if (ret)
return ret;
i915_gem_object_retire_request(obj, from_req);
} else {
int idx = intel_ring_sync_index(from, to);
u32 seqno = i915_gem_request_get_seqno(from_req);
WARN_ON(!to_req);
if (seqno <= from->semaphore.sync_seqno[idx])
return 0;
if (*to_req == NULL) {
struct drm_i915_gem_request *req;
req = i915_gem_request_alloc(to, NULL);
if (IS_ERR(req))
return PTR_ERR(req);
*to_req = req;
}
trace_i915_gem_ring_sync_to(*to_req, from, from_req);
ret = to->semaphore.sync_to(*to_req, from, seqno);
if (ret)
return ret;
from->semaphore.sync_seqno[idx] =
i915_gem_request_get_seqno(obj->last_read_req[from->id]);
}
return 0;
}
int
i915_gem_object_sync(struct drm_i915_gem_object *obj,
struct intel_engine_cs *to,
struct drm_i915_gem_request **to_req)
{
const bool readonly = obj->base.pending_write_domain == 0;
struct drm_i915_gem_request *req[I915_NUM_ENGINES];
int ret, i, n;
if (!obj->active)
return 0;
if (to == NULL)
return i915_gem_object_wait_rendering(obj, readonly);
n = 0;
if (readonly) {
if (obj->last_write_req)
req[n++] = obj->last_write_req;
} else {
for (i = 0; i < I915_NUM_ENGINES; i++)
if (obj->last_read_req[i])
req[n++] = obj->last_read_req[i];
}
for (i = 0; i < n; i++) {
ret = __i915_gem_object_sync(obj, to, req[i], to_req);
if (ret)
return ret;
}
return 0;
}
static void i915_gem_object_finish_gtt(struct drm_i915_gem_object *obj)
{
u32 old_write_domain, old_read_domains;
i915_gem_release_mmap(obj);
if ((obj->base.read_domains & I915_GEM_DOMAIN_GTT) == 0)
return;
old_read_domains = obj->base.read_domains;
old_write_domain = obj->base.write_domain;
obj->base.read_domains &= ~I915_GEM_DOMAIN_GTT;
obj->base.write_domain &= ~I915_GEM_DOMAIN_GTT;
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
}
static void __i915_vma_iounmap(struct i915_vma *vma)
{
GEM_BUG_ON(vma->pin_count);
if (vma->iomap == NULL)
return;
io_mapping_unmap(vma->iomap);
vma->iomap = NULL;
}
static int __i915_vma_unbind(struct i915_vma *vma, bool wait)
{
struct drm_i915_gem_object *obj = vma->obj;
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
int ret;
if (list_empty(&vma->obj_link))
return 0;
if (!drm_mm_node_allocated(&vma->node)) {
i915_gem_vma_destroy(vma);
return 0;
}
if (vma->pin_count)
return -EBUSY;
BUG_ON(obj->pages == NULL);
if (wait) {
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
}
if (vma->is_ggtt && vma->ggtt_view.type == I915_GGTT_VIEW_NORMAL) {
i915_gem_object_finish_gtt(obj);
ret = i915_gem_object_put_fence(obj);
if (ret)
return ret;
__i915_vma_iounmap(vma);
}
trace_i915_vma_unbind(vma);
vma->vm->unbind_vma(vma);
vma->bound = 0;
list_del_init(&vma->vm_link);
if (vma->is_ggtt) {
if (vma->ggtt_view.type == I915_GGTT_VIEW_NORMAL) {
obj->map_and_fenceable = false;
} else if (vma->ggtt_view.pages) {
sg_free_table(vma->ggtt_view.pages);
kfree(vma->ggtt_view.pages);
}
vma->ggtt_view.pages = NULL;
}
drm_mm_remove_node(&vma->node);
i915_gem_vma_destroy(vma);
if (list_empty(&obj->vma_list))
list_move_tail(&obj->global_list, &dev_priv->mm.unbound_list);
i915_gem_object_unpin_pages(obj);
return 0;
}
int i915_vma_unbind(struct i915_vma *vma)
{
return __i915_vma_unbind(vma, true);
}
int __i915_vma_unbind_no_wait(struct i915_vma *vma)
{
return __i915_vma_unbind(vma, false);
}
int i915_gem_wait_for_idle(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
int ret;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
for_each_engine(engine, dev_priv) {
if (engine->last_context == NULL)
continue;
ret = intel_engine_idle(engine);
if (ret)
return ret;
}
WARN_ON(i915_verify_lists(dev));
return 0;
}
static bool i915_gem_valid_gtt_space(struct i915_vma *vma,
unsigned long cache_level)
{
struct drm_mm_node *gtt_space = &vma->node;
struct drm_mm_node *other;
if (vma->vm->mm.color_adjust == NULL)
return true;
if (!drm_mm_node_allocated(gtt_space))
return true;
if (list_empty(&gtt_space->node_list))
return true;
other = list_entry(gtt_space->node_list.prev, struct drm_mm_node, node_list);
if (other->allocated && !other->hole_follows && other->color != cache_level)
return false;
other = list_entry(gtt_space->node_list.next, struct drm_mm_node, node_list);
if (other->allocated && !gtt_space->hole_follows && other->color != cache_level)
return false;
return true;
}
static struct i915_vma *
i915_gem_object_bind_to_vm(struct drm_i915_gem_object *obj,
struct i915_address_space *vm,
const struct i915_ggtt_view *ggtt_view,
unsigned alignment,
uint64_t flags)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
u32 fence_alignment, unfenced_alignment;
u32 search_flag, alloc_flag;
u64 start, end;
u64 size, fence_size;
struct i915_vma *vma;
int ret;
if (i915_is_ggtt(vm)) {
u32 view_size;
if (WARN_ON(!ggtt_view))
return ERR_PTR(-EINVAL);
view_size = i915_ggtt_view_size(obj, ggtt_view);
fence_size = i915_gem_get_gtt_size(dev,
view_size,
obj->tiling_mode);
fence_alignment = i915_gem_get_gtt_alignment(dev,
view_size,
obj->tiling_mode,
true);
unfenced_alignment = i915_gem_get_gtt_alignment(dev,
view_size,
obj->tiling_mode,
false);
size = flags & PIN_MAPPABLE ? fence_size : view_size;
} else {
fence_size = i915_gem_get_gtt_size(dev,
obj->base.size,
obj->tiling_mode);
fence_alignment = i915_gem_get_gtt_alignment(dev,
obj->base.size,
obj->tiling_mode,
true);
unfenced_alignment =
i915_gem_get_gtt_alignment(dev,
obj->base.size,
obj->tiling_mode,
false);
size = flags & PIN_MAPPABLE ? fence_size : obj->base.size;
}
start = flags & PIN_OFFSET_BIAS ? flags & PIN_OFFSET_MASK : 0;
end = vm->total;
if (flags & PIN_MAPPABLE)
end = min_t(u64, end, ggtt->mappable_end);
if (flags & PIN_ZONE_4G)
end = min_t(u64, end, (1ULL << 32) - PAGE_SIZE);
if (alignment == 0)
alignment = flags & PIN_MAPPABLE ? fence_alignment :
unfenced_alignment;
if (flags & PIN_MAPPABLE && alignment & (fence_alignment - 1)) {
DRM_DEBUG("Invalid object (view type=%u) alignment requested %u\n",
ggtt_view ? ggtt_view->type : 0,
alignment);
return ERR_PTR(-EINVAL);
}
if (size > end) {
DRM_DEBUG("Attempting to bind an object (view type=%u) larger than the aperture: size=%llu > %s aperture=%llu\n",
ggtt_view ? ggtt_view->type : 0,
size,
flags & PIN_MAPPABLE ? "mappable" : "total",
end);
return ERR_PTR(-E2BIG);
}
ret = i915_gem_object_get_pages(obj);
if (ret)
return ERR_PTR(ret);
i915_gem_object_pin_pages(obj);
vma = ggtt_view ? i915_gem_obj_lookup_or_create_ggtt_vma(obj, ggtt_view) :
i915_gem_obj_lookup_or_create_vma(obj, vm);
if (IS_ERR(vma))
goto err_unpin;
if (flags & PIN_OFFSET_FIXED) {
uint64_t offset = flags & PIN_OFFSET_MASK;
if (offset & (alignment - 1) || offset + size > end) {
ret = -EINVAL;
goto err_free_vma;
}
vma->node.start = offset;
vma->node.size = size;
vma->node.color = obj->cache_level;
ret = drm_mm_reserve_node(&vm->mm, &vma->node);
if (ret) {
ret = i915_gem_evict_for_vma(vma);
if (ret == 0)
ret = drm_mm_reserve_node(&vm->mm, &vma->node);
}
if (ret)
goto err_free_vma;
} else {
if (flags & PIN_HIGH) {
search_flag = DRM_MM_SEARCH_BELOW;
alloc_flag = DRM_MM_CREATE_TOP;
} else {
search_flag = DRM_MM_SEARCH_DEFAULT;
alloc_flag = DRM_MM_CREATE_DEFAULT;
}
search_free:
ret = drm_mm_insert_node_in_range_generic(&vm->mm, &vma->node,
size, alignment,
obj->cache_level,
start, end,
search_flag,
alloc_flag);
if (ret) {
ret = i915_gem_evict_something(dev, vm, size, alignment,
obj->cache_level,
start, end,
flags);
if (ret == 0)
goto search_free;
goto err_free_vma;
}
}
if (WARN_ON(!i915_gem_valid_gtt_space(vma, obj->cache_level))) {
ret = -EINVAL;
goto err_remove_node;
}
trace_i915_vma_bind(vma, flags);
ret = i915_vma_bind(vma, obj->cache_level, flags);
if (ret)
goto err_remove_node;
list_move_tail(&obj->global_list, &dev_priv->mm.bound_list);
list_add_tail(&vma->vm_link, &vm->inactive_list);
return vma;
err_remove_node:
drm_mm_remove_node(&vma->node);
err_free_vma:
i915_gem_vma_destroy(vma);
vma = ERR_PTR(ret);
err_unpin:
i915_gem_object_unpin_pages(obj);
return vma;
}
bool
i915_gem_clflush_object(struct drm_i915_gem_object *obj,
bool force)
{
if (obj->pages == NULL)
return false;
if (obj->stolen || obj->phys_handle)
return false;
if (!force && cpu_cache_is_coherent(obj->base.dev, obj->cache_level)) {
obj->cache_dirty = true;
return false;
}
trace_i915_gem_object_clflush(obj);
drm_clflush_sg(obj->pages);
obj->cache_dirty = false;
return true;
}
static void
i915_gem_object_flush_gtt_write_domain(struct drm_i915_gem_object *obj)
{
uint32_t old_write_domain;
if (obj->base.write_domain != I915_GEM_DOMAIN_GTT)
return;
wmb();
old_write_domain = obj->base.write_domain;
obj->base.write_domain = 0;
intel_fb_obj_flush(obj, false, ORIGIN_GTT);
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
old_write_domain);
}
static void
i915_gem_object_flush_cpu_write_domain(struct drm_i915_gem_object *obj)
{
uint32_t old_write_domain;
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU)
return;
if (i915_gem_clflush_object(obj, obj->pin_display))
i915_gem_chipset_flush(to_i915(obj->base.dev));
old_write_domain = obj->base.write_domain;
obj->base.write_domain = 0;
intel_fb_obj_flush(obj, false, ORIGIN_CPU);
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
old_write_domain);
}
int
i915_gem_object_set_to_gtt_domain(struct drm_i915_gem_object *obj, bool write)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
uint32_t old_write_domain, old_read_domains;
struct i915_vma *vma;
int ret;
if (obj->base.write_domain == I915_GEM_DOMAIN_GTT)
return 0;
ret = i915_gem_object_wait_rendering(obj, !write);
if (ret)
return ret;
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
i915_gem_object_flush_cpu_write_domain(obj);
if ((obj->base.read_domains & I915_GEM_DOMAIN_GTT) == 0)
mb();
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
BUG_ON((obj->base.write_domain & ~I915_GEM_DOMAIN_GTT) != 0);
obj->base.read_domains |= I915_GEM_DOMAIN_GTT;
if (write) {
obj->base.read_domains = I915_GEM_DOMAIN_GTT;
obj->base.write_domain = I915_GEM_DOMAIN_GTT;
obj->dirty = 1;
}
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
vma = i915_gem_obj_to_ggtt(obj);
if (vma && drm_mm_node_allocated(&vma->node) && !obj->active)
list_move_tail(&vma->vm_link,
&ggtt->base.inactive_list);
return 0;
}
int i915_gem_object_set_cache_level(struct drm_i915_gem_object *obj,
enum i915_cache_level cache_level)
{
struct drm_device *dev = obj->base.dev;
struct i915_vma *vma, *next;
bool bound = false;
int ret = 0;
if (obj->cache_level == cache_level)
goto out;
list_for_each_entry_safe(vma, next, &obj->vma_list, obj_link) {
if (!drm_mm_node_allocated(&vma->node))
continue;
if (vma->pin_count) {
DRM_DEBUG("can not change the cache level of pinned objects\n");
return -EBUSY;
}
if (!i915_gem_valid_gtt_space(vma, cache_level)) {
ret = i915_vma_unbind(vma);
if (ret)
return ret;
} else
bound = true;
}
if (bound) {
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
if (!HAS_LLC(dev) && cache_level != I915_CACHE_NONE) {
i915_gem_release_mmap(obj);
ret = i915_gem_object_put_fence(obj);
if (ret)
return ret;
} else {
}
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!drm_mm_node_allocated(&vma->node))
continue;
ret = i915_vma_bind(vma, cache_level, PIN_UPDATE);
if (ret)
return ret;
}
}
list_for_each_entry(vma, &obj->vma_list, obj_link)
vma->node.color = cache_level;
obj->cache_level = cache_level;
out:
if (obj->cache_dirty && cpu_write_needs_clflush(obj)) {
if (i915_gem_clflush_object(obj, true))
i915_gem_chipset_flush(to_i915(obj->base.dev));
}
return 0;
}
int i915_gem_get_caching_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_caching *args = data;
struct drm_i915_gem_object *obj;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL)
return -ENOENT;
switch (obj->cache_level) {
case I915_CACHE_LLC:
case I915_CACHE_L3_LLC:
args->caching = I915_CACHING_CACHED;
break;
case I915_CACHE_WT:
args->caching = I915_CACHING_DISPLAY;
break;
default:
args->caching = I915_CACHING_NONE;
break;
}
drm_gem_object_unreference_unlocked(&obj->base);
return 0;
}
int i915_gem_set_caching_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_caching *args = data;
struct drm_i915_gem_object *obj;
enum i915_cache_level level;
int ret;
switch (args->caching) {
case I915_CACHING_NONE:
level = I915_CACHE_NONE;
break;
case I915_CACHING_CACHED:
if (!HAS_LLC(dev) && !HAS_SNOOP(dev))
return -ENODEV;
level = I915_CACHE_LLC;
break;
case I915_CACHING_DISPLAY:
level = HAS_WT(dev) ? I915_CACHE_WT : I915_CACHE_NONE;
break;
default:
return -EINVAL;
}
intel_runtime_pm_get(dev_priv);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto rpm_put;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
ret = i915_gem_object_set_cache_level(obj, level);
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
rpm_put:
intel_runtime_pm_put(dev_priv);
return ret;
}
int
i915_gem_object_pin_to_display_plane(struct drm_i915_gem_object *obj,
u32 alignment,
const struct i915_ggtt_view *view)
{
u32 old_read_domains, old_write_domain;
int ret;
obj->pin_display++;
ret = i915_gem_object_set_cache_level(obj,
HAS_WT(obj->base.dev) ? I915_CACHE_WT : I915_CACHE_NONE);
if (ret)
goto err_unpin_display;
ret = i915_gem_object_ggtt_pin(obj, view, alignment,
view->type == I915_GGTT_VIEW_NORMAL ?
PIN_MAPPABLE : 0);
if (ret)
goto err_unpin_display;
i915_gem_object_flush_cpu_write_domain(obj);
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
obj->base.write_domain = 0;
obj->base.read_domains |= I915_GEM_DOMAIN_GTT;
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
return 0;
err_unpin_display:
obj->pin_display--;
return ret;
}
void
i915_gem_object_unpin_from_display_plane(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view)
{
if (WARN_ON(obj->pin_display == 0))
return;
i915_gem_object_ggtt_unpin_view(obj, view);
obj->pin_display--;
}
int
i915_gem_object_set_to_cpu_domain(struct drm_i915_gem_object *obj, bool write)
{
uint32_t old_write_domain, old_read_domains;
int ret;
if (obj->base.write_domain == I915_GEM_DOMAIN_CPU)
return 0;
ret = i915_gem_object_wait_rendering(obj, !write);
if (ret)
return ret;
i915_gem_object_flush_gtt_write_domain(obj);
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
if ((obj->base.read_domains & I915_GEM_DOMAIN_CPU) == 0) {
i915_gem_clflush_object(obj, false);
obj->base.read_domains |= I915_GEM_DOMAIN_CPU;
}
BUG_ON((obj->base.write_domain & ~I915_GEM_DOMAIN_CPU) != 0);
if (write) {
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
return 0;
}
static int
i915_gem_ring_throttle(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_file_private *file_priv = file->driver_priv;
unsigned long recent_enough = jiffies - DRM_I915_THROTTLE_JIFFIES;
struct drm_i915_gem_request *request, *target = NULL;
int ret;
ret = i915_gem_wait_for_error(&dev_priv->gpu_error);
if (ret)
return ret;
if (i915_terminally_wedged(&dev_priv->gpu_error))
return -EIO;
spin_lock(&file_priv->mm.lock);
list_for_each_entry(request, &file_priv->mm.request_list, client_list) {
if (time_after_eq(request->emitted_jiffies, recent_enough))
break;
if (!request->emitted_jiffies)
continue;
target = request;
}
if (target)
i915_gem_request_reference(target);
spin_unlock(&file_priv->mm.lock);
if (target == NULL)
return 0;
ret = __i915_wait_request(target, true, NULL, NULL);
i915_gem_request_unreference(target);
return ret;
}
static bool
i915_vma_misplaced(struct i915_vma *vma, uint32_t alignment, uint64_t flags)
{
struct drm_i915_gem_object *obj = vma->obj;
if (alignment &&
vma->node.start & (alignment - 1))
return true;
if (flags & PIN_MAPPABLE && !obj->map_and_fenceable)
return true;
if (flags & PIN_OFFSET_BIAS &&
vma->node.start < (flags & PIN_OFFSET_MASK))
return true;
if (flags & PIN_OFFSET_FIXED &&
vma->node.start != (flags & PIN_OFFSET_MASK))
return true;
return false;
}
void __i915_vma_set_map_and_fenceable(struct i915_vma *vma)
{
struct drm_i915_gem_object *obj = vma->obj;
bool mappable, fenceable;
u32 fence_size, fence_alignment;
fence_size = i915_gem_get_gtt_size(obj->base.dev,
obj->base.size,
obj->tiling_mode);
fence_alignment = i915_gem_get_gtt_alignment(obj->base.dev,
obj->base.size,
obj->tiling_mode,
true);
fenceable = (vma->node.size == fence_size &&
(vma->node.start & (fence_alignment - 1)) == 0);
mappable = (vma->node.start + fence_size <=
to_i915(obj->base.dev)->ggtt.mappable_end);
obj->map_and_fenceable = mappable && fenceable;
}
static int
i915_gem_object_do_pin(struct drm_i915_gem_object *obj,
struct i915_address_space *vm,
const struct i915_ggtt_view *ggtt_view,
uint32_t alignment,
uint64_t flags)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
struct i915_vma *vma;
unsigned bound;
int ret;
if (WARN_ON(vm == &dev_priv->mm.aliasing_ppgtt->base))
return -ENODEV;
if (WARN_ON(flags & (PIN_GLOBAL | PIN_MAPPABLE) && !i915_is_ggtt(vm)))
return -EINVAL;
if (WARN_ON((flags & (PIN_MAPPABLE | PIN_GLOBAL)) == PIN_MAPPABLE))
return -EINVAL;
if (WARN_ON(i915_is_ggtt(vm) != !!ggtt_view))
return -EINVAL;
vma = ggtt_view ? i915_gem_obj_to_ggtt_view(obj, ggtt_view) :
i915_gem_obj_to_vma(obj, vm);
if (vma) {
if (WARN_ON(vma->pin_count == DRM_I915_GEM_OBJECT_MAX_PIN_COUNT))
return -EBUSY;
if (i915_vma_misplaced(vma, alignment, flags)) {
WARN(vma->pin_count,
"bo is already pinned in %s with incorrect alignment:"
" offset=%08x %08x, req.alignment=%x, req.map_and_fenceable=%d,"
" obj->map_and_fenceable=%d\n",
ggtt_view ? "ggtt" : "ppgtt",
upper_32_bits(vma->node.start),
lower_32_bits(vma->node.start),
alignment,
!!(flags & PIN_MAPPABLE),
obj->map_and_fenceable);
ret = i915_vma_unbind(vma);
if (ret)
return ret;
vma = NULL;
}
}
bound = vma ? vma->bound : 0;
if (vma == NULL || !drm_mm_node_allocated(&vma->node)) {
vma = i915_gem_object_bind_to_vm(obj, vm, ggtt_view, alignment,
flags);
if (IS_ERR(vma))
return PTR_ERR(vma);
} else {
ret = i915_vma_bind(vma, obj->cache_level, flags);
if (ret)
return ret;
}
if (ggtt_view && ggtt_view->type == I915_GGTT_VIEW_NORMAL &&
(bound ^ vma->bound) & GLOBAL_BIND) {
__i915_vma_set_map_and_fenceable(vma);
WARN_ON(flags & PIN_MAPPABLE && !obj->map_and_fenceable);
}
vma->pin_count++;
return 0;
}
int
i915_gem_object_pin(struct drm_i915_gem_object *obj,
struct i915_address_space *vm,
uint32_t alignment,
uint64_t flags)
{
return i915_gem_object_do_pin(obj, vm,
i915_is_ggtt(vm) ? &i915_ggtt_view_normal : NULL,
alignment, flags);
}
int
i915_gem_object_ggtt_pin(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view,
uint32_t alignment,
uint64_t flags)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
BUG_ON(!view);
return i915_gem_object_do_pin(obj, &ggtt->base, view,
alignment, flags | PIN_GLOBAL);
}
void
i915_gem_object_ggtt_unpin_view(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view)
{
struct i915_vma *vma = i915_gem_obj_to_ggtt_view(obj, view);
WARN_ON(vma->pin_count == 0);
WARN_ON(!i915_gem_obj_ggtt_bound_view(obj, view));
--vma->pin_count;
}
int
i915_gem_busy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_busy *args = data;
struct drm_i915_gem_object *obj;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
ret = i915_gem_object_flush_active(obj);
if (ret)
goto unref;
args->busy = 0;
if (obj->active) {
int i;
for (i = 0; i < I915_NUM_ENGINES; i++) {
struct drm_i915_gem_request *req;
req = obj->last_read_req[i];
if (req)
args->busy |= 1 << (16 + req->engine->exec_id);
}
if (obj->last_write_req)
args->busy |= obj->last_write_req->engine->exec_id;
}
unref:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_throttle_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return i915_gem_ring_throttle(dev, file_priv);
}
int
i915_gem_madvise_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_madvise *args = data;
struct drm_i915_gem_object *obj;
int ret;
switch (args->madv) {
case I915_MADV_DONTNEED:
case I915_MADV_WILLNEED:
break;
default:
return -EINVAL;
}
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(file_priv, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (i915_gem_obj_is_pinned(obj)) {
ret = -EINVAL;
goto out;
}
if (obj->pages &&
obj->tiling_mode != I915_TILING_NONE &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES) {
if (obj->madv == I915_MADV_WILLNEED)
i915_gem_object_unpin_pages(obj);
if (args->madv == I915_MADV_WILLNEED)
i915_gem_object_pin_pages(obj);
}
if (obj->madv != __I915_MADV_PURGED)
obj->madv = args->madv;
if (obj->madv == I915_MADV_DONTNEED && obj->pages == NULL)
i915_gem_object_truncate(obj);
args->retained = obj->madv != __I915_MADV_PURGED;
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
void i915_gem_object_init(struct drm_i915_gem_object *obj,
const struct drm_i915_gem_object_ops *ops)
{
int i;
INIT_LIST_HEAD(&obj->global_list);
for (i = 0; i < I915_NUM_ENGINES; i++)
INIT_LIST_HEAD(&obj->engine_list[i]);
INIT_LIST_HEAD(&obj->obj_exec_link);
INIT_LIST_HEAD(&obj->vma_list);
INIT_LIST_HEAD(&obj->batch_pool_link);
obj->ops = ops;
obj->fence_reg = I915_FENCE_REG_NONE;
obj->madv = I915_MADV_WILLNEED;
i915_gem_info_add_obj(to_i915(obj->base.dev), obj->base.size);
}
struct drm_i915_gem_object *i915_gem_object_create(struct drm_device *dev,
size_t size)
{
struct drm_i915_gem_object *obj;
struct address_space *mapping;
gfp_t mask;
int ret;
obj = i915_gem_object_alloc(dev);
if (obj == NULL)
return ERR_PTR(-ENOMEM);
ret = drm_gem_object_init(dev, &obj->base, size);
if (ret)
goto fail;
mask = GFP_HIGHUSER | __GFP_RECLAIMABLE;
if (IS_CRESTLINE(dev) || IS_BROADWATER(dev)) {
mask &= ~__GFP_HIGHMEM;
mask |= __GFP_DMA32;
}
mapping = obj->base.filp->f_mapping;
mapping_set_gfp_mask(mapping, mask);
i915_gem_object_init(obj, &i915_gem_object_ops);
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
if (HAS_LLC(dev)) {
obj->cache_level = I915_CACHE_LLC;
} else
obj->cache_level = I915_CACHE_NONE;
trace_i915_gem_object_create(obj);
return obj;
fail:
i915_gem_object_free(obj);
return ERR_PTR(ret);
}
static bool discard_backing_storage(struct drm_i915_gem_object *obj)
{
if (obj->madv != I915_MADV_WILLNEED)
return false;
if (obj->base.filp == NULL)
return true;
return atomic_long_read(&obj->base.filp->f_count) == 1;
}
void i915_gem_free_object(struct drm_gem_object *gem_obj)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem_obj);
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_vma *vma, *next;
intel_runtime_pm_get(dev_priv);
trace_i915_gem_object_destroy(obj);
list_for_each_entry_safe(vma, next, &obj->vma_list, obj_link) {
int ret;
vma->pin_count = 0;
ret = i915_vma_unbind(vma);
if (WARN_ON(ret == -ERESTARTSYS)) {
bool was_interruptible;
was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
WARN_ON(i915_vma_unbind(vma));
dev_priv->mm.interruptible = was_interruptible;
}
}
if (obj->stolen)
i915_gem_object_unpin_pages(obj);
WARN_ON(obj->frontbuffer_bits);
if (obj->pages && obj->madv == I915_MADV_WILLNEED &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES &&
obj->tiling_mode != I915_TILING_NONE)
i915_gem_object_unpin_pages(obj);
if (WARN_ON(obj->pages_pin_count))
obj->pages_pin_count = 0;
if (discard_backing_storage(obj))
obj->madv = I915_MADV_DONTNEED;
i915_gem_object_put_pages(obj);
i915_gem_object_free_mmap_offset(obj);
BUG_ON(obj->pages);
if (obj->base.import_attach)
drm_prime_gem_destroy(&obj->base, NULL);
if (obj->ops->release)
obj->ops->release(obj);
drm_gem_object_release(&obj->base);
i915_gem_info_remove_obj(dev_priv, obj->base.size);
kfree(obj->bit_17);
i915_gem_object_free(obj);
intel_runtime_pm_put(dev_priv);
}
struct i915_vma *i915_gem_obj_to_vma(struct drm_i915_gem_object *obj,
struct i915_address_space *vm)
{
struct i915_vma *vma;
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (vma->ggtt_view.type == I915_GGTT_VIEW_NORMAL &&
vma->vm == vm)
return vma;
}
return NULL;
}
struct i915_vma *i915_gem_obj_to_ggtt_view(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view)
{
struct i915_vma *vma;
GEM_BUG_ON(!view);
list_for_each_entry(vma, &obj->vma_list, obj_link)
if (vma->is_ggtt && i915_ggtt_view_equal(&vma->ggtt_view, view))
return vma;
return NULL;
}
void i915_gem_vma_destroy(struct i915_vma *vma)
{
WARN_ON(vma->node.allocated);
if (!list_empty(&vma->exec_list))
return;
if (!vma->is_ggtt)
i915_ppgtt_put(i915_vm_to_ppgtt(vma->vm));
list_del(&vma->obj_link);
kmem_cache_free(to_i915(vma->obj->base.dev)->vmas, vma);
}
static void
i915_gem_stop_engines(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine;
for_each_engine(engine, dev_priv)
dev_priv->gt.stop_engine(engine);
}
int
i915_gem_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret = 0;
mutex_lock(&dev->struct_mutex);
ret = i915_gem_wait_for_idle(dev_priv);
if (ret)
goto err;
i915_gem_retire_requests(dev_priv);
i915_gem_stop_engines(dev);
i915_gem_context_lost(dev_priv);
mutex_unlock(&dev->struct_mutex);
cancel_delayed_work_sync(&dev_priv->gpu_error.hangcheck_work);
cancel_delayed_work_sync(&dev_priv->gt.retire_work);
flush_delayed_work(&dev_priv->gt.idle_work);
WARN_ON(dev_priv->gt.awake);
return 0;
err:
mutex_unlock(&dev->struct_mutex);
return ret;
}
void i915_gem_init_swizzling(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (INTEL_INFO(dev)->gen < 5 ||
dev_priv->mm.bit_6_swizzle_x == I915_BIT_6_SWIZZLE_NONE)
return;
I915_WRITE(DISP_ARB_CTL, I915_READ(DISP_ARB_CTL) |
DISP_TILE_SURFACE_SWIZZLING);
if (IS_GEN5(dev))
return;
I915_WRITE(TILECTL, I915_READ(TILECTL) | TILECTL_SWZCTL);
if (IS_GEN6(dev))
I915_WRITE(ARB_MODE, _MASKED_BIT_ENABLE(ARB_MODE_SWIZZLE_SNB));
else if (IS_GEN7(dev))
I915_WRITE(ARB_MODE, _MASKED_BIT_ENABLE(ARB_MODE_SWIZZLE_IVB));
else if (IS_GEN8(dev))
I915_WRITE(GAMTARBMODE, _MASKED_BIT_ENABLE(ARB_MODE_SWIZZLE_BDW));
else
BUG();
}
static void init_unused_ring(struct drm_device *dev, u32 base)
{
struct drm_i915_private *dev_priv = to_i915(dev);
I915_WRITE(RING_CTL(base), 0);
I915_WRITE(RING_HEAD(base), 0);
I915_WRITE(RING_TAIL(base), 0);
I915_WRITE(RING_START(base), 0);
}
static void init_unused_rings(struct drm_device *dev)
{
if (IS_I830(dev)) {
init_unused_ring(dev, PRB1_BASE);
init_unused_ring(dev, SRB0_BASE);
init_unused_ring(dev, SRB1_BASE);
init_unused_ring(dev, SRB2_BASE);
init_unused_ring(dev, SRB3_BASE);
} else if (IS_GEN2(dev)) {
init_unused_ring(dev, SRB0_BASE);
init_unused_ring(dev, SRB1_BASE);
} else if (IS_GEN3(dev)) {
init_unused_ring(dev, PRB1_BASE);
init_unused_ring(dev, PRB2_BASE);
}
}
int i915_gem_init_engines(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
ret = intel_init_render_ring_buffer(dev);
if (ret)
return ret;
if (HAS_BSD(dev)) {
ret = intel_init_bsd_ring_buffer(dev);
if (ret)
goto cleanup_render_ring;
}
if (HAS_BLT(dev)) {
ret = intel_init_blt_ring_buffer(dev);
if (ret)
goto cleanup_bsd_ring;
}
if (HAS_VEBOX(dev)) {
ret = intel_init_vebox_ring_buffer(dev);
if (ret)
goto cleanup_blt_ring;
}
if (HAS_BSD2(dev)) {
ret = intel_init_bsd2_ring_buffer(dev);
if (ret)
goto cleanup_vebox_ring;
}
return 0;
cleanup_vebox_ring:
intel_cleanup_engine(&dev_priv->engine[VECS]);
cleanup_blt_ring:
intel_cleanup_engine(&dev_priv->engine[BCS]);
cleanup_bsd_ring:
intel_cleanup_engine(&dev_priv->engine[VCS]);
cleanup_render_ring:
intel_cleanup_engine(&dev_priv->engine[RCS]);
return ret;
}
int
i915_gem_init_hw(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine;
int ret;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
if (HAS_EDRAM(dev) && INTEL_GEN(dev_priv) < 9)
I915_WRITE(HSW_IDICR, I915_READ(HSW_IDICR) | IDIHASHMSK(0xf));
if (IS_HASWELL(dev))
I915_WRITE(MI_PREDICATE_RESULT_2, IS_HSW_GT3(dev) ?
LOWER_SLICE_ENABLED : LOWER_SLICE_DISABLED);
if (HAS_PCH_NOP(dev)) {
if (IS_IVYBRIDGE(dev)) {
u32 temp = I915_READ(GEN7_MSG_CTL);
temp &= ~(WAIT_FOR_PCH_FLR_ACK | WAIT_FOR_PCH_RESET_ACK);
I915_WRITE(GEN7_MSG_CTL, temp);
} else if (INTEL_INFO(dev)->gen >= 7) {
u32 temp = I915_READ(HSW_NDE_RSTWRN_OPT);
temp &= ~RESET_PCH_HANDSHAKE_ENABLE;
I915_WRITE(HSW_NDE_RSTWRN_OPT, temp);
}
}
i915_gem_init_swizzling(dev);
init_unused_rings(dev);
BUG_ON(!dev_priv->kernel_context);
ret = i915_ppgtt_init_hw(dev);
if (ret) {
DRM_ERROR("PPGTT enable HW failed %d\n", ret);
goto out;
}
for_each_engine(engine, dev_priv) {
ret = engine->init_hw(engine);
if (ret)
goto out;
}
intel_mocs_init_l3cc_table(dev);
ret = intel_guc_setup(dev);
if (ret)
goto out;
out:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
int i915_gem_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
mutex_lock(&dev->struct_mutex);
if (!i915.enable_execlists) {
dev_priv->gt.execbuf_submit = i915_gem_ringbuffer_submission;
dev_priv->gt.init_engines = i915_gem_init_engines;
dev_priv->gt.cleanup_engine = intel_cleanup_engine;
dev_priv->gt.stop_engine = intel_stop_engine;
} else {
dev_priv->gt.execbuf_submit = intel_execlists_submission;
dev_priv->gt.init_engines = intel_logical_rings_init;
dev_priv->gt.cleanup_engine = intel_logical_ring_cleanup;
dev_priv->gt.stop_engine = intel_logical_ring_stop;
}
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
i915_gem_init_userptr(dev_priv);
i915_gem_init_ggtt(dev);
ret = i915_gem_context_init(dev);
if (ret)
goto out_unlock;
ret = dev_priv->gt.init_engines(dev);
if (ret)
goto out_unlock;
ret = i915_gem_init_hw(dev);
if (ret == -EIO) {
DRM_ERROR("Failed to initialize GPU, declaring it wedged\n");
atomic_or(I915_WEDGED, &dev_priv->gpu_error.reset_counter);
ret = 0;
}
out_unlock:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
mutex_unlock(&dev->struct_mutex);
return ret;
}
void
i915_gem_cleanup_engines(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine;
for_each_engine(engine, dev_priv)
dev_priv->gt.cleanup_engine(engine);
}
static void
init_engine_lists(struct intel_engine_cs *engine)
{
INIT_LIST_HEAD(&engine->active_list);
INIT_LIST_HEAD(&engine->request_list);
}
void
i915_gem_load_init_fences(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
if (INTEL_INFO(dev_priv)->gen >= 7 && !IS_VALLEYVIEW(dev_priv) &&
!IS_CHERRYVIEW(dev_priv))
dev_priv->num_fence_regs = 32;
else if (INTEL_INFO(dev_priv)->gen >= 4 || IS_I945G(dev_priv) ||
IS_I945GM(dev_priv) || IS_G33(dev_priv))
dev_priv->num_fence_regs = 16;
else
dev_priv->num_fence_regs = 8;
if (intel_vgpu_active(dev_priv))
dev_priv->num_fence_regs =
I915_READ(vgtif_reg(avail_rs.fence_num));
i915_gem_restore_fences(dev);
i915_gem_detect_bit_6_swizzle(dev);
}
void
i915_gem_load_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int i;
dev_priv->objects =
kmem_cache_create("i915_gem_object",
sizeof(struct drm_i915_gem_object), 0,
SLAB_HWCACHE_ALIGN,
NULL);
dev_priv->vmas =
kmem_cache_create("i915_gem_vma",
sizeof(struct i915_vma), 0,
SLAB_HWCACHE_ALIGN,
NULL);
dev_priv->requests =
kmem_cache_create("i915_gem_request",
sizeof(struct drm_i915_gem_request), 0,
SLAB_HWCACHE_ALIGN,
NULL);
INIT_LIST_HEAD(&dev_priv->vm_list);
INIT_LIST_HEAD(&dev_priv->context_list);
INIT_LIST_HEAD(&dev_priv->mm.unbound_list);
INIT_LIST_HEAD(&dev_priv->mm.bound_list);
INIT_LIST_HEAD(&dev_priv->mm.fence_list);
for (i = 0; i < I915_NUM_ENGINES; i++)
init_engine_lists(&dev_priv->engine[i]);
for (i = 0; i < I915_MAX_NUM_FENCES; i++)
INIT_LIST_HEAD(&dev_priv->fence_regs[i].lru_list);
INIT_DELAYED_WORK(&dev_priv->gt.retire_work,
i915_gem_retire_work_handler);
INIT_DELAYED_WORK(&dev_priv->gt.idle_work,
i915_gem_idle_work_handler);
init_waitqueue_head(&dev_priv->gpu_error.wait_queue);
init_waitqueue_head(&dev_priv->gpu_error.reset_queue);
dev_priv->relative_constants_mode = I915_EXEC_CONSTANTS_REL_GENERAL;
INIT_LIST_HEAD(&dev_priv->mm.fence_list);
init_waitqueue_head(&dev_priv->pending_flip_queue);
dev_priv->mm.interruptible = true;
mutex_init(&dev_priv->fb_tracking.lock);
}
void i915_gem_load_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
kmem_cache_destroy(dev_priv->requests);
kmem_cache_destroy(dev_priv->vmas);
kmem_cache_destroy(dev_priv->objects);
}
int i915_gem_freeze_late(struct drm_i915_private *dev_priv)
{
struct drm_i915_gem_object *obj;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_list) {
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
return 0;
}
void i915_gem_release(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
spin_lock(&file_priv->mm.lock);
while (!list_empty(&file_priv->mm.request_list)) {
struct drm_i915_gem_request *request;
request = list_first_entry(&file_priv->mm.request_list,
struct drm_i915_gem_request,
client_list);
list_del(&request->client_list);
request->file_priv = NULL;
}
spin_unlock(&file_priv->mm.lock);
if (!list_empty(&file_priv->rps.link)) {
spin_lock(&to_i915(dev)->rps.client_lock);
list_del(&file_priv->rps.link);
spin_unlock(&to_i915(dev)->rps.client_lock);
}
}
int i915_gem_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv;
int ret;
DRM_DEBUG_DRIVER("\n");
file_priv = kzalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
file_priv->dev_priv = to_i915(dev);
file_priv->file = file;
INIT_LIST_HEAD(&file_priv->rps.link);
spin_lock_init(&file_priv->mm.lock);
INIT_LIST_HEAD(&file_priv->mm.request_list);
file_priv->bsd_ring = -1;
ret = i915_gem_context_open(dev, file);
if (ret)
kfree(file_priv);
return ret;
}
void i915_gem_track_fb(struct drm_i915_gem_object *old,
struct drm_i915_gem_object *new,
unsigned frontbuffer_bits)
{
if (old) {
WARN_ON(!mutex_is_locked(&old->base.dev->struct_mutex));
WARN_ON(!(old->frontbuffer_bits & frontbuffer_bits));
old->frontbuffer_bits &= ~frontbuffer_bits;
}
if (new) {
WARN_ON(!mutex_is_locked(&new->base.dev->struct_mutex));
WARN_ON(new->frontbuffer_bits & frontbuffer_bits);
new->frontbuffer_bits |= frontbuffer_bits;
}
}
u64 i915_gem_obj_offset(struct drm_i915_gem_object *o,
struct i915_address_space *vm)
{
struct drm_i915_private *dev_priv = to_i915(o->base.dev);
struct i915_vma *vma;
WARN_ON(vm == &dev_priv->mm.aliasing_ppgtt->base);
list_for_each_entry(vma, &o->vma_list, obj_link) {
if (vma->is_ggtt &&
vma->ggtt_view.type != I915_GGTT_VIEW_NORMAL)
continue;
if (vma->vm == vm)
return vma->node.start;
}
WARN(1, "%s vma for this object not found.\n",
i915_is_ggtt(vm) ? "global" : "ppgtt");
return -1;
}
u64 i915_gem_obj_ggtt_offset_view(struct drm_i915_gem_object *o,
const struct i915_ggtt_view *view)
{
struct i915_vma *vma;
list_for_each_entry(vma, &o->vma_list, obj_link)
if (vma->is_ggtt && i915_ggtt_view_equal(&vma->ggtt_view, view))
return vma->node.start;
WARN(1, "global vma for this object not found. (view=%u)\n", view->type);
return -1;
}
bool i915_gem_obj_bound(struct drm_i915_gem_object *o,
struct i915_address_space *vm)
{
struct i915_vma *vma;
list_for_each_entry(vma, &o->vma_list, obj_link) {
if (vma->is_ggtt &&
vma->ggtt_view.type != I915_GGTT_VIEW_NORMAL)
continue;
if (vma->vm == vm && drm_mm_node_allocated(&vma->node))
return true;
}
return false;
}
bool i915_gem_obj_ggtt_bound_view(struct drm_i915_gem_object *o,
const struct i915_ggtt_view *view)
{
struct i915_vma *vma;
list_for_each_entry(vma, &o->vma_list, obj_link)
if (vma->is_ggtt &&
i915_ggtt_view_equal(&vma->ggtt_view, view) &&
drm_mm_node_allocated(&vma->node))
return true;
return false;
}
bool i915_gem_obj_bound_any(struct drm_i915_gem_object *o)
{
struct i915_vma *vma;
list_for_each_entry(vma, &o->vma_list, obj_link)
if (drm_mm_node_allocated(&vma->node))
return true;
return false;
}
unsigned long i915_gem_obj_ggtt_size(struct drm_i915_gem_object *o)
{
struct i915_vma *vma;
GEM_BUG_ON(list_empty(&o->vma_list));
list_for_each_entry(vma, &o->vma_list, obj_link) {
if (vma->is_ggtt &&
vma->ggtt_view.type == I915_GGTT_VIEW_NORMAL)
return vma->node.size;
}
return 0;
}
bool i915_gem_obj_is_pinned(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
list_for_each_entry(vma, &obj->vma_list, obj_link)
if (vma->pin_count > 0)
return true;
return false;
}
struct page *
i915_gem_object_get_dirty_page(struct drm_i915_gem_object *obj, int n)
{
struct page *page;
if (WARN_ON(!i915_gem_object_has_struct_page(obj)))
return NULL;
page = i915_gem_object_get_page(obj, n);
set_page_dirty(page);
return page;
}
struct drm_i915_gem_object *
i915_gem_object_create_from_data(struct drm_device *dev,
const void *data, size_t size)
{
struct drm_i915_gem_object *obj;
struct sg_table *sg;
size_t bytes;
int ret;
obj = i915_gem_object_create(dev, round_up(size, PAGE_SIZE));
if (IS_ERR(obj))
return obj;
ret = i915_gem_object_set_to_cpu_domain(obj, true);
if (ret)
goto fail;
ret = i915_gem_object_get_pages(obj);
if (ret)
goto fail;
i915_gem_object_pin_pages(obj);
sg = obj->pages;
bytes = sg_copy_from_buffer(sg->sgl, sg->nents, (void *)data, size);
obj->dirty = 1;
i915_gem_object_unpin_pages(obj);
if (WARN_ON(bytes != size)) {
DRM_ERROR("Incomplete copy, wrote %zu of %zu", bytes, size);
ret = -EFAULT;
goto fail;
}
return obj;
fail:
drm_gem_object_unreference(&obj->base);
return ERR_PTR(ret);
}
