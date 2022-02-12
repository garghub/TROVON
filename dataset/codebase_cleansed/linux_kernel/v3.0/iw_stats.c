unsigned int rds_iw_stats_info_copy(struct rds_info_iterator *iter,
unsigned int avail)
{
struct rds_iw_statistics stats = {0, };
uint64_t *src;
uint64_t *sum;
size_t i;
int cpu;
if (avail < ARRAY_SIZE(rds_iw_stat_names))
goto out;
for_each_online_cpu(cpu) {
src = (uint64_t *)&(per_cpu(rds_iw_stats, cpu));
sum = (uint64_t *)&stats;
for (i = 0; i < sizeof(stats) / sizeof(uint64_t); i++)
*(sum++) += *(src++);
}
rds_stats_info_copy(iter, (uint64_t *)&stats, rds_iw_stat_names,
ARRAY_SIZE(rds_iw_stat_names));
out:
return ARRAY_SIZE(rds_iw_stat_names);
}
