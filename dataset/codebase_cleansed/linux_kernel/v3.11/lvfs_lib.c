void lprocfs_counter_add(struct lprocfs_stats *stats, int idx, long amount)
{
struct lprocfs_counter *percpu_cntr;
struct lprocfs_counter_header *header;
int smp_id;
unsigned long flags = 0;
if (stats == NULL)
return;
smp_id = lprocfs_stats_lock(stats, LPROCFS_GET_SMP_ID, &flags);
if (smp_id < 0)
return;
header = &stats->ls_cnt_header[idx];
percpu_cntr = lprocfs_stats_counter_get(stats, smp_id, idx);
percpu_cntr->lc_count++;
if (header->lc_config & LPROCFS_CNTR_AVGMINMAX) {
if (in_interrupt() &&
(stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE) != 0)
percpu_cntr->lc_sum_irq += amount;
else
percpu_cntr->lc_sum += amount;
if (header->lc_config & LPROCFS_CNTR_STDDEV)
percpu_cntr->lc_sumsquare += (__s64)amount * amount;
if (amount < percpu_cntr->lc_min)
percpu_cntr->lc_min = amount;
if (amount > percpu_cntr->lc_max)
percpu_cntr->lc_max = amount;
}
lprocfs_stats_unlock(stats, LPROCFS_GET_SMP_ID, &flags);
}
void lprocfs_counter_sub(struct lprocfs_stats *stats, int idx, long amount)
{
struct lprocfs_counter *percpu_cntr;
struct lprocfs_counter_header *header;
int smp_id;
unsigned long flags = 0;
if (stats == NULL)
return;
smp_id = lprocfs_stats_lock(stats, LPROCFS_GET_SMP_ID, &flags);
if (smp_id < 0)
return;
header = &stats->ls_cnt_header[idx];
percpu_cntr = lprocfs_stats_counter_get(stats, smp_id, idx);
if (header->lc_config & LPROCFS_CNTR_AVGMINMAX) {
if (in_interrupt() &&
(stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE) != 0)
percpu_cntr->lc_sum_irq -= amount;
else
percpu_cntr->lc_sum -= amount;
}
lprocfs_stats_unlock(stats, LPROCFS_GET_SMP_ID, &flags);
}
int lprocfs_stats_alloc_one(struct lprocfs_stats *stats, unsigned int cpuid)
{
struct lprocfs_counter *cntr;
unsigned int percpusize;
int rc = -ENOMEM;
unsigned long flags = 0;
int i;
LASSERT(stats->ls_percpu[cpuid] == NULL);
LASSERT((stats->ls_flags & LPROCFS_STATS_FLAG_NOPERCPU) == 0);
percpusize = lprocfs_stats_counter_size(stats);
LIBCFS_ALLOC_ATOMIC(stats->ls_percpu[cpuid], percpusize);
if (stats->ls_percpu[cpuid] != NULL) {
rc = 0;
if (unlikely(stats->ls_biggest_alloc_num <= cpuid)) {
if (stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE)
spin_lock_irqsave(&stats->ls_lock, flags);
else
spin_lock(&stats->ls_lock);
if (stats->ls_biggest_alloc_num <= cpuid)
stats->ls_biggest_alloc_num = cpuid + 1;
if (stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE) {
spin_unlock_irqrestore(&stats->ls_lock, flags);
} else {
spin_unlock(&stats->ls_lock);
}
}
for (i = 0; i < stats->ls_num; ++i) {
cntr = lprocfs_stats_counter_get(stats, cpuid, i);
cntr->lc_min = LC_MIN_INIT;
}
}
return rc;
}
