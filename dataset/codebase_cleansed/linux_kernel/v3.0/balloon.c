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
if (PageHighMem(page))
dec_totalhigh_pages();
totalram_pages--;
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
if (PageHighMem(page)) {
balloon_stats.balloon_high--;
inc_totalhigh_pages();
}
else
balloon_stats.balloon_low--;
totalram_pages++;
return page;
}
static struct page *balloon_first_page(void)
{
if (list_empty(&ballooned_pages))
return NULL;
return list_entry(ballooned_pages.next, struct page, lru);
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
unsigned long target = balloon_stats.target_pages;
target = min(target,
balloon_stats.current_pages +
balloon_stats.balloon_low +
balloon_stats.balloon_high);
return target - balloon_stats.current_pages;
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
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
page = balloon_first_page();
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
BUG_ON(!xen_feature(XENFEAT_auto_translated_physmap) &&
phys_to_machine_mapping_valid(pfn));
set_phys_to_machine(pfn, frame_list[i]);
if (xen_pv_domain() && !PageHighMem(page)) {
int ret;
ret = HYPERVISOR_update_va_mapping(
(unsigned long)__va(pfn << PAGE_SHIFT),
mfn_pte(frame_list[i], PAGE_KERNEL),
0);
BUG_ON(ret);
}
ClearPageReserved(page);
init_page_count(page);
__free_page(page);
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
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
for (i = 0; i < nr_pages; i++) {
if ((page = alloc_page(gfp)) == NULL) {
nr_pages = i;
state = BP_EAGAIN;
break;
}
pfn = page_to_pfn(page);
frame_list[i] = pfn_to_mfn(pfn);
scrub_page(page);
if (xen_pv_domain() && !PageHighMem(page)) {
ret = HYPERVISOR_update_va_mapping(
(unsigned long)__va(pfn << PAGE_SHIFT),
__pte_ma(0), 0);
BUG_ON(ret);
}
}
kmap_flush_unused();
flush_tlb_all();
for (i = 0; i < nr_pages; i++) {
pfn = mfn_to_pfn(frame_list[i]);
__set_phys_to_machine(pfn, INVALID_P2M_ENTRY);
balloon_append(pfn_to_page(pfn));
}
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
mutex_lock(&balloon_mutex);
do {
credit = current_credit();
if (credit > 0)
state = increase_reservation(credit);
if (credit < 0)
state = decrease_reservation(-credit, GFP_BALLOON);
state = update_schedule(state);
#ifndef CONFIG_PREEMPT
if (need_resched())
schedule();
#endif
} while (credit && state == BP_DONE);
if (state == BP_EAGAIN)
schedule_delayed_work(&balloon_worker, balloon_stats.schedule_delay * HZ);
mutex_unlock(&balloon_mutex);
}
void balloon_set_new_target(unsigned long target)
{
balloon_stats.target_pages = target;
schedule_delayed_work(&balloon_worker, 0);
}
int alloc_xenballooned_pages(int nr_pages, struct page** pages)
{
int pgno = 0;
struct page* page;
mutex_lock(&balloon_mutex);
while (pgno < nr_pages) {
page = balloon_retrieve(true);
if (page) {
pages[pgno++] = page;
} else {
enum bp_state st;
st = decrease_reservation(nr_pages - pgno, GFP_HIGHUSER);
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
void free_xenballooned_pages(int nr_pages, struct page** pages)
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
static int __init balloon_init(void)
{
unsigned long pfn, extra_pfn_end;
struct page *page;
if (!xen_domain())
return -ENODEV;
pr_info("xen/balloon: Initialising balloon driver.\n");
balloon_stats.current_pages = xen_pv_domain() ? min(xen_start_info->nr_pages, max_pfn) : max_pfn;
balloon_stats.target_pages = balloon_stats.current_pages;
balloon_stats.balloon_low = 0;
balloon_stats.balloon_high = 0;
balloon_stats.schedule_delay = 1;
balloon_stats.max_schedule_delay = 32;
balloon_stats.retry_count = 1;
balloon_stats.max_retry_count = RETRY_UNLIMITED;
extra_pfn_end = min(min(max_pfn, e820_end_of_ram_pfn()),
(unsigned long)PFN_DOWN(xen_extra_mem_start + xen_extra_mem_size));
for (pfn = PFN_UP(xen_extra_mem_start);
pfn < extra_pfn_end;
pfn++) {
page = pfn_to_page(pfn);
__balloon_append(page);
}
return 0;
}
