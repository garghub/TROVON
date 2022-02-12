int __first_cpu(const cpumask_t *srcp)
{
return min_t(int, NR_CPUS, find_first_bit(srcp->bits, NR_CPUS));
}
int __next_cpu(int n, const cpumask_t *srcp)
{
return min_t(int, NR_CPUS, find_next_bit(srcp->bits, NR_CPUS, n+1));
}
int __next_cpu_nr(int n, const cpumask_t *srcp)
{
return min_t(int, nr_cpu_ids,
find_next_bit(srcp->bits, nr_cpu_ids, n+1));
}
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
bool alloc_cpumask_var_node(cpumask_var_t *mask, gfp_t flags, int node)
{
*mask = kmalloc_node(cpumask_size(), flags, node);
#ifdef CONFIG_DEBUG_PER_CPU_MAPS
if (!*mask) {
printk(KERN_ERR "=> alloc_cpumask_var: failed!\n");
dump_stack();
}
#endif
if (*mask) {
unsigned char *ptr = (unsigned char *)cpumask_bits(*mask);
unsigned int tail;
tail = BITS_TO_LONGS(NR_CPUS - nr_cpumask_bits) * sizeof(long);
memset(ptr + cpumask_size() - tail, 0, tail);
}
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
int cpumask_set_cpu_local_first(int i, int numa_node, cpumask_t *dstp)
{
cpumask_var_t mask;
int cpu;
int ret = 0;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
i %= num_online_cpus();
if (numa_node == -1 || !cpumask_of_node(numa_node)) {
cpumask_copy(mask, cpu_online_mask);
} else {
int n;
cpumask_and(mask,
cpumask_of_node(numa_node), cpu_online_mask);
n = cpumask_weight(mask);
if (i >= n) {
i -= n;
cpumask_andnot(mask, cpu_online_mask, mask);
}
}
for_each_cpu(cpu, mask) {
if (--i < 0)
goto out;
}
ret = -EAGAIN;
out:
free_cpumask_var(mask);
if (!ret)
cpumask_set_cpu(cpu, dstp);
return ret;
}
