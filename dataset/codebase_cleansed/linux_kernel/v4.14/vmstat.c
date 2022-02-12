static void sum_vm_events(unsigned long *ret)
{
int cpu;
int i;
memset(ret, 0, NR_VM_EVENT_ITEMS * sizeof(unsigned long));
for_each_online_cpu(cpu) {
struct vm_event_state *this = &per_cpu(vm_event_states, cpu);
for (i = 0; i < NR_VM_EVENT_ITEMS; i++)
ret[i] += this->event[i];
}
}
void all_vm_events(unsigned long *ret)
{
get_online_cpus();
sum_vm_events(ret);
put_online_cpus();
}
void vm_events_fold_cpu(int cpu)
{
struct vm_event_state *fold_state = &per_cpu(vm_event_states, cpu);
int i;
for (i = 0; i < NR_VM_EVENT_ITEMS; i++) {
count_vm_events(i, fold_state->event[i]);
fold_state->event[i] = 0;
}
}
int calculate_pressure_threshold(struct zone *zone)
{
int threshold;
int watermark_distance;
watermark_distance = low_wmark_pages(zone) - min_wmark_pages(zone);
threshold = max(1, (int)(watermark_distance / num_online_cpus()));
threshold = min(125, threshold);
return threshold;
}
int calculate_normal_threshold(struct zone *zone)
{
int threshold;
int mem;
mem = zone->managed_pages >> (27 - PAGE_SHIFT);
threshold = 2 * fls(num_online_cpus()) * (1 + fls(mem));
threshold = min(125, threshold);
return threshold;
}
void refresh_zone_stat_thresholds(void)
{
struct pglist_data *pgdat;
struct zone *zone;
int cpu;
int threshold;
for_each_online_pgdat(pgdat) {
for_each_online_cpu(cpu) {
per_cpu_ptr(pgdat->per_cpu_nodestats, cpu)->stat_threshold = 0;
}
}
for_each_populated_zone(zone) {
struct pglist_data *pgdat = zone->zone_pgdat;
unsigned long max_drift, tolerate_drift;
threshold = calculate_normal_threshold(zone);
for_each_online_cpu(cpu) {
int pgdat_threshold;
per_cpu_ptr(zone->pageset, cpu)->stat_threshold
= threshold;
pgdat_threshold = per_cpu_ptr(pgdat->per_cpu_nodestats, cpu)->stat_threshold;
per_cpu_ptr(pgdat->per_cpu_nodestats, cpu)->stat_threshold
= max(threshold, pgdat_threshold);
}
tolerate_drift = low_wmark_pages(zone) - min_wmark_pages(zone);
max_drift = num_online_cpus() * threshold;
if (max_drift > tolerate_drift)
zone->percpu_drift_mark = high_wmark_pages(zone) +
max_drift;
}
}
void set_pgdat_percpu_threshold(pg_data_t *pgdat,
int (*calculate_pressure)(struct zone *))
{
struct zone *zone;
int cpu;
int threshold;
int i;
for (i = 0; i < pgdat->nr_zones; i++) {
zone = &pgdat->node_zones[i];
if (!zone->percpu_drift_mark)
continue;
threshold = (*calculate_pressure)(zone);
for_each_online_cpu(cpu)
per_cpu_ptr(zone->pageset, cpu)->stat_threshold
= threshold;
}
}
void __mod_zone_page_state(struct zone *zone, enum zone_stat_item item,
long delta)
{
struct per_cpu_pageset __percpu *pcp = zone->pageset;
s8 __percpu *p = pcp->vm_stat_diff + item;
long x;
long t;
x = delta + __this_cpu_read(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(x > t || x < -t)) {
zone_page_state_add(x, zone, item);
x = 0;
}
__this_cpu_write(*p, x);
}
void __mod_node_page_state(struct pglist_data *pgdat, enum node_stat_item item,
long delta)
{
struct per_cpu_nodestat __percpu *pcp = pgdat->per_cpu_nodestats;
s8 __percpu *p = pcp->vm_node_stat_diff + item;
long x;
long t;
x = delta + __this_cpu_read(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(x > t || x < -t)) {
node_page_state_add(x, pgdat, item);
x = 0;
}
__this_cpu_write(*p, x);
}
void __inc_zone_state(struct zone *zone, enum zone_stat_item item)
{
struct per_cpu_pageset __percpu *pcp = zone->pageset;
s8 __percpu *p = pcp->vm_stat_diff + item;
s8 v, t;
v = __this_cpu_inc_return(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(v > t)) {
s8 overstep = t >> 1;
zone_page_state_add(v + overstep, zone, item);
__this_cpu_write(*p, -overstep);
}
}
void __inc_node_state(struct pglist_data *pgdat, enum node_stat_item item)
{
struct per_cpu_nodestat __percpu *pcp = pgdat->per_cpu_nodestats;
s8 __percpu *p = pcp->vm_node_stat_diff + item;
s8 v, t;
v = __this_cpu_inc_return(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(v > t)) {
s8 overstep = t >> 1;
node_page_state_add(v + overstep, pgdat, item);
__this_cpu_write(*p, -overstep);
}
}
void __inc_zone_page_state(struct page *page, enum zone_stat_item item)
{
__inc_zone_state(page_zone(page), item);
}
void __inc_node_page_state(struct page *page, enum node_stat_item item)
{
__inc_node_state(page_pgdat(page), item);
}
void __dec_zone_state(struct zone *zone, enum zone_stat_item item)
{
struct per_cpu_pageset __percpu *pcp = zone->pageset;
s8 __percpu *p = pcp->vm_stat_diff + item;
s8 v, t;
v = __this_cpu_dec_return(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(v < - t)) {
s8 overstep = t >> 1;
zone_page_state_add(v - overstep, zone, item);
__this_cpu_write(*p, overstep);
}
}
void __dec_node_state(struct pglist_data *pgdat, enum node_stat_item item)
{
struct per_cpu_nodestat __percpu *pcp = pgdat->per_cpu_nodestats;
s8 __percpu *p = pcp->vm_node_stat_diff + item;
s8 v, t;
v = __this_cpu_dec_return(*p);
t = __this_cpu_read(pcp->stat_threshold);
if (unlikely(v < - t)) {
s8 overstep = t >> 1;
node_page_state_add(v - overstep, pgdat, item);
__this_cpu_write(*p, overstep);
}
}
void __dec_zone_page_state(struct page *page, enum zone_stat_item item)
{
__dec_zone_state(page_zone(page), item);
}
void __dec_node_page_state(struct page *page, enum node_stat_item item)
{
__dec_node_state(page_pgdat(page), item);
}
static inline void mod_zone_state(struct zone *zone,
enum zone_stat_item item, long delta, int overstep_mode)
{
struct per_cpu_pageset __percpu *pcp = zone->pageset;
s8 __percpu *p = pcp->vm_stat_diff + item;
long o, n, t, z;
do {
z = 0;
t = this_cpu_read(pcp->stat_threshold);
o = this_cpu_read(*p);
n = delta + o;
if (n > t || n < -t) {
int os = overstep_mode * (t >> 1) ;
z = n + os;
n = -os;
}
} while (this_cpu_cmpxchg(*p, o, n) != o);
if (z)
zone_page_state_add(z, zone, item);
}
void mod_zone_page_state(struct zone *zone, enum zone_stat_item item,
long delta)
{
mod_zone_state(zone, item, delta, 0);
}
void inc_zone_page_state(struct page *page, enum zone_stat_item item)
{
mod_zone_state(page_zone(page), item, 1, 1);
}
void dec_zone_page_state(struct page *page, enum zone_stat_item item)
{
mod_zone_state(page_zone(page), item, -1, -1);
}
static inline void mod_node_state(struct pglist_data *pgdat,
enum node_stat_item item, int delta, int overstep_mode)
{
struct per_cpu_nodestat __percpu *pcp = pgdat->per_cpu_nodestats;
s8 __percpu *p = pcp->vm_node_stat_diff + item;
long o, n, t, z;
do {
z = 0;
t = this_cpu_read(pcp->stat_threshold);
o = this_cpu_read(*p);
n = delta + o;
if (n > t || n < -t) {
int os = overstep_mode * (t >> 1) ;
z = n + os;
n = -os;
}
} while (this_cpu_cmpxchg(*p, o, n) != o);
if (z)
node_page_state_add(z, pgdat, item);
}
void mod_node_page_state(struct pglist_data *pgdat, enum node_stat_item item,
long delta)
{
mod_node_state(pgdat, item, delta, 0);
}
void inc_node_state(struct pglist_data *pgdat, enum node_stat_item item)
{
mod_node_state(pgdat, item, 1, 1);
}
void inc_node_page_state(struct page *page, enum node_stat_item item)
{
mod_node_state(page_pgdat(page), item, 1, 1);
}
void dec_node_page_state(struct page *page, enum node_stat_item item)
{
mod_node_state(page_pgdat(page), item, -1, -1);
}
void mod_zone_page_state(struct zone *zone, enum zone_stat_item item,
long delta)
{
unsigned long flags;
local_irq_save(flags);
__mod_zone_page_state(zone, item, delta);
local_irq_restore(flags);
}
void inc_zone_page_state(struct page *page, enum zone_stat_item item)
{
unsigned long flags;
struct zone *zone;
zone = page_zone(page);
local_irq_save(flags);
__inc_zone_state(zone, item);
local_irq_restore(flags);
}
void dec_zone_page_state(struct page *page, enum zone_stat_item item)
{
unsigned long flags;
local_irq_save(flags);
__dec_zone_page_state(page, item);
local_irq_restore(flags);
}
void inc_node_state(struct pglist_data *pgdat, enum node_stat_item item)
{
unsigned long flags;
local_irq_save(flags);
__inc_node_state(pgdat, item);
local_irq_restore(flags);
}
void mod_node_page_state(struct pglist_data *pgdat, enum node_stat_item item,
long delta)
{
unsigned long flags;
local_irq_save(flags);
__mod_node_page_state(pgdat, item, delta);
local_irq_restore(flags);
}
void inc_node_page_state(struct page *page, enum node_stat_item item)
{
unsigned long flags;
struct pglist_data *pgdat;
pgdat = page_pgdat(page);
local_irq_save(flags);
__inc_node_state(pgdat, item);
local_irq_restore(flags);
}
void dec_node_page_state(struct page *page, enum node_stat_item item)
{
unsigned long flags;
local_irq_save(flags);
__dec_node_page_state(page, item);
local_irq_restore(flags);
}
static int fold_diff(int *zone_diff, int *numa_diff, int *node_diff)
{
int i;
int changes = 0;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (zone_diff[i]) {
atomic_long_add(zone_diff[i], &vm_zone_stat[i]);
changes++;
}
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++)
if (numa_diff[i]) {
atomic_long_add(numa_diff[i], &vm_numa_stat[i]);
changes++;
}
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++)
if (node_diff[i]) {
atomic_long_add(node_diff[i], &vm_node_stat[i]);
changes++;
}
return changes;
}
static int fold_diff(int *zone_diff, int *node_diff)
{
int i;
int changes = 0;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (zone_diff[i]) {
atomic_long_add(zone_diff[i], &vm_zone_stat[i]);
changes++;
}
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++)
if (node_diff[i]) {
atomic_long_add(node_diff[i], &vm_node_stat[i]);
changes++;
}
return changes;
}
static int refresh_cpu_vm_stats(bool do_pagesets)
{
struct pglist_data *pgdat;
struct zone *zone;
int i;
int global_zone_diff[NR_VM_ZONE_STAT_ITEMS] = { 0, };
#ifdef CONFIG_NUMA
int global_numa_diff[NR_VM_NUMA_STAT_ITEMS] = { 0, };
#endif
int global_node_diff[NR_VM_NODE_STAT_ITEMS] = { 0, };
int changes = 0;
for_each_populated_zone(zone) {
struct per_cpu_pageset __percpu *p = zone->pageset;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++) {
int v;
v = this_cpu_xchg(p->vm_stat_diff[i], 0);
if (v) {
atomic_long_add(v, &zone->vm_stat[i]);
global_zone_diff[i] += v;
#ifdef CONFIG_NUMA
__this_cpu_write(p->expire, 3);
#endif
}
}
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++) {
int v;
v = this_cpu_xchg(p->vm_numa_stat_diff[i], 0);
if (v) {
atomic_long_add(v, &zone->vm_numa_stat[i]);
global_numa_diff[i] += v;
__this_cpu_write(p->expire, 3);
}
}
if (do_pagesets) {
cond_resched();
if (!__this_cpu_read(p->expire) ||
!__this_cpu_read(p->pcp.count))
continue;
if (zone_to_nid(zone) == numa_node_id()) {
__this_cpu_write(p->expire, 0);
continue;
}
if (__this_cpu_dec_return(p->expire))
continue;
if (__this_cpu_read(p->pcp.count)) {
drain_zone_pages(zone, this_cpu_ptr(&p->pcp));
changes++;
}
}
#endif
}
for_each_online_pgdat(pgdat) {
struct per_cpu_nodestat __percpu *p = pgdat->per_cpu_nodestats;
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++) {
int v;
v = this_cpu_xchg(p->vm_node_stat_diff[i], 0);
if (v) {
atomic_long_add(v, &pgdat->vm_stat[i]);
global_node_diff[i] += v;
}
}
}
#ifdef CONFIG_NUMA
changes += fold_diff(global_zone_diff, global_numa_diff,
global_node_diff);
#else
changes += fold_diff(global_zone_diff, global_node_diff);
#endif
return changes;
}
void cpu_vm_stats_fold(int cpu)
{
struct pglist_data *pgdat;
struct zone *zone;
int i;
int global_zone_diff[NR_VM_ZONE_STAT_ITEMS] = { 0, };
#ifdef CONFIG_NUMA
int global_numa_diff[NR_VM_NUMA_STAT_ITEMS] = { 0, };
#endif
int global_node_diff[NR_VM_NODE_STAT_ITEMS] = { 0, };
for_each_populated_zone(zone) {
struct per_cpu_pageset *p;
p = per_cpu_ptr(zone->pageset, cpu);
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (p->vm_stat_diff[i]) {
int v;
v = p->vm_stat_diff[i];
p->vm_stat_diff[i] = 0;
atomic_long_add(v, &zone->vm_stat[i]);
global_zone_diff[i] += v;
}
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++)
if (p->vm_numa_stat_diff[i]) {
int v;
v = p->vm_numa_stat_diff[i];
p->vm_numa_stat_diff[i] = 0;
atomic_long_add(v, &zone->vm_numa_stat[i]);
global_numa_diff[i] += v;
}
#endif
}
for_each_online_pgdat(pgdat) {
struct per_cpu_nodestat *p;
p = per_cpu_ptr(pgdat->per_cpu_nodestats, cpu);
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++)
if (p->vm_node_stat_diff[i]) {
int v;
v = p->vm_node_stat_diff[i];
p->vm_node_stat_diff[i] = 0;
atomic_long_add(v, &pgdat->vm_stat[i]);
global_node_diff[i] += v;
}
}
#ifdef CONFIG_NUMA
fold_diff(global_zone_diff, global_numa_diff, global_node_diff);
#else
fold_diff(global_zone_diff, global_node_diff);
#endif
}
void drain_zonestat(struct zone *zone, struct per_cpu_pageset *pset)
{
int i;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (pset->vm_stat_diff[i]) {
int v = pset->vm_stat_diff[i];
pset->vm_stat_diff[i] = 0;
atomic_long_add(v, &zone->vm_stat[i]);
atomic_long_add(v, &vm_zone_stat[i]);
}
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++)
if (pset->vm_numa_stat_diff[i]) {
int v = pset->vm_numa_stat_diff[i];
pset->vm_numa_stat_diff[i] = 0;
atomic_long_add(v, &zone->vm_numa_stat[i]);
atomic_long_add(v, &vm_numa_stat[i]);
}
#endif
}
void __inc_numa_state(struct zone *zone,
enum numa_stat_item item)
{
struct per_cpu_pageset __percpu *pcp = zone->pageset;
u16 __percpu *p = pcp->vm_numa_stat_diff + item;
u16 v;
v = __this_cpu_inc_return(*p);
if (unlikely(v > NUMA_STATS_THRESHOLD)) {
zone_numa_state_add(v, zone, item);
__this_cpu_write(*p, 0);
}
}
unsigned long sum_zone_node_page_state(int node,
enum zone_stat_item item)
{
struct zone *zones = NODE_DATA(node)->node_zones;
int i;
unsigned long count = 0;
for (i = 0; i < MAX_NR_ZONES; i++)
count += zone_page_state(zones + i, item);
return count;
}
unsigned long sum_zone_numa_state(int node,
enum numa_stat_item item)
{
struct zone *zones = NODE_DATA(node)->node_zones;
int i;
unsigned long count = 0;
for (i = 0; i < MAX_NR_ZONES; i++)
count += zone_numa_state_snapshot(zones + i, item);
return count;
}
unsigned long node_page_state(struct pglist_data *pgdat,
enum node_stat_item item)
{
long x = atomic_long_read(&pgdat->vm_stat[item]);
#ifdef CONFIG_SMP
if (x < 0)
x = 0;
#endif
return x;
}
static void fill_contig_page_info(struct zone *zone,
unsigned int suitable_order,
struct contig_page_info *info)
{
unsigned int order;
info->free_pages = 0;
info->free_blocks_total = 0;
info->free_blocks_suitable = 0;
for (order = 0; order < MAX_ORDER; order++) {
unsigned long blocks;
blocks = zone->free_area[order].nr_free;
info->free_blocks_total += blocks;
info->free_pages += blocks << order;
if (order >= suitable_order)
info->free_blocks_suitable += blocks <<
(order - suitable_order);
}
}
static int __fragmentation_index(unsigned int order, struct contig_page_info *info)
{
unsigned long requested = 1UL << order;
if (WARN_ON_ONCE(order >= MAX_ORDER))
return 0;
if (!info->free_blocks_total)
return 0;
if (info->free_blocks_suitable)
return -1000;
return 1000 - div_u64( (1000+(div_u64(info->free_pages * 1000ULL, requested))), info->free_blocks_total);
}
int fragmentation_index(struct zone *zone, unsigned int order)
{
struct contig_page_info info;
fill_contig_page_info(zone, order, &info);
return __fragmentation_index(order, &info);
}
static void *frag_start(struct seq_file *m, loff_t *pos)
{
pg_data_t *pgdat;
loff_t node = *pos;
for (pgdat = first_online_pgdat();
pgdat && node;
pgdat = next_online_pgdat(pgdat))
--node;
return pgdat;
}
static void *frag_next(struct seq_file *m, void *arg, loff_t *pos)
{
pg_data_t *pgdat = (pg_data_t *)arg;
(*pos)++;
return next_online_pgdat(pgdat);
}
static void frag_stop(struct seq_file *m, void *arg)
{
}
static void walk_zones_in_node(struct seq_file *m, pg_data_t *pgdat,
bool assert_populated, bool nolock,
void (*print)(struct seq_file *m, pg_data_t *, struct zone *))
{
struct zone *zone;
struct zone *node_zones = pgdat->node_zones;
unsigned long flags;
for (zone = node_zones; zone - node_zones < MAX_NR_ZONES; ++zone) {
if (assert_populated && !populated_zone(zone))
continue;
if (!nolock)
spin_lock_irqsave(&zone->lock, flags);
print(m, pgdat, zone);
if (!nolock)
spin_unlock_irqrestore(&zone->lock, flags);
}
}
static void frag_show_print(struct seq_file *m, pg_data_t *pgdat,
struct zone *zone)
{
int order;
seq_printf(m, "Node %d, zone %8s ", pgdat->node_id, zone->name);
for (order = 0; order < MAX_ORDER; ++order)
seq_printf(m, "%6lu ", zone->free_area[order].nr_free);
seq_putc(m, '\n');
}
static int frag_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
walk_zones_in_node(m, pgdat, true, false, frag_show_print);
return 0;
}
static void pagetypeinfo_showfree_print(struct seq_file *m,
pg_data_t *pgdat, struct zone *zone)
{
int order, mtype;
for (mtype = 0; mtype < MIGRATE_TYPES; mtype++) {
seq_printf(m, "Node %4d, zone %8s, type %12s ",
pgdat->node_id,
zone->name,
migratetype_names[mtype]);
for (order = 0; order < MAX_ORDER; ++order) {
unsigned long freecount = 0;
struct free_area *area;
struct list_head *curr;
area = &(zone->free_area[order]);
list_for_each(curr, &area->free_list[mtype])
freecount++;
seq_printf(m, "%6lu ", freecount);
}
seq_putc(m, '\n');
}
}
static int pagetypeinfo_showfree(struct seq_file *m, void *arg)
{
int order;
pg_data_t *pgdat = (pg_data_t *)arg;
seq_printf(m, "%-43s ", "Free pages count per migrate type at order");
for (order = 0; order < MAX_ORDER; ++order)
seq_printf(m, "%6d ", order);
seq_putc(m, '\n');
walk_zones_in_node(m, pgdat, true, false, pagetypeinfo_showfree_print);
return 0;
}
static void pagetypeinfo_showblockcount_print(struct seq_file *m,
pg_data_t *pgdat, struct zone *zone)
{
int mtype;
unsigned long pfn;
unsigned long start_pfn = zone->zone_start_pfn;
unsigned long end_pfn = zone_end_pfn(zone);
unsigned long count[MIGRATE_TYPES] = { 0, };
for (pfn = start_pfn; pfn < end_pfn; pfn += pageblock_nr_pages) {
struct page *page;
page = pfn_to_online_page(pfn);
if (!page)
continue;
if (!memmap_valid_within(pfn, page, zone))
continue;
if (page_zone(page) != zone)
continue;
mtype = get_pageblock_migratetype(page);
if (mtype < MIGRATE_TYPES)
count[mtype]++;
}
seq_printf(m, "Node %d, zone %8s ", pgdat->node_id, zone->name);
for (mtype = 0; mtype < MIGRATE_TYPES; mtype++)
seq_printf(m, "%12lu ", count[mtype]);
seq_putc(m, '\n');
}
static int pagetypeinfo_showblockcount(struct seq_file *m, void *arg)
{
int mtype;
pg_data_t *pgdat = (pg_data_t *)arg;
seq_printf(m, "\n%-23s", "Number of blocks type ");
for (mtype = 0; mtype < MIGRATE_TYPES; mtype++)
seq_printf(m, "%12s ", migratetype_names[mtype]);
seq_putc(m, '\n');
walk_zones_in_node(m, pgdat, true, false,
pagetypeinfo_showblockcount_print);
return 0;
}
static void pagetypeinfo_showmixedcount(struct seq_file *m, pg_data_t *pgdat)
{
#ifdef CONFIG_PAGE_OWNER
int mtype;
if (!static_branch_unlikely(&page_owner_inited))
return;
drain_all_pages(NULL);
seq_printf(m, "\n%-23s", "Number of mixed blocks ");
for (mtype = 0; mtype < MIGRATE_TYPES; mtype++)
seq_printf(m, "%12s ", migratetype_names[mtype]);
seq_putc(m, '\n');
walk_zones_in_node(m, pgdat, true, true,
pagetypeinfo_showmixedcount_print);
#endif
}
static int pagetypeinfo_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
if (!node_state(pgdat->node_id, N_MEMORY))
return 0;
seq_printf(m, "Page block order: %d\n", pageblock_order);
seq_printf(m, "Pages per block: %lu\n", pageblock_nr_pages);
seq_putc(m, '\n');
pagetypeinfo_showfree(m, pgdat);
pagetypeinfo_showblockcount(m, pgdat);
pagetypeinfo_showmixedcount(m, pgdat);
return 0;
}
static int fragmentation_open(struct inode *inode, struct file *file)
{
return seq_open(file, &fragmentation_op);
}
static int pagetypeinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &pagetypeinfo_op);
}
static bool is_zone_first_populated(pg_data_t *pgdat, struct zone *zone)
{
int zid;
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
struct zone *compare = &pgdat->node_zones[zid];
if (populated_zone(compare))
return zone == compare;
}
return false;
}
static void zoneinfo_show_print(struct seq_file *m, pg_data_t *pgdat,
struct zone *zone)
{
int i;
seq_printf(m, "Node %d, zone %8s", pgdat->node_id, zone->name);
if (is_zone_first_populated(pgdat, zone)) {
seq_printf(m, "\n per-node stats");
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++) {
seq_printf(m, "\n %-12s %lu",
vmstat_text[i + NR_VM_ZONE_STAT_ITEMS +
NR_VM_NUMA_STAT_ITEMS],
node_page_state(pgdat, i));
}
}
seq_printf(m,
"\n pages free %lu"
"\n min %lu"
"\n low %lu"
"\n high %lu"
"\n spanned %lu"
"\n present %lu"
"\n managed %lu",
zone_page_state(zone, NR_FREE_PAGES),
min_wmark_pages(zone),
low_wmark_pages(zone),
high_wmark_pages(zone),
zone->spanned_pages,
zone->present_pages,
zone->managed_pages);
seq_printf(m,
"\n protection: (%ld",
zone->lowmem_reserve[0]);
for (i = 1; i < ARRAY_SIZE(zone->lowmem_reserve); i++)
seq_printf(m, ", %ld", zone->lowmem_reserve[i]);
seq_putc(m, ')');
if (!populated_zone(zone)) {
seq_putc(m, '\n');
return;
}
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
seq_printf(m, "\n %-12s %lu", vmstat_text[i],
zone_page_state(zone, i));
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++)
seq_printf(m, "\n %-12s %lu",
vmstat_text[i + NR_VM_ZONE_STAT_ITEMS],
zone_numa_state_snapshot(zone, i));
#endif
seq_printf(m, "\n pagesets");
for_each_online_cpu(i) {
struct per_cpu_pageset *pageset;
pageset = per_cpu_ptr(zone->pageset, i);
seq_printf(m,
"\n cpu: %i"
"\n count: %i"
"\n high: %i"
"\n batch: %i",
i,
pageset->pcp.count,
pageset->pcp.high,
pageset->pcp.batch);
#ifdef CONFIG_SMP
seq_printf(m, "\n vm stats threshold: %d",
pageset->stat_threshold);
#endif
}
seq_printf(m,
"\n node_unreclaimable: %u"
"\n start_pfn: %lu"
"\n node_inactive_ratio: %u",
pgdat->kswapd_failures >= MAX_RECLAIM_RETRIES,
zone->zone_start_pfn,
zone->zone_pgdat->inactive_ratio);
seq_putc(m, '\n');
}
static int zoneinfo_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
walk_zones_in_node(m, pgdat, false, false, zoneinfo_show_print);
return 0;
}
static int zoneinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &zoneinfo_op);
}
static void *vmstat_start(struct seq_file *m, loff_t *pos)
{
unsigned long *v;
int i, stat_items_size;
if (*pos >= ARRAY_SIZE(vmstat_text))
return NULL;
stat_items_size = NR_VM_ZONE_STAT_ITEMS * sizeof(unsigned long) +
NR_VM_NUMA_STAT_ITEMS * sizeof(unsigned long) +
NR_VM_NODE_STAT_ITEMS * sizeof(unsigned long) +
NR_VM_WRITEBACK_STAT_ITEMS * sizeof(unsigned long);
#ifdef CONFIG_VM_EVENT_COUNTERS
stat_items_size += sizeof(struct vm_event_state);
#endif
v = kmalloc(stat_items_size, GFP_KERNEL);
m->private = v;
if (!v)
return ERR_PTR(-ENOMEM);
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
v[i] = global_zone_page_state(i);
v += NR_VM_ZONE_STAT_ITEMS;
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++)
v[i] = global_numa_state(i);
v += NR_VM_NUMA_STAT_ITEMS;
#endif
for (i = 0; i < NR_VM_NODE_STAT_ITEMS; i++)
v[i] = global_node_page_state(i);
v += NR_VM_NODE_STAT_ITEMS;
global_dirty_limits(v + NR_DIRTY_BG_THRESHOLD,
v + NR_DIRTY_THRESHOLD);
v += NR_VM_WRITEBACK_STAT_ITEMS;
#ifdef CONFIG_VM_EVENT_COUNTERS
all_vm_events(v);
v[PGPGIN] /= 2;
v[PGPGOUT] /= 2;
#endif
return (unsigned long *)m->private + *pos;
}
static void *vmstat_next(struct seq_file *m, void *arg, loff_t *pos)
{
(*pos)++;
if (*pos >= ARRAY_SIZE(vmstat_text))
return NULL;
return (unsigned long *)m->private + *pos;
}
static int vmstat_show(struct seq_file *m, void *arg)
{
unsigned long *l = arg;
unsigned long off = l - (unsigned long *)m->private;
seq_puts(m, vmstat_text[off]);
seq_put_decimal_ull(m, " ", *l);
seq_putc(m, '\n');
return 0;
}
static void vmstat_stop(struct seq_file *m, void *arg)
{
kfree(m->private);
m->private = NULL;
}
static int vmstat_open(struct inode *inode, struct file *file)
{
return seq_open(file, &vmstat_op);
}
static void refresh_vm_stats(struct work_struct *work)
{
refresh_cpu_vm_stats(true);
}
int vmstat_refresh(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
long val;
int err;
int i;
err = schedule_on_each_cpu(refresh_vm_stats);
if (err)
return err;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++) {
val = atomic_long_read(&vm_zone_stat[i]);
if (val < 0) {
pr_warn("%s: %s %ld\n",
__func__, vmstat_text[i], val);
err = -EINVAL;
}
}
#ifdef CONFIG_NUMA
for (i = 0; i < NR_VM_NUMA_STAT_ITEMS; i++) {
val = atomic_long_read(&vm_numa_stat[i]);
if (val < 0) {
pr_warn("%s: %s %ld\n",
__func__, vmstat_text[i + NR_VM_ZONE_STAT_ITEMS], val);
err = -EINVAL;
}
}
#endif
if (err)
return err;
if (write)
*ppos += *lenp;
else
*lenp = 0;
return 0;
}
static void vmstat_update(struct work_struct *w)
{
if (refresh_cpu_vm_stats(true)) {
queue_delayed_work_on(smp_processor_id(), mm_percpu_wq,
this_cpu_ptr(&vmstat_work),
round_jiffies_relative(sysctl_stat_interval));
}
}
static bool need_update(int cpu)
{
struct zone *zone;
for_each_populated_zone(zone) {
struct per_cpu_pageset *p = per_cpu_ptr(zone->pageset, cpu);
BUILD_BUG_ON(sizeof(p->vm_stat_diff[0]) != 1);
#ifdef CONFIG_NUMA
BUILD_BUG_ON(sizeof(p->vm_numa_stat_diff[0]) != 2);
#endif
if (memchr_inv(p->vm_stat_diff, 0, NR_VM_ZONE_STAT_ITEMS))
return true;
#ifdef CONFIG_NUMA
if (memchr_inv(p->vm_numa_stat_diff, 0, NR_VM_NUMA_STAT_ITEMS))
return true;
#endif
}
return false;
}
void quiet_vmstat(void)
{
if (system_state != SYSTEM_RUNNING)
return;
if (!delayed_work_pending(this_cpu_ptr(&vmstat_work)))
return;
if (!need_update(smp_processor_id()))
return;
refresh_cpu_vm_stats(false);
}
static void vmstat_shepherd(struct work_struct *w)
{
int cpu;
get_online_cpus();
for_each_online_cpu(cpu) {
struct delayed_work *dw = &per_cpu(vmstat_work, cpu);
if (!delayed_work_pending(dw) && need_update(cpu))
queue_delayed_work_on(cpu, mm_percpu_wq, dw, 0);
}
put_online_cpus();
schedule_delayed_work(&shepherd,
round_jiffies_relative(sysctl_stat_interval));
}
static void __init start_shepherd_timer(void)
{
int cpu;
for_each_possible_cpu(cpu)
INIT_DEFERRABLE_WORK(per_cpu_ptr(&vmstat_work, cpu),
vmstat_update);
schedule_delayed_work(&shepherd,
round_jiffies_relative(sysctl_stat_interval));
}
static void __init init_cpu_node_state(void)
{
int node;
for_each_online_node(node) {
if (cpumask_weight(cpumask_of_node(node)) > 0)
node_set_state(node, N_CPU);
}
}
static int vmstat_cpu_online(unsigned int cpu)
{
refresh_zone_stat_thresholds();
node_set_state(cpu_to_node(cpu), N_CPU);
return 0;
}
static int vmstat_cpu_down_prep(unsigned int cpu)
{
cancel_delayed_work_sync(&per_cpu(vmstat_work, cpu));
return 0;
}
static int vmstat_cpu_dead(unsigned int cpu)
{
const struct cpumask *node_cpus;
int node;
node = cpu_to_node(cpu);
refresh_zone_stat_thresholds();
node_cpus = cpumask_of_node(node);
if (cpumask_weight(node_cpus) > 0)
return 0;
node_clear_state(node, N_CPU);
return 0;
}
void __init init_mm_internals(void)
{
int ret __maybe_unused;
mm_percpu_wq = alloc_workqueue("mm_percpu_wq", WQ_MEM_RECLAIM, 0);
#ifdef CONFIG_SMP
ret = cpuhp_setup_state_nocalls(CPUHP_MM_VMSTAT_DEAD, "mm/vmstat:dead",
NULL, vmstat_cpu_dead);
if (ret < 0)
pr_err("vmstat: failed to register 'dead' hotplug state\n");
ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN, "mm/vmstat:online",
vmstat_cpu_online,
vmstat_cpu_down_prep);
if (ret < 0)
pr_err("vmstat: failed to register 'online' hotplug state\n");
get_online_cpus();
init_cpu_node_state();
put_online_cpus();
start_shepherd_timer();
#endif
#ifdef CONFIG_PROC_FS
proc_create("buddyinfo", 0444, NULL, &buddyinfo_file_operations);
proc_create("pagetypeinfo", 0444, NULL, &pagetypeinfo_file_operations);
proc_create("vmstat", 0444, NULL, &vmstat_file_operations);
proc_create("zoneinfo", 0444, NULL, &zoneinfo_file_operations);
#endif
}
static int unusable_free_index(unsigned int order,
struct contig_page_info *info)
{
if (info->free_pages == 0)
return 1000;
return div_u64((info->free_pages - (info->free_blocks_suitable << order)) * 1000ULL, info->free_pages);
}
static void unusable_show_print(struct seq_file *m,
pg_data_t *pgdat, struct zone *zone)
{
unsigned int order;
int index;
struct contig_page_info info;
seq_printf(m, "Node %d, zone %8s ",
pgdat->node_id,
zone->name);
for (order = 0; order < MAX_ORDER; ++order) {
fill_contig_page_info(zone, order, &info);
index = unusable_free_index(order, &info);
seq_printf(m, "%d.%03d ", index / 1000, index % 1000);
}
seq_putc(m, '\n');
}
static int unusable_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
if (!node_state(pgdat->node_id, N_MEMORY))
return 0;
walk_zones_in_node(m, pgdat, true, false, unusable_show_print);
return 0;
}
static int unusable_open(struct inode *inode, struct file *file)
{
return seq_open(file, &unusable_op);
}
static void extfrag_show_print(struct seq_file *m,
pg_data_t *pgdat, struct zone *zone)
{
unsigned int order;
int index;
struct contig_page_info info;
seq_printf(m, "Node %d, zone %8s ",
pgdat->node_id,
zone->name);
for (order = 0; order < MAX_ORDER; ++order) {
fill_contig_page_info(zone, order, &info);
index = __fragmentation_index(order, &info);
seq_printf(m, "%d.%03d ", index / 1000, index % 1000);
}
seq_putc(m, '\n');
}
static int extfrag_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
walk_zones_in_node(m, pgdat, true, false, extfrag_show_print);
return 0;
}
static int extfrag_open(struct inode *inode, struct file *file)
{
return seq_open(file, &extfrag_op);
}
static int __init extfrag_debug_init(void)
{
struct dentry *extfrag_debug_root;
extfrag_debug_root = debugfs_create_dir("extfrag", NULL);
if (!extfrag_debug_root)
return -ENOMEM;
if (!debugfs_create_file("unusable_index", 0444,
extfrag_debug_root, NULL, &unusable_file_ops))
goto fail;
if (!debugfs_create_file("extfrag_index", 0444,
extfrag_debug_root, NULL, &extfrag_file_ops))
goto fail;
return 0;
fail:
debugfs_remove_recursive(extfrag_debug_root);
return -ENOMEM;
}
