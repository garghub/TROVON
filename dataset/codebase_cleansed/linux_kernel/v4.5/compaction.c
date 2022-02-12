static inline void count_compact_event(enum vm_event_item item)
{
count_vm_event(item);
}
static inline void count_compact_events(enum vm_event_item item, long delta)
{
count_vm_events(item, delta);
}
static unsigned long release_freepages(struct list_head *freelist)
{
struct page *page, *next;
unsigned long high_pfn = 0;
list_for_each_entry_safe(page, next, freelist, lru) {
unsigned long pfn = page_to_pfn(page);
list_del(&page->lru);
__free_page(page);
if (pfn > high_pfn)
high_pfn = pfn;
}
return high_pfn;
}
static void map_pages(struct list_head *list)
{
struct page *page;
list_for_each_entry(page, list, lru) {
arch_alloc_page(page, 0);
kernel_map_pages(page, 1, 1);
kasan_alloc_pages(page, 0);
}
}
static inline bool migrate_async_suitable(int migratetype)
{
return is_migrate_cma(migratetype) || migratetype == MIGRATE_MOVABLE;
}
static struct page *pageblock_pfn_to_page(unsigned long start_pfn,
unsigned long end_pfn, struct zone *zone)
{
struct page *start_page;
struct page *end_page;
end_pfn--;
if (!pfn_valid(start_pfn) || !pfn_valid(end_pfn))
return NULL;
start_page = pfn_to_page(start_pfn);
if (page_zone(start_page) != zone)
return NULL;
end_page = pfn_to_page(end_pfn);
if (page_zone_id(start_page) != page_zone_id(end_page))
return NULL;
return start_page;
}
void defer_compaction(struct zone *zone, int order)
{
zone->compact_considered = 0;
zone->compact_defer_shift++;
if (order < zone->compact_order_failed)
zone->compact_order_failed = order;
if (zone->compact_defer_shift > COMPACT_MAX_DEFER_SHIFT)
zone->compact_defer_shift = COMPACT_MAX_DEFER_SHIFT;
trace_mm_compaction_defer_compaction(zone, order);
}
bool compaction_deferred(struct zone *zone, int order)
{
unsigned long defer_limit = 1UL << zone->compact_defer_shift;
if (order < zone->compact_order_failed)
return false;
if (++zone->compact_considered > defer_limit)
zone->compact_considered = defer_limit;
if (zone->compact_considered >= defer_limit)
return false;
trace_mm_compaction_deferred(zone, order);
return true;
}
void compaction_defer_reset(struct zone *zone, int order,
bool alloc_success)
{
if (alloc_success) {
zone->compact_considered = 0;
zone->compact_defer_shift = 0;
}
if (order >= zone->compact_order_failed)
zone->compact_order_failed = order + 1;
trace_mm_compaction_defer_reset(zone, order);
}
bool compaction_restarting(struct zone *zone, int order)
{
if (order < zone->compact_order_failed)
return false;
return zone->compact_defer_shift == COMPACT_MAX_DEFER_SHIFT &&
zone->compact_considered >= 1UL << zone->compact_defer_shift;
}
static inline bool isolation_suitable(struct compact_control *cc,
struct page *page)
{
if (cc->ignore_skip_hint)
return true;
return !get_pageblock_skip(page);
}
static void reset_cached_positions(struct zone *zone)
{
zone->compact_cached_migrate_pfn[0] = zone->zone_start_pfn;
zone->compact_cached_migrate_pfn[1] = zone->zone_start_pfn;
zone->compact_cached_free_pfn = zone_end_pfn(zone);
}
static void __reset_isolation_suitable(struct zone *zone)
{
unsigned long start_pfn = zone->zone_start_pfn;
unsigned long end_pfn = zone_end_pfn(zone);
unsigned long pfn;
zone->compact_blockskip_flush = false;
for (pfn = start_pfn; pfn < end_pfn; pfn += pageblock_nr_pages) {
struct page *page;
cond_resched();
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (zone != page_zone(page))
continue;
clear_pageblock_skip(page);
}
reset_cached_positions(zone);
}
void reset_isolation_suitable(pg_data_t *pgdat)
{
int zoneid;
for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
struct zone *zone = &pgdat->node_zones[zoneid];
if (!populated_zone(zone))
continue;
if (zone->compact_blockskip_flush)
__reset_isolation_suitable(zone);
}
}
static void update_pageblock_skip(struct compact_control *cc,
struct page *page, unsigned long nr_isolated,
bool migrate_scanner)
{
struct zone *zone = cc->zone;
unsigned long pfn;
if (cc->ignore_skip_hint)
return;
if (!page)
return;
if (nr_isolated)
return;
set_pageblock_skip(page);
pfn = page_to_pfn(page);
if (migrate_scanner) {
if (pfn > zone->compact_cached_migrate_pfn[0])
zone->compact_cached_migrate_pfn[0] = pfn;
if (cc->mode != MIGRATE_ASYNC &&
pfn > zone->compact_cached_migrate_pfn[1])
zone->compact_cached_migrate_pfn[1] = pfn;
} else {
if (pfn < zone->compact_cached_free_pfn)
zone->compact_cached_free_pfn = pfn;
}
}
static inline bool isolation_suitable(struct compact_control *cc,
struct page *page)
{
return true;
}
static void update_pageblock_skip(struct compact_control *cc,
struct page *page, unsigned long nr_isolated,
bool migrate_scanner)
{
}
static bool compact_trylock_irqsave(spinlock_t *lock, unsigned long *flags,
struct compact_control *cc)
{
if (cc->mode == MIGRATE_ASYNC) {
if (!spin_trylock_irqsave(lock, *flags)) {
cc->contended = COMPACT_CONTENDED_LOCK;
return false;
}
} else {
spin_lock_irqsave(lock, *flags);
}
return true;
}
static bool compact_unlock_should_abort(spinlock_t *lock,
unsigned long flags, bool *locked, struct compact_control *cc)
{
if (*locked) {
spin_unlock_irqrestore(lock, flags);
*locked = false;
}
if (fatal_signal_pending(current)) {
cc->contended = COMPACT_CONTENDED_SCHED;
return true;
}
if (need_resched()) {
if (cc->mode == MIGRATE_ASYNC) {
cc->contended = COMPACT_CONTENDED_SCHED;
return true;
}
cond_resched();
}
return false;
}
static inline bool compact_should_abort(struct compact_control *cc)
{
if (need_resched()) {
if (cc->mode == MIGRATE_ASYNC) {
cc->contended = COMPACT_CONTENDED_SCHED;
return true;
}
cond_resched();
}
return false;
}
static unsigned long isolate_freepages_block(struct compact_control *cc,
unsigned long *start_pfn,
unsigned long end_pfn,
struct list_head *freelist,
bool strict)
{
int nr_scanned = 0, total_isolated = 0;
struct page *cursor, *valid_page = NULL;
unsigned long flags = 0;
bool locked = false;
unsigned long blockpfn = *start_pfn;
cursor = pfn_to_page(blockpfn);
for (; blockpfn < end_pfn; blockpfn++, cursor++) {
int isolated, i;
struct page *page = cursor;
if (!(blockpfn % SWAP_CLUSTER_MAX)
&& compact_unlock_should_abort(&cc->zone->lock, flags,
&locked, cc))
break;
nr_scanned++;
if (!pfn_valid_within(blockpfn))
goto isolate_fail;
if (!valid_page)
valid_page = page;
if (PageCompound(page)) {
unsigned int comp_order = compound_order(page);
if (likely(comp_order < MAX_ORDER)) {
blockpfn += (1UL << comp_order) - 1;
cursor += (1UL << comp_order) - 1;
}
goto isolate_fail;
}
if (!PageBuddy(page))
goto isolate_fail;
if (!locked) {
locked = compact_trylock_irqsave(&cc->zone->lock,
&flags, cc);
if (!locked)
break;
if (!PageBuddy(page))
goto isolate_fail;
}
isolated = split_free_page(page);
total_isolated += isolated;
for (i = 0; i < isolated; i++) {
list_add(&page->lru, freelist);
page++;
}
if (isolated) {
cc->nr_freepages += isolated;
if (!strict &&
cc->nr_migratepages <= cc->nr_freepages) {
blockpfn += isolated;
break;
}
blockpfn += isolated - 1;
cursor += isolated - 1;
continue;
}
isolate_fail:
if (strict)
break;
else
continue;
}
if (unlikely(blockpfn > end_pfn))
blockpfn = end_pfn;
trace_mm_compaction_isolate_freepages(*start_pfn, blockpfn,
nr_scanned, total_isolated);
*start_pfn = blockpfn;
if (strict && blockpfn < end_pfn)
total_isolated = 0;
if (locked)
spin_unlock_irqrestore(&cc->zone->lock, flags);
if (blockpfn == end_pfn)
update_pageblock_skip(cc, valid_page, total_isolated, false);
count_compact_events(COMPACTFREE_SCANNED, nr_scanned);
if (total_isolated)
count_compact_events(COMPACTISOLATED, total_isolated);
return total_isolated;
}
unsigned long
isolate_freepages_range(struct compact_control *cc,
unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long isolated, pfn, block_end_pfn;
LIST_HEAD(freelist);
pfn = start_pfn;
block_end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
for (; pfn < end_pfn; pfn += isolated,
block_end_pfn += pageblock_nr_pages) {
unsigned long isolate_start_pfn = pfn;
block_end_pfn = min(block_end_pfn, end_pfn);
if (pfn >= block_end_pfn) {
block_end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
block_end_pfn = min(block_end_pfn, end_pfn);
}
if (!pageblock_pfn_to_page(pfn, block_end_pfn, cc->zone))
break;
isolated = isolate_freepages_block(cc, &isolate_start_pfn,
block_end_pfn, &freelist, true);
if (!isolated)
break;
}
map_pages(&freelist);
if (pfn < end_pfn) {
release_freepages(&freelist);
return 0;
}
return pfn;
}
static void acct_isolated(struct zone *zone, struct compact_control *cc)
{
struct page *page;
unsigned int count[2] = { 0, };
if (list_empty(&cc->migratepages))
return;
list_for_each_entry(page, &cc->migratepages, lru)
count[!!page_is_file_cache(page)]++;
mod_zone_page_state(zone, NR_ISOLATED_ANON, count[0]);
mod_zone_page_state(zone, NR_ISOLATED_FILE, count[1]);
}
static bool too_many_isolated(struct zone *zone)
{
unsigned long active, inactive, isolated;
inactive = zone_page_state(zone, NR_INACTIVE_FILE) +
zone_page_state(zone, NR_INACTIVE_ANON);
active = zone_page_state(zone, NR_ACTIVE_FILE) +
zone_page_state(zone, NR_ACTIVE_ANON);
isolated = zone_page_state(zone, NR_ISOLATED_FILE) +
zone_page_state(zone, NR_ISOLATED_ANON);
return isolated > (inactive + active) / 2;
}
static unsigned long
isolate_migratepages_block(struct compact_control *cc, unsigned long low_pfn,
unsigned long end_pfn, isolate_mode_t isolate_mode)
{
struct zone *zone = cc->zone;
unsigned long nr_scanned = 0, nr_isolated = 0;
struct list_head *migratelist = &cc->migratepages;
struct lruvec *lruvec;
unsigned long flags = 0;
bool locked = false;
struct page *page = NULL, *valid_page = NULL;
unsigned long start_pfn = low_pfn;
while (unlikely(too_many_isolated(zone))) {
if (cc->mode == MIGRATE_ASYNC)
return 0;
congestion_wait(BLK_RW_ASYNC, HZ/10);
if (fatal_signal_pending(current))
return 0;
}
if (compact_should_abort(cc))
return 0;
for (; low_pfn < end_pfn; low_pfn++) {
bool is_lru;
if (!(low_pfn % SWAP_CLUSTER_MAX)
&& compact_unlock_should_abort(&zone->lru_lock, flags,
&locked, cc))
break;
if (!pfn_valid_within(low_pfn))
continue;
nr_scanned++;
page = pfn_to_page(low_pfn);
if (!valid_page)
valid_page = page;
if (PageBuddy(page)) {
unsigned long freepage_order = page_order_unsafe(page);
if (freepage_order > 0 && freepage_order < MAX_ORDER)
low_pfn += (1UL << freepage_order) - 1;
continue;
}
is_lru = PageLRU(page);
if (!is_lru) {
if (unlikely(balloon_page_movable(page))) {
if (balloon_page_isolate(page)) {
goto isolate_success;
}
}
}
if (PageCompound(page)) {
unsigned int comp_order = compound_order(page);
if (likely(comp_order < MAX_ORDER))
low_pfn += (1UL << comp_order) - 1;
continue;
}
if (!is_lru)
continue;
if (!page_mapping(page) &&
page_count(page) > page_mapcount(page))
continue;
if (!locked) {
locked = compact_trylock_irqsave(&zone->lru_lock,
&flags, cc);
if (!locked)
break;
if (!PageLRU(page))
continue;
if (unlikely(PageCompound(page))) {
low_pfn += (1UL << compound_order(page)) - 1;
continue;
}
}
lruvec = mem_cgroup_page_lruvec(page, zone);
if (__isolate_lru_page(page, isolate_mode) != 0)
continue;
VM_BUG_ON_PAGE(PageCompound(page), page);
del_page_from_lru_list(page, lruvec, page_lru(page));
isolate_success:
list_add(&page->lru, migratelist);
cc->nr_migratepages++;
nr_isolated++;
if (cc->nr_migratepages == COMPACT_CLUSTER_MAX) {
++low_pfn;
break;
}
}
if (unlikely(low_pfn > end_pfn))
low_pfn = end_pfn;
if (locked)
spin_unlock_irqrestore(&zone->lru_lock, flags);
if (low_pfn == end_pfn)
update_pageblock_skip(cc, valid_page, nr_isolated, true);
trace_mm_compaction_isolate_migratepages(start_pfn, low_pfn,
nr_scanned, nr_isolated);
count_compact_events(COMPACTMIGRATE_SCANNED, nr_scanned);
if (nr_isolated)
count_compact_events(COMPACTISOLATED, nr_isolated);
return low_pfn;
}
unsigned long
isolate_migratepages_range(struct compact_control *cc, unsigned long start_pfn,
unsigned long end_pfn)
{
unsigned long pfn, block_end_pfn;
pfn = start_pfn;
block_end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
for (; pfn < end_pfn; pfn = block_end_pfn,
block_end_pfn += pageblock_nr_pages) {
block_end_pfn = min(block_end_pfn, end_pfn);
if (!pageblock_pfn_to_page(pfn, block_end_pfn, cc->zone))
continue;
pfn = isolate_migratepages_block(cc, pfn, block_end_pfn,
ISOLATE_UNEVICTABLE);
if (!pfn) {
putback_movable_pages(&cc->migratepages);
cc->nr_migratepages = 0;
break;
}
if (cc->nr_migratepages == COMPACT_CLUSTER_MAX)
break;
}
acct_isolated(cc->zone, cc);
return pfn;
}
static bool suitable_migration_target(struct page *page)
{
if (PageBuddy(page)) {
if (page_order_unsafe(page) >= pageblock_order)
return false;
}
if (migrate_async_suitable(get_pageblock_migratetype(page)))
return true;
return false;
}
static inline bool compact_scanners_met(struct compact_control *cc)
{
return (cc->free_pfn >> pageblock_order)
<= (cc->migrate_pfn >> pageblock_order);
}
static void isolate_freepages(struct compact_control *cc)
{
struct zone *zone = cc->zone;
struct page *page;
unsigned long block_start_pfn;
unsigned long isolate_start_pfn;
unsigned long block_end_pfn;
unsigned long low_pfn;
struct list_head *freelist = &cc->freepages;
isolate_start_pfn = cc->free_pfn;
block_start_pfn = cc->free_pfn & ~(pageblock_nr_pages-1);
block_end_pfn = min(block_start_pfn + pageblock_nr_pages,
zone_end_pfn(zone));
low_pfn = ALIGN(cc->migrate_pfn + 1, pageblock_nr_pages);
for (; block_start_pfn >= low_pfn;
block_end_pfn = block_start_pfn,
block_start_pfn -= pageblock_nr_pages,
isolate_start_pfn = block_start_pfn) {
if (!(block_start_pfn % (SWAP_CLUSTER_MAX * pageblock_nr_pages))
&& compact_should_abort(cc))
break;
page = pageblock_pfn_to_page(block_start_pfn, block_end_pfn,
zone);
if (!page)
continue;
if (!suitable_migration_target(page))
continue;
if (!isolation_suitable(cc, page))
continue;
isolate_freepages_block(cc, &isolate_start_pfn,
block_end_pfn, freelist, false);
if ((cc->nr_freepages >= cc->nr_migratepages)
|| cc->contended) {
if (isolate_start_pfn >= block_end_pfn)
isolate_start_pfn =
block_start_pfn - pageblock_nr_pages;
break;
} else {
VM_BUG_ON(isolate_start_pfn < block_end_pfn);
}
}
map_pages(freelist);
cc->free_pfn = isolate_start_pfn;
}
static struct page *compaction_alloc(struct page *migratepage,
unsigned long data,
int **result)
{
struct compact_control *cc = (struct compact_control *)data;
struct page *freepage;
if (list_empty(&cc->freepages)) {
if (!cc->contended)
isolate_freepages(cc);
if (list_empty(&cc->freepages))
return NULL;
}
freepage = list_entry(cc->freepages.next, struct page, lru);
list_del(&freepage->lru);
cc->nr_freepages--;
return freepage;
}
static void compaction_free(struct page *page, unsigned long data)
{
struct compact_control *cc = (struct compact_control *)data;
list_add(&page->lru, &cc->freepages);
cc->nr_freepages++;
}
static isolate_migrate_t isolate_migratepages(struct zone *zone,
struct compact_control *cc)
{
unsigned long low_pfn, end_pfn;
unsigned long isolate_start_pfn;
struct page *page;
const isolate_mode_t isolate_mode =
(sysctl_compact_unevictable_allowed ? ISOLATE_UNEVICTABLE : 0) |
(cc->mode == MIGRATE_ASYNC ? ISOLATE_ASYNC_MIGRATE : 0);
low_pfn = cc->migrate_pfn;
end_pfn = ALIGN(low_pfn + 1, pageblock_nr_pages);
for (; end_pfn <= cc->free_pfn;
low_pfn = end_pfn, end_pfn += pageblock_nr_pages) {
if (!(low_pfn % (SWAP_CLUSTER_MAX * pageblock_nr_pages))
&& compact_should_abort(cc))
break;
page = pageblock_pfn_to_page(low_pfn, end_pfn, zone);
if (!page)
continue;
if (!isolation_suitable(cc, page))
continue;
if (cc->mode == MIGRATE_ASYNC &&
!migrate_async_suitable(get_pageblock_migratetype(page)))
continue;
isolate_start_pfn = low_pfn;
low_pfn = isolate_migratepages_block(cc, low_pfn, end_pfn,
isolate_mode);
if (!low_pfn || cc->contended) {
acct_isolated(zone, cc);
return ISOLATE_ABORT;
}
if (cc->nr_migratepages && !cc->last_migrated_pfn)
cc->last_migrated_pfn = isolate_start_pfn;
break;
}
acct_isolated(zone, cc);
cc->migrate_pfn = low_pfn;
return cc->nr_migratepages ? ISOLATE_SUCCESS : ISOLATE_NONE;
}
static inline bool is_via_compact_memory(int order)
{
return order == -1;
}
static int __compact_finished(struct zone *zone, struct compact_control *cc,
const int migratetype)
{
unsigned int order;
unsigned long watermark;
if (cc->contended || fatal_signal_pending(current))
return COMPACT_CONTENDED;
if (compact_scanners_met(cc)) {
reset_cached_positions(zone);
if (!current_is_kswapd())
zone->compact_blockskip_flush = true;
return COMPACT_COMPLETE;
}
if (is_via_compact_memory(cc->order))
return COMPACT_CONTINUE;
watermark = low_wmark_pages(zone);
if (!zone_watermark_ok(zone, cc->order, watermark, cc->classzone_idx,
cc->alloc_flags))
return COMPACT_CONTINUE;
for (order = cc->order; order < MAX_ORDER; order++) {
struct free_area *area = &zone->free_area[order];
bool can_steal;
if (!list_empty(&area->free_list[migratetype]))
return COMPACT_PARTIAL;
#ifdef CONFIG_CMA
if (migratetype == MIGRATE_MOVABLE &&
!list_empty(&area->free_list[MIGRATE_CMA]))
return COMPACT_PARTIAL;
#endif
if (find_suitable_fallback(area, order, migratetype,
true, &can_steal) != -1)
return COMPACT_PARTIAL;
}
return COMPACT_NO_SUITABLE_PAGE;
}
static int compact_finished(struct zone *zone, struct compact_control *cc,
const int migratetype)
{
int ret;
ret = __compact_finished(zone, cc, migratetype);
trace_mm_compaction_finished(zone, cc->order, ret);
if (ret == COMPACT_NO_SUITABLE_PAGE)
ret = COMPACT_CONTINUE;
return ret;
}
static unsigned long __compaction_suitable(struct zone *zone, int order,
int alloc_flags, int classzone_idx)
{
int fragindex;
unsigned long watermark;
if (is_via_compact_memory(order))
return COMPACT_CONTINUE;
watermark = low_wmark_pages(zone);
if (zone_watermark_ok(zone, order, watermark, classzone_idx,
alloc_flags))
return COMPACT_PARTIAL;
watermark += (2UL << order);
if (!zone_watermark_ok(zone, 0, watermark, classzone_idx, alloc_flags))
return COMPACT_SKIPPED;
fragindex = fragmentation_index(zone, order);
if (fragindex >= 0 && fragindex <= sysctl_extfrag_threshold)
return COMPACT_NOT_SUITABLE_ZONE;
return COMPACT_CONTINUE;
}
unsigned long compaction_suitable(struct zone *zone, int order,
int alloc_flags, int classzone_idx)
{
unsigned long ret;
ret = __compaction_suitable(zone, order, alloc_flags, classzone_idx);
trace_mm_compaction_suitable(zone, order, ret);
if (ret == COMPACT_NOT_SUITABLE_ZONE)
ret = COMPACT_SKIPPED;
return ret;
}
static int compact_zone(struct zone *zone, struct compact_control *cc)
{
int ret;
unsigned long start_pfn = zone->zone_start_pfn;
unsigned long end_pfn = zone_end_pfn(zone);
const int migratetype = gfpflags_to_migratetype(cc->gfp_mask);
const bool sync = cc->mode != MIGRATE_ASYNC;
ret = compaction_suitable(zone, cc->order, cc->alloc_flags,
cc->classzone_idx);
switch (ret) {
case COMPACT_PARTIAL:
case COMPACT_SKIPPED:
return ret;
case COMPACT_CONTINUE:
;
}
if (compaction_restarting(zone, cc->order) && !current_is_kswapd())
__reset_isolation_suitable(zone);
cc->migrate_pfn = zone->compact_cached_migrate_pfn[sync];
cc->free_pfn = zone->compact_cached_free_pfn;
if (cc->free_pfn < start_pfn || cc->free_pfn > end_pfn) {
cc->free_pfn = end_pfn & ~(pageblock_nr_pages-1);
zone->compact_cached_free_pfn = cc->free_pfn;
}
if (cc->migrate_pfn < start_pfn || cc->migrate_pfn > end_pfn) {
cc->migrate_pfn = start_pfn;
zone->compact_cached_migrate_pfn[0] = cc->migrate_pfn;
zone->compact_cached_migrate_pfn[1] = cc->migrate_pfn;
}
cc->last_migrated_pfn = 0;
trace_mm_compaction_begin(start_pfn, cc->migrate_pfn,
cc->free_pfn, end_pfn, sync);
migrate_prep_local();
while ((ret = compact_finished(zone, cc, migratetype)) ==
COMPACT_CONTINUE) {
int err;
switch (isolate_migratepages(zone, cc)) {
case ISOLATE_ABORT:
ret = COMPACT_CONTENDED;
putback_movable_pages(&cc->migratepages);
cc->nr_migratepages = 0;
goto out;
case ISOLATE_NONE:
goto check_drain;
case ISOLATE_SUCCESS:
;
}
err = migrate_pages(&cc->migratepages, compaction_alloc,
compaction_free, (unsigned long)cc, cc->mode,
MR_COMPACTION);
trace_mm_compaction_migratepages(cc->nr_migratepages, err,
&cc->migratepages);
cc->nr_migratepages = 0;
if (err) {
putback_movable_pages(&cc->migratepages);
if (err == -ENOMEM && !compact_scanners_met(cc)) {
ret = COMPACT_CONTENDED;
goto out;
}
}
check_drain:
if (cc->order > 0 && cc->last_migrated_pfn) {
int cpu;
unsigned long current_block_start =
cc->migrate_pfn & ~((1UL << cc->order) - 1);
if (cc->last_migrated_pfn < current_block_start) {
cpu = get_cpu();
lru_add_drain_cpu(cpu);
drain_local_pages(zone);
put_cpu();
cc->last_migrated_pfn = 0;
}
}
}
out:
if (cc->nr_freepages > 0) {
unsigned long free_pfn = release_freepages(&cc->freepages);
cc->nr_freepages = 0;
VM_BUG_ON(free_pfn == 0);
free_pfn &= ~(pageblock_nr_pages-1);
if (free_pfn > zone->compact_cached_free_pfn)
zone->compact_cached_free_pfn = free_pfn;
}
trace_mm_compaction_end(start_pfn, cc->migrate_pfn,
cc->free_pfn, end_pfn, sync, ret);
if (ret == COMPACT_CONTENDED)
ret = COMPACT_PARTIAL;
return ret;
}
static unsigned long compact_zone_order(struct zone *zone, int order,
gfp_t gfp_mask, enum migrate_mode mode, int *contended,
int alloc_flags, int classzone_idx)
{
unsigned long ret;
struct compact_control cc = {
.nr_freepages = 0,
.nr_migratepages = 0,
.order = order,
.gfp_mask = gfp_mask,
.zone = zone,
.mode = mode,
.alloc_flags = alloc_flags,
.classzone_idx = classzone_idx,
};
INIT_LIST_HEAD(&cc.freepages);
INIT_LIST_HEAD(&cc.migratepages);
ret = compact_zone(zone, &cc);
VM_BUG_ON(!list_empty(&cc.freepages));
VM_BUG_ON(!list_empty(&cc.migratepages));
*contended = cc.contended;
return ret;
}
unsigned long try_to_compact_pages(gfp_t gfp_mask, unsigned int order,
int alloc_flags, const struct alloc_context *ac,
enum migrate_mode mode, int *contended)
{
int may_enter_fs = gfp_mask & __GFP_FS;
int may_perform_io = gfp_mask & __GFP_IO;
struct zoneref *z;
struct zone *zone;
int rc = COMPACT_DEFERRED;
int all_zones_contended = COMPACT_CONTENDED_LOCK;
*contended = COMPACT_CONTENDED_NONE;
if (!order || !may_enter_fs || !may_perform_io)
return COMPACT_SKIPPED;
trace_mm_compaction_try_to_compact_pages(order, gfp_mask, mode);
for_each_zone_zonelist_nodemask(zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
int status;
int zone_contended;
if (compaction_deferred(zone, order))
continue;
status = compact_zone_order(zone, order, gfp_mask, mode,
&zone_contended, alloc_flags,
ac->classzone_idx);
rc = max(status, rc);
all_zones_contended &= zone_contended;
if (zone_watermark_ok(zone, order, low_wmark_pages(zone),
ac->classzone_idx, alloc_flags)) {
compaction_defer_reset(zone, order, false);
if (zone_contended == COMPACT_CONTENDED_SCHED)
*contended = COMPACT_CONTENDED_SCHED;
goto break_loop;
}
if (mode != MIGRATE_ASYNC && status == COMPACT_COMPLETE) {
defer_compaction(zone, order);
}
if ((zone_contended == COMPACT_CONTENDED_SCHED)
|| fatal_signal_pending(current)) {
*contended = COMPACT_CONTENDED_SCHED;
goto break_loop;
}
continue;
break_loop:
all_zones_contended = 0;
break;
}
if (rc > COMPACT_SKIPPED && all_zones_contended)
*contended = COMPACT_CONTENDED_LOCK;
return rc;
}
static void __compact_pgdat(pg_data_t *pgdat, struct compact_control *cc)
{
int zoneid;
struct zone *zone;
for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
zone = &pgdat->node_zones[zoneid];
if (!populated_zone(zone))
continue;
cc->nr_freepages = 0;
cc->nr_migratepages = 0;
cc->zone = zone;
INIT_LIST_HEAD(&cc->freepages);
INIT_LIST_HEAD(&cc->migratepages);
if (is_via_compact_memory(cc->order))
__reset_isolation_suitable(zone);
if (is_via_compact_memory(cc->order) ||
!compaction_deferred(zone, cc->order))
compact_zone(zone, cc);
VM_BUG_ON(!list_empty(&cc->freepages));
VM_BUG_ON(!list_empty(&cc->migratepages));
if (is_via_compact_memory(cc->order))
continue;
if (zone_watermark_ok(zone, cc->order,
low_wmark_pages(zone), 0, 0))
compaction_defer_reset(zone, cc->order, false);
}
}
void compact_pgdat(pg_data_t *pgdat, int order)
{
struct compact_control cc = {
.order = order,
.mode = MIGRATE_ASYNC,
};
if (!order)
return;
__compact_pgdat(pgdat, &cc);
}
static void compact_node(int nid)
{
struct compact_control cc = {
.order = -1,
.mode = MIGRATE_SYNC,
.ignore_skip_hint = true,
};
__compact_pgdat(NODE_DATA(nid), &cc);
}
static void compact_nodes(void)
{
int nid;
lru_add_drain_all();
for_each_online_node(nid)
compact_node(nid);
}
int sysctl_compaction_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
if (write)
compact_nodes();
return 0;
}
int sysctl_extfrag_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
proc_dointvec_minmax(table, write, buffer, length, ppos);
return 0;
}
static ssize_t sysfs_compact_node(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nid = dev->id;
if (nid >= 0 && nid < nr_node_ids && node_online(nid)) {
lru_add_drain_all();
compact_node(nid);
}
return count;
}
int compaction_register_node(struct node *node)
{
return device_create_file(&node->dev, &dev_attr_compact);
}
void compaction_unregister_node(struct node *node)
{
return device_remove_file(&node->dev, &dev_attr_compact);
}
