void mlx5_srq_event(struct mlx5_core_dev *dev, u32 srqn, int event_type)
{
struct mlx5_srq_table *table = &dev->priv.srq_table;
struct mlx5_core_srq *srq;
spin_lock(&table->lock);
srq = radix_tree_lookup(&table->tree, srqn);
if (srq)
atomic_inc(&srq->refcount);
spin_unlock(&table->lock);
if (!srq) {
mlx5_core_warn(dev, "Async event for bogus SRQ 0x%08x\n", srqn);
return;
}
srq->event(srq, event_type);
if (atomic_dec_and_test(&srq->refcount))
complete(&srq->free);
}
static int get_pas_size(void *srqc)
{
u32 log_page_size = MLX5_GET(srqc, srqc, log_page_size) + 12;
u32 log_srq_size = MLX5_GET(srqc, srqc, log_srq_size);
u32 log_rq_stride = MLX5_GET(srqc, srqc, log_rq_stride);
u32 page_offset = MLX5_GET(srqc, srqc, page_offset);
u32 po_quanta = 1 << (log_page_size - 6);
u32 rq_sz = 1 << (log_srq_size + 4 + log_rq_stride);
u32 page_size = 1 << log_page_size;
u32 rq_sz_po = rq_sz + (page_offset * po_quanta);
u32 rq_num_pas = (rq_sz_po + page_size - 1) / page_size;
return rq_num_pas * sizeof(u64);
}
static void rmpc_srqc_reformat(void *srqc, void *rmpc, bool srqc_to_rmpc)
{
void *wq = MLX5_ADDR_OF(rmpc, rmpc, wq);
if (srqc_to_rmpc) {
switch (MLX5_GET(srqc, srqc, state)) {
case MLX5_SRQC_STATE_GOOD:
MLX5_SET(rmpc, rmpc, state, MLX5_RMPC_STATE_RDY);
break;
case MLX5_SRQC_STATE_ERROR:
MLX5_SET(rmpc, rmpc, state, MLX5_RMPC_STATE_ERR);
break;
default:
pr_warn("%s: %d: Unknown srq state = 0x%x\n", __func__,
__LINE__, MLX5_GET(srqc, srqc, state));
MLX5_SET(rmpc, rmpc, state, MLX5_GET(srqc, srqc, state));
}
MLX5_SET(wq, wq, wq_signature, MLX5_GET(srqc, srqc, wq_signature));
MLX5_SET(wq, wq, log_wq_pg_sz, MLX5_GET(srqc, srqc, log_page_size));
MLX5_SET(wq, wq, log_wq_stride, MLX5_GET(srqc, srqc, log_rq_stride) + 4);
MLX5_SET(wq, wq, log_wq_sz, MLX5_GET(srqc, srqc, log_srq_size));
MLX5_SET(wq, wq, page_offset, MLX5_GET(srqc, srqc, page_offset));
MLX5_SET(wq, wq, lwm, MLX5_GET(srqc, srqc, lwm));
MLX5_SET(wq, wq, pd, MLX5_GET(srqc, srqc, pd));
MLX5_SET64(wq, wq, dbr_addr, MLX5_GET64(srqc, srqc, dbr_addr));
} else {
switch (MLX5_GET(rmpc, rmpc, state)) {
case MLX5_RMPC_STATE_RDY:
MLX5_SET(srqc, srqc, state, MLX5_SRQC_STATE_GOOD);
break;
case MLX5_RMPC_STATE_ERR:
MLX5_SET(srqc, srqc, state, MLX5_SRQC_STATE_ERROR);
break;
default:
pr_warn("%s: %d: Unknown rmp state = 0x%x\n",
__func__, __LINE__,
MLX5_GET(rmpc, rmpc, state));
MLX5_SET(srqc, srqc, state,
MLX5_GET(rmpc, rmpc, state));
}
MLX5_SET(srqc, srqc, wq_signature, MLX5_GET(wq, wq, wq_signature));
MLX5_SET(srqc, srqc, log_page_size, MLX5_GET(wq, wq, log_wq_pg_sz));
MLX5_SET(srqc, srqc, log_rq_stride, MLX5_GET(wq, wq, log_wq_stride) - 4);
MLX5_SET(srqc, srqc, log_srq_size, MLX5_GET(wq, wq, log_wq_sz));
MLX5_SET(srqc, srqc, page_offset, MLX5_GET(wq, wq, page_offset));
MLX5_SET(srqc, srqc, lwm, MLX5_GET(wq, wq, lwm));
MLX5_SET(srqc, srqc, pd, MLX5_GET(wq, wq, pd));
MLX5_SET64(srqc, srqc, dbr_addr, MLX5_GET64(wq, wq, dbr_addr));
}
}
struct mlx5_core_srq *mlx5_core_get_srq(struct mlx5_core_dev *dev, u32 srqn)
{
struct mlx5_srq_table *table = &dev->priv.srq_table;
struct mlx5_core_srq *srq;
spin_lock(&table->lock);
srq = radix_tree_lookup(&table->tree, srqn);
if (srq)
atomic_inc(&srq->refcount);
spin_unlock(&table->lock);
return srq;
}
static int create_srq_cmd(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_create_srq_mbox_in *in, int inlen)
{
struct mlx5_create_srq_mbox_out out;
int err;
memset(&out, 0, sizeof(out));
in->hdr.opcode = cpu_to_be16(MLX5_CMD_OP_CREATE_SRQ);
err = mlx5_cmd_exec_check_status(dev, (u32 *)in, inlen, (u32 *)(&out),
sizeof(out));
srq->srqn = be32_to_cpu(out.srqn) & 0xffffff;
return err;
}
static int destroy_srq_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq)
{
struct mlx5_destroy_srq_mbox_in in;
struct mlx5_destroy_srq_mbox_out out;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DESTROY_SRQ);
in.srqn = cpu_to_be32(srq->srqn);
return mlx5_cmd_exec_check_status(dev, (u32 *)(&in), sizeof(in),
(u32 *)(&out), sizeof(out));
}
static int arm_srq_cmd(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
u16 lwm, int is_srq)
{
struct mlx5_arm_srq_mbox_in in;
struct mlx5_arm_srq_mbox_out out;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_ARM_RQ);
in.hdr.opmod = cpu_to_be16(!!is_srq);
in.srqn = cpu_to_be32(srq->srqn);
in.lwm = cpu_to_be16(lwm);
return mlx5_cmd_exec_check_status(dev, (u32 *)(&in),
sizeof(in), (u32 *)(&out),
sizeof(out));
}
static int query_srq_cmd(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_query_srq_mbox_out *out)
{
struct mlx5_query_srq_mbox_in in;
memset(&in, 0, sizeof(in));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_QUERY_SRQ);
in.srqn = cpu_to_be32(srq->srqn);
return mlx5_cmd_exec_check_status(dev, (u32 *)(&in), sizeof(in),
(u32 *)out, sizeof(*out));
}
static int create_xrc_srq_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq,
struct mlx5_create_srq_mbox_in *in,
int srq_inlen)
{
u32 create_out[MLX5_ST_SZ_DW(create_xrc_srq_out)];
void *create_in;
void *srqc;
void *xrc_srqc;
void *pas;
int pas_size;
int inlen;
int err;
srqc = MLX5_ADDR_OF(create_srq_in, in, srq_context_entry);
pas_size = get_pas_size(srqc);
inlen = MLX5_ST_SZ_BYTES(create_xrc_srq_in) + pas_size;
create_in = mlx5_vzalloc(inlen);
if (!create_in)
return -ENOMEM;
xrc_srqc = MLX5_ADDR_OF(create_xrc_srq_in, create_in,
xrc_srq_context_entry);
pas = MLX5_ADDR_OF(create_xrc_srq_in, create_in, pas);
memcpy(xrc_srqc, srqc, MLX5_ST_SZ_BYTES(srqc));
memcpy(pas, in->pas, pas_size);
MLX5_SET(create_xrc_srq_in, create_in, opcode,
MLX5_CMD_OP_CREATE_XRC_SRQ);
memset(create_out, 0, sizeof(create_out));
err = mlx5_cmd_exec_check_status(dev, create_in, inlen, create_out,
sizeof(create_out));
if (err)
goto out;
srq->srqn = MLX5_GET(create_xrc_srq_out, create_out, xrc_srqn);
out:
kvfree(create_in);
return err;
}
static int destroy_xrc_srq_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq)
{
u32 xrcsrq_in[MLX5_ST_SZ_DW(destroy_xrc_srq_in)];
u32 xrcsrq_out[MLX5_ST_SZ_DW(destroy_xrc_srq_out)];
memset(xrcsrq_in, 0, sizeof(xrcsrq_in));
memset(xrcsrq_out, 0, sizeof(xrcsrq_out));
MLX5_SET(destroy_xrc_srq_in, xrcsrq_in, opcode,
MLX5_CMD_OP_DESTROY_XRC_SRQ);
MLX5_SET(destroy_xrc_srq_in, xrcsrq_in, xrc_srqn, srq->srqn);
return mlx5_cmd_exec_check_status(dev, xrcsrq_in, sizeof(xrcsrq_in),
xrcsrq_out, sizeof(xrcsrq_out));
}
static int arm_xrc_srq_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq, u16 lwm)
{
u32 xrcsrq_in[MLX5_ST_SZ_DW(arm_xrc_srq_in)];
u32 xrcsrq_out[MLX5_ST_SZ_DW(arm_xrc_srq_out)];
memset(xrcsrq_in, 0, sizeof(xrcsrq_in));
memset(xrcsrq_out, 0, sizeof(xrcsrq_out));
MLX5_SET(arm_xrc_srq_in, xrcsrq_in, opcode, MLX5_CMD_OP_ARM_XRC_SRQ);
MLX5_SET(arm_xrc_srq_in, xrcsrq_in, op_mod, MLX5_ARM_XRC_SRQ_IN_OP_MOD_XRC_SRQ);
MLX5_SET(arm_xrc_srq_in, xrcsrq_in, xrc_srqn, srq->srqn);
MLX5_SET(arm_xrc_srq_in, xrcsrq_in, lwm, lwm);
return mlx5_cmd_exec_check_status(dev, xrcsrq_in, sizeof(xrcsrq_in),
xrcsrq_out, sizeof(xrcsrq_out));
}
static int query_xrc_srq_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq,
struct mlx5_query_srq_mbox_out *out)
{
u32 xrcsrq_in[MLX5_ST_SZ_DW(query_xrc_srq_in)];
u32 *xrcsrq_out;
void *srqc;
void *xrc_srqc;
int err;
xrcsrq_out = mlx5_vzalloc(MLX5_ST_SZ_BYTES(query_xrc_srq_out));
if (!xrcsrq_out)
return -ENOMEM;
memset(xrcsrq_in, 0, sizeof(xrcsrq_in));
MLX5_SET(query_xrc_srq_in, xrcsrq_in, opcode,
MLX5_CMD_OP_QUERY_XRC_SRQ);
MLX5_SET(query_xrc_srq_in, xrcsrq_in, xrc_srqn, srq->srqn);
err = mlx5_cmd_exec_check_status(dev, xrcsrq_in, sizeof(xrcsrq_in),
xrcsrq_out,
MLX5_ST_SZ_BYTES(query_xrc_srq_out));
if (err)
goto out;
xrc_srqc = MLX5_ADDR_OF(query_xrc_srq_out, xrcsrq_out,
xrc_srq_context_entry);
srqc = MLX5_ADDR_OF(query_srq_out, out, srq_context_entry);
memcpy(srqc, xrc_srqc, MLX5_ST_SZ_BYTES(srqc));
out:
kvfree(xrcsrq_out);
return err;
}
static int create_rmp_cmd(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_create_srq_mbox_in *in, int srq_inlen)
{
void *create_in;
void *rmpc;
void *srqc;
int pas_size;
int inlen;
int err;
srqc = MLX5_ADDR_OF(create_srq_in, in, srq_context_entry);
pas_size = get_pas_size(srqc);
inlen = MLX5_ST_SZ_BYTES(create_rmp_in) + pas_size;
create_in = mlx5_vzalloc(inlen);
if (!create_in)
return -ENOMEM;
rmpc = MLX5_ADDR_OF(create_rmp_in, create_in, ctx);
memcpy(MLX5_ADDR_OF(rmpc, rmpc, wq.pas), in->pas, pas_size);
rmpc_srqc_reformat(srqc, rmpc, true);
err = mlx5_core_create_rmp(dev, create_in, inlen, &srq->srqn);
kvfree(create_in);
return err;
}
static int destroy_rmp_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq)
{
return mlx5_core_destroy_rmp(dev, srq->srqn);
}
static int arm_rmp_cmd(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq,
u16 lwm)
{
void *in;
void *rmpc;
void *wq;
void *bitmask;
int err;
in = mlx5_vzalloc(MLX5_ST_SZ_BYTES(modify_rmp_in));
if (!in)
return -ENOMEM;
rmpc = MLX5_ADDR_OF(modify_rmp_in, in, ctx);
bitmask = MLX5_ADDR_OF(modify_rmp_in, in, bitmask);
wq = MLX5_ADDR_OF(rmpc, rmpc, wq);
MLX5_SET(modify_rmp_in, in, rmp_state, MLX5_RMPC_STATE_RDY);
MLX5_SET(modify_rmp_in, in, rmpn, srq->srqn);
MLX5_SET(wq, wq, lwm, lwm);
MLX5_SET(rmp_bitmask, bitmask, lwm, 1);
MLX5_SET(rmpc, rmpc, state, MLX5_RMPC_STATE_RDY);
err = mlx5_core_modify_rmp(dev, in, MLX5_ST_SZ_BYTES(modify_rmp_in));
kvfree(in);
return err;
}
static int query_rmp_cmd(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_query_srq_mbox_out *out)
{
u32 *rmp_out;
void *rmpc;
void *srqc;
int err;
rmp_out = mlx5_vzalloc(MLX5_ST_SZ_BYTES(query_rmp_out));
if (!rmp_out)
return -ENOMEM;
err = mlx5_core_query_rmp(dev, srq->srqn, rmp_out);
if (err)
goto out;
srqc = MLX5_ADDR_OF(query_srq_out, out, srq_context_entry);
rmpc = MLX5_ADDR_OF(query_rmp_out, rmp_out, rmp_context);
rmpc_srqc_reformat(srqc, rmpc, false);
out:
kvfree(rmp_out);
return err;
}
static int create_srq_split(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq,
struct mlx5_create_srq_mbox_in *in,
int inlen, int is_xrc)
{
if (!dev->issi)
return create_srq_cmd(dev, srq, in, inlen);
else if (srq->common.res == MLX5_RES_XSRQ)
return create_xrc_srq_cmd(dev, srq, in, inlen);
else
return create_rmp_cmd(dev, srq, in, inlen);
}
static int destroy_srq_split(struct mlx5_core_dev *dev,
struct mlx5_core_srq *srq)
{
if (!dev->issi)
return destroy_srq_cmd(dev, srq);
else if (srq->common.res == MLX5_RES_XSRQ)
return destroy_xrc_srq_cmd(dev, srq);
else
return destroy_rmp_cmd(dev, srq);
}
int mlx5_core_create_srq(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_create_srq_mbox_in *in, int inlen,
int is_xrc)
{
int err;
struct mlx5_srq_table *table = &dev->priv.srq_table;
srq->common.res = is_xrc ? MLX5_RES_XSRQ : MLX5_RES_SRQ;
err = create_srq_split(dev, srq, in, inlen, is_xrc);
if (err)
return err;
atomic_set(&srq->refcount, 1);
init_completion(&srq->free);
spin_lock_irq(&table->lock);
err = radix_tree_insert(&table->tree, srq->srqn, srq);
spin_unlock_irq(&table->lock);
if (err) {
mlx5_core_warn(dev, "err %d, srqn 0x%x\n", err, srq->srqn);
goto err_destroy_srq_split;
}
return 0;
err_destroy_srq_split:
destroy_srq_split(dev, srq);
return err;
}
int mlx5_core_destroy_srq(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq)
{
struct mlx5_srq_table *table = &dev->priv.srq_table;
struct mlx5_core_srq *tmp;
int err;
spin_lock_irq(&table->lock);
tmp = radix_tree_delete(&table->tree, srq->srqn);
spin_unlock_irq(&table->lock);
if (!tmp) {
mlx5_core_warn(dev, "srq 0x%x not found in tree\n", srq->srqn);
return -EINVAL;
}
if (tmp != srq) {
mlx5_core_warn(dev, "corruption on srqn 0x%x\n", srq->srqn);
return -EINVAL;
}
err = destroy_srq_split(dev, srq);
if (err)
return err;
if (atomic_dec_and_test(&srq->refcount))
complete(&srq->free);
wait_for_completion(&srq->free);
return 0;
}
int mlx5_core_query_srq(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
struct mlx5_query_srq_mbox_out *out)
{
if (!dev->issi)
return query_srq_cmd(dev, srq, out);
else if (srq->common.res == MLX5_RES_XSRQ)
return query_xrc_srq_cmd(dev, srq, out);
else
return query_rmp_cmd(dev, srq, out);
}
int mlx5_core_arm_srq(struct mlx5_core_dev *dev, struct mlx5_core_srq *srq,
u16 lwm, int is_srq)
{
if (!dev->issi)
return arm_srq_cmd(dev, srq, lwm, is_srq);
else if (srq->common.res == MLX5_RES_XSRQ)
return arm_xrc_srq_cmd(dev, srq, lwm);
else
return arm_rmp_cmd(dev, srq, lwm);
}
void mlx5_init_srq_table(struct mlx5_core_dev *dev)
{
struct mlx5_srq_table *table = &dev->priv.srq_table;
memset(table, 0, sizeof(*table));
spin_lock_init(&table->lock);
INIT_RADIX_TREE(&table->tree, GFP_ATOMIC);
}
void mlx5_cleanup_srq_table(struct mlx5_core_dev *dev)
{
}
