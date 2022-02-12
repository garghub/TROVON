int cpumask_next_and(int n, const struct cpumask *src1p,
const struct cpumask *src2p)
{
while ((n = cpumask_next(n, src1p)) < nr_cpu_ids)
if (cpumask_test_cpu(n, src2p))
break;
return n;
}
int cpumask_any_but(const struct cpumask *mask, unsigned int cpu)
{
unsigned int i;
cpumask_check(cpu);
for_each_cpu(i, mask)
if (i != cpu)
break;
return i;
}
int cpumask_next_wrap(int n, const struct cpumask *mask, int start, bool wrap)
{
int next;
again:
next = cpumask_next(n, mask);
if (wrap && n < start && next >= start) {
return nr_cpumask_bits;
} else if (next >= nr_cpumask_bits) {
wrap = true;
n = -1;
goto again;
}
return next;
}
bool alloc_cpumask_var_node(cpumask_var_t *mask, gfp_t flags, int node)
{
*mask = kmalloc_node(cpumask_size(), flags, node);
#ifdef CONFIG_DEBUG_PER_CPU_MAPS
if (!*mask) {
printk(KERN_ERR "=> alloc_cpumask_var: failed!\n");
dump_stack();
}
#endif
return *mask != NULL;
}
bool zalloc_cpumask_var_node(cpumask_var_t *mask, gfp_t flags, int node)
{
return alloc_cpumask_var_node(mask, flags | __GFP_ZERO, node);
}
bool alloc_cpumask_var(cpumask_var_t *mask, gfp_t flags)
{
return alloc_cpumask_var_node(mask, flags, NUMA_NO_NODE);
}
bool zalloc_cpumask_var(cpumask_var_t *mask, gfp_t flags)
{
return alloc_cpumask_var(mask, flags | __GFP_ZERO);
}
void __init alloc_bootmem_cpumask_var(cpumask_var_t *mask)
{
*mask = memblock_virt_alloc(cpumask_size(), 0);
}
void free_cpumask_var(cpumask_var_t mask)
{
kfree(mask);
}
void __init free_bootmem_cpumask_var(cpumask_var_t mask)
{
memblock_free_early(__pa(mask), cpumask_size());
}
unsigned int cpumask_local_spread(unsigned int i, int node)
{
int cpu;
i %= num_online_cpus();
if (node == -1) {
for_each_cpu(cpu, cpu_online_mask)
if (i-- == 0)
return cpu;
} else {
for_each_cpu_and(cpu, cpumask_of_node(node), cpu_online_mask)
if (i-- == 0)
return cpu;
for_each_cpu(cpu, cpu_online_mask) {
if (cpumask_test_cpu(cpu, cpumask_of_node(node)))
continue;
if (i-- == 0)
return cpu;
}
}
BUG();
}
