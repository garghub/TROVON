void qib_release_mmap_info(struct kref *ref)
{
struct qib_mmap_info *ip =
container_of(ref, struct qib_mmap_info, ref);
struct qib_ibdev *dev = to_idev(ip->context->device);
spin_lock_irq(&dev->pending_lock);
list_del(&ip->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
vfree(ip->obj);
kfree(ip);
}
static void qib_vma_open(struct vm_area_struct *vma)
{
struct qib_mmap_info *ip = vma->vm_private_data;
kref_get(&ip->ref);
}
static void qib_vma_close(struct vm_area_struct *vma)
{
struct qib_mmap_info *ip = vma->vm_private_data;
kref_put(&ip->ref, qib_release_mmap_info);
}
int qib_mmap(struct ib_ucontext *context, struct vm_area_struct *vma)
{
struct qib_ibdev *dev = to_idev(context->device);
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
unsigned long size = vma->vm_end - vma->vm_start;
struct qib_mmap_info *ip, *pp;
int ret = -EINVAL;
spin_lock_irq(&dev->pending_lock);
list_for_each_entry_safe(ip, pp, &dev->pending_mmaps,
pending_mmaps) {
if (context != ip->context || (__u64) offset != ip->offset)
continue;
if (size > ip->size)
break;
list_del_init(&ip->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
ret = remap_vmalloc_range(vma, ip->obj, 0);
if (ret)
goto done;
vma->vm_ops = &qib_vm_ops;
vma->vm_private_data = ip;
qib_vma_open(vma);
goto done;
}
spin_unlock_irq(&dev->pending_lock);
done:
return ret;
}
struct qib_mmap_info *qib_create_mmap_info(struct qib_ibdev *dev,
u32 size,
struct ib_ucontext *context,
void *obj) {
struct qib_mmap_info *ip;
ip = kmalloc(sizeof(*ip), GFP_KERNEL);
if (!ip)
goto bail;
size = PAGE_ALIGN(size);
spin_lock_irq(&dev->mmap_offset_lock);
if (dev->mmap_offset == 0)
dev->mmap_offset = PAGE_SIZE;
ip->offset = dev->mmap_offset;
dev->mmap_offset += size;
spin_unlock_irq(&dev->mmap_offset_lock);
INIT_LIST_HEAD(&ip->pending_mmaps);
ip->size = size;
ip->context = context;
ip->obj = obj;
kref_init(&ip->ref);
bail:
return ip;
}
void qib_update_mmap_info(struct qib_ibdev *dev, struct qib_mmap_info *ip,
u32 size, void *obj)
{
size = PAGE_ALIGN(size);
spin_lock_irq(&dev->mmap_offset_lock);
if (dev->mmap_offset == 0)
dev->mmap_offset = PAGE_SIZE;
ip->offset = dev->mmap_offset;
dev->mmap_offset += size;
spin_unlock_irq(&dev->mmap_offset_lock);
ip->size = size;
ip->obj = obj;
}
