static void set_pageblock_isolate(struct page *page)
{
if (get_pageblock_migratetype(page) == MIGRATE_ISOLATE)
return;
set_pageblock_migratetype(page, MIGRATE_ISOLATE);
page_zone(page)->nr_pageblock_isolate++;
}
static void restore_pageblock_isolate(struct page *page, int migratetype)
{
struct zone *zone = page_zone(page);
if (WARN_ON(get_pageblock_migratetype(page) != MIGRATE_ISOLATE))
return;
BUG_ON(zone->nr_pageblock_isolate <= 0);
set_pageblock_migratetype(page, migratetype);
zone->nr_pageblock_isolate--;
}
int set_migratetype_isolate(struct page *page)
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
if (!has_unmovable_pages(zone, page, arg.pages_found))
ret = 0;
out:
if (!ret) {
unsigned long nr_pages;
int migratetype = get_pageblock_migratetype(page);
set_pageblock_isolate(page);
nr_pages = move_freepages_block(zone, page, MIGRATE_ISOLATE);
__mod_zone_freepage_state(zone, -nr_pages, migratetype);
}
spin_unlock_irqrestore(&zone->lock, flags);
if (!ret)
drain_all_pages();
return ret;
}
void unset_migratetype_isolate(struct page *page, unsigned migratetype)
{
struct zone *zone;
unsigned long flags, nr_pages;
zone = page_zone(page);
spin_lock_irqsave(&zone->lock, flags);
if (get_pageblock_migratetype(page) != MIGRATE_ISOLATE)
goto out;
nr_pages = move_freepages_block(zone, page, migratetype);
__mod_zone_freepage_state(zone, nr_pages, migratetype);
restore_pageblock_isolate(page, migratetype);
out:
spin_unlock_irqrestore(&zone->lock, flags);
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
unsigned migratetype)
{
unsigned long pfn;
unsigned long undo_pfn;
struct page *page;
BUG_ON((start_pfn) & (pageblock_nr_pages - 1));
BUG_ON((end_pfn) & (pageblock_nr_pages - 1));
for (pfn = start_pfn;
pfn < end_pfn;
pfn += pageblock_nr_pages) {
page = __first_valid_page(pfn, pageblock_nr_pages);
if (page && set_migratetype_isolate(page)) {
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
BUG_ON((start_pfn) & (pageblock_nr_pages - 1));
BUG_ON((end_pfn) & (pageblock_nr_pages - 1));
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
static int
__test_page_isolated_in_pageblock(unsigned long pfn, unsigned long end_pfn)
{
struct page *page;
while (pfn < end_pfn) {
if (!pfn_valid_within(pfn)) {
pfn++;
continue;
}
page = pfn_to_page(pfn);
if (PageBuddy(page)) {
if (get_freepage_migratetype(page) != MIGRATE_ISOLATE) {
struct page *end_page;
end_page = page + (1 << page_order(page)) - 1;
move_freepages(page_zone(page), page, end_page,
MIGRATE_ISOLATE);
}
pfn += 1 << page_order(page);
}
else if (page_count(page) == 0 &&
get_freepage_migratetype(page) == MIGRATE_ISOLATE)
pfn += 1;
else
break;
}
if (pfn < end_pfn)
return 0;
return 1;
}
int test_pages_isolated(unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long pfn, flags;
struct page *page;
struct zone *zone;
int ret;
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
ret = __test_page_isolated_in_pageblock(start_pfn, end_pfn);
spin_unlock_irqrestore(&zone->lock, flags);
return ret ? 0 : -EBUSY;
}
struct page *alloc_migrate_target(struct page *page, unsigned long private,
int **resultp)
{
gfp_t gfp_mask = GFP_USER | __GFP_MOVABLE;
if (PageHighMem(page))
gfp_mask |= __GFP_HIGHMEM;
return alloc_page(gfp_mask);
}
