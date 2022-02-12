static int madvise_need_mmap_write(int behavior)
{
switch (behavior) {
case MADV_REMOVE:
case MADV_WILLNEED:
case MADV_DONTNEED:
return 0;
default:
return 1;
}
}
static long madvise_behavior(struct vm_area_struct * vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end, int behavior)
{
struct mm_struct * mm = vma->vm_mm;
int error = 0;
pgoff_t pgoff;
unsigned long new_flags = vma->vm_flags;
switch (behavior) {
case MADV_NORMAL:
new_flags = new_flags & ~VM_RAND_READ & ~VM_SEQ_READ;
break;
case MADV_SEQUENTIAL:
new_flags = (new_flags & ~VM_RAND_READ) | VM_SEQ_READ;
break;
case MADV_RANDOM:
new_flags = (new_flags & ~VM_SEQ_READ) | VM_RAND_READ;
break;
case MADV_DONTFORK:
new_flags |= VM_DONTCOPY;
break;
case MADV_DOFORK:
if (vma->vm_flags & VM_IO) {
error = -EINVAL;
goto out;
}
new_flags &= ~VM_DONTCOPY;
break;
case MADV_MERGEABLE:
case MADV_UNMERGEABLE:
error = ksm_madvise(vma, start, end, behavior, &new_flags);
if (error)
goto out;
break;
case MADV_HUGEPAGE:
case MADV_NOHUGEPAGE:
error = hugepage_madvise(vma, &new_flags, behavior);
if (error)
goto out;
break;
}
if (new_flags == vma->vm_flags) {
*prev = vma;
goto out;
}
pgoff = vma->vm_pgoff + ((start - vma->vm_start) >> PAGE_SHIFT);
*prev = vma_merge(mm, *prev, start, end, new_flags, vma->anon_vma,
vma->vm_file, pgoff, vma_policy(vma));
if (*prev) {
vma = *prev;
goto success;
}
*prev = vma;
if (start != vma->vm_start) {
error = split_vma(mm, vma, start, 1);
if (error)
goto out;
}
if (end != vma->vm_end) {
error = split_vma(mm, vma, end, 0);
if (error)
goto out;
}
success:
vma->vm_flags = new_flags;
out:
if (error == -ENOMEM)
error = -EAGAIN;
return error;
}
static long madvise_willneed(struct vm_area_struct * vma,
struct vm_area_struct ** prev,
unsigned long start, unsigned long end)
{
struct file *file = vma->vm_file;
if (!file)
return -EBADF;
if (file->f_mapping->a_ops->get_xip_mem) {
return 0;
}
*prev = vma;
start = ((start - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
if (end > vma->vm_end)
end = vma->vm_end;
end = ((end - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
force_page_cache_readahead(file->f_mapping, file, start, end - start);
return 0;
}
static long madvise_dontneed(struct vm_area_struct * vma,
struct vm_area_struct ** prev,
unsigned long start, unsigned long end)
{
*prev = vma;
if (vma->vm_flags & (VM_LOCKED|VM_HUGETLB|VM_PFNMAP))
return -EINVAL;
if (unlikely(vma->vm_flags & VM_NONLINEAR)) {
struct zap_details details = {
.nonlinear_vma = vma,
.last_index = ULONG_MAX,
};
zap_page_range(vma, start, end - start, &details);
} else
zap_page_range(vma, start, end - start, NULL);
return 0;
}
static long madvise_remove(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end)
{
struct address_space *mapping;
loff_t offset, endoff;
int error;
*prev = NULL;
if (vma->vm_flags & (VM_LOCKED|VM_NONLINEAR|VM_HUGETLB))
return -EINVAL;
if (!vma->vm_file || !vma->vm_file->f_mapping
|| !vma->vm_file->f_mapping->host) {
return -EINVAL;
}
if ((vma->vm_flags & (VM_SHARED|VM_WRITE)) != (VM_SHARED|VM_WRITE))
return -EACCES;
mapping = vma->vm_file->f_mapping;
offset = (loff_t)(start - vma->vm_start)
+ ((loff_t)vma->vm_pgoff << PAGE_SHIFT);
endoff = (loff_t)(end - vma->vm_start - 1)
+ ((loff_t)vma->vm_pgoff << PAGE_SHIFT);
up_read(&current->mm->mmap_sem);
error = vmtruncate_range(mapping->host, offset, endoff);
down_read(&current->mm->mmap_sem);
return error;
}
static int madvise_hwpoison(int bhv, unsigned long start, unsigned long end)
{
int ret = 0;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
for (; start < end; start += PAGE_SIZE) {
struct page *p;
int ret = get_user_pages_fast(start, 1, 0, &p);
if (ret != 1)
return ret;
if (bhv == MADV_SOFT_OFFLINE) {
printk(KERN_INFO "Soft offlining page %lx at %lx\n",
page_to_pfn(p), start);
ret = soft_offline_page(p, MF_COUNT_INCREASED);
if (ret)
break;
continue;
}
printk(KERN_INFO "Injecting memory failure for page %lx at %lx\n",
page_to_pfn(p), start);
__memory_failure(page_to_pfn(p), 0, MF_COUNT_INCREASED);
}
return ret;
}
static long
madvise_vma(struct vm_area_struct *vma, struct vm_area_struct **prev,
unsigned long start, unsigned long end, int behavior)
{
switch (behavior) {
case MADV_REMOVE:
return madvise_remove(vma, prev, start, end);
case MADV_WILLNEED:
return madvise_willneed(vma, prev, start, end);
case MADV_DONTNEED:
return madvise_dontneed(vma, prev, start, end);
default:
return madvise_behavior(vma, prev, start, end, behavior);
}
}
static int
madvise_behavior_valid(int behavior)
{
switch (behavior) {
case MADV_DOFORK:
case MADV_DONTFORK:
case MADV_NORMAL:
case MADV_SEQUENTIAL:
case MADV_RANDOM:
case MADV_REMOVE:
case MADV_WILLNEED:
case MADV_DONTNEED:
#ifdef CONFIG_KSM
case MADV_MERGEABLE:
case MADV_UNMERGEABLE:
#endif
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
case MADV_HUGEPAGE:
case MADV_NOHUGEPAGE:
#endif
return 1;
default:
return 0;
}
}
