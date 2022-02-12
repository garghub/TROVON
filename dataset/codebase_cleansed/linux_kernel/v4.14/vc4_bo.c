static bool is_user_label(int label)
{
return label >= VC4_BO_TYPE_COUNT;
}
static void vc4_bo_stats_dump(struct vc4_dev *vc4)
{
int i;
for (i = 0; i < vc4->num_labels; i++) {
if (!vc4->bo_labels[i].num_allocated)
continue;
DRM_INFO("%30s: %6dkb BOs (%d)\n",
vc4->bo_labels[i].name,
vc4->bo_labels[i].size_allocated / 1024,
vc4->bo_labels[i].num_allocated);
}
}
int vc4_bo_stats_debugfs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
mutex_lock(&vc4->bo_lock);
for (i = 0; i < vc4->num_labels; i++) {
if (!vc4->bo_labels[i].num_allocated)
continue;
seq_printf(m, "%30s: %6dkb BOs (%d)\n",
vc4->bo_labels[i].name,
vc4->bo_labels[i].size_allocated / 1024,
vc4->bo_labels[i].num_allocated);
}
mutex_unlock(&vc4->bo_lock);
return 0;
}
static int vc4_get_user_label(struct vc4_dev *vc4, const char *name)
{
int i;
int free_slot = -1;
for (i = 0; i < vc4->num_labels; i++) {
if (!vc4->bo_labels[i].name) {
free_slot = i;
} else if (strcmp(vc4->bo_labels[i].name, name) == 0) {
kfree(name);
return i;
}
}
if (free_slot != -1) {
WARN_ON(vc4->bo_labels[free_slot].num_allocated != 0);
vc4->bo_labels[free_slot].name = name;
return free_slot;
} else {
u32 new_label_count = vc4->num_labels + 1;
struct vc4_label *new_labels =
krealloc(vc4->bo_labels,
new_label_count * sizeof(*new_labels),
GFP_KERNEL);
if (!new_labels) {
kfree(name);
return -1;
}
free_slot = vc4->num_labels;
vc4->bo_labels = new_labels;
vc4->num_labels = new_label_count;
vc4->bo_labels[free_slot].name = name;
vc4->bo_labels[free_slot].num_allocated = 0;
vc4->bo_labels[free_slot].size_allocated = 0;
return free_slot;
}
}
static void vc4_bo_set_label(struct drm_gem_object *gem_obj, int label)
{
struct vc4_bo *bo = to_vc4_bo(gem_obj);
struct vc4_dev *vc4 = to_vc4_dev(gem_obj->dev);
lockdep_assert_held(&vc4->bo_lock);
if (label != -1) {
vc4->bo_labels[label].num_allocated++;
vc4->bo_labels[label].size_allocated += gem_obj->size;
}
vc4->bo_labels[bo->label].num_allocated--;
vc4->bo_labels[bo->label].size_allocated -= gem_obj->size;
if (vc4->bo_labels[bo->label].num_allocated == 0 &&
is_user_label(bo->label)) {
kfree(vc4->bo_labels[bo->label].name);
vc4->bo_labels[bo->label].name = NULL;
}
bo->label = label;
}
static uint32_t bo_page_index(size_t size)
{
return (size / PAGE_SIZE) - 1;
}
static void vc4_bo_destroy(struct vc4_bo *bo)
{
struct drm_gem_object *obj = &bo->base.base;
struct vc4_dev *vc4 = to_vc4_dev(obj->dev);
lockdep_assert_held(&vc4->bo_lock);
vc4_bo_set_label(obj, -1);
if (bo->validated_shader) {
kfree(bo->validated_shader->texture_samples);
kfree(bo->validated_shader);
bo->validated_shader = NULL;
}
reservation_object_fini(&bo->_resv);
drm_gem_cma_free_object(obj);
}
static void vc4_bo_remove_from_cache(struct vc4_bo *bo)
{
struct vc4_dev *vc4 = to_vc4_dev(bo->base.base.dev);
lockdep_assert_held(&vc4->bo_lock);
list_del(&bo->unref_head);
list_del(&bo->size_head);
}
static struct list_head *vc4_get_cache_list_for_size(struct drm_device *dev,
size_t size)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
uint32_t page_index = bo_page_index(size);
if (vc4->bo_cache.size_list_size <= page_index) {
uint32_t new_size = max(vc4->bo_cache.size_list_size * 2,
page_index + 1);
struct list_head *new_list;
uint32_t i;
new_list = kmalloc_array(new_size, sizeof(struct list_head),
GFP_KERNEL);
if (!new_list)
return NULL;
for (i = 0; i < vc4->bo_cache.size_list_size; i++) {
struct list_head *old_list =
&vc4->bo_cache.size_list[i];
if (list_empty(old_list))
INIT_LIST_HEAD(&new_list[i]);
else
list_replace(old_list, &new_list[i]);
}
for (i = vc4->bo_cache.size_list_size; i < new_size; i++)
INIT_LIST_HEAD(&new_list[i]);
kfree(vc4->bo_cache.size_list);
vc4->bo_cache.size_list = new_list;
vc4->bo_cache.size_list_size = new_size;
}
return &vc4->bo_cache.size_list[page_index];
}
static void vc4_bo_cache_purge(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
mutex_lock(&vc4->bo_lock);
while (!list_empty(&vc4->bo_cache.time_list)) {
struct vc4_bo *bo = list_last_entry(&vc4->bo_cache.time_list,
struct vc4_bo, unref_head);
vc4_bo_remove_from_cache(bo);
vc4_bo_destroy(bo);
}
mutex_unlock(&vc4->bo_lock);
}
static struct vc4_bo *vc4_bo_get_from_cache(struct drm_device *dev,
uint32_t size,
enum vc4_kernel_bo_type type)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
uint32_t page_index = bo_page_index(size);
struct vc4_bo *bo = NULL;
size = roundup(size, PAGE_SIZE);
mutex_lock(&vc4->bo_lock);
if (page_index >= vc4->bo_cache.size_list_size)
goto out;
if (list_empty(&vc4->bo_cache.size_list[page_index]))
goto out;
bo = list_first_entry(&vc4->bo_cache.size_list[page_index],
struct vc4_bo, size_head);
vc4_bo_remove_from_cache(bo);
kref_init(&bo->base.base.refcount);
out:
if (bo)
vc4_bo_set_label(&bo->base.base, type);
mutex_unlock(&vc4->bo_lock);
return bo;
}
struct drm_gem_object *vc4_create_object(struct drm_device *dev, size_t size)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_bo *bo;
bo = kzalloc(sizeof(*bo), GFP_KERNEL);
if (!bo)
return ERR_PTR(-ENOMEM);
mutex_lock(&vc4->bo_lock);
bo->label = VC4_BO_TYPE_KERNEL;
vc4->bo_labels[VC4_BO_TYPE_KERNEL].num_allocated++;
vc4->bo_labels[VC4_BO_TYPE_KERNEL].size_allocated += size;
mutex_unlock(&vc4->bo_lock);
bo->resv = &bo->_resv;
reservation_object_init(bo->resv);
return &bo->base.base;
}
struct vc4_bo *vc4_bo_create(struct drm_device *dev, size_t unaligned_size,
bool allow_unzeroed, enum vc4_kernel_bo_type type)
{
size_t size = roundup(unaligned_size, PAGE_SIZE);
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_gem_cma_object *cma_obj;
struct vc4_bo *bo;
if (size == 0)
return ERR_PTR(-EINVAL);
bo = vc4_bo_get_from_cache(dev, size, type);
if (bo) {
if (!allow_unzeroed)
memset(bo->base.vaddr, 0, bo->base.base.size);
return bo;
}
cma_obj = drm_gem_cma_create(dev, size);
if (IS_ERR(cma_obj)) {
vc4_bo_cache_purge(dev);
cma_obj = drm_gem_cma_create(dev, size);
if (IS_ERR(cma_obj)) {
DRM_ERROR("Failed to allocate from CMA:\n");
vc4_bo_stats_dump(vc4);
return ERR_PTR(-ENOMEM);
}
}
bo = to_vc4_bo(&cma_obj->base);
mutex_lock(&vc4->bo_lock);
vc4_bo_set_label(&cma_obj->base, type);
mutex_unlock(&vc4->bo_lock);
return bo;
}
int vc4_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
int min_pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
struct vc4_bo *bo = NULL;
int ret;
if (args->pitch < min_pitch)
args->pitch = min_pitch;
if (args->size < args->pitch * args->height)
args->size = args->pitch * args->height;
bo = vc4_bo_create(dev, args->size, false, VC4_BO_TYPE_DUMB);
if (IS_ERR(bo))
return PTR_ERR(bo);
ret = drm_gem_handle_create(file_priv, &bo->base.base, &args->handle);
drm_gem_object_put_unlocked(&bo->base.base);
return ret;
}
static void vc4_bo_cache_free_old(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
unsigned long expire_time = jiffies - msecs_to_jiffies(1000);
lockdep_assert_held(&vc4->bo_lock);
while (!list_empty(&vc4->bo_cache.time_list)) {
struct vc4_bo *bo = list_last_entry(&vc4->bo_cache.time_list,
struct vc4_bo, unref_head);
if (time_before(expire_time, bo->free_time)) {
mod_timer(&vc4->bo_cache.time_timer,
round_jiffies_up(jiffies +
msecs_to_jiffies(1000)));
return;
}
vc4_bo_remove_from_cache(bo);
vc4_bo_destroy(bo);
}
}
void vc4_free_object(struct drm_gem_object *gem_bo)
{
struct drm_device *dev = gem_bo->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_bo *bo = to_vc4_bo(gem_bo);
struct list_head *cache_list;
mutex_lock(&vc4->bo_lock);
if (gem_bo->import_attach) {
vc4_bo_destroy(bo);
goto out;
}
if (gem_bo->name) {
vc4_bo_destroy(bo);
goto out;
}
if (!bo->base.vaddr) {
vc4_bo_destroy(bo);
goto out;
}
cache_list = vc4_get_cache_list_for_size(dev, gem_bo->size);
if (!cache_list) {
vc4_bo_destroy(bo);
goto out;
}
if (bo->validated_shader) {
kfree(bo->validated_shader->texture_samples);
kfree(bo->validated_shader);
bo->validated_shader = NULL;
}
bo->t_format = false;
bo->free_time = jiffies;
list_add(&bo->size_head, cache_list);
list_add(&bo->unref_head, &vc4->bo_cache.time_list);
vc4_bo_set_label(&bo->base.base, VC4_BO_TYPE_KERNEL_CACHE);
vc4_bo_cache_free_old(dev);
out:
mutex_unlock(&vc4->bo_lock);
}
static void vc4_bo_cache_time_work(struct work_struct *work)
{
struct vc4_dev *vc4 =
container_of(work, struct vc4_dev, bo_cache.time_work);
struct drm_device *dev = vc4->dev;
mutex_lock(&vc4->bo_lock);
vc4_bo_cache_free_old(dev);
mutex_unlock(&vc4->bo_lock);
}
static void vc4_bo_cache_time_timer(unsigned long data)
{
struct drm_device *dev = (struct drm_device *)data;
struct vc4_dev *vc4 = to_vc4_dev(dev);
schedule_work(&vc4->bo_cache.time_work);
}
struct reservation_object *vc4_prime_res_obj(struct drm_gem_object *obj)
{
struct vc4_bo *bo = to_vc4_bo(obj);
return bo->resv;
}
struct dma_buf *
vc4_prime_export(struct drm_device *dev, struct drm_gem_object *obj, int flags)
{
struct vc4_bo *bo = to_vc4_bo(obj);
if (bo->validated_shader) {
DRM_DEBUG("Attempting to export shader BO\n");
return ERR_PTR(-EINVAL);
}
return drm_gem_prime_export(dev, obj, flags);
}
int vc4_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_gem_object *gem_obj;
struct vc4_bo *bo;
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret)
return ret;
gem_obj = vma->vm_private_data;
bo = to_vc4_bo(gem_obj);
if (bo->validated_shader && (vma->vm_flags & VM_WRITE)) {
DRM_DEBUG("mmaping of shader BOs for writing not allowed.\n");
return -EINVAL;
}
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_pgoff = 0;
ret = dma_mmap_wc(bo->base.base.dev->dev, vma, bo->base.vaddr,
bo->base.paddr, vma->vm_end - vma->vm_start);
if (ret)
drm_gem_vm_close(vma);
return ret;
}
int vc4_prime_mmap(struct drm_gem_object *obj, struct vm_area_struct *vma)
{
struct vc4_bo *bo = to_vc4_bo(obj);
if (bo->validated_shader && (vma->vm_flags & VM_WRITE)) {
DRM_DEBUG("mmaping of shader BOs for writing not allowed.\n");
return -EINVAL;
}
return drm_gem_cma_prime_mmap(obj, vma);
}
void *vc4_prime_vmap(struct drm_gem_object *obj)
{
struct vc4_bo *bo = to_vc4_bo(obj);
if (bo->validated_shader) {
DRM_DEBUG("mmaping of shader BOs not allowed.\n");
return ERR_PTR(-EINVAL);
}
return drm_gem_cma_prime_vmap(obj);
}
struct drm_gem_object *
vc4_prime_import_sg_table(struct drm_device *dev,
struct dma_buf_attachment *attach,
struct sg_table *sgt)
{
struct drm_gem_object *obj;
struct vc4_bo *bo;
obj = drm_gem_cma_prime_import_sg_table(dev, attach, sgt);
if (IS_ERR(obj))
return obj;
bo = to_vc4_bo(obj);
bo->resv = attach->dmabuf->resv;
return obj;
}
int vc4_create_bo_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vc4_create_bo *args = data;
struct vc4_bo *bo = NULL;
int ret;
bo = vc4_bo_create(dev, args->size, false, VC4_BO_TYPE_V3D);
if (IS_ERR(bo))
return PTR_ERR(bo);
ret = drm_gem_handle_create(file_priv, &bo->base.base, &args->handle);
drm_gem_object_put_unlocked(&bo->base.base);
return ret;
}
int vc4_mmap_bo_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vc4_mmap_bo *args = data;
struct drm_gem_object *gem_obj;
gem_obj = drm_gem_object_lookup(file_priv, args->handle);
if (!gem_obj) {
DRM_DEBUG("Failed to look up GEM BO %d\n", args->handle);
return -EINVAL;
}
args->offset = drm_vma_node_offset_addr(&gem_obj->vma_node);
drm_gem_object_put_unlocked(gem_obj);
return 0;
}
int
vc4_create_shader_bo_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vc4_create_shader_bo *args = data;
struct vc4_bo *bo = NULL;
int ret;
if (args->size == 0)
return -EINVAL;
if (args->size % sizeof(u64) != 0)
return -EINVAL;
if (args->flags != 0) {
DRM_INFO("Unknown flags set: 0x%08x\n", args->flags);
return -EINVAL;
}
if (args->pad != 0) {
DRM_INFO("Pad set: 0x%08x\n", args->pad);
return -EINVAL;
}
bo = vc4_bo_create(dev, args->size, true, VC4_BO_TYPE_V3D_SHADER);
if (IS_ERR(bo))
return PTR_ERR(bo);
if (copy_from_user(bo->base.vaddr,
(void __user *)(uintptr_t)args->data,
args->size)) {
ret = -EFAULT;
goto fail;
}
memset(bo->base.vaddr + args->size, 0,
bo->base.base.size - args->size);
bo->validated_shader = vc4_validate_shader(&bo->base);
if (!bo->validated_shader) {
ret = -EINVAL;
goto fail;
}
ret = drm_gem_handle_create(file_priv, &bo->base.base, &args->handle);
fail:
drm_gem_object_put_unlocked(&bo->base.base);
return ret;
}
int vc4_set_tiling_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vc4_set_tiling *args = data;
struct drm_gem_object *gem_obj;
struct vc4_bo *bo;
bool t_format;
if (args->flags != 0)
return -EINVAL;
switch (args->modifier) {
case DRM_FORMAT_MOD_NONE:
t_format = false;
break;
case DRM_FORMAT_MOD_BROADCOM_VC4_T_TILED:
t_format = true;
break;
default:
return -EINVAL;
}
gem_obj = drm_gem_object_lookup(file_priv, args->handle);
if (!gem_obj) {
DRM_DEBUG("Failed to look up GEM BO %d\n", args->handle);
return -ENOENT;
}
bo = to_vc4_bo(gem_obj);
bo->t_format = t_format;
drm_gem_object_put_unlocked(gem_obj);
return 0;
}
int vc4_get_tiling_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vc4_get_tiling *args = data;
struct drm_gem_object *gem_obj;
struct vc4_bo *bo;
if (args->flags != 0 || args->modifier != 0)
return -EINVAL;
gem_obj = drm_gem_object_lookup(file_priv, args->handle);
if (!gem_obj) {
DRM_DEBUG("Failed to look up GEM BO %d\n", args->handle);
return -ENOENT;
}
bo = to_vc4_bo(gem_obj);
if (bo->t_format)
args->modifier = DRM_FORMAT_MOD_BROADCOM_VC4_T_TILED;
else
args->modifier = DRM_FORMAT_MOD_NONE;
drm_gem_object_put_unlocked(gem_obj);
return 0;
}
int vc4_bo_cache_init(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
vc4->bo_labels = kcalloc(VC4_BO_TYPE_COUNT, sizeof(*vc4->bo_labels),
GFP_KERNEL);
if (!vc4->bo_labels)
return -ENOMEM;
vc4->num_labels = VC4_BO_TYPE_COUNT;
BUILD_BUG_ON(ARRAY_SIZE(bo_type_names) != VC4_BO_TYPE_COUNT);
for (i = 0; i < VC4_BO_TYPE_COUNT; i++)
vc4->bo_labels[i].name = bo_type_names[i];
mutex_init(&vc4->bo_lock);
INIT_LIST_HEAD(&vc4->bo_cache.time_list);
INIT_WORK(&vc4->bo_cache.time_work, vc4_bo_cache_time_work);
setup_timer(&vc4->bo_cache.time_timer,
vc4_bo_cache_time_timer,
(unsigned long)dev);
return 0;
}
void vc4_bo_cache_destroy(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
del_timer(&vc4->bo_cache.time_timer);
cancel_work_sync(&vc4->bo_cache.time_work);
vc4_bo_cache_purge(dev);
for (i = 0; i < vc4->num_labels; i++) {
if (vc4->bo_labels[i].num_allocated) {
DRM_ERROR("Destroying BO cache with %d %s "
"BOs still allocated\n",
vc4->bo_labels[i].num_allocated,
vc4->bo_labels[i].name);
}
if (is_user_label(i))
kfree(vc4->bo_labels[i].name);
}
kfree(vc4->bo_labels);
}
int vc4_label_bo_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_vc4_label_bo *args = data;
char *name;
struct drm_gem_object *gem_obj;
int ret = 0, label;
if (!args->len)
return -EINVAL;
name = strndup_user(u64_to_user_ptr(args->name), args->len + 1);
if (IS_ERR(name))
return PTR_ERR(name);
gem_obj = drm_gem_object_lookup(file_priv, args->handle);
if (!gem_obj) {
DRM_ERROR("Failed to look up GEM BO %d\n", args->handle);
kfree(name);
return -ENOENT;
}
mutex_lock(&vc4->bo_lock);
label = vc4_get_user_label(vc4, name);
if (label != -1)
vc4_bo_set_label(gem_obj, label);
else
ret = -ENOMEM;
mutex_unlock(&vc4->bo_lock);
drm_gem_object_put_unlocked(gem_obj);
return ret;
}
