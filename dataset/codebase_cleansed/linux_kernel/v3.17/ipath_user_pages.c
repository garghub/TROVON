static void __ipath_release_user_pages(struct page **p, size_t num_pages,
int dirty)
{
size_t i;
for (i = 0; i < num_pages; i++) {
ipath_cdbg(MM, "%lu/%lu put_page %p\n", (unsigned long) i,
(unsigned long) num_pages, p[i]);
if (dirty)
set_page_dirty_lock(p[i]);
put_page(p[i]);
}
}
static int __ipath_get_user_pages(unsigned long start_page, size_t num_pages,
struct page **p)
{
unsigned long lock_limit;
size_t got;
int ret;
lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
if (num_pages > lock_limit) {
ret = -ENOMEM;
goto bail;
}
ipath_cdbg(VERBOSE, "pin %lx pages from vaddr %lx\n",
(unsigned long) num_pages, start_page);
for (got = 0; got < num_pages; got += ret) {
ret = get_user_pages(current, current->mm,
start_page + got * PAGE_SIZE,
num_pages - got, 1, 1,
p + got, NULL);
if (ret < 0)
goto bail_release;
}
current->mm->pinned_vm += num_pages;
ret = 0;
goto bail;
bail_release:
__ipath_release_user_pages(p, got, 0);
bail:
return ret;
}
dma_addr_t ipath_map_page(struct pci_dev *hwdev, struct page *page,
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
dma_addr_t ipath_map_single(struct pci_dev *hwdev, void *ptr, size_t size,
int direction)
{
dma_addr_t phys;
phys = pci_map_single(hwdev, ptr, size, direction);
if (phys == 0) {
pci_unmap_single(hwdev, phys, size, direction);
phys = pci_map_single(hwdev, ptr, size, direction);
}
return phys;
}
int ipath_get_user_pages(unsigned long start_page, size_t num_pages,
struct page **p)
{
int ret;
down_write(&current->mm->mmap_sem);
ret = __ipath_get_user_pages(start_page, num_pages, p);
up_write(&current->mm->mmap_sem);
return ret;
}
void ipath_release_user_pages(struct page **p, size_t num_pages)
{
down_write(&current->mm->mmap_sem);
__ipath_release_user_pages(p, num_pages, 1);
current->mm->pinned_vm -= num_pages;
up_write(&current->mm->mmap_sem);
}
static void user_pages_account(struct work_struct *_work)
{
struct ipath_user_pages_work *work =
container_of(_work, struct ipath_user_pages_work, work);
down_write(&work->mm->mmap_sem);
work->mm->pinned_vm -= work->num_pages;
up_write(&work->mm->mmap_sem);
mmput(work->mm);
kfree(work);
}
void ipath_release_user_pages_on_close(struct page **p, size_t num_pages)
{
struct ipath_user_pages_work *work;
struct mm_struct *mm;
__ipath_release_user_pages(p, num_pages, 1);
mm = get_task_mm(current);
if (!mm)
return;
work = kmalloc(sizeof(*work), GFP_KERNEL);
if (!work)
goto bail_mm;
INIT_WORK(&work->work, user_pages_account);
work->mm = mm;
work->num_pages = num_pages;
queue_work(ib_wq, &work->work);
return;
bail_mm:
mmput(mm);
return;
}
