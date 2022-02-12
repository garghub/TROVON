static unsigned long max_pages(unsigned long min_pages)
{
unsigned long node_free_pages, max;
int node = numa_node_id();
struct zone *zones = NODE_DATA(node)->node_zones;
int num_cpus_on_node;
node_free_pages =
#ifdef CONFIG_ZONE_DMA
zone_page_state(&zones[ZONE_DMA], NR_FREE_PAGES) +
#endif
#ifdef CONFIG_ZONE_DMA32
zone_page_state(&zones[ZONE_DMA32], NR_FREE_PAGES) +
#endif
zone_page_state(&zones[ZONE_NORMAL], NR_FREE_PAGES);
max = node_free_pages / FRACTION_OF_NODE_MEM;
num_cpus_on_node = cpumask_weight(cpumask_of_node(node));
max /= num_cpus_on_node;
return max(max, min_pages);
}
static long min_pages_to_free(struct quicklist *q,
unsigned long min_pages, long max_free)
{
long pages_to_free;
pages_to_free = q->nr_pages - max_pages(min_pages);
return min(pages_to_free, max_free);
}
void quicklist_trim(int nr, void (*dtor)(void *),
unsigned long min_pages, unsigned long max_free)
{
long pages_to_free;
struct quicklist *q;
q = &get_cpu_var(quicklist)[nr];
if (q->nr_pages > min_pages) {
pages_to_free = min_pages_to_free(q, min_pages, max_free);
while (pages_to_free > 0) {
void *p = quicklist_alloc(nr, 0, NULL);
if (dtor)
dtor(p);
free_page((unsigned long)p);
pages_to_free--;
}
}
put_cpu_var(quicklist);
}
unsigned long quicklist_total_size(void)
{
unsigned long count = 0;
int cpu;
struct quicklist *ql, *q;
for_each_online_cpu(cpu) {
ql = per_cpu(quicklist, cpu);
for (q = ql; q < ql + CONFIG_NR_QUICK; q++)
count += q->nr_pages;
}
return count;
}
