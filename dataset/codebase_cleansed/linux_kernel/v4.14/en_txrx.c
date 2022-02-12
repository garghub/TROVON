static inline bool mlx5e_channel_no_affinity_change(struct mlx5e_channel *c)
{
int current_cpu = smp_processor_id();
const struct cpumask *aff;
struct irq_data *idata;
idata = irq_desc_get_irq_data(c->irq_desc);
aff = irq_data_get_affinity_mask(idata);
return cpumask_test_cpu(current_cpu, aff);
}
int mlx5e_napi_poll(struct napi_struct *napi, int budget)
{
struct mlx5e_channel *c = container_of(napi, struct mlx5e_channel,
napi);
bool busy = false;
int work_done = 0;
int i;
for (i = 0; i < c->num_tc; i++)
busy |= mlx5e_poll_tx_cq(&c->sq[i].cq, budget);
if (c->xdp)
busy |= mlx5e_poll_xdpsq_cq(&c->rq.xdpsq.cq);
if (likely(budget)) {
work_done = mlx5e_poll_rx_cq(&c->rq.cq, budget);
busy |= work_done == budget;
}
busy |= c->rq.post_wqes(&c->rq);
if (busy) {
if (likely(mlx5e_channel_no_affinity_change(c)))
return budget;
if (budget && work_done == budget)
work_done--;
}
if (unlikely(!napi_complete_done(napi, work_done)))
return work_done;
for (i = 0; i < c->num_tc; i++)
mlx5e_cq_arm(&c->sq[i].cq);
if (MLX5E_TEST_BIT(c->rq.state, MLX5E_RQ_STATE_AM))
mlx5e_rx_am(&c->rq);
mlx5e_cq_arm(&c->rq.cq);
mlx5e_cq_arm(&c->icosq.cq);
return work_done;
}
void mlx5e_completion_event(struct mlx5_core_cq *mcq)
{
struct mlx5e_cq *cq = container_of(mcq, struct mlx5e_cq, mcq);
cq->event_ctr++;
napi_schedule(cq->napi);
}
void mlx5e_cq_error_event(struct mlx5_core_cq *mcq, enum mlx5_event event)
{
struct mlx5e_cq *cq = container_of(mcq, struct mlx5e_cq, mcq);
struct mlx5e_channel *c = cq->channel;
struct net_device *netdev = c->netdev;
netdev_err(netdev, "%s: cqn=0x%.6x event=0x%.2x\n",
__func__, mcq->cqn, event);
}
