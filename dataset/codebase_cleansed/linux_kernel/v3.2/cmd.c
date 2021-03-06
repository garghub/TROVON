static int mlx4_status_to_errno(u8 status)
{
static const int trans_table[] = {
[CMD_STAT_INTERNAL_ERR] = -EIO,
[CMD_STAT_BAD_OP] = -EPERM,
[CMD_STAT_BAD_PARAM] = -EINVAL,
[CMD_STAT_BAD_SYS_STATE] = -ENXIO,
[CMD_STAT_BAD_RESOURCE] = -EBADF,
[CMD_STAT_RESOURCE_BUSY] = -EBUSY,
[CMD_STAT_EXCEED_LIM] = -ENOMEM,
[CMD_STAT_BAD_RES_STATE] = -EBADF,
[CMD_STAT_BAD_INDEX] = -EBADF,
[CMD_STAT_BAD_NVMEM] = -EFAULT,
[CMD_STAT_ICM_ERROR] = -ENFILE,
[CMD_STAT_BAD_QP_STATE] = -EINVAL,
[CMD_STAT_BAD_SEG_PARAM] = -EFAULT,
[CMD_STAT_REG_BOUND] = -EBUSY,
[CMD_STAT_LAM_NOT_PRE] = -EAGAIN,
[CMD_STAT_BAD_PKT] = -EINVAL,
[CMD_STAT_BAD_SIZE] = -ENOMEM,
[CMD_STAT_MULTI_FUNC_REQ] = -EACCES,
};
if (status >= ARRAY_SIZE(trans_table) ||
(status != CMD_STAT_OK && trans_table[status] == 0))
return -EIO;
return trans_table[status];
}
static int cmd_pending(struct mlx4_dev *dev)
{
u32 status = readl(mlx4_priv(dev)->cmd.hcr + HCR_STATUS_OFFSET);
return (status & swab32(1 << HCR_GO_BIT)) ||
(mlx4_priv(dev)->cmd.toggle ==
!!(status & swab32(1 << HCR_T_BIT)));
}
static int mlx4_cmd_post(struct mlx4_dev *dev, u64 in_param, u64 out_param,
u32 in_modifier, u8 op_modifier, u16 op, u16 token,
int event)
{
struct mlx4_cmd *cmd = &mlx4_priv(dev)->cmd;
u32 __iomem *hcr = cmd->hcr;
int ret = -EAGAIN;
unsigned long end;
mutex_lock(&cmd->hcr_mutex);
end = jiffies;
if (event)
end += msecs_to_jiffies(GO_BIT_TIMEOUT_MSECS);
while (cmd_pending(dev)) {
if (time_after_eq(jiffies, end))
goto out;
cond_resched();
}
__raw_writel((__force u32) cpu_to_be32(in_param >> 32), hcr + 0);
__raw_writel((__force u32) cpu_to_be32(in_param & 0xfffffffful), hcr + 1);
__raw_writel((__force u32) cpu_to_be32(in_modifier), hcr + 2);
__raw_writel((__force u32) cpu_to_be32(out_param >> 32), hcr + 3);
__raw_writel((__force u32) cpu_to_be32(out_param & 0xfffffffful), hcr + 4);
__raw_writel((__force u32) cpu_to_be32(token << 16), hcr + 5);
wmb();
__raw_writel((__force u32) cpu_to_be32((1 << HCR_GO_BIT) |
(cmd->toggle << HCR_T_BIT) |
(event ? (1 << HCR_E_BIT) : 0) |
(op_modifier << HCR_OPMOD_SHIFT) |
op), hcr + 6);
mmiowb();
cmd->toggle = cmd->toggle ^ 1;
ret = 0;
out:
mutex_unlock(&cmd->hcr_mutex);
return ret;
}
static int mlx4_cmd_poll(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
struct mlx4_priv *priv = mlx4_priv(dev);
void __iomem *hcr = priv->cmd.hcr;
int err = 0;
unsigned long end;
down(&priv->cmd.poll_sem);
err = mlx4_cmd_post(dev, in_param, out_param ? *out_param : 0,
in_modifier, op_modifier, op, CMD_POLL_TOKEN, 0);
if (err)
goto out;
end = msecs_to_jiffies(timeout) + jiffies;
while (cmd_pending(dev) && time_before(jiffies, end))
cond_resched();
if (cmd_pending(dev)) {
err = -ETIMEDOUT;
goto out;
}
if (out_is_imm)
*out_param =
(u64) be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_OUT_PARAM_OFFSET)) << 32 |
(u64) be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_OUT_PARAM_OFFSET + 4));
err = mlx4_status_to_errno(be32_to_cpu((__force __be32)
__raw_readl(hcr + HCR_STATUS_OFFSET)) >> 24);
out:
up(&priv->cmd.poll_sem);
return err;
}
void mlx4_cmd_event(struct mlx4_dev *dev, u16 token, u8 status, u64 out_param)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_cmd_context *context =
&priv->cmd.context[token & priv->cmd.token_mask];
if (token != context->token)
return;
context->result = mlx4_status_to_errno(status);
context->out_param = out_param;
complete(&context->done);
}
static int mlx4_cmd_wait(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
struct mlx4_cmd *cmd = &mlx4_priv(dev)->cmd;
struct mlx4_cmd_context *context;
int err = 0;
down(&cmd->event_sem);
spin_lock(&cmd->context_lock);
BUG_ON(cmd->free_head < 0);
context = &cmd->context[cmd->free_head];
context->token += cmd->token_mask + 1;
cmd->free_head = context->next;
spin_unlock(&cmd->context_lock);
init_completion(&context->done);
mlx4_cmd_post(dev, in_param, out_param ? *out_param : 0,
in_modifier, op_modifier, op, context->token, 1);
if (!wait_for_completion_timeout(&context->done, msecs_to_jiffies(timeout))) {
err = -EBUSY;
goto out;
}
err = context->result;
if (err)
goto out;
if (out_is_imm)
*out_param = context->out_param;
out:
spin_lock(&cmd->context_lock);
context->next = cmd->free_head;
cmd->free_head = context - cmd->context;
spin_unlock(&cmd->context_lock);
up(&cmd->event_sem);
return err;
}
int __mlx4_cmd(struct mlx4_dev *dev, u64 in_param, u64 *out_param,
int out_is_imm, u32 in_modifier, u8 op_modifier,
u16 op, unsigned long timeout)
{
if (mlx4_priv(dev)->cmd.use_events)
return mlx4_cmd_wait(dev, in_param, out_param, out_is_imm,
in_modifier, op_modifier, op, timeout);
else
return mlx4_cmd_poll(dev, in_param, out_param, out_is_imm,
in_modifier, op_modifier, op, timeout);
}
int mlx4_cmd_init(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
mutex_init(&priv->cmd.hcr_mutex);
sema_init(&priv->cmd.poll_sem, 1);
priv->cmd.use_events = 0;
priv->cmd.toggle = 1;
priv->cmd.hcr = ioremap(pci_resource_start(dev->pdev, 0) + MLX4_HCR_BASE,
MLX4_HCR_SIZE);
if (!priv->cmd.hcr) {
mlx4_err(dev, "Couldn't map command register.");
return -ENOMEM;
}
priv->cmd.pool = pci_pool_create("mlx4_cmd", dev->pdev,
MLX4_MAILBOX_SIZE,
MLX4_MAILBOX_SIZE, 0);
if (!priv->cmd.pool) {
iounmap(priv->cmd.hcr);
return -ENOMEM;
}
return 0;
}
void mlx4_cmd_cleanup(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
pci_pool_destroy(priv->cmd.pool);
iounmap(priv->cmd.hcr);
}
int mlx4_cmd_use_events(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
priv->cmd.context = kmalloc(priv->cmd.max_cmds *
sizeof (struct mlx4_cmd_context),
GFP_KERNEL);
if (!priv->cmd.context)
return -ENOMEM;
for (i = 0; i < priv->cmd.max_cmds; ++i) {
priv->cmd.context[i].token = i;
priv->cmd.context[i].next = i + 1;
}
priv->cmd.context[priv->cmd.max_cmds - 1].next = -1;
priv->cmd.free_head = 0;
sema_init(&priv->cmd.event_sem, priv->cmd.max_cmds);
spin_lock_init(&priv->cmd.context_lock);
for (priv->cmd.token_mask = 1;
priv->cmd.token_mask < priv->cmd.max_cmds;
priv->cmd.token_mask <<= 1)
;
--priv->cmd.token_mask;
priv->cmd.use_events = 1;
down(&priv->cmd.poll_sem);
return 0;
}
void mlx4_cmd_use_polling(struct mlx4_dev *dev)
{
struct mlx4_priv *priv = mlx4_priv(dev);
int i;
priv->cmd.use_events = 0;
for (i = 0; i < priv->cmd.max_cmds; ++i)
down(&priv->cmd.event_sem);
kfree(priv->cmd.context);
up(&priv->cmd.poll_sem);
}
struct mlx4_cmd_mailbox *mlx4_alloc_cmd_mailbox(struct mlx4_dev *dev)
{
struct mlx4_cmd_mailbox *mailbox;
mailbox = kmalloc(sizeof *mailbox, GFP_KERNEL);
if (!mailbox)
return ERR_PTR(-ENOMEM);
mailbox->buf = pci_pool_alloc(mlx4_priv(dev)->cmd.pool, GFP_KERNEL,
&mailbox->dma);
if (!mailbox->buf) {
kfree(mailbox);
return ERR_PTR(-ENOMEM);
}
return mailbox;
}
void mlx4_free_cmd_mailbox(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox)
{
if (!mailbox)
return;
pci_pool_free(mlx4_priv(dev)->cmd.pool, mailbox->buf, mailbox->dma);
kfree(mailbox);
}
