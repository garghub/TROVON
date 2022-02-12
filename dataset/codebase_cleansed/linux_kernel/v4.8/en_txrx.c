struct mlx5_cqe64 *mlx5e_get_cqe(struct mlx5e_cq *cq)
{
struct mlx5_cqwq *wq = &cq->wq;
u32 ci = mlx5_cqwq_get_ci(wq);
struct mlx5_cqe64 *cqe = mlx5_cqwq_get_wqe(wq, ci);
int cqe_ownership_bit = cqe->op_own & MLX5_CQE_OWNER_MASK;
int sw_ownership_val = mlx5_cqwq_get_wrap_cnt(wq) & 1;
if (cqe_ownership_bit != sw_ownership_val)
return NULL;
rmb();
return cqe;
}
static void mlx5e_poll_ico_cq(struct mlx5e_cq *cq)
{
struct mlx5e_sq *sq = container_of(cq, struct mlx5e_sq, cq);
struct mlx5_wq_cyc *wq;
struct mlx5_cqe64 *cqe;
u16 sqcc;
if (unlikely(test_bit(MLX5E_SQ_STATE_FLUSH, &sq->state)))
return;
cqe = mlx5e_get_cqe(cq);
if (likely(!cqe))
return;
wq = &sq->wq;
sqcc = sq->cc;
do {
u16 ci = be16_to_cpu(cqe->wqe_counter) & wq->sz_m1;
struct mlx5e_ico_wqe_info *icowi = &sq->ico_wqe_info[ci];
mlx5_cqwq_pop(&cq->wq);
sqcc += icowi->num_wqebbs;
if (unlikely((cqe->op_own >> 4) != MLX5_CQE_REQ)) {
WARN_ONCE(true, "mlx5e: Bad OP in ICOSQ CQE: 0x%x\n",
cqe->op_own);
break;
}
switch (icowi->opcode) {
case MLX5_OPCODE_NOP:
break;
case MLX5_OPCODE_UMR:
mlx5e_post_rx_fragmented_mpwqe(&sq->channel->rq);
break;
default:
WARN_ONCE(true,
"mlx5e: Bad OPCODE in ICOSQ WQE info: 0x%x\n",
icowi->opcode);
}
} while ((cqe = mlx5e_get_cqe(cq)));
mlx5_cqwq_update_db_record(&cq->wq);
wmb();
sq->cc = sqcc;
}
int mlx5e_napi_poll(struct napi_struct *napi, int budget)
{
struct mlx5e_channel *c = container_of(napi, struct mlx5e_channel,
napi);
bool busy = false;
int work_done;
int i;
clear_bit(MLX5E_CHANNEL_NAPI_SCHED, &c->flags);
for (i = 0; i < c->num_tc; i++)
busy |= mlx5e_poll_tx_cq(&c->sq[i].cq, budget);
work_done = mlx5e_poll_rx_cq(&c->rq.cq, budget);
busy |= work_done == budget;
mlx5e_poll_ico_cq(&c->icosq.cq);
busy |= mlx5e_post_rx_wqes(&c->rq);
if (busy)
return budget;
napi_complete_done(napi, work_done);
if (test_bit(MLX5E_CHANNEL_NAPI_SCHED, &c->flags)) {
napi_schedule(napi);
return work_done;
}
for (i = 0; i < c->num_tc; i++)
mlx5e_cq_arm(&c->sq[i].cq);
if (test_bit(MLX5E_RQ_STATE_AM, &c->rq.state))
mlx5e_rx_am(&c->rq);
mlx5e_cq_arm(&c->rq.cq);
mlx5e_cq_arm(&c->icosq.cq);
return work_done;
}
void mlx5e_completion_event(struct mlx5_core_cq *mcq)
{
struct mlx5e_cq *cq = container_of(mcq, struct mlx5e_cq, mcq);
cq->event_ctr++;
set_bit(MLX5E_CHANNEL_NAPI_SCHED, &cq->channel->flags);
napi_schedule(cq->napi);
}
void mlx5e_cq_error_event(struct mlx5_core_cq *mcq, enum mlx5_event event)
{
struct mlx5e_cq *cq = container_of(mcq, struct mlx5e_cq, mcq);
struct mlx5e_channel *c = cq->channel;
struct mlx5e_priv *priv = c->priv;
struct net_device *netdev = priv->netdev;
netdev_err(netdev, "%s: cqn=0x%.6x event=0x%.2x\n",
__func__, mcq->cqn, event);
}
