static void *vb2_vmalloc_alloc(void *alloc_ctx, unsigned long size)
{
struct vb2_vmalloc_buf *buf;
buf = kzalloc(sizeof *buf, GFP_KERNEL);
if (!buf)
return NULL;
buf->size = size;
buf->vaddr = vmalloc_user(buf->size);
buf->handler.refcount = &buf->refcount;
buf->handler.put = vb2_vmalloc_put;
buf->handler.arg = buf;
if (!buf->vaddr) {
printk(KERN_ERR "vmalloc of size %ld failed\n", buf->size);
kfree(buf);
return NULL;
}
atomic_inc(&buf->refcount);
printk(KERN_DEBUG "Allocated vmalloc buffer of size %ld at vaddr=%p\n",
buf->size, buf->vaddr);
return buf;
}
static void vb2_vmalloc_put(void *buf_priv)
{
struct vb2_vmalloc_buf *buf = buf_priv;
if (atomic_dec_and_test(&buf->refcount)) {
printk(KERN_DEBUG "%s: Freeing vmalloc mem at vaddr=%p\n",
__func__, buf->vaddr);
vfree(buf->vaddr);
kfree(buf);
}
}
static void *vb2_vmalloc_vaddr(void *buf_priv)
{
struct vb2_vmalloc_buf *buf = buf_priv;
BUG_ON(!buf);
if (!buf->vaddr) {
printk(KERN_ERR "Address of an unallocated plane requested\n");
return NULL;
}
return buf->vaddr;
}
static unsigned int vb2_vmalloc_num_users(void *buf_priv)
{
struct vb2_vmalloc_buf *buf = buf_priv;
return atomic_read(&buf->refcount);
}
static int vb2_vmalloc_mmap(void *buf_priv, struct vm_area_struct *vma)
{
struct vb2_vmalloc_buf *buf = buf_priv;
int ret;
if (!buf) {
printk(KERN_ERR "No memory to map\n");
return -EINVAL;
}
ret = remap_vmalloc_range(vma, buf->vaddr, 0);
if (ret) {
printk(KERN_ERR "Remapping vmalloc memory, error: %d\n", ret);
return ret;
}
vma->vm_flags |= VM_DONTEXPAND;
vma->vm_private_data = &buf->handler;
vma->vm_ops = &vb2_common_vm_ops;
vma->vm_ops->open(vma);
return 0;
}
