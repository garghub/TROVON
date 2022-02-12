int blk_mq_rdma_map_queues(struct blk_mq_tag_set *set,
struct ib_device *dev, int first_vec)
{
const struct cpumask *mask;
unsigned int queue, cpu;
for (queue = 0; queue < set->nr_hw_queues; queue++) {
mask = ib_get_vector_affinity(dev, first_vec + queue);
if (!mask)
goto fallback;
for_each_cpu(cpu, mask)
set->mq_map[cpu] = queue;
}
return 0;
fallback:
return blk_mq_map_queues(set);
}
