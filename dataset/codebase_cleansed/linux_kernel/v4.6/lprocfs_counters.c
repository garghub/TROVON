void lprocfs_counter_add(struct lprocfs_stats *stats, int idx, long amount)
{
struct lprocfs_counter *percpu_cntr;
struct lprocfs_counter_header *header;
int smp_id;
unsigned long flags = 0;
if (!stats)
return;
LASSERTF(0 <= idx && idx < stats->ls_num,
"idx %d, ls_num %hu\n", idx, stats->ls_num);
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
if (!stats)
return;
LASSERTF(0 <= idx && idx < stats->ls_num,
"idx %d, ls_num %hu\n", idx, stats->ls_num);
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
