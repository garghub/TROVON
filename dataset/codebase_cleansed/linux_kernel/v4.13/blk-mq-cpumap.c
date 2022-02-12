static int cpu_to_queue_index(unsigned int nr_queues, const int cpu)
{
if (!cpu_present(cpu))
return 0;
return cpu % nr_queues;
}
static int get_first_sibling(unsigned int cpu)
{
unsigned int ret;
ret = cpumask_first(topology_sibling_cpumask(cpu));
if (ret < nr_cpu_ids)
return ret;
return cpu;
}
int blk_mq_map_queues(struct blk_mq_tag_set *set)
{
unsigned int *map = set->mq_map;
unsigned int nr_queues = set->nr_hw_queues;
unsigned int cpu, first_sibling;
for_each_possible_cpu(cpu) {
if (cpu < nr_queues) {
map[cpu] = cpu_to_queue_index(nr_queues, cpu);
} else {
first_sibling = get_first_sibling(cpu);
if (first_sibling == cpu)
map[cpu] = cpu_to_queue_index(nr_queues, cpu);
else
map[cpu] = map[first_sibling];
}
}
return 0;
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
