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
unsigned long count = 0;
list_for_each_entry_safe(page, next, freelist, lru) {
list_del(&page->lru);
__free_page(page);
count++;
}
return count;
}
static void map_pages(struct list_head *list)
{
struct page *page;
list_for_each_entry(page, list, lru) {
arch_alloc_page(page, 0);
kernel_map_pages(page, 1, 1);
}
}
static inline bool migrate_async_suitable(int migratetype)
{
return is_migrate_cma(migratetype) || migratetype == MIGRATE_MOVABLE;
}
static inline bool isolation_suitable(struct compact_control *cc,
struct page *page)
{
if (cc->ignore_skip_hint)
return true;
return !get_pageblock_skip(page);
}
static void __reset_isolation_suitable(struct zone *zone)
{
unsigned long start_pfn = zone->zone_start_pfn;
unsigned long end_pfn = zone_end_pfn(zone);
unsigned long pfn;
zone->compact_cached_migrate_pfn = start_pfn;
zone->compact_cached_free_pfn = end_pfn;
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
if (cc->ignore_skip_hint)
return;
if (!page)
return;
if (!nr_isolated) {
unsigned long pfn = page_to_pfn(page);
set_pageblock_skip(page);
if (migrate_scanner) {
if (!cc->finished_update_migrate &&
pfn > zone->compact_cached_migrate_pfn)
zone->compact_cached_migrate_pfn = pfn;
} else {
if (!cc->finished_update_free &&
pfn < zone->compact_cached_free_pfn)
zone->compact_cached_free_pfn = pfn;
}
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
static inline bool should_release_lock(spinlock_t *lock)
{
return need_resched() || spin_is_contended(lock);
}
static bool compact_checklock_irqsave(spinlock_t *lock, unsigned long *flags,
bool locked, struct compact_control *cc)
{
if (should_release_lock(lock)) {
if (locked) {
spin_unlock_irqrestore(lock, *flags);
locked = false;
}
if (!cc->sync) {
cc->contended = true;
return false;
}
cond_resched();
}
if (!locked)
spin_lock_irqsave(lock, *flags);
return true;
}
static inline bool compact_trylock_irqsave(spinlock_t *lock,
unsigned long *flags, struct compact_control *cc)
{
return compact_checklock_irqsave(lock, flags, false, cc);
}
static bool suitable_migration_target(struct page *page)
{
int migratetype = get_pageblock_migratetype(page);
if (migratetype == MIGRATE_RESERVE)
return false;
if (is_migrate_isolate(migratetype))
return false;
if (PageBuddy(page) && page_order(page) >= pageblock_order)
return true;
if (migrate_async_suitable(migratetype))
return true;
return false;
}
static unsigned long isolate_freepages_block(struct compact_control *cc,
unsigned long blockpfn,
unsigned long end_pfn,
struct list_head *freelist,
bool strict)
{
int nr_scanned = 0, total_isolated = 0;
struct page *cursor, *valid_page = NULL;
unsigned long flags;
bool locked = false;
cursor = pfn_to_page(blockpfn);
for (; blockpfn < end_pfn; blockpfn++, cursor++) {
int isolated, i;
struct page *page = cursor;
nr_scanned++;
if (!pfn_valid_within(blockpfn))
goto isolate_fail;
if (!valid_page)
valid_page = page;
if (!PageBuddy(page))
goto isolate_fail;
locked = compact_checklock_irqsave(&cc->zone->lock, &flags,
locked, cc);
if (!locked)
break;
if (!strict && !suitable_migration_target(page))
break;
if (!PageBuddy(page))
goto isolate_fail;
isolated = split_free_page(page);
total_isolated += isolated;
for (i = 0; i < isolated; i++) {
list_add(&page->lru, freelist);
page++;
}
if (isolated) {
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
trace_mm_compaction_isolate_freepages(nr_scanned, total_isolated);
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
for (pfn = start_pfn; pfn < end_pfn; pfn += isolated) {
if (!pfn_valid(pfn) || cc->zone != page_zone(pfn_to_page(pfn)))
break;
block_end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
block_end_pfn = min(block_end_pfn, end_pfn);
isolated = isolate_freepages_block(cc, pfn, block_end_pfn,
&freelist, true);
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
static void acct_isolated(struct zone *zone, bool locked, struct compact_control *cc)
{
struct page *page;
unsigned int count[2] = { 0, };
list_for_each_entry(page, &cc->migratepages, lru)
count[!!page_is_file_cache(page)]++;
if (locked) {
__mod_zone_page_state(zone, NR_ISOLATED_ANON, count[0]);
__mod_zone_page_state(zone, NR_ISOLATED_FILE, count[1]);
} else {
mod_zone_page_state(zone, NR_ISOLATED_ANON, count[0]);
mod_zone_page_state(zone, NR_ISOLATED_FILE, count[1]);
}
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
unsigned long
isolate_migratepages_range(struct zone *zone, struct compact_control *cc,
unsigned long low_pfn, unsigned long end_pfn, bool unevictable)
{
unsigned long last_pageblock_nr = 0, pageblock_nr;
unsigned long nr_scanned = 0, nr_isolated = 0;
struct list_head *migratelist = &cc->migratepages;
isolate_mode_t mode = 0;
struct lruvec *lruvec;
unsigned long flags;
bool locked = false;
struct page *page = NULL, *valid_page = NULL;
bool skipped_async_unsuitable = false;
while (unlikely(too_many_isolated(zone))) {
if (!cc->sync)
return 0;
congestion_wait(BLK_RW_ASYNC, HZ/10);
if (fatal_signal_pending(current))
return 0;
}
cond_resched();
for (; low_pfn < end_pfn; low_pfn++) {
if (locked && !((low_pfn+1) % SWAP_CLUSTER_MAX)) {
if (should_release_lock(&zone->lru_lock)) {
spin_unlock_irqrestore(&zone->lru_lock, flags);
locked = false;
}
}
if ((low_pfn & (MAX_ORDER_NR_PAGES - 1)) == 0) {
if (!pfn_valid(low_pfn)) {
low_pfn += MAX_ORDER_NR_PAGES - 1;
continue;
}
}
if (!pfn_valid_within(low_pfn))
continue;
nr_scanned++;
page = pfn_to_page(low_pfn);
if (page_zone(page) != zone)
continue;
if (!valid_page)
valid_page = page;
pageblock_nr = low_pfn >> pageblock_order;
if (!isolation_suitable(cc, page))
goto next_pageblock;
if (PageBuddy(page))
continue;
if (!cc->sync && last_pageblock_nr != pageblock_nr &&
!migrate_async_suitable(get_pageblock_migratetype(page))) {
cc->finished_update_migrate = true;
skipped_async_unsuitable = true;
goto next_pageblock;
}
if (!PageLRU(page)) {
if (unlikely(balloon_page_movable(page))) {
if (locked && balloon_page_isolate(page)) {
cc->finished_update_migrate = true;
list_add(&page->lru, migratelist);
cc->nr_migratepages++;
nr_isolated++;
goto check_compact_cluster;
}
}
continue;
}
if (PageTransHuge(page)) {
if (!locked)
goto next_pageblock;
low_pfn += (1 << compound_order(page)) - 1;
continue;
}
locked = compact_checklock_irqsave(&zone->lru_lock, &flags,
locked, cc);
if (!locked || fatal_signal_pending(current))
break;
if (!PageLRU(page))
continue;
if (PageTransHuge(page)) {
low_pfn += (1 << compound_order(page)) - 1;
continue;
}
if (!cc->sync)
mode |= ISOLATE_ASYNC_MIGRATE;
if (unevictable)
mode |= ISOLATE_UNEVICTABLE;
lruvec = mem_cgroup_page_lruvec(page, zone);
if (__isolate_lru_page(page, mode) != 0)
continue;
VM_BUG_ON_PAGE(PageTransCompound(page), page);
cc->finished_update_migrate = true;
del_page_from_lru_list(page, lruvec, page_lru(page));
list_add(&page->lru, migratelist);
cc->nr_migratepages++;
nr_isolated++;
check_compact_cluster:
if (cc->nr_migratepages == COMPACT_CLUSTER_MAX) {
++low_pfn;
break;
}
continue;
next_pageblock:
low_pfn = ALIGN(low_pfn + 1, pageblock_nr_pages) - 1;
last_pageblock_nr = pageblock_nr;
}
acct_isolated(zone, locked, cc);
if (locked)
spin_unlock_irqrestore(&zone->lru_lock, flags);
if (low_pfn == end_pfn && !skipped_async_unsuitable)
update_pageblock_skip(cc, valid_page, nr_isolated, true);
trace_mm_compaction_isolate_migratepages(nr_scanned, nr_isolated);
count_compact_events(COMPACTMIGRATE_SCANNED, nr_scanned);
if (nr_isolated)
count_compact_events(COMPACTISOLATED, nr_isolated);
return low_pfn;
}
static void isolate_freepages(struct zone *zone,
struct compact_control *cc)
{
struct page *page;
unsigned long high_pfn, low_pfn, pfn, z_end_pfn, end_pfn;
int nr_freepages = cc->nr_freepages;
struct list_head *freelist = &cc->freepages;
pfn = cc->free_pfn;
low_pfn = ALIGN(cc->migrate_pfn + 1, pageblock_nr_pages);
high_pfn = min(low_pfn, pfn);
z_end_pfn = zone_end_pfn(zone);
for (; pfn >= low_pfn && cc->nr_migratepages > nr_freepages;
pfn -= pageblock_nr_pages) {
unsigned long isolated;
cond_resched();
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (page_zone(page) != zone)
continue;
if (!suitable_migration_target(page))
continue;
if (!isolation_suitable(cc, page))
continue;
isolated = 0;
end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
end_pfn = min(end_pfn, z_end_pfn);
isolated = isolate_freepages_block(cc, pfn, end_pfn,
freelist, false);
nr_freepages += isolated;
if (isolated) {
cc->finished_update_free = true;
high_pfn = max(high_pfn, pfn);
}
}
map_pages(freelist);
if (pfn < low_pfn)
cc->free_pfn = max(pfn, zone->zone_start_pfn);
else
cc->free_pfn = high_pfn;
cc->nr_freepages = nr_freepages;
}
static struct page *compaction_alloc(struct page *migratepage,
unsigned long data,
int **result)
{
struct compact_control *cc = (struct compact_control *)data;
struct page *freepage;
if (list_empty(&cc->freepages)) {
isolate_freepages(cc->zone, cc);
if (list_empty(&cc->freepages))
return NULL;
}
freepage = list_entry(cc->freepages.next, struct page, lru);
list_del(&freepage->lru);
cc->nr_freepages--;
return freepage;
}
static void update_nr_listpages(struct compact_control *cc)
{
int nr_migratepages = 0;
int nr_freepages = 0;
struct page *page;
list_for_each_entry(page, &cc->migratepages, lru)
nr_migratepages++;
list_for_each_entry(page, &cc->freepages, lru)
nr_freepages++;
cc->nr_migratepages = nr_migratepages;
cc->nr_freepages = nr_freepages;
}
static isolate_migrate_t isolate_migratepages(struct zone *zone,
struct compact_control *cc)
{
unsigned long low_pfn, end_pfn;
low_pfn = max(cc->migrate_pfn, zone->zone_start_pfn);
end_pfn = ALIGN(low_pfn + 1, pageblock_nr_pages);
if (end_pfn > cc->free_pfn || !pfn_valid(low_pfn)) {
cc->migrate_pfn = end_pfn;
return ISOLATE_NONE;
}
low_pfn = isolate_migratepages_range(zone, cc, low_pfn, end_pfn, false);
if (!low_pfn || cc->contended)
return ISOLATE_ABORT;
cc->migrate_pfn = low_pfn;
return ISOLATE_SUCCESS;
}
static int compact_finished(struct zone *zone,
struct compact_control *cc)
{
unsigned int order;
unsigned long watermark;
if (fatal_signal_pending(current))
return COMPACT_PARTIAL;
if (cc->free_pfn <= cc->migrate_pfn) {
zone->compact_cached_migrate_pfn = zone->zone_start_pfn;
zone->compact_cached_free_pfn = zone_end_pfn(zone);
if (!current_is_kswapd())
zone->compact_blockskip_flush = true;
return COMPACT_COMPLETE;
}
if (cc->order == -1)
return COMPACT_CONTINUE;
watermark = low_wmark_pages(zone);
watermark += (1 << cc->order);
if (!zone_watermark_ok(zone, cc->order, watermark, 0, 0))
return COMPACT_CONTINUE;
for (order = cc->order; order < MAX_ORDER; order++) {
struct free_area *area = &zone->free_area[order];
if (!list_empty(&area->free_list[cc->migratetype]))
return COMPACT_PARTIAL;
if (cc->order >= pageblock_order && area->nr_free)
return COMPACT_PARTIAL;
}
return COMPACT_CONTINUE;
}
unsigned long compaction_suitable(struct zone *zone, int order)
{
int fragindex;
unsigned long watermark;
if (order == -1)
return COMPACT_CONTINUE;
watermark = low_wmark_pages(zone) + (2UL << order);
if (!zone_watermark_ok(zone, 0, watermark, 0, 0))
return COMPACT_SKIPPED;
fragindex = fragmentation_index(zone, order);
if (fragindex >= 0 && fragindex <= sysctl_extfrag_threshold)
return COMPACT_SKIPPED;
if (fragindex == -1000 && zone_watermark_ok(zone, order, watermark,
0, 0))
return COMPACT_PARTIAL;
return COMPACT_CONTINUE;
}
static int compact_zone(struct zone *zone, struct compact_control *cc)
{
int ret;
unsigned long start_pfn = zone->zone_start_pfn;
unsigned long end_pfn = zone_end_pfn(zone);
ret = compaction_suitable(zone, cc->order);
switch (ret) {
case COMPACT_PARTIAL:
case COMPACT_SKIPPED:
return ret;
case COMPACT_CONTINUE:
;
}
if (compaction_restarting(zone, cc->order) && !current_is_kswapd())
__reset_isolation_suitable(zone);
cc->migrate_pfn = zone->compact_cached_migrate_pfn;
cc->free_pfn = zone->compact_cached_free_pfn;
if (cc->free_pfn < start_pfn || cc->free_pfn > end_pfn) {
cc->free_pfn = end_pfn & ~(pageblock_nr_pages-1);
zone->compact_cached_free_pfn = cc->free_pfn;
}
if (cc->migrate_pfn < start_pfn || cc->migrate_pfn > end_pfn) {
cc->migrate_pfn = start_pfn;
zone->compact_cached_migrate_pfn = cc->migrate_pfn;
}
trace_mm_compaction_begin(start_pfn, cc->migrate_pfn, cc->free_pfn, end_pfn);
migrate_prep_local();
while ((ret = compact_finished(zone, cc)) == COMPACT_CONTINUE) {
unsigned long nr_migrate, nr_remaining;
int err;
switch (isolate_migratepages(zone, cc)) {
case ISOLATE_ABORT:
ret = COMPACT_PARTIAL;
putback_movable_pages(&cc->migratepages);
cc->nr_migratepages = 0;
goto out;
case ISOLATE_NONE:
continue;
case ISOLATE_SUCCESS:
;
}
nr_migrate = cc->nr_migratepages;
err = migrate_pages(&cc->migratepages, compaction_alloc,
(unsigned long)cc,
cc->sync ? MIGRATE_SYNC_LIGHT : MIGRATE_ASYNC,
MR_COMPACTION);
update_nr_listpages(cc);
nr_remaining = cc->nr_migratepages;
trace_mm_compaction_migratepages(nr_migrate - nr_remaining,
nr_remaining);
if (err) {
putback_movable_pages(&cc->migratepages);
cc->nr_migratepages = 0;
if (err == -ENOMEM && cc->free_pfn > cc->migrate_pfn) {
ret = COMPACT_PARTIAL;
goto out;
}
}
}
out:
cc->nr_freepages -= release_freepages(&cc->freepages);
VM_BUG_ON(cc->nr_freepages != 0);
trace_mm_compaction_end(ret);
return ret;
}
static unsigned long compact_zone_order(struct zone *zone,
int order, gfp_t gfp_mask,
bool sync, bool *contended)
{
unsigned long ret;
struct compact_control cc = {
.nr_freepages = 0,
.nr_migratepages = 0,
.order = order,
.migratetype = allocflags_to_migratetype(gfp_mask),
.zone = zone,
.sync = sync,
};
INIT_LIST_HEAD(&cc.freepages);
INIT_LIST_HEAD(&cc.migratepages);
ret = compact_zone(zone, &cc);
VM_BUG_ON(!list_empty(&cc.freepages));
VM_BUG_ON(!list_empty(&cc.migratepages));
*contended = cc.contended;
return ret;
}
unsigned long try_to_compact_pages(struct zonelist *zonelist,
int order, gfp_t gfp_mask, nodemask_t *nodemask,
bool sync, bool *contended)
{
enum zone_type high_zoneidx = gfp_zone(gfp_mask);
int may_enter_fs = gfp_mask & __GFP_FS;
int may_perform_io = gfp_mask & __GFP_IO;
struct zoneref *z;
struct zone *zone;
int rc = COMPACT_SKIPPED;
int alloc_flags = 0;
if (!order || !may_enter_fs || !may_perform_io)
return rc;
count_compact_event(COMPACTSTALL);
#ifdef CONFIG_CMA
if (allocflags_to_migratetype(gfp_mask) == MIGRATE_MOVABLE)
alloc_flags |= ALLOC_CMA;
#endif
for_each_zone_zonelist_nodemask(zone, z, zonelist, high_zoneidx,
nodemask) {
int status;
status = compact_zone_order(zone, order, gfp_mask, sync,
contended);
rc = max(status, rc);
if (zone_watermark_ok(zone, order, low_wmark_pages(zone), 0,
alloc_flags))
break;
}
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
if (cc->order == -1 || !compaction_deferred(zone, cc->order))
compact_zone(zone, cc);
if (cc->order > 0) {
if (zone_watermark_ok(zone, cc->order,
low_wmark_pages(zone), 0, 0))
compaction_defer_reset(zone, cc->order, false);
else if (cc->sync)
defer_compaction(zone, cc->order);
}
VM_BUG_ON(!list_empty(&cc->freepages));
VM_BUG_ON(!list_empty(&cc->migratepages));
}
}
void compact_pgdat(pg_data_t *pgdat, int order)
{
struct compact_control cc = {
.order = order,
.sync = false,
};
if (!order)
return;
__compact_pgdat(pgdat, &cc);
}
static void compact_node(int nid)
{
struct compact_control cc = {
.order = -1,
.sync = true,
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
ssize_t sysfs_compact_node(struct device *dev,
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
