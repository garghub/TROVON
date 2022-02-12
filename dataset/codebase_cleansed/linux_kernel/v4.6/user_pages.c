bool hfi1_can_pin_pages(struct hfi1_devdata *dd, u32 nlocked, u32 npages)
{
unsigned long ulimit = rlimit(RLIMIT_MEMLOCK), pinned, cache_limit,
size = (cache_size * (1UL << 20));
unsigned usr_ctxts = dd->num_rcv_contexts - dd->first_user_ctxt;
bool can_lock = capable(CAP_IPC_LOCK);
cache_limit = (ulimit / usr_ctxts) / 4;
if (ulimit != (-1UL) && size > cache_limit)
size = cache_limit;
size = DIV_ROUND_UP(size, PAGE_SIZE);
down_read(&current->mm->mmap_sem);
pinned = current->mm->pinned_vm;
up_read(&current->mm->mmap_sem);
if (pinned + npages >= ulimit && !can_lock)
return false;
return ((nlocked + npages) <= size) || can_lock;
}
int hfi1_acquire_user_pages(unsigned long vaddr, size_t npages, bool writable,
struct page **pages)
{
int ret;
ret = get_user_pages_fast(vaddr, npages, writable, pages);
if (ret < 0)
return ret;
down_write(&current->mm->mmap_sem);
current->mm->pinned_vm += ret;
up_write(&current->mm->mmap_sem);
return ret;
}
void hfi1_release_user_pages(struct mm_struct *mm, struct page **p,
size_t npages, bool dirty)
{
size_t i;
for (i = 0; i < npages; i++) {
if (dirty)
set_page_dirty_lock(p[i]);
put_page(p[i]);
}
if (mm) {
down_write(&mm->mmap_sem);
mm->pinned_vm -= npages;
up_write(&mm->mmap_sem);
}
}
