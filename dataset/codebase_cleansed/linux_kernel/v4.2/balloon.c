static void scrub_page(struct page *page)
{
#ifdef CONFIG_XEN_SCRUB_PAGES
clear_highpage(page);
#endif
}
static void __balloon_append(struct page *page)
{
if (PageHighMem(page)) {
list_add_tail(&page->lru, &ballooned_pages);
balloon_stats.balloon_high++;
} else {
list_add(&page->lru, &ballooned_pages);
balloon_stats.balloon_low++;
}
}
static void balloon_append(struct page *page)
{
__balloon_append(page);
adjust_managed_page_count(page, -1);
}
static struct page *balloon_retrieve(bool prefer_highmem)
{
struct page *page;
if (list_empty(&ballooned_pages))
return NULL;
if (prefer_highmem)
page = list_entry(ballooned_pages.prev, struct page, lru);
else
page = list_entry(ballooned_pages.next, struct page, lru);
list_del(&page->lru);
if (PageHighMem(page))
balloon_stats.balloon_high--;
else
balloon_stats.balloon_low--;
adjust_managed_page_count(page, 1);
return page;
}
static struct page *balloon_next_page(struct page *page)
{
struct list_head *next = page->lru.next;
if (next == &ballooned_pages)
return NULL;
return list_entry(next, struct page, lru);
}
static enum bp_state update_schedule(enum bp_state state)
{
if (state == BP_ECANCELED)
return BP_ECANCELED;
if (state == BP_DONE) {
balloon_stats.schedule_delay = 1;
balloon_stats.retry_count = 1;
return BP_DONE;
}
++balloon_stats.retry_count;
if (balloon_stats.max_retry_count != RETRY_UNLIMITED &&
balloon_stats.retry_count > balloon_stats.max_retry_count) {
balloon_stats.schedule_delay = 1;
balloon_stats.retry_count = 1;
return BP_ECANCELED;
}
balloon_stats.schedule_delay <<= 1;
if (balloon_stats.schedule_delay > balloon_stats.max_schedule_delay)
balloon_stats.schedule_delay = balloon_stats.max_schedule_delay;
return BP_EAGAIN;
}
static long current_credit(void)
{
return balloon_stats.target_pages - balloon_stats.current_pages -
balloon_stats.hotplug_pages;
}
static bool balloon_is_inflated(void)
{
if (balloon_stats.balloon_low || balloon_stats.balloon_high ||
balloon_stats.balloon_hotplug)
return true;
else
return false;
}
static enum bp_state reserve_additional_memory(long credit)
{
int nid, rc;
u64 hotplug_start_paddr;
unsigned long balloon_hotplug = credit;
hotplug_start_paddr = PFN_PHYS(SECTION_ALIGN_UP(max_pfn));
balloon_hotplug = round_up(balloon_hotplug, PAGES_PER_SECTION);
nid = memory_add_physaddr_to_nid(hotplug_start_paddr);
#ifdef CONFIG_XEN_HAVE_PVMMU
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
unsigned long pfn, i;
pfn = PFN_DOWN(hotplug_start_paddr);
for (i = 0; i < balloon_hotplug; i++) {
if (!set_phys_to_machine(pfn + i, INVALID_P2M_ENTRY)) {
pr_warn("set_phys_to_machine() failed, no memory added\n");
return BP_ECANCELED;
}
}
}
#endif
rc = add_memory(nid, hotplug_start_paddr, balloon_hotplug << PAGE_SHIFT);
if (rc) {
pr_warn("Cannot add additional memory (%i)\n", rc);
return BP_ECANCELED;
}
balloon_hotplug -= credit;
balloon_stats.hotplug_pages += credit;
balloon_stats.balloon_hotplug = balloon_hotplug;
return BP_DONE;
}
static void xen_online_page(struct page *page)
{
__online_page_set_limits(page);
mutex_lock(&balloon_mutex);
__balloon_append(page);
if (balloon_stats.hotplug_pages)
--balloon_stats.hotplug_pages;
else
--balloon_stats.balloon_hotplug;
mutex_unlock(&balloon_mutex);
}
static int xen_memory_notifier(struct notifier_block *nb, unsigned long val, void *v)
{
if (val == MEM_ONLINE)
schedule_delayed_work(&balloon_worker, 0);
return NOTIFY_OK;
}
static long current_credit(void)
{
unsigned long target = balloon_stats.target_pages;
target = min(target,
balloon_stats.current_pages +
balloon_stats.balloon_low +
balloon_stats.balloon_high);
return target - balloon_stats.current_pages;
}
static bool balloon_is_inflated(void)
{
if (balloon_stats.balloon_low || balloon_stats.balloon_high)
return true;
else
return false;
}
static enum bp_state reserve_additional_memory(long credit)
{
balloon_stats.target_pages = balloon_stats.current_pages;
return BP_DONE;
}
static enum bp_state increase_reservation(unsigned long nr_pages)
{
int rc;
unsigned long pfn, i;
struct page *page;
struct xen_memory_reservation reservation = {
.address_bits = 0,
.extent_order = 0,
.domid = DOMID_SELF
};
#ifdef CONFIG_XEN_BALLOON_MEMORY_HOTPLUG
if (!balloon_stats.balloon_low && !balloon_stats.balloon_high) {
nr_pages = min(nr_pages, balloon_stats.balloon_hotplug);
balloon_stats.hotplug_pages += nr_pages;
balloon_stats.balloon_hotplug -= nr_pages;
return BP_DONE;
}
#endif
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
page = list_first_entry_or_null(&ballooned_pages, struct page, lru);
for (i = 0; i < nr_pages; i++) {
if (!page) {
nr_pages = i;
break;
}
frame_list[i] = page_to_pfn(page);
page = balloon_next_page(page);
}
set_xen_guest_handle(reservation.extent_start, frame_list);
reservation.nr_extents = nr_pages;
rc = HYPERVISOR_memory_op(XENMEM_populate_physmap, &reservation);
if (rc <= 0)
return BP_EAGAIN;
for (i = 0; i < rc; i++) {
page = balloon_retrieve(false);
BUG_ON(page == NULL);
pfn = page_to_pfn(page);
#ifdef CONFIG_XEN_HAVE_PVMMU
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
set_phys_to_machine(pfn, frame_list[i]);
if (!PageHighMem(page)) {
int ret;
ret = HYPERVISOR_update_va_mapping(
(unsigned long)__va(pfn << PAGE_SHIFT),
mfn_pte(frame_list[i], PAGE_KERNEL),
0);
BUG_ON(ret);
}
}
#endif
__free_reserved_page(page);
}
balloon_stats.current_pages += rc;
return BP_DONE;
}
static enum bp_state decrease_reservation(unsigned long nr_pages, gfp_t gfp)
{
enum bp_state state = BP_DONE;
unsigned long pfn, i;
struct page *page;
int ret;
struct xen_memory_reservation reservation = {
.address_bits = 0,
.extent_order = 0,
.domid = DOMID_SELF
};
#ifdef CONFIG_XEN_BALLOON_MEMORY_HOTPLUG
if (balloon_stats.hotplug_pages) {
nr_pages = min(nr_pages, balloon_stats.hotplug_pages);
balloon_stats.hotplug_pages -= nr_pages;
balloon_stats.balloon_hotplug += nr_pages;
return BP_DONE;
}
#endif
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
for (i = 0; i < nr_pages; i++) {
page = alloc_page(gfp);
if (page == NULL) {
nr_pages = i;
state = BP_EAGAIN;
break;
}
scrub_page(page);
frame_list[i] = page_to_pfn(page);
}
kmap_flush_unused();
for (i = 0; i < nr_pages; i++) {
pfn = frame_list[i];
frame_list[i] = pfn_to_mfn(pfn);
page = pfn_to_page(pfn);
#ifdef CONFIG_XEN_HAVE_PVMMU
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
if (!PageHighMem(page)) {
ret = HYPERVISOR_update_va_mapping(
(unsigned long)__va(pfn << PAGE_SHIFT),
__pte_ma(0), 0);
BUG_ON(ret);
}
__set_phys_to_machine(pfn, INVALID_P2M_ENTRY);
}
#endif
balloon_append(page);
}
flush_tlb_all();
set_xen_guest_handle(reservation.extent_start, frame_list);
reservation.nr_extents = nr_pages;
ret = HYPERVISOR_memory_op(XENMEM_decrease_reservation, &reservation);
BUG_ON(ret != nr_pages);
balloon_stats.current_pages -= nr_pages;
return state;
}
static void balloon_process(struct work_struct *work)
{
enum bp_state state = BP_DONE;
long credit;
do {
mutex_lock(&balloon_mutex);
credit = current_credit();
if (credit > 0) {
if (balloon_is_inflated())
state = increase_reservation(credit);
else
state = reserve_additional_memory(credit);
}
if (credit < 0)
state = decrease_reservation(-credit, GFP_BALLOON);
state = update_schedule(state);
mutex_unlock(&balloon_mutex);
cond_resched();
} while (credit && state == BP_DONE);
if (state == BP_EAGAIN)
schedule_delayed_work(&balloon_worker, balloon_stats.schedule_delay * HZ);
}
void balloon_set_new_target(unsigned long target)
{
balloon_stats.target_pages = target;
schedule_delayed_work(&balloon_worker, 0);
}
int alloc_xenballooned_pages(int nr_pages, struct page **pages, bool highmem)
{
int pgno = 0;
struct page *page;
mutex_lock(&balloon_mutex);
while (pgno < nr_pages) {
page = balloon_retrieve(highmem);
if (page && (highmem || !PageHighMem(page))) {
pages[pgno++] = page;
} else {
enum bp_state st;
if (page)
balloon_append(page);
st = decrease_reservation(nr_pages - pgno,
highmem ? GFP_HIGHUSER : GFP_USER);
if (st != BP_DONE)
goto out_undo;
}
}
mutex_unlock(&balloon_mutex);
return 0;
out_undo:
while (pgno)
balloon_append(pages[--pgno]);
schedule_delayed_work(&balloon_worker, 0);
mutex_unlock(&balloon_mutex);
return -ENOMEM;
}
void free_xenballooned_pages(int nr_pages, struct page **pages)
{
int i;
mutex_lock(&balloon_mutex);
for (i = 0; i < nr_pages; i++) {
if (pages[i])
balloon_append(pages[i]);
}
if (current_credit())
schedule_delayed_work(&balloon_worker, 0);
mutex_unlock(&balloon_mutex);
}
static void __init balloon_add_region(unsigned long start_pfn,
unsigned long pages)
{
unsigned long pfn, extra_pfn_end;
struct page *page;
extra_pfn_end = min(max_pfn, start_pfn + pages);
for (pfn = start_pfn; pfn < extra_pfn_end; pfn++) {
page = pfn_to_page(pfn);
__balloon_append(page);
}
}
static int __init balloon_init(void)
{
int i;
if (!xen_domain())
return -ENODEV;
pr_info("Initialising balloon driver\n");
balloon_stats.current_pages = xen_pv_domain()
? min(xen_start_info->nr_pages - xen_released_pages, max_pfn)
: get_num_physpages();
balloon_stats.target_pages = balloon_stats.current_pages;
balloon_stats.balloon_low = 0;
balloon_stats.balloon_high = 0;
balloon_stats.schedule_delay = 1;
balloon_stats.max_schedule_delay = 32;
balloon_stats.retry_count = 1;
balloon_stats.max_retry_count = RETRY_UNLIMITED;
#ifdef CONFIG_XEN_BALLOON_MEMORY_HOTPLUG
balloon_stats.hotplug_pages = 0;
balloon_stats.balloon_hotplug = 0;
set_online_page_callback(&xen_online_page);
register_memory_notifier(&xen_memory_nb);
#endif
for (i = 0; i < XEN_EXTRA_MEM_MAX_REGIONS; i++)
if (xen_extra_mem[i].size)
balloon_add_region(PFN_UP(xen_extra_mem[i].start),
PFN_DOWN(xen_extra_mem[i].size));
return 0;
}
