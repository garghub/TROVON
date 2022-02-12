static int ttm_bo_vm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
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
unsigned long address = (unsigned long)vmf->virtual_address;
int retval = VM_FAULT_NOPAGE;
struct ttm_mem_type_manager *man =
&bdev->man[bo->mem.mem_type];
ret = ttm_bo_reserve(bo, true, true, false, 0);
if (unlikely(ret != 0)) {
if (ret == -EBUSY)
set_need_resched();
return VM_FAULT_NOPAGE;
}
if (bdev->driver->fault_reserve_notify) {
ret = bdev->driver->fault_reserve_notify(bo);
switch (ret) {
case 0:
break;
case -EBUSY:
set_need_resched();
case -ERESTARTSYS:
retval = VM_FAULT_NOPAGE;
goto out_unlock;
default:
retval = VM_FAULT_SIGBUS;
goto out_unlock;
}
}
spin_lock(&bdev->fence_lock);
if (test_bit(TTM_BO_PRIV_FLAG_MOVING, &bo->priv_flags)) {
ret = ttm_bo_wait(bo, false, true, false);
spin_unlock(&bdev->fence_lock);
if (unlikely(ret != 0)) {
retval = (ret != -ERESTARTSYS) ?
VM_FAULT_SIGBUS : VM_FAULT_NOPAGE;
goto out_unlock;
}
} else
spin_unlock(&bdev->fence_lock);
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
drm_vma_node_start(&bo->vma_node) - vma->vm_pgoff;
page_last = vma_pages(vma) +
drm_vma_node_start(&bo->vma_node) - vma->vm_pgoff;
if (unlikely(page_offset >= bo->num_pages)) {
retval = VM_FAULT_SIGBUS;
goto out_io_unlock;
}
if (bo->mem.bus.is_iomem) {
vma->vm_page_prot = ttm_io_prot(bo->mem.placement,
vma->vm_page_prot);
} else {
ttm = bo->ttm;
vma->vm_page_prot = (bo->mem.placement & TTM_PL_FLAG_CACHED) ?
vm_get_page_prot(vma->vm_flags) :
ttm_io_prot(bo->mem.placement, vma->vm_page_prot);
if (ttm->bdev->driver->ttm_tt_populate(ttm)) {
retval = VM_FAULT_OOM;
goto out_io_unlock;
}
}
for (i = 0; i < TTM_BO_VM_NUM_PREFAULT; ++i) {
if (bo->mem.bus.is_iomem)
pfn = ((bo->mem.bus.base + bo->mem.bus.offset) >> PAGE_SHIFT) + page_offset;
else {
page = ttm->pages[page_offset];
if (unlikely(!page && i == 0)) {
retval = VM_FAULT_OOM;
goto out_io_unlock;
} else if (unlikely(!page)) {
break;
}
pfn = page_to_pfn(page);
}
ret = vm_insert_mixed(vma, address, pfn);
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
(void)ttm_bo_reference(bo);
}
static void ttm_bo_vm_close(struct vm_area_struct *vma)
{
struct ttm_buffer_object *bo = (struct ttm_buffer_object *)vma->vm_private_data;
ttm_bo_unref(&bo);
vma->vm_private_data = NULL;
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
vma->vm_flags |= VM_IO | VM_MIXEDMAP | VM_DONTEXPAND | VM_DONTDUMP;
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
vma->vm_flags |= VM_IO | VM_MIXEDMAP | VM_DONTEXPAND;
return 0;
}
