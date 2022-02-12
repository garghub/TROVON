static void videobuf_vm_open(struct vm_area_struct *vma)
{
struct videobuf_mapping *map = vma->vm_private_data;
struct videobuf_queue *q = map->q;
dprintk(2, "vm_open %p [count=%u,vma=%08lx-%08lx]\n", map,
map->count, vma->vm_start, vma->vm_end);
videobuf_queue_lock(q);
map->count++;
videobuf_queue_unlock(q);
}
static void videobuf_vm_close(struct vm_area_struct *vma)
{
struct videobuf_mapping *map = vma->vm_private_data;
struct videobuf_queue *q = map->q;
int i;
dprintk(2, "vm_close %p [count=%u,vma=%08lx-%08lx]\n", map,
map->count, vma->vm_start, vma->vm_end);
videobuf_queue_lock(q);
if (!--map->count) {
struct videobuf_vmalloc_memory *mem;
dprintk(1, "munmap %p q=%p\n", map, q);
if (q->streaming)
videobuf_queue_cancel(q);
for (i = 0; i < VIDEO_MAX_FRAME; i++) {
if (NULL == q->bufs[i])
continue;
if (q->bufs[i]->map != map)
continue;
mem = q->bufs[i]->priv;
if (mem) {
MAGIC_CHECK(mem->magic, MAGIC_VMAL_MEM);
dprintk(1, "%s: buf[%d] freeing (%p)\n",
__func__, i, mem->vaddr);
vfree(mem->vaddr);
mem->vaddr = NULL;
}
q->bufs[i]->map = NULL;
q->bufs[i]->baddr = 0;
}
kfree(map);
}
videobuf_queue_unlock(q);
return;
}
static struct videobuf_buffer *__videobuf_alloc_vb(size_t size)
{
struct videobuf_vmalloc_memory *mem;
struct videobuf_buffer *vb;
vb = kzalloc(size + sizeof(*mem), GFP_KERNEL);
if (!vb)
return vb;
mem = vb->priv = ((char *)vb) + size;
mem->magic = MAGIC_VMAL_MEM;
dprintk(1, "%s: allocated at %p(%ld+%ld) & %p(%ld)\n",
__func__, vb, (long)sizeof(*vb), (long)size - sizeof(*vb),
mem, (long)sizeof(*mem));
return vb;
}
static int __videobuf_iolock(struct videobuf_queue *q,
struct videobuf_buffer *vb,
struct v4l2_framebuffer *fbuf)
{
struct videobuf_vmalloc_memory *mem = vb->priv;
int pages;
BUG_ON(!mem);
MAGIC_CHECK(mem->magic, MAGIC_VMAL_MEM);
switch (vb->memory) {
case V4L2_MEMORY_MMAP:
dprintk(1, "%s memory method MMAP\n", __func__);
if (!mem->vaddr) {
printk(KERN_ERR "memory is not alloced/mmapped.\n");
return -EINVAL;
}
break;
case V4L2_MEMORY_USERPTR:
pages = PAGE_ALIGN(vb->size);
dprintk(1, "%s memory method USERPTR\n", __func__);
if (vb->baddr) {
printk(KERN_ERR "USERPTR is currently not supported\n");
return -EINVAL;
}
mem->vaddr = vmalloc_user(pages);
if (!mem->vaddr) {
printk(KERN_ERR "vmalloc (%d pages) failed\n", pages);
return -ENOMEM;
}
dprintk(1, "vmalloc is at addr %p (%d pages)\n",
mem->vaddr, pages);
#if 0
int rc;
if (!vb->baddr)
return 0;
rc = remap_vmalloc_range(mem->vma, (void *)vb->baddr, 0);
if (rc < 0) {
printk(KERN_ERR "mmap: remap failed with error %d", rc);
return -ENOMEM;
}
#endif
break;
case V4L2_MEMORY_OVERLAY:
default:
dprintk(1, "%s memory method OVERLAY/unknown\n", __func__);
printk(KERN_ERR "Memory method currently unsupported.\n");
return -EINVAL;
}
return 0;
}
static int __videobuf_mmap_mapper(struct videobuf_queue *q,
struct videobuf_buffer *buf,
struct vm_area_struct *vma)
{
struct videobuf_vmalloc_memory *mem;
struct videobuf_mapping *map;
int retval, pages;
dprintk(1, "%s\n", __func__);
map = kzalloc(sizeof(struct videobuf_mapping), GFP_KERNEL);
if (NULL == map)
return -ENOMEM;
buf->map = map;
map->q = q;
buf->baddr = vma->vm_start;
mem = buf->priv;
BUG_ON(!mem);
MAGIC_CHECK(mem->magic, MAGIC_VMAL_MEM);
pages = PAGE_ALIGN(vma->vm_end - vma->vm_start);
mem->vaddr = vmalloc_user(pages);
if (!mem->vaddr) {
printk(KERN_ERR "vmalloc (%d pages) failed\n", pages);
goto error;
}
dprintk(1, "vmalloc is at addr %p (%d pages)\n", mem->vaddr, pages);
retval = remap_vmalloc_range(vma, mem->vaddr, 0);
if (retval < 0) {
printk(KERN_ERR "mmap: remap failed with error %d. ", retval);
vfree(mem->vaddr);
goto error;
}
vma->vm_ops = &videobuf_vm_ops;
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_private_data = map;
dprintk(1, "mmap %p: q=%p %08lx-%08lx (%lx) pgoff %08lx buf %d\n",
map, q, vma->vm_start, vma->vm_end,
(long int)buf->bsize,
vma->vm_pgoff, buf->i);
videobuf_vm_open(vma);
return 0;
error:
mem = NULL;
kfree(map);
return -ENOMEM;
}
void videobuf_queue_vmalloc_init(struct videobuf_queue *q,
const struct videobuf_queue_ops *ops,
struct device *dev,
spinlock_t *irqlock,
enum v4l2_buf_type type,
enum v4l2_field field,
unsigned int msize,
void *priv,
struct mutex *ext_lock)
{
videobuf_queue_core_init(q, ops, dev, irqlock, type, field, msize,
priv, &qops, ext_lock);
}
void *videobuf_to_vmalloc(struct videobuf_buffer *buf)
{
struct videobuf_vmalloc_memory *mem = buf->priv;
BUG_ON(!mem);
MAGIC_CHECK(mem->magic, MAGIC_VMAL_MEM);
return mem->vaddr;
}
void videobuf_vmalloc_free(struct videobuf_buffer *buf)
{
struct videobuf_vmalloc_memory *mem = buf->priv;
if ((buf->memory != V4L2_MEMORY_USERPTR) || buf->baddr)
return;
if (!mem)
return;
MAGIC_CHECK(mem->magic, MAGIC_VMAL_MEM);
vfree(mem->vaddr);
mem->vaddr = NULL;
return;
}
