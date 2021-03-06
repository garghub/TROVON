static struct mlx5_core_rsc_common *mlx5_get_rsc(struct mlx5_core_dev *dev,
u32 rsn)
{
struct mlx5_qp_table *table = &dev->priv.qp_table;
struct mlx5_core_rsc_common *common;
spin_lock(&table->lock);
common = radix_tree_lookup(&table->tree, rsn);
if (common)
atomic_inc(&common->refcount);
spin_unlock(&table->lock);
if (!common) {
mlx5_core_warn(dev, "Async event for bogus resource 0x%x\n",
rsn);
return NULL;
}
return common;
}
void mlx5_core_put_rsc(struct mlx5_core_rsc_common *common)
{
if (atomic_dec_and_test(&common->refcount))
complete(&common->free);
}
static u64 qp_allowed_event_types(void)
{
u64 mask;
mask = BIT(MLX5_EVENT_TYPE_PATH_MIG) |
BIT(MLX5_EVENT_TYPE_COMM_EST) |
BIT(MLX5_EVENT_TYPE_SQ_DRAINED) |
BIT(MLX5_EVENT_TYPE_SRQ_LAST_WQE) |
BIT(MLX5_EVENT_TYPE_WQ_CATAS_ERROR) |
BIT(MLX5_EVENT_TYPE_PATH_MIG_FAILED) |
BIT(MLX5_EVENT_TYPE_WQ_INVAL_REQ_ERROR) |
BIT(MLX5_EVENT_TYPE_WQ_ACCESS_ERROR);
return mask;
}
static u64 rq_allowed_event_types(void)
{
u64 mask;
mask = BIT(MLX5_EVENT_TYPE_SRQ_LAST_WQE) |
BIT(MLX5_EVENT_TYPE_WQ_CATAS_ERROR);
return mask;
}
static u64 sq_allowed_event_types(void)
{
return BIT(MLX5_EVENT_TYPE_WQ_CATAS_ERROR);
}
static bool is_event_type_allowed(int rsc_type, int event_type)
{
switch (rsc_type) {
case MLX5_EVENT_QUEUE_TYPE_QP:
return BIT(event_type) & qp_allowed_event_types();
case MLX5_EVENT_QUEUE_TYPE_RQ:
return BIT(event_type) & rq_allowed_event_types();
case MLX5_EVENT_QUEUE_TYPE_SQ:
return BIT(event_type) & sq_allowed_event_types();
default:
WARN(1, "Event arrived for unknown resource type");
return false;
}
}
void mlx5_rsc_event(struct mlx5_core_dev *dev, u32 rsn, int event_type)
{
struct mlx5_core_rsc_common *common = mlx5_get_rsc(dev, rsn);
struct mlx5_core_qp *qp;
if (!common)
return;
if (!is_event_type_allowed((rsn >> MLX5_USER_INDEX_LEN), event_type)) {
mlx5_core_warn(dev, "event 0x%.2x is not allowed on resource 0x%.8x\n",
event_type, rsn);
return;
}
switch (common->res) {
case MLX5_RES_QP:
case MLX5_RES_RQ:
case MLX5_RES_SQ:
qp = (struct mlx5_core_qp *)common;
qp->event(qp, event_type);
break;
default:
mlx5_core_warn(dev, "invalid resource type for 0x%x\n", rsn);
}
mlx5_core_put_rsc(common);
}
void mlx5_eq_pagefault(struct mlx5_core_dev *dev, struct mlx5_eqe *eqe)
{
struct mlx5_eqe_page_fault *pf_eqe = &eqe->data.page_fault;
int qpn = be32_to_cpu(pf_eqe->flags_qpn) & MLX5_QPN_MASK;
struct mlx5_core_rsc_common *common = mlx5_get_rsc(dev, qpn);
struct mlx5_core_qp *qp =
container_of(common, struct mlx5_core_qp, common);
struct mlx5_pagefault pfault;
if (!qp) {
mlx5_core_warn(dev, "ODP event for non-existent QP %06x\n",
qpn);
return;
}
pfault.event_subtype = eqe->sub_type;
pfault.flags = (be32_to_cpu(pf_eqe->flags_qpn) >> MLX5_QPN_BITS) &
(MLX5_PFAULT_REQUESTOR | MLX5_PFAULT_WRITE | MLX5_PFAULT_RDMA);
pfault.bytes_committed = be32_to_cpu(
pf_eqe->bytes_committed);
mlx5_core_dbg(dev,
"PAGE_FAULT: subtype: 0x%02x, flags: 0x%02x,\n",
eqe->sub_type, pfault.flags);
switch (eqe->sub_type) {
case MLX5_PFAULT_SUBTYPE_RDMA:
pfault.rdma.r_key =
be32_to_cpu(pf_eqe->rdma.r_key);
pfault.rdma.packet_size =
be16_to_cpu(pf_eqe->rdma.packet_length);
pfault.rdma.rdma_op_len =
be32_to_cpu(pf_eqe->rdma.rdma_op_len);
pfault.rdma.rdma_va =
be64_to_cpu(pf_eqe->rdma.rdma_va);
mlx5_core_dbg(dev,
"PAGE_FAULT: qpn: 0x%06x, r_key: 0x%08x,\n",
qpn, pfault.rdma.r_key);
mlx5_core_dbg(dev,
"PAGE_FAULT: rdma_op_len: 0x%08x,\n",
pfault.rdma.rdma_op_len);
mlx5_core_dbg(dev,
"PAGE_FAULT: rdma_va: 0x%016llx,\n",
pfault.rdma.rdma_va);
mlx5_core_dbg(dev,
"PAGE_FAULT: bytes_committed: 0x%06x\n",
pfault.bytes_committed);
break;
case MLX5_PFAULT_SUBTYPE_WQE:
pfault.wqe.wqe_index =
be16_to_cpu(pf_eqe->wqe.wqe_index);
pfault.wqe.packet_size =
be16_to_cpu(pf_eqe->wqe.packet_length);
mlx5_core_dbg(dev,
"PAGE_FAULT: qpn: 0x%06x, wqe_index: 0x%04x,\n",
qpn, pfault.wqe.wqe_index);
mlx5_core_dbg(dev,
"PAGE_FAULT: bytes_committed: 0x%06x\n",
pfault.bytes_committed);
break;
default:
mlx5_core_warn(dev,
"Unsupported page fault event sub-type: 0x%02hhx, QP %06x\n",
eqe->sub_type, qpn);
}
if (qp->pfault_handler) {
qp->pfault_handler(qp, &pfault);
} else {
mlx5_core_err(dev,
"ODP event for QP %08x, without a fault handler in QP\n",
qpn);
}
mlx5_core_put_rsc(common);
}
static int create_qprqsq_common(struct mlx5_core_dev *dev,
struct mlx5_core_qp *qp,
int rsc_type)
{
struct mlx5_qp_table *table = &dev->priv.qp_table;
int err;
qp->common.res = rsc_type;
spin_lock_irq(&table->lock);
err = radix_tree_insert(&table->tree,
qp->qpn | (rsc_type << MLX5_USER_INDEX_LEN),
qp);
spin_unlock_irq(&table->lock);
if (err)
return err;
atomic_set(&qp->common.refcount, 1);
init_completion(&qp->common.free);
qp->pid = current->pid;
return 0;
}
static void destroy_qprqsq_common(struct mlx5_core_dev *dev,
struct mlx5_core_qp *qp)
{
struct mlx5_qp_table *table = &dev->priv.qp_table;
unsigned long flags;
spin_lock_irqsave(&table->lock, flags);
radix_tree_delete(&table->tree,
qp->qpn | (qp->common.res << MLX5_USER_INDEX_LEN));
spin_unlock_irqrestore(&table->lock, flags);
mlx5_core_put_rsc((struct mlx5_core_rsc_common *)qp);
wait_for_completion(&qp->common.free);
}
int mlx5_core_create_qp(struct mlx5_core_dev *dev,
struct mlx5_core_qp *qp,
struct mlx5_create_qp_mbox_in *in,
int inlen)
{
struct mlx5_create_qp_mbox_out out;
struct mlx5_destroy_qp_mbox_in din;
struct mlx5_destroy_qp_mbox_out dout;
int err;
memset(&out, 0, sizeof(out));
in->hdr.opcode = cpu_to_be16(MLX5_CMD_OP_CREATE_QP);
err = mlx5_cmd_exec(dev, in, inlen, &out, sizeof(out));
if (err) {
mlx5_core_warn(dev, "ret %d\n", err);
return err;
}
if (out.hdr.status) {
mlx5_core_warn(dev, "current num of QPs 0x%x\n",
atomic_read(&dev->num_qps));
return mlx5_cmd_status_to_err(&out.hdr);
}
qp->qpn = be32_to_cpu(out.qpn) & 0xffffff;
mlx5_core_dbg(dev, "qpn = 0x%x\n", qp->qpn);
err = create_qprqsq_common(dev, qp, MLX5_RES_QP);
if (err)
goto err_cmd;
err = mlx5_debug_qp_add(dev, qp);
if (err)
mlx5_core_dbg(dev, "failed adding QP 0x%x to debug file system\n",
qp->qpn);
atomic_inc(&dev->num_qps);
return 0;
err_cmd:
memset(&din, 0, sizeof(din));
memset(&dout, 0, sizeof(dout));
din.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DESTROY_QP);
din.qpn = cpu_to_be32(qp->qpn);
mlx5_cmd_exec(dev, &din, sizeof(din), &out, sizeof(dout));
return err;
}
int mlx5_core_destroy_qp(struct mlx5_core_dev *dev,
struct mlx5_core_qp *qp)
{
struct mlx5_destroy_qp_mbox_in in;
struct mlx5_destroy_qp_mbox_out out;
int err;
mlx5_debug_qp_remove(dev, qp);
destroy_qprqsq_common(dev, qp);
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DESTROY_QP);
in.qpn = cpu_to_be32(qp->qpn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
return mlx5_cmd_status_to_err(&out.hdr);
atomic_dec(&dev->num_qps);
return 0;
}
int mlx5_core_qp_modify(struct mlx5_core_dev *dev, u16 operation,
struct mlx5_modify_qp_mbox_in *in, int sqd_event,
struct mlx5_core_qp *qp)
{
struct mlx5_modify_qp_mbox_out out;
int err = 0;
memset(&out, 0, sizeof(out));
in->hdr.opcode = cpu_to_be16(operation);
in->qpn = cpu_to_be32(qp->qpn);
err = mlx5_cmd_exec(dev, in, sizeof(*in), &out, sizeof(out));
if (err)
return err;
return mlx5_cmd_status_to_err(&out.hdr);
}
void mlx5_init_qp_table(struct mlx5_core_dev *dev)
{
struct mlx5_qp_table *table = &dev->priv.qp_table;
memset(table, 0, sizeof(*table));
spin_lock_init(&table->lock);
INIT_RADIX_TREE(&table->tree, GFP_ATOMIC);
mlx5_qp_debugfs_init(dev);
}
void mlx5_cleanup_qp_table(struct mlx5_core_dev *dev)
{
mlx5_qp_debugfs_cleanup(dev);
}
int mlx5_core_qp_query(struct mlx5_core_dev *dev, struct mlx5_core_qp *qp,
struct mlx5_query_qp_mbox_out *out, int outlen)
{
struct mlx5_query_qp_mbox_in in;
int err;
memset(&in, 0, sizeof(in));
memset(out, 0, outlen);
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_QUERY_QP);
in.qpn = cpu_to_be32(qp->qpn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), out, outlen);
if (err)
return err;
if (out->hdr.status)
return mlx5_cmd_status_to_err(&out->hdr);
return err;
}
int mlx5_core_xrcd_alloc(struct mlx5_core_dev *dev, u32 *xrcdn)
{
struct mlx5_alloc_xrcd_mbox_in in;
struct mlx5_alloc_xrcd_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_ALLOC_XRCD);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
err = mlx5_cmd_status_to_err(&out.hdr);
else
*xrcdn = be32_to_cpu(out.xrcdn);
return err;
}
int mlx5_core_xrcd_dealloc(struct mlx5_core_dev *dev, u32 xrcdn)
{
struct mlx5_dealloc_xrcd_mbox_in in;
struct mlx5_dealloc_xrcd_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DEALLOC_XRCD);
in.xrcdn = cpu_to_be32(xrcdn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
err = mlx5_cmd_status_to_err(&out.hdr);
return err;
}
int mlx5_core_page_fault_resume(struct mlx5_core_dev *dev, u32 qpn,
u8 flags, int error)
{
struct mlx5_page_fault_resume_mbox_in in;
struct mlx5_page_fault_resume_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_PAGE_FAULT_RESUME);
in.hdr.opmod = 0;
flags &= (MLX5_PAGE_FAULT_RESUME_REQUESTOR |
MLX5_PAGE_FAULT_RESUME_WRITE |
MLX5_PAGE_FAULT_RESUME_RDMA);
flags |= (error ? MLX5_PAGE_FAULT_RESUME_ERROR : 0);
in.flags_qpn = cpu_to_be32((qpn & MLX5_QPN_MASK) |
(flags << MLX5_QPN_BITS));
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
err = mlx5_cmd_status_to_err(&out.hdr);
return err;
}
int mlx5_core_create_rq_tracked(struct mlx5_core_dev *dev, u32 *in, int inlen,
struct mlx5_core_qp *rq)
{
int err;
u32 rqn;
err = mlx5_core_create_rq(dev, in, inlen, &rqn);
if (err)
return err;
rq->qpn = rqn;
err = create_qprqsq_common(dev, rq, MLX5_RES_RQ);
if (err)
goto err_destroy_rq;
return 0;
err_destroy_rq:
mlx5_core_destroy_rq(dev, rq->qpn);
return err;
}
void mlx5_core_destroy_rq_tracked(struct mlx5_core_dev *dev,
struct mlx5_core_qp *rq)
{
destroy_qprqsq_common(dev, rq);
mlx5_core_destroy_rq(dev, rq->qpn);
}
int mlx5_core_create_sq_tracked(struct mlx5_core_dev *dev, u32 *in, int inlen,
struct mlx5_core_qp *sq)
{
int err;
u32 sqn;
err = mlx5_core_create_sq(dev, in, inlen, &sqn);
if (err)
return err;
sq->qpn = sqn;
err = create_qprqsq_common(dev, sq, MLX5_RES_SQ);
if (err)
goto err_destroy_sq;
return 0;
err_destroy_sq:
mlx5_core_destroy_sq(dev, sq->qpn);
return err;
}
void mlx5_core_destroy_sq_tracked(struct mlx5_core_dev *dev,
struct mlx5_core_qp *sq)
{
destroy_qprqsq_common(dev, sq);
mlx5_core_destroy_sq(dev, sq->qpn);
}
