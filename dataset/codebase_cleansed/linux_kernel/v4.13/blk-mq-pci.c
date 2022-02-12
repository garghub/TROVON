int blk_mq_pci_map_queues(struct blk_mq_tag_set *set, struct pci_dev *pdev)
{
const struct cpumask *mask;
unsigned int queue, cpu;
for (queue = 0; queue < set->nr_hw_queues; queue++) {
mask = pci_irq_get_affinity(pdev, queue);
if (!mask)
goto fallback;
for_each_cpu(cpu, mask)
set->mq_map[cpu] = queue;
}
return 0;
fallback:
WARN_ON_ONCE(set->nr_hw_queues > 1);
for_each_possible_cpu(cpu)
set->mq_map[cpu] = 0;
return 0;
}
