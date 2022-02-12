struct vm_area_struct *vb2_get_vma(struct vm_area_struct *vma)
{
struct vm_area_struct *vma_copy;
vma_copy = kmalloc(sizeof(*vma_copy), GFP_KERNEL);
if (vma_copy == NULL)
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
void vb2_put_vma(struct vm_area_struct *vma)
{
if (!vma)
return;
if (vma->vm_ops && vma->vm_ops->close)
vma->vm_ops->close(vma);
if (vma->vm_file)
fput(vma->vm_file);
kfree(vma);
}
int vb2_get_contig_userptr(unsigned long vaddr, unsigned long size,
struct vm_area_struct **res_vma, dma_addr_t *res_pa)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned long offset, start, end;
unsigned long this_pfn, prev_pfn;
dma_addr_t pa = 0;
start = vaddr;
offset = start & ~PAGE_MASK;
end = start + size;
vma = find_vma(mm, start);
if (vma == NULL || vma->vm_end < end)
return -EFAULT;
for (prev_pfn = 0; start < end; start += PAGE_SIZE) {
int ret = follow_pfn(vma, start, &this_pfn);
if (ret)
return ret;
if (prev_pfn == 0)
pa = this_pfn << PAGE_SHIFT;
else if (this_pfn != prev_pfn + 1)
return -EFAULT;
prev_pfn = this_pfn;
}
*res_vma = vb2_get_vma(vma);
if (*res_vma == NULL)
return -ENOMEM;
*res_pa = pa + offset;
return 0;
}
static void vb2_common_vm_open(struct vm_area_struct *vma)
{
struct vb2_vmarea_handler *h = vma->vm_private_data;
pr_debug("%s: %p, refcount: %d, vma: %08lx-%08lx\n",
__func__, h, atomic_read(h->refcount), vma->vm_start,
vma->vm_end);
atomic_inc(h->refcount);
}
static void vb2_common_vm_close(struct vm_area_struct *vma)
{
struct vb2_vmarea_handler *h = vma->vm_private_data;
pr_debug("%s: %p, refcount: %d, vma: %08lx-%08lx\n",
__func__, h, atomic_read(h->refcount), vma->vm_start,
vma->vm_end);
h->put(h->arg);
}
