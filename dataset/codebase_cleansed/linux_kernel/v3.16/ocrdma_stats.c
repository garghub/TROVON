static int ocrdma_add_stat(char *start, char *pcur,
char *name, u64 count)
{
char buff[128] = {0};
int cpy_len = 0;
snprintf(buff, 128, "%s: %llu\n", name, count);
cpy_len = strlen(buff);
if (pcur + cpy_len > start + OCRDMA_MAX_DBGFS_MEM) {
pr_err("%s: No space in stats buff\n", __func__);
return 0;
}
memcpy(pcur, buff, cpy_len);
return cpy_len;
}
static bool ocrdma_alloc_stats_mem(struct ocrdma_dev *dev)
{
struct stats_mem *mem = &dev->stats_mem;
mem->size = max_t(u32, sizeof(struct ocrdma_rdma_stats_req),
sizeof(struct ocrdma_rdma_stats_resp));
mem->va = dma_alloc_coherent(&dev->nic_info.pdev->dev, mem->size,
&mem->pa, GFP_KERNEL);
if (!mem->va) {
pr_err("%s: stats mbox allocation failed\n", __func__);
return false;
}
memset(mem->va, 0, mem->size);
mem->debugfs_mem = kzalloc(OCRDMA_MAX_DBGFS_MEM, GFP_KERNEL);
if (!mem->debugfs_mem) {
pr_err("%s: stats debugfs mem allocation failed\n", __func__);
return false;
}
return true;
}
static void ocrdma_release_stats_mem(struct ocrdma_dev *dev)
{
struct stats_mem *mem = &dev->stats_mem;
if (mem->va)
dma_free_coherent(&dev->nic_info.pdev->dev, mem->size,
mem->va, mem->pa);
kfree(mem->debugfs_mem);
}
static char *ocrdma_resource_stats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_rsrc_stats *rsrc_stats = &rdma_stats->act_rsrc_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "active_dpp_pds",
(u64)rsrc_stats->dpp_pds);
pcur += ocrdma_add_stat(stats, pcur, "active_non_dpp_pds",
(u64)rsrc_stats->non_dpp_pds);
pcur += ocrdma_add_stat(stats, pcur, "active_rc_dpp_qps",
(u64)rsrc_stats->rc_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_uc_dpp_qps",
(u64)rsrc_stats->uc_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_ud_dpp_qps",
(u64)rsrc_stats->ud_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_rc_non_dpp_qps",
(u64)rsrc_stats->rc_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_uc_non_dpp_qps",
(u64)rsrc_stats->uc_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_ud_non_dpp_qps",
(u64)rsrc_stats->ud_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_srqs",
(u64)rsrc_stats->srqs);
pcur += ocrdma_add_stat(stats, pcur, "active_rbqs",
(u64)rsrc_stats->rbqs);
pcur += ocrdma_add_stat(stats, pcur, "active_64K_nsmr",
(u64)rsrc_stats->r64K_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_64K_to_2M_nsmr",
(u64)rsrc_stats->r64K_to_2M_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_2M_to_44M_nsmr",
(u64)rsrc_stats->r2M_to_44M_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_44M_to_1G_nsmr",
(u64)rsrc_stats->r44M_to_1G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_1G_to_4G_nsmr",
(u64)rsrc_stats->r1G_to_4G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_nsmr_count_4G_to_32G",
(u64)rsrc_stats->nsmr_count_4G_to_32G);
pcur += ocrdma_add_stat(stats, pcur, "active_32G_to_64G_nsmr",
(u64)rsrc_stats->r32G_to_64G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_64G_to_128G_nsmr",
(u64)rsrc_stats->r64G_to_128G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_128G_to_higher_nsmr",
(u64)rsrc_stats->r128G_to_higher_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_embedded_nsmr",
(u64)rsrc_stats->embedded_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "active_frmr",
(u64)rsrc_stats->frmr);
pcur += ocrdma_add_stat(stats, pcur, "active_prefetch_qps",
(u64)rsrc_stats->prefetch_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_ondemand_qps",
(u64)rsrc_stats->ondemand_qps);
pcur += ocrdma_add_stat(stats, pcur, "active_phy_mr",
(u64)rsrc_stats->phy_mr);
pcur += ocrdma_add_stat(stats, pcur, "active_mw",
(u64)rsrc_stats->mw);
rsrc_stats = &rdma_stats->th_rsrc_stats;
pcur += ocrdma_add_stat(stats, pcur, "threshold_dpp_pds",
(u64)rsrc_stats->dpp_pds);
pcur += ocrdma_add_stat(stats, pcur, "threshold_non_dpp_pds",
(u64)rsrc_stats->non_dpp_pds);
pcur += ocrdma_add_stat(stats, pcur, "threshold_rc_dpp_qps",
(u64)rsrc_stats->rc_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_uc_dpp_qps",
(u64)rsrc_stats->uc_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_ud_dpp_qps",
(u64)rsrc_stats->ud_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_rc_non_dpp_qps",
(u64)rsrc_stats->rc_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_uc_non_dpp_qps",
(u64)rsrc_stats->uc_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_ud_non_dpp_qps",
(u64)rsrc_stats->ud_non_dpp_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_srqs",
(u64)rsrc_stats->srqs);
pcur += ocrdma_add_stat(stats, pcur, "threshold_rbqs",
(u64)rsrc_stats->rbqs);
pcur += ocrdma_add_stat(stats, pcur, "threshold_64K_nsmr",
(u64)rsrc_stats->r64K_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_64K_to_2M_nsmr",
(u64)rsrc_stats->r64K_to_2M_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_2M_to_44M_nsmr",
(u64)rsrc_stats->r2M_to_44M_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_44M_to_1G_nsmr",
(u64)rsrc_stats->r44M_to_1G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_1G_to_4G_nsmr",
(u64)rsrc_stats->r1G_to_4G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_nsmr_count_4G_to_32G",
(u64)rsrc_stats->nsmr_count_4G_to_32G);
pcur += ocrdma_add_stat(stats, pcur, "threshold_32G_to_64G_nsmr",
(u64)rsrc_stats->r32G_to_64G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_64G_to_128G_nsmr",
(u64)rsrc_stats->r64G_to_128G_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_128G_to_higher_nsmr",
(u64)rsrc_stats->r128G_to_higher_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_embedded_nsmr",
(u64)rsrc_stats->embedded_nsmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_frmr",
(u64)rsrc_stats->frmr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_prefetch_qps",
(u64)rsrc_stats->prefetch_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_ondemand_qps",
(u64)rsrc_stats->ondemand_qps);
pcur += ocrdma_add_stat(stats, pcur, "threshold_phy_mr",
(u64)rsrc_stats->phy_mr);
pcur += ocrdma_add_stat(stats, pcur, "threshold_mw",
(u64)rsrc_stats->mw);
return stats;
}
static char *ocrdma_rx_stats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_rx_stats *rx_stats = &rdma_stats->rx_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat
(stats, pcur, "roce_frame_bytes",
convert_to_64bit(rx_stats->roce_frame_bytes_lo,
rx_stats->roce_frame_bytes_hi));
pcur += ocrdma_add_stat(stats, pcur, "roce_frame_icrc_drops",
(u64)rx_stats->roce_frame_icrc_drops);
pcur += ocrdma_add_stat(stats, pcur, "roce_frame_payload_len_drops",
(u64)rx_stats->roce_frame_payload_len_drops);
pcur += ocrdma_add_stat(stats, pcur, "ud_drops",
(u64)rx_stats->ud_drops);
pcur += ocrdma_add_stat(stats, pcur, "qp1_drops",
(u64)rx_stats->qp1_drops);
pcur += ocrdma_add_stat(stats, pcur, "psn_error_request_packets",
(u64)rx_stats->psn_error_request_packets);
pcur += ocrdma_add_stat(stats, pcur, "psn_error_resp_packets",
(u64)rx_stats->psn_error_resp_packets);
pcur += ocrdma_add_stat(stats, pcur, "rnr_nak_timeouts",
(u64)rx_stats->rnr_nak_timeouts);
pcur += ocrdma_add_stat(stats, pcur, "rnr_nak_receives",
(u64)rx_stats->rnr_nak_receives);
pcur += ocrdma_add_stat(stats, pcur, "roce_frame_rxmt_drops",
(u64)rx_stats->roce_frame_rxmt_drops);
pcur += ocrdma_add_stat(stats, pcur, "nak_count_psn_sequence_errors",
(u64)rx_stats->nak_count_psn_sequence_errors);
pcur += ocrdma_add_stat(stats, pcur, "rc_drop_count_lookup_errors",
(u64)rx_stats->rc_drop_count_lookup_errors);
pcur += ocrdma_add_stat(stats, pcur, "rq_rnr_naks",
(u64)rx_stats->rq_rnr_naks);
pcur += ocrdma_add_stat(stats, pcur, "srq_rnr_naks",
(u64)rx_stats->srq_rnr_naks);
pcur += ocrdma_add_stat(stats, pcur, "roce_frames",
convert_to_64bit(rx_stats->roce_frames_lo,
rx_stats->roce_frames_hi));
return stats;
}
static char *ocrdma_tx_stats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_tx_stats *tx_stats = &rdma_stats->tx_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "send_pkts",
convert_to_64bit(tx_stats->send_pkts_lo,
tx_stats->send_pkts_hi));
pcur += ocrdma_add_stat(stats, pcur, "write_pkts",
convert_to_64bit(tx_stats->write_pkts_lo,
tx_stats->write_pkts_hi));
pcur += ocrdma_add_stat(stats, pcur, "read_pkts",
convert_to_64bit(tx_stats->read_pkts_lo,
tx_stats->read_pkts_hi));
pcur += ocrdma_add_stat(stats, pcur, "read_rsp_pkts",
convert_to_64bit(tx_stats->read_rsp_pkts_lo,
tx_stats->read_rsp_pkts_hi));
pcur += ocrdma_add_stat(stats, pcur, "ack_pkts",
convert_to_64bit(tx_stats->ack_pkts_lo,
tx_stats->ack_pkts_hi));
pcur += ocrdma_add_stat(stats, pcur, "send_bytes",
convert_to_64bit(tx_stats->send_bytes_lo,
tx_stats->send_bytes_hi));
pcur += ocrdma_add_stat(stats, pcur, "write_bytes",
convert_to_64bit(tx_stats->write_bytes_lo,
tx_stats->write_bytes_hi));
pcur += ocrdma_add_stat(stats, pcur, "read_req_bytes",
convert_to_64bit(tx_stats->read_req_bytes_lo,
tx_stats->read_req_bytes_hi));
pcur += ocrdma_add_stat(stats, pcur, "read_rsp_bytes",
convert_to_64bit(tx_stats->read_rsp_bytes_lo,
tx_stats->read_rsp_bytes_hi));
pcur += ocrdma_add_stat(stats, pcur, "ack_timeouts",
(u64)tx_stats->ack_timeouts);
return stats;
}
static char *ocrdma_wqe_stats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_wqe_stats *wqe_stats = &rdma_stats->wqe_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "large_send_rc_wqes",
convert_to_64bit(wqe_stats->large_send_rc_wqes_lo,
wqe_stats->large_send_rc_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "large_write_rc_wqes",
convert_to_64bit(wqe_stats->large_write_rc_wqes_lo,
wqe_stats->large_write_rc_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "read_wqes",
convert_to_64bit(wqe_stats->read_wqes_lo,
wqe_stats->read_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "frmr_wqes",
convert_to_64bit(wqe_stats->frmr_wqes_lo,
wqe_stats->frmr_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "mw_bind_wqes",
convert_to_64bit(wqe_stats->mw_bind_wqes_lo,
wqe_stats->mw_bind_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "invalidate_wqes",
convert_to_64bit(wqe_stats->invalidate_wqes_lo,
wqe_stats->invalidate_wqes_hi));
pcur += ocrdma_add_stat(stats, pcur, "dpp_wqe_drops",
(u64)wqe_stats->dpp_wqe_drops);
return stats;
}
static char *ocrdma_db_errstats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_db_err_stats *db_err_stats = &rdma_stats->db_err_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "sq_doorbell_errors",
(u64)db_err_stats->sq_doorbell_errors);
pcur += ocrdma_add_stat(stats, pcur, "cq_doorbell_errors",
(u64)db_err_stats->cq_doorbell_errors);
pcur += ocrdma_add_stat(stats, pcur, "rq_srq_doorbell_errors",
(u64)db_err_stats->rq_srq_doorbell_errors);
pcur += ocrdma_add_stat(stats, pcur, "cq_overflow_errors",
(u64)db_err_stats->cq_overflow_errors);
return stats;
}
static char *ocrdma_rxqp_errstats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_rx_qp_err_stats *rx_qp_err_stats =
&rdma_stats->rx_qp_err_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "nak_invalid_requst_errors",
(u64)rx_qp_err_stats->nak_invalid_requst_errors);
pcur += ocrdma_add_stat(stats, pcur, "nak_remote_operation_errors",
(u64)rx_qp_err_stats->nak_remote_operation_errors);
pcur += ocrdma_add_stat(stats, pcur, "nak_count_remote_access_errors",
(u64)rx_qp_err_stats->nak_count_remote_access_errors);
pcur += ocrdma_add_stat(stats, pcur, "local_length_errors",
(u64)rx_qp_err_stats->local_length_errors);
pcur += ocrdma_add_stat(stats, pcur, "local_protection_errors",
(u64)rx_qp_err_stats->local_protection_errors);
pcur += ocrdma_add_stat(stats, pcur, "local_qp_operation_errors",
(u64)rx_qp_err_stats->local_qp_operation_errors);
return stats;
}
static char *ocrdma_txqp_errstats(struct ocrdma_dev *dev)
{
char *stats = dev->stats_mem.debugfs_mem, *pcur;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_tx_qp_err_stats *tx_qp_err_stats =
&rdma_stats->tx_qp_err_stats;
memset(stats, 0, (OCRDMA_MAX_DBGFS_MEM));
pcur = stats;
pcur += ocrdma_add_stat(stats, pcur, "local_length_errors",
(u64)tx_qp_err_stats->local_length_errors);
pcur += ocrdma_add_stat(stats, pcur, "local_protection_errors",
(u64)tx_qp_err_stats->local_protection_errors);
pcur += ocrdma_add_stat(stats, pcur, "local_qp_operation_errors",
(u64)tx_qp_err_stats->local_qp_operation_errors);
pcur += ocrdma_add_stat(stats, pcur, "retry_count_exceeded_errors",
(u64)tx_qp_err_stats->retry_count_exceeded_errors);
pcur += ocrdma_add_stat(stats, pcur, "rnr_retry_count_exceeded_errors",
(u64)tx_qp_err_stats->rnr_retry_count_exceeded_errors);
return stats;
}
static char *ocrdma_tx_dbg_stats(struct ocrdma_dev *dev)
{
int i;
char *pstats = dev->stats_mem.debugfs_mem;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_tx_dbg_stats *tx_dbg_stats =
&rdma_stats->tx_dbg_stats;
memset(pstats, 0, (OCRDMA_MAX_DBGFS_MEM));
for (i = 0; i < 100; i++)
pstats += snprintf(pstats, 80, "DW[%d] = 0x%x\n", i,
tx_dbg_stats->data[i]);
return dev->stats_mem.debugfs_mem;
}
static char *ocrdma_rx_dbg_stats(struct ocrdma_dev *dev)
{
int i;
char *pstats = dev->stats_mem.debugfs_mem;
struct ocrdma_rdma_stats_resp *rdma_stats =
(struct ocrdma_rdma_stats_resp *)dev->stats_mem.va;
struct ocrdma_rx_dbg_stats *rx_dbg_stats =
&rdma_stats->rx_dbg_stats;
memset(pstats, 0, (OCRDMA_MAX_DBGFS_MEM));
for (i = 0; i < 200; i++)
pstats += snprintf(pstats, 80, "DW[%d] = 0x%x\n", i,
rx_dbg_stats->data[i]);
return dev->stats_mem.debugfs_mem;
}
static void ocrdma_update_stats(struct ocrdma_dev *dev)
{
ulong now = jiffies, secs;
int status = 0;
secs = jiffies_to_msecs(now - dev->last_stats_time) / 1000U;
if (secs) {
status = ocrdma_mbx_rdma_stats(dev, false);
if (status)
pr_err("%s: stats mbox failed with status = %d\n",
__func__, status);
dev->last_stats_time = jiffies;
}
}
static ssize_t ocrdma_dbgfs_ops_read(struct file *filp, char __user *buffer,
size_t usr_buf_len, loff_t *ppos)
{
struct ocrdma_stats *pstats = filp->private_data;
struct ocrdma_dev *dev = pstats->dev;
ssize_t status = 0;
char *data = NULL;
if (*ppos != 0)
return 0;
mutex_lock(&dev->stats_lock);
ocrdma_update_stats(dev);
switch (pstats->type) {
case OCRDMA_RSRC_STATS:
data = ocrdma_resource_stats(dev);
break;
case OCRDMA_RXSTATS:
data = ocrdma_rx_stats(dev);
break;
case OCRDMA_WQESTATS:
data = ocrdma_wqe_stats(dev);
break;
case OCRDMA_TXSTATS:
data = ocrdma_tx_stats(dev);
break;
case OCRDMA_DB_ERRSTATS:
data = ocrdma_db_errstats(dev);
break;
case OCRDMA_RXQP_ERRSTATS:
data = ocrdma_rxqp_errstats(dev);
break;
case OCRDMA_TXQP_ERRSTATS:
data = ocrdma_txqp_errstats(dev);
break;
case OCRDMA_TX_DBG_STATS:
data = ocrdma_tx_dbg_stats(dev);
break;
case OCRDMA_RX_DBG_STATS:
data = ocrdma_rx_dbg_stats(dev);
break;
default:
status = -EFAULT;
goto exit;
}
if (usr_buf_len < strlen(data)) {
status = -ENOSPC;
goto exit;
}
status = simple_read_from_buffer(buffer, usr_buf_len, ppos, data,
strlen(data));
exit:
mutex_unlock(&dev->stats_lock);
return status;
}
void ocrdma_add_port_stats(struct ocrdma_dev *dev)
{
if (!ocrdma_dbgfs_dir)
return;
dev->dir = debugfs_create_dir(dev->ibdev.name, ocrdma_dbgfs_dir);
if (!dev->dir)
goto err;
dev->rsrc_stats.type = OCRDMA_RSRC_STATS;
dev->rsrc_stats.dev = dev;
if (!debugfs_create_file("resource_stats", S_IRUSR, dev->dir,
&dev->rsrc_stats, &ocrdma_dbg_ops))
goto err;
dev->rx_stats.type = OCRDMA_RXSTATS;
dev->rx_stats.dev = dev;
if (!debugfs_create_file("rx_stats", S_IRUSR, dev->dir,
&dev->rx_stats, &ocrdma_dbg_ops))
goto err;
dev->wqe_stats.type = OCRDMA_WQESTATS;
dev->wqe_stats.dev = dev;
if (!debugfs_create_file("wqe_stats", S_IRUSR, dev->dir,
&dev->wqe_stats, &ocrdma_dbg_ops))
goto err;
dev->tx_stats.type = OCRDMA_TXSTATS;
dev->tx_stats.dev = dev;
if (!debugfs_create_file("tx_stats", S_IRUSR, dev->dir,
&dev->tx_stats, &ocrdma_dbg_ops))
goto err;
dev->db_err_stats.type = OCRDMA_DB_ERRSTATS;
dev->db_err_stats.dev = dev;
if (!debugfs_create_file("db_err_stats", S_IRUSR, dev->dir,
&dev->db_err_stats, &ocrdma_dbg_ops))
goto err;
dev->tx_qp_err_stats.type = OCRDMA_TXQP_ERRSTATS;
dev->tx_qp_err_stats.dev = dev;
if (!debugfs_create_file("tx_qp_err_stats", S_IRUSR, dev->dir,
&dev->tx_qp_err_stats, &ocrdma_dbg_ops))
goto err;
dev->rx_qp_err_stats.type = OCRDMA_RXQP_ERRSTATS;
dev->rx_qp_err_stats.dev = dev;
if (!debugfs_create_file("rx_qp_err_stats", S_IRUSR, dev->dir,
&dev->rx_qp_err_stats, &ocrdma_dbg_ops))
goto err;
dev->tx_dbg_stats.type = OCRDMA_TX_DBG_STATS;
dev->tx_dbg_stats.dev = dev;
if (!debugfs_create_file("tx_dbg_stats", S_IRUSR, dev->dir,
&dev->tx_dbg_stats, &ocrdma_dbg_ops))
goto err;
dev->rx_dbg_stats.type = OCRDMA_RX_DBG_STATS;
dev->rx_dbg_stats.dev = dev;
if (!debugfs_create_file("rx_dbg_stats", S_IRUSR, dev->dir,
&dev->rx_dbg_stats, &ocrdma_dbg_ops))
goto err;
if (!ocrdma_alloc_stats_mem(dev))
goto err;
mutex_init(&dev->stats_lock);
return;
err:
ocrdma_release_stats_mem(dev);
debugfs_remove_recursive(dev->dir);
dev->dir = NULL;
}
void ocrdma_rem_port_stats(struct ocrdma_dev *dev)
{
if (!dev->dir)
return;
mutex_destroy(&dev->stats_lock);
ocrdma_release_stats_mem(dev);
debugfs_remove(dev->dir);
}
void ocrdma_init_debugfs(void)
{
ocrdma_dbgfs_dir = debugfs_create_dir("ocrdma", NULL);
}
void ocrdma_rem_debugfs(void)
{
debugfs_remove_recursive(ocrdma_dbgfs_dir);
}
