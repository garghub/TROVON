static void ib_umem_notifier_start_account(struct ib_umem *item)
{
mutex_lock(&item->odp_data->umem_mutex);
if (item->odp_data->mn_counters_active) {
int notifiers_count = item->odp_data->notifiers_count++;
if (notifiers_count == 0)
reinit_completion(&item->odp_data->notifier_completion);
}
mutex_unlock(&item->odp_data->umem_mutex);
}
static void ib_umem_notifier_end_account(struct ib_umem *item)
{
mutex_lock(&item->odp_data->umem_mutex);
if (item->odp_data->mn_counters_active) {
++item->odp_data->notifiers_seq;
if (--item->odp_data->notifiers_count == 0)
complete_all(&item->odp_data->notifier_completion);
}
mutex_unlock(&item->odp_data->umem_mutex);
}
static void ib_ucontext_notifier_start_account(struct ib_ucontext *context)
{
atomic_inc(&context->notifier_count);
}
static void ib_ucontext_notifier_end_account(struct ib_ucontext *context)
{
int zero_notifiers = atomic_dec_and_test(&context->notifier_count);
if (zero_notifiers &&
!list_empty(&context->no_private_counters)) {
struct ib_umem_odp *odp_data, *next;
down_write(&context->umem_rwsem);
if (!atomic_read(&context->notifier_count)) {
list_for_each_entry_safe(odp_data, next,
&context->no_private_counters,
no_private_counters) {
mutex_lock(&odp_data->umem_mutex);
odp_data->mn_counters_active = true;
list_del(&odp_data->no_private_counters);
complete_all(&odp_data->notifier_completion);
mutex_unlock(&odp_data->umem_mutex);
}
}
up_write(&context->umem_rwsem);
}
}
static int ib_umem_notifier_release_trampoline(struct ib_umem *item, u64 start,
u64 end, void *cookie) {
ib_umem_notifier_start_account(item);
item->odp_data->dying = 1;
smp_wmb();
complete_all(&item->odp_data->notifier_completion);
item->context->invalidate_range(item, ib_umem_start(item),
ib_umem_end(item));
return 0;
}
static void ib_umem_notifier_release(struct mmu_notifier *mn,
struct mm_struct *mm)
{
struct ib_ucontext *context = container_of(mn, struct ib_ucontext, mn);
if (!context->invalidate_range)
return;
ib_ucontext_notifier_start_account(context);
down_read(&context->umem_rwsem);
rbt_ib_umem_for_each_in_range(&context->umem_tree, 0,
ULLONG_MAX,
ib_umem_notifier_release_trampoline,
NULL);
up_read(&context->umem_rwsem);
}
static int invalidate_page_trampoline(struct ib_umem *item, u64 start,
u64 end, void *cookie)
{
ib_umem_notifier_start_account(item);
item->context->invalidate_range(item, start, start + PAGE_SIZE);
ib_umem_notifier_end_account(item);
return 0;
}
static void ib_umem_notifier_invalidate_page(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
struct ib_ucontext *context = container_of(mn, struct ib_ucontext, mn);
if (!context->invalidate_range)
return;
ib_ucontext_notifier_start_account(context);
down_read(&context->umem_rwsem);
rbt_ib_umem_for_each_in_range(&context->umem_tree, address,
address + PAGE_SIZE,
invalidate_page_trampoline, NULL);
up_read(&context->umem_rwsem);
ib_ucontext_notifier_end_account(context);
}
static int invalidate_range_start_trampoline(struct ib_umem *item, u64 start,
u64 end, void *cookie)
{
ib_umem_notifier_start_account(item);
item->context->invalidate_range(item, start, end);
return 0;
}
static void ib_umem_notifier_invalidate_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct ib_ucontext *context = container_of(mn, struct ib_ucontext, mn);
if (!context->invalidate_range)
return;
ib_ucontext_notifier_start_account(context);
down_read(&context->umem_rwsem);
rbt_ib_umem_for_each_in_range(&context->umem_tree, start,
end,
invalidate_range_start_trampoline, NULL);
up_read(&context->umem_rwsem);
}
static int invalidate_range_end_trampoline(struct ib_umem *item, u64 start,
u64 end, void *cookie)
{
ib_umem_notifier_end_account(item);
return 0;
}
static void ib_umem_notifier_invalidate_range_end(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct ib_ucontext *context = container_of(mn, struct ib_ucontext, mn);
if (!context->invalidate_range)
return;
down_read(&context->umem_rwsem);
rbt_ib_umem_for_each_in_range(&context->umem_tree, start,
end,
invalidate_range_end_trampoline, NULL);
up_read(&context->umem_rwsem);
ib_ucontext_notifier_end_account(context);
}
int ib_umem_odp_get(struct ib_ucontext *context, struct ib_umem *umem)
{
int ret_val;
struct pid *our_pid;
struct mm_struct *mm = get_task_mm(current);
if (!mm)
return -EINVAL;
rcu_read_lock();
our_pid = get_task_pid(current->group_leader, PIDTYPE_PID);
rcu_read_unlock();
put_pid(our_pid);
if (context->tgid != our_pid) {
ret_val = -EINVAL;
goto out_mm;
}
umem->hugetlb = 0;
umem->odp_data = kzalloc(sizeof(*umem->odp_data), GFP_KERNEL);
if (!umem->odp_data) {
ret_val = -ENOMEM;
goto out_mm;
}
umem->odp_data->umem = umem;
mutex_init(&umem->odp_data->umem_mutex);
init_completion(&umem->odp_data->notifier_completion);
umem->odp_data->page_list = vzalloc(ib_umem_num_pages(umem) *
sizeof(*umem->odp_data->page_list));
if (!umem->odp_data->page_list) {
ret_val = -ENOMEM;
goto out_odp_data;
}
umem->odp_data->dma_list = vzalloc(ib_umem_num_pages(umem) *
sizeof(*umem->odp_data->dma_list));
if (!umem->odp_data->dma_list) {
ret_val = -ENOMEM;
goto out_page_list;
}
down_write(&context->umem_rwsem);
context->odp_mrs_count++;
if (likely(ib_umem_start(umem) != ib_umem_end(umem)))
rbt_ib_umem_insert(&umem->odp_data->interval_tree,
&context->umem_tree);
if (likely(!atomic_read(&context->notifier_count)) ||
context->odp_mrs_count == 1)
umem->odp_data->mn_counters_active = true;
else
list_add(&umem->odp_data->no_private_counters,
&context->no_private_counters);
downgrade_write(&context->umem_rwsem);
if (context->odp_mrs_count == 1) {
atomic_set(&context->notifier_count, 0);
INIT_HLIST_NODE(&context->mn.hlist);
context->mn.ops = &ib_umem_notifiers;
lockdep_off();
ret_val = mmu_notifier_register(&context->mn, mm);
lockdep_on();
if (ret_val) {
pr_err("Failed to register mmu_notifier %d\n", ret_val);
ret_val = -EBUSY;
goto out_mutex;
}
}
up_read(&context->umem_rwsem);
mmput(mm);
return 0;
out_mutex:
up_read(&context->umem_rwsem);
vfree(umem->odp_data->dma_list);
out_page_list:
vfree(umem->odp_data->page_list);
out_odp_data:
kfree(umem->odp_data);
out_mm:
mmput(mm);
return ret_val;
}
void ib_umem_odp_release(struct ib_umem *umem)
{
struct ib_ucontext *context = umem->context;
ib_umem_odp_unmap_dma_pages(umem, ib_umem_start(umem),
ib_umem_end(umem));
down_write(&context->umem_rwsem);
if (likely(ib_umem_start(umem) != ib_umem_end(umem)))
rbt_ib_umem_remove(&umem->odp_data->interval_tree,
&context->umem_tree);
context->odp_mrs_count--;
if (!umem->odp_data->mn_counters_active) {
list_del(&umem->odp_data->no_private_counters);
complete_all(&umem->odp_data->notifier_completion);
}
downgrade_write(&context->umem_rwsem);
if (!context->odp_mrs_count) {
struct task_struct *owning_process = NULL;
struct mm_struct *owning_mm = NULL;
owning_process = get_pid_task(context->tgid,
PIDTYPE_PID);
if (owning_process == NULL)
goto out;
owning_mm = get_task_mm(owning_process);
if (owning_mm == NULL)
goto out_put_task;
mmu_notifier_unregister(&context->mn, owning_mm);
mmput(owning_mm);
out_put_task:
put_task_struct(owning_process);
}
out:
up_read(&context->umem_rwsem);
vfree(umem->odp_data->dma_list);
vfree(umem->odp_data->page_list);
kfree(umem->odp_data);
kfree(umem);
}
static int ib_umem_odp_map_dma_single_page(
struct ib_umem *umem,
int page_index,
u64 base_virt_addr,
struct page *page,
u64 access_mask,
unsigned long current_seq)
{
struct ib_device *dev = umem->context->device;
dma_addr_t dma_addr;
int stored_page = 0;
int remove_existing_mapping = 0;
int ret = 0;
mutex_lock(&umem->odp_data->umem_mutex);
if (ib_umem_mmu_notifier_retry(umem, current_seq)) {
ret = -EAGAIN;
goto out;
}
if (!(umem->odp_data->dma_list[page_index])) {
dma_addr = ib_dma_map_page(dev,
page,
0, PAGE_SIZE,
DMA_BIDIRECTIONAL);
if (ib_dma_mapping_error(dev, dma_addr)) {
ret = -EFAULT;
goto out;
}
umem->odp_data->dma_list[page_index] = dma_addr | access_mask;
umem->odp_data->page_list[page_index] = page;
stored_page = 1;
} else if (umem->odp_data->page_list[page_index] == page) {
umem->odp_data->dma_list[page_index] |= access_mask;
} else {
pr_err("error: got different pages in IB device and from get_user_pages. IB device page: %p, gup page: %p\n",
umem->odp_data->page_list[page_index], page);
remove_existing_mapping = 1;
}
out:
mutex_unlock(&umem->odp_data->umem_mutex);
if (umem->context->invalidate_range || !stored_page)
put_page(page);
if (remove_existing_mapping && umem->context->invalidate_range) {
invalidate_page_trampoline(
umem,
base_virt_addr + (page_index * PAGE_SIZE),
base_virt_addr + ((page_index+1)*PAGE_SIZE),
NULL);
ret = -EAGAIN;
}
return ret;
}
int ib_umem_odp_map_dma_pages(struct ib_umem *umem, u64 user_virt, u64 bcnt,
u64 access_mask, unsigned long current_seq)
{
struct task_struct *owning_process = NULL;
struct mm_struct *owning_mm = NULL;
struct page **local_page_list = NULL;
u64 off;
int j, k, ret = 0, start_idx, npages = 0;
u64 base_virt_addr;
if (access_mask == 0)
return -EINVAL;
if (user_virt < ib_umem_start(umem) ||
user_virt + bcnt > ib_umem_end(umem))
return -EFAULT;
local_page_list = (struct page **)__get_free_page(GFP_KERNEL);
if (!local_page_list)
return -ENOMEM;
off = user_virt & (~PAGE_MASK);
user_virt = user_virt & PAGE_MASK;
base_virt_addr = user_virt;
bcnt += off;
owning_process = get_pid_task(umem->context->tgid, PIDTYPE_PID);
if (owning_process == NULL) {
ret = -EINVAL;
goto out_no_task;
}
owning_mm = get_task_mm(owning_process);
if (owning_mm == NULL) {
ret = -EINVAL;
goto out_put_task;
}
start_idx = (user_virt - ib_umem_start(umem)) >> PAGE_SHIFT;
k = start_idx;
while (bcnt > 0) {
const size_t gup_num_pages =
min_t(size_t, ALIGN(bcnt, PAGE_SIZE) / PAGE_SIZE,
PAGE_SIZE / sizeof(struct page *));
down_read(&owning_mm->mmap_sem);
npages = get_user_pages(owning_process, owning_mm, user_virt,
gup_num_pages,
access_mask & ODP_WRITE_ALLOWED_BIT, 0,
local_page_list, NULL);
up_read(&owning_mm->mmap_sem);
if (npages < 0)
break;
bcnt -= min_t(size_t, npages << PAGE_SHIFT, bcnt);
user_virt += npages << PAGE_SHIFT;
for (j = 0; j < npages; ++j) {
ret = ib_umem_odp_map_dma_single_page(
umem, k, base_virt_addr, local_page_list[j],
access_mask, current_seq);
if (ret < 0)
break;
k++;
}
if (ret < 0) {
for (++j; j < npages; ++j)
put_page(local_page_list[j]);
break;
}
}
if (ret >= 0) {
if (npages < 0 && k == start_idx)
ret = npages;
else
ret = k - start_idx;
}
mmput(owning_mm);
out_put_task:
put_task_struct(owning_process);
out_no_task:
free_page((unsigned long)local_page_list);
return ret;
}
void ib_umem_odp_unmap_dma_pages(struct ib_umem *umem, u64 virt,
u64 bound)
{
int idx;
u64 addr;
struct ib_device *dev = umem->context->device;
virt = max_t(u64, virt, ib_umem_start(umem));
bound = min_t(u64, bound, ib_umem_end(umem));
for (addr = virt; addr < bound; addr += (u64)umem->page_size) {
idx = (addr - ib_umem_start(umem)) / PAGE_SIZE;
mutex_lock(&umem->odp_data->umem_mutex);
if (umem->odp_data->page_list[idx]) {
struct page *page = umem->odp_data->page_list[idx];
struct page *head_page = compound_head(page);
dma_addr_t dma = umem->odp_data->dma_list[idx];
dma_addr_t dma_addr = dma & ODP_DMA_ADDR_MASK;
WARN_ON(!dma_addr);
ib_dma_unmap_page(dev, dma_addr, PAGE_SIZE,
DMA_BIDIRECTIONAL);
if (dma & ODP_WRITE_ALLOWED_BIT)
set_page_dirty(head_page);
if (!umem->context->invalidate_range)
put_page(page);
umem->odp_data->page_list[idx] = NULL;
umem->odp_data->dma_list[idx] = 0;
}
mutex_unlock(&umem->odp_data->umem_mutex);
}
}
