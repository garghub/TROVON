unsigned int rds_ib_stats_info_copy(struct rds_info_iterator *iter,
unsigned int avail)
{
struct rds_ib_statistics stats = {0, };
uint64_t *src;
uint64_t *sum;
size_t i;
int cpu;
if (avail < ARRAY_SIZE(rds_ib_stat_names))
goto out;
for_each_online_cpu(cpu) {
src = (uint64_t *)&(per_cpu(rds_ib_stats, cpu));
sum = (uint64_t *)&stats;
for (i = 0; i < sizeof(stats) / sizeof(uint64_t); i++)
*(sum++) += *(src++);
}
rds_stats_info_copy(iter, (uint64_t *)&stats, rds_ib_stat_names,
ARRAY_SIZE(rds_ib_stat_names));
out:
return ARRAY_SIZE(rds_ib_stat_names);
}
