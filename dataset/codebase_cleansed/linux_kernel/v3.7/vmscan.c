static bool global_reclaim(struct scan_control *sc)
{
return !sc->target_mem_cgroup;
}
static bool global_reclaim(struct scan_control *sc)
{
return true;
}
static unsigned long get_lru_size(struct lruvec *lruvec, enum lru_list lru)
{
if (!mem_cgroup_disabled())
return mem_cgroup_get_lru_size(lruvec, lru);
return zone_page_state(lruvec_zone(lruvec), NR_LRU_BASE + lru);
}
void register_shrinker(struct shrinker *shrinker)
{
atomic_long_set(&shrinker->nr_in_batch, 0);
down_write(&shrinker_rwsem);
list_add_tail(&shrinker->list, &shrinker_list);
up_write(&shrinker_rwsem);
}
void unregister_shrinker(struct shrinker *shrinker)
{
down_write(&shrinker_rwsem);
list_del(&shrinker->list);
up_write(&shrinker_rwsem);
}
static inline int do_shrinker_shrink(struct shrinker *shrinker,
struct shrink_control *sc,
unsigned long nr_to_scan)
{
sc->nr_to_scan = nr_to_scan;
return (*shrinker->shrink)(shrinker, sc);
}
unsigned long shrink_slab(struct shrink_control *shrink,
unsigned long nr_pages_scanned,
unsigned long lru_pages)
{
struct shrinker *shrinker;
unsigned long ret = 0;
if (nr_pages_scanned == 0)
nr_pages_scanned = SWAP_CLUSTER_MAX;
if (!down_read_trylock(&shrinker_rwsem)) {
ret = 1;
goto out;
}
list_for_each_entry(shrinker, &shrinker_list, list) {
unsigned long long delta;
long total_scan;
long max_pass;
int shrink_ret = 0;
long nr;
long new_nr;
long batch_size = shrinker->batch ? shrinker->batch
: SHRINK_BATCH;
max_pass = do_shrinker_shrink(shrinker, shrink, 0);
if (max_pass <= 0)
continue;
nr = atomic_long_xchg(&shrinker->nr_in_batch, 0);
total_scan = nr;
delta = (4 * nr_pages_scanned) / shrinker->seeks;
delta *= max_pass;
do_div(delta, lru_pages + 1);
total_scan += delta;
if (total_scan < 0) {
printk(KERN_ERR "shrink_slab: %pF negative objects to "
"delete nr=%ld\n",
shrinker->shrink, total_scan);
total_scan = max_pass;
}
if (delta < max_pass / 4)
total_scan = min(total_scan, max_pass / 2);
if (total_scan > max_pass * 2)
total_scan = max_pass * 2;
trace_mm_shrink_slab_start(shrinker, shrink, nr,
nr_pages_scanned, lru_pages,
max_pass, delta, total_scan);
while (total_scan >= batch_size) {
int nr_before;
nr_before = do_shrinker_shrink(shrinker, shrink, 0);
shrink_ret = do_shrinker_shrink(shrinker, shrink,
batch_size);
if (shrink_ret == -1)
break;
if (shrink_ret < nr_before)
ret += nr_before - shrink_ret;
count_vm_events(SLABS_SCANNED, batch_size);
total_scan -= batch_size;
cond_resched();
}
if (total_scan > 0)
new_nr = atomic_long_add_return(total_scan,
&shrinker->nr_in_batch);
else
new_nr = atomic_long_read(&shrinker->nr_in_batch);
trace_mm_shrink_slab_end(shrinker, shrink_ret, nr, new_nr);
}
up_read(&shrinker_rwsem);
out:
cond_resched();
return ret;
}
static inline int is_page_cache_freeable(struct page *page)
{
return page_count(page) - page_has_private(page) == 2;
}
static int may_write_to_queue(struct backing_dev_info *bdi,
struct scan_control *sc)
{
if (current->flags & PF_SWAPWRITE)
return 1;
if (!bdi_write_congested(bdi))
return 1;
if (bdi == current->backing_dev_info)
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
printk("%s: orphaned page\n", __func__);
return PAGE_CLEAN;
}
}
return PAGE_KEEP;
}
if (mapping->a_ops->writepage == NULL)
return PAGE_ACTIVATE;
if (!may_write_to_queue(mapping->backing_dev_info, sc))
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
trace_mm_vmscan_writepage(page, trace_reclaim_flags(page));
inc_zone_page_state(page, NR_VMSCAN_WRITE);
return PAGE_SUCCESS;
}
return PAGE_CLEAN;
}
static int __remove_mapping(struct address_space *mapping, struct page *page)
{
BUG_ON(!PageLocked(page));
BUG_ON(mapping != page_mapping(page));
spin_lock_irq(&mapping->tree_lock);
if (!page_freeze_refs(page, 2))
goto cannot_free;
if (unlikely(PageDirty(page))) {
page_unfreeze_refs(page, 2);
goto cannot_free;
}
if (PageSwapCache(page)) {
swp_entry_t swap = { .val = page_private(page) };
__delete_from_swap_cache(page);
spin_unlock_irq(&mapping->tree_lock);
swapcache_free(swap, page);
} else {
void (*freepage)(struct page *);
freepage = mapping->a_ops->freepage;
__delete_from_page_cache(page);
spin_unlock_irq(&mapping->tree_lock);
mem_cgroup_uncharge_cache_page(page);
if (freepage != NULL)
freepage(page);
}
return 1;
cannot_free:
spin_unlock_irq(&mapping->tree_lock);
return 0;
}
int remove_mapping(struct address_space *mapping, struct page *page)
{
if (__remove_mapping(mapping, page)) {
page_unfreeze_refs(page, 1);
return 1;
}
return 0;
}
void putback_lru_page(struct page *page)
{
int lru;
int active = !!TestClearPageActive(page);
int was_unevictable = PageUnevictable(page);
VM_BUG_ON(PageLRU(page));
redo:
ClearPageUnevictable(page);
if (page_evictable(page)) {
lru = active + page_lru_base_type(page);
lru_cache_add_lru(page, lru);
} else {
lru = LRU_UNEVICTABLE;
add_page_to_unevictable_list(page);
smp_mb();
}
if (lru == LRU_UNEVICTABLE && page_evictable(page)) {
if (!isolate_lru_page(page)) {
put_page(page);
goto redo;
}
}
if (was_unevictable && lru != LRU_UNEVICTABLE)
count_vm_event(UNEVICTABLE_PGRESCUED);
else if (!was_unevictable && lru == LRU_UNEVICTABLE)
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
static unsigned long shrink_page_list(struct list_head *page_list,
struct zone *zone,
struct scan_control *sc,
enum ttu_flags ttu_flags,
unsigned long *ret_nr_dirty,
unsigned long *ret_nr_writeback,
bool force_reclaim)
{
LIST_HEAD(ret_pages);
LIST_HEAD(free_pages);
int pgactivate = 0;
unsigned long nr_dirty = 0;
unsigned long nr_congested = 0;
unsigned long nr_reclaimed = 0;
unsigned long nr_writeback = 0;
cond_resched();
mem_cgroup_uncharge_start();
while (!list_empty(page_list)) {
struct address_space *mapping;
struct page *page;
int may_enter_fs;
enum page_references references = PAGEREF_RECLAIM_CLEAN;
cond_resched();
page = lru_to_page(page_list);
list_del(&page->lru);
if (!trylock_page(page))
goto keep;
VM_BUG_ON(PageActive(page));
VM_BUG_ON(page_zone(page) != zone);
sc->nr_scanned++;
if (unlikely(!page_evictable(page)))
goto cull_mlocked;
if (!sc->may_unmap && page_mapped(page))
goto keep_locked;
if (page_mapped(page) || PageSwapCache(page))
sc->nr_scanned++;
may_enter_fs = (sc->gfp_mask & __GFP_FS) ||
(PageSwapCache(page) && (sc->gfp_mask & __GFP_IO));
if (PageWriteback(page)) {
if (global_reclaim(sc) ||
!PageReclaim(page) || !(sc->gfp_mask & __GFP_IO)) {
SetPageReclaim(page);
nr_writeback++;
goto keep_locked;
}
wait_on_page_writeback(page);
}
if (!force_reclaim)
references = page_check_references(page, sc);
switch (references) {
case PAGEREF_ACTIVATE:
goto activate_locked;
case PAGEREF_KEEP:
goto keep_locked;
case PAGEREF_RECLAIM:
case PAGEREF_RECLAIM_CLEAN:
;
}
if (PageAnon(page) && !PageSwapCache(page)) {
if (!(sc->gfp_mask & __GFP_IO))
goto keep_locked;
if (!add_to_swap(page))
goto activate_locked;
may_enter_fs = 1;
}
mapping = page_mapping(page);
if (page_mapped(page) && mapping) {
switch (try_to_unmap(page, ttu_flags)) {
case SWAP_FAIL:
goto activate_locked;
case SWAP_AGAIN:
goto keep_locked;
case SWAP_MLOCK:
goto cull_mlocked;
case SWAP_SUCCESS:
;
}
}
if (PageDirty(page)) {
nr_dirty++;
if (page_is_file_cache(page) &&
(!current_is_kswapd() ||
sc->priority >= DEF_PRIORITY - 2)) {
inc_zone_page_state(page, NR_VMSCAN_IMMEDIATE);
SetPageReclaim(page);
goto keep_locked;
}
if (references == PAGEREF_RECLAIM_CLEAN)
goto keep_locked;
if (!may_enter_fs)
goto keep_locked;
if (!sc->may_writepage)
goto keep_locked;
switch (pageout(page, mapping, sc)) {
case PAGE_KEEP:
nr_congested++;
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
if (!mapping || !__remove_mapping(mapping, page))
goto keep_locked;
__clear_page_locked(page);
free_it:
nr_reclaimed++;
list_add(&page->lru, &free_pages);
continue;
cull_mlocked:
if (PageSwapCache(page))
try_to_free_swap(page);
unlock_page(page);
putback_lru_page(page);
continue;
activate_locked:
if (PageSwapCache(page) && vm_swap_full())
try_to_free_swap(page);
VM_BUG_ON(PageActive(page));
SetPageActive(page);
pgactivate++;
keep_locked:
unlock_page(page);
keep:
list_add(&page->lru, &ret_pages);
VM_BUG_ON(PageLRU(page) || PageUnevictable(page));
}
if (nr_dirty && nr_dirty == nr_congested && global_reclaim(sc))
zone_set_flag(zone, ZONE_CONGESTED);
free_hot_cold_page_list(&free_pages, 1);
list_splice(&ret_pages, page_list);
count_vm_events(PGACTIVATE, pgactivate);
mem_cgroup_uncharge_end();
*ret_nr_dirty += nr_dirty;
*ret_nr_writeback += nr_writeback;
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
unsigned long ret, dummy1, dummy2;
struct page *page, *next;
LIST_HEAD(clean_pages);
list_for_each_entry_safe(page, next, page_list, lru) {
if (page_is_file_cache(page) && !PageDirty(page)) {
ClearPageActive(page);
list_move(&page->lru, &clean_pages);
}
}
ret = shrink_page_list(&clean_pages, zone, &sc,
TTU_UNMAP|TTU_IGNORE_ACCESS,
&dummy1, &dummy2, true);
list_splice(&clean_pages, page_list);
__mod_zone_page_state(zone, NR_ISOLATED_FILE, -ret);
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
if (mode & (ISOLATE_CLEAN|ISOLATE_ASYNC_MIGRATE)) {
if (PageWriteback(page))
return ret;
if (PageDirty(page)) {
struct address_space *mapping;
if (mode & ISOLATE_CLEAN)
return ret;
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
static unsigned long isolate_lru_pages(unsigned long nr_to_scan,
struct lruvec *lruvec, struct list_head *dst,
unsigned long *nr_scanned, struct scan_control *sc,
isolate_mode_t mode, enum lru_list lru)
{
struct list_head *src = &lruvec->lists[lru];
unsigned long nr_taken = 0;
unsigned long scan;
for (scan = 0; scan < nr_to_scan && !list_empty(src); scan++) {
struct page *page;
int nr_pages;
page = lru_to_page(src);
prefetchw_prev_lru_page(page, src, flags);
VM_BUG_ON(!PageLRU(page));
switch (__isolate_lru_page(page, mode)) {
case 0:
nr_pages = hpage_nr_pages(page);
mem_cgroup_update_lru_size(lruvec, lru, -nr_pages);
list_move(&page->lru, dst);
nr_taken += nr_pages;
break;
case -EBUSY:
list_move(&page->lru, src);
continue;
default:
BUG();
}
}
*nr_scanned = scan;
trace_mm_vmscan_lru_isolate(sc->order, nr_to_scan, scan,
nr_taken, mode, is_file_lru(lru));
return nr_taken;
}
int isolate_lru_page(struct page *page)
{
int ret = -EBUSY;
VM_BUG_ON(!page_count(page));
if (PageLRU(page)) {
struct zone *zone = page_zone(page);
struct lruvec *lruvec;
spin_lock_irq(&zone->lru_lock);
lruvec = mem_cgroup_page_lruvec(page, zone);
if (PageLRU(page)) {
int lru = page_lru(page);
get_page(page);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, lru);
ret = 0;
}
spin_unlock_irq(&zone->lru_lock);
}
return ret;
}
static int too_many_isolated(struct zone *zone, int file,
struct scan_control *sc)
{
unsigned long inactive, isolated;
if (current_is_kswapd())
return 0;
if (!global_reclaim(sc))
return 0;
if (file) {
inactive = zone_page_state(zone, NR_INACTIVE_FILE);
isolated = zone_page_state(zone, NR_ISOLATED_FILE);
} else {
inactive = zone_page_state(zone, NR_INACTIVE_ANON);
isolated = zone_page_state(zone, NR_ISOLATED_ANON);
}
return isolated > inactive;
}
static noinline_for_stack void
putback_inactive_pages(struct lruvec *lruvec, struct list_head *page_list)
{
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
struct zone *zone = lruvec_zone(lruvec);
LIST_HEAD(pages_to_free);
while (!list_empty(page_list)) {
struct page *page = lru_to_page(page_list);
int lru;
VM_BUG_ON(PageLRU(page));
list_del(&page->lru);
if (unlikely(!page_evictable(page))) {
spin_unlock_irq(&zone->lru_lock);
putback_lru_page(page);
spin_lock_irq(&zone->lru_lock);
continue;
}
lruvec = mem_cgroup_page_lruvec(page, zone);
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
spin_unlock_irq(&zone->lru_lock);
(*get_compound_page_dtor(page))(page);
spin_lock_irq(&zone->lru_lock);
} else
list_add(&page->lru, &pages_to_free);
}
}
list_splice(&pages_to_free, page_list);
}
static noinline_for_stack unsigned long
shrink_inactive_list(unsigned long nr_to_scan, struct lruvec *lruvec,
struct scan_control *sc, enum lru_list lru)
{
LIST_HEAD(page_list);
unsigned long nr_scanned;
unsigned long nr_reclaimed = 0;
unsigned long nr_taken;
unsigned long nr_dirty = 0;
unsigned long nr_writeback = 0;
isolate_mode_t isolate_mode = 0;
int file = is_file_lru(lru);
struct zone *zone = lruvec_zone(lruvec);
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
while (unlikely(too_many_isolated(zone, file, sc))) {
congestion_wait(BLK_RW_ASYNC, HZ/10);
if (fatal_signal_pending(current))
return SWAP_CLUSTER_MAX;
}
lru_add_drain();
if (!sc->may_unmap)
isolate_mode |= ISOLATE_UNMAPPED;
if (!sc->may_writepage)
isolate_mode |= ISOLATE_CLEAN;
spin_lock_irq(&zone->lru_lock);
nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &page_list,
&nr_scanned, sc, isolate_mode, lru);
__mod_zone_page_state(zone, NR_LRU_BASE + lru, -nr_taken);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, nr_taken);
if (global_reclaim(sc)) {
zone->pages_scanned += nr_scanned;
if (current_is_kswapd())
__count_zone_vm_events(PGSCAN_KSWAPD, zone, nr_scanned);
else
__count_zone_vm_events(PGSCAN_DIRECT, zone, nr_scanned);
}
spin_unlock_irq(&zone->lru_lock);
if (nr_taken == 0)
return 0;
nr_reclaimed = shrink_page_list(&page_list, zone, sc, TTU_UNMAP,
&nr_dirty, &nr_writeback, false);
spin_lock_irq(&zone->lru_lock);
reclaim_stat->recent_scanned[file] += nr_taken;
if (global_reclaim(sc)) {
if (current_is_kswapd())
__count_zone_vm_events(PGSTEAL_KSWAPD, zone,
nr_reclaimed);
else
__count_zone_vm_events(PGSTEAL_DIRECT, zone,
nr_reclaimed);
}
putback_inactive_pages(lruvec, &page_list);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, -nr_taken);
spin_unlock_irq(&zone->lru_lock);
free_hot_cold_page_list(&page_list, 1);
if (nr_writeback && nr_writeback >=
(nr_taken >> (DEF_PRIORITY - sc->priority)))
wait_iff_congested(zone, BLK_RW_ASYNC, HZ/10);
trace_mm_vmscan_lru_shrink_inactive(zone->zone_pgdat->node_id,
zone_idx(zone),
nr_scanned, nr_reclaimed,
sc->priority,
trace_shrink_flags(file));
return nr_reclaimed;
}
static void move_active_pages_to_lru(struct lruvec *lruvec,
struct list_head *list,
struct list_head *pages_to_free,
enum lru_list lru)
{
struct zone *zone = lruvec_zone(lruvec);
unsigned long pgmoved = 0;
struct page *page;
int nr_pages;
while (!list_empty(list)) {
page = lru_to_page(list);
lruvec = mem_cgroup_page_lruvec(page, zone);
VM_BUG_ON(PageLRU(page));
SetPageLRU(page);
nr_pages = hpage_nr_pages(page);
mem_cgroup_update_lru_size(lruvec, lru, nr_pages);
list_move(&page->lru, &lruvec->lists[lru]);
pgmoved += nr_pages;
if (put_page_testzero(page)) {
__ClearPageLRU(page);
__ClearPageActive(page);
del_page_from_lru_list(page, lruvec, lru);
if (unlikely(PageCompound(page))) {
spin_unlock_irq(&zone->lru_lock);
(*get_compound_page_dtor(page))(page);
spin_lock_irq(&zone->lru_lock);
} else
list_add(&page->lru, pages_to_free);
}
}
__mod_zone_page_state(zone, NR_LRU_BASE + lru, pgmoved);
if (!is_active_lru(lru))
__count_vm_events(PGDEACTIVATE, pgmoved);
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
unsigned long nr_rotated = 0;
isolate_mode_t isolate_mode = 0;
int file = is_file_lru(lru);
struct zone *zone = lruvec_zone(lruvec);
lru_add_drain();
if (!sc->may_unmap)
isolate_mode |= ISOLATE_UNMAPPED;
if (!sc->may_writepage)
isolate_mode |= ISOLATE_CLEAN;
spin_lock_irq(&zone->lru_lock);
nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &l_hold,
&nr_scanned, sc, isolate_mode, lru);
if (global_reclaim(sc))
zone->pages_scanned += nr_scanned;
reclaim_stat->recent_scanned[file] += nr_taken;
__count_zone_vm_events(PGREFILL, zone, nr_scanned);
__mod_zone_page_state(zone, NR_LRU_BASE + lru, -nr_taken);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, nr_taken);
spin_unlock_irq(&zone->lru_lock);
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
spin_lock_irq(&zone->lru_lock);
reclaim_stat->recent_rotated[file] += nr_rotated;
move_active_pages_to_lru(lruvec, &l_active, &l_hold, lru);
move_active_pages_to_lru(lruvec, &l_inactive, &l_hold, lru - LRU_ACTIVE);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, -nr_taken);
spin_unlock_irq(&zone->lru_lock);
free_hot_cold_page_list(&l_hold, 1);
}
static int inactive_anon_is_low_global(struct zone *zone)
{
unsigned long active, inactive;
active = zone_page_state(zone, NR_ACTIVE_ANON);
inactive = zone_page_state(zone, NR_INACTIVE_ANON);
if (inactive * zone->inactive_ratio < active)
return 1;
return 0;
}
static int inactive_anon_is_low(struct lruvec *lruvec)
{
if (!total_swap_pages)
return 0;
if (!mem_cgroup_disabled())
return mem_cgroup_inactive_anon_is_low(lruvec);
return inactive_anon_is_low_global(lruvec_zone(lruvec));
}
static inline int inactive_anon_is_low(struct lruvec *lruvec)
{
return 0;
}
static int inactive_file_is_low_global(struct zone *zone)
{
unsigned long active, inactive;
active = zone_page_state(zone, NR_ACTIVE_FILE);
inactive = zone_page_state(zone, NR_INACTIVE_FILE);
return (active > inactive);
}
static int inactive_file_is_low(struct lruvec *lruvec)
{
if (!mem_cgroup_disabled())
return mem_cgroup_inactive_file_is_low(lruvec);
return inactive_file_is_low_global(lruvec_zone(lruvec));
}
static int inactive_list_is_low(struct lruvec *lruvec, enum lru_list lru)
{
if (is_file_lru(lru))
return inactive_file_is_low(lruvec);
else
return inactive_anon_is_low(lruvec);
}
static unsigned long shrink_list(enum lru_list lru, unsigned long nr_to_scan,
struct lruvec *lruvec, struct scan_control *sc)
{
if (is_active_lru(lru)) {
if (inactive_list_is_low(lruvec, lru))
shrink_active_list(nr_to_scan, lruvec, sc, lru);
return 0;
}
return shrink_inactive_list(nr_to_scan, lruvec, sc, lru);
}
static int vmscan_swappiness(struct scan_control *sc)
{
if (global_reclaim(sc))
return vm_swappiness;
return mem_cgroup_swappiness(sc->target_mem_cgroup);
}
static void get_scan_count(struct lruvec *lruvec, struct scan_control *sc,
unsigned long *nr)
{
unsigned long anon, file, free;
unsigned long anon_prio, file_prio;
unsigned long ap, fp;
struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
u64 fraction[2], denominator;
enum lru_list lru;
int noswap = 0;
bool force_scan = false;
struct zone *zone = lruvec_zone(lruvec);
if (current_is_kswapd() && zone->all_unreclaimable)
force_scan = true;
if (!global_reclaim(sc))
force_scan = true;
if (!sc->may_swap || (nr_swap_pages <= 0)) {
noswap = 1;
fraction[0] = 0;
fraction[1] = 1;
denominator = 1;
goto out;
}
anon = get_lru_size(lruvec, LRU_ACTIVE_ANON) +
get_lru_size(lruvec, LRU_INACTIVE_ANON);
file = get_lru_size(lruvec, LRU_ACTIVE_FILE) +
get_lru_size(lruvec, LRU_INACTIVE_FILE);
if (global_reclaim(sc)) {
free = zone_page_state(zone, NR_FREE_PAGES);
if (unlikely(file + free <= high_wmark_pages(zone))) {
fraction[0] = 1;
fraction[1] = 0;
denominator = 1;
goto out;
}
}
anon_prio = vmscan_swappiness(sc);
file_prio = 200 - anon_prio;
spin_lock_irq(&zone->lru_lock);
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
spin_unlock_irq(&zone->lru_lock);
fraction[0] = ap;
fraction[1] = fp;
denominator = ap + fp + 1;
out:
for_each_evictable_lru(lru) {
int file = is_file_lru(lru);
unsigned long scan;
scan = get_lru_size(lruvec, lru);
if (sc->priority || noswap || !vmscan_swappiness(sc)) {
scan >>= sc->priority;
if (!scan && force_scan)
scan = SWAP_CLUSTER_MAX;
scan = div64_u64(scan * fraction[file], denominator);
}
nr[lru] = scan;
}
}
static bool in_reclaim_compaction(struct scan_control *sc)
{
if (COMPACTION_BUILD && sc->order &&
(sc->order > PAGE_ALLOC_COSTLY_ORDER ||
sc->priority < DEF_PRIORITY - 2))
return true;
return false;
}
static inline bool should_continue_reclaim(struct lruvec *lruvec,
unsigned long nr_reclaimed,
unsigned long nr_scanned,
struct scan_control *sc)
{
unsigned long pages_for_compaction;
unsigned long inactive_lru_pages;
if (!in_reclaim_compaction(sc))
return false;
if (sc->gfp_mask & __GFP_REPEAT) {
if (!nr_reclaimed && !nr_scanned)
return false;
} else {
if (!nr_reclaimed)
return false;
}
pages_for_compaction = (2UL << sc->order);
inactive_lru_pages = get_lru_size(lruvec, LRU_INACTIVE_FILE);
if (nr_swap_pages > 0)
inactive_lru_pages += get_lru_size(lruvec, LRU_INACTIVE_ANON);
if (sc->nr_reclaimed < pages_for_compaction &&
inactive_lru_pages > pages_for_compaction)
return true;
switch (compaction_suitable(lruvec_zone(lruvec), sc->order)) {
case COMPACT_PARTIAL:
case COMPACT_CONTINUE:
return false;
default:
return true;
}
}
static void shrink_lruvec(struct lruvec *lruvec, struct scan_control *sc)
{
unsigned long nr[NR_LRU_LISTS];
unsigned long nr_to_scan;
enum lru_list lru;
unsigned long nr_reclaimed, nr_scanned;
unsigned long nr_to_reclaim = sc->nr_to_reclaim;
struct blk_plug plug;
restart:
nr_reclaimed = 0;
nr_scanned = sc->nr_scanned;
get_scan_count(lruvec, sc, nr);
blk_start_plug(&plug);
while (nr[LRU_INACTIVE_ANON] || nr[LRU_ACTIVE_FILE] ||
nr[LRU_INACTIVE_FILE]) {
for_each_evictable_lru(lru) {
if (nr[lru]) {
nr_to_scan = min_t(unsigned long,
nr[lru], SWAP_CLUSTER_MAX);
nr[lru] -= nr_to_scan;
nr_reclaimed += shrink_list(lru, nr_to_scan,
lruvec, sc);
}
}
if (nr_reclaimed >= nr_to_reclaim &&
sc->priority < DEF_PRIORITY)
break;
}
blk_finish_plug(&plug);
sc->nr_reclaimed += nr_reclaimed;
if (inactive_anon_is_low(lruvec))
shrink_active_list(SWAP_CLUSTER_MAX, lruvec,
sc, LRU_ACTIVE_ANON);
if (should_continue_reclaim(lruvec, nr_reclaimed,
sc->nr_scanned - nr_scanned, sc))
goto restart;
throttle_vm_writeout(sc->gfp_mask);
}
static void shrink_zone(struct zone *zone, struct scan_control *sc)
{
struct mem_cgroup *root = sc->target_mem_cgroup;
struct mem_cgroup_reclaim_cookie reclaim = {
.zone = zone,
.priority = sc->priority,
};
struct mem_cgroup *memcg;
memcg = mem_cgroup_iter(root, NULL, &reclaim);
do {
struct lruvec *lruvec = mem_cgroup_zone_lruvec(zone, memcg);
shrink_lruvec(lruvec, sc);
if (!global_reclaim(sc)) {
mem_cgroup_iter_break(root, memcg);
break;
}
memcg = mem_cgroup_iter(root, memcg, &reclaim);
} while (memcg);
}
static inline bool compaction_ready(struct zone *zone, struct scan_control *sc)
{
unsigned long balance_gap, watermark;
bool watermark_ok;
if (sc->order <= PAGE_ALLOC_COSTLY_ORDER)
return false;
balance_gap = min(low_wmark_pages(zone),
(zone->present_pages + KSWAPD_ZONE_BALANCE_GAP_RATIO-1) /
KSWAPD_ZONE_BALANCE_GAP_RATIO);
watermark = high_wmark_pages(zone) + balance_gap + (2UL << sc->order);
watermark_ok = zone_watermark_ok_safe(zone, 0, watermark, 0, 0);
if (compaction_deferred(zone, sc->order))
return watermark_ok;
if (!compaction_suitable(zone, sc->order))
return false;
return watermark_ok;
}
static bool shrink_zones(struct zonelist *zonelist, struct scan_control *sc)
{
struct zoneref *z;
struct zone *zone;
unsigned long nr_soft_reclaimed;
unsigned long nr_soft_scanned;
bool aborted_reclaim = false;
if (buffer_heads_over_limit)
sc->gfp_mask |= __GFP_HIGHMEM;
for_each_zone_zonelist_nodemask(zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if (!populated_zone(zone))
continue;
if (global_reclaim(sc)) {
if (!cpuset_zone_allowed_hardwall(zone, GFP_KERNEL))
continue;
if (zone->all_unreclaimable &&
sc->priority != DEF_PRIORITY)
continue;
if (COMPACTION_BUILD) {
if (compaction_ready(zone, sc)) {
aborted_reclaim = true;
continue;
}
}
nr_soft_scanned = 0;
nr_soft_reclaimed = mem_cgroup_soft_limit_reclaim(zone,
sc->order, sc->gfp_mask,
&nr_soft_scanned);
sc->nr_reclaimed += nr_soft_reclaimed;
sc->nr_scanned += nr_soft_scanned;
}
shrink_zone(zone, sc);
}
return aborted_reclaim;
}
static bool zone_reclaimable(struct zone *zone)
{
return zone->pages_scanned < zone_reclaimable_pages(zone) * 6;
}
static bool all_unreclaimable(struct zonelist *zonelist,
struct scan_control *sc)
{
struct zoneref *z;
struct zone *zone;
for_each_zone_zonelist_nodemask(zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if (!populated_zone(zone))
continue;
if (!cpuset_zone_allowed_hardwall(zone, GFP_KERNEL))
continue;
if (!zone->all_unreclaimable)
return false;
}
return true;
}
static unsigned long do_try_to_free_pages(struct zonelist *zonelist,
struct scan_control *sc,
struct shrink_control *shrink)
{
unsigned long total_scanned = 0;
struct reclaim_state *reclaim_state = current->reclaim_state;
struct zoneref *z;
struct zone *zone;
unsigned long writeback_threshold;
bool aborted_reclaim;
delayacct_freepages_start();
if (global_reclaim(sc))
count_vm_event(ALLOCSTALL);
do {
sc->nr_scanned = 0;
aborted_reclaim = shrink_zones(zonelist, sc);
if (global_reclaim(sc)) {
unsigned long lru_pages = 0;
for_each_zone_zonelist(zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if (!cpuset_zone_allowed_hardwall(zone, GFP_KERNEL))
continue;
lru_pages += zone_reclaimable_pages(zone);
}
shrink_slab(shrink, sc->nr_scanned, lru_pages);
if (reclaim_state) {
sc->nr_reclaimed += reclaim_state->reclaimed_slab;
reclaim_state->reclaimed_slab = 0;
}
}
total_scanned += sc->nr_scanned;
if (sc->nr_reclaimed >= sc->nr_to_reclaim)
goto out;
writeback_threshold = sc->nr_to_reclaim + sc->nr_to_reclaim / 2;
if (total_scanned > writeback_threshold) {
wakeup_flusher_threads(laptop_mode ? 0 : total_scanned,
WB_REASON_TRY_TO_FREE_PAGES);
sc->may_writepage = 1;
}
if (!sc->hibernation_mode && sc->nr_scanned &&
sc->priority < DEF_PRIORITY - 2) {
struct zone *preferred_zone;
first_zones_zonelist(zonelist, gfp_zone(sc->gfp_mask),
&cpuset_current_mems_allowed,
&preferred_zone);
wait_iff_congested(preferred_zone, BLK_RW_ASYNC, HZ/10);
}
} while (--sc->priority >= 0);
out:
delayacct_freepages_end();
if (sc->nr_reclaimed)
return sc->nr_reclaimed;
if (oom_killer_disabled)
return 0;
if (aborted_reclaim)
return 1;
if (global_reclaim(sc) && !all_unreclaimable(zonelist, sc))
return 1;
return 0;
}
static bool pfmemalloc_watermark_ok(pg_data_t *pgdat)
{
struct zone *zone;
unsigned long pfmemalloc_reserve = 0;
unsigned long free_pages = 0;
int i;
bool wmark_ok;
for (i = 0; i <= ZONE_NORMAL; i++) {
zone = &pgdat->node_zones[i];
pfmemalloc_reserve += min_wmark_pages(zone);
free_pages += zone_page_state(zone, NR_FREE_PAGES);
}
wmark_ok = free_pages > pfmemalloc_reserve / 2;
if (!wmark_ok && waitqueue_active(&pgdat->kswapd_wait)) {
pgdat->classzone_idx = min(pgdat->classzone_idx,
(enum zone_type)ZONE_NORMAL);
wake_up_interruptible(&pgdat->kswapd_wait);
}
return wmark_ok;
}
static bool throttle_direct_reclaim(gfp_t gfp_mask, struct zonelist *zonelist,
nodemask_t *nodemask)
{
struct zone *zone;
int high_zoneidx = gfp_zone(gfp_mask);
pg_data_t *pgdat;
if (current->flags & PF_KTHREAD)
goto out;
if (fatal_signal_pending(current))
goto out;
first_zones_zonelist(zonelist, high_zoneidx, NULL, &zone);
pgdat = zone->zone_pgdat;
if (pfmemalloc_watermark_ok(pgdat))
goto out;
count_vm_event(PGSCAN_DIRECT_THROTTLE);
if (!(gfp_mask & __GFP_FS)) {
wait_event_interruptible_timeout(pgdat->pfmemalloc_wait,
pfmemalloc_watermark_ok(pgdat), HZ);
goto check_pending;
}
wait_event_killable(zone->zone_pgdat->pfmemalloc_wait,
pfmemalloc_watermark_ok(pgdat));
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
.gfp_mask = gfp_mask,
.may_writepage = !laptop_mode,
.nr_to_reclaim = SWAP_CLUSTER_MAX,
.may_unmap = 1,
.may_swap = 1,
.order = order,
.priority = DEF_PRIORITY,
.target_mem_cgroup = NULL,
.nodemask = nodemask,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
if (throttle_direct_reclaim(gfp_mask, zonelist, nodemask))
return 1;
trace_mm_vmscan_direct_reclaim_begin(order,
sc.may_writepage,
gfp_mask);
nr_reclaimed = do_try_to_free_pages(zonelist, &sc, &shrink);
trace_mm_vmscan_direct_reclaim_end(nr_reclaimed);
return nr_reclaimed;
}
unsigned long mem_cgroup_shrink_node_zone(struct mem_cgroup *memcg,
gfp_t gfp_mask, bool noswap,
struct zone *zone,
unsigned long *nr_scanned)
{
struct scan_control sc = {
.nr_scanned = 0,
.nr_to_reclaim = SWAP_CLUSTER_MAX,
.may_writepage = !laptop_mode,
.may_unmap = 1,
.may_swap = !noswap,
.order = 0,
.priority = 0,
.target_mem_cgroup = memcg,
};
struct lruvec *lruvec = mem_cgroup_zone_lruvec(zone, memcg);
sc.gfp_mask = (gfp_mask & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK);
trace_mm_vmscan_memcg_softlimit_reclaim_begin(sc.order,
sc.may_writepage,
sc.gfp_mask);
shrink_lruvec(lruvec, &sc);
trace_mm_vmscan_memcg_softlimit_reclaim_end(sc.nr_reclaimed);
*nr_scanned = sc.nr_scanned;
return sc.nr_reclaimed;
}
unsigned long try_to_free_mem_cgroup_pages(struct mem_cgroup *memcg,
gfp_t gfp_mask,
bool noswap)
{
struct zonelist *zonelist;
unsigned long nr_reclaimed;
int nid;
struct scan_control sc = {
.may_writepage = !laptop_mode,
.may_unmap = 1,
.may_swap = !noswap,
.nr_to_reclaim = SWAP_CLUSTER_MAX,
.order = 0,
.priority = DEF_PRIORITY,
.target_mem_cgroup = memcg,
.nodemask = NULL,
.gfp_mask = (gfp_mask & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK),
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
nid = mem_cgroup_select_victim_node(memcg);
zonelist = NODE_DATA(nid)->node_zonelists;
trace_mm_vmscan_memcg_reclaim_begin(0,
sc.may_writepage,
sc.gfp_mask);
nr_reclaimed = do_try_to_free_pages(zonelist, &sc, &shrink);
trace_mm_vmscan_memcg_reclaim_end(nr_reclaimed);
return nr_reclaimed;
}
static void age_active_anon(struct zone *zone, struct scan_control *sc)
{
struct mem_cgroup *memcg;
if (!total_swap_pages)
return;
memcg = mem_cgroup_iter(NULL, NULL, NULL);
do {
struct lruvec *lruvec = mem_cgroup_zone_lruvec(zone, memcg);
if (inactive_anon_is_low(lruvec))
shrink_active_list(SWAP_CLUSTER_MAX, lruvec,
sc, LRU_ACTIVE_ANON);
memcg = mem_cgroup_iter(NULL, memcg, NULL);
} while (memcg);
}
static bool zone_balanced(struct zone *zone, int order,
unsigned long balance_gap, int classzone_idx)
{
if (!zone_watermark_ok_safe(zone, order, high_wmark_pages(zone) +
balance_gap, classzone_idx, 0))
return false;
if (COMPACTION_BUILD && order && !compaction_suitable(zone, order))
return false;
return true;
}
static bool pgdat_balanced(pg_data_t *pgdat, unsigned long balanced_pages,
int classzone_idx)
{
unsigned long present_pages = 0;
int i;
for (i = 0; i <= classzone_idx; i++)
present_pages += pgdat->node_zones[i].present_pages;
return balanced_pages >= (present_pages >> 2);
}
static bool prepare_kswapd_sleep(pg_data_t *pgdat, int order, long remaining,
int classzone_idx)
{
int i;
unsigned long balanced = 0;
bool all_zones_ok = true;
if (remaining)
return false;
if (waitqueue_active(&pgdat->pfmemalloc_wait)) {
wake_up(&pgdat->pfmemalloc_wait);
return false;
}
for (i = 0; i <= classzone_idx; i++) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable) {
balanced += zone->present_pages;
continue;
}
if (!zone_balanced(zone, order, 0, i))
all_zones_ok = false;
else
balanced += zone->present_pages;
}
if (order)
return pgdat_balanced(pgdat, balanced, classzone_idx);
else
return all_zones_ok;
}
static unsigned long balance_pgdat(pg_data_t *pgdat, int order,
int *classzone_idx)
{
int all_zones_ok;
unsigned long balanced;
int i;
int end_zone = 0;
unsigned long total_scanned;
struct reclaim_state *reclaim_state = current->reclaim_state;
unsigned long nr_soft_reclaimed;
unsigned long nr_soft_scanned;
struct scan_control sc = {
.gfp_mask = GFP_KERNEL,
.may_unmap = 1,
.may_swap = 1,
.nr_to_reclaim = ULONG_MAX,
.order = order,
.target_mem_cgroup = NULL,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
loop_again:
total_scanned = 0;
sc.priority = DEF_PRIORITY;
sc.nr_reclaimed = 0;
sc.may_writepage = !laptop_mode;
count_vm_event(PAGEOUTRUN);
do {
unsigned long lru_pages = 0;
int has_under_min_watermark_zone = 0;
all_zones_ok = 1;
balanced = 0;
for (i = pgdat->nr_zones - 1; i >= 0; i--) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable &&
sc.priority != DEF_PRIORITY)
continue;
age_active_anon(zone, &sc);
if (buffer_heads_over_limit && is_highmem_idx(i)) {
end_zone = i;
break;
}
if (!zone_balanced(zone, order, 0, 0)) {
end_zone = i;
break;
} else {
zone_clear_flag(zone, ZONE_CONGESTED);
}
}
if (i < 0)
goto out;
for (i = 0; i <= end_zone; i++) {
struct zone *zone = pgdat->node_zones + i;
lru_pages += zone_reclaimable_pages(zone);
}
for (i = 0; i <= end_zone; i++) {
struct zone *zone = pgdat->node_zones + i;
int nr_slab, testorder;
unsigned long balance_gap;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable &&
sc.priority != DEF_PRIORITY)
continue;
sc.nr_scanned = 0;
nr_soft_scanned = 0;
nr_soft_reclaimed = mem_cgroup_soft_limit_reclaim(zone,
order, sc.gfp_mask,
&nr_soft_scanned);
sc.nr_reclaimed += nr_soft_reclaimed;
total_scanned += nr_soft_scanned;
balance_gap = min(low_wmark_pages(zone),
(zone->present_pages +
KSWAPD_ZONE_BALANCE_GAP_RATIO-1) /
KSWAPD_ZONE_BALANCE_GAP_RATIO);
testorder = order;
if (COMPACTION_BUILD && order &&
compaction_suitable(zone, order) !=
COMPACT_SKIPPED)
testorder = 0;
if ((buffer_heads_over_limit && is_highmem_idx(i)) ||
!zone_balanced(zone, testorder,
balance_gap, end_zone)) {
shrink_zone(zone, &sc);
reclaim_state->reclaimed_slab = 0;
nr_slab = shrink_slab(&shrink, sc.nr_scanned, lru_pages);
sc.nr_reclaimed += reclaim_state->reclaimed_slab;
total_scanned += sc.nr_scanned;
if (nr_slab == 0 && !zone_reclaimable(zone))
zone->all_unreclaimable = 1;
}
if (total_scanned > SWAP_CLUSTER_MAX * 2 &&
total_scanned > sc.nr_reclaimed + sc.nr_reclaimed / 2)
sc.may_writepage = 1;
if (zone->all_unreclaimable) {
if (end_zone && end_zone == i)
end_zone--;
continue;
}
if (!zone_balanced(zone, testorder, 0, end_zone)) {
all_zones_ok = 0;
if (!zone_watermark_ok_safe(zone, order,
min_wmark_pages(zone), end_zone, 0))
has_under_min_watermark_zone = 1;
} else {
zone_clear_flag(zone, ZONE_CONGESTED);
if (i <= *classzone_idx)
balanced += zone->present_pages;
}
}
if (waitqueue_active(&pgdat->pfmemalloc_wait) &&
pfmemalloc_watermark_ok(pgdat))
wake_up(&pgdat->pfmemalloc_wait);
if (all_zones_ok || (order && pgdat_balanced(pgdat, balanced, *classzone_idx)))
break;
if (total_scanned && (sc.priority < DEF_PRIORITY - 2)) {
if (has_under_min_watermark_zone)
count_vm_event(KSWAPD_SKIP_CONGESTION_WAIT);
else
congestion_wait(BLK_RW_ASYNC, HZ/10);
}
if (sc.nr_reclaimed >= SWAP_CLUSTER_MAX)
break;
} while (--sc.priority >= 0);
out:
if (!(all_zones_ok || (order && pgdat_balanced(pgdat, balanced, *classzone_idx)))) {
cond_resched();
try_to_freeze();
if (sc.nr_reclaimed < SWAP_CLUSTER_MAX)
order = sc.order = 0;
goto loop_again;
}
if (order) {
int zones_need_compaction = 1;
for (i = 0; i <= end_zone; i++) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone_watermark_ok(zone, order,
low_wmark_pages(zone), *classzone_idx, 0))
zones_need_compaction = 0;
}
if (zones_need_compaction)
compact_pgdat(pgdat, order);
}
*classzone_idx = end_zone;
return order;
}
static void kswapd_try_to_sleep(pg_data_t *pgdat, int order, int classzone_idx)
{
long remaining = 0;
DEFINE_WAIT(wait);
if (freezing(current) || kthread_should_stop())
return;
prepare_to_wait(&pgdat->kswapd_wait, &wait, TASK_INTERRUPTIBLE);
if (prepare_kswapd_sleep(pgdat, order, remaining, classzone_idx)) {
remaining = schedule_timeout(HZ/10);
finish_wait(&pgdat->kswapd_wait, &wait);
prepare_to_wait(&pgdat->kswapd_wait, &wait, TASK_INTERRUPTIBLE);
}
if (prepare_kswapd_sleep(pgdat, order, remaining, classzone_idx)) {
trace_mm_vmscan_kswapd_sleep(pgdat->node_id);
set_pgdat_percpu_threshold(pgdat, calculate_normal_threshold);
reset_isolation_suitable(pgdat);
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
unsigned long order, new_order;
unsigned balanced_order;
int classzone_idx, new_classzone_idx;
int balanced_classzone_idx;
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
order = new_order = 0;
balanced_order = 0;
classzone_idx = new_classzone_idx = pgdat->nr_zones - 1;
balanced_classzone_idx = classzone_idx;
for ( ; ; ) {
int ret;
if (balanced_classzone_idx >= new_classzone_idx &&
balanced_order == new_order) {
new_order = pgdat->kswapd_max_order;
new_classzone_idx = pgdat->classzone_idx;
pgdat->kswapd_max_order = 0;
pgdat->classzone_idx = pgdat->nr_zones - 1;
}
if (order < new_order || classzone_idx > new_classzone_idx) {
order = new_order;
classzone_idx = new_classzone_idx;
} else {
kswapd_try_to_sleep(pgdat, balanced_order,
balanced_classzone_idx);
order = pgdat->kswapd_max_order;
classzone_idx = pgdat->classzone_idx;
new_order = order;
new_classzone_idx = classzone_idx;
pgdat->kswapd_max_order = 0;
pgdat->classzone_idx = pgdat->nr_zones - 1;
}
ret = try_to_freeze();
if (kthread_should_stop())
break;
if (!ret) {
trace_mm_vmscan_kswapd_wake(pgdat->node_id, order);
balanced_classzone_idx = classzone_idx;
balanced_order = balance_pgdat(pgdat, order,
&balanced_classzone_idx);
}
}
current->reclaim_state = NULL;
return 0;
}
void wakeup_kswapd(struct zone *zone, int order, enum zone_type classzone_idx)
{
pg_data_t *pgdat;
if (!populated_zone(zone))
return;
if (!cpuset_zone_allowed_hardwall(zone, GFP_KERNEL))
return;
pgdat = zone->zone_pgdat;
if (pgdat->kswapd_max_order < order) {
pgdat->kswapd_max_order = order;
pgdat->classzone_idx = min(pgdat->classzone_idx, classzone_idx);
}
if (!waitqueue_active(&pgdat->kswapd_wait))
return;
if (zone_watermark_ok_safe(zone, order, low_wmark_pages(zone), 0, 0))
return;
trace_mm_vmscan_wakeup_kswapd(pgdat->node_id, zone_idx(zone), order);
wake_up_interruptible(&pgdat->kswapd_wait);
}
unsigned long global_reclaimable_pages(void)
{
int nr;
nr = global_page_state(NR_ACTIVE_FILE) +
global_page_state(NR_INACTIVE_FILE);
if (nr_swap_pages > 0)
nr += global_page_state(NR_ACTIVE_ANON) +
global_page_state(NR_INACTIVE_ANON);
return nr;
}
unsigned long zone_reclaimable_pages(struct zone *zone)
{
int nr;
nr = zone_page_state(zone, NR_ACTIVE_FILE) +
zone_page_state(zone, NR_INACTIVE_FILE);
if (nr_swap_pages > 0)
nr += zone_page_state(zone, NR_ACTIVE_ANON) +
zone_page_state(zone, NR_INACTIVE_ANON);
return nr;
}
unsigned long shrink_all_memory(unsigned long nr_to_reclaim)
{
struct reclaim_state reclaim_state;
struct scan_control sc = {
.gfp_mask = GFP_HIGHUSER_MOVABLE,
.may_swap = 1,
.may_unmap = 1,
.may_writepage = 1,
.nr_to_reclaim = nr_to_reclaim,
.hibernation_mode = 1,
.order = 0,
.priority = DEF_PRIORITY,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
struct zonelist *zonelist = node_zonelist(numa_node_id(), sc.gfp_mask);
struct task_struct *p = current;
unsigned long nr_reclaimed;
p->flags |= PF_MEMALLOC;
lockdep_set_current_reclaim_state(sc.gfp_mask);
reclaim_state.reclaimed_slab = 0;
p->reclaim_state = &reclaim_state;
nr_reclaimed = do_try_to_free_pages(zonelist, &sc, &shrink);
p->reclaim_state = NULL;
lockdep_clear_current_reclaim_state();
p->flags &= ~PF_MEMALLOC;
return nr_reclaimed;
}
static int __devinit cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
int nid;
if (action == CPU_ONLINE || action == CPU_ONLINE_FROZEN) {
for_each_node_state(nid, N_HIGH_MEMORY) {
pg_data_t *pgdat = NODE_DATA(nid);
const struct cpumask *mask;
mask = cpumask_of_node(pgdat->node_id);
if (cpumask_any_and(cpu_online_mask, mask) < nr_cpu_ids)
set_cpus_allowed_ptr(pgdat->kswapd, mask);
}
}
return NOTIFY_OK;
}
int kswapd_run(int nid)
{
pg_data_t *pgdat = NODE_DATA(nid);
int ret = 0;
if (pgdat->kswapd)
return 0;
pgdat->kswapd = kthread_run(kswapd, pgdat, "kswapd%d", nid);
if (IS_ERR(pgdat->kswapd)) {
BUG_ON(system_state == SYSTEM_BOOTING);
pgdat->kswapd = NULL;
pr_err("Failed to start kswapd on node %d\n", nid);
ret = PTR_ERR(pgdat->kswapd);
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
int nid;
swap_setup();
for_each_node_state(nid, N_HIGH_MEMORY)
kswapd_run(nid);
hotcpu_notifier(cpu_callback, 0);
return 0;
}
static inline unsigned long zone_unmapped_file_pages(struct zone *zone)
{
unsigned long file_mapped = zone_page_state(zone, NR_FILE_MAPPED);
unsigned long file_lru = zone_page_state(zone, NR_INACTIVE_FILE) +
zone_page_state(zone, NR_ACTIVE_FILE);
return (file_lru > file_mapped) ? (file_lru - file_mapped) : 0;
}
static long zone_pagecache_reclaimable(struct zone *zone)
{
long nr_pagecache_reclaimable;
long delta = 0;
if (zone_reclaim_mode & RECLAIM_SWAP)
nr_pagecache_reclaimable = zone_page_state(zone, NR_FILE_PAGES);
else
nr_pagecache_reclaimable = zone_unmapped_file_pages(zone);
if (!(zone_reclaim_mode & RECLAIM_WRITE))
delta += zone_page_state(zone, NR_FILE_DIRTY);
if (unlikely(delta > nr_pagecache_reclaimable))
delta = nr_pagecache_reclaimable;
return nr_pagecache_reclaimable - delta;
}
static int __zone_reclaim(struct zone *zone, gfp_t gfp_mask, unsigned int order)
{
const unsigned long nr_pages = 1 << order;
struct task_struct *p = current;
struct reclaim_state reclaim_state;
struct scan_control sc = {
.may_writepage = !!(zone_reclaim_mode & RECLAIM_WRITE),
.may_unmap = !!(zone_reclaim_mode & RECLAIM_SWAP),
.may_swap = 1,
.nr_to_reclaim = max_t(unsigned long, nr_pages,
SWAP_CLUSTER_MAX),
.gfp_mask = gfp_mask,
.order = order,
.priority = ZONE_RECLAIM_PRIORITY,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
unsigned long nr_slab_pages0, nr_slab_pages1;
cond_resched();
p->flags |= PF_MEMALLOC | PF_SWAPWRITE;
lockdep_set_current_reclaim_state(gfp_mask);
reclaim_state.reclaimed_slab = 0;
p->reclaim_state = &reclaim_state;
if (zone_pagecache_reclaimable(zone) > zone->min_unmapped_pages) {
do {
shrink_zone(zone, &sc);
} while (sc.nr_reclaimed < nr_pages && --sc.priority >= 0);
}
nr_slab_pages0 = zone_page_state(zone, NR_SLAB_RECLAIMABLE);
if (nr_slab_pages0 > zone->min_slab_pages) {
for (;;) {
unsigned long lru_pages = zone_reclaimable_pages(zone);
if (!shrink_slab(&shrink, sc.nr_scanned, lru_pages))
break;
nr_slab_pages1 = zone_page_state(zone,
NR_SLAB_RECLAIMABLE);
if (nr_slab_pages1 + nr_pages <= nr_slab_pages0)
break;
}
nr_slab_pages1 = zone_page_state(zone, NR_SLAB_RECLAIMABLE);
if (nr_slab_pages1 < nr_slab_pages0)
sc.nr_reclaimed += nr_slab_pages0 - nr_slab_pages1;
}
p->reclaim_state = NULL;
current->flags &= ~(PF_MEMALLOC | PF_SWAPWRITE);
lockdep_clear_current_reclaim_state();
return sc.nr_reclaimed >= nr_pages;
}
int zone_reclaim(struct zone *zone, gfp_t gfp_mask, unsigned int order)
{
int node_id;
int ret;
if (zone_pagecache_reclaimable(zone) <= zone->min_unmapped_pages &&
zone_page_state(zone, NR_SLAB_RECLAIMABLE) <= zone->min_slab_pages)
return ZONE_RECLAIM_FULL;
if (zone->all_unreclaimable)
return ZONE_RECLAIM_FULL;
if (!(gfp_mask & __GFP_WAIT) || (current->flags & PF_MEMALLOC))
return ZONE_RECLAIM_NOSCAN;
node_id = zone_to_nid(zone);
if (node_state(node_id, N_CPU) && node_id != numa_node_id())
return ZONE_RECLAIM_NOSCAN;
if (zone_test_and_set_flag(zone, ZONE_RECLAIM_LOCKED))
return ZONE_RECLAIM_NOSCAN;
ret = __zone_reclaim(zone, gfp_mask, order);
zone_clear_flag(zone, ZONE_RECLAIM_LOCKED);
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
struct zone *zone = NULL;
int pgscanned = 0;
int pgrescued = 0;
int i;
for (i = 0; i < nr_pages; i++) {
struct page *page = pages[i];
struct zone *pagezone;
pgscanned++;
pagezone = page_zone(page);
if (pagezone != zone) {
if (zone)
spin_unlock_irq(&zone->lru_lock);
zone = pagezone;
spin_lock_irq(&zone->lru_lock);
}
lruvec = mem_cgroup_page_lruvec(page, zone);
if (!PageLRU(page) || !PageUnevictable(page))
continue;
if (page_evictable(page)) {
enum lru_list lru = page_lru_base_type(page);
VM_BUG_ON(PageActive(page));
ClearPageUnevictable(page);
del_page_from_lru_list(page, lruvec, LRU_UNEVICTABLE);
add_page_to_lru_list(page, lruvec, lru);
pgrescued++;
}
}
if (zone) {
__count_vm_events(UNEVICTABLE_PGRESCUED, pgrescued);
__count_vm_events(UNEVICTABLE_PGSCANNED, pgscanned);
spin_unlock_irq(&zone->lru_lock);
}
}
static void warn_scan_unevictable_pages(void)
{
printk_once(KERN_WARNING
"%s: The scan_unevictable_pages sysctl/node-interface has been "
"disabled for lack of a legitimate use case. If you have "
"one, please send an email to linux-mm@kvack.org.\n",
current->comm);
}
int scan_unevictable_handler(struct ctl_table *table, int write,
void __user *buffer,
size_t *length, loff_t *ppos)
{
warn_scan_unevictable_pages();
proc_doulongvec_minmax(table, write, buffer, length, ppos);
scan_unevictable_pages = 0;
return 0;
}
static ssize_t read_scan_unevictable_node(struct device *dev,
struct device_attribute *attr,
char *buf)
{
warn_scan_unevictable_pages();
return sprintf(buf, "0\n");
}
static ssize_t write_scan_unevictable_node(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
warn_scan_unevictable_pages();
return 1;
}
int scan_unevictable_register_node(struct node *node)
{
return device_create_file(&node->dev, &dev_attr_scan_unevictable_pages);
}
void scan_unevictable_unregister_node(struct node *node)
{
device_remove_file(&node->dev, &dev_attr_scan_unevictable_pages);
}
