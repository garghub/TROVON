int mlx4_SET_PORT_PRIO2TC(struct mlx4_dev *dev, u8 port, u8 *prio2tc)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_prio2tc_context *context;
int err;
u32 in_mod;
int i;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
for (i = 0; i < MLX4_NUM_UP; i += 2)
context->prio2tc[i >> 1] = prio2tc[i] << 4 | prio2tc[i + 1];
in_mod = MLX4_SET_PORT_PRIO2TC << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_PORT_SCHEDULER(struct mlx4_dev *dev, u8 port, u8 *tc_tx_bw,
u8 *pg, u16 *ratelimit)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_port_scheduler_context *context;
int err;
u32 in_mod;
int i;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
context = mailbox->buf;
for (i = 0; i < MLX4_NUM_TC; i++) {
struct mlx4_port_scheduler_tc_cfg_be *tc = &context->tc[i];
u16 r;
if (ratelimit && ratelimit[i]) {
if (ratelimit[i] <= MLX4_MAX_100M_UNITS_VAL) {
r = ratelimit[i];
tc->max_bw_units =
htons(MLX4_RATELIMIT_100M_UNITS);
} else {
r = ratelimit[i] / 10;
tc->max_bw_units =
htons(MLX4_RATELIMIT_1G_UNITS);
}
tc->max_bw_value = htons(r);
} else {
tc->max_bw_value = htons(MLX4_RATELIMIT_DEFAULT);
tc->max_bw_units = htons(MLX4_RATELIMIT_1G_UNITS);
}
tc->pg = htons(pg[i]);
tc->bw_precentage = htons(tc_tx_bw[i]);
}
in_mod = MLX4_SET_PORT_SCHEDULER << 8 | port;
err = mlx4_cmd(dev, mailbox->dma, in_mod, 1, MLX4_CMD_SET_PORT,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_ALLOCATE_VPP_get(struct mlx4_dev *dev, u8 port,
u16 *available_vpp, u8 *vpp_p_up)
{
int i;
int err;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_alloc_vpp_param *out_param;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
out_param = mailbox->buf;
err = mlx4_cmd_box(dev, 0, mailbox->dma, port,
MLX4_ALLOCATE_VPP_QUERY,
MLX4_CMD_ALLOCATE_VPP,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
goto out;
*available_vpp = (u16)be32_to_cpu(out_param->available_vpp);
for (i = 0; i < MLX4_NUM_UP; i++)
vpp_p_up[i] = (u8)be32_to_cpu(out_param->vpp_p_up[i]);
out:
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_ALLOCATE_VPP_set(struct mlx4_dev *dev, u8 port, u8 *vpp_p_up)
{
int i;
int err;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_alloc_vpp_param *in_param;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
in_param = mailbox->buf;
for (i = 0; i < MLX4_NUM_UP; i++)
in_param->vpp_p_up[i] = cpu_to_be32(vpp_p_up[i]);
err = mlx4_cmd(dev, mailbox->dma, port,
MLX4_ALLOCATE_VPP_ALLOCATE,
MLX4_CMD_ALLOCATE_VPP,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_VPORT_QOS_get(struct mlx4_dev *dev, u8 port, u8 vport,
struct mlx4_vport_qos_param *out_param)
{
int i;
int err;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_vport_context *ctx;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
ctx = mailbox->buf;
err = mlx4_cmd_box(dev, 0, mailbox->dma, (vport << 8) | port,
MLX4_SET_VPORT_QOS_QUERY,
MLX4_CMD_SET_VPORT_QOS,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
if (err)
goto out;
for (i = 0; i < MLX4_NUM_UP; i++) {
out_param[i].bw_share = be32_to_cpu(ctx->qos_p_up[i].bw_share);
out_param[i].max_avg_bw =
be32_to_cpu(ctx->qos_p_up[i].max_avg_bw);
out_param[i].enable =
!!(be32_to_cpu(ctx->qos_p_up[i].enable) & 31);
}
out:
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_SET_VPORT_QOS_set(struct mlx4_dev *dev, u8 port, u8 vport,
struct mlx4_vport_qos_param *in_param)
{
int i;
int err;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_vport_context *ctx;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
ctx = mailbox->buf;
for (i = 0; i < MLX4_NUM_UP; i++) {
ctx->qos_p_up[i].bw_share = cpu_to_be32(in_param[i].bw_share);
ctx->qos_p_up[i].max_avg_bw =
cpu_to_be32(in_param[i].max_avg_bw);
ctx->qos_p_up[i].enable =
cpu_to_be32(in_param[i].enable << 31);
}
err = mlx4_cmd(dev, mailbox->dma, (vport << 8) | port,
MLX4_SET_VPORT_QOS_SET,
MLX4_CMD_SET_VPORT_QOS,
MLX4_CMD_TIME_CLASS_A,
MLX4_CMD_NATIVE);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
