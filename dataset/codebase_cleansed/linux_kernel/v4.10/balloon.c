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
wake_up(&balloon_wq);
}
static void balloon_append(struct page *page)
{
__balloon_append(page);
}
static struct page *balloon_retrieve(bool require_lowmem)
{
struct page *page;
if (list_empty(&ballooned_pages))
return NULL;
page = list_entry(ballooned_pages.next, struct page, lru);
if (require_lowmem && PageHighMem(page))
return NULL;
list_del(&page->lru);
if (PageHighMem(page))
balloon_stats.balloon_high--;
else
balloon_stats.balloon_low--;
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
if (state == BP_WAIT)
return BP_WAIT;
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
static void release_memory_resource(struct resource *resource)
{
if (!resource)
return;
release_resource(resource);
kfree(resource);
}
static struct resource *additional_memory_resource(phys_addr_t size)
{
struct resource *res;
int ret;
res = kzalloc(sizeof(*res), GFP_KERNEL);
if (!res)
return NULL;
res->name = "System RAM";
res->flags = IORESOURCE_SYSTEM_RAM | IORESOURCE_BUSY;
ret = allocate_resource(&iomem_resource, res,
size, 0, -1,
PAGES_PER_SECTION * PAGE_SIZE, NULL, NULL);
if (ret < 0) {
pr_err("Cannot allocate new System RAM resource\n");
kfree(res);
return NULL;
}
#ifdef CONFIG_SPARSEMEM
{
unsigned long limit = 1UL << (MAX_PHYSMEM_BITS - PAGE_SHIFT);
unsigned long pfn = res->start >> PAGE_SHIFT;
if (pfn > limit) {
pr_err("New System RAM resource outside addressable RAM (%lu > %lu)\n",
pfn, limit);
release_memory_resource(res);
return NULL;
}
}
#endif
return res;
}
static enum bp_state reserve_additional_memory(void)
{
long credit;
struct resource *resource;
int nid, rc;
unsigned long balloon_hotplug;
credit = balloon_stats.target_pages + balloon_stats.target_unpopulated
- balloon_stats.total_pages;
if (credit <= 0)
return BP_WAIT;
balloon_hotplug = round_up(credit, PAGES_PER_SECTION);
resource = additional_memory_resource(balloon_hotplug * PAGE_SIZE);
if (!resource)
goto err;
nid = memory_add_physaddr_to_nid(resource->start);
#ifdef CONFIG_XEN_HAVE_PVMMU
BUILD_BUG_ON(XEN_PAGE_SIZE != PAGE_SIZE);
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
unsigned long pfn, i;
pfn = PFN_DOWN(resource->start);
for (i = 0; i < balloon_hotplug; i++) {
if (!set_phys_to_machine(pfn + i, INVALID_P2M_ENTRY)) {
pr_warn("set_phys_to_machine() failed, no memory added\n");
goto err;
}
}
}
#endif
mutex_unlock(&balloon_mutex);
rc = add_memory_resource(nid, resource, memhp_auto_online);
mutex_lock(&balloon_mutex);
if (rc) {
pr_warn("Cannot add additional memory (%i)\n", rc);
goto err;
}
balloon_stats.total_pages += balloon_hotplug;
return BP_WAIT;
err:
release_memory_resource(resource);
return BP_ECANCELED;
}
static void xen_online_page(struct page *page)
{
__online_page_set_limits(page);
mutex_lock(&balloon_mutex);
__balloon_append(page);
mutex_unlock(&balloon_mutex);
}
static int xen_memory_notifier(struct notifier_block *nb, unsigned long val, void *v)
{
if (val == MEM_ONLINE)
schedule_delayed_work(&balloon_worker, 0);
return NOTIFY_OK;
}
static enum bp_state reserve_additional_memory(void)
{
balloon_stats.target_pages = balloon_stats.current_pages;
return BP_ECANCELED;
}
static long current_credit(void)
{
return balloon_stats.target_pages - balloon_stats.current_pages;
}
static bool balloon_is_inflated(void)
{
return balloon_stats.balloon_low || balloon_stats.balloon_high;
}
static enum bp_state increase_reservation(unsigned long nr_pages)
{
int rc;
unsigned long i;
struct page *page;
struct xen_memory_reservation reservation = {
.address_bits = 0,
.extent_order = EXTENT_ORDER,
.domid = DOMID_SELF
};
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
page = list_first_entry_or_null(&ballooned_pages, struct page, lru);
for (i = 0; i < nr_pages; i++) {
if (!page) {
nr_pages = i;
break;
}
frame_list[i] = page_to_xen_pfn(page);
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
#ifdef CONFIG_XEN_HAVE_PVMMU
BUILD_BUG_ON(XEN_PAGE_SIZE != PAGE_SIZE);
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
unsigned long pfn = page_to_pfn(page);
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
free_reserved_page(page);
}
balloon_stats.current_pages += rc;
return BP_DONE;
}
static enum bp_state decrease_reservation(unsigned long nr_pages, gfp_t gfp)
{
enum bp_state state = BP_DONE;
unsigned long i;
struct page *page, *tmp;
int ret;
struct xen_memory_reservation reservation = {
.address_bits = 0,
.extent_order = EXTENT_ORDER,
.domid = DOMID_SELF
};
LIST_HEAD(pages);
if (nr_pages > ARRAY_SIZE(frame_list))
nr_pages = ARRAY_SIZE(frame_list);
for (i = 0; i < nr_pages; i++) {
page = alloc_page(gfp);
if (page == NULL) {
nr_pages = i;
state = BP_EAGAIN;
break;
}
adjust_managed_page_count(page, -1);
scrub_page(page);
list_add(&page->lru, &pages);
}
kmap_flush_unused();
i = 0;
list_for_each_entry_safe(page, tmp, &pages, lru) {
frame_list[i++] = xen_page_to_gfn(page);
#ifdef CONFIG_XEN_HAVE_PVMMU
BUILD_BUG_ON(XEN_PAGE_SIZE != PAGE_SIZE);
if (!xen_feature(XENFEAT_auto_translated_physmap)) {
unsigned long pfn = page_to_pfn(page);
if (!PageHighMem(page)) {
ret = HYPERVISOR_update_va_mapping(
(unsigned long)__va(pfn << PAGE_SHIFT),
__pte_ma(0), 0);
BUG_ON(ret);
}
__set_phys_to_machine(pfn, INVALID_P2M_ENTRY);
}
#endif
list_del(&page->lru);
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
state = reserve_additional_memory();
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
static int add_ballooned_pages(int nr_pages)
{
enum bp_state st;
if (xen_hotplug_unpopulated) {
st = reserve_additional_memory();
if (st != BP_ECANCELED) {
mutex_unlock(&balloon_mutex);
wait_event(balloon_wq,
!list_empty(&ballooned_pages));
mutex_lock(&balloon_mutex);
return 0;
}
}
st = decrease_reservation(nr_pages, GFP_USER);
if (st != BP_DONE)
return -ENOMEM;
return 0;
}
int alloc_xenballooned_pages(int nr_pages, struct page **pages)
{
int pgno = 0;
struct page *page;
int ret;
mutex_lock(&balloon_mutex);
balloon_stats.target_unpopulated += nr_pages;
while (pgno < nr_pages) {
page = balloon_retrieve(true);
if (page) {
pages[pgno++] = page;
#ifdef CONFIG_XEN_HAVE_PVMMU
BUILD_BUG_ON(XEN_PAGE_SIZE != PAGE_SIZE);
ret = xen_alloc_p2m_entry(page_to_pfn(page));
if (ret < 0)
goto out_undo;
#endif
} else {
ret = add_ballooned_pages(nr_pages - pgno);
if (ret < 0)
goto out_undo;
}
}
mutex_unlock(&balloon_mutex);
return 0;
out_undo:
mutex_unlock(&balloon_mutex);
free_xenballooned_pages(pgno, pages);
return ret;
}
void free_xenballooned_pages(int nr_pages, struct page **pages)
{
int i;
mutex_lock(&balloon_mutex);
for (i = 0; i < nr_pages; i++) {
if (pages[i])
balloon_append(pages[i]);
}
balloon_stats.target_unpopulated -= nr_pages;
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
balloon_stats.total_pages += extra_pfn_end - start_pfn;
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
balloon_stats.total_pages = balloon_stats.current_pages;
balloon_stats.schedule_delay = 1;
balloon_stats.max_schedule_delay = 32;
balloon_stats.retry_count = 1;
balloon_stats.max_retry_count = RETRY_UNLIMITED;
#ifdef CONFIG_XEN_BALLOON_MEMORY_HOTPLUG
set_online_page_callback(&xen_online_page);
register_memory_notifier(&xen_memory_nb);
register_sysctl_table(xen_root);
#endif
for (i = 0; i < XEN_EXTRA_MEM_MAX_REGIONS; i++)
if (xen_extra_mem[i].n_pfns)
balloon_add_region(xen_extra_mem[i].start_pfn,
xen_extra_mem[i].n_pfns);
return 0;
}
