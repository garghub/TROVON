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
static int check_gem_flags(unsigned int flags)
{
if (flags & ~(EXYNOS_BO_MASK)) {
DRM_ERROR("invalid flags.\n");
return -EINVAL;
}
return 0;
}
static void update_vm_cache_attr(struct exynos_drm_gem_obj *obj,
struct vm_area_struct *vma)
{
DRM_DEBUG_KMS("flags = 0x%x\n", obj->flags);
if (obj->flags & EXYNOS_BO_CACHABLE)
vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
else if (obj->flags & EXYNOS_BO_WC)
vma->vm_page_prot =
pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
else
vma->vm_page_prot =
pgprot_noncached(vm_get_page_prot(vma->vm_flags));
}
static unsigned long roundup_gem_size(unsigned long size, unsigned int flags)
{
return roundup(size, PAGE_SIZE);
}
static int exynos_drm_gem_map_buf(struct drm_gem_object *obj,
struct vm_area_struct *vma,
unsigned long f_vaddr,
pgoff_t page_offset)
{
struct exynos_drm_gem_obj *exynos_gem_obj = to_exynos_gem_obj(obj);
struct exynos_drm_gem_buf *buf = exynos_gem_obj->buffer;
struct scatterlist *sgl;
unsigned long pfn;
int i;
if (!buf->sgt)
return -EINTR;
if (page_offset >= (buf->size >> PAGE_SHIFT)) {
DRM_ERROR("invalid page offset\n");
return -EINVAL;
}
sgl = buf->sgt->sgl;
for_each_sg(buf->sgt->sgl, sgl, buf->sgt->nents, i) {
if (page_offset < (sgl->length >> PAGE_SHIFT))
break;
page_offset -= (sgl->length >> PAGE_SHIFT);
}
pfn = __phys_to_pfn(sg_phys(sgl)) + page_offset;
return vm_insert_mixed(vma, f_vaddr, pfn);
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
struct exynos_drm_gem_buf *buf;
DRM_DEBUG_KMS("%s\n", __FILE__);
obj = &exynos_gem_obj->base;
buf = exynos_gem_obj->buffer;
DRM_DEBUG_KMS("handle count = %d\n", atomic_read(&obj->handle_count));
if (obj->import_attach)
goto out;
exynos_drm_free_buf(obj->dev, exynos_gem_obj->flags, buf);
out:
exynos_drm_fini_buf(obj->dev, buf);
exynos_gem_obj->buffer = NULL;
if (obj->map_list.map)
drm_gem_free_mmap_offset(obj);
drm_gem_object_release(obj);
kfree(exynos_gem_obj);
exynos_gem_obj = NULL;
}
struct exynos_drm_gem_obj *exynos_drm_gem_init(struct drm_device *dev,
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
exynos_gem_obj->size = size;
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
unsigned int flags,
unsigned long size)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct exynos_drm_gem_buf *buf;
int ret;
if (!size) {
DRM_ERROR("invalid size.\n");
return ERR_PTR(-EINVAL);
}
size = roundup_gem_size(size, flags);
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = check_gem_flags(flags);
if (ret)
return ERR_PTR(ret);
buf = exynos_drm_init_buf(dev, size);
if (!buf)
return ERR_PTR(-ENOMEM);
exynos_gem_obj = exynos_drm_gem_init(dev, size);
if (!exynos_gem_obj) {
ret = -ENOMEM;
goto err_fini_buf;
}
exynos_gem_obj->buffer = buf;
exynos_gem_obj->flags = flags;
ret = exynos_drm_alloc_buf(dev, buf, flags);
if (ret < 0) {
drm_gem_object_release(&exynos_gem_obj->base);
goto err_fini_buf;
}
return exynos_gem_obj;
err_fini_buf:
exynos_drm_fini_buf(dev, buf);
return ERR_PTR(ret);
}
int exynos_drm_gem_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_exynos_gem_create *args = data;
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_gem_obj = exynos_drm_gem_create(dev, args->flags, args->size);
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
dma_addr_t *exynos_drm_gem_get_dma_addr(struct drm_device *dev,
unsigned int gem_handle,
struct drm_file *filp)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_gem_object *obj;
obj = drm_gem_object_lookup(dev, filp, gem_handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
return ERR_PTR(-EINVAL);
}
exynos_gem_obj = to_exynos_gem_obj(obj);
return &exynos_gem_obj->buffer->dma_addr;
}
void exynos_drm_gem_put_dma_addr(struct drm_device *dev,
unsigned int gem_handle,
struct drm_file *filp)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_gem_object *obj;
obj = drm_gem_object_lookup(dev, filp, gem_handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
return;
}
exynos_gem_obj = to_exynos_gem_obj(obj);
drm_gem_object_unreference_unlocked(obj);
drm_gem_object_unreference_unlocked(obj);
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
static struct drm_file *exynos_drm_find_drm_file(struct drm_device *drm_dev,
struct file *filp)
{
struct drm_file *file_priv;
mutex_lock(&drm_dev->struct_mutex);
list_for_each_entry(file_priv, &drm_dev->filelist, lhead) {
if (file_priv->filp == filp) {
mutex_unlock(&drm_dev->struct_mutex);
return file_priv;
}
}
mutex_unlock(&drm_dev->struct_mutex);
WARN_ON(1);
return ERR_PTR(-EFAULT);
}
static int exynos_drm_gem_mmap_buffer(struct file *filp,
struct vm_area_struct *vma)
{
struct drm_gem_object *obj = filp->private_data;
struct exynos_drm_gem_obj *exynos_gem_obj = to_exynos_gem_obj(obj);
struct drm_device *drm_dev = obj->dev;
struct exynos_drm_gem_buf *buffer;
struct drm_file *file_priv;
unsigned long vm_size;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_private_data = obj;
vma->vm_ops = drm_dev->driver->gem_vm_ops;
filp->f_op = fops_get(drm_dev->driver->fops);
file_priv = exynos_drm_find_drm_file(drm_dev, filp);
if (IS_ERR(file_priv))
return PTR_ERR(file_priv);
filp->private_data = file_priv;
update_vm_cache_attr(exynos_gem_obj, vma);
vm_size = vma->vm_end - vma->vm_start;
buffer = exynos_gem_obj->buffer;
if (vm_size > buffer->size)
return -EINVAL;
ret = dma_mmap_attrs(drm_dev->dev, vma, buffer->pages,
buffer->dma_addr, buffer->size,
&buffer->dma_attrs);
if (ret < 0) {
DRM_ERROR("failed to mmap.\n");
return ret;
}
drm_gem_object_reference(obj);
mutex_lock(&drm_dev->struct_mutex);
drm_vm_open_locked(drm_dev, vma);
mutex_unlock(&drm_dev->struct_mutex);
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
file_priv->filp->f_op = &exynos_drm_gem_fops;
file_priv->filp->private_data = obj;
addr = vm_mmap(file_priv->filp, 0, args->size,
PROT_READ | PROT_WRITE, MAP_SHARED, 0);
drm_gem_object_unreference_unlocked(obj);
if (IS_ERR((void *)addr)) {
file_priv->filp->private_data = file_priv;
return PTR_ERR((void *)addr);
}
args->mapped = addr;
DRM_DEBUG_KMS("mapped = 0x%lx\n", (unsigned long)args->mapped);
return 0;
}
int exynos_drm_gem_get_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{ struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_exynos_gem_info *args = data;
struct drm_gem_object *obj;
mutex_lock(&dev->struct_mutex);
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
exynos_gem_obj = to_exynos_gem_obj(obj);
args->flags = exynos_gem_obj->flags;
args->size = exynos_gem_obj->size;
drm_gem_object_unreference(obj);
mutex_unlock(&dev->struct_mutex);
return 0;
}
struct vm_area_struct *exynos_gem_get_vma(struct vm_area_struct *vma)
{
struct vm_area_struct *vma_copy;
vma_copy = kmalloc(sizeof(*vma_copy), GFP_KERNEL);
if (!vma_copy)
return NULL;
if (vma->vm_ops && vma->vm_ops->open)
vma->vm_ops->open(vma);
if (vma->vm_file)
get_file(vma->vm_file);
memcpy(vma_copy, vma, sizeof(*vma));
vma_copy->vm_mm = NULL;
vma_copy->vm_next = NULL;
vma_copy->vm_prev = NULL;
return vma_copy;
}
void exynos_gem_put_vma(struct vm_area_struct *vma)
{
if (!vma)
return;
if (vma->vm_ops && vma->vm_ops->close)
vma->vm_ops->close(vma);
if (vma->vm_file)
fput(vma->vm_file);
kfree(vma);
}
int exynos_gem_get_pages_from_userptr(unsigned long start,
unsigned int npages,
struct page **pages,
struct vm_area_struct *vma)
{
int get_npages;
if (vma_is_io(vma)) {
unsigned int i;
for (i = 0; i < npages; ++i, start += PAGE_SIZE) {
unsigned long pfn;
int ret = follow_pfn(vma, start, &pfn);
if (ret)
return ret;
pages[i] = pfn_to_page(pfn);
}
if (i != npages) {
DRM_ERROR("failed to get user_pages.\n");
return -EINVAL;
}
return 0;
}
get_npages = get_user_pages(current, current->mm, start,
npages, 1, 1, pages, NULL);
get_npages = max(get_npages, 0);
if (get_npages != npages) {
DRM_ERROR("failed to get user_pages.\n");
while (get_npages)
put_page(pages[--get_npages]);
return -EFAULT;
}
return 0;
}
void exynos_gem_put_pages_to_userptr(struct page **pages,
unsigned int npages,
struct vm_area_struct *vma)
{
if (!vma_is_io(vma)) {
unsigned int i;
for (i = 0; i < npages; i++) {
set_page_dirty_lock(pages[i]);
put_page(pages[i]);
}
}
}
int exynos_gem_map_sgt_with_dma(struct drm_device *drm_dev,
struct sg_table *sgt,
enum dma_data_direction dir)
{
int nents;
mutex_lock(&drm_dev->struct_mutex);
nents = dma_map_sg(drm_dev->dev, sgt->sgl, sgt->nents, dir);
if (!nents) {
DRM_ERROR("failed to map sgl with dma.\n");
mutex_unlock(&drm_dev->struct_mutex);
return nents;
}
mutex_unlock(&drm_dev->struct_mutex);
return 0;
}
void exynos_gem_unmap_sgt_from_dma(struct drm_device *drm_dev,
struct sg_table *sgt,
enum dma_data_direction dir)
{
dma_unmap_sg(drm_dev->dev, sgt->sgl, sgt->nents, dir);
}
int exynos_drm_gem_init_object(struct drm_gem_object *obj)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
void exynos_drm_gem_free_object(struct drm_gem_object *obj)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct exynos_drm_gem_buf *buf;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_gem_obj = to_exynos_gem_obj(obj);
buf = exynos_gem_obj->buffer;
if (obj->import_attach)
drm_prime_gem_destroy(obj, buf->sgt);
exynos_drm_gem_destroy(to_exynos_gem_obj(obj));
}
int exynos_drm_gem_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
args->pitch = args->width * ((args->bpp + 7) / 8);
args->size = args->pitch * args->height;
exynos_gem_obj = exynos_drm_gem_create(dev, args->flags, args->size);
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
if (!obj->map_list.map) {
ret = drm_gem_create_mmap_offset(obj);
if (ret)
goto out;
}
*offset = (u64)obj->map_list.hash.key << PAGE_SHIFT;
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
struct drm_device *dev = obj->dev;
unsigned long f_vaddr;
pgoff_t page_offset;
int ret;
page_offset = ((unsigned long)vmf->virtual_address -
vma->vm_start) >> PAGE_SHIFT;
f_vaddr = (unsigned long)vmf->virtual_address;
mutex_lock(&dev->struct_mutex);
ret = exynos_drm_gem_map_buf(obj, vma, f_vaddr, page_offset);
if (ret < 0)
DRM_ERROR("failed to map a buffer with user.\n");
mutex_unlock(&dev->struct_mutex);
return convert_to_vm_err_msg(ret);
}
int exynos_drm_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_gem_object *obj;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = drm_gem_mmap(filp, vma);
if (ret < 0) {
DRM_ERROR("failed to mmap.\n");
return ret;
}
obj = vma->vm_private_data;
exynos_gem_obj = to_exynos_gem_obj(obj);
ret = check_gem_flags(exynos_gem_obj->flags);
if (ret) {
drm_gem_vm_close(vma);
drm_gem_free_mmap_offset(obj);
return ret;
}
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_flags |= VM_MIXEDMAP;
update_vm_cache_attr(exynos_gem_obj, vma);
return ret;
}
