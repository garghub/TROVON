static int __init_cache_level(unsigned int cpu)
{
struct cpuinfo_mips *c = &current_cpu_data;
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
int levels = 0, leaves = 0;
if (c->dcache.waysize)
levels += 1;
else
return -ENOENT;
leaves += (c->icache.waysize) ? 2 : 1;
if (c->scache.waysize) {
levels++;
leaves++;
}
if (c->tcache.waysize) {
levels++;
leaves++;
}
this_cpu_ci->num_levels = levels;
this_cpu_ci->num_leaves = leaves;
return 0;
}
static int __populate_cache_leaves(unsigned int cpu)
{
struct cpuinfo_mips *c = &current_cpu_data;
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
struct cacheinfo *this_leaf = this_cpu_ci->info_list;
if (c->icache.waysize) {
populate_cache(dcache, this_leaf, 1, CACHE_TYPE_DATA);
populate_cache(icache, this_leaf, 1, CACHE_TYPE_INST);
} else {
populate_cache(dcache, this_leaf, 1, CACHE_TYPE_UNIFIED);
}
if (c->scache.waysize)
populate_cache(scache, this_leaf, 2, CACHE_TYPE_UNIFIED);
if (c->tcache.waysize)
populate_cache(tcache, this_leaf, 3, CACHE_TYPE_UNIFIED);
return 0;
}
