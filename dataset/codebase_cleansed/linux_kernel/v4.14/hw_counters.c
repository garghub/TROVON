int bnxt_re_ib_get_hw_stats(struct ib_device *ibdev,
struct rdma_hw_stats *stats,
u8 port, int index)
{
struct bnxt_re_dev *rdev = to_bnxt_re_dev(ibdev, ibdev);
struct ctx_hw_stats *bnxt_re_stats = rdev->qplib_ctx.stats.dma;
if (!port || !stats)
return -EINVAL;
stats->value[BNXT_RE_ACTIVE_QP] = atomic_read(&rdev->qp_count);
stats->value[BNXT_RE_ACTIVE_SRQ] = atomic_read(&rdev->srq_count);
stats->value[BNXT_RE_ACTIVE_CQ] = atomic_read(&rdev->cq_count);
stats->value[BNXT_RE_ACTIVE_MR] = atomic_read(&rdev->mr_count);
stats->value[BNXT_RE_ACTIVE_MW] = atomic_read(&rdev->mw_count);
if (bnxt_re_stats) {
stats->value[BNXT_RE_RECOVERABLE_ERRORS] =
le64_to_cpu(bnxt_re_stats->tx_bcast_pkts);
stats->value[BNXT_RE_RX_PKTS] =
le64_to_cpu(bnxt_re_stats->rx_ucast_pkts);
stats->value[BNXT_RE_RX_BYTES] =
le64_to_cpu(bnxt_re_stats->rx_ucast_bytes);
stats->value[BNXT_RE_TX_PKTS] =
le64_to_cpu(bnxt_re_stats->tx_ucast_pkts);
stats->value[BNXT_RE_TX_BYTES] =
le64_to_cpu(bnxt_re_stats->tx_ucast_bytes);
}
return ARRAY_SIZE(bnxt_re_stat_name);
}
struct rdma_hw_stats *bnxt_re_ib_alloc_hw_stats(struct ib_device *ibdev,
u8 port_num)
{
BUILD_BUG_ON(ARRAY_SIZE(bnxt_re_stat_name) != BNXT_RE_NUM_COUNTERS);
if (!port_num)
return NULL;
return rdma_alloc_hw_stats_struct(bnxt_re_stat_name,
ARRAY_SIZE(bnxt_re_stat_name),
RDMA_HW_STATS_DEFAULT_LIFESPAN);
}
