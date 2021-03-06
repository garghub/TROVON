static inline int get_pcppage_migratetype(struct page *page)
{
return page->index;
}
static inline void set_pcppage_migratetype(struct page *page, int migratetype)
{
page->index = migratetype;
}
void pm_restore_gfp_mask(void)
{
WARN_ON(!mutex_is_locked(&pm_mutex));
if (saved_gfp_mask) {
gfp_allowed_mask = saved_gfp_mask;
saved_gfp_mask = 0;
}
}
void pm_restrict_gfp_mask(void)
{
WARN_ON(!mutex_is_locked(&pm_mutex));
WARN_ON(saved_gfp_mask);
saved_gfp_mask = gfp_allowed_mask;
gfp_allowed_mask &= ~(__GFP_IO | __GFP_FS);
}
bool pm_suspended_storage(void)
{
if ((gfp_allowed_mask & (__GFP_IO | __GFP_FS)) == (__GFP_IO | __GFP_FS))
return false;
return true;
}
static inline void reset_deferred_meminit(pg_data_t *pgdat)
{
pgdat->first_deferred_pfn = ULONG_MAX;
}
static inline bool __meminit early_page_uninitialised(unsigned long pfn)
{
int nid = early_pfn_to_nid(pfn);
if (node_online(nid) && pfn >= NODE_DATA(nid)->first_deferred_pfn)
return true;
return false;
}
static inline bool update_defer_init(pg_data_t *pgdat,
unsigned long pfn, unsigned long zone_end,
unsigned long *nr_initialised)
{
unsigned long max_initialise;
if (zone_end < pgdat_end_pfn(pgdat))
return true;
max_initialise = max(2UL << (30 - PAGE_SHIFT),
(pgdat->node_spanned_pages >> 8));
(*nr_initialised)++;
if ((*nr_initialised > max_initialise) &&
(pfn & (PAGES_PER_SECTION - 1)) == 0) {
pgdat->first_deferred_pfn = pfn;
return false;
}
return true;
}
static inline void reset_deferred_meminit(pg_data_t *pgdat)
{
}
static inline bool early_page_uninitialised(unsigned long pfn)
{
return false;
}
static inline bool update_defer_init(pg_data_t *pgdat,
unsigned long pfn, unsigned long zone_end,
unsigned long *nr_initialised)
{
return true;
}
static inline unsigned long *get_pageblock_bitmap(struct page *page,
unsigned long pfn)
{
#ifdef CONFIG_SPARSEMEM
return __pfn_to_section(pfn)->pageblock_flags;
#else
return page_zone(page)->pageblock_flags;
#endif
}
static inline int pfn_to_bitidx(struct page *page, unsigned long pfn)
{
#ifdef CONFIG_SPARSEMEM
pfn &= (PAGES_PER_SECTION-1);
return (pfn >> pageblock_order) * NR_PAGEBLOCK_BITS;
#else
pfn = pfn - round_down(page_zone(page)->zone_start_pfn, pageblock_nr_pages);
return (pfn >> pageblock_order) * NR_PAGEBLOCK_BITS;
#endif
}
static __always_inline unsigned long __get_pfnblock_flags_mask(struct page *page,
unsigned long pfn,
unsigned long end_bitidx,
unsigned long mask)
{
unsigned long *bitmap;
unsigned long bitidx, word_bitidx;
unsigned long word;
bitmap = get_pageblock_bitmap(page, pfn);
bitidx = pfn_to_bitidx(page, pfn);
word_bitidx = bitidx / BITS_PER_LONG;
bitidx &= (BITS_PER_LONG-1);
word = bitmap[word_bitidx];
bitidx += end_bitidx;
return (word >> (BITS_PER_LONG - bitidx - 1)) & mask;
}
unsigned long get_pfnblock_flags_mask(struct page *page, unsigned long pfn,
unsigned long end_bitidx,
unsigned long mask)
{
return __get_pfnblock_flags_mask(page, pfn, end_bitidx, mask);
}
static __always_inline int get_pfnblock_migratetype(struct page *page, unsigned long pfn)
{
return __get_pfnblock_flags_mask(page, pfn, PB_migrate_end, MIGRATETYPE_MASK);
}
void set_pfnblock_flags_mask(struct page *page, unsigned long flags,
unsigned long pfn,
unsigned long end_bitidx,
unsigned long mask)
{
unsigned long *bitmap;
unsigned long bitidx, word_bitidx;
unsigned long old_word, word;
BUILD_BUG_ON(NR_PAGEBLOCK_BITS != 4);
bitmap = get_pageblock_bitmap(page, pfn);
bitidx = pfn_to_bitidx(page, pfn);
word_bitidx = bitidx / BITS_PER_LONG;
bitidx &= (BITS_PER_LONG-1);
VM_BUG_ON_PAGE(!zone_spans_pfn(page_zone(page), pfn), page);
bitidx += end_bitidx;
mask <<= (BITS_PER_LONG - bitidx - 1);
flags <<= (BITS_PER_LONG - bitidx - 1);
word = READ_ONCE(bitmap[word_bitidx]);
for (;;) {
old_word = cmpxchg(&bitmap[word_bitidx], word, (word & ~mask) | flags);
if (word == old_word)
break;
word = old_word;
}
}
void set_pageblock_migratetype(struct page *page, int migratetype)
{
if (unlikely(page_group_by_mobility_disabled &&
migratetype < MIGRATE_PCPTYPES))
migratetype = MIGRATE_UNMOVABLE;
set_pageblock_flags_group(page, (unsigned long)migratetype,
PB_migrate, PB_migrate_end);
}
static int page_outside_zone_boundaries(struct zone *zone, struct page *page)
{
int ret = 0;
unsigned seq;
unsigned long pfn = page_to_pfn(page);
unsigned long sp, start_pfn;
do {
seq = zone_span_seqbegin(zone);
start_pfn = zone->zone_start_pfn;
sp = zone->spanned_pages;
if (!zone_spans_pfn(zone, pfn))
ret = 1;
} while (zone_span_seqretry(zone, seq));
if (ret)
pr_err("page 0x%lx outside node %d zone %s [ 0x%lx - 0x%lx ]\n",
pfn, zone_to_nid(zone), zone->name,
start_pfn, start_pfn + sp);
return ret;
}
static int page_is_consistent(struct zone *zone, struct page *page)
{
if (!pfn_valid_within(page_to_pfn(page)))
return 0;
if (zone != page_zone(page))
return 0;
return 1;
}
static int bad_range(struct zone *zone, struct page *page)
{
if (page_outside_zone_boundaries(zone, page))
return 1;
if (!page_is_consistent(zone, page))
return 1;
return 0;
}
static inline int bad_range(struct zone *zone, struct page *page)
{
return 0;
}
static void bad_page(struct page *page, const char *reason,
unsigned long bad_flags)
{
static unsigned long resume;
static unsigned long nr_shown;
static unsigned long nr_unshown;
if (nr_shown == 60) {
if (time_before(jiffies, resume)) {
nr_unshown++;
goto out;
}
if (nr_unshown) {
pr_alert(
"BUG: Bad page state: %lu messages suppressed\n",
nr_unshown);
nr_unshown = 0;
}
nr_shown = 0;
}
if (nr_shown++ == 0)
resume = jiffies + 60 * HZ;
pr_alert("BUG: Bad page state in process %s pfn:%05lx\n",
current->comm, page_to_pfn(page));
__dump_page(page, reason);
bad_flags &= page->flags;
if (bad_flags)
pr_alert("bad because of flags: %#lx(%pGp)\n",
bad_flags, &bad_flags);
dump_page_owner(page);
print_modules();
dump_stack();
out:
page_mapcount_reset(page);
add_taint(TAINT_BAD_PAGE, LOCKDEP_NOW_UNRELIABLE);
}
void free_compound_page(struct page *page)
{
__free_pages_ok(page, compound_order(page));
}
void prep_compound_page(struct page *page, unsigned int order)
{
int i;
int nr_pages = 1 << order;
set_compound_page_dtor(page, COMPOUND_PAGE_DTOR);
set_compound_order(page, order);
__SetPageHead(page);
for (i = 1; i < nr_pages; i++) {
struct page *p = page + i;
set_page_count(p, 0);
p->mapping = TAIL_MAPPING;
set_compound_head(p, page);
}
atomic_set(compound_mapcount_ptr(page), -1);
}
static int __init early_debug_pagealloc(char *buf)
{
if (!buf)
return -EINVAL;
return kstrtobool(buf, &_debug_pagealloc_enabled);
}
static bool need_debug_guardpage(void)
{
if (!debug_pagealloc_enabled())
return false;
if (!debug_guardpage_minorder())
return false;
return true;
}
static void init_debug_guardpage(void)
{
if (!debug_pagealloc_enabled())
return;
if (!debug_guardpage_minorder())
return;
_debug_guardpage_enabled = true;
}
static int __init debug_guardpage_minorder_setup(char *buf)
{
unsigned long res;
if (kstrtoul(buf, 10, &res) < 0 || res > MAX_ORDER / 2) {
pr_err("Bad debug_guardpage_minorder value\n");
return 0;
}
_debug_guardpage_minorder = res;
pr_info("Setting debug_guardpage_minorder to %lu\n", res);
return 0;
}
static inline bool set_page_guard(struct zone *zone, struct page *page,
unsigned int order, int migratetype)
{
struct page_ext *page_ext;
if (!debug_guardpage_enabled())
return false;
if (order >= debug_guardpage_minorder())
return false;
page_ext = lookup_page_ext(page);
if (unlikely(!page_ext))
return false;
__set_bit(PAGE_EXT_DEBUG_GUARD, &page_ext->flags);
INIT_LIST_HEAD(&page->lru);
set_page_private(page, order);
__mod_zone_freepage_state(zone, -(1 << order), migratetype);
return true;
}
static inline void clear_page_guard(struct zone *zone, struct page *page,
unsigned int order, int migratetype)
{
struct page_ext *page_ext;
if (!debug_guardpage_enabled())
return;
page_ext = lookup_page_ext(page);
if (unlikely(!page_ext))
return;
__clear_bit(PAGE_EXT_DEBUG_GUARD, &page_ext->flags);
set_page_private(page, 0);
if (!is_migrate_isolate(migratetype))
__mod_zone_freepage_state(zone, (1 << order), migratetype);
}
static inline bool set_page_guard(struct zone *zone, struct page *page,
unsigned int order, int migratetype) { return false; }
static inline void clear_page_guard(struct zone *zone, struct page *page,
unsigned int order, int migratetype) {}
static inline void set_page_order(struct page *page, unsigned int order)
{
set_page_private(page, order);
__SetPageBuddy(page);
}
static inline void rmv_page_order(struct page *page)
{
__ClearPageBuddy(page);
set_page_private(page, 0);
}
static inline int page_is_buddy(struct page *page, struct page *buddy,
unsigned int order)
{
if (!pfn_valid_within(page_to_pfn(buddy)))
return 0;
if (page_is_guard(buddy) && page_order(buddy) == order) {
if (page_zone_id(page) != page_zone_id(buddy))
return 0;
VM_BUG_ON_PAGE(page_count(buddy) != 0, buddy);
return 1;
}
if (PageBuddy(buddy) && page_order(buddy) == order) {
if (page_zone_id(page) != page_zone_id(buddy))
return 0;
VM_BUG_ON_PAGE(page_count(buddy) != 0, buddy);
return 1;
}
return 0;
}
static inline void __free_one_page(struct page *page,
unsigned long pfn,
struct zone *zone, unsigned int order,
int migratetype)
{
unsigned long page_idx;
unsigned long combined_idx;
unsigned long uninitialized_var(buddy_idx);
struct page *buddy;
unsigned int max_order;
max_order = min_t(unsigned int, MAX_ORDER, pageblock_order + 1);
VM_BUG_ON(!zone_is_initialized(zone));
VM_BUG_ON_PAGE(page->flags & PAGE_FLAGS_CHECK_AT_PREP, page);
VM_BUG_ON(migratetype == -1);
if (likely(!is_migrate_isolate(migratetype)))
__mod_zone_freepage_state(zone, 1 << order, migratetype);
page_idx = pfn & ((1 << MAX_ORDER) - 1);
VM_BUG_ON_PAGE(page_idx & ((1 << order) - 1), page);
VM_BUG_ON_PAGE(bad_range(zone, page), page);
continue_merging:
while (order < max_order - 1) {
buddy_idx = __find_buddy_index(page_idx, order);
buddy = page + (buddy_idx - page_idx);
if (!page_is_buddy(page, buddy, order))
goto done_merging;
if (page_is_guard(buddy)) {
clear_page_guard(zone, buddy, order, migratetype);
} else {
list_del(&buddy->lru);
zone->free_area[order].nr_free--;
rmv_page_order(buddy);
}
combined_idx = buddy_idx & page_idx;
page = page + (combined_idx - page_idx);
page_idx = combined_idx;
order++;
}
if (max_order < MAX_ORDER) {
if (unlikely(has_isolate_pageblock(zone))) {
int buddy_mt;
buddy_idx = __find_buddy_index(page_idx, order);
buddy = page + (buddy_idx - page_idx);
buddy_mt = get_pageblock_migratetype(buddy);
if (migratetype != buddy_mt
&& (is_migrate_isolate(migratetype) ||
is_migrate_isolate(buddy_mt)))
goto done_merging;
}
max_order++;
goto continue_merging;
}
done_merging:
set_page_order(page, order);
if ((order < MAX_ORDER-2) && pfn_valid_within(page_to_pfn(buddy))) {
struct page *higher_page, *higher_buddy;
combined_idx = buddy_idx & page_idx;
higher_page = page + (combined_idx - page_idx);
buddy_idx = __find_buddy_index(combined_idx, order + 1);
higher_buddy = higher_page + (buddy_idx - combined_idx);
if (page_is_buddy(higher_page, higher_buddy, order + 1)) {
list_add_tail(&page->lru,
&zone->free_area[order].free_list[migratetype]);
goto out;
}
}
list_add(&page->lru, &zone->free_area[order].free_list[migratetype]);
out:
zone->free_area[order].nr_free++;
}
static inline bool page_expected_state(struct page *page,
unsigned long check_flags)
{
if (unlikely(atomic_read(&page->_mapcount) != -1))
return false;
if (unlikely((unsigned long)page->mapping |
page_ref_count(page) |
#ifdef CONFIG_MEMCG
(unsigned long)page->mem_cgroup |
#endif
(page->flags & check_flags)))
return false;
return true;
}
static void free_pages_check_bad(struct page *page)
{
const char *bad_reason;
unsigned long bad_flags;
bad_reason = NULL;
bad_flags = 0;
if (unlikely(atomic_read(&page->_mapcount) != -1))
bad_reason = "nonzero mapcount";
if (unlikely(page->mapping != NULL))
bad_reason = "non-NULL mapping";
if (unlikely(page_ref_count(page) != 0))
bad_reason = "nonzero _refcount";
if (unlikely(page->flags & PAGE_FLAGS_CHECK_AT_FREE)) {
bad_reason = "PAGE_FLAGS_CHECK_AT_FREE flag(s) set";
bad_flags = PAGE_FLAGS_CHECK_AT_FREE;
}
#ifdef CONFIG_MEMCG
if (unlikely(page->mem_cgroup))
bad_reason = "page still charged to cgroup";
#endif
bad_page(page, bad_reason, bad_flags);
}
static inline int free_pages_check(struct page *page)
{
if (likely(page_expected_state(page, PAGE_FLAGS_CHECK_AT_FREE)))
return 0;
free_pages_check_bad(page);
return 1;
}
static int free_tail_pages_check(struct page *head_page, struct page *page)
{
int ret = 1;
BUILD_BUG_ON((unsigned long)LIST_POISON1 & 1);
if (!IS_ENABLED(CONFIG_DEBUG_VM)) {
ret = 0;
goto out;
}
switch (page - head_page) {
case 1:
if (unlikely(compound_mapcount(page))) {
bad_page(page, "nonzero compound_mapcount", 0);
goto out;
}
break;
case 2:
break;
default:
if (page->mapping != TAIL_MAPPING) {
bad_page(page, "corrupted mapping in tail page", 0);
goto out;
}
break;
}
if (unlikely(!PageTail(page))) {
bad_page(page, "PageTail not set", 0);
goto out;
}
if (unlikely(compound_head(page) != head_page)) {
bad_page(page, "compound_head not consistent", 0);
goto out;
}
ret = 0;
out:
page->mapping = NULL;
clear_compound_head(page);
return ret;
}
static __always_inline bool free_pages_prepare(struct page *page,
unsigned int order, bool check_free)
{
int bad = 0;
VM_BUG_ON_PAGE(PageTail(page), page);
trace_mm_page_free(page, order);
kmemcheck_free_shadow(page, order);
if (unlikely(order)) {
bool compound = PageCompound(page);
int i;
VM_BUG_ON_PAGE(compound && compound_order(page) != order, page);
if (compound)
ClearPageDoubleMap(page);
for (i = 1; i < (1 << order); i++) {
if (compound)
bad += free_tail_pages_check(page, page + i);
if (unlikely(free_pages_check(page + i))) {
bad++;
continue;
}
(page + i)->flags &= ~PAGE_FLAGS_CHECK_AT_PREP;
}
}
if (PageMappingFlags(page))
page->mapping = NULL;
if (memcg_kmem_enabled() && PageKmemcg(page))
memcg_kmem_uncharge(page, order);
if (check_free)
bad += free_pages_check(page);
if (bad)
return false;
page_cpupid_reset_last(page);
page->flags &= ~PAGE_FLAGS_CHECK_AT_PREP;
reset_page_owner(page, order);
if (!PageHighMem(page)) {
debug_check_no_locks_freed(page_address(page),
PAGE_SIZE << order);
debug_check_no_obj_freed(page_address(page),
PAGE_SIZE << order);
}
arch_free_page(page, order);
kernel_poison_pages(page, 1 << order, 0);
kernel_map_pages(page, 1 << order, 0);
kasan_free_pages(page, order);
return true;
}
static inline bool free_pcp_prepare(struct page *page)
{
return free_pages_prepare(page, 0, true);
}
static inline bool bulkfree_pcp_prepare(struct page *page)
{
return false;
}
static bool free_pcp_prepare(struct page *page)
{
return free_pages_prepare(page, 0, false);
}
static bool bulkfree_pcp_prepare(struct page *page)
{
return free_pages_check(page);
}
static void free_pcppages_bulk(struct zone *zone, int count,
struct per_cpu_pages *pcp)
{
int migratetype = 0;
int batch_free = 0;
unsigned long nr_scanned;
bool isolated_pageblocks;
spin_lock(&zone->lock);
isolated_pageblocks = has_isolate_pageblock(zone);
nr_scanned = node_page_state(zone->zone_pgdat, NR_PAGES_SCANNED);
if (nr_scanned)
__mod_node_page_state(zone->zone_pgdat, NR_PAGES_SCANNED, -nr_scanned);
while (count) {
struct page *page;
struct list_head *list;
do {
batch_free++;
if (++migratetype == MIGRATE_PCPTYPES)
migratetype = 0;
list = &pcp->lists[migratetype];
} while (list_empty(list));
if (batch_free == MIGRATE_PCPTYPES)
batch_free = count;
do {
int mt;
page = list_last_entry(list, struct page, lru);
list_del(&page->lru);
mt = get_pcppage_migratetype(page);
VM_BUG_ON_PAGE(is_migrate_isolate(mt), page);
if (unlikely(isolated_pageblocks))
mt = get_pageblock_migratetype(page);
if (bulkfree_pcp_prepare(page))
continue;
__free_one_page(page, page_to_pfn(page), zone, 0, mt);
trace_mm_page_pcpu_drain(page, 0, mt);
} while (--count && --batch_free && !list_empty(list));
}
spin_unlock(&zone->lock);
}
static void free_one_page(struct zone *zone,
struct page *page, unsigned long pfn,
unsigned int order,
int migratetype)
{
unsigned long nr_scanned;
spin_lock(&zone->lock);
nr_scanned = node_page_state(zone->zone_pgdat, NR_PAGES_SCANNED);
if (nr_scanned)
__mod_node_page_state(zone->zone_pgdat, NR_PAGES_SCANNED, -nr_scanned);
if (unlikely(has_isolate_pageblock(zone) ||
is_migrate_isolate(migratetype))) {
migratetype = get_pfnblock_migratetype(page, pfn);
}
__free_one_page(page, pfn, zone, order, migratetype);
spin_unlock(&zone->lock);
}
static void __meminit __init_single_page(struct page *page, unsigned long pfn,
unsigned long zone, int nid)
{
set_page_links(page, zone, nid, pfn);
init_page_count(page);
page_mapcount_reset(page);
page_cpupid_reset_last(page);
INIT_LIST_HEAD(&page->lru);
#ifdef WANT_PAGE_VIRTUAL
if (!is_highmem_idx(zone))
set_page_address(page, __va(pfn << PAGE_SHIFT));
#endif
}
static void __meminit __init_single_pfn(unsigned long pfn, unsigned long zone,
int nid)
{
return __init_single_page(pfn_to_page(pfn), pfn, zone, nid);
}
static void init_reserved_page(unsigned long pfn)
{
pg_data_t *pgdat;
int nid, zid;
if (!early_page_uninitialised(pfn))
return;
nid = early_pfn_to_nid(pfn);
pgdat = NODE_DATA(nid);
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
struct zone *zone = &pgdat->node_zones[zid];
if (pfn >= zone->zone_start_pfn && pfn < zone_end_pfn(zone))
break;
}
__init_single_pfn(pfn, zid, nid);
}
static inline void init_reserved_page(unsigned long pfn)
{
}
void __meminit reserve_bootmem_region(phys_addr_t start, phys_addr_t end)
{
unsigned long start_pfn = PFN_DOWN(start);
unsigned long end_pfn = PFN_UP(end);
for (; start_pfn < end_pfn; start_pfn++) {
if (pfn_valid(start_pfn)) {
struct page *page = pfn_to_page(start_pfn);
init_reserved_page(start_pfn);
INIT_LIST_HEAD(&page->lru);
SetPageReserved(page);
}
}
}
static void __free_pages_ok(struct page *page, unsigned int order)
{
unsigned long flags;
int migratetype;
unsigned long pfn = page_to_pfn(page);
if (!free_pages_prepare(page, order, true))
return;
migratetype = get_pfnblock_migratetype(page, pfn);
local_irq_save(flags);
__count_vm_events(PGFREE, 1 << order);
free_one_page(page_zone(page), page, pfn, order, migratetype);
local_irq_restore(flags);
}
static void __init __free_pages_boot_core(struct page *page, unsigned int order)
{
unsigned int nr_pages = 1 << order;
struct page *p = page;
unsigned int loop;
prefetchw(p);
for (loop = 0; loop < (nr_pages - 1); loop++, p++) {
prefetchw(p + 1);
__ClearPageReserved(p);
set_page_count(p, 0);
}
__ClearPageReserved(p);
set_page_count(p, 0);
page_zone(page)->managed_pages += nr_pages;
set_page_refcounted(page);
__free_pages(page, order);
}
int __meminit early_pfn_to_nid(unsigned long pfn)
{
static DEFINE_SPINLOCK(early_pfn_lock);
int nid;
spin_lock(&early_pfn_lock);
nid = __early_pfn_to_nid(pfn, &early_pfnnid_cache);
if (nid < 0)
nid = first_online_node;
spin_unlock(&early_pfn_lock);
return nid;
}
static inline bool __meminit meminit_pfn_in_nid(unsigned long pfn, int node,
struct mminit_pfnnid_cache *state)
{
int nid;
nid = __early_pfn_to_nid(pfn, state);
if (nid >= 0 && nid != node)
return false;
return true;
}
static inline bool __meminit early_pfn_in_nid(unsigned long pfn, int node)
{
return meminit_pfn_in_nid(pfn, node, &early_pfnnid_cache);
}
static inline bool __meminit early_pfn_in_nid(unsigned long pfn, int node)
{
return true;
}
static inline bool __meminit meminit_pfn_in_nid(unsigned long pfn, int node,
struct mminit_pfnnid_cache *state)
{
return true;
}
void __init __free_pages_bootmem(struct page *page, unsigned long pfn,
unsigned int order)
{
if (early_page_uninitialised(pfn))
return;
return __free_pages_boot_core(page, order);
}
struct page *__pageblock_pfn_to_page(unsigned long start_pfn,
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
void set_zone_contiguous(struct zone *zone)
{
unsigned long block_start_pfn = zone->zone_start_pfn;
unsigned long block_end_pfn;
block_end_pfn = ALIGN(block_start_pfn + 1, pageblock_nr_pages);
for (; block_start_pfn < zone_end_pfn(zone);
block_start_pfn = block_end_pfn,
block_end_pfn += pageblock_nr_pages) {
block_end_pfn = min(block_end_pfn, zone_end_pfn(zone));
if (!__pageblock_pfn_to_page(block_start_pfn,
block_end_pfn, zone))
return;
}
zone->contiguous = true;
}
void clear_zone_contiguous(struct zone *zone)
{
zone->contiguous = false;
}
static void __init deferred_free_range(struct page *page,
unsigned long pfn, int nr_pages)
{
int i;
if (!page)
return;
if (nr_pages == pageblock_nr_pages &&
(pfn & (pageblock_nr_pages - 1)) == 0) {
set_pageblock_migratetype(page, MIGRATE_MOVABLE);
__free_pages_boot_core(page, pageblock_order);
return;
}
for (i = 0; i < nr_pages; i++, page++, pfn++) {
if ((pfn & (pageblock_nr_pages - 1)) == 0)
set_pageblock_migratetype(page, MIGRATE_MOVABLE);
__free_pages_boot_core(page, 0);
}
}
static inline void __init pgdat_init_report_one_done(void)
{
if (atomic_dec_and_test(&pgdat_init_n_undone))
complete(&pgdat_init_all_done_comp);
}
static int __init deferred_init_memmap(void *data)
{
pg_data_t *pgdat = data;
int nid = pgdat->node_id;
struct mminit_pfnnid_cache nid_init_state = { };
unsigned long start = jiffies;
unsigned long nr_pages = 0;
unsigned long walk_start, walk_end;
int i, zid;
struct zone *zone;
unsigned long first_init_pfn = pgdat->first_deferred_pfn;
const struct cpumask *cpumask = cpumask_of_node(pgdat->node_id);
if (first_init_pfn == ULONG_MAX) {
pgdat_init_report_one_done();
return 0;
}
if (!cpumask_empty(cpumask))
set_cpus_allowed_ptr(current, cpumask);
BUG_ON(pgdat->first_deferred_pfn < pgdat->node_start_pfn);
BUG_ON(pgdat->first_deferred_pfn > pgdat_end_pfn(pgdat));
pgdat->first_deferred_pfn = ULONG_MAX;
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
zone = pgdat->node_zones + zid;
if (first_init_pfn < zone_end_pfn(zone))
break;
}
for_each_mem_pfn_range(i, nid, &walk_start, &walk_end, NULL) {
unsigned long pfn, end_pfn;
struct page *page = NULL;
struct page *free_base_page = NULL;
unsigned long free_base_pfn = 0;
int nr_to_free = 0;
end_pfn = min(walk_end, zone_end_pfn(zone));
pfn = first_init_pfn;
if (pfn < walk_start)
pfn = walk_start;
if (pfn < zone->zone_start_pfn)
pfn = zone->zone_start_pfn;
for (; pfn < end_pfn; pfn++) {
if (!pfn_valid_within(pfn))
goto free_range;
if ((pfn & (pageblock_nr_pages - 1)) == 0) {
if (!pfn_valid(pfn)) {
page = NULL;
goto free_range;
}
}
if (!meminit_pfn_in_nid(pfn, nid, &nid_init_state)) {
page = NULL;
goto free_range;
}
if (page && (pfn & (pageblock_nr_pages - 1)) != 0) {
page++;
} else {
nr_pages += nr_to_free;
deferred_free_range(free_base_page,
free_base_pfn, nr_to_free);
free_base_page = NULL;
free_base_pfn = nr_to_free = 0;
page = pfn_to_page(pfn);
cond_resched();
}
if (page->flags) {
VM_BUG_ON(page_zone(page) != zone);
goto free_range;
}
__init_single_page(page, pfn, zid, nid);
if (!free_base_page) {
free_base_page = page;
free_base_pfn = pfn;
nr_to_free = 0;
}
nr_to_free++;
continue;
free_range:
nr_pages += nr_to_free;
deferred_free_range(free_base_page, free_base_pfn,
nr_to_free);
free_base_page = NULL;
free_base_pfn = nr_to_free = 0;
}
nr_pages += nr_to_free;
deferred_free_range(free_base_page, free_base_pfn, nr_to_free);
first_init_pfn = max(end_pfn, first_init_pfn);
}
WARN_ON(++zid < MAX_NR_ZONES && populated_zone(++zone));
pr_info("node %d initialised, %lu pages in %ums\n", nid, nr_pages,
jiffies_to_msecs(jiffies - start));
pgdat_init_report_one_done();
return 0;
}
void __init page_alloc_init_late(void)
{
struct zone *zone;
#ifdef CONFIG_DEFERRED_STRUCT_PAGE_INIT
int nid;
atomic_set(&pgdat_init_n_undone, num_node_state(N_MEMORY));
for_each_node_state(nid, N_MEMORY) {
kthread_run(deferred_init_memmap, NODE_DATA(nid), "pgdatinit%d", nid);
}
wait_for_completion(&pgdat_init_all_done_comp);
files_maxfiles_init();
#endif
for_each_populated_zone(zone)
set_zone_contiguous(zone);
}
void __init init_cma_reserved_pageblock(struct page *page)
{
unsigned i = pageblock_nr_pages;
struct page *p = page;
do {
__ClearPageReserved(p);
set_page_count(p, 0);
} while (++p, --i);
set_pageblock_migratetype(page, MIGRATE_CMA);
if (pageblock_order >= MAX_ORDER) {
i = pageblock_nr_pages;
p = page;
do {
set_page_refcounted(p);
__free_pages(p, MAX_ORDER - 1);
p += MAX_ORDER_NR_PAGES;
} while (i -= MAX_ORDER_NR_PAGES);
} else {
set_page_refcounted(page);
__free_pages(page, pageblock_order);
}
adjust_managed_page_count(page, pageblock_nr_pages);
}
static inline void expand(struct zone *zone, struct page *page,
int low, int high, struct free_area *area,
int migratetype)
{
unsigned long size = 1 << high;
while (high > low) {
area--;
high--;
size >>= 1;
VM_BUG_ON_PAGE(bad_range(zone, &page[size]), &page[size]);
if (set_page_guard(zone, &page[size], high, migratetype))
continue;
list_add(&page[size].lru, &area->free_list[migratetype]);
area->nr_free++;
set_page_order(&page[size], high);
}
}
static void check_new_page_bad(struct page *page)
{
const char *bad_reason = NULL;
unsigned long bad_flags = 0;
if (unlikely(atomic_read(&page->_mapcount) != -1))
bad_reason = "nonzero mapcount";
if (unlikely(page->mapping != NULL))
bad_reason = "non-NULL mapping";
if (unlikely(page_ref_count(page) != 0))
bad_reason = "nonzero _count";
if (unlikely(page->flags & __PG_HWPOISON)) {
bad_reason = "HWPoisoned (hardware-corrupted)";
bad_flags = __PG_HWPOISON;
page_mapcount_reset(page);
return;
}
if (unlikely(page->flags & PAGE_FLAGS_CHECK_AT_PREP)) {
bad_reason = "PAGE_FLAGS_CHECK_AT_PREP flag set";
bad_flags = PAGE_FLAGS_CHECK_AT_PREP;
}
#ifdef CONFIG_MEMCG
if (unlikely(page->mem_cgroup))
bad_reason = "page still charged to cgroup";
#endif
bad_page(page, bad_reason, bad_flags);
}
static inline int check_new_page(struct page *page)
{
if (likely(page_expected_state(page,
PAGE_FLAGS_CHECK_AT_PREP|__PG_HWPOISON)))
return 0;
check_new_page_bad(page);
return 1;
}
static inline bool free_pages_prezeroed(bool poisoned)
{
return IS_ENABLED(CONFIG_PAGE_POISONING_ZERO) &&
page_poisoning_enabled() && poisoned;
}
static bool check_pcp_refill(struct page *page)
{
return false;
}
static bool check_new_pcp(struct page *page)
{
return check_new_page(page);
}
static bool check_pcp_refill(struct page *page)
{
return check_new_page(page);
}
static bool check_new_pcp(struct page *page)
{
return false;
}
static bool check_new_pages(struct page *page, unsigned int order)
{
int i;
for (i = 0; i < (1 << order); i++) {
struct page *p = page + i;
if (unlikely(check_new_page(p)))
return true;
}
return false;
}
inline void post_alloc_hook(struct page *page, unsigned int order,
gfp_t gfp_flags)
{
set_page_private(page, 0);
set_page_refcounted(page);
arch_alloc_page(page, order);
kernel_map_pages(page, 1 << order, 1);
kernel_poison_pages(page, 1 << order, 1);
kasan_alloc_pages(page, order);
set_page_owner(page, order, gfp_flags);
}
static void prep_new_page(struct page *page, unsigned int order, gfp_t gfp_flags,
unsigned int alloc_flags)
{
int i;
bool poisoned = true;
for (i = 0; i < (1 << order); i++) {
struct page *p = page + i;
if (poisoned)
poisoned &= page_is_poisoned(p);
}
post_alloc_hook(page, order, gfp_flags);
if (!free_pages_prezeroed(poisoned) && (gfp_flags & __GFP_ZERO))
for (i = 0; i < (1 << order); i++)
clear_highpage(page + i);
if (order && (gfp_flags & __GFP_COMP))
prep_compound_page(page, order);
if (alloc_flags & ALLOC_NO_WATERMARKS)
set_page_pfmemalloc(page);
else
clear_page_pfmemalloc(page);
}
static inline
struct page *__rmqueue_smallest(struct zone *zone, unsigned int order,
int migratetype)
{
unsigned int current_order;
struct free_area *area;
struct page *page;
for (current_order = order; current_order < MAX_ORDER; ++current_order) {
area = &(zone->free_area[current_order]);
page = list_first_entry_or_null(&area->free_list[migratetype],
struct page, lru);
if (!page)
continue;
list_del(&page->lru);
rmv_page_order(page);
area->nr_free--;
expand(zone, page, order, current_order, area, migratetype);
set_pcppage_migratetype(page, migratetype);
return page;
}
return NULL;
}
static struct page *__rmqueue_cma_fallback(struct zone *zone,
unsigned int order)
{
return __rmqueue_smallest(zone, order, MIGRATE_CMA);
}
static inline struct page *__rmqueue_cma_fallback(struct zone *zone,
unsigned int order) { return NULL; }
int move_freepages(struct zone *zone,
struct page *start_page, struct page *end_page,
int migratetype)
{
struct page *page;
unsigned int order;
int pages_moved = 0;
#ifndef CONFIG_HOLES_IN_ZONE
VM_BUG_ON(page_zone(start_page) != page_zone(end_page));
#endif
for (page = start_page; page <= end_page;) {
if (!pfn_valid_within(page_to_pfn(page))) {
page++;
continue;
}
VM_BUG_ON_PAGE(page_to_nid(page) != zone_to_nid(zone), page);
if (!PageBuddy(page)) {
page++;
continue;
}
order = page_order(page);
list_move(&page->lru,
&zone->free_area[order].free_list[migratetype]);
page += 1 << order;
pages_moved += 1 << order;
}
return pages_moved;
}
int move_freepages_block(struct zone *zone, struct page *page,
int migratetype)
{
unsigned long start_pfn, end_pfn;
struct page *start_page, *end_page;
start_pfn = page_to_pfn(page);
start_pfn = start_pfn & ~(pageblock_nr_pages-1);
start_page = pfn_to_page(start_pfn);
end_page = start_page + pageblock_nr_pages - 1;
end_pfn = start_pfn + pageblock_nr_pages - 1;
if (!zone_spans_pfn(zone, start_pfn))
start_page = page;
if (!zone_spans_pfn(zone, end_pfn))
return 0;
return move_freepages(zone, start_page, end_page, migratetype);
}
static void change_pageblock_range(struct page *pageblock_page,
int start_order, int migratetype)
{
int nr_pageblocks = 1 << (start_order - pageblock_order);
while (nr_pageblocks--) {
set_pageblock_migratetype(pageblock_page, migratetype);
pageblock_page += pageblock_nr_pages;
}
}
static bool can_steal_fallback(unsigned int order, int start_mt)
{
if (order >= pageblock_order)
return true;
if (order >= pageblock_order / 2 ||
start_mt == MIGRATE_RECLAIMABLE ||
start_mt == MIGRATE_UNMOVABLE ||
page_group_by_mobility_disabled)
return true;
return false;
}
static void steal_suitable_fallback(struct zone *zone, struct page *page,
int start_type)
{
unsigned int current_order = page_order(page);
int pages;
if (current_order >= pageblock_order) {
change_pageblock_range(page, current_order, start_type);
return;
}
pages = move_freepages_block(zone, page, start_type);
if (pages >= (1 << (pageblock_order-1)) ||
page_group_by_mobility_disabled)
set_pageblock_migratetype(page, start_type);
}
int find_suitable_fallback(struct free_area *area, unsigned int order,
int migratetype, bool only_stealable, bool *can_steal)
{
int i;
int fallback_mt;
if (area->nr_free == 0)
return -1;
*can_steal = false;
for (i = 0;; i++) {
fallback_mt = fallbacks[migratetype][i];
if (fallback_mt == MIGRATE_TYPES)
break;
if (list_empty(&area->free_list[fallback_mt]))
continue;
if (can_steal_fallback(order, migratetype))
*can_steal = true;
if (!only_stealable)
return fallback_mt;
if (*can_steal)
return fallback_mt;
}
return -1;
}
static void reserve_highatomic_pageblock(struct page *page, struct zone *zone,
unsigned int alloc_order)
{
int mt;
unsigned long max_managed, flags;
max_managed = (zone->managed_pages / 100) + pageblock_nr_pages;
if (zone->nr_reserved_highatomic >= max_managed)
return;
spin_lock_irqsave(&zone->lock, flags);
if (zone->nr_reserved_highatomic >= max_managed)
goto out_unlock;
mt = get_pageblock_migratetype(page);
if (mt != MIGRATE_HIGHATOMIC &&
!is_migrate_isolate(mt) && !is_migrate_cma(mt)) {
zone->nr_reserved_highatomic += pageblock_nr_pages;
set_pageblock_migratetype(page, MIGRATE_HIGHATOMIC);
move_freepages_block(zone, page, MIGRATE_HIGHATOMIC);
}
out_unlock:
spin_unlock_irqrestore(&zone->lock, flags);
}
static bool unreserve_highatomic_pageblock(const struct alloc_context *ac,
bool force)
{
struct zonelist *zonelist = ac->zonelist;
unsigned long flags;
struct zoneref *z;
struct zone *zone;
struct page *page;
int order;
bool ret;
for_each_zone_zonelist_nodemask(zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if (!force && zone->nr_reserved_highatomic <=
pageblock_nr_pages)
continue;
spin_lock_irqsave(&zone->lock, flags);
for (order = 0; order < MAX_ORDER; order++) {
struct free_area *area = &(zone->free_area[order]);
page = list_first_entry_or_null(
&area->free_list[MIGRATE_HIGHATOMIC],
struct page, lru);
if (!page)
continue;
if (get_pageblock_migratetype(page) ==
MIGRATE_HIGHATOMIC) {
zone->nr_reserved_highatomic -= min(
pageblock_nr_pages,
zone->nr_reserved_highatomic);
}
set_pageblock_migratetype(page, ac->migratetype);
ret = move_freepages_block(zone, page, ac->migratetype);
if (ret) {
spin_unlock_irqrestore(&zone->lock, flags);
return ret;
}
}
spin_unlock_irqrestore(&zone->lock, flags);
}
return false;
}
static inline struct page *
__rmqueue_fallback(struct zone *zone, unsigned int order, int start_migratetype)
{
struct free_area *area;
unsigned int current_order;
struct page *page;
int fallback_mt;
bool can_steal;
for (current_order = MAX_ORDER-1;
current_order >= order && current_order <= MAX_ORDER-1;
--current_order) {
area = &(zone->free_area[current_order]);
fallback_mt = find_suitable_fallback(area, current_order,
start_migratetype, false, &can_steal);
if (fallback_mt == -1)
continue;
page = list_first_entry(&area->free_list[fallback_mt],
struct page, lru);
if (can_steal &&
get_pageblock_migratetype(page) != MIGRATE_HIGHATOMIC)
steal_suitable_fallback(zone, page, start_migratetype);
area->nr_free--;
list_del(&page->lru);
rmv_page_order(page);
expand(zone, page, order, current_order, area,
start_migratetype);
set_pcppage_migratetype(page, start_migratetype);
trace_mm_page_alloc_extfrag(page, order, current_order,
start_migratetype, fallback_mt);
return page;
}
return NULL;
}
static struct page *__rmqueue(struct zone *zone, unsigned int order,
int migratetype)
{
struct page *page;
page = __rmqueue_smallest(zone, order, migratetype);
if (unlikely(!page)) {
if (migratetype == MIGRATE_MOVABLE)
page = __rmqueue_cma_fallback(zone, order);
if (!page)
page = __rmqueue_fallback(zone, order, migratetype);
}
trace_mm_page_alloc_zone_locked(page, order, migratetype);
return page;
}
static int rmqueue_bulk(struct zone *zone, unsigned int order,
unsigned long count, struct list_head *list,
int migratetype, bool cold)
{
int i, alloced = 0;
spin_lock(&zone->lock);
for (i = 0; i < count; ++i) {
struct page *page = __rmqueue(zone, order, migratetype);
if (unlikely(page == NULL))
break;
if (unlikely(check_pcp_refill(page)))
continue;
if (likely(!cold))
list_add(&page->lru, list);
else
list_add_tail(&page->lru, list);
list = &page->lru;
alloced++;
if (is_migrate_cma(get_pcppage_migratetype(page)))
__mod_zone_page_state(zone, NR_FREE_CMA_PAGES,
-(1 << order));
}
__mod_zone_page_state(zone, NR_FREE_PAGES, -(i << order));
spin_unlock(&zone->lock);
return alloced;
}
void drain_zone_pages(struct zone *zone, struct per_cpu_pages *pcp)
{
unsigned long flags;
int to_drain, batch;
local_irq_save(flags);
batch = READ_ONCE(pcp->batch);
to_drain = min(pcp->count, batch);
if (to_drain > 0) {
free_pcppages_bulk(zone, to_drain, pcp);
pcp->count -= to_drain;
}
local_irq_restore(flags);
}
static void drain_pages_zone(unsigned int cpu, struct zone *zone)
{
unsigned long flags;
struct per_cpu_pageset *pset;
struct per_cpu_pages *pcp;
local_irq_save(flags);
pset = per_cpu_ptr(zone->pageset, cpu);
pcp = &pset->pcp;
if (pcp->count) {
free_pcppages_bulk(zone, pcp->count, pcp);
pcp->count = 0;
}
local_irq_restore(flags);
}
static void drain_pages(unsigned int cpu)
{
struct zone *zone;
for_each_populated_zone(zone) {
drain_pages_zone(cpu, zone);
}
}
void drain_local_pages(struct zone *zone)
{
int cpu = smp_processor_id();
if (zone)
drain_pages_zone(cpu, zone);
else
drain_pages(cpu);
}
void drain_all_pages(struct zone *zone)
{
int cpu;
static cpumask_t cpus_with_pcps;
for_each_online_cpu(cpu) {
struct per_cpu_pageset *pcp;
struct zone *z;
bool has_pcps = false;
if (zone) {
pcp = per_cpu_ptr(zone->pageset, cpu);
if (pcp->pcp.count)
has_pcps = true;
} else {
for_each_populated_zone(z) {
pcp = per_cpu_ptr(z->pageset, cpu);
if (pcp->pcp.count) {
has_pcps = true;
break;
}
}
}
if (has_pcps)
cpumask_set_cpu(cpu, &cpus_with_pcps);
else
cpumask_clear_cpu(cpu, &cpus_with_pcps);
}
on_each_cpu_mask(&cpus_with_pcps, (smp_call_func_t) drain_local_pages,
zone, 1);
}
void mark_free_pages(struct zone *zone)
{
unsigned long pfn, max_zone_pfn;
unsigned long flags;
unsigned int order, t;
struct page *page;
if (zone_is_empty(zone))
return;
spin_lock_irqsave(&zone->lock, flags);
max_zone_pfn = zone_end_pfn(zone);
for (pfn = zone->zone_start_pfn; pfn < max_zone_pfn; pfn++)
if (pfn_valid(pfn)) {
page = pfn_to_page(pfn);
if (page_zone(page) != zone)
continue;
if (!swsusp_page_is_forbidden(page))
swsusp_unset_page_free(page);
}
for_each_migratetype_order(order, t) {
list_for_each_entry(page,
&zone->free_area[order].free_list[t], lru) {
unsigned long i;
pfn = page_to_pfn(page);
for (i = 0; i < (1UL << order); i++)
swsusp_set_page_free(pfn_to_page(pfn + i));
}
}
spin_unlock_irqrestore(&zone->lock, flags);
}
void free_hot_cold_page(struct page *page, bool cold)
{
struct zone *zone = page_zone(page);
struct per_cpu_pages *pcp;
unsigned long flags;
unsigned long pfn = page_to_pfn(page);
int migratetype;
if (!free_pcp_prepare(page))
return;
migratetype = get_pfnblock_migratetype(page, pfn);
set_pcppage_migratetype(page, migratetype);
local_irq_save(flags);
__count_vm_event(PGFREE);
if (migratetype >= MIGRATE_PCPTYPES) {
if (unlikely(is_migrate_isolate(migratetype))) {
free_one_page(zone, page, pfn, 0, migratetype);
goto out;
}
migratetype = MIGRATE_MOVABLE;
}
pcp = &this_cpu_ptr(zone->pageset)->pcp;
if (!cold)
list_add(&page->lru, &pcp->lists[migratetype]);
else
list_add_tail(&page->lru, &pcp->lists[migratetype]);
pcp->count++;
if (pcp->count >= pcp->high) {
unsigned long batch = READ_ONCE(pcp->batch);
free_pcppages_bulk(zone, batch, pcp);
pcp->count -= batch;
}
out:
local_irq_restore(flags);
}
void free_hot_cold_page_list(struct list_head *list, bool cold)
{
struct page *page, *next;
list_for_each_entry_safe(page, next, list, lru) {
trace_mm_page_free_batched(page, cold);
free_hot_cold_page(page, cold);
}
}
void split_page(struct page *page, unsigned int order)
{
int i;
VM_BUG_ON_PAGE(PageCompound(page), page);
VM_BUG_ON_PAGE(!page_count(page), page);
#ifdef CONFIG_KMEMCHECK
if (kmemcheck_page_is_tracked(page))
split_page(virt_to_page(page[0].shadow), order);
#endif
for (i = 1; i < (1 << order); i++)
set_page_refcounted(page + i);
split_page_owner(page, order);
}
int __isolate_free_page(struct page *page, unsigned int order)
{
unsigned long watermark;
struct zone *zone;
int mt;
BUG_ON(!PageBuddy(page));
zone = page_zone(page);
mt = get_pageblock_migratetype(page);
if (!is_migrate_isolate(mt)) {
watermark = min_wmark_pages(zone) + (1UL << order);
if (!zone_watermark_ok(zone, 0, watermark, 0, ALLOC_CMA))
return 0;
__mod_zone_freepage_state(zone, -(1UL << order), mt);
}
list_del(&page->lru);
zone->free_area[order].nr_free--;
rmv_page_order(page);
if (order >= pageblock_order - 1) {
struct page *endpage = page + (1 << order) - 1;
for (; page < endpage; page += pageblock_nr_pages) {
int mt = get_pageblock_migratetype(page);
if (!is_migrate_isolate(mt) && !is_migrate_cma(mt)
&& mt != MIGRATE_HIGHATOMIC)
set_pageblock_migratetype(page,
MIGRATE_MOVABLE);
}
}
return 1UL << order;
}
static inline void zone_statistics(struct zone *preferred_zone, struct zone *z)
{
#ifdef CONFIG_NUMA
enum zone_stat_item local_stat = NUMA_LOCAL;
if (z->node != numa_node_id())
local_stat = NUMA_OTHER;
if (z->node == preferred_zone->node)
__inc_zone_state(z, NUMA_HIT);
else {
__inc_zone_state(z, NUMA_MISS);
__inc_zone_state(preferred_zone, NUMA_FOREIGN);
}
__inc_zone_state(z, local_stat);
#endif
}
static inline
struct page *buffered_rmqueue(struct zone *preferred_zone,
struct zone *zone, unsigned int order,
gfp_t gfp_flags, unsigned int alloc_flags,
int migratetype)
{
unsigned long flags;
struct page *page;
bool cold = ((gfp_flags & __GFP_COLD) != 0);
if (likely(order == 0)) {
struct per_cpu_pages *pcp;
struct list_head *list;
local_irq_save(flags);
do {
pcp = &this_cpu_ptr(zone->pageset)->pcp;
list = &pcp->lists[migratetype];
if (list_empty(list)) {
pcp->count += rmqueue_bulk(zone, 0,
pcp->batch, list,
migratetype, cold);
if (unlikely(list_empty(list)))
goto failed;
}
if (cold)
page = list_last_entry(list, struct page, lru);
else
page = list_first_entry(list, struct page, lru);
list_del(&page->lru);
pcp->count--;
} while (check_new_pcp(page));
} else {
WARN_ON_ONCE((gfp_flags & __GFP_NOFAIL) && (order > 1));
spin_lock_irqsave(&zone->lock, flags);
do {
page = NULL;
if (alloc_flags & ALLOC_HARDER) {
page = __rmqueue_smallest(zone, order, MIGRATE_HIGHATOMIC);
if (page)
trace_mm_page_alloc_zone_locked(page, order, migratetype);
}
if (!page)
page = __rmqueue(zone, order, migratetype);
} while (page && check_new_pages(page, order));
spin_unlock(&zone->lock);
if (!page)
goto failed;
__mod_zone_freepage_state(zone, -(1 << order),
get_pcppage_migratetype(page));
}
__count_zid_vm_events(PGALLOC, page_zonenum(page), 1 << order);
zone_statistics(preferred_zone, zone);
local_irq_restore(flags);
VM_BUG_ON_PAGE(bad_range(zone, page), page);
return page;
failed:
local_irq_restore(flags);
return NULL;
}
static int __init setup_fail_page_alloc(char *str)
{
return setup_fault_attr(&fail_page_alloc.attr, str);
}
static bool should_fail_alloc_page(gfp_t gfp_mask, unsigned int order)
{
if (order < fail_page_alloc.min_order)
return false;
if (gfp_mask & __GFP_NOFAIL)
return false;
if (fail_page_alloc.ignore_gfp_highmem && (gfp_mask & __GFP_HIGHMEM))
return false;
if (fail_page_alloc.ignore_gfp_reclaim &&
(gfp_mask & __GFP_DIRECT_RECLAIM))
return false;
return should_fail(&fail_page_alloc.attr, 1 << order);
}
static int __init fail_page_alloc_debugfs(void)
{
umode_t mode = S_IFREG | S_IRUSR | S_IWUSR;
struct dentry *dir;
dir = fault_create_debugfs_attr("fail_page_alloc", NULL,
&fail_page_alloc.attr);
if (IS_ERR(dir))
return PTR_ERR(dir);
if (!debugfs_create_bool("ignore-gfp-wait", mode, dir,
&fail_page_alloc.ignore_gfp_reclaim))
goto fail;
if (!debugfs_create_bool("ignore-gfp-highmem", mode, dir,
&fail_page_alloc.ignore_gfp_highmem))
goto fail;
if (!debugfs_create_u32("min-order", mode, dir,
&fail_page_alloc.min_order))
goto fail;
return 0;
fail:
debugfs_remove_recursive(dir);
return -ENOMEM;
}
static inline bool should_fail_alloc_page(gfp_t gfp_mask, unsigned int order)
{
return false;
}
bool __zone_watermark_ok(struct zone *z, unsigned int order, unsigned long mark,
int classzone_idx, unsigned int alloc_flags,
long free_pages)
{
long min = mark;
int o;
const bool alloc_harder = (alloc_flags & ALLOC_HARDER);
free_pages -= (1 << order) - 1;
if (alloc_flags & ALLOC_HIGH)
min -= min / 2;
if (likely(!alloc_harder))
free_pages -= z->nr_reserved_highatomic;
else
min -= min / 4;
#ifdef CONFIG_CMA
if (!(alloc_flags & ALLOC_CMA))
free_pages -= zone_page_state(z, NR_FREE_CMA_PAGES);
#endif
if (free_pages <= min + z->lowmem_reserve[classzone_idx])
return false;
if (!order)
return true;
for (o = order; o < MAX_ORDER; o++) {
struct free_area *area = &z->free_area[o];
int mt;
if (!area->nr_free)
continue;
if (alloc_harder)
return true;
for (mt = 0; mt < MIGRATE_PCPTYPES; mt++) {
if (!list_empty(&area->free_list[mt]))
return true;
}
#ifdef CONFIG_CMA
if ((alloc_flags & ALLOC_CMA) &&
!list_empty(&area->free_list[MIGRATE_CMA])) {
return true;
}
#endif
}
return false;
}
bool zone_watermark_ok(struct zone *z, unsigned int order, unsigned long mark,
int classzone_idx, unsigned int alloc_flags)
{
return __zone_watermark_ok(z, order, mark, classzone_idx, alloc_flags,
zone_page_state(z, NR_FREE_PAGES));
}
static inline bool zone_watermark_fast(struct zone *z, unsigned int order,
unsigned long mark, int classzone_idx, unsigned int alloc_flags)
{
long free_pages = zone_page_state(z, NR_FREE_PAGES);
long cma_pages = 0;
#ifdef CONFIG_CMA
if (!(alloc_flags & ALLOC_CMA))
cma_pages = zone_page_state(z, NR_FREE_CMA_PAGES);
#endif
if (!order && (free_pages - cma_pages) > mark + z->lowmem_reserve[classzone_idx])
return true;
return __zone_watermark_ok(z, order, mark, classzone_idx, alloc_flags,
free_pages);
}
bool zone_watermark_ok_safe(struct zone *z, unsigned int order,
unsigned long mark, int classzone_idx)
{
long free_pages = zone_page_state(z, NR_FREE_PAGES);
if (z->percpu_drift_mark && free_pages < z->percpu_drift_mark)
free_pages = zone_page_state_snapshot(z, NR_FREE_PAGES);
return __zone_watermark_ok(z, order, mark, classzone_idx, 0,
free_pages);
}
static bool zone_allows_reclaim(struct zone *local_zone, struct zone *zone)
{
return node_distance(zone_to_nid(local_zone), zone_to_nid(zone)) <
RECLAIM_DISTANCE;
}
static bool zone_allows_reclaim(struct zone *local_zone, struct zone *zone)
{
return true;
}
static struct page *
get_page_from_freelist(gfp_t gfp_mask, unsigned int order, int alloc_flags,
const struct alloc_context *ac)
{
struct zoneref *z = ac->preferred_zoneref;
struct zone *zone;
struct pglist_data *last_pgdat_dirty_limit = NULL;
for_next_zone_zonelist_nodemask(zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct page *page;
unsigned long mark;
if (cpusets_enabled() &&
(alloc_flags & ALLOC_CPUSET) &&
!__cpuset_zone_allowed(zone, gfp_mask))
continue;
if (ac->spread_dirty_pages) {
if (last_pgdat_dirty_limit == zone->zone_pgdat)
continue;
if (!node_dirty_ok(zone->zone_pgdat)) {
last_pgdat_dirty_limit = zone->zone_pgdat;
continue;
}
}
mark = zone->watermark[alloc_flags & ALLOC_WMARK_MASK];
if (!zone_watermark_fast(zone, order, mark,
ac_classzone_idx(ac), alloc_flags)) {
int ret;
BUILD_BUG_ON(ALLOC_NO_WATERMARKS < NR_WMARK);
if (alloc_flags & ALLOC_NO_WATERMARKS)
goto try_this_zone;
if (node_reclaim_mode == 0 ||
!zone_allows_reclaim(ac->preferred_zoneref->zone, zone))
continue;
ret = node_reclaim(zone->zone_pgdat, gfp_mask, order);
switch (ret) {
case NODE_RECLAIM_NOSCAN:
continue;
case NODE_RECLAIM_FULL:
continue;
default:
if (zone_watermark_ok(zone, order, mark,
ac_classzone_idx(ac), alloc_flags))
goto try_this_zone;
continue;
}
}
try_this_zone:
page = buffered_rmqueue(ac->preferred_zoneref->zone, zone, order,
gfp_mask, alloc_flags, ac->migratetype);
if (page) {
prep_new_page(page, order, gfp_mask, alloc_flags);
if (unlikely(order && (alloc_flags & ALLOC_HARDER)))
reserve_highatomic_pageblock(page, zone, order);
return page;
}
}
return NULL;
}
static inline bool should_suppress_show_mem(void)
{
bool ret = false;
#if NODES_SHIFT > 8
ret = in_interrupt();
#endif
return ret;
}
void warn_alloc(gfp_t gfp_mask, const char *fmt, ...)
{
unsigned int filter = SHOW_MEM_FILTER_NODES;
struct va_format vaf;
va_list args;
if ((gfp_mask & __GFP_NOWARN) || !__ratelimit(&nopage_rs) ||
debug_guardpage_minorder() > 0)
return;
if (!(gfp_mask & __GFP_NOMEMALLOC))
if (test_thread_flag(TIF_MEMDIE) ||
(current->flags & (PF_MEMALLOC | PF_EXITING)))
filter &= ~SHOW_MEM_FILTER_NODES;
if (in_interrupt() || !(gfp_mask & __GFP_DIRECT_RECLAIM))
filter &= ~SHOW_MEM_FILTER_NODES;
pr_warn("%s: ", current->comm);
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
pr_cont("%pV", &vaf);
va_end(args);
pr_cont(", mode:%#x(%pGg)\n", gfp_mask, &gfp_mask);
dump_stack();
if (!should_suppress_show_mem())
show_mem(filter);
}
static inline struct page *
__alloc_pages_may_oom(gfp_t gfp_mask, unsigned int order,
const struct alloc_context *ac, unsigned long *did_some_progress)
{
struct oom_control oc = {
.zonelist = ac->zonelist,
.nodemask = ac->nodemask,
.memcg = NULL,
.gfp_mask = gfp_mask,
.order = order,
};
struct page *page;
*did_some_progress = 0;
if (!mutex_trylock(&oom_lock)) {
*did_some_progress = 1;
schedule_timeout_uninterruptible(1);
return NULL;
}
page = get_page_from_freelist(gfp_mask | __GFP_HARDWALL, order,
ALLOC_WMARK_HIGH|ALLOC_CPUSET, ac);
if (page)
goto out;
if (!(gfp_mask & __GFP_NOFAIL)) {
if (current->flags & PF_DUMPCORE)
goto out;
if (order > PAGE_ALLOC_COSTLY_ORDER)
goto out;
if (ac->high_zoneidx < ZONE_NORMAL)
goto out;
if (pm_suspended_storage())
goto out;
if (gfp_mask & __GFP_THISNODE)
goto out;
}
if (out_of_memory(&oc) || WARN_ON_ONCE(gfp_mask & __GFP_NOFAIL)) {
*did_some_progress = 1;
if (gfp_mask & __GFP_NOFAIL) {
page = get_page_from_freelist(gfp_mask, order,
ALLOC_NO_WATERMARKS|ALLOC_CPUSET, ac);
if (!page)
page = get_page_from_freelist(gfp_mask, order,
ALLOC_NO_WATERMARKS, ac);
}
}
out:
mutex_unlock(&oom_lock);
return page;
}
static struct page *
__alloc_pages_direct_compact(gfp_t gfp_mask, unsigned int order,
unsigned int alloc_flags, const struct alloc_context *ac,
enum compact_priority prio, enum compact_result *compact_result)
{
struct page *page;
if (!order)
return NULL;
current->flags |= PF_MEMALLOC;
*compact_result = try_to_compact_pages(gfp_mask, order, alloc_flags, ac,
prio);
current->flags &= ~PF_MEMALLOC;
if (*compact_result <= COMPACT_INACTIVE)
return NULL;
count_vm_event(COMPACTSTALL);
page = get_page_from_freelist(gfp_mask, order, alloc_flags, ac);
if (page) {
struct zone *zone = page_zone(page);
zone->compact_blockskip_flush = false;
compaction_defer_reset(zone, order, true);
count_vm_event(COMPACTSUCCESS);
return page;
}
count_vm_event(COMPACTFAIL);
cond_resched();
return NULL;
}
static inline bool
should_compact_retry(struct alloc_context *ac, int order, int alloc_flags,
enum compact_result compact_result,
enum compact_priority *compact_priority,
int *compaction_retries)
{
int max_retries = MAX_COMPACT_RETRIES;
int min_priority;
if (!order)
return false;
if (compaction_made_progress(compact_result))
(*compaction_retries)++;
if (compaction_failed(compact_result))
goto check_priority;
if (compaction_withdrawn(compact_result))
return compaction_zonelist_suitable(ac, order, alloc_flags);
if (order > PAGE_ALLOC_COSTLY_ORDER)
max_retries /= 4;
if (*compaction_retries <= max_retries)
return true;
check_priority:
min_priority = (order > PAGE_ALLOC_COSTLY_ORDER) ?
MIN_COMPACT_COSTLY_PRIORITY : MIN_COMPACT_PRIORITY;
if (*compact_priority > min_priority) {
(*compact_priority)--;
*compaction_retries = 0;
return true;
}
return false;
}
static inline struct page *
__alloc_pages_direct_compact(gfp_t gfp_mask, unsigned int order,
unsigned int alloc_flags, const struct alloc_context *ac,
enum compact_priority prio, enum compact_result *compact_result)
{
*compact_result = COMPACT_SKIPPED;
return NULL;
}
static inline bool
should_compact_retry(struct alloc_context *ac, unsigned int order, int alloc_flags,
enum compact_result compact_result,
enum compact_priority *compact_priority,
int *compaction_retries)
{
struct zone *zone;
struct zoneref *z;
if (!order || order > PAGE_ALLOC_COSTLY_ORDER)
return false;
for_each_zone_zonelist_nodemask(zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if (zone_watermark_ok(zone, 0, min_wmark_pages(zone),
ac_classzone_idx(ac), alloc_flags))
return true;
}
return false;
}
static int
__perform_reclaim(gfp_t gfp_mask, unsigned int order,
const struct alloc_context *ac)
{
struct reclaim_state reclaim_state;
int progress;
cond_resched();
cpuset_memory_pressure_bump();
current->flags |= PF_MEMALLOC;
lockdep_set_current_reclaim_state(gfp_mask);
reclaim_state.reclaimed_slab = 0;
current->reclaim_state = &reclaim_state;
progress = try_to_free_pages(ac->zonelist, order, gfp_mask,
ac->nodemask);
current->reclaim_state = NULL;
lockdep_clear_current_reclaim_state();
current->flags &= ~PF_MEMALLOC;
cond_resched();
return progress;
}
static inline struct page *
__alloc_pages_direct_reclaim(gfp_t gfp_mask, unsigned int order,
unsigned int alloc_flags, const struct alloc_context *ac,
unsigned long *did_some_progress)
{
struct page *page = NULL;
bool drained = false;
*did_some_progress = __perform_reclaim(gfp_mask, order, ac);
if (unlikely(!(*did_some_progress)))
return NULL;
retry:
page = get_page_from_freelist(gfp_mask, order, alloc_flags, ac);
if (!page && !drained) {
unreserve_highatomic_pageblock(ac, false);
drain_all_pages(NULL);
drained = true;
goto retry;
}
return page;
}
static void wake_all_kswapds(unsigned int order, const struct alloc_context *ac)
{
struct zoneref *z;
struct zone *zone;
pg_data_t *last_pgdat = NULL;
for_each_zone_zonelist_nodemask(zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if (last_pgdat != zone->zone_pgdat)
wakeup_kswapd(zone, order, ac->high_zoneidx);
last_pgdat = zone->zone_pgdat;
}
}
static inline unsigned int
gfp_to_alloc_flags(gfp_t gfp_mask)
{
unsigned int alloc_flags = ALLOC_WMARK_MIN | ALLOC_CPUSET;
BUILD_BUG_ON(__GFP_HIGH != (__force gfp_t) ALLOC_HIGH);
alloc_flags |= (__force int) (gfp_mask & __GFP_HIGH);
if (gfp_mask & __GFP_ATOMIC) {
if (!(gfp_mask & __GFP_NOMEMALLOC))
alloc_flags |= ALLOC_HARDER;
alloc_flags &= ~ALLOC_CPUSET;
} else if (unlikely(rt_task(current)) && !in_interrupt())
alloc_flags |= ALLOC_HARDER;
#ifdef CONFIG_CMA
if (gfpflags_to_migratetype(gfp_mask) == MIGRATE_MOVABLE)
alloc_flags |= ALLOC_CMA;
#endif
return alloc_flags;
}
bool gfp_pfmemalloc_allowed(gfp_t gfp_mask)
{
if (unlikely(gfp_mask & __GFP_NOMEMALLOC))
return false;
if (gfp_mask & __GFP_MEMALLOC)
return true;
if (in_serving_softirq() && (current->flags & PF_MEMALLOC))
return true;
if (!in_interrupt() &&
((current->flags & PF_MEMALLOC) ||
unlikely(test_thread_flag(TIF_MEMDIE))))
return true;
return false;
}
static inline bool
should_reclaim_retry(gfp_t gfp_mask, unsigned order,
struct alloc_context *ac, int alloc_flags,
bool did_some_progress, int *no_progress_loops)
{
struct zone *zone;
struct zoneref *z;
if (did_some_progress && order <= PAGE_ALLOC_COSTLY_ORDER)
*no_progress_loops = 0;
else
(*no_progress_loops)++;
if (*no_progress_loops > MAX_RECLAIM_RETRIES) {
return unreserve_highatomic_pageblock(ac, true);
}
for_each_zone_zonelist_nodemask(zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long available;
unsigned long reclaimable;
available = reclaimable = zone_reclaimable_pages(zone);
available -= DIV_ROUND_UP((*no_progress_loops) * available,
MAX_RECLAIM_RETRIES);
available += zone_page_state_snapshot(zone, NR_FREE_PAGES);
if (__zone_watermark_ok(zone, order, min_wmark_pages(zone),
ac_classzone_idx(ac), alloc_flags, available)) {
if (!did_some_progress) {
unsigned long write_pending;
write_pending = zone_page_state_snapshot(zone,
NR_ZONE_WRITE_PENDING);
if (2 * write_pending > reclaimable) {
congestion_wait(BLK_RW_ASYNC, HZ/10);
return true;
}
}
if (current->flags & PF_WQ_WORKER)
schedule_timeout_uninterruptible(1);
else
cond_resched();
return true;
}
}
return false;
}
static inline struct page *
__alloc_pages_slowpath(gfp_t gfp_mask, unsigned int order,
struct alloc_context *ac)
{
bool can_direct_reclaim = gfp_mask & __GFP_DIRECT_RECLAIM;
struct page *page = NULL;
unsigned int alloc_flags;
unsigned long did_some_progress;
enum compact_priority compact_priority;
enum compact_result compact_result;
int compaction_retries;
int no_progress_loops;
unsigned long alloc_start = jiffies;
unsigned int stall_timeout = 10 * HZ;
unsigned int cpuset_mems_cookie;
if (order >= MAX_ORDER) {
WARN_ON_ONCE(!(gfp_mask & __GFP_NOWARN));
return NULL;
}
if (WARN_ON_ONCE((gfp_mask & (__GFP_ATOMIC|__GFP_DIRECT_RECLAIM)) ==
(__GFP_ATOMIC|__GFP_DIRECT_RECLAIM)))
gfp_mask &= ~__GFP_ATOMIC;
retry_cpuset:
compaction_retries = 0;
no_progress_loops = 0;
compact_priority = DEF_COMPACT_PRIORITY;
cpuset_mems_cookie = read_mems_allowed_begin();
ac->preferred_zoneref = first_zones_zonelist(ac->zonelist,
ac->high_zoneidx, ac->nodemask);
if (!ac->preferred_zoneref->zone)
goto nopage;
alloc_flags = gfp_to_alloc_flags(gfp_mask);
if (gfp_mask & __GFP_KSWAPD_RECLAIM)
wake_all_kswapds(order, ac);
page = get_page_from_freelist(gfp_mask, order, alloc_flags, ac);
if (page)
goto got_pg;
if (can_direct_reclaim && order > PAGE_ALLOC_COSTLY_ORDER &&
!gfp_pfmemalloc_allowed(gfp_mask)) {
page = __alloc_pages_direct_compact(gfp_mask, order,
alloc_flags, ac,
INIT_COMPACT_PRIORITY,
&compact_result);
if (page)
goto got_pg;
if (gfp_mask & __GFP_NORETRY) {
if (compact_result == COMPACT_DEFERRED)
goto nopage;
compact_priority = INIT_COMPACT_PRIORITY;
}
}
retry:
if (gfp_mask & __GFP_KSWAPD_RECLAIM)
wake_all_kswapds(order, ac);
if (gfp_pfmemalloc_allowed(gfp_mask))
alloc_flags = ALLOC_NO_WATERMARKS;
if (!(alloc_flags & ALLOC_CPUSET) || (alloc_flags & ALLOC_NO_WATERMARKS)) {
ac->zonelist = node_zonelist(numa_node_id(), gfp_mask);
ac->preferred_zoneref = first_zones_zonelist(ac->zonelist,
ac->high_zoneidx, ac->nodemask);
}
page = get_page_from_freelist(gfp_mask, order, alloc_flags, ac);
if (page)
goto got_pg;
if (!can_direct_reclaim) {
WARN_ON_ONCE(gfp_mask & __GFP_NOFAIL);
goto nopage;
}
if (current->flags & PF_MEMALLOC) {
if (WARN_ON_ONCE(gfp_mask & __GFP_NOFAIL)) {
cond_resched();
goto retry;
}
goto nopage;
}
if (test_thread_flag(TIF_MEMDIE) && !(gfp_mask & __GFP_NOFAIL))
goto nopage;
page = __alloc_pages_direct_reclaim(gfp_mask, order, alloc_flags, ac,
&did_some_progress);
if (page)
goto got_pg;
page = __alloc_pages_direct_compact(gfp_mask, order, alloc_flags, ac,
compact_priority, &compact_result);
if (page)
goto got_pg;
if (gfp_mask & __GFP_NORETRY)
goto nopage;
if (order > PAGE_ALLOC_COSTLY_ORDER && !(gfp_mask & __GFP_REPEAT))
goto nopage;
if (time_after(jiffies, alloc_start + stall_timeout)) {
warn_alloc(gfp_mask,
"page allocation stalls for %ums, order:%u",
jiffies_to_msecs(jiffies-alloc_start), order);
stall_timeout += 10 * HZ;
}
if (should_reclaim_retry(gfp_mask, order, ac, alloc_flags,
did_some_progress > 0, &no_progress_loops))
goto retry;
if (did_some_progress > 0 &&
should_compact_retry(ac, order, alloc_flags,
compact_result, &compact_priority,
&compaction_retries))
goto retry;
if (read_mems_allowed_retry(cpuset_mems_cookie))
goto retry_cpuset;
page = __alloc_pages_may_oom(gfp_mask, order, ac, &did_some_progress);
if (page)
goto got_pg;
if (did_some_progress) {
no_progress_loops = 0;
goto retry;
}
nopage:
if (read_mems_allowed_retry(cpuset_mems_cookie))
goto retry_cpuset;
warn_alloc(gfp_mask,
"page allocation failure: order:%u", order);
got_pg:
return page;
}
struct page *
__alloc_pages_nodemask(gfp_t gfp_mask, unsigned int order,
struct zonelist *zonelist, nodemask_t *nodemask)
{
struct page *page;
unsigned int alloc_flags = ALLOC_WMARK_LOW;
gfp_t alloc_mask = gfp_mask;
struct alloc_context ac = {
.high_zoneidx = gfp_zone(gfp_mask),
.zonelist = zonelist,
.nodemask = nodemask,
.migratetype = gfpflags_to_migratetype(gfp_mask),
};
if (cpusets_enabled()) {
alloc_mask |= __GFP_HARDWALL;
alloc_flags |= ALLOC_CPUSET;
if (!ac.nodemask)
ac.nodemask = &cpuset_current_mems_allowed;
}
gfp_mask &= gfp_allowed_mask;
lockdep_trace_alloc(gfp_mask);
might_sleep_if(gfp_mask & __GFP_DIRECT_RECLAIM);
if (should_fail_alloc_page(gfp_mask, order))
return NULL;
if (unlikely(!zonelist->_zonerefs->zone))
return NULL;
if (IS_ENABLED(CONFIG_CMA) && ac.migratetype == MIGRATE_MOVABLE)
alloc_flags |= ALLOC_CMA;
ac.spread_dirty_pages = (gfp_mask & __GFP_WRITE);
ac.preferred_zoneref = first_zones_zonelist(ac.zonelist,
ac.high_zoneidx, ac.nodemask);
if (!ac.preferred_zoneref->zone) {
page = NULL;
goto no_zone;
}
page = get_page_from_freelist(alloc_mask, order, alloc_flags, &ac);
if (likely(page))
goto out;
no_zone:
alloc_mask = memalloc_noio_flags(gfp_mask);
ac.spread_dirty_pages = false;
if (unlikely(ac.nodemask != nodemask))
ac.nodemask = nodemask;
page = __alloc_pages_slowpath(alloc_mask, order, &ac);
out:
if (memcg_kmem_enabled() && (gfp_mask & __GFP_ACCOUNT) && page &&
unlikely(memcg_kmem_charge(page, gfp_mask, order) != 0)) {
__free_pages(page, order);
page = NULL;
}
if (kmemcheck_enabled && page)
kmemcheck_pagealloc_alloc(page, order, gfp_mask);
trace_mm_page_alloc(page, order, alloc_mask, ac.migratetype);
return page;
}
unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order)
{
struct page *page;
VM_BUG_ON((gfp_mask & __GFP_HIGHMEM) != 0);
page = alloc_pages(gfp_mask, order);
if (!page)
return 0;
return (unsigned long) page_address(page);
}
unsigned long get_zeroed_page(gfp_t gfp_mask)
{
return __get_free_pages(gfp_mask | __GFP_ZERO, 0);
}
void __free_pages(struct page *page, unsigned int order)
{
if (put_page_testzero(page)) {
if (order == 0)
free_hot_cold_page(page, false);
else
__free_pages_ok(page, order);
}
}
void free_pages(unsigned long addr, unsigned int order)
{
if (addr != 0) {
VM_BUG_ON(!virt_addr_valid((void *)addr));
__free_pages(virt_to_page((void *)addr), order);
}
}
static struct page *__page_frag_cache_refill(struct page_frag_cache *nc,
gfp_t gfp_mask)
{
struct page *page = NULL;
gfp_t gfp = gfp_mask;
#if (PAGE_SIZE < PAGE_FRAG_CACHE_MAX_SIZE)
gfp_mask |= __GFP_COMP | __GFP_NOWARN | __GFP_NORETRY |
__GFP_NOMEMALLOC;
page = alloc_pages_node(NUMA_NO_NODE, gfp_mask,
PAGE_FRAG_CACHE_MAX_ORDER);
nc->size = page ? PAGE_FRAG_CACHE_MAX_SIZE : PAGE_SIZE;
#endif
if (unlikely(!page))
page = alloc_pages_node(NUMA_NO_NODE, gfp, 0);
nc->va = page ? page_address(page) : NULL;
return page;
}
void __page_frag_cache_drain(struct page *page, unsigned int count)
{
VM_BUG_ON_PAGE(page_ref_count(page) == 0, page);
if (page_ref_sub_and_test(page, count)) {
unsigned int order = compound_order(page);
if (order == 0)
free_hot_cold_page(page, false);
else
__free_pages_ok(page, order);
}
}
void *page_frag_alloc(struct page_frag_cache *nc,
unsigned int fragsz, gfp_t gfp_mask)
{
unsigned int size = PAGE_SIZE;
struct page *page;
int offset;
if (unlikely(!nc->va)) {
refill:
page = __page_frag_cache_refill(nc, gfp_mask);
if (!page)
return NULL;
#if (PAGE_SIZE < PAGE_FRAG_CACHE_MAX_SIZE)
size = nc->size;
#endif
page_ref_add(page, size - 1);
nc->pfmemalloc = page_is_pfmemalloc(page);
nc->pagecnt_bias = size;
nc->offset = size;
}
offset = nc->offset - fragsz;
if (unlikely(offset < 0)) {
page = virt_to_page(nc->va);
if (!page_ref_sub_and_test(page, nc->pagecnt_bias))
goto refill;
#if (PAGE_SIZE < PAGE_FRAG_CACHE_MAX_SIZE)
size = nc->size;
#endif
set_page_count(page, size);
nc->pagecnt_bias = size;
offset = size - fragsz;
}
nc->pagecnt_bias--;
nc->offset = offset;
return nc->va + offset;
}
void page_frag_free(void *addr)
{
struct page *page = virt_to_head_page(addr);
if (unlikely(put_page_testzero(page)))
__free_pages_ok(page, compound_order(page));
}
static void *make_alloc_exact(unsigned long addr, unsigned int order,
size_t size)
{
if (addr) {
unsigned long alloc_end = addr + (PAGE_SIZE << order);
unsigned long used = addr + PAGE_ALIGN(size);
split_page(virt_to_page((void *)addr), order);
while (used < alloc_end) {
free_page(used);
used += PAGE_SIZE;
}
}
return (void *)addr;
}
void *alloc_pages_exact(size_t size, gfp_t gfp_mask)
{
unsigned int order = get_order(size);
unsigned long addr;
addr = __get_free_pages(gfp_mask, order);
return make_alloc_exact(addr, order, size);
}
void * __meminit alloc_pages_exact_nid(int nid, size_t size, gfp_t gfp_mask)
{
unsigned int order = get_order(size);
struct page *p = alloc_pages_node(nid, gfp_mask, order);
if (!p)
return NULL;
return make_alloc_exact((unsigned long)page_address(p), order, size);
}
void free_pages_exact(void *virt, size_t size)
{
unsigned long addr = (unsigned long)virt;
unsigned long end = addr + PAGE_ALIGN(size);
while (addr < end) {
free_page(addr);
addr += PAGE_SIZE;
}
}
static unsigned long nr_free_zone_pages(int offset)
{
struct zoneref *z;
struct zone *zone;
unsigned long sum = 0;
struct zonelist *zonelist = node_zonelist(numa_node_id(), GFP_KERNEL);
for_each_zone_zonelist(zone, z, zonelist, offset) {
unsigned long size = zone->managed_pages;
unsigned long high = high_wmark_pages(zone);
if (size > high)
sum += size - high;
}
return sum;
}
unsigned long nr_free_buffer_pages(void)
{
return nr_free_zone_pages(gfp_zone(GFP_USER));
}
unsigned long nr_free_pagecache_pages(void)
{
return nr_free_zone_pages(gfp_zone(GFP_HIGHUSER_MOVABLE));
}
static inline void show_node(struct zone *zone)
{
if (IS_ENABLED(CONFIG_NUMA))
printk("Node %d ", zone_to_nid(zone));
}
long si_mem_available(void)
{
long available;
unsigned long pagecache;
unsigned long wmark_low = 0;
unsigned long pages[NR_LRU_LISTS];
struct zone *zone;
int lru;
for (lru = LRU_BASE; lru < NR_LRU_LISTS; lru++)
pages[lru] = global_node_page_state(NR_LRU_BASE + lru);
for_each_zone(zone)
wmark_low += zone->watermark[WMARK_LOW];
available = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
pagecache = pages[LRU_ACTIVE_FILE] + pages[LRU_INACTIVE_FILE];
pagecache -= min(pagecache / 2, wmark_low);
available += pagecache;
available += global_page_state(NR_SLAB_RECLAIMABLE) -
min(global_page_state(NR_SLAB_RECLAIMABLE) / 2, wmark_low);
if (available < 0)
available = 0;
return available;
}
void si_meminfo(struct sysinfo *val)
{
val->totalram = totalram_pages;
val->sharedram = global_node_page_state(NR_SHMEM);
val->freeram = global_page_state(NR_FREE_PAGES);
val->bufferram = nr_blockdev_pages();
val->totalhigh = totalhigh_pages;
val->freehigh = nr_free_highpages();
val->mem_unit = PAGE_SIZE;
}
void si_meminfo_node(struct sysinfo *val, int nid)
{
int zone_type;
unsigned long managed_pages = 0;
unsigned long managed_highpages = 0;
unsigned long free_highpages = 0;
pg_data_t *pgdat = NODE_DATA(nid);
for (zone_type = 0; zone_type < MAX_NR_ZONES; zone_type++)
managed_pages += pgdat->node_zones[zone_type].managed_pages;
val->totalram = managed_pages;
val->sharedram = node_page_state(pgdat, NR_SHMEM);
val->freeram = sum_zone_node_page_state(nid, NR_FREE_PAGES);
#ifdef CONFIG_HIGHMEM
for (zone_type = 0; zone_type < MAX_NR_ZONES; zone_type++) {
struct zone *zone = &pgdat->node_zones[zone_type];
if (is_highmem(zone)) {
managed_highpages += zone->managed_pages;
free_highpages += zone_page_state(zone, NR_FREE_PAGES);
}
}
val->totalhigh = managed_highpages;
val->freehigh = free_highpages;
#else
val->totalhigh = managed_highpages;
val->freehigh = free_highpages;
#endif
val->mem_unit = PAGE_SIZE;
}
bool skip_free_areas_node(unsigned int flags, int nid)
{
bool ret = false;
unsigned int cpuset_mems_cookie;
if (!(flags & SHOW_MEM_FILTER_NODES))
goto out;
do {
cpuset_mems_cookie = read_mems_allowed_begin();
ret = !node_isset(nid, cpuset_current_mems_allowed);
} while (read_mems_allowed_retry(cpuset_mems_cookie));
out:
return ret;
}
static void show_migration_types(unsigned char type)
{
static const char types[MIGRATE_TYPES] = {
[MIGRATE_UNMOVABLE] = 'U',
[MIGRATE_MOVABLE] = 'M',
[MIGRATE_RECLAIMABLE] = 'E',
[MIGRATE_HIGHATOMIC] = 'H',
#ifdef CONFIG_CMA
[MIGRATE_CMA] = 'C',
#endif
#ifdef CONFIG_MEMORY_ISOLATION
[MIGRATE_ISOLATE] = 'I',
#endif
};
char tmp[MIGRATE_TYPES + 1];
char *p = tmp;
int i;
for (i = 0; i < MIGRATE_TYPES; i++) {
if (type & (1 << i))
*p++ = types[i];
}
*p = '\0';
printk(KERN_CONT "(%s) ", tmp);
}
void show_free_areas(unsigned int filter)
{
unsigned long free_pcp = 0;
int cpu;
struct zone *zone;
pg_data_t *pgdat;
for_each_populated_zone(zone) {
if (skip_free_areas_node(filter, zone_to_nid(zone)))
continue;
for_each_online_cpu(cpu)
free_pcp += per_cpu_ptr(zone->pageset, cpu)->pcp.count;
}
printk("active_anon:%lu inactive_anon:%lu isolated_anon:%lu\n"
" active_file:%lu inactive_file:%lu isolated_file:%lu\n"
" unevictable:%lu dirty:%lu writeback:%lu unstable:%lu\n"
" slab_reclaimable:%lu slab_unreclaimable:%lu\n"
" mapped:%lu shmem:%lu pagetables:%lu bounce:%lu\n"
" free:%lu free_pcp:%lu free_cma:%lu\n",
global_node_page_state(NR_ACTIVE_ANON),
global_node_page_state(NR_INACTIVE_ANON),
global_node_page_state(NR_ISOLATED_ANON),
global_node_page_state(NR_ACTIVE_FILE),
global_node_page_state(NR_INACTIVE_FILE),
global_node_page_state(NR_ISOLATED_FILE),
global_node_page_state(NR_UNEVICTABLE),
global_node_page_state(NR_FILE_DIRTY),
global_node_page_state(NR_WRITEBACK),
global_node_page_state(NR_UNSTABLE_NFS),
global_page_state(NR_SLAB_RECLAIMABLE),
global_page_state(NR_SLAB_UNRECLAIMABLE),
global_node_page_state(NR_FILE_MAPPED),
global_node_page_state(NR_SHMEM),
global_page_state(NR_PAGETABLE),
global_page_state(NR_BOUNCE),
global_page_state(NR_FREE_PAGES),
free_pcp,
global_page_state(NR_FREE_CMA_PAGES));
for_each_online_pgdat(pgdat) {
printk("Node %d"
" active_anon:%lukB"
" inactive_anon:%lukB"
" active_file:%lukB"
" inactive_file:%lukB"
" unevictable:%lukB"
" isolated(anon):%lukB"
" isolated(file):%lukB"
" mapped:%lukB"
" dirty:%lukB"
" writeback:%lukB"
" shmem:%lukB"
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
" shmem_thp: %lukB"
" shmem_pmdmapped: %lukB"
" anon_thp: %lukB"
#endif
" writeback_tmp:%lukB"
" unstable:%lukB"
" pages_scanned:%lu"
" all_unreclaimable? %s"
"\n",
pgdat->node_id,
K(node_page_state(pgdat, NR_ACTIVE_ANON)),
K(node_page_state(pgdat, NR_INACTIVE_ANON)),
K(node_page_state(pgdat, NR_ACTIVE_FILE)),
K(node_page_state(pgdat, NR_INACTIVE_FILE)),
K(node_page_state(pgdat, NR_UNEVICTABLE)),
K(node_page_state(pgdat, NR_ISOLATED_ANON)),
K(node_page_state(pgdat, NR_ISOLATED_FILE)),
K(node_page_state(pgdat, NR_FILE_MAPPED)),
K(node_page_state(pgdat, NR_FILE_DIRTY)),
K(node_page_state(pgdat, NR_WRITEBACK)),
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
K(node_page_state(pgdat, NR_SHMEM_THPS) * HPAGE_PMD_NR),
K(node_page_state(pgdat, NR_SHMEM_PMDMAPPED)
* HPAGE_PMD_NR),
K(node_page_state(pgdat, NR_ANON_THPS) * HPAGE_PMD_NR),
#endif
K(node_page_state(pgdat, NR_SHMEM)),
K(node_page_state(pgdat, NR_WRITEBACK_TEMP)),
K(node_page_state(pgdat, NR_UNSTABLE_NFS)),
node_page_state(pgdat, NR_PAGES_SCANNED),
!pgdat_reclaimable(pgdat) ? "yes" : "no");
}
for_each_populated_zone(zone) {
int i;
if (skip_free_areas_node(filter, zone_to_nid(zone)))
continue;
free_pcp = 0;
for_each_online_cpu(cpu)
free_pcp += per_cpu_ptr(zone->pageset, cpu)->pcp.count;
show_node(zone);
printk(KERN_CONT
"%s"
" free:%lukB"
" min:%lukB"
" low:%lukB"
" high:%lukB"
" active_anon:%lukB"
" inactive_anon:%lukB"
" active_file:%lukB"
" inactive_file:%lukB"
" unevictable:%lukB"
" writepending:%lukB"
" present:%lukB"
" managed:%lukB"
" mlocked:%lukB"
" slab_reclaimable:%lukB"
" slab_unreclaimable:%lukB"
" kernel_stack:%lukB"
" pagetables:%lukB"
" bounce:%lukB"
" free_pcp:%lukB"
" local_pcp:%ukB"
" free_cma:%lukB"
"\n",
zone->name,
K(zone_page_state(zone, NR_FREE_PAGES)),
K(min_wmark_pages(zone)),
K(low_wmark_pages(zone)),
K(high_wmark_pages(zone)),
K(zone_page_state(zone, NR_ZONE_ACTIVE_ANON)),
K(zone_page_state(zone, NR_ZONE_INACTIVE_ANON)),
K(zone_page_state(zone, NR_ZONE_ACTIVE_FILE)),
K(zone_page_state(zone, NR_ZONE_INACTIVE_FILE)),
K(zone_page_state(zone, NR_ZONE_UNEVICTABLE)),
K(zone_page_state(zone, NR_ZONE_WRITE_PENDING)),
K(zone->present_pages),
K(zone->managed_pages),
K(zone_page_state(zone, NR_MLOCK)),
K(zone_page_state(zone, NR_SLAB_RECLAIMABLE)),
K(zone_page_state(zone, NR_SLAB_UNRECLAIMABLE)),
zone_page_state(zone, NR_KERNEL_STACK_KB),
K(zone_page_state(zone, NR_PAGETABLE)),
K(zone_page_state(zone, NR_BOUNCE)),
K(free_pcp),
K(this_cpu_read(zone->pageset->pcp.count)),
K(zone_page_state(zone, NR_FREE_CMA_PAGES)));
printk("lowmem_reserve[]:");
for (i = 0; i < MAX_NR_ZONES; i++)
printk(KERN_CONT " %ld", zone->lowmem_reserve[i]);
printk(KERN_CONT "\n");
}
for_each_populated_zone(zone) {
unsigned int order;
unsigned long nr[MAX_ORDER], flags, total = 0;
unsigned char types[MAX_ORDER];
if (skip_free_areas_node(filter, zone_to_nid(zone)))
continue;
show_node(zone);
printk(KERN_CONT "%s: ", zone->name);
spin_lock_irqsave(&zone->lock, flags);
for (order = 0; order < MAX_ORDER; order++) {
struct free_area *area = &zone->free_area[order];
int type;
nr[order] = area->nr_free;
total += nr[order] << order;
types[order] = 0;
for (type = 0; type < MIGRATE_TYPES; type++) {
if (!list_empty(&area->free_list[type]))
types[order] |= 1 << type;
}
}
spin_unlock_irqrestore(&zone->lock, flags);
for (order = 0; order < MAX_ORDER; order++) {
printk(KERN_CONT "%lu*%lukB ",
nr[order], K(1UL) << order);
if (nr[order])
show_migration_types(types[order]);
}
printk(KERN_CONT "= %lukB\n", K(total));
}
hugetlb_show_meminfo();
printk("%ld total pagecache pages\n", global_node_page_state(NR_FILE_PAGES));
show_swap_cache_info();
}
static void zoneref_set_zone(struct zone *zone, struct zoneref *zoneref)
{
zoneref->zone = zone;
zoneref->zone_idx = zone_idx(zone);
}
static int build_zonelists_node(pg_data_t *pgdat, struct zonelist *zonelist,
int nr_zones)
{
struct zone *zone;
enum zone_type zone_type = MAX_NR_ZONES;
do {
zone_type--;
zone = pgdat->node_zones + zone_type;
if (managed_zone(zone)) {
zoneref_set_zone(zone,
&zonelist->_zonerefs[nr_zones++]);
check_highest_zone(zone_type);
}
} while (zone_type);
return nr_zones;
}
static int __parse_numa_zonelist_order(char *s)
{
if (*s == 'd' || *s == 'D') {
user_zonelist_order = ZONELIST_ORDER_DEFAULT;
} else if (*s == 'n' || *s == 'N') {
user_zonelist_order = ZONELIST_ORDER_NODE;
} else if (*s == 'z' || *s == 'Z') {
user_zonelist_order = ZONELIST_ORDER_ZONE;
} else {
pr_warn("Ignoring invalid numa_zonelist_order value: %s\n", s);
return -EINVAL;
}
return 0;
}
static __init int setup_numa_zonelist_order(char *s)
{
int ret;
if (!s)
return 0;
ret = __parse_numa_zonelist_order(s);
if (ret == 0)
strlcpy(numa_zonelist_order, s, NUMA_ZONELIST_ORDER_LEN);
return ret;
}
int numa_zonelist_order_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length,
loff_t *ppos)
{
char saved_string[NUMA_ZONELIST_ORDER_LEN];
int ret;
static DEFINE_MUTEX(zl_order_mutex);
mutex_lock(&zl_order_mutex);
if (write) {
if (strlen((char *)table->data) >= NUMA_ZONELIST_ORDER_LEN) {
ret = -EINVAL;
goto out;
}
strcpy(saved_string, (char *)table->data);
}
ret = proc_dostring(table, write, buffer, length, ppos);
if (ret)
goto out;
if (write) {
int oldval = user_zonelist_order;
ret = __parse_numa_zonelist_order((char *)table->data);
if (ret) {
strncpy((char *)table->data, saved_string,
NUMA_ZONELIST_ORDER_LEN);
user_zonelist_order = oldval;
} else if (oldval != user_zonelist_order) {
mutex_lock(&zonelists_mutex);
build_all_zonelists(NULL, NULL);
mutex_unlock(&zonelists_mutex);
}
}
out:
mutex_unlock(&zl_order_mutex);
return ret;
}
static int find_next_best_node(int node, nodemask_t *used_node_mask)
{
int n, val;
int min_val = INT_MAX;
int best_node = NUMA_NO_NODE;
const struct cpumask *tmp = cpumask_of_node(0);
if (!node_isset(node, *used_node_mask)) {
node_set(node, *used_node_mask);
return node;
}
for_each_node_state(n, N_MEMORY) {
if (node_isset(n, *used_node_mask))
continue;
val = node_distance(node, n);
val += (n < node);
tmp = cpumask_of_node(n);
if (!cpumask_empty(tmp))
val += PENALTY_FOR_NODE_WITH_CPUS;
val *= (MAX_NODE_LOAD*MAX_NUMNODES);
val += node_load[n];
if (val < min_val) {
min_val = val;
best_node = n;
}
}
if (best_node >= 0)
node_set(best_node, *used_node_mask);
return best_node;
}
static void build_zonelists_in_node_order(pg_data_t *pgdat, int node)
{
int j;
struct zonelist *zonelist;
zonelist = &pgdat->node_zonelists[ZONELIST_FALLBACK];
for (j = 0; zonelist->_zonerefs[j].zone != NULL; j++)
;
j = build_zonelists_node(NODE_DATA(node), zonelist, j);
zonelist->_zonerefs[j].zone = NULL;
zonelist->_zonerefs[j].zone_idx = 0;
}
static void build_thisnode_zonelists(pg_data_t *pgdat)
{
int j;
struct zonelist *zonelist;
zonelist = &pgdat->node_zonelists[ZONELIST_NOFALLBACK];
j = build_zonelists_node(pgdat, zonelist, 0);
zonelist->_zonerefs[j].zone = NULL;
zonelist->_zonerefs[j].zone_idx = 0;
}
static void build_zonelists_in_zone_order(pg_data_t *pgdat, int nr_nodes)
{
int pos, j, node;
int zone_type;
struct zone *z;
struct zonelist *zonelist;
zonelist = &pgdat->node_zonelists[ZONELIST_FALLBACK];
pos = 0;
for (zone_type = MAX_NR_ZONES - 1; zone_type >= 0; zone_type--) {
for (j = 0; j < nr_nodes; j++) {
node = node_order[j];
z = &NODE_DATA(node)->node_zones[zone_type];
if (managed_zone(z)) {
zoneref_set_zone(z,
&zonelist->_zonerefs[pos++]);
check_highest_zone(zone_type);
}
}
}
zonelist->_zonerefs[pos].zone = NULL;
zonelist->_zonerefs[pos].zone_idx = 0;
}
static int default_zonelist_order(void)
{
return ZONELIST_ORDER_NODE;
}
static int default_zonelist_order(void)
{
return ZONELIST_ORDER_ZONE;
}
static void set_zonelist_order(void)
{
if (user_zonelist_order == ZONELIST_ORDER_DEFAULT)
current_zonelist_order = default_zonelist_order();
else
current_zonelist_order = user_zonelist_order;
}
static void build_zonelists(pg_data_t *pgdat)
{
int i, node, load;
nodemask_t used_mask;
int local_node, prev_node;
struct zonelist *zonelist;
unsigned int order = current_zonelist_order;
for (i = 0; i < MAX_ZONELISTS; i++) {
zonelist = pgdat->node_zonelists + i;
zonelist->_zonerefs[0].zone = NULL;
zonelist->_zonerefs[0].zone_idx = 0;
}
local_node = pgdat->node_id;
load = nr_online_nodes;
prev_node = local_node;
nodes_clear(used_mask);
memset(node_order, 0, sizeof(node_order));
i = 0;
while ((node = find_next_best_node(local_node, &used_mask)) >= 0) {
if (node_distance(local_node, node) !=
node_distance(local_node, prev_node))
node_load[node] = load;
prev_node = node;
load--;
if (order == ZONELIST_ORDER_NODE)
build_zonelists_in_node_order(pgdat, node);
else
node_order[i++] = node;
}
if (order == ZONELIST_ORDER_ZONE) {
build_zonelists_in_zone_order(pgdat, i);
}
build_thisnode_zonelists(pgdat);
}
int local_memory_node(int node)
{
struct zoneref *z;
z = first_zones_zonelist(node_zonelist(node, GFP_KERNEL),
gfp_zone(GFP_KERNEL),
NULL);
return z->zone->node;
}
static void set_zonelist_order(void)
{
current_zonelist_order = ZONELIST_ORDER_ZONE;
}
static void build_zonelists(pg_data_t *pgdat)
{
int node, local_node;
enum zone_type j;
struct zonelist *zonelist;
local_node = pgdat->node_id;
zonelist = &pgdat->node_zonelists[ZONELIST_FALLBACK];
j = build_zonelists_node(pgdat, zonelist, 0);
for (node = local_node + 1; node < MAX_NUMNODES; node++) {
if (!node_online(node))
continue;
j = build_zonelists_node(NODE_DATA(node), zonelist, j);
}
for (node = 0; node < local_node; node++) {
if (!node_online(node))
continue;
j = build_zonelists_node(NODE_DATA(node), zonelist, j);
}
zonelist->_zonerefs[j].zone = NULL;
zonelist->_zonerefs[j].zone_idx = 0;
}
static int __build_all_zonelists(void *data)
{
int nid;
int cpu;
pg_data_t *self = data;
#ifdef CONFIG_NUMA
memset(node_load, 0, sizeof(node_load));
#endif
if (self && !node_online(self->node_id)) {
build_zonelists(self);
}
for_each_online_node(nid) {
pg_data_t *pgdat = NODE_DATA(nid);
build_zonelists(pgdat);
}
for_each_possible_cpu(cpu) {
setup_pageset(&per_cpu(boot_pageset, cpu), 0);
#ifdef CONFIG_HAVE_MEMORYLESS_NODES
if (cpu_online(cpu))
set_cpu_numa_mem(cpu, local_memory_node(cpu_to_node(cpu)));
#endif
}
return 0;
}
static noinline void __init
build_all_zonelists_init(void)
{
__build_all_zonelists(NULL);
mminit_verify_zonelist();
cpuset_init_current_mems_allowed();
}
void __ref build_all_zonelists(pg_data_t *pgdat, struct zone *zone)
{
set_zonelist_order();
if (system_state == SYSTEM_BOOTING) {
build_all_zonelists_init();
} else {
#ifdef CONFIG_MEMORY_HOTPLUG
if (zone)
setup_zone_pageset(zone);
#endif
stop_machine(__build_all_zonelists, pgdat, NULL);
}
vm_total_pages = nr_free_pagecache_pages();
if (vm_total_pages < (pageblock_nr_pages * MIGRATE_TYPES))
page_group_by_mobility_disabled = 1;
else
page_group_by_mobility_disabled = 0;
pr_info("Built %i zonelists in %s order, mobility grouping %s. Total pages: %ld\n",
nr_online_nodes,
zonelist_order_name[current_zonelist_order],
page_group_by_mobility_disabled ? "off" : "on",
vm_total_pages);
#ifdef CONFIG_NUMA
pr_info("Policy zone: %s\n", zone_names[policy_zone]);
#endif
}
void __meminit memmap_init_zone(unsigned long size, int nid, unsigned long zone,
unsigned long start_pfn, enum memmap_context context)
{
struct vmem_altmap *altmap = to_vmem_altmap(__pfn_to_phys(start_pfn));
unsigned long end_pfn = start_pfn + size;
pg_data_t *pgdat = NODE_DATA(nid);
unsigned long pfn;
unsigned long nr_initialised = 0;
#ifdef CONFIG_HAVE_MEMBLOCK_NODE_MAP
struct memblock_region *r = NULL, *tmp;
#endif
if (highest_memmap_pfn < end_pfn - 1)
highest_memmap_pfn = end_pfn - 1;
if (altmap && start_pfn == altmap->base_pfn)
start_pfn += altmap->reserve;
for (pfn = start_pfn; pfn < end_pfn; pfn++) {
if (context != MEMMAP_EARLY)
goto not_early;
if (!early_pfn_valid(pfn))
continue;
if (!early_pfn_in_nid(pfn, nid))
continue;
if (!update_defer_init(pgdat, pfn, end_pfn, &nr_initialised))
break;
#ifdef CONFIG_HAVE_MEMBLOCK_NODE_MAP
if (mirrored_kernelcore && zone == ZONE_MOVABLE) {
if (!r || pfn >= memblock_region_memory_end_pfn(r)) {
for_each_memblock(memory, tmp)
if (pfn < memblock_region_memory_end_pfn(tmp))
break;
r = tmp;
}
if (pfn >= memblock_region_memory_base_pfn(r) &&
memblock_is_mirror(r)) {
pfn = memblock_region_memory_end_pfn(r);
continue;
}
}
#endif
not_early:
if (!(pfn & (pageblock_nr_pages - 1))) {
struct page *page = pfn_to_page(pfn);
__init_single_page(page, pfn, zone, nid);
set_pageblock_migratetype(page, MIGRATE_MOVABLE);
} else {
__init_single_pfn(pfn, zone, nid);
}
}
}
static void __meminit zone_init_free_lists(struct zone *zone)
{
unsigned int order, t;
for_each_migratetype_order(order, t) {
INIT_LIST_HEAD(&zone->free_area[order].free_list[t]);
zone->free_area[order].nr_free = 0;
}
}
static int zone_batchsize(struct zone *zone)
{
#ifdef CONFIG_MMU
int batch;
batch = zone->managed_pages / 1024;
if (batch * PAGE_SIZE > 512 * 1024)
batch = (512 * 1024) / PAGE_SIZE;
batch /= 4;
if (batch < 1)
batch = 1;
batch = rounddown_pow_of_two(batch + batch/2) - 1;
return batch;
#else
return 0;
#endif
}
static void pageset_update(struct per_cpu_pages *pcp, unsigned long high,
unsigned long batch)
{
pcp->batch = 1;
smp_wmb();
pcp->high = high;
smp_wmb();
pcp->batch = batch;
}
static void pageset_set_batch(struct per_cpu_pageset *p, unsigned long batch)
{
pageset_update(&p->pcp, 6 * batch, max(1UL, 1 * batch));
}
static void pageset_init(struct per_cpu_pageset *p)
{
struct per_cpu_pages *pcp;
int migratetype;
memset(p, 0, sizeof(*p));
pcp = &p->pcp;
pcp->count = 0;
for (migratetype = 0; migratetype < MIGRATE_PCPTYPES; migratetype++)
INIT_LIST_HEAD(&pcp->lists[migratetype]);
}
static void setup_pageset(struct per_cpu_pageset *p, unsigned long batch)
{
pageset_init(p);
pageset_set_batch(p, batch);
}
static void pageset_set_high(struct per_cpu_pageset *p,
unsigned long high)
{
unsigned long batch = max(1UL, high / 4);
if ((high / 4) > (PAGE_SHIFT * 8))
batch = PAGE_SHIFT * 8;
pageset_update(&p->pcp, high, batch);
}
static void pageset_set_high_and_batch(struct zone *zone,
struct per_cpu_pageset *pcp)
{
if (percpu_pagelist_fraction)
pageset_set_high(pcp,
(zone->managed_pages /
percpu_pagelist_fraction));
else
pageset_set_batch(pcp, zone_batchsize(zone));
}
static void __meminit zone_pageset_init(struct zone *zone, int cpu)
{
struct per_cpu_pageset *pcp = per_cpu_ptr(zone->pageset, cpu);
pageset_init(pcp);
pageset_set_high_and_batch(zone, pcp);
}
static void __meminit setup_zone_pageset(struct zone *zone)
{
int cpu;
zone->pageset = alloc_percpu(struct per_cpu_pageset);
for_each_possible_cpu(cpu)
zone_pageset_init(zone, cpu);
}
void __init setup_per_cpu_pageset(void)
{
struct pglist_data *pgdat;
struct zone *zone;
for_each_populated_zone(zone)
setup_zone_pageset(zone);
for_each_online_pgdat(pgdat)
pgdat->per_cpu_nodestats =
alloc_percpu(struct per_cpu_nodestat);
}
static __meminit void zone_pcp_init(struct zone *zone)
{
zone->pageset = &boot_pageset;
if (populated_zone(zone))
printk(KERN_DEBUG " %s zone: %lu pages, LIFO batch:%u\n",
zone->name, zone->present_pages,
zone_batchsize(zone));
}
int __meminit init_currently_empty_zone(struct zone *zone,
unsigned long zone_start_pfn,
unsigned long size)
{
struct pglist_data *pgdat = zone->zone_pgdat;
pgdat->nr_zones = zone_idx(zone) + 1;
zone->zone_start_pfn = zone_start_pfn;
mminit_dprintk(MMINIT_TRACE, "memmap_init",
"Initialising map node %d zone %lu pfns %lu -> %lu\n",
pgdat->node_id,
(unsigned long)zone_idx(zone),
zone_start_pfn, (zone_start_pfn + size));
zone_init_free_lists(zone);
zone->initialized = 1;
return 0;
}
int __meminit __early_pfn_to_nid(unsigned long pfn,
struct mminit_pfnnid_cache *state)
{
unsigned long start_pfn, end_pfn;
int nid;
if (state->last_start <= pfn && pfn < state->last_end)
return state->last_nid;
nid = memblock_search_pfn_nid(pfn, &start_pfn, &end_pfn);
if (nid != -1) {
state->last_start = start_pfn;
state->last_end = end_pfn;
state->last_nid = nid;
}
return nid;
}
void __init free_bootmem_with_active_regions(int nid, unsigned long max_low_pfn)
{
unsigned long start_pfn, end_pfn;
int i, this_nid;
for_each_mem_pfn_range(i, nid, &start_pfn, &end_pfn, &this_nid) {
start_pfn = min(start_pfn, max_low_pfn);
end_pfn = min(end_pfn, max_low_pfn);
if (start_pfn < end_pfn)
memblock_free_early_nid(PFN_PHYS(start_pfn),
(end_pfn - start_pfn) << PAGE_SHIFT,
this_nid);
}
}
void __init sparse_memory_present_with_active_regions(int nid)
{
unsigned long start_pfn, end_pfn;
int i, this_nid;
for_each_mem_pfn_range(i, nid, &start_pfn, &end_pfn, &this_nid)
memory_present(this_nid, start_pfn, end_pfn);
}
void __meminit get_pfn_range_for_nid(unsigned int nid,
unsigned long *start_pfn, unsigned long *end_pfn)
{
unsigned long this_start_pfn, this_end_pfn;
int i;
*start_pfn = -1UL;
*end_pfn = 0;
for_each_mem_pfn_range(i, nid, &this_start_pfn, &this_end_pfn, NULL) {
*start_pfn = min(*start_pfn, this_start_pfn);
*end_pfn = max(*end_pfn, this_end_pfn);
}
if (*start_pfn == -1UL)
*start_pfn = 0;
}
static void __init find_usable_zone_for_movable(void)
{
int zone_index;
for (zone_index = MAX_NR_ZONES - 1; zone_index >= 0; zone_index--) {
if (zone_index == ZONE_MOVABLE)
continue;
if (arch_zone_highest_possible_pfn[zone_index] >
arch_zone_lowest_possible_pfn[zone_index])
break;
}
VM_BUG_ON(zone_index == -1);
movable_zone = zone_index;
}
static void __meminit adjust_zone_range_for_zone_movable(int nid,
unsigned long zone_type,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *zone_start_pfn,
unsigned long *zone_end_pfn)
{
if (zone_movable_pfn[nid]) {
if (zone_type == ZONE_MOVABLE) {
*zone_start_pfn = zone_movable_pfn[nid];
*zone_end_pfn = min(node_end_pfn,
arch_zone_highest_possible_pfn[movable_zone]);
} else if (!mirrored_kernelcore &&
*zone_start_pfn < zone_movable_pfn[nid] &&
*zone_end_pfn > zone_movable_pfn[nid]) {
*zone_end_pfn = zone_movable_pfn[nid];
} else if (*zone_start_pfn >= zone_movable_pfn[nid])
*zone_start_pfn = *zone_end_pfn;
}
}
static unsigned long __meminit zone_spanned_pages_in_node(int nid,
unsigned long zone_type,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *zone_start_pfn,
unsigned long *zone_end_pfn,
unsigned long *ignored)
{
if (!node_start_pfn && !node_end_pfn)
return 0;
*zone_start_pfn = arch_zone_lowest_possible_pfn[zone_type];
*zone_end_pfn = arch_zone_highest_possible_pfn[zone_type];
adjust_zone_range_for_zone_movable(nid, zone_type,
node_start_pfn, node_end_pfn,
zone_start_pfn, zone_end_pfn);
if (*zone_end_pfn < node_start_pfn || *zone_start_pfn > node_end_pfn)
return 0;
*zone_end_pfn = min(*zone_end_pfn, node_end_pfn);
*zone_start_pfn = max(*zone_start_pfn, node_start_pfn);
return *zone_end_pfn - *zone_start_pfn;
}
unsigned long __meminit __absent_pages_in_range(int nid,
unsigned long range_start_pfn,
unsigned long range_end_pfn)
{
unsigned long nr_absent = range_end_pfn - range_start_pfn;
unsigned long start_pfn, end_pfn;
int i;
for_each_mem_pfn_range(i, nid, &start_pfn, &end_pfn, NULL) {
start_pfn = clamp(start_pfn, range_start_pfn, range_end_pfn);
end_pfn = clamp(end_pfn, range_start_pfn, range_end_pfn);
nr_absent -= end_pfn - start_pfn;
}
return nr_absent;
}
unsigned long __init absent_pages_in_range(unsigned long start_pfn,
unsigned long end_pfn)
{
return __absent_pages_in_range(MAX_NUMNODES, start_pfn, end_pfn);
}
static unsigned long __meminit zone_absent_pages_in_node(int nid,
unsigned long zone_type,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *ignored)
{
unsigned long zone_low = arch_zone_lowest_possible_pfn[zone_type];
unsigned long zone_high = arch_zone_highest_possible_pfn[zone_type];
unsigned long zone_start_pfn, zone_end_pfn;
unsigned long nr_absent;
if (!node_start_pfn && !node_end_pfn)
return 0;
zone_start_pfn = clamp(node_start_pfn, zone_low, zone_high);
zone_end_pfn = clamp(node_end_pfn, zone_low, zone_high);
adjust_zone_range_for_zone_movable(nid, zone_type,
node_start_pfn, node_end_pfn,
&zone_start_pfn, &zone_end_pfn);
nr_absent = __absent_pages_in_range(nid, zone_start_pfn, zone_end_pfn);
if (mirrored_kernelcore && zone_movable_pfn[nid]) {
unsigned long start_pfn, end_pfn;
struct memblock_region *r;
for_each_memblock(memory, r) {
start_pfn = clamp(memblock_region_memory_base_pfn(r),
zone_start_pfn, zone_end_pfn);
end_pfn = clamp(memblock_region_memory_end_pfn(r),
zone_start_pfn, zone_end_pfn);
if (zone_type == ZONE_MOVABLE &&
memblock_is_mirror(r))
nr_absent += end_pfn - start_pfn;
if (zone_type == ZONE_NORMAL &&
!memblock_is_mirror(r))
nr_absent += end_pfn - start_pfn;
}
}
return nr_absent;
}
static inline unsigned long __meminit zone_spanned_pages_in_node(int nid,
unsigned long zone_type,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *zone_start_pfn,
unsigned long *zone_end_pfn,
unsigned long *zones_size)
{
unsigned int zone;
*zone_start_pfn = node_start_pfn;
for (zone = 0; zone < zone_type; zone++)
*zone_start_pfn += zones_size[zone];
*zone_end_pfn = *zone_start_pfn + zones_size[zone_type];
return zones_size[zone_type];
}
static inline unsigned long __meminit zone_absent_pages_in_node(int nid,
unsigned long zone_type,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *zholes_size)
{
if (!zholes_size)
return 0;
return zholes_size[zone_type];
}
static void __meminit calculate_node_totalpages(struct pglist_data *pgdat,
unsigned long node_start_pfn,
unsigned long node_end_pfn,
unsigned long *zones_size,
unsigned long *zholes_size)
{
unsigned long realtotalpages = 0, totalpages = 0;
enum zone_type i;
for (i = 0; i < MAX_NR_ZONES; i++) {
struct zone *zone = pgdat->node_zones + i;
unsigned long zone_start_pfn, zone_end_pfn;
unsigned long size, real_size;
size = zone_spanned_pages_in_node(pgdat->node_id, i,
node_start_pfn,
node_end_pfn,
&zone_start_pfn,
&zone_end_pfn,
zones_size);
real_size = size - zone_absent_pages_in_node(pgdat->node_id, i,
node_start_pfn, node_end_pfn,
zholes_size);
if (size)
zone->zone_start_pfn = zone_start_pfn;
else
zone->zone_start_pfn = 0;
zone->spanned_pages = size;
zone->present_pages = real_size;
totalpages += size;
realtotalpages += real_size;
}
pgdat->node_spanned_pages = totalpages;
pgdat->node_present_pages = realtotalpages;
printk(KERN_DEBUG "On node %d totalpages: %lu\n", pgdat->node_id,
realtotalpages);
}
static unsigned long __init usemap_size(unsigned long zone_start_pfn, unsigned long zonesize)
{
unsigned long usemapsize;
zonesize += zone_start_pfn & (pageblock_nr_pages-1);
usemapsize = roundup(zonesize, pageblock_nr_pages);
usemapsize = usemapsize >> pageblock_order;
usemapsize *= NR_PAGEBLOCK_BITS;
usemapsize = roundup(usemapsize, 8 * sizeof(unsigned long));
return usemapsize / 8;
}
static void __init setup_usemap(struct pglist_data *pgdat,
struct zone *zone,
unsigned long zone_start_pfn,
unsigned long zonesize)
{
unsigned long usemapsize = usemap_size(zone_start_pfn, zonesize);
zone->pageblock_flags = NULL;
if (usemapsize)
zone->pageblock_flags =
memblock_virt_alloc_node_nopanic(usemapsize,
pgdat->node_id);
}
static inline void setup_usemap(struct pglist_data *pgdat, struct zone *zone,
unsigned long zone_start_pfn, unsigned long zonesize) {}
void __paginginit set_pageblock_order(void)
{
unsigned int order;
if (pageblock_order)
return;
if (HPAGE_SHIFT > PAGE_SHIFT)
order = HUGETLB_PAGE_ORDER;
else
order = MAX_ORDER - 1;
pageblock_order = order;
}
void __paginginit set_pageblock_order(void)
{
}
static unsigned long __paginginit calc_memmap_size(unsigned long spanned_pages,
unsigned long present_pages)
{
unsigned long pages = spanned_pages;
if (spanned_pages > present_pages + (present_pages >> 4) &&
IS_ENABLED(CONFIG_SPARSEMEM))
pages = present_pages;
return PAGE_ALIGN(pages * sizeof(struct page)) >> PAGE_SHIFT;
}
static void __paginginit free_area_init_core(struct pglist_data *pgdat)
{
enum zone_type j;
int nid = pgdat->node_id;
int ret;
pgdat_resize_init(pgdat);
#ifdef CONFIG_NUMA_BALANCING
spin_lock_init(&pgdat->numabalancing_migrate_lock);
pgdat->numabalancing_migrate_nr_pages = 0;
pgdat->numabalancing_migrate_next_window = jiffies;
#endif
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
spin_lock_init(&pgdat->split_queue_lock);
INIT_LIST_HEAD(&pgdat->split_queue);
pgdat->split_queue_len = 0;
#endif
init_waitqueue_head(&pgdat->kswapd_wait);
init_waitqueue_head(&pgdat->pfmemalloc_wait);
#ifdef CONFIG_COMPACTION
init_waitqueue_head(&pgdat->kcompactd_wait);
#endif
pgdat_page_ext_init(pgdat);
spin_lock_init(&pgdat->lru_lock);
lruvec_init(node_lruvec(pgdat));
for (j = 0; j < MAX_NR_ZONES; j++) {
struct zone *zone = pgdat->node_zones + j;
unsigned long size, realsize, freesize, memmap_pages;
unsigned long zone_start_pfn = zone->zone_start_pfn;
size = zone->spanned_pages;
realsize = freesize = zone->present_pages;
memmap_pages = calc_memmap_size(size, realsize);
if (!is_highmem_idx(j)) {
if (freesize >= memmap_pages) {
freesize -= memmap_pages;
if (memmap_pages)
printk(KERN_DEBUG
" %s zone: %lu pages used for memmap\n",
zone_names[j], memmap_pages);
} else
pr_warn(" %s zone: %lu pages exceeds freesize %lu\n",
zone_names[j], memmap_pages, freesize);
}
if (j == 0 && freesize > dma_reserve) {
freesize -= dma_reserve;
printk(KERN_DEBUG " %s zone: %lu pages reserved\n",
zone_names[0], dma_reserve);
}
if (!is_highmem_idx(j))
nr_kernel_pages += freesize;
else if (nr_kernel_pages > memmap_pages * 2)
nr_kernel_pages -= memmap_pages;
nr_all_pages += freesize;
zone->managed_pages = is_highmem_idx(j) ? realsize : freesize;
#ifdef CONFIG_NUMA
zone->node = nid;
#endif
zone->name = zone_names[j];
zone->zone_pgdat = pgdat;
spin_lock_init(&zone->lock);
zone_seqlock_init(zone);
zone_pcp_init(zone);
if (!size)
continue;
set_pageblock_order();
setup_usemap(pgdat, zone, zone_start_pfn, size);
ret = init_currently_empty_zone(zone, zone_start_pfn, size);
BUG_ON(ret);
memmap_init(size, nid, j, zone_start_pfn);
}
}
static void __ref alloc_node_mem_map(struct pglist_data *pgdat)
{
unsigned long __maybe_unused start = 0;
unsigned long __maybe_unused offset = 0;
if (!pgdat->node_spanned_pages)
return;
#ifdef CONFIG_FLAT_NODE_MEM_MAP
start = pgdat->node_start_pfn & ~(MAX_ORDER_NR_PAGES - 1);
offset = pgdat->node_start_pfn - start;
if (!pgdat->node_mem_map) {
unsigned long size, end;
struct page *map;
end = pgdat_end_pfn(pgdat);
end = ALIGN(end, MAX_ORDER_NR_PAGES);
size = (end - start) * sizeof(struct page);
map = alloc_remap(pgdat->node_id, size);
if (!map)
map = memblock_virt_alloc_node_nopanic(size,
pgdat->node_id);
pgdat->node_mem_map = map + offset;
}
#ifndef CONFIG_NEED_MULTIPLE_NODES
if (pgdat == NODE_DATA(0)) {
mem_map = NODE_DATA(0)->node_mem_map;
#if defined(CONFIG_HAVE_MEMBLOCK_NODE_MAP) || defined(CONFIG_FLATMEM)
if (page_to_pfn(mem_map) != pgdat->node_start_pfn)
mem_map -= offset;
#endif
}
#endif
#endif
}
void __paginginit free_area_init_node(int nid, unsigned long *zones_size,
unsigned long node_start_pfn, unsigned long *zholes_size)
{
pg_data_t *pgdat = NODE_DATA(nid);
unsigned long start_pfn = 0;
unsigned long end_pfn = 0;
WARN_ON(pgdat->nr_zones || pgdat->kswapd_classzone_idx);
reset_deferred_meminit(pgdat);
pgdat->node_id = nid;
pgdat->node_start_pfn = node_start_pfn;
pgdat->per_cpu_nodestats = NULL;
#ifdef CONFIG_HAVE_MEMBLOCK_NODE_MAP
get_pfn_range_for_nid(nid, &start_pfn, &end_pfn);
pr_info("Initmem setup node %d [mem %#018Lx-%#018Lx]\n", nid,
(u64)start_pfn << PAGE_SHIFT,
end_pfn ? ((u64)end_pfn << PAGE_SHIFT) - 1 : 0);
#else
start_pfn = node_start_pfn;
#endif
calculate_node_totalpages(pgdat, start_pfn, end_pfn,
zones_size, zholes_size);
alloc_node_mem_map(pgdat);
#ifdef CONFIG_FLAT_NODE_MEM_MAP
printk(KERN_DEBUG "free_area_init_node: node %d, pgdat %08lx, node_mem_map %08lx\n",
nid, (unsigned long)pgdat,
(unsigned long)pgdat->node_mem_map);
#endif
free_area_init_core(pgdat);
}
void __init setup_nr_node_ids(void)
{
unsigned int highest;
highest = find_last_bit(node_possible_map.bits, MAX_NUMNODES);
nr_node_ids = highest + 1;
}
unsigned long __init node_map_pfn_alignment(void)
{
unsigned long accl_mask = 0, last_end = 0;
unsigned long start, end, mask;
int last_nid = -1;
int i, nid;
for_each_mem_pfn_range(i, MAX_NUMNODES, &start, &end, &nid) {
if (!start || last_nid < 0 || last_nid == nid) {
last_nid = nid;
last_end = end;
continue;
}
mask = ~((1 << __ffs(start)) - 1);
while (mask && last_end <= (start & (mask << 1)))
mask <<= 1;
accl_mask |= mask;
}
return ~accl_mask + 1;
}
static unsigned long __init find_min_pfn_for_node(int nid)
{
unsigned long min_pfn = ULONG_MAX;
unsigned long start_pfn;
int i;
for_each_mem_pfn_range(i, nid, &start_pfn, NULL, NULL)
min_pfn = min(min_pfn, start_pfn);
if (min_pfn == ULONG_MAX) {
pr_warn("Could not find start_pfn for node %d\n", nid);
return 0;
}
return min_pfn;
}
unsigned long __init find_min_pfn_with_active_regions(void)
{
return find_min_pfn_for_node(MAX_NUMNODES);
}
static unsigned long __init early_calculate_totalpages(void)
{
unsigned long totalpages = 0;
unsigned long start_pfn, end_pfn;
int i, nid;
for_each_mem_pfn_range(i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long pages = end_pfn - start_pfn;
totalpages += pages;
if (pages)
node_set_state(nid, N_MEMORY);
}
return totalpages;
}
static void __init find_zone_movable_pfns_for_nodes(void)
{
int i, nid;
unsigned long usable_startpfn;
unsigned long kernelcore_node, kernelcore_remaining;
nodemask_t saved_node_state = node_states[N_MEMORY];
unsigned long totalpages = early_calculate_totalpages();
int usable_nodes = nodes_weight(node_states[N_MEMORY]);
struct memblock_region *r;
find_usable_zone_for_movable();
if (movable_node_is_enabled()) {
for_each_memblock(memory, r) {
if (!memblock_is_hotpluggable(r))
continue;
nid = r->nid;
usable_startpfn = PFN_DOWN(r->base);
zone_movable_pfn[nid] = zone_movable_pfn[nid] ?
min(usable_startpfn, zone_movable_pfn[nid]) :
usable_startpfn;
}
goto out2;
}
if (mirrored_kernelcore) {
bool mem_below_4gb_not_mirrored = false;
for_each_memblock(memory, r) {
if (memblock_is_mirror(r))
continue;
nid = r->nid;
usable_startpfn = memblock_region_memory_base_pfn(r);
if (usable_startpfn < 0x100000) {
mem_below_4gb_not_mirrored = true;
continue;
}
zone_movable_pfn[nid] = zone_movable_pfn[nid] ?
min(usable_startpfn, zone_movable_pfn[nid]) :
usable_startpfn;
}
if (mem_below_4gb_not_mirrored)
pr_warn("This configuration results in unmirrored kernel memory.");
goto out2;
}
if (required_movablecore) {
unsigned long corepages;
required_movablecore =
roundup(required_movablecore, MAX_ORDER_NR_PAGES);
required_movablecore = min(totalpages, required_movablecore);
corepages = totalpages - required_movablecore;
required_kernelcore = max(required_kernelcore, corepages);
}
if (!required_kernelcore || required_kernelcore >= totalpages)
goto out;
usable_startpfn = arch_zone_lowest_possible_pfn[movable_zone];
restart:
kernelcore_node = required_kernelcore / usable_nodes;
for_each_node_state(nid, N_MEMORY) {
unsigned long start_pfn, end_pfn;
if (required_kernelcore < kernelcore_node)
kernelcore_node = required_kernelcore / usable_nodes;
kernelcore_remaining = kernelcore_node;
for_each_mem_pfn_range(i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long size_pages;
start_pfn = max(start_pfn, zone_movable_pfn[nid]);
if (start_pfn >= end_pfn)
continue;
if (start_pfn < usable_startpfn) {
unsigned long kernel_pages;
kernel_pages = min(end_pfn, usable_startpfn)
- start_pfn;
kernelcore_remaining -= min(kernel_pages,
kernelcore_remaining);
required_kernelcore -= min(kernel_pages,
required_kernelcore);
if (end_pfn <= usable_startpfn) {
zone_movable_pfn[nid] = end_pfn;
continue;
}
start_pfn = usable_startpfn;
}
size_pages = end_pfn - start_pfn;
if (size_pages > kernelcore_remaining)
size_pages = kernelcore_remaining;
zone_movable_pfn[nid] = start_pfn + size_pages;
required_kernelcore -= min(required_kernelcore,
size_pages);
kernelcore_remaining -= size_pages;
if (!kernelcore_remaining)
break;
}
}
usable_nodes--;
if (usable_nodes && required_kernelcore > usable_nodes)
goto restart;
out2:
for (nid = 0; nid < MAX_NUMNODES; nid++)
zone_movable_pfn[nid] =
roundup(zone_movable_pfn[nid], MAX_ORDER_NR_PAGES);
out:
node_states[N_MEMORY] = saved_node_state;
}
static void check_for_memory(pg_data_t *pgdat, int nid)
{
enum zone_type zone_type;
if (N_MEMORY == N_NORMAL_MEMORY)
return;
for (zone_type = 0; zone_type <= ZONE_MOVABLE - 1; zone_type++) {
struct zone *zone = &pgdat->node_zones[zone_type];
if (populated_zone(zone)) {
node_set_state(nid, N_HIGH_MEMORY);
if (N_NORMAL_MEMORY != N_HIGH_MEMORY &&
zone_type <= ZONE_NORMAL)
node_set_state(nid, N_NORMAL_MEMORY);
break;
}
}
}
void __init free_area_init_nodes(unsigned long *max_zone_pfn)
{
unsigned long start_pfn, end_pfn;
int i, nid;
memset(arch_zone_lowest_possible_pfn, 0,
sizeof(arch_zone_lowest_possible_pfn));
memset(arch_zone_highest_possible_pfn, 0,
sizeof(arch_zone_highest_possible_pfn));
start_pfn = find_min_pfn_with_active_regions();
for (i = 0; i < MAX_NR_ZONES; i++) {
if (i == ZONE_MOVABLE)
continue;
end_pfn = max(max_zone_pfn[i], start_pfn);
arch_zone_lowest_possible_pfn[i] = start_pfn;
arch_zone_highest_possible_pfn[i] = end_pfn;
start_pfn = end_pfn;
}
arch_zone_lowest_possible_pfn[ZONE_MOVABLE] = 0;
arch_zone_highest_possible_pfn[ZONE_MOVABLE] = 0;
memset(zone_movable_pfn, 0, sizeof(zone_movable_pfn));
find_zone_movable_pfns_for_nodes();
pr_info("Zone ranges:\n");
for (i = 0; i < MAX_NR_ZONES; i++) {
if (i == ZONE_MOVABLE)
continue;
pr_info(" %-8s ", zone_names[i]);
if (arch_zone_lowest_possible_pfn[i] ==
arch_zone_highest_possible_pfn[i])
pr_cont("empty\n");
else
pr_cont("[mem %#018Lx-%#018Lx]\n",
(u64)arch_zone_lowest_possible_pfn[i]
<< PAGE_SHIFT,
((u64)arch_zone_highest_possible_pfn[i]
<< PAGE_SHIFT) - 1);
}
pr_info("Movable zone start for each node\n");
for (i = 0; i < MAX_NUMNODES; i++) {
if (zone_movable_pfn[i])
pr_info(" Node %d: %#018Lx\n", i,
(u64)zone_movable_pfn[i] << PAGE_SHIFT);
}
pr_info("Early memory node ranges\n");
for_each_mem_pfn_range(i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
pr_info(" node %3d: [mem %#018Lx-%#018Lx]\n", nid,
(u64)start_pfn << PAGE_SHIFT,
((u64)end_pfn << PAGE_SHIFT) - 1);
mminit_verify_pageflags_layout();
setup_nr_node_ids();
for_each_online_node(nid) {
pg_data_t *pgdat = NODE_DATA(nid);
free_area_init_node(nid, NULL,
find_min_pfn_for_node(nid), NULL);
if (pgdat->node_present_pages)
node_set_state(nid, N_MEMORY);
check_for_memory(pgdat, nid);
}
}
static int __init cmdline_parse_core(char *p, unsigned long *core)
{
unsigned long long coremem;
if (!p)
return -EINVAL;
coremem = memparse(p, &p);
*core = coremem >> PAGE_SHIFT;
WARN_ON((coremem >> PAGE_SHIFT) > ULONG_MAX);
return 0;
}
static int __init cmdline_parse_kernelcore(char *p)
{
if (parse_option_str(p, "mirror")) {
mirrored_kernelcore = true;
return 0;
}
return cmdline_parse_core(p, &required_kernelcore);
}
static int __init cmdline_parse_movablecore(char *p)
{
return cmdline_parse_core(p, &required_movablecore);
}
void adjust_managed_page_count(struct page *page, long count)
{
spin_lock(&managed_page_count_lock);
page_zone(page)->managed_pages += count;
totalram_pages += count;
#ifdef CONFIG_HIGHMEM
if (PageHighMem(page))
totalhigh_pages += count;
#endif
spin_unlock(&managed_page_count_lock);
}
unsigned long free_reserved_area(void *start, void *end, int poison, char *s)
{
void *pos;
unsigned long pages = 0;
start = (void *)PAGE_ALIGN((unsigned long)start);
end = (void *)((unsigned long)end & PAGE_MASK);
for (pos = start; pos < end; pos += PAGE_SIZE, pages++) {
if ((unsigned int)poison <= 0xFF)
memset(pos, poison, PAGE_SIZE);
free_reserved_page(virt_to_page(pos));
}
if (pages && s)
pr_info("Freeing %s memory: %ldK\n",
s, pages << (PAGE_SHIFT - 10));
return pages;
}
void free_highmem_page(struct page *page)
{
__free_reserved_page(page);
totalram_pages++;
page_zone(page)->managed_pages++;
totalhigh_pages++;
}
void __init mem_init_print_info(const char *str)
{
unsigned long physpages, codesize, datasize, rosize, bss_size;
unsigned long init_code_size, init_data_size;
physpages = get_num_physpages();
codesize = _etext - _stext;
datasize = _edata - _sdata;
rosize = __end_rodata - __start_rodata;
bss_size = __bss_stop - __bss_start;
init_data_size = __init_end - __init_begin;
init_code_size = _einittext - _sinittext;
#define adj_init_size(start, end, size, pos, adj) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
adj_init_size(__init_begin, __init_end, init_data_size,
_sinittext, init_code_size);
adj_init_size(_stext, _etext, codesize, _sinittext, init_code_size);
adj_init_size(_sdata, _edata, datasize, __init_begin, init_data_size);
adj_init_size(_stext, _etext, codesize, __start_rodata, rosize);
adj_init_size(_sdata, _edata, datasize, __start_rodata, rosize);
#undef adj_init_size
pr_info("Memory: %luK/%luK available (%luK kernel code, %luK rwdata, %luK rodata, %luK init, %luK bss, %luK reserved, %luK cma-reserved"
#ifdef CONFIG_HIGHMEM
", %luK highmem"
#endif
"%s%s)\n",
nr_free_pages() << (PAGE_SHIFT - 10),
physpages << (PAGE_SHIFT - 10),
codesize >> 10, datasize >> 10, rosize >> 10,
(init_data_size + init_code_size) >> 10, bss_size >> 10,
(physpages - totalram_pages - totalcma_pages) << (PAGE_SHIFT - 10),
totalcma_pages << (PAGE_SHIFT - 10),
#ifdef CONFIG_HIGHMEM
totalhigh_pages << (PAGE_SHIFT - 10),
#endif
str ? ", " : "", str ? str : "");
}
void __init set_dma_reserve(unsigned long new_dma_reserve)
{
dma_reserve = new_dma_reserve;
}
void __init free_area_init(unsigned long *zones_size)
{
free_area_init_node(0, zones_size,
__pa(PAGE_OFFSET) >> PAGE_SHIFT, NULL);
}
static int page_alloc_cpu_dead(unsigned int cpu)
{
lru_add_drain_cpu(cpu);
drain_pages(cpu);
vm_events_fold_cpu(cpu);
cpu_vm_stats_fold(cpu);
return 0;
}
void __init page_alloc_init(void)
{
int ret;
ret = cpuhp_setup_state_nocalls(CPUHP_PAGE_ALLOC_DEAD,
"mm/page_alloc:dead", NULL,
page_alloc_cpu_dead);
WARN_ON(ret < 0);
}
static void calculate_totalreserve_pages(void)
{
struct pglist_data *pgdat;
unsigned long reserve_pages = 0;
enum zone_type i, j;
for_each_online_pgdat(pgdat) {
pgdat->totalreserve_pages = 0;
for (i = 0; i < MAX_NR_ZONES; i++) {
struct zone *zone = pgdat->node_zones + i;
long max = 0;
for (j = i; j < MAX_NR_ZONES; j++) {
if (zone->lowmem_reserve[j] > max)
max = zone->lowmem_reserve[j];
}
max += high_wmark_pages(zone);
if (max > zone->managed_pages)
max = zone->managed_pages;
pgdat->totalreserve_pages += max;
reserve_pages += max;
}
}
totalreserve_pages = reserve_pages;
}
static void setup_per_zone_lowmem_reserve(void)
{
struct pglist_data *pgdat;
enum zone_type j, idx;
for_each_online_pgdat(pgdat) {
for (j = 0; j < MAX_NR_ZONES; j++) {
struct zone *zone = pgdat->node_zones + j;
unsigned long managed_pages = zone->managed_pages;
zone->lowmem_reserve[j] = 0;
idx = j;
while (idx) {
struct zone *lower_zone;
idx--;
if (sysctl_lowmem_reserve_ratio[idx] < 1)
sysctl_lowmem_reserve_ratio[idx] = 1;
lower_zone = pgdat->node_zones + idx;
lower_zone->lowmem_reserve[j] = managed_pages /
sysctl_lowmem_reserve_ratio[idx];
managed_pages += lower_zone->managed_pages;
}
}
}
calculate_totalreserve_pages();
}
static void __setup_per_zone_wmarks(void)
{
unsigned long pages_min = min_free_kbytes >> (PAGE_SHIFT - 10);
unsigned long lowmem_pages = 0;
struct zone *zone;
unsigned long flags;
for_each_zone(zone) {
if (!is_highmem(zone))
lowmem_pages += zone->managed_pages;
}
for_each_zone(zone) {
u64 tmp;
spin_lock_irqsave(&zone->lock, flags);
tmp = (u64)pages_min * zone->managed_pages;
do_div(tmp, lowmem_pages);
if (is_highmem(zone)) {
unsigned long min_pages;
min_pages = zone->managed_pages / 1024;
min_pages = clamp(min_pages, SWAP_CLUSTER_MAX, 128UL);
zone->watermark[WMARK_MIN] = min_pages;
} else {
zone->watermark[WMARK_MIN] = tmp;
}
tmp = max_t(u64, tmp >> 2,
mult_frac(zone->managed_pages,
watermark_scale_factor, 10000));
zone->watermark[WMARK_LOW] = min_wmark_pages(zone) + tmp;
zone->watermark[WMARK_HIGH] = min_wmark_pages(zone) + tmp * 2;
spin_unlock_irqrestore(&zone->lock, flags);
}
calculate_totalreserve_pages();
}
void setup_per_zone_wmarks(void)
{
mutex_lock(&zonelists_mutex);
__setup_per_zone_wmarks();
mutex_unlock(&zonelists_mutex);
}
int __meminit init_per_zone_wmark_min(void)
{
unsigned long lowmem_kbytes;
int new_min_free_kbytes;
lowmem_kbytes = nr_free_buffer_pages() * (PAGE_SIZE >> 10);
new_min_free_kbytes = int_sqrt(lowmem_kbytes * 16);
if (new_min_free_kbytes > user_min_free_kbytes) {
min_free_kbytes = new_min_free_kbytes;
if (min_free_kbytes < 128)
min_free_kbytes = 128;
if (min_free_kbytes > 65536)
min_free_kbytes = 65536;
} else {
pr_warn("min_free_kbytes is not updated to %d because user defined value %d is preferred\n",
new_min_free_kbytes, user_min_free_kbytes);
}
setup_per_zone_wmarks();
refresh_zone_stat_thresholds();
setup_per_zone_lowmem_reserve();
#ifdef CONFIG_NUMA
setup_min_unmapped_ratio();
setup_min_slab_ratio();
#endif
return 0;
}
int min_free_kbytes_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
int rc;
rc = proc_dointvec_minmax(table, write, buffer, length, ppos);
if (rc)
return rc;
if (write) {
user_min_free_kbytes = min_free_kbytes;
setup_per_zone_wmarks();
}
return 0;
}
int watermark_scale_factor_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
int rc;
rc = proc_dointvec_minmax(table, write, buffer, length, ppos);
if (rc)
return rc;
if (write)
setup_per_zone_wmarks();
return 0;
}
static void setup_min_unmapped_ratio(void)
{
pg_data_t *pgdat;
struct zone *zone;
for_each_online_pgdat(pgdat)
pgdat->min_unmapped_pages = 0;
for_each_zone(zone)
zone->zone_pgdat->min_unmapped_pages += (zone->managed_pages *
sysctl_min_unmapped_ratio) / 100;
}
int sysctl_min_unmapped_ratio_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
int rc;
rc = proc_dointvec_minmax(table, write, buffer, length, ppos);
if (rc)
return rc;
setup_min_unmapped_ratio();
return 0;
}
static void setup_min_slab_ratio(void)
{
pg_data_t *pgdat;
struct zone *zone;
for_each_online_pgdat(pgdat)
pgdat->min_slab_pages = 0;
for_each_zone(zone)
zone->zone_pgdat->min_slab_pages += (zone->managed_pages *
sysctl_min_slab_ratio) / 100;
}
int sysctl_min_slab_ratio_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
int rc;
rc = proc_dointvec_minmax(table, write, buffer, length, ppos);
if (rc)
return rc;
setup_min_slab_ratio();
return 0;
}
int lowmem_reserve_ratio_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
proc_dointvec_minmax(table, write, buffer, length, ppos);
setup_per_zone_lowmem_reserve();
return 0;
}
int percpu_pagelist_fraction_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
struct zone *zone;
int old_percpu_pagelist_fraction;
int ret;
mutex_lock(&pcp_batch_high_lock);
old_percpu_pagelist_fraction = percpu_pagelist_fraction;
ret = proc_dointvec_minmax(table, write, buffer, length, ppos);
if (!write || ret < 0)
goto out;
if (percpu_pagelist_fraction &&
percpu_pagelist_fraction < MIN_PERCPU_PAGELIST_FRACTION) {
percpu_pagelist_fraction = old_percpu_pagelist_fraction;
ret = -EINVAL;
goto out;
}
if (percpu_pagelist_fraction == old_percpu_pagelist_fraction)
goto out;
for_each_populated_zone(zone) {
unsigned int cpu;
for_each_possible_cpu(cpu)
pageset_set_high_and_batch(zone,
per_cpu_ptr(zone->pageset, cpu));
}
out:
mutex_unlock(&pcp_batch_high_lock);
return ret;
}
static int __init set_hashdist(char *str)
{
if (!str)
return 0;
hashdist = simple_strtoul(str, &str, 0);
return 1;
}
static unsigned long __init arch_reserved_kernel_pages(void)
{
return 0;
}
void *__init alloc_large_system_hash(const char *tablename,
unsigned long bucketsize,
unsigned long numentries,
int scale,
int flags,
unsigned int *_hash_shift,
unsigned int *_hash_mask,
unsigned long low_limit,
unsigned long high_limit)
{
unsigned long long max = high_limit;
unsigned long log2qty, size;
void *table = NULL;
if (!numentries) {
numentries = nr_kernel_pages;
numentries -= arch_reserved_kernel_pages();
if (PAGE_SHIFT < 20)
numentries = round_up(numentries, (1<<20)/PAGE_SIZE);
if (scale > PAGE_SHIFT)
numentries >>= (scale - PAGE_SHIFT);
else
numentries <<= (PAGE_SHIFT - scale);
if (unlikely(flags & HASH_SMALL)) {
WARN_ON(!(flags & HASH_EARLY));
if (!(numentries >> *_hash_shift)) {
numentries = 1UL << *_hash_shift;
BUG_ON(!numentries);
}
} else if (unlikely((numentries * bucketsize) < PAGE_SIZE))
numentries = PAGE_SIZE / bucketsize;
}
numentries = roundup_pow_of_two(numentries);
if (max == 0) {
max = ((unsigned long long)nr_all_pages << PAGE_SHIFT) >> 4;
do_div(max, bucketsize);
}
max = min(max, 0x80000000ULL);
if (numentries < low_limit)
numentries = low_limit;
if (numentries > max)
numentries = max;
log2qty = ilog2(numentries);
do {
size = bucketsize << log2qty;
if (flags & HASH_EARLY)
table = memblock_virt_alloc_nopanic(size, 0);
else if (hashdist)
table = __vmalloc(size, GFP_ATOMIC, PAGE_KERNEL);
else {
if (get_order(size) < MAX_ORDER) {
table = alloc_pages_exact(size, GFP_ATOMIC);
kmemleak_alloc(table, size, 1, GFP_ATOMIC);
}
}
} while (!table && size > PAGE_SIZE && --log2qty);
if (!table)
panic("Failed to allocate %s hash table\n", tablename);
pr_info("%s hash table entries: %ld (order: %d, %lu bytes)\n",
tablename, 1UL << log2qty, ilog2(size) - PAGE_SHIFT, size);
if (_hash_shift)
*_hash_shift = log2qty;
if (_hash_mask)
*_hash_mask = (1 << log2qty) - 1;
return table;
}
bool has_unmovable_pages(struct zone *zone, struct page *page, int count,
bool skip_hwpoisoned_pages)
{
unsigned long pfn, iter, found;
int mt;
if (zone_idx(zone) == ZONE_MOVABLE)
return false;
mt = get_pageblock_migratetype(page);
if (mt == MIGRATE_MOVABLE || is_migrate_cma(mt))
return false;
pfn = page_to_pfn(page);
for (found = 0, iter = 0; iter < pageblock_nr_pages; iter++) {
unsigned long check = pfn + iter;
if (!pfn_valid_within(check))
continue;
page = pfn_to_page(check);
if (PageHuge(page)) {
iter = round_up(iter + 1, 1<<compound_order(page)) - 1;
continue;
}
if (!page_ref_count(page)) {
if (PageBuddy(page))
iter += (1 << page_order(page)) - 1;
continue;
}
if (skip_hwpoisoned_pages && PageHWPoison(page))
continue;
if (!PageLRU(page))
found++;
if (found > count)
return true;
}
return false;
}
bool is_pageblock_removable_nolock(struct page *page)
{
struct zone *zone;
unsigned long pfn;
if (!node_online(page_to_nid(page)))
return false;
zone = page_zone(page);
pfn = page_to_pfn(page);
if (!zone_spans_pfn(zone, pfn))
return false;
return !has_unmovable_pages(zone, page, 0, true);
}
static unsigned long pfn_max_align_down(unsigned long pfn)
{
return pfn & ~(max_t(unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1);
}
static unsigned long pfn_max_align_up(unsigned long pfn)
{
return ALIGN(pfn, max_t(unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages));
}
static int __alloc_contig_migrate_range(struct compact_control *cc,
unsigned long start, unsigned long end)
{
unsigned long nr_reclaimed;
unsigned long pfn = start;
unsigned int tries = 0;
int ret = 0;
migrate_prep();
while (pfn < end || !list_empty(&cc->migratepages)) {
if (fatal_signal_pending(current)) {
ret = -EINTR;
break;
}
if (list_empty(&cc->migratepages)) {
cc->nr_migratepages = 0;
pfn = isolate_migratepages_range(cc, pfn, end);
if (!pfn) {
ret = -EINTR;
break;
}
tries = 0;
} else if (++tries == 5) {
ret = ret < 0 ? ret : -EBUSY;
break;
}
nr_reclaimed = reclaim_clean_pages_from_list(cc->zone,
&cc->migratepages);
cc->nr_migratepages -= nr_reclaimed;
ret = migrate_pages(&cc->migratepages, alloc_migrate_target,
NULL, 0, cc->mode, MR_CMA);
}
if (ret < 0) {
putback_movable_pages(&cc->migratepages);
return ret;
}
return 0;
}
int alloc_contig_range(unsigned long start, unsigned long end,
unsigned migratetype)
{
unsigned long outer_start, outer_end;
unsigned int order;
int ret = 0;
struct compact_control cc = {
.nr_migratepages = 0,
.order = -1,
.zone = page_zone(pfn_to_page(start)),
.mode = MIGRATE_SYNC,
.ignore_skip_hint = true,
.gfp_mask = GFP_KERNEL,
};
INIT_LIST_HEAD(&cc.migratepages);
ret = start_isolate_page_range(pfn_max_align_down(start),
pfn_max_align_up(end), migratetype,
false);
if (ret)
return ret;
ret = __alloc_contig_migrate_range(&cc, start, end);
if (ret && ret != -EBUSY)
goto done;
lru_add_drain_all();
drain_all_pages(cc.zone);
order = 0;
outer_start = start;
while (!PageBuddy(pfn_to_page(outer_start))) {
if (++order >= MAX_ORDER) {
outer_start = start;
break;
}
outer_start &= ~0UL << order;
}
if (outer_start != start) {
order = page_order(pfn_to_page(outer_start));
if (outer_start + (1UL << order) <= start)
outer_start = start;
}
if (test_pages_isolated(outer_start, end, false)) {
pr_info("%s: [%lx, %lx) PFNs busy\n",
__func__, outer_start, end);
ret = -EBUSY;
goto done;
}
outer_end = isolate_freepages_range(&cc, outer_start, end);
if (!outer_end) {
ret = -EBUSY;
goto done;
}
if (start != outer_start)
free_contig_range(outer_start, start - outer_start);
if (end != outer_end)
free_contig_range(end, outer_end - end);
done:
undo_isolate_page_range(pfn_max_align_down(start),
pfn_max_align_up(end), migratetype);
return ret;
}
void free_contig_range(unsigned long pfn, unsigned nr_pages)
{
unsigned int count = 0;
for (; nr_pages--; pfn++) {
struct page *page = pfn_to_page(pfn);
count += page_count(page) != 1;
__free_page(page);
}
WARN(count != 0, "%d pages are still in use!\n", count);
}
void __meminit zone_pcp_update(struct zone *zone)
{
unsigned cpu;
mutex_lock(&pcp_batch_high_lock);
for_each_possible_cpu(cpu)
pageset_set_high_and_batch(zone,
per_cpu_ptr(zone->pageset, cpu));
mutex_unlock(&pcp_batch_high_lock);
}
void zone_pcp_reset(struct zone *zone)
{
unsigned long flags;
int cpu;
struct per_cpu_pageset *pset;
local_irq_save(flags);
if (zone->pageset != &boot_pageset) {
for_each_online_cpu(cpu) {
pset = per_cpu_ptr(zone->pageset, cpu);
drain_zonestat(zone, pset);
}
free_percpu(zone->pageset);
zone->pageset = &boot_pageset;
}
local_irq_restore(flags);
}
void
__offline_isolated_pages(unsigned long start_pfn, unsigned long end_pfn)
{
struct page *page;
struct zone *zone;
unsigned int order, i;
unsigned long pfn;
unsigned long flags;
for (pfn = start_pfn; pfn < end_pfn; pfn++)
if (pfn_valid(pfn))
break;
if (pfn == end_pfn)
return;
zone = page_zone(pfn_to_page(pfn));
spin_lock_irqsave(&zone->lock, flags);
pfn = start_pfn;
while (pfn < end_pfn) {
if (!pfn_valid(pfn)) {
pfn++;
continue;
}
page = pfn_to_page(pfn);
if (unlikely(!PageBuddy(page) && PageHWPoison(page))) {
pfn++;
SetPageReserved(page);
continue;
}
BUG_ON(page_count(page));
BUG_ON(!PageBuddy(page));
order = page_order(page);
#ifdef CONFIG_DEBUG_VM
pr_info("remove from free list %lx %d %lx\n",
pfn, 1 << order, end_pfn);
#endif
list_del(&page->lru);
rmv_page_order(page);
zone->free_area[order].nr_free--;
for (i = 0; i < (1 << order); i++)
SetPageReserved((page+i));
pfn += (1 << order);
}
spin_unlock_irqrestore(&zone->lock, flags);
}
bool is_free_buddy_page(struct page *page)
{
struct zone *zone = page_zone(page);
unsigned long pfn = page_to_pfn(page);
unsigned long flags;
unsigned int order;
spin_lock_irqsave(&zone->lock, flags);
for (order = 0; order < MAX_ORDER; order++) {
struct page *page_head = page - (pfn & ((1 << order) - 1));
if (PageBuddy(page_head) && page_order(page_head) >= order)
break;
}
spin_unlock_irqrestore(&zone->lock, flags);
return order < MAX_ORDER;
}
