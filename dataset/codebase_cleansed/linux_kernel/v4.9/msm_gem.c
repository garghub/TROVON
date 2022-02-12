static dma_addr_t physaddr(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
struct msm_drm_private *priv = obj->dev->dev_private;
return (((dma_addr_t)msm_obj->vram_node->start) << PAGE_SHIFT) +
priv->vram.paddr;
}
static bool use_pages(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
return !msm_obj->vram_node;
}
static struct page **get_pages_vram(struct drm_gem_object *obj,
int npages)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
struct msm_drm_private *priv = obj->dev->dev_private;
dma_addr_t paddr;
struct page **p;
int ret, i;
p = drm_malloc_ab(npages, sizeof(struct page *));
if (!p)
return ERR_PTR(-ENOMEM);
ret = drm_mm_insert_node(&priv->vram.mm, msm_obj->vram_node,
npages, 0, DRM_MM_SEARCH_DEFAULT);
if (ret) {
drm_free_large(p);
return ERR_PTR(ret);
}
paddr = physaddr(obj);
for (i = 0; i < npages; i++) {
p[i] = phys_to_page(paddr);
paddr += PAGE_SIZE;
}
return p;
}
static struct page **get_pages(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
if (!msm_obj->pages) {
struct drm_device *dev = obj->dev;
struct page **p;
int npages = obj->size >> PAGE_SHIFT;
if (use_pages(obj))
p = drm_gem_get_pages(obj);
else
p = get_pages_vram(obj, npages);
if (IS_ERR(p)) {
dev_err(dev->dev, "could not get pages: %ld\n",
PTR_ERR(p));
return p;
}
msm_obj->sgt = drm_prime_pages_to_sg(p, npages);
if (IS_ERR(msm_obj->sgt)) {
dev_err(dev->dev, "failed to allocate sgt\n");
return ERR_CAST(msm_obj->sgt);
}
msm_obj->pages = p;
if (msm_obj->flags & (MSM_BO_WC|MSM_BO_UNCACHED))
dma_map_sg(dev->dev, msm_obj->sgt->sgl,
msm_obj->sgt->nents, DMA_BIDIRECTIONAL);
}
return msm_obj->pages;
}
static void put_pages(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
if (msm_obj->pages) {
if (msm_obj->flags & (MSM_BO_WC|MSM_BO_UNCACHED))
dma_unmap_sg(obj->dev->dev, msm_obj->sgt->sgl,
msm_obj->sgt->nents, DMA_BIDIRECTIONAL);
sg_free_table(msm_obj->sgt);
kfree(msm_obj->sgt);
if (use_pages(obj))
drm_gem_put_pages(obj, msm_obj->pages, true, false);
else {
drm_mm_remove_node(msm_obj->vram_node);
drm_free_large(msm_obj->pages);
}
msm_obj->pages = NULL;
}
}
struct page **msm_gem_get_pages(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct page **p;
mutex_lock(&dev->struct_mutex);
p = get_pages(obj);
mutex_unlock(&dev->struct_mutex);
return p;
}
void msm_gem_put_pages(struct drm_gem_object *obj)
{
}
int msm_gem_mmap_obj(struct drm_gem_object *obj,
struct vm_area_struct *vma)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_flags |= VM_MIXEDMAP;
if (msm_obj->flags & MSM_BO_WC) {
vma->vm_page_prot = pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
} else if (msm_obj->flags & MSM_BO_UNCACHED) {
vma->vm_page_prot = pgprot_noncached(vm_get_page_prot(vma->vm_flags));
} else {
fput(vma->vm_file);
get_file(obj->filp);
vma->vm_pgoff = 0;
vma->vm_file = obj->filp;
vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
}
return 0;
}
int msm_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret) {
DBG("mmap failed: %d", ret);
return ret;
}
return msm_gem_mmap_obj(vma->vm_private_data, vma);
}
int msm_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_gem_object *obj = vma->vm_private_data;
struct drm_device *dev = obj->dev;
struct msm_drm_private *priv = dev->dev_private;
struct page **pages;
unsigned long pfn;
pgoff_t pgoff;
int ret;
if (priv->struct_mutex_task == current)
return VM_FAULT_SIGBUS;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
goto out;
pages = get_pages(obj);
if (IS_ERR(pages)) {
ret = PTR_ERR(pages);
goto out_unlock;
}
pgoff = ((unsigned long)vmf->virtual_address -
vma->vm_start) >> PAGE_SHIFT;
pfn = page_to_pfn(pages[pgoff]);
VERB("Inserting %p pfn %lx, pa %lx", vmf->virtual_address,
pfn, pfn << PAGE_SHIFT);
ret = vm_insert_mixed(vma, (unsigned long)vmf->virtual_address,
__pfn_to_pfn_t(pfn, PFN_DEV));
out_unlock:
mutex_unlock(&dev->struct_mutex);
out:
switch (ret) {
case -EAGAIN:
case 0:
case -ERESTARTSYS:
case -EINTR:
case -EBUSY:
return VM_FAULT_NOPAGE;
case -ENOMEM:
return VM_FAULT_OOM;
default:
return VM_FAULT_SIGBUS;
}
}
static uint64_t mmap_offset(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
ret = drm_gem_create_mmap_offset(obj);
if (ret) {
dev_err(dev->dev, "could not allocate mmap offset\n");
return 0;
}
return drm_vma_node_offset_addr(&obj->vma_node);
}
uint64_t msm_gem_mmap_offset(struct drm_gem_object *obj)
{
uint64_t offset;
mutex_lock(&obj->dev->struct_mutex);
offset = mmap_offset(obj);
mutex_unlock(&obj->dev->struct_mutex);
return offset;
}
static void
put_iova(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct msm_drm_private *priv = obj->dev->dev_private;
struct msm_gem_object *msm_obj = to_msm_bo(obj);
int id;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
for (id = 0; id < ARRAY_SIZE(msm_obj->domain); id++) {
struct msm_mmu *mmu = priv->mmus[id];
if (mmu && msm_obj->domain[id].iova) {
uint32_t offset = msm_obj->domain[id].iova;
mmu->funcs->unmap(mmu, offset, msm_obj->sgt, obj->size);
msm_obj->domain[id].iova = 0;
}
}
}
int msm_gem_get_iova_locked(struct drm_gem_object *obj, int id,
uint32_t *iova)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
int ret = 0;
if (!msm_obj->domain[id].iova) {
struct msm_drm_private *priv = obj->dev->dev_private;
struct page **pages = get_pages(obj);
if (IS_ERR(pages))
return PTR_ERR(pages);
if (iommu_present(&platform_bus_type)) {
struct msm_mmu *mmu = priv->mmus[id];
uint32_t offset;
if (WARN_ON(!mmu))
return -EINVAL;
offset = (uint32_t)mmap_offset(obj);
ret = mmu->funcs->map(mmu, offset, msm_obj->sgt,
obj->size, IOMMU_READ | IOMMU_WRITE);
msm_obj->domain[id].iova = offset;
} else {
msm_obj->domain[id].iova = physaddr(obj);
}
}
if (!ret)
*iova = msm_obj->domain[id].iova;
return ret;
}
int msm_gem_get_iova(struct drm_gem_object *obj, int id, uint32_t *iova)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
int ret;
if (msm_obj->domain[id].iova) {
*iova = msm_obj->domain[id].iova;
return 0;
}
mutex_lock(&obj->dev->struct_mutex);
ret = msm_gem_get_iova_locked(obj, id, iova);
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
uint32_t msm_gem_iova(struct drm_gem_object *obj, int id)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!msm_obj->domain[id].iova);
return msm_obj->domain[id].iova;
}
void msm_gem_put_iova(struct drm_gem_object *obj, int id)
{
}
int msm_gem_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
args->pitch = align_pitch(args->width, args->bpp);
args->size = PAGE_ALIGN(args->pitch * args->height);
return msm_gem_new_handle(dev, file, args->size,
MSM_BO_SCANOUT | MSM_BO_WC, &args->handle);
}
int msm_gem_dumb_map_offset(struct drm_file *file, struct drm_device *dev,
uint32_t handle, uint64_t *offset)
{
struct drm_gem_object *obj;
int ret = 0;
obj = drm_gem_object_lookup(file, handle);
if (obj == NULL) {
ret = -ENOENT;
goto fail;
}
*offset = msm_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
fail:
return ret;
}
void *msm_gem_get_vaddr_locked(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&obj->dev->struct_mutex));
if (!msm_obj->vaddr) {
struct page **pages = get_pages(obj);
if (IS_ERR(pages))
return ERR_CAST(pages);
msm_obj->vaddr = vmap(pages, obj->size >> PAGE_SHIFT,
VM_MAP, pgprot_writecombine(PAGE_KERNEL));
if (msm_obj->vaddr == NULL)
return ERR_PTR(-ENOMEM);
}
msm_obj->vmap_count++;
return msm_obj->vaddr;
}
void *msm_gem_get_vaddr(struct drm_gem_object *obj)
{
void *ret;
mutex_lock(&obj->dev->struct_mutex);
ret = msm_gem_get_vaddr_locked(obj);
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
void msm_gem_put_vaddr_locked(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&obj->dev->struct_mutex));
WARN_ON(msm_obj->vmap_count < 1);
msm_obj->vmap_count--;
}
void msm_gem_put_vaddr(struct drm_gem_object *obj)
{
mutex_lock(&obj->dev->struct_mutex);
msm_gem_put_vaddr_locked(obj);
mutex_unlock(&obj->dev->struct_mutex);
}
int msm_gem_madvise(struct drm_gem_object *obj, unsigned madv)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&obj->dev->struct_mutex));
if (msm_obj->madv != __MSM_MADV_PURGED)
msm_obj->madv = madv;
return (msm_obj->madv != __MSM_MADV_PURGED);
}
void msm_gem_purge(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
WARN_ON(!is_purgeable(msm_obj));
WARN_ON(obj->import_attach);
put_iova(obj);
msm_gem_vunmap(obj);
put_pages(obj);
msm_obj->madv = __MSM_MADV_PURGED;
drm_vma_node_unmap(&obj->vma_node, dev->anon_inode->i_mapping);
drm_gem_free_mmap_offset(obj);
shmem_truncate_range(file_inode(obj->filp), 0, (loff_t)-1);
invalidate_mapping_pages(file_inode(obj->filp)->i_mapping,
0, (loff_t)-1);
}
void msm_gem_vunmap(struct drm_gem_object *obj)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
if (!msm_obj->vaddr || WARN_ON(!is_vunmapable(msm_obj)))
return;
vunmap(msm_obj->vaddr);
msm_obj->vaddr = NULL;
}
int msm_gem_sync_object(struct drm_gem_object *obj,
struct msm_fence_context *fctx, bool exclusive)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
struct reservation_object_list *fobj;
struct fence *fence;
int i, ret;
if (!exclusive) {
ret = reservation_object_reserve_shared(msm_obj->resv);
if (ret)
return ret;
}
fobj = reservation_object_get_list(msm_obj->resv);
if (!fobj || (fobj->shared_count == 0)) {
fence = reservation_object_get_excl(msm_obj->resv);
if (fence && (fence->context != fctx->context)) {
ret = fence_wait(fence, true);
if (ret)
return ret;
}
}
if (!exclusive || !fobj)
return 0;
for (i = 0; i < fobj->shared_count; i++) {
fence = rcu_dereference_protected(fobj->shared[i],
reservation_object_held(msm_obj->resv));
if (fence->context != fctx->context) {
ret = fence_wait(fence, true);
if (ret)
return ret;
}
}
return 0;
}
void msm_gem_move_to_active(struct drm_gem_object *obj,
struct msm_gpu *gpu, bool exclusive, struct fence *fence)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(msm_obj->madv != MSM_MADV_WILLNEED);
msm_obj->gpu = gpu;
if (exclusive)
reservation_object_add_excl_fence(msm_obj->resv, fence);
else
reservation_object_add_shared_fence(msm_obj->resv, fence);
list_del_init(&msm_obj->mm_list);
list_add_tail(&msm_obj->mm_list, &gpu->active_list);
}
void msm_gem_move_to_inactive(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
msm_obj->gpu = NULL;
list_del_init(&msm_obj->mm_list);
list_add_tail(&msm_obj->mm_list, &priv->inactive_list);
}
int msm_gem_cpu_prep(struct drm_gem_object *obj, uint32_t op, ktime_t *timeout)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
bool write = !!(op & MSM_PREP_WRITE);
unsigned long remain =
op & MSM_PREP_NOSYNC ? 0 : timeout_to_jiffies(timeout);
long ret;
ret = reservation_object_wait_timeout_rcu(msm_obj->resv, write,
true, remain);
if (ret == 0)
return remain == 0 ? -EBUSY : -ETIMEDOUT;
else if (ret < 0)
return ret;
return 0;
}
int msm_gem_cpu_fini(struct drm_gem_object *obj)
{
return 0;
}
static void describe_fence(struct fence *fence, const char *type,
struct seq_file *m)
{
if (!fence_is_signaled(fence))
seq_printf(m, "\t%9s: %s %s seq %u\n", type,
fence->ops->get_driver_name(fence),
fence->ops->get_timeline_name(fence),
fence->seqno);
}
void msm_gem_describe(struct drm_gem_object *obj, struct seq_file *m)
{
struct msm_gem_object *msm_obj = to_msm_bo(obj);
struct reservation_object *robj = msm_obj->resv;
struct reservation_object_list *fobj;
struct fence *fence;
uint64_t off = drm_vma_node_start(&obj->vma_node);
const char *madv;
WARN_ON(!mutex_is_locked(&obj->dev->struct_mutex));
switch (msm_obj->madv) {
case __MSM_MADV_PURGED:
madv = " purged";
break;
case MSM_MADV_DONTNEED:
madv = " purgeable";
break;
case MSM_MADV_WILLNEED:
default:
madv = "";
break;
}
seq_printf(m, "%08x: %c %2d (%2d) %08llx %p %zu%s\n",
msm_obj->flags, is_active(msm_obj) ? 'A' : 'I',
obj->name, obj->refcount.refcount.counter,
off, msm_obj->vaddr, obj->size, madv);
rcu_read_lock();
fobj = rcu_dereference(robj->fence);
if (fobj) {
unsigned int i, shared_count = fobj->shared_count;
for (i = 0; i < shared_count; i++) {
fence = rcu_dereference(fobj->shared[i]);
describe_fence(fence, "Shared", m);
}
}
fence = rcu_dereference(robj->fence_excl);
if (fence)
describe_fence(fence, "Exclusive", m);
rcu_read_unlock();
}
void msm_gem_describe_objects(struct list_head *list, struct seq_file *m)
{
struct msm_gem_object *msm_obj;
int count = 0;
size_t size = 0;
list_for_each_entry(msm_obj, list, mm_list) {
struct drm_gem_object *obj = &msm_obj->base;
seq_printf(m, " ");
msm_gem_describe(obj, m);
count++;
size += obj->size;
}
seq_printf(m, "Total %d objects, %zu bytes\n", count, size);
}
void msm_gem_free_object(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct msm_gem_object *msm_obj = to_msm_bo(obj);
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
WARN_ON(is_active(msm_obj));
list_del(&msm_obj->mm_list);
put_iova(obj);
if (obj->import_attach) {
if (msm_obj->vaddr)
dma_buf_vunmap(obj->import_attach->dmabuf, msm_obj->vaddr);
if (msm_obj->pages)
drm_free_large(msm_obj->pages);
drm_prime_gem_destroy(obj, msm_obj->sgt);
} else {
msm_gem_vunmap(obj);
put_pages(obj);
}
if (msm_obj->resv == &msm_obj->_resv)
reservation_object_fini(msm_obj->resv);
drm_gem_object_release(obj);
kfree(msm_obj);
}
int msm_gem_new_handle(struct drm_device *dev, struct drm_file *file,
uint32_t size, uint32_t flags, uint32_t *handle)
{
struct drm_gem_object *obj;
int ret;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
obj = msm_gem_new(dev, size, flags);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(obj))
return PTR_ERR(obj);
ret = drm_gem_handle_create(file, obj, handle);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_gem_new_impl(struct drm_device *dev,
uint32_t size, uint32_t flags,
struct reservation_object *resv,
struct drm_gem_object **obj)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_gem_object *msm_obj;
unsigned sz;
bool use_vram = false;
switch (flags & MSM_BO_CACHE_MASK) {
case MSM_BO_UNCACHED:
case MSM_BO_CACHED:
case MSM_BO_WC:
break;
default:
dev_err(dev->dev, "invalid cache flag: %x\n",
(flags & MSM_BO_CACHE_MASK));
return -EINVAL;
}
if (!iommu_present(&platform_bus_type))
use_vram = true;
else if ((flags & MSM_BO_STOLEN) && priv->vram.size)
use_vram = true;
if (WARN_ON(use_vram && !priv->vram.size))
return -EINVAL;
sz = sizeof(*msm_obj);
if (use_vram)
sz += sizeof(struct drm_mm_node);
msm_obj = kzalloc(sz, GFP_KERNEL);
if (!msm_obj)
return -ENOMEM;
if (use_vram)
msm_obj->vram_node = (void *)&msm_obj[1];
msm_obj->flags = flags;
msm_obj->madv = MSM_MADV_WILLNEED;
if (resv) {
msm_obj->resv = resv;
} else {
msm_obj->resv = &msm_obj->_resv;
reservation_object_init(msm_obj->resv);
}
INIT_LIST_HEAD(&msm_obj->submit_entry);
list_add_tail(&msm_obj->mm_list, &priv->inactive_list);
*obj = &msm_obj->base;
return 0;
}
struct drm_gem_object *msm_gem_new(struct drm_device *dev,
uint32_t size, uint32_t flags)
{
struct drm_gem_object *obj = NULL;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
size = PAGE_ALIGN(size);
ret = msm_gem_new_impl(dev, size, flags, NULL, &obj);
if (ret)
goto fail;
if (use_pages(obj)) {
ret = drm_gem_object_init(dev, obj, size);
if (ret)
goto fail;
} else {
drm_gem_private_object_init(dev, obj, size);
}
return obj;
fail:
drm_gem_object_unreference(obj);
return ERR_PTR(ret);
}
struct drm_gem_object *msm_gem_import(struct drm_device *dev,
struct dma_buf *dmabuf, struct sg_table *sgt)
{
struct msm_gem_object *msm_obj;
struct drm_gem_object *obj;
uint32_t size;
int ret, npages;
if (!iommu_present(&platform_bus_type)) {
dev_err(dev->dev, "cannot import without IOMMU\n");
return ERR_PTR(-EINVAL);
}
size = PAGE_ALIGN(dmabuf->size);
ret = msm_gem_new_impl(dev, size, MSM_BO_WC, dmabuf->resv, &obj);
if (ret)
goto fail;
drm_gem_private_object_init(dev, obj, size);
npages = size / PAGE_SIZE;
msm_obj = to_msm_bo(obj);
msm_obj->sgt = sgt;
msm_obj->pages = drm_malloc_ab(npages, sizeof(struct page *));
if (!msm_obj->pages) {
ret = -ENOMEM;
goto fail;
}
ret = drm_prime_sg_to_page_addr_arrays(sgt, msm_obj->pages, NULL, npages);
if (ret)
goto fail;
return obj;
fail:
drm_gem_object_unreference_unlocked(obj);
return ERR_PTR(ret);
}
