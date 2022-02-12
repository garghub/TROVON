dma_addr_t hfi1_map_page(struct pci_dev *hwdev, struct page *page,
unsigned long offset, size_t size, int direction)
{
dma_addr_t phys;
phys = pci_map_page(hwdev, page, offset, size, direction);
return phys;
}
int hfi1_acquire_user_pages(unsigned long vaddr, size_t npages, bool writable,
struct page **pages)
{
unsigned long pinned, lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
bool can_lock = capable(CAP_IPC_LOCK);
int ret;
down_read(&current->mm->mmap_sem);
pinned = current->mm->pinned_vm;
up_read(&current->mm->mmap_sem);
if (pinned + npages > lock_limit && !can_lock)
return -ENOMEM;
ret = get_user_pages_fast(vaddr, npages, writable, pages);
if (ret < 0)
return ret;
down_write(&current->mm->mmap_sem);
current->mm->pinned_vm += ret;
up_write(&current->mm->mmap_sem);
return ret;
}
void hfi1_release_user_pages(struct page **p, size_t npages, bool dirty)
{
size_t i;
for (i = 0; i < npages; i++) {
if (dirty)
set_page_dirty_lock(p[i]);
put_page(p[i]);
}
if (current->mm) {
down_write(&current->mm->mmap_sem);
current->mm->pinned_vm -= npages;
up_write(&current->mm->mmap_sem);
}
}
