static inline void i915_gem_object_fence_lost(struct drm_i915_gem_object *obj)
{
if (obj->tiling_mode)
i915_gem_release_mmap(obj);
obj->fence_dirty = false;
obj->fence_reg = I915_FENCE_REG_NONE;
}
static void i915_gem_info_add_obj(struct drm_i915_private *dev_priv,
size_t size)
{
dev_priv->mm.object_count++;
dev_priv->mm.object_memory += size;
}
static void i915_gem_info_remove_obj(struct drm_i915_private *dev_priv,
size_t size)
{
dev_priv->mm.object_count--;
dev_priv->mm.object_memory -= size;
}
static int
i915_gem_wait_for_error(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct completion *x = &dev_priv->error_completion;
unsigned long flags;
int ret;
if (!atomic_read(&dev_priv->mm.wedged))
return 0;
ret = wait_for_completion_interruptible(x);
if (ret)
return ret;
if (atomic_read(&dev_priv->mm.wedged)) {
spin_lock_irqsave(&x->wait.lock, flags);
x->done++;
spin_unlock_irqrestore(&x->wait.lock, flags);
}
return 0;
}
int i915_mutex_lock_interruptible(struct drm_device *dev)
{
int ret;
ret = i915_gem_wait_for_error(dev);
if (ret)
return ret;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
WARN_ON(i915_verify_lists(dev));
return 0;
}
static inline bool
i915_gem_object_is_inactive(struct drm_i915_gem_object *obj)
{
return !obj->active;
}
int
i915_gem_init_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_init *args = data;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if (args->gtt_start >= args->gtt_end ||
(args->gtt_end | args->gtt_start) & (PAGE_SIZE - 1))
return -EINVAL;
if (INTEL_INFO(dev)->gen >= 5)
return -ENODEV;
mutex_lock(&dev->struct_mutex);
i915_gem_init_global_gtt(dev, args->gtt_start,
args->gtt_end, args->gtt_end);
mutex_unlock(&dev->struct_mutex);
return 0;
}
int
i915_gem_get_aperture_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_get_aperture *args = data;
struct drm_i915_gem_object *obj;
size_t pinned;
pinned = 0;
mutex_lock(&dev->struct_mutex);
list_for_each_entry(obj, &dev_priv->mm.gtt_list, gtt_list)
if (obj->pin_count)
pinned += obj->gtt_space->size;
mutex_unlock(&dev->struct_mutex);
args->aper_size = dev_priv->mm.gtt_total;
args->aper_available_size = args->aper_size - pinned;
return 0;
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
obj = i915_gem_alloc_object(dev, size);
if (obj == NULL)
return -ENOMEM;
ret = drm_gem_handle_create(file, &obj->base, &handle);
if (ret) {
drm_gem_object_release(&obj->base);
i915_gem_info_remove_obj(dev->dev_private, obj->base.size);
kfree(obj);
return ret;
}
drm_gem_object_unreference(&obj->base);
trace_i915_gem_object_create(obj);
*handle_p = handle;
return 0;
}
int
i915_gem_dumb_create(struct drm_file *file,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
args->pitch = ALIGN(args->width * ((args->bpp + 7) / 8), 64);
args->size = args->pitch * args->height;
return i915_gem_create(file, dev,
args->size, &args->handle);
}
int i915_gem_dumb_destroy(struct drm_file *file,
struct drm_device *dev,
uint32_t handle)
{
return drm_gem_handle_delete(file, handle);
}
int
i915_gem_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_create *args = data;
return i915_gem_create(file, dev,
args->size, &args->handle);
}
static int i915_gem_object_needs_bit17_swizzle(struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = obj->base.dev->dev_private;
return dev_priv->mm.bit_6_swizzle_x == I915_BIT_6_SWIZZLE_9_10_17 &&
obj->tiling_mode != I915_TILING_NONE;
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
return ret;
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
return ret;
}
static int
i915_gem_shmem_pread(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pread *args,
struct drm_file *file)
{
struct address_space *mapping = obj->base.filp->f_path.dentry->d_inode->i_mapping;
char __user *user_data;
ssize_t remain;
loff_t offset;
int shmem_page_offset, page_length, ret = 0;
int obj_do_bit17_swizzling, page_do_bit17_swizzling;
int hit_slowpath = 0;
int prefaulted = 0;
int needs_clflush = 0;
int release_page;
user_data = (char __user *) (uintptr_t) args->data_ptr;
remain = args->size;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
if (!(obj->base.read_domains & I915_GEM_DOMAIN_CPU)) {
if (obj->cache_level == I915_CACHE_NONE)
needs_clflush = 1;
ret = i915_gem_object_set_to_gtt_domain(obj, false);
if (ret)
return ret;
}
offset = args->offset;
while (remain > 0) {
struct page *page;
shmem_page_offset = offset_in_page(offset);
page_length = remain;
if ((shmem_page_offset + page_length) > PAGE_SIZE)
page_length = PAGE_SIZE - shmem_page_offset;
if (obj->pages) {
page = obj->pages[offset >> PAGE_SHIFT];
release_page = 0;
} else {
page = shmem_read_mapping_page(mapping, offset >> PAGE_SHIFT);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
goto out;
}
release_page = 1;
}
page_do_bit17_swizzling = obj_do_bit17_swizzling &&
(page_to_phys(page) & (1 << 17)) != 0;
ret = shmem_pread_fast(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
needs_clflush);
if (ret == 0)
goto next_page;
hit_slowpath = 1;
page_cache_get(page);
mutex_unlock(&dev->struct_mutex);
if (!prefaulted) {
ret = fault_in_multipages_writeable(user_data, remain);
(void)ret;
prefaulted = 1;
}
ret = shmem_pread_slow(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
needs_clflush);
mutex_lock(&dev->struct_mutex);
page_cache_release(page);
next_page:
mark_page_accessed(page);
if (release_page)
page_cache_release(page);
if (ret) {
ret = -EFAULT;
goto out;
}
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out:
if (hit_slowpath) {
if (obj->madv == __I915_MADV_PURGED)
i915_gem_object_truncate(obj);
}
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
(char __user *)(uintptr_t)args->data_ptr,
args->size))
return -EFAULT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto out;
}
if (!obj->base.filp) {
ret = -EINVAL;
goto out;
}
trace_i915_gem_object_pread(obj, args->offset, args->size);
ret = i915_gem_shmem_pread(dev, obj, args, file);
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
i915_gem_gtt_pwrite_fast(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file)
{
drm_i915_private_t *dev_priv = dev->dev_private;
ssize_t remain;
loff_t offset, page_base;
char __user *user_data;
int page_offset, page_length, ret;
ret = i915_gem_object_pin(obj, 0, true);
if (ret)
goto out;
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
goto out_unpin;
ret = i915_gem_object_put_fence(obj);
if (ret)
goto out_unpin;
user_data = (char __user *) (uintptr_t) args->data_ptr;
remain = args->size;
offset = obj->gtt_offset + args->offset;
while (remain > 0) {
page_base = offset & PAGE_MASK;
page_offset = offset_in_page(offset);
page_length = remain;
if ((page_offset + remain) > PAGE_SIZE)
page_length = PAGE_SIZE - page_offset;
if (fast_user_write(dev_priv->mm.gtt_mapping, page_base,
page_offset, user_data, page_length)) {
ret = -EFAULT;
goto out_unpin;
}
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out_unpin:
i915_gem_object_unpin(obj);
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
ret = __copy_from_user_inatomic_nocache(vaddr + shmem_page_offset,
user_data,
page_length);
if (needs_clflush_after)
drm_clflush_virt_range(vaddr + shmem_page_offset,
page_length);
kunmap_atomic(vaddr);
return ret;
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
return ret;
}
static int
i915_gem_shmem_pwrite(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file)
{
struct address_space *mapping = obj->base.filp->f_path.dentry->d_inode->i_mapping;
ssize_t remain;
loff_t offset;
char __user *user_data;
int shmem_page_offset, page_length, ret = 0;
int obj_do_bit17_swizzling, page_do_bit17_swizzling;
int hit_slowpath = 0;
int needs_clflush_after = 0;
int needs_clflush_before = 0;
int release_page;
user_data = (char __user *) (uintptr_t) args->data_ptr;
remain = args->size;
obj_do_bit17_swizzling = i915_gem_object_needs_bit17_swizzle(obj);
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
if (obj->cache_level == I915_CACHE_NONE)
needs_clflush_after = 1;
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
return ret;
}
if (!(obj->base.read_domains & I915_GEM_DOMAIN_CPU)
&& obj->cache_level == I915_CACHE_NONE)
needs_clflush_before = 1;
offset = args->offset;
obj->dirty = 1;
while (remain > 0) {
struct page *page;
int partial_cacheline_write;
shmem_page_offset = offset_in_page(offset);
page_length = remain;
if ((shmem_page_offset + page_length) > PAGE_SIZE)
page_length = PAGE_SIZE - shmem_page_offset;
partial_cacheline_write = needs_clflush_before &&
((shmem_page_offset | page_length)
& (boot_cpu_data.x86_clflush_size - 1));
if (obj->pages) {
page = obj->pages[offset >> PAGE_SHIFT];
release_page = 0;
} else {
page = shmem_read_mapping_page(mapping, offset >> PAGE_SHIFT);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
goto out;
}
release_page = 1;
}
page_do_bit17_swizzling = obj_do_bit17_swizzling &&
(page_to_phys(page) & (1 << 17)) != 0;
ret = shmem_pwrite_fast(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush_after);
if (ret == 0)
goto next_page;
hit_slowpath = 1;
page_cache_get(page);
mutex_unlock(&dev->struct_mutex);
ret = shmem_pwrite_slow(page, shmem_page_offset, page_length,
user_data, page_do_bit17_swizzling,
partial_cacheline_write,
needs_clflush_after);
mutex_lock(&dev->struct_mutex);
page_cache_release(page);
next_page:
set_page_dirty(page);
mark_page_accessed(page);
if (release_page)
page_cache_release(page);
if (ret) {
ret = -EFAULT;
goto out;
}
remain -= page_length;
user_data += page_length;
offset += page_length;
}
out:
if (hit_slowpath) {
if (obj->madv == __I915_MADV_PURGED)
i915_gem_object_truncate(obj);
if (obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
i915_gem_clflush_object(obj);
intel_gtt_chipset_flush();
}
}
if (needs_clflush_after)
intel_gtt_chipset_flush();
return ret;
}
int
i915_gem_pwrite_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_pwrite *args = data;
struct drm_i915_gem_object *obj;
int ret;
if (args->size == 0)
return 0;
if (!access_ok(VERIFY_READ,
(char __user *)(uintptr_t)args->data_ptr,
args->size))
return -EFAULT;
ret = fault_in_multipages_readable((char __user *)(uintptr_t)args->data_ptr,
args->size);
if (ret)
return -EFAULT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (args->offset > obj->base.size ||
args->size > obj->base.size - args->offset) {
ret = -EINVAL;
goto out;
}
if (!obj->base.filp) {
ret = -EINVAL;
goto out;
}
trace_i915_gem_object_pwrite(obj, args->offset, args->size);
ret = -EFAULT;
if (obj->phys_obj) {
ret = i915_gem_phys_pwrite(dev, obj, args, file);
goto out;
}
if (obj->gtt_space &&
obj->cache_level == I915_CACHE_NONE &&
obj->tiling_mode == I915_TILING_NONE &&
obj->map_and_fenceable &&
obj->base.write_domain != I915_GEM_DOMAIN_CPU) {
ret = i915_gem_gtt_pwrite_fast(dev, obj, args, file);
}
if (ret == -EFAULT)
ret = i915_gem_shmem_pwrite(dev, obj, args, file);
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
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
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (read_domains & I915_GEM_DOMAIN_GTT) {
ret = i915_gem_object_set_to_gtt_domain(obj, write_domain != 0);
if (ret == -EINVAL)
ret = 0;
} else {
ret = i915_gem_object_set_to_cpu_domain(obj, write_domain != 0);
}
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
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->pin_count)
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
obj = drm_gem_object_lookup(dev, file, args->handle);
if (obj == NULL)
return -ENOENT;
if (!obj->filp) {
drm_gem_object_unreference_unlocked(obj);
return -EINVAL;
}
addr = vm_mmap(obj->filp, 0, args->size,
PROT_READ | PROT_WRITE, MAP_SHARED,
args->offset);
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
drm_i915_private_t *dev_priv = dev->dev_private;
pgoff_t page_offset;
unsigned long pfn;
int ret = 0;
bool write = !!(vmf->flags & FAULT_FLAG_WRITE);
page_offset = ((unsigned long)vmf->virtual_address - vma->vm_start) >>
PAGE_SHIFT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto out;
trace_i915_gem_object_fault(obj, page_offset, true, write);
if (!obj->map_and_fenceable) {
ret = i915_gem_object_unbind(obj);
if (ret)
goto unlock;
}
if (!obj->gtt_space) {
ret = i915_gem_object_bind_to_gtt(obj, 0, true);
if (ret)
goto unlock;
ret = i915_gem_object_set_to_gtt_domain(obj, write);
if (ret)
goto unlock;
}
if (!obj->has_global_gtt_mapping)
i915_gem_gtt_bind_object(obj, obj->cache_level);
ret = i915_gem_object_get_fence(obj);
if (ret)
goto unlock;
if (i915_gem_object_is_inactive(obj))
list_move_tail(&obj->mm_list, &dev_priv->mm.inactive_list);
obj->fault_mappable = true;
pfn = ((dev->agp->base + obj->gtt_offset) >> PAGE_SHIFT) +
page_offset;
ret = vm_insert_pfn(vma, (unsigned long)vmf->virtual_address, pfn);
unlock:
mutex_unlock(&dev->struct_mutex);
out:
switch (ret) {
case -EIO:
case -EAGAIN:
set_need_resched();
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
void
i915_gem_release_mmap(struct drm_i915_gem_object *obj)
{
if (!obj->fault_mappable)
return;
if (obj->base.dev->dev_mapping)
unmap_mapping_range(obj->base.dev->dev_mapping,
(loff_t)obj->base.map_list.hash.key<<PAGE_SHIFT,
obj->base.size, 1);
obj->fault_mappable = false;
}
static uint32_t
i915_gem_get_gtt_size(struct drm_device *dev, uint32_t size, int tiling_mode)
{
uint32_t gtt_size;
if (INTEL_INFO(dev)->gen >= 4 ||
tiling_mode == I915_TILING_NONE)
return size;
if (INTEL_INFO(dev)->gen == 3)
gtt_size = 1024*1024;
else
gtt_size = 512*1024;
while (gtt_size < size)
gtt_size <<= 1;
return gtt_size;
}
static uint32_t
i915_gem_get_gtt_alignment(struct drm_device *dev,
uint32_t size,
int tiling_mode)
{
if (INTEL_INFO(dev)->gen >= 4 ||
tiling_mode == I915_TILING_NONE)
return 4096;
return i915_gem_get_gtt_size(dev, size, tiling_mode);
}
uint32_t
i915_gem_get_unfenced_gtt_alignment(struct drm_device *dev,
uint32_t size,
int tiling_mode)
{
if (INTEL_INFO(dev)->gen >= 4 || IS_G33(dev) ||
tiling_mode == I915_TILING_NONE)
return 4096;
return i915_gem_get_gtt_size(dev, size, tiling_mode);
}
int
i915_gem_mmap_gtt(struct drm_file *file,
struct drm_device *dev,
uint32_t handle,
uint64_t *offset)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(dev, file, handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->base.size > dev_priv->mm.gtt_mappable_end) {
ret = -E2BIG;
goto out;
}
if (obj->madv != I915_MADV_WILLNEED) {
DRM_ERROR("Attempting to mmap a purgeable buffer\n");
ret = -EINVAL;
goto out;
}
if (!obj->base.map_list.map) {
ret = drm_gem_create_mmap_offset(&obj->base);
if (ret)
goto out;
}
*offset = (u64)obj->base.map_list.hash.key << PAGE_SHIFT;
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
int
i915_gem_object_get_pages_gtt(struct drm_i915_gem_object *obj,
gfp_t gfpmask)
{
int page_count, i;
struct address_space *mapping;
struct inode *inode;
struct page *page;
if (obj->pages || obj->sg_table)
return 0;
page_count = obj->base.size / PAGE_SIZE;
BUG_ON(obj->pages != NULL);
obj->pages = drm_malloc_ab(page_count, sizeof(struct page *));
if (obj->pages == NULL)
return -ENOMEM;
inode = obj->base.filp->f_path.dentry->d_inode;
mapping = inode->i_mapping;
gfpmask |= mapping_gfp_mask(mapping);
for (i = 0; i < page_count; i++) {
page = shmem_read_mapping_page_gfp(mapping, i, gfpmask);
if (IS_ERR(page))
goto err_pages;
obj->pages[i] = page;
}
if (i915_gem_object_needs_bit17_swizzle(obj))
i915_gem_object_do_bit_17_swizzle(obj);
return 0;
err_pages:
while (i--)
page_cache_release(obj->pages[i]);
drm_free_large(obj->pages);
obj->pages = NULL;
return PTR_ERR(page);
}
static void
i915_gem_object_put_pages_gtt(struct drm_i915_gem_object *obj)
{
int page_count = obj->base.size / PAGE_SIZE;
int i;
if (!obj->pages)
return;
BUG_ON(obj->madv == __I915_MADV_PURGED);
if (i915_gem_object_needs_bit17_swizzle(obj))
i915_gem_object_save_bit_17_swizzle(obj);
if (obj->madv == I915_MADV_DONTNEED)
obj->dirty = 0;
for (i = 0; i < page_count; i++) {
if (obj->dirty)
set_page_dirty(obj->pages[i]);
if (obj->madv == I915_MADV_WILLNEED)
mark_page_accessed(obj->pages[i]);
page_cache_release(obj->pages[i]);
}
obj->dirty = 0;
drm_free_large(obj->pages);
obj->pages = NULL;
}
void
i915_gem_object_move_to_active(struct drm_i915_gem_object *obj,
struct intel_ring_buffer *ring,
u32 seqno)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
BUG_ON(ring == NULL);
obj->ring = ring;
if (!obj->active) {
drm_gem_object_reference(&obj->base);
obj->active = 1;
}
list_move_tail(&obj->mm_list, &dev_priv->mm.active_list);
list_move_tail(&obj->ring_list, &ring->active_list);
obj->last_rendering_seqno = seqno;
if (obj->fenced_gpu_access) {
obj->last_fenced_seqno = seqno;
if (obj->fence_reg != I915_FENCE_REG_NONE) {
struct drm_i915_fence_reg *reg;
reg = &dev_priv->fence_regs[obj->fence_reg];
list_move_tail(&reg->lru_list,
&dev_priv->mm.fence_list);
}
}
}
static void
i915_gem_object_move_off_active(struct drm_i915_gem_object *obj)
{
list_del_init(&obj->ring_list);
obj->last_rendering_seqno = 0;
obj->last_fenced_seqno = 0;
}
static void
i915_gem_object_move_to_flushing(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
drm_i915_private_t *dev_priv = dev->dev_private;
BUG_ON(!obj->active);
list_move_tail(&obj->mm_list, &dev_priv->mm.flushing_list);
i915_gem_object_move_off_active(obj);
}
static void
i915_gem_object_move_to_inactive(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
list_move_tail(&obj->mm_list, &dev_priv->mm.inactive_list);
BUG_ON(!list_empty(&obj->gpu_write_list));
BUG_ON(!obj->active);
obj->ring = NULL;
i915_gem_object_move_off_active(obj);
obj->fenced_gpu_access = false;
obj->active = 0;
obj->pending_gpu_write = false;
drm_gem_object_unreference(&obj->base);
WARN_ON(i915_verify_lists(dev));
}
static void
i915_gem_object_truncate(struct drm_i915_gem_object *obj)
{
struct inode *inode;
inode = obj->base.filp->f_path.dentry->d_inode;
shmem_truncate_range(inode, 0, (loff_t)-1);
if (obj->base.map_list.map)
drm_gem_free_mmap_offset(&obj->base);
obj->madv = __I915_MADV_PURGED;
}
static inline int
i915_gem_object_is_purgeable(struct drm_i915_gem_object *obj)
{
return obj->madv == I915_MADV_DONTNEED;
}
static void
i915_gem_process_flushing_list(struct intel_ring_buffer *ring,
uint32_t flush_domains)
{
struct drm_i915_gem_object *obj, *next;
list_for_each_entry_safe(obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if (obj->base.write_domain & flush_domains) {
uint32_t old_write_domain = obj->base.write_domain;
obj->base.write_domain = 0;
list_del_init(&obj->gpu_write_list);
i915_gem_object_move_to_active(obj, ring,
i915_gem_next_request_seqno(ring));
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
old_write_domain);
}
}
}
static u32
i915_gem_get_seqno(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 seqno = dev_priv->next_seqno;
if (++dev_priv->next_seqno == 0)
dev_priv->next_seqno = 1;
return seqno;
}
u32
i915_gem_next_request_seqno(struct intel_ring_buffer *ring)
{
if (ring->outstanding_lazy_request == 0)
ring->outstanding_lazy_request = i915_gem_get_seqno(ring->dev);
return ring->outstanding_lazy_request;
}
int
i915_add_request(struct intel_ring_buffer *ring,
struct drm_file *file,
struct drm_i915_gem_request *request)
{
drm_i915_private_t *dev_priv = ring->dev->dev_private;
uint32_t seqno;
u32 request_ring_position;
int was_empty;
int ret;
BUG_ON(request == NULL);
seqno = i915_gem_next_request_seqno(ring);
request_ring_position = intel_ring_get_tail(ring);
ret = ring->add_request(ring, &seqno);
if (ret)
return ret;
trace_i915_gem_request_add(ring, seqno);
request->seqno = seqno;
request->ring = ring;
request->tail = request_ring_position;
request->emitted_jiffies = jiffies;
was_empty = list_empty(&ring->request_list);
list_add_tail(&request->list, &ring->request_list);
if (file) {
struct drm_i915_file_private *file_priv = file->driver_priv;
spin_lock(&file_priv->mm.lock);
request->file_priv = file_priv;
list_add_tail(&request->client_list,
&file_priv->mm.request_list);
spin_unlock(&file_priv->mm.lock);
}
ring->outstanding_lazy_request = 0;
if (!dev_priv->mm.suspended) {
if (i915_enable_hangcheck) {
mod_timer(&dev_priv->hangcheck_timer,
jiffies +
msecs_to_jiffies(DRM_I915_HANGCHECK_PERIOD));
}
if (was_empty)
queue_delayed_work(dev_priv->wq,
&dev_priv->mm.retire_work, HZ);
}
return 0;
}
static inline void
i915_gem_request_remove_from_client(struct drm_i915_gem_request *request)
{
struct drm_i915_file_private *file_priv = request->file_priv;
if (!file_priv)
return;
spin_lock(&file_priv->mm.lock);
if (request->file_priv) {
list_del(&request->client_list);
request->file_priv = NULL;
}
spin_unlock(&file_priv->mm.lock);
}
static void i915_gem_reset_ring_lists(struct drm_i915_private *dev_priv,
struct intel_ring_buffer *ring)
{
while (!list_empty(&ring->request_list)) {
struct drm_i915_gem_request *request;
request = list_first_entry(&ring->request_list,
struct drm_i915_gem_request,
list);
list_del(&request->list);
i915_gem_request_remove_from_client(request);
kfree(request);
}
while (!list_empty(&ring->active_list)) {
struct drm_i915_gem_object *obj;
obj = list_first_entry(&ring->active_list,
struct drm_i915_gem_object,
ring_list);
obj->base.write_domain = 0;
list_del_init(&obj->gpu_write_list);
i915_gem_object_move_to_inactive(obj);
}
}
static void i915_gem_reset_fences(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
for (i = 0; i < dev_priv->num_fence_regs; i++) {
struct drm_i915_fence_reg *reg = &dev_priv->fence_regs[i];
i915_gem_write_fence(dev, i, NULL);
if (reg->obj)
i915_gem_object_fence_lost(reg->obj);
reg->pin_count = 0;
reg->obj = NULL;
INIT_LIST_HEAD(&reg->lru_list);
}
INIT_LIST_HEAD(&dev_priv->mm.fence_list);
}
void i915_gem_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct intel_ring_buffer *ring;
int i;
for_each_ring(ring, dev_priv, i)
i915_gem_reset_ring_lists(dev_priv, ring);
while (!list_empty(&dev_priv->mm.flushing_list)) {
obj = list_first_entry(&dev_priv->mm.flushing_list,
struct drm_i915_gem_object,
mm_list);
obj->base.write_domain = 0;
list_del_init(&obj->gpu_write_list);
i915_gem_object_move_to_inactive(obj);
}
list_for_each_entry(obj,
&dev_priv->mm.inactive_list,
mm_list)
{
obj->base.read_domains &= ~I915_GEM_GPU_DOMAINS;
}
i915_gem_reset_fences(dev);
}
void
i915_gem_retire_requests_ring(struct intel_ring_buffer *ring)
{
uint32_t seqno;
int i;
if (list_empty(&ring->request_list))
return;
WARN_ON(i915_verify_lists(ring->dev));
seqno = ring->get_seqno(ring);
for (i = 0; i < ARRAY_SIZE(ring->sync_seqno); i++)
if (seqno >= ring->sync_seqno[i])
ring->sync_seqno[i] = 0;
while (!list_empty(&ring->request_list)) {
struct drm_i915_gem_request *request;
request = list_first_entry(&ring->request_list,
struct drm_i915_gem_request,
list);
if (!i915_seqno_passed(seqno, request->seqno))
break;
trace_i915_gem_request_retire(ring, request->seqno);
ring->last_retired_head = request->tail;
list_del(&request->list);
i915_gem_request_remove_from_client(request);
kfree(request);
}
while (!list_empty(&ring->active_list)) {
struct drm_i915_gem_object *obj;
obj = list_first_entry(&ring->active_list,
struct drm_i915_gem_object,
ring_list);
if (!i915_seqno_passed(seqno, obj->last_rendering_seqno))
break;
if (obj->base.write_domain != 0)
i915_gem_object_move_to_flushing(obj);
else
i915_gem_object_move_to_inactive(obj);
}
if (unlikely(ring->trace_irq_seqno &&
i915_seqno_passed(seqno, ring->trace_irq_seqno))) {
ring->irq_put(ring);
ring->trace_irq_seqno = 0;
}
WARN_ON(i915_verify_lists(ring->dev));
}
void
i915_gem_retire_requests(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring;
int i;
for_each_ring(ring, dev_priv, i)
i915_gem_retire_requests_ring(ring);
}
static void
i915_gem_retire_work_handler(struct work_struct *work)
{
drm_i915_private_t *dev_priv;
struct drm_device *dev;
struct intel_ring_buffer *ring;
bool idle;
int i;
dev_priv = container_of(work, drm_i915_private_t,
mm.retire_work.work);
dev = dev_priv->dev;
if (!mutex_trylock(&dev->struct_mutex)) {
queue_delayed_work(dev_priv->wq, &dev_priv->mm.retire_work, HZ);
return;
}
i915_gem_retire_requests(dev);
idle = true;
for_each_ring(ring, dev_priv, i) {
if (!list_empty(&ring->gpu_write_list)) {
struct drm_i915_gem_request *request;
int ret;
ret = i915_gem_flush_ring(ring,
0, I915_GEM_GPU_DOMAINS);
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (ret || request == NULL ||
i915_add_request(ring, NULL, request))
kfree(request);
}
idle &= list_empty(&ring->request_list);
}
if (!dev_priv->mm.suspended && !idle)
queue_delayed_work(dev_priv->wq, &dev_priv->mm.retire_work, HZ);
mutex_unlock(&dev->struct_mutex);
}
static int
i915_gem_check_wedge(struct drm_i915_private *dev_priv)
{
BUG_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (atomic_read(&dev_priv->mm.wedged)) {
struct completion *x = &dev_priv->error_completion;
bool recovery_complete;
unsigned long flags;
spin_lock_irqsave(&x->wait.lock, flags);
recovery_complete = x->done > 0;
spin_unlock_irqrestore(&x->wait.lock, flags);
return recovery_complete ? -EIO : -EAGAIN;
}
return 0;
}
static int
i915_gem_check_olr(struct intel_ring_buffer *ring, u32 seqno)
{
int ret = 0;
BUG_ON(!mutex_is_locked(&ring->dev->struct_mutex));
if (seqno == ring->outstanding_lazy_request) {
struct drm_i915_gem_request *request;
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
ret = i915_add_request(ring, NULL, request);
if (ret) {
kfree(request);
return ret;
}
BUG_ON(seqno != request->seqno);
}
return ret;
}
static int __wait_seqno(struct intel_ring_buffer *ring, u32 seqno,
bool interruptible)
{
drm_i915_private_t *dev_priv = ring->dev->dev_private;
int ret = 0;
if (i915_seqno_passed(ring->get_seqno(ring), seqno))
return 0;
trace_i915_gem_request_wait_begin(ring, seqno);
if (WARN_ON(!ring->irq_get(ring)))
return -ENODEV;
#define EXIT_COND \
(i915_seqno_passed(ring->get_seqno(ring), seqno) || \
atomic_read(&dev_priv->mm.wedged))
if (interruptible)
ret = wait_event_interruptible(ring->irq_queue,
EXIT_COND);
else
wait_event(ring->irq_queue, EXIT_COND);
ring->irq_put(ring);
trace_i915_gem_request_wait_end(ring, seqno);
#undef EXIT_COND
return ret;
}
int
i915_wait_request(struct intel_ring_buffer *ring,
uint32_t seqno)
{
drm_i915_private_t *dev_priv = ring->dev->dev_private;
int ret = 0;
BUG_ON(seqno == 0);
ret = i915_gem_check_wedge(dev_priv);
if (ret)
return ret;
ret = i915_gem_check_olr(ring, seqno);
if (ret)
return ret;
ret = __wait_seqno(ring, seqno, dev_priv->mm.interruptible);
if (atomic_read(&dev_priv->mm.wedged))
ret = -EAGAIN;
return ret;
}
int
i915_gem_object_wait_rendering(struct drm_i915_gem_object *obj)
{
int ret;
BUG_ON((obj->base.write_domain & I915_GEM_GPU_DOMAINS) != 0);
if (obj->active) {
ret = i915_wait_request(obj->ring, obj->last_rendering_seqno);
if (ret)
return ret;
i915_gem_retire_requests_ring(obj->ring);
}
return 0;
}
int
i915_gem_object_sync(struct drm_i915_gem_object *obj,
struct intel_ring_buffer *to)
{
struct intel_ring_buffer *from = obj->ring;
u32 seqno;
int ret, idx;
if (from == NULL || to == from)
return 0;
if (to == NULL || !i915_semaphore_is_enabled(obj->base.dev))
return i915_gem_object_wait_rendering(obj);
idx = intel_ring_sync_index(from, to);
seqno = obj->last_rendering_seqno;
if (seqno <= from->sync_seqno[idx])
return 0;
ret = i915_gem_check_olr(obj->ring, seqno);
if (ret)
return ret;
ret = to->sync_to(to, from, seqno);
if (!ret)
from->sync_seqno[idx] = seqno;
return ret;
}
static void i915_gem_object_finish_gtt(struct drm_i915_gem_object *obj)
{
u32 old_write_domain, old_read_domains;
mb();
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
int
i915_gem_object_unbind(struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = obj->base.dev->dev_private;
int ret = 0;
if (obj->gtt_space == NULL)
return 0;
if (obj->pin_count)
return -EBUSY;
ret = i915_gem_object_finish_gpu(obj);
if (ret)
return ret;
i915_gem_object_finish_gtt(obj);
if (ret == 0)
ret = i915_gem_object_set_to_cpu_domain(obj, 1);
if (ret == -ERESTARTSYS)
return ret;
if (ret) {
i915_gem_clflush_object(obj);
obj->base.read_domains = obj->base.write_domain = I915_GEM_DOMAIN_CPU;
}
ret = i915_gem_object_put_fence(obj);
if (ret)
return ret;
trace_i915_gem_object_unbind(obj);
if (obj->has_global_gtt_mapping)
i915_gem_gtt_unbind_object(obj);
if (obj->has_aliasing_ppgtt_mapping) {
i915_ppgtt_unbind_object(dev_priv->mm.aliasing_ppgtt, obj);
obj->has_aliasing_ppgtt_mapping = 0;
}
i915_gem_gtt_finish_object(obj);
i915_gem_object_put_pages_gtt(obj);
list_del_init(&obj->gtt_list);
list_del_init(&obj->mm_list);
obj->map_and_fenceable = true;
drm_mm_put_block(obj->gtt_space);
obj->gtt_space = NULL;
obj->gtt_offset = 0;
if (i915_gem_object_is_purgeable(obj))
i915_gem_object_truncate(obj);
return ret;
}
int
i915_gem_flush_ring(struct intel_ring_buffer *ring,
uint32_t invalidate_domains,
uint32_t flush_domains)
{
int ret;
if (((invalidate_domains | flush_domains) & I915_GEM_GPU_DOMAINS) == 0)
return 0;
trace_i915_gem_ring_flush(ring, invalidate_domains, flush_domains);
ret = ring->flush(ring, invalidate_domains, flush_domains);
if (ret)
return ret;
if (flush_domains & I915_GEM_GPU_DOMAINS)
i915_gem_process_flushing_list(ring, flush_domains);
return 0;
}
static int i915_ring_idle(struct intel_ring_buffer *ring)
{
int ret;
if (list_empty(&ring->gpu_write_list) && list_empty(&ring->active_list))
return 0;
if (!list_empty(&ring->gpu_write_list)) {
ret = i915_gem_flush_ring(ring,
I915_GEM_GPU_DOMAINS, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
}
return i915_wait_request(ring, i915_gem_next_request_seqno(ring));
}
int i915_gpu_idle(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring;
int ret, i;
for_each_ring(ring, dev_priv, i) {
ret = i915_ring_idle(ring);
if (ret)
return ret;
if (WARN_ON(!list_empty(&ring->gpu_write_list)))
return -EBUSY;
}
return 0;
}
static void sandybridge_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = dev->dev_private;
uint64_t val;
if (obj) {
u32 size = obj->gtt_space->size;
val = (uint64_t)((obj->gtt_offset + size - 4096) &
0xfffff000) << 32;
val |= obj->gtt_offset & 0xfffff000;
val |= (uint64_t)((obj->stride / 128) - 1) <<
SANDYBRIDGE_FENCE_PITCH_SHIFT;
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I965_FENCE_TILING_Y_SHIFT;
val |= I965_FENCE_REG_VALID;
} else
val = 0;
I915_WRITE64(FENCE_REG_SANDYBRIDGE_0 + reg * 8, val);
POSTING_READ(FENCE_REG_SANDYBRIDGE_0 + reg * 8);
}
static void i965_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = dev->dev_private;
uint64_t val;
if (obj) {
u32 size = obj->gtt_space->size;
val = (uint64_t)((obj->gtt_offset + size - 4096) &
0xfffff000) << 32;
val |= obj->gtt_offset & 0xfffff000;
val |= ((obj->stride / 128) - 1) << I965_FENCE_PITCH_SHIFT;
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I965_FENCE_TILING_Y_SHIFT;
val |= I965_FENCE_REG_VALID;
} else
val = 0;
I915_WRITE64(FENCE_REG_965_0 + reg * 8, val);
POSTING_READ(FENCE_REG_965_0 + reg * 8);
}
static void i915_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 val;
if (obj) {
u32 size = obj->gtt_space->size;
int pitch_val;
int tile_width;
WARN((obj->gtt_offset & ~I915_FENCE_START_MASK) ||
(size & -size) != size ||
(obj->gtt_offset & (size - 1)),
"object 0x%08x [fenceable? %d] not 1M or pot-size (0x%08x) aligned\n",
obj->gtt_offset, obj->map_and_fenceable, size);
if (obj->tiling_mode == I915_TILING_Y && HAS_128_BYTE_Y_TILING(dev))
tile_width = 128;
else
tile_width = 512;
pitch_val = obj->stride / tile_width;
pitch_val = ffs(pitch_val) - 1;
val = obj->gtt_offset;
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I830_FENCE_TILING_Y_SHIFT;
val |= I915_FENCE_SIZE_BITS(size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
} else
val = 0;
if (reg < 8)
reg = FENCE_REG_830_0 + reg * 4;
else
reg = FENCE_REG_945_8 + (reg - 8) * 4;
I915_WRITE(reg, val);
POSTING_READ(reg);
}
static void i830_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = dev->dev_private;
uint32_t val;
if (obj) {
u32 size = obj->gtt_space->size;
uint32_t pitch_val;
WARN((obj->gtt_offset & ~I830_FENCE_START_MASK) ||
(size & -size) != size ||
(obj->gtt_offset & (size - 1)),
"object 0x%08x not 512K or pot-size 0x%08x aligned\n",
obj->gtt_offset, size);
pitch_val = obj->stride / 128;
pitch_val = ffs(pitch_val) - 1;
val = obj->gtt_offset;
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I830_FENCE_TILING_Y_SHIFT;
val |= I830_FENCE_SIZE_BITS(size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
} else
val = 0;
I915_WRITE(FENCE_REG_830_0 + reg * 4, val);
POSTING_READ(FENCE_REG_830_0 + reg * 4);
}
static void i915_gem_write_fence(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
switch (INTEL_INFO(dev)->gen) {
case 7:
case 6: sandybridge_write_fence_reg(dev, reg, obj); break;
case 5:
case 4: i965_write_fence_reg(dev, reg, obj); break;
case 3: i915_write_fence_reg(dev, reg, obj); break;
case 2: i830_write_fence_reg(dev, reg, obj); break;
default: break;
}
}
static inline int fence_number(struct drm_i915_private *dev_priv,
struct drm_i915_fence_reg *fence)
{
return fence - dev_priv->fence_regs;
}
static void i915_gem_object_update_fence(struct drm_i915_gem_object *obj,
struct drm_i915_fence_reg *fence,
bool enable)
{
struct drm_i915_private *dev_priv = obj->base.dev->dev_private;
int reg = fence_number(dev_priv, fence);
i915_gem_write_fence(obj->base.dev, reg, enable ? obj : NULL);
if (enable) {
obj->fence_reg = reg;
fence->obj = obj;
list_move_tail(&fence->lru_list, &dev_priv->mm.fence_list);
} else {
obj->fence_reg = I915_FENCE_REG_NONE;
fence->obj = NULL;
list_del_init(&fence->lru_list);
}
}
static int
i915_gem_object_flush_fence(struct drm_i915_gem_object *obj)
{
int ret;
if (obj->fenced_gpu_access) {
if (obj->base.write_domain & I915_GEM_GPU_DOMAINS) {
ret = i915_gem_flush_ring(obj->ring,
0, obj->base.write_domain);
if (ret)
return ret;
}
obj->fenced_gpu_access = false;
}
if (obj->last_fenced_seqno) {
ret = i915_wait_request(obj->ring, obj->last_fenced_seqno);
if (ret)
return ret;
obj->last_fenced_seqno = 0;
}
if (obj->base.read_domains & I915_GEM_DOMAIN_GTT)
mb();
return 0;
}
int
i915_gem_object_put_fence(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = obj->base.dev->dev_private;
int ret;
ret = i915_gem_object_flush_fence(obj);
if (ret)
return ret;
if (obj->fence_reg == I915_FENCE_REG_NONE)
return 0;
i915_gem_object_update_fence(obj,
&dev_priv->fence_regs[obj->fence_reg],
false);
i915_gem_object_fence_lost(obj);
return 0;
}
static struct drm_i915_fence_reg *
i915_find_fence_reg(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_fence_reg *reg, *avail;
int i;
avail = NULL;
for (i = dev_priv->fence_reg_start; i < dev_priv->num_fence_regs; i++) {
reg = &dev_priv->fence_regs[i];
if (!reg->obj)
return reg;
if (!reg->pin_count)
avail = reg;
}
if (avail == NULL)
return NULL;
list_for_each_entry(reg, &dev_priv->mm.fence_list, lru_list) {
if (reg->pin_count)
continue;
return reg;
}
return NULL;
}
int
i915_gem_object_get_fence(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
bool enable = obj->tiling_mode != I915_TILING_NONE;
struct drm_i915_fence_reg *reg;
int ret;
if (obj->fence_dirty) {
ret = i915_gem_object_flush_fence(obj);
if (ret)
return ret;
}
if (obj->fence_reg != I915_FENCE_REG_NONE) {
reg = &dev_priv->fence_regs[obj->fence_reg];
if (!obj->fence_dirty) {
list_move_tail(&reg->lru_list,
&dev_priv->mm.fence_list);
return 0;
}
} else if (enable) {
reg = i915_find_fence_reg(dev);
if (reg == NULL)
return -EDEADLK;
if (reg->obj) {
struct drm_i915_gem_object *old = reg->obj;
ret = i915_gem_object_flush_fence(old);
if (ret)
return ret;
i915_gem_object_fence_lost(old);
}
} else
return 0;
i915_gem_object_update_fence(obj, reg, enable);
obj->fence_dirty = false;
return 0;
}
static int
i915_gem_object_bind_to_gtt(struct drm_i915_gem_object *obj,
unsigned alignment,
bool map_and_fenceable)
{
struct drm_device *dev = obj->base.dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_mm_node *free_space;
gfp_t gfpmask = __GFP_NORETRY | __GFP_NOWARN;
u32 size, fence_size, fence_alignment, unfenced_alignment;
bool mappable, fenceable;
int ret;
if (obj->madv != I915_MADV_WILLNEED) {
DRM_ERROR("Attempting to bind a purgeable object\n");
return -EINVAL;
}
fence_size = i915_gem_get_gtt_size(dev,
obj->base.size,
obj->tiling_mode);
fence_alignment = i915_gem_get_gtt_alignment(dev,
obj->base.size,
obj->tiling_mode);
unfenced_alignment =
i915_gem_get_unfenced_gtt_alignment(dev,
obj->base.size,
obj->tiling_mode);
if (alignment == 0)
alignment = map_and_fenceable ? fence_alignment :
unfenced_alignment;
if (map_and_fenceable && alignment & (fence_alignment - 1)) {
DRM_ERROR("Invalid object alignment requested %u\n", alignment);
return -EINVAL;
}
size = map_and_fenceable ? fence_size : obj->base.size;
if (obj->base.size >
(map_and_fenceable ? dev_priv->mm.gtt_mappable_end : dev_priv->mm.gtt_total)) {
DRM_ERROR("Attempting to bind an object larger than the aperture\n");
return -E2BIG;
}
search_free:
if (map_and_fenceable)
free_space =
drm_mm_search_free_in_range(&dev_priv->mm.gtt_space,
size, alignment, 0,
dev_priv->mm.gtt_mappable_end,
0);
else
free_space = drm_mm_search_free(&dev_priv->mm.gtt_space,
size, alignment, 0);
if (free_space != NULL) {
if (map_and_fenceable)
obj->gtt_space =
drm_mm_get_block_range_generic(free_space,
size, alignment, 0,
dev_priv->mm.gtt_mappable_end,
0);
else
obj->gtt_space =
drm_mm_get_block(free_space, size, alignment);
}
if (obj->gtt_space == NULL) {
ret = i915_gem_evict_something(dev, size, alignment,
map_and_fenceable);
if (ret)
return ret;
goto search_free;
}
ret = i915_gem_object_get_pages_gtt(obj, gfpmask);
if (ret) {
drm_mm_put_block(obj->gtt_space);
obj->gtt_space = NULL;
if (ret == -ENOMEM) {
ret = i915_gem_evict_everything(dev, false);
if (ret) {
if (gfpmask) {
gfpmask = 0;
goto search_free;
}
return -ENOMEM;
}
goto search_free;
}
return ret;
}
ret = i915_gem_gtt_prepare_object(obj);
if (ret) {
i915_gem_object_put_pages_gtt(obj);
drm_mm_put_block(obj->gtt_space);
obj->gtt_space = NULL;
if (i915_gem_evict_everything(dev, false))
return ret;
goto search_free;
}
if (!dev_priv->mm.aliasing_ppgtt)
i915_gem_gtt_bind_object(obj, obj->cache_level);
list_add_tail(&obj->gtt_list, &dev_priv->mm.gtt_list);
list_add_tail(&obj->mm_list, &dev_priv->mm.inactive_list);
BUG_ON(obj->base.read_domains & I915_GEM_GPU_DOMAINS);
BUG_ON(obj->base.write_domain & I915_GEM_GPU_DOMAINS);
obj->gtt_offset = obj->gtt_space->start;
fenceable =
obj->gtt_space->size == fence_size &&
(obj->gtt_space->start & (fence_alignment - 1)) == 0;
mappable =
obj->gtt_offset + obj->base.size <= dev_priv->mm.gtt_mappable_end;
obj->map_and_fenceable = mappable && fenceable;
trace_i915_gem_object_bind(obj, map_and_fenceable);
return 0;
}
void
i915_gem_clflush_object(struct drm_i915_gem_object *obj)
{
if (obj->pages == NULL)
return;
if (obj->cache_level != I915_CACHE_NONE)
return;
trace_i915_gem_object_clflush(obj);
drm_clflush_pages(obj->pages, obj->base.size / PAGE_SIZE);
}
static int
i915_gem_object_flush_gpu_write_domain(struct drm_i915_gem_object *obj)
{
if ((obj->base.write_domain & I915_GEM_GPU_DOMAINS) == 0)
return 0;
return i915_gem_flush_ring(obj->ring, 0, obj->base.write_domain);
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
i915_gem_clflush_object(obj);
intel_gtt_chipset_flush();
old_write_domain = obj->base.write_domain;
obj->base.write_domain = 0;
trace_i915_gem_object_change_domain(obj,
obj->base.read_domains,
old_write_domain);
}
int
i915_gem_object_set_to_gtt_domain(struct drm_i915_gem_object *obj, bool write)
{
drm_i915_private_t *dev_priv = obj->base.dev->dev_private;
uint32_t old_write_domain, old_read_domains;
int ret;
if (obj->gtt_space == NULL)
return -EINVAL;
if (obj->base.write_domain == I915_GEM_DOMAIN_GTT)
return 0;
ret = i915_gem_object_flush_gpu_write_domain(obj);
if (ret)
return ret;
if (obj->pending_gpu_write || write) {
ret = i915_gem_object_wait_rendering(obj);
if (ret)
return ret;
}
i915_gem_object_flush_cpu_write_domain(obj);
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
if (i915_gem_object_is_inactive(obj))
list_move_tail(&obj->mm_list, &dev_priv->mm.inactive_list);
return 0;
}
int i915_gem_object_set_cache_level(struct drm_i915_gem_object *obj,
enum i915_cache_level cache_level)
{
struct drm_device *dev = obj->base.dev;
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
if (obj->cache_level == cache_level)
return 0;
if (obj->pin_count) {
DRM_DEBUG("can not change the cache level of pinned objects\n");
return -EBUSY;
}
if (obj->gtt_space) {
ret = i915_gem_object_finish_gpu(obj);
if (ret)
return ret;
i915_gem_object_finish_gtt(obj);
if (INTEL_INFO(obj->base.dev)->gen < 6) {
ret = i915_gem_object_put_fence(obj);
if (ret)
return ret;
}
if (obj->has_global_gtt_mapping)
i915_gem_gtt_bind_object(obj, cache_level);
if (obj->has_aliasing_ppgtt_mapping)
i915_ppgtt_bind_object(dev_priv->mm.aliasing_ppgtt,
obj, cache_level);
}
if (cache_level == I915_CACHE_NONE) {
u32 old_read_domains, old_write_domain;
WARN_ON(obj->base.write_domain & ~I915_GEM_DOMAIN_CPU);
WARN_ON(obj->base.read_domains & ~I915_GEM_DOMAIN_CPU);
old_read_domains = obj->base.read_domains;
old_write_domain = obj->base.write_domain;
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
}
obj->cache_level = cache_level;
return 0;
}
int
i915_gem_object_pin_to_display_plane(struct drm_i915_gem_object *obj,
u32 alignment,
struct intel_ring_buffer *pipelined)
{
u32 old_read_domains, old_write_domain;
int ret;
ret = i915_gem_object_flush_gpu_write_domain(obj);
if (ret)
return ret;
if (pipelined != obj->ring) {
ret = i915_gem_object_sync(obj, pipelined);
if (ret)
return ret;
}
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_NONE);
if (ret)
return ret;
ret = i915_gem_object_pin(obj, alignment, true);
if (ret)
return ret;
i915_gem_object_flush_cpu_write_domain(obj);
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
BUG_ON((obj->base.write_domain & ~I915_GEM_DOMAIN_GTT) != 0);
obj->base.read_domains |= I915_GEM_DOMAIN_GTT;
trace_i915_gem_object_change_domain(obj,
old_read_domains,
old_write_domain);
return 0;
}
int
i915_gem_object_finish_gpu(struct drm_i915_gem_object *obj)
{
int ret;
if ((obj->base.read_domains & I915_GEM_GPU_DOMAINS) == 0)
return 0;
if (obj->base.write_domain & I915_GEM_GPU_DOMAINS) {
ret = i915_gem_flush_ring(obj->ring, 0, obj->base.write_domain);
if (ret)
return ret;
}
ret = i915_gem_object_wait_rendering(obj);
if (ret)
return ret;
obj->base.read_domains &= ~I915_GEM_GPU_DOMAINS;
return 0;
}
int
i915_gem_object_set_to_cpu_domain(struct drm_i915_gem_object *obj, bool write)
{
uint32_t old_write_domain, old_read_domains;
int ret;
if (obj->base.write_domain == I915_GEM_DOMAIN_CPU)
return 0;
ret = i915_gem_object_flush_gpu_write_domain(obj);
if (ret)
return ret;
if (write || obj->pending_gpu_write) {
ret = i915_gem_object_wait_rendering(obj);
if (ret)
return ret;
}
i915_gem_object_flush_gtt_write_domain(obj);
old_write_domain = obj->base.write_domain;
old_read_domains = obj->base.read_domains;
if ((obj->base.read_domains & I915_GEM_DOMAIN_CPU) == 0) {
i915_gem_clflush_object(obj);
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
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_file_private *file_priv = file->driver_priv;
unsigned long recent_enough = jiffies - msecs_to_jiffies(20);
struct drm_i915_gem_request *request;
struct intel_ring_buffer *ring = NULL;
u32 seqno = 0;
int ret;
if (atomic_read(&dev_priv->mm.wedged))
return -EIO;
spin_lock(&file_priv->mm.lock);
list_for_each_entry(request, &file_priv->mm.request_list, client_list) {
if (time_after_eq(request->emitted_jiffies, recent_enough))
break;
ring = request->ring;
seqno = request->seqno;
}
spin_unlock(&file_priv->mm.lock);
if (seqno == 0)
return 0;
ret = __wait_seqno(ring, seqno, true);
if (ret == 0)
queue_delayed_work(dev_priv->wq, &dev_priv->mm.retire_work, 0);
return ret;
}
int
i915_gem_object_pin(struct drm_i915_gem_object *obj,
uint32_t alignment,
bool map_and_fenceable)
{
int ret;
BUG_ON(obj->pin_count == DRM_I915_GEM_OBJECT_MAX_PIN_COUNT);
if (obj->gtt_space != NULL) {
if ((alignment && obj->gtt_offset & (alignment - 1)) ||
(map_and_fenceable && !obj->map_and_fenceable)) {
WARN(obj->pin_count,
"bo is already pinned with incorrect alignment:"
" offset=%x, req.alignment=%x, req.map_and_fenceable=%d,"
" obj->map_and_fenceable=%d\n",
obj->gtt_offset, alignment,
map_and_fenceable,
obj->map_and_fenceable);
ret = i915_gem_object_unbind(obj);
if (ret)
return ret;
}
}
if (obj->gtt_space == NULL) {
ret = i915_gem_object_bind_to_gtt(obj, alignment,
map_and_fenceable);
if (ret)
return ret;
}
if (!obj->has_global_gtt_mapping && map_and_fenceable)
i915_gem_gtt_bind_object(obj, obj->cache_level);
obj->pin_count++;
obj->pin_mappable |= map_and_fenceable;
return 0;
}
void
i915_gem_object_unpin(struct drm_i915_gem_object *obj)
{
BUG_ON(obj->pin_count == 0);
BUG_ON(obj->gtt_space == NULL);
if (--obj->pin_count == 0)
obj->pin_mappable = false;
}
int
i915_gem_pin_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_pin *args = data;
struct drm_i915_gem_object *obj;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->madv != I915_MADV_WILLNEED) {
DRM_ERROR("Attempting to pin a purgeable buffer\n");
ret = -EINVAL;
goto out;
}
if (obj->pin_filp != NULL && obj->pin_filp != file) {
DRM_ERROR("Already pinned in i915_gem_pin_ioctl(): %d\n",
args->handle);
ret = -EINVAL;
goto out;
}
obj->user_pin_count++;
obj->pin_filp = file;
if (obj->user_pin_count == 1) {
ret = i915_gem_object_pin(obj, args->alignment, true);
if (ret)
goto out;
}
i915_gem_object_flush_cpu_write_domain(obj);
args->offset = obj->gtt_offset;
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_unpin_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_pin *args = data;
struct drm_i915_gem_object *obj;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->pin_filp != file) {
DRM_ERROR("Not pinned by caller in i915_gem_pin_ioctl(): %d\n",
args->handle);
ret = -EINVAL;
goto out;
}
obj->user_pin_count--;
if (obj->user_pin_count == 0) {
obj->pin_filp = NULL;
i915_gem_object_unpin(obj);
}
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
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
obj = to_intel_bo(drm_gem_object_lookup(dev, file, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
args->busy = obj->active;
if (args->busy) {
if (obj->base.write_domain & I915_GEM_GPU_DOMAINS) {
ret = i915_gem_flush_ring(obj->ring,
0, obj->base.write_domain);
} else {
ret = i915_gem_check_olr(obj->ring,
obj->last_rendering_seqno);
}
i915_gem_retire_requests_ring(obj->ring);
args->busy = obj->active;
}
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
obj = to_intel_bo(drm_gem_object_lookup(dev, file_priv, args->handle));
if (&obj->base == NULL) {
ret = -ENOENT;
goto unlock;
}
if (obj->pin_count) {
ret = -EINVAL;
goto out;
}
if (obj->madv != __I915_MADV_PURGED)
obj->madv = args->madv;
if (i915_gem_object_is_purgeable(obj) &&
obj->gtt_space == NULL)
i915_gem_object_truncate(obj);
args->retained = obj->madv != __I915_MADV_PURGED;
out:
drm_gem_object_unreference(&obj->base);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
struct drm_i915_gem_object *i915_gem_alloc_object(struct drm_device *dev,
size_t size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct address_space *mapping;
u32 mask;
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (obj == NULL)
return NULL;
if (drm_gem_object_init(dev, &obj->base, size) != 0) {
kfree(obj);
return NULL;
}
mask = GFP_HIGHUSER | __GFP_RECLAIMABLE;
if (IS_CRESTLINE(dev) || IS_BROADWATER(dev)) {
mask &= ~__GFP_HIGHMEM;
mask |= __GFP_DMA32;
}
mapping = obj->base.filp->f_path.dentry->d_inode->i_mapping;
mapping_set_gfp_mask(mapping, mask);
i915_gem_info_add_obj(dev_priv, size);
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
if (HAS_LLC(dev)) {
obj->cache_level = I915_CACHE_LLC;
} else
obj->cache_level = I915_CACHE_NONE;
obj->base.driver_private = NULL;
obj->fence_reg = I915_FENCE_REG_NONE;
INIT_LIST_HEAD(&obj->mm_list);
INIT_LIST_HEAD(&obj->gtt_list);
INIT_LIST_HEAD(&obj->ring_list);
INIT_LIST_HEAD(&obj->exec_list);
INIT_LIST_HEAD(&obj->gpu_write_list);
obj->madv = I915_MADV_WILLNEED;
obj->map_and_fenceable = true;
return obj;
}
int i915_gem_init_object(struct drm_gem_object *obj)
{
BUG();
return 0;
}
void i915_gem_free_object(struct drm_gem_object *gem_obj)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem_obj);
struct drm_device *dev = obj->base.dev;
drm_i915_private_t *dev_priv = dev->dev_private;
trace_i915_gem_object_destroy(obj);
if (gem_obj->import_attach)
drm_prime_gem_destroy(gem_obj, obj->sg_table);
if (obj->phys_obj)
i915_gem_detach_phys_object(dev, obj);
obj->pin_count = 0;
if (WARN_ON(i915_gem_object_unbind(obj) == -ERESTARTSYS)) {
bool was_interruptible;
was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
WARN_ON(i915_gem_object_unbind(obj));
dev_priv->mm.interruptible = was_interruptible;
}
if (obj->base.map_list.map)
drm_gem_free_mmap_offset(&obj->base);
drm_gem_object_release(&obj->base);
i915_gem_info_remove_obj(dev_priv, obj->base.size);
kfree(obj->bit_17);
kfree(obj);
}
int
i915_gem_idle(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
mutex_lock(&dev->struct_mutex);
if (dev_priv->mm.suspended) {
mutex_unlock(&dev->struct_mutex);
return 0;
}
ret = i915_gpu_idle(dev);
if (ret) {
mutex_unlock(&dev->struct_mutex);
return ret;
}
i915_gem_retire_requests(dev);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_gem_evict_everything(dev, false);
i915_gem_reset_fences(dev);
dev_priv->mm.suspended = 1;
del_timer_sync(&dev_priv->hangcheck_timer);
i915_kernel_lost_context(dev);
i915_gem_cleanup_ringbuffer(dev);
mutex_unlock(&dev->struct_mutex);
cancel_delayed_work_sync(&dev_priv->mm.retire_work);
return 0;
}
void i915_gem_init_swizzling(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
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
else
I915_WRITE(ARB_MODE, _MASKED_BIT_ENABLE(ARB_MODE_SWIZZLE_IVB));
}
void i915_gem_init_ppgtt(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
uint32_t pd_offset;
struct intel_ring_buffer *ring;
struct i915_hw_ppgtt *ppgtt = dev_priv->mm.aliasing_ppgtt;
uint32_t __iomem *pd_addr;
uint32_t pd_entry;
int i;
if (!dev_priv->mm.aliasing_ppgtt)
return;
pd_addr = dev_priv->mm.gtt->gtt + ppgtt->pd_offset/sizeof(uint32_t);
for (i = 0; i < ppgtt->num_pd_entries; i++) {
dma_addr_t pt_addr;
if (dev_priv->mm.gtt->needs_dmar)
pt_addr = ppgtt->pt_dma_addr[i];
else
pt_addr = page_to_phys(ppgtt->pt_pages[i]);
pd_entry = GEN6_PDE_ADDR_ENCODE(pt_addr);
pd_entry |= GEN6_PDE_VALID;
writel(pd_entry, pd_addr + i);
}
readl(pd_addr);
pd_offset = ppgtt->pd_offset;
pd_offset /= 64;
pd_offset <<= 16;
if (INTEL_INFO(dev)->gen == 6) {
uint32_t ecochk, gab_ctl, ecobits;
ecobits = I915_READ(GAC_ECO_BITS);
I915_WRITE(GAC_ECO_BITS, ecobits | ECOBITS_PPGTT_CACHE64B);
gab_ctl = I915_READ(GAB_CTL);
I915_WRITE(GAB_CTL, gab_ctl | GAB_CTL_CONT_AFTER_PAGEFAULT);
ecochk = I915_READ(GAM_ECOCHK);
I915_WRITE(GAM_ECOCHK, ecochk | ECOCHK_SNB_BIT |
ECOCHK_PPGTT_CACHE64B);
I915_WRITE(GFX_MODE, _MASKED_BIT_ENABLE(GFX_PPGTT_ENABLE));
} else if (INTEL_INFO(dev)->gen >= 7) {
I915_WRITE(GAM_ECOCHK, ECOCHK_PPGTT_CACHE64B);
}
for_each_ring(ring, dev_priv, i) {
if (INTEL_INFO(dev)->gen >= 7)
I915_WRITE(RING_MODE_GEN7(ring),
_MASKED_BIT_ENABLE(GFX_PPGTT_ENABLE));
I915_WRITE(RING_PP_DIR_DCLV(ring), PP_DIR_DCLV_2G);
I915_WRITE(RING_PP_DIR_BASE(ring), pd_offset);
}
}
int
i915_gem_init_hw(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
i915_gem_init_swizzling(dev);
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
dev_priv->next_seqno = 1;
i915_gem_init_ppgtt(dev);
return 0;
cleanup_bsd_ring:
intel_cleanup_ring_buffer(&dev_priv->ring[VCS]);
cleanup_render_ring:
intel_cleanup_ring_buffer(&dev_priv->ring[RCS]);
return ret;
}
static bool
intel_enable_ppgtt(struct drm_device *dev)
{
if (i915_enable_ppgtt >= 0)
return i915_enable_ppgtt;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return true;
}
int i915_gem_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long gtt_size, mappable_size;
int ret;
gtt_size = dev_priv->mm.gtt->gtt_total_entries << PAGE_SHIFT;
mappable_size = dev_priv->mm.gtt->gtt_mappable_entries << PAGE_SHIFT;
mutex_lock(&dev->struct_mutex);
if (intel_enable_ppgtt(dev) && HAS_ALIASING_PPGTT(dev)) {
gtt_size -= I915_PPGTT_PD_ENTRIES*PAGE_SIZE;
i915_gem_init_global_gtt(dev, 0, mappable_size, gtt_size);
ret = i915_gem_init_aliasing_ppgtt(dev);
if (ret) {
mutex_unlock(&dev->struct_mutex);
return ret;
}
} else {
i915_gem_init_global_gtt(dev, 0, mappable_size,
gtt_size);
}
ret = i915_gem_init_hw(dev);
mutex_unlock(&dev->struct_mutex);
if (ret) {
i915_gem_cleanup_aliasing_ppgtt(dev);
return ret;
}
if (!drm_core_check_feature(dev, DRIVER_MODESET))
dev_priv->dri1.allow_batchbuffer = 1;
return 0;
}
void
i915_gem_cleanup_ringbuffer(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring;
int i;
for_each_ring(ring, dev_priv, i)
intel_cleanup_ring_buffer(ring);
}
int
i915_gem_entervt_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return 0;
if (atomic_read(&dev_priv->mm.wedged)) {
DRM_ERROR("Reenabling wedged hardware, good luck\n");
atomic_set(&dev_priv->mm.wedged, 0);
}
mutex_lock(&dev->struct_mutex);
dev_priv->mm.suspended = 0;
ret = i915_gem_init_hw(dev);
if (ret != 0) {
mutex_unlock(&dev->struct_mutex);
return ret;
}
BUG_ON(!list_empty(&dev_priv->mm.active_list));
BUG_ON(!list_empty(&dev_priv->mm.flushing_list));
BUG_ON(!list_empty(&dev_priv->mm.inactive_list));
mutex_unlock(&dev->struct_mutex);
ret = drm_irq_install(dev);
if (ret)
goto cleanup_ringbuffer;
return 0;
cleanup_ringbuffer:
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_ringbuffer(dev);
dev_priv->mm.suspended = 1;
mutex_unlock(&dev->struct_mutex);
return ret;
}
int
i915_gem_leavevt_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
if (drm_core_check_feature(dev, DRIVER_MODESET))
return 0;
drm_irq_uninstall(dev);
return i915_gem_idle(dev);
}
void
i915_gem_lastclose(struct drm_device *dev)
{
int ret;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return;
ret = i915_gem_idle(dev);
if (ret)
DRM_ERROR("failed to idle hardware: %d\n", ret);
}
static void
init_ring_lists(struct intel_ring_buffer *ring)
{
INIT_LIST_HEAD(&ring->active_list);
INIT_LIST_HEAD(&ring->request_list);
INIT_LIST_HEAD(&ring->gpu_write_list);
}
void
i915_gem_load(struct drm_device *dev)
{
int i;
drm_i915_private_t *dev_priv = dev->dev_private;
INIT_LIST_HEAD(&dev_priv->mm.active_list);
INIT_LIST_HEAD(&dev_priv->mm.flushing_list);
INIT_LIST_HEAD(&dev_priv->mm.inactive_list);
INIT_LIST_HEAD(&dev_priv->mm.fence_list);
INIT_LIST_HEAD(&dev_priv->mm.gtt_list);
for (i = 0; i < I915_NUM_RINGS; i++)
init_ring_lists(&dev_priv->ring[i]);
for (i = 0; i < I915_MAX_NUM_FENCES; i++)
INIT_LIST_HEAD(&dev_priv->fence_regs[i].lru_list);
INIT_DELAYED_WORK(&dev_priv->mm.retire_work,
i915_gem_retire_work_handler);
init_completion(&dev_priv->error_completion);
if (IS_GEN3(dev)) {
I915_WRITE(MI_ARB_STATE,
_MASKED_BIT_ENABLE(MI_ARB_C3_LP_WRITE_ENABLE));
}
dev_priv->relative_constants_mode = I915_EXEC_CONSTANTS_REL_GENERAL;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
dev_priv->fence_reg_start = 3;
if (INTEL_INFO(dev)->gen >= 4 || IS_I945G(dev) || IS_I945GM(dev) || IS_G33(dev))
dev_priv->num_fence_regs = 16;
else
dev_priv->num_fence_regs = 8;
i915_gem_reset_fences(dev);
i915_gem_detect_bit_6_swizzle(dev);
init_waitqueue_head(&dev_priv->pending_flip_queue);
dev_priv->mm.interruptible = true;
dev_priv->mm.inactive_shrinker.shrink = i915_gem_inactive_shrink;
dev_priv->mm.inactive_shrinker.seeks = DEFAULT_SEEKS;
register_shrinker(&dev_priv->mm.inactive_shrinker);
}
static int i915_gem_init_phys_object(struct drm_device *dev,
int id, int size, int align)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_gem_phys_object *phys_obj;
int ret;
if (dev_priv->mm.phys_objs[id - 1] || !size)
return 0;
phys_obj = kzalloc(sizeof(struct drm_i915_gem_phys_object), GFP_KERNEL);
if (!phys_obj)
return -ENOMEM;
phys_obj->id = id;
phys_obj->handle = drm_pci_alloc(dev, size, align);
if (!phys_obj->handle) {
ret = -ENOMEM;
goto kfree_obj;
}
#ifdef CONFIG_X86
set_memory_wc((unsigned long)phys_obj->handle->vaddr, phys_obj->handle->size / PAGE_SIZE);
#endif
dev_priv->mm.phys_objs[id - 1] = phys_obj;
return 0;
kfree_obj:
kfree(phys_obj);
return ret;
}
static void i915_gem_free_phys_object(struct drm_device *dev, int id)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_gem_phys_object *phys_obj;
if (!dev_priv->mm.phys_objs[id - 1])
return;
phys_obj = dev_priv->mm.phys_objs[id - 1];
if (phys_obj->cur_obj) {
i915_gem_detach_phys_object(dev, phys_obj->cur_obj);
}
#ifdef CONFIG_X86
set_memory_wb((unsigned long)phys_obj->handle->vaddr, phys_obj->handle->size / PAGE_SIZE);
#endif
drm_pci_free(dev, phys_obj->handle);
kfree(phys_obj);
dev_priv->mm.phys_objs[id - 1] = NULL;
}
void i915_gem_free_all_phys_object(struct drm_device *dev)
{
int i;
for (i = I915_GEM_PHYS_CURSOR_0; i <= I915_MAX_PHYS_OBJECT; i++)
i915_gem_free_phys_object(dev, i);
}
void i915_gem_detach_phys_object(struct drm_device *dev,
struct drm_i915_gem_object *obj)
{
struct address_space *mapping = obj->base.filp->f_path.dentry->d_inode->i_mapping;
char *vaddr;
int i;
int page_count;
if (!obj->phys_obj)
return;
vaddr = obj->phys_obj->handle->vaddr;
page_count = obj->base.size / PAGE_SIZE;
for (i = 0; i < page_count; i++) {
struct page *page = shmem_read_mapping_page(mapping, i);
if (!IS_ERR(page)) {
char *dst = kmap_atomic(page);
memcpy(dst, vaddr + i*PAGE_SIZE, PAGE_SIZE);
kunmap_atomic(dst);
drm_clflush_pages(&page, 1);
set_page_dirty(page);
mark_page_accessed(page);
page_cache_release(page);
}
}
intel_gtt_chipset_flush();
obj->phys_obj->cur_obj = NULL;
obj->phys_obj = NULL;
}
int
i915_gem_attach_phys_object(struct drm_device *dev,
struct drm_i915_gem_object *obj,
int id,
int align)
{
struct address_space *mapping = obj->base.filp->f_path.dentry->d_inode->i_mapping;
drm_i915_private_t *dev_priv = dev->dev_private;
int ret = 0;
int page_count;
int i;
if (id > I915_MAX_PHYS_OBJECT)
return -EINVAL;
if (obj->phys_obj) {
if (obj->phys_obj->id == id)
return 0;
i915_gem_detach_phys_object(dev, obj);
}
if (!dev_priv->mm.phys_objs[id - 1]) {
ret = i915_gem_init_phys_object(dev, id,
obj->base.size, align);
if (ret) {
DRM_ERROR("failed to init phys object %d size: %zu\n",
id, obj->base.size);
return ret;
}
}
obj->phys_obj = dev_priv->mm.phys_objs[id - 1];
obj->phys_obj->cur_obj = obj;
page_count = obj->base.size / PAGE_SIZE;
for (i = 0; i < page_count; i++) {
struct page *page;
char *dst, *src;
page = shmem_read_mapping_page(mapping, i);
if (IS_ERR(page))
return PTR_ERR(page);
src = kmap_atomic(page);
dst = obj->phys_obj->handle->vaddr + (i * PAGE_SIZE);
memcpy(dst, src, PAGE_SIZE);
kunmap_atomic(src);
mark_page_accessed(page);
page_cache_release(page);
}
return 0;
}
static int
i915_gem_phys_pwrite(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_pwrite *args,
struct drm_file *file_priv)
{
void *vaddr = obj->phys_obj->handle->vaddr + args->offset;
char __user *user_data = (char __user *) (uintptr_t) args->data_ptr;
if (__copy_from_user_inatomic_nocache(vaddr, user_data, args->size)) {
unsigned long unwritten;
mutex_unlock(&dev->struct_mutex);
unwritten = copy_from_user(vaddr, user_data, args->size);
mutex_lock(&dev->struct_mutex);
if (unwritten)
return -EFAULT;
}
intel_gtt_chipset_flush();
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
}
static int
i915_gpu_is_active(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int lists_empty;
lists_empty = list_empty(&dev_priv->mm.flushing_list) &&
list_empty(&dev_priv->mm.active_list);
return !lists_empty;
}
static int
i915_gem_inactive_shrink(struct shrinker *shrinker, struct shrink_control *sc)
{
struct drm_i915_private *dev_priv =
container_of(shrinker,
struct drm_i915_private,
mm.inactive_shrinker);
struct drm_device *dev = dev_priv->dev;
struct drm_i915_gem_object *obj, *next;
int nr_to_scan = sc->nr_to_scan;
int cnt;
if (!mutex_trylock(&dev->struct_mutex))
return 0;
if (nr_to_scan == 0) {
cnt = 0;
list_for_each_entry(obj,
&dev_priv->mm.inactive_list,
mm_list)
cnt++;
mutex_unlock(&dev->struct_mutex);
return cnt / 100 * sysctl_vfs_cache_pressure;
}
rescan:
i915_gem_retire_requests(dev);
list_for_each_entry_safe(obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if (i915_gem_object_is_purgeable(obj)) {
if (i915_gem_object_unbind(obj) == 0 &&
--nr_to_scan == 0)
break;
}
}
cnt = 0;
list_for_each_entry_safe(obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if (nr_to_scan &&
i915_gem_object_unbind(obj) == 0)
nr_to_scan--;
else
cnt++;
}
if (nr_to_scan && i915_gpu_is_active(dev)) {
if (i915_gpu_idle(dev) == 0)
goto rescan;
}
mutex_unlock(&dev->struct_mutex);
return cnt / 100 * sysctl_vfs_cache_pressure;
}
