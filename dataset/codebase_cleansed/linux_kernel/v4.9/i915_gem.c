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
if (i915_vma_is_pinned(vma))
pinned += vma->node.size;
list_for_each_entry(vma, &ggtt->base.inactive_list, vm_link)
if (i915_vma_is_pinned(vma))
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
int i915_gem_object_unbind(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
LIST_HEAD(still_in_list);
int ret;
lockdep_assert_held(&obj->base.dev->struct_mutex);
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
i915_gem_retire_requests(to_i915(obj->base.dev));
while ((vma = list_first_entry_or_null(&obj->vma_list,
struct i915_vma,
obj_link))) {
list_move_tail(&vma->obj_link, &still_in_list);
ret = i915_vma_unbind(vma);
if (ret)
break;
}
list_splice(&still_in_list, &obj->vma_list);
return ret;
}
int
i915_gem_object_wait_rendering(struct drm_i915_gem_object *obj,
bool readonly)
{
struct reservation_object *resv;
struct i915_gem_active *active;
unsigned long active_mask;
int idx;
lockdep_assert_held(&obj->base.dev->struct_mutex);
if (!readonly) {
active = obj->last_read;
active_mask = i915_gem_object_get_active(obj);
} else {
active_mask = 1;
active = &obj->last_write;
}
for_each_active(active_mask, idx) {
int ret;
ret = i915_gem_active_wait(&active[idx],
&obj->base.dev->struct_mutex);
if (ret)
return ret;
}
resv = i915_gem_object_get_dmabuf_resv(obj);
if (resv) {
long err;
err = reservation_object_wait_timeout_rcu(resv, !readonly, true,
MAX_SCHEDULE_TIMEOUT);
if (err < 0)
return err;
}
return 0;
}
static __must_check int
__unsafe_wait_rendering(struct drm_i915_gem_object *obj,
struct intel_rps_client *rps,
bool readonly)
{
struct i915_gem_active *active;
unsigned long active_mask;
int idx;
active_mask = __I915_BO_ACTIVE(obj);
if (!active_mask)
return 0;
if (!readonly) {
active = obj->last_read;
} else {
active_mask = 1;
active = &obj->last_write;
}
for_each_active(active_mask, idx) {
int ret;
ret = i915_gem_active_wait_unlocked(&active[idx],
I915_WAIT_INTERRUPTIBLE,
NULL, rps);
if (ret)
return ret;
}
return 0;
}
static struct intel_rps_client *to_rps_client(struct drm_file *file)
{
struct drm_i915_file_private *fpriv = file->driver_priv;
return &fpriv->rps;
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
ret = i915_gem_object_unbind(obj);
if (ret)
return ret;
ret = i915_gem_object_put_pages(obj);
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
i915_gem_object_put_unlocked(obj);
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
unsigned int *needs_clflush)
{
int ret;
*needs_clflush = 0;
if (!i915_gem_object_has_struct_page(obj))
return -ENODEV;
ret = i915_gem_object_wait_rendering(obj, true);
if (ret)
return ret;
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
i915_gem_object_pin_pages(obj);
i915_gem_object_flush_gtt_write_domain(obj);
if (!(obj->base.read_domains & I915_GEM_DOMAIN_CPU))
*needs_clflush = !cpu_cache_is_coherent(obj->base.dev,
obj->cache_level);
if (*needs_clflush && !static_cpu_has(X86_FEATURE_CLFLUSH)) {
ret = i915_gem_object_set_to_cpu_domain(obj, false);
if (ret)
goto err_unpin;
*needs_clflush = 0;
}
return 0;
err_unpin:
i915_gem_object_unpin_pages(obj);
return ret;
}
int i915_gem_obj_prepare_shmem_write(struct drm_i915_gem_object *obj,
unsigned int *needs_clflush)
{
int ret;
*needs_clflush = 0;
if (!i915_gem_object_has_struct_page(obj))
return -ENODEV;
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
i915_gem_object_pin_pages(obj);
i915_gem_object_flush_gtt_write_domain(obj);
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU)
*needs_clflush |= cpu_write_needs_clflush(obj) << 1;
if (!(obj->base.read_domains & I915_GEM_DOMAIN_CPU))
*needs_clflush |= !cpu_cache_is_coherent(obj->base.dev,
obj->cache_level);
if (*needs_clflush && !static_cpu_has(X86_FEATURE_CLFLUSH)) {
ret = i915_gem_object_set_to_cpu_domain(obj, true);
if (ret)
goto err_unpin;
*needs_clflush = 0;
}
if ((*needs_clflush & CLFLUSH_AFTER) == 0)
obj->cache_dirty = true;
intel_fb_obj_invalidate(obj, ORIGIN_CPU);
obj->dirty = 1;
return 0;
err_unpin:
i915_gem_object_unpin_pages(obj);
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
struct i915_vma *vma;
struct drm_mm_node node;
char __user *user_data;
uint64_t remain;
uint64_t offset;
int ret;
vma = i915_gem_object_ggtt_pin(obj, NULL, 0, 0, PIN_MAPPABLE);
if (!IS_ERR(vma)) {
node.start = i915_ggtt_offset(vma);
node.allocated = false;
ret = i915_vma_put_fence(vma);
if (ret) {
i915_vma_unpin(vma);
vma = ERR_PTR(ret);
}
}
if (IS_ERR(vma)) {
ret = insert_mappable_node(dev_priv, &node, PAGE_SIZE);
if (ret)
goto out;
ret = i915_gem_object_get_pages(obj);
if (ret) {
remove_mappable_node(&node);
goto out;
}
i915_gem_object_pin_pages(obj);
}
ret = i915_gem_object_set_to_gtt_domain(obj, false);
if (ret)
goto out_unpin;
user_data = u64_to_user_ptr(data_ptr);
remain = size;
offset = data_offset;
mutex_unlock(&dev->struct_mutex);
if (likely(!i915.prefault_disable)) {
ret = fault_in_pages_writeable(user_data, remain);
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
if (slow_user_access(&ggtt->mappable, page_base,
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
i915_vma_unpin(vma);
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
ret = i915_gem_obj_prepare_shmem_read(obj, &needs_clflush);
if (ret)
return ret;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
user_data = u64_to_user_ptr(args->data_ptr);
offset = args->offset;
remain = args->size;
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
ret = fault_in_pages_writeable(user_data, remain);
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
i915_gem_obj_finish_shmem_access(obj);
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
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto err;
}
trace_i915_gem_object_pread(obj, args->offset, args->size);
ret = __unsafe_wait_rendering(obj, to_rps_client(file), true);
if (ret)
goto err;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto err;
ret = i915_gem_shmem_pread(dev, obj, args, file);
if (ret == -EFAULT || ret == -ENODEV) {
intel_runtime_pm_get(to_i915(dev));
ret = i915_gem_gtt_pread(dev, obj, args->size,
args->offset, args->data_ptr);
intel_runtime_pm_put(to_i915(dev));
}
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
return ret;
err:
i915_gem_object_put_unlocked(obj);
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
struct i915_vma *vma;
struct drm_mm_node node;
uint64_t remain, offset;
char __user *user_data;
int ret;
bool hit_slow_path = false;
if (i915_gem_object_is_tiled(obj))
return -EFAULT;
vma = i915_gem_object_ggtt_pin(obj, NULL, 0, 0,
PIN_MAPPABLE | PIN_NONBLOCK);
if (!IS_ERR(vma)) {
node.start = i915_ggtt_offset(vma);
node.allocated = false;
ret = i915_vma_put_fence(vma);
if (ret) {
i915_vma_unpin(vma);
vma = ERR_PTR(ret);
}
}
if (IS_ERR(vma)) {
ret = insert_mappable_node(i915, &node, PAGE_SIZE);
if (ret)
goto out;
ret = i915_gem_object_get_pages(obj);
if (ret) {
remove_mappable_node(&node);
goto out;
}
i915_gem_object_pin_pages(obj);
}
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
goto out_unpin;
intel_fb_obj_invalidate(obj, ORIGIN_CPU);
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
if (fast_user_write(&ggtt->mappable, page_base,
page_offset, user_data, page_length)) {
hit_slow_path = true;
mutex_unlock(&dev->struct_mutex);
if (slow_user_access(&ggtt->mappable,
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
intel_fb_obj_flush(obj, false, ORIGIN_CPU);
out_unpin:
if (node.allocated) {
wmb();
ggtt->base.clear_range(&ggtt->base,
node.start, node.size,
true);
i915_gem_object_unpin_pages(obj);
remove_mappable_node(&node);
} else {
i915_vma_unpin(vma);
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
unsigned int needs_clflush;
struct sg_page_iter sg_iter;
ret = i915_gem_obj_prepare_shmem_write(obj, &needs_clflush);
if (ret)
return ret;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
user_data = u64_to_user_ptr(args->data_ptr);
offset = args->offset;
remain = args->size;
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
partial_cacheline_write = needs_clflush & CLFLUSH_BEFORE &&
((shmem_page_offset | page_length)
& (boot_cpu_data.x86_clflush_size - 1));
page_do_bit17_swizzling = obj_do_bit17_swizzling &&
(page_to_phys(page) & (1 << 17)) != 0;
ret = shmem_pwrite_fast(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush & CLFLUSH_AFTER);
if (ret == 0)
goto next_page;
hit_slowpath = 1;
mutex_unlock(&dev->struct_mutex);
ret = shmem_pwrite_slow(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush & CLFLUSH_AFTER);
mutex_lock(&dev->struct_mutex);
if (ret)
goto out;
next_page:
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out:
i915_gem_obj_finish_shmem_access(obj);
if (hit_slowpath) {
if (!(needs_clflush & CLFLUSH_AFTER) &&
obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
if (i915_gem_clflush_object(obj, obj->pin_display))
needs_clflush |= CLFLUSH_AFTER;
}
}
if (needs_clflush & CLFLUSH_AFTER)
i915_gem_chipset_flush(to_i915(dev));
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
ret = fault_in_pages_readable(u64_to_user_ptr(args->data_ptr),
args->size);
if (ret)
return -EFAULT;
}
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto err;
}
trace_i915_gem_object_pwrite(obj, args->offset, args->size);
ret = __unsafe_wait_rendering(obj, to_rps_client(file), false);
if (ret)
goto err;
intel_runtime_pm_get(dev_priv);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto err_rpm;
ret = -EFAULT;
if (!i915_gem_object_has_struct_page(obj) ||
cpu_write_needs_clflush(obj)) {
ret = i915_gem_gtt_pwrite_fast(dev_priv, obj, args, file);
}
if (ret == -EFAULT || ret == -ENOSPC) {
if (obj->phys_handle)
ret = i915_gem_phys_pwrite(obj, args, file);
else
ret = i915_gem_shmem_pwrite(dev, obj, args, file);
}
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
intel_runtime_pm_put(dev_priv);
return ret;
err_rpm:
intel_runtime_pm_put(dev_priv);
err:
i915_gem_object_put_unlocked(obj);
return ret;
}
static inline enum fb_op_origin
write_origin(struct drm_i915_gem_object *obj, unsigned domain)
{
return (domain == I915_GEM_DOMAIN_GTT ?
obj->frontbuffer_ggtt_origin : ORIGIN_CPU);
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
if ((write_domain | read_domains) & I915_GEM_GPU_DOMAINS)
return -EINVAL;
if (write_domain != 0 && read_domains != write_domain)
return -EINVAL;
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
ret = __unsafe_wait_rendering(obj, to_rps_client(file), !write_domain);
if (ret)
goto err;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto err;
if (read_domains & I915_GEM_DOMAIN_GTT)
ret = i915_gem_object_set_to_gtt_domain(obj, write_domain != 0);
else
ret = i915_gem_object_set_to_cpu_domain(obj, write_domain != 0);
if (write_domain != 0)
intel_fb_obj_invalidate(obj, write_origin(obj, write_domain));
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
return ret;
err:
i915_gem_object_put_unlocked(obj);
return ret;
}
int
i915_gem_sw_finish_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_sw_finish *args = data;
struct drm_i915_gem_object *obj;
int err = 0;
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (READ_ONCE(obj->pin_display)) {
err = i915_mutex_lock_interruptible(dev);
if (!err) {
i915_gem_object_flush_cpu_write_domain(obj);
mutex_unlock(&dev->struct_mutex);
}
}
i915_gem_object_put_unlocked(obj);
return err;
}
int
i915_gem_mmap_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_mmap *args = data;
struct drm_i915_gem_object *obj;
unsigned long addr;
if (args->flags & ~(I915_MMAP_WC))
return -EINVAL;
if (args->flags & I915_MMAP_WC && !boot_cpu_has(X86_FEATURE_PAT))
return -ENODEV;
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (!obj->base.filp) {
i915_gem_object_put_unlocked(obj);
return -EINVAL;
}
addr = vm_mmap(obj->base.filp, 0, args->size,
PROT_READ | PROT_WRITE, MAP_SHARED,
args->offset);
if (args->flags & I915_MMAP_WC) {
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
if (down_write_killable(&mm->mmap_sem)) {
i915_gem_object_put_unlocked(obj);
return -EINTR;
}
vma = find_vma(mm, addr);
if (vma)
vma->vm_page_prot =
pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
else
addr = -ENOMEM;
up_write(&mm->mmap_sem);
WRITE_ONCE(obj->frontbuffer_ggtt_origin, ORIGIN_CPU);
}
i915_gem_object_put_unlocked(obj);
if (IS_ERR((void *)addr))
return addr;
args->addr_ptr = (uint64_t) addr;
return 0;
}
static unsigned int tile_row_pages(struct drm_i915_gem_object *obj)
{
u64 size;
size = i915_gem_object_get_stride(obj);
size *= i915_gem_object_get_tiling(obj) == I915_TILING_Y ? 32 : 8;
return size >> PAGE_SHIFT;
}
int i915_gem_mmap_gtt_version(void)
{
return 1;
}
int i915_gem_fault(struct vm_area_struct *area, struct vm_fault *vmf)
{
#define MIN_CHUNK_PAGES ((1 << 20) >> PAGE_SHIFT)
struct drm_i915_gem_object *obj = to_intel_bo(area->vm_private_data);
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
bool write = !!(vmf->flags & FAULT_FLAG_WRITE);
struct i915_vma *vma;
pgoff_t page_offset;
unsigned int flags;
int ret;
page_offset = ((unsigned long)vmf->virtual_address - area->vm_start) >>
PAGE_SHIFT;
trace_i915_gem_object_fault(obj, page_offset, true, write);
ret = __unsafe_wait_rendering(obj, NULL, !write);
if (ret)
goto err;
intel_runtime_pm_get(dev_priv);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto err_rpm;
if (obj->cache_level != I915_CACHE_NONE && !HAS_LLC(dev)) {
ret = -EFAULT;
goto err_unlock;
}
flags = PIN_MAPPABLE;
if (obj->base.size > 2 * MIN_CHUNK_PAGES << PAGE_SHIFT)
flags |= PIN_NONBLOCK | PIN_NONFAULT;
vma = i915_gem_object_ggtt_pin(obj, NULL, 0, 0, flags);
if (IS_ERR(vma)) {
struct i915_ggtt_view view;
unsigned int chunk_size;
chunk_size = MIN_CHUNK_PAGES;
if (i915_gem_object_is_tiled(obj))
chunk_size = roundup(chunk_size, tile_row_pages(obj));
memset(&view, 0, sizeof(view));
view.type = I915_GGTT_VIEW_PARTIAL;
view.params.partial.offset = rounddown(page_offset, chunk_size);
view.params.partial.size =
min_t(unsigned int, chunk_size,
(area->vm_end - area->vm_start) / PAGE_SIZE -
view.params.partial.offset);
if (chunk_size >= obj->base.size >> PAGE_SHIFT)
view.type = I915_GGTT_VIEW_NORMAL;
obj->frontbuffer_ggtt_origin = ORIGIN_CPU;
vma = i915_gem_object_ggtt_pin(obj, &view, 0, 0, PIN_MAPPABLE);
}
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err_unlock;
}
ret = i915_gem_object_set_to_gtt_domain(obj, write);
if (ret)
goto err_unpin;
ret = i915_vma_get_fence(vma);
if (ret)
goto err_unpin;
ret = remap_io_mapping(area,
area->vm_start + (vma->ggtt_view.params.partial.offset << PAGE_SHIFT),
(ggtt->mappable_base + vma->node.start) >> PAGE_SHIFT,
min_t(u64, vma->size, area->vm_end - area->vm_start),
&ggtt->mappable);
if (ret)
goto err_unpin;
obj->fault_mappable = true;
err_unpin:
__i915_vma_unpin(vma);
err_unlock:
mutex_unlock(&dev->struct_mutex);
err_rpm:
intel_runtime_pm_put(dev_priv);
err:
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
u64 i915_gem_get_ggtt_size(struct drm_i915_private *dev_priv,
u64 size, int tiling_mode)
{
u64 ggtt_size;
GEM_BUG_ON(size == 0);
if (INTEL_GEN(dev_priv) >= 4 ||
tiling_mode == I915_TILING_NONE)
return size;
if (IS_GEN3(dev_priv))
ggtt_size = 1024*1024;
else
ggtt_size = 512*1024;
while (ggtt_size < size)
ggtt_size <<= 1;
return ggtt_size;
}
u64 i915_gem_get_ggtt_alignment(struct drm_i915_private *dev_priv, u64 size,
int tiling_mode, bool fenced)
{
GEM_BUG_ON(size == 0);
if (INTEL_GEN(dev_priv) >= 4 || (!fenced && IS_G33(dev_priv)) ||
tiling_mode == I915_TILING_NONE)
return 4096;
return i915_gem_get_ggtt_size(dev_priv, size, tiling_mode);
}
static int i915_gem_object_create_mmap_offset(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
int err;
err = drm_gem_create_mmap_offset(&obj->base);
if (!err)
return 0;
err = i915_gem_wait_for_idle(dev_priv, I915_WAIT_INTERRUPTIBLE);
if (err)
return err;
err = i915_mutex_lock_interruptible(&dev_priv->drm);
if (!err) {
i915_gem_retire_requests(dev_priv);
err = drm_gem_create_mmap_offset(&obj->base);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
return err;
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
obj = i915_gem_object_lookup(file, handle);
if (!obj)
return -ENOENT;
ret = i915_gem_object_create_mmap_offset(obj);
if (ret == 0)
*offset = drm_vma_node_offset_addr(&obj->base.vma_node);
i915_gem_object_put_unlocked(obj);
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
GEM_BUG_ON(obj->bind_count);
list_del(&obj->global_list);
if (obj->mapping) {
void *ptr;
ptr = ptr_mask_bits(obj->mapping);
if (is_vmalloc_addr(ptr))
vunmap(ptr);
else
kunmap(kmap_to_page(ptr));
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
goto err_sg;
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
if (i915_gem_object_is_tiled(obj) &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES)
i915_gem_object_pin_pages(obj);
return 0;
err_sg:
sg_mark_end(sg);
err_pages:
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
static void *i915_gem_object_map(const struct drm_i915_gem_object *obj,
enum i915_map_type type)
{
unsigned long n_pages = obj->base.size >> PAGE_SHIFT;
struct sg_table *sgt = obj->pages;
struct sgt_iter sgt_iter;
struct page *page;
struct page *stack_pages[32];
struct page **pages = stack_pages;
unsigned long i = 0;
pgprot_t pgprot;
void *addr;
if (n_pages == 1 && type == I915_MAP_WB)
return kmap(sg_page(sgt->sgl));
if (n_pages > ARRAY_SIZE(stack_pages)) {
pages = drm_malloc_gfp(n_pages, sizeof(*pages), GFP_TEMPORARY);
if (!pages)
return NULL;
}
for_each_sgt_page(page, sgt_iter, sgt)
pages[i++] = page;
GEM_BUG_ON(i != n_pages);
switch (type) {
case I915_MAP_WB:
pgprot = PAGE_KERNEL;
break;
case I915_MAP_WC:
pgprot = pgprot_writecombine(PAGE_KERNEL_IO);
break;
}
addr = vmap(pages, n_pages, 0, pgprot);
if (pages != stack_pages)
drm_free_large(pages);
return addr;
}
void *i915_gem_object_pin_map(struct drm_i915_gem_object *obj,
enum i915_map_type type)
{
enum i915_map_type has_type;
bool pinned;
void *ptr;
int ret;
lockdep_assert_held(&obj->base.dev->struct_mutex);
GEM_BUG_ON(!i915_gem_object_has_struct_page(obj));
ret = i915_gem_object_get_pages(obj);
if (ret)
return ERR_PTR(ret);
i915_gem_object_pin_pages(obj);
pinned = obj->pages_pin_count > 1;
ptr = ptr_unpack_bits(obj->mapping, has_type);
if (ptr && has_type != type) {
if (pinned) {
ret = -EBUSY;
goto err;
}
if (is_vmalloc_addr(ptr))
vunmap(ptr);
else
kunmap(kmap_to_page(ptr));
ptr = obj->mapping = NULL;
}
if (!ptr) {
ptr = i915_gem_object_map(obj, type);
if (!ptr) {
ret = -ENOMEM;
goto err;
}
obj->mapping = ptr_pack_bits(ptr, type);
}
return ptr;
err:
i915_gem_object_unpin_pages(obj);
return ERR_PTR(ret);
}
static void
i915_gem_object_retire__write(struct i915_gem_active *active,
struct drm_i915_gem_request *request)
{
struct drm_i915_gem_object *obj =
container_of(active, struct drm_i915_gem_object, last_write);
intel_fb_obj_flush(obj, true, ORIGIN_CS);
}
static void
i915_gem_object_retire__read(struct i915_gem_active *active,
struct drm_i915_gem_request *request)
{
int idx = request->engine->id;
struct drm_i915_gem_object *obj =
container_of(active, struct drm_i915_gem_object, last_read[idx]);
GEM_BUG_ON(!i915_gem_object_has_active_engine(obj, idx));
i915_gem_object_clear_active(obj, idx);
if (i915_gem_object_is_active(obj))
return;
if (obj->bind_count)
list_move_tail(&obj->global_list,
&request->i915->mm.bound_list);
i915_gem_object_put(obj);
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
struct drm_i915_gem_request *
i915_gem_find_active_request(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request;
list_for_each_entry(request, &engine->request_list, link) {
if (i915_gem_request_completed(request))
continue;
if (!i915_sw_fence_done(&request->submit))
break;
return request;
}
return NULL;
}
static void reset_request(struct drm_i915_gem_request *request)
{
void *vaddr = request->ring->vaddr;
u32 head;
head = request->head;
if (request->postfix < head) {
memset(vaddr + head, 0, request->ring->size - head);
head = 0;
}
memset(vaddr + head, 0, request->postfix - head);
}
static void i915_gem_reset_engine(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request;
struct i915_gem_context *incomplete_ctx;
bool ring_hung;
tasklet_kill(&engine->irq_tasklet);
if (engine->irq_seqno_barrier)
engine->irq_seqno_barrier(engine);
request = i915_gem_find_active_request(engine);
if (!request)
return;
ring_hung = engine->hangcheck.score >= HANGCHECK_SCORE_RING_HUNG;
i915_set_reset_status(request->ctx, ring_hung);
if (!ring_hung)
return;
DRM_DEBUG_DRIVER("resetting %s to restart from tail of request 0x%x\n",
engine->name, request->fence.seqno);
engine->reset_hw(engine, request);
incomplete_ctx = request->ctx;
if (i915_gem_context_is_default(incomplete_ctx))
return;
list_for_each_entry_continue(request, &engine->request_list, link)
if (request->ctx == incomplete_ctx)
reset_request(request);
}
void i915_gem_reset(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
i915_gem_retire_requests(dev_priv);
for_each_engine(engine, dev_priv)
i915_gem_reset_engine(engine);
i915_gem_restore_fences(&dev_priv->drm);
if (dev_priv->gt.awake) {
intel_sanitize_gt_powersave(dev_priv);
intel_enable_gt_powersave(dev_priv);
if (INTEL_GEN(dev_priv) >= 6)
gen6_rps_busy(dev_priv);
}
}
static void nop_submit_request(struct drm_i915_gem_request *request)
{
}
static void i915_gem_cleanup_engine(struct intel_engine_cs *engine)
{
engine->submit_request = nop_submit_request;
intel_engine_init_seqno(engine, engine->last_submitted_seqno);
if (i915.enable_execlists) {
spin_lock(&engine->execlist_lock);
INIT_LIST_HEAD(&engine->execlist_queue);
i915_gem_request_put(engine->execlist_port[0].request);
i915_gem_request_put(engine->execlist_port[1].request);
memset(engine->execlist_port, 0, sizeof(engine->execlist_port));
spin_unlock(&engine->execlist_lock);
}
engine->i915->gt.active_engines &= ~intel_engine_flag(engine);
}
void i915_gem_set_wedged(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
set_bit(I915_WEDGED, &dev_priv->gpu_error.flags);
i915_gem_context_lost(dev_priv);
for_each_engine(engine, dev_priv)
i915_gem_cleanup_engine(engine);
mod_delayed_work(dev_priv->wq, &dev_priv->gt.idle_work, 0);
i915_gem_retire_requests(dev_priv);
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
if (READ_ONCE(dev_priv->gt.awake)) {
i915_queue_hangcheck(dev_priv);
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.retire_work,
round_jiffies_up_relative(HZ));
}
}
static void
i915_gem_idle_work_handler(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), gt.idle_work.work);
struct drm_device *dev = &dev_priv->drm;
struct intel_engine_cs *engine;
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
void i915_gem_close_object(struct drm_gem_object *gem, struct drm_file *file)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem);
struct drm_i915_file_private *fpriv = file->driver_priv;
struct i915_vma *vma, *vn;
mutex_lock(&obj->base.dev->struct_mutex);
list_for_each_entry_safe(vma, vn, &obj->vma_list, obj_link)
if (vma->vm->file == fpriv)
i915_vma_close(vma);
mutex_unlock(&obj->base.dev->struct_mutex);
}
int
i915_gem_wait_ioctl(struct drm_device *dev, void *data, struct drm_file *file)
{
struct drm_i915_gem_wait *args = data;
struct intel_rps_client *rps = to_rps_client(file);
struct drm_i915_gem_object *obj;
unsigned long active;
int idx, ret = 0;
if (args->flags != 0)
return -EINVAL;
obj = i915_gem_object_lookup(file, args->bo_handle);
if (!obj)
return -ENOENT;
active = __I915_BO_ACTIVE(obj);
for_each_active(active, idx) {
s64 *timeout = args->timeout_ns >= 0 ? &args->timeout_ns : NULL;
ret = i915_gem_active_wait_unlocked(&obj->last_read[idx],
I915_WAIT_INTERRUPTIBLE,
timeout, rps);
if (ret)
break;
}
i915_gem_object_put_unlocked(obj);
return ret;
}
static void __i915_vma_iounmap(struct i915_vma *vma)
{
GEM_BUG_ON(i915_vma_is_pinned(vma));
if (vma->iomap == NULL)
return;
io_mapping_unmap(vma->iomap);
vma->iomap = NULL;
}
int i915_vma_unbind(struct i915_vma *vma)
{
struct drm_i915_gem_object *obj = vma->obj;
unsigned long active;
int ret;
active = i915_vma_get_active(vma);
if (active) {
int idx;
__i915_vma_pin(vma);
for_each_active(active, idx) {
ret = i915_gem_active_retire(&vma->last_read[idx],
&vma->vm->dev->struct_mutex);
if (ret)
break;
}
__i915_vma_unpin(vma);
if (ret)
return ret;
GEM_BUG_ON(i915_vma_is_active(vma));
}
if (i915_vma_is_pinned(vma))
return -EBUSY;
if (!drm_mm_node_allocated(&vma->node))
goto destroy;
GEM_BUG_ON(obj->bind_count == 0);
GEM_BUG_ON(!obj->pages);
if (i915_vma_is_map_and_fenceable(vma)) {
ret = i915_vma_put_fence(vma);
if (ret)
return ret;
i915_gem_release_mmap(obj);
__i915_vma_iounmap(vma);
vma->flags &= ~I915_VMA_CAN_FENCE;
}
if (likely(!vma->vm->closed)) {
trace_i915_vma_unbind(vma);
vma->vm->unbind_vma(vma);
}
vma->flags &= ~(I915_VMA_GLOBAL_BIND | I915_VMA_LOCAL_BIND);
drm_mm_remove_node(&vma->node);
list_move_tail(&vma->vm_link, &vma->vm->unbound_list);
if (vma->pages != obj->pages) {
GEM_BUG_ON(!vma->pages);
sg_free_table(vma->pages);
kfree(vma->pages);
}
vma->pages = NULL;
if (--obj->bind_count == 0)
list_move_tail(&obj->global_list,
&to_i915(obj->base.dev)->mm.unbound_list);
i915_gem_object_unpin_pages(obj);
destroy:
if (unlikely(i915_vma_is_closed(vma)))
i915_vma_destroy(vma);
return 0;
}
int i915_gem_wait_for_idle(struct drm_i915_private *dev_priv,
unsigned int flags)
{
struct intel_engine_cs *engine;
int ret;
for_each_engine(engine, dev_priv) {
if (engine->last_context == NULL)
continue;
ret = intel_engine_idle(engine, flags);
if (ret)
return ret;
}
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
static int
i915_vma_insert(struct i915_vma *vma, u64 size, u64 alignment, u64 flags)
{
struct drm_i915_private *dev_priv = to_i915(vma->vm->dev);
struct drm_i915_gem_object *obj = vma->obj;
u64 start, end;
int ret;
GEM_BUG_ON(vma->flags & (I915_VMA_GLOBAL_BIND | I915_VMA_LOCAL_BIND));
GEM_BUG_ON(drm_mm_node_allocated(&vma->node));
size = max(size, vma->size);
if (flags & PIN_MAPPABLE)
size = i915_gem_get_ggtt_size(dev_priv, size,
i915_gem_object_get_tiling(obj));
alignment = max(max(alignment, vma->display_alignment),
i915_gem_get_ggtt_alignment(dev_priv, size,
i915_gem_object_get_tiling(obj),
flags & PIN_MAPPABLE));
start = flags & PIN_OFFSET_BIAS ? flags & PIN_OFFSET_MASK : 0;
end = vma->vm->total;
if (flags & PIN_MAPPABLE)
end = min_t(u64, end, dev_priv->ggtt.mappable_end);
if (flags & PIN_ZONE_4G)
end = min_t(u64, end, (1ULL << 32) - PAGE_SIZE);
if (size > end) {
DRM_DEBUG("Attempting to bind an object larger than the aperture: request=%llu [object=%zd] > %s aperture=%llu\n",
size, obj->base.size,
flags & PIN_MAPPABLE ? "mappable" : "total",
end);
return -E2BIG;
}
ret = i915_gem_object_get_pages(obj);
if (ret)
return ret;
i915_gem_object_pin_pages(obj);
if (flags & PIN_OFFSET_FIXED) {
u64 offset = flags & PIN_OFFSET_MASK;
if (offset & (alignment - 1) || offset > end - size) {
ret = -EINVAL;
goto err_unpin;
}
vma->node.start = offset;
vma->node.size = size;
vma->node.color = obj->cache_level;
ret = drm_mm_reserve_node(&vma->vm->mm, &vma->node);
if (ret) {
ret = i915_gem_evict_for_vma(vma);
if (ret == 0)
ret = drm_mm_reserve_node(&vma->vm->mm, &vma->node);
if (ret)
goto err_unpin;
}
} else {
u32 search_flag, alloc_flag;
if (flags & PIN_HIGH) {
search_flag = DRM_MM_SEARCH_BELOW;
alloc_flag = DRM_MM_CREATE_TOP;
} else {
search_flag = DRM_MM_SEARCH_DEFAULT;
alloc_flag = DRM_MM_CREATE_DEFAULT;
}
if (alignment <= 4096)
alignment = 0;
search_free:
ret = drm_mm_insert_node_in_range_generic(&vma->vm->mm,
&vma->node,
size, alignment,
obj->cache_level,
start, end,
search_flag,
alloc_flag);
if (ret) {
ret = i915_gem_evict_something(vma->vm, size, alignment,
obj->cache_level,
start, end,
flags);
if (ret == 0)
goto search_free;
goto err_unpin;
}
}
GEM_BUG_ON(!i915_gem_valid_gtt_space(vma, obj->cache_level));
list_move_tail(&obj->global_list, &dev_priv->mm.bound_list);
list_move_tail(&vma->vm_link, &vma->vm->inactive_list);
obj->bind_count++;
return 0;
err_unpin:
i915_gem_object_unpin_pages(obj);
return ret;
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
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
if (obj->base.write_domain != I915_GEM_DOMAIN_GTT)
return;
wmb();
if (INTEL_GEN(dev_priv) >= 6 && !HAS_LLC(dev_priv))
POSTING_READ(RING_ACTHD(dev_priv->engine[RCS].mmio_base));
intel_fb_obj_flush(obj, false, write_origin(obj, I915_GEM_DOMAIN_GTT));
obj->base.write_domain = 0;
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
I915_GEM_DOMAIN_GTT);
}
static void
i915_gem_object_flush_cpu_write_domain(struct drm_i915_gem_object *obj)
{
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU)
return;
if (i915_gem_clflush_object(obj, obj->pin_display))
i915_gem_chipset_flush(to_i915(obj->base.dev));
intel_fb_obj_flush(obj, false, ORIGIN_CPU);
obj->base.write_domain = 0;
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
I915_GEM_DOMAIN_CPU);
}
static void i915_gem_object_bump_inactive_ggtt(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!i915_vma_is_ggtt(vma))
continue;
if (i915_vma_is_active(vma))
continue;
if (!drm_mm_node_allocated(&vma->node))
continue;
list_move_tail(&vma->vm_link, &vma->vm->inactive_list);
}
}
int
i915_gem_object_set_to_gtt_domain(struct drm_i915_gem_object *obj, bool write)
{
uint32_t old_write_domain, old_read_domains;
int ret;
ret = i915_gem_object_wait_rendering(obj, !write);
if (ret)
return ret;
if (obj->base.write_domain == I915_GEM_DOMAIN_GTT)
return 0;
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
i915_gem_object_bump_inactive_ggtt(obj);
return 0;
}
int i915_gem_object_set_cache_level(struct drm_i915_gem_object *obj,
enum i915_cache_level cache_level)
{
struct i915_vma *vma;
int ret = 0;
if (obj->cache_level == cache_level)
goto out;
restart:
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!drm_mm_node_allocated(&vma->node))
continue;
if (i915_vma_is_pinned(vma)) {
DRM_DEBUG("can not change the cache level of pinned objects\n");
return -EBUSY;
}
if (i915_gem_valid_gtt_space(vma, cache_level))
continue;
ret = i915_vma_unbind(vma);
if (ret)
return ret;
goto restart;
}
if (obj->bind_count) {
ret = i915_gem_object_wait_rendering(obj, false);
if (ret)
return ret;
if (!HAS_LLC(obj->base.dev) && cache_level != I915_CACHE_NONE) {
i915_gem_release_mmap(obj);
list_for_each_entry(vma, &obj->vma_list, obj_link) {
ret = i915_vma_put_fence(vma);
if (ret)
return ret;
}
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
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
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
i915_gem_object_put_unlocked(obj);
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
obj = i915_gem_object_lookup(file, args->handle);
if (!obj) {
ret = -ENOENT;
goto unlock;
}
ret = i915_gem_object_set_cache_level(obj, level);
i915_gem_object_put(obj);
unlock:
mutex_unlock(&dev->struct_mutex);
rpm_put:
intel_runtime_pm_put(dev_priv);
return ret;
}
struct i915_vma *
i915_gem_object_pin_to_display_plane(struct drm_i915_gem_object *obj,
u32 alignment,
const struct i915_ggtt_view *view)
{
struct i915_vma *vma;
u32 old_read_domains, old_write_domain;
int ret;
obj->pin_display++;
ret = i915_gem_object_set_cache_level(obj,
HAS_WT(obj->base.dev) ? I915_CACHE_WT : I915_CACHE_NONE);
if (ret) {
vma = ERR_PTR(ret);
goto err_unpin_display;
}
vma = ERR_PTR(-ENOSPC);
if (view->type == I915_GGTT_VIEW_NORMAL)
vma = i915_gem_object_ggtt_pin(obj, view, 0, alignment,
PIN_MAPPABLE | PIN_NONBLOCK);
if (IS_ERR(vma)) {
struct drm_i915_private *i915 = to_i915(obj->base.dev);
unsigned int flags;
flags = 0;
if (HAS_GMCH_DISPLAY(i915))
flags = PIN_MAPPABLE;
vma = i915_gem_object_ggtt_pin(obj, view, 0, alignment, flags);
}
if (IS_ERR(vma))
goto err_unpin_display;
vma->display_alignment = max_t(u64, vma->display_alignment, alignment);
i915_gem_object_flush_cpu_write_domain(obj);
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
obj->base.write_domain = 0;
obj->base.read_domains |= I915_GEM_DOMAIN_GTT;
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
return vma;
err_unpin_display:
obj->pin_display--;
return vma;
}
void
i915_gem_object_unpin_from_display_plane(struct i915_vma *vma)
{
if (WARN_ON(vma->obj->pin_display == 0))
return;
if (--vma->obj->pin_display == 0)
vma->display_alignment = 0;
if (!i915_vma_is_active(vma))
list_move_tail(&vma->vm_link, &vma->vm->inactive_list);
i915_vma_unpin(vma);
}
int
i915_gem_object_set_to_cpu_domain(struct drm_i915_gem_object *obj, bool write)
{
uint32_t old_write_domain, old_read_domains;
int ret;
ret = i915_gem_object_wait_rendering(obj, !write);
if (ret)
return ret;
if (obj->base.write_domain == I915_GEM_DOMAIN_CPU)
return 0;
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
i915_gem_request_get(target);
spin_unlock(&file_priv->mm.lock);
if (target == NULL)
return 0;
ret = i915_wait_request(target, I915_WAIT_INTERRUPTIBLE, NULL, NULL);
i915_gem_request_put(target);
return ret;
}
static bool
i915_vma_misplaced(struct i915_vma *vma, u64 size, u64 alignment, u64 flags)
{
if (!drm_mm_node_allocated(&vma->node))
return false;
if (vma->node.size < size)
return true;
if (alignment && vma->node.start & (alignment - 1))
return true;
if (flags & PIN_MAPPABLE && !i915_vma_is_map_and_fenceable(vma))
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
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
bool mappable, fenceable;
u32 fence_size, fence_alignment;
fence_size = i915_gem_get_ggtt_size(dev_priv,
vma->size,
i915_gem_object_get_tiling(obj));
fence_alignment = i915_gem_get_ggtt_alignment(dev_priv,
vma->size,
i915_gem_object_get_tiling(obj),
true);
fenceable = (vma->node.size == fence_size &&
(vma->node.start & (fence_alignment - 1)) == 0);
mappable = (vma->node.start + fence_size <=
dev_priv->ggtt.mappable_end);
if (mappable && fenceable &&
vma->ggtt_view.type != I915_GGTT_VIEW_ROTATED)
vma->flags |= I915_VMA_CAN_FENCE;
else
vma->flags &= ~I915_VMA_CAN_FENCE;
}
int __i915_vma_do_pin(struct i915_vma *vma,
u64 size, u64 alignment, u64 flags)
{
unsigned int bound = vma->flags;
int ret;
GEM_BUG_ON((flags & (PIN_GLOBAL | PIN_USER)) == 0);
GEM_BUG_ON((flags & PIN_GLOBAL) && !i915_vma_is_ggtt(vma));
if (WARN_ON(bound & I915_VMA_PIN_OVERFLOW)) {
ret = -EBUSY;
goto err;
}
if ((bound & I915_VMA_BIND_MASK) == 0) {
ret = i915_vma_insert(vma, size, alignment, flags);
if (ret)
goto err;
}
ret = i915_vma_bind(vma, vma->obj->cache_level, flags);
if (ret)
goto err;
if ((bound ^ vma->flags) & I915_VMA_GLOBAL_BIND)
__i915_vma_set_map_and_fenceable(vma);
GEM_BUG_ON(i915_vma_misplaced(vma, size, alignment, flags));
return 0;
err:
__i915_vma_unpin(vma);
return ret;
}
struct i915_vma *
i915_gem_object_ggtt_pin(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view,
u64 size,
u64 alignment,
u64 flags)
{
struct i915_address_space *vm = &to_i915(obj->base.dev)->ggtt.base;
struct i915_vma *vma;
int ret;
vma = i915_gem_obj_lookup_or_create_vma(obj, vm, view);
if (IS_ERR(vma))
return vma;
if (i915_vma_misplaced(vma, size, alignment, flags)) {
if (flags & PIN_NONBLOCK &&
(i915_vma_is_pinned(vma) || i915_vma_is_active(vma)))
return ERR_PTR(-ENOSPC);
WARN(i915_vma_is_pinned(vma),
"bo is already pinned in ggtt with incorrect alignment:"
" offset=%08x, req.alignment=%llx,"
" req.map_and_fenceable=%d, vma->map_and_fenceable=%d\n",
i915_ggtt_offset(vma), alignment,
!!(flags & PIN_MAPPABLE),
i915_vma_is_map_and_fenceable(vma));
ret = i915_vma_unbind(vma);
if (ret)
return ERR_PTR(ret);
}
ret = i915_vma_pin(vma, size, alignment, flags | PIN_GLOBAL);
if (ret)
return ERR_PTR(ret);
return vma;
}
static __always_inline unsigned int __busy_read_flag(unsigned int id)
{
BUILD_BUG_ON(I915_NUM_ENGINES > 16);
return 0x10000 << id;
}
static __always_inline unsigned int __busy_write_id(unsigned int id)
{
return id | __busy_read_flag(id);
}
static __always_inline unsigned int
busy_check_reader(const struct i915_gem_active *active)
{
return __busy_set_if_active(active, __busy_read_flag);
}
static __always_inline unsigned int
busy_check_writer(const struct i915_gem_active *active)
{
return __busy_set_if_active(active, __busy_write_id);
}
int
i915_gem_busy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_busy *args = data;
struct drm_i915_gem_object *obj;
unsigned long active;
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
args->busy = 0;
active = __I915_BO_ACTIVE(obj);
if (active) {
int idx;
rcu_read_lock();
for_each_active(active, idx)
args->busy |= busy_check_reader(&obj->last_read[idx]);
args->busy |= busy_check_writer(&obj->last_write);
rcu_read_unlock();
}
i915_gem_object_put_unlocked(obj);
return 0;
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
obj = i915_gem_object_lookup(file_priv, args->handle);
if (!obj) {
ret = -ENOENT;
goto unlock;
}
if (obj->pages &&
i915_gem_object_is_tiled(obj) &&
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
i915_gem_object_put(obj);
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
init_request_active(&obj->last_read[i],
i915_gem_object_retire__read);
init_request_active(&obj->last_write,
i915_gem_object_retire__write);
INIT_LIST_HEAD(&obj->obj_exec_link);
INIT_LIST_HEAD(&obj->vma_list);
INIT_LIST_HEAD(&obj->batch_pool_link);
obj->ops = ops;
obj->frontbuffer_ggtt_origin = ORIGIN_GTT;
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
GEM_BUG_ON(!i915_vma_is_ggtt(vma));
GEM_BUG_ON(i915_vma_is_active(vma));
vma->flags &= ~I915_VMA_PIN_MASK;
i915_vma_close(vma);
}
GEM_BUG_ON(obj->bind_count);
if (obj->stolen)
i915_gem_object_unpin_pages(obj);
WARN_ON(atomic_read(&obj->frontbuffer_bits));
if (obj->pages && obj->madv == I915_MADV_WILLNEED &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES &&
i915_gem_object_is_tiled(obj))
i915_gem_object_unpin_pages(obj);
if (WARN_ON(obj->pages_pin_count))
obj->pages_pin_count = 0;
if (discard_backing_storage(obj))
obj->madv = I915_MADV_DONTNEED;
i915_gem_object_put_pages(obj);
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
int i915_gem_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
intel_suspend_gt_powersave(dev_priv);
mutex_lock(&dev->struct_mutex);
ret = i915_gem_switch_to_kernel_context(dev_priv);
if (ret)
goto err;
ret = i915_gem_wait_for_idle(dev_priv,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
goto err;
i915_gem_retire_requests(dev_priv);
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
void i915_gem_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
dev_priv->gt.resume(dev_priv);
mutex_unlock(&dev->struct_mutex);
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
bool intel_sanitize_semaphores(struct drm_i915_private *dev_priv, int value)
{
if (INTEL_INFO(dev_priv)->gen < 6)
return false;
if (i915.enable_execlists)
return false;
if (value >= 0)
return value;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev_priv)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return true;
}
int i915_gem_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
mutex_lock(&dev->struct_mutex);
if (!i915.enable_execlists) {
dev_priv->gt.resume = intel_legacy_submission_resume;
dev_priv->gt.cleanup_engine = intel_engine_cleanup;
} else {
dev_priv->gt.resume = intel_lr_context_resume;
dev_priv->gt.cleanup_engine = intel_logical_ring_cleanup;
}
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
i915_gem_init_userptr(dev_priv);
ret = i915_gem_init_ggtt(dev_priv);
if (ret)
goto out_unlock;
ret = i915_gem_context_init(dev);
if (ret)
goto out_unlock;
ret = intel_engines_init(dev);
if (ret)
goto out_unlock;
ret = i915_gem_init_hw(dev);
if (ret == -EIO) {
DRM_ERROR("Failed to initialize GPU, declaring it wedged\n");
i915_gem_set_wedged(dev_priv);
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
INIT_LIST_HEAD(&engine->request_list);
}
void
i915_gem_load_init_fences(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
int i;
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
for (i = 0; i < dev_priv->num_fence_regs; i++) {
struct drm_i915_fence_reg *fence = &dev_priv->fence_regs[i];
fence->i915 = dev_priv;
fence->id = i;
list_add_tail(&fence->link, &dev_priv->mm.fence_list);
}
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
SLAB_HWCACHE_ALIGN |
SLAB_RECLAIM_ACCOUNT |
SLAB_DESTROY_BY_RCU,
NULL);
INIT_LIST_HEAD(&dev_priv->context_list);
INIT_LIST_HEAD(&dev_priv->mm.unbound_list);
INIT_LIST_HEAD(&dev_priv->mm.bound_list);
INIT_LIST_HEAD(&dev_priv->mm.fence_list);
for (i = 0; i < I915_NUM_ENGINES; i++)
init_engine_lists(&dev_priv->engine[i]);
INIT_DELAYED_WORK(&dev_priv->gt.retire_work,
i915_gem_retire_work_handler);
INIT_DELAYED_WORK(&dev_priv->gt.idle_work,
i915_gem_idle_work_handler);
init_waitqueue_head(&dev_priv->gpu_error.wait_queue);
init_waitqueue_head(&dev_priv->gpu_error.reset_queue);
dev_priv->relative_constants_mode = I915_EXEC_CONSTANTS_REL_GENERAL;
init_waitqueue_head(&dev_priv->pending_flip_queue);
dev_priv->mm.interruptible = true;
atomic_set(&dev_priv->mm.bsd_engine_dispatch_index, 0);
spin_lock_init(&dev_priv->fb_tracking.lock);
}
void i915_gem_load_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
kmem_cache_destroy(dev_priv->requests);
kmem_cache_destroy(dev_priv->vmas);
kmem_cache_destroy(dev_priv->objects);
rcu_barrier();
}
int i915_gem_freeze(struct drm_i915_private *dev_priv)
{
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->drm.struct_mutex);
i915_gem_shrink_all(dev_priv);
mutex_unlock(&dev_priv->drm.struct_mutex);
intel_runtime_pm_put(dev_priv);
return 0;
}
int i915_gem_freeze_late(struct drm_i915_private *dev_priv)
{
struct drm_i915_gem_object *obj;
struct list_head *phases[] = {
&dev_priv->mm.unbound_list,
&dev_priv->mm.bound_list,
NULL
}, **p;
mutex_lock(&dev_priv->drm.struct_mutex);
i915_gem_shrink(dev_priv, -1UL, I915_SHRINK_UNBOUND);
for (p = phases; *p; p++) {
list_for_each_entry(obj, *p, global_list) {
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
}
mutex_unlock(&dev_priv->drm.struct_mutex);
return 0;
}
void i915_gem_release(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_request *request;
spin_lock(&file_priv->mm.lock);
list_for_each_entry(request, &file_priv->mm.request_list, client_list)
request->file_priv = NULL;
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
file_priv->bsd_engine = -1;
ret = i915_gem_context_open(dev, file);
if (ret)
kfree(file_priv);
return ret;
}
void i915_gem_track_fb(struct drm_i915_gem_object *old,
struct drm_i915_gem_object *new,
unsigned frontbuffer_bits)
{
BUILD_BUG_ON(INTEL_FRONTBUFFER_BITS_PER_PIPE * I915_MAX_PIPES >
sizeof(atomic_t) * BITS_PER_BYTE);
if (old) {
WARN_ON(!(atomic_read(&old->frontbuffer_bits) & frontbuffer_bits));
atomic_andnot(frontbuffer_bits, &old->frontbuffer_bits);
}
if (new) {
WARN_ON(atomic_read(&new->frontbuffer_bits) & frontbuffer_bits);
atomic_or(frontbuffer_bits, &new->frontbuffer_bits);
}
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
i915_gem_object_put(obj);
return ERR_PTR(ret);
}
