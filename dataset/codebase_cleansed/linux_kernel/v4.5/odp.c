void mlx5_ib_invalidate_range(struct ib_umem *umem, unsigned long start,
unsigned long end)
{
struct mlx5_ib_mr *mr;
const u64 umr_block_mask = (MLX5_UMR_MTT_ALIGNMENT / sizeof(u64)) - 1;
u64 idx = 0, blk_start_idx = 0;
int in_block = 0;
u64 addr;
if (!umem || !umem->odp_data) {
pr_err("invalidation called on NULL umem or non-ODP umem\n");
return;
}
mr = umem->odp_data->private;
if (!mr || !mr->ibmr.pd)
return;
start = max_t(u64, ib_umem_start(umem), start);
end = min_t(u64, ib_umem_end(umem), end);
for (addr = start; addr < end; addr += (u64)umem->page_size) {
idx = (addr - ib_umem_start(umem)) / PAGE_SIZE;
if (umem->odp_data->dma_list[idx] &
(ODP_READ_ALLOWED_BIT | ODP_WRITE_ALLOWED_BIT)) {
if (!in_block) {
blk_start_idx = idx;
in_block = 1;
}
} else {
u64 umr_offset = idx & umr_block_mask;
if (in_block && umr_offset == 0) {
mlx5_ib_update_mtt(mr, blk_start_idx,
idx - blk_start_idx, 1);
in_block = 0;
}
}
}
if (in_block)
mlx5_ib_update_mtt(mr, blk_start_idx, idx - blk_start_idx + 1,
1);
ib_umem_odp_unmap_dma_pages(umem, start, end);
}
void mlx5_ib_internal_fill_odp_caps(struct mlx5_ib_dev *dev)
{
struct ib_odp_caps *caps = &dev->odp_caps;
memset(caps, 0, sizeof(*caps));
if (!MLX5_CAP_GEN(dev->mdev, pg))
return;
caps->general_caps = IB_ODP_SUPPORT;
if (MLX5_CAP_ODP(dev->mdev, ud_odp_caps.send))
caps->per_transport_caps.ud_odp_caps |= IB_ODP_SUPPORT_SEND;
if (MLX5_CAP_ODP(dev->mdev, rc_odp_caps.send))
caps->per_transport_caps.rc_odp_caps |= IB_ODP_SUPPORT_SEND;
if (MLX5_CAP_ODP(dev->mdev, rc_odp_caps.receive))
caps->per_transport_caps.rc_odp_caps |= IB_ODP_SUPPORT_RECV;
if (MLX5_CAP_ODP(dev->mdev, rc_odp_caps.write))
caps->per_transport_caps.rc_odp_caps |= IB_ODP_SUPPORT_WRITE;
if (MLX5_CAP_ODP(dev->mdev, rc_odp_caps.read))
caps->per_transport_caps.rc_odp_caps |= IB_ODP_SUPPORT_READ;
return;
}
static struct mlx5_ib_mr *mlx5_ib_odp_find_mr_lkey(struct mlx5_ib_dev *dev,
u32 key)
{
u32 base_key = mlx5_base_mkey(key);
struct mlx5_core_mr *mmr = __mlx5_mr_lookup(dev->mdev, base_key);
struct mlx5_ib_mr *mr = container_of(mmr, struct mlx5_ib_mr, mmr);
if (!mmr || mmr->key != key || !mr->live)
return NULL;
return container_of(mmr, struct mlx5_ib_mr, mmr);
}
static void mlx5_ib_page_fault_resume(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault,
int error)
{
struct mlx5_ib_dev *dev = to_mdev(qp->ibqp.pd->device);
u32 qpn = qp->trans_qp.base.mqp.qpn;
int ret = mlx5_core_page_fault_resume(dev->mdev,
qpn,
pfault->mpfault.flags,
error);
if (ret)
pr_err("Failed to resolve the page fault on QP 0x%x\n", qpn);
}
static int pagefault_single_data_segment(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault,
u32 key, u64 io_virt, size_t bcnt,
u32 *bytes_mapped)
{
struct mlx5_ib_dev *mib_dev = to_mdev(qp->ibqp.pd->device);
int srcu_key;
unsigned int current_seq;
u64 start_idx;
int npages = 0, ret = 0;
struct mlx5_ib_mr *mr;
u64 access_mask = ODP_READ_ALLOWED_BIT;
srcu_key = srcu_read_lock(&mib_dev->mr_srcu);
mr = mlx5_ib_odp_find_mr_lkey(mib_dev, key);
if (!mr || !mr->ibmr.pd) {
pr_err("Failed to find relevant mr for lkey=0x%06x, probably the MR was destroyed\n",
key);
ret = -EFAULT;
goto srcu_unlock;
}
if (!mr->umem->odp_data) {
pr_debug("skipping non ODP MR (lkey=0x%06x) in page fault handler.\n",
key);
if (bytes_mapped)
*bytes_mapped +=
(bcnt - pfault->mpfault.bytes_committed);
goto srcu_unlock;
}
if (mr->ibmr.pd != qp->ibqp.pd) {
pr_err("Page-fault with different PDs for QP and MR.\n");
ret = -EFAULT;
goto srcu_unlock;
}
current_seq = ACCESS_ONCE(mr->umem->odp_data->notifiers_seq);
smp_rmb();
io_virt += pfault->mpfault.bytes_committed;
bcnt -= pfault->mpfault.bytes_committed;
start_idx = (io_virt - (mr->mmr.iova & PAGE_MASK)) >> PAGE_SHIFT;
if (mr->umem->writable)
access_mask |= ODP_WRITE_ALLOWED_BIT;
npages = ib_umem_odp_map_dma_pages(mr->umem, io_virt, bcnt,
access_mask, current_seq);
if (npages < 0) {
ret = npages;
goto srcu_unlock;
}
if (npages > 0) {
mutex_lock(&mr->umem->odp_data->umem_mutex);
if (!ib_umem_mmu_notifier_retry(mr->umem, current_seq)) {
ret = mlx5_ib_update_mtt(mr, start_idx, npages, 0);
} else {
ret = -EAGAIN;
}
mutex_unlock(&mr->umem->odp_data->umem_mutex);
if (ret < 0) {
if (ret != -EAGAIN)
pr_err("Failed to update mkey page tables\n");
goto srcu_unlock;
}
if (bytes_mapped) {
u32 new_mappings = npages * PAGE_SIZE -
(io_virt - round_down(io_virt, PAGE_SIZE));
*bytes_mapped += min_t(u32, new_mappings, bcnt);
}
}
srcu_unlock:
if (ret == -EAGAIN) {
if (!mr->umem->odp_data->dying) {
struct ib_umem_odp *odp_data = mr->umem->odp_data;
unsigned long timeout =
msecs_to_jiffies(MMU_NOTIFIER_TIMEOUT);
if (!wait_for_completion_timeout(
&odp_data->notifier_completion,
timeout)) {
pr_warn("timeout waiting for mmu notifier completion\n");
}
} else {
ret = -EFAULT;
}
}
srcu_read_unlock(&mib_dev->mr_srcu, srcu_key);
pfault->mpfault.bytes_committed = 0;
return ret ? ret : npages;
}
static int pagefault_data_segments(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault, void *wqe,
void *wqe_end, u32 *bytes_mapped,
u32 *total_wqe_bytes, int receive_queue)
{
int ret = 0, npages = 0;
u64 io_virt;
u32 key;
u32 byte_count;
size_t bcnt;
int inline_segment;
if (receive_queue && qp->ibqp.srq)
wqe += sizeof(struct mlx5_wqe_srq_next_seg);
if (bytes_mapped)
*bytes_mapped = 0;
if (total_wqe_bytes)
*total_wqe_bytes = 0;
while (wqe < wqe_end) {
struct mlx5_wqe_data_seg *dseg = wqe;
io_virt = be64_to_cpu(dseg->addr);
key = be32_to_cpu(dseg->lkey);
byte_count = be32_to_cpu(dseg->byte_count);
inline_segment = !!(byte_count & MLX5_INLINE_SEG);
bcnt = byte_count & ~MLX5_INLINE_SEG;
if (inline_segment) {
bcnt = bcnt & MLX5_WQE_INLINE_SEG_BYTE_COUNT_MASK;
wqe += ALIGN(sizeof(struct mlx5_wqe_inline_seg) + bcnt,
16);
} else {
wqe += sizeof(*dseg);
}
if (receive_queue && bcnt == 0 && key == MLX5_INVALID_LKEY &&
io_virt == 0)
break;
if (!inline_segment && total_wqe_bytes) {
*total_wqe_bytes += bcnt - min_t(size_t, bcnt,
pfault->mpfault.bytes_committed);
}
if (bcnt == 0)
bcnt = 1U << 31;
if (inline_segment || bcnt <= pfault->mpfault.bytes_committed) {
pfault->mpfault.bytes_committed -=
min_t(size_t, bcnt,
pfault->mpfault.bytes_committed);
continue;
}
ret = pagefault_single_data_segment(qp, pfault, key, io_virt,
bcnt, bytes_mapped);
if (ret < 0)
break;
npages += ret;
}
return ret < 0 ? ret : npages;
}
static int mlx5_ib_mr_initiator_pfault_handler(
struct mlx5_ib_qp *qp, struct mlx5_ib_pfault *pfault,
void **wqe, void **wqe_end, int wqe_length)
{
struct mlx5_ib_dev *dev = to_mdev(qp->ibqp.pd->device);
struct mlx5_wqe_ctrl_seg *ctrl = *wqe;
u16 wqe_index = pfault->mpfault.wqe.wqe_index;
unsigned ds, opcode;
#if defined(DEBUG)
u32 ctrl_wqe_index, ctrl_qpn;
#endif
u32 qpn = qp->trans_qp.base.mqp.qpn;
ds = be32_to_cpu(ctrl->qpn_ds) & MLX5_WQE_CTRL_DS_MASK;
if (ds * MLX5_WQE_DS_UNITS > wqe_length) {
mlx5_ib_err(dev, "Unable to read the complete WQE. ds = 0x%x, ret = 0x%x\n",
ds, wqe_length);
return -EFAULT;
}
if (ds == 0) {
mlx5_ib_err(dev, "Got WQE with zero DS. wqe_index=%x, qpn=%x\n",
wqe_index, qpn);
return -EFAULT;
}
#if defined(DEBUG)
ctrl_wqe_index = (be32_to_cpu(ctrl->opmod_idx_opcode) &
MLX5_WQE_CTRL_WQE_INDEX_MASK) >>
MLX5_WQE_CTRL_WQE_INDEX_SHIFT;
if (wqe_index != ctrl_wqe_index) {
mlx5_ib_err(dev, "Got WQE with invalid wqe_index. wqe_index=0x%x, qpn=0x%x ctrl->wqe_index=0x%x\n",
wqe_index, qpn,
ctrl_wqe_index);
return -EFAULT;
}
ctrl_qpn = (be32_to_cpu(ctrl->qpn_ds) & MLX5_WQE_CTRL_QPN_MASK) >>
MLX5_WQE_CTRL_QPN_SHIFT;
if (qpn != ctrl_qpn) {
mlx5_ib_err(dev, "Got WQE with incorrect QP number. wqe_index=0x%x, qpn=0x%x ctrl->qpn=0x%x\n",
wqe_index, qpn,
ctrl_qpn);
return -EFAULT;
}
#endif
*wqe_end = *wqe + ds * MLX5_WQE_DS_UNITS;
*wqe += sizeof(*ctrl);
opcode = be32_to_cpu(ctrl->opmod_idx_opcode) &
MLX5_WQE_CTRL_OPCODE_MASK;
switch (qp->ibqp.qp_type) {
case IB_QPT_RC:
switch (opcode) {
case MLX5_OPCODE_SEND:
case MLX5_OPCODE_SEND_IMM:
case MLX5_OPCODE_SEND_INVAL:
if (!(dev->odp_caps.per_transport_caps.rc_odp_caps &
IB_ODP_SUPPORT_SEND))
goto invalid_transport_or_opcode;
break;
case MLX5_OPCODE_RDMA_WRITE:
case MLX5_OPCODE_RDMA_WRITE_IMM:
if (!(dev->odp_caps.per_transport_caps.rc_odp_caps &
IB_ODP_SUPPORT_WRITE))
goto invalid_transport_or_opcode;
*wqe += sizeof(struct mlx5_wqe_raddr_seg);
break;
case MLX5_OPCODE_RDMA_READ:
if (!(dev->odp_caps.per_transport_caps.rc_odp_caps &
IB_ODP_SUPPORT_READ))
goto invalid_transport_or_opcode;
*wqe += sizeof(struct mlx5_wqe_raddr_seg);
break;
default:
goto invalid_transport_or_opcode;
}
break;
case IB_QPT_UD:
switch (opcode) {
case MLX5_OPCODE_SEND:
case MLX5_OPCODE_SEND_IMM:
if (!(dev->odp_caps.per_transport_caps.ud_odp_caps &
IB_ODP_SUPPORT_SEND))
goto invalid_transport_or_opcode;
*wqe += sizeof(struct mlx5_wqe_datagram_seg);
break;
default:
goto invalid_transport_or_opcode;
}
break;
default:
invalid_transport_or_opcode:
mlx5_ib_err(dev, "ODP fault on QP of an unsupported opcode or transport. transport: 0x%x opcode: 0x%x.\n",
qp->ibqp.qp_type, opcode);
return -EFAULT;
}
return 0;
}
static int mlx5_ib_mr_responder_pfault_handler(
struct mlx5_ib_qp *qp, struct mlx5_ib_pfault *pfault,
void **wqe, void **wqe_end, int wqe_length)
{
struct mlx5_ib_dev *dev = to_mdev(qp->ibqp.pd->device);
struct mlx5_ib_wq *wq = &qp->rq;
int wqe_size = 1 << wq->wqe_shift;
if (qp->ibqp.srq) {
mlx5_ib_err(dev, "ODP fault on SRQ is not supported\n");
return -EFAULT;
}
if (qp->wq_sig) {
mlx5_ib_err(dev, "ODP fault with WQE signatures is not supported\n");
return -EFAULT;
}
if (wqe_size > wqe_length) {
mlx5_ib_err(dev, "Couldn't read all of the receive WQE's content\n");
return -EFAULT;
}
switch (qp->ibqp.qp_type) {
case IB_QPT_RC:
if (!(dev->odp_caps.per_transport_caps.rc_odp_caps &
IB_ODP_SUPPORT_RECV))
goto invalid_transport_or_opcode;
break;
default:
invalid_transport_or_opcode:
mlx5_ib_err(dev, "ODP fault on QP of an unsupported transport. transport: 0x%x\n",
qp->ibqp.qp_type);
return -EFAULT;
}
*wqe_end = *wqe + wqe_size;
return 0;
}
static void mlx5_ib_mr_wqe_pfault_handler(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault)
{
struct mlx5_ib_dev *dev = to_mdev(qp->ibqp.pd->device);
int ret;
void *wqe, *wqe_end;
u32 bytes_mapped, total_wqe_bytes;
char *buffer = NULL;
int resume_with_error = 0;
u16 wqe_index = pfault->mpfault.wqe.wqe_index;
int requestor = pfault->mpfault.flags & MLX5_PFAULT_REQUESTOR;
u32 qpn = qp->trans_qp.base.mqp.qpn;
buffer = (char *)__get_free_page(GFP_KERNEL);
if (!buffer) {
mlx5_ib_err(dev, "Error allocating memory for IO page fault handling.\n");
resume_with_error = 1;
goto resolve_page_fault;
}
ret = mlx5_ib_read_user_wqe(qp, requestor, wqe_index, buffer,
PAGE_SIZE, &qp->trans_qp.base);
if (ret < 0) {
mlx5_ib_err(dev, "Failed reading a WQE following page fault, error=%x, wqe_index=%x, qpn=%x\n",
-ret, wqe_index, qpn);
resume_with_error = 1;
goto resolve_page_fault;
}
wqe = buffer;
if (requestor)
ret = mlx5_ib_mr_initiator_pfault_handler(qp, pfault, &wqe,
&wqe_end, ret);
else
ret = mlx5_ib_mr_responder_pfault_handler(qp, pfault, &wqe,
&wqe_end, ret);
if (ret < 0) {
resume_with_error = 1;
goto resolve_page_fault;
}
if (wqe >= wqe_end) {
mlx5_ib_err(dev, "ODP fault on invalid WQE.\n");
resume_with_error = 1;
goto resolve_page_fault;
}
ret = pagefault_data_segments(qp, pfault, wqe, wqe_end, &bytes_mapped,
&total_wqe_bytes, !requestor);
if (ret == -EAGAIN) {
goto resolve_page_fault;
} else if (ret < 0 || total_wqe_bytes > bytes_mapped) {
mlx5_ib_err(dev, "Error getting user pages for page fault. Error: 0x%x\n",
-ret);
resume_with_error = 1;
goto resolve_page_fault;
}
resolve_page_fault:
mlx5_ib_page_fault_resume(qp, pfault, resume_with_error);
mlx5_ib_dbg(dev, "PAGE FAULT completed. QP 0x%x resume_with_error=%d, flags: 0x%x\n",
qpn, resume_with_error,
pfault->mpfault.flags);
free_page((unsigned long)buffer);
}
static int pages_in_range(u64 address, u32 length)
{
return (ALIGN(address + length, PAGE_SIZE) -
(address & PAGE_MASK)) >> PAGE_SHIFT;
}
static void mlx5_ib_mr_rdma_pfault_handler(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault)
{
struct mlx5_pagefault *mpfault = &pfault->mpfault;
u64 address;
u32 length;
u32 prefetch_len = mpfault->bytes_committed;
int prefetch_activated = 0;
u32 rkey = mpfault->rdma.r_key;
int ret;
struct mlx5_ib_pfault dummy_pfault = {};
dummy_pfault.mpfault.bytes_committed = 0;
mpfault->rdma.rdma_va += mpfault->bytes_committed;
mpfault->rdma.rdma_op_len -= min(mpfault->bytes_committed,
mpfault->rdma.rdma_op_len);
mpfault->bytes_committed = 0;
address = mpfault->rdma.rdma_va;
length = mpfault->rdma.rdma_op_len;
if (length == 0) {
prefetch_activated = 1;
length = mpfault->rdma.packet_size;
prefetch_len = min(MAX_PREFETCH_LEN, prefetch_len);
}
ret = pagefault_single_data_segment(qp, pfault, rkey, address, length,
NULL);
if (ret == -EAGAIN) {
prefetch_activated = 0;
} else if (ret < 0 || pages_in_range(address, length) > ret) {
mlx5_ib_page_fault_resume(qp, pfault, 1);
return;
}
mlx5_ib_page_fault_resume(qp, pfault, 0);
if (prefetch_activated) {
ret = pagefault_single_data_segment(qp, &dummy_pfault, rkey,
address,
prefetch_len,
NULL);
if (ret < 0) {
pr_warn("Prefetch failed (ret = %d, prefetch_activated = %d) for QPN %d, address: 0x%.16llx, length = 0x%.16x\n",
ret, prefetch_activated,
qp->ibqp.qp_num, address, prefetch_len);
}
}
}
void mlx5_ib_mr_pfault_handler(struct mlx5_ib_qp *qp,
struct mlx5_ib_pfault *pfault)
{
u8 event_subtype = pfault->mpfault.event_subtype;
switch (event_subtype) {
case MLX5_PFAULT_SUBTYPE_WQE:
mlx5_ib_mr_wqe_pfault_handler(qp, pfault);
break;
case MLX5_PFAULT_SUBTYPE_RDMA:
mlx5_ib_mr_rdma_pfault_handler(qp, pfault);
break;
default:
pr_warn("Invalid page fault event subtype: 0x%x\n",
event_subtype);
mlx5_ib_page_fault_resume(qp, pfault, 1);
break;
}
}
static void mlx5_ib_qp_pfault_action(struct work_struct *work)
{
struct mlx5_ib_pfault *pfault = container_of(work,
struct mlx5_ib_pfault,
work);
enum mlx5_ib_pagefault_context context =
mlx5_ib_get_pagefault_context(&pfault->mpfault);
struct mlx5_ib_qp *qp = container_of(pfault, struct mlx5_ib_qp,
pagefaults[context]);
mlx5_ib_mr_pfault_handler(qp, pfault);
}
void mlx5_ib_qp_disable_pagefaults(struct mlx5_ib_qp *qp)
{
unsigned long flags;
spin_lock_irqsave(&qp->disable_page_faults_lock, flags);
qp->disable_page_faults = 1;
spin_unlock_irqrestore(&qp->disable_page_faults_lock, flags);
flush_workqueue(mlx5_ib_page_fault_wq);
}
void mlx5_ib_qp_enable_pagefaults(struct mlx5_ib_qp *qp)
{
unsigned long flags;
spin_lock_irqsave(&qp->disable_page_faults_lock, flags);
qp->disable_page_faults = 0;
spin_unlock_irqrestore(&qp->disable_page_faults_lock, flags);
}
static void mlx5_ib_pfault_handler(struct mlx5_core_qp *qp,
struct mlx5_pagefault *pfault)
{
struct mlx5_ib_qp *mibqp = to_mibqp(qp);
enum mlx5_ib_pagefault_context context =
mlx5_ib_get_pagefault_context(pfault);
struct mlx5_ib_pfault *qp_pfault = &mibqp->pagefaults[context];
qp_pfault->mpfault = *pfault;
spin_lock(&mibqp->disable_page_faults_lock);
if (!mibqp->disable_page_faults)
queue_work(mlx5_ib_page_fault_wq, &qp_pfault->work);
spin_unlock(&mibqp->disable_page_faults_lock);
}
void mlx5_ib_odp_create_qp(struct mlx5_ib_qp *qp)
{
int i;
qp->disable_page_faults = 1;
spin_lock_init(&qp->disable_page_faults_lock);
qp->trans_qp.base.mqp.pfault_handler = mlx5_ib_pfault_handler;
for (i = 0; i < MLX5_IB_PAGEFAULT_CONTEXTS; ++i)
INIT_WORK(&qp->pagefaults[i].work, mlx5_ib_qp_pfault_action);
}
int mlx5_ib_odp_init_one(struct mlx5_ib_dev *ibdev)
{
int ret;
ret = init_srcu_struct(&ibdev->mr_srcu);
if (ret)
return ret;
return 0;
}
void mlx5_ib_odp_remove_one(struct mlx5_ib_dev *ibdev)
{
cleanup_srcu_struct(&ibdev->mr_srcu);
}
int __init mlx5_ib_odp_init(void)
{
mlx5_ib_page_fault_wq =
create_singlethread_workqueue("mlx5_ib_page_faults");
if (!mlx5_ib_page_fault_wq)
return -ENOMEM;
return 0;
}
void mlx5_ib_odp_cleanup(void)
{
destroy_workqueue(mlx5_ib_page_fault_wq);
}
