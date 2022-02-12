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
struct zone *zone;
int cpu;
int threshold;
for_each_populated_zone(zone) {
unsigned long max_drift, tolerate_drift;
threshold = calculate_normal_threshold(zone);
for_each_online_cpu(cpu)
per_cpu_ptr(zone->pageset, cpu)->stat_threshold
= threshold;
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
for_each_possible_cpu(cpu)
per_cpu_ptr(zone->pageset, cpu)->stat_threshold
= threshold;
}
}
void __mod_zone_page_state(struct zone *zone, enum zone_stat_item item,
int delta)
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
void __inc_zone_page_state(struct page *page, enum zone_stat_item item)
{
__inc_zone_state(page_zone(page), item);
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
void __dec_zone_page_state(struct page *page, enum zone_stat_item item)
{
__dec_zone_state(page_zone(page), item);
}
static inline void mod_state(struct zone *zone,
enum zone_stat_item item, int delta, int overstep_mode)
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
int delta)
{
mod_state(zone, item, delta, 0);
}
void inc_zone_state(struct zone *zone, enum zone_stat_item item)
{
mod_state(zone, item, 1, 1);
}
void inc_zone_page_state(struct page *page, enum zone_stat_item item)
{
mod_state(page_zone(page), item, 1, 1);
}
void dec_zone_page_state(struct page *page, enum zone_stat_item item)
{
mod_state(page_zone(page), item, -1, -1);
}
void mod_zone_page_state(struct zone *zone, enum zone_stat_item item,
int delta)
{
unsigned long flags;
local_irq_save(flags);
__mod_zone_page_state(zone, item, delta);
local_irq_restore(flags);
}
void inc_zone_state(struct zone *zone, enum zone_stat_item item)
{
unsigned long flags;
local_irq_save(flags);
__inc_zone_state(zone, item);
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
void refresh_cpu_vm_stats(int cpu)
{
struct zone *zone;
int i;
int global_diff[NR_VM_ZONE_STAT_ITEMS] = { 0, };
for_each_populated_zone(zone) {
struct per_cpu_pageset *p;
p = per_cpu_ptr(zone->pageset, cpu);
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (p->vm_stat_diff[i]) {
unsigned long flags;
int v;
local_irq_save(flags);
v = p->vm_stat_diff[i];
p->vm_stat_diff[i] = 0;
local_irq_restore(flags);
atomic_long_add(v, &zone->vm_stat[i]);
global_diff[i] += v;
#ifdef CONFIG_NUMA
p->expire = 3;
#endif
}
cond_resched();
#ifdef CONFIG_NUMA
if (!p->expire || !p->pcp.count)
continue;
if (zone_to_nid(zone) == numa_node_id()) {
p->expire = 0;
continue;
}
p->expire--;
if (p->expire)
continue;
if (p->pcp.count)
drain_zone_pages(zone, &p->pcp);
#endif
}
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (global_diff[i])
atomic_long_add(global_diff[i], &vm_stat[i]);
}
void drain_zonestat(struct zone *zone, struct per_cpu_pageset *pset)
{
int i;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
if (pset->vm_stat_diff[i]) {
int v = pset->vm_stat_diff[i];
pset->vm_stat_diff[i] = 0;
atomic_long_add(v, &zone->vm_stat[i]);
atomic_long_add(v, &vm_stat[i]);
}
}
void zone_statistics(struct zone *preferred_zone, struct zone *z, gfp_t flags)
{
if (z->zone_pgdat == preferred_zone->zone_pgdat) {
__inc_zone_state(z, NUMA_HIT);
} else {
__inc_zone_state(z, NUMA_MISS);
__inc_zone_state(preferred_zone, NUMA_FOREIGN);
}
if (z->node == ((flags & __GFP_OTHER_NODE) ?
preferred_zone->node : numa_node_id()))
__inc_zone_state(z, NUMA_LOCAL);
else
__inc_zone_state(z, NUMA_OTHER);
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
void (*print)(struct seq_file *m, pg_data_t *, struct zone *))
{
struct zone *zone;
struct zone *node_zones = pgdat->node_zones;
unsigned long flags;
for (zone = node_zones; zone - node_zones < MAX_NR_ZONES; ++zone) {
if (!populated_zone(zone))
continue;
spin_lock_irqsave(&zone->lock, flags);
print(m, pgdat, zone);
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
walk_zones_in_node(m, pgdat, frag_show_print);
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
walk_zones_in_node(m, pgdat, pagetypeinfo_showfree_print);
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
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (!memmap_valid_within(pfn, page, zone))
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
walk_zones_in_node(m, pgdat, pagetypeinfo_showblockcount_print);
return 0;
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
static void zoneinfo_show_print(struct seq_file *m, pg_data_t *pgdat,
struct zone *zone)
{
int i;
seq_printf(m, "Node %d, zone %8s", pgdat->node_id, zone->name);
seq_printf(m,
"\n pages free %lu"
"\n min %lu"
"\n low %lu"
"\n high %lu"
"\n scanned %lu"
"\n spanned %lu"
"\n present %lu"
"\n managed %lu",
zone_page_state(zone, NR_FREE_PAGES),
min_wmark_pages(zone),
low_wmark_pages(zone),
high_wmark_pages(zone),
zone->pages_scanned,
zone->spanned_pages,
zone->present_pages,
zone->managed_pages);
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
seq_printf(m, "\n %-12s %lu", vmstat_text[i],
zone_page_state(zone, i));
seq_printf(m,
"\n protection: (%lu",
zone->lowmem_reserve[0]);
for (i = 1; i < ARRAY_SIZE(zone->lowmem_reserve); i++)
seq_printf(m, ", %lu", zone->lowmem_reserve[i]);
seq_printf(m,
")"
"\n pagesets");
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
"\n all_unreclaimable: %u"
"\n start_pfn: %lu"
"\n inactive_ratio: %u",
zone->all_unreclaimable,
zone->zone_start_pfn,
zone->inactive_ratio);
seq_putc(m, '\n');
}
static int zoneinfo_show(struct seq_file *m, void *arg)
{
pg_data_t *pgdat = (pg_data_t *)arg;
walk_zones_in_node(m, pgdat, zoneinfo_show_print);
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
NR_VM_WRITEBACK_STAT_ITEMS * sizeof(unsigned long);
#ifdef CONFIG_VM_EVENT_COUNTERS
stat_items_size += sizeof(struct vm_event_state);
#endif
v = kmalloc(stat_items_size, GFP_KERNEL);
m->private = v;
if (!v)
return ERR_PTR(-ENOMEM);
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
v[i] = global_page_state(i);
v += NR_VM_ZONE_STAT_ITEMS;
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
seq_printf(m, "%s %lu\n", vmstat_text[off], *l);
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
static void vmstat_update(struct work_struct *w)
{
refresh_cpu_vm_stats(smp_processor_id());
schedule_delayed_work(&__get_cpu_var(vmstat_work),
round_jiffies_relative(sysctl_stat_interval));
}
static void start_cpu_timer(int cpu)
{
struct delayed_work *work = &per_cpu(vmstat_work, cpu);
INIT_DEFERRABLE_WORK(work, vmstat_update);
schedule_delayed_work_on(cpu, work, __round_jiffies_relative(HZ, cpu));
}
static int vmstat_cpuup_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
long cpu = (long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
refresh_zone_stat_thresholds();
start_cpu_timer(cpu);
node_set_state(cpu_to_node(cpu), N_CPU);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
cancel_delayed_work_sync(&per_cpu(vmstat_work, cpu));
per_cpu(vmstat_work, cpu).work.func = NULL;
break;
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
start_cpu_timer(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
refresh_zone_stat_thresholds();
break;
default:
break;
}
return NOTIFY_OK;
}
static int __init setup_vmstat(void)
{
#ifdef CONFIG_SMP
int cpu;
register_cpu_notifier(&vmstat_notifier);
for_each_online_cpu(cpu)
start_cpu_timer(cpu);
#endif
#ifdef CONFIG_PROC_FS
proc_create("buddyinfo", S_IRUGO, NULL, &fragmentation_file_operations);
proc_create("pagetypeinfo", S_IRUGO, NULL, &pagetypeinfo_file_ops);
proc_create("vmstat", S_IRUGO, NULL, &proc_vmstat_file_operations);
proc_create("zoneinfo", S_IRUGO, NULL, &proc_zoneinfo_file_operations);
#endif
return 0;
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
walk_zones_in_node(m, pgdat, unusable_show_print);
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
walk_zones_in_node(m, pgdat, extfrag_show_print);
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
