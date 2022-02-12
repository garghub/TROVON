static void __ib_umem_release(struct ib_device *dev, struct ib_umem *umem, int dirty)
{
struct scatterlist *sg;
struct page *page;
int i;
if (umem->nmap > 0)
ib_dma_unmap_sg(dev, umem->sg_head.sgl,
umem->nmap,
DMA_BIDIRECTIONAL);
for_each_sg(umem->sg_head.sgl, sg, umem->npages, i) {
page = sg_page(sg);
if (umem->writable && dirty)
set_page_dirty_lock(page);
put_page(page);
}
sg_free_table(&umem->sg_head);
return;
}
struct ib_umem *ib_umem_get(struct ib_ucontext *context, unsigned long addr,
size_t size, int access, int dmasync)
{
struct ib_umem *umem;
struct page **page_list;
struct vm_area_struct **vma_list;
unsigned long locked;
unsigned long lock_limit;
unsigned long cur_base;
unsigned long npages;
int ret;
int i;
unsigned long dma_attrs = 0;
struct scatterlist *sg, *sg_list_start;
int need_release = 0;
if (dmasync)
dma_attrs |= DMA_ATTR_WRITE_BARRIER;
if (!size)
return ERR_PTR(-EINVAL);
if (((addr + size) < addr) ||
PAGE_ALIGN(addr + size) < (addr + size))
return ERR_PTR(-EINVAL);
if (!can_do_mlock())
return ERR_PTR(-EPERM);
umem = kzalloc(sizeof *umem, GFP_KERNEL);
if (!umem)
return ERR_PTR(-ENOMEM);
umem->context = context;
umem->length = size;
umem->address = addr;
umem->page_size = PAGE_SIZE;
umem->pid = get_task_pid(current, PIDTYPE_PID);
umem->writable = !!(access &
(IB_ACCESS_LOCAL_WRITE | IB_ACCESS_REMOTE_WRITE |
IB_ACCESS_REMOTE_ATOMIC | IB_ACCESS_MW_BIND));
if (access & IB_ACCESS_ON_DEMAND) {
ret = ib_umem_odp_get(context, umem);
if (ret) {
kfree(umem);
return ERR_PTR(ret);
}
return umem;
}
umem->odp_data = NULL;
umem->hugetlb = 1;
page_list = (struct page **) __get_free_page(GFP_KERNEL);
if (!page_list) {
kfree(umem);
return ERR_PTR(-ENOMEM);
}
vma_list = (struct vm_area_struct **) __get_free_page(GFP_KERNEL);
if (!vma_list)
umem->hugetlb = 0;
npages = ib_umem_num_pages(umem);
down_write(&current->mm->mmap_sem);
locked = npages + current->mm->pinned_vm;
lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
if ((locked > lock_limit) && !capable(CAP_IPC_LOCK)) {
ret = -ENOMEM;
goto out;
}
cur_base = addr & PAGE_MASK;
if (npages == 0) {
ret = -EINVAL;
goto out;
}
ret = sg_alloc_table(&umem->sg_head, npages, GFP_KERNEL);
if (ret)
goto out;
need_release = 1;
sg_list_start = umem->sg_head.sgl;
while (npages) {
ret = get_user_pages(cur_base,
min_t(unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)),
1, !umem->writable, page_list, vma_list);
if (ret < 0)
goto out;
umem->npages += ret;
cur_base += ret * PAGE_SIZE;
npages -= ret;
for_each_sg(sg_list_start, sg, ret, i) {
if (vma_list && !is_vm_hugetlb_page(vma_list[i]))
umem->hugetlb = 0;
sg_set_page(sg, page_list[i], PAGE_SIZE, 0);
}
sg_list_start = sg;
}
umem->nmap = ib_dma_map_sg_attrs(context->device,
umem->sg_head.sgl,
umem->npages,
DMA_BIDIRECTIONAL,
dma_attrs);
if (umem->nmap <= 0) {
ret = -ENOMEM;
goto out;
}
ret = 0;
out:
if (ret < 0) {
if (need_release)
__ib_umem_release(context->device, umem, 0);
put_pid(umem->pid);
kfree(umem);
} else
current->mm->pinned_vm = locked;
up_write(&current->mm->mmap_sem);
if (vma_list)
free_page((unsigned long) vma_list);
free_page((unsigned long) page_list);
return ret < 0 ? ERR_PTR(ret) : umem;
}
static void ib_umem_account(struct work_struct *work)
{
struct ib_umem *umem = container_of(work, struct ib_umem, work);
down_write(&umem->mm->mmap_sem);
umem->mm->pinned_vm -= umem->diff;
up_write(&umem->mm->mmap_sem);
mmput(umem->mm);
kfree(umem);
}
void ib_umem_release(struct ib_umem *umem)
{
struct ib_ucontext *context = umem->context;
struct mm_struct *mm;
struct task_struct *task;
unsigned long diff;
if (umem->odp_data) {
ib_umem_odp_release(umem);
return;
}
__ib_umem_release(umem->context->device, umem, 1);
task = get_pid_task(umem->pid, PIDTYPE_PID);
put_pid(umem->pid);
if (!task)
goto out;
mm = get_task_mm(task);
put_task_struct(task);
if (!mm)
goto out;
diff = ib_umem_num_pages(umem);
if (context->closing) {
if (!down_write_trylock(&mm->mmap_sem)) {
INIT_WORK(&umem->work, ib_umem_account);
umem->mm = mm;
umem->diff = diff;
queue_work(ib_wq, &umem->work);
return;
}
} else
down_write(&mm->mmap_sem);
mm->pinned_vm -= diff;
up_write(&mm->mmap_sem);
mmput(mm);
out:
kfree(umem);
}
int ib_umem_page_count(struct ib_umem *umem)
{
int shift;
int i;
int n;
struct scatterlist *sg;
if (umem->odp_data)
return ib_umem_num_pages(umem);
shift = ilog2(umem->page_size);
n = 0;
for_each_sg(umem->sg_head.sgl, sg, umem->nmap, i)
n += sg_dma_len(sg) >> shift;
return n;
}
int ib_umem_copy_from(void *dst, struct ib_umem *umem, size_t offset,
size_t length)
{
size_t end = offset + length;
int ret;
if (offset > umem->length || length > umem->length - offset) {
pr_err("ib_umem_copy_from not in range. offset: %zd umem length: %zd end: %zd\n",
offset, umem->length, end);
return -EINVAL;
}
ret = sg_pcopy_to_buffer(umem->sg_head.sgl, umem->nmap, dst, length,
offset + ib_umem_offset(umem));
if (ret < 0)
return ret;
else if (ret != length)
return -EINVAL;
else
return 0;
}
