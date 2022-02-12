void get_online_mems(void)
{
might_sleep();
if (mem_hotplug.active_writer == current)
return;
memhp_lock_acquire_read();
mutex_lock(&mem_hotplug.lock);
mem_hotplug.refcount++;
mutex_unlock(&mem_hotplug.lock);
}
void put_online_mems(void)
{
if (mem_hotplug.active_writer == current)
return;
mutex_lock(&mem_hotplug.lock);
if (WARN_ON(!mem_hotplug.refcount))
mem_hotplug.refcount++;
if (!--mem_hotplug.refcount && unlikely(mem_hotplug.active_writer))
wake_up_process(mem_hotplug.active_writer);
mutex_unlock(&mem_hotplug.lock);
memhp_lock_release();
}
static void mem_hotplug_begin(void)
{
mem_hotplug.active_writer = current;
memhp_lock_acquire();
for (;;) {
mutex_lock(&mem_hotplug.lock);
if (likely(!mem_hotplug.refcount))
break;
__set_current_state(TASK_UNINTERRUPTIBLE);
mutex_unlock(&mem_hotplug.lock);
schedule();
}
}
static void mem_hotplug_done(void)
{
mem_hotplug.active_writer = NULL;
mutex_unlock(&mem_hotplug.lock);
memhp_lock_release();
}
static struct resource *register_memory_resource(u64 start, u64 size)
{
struct resource *res;
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
BUG_ON(!res);
res->name = "System RAM";
res->start = start;
res->end = start + size - 1;
res->flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (request_resource(&iomem_resource, res) < 0) {
pr_debug("System RAM resource %pR cannot be added\n", res);
kfree(res);
res = NULL;
}
return res;
}
static void release_memory_resource(struct resource *res)
{
if (!res)
return;
release_resource(res);
kfree(res);
return;
}
void get_page_bootmem(unsigned long info, struct page *page,
unsigned long type)
{
page->lru.next = (struct list_head *) type;
SetPagePrivate(page);
set_page_private(page, info);
atomic_inc(&page->_count);
}
void put_page_bootmem(struct page *page)
{
unsigned long type;
type = (unsigned long) page->lru.next;
BUG_ON(type < MEMORY_HOTPLUG_MIN_BOOTMEM_TYPE ||
type > MEMORY_HOTPLUG_MAX_BOOTMEM_TYPE);
if (atomic_dec_return(&page->_count) == 1) {
ClearPagePrivate(page);
set_page_private(page, 0);
INIT_LIST_HEAD(&page->lru);
free_reserved_page(page);
}
}
static void register_page_bootmem_info_section(unsigned long start_pfn)
{
unsigned long *usemap, mapsize, section_nr, i;
struct mem_section *ms;
struct page *page, *memmap;
section_nr = pfn_to_section_nr(start_pfn);
ms = __nr_to_section(section_nr);
memmap = sparse_decode_mem_map(ms->section_mem_map, section_nr);
page = virt_to_page(memmap);
mapsize = sizeof(struct page) * PAGES_PER_SECTION;
mapsize = PAGE_ALIGN(mapsize) >> PAGE_SHIFT;
for (i = 0; i < mapsize; i++, page++)
get_page_bootmem(section_nr, page, SECTION_INFO);
usemap = __nr_to_section(section_nr)->pageblock_flags;
page = virt_to_page(usemap);
mapsize = PAGE_ALIGN(usemap_size()) >> PAGE_SHIFT;
for (i = 0; i < mapsize; i++, page++)
get_page_bootmem(section_nr, page, MIX_SECTION_INFO);
}
static void register_page_bootmem_info_section(unsigned long start_pfn)
{
unsigned long *usemap, mapsize, section_nr, i;
struct mem_section *ms;
struct page *page, *memmap;
if (!pfn_valid(start_pfn))
return;
section_nr = pfn_to_section_nr(start_pfn);
ms = __nr_to_section(section_nr);
memmap = sparse_decode_mem_map(ms->section_mem_map, section_nr);
register_page_bootmem_memmap(section_nr, memmap, PAGES_PER_SECTION);
usemap = __nr_to_section(section_nr)->pageblock_flags;
page = virt_to_page(usemap);
mapsize = PAGE_ALIGN(usemap_size()) >> PAGE_SHIFT;
for (i = 0; i < mapsize; i++, page++)
get_page_bootmem(section_nr, page, MIX_SECTION_INFO);
}
void register_page_bootmem_info_node(struct pglist_data *pgdat)
{
unsigned long i, pfn, end_pfn, nr_pages;
int node = pgdat->node_id;
struct page *page;
struct zone *zone;
nr_pages = PAGE_ALIGN(sizeof(struct pglist_data)) >> PAGE_SHIFT;
page = virt_to_page(pgdat);
for (i = 0; i < nr_pages; i++, page++)
get_page_bootmem(node, page, NODE_INFO);
zone = &pgdat->node_zones[0];
for (; zone < pgdat->node_zones + MAX_NR_ZONES - 1; zone++) {
if (zone_is_initialized(zone)) {
nr_pages = zone->wait_table_hash_nr_entries
* sizeof(wait_queue_head_t);
nr_pages = PAGE_ALIGN(nr_pages) >> PAGE_SHIFT;
page = virt_to_page(zone->wait_table);
for (i = 0; i < nr_pages; i++, page++)
get_page_bootmem(node, page, NODE_INFO);
}
}
pfn = pgdat->node_start_pfn;
end_pfn = pgdat_end_pfn(pgdat);
for (; pfn < end_pfn; pfn += PAGES_PER_SECTION) {
if (pfn_valid(pfn) && (pfn_to_nid(pfn) == node))
register_page_bootmem_info_section(pfn);
}
}
static void __meminit grow_zone_span(struct zone *zone, unsigned long start_pfn,
unsigned long end_pfn)
{
unsigned long old_zone_end_pfn;
zone_span_writelock(zone);
old_zone_end_pfn = zone_end_pfn(zone);
if (zone_is_empty(zone) || start_pfn < zone->zone_start_pfn)
zone->zone_start_pfn = start_pfn;
zone->spanned_pages = max(old_zone_end_pfn, end_pfn) -
zone->zone_start_pfn;
zone_span_writeunlock(zone);
}
static void resize_zone(struct zone *zone, unsigned long start_pfn,
unsigned long end_pfn)
{
zone_span_writelock(zone);
if (end_pfn - start_pfn) {
zone->zone_start_pfn = start_pfn;
zone->spanned_pages = end_pfn - start_pfn;
} else {
zone->zone_start_pfn = 0;
zone->spanned_pages = 0;
}
zone_span_writeunlock(zone);
}
static void fix_zone_id(struct zone *zone, unsigned long start_pfn,
unsigned long end_pfn)
{
enum zone_type zid = zone_idx(zone);
int nid = zone->zone_pgdat->node_id;
unsigned long pfn;
for (pfn = start_pfn; pfn < end_pfn; pfn++)
set_page_links(pfn_to_page(pfn), zid, nid, pfn);
}
static int __ref ensure_zone_is_initialized(struct zone *zone,
unsigned long start_pfn, unsigned long num_pages)
{
if (!zone_is_initialized(zone))
return init_currently_empty_zone(zone, start_pfn, num_pages,
MEMMAP_HOTPLUG);
return 0;
}
static int __meminit move_pfn_range_left(struct zone *z1, struct zone *z2,
unsigned long start_pfn, unsigned long end_pfn)
{
int ret;
unsigned long flags;
unsigned long z1_start_pfn;
ret = ensure_zone_is_initialized(z1, start_pfn, end_pfn - start_pfn);
if (ret)
return ret;
pgdat_resize_lock(z1->zone_pgdat, &flags);
if (end_pfn > zone_end_pfn(z2))
goto out_fail;
if (start_pfn > z2->zone_start_pfn)
goto out_fail;
if (end_pfn <= z2->zone_start_pfn)
goto out_fail;
if (!zone_is_empty(z1))
z1_start_pfn = z1->zone_start_pfn;
else
z1_start_pfn = start_pfn;
resize_zone(z1, z1_start_pfn, end_pfn);
resize_zone(z2, end_pfn, zone_end_pfn(z2));
pgdat_resize_unlock(z1->zone_pgdat, &flags);
fix_zone_id(z1, start_pfn, end_pfn);
return 0;
out_fail:
pgdat_resize_unlock(z1->zone_pgdat, &flags);
return -1;
}
static int __meminit move_pfn_range_right(struct zone *z1, struct zone *z2,
unsigned long start_pfn, unsigned long end_pfn)
{
int ret;
unsigned long flags;
unsigned long z2_end_pfn;
ret = ensure_zone_is_initialized(z2, start_pfn, end_pfn - start_pfn);
if (ret)
return ret;
pgdat_resize_lock(z1->zone_pgdat, &flags);
if (z1->zone_start_pfn > start_pfn)
goto out_fail;
if (zone_end_pfn(z1) > end_pfn)
goto out_fail;
if (start_pfn >= zone_end_pfn(z1))
goto out_fail;
if (!zone_is_empty(z2))
z2_end_pfn = zone_end_pfn(z2);
else
z2_end_pfn = end_pfn;
resize_zone(z1, z1->zone_start_pfn, start_pfn);
resize_zone(z2, start_pfn, z2_end_pfn);
pgdat_resize_unlock(z1->zone_pgdat, &flags);
fix_zone_id(z2, start_pfn, end_pfn);
return 0;
out_fail:
pgdat_resize_unlock(z1->zone_pgdat, &flags);
return -1;
}
static void __meminit grow_pgdat_span(struct pglist_data *pgdat, unsigned long start_pfn,
unsigned long end_pfn)
{
unsigned long old_pgdat_end_pfn = pgdat_end_pfn(pgdat);
if (!pgdat->node_spanned_pages || start_pfn < pgdat->node_start_pfn)
pgdat->node_start_pfn = start_pfn;
pgdat->node_spanned_pages = max(old_pgdat_end_pfn, end_pfn) -
pgdat->node_start_pfn;
}
static int __meminit __add_zone(struct zone *zone, unsigned long phys_start_pfn)
{
struct pglist_data *pgdat = zone->zone_pgdat;
int nr_pages = PAGES_PER_SECTION;
int nid = pgdat->node_id;
int zone_type;
unsigned long flags;
int ret;
zone_type = zone - pgdat->node_zones;
ret = ensure_zone_is_initialized(zone, phys_start_pfn, nr_pages);
if (ret)
return ret;
pgdat_resize_lock(zone->zone_pgdat, &flags);
grow_zone_span(zone, phys_start_pfn, phys_start_pfn + nr_pages);
grow_pgdat_span(zone->zone_pgdat, phys_start_pfn,
phys_start_pfn + nr_pages);
pgdat_resize_unlock(zone->zone_pgdat, &flags);
memmap_init_zone(nr_pages, nid, zone_type,
phys_start_pfn, MEMMAP_HOTPLUG);
return 0;
}
static int __meminit __add_section(int nid, struct zone *zone,
unsigned long phys_start_pfn)
{
int ret;
if (pfn_valid(phys_start_pfn))
return -EEXIST;
ret = sparse_add_one_section(zone, phys_start_pfn);
if (ret < 0)
return ret;
ret = __add_zone(zone, phys_start_pfn);
if (ret < 0)
return ret;
return register_new_memory(nid, __pfn_to_section(phys_start_pfn));
}
int __ref __add_pages(int nid, struct zone *zone, unsigned long phys_start_pfn,
unsigned long nr_pages)
{
unsigned long i;
int err = 0;
int start_sec, end_sec;
start_sec = pfn_to_section_nr(phys_start_pfn);
end_sec = pfn_to_section_nr(phys_start_pfn + nr_pages - 1);
for (i = start_sec; i <= end_sec; i++) {
err = __add_section(nid, zone, i << PFN_SECTION_SHIFT);
if (err && (err != -EEXIST))
break;
err = 0;
}
return err;
}
static int find_smallest_section_pfn(int nid, struct zone *zone,
unsigned long start_pfn,
unsigned long end_pfn)
{
struct mem_section *ms;
for (; start_pfn < end_pfn; start_pfn += PAGES_PER_SECTION) {
ms = __pfn_to_section(start_pfn);
if (unlikely(!valid_section(ms)))
continue;
if (unlikely(pfn_to_nid(start_pfn) != nid))
continue;
if (zone && zone != page_zone(pfn_to_page(start_pfn)))
continue;
return start_pfn;
}
return 0;
}
static int find_biggest_section_pfn(int nid, struct zone *zone,
unsigned long start_pfn,
unsigned long end_pfn)
{
struct mem_section *ms;
unsigned long pfn;
pfn = end_pfn - 1;
for (; pfn >= start_pfn; pfn -= PAGES_PER_SECTION) {
ms = __pfn_to_section(pfn);
if (unlikely(!valid_section(ms)))
continue;
if (unlikely(pfn_to_nid(pfn) != nid))
continue;
if (zone && zone != page_zone(pfn_to_page(pfn)))
continue;
return pfn;
}
return 0;
}
static void shrink_zone_span(struct zone *zone, unsigned long start_pfn,
unsigned long end_pfn)
{
unsigned long zone_start_pfn = zone->zone_start_pfn;
unsigned long z = zone_end_pfn(zone);
unsigned long zone_end_pfn = z;
unsigned long pfn;
struct mem_section *ms;
int nid = zone_to_nid(zone);
zone_span_writelock(zone);
if (zone_start_pfn == start_pfn) {
pfn = find_smallest_section_pfn(nid, zone, end_pfn,
zone_end_pfn);
if (pfn) {
zone->zone_start_pfn = pfn;
zone->spanned_pages = zone_end_pfn - pfn;
}
} else if (zone_end_pfn == end_pfn) {
pfn = find_biggest_section_pfn(nid, zone, zone_start_pfn,
start_pfn);
if (pfn)
zone->spanned_pages = pfn - zone_start_pfn + 1;
}
pfn = zone_start_pfn;
for (; pfn < zone_end_pfn; pfn += PAGES_PER_SECTION) {
ms = __pfn_to_section(pfn);
if (unlikely(!valid_section(ms)))
continue;
if (page_zone(pfn_to_page(pfn)) != zone)
continue;
if (start_pfn == pfn)
continue;
zone_span_writeunlock(zone);
return;
}
zone->zone_start_pfn = 0;
zone->spanned_pages = 0;
zone_span_writeunlock(zone);
}
static void shrink_pgdat_span(struct pglist_data *pgdat,
unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long pgdat_start_pfn = pgdat->node_start_pfn;
unsigned long p = pgdat_end_pfn(pgdat);
unsigned long pgdat_end_pfn = p;
unsigned long pfn;
struct mem_section *ms;
int nid = pgdat->node_id;
if (pgdat_start_pfn == start_pfn) {
pfn = find_smallest_section_pfn(nid, NULL, end_pfn,
pgdat_end_pfn);
if (pfn) {
pgdat->node_start_pfn = pfn;
pgdat->node_spanned_pages = pgdat_end_pfn - pfn;
}
} else if (pgdat_end_pfn == end_pfn) {
pfn = find_biggest_section_pfn(nid, NULL, pgdat_start_pfn,
start_pfn);
if (pfn)
pgdat->node_spanned_pages = pfn - pgdat_start_pfn + 1;
}
pfn = pgdat_start_pfn;
for (; pfn < pgdat_end_pfn; pfn += PAGES_PER_SECTION) {
ms = __pfn_to_section(pfn);
if (unlikely(!valid_section(ms)))
continue;
if (pfn_to_nid(pfn) != nid)
continue;
if (start_pfn == pfn)
continue;
return;
}
pgdat->node_start_pfn = 0;
pgdat->node_spanned_pages = 0;
}
static void __remove_zone(struct zone *zone, unsigned long start_pfn)
{
struct pglist_data *pgdat = zone->zone_pgdat;
int nr_pages = PAGES_PER_SECTION;
int zone_type;
unsigned long flags;
zone_type = zone - pgdat->node_zones;
pgdat_resize_lock(zone->zone_pgdat, &flags);
shrink_zone_span(zone, start_pfn, start_pfn + nr_pages);
shrink_pgdat_span(pgdat, start_pfn, start_pfn + nr_pages);
pgdat_resize_unlock(zone->zone_pgdat, &flags);
}
static int __remove_section(struct zone *zone, struct mem_section *ms)
{
unsigned long start_pfn;
int scn_nr;
int ret = -EINVAL;
if (!valid_section(ms))
return ret;
ret = unregister_memory_section(ms);
if (ret)
return ret;
scn_nr = __section_nr(ms);
start_pfn = section_nr_to_pfn(scn_nr);
__remove_zone(zone, start_pfn);
sparse_remove_one_section(zone, ms);
return 0;
}
int __remove_pages(struct zone *zone, unsigned long phys_start_pfn,
unsigned long nr_pages)
{
unsigned long i;
int sections_to_remove;
resource_size_t start, size;
int ret = 0;
BUG_ON(phys_start_pfn & ~PAGE_SECTION_MASK);
BUG_ON(nr_pages % PAGES_PER_SECTION);
start = phys_start_pfn << PAGE_SHIFT;
size = nr_pages * PAGE_SIZE;
ret = release_mem_region_adjustable(&iomem_resource, start, size);
if (ret) {
resource_size_t endres = start + size - 1;
pr_warn("Unable to release resource <%pa-%pa> (%d)\n",
&start, &endres, ret);
}
sections_to_remove = nr_pages / PAGES_PER_SECTION;
for (i = 0; i < sections_to_remove; i++) {
unsigned long pfn = phys_start_pfn + i*PAGES_PER_SECTION;
ret = __remove_section(zone, __pfn_to_section(pfn));
if (ret)
break;
}
return ret;
}
int set_online_page_callback(online_page_callback_t callback)
{
int rc = -EINVAL;
get_online_mems();
mutex_lock(&online_page_callback_lock);
if (online_page_callback == generic_online_page) {
online_page_callback = callback;
rc = 0;
}
mutex_unlock(&online_page_callback_lock);
put_online_mems();
return rc;
}
int restore_online_page_callback(online_page_callback_t callback)
{
int rc = -EINVAL;
get_online_mems();
mutex_lock(&online_page_callback_lock);
if (online_page_callback == callback) {
online_page_callback = generic_online_page;
rc = 0;
}
mutex_unlock(&online_page_callback_lock);
put_online_mems();
return rc;
}
void __online_page_set_limits(struct page *page)
{
}
void __online_page_increment_counters(struct page *page)
{
adjust_managed_page_count(page, 1);
}
void __online_page_free(struct page *page)
{
__free_reserved_page(page);
}
static void generic_online_page(struct page *page)
{
__online_page_set_limits(page);
__online_page_increment_counters(page);
__online_page_free(page);
}
static int online_pages_range(unsigned long start_pfn, unsigned long nr_pages,
void *arg)
{
unsigned long i;
unsigned long onlined_pages = *(unsigned long *)arg;
struct page *page;
if (PageReserved(pfn_to_page(start_pfn)))
for (i = 0; i < nr_pages; i++) {
page = pfn_to_page(start_pfn + i);
(*online_page_callback)(page);
onlined_pages++;
}
*(unsigned long *)arg = onlined_pages;
return 0;
}
static bool can_online_high_movable(struct zone *zone)
{
return true;
}
static bool can_online_high_movable(struct zone *zone)
{
return node_state(zone_to_nid(zone), N_NORMAL_MEMORY);
}
static void node_states_check_changes_online(unsigned long nr_pages,
struct zone *zone, struct memory_notify *arg)
{
int nid = zone_to_nid(zone);
enum zone_type zone_last = ZONE_NORMAL;
if (N_MEMORY == N_NORMAL_MEMORY)
zone_last = ZONE_MOVABLE;
if (zone_idx(zone) <= zone_last && !node_state(nid, N_NORMAL_MEMORY))
arg->status_change_nid_normal = nid;
else
arg->status_change_nid_normal = -1;
#ifdef CONFIG_HIGHMEM
zone_last = ZONE_HIGHMEM;
if (N_MEMORY == N_HIGH_MEMORY)
zone_last = ZONE_MOVABLE;
if (zone_idx(zone) <= zone_last && !node_state(nid, N_HIGH_MEMORY))
arg->status_change_nid_high = nid;
else
arg->status_change_nid_high = -1;
#else
arg->status_change_nid_high = arg->status_change_nid_normal;
#endif
if (!node_state(nid, N_MEMORY))
arg->status_change_nid = nid;
else
arg->status_change_nid = -1;
}
static void node_states_set_node(int node, struct memory_notify *arg)
{
if (arg->status_change_nid_normal >= 0)
node_set_state(node, N_NORMAL_MEMORY);
if (arg->status_change_nid_high >= 0)
node_set_state(node, N_HIGH_MEMORY);
node_set_state(node, N_MEMORY);
}
int __ref online_pages(unsigned long pfn, unsigned long nr_pages, int online_type)
{
unsigned long flags;
unsigned long onlined_pages = 0;
struct zone *zone;
int need_zonelists_rebuild = 0;
int nid;
int ret;
struct memory_notify arg;
mem_hotplug_begin();
zone = page_zone(pfn_to_page(pfn));
ret = -EINVAL;
if ((zone_idx(zone) > ZONE_NORMAL ||
online_type == MMOP_ONLINE_MOVABLE) &&
!can_online_high_movable(zone))
goto out;
if (online_type == MMOP_ONLINE_KERNEL &&
zone_idx(zone) == ZONE_MOVABLE) {
if (move_pfn_range_left(zone - 1, zone, pfn, pfn + nr_pages))
goto out;
}
if (online_type == MMOP_ONLINE_MOVABLE &&
zone_idx(zone) == ZONE_MOVABLE - 1) {
if (move_pfn_range_right(zone, zone + 1, pfn, pfn + nr_pages))
goto out;
}
zone = page_zone(pfn_to_page(pfn));
arg.start_pfn = pfn;
arg.nr_pages = nr_pages;
node_states_check_changes_online(nr_pages, zone, &arg);
nid = pfn_to_nid(pfn);
ret = memory_notify(MEM_GOING_ONLINE, &arg);
ret = notifier_to_errno(ret);
if (ret) {
memory_notify(MEM_CANCEL_ONLINE, &arg);
goto out;
}
mutex_lock(&zonelists_mutex);
if (!populated_zone(zone)) {
need_zonelists_rebuild = 1;
build_all_zonelists(NULL, zone);
}
ret = walk_system_ram_range(pfn, nr_pages, &onlined_pages,
online_pages_range);
if (ret) {
if (need_zonelists_rebuild)
zone_pcp_reset(zone);
mutex_unlock(&zonelists_mutex);
printk(KERN_DEBUG "online_pages [mem %#010llx-%#010llx] failed\n",
(unsigned long long) pfn << PAGE_SHIFT,
(((unsigned long long) pfn + nr_pages)
<< PAGE_SHIFT) - 1);
memory_notify(MEM_CANCEL_ONLINE, &arg);
goto out;
}
zone->present_pages += onlined_pages;
pgdat_resize_lock(zone->zone_pgdat, &flags);
zone->zone_pgdat->node_present_pages += onlined_pages;
pgdat_resize_unlock(zone->zone_pgdat, &flags);
if (onlined_pages) {
node_states_set_node(zone_to_nid(zone), &arg);
if (need_zonelists_rebuild)
build_all_zonelists(NULL, NULL);
else
zone_pcp_update(zone);
}
mutex_unlock(&zonelists_mutex);
init_per_zone_wmark_min();
if (onlined_pages)
kswapd_run(zone_to_nid(zone));
vm_total_pages = nr_free_pagecache_pages();
writeback_set_ratelimit();
if (onlined_pages)
memory_notify(MEM_ONLINE, &arg);
out:
mem_hotplug_done();
return ret;
}
static void reset_node_present_pages(pg_data_t *pgdat)
{
struct zone *z;
for (z = pgdat->node_zones; z < pgdat->node_zones + MAX_NR_ZONES; z++)
z->present_pages = 0;
pgdat->node_present_pages = 0;
}
static pg_data_t __ref *hotadd_new_pgdat(int nid, u64 start)
{
struct pglist_data *pgdat;
unsigned long zones_size[MAX_NR_ZONES] = {0};
unsigned long zholes_size[MAX_NR_ZONES] = {0};
unsigned long start_pfn = PFN_DOWN(start);
pgdat = NODE_DATA(nid);
if (!pgdat) {
pgdat = arch_alloc_nodedata(nid);
if (!pgdat)
return NULL;
arch_refresh_nodedata(nid, pgdat);
}
free_area_init_node(nid, zones_size, start_pfn, zholes_size);
mutex_lock(&zonelists_mutex);
build_all_zonelists(pgdat, NULL);
mutex_unlock(&zonelists_mutex);
reset_node_managed_pages(pgdat);
reset_node_present_pages(pgdat);
return pgdat;
}
static void rollback_node_hotadd(int nid, pg_data_t *pgdat)
{
arch_refresh_nodedata(nid, NULL);
arch_free_nodedata(pgdat);
return;
}
int try_online_node(int nid)
{
pg_data_t *pgdat;
int ret;
if (node_online(nid))
return 0;
mem_hotplug_begin();
pgdat = hotadd_new_pgdat(nid, 0);
if (!pgdat) {
pr_err("Cannot online node %d due to NULL pgdat\n", nid);
ret = -ENOMEM;
goto out;
}
node_set_online(nid);
ret = register_one_node(nid);
BUG_ON(ret);
if (pgdat->node_zonelists->_zonerefs->zone == NULL) {
mutex_lock(&zonelists_mutex);
build_all_zonelists(NULL, NULL);
mutex_unlock(&zonelists_mutex);
}
out:
mem_hotplug_done();
return ret;
}
static int check_hotplug_memory_range(u64 start, u64 size)
{
u64 start_pfn = PFN_DOWN(start);
u64 nr_pages = size >> PAGE_SHIFT;
if ((start_pfn & ~PAGE_SECTION_MASK) ||
(nr_pages % PAGES_PER_SECTION) || (!nr_pages)) {
pr_err("Section-unaligned hotplug range: start 0x%llx, size 0x%llx\n",
(unsigned long long)start,
(unsigned long long)size);
return -EINVAL;
}
return 0;
}
static int should_add_memory_movable(int nid, u64 start, u64 size)
{
unsigned long start_pfn = start >> PAGE_SHIFT;
pg_data_t *pgdat = NODE_DATA(nid);
struct zone *movable_zone = pgdat->node_zones + ZONE_MOVABLE;
if (zone_is_empty(movable_zone))
return 0;
if (movable_zone->zone_start_pfn <= start_pfn)
return 1;
return 0;
}
int zone_for_memory(int nid, u64 start, u64 size, int zone_default)
{
if (should_add_memory_movable(nid, start, size))
return ZONE_MOVABLE;
return zone_default;
}
int __ref add_memory(int nid, u64 start, u64 size)
{
pg_data_t *pgdat = NULL;
bool new_pgdat;
bool new_node;
struct resource *res;
int ret;
ret = check_hotplug_memory_range(start, size);
if (ret)
return ret;
res = register_memory_resource(start, size);
ret = -EEXIST;
if (!res)
return ret;
{
void *p = NODE_DATA(nid);
new_pgdat = !p;
}
mem_hotplug_begin();
new_node = !node_online(nid);
if (new_node) {
pgdat = hotadd_new_pgdat(nid, start);
ret = -ENOMEM;
if (!pgdat)
goto error;
}
ret = arch_add_memory(nid, start, size);
if (ret < 0)
goto error;
node_set_online(nid);
if (new_node) {
ret = register_one_node(nid);
BUG_ON(ret);
}
firmware_map_add_hotplug(start, start + size, "System RAM");
goto out;
error:
if (new_pgdat)
rollback_node_hotadd(nid, pgdat);
release_memory_resource(res);
out:
mem_hotplug_done();
return ret;
}
static inline int pageblock_free(struct page *page)
{
return PageBuddy(page) && page_order(page) >= pageblock_order;
}
static struct page *next_active_pageblock(struct page *page)
{
BUG_ON(page_to_pfn(page) & (pageblock_nr_pages - 1));
if (pageblock_free(page)) {
int order;
order = page_order(page);
if ((order < MAX_ORDER) && (order >= pageblock_order))
return page + (1 << order);
}
return page + pageblock_nr_pages;
}
int is_mem_section_removable(unsigned long start_pfn, unsigned long nr_pages)
{
struct page *page = pfn_to_page(start_pfn);
struct page *end_page = page + nr_pages;
for (; page < end_page; page = next_active_pageblock(page)) {
if (!is_pageblock_removable_nolock(page))
return 0;
cond_resched();
}
return 1;
}
int test_pages_in_a_zone(unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long pfn;
struct zone *zone = NULL;
struct page *page;
int i;
for (pfn = start_pfn;
pfn < end_pfn;
pfn += MAX_ORDER_NR_PAGES) {
i = 0;
while ((i < MAX_ORDER_NR_PAGES) && !pfn_valid_within(pfn + i))
i++;
if (i == MAX_ORDER_NR_PAGES)
continue;
page = pfn_to_page(pfn + i);
if (zone && page_zone(page) != zone)
return 0;
zone = page_zone(page);
}
return 1;
}
static unsigned long scan_movable_pages(unsigned long start, unsigned long end)
{
unsigned long pfn;
struct page *page;
for (pfn = start; pfn < end; pfn++) {
if (pfn_valid(pfn)) {
page = pfn_to_page(pfn);
if (PageLRU(page))
return pfn;
if (PageHuge(page)) {
if (is_hugepage_active(page))
return pfn;
else
pfn = round_up(pfn + 1,
1 << compound_order(page)) - 1;
}
}
}
return 0;
}
static int
do_migrate_range(unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long pfn;
struct page *page;
int move_pages = NR_OFFLINE_AT_ONCE_PAGES;
int not_managed = 0;
int ret = 0;
LIST_HEAD(source);
for (pfn = start_pfn; pfn < end_pfn && move_pages > 0; pfn++) {
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (PageHuge(page)) {
struct page *head = compound_head(page);
pfn = page_to_pfn(head) + (1<<compound_order(head)) - 1;
if (compound_order(head) > PFN_SECTION_SHIFT) {
ret = -EBUSY;
break;
}
if (isolate_huge_page(page, &source))
move_pages -= 1 << compound_order(head);
continue;
}
if (!get_page_unless_zero(page))
continue;
ret = isolate_lru_page(page);
if (!ret) {
put_page(page);
list_add_tail(&page->lru, &source);
move_pages--;
inc_zone_page_state(page, NR_ISOLATED_ANON +
page_is_file_cache(page));
} else {
#ifdef CONFIG_DEBUG_VM
printk(KERN_ALERT "removing pfn %lx from LRU failed\n",
pfn);
dump_page(page, "failed to remove from LRU");
#endif
put_page(page);
if (page_count(page)) {
not_managed++;
ret = -EBUSY;
break;
}
}
}
if (!list_empty(&source)) {
if (not_managed) {
putback_movable_pages(&source);
goto out;
}
ret = migrate_pages(&source, alloc_migrate_target, NULL, 0,
MIGRATE_SYNC, MR_MEMORY_HOTPLUG);
if (ret)
putback_movable_pages(&source);
}
out:
return ret;
}
static int
offline_isolated_pages_cb(unsigned long start, unsigned long nr_pages,
void *data)
{
__offline_isolated_pages(start, start + nr_pages);
return 0;
}
static void
offline_isolated_pages(unsigned long start_pfn, unsigned long end_pfn)
{
walk_system_ram_range(start_pfn, end_pfn - start_pfn, NULL,
offline_isolated_pages_cb);
}
static int
check_pages_isolated_cb(unsigned long start_pfn, unsigned long nr_pages,
void *data)
{
int ret;
long offlined = *(long *)data;
ret = test_pages_isolated(start_pfn, start_pfn + nr_pages, true);
offlined = nr_pages;
if (!ret)
*(long *)data += offlined;
return ret;
}
static long
check_pages_isolated(unsigned long start_pfn, unsigned long end_pfn)
{
long offlined = 0;
int ret;
ret = walk_system_ram_range(start_pfn, end_pfn - start_pfn, &offlined,
check_pages_isolated_cb);
if (ret < 0)
offlined = (long)ret;
return offlined;
}
static bool can_offline_normal(struct zone *zone, unsigned long nr_pages)
{
return true;
}
static bool can_offline_normal(struct zone *zone, unsigned long nr_pages)
{
struct pglist_data *pgdat = zone->zone_pgdat;
unsigned long present_pages = 0;
enum zone_type zt;
for (zt = 0; zt <= ZONE_NORMAL; zt++)
present_pages += pgdat->node_zones[zt].present_pages;
if (present_pages > nr_pages)
return true;
present_pages = 0;
for (; zt <= ZONE_MOVABLE; zt++)
present_pages += pgdat->node_zones[zt].present_pages;
return present_pages == 0;
}
static int __init cmdline_parse_movable_node(char *p)
{
#ifdef CONFIG_MOVABLE_NODE
memblock_set_bottom_up(true);
movable_node_enabled = true;
#else
pr_warn("movable_node option not supported\n");
#endif
return 0;
}
static void node_states_check_changes_offline(unsigned long nr_pages,
struct zone *zone, struct memory_notify *arg)
{
struct pglist_data *pgdat = zone->zone_pgdat;
unsigned long present_pages = 0;
enum zone_type zt, zone_last = ZONE_NORMAL;
if (N_MEMORY == N_NORMAL_MEMORY)
zone_last = ZONE_MOVABLE;
for (zt = 0; zt <= zone_last; zt++)
present_pages += pgdat->node_zones[zt].present_pages;
if (zone_idx(zone) <= zone_last && nr_pages >= present_pages)
arg->status_change_nid_normal = zone_to_nid(zone);
else
arg->status_change_nid_normal = -1;
#ifdef CONFIG_HIGHMEM
zone_last = ZONE_HIGHMEM;
if (N_MEMORY == N_HIGH_MEMORY)
zone_last = ZONE_MOVABLE;
for (; zt <= zone_last; zt++)
present_pages += pgdat->node_zones[zt].present_pages;
if (zone_idx(zone) <= zone_last && nr_pages >= present_pages)
arg->status_change_nid_high = zone_to_nid(zone);
else
arg->status_change_nid_high = -1;
#else
arg->status_change_nid_high = arg->status_change_nid_normal;
#endif
zone_last = ZONE_MOVABLE;
for (; zt <= zone_last; zt++)
present_pages += pgdat->node_zones[zt].present_pages;
if (nr_pages >= present_pages)
arg->status_change_nid = zone_to_nid(zone);
else
arg->status_change_nid = -1;
}
static void node_states_clear_node(int node, struct memory_notify *arg)
{
if (arg->status_change_nid_normal >= 0)
node_clear_state(node, N_NORMAL_MEMORY);
if ((N_MEMORY != N_NORMAL_MEMORY) &&
(arg->status_change_nid_high >= 0))
node_clear_state(node, N_HIGH_MEMORY);
if ((N_MEMORY != N_HIGH_MEMORY) &&
(arg->status_change_nid >= 0))
node_clear_state(node, N_MEMORY);
}
static int __ref __offline_pages(unsigned long start_pfn,
unsigned long end_pfn, unsigned long timeout)
{
unsigned long pfn, nr_pages, expire;
long offlined_pages;
int ret, drain, retry_max, node;
unsigned long flags;
struct zone *zone;
struct memory_notify arg;
if (!IS_ALIGNED(start_pfn, pageblock_nr_pages))
return -EINVAL;
if (!IS_ALIGNED(end_pfn, pageblock_nr_pages))
return -EINVAL;
if (!test_pages_in_a_zone(start_pfn, end_pfn))
return -EINVAL;
mem_hotplug_begin();
zone = page_zone(pfn_to_page(start_pfn));
node = zone_to_nid(zone);
nr_pages = end_pfn - start_pfn;
ret = -EINVAL;
if (zone_idx(zone) <= ZONE_NORMAL && !can_offline_normal(zone, nr_pages))
goto out;
ret = start_isolate_page_range(start_pfn, end_pfn,
MIGRATE_MOVABLE, true);
if (ret)
goto out;
arg.start_pfn = start_pfn;
arg.nr_pages = nr_pages;
node_states_check_changes_offline(nr_pages, zone, &arg);
ret = memory_notify(MEM_GOING_OFFLINE, &arg);
ret = notifier_to_errno(ret);
if (ret)
goto failed_removal;
pfn = start_pfn;
expire = jiffies + timeout;
drain = 0;
retry_max = 5;
repeat:
ret = -EAGAIN;
if (time_after(jiffies, expire))
goto failed_removal;
ret = -EINTR;
if (signal_pending(current))
goto failed_removal;
ret = 0;
if (drain) {
lru_add_drain_all();
cond_resched();
drain_all_pages(zone);
}
pfn = scan_movable_pages(start_pfn, end_pfn);
if (pfn) {
ret = do_migrate_range(pfn, end_pfn);
if (!ret) {
drain = 1;
goto repeat;
} else {
if (ret < 0)
if (--retry_max == 0)
goto failed_removal;
yield();
drain = 1;
goto repeat;
}
}
lru_add_drain_all();
yield();
drain_all_pages(zone);
dissolve_free_huge_pages(start_pfn, end_pfn);
offlined_pages = check_pages_isolated(start_pfn, end_pfn);
if (offlined_pages < 0) {
ret = -EBUSY;
goto failed_removal;
}
printk(KERN_INFO "Offlined Pages %ld\n", offlined_pages);
offline_isolated_pages(start_pfn, end_pfn);
undo_isolate_page_range(start_pfn, end_pfn, MIGRATE_MOVABLE);
adjust_managed_page_count(pfn_to_page(start_pfn), -offlined_pages);
zone->present_pages -= offlined_pages;
pgdat_resize_lock(zone->zone_pgdat, &flags);
zone->zone_pgdat->node_present_pages -= offlined_pages;
pgdat_resize_unlock(zone->zone_pgdat, &flags);
init_per_zone_wmark_min();
if (!populated_zone(zone)) {
zone_pcp_reset(zone);
mutex_lock(&zonelists_mutex);
build_all_zonelists(NULL, NULL);
mutex_unlock(&zonelists_mutex);
} else
zone_pcp_update(zone);
node_states_clear_node(node, &arg);
if (arg.status_change_nid >= 0)
kswapd_stop(node);
vm_total_pages = nr_free_pagecache_pages();
writeback_set_ratelimit();
memory_notify(MEM_OFFLINE, &arg);
mem_hotplug_done();
return 0;
failed_removal:
printk(KERN_INFO "memory offlining [mem %#010llx-%#010llx] failed\n",
(unsigned long long) start_pfn << PAGE_SHIFT,
((unsigned long long) end_pfn << PAGE_SHIFT) - 1);
memory_notify(MEM_CANCEL_OFFLINE, &arg);
undo_isolate_page_range(start_pfn, end_pfn, MIGRATE_MOVABLE);
out:
mem_hotplug_done();
return ret;
}
int offline_pages(unsigned long start_pfn, unsigned long nr_pages)
{
return __offline_pages(start_pfn, start_pfn + nr_pages, 120 * HZ);
}
int walk_memory_range(unsigned long start_pfn, unsigned long end_pfn,
void *arg, int (*func)(struct memory_block *, void *))
{
struct memory_block *mem = NULL;
struct mem_section *section;
unsigned long pfn, section_nr;
int ret;
for (pfn = start_pfn; pfn < end_pfn; pfn += PAGES_PER_SECTION) {
section_nr = pfn_to_section_nr(pfn);
if (!present_section_nr(section_nr))
continue;
section = __nr_to_section(section_nr);
if (mem)
if ((section_nr >= mem->start_section_nr) &&
(section_nr <= mem->end_section_nr))
continue;
mem = find_memory_block_hinted(section, mem);
if (!mem)
continue;
ret = func(mem, arg);
if (ret) {
kobject_put(&mem->dev.kobj);
return ret;
}
}
if (mem)
kobject_put(&mem->dev.kobj);
return 0;
}
static int check_memblock_offlined_cb(struct memory_block *mem, void *arg)
{
int ret = !is_memblock_offlined(mem);
if (unlikely(ret)) {
phys_addr_t beginpa, endpa;
beginpa = PFN_PHYS(section_nr_to_pfn(mem->start_section_nr));
endpa = PFN_PHYS(section_nr_to_pfn(mem->end_section_nr + 1))-1;
pr_warn("removing memory fails, because memory "
"[%pa-%pa] is onlined\n",
&beginpa, &endpa);
}
return ret;
}
static int check_cpu_on_node(pg_data_t *pgdat)
{
int cpu;
for_each_present_cpu(cpu) {
if (cpu_to_node(cpu) == pgdat->node_id)
return -EBUSY;
}
return 0;
}
static void unmap_cpu_on_node(pg_data_t *pgdat)
{
#ifdef CONFIG_ACPI_NUMA
int cpu;
for_each_possible_cpu(cpu)
if (cpu_to_node(cpu) == pgdat->node_id)
numa_clear_node(cpu);
#endif
}
static int check_and_unmap_cpu_on_node(pg_data_t *pgdat)
{
int ret;
ret = check_cpu_on_node(pgdat);
if (ret)
return ret;
unmap_cpu_on_node(pgdat);
return 0;
}
void try_offline_node(int nid)
{
pg_data_t *pgdat = NODE_DATA(nid);
unsigned long start_pfn = pgdat->node_start_pfn;
unsigned long end_pfn = start_pfn + pgdat->node_spanned_pages;
unsigned long pfn;
int i;
for (pfn = start_pfn; pfn < end_pfn; pfn += PAGES_PER_SECTION) {
unsigned long section_nr = pfn_to_section_nr(pfn);
if (!present_section_nr(section_nr))
continue;
if (pfn_to_nid(pfn) != nid)
continue;
return;
}
if (check_and_unmap_cpu_on_node(pgdat))
return;
node_set_offline(nid);
unregister_one_node(nid);
for (i = 0; i < MAX_NR_ZONES; i++) {
struct zone *zone = pgdat->node_zones + i;
if (is_vmalloc_addr(zone->wait_table))
vfree(zone->wait_table);
}
memset(pgdat, 0, sizeof(*pgdat));
}
void __ref remove_memory(int nid, u64 start, u64 size)
{
int ret;
BUG_ON(check_hotplug_memory_range(start, size));
mem_hotplug_begin();
ret = walk_memory_range(PFN_DOWN(start), PFN_UP(start + size - 1), NULL,
check_memblock_offlined_cb);
if (ret)
BUG();
firmware_map_remove(start, start + size, "System RAM");
arch_remove_memory(start, size);
try_offline_node(nid);
mem_hotplug_done();
}
