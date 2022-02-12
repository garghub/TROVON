static int ttm_bo_vm_fault_idle(struct ttm_buffer_object *bo,
struct vm_fault *vmf)
{
int ret = 0;
if (likely(!bo->moving))
goto out_unlock;
if (dma_fence_is_signaled(bo->moving))
goto out_clear;
if (vmf->flags & FAULT_FLAG_ALLOW_RETRY) {
ret = VM_FAULT_RETRY;
if (vmf->flags & FAULT_FLAG_RETRY_NOWAIT)
goto out_unlock;
ttm_bo_reference(bo);
up_read(&vmf->vma->vm_mm->mmap_sem);
(void) dma_fence_wait(bo->moving, true);
ttm_bo_unreserve(bo);
ttm_bo_unref(&bo);
goto out_unlock;
}
ret = dma_fence_wait(bo->moving, true);
if (unlikely(ret != 0)) {
ret = (ret != -ERESTARTSYS) ? VM_FAULT_SIGBUS :
VM_FAULT_NOPAGE;
goto out_unlock;
}
out_clear:
dma_fence_put(bo->moving);
bo->moving = NULL;
out_unlock:
return ret;
}
static int ttm_bo_vm_fault(struct vm_fault *vmf)
{
struct vm_area_struct *vma = vmf->vma;
struct ttm_buffer_object *bo = (struct ttm_buffer_object *)
vma->vm_private_data;
struct ttm_bo_device *bdev = bo->bdev;
unsigned long page_offset;
unsigned long page_last;
unsigned long pfn;
struct ttm_tt *ttm = NULL;
struct page *page;
int ret;
int i;
unsigned long address = vmf->address;
int retval = VM_FAULT_NOPAGE;
struct ttm_mem_type_manager *man =
&bdev->man[bo->mem.mem_type];
struct vm_area_struct cvma;
ret = ttm_bo_reserve(bo, true, true, NULL);
if (unlikely(ret != 0)) {
if (ret != -EBUSY)
return VM_FAULT_NOPAGE;
if (vmf->flags & FAULT_FLAG_ALLOW_RETRY) {
if (!(vmf->flags & FAULT_FLAG_RETRY_NOWAIT)) {
ttm_bo_reference(bo);
up_read(&vmf->vma->vm_mm->mmap_sem);
(void) ttm_bo_wait_unreserved(bo);
ttm_bo_unref(&bo);
}
return VM_FAULT_RETRY;
}
return VM_FAULT_NOPAGE;
}
if (bo->ttm && (bo->ttm->page_flags & TTM_PAGE_FLAG_SG)) {
retval = VM_FAULT_SIGBUS;
goto out_unlock;
}
if (bdev->driver->fault_reserve_notify) {
ret = bdev->driver->fault_reserve_notify(bo);
switch (ret) {
case 0:
break;
case -EBUSY:
case -ERESTARTSYS:
retval = VM_FAULT_NOPAGE;
goto out_unlock;
default:
retval = VM_FAULT_SIGBUS;
goto out_unlock;
}
}
ret = ttm_bo_vm_fault_idle(bo, vmf);
if (unlikely(ret != 0)) {
retval = ret;
if (retval == VM_FAULT_RETRY &&
!(vmf->flags & FAULT_FLAG_RETRY_NOWAIT)) {
return retval;
}
goto out_unlock;
}
ret = ttm_mem_io_lock(man, true);
if (unlikely(ret != 0)) {
retval = VM_FAULT_NOPAGE;
goto out_unlock;
}
ret = ttm_mem_io_reserve_vm(bo);
if (unlikely(ret != 0)) {
retval = VM_FAULT_SIGBUS;
goto out_io_unlock;
}
page_offset = ((address - vma->vm_start) >> PAGE_SHIFT) +
vma->vm_pgoff - drm_vma_node_start(&bo->vma_node);
page_last = vma_pages(vma) + vma->vm_pgoff -
drm_vma_node_start(&bo->vma_node);
if (unlikely(page_offset >= bo->num_pages)) {
retval = VM_FAULT_SIGBUS;
goto out_io_unlock;
}
cvma = *vma;
cvma.vm_page_prot = vm_get_page_prot(cvma.vm_flags);
if (bo->mem.bus.is_iomem) {
cvma.vm_page_prot = ttm_io_prot(bo->mem.placement,
cvma.vm_page_prot);
} else {
ttm = bo->ttm;
cvma.vm_page_prot = ttm_io_prot(bo->mem.placement,
cvma.vm_page_prot);
if (ttm->bdev->driver->ttm_tt_populate(ttm)) {
retval = VM_FAULT_OOM;
goto out_io_unlock;
}
}
for (i = 0; i < TTM_BO_VM_NUM_PREFAULT; ++i) {
if (bo->mem.bus.is_iomem) {
cvma.vm_page_prot = pgprot_decrypted(cvma.vm_page_prot);
pfn = bdev->driver->io_mem_pfn(bo, page_offset);
} else {
page = ttm->pages[page_offset];
if (unlikely(!page && i == 0)) {
retval = VM_FAULT_OOM;
goto out_io_unlock;
} else if (unlikely(!page)) {
break;
}
page->mapping = vma->vm_file->f_mapping;
page->index = drm_vma_node_start(&bo->vma_node) +
page_offset;
pfn = page_to_pfn(page);
}
if (vma->vm_flags & VM_MIXEDMAP)
ret = vm_insert_mixed(&cvma, address,
__pfn_to_pfn_t(pfn, PFN_DEV));
else
ret = vm_insert_pfn(&cvma, address, pfn);
if (unlikely((ret == -EBUSY) || (ret != 0 && i > 0)))
break;
else if (unlikely(ret != 0)) {
retval =
(ret == -ENOMEM) ? VM_FAULT_OOM : VM_FAULT_SIGBUS;
goto out_io_unlock;
}
address += PAGE_SIZE;
if (unlikely(++page_offset >= page_last))
break;
}
out_io_unlock:
ttm_mem_io_unlock(man);
out_unlock:
ttm_bo_unreserve(bo);
return retval;
}
static void ttm_bo_vm_open(struct vm_area_struct *vma)
{
struct ttm_buffer_object *bo =
(struct ttm_buffer_object *)vma->vm_private_data;
WARN_ON(bo->bdev->dev_mapping != vma->vm_file->f_mapping);
(void)ttm_bo_reference(bo);
}
static void ttm_bo_vm_close(struct vm_area_struct *vma)
{
struct ttm_buffer_object *bo = (struct ttm_buffer_object *)vma->vm_private_data;
ttm_bo_unref(&bo);
vma->vm_private_data = NULL;
}
static int ttm_bo_vm_access_kmap(struct ttm_buffer_object *bo,
unsigned long offset,
void *buf, int len, int write)
{
unsigned long page = offset >> PAGE_SHIFT;
unsigned long bytes_left = len;
int ret;
offset -= page << PAGE_SHIFT;
do {
unsigned long bytes = min(bytes_left, PAGE_SIZE - offset);
struct ttm_bo_kmap_obj map;
void *ptr;
bool is_iomem;
ret = ttm_bo_kmap(bo, page, 1, &map);
if (ret)
return ret;
ptr = (uint8_t *)ttm_kmap_obj_virtual(&map, &is_iomem) + offset;
WARN_ON_ONCE(is_iomem);
if (write)
memcpy(ptr, buf, bytes);
else
memcpy(buf, ptr, bytes);
ttm_bo_kunmap(&map);
page++;
bytes_left -= bytes;
offset = 0;
} while (bytes_left);
return len;
}
static int ttm_bo_vm_access(struct vm_area_struct *vma, unsigned long addr,
void *buf, int len, int write)
{
unsigned long offset = (addr) - vma->vm_start;
struct ttm_buffer_object *bo = vma->vm_private_data;
int ret;
if (len < 1 || (offset + len) >> PAGE_SHIFT > bo->num_pages)
return -EIO;
ret = ttm_bo_reserve(bo, true, false, NULL);
if (ret)
return ret;
switch (bo->mem.mem_type) {
case TTM_PL_SYSTEM:
if (unlikely(bo->ttm->page_flags & TTM_PAGE_FLAG_SWAPPED)) {
ret = ttm_tt_swapin(bo->ttm);
if (unlikely(ret != 0))
return ret;
}
case TTM_PL_TT:
ret = ttm_bo_vm_access_kmap(bo, offset, buf, len, write);
break;
default:
if (bo->bdev->driver->access_memory)
ret = bo->bdev->driver->access_memory(
bo, offset, buf, len, write);
else
ret = -EIO;
}
ttm_bo_unreserve(bo);
return ret;
}
static struct ttm_buffer_object *ttm_bo_vm_lookup(struct ttm_bo_device *bdev,
unsigned long offset,
unsigned long pages)
{
struct drm_vma_offset_node *node;
struct ttm_buffer_object *bo = NULL;
drm_vma_offset_lock_lookup(&bdev->vma_manager);
node = drm_vma_offset_lookup_locked(&bdev->vma_manager, offset, pages);
if (likely(node)) {
bo = container_of(node, struct ttm_buffer_object, vma_node);
if (!kref_get_unless_zero(&bo->kref))
bo = NULL;
}
drm_vma_offset_unlock_lookup(&bdev->vma_manager);
if (!bo)
pr_err("Could not find buffer object to map\n");
return bo;
}
unsigned long ttm_bo_default_io_mem_pfn(struct ttm_buffer_object *bo,
unsigned long page_offset)
{
return ((bo->mem.bus.base + bo->mem.bus.offset) >> PAGE_SHIFT)
+ page_offset;
}
int ttm_bo_mmap(struct file *filp, struct vm_area_struct *vma,
struct ttm_bo_device *bdev)
{
struct ttm_bo_driver *driver;
struct ttm_buffer_object *bo;
int ret;
bo = ttm_bo_vm_lookup(bdev, vma->vm_pgoff, vma_pages(vma));
if (unlikely(!bo))
return -EINVAL;
driver = bo->bdev->driver;
if (unlikely(!driver->verify_access)) {
ret = -EPERM;
goto out_unref;
}
ret = driver->verify_access(bo, filp);
if (unlikely(ret != 0))
goto out_unref;
vma->vm_ops = &ttm_bo_vm_ops;
vma->vm_private_data = bo;
vma->vm_flags |= VM_MIXEDMAP;
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
return 0;
out_unref:
ttm_bo_unref(&bo);
return ret;
}
int ttm_fbdev_mmap(struct vm_area_struct *vma, struct ttm_buffer_object *bo)
{
if (vma->vm_pgoff != 0)
return -EACCES;
vma->vm_ops = &ttm_bo_vm_ops;
vma->vm_private_data = ttm_bo_reference(bo);
vma->vm_flags |= VM_MIXEDMAP;
vma->vm_flags |= VM_IO | VM_DONTEXPAND;
return 0;
}
