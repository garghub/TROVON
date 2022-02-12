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
mlx5e_cq_arm(&c->rq.cq);
return work_done;
}
void mlx5e_completion_event(struct mlx5_core_cq *mcq)
{
struct mlx5e_cq *cq = container_of(mcq, struct mlx5e_cq, mcq);
set_bit(MLX5E_CHANNEL_NAPI_SCHED, &cq->channel->flags);
barrier();
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
