static int set_migratetype_isolate(struct page *page,
bool skip_hwpoisoned_pages)
{
struct zone *zone;
unsigned long flags, pfn;
struct memory_isolate_notify arg;
int notifier_ret;
int ret = -EBUSY;
zone = page_zone(page);
spin_lock_irqsave(&zone->lock, flags);
pfn = page_to_pfn(page);
arg.start_pfn = pfn;
arg.nr_pages = pageblock_nr_pages;
arg.pages_found = 0;
notifier_ret = memory_isolate_notify(MEM_ISOLATE_COUNT, &arg);
notifier_ret = notifier_to_errno(notifier_ret);
if (notifier_ret)
goto out;
if (!has_unmovable_pages(zone, page, arg.pages_found,
skip_hwpoisoned_pages))
ret = 0;
out:
if (!ret) {
unsigned long nr_pages;
int migratetype = get_pageblock_migratetype(page);
set_pageblock_migratetype(page, MIGRATE_ISOLATE);
zone->nr_isolate_pageblock++;
nr_pages = move_freepages_block(zone, page, MIGRATE_ISOLATE);
__mod_zone_freepage_state(zone, -nr_pages, migratetype);
}
spin_unlock_irqrestore(&zone->lock, flags);
if (!ret)
drain_all_pages(zone);
return ret;
}
static void unset_migratetype_isolate(struct page *page, unsigned migratetype)
{
struct zone *zone;
unsigned long flags, nr_pages;
struct page *isolated_page = NULL;
unsigned int order;
unsigned long page_idx, buddy_idx;
struct page *buddy;
zone = page_zone(page);
spin_lock_irqsave(&zone->lock, flags);
if (get_pageblock_migratetype(page) != MIGRATE_ISOLATE)
goto out;
if (PageBuddy(page)) {
order = page_order(page);
if (order >= pageblock_order) {
page_idx = page_to_pfn(page) & ((1 << MAX_ORDER) - 1);
buddy_idx = __find_buddy_index(page_idx, order);
buddy = page + (buddy_idx - page_idx);
if (pfn_valid_within(page_to_pfn(buddy)) &&
!is_migrate_isolate_page(buddy)) {
__isolate_free_page(page, order);
kernel_map_pages(page, (1 << order), 1);
set_page_refcounted(page);
isolated_page = page;
}
}
}
if (!isolated_page) {
nr_pages = move_freepages_block(zone, page, migratetype);
__mod_zone_freepage_state(zone, nr_pages, migratetype);
}
set_pageblock_migratetype(page, migratetype);
zone->nr_isolate_pageblock--;
out:
spin_unlock_irqrestore(&zone->lock, flags);
if (isolated_page)
__free_pages(isolated_page, order);
}
static inline struct page *
__first_valid_page(unsigned long pfn, unsigned long nr_pages)
{
int i;
for (i = 0; i < nr_pages; i++)
if (pfn_valid_within(pfn + i))
break;
if (unlikely(i == nr_pages))
return NULL;
return pfn_to_page(pfn + i);
}
int start_isolate_page_range(unsigned long start_pfn, unsigned long end_pfn,
unsigned migratetype, bool skip_hwpoisoned_pages)
{
unsigned long pfn;
unsigned long undo_pfn;
struct page *page;
BUG_ON(!IS_ALIGNED(start_pfn, pageblock_nr_pages));
BUG_ON(!IS_ALIGNED(end_pfn, pageblock_nr_pages));
for (pfn = start_pfn;
pfn < end_pfn;
pfn += pageblock_nr_pages) {
page = __first_valid_page(pfn, pageblock_nr_pages);
if (page &&
set_migratetype_isolate(page, skip_hwpoisoned_pages)) {
undo_pfn = pfn;
goto undo;
}
}
return 0;
undo:
for (pfn = start_pfn;
pfn < undo_pfn;
pfn += pageblock_nr_pages)
unset_migratetype_isolate(pfn_to_page(pfn), migratetype);
return -EBUSY;
}
int undo_isolate_page_range(unsigned long start_pfn, unsigned long end_pfn,
unsigned migratetype)
{
unsigned long pfn;
struct page *page;
BUG_ON(!IS_ALIGNED(start_pfn, pageblock_nr_pages));
BUG_ON(!IS_ALIGNED(end_pfn, pageblock_nr_pages));
for (pfn = start_pfn;
pfn < end_pfn;
pfn += pageblock_nr_pages) {
page = __first_valid_page(pfn, pageblock_nr_pages);
if (!page || get_pageblock_migratetype(page) != MIGRATE_ISOLATE)
continue;
unset_migratetype_isolate(page, migratetype);
}
return 0;
}
static unsigned long
__test_page_isolated_in_pageblock(unsigned long pfn, unsigned long end_pfn,
bool skip_hwpoisoned_pages)
{
struct page *page;
while (pfn < end_pfn) {
if (!pfn_valid_within(pfn)) {
pfn++;
continue;
}
page = pfn_to_page(pfn);
if (PageBuddy(page))
pfn += 1 << page_order(page);
else if (skip_hwpoisoned_pages && PageHWPoison(page))
pfn++;
else
break;
}
return pfn;
}
int test_pages_isolated(unsigned long start_pfn, unsigned long end_pfn,
bool skip_hwpoisoned_pages)
{
unsigned long pfn, flags;
struct page *page;
struct zone *zone;
for (pfn = start_pfn; pfn < end_pfn; pfn += pageblock_nr_pages) {
page = __first_valid_page(pfn, pageblock_nr_pages);
if (page && get_pageblock_migratetype(page) != MIGRATE_ISOLATE)
break;
}
page = __first_valid_page(start_pfn, end_pfn - start_pfn);
if ((pfn < end_pfn) || !page)
return -EBUSY;
zone = page_zone(page);
spin_lock_irqsave(&zone->lock, flags);
pfn = __test_page_isolated_in_pageblock(start_pfn, end_pfn,
skip_hwpoisoned_pages);
spin_unlock_irqrestore(&zone->lock, flags);
trace_test_pages_isolated(start_pfn, end_pfn, pfn);
return pfn < end_pfn ? -EBUSY : 0;
}
struct page *alloc_migrate_target(struct page *page, unsigned long private,
int **resultp)
{
gfp_t gfp_mask = GFP_USER | __GFP_MOVABLE;
if (PageHuge(page)) {
nodemask_t src = nodemask_of_node(page_to_nid(page));
nodemask_t dst;
nodes_complement(dst, src);
return alloc_huge_page_node(page_hstate(compound_head(page)),
next_node(page_to_nid(page), dst));
}
if (PageHighMem(page))
gfp_mask |= __GFP_HIGHMEM;
return alloc_page(gfp_mask);
}
