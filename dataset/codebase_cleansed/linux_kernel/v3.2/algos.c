int __init raid6_select_algo(void)
{
const struct raid6_calls * const * algo;
const struct raid6_calls * best;
char *syndromes;
void *dptrs[(65536/PAGE_SIZE)+2];
int i, disks;
unsigned long perf, bestperf;
int bestprefer;
unsigned long j0, j1;
disks = (65536/PAGE_SIZE)+2;
for ( i = 0 ; i < disks-2 ; i++ ) {
dptrs[i] = ((char *)raid6_gfmul) + PAGE_SIZE*i;
}
syndromes = (void *) __get_free_pages(GFP_KERNEL, 1);
if ( !syndromes ) {
printk("raid6: Yikes! No memory available.\n");
return -ENOMEM;
}
dptrs[disks-2] = syndromes;
dptrs[disks-1] = syndromes + PAGE_SIZE;
bestperf = 0; bestprefer = 0; best = NULL;
for ( algo = raid6_algos ; *algo ; algo++ ) {
if ( !(*algo)->valid || (*algo)->valid() ) {
perf = 0;
preempt_disable();
j0 = jiffies;
while ( (j1 = jiffies) == j0 )
cpu_relax();
while (time_before(jiffies,
j1 + (1<<RAID6_TIME_JIFFIES_LG2))) {
(*algo)->gen_syndrome(disks, PAGE_SIZE, dptrs);
perf++;
}
preempt_enable();
if ( (*algo)->prefer > bestprefer ||
((*algo)->prefer == bestprefer &&
perf > bestperf) ) {
best = *algo;
bestprefer = best->prefer;
bestperf = perf;
}
printk("raid6: %-8s %5ld MB/s\n", (*algo)->name,
(perf*HZ) >> (20-16+RAID6_TIME_JIFFIES_LG2));
}
}
if (best) {
printk("raid6: using algorithm %s (%ld MB/s)\n",
best->name,
(bestperf*HZ) >> (20-16+RAID6_TIME_JIFFIES_LG2));
raid6_call = *best;
} else
printk("raid6: Yikes! No algorithm found!\n");
free_pages((unsigned long)syndromes, 1);
return best ? 0 : -EINVAL;
}
static void raid6_exit(void)
{
do { } while (0);
}
