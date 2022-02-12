int rxe_ib_get_hw_stats(struct ib_device *ibdev,
struct rdma_hw_stats *stats,
u8 port, int index)
{
struct rxe_dev *dev = to_rdev(ibdev);
unsigned int cnt;
if (!port || !stats)
return -EINVAL;
for (cnt = 0; cnt < ARRAY_SIZE(rxe_counter_name); cnt++)
stats->value[cnt] = dev->stats_counters[cnt];
return ARRAY_SIZE(rxe_counter_name);
}
struct rdma_hw_stats *rxe_ib_alloc_hw_stats(struct ib_device *ibdev,
u8 port_num)
{
BUILD_BUG_ON(ARRAY_SIZE(rxe_counter_name) != RXE_NUM_OF_COUNTERS);
if (!port_num)
return NULL;
return rdma_alloc_hw_stats_struct(rxe_counter_name,
ARRAY_SIZE(rxe_counter_name),
RDMA_HW_STATS_DEFAULT_LIFESPAN);
}
