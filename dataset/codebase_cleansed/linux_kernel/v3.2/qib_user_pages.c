static void __qib_release_user_pages(struct page **p, size_t num_pages,
int dirty)
{
size_t i;
for (i = 0; i < num_pages; i++) {
if (dirty)
set_page_dirty_lock(p[i]);
put_page(p[i]);
}
}
static int __qib_get_user_pages(unsigned long start_page, size_t num_pages,
struct page **p, struct vm_area_struct **vma)
{
unsigned long lock_limit;
size_t got;
int ret;
lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
if (num_pages > lock_limit && !capable(CAP_IPC_LOCK)) {
ret = -ENOMEM;
goto bail;
}
for (got = 0; got < num_pages; got += ret) {
ret = get_user_pages(current, current->mm,
start_page + got * PAGE_SIZE,
num_pages - got, 1, 1,
p + got, vma);
if (ret < 0)
goto bail_release;
}
current->mm->pinned_vm += num_pages;
ret = 0;
goto bail;
bail_release:
__qib_release_user_pages(p, got, 0);
bail:
return ret;
}
dma_addr_t qib_map_page(struct pci_dev *hwdev, struct page *page,
unsigned long offset, size_t size, int direction)
{
dma_addr_t phys;
phys = pci_map_page(hwdev, page, offset, size, direction);
if (phys == 0) {
pci_unmap_page(hwdev, phys, size, direction);
phys = pci_map_page(hwdev, page, offset, size, direction);
}
return phys;
}
int qib_get_user_pages(unsigned long start_page, size_t num_pages,
struct page **p)
{
int ret;
down_write(&current->mm->mmap_sem);
ret = __qib_get_user_pages(start_page, num_pages, p, NULL);
up_write(&current->mm->mmap_sem);
return ret;
}
void qib_release_user_pages(struct page **p, size_t num_pages)
{
if (current->mm)
down_write(&current->mm->mmap_sem);
__qib_release_user_pages(p, num_pages, 1);
if (current->mm) {
current->mm->pinned_vm -= num_pages;
up_write(&current->mm->mmap_sem);
}
}
