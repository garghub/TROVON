static int vb2_dma_sg_alloc_compacted(struct vb2_dma_sg_buf *buf,
gfp_t gfp_flags)
{
unsigned int last_page = 0;
int size = buf->size;
while (size > 0) {
struct page *pages;
int order;
int i;
order = get_order(size);
if ((PAGE_SIZE << order) > size)
order--;
pages = NULL;
while (!pages) {
pages = alloc_pages(GFP_KERNEL | __GFP_ZERO |
__GFP_NOWARN | gfp_flags, order);
if (pages)
break;
if (order == 0) {
while (last_page--)
__free_page(buf->pages[last_page]);
return -ENOMEM;
}
order--;
}
split_page(pages, order);
for (i = 0; i < (1 << order); i++)
buf->pages[last_page++] = &pages[i];
size -= PAGE_SIZE << order;
}
return 0;
}
static void *vb2_dma_sg_alloc(void *alloc_ctx, unsigned long size, gfp_t gfp_flags)
{
struct vb2_dma_sg_buf *buf;
int ret;
int num_pages;
buf = kzalloc(sizeof *buf, GFP_KERNEL);
if (!buf)
return NULL;
buf->vaddr = NULL;
buf->write = 0;
buf->offset = 0;
buf->size = size;
buf->num_pages = size >> PAGE_SHIFT;
buf->pages = kzalloc(buf->num_pages * sizeof(struct page *),
GFP_KERNEL);
if (!buf->pages)
goto fail_pages_array_alloc;
ret = vb2_dma_sg_alloc_compacted(buf, gfp_flags);
if (ret)
goto fail_pages_alloc;
ret = sg_alloc_table_from_pages(&buf->sg_table, buf->pages,
buf->num_pages, 0, size, gfp_flags);
if (ret)
goto fail_table_alloc;
buf->handler.refcount = &buf->refcount;
buf->handler.put = vb2_dma_sg_put;
buf->handler.arg = buf;
atomic_inc(&buf->refcount);
dprintk(1, "%s: Allocated buffer of %d pages\n",
__func__, buf->num_pages);
return buf;
fail_table_alloc:
num_pages = buf->num_pages;
while (num_pages--)
__free_page(buf->pages[num_pages]);
fail_pages_alloc:
kfree(buf->pages);
fail_pages_array_alloc:
kfree(buf);
return NULL;
}
static void vb2_dma_sg_put(void *buf_priv)
{
struct vb2_dma_sg_buf *buf = buf_priv;
int i = buf->num_pages;
if (atomic_dec_and_test(&buf->refcount)) {
dprintk(1, "%s: Freeing buffer of %d pages\n", __func__,
buf->num_pages);
if (buf->vaddr)
vm_unmap_ram(buf->vaddr, buf->num_pages);
sg_free_table(&buf->sg_table);
while (--i >= 0)
__free_page(buf->pages[i]);
kfree(buf->pages);
kfree(buf);
}
}
static inline int vma_is_io(struct vm_area_struct *vma)
{
return !!(vma->vm_flags & (VM_IO | VM_PFNMAP));
}
static void *vb2_dma_sg_get_userptr(void *alloc_ctx, unsigned long vaddr,
unsigned long size, int write)
{
struct vb2_dma_sg_buf *buf;
unsigned long first, last;
int num_pages_from_user;
struct vm_area_struct *vma;
buf = kzalloc(sizeof *buf, GFP_KERNEL);
if (!buf)
return NULL;
buf->vaddr = NULL;
buf->write = write;
buf->offset = vaddr & ~PAGE_MASK;
buf->size = size;
first = (vaddr & PAGE_MASK) >> PAGE_SHIFT;
last = ((vaddr + size - 1) & PAGE_MASK) >> PAGE_SHIFT;
buf->num_pages = last - first + 1;
buf->pages = kzalloc(buf->num_pages * sizeof(struct page *),
GFP_KERNEL);
if (!buf->pages)
goto userptr_fail_alloc_pages;
vma = find_vma(current->mm, vaddr);
if (!vma) {
dprintk(1, "no vma for address %lu\n", vaddr);
goto userptr_fail_find_vma;
}
if (vma->vm_end < vaddr + size) {
dprintk(1, "vma at %lu is too small for %lu bytes\n",
vaddr, size);
goto userptr_fail_find_vma;
}
buf->vma = vb2_get_vma(vma);
if (!buf->vma) {
dprintk(1, "failed to copy vma\n");
goto userptr_fail_find_vma;
}
if (vma_is_io(buf->vma)) {
for (num_pages_from_user = 0;
num_pages_from_user < buf->num_pages;
++num_pages_from_user, vaddr += PAGE_SIZE) {
unsigned long pfn;
if (follow_pfn(buf->vma, vaddr, &pfn)) {
dprintk(1, "no page for address %lu\n", vaddr);
break;
}
buf->pages[num_pages_from_user] = pfn_to_page(pfn);
}
} else
num_pages_from_user = get_user_pages(current, current->mm,
vaddr & PAGE_MASK,
buf->num_pages,
write,
1,
buf->pages,
NULL);
if (num_pages_from_user != buf->num_pages)
goto userptr_fail_get_user_pages;
if (sg_alloc_table_from_pages(&buf->sg_table, buf->pages,
buf->num_pages, buf->offset, size, 0))
goto userptr_fail_alloc_table_from_pages;
return buf;
userptr_fail_alloc_table_from_pages:
userptr_fail_get_user_pages:
dprintk(1, "get_user_pages requested/got: %d/%d]\n",
buf->num_pages, num_pages_from_user);
if (!vma_is_io(buf->vma))
while (--num_pages_from_user >= 0)
put_page(buf->pages[num_pages_from_user]);
vb2_put_vma(buf->vma);
userptr_fail_find_vma:
kfree(buf->pages);
userptr_fail_alloc_pages:
kfree(buf);
return NULL;
}
static void vb2_dma_sg_put_userptr(void *buf_priv)
{
struct vb2_dma_sg_buf *buf = buf_priv;
int i = buf->num_pages;
dprintk(1, "%s: Releasing userspace buffer of %d pages\n",
__func__, buf->num_pages);
if (buf->vaddr)
vm_unmap_ram(buf->vaddr, buf->num_pages);
sg_free_table(&buf->sg_table);
while (--i >= 0) {
if (buf->write)
set_page_dirty_lock(buf->pages[i]);
if (!vma_is_io(buf->vma))
put_page(buf->pages[i]);
}
kfree(buf->pages);
vb2_put_vma(buf->vma);
kfree(buf);
}
static void *vb2_dma_sg_vaddr(void *buf_priv)
{
struct vb2_dma_sg_buf *buf = buf_priv;
BUG_ON(!buf);
if (!buf->vaddr)
buf->vaddr = vm_map_ram(buf->pages,
buf->num_pages,
-1,
PAGE_KERNEL);
return buf->vaddr + buf->offset;
}
static unsigned int vb2_dma_sg_num_users(void *buf_priv)
{
struct vb2_dma_sg_buf *buf = buf_priv;
return atomic_read(&buf->refcount);
}
static int vb2_dma_sg_mmap(void *buf_priv, struct vm_area_struct *vma)
{
struct vb2_dma_sg_buf *buf = buf_priv;
unsigned long uaddr = vma->vm_start;
unsigned long usize = vma->vm_end - vma->vm_start;
int i = 0;
if (!buf) {
printk(KERN_ERR "No memory to map\n");
return -EINVAL;
}
do {
int ret;
ret = vm_insert_page(vma, uaddr, buf->pages[i++]);
if (ret) {
printk(KERN_ERR "Remapping memory, error: %d\n", ret);
return ret;
}
uaddr += PAGE_SIZE;
usize -= PAGE_SIZE;
} while (usize > 0);
vma->vm_private_data = &buf->handler;
vma->vm_ops = &vb2_common_vm_ops;
vma->vm_ops->open(vma);
return 0;
}
static void *vb2_dma_sg_cookie(void *buf_priv)
{
struct vb2_dma_sg_buf *buf = buf_priv;
return &buf->sg_table;
}
