static struct ttm_buffer_object *ttm_bo_vm_lookup_rb(struct ttm_bo_device *bdev,
unsigned long page_start,
unsigned long num_pages)
{
struct rb_node *cur = bdev->addr_space_rb.rb_node;
unsigned long cur_offset;
struct ttm_buffer_object *bo;
struct ttm_buffer_object *best_bo = NULL;
while (likely(cur != NULL)) {
bo = rb_entry(cur, struct ttm_buffer_object, vm_rb);
cur_offset = bo->vm_node->start;
if (page_start >= cur_offset) {
cur = cur->rb_right;
best_bo = bo;
if (page_start == cur_offset)
break;
} else
cur = cur->rb_left;
}
if (unlikely(best_bo == NULL))
return NULL;
if (unlikely((best_bo->vm_node->start + best_bo->num_pages) <
(page_start + num_pages)))
return NULL;
return best_bo;
}
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
bo->vm_node->start - vma->vm_pgoff;
page_last = vma_pages(vma) +
bo->vm_node->start - vma->vm_pgoff;
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
int ttm_bo_mmap(struct file *filp, struct vm_area_struct *vma,
struct ttm_bo_device *bdev)
{
struct ttm_bo_driver *driver;
struct ttm_buffer_object *bo;
int ret;
read_lock(&bdev->vm_lock);
bo = ttm_bo_vm_lookup_rb(bdev, vma->vm_pgoff,
vma_pages(vma));
if (likely(bo != NULL) && !kref_get_unless_zero(&bo->kref))
bo = NULL;
read_unlock(&bdev->vm_lock);
if (unlikely(bo == NULL)) {
pr_err("Could not find buffer object to map\n");
return -EINVAL;
}
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
ssize_t ttm_bo_io(struct ttm_bo_device *bdev, struct file *filp,
const char __user *wbuf, char __user *rbuf, size_t count,
loff_t *f_pos, bool write)
{
struct ttm_buffer_object *bo;
struct ttm_bo_driver *driver;
struct ttm_bo_kmap_obj map;
unsigned long dev_offset = (*f_pos >> PAGE_SHIFT);
unsigned long kmap_offset;
unsigned long kmap_end;
unsigned long kmap_num;
size_t io_size;
unsigned int page_offset;
char *virtual;
int ret;
bool no_wait = false;
bool dummy;
read_lock(&bdev->vm_lock);
bo = ttm_bo_vm_lookup_rb(bdev, dev_offset, 1);
if (likely(bo != NULL))
ttm_bo_reference(bo);
read_unlock(&bdev->vm_lock);
if (unlikely(bo == NULL))
return -EFAULT;
driver = bo->bdev->driver;
if (unlikely(!driver->verify_access)) {
ret = -EPERM;
goto out_unref;
}
ret = driver->verify_access(bo, filp);
if (unlikely(ret != 0))
goto out_unref;
kmap_offset = dev_offset - bo->vm_node->start;
if (unlikely(kmap_offset >= bo->num_pages)) {
ret = -EFBIG;
goto out_unref;
}
page_offset = *f_pos & ~PAGE_MASK;
io_size = bo->num_pages - kmap_offset;
io_size = (io_size << PAGE_SHIFT) - page_offset;
if (count < io_size)
io_size = count;
kmap_end = (*f_pos + count - 1) >> PAGE_SHIFT;
kmap_num = kmap_end - kmap_offset + 1;
ret = ttm_bo_reserve(bo, true, no_wait, false, 0);
switch (ret) {
case 0:
break;
case -EBUSY:
ret = -EAGAIN;
goto out_unref;
default:
goto out_unref;
}
ret = ttm_bo_kmap(bo, kmap_offset, kmap_num, &map);
if (unlikely(ret != 0)) {
ttm_bo_unreserve(bo);
goto out_unref;
}
virtual = ttm_kmap_obj_virtual(&map, &dummy);
virtual += page_offset;
if (write)
ret = copy_from_user(virtual, wbuf, io_size);
else
ret = copy_to_user(rbuf, virtual, io_size);
ttm_bo_kunmap(&map);
ttm_bo_unreserve(bo);
ttm_bo_unref(&bo);
if (unlikely(ret != 0))
return -EFBIG;
*f_pos += io_size;
return io_size;
out_unref:
ttm_bo_unref(&bo);
return ret;
}
ssize_t ttm_bo_fbdev_io(struct ttm_buffer_object *bo, const char __user *wbuf,
char __user *rbuf, size_t count, loff_t *f_pos,
bool write)
{
struct ttm_bo_kmap_obj map;
unsigned long kmap_offset;
unsigned long kmap_end;
unsigned long kmap_num;
size_t io_size;
unsigned int page_offset;
char *virtual;
int ret;
bool no_wait = false;
bool dummy;
kmap_offset = (*f_pos >> PAGE_SHIFT);
if (unlikely(kmap_offset >= bo->num_pages))
return -EFBIG;
page_offset = *f_pos & ~PAGE_MASK;
io_size = bo->num_pages - kmap_offset;
io_size = (io_size << PAGE_SHIFT) - page_offset;
if (count < io_size)
io_size = count;
kmap_end = (*f_pos + count - 1) >> PAGE_SHIFT;
kmap_num = kmap_end - kmap_offset + 1;
ret = ttm_bo_reserve(bo, true, no_wait, false, 0);
switch (ret) {
case 0:
break;
case -EBUSY:
return -EAGAIN;
default:
return ret;
}
ret = ttm_bo_kmap(bo, kmap_offset, kmap_num, &map);
if (unlikely(ret != 0)) {
ttm_bo_unreserve(bo);
return ret;
}
virtual = ttm_kmap_obj_virtual(&map, &dummy);
virtual += page_offset;
if (write)
ret = copy_from_user(virtual, wbuf, io_size);
else
ret = copy_to_user(rbuf, virtual, io_size);
ttm_bo_kunmap(&map);
ttm_bo_unreserve(bo);
ttm_bo_unref(&bo);
if (unlikely(ret != 0))
return ret;
*f_pos += io_size;
return io_size;
}
