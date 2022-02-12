static u64 vmballoon_batch_get_pa(struct vmballoon_batch_page *batch, int idx)
{
return batch->pages[idx] & VMW_BALLOON_BATCH_PAGE_MASK;
}
static int vmballoon_batch_get_status(struct vmballoon_batch_page *batch,
int idx)
{
return (int)(batch->pages[idx] & VMW_BALLOON_BATCH_STATUS_MASK);
}
static void vmballoon_batch_set_pa(struct vmballoon_batch_page *batch, int idx,
u64 pa)
{
batch->pages[idx] = pa;
}
static bool vmballoon_send_start(struct vmballoon *b, unsigned long req_caps)
{
unsigned long status, capabilities, dummy = 0;
bool success;
STATS_INC(b->stats.start);
status = VMWARE_BALLOON_CMD(START, req_caps, dummy, capabilities);
switch (status) {
case VMW_BALLOON_SUCCESS_WITH_CAPABILITIES:
b->capabilities = capabilities;
success = true;
break;
case VMW_BALLOON_SUCCESS:
b->capabilities = VMW_BALLOON_BASIC_CMDS;
success = true;
break;
default:
success = false;
}
if (b->capabilities & VMW_BALLOON_BATCHED_2M_CMDS)
b->supported_page_sizes = 2;
else
b->supported_page_sizes = 1;
if (!success) {
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.start_fail);
}
return success;
}
static bool vmballoon_check_status(struct vmballoon *b, unsigned long status)
{
switch (status) {
case VMW_BALLOON_SUCCESS:
return true;
case VMW_BALLOON_ERROR_RESET:
b->reset_required = true;
default:
return false;
}
}
static bool vmballoon_send_guest_id(struct vmballoon *b)
{
unsigned long status, dummy = 0;
status = VMWARE_BALLOON_CMD(GUEST_ID, VMW_BALLOON_GUEST_ID, dummy,
dummy);
STATS_INC(b->stats.guest_type);
if (vmballoon_check_status(b, status))
return true;
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.guest_type_fail);
return false;
}
static u16 vmballoon_page_size(bool is_2m_page)
{
if (is_2m_page)
return 1 << VMW_BALLOON_2M_SHIFT;
return 1;
}
static bool vmballoon_send_get_target(struct vmballoon *b, u32 *new_target)
{
unsigned long status;
unsigned long target;
unsigned long limit;
unsigned long dummy = 0;
u32 limit32;
si_meminfo(&b->sysinfo);
limit = b->sysinfo.totalram;
limit32 = (u32)limit;
if (limit != limit32)
return false;
STATS_INC(b->stats.target);
status = VMWARE_BALLOON_CMD(GET_TARGET, limit, dummy, target);
if (vmballoon_check_status(b, status)) {
*new_target = target;
return true;
}
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.target_fail);
return false;
}
static int vmballoon_send_lock_page(struct vmballoon *b, unsigned long pfn,
unsigned int *hv_status, unsigned int *target)
{
unsigned long status, dummy = 0;
u32 pfn32;
pfn32 = (u32)pfn;
if (pfn32 != pfn)
return -1;
STATS_INC(b->stats.lock[false]);
*hv_status = status = VMWARE_BALLOON_CMD(LOCK, pfn, dummy, *target);
if (vmballoon_check_status(b, status))
return 0;
pr_debug("%s - ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.lock_fail[false]);
return 1;
}
static int vmballoon_send_batched_lock(struct vmballoon *b,
unsigned int num_pages, bool is_2m_pages, unsigned int *target)
{
unsigned long status;
unsigned long pfn = page_to_pfn(b->page);
STATS_INC(b->stats.lock[is_2m_pages]);
if (is_2m_pages)
status = VMWARE_BALLOON_CMD(BATCHED_2M_LOCK, pfn, num_pages,
*target);
else
status = VMWARE_BALLOON_CMD(BATCHED_LOCK, pfn, num_pages,
*target);
if (vmballoon_check_status(b, status))
return 0;
pr_debug("%s - batch ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.lock_fail[is_2m_pages]);
return 1;
}
static bool vmballoon_send_unlock_page(struct vmballoon *b, unsigned long pfn,
unsigned int *target)
{
unsigned long status, dummy = 0;
u32 pfn32;
pfn32 = (u32)pfn;
if (pfn32 != pfn)
return false;
STATS_INC(b->stats.unlock[false]);
status = VMWARE_BALLOON_CMD(UNLOCK, pfn, dummy, *target);
if (vmballoon_check_status(b, status))
return true;
pr_debug("%s - ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.unlock_fail[false]);
return false;
}
static bool vmballoon_send_batched_unlock(struct vmballoon *b,
unsigned int num_pages, bool is_2m_pages, unsigned int *target)
{
unsigned long status;
unsigned long pfn = page_to_pfn(b->page);
STATS_INC(b->stats.unlock[is_2m_pages]);
if (is_2m_pages)
status = VMWARE_BALLOON_CMD(BATCHED_2M_UNLOCK, pfn, num_pages,
*target);
else
status = VMWARE_BALLOON_CMD(BATCHED_UNLOCK, pfn, num_pages,
*target);
if (vmballoon_check_status(b, status))
return true;
pr_debug("%s - batch ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.unlock_fail[is_2m_pages]);
return false;
}
static struct page *vmballoon_alloc_page(gfp_t flags, bool is_2m_page)
{
if (is_2m_page)
return alloc_pages(flags, VMW_BALLOON_2M_SHIFT);
return alloc_page(flags);
}
static void vmballoon_free_page(struct page *page, bool is_2m_page)
{
if (is_2m_page)
__free_pages(page, VMW_BALLOON_2M_SHIFT);
else
__free_page(page);
}
static void vmballoon_pop(struct vmballoon *b)
{
struct page *page, *next;
unsigned is_2m_pages;
for (is_2m_pages = 0; is_2m_pages < VMW_BALLOON_NUM_PAGE_SIZES;
is_2m_pages++) {
struct vmballoon_page_size *page_size =
&b->page_sizes[is_2m_pages];
u16 size_per_page = vmballoon_page_size(is_2m_pages);
list_for_each_entry_safe(page, next, &page_size->pages, lru) {
list_del(&page->lru);
vmballoon_free_page(page, is_2m_pages);
STATS_INC(b->stats.free[is_2m_pages]);
b->size -= size_per_page;
cond_resched();
}
}
if (b->batch_page) {
vunmap(b->batch_page);
b->batch_page = NULL;
}
if (b->page) {
__free_page(b->page);
b->page = NULL;
}
}
static int vmballoon_lock_page(struct vmballoon *b, unsigned int num_pages,
bool is_2m_pages, unsigned int *target)
{
int locked, hv_status;
struct page *page = b->page;
struct vmballoon_page_size *page_size = &b->page_sizes[false];
locked = vmballoon_send_lock_page(b, page_to_pfn(page), &hv_status,
target);
if (locked > 0) {
STATS_INC(b->stats.refused_alloc[false]);
if (hv_status == VMW_BALLOON_ERROR_RESET ||
hv_status == VMW_BALLOON_ERROR_PPN_NOTNEEDED) {
vmballoon_free_page(page, false);
return -EIO;
}
if (page_size->n_refused_pages < VMW_BALLOON_MAX_REFUSED) {
page_size->n_refused_pages++;
list_add(&page->lru, &page_size->refused_pages);
} else {
vmballoon_free_page(page, false);
}
return -EIO;
}
list_add(&page->lru, &page_size->pages);
b->size++;
return 0;
}
static int vmballoon_lock_batched_page(struct vmballoon *b,
unsigned int num_pages, bool is_2m_pages, unsigned int *target)
{
int locked, i;
u16 size_per_page = vmballoon_page_size(is_2m_pages);
locked = vmballoon_send_batched_lock(b, num_pages, is_2m_pages,
target);
if (locked > 0) {
for (i = 0; i < num_pages; i++) {
u64 pa = vmballoon_batch_get_pa(b->batch_page, i);
struct page *p = pfn_to_page(pa >> PAGE_SHIFT);
vmballoon_free_page(p, is_2m_pages);
}
return -EIO;
}
for (i = 0; i < num_pages; i++) {
u64 pa = vmballoon_batch_get_pa(b->batch_page, i);
struct page *p = pfn_to_page(pa >> PAGE_SHIFT);
struct vmballoon_page_size *page_size =
&b->page_sizes[is_2m_pages];
locked = vmballoon_batch_get_status(b->batch_page, i);
switch (locked) {
case VMW_BALLOON_SUCCESS:
list_add(&p->lru, &page_size->pages);
b->size += size_per_page;
break;
case VMW_BALLOON_ERROR_PPN_PINNED:
case VMW_BALLOON_ERROR_PPN_INVALID:
if (page_size->n_refused_pages
< VMW_BALLOON_MAX_REFUSED) {
list_add(&p->lru, &page_size->refused_pages);
page_size->n_refused_pages++;
break;
}
case VMW_BALLOON_ERROR_RESET:
case VMW_BALLOON_ERROR_PPN_NOTNEEDED:
vmballoon_free_page(p, is_2m_pages);
break;
default:
WARN_ON_ONCE(true);
}
}
return 0;
}
static int vmballoon_unlock_page(struct vmballoon *b, unsigned int num_pages,
bool is_2m_pages, unsigned int *target)
{
struct page *page = b->page;
struct vmballoon_page_size *page_size = &b->page_sizes[false];
if (!vmballoon_send_unlock_page(b, page_to_pfn(page), target)) {
list_add(&page->lru, &page_size->pages);
return -EIO;
}
vmballoon_free_page(page, false);
STATS_INC(b->stats.free[false]);
b->size--;
return 0;
}
static int vmballoon_unlock_batched_page(struct vmballoon *b,
unsigned int num_pages, bool is_2m_pages,
unsigned int *target)
{
int locked, i, ret = 0;
bool hv_success;
u16 size_per_page = vmballoon_page_size(is_2m_pages);
hv_success = vmballoon_send_batched_unlock(b, num_pages, is_2m_pages,
target);
if (!hv_success)
ret = -EIO;
for (i = 0; i < num_pages; i++) {
u64 pa = vmballoon_batch_get_pa(b->batch_page, i);
struct page *p = pfn_to_page(pa >> PAGE_SHIFT);
struct vmballoon_page_size *page_size =
&b->page_sizes[is_2m_pages];
locked = vmballoon_batch_get_status(b->batch_page, i);
if (!hv_success || locked != VMW_BALLOON_SUCCESS) {
list_add(&p->lru, &page_size->pages);
} else {
vmballoon_free_page(p, is_2m_pages);
STATS_INC(b->stats.free[is_2m_pages]);
b->size -= size_per_page;
}
}
return ret;
}
static void vmballoon_release_refused_pages(struct vmballoon *b,
bool is_2m_pages)
{
struct page *page, *next;
struct vmballoon_page_size *page_size =
&b->page_sizes[is_2m_pages];
list_for_each_entry_safe(page, next, &page_size->refused_pages, lru) {
list_del(&page->lru);
vmballoon_free_page(page, is_2m_pages);
STATS_INC(b->stats.refused_free[is_2m_pages]);
}
page_size->n_refused_pages = 0;
}
static void vmballoon_add_page(struct vmballoon *b, int idx, struct page *p)
{
b->page = p;
}
static void vmballoon_add_batched_page(struct vmballoon *b, int idx,
struct page *p)
{
vmballoon_batch_set_pa(b->batch_page, idx,
(u64)page_to_pfn(p) << PAGE_SHIFT);
}
static void vmballoon_inflate(struct vmballoon *b)
{
unsigned rate;
unsigned int allocations = 0;
unsigned int num_pages = 0;
int error = 0;
gfp_t flags = VMW_PAGE_ALLOC_NOSLEEP;
bool is_2m_pages;
pr_debug("%s - size: %d, target %d\n", __func__, b->size, b->target);
if (b->slow_allocation_cycles) {
rate = b->rate_alloc;
is_2m_pages = false;
} else {
rate = UINT_MAX;
is_2m_pages =
b->supported_page_sizes == VMW_BALLOON_NUM_PAGE_SIZES;
}
pr_debug("%s - goal: %d, no-sleep rate: %u, sleep rate: %d\n",
__func__, b->target - b->size, rate, b->rate_alloc);
while (!b->reset_required &&
b->size + num_pages * vmballoon_page_size(is_2m_pages)
< b->target) {
struct page *page;
if (flags == VMW_PAGE_ALLOC_NOSLEEP)
STATS_INC(b->stats.alloc[is_2m_pages]);
else
STATS_INC(b->stats.sleep_alloc);
page = vmballoon_alloc_page(flags, is_2m_pages);
if (!page) {
STATS_INC(b->stats.alloc_fail[is_2m_pages]);
if (is_2m_pages) {
b->ops->lock(b, num_pages, true, &b->target);
num_pages = 0;
is_2m_pages = false;
continue;
}
if (flags == VMW_PAGE_ALLOC_CANSLEEP) {
b->rate_alloc = max(b->rate_alloc / 2,
VMW_BALLOON_RATE_ALLOC_MIN);
STATS_INC(b->stats.sleep_alloc_fail);
break;
}
b->slow_allocation_cycles = VMW_BALLOON_SLOW_CYCLES;
if (allocations >= b->rate_alloc)
break;
flags = VMW_PAGE_ALLOC_CANSLEEP;
rate = b->rate_alloc;
continue;
}
b->ops->add_page(b, num_pages++, page);
if (num_pages == b->batch_max_pages) {
error = b->ops->lock(b, num_pages, is_2m_pages,
&b->target);
num_pages = 0;
if (error)
break;
}
cond_resched();
if (allocations >= rate) {
break;
}
}
if (num_pages > 0)
b->ops->lock(b, num_pages, is_2m_pages, &b->target);
if (error == 0 && allocations >= b->rate_alloc) {
unsigned int mult = allocations / b->rate_alloc;
b->rate_alloc =
min(b->rate_alloc + mult * VMW_BALLOON_RATE_ALLOC_INC,
VMW_BALLOON_RATE_ALLOC_MAX);
}
vmballoon_release_refused_pages(b, true);
vmballoon_release_refused_pages(b, false);
}
static void vmballoon_deflate(struct vmballoon *b)
{
unsigned is_2m_pages;
pr_debug("%s - size: %d, target %d\n", __func__, b->size, b->target);
for (is_2m_pages = 0; is_2m_pages < b->supported_page_sizes;
is_2m_pages++) {
struct page *page, *next;
unsigned int num_pages = 0;
struct vmballoon_page_size *page_size =
&b->page_sizes[is_2m_pages];
list_for_each_entry_safe(page, next, &page_size->pages, lru) {
if (b->reset_required ||
(b->target > 0 &&
b->size - num_pages
* vmballoon_page_size(is_2m_pages)
< b->target + vmballoon_page_size(true)))
break;
list_del(&page->lru);
b->ops->add_page(b, num_pages++, page);
if (num_pages == b->batch_max_pages) {
int error;
error = b->ops->unlock(b, num_pages,
is_2m_pages, &b->target);
num_pages = 0;
if (error)
return;
}
cond_resched();
}
if (num_pages > 0)
b->ops->unlock(b, num_pages, is_2m_pages, &b->target);
}
}
static bool vmballoon_init_batching(struct vmballoon *b)
{
b->page = alloc_page(VMW_PAGE_ALLOC_NOSLEEP);
if (!b->page)
return false;
b->batch_page = vmap(&b->page, 1, VM_MAP, PAGE_KERNEL);
if (!b->batch_page) {
__free_page(b->page);
return false;
}
return true;
}
static void vmballoon_doorbell(void *client_data)
{
struct vmballoon *b = client_data;
STATS_INC(b->stats.doorbell);
mod_delayed_work(system_freezable_wq, &b->dwork, 0);
}
static void vmballoon_vmci_cleanup(struct vmballoon *b)
{
int error;
VMWARE_BALLOON_CMD(VMCI_DOORBELL_SET, VMCI_INVALID_ID,
VMCI_INVALID_ID, error);
STATS_INC(b->stats.doorbell_unset);
if (!vmci_handle_is_invalid(b->vmci_doorbell)) {
vmci_doorbell_destroy(b->vmci_doorbell);
b->vmci_doorbell = VMCI_INVALID_HANDLE;
}
}
static int vmballoon_vmci_init(struct vmballoon *b)
{
int error = 0;
if ((b->capabilities & VMW_BALLOON_SIGNALLED_WAKEUP_CMD) != 0) {
error = vmci_doorbell_create(&b->vmci_doorbell,
VMCI_FLAG_DELAYED_CB,
VMCI_PRIVILEGE_FLAG_RESTRICTED,
vmballoon_doorbell, b);
if (error == VMCI_SUCCESS) {
VMWARE_BALLOON_CMD(VMCI_DOORBELL_SET,
b->vmci_doorbell.context,
b->vmci_doorbell.resource, error);
STATS_INC(b->stats.doorbell_set);
}
}
if (error != 0) {
vmballoon_vmci_cleanup(b);
return -EIO;
}
return 0;
}
static void vmballoon_reset(struct vmballoon *b)
{
int error;
vmballoon_vmci_cleanup(b);
vmballoon_pop(b);
if (!vmballoon_send_start(b, VMW_BALLOON_CAPABILITIES))
return;
if ((b->capabilities & VMW_BALLOON_BATCHED_CMDS) != 0) {
b->ops = &vmballoon_batched_ops;
b->batch_max_pages = VMW_BALLOON_BATCH_MAX_PAGES;
if (!vmballoon_init_batching(b)) {
vmballoon_send_start(b, 0);
return;
}
} else if ((b->capabilities & VMW_BALLOON_BASIC_CMDS) != 0) {
b->ops = &vmballoon_basic_ops;
b->batch_max_pages = 1;
}
b->reset_required = false;
error = vmballoon_vmci_init(b);
if (error)
pr_err("failed to initialize vmci doorbell\n");
if (!vmballoon_send_guest_id(b))
pr_err("failed to send guest ID to the host\n");
}
static void vmballoon_work(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct vmballoon *b = container_of(dwork, struct vmballoon, dwork);
unsigned int target;
STATS_INC(b->stats.timer);
if (b->reset_required)
vmballoon_reset(b);
if (b->slow_allocation_cycles > 0)
b->slow_allocation_cycles--;
if (!b->reset_required && vmballoon_send_get_target(b, &target)) {
b->target = target;
if (b->size < target)
vmballoon_inflate(b);
else if (target == 0 ||
b->size > target + vmballoon_page_size(true))
vmballoon_deflate(b);
}
queue_delayed_work(system_freezable_wq,
dwork, round_jiffies_relative(HZ));
}
static int vmballoon_debug_show(struct seq_file *f, void *offset)
{
struct vmballoon *b = f->private;
struct vmballoon_stats *stats = &b->stats;
seq_printf(f,
"balloon capabilities: %#4x\n"
"used capabilities: %#4lx\n"
"is resetting: %c\n",
VMW_BALLOON_CAPABILITIES, b->capabilities,
b->reset_required ? 'y' : 'n');
seq_printf(f,
"target: %8d pages\n"
"current: %8d pages\n",
b->target, b->size);
seq_printf(f,
"rateSleepAlloc: %8d pages/sec\n",
b->rate_alloc);
seq_printf(f,
"\n"
"timer: %8u\n"
"doorbell: %8u\n"
"start: %8u (%4u failed)\n"
"guestType: %8u (%4u failed)\n"
"2m-lock: %8u (%4u failed)\n"
"lock: %8u (%4u failed)\n"
"2m-unlock: %8u (%4u failed)\n"
"unlock: %8u (%4u failed)\n"
"target: %8u (%4u failed)\n"
"prim2mAlloc: %8u (%4u failed)\n"
"primNoSleepAlloc: %8u (%4u failed)\n"
"primCanSleepAlloc: %8u (%4u failed)\n"
"prim2mFree: %8u\n"
"primFree: %8u\n"
"err2mAlloc: %8u\n"
"errAlloc: %8u\n"
"err2mFree: %8u\n"
"errFree: %8u\n"
"doorbellSet: %8u\n"
"doorbellUnset: %8u\n",
stats->timer,
stats->doorbell,
stats->start, stats->start_fail,
stats->guest_type, stats->guest_type_fail,
stats->lock[true], stats->lock_fail[true],
stats->lock[false], stats->lock_fail[false],
stats->unlock[true], stats->unlock_fail[true],
stats->unlock[false], stats->unlock_fail[false],
stats->target, stats->target_fail,
stats->alloc[true], stats->alloc_fail[true],
stats->alloc[false], stats->alloc_fail[false],
stats->sleep_alloc, stats->sleep_alloc_fail,
stats->free[true],
stats->free[false],
stats->refused_alloc[true], stats->refused_alloc[false],
stats->refused_free[true], stats->refused_free[false],
stats->doorbell_set, stats->doorbell_unset);
return 0;
}
static int vmballoon_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, vmballoon_debug_show, inode->i_private);
}
static int __init vmballoon_debugfs_init(struct vmballoon *b)
{
int error;
b->dbg_entry = debugfs_create_file("vmmemctl", S_IRUGO, NULL, b,
&vmballoon_debug_fops);
if (IS_ERR(b->dbg_entry)) {
error = PTR_ERR(b->dbg_entry);
pr_err("failed to create debugfs entry, error: %d\n", error);
return error;
}
return 0;
}
static void __exit vmballoon_debugfs_exit(struct vmballoon *b)
{
debugfs_remove(b->dbg_entry);
}
static inline int vmballoon_debugfs_init(struct vmballoon *b)
{
return 0;
}
static inline void vmballoon_debugfs_exit(struct vmballoon *b)
{
}
static int __init vmballoon_init(void)
{
int error;
unsigned is_2m_pages;
if (x86_hyper != &x86_hyper_vmware)
return -ENODEV;
for (is_2m_pages = 0; is_2m_pages < VMW_BALLOON_NUM_PAGE_SIZES;
is_2m_pages++) {
INIT_LIST_HEAD(&balloon.page_sizes[is_2m_pages].pages);
INIT_LIST_HEAD(&balloon.page_sizes[is_2m_pages].refused_pages);
}
balloon.rate_alloc = VMW_BALLOON_RATE_ALLOC_MAX;
INIT_DELAYED_WORK(&balloon.dwork, vmballoon_work);
error = vmballoon_debugfs_init(&balloon);
if (error)
return error;
balloon.vmci_doorbell = VMCI_INVALID_HANDLE;
balloon.batch_page = NULL;
balloon.page = NULL;
balloon.reset_required = true;
queue_delayed_work(system_freezable_wq, &balloon.dwork, 0);
return 0;
}
static void __exit vmballoon_exit(void)
{
vmballoon_vmci_cleanup(&balloon);
cancel_delayed_work_sync(&balloon.dwork);
vmballoon_debugfs_exit(&balloon);
vmballoon_send_start(&balloon, 0);
vmballoon_pop(&balloon);
}
