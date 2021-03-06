int radeon_gem_object_init(struct drm_gem_object *obj)
{
BUG();
return 0;
}
void radeon_gem_object_free(struct drm_gem_object *gobj)
{
struct radeon_bo *robj = gem_to_radeon_bo(gobj);
if (robj) {
if (robj->gem_base.import_attach)
drm_prime_gem_destroy(&robj->gem_base, robj->tbo.sg);
radeon_bo_unref(&robj);
}
}
int radeon_gem_object_create(struct radeon_device *rdev, int size,
int alignment, int initial_domain,
bool discardable, bool kernel,
struct drm_gem_object **obj)
{
struct radeon_bo *robj;
unsigned long max_size;
int r;
*obj = NULL;
if (alignment < PAGE_SIZE) {
alignment = PAGE_SIZE;
}
max_size = min(rdev->mc.visible_vram_size, rdev->mc.gtt_size);
if (size > max_size) {
printk(KERN_WARNING "%s:%d alloc size %dMb bigger than %ldMb limit\n",
__func__, __LINE__, size >> 20, max_size >> 20);
return -ENOMEM;
}
retry:
r = radeon_bo_create(rdev, size, alignment, kernel, initial_domain, NULL, &robj);
if (r) {
if (r != -ERESTARTSYS) {
if (initial_domain == RADEON_GEM_DOMAIN_VRAM) {
initial_domain |= RADEON_GEM_DOMAIN_GTT;
goto retry;
}
DRM_ERROR("Failed to allocate GEM object (%d, %d, %u, %d)\n",
size, initial_domain, alignment, r);
}
return r;
}
*obj = &robj->gem_base;
robj->pid = task_pid_nr(current);
mutex_lock(&rdev->gem.mutex);
list_add_tail(&robj->list, &rdev->gem.objects);
mutex_unlock(&rdev->gem.mutex);
return 0;
}
int radeon_gem_set_domain(struct drm_gem_object *gobj,
uint32_t rdomain, uint32_t wdomain)
{
struct radeon_bo *robj;
uint32_t domain;
int r;
robj = gem_to_radeon_bo(gobj);
domain = wdomain;
if (!domain) {
domain = rdomain;
}
if (!domain) {
printk(KERN_WARNING "Set domain without domain !\n");
return 0;
}
if (domain == RADEON_GEM_DOMAIN_CPU) {
r = radeon_bo_wait(robj, NULL, false);
if (r) {
printk(KERN_ERR "Failed to wait for object !\n");
return r;
}
}
return 0;
}
int radeon_gem_init(struct radeon_device *rdev)
{
INIT_LIST_HEAD(&rdev->gem.objects);
return 0;
}
void radeon_gem_fini(struct radeon_device *rdev)
{
radeon_bo_force_delete(rdev);
}
int radeon_gem_object_open(struct drm_gem_object *obj, struct drm_file *file_priv)
{
struct radeon_bo *rbo = gem_to_radeon_bo(obj);
struct radeon_device *rdev = rbo->rdev;
struct radeon_fpriv *fpriv = file_priv->driver_priv;
struct radeon_vm *vm = &fpriv->vm;
struct radeon_bo_va *bo_va;
int r;
if (rdev->family < CHIP_CAYMAN) {
return 0;
}
r = radeon_bo_reserve(rbo, false);
if (r) {
return r;
}
bo_va = radeon_vm_bo_find(vm, rbo);
if (!bo_va) {
bo_va = radeon_vm_bo_add(rdev, vm, rbo);
} else {
++bo_va->ref_count;
}
radeon_bo_unreserve(rbo);
return 0;
}
void radeon_gem_object_close(struct drm_gem_object *obj,
struct drm_file *file_priv)
{
struct radeon_bo *rbo = gem_to_radeon_bo(obj);
struct radeon_device *rdev = rbo->rdev;
struct radeon_fpriv *fpriv = file_priv->driver_priv;
struct radeon_vm *vm = &fpriv->vm;
struct radeon_bo_va *bo_va;
int r;
if (rdev->family < CHIP_CAYMAN) {
return;
}
r = radeon_bo_reserve(rbo, true);
if (r) {
dev_err(rdev->dev, "leaking bo va because "
"we fail to reserve bo (%d)\n", r);
return;
}
bo_va = radeon_vm_bo_find(vm, rbo);
if (bo_va) {
if (--bo_va->ref_count == 0) {
radeon_vm_bo_rmv(rdev, bo_va);
}
}
radeon_bo_unreserve(rbo);
}
static int radeon_gem_handle_lockup(struct radeon_device *rdev, int r)
{
if (r == -EDEADLK) {
r = radeon_gpu_reset(rdev);
if (!r)
r = -EAGAIN;
}
return r;
}
int radeon_gem_info_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_gem_info *args = data;
struct ttm_mem_type_manager *man;
unsigned i;
man = &rdev->mman.bdev.man[TTM_PL_VRAM];
args->vram_size = rdev->mc.real_vram_size;
args->vram_visible = (u64)man->size << PAGE_SHIFT;
if (rdev->stollen_vga_memory)
args->vram_visible -= radeon_bo_size(rdev->stollen_vga_memory);
args->vram_visible -= radeon_fbdev_total_size(rdev);
args->gart_size = rdev->mc.gtt_size - 4096 - RADEON_IB_POOL_SIZE*64*1024;
for(i = 0; i < RADEON_NUM_RINGS; ++i)
args->gart_size -= rdev->ring[i].ring_size;
return 0;
}
int radeon_gem_pread_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
DRM_ERROR("unimplemented %s\n", __func__);
return -ENOSYS;
}
int radeon_gem_pwrite_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
DRM_ERROR("unimplemented %s\n", __func__);
return -ENOSYS;
}
int radeon_gem_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_gem_create *args = data;
struct drm_gem_object *gobj;
uint32_t handle;
int r;
down_read(&rdev->exclusive_lock);
args->size = roundup(args->size, PAGE_SIZE);
r = radeon_gem_object_create(rdev, args->size, args->alignment,
args->initial_domain, false,
false, &gobj);
if (r) {
up_read(&rdev->exclusive_lock);
r = radeon_gem_handle_lockup(rdev, r);
return r;
}
r = drm_gem_handle_create(filp, gobj, &handle);
drm_gem_object_unreference_unlocked(gobj);
if (r) {
up_read(&rdev->exclusive_lock);
r = radeon_gem_handle_lockup(rdev, r);
return r;
}
args->handle = handle;
up_read(&rdev->exclusive_lock);
return 0;
}
int radeon_gem_set_domain_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_gem_set_domain *args = data;
struct drm_gem_object *gobj;
struct radeon_bo *robj;
int r;
down_read(&rdev->exclusive_lock);
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL) {
up_read(&rdev->exclusive_lock);
return -ENOENT;
}
robj = gem_to_radeon_bo(gobj);
r = radeon_gem_set_domain(gobj, args->read_domains, args->write_domain);
drm_gem_object_unreference_unlocked(gobj);
up_read(&rdev->exclusive_lock);
r = radeon_gem_handle_lockup(robj->rdev, r);
return r;
}
int radeon_mode_dumb_mmap(struct drm_file *filp,
struct drm_device *dev,
uint32_t handle, uint64_t *offset_p)
{
struct drm_gem_object *gobj;
struct radeon_bo *robj;
gobj = drm_gem_object_lookup(dev, filp, handle);
if (gobj == NULL) {
return -ENOENT;
}
robj = gem_to_radeon_bo(gobj);
*offset_p = radeon_bo_mmap_offset(robj);
drm_gem_object_unreference_unlocked(gobj);
return 0;
}
int radeon_gem_mmap_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct drm_radeon_gem_mmap *args = data;
return radeon_mode_dumb_mmap(filp, dev, args->handle, &args->addr_ptr);
}
int radeon_gem_busy_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_gem_busy *args = data;
struct drm_gem_object *gobj;
struct radeon_bo *robj;
int r;
uint32_t cur_placement = 0;
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL) {
return -ENOENT;
}
robj = gem_to_radeon_bo(gobj);
r = radeon_bo_wait(robj, &cur_placement, true);
switch (cur_placement) {
case TTM_PL_VRAM:
args->domain = RADEON_GEM_DOMAIN_VRAM;
break;
case TTM_PL_TT:
args->domain = RADEON_GEM_DOMAIN_GTT;
break;
case TTM_PL_SYSTEM:
args->domain = RADEON_GEM_DOMAIN_CPU;
default:
break;
}
drm_gem_object_unreference_unlocked(gobj);
r = radeon_gem_handle_lockup(rdev, r);
return r;
}
int radeon_gem_wait_idle_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_gem_wait_idle *args = data;
struct drm_gem_object *gobj;
struct radeon_bo *robj;
int r;
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL) {
return -ENOENT;
}
robj = gem_to_radeon_bo(gobj);
r = radeon_bo_wait(robj, NULL, false);
if (rdev->asic->ioctl_wait_idle)
robj->rdev->asic->ioctl_wait_idle(rdev, robj);
drm_gem_object_unreference_unlocked(gobj);
r = radeon_gem_handle_lockup(rdev, r);
return r;
}
int radeon_gem_set_tiling_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct drm_radeon_gem_set_tiling *args = data;
struct drm_gem_object *gobj;
struct radeon_bo *robj;
int r = 0;
DRM_DEBUG("%d \n", args->handle);
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL)
return -ENOENT;
robj = gem_to_radeon_bo(gobj);
r = radeon_bo_set_tiling_flags(robj, args->tiling_flags, args->pitch);
drm_gem_object_unreference_unlocked(gobj);
return r;
}
int radeon_gem_get_tiling_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct drm_radeon_gem_get_tiling *args = data;
struct drm_gem_object *gobj;
struct radeon_bo *rbo;
int r = 0;
DRM_DEBUG("\n");
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL)
return -ENOENT;
rbo = gem_to_radeon_bo(gobj);
r = radeon_bo_reserve(rbo, false);
if (unlikely(r != 0))
goto out;
radeon_bo_get_tiling_flags(rbo, &args->tiling_flags, &args->pitch);
radeon_bo_unreserve(rbo);
out:
drm_gem_object_unreference_unlocked(gobj);
return r;
}
int radeon_gem_va_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
struct drm_radeon_gem_va *args = data;
struct drm_gem_object *gobj;
struct radeon_device *rdev = dev->dev_private;
struct radeon_fpriv *fpriv = filp->driver_priv;
struct radeon_bo *rbo;
struct radeon_bo_va *bo_va;
u32 invalid_flags;
int r = 0;
if (!rdev->vm_manager.enabled) {
args->operation = RADEON_VA_RESULT_ERROR;
return -ENOTTY;
}
if (args->vm_id) {
args->operation = RADEON_VA_RESULT_ERROR;
return -EINVAL;
}
if (args->offset < RADEON_VA_RESERVED_SIZE) {
dev_err(&dev->pdev->dev,
"offset 0x%lX is in reserved area 0x%X\n",
(unsigned long)args->offset,
RADEON_VA_RESERVED_SIZE);
args->operation = RADEON_VA_RESULT_ERROR;
return -EINVAL;
}
invalid_flags = RADEON_VM_PAGE_VALID | RADEON_VM_PAGE_SYSTEM;
if ((args->flags & invalid_flags)) {
dev_err(&dev->pdev->dev, "invalid flags 0x%08X vs 0x%08X\n",
args->flags, invalid_flags);
args->operation = RADEON_VA_RESULT_ERROR;
return -EINVAL;
}
if (!(args->flags & RADEON_VM_PAGE_SNOOPED)) {
dev_err(&dev->pdev->dev, "only supported snooped mapping for now\n");
args->operation = RADEON_VA_RESULT_ERROR;
return -EINVAL;
}
switch (args->operation) {
case RADEON_VA_MAP:
case RADEON_VA_UNMAP:
break;
default:
dev_err(&dev->pdev->dev, "unsupported operation %d\n",
args->operation);
args->operation = RADEON_VA_RESULT_ERROR;
return -EINVAL;
}
gobj = drm_gem_object_lookup(dev, filp, args->handle);
if (gobj == NULL) {
args->operation = RADEON_VA_RESULT_ERROR;
return -ENOENT;
}
rbo = gem_to_radeon_bo(gobj);
r = radeon_bo_reserve(rbo, false);
if (r) {
args->operation = RADEON_VA_RESULT_ERROR;
drm_gem_object_unreference_unlocked(gobj);
return r;
}
bo_va = radeon_vm_bo_find(&fpriv->vm, rbo);
if (!bo_va) {
args->operation = RADEON_VA_RESULT_ERROR;
drm_gem_object_unreference_unlocked(gobj);
return -ENOENT;
}
switch (args->operation) {
case RADEON_VA_MAP:
if (bo_va->soffset) {
args->operation = RADEON_VA_RESULT_VA_EXIST;
args->offset = bo_va->soffset;
goto out;
}
r = radeon_vm_bo_set_addr(rdev, bo_va, args->offset, args->flags);
break;
case RADEON_VA_UNMAP:
r = radeon_vm_bo_set_addr(rdev, bo_va, 0, 0);
break;
default:
break;
}
args->operation = RADEON_VA_RESULT_OK;
if (r) {
args->operation = RADEON_VA_RESULT_ERROR;
}
out:
radeon_bo_unreserve(rbo);
drm_gem_object_unreference_unlocked(gobj);
return r;
}
int radeon_mode_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_gem_object *gobj;
uint32_t handle;
int r;
args->pitch = radeon_align_pitch(rdev, args->width, args->bpp, 0) * ((args->bpp + 1) / 8);
args->size = args->pitch * args->height;
args->size = ALIGN(args->size, PAGE_SIZE);
r = radeon_gem_object_create(rdev, args->size, 0,
RADEON_GEM_DOMAIN_VRAM,
false, ttm_bo_type_device,
&gobj);
if (r)
return -ENOMEM;
r = drm_gem_handle_create(file_priv, gobj, &handle);
drm_gem_object_unreference_unlocked(gobj);
if (r) {
return r;
}
args->handle = handle;
return 0;
}
static int radeon_debugfs_gem_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_bo *rbo;
unsigned i = 0;
mutex_lock(&rdev->gem.mutex);
list_for_each_entry(rbo, &rdev->gem.objects, list) {
unsigned domain;
const char *placement;
domain = radeon_mem_type_to_domain(rbo->tbo.mem.mem_type);
switch (domain) {
case RADEON_GEM_DOMAIN_VRAM:
placement = "VRAM";
break;
case RADEON_GEM_DOMAIN_GTT:
placement = " GTT";
break;
case RADEON_GEM_DOMAIN_CPU:
default:
placement = " CPU";
break;
}
seq_printf(m, "bo[0x%08x] %8ldkB %8ldMB %s pid %8ld\n",
i, radeon_bo_size(rbo) >> 10, radeon_bo_size(rbo) >> 20,
placement, (unsigned long)rbo->pid);
i++;
}
mutex_unlock(&rdev->gem.mutex);
return 0;
}
int radeon_gem_debugfs_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, radeon_debugfs_gem_list, 1);
#endif
return 0;
}
