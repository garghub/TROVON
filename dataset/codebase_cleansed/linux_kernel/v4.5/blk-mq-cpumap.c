static int cpu_to_queue_index(unsigned int nr_cpus, unsigned int nr_queues,
const int cpu)
{
return cpu * nr_queues / nr_cpus;
}
static int get_first_sibling(unsigned int cpu)
{
unsigned int ret;
ret = cpumask_first(topology_sibling_cpumask(cpu));
if (ret < nr_cpu_ids)
return ret;
return cpu;
}
int blk_mq_update_queue_map(unsigned int *map, unsigned int nr_queues,
const struct cpumask *online_mask)
{
unsigned int i, nr_cpus, nr_uniq_cpus, queue, first_sibling;
cpumask_var_t cpus;
if (!alloc_cpumask_var(&cpus, GFP_ATOMIC))
return 1;
cpumask_clear(cpus);
nr_cpus = nr_uniq_cpus = 0;
for_each_cpu(i, online_mask) {
nr_cpus++;
first_sibling = get_first_sibling(i);
if (!cpumask_test_cpu(first_sibling, cpus))
nr_uniq_cpus++;
cpumask_set_cpu(i, cpus);
}
queue = 0;
for_each_possible_cpu(i) {
if (!cpumask_test_cpu(i, online_mask)) {
map[i] = 0;
continue;
}
if (nr_queues >= nr_cpus || nr_cpus == nr_uniq_cpus) {
map[i] = cpu_to_queue_index(nr_cpus, nr_queues, queue);
queue++;
continue;
}
first_sibling = get_first_sibling(i);
if (first_sibling == i) {
map[i] = cpu_to_queue_index(nr_uniq_cpus, nr_queues,
queue);
queue++;
} else
map[i] = map[first_sibling];
}
free_cpumask_var(cpus);
return 0;
}
unsigned int *blk_mq_make_queue_map(struct blk_mq_tag_set *set)
{
unsigned int *map;
map = kzalloc_node(sizeof(*map) * nr_cpu_ids, GFP_KERNEL,
set->numa_node);
if (!map)
return NULL;
if (!blk_mq_update_queue_map(map, set->nr_hw_queues, cpu_online_mask))
return map;
kfree(map);
return NULL;
}
int blk_mq_hw_queue_to_node(unsigned int *mq_map, unsigned int index)
{
int i;
for_each_possible_cpu(i) {
if (index == mq_map[i])
return local_memory_node(cpu_to_node(i));
}
return NUMA_NO_NODE;
}
