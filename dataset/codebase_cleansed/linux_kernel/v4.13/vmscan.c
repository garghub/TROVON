static bool global_reclaim(struct scan_control *sc)
{
return !sc->target_mem_cgroup;
}
static bool sane_reclaim(struct scan_control *sc)
{
struct mem_cgroup *memcg = sc->target_mem_cgroup;
if (!memcg)
return true;
#ifdef CONFIG_CGROUP_WRITEBACK
if (cgroup_subsys_on_dfl(memory_cgrp_subsys))
return true;
#endif
return false;
}
static bool global_reclaim(struct scan_control *sc)
{
return true;
}
static bool sane_reclaim(struct scan_control *sc)
{
return true;
}
unsigned long zone_reclaimable_pages(struct zone *zone)
{
unsigned long nr;
nr = zone_page_state_snapshot(zone, NR_ZONE_INACTIVE_FILE) +
zone_page_state_snapshot(zone, NR_ZONE_ACTIVE_FILE);
if (get_nr_swap_pages() > 0)
nr += zone_page_state_snapshot(zone, NR_ZONE_INACTIVE_ANON) +
zone_page_state_snapshot(zone, NR_ZONE_ACTIVE_ANON);
return nr;
}
unsigned long pgdat_reclaimable_pages(struct pglist_data *pgdat)
{
unsigned long nr;
nr = node_page_state_snapshot(pgdat, NR_ACTIVE_FILE) +
node_page_state_snapshot(pgdat, NR_INACTIVE_FILE) +
node_page_state_snapshot(pgdat, NR_ISOLATED_FILE);
if (get_nr_swap_pages() > 0)
nr += node_page_state_snapshot(pgdat, NR_ACTIVE_ANON) +
node_page_state_snapshot(pgdat, NR_INACTIVE_ANON) +
node_page_state_snapshot(pgdat, NR_ISOLATED_ANON);
return nr;
}
unsigned long lruvec_lru_size(struct lruvec *lruvec, enum lru_list lru, int zone_idx)
{
unsigned long lru_size;
int zid;
if (!mem_cgroup_disabled())
lru_size = mem_cgroup_get_lru_size(lruvec, lru);
else
lru_size = node_page_state(lruvec_pgdat(lruvec), NR_LRU_BASE + lru);
for (zid = zone_idx + 1; zid < MAX_NR_ZONES; zid++) {
struct zone *zone = &lruvec_pgdat(lruvec)->node_zones[zid];
unsigned long size;
if (!managed_zone(zone))
continue;
if (!mem_cgroup_disabled())
size = mem_cgroup_get_zone_lru_size(lruvec, lru, zid);
else
size = zone_page_state(&lruvec_pgdat(lruvec)->node_zones[zid],
NR_ZONE_LRU_BASE + lru);
lru_size -= min(size, lru_size);
}
return lru_size;
}
int register_shrinker(struct shrinker *shrinker)
{
size_t size = sizeof(*shrinker->nr_deferred);
if (shrinker->flags & SHRINKER_NUMA_AWARE)
size *= nr_node_ids;
shrinker->nr_deferred = kzalloc(size, GFP_KERNEL);
if (!shrinker->nr_deferred)
return -ENOMEM;
down_write(&shrinker_rwsem);
list_add_tail(&shrinker->list, &shrinker_list);
up_write(&shrinker_rwsem);
return 0;
}
void unregister_shrinker(struct shrinker *shrinker)
{
down_write(&shrinker_rwsem);
list_del(&shrinker->list);
up_write(&shrinker_rwsem);
kfree(shrinker->nr_deferred);
}
static unsigned long do_shrink_slab(struct shrink_control *shrinkctl,
struct shrinker *shrinker,
unsigned long nr_scanned,
unsigned long nr_eligible)
{
unsigned long freed = 0;
unsigned long long delta;
long total_scan;
long freeable;
long nr;
long new_nr;
int nid = shrinkctl->nid;
long batch_size = shrinker->batch ? shrinker->batch
: SHRINK_BATCH;
long scanned = 0, next_deferred;
freeable = shrinker->count_objects(shrinker, shrinkctl);
if (freeable == 0)
return 0;
nr = atomic_long_xchg(&shrinker->nr_deferred[nid], 0);
total_scan = nr;
delta = (4 * nr_scanned) / shrinker->seeks;
delta *= freeable;
do_div(delta, nr_eligible + 1);
total_scan += delta;
if (total_scan < 0) {
pr_err("shrink_slab: %pF negative objects to delete nr=%ld\n",
shrinker->scan_objects, total_scan);
total_scan = freeable;
next_deferred = nr;
} else
next_deferred = total_scan;
if (delta < freeable / 4)
total_scan = min(total_scan, freeable / 2);
if (total_scan > freeable * 2)
total_scan = freeable * 2;
trace_mm_shrink_slab_start(shrinker, shrinkctl, nr,
nr_scanned, nr_eligible,
freeable, delta, total_scan);
while (total_scan >= batch_size ||
total_scan >= freeable) {
unsigned long ret;
unsigned long nr_to_scan = min(batch_size, total_scan);
shrinkctl->nr_to_scan = nr_to_scan;
ret = shrinker->scan_objects(shrinker, shrinkctl);
if (ret == SHRINK_STOP)
break;
freed += ret;
count_vm_events(SLABS_SCANNED, nr_to_scan);
total_scan -= nr_to_scan;
scanned += nr_to_scan;
cond_resched();
}
if (next_deferred >= scanned)
next_deferred -= scanned;
else
next_deferred = 0;
if (next_deferred > 0)
new_nr = atomic_long_add_return(next_deferred,
&shrinker->nr_deferred[nid]);
else
new_nr = atomic_long_read(&shrinker->nr_deferred[nid]);
trace_mm_shrink_slab_end(shrinker, nid, freed, nr, new_nr, total_scan);
return freed;
}
static unsigned long shrink_slab(gfp_t gfp_mask, int nid,
struct mem_cgroup *memcg,
unsigned long nr_scanned,
unsigned long nr_eligible)
{
struct shrinker *shrinker;
unsigned long freed = 0;
if (memcg && (!memcg_kmem_enabled() || !mem_cgroup_online(memcg)))
return 0;
if (nr_scanned == 0)
nr_scanned = SWAP_CLUSTER_MAX;
if (!down_read_trylock(&shrinker_rwsem)) {
freed = 1;
goto out;
}
list_for_each_entry(shrinker, &shrinker_list, list) {
struct shrink_control sc = {
.gfp_mask = gfp_mask,
.nid = nid,
.memcg = memcg,
};
if (memcg_kmem_enabled() &&
!!memcg != !!(shrinker->flags & SHRINKER_MEMCG_AWARE))
continue;
if (!(shrinker->flags & SHRINKER_NUMA_AWARE))
sc.nid = 0;
freed += do_shrink_slab(&sc, shrinker, nr_scanned, nr_eligible);
}
up_read(&shrinker_rwsem);
out:
cond_resched();
return freed;
}
void drop_slab_node(int nid)
{
unsigned long freed;
do {
struct mem_cgroup *memcg = NULL;
freed = 0;
do {
freed += shrink_slab(GFP_KERNEL, nid, memcg,
1000, 1000);
} while ((memcg = mem_cgroup_iter(NULL, memcg, NULL)) != NULL);
} while (freed > 10);
}
void drop_slab(void)
{
int nid;
for_each_online_node(nid)
drop_slab_node(nid);
}
static inline int is_page_cache_freeable(struct page *page)
{
return page_count(page) - page_has_private(page) == 2;
}
static int may_write_to_inode(struct inode *inode, struct scan_control *sc)
{
if (current->flags & PF_SWAPWRITE)
return 1;
if (!inode_write_congested(inode))
return 1;
if (inode_to_bdi(inode) == current->backing_dev_info)
return 1;
return 0;
}
static void handle_write_error(struct address_space *mapping,
struct page *page, int error)
{
lock_page(page);
if (page_mapping(page) == mapping)
mapping_set_error(mapping, error);
unlock_page(page);
}
static pageout_t pageout(struct page *page, struct address_space *mapping,
struct scan_control *sc)
{
if (!is_page_cache_freeable(page))
return PAGE_KEEP;
if (!mapping) {
if (page_has_private(page)) {
if (try_to_free_buffers(page)) {
ClearPageDirty(page);
pr_info("%s: orphaned page\n", __func__);
return PAGE_CLEAN;
}
}
return PAGE_KEEP;
}
if (mapping->a_ops->writepage == NULL)
return PAGE_ACTIVATE;
if (!may_write_to_inode(mapping->host, sc))
return PAGE_KEEP;
if (clear_page_dirty_for_io(page)) {
int res;
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
.nr_to_write = SWAP_CLUSTER_MAX,
.range_start = 0,
.range_end = LLONG_MAX,
.for_reclaim = 1,
};
SetPageReclaim(page);
res = mapping->a_ops->writepage(page, &wbc);
if (res < 0)
handle_write_error(mapping, page, res);
if (res == AOP_WRITEPAGE_ACTIVATE) {
ClearPageReclaim(page);
return PAGE_ACTIVATE;
}
if (!PageWriteback(page)) {
ClearPageReclaim(page);
}
trace_mm_vmscan_writepage(page);
inc_node_page_state(page, NR_VMSCAN_WRITE);
return PAGE_SUCCESS;
}
return PAGE_CLEAN;
}
static int __remove_mapping(struct address_space *mapping, struct page *page,
bool reclaimed)
{
unsigned long flags;
BUG_ON(!PageLocked(page));
BUG_ON(mapping != page_mapping(page));
spin_lock_irqsave(&mapping->tree_lock, flags);
if (!page_ref_freeze(page, 2))
goto cannot_free;
if (unlikely(PageDirty(page))) {
page_ref_unfreeze(page, 2);
goto cannot_free;
}
if (PageSwapCache(page)) {
swp_entry_t swap = { .val = page_private(page) };
mem_cgroup_swapout(page, swap);
__delete_from_swap_cache(page);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
put_swap_page(page, swap);
} else {
void (*freepage)(struct page *);
void *shadow = NULL;
freepage = mapping->a_ops->freepage;
if (reclaimed && page_is_file_cache(page) &&
!mapping_exiting(mapping) && !dax_mapping(mapping))
shadow = workingset_eviction(mapping, page);
__delete_from_page_cache(page, shadow);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
if (freepage != NULL)
freepage(page);
}
return 1;
cannot_free:
spin_unlock_irqrestore(&mapping->tree_lock, flags);
return 0;
}
int remove_mapping(struct address_space *mapping, struct page *page)
{
if (__remove_mapping(mapping, page, false)) {
page_ref_unfreeze(page, 1);
return 1;
}
return 0;
}
void putback_lru_page(struct page *page)
{
bool is_unevictable;
int was_unevictable = PageUnevictable(page);
VM_BUG_ON_PAGE(PageLRU(page), page);
redo:
ClearPageUnevictable(page);
if (page_evictable(page)) {
is_unevictable = false;
lru_cache_add(page);
} else {
is_unevictable = true;
add_page_to_unevictable_list(page);
smp_mb();
}
if (is_unevictable && page_evictable(page)) {
if (!isolate_lru_page(page)) {
put_page(page);
goto redo;
}
}
if (was_unevictable && !is_unevictable)
count_vm_event(UNEVICTABLE_PGRESCUED);
else if (!was_unevictable && is_unevictable)
count_vm_event(UNEVICTABLE_PGCULLED);
put_page(page);
}
static enum page_references page_check_references(struct page *page,
struct scan_control *sc)
{
int referenced_ptes, referenced_page;
unsigned long vm_flags;
referenced_ptes = page_referenced(page, 1, sc->target_mem_cgroup,
&vm_flags);
referenced_page = TestClearPageReferenced(page);
if (vm_flags & VM_LOCKED)
return PAGEREF_RECLAIM;
if (referenced_ptes) {
if (PageSwapBacked(page))
return PAGEREF_ACTIVATE;
SetPageReferenced(page);
if (referenced_page || referenced_ptes > 1)
return PAGEREF_ACTIVATE;
if (vm_flags & VM_EXEC)
return PAGEREF_ACTIVATE;
return PAGEREF_KEEP;
}
if (referenced_page && !PageSwapBacked(page))
return PAGEREF_RECLAIM_CLEAN;
return PAGEREF_RECLAIM;
}
static void page_check_dirty_writeback(struct page *page,
bool *dirty, bool *writeback)
{
struct address_space *mapping;
if (!page_is_file_cache(page) ||
(PageAnon(page) && !PageSwapBacked(page))) {
*dirty = false;
*writeback = false;
return;
}
*dirty = PageDirty(page);
*writeback = PageWriteback(page);
if (!page_has_private(page))
return;
mapping = page_mapping(page);
if (mapping && mapping->a_ops->is_dirty_writeback)
mapping->a_ops->is_dirty_writeback(page, dirty, writeback);
}
static unsigned long shrink_page_list(struct list_head *page_list,
struct pglist_data *pgdat,
struct scan_control *sc,
enum ttu_flags ttu_flags,
struct reclaim_stat *stat,
bool force_reclaim)
{
LIST_HEAD(ret_pages);
LIST_HEAD(free_pages);
int pgactivate = 0;
unsigned nr_unqueued_dirty = 0;
unsigned nr_dirty = 0;
unsigned nr_congested = 0;
unsigned nr_reclaimed = 0;
unsigned nr_writeback = 0;
unsigned nr_immediate = 0;
unsigned nr_ref_keep = 0;
unsigned nr_unmap_fail = 0;
cond_resched();
while (!list_empty(page_list)) {
struct address_space *mapping;
struct page *page;
int may_enter_fs;
enum page_references references = PAGEREF_RECLAIM_CLEAN;
bool dirty, writeback;
cond_resched();
page = lru_to_page(page_list);
list_del(&page->lru);
if (!trylock_page(page))
goto keep;
VM_BUG_ON_PAGE(PageActive(page), page);
sc->nr_scanned++;
if (unlikely(!page_evictable(page)))
goto activate_locked;
if (!sc->may_unmap && page_mapped(page))
goto keep_locked;
if ((page_mapped(page) || PageSwapCache(page)) &&
!(PageAnon(page) && !PageSwapBacked(page)))
sc->nr_scanned++;
may_enter_fs = (sc->gfp_mask & __GFP_FS) ||
(PageSwapCache(page) && (sc->gfp_mask & __GFP_IO));
page_check_dirty_writeback(page, &dirty, &writeback);
if (dirty || writeback)
nr_dirty++;
if (dirty && !writeback)
nr_unqueued_dirty++;
mapping = page_mapping(page);
if (((dirty || writeback) && mapping &&
inode_write_congested(mapping->host)) ||
(writeback && PageReclaim(page)))
nr_congested++;
if (PageWriteback(page)) {
if (current_is_kswapd() &&
PageReclaim(page) &&
test_bit(PGDAT_WRITEBACK, &pgdat->flags)) {
nr_immediate++;
goto activate_locked;
} else if (sane_reclaim(sc) ||
!PageReclaim(page) || !may_enter_fs) {
SetPageReclaim(page);
nr_writeback++;
goto activate_locked;
} else {
unlock_page(page);
wait_on_page_writeback(page);
list_add_tail(&page->lru, page_list);
continue;
}
}
if (!force_reclaim)
references = page_check_references(page, sc);
switch (references) {
case PAGEREF_ACTIVATE:
goto activate_locked;
case PAGEREF_KEEP:
nr_ref_keep++;
goto keep_locked;
case PAGEREF_RECLAIM:
case PAGEREF_RECLAIM_CLEAN:
;
}
if (PageAnon(page) && PageSwapBacked(page) &&
!PageSwapCache(page)) {
if (!(sc->gfp_mask & __GFP_IO))
goto keep_locked;
if (PageTransHuge(page)) {
if (!can_split_huge_page(page, NULL))
goto activate_locked;
if (!compound_mapcount(page) &&
split_huge_page_to_list(page, page_list))
goto activate_locked;
}
if (!add_to_swap(page)) {
if (!PageTransHuge(page))
goto activate_locked;
if (split_huge_page_to_list(page, page_list))
goto activate_locked;
if (!add_to_swap(page))
goto activate_locked;
}
if (PageTransHuge(page) &&
split_huge_page_to_list(page, page_list)) {
delete_from_swap_cache(page);
goto activate_locked;
}
may_enter_fs = 1;
mapping = page_mapping(page);
} else if (unlikely(PageTransHuge(page))) {
if (split_huge_page_to_list(page, page_list))
goto keep_locked;
}
VM_BUG_ON_PAGE(PageTransHuge(page), page);
if (page_mapped(page)) {
if (!try_to_unmap(page, ttu_flags | TTU_BATCH_FLUSH)) {
nr_unmap_fail++;
goto activate_locked;
}
}
if (PageDirty(page)) {
if (page_is_file_cache(page) &&
(!current_is_kswapd() || !PageReclaim(page) ||
!test_bit(PGDAT_DIRTY, &pgdat->flags))) {
inc_node_page_state(page, NR_VMSCAN_IMMEDIATE);
SetPageReclaim(page);
goto activate_locked;
}
if (references == PAGEREF_RECLAIM_CLEAN)
goto keep_locked;
if (!may_enter_fs)
goto keep_locked;
if (!sc->may_writepage)
goto keep_locked;
try_to_unmap_flush_dirty();
switch (pageout(page, mapping, sc)) {
case PAGE_KEEP:
goto keep_locked;
case PAGE_ACTIVATE:
goto activate_locked;
case PAGE_SUCCESS:
if (PageWriteback(page))
goto keep;
if (PageDirty(page))
goto keep;
if (!trylock_page(page))
goto keep;
if (PageDirty(page) || PageWriteback(page))
goto keep_locked;
mapping = page_mapping(page);
case PAGE_CLEAN:
;
}
}
if (page_has_private(page)) {
if (!try_to_release_page(page, sc->gfp_mask))
goto activate_locked;
if (!mapping && page_count(page) == 1) {
unlock_page(page);
if (put_page_testzero(page))
goto free_it;
else {
nr_reclaimed++;
continue;
}
}
}
if (PageAnon(page) && !PageSwapBacked(page)) {
if (!page_ref_freeze(page, 1))
goto keep_locked;
if (PageDirty(page)) {
page_ref_unfreeze(page, 1);
goto keep_locked;
}
count_vm_event(PGLAZYFREED);
count_memcg_page_event(page, PGLAZYFREED);
} else if (!mapping || !__remove_mapping(mapping, page, true))
goto keep_locked;
__ClearPageLocked(page);
free_it:
nr_reclaimed++;
list_add(&page->lru, &free_pages);
continue;
activate_locked:
if (PageSwapCache(page) && (mem_cgroup_swap_full(page) ||
PageMlocked(page)))
try_to_free_swap(page);
VM_BUG_ON_PAGE(PageActive(page), page);
if (!PageMlocked(page)) {
SetPageActive(page);
pgactivate++;
count_memcg_page_event(page, PGACTIVATE);
}
keep_locked:
unlock_page(page);
keep:
list_add(&page->lru, &ret_pages);
VM_BUG_ON_PAGE(PageLRU(page) || PageUnevictable(page), page);
}
mem_cgroup_uncharge_list(&free_pages);
try_to_unmap_flush();
free_hot_cold_page_list(&free_pages, true);
list_splice(&ret_pages, page_list);
count_vm_events(PGACTIVATE, pgactivate);
if (stat) {
stat->nr_dirty = nr_dirty;
stat->nr_congested = nr_congested;
stat->nr_unqueued_dirty = nr_unqueued_dirty;
stat->nr_writeback = nr_writeback;
stat->nr_immediate = nr_immediate;
stat->nr_activate = pgactivate;
stat->nr_ref_keep = nr_ref_keep;
stat->nr_unmap_fail = nr_unmap_fail;
}
return nr_reclaimed;
}
unsigned long reclaim_clean_pages_from_list(struct zone *zone,
struct list_head *page_list)
{
struct scan_control sc = {
.gfp_mask = GFP_KERNEL,
.priority = DEF_PRIORITY,
.may_unmap = 1,
};
unsigned long ret;
struct page *page, *next;
LIST_HEAD(clean_pages);
list_for_each_entry_safe(page, next, page_list, lru) {
if (page_is_file_cache(page) && !PageDirty(page) &&
!__PageMovable(page)) {
ClearPageActive(page);
list_move(&page->lru, &clean_pages);
}
}
ret = shrink_page_list(&clean_pages, zone->zone_pgdat, &sc,
TTU_IGNORE_ACCESS, NULL, true);
list_splice(&clean_pages, page_list);
mod_node_page_state(zone->zone_pgdat, NR_ISOLATED_FILE, -ret);
return ret;
}
int __isolate_lru_page(struct page *page, isolate_mode_t mode)
{
int ret = -EINVAL;
if (!PageLRU(page))
return ret;
if (PageUnevictable(page) && !(mode & ISOLATE_UNEVICTABLE))
return ret;
ret = -EBUSY;
if (mode & ISOLATE_ASYNC_MIGRATE) {
if (PageWriteback(page))
return ret;
if (PageDirty(page)) {
struct address_space *mapping;
mapping = page_mapping(page);
if (mapping && !mapping->a_ops->migratepage)
return ret;
}
}
if ((mode & ISOLATE_UNMAPPED) && page_mapped(page))
return ret;
if (likely(get_page_unless_zero(page))) {
ClearPageLRU(page);
ret = 0;
}
return ret;
}
static __always_inline void update_lru_sizes(struct lruvec *lruvec,
enum lru_list lru, unsigned long *nr_zone_taken)
{
int zid;
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
if (!nr_zone_taken[zid])
continue;
__update_lru_size(lruvec, lru, zid, -nr_zone_taken[zid]);
#ifdef CONFIG_MEMCG
mem_cgroup_update_lru_size(lruvec, lru, zid, -nr_zone_taken[zid]);
#endif
}
}
static unsigned long isolate_lru_pages(unsigned long nr_to_scan,
struct lruvec *lruvec, struct list_head *dst,
unsigned long *nr_scanned, struct scan_control *sc,
isolate_mode_t mode, enum lru_list lru)
{
struct list_head *src = &lruvec->lists[lru];
unsigned long nr_taken = 0;
unsigned long nr_zone_taken[MAX_NR_ZONES] = { 0 };
unsigned long nr_skipped[MAX_NR_ZONES] = { 0, };
unsigned long skipped = 0;
unsigned long scan, total_scan, nr_pages;
LIST_HEAD(pages_skipped);
scan = 0;
for (total_scan = 0;
scan < nr_to_scan && nr_taken < nr_to_scan && !list_empty(src);
total_scan++) {
struct page *page;
page = lru_to_page(src);
prefetchw_prev_lru_page(page, src, flags);
VM_BUG_ON_PAGE(!PageLRU(page), page);
if (page_zonenum(page) > sc->reclaim_idx) {
list_move(&page->lru, &pages_skipped);
nr_skipped[page_zonenum(page)]++;
continue;
}
scan++;
switch (__isolate_lru_page(page, mode)) {
case 0:
nr_pages = hpage_nr_pages(page);
nr_taken += nr_pages;
nr_zone_taken[page_zonenum(page)] += nr_pages;
list_move(&page->lru, dst);
break;
case -EBUSY:
list_move(&page->lru, src);
continue;
default:
BUG();
}
}
if (!list_empty(&pages_skipped)) {
int zid;
list_splice(&pages_skipped, src);
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
if (!nr_skipped[zid])
continue;
__count_zid_vm_events(PGSCAN_SKIP, zid, nr_skipped[zid]);
skipped += nr_skipped[zid];
}
}
*nr_scanned = total_scan;
trace_mm_vmscan_lru_isolate(sc->reclaim_idx, sc->order, nr_to_scan,
total_scan, skipped, nr_taken, mode, lru);
update_lru_sizes(lruvec, lru, nr_zone_taken);
return nr_taken;
}
int isolate_lru_page(struct page *page)
{
int ret = -EBUSY;
VM_BUG_ON_PAGE(!page_count(page), page);
WARN_RATELIMIT(PageTail(page), "trying to isolate tail page");
if (PageLRU(page)) {
struct zone *zone = page_zone(page);
struct lruvec *lruvec;
spin_lock_irq(zone_lru_lock(zone));
lruvec = mem_cgroup_page_lruvec(page, zone->zone_pgdat);
if (PageLRU(page)) {
int lru = page_lru(page);
get_page(page);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, lru);
ret = 0;
}
spin_unlock_irq(zone_lru_lock(zone));
}
return ret;
}
static int too_many_isolated(struct pglist_data *pgdat, int file,
struct scan_control *sc)
{
unsigned long inactive, isolated;
if (current_is_kswapd())
return 0;
if (!sane_reclaim(sc))
return 0;
if (file) {
inactive = node_page_state(pgdat, NR_INACTIVE_FILE);
isolated = node_page_state(pgdat, NR_ISOLATED_FILE);
} else {
inactive = node_page_state(pgdat, NR_INACTIVE_ANON);
isolated = node_page_state(pgdat, NR_ISOLATED_ANON);
}
if ((sc->gfp_mask & (__GFP_IO | __GFP_FS)) == (__GFP_IO | __GFP_FS))
inactive >>= 3;
return isolated > inactive;
}
static noinline_for_stack void
putback_inactive_pages(struct lruvec *lruvec, struct list_head *page_list)
{
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
LIST_HEAD(pages_to_free);
while (!list_empty(page_list)) {
struct page *page = lru_to_page(page_list);
int lru;
VM_BUG_ON_PAGE(PageLRU(page), page);
list_del(&page->lru);
if (unlikely(!page_evictable(page))) {
spin_unlock_irq(&pgdat->lru_lock);
putback_lru_page(page);
spin_lock_irq(&pgdat->lru_lock);
continue;
}
lruvec = mem_cgroup_page_lruvec(page, pgdat);
SetPageLRU(page);
lru = page_lru(page);
add_page_to_lru_list(page, lruvec, lru);
if (is_active_lru(lru)) {
int file = is_file_lru(lru);
int numpages = hpage_nr_pages(page);
reclaim_stat->recent_rotated[file] += numpages;
}
if (put_page_testzero(page)) {
__ClearPageLRU(page);
__ClearPageActive(page);
del_page_from_lru_list(page, lruvec, lru);
if (unlikely(PageCompound(page))) {
spin_unlock_irq(&pgdat->lru_lock);
mem_cgroup_uncharge(page);
(*get_compound_page_dtor(page))(page);
spin_lock_irq(&pgdat->lru_lock);
} else
list_add(&page->lru, &pages_to_free);
}
}
list_splice(&pages_to_free, page_list);
}
static int current_may_throttle(void)
{
return !(current->flags & PF_LESS_THROTTLE) ||
current->backing_dev_info == NULL ||
bdi_write_congested(current->backing_dev_info);
}
static noinline_for_stack unsigned long
shrink_inactive_list(unsigned long nr_to_scan, struct lruvec *lruvec,
struct scan_control *sc, enum lru_list lru)
{
LIST_HEAD(page_list);
unsigned long nr_scanned;
unsigned long nr_reclaimed = 0;
unsigned long nr_taken;
struct reclaim_stat stat = {};
isolate_mode_t isolate_mode = 0;
int file = is_file_lru(lru);
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
while (unlikely(too_many_isolated(pgdat, file, sc))) {
congestion_wait(BLK_RW_ASYNC, HZ/10);
if (fatal_signal_pending(current))
return SWAP_CLUSTER_MAX;
}
lru_add_drain();
if (!sc->may_unmap)
isolate_mode |= ISOLATE_UNMAPPED;
spin_lock_irq(&pgdat->lru_lock);
nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &page_list,
&nr_scanned, sc, isolate_mode, lru);
__mod_node_page_state(pgdat, NR_ISOLATED_ANON + file, nr_taken);
reclaim_stat->recent_scanned[file] += nr_taken;
if (current_is_kswapd()) {
if (global_reclaim(sc))
__count_vm_events(PGSCAN_KSWAPD, nr_scanned);
count_memcg_events(lruvec_memcg(lruvec), PGSCAN_KSWAPD,
nr_scanned);
} else {
if (global_reclaim(sc))
__count_vm_events(PGSCAN_DIRECT, nr_scanned);
count_memcg_events(lruvec_memcg(lruvec), PGSCAN_DIRECT,
nr_scanned);
}
spin_unlock_irq(&pgdat->lru_lock);
if (nr_taken == 0)
return 0;
nr_reclaimed = shrink_page_list(&page_list, pgdat, sc, 0,
&stat, false);
spin_lock_irq(&pgdat->lru_lock);
if (current_is_kswapd()) {
if (global_reclaim(sc))
__count_vm_events(PGSTEAL_KSWAPD, nr_reclaimed);
count_memcg_events(lruvec_memcg(lruvec), PGSTEAL_KSWAPD,
nr_reclaimed);
} else {
if (global_reclaim(sc))
__count_vm_events(PGSTEAL_DIRECT, nr_reclaimed);
count_memcg_events(lruvec_memcg(lruvec), PGSTEAL_DIRECT,
nr_reclaimed);
}
putback_inactive_pages(lruvec, &page_list);
__mod_node_page_state(pgdat, NR_ISOLATED_ANON + file, -nr_taken);
spin_unlock_irq(&pgdat->lru_lock);
mem_cgroup_uncharge_list(&page_list);
free_hot_cold_page_list(&page_list, true);
if (stat.nr_writeback && stat.nr_writeback == nr_taken)
set_bit(PGDAT_WRITEBACK, &pgdat->flags);
if (sane_reclaim(sc)) {
if (stat.nr_dirty && stat.nr_dirty == stat.nr_congested)
set_bit(PGDAT_CONGESTED, &pgdat->flags);
if (stat.nr_unqueued_dirty == nr_taken) {
wakeup_flusher_threads(0, WB_REASON_VMSCAN);
set_bit(PGDAT_DIRTY, &pgdat->flags);
}
if (stat.nr_immediate && current_may_throttle())
congestion_wait(BLK_RW_ASYNC, HZ/10);
}
if (!sc->hibernation_mode && !current_is_kswapd() &&
current_may_throttle())
wait_iff_congested(pgdat, BLK_RW_ASYNC, HZ/10);
trace_mm_vmscan_lru_shrink_inactive(pgdat->node_id,
nr_scanned, nr_reclaimed,
stat.nr_dirty, stat.nr_writeback,
stat.nr_congested, stat.nr_immediate,
stat.nr_activate, stat.nr_ref_keep,
stat.nr_unmap_fail,
sc->priority, file);
return nr_reclaimed;
}
static unsigned move_active_pages_to_lru(struct lruvec *lruvec,
struct list_head *list,
struct list_head *pages_to_free,
enum lru_list lru)
{
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
struct page *page;
int nr_pages;
int nr_moved = 0;
while (!list_empty(list)) {
page = lru_to_page(list);
lruvec = mem_cgroup_page_lruvec(page, pgdat);
VM_BUG_ON_PAGE(PageLRU(page), page);
SetPageLRU(page);
nr_pages = hpage_nr_pages(page);
update_lru_size(lruvec, lru, page_zonenum(page), nr_pages);
list_move(&page->lru, &lruvec->lists[lru]);
if (put_page_testzero(page)) {
__ClearPageLRU(page);
__ClearPageActive(page);
del_page_from_lru_list(page, lruvec, lru);
if (unlikely(PageCompound(page))) {
spin_unlock_irq(&pgdat->lru_lock);
mem_cgroup_uncharge(page);
(*get_compound_page_dtor(page))(page);
spin_lock_irq(&pgdat->lru_lock);
} else
list_add(&page->lru, pages_to_free);
} else {
nr_moved += nr_pages;
}
}
if (!is_active_lru(lru)) {
__count_vm_events(PGDEACTIVATE, nr_moved);
count_memcg_events(lruvec_memcg(lruvec), PGDEACTIVATE,
nr_moved);
}
return nr_moved;
}
static void shrink_active_list(unsigned long nr_to_scan,
struct lruvec *lruvec,
struct scan_control *sc,
enum lru_list lru)
{
unsigned long nr_taken;
unsigned long nr_scanned;
unsigned long vm_flags;
LIST_HEAD(l_hold);
LIST_HEAD(l_active);
LIST_HEAD(l_inactive);
struct page *page;
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
unsigned nr_deactivate, nr_activate;
unsigned nr_rotated = 0;
isolate_mode_t isolate_mode = 0;
int file = is_file_lru(lru);
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
lru_add_drain();
if (!sc->may_unmap)
isolate_mode |= ISOLATE_UNMAPPED;
spin_lock_irq(&pgdat->lru_lock);
nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &l_hold,
&nr_scanned, sc, isolate_mode, lru);
__mod_node_page_state(pgdat, NR_ISOLATED_ANON + file, nr_taken);
reclaim_stat->recent_scanned[file] += nr_taken;
__count_vm_events(PGREFILL, nr_scanned);
count_memcg_events(lruvec_memcg(lruvec), PGREFILL, nr_scanned);
spin_unlock_irq(&pgdat->lru_lock);
while (!list_empty(&l_hold)) {
cond_resched();
page = lru_to_page(&l_hold);
list_del(&page->lru);
if (unlikely(!page_evictable(page))) {
putback_lru_page(page);
continue;
}
if (unlikely(buffer_heads_over_limit)) {
if (page_has_private(page) && trylock_page(page)) {
if (page_has_private(page))
try_to_release_page(page, 0);
unlock_page(page);
}
}
if (page_referenced(page, 0, sc->target_mem_cgroup,
&vm_flags)) {
nr_rotated += hpage_nr_pages(page);
if ((vm_flags & VM_EXEC) && page_is_file_cache(page)) {
list_add(&page->lru, &l_active);
continue;
}
}
ClearPageActive(page);
list_add(&page->lru, &l_inactive);
}
spin_lock_irq(&pgdat->lru_lock);
reclaim_stat->recent_rotated[file] += nr_rotated;
nr_activate = move_active_pages_to_lru(lruvec, &l_active, &l_hold, lru);
nr_deactivate = move_active_pages_to_lru(lruvec, &l_inactive, &l_hold, lru - LRU_ACTIVE);
__mod_node_page_state(pgdat, NR_ISOLATED_ANON + file, -nr_taken);
spin_unlock_irq(&pgdat->lru_lock);
mem_cgroup_uncharge_list(&l_hold);
free_hot_cold_page_list(&l_hold, true);
trace_mm_vmscan_lru_shrink_active(pgdat->node_id, nr_taken, nr_activate,
nr_deactivate, nr_rotated, sc->priority, file);
}
static bool inactive_list_is_low(struct lruvec *lruvec, bool file,
struct mem_cgroup *memcg,
struct scan_control *sc, bool actual_reclaim)
{
enum lru_list active_lru = file * LRU_FILE + LRU_ACTIVE;
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
enum lru_list inactive_lru = file * LRU_FILE;
unsigned long inactive, active;
unsigned long inactive_ratio;
unsigned long refaults;
unsigned long gb;
if (!file && !total_swap_pages)
return false;
inactive = lruvec_lru_size(lruvec, inactive_lru, sc->reclaim_idx);
active = lruvec_lru_size(lruvec, active_lru, sc->reclaim_idx);
if (memcg)
refaults = memcg_page_state(memcg, WORKINGSET_ACTIVATE);
else
refaults = node_page_state(pgdat, WORKINGSET_ACTIVATE);
if (file && actual_reclaim && lruvec->refaults != refaults) {
inactive_ratio = 0;
} else {
gb = (inactive + active) >> (30 - PAGE_SHIFT);
if (gb)
inactive_ratio = int_sqrt(10 * gb);
else
inactive_ratio = 1;
}
if (actual_reclaim)
trace_mm_vmscan_inactive_list_is_low(pgdat->node_id, sc->reclaim_idx,
lruvec_lru_size(lruvec, inactive_lru, MAX_NR_ZONES), inactive,
lruvec_lru_size(lruvec, active_lru, MAX_NR_ZONES), active,
inactive_ratio, file);
return inactive * inactive_ratio < active;
}
static unsigned long shrink_list(enum lru_list lru, unsigned long nr_to_scan,
struct lruvec *lruvec, struct mem_cgroup *memcg,
struct scan_control *sc)
{
if (is_active_lru(lru)) {
if (inactive_list_is_low(lruvec, is_file_lru(lru),
memcg, sc, true))
shrink_active_list(nr_to_scan, lruvec, sc, lru);
return 0;
}
return shrink_inactive_list(nr_to_scan, lruvec, sc, lru);
}
static void get_scan_count(struct lruvec *lruvec, struct mem_cgroup *memcg,
struct scan_control *sc, unsigned long *nr,
unsigned long *lru_pages)
{
int swappiness = mem_cgroup_swappiness(memcg);
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
u64 fraction[2];
u64 denominator = 0;
struct pglist_data *pgdat = lruvec_pgdat(lruvec);
unsigned long anon_prio, file_prio;
enum scan_balance scan_balance;
unsigned long anon, file;
unsigned long ap, fp;
enum lru_list lru;
if (!sc->may_swap || mem_cgroup_get_nr_swap_pages(memcg) <= 0) {
scan_balance = SCAN_FILE;
goto out;
}
if (!global_reclaim(sc) && !swappiness) {
scan_balance = SCAN_FILE;
goto out;
}
if (!sc->priority && swappiness) {
scan_balance = SCAN_EQUAL;
goto out;
}
if (global_reclaim(sc)) {
unsigned long pgdatfile;
unsigned long pgdatfree;
int z;
unsigned long total_high_wmark = 0;
pgdatfree = sum_zone_node_page_state(pgdat->node_id, NR_FREE_PAGES);
pgdatfile = node_page_state(pgdat, NR_ACTIVE_FILE) +
node_page_state(pgdat, NR_INACTIVE_FILE);
for (z = 0; z < MAX_NR_ZONES; z++) {
struct zone *zone = &pgdat->node_zones[z];
if (!managed_zone(zone))
continue;
total_high_wmark += high_wmark_pages(zone);
}
if (unlikely(pgdatfile + pgdatfree <= total_high_wmark)) {
if (!inactive_list_is_low(lruvec, false, memcg, sc, false) &&
lruvec_lru_size(lruvec, LRU_INACTIVE_ANON, sc->reclaim_idx)
>> sc->priority) {
scan_balance = SCAN_ANON;
goto out;
}
}
}
if (!inactive_list_is_low(lruvec, true, memcg, sc, false) &&
lruvec_lru_size(lruvec, LRU_INACTIVE_FILE, sc->reclaim_idx) >> sc->priority) {
scan_balance = SCAN_FILE;
goto out;
}
scan_balance = SCAN_FRACT;
anon_prio = swappiness;
file_prio = 200 - anon_prio;
anon = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON, MAX_NR_ZONES) +
lruvec_lru_size(lruvec, LRU_INACTIVE_ANON, MAX_NR_ZONES);
file = lruvec_lru_size(lruvec, LRU_ACTIVE_FILE, MAX_NR_ZONES) +
lruvec_lru_size(lruvec, LRU_INACTIVE_FILE, MAX_NR_ZONES);
spin_lock_irq(&pgdat->lru_lock);
if (unlikely(reclaim_stat->recent_scanned[0] > anon / 4)) {
reclaim_stat->recent_scanned[0] /= 2;
reclaim_stat->recent_rotated[0] /= 2;
}
if (unlikely(reclaim_stat->recent_scanned[1] > file / 4)) {
reclaim_stat->recent_scanned[1] /= 2;
reclaim_stat->recent_rotated[1] /= 2;
}
ap = anon_prio * (reclaim_stat->recent_scanned[0] + 1);
ap /= reclaim_stat->recent_rotated[0] + 1;
fp = file_prio * (reclaim_stat->recent_scanned[1] + 1);
fp /= reclaim_stat->recent_rotated[1] + 1;
spin_unlock_irq(&pgdat->lru_lock);
fraction[0] = ap;
fraction[1] = fp;
denominator = ap + fp + 1;
out:
*lru_pages = 0;
for_each_evictable_lru(lru) {
int file = is_file_lru(lru);
unsigned long size;
unsigned long scan;
size = lruvec_lru_size(lruvec, lru, sc->reclaim_idx);
scan = size >> sc->priority;
if (!scan && !mem_cgroup_online(memcg))
scan = min(size, SWAP_CLUSTER_MAX);
switch (scan_balance) {
case SCAN_EQUAL:
break;
case SCAN_FRACT:
scan = div64_u64(scan * fraction[file],
denominator);
break;
case SCAN_FILE:
case SCAN_ANON:
if ((scan_balance == SCAN_FILE) != file) {
size = 0;
scan = 0;
}
break;
default:
BUG();
}
*lru_pages += size;
nr[lru] = scan;
}
}
static void shrink_node_memcg(struct pglist_data *pgdat, struct mem_cgroup *memcg,
struct scan_control *sc, unsigned long *lru_pages)
{
struct lruvec *lruvec = mem_cgroup_lruvec(pgdat, memcg);
unsigned long nr[NR_LRU_LISTS];
unsigned long targets[NR_LRU_LISTS];
unsigned long nr_to_scan;
enum lru_list lru;
unsigned long nr_reclaimed = 0;
unsigned long nr_to_reclaim = sc->nr_to_reclaim;
struct blk_plug plug;
bool scan_adjusted;
get_scan_count(lruvec, memcg, sc, nr, lru_pages);
memcpy(targets, nr, sizeof(nr));
scan_adjusted = (global_reclaim(sc) && !current_is_kswapd() &&
sc->priority == DEF_PRIORITY);
blk_start_plug(&plug);
while (nr[LRU_INACTIVE_ANON] || nr[LRU_ACTIVE_FILE] ||
nr[LRU_INACTIVE_FILE]) {
unsigned long nr_anon, nr_file, percentage;
unsigned long nr_scanned;
for_each_evictable_lru(lru) {
if (nr[lru]) {
nr_to_scan = min(nr[lru], SWAP_CLUSTER_MAX);
nr[lru] -= nr_to_scan;
nr_reclaimed += shrink_list(lru, nr_to_scan,
lruvec, memcg, sc);
}
}
cond_resched();
if (nr_reclaimed < nr_to_reclaim || scan_adjusted)
continue;
nr_file = nr[LRU_INACTIVE_FILE] + nr[LRU_ACTIVE_FILE];
nr_anon = nr[LRU_INACTIVE_ANON] + nr[LRU_ACTIVE_ANON];
if (!nr_file || !nr_anon)
break;
if (nr_file > nr_anon) {
unsigned long scan_target = targets[LRU_INACTIVE_ANON] +
targets[LRU_ACTIVE_ANON] + 1;
lru = LRU_BASE;
percentage = nr_anon * 100 / scan_target;
} else {
unsigned long scan_target = targets[LRU_INACTIVE_FILE] +
targets[LRU_ACTIVE_FILE] + 1;
lru = LRU_FILE;
percentage = nr_file * 100 / scan_target;
}
nr[lru] = 0;
nr[lru + LRU_ACTIVE] = 0;
lru = (lru == LRU_FILE) ? LRU_BASE : LRU_FILE;
nr_scanned = targets[lru] - nr[lru];
nr[lru] = targets[lru] * (100 - percentage) / 100;
nr[lru] -= min(nr[lru], nr_scanned);
lru += LRU_ACTIVE;
nr_scanned = targets[lru] - nr[lru];
nr[lru] = targets[lru] * (100 - percentage) / 100;
nr[lru] -= min(nr[lru], nr_scanned);
scan_adjusted = true;
}
blk_finish_plug(&plug);
sc->nr_reclaimed += nr_reclaimed;
if (inactive_list_is_low(lruvec, false, memcg, sc, true))
shrink_active_list(SWAP_CLUSTER_MAX, lruvec,
sc, LRU_ACTIVE_ANON);
}
static bool in_reclaim_compaction(struct scan_control *sc)
{
if (IS_ENABLED(CONFIG_COMPACTION) && sc->order &&
(sc->order > PAGE_ALLOC_COSTLY_ORDER ||
sc->priority < DEF_PRIORITY - 2))
return true;
return false;
}
static inline bool should_continue_reclaim(struct pglist_data *pgdat,
unsigned long nr_reclaimed,
unsigned long nr_scanned,
struct scan_control *sc)
{
unsigned long pages_for_compaction;
unsigned long inactive_lru_pages;
int z;
if (!in_reclaim_compaction(sc))
return false;
if (sc->gfp_mask & __GFP_RETRY_MAYFAIL) {
if (!nr_reclaimed && !nr_scanned)
return false;
} else {
if (!nr_reclaimed)
return false;
}
pages_for_compaction = compact_gap(sc->order);
inactive_lru_pages = node_page_state(pgdat, NR_INACTIVE_FILE);
if (get_nr_swap_pages() > 0)
inactive_lru_pages += node_page_state(pgdat, NR_INACTIVE_ANON);
if (sc->nr_reclaimed < pages_for_compaction &&
inactive_lru_pages > pages_for_compaction)
return true;
for (z = 0; z <= sc->reclaim_idx; z++) {
struct zone *zone = &pgdat->node_zones[z];
if (!managed_zone(zone))
continue;
switch (compaction_suitable(zone, sc->order, 0, sc->reclaim_idx)) {
case COMPACT_SUCCESS:
case COMPACT_CONTINUE:
return false;
default:
;
}
}
return true;
}
static bool shrink_node(pg_data_t *pgdat, struct scan_control *sc)
{
struct reclaim_state *reclaim_state = current->reclaim_state;
unsigned long nr_reclaimed, nr_scanned;
bool reclaimable = false;
do {
struct mem_cgroup *root = sc->target_mem_cgroup;
struct mem_cgroup_reclaim_cookie reclaim = {
.pgdat = pgdat,
.priority = sc->priority,
};
unsigned long node_lru_pages = 0;
struct mem_cgroup *memcg;
nr_reclaimed = sc->nr_reclaimed;
nr_scanned = sc->nr_scanned;
memcg = mem_cgroup_iter(root, NULL, &reclaim);
do {
unsigned long lru_pages;
unsigned long reclaimed;
unsigned long scanned;
if (mem_cgroup_low(root, memcg)) {
if (!sc->memcg_low_reclaim) {
sc->memcg_low_skipped = 1;
continue;
}
mem_cgroup_event(memcg, MEMCG_LOW);
}
reclaimed = sc->nr_reclaimed;
scanned = sc->nr_scanned;
shrink_node_memcg(pgdat, memcg, sc, &lru_pages);
node_lru_pages += lru_pages;
if (memcg)
shrink_slab(sc->gfp_mask, pgdat->node_id,
memcg, sc->nr_scanned - scanned,
lru_pages);
vmpressure(sc->gfp_mask, memcg, false,
sc->nr_scanned - scanned,
sc->nr_reclaimed - reclaimed);
if (!global_reclaim(sc) &&
sc->nr_reclaimed >= sc->nr_to_reclaim) {
mem_cgroup_iter_break(root, memcg);
break;
}
} while ((memcg = mem_cgroup_iter(root, memcg, &reclaim)));
if (global_reclaim(sc))
shrink_slab(sc->gfp_mask, pgdat->node_id, NULL,
sc->nr_scanned - nr_scanned,
node_lru_pages);
if (reclaim_state) {
sc->nr_reclaimed += reclaim_state->reclaimed_slab;
reclaim_state->reclaimed_slab = 0;
}
vmpressure(sc->gfp_mask, sc->target_mem_cgroup, true,
sc->nr_scanned - nr_scanned,
sc->nr_reclaimed - nr_reclaimed);
if (sc->nr_reclaimed - nr_reclaimed)
reclaimable = true;
} while (should_continue_reclaim(pgdat, sc->nr_reclaimed - nr_reclaimed,
sc->nr_scanned - nr_scanned, sc));
if (reclaimable)
pgdat->kswapd_failures = 0;
return reclaimable;
}
static inline bool compaction_ready(struct zone *zone, struct scan_control *sc)
{
unsigned long watermark;
enum compact_result suitable;
suitable = compaction_suitable(zone, sc->order, 0, sc->reclaim_idx);
if (suitable == COMPACT_SUCCESS)
return true;
if (suitable == COMPACT_SKIPPED)
return false;
watermark = high_wmark_pages(zone) + compact_gap(sc->order);
return zone_watermark_ok_safe(zone, 0, watermark, sc->reclaim_idx);
}
static void shrink_zones(struct zonelist *zonelist, struct scan_control *sc)
{
struct zoneref *z;
struct zone *zone;
unsigned long nr_soft_reclaimed;
unsigned long nr_soft_scanned;
gfp_t orig_mask;
pg_data_t *last_pgdat = NULL;
orig_mask = sc->gfp_mask;
if (buffer_heads_over_limit) {
sc->gfp_mask |= __GFP_HIGHMEM;
sc->reclaim_idx = gfp_zone(sc->gfp_mask);
}
for_each_zone_zonelist_nodemask(zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if (global_reclaim(sc)) {
if (!cpuset_zone_allowed(zone,
GFP_KERNEL | __GFP_HARDWALL))
continue;
if (IS_ENABLED(CONFIG_COMPACTION) &&
sc->order > PAGE_ALLOC_COSTLY_ORDER &&
compaction_ready(zone, sc)) {
sc->compaction_ready = true;
continue;
}
if (zone->zone_pgdat == last_pgdat)
continue;
nr_soft_scanned = 0;
nr_soft_reclaimed = mem_cgroup_soft_limit_reclaim(zone->zone_pgdat,
sc->order, sc->gfp_mask,
&nr_soft_scanned);
sc->nr_reclaimed += nr_soft_reclaimed;
sc->nr_scanned += nr_soft_scanned;
}
if (zone->zone_pgdat == last_pgdat)
continue;
last_pgdat = zone->zone_pgdat;
shrink_node(zone->zone_pgdat, sc);
}
sc->gfp_mask = orig_mask;
}
static void snapshot_refaults(struct mem_cgroup *root_memcg, pg_data_t *pgdat)
{
struct mem_cgroup *memcg;
memcg = mem_cgroup_iter(root_memcg, NULL, NULL);
do {
unsigned long refaults;
struct lruvec *lruvec;
if (memcg)
refaults = memcg_page_state(memcg, WORKINGSET_ACTIVATE);
else
refaults = node_page_state(pgdat, WORKINGSET_ACTIVATE);
lruvec = mem_cgroup_lruvec(pgdat, memcg);
lruvec->refaults = refaults;
} while ((memcg = mem_cgroup_iter(root_memcg, memcg, NULL)));
}
static unsigned long do_try_to_free_pages(struct zonelist *zonelist,
struct scan_control *sc)
{
int initial_priority = sc->priority;
pg_data_t *last_pgdat;
struct zoneref *z;
struct zone *zone;
retry:
delayacct_freepages_start();
if (global_reclaim(sc))
__count_zid_vm_events(ALLOCSTALL, sc->reclaim_idx, 1);
do {
vmpressure_prio(sc->gfp_mask, sc->target_mem_cgroup,
sc->priority);
sc->nr_scanned = 0;
shrink_zones(zonelist, sc);
if (sc->nr_reclaimed >= sc->nr_to_reclaim)
break;
if (sc->compaction_ready)
break;
if (sc->priority < DEF_PRIORITY - 2)
sc->may_writepage = 1;
} while (--sc->priority >= 0);
last_pgdat = NULL;
for_each_zone_zonelist_nodemask(zone, z, zonelist, sc->reclaim_idx,
sc->nodemask) {
if (zone->zone_pgdat == last_pgdat)
continue;
last_pgdat = zone->zone_pgdat;
snapshot_refaults(sc->target_mem_cgroup, zone->zone_pgdat);
}
delayacct_freepages_end();
if (sc->nr_reclaimed)
return sc->nr_reclaimed;
if (sc->compaction_ready)
return 1;
if (sc->memcg_low_skipped) {
sc->priority = initial_priority;
sc->memcg_low_reclaim = 1;
sc->memcg_low_skipped = 0;
goto retry;
}
return 0;
}
static bool allow_direct_reclaim(pg_data_t *pgdat)
{
struct zone *zone;
unsigned long pfmemalloc_reserve = 0;
unsigned long free_pages = 0;
int i;
bool wmark_ok;
if (pgdat->kswapd_failures >= MAX_RECLAIM_RETRIES)
return true;
for (i = 0; i <= ZONE_NORMAL; i++) {
zone = &pgdat->node_zones[i];
if (!managed_zone(zone))
continue;
if (!zone_reclaimable_pages(zone))
continue;
pfmemalloc_reserve += min_wmark_pages(zone);
free_pages += zone_page_state(zone, NR_FREE_PAGES);
}
if (!pfmemalloc_reserve)
return true;
wmark_ok = free_pages > pfmemalloc_reserve / 2;
if (!wmark_ok && waitqueue_active(&pgdat->kswapd_wait)) {
pgdat->kswapd_classzone_idx = min(pgdat->kswapd_classzone_idx,
(enum zone_type)ZONE_NORMAL);
wake_up_interruptible(&pgdat->kswapd_wait);
}
return wmark_ok;
}
static bool throttle_direct_reclaim(gfp_t gfp_mask, struct zonelist *zonelist,
nodemask_t *nodemask)
{
struct zoneref *z;
struct zone *zone;
pg_data_t *pgdat = NULL;
if (current->flags & PF_KTHREAD)
goto out;
if (fatal_signal_pending(current))
goto out;
for_each_zone_zonelist_nodemask(zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if (zone_idx(zone) > ZONE_NORMAL)
continue;
pgdat = zone->zone_pgdat;
if (allow_direct_reclaim(pgdat))
goto out;
break;
}
if (!pgdat)
goto out;
count_vm_event(PGSCAN_DIRECT_THROTTLE);
if (!(gfp_mask & __GFP_FS)) {
wait_event_interruptible_timeout(pgdat->pfmemalloc_wait,
allow_direct_reclaim(pgdat), HZ);
goto check_pending;
}
wait_event_killable(zone->zone_pgdat->pfmemalloc_wait,
allow_direct_reclaim(pgdat));
check_pending:
if (fatal_signal_pending(current))
return true;
out:
return false;
}
unsigned long try_to_free_pages(struct zonelist *zonelist, int order,
gfp_t gfp_mask, nodemask_t *nodemask)
{
unsigned long nr_reclaimed;
struct scan_control sc = {
.nr_to_reclaim = SWAP_CLUSTER_MAX,
.gfp_mask = current_gfp_context(gfp_mask),
.reclaim_idx = gfp_zone(gfp_mask),
.order = order,
.nodemask = nodemask,
.priority = DEF_PRIORITY,
.may_writepage = !laptop_mode,
.may_unmap = 1,
.may_swap = 1,
};
if (throttle_direct_reclaim(sc.gfp_mask, zonelist, nodemask))
return 1;
trace_mm_vmscan_direct_reclaim_begin(order,
sc.may_writepage,
sc.gfp_mask,
sc.reclaim_idx);
nr_reclaimed = do_try_to_free_pages(zonelist, &sc);
trace_mm_vmscan_direct_reclaim_end(nr_reclaimed);
return nr_reclaimed;
}
unsigned long mem_cgroup_shrink_node(struct mem_cgroup *memcg,
gfp_t gfp_mask, bool noswap,
pg_data_t *pgdat,
unsigned long *nr_scanned)
{
struct scan_control sc = {
.nr_to_reclaim = SWAP_CLUSTER_MAX,
.target_mem_cgroup = memcg,
.may_writepage = !laptop_mode,
.may_unmap = 1,
.reclaim_idx = MAX_NR_ZONES - 1,
.may_swap = !noswap,
};
unsigned long lru_pages;
sc.gfp_mask = (gfp_mask & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK);
trace_mm_vmscan_memcg_softlimit_reclaim_begin(sc.order,
sc.may_writepage,
sc.gfp_mask,
sc.reclaim_idx);
shrink_node_memcg(pgdat, memcg, &sc, &lru_pages);
trace_mm_vmscan_memcg_softlimit_reclaim_end(sc.nr_reclaimed);
*nr_scanned = sc.nr_scanned;
return sc.nr_reclaimed;
}
unsigned long try_to_free_mem_cgroup_pages(struct mem_cgroup *memcg,
unsigned long nr_pages,
gfp_t gfp_mask,
bool may_swap)
{
struct zonelist *zonelist;
unsigned long nr_reclaimed;
int nid;
unsigned int noreclaim_flag;
struct scan_control sc = {
.nr_to_reclaim = max(nr_pages, SWAP_CLUSTER_MAX),
.gfp_mask = (current_gfp_context(gfp_mask) & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK),
.reclaim_idx = MAX_NR_ZONES - 1,
.target_mem_cgroup = memcg,
.priority = DEF_PRIORITY,
.may_writepage = !laptop_mode,
.may_unmap = 1,
.may_swap = may_swap,
};
nid = mem_cgroup_select_victim_node(memcg);
zonelist = &NODE_DATA(nid)->node_zonelists[ZONELIST_FALLBACK];
trace_mm_vmscan_memcg_reclaim_begin(0,
sc.may_writepage,
sc.gfp_mask,
sc.reclaim_idx);
noreclaim_flag = memalloc_noreclaim_save();
nr_reclaimed = do_try_to_free_pages(zonelist, &sc);
memalloc_noreclaim_restore(noreclaim_flag);
trace_mm_vmscan_memcg_reclaim_end(nr_reclaimed);
return nr_reclaimed;
}
static void age_active_anon(struct pglist_data *pgdat,
struct scan_control *sc)
{
struct mem_cgroup *memcg;
if (!total_swap_pages)
return;
memcg = mem_cgroup_iter(NULL, NULL, NULL);
do {
struct lruvec *lruvec = mem_cgroup_lruvec(pgdat, memcg);
if (inactive_list_is_low(lruvec, false, memcg, sc, true))
shrink_active_list(SWAP_CLUSTER_MAX, lruvec,
sc, LRU_ACTIVE_ANON);
memcg = mem_cgroup_iter(NULL, memcg, NULL);
} while (memcg);
}
static bool pgdat_balanced(pg_data_t *pgdat, int order, int classzone_idx)
{
int i;
unsigned long mark = -1;
struct zone *zone;
for (i = 0; i <= classzone_idx; i++) {
zone = pgdat->node_zones + i;
if (!managed_zone(zone))
continue;
mark = high_wmark_pages(zone);
if (zone_watermark_ok_safe(zone, order, mark, classzone_idx))
return true;
}
if (mark == -1)
return true;
return false;
}
static void clear_pgdat_congested(pg_data_t *pgdat)
{
clear_bit(PGDAT_CONGESTED, &pgdat->flags);
clear_bit(PGDAT_DIRTY, &pgdat->flags);
clear_bit(PGDAT_WRITEBACK, &pgdat->flags);
}
static bool prepare_kswapd_sleep(pg_data_t *pgdat, int order, int classzone_idx)
{
if (waitqueue_active(&pgdat->pfmemalloc_wait))
wake_up_all(&pgdat->pfmemalloc_wait);
if (pgdat->kswapd_failures >= MAX_RECLAIM_RETRIES)
return true;
if (pgdat_balanced(pgdat, order, classzone_idx)) {
clear_pgdat_congested(pgdat);
return true;
}
return false;
}
static bool kswapd_shrink_node(pg_data_t *pgdat,
struct scan_control *sc)
{
struct zone *zone;
int z;
sc->nr_to_reclaim = 0;
for (z = 0; z <= sc->reclaim_idx; z++) {
zone = pgdat->node_zones + z;
if (!managed_zone(zone))
continue;
sc->nr_to_reclaim += max(high_wmark_pages(zone), SWAP_CLUSTER_MAX);
}
shrink_node(pgdat, sc);
if (sc->order && sc->nr_reclaimed >= compact_gap(sc->order))
sc->order = 0;
return sc->nr_scanned >= sc->nr_to_reclaim;
}
static int balance_pgdat(pg_data_t *pgdat, int order, int classzone_idx)
{
int i;
unsigned long nr_soft_reclaimed;
unsigned long nr_soft_scanned;
struct zone *zone;
struct scan_control sc = {
.gfp_mask = GFP_KERNEL,
.order = order,
.priority = DEF_PRIORITY,
.may_writepage = !laptop_mode,
.may_unmap = 1,
.may_swap = 1,
};
count_vm_event(PAGEOUTRUN);
do {
unsigned long nr_reclaimed = sc.nr_reclaimed;
bool raise_priority = true;
sc.reclaim_idx = classzone_idx;
if (buffer_heads_over_limit) {
for (i = MAX_NR_ZONES - 1; i >= 0; i--) {
zone = pgdat->node_zones + i;
if (!managed_zone(zone))
continue;
sc.reclaim_idx = i;
break;
}
}
if (pgdat_balanced(pgdat, sc.order, classzone_idx))
goto out;
age_active_anon(pgdat, &sc);
if (sc.priority < DEF_PRIORITY - 2)
sc.may_writepage = 1;
sc.nr_scanned = 0;
nr_soft_scanned = 0;
nr_soft_reclaimed = mem_cgroup_soft_limit_reclaim(pgdat, sc.order,
sc.gfp_mask, &nr_soft_scanned);
sc.nr_reclaimed += nr_soft_reclaimed;
if (kswapd_shrink_node(pgdat, &sc))
raise_priority = false;
if (waitqueue_active(&pgdat->pfmemalloc_wait) &&
allow_direct_reclaim(pgdat))
wake_up_all(&pgdat->pfmemalloc_wait);
if (try_to_freeze() || kthread_should_stop())
break;
nr_reclaimed = sc.nr_reclaimed - nr_reclaimed;
if (raise_priority || !nr_reclaimed)
sc.priority--;
} while (sc.priority >= 1);
if (!sc.nr_reclaimed)
pgdat->kswapd_failures++;
out:
snapshot_refaults(NULL, pgdat);
return sc.order;
}
static enum zone_type kswapd_classzone_idx(pg_data_t *pgdat,
enum zone_type classzone_idx)
{
if (pgdat->kswapd_classzone_idx == MAX_NR_ZONES)
return classzone_idx;
return max(pgdat->kswapd_classzone_idx, classzone_idx);
}
static void kswapd_try_to_sleep(pg_data_t *pgdat, int alloc_order, int reclaim_order,
unsigned int classzone_idx)
{
long remaining = 0;
DEFINE_WAIT(wait);
if (freezing(current) || kthread_should_stop())
return;
prepare_to_wait(&pgdat->kswapd_wait, &wait, TASK_INTERRUPTIBLE);
if (prepare_kswapd_sleep(pgdat, reclaim_order, classzone_idx)) {
reset_isolation_suitable(pgdat);
wakeup_kcompactd(pgdat, alloc_order, classzone_idx);
remaining = schedule_timeout(HZ/10);
if (remaining) {
pgdat->kswapd_classzone_idx = kswapd_classzone_idx(pgdat, classzone_idx);
pgdat->kswapd_order = max(pgdat->kswapd_order, reclaim_order);
}
finish_wait(&pgdat->kswapd_wait, &wait);
prepare_to_wait(&pgdat->kswapd_wait, &wait, TASK_INTERRUPTIBLE);
}
if (!remaining &&
prepare_kswapd_sleep(pgdat, reclaim_order, classzone_idx)) {
trace_mm_vmscan_kswapd_sleep(pgdat->node_id);
set_pgdat_percpu_threshold(pgdat, calculate_normal_threshold);
if (!kthread_should_stop())
schedule();
set_pgdat_percpu_threshold(pgdat, calculate_pressure_threshold);
} else {
if (remaining)
count_vm_event(KSWAPD_LOW_WMARK_HIT_QUICKLY);
else
count_vm_event(KSWAPD_HIGH_WMARK_HIT_QUICKLY);
}
finish_wait(&pgdat->kswapd_wait, &wait);
}
static int kswapd(void *p)
{
unsigned int alloc_order, reclaim_order;
unsigned int classzone_idx = MAX_NR_ZONES - 1;
pg_data_t *pgdat = (pg_data_t*)p;
struct task_struct *tsk = current;
struct reclaim_state reclaim_state = {
.reclaimed_slab = 0,
};
const struct cpumask *cpumask = cpumask_of_node(pgdat->node_id);
lockdep_set_current_reclaim_state(GFP_KERNEL);
if (!cpumask_empty(cpumask))
set_cpus_allowed_ptr(tsk, cpumask);
current->reclaim_state = &reclaim_state;
tsk->flags |= PF_MEMALLOC | PF_SWAPWRITE | PF_KSWAPD;
set_freezable();
pgdat->kswapd_order = 0;
pgdat->kswapd_classzone_idx = MAX_NR_ZONES;
for ( ; ; ) {
bool ret;
alloc_order = reclaim_order = pgdat->kswapd_order;
classzone_idx = kswapd_classzone_idx(pgdat, classzone_idx);
kswapd_try_sleep:
kswapd_try_to_sleep(pgdat, alloc_order, reclaim_order,
classzone_idx);
alloc_order = reclaim_order = pgdat->kswapd_order;
classzone_idx = kswapd_classzone_idx(pgdat, 0);
pgdat->kswapd_order = 0;
pgdat->kswapd_classzone_idx = MAX_NR_ZONES;
ret = try_to_freeze();
if (kthread_should_stop())
break;
if (ret)
continue;
trace_mm_vmscan_kswapd_wake(pgdat->node_id, classzone_idx,
alloc_order);
reclaim_order = balance_pgdat(pgdat, alloc_order, classzone_idx);
if (reclaim_order < alloc_order)
goto kswapd_try_sleep;
}
tsk->flags &= ~(PF_MEMALLOC | PF_SWAPWRITE | PF_KSWAPD);
current->reclaim_state = NULL;
lockdep_clear_current_reclaim_state();
return 0;
}
void wakeup_kswapd(struct zone *zone, int order, enum zone_type classzone_idx)
{
pg_data_t *pgdat;
if (!managed_zone(zone))
return;
if (!cpuset_zone_allowed(zone, GFP_KERNEL | __GFP_HARDWALL))
return;
pgdat = zone->zone_pgdat;
pgdat->kswapd_classzone_idx = kswapd_classzone_idx(pgdat,
classzone_idx);
pgdat->kswapd_order = max(pgdat->kswapd_order, order);
if (!waitqueue_active(&pgdat->kswapd_wait))
return;
if (pgdat->kswapd_failures >= MAX_RECLAIM_RETRIES)
return;
if (pgdat_balanced(pgdat, order, classzone_idx))
return;
trace_mm_vmscan_wakeup_kswapd(pgdat->node_id, classzone_idx, order);
wake_up_interruptible(&pgdat->kswapd_wait);
}
unsigned long shrink_all_memory(unsigned long nr_to_reclaim)
{
struct reclaim_state reclaim_state;
struct scan_control sc = {
.nr_to_reclaim = nr_to_reclaim,
.gfp_mask = GFP_HIGHUSER_MOVABLE,
.reclaim_idx = MAX_NR_ZONES - 1,
.priority = DEF_PRIORITY,
.may_writepage = 1,
.may_unmap = 1,
.may_swap = 1,
.hibernation_mode = 1,
};
struct zonelist *zonelist = node_zonelist(numa_node_id(), sc.gfp_mask);
struct task_struct *p = current;
unsigned long nr_reclaimed;
unsigned int noreclaim_flag;
noreclaim_flag = memalloc_noreclaim_save();
lockdep_set_current_reclaim_state(sc.gfp_mask);
reclaim_state.reclaimed_slab = 0;
p->reclaim_state = &reclaim_state;
nr_reclaimed = do_try_to_free_pages(zonelist, &sc);
p->reclaim_state = NULL;
lockdep_clear_current_reclaim_state();
memalloc_noreclaim_restore(noreclaim_flag);
return nr_reclaimed;
}
static int kswapd_cpu_online(unsigned int cpu)
{
int nid;
for_each_node_state(nid, N_MEMORY) {
pg_data_t *pgdat = NODE_DATA(nid);
const struct cpumask *mask;
mask = cpumask_of_node(pgdat->node_id);
if (cpumask_any_and(cpu_online_mask, mask) < nr_cpu_ids)
set_cpus_allowed_ptr(pgdat->kswapd, mask);
}
return 0;
}
int kswapd_run(int nid)
{
pg_data_t *pgdat = NODE_DATA(nid);
int ret = 0;
if (pgdat->kswapd)
return 0;
pgdat->kswapd = kthread_run(kswapd, pgdat, "kswapd%d", nid);
if (IS_ERR(pgdat->kswapd)) {
BUG_ON(system_state < SYSTEM_RUNNING);
pr_err("Failed to start kswapd on node %d\n", nid);
ret = PTR_ERR(pgdat->kswapd);
pgdat->kswapd = NULL;
}
return ret;
}
void kswapd_stop(int nid)
{
struct task_struct *kswapd = NODE_DATA(nid)->kswapd;
if (kswapd) {
kthread_stop(kswapd);
NODE_DATA(nid)->kswapd = NULL;
}
}
static int __init kswapd_init(void)
{
int nid, ret;
swap_setup();
for_each_node_state(nid, N_MEMORY)
kswapd_run(nid);
ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN,
"mm/vmscan:online", kswapd_cpu_online,
NULL);
WARN_ON(ret < 0);
return 0;
}
static inline unsigned long node_unmapped_file_pages(struct pglist_data *pgdat)
{
unsigned long file_mapped = node_page_state(pgdat, NR_FILE_MAPPED);
unsigned long file_lru = node_page_state(pgdat, NR_INACTIVE_FILE) +
node_page_state(pgdat, NR_ACTIVE_FILE);
return (file_lru > file_mapped) ? (file_lru - file_mapped) : 0;
}
static unsigned long node_pagecache_reclaimable(struct pglist_data *pgdat)
{
unsigned long nr_pagecache_reclaimable;
unsigned long delta = 0;
if (node_reclaim_mode & RECLAIM_UNMAP)
nr_pagecache_reclaimable = node_page_state(pgdat, NR_FILE_PAGES);
else
nr_pagecache_reclaimable = node_unmapped_file_pages(pgdat);
if (!(node_reclaim_mode & RECLAIM_WRITE))
delta += node_page_state(pgdat, NR_FILE_DIRTY);
if (unlikely(delta > nr_pagecache_reclaimable))
delta = nr_pagecache_reclaimable;
return nr_pagecache_reclaimable - delta;
}
static int __node_reclaim(struct pglist_data *pgdat, gfp_t gfp_mask, unsigned int order)
{
const unsigned long nr_pages = 1 << order;
struct task_struct *p = current;
struct reclaim_state reclaim_state;
unsigned int noreclaim_flag;
struct scan_control sc = {
.nr_to_reclaim = max(nr_pages, SWAP_CLUSTER_MAX),
.gfp_mask = current_gfp_context(gfp_mask),
.order = order,
.priority = NODE_RECLAIM_PRIORITY,
.may_writepage = !!(node_reclaim_mode & RECLAIM_WRITE),
.may_unmap = !!(node_reclaim_mode & RECLAIM_UNMAP),
.may_swap = 1,
.reclaim_idx = gfp_zone(gfp_mask),
};
cond_resched();
noreclaim_flag = memalloc_noreclaim_save();
p->flags |= PF_SWAPWRITE;
lockdep_set_current_reclaim_state(sc.gfp_mask);
reclaim_state.reclaimed_slab = 0;
p->reclaim_state = &reclaim_state;
if (node_pagecache_reclaimable(pgdat) > pgdat->min_unmapped_pages) {
do {
shrink_node(pgdat, &sc);
} while (sc.nr_reclaimed < nr_pages && --sc.priority >= 0);
}
p->reclaim_state = NULL;
current->flags &= ~PF_SWAPWRITE;
memalloc_noreclaim_restore(noreclaim_flag);
lockdep_clear_current_reclaim_state();
return sc.nr_reclaimed >= nr_pages;
}
int node_reclaim(struct pglist_data *pgdat, gfp_t gfp_mask, unsigned int order)
{
int ret;
if (node_pagecache_reclaimable(pgdat) <= pgdat->min_unmapped_pages &&
node_page_state(pgdat, NR_SLAB_RECLAIMABLE) <= pgdat->min_slab_pages)
return NODE_RECLAIM_FULL;
if (!gfpflags_allow_blocking(gfp_mask) || (current->flags & PF_MEMALLOC))
return NODE_RECLAIM_NOSCAN;
if (node_state(pgdat->node_id, N_CPU) && pgdat->node_id != numa_node_id())
return NODE_RECLAIM_NOSCAN;
if (test_and_set_bit(PGDAT_RECLAIM_LOCKED, &pgdat->flags))
return NODE_RECLAIM_NOSCAN;
ret = __node_reclaim(pgdat, gfp_mask, order);
clear_bit(PGDAT_RECLAIM_LOCKED, &pgdat->flags);
if (!ret)
count_vm_event(PGSCAN_ZONE_RECLAIM_FAILED);
return ret;
}
int page_evictable(struct page *page)
{
return !mapping_unevictable(page_mapping(page)) && !PageMlocked(page);
}
void check_move_unevictable_pages(struct page **pages, int nr_pages)
{
struct lruvec *lruvec;
struct pglist_data *pgdat = NULL;
int pgscanned = 0;
int pgrescued = 0;
int i;
for (i = 0; i < nr_pages; i++) {
struct page *page = pages[i];
struct pglist_data *pagepgdat = page_pgdat(page);
pgscanned++;
if (pagepgdat != pgdat) {
if (pgdat)
spin_unlock_irq(&pgdat->lru_lock);
pgdat = pagepgdat;
spin_lock_irq(&pgdat->lru_lock);
}
lruvec = mem_cgroup_page_lruvec(page, pgdat);
if (!PageLRU(page) || !PageUnevictable(page))
continue;
if (page_evictable(page)) {
enum lru_list lru = page_lru_base_type(page);
VM_BUG_ON_PAGE(PageActive(page), page);
ClearPageUnevictable(page);
del_page_from_lru_list(page, lruvec, LRU_UNEVICTABLE);
add_page_to_lru_list(page, lruvec, lru);
pgrescued++;
}
}
if (pgdat) {
__count_vm_events(UNEVICTABLE_PGRESCUED, pgrescued);
__count_vm_events(UNEVICTABLE_PGSCANNED, pgscanned);
spin_unlock_irq(&pgdat->lru_lock);
}
}
