static bool vmballoon_send_start(struct vmballoon *b)
{
unsigned long status, dummy;
STATS_INC(b->stats.start);
status = VMWARE_BALLOON_CMD(START, VMW_BALLOON_PROTOCOL_VERSION, dummy);
if (status == VMW_BALLOON_SUCCESS)
return true;
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.start_fail);
return false;
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
unsigned long status, dummy;
status = VMWARE_BALLOON_CMD(GUEST_ID, VMW_BALLOON_GUEST_ID, dummy);
STATS_INC(b->stats.guest_type);
if (vmballoon_check_status(b, status))
return true;
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.guest_type_fail);
return false;
}
static bool vmballoon_send_get_target(struct vmballoon *b, u32 *new_target)
{
unsigned long status;
unsigned long target;
unsigned long limit;
u32 limit32;
si_meminfo(&b->sysinfo);
limit = b->sysinfo.totalram;
limit32 = (u32)limit;
if (limit != limit32)
return false;
STATS_INC(b->stats.target);
status = VMWARE_BALLOON_CMD(GET_TARGET, limit, target);
if (vmballoon_check_status(b, status)) {
*new_target = target;
return true;
}
pr_debug("%s - failed, hv returns %ld\n", __func__, status);
STATS_INC(b->stats.target_fail);
return false;
}
static int vmballoon_send_lock_page(struct vmballoon *b, unsigned long pfn,
unsigned int *hv_status)
{
unsigned long status, dummy;
u32 pfn32;
pfn32 = (u32)pfn;
if (pfn32 != pfn)
return -1;
STATS_INC(b->stats.lock);
*hv_status = status = VMWARE_BALLOON_CMD(LOCK, pfn, dummy);
if (vmballoon_check_status(b, status))
return 0;
pr_debug("%s - ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.lock_fail);
return 1;
}
static bool vmballoon_send_unlock_page(struct vmballoon *b, unsigned long pfn)
{
unsigned long status, dummy;
u32 pfn32;
pfn32 = (u32)pfn;
if (pfn32 != pfn)
return false;
STATS_INC(b->stats.unlock);
status = VMWARE_BALLOON_CMD(UNLOCK, pfn, dummy);
if (vmballoon_check_status(b, status))
return true;
pr_debug("%s - ppn %lx, hv returns %ld\n", __func__, pfn, status);
STATS_INC(b->stats.unlock_fail);
return false;
}
static void vmballoon_pop(struct vmballoon *b)
{
struct page *page, *next;
unsigned int count = 0;
list_for_each_entry_safe(page, next, &b->pages, lru) {
list_del(&page->lru);
__free_page(page);
STATS_INC(b->stats.free);
b->size--;
if (++count >= b->rate_free) {
count = 0;
cond_resched();
}
}
}
static void vmballoon_reset(struct vmballoon *b)
{
vmballoon_pop(b);
if (vmballoon_send_start(b)) {
b->reset_required = false;
if (!vmballoon_send_guest_id(b))
pr_err("failed to send guest ID to the host\n");
}
}
static int vmballoon_reserve_page(struct vmballoon *b, bool can_sleep)
{
struct page *page;
gfp_t flags;
unsigned int hv_status;
int locked;
flags = can_sleep ? VMW_PAGE_ALLOC_CANSLEEP : VMW_PAGE_ALLOC_NOSLEEP;
do {
if (!can_sleep)
STATS_INC(b->stats.alloc);
else
STATS_INC(b->stats.sleep_alloc);
page = alloc_page(flags);
if (!page) {
if (!can_sleep)
STATS_INC(b->stats.alloc_fail);
else
STATS_INC(b->stats.sleep_alloc_fail);
return -ENOMEM;
}
locked = vmballoon_send_lock_page(b, page_to_pfn(page), &hv_status);
if (locked > 0) {
STATS_INC(b->stats.refused_alloc);
if (hv_status == VMW_BALLOON_ERROR_RESET ||
hv_status == VMW_BALLOON_ERROR_PPN_NOTNEEDED) {
__free_page(page);
return -EIO;
}
list_add(&page->lru, &b->refused_pages);
if (++b->n_refused_pages >= VMW_BALLOON_MAX_REFUSED)
return -EIO;
}
} while (locked != 0);
list_add(&page->lru, &b->pages);
b->size++;
return 0;
}
static int vmballoon_release_page(struct vmballoon *b, struct page *page)
{
if (!vmballoon_send_unlock_page(b, page_to_pfn(page)))
return -EIO;
list_del(&page->lru);
__free_page(page);
STATS_INC(b->stats.free);
b->size--;
return 0;
}
static void vmballoon_release_refused_pages(struct vmballoon *b)
{
struct page *page, *next;
list_for_each_entry_safe(page, next, &b->refused_pages, lru) {
list_del(&page->lru);
__free_page(page);
STATS_INC(b->stats.refused_free);
}
b->n_refused_pages = 0;
}
static void vmballoon_inflate(struct vmballoon *b)
{
unsigned int goal;
unsigned int rate;
unsigned int i;
unsigned int allocations = 0;
int error = 0;
bool alloc_can_sleep = false;
pr_debug("%s - size: %d, target %d\n", __func__, b->size, b->target);
goal = b->target - b->size;
rate = b->slow_allocation_cycles ?
b->rate_alloc : VMW_BALLOON_NOSLEEP_ALLOC_MAX;
pr_debug("%s - goal: %d, no-sleep rate: %d, sleep rate: %d\n",
__func__, goal, rate, b->rate_alloc);
for (i = 0; i < goal; i++) {
error = vmballoon_reserve_page(b, alloc_can_sleep);
if (error) {
if (error != -ENOMEM) {
break;
}
if (alloc_can_sleep) {
b->rate_alloc = max(b->rate_alloc / 2,
VMW_BALLOON_RATE_ALLOC_MIN);
break;
}
b->slow_allocation_cycles = VMW_BALLOON_SLOW_CYCLES;
if (i >= b->rate_alloc)
break;
alloc_can_sleep = true;
rate = b->rate_alloc;
}
if (++allocations > VMW_BALLOON_YIELD_THRESHOLD) {
cond_resched();
allocations = 0;
}
if (i >= rate) {
break;
}
}
if (error == 0 && i >= b->rate_alloc) {
unsigned int mult = i / b->rate_alloc;
b->rate_alloc =
min(b->rate_alloc + mult * VMW_BALLOON_RATE_ALLOC_INC,
VMW_BALLOON_RATE_ALLOC_MAX);
}
vmballoon_release_refused_pages(b);
}
static void vmballoon_deflate(struct vmballoon *b)
{
struct page *page, *next;
unsigned int i = 0;
unsigned int goal;
int error;
pr_debug("%s - size: %d, target %d\n", __func__, b->size, b->target);
goal = min(b->size - b->target, b->rate_free);
pr_debug("%s - goal: %d, rate: %d\n", __func__, goal, b->rate_free);
list_for_each_entry_safe(page, next, &b->pages, lru) {
error = vmballoon_release_page(b, page);
if (error) {
b->rate_free = max(b->rate_free / 2,
VMW_BALLOON_RATE_FREE_MIN);
return;
}
if (++i >= goal)
break;
}
b->rate_free = min(b->rate_free + VMW_BALLOON_RATE_FREE_INC,
VMW_BALLOON_RATE_FREE_MAX);
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
if (vmballoon_send_get_target(b, &target)) {
b->target = target;
if (b->size < target)
vmballoon_inflate(b);
else if (b->size > target)
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
"target: %8d pages\n"
"current: %8d pages\n",
b->target, b->size);
seq_printf(f,
"rateNoSleepAlloc: %8d pages/sec\n"
"rateSleepAlloc: %8d pages/sec\n"
"rateFree: %8d pages/sec\n",
VMW_BALLOON_NOSLEEP_ALLOC_MAX,
b->rate_alloc, b->rate_free);
seq_printf(f,
"\n"
"timer: %8u\n"
"start: %8u (%4u failed)\n"
"guestType: %8u (%4u failed)\n"
"lock: %8u (%4u failed)\n"
"unlock: %8u (%4u failed)\n"
"target: %8u (%4u failed)\n"
"primNoSleepAlloc: %8u (%4u failed)\n"
"primCanSleepAlloc: %8u (%4u failed)\n"
"primFree: %8u\n"
"errAlloc: %8u\n"
"errFree: %8u\n",
stats->timer,
stats->start, stats->start_fail,
stats->guest_type, stats->guest_type_fail,
stats->lock, stats->lock_fail,
stats->unlock, stats->unlock_fail,
stats->target, stats->target_fail,
stats->alloc, stats->alloc_fail,
stats->sleep_alloc, stats->sleep_alloc_fail,
stats->free,
stats->refused_alloc, stats->refused_free);
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
if (x86_hyper != &x86_hyper_vmware)
return -ENODEV;
INIT_LIST_HEAD(&balloon.pages);
INIT_LIST_HEAD(&balloon.refused_pages);
balloon.rate_alloc = VMW_BALLOON_RATE_ALLOC_MAX;
balloon.rate_free = VMW_BALLOON_RATE_FREE_MAX;
INIT_DELAYED_WORK(&balloon.dwork, vmballoon_work);
if (!vmballoon_send_start(&balloon)) {
pr_err("failed to send start command to the host\n");
return -EIO;
}
if (!vmballoon_send_guest_id(&balloon)) {
pr_err("failed to send guest ID to the host\n");
return -EIO;
}
error = vmballoon_debugfs_init(&balloon);
if (error)
return error;
queue_delayed_work(system_freezable_wq, &balloon.dwork, 0);
return 0;
}
static void __exit vmballoon_exit(void)
{
cancel_delayed_work_sync(&balloon.dwork);
vmballoon_debugfs_exit(&balloon);
vmballoon_send_start(&balloon);
vmballoon_pop(&balloon);
}
