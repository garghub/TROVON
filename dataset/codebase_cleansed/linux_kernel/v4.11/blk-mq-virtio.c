int blk_mq_virtio_map_queues(struct blk_mq_tag_set *set,
struct virtio_device *vdev, int first_vec)
{
const struct cpumask *mask;
unsigned int queue, cpu;
if (!vdev->config->get_vq_affinity)
goto fallback;
for (queue = 0; queue < set->nr_hw_queues; queue++) {
mask = vdev->config->get_vq_affinity(vdev, first_vec + queue);
if (!mask)
goto fallback;
for_each_cpu(cpu, mask)
set->mq_map[cpu] = queue;
}
return 0;
fallback:
return blk_mq_map_queues(set);
}
