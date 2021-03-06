static struct zone_reclaim_stat *get_reclaim_stat(struct zone *zone,
struct scan_control *sc)
{
if (!scanning_global_lru(sc))
return mem_cgroup_get_reclaim_stat(sc->mem_cgroup, zone);
return &zone->reclaim_stat;
}
static unsigned long zone_nr_lru_pages(struct zone *zone,
struct scan_control *sc, enum lru_list lru)
{
if (!scanning_global_lru(sc))
return mem_cgroup_zone_nr_lru_pages(sc->mem_cgroup,
zone_to_nid(zone), zone_idx(zone), BIT(lru));
return zone_page_state(zone, NR_LRU_BASE + lru);
}
void register_shrinker(struct shrinker *shrinker)
{
shrinker->nr = 0;
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
unsigned long total_scan;
unsigned long max_pass;
int shrink_ret = 0;
long nr;
long new_nr;
long batch_size = shrinker->batch ? shrinker->batch
: SHRINK_BATCH;
do {
nr = shrinker->nr;
} while (cmpxchg(&shrinker->nr, nr, 0) != nr);
total_scan = nr;
max_pass = do_shrinker_shrink(shrinker, shrink, 0);
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
do {
nr = shrinker->nr;
new_nr = total_scan + nr;
if (total_scan <= 0)
break;
} while (cmpxchg(&shrinker->nr, nr, new_nr) != nr);
trace_mm_shrink_slab_end(shrinker, shrink_ret, nr, new_nr);
}
up_read(&shrinker_rwsem);
out:
cond_resched();
return ret;
}
static void set_reclaim_mode(int priority, struct scan_control *sc,
bool sync)
{
reclaim_mode_t syncmode = sync ? RECLAIM_MODE_SYNC : RECLAIM_MODE_ASYNC;
if (COMPACTION_BUILD)
sc->reclaim_mode = RECLAIM_MODE_COMPACTION;
else
sc->reclaim_mode = RECLAIM_MODE_LUMPYRECLAIM;
if (sc->order > PAGE_ALLOC_COSTLY_ORDER)
sc->reclaim_mode |= syncmode;
else if (sc->order && priority < DEF_PRIORITY - 2)
sc->reclaim_mode |= syncmode;
else
sc->reclaim_mode = RECLAIM_MODE_SINGLE | RECLAIM_MODE_ASYNC;
}
static void reset_reclaim_mode(struct scan_control *sc)
{
sc->reclaim_mode = RECLAIM_MODE_SINGLE | RECLAIM_MODE_ASYNC;
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
if (sc->order > PAGE_ALLOC_COSTLY_ORDER)
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
if (PageWriteback(page) &&
(sc->reclaim_mode & RECLAIM_MODE_SYNC))
wait_on_page_writeback(page);
if (!PageWriteback(page)) {
ClearPageReclaim(page);
}
trace_mm_vmscan_writepage(page,
trace_reclaim_flags(page, sc->reclaim_mode));
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
if (page_evictable(page, NULL)) {
lru = active + page_lru_base_type(page);
lru_cache_add_lru(page, lru);
} else {
lru = LRU_UNEVICTABLE;
add_page_to_unevictable_list(page);
smp_mb();
}
if (lru == LRU_UNEVICTABLE && page_evictable(page, NULL)) {
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
referenced_ptes = page_referenced(page, 1, sc->mem_cgroup, &vm_flags);
referenced_page = TestClearPageReferenced(page);
if (sc->reclaim_mode & RECLAIM_MODE_LUMPYRECLAIM)
return PAGEREF_RECLAIM;
if (vm_flags & VM_LOCKED)
return PAGEREF_RECLAIM;
if (referenced_ptes) {
if (PageAnon(page))
return PAGEREF_ACTIVATE;
SetPageReferenced(page);
if (referenced_page)
return PAGEREF_ACTIVATE;
return PAGEREF_KEEP;
}
if (referenced_page && !PageSwapBacked(page))
return PAGEREF_RECLAIM_CLEAN;
return PAGEREF_RECLAIM;
}
static noinline_for_stack void free_page_list(struct list_head *free_pages)
{
struct pagevec freed_pvec;
struct page *page, *tmp;
pagevec_init(&freed_pvec, 1);
list_for_each_entry_safe(page, tmp, free_pages, lru) {
list_del(&page->lru);
if (!pagevec_add(&freed_pvec, page)) {
__pagevec_free(&freed_pvec);
pagevec_reinit(&freed_pvec);
}
}
pagevec_free(&freed_pvec);
}
static unsigned long shrink_page_list(struct list_head *page_list,
struct zone *zone,
struct scan_control *sc)
{
LIST_HEAD(ret_pages);
LIST_HEAD(free_pages);
int pgactivate = 0;
unsigned long nr_dirty = 0;
unsigned long nr_congested = 0;
unsigned long nr_reclaimed = 0;
cond_resched();
while (!list_empty(page_list)) {
enum page_references references;
struct address_space *mapping;
struct page *page;
int may_enter_fs;
cond_resched();
page = lru_to_page(page_list);
list_del(&page->lru);
if (!trylock_page(page))
goto keep;
VM_BUG_ON(PageActive(page));
VM_BUG_ON(page_zone(page) != zone);
sc->nr_scanned++;
if (unlikely(!page_evictable(page, NULL)))
goto cull_mlocked;
if (!sc->may_unmap && page_mapped(page))
goto keep_locked;
if (page_mapped(page) || PageSwapCache(page))
sc->nr_scanned++;
may_enter_fs = (sc->gfp_mask & __GFP_FS) ||
(PageSwapCache(page) && (sc->gfp_mask & __GFP_IO));
if (PageWriteback(page)) {
if ((sc->reclaim_mode & RECLAIM_MODE_SYNC) &&
may_enter_fs)
wait_on_page_writeback(page);
else {
unlock_page(page);
goto keep_lumpy;
}
}
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
switch (try_to_unmap(page, TTU_UNMAP)) {
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
goto keep_lumpy;
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
reset_reclaim_mode(sc);
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
reset_reclaim_mode(sc);
keep_lumpy:
list_add(&page->lru, &ret_pages);
VM_BUG_ON(PageLRU(page) || PageUnevictable(page));
}
if (nr_dirty && nr_dirty == nr_congested && scanning_global_lru(sc))
zone_set_flag(zone, ZONE_CONGESTED);
free_page_list(&free_pages);
list_splice(&ret_pages, page_list);
count_vm_events(PGACTIVATE, pgactivate);
return nr_reclaimed;
}
int __isolate_lru_page(struct page *page, int mode, int file)
{
int ret = -EINVAL;
if (!PageLRU(page))
return ret;
if (mode != ISOLATE_BOTH && (!PageActive(page) != !mode))
return ret;
if (mode != ISOLATE_BOTH && page_is_file_cache(page) != file)
return ret;
if (PageUnevictable(page))
return ret;
ret = -EBUSY;
if (likely(get_page_unless_zero(page))) {
ClearPageLRU(page);
ret = 0;
}
return ret;
}
static unsigned long isolate_lru_pages(unsigned long nr_to_scan,
struct list_head *src, struct list_head *dst,
unsigned long *scanned, int order, int mode, int file)
{
unsigned long nr_taken = 0;
unsigned long nr_lumpy_taken = 0;
unsigned long nr_lumpy_dirty = 0;
unsigned long nr_lumpy_failed = 0;
unsigned long scan;
for (scan = 0; scan < nr_to_scan && !list_empty(src); scan++) {
struct page *page;
unsigned long pfn;
unsigned long end_pfn;
unsigned long page_pfn;
int zone_id;
page = lru_to_page(src);
prefetchw_prev_lru_page(page, src, flags);
VM_BUG_ON(!PageLRU(page));
switch (__isolate_lru_page(page, mode, file)) {
case 0:
list_move(&page->lru, dst);
mem_cgroup_del_lru(page);
nr_taken += hpage_nr_pages(page);
break;
case -EBUSY:
list_move(&page->lru, src);
mem_cgroup_rotate_lru_list(page, page_lru(page));
continue;
default:
BUG();
}
if (!order)
continue;
zone_id = page_zone_id(page);
page_pfn = page_to_pfn(page);
pfn = page_pfn & ~((1 << order) - 1);
end_pfn = pfn + (1 << order);
for (; pfn < end_pfn; pfn++) {
struct page *cursor_page;
if (unlikely(pfn == page_pfn))
continue;
if (unlikely(!pfn_valid_within(pfn)))
break;
cursor_page = pfn_to_page(pfn);
if (unlikely(page_zone_id(cursor_page) != zone_id))
break;
if (nr_swap_pages <= 0 && PageAnon(cursor_page) &&
!PageSwapCache(cursor_page))
break;
if (__isolate_lru_page(cursor_page, mode, file) == 0) {
list_move(&cursor_page->lru, dst);
mem_cgroup_del_lru(cursor_page);
nr_taken += hpage_nr_pages(page);
nr_lumpy_taken++;
if (PageDirty(cursor_page))
nr_lumpy_dirty++;
scan++;
} else {
if (!PageTail(cursor_page) &&
!atomic_read(&cursor_page->_count))
continue;
break;
}
}
if (pfn < end_pfn)
nr_lumpy_failed++;
}
*scanned = scan;
trace_mm_vmscan_lru_isolate(order,
nr_to_scan, scan,
nr_taken,
nr_lumpy_taken, nr_lumpy_dirty, nr_lumpy_failed,
mode);
return nr_taken;
}
static unsigned long isolate_pages_global(unsigned long nr,
struct list_head *dst,
unsigned long *scanned, int order,
int mode, struct zone *z,
int active, int file)
{
int lru = LRU_BASE;
if (active)
lru += LRU_ACTIVE;
if (file)
lru += LRU_FILE;
return isolate_lru_pages(nr, &z->lru[lru].list, dst, scanned, order,
mode, file);
}
static unsigned long clear_active_flags(struct list_head *page_list,
unsigned int *count)
{
int nr_active = 0;
int lru;
struct page *page;
list_for_each_entry(page, page_list, lru) {
int numpages = hpage_nr_pages(page);
lru = page_lru_base_type(page);
if (PageActive(page)) {
lru += LRU_ACTIVE;
ClearPageActive(page);
nr_active += numpages;
}
if (count)
count[lru] += numpages;
}
return nr_active;
}
int isolate_lru_page(struct page *page)
{
int ret = -EBUSY;
VM_BUG_ON(!page_count(page));
if (PageLRU(page)) {
struct zone *zone = page_zone(page);
spin_lock_irq(&zone->lru_lock);
if (PageLRU(page)) {
int lru = page_lru(page);
ret = 0;
get_page(page);
ClearPageLRU(page);
del_page_from_lru_list(zone, page, lru);
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
if (!scanning_global_lru(sc))
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
putback_lru_pages(struct zone *zone, struct scan_control *sc,
unsigned long nr_anon, unsigned long nr_file,
struct list_head *page_list)
{
struct page *page;
struct pagevec pvec;
struct zone_reclaim_stat *reclaim_stat = get_reclaim_stat(zone, sc);
pagevec_init(&pvec, 1);
spin_lock(&zone->lru_lock);
while (!list_empty(page_list)) {
int lru;
page = lru_to_page(page_list);
VM_BUG_ON(PageLRU(page));
list_del(&page->lru);
if (unlikely(!page_evictable(page, NULL))) {
spin_unlock_irq(&zone->lru_lock);
putback_lru_page(page);
spin_lock_irq(&zone->lru_lock);
continue;
}
SetPageLRU(page);
lru = page_lru(page);
add_page_to_lru_list(zone, page, lru);
if (is_active_lru(lru)) {
int file = is_file_lru(lru);
int numpages = hpage_nr_pages(page);
reclaim_stat->recent_rotated[file] += numpages;
}
if (!pagevec_add(&pvec, page)) {
spin_unlock_irq(&zone->lru_lock);
__pagevec_release(&pvec);
spin_lock_irq(&zone->lru_lock);
}
}
__mod_zone_page_state(zone, NR_ISOLATED_ANON, -nr_anon);
__mod_zone_page_state(zone, NR_ISOLATED_FILE, -nr_file);
spin_unlock_irq(&zone->lru_lock);
pagevec_release(&pvec);
}
static noinline_for_stack void update_isolated_counts(struct zone *zone,
struct scan_control *sc,
unsigned long *nr_anon,
unsigned long *nr_file,
struct list_head *isolated_list)
{
unsigned long nr_active;
unsigned int count[NR_LRU_LISTS] = { 0, };
struct zone_reclaim_stat *reclaim_stat = get_reclaim_stat(zone, sc);
nr_active = clear_active_flags(isolated_list, count);
__count_vm_events(PGDEACTIVATE, nr_active);
__mod_zone_page_state(zone, NR_ACTIVE_FILE,
-count[LRU_ACTIVE_FILE]);
__mod_zone_page_state(zone, NR_INACTIVE_FILE,
-count[LRU_INACTIVE_FILE]);
__mod_zone_page_state(zone, NR_ACTIVE_ANON,
-count[LRU_ACTIVE_ANON]);
__mod_zone_page_state(zone, NR_INACTIVE_ANON,
-count[LRU_INACTIVE_ANON]);
*nr_anon = count[LRU_ACTIVE_ANON] + count[LRU_INACTIVE_ANON];
*nr_file = count[LRU_ACTIVE_FILE] + count[LRU_INACTIVE_FILE];
__mod_zone_page_state(zone, NR_ISOLATED_ANON, *nr_anon);
__mod_zone_page_state(zone, NR_ISOLATED_FILE, *nr_file);
reclaim_stat->recent_scanned[0] += *nr_anon;
reclaim_stat->recent_scanned[1] += *nr_file;
}
static inline bool should_reclaim_stall(unsigned long nr_taken,
unsigned long nr_freed,
int priority,
struct scan_control *sc)
{
int lumpy_stall_priority;
if (current_is_kswapd())
return false;
if (sc->reclaim_mode & RECLAIM_MODE_SINGLE)
return false;
if (nr_freed == nr_taken)
return false;
if (sc->order > PAGE_ALLOC_COSTLY_ORDER)
lumpy_stall_priority = DEF_PRIORITY;
else
lumpy_stall_priority = DEF_PRIORITY / 3;
return priority <= lumpy_stall_priority;
}
static noinline_for_stack unsigned long
shrink_inactive_list(unsigned long nr_to_scan, struct zone *zone,
struct scan_control *sc, int priority, int file)
{
LIST_HEAD(page_list);
unsigned long nr_scanned;
unsigned long nr_reclaimed = 0;
unsigned long nr_taken;
unsigned long nr_anon;
unsigned long nr_file;
while (unlikely(too_many_isolated(zone, file, sc))) {
congestion_wait(BLK_RW_ASYNC, HZ/10);
if (fatal_signal_pending(current))
return SWAP_CLUSTER_MAX;
}
set_reclaim_mode(priority, sc, false);
lru_add_drain();
spin_lock_irq(&zone->lru_lock);
if (scanning_global_lru(sc)) {
nr_taken = isolate_pages_global(nr_to_scan,
&page_list, &nr_scanned, sc->order,
sc->reclaim_mode & RECLAIM_MODE_LUMPYRECLAIM ?
ISOLATE_BOTH : ISOLATE_INACTIVE,
zone, 0, file);
zone->pages_scanned += nr_scanned;
if (current_is_kswapd())
__count_zone_vm_events(PGSCAN_KSWAPD, zone,
nr_scanned);
else
__count_zone_vm_events(PGSCAN_DIRECT, zone,
nr_scanned);
} else {
nr_taken = mem_cgroup_isolate_pages(nr_to_scan,
&page_list, &nr_scanned, sc->order,
sc->reclaim_mode & RECLAIM_MODE_LUMPYRECLAIM ?
ISOLATE_BOTH : ISOLATE_INACTIVE,
zone, sc->mem_cgroup,
0, file);
}
if (nr_taken == 0) {
spin_unlock_irq(&zone->lru_lock);
return 0;
}
update_isolated_counts(zone, sc, &nr_anon, &nr_file, &page_list);
spin_unlock_irq(&zone->lru_lock);
nr_reclaimed = shrink_page_list(&page_list, zone, sc);
if (should_reclaim_stall(nr_taken, nr_reclaimed, priority, sc)) {
set_reclaim_mode(priority, sc, true);
nr_reclaimed += shrink_page_list(&page_list, zone, sc);
}
local_irq_disable();
if (current_is_kswapd())
__count_vm_events(KSWAPD_STEAL, nr_reclaimed);
__count_zone_vm_events(PGSTEAL, zone, nr_reclaimed);
putback_lru_pages(zone, sc, nr_anon, nr_file, &page_list);
trace_mm_vmscan_lru_shrink_inactive(zone->zone_pgdat->node_id,
zone_idx(zone),
nr_scanned, nr_reclaimed,
priority,
trace_shrink_flags(file, sc->reclaim_mode));
return nr_reclaimed;
}
static void move_active_pages_to_lru(struct zone *zone,
struct list_head *list,
enum lru_list lru)
{
unsigned long pgmoved = 0;
struct pagevec pvec;
struct page *page;
pagevec_init(&pvec, 1);
while (!list_empty(list)) {
page = lru_to_page(list);
VM_BUG_ON(PageLRU(page));
SetPageLRU(page);
list_move(&page->lru, &zone->lru[lru].list);
mem_cgroup_add_lru_list(page, lru);
pgmoved += hpage_nr_pages(page);
if (!pagevec_add(&pvec, page) || list_empty(list)) {
spin_unlock_irq(&zone->lru_lock);
if (buffer_heads_over_limit)
pagevec_strip(&pvec);
__pagevec_release(&pvec);
spin_lock_irq(&zone->lru_lock);
}
}
__mod_zone_page_state(zone, NR_LRU_BASE + lru, pgmoved);
if (!is_active_lru(lru))
__count_vm_events(PGDEACTIVATE, pgmoved);
}
static void shrink_active_list(unsigned long nr_pages, struct zone *zone,
struct scan_control *sc, int priority, int file)
{
unsigned long nr_taken;
unsigned long pgscanned;
unsigned long vm_flags;
LIST_HEAD(l_hold);
LIST_HEAD(l_active);
LIST_HEAD(l_inactive);
struct page *page;
struct zone_reclaim_stat *reclaim_stat = get_reclaim_stat(zone, sc);
unsigned long nr_rotated = 0;
lru_add_drain();
spin_lock_irq(&zone->lru_lock);
if (scanning_global_lru(sc)) {
nr_taken = isolate_pages_global(nr_pages, &l_hold,
&pgscanned, sc->order,
ISOLATE_ACTIVE, zone,
1, file);
zone->pages_scanned += pgscanned;
} else {
nr_taken = mem_cgroup_isolate_pages(nr_pages, &l_hold,
&pgscanned, sc->order,
ISOLATE_ACTIVE, zone,
sc->mem_cgroup, 1, file);
}
reclaim_stat->recent_scanned[file] += nr_taken;
__count_zone_vm_events(PGREFILL, zone, pgscanned);
if (file)
__mod_zone_page_state(zone, NR_ACTIVE_FILE, -nr_taken);
else
__mod_zone_page_state(zone, NR_ACTIVE_ANON, -nr_taken);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, nr_taken);
spin_unlock_irq(&zone->lru_lock);
while (!list_empty(&l_hold)) {
cond_resched();
page = lru_to_page(&l_hold);
list_del(&page->lru);
if (unlikely(!page_evictable(page, NULL))) {
putback_lru_page(page);
continue;
}
if (page_referenced(page, 0, sc->mem_cgroup, &vm_flags)) {
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
move_active_pages_to_lru(zone, &l_active,
LRU_ACTIVE + file * LRU_FILE);
move_active_pages_to_lru(zone, &l_inactive,
LRU_BASE + file * LRU_FILE);
__mod_zone_page_state(zone, NR_ISOLATED_ANON + file, -nr_taken);
spin_unlock_irq(&zone->lru_lock);
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
static int inactive_anon_is_low(struct zone *zone, struct scan_control *sc)
{
int low;
if (!total_swap_pages)
return 0;
if (scanning_global_lru(sc))
low = inactive_anon_is_low_global(zone);
else
low = mem_cgroup_inactive_anon_is_low(sc->mem_cgroup);
return low;
}
static inline int inactive_anon_is_low(struct zone *zone,
struct scan_control *sc)
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
static int inactive_file_is_low(struct zone *zone, struct scan_control *sc)
{
int low;
if (scanning_global_lru(sc))
low = inactive_file_is_low_global(zone);
else
low = mem_cgroup_inactive_file_is_low(sc->mem_cgroup);
return low;
}
static int inactive_list_is_low(struct zone *zone, struct scan_control *sc,
int file)
{
if (file)
return inactive_file_is_low(zone, sc);
else
return inactive_anon_is_low(zone, sc);
}
static unsigned long shrink_list(enum lru_list lru, unsigned long nr_to_scan,
struct zone *zone, struct scan_control *sc, int priority)
{
int file = is_file_lru(lru);
if (is_active_lru(lru)) {
if (inactive_list_is_low(zone, sc, file))
shrink_active_list(nr_to_scan, zone, sc, priority, file);
return 0;
}
return shrink_inactive_list(nr_to_scan, zone, sc, priority, file);
}
static int vmscan_swappiness(struct scan_control *sc)
{
if (scanning_global_lru(sc))
return vm_swappiness;
return mem_cgroup_swappiness(sc->mem_cgroup);
}
static void get_scan_count(struct zone *zone, struct scan_control *sc,
unsigned long *nr, int priority)
{
unsigned long anon, file, free;
unsigned long anon_prio, file_prio;
unsigned long ap, fp;
struct zone_reclaim_stat *reclaim_stat = get_reclaim_stat(zone, sc);
u64 fraction[2], denominator;
enum lru_list l;
int noswap = 0;
bool force_scan = false;
unsigned long nr_force_scan[2];
if (scanning_global_lru(sc) && current_is_kswapd())
force_scan = true;
if (!scanning_global_lru(sc))
force_scan = true;
if (!sc->may_swap || (nr_swap_pages <= 0)) {
noswap = 1;
fraction[0] = 0;
fraction[1] = 1;
denominator = 1;
nr_force_scan[0] = 0;
nr_force_scan[1] = SWAP_CLUSTER_MAX;
goto out;
}
anon = zone_nr_lru_pages(zone, sc, LRU_ACTIVE_ANON) +
zone_nr_lru_pages(zone, sc, LRU_INACTIVE_ANON);
file = zone_nr_lru_pages(zone, sc, LRU_ACTIVE_FILE) +
zone_nr_lru_pages(zone, sc, LRU_INACTIVE_FILE);
if (scanning_global_lru(sc)) {
free = zone_page_state(zone, NR_FREE_PAGES);
if (unlikely(file + free <= high_wmark_pages(zone))) {
fraction[0] = 1;
fraction[1] = 0;
denominator = 1;
nr_force_scan[0] = SWAP_CLUSTER_MAX;
nr_force_scan[1] = 0;
goto out;
}
}
anon_prio = vmscan_swappiness(sc);
file_prio = 200 - vmscan_swappiness(sc);
spin_lock_irq(&zone->lru_lock);
if (unlikely(reclaim_stat->recent_scanned[0] > anon / 4)) {
reclaim_stat->recent_scanned[0] /= 2;
reclaim_stat->recent_rotated[0] /= 2;
}
if (unlikely(reclaim_stat->recent_scanned[1] > file / 4)) {
reclaim_stat->recent_scanned[1] /= 2;
reclaim_stat->recent_rotated[1] /= 2;
}
ap = (anon_prio + 1) * (reclaim_stat->recent_scanned[0] + 1);
ap /= reclaim_stat->recent_rotated[0] + 1;
fp = (file_prio + 1) * (reclaim_stat->recent_scanned[1] + 1);
fp /= reclaim_stat->recent_rotated[1] + 1;
spin_unlock_irq(&zone->lru_lock);
fraction[0] = ap;
fraction[1] = fp;
denominator = ap + fp + 1;
if (force_scan) {
unsigned long scan = SWAP_CLUSTER_MAX;
nr_force_scan[0] = div64_u64(scan * ap, denominator);
nr_force_scan[1] = div64_u64(scan * fp, denominator);
}
out:
for_each_evictable_lru(l) {
int file = is_file_lru(l);
unsigned long scan;
scan = zone_nr_lru_pages(zone, sc, l);
if (priority || noswap) {
scan >>= priority;
scan = div64_u64(scan * fraction[file], denominator);
}
if (!scan && force_scan)
scan = nr_force_scan[file];
nr[l] = scan;
}
}
static inline bool should_continue_reclaim(struct zone *zone,
unsigned long nr_reclaimed,
unsigned long nr_scanned,
struct scan_control *sc)
{
unsigned long pages_for_compaction;
unsigned long inactive_lru_pages;
if (!(sc->reclaim_mode & RECLAIM_MODE_COMPACTION))
return false;
if (sc->gfp_mask & __GFP_REPEAT) {
if (!nr_reclaimed && !nr_scanned)
return false;
} else {
if (!nr_reclaimed)
return false;
}
pages_for_compaction = (2UL << sc->order);
inactive_lru_pages = zone_nr_lru_pages(zone, sc, LRU_INACTIVE_ANON) +
zone_nr_lru_pages(zone, sc, LRU_INACTIVE_FILE);
if (sc->nr_reclaimed < pages_for_compaction &&
inactive_lru_pages > pages_for_compaction)
return true;
switch (compaction_suitable(zone, sc->order)) {
case COMPACT_PARTIAL:
case COMPACT_CONTINUE:
return false;
default:
return true;
}
}
static void shrink_zone(int priority, struct zone *zone,
struct scan_control *sc)
{
unsigned long nr[NR_LRU_LISTS];
unsigned long nr_to_scan;
enum lru_list l;
unsigned long nr_reclaimed, nr_scanned;
unsigned long nr_to_reclaim = sc->nr_to_reclaim;
restart:
nr_reclaimed = 0;
nr_scanned = sc->nr_scanned;
get_scan_count(zone, sc, nr, priority);
while (nr[LRU_INACTIVE_ANON] || nr[LRU_ACTIVE_FILE] ||
nr[LRU_INACTIVE_FILE]) {
for_each_evictable_lru(l) {
if (nr[l]) {
nr_to_scan = min_t(unsigned long,
nr[l], SWAP_CLUSTER_MAX);
nr[l] -= nr_to_scan;
nr_reclaimed += shrink_list(l, nr_to_scan,
zone, sc, priority);
}
}
if (nr_reclaimed >= nr_to_reclaim && priority < DEF_PRIORITY)
break;
}
sc->nr_reclaimed += nr_reclaimed;
if (inactive_anon_is_low(zone, sc))
shrink_active_list(SWAP_CLUSTER_MAX, zone, sc, priority, 0);
if (should_continue_reclaim(zone, nr_reclaimed,
sc->nr_scanned - nr_scanned, sc))
goto restart;
throttle_vm_writeout(sc->gfp_mask);
}
static void shrink_zones(int priority, struct zonelist *zonelist,
struct scan_control *sc)
{
struct zoneref *z;
struct zone *zone;
unsigned long nr_soft_reclaimed;
unsigned long nr_soft_scanned;
for_each_zone_zonelist_nodemask(zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if (!populated_zone(zone))
continue;
if (scanning_global_lru(sc)) {
if (!cpuset_zone_allowed_hardwall(zone, GFP_KERNEL))
continue;
if (zone->all_unreclaimable && priority != DEF_PRIORITY)
continue;
nr_soft_scanned = 0;
nr_soft_reclaimed = mem_cgroup_soft_limit_reclaim(zone,
sc->order, sc->gfp_mask,
&nr_soft_scanned);
sc->nr_reclaimed += nr_soft_reclaimed;
sc->nr_scanned += nr_soft_scanned;
}
shrink_zone(priority, zone, sc);
}
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
int priority;
unsigned long total_scanned = 0;
struct reclaim_state *reclaim_state = current->reclaim_state;
struct zoneref *z;
struct zone *zone;
unsigned long writeback_threshold;
get_mems_allowed();
delayacct_freepages_start();
if (scanning_global_lru(sc))
count_vm_event(ALLOCSTALL);
for (priority = DEF_PRIORITY; priority >= 0; priority--) {
sc->nr_scanned = 0;
if (!priority)
disable_swap_token(sc->mem_cgroup);
shrink_zones(priority, zonelist, sc);
if (scanning_global_lru(sc)) {
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
wakeup_flusher_threads(laptop_mode ? 0 : total_scanned);
sc->may_writepage = 1;
}
if (!sc->hibernation_mode && sc->nr_scanned &&
priority < DEF_PRIORITY - 2) {
struct zone *preferred_zone;
first_zones_zonelist(zonelist, gfp_zone(sc->gfp_mask),
&cpuset_current_mems_allowed,
&preferred_zone);
wait_iff_congested(preferred_zone, BLK_RW_ASYNC, HZ/10);
}
}
out:
delayacct_freepages_end();
put_mems_allowed();
if (sc->nr_reclaimed)
return sc->nr_reclaimed;
if (oom_killer_disabled)
return 0;
if (scanning_global_lru(sc) && !all_unreclaimable(zonelist, sc))
return 1;
return 0;
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
.mem_cgroup = NULL,
.nodemask = nodemask,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
trace_mm_vmscan_direct_reclaim_begin(order,
sc.may_writepage,
gfp_mask);
nr_reclaimed = do_try_to_free_pages(zonelist, &sc, &shrink);
trace_mm_vmscan_direct_reclaim_end(nr_reclaimed);
return nr_reclaimed;
}
unsigned long mem_cgroup_shrink_node_zone(struct mem_cgroup *mem,
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
.mem_cgroup = mem,
};
sc.gfp_mask = (gfp_mask & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK);
trace_mm_vmscan_memcg_softlimit_reclaim_begin(0,
sc.may_writepage,
sc.gfp_mask);
shrink_zone(0, zone, &sc);
trace_mm_vmscan_memcg_softlimit_reclaim_end(sc.nr_reclaimed);
*nr_scanned = sc.nr_scanned;
return sc.nr_reclaimed;
}
unsigned long try_to_free_mem_cgroup_pages(struct mem_cgroup *mem_cont,
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
.mem_cgroup = mem_cont,
.nodemask = NULL,
.gfp_mask = (gfp_mask & GFP_RECLAIM_MASK) |
(GFP_HIGHUSER_MOVABLE & ~GFP_RECLAIM_MASK),
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
nid = mem_cgroup_select_victim_node(mem_cont);
zonelist = NODE_DATA(nid)->node_zonelists;
trace_mm_vmscan_memcg_reclaim_begin(0,
sc.may_writepage,
sc.gfp_mask);
nr_reclaimed = do_try_to_free_pages(zonelist, &sc, &shrink);
trace_mm_vmscan_memcg_reclaim_end(nr_reclaimed);
return nr_reclaimed;
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
static bool sleeping_prematurely(pg_data_t *pgdat, int order, long remaining,
int classzone_idx)
{
int i;
unsigned long balanced = 0;
bool all_zones_ok = true;
if (remaining)
return true;
for (i = 0; i <= classzone_idx; i++) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable) {
balanced += zone->present_pages;
continue;
}
if (!zone_watermark_ok_safe(zone, order, high_wmark_pages(zone),
i, 0))
all_zones_ok = false;
else
balanced += zone->present_pages;
}
if (order)
return !pgdat_balanced(pgdat, balanced, classzone_idx);
else
return !all_zones_ok;
}
static unsigned long balance_pgdat(pg_data_t *pgdat, int order,
int *classzone_idx)
{
int all_zones_ok;
unsigned long balanced;
int priority;
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
.mem_cgroup = NULL,
};
struct shrink_control shrink = {
.gfp_mask = sc.gfp_mask,
};
loop_again:
total_scanned = 0;
sc.nr_reclaimed = 0;
sc.may_writepage = !laptop_mode;
count_vm_event(PAGEOUTRUN);
for (priority = DEF_PRIORITY; priority >= 0; priority--) {
unsigned long lru_pages = 0;
int has_under_min_watermark_zone = 0;
if (!priority)
disable_swap_token(NULL);
all_zones_ok = 1;
balanced = 0;
for (i = pgdat->nr_zones - 1; i >= 0; i--) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable && priority != DEF_PRIORITY)
continue;
if (inactive_anon_is_low(zone, &sc))
shrink_active_list(SWAP_CLUSTER_MAX, zone,
&sc, priority, 0);
if (!zone_watermark_ok_safe(zone, order,
high_wmark_pages(zone), 0, 0)) {
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
int nr_slab;
unsigned long balance_gap;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable && priority != DEF_PRIORITY)
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
if (!zone_watermark_ok_safe(zone, order,
high_wmark_pages(zone) + balance_gap,
end_zone, 0)) {
shrink_zone(priority, zone, &sc);
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
if (!zone_watermark_ok_safe(zone, order,
high_wmark_pages(zone), end_zone, 0)) {
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
if (all_zones_ok || (order && pgdat_balanced(pgdat, balanced, *classzone_idx)))
break;
if (total_scanned && (priority < DEF_PRIORITY - 2)) {
if (has_under_min_watermark_zone)
count_vm_event(KSWAPD_SKIP_CONGESTION_WAIT);
else
congestion_wait(BLK_RW_ASYNC, HZ/10);
}
if (sc.nr_reclaimed >= SWAP_CLUSTER_MAX)
break;
}
out:
if (!(all_zones_ok || (order && pgdat_balanced(pgdat, balanced, *classzone_idx)))) {
cond_resched();
try_to_freeze();
if (sc.nr_reclaimed < SWAP_CLUSTER_MAX)
order = sc.order = 0;
goto loop_again;
}
if (order) {
for (i = 0; i <= end_zone; i++) {
struct zone *zone = pgdat->node_zones + i;
if (!populated_zone(zone))
continue;
if (zone->all_unreclaimable && priority != DEF_PRIORITY)
continue;
if (!zone_watermark_ok(zone, 0,
high_wmark_pages(zone), 0, 0)) {
order = sc.order = 0;
goto loop_again;
}
zone_clear_flag(zone, ZONE_CONGESTED);
}
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
if (!sleeping_prematurely(pgdat, order, remaining, classzone_idx)) {
remaining = schedule_timeout(HZ/10);
finish_wait(&pgdat->kswapd_wait, &wait);
prepare_to_wait(&pgdat->kswapd_wait, &wait, TASK_INTERRUPTIBLE);
}
if (!sleeping_prematurely(pgdat, order, remaining, classzone_idx)) {
trace_mm_vmscan_kswapd_sleep(pgdat->node_id);
set_pgdat_percpu_threshold(pgdat, calculate_normal_threshold);
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
int classzone_idx, new_classzone_idx;
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
classzone_idx = new_classzone_idx = pgdat->nr_zones - 1;
for ( ; ; ) {
int ret;
if (classzone_idx >= new_classzone_idx && order == new_order) {
new_order = pgdat->kswapd_max_order;
new_classzone_idx = pgdat->classzone_idx;
pgdat->kswapd_max_order = 0;
pgdat->classzone_idx = pgdat->nr_zones - 1;
}
if (order < new_order || classzone_idx > new_classzone_idx) {
order = new_order;
classzone_idx = new_classzone_idx;
} else {
kswapd_try_to_sleep(pgdat, order, classzone_idx);
order = pgdat->kswapd_max_order;
classzone_idx = pgdat->classzone_idx;
pgdat->kswapd_max_order = 0;
pgdat->classzone_idx = pgdat->nr_zones - 1;
}
ret = try_to_freeze();
if (kthread_should_stop())
break;
if (!ret) {
trace_mm_vmscan_kswapd_wake(pgdat->node_id, order);
order = balance_pgdat(pgdat, order, &classzone_idx);
}
}
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
printk("Failed to start kswapd on node %d\n",nid);
ret = -1;
}
return ret;
}
void kswapd_stop(int nid)
{
struct task_struct *kswapd = NODE_DATA(nid)->kswapd;
if (kswapd)
kthread_stop(kswapd);
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
int priority;
struct scan_control sc = {
.may_writepage = !!(zone_reclaim_mode & RECLAIM_WRITE),
.may_unmap = !!(zone_reclaim_mode & RECLAIM_SWAP),
.may_swap = 1,
.nr_to_reclaim = max_t(unsigned long, nr_pages,
SWAP_CLUSTER_MAX),
.gfp_mask = gfp_mask,
.order = order,
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
priority = ZONE_RECLAIM_PRIORITY;
do {
shrink_zone(priority, zone, &sc);
priority--;
} while (priority >= 0 && sc.nr_reclaimed < nr_pages);
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
int page_evictable(struct page *page, struct vm_area_struct *vma)
{
if (mapping_unevictable(page_mapping(page)))
return 0;
if (PageMlocked(page) || (vma && is_mlocked_vma(vma, page)))
return 0;
return 1;
}
static void check_move_unevictable_page(struct page *page, struct zone *zone)
{
VM_BUG_ON(PageActive(page));
retry:
ClearPageUnevictable(page);
if (page_evictable(page, NULL)) {
enum lru_list l = page_lru_base_type(page);
__dec_zone_state(zone, NR_UNEVICTABLE);
list_move(&page->lru, &zone->lru[l].list);
mem_cgroup_move_lists(page, LRU_UNEVICTABLE, l);
__inc_zone_state(zone, NR_INACTIVE_ANON + l);
__count_vm_event(UNEVICTABLE_PGRESCUED);
} else {
SetPageUnevictable(page);
list_move(&page->lru, &zone->lru[LRU_UNEVICTABLE].list);
mem_cgroup_rotate_lru_list(page, LRU_UNEVICTABLE);
if (page_evictable(page, NULL))
goto retry;
}
}
void scan_mapping_unevictable_pages(struct address_space *mapping)
{
pgoff_t next = 0;
pgoff_t end = (i_size_read(mapping->host) + PAGE_CACHE_SIZE - 1) >>
PAGE_CACHE_SHIFT;
struct zone *zone;
struct pagevec pvec;
if (mapping->nrpages == 0)
return;
pagevec_init(&pvec, 0);
while (next < end &&
pagevec_lookup(&pvec, mapping, next, PAGEVEC_SIZE)) {
int i;
int pg_scanned = 0;
zone = NULL;
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
pgoff_t page_index = page->index;
struct zone *pagezone = page_zone(page);
pg_scanned++;
if (page_index > next)
next = page_index;
next++;
if (pagezone != zone) {
if (zone)
spin_unlock_irq(&zone->lru_lock);
zone = pagezone;
spin_lock_irq(&zone->lru_lock);
}
if (PageLRU(page) && PageUnevictable(page))
check_move_unevictable_page(page, zone);
}
if (zone)
spin_unlock_irq(&zone->lru_lock);
pagevec_release(&pvec);
count_vm_events(UNEVICTABLE_PGSCANNED, pg_scanned);
}
}
static void scan_zone_unevictable_pages(struct zone *zone)
{
struct list_head *l_unevictable = &zone->lru[LRU_UNEVICTABLE].list;
unsigned long scan;
unsigned long nr_to_scan = zone_page_state(zone, NR_UNEVICTABLE);
while (nr_to_scan > 0) {
unsigned long batch_size = min(nr_to_scan,
SCAN_UNEVICTABLE_BATCH_SIZE);
spin_lock_irq(&zone->lru_lock);
for (scan = 0; scan < batch_size; scan++) {
struct page *page = lru_to_page(l_unevictable);
if (!trylock_page(page))
continue;
prefetchw_prev_lru_page(page, l_unevictable, flags);
if (likely(PageLRU(page) && PageUnevictable(page)))
check_move_unevictable_page(page, zone);
unlock_page(page);
}
spin_unlock_irq(&zone->lru_lock);
nr_to_scan -= batch_size;
}
}
static void scan_all_zones_unevictable_pages(void)
{
struct zone *zone;
for_each_zone(zone) {
scan_zone_unevictable_pages(zone);
}
}
int scan_unevictable_handler(struct ctl_table *table, int write,
void __user *buffer,
size_t *length, loff_t *ppos)
{
proc_doulongvec_minmax(table, write, buffer, length, ppos);
if (write && *(unsigned long *)table->data)
scan_all_zones_unevictable_pages();
scan_unevictable_pages = 0;
return 0;
}
static ssize_t read_scan_unevictable_node(struct sys_device *dev,
struct sysdev_attribute *attr,
char *buf)
{
return sprintf(buf, "0\n");
}
static ssize_t write_scan_unevictable_node(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf, size_t count)
{
struct zone *node_zones = NODE_DATA(dev->id)->node_zones;
struct zone *zone;
unsigned long res;
unsigned long req = strict_strtoul(buf, 10, &res);
if (!req)
return 1;
for (zone = node_zones; zone - node_zones < MAX_NR_ZONES; ++zone) {
if (!populated_zone(zone))
continue;
scan_zone_unevictable_pages(zone);
}
return 1;
}
int scan_unevictable_register_node(struct node *node)
{
return sysdev_create_file(&node->sysdev, &attr_scan_unevictable_pages);
}
void scan_unevictable_unregister_node(struct node *node)
{
sysdev_remove_file(&node->sysdev, &attr_scan_unevictable_pages);
}
