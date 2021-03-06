static unsigned int convert_to_vm_err_msg(int msg)
{
unsigned int out_msg;
switch (msg) {
case 0:
case -ERESTARTSYS:
case -EINTR:
out_msg = VM_FAULT_NOPAGE;
break;
case -ENOMEM:
out_msg = VM_FAULT_OOM;
break;
default:
out_msg = VM_FAULT_SIGBUS;
break;
}
return out_msg;
}
static int exynos_drm_gem_handle_create(struct drm_gem_object *obj,
struct drm_file *file_priv,
unsigned int *handle)
{
int ret;
ret = drm_gem_handle_create(file_priv, obj, handle);
if (ret)
return ret;
DRM_DEBUG_KMS("gem handle = 0x%x\n", *handle);
drm_gem_object_unreference_unlocked(obj);
return 0;
}
void exynos_drm_gem_destroy(struct exynos_drm_gem_obj *exynos_gem_obj)
{
struct drm_gem_object *obj;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!exynos_gem_obj)
return;
obj = &exynos_gem_obj->base;
DRM_DEBUG_KMS("handle count = %d\n", atomic_read(&obj->handle_count));
exynos_drm_buf_destroy(obj->dev, exynos_gem_obj->buffer);
if (obj->map_list.map)
drm_gem_free_mmap_offset(obj);
drm_gem_object_release(obj);
kfree(exynos_gem_obj);
}
static struct exynos_drm_gem_obj *exynos_drm_gem_init(struct drm_device *dev,
unsigned long size)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_gem_object *obj;
int ret;
exynos_gem_obj = kzalloc(sizeof(*exynos_gem_obj), GFP_KERNEL);
if (!exynos_gem_obj) {
DRM_ERROR("failed to allocate exynos gem object\n");
return NULL;
}
obj = &exynos_gem_obj->base;
ret = drm_gem_object_init(dev, obj, size);
if (ret < 0) {
DRM_ERROR("failed to initialize gem object\n");
kfree(exynos_gem_obj);
return NULL;
}
DRM_DEBUG_KMS("created file object = 0x%x\n", (unsigned int)obj->filp);
return exynos_gem_obj;
}
struct exynos_drm_gem_obj *exynos_drm_gem_create(struct drm_device *dev,
unsigned long size)
{
struct exynos_drm_gem_buf *buffer;
struct exynos_drm_gem_obj *exynos_gem_obj;
size = roundup(size, PAGE_SIZE);
DRM_DEBUG_KMS("%s: size = 0x%lx\n", __FILE__, size);
buffer = exynos_drm_buf_create(dev, size);
if (!buffer)
return ERR_PTR(-ENOMEM);
exynos_gem_obj = exynos_drm_gem_init(dev, size);
if (!exynos_gem_obj) {
exynos_drm_buf_destroy(dev, buffer);
return ERR_PTR(-ENOMEM);
}
exynos_gem_obj->buffer = buffer;
return exynos_gem_obj;
}
int exynos_drm_gem_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_exynos_gem_create *args = data;
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_gem_obj = exynos_drm_gem_create(dev, args->size);
if (IS_ERR(exynos_gem_obj))
return PTR_ERR(exynos_gem_obj);
ret = exynos_drm_gem_handle_create(&exynos_gem_obj->base, file_priv,
&args->handle);
if (ret) {
exynos_drm_gem_destroy(exynos_gem_obj);
return ret;
}
return 0;
}
int exynos_drm_gem_map_offset_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_exynos_gem_map_off *args = data;
DRM_DEBUG_KMS("%s\n", __FILE__);
DRM_DEBUG_KMS("handle = 0x%x, offset = 0x%lx\n",
args->handle, (unsigned long)args->offset);
if (!(dev->driver->driver_features & DRIVER_GEM)) {
DRM_ERROR("does not support GEM.\n");
return -ENODEV;
}
return exynos_drm_gem_dumb_map_offset(file_priv, dev, args->handle,
&args->offset);
}
static int exynos_drm_gem_mmap_buffer(struct file *filp,
struct vm_area_struct *vma)
{
struct drm_gem_object *obj = filp->private_data;
struct exynos_drm_gem_obj *exynos_gem_obj = to_exynos_gem_obj(obj);
struct exynos_drm_gem_buf *buffer;
unsigned long pfn, vm_size;
DRM_DEBUG_KMS("%s\n", __FILE__);
vma->vm_flags |= (VM_IO | VM_RESERVED);
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
vma->vm_file = filp;
vm_size = vma->vm_end - vma->vm_start;
buffer = exynos_gem_obj->buffer;
if (vm_size > buffer->size)
return -EINVAL;
pfn = ((unsigned long)exynos_gem_obj->buffer->dma_addr) >> PAGE_SHIFT;
DRM_DEBUG_KMS("pfn = 0x%lx\n", pfn);
if (remap_pfn_range(vma, vma->vm_start, pfn, vm_size,
vma->vm_page_prot)) {
DRM_ERROR("failed to remap pfn range.\n");
return -EAGAIN;
}
return 0;
}
int exynos_drm_gem_mmap_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_exynos_gem_mmap *args = data;
struct drm_gem_object *obj;
unsigned int addr;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!(dev->driver->driver_features & DRIVER_GEM)) {
DRM_ERROR("does not support GEM.\n");
return -ENODEV;
}
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
return -EINVAL;
}
obj->filp->f_op = &exynos_drm_gem_fops;
obj->filp->private_data = obj;
down_write(&current->mm->mmap_sem);
addr = do_mmap(obj->filp, 0, args->size,
PROT_READ | PROT_WRITE, MAP_SHARED, 0);
up_write(&current->mm->mmap_sem);
drm_gem_object_unreference_unlocked(obj);
if (IS_ERR((void *)addr))
return PTR_ERR((void *)addr);
args->mapped = addr;
DRM_DEBUG_KMS("mapped = 0x%lx\n", (unsigned long)args->mapped);
return 0;
}
int exynos_drm_gem_init_object(struct drm_gem_object *obj)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
void exynos_drm_gem_free_object(struct drm_gem_object *obj)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_gem_destroy(to_exynos_gem_obj(obj));
}
int exynos_drm_gem_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
args->pitch = args->width * args->bpp >> 3;
args->size = args->pitch * args->height;
exynos_gem_obj = exynos_drm_gem_create(dev, args->size);
if (IS_ERR(exynos_gem_obj))
return PTR_ERR(exynos_gem_obj);
ret = exynos_drm_gem_handle_create(&exynos_gem_obj->base, file_priv,
&args->handle);
if (ret) {
exynos_drm_gem_destroy(exynos_gem_obj);
return ret;
}
return 0;
}
int exynos_drm_gem_dumb_map_offset(struct drm_file *file_priv,
struct drm_device *dev, uint32_t handle,
uint64_t *offset)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_gem_object *obj;
int ret = 0;
DRM_DEBUG_KMS("%s\n", __FILE__);
mutex_lock(&dev->struct_mutex);
obj = drm_gem_object_lookup(dev, file_priv, handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
ret = -EINVAL;
goto unlock;
}
exynos_gem_obj = to_exynos_gem_obj(obj);
if (!exynos_gem_obj->base.map_list.map) {
ret = drm_gem_create_mmap_offset(&exynos_gem_obj->base);
if (ret)
goto out;
}
*offset = (u64)exynos_gem_obj->base.map_list.hash.key << PAGE_SHIFT;
DRM_DEBUG_KMS("offset = 0x%lx\n", (unsigned long)*offset);
out:
drm_gem_object_unreference(obj);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int exynos_drm_gem_dumb_destroy(struct drm_file *file_priv,
struct drm_device *dev,
unsigned int handle)
{
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = drm_gem_handle_delete(file_priv, handle);
if (ret < 0) {
DRM_ERROR("failed to delete drm_gem_handle.\n");
return ret;
}
return 0;
}
int exynos_drm_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_gem_object *obj = vma->vm_private_data;
struct exynos_drm_gem_obj *exynos_gem_obj = to_exynos_gem_obj(obj);
struct drm_device *dev = obj->dev;
unsigned long pfn;
pgoff_t page_offset;
int ret;
page_offset = ((unsigned long)vmf->virtual_address -
vma->vm_start) >> PAGE_SHIFT;
mutex_lock(&dev->struct_mutex);
pfn = (((unsigned long)exynos_gem_obj->buffer->dma_addr) >>
PAGE_SHIFT) + page_offset;
ret = vm_insert_mixed(vma, (unsigned long)vmf->virtual_address, pfn);
mutex_unlock(&dev->struct_mutex);
return convert_to_vm_err_msg(ret);
}
int exynos_drm_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = drm_gem_mmap(filp, vma);
if (ret < 0) {
DRM_ERROR("failed to mmap.\n");
return ret;
}
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_flags |= VM_MIXEDMAP;
return ret;
}
